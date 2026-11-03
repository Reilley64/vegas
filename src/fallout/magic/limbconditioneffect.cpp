// fallout/magic/limbconditioneffect.cpp: LimbConditionEffect, MyEffect, LimbConditionEffectShell, ValueModifierEffect (11 functions)

#include "fnv/decl/ActiveEffectSaveShell.h"
#include "fnv/decl/FUN_00802d90_shell.h"
#include "fnv/decl/FUN_00806420_shell.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/ValueModifierEffect_LoadGame_Helper.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
bool g_bLimbConditionEffectInitialized;

// @fnv 0x005b9210
bool GetLimbConditionEffectInitialized()
{
    return g_bLimbConditionEffectInitialized;
}

struct Actor;
struct LimbConditionEffect
{
    unsigned short FUN_0080f2b0(Actor* apActor);
};

// @fnv 0x0080f2b0
unsigned short LimbConditionEffect::FUN_0080f2b0(Actor* apActor)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::FUN_00802d90_shell *>((((LimbConditionEffect*)this)))->FUN_00802d90(apActor);
    isize += 4;
    return isize;
}

class ActiveEffect;
class Actor;
namespace ActorValue { enum Index; }
struct Actor;
struct ValueModifierEffect
{
    ValueModifierEffect(void*, void*, void*);
public:
    void FUN_00802db0(::Actor *);
public:
    void CopyData(::ActiveEffect *);
public:
    void ApplyActorValueModifier(::Actor *, float, ::ActorValue::Index);
};
extern int DAT_0107a3fc;
struct FUN_0080f060 : ValueModifierEffect
{
    FUN_0080f060(void*, void*, void*);
};
// Constructs the object by calling the ValueModifierEffect base constructor, setting the vtable to DAT_0107a3fc and initializing the field at offset 0x4C to -1.
// @fnv 0x0080f060
FUN_0080f060::FUN_0080f060(void* a, void* b, void* c) : ValueModifierEffect(a, b, c)
{
    *(void**)this = (void*)&DAT_0107a3fc;
    *(int*)((char*)this + 0x4C) = -1;
}

struct TESSaveLoadGame
{
};
struct Base00802dd0
{
};
struct FUN_0080f2f0_Owner
{
    char _pad[0x4C];
    int m_4C;
    void FUN_0080f2f0(void*);
};
// @fnv 0x0080f2f0
void FUN_0080f2f0_Owner::FUN_0080f2f0(void* a1)
{
    reinterpret_cast<::ValueModifierEffect_LoadGame_Helper *>((((Base00802dd0*)this)))->FUN_00802dd0((::Actor *)(a1));
    reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0(&m_4C, 4);
}

struct BGSSaveFormBuffer
{
};
struct Unk0080F320
{
    void SaveToBuffer(BGSSaveFormBuffer*);
    char _pad[0x4C];
    int _m4C;
};
// @fnv 0x0080f320
void Unk0080F320::SaveToBuffer(BGSSaveFormBuffer* apBuffer)
{
    reinterpret_cast<::ActiveEffectSaveShell *>(this)->FUN_00806230((::SaveFormBuf *)(apBuffer));
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&_m4C, 4, 0);
}

struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
};
struct ActiveEffect
{
    virtual void LoadGame(BGSLoadFormBuffer*);
};
struct MyEffect : ActiveEffect
{
    void FUN_0080f350(BGSLoadFormBuffer*);
};
// Calls ActiveEffect::LoadGame, then for buffer version 8 or higher reads 4 bytes into the field at offset 0x4c.
// @fnv 0x0080f350
void MyEffect::FUN_0080f350(BGSLoadFormBuffer* apBuffer)
{
    reinterpret_cast<::FUN_00806420_shell *>(this)->FUN_00806420(apBuffer);
    if (apBuffer->GetVersion() >= 8)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x4c), 4);
    }
}

struct ValueModifierEffectShell : public ValueModifierEffect
{
};

struct LimbConditionEffectShell : public LimbConditionEffect
{
    char _pad[0x4C];
    int m_4C;
    void FUN_0080f150(ActiveEffect* other);
};

// Copies the base value-modifier data from other, then, if other is a LimbConditionEffect, copies m_4C into it.
// @fnv 0x0080f150
void LimbConditionEffectShell::FUN_0080f150(ActiveEffect* other)
{
    reinterpret_cast<::ValueModifierEffect *>((reinterpret_cast<ValueModifierEffectShell*>(this)))->CopyData(other);
    LimbConditionEffect* target = dynamic_cast<LimbConditionEffect*>(other);
    if (target)
        reinterpret_cast<LimbConditionEffectShell*>(target)->m_4C = m_4C;
}

namespace fnv_0082ba30 {
struct ValueModifierEffect
{
    char _pad[0x4C];
    int m_4C;
    void FUN_0082ba30(Actor*);
};
struct TESSaveLoadGame
{
};
// @fnv 0x0082ba30
void ValueModifierEffect::FUN_0082ba30(Actor* apActor)
{
    reinterpret_cast<::ValueModifierEffect *>(this)->FUN_00802db0(apActor);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0082ba30::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&m_4C, 4);
}
}  // namespace fnv_0082ba30

struct GameSettingCollection
{
    float fValue;
};
template <class T> struct SettingT
{
    float* Float();
};
namespace ActorValue { enum Index; }
// ActorValue::Index values used below: no actor value, and the first limb
// condition (perception condition; the limb conditions run to 31).
constexpr int kActorValueNone = -1;
constexpr int kActorValuePerceptionCondition = 25;
struct ValueModifierEffectHelper
{
};
struct LimbConditionEffect_0080f220
{
    char _pad[0x4C];
    int m_4C;
    void FUN_0080f220(Actor* apActor, float afModifier, ActorValue::Index aeOverrideActorValue);
};
// @fnv 0x0080f220
void LimbConditionEffect_0080f220::FUN_0080f220(Actor* apActor, float afModifier,
                                                           ActorValue::Index aeOverrideActorValue)
{
    if (m_4C != kActorValueNone)
    {
        float fScaledMagnitude = afModifier * *((float *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting1213))));
        reinterpret_cast<::ValueModifierEffect *>((((ValueModifierEffectHelper*)this)))->ApplyActorValueModifier(apActor, afModifier, (ActorValue::Index)m_4C);
    }
    else
    {
        float fScaledMagnitude = afModifier * *((float *)&(::FUN_00403e20((float *)&(::originalRuntimeFloatSetting1214))));
        for (int i = kActorValuePerceptionCondition; i < 32; ++i)
            reinterpret_cast<::ValueModifierEffect *>((((ValueModifierEffectHelper*)this)))->ApplyActorValueModifier(apActor, fScaledMagnitude, (ActorValue::Index)i);
    }
}

struct FUN_0080f1a0_StandIn : ValueModifierEffect
{
    char _pad[0x50 - sizeof(void*)];
    int _m50;
    FUN_0080f1a0_StandIn(void*, void*, void*);
};

// Allocates and constructs a stand-in ValueModifierEffect-derived object from three arguments and returns it.
// @fnv 0x0080f1a0
FUN_0080f1a0_StandIn* FUN_0080f1a0(void* ap1, void* ap2, void* ap3)
{
    return new FUN_0080f1a0_StandIn(ap1, ap2, ap3);
}

extern int _data_011c16bc;

struct FUN_0080f0a0_Class
{
// @fnv 0x0080f0a0
    virtual void FUN_0080f0a0_00()
    {}
    virtual void FUN_0080f0a0_01()
    {}
    virtual void FUN_0080f0a0_02()
    {}
    virtual void FUN_0080f0a0_03()
    {}
    virtual void FUN_0080f0a0_04()
    {}
    virtual void FUN_0080f0a0_05()
    {}
    virtual void FUN_0080f0a0_06()
    {}
    virtual void FUN_0080f0a0_07()
    {}
    virtual void FUN_0080f0a0_08()
    {}
    virtual void FUN_0080f0a0_09()
    {}
    virtual void FUN_0080f0a0_10()
    {}
    virtual void FUN_0080f0a0_11()
    {}
    virtual void FUN_0080f0a0_12()
    {}
    virtual void FUN_0080f0a0_13()
    {}
    virtual void FUN_0080f0a0_14()
    {}
    virtual void FUN_0080f0a0_15()
    {}
    virtual void FUN_0080f0a0_16()
    {}
    virtual void CopyFrom(ActiveEffect* other);

    char _pad[4];
    void* _p8;
    void* _pC;
    char _pad10[0x18];
    void* _p28;
};

ActiveEffect* FUN_0080f0a0(FUN_0080f0a0_Class* self)
{
    ActiveEffect* presult = (ActiveEffect*)new FUN_0080f1a0_StandIn(self->_p28, self->_p8, self->_pC);

    self->CopyFrom(presult);

    return presult;
}
