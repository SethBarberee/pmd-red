struct LocalScriptVarInfo
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    const u8 *text;
};

const struct LocalScriptVarInfo sLocalScriptVarInfo[4] = {
    5, 7, 0, 0, 1, 0, "LOCAL0",
    5, 7, 2, 0, 1, 0, "LOCAL1",
    5, 7, 4, 0, 1, 0, "LOCAL2",
    5, 7, 6, 0, 1, 0, "LOCAL3",
};

struct unkStruct_80B6D90
{
    const u8 *text;
    s32 num;
};

const u8 gUnknown_80B7144[];

const struct unkStruct_80B6D90 gUnknown_80B6D90[59] = {
    {gUnknown_80B7144, 0},
    {"M00E01A", -1},
    {"M01E01A", -1},
    {"M01E02A", -1},
    {"M01E02B", -1},
    {"M01E03A", -1},
    {"M01E04A", -1},
    {"M01E04B", -1},
    {"M01E05A", -1},
    {"M01E05B", -1},
    {"M01E06A", -1},
    {"M01E07A", -1},
    {"M01E07B", -1},
    {"M01E08A", -1},
    {"M01E08B", -1},
    {"M01E09A", -1},
    {"M01E10A", -1},
    {"M01END", -1},
    {"M02E01A", -1},
    {"M02E02A", -1},
    {"M02E02B", -1},
    {"M02E02C", -1},
    {"M02E02D", -1},
    {"M02E02E", -1},
    {"M02E02F", -1},
    {"M02E02G", -1},
    {"M02E02H", -1},
    {"M02END", -1},
    {"S00E01A", -1},
    {"S01E01A", 1},
    {"S01E01B", 1},
    {"S01E02A", 1},
    {"S01E02B", 2},
    {"S02E01A", -1},
    {"S02E02A", -1},
    {"S02E02B", 3},
    {"S03E01A", 1},
    {"S03E01B", 3},
    {"S04E01A", 1},
    {"S04E01B", 1},
    {"S04E01C", 1},
    {"S04E01D", 1},
    {"S04E01E", 1},
    {"S04E01F", 2},
    {"S05E01A", 1},
    {"S05E01B", 3},
    {"S06E01A", 1},
    {"S06E01B", 1},
    {"S06E01C", 3},
    {"S07E01A", 1},
    {"S07E01B", 3},
    {"S08E01A", 1},
    {"S08E01B", 3},
    {"S09E01A", 1},
    {"S09E01B",1},
    {"S09E01C", 2},
    {"R00E01A", -1},
    {"NEXT DAY", -1},
    {"DEBUG GROUND", -1},
};

ALIGNED(4) const u8 gUnknown_80B7144[] = "NONE";

const u8 *const gUnknown_80B714C[10] = {
    "2-1",
    "2-1",
    "1-2 7",
    "4",
    "5",
    "6",
    "2-2 8",
    "3",
    "9",
    "END",
};

const u8 *const gUnknown_80B71A0[4] = {
    _("{COLOR GREEN_I}START{RESET}"),
    _("{COLOR GENDER_COLOR}CONTINUE{RESET}"),
    _("{COLOR YELLOW_N}LAST{RESET}"),
    _("{COLOR RED_W}END{RESET}"),
};

struct GroundEventTableEntry
{
    // size: 0x4
    s16 groundEnterId;
    u8 value; // Seems like friend area number
};

const struct GroundEventTableEntry gGroundEnterLookupTable[58] = {
    {105, 1 },
    {106, 2 },
    {107, 3 },
    {108, 4 },
    {109, 5 },
    {110, 6 },
    {111, 7 },
    {112, 8 },
    {113, 9 },
    {114, 10},
    {115, 11},
    {116, 12},
    {117, 13},
    {118, 14},
    {119, 15},
    {120, 16},
    {121, 17},
    {122, 18},
    {123, 19},
    {124, 20},
    {125, 21},
    {126, 22},
    {127, 23},
    {128, 24},
    {129, 25},
    {130, 26},
    {131, 27},
    {132, 28},
    {133, 29},
    {134, 30},
    { 135, 31},
    { 136, 32},
    { 137, 33},
    { 138, 34},
    { 139, 35},
    { 140, 36},
    { 141, 37},
    { 142, 38},
    { 143, 39},
    { 144, 40},
    { 145, 41},
    { 146, 42},
    { 147, 43},
    { 148, 44},
    { 149, 45},
    { 150, 46},
    { 151, 47},
    { 152, 48},
    { 153, 49},
    { 154, 50},
    { 155, 51},
    { 156, 52},
    { 157, 53},
    { 158, 54},
    { 159, 55},
    { 160, 56},
    { 161, 57},
    { -1, 0},
};
