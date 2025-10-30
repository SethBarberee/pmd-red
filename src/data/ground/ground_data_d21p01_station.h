







static const struct ScriptCommand s_gs217_g0_s0_station_sref_script[] = { /* 0x8269754 */
    DEBUGINFO_O(10),
    SELECT_MAP(217),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs217_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs217_g0_s0_station_sref_script }; /* 0x82697c0 */

static const struct ScriptCommand s_gs217_g1_s0_station_sref_script[] = { /* 0x82697cc */
    DEBUGINFO_O(19),
    SELECT_MAP(217),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(114),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    BGM_FADEOUT(60),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs217_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs217_g1_s0_station_sref_script }; /* 0x826986c */

static const struct ScriptCommand s_gs217_g1_s0_lives0_dlg0[] = { /* 0x8269878 */
    DEBUGINFO_O(34),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(475),
    ALERT_CUE(7),
    WAIT(10),
    { 0x28, 0x01,  0x0005,  0x00000005,  0x00ffffff, NULL },
    { 0x27, 0x01,  0x0005,  0x00000005,  0x00ffffff, NULL },
    { 0xe2, 0x00,  0x01db,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_RIGHT, 0x0002, 0x00000000),
    MSG_NPC(2, _(" Urghgh...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    MSG_NPC(2, _(" ............{WAIT_PRESS}Please...\nPlease let me go...")),
    MSG_NPC(2, _(" I have to go...{WAIT_PRESS}\nThere's somewhere that I have to go...")),
    MSG_NPC(2, _(" If...I don't hurry...{WAIT_PRESS}\nM-my little sister...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    WAIT(30),
    CALL_SCRIPT(SHOCK_FUNC),
    ALERT_CUE(3),
    WALK_RELATIVE(204, 0, -48),
    HALT,
};


static const struct ScriptCommand s_gs217_g1_s0_lives1_dlg0[] = { /* 0x8269b04 */
    DEBUGINFO_O(68),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    SELECT_ANIMATION(19),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    SELECT_ANIMATION(25),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(33),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x54, 0x00,  0x001d,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    FANFARE_PLAY2(475),
    SELECT_ANIMATION(9),
    { 0xe2, 0x00,  0x01db,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(779),
    { 0x54, 0x00,  0x000a,  0x00000000,  0x00000000, NULL },
    WAIT(50),
    { 0x54, 0x00,  0x001a,  0x00000000,  0x00000000, NULL },
    WAIT(40),
    FANFARE_PLAY2(682),
    { 0xe2, 0x00,  0x02aa,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    HALT,
};

static const struct GroundLivesData s_gs217_g1_s0_lives[] = { /* 0x8269cb4 */
    /*  0 */ {   0,   4,   0,   0, {  31,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs217_g1_s0_lives0_dlg0,
    } },
    /*  1 */ { 121,   0,   0,   0, {  31,  23, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs217_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs217_g1_s0_effs[] = { /* 0x8269ce4 */
    /*  0 */ {   0,   0,   1,   1, {  31,  29, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8269cf0 */
    &s_gs217_g0_s0_station_sref,
    &s_gs217_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs217_g0_sectors[] = { /* 0x8269cf8 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs217_g1_sectors[] = { /* 0x8269d20 */
    { LPARRAY(s_gs217_g1_s0_lives), 0,NULL, LPARRAY(s_gs217_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs217_groups[] = { /* 0x8269d48 */
    { LPARRAY(s_gs217_g0_sectors) },
    { LPARRAY(s_gs217_g1_sectors) },
};

static const struct GroundLink s_gs217_links[] = { /* 0x8269d58 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs217 = { LPARRAY(s_gs217_groups), s_gs217_links }; /* 0x8269d60 */
