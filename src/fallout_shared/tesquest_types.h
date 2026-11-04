// fallout_shared/tesquest_types.h: declares TESRecipe, ScriptLocals, TESScriptableForm, TESTexture, TESIcon and more
#ifndef TESQUEST_TYPES_H
#define TESQUEST_TYPES_H

#include <malloc.h>
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0059e400_shell.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005abf60_shell.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_005dc960_shell.h"
#include "fnv/decl/FUN_005ec370_shell.h"
#include "fnv/decl/FUN_005ec500_shell.h"
#include "fnv/decl/FUN_0060ce80_Obj.h"
#include "fnv/decl/FUN_0067fdb0_shell.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/StageHolder.h"
#include "fnv/decl/TESFaction_RankDataView.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_005a9f20__FUN_005a9f20_shell.h"
#include "fnv/decl/fnv_005aa090__FUN_005aa090.h"
#include "fnv/decl/fnv_0060f2c0__FUN_0060f2c0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv_a3d_form_types.h"
class TESQuest;
class PlayerQuestData;
class RegionObjectEntry;
class QuantityData;
class TESRecipe
{
  public:
};
class ScriptLocalVariable;
class FormFlagRecord;
class ScriptDefinition;
class ScriptLocals
{
  public:
    Script* m_pOwnerScript;
    char m_cActionFlags;
    BSSimpleList<FormFlagRecord*>* m_pLocalVariableList;
    BSSimpleList<ScriptLocalVariable*>* m_pVariableList;
    ScriptDefinition* m_pExtendedLocals;
    ScriptLocals();
    ~ScriptLocals();
};
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;
    bool m_bHasScript;
    unsigned char layoutPadding9[3];
    void InitItem(TESForm* owner);
};
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> cTextureName;
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};
class TESIcon : public TESTexture
{
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
};
class PerkEntryConditionSet
{
  public:
    BSSimpleList<void*> m_kConditionItems;
    void InitializeConditionItems();
    void InitItem(TESForm* owner);
    void Load(TESFile* file);
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target);
};
class QuestData
{
  public:
    unsigned char m_ucEntryType, ucPriority;
    unsigned char layoutPadding2[2];
    float fQuestDelayTime;
};
class AnimationClipStatus
{
  public:
    unsigned char m_ucClipIdentifier;
    bool m_bCompleted;
};
class QuestStage
{
  public:
    AnimationClipStatus m_Data;
    unsigned char layoutPadding2[2];
    BSSimpleList<PlayerQuestData*> m_kStageItems;
    QuestStage();
    ~QuestStage();
    void SetIndex(unsigned char index);
    void InitItem(TESForm* owner);
    void Load(TESFile* file);
    void AddStageItem(PlayerQuestData* item);
};
enum QUEST_OBJECTIVE_STATE
{
    QOS_DORMANT = 0,
    QOS_DISPLAYED = 1,
    QOS_COMPLETED = 2,
    QOS_COMPLETED_DISPLAYED = 3
};
class TESQuest;
class BGSQuestObjective
{
  public:
    virtual ~BGSQuestObjective();
    unsigned int iIndex;
    BSStringT<char> m_kDisplayText;
    TESQuest* m_pOwnerQuest;
    BSSimpleList<RegionObjectEntry*> m_kTargetList;
    bool bInitialized;
    unsigned char layoutPadding1D[3];
    QUEST_OBJECTIVE_STATE eState;
    BGSQuestObjective();
    void SetIndex(unsigned int index);
    void InitItem(TESQuest* owner);
public:
    void SetOwner(::TESQuest *);
public:
    bool GetDisplayed() const;
};
class RegionObjectEntry
{
  public:
    unsigned char cFlags;
    unsigned char layoutPadding1[3];
    PerkEntryConditionSet m_kInfoConditions;
    TESObjectREFR* m_pReference;
    unsigned int m_auiData[14];
    RegionObjectEntry();
    void Load(TESFile* file);
    TESObjectREFR* GetReference(bool resolve);
};
class Script : public TESForm
{
  public:
    // The canonical Script prefix is 0x54 bytes; these routines only call members.
    unsigned char scriptFields[0x3c];
};
class Date
{
  public:
    unsigned short usDate, usYear;
    Date();
    Date(const Date& date);
    ~Date();
};
class PlayerQuestData
{
  public:
    unsigned char m_ucEntryType;
    unsigned char layoutPadding1[3];
    PerkEntryConditionSet m_kInfoConditions;
    Script ScriptData;
    unsigned int uiFileOffset;
    unsigned char m_ucClipIdentifier;
    bool bHasLogEntry;
    unsigned char layoutPadding66[2];
    Date* pLogDate;
    TESQuest* pOwner;
    TESQuest* pNextQuest;
    PlayerQuestData();
    bool Load(TESFile* file);
    void SetIndex(unsigned char index);
    void SetHasLogEntry(bool value);
};
class TESFile
{
  public:
    bool NextChunk();
    bool IsEndianConversionRequired();
    bool GetChunkData(unsigned int* value);
};
class TESFullNameLoader
{
  public:
};
class FormChangeMask
{
  public:
    unsigned int uiFlags;
    FormChangeMask(unsigned int value);
    operator bool() const;
};
class BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags(unsigned int mask);
    FormChangeMask GetOldChangeFlags(unsigned int mask);
};
union SETTING_VALUE
{
    bool b;
    float f;
    int i;
    const char* s;
};
class INISettingCollection;
template <class C> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
class TESQuest : public TESForm
{
  public:
    TESScriptableForm tESScriptableFormComponent;
    TESIcon tESIconComponent;
    TESFullName tESFullNameComponent;
    QuestData data;
    BSSimpleList<QuestStage*> m_kStageList;
    BSSimpleList<BGSQuestObjective*> m_kObjectives;
    PerkEntryConditionSet m_kInfoConditions;
    ScriptLocals* m_pScriptLocals;
    unsigned char m_ucEnabled;
    unsigned char layoutPadding61[3];
    BSStringT<char> strEditorID;
    virtual const char* GetEditorName() const;  // 0x138: public PC header confirms this slot
    void ResetFormData();
    virtual void ClearData();
    void RemoveAllStages();
    void ClearObjectives();
    unsigned int GetStageMask();
    void UpdateStageMask();
    bool HasStage(unsigned char index);
    bool IsStageComplete(unsigned char index);
    BGSQuestObjective* GetObjective(unsigned int index);
    void GetTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets, BSSimpleList<BGSQuestObjective*>* objectives);
    bool HasTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets, BSSimpleList<BGSQuestObjective*>* objectives);
    virtual void InitItem();
    bool Load(TESFile* file);
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    void SetEnabled(bool enabled);
    void RunScript();
    void SetStartsEnabled(bool enabled);
    PerkEntryConditionSet* GetConditions();
    QuestStage* GetStage(unsigned char index);
    void AddStageDataAtIndex(QuestStage* stage);
    void AddObjective(BGSQuestObjective* objective);
};
#endif
