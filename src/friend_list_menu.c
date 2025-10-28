#include "global.h"
#include "globaldata.h"
#include "friend_list_menu.h"
#include "constants/dungeon.h"
#include "music_util.h"
#include "code_801602C.h"
#include "code_801B3C0.h"
#include "code_801EE10.h"
#include "code_801EE10_mid.h"
#include "friend_list.h"
#include "code_8024458.h"
#include "code_8099360.h"
#include "common_strings.h"
#include "event_flag.h"
#include "ground_map.h"
#include "input.h"
#include "iq_skill_menu.h"
#include "items.h"
#include "kecleon_bros4.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "unk_ds_only_feature.h"

// there might be more overlap with unkStruct_203B2BC
// I was working on the moves and put the data that seemed to correspond to that
// into a separate struct
typedef struct unkStruct_203B2B4
{
    // size: 0x178
    s32 unk0;
    s32 state;
    u32 fallbackState;
    u8 unkC; // friend Area
    u8 unkD; // friend Area
    s16 species;
    u32 itemIndex;
    BulkItem item1;
    BulkItem item2;
    /* 0x1C */ Pokemon *pokeStruct;
    u32 moveIndex; // some sort of move index
    u16 moveID;
    Move moves[8];
    u16 moveIDs[4]; // some list of move IDs
    u32 menuAction1;
    s32 menuAction2;
    MenuStruct unk78;
    MenuItem unkC8[8];
    u16 unk108[8];
    WindowTemplates unk118;
} unkStruct_203B2B4;

static EWRAM_INIT unkStruct_203B2B4 *gUnknown_203B2B4 = {NULL};

#include "data/friend_list_menu.h"

static void SetFriendListMenuState(s32);
static void sub_802544C(void);
static void sub_8025518(void);
static void sub_8025728(void);
static void sub_802591C(void);
static void sub_80259F0(void);
static void sub_8025A84(void);
static void sub_8025BCC(void);
static void sub_8025BE8(void);
static void sub_8025C04(void);
static void sub_8025CB4(void);
static void sub_8025D90(void);
static void sub_8025DAC(void);
static void sub_8025E08(void);
static void sub_8025E24(void);
static void FriendListMenu_GotoFallbackState(void);
static void sub_8025E68(u32 , BulkItem *);
static bool8 FriendListMenu_isOnTeam(Pokemon *);

enum FriendListMenuStates {
    // 0
    // 1
    // 2
    // 3
    FRIEND_LIST_MENU_STATE_SUMMARY = 4,
    FRIEND_LIST_MENU_STATE_CHECK_IQ = 5,
    FRIEND_LIST_MENU_STATE_STANDBY = 7,
    FRIEND_LIST_MENU_STATE_ITEM_GIVEN = 8,
    FRIEND_LIST_MENU_STATE_ITEM_EXCHANGE = 9,
    FRIEND_LIST_MENU_STATE_TAKE = 0xA,
    FRIEND_LIST_MENU_STATE_GIVE = 0xB,
    // 0xC
    // 0xD
    FRIEND_LIST_MENU_STATE_INFO = 0xE,
    FRIEND_LIST_MENU_STATE_MOVES = 0xF,
    // 0x10
    // 0x11
    // 0x12
    FRIEND_LIST_MENU_STATE_EXIT = 0x13
};

enum FriendListMenuActions {
    FRIEND_LIST_MENU_NULL = 1,
    FRIEND_LIST_MENU_INFO = 4,
    FRIEND_LIST_MENU_SUMMARY = 4,
    FRIEND_LIST_MENU_CHECK_IQ = 5,
    FRIEND_LIST_MENU_MOVES,
    FRIEND_LIST_MENU_VISIT,
    // 8
    FRIEND_LIST_MENU_STANDBY = 9,
    FRIEND_LIST_MENU_GIVE = 0xA,
    FRIEND_LIST_MENU_TAKE,

};

bool8 CreateFriendListMenu(s32 param_1)
{
  if ((param_1 == 2) && (sub_8024108(4) != 0)) {
    return FALSE;
  }
  else {
    gUnknown_203B2B4 = MemoryAlloc(sizeof(unkStruct_203B2B4),8);
    gUnknown_203B2B4->menuAction1 = 0;
    gUnknown_203B2B4->unk0 = param_1;
    gUnknown_203B2B4->unkC = MapIdToFriendAreaId(GetGroundMapID());
    gUnknown_203B2B4->unkD = 0;
    if (gUnknown_203B2B4->unk0 == 2) {
      SetFriendListMenuState(0);
    }
    else {
      SetFriendListMenuState(1);
    }
    return TRUE;
  }
}

u32 sub_8025354(void)
{
  switch(gUnknown_203B2B4->state) {
    case FRIEND_LIST_MENU_STATE_EXIT:
        return 3;
    case 1:
    case 2:
        sub_80259F0();
        break;
    case 3:
        sub_8025A84();
        break;
    case FRIEND_LIST_MENU_STATE_SUMMARY:
        sub_8025BCC();
        break;
    case FRIEND_LIST_MENU_STATE_CHECK_IQ:
        sub_8025BE8();
        break;
    case FRIEND_LIST_MENU_STATE_GIVE:
    case 0xc:
        sub_8025C04();
        break;
    case 0xd:
        sub_8025CB4();
        break;
    case FRIEND_LIST_MENU_STATE_INFO:
        sub_8025D90();
        break;
    case FRIEND_LIST_MENU_STATE_MOVES:
    case 0x10:
        sub_8025DAC();
        break;
    case 0x11:
        sub_8025E08();
        break;
    case 0x12:
        sub_8025E24();
        break;
    default:
        FriendListMenu_GotoFallbackState();
        break;
  }
  return 0;
}

u8 sub_802540C(void)
{
    return gUnknown_203B2B4->unkD;
}

void CleanFriendListMenu(void)
{
    TRY_FREE_AND_SET_NULL(gUnknown_203B2B4);
}

static void SetFriendListMenuState(s32 newState)
{
    gUnknown_203B2B4->state = newState;
    sub_802544C();
    sub_8025518();
}

static void sub_802544C(void)
{
    s32 i;

    RestoreSavedWindows(&gUnknown_203B2B4->unk118);

    switch (gUnknown_203B2B4->state) {
        case 3:
            if (gUnknown_203B2B4->unk0 == 0)
                gUnknown_203B2B4->unk118.id[3] = sUnknown_80DD190;

            sub_8025728();
            gUnknown_203B2B4->unk118.id[2] = sUnknown_80DD160;
            sub_8012CAC(&gUnknown_203B2B4->unk118.id[2], gUnknown_203B2B4->unkC8);
            break;
        case 13:
            sub_802591C();
            gUnknown_203B2B4->unk118.id[2] = sUnknown_80DD178;
            sub_8012CAC(&gUnknown_203B2B4->unk118.id[2], gUnknown_203B2B4->unkC8);
            break;
        default:
            for (i = 0; i < 4; i++)
                gUnknown_203B2B4->unk118.id[i] = sUnknown_80DD148;
            break;

    }

    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B2B4->unk118, TRUE, TRUE);
}

static void sub_8025518(void)
{
  u32 uVar3;
  Item item;

  switch(gUnknown_203B2B4->state)
  {
    case 0:
        gUnknown_203B2B4->fallbackState = 1;
        CreateDialogueBoxAndPortrait(sVisitWhoPrompt,0,0,0x301);
        break;
    case 1:
        uVar3 = 4;
        if (gUnknown_203B2B4->unk0 == 0) {
            uVar3 = 2;
        }
        FriendList_Init(uVar3,0,0,10);
        break;
    case 2:
        sub_8023B7C(1);
        break;
    case 3:
        if (gUnknown_203B2B4->unk0 == 0) {
            sub_8025E68(3,&gUnknown_203B2B4->item2);
        }
        FriendList_ShowWindow();
        PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[0],gUnknown_203B2B4->pokeStruct,7);
        PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[1],gUnknown_203B2B4->pokeStruct,6);
        sub_8012D60(&gUnknown_203B2B4->unk78,gUnknown_203B2B4->unkC8,0,gUnknown_203B2B4->unk108,gUnknown_203B2B4->menuAction1,2);
        break;
    case FRIEND_LIST_MENU_STATE_SUMMARY:
        sub_8024458(gUnknown_203B2B4->species,2);
        break;
    case FRIEND_LIST_MENU_STATE_CHECK_IQ:
        CreateIQSkillMenu(gUnknown_203B2B4->species);
        break;
    case FRIEND_LIST_MENU_STATE_GIVE:
        sub_801A5D8(1, 0, NULL, 10);
        break;
    case 0xc:
        sub_801A8D0(TRUE);
        break;
    case 0xd:
        sub_801A9E0();
        sub_8012D60(&gUnknown_203B2B4->unk78,gUnknown_203B2B4->unkC8,0,gUnknown_203B2B4->unk108,gUnknown_203B2B4->menuAction2,2);
        break;
    case FRIEND_LIST_MENU_STATE_INFO:
        BulkItemToItem(&item, &gUnknown_203B2B4->item1);
        InitItemDescriptionWindow(&item);
        break;
    case FRIEND_LIST_MENU_STATE_ITEM_GIVEN:
        gUnknown_203B2B4->fallbackState = 2;
        CreateDialogueBoxAndPortrait(sItemHandedOver,0,0,0x101);
        break;
    case FRIEND_LIST_MENU_STATE_ITEM_EXCHANGE:
        gUnknown_203B2B4->fallbackState = 2;
        CreateDialogueBoxAndPortrait(sItemExchanged,0,0,0x101);
        break;
    case FRIEND_LIST_MENU_STATE_TAKE:
        gUnknown_203B2B4->fallbackState = 2;
        CreateDialogueBoxAndPortrait(sReturnedToToolbox,0,0,0x101);
        break;
    case FRIEND_LIST_MENU_STATE_STANDBY:
        gUnknown_203B2B4->fallbackState = 1;
        PlaySound(0xcf);
        CreateDialogueBoxAndPortrait(sLeftOnStandby,0,0,0x101);
        break;
    case FRIEND_LIST_MENU_STATE_MOVES:
        unk_CopyMoves4To8(gUnknown_203B2B4->moves,gUnknown_203B2B4->pokeStruct->moves);
        sub_801EE10(3,gUnknown_203B2B4->species,gUnknown_203B2B4->moves,0,NULL,0);
        break;
    case 0x10:
        sub_801F1B0(TRUE, FALSE);
        break;
    case 0x11:
        GetLinkedSequence(gUnknown_203B2B4->moveIndex,gUnknown_203B2B4->moves, gUnknown_203B2B4->moveIDs);
        sub_801F808(gUnknown_203B2B4->moveIDs);
        break;
    case 0x12:
        CreateConfirmNameMenu(2,gUnknown_203B2B4->pokeStruct->name);
        break;
    case FRIEND_LIST_MENU_STATE_EXIT:
        break;
  }
}

static void sub_8025728(void)
{
    int index;
    Pokemon *pokeStruct;
    s32 loopMax = 0;

    pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2B4->species];
    MemoryFill16(gUnknown_203B2B4->unk108,0,sizeof(gUnknown_203B2B4->unk108));
    if (gUnknown_203B2B4->unk0 == 0) {
        gUnknown_203B2B4->unkC8[loopMax].text = sGive;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_GIVE;
        if (GetNumberOfFilledInventorySlots() == 0) {
            gUnknown_203B2B4->unk108[loopMax] = 1;
        }
        loopMax += 1;

        gUnknown_203B2B4->unkC8[loopMax].text = sTake;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_TAKE;
        if ((INVENTORY_SIZE <= GetNumberOfFilledInventorySlots()) || (gUnknown_203B2B4->item2.id == ITEM_NOTHING)) {
            gUnknown_203B2B4->unk108[loopMax] = 1;
        }
        loopMax += 1;

        if (FriendListMenu_isOnTeam(pokeStruct)) {
            gUnknown_203B2B4->unkC8[loopMax].text = sStandBy;
            gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_STANDBY;
            loopMax += 1;
        }
    }
    else {
        gUnknown_203B2B4->unkC8[loopMax].text = sVisit;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_VISIT;
        if (gUnknown_203B2B4->unkC == GetFriendArea(gUnknown_203B2B4->pokeStruct->speciesNum)) {
            gUnknown_203B2B4->unk108[loopMax] = 1;
        }
        loopMax += 1;
    }
    if ((pokeStruct->speciesNum == 0x13d) &&
        (IsPokemonRenamed(pokeStruct))) {
        gUnknown_203B2B4->unkC8[loopMax].text = sName;
        gUnknown_203B2B4->unkC8[loopMax].menuAction = 8;
        loopMax += 1;
    }
    gUnknown_203B2B4->unkC8[loopMax].text = sSummary;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_SUMMARY;
    loopMax += 1;
    gUnknown_203B2B4->unkC8[loopMax].text = sMoves;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_MOVES;
    loopMax += 1;
    gUnknown_203B2B4->unkC8[loopMax].text = sCheckIQ;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_CHECK_IQ;
    loopMax += 1;
    gUnknown_203B2B4->unkC8[loopMax].text = NULL;
    gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_NULL;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2B4->unk108[index] == 0)
        {
            if (gUnknown_203B2B4->unkC8[index].menuAction == gUnknown_203B2B4->menuAction1)
                return;
        }
    }
    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2B4->unk108[index] == 0)
        {
            gUnknown_203B2B4->menuAction1 = gUnknown_203B2B4->unkC8[index].menuAction;
            break;
        }
    }
}

static void sub_802591C(void)
{
  int index;
  s32 loopMax = 0;


  MemoryFill16(gUnknown_203B2B4->unk108,0, sizeof(gUnknown_203B2B4->unk108));

  gUnknown_203B2B4->unkC8[loopMax].text = sGive;
  gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_GIVE;
  if (GetNumberOfFilledInventorySlots() == 0) {
      gUnknown_203B2B4->unk108[loopMax] = 1;
  }
  loopMax += 1;
  gUnknown_203B2B4->unkC8[loopMax].text = gCommonInfo[0];
  gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_INFO;
  loopMax += 1;
  gUnknown_203B2B4->unkC8[loopMax].text = NULL;
  gUnknown_203B2B4->unkC8[loopMax].menuAction = FRIEND_LIST_MENU_NULL;

  for(index = 0; index < loopMax; index++)
  {
      if(gUnknown_203B2B4->unk108[index] == 0)
      {
          if (gUnknown_203B2B4->unkC8[index].menuAction == gUnknown_203B2B4->menuAction2)
            return;
      }
  }
  for(index = 0; index < loopMax; index++)
  {
      if(gUnknown_203B2B4->unk108[index] == 0)
      {
          gUnknown_203B2B4->menuAction2 = gUnknown_203B2B4->unkC8[index].menuAction;
          break;
      }
  }
}

static void sub_80259F0(void)
{
    switch(FriendList_HandleInput(TRUE))
    {
        case 3:
            gUnknown_203B2B4->species = FriendList_GetCurrId();
            gUnknown_203B2B4->pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2B4->species];
            PeekPokemonItem(gUnknown_203B2B4->species, &gUnknown_203B2B4->item2);
            SetFriendListMenuState(3);
            break;
        case 4:
            gUnknown_203B2B4->species = FriendList_GetCurrId();
            gUnknown_203B2B4->pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2B4->species];
            PeekPokemonItem(gUnknown_203B2B4->species, &gUnknown_203B2B4->item2);
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_SUMMARY);
            break;
        case 2:
            FriendList_Free();
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_EXIT);
            break;
    }
}

static void sub_8025A84(void)
{
    s32 menuAction = 0;

    FriendList_HandleInput(FALSE);
    if(!sub_8012FD8(&gUnknown_203B2B4->unk78))
    {
        sub_8013114(&gUnknown_203B2B4->unk78, &menuAction);
        if(menuAction != FRIEND_LIST_MENU_NULL) gUnknown_203B2B4->menuAction1 = menuAction;
    }
    switch(menuAction)
    {
        case FRIEND_LIST_MENU_VISIT:
            gUnknown_203B2B4->unkD = GetFriendArea(gUnknown_203B2B4->pokeStruct->speciesNum);
            FriendList_Free();
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_EXIT);
            break;
        case FRIEND_LIST_MENU_GIVE:
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_GIVE);
            break;
        case FRIEND_LIST_MENU_TAKE:
            PlaySound(0x14d);
            if(gUnknown_203B2B4->item2.id != ITEM_NOTHING)
            {
                AddHeldItemToInventory(&gUnknown_203B2B4->item2);
            }
            FillInventoryGaps();
            gUnknown_203B2B4->item2.id = ITEM_NOTHING;
            gUnknown_203B2B4->item2.quantity = 0;
            GivePokemonItem(gUnknown_203B2B4->species, &gUnknown_203B2B4->item2);
            nullsub_104();
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_TAKE);
            break;
        case FRIEND_LIST_MENU_STANDBY:
            gUnknown_203B2B4->pokeStruct->flags &= ~(POKEMON_FLAG_ON_TEAM);
            nullsub_104();
            sub_808ED00();
            FriendList_Free();
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_STANDBY);
            break;
        case FRIEND_LIST_MENU_MOVES:
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_MOVES);
            break;
        case 8:
            SetFriendListMenuState(0x12);
            break;
        case FRIEND_LIST_MENU_SUMMARY:
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_SUMMARY);
            break;
        case FRIEND_LIST_MENU_CHECK_IQ:
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_CHECK_IQ);
            break;
        case FRIEND_LIST_MENU_NULL:
            SetFriendListMenuState(0x2);
            break;
        case 2:
        case 3:
            break;
    }
}

static void sub_8025BCC(void)
{
    switch(sub_80244E4())
    {
        case 2:
        case 3:
            sub_802453C();
            SetFriendListMenuState(2);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8025BE8(void)
{
    switch(sub_801BF48())
    {
        case 2:
        case 3:
            CleanIQSkillMenu();
            SetFriendListMenuState(2);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8025C04(void)
{
    switch(sub_801A6E8(TRUE))
    {
        case 3:
            gUnknown_203B2B4->itemIndex = sub_801A8AC();
            gUnknown_203B2B4->item1.id = gTeamInventoryRef->teamItems[gUnknown_203B2B4->itemIndex].id;
            gUnknown_203B2B4->item1.quantity = gTeamInventoryRef->teamItems[gUnknown_203B2B4->itemIndex].quantity;
            SetFriendListMenuState(0xD);
            break;
        case 4:
            gUnknown_203B2B4->itemIndex = sub_801A8AC();
            gUnknown_203B2B4->item1.id = gTeamInventoryRef->teamItems[gUnknown_203B2B4->itemIndex].id;
            gUnknown_203B2B4->item1.quantity = gTeamInventoryRef->teamItems[gUnknown_203B2B4->itemIndex].quantity;
            sub_8099690(0);
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_INFO);
            break;
        case 2:
            sub_801A928();
            SetFriendListMenuState(2);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_8025CB4(void)
{
  u32 nextState;
  s32 menuAction;
  struct unkStruct_8090F58 a3;
  Item item;

  menuAction = 0;
  sub_801A6E8(FALSE);
  if ((!sub_8012FD8(&gUnknown_203B2B4->unk78)) && (sub_8013114(&gUnknown_203B2B4->unk78,&menuAction), menuAction != FRIEND_LIST_MENU_NULL)) {
    gUnknown_203B2B4->menuAction2 = menuAction;
  }

    switch(menuAction)
    {
        case FRIEND_LIST_MENU_GIVE:
            nextState = FRIEND_LIST_MENU_STATE_ITEM_GIVEN;
            PlaySound(0x14d);
            ShiftItemsDownFrom(gUnknown_203B2B4->itemIndex);
            FillInventoryGaps();
            if ((gUnknown_203B2B4->item2).id != 0) {
                AddHeldItemToInventory(&gUnknown_203B2B4->item2);
                nextState = FRIEND_LIST_MENU_STATE_ITEM_EXCHANGE;
            }
            BulkItemToItem(&item,&gUnknown_203B2B4->item1);
            a3.unk0 = 0;
            a3.unk4 = 0;
            a3.unk8 = 1;
            item.flags = ITEM_FLAG_EXISTS;
            sub_8090E14(gFormatBuffer_Items[1],&item,&a3);
            GivePokemonItem(gUnknown_203B2B4->species,&gUnknown_203B2B4->item1);
            sub_801A928();
            nullsub_104();
            SetFriendListMenuState(nextState);
            break;
        case FRIEND_LIST_MENU_INFO:
            sub_8099690(0);
            SetFriendListMenuState(FRIEND_LIST_MENU_STATE_INFO);
            break;
        case FRIEND_LIST_MENU_NULL:
            SetFriendListMenuState(0xc);
            break;
    }
}

static void sub_8025D90(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            FreeItemDescriptionWindow();
            SetFriendListMenuState(0xC);
        case 0:
        case 1:
            break;
    }
}

static void sub_8025DAC(void)
{
    switch(sub_801EF38(1))
    {
        case 3:
            gUnknown_203B2B4->moveIndex = sub_801F194();
            gUnknown_203B2B4->moveID = gUnknown_203B2B4->moves[gUnknown_203B2B4->moveIndex].id;
            SetFriendListMenuState(0x11);
            break;
        case 4:
            gUnknown_203B2B4->moveIndex = sub_801F194();
            gUnknown_203B2B4->moveID = gUnknown_203B2B4->moves[gUnknown_203B2B4->moveIndex].id;
            SetFriendListMenuState(0x11);
            break;
        case 2:
            sub_801F214();
            sub_8094060(gUnknown_203B2B4->moves,gUnknown_203B2B4->pokeStruct->moves);
            SetFriendListMenuState(0x2);
            break;
    }
}

static void sub_8025E08(void)
{
    switch(sub_801F890())
    {
        case 2:
        case 3:
            sub_801F8D0();
            SetFriendListMenuState(0x10);
        case 0:
        case 1:
            break;
    }
}

static void sub_8025E24(void)
{
    switch(sub_8016080())
    {
        case 2:
        case 3:
            CleanConfirmNameMenu();
            nullsub_104();
            SetFriendListMenuState(0x2);
            break;
    }
}

static void FriendListMenu_GotoFallbackState(void)
{
    s32 local;
    if(sub_80144A4(&local) == 0)
    {
        SetFriendListMenuState(gUnknown_203B2B4->fallbackState);
    }
}

static void sub_8025E68(u32 r0, BulkItem *heldItem)
{
    Item item;
    struct unkStruct_8090F58 a3;

    CallPrepareTextbox_8008C54(r0);
    sub_80073B8(r0);
    BulkItemToItem(&item, heldItem);
    a3.unk0 = 0;
    a3.unk4 = 0;
    a3.unk8 = 1;
    item.flags = ITEM_FLAG_EXISTS;
    sub_8090E14(gFormatBuffer_Items[0], &item, &a3);
    PrintFormattedStringOnWindow(4, 3, sItemBuffered, r0, 0);
    sub_80073E0(r0);
}

static bool8 FriendListMenu_isOnTeam(Pokemon *pokeStruct)
{
    if (pokeStruct->isTeamLeader)
        return FALSE;

    if (IsMonPartner(pokeStruct) && !sub_80023E4(8))
        return FALSE;

    return TRUE;
}
