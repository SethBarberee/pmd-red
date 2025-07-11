#include "global.h"
#include "globaldata.h"
#include "constants/emotions.h"
#include "bg_palette_buffer.h"
#include "code_801602C.h"
#include "random_mersenne_twister.h"
#include "code_8099360.h"
#include "game_options.h"
#include "input.h"
#include "main_loops.h"
#include "memory.h"
#include "menu_input.h"
#include "personality_test1.h"
#include "personality_test2.h"
#include "random.h"
#include "save.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_util.h"

enum
{
    PERSONALITY_GENERATE_NEW_QUESTION,
    PERSONALITY_ASK_QUESTION,
    PERSONALITY_UPDATE_TOTALS,
    PERSONALITY_PLAYER_GENDER,
    PERSONALITY_REVEAL,
    PERSONALITY_STARTER_REVEAL,
    PERSONALITY_ADVANCE_TO_PARTNER_SELECTION_1,
    PERSONALITY_ADVANCE_TO_PARTNER_SELECTION_2,
    PERSONALITY_ADVANCE_TO_PARTNER_SELECTION_3,
    PERSONALITY_PARTNER_SELECTION,
    PERSONALITY_ADVANCE_TO_PARTNER_NICKNAME_1,
    PERSONALITY_ADVANCE_TO_PARTNER_NICKNAME_2,
    PERSONALITY_PARTNER_NICKNAME,
    PERSONALITY_END_INTRO,
    PERSONALITY_ADVANCE_TO_TEST_END,
    PERSONALITY_TEST_END,
};

static EWRAM_INIT PersonalityTestTracker *sPersonalityTestTracker = {NULL};

#include "data/personality_test1.h"

static void AdvanceToPartnerNicknameScreen(void);
static void AdvanceToPartnerSelection(void);
static void AdvanceToPickPartnerPrompt(void);
static void AdvanceToTestEnd(void);
static void CallCreatePartnerSelectionMenu(void);
static void CallPromptNewQuestion(void);
static void GenerateNewQuestionOrGender(void);
static void InitializeTestStats(void);
static void NicknamePartner(void);
static void PersonalityTest_DisplayStarterSprite(void);
static void PrintEndIntroText(void);
static void PrintPersonalityTypeDescription(void);
static void PromptForPartnerNickname(void);
static void PromptNewQuestion(void);
static void PromptPickPartner(void);
static void RevealPersonality(void);
static void RevealStarter(void);
static void SetPlayerGender(void);
static void UpdateNatureTotals(void);

bool8 CreateTestTracker(void)
{
    sPersonalityTestTracker = MemoryAlloc(sizeof(PersonalityTestTracker), 8);
    ResetTouchScreenMenuInput(&sPersonalityTestTracker->input);
    InitializeTestStats();
    sub_8099690(1);
    return TRUE;
}

static void InitializeTestStats(void)
{
    s32 i;

    sub_8001024(&sPersonalityTestTracker->unk4);
    sPersonalityTestTracker->FrameCounter = 0;
    sPersonalityTestTracker->TestState = 0;
    sPersonalityTestTracker->QuestionCounter = 0;

    for (i = 0; i < NUM_PERSONALITIES; i++)
        sPersonalityTestTracker->NatureTotals[i] = 0;

    sPersonalityTestTracker->currQuestionIndex = 0;

    for (i = 0; i < NUM_QUIZ_QUESTIONS; i++)
        sPersonalityTestTracker->QuestionTracker[i] = 0;

    sPersonalityTestTracker->playerNature = 0;
    sPersonalityTestTracker->playerGender = 0;
}

u32 HandleTestTrackerState(void)
{
    s32 counter;
    s32 iVar1;

    sPersonalityTestTracker->FrameCounter++;

    switch (sPersonalityTestTracker->TestState) {
        case PERSONALITY_GENERATE_NEW_QUESTION:
            GenerateNewQuestionOrGender();
            break;
        case PERSONALITY_ASK_QUESTION:
            CallPromptNewQuestion();
            break;
        case PERSONALITY_UPDATE_TOTALS:
            UpdateNatureTotals();
            break;
        case PERSONALITY_PLAYER_GENDER:
            SetPlayerGender();
            break;
        case PERSONALITY_REVEAL:
            RevealPersonality();
            break;
        case PERSONALITY_STARTER_REVEAL:
            RevealStarter();
            break;
        case PERSONALITY_ADVANCE_TO_PARTNER_SELECTION_1:
            AdvanceToPickPartnerPrompt();
            break;
        case PERSONALITY_ADVANCE_TO_PARTNER_SELECTION_2:
            PromptPickPartner();
            break;
        case PERSONALITY_ADVANCE_TO_PARTNER_SELECTION_3:
            AdvanceToPartnerSelection();
            break;
        case PERSONALITY_PARTNER_SELECTION:
            CallCreatePartnerSelectionMenu();
            break;
        case PERSONALITY_ADVANCE_TO_PARTNER_NICKNAME_1:
            PromptForPartnerNickname();
            break;
        case PERSONALITY_ADVANCE_TO_PARTNER_NICKNAME_2:
            AdvanceToPartnerNicknameScreen();
            break;
        case PERSONALITY_PARTNER_NICKNAME:
            NicknamePartner();
            break;
        case PERSONALITY_END_INTRO:
            PrintEndIntroText();
            break;
        case PERSONALITY_ADVANCE_TO_TEST_END:
            AdvanceToTestEnd();
            break;
        case PERSONALITY_TEST_END:
            iVar1 = Rand32Bit() * sPersonalityTestTracker->FrameCounter;
            MersenneTwister_InitializeState(Rand32Bit());

            for (counter = 0; counter < NUM_PERSONALITIES; counter++)
                iVar1 *= sPersonalityTestTracker->NatureTotals[counter] + counter + 3;

            iVar1 += Random32MersenneTwister();
            while (iVar1 == -1)
                iVar1 += Random32MersenneTwister();

            sub_8011C40(iVar1);
            return 3;
        default:
            break;
    }
    return 0;
}

void DeleteTestTracker(void)
{
    sub_8001044(&sPersonalityTestTracker->unk4);
    MemoryFree(sPersonalityTestTracker);
    sPersonalityTestTracker = NULL;
}

static void GenerateNewQuestionOrGender(void)
{
    u8 category;
    s32 i;
    s32 newQuestion;

    sPersonalityTestTracker->QuestionCounter++;

    if (sPersonalityTestTracker->QuestionCounter > MAX_ASKED_QUESTIONS) {
        CreateMenuDialogueBoxAndPortrait(sGender0, 0, 0, gGenderMenu, 0, 3, 0, 0, 257);
        sPersonalityTestTracker->TestState = PERSONALITY_PLAYER_GENDER;
    }
    else {
        do {
            // Generate new question number and make sure we haven't done it
            newQuestion = RandInt(NUM_QUIZ_QUESTIONS);
            sPersonalityTestTracker->currQuestionIndex = newQuestion;
        } while (sPersonalityTestTracker->QuestionTracker[newQuestion] == 1);

        // Found one so let's get the category
        category = gNatureQuestionTable[sPersonalityTestTracker->currQuestionIndex];

        // Mark all of the questions in the category as used
        for (i = 0; i < NUM_QUIZ_QUESTIONS; i++) {
            if (gNatureQuestionTable[i] == category)
                sPersonalityTestTracker->QuestionTracker[i] = 1;
        }
        sPersonalityTestTracker->TestState = PERSONALITY_ASK_QUESTION;
    }
}

static void CallPromptNewQuestion(void)
{
    PromptNewQuestion();
    sPersonalityTestTracker->TestState = PERSONALITY_UPDATE_TOTALS;
}

static void UpdateNatureTotals(void)
{
    s32 answerIndex;
    s32 natureIndex;
    const PersonalityEffects *pointArray;

    if (sub_80144A4(&answerIndex))
        return;

    // This is for the second part of Brave 2 Question if you fight..
    if (answerIndex == BRAVE_2B_TRIGGER) {
        // Set question to BRAVE_2B and ask the question..
        sPersonalityTestTracker->currQuestionIndex = NUM_QUIZ_QUESTIONS;
        sPersonalityTestTracker->TestState = PERSONALITY_ASK_QUESTION;
    }
    else {
        pointArray = gPersonalityQuestionPointerTable[sPersonalityTestTracker->currQuestionIndex]->effects;
        pointArray += answerIndex;
        for (natureIndex = 0; natureIndex < NUM_PERSONALITIES; natureIndex++)
            sPersonalityTestTracker->NatureTotals[natureIndex] += (*pointArray)[natureIndex];

        sPersonalityTestTracker->TestState = PERSONALITY_GENERATE_NEW_QUESTION;
    }
}

static void SetPlayerGender(void)
{
    s32 gender;

    if (sub_80144A4(&gender) != 0)
        return;

    if (gender == MALE) {
        sPersonalityTestTracker->playerGender = MALE;
        gGameOptionsRef->playerGender = MALE;
    }
    else {
        sPersonalityTestTracker->playerGender = FEMALE;
        gGameOptionsRef->playerGender = FEMALE;
    }

    sub_8099690(0);
    sPersonalityTestTracker->TestState = PERSONALITY_REVEAL;
}

static void RevealPersonality(void)
{
    s32 currentNature;
    s32 i;

    sPersonalityTestTracker->playerNature = RandInt(NUM_PERSONALITIES);
    currentNature = sPersonalityTestTracker->playerNature;

    for (i = 0; i < NUM_PERSONALITIES - 1; i++) {
        currentNature++;

        // Wraparound check
        if (currentNature > QUIRKY)
            currentNature = HARDY;

        if (sPersonalityTestTracker->NatureTotals[currentNature] > sPersonalityTestTracker->NatureTotals[sPersonalityTestTracker->playerNature])
            sPersonalityTestTracker->playerNature = currentNature;
    }

    sPersonalityTestTracker->unk4.StarterID = gStarters[sPersonalityTestTracker->playerNature][sPersonalityTestTracker->playerGender];
    PrintPersonalityTypeDescription();
    sPersonalityTestTracker->TestState = PERSONALITY_STARTER_REVEAL;
}

static void RevealStarter(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0) {
        CreateDialogueBoxAndPortrait(gStarterReveal, 0, 0, 0x101);
        PersonalityTest_DisplayStarterSprite();
        sPersonalityTestTracker->TestState = PERSONALITY_ADVANCE_TO_PARTNER_SELECTION_1;
    }
}

static void AdvanceToPickPartnerPrompt(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        sPersonalityTestTracker->TestState = PERSONALITY_ADVANCE_TO_PARTNER_SELECTION_2;
}

static void PromptPickPartner(void)
{
    CreateDialogueBoxAndPortrait(gPartnerPrompt, 0, 0, 0x301);
    sPersonalityTestTracker->TestState = PERSONALITY_ADVANCE_TO_PARTNER_SELECTION_3;
}

static void AdvanceToPartnerSelection(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        sPersonalityTestTracker->TestState = PERSONALITY_PARTNER_SELECTION;
}

static void CallCreatePartnerSelectionMenu(void)
{
    CreatePartnerSelectionMenu(sPersonalityTestTracker->unk4.StarterID);
    sPersonalityTestTracker->TestState = PERSONALITY_ADVANCE_TO_PARTNER_NICKNAME_1;
}

static void PromptForPartnerNickname(void)
{
    u16 selectedPartner;

    selectedPartner = HandlePartnerSelectionInput();

    if (selectedPartner != 0xFFFF) {
        if (selectedPartner != 0xFFFE) {
            sub_803CE6C();
            sPersonalityTestTracker->unk4.PartnerID = selectedPartner;
            CreateDialogueBoxAndPortrait(gPartnerNickPrompt, 0, 0, 0x301);
            sPersonalityTestTracker->TestState = PERSONALITY_ADVANCE_TO_PARTNER_NICKNAME_2;
        }
    }
}

static void AdvanceToPartnerNicknameScreen(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        sPersonalityTestTracker->TestState = PERSONALITY_PARTNER_NICKNAME;
}

static void NicknamePartner(void)
{
    CopyStringtoBuffer(sPersonalityTestTracker->unk4.PartnerNick, GetMonSpecies(sPersonalityTestTracker->unk4.PartnerID));
    CreateConfirmNameMenu(3, sPersonalityTestTracker->unk4.PartnerNick);
    sPersonalityTestTracker->TestState = PERSONALITY_END_INTRO;
}

static void PrintEndIntroText(void)
{
    if (sub_8016080()) {
        CleanConfirmNameMenu();
        CreateDialogueBoxAndPortrait(gEndIntroText, 0, 0, 0x301);
        sPersonalityTestTracker->TestState = PERSONALITY_ADVANCE_TO_TEST_END;
    }
}

static void AdvanceToTestEnd(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        sPersonalityTestTracker->TestState = PERSONALITY_TEST_END;
}

static void PromptNewQuestion(void)
{
    CreateMenuDialogueBoxAndPortrait(gPersonalityQuestionPointerTable[sPersonalityTestTracker->currQuestionIndex]->question,
        0, 0,
        gPersonalityQuestionPointerTable[sPersonalityTestTracker->currQuestionIndex]->answers,
        0, 3, 0, 0, 0x101);
}

static void PrintPersonalityTypeDescription(void)
{
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[0], sPersonalityTestTracker->unk4.StarterID);
    CreateDialogueBoxAndPortrait(sPersonalityTypeDescriptionTable[sPersonalityTestTracker->playerNature], 0, 0, 0x101);
}

static void PersonalityTest_DisplayStarterSprite(void)
{
    s32 starterID;
    struct OpenedFile *faceFile;
    s32 paletteIndex;
    s32 emotionId;
    const u8 *gfx;
    WindowTemplates stackArray;

    starterID = sPersonalityTestTracker->unk4.StarterID;
    RestoreSavedWindows(&stackArray);
    stackArray.id[1] = sUnknown_80F4244;
    ResetUnusedInputStruct();
    ShowWindows(&stackArray, TRUE, FALSE);
    CallPrepareTextbox_8008C54(1);
    sub_80073B8(1);

    faceFile = GetDialogueSpriteDataPtr(starterID);
    gfx = ((PortraitGfx *)(faceFile->data))->sprites[EMOTION_HAPPY].gfx;
    emotionId = EMOTION_HAPPY;
    for (paletteIndex = 0; paletteIndex < 0x10; paletteIndex++) {
        SetBGPaletteBufferColorArray(paletteIndex + 0xE0, &((PortraitGfx *)(faceFile->data))->sprites[emotionId].pal[paletteIndex]);
    }

    DisplayMonPortraitSpriteFlipped(1, gfx, 14);
    CloseFile(faceFile);
    sub_80073E0(1);
}
