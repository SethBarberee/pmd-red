#ifndef GUARD_CODE_8024458_H
#define GUARD_CODE_8024458_H

#include "structs/menu.h"
#include "structs/str_text.h"
#include "pokemon_summary_window.h"

struct unkStruct_203B2AC
{
    MenuInputStruct input;
    u32 unk34[3];
    u8 unk40[0x48 - 0x40];
    s16 speciesNum;
    struct MonSummaryInfo unk4C;
    struct UnkInfoTabStruct unkB0;
    u32 unkE0;
    WindowTemplate *unkE4;
    WindowTemplates unkE8;
    WindowHeader unk148;
};

bool8 sub_8024458(s16 speciesNum, s32);
u32 sub_80244E4(void);
void sub_802452C(void);
void sub_802453C(void);

#endif // GUARD_CODE_8024458_H
