#include "global.h"
#include "globaldata.h"
#include "pokemon_evolution.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text_util.h"
#include "friend_area.h"
#include "adventure_info.h"
#include "constants/evolve_type.h"
#include "constants/evolution_status.h"

void SetMonEvolveStatus(Pokemon *pokemon, EvolveStatus *evolveStatus, bool8 param_3)
{
    struct FriendAreaCapacity friendAreaCapacity;
    struct unkEvolve evolveConditions;
    s32 index;

    evolveStatus->evolutionConditionStatus = 0;
    for (index = MONSTER_BULBASAUR; index < MONSTER_MAX; index++) {
        s32 speciesId = (s16) index;
        if (speciesId == MONSTER_ALAKAZAM) {
            GetPokemonEvolveConditions(MONSTER_ALAKAZAM,&evolveConditions);
        }
        else {
            GetPokemonEvolveConditions(speciesId,&evolveConditions);
        }
        if (evolveConditions.preEvolution.evolveType != 0 && pokemon->speciesNum == evolveConditions.preEvolution.evolveFrom)
            break;
    };

    if (index == MONSTER_MAX) {
        evolveStatus->evolutionConditionStatus = EVOLUTION_NO_MORE;
        return;
    }

    for (index = MONSTER_BULBASAUR; index < MONSTER_MAX; index++) {
        u8 evolvedMonFriendArea, monFriendArea;
        bool8 cannotEvolve = FALSE;
        s32 speciesId = (s16) (index);

        GetPokemonEvolveConditions(speciesId, &evolveConditions);
        if (evolveConditions.preEvolution.evolveType == 0 || pokemon->speciesNum != evolveConditions.preEvolution.evolveFrom)
            continue;

        evolvedMonFriendArea = GetFriendArea(speciesId);
        monFriendArea = GetFriendArea(pokemon->speciesNum);
        GetFriendAreaCapacity2(evolvedMonFriendArea,&friendAreaCapacity,0,0);
        if (!friendAreaCapacity.hasFriendArea) {
            evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_FRIEND_AREA;
            cannotEvolve = TRUE;
        }
        else {
            s32 currMonsNo = friendAreaCapacity.currNoPokemon;
            if (evolvedMonFriendArea == monFriendArea) {
                currMonsNo--;
            }
            if (friendAreaCapacity.maxPokemon <= currMonsNo) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ROOM;
                cannotEvolve = TRUE;
            }
         }

        if (evolveConditions.preEvolution.evolveType == EVOLVE_TYPE_LEVEL) {
            if (evolveStatus->evolutionConditionStatus & 1)
                continue;
            if (pokemon->level < evolveConditions.evolutionRequirements.mainRequirement) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_LEVEL;
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.preEvolution.evolveType == EVOLVE_TYPE_IQ) {
            if (pokemon->IQ < evolveConditions.evolutionRequirements.mainRequirement) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_IQ;
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.preEvolution.evolveType == EVOLVE_TYPE_ITEM) {
            if (param_3) {
                if ((evolveStatus->evoItem1 != evolveConditions.evolutionRequirements.mainRequirement) &&
                        (evolveStatus->evoItem2 != evolveConditions.evolutionRequirements.mainRequirement))
                {
                    evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                    cannotEvolve = TRUE;
                }
            }
            else if (FindItemInInventory(evolveConditions.evolutionRequirements.mainRequirement) < 0) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                cannotEvolve = TRUE;
            }
        }

        if (evolveConditions.evolutionRequirements.additionalRequirement == 4) {
            if (param_3) {
                if ((evolveStatus->evoItem1 != ITEM_LINK_CABLE) && (evolveStatus->evoItem2 != ITEM_LINK_CABLE)) {
                    evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                    cannotEvolve = TRUE;
                }
            }
            else if (FindItemInInventory(ITEM_LINK_CABLE) < 0) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 5) {
            if (pokemon->offense.att[0] <= pokemon->offense.def[0]) {
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 6) {
            if (pokemon->offense.att[0] >= pokemon->offense.def[0]) {
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 7) {
            if (pokemon->offense.att[0] != pokemon->offense.def[0]) {
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 8) {
            if (param_3) {
                if ((evolveStatus->evoItem1 != ITEM_SUN_RIBBON) && (evolveStatus->evoItem2 != ITEM_SUN_RIBBON)) {
                    evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                    cannotEvolve = TRUE;
                }
            }
            else if (FindItemInInventory(ITEM_SUN_RIBBON) < 0) {
                evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 9) {
                if (param_3) {
                    if ((evolveStatus->evoItem1 != ITEM_LUNAR_RIBBON) && (evolveStatus->evoItem2 != ITEM_LUNAR_RIBBON)) {
                        evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                        cannotEvolve = TRUE;
                    }
                }
                else if (FindItemInInventory(ITEM_LUNAR_RIBBON) < 0) {
                    evolveStatus->evolutionConditionStatus |= EVOLUTION_LACK_ITEM;
                    cannotEvolve = TRUE;
                }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 0xb) {
            if ((evolveStatus->wurmpleVal & 1)) {
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 0xc) {
            if (!(evolveStatus->wurmpleVal & 1)) {
                cannotEvolve = TRUE;
            }
        }
        else if (evolveConditions.evolutionRequirements.additionalRequirement == 10) {
            if (param_3 != 0) {
                if ((evolveStatus->evoItem1 != ITEM_BEAUTY_SCARF) && (evolveStatus->evoItem2 != ITEM_BEAUTY_SCARF)) {
                    cannotEvolve = TRUE;
                }
            }
            else {
                if (FindItemInInventory(ITEM_BEAUTY_SCARF) < 0) {
                    cannotEvolve = TRUE;
                }
            }
        }

        if (!cannotEvolve) {
            evolveStatus->evolutionConditionStatus |= EVOLUTION_GOOD;
            evolveStatus->targetEvolveSpecies = speciesId;
        }
    }
}

s32 GetMonSummaryScreenEvoStringId(Pokemon *pokemon)
{
    EvolveStatus evolveStatus;

    SetMonEvolveStatus(pokemon, &evolveStatus, 0);
    if (evolveStatus.evolutionConditionStatus & EVOLUTION_GOOD) {
        return EVO_STRING_POSSIBLE;
    }
    else if (evolveStatus.evolutionConditionStatus & EVOLUTION_NO_MORE) {
        return EVO_STRING_NO_MORE;
    }
    else {
        return EVO_STRING_NOT_NOW;
    }
}

Pokemon *sub_808F734(Pokemon *pokemon, s16 _species)
{
    Pokemon *uVar1;
    Pokemon *iVar3;
    Pokemon pokeStruct;
    s32 species = _species;

    iVar3 = NULL;
    pokeStruct = *pokemon;
    uVar1 = sub_808F798(pokemon, species);
    if (species == MONSTER_NINJASK) {
        pokeStruct.isTeamLeader = FALSE;
        pokeStruct.heldItem.id = ITEM_NOTHING;
        BoundedCopyStringtoBuffer(pokeStruct.name, GetMonSpecies(MONSTER_SHEDINJA),POKEMON_NAME_LENGTH);
        iVar3 = sub_808F798(&pokeStruct,MONSTER_SHEDINJA);
    }
    if (iVar3 != NULL) {
        IncrementAdventureNumJoined();
    }
    return uVar1;
}

Pokemon *sub_808F798(Pokemon *pokemon, s16 _species)
{
    s32 r6;
    s32 i;
    Pokemon pokeStruct;
    LevelData levelData;
    u8 buffer [64];
    s32 species = _species;
    bool8 copy;

    pokeStruct = *pokemon;
    r6 = pokeStruct.speciesNum;
    GetLvlUpEntry(&levelData,species,pokeStruct.level);
    pokeStruct.currExp = levelData.expRequired;
    pokemon->flags = 0;
    pokeStruct.speciesNum = species;
    if (pokeStruct.unkC[0].level == 0) {
        pokeStruct.unkC[0].level = pokeStruct.level;
    }
    else if (pokeStruct.unkC[1].level == 0) {
        pokeStruct.unkC[1].level = pokeStruct.level;
    }

    CopyStringtoBuffer(buffer, GetMonSpecies(r6));
    copy = TRUE;
    for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
        if (buffer[i] != pokeStruct.name[i]) {
            copy = FALSE;
            break;
        }
        if (buffer[i] == '\0')
            break;
    }

    if (copy)
        BoundedCopyStringtoBuffer(pokeStruct.name, GetMonSpecies(species), POKEMON_NAME_LENGTH);

    return TryAddPokemonToRecruited(&pokeStruct);
}

UNUSED static void sub_808F83C(Pokemon *pokemon, s16 species, u8 *r2)
{
    *r2 = 0;
}
