static const MenuItem sUnknown_80DC584[3] =
{
    {_("Yes"), 2},
    {_("No"), 3},
    {NULL, 1},
};

static const WindowTemplate sUnknown_80DC5A4 =
{
    0,
    3,
    0, 0,
    0, 0,
    0, 0,
    NULL
};
static const WindowTemplate sUnknown_80DC5BC =
{
    0,
    3,
    20, 4,
    6, 3,
    3, 0,
    NULL
};
static const WindowTemplate sUnknown_80DC5D4 =
{
    0,
    3,
    20, 11,
    6, 3,
    3, 0,
    NULL
};

ALIGNED(4) static const u8 sTripleQuestionMark[] = _("？？？");
ALIGNED(4) static const u8 sDoesNotAppearHungry[] = _("It doesn't appear to be hungry.");

ALIGNED(4) static const u8 sFmtGummiBigFav[] = _(
    "{POKEMON_1} took the Gummi and ate it.\n"
    "This Gummi looks like a big favorite!\n"
    "{POKEMON_1}'s IQ went up!");

ALIGNED(4) static const u8 sFmtGummiFav[] = _(
    "{POKEMON_1} took the Gummi and ate it.\n"
    "This Gummi looks like a favorite!\n"
    "{POKEMON_1}'s IQ went up!");

ALIGNED(4) static const u8 sFmtGummiOkay[] = _(
    "{POKEMON_1} took the Gummi and ate it.\n"
    "It doesn't seem to dislike this Gummi.\n"
    "{POKEMON_1}'s IQ went up!");

ALIGNED(4) static const u8 sFmtGummiSatisfied[] = _(
    "{POKEMON_1} took the Gummi and ate it.\n"
    "It appears to be just a little satisfied.\n"
    "{POKEMON_1}'s IQ went up!");

ALIGNED(4) static const u8 sFmtIQHelpedLearn[] = _(
    "{POKEMON_1}'s IQ helped it learn how to\n"
    "use {MOVE_ITEM_1}!");

ALIGNED(4) static const u8 sFmtPlusEverything[] = _(
    "Yes! {POKEMON_1} grew explosively!\n"
    "Attack, Defense, and so on rose by 1!");

ALIGNED(4) static const u8 sFmtPlusAtk[] = _(
    "Yes!\n"
    "{POKEMON_1}'s Attack rose by 1!");

ALIGNED(4) static const u8 sFmtPlusSpAtk[] = _(
    "Yes!\n"
    "{POKEMON_1}'s Special Attack rose by 1!");

ALIGNED(4) static const u8 sFmtPlusDef[] = _(
    "Yes!\n"
    "{POKEMON_1}'s Defense rose by 1!");

ALIGNED(4) static const u8 sFmtPlusSpDef[] = _(
    "Yes!\n"
    "{POKEMON_1}'s Special Defense rose by 1!");

ALIGNED(4) static const u8 sNoGummis[] = _("You don't have any Gummis.");
ALIGNED(4) static const u8 sNoItem[] = _("You don't have an item.");
ALIGNED(4) static const u8 sGummiGone[] = _("The Gummi is gone!");
ALIGNED(4) static const u8 sItemGone[] = _("The item is gone!");
ALIGNED(4) static const u8 sGive[] = _("Give");
ALIGNED(4) static const u8 sUse[] = _("Use");
