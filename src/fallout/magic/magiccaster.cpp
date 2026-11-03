// fallout/magic/magiccaster.cpp: MagicCaster, Caster, ScriptLocalsX, CastingCheck and more (34 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/EffectItemList.h"
#include "fnv/decl/FUN_004029d0_shell.h"
#include "fnv/decl/FUN_00403e80_shell.h"
#include "fnv/decl/FUN_00403f00_shell.h"
#include "fnv/decl/FUN_00404420_shell.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00445300_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004a51b0_shell.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00689920_shell.h"
#include "fnv/decl/FUN_00693d50_shell.h"
#include "fnv/decl/FUN_0080fcc0_class.h"
#include "fnv/decl/FUN_00824e70_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00981920_Class.h"
#include "fnv/decl/FUN_009d9f40_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FlaggedData.h"
#include "fnv/decl/HealthReferenceEntry.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/Master.h"
#include "fnv/decl/NiTransform.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/PlayerMover.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S86a0.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/ShadowLightData.h"
#include "fnv/decl/TESGrass.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00405f30__EILStandIn.h"
#include "fnv/decl/fnv_00405fe0__EffectItemList.h"
#include "fnv/decl/fnv_004064d0__EffectItemList.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00490e40__FUN_00490e40_shell.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_004b4ea0__TESDataHandler.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00572380__Fn572380.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00818ba0__MagicFogProjectile.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008808a0__ActorProxy.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00405000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00409000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b6000.h"
#include "fnv/symbols_005b9000.h"
#include "fnv/symbols_005c5000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00648000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_00689000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00804000.h"
#include "fnv/symbols_009a6000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "magiccaster_private_match.h"

// Handoff for the remaining four functions of this unit (all decoded, none
// attempted): 0x815B00 RemoveCastingArt calls GetCasterActor plus slots
// +0x34/+0x24/+0x40/+0x48 and direct callees 0x453470, 0x4DEF90, 0x80FCC0
// 0x48CEE0, 0x445300 (global 0x11C3B3C). 0x815C50 HasActiveEffect does
// dynamic_cast (via __RTDynamicCast at 0xEC43FB with RTTI refs 0x11A1224 /
// bool(MagicTarget*, NiPoint3, MagicItem*, ActiveEffect*, bool)) with a
// global NiPoint3 at 0x11F426C whose name is still unknown. 0x818C60
// 0x4839C0) then GetIsReference (+0xF0) then TESObjectREFR::GetMagicCaster
// (+0x198); the canonical TESObjectREFR.h lacks that name (its slot-102
// virtual is currently Unk_66). 0x815D00 LaunchMagicProjectile is the 4611-byte
// dispatcher with EH/GS frames and dozens of callees.

// @fnv 0x00815410
Actor* MagicCaster::GetCasterActor()
{
    TESObjectREFR* pStatsObject = GetCasterReference();
    return (pStatsObject && pStatsObject->IsActor()) ? (Actor*)this : NULL;
}

// @fnv 0x00815600
void MagicCaster::CastSpellOnCaster(SpellItem* pSpell, bool bImmediate)
{
    if (pSpell->GetSpellType() == MagicSystem__SpellType_ABILITY)
    {
        SetSelectedMagicItem(pSpell);
        LaunchMagicProjectile(0.0f, NULL, bImmediate, 1.0f, false);
    }
}

// @fnv 0x00815740
void MagicCaster::CastMagicItem(MagicItem* pItem, bool bArg1, MagicTarget* pTarget, float fValue, bool bArg2)
{
    if (pTarget)
        SetMagicTarget(pTarget);
    SetSelectedMagicItem(pItem);
    LaunchMagicProjectile(0.0f, NULL, bArg1, fValue, bArg2);
}

// @fnv 0x008157a0
void MagicCaster::CastSpellAtTarget(SpellItem* pSpell, MagicTarget* pTarget, bool bImmediate)
{
    if (pSpell->GetSpellType() == MagicSystem__SpellType_DISEASE && pTarget)
    {
        SetSelectedMagicItem(pSpell);
        LaunchMagicProjectile(0.0f, NULL, bImmediate, 1.0f, false);
    }
}

// Forwards the caster, item, effect and source to Activate and returns the resulting ActiveEffect.
// @fnv 0x00815cd0
ActiveEffect* MagicCaster::CreateActiveEffect(MagicItem* pItem, EffectItem* pEffect, TESBoundObject* pSource)
{
    return MagicEffectSystem::Activate(this, pItem, pEffect, pSource);
}

// @fnv 0x00818af0
void MagicCaster::SetState(MagicCaster__State state, char* reason)
{
    eState = state;
}

// Qualified covered-body mapping; position is unused in the original.
// @fnv 0x00817940
bool MagicCaster::AddEffectToTarget(MagicTarget* target, NiPoint3 position, MagicItem* spell, ActiveEffect* effect,
                                    bool immediate)
{
    return target->AddEffectToTarget(this, spell, effect, immediate);
}

// @fnv 0x00815c50
bool MagicCaster::HasActiveEffect(ActiveEffect* effect)
{
    MagicTarget* pTarget;
    bool bRetVal = false;
    pTarget = dynamic_cast<MagicTarget*>(this);
    if (pTarget)
    {
        bRetVal = AddEffectToTarget(pTarget, NiPoint3::ZERO, GetSelectedMagicItem(), effect, false);
    }
    return bRetVal;
}

// Looks up the form by formID, and if it is a reference, returns that reference's magic caster; otherwise returns NULL.
// @fnv 0x00818c60
MagicCaster* MagicCaster::GetCasterByHandle(unsigned int formID)
{
    TESForm* form = ::FUN_004839c0(formID);
    if (form && form->GetIsReference())
    {
        TESObjectREFR* reference = static_cast<TESObjectREFR*>(form);
        return reference->GetMagicCaster();
    }
    return NULL;
}

// @fnv 0x00815b00
void MagicCaster::RemoveCastingArt()
{
    Actor* actor = GetCasterActor();
    bool hadNode = false;
    NiNode* effect;
    if (actor)
    {
        effect = actor->GetMagicNode();
        if (effect && (unsigned int)reinterpret_cast<::FUN_00453470_shell *>((effect))->FUN_00453470() > 0)
        {
            hadNode = true;
            reinterpret_cast<::FUN_004def90_Class *>((effect))->FUN_004def90();
        }
        if (apTargetLight)
        {
            MagicEffectCollection* light = apTargetLight;
            MagicEffectCollection* deletingLight = light;
            deletingLight ? reinterpret_cast<::FUN_0080fcc0_class *>((deletingLight))->FUN_0080fcc0(1) : 0;
        }
        apTargetLight = NULL;
    }
    EffectSetting* node;
    if (!GetSelectedMagicItem())
        return;
    SetState(MagicCaster__State_ERR_CANNOT_CAST, "Cannot Cast");
    SpellCast(GetSelectedMagicItem(), false);
    if (hadNode)
    {
        node = GetSelectedMagicItem()->GetEffectSettingForRange((MagicSystem::Range)0);
        if (node && node->GetModelLength() > 0)
            reinterpret_cast<::FUN_00445300_shell *>((g_modelLoader))->FUN_00445300((char *)(node->GetModelFilePath()), false, 1);
    }
    SetSelectedMagicItem(NULL);
    SetMagicTarget(NULL);
}

struct bhkFilter
{
    int v;
    bhkFilter();
};
struct bhkWorldObject
{
    bhkFilter FUN_0043b4f0();
};
struct BSS819
{
    operator bhkWorldObject*() const;
};
struct S819
{
    char p[0x594];
    BSS819 s;
    int FUN_00819250();
};
// @fnv 0x00819250
int S819::FUN_00819250()
{
    return ((bhkWorldObject*)s) ? ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::bhkFilter &)(((bhkWorldObject*)s)->FUN_0043b4f0()))->FUN_004a3a20())) : 0;
}

struct MagicCaster_shell : MagicCaster
{
    MagicTarget* pTarget;
    MagicTarget* FUN_0044edb0();
};

// @fnv 0x0044edb0
MagicTarget* MagicCaster_shell::FUN_0044edb0()
{
    return *(MagicTarget**)((char*)this + 0x10);
}

struct FUN_008153a0_shell
{
    float FUN_008153a0(bool abJustArmor, float afUseThisFatigue);
};

// @fnv 0x008153a0
float FUN_008153a0_shell::FUN_008153a0(bool abJustArmor, float afUseThisFatigue)
{
    return 1.0f;
}

struct FUN_00818cb0_shell
{
    bool __thiscall FUN_00818cb0(MagicItem* apSpell, float* afEffectStrength, MagicItem::CannotCastReason* apReason,
                                 bool abUseBaseMagicka);
};

// Initializes the optional effect strength to 1.0 and the reason to 0, then returns true.
// @fnv 0x00818cb0
bool __thiscall FUN_00818cb0_shell::FUN_00818cb0(MagicItem* apSpell, float* afEffectStrength,
                                                 MagicItem::CannotCastReason* apReason, bool abUseBaseMagicka)
{
    if (afEffectStrength)
        *afEffectStrength = 1.0f;
    if (apReason)
        *apReason = 0;
    return true;
}

struct FUN_008156e0_This : MagicCaster
{
    void FUN_008156e0(SpellItem* apSpell, bool abLoadCast);
};
// @fnv 0x008156e0
void FUN_008156e0_This::FUN_008156e0(SpellItem* apSpell, bool abLoadCast)
{
    SetSelectedMagicItem(apSpell);
    LaunchMagicProjectile(0.0F, 0, abLoadCast, 1.0F, 0);
}

struct ProxyFor15820
{
    void FUN_00815820(MagicItem* apSpell, TESBoundObject* apSource, bool abLoadCast);
};
// @fnv 0x00815820
void ProxyFor15820::FUN_00815820(MagicItem* apSpell, TESBoundObject* apSource, bool abLoadCast)
{
    if (apSpell == 0)
        return;
    ((MagicCaster*)this)->SetSelectedMagicItem(apSpell);
    ((MagicCaster*)this)->LaunchMagicProjectile(0.0f, apSource, abLoadCast, 1.0f, false);
}

struct ScriptLocalsX
{
    void* FUN_00818110();
};
struct FUN_0045c650_shell
{
    void* FUN_0045c650();
};
// @fnv 0x00818110
void* ScriptLocalsX::FUN_00818110()
{
    void* p = ((void *)(::FUN_004ae750((void *)this)));
    return p ? ((FUN_0045c650_shell*)p)->FUN_0045c650() : 0;
}

extern "C" void __cdecl TryCast(void*);

struct FUN_00815380_shell
{
    void __thiscall TryCast(int);
    void __thiscall FUN_00815380();
};

struct ActorVT
{
    virtual void A0();
    virtual void A1();
    virtual void A2();
    virtual void A3();
    virtual void A4();
    virtual void A5();
    virtual void A6();
    virtual void A7();
    virtual void A8();
    virtual void A9();
    virtual void A10();
    virtual void A11();
    virtual void A12();
    virtual void A13();
    virtual void A14();
    virtual void A15();
    virtual void A16();
    virtual void A17();
    virtual void A18();
    virtual void A19();
    virtual void A20();
    virtual void A21();
    virtual void A22();
    virtual void A23();
    virtual void A24();
    virtual void A25();
    virtual void A26();
    virtual void A27();
    virtual void A28();
    virtual void A29();
    virtual void A30();
    virtual void A31();
    virtual void A32();
    virtual void A33();
    virtual void A34();
    virtual void A35();
    virtual void A36();
    virtual void A37();
    virtual void A38();
    virtual void A39();
    virtual void A40();
    virtual void A41();
    virtual void A42();
    virtual void A43();
    virtual void A44();
    virtual void A45();
    virtual void A46();
    virtual void A47();
    virtual void A48();
    virtual void A49();
    virtual void A50();
    virtual void A51();
    virtual void A52();
    virtual void A53();
    virtual void A54();
    virtual void A55();
    virtual void A56();
    virtual void A57();
    virtual void A58();
    virtual void A59();
    virtual void A60();
    virtual void A61();
    virtual void A62();
    virtual void A63();
    virtual void A64();
    virtual void A65();
    virtual void A66();
    virtual void A67();
    virtual void A68();
    virtual void A69();
    virtual void A70();
    virtual void A71();
    virtual void A72();
    virtual void A73();
    virtual void A74();
    virtual void A75();
    virtual void A76();
    virtual void A77();
    virtual void A78();
    virtual void A79();
    virtual void A80();
    virtual void A81();
    virtual void A82();
    virtual void A83();
    virtual void A84();
    virtual void A85();
    virtual void A86();
    virtual void A87();
    virtual void A88();
    virtual void A89();
    virtual void A90();
    virtual void A91();
    virtual void A92();
    virtual void A93();
    virtual void A94();
    virtual void A95();
    virtual void A96();
    virtual void A97();
    virtual void A98();
    virtual void A99();
    virtual void A100();
    virtual void A101();
    virtual void A102();
    virtual void A103();
    virtual void A104();
    virtual void A105();
    virtual void A106();
    virtual void A107();
    virtual void A108();
    virtual void A109();
    virtual void A110();
    virtual void A111();
    virtual void A112();
    virtual void A113();
    virtual void A114();
    virtual void A115();
    virtual void A116();
    virtual void A117();
    virtual void A118();
    virtual void A119();
    virtual void A120();
    virtual void A121();
    virtual void A122();
    virtual void A123();
    virtual void A124();
    virtual void A125();
    virtual void A126();
    virtual void A127();
    virtual void A128();
    virtual void A129();
    virtual void A130();
    virtual void A131();
    virtual void A132();
    virtual void A133();
    virtual void A134();
    virtual void A135();
    virtual void A136();
    virtual void A137();
    virtual void A138();
    virtual bool V139(int);
    virtual void A140();
    virtual void A141();
    virtual void A142();
    virtual void A143();
    virtual void A144();
    virtual void A145();
    virtual void A146();
    virtual void A147();
    virtual void A148();
    virtual void A149();
    virtual void A150();
    virtual void A151();
    virtual void A152();
    virtual void A153();
    virtual void A154();
    virtual void A155();
    virtual void A156();
    virtual void A157();
    virtual void A158();
    virtual void A159();
    virtual void A160();
    virtual void A161();
    virtual void A162();
    virtual void A163();
    virtual void A164();
    virtual void A165();
    virtual void A166();
    virtual void A167();
    virtual void A168();
    virtual void A169();
    virtual void A170();
    virtual void A171();
    virtual void A172();
    virtual void A173();
    virtual void A174();
    virtual void A175();
    virtual void A176();
    virtual void A177();
    virtual void A178();
    virtual void A179();
    virtual void A180();
    virtual void A181();
    virtual void A182();
    virtual void A183();
    virtual void A184();
    virtual void A185();
    virtual void A186();
    virtual void A187();
    virtual void A188();
    virtual void A189();
    virtual void A190();
    virtual void A191();
    virtual void A192();
    virtual void A193();
    virtual void A194();
    virtual void A195();
    virtual void A196();
    virtual void A197();
    virtual void A198();
    virtual void A199();
    virtual void A200();
    virtual void A201();
    virtual void A202();
    virtual void A203();
    virtual void A204();
    virtual void A205();
    virtual void A206();
    virtual void A207();
    virtual void A208();
    virtual void A209();
    virtual void A210();
    virtual void A211();
    virtual void A212();
    virtual void A213();
    virtual void A214();
    virtual void A215();
    virtual void A216();
    virtual void A217();
    virtual void A218();
    virtual void A219();
    virtual void A220();
    virtual void A221();
    virtual void A222();
    virtual void A223();
    virtual float V224();
};
struct ActorV_S
{
};
struct Setting_S
{
};
struct TgtOps
{
    void* GetPosition();
};
struct TESResponse
{
};
struct TES
{
};
struct MobileObjectProcessArray
{
};
namespace S {
struct BSSimpleList
{
};
}
class Character : public Actor
{
};

struct FUN_00817620_shell : MagicCaster
{
    MagicTarget* FindClosestMagicTarget();
};

extern int DAT_0107ac5c;

class FUN_008153b0_cls
{
  public:
    void* m_vtbl;
    MagicEffectCollection* m_pLight;
    void FUN_008153b0();
};

// @fnv 0x008153b0
void FUN_008153b0_cls::FUN_008153b0()
{
    MagicEffectCollection* target;
    MagicEffectCollection* light;
    m_vtbl = (void*)&DAT_0107ac5c;
    if (m_pLight != 0)
    {
        target = m_pLight;
        light = target;
        (light != 0) ? reinterpret_cast<::FUN_0080fcc0_class *>((light))->FUN_0080fcc0(1) : 0;
    }
    m_pLight = 0;
}

struct ChildCell
{
    virtual void Unk_00(void);
    virtual void Unk_01(void);
    virtual void Unk_02(void);
    virtual void Unk_03(void);
    virtual void Unk_04(void);
    virtual void Unk_05(void);
    virtual int Unk_06(void);
};

struct RefShell
{
    char unk00[0x18];
    ChildCell child;
};

struct FUN_00815670_cls
{
    virtual void Unk_00(void);
    virtual void Unk_01(void);
    virtual void Unk_02(void);
    virtual void Unk_03(void);
    virtual void Unk_04(void);
    virtual void Unk_05(void);
    virtual void Unk_06(void);
    virtual void Unk_07(void);
    virtual void Unk_08(void);
    virtual void Unk_09(void);
    virtual void Unk_0A(void);
    virtual void Unk_0B(void);
    virtual void Unk_0C(void);
    virtual void Unk_0D(void);
    virtual void Unk_0E(void);
    virtual void Unk_0F(void);
    virtual void Unk_10(ChildCell* target);
    void FUN_00815d00(float a1, int a2, bool a3, float a4, int a5);
    void FUN_00815670(RefShell* ref, bool flag);
};

// @fnv 0x00815670
void FUN_00815670_cls::FUN_00815670(RefShell* ref, bool flag)
{
    if (ref->child.Unk_06() == 10)
    {
        Unk_10(ref ? &ref->child : 0);
        FUN_00815d00(0.0f, 0, flag, 1.0f, 0);
    }
}

class B8182D0Target
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void Apply(void* pvArg);
};

class B8182D0Object
{
  public:
    void ApplyToTarget(void* pvArg);
};

// Calls FUN_00c9c1d0, then gets the target via FUN_009d9f40 and calls its Apply with pvArg.
// @fnv 0x008182d0
void B8182D0Object::ApplyToTarget(void* pvArg)
{
    reinterpret_cast<::hkpEntityC9C *>(this)->FUN_00c9c1d0();
    ((::B8182D0Target *)(reinterpret_cast<::FUN_009d9f40_Class *>(this)->FUN_009d9f40()))->Apply(pvArg);
}

// Update the owned effect; drop it once it has finished (unless this owner keeps finished effects).

class B8B10Effect
{
  public:
    ~B8B10Effect();
};

class B8B10Owner
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual int KeepsFinishedEffects();

    B8B10Effect* m_pkEffect;

    void UpdateEffect(float fTime);
};

// Updates m_pkEffect with fTime and deletes it when finished effects are not kept and the effect is no longer active.
// @fnv 0x00818b10
void B8B10Owner::UpdateEffect(float fTime)
{
    if (m_pkEffect)
    {
        reinterpret_cast<::MagicEffectCollection *>((m_pkEffect))->UpdateLightFade(fTime);
        if (!KeepsFinishedEffects() && !reinterpret_cast<::fnv_00818ba0::MagicFogProjectile *>((m_pkEffect))->IsAboveZero())
        {
            delete m_pkEffect;
            m_pkEffect = 0;
        }
    }
}

struct EmbV
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void* v11();
};

struct OuterB
{
    int unk00;
    int unk04;
    int unk08;
    EmbV emb;
};

struct Callee00815410
{
};

struct Callee0084e3a0
{
};

extern int DAT_01184638;
extern int DAT_011a1224;
void* __cdecl FUN_00ec43fb(void* a0, int a1, int* a2, int* a3, int a4);

struct FUN_00818be0_cls
{
    void* FUN_00818be0();
};

// @fnv 0x00818be0
void* FUN_00818be0_cls::FUN_00818be0()
{
    void* a = ((void *)(reinterpret_cast<::MagicCaster *>((((Callee00815410*)this)))->GetCasterActor()));
    OuterB* b = (OuterB*)FUN_00ec43fb(this, 0, &DAT_011a1224, &DAT_01184638, 0);
    if (a != 0)
    {
        return ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((Callee0084e3a0*)a)))->FUN_0084e3a0()));
    }
    else
    {
        if (b != 0)
        {
            if (b->emb.v11() != 0)
            {
                return ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((Callee0084e3a0*)b->emb.v11())))->FUN_0084e3a0()));
            }
        }
    }
    return 0;
}

struct FeedbackString
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    ~FeedbackString();
};
struct BSSoundHandleEx
{
    unsigned int soundID;
    unsigned int state;
    unsigned int flags;
    ~BSSoundHandleEx();
};
struct FeedbackActor
{
    virtual void Unk000();
    virtual void Unk001();
    virtual void Unk002();
    virtual void Unk003();
    virtual void Unk004();
    virtual void Unk005();
    virtual void Unk006();
    virtual void Unk007();
    virtual void Unk008();
    virtual void Unk009();
    virtual void Unk010();
    virtual void Unk011();
    virtual void Unk012();
    virtual void Unk013();
    virtual void Unk014();
    virtual void Unk015();
    virtual void Unk016();
    virtual void Unk017();
    virtual void Unk018();
    virtual void Unk019();
    virtual void Unk020();
    virtual void Unk021();
    virtual void Unk022();
    virtual void Unk023();
    virtual void Unk024();
    virtual void Unk025();
    virtual void Unk026();
    virtual void Unk027();
    virtual void Unk028();
    virtual void Unk029();
    virtual void Unk030();
    virtual void Unk031();
    virtual void Unk032();
    virtual void Unk033();
    virtual void Unk034();
    virtual void Unk035();
    virtual void Unk036();
    virtual void Unk037();
    virtual void Unk038();
    virtual void Unk039();
    virtual void Unk040();
    virtual void Unk041();
    virtual void Unk042();
    virtual void Unk043();
    virtual void Unk044();
    virtual void Unk045();
    virtual void Unk046();
    virtual void Unk047();
    virtual void Unk048();
    virtual void Unk049();
    virtual void Unk050();
    virtual void Unk051();
    virtual void Unk052();
    virtual void Unk053();
    virtual void Unk054();
    virtual void Unk055();
    virtual void Unk056();
    virtual void Unk057();
    virtual void Unk058();
    virtual void Unk059();
    virtual void Unk060();
    virtual void Unk061();
    virtual void Unk062();
    virtual void Unk063();
    virtual void Unk064();
    virtual void Unk065();
    virtual void Unk066();
    virtual void Unk067();
    virtual void Unk068();
    virtual void Unk069();
    virtual void Unk070();
    virtual void Unk071();
    virtual void Unk072();
    virtual void Unk073();
    virtual void Unk074();
    virtual void Unk075();
    virtual void Unk076();
    virtual void Unk077();
    virtual void Unk078();
    virtual void Unk079();
    virtual void Unk080();
    virtual void Unk081();
    virtual void Unk082();
    virtual void Unk083();
    virtual void Unk084();
    virtual void Unk085();
    virtual void Unk086();
    virtual void Unk087();
    virtual void Unk088();
    virtual void Unk089();
    virtual void Unk090();
    virtual void Unk091();
    virtual void Unk092();
    virtual void Unk093();
    virtual void Unk094();
    virtual void Unk095();
    virtual void Unk096();
    virtual void Unk097();
    virtual void Unk098();
    virtual void Unk099();
    virtual void Unk100();
    virtual void Unk101();
    virtual void Unk102();
    virtual void Unk103();
    virtual void Unk104();
    virtual void Unk105();
    virtual void Unk106();
    virtual void Unk107();
    virtual void Unk108();
    virtual void Unk109();
    virtual void Unk110();
    virtual void Unk111();
    virtual void Unk112();
    virtual void Unk113();
    virtual void Unk114();
    virtual void Unk115();
    virtual void Unk116();
    virtual void Unk117();
    virtual void Unk118();
    virtual void Unk119();
    virtual void Unk120();
    virtual void Unk121();
    virtual void Unk122();
    virtual void Unk123();
    virtual void Unk124();
    virtual void Unk125();
    virtual void Unk126();
    virtual void Unk127();
    virtual void Unk128();
    virtual void Unk129();
    virtual void Unk130();
    virtual void Unk131();
    virtual void Unk132();
    virtual void Unk133();
    virtual void Unk134();
    virtual void Unk135();
    virtual void Unk136();
    virtual void Unk137();
    virtual void Unk138();
    virtual void Unk139();
    virtual void Unk140();
    virtual void Unk141();
    virtual void Unk142();
    virtual void Unk143();
    virtual void Unk144();
    virtual void Unk145();
    virtual void Unk146();
    virtual void Unk147();
    virtual void Unk148();
    virtual void Unk149();
    virtual void Unk150();
    virtual void Unk151();
    virtual void Unk152();
    virtual void Unk153();
    virtual void Unk154();
    virtual void Unk155();
    virtual void Unk156();
    virtual void Unk157();
    virtual void Unk158();
    virtual void Unk159();
    virtual void Unk160();
    virtual void Unk161();
    virtual void Unk162();
    virtual void Unk163();
    virtual void Unk164();
    virtual void Unk165();
    virtual void Unk166();
    virtual void Unk167();
    virtual void Unk168();
    virtual void Unk169();
    virtual void Unk170();
    virtual void Unk171();
    virtual void Unk172();
    virtual void Unk173();
    virtual void Unk174();
    virtual void Unk175();
    virtual void Unk176();
    virtual void Unk177();
    virtual void Unk178();
    virtual void Unk179();
    virtual void Unk180();
    virtual void Unk181();
    virtual void Unk182();
    virtual void Unk183();
    virtual void Unk184();
    virtual void Unk185();
    virtual void Unk186();
    virtual void Unk187();
    virtual void Unk188();
    virtual void Unk189();
    virtual void Unk190();
    virtual void Unk191();
    virtual void Unk192();
    virtual void Unk193();
    virtual void Unk194();
    virtual void Unk195();
    virtual void Unk196();
    virtual void Unk197();
    virtual void Unk198();
    virtual void Unk199();
    virtual void Unk200();
    virtual void Unk201();
    virtual void Unk202();
    virtual void Unk203();
    virtual void Unk204();
    virtual void Unk205();
    virtual void Unk206();
    virtual void Unk207();
    virtual void Unk208();
    virtual void Unk209();
    virtual void Unk210();
    virtual void Unk211();
    virtual void Unk212();
    virtual void Unk213();
    virtual void Unk214();
    virtual void Unk215();
    virtual bool IsPlayer();
    BSSoundHandleEx PlaySoundAtOwner(const char*, int, unsigned int);
};
struct IngredientData
{
    virtual void Unk0();
    virtual bool HasFoodEffect();
};
class IngredientItem : public MagicItemForm
{
  public:
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    IngredientData data;
};
struct SoundFile
{
};
class TESSound : public TESForm
{
  public:
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    SoundFile soundFile;
};
struct SpellFeedback : MagicItem
{
    EffectSetting* FUN_0040a300(int);
    FeedbackString GetNameForType(int);
};
struct FUN_0081c470_shell
{
    void FUN_0081c470(bool, float);
};
struct CastingCheck : MagicCaster
{
    bool TryCast(TESBoundObject* source);
    void FUN_00815d00(float, TESBoundObject*, bool, float, bool);
};
// @fnv 0x00815380
void __thiscall FUN_00815380_shell::FUN_00815380()
{
    reinterpret_cast<::CastingCheck *>(this)->TryCast((::TESBoundObject *)(0));
}

// @fnv 0x00815870
bool CastingCheck::TryCast(TESBoundObject* source)
{
    if (!GetSelectedMagicItem())
        return false;
    float cost = 0.0f;
    MagicItem* releasedSpell = GetSelectedMagicItem();
    IngredientItem* pCastSpell = dynamic_cast<IngredientItem*>(releasedSpell);
    int eReason = 0;
    if (!CanCast(GetSelectedMagicItem(), &cost, &eReason, false))
    {
        FeedbackActor* actor = ((::FeedbackActor *)(reinterpret_cast<::MagicCaster *>(this)->GetCasterActor()));
        EffectSetting* effect = ((SpellFeedback*)GetSelectedMagicItem())->FUN_0040a300(0);
        if (actor && effect)
        {
            TESSound* sound = 0;
            if (sound && ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(sound->soundFile))->FUN_00408da0())) && !pCastSpell)
            {
                const char* filename = ::FUN_00511840((char *)(sound));
                actor->PlaySoundAtOwner(filename, 0, 0x40000102);
            }
        }
        FeedbackString message = ((SpellFeedback*)GetSelectedMagicItem())->GetNameForType(eReason);
        if (actor && actor->IsPlayer() && (!pCastSpell || pCastSpell->data.HasFoodEffect()))
            ::DispatchMessageToSink((int)(((const char *)(::FUN_00559450((int *)&(message))))), 0, (int)(0), (int)(0), 2.0f, false);
        SetState(MagicCaster__State_ERR_CANNOT_CAST, (char*)((const char *)(::FUN_00559450((int *)&(message)))));
        SpellCast(GetSelectedMagicItem(), false);
        SetSelectedMagicItem(0);
        SetMagicTarget(0);
        return false;
    }
    SetState(MagicCaster__State_RELEASE, "Release Cast");
    MagicItem* spell = GetSelectedMagicItem();
    FUN_00815d00(cost, source, false, 1.0f, false);
    SpellCast(spell, true);
    if (apTargetLight)
        ((FUN_0081c470_shell*)apTargetLight)->FUN_0081c470(false, 0.75f);
    return true;
}

struct Vec
{
    float x, y, z;
};
struct Target;
struct Ref;
struct Item;
struct Target
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual void slot198();
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual void slot267();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void notify(int, int, float);
};
struct ActorTarget : Target
{
};
struct Ref
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual Target* target();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual int eligible();
    float distance(Vec*);
};
struct TargetView
{
    ActorTarget* actor();
};
struct Filter
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void applied(Target*, Item*);
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual bool accepts(Target*, Item*);
};
struct Magic
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int kind();
    int unk04;
    int unk08;
    struct Effects
    {
        int count();
    } effects;
};
struct Area
{
};
struct Item
{
    Area* area();
};
struct Node
{
    Ref** data();
    Node* next();
};
struct FloatSetting
{
};
struct Caster
{
    void ApplyAreaEffect(Magic*, Item*, int, Vec, Target*, Filter*, Node*, bool*, float);
};
struct P142EffectSetting
{
};
class EffectItem
{
  public:
public:
    int GetAffectedActorValue();
public:
    bool IsHostile();
};
class EffectSetting;
class ActiveEffect
{
  public:
    virtual ~ActiveEffect();
    void AddFlags(unsigned int);
public:
    ::EffectSetting *GetEffectSetting() const;
public:
    float GetDuration() const;
public:
    void SetEffectiveness(float);
};
struct P142Node
{
    EffectItem* item;
    P142Node* next;
};
struct P142Prefix
{
    int unknown;
};
struct P142EffectList : P142Prefix, P142Node
{
};
struct P142Spell : TESFullName, P142EffectList
{
    virtual bool IsAutoCalculated();
    virtual void SetPlayable(bool);
    virtual int GetSpellType();
};
struct P142Caster;
struct P142Ref
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool IsActor();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual MagicTarget* GetMagicTarget();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual void slot175();
    virtual void slot176();
    virtual void slot177();
    virtual void slot178();
    virtual void slot179();
    virtual void slot180();
    virtual void slot181();
    virtual void slot182();
    virtual void slot183();
    virtual void slot184();
    virtual void slot185();
    virtual void slot186();
    virtual void slot187();
    virtual void slot188();
    virtual void slot189();
    virtual void slot190();
    virtual void slot191();
    virtual void slot192();
    virtual void slot193();
    virtual void slot194();
    virtual void slot195();
    virtual void slot196();
    virtual void slot197();
    virtual bool AllowsEffect(MagicTarget*, ActiveEffect*);
    virtual void slot199();
    virtual void slot200();
    virtual void slot201();
    virtual void slot202();
    virtual void slot203();
    virtual void slot204();
    virtual void slot205();
    virtual void slot206();
    virtual void slot207();
    virtual void slot208();
    virtual void slot209();
    virtual void slot210();
    virtual void slot211();
    virtual void slot212();
    virtual void slot213();
    virtual void slot214();
    virtual void slot215();
    virtual void slot216();
    virtual void slot217();
    virtual void slot218();
    virtual void slot219();
    virtual void slot220();
    virtual void slot221();
    virtual void slot222();
    virtual void slot223();
    virtual void slot224();
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual void slot266();
    virtual void slot267();
    virtual void slot268();
    virtual void slot269();
    virtual void slot270();
    virtual void slot271();
    virtual void slot272();
    virtual void slot273();
    virtual void slot274();
    virtual void slot275();
    virtual void slot276();
    virtual void slot277();
    virtual void slot278();
    virtual void slot279();
    virtual void slot280();
    virtual void slot281();
    virtual void slot282();
    virtual void slot283();
    virtual void slot284();
    virtual void slot285();
    virtual void slot286();
    virtual void slot287();
    virtual void NotifySpell(int);
};
struct P142Caster : MagicCaster
{
    bool CheckHealthDamageKill(MagicTarget*, P142Spell*);
    void ApplyExplosion(Actor*, NiPoint3, EffectItem*, float);
    void ApplySpellEffects(P142Spell*, int, NiPoint3, P142Ref*, P142Ref*, int, float, float);
};
namespace fnv_00817970 {
struct HealthRef : TESObjectREFR
{
};
struct EffectSettingOps : EffectSetting
{
};
struct EffectItemOps
{
};
class ActiveEffect
{
  public:
};
struct EffectNode
{
    bool FUN_008256d0();
    ActiveEffect** FUN_006815c0();
};
struct Recipient : MagicTarget
{
    virtual HealthRef* GetActor();
    virtual EffectNode* GetEffects();
};
struct EffectDuration
{
};
struct EffectSpec
{
    int magnitude;
    int area;
    int duration;
    EffectDuration data;
};
struct CasterOps : MagicCaster
{
    bool CheckHealthDamageKill(Recipient* target, EffectSpec* spell);
};
// @fnv 0x00817970
bool CasterOps::CheckHealthDamageKill(Recipient* pRecipient, EffectSpec* pEffectSpec)
{
    if (!pRecipient || !pEffectSpec || !pRecipient->GetActor() || !pRecipient->GetActor()->IsActor() ||
        !pRecipient->GetActor()->GetNiNode())
        return false;
    if (::FUN_00405d80((int *)&(pEffectSpec->data)))
    {
        Actor* sourceActor = reinterpret_cast<::MagicCaster *>(this)->GetCasterActor();
        HealthRef* actor = pRecipient->GetActor();
        float health = reinterpret_cast<::HealthReferenceEntry *>((actor))->FUN_00568ad0();
        EffectNode* node = pRecipient->GetEffects();
        float total = 0.0f;
        while (node && !node->FUN_008256d0())
        {
            ActiveEffect* effect = *node->FUN_006815c0();
            if (effect && ((void *)(reinterpret_cast<::Twin_0044ddc0 *>((effect))->GetName())) == pEffectSpec)
            {
                EffectSettingOps* setting = ((::fnv_00817970::EffectSettingOps *)(reinterpret_cast<::ActiveEffect *>((effect))->GetEffectSetting()));
                int value;
                if (reinterpret_cast<::FUN_00403e80_shell *>((setting))->FUN_00403e80())
                    value = ((int)(reinterpret_cast<::InterfaceManager *>((setting))->FUN_00586150()));
                else
                    value = reinterpret_cast<::EffectItem *>((((::fnv_00817970::EffectItemOps *)(reinterpret_cast<::FUN_0084e3a0_Class *>((effect))->FUN_0084e3a0()))))->GetAffectedActorValue();
                if (value == 16 && reinterpret_cast<::S3e60 *>((setting))->FUN_00403e60(4) && !reinterpret_cast<::S3e60 *>((setting))->FUN_00403e60(2))
                {
                    float magnitude = ::GetFloatAtOffset1C((char *)(effect));
                    if (reinterpret_cast<::ActiveEffect *>((effect))->GetDuration() > 0.0)
                    {
                        float factor = ::FUN_0040ebd0(4.0f, ::FUN_00404010(0.0f, reinterpret_cast<::ActiveEffect *>((effect))->GetDuration()));
                        magnitude *= factor;
                    }
                    total += magnitude;
                }
            }
            node = ((::fnv_00817970::EffectNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        total = -reinterpret_cast<::fnv_008808a0::ActorProxy *>((actor))->FUN_008808a0(-total, sourceActor);
        if (total >= health)
            return true;
    }
    return false;
}
}  // namespace fnv_00817970

namespace fnv_00818310 {
struct ExplosionValues
{
};
class ExplosionPoint : public NiPoint3
{
  public:
};
class NiTransform
{
  public:
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    NiPoint3 translate;
    float scale;
    NiTransform();
    NiPoint3 FUN_00524c40(const NiPoint3&) const;
};
struct TransformNode
{
};
struct ExplosionNode
{
};
class ExplosionActor;
class ExplosionProcess
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v125();
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
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void Stagger(ExplosionActor*, NiPoint3, float);
};
class ExplosionActor
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual ExplosionNode* GetNode();
    virtual void v117();
    virtual NiPoint3 GetMinimum();
    virtual NiPoint3 GetMaximum();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* GetPosition();
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
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void Impulse(Actor*, float, float, NiPoint3*, NiPoint3*);
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
    ExplosionValues values;
};
struct ExplosionEffect
{
};
struct ExplosionCaster
{
    void ApplyExplosion(ExplosionActor*, NiPoint3, ExplosionEffect*, float);
};
void __cdecl DebugLog(const char*, ...);
// Computes explosion magnitude from the target's height and distance to origin, clamps it, then staggers or impulses the target and logs the hit.
// @fnv 0x00818310
void ExplosionCaster::ApplyExplosion(ExplosionActor* target, NiPoint3 origin, ExplosionEffect* effect, float strength)
{
    float h;  // Distance from the explosion origin.
    // Actor height from the upper and lower bounds.
    float a = target->GetMaximum().z - target->GetMinimum().z;
    float i;  // Explosion magnitude, capped before choosing the reaction.
    // Position raised to three quarters of the actor height.
    NiPoint3 s = *target->GetPosition();
    s.z += a * 0.75;
    // Displacement used to calculate the distance.
    NiPoint3 p = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(((ExplosionPoint&)s)))->FUN_00439ef0((::NiPoint3 *)&(origin), *(const ::NiPoint3 *)nullptr)));
    h = reinterpret_cast<::NiPoint3 *>((void *)&(((ExplosionPoint&)p)))->ComputeMagnitude();
    i = ::ComputeBlastPower((int)strength, (int)(reinterpret_cast<::FUN_00404420_shell *>((effect))->FUN_00404420() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1112))))))), h,
                          reinterpret_cast<::ActorValueOwner *>(&(target->values))->GetActorValueAsInteger((::ActorValue::Index)(10)), reinterpret_cast<::ActorValueOwner *>(&(target->values))->GetActorValueAsInteger((::ActorValue::Index)(11)), reinterpret_cast<::FUN_00893530_shell *>((target))->GetFatigueRatio());
    if (i > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1131)))))))
        i = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1131))))));
    if (i > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::g_011d180c)))))))
    {
        ((::fnv_00818310::ExplosionProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((target))->GetBaseTexture()))->Stagger(target, origin, i);
    }
    else if (i > 0.0)
    {
        Actor* caster = reinterpret_cast<::MagicCaster *>(this)->GetCasterActor();
        if (caster)
        {
            NiPoint3 localOrigin = ::DAT_011a9478;
            NiPoint3 localPosition = NiPoint3::ZERO;
            ExplosionNode* node = ((ExplosionActor*)caster)->GetNode();
            if (node)
            {
                NiTransform transform;
                reinterpret_cast<::NiTransform *>((((::fnv_00818310::TransformNode *)(::FUN_00461130((int)(node))))))->CalculateInverse(*(::NiTransform *)nullptr);
                localOrigin = transform.FUN_00524c40(origin);
                localPosition = transform.FUN_00524c40(s);
            }
            target->Impulse(caster, 2.0 * i, 0.0f, &localPosition, &localOrigin);
        }
    }
    if (i > 0.0 && ((bool)(::FUN_005b6f70())))
        DebugLog("An explosion of %.1f magnitude hits %.20s!", i, reinterpret_cast<::FUN_0055d520_shell *>((target))->FUN_0055d520());
}
}  // namespace fnv_00818310

struct AimPoint
{
    float x, y, z;
    AimPoint();
    AimPoint operator+(const AimPoint&) const;
    AimPoint& operator+=(const AimPoint&);
};
struct AimRef
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual AimPoint Lower();
    virtual AimPoint Upper();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual AimPoint* Position();
};
struct AimTarget
{
    virtual void slot0();
    virtual TESObjectREFR* Reference();
};
struct EffectDistance
{
};
struct EffectList
{
};
struct SpellOps
{
    int unk00, unk04, unk08;
    EffectList effects;
};
struct NodeAim
{
    const AimPoint& FUN_0045bb80() const;
};
struct ActorLooking
{
};
struct AimAux
{
};
struct ActorAim : ActorVT
{
    virtual void slot225();
    virtual void slot226();
    virtual void slot227();
    virtual void slot228();
    virtual void slot229();
    virtual void slot230();
    virtual void slot231();
    virtual void slot232();
    virtual void slot233();
    virtual void slot234();
    virtual void slot235();
    virtual void slot236();
    virtual void slot237();
    virtual void slot238();
    virtual void slot239();
    virtual void slot240();
    virtual void slot241();
    virtual void slot242();
    virtual void slot243();
    virtual void slot244();
    virtual void slot245();
    virtual void slot246();
    virtual void slot247();
    virtual void slot248();
    virtual void slot249();
    virtual void slot250();
    virtual void slot251();
    virtual void slot252();
    virtual void slot253();
    virtual void slot254();
    virtual void slot255();
    virtual void slot256();
    virtual void slot257();
    virtual void slot258();
    virtual void slot259();
    virtual void slot260();
    virtual void slot261();
    virtual void slot262();
    virtual void slot263();
    virtual void slot264();
    virtual void slot265();
    virtual AimAux* Aux();
};
struct LightDelete
{
    ~LightDelete();
};
AimPoint ComputeRelativeFiringAngle(TESObjectREFR*, TESObjectREFR*, float, float, int);
AimPoint FUN_009a87f0(AimPoint, TESObjectREFR*, float, float, int);
void FUN_0081e040(MagicCaster*, int, MagicEffectCollection*, MagicItem*, EffectItem*, EffectSetting*, AimPoint, AimPoint);
struct FUN_00818610_class : MagicCaster
{
    void CastAimEffect();
};
// If the caster has a valid spell and effect item, computes aim points from the aim reference or actor and dispatches the magic effect via FUN_0081e040.
// @fnv 0x00818610
void FUN_00818610_class::CastAimEffect()
{
    if (!GetSelectedMagicItem())
        return;
    AimRef* s = (AimRef*)GetCasterReference();
    Actor* h = GetCasterActor();
    TESObjectREFR* p = GetCurrentMagicTarget() ? ((AimTarget*)GetCurrentMagicTarget())->Reference() : 0;
    EffectItem* i = reinterpret_cast<::fnv_004064d0::EffectItemList *>(&(((SpellOps*)GetSelectedMagicItem())->effects))->FindCostliestEffectItem(2, 0);
    EffectSetting* a = GetSelectedMagicItem()->GetEffectSettingForRange(MagicSystem::SELF);
    if (!i)
        return;
    if (s)
    {
        bool f = true;
        AimPoint b;
        AimPoint q = (*reinterpret_cast<::AimPoint *>((void *)&::NiPoint3::ZERO));
        AimPoint cf = (*reinterpret_cast<::AimPoint *>((void *)&::NiPoint3::ZERO));
        if (h)
        {
            cf.z = h->AdjustRot(0);
            cf.x = reinterpret_cast<::MobileObject *>((void *)(((ActorLooking*)h)))->GetLooking();
            b = *s->Position();
            float delta = s->Upper().z - s->Lower().z;
            q.z = delta * 0.699999988079071;
            reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::AimPoint &)(b))->FUN_0063c8a0((void *)&(q));
        }
        else
        {
            float distance = reinterpret_cast<::PathingRequest *>((void *)(((EffectDistance*)a)))->GetCenterRadius() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1140))))));
            cf = (*(const ::AimPoint *)(reinterpret_cast<::TESRecipe *>((void *)(s))->GetData())) + ComputeRelativeFiringAngle((TESObjectREFR*)s, p, distance, 0.0f, 2);
            b = *s->Position();
            b.z += (s->Upper().z - s->Lower().z) * 0.5;
        }
        NiNode* eb = GetMagicNode();
        if (eb)
            b = ((NodeAim*)eb)->FUN_0045bb80();
        if (this != static_cast<MagicCaster*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))) && h && p)
        {
            AimAux* hDistance;
            float aAux = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1140)))))) * (a ? reinterpret_cast<::PathingRequest *>((void *)(((EffectDistance*)a)))->GetCenterRadius() : 1.0f);
            float iMode = 0;
            hDistance = ((ActorAim*)h)->Aux();
            int pElevation = hDistance ? ((int)(reinterpret_cast<::FUN_00981920_Class *>((hDistance))->GetPackageRefCount())) : 1;
            cf = FUN_009a87f0(b, p, aAux, iMode, pElevation);
        }
        if (i && f)
        {
            FUN_0081e040(this, 0, apTargetLight, GetSelectedMagicItem(), i, a, b, cf);
            apTargetLight = 0;
        }
        if (apTargetLight)
            delete (LightDelete*)apTargetLight;
        apTargetLight = 0;
    }
}

struct AEEffectItem
{
};

struct AEEffectListBase
{
    virtual void v00();
};

struct AEEffectList : AEEffectListBase, BSSimpleList<AEEffectItem*>
{
};

struct AEMagicItem : MagicItem, AEEffectList
{
};

struct AESpellItem : SpellItem
{
};

struct AEProcess
{
};

struct AEMobile : MobileObject
{
};

struct AEActor : Actor
{
};

struct AERefVtbl
{
    virtual void v000();
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
    virtual int Unk_67();
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
    virtual void* GetNiNode();
};

struct AEActorArray
{
    MobileObject* GetAt(unsigned int auiIndex);
};

struct AEProcessLists
{
};

struct AEFloatSetting
{
};


struct AETargetList
{
    TESObjectREFR* pItem;
    AETargetList* pNext;

    void AddHead(TESObjectREFR* const& arItem);
};

struct AEGatherer
{
    void GatherTargetsInArea(MagicItem* apItem, unsigned int auiEffectCode, NiPoint3 akPos, AETargetList* apTargets);
};

#include <xmmintrin.h>
struct Vec3
{
    float x;
    float y;
    float z;
public:
    Vec3();
};
// Scans nearby actors within reach and strike angle of the caster and returns the closest valid target, falling back to the player.
// @fnv 0x00817620
MagicTarget* FUN_00817620_shell::FindClosestMagicTarget()
{
    Actor* pactor = GetCasterActor();
    float freach =
        pactor ? ((ActorVT*)pactor)->V224() * reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((((ActorV_S*)pactor)))->FUN_00567400() : *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting594))))));
    TESObjectREFR* pcaster = pactor ? pactor : GetCasterReference();
    Actor* pclosestTarget = 0;
    float fclosestDelta = 3.402823466e+38f;
    if (::FUN_009a64d0((::S_9a64d0_Ref *)(::Actor *)((Actor*)pcaster), (::S_9a64d0_Ref *)((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))), 0) <= freach)
    {
        float fdelta = 3.402823466e+38f;
        bool binStrikeAngle = pactor ? ::IsTargetInCone((::ConeRef *)(pactor), (::ConeRef *)((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))), &fdelta) : true;
        if (binStrikeAngle && fdelta <= fclosestDelta)
        {
            pclosestTarget = (*reinterpret_cast<::Actor * *>(&::_g_thePlayer));
            fclosestDelta = fdelta;
        }
    }
    MobileObjectProcessArray* parray = (MobileObjectProcessArray*)((void *)(reinterpret_cast<::BaseProcess *>((((TgtOps*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->GetCurrentProcessData()));
    for (unsigned int i = 0; i < reinterpret_cast<::FUN_005be5c0_shell *>((void *)(parray))->FUN_005be5c0((*(int *)&(const ::PROCESS_TYPE &)((PROCESS_TYPE)0))); i++)
    {
        MobileObject* pmob = ((::MobileObject *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((void *)(parray))->FUN_00968670(i)));
        Actor* ptargetActor = (pmob && pmob->IsActor()) ? (Actor*)pmob : 0;
        S::BSSimpleList* ptempfollower = 0;
        while (ptargetActor)
        {
            if (ptargetActor != pcaster && !((ActorVT*)ptargetActor)->V139(0) && ptargetActor->GetNiNode())
            {
                if (::FUN_009a64d0((::S_9a64d0_Ref *)(::Actor *)((Actor*)pcaster), (::S_9a64d0_Ref *)(ptargetActor), 0) <= freach)
                {
                    float fdelta = 3.402823466e+38f;
                    bool binStrikeAngle = pactor ? ::IsTargetInCone((::ConeRef *)(pactor), (::ConeRef *)(ptargetActor), &fdelta) : true;
                    if (binStrikeAngle && fdelta <= fclosestDelta)
                    {
                        pclosestTarget = ptargetActor;
                        fclosestDelta = fdelta;
                    }
                }
            }
            if (ptempfollower && *((::Actor **)(new ((void *)(ptempfollower)) ::Vec3())))
            {
                ptargetActor = dynamic_cast<Character*>(*((::Actor **)(new ((void *)(ptempfollower)) ::Vec3())));
                ptempfollower = ((::S::BSSimpleList *)(reinterpret_cast<::Callees *>((ptempfollower))->FUN_00726070()));
                while (ptargetActor && (!((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)ptargetActor)))->GetBaseTexture())) ||
                                        ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((TESResponse*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)ptargetActor)))->GetBaseTexture())))))->FUN_0045cd60()))))
                {
                    ptargetActor = 0;
                    if (ptempfollower)
                        ptargetActor = dynamic_cast<Character*>(*((::Actor **)(new ((void *)(ptempfollower)) ::Vec3())));
                    if (ptempfollower)
                        ptempfollower = ((::S::BSSimpleList *)(reinterpret_cast<::Callees *>((ptempfollower))->FUN_00726070()));
                }
            }
            else
                ptargetActor = 0;
        }
    }
    return pclosestTarget;
}
// @fnv 0x00816f10
void Caster::ApplyAreaEffect(Magic* magic, Item* item, int enabled, Vec pos, Target* exclude, Filter* filter,
                             Node* list, bool* done, float scale)
{
    if (!enabled)
        return;
    int radius5 = reinterpret_cast<::FUN_00404420_shell *>((((::Area *)(reinterpret_cast<::FUN_0084e3a0_Class *>((item))->FUN_0084e3a0()))))->FUN_00404420();
    if (radius5 > 0)
    {
        radius5 *= (int)(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting1112)))))) * scale);
        ActorTarget* source7 = ((::ActorTarget *)(reinterpret_cast<::MagicCaster *>(this)->GetCasterActor()));
        bool notified5 = *done;
        Node* nodeB = list;
        while (nodeB && *((::Ref **)(new ((void *)(nodeB)) ::Vec3())))
        {
            Ref* ref5 = *((::Ref **)(new ((void *)(nodeB)) ::Vec3()));
            if (ref5)
            {
                Target* target = ref5->target();
                bool isSource = false;
                ActorTarget* actorA = target ? ((::ActorTarget *)(reinterpret_cast<::MagicTarget *>((((TargetView*)target)))->GetOwnerActor())) : 0;
                if (source7)
                    isSource = actorA == source7;
                if (target && !isSource && target != exclude && ref5->eligible())
                {
                    float distance4 = reinterpret_cast<::fnv_00572380::Fn572380 *>((ref5))->FUN_00572380((::fnv_00572380::NiP3Sub *)(::Vec *)(&pos));
                    if (distance4 <= radius5 && (!actorA || !reinterpret_cast<::FUN_008ace90_shell *>((actorA))->FUN_008ace90()))
                    {
                        if (!filter || filter->accepts(target, item))
                        {
                            if (reinterpret_cast<::MagicCaster *>(this)->AddEffectToTarget((::MagicTarget *)(target), (*(::NiPoint3 *)&(const ::Vec &)(pos)), (::MagicItem *)(magic), (::ActiveEffect *)(item), 1))
                            {
                                if (filter)
                                    filter->applied(target, item);
                                if (!exclude && !notified5 && source7 && (!magic->kind() || magic->kind() == 5))
                                {
                                    notified5 = true;
                                    *done = true;
                                    source7->notify(::FUN_004065e0((::EffectItemList_shell *)&(magic->effects)), 1, 0.0f);
                                }
                            }
                        }
                    }
                }
            }
            nodeB = ((::Node *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
        }
    }
}
// Applies each effect item of the spell to the target, creating active effects, notifying the caster, and handling secondary effects.
// @fnv 0x00817160
void P142Caster::ApplySpellEffects(P142Spell* spell, int flags, NiPoint3 position, P142Ref* source, P142Ref* target,
                                   int unused, float effectiveness, float magnitude)
{
    P142EffectList* targets = spell;
    float entry = spell->GetSpellType() == 0 ? GetCasterEffectiveness(false, 0.0f) : 1.0f;
    entry *= effectiveness;
    EffectItem* notified = reinterpret_cast<::fnv_004064d0::EffectItemList *>((spell))->FindCostliestEffectItem(2, 0);
    BSSimpleList<const char*> special;
    reinterpret_cast<::FileMatchList *>((void *)&(special))->RemoveAll();
    reinterpret_cast<::AEGatherer *>(this)->GatherTargetsInArea((::MagicItem *)(spell), 2, position, (::AETargetList *)(::BSSimpleList<const char *> *)(&special));
    bool modifier = false;
    while (targets)
    {
        EffectItem* item = *((::EffectItem **)(new ((void *)(targets)) ::Vec3()));
        if (item && reinterpret_cast<::FUN_0084e3a0_Class *>((item))->FUN_0084e3a0() == 2)
        {
            ActiveEffect* effect = CreateActiveEffect((MagicItem*)spell, item, 0);
            if (item != notified)
            {
                effect->AddFlags(4);
                effect->AddFlags(2);
                effect->AddFlags(8);
            }
            effect->SetEffectiveness(entry);
            if (target && target->GetMagicTarget() && target != (P142Ref*)GetCasterReference() &&
                (!source || source->AllowsEffect(target->GetMagicTarget(), effect)))
            {
                bool added = reinterpret_cast<::MagicCaster *>(this)->AddEffectToTarget(target->GetMagicTarget(), position, (::MagicItem *)(spell), effect, false);
                if (added)
                {
                    P142Caster* caster = ((::P142Caster *)(reinterpret_cast<::PlayerMover *>((source))->GetActorStateFlags()));
                    P142Ref* ref = caster ? ((::P142Ref *)(reinterpret_cast<::MagicCaster *>((caster))->GetCasterActor())) : 0;
                    if ((ref && !modifier && spell->GetSpellType() == 0) || spell->GetSpellType() == 5)
                    {
                        modifier = true;
                        ref->NotifySpell(::FUN_004065e0((::EffectItemList_shell *)(spell)));
                    }
                }
            }
            reinterpret_cast<::Caster *>(this)->ApplyAreaEffect((::Magic *)(spell), (::Item *)(effect), flags, (*(::Vec *)&(const ::NiPoint3 &)(position)), (::Target *)(::MagicTarget *)(target ? target->GetMagicTarget() : 0), (::Filter *)(source), (::Node *)(::BSSimpleList<const char *> *)(&special),
                            &modifier, magnitude);
            delete effect;
        }
        targets = static_cast<P142EffectList*>(((::P142Node *)(reinterpret_cast<::Callees *>((targets))->FUN_00726070())));
    }
    bool primary = reinterpret_cast<::S86a0 *>((((::P142Ref *)(reinterpret_cast<::MagicProjectile *>((source))->FUN_004fd400()))))->FUN_004086a0() == 3;
    EffectItem* secondary = reinterpret_cast<::fnv_004064d0::EffectItemList *>((spell))->FindCostliestEffectItem(2, 1);
    if (!primary)
    {
        if (secondary)
            reinterpret_cast<::Master *>(this)->FUN_00817b90((*(::Vec3 *)&(const ::NiPoint3 &)(position)), (::ListHandle *)(flags), spell, (::RangeManager *)(secondary), (::TargetInterface *)(::BSSimpleList<const char *> *)(&special), effectiveness, magnitude);
        else if (target && target->IsActor() && notified && reinterpret_cast<::S3e60 *>((((::P142EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((notified))->FUN_00825c00()))))->FUN_00403e60(0x20000000))
        {
            Actor* actor = (Actor*)target;
            if (CheckHealthDamageKill(actor, spell))
                ApplyExplosion(actor, position, notified, reinterpret_cast<::FUN_00403f00_shell *>((notified))->FUN_00403f00());
        }
    }
    reinterpret_cast<::FileMatchList *>((void *)&(special))->RemoveAll();
}

struct RayGroupSrc
{
    unsigned int GetGroup();
};

struct RayCaster
{
    unsigned int GetGroup();
};

struct RayInput
{
    __m128 q00;
    __m128 q10;
    __m128 q20;
    __m128 q30;
    __m128 q40;
    __m128 q50;
    __m128 q60;
    __m128 q70;
    __m128 q80;
    __m128 q90;
    __m128 qa0;
    RayInput();
    void SetFilter(unsigned int f);
};

struct RayFilter
{
    unsigned int value;
    RayFilter(int a);
};

struct RayWorld
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual bool CastRay(RayInput* input);
};

struct RayCell
{
};

struct RayRef
{
    virtual void w000();
    virtual void w004();
    virtual void w008();
    virtual void w00c();
    virtual void w010();
    virtual void w014();
    virtual void w018();
    virtual void w01c();
    virtual void w020();
    virtual void w024();
    virtual void w028();
    virtual void w02c();
    virtual void w030();
    virtual void w034();
    virtual void w038();
    virtual void w03c();
    virtual void w040();
    virtual void w044();
    virtual void w048();
    virtual void w04c();
    virtual void w050();
    virtual void w054();
    virtual void w058();
    virtual void w05c();
    virtual void w060();
    virtual void w064();
    virtual void w068();
    virtual void w06c();
    virtual void w070();
    virtual void w074();
    virtual void w078();
    virtual void w07c();
    virtual void w080();
    virtual void w084();
    virtual void w088();
    virtual void w08c();
    virtual void w090();
    virtual void w094();
    virtual void w098();
    virtual void w09c();
    virtual void w0a0();
    virtual void w0a4();
    virtual void w0a8();
    virtual void w0ac();
    virtual void w0b0();
    virtual void w0b4();
    virtual void w0b8();
    virtual void w0bc();
    virtual void w0c0();
    virtual void w0c4();
    virtual void w0c8();
    virtual void w0cc();
    virtual void w0d0();
    virtual void w0d4();
    virtual void w0d8();
    virtual void w0dc();
    virtual void w0e0();
    virtual void w0e4();
    virtual void w0e8();
    virtual void w0ec();
    virtual void w0f0();
    virtual void w0f4();
    virtual void w0f8();
    virtual void w0fc();
    virtual void w100();
    virtual void w104();
    virtual void w108();
    virtual void w10c();
    virtual void w110();
    virtual void w114();
    virtual void w118();
    virtual void w11c();
    virtual void w120();
    virtual void w124();
    virtual void w128();
    virtual void w12c();
    virtual void w130();
    virtual void w134();
    virtual void w138();
    virtual void w13c();
    virtual void w140();
    virtual void w144();
    virtual void w148();
    virtual void w14c();
    virtual void w150();
    virtual void w154();
    virtual void w158();
    virtual void w15c();
    virtual void w160();
    virtual void w164();
    virtual void w168();
    virtual void w16c();
    virtual void w170();
    virtual void w174();
    virtual void w178();
    virtual void w17c();
    virtual void w180();
    virtual void w184();
    virtual void w188();
    virtual void w18c();
    virtual void w190();
    virtual void w194();
    virtual void w198();
    virtual void w19c();
    virtual void w1a0();
    virtual void w1a4();
    virtual void w1a8();
    virtual void w1ac();
    virtual void w1b0();
    virtual void w1b4();
    virtual void w1b8();
    virtual void w1bc();
    virtual void w1c0();
    virtual void w1c4();
    virtual void w1c8();
    virtual void w1cc();
    virtual void w1d0();
    virtual void w1d4();
    virtual void w1d8();
    virtual void w1dc();
    virtual void w1e0();
    virtual void w1e4();
    virtual void w1e8();
    virtual void w1ec();
    virtual void w1f0();
    virtual Vec3* GetPos();
};


struct RayObj
{
    bool FUN_008190d0(Vec3 from, RayRef* ref);
};
// Finds the largest area of the matching effect, then adds nearby high actors and the player within the scaled radius to apTargets.
// @fnv 0x00818ce0
void AEGatherer::GatherTargetsInArea(MagicItem* apItem, unsigned int auiEffectCode, NiPoint3 akPos,
                                     AETargetList* apTargets)
{
    if (!apTargets)
        return;

    int iMaxAreaA = 0;
    AEEffectList* pIter = static_cast<AEMagicItem*>(apItem);
    while (pIter && !pIter->IsEmpty())
    {
        AEEffectItem* pEffect = ((::AEEffectItem *)(new ((void *)(pIter)) ::Vec3()));
        if (pEffect && ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pEffect))->FUN_0084e3a0())) == auiEffectCode && reinterpret_cast<::FUN_00404420_shell *>((pEffect))->FUN_00404420() > iMaxAreaA)
            iMaxAreaA = reinterpret_cast<::FUN_00404420_shell *>((pEffect))->FUN_00404420();
        pIter = static_cast<AEEffectList*>(((::BSSimpleList< ::AEEffectItem *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070())));
    }
    if (!iMaxAreaA)
        return;

    SpellItem* pSpell5 = dynamic_cast<SpellItem*>(apItem);
    bool bNoCheck2 = pSpell5 && ((bool)(reinterpret_cast<::FlaggedData *>((static_cast<AESpellItem*>(pSpell5)))->ContainsAnyFlag(0x10)));
    float fRadius4 = iMaxAreaA * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AEFloatSetting *>(&::originalRuntimeFloatSetting1112))))));
    Actor* m_pEffectInstance = reinterpret_cast<::MagicCaster *>(this)->GetCasterActor();
    AEActorArray* pActors3 = ((::AEActorArray *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::AEProcessLists *>(&::g_011e0e80))))->GetCurrentProcessData()));
    for (unsigned int i = 0; i < reinterpret_cast<::FUN_005be5c0_shell *>((pActors3))->FUN_005be5c0(0); i++)
    {
        MobileObject* pMobile4 = ((::MobileObject *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((pActors3))->FUN_00968670(i)));
        BSSimpleList<Actor*>* pNode = 0;
        while (pMobile4)
        {
            int iValid = ((AERefVtbl*)pMobile4)->Unk_67();
            bool bIsCaster = false;
            Actor* pActor4 = dynamic_cast<Actor*>(pMobile4);
            if (m_pEffectInstance)
                bIsCaster = pActor4 == m_pEffectInstance;
            if (iValid && !bIsCaster && ((AERefVtbl*)pMobile4)->GetNiNode())
            {
                float fDist = reinterpret_cast<::fnv_00572380::Fn572380 *>((static_cast<AEMobile*>(pMobile4)))->FUN_00572380((::fnv_00572380::NiP3Sub *)(::NiPoint3 *)(&akPos));
                if (fDist <= fRadius4 && (!pActor4 || !reinterpret_cast<::FUN_008ace90_shell *>((static_cast<AEActor*>(pActor4)))->FUN_008ace90()) &&
                    (bNoCheck2 || reinterpret_cast<::RayObj *>(this)->FUN_008190d0((*(::Vec3 *)&(const ::NiPoint3 &)(akPos)), (::RayRef *)(pActor4))))
                {
                    apTargets->AddHead(pActor4);
                }
            }
            if (pNode && ((::Actor *)(new ((void *)(pNode)) ::Vec3())))
            {
                pMobile4 = dynamic_cast<Character*>(((::Actor *)(new ((void *)(pNode)) ::Vec3())));
                pNode = ((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
                while (pMobile4 && (!((::AEProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((static_cast<AEMobile*>(pMobile4)))->GetBaseTexture())) ||
                                    ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((::AEProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((static_cast<AEMobile*>(pMobile4)))->GetBaseTexture()))))->FUN_0045cd60()))))
                {
                    if (pNode)
                        pMobile4 = dynamic_cast<Character*>(((::Actor *)(new ((void *)(pNode)) ::Vec3())));
                    else
                        pMobile4 = 0;
                    if (pNode)
                        pNode = ((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
                }
            }
            else
                pMobile4 = 0;
        }
    }

    if ((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)) != m_pEffectInstance && ((AERefVtbl*)(*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))->GetNiNode())
    {
        float fPlayerDist = reinterpret_cast<::fnv_00572380::Fn572380 *>((static_cast<AEMobile*>(static_cast<MobileObject*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))))->FUN_00572380((::fnv_00572380::NiP3Sub *)(::NiPoint3 *)(&akPos));
        if (fPlayerDist <= fRadius4 && !reinterpret_cast<::FUN_008ace90_shell *>((static_cast<AEActor*>((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->FUN_008ace90() &&
            (bNoCheck2 || reinterpret_cast<::RayObj *>(this)->FUN_008190d0((*(::Vec3 *)&(const ::NiPoint3 &)(akPos)), (::RayRef *)((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))))
        {
            apTargets->AddHead((*reinterpret_cast<::Actor * *>(&::_g_thePlayer)));
        }
    }
}

// Sets a ray from from to the reference position plus a height offset, then returns the negation of CastRay.
// @fnv 0x008190d0
bool RayObj::FUN_008190d0(Vec3 from, RayRef* ref)
{
    if (!ref)
        return false;
    RayWorld* world = ((::RayCell *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())) ? ((::RayWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::RayCell *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget()))))->FUN_004543c0())) : 0;
    if (!world)
        return false;
    unsigned int flag = 0x26206;
    ::ShadowLightData::SetTargetMaskForSelection(0x27, flag);
    Vec3 vTo = *ref->GetPos();
    vTo.z += reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((ref))->GetActorHeight() * ::DAT_01011588;
    RayInput input;
    RayFilter filter(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(filter))->FUN_004a39f0(0x27);
    if (((::RayCaster *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((ref))->FUN_009306d0())))
        reinterpret_cast<::FUN_0059ce80_shell *>(&(filter))->FUN_0059ce80(((unsigned int)(reinterpret_cast<::S819 *>((((::RayCaster *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((ref))->FUN_009306d0()))))->FUN_00819250())));
    else
        reinterpret_cast<::FUN_0059ce80_shell *>(&(filter))->FUN_0059ce80(::FUN_005dbe10());
    input.SetFilter(filter.value);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(input))->FUN_004a3da0(&from);
    reinterpret_cast<::FUN_004a3eb0_shell *>(&(input))->FUN_004a3eb0(&vTo);
    return !world->CastRay(&input);
}

class AlchemyItem : public MagicItem
{
  public:
};
class EnchantmentItem : public MagicItem
{
  public:
};

namespace CastTargets {
struct Effect;
struct Active;
struct Object;
struct Target;
struct SpellNode;
struct Point
{
    float x, y, z;
    Point();
    Point(float, float, float);
};
struct Context
{
    unsigned int unk00, unk04;
    Context();
    ~Context();
};
struct Setting
{
};
struct EffectSettings
{
};
struct Effect
{
};
struct Active
{
    virtual ~Active();
};
struct EffectLink
{
    Effect* value;
    EffectLink* next;
};
struct UnsignedIntegerValue
{
    unsigned int unk00;
};
struct EffectList : UnsignedIntegerValue, EffectLink
{
};
struct NameView
{
    virtual void Slot0();
    unsigned int unk04, unk08;
};
struct MagicView : NameView, EffectList
{
};
struct IngredientFlags
{
    virtual void slot0();
    virtual bool HasFoodEffect();
};
struct IngredientView
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    IngredientFlags flags;
};
struct SpellView
{
};
struct Source
{
    int FUN_00401170();
};
struct Model
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual const char* GetModelFilePath();
    unsigned int FUN_0048cee0();
};
struct MagicArt
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Model model;
};
struct MagicAccessor
{
    MagicArt* FUN_0040a300(bool);
};
struct Node
{
};
struct ModelInstance
{
};
struct PositionProvider
{
};
struct CasterPart
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual PositionProvider* GetSourcePosition();
    unsigned int unk04, unk08;
};
struct TargetPart
{
    unsigned int unk00;
};
struct Object
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual bool IsActor();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual Point* GetPosition();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual int GetActorType();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual bool IsCharacter();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual float GetReach();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual void slot3e4();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual void slot3f8();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41c();
    virtual void slot420();
    virtual void slot424();
    virtual void slot428();
    virtual void slot42c();
    virtual void slot430();
    virtual void slot434();
    virtual void slot438();
    virtual void slot43c();
    virtual void slot440();
    virtual void slot444();
    virtual void slot448();
    virtual void slot44c();
    virtual void slot450();
    virtual void slot454();
    virtual void slot458();
    virtual void slot45c();
    virtual void slot460();
    virtual void slot464();
    virtual void slot468();
    virtual void slot46c();
    virtual void slot470();
    virtual void slot474();
    virtual void slot478();
    virtual void slot47c();
    virtual void UseSkill(void*, float);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    CasterPart caster;
    TargetPart target;
    float AttachSubObject();
    float FUN_008bec80();
};
struct ActorHead
{
    virtual void slot0();
};
struct ActorCast : ActorHead
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
};
struct ActorView : ActorCast, TargetPart
{
};
struct Target
{
    virtual void slot0();
    virtual Object* GetObject();
};
struct Loader
{
};
extern const char DAT_0107acfc[];
extern const char DAT_0102054c[];
struct Caster
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual Target* GetSpellTarget();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual Object* GetCasterObject();
    virtual Node* GetMagicNode();
    virtual MagicItem* GetSpell();
    virtual bool HasActiveEffect(Active*);
    virtual float Effectiveness(bool, float);
    virtual void SetSpell(MagicItem*);
    virtual Target* GetCurrentMagicTarget();
    virtual void SetMagicTarget(Target*);
    virtual Active* CreateActiveEffect(MagicItem*, Effect*, Source*);
    void FUN_00815d00(float, Source*, bool, float, bool);
};
// Casts the current spell on a target, creating active effects, applying area effects, and updating the caster's state.
// @fnv 0x00815d00
void Caster::FUN_00815d00(float power, Source* source, bool immediate, float multiplier, bool abFlag4)
{
    MagicItem* spellB = GetSpell();
    if (!spellB)
        return;
    reinterpret_cast<::MagicCaster *>(this)->SetState((::MagicCaster__State)(4), (char *)(DAT_0107acfc));
    Object* casterObjectSlot2 = GetCasterObject();
    Object* casterActorSlot25 = ((::CastTargets::Object *)(reinterpret_cast<::MagicCaster *>(this)->GetCasterActor()));
    Target* target6 = 0;
    bool potion = spellB->GetSpellType() == 7;
    bool touchPotionSlot30 = potion && reinterpret_cast<::EffectItemList *>((reinterpret_cast<MagicView*>(spellB)))->FUN_00405da0();
    AlchemyItem* alchemy2 = potion ? dynamic_cast<AlchemyItem*>(spellB) : 0;
    if (reinterpret_cast<::fnv_00405fe0::EffectItemList *>((reinterpret_cast<MagicView*>(spellB)))->FUN_00405fe0() || touchPotionSlot30)
    {
        bool noTouch = source ? source->FUN_00401170() == 0x29 : false;
        if (!noTouch && spellB->GetSpellType() == 6)
        {
            EnchantmentItem* enchantment = dynamic_cast<EnchantmentItem*>(spellB);
            if (enchantment)
                noTouch = ((int)(reinterpret_cast<::BGSCameraPath *>((enchantment))->GetPrevPath())) == 2;
        }
        if (!noTouch && (casterActorSlot25 || !GetCurrentMagicTarget()))
            target6 = GetSpellTarget();
        if (!target6)
        {
            target6 = GetCurrentMagicTarget();
            if (target6 && !source && !noTouch && target6->GetObject())
            {
                float reach = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CastTargets::Setting *>(&::originalRuntimeFloatSetting1126))))));
                if (casterObjectSlot2->IsActor() &&
                    (casterObjectSlot2 == (*reinterpret_cast<::CastTargets::Object * *>(&::_g_thePlayer)) || !target6->GetObject()->IsActor() ||
                     target6->GetObject()->GetActorType() != 9))
                    reach = casterObjectSlot2->GetReach();
                reach *= ::FUN_00404010(1.0f, reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((casterObjectSlot2))->FUN_00567400());
                if (reach < ::FUN_009a64d0((::S_9a64d0_Ref *)(casterObjectSlot2), (::S_9a64d0_Ref *)(::CastTargets::Object *)(target6->GetObject()), false))
                    target6 = 0;
            }
        }
    }
    bool releaseModel = false;
    Node* magicNode = GetMagicNode();
    if (magicNode && ((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((magicNode))->FUN_00453470())) > 0 && !source)
        releaseModel = true;
    Object* aTargetObject = target6 ? target6->GetObject() : 0;
    bool didTarget2 = false;
    MagicItem* castSpell9 = spellB;
    IngredientItem* ingredientSlot11 = dynamic_cast<IngredientItem*>(castSpell9);
    Effect* kSelfEffect = ((::CastTargets::Effect *)(reinterpret_cast<::fnv_004064d0::EffectItemList *>((reinterpret_cast<MagicView*>(castSpell9)))->FindCostliestEffectItem(0, false)));
    Effect* aTouchEffect = ((::CastTargets::Effect *)(reinterpret_cast<::fnv_004064d0::EffectItemList *>((reinterpret_cast<MagicView*>(castSpell9)))->FindCostliestEffectItem(1, false)));
    SpellItem* spellFormSlot1 = dynamic_cast<SpellItem*>(spellB);
    Context contextSlot12;
    reinterpret_cast<::FileMatchList *>(&(contextSlot12))->RemoveAll();
    if (aTargetObject)
        reinterpret_cast<::AEGatherer *>(this)->GatherTargetsInArea(castSpell9, true, (*(::NiPoint3 *)&(const ::CastTargets::Point &)(*aTargetObject->GetPosition())), (::AETargetList *)(::CastTargets::Context *)(&contextSlot12));
    else if (casterActorSlot25 && spellFormSlot1 && ((bool)(reinterpret_cast<::FlaggedData *>((reinterpret_cast<SpellView*>(spellFormSlot1)))->ContainsAnyFlag(0x80))))
        reinterpret_cast<::AEGatherer *>(this)->GatherTargetsInArea(castSpell9, true, (*(::NiPoint3 *)&(const ::CastTargets::Point &)(*casterActorSlot25->GetPosition())), (::AETargetList *)(::CastTargets::Context *)(&contextSlot12));
    EffectList* cursorA = static_cast<EffectList*>(reinterpret_cast<MagicView*>(spellB));
    while (cursorA)
    {
        Effect* effect = *((::CastTargets::Effect **)(new ((void *)(cursorA)) ::Vec3()));
        if (effect && spellB->GetSpellType() == 6 && source && !::FUN_00409720((::TESBoundObject *)(source), (::ItemExtraList *)(0), (::EffectSetting *)(::CastTargets::EffectSettings *)(((::CastTargets::EffectSettings *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((effect))->FUN_00825c00())))))
            effect = 0;
        if (effect)
        {
            Active* active = CreateActiveEffect(spellB, effect, source);
            Effect* activeEffect = ((::CastTargets::Effect *)(reinterpret_cast<::FUN_0084e3a0_Class *>((active))->FUN_0084e3a0()));
            float _cost = reinterpret_cast<::TESGrass *>((((::CastTargets::EffectSettings *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((activeEffect))->FUN_00825c00()))))->GetLowestAllowedSlope();
            if (immediate)
            {
                reinterpret_cast<::ActiveEffect *>((active))->AddFlags(4);
                reinterpret_cast<::ActiveEffect *>((active))->AddFlags(16);
            }
            switch (spellB->GetSpellType())
            {
            case 8: {
                if (ingredientSlot11 && reinterpret_cast<IngredientView*>(ingredientSlot11)->flags.HasFoodEffect())
                    reinterpret_cast<::FUN_00693d50_shell *>((active))->FUN_00693d50(1.0f);
                else
                {
                    EffectSettings* _settings = ((::CastTargets::EffectSettings *)(reinterpret_cast<::ActiveEffect *>((active))->GetEffectSetting()));
                    float magnitude = 0, _duration = 0;
                    if (!reinterpret_cast<::S3e60 *>((_settings))->FUN_00403e60(0x80) && !reinterpret_cast<::S3e60 *>((_settings))->FUN_00403e60(0x100))
                        ::ComputeDerivedValues(&magnitude, &_duration, _cost, power, 6, 0, 0, 0, 0, 0);
                    else if (!reinterpret_cast<::S3e60 *>((_settings))->FUN_00403e60(0x80) && reinterpret_cast<::S3e60 *>((_settings))->FUN_00403e60(0x100))
                        ::ComputeScaledResult(&_duration, _cost, power, 6, 0, 0, 0, 0, 0);
                    else if (reinterpret_cast<::S3e60 *>((_settings))->FUN_00403e60(0x80) && !reinterpret_cast<::S3e60 *>((_settings))->FUN_00403e60(0x100))
                        ::fnv_00648810::ComputeSettingAdjustedValue(&magnitude, _cost, power, 6, 0, 0, 0, 0, 0);
                    _duration = ::InventoryStackRecord::RoundToNearestStep(_duration, 1.0f);
                    magnitude = ::InventoryStackRecord::RoundToNearestStep(magnitude, 1.0f);
                    reinterpret_cast<::FUN_00693d50_shell *>((active))->FUN_00693d50(_duration);
                    ::FUN_00804cb0((void *)(active), magnitude);
                }
                break;
            }
            case 0:
                if (!abFlag4 || (abFlag4 && reinterpret_cast<::EffectItem *>((((::CastTargets::Effect *)(reinterpret_cast<::FUN_0084e3a0_Class *>((active))->FUN_0084e3a0()))))->IsHostile()))
                    reinterpret_cast<::ActiveEffect *>((active))->SetEffectiveness(Effectiveness(false, 0) * multiplier);
                break;
            case 7: {
                if (alchemy2 && reinterpret_cast<::FUN_004029d0_shell *>((alchemy2))->FUN_004029d0(4))
                {
                    float potency = casterActorSlot25->AttachSubObject() * multiplier;
                    if (casterActorSlot25->IsCharacter() && reinterpret_cast<::EffectItem *>((((::CastTargets::Effect *)(reinterpret_cast<::FUN_0084e3a0_Class *>((active))->FUN_0084e3a0()))))->GetAffectedActorValue() == 16)
                        ::ApplyPerkModifiers(12, (::Actor *)(casterActorSlot25), &potency);
                    reinterpret_cast<::ActiveEffect *>((active))->SetEffectiveness(potency);
                }
                if (alchemy2 && reinterpret_cast<::FUN_004029d0_shell *>((alchemy2))->FUN_004029d0(2) && reinterpret_cast<::EffectItem *>((((::CastTargets::Effect *)(reinterpret_cast<::FUN_0084e3a0_Class *>((active))->FUN_0084e3a0()))))->GetAffectedActorValue() != 54)
                {
                    float foodPower = casterActorSlot25->FUN_008bec80() * multiplier;
                    if (casterActorSlot25->IsCharacter() && reinterpret_cast<::EffectItem *>((((::CastTargets::Effect *)(reinterpret_cast<::FUN_0084e3a0_Class *>((active))->FUN_0084e3a0()))))->GetAffectedActorValue() == 16)
                        ::ApplyPerkModifiers(12, (::Actor *)(casterActorSlot25), &foodPower);
                    reinterpret_cast<::ActiveEffect *>((active))->SetEffectiveness(foodPower);
                }
                else if (alchemy2 && reinterpret_cast<::FUN_004029d0_shell *>((alchemy2))->FUN_004029d0(2) && reinterpret_cast<::EffectItem *>((((::CastTargets::Effect *)(reinterpret_cast<::FUN_0084e3a0_Class *>((active))->FUN_0084e3a0()))))->GetAffectedActorValue() == 54)
                {
                    float modifier = 1.0f;
                    ::ApplyPerkModifiers(44, (::Actor *)(casterActorSlot25), &modifier);
                    reinterpret_cast<::ActiveEffect *>((active))->SetEffectiveness(multiplier * modifier);
                }
                break;
            }
            }
            if (reinterpret_cast<::FUN_0084e3a0_Class *>((effect))->FUN_0084e3a0() == 0 && !touchPotionSlot30)
            {
                if (effect != kSelfEffect)
                {
                    reinterpret_cast<::ActiveEffect *>((active))->AddFlags(4);
                    reinterpret_cast<::ActiveEffect *>((active))->AddFlags(2);
                    reinterpret_cast<::ActiveEffect *>((active))->AddFlags(8);
                }
                bool accepted = HasActiveEffect(active);
                if (accepted)
                    didTarget2 = true;
            }
            else if (reinterpret_cast<::FUN_0084e3a0_Class *>((effect))->FUN_0084e3a0() == 1 || touchPotionSlot30)
            {
                if (effect != (touchPotionSlot30 ? kSelfEffect : aTouchEffect))
                {
                    reinterpret_cast<::ActiveEffect *>((active))->AddFlags(4);
                    reinterpret_cast<::ActiveEffect *>((active))->AddFlags(2);
                    reinterpret_cast<::ActiveEffect *>((active))->AddFlags(8);
                }
                if (target6)
                {
                    if (reinterpret_cast<::MagicCaster *>(this)->AddEffectToTarget((::MagicTarget *)(target6), (*(::NiPoint3 *)&(const ::CastTargets::Point &)((*reinterpret_cast<::CastTargets::Point *>((void *)&::NiPoint3::ZERO)))), spellB, (::ActiveEffect *)(active), false))
                        didTarget2 = true;
                    if (reinterpret_cast<::FUN_00404420_shell *>((effect))->FUN_00404420() > 0 && aTargetObject)
                    {
                        bool blocked = false;
                        reinterpret_cast<::Caster *>(this)->ApplyAreaEffect((::Magic *)(spellB), (::Item *)(active), (int)(((void *)(reinterpret_cast<::LowProcess *>((aTargetObject))->GetTarget()))), (*(::Vec *)&(const ::CastTargets::Point &)(*aTargetObject->GetPosition())),
                                        (::Target *)(target6), (::Filter *)(false), (::Node *)(::CastTargets::Context *)(&contextSlot12), &blocked, 1.0f);
                        if (blocked)
                            didTarget2 = false;
                    }
                }
                else if (!touchPotionSlot30 && spellFormSlot1 &&
                         ((bool)(reinterpret_cast<::FlaggedData *>((reinterpret_cast<SpellView*>(spellFormSlot1)))->ContainsAnyFlag(0x80))) &&
                         reinterpret_cast<::FUN_00404420_shell *>((effect))->FUN_00404420() > 0 && casterActorSlot25)
                {
                    bool blockedCaster = false;
                    reinterpret_cast<::Caster *>(this)->ApplyAreaEffect((::Magic *)(spellB), (::Item *)(active), (int)(((void *)(reinterpret_cast<::LowProcess *>((casterActorSlot25))->GetTarget()))),
                                    (*(::Vec *)&(const ::CastTargets::Point &)(*casterActorSlot25->GetPosition())), (::Target *)(target6), (::Filter *)(false), (::Node *)(::CastTargets::Context *)(&contextSlot12), &blockedCaster,
                                    1.0f);
                    if (blockedCaster)
                        didTarget2 = false;
                }
            }
            delete active;
        }
        if (spellB->GetSpellType() == 8)
            cursorA = 0;
        else
            cursorA = static_cast<EffectList*>(((::CastTargets::EffectLink *)(reinterpret_cast<::Callees *>((cursorA))->FUN_00726070())));
    }
    MagicArt* artSlot15 = reinterpret_cast<MagicAccessor*>(spellB)->FUN_0040a300(false);
    Effect* areaEffect7 = ((::CastTargets::Effect *)(reinterpret_cast<::fnv_004064d0::EffectItemList *>((reinterpret_cast<MagicView*>(spellB)))->FindCostliestEffectItem(1, true)));
    bool specialSlot29 = spellFormSlot1 && ((bool)(reinterpret_cast<::FlaggedData *>((reinterpret_cast<SpellView*>(spellFormSlot1)))->ContainsAnyFlag(0x80)));
    Object* areaTarget3 =
        aTargetObject ? aTargetObject : ((casterActorSlot25 && specialSlot29) ? casterActorSlot25 : 0);
    if (areaTarget3)
    {
        Point position;
        PositionProvider* provider3 =
            (casterActorSlot25 && !source) ? casterActorSlot25->caster.GetSourcePosition() : 0;
        position = provider3 ? *((::CastTargets::Point *)(::FUN_0045bb80((int)(provider3)))) : *areaTarget3->GetPosition();
        if (areaEffect7)
        {
            reinterpret_cast<::Master *>(this)->FUN_00817b90((*(::Vec3 *)&(const ::CastTargets::Point &)(position)), (::ListHandle *)(void *)(((void *)(reinterpret_cast<::LowProcess *>((areaTarget3))->GetTarget()))), spellB, (::RangeManager *)(areaEffect7), (::TargetInterface *)(::CastTargets::Context *)(&contextSlot12), 1.0f, 1.0f);
            if (artSlot15 && artSlot15->model.FUN_0048cee0())
            {
                Point direction(-::FUN_005c53d0(-((::CastTargets::Point *)(reinterpret_cast<::TESRecipe *>((areaTarget3))->GetData()))->x),
                                ::FUN_005b9e80(-((::CastTargets::Point *)(reinterpret_cast<::TESRecipe *>((areaTarget3))->GetData()))->x), 0);
                ModelInstance* instance2 =
                    ((::CastTargets::ModelInstance *)(::FUN_006890b0((::World *)(void *)(((void *)(reinterpret_cast<::LowProcess *>((areaTarget3))->GetTarget()))), 1.0f, (int)(artSlot15->model.GetModelFilePath()), (*(::Vec3 *)&(const ::CastTargets::Point &)(direction)),
                                 (*(::Vec3 *)&(const ::CastTargets::Point &)(position)), 1.0f, 7, 0)));
                reinterpret_cast<::FUN_00689920_shell *>((instance2))->FUN_00689920(DAT_0102054c);
                if (((::CastTargets::Node *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((instance2))->FUN_00490e40())))
                {
                    float areaScale = reinterpret_cast<::FUN_00404420_shell *>((areaEffect7))->FUN_00404420() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CastTargets::Setting *>(&::originalRuntimeFloatSetting1137))))));
                    if (areaScale > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CastTargets::Setting *>(&::originalRuntimeFloatSetting1138)))))))
                        areaScale = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CastTargets::Setting *>(&::originalRuntimeFloatSetting1138))))));
                    else if (areaScale < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CastTargets::Setting *>(&::originalRuntimeFloatSetting1139)))))))
                        areaScale = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CastTargets::Setting *>(&::originalRuntimeFloatSetting1139))))));
                    reinterpret_cast<::FUN_00440490_shell *>((((::CastTargets::Node *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((instance2))->FUN_00490e40()))))->FUN_00440490(areaScale);
                }
            }
        }
        else if (areaTarget3->IsActor() && aTouchEffect && reinterpret_cast<::S3e60 *>((((::CastTargets::EffectSettings *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((aTouchEffect))->FUN_00825c00()))))->FUN_00403e60(0x20000000))
        {
            ActorView* actor = reinterpret_cast<ActorView*>(areaTarget3);
            if (reinterpret_cast<::fnv_00817970::CasterOps *>(this)->CheckHealthDamageKill((::fnv_00817970::Recipient *)(::CastTargets::TargetPart *)(static_cast<TargetPart*>(actor)), (::fnv_00817970::EffectSpec *)(spellB)))
                reinterpret_cast<::fnv_00818310::ExplosionCaster *>(this)->ApplyExplosion((::fnv_00818310::ExplosionActor *)(actor), (*(::NiPoint3 *)&(const ::CastTargets::Point &)(position)), (::fnv_00818310::ExplosionEffect *)(aTouchEffect), reinterpret_cast<::FUN_00403f00_shell *>((aTouchEffect))->FUN_00403f00());
        }
    }
    reinterpret_cast<::FileMatchList *>(&(contextSlot12))->RemoveAll();
    if (reinterpret_cast<::fnv_00405f30::EILStandIn *>((reinterpret_cast<MagicView*>(spellB)))->HasNonDetrimentalEffect())
        reinterpret_cast<::FUN_00818610_class *>(this)->CastAimEffect();
    else if (didTarget2 && casterActorSlot25 && (spellB->GetSpellType() == 0 || spellB->GetSpellType() == 5))
        casterActorSlot25->UseSkill(((void *)(::FUN_004065e0((::EffectItemList_shell *)(reinterpret_cast<MagicView*>(spellB))))), 0);
    if (releaseModel && artSlot15 && artSlot15->model.FUN_0048cee0() > 0)
        reinterpret_cast<::FUN_00445300_shell *>(((*reinterpret_cast<::CastTargets::Loader * *>(&::g_modelLoader))))->FUN_00445300((char *)(artSlot15->model.GetModelFilePath()), false, 1);
    SetSpell(0);
    SetMagicTarget(0);
    reinterpret_cast<::MagicCaster *>(this)->SetState((::MagicCaster__State)(0), (char *)(0));
    if (potion && casterActorSlot25)
    {
        AlchemyItem* consumed = dynamic_cast<AlchemyItem*>(spellB);
        if (consumed)
            reinterpret_cast<::FUN_00824e70_shell *>(&(casterActorSlot25->target))->ApplyAddiction((::StandinAlchemyItem *)(consumed));
    }
}
}

#include <xmmintrin.h>
namespace fnv_00818150 {
#include <xmmintrin.h>

struct Vec3
{
    float x;
    float y;
    float z;
    Vec3();
    Vec3 operator-(const Vec3& o) const;
    Vec3 operator*(float f) const;
    float& operator[](unsigned int i);
};

struct MassVec;
struct hkVector4
{
    __m128 v;
    hkVector4();
};

struct RefNode;

struct PushRef
{
    RefNode* GetNode();
};

struct MassVec
{
    __m128 v;
    MassVec(float f);
};

struct EffectStub
{
};

template <class T> struct SettingT
{
    float* Float();
};
struct GameSettingCollection;


struct Pusher
{
    void FUN_00818150(PushRef* target, Vec3 origin, EffectStub* effect, float magnitude);
};

// Computes a force on target from origin and effect, clamps and scales it, then applies the resulting impulse to the target.
// @fnv 0x00818150
void Pusher::FUN_00818150(PushRef* target, Vec3 origin, EffectStub* effect, float magnitude)
{
    Vec3 pos;
    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&pos)), (*(const ::hkVector4 *)(target->GetNode())));
    Vec3 vDirection = pos - origin;
    float dist = reinterpret_cast<::NiPoint3 *>((void *)&(vDirection))->GetLengthSquared();
    float force = ::ComputeBlastPower((int)magnitude, (int)((double)reinterpret_cast<::FUN_00404420_shell *>((effect))->FUN_00404420() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00818150::SettingT< ::fnv_00818150::GameSettingCollection> *>(&::originalRuntimeFloatSetting1112))))))),
                            dist, 0, 0, 0.0f);
    if (force > ::_DAT_01012060)
    {
        if (force > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00818150::SettingT< ::fnv_00818150::GameSettingCollection> *>(&::originalRuntimeFloatSetting1131)))))))
            force = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00818150::SettingT< ::fnv_00818150::GameSettingCollection> *>(&::originalRuntimeFloatSetting1131))))));
        force = force * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_00818150::SettingT< ::fnv_00818150::GameSettingCollection> *>(&::originalRuntimeFloatSetting1136))))));
        reinterpret_cast<::FUN_004a51b0_shell *>((void *)&(const ::fnv_00818150::Vec3 &)(vDirection))->FUN_004a51b0(2) += 0.5;
        Vec3 vImpulse = vDirection * force;
        hkVector4 v;
        ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(v), (const ::fnv_004a3e00::NiPoint3 &)(vImpulse));
        MassVec m(reinterpret_cast<::fnv_004b4ea0::TESDataHandler *>((target))->FUN_004b4ea0());
        reinterpret_cast<::S_00627920 *>(&(v))->FUN_00627920((::S_00561240 *)&(m));
        reinterpret_cast<::hkpEntityC9C *>((target))->FUN_00c9c1d0();
        reinterpret_cast<::B8182D0Object *>((target))->ApplyToTarget((void *)&(v));
    }
}
}  // namespace fnv_00818150
