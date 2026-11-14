
// src/fallout/magic/detectlifeeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/detectlifeeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x0080cec0
#include "fnv/active_effect_fields.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Cls.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00477ba0_shell.h"
#include "fnv/decl/FUN_0080d930.h"
#include "fnv/decl/FUN_0082c000_shell.h"
#include "fnv/decl/FUN_00973fd0_cls.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/fnv_00974a50__FUN_00974a50_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0080c000.h"
#include "fnv/symbols_0080d000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01079000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011dc000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
void __cdecl FUN_0080cec0()
{
    DAT_011dc034 = 0;
}

class TESEffectShader;


// @fnv 0x0080d0d0
TESEffectShader* __cdecl FUN_0080d0d0()
{
    return ::DAT_011c3588;
}

struct FUN_0080cd60_shell
{
    void* Destroy(unsigned int flags);
};
struct FUN_0080d930_shell
{
};
struct FUN_0080cd90_shell
{
    void FUN_0080cd90();
};
// Calls FUN_0080cd90, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0080cd60
void* FUN_0080cd60_shell::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_0080cd90_shell *>(this)->FUN_0080cd90();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x0080cd90
void FUN_0080cd90_shell::FUN_0080cd90()
{
    *reinterpret_cast<void**>(this) = &DAT_01079e7c;
    reinterpret_cast<::FUN_0080d930 *>((reinterpret_cast<FUN_0080d930_shell*>(this)))->FUN_0080d930::~FUN_0080d930();
}

struct BSThread
{
};
struct FUN_0082a670_shell
{
};
struct PC7d;
struct RetObj
{
    virtual void f0();
    virtual PC7d* f1();
};
struct DetectLifeEffect : FUN_0082a670_shell
{
    void FUN_0080ce60();
};
// @fnv 0x0080ce60
void DetectLifeEffect::FUN_0080ce60()
{
    reinterpret_cast<::FUN_0082c000_shell *>(this)->FUN_0082c000();
    if (((RetObj*)reinterpret_cast<::ActiveEffectFields *>(this)->target)->f1() == (*reinterpret_cast<::PC7d * *>(&::_g_thePlayer)))
        FUN_0080cec0();
}

namespace fnv_0080d0e0 {
struct BSThread
{
};
struct ValueModifierEffect
{
};
struct PC7d;
struct ActorWrapper
{
    virtual void Unk0();
    virtual PC7d* Unk1();
};
struct DetectLifeEffect : ValueModifierEffect
{
    void FUN_0080d0e0();
};
// @fnv 0x0080d0e0
void DetectLifeEffect::FUN_0080d0e0()
{
    reinterpret_cast<::Cls *>(this)->ApplyEffect();
    if (((ActorWrapper*)reinterpret_cast<::ActiveEffectFields *>(this)->target)->Unk1() == (*reinterpret_cast<::fnv_0080d0e0::PC7d * *>(&::_g_thePlayer)))
        FUN_0080cec0();
}
}  // namespace fnv_0080d0e0

class ActiveEffect;

struct SpawnedEffect
{
    unsigned int unk00[19];
    SpawnedEffect(int a, int b, int c);
};

struct FUN_0080cdb0_cls
{
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn0A();
    virtual void vfn0B();
    virtual void vfn0C();
    virtual void vfn0D();
    virtual void vfn0E();
    virtual void vfn0F();
    virtual void vfn10();
    virtual ActiveEffect* HookEffect(ActiveEffect* e);

    int unk04;
    int m_08;
    int m_0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_28;

    ActiveEffect* CreateSpawnedEffect();
};

// Allocates a SpawnedEffect from m_28, m_08 and m_0C, passes it to HookEffect, and returns it.
// @fnv 0x0080cdb0
ActiveEffect* FUN_0080cdb0_cls::CreateSpawnedEffect()
{
    ActiveEffect* e = (ActiveEffect*)new SpawnedEffect(m_28, m_08, m_0C);
    HookEffect(e);
    return e;
}

class TESEffectShader;
struct NiPoint3
{
    float x, y, z;
};
struct FUN_0045cd60_cls
{
};
struct Setting80c
{
};
struct Actor80c
{
    virtual ~Actor80c();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* GetPos();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool IsDead(int);
};
struct NiMemObject
{
};
struct FUN_0081f580 : public NiMemObject
{
    FUN_0081f580(Actor80c* pkRef, TESEffectShader* pkShader, float fTime);
    virtual ~FUN_0081f580();
    virtual void e01();
    virtual void e02();
    virtual void e03();
    virtual void e04();
    virtual void e05();
    virtual void e06();
    virtual void e07();
    virtual void e08();
    virtual void e09();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual void e14();
    virtual void e15();
    virtual void e16();
    virtual void e17();
    virtual void e18();
    virtual void e19();
    virtual void e20();
    virtual void e21();
    virtual void e22();
    virtual void e23();
    virtual void e24();
    virtual void e25();
    virtual void e26();
    virtual void e27();
    virtual void e28();
    virtual void e29();
    virtual void e30();
    virtual void e31();
    virtual void e32();
    virtual void e33();
    virtual void e34();
    virtual void e35();
    virtual void e36();
    virtual void e37();
    virtual void e38();
    virtual void e39();
    virtual void e40();
    virtual void e41();
    virtual void e42();
    virtual void e43();
    virtual void e44();
    virtual void e45();
    virtual void e46();
    virtual void e47();
    virtual void e48();
    virtual bool IsValid();
    int unk04[26];
};
struct Mgr80c
{
};
TESEffectShader* __cdecl FUN_0080d0d0();

// @fnv 0x0080ced0
bool __cdecl UpdateEffectShaderOnActor(Actor80c* pkRef, bool bStopEffect)
{
    TESEffectShader* pkShader2 = FUN_0080d0d0();
    if (!pkShader2 || !pkRef || pkRef == (*reinterpret_cast<::Actor80c * *>(&::_g_thePlayer)) || !((::FUN_0045cd60_cls *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pkRef))->GetBaseTexture())))
        return false;
    float fZero = 0.0f;
    float fDistSq = fZero * *((float *)&(::FUN_00403e20((::Setting *)&((*reinterpret_cast<::Setting80c *>(&::originalRuntimeFloatSetting1112))))));
    fDistSq *= fDistSq;
    NiPoint3 kPlayerPos9 = *(*reinterpret_cast<::Actor80c * *>(&::_g_thePlayer))->GetPos();
    if (reinterpret_cast<::TESCombatStyle *>((void *)(void *)&(const ::NiPoint3 &)(([&] { ::NiPoint3 difference; reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kPlayerPos9))->FUN_00439ef0((::NiPoint3 *)&difference, *(const ::NiPoint3 *)((::NiPoint3 *)&(*pkRef->GetPos()))); return difference; }())))->UpdateCombatStyle() < fDistSq && !pkRef->IsDead(0) &&
        !(reinterpret_cast<::FUN_0045cd60_shell *>((((::FUN_0045cd60_cls *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pkRef))->GetBaseTexture()))))->FUN_0045cd60()) && !reinterpret_cast<::FUN_00477ba0_shell *>((pkRef))->FUN_00477ba0())
    {
        if (!bStopEffect)
        {
            FUN_0081f580* pkEffect = new FUN_0081f580(pkRef, pkShader2, ::DAT_01012054);
            if (pkEffect->IsValid())
                reinterpret_cast<::FUN_00973fd0_cls *>(&((*reinterpret_cast<::Mgr80c *>(&::g_011e0e80))))->FUN_00973fd0((::FnvArgObj *)(pkEffect));
            else
                delete pkEffect;
        }
        return true;
    }
    else
    {
        if (bStopEffect)
            reinterpret_cast<::fnv_00974a50::FUN_00974a50_shell *>(&((*reinterpret_cast<::Mgr80c *>(&::g_011e0e80))))->FUN_00974a50((::TESObjectREFR *)(pkRef), pkShader2);
        return false;
    }
}

#include "generated/data/fallout/magic/detectlifeeffect.inc"
