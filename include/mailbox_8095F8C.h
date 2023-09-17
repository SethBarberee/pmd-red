#ifndef GUARD_MAILBOX_8095F8C_H
#define GUARD_MAILBOX_8095F8C_H

s32 CountFilledMailboxSlots(void);
WonderMail *GetMailboxSlotInfo(u8 index);
bool8 IsMailSlotEmpty(u8 index);
void ResetMailbox(void);
void ResetMailboxSlot(u8 index);
void sub_8096078(void);
void sub_8096114(void);
void sub_80961B4(void);
bool8 sub_80961D8(void);
bool8 sub_80963B4(void);
void sub_80963FC(void);
void sub_8096488(void);
bool8 sub_80964B4(void);
bool8 sub_80964E4(void);
WonderMail *GetPelipperBoardSlotInfo(u8 index);
bool8 IsPelipperBoardSlotEmpty(u8 index);
void ResetPelipperBoardSlot(u8 index);

#endif
