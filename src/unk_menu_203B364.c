#include "global.h"
#include "input.h"
#include "menu.h"
#include "main_menu.h"
#include "memory.h"
#include "text.h"

struct unkStruct_203B360
{
    // size: 0x1b4
    u32 currMenu;
    u32 unk4;
    u32 unk8;
    u8 fill8[0x148 - 0xC];
    struct UnkTextStruct2 unk148[4];
    u16 unk1A8;
    u16 unk1AA;
    u16 unk1AC;
    u16 unk1AE;
    u32 unk1B0; // Sprite count?
};

extern struct unkStruct_203B360 *gUnknown_203B364;
extern struct UnkTextStruct2 gUnknown_80E6F20;
extern struct UnkTextStruct2 gUnknown_80E6F38;
extern struct MenuItem gUnknown_80E7090[];
extern struct MenuItem gUnknown_80E6F50[];

extern void sub_8038440();
extern void sub_8035CF4(u32 *, u32, u32);
extern void SetMenuItems(void *, struct UnkTextStruct2 *, u32, struct UnkTextStruct2 *, struct MenuItem *, u32, u32, u32);
extern u8 sub_80130A8(u32 *);
extern void sub_8013114(u32 *, u32 *);
extern void sub_80384D0();
extern void sub_8038830();

void CreateSaveMenu(s32 currMenu)
{
  s32 iVar4;
  
  if (gUnknown_203B364 == NULL) {
    gUnknown_203B364 = MemoryAlloc(sizeof(struct unkStruct_203B360),8);
    MemoryFill8((u8 *)gUnknown_203B364,0,sizeof(struct unkStruct_203B360));
  }
  for(iVar4 = 0; iVar4 < 4; iVar4++){
    gUnknown_203B364->unk148[iVar4] = gUnknown_80E6F20;
  } 
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B364->unk148,1,1);

  if (currMenu == MENU_DELETE_SAVE) {
      // Beware, Deleting your Adventure
    SetMenuItems(&gUnknown_203B364->unk8,gUnknown_203B364->unk148,0,&gUnknown_80E6F38,gUnknown_80E7090,
                 0,6,0);
  }
  else {
      // Saving your Adventure
    SetMenuItems(&gUnknown_203B364->unk8,gUnknown_203B364->unk148,0,&gUnknown_80E6F38,gUnknown_80E6F50,
                 0,6,0);
  }
  sub_8035CF4(&gUnknown_203B364->unk8,0,1);
  gUnknown_203B364->unk4 = 0;
  gUnknown_203B364->currMenu = currMenu;
  sub_8038830();
}

void CleanSaveMenu(void)
{
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  if (gUnknown_203B364 != NULL) {
    MemoryFree(gUnknown_203B364);
    gUnknown_203B364 = NULL;
  }
}

