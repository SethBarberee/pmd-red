









static const struct ScriptCommand s_gs201_g0_s0_station_sref_script[] = { /* 0x8251f44 */
    DEBUGINFO_O(12),
    JUMPIF_SCENARIOCHECK(5, /* to label */ 0),
    EXECUTE_STATION(12, 0, 0),
  LABEL(0), /* = 0x00 */
    SELECT_MAP(MAP_MT_FREEZE_ENTRY),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 14, /* to label */ 1),
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    { 0x3b, 0x1c,  0x0000,  0x00000000,  0x00000000, NULL },
    CALL_STATION(  2,  0),
    JUMP_LABEL(2),
  LABEL(2), /* = 0x02 */
    JUMPIF_EQUAL(START_MODE, 1, /* to label */ 3),
    JUMPIF_EQUAL(START_MODE, 3, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, 2, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 10, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 12, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 11, /* to label */ 6),
    JUMP_LABEL(3),
  LABEL(5), /* = 0x05 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 7),
    JUMP_LABEL(7),
  LABEL(3), /* = 0x03 */
    SELECT_LIVES(0, 3),
    JUMP_LABEL(8),
  LABEL(4), /* = 0x04 */
    SELECT_LIVES(0, 4),
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(8),
  LABEL(6), /* = 0x06 */
    SELECT_LIVES(0, 2),
    JUMP_LABEL(8),
  LABEL(8), /* = 0x08 */
    BGM_SWITCH(36),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs201_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs201_g0_s0_station_sref_script }; /* 0x8252210 */

static const struct ScriptCommand s_gs201_g0_s0_obj0_dlg2[] = { /* 0x825221c */
    DEBUGINFO_O(59),
    JUMP_SCRIPT(SAVE_AND_WAREHOUSE_POINT),
};

static const struct ScriptCommand s_gs201_g0_s1_lives0_dlg0[] = { /* 0x825223c */
    DEBUGINFO_O(64),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs201_g0_s1_lives1_dlg0[] = { /* 0x825227c */
    DEBUGINFO_O(71),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs201_g0_s2_lives0_dlg0[] = { /* 0x82522bc */
    DEBUGINFO_O(78),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs201_g0_s2_lives1_dlg0[] = { /* 0x82522fc */
    DEBUGINFO_O(85),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs201_g0_s3_lives0_dlg0[] = { /* 0x825233c */
    DEBUGINFO_O(92),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs201_g0_s3_lives1_dlg0[] = { /* 0x825237c */
    DEBUGINFO_O(99),
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs201_g0_s4_lives0_dlg0[] = { /* 0x82523bc */
    DEBUGINFO_O(106),
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs201_g0_s4_lives1_dlg0[] = { /* 0x82523ec */
    DEBUGINFO_O(112),
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs201_g0_s5_obj0_dlg2[] = { /* 0x825241c */
    DEBUGINFO_O(118),
    JUMP_SCRIPT(WAREHOUSE_POINT),
};

static const struct ScriptCommand s_gs201_g0_s5_obj1_dlg2[] = { /* 0x825243c */
    DEBUGINFO_O(123),
    JUMP_SCRIPT(SAVE_POINT),
};

static const struct ScriptCommand s_gs201_g1_s0_station_sref_script[] = { /* 0x825245c */
    DEBUGINFO_O(128),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_MT_FREEZE_ENTRY),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_MT_FREEZE_ENTRY),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    { 0x3b, 0x1c,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(MAP_MT_FREEZE_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(36),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs201_g1_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs201_g1_s0_station_sref_script }; /* 0x825253c */

static const struct ScriptCommand s_gs201_g1_s0_lives0_dlg0[] = { /* 0x8252548 */
    DEBUGINFO_O(147),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0002,  0x00000052,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0003,  0x00000063,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(30),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ...OK.\nSo that's what happened...")),
    VARIANT(/* == */  1, _(" {NAME_2} appeared to\nyou...")),
    VARIANT(/* == */  1, _(" So that's why you were\nlooking so stunned.")),
    VARIANT_DEFAULT(_(" ...Oh.\nSo something like that happened.")),
    VARIANT_DEFAULT(_(" {NAME_2} appeared to\nyou...")),
    VARIANT_DEFAULT(_(" That's why you were\nlooking so stunned earlier.")),
    TEXTBOX_CLEAR,
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But, wow...\n{NAME_3} isn't just a legend.\nIt really exists...")),
    VARIANT_DEFAULT(_(" I'm amazed, though...\n{NAME_3} isn't just a legend.\nIt really exists...")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" And that {NAME_3} is\nat the peak way up there.")),
    VARIANT_DEFAULT(_(" And that {NAME_3} is up\nat the peak...")),
    TEXTBOX_CLEAR,
    WAIT(10),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000008),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Sniffle...{WAIT_PRESS}\n{NAME_0}!")),
    VARIANT(/* == */  1, _(" All the effort we put into\ngetting here...\nIt's finally going to pay off!")),
    VARIANT(/* == */  1, _(" We'll meet {NAME_3}\nand get the truth!")),
    VARIANT_DEFAULT(_(" Sniffle...{WAIT_PRESS}\n{NAME_0}!")),
    VARIANT_DEFAULT(_(" All the effort we put into\ngetting here...\nIt's finally going to bear fruit!")),
    VARIANT_DEFAULT(_(" We'll meet {NAME_3}\nand get the truth!")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0001, 0x00000001),
    ASK3_VAR(FALSE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" We'll finally clear your\nreputation, {NAME_0}!{WAIT_PRESS}\nThat'll be great!")),
    VARIANT_DEFAULT(_(" We'll finally get rid of the\nsuspicions others have about you,\n{NAME_0}!{WAIT_PRESS} Awesome!")),
    CHOICE(/* label */  2, _("........................")),
    CHOICE(/* label */  2, _("........................")),
  LABEL(2), /* = 0x02 */
    TEXTBOX_CLEAR,
    WAIT(30),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Hey, {NAME_0}...")),
    VARIANT(/* == */  1, _(" You don't need to look so\nworried.{WAIT_PRESS}\nIt'll be OK.")),
    VARIANT(/* == */  1, _(" {NAME_0}, I can\nunderstand how it'd be scary for you to\nmeet {NAME_3}.")),
    VARIANT(/* == */  1, _(" The heartless human who\nabandoned {NAME_2}...{WAIT_PRESS}\nHow that might be you...")),
    VARIANT(/* == */  1, _(" I bet you're scared,\nthinking that.")),
    VARIANT_DEFAULT(_(" Listen, {NAME_0}...")),
    VARIANT_DEFAULT(_(" ...Don't be so worried.{WAIT_PRESS}\nIt will be all right.")),
    VARIANT_DEFAULT(_(" It's only natural that you\nwould be scared of meeting {NAME_3},\n{NAME_0}.")),
    VARIANT_DEFAULT(_(" The heartless human who\nabandoned {NAME_2}...{WAIT_PRESS}\nIt may be you...")),
    VARIANT_DEFAULT(_(" I can understand how\nyou could think that.")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0001, 0x00000000),
    ASK3(FALSE, /*default*/ -1, /* speaker */ 1, _(" But that's impossible.\nYou're not that human--I'm sure.")),
    CHOICE(/* label */  4, _("How can you say that?")),
    CHOICE(/* label */  4, _("You believe so much in me?")),
  LABEL(4), /* = 0x04 */
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" Hmm...?{WAIT_PRESS} Well, there was\na time when I had some doubts...{WAIT_PRESS}\nBut now...")),
    ALERT_CUE(6),
    PORTRAIT_REP(0x0001, 0x00000004),
    MSG_NPC(1, _(" ...I wonder why?{WAIT_PRESS}\nI really don't know why.")),
    TEXTBOX_CLEAR,
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" But it doesn't matter now.{WAIT_PRESS}\n{NAME_0}, you're a really good sort.")),
    VARIANT(/* == */  1, _(" You know, before...")),
    VARIANT(/* == */  1, _(" When I first got the idea\nto start this rescue team...")),
    VARIANT(/* == */  1, _(" I met you in the Tiny\nWoods, {NAME_0}.")),
    VARIANT(/* == */  1, _(" Now that I think about it,\nthere was something different about you.\nJust a feeling.")),
    VARIANT(/* == */  3, _(" But it doesn't matter.\nI know you're a good sort, {NAME_0}...")),
    VARIANT(/* == */  3, _(" Do you remember...?")),
    VARIANT(/* == */  3, _(" When I first got the idea to\nstart a rescue team...")),
    VARIANT(/* == */  3, _(" I met you in the Tiny\nWoods, {NAME_0}...")),
    VARIANT(/* == */  3, _(" Even back then, I sensed\nthere was something different about you.")),
    VARIANT_DEFAULT(_(" But it's all right.{WAIT_PRESS}\n{NAME_0}, you're a really good sort.")),
    VARIANT_DEFAULT(_(" You know, before...")),
    VARIANT_DEFAULT(_(" When I first got the idea\nto start a rescue team...")),
    VARIANT_DEFAULT(_(" I met you in the Tiny\nWoods, {NAME_0}.")),
    VARIANT_DEFAULT(_(" Now that I think about it,\nthere was something different about you.")),
    PORTRAIT_REP(0x0001, 0x00000001),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is kind of weird,\nisn't it?{WAIT_PRESS}\nBut I believe in you, {NAME_0}.")),
    VARIANT(/* == */  3, _(" It is weird, isn't it?{WAIT_PRESS}\nBut I believe in you, {NAME_0}.")),
    VARIANT_DEFAULT(_(" It is strange, isn't it?{WAIT_PRESS}\nBut, {NAME_0}, I believe in you.")),
    TEXTBOX_CLEAR,
    WAIT(30),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_NPC(1, _(" Anyway, we'll know the\ntruth when we get to the peak.")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" {NAME_0}, let's give it\nour best!")),
    VARIANT_DEFAULT(_(" {NAME_0}, let's do our\nbest!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    SELECT_ANIMATION(5),
    ALERT_CUE(3),
    RET,
};





static const struct ScriptCommand s_gs201_g1_s0_lives1_dlg0[] = { /* 0x825366c */
    DEBUGINFO_O(264),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    { 0x56, 0x00,  0x0000,  0x0000005d,  0x00000000, NULL },
    WAIT(100),
    { 0x56, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_EAST),
    CALL_SCRIPT(JUMP_ANGRY_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    FANFARE_PLAY2(469),
    CALL_SCRIPT(QUESTION_FUNC),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_NORTHEAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 1, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs201_g2_s0_station_sref_script[] = { /* 0x825380c */
    DEBUGINFO_O(293),
    SELECT_ENTITIES(-1, -1),
    RET_DIRECT,
};

static const struct ScriptRef s_gs201_g2_s0_station_sref = { 403, 8, NULL /* STATION_CONTROL */, s_gs201_g2_s0_station_sref_script }; /* 0x825383c */

static const struct ScriptCommand s_gs201_g2_s0_lives0_dlg2[] = { /* 0x8253848 */
    DEBUGINFO_O(301),
    EXECUTE_STATION(-1, 2, 1),
    HALT,
};

static const struct ScriptCommand s_gs201_g2_s0_evt0_sref_script[] = { /* 0x8253878 */
    DEBUGINFO_O(307),
    EXECUTE_STATION(-1, 2, 1),
    HALT,
};

static const struct ScriptRef s_gs201_g2_s0_evt0_sref = { 357, 2, NULL /* GETOUT_NORMAL */, s_gs201_g2_s0_evt0_sref_script }; /* 0x82538a8 */

static const struct ScriptCommand s_gs201_g2_s1_station_sref_script[] = { /* 0x82538b4 */
    DEBUGINFO_O(315),
    SELECT_ENTITIES(-1, 1),
    CANCEL_ENTITIES(-1, 0),
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs201_g2_s1_station_sref = { 401, 7, NULL /* EVENT_WAKEUP */, s_gs201_g2_s1_station_sref_script }; /* 0x8253904 */

static const struct ScriptCommand s_gs201_g2_s1_lives0_dlg0[] = { /* 0x8253910 */
    DEBUGINFO_O(325),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(1),
    { 0x8e, 0x01,  0x0000,  0x00000022,  0x00000000, NULL },
    ASK3_VAR( TRUE, /*default*/ -1, /* speaker */ 1, PARTNER_TALK_KIND),
    VARIANT(/* == */  1, _(" Hey, {NAME_0}.\nAre you all ready?")),
    VARIANT_DEFAULT(_(" Hi, {NAME_0}.\nAre you ready?")),
    CHOICE(/* label */  2, _("All set!")),
    CHOICE(/* label */  3, _("Not yet.")),
  LABEL(3), /* = 0x03 */
    MSG_NPC(1, _(" Hmm? Is that so?")),
    MSG_NPC(1, _(" OK.\nLet's go when you're ready.")),
    TEXTBOX_CLEAR,
    SELECT_ENTITIES(-1, 0),
    JUMP_SCRIPT(END_TALK),
  LABEL(2), /* = 0x02 */
    ASK3( TRUE, /*default*/ 0, /* speaker */ 1, _(" Which way should we go?")),
    CHOICE(/* label */  5, _("Mt. Freeze.")),
    CHOICE(/* label */  6, _("Snow Path.")),
    JUMP_LABEL(3),
  LABEL(5), /* = 0x05 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right!\nLet's roll out!")),
    VARIANT(/* == */  1, _(" We want the peak.\nLet's give it our best!")),
    VARIANT_DEFAULT(_(" OK!\nLet's go!")),
    VARIANT_DEFAULT(_(" Let's do our best to reach\nthe peak!")),
    TEXTBOX_CLEAR,
    CJUMP_UNK_C8(34),
    COND_EQUAL(4, /* to label */ 7),
    COND_EQUAL(3, /* to label */ 7),
    COND_EQUAL(5, /* to label */ 7),
    COND_EQUAL(2, /* to label */ 7),
    ALERT_CUE(6),
    BGM_FADEOUT(120),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    CAMERA_PAN(256, 0),
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    ALERT_CUE(6),
    BGM_FADEOUT(120),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    CAMERA_PAN(256, 0),
  LABEL(8), /* = 0x08 */
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x07, 0x00,  0x001e,  0x0000000f,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 3),
    HALT,
  LABEL(6), /* = 0x06 */
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" All right!\nLet's roll out!")),
    VARIANT_DEFAULT(_(" OK!\nLet's go!")),
    TEXTBOX_CLEAR,
    CJUMP_UNK_C8(34),
    COND_EQUAL(4, /* to label */ 9),
    COND_EQUAL(3, /* to label */ 9),
    COND_EQUAL(5, /* to label */ 9),
    COND_EQUAL(2, /* to label */ 9),
    ALERT_CUE(6),
    BGM_FADEOUT(120),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    CAMERA_PAN(256, 0),
    JUMP_LABEL(10),
  LABEL(9), /* = 0x09 */
    ALERT_CUE(6),
    BGM_FADEOUT(120),
    { 0x23, 0x00,  0x0050,  0x00000000,  0x00000000, NULL },
    WAIT(15),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    CAMERA_PAN(256, 0),
  LABEL(10), /* = 0x0a */
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x06, 0x00,  0x001e,  0x0000004f,  0x00000000, NULL },
    COND_EQUAL(-1, /* to label */ 3),
    HALT,
};




static const struct ScriptCommand s_gs201_g2_s1_lives1_dlg0[] = { /* 0x8253f50 */
    DEBUGINFO_O(410),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x00000400,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x8e, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    CJUMP_UNK_C8(0),
    COND_EQUAL(0, /* to label */ 0),
    COND_EQUAL(1, /* to label */ 0),
    COND_EQUAL(7, /* to label */ 0),
    COND_EQUAL(6, /* to label */ 0),
    WAIT(15),
    SELECT_ANIMATION(5),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    CAMERA_PAN(256, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
  LABEL(0), /* = 0x00 */
    SELECT_ANIMATION(5),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    CAMERA_PAN(256, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct ScriptCommand s_gs201_g3_s0_station_sref_script[] = { /* 0x82540c0 */
    DEBUGINFO_O(436),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_MT_FREEZE_ENTRY),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_MT_FREEZE_ENTRY),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    { 0x3b, 0x1c,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(MAP_MT_FREEZE_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(36),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs201_g3_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs201_g3_s0_station_sref_script }; /* 0x82541a0 */

static const struct ScriptCommand s_gs201_g3_s0_lives0_dlg0[] = { /* 0x82541ac */
    DEBUGINFO_O(455),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000002),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Darn...{WAIT_PRESS}\nThat didn't go well.")),
    VARIANT_DEFAULT(_(" Ouch...{WAIT_PRESS}\nThat turned out badly.")),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is one seriously\nrough neighborhood...")),
    VARIANT(/* == */  1, _(" But let's storm our way\nto the peak, {NAME_0}!")),
    VARIANT_DEFAULT(_(" This is a seriously tough\nchallenge, but...")),
    VARIANT_DEFAULT(_(" Let's be sure to reach the\npeak, {NAME_0}!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};


static const struct ScriptCommand s_gs201_g3_s0_lives1_dlg0[] = { /* 0x8254430 */
    DEBUGINFO_O(483),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    ROTATE(4, 2, DIRECTION_EAST),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs201_g4_s0_station_sref_script[] = { /* 0x8254500 */
    DEBUGINFO_O(499),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_MT_FREEZE_ENTRY),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_MT_FREEZE_ENTRY),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    { 0x3b, 0x1c,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(MAP_MT_FREEZE_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(36),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs201_g4_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs201_g4_s0_station_sref_script }; /* 0x82545e0 */

static const struct ScriptCommand s_gs201_g4_s0_lives0_dlg0[] = { /* 0x82545ec */
    DEBUGINFO_O(518),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x30,  0x0080,  0x00000007,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(20),
    FANFARE_PLAY2(465),
    ALERT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x0000000c),
    MSG_NPC(1, _(" What the...?{WAIT_PRESS}\nIsn't this where we started from?!")),
    TEXTBOX_CLEAR,
    FANFARE_PLAY2(468),
    ALERT_CUE(6),
    WAIT(15),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" ............{WAIT_PRESS}\nI guess that path just loops back to the\nstart.")),
    VARIANT(/* == */  1, _(" If we want to move on,\nI think our only choice is {COLOR YELLOW_D}Mt. Freeze{RESET}.")),
    VARIANT(/* == */  1, _(" {NAME_0}, let's give it\nour best!")),
    VARIANT_DEFAULT(_(" ............{WAIT_PRESS}\nI guess that path we took just loops back\nto where it started.")),
    VARIANT_DEFAULT(_(" It looks like we have to get\nover {COLOR YELLOW_D}Mt. Freeze{RESET} to move on.")),
    VARIANT_DEFAULT(_(" {NAME_0}, let's do our\nbest!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};

static const struct ScriptCommand s_gs201_g4_s0_lives1_dlg0[] = { /* 0x825492c */
    DEBUGINFO_O(552),
    SELECT_ANIMATION(2),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    { 0x89, 0x20,  0x0080,  0x00000007,  0x00000000, NULL },
    AWAIT_CUE(6),
    CALL_SCRIPT(NOTICE_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x0002,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs201_g5_s0_station_sref_script[] = { /* 0x8254a0c */
    DEBUGINFO_O(569),
    SET_DUNGEON_RES(/* result */ 0, /* enter */ -1),
    UPDATE_VARINT(CALC_SET, GROUND_ENTER, MAP_MT_FREEZE_ENTRY),
    UPDATE_VARINT(CALC_SET, GROUND_GETOUT, MAP_MT_FREEZE_ENTRY),
    UPDATE_VARINT(CALC_SET, PARTNER1_KIND, 0),
    UPDATE_VARINT(CALC_SET, PARTNER2_KIND, 0),
    { 0x3b, 0x1c,  0x0000,  0x00000000,  0x00000000, NULL },
    SELECT_MAP(MAP_MT_FREEZE_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(36),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    CALL_STATION(  2,  0),
    RET,
};

static const struct ScriptRef s_gs201_g5_s0_station_sref = { 402, 7, NULL /* EVENT_STATION */, s_gs201_g5_s0_station_sref_script }; /* 0x8254aec */

static const struct ScriptCommand s_gs201_g5_s0_lives0_dlg0[] = { /* 0x8254af8 */
    DEBUGINFO_O(588),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    { 0xdf, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(6),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_LEFT_FUNC),
    AWAIT_CUE(5),
    PORTRAIT(PLACEMENT_LEFT_, 0x0001, 0x00000002),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" Urrggh...{WAIT_PRESS}\nWe couldn't get through...")),
    VARIANT_DEFAULT(_(" Ouch...{WAIT_PRESS}\nWe couldn't break through...")),
    TEXTBOX_CLEAR,
    WAIT(15),
    ALERT_CUE(6),
    AWAIT_CUE(5),
    PORTRAIT_REP(0x0001, 0x00000000),
    MSG_VAR(2, PARTNER_TALK_KIND, 1),
    VARIANT(/* == */  1, _(" This is one harsh place,\nbut let's bear down and get through,\n{NAME_0}!")),
    VARIANT_DEFAULT(_(" This is a harsh place,\nso let's do our best to get through,\n{NAME_0}!")),
    TEXTBOX_CLEAR,
    { 0x9b, 0x00,  0x0100,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(3),
    RET,
};

static const struct ScriptCommand s_gs201_g5_s0_lives1_dlg0[] = { /* 0x8254d64 */
    DEBUGINFO_O(615),
    CALL_SCRIPT(INIT_SLEEP_FUNC),
    { 0x2d, 0x07,  0x0001,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(6),
    WAIT(15),
    CALL_SCRIPT(WAKEUP_FUNC),
    CALL_SCRIPT(LOOK_AROUND_FUNC),
    ALERT_CUE(5),
    AWAIT_CUE(6),
    { 0x93, 0x04,  0x000a,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(5),
    AWAIT_CUE(6),
    HALT,
};

static const struct ScriptCommand s_gs201_g6_s0_station_sref_script[] = { /* 0x8254e34 */
    DEBUGINFO_O(631),
    SELECT_MAP(MAP_MT_FREEZE_ENTRY),
    SELECT_ENTITIES(-1, 0),
    BGM_SWITCH(115),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(3),
    RET,
};

static const struct ScriptRef s_gs201_g6_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs201_g6_s0_station_sref_script }; /* 0x8254ea4 */

static const struct ScriptCommand s_gs201_g6_s0_eff0_script[] = { /* 0x8254eb0 */
    DEBUGINFO_O(643),
    CAMERA_END_PAN,
    WAIT(1),
    AWAIT_CUE(4),
    WAIT(30),
    { 0x23, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    AWAIT_CUE(4),
    END_DELETE,
};

static const struct ScriptCommand s_gs201_g6_s0_lives0_dlg0[] = { /* 0x8254f30 */
    DEBUGINFO_O(654),
    SELECT_ANIMATION(2),
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    { 0x2d, 0x07,  0x0000,  0x00000000,  0x00000000, NULL },
    ALERT_CUE(7),
    { 0x89, 0x40,  0x0080,  0x00000003,  0x00000000, NULL },
    AWAIT_CUE(5),
    ROTATE(4, 10, DIRECTION_SOUTHWEST),
    MSG_NPC(2, _(" You're going to {COLOR YELLOW_D}Mt. Freeze{RESET}?")),
    MSG_NPC(2, _(" Don't forget to take me,\nkekeh!")),
    TEXTBOX_CLEAR,
    ALERT_CUE(4),
    ALERT_CUE(7),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    WALK_GRID(128, 0),
    ALERT_CUE(3),
    HALT,
};

static const struct ScriptCommand s_gs201_g6_s0_lives1_dlg0[] = { /* 0x825508c */
    DEBUGINFO_O(674),
    { 0x2d, 0x07,  0x0002,  0x00000000,  0x00000000, NULL },
    { 0x53, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    SELECT_ANIMATION(2),
    CAMERA_PAN(256, 1),
    ROTATE(4, 10, DIRECTION_NORTHEAST),
    ALERT_CUE(5),
    AWAIT_CUE(7),
    WAIT(15),
    WALK_GRID(128, 0),
    { 0x52, 0x00,  0x0000,  0x0000001f,  0x00000000, NULL },
    HALT,
};

static const struct GroundLivesData s_gs201_g0_s0_lives[] = { /* 0x825514c */
    /*  0 */ { 144,   0,   0,   0, {  10,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs201_g0_s1_lives[] = { /* 0x8255164 */
    /*  0 */ {   0,   4,   0,   0, {  16,  29, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs201_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  16,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs201_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs201_g0_s2_lives[] = { /* 0x8255194 */
    /*  0 */ {   0,   0,   0,   0, {  27,  22, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs201_g0_s2_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  27,  20, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs201_g0_s2_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs201_g0_s3_lives[] = { /* 0x82551c4 */
    /*  0 */ {   0,   4,   0,   0, {  16,  29, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs201_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  16,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs201_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs201_g0_s4_lives[] = { /* 0x82551f4 */
    /*  0 */ {   0,   4,   0,   0, {  16,  29, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs201_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  16,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs201_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs201_g0_s5_lives[] = { /* 0x8255224 */
    /*  0 */ { 144,   0,   0,   0, {  10,  18, CPOS_HALFTILE, CPOS_HALFTILE }, {} },
    /*  1 */ { 145,   0,   0,   0, {  25,  30, 0, CPOS_HALFTILE }, {} },
};

static const struct GroundLivesData s_gs201_g1_s0_lives[] = { /* 0x8255254 */
    /*  0 */ {   0,   6,   0,   0, {  21,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs201_g1_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   2,   0,   0, {  16,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs201_g1_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs201_g2_s0_lives[] = { /* 0x8255284 */
    /*  0 */ {  34,   0,   0,   0, {  16,  24, 0, CPOS_HALFTILE }, {
        [2] = s_gs201_g2_s0_lives0_dlg2,
    } },
};

static const struct GroundLivesData s_gs201_g2_s1_lives[] = { /* 0x825529c */
    /*  0 */ {   0,   0,   0,   0, {  21,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs201_g2_s1_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  16,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs201_g2_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs201_g3_s0_lives[] = { /* 0x82552cc */
    /*  0 */ {   0,   0,   0,   0, {  21,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs201_g3_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  16,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs201_g3_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs201_g4_s0_lives[] = { /* 0x82552fc */
    /*  0 */ {   0,   0,   0,   0, {  24,  21, 0, CPOS_HALFTILE }, {
        [0] = s_gs201_g4_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  18,  22, 0, CPOS_HALFTILE }, {
        [0] = s_gs201_g4_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs201_g5_s0_lives[] = { /* 0x825532c */
    /*  0 */ {   0,   0,   0,   0, {  21,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs201_g5_s0_lives0_dlg0,
    } },
    /*  1 */ {  34,   0,   0,   0, {  16,  24, 0, CPOS_HALFTILE }, {
        [0] = s_gs201_g5_s0_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs201_g6_s0_lives[] = { /* 0x825535c */
    /*  0 */ {   0,   4,   0,   0, {  21,  27, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs201_g6_s0_lives0_dlg0,
    } },
    /*  1 */ {  91,   4,   0,   0, {  16,  31, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs201_g6_s0_lives1_dlg0,
    } },
};

static const struct GroundObjectData s_gs201_g0_s0_objs[] = { /* 0x825538c */
    /*  0 */ {   4,   0,   5,   2, {  10,  19, CPOS_HALFTILE, 0 }, {
        [2] = s_gs201_g0_s0_obj0_dlg2,
    } },
};

static const struct GroundObjectData s_gs201_g0_s5_objs[] = { /* 0x82553a4 */
    /*  0 */ {   4,   0,   5,   2, {  10,  19, CPOS_HALFTILE, 0 }, {
        [2] = s_gs201_g0_s5_obj0_dlg2,
    } },
    /*  1 */ {   4,   0,   4,   3, {  25,  30, 0, CPOS_HALFTILE }, {
        [2] = s_gs201_g0_s5_obj1_dlg2,
    } },
};

static const struct GroundEffectData s_gs201_g1_s0_effs[] = { /* 0x82553d4 */
    /*  0 */ {   0,   0,   1,   1, {  19,  22, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs201_g3_s0_effs[] = { /* 0x82553e0 */
    /*  0 */ {   0,   0,   1,   1, {  19,  22, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs201_g4_s0_effs[] = { /* 0x82553ec */
    /*  0 */ {   0,   0,   1,   1, {  19,  22, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs201_g5_s0_effs[] = { /* 0x82553f8 */
    /*  0 */ {   0,   0,   1,   1, {  19,  22, 0, CPOS_HALFTILE }, NULL },
};

static const struct GroundEffectData s_gs201_g6_s0_effs[] = { /* 0x8255404 */
    /*  0 */ {   0,   0,   1,   1, {  22,  23, CPOS_HALFTILE, CPOS_HALFTILE }, s_gs201_g6_s0_eff0_script },
};

static const struct GroundEventData s_gs201_g2_s0_evts[] = { /* 0x8255410 */
    /*  0 */ {   3,   3,   0,   0, {  26,  17, 0, 0 }, &s_gs201_g2_s0_evt0_sref },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x825541c */
    &s_gs201_g0_s0_station_sref,
    &s_gs201_g1_s0_station_sref,
    &s_gs201_g2_s0_station_sref,
    &s_gs201_g2_s1_station_sref,
    &s_gs201_g3_s0_station_sref,
    &s_gs201_g4_s0_station_sref,
    &s_gs201_g5_s0_station_sref,
    &s_gs201_g6_s0_station_sref,
};

static const struct GroundScriptSector s_gs201_g0_sectors[] = { /* 0x825543c */
    { LPARRAY(s_gs201_g0_s0_lives), LPARRAY(s_gs201_g0_s0_objs), 0,NULL, 0,NULL, 1,&sStationScripts[0], },
    { LPARRAY(s_gs201_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs201_g0_s2_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs201_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs201_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs201_g0_s5_lives), LPARRAY(s_gs201_g0_s5_objs), 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs201_g1_sectors[] = { /* 0x825552c */
    { LPARRAY(s_gs201_g1_s0_lives), 0,NULL, LPARRAY(s_gs201_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptSector s_gs201_g2_sectors[] = { /* 0x8255554 */
    { LPARRAY(s_gs201_g2_s0_lives), 0,NULL, 0,NULL, LPARRAY(s_gs201_g2_s0_evts), 1,&sStationScripts[2], },
    { LPARRAY(s_gs201_g2_s1_lives), 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[3], },
};

static const struct GroundScriptSector s_gs201_g3_sectors[] = { /* 0x82555a4 */
    { LPARRAY(s_gs201_g3_s0_lives), 0,NULL, LPARRAY(s_gs201_g3_s0_effs), 0,NULL, 1,&sStationScripts[4], },
};

static const struct GroundScriptSector s_gs201_g4_sectors[] = { /* 0x82555cc */
    { LPARRAY(s_gs201_g4_s0_lives), 0,NULL, LPARRAY(s_gs201_g4_s0_effs), 0,NULL, 1,&sStationScripts[5], },
};

static const struct GroundScriptSector s_gs201_g5_sectors[] = { /* 0x82555f4 */
    { LPARRAY(s_gs201_g5_s0_lives), 0,NULL, LPARRAY(s_gs201_g5_s0_effs), 0,NULL, 1,&sStationScripts[6], },
};

static const struct GroundScriptSector s_gs201_g6_sectors[] = { /* 0x825561c */
    { LPARRAY(s_gs201_g6_s0_lives), 0,NULL, LPARRAY(s_gs201_g6_s0_effs), 0,NULL, 1,&sStationScripts[7], },
};

static const struct GroundScriptGroup s_gs201_groups[] = { /* 0x8255644 */
    { LPARRAY(s_gs201_g0_sectors) },
    { LPARRAY(s_gs201_g1_sectors) },
    { LPARRAY(s_gs201_g2_sectors) },
    { LPARRAY(s_gs201_g3_sectors) },
    { LPARRAY(s_gs201_g4_sectors) },
    { LPARRAY(s_gs201_g5_sectors) },
    { LPARRAY(s_gs201_g6_sectors) },
};

static const struct GroundLink s_gs201_links[] = { /* 0x825567c */
    /* link   0 */ { { /*x*/  27, /*y*/  19, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
    /* link   1 */ { { /*x*/  23, /*y*/  25, /*flags*/ CPOS_HALFTILE, CPOS_HALFTILE }, /*w*/  1, /*h*/  1, /*ret*/ 1, /*?*/ 0 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs201 = { LPARRAY(s_gs201_groups), s_gs201_links }; /* 0x825568c */
