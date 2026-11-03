// fallout_shared/tescreature.cpp: TESCreature, DelStandIn, ActorValue, StandIn and more (45 functions)

#include <new>
#include <cstring>
#include <malloc.h>
#include "fnv/decl/ActorBaseSaveView.h"
#include "fnv/decl/ActorSpellView.h"
#include "fnv/decl/B50F600Ref.h"
#include "fnv/decl/B5FA120Checker.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BipedAnim.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ContainerItemExtra.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_00461560_shell.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_0047bd70_shell.h"
#include "fnv/decl/FUN_0047bdd0_shell.h"
#include "fnv/decl/FUN_0047cac0_t.h"
#include "fnv/decl/FUN_0047d800_shell.h"
#include "fnv/decl/FUN_0047fb50_shell.h"
#include "fnv/decl/FUN_0047ff50_class.h"
#include "fnv/decl/FUN_00480000_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004870f0_shell.h"
#include "fnv/decl/FUN_00487240_shell.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_00489a60.h"
#include "fnv/decl/FUN_00489ba0_shell.h"
#include "fnv/decl/FUN_004bfe50_t.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00503240_shell.h"
#include "fnv/decl/FUN_00507780.h"
#include "fnv/decl/FUN_00572fc0_shell.h"
#include "fnv/decl/FUN_005e50f0_Obj.h"
#include "fnv/decl/FUN_005e5190_Class.h"
#include "fnv/decl/FUN_005f03a0_shell.h"
#include "fnv/decl/FUN_005f0640_shell.h"
#include "fnv/decl/FUN_005f7b50_Class.h"
#include "fnv/decl/FUN_005f8bd0_Helper.h"
#include "fnv/decl/FUN_00803a90_shell.h"
#include "fnv/decl/FUN_00821640_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_0087b440_holder.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_008b4360_Class.h"
#include "fnv/decl/FUN_008b4cd0_class.h"
#include "fnv/decl/FUN_008b4cf0_class.h"
#include "fnv/decl/FUN_008b5190_Class.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/Header47cb90.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/ModelCopyView.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S00489ce0.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/TESEnchantableForm.h"
#include "fnv/decl/TESFile.h"
#include "fnv/decl/TESSpellListShell.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Thing575.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_009c0070.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047d220__ABD_47d220.h"
#include "fnv/decl/fnv_0047e1c0__S47b.h"
#include "fnv/decl/fnv_0047e270__FUN_0047e270_shell.h"
#include "fnv/decl/fnv_0047f500__FUN_0047f500_shell.h"
#include "fnv/decl/fnv_004817f0__FUN_004817f0_shell.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00489db0__FUN_00489db0_shell.h"
#include "fnv/decl/fnv_0048cce0__FUN_0048cce0_shell.h"
#include "fnv/decl/fnv_0048d290__FUN_0048d290_shell.h"
#include "fnv/decl/fnv_0048d630__SpellListAccess.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_005f14b0__FUN_005f14b0_Class.h"
#include "fnv/decl/fnv_005f14d0__TESAttributes.h"
#include "fnv/decl/fnv_005f14f0__TESAttributes.h"
#include "fnv/decl/fnv_005f1510__FUN_005f1510.h"
#include "fnv/decl/fnv_005f1530__TESAttributes.h"
#include "fnv/decl/fnv_005f1550__TESAttributes.h"
#include "fnv/decl/fnv_005f1570__TESAttributes.h"
#include "fnv/decl/fnv_005f18c0__SaveActorBase.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008b52a0__ActorView.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00567000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005f9000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_008f2000.h"
#include "fnv/symbols_01000000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011df000.h"
#include "tescreature_decls.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/decl/ActorBaseInitItemView.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/FUN_0047f4c0_shell.h"
#include "fnv/decl/FUN_00484d40_Host.h"
#include "fnv/decl/FUN_00565210_shell.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_005f1b30__ActorBaseLoad.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00505000.h"
#include "tescreature_decls_rtti2_tescreature.h"
#include "tescreature_decls_rtti_variant.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005f06f0_shell.h"
#include "tescreature_decls_rtti_variant_decl_tescreature_rtti_variant.h"
#include <string.h>

// @fnv 0x005F7900
TESCreature::~TESCreature()
{
    ClearData();
}

// @fnv 0x005F7B80
void TESCreature::ClearData()
{
    if ((static_cast<TESActorBaseData *>(this))->GetFlag(0x100))
    {
        delete m_pCreatureSounds;
        m_pCreatureSounds = 0;
    }
    m_cCreatureDataFlag = 0xff;
}

// @fnv 0x005F7A40
void TESCreature::ResetFormData()
{
    dataPadding = 0;
    m_ucField00 = 50;
    m_ucField01 = 50;
    m_ucField02 = 50;
    m_ucCreatureType = 32;
    m_pImpactDataSet = 0;
    m_pCreatureListForm = 0;
    m_fFirstCreatureStat = 0.0f;
    m_fSecondCreatureStat = ::DAT_01017718;
    m_fThirdCreatureStatCur = 1.0f;
    m_pCreatureSounds = 0;
    m_pCombatStyle = 0;
    m_pBodyPartDataCur = 0;
    m_bHasImpactDataSet = false;
    m_eSoundLevel = 1;
    m_eImpactMaterial = 6;
    m_cCreatureDataFlag = 0xff;
    reinterpret_cast<::FlagSet *>(((static_cast<TESActorBaseData *>(this))))->FUN_0047dd50(0x40, true, false);
    reinterpret_cast<::FUN_005f7b50_Class *>(((static_cast<TESActorBaseData *>(this))))->SetFlag200(false, false);
    ((CombatProcedure*)static_cast<TESHealthForm *>(this))->Initialize((CombatController*)0x32);
}

// @fnv 0x005F9210
CreatureSoundCollection* TESCreature::GetMutableCreatureSounds()
{
    if (!(static_cast<TESActorBaseData *>(this))->GetFlag(0x100) || !m_pCreatureSounds)
    {
        reinterpret_cast<::FlagSet *>(((static_cast<TESActorBaseData *>(this))))->FUN_0047dd50(0x100, true, true);
        m_pCreatureSounds = new CreatureSoundCollection;
    }
    return m_pCreatureSounds;
}

// @fnv 0x005FB3B0
void TESCreature::LoadGame(BGSLoadFormBuffer* buffer)
{
    ((TESActorBase*)this)->LoadGame(buffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(0x200)))->FUN_004280f0())
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_ucField00), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_ucField01), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_ucField02), 1);
    }
}

// @fnv 0x005F9140
void TESCreature::SetCreatureSoundsFrom(TESCreature* soundCreature)
{
    if ((static_cast<TESActorBaseData *>(this))->GetFlag(0x100))
    {
        if (soundCreature)
        {
            delete m_pCreatureSounds;
            reinterpret_cast<::FlagSet *>(((static_cast<TESActorBaseData *>(this))))->FUN_0047dd50(0x100, false, true);
            m_pCreature = soundCreature;
        }
    }
    else
    {
        m_pCreature = soundCreature;
    }
}

// @fnv 0x005FA2E0
BGSBodyPartData* TESCreature::GetBodyPartData()
{
    if (m_pBodyPartDataCur)
        return m_pBodyPartDataCur;
    return BGSBodyPartData::ms_pBodyPartData;
}

// @fnv 0x005FA310
void TESCreature::SetBodyPartData(BGSBodyPartData* bodyPartData)
{
    m_pBodyPartDataCur = bodyPartData;
}

// @fnv 0x005FB430
void TESCreature::Revert(BGSLoadFormBuffer* buffer)
{
    ((TESNPC*)this)->Revert(buffer);
}

// @fnv 0x005F7230
TESCreature::TESCreature()
{
    reinterpret_cast<::FUN_004f15a0_shell *>((((TESForm*)this)))->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(kCreature)));
    ResetFormData();
    static_cast<TESAIForm *>(this)->SetResponsibility(50, false);
    static_cast<TESAIForm *>(this)->SetAggression(1, false);
    static_cast<TESAIForm *>(this)->SetConfidence(2, false);
    static_cast<TESAIForm *>(this)->SetEnergy(2, false);
    if (!reinterpret_cast<::FUN_004516b0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004516b0())
        reinterpret_cast<::FUN_0047d800_shell *>(((static_cast<TESActorBaseData *>(this))))->FUN_0047d800((::TESFaction *)(DAT_011cb550), 0);
}

struct BGSImpactDataSet;
struct QueuedFile;
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct BGSPreloadable : public BaseFormComponent
{
    virtual void QueueResourceLoad(int, QueuedFile*);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct FUN_005f8bb0_shell : public TESCreature
{
    void SetImpactDataSet(BGSImpactDataSet*);
};

// @fnv 0x005f8bb0
void FUN_005f8bb0_shell::SetImpactDataSet(BGSImpactDataSet* apSet)
{
    m_pImpactDataSet = apSet;
}

struct FUN_005f9100_shell : public TESCreature
{
    TESCreature* FUN_005f9100();
};

// Returns the TESCreature at offset 0x128 unless the actor base data has flag 0x100 set, in which case it returns 0.
// @fnv 0x005f9100
TESCreature* FUN_005f9100_shell::FUN_005f9100()
{
    if ((static_cast<TESActorBaseData *>(this))->GetFlag(0x100))
    {
        return 0;
    }
    else
    {
        return this->m_pCreature;
    }
}

struct FUN_005f91d0_shell : public TESCreature
{
    CreatureSoundCollection* FUN_005f91d0();
};

// @fnv 0x005f91d0
CreatureSoundCollection* FUN_005f91d0_shell::FUN_005f91d0()
{
    if ((static_cast<TESActorBaseData *>(this))->GetFlag(0x100))
        return this->m_pCreatureSounds;
    else
        return 0;
}

struct FUN_005f9ad0_shell : public TESCreature
{
    unsigned char FUN_005f9ad0();
};

// @fnv 0x005f9ad0
unsigned char FUN_005f9ad0_shell::FUN_005f9ad0()
{
    return m_ucCreatureType;
}

struct FUN_005f9af0_shell : public TESCreature
{
    void SetCreatureType(unsigned char);
};

// @fnv 0x005f9af0
void FUN_005f9af0_shell::SetCreatureType(unsigned char acVal)
{
    m_ucCreatureType = acVal;
}

struct BGSImpactDataSet;
struct FUN_005f9b30_shell : public TESCreature
{
    BGSImpactDataSet* GetImpactDataSet();
};

// @fnv 0x005f9b30
BGSImpactDataSet* FUN_005f9b30_shell::GetImpactDataSet()
{
    return m_pImpactDataSet;
}

struct FUN_005fa2c0_shell : public TESCreature
{
    void SetByteAt12D(unsigned char);
};

// @fnv 0x005fa2c0
void FUN_005fa2c0_shell::SetByteAt12D(unsigned char aiVal)
{
    this->m_ucField00 = aiVal;
}

struct FUN_005fbdb0_shell : public TESCreature
{
    void FUN_005fbdb0(char);
};

// @fnv 0x005fbdb0
void FUN_005fbdb0_shell::FUN_005fbdb0(char aeType)
{
    *((char*)&this->dataPadding) = aeType;
}

struct FUN_00821660_shell : public TESCreature
{
    float FUN_00821660();
};

// @fnv 0x00821660
float FUN_00821660_shell::FUN_00821660()
{
    return m_fSecondCreatureStat;
}

struct NiFormArray;
struct TESIdleForm;
struct TESObject;
struct TESObjectREFR;
enum ANIM_GROUP_WEAPON_ENUM;
template <class> class BSSimpleList;
struct IdleAnimationManager
{
    void RemoveIdleForm(TESIdleForm*);
    void InitializeIdleAnimations();
    void ResetIdleAnimations();
    void LoadIdleAnimations();
    NiFormArray* AddRootIdleArray(TESForm*);
    NiFormArray* AddRootIdleArray(char*, void*, bool);
    NiFormArray* GetRootIdleArray(TESForm*);
    NiFormArray* GetRootIdleArray(char*);
    NiFormArray* GetIdleArray(TESForm*);
    NiFormArray* GetIdleArray(char*);
    static void BuildIdlePath(char*, char*);
    void* FindIdleArrayEntry(char*, int);
    void ClearIdleData();
    static void SetUsedItem(TESObject*);
    static void SetUsedItemLevel(int);
    static int GetUsedItemLevel();
    static void SetUsedItemActivate(bool);
    static bool GetUsedItemActivate();
    bool GetInitialized();
    TESIdleForm* FindIdleFormForObject(TESObjectREFR*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char m_acIdlePath[20];
    bool bInitialized;
    char _pad_15[3];
    char m_acIdleName[16];
public:
    ::BSSimpleList<const char *> *FindIdleArrayEntry(const char *, ::ANIM_GROUP_WEAPON_ENUM);
};
struct FUN_00843150_shell : public IdleAnimationManager
{
    bool FUN_00843150();
};

// @fnv 0x00843150
bool FUN_00843150_shell::FUN_00843150()
{
    return bInitialized;
}

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_005f75b0(unsigned int flags);
};
// Runs the destructor on this object, then frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x005f75b0
void* DelStandIn::FUN_005f75b0(unsigned int flags)
{
    reinterpret_cast<::TESCreature *>((((DtorStandIn*)this)))->TESCreature::~TESCreature();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct FUN_0050f760_shell
{
    int FUN_0050f760(int);
};
// @fnv 0x0050f760
int FUN_0050f760_shell::FUN_0050f760(int a)
{
    return ((int)(reinterpret_cast<::B50F600Ref *>(this)->FUN_0050f600(a)));
}

struct FUN_0051f4b0_shell
{
    void FUN_0051f4b0(int value);
};

// @fnv 0x0051f4b0
void FUN_0051f4b0_shell::FUN_0051f4b0(int value)
{
    *(int*)((char*)this + 0x118) = value;
}

struct FUN_0047ded0_shell
{
    unsigned short FUN_0047ded0(void);
};

struct FUN_005f7460_shell
{
    void FUN_005f7460();
};

// @fnv 0x005f7460
void FUN_005f7460_shell::FUN_005f7460()
{
    ((FUN_0047ded0_shell*)((char*)this - 0xd0))->FUN_0047ded0();
}

struct FUN_005f7570_shell
{
    void* FUN_005f7570();
};
// @fnv 0x005f7570
void* FUN_005f7570_shell::FUN_005f7570()
{
    return (char*)this - 0x100;
}

struct FUN_005f9040_shell : public TESActorBaseData
{
    bool FUN_005f9040();
};
// @fnv 0x005f9040
bool FUN_005f9040_shell::FUN_005f9040()
{
    return GetFlag(0x20000);
}

struct FUN_005f9060_shell : public TESActorBaseData
{
    bool FUN_005f9060();
};
// @fnv 0x005f9060
bool FUN_005f9060_shell::FUN_005f9060()
{
    return GetFlag(0x10000);
}

struct FUN_005f9080_shell : public TESActorBaseData
{
    bool FUN_005f9080();
};
// @fnv 0x005f9080
bool FUN_005f9080_shell::FUN_005f9080()
{
    return GetFlag(0x8000);
}

struct FUN_005f90a0_shell : public TESActorBaseData
{
    bool FUN_005f90a0();
};
// @fnv 0x005f90a0
bool FUN_005f90a0_shell::FUN_005f90a0()
{
    return GetFlag(0x80000);
}


struct FUN_005f90c0_shell : TESActorBaseData
{
    bool FUN_005f90c0();
};

// @fnv 0x005f90c0
bool FUN_005f90c0_shell::FUN_005f90c0()
{
    return ((TESActorBaseData*)((char*)this + 0x30))->GetFlag((unsigned int)&DAT_01000000);
}

struct FUN_005f90e0_shell : TESActorBaseData
{
    bool FUN_005f90e0();
};

// @fnv 0x005f90e0
bool FUN_005f90e0_shell::FUN_005f90e0()
{
    return ((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x2000000);
}

struct FUN_005f9b10_class
{
    void SetBoltSmallWidth(float afBoltSmallWidth);
};

// @fnv 0x005f9b10
void FUN_005f9b10_class::SetBoltSmallWidth(float afBoltSmallWidth)
{
    *(float*)((char*)this + 0x138) = afBoltSmallWidth;
}

struct FUN_005f9b70_shell
{
    void* GetOffset12C();
};
// @fnv 0x005f9b70
void* FUN_005f9b70_shell::GetOffset12C()
{
    return (char*)this + 0x12c;
}

struct ActorValue
{
    enum Index
    {
        kNone
    };
};
struct FUN_006078e0_s
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void SetFlags(int);
    void FUN_006078e0(ActorValue::Index aiWhich, int aiValue);
};
struct FUN_008126e0_shell
{
    void SetWhich(int aiWhich);
};

// @fnv 0x008126e0
void FUN_008126e0_shell::SetWhich(int aiWhich)
{
    *(int*)((char*)this + 0x140) = aiWhich;
}

struct FUN_005f8f10_shell : TESActorBaseData
{
    unsigned short GetScaledFatigue();
};

// Returns fatigue, multiplied by FUN_0047ded0 (clamped to at least 1) when GetMatchesPCLevel is true.
// @fnv 0x005f8f10
unsigned short FUN_005f8f10_shell::GetScaledFatigue()
{
    unsigned short fatigue = reinterpret_cast<::TESActorBaseData *>(this)->GetFatigue();
    if (reinterpret_cast<::FUN_00461560_shell *>(this)->FUN_00461560())
    {
        short value = reinterpret_cast<::FUN_0047ded0_shell *>(this)->FUN_0047ded0();
        if (value < 1)
            value = 1;
        fatigue = (unsigned short)(value * (unsigned short)fatigue);
    }
    return fatigue;
}

struct FUN_005f7420_shell
{
    virtual void _v0();
    virtual double _v1(int);
    virtual void _v2();
    virtual void _v3();
    virtual void _v4();
    virtual void _v5();
    virtual double _v6(int);
    float GetSumOfVirtualValues(int);
};
// Returns the sum of the two virtual calls _v1 and _v6 for the given index, cast to float.
// @fnv 0x005f7420
float FUN_005f7420_shell::GetSumOfVirtualValues(int aiWhich)
{
    return (float)(_v1(aiWhich) + _v6(aiWhich));
}

struct FUN_005f78b0_shell
{
    void* DestroyActorBase(unsigned int);
};
struct FUN_005f8e90_shell : public TESActorBaseData
{
    int FUN_005f8e90();
};

// @fnv 0x005f8e90
int FUN_005f8e90_shell::FUN_005f8e90()
{
    unsigned short result = 0;
    if (reinterpret_cast<::FUN_00461560_shell *>((reinterpret_cast<FUN_005f8e90_shell*>(reinterpret_cast<char*>(this) - 0x80)))->FUN_00461560())
    {
        short factor = ((short)(reinterpret_cast<::FUN_0047ded0_shell *>((reinterpret_cast<FUN_005f8e90_shell*>(reinterpret_cast<char*>(this) - 0x80)))->FUN_0047ded0()));
        if (factor < 1)
            factor = 1;
        result = factor * ((int)(reinterpret_cast<::Callees *>(this)->FUN_00726070()));
    }
    else
    {
        result = ((int)(reinterpret_cast<::Callees *>(this)->FUN_00726070()));
    }
    return result;
}

struct FUN_005f16f0_shell
{
};
struct FUN_005fb180_shell : FUN_005f16f0_shell
{
    unsigned short FUN_005fb180(unsigned int);
};
// @fnv 0x005fb180
unsigned short FUN_005fb180_shell::FUN_005fb180(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::ActorBaseSaveView *>(this)->FUN_005f16f0(aiFlags);
    if (aiFlags & 0x200)
        isize += 3;
    if (aiFlags & 0)
        isize += 4;
    return isize;
}

struct BGSSaveFormBuffer
{
};
struct FUN_005f1f30_shell
{
public:
    void FUN_005f1f30(unsigned int);
};
struct FUN_005fb330_shell
{
    void FUN_005fb330(BGSSaveFormBuffer* buffer);
};
// Calls FUN_005f1f30, then if change flag 0x200 is set saves three bytes at offsets 0x12d, 0x12e and 0x12f into the buffer.
// @fnv 0x005fb330
void FUN_005fb330_shell::FUN_005fb330(BGSSaveFormBuffer* buffer)
{
    ((FUN_005f1f30_shell*)this)->FUN_005f1f30((unsigned int)(buffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(((BGSLoadFormBuffer*)buffer)->GetChangeFlags(0x200)))->FUN_004280f0())
    {
        reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 0x12d, 1, 0);
        reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 0x12e, 1, 0);
        reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 0x12f, 1, 0);
    }
}

struct FUN_005f73f0_Holder
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual float v8(int);
    int ConvertVirtualResultToInt(int);
};
// Calls the virtual v8 with a and converts the returned float to int via FUN_00406ce0.
// @fnv 0x005f73f0
int FUN_005f73f0_Holder::ConvertVirtualResultToInt(int a)
{
    return (int)FUN_00406ce0(v8(a));
}

struct FakeAVOwner
{
    virtual void b0() = 0;
    virtual void b1() = 0;
    virtual void b2() = 0;
    virtual float GetAV(int) = 0;
};
struct FakePrimary
{
    virtual void a0() = 0;
    virtual void a1() = 0;
    virtual void a2() = 0;
    virtual void a3() = 0;
    virtual void a4() = 0;
    virtual void a5() = 0;
    virtual void a6() = 0;
    virtual void a7() = 0;
    virtual void a8() = 0;
    virtual void a9() = 0;
    virtual void a10() = 0;
    virtual void a11() = 0;
    virtual void a12() = 0;
    virtual void a13() = 0;
    virtual void a14() = 0;
    virtual void a15() = 0;
    virtual void a16() = 0;
    virtual void a17() = 0;
    virtual void a18() = 0;
    virtual void a19() = 0;
    virtual void a20() = 0;
    virtual void a21() = 0;
    virtual void a22() = 0;
    virtual void a23() = 0;
    virtual void a24() = 0;
    virtual void a25() = 0;
    virtual void a26() = 0;
    virtual void a27() = 0;
    virtual void a28() = 0;
    virtual void a29() = 0;
    virtual void a30() = 0;
    virtual void a31() = 0;
    virtual void a32() = 0;
    virtual void a33() = 0;
    virtual void a34() = 0;
    virtual void a35() = 0;
    virtual void a36() = 0;
    virtual void a37() = 0;
    virtual void a38() = 0;
    virtual void a39() = 0;
    virtual void a40() = 0;
    virtual void a41() = 0;
    virtual void a42() = 0;
    virtual void a43() = 0;
    virtual void a44() = 0;
    virtual void a45() = 0;
    virtual void a46() = 0;
    virtual void a47() = 0;
    virtual void a48() = 0;
    virtual void a49() = 0;
    virtual void a50() = 0;
    virtual void a51() = 0;
    virtual void a52() = 0;
    virtual void a53() = 0;
    virtual void a54() = 0;
    virtual void a55() = 0;
    virtual void a56() = 0;
    virtual void a57() = 0;
    virtual void a58() = 0;
    virtual void a59() = 0;
    virtual void a60() = 0;
    virtual void a61() = 0;
    virtual void a62() = 0;
    virtual void a63() = 0;
    virtual void a64() = 0;
    virtual void a65() = 0;
    virtual void a66() = 0;
    virtual void a67() = 0;
    virtual void a68() = 0;
    virtual void a69() = 0;
    virtual void a70() = 0;
    virtual void a71() = 0;
    virtual void a72() = 0;
    virtual void a73() = 0;
    virtual void a74() = 0;
    virtual void a75() = 0;
    virtual void a76() = 0;
    virtual void a77() = 0;
    virtual void a78() = 0;
    virtual void a79() = 0;
    virtual void a80() = 0;
    virtual void a81() = 0;
    virtual void a82() = 0;
    virtual void a83() = 0;
    virtual void a84() = 0;
    virtual void a85() = 0;
    virtual void a86() = 0;
    virtual void a87() = 0;
    virtual void a88() = 0;
    virtual void a89() = 0;
    virtual void a90() = 0;
    virtual void a91() = 0;
    virtual void a92() = 0;
    virtual void a93() = 0;
    virtual void a94() = 0;
    virtual void a95() = 0;
    virtual void a96() = 0;
    virtual void a97() = 0;
    virtual void a98() = 0;
    virtual void a99() = 0;
    virtual void SetAV(int, float) = 0;
    char _pad[252];
};
struct StandIn : FakePrimary, FakeAVOwner
{
    void FUN_005f7520(int, float);
};
// Adds aiValue to the actor value aiWhich by reading GetAV and writing the sum back with SetAV.
// @fnv 0x005f7520
void StandIn::FUN_005f7520(int aiWhich, float aiValue)
{
    SetAV(aiWhich, GetAV(aiWhich) + aiValue);
}

struct FUN_0050f6f0
{
    FUN_0050f6f0();
    ~FUN_0050f6f0();
    virtual void v0();
    int d[11];
};
struct FUN_0047c700
{
    FUN_0047c700();
    ~FUN_0047c700();
    virtual void v0();
    int d[12];
};
struct FUN_00481610
{
    FUN_00481610();
    ~FUN_00481610();
    virtual void v0();
    int d[2];
};
struct FUN_0047bd10
{
    FUN_0047bd10();
    virtual void v0();
    int d[2];
};
struct FUN_0048cfe0
{
    FUN_0048cfe0();
    ~FUN_0048cfe0();
    virtual void v0();
    int d[4];
};
struct FUN_0047ec40
{
    FUN_0047ec40();
    ~FUN_0047ec40();
    virtual void v0();
    int d[7];
};
struct FUN_004871d0
{
    FUN_004871d0();
    ~FUN_004871d0();
    virtual void v0();
    int d[1];
};
struct FUN_0047ff70
{
    FUN_0047ff70();
    ~FUN_0047ff70();
    virtual void v0();
    int d[2];
};
struct FUN_0047f9c0
{
    FUN_0047f9c0();
    ~FUN_0047f9c0();
    virtual void v0();
    int d[2];
};
struct FUN_00402d00
{
    FUN_00402d00();
    ~FUN_00402d00();
    virtual void v0();
    int d[2];
};
struct FUN_00488f50
{
    FUN_00488f50();
    ~FUN_00488f50();
    virtual void v0();
    int d[5];
};
struct FUN_0048cc50
{
    FUN_0048cc50();
    virtual void v0();
    int d[2];
};
struct FUN_005f78e0
{
    FUN_005f78e0();
    virtual void v0();
};
struct FUN_00475350
{
    FUN_00475350();
    virtual void v0();
    int d[1];
};

struct FUN_005f75e0 : public FUN_0050f6f0,
                      public FUN_0047c700,
                      public FUN_00481610,
                      public FUN_0047bd10,
                      public FUN_0048cfe0,
                      public FUN_0047ec40,
                      public FUN_004871d0,
                      public FUN_0047ff70,
                      public FUN_0047f9c0,
                      public FUN_00402d00,
                      public FUN_00488f50,
                      public FUN_0048cc50,
                      public FUN_005f78e0,
                      public FUN_00475350
{
    FUN_005f75e0();
};

// Empty constructor that initializes the object's base subobjects.
// @fnv 0x005f75e0
FUN_005f75e0::FUN_005f75e0()
{}

struct FUN_005f0b30_shell
{
    void FUN_005f0b30(int);
};

struct FUN_005f12d0_AIForm
{
};

struct FUN_005f12d0_ActorBase
{
};

struct FUN_005f12d0_MoodForm
{
};

struct FUN_005f12d0_shell : public FUN_005f0b30_shell
{
    void ApplyCommand(int, int);
};
// Stores a skill actor value as a byte at offset 0x114 and sets flag 0x200, otherwise forwards to ApplyCommand.
// @fnv 0x006078e0
void FUN_006078e0_s::FUN_006078e0(ActorValue::Index aiWhich, int aiValue)
{
    if (::FUN_0047f060((*(int *)&(aiWhich))))
    {
        reinterpret_cast<unsigned char*>(this)[0x114 + (char)::ActorValue::ToArrayIndex(2, aiWhich)] =
            (unsigned char)aiValue;
        SetFlags(0x200);
    }
    else
    {
        reinterpret_cast<::FUN_005f12d0_shell *>(this)->ApplyCommand((*(int *)&(aiWhich)), aiValue);
    }
}

// Dispatches a command code to the matching setter on the AI form, mood form, actor base or base shell, passing value as the argument.
// @fnv 0x005f12d0
void FUN_005f12d0_shell::ApplyCommand(int command, int value)
{
    switch (command)
    {
    case 5:
        reinterpret_cast<::fnv_005f14b0::FUN_005f14b0_Class *>((((FUN_005f12d0_AIForm*)((char*)this + 0xb8))))->SetAttribute5((unsigned char)value);
        break;
    case 6:
        reinterpret_cast<::fnv_005f14d0::TESAttributes *>((((FUN_005f12d0_AIForm*)((char*)this + 0xb8))))->FUN_005f14d0((unsigned char)value);
        break;
    case 7:
        reinterpret_cast<::fnv_005f14f0::TESAttributes *>((((FUN_005f12d0_AIForm*)((char*)this + 0xb8))))->FUN_005f14f0((unsigned char)value);
        break;
    case 8:
        reinterpret_cast<::fnv_005f1510::FUN_005f1510 *>((((FUN_005f12d0_AIForm*)((char*)this + 0xb8))))->SetFlag((unsigned char)value);
        break;
    case 9:
        reinterpret_cast<::fnv_005f1530::TESAttributes *>((((FUN_005f12d0_AIForm*)((char*)this + 0xb8))))->FUN_005f1530((unsigned char)value);
        break;
    case 10:
        reinterpret_cast<::fnv_005f1550::TESAttributes *>((((FUN_005f12d0_AIForm*)((char*)this + 0xb8))))->SetAttribute((unsigned char)value);
        break;
    case 11:
        reinterpret_cast<::fnv_005f1570::TESAttributes *>((((FUN_005f12d0_AIForm*)((char*)this + 0xb8))))->FUN_005f1570((unsigned char)value);
        break;
    case 16:
        this->FUN_005f0b30(value);
        break;
    case 0:
        ((TESAIForm*)((char*)this + 0x90))->SetAggression((unsigned char)value, true);
        break;
    case 1:
        ((TESAIForm*)((char*)this + 0x90))->SetConfidence((unsigned char)value, true);
        break;
    case 2:
        ((TESAIForm*)((char*)this + 0x90))->SetEnergy((unsigned char)value, true);
        break;
    case 3:
        ((TESAIForm*)((char*)this + 0x90))->SetResponsibility((unsigned char)value, true);
        break;
    case 4:
        reinterpret_cast<::TESAIForm *>((((FUN_005f12d0_MoodForm*)((char*)this + 0x90))))->SetAIMood((unsigned char)value);
        break;
    case 21:
        reinterpret_cast<::fnv_0047e270::FUN_0047e270_shell *>((((FUN_005f12d0_ActorBase*)((char*)this + 0x30))))->SetSpeedMult((unsigned short)value);
        break;
    case 23:
        reinterpret_cast<::fnv_0047e1c0::S47b *>((((FUN_005f12d0_ActorBase*)((char*)this + 0x30))))->SetClampedValue((float)value);
        break;
    default:
        break;
    }
}

namespace fnv_005fa200 {
struct ActorValue
{
    enum Index
    {
        index_0 = 0
    };
};

struct P09AV
{
};

struct FUN_0047ff50_class
{
};

struct FUN_005fa2c0_shell
{
};

struct FUN_006078e0_s
{
};

struct FUN_005fa200_shell
{
    virtual void vfn_00()
    {}
    virtual void vfn_01()
    {}
    virtual void vfn_02()
    {}
    virtual void vfn_03()
    {}
    virtual void vfn_04()
    {}
    virtual void vfn_05()
    {}
    virtual void vfn_06()
    {}
    virtual void vfn_07()
    {}
    virtual void vfn_08()
    {}
    virtual void vfn_09()
    {}
    virtual void vfn_10()
    {}
    virtual void vfn_11()
    {}
    virtual void vfn_12()
    {}
    virtual void vfn_13()
    {}
    virtual void vfn_14()
    {}
    virtual void vfn_15()
    {}
    virtual void vfn_16()
    {}
    virtual void vfn_17()
    {}
    virtual void vfn_18(int value)
    {}

    void FUN_005fa200(ActorValue::Index index, int value);
};

// @fnv 0x005fa200
void FUN_005fa200_shell::FUN_005fa200(ActorValue::Index index, int value)
{
    if (::FUN_00406d70(index, 0x400))
    {
        reinterpret_cast<::FUN_005fa2c0_shell *>((reinterpret_cast<FUN_005fa2c0_shell*>(this)))->SetByteAt12D(static_cast<unsigned char>(value));
        vfn_18(0x200);
    }
    else
    {
        switch (index)
        {
        case static_cast<ActorValue::Index>(0x38):
            if (value < 0)
            {
                reinterpret_cast<::FUN_0047ff50_class *>((reinterpret_cast<FUN_0047ff50_class*>(reinterpret_cast<char*>(this) + 0x10c)))->FUN_0047ff50(0);
            }
            else if (value > 0xffff)
            {
                reinterpret_cast<::FUN_0047ff50_class *>((reinterpret_cast<FUN_0047ff50_class*>(reinterpret_cast<char*>(this) + 0x10c)))->FUN_0047ff50(0xffff);
            }
            else
            {
                reinterpret_cast<::FUN_0047ff50_class *>((reinterpret_cast<FUN_0047ff50_class*>(reinterpret_cast<char*>(this) + 0x10c)))->FUN_0047ff50(static_cast<unsigned short>(value));
            }
            break;

        default:
            reinterpret_cast<::FUN_005f12d0_shell *>((reinterpret_cast<FUN_006078e0_s*>(this)))->ApplyCommand((*(int *)&(index)), value);
            break;
        }
    }
}
}  // namespace fnv_005fa200

struct FUN_00608e00_shell
{
};

struct PC7d
{
};

struct FUN_00484d20_Class
{
    void ForwardToSaveLoadGame(int, int);
};


struct FUN_005fb1e0_shell
{
    void FUN_005fb1e0(unsigned int);
};

// @fnv 0x005fb1e0
void FUN_005fb1e0_shell::FUN_005fb1e0(unsigned int flags)
{
    reinterpret_cast<::fnv_005f18c0::SaveActorBase *>((reinterpret_cast<FUN_00608e00_shell*>(this)))->FUN_005f18c0(flags);

    if (flags & 0x200)
    {
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(
            (void *)(reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x12d)), 1);
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(
            (void *)(reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x12e)), 1);
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(
            (void *)(reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x12f)), 1);
    }

    if (flags & 0)
    {
        unsigned int result =
            ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((*reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x140)))->FUN_0084e3a0()));
        reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<int>(&result), 4);
    }
}

class CreatureBaseSub_b3926
{
  public:
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
    ~CreatureBaseSub_b3926();
};

class CreatureMemberA_b3926
{
  public:
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
    ~CreatureMemberA_b3926();
};

class CreatureMemberB_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ~CreatureMemberB_b3926();
};

class CreatureMemberC_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    ~CreatureMemberC_b3926();
};

class CreatureMemberD_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ~CreatureMemberD_b3926();
};

class CreatureMemberE_b3926
{
  public:
    int unk00;
    int unk04;
    ~CreatureMemberE_b3926();
};

class CreatureMemberF_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ~CreatureMemberF_b3926();
};

class CreatureMemberG_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ~CreatureMemberG_b3926();
};

class CreatureMemberH_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    ~CreatureMemberH_b3926();
};

class CreatureMemberI_b3926
{
  public:
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
    ~CreatureMemberI_b3926();
};

class CreatureMemberJ_b3926
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~CreatureMemberJ_b3926();
};

class FUN_005f77b0 : public CreatureBaseSub_b3926
{
  public:
    CreatureMemberA_b3926 m_30;
    CreatureMemberB_b3926 m_64;
    CreatureMemberC_b3926 m_7c;
    CreatureMemberD_b3926 m_90;
    CreatureMemberE_b3926 m_b0;
    CreatureMemberF_b3926 m_b8;
    CreatureMemberG_b3926 m_c4;
    CreatureMemberH_b3926 m_d0;
    CreatureMemberI_b3926 m_dc;
    CreatureMemberJ_b3926 m_104;
    ~FUN_005f77b0();
};
// Destructs the TESActorBase and, if flags has bit 0 set, frees the object with operator delete; returns this.
// @fnv 0x005f78b0
void* FUN_005f78b0_shell::DestroyActorBase(unsigned int flags)
{
    reinterpret_cast<::FUN_005f77b0 *>((((TESActorBase*)this)))->FUN_005f77b0::~FUN_005f77b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x005f77b0
FUN_005f77b0::~FUN_005f77b0()
{}

struct FormObj_5f7c20
{
};

struct SoundsObj_5f7c20
{
};

struct Sub30_5f7c20
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30;
};

struct Sub64_5f7c20
{
    int u00, u04, u08;
};

struct Sub70_5f7c20
{
    int u00, u04, u08;
};

struct Sub7c_5f7c20
{
    int u00, u04, u08, u0c, u10;
};

struct Sub90_5f7c20
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    int u20, u24;
    int u28, u2c, u30;
    int u34, u38, u3c;
};

struct Subd0_5f7c20
{
    int u00, u04, u08;
};

struct Subdc_5f7c20
{
    int u00, u04, u08, u0c, u10, u14;
    int u18, u1c, u20;
    int u24;
};

struct Sub104_5f7c20
{
    int u00, u04;
    int u08, u0c;
};

struct Sub114_5f7c20
{
    int u00, u04, u08, u0c, u10;
};

struct Sub12c_5f7c20
{
    int u00;
};


struct Host_5f7c20
{
    virtual void v00();
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
    virtual FormObj_5f7c20* v96();
    virtual void v97();
    virtual FormObj_5f7c20* v98();

    int u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c;
    Sub30_5f7c20 m_30;
    Sub64_5f7c20 m_64;
    Sub70_5f7c20 m_70;
    Sub7c_5f7c20 m_7c;
    Sub90_5f7c20 m_90;
    Subd0_5f7c20 m_d0;
    Subdc_5f7c20 m_dc;
    Sub104_5f7c20 m_104;
    Sub114_5f7c20 m_114;
    int m_128;
    Sub12c_5f7c20 m_12c;
    unsigned char m_130;
    unsigned char m_131;
    unsigned char m_132;
    unsigned char m_133;
    float m_134;
    float m_138;
    float m_13c;
    int m_140;
    int m_144;
    int m_148;
    FormObj_5f7c20* m_14c;
    int m_150;
    int m_154;
    FormObj_5f7c20* m_158;

    void Init();
};

// @fnv 0x005f7c20
void Host_5f7c20::Init()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(&(m_d0))->FUN_00487010();
    reinterpret_cast<::FUN_004891d0_cls *>(&(m_dc))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));
    reinterpret_cast<::TESSpellListShell *>(&(m_7c))->FUN_0048d330();
    reinterpret_cast<::FUN_0047bd70_shell *>(&(m_70))->FUN_0047bd70();
    reinterpret_cast<::FUN_00489ba0_shell *>(&(m_114))->CopyModelListToBuffer((void *)(0x5a46494e), 0x5446494e);
    reinterpret_cast<::FUN_0047cac0_t *>(&(m_30))->DestroySoundHandles();
    reinterpret_cast<::FUN_00477f20_shell *>(&(m_104))->FUN_00477f20();
    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::TESForm *>(&(m_12c))->ClearData();
    }
    reinterpret_cast<::SDSaveForm *>(this)->FUN_00485e20(&m_12c, 4);
    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::TESForm *>(&(m_12c))->ClearData();
    }
    FUN_004858f0(0x4d414e52, m_130);
    if (v98())
    {
        ::FUN_00485910(0x4d414e5a, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((v98()))->FUN_0084e3a0())));
    }
    if (v96())
    {
        ::FUN_00485910(0x4d414e50, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((v96()))->FUN_0084e3a0())));
    }
    ::FUN_00485910(0x4d414e54, m_134);
    ::FUN_00485910(0x4d414e42, m_13c);
    ::FUN_00485910(0x4d414e57, m_138);
    FUN_00485910(0x344d414e, m_148);
    FUN_00485910(0x354d414e, m_154);
    if (reinterpret_cast<::TESActorBaseData *>((void *)&(m_30))->GetFlag(0x100))
    {
        SoundsObj_5f7c20* sounds = ((::SoundsObj_5f7c20 *)(reinterpret_cast<::FUN_005f91d0_shell *>(this)->FUN_005f91d0()));
        if (sounds)
        {
            reinterpret_cast<::FUN_005f03a0_shell *>((sounds))->FUN_005f03a0();
        }
    }
    else
    {
        FormObj_5f7c20* soundCreature = ((::FormObj_5f7c20 *)(reinterpret_cast<::FUN_005f9100_shell *>(this)->FUN_005f9100()));
        if (soundCreature)
        {
            unsigned int soundId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((soundCreature))->FUN_0084e3a0()));
            ::FUN_00485910(0x52435343, soundId);
        }
    }
    if (m_14c)
    {
        unsigned int impactId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_14c))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e43, impactId);
    }
    if (m_158)
    {
        unsigned int weaponId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_158))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e4c, weaponId);
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

struct CreatureRecordFile
{
    void ReadChunkInt(void*);
};
struct CreatureContainerEntry
{
    unsigned int form;
    int count;
};
struct CreatureFactionEntry
{
    unsigned int faction;
    unsigned char rank;
    unsigned char unk05;
    unsigned short unk06;
};
struct CreatureAIData
{
    unsigned char aggression, confidence, energy, responsibility;
    unsigned int services;
    unsigned char trainingSkill, trainingLevel;
    unsigned short unk0A;
    unsigned char unk0C, unk0D, mood, unk0F;
    unsigned int unk10;
};
struct CreatureBaseData
{
    unsigned int flags;
    unsigned short fatigue, level;
    unsigned short minLevel, maxLevel;
    unsigned short speed, karma;
    unsigned int disposition;
    unsigned short unknown, templateFlags;
};
struct FUN_0040e690
{
    unsigned int owner, global, condition;
    FUN_0040e690();
};
struct LastContainerItem
{
    unsigned int object;
    unsigned int count;
    FUN_0040e690* extra;
};
extern LastContainerItem* DAT_011cb5f8;
struct CreatureSoundsLoad
{
};
struct CreaturePrimary
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
    virtual void LoadBounds(CreatureRecordFile*);
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
    virtual const char* GetName();
    virtual void SetEditorID(const char*);
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
    virtual void SetCombatStyle(unsigned int);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
};
struct CreatureActorComponent
{
    virtual void slot0();
    CreatureBaseData data;
    unsigned int deathItem;
    unsigned int voice;
    unsigned int templateForm;
    unsigned int unk28, unk2C, unk30;
};
struct CreatureContainerComponent
{
    virtual void slot0();
    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureTouchComponent
{
    virtual void slot0();
    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureSpellComponent
{
    virtual void slot0();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
};
struct CreatureAIComponent
{
    virtual void slot0();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};
struct CreatureHealthComponent
{
    virtual void slot0();

    unsigned int unk04;
};
struct CreatureAttributesComponent
{
    virtual void slot0();

    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureAnimationComponent
{
    virtual void slot0();
    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureNameComponent
{
    virtual void slot0();

    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureModelComponent
{
    virtual void slot0();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};
struct CreatureScriptComponent
{
    virtual void slot0();
    unsigned int unk04;
    unsigned int unk08;
};
struct CreatureAVComponent
{
    virtual void slot0();
};
struct CreatureDestructionComponent
{
    virtual void slot0();

    unsigned int unk04;
};
struct CreatureAttackComponent
{
    virtual void slot0();

    unsigned int unk04;
};
struct CreatureModelsComponent
{
    virtual void slot0();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
};
extern const char DAT_0104947c[];
struct CreatureRecord : CreaturePrimary,
                        CreatureActorComponent,
                        CreatureContainerComponent,
                        CreatureTouchComponent,
                        CreatureSpellComponent,
                        CreatureAIComponent,
                        CreatureHealthComponent,
                        CreatureAttributesComponent,
                        CreatureAnimationComponent,
                        CreatureNameComponent,
                        CreatureModelComponent,
                        CreatureScriptComponent,
                        CreatureAVComponent,
                        CreatureDestructionComponent,
                        CreatureAttackComponent,
                        CreatureModelsComponent
{
    unsigned int sounds;
    unsigned char type, aggression, confidence, energy;
    unsigned char reach, unk131;
    unsigned short unk132;
    float turnSpeed, footWeight, scale;
    unsigned int combatStyle, bodyParts;
    unsigned int bloodMaterial, impactData, unk150, soundLevel, weaponList;
    bool FUN_005f7ec0(CreatureRecordFile*);
};
// Reads a creature record from the file, dispatching each chunk to the matching component loader, and returns true when the record type is 43.
// @fnv 0x005f7ec0
bool CreatureRecord::FUN_005f7ec0(CreatureRecordFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 43)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(false);
    int soundType = -1;
    int chunk;
    bool consumed5;
    bool valid4;
    while ((chunk = reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()) != 0)
    {
        consumed5 = false;
        valid4 = true;
        switch (chunk)
        {
        case 0x44494445: {  // EDID
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID(editorID);
            break;
        }
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName((::TESFullName *)(::CreatureNameComponent *)(this), (::TESFile *)(file));
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            ::TESModel::LoadModelData((::TESModel *)(::CreatureModelComponent *)(this), (::TESFile *)(file));
            break;
        case 0x49524353: {
            unsigned int scriptID = 0;
            file->ReadChunkInt(&scriptID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(scriptID));
            reinterpret_cast<::TESScriptableForm *>(this)->InitItem((::TESForm *)(void *)(this));
            break;
        }
        case 0x4f544e43:
        case 0x44454f43:
            switch (reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())
            {
            case 0x4f544e43: {
                CreatureContainerEntry item;
                ::FUN_00403d30(&item, 0, 8);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&item), 8);
                if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                    reinterpret_cast<::S_00462230 *>(&(item))->FUN_00462230();
                DAT_011cb5f8 = ((::LastContainerItem *)(reinterpret_cast<::fnv_004817f0::FUN_004817f0_shell *>(this)->AddContainerObject((::fnv_004817f0::ContainerChanges *)(::CreatureContainerEntry *)(&item))));
                break;
            }
            case 0x44454f43:
                if (DAT_011cb5f8)
                {
                    DAT_011cb5f8->extra = new FUN_0040e690;
                    reinterpret_cast<::ContainerItemExtra *>((DAT_011cb5f8->extra))->Load((::TESFile *)(file));
                    DAT_011cb5f8 = 0;
                }
                break;
            }
            break;
        case 0x4f4c5053: {
            unsigned int spellID = 0;
            file->ReadChunkInt(&spellID);
            reinterpret_cast<::fnv_0048d290::FUN_0048d290_shell *>(this)->FUN_0048d290((::TESForm *)(spellID));
            break;
        }
        case 0x4d544945: {
            unsigned int touchID = 0;
            file->ReadChunkInt(&touchID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(touchID));
            break;
        }
        case 0x544d4145: {
            unsigned short touchAmount = 0;
            reinterpret_cast<::FUN_00472840_impl *>((file))->ReadChunkData((unsigned short *)(void *)(&touchAmount));
            reinterpret_cast<::TESEnchantableForm *>(this)->SetFormEnchantmentAmount(touchAmount);
            break;
        }
        case 0x54444941: {
            CreatureAIData ai;
            ::FUN_00403d30(&ai, 0, 20);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&ai), 20);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00503240_shell *>(&(ai))->SwapEndianFields();
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((file))->FUN_00403570() < 4 && ai.aggression > 1)
                ++ai.aggression;
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((file))->FUN_00403570() < 6)
            {
                switch (ai.aggression)
                {
                case 0:
                    ai.mood = 0;
                    break;
                case 1:
                    ai.aggression = 0;
                    ai.mood = 1;
                    break;
                case 2:
                    ai.aggression = 1;
                    ai.mood = 1;
                    break;
                case 3:
                    ai.aggression = 1;
                    ai.mood = 2;
                    break;
                case 4:
                    ai.aggression = 2;
                    ai.mood = 2;
                    break;
                case 5:
                    ai.aggression = 3;
                    ai.mood = 0;
                    break;
                }
            }
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((file))->FUN_00403570() < 7)
                ai.confidence = 4 - ai.confidence;
            reinterpret_cast<::TESAIForm *>(this)->CopyAIDataFromAIDATA((::PackedRecordData *)(::CreatureAIData *)(&ai));
            break;
        }
        case 0x44494b50: {
            unsigned int packageID = 0;
            file->ReadChunkInt(&packageID);
            reinterpret_cast<::fnv_0047f500::FUN_0047f500_shell *>(this)->FUN_0047f500((::fnv_0047f500::TESPackage *)(packageID));
            break;
        }
        case 0x4d414e53: {
            CreatureFactionEntry faction;
            ::FUN_00403d30(&faction, 0, 8);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&faction), 8);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::fnv_00503210::Unk *>(&(faction))->FUN_00503210();
            reinterpret_cast<::FUN_0047d800_shell *>(this)->FUN_0047d800((::TESFaction *)(faction.faction), faction.rank);
            break;
        }
        case 0x4d414e49: {
            unsigned int deathID = 0;
            file->ReadChunkInt(&deathID);
            deathItem = deathID;
            break;
        }
        case 0x4b435456: {
            unsigned int voiceID;
            file->ReadChunkInt(&voiceID);
            voice = voiceID;
            break;
        }
        case 0x544c5054: {
            unsigned int templateID;
            file->ReadChunkInt(&templateID);
            templateForm = templateID;
            break;
        }
        case 0x53424341:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data), 24);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::Header47cb90 *>(&(data))->SwapEndianness();
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((file))->FUN_00403570() < 8)
                data.templateFlags = 0;
            data.level = 0;
            break;
        case 0x5a46464b:
            reinterpret_cast<::TESAnimation *>(this)->LoadComponent((::TESForm *)(::CreatureAnimationComponent *)(this), (::TESFile *)(file));
            break;
        case 0x5a46494e:
        case 0x5446494e:
            reinterpret_cast<::S00489ce0 *>(this)->LoadStringChunk(this, (::TESFile *)(file));
            break;
        case 0x54534544:
        case 0x44545344:
            ::FUN_004781e0((::BGSDestructibleObjectForm *)(::CreatureDestructionComponent *)(this), (::TESFile *)(file));
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0((::TESFile *)(file), &type, 4);
            break;
        case 0x304d414e: {
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C())
            {
                char* model = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(model), 0);
            }
            break;
        }
        case 0x314d414e: {
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C())
            {
                char* model2 = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(model2), 0);
            }
            break;
        }
        case 0x4d414e42:
            file->ReadChunkInt(&scale);
            break;
        case 0x4d414e57:
            file->ReadChunkInt(&footWeight);
            break;
        case 0x4d414e54:
            file->ReadChunkInt(&turnSpeed);
            break;
        case 0x344d414e: {
            unsigned int material;
            file->ReadChunkInt(&material);
            bloodMaterial = material;
            break;
        }
        case 0x354d414e: {
            unsigned int level;
            file->ReadChunkInt(&level);
            if (level > 3)
                soundLevel = 1;
            else
                soundLevel = level;
            break;
        }
        case 0x4d414e52: {
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 4)
            {
                unsigned int oldReach = 0;
                file->ReadChunkInt(&oldReach);
                reach = (unsigned char)oldReach;
            }
            else
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&reach), 1);
            break;
        }
        case 0x52435343: {
            unsigned int soundCreature = 0;
            file->ReadChunkInt(&soundCreature);
            reinterpret_cast<::TESCreature *>(this)->SetCreatureSoundsFrom((::TESCreature *)(soundCreature));
            break;
        }
        case 0x54445343: {
            int newSoundType;
            file->ReadChunkInt(&newSoundType);
            soundType = newSoundType;
            break;
        }
        case 0x49445343:
        case 0x46445343: {
            CreatureSoundsLoad* loadedSounds = ((::CreatureSoundsLoad *)(reinterpret_cast<::TESCreature *>(this)->GetMutableCreatureSounds()));
            if (!reinterpret_cast<::CreatureSoundCollection *>((loadedSounds))->LoadSoundsFromFile((::TESFile *)(file), (::CREATURE_SOUND_TYPE)(soundType), (::TESCreature *)(void *)(this)))
                consumed5 = true;
            break;
        }
        case 0x4d414e5a: {
            unsigned int combat;
            file->ReadChunkInt(&combat);
            SetCombatStyle(combat);
            break;
        }
        case 0x4d414e50: {
            unsigned int parts;
            file->ReadChunkInt(&parts);
            bodyParts = parts;
            break;
        }
        case 0x4d414e43: {
            unsigned int impact = 0;
            file->ReadChunkInt(&impact);
            reinterpret_cast<::FUN_005f8bb0_shell *>(this)->SetImpactDataSet((::BGSImpactDataSet *)(impact));
            break;
        }
        case 0x4d414e4c: {
            unsigned int weapons = 0;
            file->ReadChunkInt(&weapons);
            reinterpret_cast<::FUN_005f8bd0_Helper *>(this)->Set(weapons);
            break;
        }
        }
        if (!valid4)
            break;
        if (!consumed5 && !reinterpret_cast<::TESFile *>((file))->NextChunk())
            break;
    }
    if (!::GetShortAtOffset12((const char *)this))
        ::FUN_005b5e40();
    return true;
}

struct FUN_005f8d70_runtime : FUN_00843150_shell
{
};
struct FUN_005f8d70_virtual
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5(unsigned int);
};
struct FUN_005f8d70_record
{
};
struct FUN_005f8d70_actor : FUN_0047ded0_shell
{
};
struct FUN_005f8d70_settings
{
};
struct FUN_005f8d70_shell
{
    unsigned short FUN_005f8d70();
};
// @fnv 0x005f8d70
unsigned short FUN_005f8d70_shell::FUN_005f8d70()
{
    unsigned short result = 0;
    if ((*reinterpret_cast<::FUN_005f8d70_runtime * *>(&::DAT_011cb6a0))->FUN_00843150() && !reinterpret_cast<::FUN_004516b0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004516b0() &&
        reinterpret_cast<signed char*>(this)[0x50] == -1)
    {
        FUN_005f8d70_record* record = static_cast<FUN_005f8d70_record*>(((void *)(reinterpret_cast<::IdleAnimationManager *>(((*reinterpret_cast<::FUN_005f8d70_runtime * *>(&::DAT_011cb6a0))))->FindIdleArrayEntry(
            (const char *)(void *)(reinterpret_cast<FUN_005f8d70_virtual*>(reinterpret_cast<char*>(this) - 0x30)->v5(1)), {}))));
        if (record == 0 || *((int *)((void *)(record))) == 0)
            reinterpret_cast<signed char*>(this)[0x50] = 0;
        else
            reinterpret_cast<signed char*>(this)[0x50] = 1;
    }
    if (reinterpret_cast<signed char*>(this)[0x50] == 0)
        return 0;
    if (reinterpret_cast<::FUN_00461560_shell *>((reinterpret_cast<FUN_005f8d70_actor*>(reinterpret_cast<char*>(this) - 0xdc)))->FUN_00461560())
    {
        short level = reinterpret_cast<FUN_005f8d70_actor*>(reinterpret_cast<char*>(this) - 0xdc)->FUN_0047ded0();
        if (level < 1)
            level = 1;
        result = reinterpret_cast<::TESAttackDamageForm *>(this)->GetAttackDamage();
        result += static_cast<int>(static_cast<double>(level) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FUN_005f8d70_settings *>(&::g_011cb58c)))))));
    }
    else
    {
        result = reinterpret_cast<::TESAttackDamageForm *>(this)->GetAttackDamage();
    }
    return result;
}

class TESBoundObject;
class ActorPackageContext;
class BaseProcess
{
  public:
    virtual void v00();
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
    virtual void ClearEquipment(void*, void*, void*);
    virtual void ClearWeapon(void*);
    virtual void ClearAmmo(void*);
    virtual void ClearOther(void*);
public:
    ::ActorPackageContext *GetCurrentProcessData();
};
class TESObjectREFR
{
  public:
    virtual void v00();
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
    virtual bool IsActor();
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
    virtual void EquipItem(TESBoundObject*, int, void*, bool);
public:
    bool IsLimbMissing(int);
};
class TESActorBase;
class Actor : public TESObjectREFR
{
  public:
public:
    ::TESActorBase *GetActorBase();
};
struct ExtraDataList;
struct ExtraDataNode
{
};
struct InventoryEntryData
{
    ~InventoryEntryData();
};
class TESObjectREFR;
class InventoryChanges
{
  public:
public:
    static ::InventoryChanges *CreateForReference(::TESObjectREFR *);
};
struct BGSSaveLoadGame
{
};
struct CreatureEquipment : TESCreature
{
    void FUN_005f9e00(TESObjectREFR*, int, bool, bool);
};

// @fnv 0x005f9e00
void CreatureEquipment::FUN_005f9e00(TESObjectREFR* reference, int unused, bool equip, bool allowChanges)
{
    bool savedVal = true;
    if (!allowChanges)
        savedVal = reinterpret_cast<::FUN_004623f0_shell *>((g_BGSSaveLoadGame))->FUN_004623f0(false);
    if (reference->IsActor())
        reinterpret_cast<::BipedAnim *>((reference))->AttachFaceGenNode();
    InventoryChanges* entry = ::InventoryChanges::CreateForReference(reference);
    reinterpret_cast<::FUN_004bfe50_t *>((entry))->RemoveWornItems(true, reference);
    Actor* actor = dynamic_cast<Actor*>(reference);
    if (actor && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(actor))->GetBaseTexture())))
    {
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(actor))->GetBaseTexture()))->ClearAmmo(0);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(actor))->GetBaseTexture()))->ClearOther(0);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(actor))->GetBaseTexture()))->ClearWeapon(0);
        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(actor))->GetBaseTexture()))->ClearEquipment(0, 0, 0);
    }
    InventoryEntryData* weapon = 0;
    InventoryEntryData* aWeapon = 0;
    float value = 0.0f;
    if (equip && entry)
        weapon = ((::InventoryEntryData *)(reinterpret_cast<::Target *>((entry))->SelectBestWeapon((::ActorStand *)(::TESCreature *)(this), &value, 6, true)));
    if (weapon && reinterpret_cast<::B5FA120Checker *>(this)->FUN_005fa120((::B5FA120Form *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((weapon))->GetName())))) && !reinterpret_cast<::Thing575 *>((reference))->FUN_00575400((int)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((weapon))->GetName())))))
    {
        reference->EquipItem(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((weapon))->GetName())), 1, 0, false);
        if (aWeapon && !reinterpret_cast<::Thing575 *>((reference))->FUN_00575400((int)(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((aWeapon))->GetName())))))
        {
            ExtraDataList* extra = 0;
            if (((::ExtraDataNode *)(::FUN_00559450((int *)(aWeapon)))))
                extra = ((::ExtraDataList *)((void *)(((::ExtraDataNode *)(::FUN_00559450((int *)(aWeapon)))))));
            reference->EquipItem(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((aWeapon))->GetName())), ((int)(reinterpret_cast<::Callees *>((aWeapon))->FUN_00726070())), extra, false);
        }
    }
    delete weapon;
    delete aWeapon;
    if (!allowChanges)
        reinterpret_cast<::FUN_004623f0_shell *>((g_BGSSaveLoadGame))->FUN_004623f0(savedVal);
    if (actor && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(actor))->GetBaseTexture())))
        reinterpret_cast<::ActorSpellView *>((actor))->UpdateSpells(true);
}

namespace fnv_008b4d10 {
struct CreatureView
{
};
struct Part
{
};
struct Body
{
};
struct BaseView
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
    virtual Body* GetBody();
};
struct Node
{
};
struct Process
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
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void v401();
    virtual void v402();
    virtual void v403();
    virtual void v404();
    virtual void v405();
    virtual void v406();
    virtual void v407();
    virtual void v408();
    virtual void v409();
    virtual void v410();
    virtual void v411();
    virtual void v412();
    virtual void v413();
    virtual void v414();
    virtual void v415();
    virtual void v416();
    virtual void v417();
    virtual void v418();
    virtual void v419();
    virtual void v420();
    virtual void v421();
    virtual void v422();
    virtual void v423();
    virtual void v424();
    virtual void v425();
    virtual void v426();
    virtual void v427();
    virtual void v428();
    virtual void v429();
    virtual void v430();
    virtual void v431();
    virtual void v432();
    virtual void v433();
    virtual void v434();
    virtual void v435();
    virtual Node* GetNode(int);
};
struct Effect
{
    int unk00;
    int unk04;
    int unk08;
    int type;
    int part;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void* weapon;
    bool FUN_0058cba0(unsigned int);
};
struct Weapon
{
    unsigned int FUN_00401170();
};
struct GlobalObject_0045cf30
{
    bool* Bool();
};
struct LimbOwner
{
};
struct ActorPrefix
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
    virtual bool IsStateActive(int);
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
    virtual bool IsSpecial();
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
    Process* process;
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
};
struct Queue
{
};
struct Actor : ActorPrefix, LimbOwner
{
    void ApplyEffectToBodyParts(Effect*, int, int, void*, void*, int, int, bool);
};
// Checks the actor's creature/special state, then applies the effect to matching body parts, calling FUN_00572fc0 and FUN_008b52a0 or queueing via FUN_0087b440.
// @fnv 0x008b4d10
void Actor::ApplyEffectToBodyParts(Effect* effect, int type, int part, void* source, void* target, int intA, int intB,
                                   bool flag)
{
    TESCreature* eb = dynamic_cast<TESCreature*>(reinterpret_cast<::Actor *>(this)->GetActorBase());
    if (((eb && ((bool)(reinterpret_cast<::TESCreature *>((void *)(reinterpret_cast<CreatureView*>(eb)))->FUN_005fbf20()))) || IsSpecial()) && *(*reinterpret_cast<::fnv_008b4d10::GlobalObject_0045cf30 *>(&::g_011df7f8)).Bool())
        return;
    switch (type)
    {
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
        break;
    default:
        reinterpret_cast<::FUN_00572fc0_shell *>(this)->FUN_00572fc0(-1, (int)(source), (int)(target), effect ? effect->part : part, false);
        return;
    }
    if (reinterpret_cast<::TESObjectREFR *>(this)->IsLimbMissing(part))
        return;
    if (reinterpret_cast<::FUN_0087f3d0_shell *>(this)->FUN_0087f3d0() || IsStateActive(0))
        return;
    Part* q;
    Weapon* b;
    int ba;
    Node* k;
    Body* l;
    Part* c;
    int h = 0;
    bool f = false;
    bool cf = false;
    Body* i = reinterpret_cast<BaseView*>(reinterpret_cast<::Actor *>(this)->GetActorBase())->GetBody();
    if (i)
    {
        q = ((::fnv_008b4d10::Part *)(reinterpret_cast<::FUN_005e50f0_Obj *>((i))->GetValueByIndex(part)));
        if (q)
        {
            cf = reinterpret_cast<::FUN_008b4cd0_class *>((q))->IsFlag40Set();
            if (reinterpret_cast<::FUN_008b4360_Class *>((q))->FUN_008b4360())
                h = reinterpret_cast<::FUN_008b4cf0_class *>((q))->GetByte65();
            if (q && cf && h >= 100)
                f = true;
        }
    }
    bool s = (effect && effect->part != part) ? true : false;
    bool p = false;
    bool a = f;
    if (effect)
    {
        if (effect->FUN_0058cba0(64))
            a = true;
        else if (effect->FUN_0058cba0(32))
            p = true;
    }
    if (!p && !a)
    {
        b = s ? 0
              : (source && reinterpret_cast<Weapon*>(source)->FUN_00401170() == 40
                     ? reinterpret_cast<Weapon*>(source)
                     : (effect && effect->weapon ? reinterpret_cast<Weapon*>(effect->weapon)
                                                 : (effect && effect->type == 45 ? (*reinterpret_cast<::fnv_008b4d10::Weapon * *>(&::DAT_011ca278)) : 0)));
        ::RollChanceOutcome(this, (::ChanceModifier *)(b), h, intA, intB, cf, (unsigned char *)(bool *)(&p), (unsigned char *)(bool *)(&a));
    }
    if (!p && !a)
        return;
    for (ba = 0; ba < 15; ba++)
    {
        if (*(*reinterpret_cast<::fnv_008b4d10::GlobalObject_0045cf30 *>(&::g_011df858)).Bool() && ba != -1)
            ba = part;
        l = reinterpret_cast<BaseView*>(reinterpret_cast<::Actor *>(this)->GetActorBase())->GetBody();
        c = l ? ((::fnv_008b4d10::Part *)(reinterpret_cast<::FUN_005e50f0_Obj *>((l))->GetValueByIndex(ba))) : 0;
        if (!c || ((signed char)(reinterpret_cast<::FUN_005e5190_Class *>((c))->GetByte63())) != type)
            continue;
        k = process->GetNode(ba);
        if (!k || reinterpret_cast<::FUN_00456630_helper *>((k))->FUN_00456610())
            continue;
        if (a && !reinterpret_cast<::FUN_008b4360_Class *>((c))->FUN_008b4360())
            a = false;
        if (!reinterpret_cast<::FUN_008b5190_Class *>((c))->FUN_008b5190() && !reinterpret_cast<::FUN_008b4360_Class *>((c))->FUN_008b4360())
            continue;
        reinterpret_cast<::FUN_00572fc0_shell *>(this)->FUN_00572fc0(ba, (int)(source), (int)(target), ba, a);
        if (!::FUN_008c7aa0())
            reinterpret_cast<::fnv_008b52a0::ActorView *>(this)->FUN_008b52a0((void *)(type), ba, a, !flag, true, false);
        else
            reinterpret_cast<::FUN_0087b440_holder *>((((::fnv_008b4d10::Queue *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087b440((int)(this), type, ba, a, !flag);
        if (*(*reinterpret_cast<::fnv_008b4d10::GlobalObject_0045cf30 *>(&::g_011df858)).Bool() && ba != -1)
            break;
    }
}
}  // namespace fnv_008b4d10

extern "C" char DAT_01183a00;
extern "C" void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct S47f190
{
};
struct S48d630
{
};
struct S47bdd0
{
};
struct S47d220
{
};
struct S487240
{
};
struct S480000
{
};
struct S4870f0
{
};
struct S489430
{
};
struct S489db0
{
};
struct S48cce0
{
};
struct S481c80
{
};
struct S47fb50
{
};
struct S4786e0
{
};
struct Sound
{
};
struct Spells
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
    virtual int v22();
    virtual void v23(int);
};
struct C005f9820
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
    virtual int v96();
    virtual void v97(int);
    virtual int v98();
    virtual void v99(int);
    char pad[0x30];
    int unk34;
    char pad38[0xf0];
    Sound* sounds;
    void CopyFrom(void*);
};
// @fnv 0x005f9820
void C005f9820::CopyFrom(void* apSource)
{
    Sound* ptr;
    C005f9820* src2 = (C005f9820*)FUN_00ec43fb(apSource, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &DAT_01183a00, 0);
    if (!src2)
        return;
    if (((::Sound *)(reinterpret_cast<::FUN_005f91d0_shell *>(this)->FUN_005f91d0())))
    {
        Sound* snd = sounds;
        Sound* del2 = snd;
        del2 ? reinterpret_cast<::CreatureSoundCollection *>((del2))->DeleteThis(1) : 0;
    }
    sounds = 0;
    reinterpret_cast<::TESAIForm *>((((S47f190*)((char*)this + 0x90))))->BaseFormRecord((::BaseFormComponent *)(apSource));
    reinterpret_cast<::fnv_0048d630::SpellListAccess *>((((S48d630*)((char*)this + 0x7c))))->FUN_0048d630((::BaseFormComponent *)(apSource));
    reinterpret_cast<::FUN_0047bdd0_shell *>((((S47bdd0*)((char*)this + 0x70))))->FUN_0047bdd0((::BaseFormComponent *)(apSource));
    reinterpret_cast<::fnv_0047d220::ABD_47d220 *>((((S47d220*)((char*)this + 0x30))))->CopyFromActorBaseData((::BaseFormComponent *)(apSource));
    reinterpret_cast<::FUN_00487240_shell *>((((S487240*)((char*)this + 0xb0))))->CopyHealthForm((::BaseFormComponent *)(apSource));
    reinterpret_cast<::FUN_00480000_shell *>((((S480000*)((char*)this + 0xb8))))->CopyAttributesFromComponent((::BaseFormComponent *)(apSource));
    reinterpret_cast<::FUN_004870f0_shell *>((((S4870f0*)((char*)this + 0xd0))))->CopyFullNameFrom((::BaseFormComponent *)(apSource));
    reinterpret_cast<::ModelCopyView *>((((S489430*)((char*)this + 0xdc))))->FUN_00489430((::BaseFormComponent *)(apSource));
    reinterpret_cast<::fnv_00489db0::FUN_00489db0_shell *>((((S489db0*)((char*)this + 0x114))))->CopyModelListFromComponent((::BaseFormComponent *)(apSource));
    reinterpret_cast<::fnv_0048cce0::FUN_0048cce0_shell *>((((S48cce0*)((char*)this + 0xf4))))->CopyFromScriptableForm((::BaseFormComponent *)(apSource));
    reinterpret_cast<::TESContainer *>((((S481c80*)((char*)this + 0x64))))->CopyFromBase((::BaseFormComponent *)(apSource));
    reinterpret_cast<::FUN_0047fb50_shell *>((((S47fb50*)((char*)this + 0xc4))))->FUN_0047fb50((::BaseFormComponent *)(apSource));
    reinterpret_cast<::BGSDestructibleObjectForm *>((((S4786e0*)((char*)this + 0x104))))->FUN_004786e0((::BaseFormComponent *)(apSource));
    memcpy((char*)this + 0x12c, reinterpret_cast<::FUN_005f9b70_shell *>((src2))->GetOffset12C(), 4);
    this->unk34 = *((int *)(reinterpret_cast<::BaseProcess *>((((Spells*)((char*)src2 + 0x30))))->GetCurrentProcessData()));
    reinterpret_cast<::FUN_005f9af0_shell *>(this)->SetCreatureType(reinterpret_cast<::FUN_005f9ad0_shell *>((src2))->FUN_005f9ad0());
    reinterpret_cast<::FUN_00507780 *>(this)->SetBoltsRadiusStrength(reinterpret_cast<::FUN_00821640_shell *>((src2))->FUN_00821640());
    reinterpret_cast<::FUN_00803a90_shell *>(this)->SetBoltGrowWidth(::FUN_00567470((char *)(src2)));
    reinterpret_cast<::FUN_005f9b10_class *>(this)->SetBoltSmallWidth(reinterpret_cast<::FUN_00821660_shell *>((src2))->FUN_00821660());
    ((Spells*)((char*)this + 0x30))->v23(((Spells*)((char*)src2 + 0x30))->v22());
    if (((::Sound *)(reinterpret_cast<::FUN_005f91d0_shell *>((src2))->FUN_005f91d0())))
    {
        ptr = ((::Sound *)(reinterpret_cast<::TESCreature *>(this)->GetMutableCreatureSounds()));
        reinterpret_cast<::FUN_005f0640_shell *>((ptr))->CopyCreatureSoundLists((::CreatureSoundCollection *)(::Sound *)(((::Sound *)(reinterpret_cast<::FUN_005f91d0_shell *>((src2))->FUN_005f91d0()))));
    }
    else
    {
        reinterpret_cast<::TESCreature *>(this)->SetCreatureSoundsFrom((::TESCreature *)(::C005f9820 *)(((::C005f9820 *)(reinterpret_cast<::FUN_005f9100_shell *>((src2))->FUN_005f9100()))));
    }
    *(unsigned int*)((char*)this + 0x154) = reinterpret_cast<::Twin_009c0070 *>((src2))->GetFilePosition();
    reinterpret_cast<::FUN_005f8bb0_shell *>(this)->SetImpactDataSet((::BGSImpactDataSet *)(void *)(((void *)(reinterpret_cast<::FUN_005f9b30_shell *>((src2))->GetImpactDataSet()))));
    reinterpret_cast<::FUN_005f8bd0_Helper *>(this)->Set((int)(((void *)(::GetField158((int)(src2))))));
    v99(src2->v98());
    v97(src2->v96());
}

class MobileObject : public TESObjectREFR
{
  public:
};
class MiddleHighProcess : public BaseProcess
{
  public:
    virtual void w092();
    virtual void w093();
    virtual void w094();
    virtual void w095();
    virtual void w096();
    virtual void w097();
    virtual void w098();
    virtual void w099();
    virtual void w100();
    virtual void w101();
    virtual void w102();
    virtual void w103();
    virtual void w104();
    virtual void w105();
    virtual void w106();
    virtual void w107();
    virtual void w108();
    virtual void w109();
    virtual void w110();
    virtual void w111();
    virtual void w112();
    virtual void w113();
    virtual void w114();
    virtual void w115();
    virtual void w116();
    virtual void w117();
    virtual void w118();
    virtual void w119();
    virtual void w120();
    virtual void w121();
    virtual void w122();
    virtual void w123();
    virtual void w124();
    virtual void w125();
    virtual void w126();
    virtual void w127();
    virtual void w128();
    virtual void w129();
    virtual void w130();
    virtual void w131();
    virtual void w132();
    virtual void w133();
    virtual void w134();
    virtual void w135();
    virtual void w136();
    virtual void w137();
    virtual void w138();
    virtual void w139();
    virtual void w140();
    virtual void w141();
    virtual void w142();
    virtual void w143();
    virtual void w144();
    virtual void w145();
    virtual void w146();
    virtual void w147();
    virtual void w148();
    virtual void w149();
    virtual void w150();
    virtual void w151();
    virtual void w152();
    virtual void w153();
    virtual void w154();
    virtual void w155();
    virtual void w156();
    virtual void w157();
    virtual void w158();
    virtual void w159();
    virtual void w160();
    virtual void w161();
    virtual void w162();
    virtual void w163();
    virtual void w164();
    virtual void w165();
    virtual void w166();
    virtual void w167();
    virtual void w168();
    virtual void w169();
    virtual void w170();
    virtual void w171();
    virtual void w172();
    virtual void w173();
    virtual void w174();
    virtual void w175();
    virtual void w176();
    virtual void w177();
    virtual void w178();
    virtual void w179();
    virtual void w180();
    virtual void w181();
    virtual void w182();
    virtual void w183();
    virtual void w184();
    virtual void w185();
    virtual void w186();
    virtual void w187();
    virtual void w188();
    virtual void w189();
    virtual void w190();
    virtual void w191();
    virtual void w192();
    virtual void w193();
    virtual void w194();
    virtual void w195();
    virtual void w196();
    virtual void w197();
    virtual void w198();
    virtual void w199();
    virtual void w200();
    virtual void w201();
    virtual void w202();
    virtual void w203();
    virtual void w204();
    virtual void w205();
    virtual void w206();
    virtual void w207();
    virtual void w208();
    virtual void w209();
    virtual void w210();
    virtual void w211();
    virtual void w212();
    virtual void w213();
    virtual void w214();
    virtual void w215();
    virtual void w216();
    virtual void w217();
    virtual void w218();
    virtual void w219();
    virtual void w220();
    virtual void w221();
    virtual void w222();
    virtual void w223();
    virtual void w224();
    virtual void w225();
    virtual void w226();
    virtual void w227();
    virtual void w228();
    virtual void w229();
    virtual void w230();
    virtual void w231();
    virtual void w232();
    virtual void w233();
    virtual void w234();
    virtual void w235();
    virtual void w236();
    virtual void w237();
    virtual void w238();
    virtual void w239();
    virtual void w240();
    virtual void w241();
    virtual void w242();
    virtual void w243();
    virtual void w244();
    virtual void w245();
    virtual void w246();
    virtual void w247();
    virtual void w248();
    virtual void w249();
    virtual void w250();
    virtual void w251();
    virtual void w252();
    virtual void w253();
    virtual void w254();
    virtual void w255();
    virtual void w256();
    virtual void w257();
    virtual void w258();
    virtual void w259();
    virtual void w260();
    virtual void w261();
    virtual void w262();
    virtual void w263();
    virtual void w264();
    virtual void w265();
    virtual void w266();
    virtual void w267();
    virtual void w268();
    virtual void w269();
    virtual void w270();
    virtual void w271();
    virtual void w272();
    virtual void w273();
    virtual void w274();
    virtual void w275();
    virtual void w276();
    virtual void w277();
    virtual void w278();
    virtual void w279();
    virtual void w280();
    virtual void w281();
    virtual void w282();
    virtual void w283();
    virtual void w284();
    virtual void w285();
    virtual void w286();
    virtual void w287();
    virtual void w288();
    virtual void w289();
    virtual void w290();
    virtual void w291();
    virtual void w292();
    virtual void w293();
    virtual void w294();
    virtual void w295();
    virtual void w296();
    virtual void w297();
    virtual void w298();
    virtual void w299();
    virtual void w300();
    virtual void w301();
    virtual void w302();
    virtual void w303();
    virtual void w304();
    virtual void w305();
    virtual void w306();
    virtual void w307();
    virtual void w308();
    virtual void w309();
    virtual void w310();
    virtual void w311();
    virtual void w312();
    virtual void w313();
    virtual void w314();
    virtual void w315();
    virtual void w316();
    virtual void w317();
    virtual void w318();
    virtual void w319();
    virtual void w320();
    virtual void w321();
    virtual void w322();
    virtual void w323();
    virtual void w324();
    virtual void w325();
    virtual void w326();
    virtual void w327();
    virtual void w328();
    virtual void w329();
    virtual void w330();
    virtual void w331();
    virtual void w332();
    virtual void w333();
    virtual void w334();
    virtual void w335();
    virtual void w336();
    virtual void Apply(MobileObject*);
};
struct CreatureHost_5fa0a0
{
    void FUN_005fa0a0(TESObjectREFR* ref);
};
// Casts ref to MobileObject, gets its BaseProcess, casts to MiddleHighProcess, and calls Apply on it.
// @fnv 0x005fa0a0
void CreatureHost_5fa0a0::FUN_005fa0a0(TESObjectREFR* ref)
{
    MobileObject* mobile = dynamic_cast<MobileObject*>(ref);
    if (mobile && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(mobile))->GetBaseTexture())))
    {
        MiddleHighProcess* process = dynamic_cast<MiddleHighProcess*>(((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(mobile))->GetBaseTexture())));
        if (process)
        {
            process->Apply(mobile);
        }
    }
}

// sub ecx,0x7c; jmp target  ==  MSVC adjustor thunk (multiple inheritance, shared virtual).
// PrimaryBase = vptr + 30 named int fields = 0x7c bytes; Derived redeclares the claimed virtual and defines only its ctor.
struct PrimaryBase
{
    virtual void FUN_005fbf80();
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

struct SecondaryBase
{
    virtual void FUN_005fbf80();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbf80
    virtual void FUN_005fbf80();
};

Derived::Derived()
{}

namespace fnv_005fbfb0 {
// MSVC adjustor thunk: the primary base occupies 0x7c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_005fbfb0();
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

struct SecondaryBase
{
    virtual void FUN_005fbfb0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbfb0
    virtual void FUN_005fbfb0();
};

Derived::Derived()
{}
}

// namespace fnv_005fbfb0

namespace fnv_005fbfd0 {
// MSVC adjustor thunk: the primary base occupies 0x90 bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_005fbfd0();
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
};

struct SecondaryBase
{
    virtual void FUN_005fbfd0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbfd0
    virtual void FUN_005fbfd0();
};

Derived::Derived()
{}
}

// namespace fnv_005fbfd0

namespace fnv_005fbff0 {
// Adjustor (this-adjusting) thunk for FUN_005fbff0:
//     sub ecx, 0xdc ; jmp FUN_005f75b0
// MSVC emits such a thunk in the vftable of a class that inherits the same
// virtual from two bases: the thunk converts the secondary base sub-object
// pointer back to the primary base pointer by subtracting the size of the
// primary base (0xdc = 4 byte vptr + 54 int members) and tail jumps to the
// implementation.  Both bases declare the virtual, the derived class
// redeclares it and defines only its constructor, which makes the compiler
// emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_005fbff0();
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
};

struct SecondaryBase
{
    virtual void FUN_005fbff0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbff0
    virtual void FUN_005fbff0();
};

Derived::Derived()
{}
}

// namespace fnv_005fbff0

// Adjustor thunk: the secondary-base (+0x90) vtable entry for an override defined on the derived class.

class FC010Primary
{
  public:
    virtual void FUN_005fc010(unsigned int uiA, unsigned int uiB);
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
};

class FC010Secondary
{
  public:
    virtual void FUN_005fc010(unsigned int uiA, unsigned int uiB);
};

class FC010Derived : public FC010Primary, public FC010Secondary
{
  public:
    FC010Derived();
// @fnv 0x005fc010
    virtual void FUN_005fc010(unsigned int uiA, unsigned int uiB);
};

FC010Derived::FC010Derived()
{}

namespace fnv_005fc030 {
struct PrimaryBase
{
    virtual void FUN_005fc030();
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

struct SecondaryBase
{
    virtual void FUN_005fc030();
};

struct TESCreatureAdjust : PrimaryBase, SecondaryBase
{
    TESCreatureAdjust();
// @fnv 0x005fc030
    virtual void FUN_005fc030();
};

TESCreatureAdjust::TESCreatureAdjust()
{}
}

// namespace fnv_005fc030

namespace fnv_005fc040 {
// Adjustor thunk for FUN_005fc040: sub ecx,0x90; jmp FUN_005fb1e0
// Primary base = vptr + 35 int fields (0x90 bytes).
struct PrimaryBase
{
    virtual void FUN_005fc040();
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
};

struct SecondaryBase
{
    virtual void FUN_005fc040();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fc040
    virtual void FUN_005fc040();
};

Derived::Derived()
{}
}

class TESForm;

class TESCreature;

class BGSBodyPartData;

class TESCombatStyle;

class BGSImpactDataSet;

class BGSListForm;

struct FormObj_CreatureInit;

struct Host_CreatureInit;

struct FormObj_CreatureInit
{
    unsigned int FUN_0084e3a0();
};

struct Sub30_CreatureInit
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30;
};

struct Sub64_CreatureInit
{
    int u00, u04, u08;
};

struct Sub70_CreatureInit
{
    int u00, u04, u08;
};

struct Sub7c_CreatureInit
{
    int u00, u04, u08, u0c, u10;
};

struct AIList_CreatureInit
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int Size();
    int u04;
};

struct Sub90_CreatureInit
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    AIList_CreatureInit packages;
    int u28, u2c, u30;
    int u34, u38, u3c;
};

struct Subd0_CreatureInit
{
    int u00, u04, u08;
};

struct Subdc_CreatureInit
{
    int u00, u04, u08, u0c, u10, u14;
    struct ScriptInit
    {
        int u00, u04, u08;
    } script;
    int u24;
};

struct Sub104_CreatureInit
{
    int u00, u04;
    int u08, u0c;
};

struct Sub114_CreatureInit
{
    int u00, u04, u08, u0c, u10;
};

struct Sub12c_CreatureInit
{
    int u00;
};

struct Host_CreatureInit
{
    virtual void v00();
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
    virtual const char* v76();
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
    virtual struct FormObj_CreatureInit* v96();
    virtual void v97();
    virtual TESCombatStyle* v98();
    virtual void v99(TESCombatStyle*);

    int u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c;
    Sub30_CreatureInit m_30;
    Sub64_CreatureInit m_64;
    Sub70_CreatureInit m_70;
    Sub7c_CreatureInit m_7c;
    Sub90_CreatureInit m_90;
    Subd0_CreatureInit m_d0;
    Subdc_CreatureInit m_dc;
    Sub104_CreatureInit m_104;
    Sub114_CreatureInit m_114;
    struct Host_CreatureInit* m_128;
    Sub12c_CreatureInit m_12c;
    unsigned char m_130;
    unsigned char m_131;
    unsigned char m_132;
    unsigned char m_133;
    float m_134;
    float m_138;
    float m_13c;
    TESCombatStyle* m_140;
    BGSBodyPartData* m_144;
    int m_148;
    BGSImpactDataSet* m_14c;
    int m_150;
    int m_154;
    BGSListForm* m_158;

    unsigned int FUN_0084e3a0();
    void FUN_005f9340();
};

class TESCreature;

class BGSBodyPartData;

extern "C" const char DAT_010495e0[], DAT_01049598[], DAT_01049548[], DAT_010494f8[], DAT_0102c740[], DAT_010494bc[];

class TESCombatStyle
{
};

class BGSImpactDataSet
{
};

class BGSListForm
{
};

// @fnv 0x005f9340
void Host_CreatureInit::FUN_005f9340()
{
    unsigned int formId;
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    reinterpret_cast<::TESScriptableForm *>(&(m_dc.script))->InitItem((::TESForm *)(void *)(this));
    reinterpret_cast<::TESContainer *>(&(m_64))->InitItem((::TESForm *)(void *)(this));
    reinterpret_cast<::TESSpellList *>(&(m_7c))->InitItem((::TESForm *)(void *)(this));
    reinterpret_cast<::BGSTouchSpellForm *>(&(m_70))->InitItem((::TESForm *)(void *)(this));
    reinterpret_cast<::FUN_0047f4c0_shell *>(&(m_90))->FUN_0047f4c0((::TESForm *)(void *)(this));
    reinterpret_cast<::ActorBaseInitItemView *>(&(m_30))->FUN_0047d8b0((::TESForm *)(void *)(this));
    reinterpret_cast<::BGSDestructibleObjectForm *>(&(m_104))->InitItem((::TESForm *)(void *)(this));
    if (m_30.u04 & 1)
    {
        m_30.u04 &= ~0x40;
        m_30.u04 &= ~0x10;
        m_30.u04 &= ~0x20;
        m_30.u04 &= ~0x40000;
        m_30.u04 &= ~0x800000;
    }
    if (!reinterpret_cast<::TESActorBaseData *>((void *)&(m_30))->GetFlag(0x100))
    {
        unsigned int soundId = (unsigned int)m_128;
        if (soundId)
        {
            ::ResolveFormID(&soundId, (::TESFile *)(void *)(((void *)(reinterpret_cast<::TESForm *>(this)->GetFile(-1)))));
            m_128 = (struct Host_CreatureInit*)dynamic_cast<TESCreature*>(::FUN_004839c0(soundId));
            if (!m_128)
            {
                ::FUN_005b5e40();
            }
            else if (m_128 == this || reinterpret_cast<::ActorMover *>(&(m_128->m_30))->GetCurrentMoveModeType())
            {
                ::FUN_005b5e40();
                m_128 = 0;
            }
        }
    }
    if (m_140)
    {
        unsigned int combatId = (unsigned int)v98();
        if (combatId)
        {
            ::ResolveFormID(&combatId, (::TESFile *)(void *)(((void *)(reinterpret_cast<::TESForm *>(this)->GetFile(-1)))));
            m_140 = dynamic_cast<TESCombatStyle*>(::FUN_004839c0(combatId));
            if (!m_140)
            {
                ::FUN_005b5e40();
            }
        }
    }
    if (!v98())
        v99(((::TESCombatStyle *)(::FUN_00505000())));
    if (m_144)
    {
        unsigned int bodyId = (unsigned int)m_144;
        if (bodyId)
        {
            ::ResolveFormID(&bodyId, (::TESFile *)(void *)(((void *)(reinterpret_cast<::TESForm *>(this)->GetFile(-1)))));
            m_144 = dynamic_cast<BGSBodyPartData*>(::FUN_004839c0(bodyId));
            if (!m_144)
            {
                ::FUN_005b5e40();
            }
        }
    }
    formId = (unsigned int)m_14c;
    if (formId)
    {
        ::ResolveFormID(&formId, (::TESFile *)(void *)(((void *)(reinterpret_cast<::TESForm *>(this)->GetFile(-1)))));
        m_14c = dynamic_cast<BGSImpactDataSet*>(::FUN_004839c0(formId));
        if (!m_14c)
            ::FUN_005b5e40();
    }
    formId = (unsigned int)m_158;
    if (formId)
    {
        ::ResolveFormID(&formId, (::TESFile *)(void *)(((void *)(reinterpret_cast<::TESForm *>(this)->GetFile(-1)))));
        m_158 = dynamic_cast<BGSListForm*>(::FUN_004839c0(formId));
        if (!m_158)
            ::FUN_005b5e40();
    }
    if (m_90.packages.Size() <= 0)
        reinterpret_cast<::FUN_00565210_shell *>(this)->FUN_00565210(true);
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(1);
}

namespace fnv_005fb270 {
__if_not_exists(::TESCombatStyle::SetFormType)
{
    class TESCombatStyle : public ::TESForm
    {
    };
}


struct TESCreatureCall_1b30
{
};

struct TESCreatureCall_0d00
{
};

__if_exists(::TESCreature::m_ucField00)
{
    struct TESCreatureLoad : ::TESCreature
    {
        void FUN_005fb270(int a1, int a2);
    };
}

// @fnv 0x005fb270
void TESCreatureLoad::FUN_005fb270(int a1, int a2)
{
    reinterpret_cast<::fnv_005f1b30::ActorBaseLoad *>((((TESCreatureCall_1b30*)this)))->FUN_005f1b30(a1, a2);
    if (a1 & 0x200)
    {
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((TESCreatureCall_0d00*)this)))->FUN_00484d00(&m_ucField00, 1);
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((TESCreatureCall_0d00*)this)))->FUN_00484d00(&m_ucField01, 1);
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((TESCreatureCall_0d00*)this)))->FUN_00484d00(&m_ucField02, 1);
    }
    if (a1 & 0)
    {
        unsigned int formId;
        reinterpret_cast<::FUN_00484d40_Host *>((((TESCreatureCall_0d00*)this)))->FUN_00484d40(&formId, 4);
        ::TESCombatStyle* style = dynamic_cast< ::TESCombatStyle*>(::FUN_004839c0(formId));
        if (style)
        {
            m_pCombatStyle = style;
        }
    }
}
}



// @fnv 0x005f9b90
bool TESCreature::FUN_005f9b90(TESForm* otherForm)
{
    TESCreature* other = dynamic_cast<TESCreature*>(otherForm);
    if (!other)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(other)))
        return true;
    if (memcmp(&dataPadding, reinterpret_cast<::FUN_005f9b70_shell *>((other))->GetOffset12C(), 4))
        return true;
    if (((bool)(reinterpret_cast<::FUN_005f9ad0_shell *>(this)->FUN_005f9ad0())) != ((bool)(reinterpret_cast<::FUN_005f9ad0_shell *>((other))->FUN_005f9ad0())))
        return true;
    if (reinterpret_cast<::FUN_00821640_shell *>(this)->FUN_00821640() != reinterpret_cast<::FUN_00821640_shell *>((other))->FUN_00821640())
        return true;
    if (::FUN_00567470((char *)this) != ::FUN_00567470((char *)(other)))
        return true;
    if (reinterpret_cast<::FUN_00821660_shell *>(this)->FUN_00821660() != reinterpret_cast<::FUN_00821660_shell *>((other))->FUN_00821660())
        return true;
    if (GetBloodImpactMaterial() != other->GetBloodImpactMaterial())
        return true;
    if (GetCombatStyle() != other->GetCombatStyle())
        return true;
    if (GetBodyPartData() != other->GetBodyPartData())
        return true;
    if (((int)(reinterpret_cast<::Twin_009c0070 *>(this)->GetFilePosition())) != ((int)(reinterpret_cast<::Twin_009c0070 *>((other))->GetFilePosition())))
        return true;
    if (reinterpret_cast<::TESActorBaseData *>(this)->GetFlag(0x100))
    {
        CreatureSoundCollection* sounds = reinterpret_cast<::FUN_005f91d0_shell *>(this)->FUN_005f91d0();
        CreatureSoundCollection* otherSounds5 = reinterpret_cast<::FUN_005f91d0_shell *>((other))->FUN_005f91d0();
        if (sounds)
        {
            if (!otherSounds5)
                return true;
            if (reinterpret_cast<::FUN_005f06f0_shell *>((sounds))->IsDifferentFrom(otherSounds5))
                return true;
        }
        else if (otherSounds5)
            return true;
    }
    else
    {
        if (reinterpret_cast<::FUN_005f9100_shell *>(this)->FUN_005f9100() != reinterpret_cast<::FUN_005f9100_shell *>((other))->FUN_005f9100())
            return true;
    }
    if (((int)(reinterpret_cast<::FUN_005f9b30_shell *>(this)->GetImpactDataSet())) != ((int)(reinterpret_cast<::FUN_005f9b30_shell *>((other))->GetImpactDataSet())))
        return true;
    if (::GetField158((int)this) != ::GetField158((int)(other)))
        return true;
    return false;
}

#include "generated/data/fallout_shared/tescreature.inc"
