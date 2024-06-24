#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "iq_skill_list_menu.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "text1.h"
#include "text2.h"

extern u8 gUnknown_202DEA8[];

static EWRAM_DATA_2 struct IQSkillListMenu *sIQSkillListMenu = {0};

#include "data/iq_skill_list_menu.h"

static void sub_801C440(void);

bool8 CreateIQSkillListMenu(s16 species, u32 index, u32 a2)
{
#ifndef NONMATCHING
    register s32 species_s32 asm("r4");
#else
    s32 species_s32;
#endif

    species_s32 = species;

    if (HasNoAvailIQSkills(species))
        return FALSE;

    if (sIQSkillListMenu == NULL)
        sIQSkillListMenu = MemoryAlloc(sizeof(struct IQSkillListMenu), 8);

    sIQSkillListMenu->species = species_s32;
    sIQSkillListMenu->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
    sIQSkillListMenu->numIQSkills = GetNumAvailableIQSkills(sIQSkillListMenu->iqSkills, sIQSkillListMenu->pokeStruct->IQ);
    sIQSkillListMenu->unk58 = index;
    sIQSkillListMenu->unk5C = &sIQSkillListMenu->unk60[index];
    sub_8006518(sIQSkillListMenu->unk60);
    sIQSkillListMenu->unk60[sIQSkillListMenu->unk58] = sUnknown_80DBDF0;
    sIQSkillListMenu->unk5C->unk14 = &sIQSkillListMenu->unkC0;
    sub_8012D08(sIQSkillListMenu->unk5C, a2);
    ResetUnusedInputStruct();
    sub_800641C(sIQSkillListMenu->unk60, TRUE, TRUE);
    sub_8013818(&sIQSkillListMenu->input, sIQSkillListMenu->numIQSkills, a2, index);
    sub_801C440();
    BuildIQSkillList();
    return TRUE;
}

u32 HandleIQSkillListMenuInput(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sIQSkillListMenu->input);
        return 0;
    }

    switch (GetKeyPress(&sIQSkillListMenu->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&sIQSkillListMenu->input, 1) != 0) {
                sub_801C440();
                BuildIQSkillList();
                return 1;
            }
            return 0;
    }
}

s32 GetIQSkillSelection(void)
{
    return (sIQSkillListMenu->input.unk1E * sIQSkillListMenu->input.unk1C) + sIQSkillListMenu->input.menuIndex;
}

void RedrawIQSkillListMenu(bool8 addCursor)
{
    ResetUnusedInputStruct();
    sub_800641C(sIQSkillListMenu->unk60, FALSE, FALSE);
    sIQSkillListMenu->input.unk22 = sIQSkillListMenu->numIQSkills;
    sub_8013984(&sIQSkillListMenu->input);
    sub_801C440();
    BuildIQSkillList();

    if (addCursor)
       AddMenuCursorSprite(&sIQSkillListMenu->input);
}

void CleanIQSkillListMenu(void)
{
    if (sIQSkillListMenu != NULL) {
        sIQSkillListMenu->unk60[sIQSkillListMenu->unk58] = sUnknown_80DBDD8;
        ResetUnusedInputStruct();
        sub_800641C(sIQSkillListMenu->unk60, TRUE, TRUE);
        MemoryFree(sIQSkillListMenu);
        sIQSkillListMenu = NULL;
    }
}

#ifdef NONMATCHING // sub_80095E4 memes
// https://decomp.me/scratch/NdDP3  (98.06% matching) - Seth
static void sub_801C440(void)
{
    u16 sVar2;

    sIQSkillListMenu->unkC0 = sUnknown_203B23C->unk24.unk20;
    sIQSkillListMenu->unkC1 = sUnknown_203B23C->unk24.unk1E;
    sIQSkillListMenu->unkC2 = 10;
    sIQSkillListMenu->unkC3 = 0;
    ResetUnusedInputStruct();
    sub_800641C(sIQSkillListMenu->unk60, TRUE, TRUE);
    sVar2 = sub_80095E4(sIQSkillListMenu->unk24.unk1A, 12) + 2;
    sIQSkillListMenu->unk60[sUnknown_203B23C->unk58].unkE = sVar2;
    sIQSkillListMenu->unk60[sUnknown_203B23C->unk58].unk10 = sVar2;
    ResetUnusedInputStruct();
    sub_800641C(sIQSkillListMenu->unk60, TRUE, TRUE);
}
#else
NAKED
static void sub_801C440(void)
{
    asm_unified(
    "\tpush {r4,lr}\n"
    "\tldr r4, _0801C4C4\n"
    "\tldr r0, [r4]\n"
    "\tadds r1, r0, 0\n"
    "\tadds r1, 0x44\n"
    "\tldrh r1, [r1]\n"
    "\tadds r0, 0xC0\n"
    "\tmovs r2, 0\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r1, r0, 0\n"
    "\tadds r1, 0x42\n"
    "\tldrh r1, [r1]\n"
    "\tadds r0, 0xC1\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0xC2\n"
    "\tmovs r1, 0xA\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0xC3\n"
    "\tstrb r2, [r0]\n"
    "\tbl ResetUnusedInputStruct\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x60\n"
    "\tmovs r1, 0x1\n"
    "\tmovs r2, 0x1\n"
    "\tbl sub_800641C\n"
    "\tldr r0, [r4]\n"
    "\tmovs r1, 0x3E\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tmovs r1, 0xC\n"
    "\tbl sub_80095E4\n"
    "\tadds r0, 0x2\n"
    "\tldr r2, [r4]\n"
    "\tldr r3, [r2, 0x58]\n"
    "\tlsls r1, r3, 1\n"
    "\tadds r1, r3\n"
    "\tlsls r1, 3\n"
    "\tadds r1, r2, r1\n"
    "\tadds r1, 0x6E\n"
    "\tlsls r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tstrh r0, [r1]\n"
    "\tldr r3, [r2, 0x58]\n"
    "\tlsls r1, r3, 1\n"
    "\tadds r1, r3\n"
    "\tlsls r1, 3\n"
    "\tadds r2, r1\n"
    "\tadds r2, 0x70\n"
    "\tstrh r0, [r2]\n"
    "\tbl ResetUnusedInputStruct\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x60\n"
    "\tmovs r1, 0x1\n"
    "\tmovs r2, 0x1\n"
    "\tbl sub_800641C\n"
    "\tpop {r4}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_0801C4C4: .4byte sIQSkillListMenu"
    );
}
#endif

void BuildIQSkillList(void)
{
    u32 y;
    s32 x;
    s32 x2;
    u32 skillIndex;
    s32 counter;

    sub_8008C54(sIQSkillListMenu->unk58);
    sub_80073B8(sIQSkillListMenu->unk58);
    x = sIQSkillListMenu->input.unk1E * 8;
    x2 = x;
    x2 += 10;
    xxx_call_draw_string(x2, 0, sIQSkills, sIQSkillListMenu->unk58, 0);

    x += 4;
    x2 = x + sIQSkillListMenu->unkC2 * 8;
    sub_8012BC4(x2, 0, sIQSkillListMenu->input.unk1E + 1, 1, 7, sIQSkillListMenu->unk58);

    for (counter = 0; counter < sIQSkillListMenu->input.unk1A; counter++) {
        skillIndex = sIQSkillListMenu->iqSkills[(sIQSkillListMenu->input.unk1E * sIQSkillListMenu->input.unk1C) + counter];

        y = sub_8013800(&sIQSkillListMenu->input, counter);
        strncpy(gUnknown_202DEA8, GetIQSkillName(skillIndex), 80);

        if (IsIQSkillSet((u8 *)&sIQSkillListMenu->pokeStruct->IQSkills, 1 << skillIndex))
            strcpy(gUnknown_202DEA8 - 80, sStarBullet);
        else
            strcpy(gUnknown_202DEA8 - 80, sUnknown_80DBE18);

        xxx_format_and_draw(12, y, sFmt01, sIQSkillListMenu->unk58, 0);
    }

    sub_80073E0(sIQSkillListMenu->unk58);
}

bool8 HasNoAvailIQSkills(s16 species)
{
    s32 species_s32;
    u8 iqSkillBuffer[NUM_IQ_SKILLS];
    PokemonStruct1 *pokeStruct;

    species_s32 = species;
    pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];

    if (GetNumAvailableIQSkills(iqSkillBuffer, pokeStruct->IQ) == 0)
        return TRUE;

    return FALSE;
}
