#include "global.h"
#include "globaldata.h"
#include "dungeon_menu_others.h"
#include "dungeon_menu_recruitment.h"
#include "dungeon_engine.h"
#include "dungeon_music.h"
#include "dungeon_submenu.h"
#include "dungeon.h"
#include "text.h"
#include "menu_input.h"
#include "input.h"
#include "code_803E46C.h"
#include "code_8044CC8.h"
#include "dungeon_action.h"
#include "dungeon_util.h"
#include "dungeon_map_access.h"
#include "dungeon_leader.h"
#include "code_8045A00.h"
#include "code_8097DD0.h"
#include "dungeon_message.h"
#include "game_options.h"
#include "post_office_guide2.h"
#include "dungeon_main.h"
#include "dungeon_map.h"

extern void sub_803EAF0(u32, u8 *);
extern bool8 CanSubMenuItemBeChosen(s32 param_1);
extern void DungeonShowWindows(WindowTemplates *a0, bool8 a1);
extern void AddActionToDungeonSubMenu(u16 actionId, u8 param_2);
extern void sub_8045064(void);
extern void sub_803E13C(void);
extern void sub_8083AB0(s16 param_0, Entity * target, Entity * entity);

extern MenuInputStruct gDungeonMenu;

extern const u8 *const gUnknown_80FEBF8;
extern const u8 *const gUnknown_80FEC28;
extern const u8 *const gUnknown_80FDE6C;
extern const u8 *const gUnknown_80FDEB8;
extern const u8 *const gUnknown_80FEA44;
extern const u8 *const gUnknown_80FEA50;
extern const u8 *const gUnknown_80FEA28;
extern const u8 *const gUnknown_80FEA10;
extern const u8 *const gUnknown_80FE9F8;
extern const u8 *const gUnknown_80FE9E8;
extern const u8 *const gUnknown_80FE9CC;
extern const u8 *const gUnknown_80FE8F8;
extern const u8 *const gUnknown_80FF770;
extern const u8 *const gUnknown_80FE8F4;
extern const u8 *const gGameOptionsTextPtr;
extern const u8 *const gOptionsDungeonTextPtr;
extern const u8 *const gOptionsOthersTextPtr;
extern const u8 *const gUnknown_80FE748;
extern const u8 *const gUnknown_80FE764;
extern const u8 *const gUnknown_80FE7C0;
extern const u8 *const gUnknown_80FE788;
extern const u8 *const gUnknown_80FE7A8;
extern const u8 *const gUnknown_80FE7E4;
extern const u8 *const gUnknown_80FA61C;
extern const u8 *const gUnknown_80FA5F4;
extern const u8 *const gOptionsOthersTextPtr;
extern const u8 *const gOptionsWindowColorPtr;
extern const u8 *const gUnknown_80FF774[];

static void PrintOthersMenuOptions(void);
static void ShowGameOptionsMenu(void);
static void ShowQuickSaveGiveUpMenu(void);
static void ShowMissionObjectivesMenu(void);
static void ShowHintsMenu(void);
static bool8 ShowDungeonOptions(void);
static bool8 ShowOthersOptions(void);
static void TrySetNewGameOptions(bool8 bPressed);
static void AskToResetToDefault(void);
static void PrintGameOptions(void);
static void PrintDungeonOptions(void);
static void PrintOthersOptions(void);
static void ChangeGameOptionLeft(s32 optionId);
static void ChangeGameOptionRight(s32 optionId);
static bool8 UnknownDungeonOption(void);
static bool8 UnknownOthersOption(void);
static bool8 AskToQuickSave(void);
static bool8 AskToGiveUp(void);
static void PrintQuickSaveMenuOptions(void);
static void PrintHintsMenu(void);
static void ShowChosenHintWindow(s32 hintId);

EWRAM_DATA static s32 sOthersCursorId = 0;
UNUSED EWRAM_DATA static u8 sUnused[4] = {0};
EWRAM_DATA static GameOptions sChangedGameOptions = {0};

enum {
    OTHERS_GAME_OPTIONS,
    OTHERS_QUICKSAVE_GIVEUP,
    OTHERS_MESSAGE_LOG,
    OTHERS_MISSION_OBJECTIVES,
    OTHERS_RECRUITMENT_SEARCH,
    OTHERS_HINTS,
    OTHERS_COUNT
};

void ShowDungeonOthersMenu(void)
{
    bool8 unkAlwaysFalse;
    s32 hintsMenuId = (gDungeon->unk644.canRecruit) ? OTHERS_HINTS : OTHERS_HINTS - 1;

    sOthersCursorId = 0;
    unkAlwaysFalse = FALSE;
    while (1) {
        bool8 bPress = FALSE;

        PrintOthersMenuOptions();
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                if (gDungeonMenu.menuIndex != OTHERS_RECRUITMENT_SEARCH || (gDungeon->unk644.canRecruit && !IsBossFight())) {
                    PlayDungeonConfirmationSE();
                }
                else {
                    PlayDungeonCancelSE();
                }
                break;
            }
            else if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x24);
        if (unkAlwaysFalse)
            continue;
        if (bPress)
            break;

        sOthersCursorId = gDungeonMenu.menuIndex;
        if (sOthersCursorId == OTHERS_GAME_OPTIONS) {
            ShowGameOptionsMenu();
        }
        if (sOthersCursorId == OTHERS_QUICKSAVE_GIVEUP) {
            ShowQuickSaveGiveUpMenu();
        }
        if (sOthersCursorId == OTHERS_MESSAGE_LOG) {
            DisplayMessageLog();
        }
        if (sOthersCursorId == OTHERS_MISSION_OBJECTIVES) {
            ShowMissionObjectivesMenu();
        }
        if (gDungeon->unk644.canRecruit && !IsBossFight() && sOthersCursorId == OTHERS_RECRUITMENT_SEARCH) {
            ShowRecruitmentSearchMenu();
        }
        if (sOthersCursorId == hintsMenuId) {
            ShowHintsMenu();
        }

        if (gDungeon->unk4)
            break;
        if (GetLeaderActionId() != ACTION_NOTHING)
            break;
    }

    ShowWholeRevealedDungeonMap();
    sub_803EAF0(0, NULL);
}

enum {
    GAME_OPTION_DUNGEON,
    GAME_OPTION_OTHERS,
    GAME_OPTION_DEFAULT,
};

static void ShowGameOptionsMenu(void)
{
    while (1) {
        bool8 bPress = FALSE;

        PrintGameOptions();
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                PlayDungeonConfirmationSE();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x24);
        if (bPress)
            break;

        sChangedGameOptions = *gGameOptionsRef;
        if (gDungeonMenu.menuIndex == GAME_OPTION_DUNGEON) {
            bPress = ShowDungeonOptions();
            TrySetNewGameOptions(bPress);
        }
        else if (gDungeonMenu.menuIndex == GAME_OPTION_OTHERS) {
            bPress = ShowOthersOptions();
            TrySetNewGameOptions(bPress);
        }
        else if (gDungeonMenu.menuIndex == GAME_OPTION_DEFAULT) {
            AskToResetToDefault();
        }
    }

    sub_803EAF0(0, NULL);
}

enum {
    OPTION_SPEED,
    OPTION_FAR_OFF_PALS,
    OPTION_DAMAGE_TURN,
    OPTION_GRIDS,
    OPTION_MAP,
    OPTION_WINDOWS,
    OPTION_COUNT
};

#define DUNGEON_OPTIONS_COUNT OPTION_WINDOWS
#define OTHERS_OPTIONS_COUNT (OPTION_COUNT - DUNGEON_OPTIONS_COUNT)

static bool8 ShowDungeonOptions(void)
{
    bool8 dpadMoved;
    bool8 bPress = FALSE;

    gDungeonMenu.menuIndex = 0;
    while (1) {
        bPress = FALSE;
        dpadMoved = FALSE;

        PrintDungeonOptions();
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if (gRealInputs.repeated & DPAD_LEFT) {
                PlayDungeonCursorSE(FALSE);
                ChangeGameOptionLeft(gDungeonMenu.menuIndex);
                dpadMoved = TRUE;
                break;
            }
            if (gRealInputs.repeated & DPAD_RIGHT) {
                PlayDungeonCursorSE(FALSE);
                ChangeGameOptionRight(gDungeonMenu.menuIndex);
                dpadMoved = TRUE;
                break;
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonConfirmationSE();
                break;
            }
            if (gRealInputs.pressed & B_BUTTON) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }

            if (UnknownDungeonOption()) {
                dpadMoved = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x24);
        if (!dpadMoved)
            break;
    }

    return bPress;
}

static bool8 ShowOthersOptions(void)
{
    bool8 dpadMoved;
    bool8 bPress = FALSE;

    gDungeonMenu.menuIndex = 0;
    while (1) {
        bPress = FALSE;
        dpadMoved = FALSE;

        PrintOthersOptions();
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if (gRealInputs.repeated & DPAD_LEFT) {
                PlayDungeonCursorSE(FALSE);
                ChangeGameOptionLeft(gDungeonMenu.menuIndex + DUNGEON_OPTIONS_COUNT);
                dpadMoved = TRUE;
                break;
            }
            if (gRealInputs.repeated & DPAD_RIGHT) {
                PlayDungeonCursorSE(FALSE);
                ChangeGameOptionRight(gDungeonMenu.menuIndex + DUNGEON_OPTIONS_COUNT);
                dpadMoved = TRUE;
                break;
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonConfirmationSE();
                break;
            }
            if (gRealInputs.pressed & B_BUTTON) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }

            if (UnknownOthersOption()) {
                dpadMoved = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x24);
        if (!dpadMoved)
            break;
    }

    return bPress;
}

static void TrySetNewGameOptions(bool8 bPressed)
{
    bool8 optionsChanged = FALSE;

    if (bPressed) {
        if (!GameOptionsNotChange(&sChangedGameOptions))
            optionsChanged = TRUE;
    }
    else {
        optionsChanged = TRUE;
    }

    if (optionsChanged) {
        if (DisplayDungeonYesNoMessage(0, gUnknown_80FEBF8, TRUE) == 1) {
            *gGameOptionsRef = sChangedGameOptions;
            sub_803E13C();
            LoadDungeonMapPalette();
        }
    }
}

static void AskToResetToDefault(void)
{
    if (DisplayDungeonYesNoMessage(0, gUnknown_80FEC28, FALSE) == 1) {
        InitializeGameOptions(FALSE);
        sub_803E13C();
    }
}

static void ShowQuickSaveGiveUpMenu(void)
{
    bool8 unkAlwaysFalse = FALSE;
    while (1) {
        bool8 bPress = FALSE;

        PrintQuickSaveMenuOptions();
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                PlayDungeonConfirmationSE();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x24);

        if (unkAlwaysFalse)
            continue;
        if (bPress)
            break;

        if (gDungeonMenu.menuIndex == 0) {
            AskToQuickSave();
        }
        else if (gDungeonMenu.menuIndex == 1) {
            AskToGiveUp();
        }

        if (GetLeaderActionId() != ACTION_NOTHING)
            break;
    }
}

static void ShowMissionObjectivesMenu(void)
{
    sub_80319A4(gDungeon->unk644.unk34, gDungeon->unk644.dungeonLocation.id, 0);
    do {
        DungeonRunFrameActions(0x47);
    } while (sub_80319F8() == 0);
    sub_8031A3C();
}

static bool8 AskToQuickSave(void)
{
    if (DisplayDungeonYesNoMessage(NULL, gUnknown_80FDE6C, FALSE) != 1) {
        return TRUE;
    }
    SetMonsterActionFields(GetLeaderActionContainer(), ACTION_QUICK_SAVE);
    return FALSE;
}

static bool8 AskToGiveUp(void)
{
    if (DisplayDungeonYesNoMessage(NULL, gUnknown_80FDEB8, FALSE) != 1) {
        return TRUE;
    }
    SetMonsterActionFields(GetLeaderActionContainer(), ACTION_GIVE_UP);
    sub_8083AB0(0x21B, NULL, GetLeader());
    gDungeon->unk644.unk10 = 1;
    return FALSE;
}

static void PrintOthersMenuOptions(void)
{
    s32 optionsCount, currOptionId;
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 16,
                .unk10 = 16,
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
    header.f3 = 0;
    gDungeonMenu.menuIndex = sOthersCursorId;
    optionsCount = (gDungeon->unk644.canRecruit) ? OTHERS_COUNT : OTHERS_COUNT - 1;
    gDungeonMenu.unk1A = optionsCount;
    gDungeonMenu.unk1C = optionsCount;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    windows.id[0].width = 18;
    windows.id[0].height = windows.id[0].unk10 = sub_80095E4(optionsCount, 12) + 2;
    header.width = 10;
    windows.id[0].pos.x = 2;
    DungeonShowWindows(&windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);
    sub_80073B8(0);
    currOptionId = 0;
    PrintFormattedStringOnWindow(16, 0, gUnknown_80FE8F8, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FE9CC, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FE9E8, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FE9F8, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FEA10, 0, '\0');
    if (gDungeon->unk644.canRecruit) {
        if (!IsBossFight()) {
            PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FEA28, 0, '\0');
        }
        else {
            PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80FEA44, 0, '\0');
        }
    }
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId), gUnknown_80FEA50, 0, '\0');

    sub_80073E0(0);
}

struct Struct_80F7C50
{
    const u8 *str;
    s32 val;
};

// TODO: Fix this table in other file

extern const struct Struct_80F7C50 gUnknown_80F7C50[];

static void PrintQuickSaveMenuOptions(void)
{
    s32 optionsCount, currOptionId;
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 16,
                .unk10 = 16,
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
    header.f3 = 0;
    gDungeonMenu.menuIndex = 0;
    optionsCount = 2;
    gDungeonMenu.unk1A = optionsCount;
    gDungeonMenu.unk1C = optionsCount;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    windows.id[0].width = 18;
    windows.id[0].height = windows.id[0].unk10 = sub_80095E4(optionsCount, 12) + 2;
    header.width = 10;
    windows.id[0].pos.x = 2;
    DungeonShowWindows(&windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);
    sub_80073B8(0);
    currOptionId = 0;
    PrintFormattedStringOnWindow(16, 0, gUnknown_80FE8F4, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80F7C50[43].str, 0, '\0');
    PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, currOptionId++), gUnknown_80F7C50[46].str, 0, '\0');

    sub_80073E0(0);
}

static void PrintGameOptions(void)
{
    s32 optionsCount;
    s32 y[3];
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 12,
                .height = 16,
                .unk10 = 16,
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
    header.f3 = 0;
    gDungeonMenu.menuIndex = 0;
    optionsCount = 3;
    gDungeonMenu.unk1A = optionsCount;
    gDungeonMenu.unk1C = optionsCount;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    windows.id[0].width = 12;
    windows.id[0].height = windows.id[0].unk10 = sub_80095E4(optionsCount, 12) + 2;
    header.width = 10;
    windows.id[0].pos.x = 2;
    DungeonShowWindows(&windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);

    y[0] = GetMenuEntryYCoord(&gDungeonMenu, 0);
    y[1] = GetMenuEntryYCoord(&gDungeonMenu, 1);
    y[2] = GetMenuEntryYCoord(&gDungeonMenu, 2);
    sub_80073B8(0);
    PrintFormattedStringOnWindow(16, 0, gGameOptionsTextPtr, 0, '\0');
    PrintFormattedStringOnWindow(8, y[0], gOptionsDungeonTextPtr, 0, '\0');
    PrintFormattedStringOnWindow(8, y[1], gOptionsOthersTextPtr, 0, '\0');
    PrintFormattedStringOnWindow(8, y[2], gUnknown_80FE748, 0, '\0');
    sub_80073E0(0);
}

static void PrintDungeonOptions(void)
{
    s32 y[DUNGEON_OPTIONS_COUNT];
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };
    s32 mapOptionUnderscoreWidths[] = {16, 25, 27};

    header.count = 1;
    header.currId = 0;
    header.f3 = 0;

    gDungeonMenu.unk1A = DUNGEON_OPTIONS_COUNT;
    gDungeonMenu.unk1C = DUNGEON_OPTIONS_COUNT;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    windows.id[0].width = 24;
    windows.id[0].height = windows.id[0].unk10 = sub_80095E4(DUNGEON_OPTIONS_COUNT, 12) + 2;
    header.width = 10;
    windows.id[0].pos.x = 2;
    DungeonShowWindows(&windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);

    y[0] = GetMenuEntryYCoord(&gDungeonMenu, 0);
    y[1] = GetMenuEntryYCoord(&gDungeonMenu, 1);
    y[2] = GetMenuEntryYCoord(&gDungeonMenu, 2);
    y[3] = GetMenuEntryYCoord(&gDungeonMenu, 3);
    y[4] = GetMenuEntryYCoord(&gDungeonMenu, 4);
    sub_80073B8(0);
    PrintFormattedStringOnWindow(16, 0, gOptionsDungeonTextPtr, 0, '\0');
    PrintFormattedStringOnWindow(8, y[0], gUnknown_80FE764, 0, '\0');
    PrintFormattedStringOnWindow(8, y[1], gUnknown_80FE788, 0, '\0');
    PrintFormattedStringOnWindow(8, y[2], gUnknown_80FE7A8, 0, '\0');
    PrintFormattedStringOnWindow(8, y[3], gUnknown_80FE7C0, 0, '\0');
    PrintFormattedStringOnWindow(8, y[4], gUnknown_80FE7E4, 0, '\0');

    if (sChangedGameOptions.dungeonSpeed != DUNGEON_SPEED_SLOW) {
        AddDoubleUnderScoreHighlight(0, 136, y[0] + 10, 21, 7);
    }
    else {
        AddDoubleUnderScoreHighlight(0, 80, y[0] + 10, 22, 7);
    }

    if (sChangedGameOptions.FarOffPals != FAROFFPALS_SELF) {
        AddDoubleUnderScoreHighlight(0, 136, y[1] + 10, 22, 7);
    }
    else {
        AddDoubleUnderScoreHighlight(0, 80, y[1] + 10, 18, 7);
    }

    if (sChangedGameOptions.damageTurn) {
        AddDoubleUnderScoreHighlight(0, 136, y[2] + 10, 16, 7);
    }
    else {
        AddDoubleUnderScoreHighlight(0, 80, y[2] + 10, 12, 7);
    }

    if (sChangedGameOptions.gridEnable) {
        AddDoubleUnderScoreHighlight(0, 136, y[3] + 10, 12, 7);
    }
    else {
        AddDoubleUnderScoreHighlight(0, 80, y[3] + 10, 16, 7);
    }

    AddDoubleUnderScoreHighlight(0, 80 + (sChangedGameOptions.mapOption * 40), y[4] + 10, mapOptionUnderscoreWidths[sChangedGameOptions.mapOption], 7);

    sub_80073E0(0);
}

static void PrintOthersOptions(void)
{
    s32 i;
    s32 y[OTHERS_OPTIONS_COUNT];
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 18,
                .height = 16,
                .unk10 = 16,
                .unk12 = 0,
                .header = &header,
            },
            [1] = WIN_TEMPLATE_DUMMY,
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };
    s32 underscoreWidths[] = {19, 17, 25};

    header.count = 1;
    header.currId = 0;
    header.f3 = 0;

    gDungeonMenu.unk1A = OTHERS_OPTIONS_COUNT;
    gDungeonMenu.unk1C = OTHERS_OPTIONS_COUNT;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    windows.id[0].width = 24;
    windows.id[0].height = windows.id[0].unk10 = sub_80095E4(OTHERS_OPTIONS_COUNT, 12) + 2;
    header.width = 10;
    windows.id[0].pos.x = 2;
    DungeonShowWindows(&windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);

    for (i = 0; i < OTHERS_OPTIONS_COUNT; i++) {
        y[i] = GetMenuEntryYCoord(&gDungeonMenu, i);
    }
    sub_80073B8(0);

    PrintFormattedStringOnWindow(16, 0, gOptionsOthersTextPtr, 0, '\0');
    PrintFormattedStringOnWindow(8, y[0], gOptionsWindowColorPtr, 0, '\0');
    AddDoubleUnderScoreHighlight(0, 80 + (sChangedGameOptions.windowColor * 40), y[0] + 10, underscoreWidths[sChangedGameOptions.windowColor], 7);

    sub_80073E0(0);
}

static void ChangeGameOptionLeft(s32 optionId)
{
    switch (optionId) {
        case OPTION_SPEED:
            sChangedGameOptions.dungeonSpeed = (sChangedGameOptions.dungeonSpeed == DUNGEON_SPEED_SLOW) ? DUNGEON_SPEED_FAST : DUNGEON_SPEED_SLOW;
            break;
        case OPTION_FAR_OFF_PALS:
            sChangedGameOptions.FarOffPals = (sChangedGameOptions.FarOffPals == 0) ? 1 : 0;
            break;
        case OPTION_DAMAGE_TURN:
            sChangedGameOptions.damageTurn = (sChangedGameOptions.damageTurn == 0) ? 1 : 0;
            break;
        case OPTION_GRIDS:
            sChangedGameOptions.gridEnable = (sChangedGameOptions.gridEnable == 0) ? 1 : 0;
            break;
        case OPTION_MAP:
            if (sChangedGameOptions.mapOption == 0) {
                sChangedGameOptions.mapOption = MAP_OPTION_SHADE;
            }
            else {
                sChangedGameOptions.mapOption--;
            }
            break;
        case OPTION_WINDOWS:
            if (sChangedGameOptions.windowColor == 0) {
                sChangedGameOptions.windowColor = WINDOW_COLOR_GREEN;
            }
            else {
                sChangedGameOptions.windowColor--;
            }
            break;
    }
}

static void ChangeGameOptionRight(s32 optionId)
{
    switch (optionId) {
        case OPTION_SPEED:
            sChangedGameOptions.dungeonSpeed = (sChangedGameOptions.dungeonSpeed == DUNGEON_SPEED_SLOW) ? DUNGEON_SPEED_FAST : DUNGEON_SPEED_SLOW;
            break;
        case OPTION_FAR_OFF_PALS:
            sChangedGameOptions.FarOffPals = (sChangedGameOptions.FarOffPals == 0) ? 1 : 0;
            break;
        case OPTION_DAMAGE_TURN:
            sChangedGameOptions.damageTurn = (sChangedGameOptions.damageTurn == 0) ? 1 : 0;
            break;
        case OPTION_GRIDS:
            sChangedGameOptions.gridEnable = (sChangedGameOptions.gridEnable == 0) ? 1 : 0;
            break;
        case OPTION_MAP:
            if (sChangedGameOptions.mapOption == MAP_OPTION_SHADE) {
                sChangedGameOptions.mapOption = 0;
            }
            else {
                sChangedGameOptions.mapOption++;
            }
            break;
        case OPTION_WINDOWS:
            if (sChangedGameOptions.windowColor == WINDOW_COLOR_GREEN) {
                sChangedGameOptions.windowColor = 0;
            }
            else {
                sChangedGameOptions.windowColor++;
            }
            break;
    }
}

// Different in Blue maybe?
static bool8 UnknownDungeonOption(void)
{
    return FALSE;
}

static bool8 UnknownOthersOption(void)
{
    return FALSE;
}

enum
{
    HINTS_CONTROLS,
    HINTS_ORIENTATION,
    HINTS_SEEDS,
    HINTS_MOVES,
    HINTS_RANGE,
    HINTS_LINKING_MOVES,
    HINTS_POKEMON_TYPES,
    HINTS_TOUCH_SCREEN,
    HINTS_COUNT,
};

#define HINTS_COUNT_RED_VERSION HINTS_COUNT - 1 // No Touch Screen Hints in Red

static void ShowHintsMenu(void)
{
    while (1) {
        bool8 bPress = FALSE;

        PrintHintsMenu();
        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if (gRealInputs.repeated & DPAD_DOWN) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorDownWrapAround(&gDungeonMenu, TRUE);
            }
            if (gRealInputs.repeated & DPAD_UP) {
                PlayDungeonCursorSE(TRUE);
                MoveMenuCursorUpWrapAround(&gDungeonMenu, TRUE);
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                PlayDungeonConfirmationSE();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                bPress = TRUE;
                break;
            }
        }

        AddMenuCursorSprite(&gDungeonMenu);
        DungeonRunFrameActions(0x24);
        if (bPress)
            break;

        ShowChosenHintWindow(gDungeonMenu.menuIndex);
    }
}

static void PrintHintsMenu(void)
{
    s32 i;
    WindowHeader header;
    WindowTemplates windows = {
        .id = {
            [0] = {
                .type = WINDOW_TYPE_WITH_HEADER,
                .pos = {2, 2},
                .width = 12,
                .height = 16,
                .unk10 = 16,
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
    header.f3 = 0;
    gDungeonMenu.menuIndex = 0;
    gDungeonMenu.unk1A = HINTS_COUNT_RED_VERSION;
    gDungeonMenu.unk1C = HINTS_COUNT_RED_VERSION;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 16;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    gDungeonMenu.unk0 = 0;
    sub_801317C(&gDungeonMenu.unk28);
    windows.id[0].width = 12;
    windows.id[0].height = windows.id[0].unk10 = sub_80095E4(HINTS_COUNT_RED_VERSION, 12) + 2;
    header.width = 10;
    windows.id[0].pos.x = 2;
    DungeonShowWindows(&windows, TRUE);
    sub_80137B0(&gDungeonMenu, 0);
    sub_80073B8(0);
    PrintFormattedStringOnWindow(16, 0, gUnknown_80FF770, 0, '\0');
    for (i = 0; i < HINTS_COUNT_RED_VERSION; i++) {
        PrintFormattedStringOnWindow(8, GetMenuEntryYCoord(&gDungeonMenu, i), gUnknown_80FF774[i], 0, '\0');
    }
    sub_80073E0(0);
}

extern const u8 *const gUnknown_80FF7EC[2][HINTS_COUNT];

static void ShowChosenHintWindow(s32 hintId)
{
    bool8 unk9 = (gGameOptionsRef->unk9 != 0);

    while (1) {
        bool8 dpadPressed = FALSE;
        WindowHeader header;
        WindowTemplates windows = {
            .id = {
                [0] = {
                    .type = WINDOW_TYPE_WITH_HEADER,
                    .pos = {2, 2},
                    .width = 12,
                    .height = 16,
                    .unk10 = 16,
                    .unk12 = 0,
                    .header = &header,
                },
                [1] = WIN_TEMPLATE_DUMMY,
                [2] = WIN_TEMPLATE_DUMMY,
                [3] = WIN_TEMPLATE_DUMMY,
            }
        };

        header.count = HINTS_COUNT_RED_VERSION;
        header.currId = hintId;
        header.f3 = 0;
        gDungeonMenu.unk1E = hintId;
        gDungeonMenu.unk20 = HINTS_COUNT_RED_VERSION;
        gDungeonMenu.unk1A = 0;
        gDungeonMenu.menuIndex = 0;
        gDungeonMenu.unk1C = 0;
        gDungeonMenu.unk4 = 0;
        gDungeonMenu.firstEntryY = 16;
        gDungeonMenu.unk14.x = 0;
        gDungeonMenu.unk0 = 0;
        sub_801317C(&gDungeonMenu.unk28);
        windows.id[0].width = 24;
        windows.id[0].height = windows.id[0].unk10 = sub_80095E4(HINTS_COUNT, 12) + 2;
        header.width = 10;
        windows.id[0].pos.x = 2;
        DungeonShowWindows(&windows, TRUE);
        gDungeonMenu.unkC = (gWindows[0].x + 19) * 8;
        gDungeonMenu.unkE = ((gWindows[0].y + 1) * 8) - 2;
        sub_80073B8(0);
        PrintFormattedStringOnWindow(16 + hintId * 8, 0, gUnknown_80FF774[hintId], 0, '\0');
        PrintFormattedStringOnWindow(8, 16, gUnknown_80FF7EC[unk9][hintId], 0, '\0');
        sub_80073E0(0);

        while (1) {
            AddMenuCursorSprite(&gDungeonMenu);
            DungeonRunFrameActions(0x24);
            if ((gRealInputs.pressed & DPAD_RIGHT) || gDungeonMenu.unk28.dpad_right) {
                PlayDungeonCursorSE(FALSE);
                if (++hintId == HINTS_COUNT_RED_VERSION) {
                    hintId = 0;
                }
                dpadPressed = TRUE;
                break;
            }
            if ((gRealInputs.pressed & DPAD_LEFT) || gDungeonMenu.unk28.dpad_left) {
                PlayDungeonCursorSE(FALSE);
                if (--hintId == -1) {
                    hintId = HINTS_COUNT_RED_VERSION - 1;
                }
                dpadPressed = TRUE;
                break;
            }

            if ((gRealInputs.pressed & A_BUTTON) || gDungeonMenu.unk28.a_button) {
                PlayDungeonConfirmationSE();
                break;
            }
            if ((gRealInputs.pressed & B_BUTTON) || gDungeonMenu.unk28.b_button) {
                PlayDungeonCancelSE();
                break;
            }
        }

        DungeonRunFrameActions(0x24);
        if (!dpadPressed)
            break;
    }
}
