#include "global.h"

// Wonder Mail Related
struct WonderMailStruct_203B2C0
{
    u32 unk0;
    u32 unk4;
    u8 padding2[0x38];
    u32 unk40;
    u32 unk44;
    u16 unk48[232];
    u8 unk218;
    u8 padding7[3];
    u32 unk21C;
    u8 padding[0x7C];
    u32 unk29C;
    u8 padding6[0x6C];
    u32 unk30C;
    u8 padding8[0x4C];
    u32 unk35C;
    u8 padding5[0x5C];
    u32 unk3BC;
    u8 padding4[0x60];
    u32 unk420;
    u8 padding3[0x110];
    u32 unk534;
    s32 unk538; // A7 << 3
    u32 unk53C;
    u32 unk540; // A8 << 4
    u16 unk544;
};

struct unkStruct_8095228
{
    u32 unk0;
    u8 unk4;
    u8 padding[0x27];
    s8 unk30;
};

extern struct WonderMailStruct_203B2C0 *gUnknown_203B2C0;

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

extern struct unkStruct_8095228 *sub_8095228(u8);
extern u8 sub_80A2824(u32);

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
extern void sub_800641C(u32 *r0, u32, u32);
extern void sub_8004914();
extern void sub_803084C();
extern u32 sub_8030768(u32);
extern u8 sub_80307EC();
extern void sub_8030D40(u8, u32);
extern void sub_8006518(u32 *r0);
extern u8 sub_8012FD8(u32 *r0);
extern void sub_8030810(u32);
extern void sub_8035CC0(u32 *r0, u32);
extern void sub_8013114(u32 *r0, u32 *r1);
extern void sub_8035CF4(u32 *r0, u32, u32);
extern u32 sub_8030DA0(void);
extern void sub_8030DE4(void);
extern void sub_800641C(u32 *r0, u32, u32);
extern void sub_803092C(void);
extern void sub_8011C28(u32);
extern void sub_8012574(u32);
extern u8 sub_8012600();
extern u32 sub_8012744();
extern void sub_8012750();

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
    gUnknown_203B2C0->unk544 = 0xffff;
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
    switch(gUnknown_203B2C0->unk538)
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
        case 8:
            sub_8028B04(20);
            break;
        case 10:
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
    sub_8028B04(24);
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
    sub_8028B04(21);
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
    sub_809927C(gUnknown_203B2C0->unk218);
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

void sub_8028FDC(void)
{
    s32 temp;
    struct unkStruct_8095228 *return_var;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            return_var = sub_8095228(gUnknown_203B2C0->unk218);
            if(sub_80A2824(return_var->unk4) == 0)
            {
                sub_8028B04(0x1C);
            }
            else
            {
                if(return_var->unk30 <= 0)
                {
                    sub_8028B04(0x1D);
                }
                else
                {
                    sub_8028B04(0x1B);
                }
            }
            break;
        case 9:
        case 10:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8029044(void)
{
    switch(sub_8030768(1))
    {
        case 2:
            sub_803084C();
            sub_8028B04(1);
            break;
        case 3:
            gUnknown_203B2C0->unk218 = sub_80307EC();
            sub_8028B04(32);
            break;
        case 4:
            gUnknown_203B2C0->unk0 = 0x1F;
            gUnknown_203B2C0->unk218 = sub_80307EC();
            sub_8006518(&(gUnknown_203B2C0->unk3BC));
            sub_8004914();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B2C0->unk218, 0);
            sub_8028B04(33);
            break;
    }
}

void sub_80290D4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(31);
}

void sub_80290F0(void)
{
    s32 temp;
    temp = -1;
    sub_8030768(0);
    if(sub_8012FD8(&(gUnknown_203B2C0->unk30C)) == 0)
    {
        sub_8013114(&(gUnknown_203B2C0->unk30C), &temp);
    }
    switch(temp)
    {
        case 11:
            sub_803084C();
            sub_8028B04(34);
            break;
        case 12:
            gUnknown_203B2C0->unk0 = 0x3D;
            sub_8006518(&(gUnknown_203B2C0->unk3BC));
            sub_8004914();
            sub_800641C(0, 1, 1);
            sub_8030D40(gUnknown_203B2C0->unk218, 0);
            sub_8028B04(33);
            break;
        case 4:
        case 10:
            sub_8035CC0(&(gUnknown_203B2C0->unk35C), 2);
            sub_8030810(1);
            sub_8028B04(31);
            break;
        default:
            break;
    }
}

void sub_80291AC(void)
{
    switch(sub_8030DA0())
    {
        case 2:
        case 3:
            sub_8030DE4();
            sub_8004914();
            sub_800641C(&(gUnknown_203B2C0->unk3BC), 1, 1);
            sub_803092C();
            if(gUnknown_203B2C0->unk0 == 0x3D)
            {
                sub_8035CF4(&(gUnknown_203B2C0->unk21C), 3, 1);
                sub_8028B04(0x20);
            }
            else
            {
                sub_8028B04(gUnknown_203B2C0->unk0);
            }
        default:
            break;
    }
}

void sub_8029208(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {

        case 13:
        case 14:
            gUnknown_203B2C0->unk534 = 0xD;
            switch(gUnknown_203B2C0->unk538)
            {
                case 0:
                    sub_8028B04(4);
                    break;
                case 2:
                    sub_8028B04(0x30);
                    break;
                default:
                    return;
            }
            break;
        case 15:
            gUnknown_203B2C0->unk534 = temp;
            switch(gUnknown_203B2C0->unk538)
            {
                case 0:
                    sub_8028B04(0x26);
                    break;
                case 2:
                    sub_8028B04(0x3A);
                    break;
                default:
                    return;
            }
            break;
        case 10:
            sub_8028B04(1);
            break;
    }
}

void sub_80292A4(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 8:
            switch(gUnknown_203B2C0->unk538)
            {
                case 0:
                case 2:
                    sub_8028B04(5);
                    break;
            }
            break;
        case 10:
            sub_8028B04(1);
            break;
    }
}

void sub_80292EC(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(gUnknown_203B2C0->unk44 == 0)
    {
        switch(gUnknown_203B2C0->unk538)
        {
            case 0:
                sub_8028B04(0x23);
                break;
            case 2:
                sub_8028B04(0x37);
                break;
        }
    }
    else
    {
        sub_8028B1C(gUnknown_203B2C0->unk44);
        sub_8028B04(0x7);
    }
}

void sub_802933C(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

void sub_8029358(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

void sub_8029374(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x24);
    sub_8011C28(1);
    sub_8012574(0);
}

void sub_802939C(void)
{
    s32 temp;
    u32 return_var;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(sub_8012600() == 0)
    {
        return_var = sub_8012744();
        sub_8012750();
        if(return_var == 0)
        {
            sub_8028B04(0x25);
        }
        else
        {
            sub_8028B04(0x2);
        }
    }
}

void sub_80293D8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x27);
}
