#include "global.h"
#include "globaldata.h"
#include "music_util.h"
#include "code_801B3C0.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT unkStruct_203B230 *sUnknown_203B230 = { NULL };

#include "data/code_801B3C0.h"

static void sub_801B46C(u32);
static void sub_801B480(void);
static void sub_801B51C(void);
static void sub_801B590(void);

// arm9.bin::02027658
bool8 InitItemDescriptionWindow(Item *item)
{
    ResetSprites(TRUE);
    sUnknown_203B230 = MemoryAlloc(sizeof(unkStruct_203B230), 8);
    sUnknown_203B230->item = *item;
    ResetTouchScreenMenuInput(&sUnknown_203B230->unk88);
    sUnknown_203B230->unk24 = 0;
    sub_80140B4(&sUnknown_203B230->unk28);
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B230->unk28, TRUE, TRUE);
    sub_801B46C(0);
    return TRUE;
}

// arm9.bin::020275F8
u32 sub_801B410(void)
{
    switch (sUnknown_203B230->state) {
        case 0:
            sub_801B51C();
            break;
        case 1:
            sub_801B590();
            break;
        case 3:
            return 3;
        case 2:
        default:
            return 2;
    }

    return 0;
}

// arm9.bin::020275C4
void FreeItemDescriptionWindow(void)
{
    if (sUnknown_203B230 != NULL) {
        MemoryFree(sUnknown_203B230);
        sUnknown_203B230 = NULL;
    }
}

// arm9.bin::020275A8
static void sub_801B46C(u32 newState)
{
    sUnknown_203B230->state = newState;
    sub_801B480();
}

// arm9.bin::02027490
static void sub_801B480(void)
{
    switch (sUnknown_203B230->state) {
        case 0:
            CallPrepareTextbox_8008C54(sUnknown_203B230->unk24);
            sUnknown_203B230->unkC = sub_80913E0(&sUnknown_203B230->item, sUnknown_203B230->unk24, sUnknown_203B230->unk10);
            sUnknown_203B230->unk20 = 0;
            break;
        case 1:
            CallPrepareTextbox_8008C54(sUnknown_203B230->unk24);
            sub_80073B8(sUnknown_203B230->unk24);
            InlineStrcpy(gFormatBuffer_Monsters[0], sUnknown_203B230->unk10[sUnknown_203B230->unk8]->name);
            PrintFormattedStringOnWindow(16, 0, sFmtPkmn0, sUnknown_203B230->unk24, 0); // {POKEMON_0}
            PrintFormattedStringOnWindow(4, 16, sUnknown_203B230->unk10[sUnknown_203B230->unk8]->desc, sUnknown_203B230->unk24, 0);
            sub_80073E0(sUnknown_203B230->unk24);
            break;
        case 2:
        default:
            break;
    }
}

static void sub_801B51C(void)
{
    if (sUnknown_203B230->unkC != 0) {
        if (sUnknown_203B230->unk20 & 8)
            sub_8013F84();

        sUnknown_203B230->unk20++;
    }

    switch (sub_8012A64(&sUnknown_203B230->unk88, sUnknown_203B230->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);

            if (sUnknown_203B230->unkC != 0) {
                sUnknown_203B230->unk8 = 0;
                sub_801B46C(1);
            }
            else
                sub_801B46C(3);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_801B46C(2);
            break;
        default:
            break;
    }
}

static void sub_801B590(void)
{
    if (sUnknown_203B230->unk8 < (sUnknown_203B230->unkC - 1)) {
        if (sUnknown_203B230->unk20 & 8)
            sub_8013F84();

        sUnknown_203B230->unk20++;
    }

    switch (sub_8012A64(&sUnknown_203B230->unk88,sUnknown_203B230->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);

            sUnknown_203B230->unk8++;
            if (sUnknown_203B230->unk8 < sUnknown_203B230->unkC)
                sub_801B46C(1);
            else
                sub_801B46C(0);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_801B46C(2);
            break;
    }
}
