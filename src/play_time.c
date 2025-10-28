#include "global.h"
#include "globaldata.h"
#include "play_time.h"
#include "data_serializer.h"

EWRAM_INIT struct PlayTimeStruct *gPlayTimeRef = {NULL};
EWRAM_DATA struct PlayTimeStruct gPlayTime = {0};

void InitializePlayTime(void)
{
    gPlayTimeRef = &gPlayTime;
    ResetPlayTime(&gPlayTime);
}

struct PlayTimeStruct *GetPlayTime(void)
{
    return &gPlayTime;
}

void ResetPlayTime(struct PlayTimeStruct *Time)
{
    Time->frames = 0;
    Time->seconds = 0;
    Time->minutes = 0;
    Time->hours = 0;
}

void IncrementPlayTime(struct PlayTimeStruct *Time)
{
    u16 temp_store16;

    Time->frames++;
    if(Time->frames <= 59)
        return;
    Time->frames = 0;

    Time->seconds++;
    if(Time->seconds <= 59)
        return;
    Time->seconds = 0;

    Time->minutes++;
    if(Time->minutes <= 59)
        return;
    Time->minutes = 0;

    // Casting here for unsigned comparison
    temp_store16 = Time->hours;
    if(Time->hours <= 9998)
    {
        temp_store16++;
        Time->hours = temp_store16;
    }
    else
    {
        Time->seconds = 59;
        Time->minutes = 59;
        Time->hours= 9999;
    }
}

void DeconstructPlayTime(struct PlayTimeStruct *r0, u32 *outHours, u32 *outMinutes, u32 *outSeconds)
{
    if(r0->hours <= 9999)
    {
        *outHours = r0->hours;
        *outMinutes = r0->minutes;
        *outSeconds = r0->seconds;
    }
    else
    {
        *outHours = 9999;
        *outMinutes = 59;
        *outSeconds = 59;
    }
}

void WritePlayTimeBits(DataSerializer *r0)
{
    WriteBits(r0, &gPlayTimeRef->frames, 6);
    WriteBits(r0, &gPlayTimeRef->seconds, 6);
    WriteBits(r0, &gPlayTimeRef->minutes, 6);
    WriteBits(r0, &gPlayTimeRef->hours, 14);
}

void ReadPlayTimeBits(DataSerializer *r0)
{
    ReadBits(r0, &gPlayTimeRef->frames, 6);
    ReadBits(r0, &gPlayTimeRef->seconds, 6);
    ReadBits(r0, &gPlayTimeRef->minutes, 6);
    ReadBits(r0, &gPlayTimeRef->hours, 14);
}
