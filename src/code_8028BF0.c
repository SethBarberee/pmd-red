#include "global.h"


// TODO unify with code_8028DE8
// Wonder mail related
struct unkStruct_203B2C0
{
    u32 padding;
    u32 unk4;
    u8 padding2[0x38];
    u32 unk40;
    u16 unk44[494]; // TODO figure out correct size
    u32 unk420;
    u8 padding3[0x114];
    u32 unk538;
};

extern u32 gWonderMailErrorText;
extern u32 gWonderMailNumGBAsText;
extern u32 gWonderMailWrongModeText;
extern u32 gWonderMailStorageFullText;
extern u32 gWonderMailDuplicateText;
extern u32 gWonderMailNotEligibleReceiveText;
extern u32 gWonderMailNoRoomText;
extern u32 gWonderMailFriendErrorText;

extern u32 sub_80144A4(s32 *r0);
extern struct unkStruct_203B2C0 *gUnknown_203B2C0;
extern void sub_8028B04(u32);
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
            return;
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
            return;
        case 9:
            sub_80141B4(&gWonderMailNotEligibleReceiveText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 10:
            return;
        case 11:
            sub_80141B4(&gWonderMailNotEligibleReceiveText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 12:
            return;
        case 13:
            sub_80141B4(&gWonderMailNoRoomText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 14:
            sub_80141B4(&gWonderMailErrorText, 0, &gUnknown_203B2C0->unk420, 0x10d);
            break;
        case 15:
            sub_80141B4(&gWonderMailFriendErrorText, 0, &gUnknown_203B2C0->unk420, 0x10d);
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
    gUnknown_203B2C0->unk44[640] = 0xffff; // TODO needs to be strh
    switch(temp)
    {
        case 0:
            gUnknown_203B2C0->unk40 = 3;
            gUnknown_203B2C0->unk538 = 0;
            if(sub_8095190() != -1){
                sub_8028B04(8);
            }
            else
            {
                sub_8028B04(9);
            }
            break;
        case 1:
            if(sub_8095324(2) != 0)
                sub_8028B04(30);
            else
            {
                sub_8028B04(26);
            }
            break;
        case 2:
            gUnknown_203B2C0->unk40 = 4;
            gUnknown_203B2C0->unk538 = 2;
            if(sub_8095324(4) != 0)
                sub_8028B04(41);
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
            return;

        case 10:
            sub_8028B04(2);
            break;
    }
}

