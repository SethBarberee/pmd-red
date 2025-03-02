#include "global.h"
#include "structs/str_dungeon.h"
#include "dungeon_leader.h"
#include "dungeon_util.h"

EWRAM_INIT Entity *gLeaderPointer = NULL;

Entity* GetLeader(void)
{
    Entity *leader = gLeaderPointer;
    if (leader == NULL)
    {
        s32 i;
        for (i = 0; i < MAX_TEAM_MEMBERS; i++)
        {
            Entity *currentPokemon = gDungeon->teamPokemon[i];
            if (EntityIsValid(currentPokemon) && GetEntInfo(currentPokemon)->isTeamLeader)
            {
                gLeaderPointer = currentPokemon;
                return currentPokemon;
            }
        }
        return NULL;
    }
    return leader;
}

EntityInfo* GetLeaderInfo(void)
{
    return GetEntInfo(GetLeader());
}
