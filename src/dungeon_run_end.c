#include "global.h"
#include "globaldata.h"
#include "dungeon_run_end.h"
#include "structs/str_dungeon.h"
#include "data_serializer.h"
#include "dungeon_info.h"
#include "items.h"
#include "moves.h"
#include "string_format.h"
#include "text_1.h"
#include "text_3.h"
#include "text_util.h"
#include "strings.h"

#define TEXT_BUFFER_LEN 200

static void WriteDeathText(s16 moveID, u8 *buffer)
{
    u16 moveID_u16;
    s32 moveID_s32 = moveID;
    Move move;

    if (moveID_s32 < 0x1F4) {
        // Needed this cast/variable to match
        moveID_u16 = moveID_s32;
        InitPokemonMoveOrNullObject(&move, moveID_u16);
        BufferMoveName(gFormatBuffer_Items[0], &move, NULL);
        FormatString(gText_DeathToMove, buffer, buffer + TEXT_BUFFER_LEN, 0); // $m0's $i0
    } else {
        strncpy(buffer, gSpecialDeathTexts[moveID - 0x1F4].text, TEXT_BUFFER_LEN);
    }
}

static bool8 WasDefeatedByMove(s16 moveID)
{
    if(moveID < 0x1F4)
    {
        return TRUE;
    }
    else
    {
        return gSpecialDeathTexts[moveID  - 0x1F4].unk0;
    }
}

void PrintOnDungeonFinishedWindow(u32 windowId, const u8 *headerText, UnkDungeonGlobal_unk1CE98_sub *param_3)
{
    u8 buffer[TEXT_BUFFER_LEN];
    s32 x, y;
    Item *item;

    sub_80073B8(windowId);
    PrintFormattedStringOnWindow(16,0,headerText,windowId,0);
    PrintYellowDungeonNametoBuffer(gFormatBuffer_Monsters[0], &param_3->dungeonLocation);
    PrintFormattedStringOnWindow(4,16,gText_AlignPlaceX,windowId,0); // #+Place: $m0
    y = 26;
    StrncpyCustom(gFormatBuffer_Monsters[0], param_3->buffer1, POKEMON_NAME_LENGTH);
    StrncpyCustom(gFormatBuffer_Monsters[1], param_3->buffer2, POKEMON_NAME_LENGTH);
    if (WasDefeatedByMove(param_3->moveID) != 0) {
        // $m1 was defeated by
        FormatString(gText_Pokemon1WasDefeatedBy,buffer, buffer + sizeof(buffer),0);
    }
    else {
        // $m1
        FormatString(gText_Pokemon1,buffer, buffer + sizeof(buffer),0);
    }

    x = (176 - GetStringLineWidth(buffer)) / 2;
    PrintFormattedStringOnWindow(x,y,buffer,windowId,0);

    y += 10;
    WriteDeathText(param_3->moveID, buffer);

    x = (176 - GetStringLineWidth(buffer)) / 2;
    PrintFormattedStringOnWindow(x,y,buffer,windowId,0);

    y += 16;
    gFormatArgs[0] = param_3->exp;
    gFormatArgs[1] = param_3->level;
    if (gFormatArgs[1] >= 100) {
        PrintFormattedStringOnWindow(4,y,gUnknown_81138C0,windowId,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,gUnknown_8113898,windowId,0);
    }
    y += 10;
    gFormatArgs[0] = param_3->maxHPStat;
    PrintFormattedStringOnWindow(4,y,gUnknown_81138D0,windowId,0);
    y += 10;
    gFormatArgs[0] = param_3->atk;
    gFormatArgs[1] = param_3->def;
    if (param_3->attBoost) {
        gFormatArgs[0] = gFormatArgs[0] + param_3->attBoost;
        PrintFormattedStringOnWindow(4,y,gUnknown_8113950,windowId,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,gUnknown_81138E4,windowId,0);
    }
    if (param_3->defBoost) {
        gFormatArgs[1] = gFormatArgs[1] + param_3->defBoost;
        PrintFormattedStringOnWindow(4,y,gUnknown_8113974,windowId,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,gUnknown_8113900,windowId,0);
    }
    y += 10;
    gFormatArgs[0] = param_3->spAtk;
    gFormatArgs[1] = param_3->spDef;
    if (param_3->spAttBoost) {
        gFormatArgs[0] = gFormatArgs[0] + param_3->spAttBoost;
        PrintFormattedStringOnWindow(4,y,gUnknown_8113990,windowId,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,gUnknown_8113918,windowId,0);
    }
    if (param_3->spDefBoost) {
        gFormatArgs[1] = gFormatArgs[1] + param_3->spDefBoost;
        PrintFormattedStringOnWindow(4,y,gUnknown_81139B4,windowId,0);
    }
    else {
        PrintFormattedStringOnWindow(4,y,gUnknown_8113934,windowId,0);
    }
    y += 16;
    item = &(param_3->heldItem);
    if ((param_3->heldItem.flags & ITEM_FLAG_EXISTS)) {
        sub_8090E14(gFormatBuffer_Items[0],item,0);
    }
    else {
        strcpy(gFormatBuffer_Items[0],gUnknown_81139B8);
    }
    PrintFormattedStringOnWindow(4,y,gText_ItemAlignedX,windowId,0);
    sub_80073E0(windowId);
}

s16 sub_8094828(u16 moveID, u8 id)
{
    if(id != 0)
    {
        if(GetItemCategory(id) == CATEGORY_ORBS)
            return 0x223;
        else
            return 0x224;
    }
    else
    {
        return moveID;
    }
}
