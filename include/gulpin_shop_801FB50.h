#ifndef GUARD_GULPIN_SHOP_801FB50_H
#define GUARD_GULPIN_SHOP_801FB50_H

#include "constants/move.h"
#include "structs/menu.h"
#include "pokemon.h"
#include "structs/str_mon_portrait.h"
#include "structs/str_text.h"

// size: 0x1E0
typedef struct unkStruct_203B27C
{
    /* 0x0 */ u32 mode; // Corresponds to the enum: GulpinShopMode
    /* 0x4 */ s32 state;
    /* 0x8 */ u32 fallbackState;
    /* 0xC */ s16 speciesNum;
    /* 0x10 */ Pokemon *pokeStruct;
    /* 0x14 */ bool8 isNextMoveLinked;
    bool8 unk15;
    /* 0x16 */ bool8 isTeamLeader;
    /* 0x18 */ u32 moveIndex;
    // Group of move ids but not sure purpose just yet...
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    /* 0x24 */ Move moves[MAX_MON_MOVES * 2];
    /* 0x64 */ u16 sequenceMoveIDs[MAX_MON_MOVES];
    /* 0x6C */ u32 menuAction1;
    /* 0x70 */ u32 menuAction2;
    /* 0x74 */ u32 menuAction3;
    /* 0x78 */ u32 menuAction4;
    MenuItem unk7C[8];
    u16 unkBC[8];
    MenuStruct unkCC;
    u8 fill11C[0x16C - 0x11C];
    /* 0x16C */ MonPortraitMsg monPortrait;
    MonPortraitMsg *monPortraitPtr;
    WindowTemplates unk180;
} unkStruct_203B27C;

bool8 sub_801FB50(u32 mode);
u32 sub_801FC40(void);
void sub_801FD7C(void);

#endif // GUARD_GULPIN_SHOP_801FB50_H
