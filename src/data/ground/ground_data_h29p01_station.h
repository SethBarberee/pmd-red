




















static const struct ScriptCommand s_gs158_g0_s0_station_sref_script[] = { /* 0x820c898 */
    DEBUGINFO_O(23),
    SELECT_MAP(158),
    JUMPIF_SCENE_EQ(SCENARIO_SUB2, 34, 2, /* to label */ 0),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 3, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 3),
    JUMP_LABEL(4),
  LABEL(3), /* = 0x03 */
    JUMP_LABEL(4),
  LABEL(2), /* = 0x02 */
    SELECT_ENTITIES(1, 0),
    JUMP_LABEL(4),
  LABEL(0), /* = 0x00 */
    { 0x3b, 0x21,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 2),
    { 0x3b, 0x22,  0x0000,  0x00000000,  0x00000000, NULL },
    COND_EQUAL(0, /* to label */ 2),
    JUMP_SCRIPT(EVENT_S02E02A_L002),
  LABEL(4), /* = 0x04 */
    JUMPIF_EQUAL(START_MODE, 1, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 3, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 2, /* to label */ 7),
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 7),
    JUMP_LABEL(5),
  LABEL(7), /* = 0x07 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 8),
    JUMP_LABEL(8),
  LABEL(5), /* = 0x05 */
    SELECT_LIVES(0, 3),
    JUMP_LABEL(9),
  LABEL(6), /* = 0x06 */
    SELECT_LIVES(0, 4),
    JUMP_LABEL(9),
  LABEL(8), /* = 0x08 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(9),
  LABEL(9), /* = 0x09 */
    BGM_SWITCH(117),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs158_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs158_g0_s0_station_sref_script }; /* 0x820cb74 */

static const struct ScriptCommand s_gs158_g0_s1_lives0_dlg0[] = { /* 0x820cb80 */
    DEBUGINFO_O(71),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs158_g0_s1_lives1_dlg0[] = { /* 0x820cbc0 */
    DEBUGINFO_O(78),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs158_g0_s3_lives0_dlg0[] = { /* 0x820cc00 */
    DEBUGINFO_O(85),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs158_g0_s3_lives1_dlg0[] = { /* 0x820cc40 */
    DEBUGINFO_O(92),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs158_g0_s4_lives0_dlg0[] = { /* 0x820cc80 */
    DEBUGINFO_O(99),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs158_g0_s4_lives1_dlg0[] = { /* 0x820ccb0 */
    DEBUGINFO_O(105),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs158_g1_s0_lives0_dlg1[] = { /* 0x820cce0 */
    DEBUGINFO_O(111),
    CJUMP_UNK_C6(14),
    COND_EQUAL(144, /* to label */ 0),
    COND_EQUAL(145, /* to label */ 1),
    COND_EQUAL(146, /* to label */ 2),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    WARP_WAYPOINT(0, 0),
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
  LABEL(1), /* = 0x01 */
    WARP_WAYPOINT(0, 2),
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
  LABEL(2), /* = 0x02 */
    WARP_WAYPOINT(0, 4),
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs158_g1_s0_lives0_dlg2[] = { /* 0x820ce00 */
    DEBUGINFO_O(132),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs158_g1_s0_lives1_dlg1[] = { /* 0x820ce20 */
    DEBUGINFO_O(137),
    CJUMP_UNK_C6(15),
    COND_EQUAL(144, /* to label */ 0),
    COND_EQUAL(145, /* to label */ 1),
    COND_EQUAL(146, /* to label */ 2),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    WARP_WAYPOINT(0, 0),
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
  LABEL(1), /* = 0x01 */
    WARP_WAYPOINT(0, 2),
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
  LABEL(2), /* = 0x02 */
    WARP_WAYPOINT(0, 4),
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs158_g1_s0_lives1_dlg2[] = { /* 0x820cf40 */
    DEBUGINFO_O(158),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs158_g1_s0_lives2_dlg1[] = { /* 0x820cf60 */
    DEBUGINFO_O(163),
    CJUMP_UNK_C6(16),
    COND_EQUAL(144, /* to label */ 0),
    COND_EQUAL(145, /* to label */ 1),
    COND_EQUAL(146, /* to label */ 2),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    WARP_WAYPOINT(0, 0),
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
  LABEL(1), /* = 0x01 */
    WARP_WAYPOINT(0, 2),
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
  LABEL(2), /* = 0x02 */
    WARP_WAYPOINT(0, 4),
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs158_g1_s0_lives2_dlg2[] = { /* 0x820d080 */
    DEBUGINFO_O(184),
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs158_g2_s0_station_sref_script[] = { /* 0x820d0a0 */
    DEBUGINFO_O(189),
    SELECT_MAP(158),
    SELECT_ENTITIES(-1, -1),
    BGM_SWITCH(117),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    WAIT(60),
    BGM_FADEOUT(30),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    WAIT(120),
    RET,
};

static const struct ScriptRef s_gs158_g2_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs158_g2_s0_station_sref_script }; /* 0x820d150 */

static const struct ScriptCommand s_gs158_g2_s0_eff0_script[] = { /* 0x820d15c */
    DEBUGINFO_O(205),
    CAMERA_INIT_PAN,
    AWAIT_CUE(4),
    WARP_WAYPOINT(0, 10),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    WARP_WAYPOINT(0, 11),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    WARP_WAYPOINT(0, 12),
    ALERT_CUE(5),
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs158_g2_s0_lives0_dlg0[] = { /* 0x820d22c */
    DEBUGINFO_O(221),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00040000,  0x00000000, NULL },
    { 0x89, 0x30,  0x0100,  0x00000004,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ROTATE(8, 10, DIRECTION_WEST),
    WAIT(30),
    ROTATE(8, 10, DIRECTION_EAST),
    WAIT(30),
    ROTATE(8, 10, DIRECTION_NORTH),
    WAIT(60),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(4),
    AWAIT_CUE(5),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(8),
    AWAIT_CUE(5),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(4),
    AWAIT_CUE(5),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(7),
    AWAIT_CUE(5),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0x8b, 0x00,  0x0004,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(4),
    AWAIT_CUE(5),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(8),
    ALERT_CUE(7),
    AWAIT_CUE(5),
    WAIT(60),
    ALERT_CUE(8),
    AWAIT_CUE(5),
    { 0x28, 0x01,  0x0001,  0x00000005,  0x00ff1010, NULL },
    FANFARE_PLAY2(502),
    { 0x27, 0x01,  0x0001,  0x00000005,  0x00ff1010, NULL },
    ALERT_CUE(7),
    AWAIT_CUE(5),
    { 0x28, 0x01,  0x0001,  0x00000005,  0x00ffff10, NULL },
    FANFARE_PLAY2(502),
    { 0x27, 0x01,  0x0001,  0x00000005,  0x00ffff10, NULL },
    ALERT_CUE(6),
    AWAIT_CUE(5),
    FANFARE_PLAY2(506),
    { 0x28, 0x01,  0x0001,  0x00000005,  0x00ffffff, NULL },
    ALERT_CUE(6),
    ALERT_CUE(7),
    ALERT_CUE(8),
    ALERT_CUE(10),
    WAIT(60),
    { 0x27, 0x01,  0x0001,  0x0000003c,  0x00ffffff, NULL },
    ALERT_CUE(10),
    AWAIT_CUE(5),
    WAIT(60),
    WALK_GRID(256, 6),
    ALERT_CUE(7),
    ALERT_CUE(8),
    WAIT(60),
    PORTRAIT(PLACEMENT_TOP, 0x0001, 0x00000000),
    PORTRAIT(PLACEMENT_RIGHT, 0x0002, 0x00000000),
    PORTRAIT(PLACEMENT_LEFT_, 0x0003, 0x00000000),
    MSG_NPC(3, _(" Fire, ice, and electricity...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" When the three powers\nmerge as one...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" The guardian of the sea is\nsaid to arise.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Our arrival at the\n{COLOR GREEN_H}Legendary Island{RESET}...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" The three of us caused\nthe sea guardian to awaken.")),
    MSG_NPC(2, _(" It is what caused whirlpools\nto grow into tornadoes.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(1, _(" I have here the\n{COLOR GREEN}Vortex Stone{RESET}.")),
    MSG_NPC(1, _(" Bearing it, you will gain\npassage through the sea's tornadoes...")),
    MSG_NPC(1, _(" It will lead you to a place\ncalled the {COLOR YELLOW_D}Silver Trench{RESET}.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(2, _(" There, you will find the\nguardian of the sea.")),
    TEXTBOX_CLEAR,
    WAIT(10),
    MSG_NPC(3, _(" Now go.\nThe guardian of the sea awaits you.")),
    TEXTBOX_CLEAR,
    WAIT(30),
    WALK_RELATIVE(128, 0, -16),
    ALERT_CUE(10),
    WAIT(30),
    BGM_STOP,
    FANFARE_PLAY(212),
    MSG_INSTANT(_("{CENTER_ALIGN}Obtained the {COLOR GREEN}Vortex Stone{RESET}.")),
    { 0xe1, 0x00,  0x00d4,  0x00000000,  0x00000000, NULL },
    MSG_INSTANT(_("{CENTER_ALIGN}And...")),
    FANFARE_PLAY(205),
    MSG_INSTANT(_("{CENTER_ALIGN}Gained access to\n{CENTER_ALIGN}the {COLOR YELLOW_D}Silver Trench{RESET}!")),
    { 0xe1, 0x00,  0x00cd,  0x00000000,  0x00000000, NULL },
    TEXTBOX_CLEAR,
    ALERT_CUE(3),
    HALT,
};


static const struct ScriptCommand s_gs158_g2_s0_lives1_dlg0[] = { /* 0x820db5c */
    DEBUGINFO_O(332),
    SELECT_ANIMATION(2),
    { 0x59, 0x00, -0x0004,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x54, 0x00,  0x0400,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(497),
    SELECT_ANIMATION(18),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(6),
    SELECT_ANIMATION(2),
    { 0x8b, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x70, 0x00,  0x0080,  0x0000000a,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0100,  0x00000014,  0x00000000, NULL },
    { 0x70, 0x00,  0x0300,  0x00000064,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs158_g2_s0_lives2_dlg0[] = { /* 0x820dccc */
    DEBUGINFO_O(358),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(7),
    WAIT(60),
    { 0x54, 0x00,  0x0400,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0080,  0x0000000a,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0100,  0x00000014,  0x00000000, NULL },
    FANFARE_PLAY2(504),
    { 0x70, 0x00,  0x0300,  0x00000064,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(7),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    WARP_WAYPOINT(0, 7),
    { 0x8b, 0x04,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0100,  0x00000014,  0x00000000, NULL },
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0080,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ROTATE(4, 10, DIRECTION_WEST),
    AWAIT_CUE(7),
    { 0x54, 0x00,  0x0400,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(497),
    SELECT_ANIMATION(18),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(7),
    SELECT_ANIMATION(2),
    AWAIT_CUE(7),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    AWAIT_CUE(7),
    HALT,
};

static const struct ScriptCommand s_gs158_g2_s0_lives3_dlg0[] = { /* 0x820df0c */
    DEBUGINFO_O(397),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0003,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(8),
    WAIT(60),
    { 0x54, 0x00,  0x0400,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0080,  0x0000000a,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0100,  0x00000014,  0x00000000, NULL },
    FANFARE_PLAY2(504),
    { 0x70, 0x00,  0x0300,  0x00000064,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    WARP_WAYPOINT(0, 8),
    { 0x8b, 0x04,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0100,  0x00000014,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x01000000,  0x00000000, NULL },
    { 0x70, 0x00,  0x0080,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    ROTATE(4, 10, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(8),
    { 0x54, 0x00,  0x0400,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x54, 0x00,  0x0300,  0x00000000,  0x00000000, NULL },
    FANFARE_PLAY2(497),
    SELECT_ANIMATION(18),
    STOP_ANIMATION_ON_CURRENT_FRAME,
    ALERT_CUE(5),
    AWAIT_CUE(8),
    SELECT_ANIMATION(2),
    AWAIT_CUE(8),
    ROTATE(4, 10, DIRECTION_SOUTHEAST),
    AWAIT_CUE(8),
    HALT,
};

static const struct ScriptCommand s_gs158_g2_s0_eff1_script[] = { /* 0x820e14c */
    DEBUGINFO_O(436),
    { 0x59, 0x00, -0x0004,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    FANFARE_PLAY2(485),
    { 0x56, 0x00,  0x0000,  0x00000173,  0x00000000, NULL },
    AWAIT_CUE(10),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x00000174,  0x00000000, NULL },
    { 0xde, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x56, 0x00,  0x0000,  0x00000175,  0x00000000, NULL },
    { 0x52, 0x00,  0x0000,  0x00020000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(10),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(10),
    RET,
};

static const struct ScriptCommand s_gs158_g2_s0_lives4_dlg0[] = { /* 0x820e27c */
    DEBUGINFO_O(458),
    WAIT(4),
    CJUMP_UNK_C6(14),
    COND_EQUAL(144, /* to label */ 0),
    COND_EQUAL(145, /* to label */ 1),
    COND_EQUAL(146, /* to label */ 2),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    { 0x2d, 0x07,  0x0001,  0x0000000e,  0x00000000, NULL },
    END_DELETE,
  LABEL(1), /* = 0x01 */
    { 0x2d, 0x07,  0x0002,  0x0000000e,  0x00000000, NULL },
    END_DELETE,
  LABEL(2), /* = 0x02 */
    { 0x2d, 0x07,  0x0003,  0x0000000e,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs158_g2_s0_lives4_dlg1[] = { /* 0x820e37c */
    DEBUGINFO_O(477),
    CJUMP_UNK_C6(14),
    COND_EQUAL(144, /* to label */ 0),
    COND_EQUAL(145, /* to label */ 1),
    COND_EQUAL(146, /* to label */ 2),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    WARP_WAYPOINT(0, 0),
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
  LABEL(1), /* = 0x01 */
    WARP_WAYPOINT(0, 2),
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
  LABEL(2), /* = 0x02 */
    WARP_WAYPOINT(0, 4),
    { 0x51, 0x00,  0x0005,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs158_g2_s0_lives5_dlg0[] = { /* 0x820e49c */
    DEBUGINFO_O(498),
    WAIT(4),
    CJUMP_UNK_C6(15),
    COND_EQUAL(144, /* to label */ 0),
    COND_EQUAL(145, /* to label */ 1),
    COND_EQUAL(146, /* to label */ 2),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    { 0x2d, 0x07,  0x0001,  0x0000000f,  0x00000000, NULL },
    END_DELETE,
  LABEL(1), /* = 0x01 */
    { 0x2d, 0x07,  0x0002,  0x0000000f,  0x00000000, NULL },
    END_DELETE,
  LABEL(2), /* = 0x02 */
    { 0x2d, 0x07,  0x0003,  0x0000000f,  0x00000000, NULL },
    END_DELETE,
};

static const struct ScriptCommand s_gs158_g2_s0_lives6_dlg0[] = { /* 0x820e59c */
    DEBUGINFO_O(517),
    WAIT(4),
    CJUMP_UNK_C6(16),
    COND_EQUAL(144, /* to label */ 0),
    COND_EQUAL(145, /* to label */ 1),
    COND_EQUAL(146, /* to label */ 2),
    END_DELETE,
  LABEL(0), /* = 0x00 */
    { 0x2d, 0x07,  0x0001,  0x00000010,  0x00000000, NULL },
    END_DELETE,
  LABEL(1), /* = 0x01 */
    { 0x2d, 0x07,  0x0002,  0x00000010,  0x00000000, NULL },
    END_DELETE,
  LABEL(2), /* = 0x02 */
    { 0x2d, 0x07,  0x0003,  0x00000010,  0x00000000, NULL },
    END_DELETE,
};

static const struct GroundLivesData s_gs158_g0_s1_lives[] = { /* 0x820e69c */
    /*  0 */ {   0,   4,   0,   0, {  30,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs158_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs158_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs158_g0_s3_lives[] = { /* 0x820e6cc */
    /*  0 */ {   0,   4,   0,   0, {  30,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs158_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs158_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs158_g0_s4_lives[] = { /* 0x820e6fc */
    /*  0 */ {   0,   0,   0,   0, {  30,  26, 0, CPOS_HALFTILE }, {
        [0] = s_gs158_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  30,  29, 0, CPOS_HALFTILE }, {
        [0] = s_gs158_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs158_g1_s0_lives[] = { /* 0x820e72c */
    /*  0 */ {  14,   0,   0,   0, {  30,   4, 0, CPOS_HALFTILE }, {
        [1] = s_gs158_g1_s0_lives0_dlg1,
        [2] = s_gs158_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   7,   0,   0, {  50,   4, 0, CPOS_HALFTILE }, {
        [1] = s_gs158_g1_s0_lives1_dlg1,
        [2] = s_gs158_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   1,   0,   0, {  10,   4, 0, CPOS_HALFTILE }, {
        [1] = s_gs158_g1_s0_lives2_dlg1,
        [2] = s_gs158_g1_s0_lives2_dlg2,
    } },
};

static const struct GroundLivesData s_gs158_g2_s0_lives[] = { /* 0x820e774 */
    /*  0 */ {   0,   4,   0,   0, {  30,  32, 0, CPOS_HALFTILE }, {
        [0] = s_gs158_g2_s0_lives0_dlg0,
    } },
    /*  1 */ { 102,   0,   0,   0, {  30,  14, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs158_g2_s0_lives1_dlg0,
    } },
    /*  2 */ {  96,   7,   0,   0, {  49,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs158_g2_s0_lives2_dlg0,
    } },
    /*  3 */ { 101,   1,   0,   0, {   9,  21, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs158_g2_s0_lives3_dlg0,
    } },
    /*  4 */ {  14,   0,   0,   0, {  30,   0, 0, CPOS_HALFTILE }, {
        [0] = s_gs158_g2_s0_lives4_dlg0,
        [1] = s_gs158_g2_s0_lives4_dlg1,
    } },
    /*  5 */ {  15,   7,   0,   0, {  50,   0, 0, CPOS_HALFTILE }, {
        [0] = s_gs158_g2_s0_lives5_dlg0,
    } },
    /*  6 */ {  16,   1,   0,   0, {  10,   0, 0, CPOS_HALFTILE }, {
        [0] = s_gs158_g2_s0_lives6_dlg0,
    } },
};

static const struct GroundEffectData s_gs158_g2_s0_effs[] = { /* 0x820e81c */
    /*  0 */ {   0,   0,   1,   1, {  30,  25, 0, CPOS_HALFTILE }, s_gs158_g2_s0_eff0_script },
    /*  1 */ {   5,   0,   1,   1, {  30,  17, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs158_g2_s0_eff1_script },
};

static const struct GroundEventData s_gs158_g0_s0_evts[] = { /* 0x820e834 */
    /*  0 */ {  60,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  60,   1,   0,   0, {   0,  32, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   1,  33,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   1,  33,   0,   0, {  59,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x820e864 */
    &s_gs158_g0_s0_station_sref,
    &s_gs158_g2_s0_station_sref,
};

static const struct GroundScriptSector s_gs158_g0_sectors[] = { /* 0x820e86c */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs158_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs158_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs158_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs158_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs158_g1_sectors[] = { /* 0x820e934 */
    { LPARRAY(s_gs158_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs158_g2_sectors[] = { /* 0x820e95c */
    { LPARRAY(s_gs158_g2_s0_lives), 0,NULL, LPARRAY(s_gs158_g2_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs158_groups[] = { /* 0x820e984 */
    { LPARRAY(s_gs158_g0_sectors) },
    { LPARRAY(s_gs158_g1_sectors) },
    { LPARRAY(s_gs158_g2_sectors) },
};

static const struct GroundLink s_gs158_links[] = { /* 0x820e99c */
    /* link   0 */ { { /*x*/  30, /*y*/  16, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  27, /*y*/  14, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  50, /*y*/  21, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   3 */ { { /*x*/  47, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   4 */ { { /*x*/  10, /*y*/  21, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   5 */ { { /*x*/   7, /*y*/  19, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   6 */ { { /*x*/  30, /*y*/  20, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   7 */ { { /*x*/  35, /*y*/  16, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   8 */ { { /*x*/  24, /*y*/  16, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   9 */ { { /*x*/  30, /*y*/  16, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  10 */ { { /*x*/   9, /*y*/  21, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  11 */ { { /*x*/  49, /*y*/  21, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link  12 */ { { /*x*/  30, /*y*/  16, /*flags*/ 0, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs158 = { LPARRAY(s_gs158_groups), s_gs158_links }; /* 0x820ea04 */
