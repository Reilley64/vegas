
// src/fallout/magic/sundamageeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/sundamageeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/active_effect_fields.h"
#include "fnv/simple_list_node_view.h"
#include <new>
#include "fnv/decl/ActiveEffectLoader.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/EffectSaveShell.h"
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_00461310_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_00596030_cls.h"
#include "fnv/decl/FUN_00804f80_shell.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_00973fd0_cls.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_00454b10__TESObjectCELL.h"
#include "fnv/decl/fnv_00575d10__FUN_00575d10_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008a7d50__ActorHitOwner.h"
#include "fnv/decl/fnv_00974a50__FUN_00974a50_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_00595000.h"
#include "fnv/symbols_00644000.h"
#include "fnv/symbols_00966000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
struct Actor;
class EffectSetting;
struct ActiveEffect
{
public:
    ::EffectSetting *GetEffectSetting() const;
};
struct TESSaveLoadGame
{
};
struct SunDamageEffect : ActiveEffect
{
    unsigned short FUN_0082a390(Actor* apActor);
};

// @fnv 0x0082a390
unsigned short SunDamageEffect::FUN_0082a390(Actor* apActor)
{
    unsigned short usSize = 0;
    usSize += reinterpret_cast<::FUN_00804f80_shell *>(this)->FUN_00804f80(apActor);
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x71)
        usSize += 4;
    return usSize;
}

namespace fnv_0082a420 {
struct ActiveEffect
{
};

struct TESSaveLoadGame
{
};


struct FUN_0082a420_shell : ActiveEffect
{
    void FUN_0082a420(void* apActor);
};

// @fnv 0x0082a420
void FUN_0082a420_shell::FUN_0082a420(void* apActor)
{
    reinterpret_cast<::ActiveEffectLoader *>(this)->FUN_00805330((::Actor *)(apActor));
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_0082a420::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x71)
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0082a420::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0((char*)this + 0x48, 4);
}
}  // namespace fnv_0082a420

struct BSThread
{
};
struct PC7d
{
    char _pad[148];
};
struct S_0082a150
{
    double FUN_0082a1b0();
    bool FUN_0082a150();
};
// @fnv 0x0082a150
bool S_0082a150::FUN_0082a150()
{
    if (reinterpret_cast<::ActorMover *>((reinterpret_cast<BSThread*>(this)))->GetCurrentMoveModeType() ==
        ((*reinterpret_cast<::PC7d * *>(&::_g_thePlayer)) ? (uintptr_t)(reinterpret_cast<char*>((*reinterpret_cast<::PC7d * *>(&::_g_thePlayer))) + 0x94) : 0))
    {
        if (this->FUN_0082a1b0() > (double)0.01f)
            return true;
    }
    return false;
}

struct ActiveEffectSaveHelper
{
};
struct TESSaveLoadGameHelper
{
};
struct FUN_0082a3e0_shell : SunDamageEffect
{
    void SaveSunDamageEffect(Actor* apActor);
};
// @fnv 0x0082a3e0
void FUN_0082a3e0_shell::SaveSunDamageEffect(Actor* apActor)
{
    reinterpret_cast<::EffectSaveShell *>((((ActiveEffectSaveHelper*)this)))->FUN_008050d0(apActor);
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x71)
        reinterpret_cast<::FUN_008579b0_shell *>((((TESSaveLoadGameHelper*)g_TESSaveLoadGame)))->FUN_008579b0((char*)this + 0x48, 4);
}

struct MagicCaster;
struct MagicItem;
struct EffectItem;
struct FUN_0080bc70_base
{
    char _pad[72];
    FUN_0080bc70_base(MagicCaster*, MagicItem*, EffectItem*);
};
extern int DAT_0107c3ec;
struct FUN_00829a70 : FUN_0080bc70_base
{
    float f48;
    unsigned char b4c;
    unsigned char b4d;
    FUN_00829a70(MagicCaster*, MagicItem*, EffectItem*);
};
// Initializes the object: sets its vtable to DAT_0107c3ec and zeroes f48, b4d and b4c.
// @fnv 0x00829a70
FUN_00829a70::FUN_00829a70(MagicCaster* a, MagicItem* pItem, EffectItem* pEffect) : FUN_0080bc70_base(a, pItem, pEffect)
{
    *(void**)this = (void*)&DAT_0107c3ec;
    f48 = 0.0f;
    b4d = 0;
    b4c = 0;
}

struct MagicCaster;
struct MagicItem;
struct EffectItem;

struct AC0ActiveEffect
{

    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3C();
    virtual void vfunc40();
    virtual void CopyTo(AC0ActiveEffect* pkTarget);

    int unk04;
    MagicItem* pkItem;
    EffectItem* pkEffectItem;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    MagicCaster* pkCaster;
};

struct AC0ValueEffect : AC0ActiveEffect
{
    AC0ValueEffect(MagicCaster* apCaster, MagicItem* apItem, EffectItem* apEffectItem);

    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    float fValue;
    bool bFlag4C;
    bool bFlag4D;

    AC0ActiveEffect* FUN_00829ac0();
};

// Allocates a new AC0ValueEffect from the caster, item and effect item, copies base state into it, copies fValue and the two flags, and returns it.
// @fnv 0x00829ac0
AC0ActiveEffect* AC0ValueEffect::FUN_00829ac0()
{
    AC0ValueEffect* pkClone = new AC0ValueEffect(pkCaster, pkItem, pkEffectItem);
    CopyTo(pkClone);
    pkClone->fValue = fValue;
    pkClone->bFlag4C = bFlag4C;
    pkClone->bFlag4D = bFlag4D;
    return pkClone;
}

struct S_00829bb0_Cell
{
};

struct S_00829bb0_Val
{
    float FUN_004ed230(int a, float b, float c);
};

struct S_00829bb0_Proc
{
};

struct S_00829bb0_Actor
{
    virtual ~S_00829bb0_Actor();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338(float a, float b, int c);
};

struct S_00829bb0_Caster
{
    virtual void v00();
    virtual S_00829bb0_Actor* GetActor();
};

struct S_00829bb0_Setting
{
};

extern float DAT_011a14f8;

struct S_00829bb0_Eff : FUN_00829a70
{
    void UpdateEffect(float arg);
};

struct S_00829e00_Target;

struct S_00829e00_Caster
{
    virtual void v00();
    virtual S_00829e00_Target* GetTarget();
};

struct S_00829e00_Setting
{
};

// Hit effect applied to the target (0x6c bytes).
struct S_00829e00_HitEffect
{
    virtual ~S_00829e00_HitEffect();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual bool vC4();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    struct S_00829e00_ActiveEffect* pEffect;  // MagicHitEffect::pEffect
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
};

struct S_00829e00_Effect : S_00829e00_HitEffect
{
    S_00829e00_Effect(S_00829e00_Target* target, void* form, float duration);
};

struct S_00829e00_List
{
    S_00829e00_HitEffect* m_item;
    S_00829e00_List* m_next;
    S_00829e00_List(S_00829e00_HitEffect* const& item);
    ~S_00829e00_List();
    bool FUN_008256d0();
};

struct S_00829e00_Manager
{
};

struct S_00829e00_ActiveEffect
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    S_00829e00_List* m_effects;
    void FUN_00829e00(bool abApply);
};
// Toggles the effect based on the caster's actor and cell, and when the actor is DAT_011dea3c updates DAT_011a14f8 and blends proc values.
// @fnv 0x00829bb0
void S_00829bb0_Eff::UpdateEffect(float arg)
{
    if (b4d)
    {
        b4d = 0;
    }
    else if (((::S_00829bb0_Caster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) && ((::S_00829bb0_Caster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))->GetActor())
    {
        S_00829bb0_Actor* actor = ((::S_00829bb0_Caster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))->GetActor();
        S_00829bb0_Cell* cell = ((::S_00829bb0_Cell *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget()));
        if (reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((actor))->FUN_00575d10() && (!cell || !((bool)(reinterpret_cast<::fnv_00454b10::TESObjectCELL *>((cell))->GetFakeExterior()))))
        {
            reinterpret_cast<::S_00829e00_ActiveEffect *>(this)->FUN_00829e00(false);
            if (actor == (*reinterpret_cast<::S_00829bb0_Actor * *>(&::_g_thePlayer)))
                DAT_011a14f8 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_00829bb0_Setting *>(&::originalRuntimeFloatSetting1164))))));
        }
        else
        {
            S_00829bb0_Proc* proc;
            float f = reinterpret_cast<::S_0082a150 *>(this)->FUN_0082a1b0();
            reinterpret_cast<::S_00829e00_ActiveEffect *>(this)->FUN_00829e00(f > 0.01f);
            if (actor == (*reinterpret_cast<::S_00829bb0_Actor * *>(&::_g_thePlayer)))
            {
                if (f > 0.01f)
                {
                    (*reinterpret_cast<::S_00829bb0_Actor * *>(&::_g_thePlayer))->v338(f * arg, 0.0f, 0);
                    if (DAT_011a14f8 < 0.0)
                    {
                        reinterpret_cast<::fnv_008a7d50::ActorHitOwner *>(((*reinterpret_cast<::S_00829bb0_Actor * *>(&::_g_thePlayer))))->FUN_008a7d50(1, 1);
                        DAT_011a14f8 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_00829bb0_Setting *>(&::originalRuntimeFloatSetting1163))))));
                    }
                    else if (DAT_011a14f8 == 3.4028234663852886e+38)
                    {
                        DAT_011a14f8 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::S_00829bb0_Setting *>(&::originalRuntimeFloatSetting1164))))));
                    }
                    DAT_011a14f8 = DAT_011a14f8 - arg;
                }
                proc = ((::S_00829bb0_Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::S_00829bb0_Actor * *>(&::g_TES))))->GetBaseTexture()));
                float fValue = ((::S_00829bb0_Val *)(reinterpret_cast<::MagicCaster_shell *>((proc))->FUN_0044edb0())) ? ((::S_00829bb0_Val *)(reinterpret_cast<::MagicCaster_shell *>((proc))->FUN_0044edb0()))->FUN_004ed230(5, 1.0f, 0.0f) : 0.0f;
                if (((::S_00829bb0_Val *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((proc))->FUN_00825c00())))
                {
                    float w = ::FUN_006447d0((const char *)(proc));
                    fValue = fValue * w;
                    fValue += (1.0 - w) * ((::S_00829bb0_Val *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((proc))->FUN_00825c00()))->FUN_004ed230(5, 1.0f, 0.0f);
                }
            }
        }
    }
}

// @fnv 0x00829e00
void S_00829e00_ActiveEffect::FUN_00829e00(bool abApply)
{
    void* form = ((void *)(reinterpret_cast<::FUN_00407820_shell *>((((::S_00829e00_Setting *)(reinterpret_cast<::ActiveEffect *>(this)->GetEffectSetting()))))->FUN_00407820()));
    if (!form || !((::S_00829e00_Caster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) || ((int)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())) != 4)
        return;
    if (abApply)
    {
        if (!m_effects || m_effects->FUN_008256d0())
        {
            if (m_effects)
            {
                reinterpret_cast<::FileMatchList *>((m_effects))->RemoveAll();
                delete m_effects;
                m_effects = 0;
            }
            S_00829e00_Effect* effect = new S_00829e00_Effect(((::S_00829e00_Caster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))->GetTarget(), form, -1.0f);
            if (effect->vC4())
            {
                reinterpret_cast<::FUN_00973fd0_cls *>(&((*reinterpret_cast<::S_00829e00_Manager *>(&::g_011e0e80))))->FUN_00973fd0((::FnvArgObj *)(effect));
                m_effects = new S_00829e00_List(effect);
                effect->pEffect = this;
            }
            else
            {
                delete effect;
                effect = 0;
            }
        }
    }
    else if (m_effects)
    {
        S_00829e00_List* node = m_effects;
        while (node && !node->FUN_008256d0())
        {
            S_00829e00_HitEffect* item = *((::S_00829e00_HitEffect **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item));
            reinterpret_cast<::FUN_00461310_shell *>((item))->SetByteAt24(1);
            reinterpret_cast<::TESPackage *>((item))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(0));
            node = ((::S_00829e00_List *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        reinterpret_cast<::FileMatchList *>((m_effects))->RemoveAll();
        delete m_effects;
        m_effects = 0;
        reinterpret_cast<::fnv_00974a50::FUN_00974a50_shell *>(&((*reinterpret_cast<::S_00829e00_Manager *>(&::g_011e0e80))))->FUN_00974a50((::TESObjectREFR *)(::S_00829e00_Target *)(((::S_00829e00_Caster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))->GetTarget()), form);
    }
}

struct MagicCaster;
struct MagicItem;
struct EffectItem;
struct FUN_00829a70;

// Allocates and constructs a FUN_00829a70 from the given MagicCaster, MagicItem and EffectItem, returning the new object.
// @fnv 0x0082a0d0
FUN_00829a70* FUN_0082a0d0(MagicCaster* apCaster, MagicItem* apItem, EffectItem* apEffect)
{
    return new FUN_00829a70(apCaster, apItem, apEffect);
}

struct H_Fld
{
    char _pad0[8];
    float f8;
};
struct H_Calls;
struct H_Calls
{
    virtual H_Calls* v0() = 0;
    virtual H_Calls* v1() = 0;
    virtual H_Calls* v2() = 0;
    virtual H_Calls* v3() = 0;
    virtual H_Calls* v4() = 0;
    virtual H_Calls* v5() = 0;
    virtual H_Calls* v6() = 0;
    virtual H_Calls* v7() = 0;
    virtual H_Calls* v8() = 0;
    virtual H_Calls* v9() = 0;
    virtual H_Calls* v10() = 0;
    virtual H_Calls* v11() = 0;
    virtual H_Calls* v12() = 0;
    virtual H_Calls* v13() = 0;
    virtual H_Calls* v14() = 0;
    virtual H_Calls* v15() = 0;
    virtual H_Calls* v16() = 0;
    virtual H_Calls* v17() = 0;
    virtual H_Calls* v18() = 0;
    virtual H_Calls* v19() = 0;
    virtual H_Calls* v20() = 0;
    virtual H_Calls* v21() = 0;
    virtual H_Calls* v22() = 0;
    virtual H_Calls* v23() = 0;
    virtual H_Calls* v24() = 0;
    virtual H_Calls* v25() = 0;
    virtual H_Calls* v26() = 0;
    virtual H_Calls* v27() = 0;
    virtual H_Calls* v28() = 0;
    virtual H_Calls* v29() = 0;
    virtual H_Calls* v30() = 0;
    virtual H_Calls* v31() = 0;
    virtual H_Calls* v32() = 0;
    virtual H_Calls* v33() = 0;
    virtual H_Calls* v34() = 0;
    virtual H_Calls* v35() = 0;
    virtual H_Calls* v36() = 0;
    virtual H_Calls* v37() = 0;
    virtual H_Calls* v38() = 0;
    virtual H_Calls* v39() = 0;
    virtual H_Calls* v40() = 0;
    virtual H_Calls* v41() = 0;
    virtual H_Calls* v42() = 0;
    virtual H_Calls* v43() = 0;
    virtual H_Calls* v44() = 0;
    virtual H_Calls* v45() = 0;
    virtual H_Calls* v46() = 0;
    virtual H_Calls* v47() = 0;
    virtual H_Calls* v48() = 0;
    virtual H_Calls* v49() = 0;
    virtual H_Calls* v50() = 0;
    virtual H_Calls* v51() = 0;
    virtual H_Calls* v52() = 0;
    virtual H_Calls* v53() = 0;
    virtual H_Calls* v54() = 0;
    virtual H_Calls* v55() = 0;
    virtual H_Calls* v56() = 0;
    virtual H_Calls* v57() = 0;
    virtual H_Calls* v58() = 0;
    virtual H_Calls* v59() = 0;
    virtual H_Calls* v60() = 0;
    virtual H_Calls* v61() = 0;
    virtual H_Calls* v62() = 0;
    virtual H_Calls* v63() = 0;
    virtual H_Calls* v64() = 0;
    virtual H_Calls* v65() = 0;
    virtual H_Calls* v66() = 0;
    virtual H_Calls* v67() = 0;
    virtual H_Calls* v68() = 0;
    virtual H_Calls* v69() = 0;
    virtual H_Calls* v70() = 0;
    virtual H_Calls* v71() = 0;
    virtual H_Calls* v72() = 0;
    virtual H_Calls* v73() = 0;
    virtual H_Calls* v74() = 0;
    virtual H_Calls* v75() = 0;
    virtual H_Calls* v76() = 0;
    virtual H_Calls* v77() = 0;
    virtual H_Calls* v78() = 0;
    virtual H_Calls* v79() = 0;
    virtual H_Calls* v80() = 0;
    virtual H_Calls* v81() = 0;
    virtual H_Calls* v82() = 0;
    virtual H_Calls* v83() = 0;
    virtual H_Calls* v84() = 0;
    virtual H_Calls* v85() = 0;
    virtual H_Calls* v86() = 0;
    virtual H_Calls* v87() = 0;
    virtual H_Calls* v88() = 0;
    virtual H_Calls* v89() = 0;
    virtual H_Calls* v90() = 0;
    virtual H_Calls* v91() = 0;
    virtual H_Calls* v92() = 0;
    virtual H_Calls* v93() = 0;
    virtual H_Calls* v94() = 0;
    virtual H_Calls* v95() = 0;
    virtual H_Calls* v96() = 0;
    virtual H_Calls* v97() = 0;
    virtual H_Calls* v98() = 0;
    virtual H_Calls* v99() = 0;
    virtual H_Calls* v100() = 0;
    virtual H_Calls* v101() = 0;
    virtual H_Calls* v102() = 0;
    virtual H_Calls* v103() = 0;
    virtual H_Calls* v104() = 0;
    virtual H_Calls* v105() = 0;
    virtual H_Calls* v106() = 0;
    virtual H_Calls* v107() = 0;
    virtual H_Calls* v108() = 0;
    virtual H_Calls* v109() = 0;
    virtual H_Calls* v110() = 0;
    virtual H_Calls* v111() = 0;
    virtual H_Calls* v112() = 0;
    virtual H_Calls* v113() = 0;
    virtual H_Calls* v114() = 0;
    virtual H_Calls* v115() = 0;
    virtual H_Calls* v116() = 0;
    virtual H_Calls* v117() = 0;
    virtual H_Calls* v118() = 0;
    virtual H_Calls* v119() = 0;
    virtual H_Calls* v120() = 0;
    virtual H_Calls* v121() = 0;
    virtual H_Calls* v122() = 0;
    virtual H_Calls* v123() = 0;
    virtual H_Calls* v124() = 0;
    virtual H_Fld* v125() = 0;
    float FUN_004ed230(int, float, float);
};
float FUN_00649390(float, float, float, float, bool, float, bool);

// Calls FUN_00649390 with values read from this, DAT_011dea10, and p; returns 0.0 when the guard fails.
// @fnv 0x0082a1b0
double S_0082a150::FUN_0082a1b0()
{
    H_Calls* p;
    H_Calls* aQ;
    p = ((::H_Calls *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::H_Calls *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))->v1() : 0;
    aQ = p ? ((::H_Calls *)(reinterpret_cast<::LowProcess *>((p))->GetTarget())) : 0;
    if (p && (!reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((p))->FUN_00575d10() || (aQ && ((bool)(reinterpret_cast<::fnv_00454b10::TESObjectCELL *>((aQ))->GetFakeExterior())))))
    {
        bool b9;
        float f4;
        bool b11;
        float f18;
        float aF1c;
        H_Calls* obj;
        float vTmp;
        float v_;
        obj = ((::H_Calls *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((H_Calls*)(*reinterpret_cast<::S_00829bb0_Actor * *>(&::g_TES)))))->GetBaseTexture()));
        aF1c = ::GetFieldEC((const char *)(obj));
        f4 = ::FUN_00595ea0((char *)(obj));
        f18 = reinterpret_cast<::FUN_00596030_cls *>((obj))->FUN_00596030();
        b9 = true;
        vTmp = ((::H_Calls *)(reinterpret_cast<::MagicCaster_shell *>((obj))->FUN_0044edb0())) ? ((::H_Calls *)(reinterpret_cast<::MagicCaster_shell *>((obj))->FUN_0044edb0()))->FUN_004ed230(5, 1.0f, 0.0f) : 0.0f;
        if (((::H_Calls *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((obj))->FUN_00825c00())))
        {
            v_ = ::FUN_006447d0((const char *)(obj));
            vTmp = vTmp * v_;
            vTmp = (1.0 - v_) * ((::H_Calls *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((obj))->FUN_00825c00()))->FUN_004ed230(5, 1.0f, 0.0f) + vTmp;
        }
        b11 = false;
        if (reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((((::H_Calls *)(reinterpret_cast<::LowProcess *>((p))->GetTarget()))))->FUN_004518e0())
        {
            if (((double)(reinterpret_cast<::FUN_0057b0a0_shell *>((p))->FUN_0057b0a0())) >= p->v125()->f8)
                b11 = true;
        }
        return FUN_00649390(::GetFloatAtOffset1C((char *)(((H_Calls*)this))), aF1c, f4, f18, b9, vTmp, b11);
    }
    return 0.0;
}

#include "generated/data/fallout/magic/sundamageeffect.inc"
