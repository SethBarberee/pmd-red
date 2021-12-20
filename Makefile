TOOLCHAIN := $(DEVKITARM)

ifeq ($(CC),)
HOSTCC := gcc
else
HOSTCC := $(CC)
endif

ifeq ($(CXX),)
HOSTCXX := g++
else
HOSTCXX := $(CXX)
endif

ifneq (,$(wildcard $(TOOLCHAIN)/base_tools))
include $(TOOLCHAIN)/base_tools
else
export PATH := $(TOOLCHAIN)/bin:$(PATH)
PREFIX := arm-none-eabi-
OBJCOPY   := $(PREFIX)objcopy
export CC 	 := $(PREFIX)gcc
export AS        := $(PREFIX)as
endif
export CPP       := $(CC) -E
export LD        := $(PREFIX)ld

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif


TITLE       := POKE DUNGEON
GAME_CODE   := B24E
MAKER_CODE  := 01
REVISION    := 0

ifeq ($(OS),Windows_NT)
LIB := ../../tools/agbcc/lib/libc.a ../../tools/agbcc/lib/libgcc.a ../../libagbsyscall/libagbsyscall.a
else
LIB := -L ../../tools/agbcc/lib -lc -lgcc -L ../../libagbsyscall -lagbsyscall
endif


#### Tools ####

SHELL     := /bin/bash -o pipefail
CC1       := tools/agbcc/bin/agbcc
SHA1SUM   := sha1sum -c
GBAGFX    := tools/gbagfx/gbagfx
GBAFIX    := tools/gbafix/gbafix
AIF2PCM   := tools/aif2pcm/aif2pcm
MID2AGB   := tools/mid2agb/mid2agb
PREPROC   := tools/preproc/preproc
SCANINC   := tools/scaninc/scaninc
RAMSCRGEN := tools/ramscrgen/ramscrgen
DUNGEONJSON := tools/dungeonjson/dungeonjson

TOOLDIRS := $(filter-out tools/agbcc tools/binutils,$(wildcard tools/*))
TOOLBASE = $(TOOLDIRS:tools/%=%)
TOOLS = $(foreach tool,$(TOOLBASE),tools/$(tool)/$(tool)$(EXE))


ASFLAGS         := -mcpu=arm7tdmi

override CC1FLAGS += -mthumb-interwork -Wimplicit -Wparentheses -Wunused -Werror -O2 -fhex-asm
INCLUDE_PATHS   := -I include -I tools/agbcc/include
CPPFLAGS        := -iquote include -I tools/agbcc/include -nostdinc -undef

#### Files ####

BUILD_NAME = red
BUILD_DIR := build/pmd_$(BUILD_NAME)

ROM := pmd_$(BUILD_NAME).gba
ELF := $(ROM:%.gba=%.elf)
MAP := $(ROM:%.gba=%.map)

C_SUBDIR = src
ASM_SUBDIR = asm
DATA_SRC_SUBDIR = src/data
DATA_ASM_SUBDIR = data
SONG_SUBDIR = sound/songs
MID_SUBDIR = sound/songs/midi
SAMPLE_SUBDIR = sound/direct_sound_samples

C_BUILDDIR = $(BUILD_DIR)/$(C_SUBDIR)
ASM_BUILDDIR = $(BUILD_DIR)/$(ASM_SUBDIR)
DATA_ASM_BUILDDIR = $(BUILD_DIR)/$(DATA_ASM_SUBDIR)
SONG_BUILDDIR = $(BUILD_DIR)/$(SONG_SUBDIR)
MID_BUILDDIR = $(BUILD_DIR)/$(MID_SUBDIR)

C_SOURCES   := $(wildcard src/*.c)
ASM_SOURCES := $(wildcard asm/*.s data/*.s)

C_OBJECTS    := $(addprefix $(BUILD_DIR)/, $(C_SOURCES:%.c=%.o))
ASM_OBJECTS  := $(addprefix $(BUILD_DIR)/, $(ASM_SOURCES:%.s=%.o))
ALL_OBJECTS := $(C_OBJECTS) $(ASM_OBJECTS)

SUBDIRS := $(sort $(dir $(ALL_OBJECTS)))


LD_SCRIPT := $(BUILD_DIR)/ld_script.ld


# Special configurations required for lib files
$(C_BUILDDIR)/agb_flash.o   : CC1FLAGS := -O -mthumb-interwork
$(C_BUILDDIR)/agb_flash_1m.o: CC1FLAGS := -O -mthumb-interwork
$(C_BUILDDIR)/agb_flash_mx.o: CC1FLAGS := -O -mthumb-interwork

$(C_BUILDDIR)/m4a.o: CC1 := tools/agbcc/bin/old_agbcc

#### Main Rules ####


ALL_BUILDS := red

# Available targets
.PHONY: all clean compare tidy libagbsyscall tools clean-tools $(TOOLDIRS)

MAKEFLAGS += --no-print-directory

# Secondary expansion is required for dependency variables in object rules.
.SECONDEXPANSION:
# Clear the default suffixes
.SUFFIXES:
# Don't delete intermediate files
.SECONDARY:
# Delete files that weren't built properly
.DELETE_ON_ERROR:

infoshell = $(foreach line, $(shell $1 | sed "s/ /__SPACE__/g"), $(info $(subst __SPACE__, ,$(line))))

# Build tools when building the rom
# Disable dependency scanning for clean/tidy/tools
# Use a separate minimal makefile for speed
# Since we don't need to reload most of this makefile
ifeq (,$(filter clean,$(MAKECMDGOALS)))
$(call infoshell, $(MAKE) -f make_tools.mk)
endif

.PRECIOUS: %.1bpp %.4bpp %.8bpp %.gbapal %.lz %.rl %.pcm %.bin


# Create build subdirectories

$(shell mkdir -p $(SUBDIRS))

all: $(ROM)

tools: $(TOOLDIRS)

include dungeon_pokemon.mk
include dungeon_floor.mk
include data_pokemon.mk
include data_item.mk
include data_move.mk
include graphics.mk

$(TOOLDIRS):
	@$(MAKE) -C $@ CC=$(HOSTCC) CXX=$(HOSTCXX)

compare: $(ROM)
	@$(SHA1SUM) $(BUILD_NAME).sha1

clean: tidy clean-tools
	$(RM) $(ALL_OBJECTS) $(ALL_OBJECTS:.o=.d)

clean-tools:
	@$(foreach tooldir,$(TOOLDIRS),$(MAKE) clean -C $(tooldir);)

tidy:
	$(RM) -f $(ROM) $(ELF) $(MAP)
	$(RM) -r $(BUILD_DIR)
	$(RM) -f $(ITEM_DATA)
	$(RM) -f $(MOVE_DATA)
	$(RM) -f $(POKEMON_SPECIES)
	$(RM) -f $(DUNGEON_FLOOR)
	$(RM) -f $(DUNGEON_POKEMON)
	find . \( -iname '*.1bpp' -o -iname '*.4bpp' -o -iname '*.8bpp' -o -iname '*.gbapal' -o -iname '*.lz' -o -iname '*.latfont' -o -iname '*.hwjpnfont' -o -iname '*.fwjpnfont' \) -exec rm {} +
	@$(MAKE) clean -C libagbsyscall

define scaninc
	( paths="$$($(SCANINC) $1 $<)"; \
		echo -n "$(@:.d=.o): " > $@; \
		echo "$$paths" | xargs printf "%s " >> $@; \
		test -n "$$paths" && echo "$$paths" | xargs printf "\n%s:" >> $@; \
		echo >> $@; )
endef

$(C_BUILDDIR)/%.o: $(C_SUBDIR)/%.c
	@$(CPP) $(CPPFLAGS) $< -o $(C_BUILDDIR)/$*.i
	@$(PREPROC) $(C_BUILDDIR)/$*.i charmap.txt | $(CC1) $(CC1FLAGS) -o $(C_BUILDDIR)/$*.s
	@echo -e ".text\n\t.align\t2, 0\n" >> $(C_BUILDDIR)/$*.s
	$(AS) $(ASFLAGS) -o $@ $(C_BUILDDIR)/$*.s

$(C_BUILDDIR)/%.d: $(C_SUBDIR)/%.c
	@$(call scaninc,$(INCLUDE_PATHS))

$(DATA_ASM_BUILDDIR)/%.o: $(DATA_ASM_SUBDIR)/%.s dungeon_pokemon dungeon_floor data_pokemon data_item data_move
	@$(CPP) -x assembler-with-cpp $(CPPFLAGS) $< -o $(DATA_ASM_BUILDDIR)/$*.i.s
	@$(PREPROC) $(DATA_ASM_BUILDDIR)/$*.i.s charmap.txt > $(DATA_ASM_BUILDDIR)/$*.s
	$(AS) $(ASFLAGS) -o $@ $(DATA_ASM_BUILDDIR)/$*.s

$(DATA_ASM_BUILDDIR)/%.d: $(DATA_ASM_SUBDIR)/%.s
	@$(call scaninc,$(INCLUDE_PATHS))

$(ASM_BUILDDIR)/%.o: $(ASM_SUBDIR)/%.s
	@$(CPP) -x assembler-with-cpp $(CPPFLAGS) $< -o $(ASM_BUILDDIR)/$*.s
	$(AS) $(ASFLAGS) -o $@ $(ASM_BUILDDIR)/$*.s

$(ASM_BUILDDIR)/%.d: $(ASM_SUBDIR)/%.s
	@$(call scaninc,$(INCLUDE_PATHS))

libagbsyscall:
	@$(MAKE) -C libagbsyscall TOOLCHAIN=$(TOOLCHAIN)

$(BUILD_DIR)/sym_%.txt: sym_%.txt
	cp $< $(BUILD_DIR)

$(LD_SCRIPT): ld_script.txt $(BUILD_DIR)/sym_ewram.txt $(BUILD_DIR)/sym_ewram2.txt $(BUILD_DIR)/sym_iwram.txt
	cd $(BUILD_DIR) && sed -e "s#tools/#../../tools/#g" ../../ld_script.txt >ld_script.ld

$(ELF): $(LD_SCRIPT) $(ALL_OBJECTS) $(LIBC) libagbsyscall tools
	cd $(BUILD_DIR) && $(LD) -T ld_script.ld -Map ../../$(MAP) -o ../../$@ $(LIB)

$(ROM): %.gba: $(ELF)
	$(OBJCOPY) -O binary --gap-fill 0xFF --pad-to 0xA000000 $< $@
	$(GBAFIX) $@ -p -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(REVISION) --silent

ifeq (,$(filter clean,$(MAKECMDGOALS)))
-include $(ALL_OBJECTS:.o=.d)
endif
