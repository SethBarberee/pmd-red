#include "global.h"
#include "globaldata.h"
#include "dungeon.h"
#include "dungeon_strings.h"
#include "dungeon_vram.h"
#include "input.h"
#include "text_1.h"

extern void sub_8094558(u32 param_1, const u8 *param_2,UnkDungeonGlobal_unk1CE98_sub *param_3);
extern void PlayDungeonCompleteBGM(void);
extern void PlayDungeonFailBGM(void);
extern void PlayDungeonConfirmationSE(void);
extern void UpdateDungeonMusic(void);
extern u8 sub_8094D14(void);

void ShowDungeonClearedWindow(void)
{
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {4, 3},
                .width = 22,
                .height = 14,
                .unk10 = 14,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };

    header.count = 1;
    header.currId = 0;
    header.width = 14;
    header.f3 = 0;
    windows.id[0].pos.y = 20;
    DungeonShowWindows(&windows, TRUE);
    if (gDungeon->unk1CE98.moveID > 549) {
        PlayDungeonCompleteBGM();
    }
    else {
        PlayDungeonFailBGM();
    }
    sub_8094558(0, gUnknown_80FE6E8,&gDungeon->unk1CE98); // The Last Outing
    while(1) {
        sub_803E668(0x36);
        UpdateDungeonMusic();
        if (windows.id[0].pos.y >= 4){
            windows.id[0].pos.y--;
            windows.id[0].unk0 = 0xa0;
            DungeonShowWindows(&windows, TRUE);
            continue;
        }
        if (sub_8094D14())
            break;
        if (gRealInputs.pressed & A_BUTTON)
            break;
    }
    PlayDungeonConfirmationSE();
}
