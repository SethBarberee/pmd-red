#include "global.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "wonder_mail.h"
#include "code_80958E8.h"
#include "random.h"
#include "event_flag.h"
#include "rescue_team_info.h"
#include "mailbox_8095F8C.h"

extern unkStruct_203B490 *gUnknown_203B490;

extern u8 sub_8096E2C(void);
bool8 sub_8096E80(u8 floor);
u8 sub_8095E78(void);
bool8 GenerateMailJobInfo(WonderMail *);
bool8 sub_803C1D0(DungeonLocation *, u8);
void sub_803C37C(DungeonLocation *, u8, u8 *);
u8 sub_8095F28(u8);

s32 CountFilledMailboxSlots(void)
{
    s32 index;
    s32 counter;

    counter = 0;
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        if(!IsMailSlotEmpty(index))
            counter++;
    }
    return counter;
}

UNUSED bool8 sub_8095FB0(WonderMail *mail)
{
    s32 index;

    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        if(gUnknown_203B490->mailboxSlots[index].mailType == MAIL_TYPE_NONE)
        {
            gUnknown_203B490->mailboxSlots[index] = *mail;
            return FALSE;
        }
    }
    return TRUE;
}

WonderMail *GetMailboxSlotInfo(u8 index)
{
    return &gUnknown_203B490->mailboxSlots[index];
}

bool8 IsMailSlotEmpty(u8 index)
{
    if(gUnknown_203B490->mailboxSlots[index].mailType == MAIL_TYPE_NONE)
        return TRUE;
    else
        return FALSE;
}

void ResetMailbox(void)
{
    s32 index;
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        ResetMailboxSlot(index);
    }
}

void ResetMailboxSlot(u8 index)
{
    gUnknown_203B490->mailboxSlots[index].mailType = MAIL_TYPE_NONE;
    gUnknown_203B490->mailboxSlots[index].unk4.dungeon.id = 99;
    gUnknown_203B490->mailboxSlots[index].unk4.dungeon.floor = 0;
    gUnknown_203B490->mailboxSlots[index].rewardType = MONEY1;
}

//  https://decomp.me/scratch/bggYn (80.39% matching - Seth)
#ifdef NONMATCHING
void sub_8096078(void)
{
  int counter1; // r5
  int counter2;
    
  
  counter1 = 0;
  counter2 = 0;

  do {
    if (counter1 > counter2) {
        gUnknown_203B490->mailboxSlots[counter1] = gUnknown_203B490->mailboxSlots[counter2];
    }
    counter1++;
    counter2++;
      
    for( ; counter1 < 4; counter1++)
    {
        if(gUnknown_203B490->mailboxSlots[counter1].mailType != 0)
            break;
    }
      
    if (counter1 == 4) {
        for(; counter2 < 4; counter2++)
        {
            gUnknown_203B490->mailboxSlots[counter2].mailType = 0;
        }
        break;
    }
  } while( 1 );
}
#else
NAKED
void sub_8096078(void)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r9\n"
	"\tmov r6, r8\n"
	"\tpush {r6,r7}\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0\n"
	"\tldr r0, _08096090\n"
	"\tmov r12, r0\n"
	"\tmov r8, r3\n"
	"\tmovs r4, 0\n"
	"\tmov r9, r4\n"
	"\tb _080960B6\n"
	"\t.align 2, 0\n"
"_08096090: .4byte gUnknown_203B490\n"
"_08096094:\n"
	"\tcmp r2, r3\n"
	"\tble _080960AA\n"
	"\tmov r1, r12\n"
	"\tldr r0, [r1]\n"
	"\tmov r5, r8\n"
	"\tadds r1, r0, r5\n"
	"\tadds r0, r4\n"
	"\tldm r0!, {r5-r7}\n"
	"\tstm r1!, {r5-r7}\n"
	"\tldm r0!, {r6,r7}\n"
	"\tstm r1!, {r6,r7}\n"
"_080960AA:\n"
	"\tadds r4, 0x14\n"
	"\tmovs r0, 0x14\n"
	"\tadd r9, r0\n"
	"\tadds r2, 0x1\n"
	"\tadd r8, r0\n"
	"\tadds r3, 0x1\n"
"_080960B6:\n"
	"\tcmp r2, 0x3\n"
	"\tbgt _080960E2\n"
	"\tmov r1, r12\n"
	"\tldr r0, [r1]\n"
	"\tadds r0, r4\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbne _080960E2\n"
	"\tldr r6, _08096110\n"
	"\tmov r1, r9\n"
"_080960CA:\n"
	"\tadds r1, 0x14\n"
	"\tadds r4, 0x14\n"
	"\tmovs r5, 0x14\n"
	"\tadd r9, r5\n"
	"\tadds r2, 0x1\n"
	"\tcmp r2, 0x3\n"
	"\tbgt _080960E2\n"
	"\tldr r0, [r6]\n"
	"\tadds r0, r1\n"
	"\tldrb r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbeq _080960CA\n"
"_080960E2:\n"
	"\tcmp r2, 0x4\n"
	"\tbne _08096094\n"
	"\tcmp r3, 0x3\n"
	"\tbgt _08096102\n"
	"\tldr r4, _08096110\n"
	"\tmovs r2, 0\n"
	"\tlsls r0, r3, 2\n"
	"\tadds r0, r3\n"
	"\tlsls r1, r0, 2\n"
"_080960F4:\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, r1\n"
	"\tstrb r2, [r0]\n"
	"\tadds r1, 0x14\n"
	"\tadds r3, 0x1\n"
	"\tcmp r3, 0x3\n"
	"\tble _080960F4\n"
"_08096102:\n"
	"\tpop {r3,r4}\n"
	"\tmov r8, r3\n"
	"\tmov r9, r4\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08096110: .4byte gUnknown_203B490"
    );
}
#endif

void sub_8096114(void) {
    s32 r1;
    s32 r6;
    WonderMail job;
    
    for(r1 = 0; r1 < NUM_MAILBOX_SLOTS - 1; r1++)
    {
         for(r6 = r1 + 1; r6 < NUM_MAILBOX_SLOTS; r6++)
        {
                if(gUnknown_203B490->mailboxSlots[r6].mailType != 0)
                {
                    if((gUnknown_203B490->mailboxSlots[r1].unk4.dungeon.id > gUnknown_203B490->mailboxSlots[r6].unk4.dungeon.id) || 
                        ((gUnknown_203B490->mailboxSlots[r1].unk4.dungeon.id == gUnknown_203B490->mailboxSlots[r6].unk4.dungeon.id) && 
                        (gUnknown_203B490->mailboxSlots[r1].unk4.dungeon.floor > gUnknown_203B490->mailboxSlots[r6].unk4.dungeon.floor)))
                    {
                        job = gUnknown_203B490->mailboxSlots[r1];
                        gUnknown_203B490->mailboxSlots[r1] = gUnknown_203B490->mailboxSlots[r6];
                        gUnknown_203B490->mailboxSlots[r6] =  job;
                    }
                }
        }
    }
}

void sub_80961B4(void) {
    if(sub_8096E2C() != 0)
    {
        gUnknown_203B490->unk328 = 1;
    }
}

bool8 sub_80961D8(void) {
    s32 num;
    s32 index;
    u32 floor;
    s32 friendAreaReward;
    WonderMail *slot;
    bool8 flag = FALSE;
    
    num = CountFilledMailboxSlots();
    index = RandRange(num, NUM_MAILBOX_SLOTS);
    if(num >= NUM_MAILBOX_SLOTS) return FALSE;
    if(!gUnknown_203B490->unk328) 
        return FALSE;
    else
    {
         gUnknown_203B490->unk328 = flag;
    }
    floor = 0x38;
    if(sub_8001D08(0xA, 0x31, 0x1))
    {
        if(!gUnknown_203B490->PKMNNewsReceived[0x35])
            if(!sub_8096E80(0x35)) floor = 0x35;
    }
    if(sub_80023E4(0xF))
    {
        if(!gUnknown_203B490->PKMNNewsReceived[0x34])
            if(!sub_8096E80(0x34)) floor = 0x34;
        if(!gUnknown_203B490->PKMNNewsReceived[0x33])
            if(!sub_8096E80(0x33)) floor = 0x33;
        if(!gUnknown_203B490->PKMNNewsReceived[0x32])
            if(!sub_8096E80(0x32)) floor = 0x32;

    }
    if(GetRescueTeamRank() == LUCARIO_RANK)
    {
        if(!gUnknown_203B490->PKMNNewsReceived[0x36])
            if(!sub_8096E80(0x36)) floor = 0x36;
    }
    if(sub_80023E4(6))
    {
        if(!gUnknown_203B490->PKMNNewsReceived[0x37])
            if(!sub_8096E80(0x37)) floor = 0x37;
    }
    
    if(floor != 0x38) goto _slot;
    if(num > index) goto _08096392;
    floor = sub_8096E2C();
    if(!sub_80023E4(0xE) && (floor > 2)) goto _0809638E;
    if (floor > 0x31) goto _0809638E;
_slot:
    slot = GetMailboxSlotInfo(num);
    slot->mailType = 1;
    slot->unk4.dungeon.id = NUM_DUNGEONS;
    slot->unk4.dungeon.floor = floor;
    goto _flag;
_0809638E:
    for(; num <= index; num++)
    {
        slot = GetMailboxSlotInfo(num);
        if(GenerateMailJobInfo(slot))
        {
            friendAreaReward = sub_8095E78();
            if(!sub_803C1D0(&slot->unk4.dungeon, slot->missionType)) friendAreaReward = NONE;
            slot->rewardType = RandRange(MONEY1, END_REWARDS);
            if(slot->rewardType == FRIEND_AREA)
            {
                if(!friendAreaReward)
                {
                    slot->rewardType = MONEY1;
                    flag = TRUE;
                }
                else
                {
                    slot->friendAreaReward = friendAreaReward;
                    flag = TRUE;
                }
            }
            else
            {
_flag:
                flag = TRUE;
            }
        } else break;
    }
_08096392:
    if(sub_80963B4())
        flag = TRUE;
    sub_8096078();
    sub_8096114();
    return flag;
}

bool8 sub_80963B4(void) {
    u8 floor;
    s32 num;
    WonderMail *slot;
    bool8 flag = FALSE;
    
    floor = sub_8096E2C();
    num = CountFilledMailboxSlots();
    if(num >= NUM_MAILBOX_SLOTS) return FALSE;
    if(sub_80023E4(0xE))
    {
        if(floor < 0x32)
        {
            slot = GetMailboxSlotInfo(num);
            slot->mailType = 1;
            slot->unk4.dungeon.id = NUM_DUNGEONS;
            slot->unk4.dungeon.floor = floor;
            flag = TRUE;
        }
    }
    return flag;
}

void sub_80963FC(void) {
    s32 index;
    WonderMail *slot;
    
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        slot = GetMailboxSlotInfo(index);
        if(slot->mailType != 1)
        {
            ResetMailboxSlot(index);
        }
    }
    sub_8096078();
    slot = GetMailboxSlotInfo(CountFilledMailboxSlots());
    slot->mailType = 5;
    slot->missionType = 0;
    slot->unk2 = 0;
    slot->unk4.dungeon.id = DUNGEON_MT_STEEL;
    slot->unk4.dungeon.floor = 3;
    slot->unk4.seed = 0x00ffffff & Rand32Bit();
    slot->clientSpecies = MONSTER_PIDGEY;
    slot->targetSpecies = MONSTER_PIDGEY;
    slot->targetItem = sub_8095F28(slot->unk4.dungeon.id);
    slot->rewardType = MONEY1;
    do
    {
        sub_803C37C(&slot->unk4.dungeon, slot->missionType, &slot->itemReward);
    } while (slot->targetItem == slot->itemReward);
    slot->friendAreaReward = NONE;
    sub_8096078();
    sub_8096114();
}

void sub_8096488(void) {
    s32 index;
    WonderMail *slot;
    
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        ResetMailboxSlot(index);
    }
    slot = GetMailboxSlotInfo(0);
    slot->mailType = 1;
    slot->unk4.dungeon.id = NUM_DUNGEONS;
    slot->unk4.dungeon.floor = 0;
}

bool8 sub_80964B4(void) {
    if(!gUnknown_203B490->PKMNNewsReceived[0x35])
        if(!sub_8096E80(0x35))
            return FALSE;
    return TRUE;
}

bool8 sub_80964E4(void) {
    if(!gUnknown_203B490->PKMNNewsReceived[0x36])
        if(!sub_8096E80(0x36))
            return FALSE;
    return TRUE;
}

UNUSED s32 CountFilledPelipperBoardSlots(void) {
    s32 index;
    s32 counter;
    
    counter = 0;
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        if(!IsPelipperBoardSlotEmpty(index))
            counter++;
    }
    return counter;
}

UNUSED bool8 sub_8096538(WonderMail *mail) {
    s32 index;
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        if(gUnknown_203B490->pelipperBoardJobs[index].mailType == 0)
        {
            gUnknown_203B490->pelipperBoardJobs[index] = *mail;
            return FALSE;
        }
    }
    return TRUE;
}

WonderMail *GetPelipperBoardSlotInfo(u8 index) {
    return &gUnknown_203B490->pelipperBoardJobs[index];
}

bool8 IsPelipperBoardSlotEmpty(u8 index) {
    if(gUnknown_203B490->pelipperBoardJobs[index].mailType == 0)
        return TRUE;
    else
         return FALSE;
}

void ResetPelipperBoardSlot(u8 index) {
    gUnknown_203B490->pelipperBoardJobs[index].mailType = 0;
    gUnknown_203B490->pelipperBoardJobs[index].unk4.dungeon.id = NUM_DUNGEONS + 1;
    gUnknown_203B490->pelipperBoardJobs[index].unk4.dungeon.floor = 0;
    gUnknown_203B490->pelipperBoardJobs[index].rewardType = 0;
}
