
// src/fallout_shared/tesscriptfunctions_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesscriptfunctions.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/F005fd430.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00572db0_shell.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/fnv_00567490__ScaleReference.h"
#include "fnv/decl/fnv_00572d30__FUN_00572d30_shell.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0059c000.h"
#include "fnv/symbols_0059d000.h"
#include "fnv/symbols_0059e000.h"
#include "fnv/symbols_0059f000.h"
#include "fnv/symbols_005a0000.h"
#include "fnv/symbols_005a1000.h"
#include "fnv/symbols_005a2000.h"
#include "fnv/symbols_005a3000.h"
#include "fnv/symbols_005a4000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005ca000.h"
#include "fnv/symbols_0082f000.h"
#include "fnv/symbols_00aa1000.h"
#include "tesscriptfunctions_layout_support.h"
class ScriptParameter;
class ScriptHeaderData;
class TESForm
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void SetAltered(bool);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(TESFile* modInfo);
    virtual bool IsActor_InEditor(void);
    ENUM_FORM_ID GetFormType() const;
    void SetDestroyed(bool);
};
enum OBJECT_ACTION
{
    OBJECT_ACTION_ONE = 1,
    OBJECT_ACTION_TWO = 2
};
class TESObjectREFR : public TESForm
{
  public:
};
class BGSMusicType;
class FalloutAudioMedia
{
  public:
    static void PlayMedia(BGSMusicType*);
    static void EndMediaUpdate();
};
class ScriptLocals;
class TESQuest
{
  public:
    bool IsStageComplete(unsigned char);
    void SetEnabled(bool);
};
class Script;
class Script
{
  public:
    static bool OnHitWithFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool StopQuestFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool ScriptEffectUpdateFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*,
                                           Script*, ScriptLocals*, double&, unsigned int&);
    static bool SetAllyFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool SetDestroyedFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool GetCurrentTimeFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);
    static bool GetSecondsPassedFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                         ScriptLocals*, double&, unsigned int&);
    static bool GetDead(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                        double&, unsigned int&);
    static bool GetItemCount(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                             ScriptLocals*, double&, unsigned int&);
    static bool GetSitting(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                           double&, unsigned int&);
    static bool GetTalkedToPC(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                              ScriptLocals*, double&, unsigned int&);
    static bool GetIsRaining(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                             ScriptLocals*, double&, unsigned int&);
    static bool GetInCell(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                          double&, unsigned int&);
    static bool GetInFaction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                             ScriptLocals*, double&, unsigned int&);
    static bool GetRandomPercent(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                 ScriptLocals*, double&, unsigned int&);
    static bool GetLevel(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                         double&, unsigned int&);
    static bool OnAddFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                              ScriptLocals*, double&, unsigned int&);
    static bool OnSellFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool OnEquipFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool OnUnequipFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool OnFireFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool OnOpenFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool OnCloseFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool OnGrabFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool OnReleaseFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool OnDestructionStageChangeFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*,
                                                 Script*, ScriptLocals*, double&, unsigned int&);
    static bool OnHitFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                              ScriptLocals*, double&, unsigned int&);
    static bool OnDeathFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool OnStartCombatFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                      ScriptLocals*, double&, unsigned int&);
    static bool OnCombatEndFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                    ScriptLocals*, double&, unsigned int&);
    static bool OnSayToDoneFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                    ScriptLocals*, double&, unsigned int&);
    static bool OnPackageStartFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);
    static bool OnPackageEndFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool OnPackageChangeFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                        ScriptLocals*, double&, unsigned int&);
    static bool OnLoadFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool OnResetFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool OnMagicEffectHitFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                         ScriptLocals*, double&, unsigned int&);
    static bool OnTriggerFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool OnTriggerEnterFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);
    static bool OnTriggerLeaveFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);

    // Insert these declaration-only additions in the existing Script public section.
    static bool IsIdlePlayingFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                      ScriptLocals*, double&, unsigned int&);
    static bool IsTalkingFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool GetDayOfWeekFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool IsPCSleepingFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool GetDestroyedFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool HasBeenEatenFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool GetUnconsciousFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);
    static bool IsInCombatFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                   ScriptLocals*, double&, unsigned int&);
    static bool IsInInteriorFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);

    static void SetReferenceScale(TESObjectREFR*, float);

    static bool GetQuestCompleted(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                  ScriptLocals*, double&, unsigned int&);
    static bool GetQuestRunning(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool GetStage(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                         double&, unsigned int&);
    static bool GetDeadCount(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                             ScriptLocals*, double&, unsigned int&);
    static bool GetQuestCompletedStatus(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                        ScriptLocals*, double&, unsigned int&);
    static bool InvokeScriptFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool GetQuestCompletionState(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                        ScriptLocals*, double&, unsigned int&);
    static bool GetStageDone(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                             ScriptLocals*, double&, unsigned int&);
    static bool ConvertScriptValue(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                   ScriptLocals*, double&, unsigned int&);
    static bool GetInWorldspace(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                ScriptLocals*, double&, unsigned int&);
    static bool GetInSameCell(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                              ScriptLocals*, double&, unsigned int&);
    static bool GetDetected(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                            ScriptLocals*, double&, unsigned int&);
    static bool GetGlobalValue(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                               ScriptLocals*, double&, unsigned int&);
    static bool IsCurrentFurnitureRef(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                      ScriptLocals*, double&, unsigned int&);
    static bool GetIsID(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                        double&, unsigned int&);
    static bool EvaluateScriptExpression(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                         ScriptLocals*, double&, unsigned int&);
    static bool GetPCMiscStat(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                              ScriptLocals*, double&, unsigned int&);
    static bool HandleScriptVariable(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                     ScriptLocals*, double&, unsigned int&);
    static bool ReadScriptReference(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                    ScriptLocals*, double&, unsigned int&);
    static bool EvaluateParsedScriptFunction(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*,
                                             Script*, ScriptLocals*, double&, unsigned int&);
    static bool EvaluateScriptFunctionCall(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*,
                                           Script*, ScriptLocals*, double&, unsigned int&);
    static bool EvaluateScriptCall(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                   ScriptLocals*, double&, unsigned int&);
    static bool EvaluateScriptCallback(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*, Script*,
                                       ScriptLocals*, double&, unsigned int&);
};
#include "tesscriptfunctions_TESActorBaseData.h"
#include "tesscriptfunctions_SCRIPT_HEADER.h"
struct _FightReaction
{
    enum Type
    {
        NEUTRAL = 0,
        ENEMY = 1,
        ALLY = 2,
        FRIEND = 3,
        COUNT
    };
};
typedef _FightReaction::Type FIGHT_REACTION;
class TESFaction
{
  public:
};
class BGSListForm : public TESForm
{
  public:
};

struct Map;
struct NiProperty
{
    NiProperty();
    virtual void V0();
    char pad[0x14];
};
struct StrArr
{
    virtual void V0();
    Map** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    StrArr(unsigned int uiMaxSize, unsigned int uiGrowBy)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = (Map**)::FUN_00aa1070(sizeof(Map*) * m_usMaxSize);
        else
            m_pBase = 0;
    }
};
struct StrArrP : StrArr
{
    StrArrP(unsigned int a, unsigned int b) : StrArr(a, b)
    {}
    virtual void V0();
};
struct FUN_00a6aa40 : NiProperty
{
    unsigned short m_uiObjectFlags;
    StrArrP m_kStringArray;
    int m_iArrayLength;
    FUN_00a6aa40();
    virtual void V0();
};
// @fnv 0x00a6aa40
FUN_00a6aa40::FUN_00a6aa40() : m_uiObjectFlags(0), m_kStringArray(9, 1), m_iArrayLength(0)
{
    Map* pkMap;
    pkMap = 0;
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kStringArray))->SetAt(0, (char *&)(pkMap));
    pkMap = 0;
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kStringArray))->SetAt(1, (char *&)(pkMap));
    pkMap = 0;
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kStringArray))->SetAt(2, (char *&)(pkMap));
    pkMap = 0;
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kStringArray))->SetAt(3, (char *&)(pkMap));
    pkMap = 0;
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kStringArray))->SetAt(4, (char *&)(pkMap));
    pkMap = 0;
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kStringArray))->SetAt(5, (char *&)(pkMap));
    pkMap = 0;
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kStringArray))->SetAt(6, (char *&)(pkMap));
    pkMap = 0;
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kStringArray))->SetAt(7, (char *&)(pkMap));
    pkMap = 0;
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(m_kStringArray))->SetAt(8, (char *&)(pkMap));
    m_uiObjectFlags &= 0xf00f;
    bool bMulti = false;
    unsigned int uiSize = m_kStringArray.m_usSize;
    for (unsigned int i = 1; i < uiSize; i++)
    {
        if (m_kStringArray.m_pBase[i])
        {
            bMulti = true;
            break;
        }
    }
    if (bMulti)
        m_uiObjectFlags |= 1;
    else
        m_uiObjectFlags &= ~1;
    m_uiObjectFlags = (m_uiObjectFlags & ~0xA) | 4;
}
