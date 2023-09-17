#include "global.h"
#include "code_80521D0.h"
#include "dungeon_global_data.h"

extern Entity * gUnknown_202F1E8[2];
extern u8 gUnknown_203B434;

extern void sub_80526D0(u8);
extern u8 sub_8045888(Entity *entity);
extern u8 sub_8052DC0(Entity *);
extern u8 sub_803F428(u32);
extern u8 * xxx_format_string(const u8 *param_1,u8 *param_2,u8 *param_3,u16 param_4);
extern void sub_805E804(void);
extern void sub_803E46C(u32);
extern void sub_8053210(u8 *, u8, u32);

void sub_805229C(void)
{
    sub_80526D0(0x50);
}

void SendMessage(Entity *pokemon, const u8 * message)
{
    if (sub_8045888(pokemon) != 0){
        sub_80523A8(pokemon, message, TRUE);
    }
}

UNUSED void sub_80522C8(Entity *entity, u8 * message)
{
    if (sub_8045888(entity) != 0){
        sub_80523A8(entity, message, FALSE);
    }
}

void sub_80522E8(Entity *entity, u8 * message)
{
    sub_80523A8(entity, message, FALSE);
}

void sub_80522F4(Entity *entity, Entity *r1, u8 * message)
{
    u8 temp;
    u32 temp_reg;
    u32 temp2;
    temp = sub_8045888(entity);
    temp_reg = (-temp | temp);
    temp2 = temp_reg >> 31;
    if(sub_8052DC0(r1) != 0)
    {
        temp2 = 1;
    }
    if(temp2 != 0)
    {
        sub_80523A8(entity, message, TRUE);
    }
}

void sub_805232C(Entity *entity, Entity *r1, u8 * message)
{
    u8 temp;
    u32 temp_reg;
    u32 temp2;
    temp = sub_8045888(entity);
    temp_reg = (-temp | temp);
    temp2 = temp_reg >> 31;
    if(sub_8052DC0(r1) != 0)
    {
        temp2 = 1;
    }
    if(temp2 != 0)
    {
        sub_80523A8(entity, message, FALSE);
    }
}

void sub_8052364(Entity *entity, u32 r1, u8 * message)
{
    u8 temp;
    u32 temp_reg;
    u32 temp2;
    temp = sub_8045888(entity);
    temp_reg = (-temp | temp);
    temp2 = temp_reg >> 31;
    if(sub_803F428(r1) != 0)
    {
        temp2 = 1;
    }
    if(temp2 != 0)
    {
        sub_80523A8(entity, message, TRUE);
    }
}

void sub_805239C(Entity *entity, u8 * message)
{
    sub_80523A8(entity, message, TRUE);
}

void sub_80523A8(Entity *pokemon, const u8 *message, bool8 param_3)
{
    s32 iVar3;
    u8 uVar5;
    u32 uVar6;
    u8 buffer1 [0x3E];
    bool8 flag;

    if (gUnknown_202F1E8[0] != pokemon) {
        uVar5 = 1;
    }
    else
{
        uVar5 = gUnknown_203B434;
    }
    uVar6 = 1;
    gUnknown_202F1E8[0] = pokemon;
    gUnknown_203B434 = 0;
    flag = FALSE;

    while( TRUE ) {
        while( TRUE ) {
            iVar3 = gDungeon->unk1C060;
            iVar3++;
            if (iVar3 == 0xA) {
                iVar3 = 0;
            }
            if (iVar3 != gDungeon->unk1C062) break;
            sub_803E46C(0);
        }
        if (*message == '\0') break;
        gDungeon->unk1C054[gDungeon->unk1C060] = uVar5;
        message = xxx_format_string(message,buffer1,buffer1 + 0x3E,0x80);
        if (*message == '\r') {
            message++;
        }
        if (*message == '\n') {
            message++;
        }
        sub_8053210(buffer1,uVar5,uVar6);
        uVar5 = 0;
        uVar6 = 0;
        if (param_3) {
            flag = TRUE;
            // NOTE: stolen from Ghidra
            strncpy((gDungeon->fill18218 + gDungeon->unk1C060 * 0x40 + 0x3bbc),buffer1,0x40);
            // TODO not sure why this doesn't work
            // https://decomp.me/scratch/QLEgc 
            // strncpy((gDungeon->unk1BDD4[gDungeon->unk1C060],buffer1,0x40);

            gDungeon->unk1C060++;

            if (gDungeon->unk1C060 == 10) {
                gDungeon->unk1C060 = 0;
            }
        }
    }
    if (flag) {
        gDungeon->unk1C064 = 0xf0;
        if (gDungeon->unk1C06C == 0) {
            gDungeon->unk1C06C = 1;
        }
        sub_805E804();
    }
}
