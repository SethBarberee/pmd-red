#include "constants/mailbox.h"
#include "global.h"
#include "constants/dungeon.h"
#include "constants/monster.h"
#include "constants/wonder_mail.h"
#include "items.h"
#include "code_80958E8.h"
#include "code_80958E8_1.h"
#include "random.h"
#include "pokemon.h"

void SortJobSlots(void) {
    s32 r1;
    s32 r6;
    WonderMail job;
    
    for(r1 = 0; r1 < MAX_ACCEPTED_JOBS - 1; r1++)
    {
         for(r6 = r1 + 1; r6 < MAX_ACCEPTED_JOBS; r6++)
        {
                if(gUnknown_203B490->jobSlots[r6].mailType != 0)
                {
                    if((gUnknown_203B490->jobSlots[r1].unk4.dungeon.id > gUnknown_203B490->jobSlots[r6].unk4.dungeon.id) || 
                        ((gUnknown_203B490->jobSlots[r1].unk4.dungeon.id == gUnknown_203B490->jobSlots[r6].unk4.dungeon.id) && 
                        (gUnknown_203B490->jobSlots[r1].unk4.dungeon.floor > gUnknown_203B490->jobSlots[r6].unk4.dungeon.floor)))
                    {
                        job = gUnknown_203B490->jobSlots[r1];
                        gUnknown_203B490->jobSlots[r1] = gUnknown_203B490->jobSlots[r6];
                        gUnknown_203B490->jobSlots[r6] =  job;
                    }
                }
        }
    }
}

u8 *sub_8096DD8(void) {
    return gUnknown_203B490->unk190;
}

u8 *sub_8096DE8(void) {
    return gUnknown_203B490->unk1B8;
}

void ReceivePKMNNews(u8 index) {
    gUnknown_203B490->PKMNNewsReceived[index] = TRUE;
}

bool8 CheckPKMNNewsSlot(u8 index) {
    return gUnknown_203B490->PKMNNewsReceived[index];
}

u8 sub_8096E2C(void) {
    s32 index;
    s32 floor = 0;
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        if(gUnknown_203B490->mailboxSlots[index].mailType == 1)
        {
             if(floor <= gUnknown_203B490->mailboxSlots[index].unk4.dungeon.floor)
                 if( gUnknown_203B490->mailboxSlots[index].unk4.dungeon.floor < 50) 
                    floor =  gUnknown_203B490->mailboxSlots[index].unk4.dungeon.floor + 1;
        }
    }

    for(index = floor; index < 50; index++)
    {
        if(!gUnknown_203B490->PKMNNewsReceived[index]) return index;
    }
    return 0x38;
}

bool8 sub_8096E80(u8 floor) {
    s32 index;
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        if(gUnknown_203B490->mailboxSlots[index].mailType == 1)
        {
             if(floor == gUnknown_203B490->mailboxSlots[index].unk4.dungeon.floor)
                return TRUE;
        }
    }
    return FALSE;
}

s32 sub_8096EB0(WonderMail *mail) {
    s32 sum;

    sum = (mail->unk2 + mail->missionType);
    
    sum += mail->unk4.dungeon.id;
    sum += mail->unk4.dungeon.floor;

    sum += mail->unk4.seed << 8;

    sum += mail->clientSpecies << 12;

    sum += mail->targetSpecies << 16;

    sum += mail->targetItem << 24;

    sum += mail->rewardType;

    sum += mail->itemReward;

    sum += mail->friendAreaReward;

    return sum;
}

// https://decomp.me/scratch/gl6SB  (97.92% matching - Seth)

#ifdef NONMATCHING
void sub_8096EEC(WonderMail *r0) {
    register WonderMail *temp1 asm("ip");
    s32 index;

    temp1 = r0;

    for(index = 15; index > 0; index--)
    {
         gUnknown_203B490->unk230[index] =  gUnknown_203B490->unk230[index - 1];
    }
    {
        register DungeonLocation temp;
        register subStruct_203B490 *org;
        register s32 seed;
        
        org = &gUnknown_203B490->unk230[0];
        temp = temp1->unk4.dungeon;
        seed = temp1->unk4.seed;
        org->dungeon = temp;
        org->seed = seed;
    }
    gUnknown_203B490->unk230[0].unk8 = sub_8096EB0(temp1);
}
#else
NAKED
void sub_8096EEC(WonderMail *r0) {
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tmov r12, r0\n"
	"\tmovs r3, 0xF\n"
	"\tldr r5, _08096F4C\n"
	"\tmov r8, r5\n"
	"\tmovs r4, 0x8C\n"
	"\tlsls r4, 2\n"
"_08096EFE:\n"
	"\tmov r0, r8\n"
	"\tldr r2, [r0]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 2\n"
	"\tadds r1, r2, r1\n"
	"\tsubs r3, 0x1\n"
	"\tlsls r0, r3, 1\n"
	"\tadds r0, r3\n"
	"\tlsls r0, 2\n"
	"\tadds r2, r0\n"
	"\tadds r1, r4\n"
	"\tadds r2, r4\n"
	"\tldm r2!, {r0,r6,r7}\n"
	"\tstm r1!, {r0,r6,r7}\n"
	"\tcmp r3, 0\n"
	"\tbgt _08096EFE\n"
	"\tldr r2, [r5]\n"
	"\tmovs r3, 0x8C\n"
	"\tlsls r3, 2\n"
	"\tadds r2, r3\n"
	"\tmov r6, r12\n"
	"\tldr r0, [r6, 0x4]\n"
	"\tldr r1, [r6, 0x8]\n"
	"\tstr r0, [r2]\n"
	"\tstr r1, [r2, 0x4]\n"
	"\tmov r0, r12\n"
	"\tbl sub_8096EB0\n"
	"\tldr r1, [r5]\n"
	"\tmovs r7, 0x8E\n"
	"\tlsls r7, 2\n"
	"\tadds r1, r7\n"
	"\tstr r0, [r1]\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08096F4C: .4byte gUnknown_203B490");

}

#endif
