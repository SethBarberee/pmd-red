#ifndef GUARD_CODE_80A26CC_H
#define GUARD_CODE_80A26CC_H

// size: 0x14
typedef struct DungeonInfo
{
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s16 unk8;
    /* 0xA */ s16 unkA;
    /* 0xC */ u8 dungeonIndex;
    /* 0xD */ u8 unkD;
    /* 0xE */ s16 unkE;
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
} DungeonInfo;

const DungeonInfo *GetDungeonInfo_80A2608(s32 index);
s16 sub_80A2654(s16 index);
s16 sub_80A2668(s16);
s16 sub_80A2688(u8);
s16 RescueDungeonToScriptDungeonId(s16);
s16 sub_80A26CC(s16);
u8 RescueDungeonToDungeonId(s16 index);
u8 sub_80A2728(s16 index);
u8 ScriptDungeonIdToDungeonId(s16 index);
s16 sub_80A2750(s16);
bool8 IsRescueDungeonAvailable(s16 _rescueDungeonId);
bool8 sub_80A2824(u8 index);
bool8 sub_80A28F0(u8 index);
s32 sub_80A29B0(u8 *);

#endif // GUARD_CODE_80A26CC_H
