#ifndef GUARD_ADVENTURE_INFO_H
#define GUARD_ADVENTURE_INFO_H

#include "structs/str_dungeon_location.h"
#include "data_serializer.h"

// See gAdventureLogText
enum AdventureAchievement
{
    AA_HILL_OF_ANCIENTS,
    AA_FUGITIVE,
    AA_PREVENT_METEOR,
    AA_BROKE_CURSE,
    AA_TEAM_BASE_DONE,
    AA_SMEARGLE,
    AA_SPOTTED_MUNCHLAX,
    AA_NUM_MOVES_LEARNED,
    AA_NUM_FRIEND_RESCUE_SUCCESSES,
    AA_NUM_POKEMON_EVOLVED,
    AA_NUM_POKEMON_JOINED,
    AA_NUM_THIEVING_SUCCESSES,
    AA_NUM_FLOORS_EXPLORED,
    AA_ALL_FRIEND_AREAS,
    AA_ALL_POKEMON_LEADERS,
    AA_ALL_POKEMON_JOINED,
    AA_RECRUIT_MOLTRES,
    AA_RECRUIT_ZAPDOS,
    AA_RECRUIT_ARTICUNO,
    AA_RECRUIT_DEOXYS,
    AA_RECRUIT_ENTEI,
    AA_RECRUIT_RAIKOU,
    AA_RECRUIT_SUICUNE,
    AA_RECRUIT_HO_OH,
    AA_RECRUIT_KYOGRE,
    AA_RECRUIT_GROUDON,
    AA_RECRUIT_RAYQUAZA,
    AA_RECRUIT_LUGIA,
    AA_RECRUIT_CELEBI,
    AA_RECRUIT_MEW,
    AA_RECRUIT_MEWTWO,
    AA_RECRUIT_JIRACHI,
    AA_MAX
};

// size: 0xC4
struct unkStruct_203B494
{
    /* 0x0 */ u32 achievements; // Adventure achievement flags
    /* 0x4 */ s32 numAdventures;
    /* 0x8 */ s32 friendRescueSuccesses;
    /* 0xC */ s32 numEvolved;
    /* 0x10 */ DungeonLocation dungeonLocation;
    /* 0x14 */ s16 thievingSuccesses;
    /* 0x16 */ s16 numJoined;
    /* 0x18 */ s16 adventureMovesLearned;
    u32 unk1C[14];
    u32 unk54[14];
    /* 0x8C */ u32 learnedMoves[13]; // Get with `learnedMoves[move / 32] & 1 << move % 32` ... Set with `learnedMoves[move / 32] |= 1 << move % 32`
    /* 0xC0 */ s32 numFloorsExplored;
};

extern struct unkStruct_203B494 *gUnknown_203B494;

void sub_8097670(void);
struct unkStruct_203B494 *sub_8097680(void);
void SetDungeonLocationInfo(DungeonLocation *dl);
DungeonLocation *GetDungeonLocationInfo(void);
void ResetAdventureInfo(void);
void SetAdventureAchievement(u8);
bool8 GetAdventureAchievement(u8);
const u8 *GetAdventureLogLine(u8 index);
void ResetNumAdventures(void);
void IncrementNumAdventures(void);
s32 GetNumAdventures(void);
void IncrementFriendRescueSuccesses(void);
s32 GetFriendRescueSuccesses(void);
void IncrementNumEvolved(void);
s32 GetAdventureNumEvolved(void);
void IncrementThievingSuccesses(void);
s16 GetThievingSuccesses(void);
void IncrementAdventureNumJoined(void);
s16 GetAdventureNumJoined(void);
s16 GetAdventureMovesLearned(void);
void IncrementAdventureFloorsExplored(void);
s16 GetAdventureFloorsExplored(void);
void sub_80978C8(s16 pokeIndex);
bool8 sub_8097900(s16 pokeIndex);
void UpdateAdventureAchievements(void);
void WriteAdventureBits(DataSerializer *r0);
void ReadAdventureBits(DataSerializer *r0);

#endif // GUARD_ADVENTURE_INFO_H
