#include "global.h"
#include "globaldata.h"
#include "dungeon_ai.h"
#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/type.h"
#include "code_806CD90.h"
#include "dungeon_items.h"
#include "dungeon_range.h"
#include "dungeon_map_access.h"
#include "dungeon_logic.h"
#include "dungeon_util.h"
#include "structs/str_dungeon.h"
#include "position_util.h"
#include "trap.h"
#include "items.h"
#include "weather.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_moves.h"
#include "position_util.h"
#include "dungeon_music.h"
#include "dungeon_map_access.h"
#include "dungeon_vram.h"
#include "code_806CD90.h"
#include "game_options.h"
#include "dungeon_items.h"
#include "moves.h"
#include "dungeon_random.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/ability.h"
#include "constants/type.h"
#include "constants/move_id.h"
#include "constants/weather.h"
#include "number_util.h"
#include "dungeon_message.h"
#include "math.h"
#include "dungeon_config.h"
#include "dungeon_engine.h"
#include "dungeon_kecleon_shop.h"
#include "dungeon_misc.h"
#include "dungeon_pos_data.h"
#include "dungeon_turn_effects.h"
#include "dungeon_leveling.h"
#include "dungeon_cutscene.h"
#include "dungeon_monster_house.h"
#include "dungeon_strings.h"
#include "warp_target.h"

extern void sub_8073D14(Entity *);
extern void sub_8075708(Entity *entity);
extern void sub_805229C(void);
extern void sub_80420B8(Entity *pokemon);
extern void sub_8041C4C(Entity *pokemon, u32 r1);
extern void sub_805E804(void);
extern bool8 TryUseChosenMove(struct Entity *, u32, u32, u32, u32, struct Move *);
extern void nullsub_97(Entity *entity);
extern void CheckLeaderTile(void);
extern void sub_8075708(Entity *entity);
extern void TryForcedLoss(u32);
extern void sub_8075900(Entity *pokemon, u8 r1);
extern void sub_8075050(EntityInfo *info, Unk_Entity_x184 *strPtr);
extern bool8 sub_803F428(DungeonPos *pos);

extern u8 gUnknown_202F32D;

static EWRAM_DATA s32 gUnknown_202F378 = 0;

void sub_8074FB0(Entity *entity, s32 a1, DungeonPos *pos)
{
    Unk_Entity_x184 *strPtr;
    EntityInfo *entityInfo = GetEntInfo(entity);

    if (entityInfo->numMoveTiles > 3) {
        entityInfo->action.action = 0;
        return;
    }

    if (gGameOptionsRef->dungeonSpeed != 0)
        gUnknown_202F378 = 2;
    else
        gUnknown_202F378 = 1;

    strPtr = &entityInfo->unk184[entityInfo->numMoveTiles];
    strPtr->unk1A = 0;
    strPtr->lastMoveDirection = a1;
    strPtr->previousTargetMovePosition1.x = entity->pos.x;
    strPtr->previousTargetMovePosition1.y = entity->pos.y;
    strPtr->previousTargetMovePosition2.x = pos->x;
    strPtr->previousTargetMovePosition2.y = pos->y;
    strPtr->lastMoveIncrement.x = gUnknown_80F4D44[a1].x * gUnknown_202F378;
    strPtr->lastMoveIncrement.y = gUnknown_80F4D44[a1].y * gUnknown_202F378;
    sub_8075050(entityInfo, strPtr);
}

void sub_8075050(EntityInfo *info, Unk_Entity_x184 *strPtr)
{
    s32 savedX, savedY;

    if (gGameOptionsRef->dungeonSpeed != 0)
        gUnknown_202F378 = 2;
    else
        gUnknown_202F378 = 1;

    info->numMoveTiles++;
    if (info->numMoveTiles == 2) {
        info->unk184[0].walkAnimFramesLeft = 24 / (gUnknown_202F378 * 2);
        info->unk184[0].lastMoveIncrement.x *= 2;
        info->unk184[0].lastMoveIncrement.y *= 2;
        strPtr->walkAnimFramesLeft = 24 / (gUnknown_202F378 * 2);
        strPtr->lastMoveIncrement.x *= 2;
        strPtr->lastMoveIncrement.y *= 2;
    }
    else if (info->numMoveTiles == 3) {
        s32 i;

        savedX = strPtr->lastMoveIncrement.x;
        savedY = strPtr->lastMoveIncrement.y;
        for (i = 0; i < 2; i++) {
            info->unk184[i].walkAnimFramesLeft = 24 / (gUnknown_202F378 * 3);
            info->unk184[i].lastMoveIncrement.x *= 3;
            info->unk184[i].lastMoveIncrement.y *= 3;
            info->unk184[i].lastMoveIncrement.x /= 2;
            info->unk184[i].lastMoveIncrement.y /= 2;
        }
        strPtr->walkAnimFramesLeft = 24 / (gUnknown_202F378 * 3);
        strPtr->lastMoveIncrement.x = savedX * 3;
        strPtr->lastMoveIncrement.y = savedY * 3;
    }
    else if (info->numMoveTiles == 4) {
        s32 i;

        savedX = strPtr->lastMoveIncrement.x;
        savedY = strPtr->lastMoveIncrement.y;
        for (i = 0; i < 3; i++) {
            info->unk184[i].walkAnimFramesLeft = 24 / (gUnknown_202F378 * 4);
            info->unk184[i].lastMoveIncrement.x *= 4;
            info->unk184[i].lastMoveIncrement.y *= 4;
            info->unk184[i].lastMoveIncrement.x /= 3;
            info->unk184[i].lastMoveIncrement.y /= 3;
        }
        strPtr->walkAnimFramesLeft = 24 / (gUnknown_202F378 * 4);
        strPtr->lastMoveIncrement.x = savedX * 4;
        strPtr->lastMoveIncrement.y = savedY * 4;
    }
    else {
        strPtr->walkAnimFramesLeft = 24 / gUnknown_202F378;
    }
}

bool8 DisplayActions(Entity *a0)
{
    s32 i, j, loop;
    Entity *savedEntityPtr;
    bool32 r7 = FALSE;
    bool32 r9 = FALSE;

    gUnknown_202F32D = 0;
    if (gGameOptionsRef->dungeonSpeed != 0)
        gUnknown_202F378 = 2;
    else
        gUnknown_202F378 = 1;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *mon = gDungeon->activePokemon[i];
        if (EntityIsValid(mon)) {
            EntityInfo *monInfo = GetEntInfo(mon);
            if (monInfo->numMoveTiles == 0) {
                if (monInfo->waiting) {
                    monInfo->waiting = FALSE;
                    if ((monInfo->targetPos.x != 0 || monInfo->targetPos.y != 0)
                        && (monInfo->targetPos.x != mon->pos.x || monInfo->targetPos.y != mon->pos.y)
                        && (!CheckVariousStatuses2(mon, TRUE) || !CheckVariousStatuses(mon)))
                    {
                        s32 direction = GetDirectionTowardsPosition(&mon->pos, &monInfo->targetPos);
                        if (direction != monInfo->action.direction)
                            sub_806CE68(mon, direction);
                    }
                }
            }
            else {
                PixelPos pos;

                monInfo->flags |= 0x2000;
                pos.x = X_POS_TO_PIXELPOS(monInfo->unk184[0].previousTargetMovePosition2.x);
                pos.y = Y_POS_TO_PIXELPOS(monInfo->unk184[0].previousTargetMovePosition2.y);
                UpdateEntityPixelPos(mon, &pos);
                sub_806CDFC(mon, 0, monInfo->unk184[0].lastMoveDirection);
                monInfo->notMoving = 0;
                r7 = TRUE;
                if (ShouldDisplayEntity(mon))
                    r9 = TRUE;
            }
        }
    }

    if (!r7)
        return FALSE;

    savedEntityPtr = gDungeon->unkB8;
    gDungeon->unkB8 = a0;
    if (gDungeon->unk644.unk28 == 0 && r9) {
        sub_80526D0(0x35);
        for (loop = 0; loop < 24 / gUnknown_202F378; loop++) {
            DungeonRunFrameActions(7);
            for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
                Entity *mon = gDungeon->activePokemon[i];
                if (EntityIsValid(mon)) {
                    EntityInfo *monInfo = GetEntInfo(mon);
                    Unk_Entity_x184 *strPtr = &monInfo->unk184[monInfo->notMoving];

                    ASM_MATCH_TRICK(i);
                    if (monInfo->numMoveTiles != 0) {
                        IncreaseEntityPixelPos(mon, strPtr->lastMoveIncrement.x, strPtr->lastMoveIncrement.y);
                        if (--strPtr->walkAnimFramesLeft == 0) {
                            if (++monInfo->notMoving == monInfo->numMoveTiles) {
                                monInfo->numMoveTiles = 0;
                            }
                            else {
                                PixelPos pos;

                                pos.x = X_POS_TO_PIXELPOS(monInfo->unk184[monInfo->notMoving].previousTargetMovePosition2.x);
                                pos.y = Y_POS_TO_PIXELPOS(monInfo->unk184[monInfo->notMoving].previousTargetMovePosition2.y);
                                UpdateEntityPixelPos(mon, &pos);
                                sub_806CDFC(mon, 0, monInfo->unk184[monInfo->notMoving].lastMoveDirection);
                            }
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *mon = gDungeon->activePokemon[i];
        if (EntityIsValid(mon)) {
            EntityInfo *monInfo = GetEntInfo(mon);
            monInfo->numMoveTiles = 0;
            nullsub_97(mon);
            if (monInfo->flags & 0x2000) {
                UpdateEntityPixelPos(mon, NULL);
            }
        }
    }

    TryWakeSleepingWildPokemon();
    for (j = 0; j < 2; j++) {
        for (loop = 0; loop < DUNGEON_MAX_POKEMON; loop++) {
            DungeonPos monPosBefore;
            EntityInfo *monInfo;
            Entity *mon = gDungeon->activePokemon[loop];

            if (!EntityIsValid(mon))
                continue;
            if (IsFloorOver())
                break;

            monInfo = GetEntInfo(mon);
            if ((j == 0 && !monInfo->isTeamLeader) || (j != 0 && monInfo->isTeamLeader))
                continue;

            monPosBefore = mon->pos;

            // Statement with no effect needed to match.
            GetEntInfo(mon)->isTeamLeader = GetEntInfo(mon)->isTeamLeader;

            if (monInfo->flags & 0x2000) {
                monInfo->flags &= ~(0x2000);
                if (monInfo->isTeamLeader) {
                    DiscoverMinimap(&mon->pos);
                    sub_807EC28(FALSE);
                    CheckLeaderTile();
                }
                else {
                    sub_8075708(mon);
                }
                if (!EntityIsValid(mon))
                    continue;
                if (IsFloorOver())
                    break;

                TryForcedLoss(0);
                ApplyEndOfTurnEffects(mon);
                if (!EntityIsValid(mon))
                    continue;
                if (IsFloorOver())
                    break;

                EnemyEvolution(mon);
                sub_8046D20();
                sub_8075900(mon, gDungeon->forceMonsterHouse);
            }
            if (!EntityIsValid(mon))
                continue;
            if (IsFloorOver())
                break;

            if (monPosBefore.x != mon->pos.x || monPosBefore.y != mon->pos.y)
                gUnknown_202F32D = 1;

            sub_806A5B8(mon);
            if (sub_80706A4(mon, &mon->pos)) {
                WarpTarget(mon, mon, 0, NULL);
            }
        }
    }

    sub_8086AC0();
    if (!IsFloorOver()) {
        sub_8085140();
        gDungeon->unkB8 = savedEntityPtr;
    }
    else {
        gDungeon->unkB8 = savedEntityPtr;
    }

    return TRUE;
}

void sub_8075680(void)
{
    u32 direction;
    DungeonPos *targetPos;
    Entity *entity;
    EntityInfo *info;
    int index;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->activePokemon[index];
        if ((EntityIsValid(entity)) && (info = GetEntInfo(entity), !info->isTeamLeader)) {
            targetPos = &(info->targetPos);

            if (targetPos->x == 0 && targetPos->y == 0)
                continue;

            if (targetPos->x == entity->pos.x && targetPos->y == entity->pos.y)
                continue;

            if (CheckVariousStatuses2(entity, TRUE))
                continue;

            direction = GetDirectionTowardsPosition(&entity->pos, targetPos);
            info->action.direction = direction & DIRECTION_MASK;
            sub_806CDD4(entity, sub_806CEBC(entity), direction);
        }
    }
}

void nullsub_97(Entity *entity)
{}

void sub_8075708(Entity *entity)
{
    bool8 bVar1;
    bool8 bVar2;
    const Tile *tile;
    Trap *trapData;
    Entity *trap;
    EntityInfo *info;

    info = GetEntInfo(entity);
    if (!EntityIsValid(entity)) {
        return;
    }
    tile = GetTileAtEntitySafe(entity);
    if (((IQSkillIsEnabled(entity, IQ_SUPER_MOBILE)) && (info->invisibleClassStatus.status != STATUS_MOBILE)) &&
        (!HasHeldItem(entity, ITEM_MOBILE_SCARF))) {
        sub_804AE84(&entity->pos);
    }
    trap = tile->object;
    if (trap == NULL) {
        return;
    }

    switch(GetEntityType(trap)) {
        case ENTITY_TRAP:
            trapData = GetTrapInfo(trap);
            bVar1 = FALSE;
            bVar2 = FALSE;
            if ((IQSkillIsEnabled(entity, IQ_TRAP_SEER)) && (!trap->isVisible)) {
                trap->isVisible = TRUE;
                UpdateTrapsVisibility();
                bVar2 = TRUE;
            }

            if (trapData->unk1 == 0) {
                if (!trap->isVisible) goto _080757EC;
                if (info->isNotTeamMember) goto _080757EC;
            }
            else {
                if (trapData->unk1 == 1) {
                    if (!info->isNotTeamMember) goto _080757EC;
                    goto _ret;
                }
                if ((trapData->unk1 == 2) && (!info->isNotTeamMember)) {
                    bVar1 = TRUE;
                }
            _080757EC:
                if (!bVar1) {
                    return;
                }
            }
        _ret:
            if (!bVar2) {
                TryTriggerTrap(entity, &entity->pos, 0, 1);
            }
            break;
        case ENTITY_ITEM:
            sub_8073D14(entity);
            break;
        case ENTITY_NOTHING:
        case ENTITY_MONSTER:
        case ENTITY_UNK_4:
        case ENTITY_UNK_5:
            break;
    }
}

u32 sub_8075818(Entity *entity)
{
    const Tile *tile;
    EntityInfo *entityInfo;
    Entity *subEntity;
    Item *item;
    Trap *trapData;
    u8 r1;

    entityInfo = GetEntInfo(entity);
    if(EntityIsValid(entity))
    {
        tile = GetTileAtEntitySafe(entity);
        if(IQSkillIsEnabled(entity, IQ_SUPER_MOBILE))
            if(!(tile->terrainFlags & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
                return 1;
        subEntity = tile->object;
        if(subEntity != NULL)
        {
            switch(GetEntityType(subEntity))
            {
                case ENTITY_NOTHING:
                case ENTITY_MONSTER:
                case ENTITY_UNK_4:
                case ENTITY_UNK_5:
                    break;
                case ENTITY_TRAP:
                    trapData = GetTrapInfo(subEntity);
                    r1 = 0;
                    if(trapData->unk1 == 0)
                    {
                        if(!subEntity->isVisible || entityInfo->isNotTeamMember)
                            goto flag_check;
                        else
                            goto error;
                    }
                    else if(trapData->unk1 == 1)
                    {
                        if(!entityInfo->isNotTeamMember)
                            goto flag_check;
                        else
                            goto error;
                    }
                    else if(trapData->unk1 == 2)
                    {
                        if(!entityInfo->isNotTeamMember)
                            r1 = 1;
                    }
flag_check:
                    if(r1 == 0)
                        break;
                    else
                        goto error;
                case ENTITY_ITEM:
                    if(!entityInfo->isTeamLeader)
                    {
                        if(!(entityInfo->heldItem.flags & ITEM_FLAG_EXISTS))
                        {
                            if(!(tile->terrainFlags & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
                            {
                                if(entityInfo->isNotTeamMember)
                                    break;
                                else
                                {
                                    item = GetItemInfo(subEntity);
                                    if(!(item->flags & ITEM_FLAG_IN_SHOP))
                                    {
                                        return 1;
                                    }
                                }
                            }
                            else
                            {
                                item = GetItemInfo(subEntity);
                                if(!(item->flags & ITEM_FLAG_IN_SHOP))
                                {
error:
                                    return 1;
                                }
                            }
                        }
                    }
                    break;
            }
        }
    }
    return 0;
}

extern void sub_8041888(u32);

void sub_8075900(Entity *pokemon, u8 r1)
{
    if(EntityIsValid(pokemon))
    {
        if(!GetEntInfo(pokemon)->isNotTeamMember)
        {
            if(!IsFloorOver())
            {
                if(!gDungeon->unk644.monsterHouseTriggered)
                {
                    if((GetTileAtEntitySafe(pokemon)->terrainFlags & TERRAIN_TYPE_IN_MONSTER_HOUSE))
                    {
                        // It's a monster house!
                        LogMessageByIdWithPopupCheckUser(GetLeader(), gPtrItsaMonsterHouseMessage);
                        gDungeon->unk644.monsterHouseTriggeredEvent = TRUE;
                        TriggerMonsterHouse(pokemon, r1);
                        sub_8041888(0);
                        if(sub_803F428(&pokemon->pos))
                            sub_803E708(0x78, 0x39);
                    }
                }
            }
        }
    }
}
