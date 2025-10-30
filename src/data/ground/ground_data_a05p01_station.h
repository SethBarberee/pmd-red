







static const struct ScriptCommand s_gs175_g0_s0_station_sref_script[] = { /* 0x822af80 */
    DEBUGINFO_O(10),
    SELECT_MAP(175),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs175_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs175_g0_s0_station_sref_script }; /* 0x822afdc */

static const struct ScriptCommand s_gs175_g1_s0_station_sref_script[] = { /* 0x822afe8 */
    DEBUGINFO_O(18),
    BGM_STOP,
    WAIT(180),
    SELECT_MAP(175),
    SELECT_ENTITIES(-1, 0),
    { 0x3b, 0x36,  0x0000, -0x00000002,  0x00000000, NULL },
    { 0x22, 0x01,  0x00b4,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    WAIT(0),
    { 0x28, 0x01,  0x0001,  0x0000001e,  0x00ffffff, NULL },
    WAIT(45),
    RET,
  LABEL(0), /* = 0x00 */
    { 0x28, 0x01,  0x0001,  0x0000001e,  0x00ffffff, NULL },
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs175_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs175_g1_s0_station_sref_script }; /* 0x822b0e8 */

static const struct ScriptCommand s_gs175_g1_s0_eff1_script[] = { /* 0x822b0f4 */
    DEBUGINFO_O(39),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(40),
    BGM_SWITCH(44),
    WAIT(300),
    TEXTBOX_AUTO_PRESS(-200, 60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(..................)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(What is this...?)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(I'm rising into the sky...)") },
    TEXTBOX_AUTO_PRESS(-190, 60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Is this my spirit...?)") },
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(I wonder where I'm going?)") },
    TEXTBOX_CLEAR,
    WAIT(120),
    TEXTBOX_AUTO_PRESS(-110, 60),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(......!)") },
    TEXTBOX_AUTO_PRESS(-210, 50),
    { 0x33, 0x00,  0x0000,  0x00000000,  0x00000000, _("(Voices...{WAIT_PRESS}\nI hear voices...)") },
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs175_g2_s0_station_sref_script[] = { /* 0x822b2f4 */
    DEBUGINFO_O(64),
    SELECT_MAP(175),
    SELECT_ENTITIES(-1, 0),
    { 0x3b, 0x36,  0x0000, -0x00000002,  0x00000000, NULL },
    BGM_STOP,
    { 0x22, 0x01,  0x00b4,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x28, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    WAIT(170),
    { 0x28, 0x01,  0x0002,  0x0000003c,  0x00ffffff, NULL },
    WAIT(90),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs175_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs175_g2_s0_station_sref_script }; /* 0x822b3c4 */

static const struct ScriptCommand s_gs175_g2_s0_eff1_script[] = { /* 0x822b3d0 */
    DEBUGINFO_O(82),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    BGM_SWITCH(45),
    WAIT(60),
    TEXTBOX_AUTO_PRESS(190, 190),
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    MSG_ON_BG_AUTO(30, _("\n{CENTER_ALIGN}I don't want to leave...")),
    WAIT(100),
    MSG_ON_BG_AUTO(30, _("\n{CENTER_ALIGN}I want to stay longer...")),
    WAIT(100),
    MSG_ON_BG_AUTO(30, _("\n{CENTER_ALIGN}With my invaluable...")),
    WAIT(100),
    MSG_ON_BG_AUTO(30, _("\n{CENTER_ALIGN}Irreplaceable friend...")),
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    HALT,
};

static const struct GroundEffectData s_gs175_g1_s0_effs[] = { /* 0x822b584 */
    /*  0 */ {   0,   0,   1,   1, {  21,  15, 0, CPOS_HALFTILE }, NULL },
    /*  1 */ {   3,   4,   2,   1, {  22,  15, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs175_g1_s0_eff1_script },
};

static const struct GroundEffectData s_gs175_g2_s0_effs[] = { /* 0x822b59c */
    /*  0 */ {   0,   0,   1,   1, {  21,  18, 0, CPOS_HALFTILE }, NULL },
    /*  1 */ {   3,   4,   2,   1, {  22,  15, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs175_g2_s0_eff1_script },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x822b5b4 */
    &s_gs175_g0_s0_station_sref,
    &s_gs175_g1_s0_station_sref,
    &s_gs175_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs175_g0_sectors[] = { /* 0x822b5c0 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs175_g1_sectors[] = { /* 0x822b5e8 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs175_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs175_g2_sectors[] = { /* 0x822b610 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs175_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs175_groups[] = { /* 0x822b638 */
    { LPARRAY(s_gs175_g0_sectors) },
    { LPARRAY(s_gs175_g1_sectors) },
    { LPARRAY(s_gs175_g2_sectors) },
};

static const struct GroundLink s_gs175_links[] = { /* 0x822b650 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs175 = { LPARRAY(s_gs175_groups), s_gs175_links }; /* 0x822b658 */
