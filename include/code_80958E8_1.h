#ifndef GUARD_CODE_80958E8_1_H
#define GUARD_CODE_80958E8_1_H

#include "wonder_mail.h"

void SortPelipperJobs(void);
void GeneratePelipperJobs(void);
bool8 IsMailinJobSlot(WonderMail *mail);
bool8 sub_809693C(WonderMail *mail);
s32 GetNumAcceptedJobs(void);
s32 CountJobsinDungeon(u8 dungeon);
bool8 sub_8096A08(u8 dungeon, u8 *param_2);
bool8 AcceptJob(WonderMail *mail);
WonderMail *GetJobSlotInfo(u8 index);
bool8 IsJobSlotEmpty(u8 index);
bool8 sub_8096C08(u8 *jobIndex);
void ResetJobSlot(u8 index);

#endif // GUARD_CODE_80958E8_1_H
