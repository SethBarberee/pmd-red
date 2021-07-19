#include "global.h"
#include "pokemon.h"
#include "constants/colors.h"

extern struct gPokemon *gMonsterParameters;
extern const char gUnknown_8107600[];
extern const char gUnknown_8107608[];
extern const char gUnownLetters[];
extern const char gUnknown_8107630[];
extern const char gUnknown_8107638[];
extern const char gUnknown_810763C[];

extern void ExpandPlaceholdersBuffer(u8 *buffer, const char *r2, ...);
extern s16 sub_808E770(s32);
extern void sub_80922B4(u8 *, u8 *, s32);

extern void ExpandPlaceholdersBuffer(u8 *buffer, const char *r2, ...);

void CopySpeciesNametoBuffer(u8 * buffer, s16 index)
{
    strncpy(buffer, gMonsterParameters[index].species, 0x14);
}

void CopyYellowSpeciesNametoBuffer(u8 *buffer, s16 index)
{
    s32 new_index = index;
    ExpandPlaceholdersBuffer(buffer, gUnknown_8107600, gMonsterParameters[new_index].species); // #c6%s#r
}

void CopyCyanSpeciesNametoBuffer(u8 *buffer, s16 index)
{
    s32 new_index = index;
    ExpandPlaceholdersBuffer(buffer, gUnknown_8107608, gMonsterParameters[new_index].species); // #c5%s#r
}

void sub_808D930(u8 *buffer, s16 index)
{
  char *unownString;
  s32 unownIndex;
  const char *preload;
  
  if (sub_808E770(index) == SPECIES_UNOWN) {
    preload = gUnknown_8107630; // %s%c
    unownString = GetMonSpecies(SPECIES_UNOWN);
    unownIndex = GetUnownIndex(index);
    ExpandPlaceholdersBuffer(buffer,preload,unownString,gUnownLetters[unownIndex]); // ABCDEFGHIJKLMNOPQRSTUVWXYZ!? 
  }
  else {
    ExpandPlaceholdersBuffer(buffer,gUnknown_8107638, gMonsterParameters[index].species); // %s
  }
}

char * GetMonSpecies(s16 index)
{
    return gMonsterParameters[index].species;
}

void sub_808D9AC(u8 *buffer, struct PokemonStruct *pokemon, s32 colorNum)
{
  u8 nameBuffer [20];

  sub_80922B4(nameBuffer, pokemon->name, POKEMON_NAME_LENGTH);
  if (colorNum == 0) {
    colorNum = COLOR_CYAN;
  }
  ExpandPlaceholdersBuffer(buffer,gUnknown_810763C,colorNum,nameBuffer); // #c%c%s#r
}

void sub_808D9DC(u8 *buffer, u8 *param_2, s32 colorNum)
{
  u8 nameBuffer [20];

  sub_80922B4(nameBuffer, param_2 + 0x58, POKEMON_NAME_LENGTH);
  if (colorNum == 0) {
    colorNum = COLOR_YELLOW;
  }
  ExpandPlaceholdersBuffer(buffer,gUnknown_810763C,colorNum,nameBuffer); // #c%c%s#r
}

void sub_808DA0C(u8 *buffer, u8 *param_2)
{
  u8 nameBuffer [20];

  sub_80922B4(nameBuffer, param_2 + 0x58, POKEMON_NAME_LENGTH);
  ExpandPlaceholdersBuffer(buffer,gUnknown_8107638,nameBuffer); // %s
}

void sub_808DA34(u8 *buffer, struct PokemonStruct *pokemon)
{
  sub_80922B4(buffer, pokemon->name, POKEMON_NAME_LENGTH);
}
