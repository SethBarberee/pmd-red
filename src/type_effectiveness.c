#include "global.h"
#include "type_effectiveness.h"
#include "constants/ability.h"
#include "constants/status.h"
#include "constants/weather.h"
#include "structs/str_dungeon.h"
#include "dungeon_message.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "math.h"
#include "status.h"
#include "dungeon_config.h"
#include "weather.h"


u32 gUnknown_8106EFC[] = { 0x00, 0x00  };
s48_16 gUnknown_8106F04 = { 0x0, 0x10000 };
s48_16 gUnknown_8106F0C = { 0x0, 0x20000 };
s48_16 gUnknown_8106F14 = { 0x0, 0x18000 };
s48_16 gUnknown_8106F1C = { 0x0, 0x8000 };
u8 gUnknown_8106F24[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0x03,
                          0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, 0x01, 0x00 };
s48_16 gUnknown_8106F3C = {0x0, 0x8000};
s48_16 gUnknown_8106F44 = {0x0, 0xE666};
s48_16 gUnknown_8106F4C = {0x0, 0x18000};


struct dumb_struct
{
    s48_16 *unk0[NUM_EFFECTIVENESS];
};

struct dumb_struct gUnknown_8106F54 = {
        &gUnknown_8106F3C, // IMMUNE
        &gUnknown_8106F44, // RESIST
        &gUnknown_8106F04, // NEUTRAL
        &gUnknown_8106F4C, // SUPER
};

s48_16 gUnknown_8106F64 = {0x0, 0xC000};
u32 gTypeEffectivenessMultipliers[] = {0, 1, 2, 4};


struct unkStruct_806D010
{
    s32 unk0;
    u32 unk4;
    u32 effectiveness;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
};

extern u8 *gUnknown_80FEDE8[];
extern u8 *gUnknown_80FEDC8[];
extern u8 *gUnknown_80FEDA8[];
extern u8 *gUnknown_80FED88[];

void sub_80428D8(Entity *);
void sub_8042978(Entity *);
void sub_804298C(Entity *);
void sub_80428EC(Entity *);

bool8 sub_806E100(s48_16 *param_1, Entity *pokemon, Entity *target, u8 type, struct unkStruct_806D010 *param_5)
{
  bool8 torrentFlag;
  bool8 overgrowFlag;
  bool8 swarmFlag;
  bool8 blazeFlag;
  bool8 torrentVisualFlag;
  bool8 overgrowVisualFlag;
  bool8 swarmVisualFlag;
  bool8 blazeVisualFlag;
  bool8 bVar4;
  EntityInfo *targetInfo;
  s32 effectiveness;
  s32 index;
  struct dumb_struct local_48;
  s32 local_38 [2];
  s32 hasWonderGuard;
  s32 normalOrFightingType;
  EntityInfo *pokemonInfo;
  u8 weather;
  s32 temp;

  bVar4 = FALSE;
  normalOrFightingType = FALSE;
  pokemonInfo = GetEntInfo(pokemon);
  targetInfo = GetEntInfo(target);
  FP48_16_FromS32(param_1, 1);
  param_5->unkD = 0;
  param_5->unkE = 0;
  hasWonderGuard = FALSE;
  if (!EntityIsValid(target)) {
    return TRUE;
  }
  else {
    if ((type == TYPE_NORMAL) || (type == TYPE_FIGHTING)) {
      normalOrFightingType = TRUE;
    }
    if ((AbilityIsActive(target, ABILITY_WONDER_GUARD)) && (type != TYPE_NONE)) {
      hasWonderGuard = TRUE;
    }
    param_5->effectiveness = EFFECTIVENESS_NEUTRAL;
    for (index = 0; index < 2; index++) {
      local_48 = gUnknown_8106F54;
      if (F48_16_IsZero(param_1)) break;
      if (((normalOrFightingType) && (targetInfo->types[index] == TYPE_GHOST)) && (targetInfo->exposed == FALSE)) {
            effectiveness = EFFECTIVENESS_IMMUNE;
            gDungeon->unk134.pokemonExposed = TRUE;
      }
      else {
            effectiveness = gTypeEffectivenessChart[type][targetInfo->types[index]];
      }
      if (effectiveness != EFFECTIVENESS_NEUTRAL) {
        F48_16_SMul(param_1,param_1,local_48.unk0[effectiveness]);
      }
      local_38[index] = effectiveness;
      gDungeon->unk134.unk13C[index] = effectiveness;
    }

    param_5->effectiveness = gEffectivenessChart[local_38[0]][local_38[1]];
    bVar4 = TRUE;
    if ((param_5->effectiveness != EFFECTIVENESS_SUPER) && (bVar4 = FALSE, hasWonderGuard)) {
      temp = gUnknown_8106EFC[1];
      param_1->hi = gUnknown_8106EFC[0];
      param_1->lo = temp;
    }

    if (((type == TYPE_FIRE) || (type == TYPE_ICE)) && (AbilityIsActive(target,ABILITY_THICK_FAT))) {
      gDungeon->unk134.unk16D = TRUE;
      F48_16_SMul(param_1,param_1, &gUnknown_8106F1C);
    }
    if ((type == TYPE_FIRE) && (GetFlashFireStatus(target) != FLASH_FIRE_STATUS_NONE)) {
      gDungeon->unk134.fill16E[0] = TRUE;
      FP48_16_FromS32(param_1,0);
      param_5->effectiveness = EFFECTIVENESS_IMMUNE;
      param_5->unkD = 0;
      param_5->unkE = 1;
      bVar4 = FALSE;
    }
    if ((type == TYPE_GROUND) && (AbilityIsActive(target, ABILITY_LEVITATE))) {
      gDungeon->unk134.fill16E[1] = TRUE;
      FP48_16_FromS32(param_1,0);
      param_5->effectiveness = EFFECTIVENESS_IMMUNE;
      param_5->unkD = 0;
      param_5->unkE = 1;
      bVar4 = FALSE;
    }
    if ((type == TYPE_WATER) && (AbilityIsActive(pokemon, ABILITY_TORRENT))) {
      torrentFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      torrentVisualFlag = SetVisualFlags(pokemonInfo,0x80,torrentFlag);
      if (torrentFlag) {
        gDungeon->unk134.fill16E[2] = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F0C);
      }
      if (torrentVisualFlag) {
        sub_80428EC(pokemon);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEDA8);
      }
    }
    if ((type == TYPE_GRASS) && (AbilityIsActive(pokemon, ABILITY_OVERGROW))) {
      overgrowFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      overgrowVisualFlag = SetVisualFlags(pokemonInfo,2,overgrowFlag);
      if (overgrowFlag) {
        gDungeon->unk134.fill16E[3] = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F0C);
      }
      if (overgrowVisualFlag) {
        sub_80428D8(pokemon);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FED88);
      }
    }
    if ((type == TYPE_BUG) && (AbilityIsActive(pokemon, ABILITY_SWARM))) {
      swarmFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      swarmVisualFlag = SetVisualFlags(pokemonInfo,0x10,swarmFlag);
      if (swarmFlag) {
        gDungeon->unk134.fill16E[4] = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F0C);
      }
      if (swarmVisualFlag) {
        sub_8042978(pokemon);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEDC8);
      }
    }
    if ((type == TYPE_FIRE) && (AbilityIsActive(pokemon, ABILITY_BLAZE))) {
      blazeFlag = pokemonInfo->maxHPStat / 4 >= pokemonInfo->HP;
      blazeVisualFlag = SetVisualFlags(pokemonInfo,0x20,blazeFlag);
      if (blazeFlag) {
        gDungeon->unk134.fill16E[5] = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F0C);
      }
      if (blazeVisualFlag) {
        sub_804298C(pokemon);
        TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FEDE8);
      }
    }
    if (!(F48_16_IsZero(param_1)) && (MonsterIsType(pokemon, type))) {
      gDungeon->unk134.fill16E[6] = TRUE;
      F48_16_SMul(param_1,param_1, &gUnknown_8106F14);
    }
    weather = GetApparentWeather(pokemon);
    if (weather == WEATHER_SUNNY) {
      if (type == TYPE_FIRE) {
        gDungeon->unk134.unk16C = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F14);
      }
      else if (type == TYPE_WATER) {
        gDungeon->unk134.unk16C = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F1C);
      }
    }
    if (weather == WEATHER_RAIN) {
      if (type == TYPE_FIRE) {
        gDungeon->unk134.unk16B = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F1C);
      }
      else if (type == TYPE_WATER) {
        gDungeon->unk134.unk16B = TRUE;
        F48_16_SMul(param_1,param_1, &gUnknown_8106F14);
      }
    }
    if ((weather == WEATHER_CLOUDY) && (type != TYPE_NORMAL)) {
      F48_16_SMul(param_1,param_1, &gUnknown_8106F64);
      gDungeon->unk134.unk16A = TRUE;
    }
    if (((gDungeon->weather.mudSportTurns != 0) || (weather == WEATHER_FOG)) && (type == TYPE_ELECTRIC)) {
      gDungeon->unk134.fill16E[7] = TRUE;
      F48_16_SMul(param_1,param_1, &gUnknown_8106F1C);
    }
    if ((gDungeon->weather.waterSportTurns != 0) && (type == TYPE_FIRE)) {
      gDungeon->unk134.fill16E[8] = TRUE;
      F48_16_SMul(param_1,param_1, &gUnknown_8106F1C);
    }
    if ((type == TYPE_ELECTRIC) && (pokemonInfo->bideClassStatus.status == STATUS_CHARGING)) {
      gDungeon->unk134.fill16E[9] = TRUE;
      F48_16_SMul(param_1,param_1, &gUnknown_8106F0C);
    }
  }
  return bVar4;
}

s32 WeightWeakTypePicker(Entity *user, Entity *target, u8 moveType)
{
    s32 weight = 1;
    bool8 checkExposed = FALSE;
    EntityInfo *userData;
    EntityInfo *targetData;
    u8 *targetTypes;
    u8 *targetType;
    u32 moveTypeOffset;
    if (!EntityIsValid(target))
    {
        return 1;
    }
    if (moveType == TYPE_NORMAL || moveType == TYPE_FIGHTING)
    {
        checkExposed = TRUE;
    }
    userData = GetEntInfo(user);
    targetData = GetEntInfo(target);
    if (moveType == TYPE_FIRE && GetFlashFireStatus(target) != FLASH_FIRE_STATUS_NONE)
    {
        return 0;
    }
    if (moveType == TYPE_ELECTRIC && AbilityIsActive(target, ABILITY_VOLT_ABSORB))
    {
        return 0;
    }
    if (moveType == TYPE_WATER && AbilityIsActive(target, ABILITY_WATER_ABSORB))
    {
        return 0;
    }
    if (moveType == TYPE_GROUND && AbilityIsActive(target, ABILITY_LEVITATE))
    {
        return 1;
    }
    targetTypes = targetData->types;
    moveTypeOffset = moveType * NUM_TYPES * sizeof(s16);
    targetType = targetData->types;
    do
    {
        s32 effectiveness;
        u32 typeEffectivenessMultipliers[NUM_EFFECTIVENESS];
        memcpy(typeEffectivenessMultipliers, gTypeEffectivenessMultipliers, NUM_EFFECTIVENESS * sizeof(u32));
        if (checkExposed && *targetType == TYPE_GHOST && !targetData->exposed)
        {
            effectiveness = 0;
            gDungeon->unk134.pokemonExposed = TRUE;
        }
        else
        {
            effectiveness = gTypeEffectivenessChart[moveType][*targetType];
            // Used to swap variable initialization order at the loop start.
            effectiveness = *(s16*)(((s8*) gTypeEffectivenessChart) + moveTypeOffset + *targetType * 2);
        }
        if (weight == 0)
        {
            goto breakLoop;
        }
        weight *= typeEffectivenessMultipliers[effectiveness];
        weight /= 2;
        if (weight == 0)
        {
            // BUG: If the Pokémon's first type resists the move, the second type is ignored.
            // This calculates type effectiveness incorrectly if the first type resists the move and the second type is weak to the move.
            // For example, a Fire-type move is considered not very effective against a Rock/Bug-type like Anorith.
            return 2;
        }
    } while ((s32)(++targetType) <= (s32)(targetTypes + 1));
    breakLoop:
    if ((moveType == TYPE_FIRE || moveType == TYPE_ICE) && AbilityIsActive(target, ABILITY_THICK_FAT))
    {
        return 2;
    }
    if (moveType == TYPE_WATER && AbilityIsActive(user, ABILITY_TORRENT))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_GRASS && AbilityIsActive(user, ABILITY_OVERGROW))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_BUG && AbilityIsActive(user, ABILITY_SWARM))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (moveType == TYPE_FIRE && AbilityIsActive(user, ABILITY_BLAZE))
    {
        s32 maxHPStat = userData->maxHPStat;
        if (maxHPStat < 0)
        {
            maxHPStat += 3;
        }
        if (maxHPStat >> 2 >= userData->HP)
        {
            weight *= 2;
        }
    }
    if (weight == 0)
    {
        return 2;
    }
    if (MonsterIsType(user, moveType))
    {
        weight *= 2;
    }
    targetTypes = targetData->types;
    if (GetApparentWeather(user) == WEATHER_SUNNY)
    {
        if (moveType == TYPE_FIRE)
        {
            weight *= 2;
        }
        else if (moveType == TYPE_WATER)
        {
            return 2;
        }
    }
    if (gDungeon->weather.mudSportTurns != 0 && moveType == TYPE_ELECTRIC)
    {
        return 2;
    }
    if (gDungeon->weather.waterSportTurns != 0 && moveType == TYPE_FIRE)
    {
        return 2;
    }
    if (moveType == TYPE_ELECTRIC && userData->bideClassStatus.status == STATUS_CHARGING)
    {
        weight *= 2;
    }
    if (weight > 2)
    {
        weight = 3;
    }
    return weight + 2;
}
