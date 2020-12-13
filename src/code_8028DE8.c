#include "global.h"

// Wonder Mail Related
struct unkStruct_203B2C0
{
    u32 padding;
    u32 unk4;
    u8 padding2[0x38];
    u32 unk40;
    u16 unk44[494]; // TODO figure out correct size
    u32 unk420;
    u8 padding3[0x114];
    u32 unk538; // A7 << 3
    u32 unk53C;
    u32 unk540; // A8 << 4
};

extern struct unkStruct_203B2C0 *gUnknown_203B2C0;

extern u32 sub_80144A4(s32 *r0);
extern void sub_8011C28(u32);
extern void sub_8012574(u32);
extern u8 sub_8012600();
extern void sub_8012750();
extern void sub_8095240(u8);

extern void sub_809927C(u8);
extern u8 sub_8030C20(u32);
extern u32 sub_8031050();
extern void sub_80310B4();
extern u32 sub_8095350();

extern u32 gWonderMailErrorText;
extern u32 gWonderMailNumGBAsText;
extern u32 gWonderMailWrongModeText;
extern u32 gWonderMailStorageFullText;
extern u32 gWonderMailDuplicateText;
extern u32 gWonderMailNotEligibleReceiveText;
extern u32 gWonderMailNoRoomText;
extern u32 gWonderMailFriendErrorText;

extern s32 sub_8095190(void);
extern u32 sub_8095324(u32);
extern void sub_80141B4(u32 *r0, u32, u32 *r1, u32);
extern void nullsub_130(void);
extern void sub_8028348(void);


void sub_8028B04(u32 r0)
{
    gUnknown_203B2C0->unk4 = r0;
    nullsub_130();
    sub_8028348();
}

// Wonder Mail Linking...
void sub_8028B1C(u32 r0)
{
    switch(r0)
    {
        case 0:
            break;
        case 1:
        case 2:
            sub_80141B4(&gWonderMailErrorText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 3:
            sub_80141B4(&gWonderMailNumGBAsText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 4:
            sub_80141B4(&gWonderMailWrongModeText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 5:
            sub_80141B4(&gWonderMailErrorText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 6:
            sub_80141B4(&gWonderMailStorageFullText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 7:
            sub_80141B4(&gWonderMailDuplicateText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 8:
            break;
        case 9:
            sub_80141B4(&gWonderMailNotEligibleReceiveText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 10:
            break;
        case 11:
            sub_80141B4(&gWonderMailNotEligibleReceiveText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 12:
            break;
        case 13:
            sub_80141B4(&gWonderMailNoRoomText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 14:
            sub_80141B4(&gWonderMailErrorText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 15:
            sub_80141B4(&gWonderMailFriendErrorText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        default:
            break;
    }
}

void sub_8028BF0(void)
{  
    u32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    gUnknown_203B2C0->unk40 = 8;
    gUnknown_203B2C0->unk44[640] = 0xffff;
    switch(temp)
    {
        case 0:
            gUnknown_203B2C0->unk40 = 3;
            gUnknown_203B2C0->unk538 = 0;
            if(sub_8095190() != -1)
            {
                sub_8028B04(8);
            }
            else
            {
                sub_8028B04(9);
            }
            break;
        case 1:
            if(sub_8095324(2) != 0)
            {
                sub_8028B04(30);
            }
            else
            {
                sub_8028B04(26);
            }
            break;
        case 2:
            gUnknown_203B2C0->unk40 = 4;
            gUnknown_203B2C0->unk538 = 2;
            if(sub_8095324(4) != 0)
            {
                sub_8028B04(41);
            }
            else
            {
                sub_8028B04(47);
            }
            break;
        case 3:
            sub_8028B04(11);
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        case 10:
            sub_8028B04(2);
            break;
        default:
            break;
    }
}


void sub_8028CE0()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(3);
}

void sub_8028CFC()
{
    s32 temp;
    u32 temp2;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(sub_8031050())
    {
        case 2:
        case 3:
            temp2 = sub_8095350();
            sub_80310B4();
            if(temp2 != gUnknown_203B2C0->unk540)
            {
                sub_8028B04(23);
            }
            else
            {
                sub_8028B04(25);
            }
            break;
        default:
            break;
    }
}

void sub_8028D4C()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    gUnknown_203B2C0->unk538 = temp;
    switch((s32)gUnknown_203B2C0->unk538)
    {
        case 5:
            if(sub_8030C20(2) != 0)
            {
                sub_8028B04(12);
            }
            else
            {
                sub_8028B04(13);
            }
            break;
        case 6:
            if(sub_8030C20(4) != 0)
            {
                sub_8028B04(14);
            }
            else
            {
                sub_8028B04(15);
            }
            break;
        case 7:
            if(sub_8030C20(0) != 0)
            {
                sub_8028B04(16);
            }
            else
            {
                sub_8028B04(17);
            }
            break;
        case 10:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8028DE8(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(r0);
}

void sub_8028E08()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(18);
}

void sub_8028E24()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            sub_8028B04(19);
            break;
        case 10:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8028E54()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 0x8:
            sub_8028B04(20);
            break;
        case 0xA:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8028E84()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x18);
    sub_8011C28(1);
    sub_8012574(0);
}

void sub_8028EAC()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(sub_8012600() == 0)
    {
        sub_8012750();
        sub_8028B04(25);
    }
}

void sub_8028ED4()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(temp == 8)
    {
        sub_8028B04(11);
    }
    else
    {
        switch(temp){
            case 8:
                sub_8028B04(2);
                break;
            case 9:
            case 10:
                sub_8028B04(2);
                break;
            default:
                break;
        }
    }
}

void sub_8028F04()
{
    s32 temp;
    s32 counter;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    for(counter = 0; counter <= 31; counter++)
    {
        sub_8095240(counter);
    }
    sub_8028B04(0x15);
}

void sub_8028F30()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(22);
    sub_8011C28(1);
    sub_8012574(0);
}

void sub_8028F58()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(sub_8012600() == 0)
    {
        sub_8012750();
        sub_8028B04(2);
    }
}

void sub_8028F80()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_809927C(gUnknown_203B2C0->unk44[234]);
    gUnknown_203B2C0->unk53C = 1;
    sub_8028B04(3);
}

void sub_8028FC0()
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

