// fallout_shared/tesaiform.cpp: TESAIForm, ActorValue, MyInner, AIFormFlags and more (42 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f6de0_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_0067e4a0_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00824000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011de000.h"
#include "tesaiform_decls.h"

// @fnv 0x0047ede0
void TESAIForm::FreeDataComponent()
{
    packages.ClearPackageList();
}

// @fnv 0x0047f190
void TESAIForm::BaseFormRecord(BaseFormComponent* component)
{
    TESAIForm* source = dynamic_cast<TESAIForm*>(component);
    if (!source)
        return;
    CopyAISettings(source);
    CopyAIPackageList(source);
}

// Returns the actor's current package by looking up the package list on the actor base's AI form, or null if actor or base is missing.
// @fnv 0x0047f520
TESPackage* TESAIForm::GetCurrentPackage(Actor* actor)
{
    TESPackage* result = 0;
    TESAIForm* ai;
    if (actor)
    {
        TESActorBase* base = actor->GetActorBase();
        ai = base ? reinterpret_cast<TESAIForm*>(reinterpret_cast<char*>(base) + 0x90) : 0;
        if (ai)
            result = reinterpret_cast<PackageList*>(reinterpret_cast<BGSCameraPath*>(ai)->GetConditions())
                         ->GetPackageForActor(actor);
    }
    return result;
}

// @fnv 0x0047f590
void TESAIForm::FindAvailablePackages(Actor* actor, BSSimpleList<TESPackage*>* missed, float start, float hour)
{
    TESAIForm* ai;
    if (actor)
    {
        TESActorBase* base = actor->GetActorBase();
        ai = base ? reinterpret_cast<TESAIForm*>(reinterpret_cast<char*>(base) + 0x90) : 0;
        if (ai)
            reinterpret_cast<PackageList*>(reinterpret_cast<BGSCameraPath*>(ai)->GetConditions())
                ->CollectEligiblePackages(actor, missed, start, hour);
    }
}

// Resets all AI form fields to defaults and, on first call, caches five game-setting floats into globals.
// @fnv 0x0047ed10
void TESAIForm::InitializeComponent()
{
    aggression = 0;
    confidence = 4;
    energy = 0;
    responsibility = 0;
    mood = 0;
    services = 0;
    skill = 0;
    level = 0;
    assistance = 0;
    radius = false;
    distance = 0;
    if (!DAT_011c52c0)
    {
        DAT_011c52a8 = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(reinterpret_cast<SettingT_GameSettingCollection_*>(&originalRuntimeFloatSetting28)))))->f;
        DAT_011c52ac = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(reinterpret_cast<SettingT_GameSettingCollection_*>(&originalRuntimeFloatSetting27)))))->f;
        DAT_011c52b0 = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011c52fc)))))->f;
        DAT_011c52b4 = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(reinterpret_cast<SettingT_GameSettingCollection_*>(&originalRuntimeFloatSetting26)))))->f;
        DAT_011c52b8 = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011c52e4)))))->f;
        DAT_011c52c0 = true;
    }
}

// @fnv 0x0047ee30
unsigned char TESAIForm::GetAssistance()
{
    return assistance;
}

// @fnv 0x0047ef30
unsigned char TESAIForm::GetResponsibility()
{
    return responsibility;
}

// @fnv 0x0047f000
int TESAIForm::GetTrainingSkill()
{
    int result;
    result = skill + 0x20;
    return result;
}

// @fnv 0x0047f0b0
void TESAIForm::CopyAIDataFromAIDATA(PackedRecordData* source)
{
    if (source)
    {
        SetAggression(source->m_ucField00, true);
        SetAssistance(source->m_ucField0E);
        SetConfidence(source->m_ucField01, true);
        SetEnergy(source->m_ucField02, true);
        SetResponsibility(source->m_ucField03, true);
        SetServiceFlags(source->m_uiField08, true);
        SetAIMood(source->m_ucField04);
        SetHasAggroRadius(source->m_bField0F);
        SetAggroRadius(source->m_uiField10);
        skill = source->m_ucField0C;
        level = source->m_ucField0D;
        if (confidence >= 5)
        {
            confidence = 0;
        }
    }
}

struct FUN_0047ee00_class : ::TESAIForm
{
    void FUN_0047ee00(unsigned char value, bool flag);
};

struct FUN_0047eed0_shell : public TESAIForm
{
    void FUN_0047eed0(unsigned char, bool);
};

struct FUN_0047ef00_shell : public TESAIForm
{
    void FUN_0047ef00(unsigned char, bool);
};

struct FUN_0047ef50_shell : public TESAIForm
{
    void FUN_0047ef50(unsigned char, bool);
};

struct FUN_0047ef80_shell : public TESAIForm
{
    void FUN_0047ef80(unsigned char);
};

struct FUN_0047efb0_shell : public TESAIForm
{
    void SetServices(unsigned int, bool);
};

struct FUN_0047f020_shell : public TESAIForm
{
    void SetSkill(int);
};

// Returns true when index is between 0x20 and 0x2d inclusive.
// @fnv 0x0047f060
bool __cdecl FUN_0047f060(int index)
{
    return index >= 0x20 && index < 0x2e;
}

struct FUN_0047f4c0_shell : public TESAIForm
{
    void FUN_0047f4c0(TESForm*);
};

class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

struct PackageList_Helper
{
};

// If the ProcessLists byte is zero, calls InitItem on the conditions object obtained from this, passing apOwner.
// @fnv 0x0047f4c0
void FUN_0047f4c0_shell::FUN_0047f4c0(TESForm* apOwner)
{
    if (!*(*reinterpret_cast<::ProcessLists *>(&::g_011c5348)).GetLifeStateControlFlag())
    {
        reinterpret_cast<::PackageList *>((((PackageList_Helper*)((BGSCameraPath*)this)->GetConditions())))->InitItem(apOwner);
    }
}

namespace fnv_0047f500 {
struct BGSIdleCollection;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct MobileObject;
struct LocationDescriptor;
struct DurationData;
struct PackageTargetRecord;
struct Script;
struct TESCombatStyle;
struct PerkEntryConditionSet;
struct TESEscortPackageData;
struct TESIdleForm;
struct TESObjectCELL;
struct TESObjectREFR;
struct TESPackage;
struct TESPackageData;
struct TESPatrolPackageData;
struct TESTopic;
struct TESUseWeaponPackageData;
struct TESWorldSpace;
struct blob12
{
    char b[12];
};
struct FUN_0047f500_shell : public TESAIForm
{
    void FUN_0047f500(TESPackage*);
};

struct PackageList_Helper
{
};

// Adds the given package to the package list obtained from the form's conditions.
// @fnv 0x0047f500
void FUN_0047f500_shell::FUN_0047f500(TESPackage* apPack)
{
    reinterpret_cast<::PackageList *>((((PackageList_Helper*)((BGSCameraPath*)this)->GetConditions())))->AddPackage((::TESPackage *)(apPack));
}
}  // namespace fnv_0047f500

struct FUN_0062f2f0_shell : public TESAIForm
{
    unsigned char FUN_0062f2f0();
};
// Copies aggression, assistance, confidence, energy, responsibility, service flags, aggro radius and training data from source into this form.
// @fnv 0x0047f1e0
void TESAIForm::CopyAISettings(TESAIForm* source)
{
    SetAggression(reinterpret_cast<PatrolActorPackageData*>(source)->IsPatrolling(), true);
    SetAssistance(source->GetAssistance());
    SetConfidence(((unsigned char)(reinterpret_cast<::FUN_004f6de0_shell *>((source))->FUN_004f6de0())), true);
    SetEnergy(reinterpret_cast<::FUN_005bb4d0_shell *>((reinterpret_cast<BSAudio*>(source)))->FUN_005bb4d0(), true);
    SetResponsibility(source->GetResponsibility(), true);
    SetAIMood(reinterpret_cast<::FUN_0062f2f0_shell *>((source))->FUN_0062f2f0());
    SetHasAggroRadius(reinterpret_cast<ActiveEffect*>(source)->IsDone());
    SetAggroRadius(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>(source)))->FUN_00825c00());
    SetServiceFlags(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(source)))->FUN_0084e3a0())), true);
    SetTrainingSkill(source->GetTrainingSkill());
    SetTrainingSkillLevel(((bool)(::GetByteAtOffset17((const char *)(reinterpret_cast<ActiveEffect*>(source))))));
}

// @fnv 0x0062f2f0
unsigned char FUN_0062f2f0_shell::FUN_0062f2f0()
{
    return this->mood;
}

extern unsigned int _data_011c16bc;
struct BFC_s
{
    virtual void v();
    BFC_s();
};
struct CondS
{
    char p[8];
    CondS();
    ~CondS();
};
struct FUN_0047ec40 : public BFC_s
{
    char pad[0x14];
    CondS m_kCondition;
    FUN_0047ec40();
    virtual void v();
};
// @fnv 0x0047ec40
FUN_0047ec40::FUN_0047ec40()
{
    reinterpret_cast<::TESAIForm *>(this)->InitializeComponent();
}

namespace fnv_0047ecb0 {
extern unsigned int _data_011c16bc;
struct BFC_s
{
    virtual void v();
};
struct CondS
{
    char p[8];
    CondS();
    ~CondS();
};
struct FUN_0047ecb0 : public BFC_s
{
    char pad[0x14];
    CondS m_kCondition;
    virtual ~FUN_0047ecb0();
};
// Destructor that calls FreeDataComponent to release the object's data component.
// @fnv 0x0047ecb0
FUN_0047ecb0::~FUN_0047ecb0()
{
    reinterpret_cast<::TESAIForm *>(this)->FreeDataComponent();
}
}  // namespace fnv_0047ecb0

extern float DAT_011c52a8;

// @fnv 0x0047eeb0
float __cdecl FUN_0047eeb0(unsigned char a)
{
    if (a >= 5)
        return 0.0f;
    return *(float*)(&DAT_011c52a8 + a);
}

struct FUN_0047f7e0_shell
{
    unsigned short FUN_0047f7e0(unsigned int aiFlags);
};

// @fnv 0x0047f7e0
unsigned short FUN_0047f7e0_shell::FUN_0047f7e0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    if (aiFlags & 8)
    {
        isize += 1;
        isize += 1;
        isize += 1;
        isize += 1;
        isize += 1;
    }
    return isize;
}

struct FUN_0047efe0_shell
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    int m_flags;
    bool HasFlags(int arg);
};

// @fnv 0x0047efe0
bool FUN_0047efe0_shell::HasFlags(int aiFlags)
{
    if (m_flags & aiFlags)
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct TESSaveLoadGame
{
};

TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_0047f8c0_shell : ::TESAIForm
{
    void FUN_0047f8c0(unsigned int arg1, unsigned int arg2);
};

// @fnv 0x0047f8c0
void FUN_0047f8c0_shell::FUN_0047f8c0(unsigned int uiFlags, unsigned int arg2)
{
    if (uiFlags & 8)
    {
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((void*)((char*)&this->aggression), 1);
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((void*)((char*)&this->confidence), 1);
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((void*)((char*)&this->energy), 1);
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((void*)((char*)&this->responsibility), 1);
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((void*)((char*)&this->mood), 1);
    }
}

struct FakeOuter
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void v18(int);
};
struct MyInner
{
    void DispatchToOuter(int);
};
// @fnv 0x0047ee00
void TESAIForm::SetAggression(unsigned char value, bool flag)
{
    aggression = value;
    if (flag)
    {
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
    }
}
// Stores value into assistance and calls DispatchToOuter with 8.
// @fnv 0x0047ee50
void TESAIForm::SetAssistance(unsigned char aucAssistance)
{
    assistance = aucAssistance;
    reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
}
// Stores value into radius and calls DispatchToOuter with 8.
// @fnv 0x0047ee70
void TESAIForm::SetHasAggroRadius(bool value)
{
    radius = value;
    reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
}
// Stores value into distance and calls DispatchToOuter with 8.
// @fnv 0x0047ee90
void TESAIForm::SetAggroRadius(unsigned int auiRadius)
{
    distance = auiRadius;
    reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
}
// @fnv 0x0047eed0
void TESAIForm::SetConfidence(unsigned char value, bool flag)
{
    confidence = value;
    if (flag)
    {
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
    }
}
// @fnv 0x0047ef00
void TESAIForm::SetEnergy(unsigned char value, bool flag)
{
    energy = value;
    if (flag)
    {
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
    }
}
// @fnv 0x0047ef50
void TESAIForm::SetResponsibility(unsigned char value, bool flag)
{
    responsibility = value;
    if (flag)
    {
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
    }
}
// @fnv 0x0047ef80
void TESAIForm::SetAIMood(unsigned char value)
{
    if (value < 8)
    {
        mood = value;
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
    }
}
// @fnv 0x0047efb0
void TESAIForm::SetServiceFlags(unsigned int value, bool flag)
{
    services = value;
    if (flag)
    {
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
    }
}
// @fnv 0x0047f020
void TESAIForm::SetTrainingSkill(int value)
{
    if (::FUN_0047f060((*(int *)&(const ::ActorValue::Index &)(static_cast<ActorValue::Index>(value)))))
    {
        skill = static_cast<unsigned char>(value - 0x20);
    }
    reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
}
// Stores the given value into level and calls DispatchToOuter with 8.
// @fnv 0x0047f090
void TESAIForm::SetTrainingSkillLevel(unsigned char aucLevel)
{
    level = aucLevel;
    reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
}
// Stores value at offset 4 of this object and, when flag is set, calls DispatchToOuter with 8.
// @fnv 0x0047ee00
void FUN_0047ee00_class::FUN_0047ee00(unsigned char value, bool flag)
{
    this->aggression = value;
    if (flag)
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
}
// Sets confidence to acConfidence and, when abAddChange is true, calls DispatchToOuter with 8.
// @fnv 0x0047eed0
void FUN_0047eed0_shell::FUN_0047eed0(unsigned char acConfidence, bool abAddChange)
{
    confidence = acConfidence;
    if (abAddChange)
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
}
// Sets the energy field to acEnergy and, when abAddChange is set, calls DispatchToOuter with 8.
// @fnv 0x0047ef00
void FUN_0047ef00_shell::FUN_0047ef00(unsigned char acEnergy, bool abAddChange)
{
    energy = acEnergy;
    if (abAddChange)
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
}
// Sets the responsibility field to acResponsibility and, when abAddChange is true, calls DispatchToOuter with 8.
// @fnv 0x0047ef50
void FUN_0047ef50_shell::FUN_0047ef50(unsigned char acResponsibility, bool abAddChange)
{
    responsibility = acResponsibility;
    if (abAddChange)
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
}
// If acMood is below 8, stores it in mood and calls DispatchToOuter with 8.
// @fnv 0x0047ef80
void FUN_0047ef80_shell::FUN_0047ef80(unsigned char acMood)
{
    if (acMood < 8)
    {
        mood = acMood;
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
    }
}
// Stores aiServeFlags into services and, when abAddChange is set, calls DispatchToOuter(8).
// @fnv 0x0047efb0
void FUN_0047efb0_shell::SetServices(unsigned int aiServeFlags, bool abAddChange)
{
    services = aiServeFlags;
    if (abAddChange)
        reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
}
// If aeSkill is a skill actor value, stores it minus 0x20 in skill, then calls DispatchToOuter(8).
// @fnv 0x0047f020
void FUN_0047f020_shell::SetSkill(int aeSkill)
{
    if (::FUN_0047f060((*(int *)&(const ::ActorValue::Index &)((ActorValue::Index)aeSkill))))
    {
        skill = aeSkill - 0x20;
    }
    reinterpret_cast<::MyInner *>(this)->DispatchToOuter(8);
}
// Computes the enclosing FakeOuter from this (offset 0x90) and, if non-null, calls its v18 with arg.
// @fnv 0x0047f790
void MyInner::DispatchToOuter(int arg)
{
    FakeOuter* b = this ? (FakeOuter*)((char*)this - 0x90) : (FakeOuter*)0;
    FakeOuter* a = b;
    if (a != 0)
        a->v18(arg);
}

namespace fnv_0047f840 {
struct TESSaveLoadGame
{
};

struct FUN_0047f840_shell : ::TESAIForm
{
    void FUN_0047f840(unsigned int aFlags);
};

// When the flags include 8, passes five consecutive bytes starting at this+4 to TESSaveLoadGame's save routine.
// @fnv 0x0047f840
void FUN_0047f840_shell::FUN_0047f840(unsigned int aFlags)
{
    if (aFlags & 8)
    {
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0047f840::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0((char*)&this->aggression, 1);
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0047f840::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0((char*)&this->confidence, 1);
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0047f840::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0((char*)&this->energy, 1);
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0047f840::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0((char*)&this->responsibility, 1);
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0047f840::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0((char*)&this->mood, 1);
    }
}
}  // namespace fnv_0047f840

struct FUN_0067e4a0_shell
{
};

struct FUN_0047f300_shell
{
    bool FUN_0047f300(BaseFormComponent* apCompareFC);
};

// Compares this object with apCompareFC via a TESAIForm cast and many field getters, returning true if any differ or the cast fails.
// @fnv 0x0047f300
bool FUN_0047f300_shell::FUN_0047f300(BaseFormComponent* apCompareFC)
{
    TESAIForm* pCompare = dynamic_cast<TESAIForm*>(apCompareFC);
    if (!pCompare)
        return true;

    if (reinterpret_cast<PatrolActorPackageData*>(this)->IsPatrolling() !=
        reinterpret_cast<PatrolActorPackageData*>(pCompare)->IsPatrolling())
        return true;

    if (reinterpret_cast<TESAIForm*>(this)->GetAssistance() != pCompare->GetAssistance())
        return true;

    if (((unsigned char)(reinterpret_cast<::FUN_004f6de0_shell *>((reinterpret_cast<TESAIForm*>(this)))->FUN_004f6de0())) != ((unsigned char)(reinterpret_cast<::FUN_004f6de0_shell *>((pCompare))->FUN_004f6de0())))
        return true;

    if (reinterpret_cast<::FUN_005bb4d0_shell *>((reinterpret_cast<BSAudio*>(this)))->FUN_005bb4d0() != reinterpret_cast<::FUN_005bb4d0_shell *>((reinterpret_cast<BSAudio*>(pCompare)))->FUN_005bb4d0())
        return true;

    if (reinterpret_cast<TESAIForm*>(this)->GetResponsibility() != pCompare->GetResponsibility())
        return true;

    if (reinterpret_cast<::FUN_0062f2f0_shell *>((reinterpret_cast<TESAIForm*>(this)))->FUN_0062f2f0() != reinterpret_cast<::FUN_0062f2f0_shell *>((pCompare))->FUN_0062f2f0())
        return true;

    if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>(this)))->FUN_00825c00() != reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>(pCompare)))->FUN_00825c00())
        return true;

    if (reinterpret_cast<ActiveEffect*>(this)->IsDone() !=
        reinterpret_cast<ActiveEffect*>(pCompare)->IsDone())
        return true;

    if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(this)))->FUN_0084e3a0())) != ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(pCompare)))->FUN_0084e3a0())))
        return true;

    if (reinterpret_cast<TESAIForm*>(this)->GetTrainingSkill() != pCompare->GetTrainingSkill())
        return true;

    if (((bool)(::GetByteAtOffset17((const char *)(reinterpret_cast<ActiveEffect*>(this))))) !=
        ((bool)(::GetByteAtOffset17((const char *)(reinterpret_cast<ActiveEffect*>(pCompare))))))
        return true;

    if (reinterpret_cast<::FUN_0067e4a0_cls *>((reinterpret_cast<FUN_0067e4a0_shell*>(reinterpret_cast<BGSCameraPath*>(this)->GetConditions())))->FUN_0067e4a0((::FUN_0067e4a0_cls *)(::PerkEntryConditionSet *)(reinterpret_cast<BGSCameraPath*>(pCompare)->GetConditions())))
        return true;

    return false;
}

struct AIFormFlags
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    int m_flags;
    bool FUN_0047f600(TESForm* apForm);
};

struct FormTypeStub
{
    int GetFormType();
};

struct BGSEquipType
{
    enum EQUIP_TYPE
    {
    };
    static EQUIP_TYPE __cdecl GetEquipType(TESForm* apForm);
};

// Maps the form's type (and equip type for type 0x2f) to a flag bit and returns the result of HasFlags for that bit.
// @fnv 0x0047f600
bool AIFormFlags::FUN_0047f600(TESForm* apForm)
{
    bool bResult2 = false;
    int iType8 = ((FormTypeStub*)apForm)->GetFormType();
    switch (iType8)
    {
    case 0x28:
        bResult2 = reinterpret_cast<::FUN_0047efe0_shell *>(this)->HasFlags(1);
        break;
    case 0x29:
        bResult2 = reinterpret_cast<::FUN_0047efe0_shell *>(this)->HasFlags(1);
        break;
    case 0x18:
        bResult2 = reinterpret_cast<::FUN_0047efe0_shell *>(this)->HasFlags(2);
        break;
    case 0x2f: {
        TESForm* pForm = apForm;
        switch (BGSEquipType::GetEquipType(pForm))
        {
        case 10:
            bResult2 = reinterpret_cast<::FUN_0047efe0_shell *>(this)->HasFlags(0x20);
            break;
        case 11:
            bResult2 = reinterpret_cast<::FUN_0047efe0_shell *>(this)->HasFlags(0x40);
            break;
        case 12:
            bResult2 = reinterpret_cast<::FUN_0047efe0_shell *>(this)->HasFlags(0x10);
            break;
        case 13:
            bResult2 = reinterpret_cast<::FUN_0047efe0_shell *>(this)->HasFlags(4);
            break;
        }
        break;
    }
    case 0x19:
        bResult2 = reinterpret_cast<::FUN_0047efe0_shell *>(this)->HasFlags(8);
        break;
    case 0x1f:
    case 0x32:
    case 0x67:
        bResult2 = reinterpret_cast<::FUN_0047efe0_shell *>(this)->HasFlags(0x400);
        break;
    }
    return bResult2;
}

struct PrimaryBase
{
    virtual void FUN_005fbf90();
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
    virtual void FUN_005fbf90();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbf90
    virtual void FUN_005fbf90();
};

Derived::Derived()
{}

namespace fnv_005fbfc0 {
struct PrimaryBase
{
    virtual void FUN_005fbfc0();
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
    virtual void FUN_005fbfc0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fbfc0
    virtual void FUN_005fbfc0();
};

Derived::Derived()
{}
}

// namespace fnv_005fbfc0

namespace fnv_005fc000 {
struct PrimaryBase
{
    virtual void FUN_005fc000();
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
    virtual void FUN_005fc000();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fc000
    virtual void FUN_005fc000();
};

Derived::Derived()
{}
}

#include "generated/data/fallout_shared/tesaiform.inc"
