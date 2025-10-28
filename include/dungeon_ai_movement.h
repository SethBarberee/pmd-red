#ifndef GUARD_DUNGEON_AI_MOVEMENT_H
#define GUARD_DUNGEON_AI_MOVEMENT_H

#include "structs/dungeon_entity.h"

void AIMovement(Entity *pokemon, bool8 showRunAwayEffect);
bool8 CanTakeItem(Entity *pokemon);
bool8 ChooseTargetPosition(Entity *pokemon);
void DecideMovement(Entity *pokemon, bool8 showRunAwayEffect);
bool8 AvoidEnemies(Entity *pokemon);
bool8 Wander(Entity *pokemon);
void sub_807BB78(Entity *pokemon);

#endif
