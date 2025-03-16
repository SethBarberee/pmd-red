#ifndef GUARD_GAME_OPTIONS_H
#define GUARD_GAME_OPTIONS_H

enum DungeonSpeed
{
    DUNGEON_SPEED_SLOW,
    DUNGEON_SPEED_FAST,
};

enum FarOffPals
{
    FAROFFPALS_SELF,
    FAROFFPALS_LOCK,
};

// GBA has 3 options while DS has 7
enum MapOption
{
    MAP_OPTION_OFF,
    MAP_OPTION_CLEAR,
    MAP_OPTION_SHADE,
    NUM_GBA_MAP_OPTIONS,
};

enum DSMapOption
{
    TOP_TEAM_DATA_NO_BOTTOM,
    TOP_TEAM_DATA_CLEAR_MAP_BOTTOM,
    TOP_TEAM_DATA_SHADED_MAP_BOTTOM,
    TOP_MESSAGE_LOG_NO_BOTTOM,
    TOP_MESSAGE_LOG_CLEAR_MAP_BOTTOM,
    TOP_MESSAGE_LOG_SHADED_MAP_BOTTOM,
    TOP_MAP_AND_TEAM_NO_BOTTOM,
    NUM_DS_MAP_OPTIONS,
};

enum windowColor
{
    WINDOW_COLOR_BLUE,
    WINDOW_COLOR_RED,
    WINDOW_COLOR_GREEN,
    NUM_WINDOW_COLORS,
};

// size: 0x10
typedef struct GameOptions
{
    // TODO: find where Controls/Touch Screen are in this structure in PMD Blue

    /* 0x0 */ u8 dungeonSpeed;
    /* 0x1 */ u8 FarOffPals;
    /* 0x2 */ bool8 damageTurn;
    /* 0x3 */ bool8 gridEnable;
    /* 0x4 */ u8 mapOption;
    /* 0x5 */ u8 fill5[3];
    /* 0x8 */ u8 windowColor;
    /* 0x9 */ u8 unk9; // maybe Controls?
    /* 0xA */ u8 unkA; // maybe Touch Screen?
    /* 0xB */ u8 playerGender;
    /* 0xC */ u8 unkC;
} GameOptions;

extern GameOptions *gGameOptionsRef;

GameOptions *GetGameOptions(void);
bool8 GameOptionsNotChange(GameOptions *);
void InitializeGameOptions(bool8 initializeGender);
void LoadGameOptions(void);
void SetWindowBGColor(void);
bool8 sub_8094C48(void);
bool8 DoesNotHaveShadedMap(void);
void sub_8094C88(void);

#endif // GUARD_GAME_OPTIONS_H
