







static const struct ScriptCommand s_gs168_g0_s0_station_sref_script[] = { /* 0x821ba24 */
    DEBUGINFO_O(10),
    SELECT_MAP(168),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs168_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs168_g0_s0_station_sref_script }; /* 0x821ba90 */

static const struct ScriptCommand s_gs168_g1_s0_station_sref_script[] = { /* 0x821ba9c */
    DEBUGINFO_O(19),
    SELECT_MAP(168),
    SELECT_WEATHER(-1),
    SELECT_ENTITIES(-1, 0),
    BGM_FADEIN(120, 36),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs168_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs168_g1_s0_station_sref_script }; /* 0x821bb2c */

static const struct ScriptCommand s_gs168_g1_s0_eff0_script[] = { /* 0x821bb38 */
    DEBUGINFO_O(33),
    CAMERA_END_PAN,
    CAMERA_INIT_PAN,
    AWAIT_CUE(4),
    { 0x89, 0x50,  0x0100,  0x00000002,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    { 0x89, 0x50,  0x0100,  0x00000006,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(4),
    WAIT(1),
    END_DELETE,
};

static const struct ScriptCommand s_gs168_g1_s0_lives0_dlg0[] = { /* 0x821bbf8 */
    DEBUGINFO_O(48),
    SELECT_ANIMATION(5),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x3b, 0x36,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(80),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    { 0x3b, 0x36,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000002),
    MSG_NPC(1, _(" ...Brr... It's cold!{WAIT_PRESS}")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    WAIT(8),
    FANFARE_PLAY2(480),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000007),
    MSG_NPC(1, _(" Hachoo!")),
    TEXTBOX_CLEAR,
    WAIT(8),
    ROTATE(4, 1, DIRECTION_SOUTHWEST),
    WAIT(24),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    SELECT_ANIMATION(2),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000005),
    MSG_NPC(1, _(" Yuck...{WAIT_PRESS}\nMy nose is running, and it's freezing.")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ROTATE(4, 2, DIRECTION_EAST),
    { 0x3b, 0x36,  0x0004,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(5),
    ALERT_CUE(6),
    WAIT(60),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ..................")),
    VARIANT(/* == */  1, _(" This is one barren place...")),
    VARIANT(/* == */  1, _(" That snow's deep.")),
    VARIANT(/* == */  1, _(" There haven't been any\nPokémon around for a while, either.")),
    VARIANT(/* == */  1, _(" Maybe there isn't anyone\nelse out here but us.")),
    VARIANT_DEFAULT(_(" ..................")),
    VARIANT_DEFAULT(_(" Isn't this one lonely place?")),
    VARIANT_DEFAULT(_(" See how deep the snow is.")),
    VARIANT_DEFAULT(_(" I haven't seen any other\nPokémon for a while, either.")),
    VARIANT_DEFAULT(_(" Maybe we're all alone here.")),
    TEXTBOX_CLEAR,
    { 0x3b, 0x36,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    FANFARE_PLAY2(465),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Huh? What's up?")),
    VARIANT_DEFAULT(_(" Oh? What's the matter?")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    AWAIT_CUE(5),
    MSG_NPC(-1, _(" ........................")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_TOP_LEFT, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" Wh-what's that?!")),
    TEXTBOX_CLEAR,
    WAIT(40),
    ALERT_CUE(7),
    WAIT(90),
    ALERT_CUE(4),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000004),
    MSG_NPC(1, _(" ...{WAIT_PRESS}What was that?{WAIT_PRESS}\nIt looked like a Pokémon, but...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Was I seeing things?{WAIT_PRESS}\nNo, that can't be right.{WAIT_PRESS}\nI'm sure there was someone there...")),
    VARIANT_DEFAULT(_(" Did I imagine that?{WAIT_PRESS}\nNo, I don't think so.{WAIT_PRESS}\nI'm sure there was somebody there.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_NPC(1, _(" I wonder what they were\ndoing in this lonely place?")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Well, thinking about it\nisn't going to help.{WAIT_PRESS}\nLet's keep moving.")),
    VARIANT_DEFAULT(_(" I guess thinking about it\nwon't help us.{WAIT_PRESS}\nWe should keep moving.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    SELECT_ANIMATION(5),
    { 0x3b, 0x36,  0x0004,  0x00000000,  0x00000000, NULL },
    WAIT(64),
    ALERT_CUE(3),
    HALT,
};




static const struct ScriptCommand s_gs168_g1_s0_lives1_dlg0[] = { /* 0x821c620 */
    DEBUGINFO_O(155),
    SELECT_ANIMATION(5),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    SELECT_ANIMATION(2),
    { 0x62, 0x00,  0x0100, -0x00000018,  0x00000000, NULL },
    SELECT_ANIMATION(9),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x54, 0x00,  0x002f,  0x00000000,  0x00000000, NULL },
    WAIT(4),
    { 0x56, 0x00,  0x0000,  0x0000005b,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_EAST),
    SELECT_ANIMATION(5),
    AWAIT_CUE(6),
    SELECT_ANIMATION(2),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_EAST),
    { 0x56, 0x00,  0x0000,  0x00000058,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x0c,  0x0100,  0x00000002,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_EAST),
    ALERT_CUE(5),
    SELECT_ANIMATION(5),
    HALT,
};

static const struct ScriptCommand s_gs168_g1_s0_lives2_dlg0[] = { /* 0x821c8e0 */
    DEBUGINFO_O(202),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    ROTATE(4, 2, DIRECTION_EAST),
    SELECT_ANIMATION(32),
    WAIT(9),
    FANFARE_PLAY2(478),
    { 0x89, 0x50,  0x0400,  0x00000002,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs168_g2_s0_station_sref_script[] = { /* 0x821c980 */
    DEBUGINFO_O(215),
    SELECT_MAP(168),
    SELECT_WEATHER(-1),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(36),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    { 0x23, 0x01,  0x003c,  0x00000000,  0x00000000, NULL },
    RET,
};

static const struct ScriptRef s_gs168_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs168_g2_s0_station_sref_script }; /* 0x821ca10 */

static const struct ScriptCommand s_gs168_g2_s0_lives0_dlg0[] = { /* 0x821ca1c */
    DEBUGINFO_O(229),
    SELECT_ANIMATION(5),
    { 0x3b, 0x36,  0x0004,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    { 0x3b, 0x36,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x0000000b),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Wow!")),
    VARIANT_DEFAULT(_(" Oh!")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ROTATE(4, 1, DIRECTION_SOUTHEAST),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}!\nCheck that out!")),
    VARIANT_DEFAULT(_(" {NAME_0}! Look!")),
    ROTATE(4, 2, DIRECTION_EAST),
    ALERT_CUE(6),
    MSG_NPC(1, _(" See that?{WAIT_PRESS}\nThose trees are frozen!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs168_g2_s0_lives1_dlg0[] = { /* 0x821cc58 */
    DEBUGINFO_O(263),
    SELECT_ANIMATION(5),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x56, 0x00,  0x0000,  0x00000058,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    SELECT_ANIMATION(2),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHWEST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_EAST),
    AWAIT_CUE(6),
    HALT,
};

static const struct GroundLivesData s_gs168_g1_s0_lives[] = { /* 0x821cd58 */
    /*  0 */ {   0,   2,   0,   0, {  64,  23, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs168_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  64,  25, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs168_g1_s0_lives1_dlg0,
    } },
    /*  2 */ {  83,   6,   0,   0, {  82,  22, 0, CPOS_HALFTILE }, {
        [0] = s_gs168_g1_s0_lives2_dlg0,
    } },
};

static const struct GroundLivesData s_gs168_g2_s0_lives[] = { /* 0x821cda0 */
    /*  0 */ {   0,   2,   0,   0, {  78,  23, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs168_g2_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  81,  25, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs168_g2_s0_lives1_dlg0,
    } },
};

static const struct GroundEffectData s_gs168_g1_s0_effs[] = { /* 0x821cdd0 */
    /*  0 */ {   0,   0,   1,   1, {  64,  24, 0, CPOS_HALFTILE }, s_gs168_g1_s0_eff0_script },
};

static const struct GroundEffectData s_gs168_g2_s0_effs[] = { /* 0x821cddc */
    /*  0 */ {   0,   0,   1,   1, {  79,  24, 0, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x821cde8 */
    &s_gs168_g0_s0_station_sref,
    &s_gs168_g1_s0_station_sref,
    &s_gs168_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs168_g0_sectors[] = { /* 0x821cdf4 */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs168_g1_sectors[] = { /* 0x821ce1c */
    { LPARRAY(s_gs168_g1_s0_lives), 0,NULL, LPARRAY(s_gs168_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs168_g2_sectors[] = { /* 0x821ce44 */
    { LPARRAY(s_gs168_g2_s0_lives), 0,NULL, LPARRAY(s_gs168_g2_s0_effs), 0,NULL, 1,&sStationScripts[2], },
};

static const struct GroundScriptGroup s_gs168_groups[] = { /* 0x821ce6c */
    { LPARRAY(s_gs168_g0_sectors) },
    { LPARRAY(s_gs168_g1_sectors) },
    { LPARRAY(s_gs168_g2_sectors) },
};

static const struct GroundLink s_gs168_links[] = { /* 0x821ce84 */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs168 = { LPARRAY(s_gs168_groups), s_gs168_links }; /* 0x821ce8c */
