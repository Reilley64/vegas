
// src/fallout/magic/cureeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/cureeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/active_effect_fields.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/B824800MagicTarget.h"
#include "fnv/decl/MagicTargetTypedDispel.h"
struct Actor;
struct MagicTarget
{
    Actor* GetOwnerActor() const;
};

struct FUN_0080d4b0_shell
{
    bool HasActor(MagicTarget* apTarget);
};

// @fnv 0x0080d4b0
bool FUN_0080d4b0_shell::HasActor(MagicTarget* apTarget)
{
    Actor* pActor = apTarget ? apTarget->GetOwnerActor() : 0;
    return pActor != 0;
}

struct BSThread
{
};
struct Unk824630
{
};
struct Unk824800
{
};
struct CureEffect
{
    char _pad[0x48];
    int m_eSpellType;
    int m_iCureType;
    void FUN_0080c210();
};
// @fnv 0x0080c210
void CureEffect::FUN_0080c210()
{
    if (m_iCureType == -1)
        reinterpret_cast<::MagicTargetTypedDispel *>((((Unk824630*)reinterpret_cast<::ActiveEffectFields *>(this)->target)))->FUN_00824630(m_eSpellType);
    else
        reinterpret_cast<::B824800MagicTarget *>((((Unk824800*)reinterpret_cast<::ActiveEffectFields *>(this)->target)))->RemoveEffectsByArchetype(m_iCureType, 0);
}

struct MagicCaster;
struct MagicItem;
struct EffectItem;

struct ActiveEffect
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v0a()
    {}
    virtual void v0b()
    {}
    virtual void v0c()
    {}
    virtual void v0d()
    {}
    virtual void v0e()
    {}
    virtual void v0f()
    {}
    virtual void v10()
    {}
    virtual void v11(ActiveEffect*)
    {}
};

struct FUN_0080c070 : ActiveEffect
{
    char _pad[0x4c];

    FUN_0080c070(MagicCaster*, MagicItem*, EffectItem*, int);
};

struct FUN_0080c0b0 : ActiveEffect
{
    char _pad[0x4c];

    FUN_0080c0b0(MagicCaster*, MagicItem*, EffectItem*, int);
};

struct FUN_0080c0f0_shell : ActiveEffect
{
    char _pad0[4];
    MagicItem* pMagicItem;
    EffectItem* pEffectItem;
    char _pad1[0x18];
    MagicCaster* pMagicCaster;
    char _pad2[0x1c];
    int m_eSpellType;
    int m_iCureType;

    ActiveEffect* FUN_0080c0f0();
};


// @fnv 0x0080c0f0
ActiveEffect* FUN_0080c0f0_shell::FUN_0080c0f0()
{
    ActiveEffect* pEffect = 0;

    if (m_iCureType == -1)
    {
        pEffect = new FUN_0080c070(pMagicCaster, pMagicItem, pEffectItem, m_eSpellType);
    }
    else
    {
        pEffect = new FUN_0080c0b0(pMagicCaster, pMagicItem, pEffectItem, m_iCureType);
    }

    this->v11(pEffect);
    return pEffect;
}
