









static const struct ScriptCommand s_gs179_g0_s0_station_sref_script[] = { /* 0x822fcbc */
    DEBUGINFO,
    SELECT_MAP(179),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs179_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs179_g0_s0_station_sref_script }; /* 0x822fd28 */

static const struct ScriptCommand s_gs179_g1_s0_station_sref_script[] = { /* 0x822fd34 - PART 1 0:16:37-0:17:16 - Tiny Woods end room */
    DEBUGINFO,
    SELECT_MAP(179),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(114),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    RET,
};

static const struct ScriptRef s_gs179_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs179_g1_s0_station_sref_script }; /* 0x822fdc4 */

static const struct ScriptCommand s_gs179_g1_s0_lives0_dlg0[] = { /* 0x822fdd0 - PART 1 0:16:37-0:17:16 - Player */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    PORTRAIT(PLACEMENT_LEFT_, 0x0000, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0001, 0x00000000),
    PORTRAIT(PLACEMENT_MIDDLE_TOP_LEFT, 0x0002, 0x00000000),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0002, 0x00000042),
    MSG_NPC(2, _(" Waaaaah...")),
    MSG_NPC(2, _(" Mommy...\nWhere are you...? Sniffle...")),
    TEXTBOX_CLEAR,
    WAIT(30),
    { 0xe4, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" We came to rescue you.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    MSG_NPC(2, _(" Huh?")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" Your mom's waiting.\nLet's get you out!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    { 0xe4, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    PORTRAIT_REP(0x0002, 0x00000000),
    MSG_NPC(2, _(" OK.")),
    TEXTBOX_CLEAR,
    { 0xe4, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    HALT,
};






static const struct ScriptCommand s_gs179_g1_s0_lives1_dlg0[] = { /* 0x82300a8 - PART 1 0:16:37-0:17:16 - Partner */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0006,  0x00000000,  0x00000000, NULL },
    { 0x6b, 0x00,  0x0100,  0x00000001,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs179_g1_s0_lives2_dlg0[] = { /* 0x8230108 - PART 1 0:16:37-0:17:16 - Caterpie */
    DEBUGINFO,
    { 0x54, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x0000003e,  0x00000000, NULL },
    FANFARE_PLAY2(457),
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xe2, 0x00,  0x01c9,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    { 0x91, 0x04,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    CALL_SCRIPT(JUMP_HAPPY_FUNC),
    { 0xe4, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    { 0xe3, 0x00,  0x0007,  0x00000000,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs179_g1_s0_lives[] = { /* 0x8230218 */
    /*  0 */ {   0,   4,   0,   0, {  20,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs179_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   4,   0,   0, {  24,  34, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs179_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  54,   4,   0,   0, {  22,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs179_g1_s0_lives2_dlg0,
    } },
};

static const struct GroundEffectData s_gs179_g1_s0_effs[] = { /* 0x8230260 */
    /*  0 */ {   0,   0,   1,   1, {  22,  21, CPOS_HALFTILE, 0 }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x823026c */
    &s_gs179_g0_s0_station_sref,
    &s_gs179_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs179_g0_sectors[] = { /* 0x8230274 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs179_g1_sectors[] = { /* 0x823029c */
    { LPARRAY(s_gs179_g1_s0_lives), 0,NULL, LPARRAY(s_gs179_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs179_groups[] = { /* 0x82302c4 */
    { LPARRAY(s_gs179_g0_sectors) },
    { LPARRAY(s_gs179_g1_sectors) },
};

static const struct GroundLink s_gs179_links[] = { /* 0x82302d4 */
    /* link   0 */ { { /*x*/  20, /*y*/  23, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  24, /*y*/  23, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs179 = { LPARRAY(s_gs179_groups), s_gs179_links }; /* 0x82302e4 */
