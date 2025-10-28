#include "global.h"
#include "globaldata.h"
#include "dungeon_action.h"
#include "constants/dungeon_action.h"
#include "dungeon_ai.h"
#include "dungeon_ai_leader.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_range.h"
#include "dungeon_logic.h"
#include "dungeon_generation.h"
#include "dungeon_util.h"
#include "dungeon_strings.h"
#include "pokemon.h"
#include "items.h"
#include "structs/str_item_text.h"
#include "dungeon_action.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_engine.h"
#include "run_dungeon.h"

EWRAM_DATA SubMenuAction gDungeonSubMenu[10] = {0};
EWRAM_DATA s32 gDungeonSubMenuItemsCount = 0;

static const u16 gUnknown_80F6964[NUM_ITEM_CATEGORIES] = {
    [CATEGORY_THROWN_LINE] = 0,
    [CATEGORY_THROWN_ARC] = 0,
    [CATEGORY_BERRIES_SEEDS_VITAMINS] = 13,
    [CATEGORY_FOOD_GUMMIES] = 14,
    [CATEGORY_HELD_ITEMS] = 0,
    [CATEGORY_TMS_HMS] = 16,
    [CATEGORY_POKE] = 0,
    [CATEGORY_7] = 18,
    [CATEGORY_OTHER] = 18,
    [CATEGORY_ORBS] = 49,
    [CATEGORY_LINK_BOX] = 44,
    [CATEGORY_USED_TM] = 18,
};

UNUSED static const u8 *sub_8044BA8(u16 actionId, u8 id)
{
    if (actionId == ACTION_STAIRS && GetFloorType() == FLOOR_TYPE_RESCUE) {
        return gUnknown_80F91EC;
    }
    else {
        if (!AreStringsDifferent(gUnknown_80F7C50[actionId].str, "X")) {
            return gActions[GetItemActionType(id)].useText;
        }
        else {
            return gUnknown_80F7C50[actionId].str;
        }
    }
}

void SetLeaderActionToNothing(bool8 clearActionFields)
{
    EntityInfo * entityInfo = GetLeaderInfo();

    entityInfo->action.action = ACTION_NOTHING;

    if (clearActionFields) {
        entityInfo->action.actionParameters[0].actionUseIndex = 0;
        entityInfo->action.actionParameters[1].actionUseIndex = 0;
        entityInfo->action.itemTargetPosition.x = -1;
        entityInfo->action.itemTargetPosition.y = -1;
    }
}

void SetLeaderActionFields(u16 action)
{
    EntityInfo * entityInfo = GetLeaderInfo();

    entityInfo->action.action = action;
    entityInfo->action.actionParameters[0].actionUseIndex = 0;
    entityInfo->action.actionParameters[1].actionUseIndex = 0;

    entityInfo->action.itemTargetPosition.x = -1;
    entityInfo->action.itemTargetPosition.y = -1;
}

void ClearMonsterActionFields(ActionContainer *actionPointer)
{
    actionPointer->action = ACTION_NOTHING;
    actionPointer->actionParameters[0].actionUseIndex = 0;
    actionPointer->actionParameters[1].actionUseIndex = 0;
}

void SetMonsterActionFields(ActionContainer *actionPointer, u16 action)
{
    actionPointer->action = action;
    actionPointer->actionParameters[0].actionUseIndex = 0;
    actionPointer->actionParameters[1].actionUseIndex = 0;
}

void SetActionPassTurnOrWalk(ActionContainer *actionPointer, s16 species)
{
    if (GetCanMoveFlag(species))
    {
        actionPointer->action = ACTION_WALK;
    }
    else
    {
        actionPointer->action = ACTION_PASS_TURN;
    }
    actionPointer->actionParameters[0].actionUseIndex = 0;
    actionPointer->actionParameters[1].actionUseIndex = 0;
}

Item * sub_8044CC8(Entity *param_1, ActionParameter *param_2, UNUSED s32 a3)
{
  const Tile *tile;
  Item *item;
  EntityInfo *info;

  if (param_2->actionUseIndex >= 1 && param_2->actionUseIndex < INVENTORY_SIZE + 1) {
    item = &gTeamInventoryRef->teamItems[param_2->actionUseIndex - 1];
  }
  else if (param_2->actionUseIndex == 0x80) {
    tile = GetTile((param_2->itemPos).x,(param_2->itemPos).y);
    item = GetItemInfo(tile->object);
  }
  else {
    if (param_2->actionUseIndex == 0x81) {
      info = GetEntInfo(param_1);
    }
    else {
      if (param_2->actionUseIndex >= 0x90 && param_2->actionUseIndex < 0x94) {
        info = GetEntInfo(gDungeon->teamPokemon[param_2->actionUseIndex - 0x90]);
      }
      else {
        return NULL;
      }
    }
    item = &info->heldItem;
  }
  return item;
}

bool8 sub_8044D40(ActionContainer *param_1,s32 index)
{
  Item *item;
  ActionParameter *puVar1;

  puVar1 = &param_1->actionParameters[index];
  if ((u8)(puVar1->actionUseIndex - 1) < INVENTORY_SIZE) {
    item = &gTeamInventoryRef->teamItems[puVar1->actionUseIndex - 1];
    item->id = ITEM_NOTHING;
    item->quantity = 0;
    item->flags = 0;
    FillInventoryGaps();
  }
  else {
    if (puVar1->actionUseIndex != 0x80) {
      return FALSE;
    }
    RemoveGroundItem(&puVar1->itemPos,1);
  }
  return TRUE;
}

Item *sub_8044D90(Entity *entity, s32 index, s32 unused)
{
    EntityInfo *info = GetEntInfo(entity);
    return sub_8044CC8(entity, &info->action.actionParameters[index], unused);
}

Entity *sub_8044DA4(Entity *entity, s32 index)
{
    EntityInfo *info = GetEntInfo(entity);
    return gDungeon->teamPokemon[info->action.actionParameters[index].actionUseIndex];
}

u16 sub_8044DC8(Item *param_1)
{
  if (param_1->id == ITEM_SWITCH_BOX) {
    return 0x35;
  }
  else {
    return gUnknown_80F6964[GetItemCategory(param_1->id)];
  }
}

void sub_8044DF0(Entity *entity, s32 index, u32 unused)
{
  Item *item;
  EntityInfo *info;

  info = GetEntInfo(entity);
  item = sub_8044D90(entity,index,unused);
  if ((info->action).actionParameters[0].actionUseIndex == 0x80) {
    RemoveGroundItem(&(info->action).actionParameters[0].itemPos,1);
  }
  else {
    item->id = ITEM_NOTHING;
    item->quantity = 0;
    item->flags = 0;
    FillInventoryGaps();
  }
}

void sub_8044E24(Entity *entity,int index,u32 unused)
{
  Item *itemPtr;
  EntityInfo *info;
  DungeonPos *pos;
  Item item;

  itemPtr = sub_8044D90(entity,index,unused);
  info = GetEntInfo(entity);
  if (!IsHMItem(itemPtr->id)) {
    if (GetItemCategory(itemPtr->id) == CATEGORY_TMS_HMS) {
      if (info->action.actionParameters[index].actionUseIndex == 0x80) {
        item = *itemPtr;
        pos = &info->action.actionParameters[index].itemPos;
        RemoveGroundItem(pos,1);
        item.quantity = itemPtr->id - 125;
        item.id = ITEM_TM_USED_TM;
        SpawnItem(pos,&item,1);
      }
      else {
        itemPtr->quantity = itemPtr->id - 125;
        itemPtr->id = ITEM_TM_USED_TM;
      }
    }
    else {
      sub_8044DF0(entity,index,unused);
    }
  }
}

// Similar to sub_8044BA8
const u8 *GetDungeonSubMenuItemString(s32 param_1)
{
    u16 actionId = gDungeonSubMenu[param_1].actionId;

    if (actionId == ACTION_STAIRS && GetFloorType() == FLOOR_TYPE_RESCUE) {
        return gUnknown_80F91EC;
    }
    else {
        if (!AreStringsDifferent(gUnknown_80F7C50[actionId].str, "X")) {
            return gActions[GetItemActionType(gDungeonSubMenu[param_1].unk2)].useText;
        }
        else {
            return gUnknown_80F7C50[actionId].str;
        }
    }
}

bool8 CanSubMenuItemBeChosen(s32 itemId)
{
    if (itemId < 0)
        return FALSE;
    else
        return gDungeonSubMenu[itemId].canBeChosen;
}

void AddActionToDungeonSubMenu(u16 actionId, u8 param_2)
{
  int index;

  if (gDungeonSubMenuItemsCount < 10) {
    for(index = 0; index < gDungeonSubMenuItemsCount; index++)
    {
        if (gDungeonSubMenu[index].actionId == actionId) {
          return;
        }
    }
    gDungeonSubMenu[gDungeonSubMenuItemsCount].actionId = actionId;
    gDungeonSubMenu[gDungeonSubMenuItemsCount].unk2 = param_2;
    gDungeonSubMenu[gDungeonSubMenuItemsCount].canBeChosen = TRUE;
    gDungeonSubMenuItemsCount++;
  }
}

s32 ActionToDungeonSubMenuId(u16 actionId)
{
    int index;

    for(index = 0; index < gDungeonSubMenuItemsCount; index++)
    {
        if (gDungeonSubMenu[index].actionId == actionId) {
            return index;
        }
    }
    return -1;
}

void SetActionUnusableInDungeonSubMenu(u16 actionId)
{
    int index;

    for(index = 0; index < gDungeonSubMenuItemsCount; index++)
    {
        if (gDungeonSubMenu[index].actionId == actionId) {
           gDungeonSubMenu[index].canBeChosen = FALSE;
           return;
        }
    }
}

bool8 IsNotAttacking(Entity *param_1, bool8 param_2)
{
    EntityInfo *info;
    u16 *action;

    info = GetEntInfo(param_1);
    action = &(info->action).action;
    if ((param_2 == 0) || (ShouldDisplayEntity(param_1)))
    {
        if(*action == ACTION_NOTHING)
            return TRUE;
        if (*action == ACTION_WALK)
            return TRUE;
        if (*action == ACTION_PASS_TURN)
            return TRUE;
        if (*action == ACTION_UNK5)
            return TRUE;
        return FALSE;
    }
    else {
        return TRUE;
    }
}

void sub_8045064(void)
{
    s32 i, j;

    for (i = 0; i < gDungeonSubMenuItemsCount; i++) {
        for (j = i + 1; j < gDungeonSubMenuItemsCount; j++) {
            SubMenuAction temp;
            SubMenuAction *iPtr = &gDungeonSubMenu[i];
            SubMenuAction *jPtr = &gDungeonSubMenu[j];

            if (gUnknown_80F7C50[iPtr->actionId].val > gUnknown_80F7C50[jPtr->actionId].val) {
                SWAP(*iPtr, *jPtr, temp);
            }
        }
    }
}
