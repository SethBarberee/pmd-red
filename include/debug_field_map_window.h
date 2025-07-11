#ifndef GUARD_DEBUG_FIELD_MAP_WINDOW_H
#define GUARD_DEBUG_FIELD_MAP_WINDOW_H

#define DEBUG_INPUT_NOTHING 0
#define DEBUG_INPUT_DPAD    1
#define DEBUG_INPUT_B_PRESS 2
#define DEBUG_INPUT_A_PRESS 3

bool8 DebugFieldMapWindow_Init(void);
void DebugFieldMapWindow_MoveMenuTo(s16);
u32 DebugFieldMapWindow_GetInput(void);
s16 DebugFieldMapWindow_GetCurrentIndex(void);
void DebugFieldMapWindow_Free(void);

#endif // GUARD_DEBUG_FIELD_MAP_WINDOW_H
