#ifndef GUARD_STR_DAMAGE_H
#define GUARD_STR_DAMAGE_H

// size: 0x10
typedef struct DamageStruct
{
    s32 dmg;
    s32 residualDmgType;
    u32 typeEffectiveness;
    u8 type;
    bool8 isCrit;
    u8 unkE;
    bool8 tookNoDamage;
} DamageStruct;

#endif // GUARD_STR_DAMAGE_H