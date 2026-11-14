// fallout/magic/valuemodifiereffect.cpp: ValueModifierEffect, ActorValue, LocalEffect, Cls (16 functions)

#include <cstdio>
#include <cstdint>
#include "fnv/effect_item_fields.h"
#include "fnv/active_effect_fields.h"
#include "fnv/decl/B968730Actor.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_007df210_shell.h"
#include "fnv/decl/FUN_00805760_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/HealthReferenceEntry.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/KillActor.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008808a0__ActorProxy.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005d1000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_0087a000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011de000.h"
#include "valuemodifiereffect_decls.h"

// @fnv 0x0082bbe0
void ValueModifierEffect::CopyData(ActiveEffect* other)
{
    ActiveEffect::CopyData(other);
    ValueModifierEffect* modifier = dynamic_cast<ValueModifierEffect*>(other);
    if (modifier)
        modifier->m_eActorValue = m_eActorValue;
}

// Returns true if the target resolves to an actor that has no health, otherwise false.
// @fnv 0x0082bcb0
bool ValueModifierEffect::IsEffectValid(MagicTarget* target)
{
    Actor* actor = target ? target->GetOwnerActor() : 0;
    return actor && !actor->HasHealth(false);
}

// Allocates a new ValueModifierEffect from the current effect's data, copies state into it via CopyFrom, and returns the copy.
// @fnv 0x0082bb30
ActiveEffect* ValueModifierEffect::Copy()
{
    ActiveEffect* copy = new ValueModifierEffect(m_pEffectInstance, pSpell, pEffect);
    CopyFrom(copy);
    return copy;
}

// @fnv 0x0082bd20
void ValueModifierEffect::Finalize()
{
    Actor* actor = reinterpret_cast<::ActiveEffectFields *>(this)->target
                       ? ((MagicTarget*)reinterpret_cast<::ActiveEffectFields *>(this)->target)->GetOwnerActor()
                       : 0;
    if (((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(((EffectItem*)pEffect))->setting))->IsDetrimentalToActorValue(GetActorValue()))
    {
        m_fElapsedTime = -m_fElapsedTime;
        if (actor && GetActorValue() == 16 &&
            ((::MagicItem *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((MagicCaster*)((::MagicItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->effect)))))->FUN_0084e3a0())))
        {
            Actor* caster = (reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)this)))->FUN_0045cd60())
                                ? ((MagicCaster*)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)this)))->FUN_0045cd60()))->GetCasterActor()
                                : 0;
            m_fElapsedTime = reinterpret_cast<::fnv_008808a0::ActorProxy *>((actor))->FUN_008808a0(m_fElapsedTime, caster);
        }
    }
    ActiveEffect::Finalize();
}

// @fnv 0x0082ce70
float ValueModifierEffect::GetModifiedMagnitude(float magnitude)
{
    float adjusted = magnitude;
    if (reinterpret_cast<::FUN_007df210_shell *>(this)->FUN_007df210())
        return adjusted;
    if ((::FUN_005d1260((*(int *)&(const ::ActorValue::Index &)(GetActorValue()))) || ActorValue::IsDerivedAttribute(GetActorValue()) ||
         ::FUN_0047f060((*(int *)&(const ::ActorValue::Index &)(GetActorValue())))) &&
        magnitude <= 0.0)
    {
        Actor* actor = reinterpret_cast<::ActiveEffectFields *>(this)->target
                           ? ((MagicTarget*)reinterpret_cast<::ActiveEffectFields *>(this)->target)->GetOwnerActor()
                           : 0;
        float result = actor->avOwner.GetActorValue(GetActorValue()) + adjusted;
        if (result < 0.0)
            adjusted = -result + adjusted;
    }
    return adjusted;
}

// @fnv 0x0082c660
void ValueModifierEffect::Update(float delta)
{
    if (!reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(((EffectItem*)pEffect))->setting))))->FUN_00403e60(2))
    {
        Actor* actor = reinterpret_cast<::ActiveEffectFields *>(this)->target
                           ? ((MagicTarget*)reinterpret_cast<::ActiveEffectFields *>(this)->target)->GetOwnerActor()
                           : 0;
        if (IsFlagged() || fDuration > 0.0 || m_eSpellType == 4 || m_eSpellType == 1)
        {
            ApplyActorValueModifier(actor, m_fElapsedTime * delta, ActorValue::kNone);
            if (m_eActorValue == 16 && actor == (Actor*)::_g_thePlayer)
            {
                TESBoundObject* object = ((::TESBoundObject *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell));
                if (object && object->component.HasFoodEffect())
                    ::FUN_005b5e40();
                else if (object->GetSpellType() == 7)
                    ::FUN_005b5e40();
            }
            if (m_eActorValue == 7 && m_fElapsedTime < 0.0 &&
                actor->avOwner.GetActorValue((ActorValue::Index)16) <= 1.0)
            {
                Actor* caster = (reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)this)))->FUN_0045cd60())
                                    ? ((MagicCaster*)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)this)))->FUN_0045cd60()))->GetCasterActor()
                                    : 0;
                reinterpret_cast<::KillActor *>((actor))->FUN_0089d900(caster, 0.0f);
            }
        }
    }
}

// @fnv 0x0082be10
void ValueModifierEffect::RefreshPlayerActorValue()
{
    if ((MagicTarget*)reinterpret_cast<::ActiveEffectFields *>(this)->target == (::_g_thePlayer ? &::_g_thePlayer->target : 0) &&
        (::FUN_005d1260((*(int *)&(const ::ActorValue::Index &)((ActorValue::Index)((EffectItem*)pEffect)->GetAffectedActorValue()))) ||
         ::FUN_0047f060((*(int *)&(const ::ActorValue::Index &)((ActorValue::Index)((EffectItem*)pEffect)->GetAffectedActorValue())))) &&
        ((EffectItem*)pEffect)->IsHostile())
    {
        if (((::TESBoundObject *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell))->GetSpellType() != 4 &&
            reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(((EffectItem*)pEffect))->setting))))->FUN_00403e60(4))
        {
            bool continuous = reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(((EffectItem*)pEffect))->setting))))->FUN_00403e60(2) || IsFlagged();
            char buffer[200];
            sprintf(buffer, "%s %s %s", ((const char *)(reinterpret_cast<::StartMenu *>(&(((SettingT_GameSettingCollection_&)g_011d2ce8)))->GetMenuTitle())),
                    ActorValue::GetActorValueName((ActorValue::Index)((EffectItem*)pEffect)->GetAffectedActorValue()),
                    continuous ? ((const char *)(reinterpret_cast<::StartMenu *>(&(((SettingT_GameSettingCollection_&)g_011d21a8)))->GetMenuTitle()))
                               : ((const char *)(reinterpret_cast<::StartMenu *>(&(((SettingT_GameSettingCollection_&)g_011d4a5c)))->GetMenuTitle())));
            ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)(0), (const char *)(0), 2.0f, false);
        }
    }
}

// @fnv 0x0082ca50
void ValueModifierEffect::ApplyActorValueModifier(Actor* actor, float magnitude, ActorValue::Index requested)
{
    if (!actor)
        return;
    ActorValue::Index value = requested == ActorValue::kNone ? (ActorValue::Index)m_eActorValue : requested;
    if (value == ActorValue::kNone)
    {
        if (magnitude != 0.0)
            ::FUN_005b5e40();
        return;
    }
    bool ability = m_eSpellType == 4 && !reinterpret_cast<::FUN_007df210_shell *>(this)->FUN_007df210();
    if (actor->IsPlayerRef() && ability && reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(((EffectItem*)pEffect))->setting))))->FUN_00403e60(2))
        actor->ForceActorValue(value, magnitude, 0);
    else
    {
        Actor* caster = (reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)this)))->FUN_0045cd60())
                            ? ((MagicCaster*)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)this)))->FUN_0045cd60()))->GetCasterActor()
                            : 0;
        if (!((::MagicItem *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((MagicCaster*)((::MagicItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->effect)))))->FUN_0084e3a0())) ||
            !((EffectItem*)((::MagicItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->effect)))->IsHostile())
            caster = 0;
        if (reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(((EffectItem*)pEffect))->setting))))->FUN_00403e60(2))
            actor->ModActorValue(value, magnitude, caster);
        else
        {
            if (caster && magnitude < 0.0 && value == 16 && caster->IsPlayerRef() && actor != caster &&
                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && !reinterpret_cast<::FUN_0087f3d0_shell *>((actor))->FUN_0087f3d0())
                ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->vfn_72c(::_g_thePlayer, -magnitude);
            actor->DamageActorValue(value, magnitude, caster);
            if (magnitude < 0.0 && value == 16)
                ::FUN_0087a8b0(TaskQueueInterface::GetSingleton(), 0x116c, (::FormTaskRef *)(actor), -magnitude);
        }
    }
}

// Allocates and constructs a ValueModifierEffect from the three given arguments and returns it.
// @fnv 0x0082bc30
ValueModifierEffect* __cdecl FUN_0082bc30(void* p1, void* p2, void* p3)
{
    return new ValueModifierEffect(p1, p2, p3);
}

struct FUN_0080a900 : ValueModifierEffect
{
    FUN_0080a900(void*, void*, void*);
};
// Constructs a ValueModifierEffect by forwarding the three arguments to the base class constructor.
// @fnv 0x0080a900
FUN_0080a900::FUN_0080a900(void* apArg1, void* apArg2, void* apArg3) : ValueModifierEffect(apArg1, apArg2, apArg3)
{}

struct FUN_0082ccb0_Cls : ActiveEffect
{
    bool FUN_0082ccb0();
    int unk48;
};
// @fnv 0x0082ccb0
bool FUN_0082ccb0_Cls::FUN_0082ccb0()
{
    return this->unk48 == 16 && reinterpret_cast<::S3e60 *>((reinterpret_cast<::ActiveEffect *>(this)->GetEffectSetting()))->FUN_00403e60(4) && !reinterpret_cast<::S3e60 *>((reinterpret_cast<::ActiveEffect *>(this)->GetEffectSetting()))->FUN_00403e60(2);
}

extern int DAT_0107c68c;

struct FUN_0080bc70_base
{
    ~FUN_0080bc70_base();
    FUN_0080bc70_base(MagicCaster*, MagicItem*, EffectItem*);
};

struct FUN_00403e80_shell
{
    bool FUN_00403e80();
};

struct IMH
{
};

struct FUN_0082ba60 : public FUN_0080bc70_base
{
    FUN_0082ba60(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
};

// Initializes the base with caster, spell and effect, stores a value derived from the effect setting or effect, and sets a float to 1.0 when flag 0x100 is set.
// @fnv 0x0082ba60
FUN_0082ba60::FUN_0082ba60(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect)
    : FUN_0080bc70_base(apCaster, apSpell, apEffect)
{
    *(void**)this = &DAT_0107c68c;
    EffectSetting* psetting = ((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(apEffect)->setting));
    if (reinterpret_cast<FUN_00403e80_shell*>(psetting)->FUN_00403e80())
        reinterpret_cast<ValueModifierEffectFields*>(this)->actorValue = (int)((intptr_t)(reinterpret_cast<::InterfaceManager *>((reinterpret_cast<IMH*>(psetting)))->FUN_00586150()));
    else
        reinterpret_cast<ValueModifierEffectFields*>(this)->actorValue = apEffect->GetAffectedActorValue();

    if (reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(apEffect)->setting))))->FUN_00403e60(0x100))
        reinterpret_cast<ActiveEffectFields*>(this)->elapsedTime = 1.0f;
}

struct ActorAVExt : Actor
{
    virtual void vfn_3b0();
    virtual void SetActorValueF(ActorValue::Index, float);
};

struct ParentCellStub
{
};

struct CasterStub
{
};

struct EffectItemStub
{
};

struct TESSaveLoadGameStub
{
};

struct LoadedValueEffect : ValueModifierEffect
{
    void FUN_0082cd10(Actor* apActor);
};

// Restarts the effect on the actor, then for save versions 0x5f-0x61 re-applies the magnitude to the player target via SetActorValueF and ModActorValue.
// @fnv 0x0082cd10
void LoadedValueEffect::FUN_0082cd10(Actor* apActor)
{
    reinterpret_cast<::FUN_00805760_shell *>(this)->FUN_00805760(apActor);
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::TESSaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x5f && reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::TESSaveLoadGameStub * *>(&::g_TESSaveLoadGame))))->FUN_008df040() < 0x62)
    {
        ActorAVExt* pTarget = ((::ParentCellStub *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::ActorAVExt *)(reinterpret_cast<::MagicTarget *>((((::ParentCellStub *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
        if (pTarget && pTarget->IsPlayerRef() && IsFlagged() &&
            reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(((EffectItemStub*)pEffect))->setting))))->FUN_00403e60(2))
        {
            Actor* pCasterActor = ((::CasterStub *)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60())) ? reinterpret_cast<::MagicCaster *>((((::CasterStub *)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60()))))->GetCasterActor() : 0;
            pTarget->SetActorValueF(GetActorValue(), -::GetFloatAtOffset1C((char *)this));
            pTarget->ModActorValue(GetActorValue(), ::GetFloatAtOffset1C((char *)this), pCasterActor);
        }
    }
}

class MagicItem
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int GetSpellType();
};
class AlchemyItem : public MagicItem
{
  public:
};
struct EffectDuration
{
};
struct TargetGetter
{
};
struct AVInterface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual double current(int);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual double base(int);
};
struct LocalPlayer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    AVInterface values;
};
void __cdecl FUN_004d5e10(int, int);
struct LocalEffect
{
    int unk00;
    int unk04;
    int unk08;
    EffectDuration* effect;
    int unk10;
    int unk14;
    int unk18;
    float magnitude;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int which;
    void FUN_0082c490();
};
class BSThread
{
  public:
};
class NiQuatTransform
{
  public:
};
class TESObjectREFR
{
  public:
};
struct EffectObj
{
};
struct Obj822b40
{
};
struct Obj815410
{
};
struct Obj968730
{
};
struct MyOwner
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual int vfn_8(int);
};
struct ProcObj
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual void vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void vfn_468();
    virtual void vfn_46c();
    virtual void vfn_470();
    virtual void vfn_474();
    virtual void vfn_478();
    virtual void vfn_47c();
    virtual void vfn_480();
    virtual void vfn_484();
    virtual void vfn_488();
    virtual void vfn_48c();
    virtual void vfn_490();
    virtual void vfn_494();
    virtual void vfn_498();
    virtual void vfn_49c();
    virtual void vfn_4a0();
    virtual void vfn_4a4();
    virtual void vfn_4a8();
    virtual void vfn_4ac();
    virtual void vfn_4b0();
    virtual void vfn_4b4();
    virtual void vfn_4b8();
    virtual void vfn_4bc();
    virtual void vfn_4c0();
    virtual void vfn_4c4();
    virtual void vfn_4c8();
    virtual void vfn_4cc();
    virtual void vfn_4d0();
    virtual void vfn_4d4();
    virtual void vfn_4d8();
    virtual void vfn_4dc();
    virtual void vfn_4e0();
    virtual void vfn_4e4();
    virtual void vfn_4e8();
    virtual void vfn_4ec();
    virtual void vfn_4f0();
    virtual void vfn_4f4();
    virtual void vfn_4f8();
    virtual void vfn_4fc();
    virtual void vfn_500();
    virtual void vfn_504();
    virtual void vfn_508();
    virtual void vfn_50c();
    virtual void vfn_510();
    virtual void vfn_514();
    virtual void vfn_518();
    virtual void vfn_51c();
    virtual void vfn_520();
    virtual void vfn_524();
    virtual void vfn_528();
    virtual void vfn_52c();
    virtual void vfn_530();
    virtual void vfn_534();
    virtual void vfn_538();
    virtual void vfn_53c();
    virtual void vfn_540();
    virtual void vfn_544();
    virtual void vfn_548();
    virtual void vfn_54c();
    virtual void vfn_550();
    virtual void vfn_554();
    virtual void vfn_558();
    virtual void vfn_55c();
    virtual void vfn_560();
    virtual void vfn_564();
    virtual void vfn_568();
    virtual void vfn_56c();
    virtual void vfn_570();
    virtual void vfn_574();
    virtual void vfn_578();
    virtual void vfn_57c();
    virtual void vfn_580();
    virtual void vfn_584();
    virtual void vfn_588();
    virtual void vfn_58c();
    virtual void vfn_590();
    virtual void vfn_594();
    virtual void vfn_598();
    virtual void vfn_59c();
    virtual void vfn_5a0();
    virtual void vfn_5a4();
    virtual void vfn_5a8();
    virtual void vfn_5ac();
    virtual void vfn_5b0();
    virtual void vfn_5b4();
    virtual void vfn_5b8();
    virtual void vfn_5bc();
    virtual void vfn_5c0();
    virtual void vfn_5c4();
    virtual void vfn_5c8();
    virtual void vfn_5cc();
    virtual void vfn_5d0();
    virtual void vfn_5d4();
    virtual void vfn_5d8();
    virtual void vfn_5dc();
    virtual void vfn_5e0();
    virtual void vfn_5e4();
    virtual void vfn_5e8();
    virtual void vfn_5ec();
    virtual void vfn_5f0();
    virtual void vfn_5f4();
    virtual void vfn_5f8();
    virtual void vfn_5fc();
    virtual void vfn_600();
    virtual void vfn_604();
    virtual void vfn_608();
    virtual void vfn_60c();
    virtual void vfn_610();
    virtual void vfn_614();
    virtual void vfn_618();
    virtual void vfn_61c();
    virtual void vfn_620();
    virtual void vfn_624();
    virtual void vfn_628();
    virtual void vfn_62c();
    virtual void vfn_630();
    virtual void vfn_634();
    virtual void vfn_638();
    virtual void vfn_63c();
    virtual void vfn_640();
    virtual void vfn_644();
    virtual void vfn_648();
    virtual void vfn_64c();
    virtual void vfn_650();
    virtual void vfn_654();
    virtual void vfn_658();
    virtual void vfn_65c();
    virtual void vfn_660();
    virtual void vfn_664();
    virtual void vfn_668();
    virtual void vfn_66c();
    virtual void vfn_670();
    virtual void vfn_674();
    virtual void vfn_678();
    virtual void vfn_67c();
    virtual void vfn_680();
    virtual void vfn_684();
    virtual void vfn_688();
    virtual void vfn_68c();
    virtual void vfn_690();
    virtual void vfn_694();
    virtual void vfn_698();
    virtual void vfn_69c();
    virtual void vfn_6a0();
    virtual void vfn_6a4();
    virtual void vfn_6a8();
    virtual void vfn_6ac();
    virtual void vfn_6b0();
    virtual void vfn_6b4();
    virtual void vfn_6b8();
    virtual void vfn_6bc();
    virtual void vfn_6c0();
    virtual void vfn_6c4();
    virtual void vfn_6c8();
    virtual void vfn_6cc();
    virtual void vfn_6d0();
    virtual void vfn_6d4();
    virtual void vfn_6d8();
    virtual void vfn_6dc();
    virtual void vfn_6e0();
    virtual void vfn_6e4();
    virtual void vfn_6e8();
    virtual void vfn_6ec();
    virtual void vfn_6f0();
    virtual void vfn_6f4();
    virtual void vfn_6f8();
    virtual void vfn_6fc();
    virtual void vfn_700();
    virtual void vfn_704();
    virtual void vfn_708();
    virtual void vfn_70c();
    virtual void vfn_710();
    virtual void vfn_714();
    virtual void vfn_718();
    virtual void vfn_71c();
    virtual void vfn_720();
    virtual void vfn_724();
    virtual void vfn_728();
    virtual void vfn_72c();
    virtual void vfn_730();
    virtual void vfn_734();
    virtual void vfn_738();
    virtual void vfn_73c();
    virtual void vfn_740();
    virtual void vfn_744();
    virtual void vfn_748();
    virtual void vfn_74c();
    virtual void vfn_750();
    virtual void vfn_754();
    virtual void vfn_758(float);
};
struct Cls
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual ActorValue::Index GetActorValue();
    virtual void ApplyActorValueModifier(Actor*, float, ActorValue::Index);
    unsigned char field04[4];
    void* field08;
    EffectObj* pEffect;
    unsigned char field10[12];
    float m_fElapsedTime;
    float fDuration;
    void* pTarget;
    void* m_pEffectInstance;
    int m_eSpellType;
    unsigned char field30[24];
    int m_eActorValue;
    void ApplyEffect();
};

// @fnv 0x0082c810
void Cls::ApplyEffect()
{
    Actor* pActor =
        reinterpret_cast<::ActiveEffectFields *>(this)->target ? reinterpret_cast<::MagicTarget *>((((Obj822b40*)reinterpret_cast<::ActiveEffectFields *>(this)->target)))->GetOwnerActor() : 0;
    if (reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(pEffect)->setting))))->FUN_00403e60(2))
    {
        if (pActor != 0 && m_fElapsedTime > ::_DAT_01012060)
        {
            float fValue = reinterpret_cast<::ValueModifierEffect *>(this)->GetModifiedMagnitude(-m_fElapsedTime) + m_fElapsedTime;
            if (GetActorValue() == 0x10)
            {
                if (reinterpret_cast<::HealthReferenceEntry *>((((TESObjectREFR*)pActor)))->FUN_00568ad0() + fValue <= 1.0 + m_fElapsedTime)
                    fValue += 1.0;
            }
            if (fValue != ::_DAT_01012060)
            {
                pActor->DamageActorValue((ActorValue::Index)m_eActorValue, fValue,
                                         (reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)this)))->FUN_0045cd60())
                                             ? reinterpret_cast<::MagicCaster *>((((Obj815410*)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)this)))->FUN_0045cd60()))))->GetCasterActor()
                                             : 0);
            }
        }
        ApplyActorValueModifier(pActor, -m_fElapsedTime, (ActorValue::Index)-1);
        if (pActor != 0 && pActor->HasHealth(0) && (m_eActorValue == 0x10 || m_eActorValue == 7))
        {
            float fTemp = (float)((MyOwner*)&pActor->avOwner)->vfn_8(0x10);
            if (fTemp > ::_DAT_01012060)
                pActor->DamageActorValue((ActorValue::Index)0x10, -fTemp, 0);
        }
    }
    if (m_eActorValue == 0x36)
    {
        if (reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>(pEffect)->setting))))->FUN_00403e60(4))
        {
            if (pActor != 0 && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture())) != 0)
            {
                ((ProcObj*)((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture())))->vfn_758(::GetFloatAtOffset1C((char *)(((NiQuatTransform*)this))));
            }
            if (pActor == (Actor*)::_g_thePlayer)
                reinterpret_cast<::B968730Actor *>((((Obj968730*)::_g_thePlayer)))->FUN_00968730();
        }
    }
}

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
class MagicItem;
class NiAVObject;
class Script;
class TESFile;
class TESForm;
class TESModel;
class TESModelTextureSwap;
class TESObjectREFR;
struct FileEntryList;
struct DistantTreeTextureInfo;
struct LimbConditionEffect : public ValueModifierEffect
{
    virtual void __vslot_0();
    virtual ActiveEffect* Copy();
    virtual void CopyData(ActiveEffect*);
    static ActiveEffect* Instantiate(MagicCaster*, MagicItem*, EffectItem*);
    void SetLimbIndex(int);
    virtual unsigned short GetSaveSize(Actor*);
    virtual void SaveGame(BGSSaveFormBuffer*);
    virtual void SaveGame(Actor*);
    virtual void LoadGame(BGSLoadFormBuffer*);
    virtual void LoadGame(Actor*);
    virtual void ApplyActorValueModifier(Actor*, float, int);
    int m_eModifiedActorValue;
};
class BaseFormComponent
{
  public:
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
class TESFullName : public BaseFormComponent
{
  public:
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
class TESTexture : public BaseFormComponent
{
  public:
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
struct TESIcon : public TESTexture
{
    virtual char* GetTextureResourcePath();
    void* __vecDelDtor(unsigned int);
};
struct BGSMessageIcon : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    static void LoadMessageIcon(BGSMessageIcon*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    TESIcon* GetIcon();
    char* GetMessageIconTextureName();
    unsigned int GetMessageIconTextureNameLength();
    void SetMessageIconTextureName(char*);
    void* __vecDelDtor(unsigned int);
    TESIcon Icon;
};
struct TESScriptableForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static Script* GetScriptForForm(TESForm*);
    Script* GetScriptForForm();
    static char* GetFormScriptEditorID(TESForm*);
    char* GetFormScriptEditorID();
    static void SetFormScript(TESForm*, Script*);
    void SetFormScript(Script*);
    Script* m_pFormScript;
    bool m_bHasScript;
    char _pad_9[3];
};
struct TESWeightForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static float GetWeightForForm(TESForm*, bool);
    float GetWeightForForm();
    void SetFormWeight(float);
    void* __vecDelDtor(unsigned int);
    float fWeight;
};
struct FUN_0082c000_shell : public ValueModifierEffect
{
    void FUN_0082c000();
};

struct FUN_004029d0_shell
{
    bool FUN_004029d0(int);
};
struct FUN_004044d0_shell
{
    int FUN_004044d0();
};
// @fnv 0x0082c490
void LocalEffect::FUN_0082c490()
{
    Actor* target = ((::TargetGetter *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? reinterpret_cast<::MagicTarget *>((((::TargetGetter *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor() : 0;
    if (target == (Actor*)::_g_thePlayer && effect && reinterpret_cast<::FUN_004044d0_shell *>((effect))->FUN_004044d0() > 0 && which == 16)
    {
        float missing = ((LocalPlayer*)::_g_thePlayer)->values.base(16) - ((LocalPlayer*)::_g_thePlayer)->values.current(16);
        MagicItem* pMagicItem = ((::MagicItem *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell));
        bool potion = pMagicItem->GetSpellType() == 7;
        AlchemyItem* item = potion ? dynamic_cast<AlchemyItem*>(pMagicItem) : 0;
        if (item && reinterpret_cast<::FUN_004029d0_shell *>((item))->FUN_004029d0(2))
        {
            FUN_004d5e10(18, (int)FUN_0040ebd0(magnitude * reinterpret_cast<::FUN_004044d0_shell *>((effect))->FUN_004044d0(), missing));
        }
        if (item && reinterpret_cast<::FUN_004029d0_shell *>((item))->FUN_004029d0(4))
        {
            FUN_004d5e10(16, (int)FUN_0040ebd0(magnitude * reinterpret_cast<::FUN_004044d0_shell *>((effect))->FUN_004044d0(), missing));
        }
    }
}
struct BGSMessageInitAccess
{
    unsigned int GetIconFormID();
};

struct ActorValueOwnerVT
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual float GetActorValue(int);
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual float GetBaseActorValue(int);
};

struct ActorHead
{
    virtual void vfn_00();
    char padding04[0xa0];
};

struct ActorAV : public ActorHead, public ActorValueOwnerVT
{
};

struct ProcessRads
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual void vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void vfn_468();
    virtual void vfn_46c();
    virtual void vfn_470();
    virtual void vfn_474();
    virtual void vfn_478();
    virtual void vfn_47c();
    virtual void vfn_480();
    virtual void vfn_484();
    virtual void vfn_488();
    virtual void vfn_48c();
    virtual void vfn_490();
    virtual void vfn_494();
    virtual void vfn_498();
    virtual void vfn_49c();
    virtual void vfn_4a0();
    virtual void vfn_4a4();
    virtual void vfn_4a8();
    virtual void vfn_4ac();
    virtual void vfn_4b0();
    virtual void vfn_4b4();
    virtual void vfn_4b8();
    virtual void vfn_4bc();
    virtual void vfn_4c0();
    virtual void vfn_4c4();
    virtual void vfn_4c8();
    virtual void vfn_4cc();
    virtual void vfn_4d0();
    virtual void vfn_4d4();
    virtual void vfn_4d8();
    virtual void vfn_4dc();
    virtual void vfn_4e0();
    virtual void vfn_4e4();
    virtual void vfn_4e8();
    virtual void vfn_4ec();
    virtual void vfn_4f0();
    virtual void vfn_4f4();
    virtual void vfn_4f8();
    virtual void vfn_4fc();
    virtual void vfn_500();
    virtual void vfn_504();
    virtual void vfn_508();
    virtual void vfn_50c();
    virtual void vfn_510();
    virtual void vfn_514();
    virtual void vfn_518();
    virtual void vfn_51c();
    virtual void vfn_520();
    virtual void vfn_524();
    virtual void vfn_528();
    virtual void vfn_52c();
    virtual void vfn_530();
    virtual void vfn_534();
    virtual void vfn_538();
    virtual void vfn_53c();
    virtual void vfn_540();
    virtual void vfn_544();
    virtual void vfn_548();
    virtual void vfn_54c();
    virtual void vfn_550();
    virtual void vfn_554();
    virtual void vfn_558();
    virtual void vfn_55c();
    virtual void vfn_560();
    virtual void vfn_564();
    virtual void vfn_568();
    virtual void vfn_56c();
    virtual void vfn_570();
    virtual void vfn_574();
    virtual void vfn_578();
    virtual void vfn_57c();
    virtual void vfn_580();
    virtual void vfn_584();
    virtual void vfn_588();
    virtual void vfn_58c();
    virtual void vfn_590();
    virtual void vfn_594();
    virtual void vfn_598();
    virtual void vfn_59c();
    virtual void vfn_5a0();
    virtual void vfn_5a4();
    virtual void vfn_5a8();
    virtual void vfn_5ac();
    virtual void vfn_5b0();
    virtual void vfn_5b4();
    virtual void vfn_5b8();
    virtual void vfn_5bc();
    virtual void vfn_5c0();
    virtual void vfn_5c4();
    virtual void vfn_5c8();
    virtual void vfn_5cc();
    virtual void vfn_5d0();
    virtual void vfn_5d4();
    virtual void vfn_5d8();
    virtual void vfn_5dc();
    virtual void vfn_5e0();
    virtual void vfn_5e4();
    virtual void vfn_5e8();
    virtual void vfn_5ec();
    virtual void vfn_5f0();
    virtual void vfn_5f4();
    virtual void vfn_5f8();
    virtual void vfn_5fc();
    virtual void vfn_600();
    virtual void vfn_604();
    virtual void vfn_608();
    virtual void vfn_60c();
    virtual void vfn_610();
    virtual void vfn_614();
    virtual void vfn_618();
    virtual void vfn_61c();
    virtual void vfn_620();
    virtual void vfn_624();
    virtual void vfn_628();
    virtual void vfn_62c();
    virtual void vfn_630();
    virtual void vfn_634();
    virtual void vfn_638();
    virtual void vfn_63c();
    virtual void vfn_640();
    virtual void vfn_644();
    virtual void vfn_648();
    virtual void vfn_64c();
    virtual void vfn_650();
    virtual void vfn_654();
    virtual void vfn_658();
    virtual void vfn_65c();
    virtual void vfn_660();
    virtual void vfn_664();
    virtual void vfn_668();
    virtual void vfn_66c();
    virtual void vfn_670();
    virtual void vfn_674();
    virtual void vfn_678();
    virtual void vfn_67c();
    virtual void vfn_680();
    virtual void vfn_684();
    virtual void vfn_688();
    virtual void vfn_68c();
    virtual void vfn_690();
    virtual void vfn_694();
    virtual void vfn_698();
    virtual void vfn_69c();
    virtual void vfn_6a0();
    virtual void vfn_6a4();
    virtual void vfn_6a8();
    virtual void vfn_6ac();
    virtual void vfn_6b0();
    virtual void vfn_6b4();
    virtual void vfn_6b8();
    virtual void vfn_6bc();
    virtual void vfn_6c0();
    virtual void vfn_6c4();
    virtual void vfn_6c8();
    virtual void vfn_6cc();
    virtual void vfn_6d0();
    virtual void vfn_6d4();
    virtual void vfn_6d8();
    virtual void vfn_6dc();
    virtual void vfn_6e0();
    virtual void vfn_6e4();
    virtual void vfn_6e8();
    virtual void vfn_6ec();
    virtual void vfn_6f0();
    virtual void vfn_6f4();
    virtual void vfn_6f8();
    virtual void vfn_6fc();
    virtual void vfn_700();
    virtual void vfn_704();
    virtual void vfn_708();
    virtual void vfn_70c();
    virtual void vfn_710();
    virtual void vfn_714();
    virtual void vfn_718();
    virtual void vfn_71c();
    virtual void vfn_720();
    virtual void vfn_724();
    virtual void vfn_728();
    virtual void vfn_72c();
    virtual void vfn_730();
    virtual void vfn_734();
    virtual void vfn_738();
    virtual void vfn_73c();
    virtual void vfn_740();
    virtual void vfn_744();
    virtual void vfn_748();
    virtual void vfn_74c();
    virtual void vfn_750();
    virtual void SetRadsSec(float);
};

struct MiscStatManager
{
    enum MiscStat
    {
        MS_STIMPAKS_TAKEN = 0x10,
        MS_RAD_AWAY_TAKEN = 0x12
    };
    static void AddMiscStat(MiscStat, int);
};

namespace Local {
class PlayerCharacter
{
};
}


// Updates a modifier, may add misc stats or call Kill, and may update radiation rate and player effects.
// @fnv 0x0082c000
void FUN_0082c000_shell::FUN_0082c000()
{
    Actor* pActor = reinterpret_cast<::ActiveEffectFields *>(this)->target
                        ? ((MagicTarget*)reinterpret_cast<::ActiveEffectFields *>(this)->target)->GetOwnerActor()
                        : 0;

    if (reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>((*(EffectItem**)&this->pEffect))->setting))))->FUN_00403e60(2) ||
        (!(*(FUN_004044d0_shell**)&this->pEffect)->FUN_004044d0() && !((ActiveEffect*)this)->IsFlagged() &&
         ((BGSMessageInitAccess*)this)->GetIconFormID() != 4 && ((BGSMessageInitAccess*)this)->GetIconFormID() != 1))
    {
        this->m_fElapsedTime =
            ((ValueModifierEffect*)this)->GetModifiedMagnitude(this->m_fElapsedTime);
        if (this->m_eActorValue == 16 && pActor == (Actor*)::_g_thePlayer)
        {
            float fPlayerHealthDiff =
                ((ActorAV*)::_g_thePlayer)->GetBaseActorValue(16) - ((ActorAV*)::_g_thePlayer)->GetActorValue(16);
            MagicItem* pMagicItem = (MagicItem*)((::TESBoundObject *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell));
            bool bpotion = pMagicItem->GetSpellType() == 7;
            AlchemyItem* ppotion = bpotion ? dynamic_cast<AlchemyItem*>(pMagicItem) : 0;
            if (ppotion && reinterpret_cast<::FUN_004029d0_shell *>((ppotion))->FUN_004029d0(2))
                MiscStatManager::AddMiscStat((MiscStatManager::MiscStat)0x12,
                                             (int)FUN_0040ebd0(this->m_fElapsedTime, fPlayerHealthDiff));
            if (ppotion && reinterpret_cast<::FUN_004029d0_shell *>((ppotion))->FUN_004029d0(4))
                MiscStatManager::AddMiscStat((MiscStatManager::MiscStat)0x10,
                                             (int)FUN_0040ebd0(this->m_fElapsedTime, fPlayerHealthDiff));
        }
        if (this->m_eActorValue == 7 && this->m_fElapsedTime < ::_DAT_01012060 &&
            ((ActorAV*)pActor)->GetActorValue(16) <= 1.0)
        {
            Actor* pcasterActor = (reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)this)))->FUN_0045cd60())
                                      ? ((MagicCaster*)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)this)))->FUN_0045cd60()))->GetCasterActor()
                                      : 0;
            reinterpret_cast<::KillActor *>((pActor))->FUN_0089d900(pcasterActor, 0.0f);
        }
        ((ValueModifierEffect*)this)
            ->ApplyActorValueModifier(pActor, this->m_fElapsedTime, (ActorValue::Index)-1);
    }
    else if (pActor == (Actor*)::_g_thePlayer && (*(FUN_004044d0_shell**)&this->pEffect)->FUN_004044d0() > 0 &&
             this->m_eActorValue == 16)
    {
        float fPlayerHealthDiff =
            ((ActorAV*)::_g_thePlayer)->GetBaseActorValue(16) - ((ActorAV*)::_g_thePlayer)->GetActorValue(16);
        MagicItem* pMagicItem = (MagicItem*)((::TESBoundObject *)(reinterpret_cast<::ActiveEffectFields *>(this)->spell));
        bool bpotion = pMagicItem->GetSpellType() == 7;
        AlchemyItem* ppotion = bpotion ? dynamic_cast<AlchemyItem*>(pMagicItem) : 0;
        if (ppotion && reinterpret_cast<::FUN_004029d0_shell *>((ppotion))->FUN_004029d0(2))
            MiscStatManager::AddMiscStat(
                (MiscStatManager::MiscStat)0x12,
                (int)FUN_0040ebd0((*(FUN_004044d0_shell**)&this->pEffect)->FUN_004044d0() *
                                      this->m_fElapsedTime,
                                  fPlayerHealthDiff));
        if (ppotion && reinterpret_cast<::FUN_004029d0_shell *>((ppotion))->FUN_004029d0(4))
            MiscStatManager::AddMiscStat(
                (MiscStatManager::MiscStat)0x10,
                (int)FUN_0040ebd0((*(FUN_004044d0_shell**)&this->pEffect)->FUN_004044d0() *
                                      this->m_fElapsedTime,
                                  fPlayerHealthDiff));
    }

    if (this->m_eActorValue == 0x36 && reinterpret_cast<::S3e60 *>((((::EffectSetting *)(reinterpret_cast<::EffectItemFields *>((*(EffectItem**)&this->pEffect))->setting))))->FUN_00403e60(4))
    {
        if (pActor && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture())))
            ((ProcessRads*)((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture())))->SetRadsSec(GetFloatAtOffset1C((char*)this));
        if (pActor == (Actor*)::_g_thePlayer)
            reinterpret_cast<::B968730Actor *>((((Local::PlayerCharacter*)::_g_thePlayer)))->FUN_00968730();
    }
    ((ValueModifierEffect*)this)->RefreshPlayerActorValue();
}
