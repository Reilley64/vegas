// fallout_shared/tesaiform_decls.h: declares PackageList, PackedRecordData, TESAIForm, Actor, BGSCameraPath and more

#include "fnv/decl/FUN_004f6de0_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00824000.h"
#include "BaseFormComponent.h"
class TESPackage;
class Actor;
class TESActorBase;
template <class T> class BSSimpleList;
class TESForm;
class TESPackage;
class PackageList
{
  public:
    unsigned char data[8];
    void ClearPackageList();
    TESPackage* GetPackageForActor(Actor*);
    void CollectEligiblePackages(Actor*, BSSimpleList<TESPackage*>*, float, float);
public:
    void AddPackage(::TESPackage *);
public:
    void InitItem(::TESForm *);
};
struct PackedRecordData
{
    unsigned char m_ucField00;
    unsigned char m_ucField01;
    unsigned char m_ucField02;
    unsigned char m_ucField03;
    unsigned char m_ucField04;
    unsigned char pad[3];
    unsigned int m_uiField08;
    unsigned char m_ucField0C;
    unsigned char m_ucField0D;
    unsigned char m_ucField0E;
    bool m_bField0F;
    unsigned int m_uiField10;
};
class TESAIForm : public BaseFormComponent
{
  public:
    unsigned char aggression, confidence, energy, responsibility, mood, pad[3];
    unsigned int services;
    unsigned char skill, level, assistance;
    bool radius;
    unsigned int distance;
    PackageList packages;
    void FreeDataComponent();
    void BaseFormRecord(BaseFormComponent*);
    void CopyAISettings(TESAIForm*);
    void CopyAIPackageList(const TESAIForm*);
    void CopyAIDataFromAIDATA(PackedRecordData*);
    static TESPackage* GetCurrentPackage(Actor*);
    static void FindAvailablePackages(Actor*, BSSimpleList<TESPackage*>*, float, float);
    void InitializeComponent();
    unsigned char GetAssistance();
    unsigned char GetResponsibility();
    void SetAggression(unsigned char, bool);
    void SetAssistance(unsigned char);
    void SetConfidence(unsigned char, bool);
    void SetEnergy(unsigned char, bool);
    void SetResponsibility(unsigned char, bool);
    void SetAIMood(unsigned char);
    void SetHasAggroRadius(bool);
    void SetAggroRadius(unsigned int);
    void SetServiceFlags(unsigned int, bool);
    int GetTrainingSkill();
    void SetTrainingSkill(int);
    void SetTrainingSkillLevel(unsigned char);
};
class Actor
{
  public:
    TESActorBase* GetActorBase();
};
class PerkEntryConditionSet;
class BGSCameraPath
{
  public:
    PerkEntryConditionSet* GetConditions();
};
union SETTING_VALUE
{
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
};
struct GameSettingCollection;
template <class T> class SettingT
{
  public:
    char opaque[16];
};
class GlobalObject_0040e0b0
{
  public:
    char opaque[16];
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting26, originalRuntimeFloatSetting27,
    originalRuntimeFloatSetting28;
extern GlobalObject_0040e0b0 g_011c52e4, g_011c52fc;
extern float DAT_011c52a8, DAT_011c52ac, DAT_011c52b0, DAT_011c52b4, DAT_011c52b8;
extern bool DAT_011c52c0;
class PatrolActorPackageData
{
  public:
    bool IsPatrolling();
};
struct BSAudio
{
  public:
};
class ActiveEffect
{
  public:
public:
    bool IsDone() const;
};
class TimeGlobal
{
  public:
};
class TESForm
{
  public:
};
namespace ActorValue {
enum Index;
}