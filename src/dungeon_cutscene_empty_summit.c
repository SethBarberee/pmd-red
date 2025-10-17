#include "global.h"
#include "globaldata.h"
#include "dungeon_cutscene.h"
#include "effect_main.h"
#include "dungeon_vram.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "dungeon_mon_sprite_render.h"
#include "constants/bg_music.h"
#include "constants/direction.h"
#include "constants/friend_area.h"
#include "constants/weather.h"
#include "dungeon_items.h"
#include "dungeon_range.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_misc.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "items.h"
#include "pokemon_3.h"
#include "pokemon.h"
#include "position_util.h"
#include "trap.h"
#include "math.h"
#include "dungeon_config.h"
#include "dungeon_boss_dialogue.h"


void sub_80885A0(void)
{
  DungeonFadeOutBGM(0x3c);
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  gDungeon->unk7 = 1;
}

void sub_80885C4(void)
{
  Entity * leaderEntity;

  leaderEntity = CutsceneGetLeader();
  DungeonFadeOutBGM(0x3c);
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
}

void sub_8088608(void)
{
    gDungeon->unk2 = 1;
}

void sub_8088618(void)
{
    sub_8086448();
    // The mountain's summit...
    // But there is no one here
    // It's time to go back
    sub_80866C4(&gUnknown_8102B10);
}
