#include "global.h"
#include "globaldata.h"
#include "menu_input.h"
#include "string_format.h"
#include "memory.h"
#include "quick_save_write.h"
#include "save.h"

static EWRAM_INIT QuickSaveWrite *sQuickSaveWrite = {NULL};

#include "data/quick_save_write.h"

void PrepareQuickSaveWrite(u8 *r0, u32 r1, u8 r2)
{
    sQuickSaveWrite = MemoryAlloc(sizeof(QuickSaveWrite), 5);
    sQuickSaveWrite->unk4 = r0;
    sQuickSaveWrite->unk8 = r1;
    sQuickSaveWrite->unkC = r2;
    sQuickSaveWrite->state = 0;

    if (sQuickSaveWrite->unkC != 0)
        CreateDialogueBoxAndPortrait(sUnknown_80D45AC, 0, 0, 0x20);
    else
        CreateDialogueBoxAndPortrait(sUnknown_80D45AC, 0, 0, 0x20);
}

u32 WriteQuickSave(void)
{
    u32 stack_1;
    u32 stack_2;

    switch (sQuickSaveWrite->state) {
        case 0:
            sQuickSaveWrite->state = 1;
            break;
        case 1:
            sub_80140DC();
            stack_1 = 16;
            sQuickSaveWrite->quickSaveStatus = sub_80121D4(&stack_1, sQuickSaveWrite->unk4, sQuickSaveWrite->unk8);
            sQuickSaveWrite->state = 2;
            return 1;
        case 2:
            stack_1 = 0;

            if (sQuickSaveWrite->quickSaveStatus == 0)
                sQuickSaveWrite->quickSaveStatus = WriteSavetoPak(&stack_1, 2);

            switch (sQuickSaveWrite->quickSaveStatus) {
                case SAVE_COMPLETED:
                    sub_80121E0(987655);

                    if (sQuickSaveWrite->unkC != 0)
                        CreateDialogueBoxAndPortrait(sUnknown_80D45F4, 0, 0, 0x301);
                    else
                        CreateDialogueBoxAndPortrait(sUnknown_80D4668, 0, 0, 0x301);

                    sQuickSaveWrite->state = 3;
                    break;
                case SAVE_NOT_WRTTEN:
                    CreateDialogueBoxAndPortrait(sSaveNotWritten, 0, 0, 0);
                    sQuickSaveWrite->state = 4;
                    break;
                default:
                    sub_80121E0(987657);
                    CreateDialogueBoxAndPortrait(sSaveFailed, 0, 0, 0x301);
                    sQuickSaveWrite->state = 3;
                    break;
            }
            sub_8014114();
            break;
        case 3:
            if (sub_80144A4(&stack_2) == 0)
                sQuickSaveWrite->state = 5;
            break;
        case 4:
            break;
        case 5:
            if (sQuickSaveWrite->quickSaveStatus == SAVE_COMPLETED)
                return 2;
            return 3;
        default:
            break;
    }
    return 0;
}

void FinishQuickSaveWrite()
{
    if (sQuickSaveWrite) {
        MemoryFree(sQuickSaveWrite);
        sQuickSaveWrite = NULL;
    }
}
