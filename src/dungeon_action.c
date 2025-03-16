#include "global.h"
#include "dungeon_action.h"
#include "constants/ability.h"
#include "constants/dungeon_action.h"
#include "dungeon_ai.h"
#include "dungeon_ai_leader.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_leader.h"
#include "dungeon_movement.h"
#include "dungeon_generation.h"
#include "dungeon_util.h"
#include "dungeon_pokemon_attributes.h"
#include "pokemon.h"
#include "items.h"
#include "structs/str_item_text.h"

extern u8 *gUnknown_80F91EC[];
extern u8 *gUnknown_80F7C50[];
extern u8 gUnknown_80F697C[];
extern s16 gSpeedTurns[2][0x19];

extern void sub_8071B48(void);
extern u8 GetFloorType(void);
extern bool8 sub_8044B28(void);
extern void sub_8086AC0(void);
extern void sub_8043ED0(u32);
extern void sub_807EAA0(u32, u32);
extern void UseAttack(u32);
extern void TriggerWeatherAbilities(void);
extern void sub_8074094(Entity *);
extern void sub_8071DA4(Entity *);
extern void TickStatusHeal(Entity *);

void sub_8044820(void)
{
  s32 movSpeed;
  EntityInfo *entityInfo;
  EntityInfo *entityInfo2;
  Entity * entity;
  Entity * entity2;
  s32 index;

  for (index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++) {
    entity = gDungeon->wildPokemon[index];
    if (EntityIsValid(entity)) {
      if (sub_8044B28()) break;
      entityInfo = GetEntInfo(entity);
      gDungeon->unkB8 = entity;
      TriggerWeatherAbilities();
      if ((entityInfo->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY) == 0) {
        if ((u16)(entityInfo->flags & MOVEMENT_FLAG_UNK_14) != 0) {
            entityInfo->flags &= ~(MOVEMENT_FLAG_UNK_14);
        }
        else
        {
          entityInfo->aiAllySkip = FALSE;
          movSpeed = CalcSpeedStage(entity);
          if (gSpeedTurns[movSpeed][gDungeon->unk644.fractionalTurn] != 0) {
            if (!entityInfo->attacking) {
              entityInfo->flags &= ~(MOVEMENT_FLAG_UNK_14 | MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY);
              entityInfo->recalculateFollow = FALSE;
              TickStatusHeal(entity);
              if (EntityIsValid(entity)) {
                sub_8071DA4(entity);
                RunMonsterAI(entity, 0);
                if (sub_8044B28()) break;
                sub_8072CF4(entity);
                sub_8086AC0();
                sub_8043ED0(0);
                if (sub_8044B28()) break;
              }
            }
          }
        }
      }
    }
  }
  if (sub_8044B28() == 0) {
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
      entity2 = gDungeon->wildPokemon[index];
      if ((EntityIsValid(entity2)) && (entityInfo2 = GetEntInfo(entity2), entityInfo2->aiAllySkip))
      {
        sub_8074094(entity2);
        if (EntityIsValid(entity2)) {
          sub_8071DA4(entity2);
          entityInfo2->aiAllySkip = FALSE;
        }
      }
    }
  }
}

void TrySpawnMonsterAndActivatePlusMinus(void)
{
  EntityInfo * entityInfo;
  Entity *entity;
  u32 isNotEnemy;
  s32 index;

  if (gSpeedTurns[1][gDungeon->unk644.fractionalTurn] != 0) {
    sub_8071B48();
    gDungeon->plusIsActive[0] = FALSE;
    gDungeon->plusIsActive[1] = FALSE;
    gDungeon->minusIsActive[0] = FALSE;
    gDungeon->minusIsActive[1] = FALSE;
    gDungeon->lightningRodPokemon = NULL;
    gDungeon->unk17B38 = 2;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->activePokemon[index];
        if (EntityIsValid(entity)) {
            entityInfo = GetEntInfo(entity);
            entityInfo->attacking = FALSE;

            if(entityInfo->isNotTeamMember)
            {
                isNotEnemy = FALSE;
            }
            else {
                isNotEnemy = TRUE;
            }

            if (AbilityIsActive(entity, ABILITY_LIGHTNINGROD)) {
                gDungeon->lightningRodPokemon = entity;
                gDungeon->unk17B38 = entityInfo->unk98;
            }
            if (AbilityIsActive(entity, ABILITY_MINUS)) {
                gDungeon->minusIsActive[isNotEnemy] = TRUE;
            }
            if (AbilityIsActive(entity, ABILITY_PLUS)) {
                gDungeon->plusIsActive[isNotEnemy] = TRUE;
            }
        }
    }
    sub_8043ED0(0);
  }
}

void sub_8044AB4(void)
{
  s32 index;

  if (gSpeedTurns[1][gDungeon->unk644.fractionalTurn + 1] != 0) {
    for (index = 0; index < DUNGEON_MAX_POKEMON; index++) {
      if (EntityIsValid(gDungeon->activePokemon[index])) {
        UseAttack(0);
        break;
      }
    }
    sub_807EAA0(1,0);
    sub_8086AC0();
    sub_8043ED0(0);
  }
}

bool8 sub_8044B28(void)
{
    if (gDungeon->unk4 == 0) {
        if (GetLeader() == NULL) {
            gDungeon->unk644.unk10 = 1;
        }
        else if (gDungeon->unk2 == 1) {
            gDungeon->unk644.unk10 = 2;
        }
        else if (gDungeon->unk2 != 2) {
            return FALSE;
        }
        else {
            gDungeon->unk644.unk10 = 2;
        }
    }
    return TRUE;
}

bool8 sub_8044B84(void)
{
    if(gDungeon->unk10 != 0)
    {
        return TRUE;
    }
    else {
        return sub_8044B28();
    }
}

const u8 *sub_8044BA8(u16 actionId, u8 id)
{
    if (actionId == ACTION_STAIRS && GetFloorType() == FLOOR_TYPE_RESCUE) {
        return *gUnknown_80F91EC;
    }
    else {
        if (!AreStringsDifferent(gUnknown_80F7C50[actionId << 1], gUnknown_80F697C)) {
            return gActions[GetItemActionType(id)].useText;
        }
        else {
            return gUnknown_80F7C50[actionId << 1];
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

void sub_8044C50(u16 action)
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
