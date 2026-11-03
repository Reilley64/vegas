#pragma once

class BGSQuestObjective;
class PerkEntryConditionSet;
class QuestStage;
class RegionObjectEntry;
class ScriptLocals;
template <class> class BSSimpleList;

class TESQuest {
public:
    // 0x0059e300
    ::ScriptLocals *GetScriptLocalData();
    // 0x005f5760
    ::PerkEntryConditionSet *GetConditions();
    // 0x0060c740
    void ResetFormData();
    // 0x0060c760
    void ClearData();
    // 0x0060c8e0
    ::BGSQuestObjective *GetObjective(unsigned int);
    // 0x0060c9c0
    void SetEnabled(bool);
    // 0x0060d4d0
    void RunScript();
    // 0x0060d510
    bool IsStageComplete(unsigned char);
    // 0x0060d600
    bool HasStage(unsigned char);
    // 0x0060d670
    void UpdateStageMask();
    // 0x0060d700
    unsigned int GetStageMask();
    // 0x0060db40
    ::QuestStage *GetStage(unsigned char);
    // 0x0060efd0
    bool HasTargetsAndObjectives(::BSSimpleList< ::RegionObjectEntry *> *, ::BSSimpleList< ::BGSQuestObjective *> *);
    // 0x0060f110
    void GetTargetsAndObjectives(::BSSimpleList< ::RegionObjectEntry *> *, ::BSSimpleList< ::BGSQuestObjective *> *);
};
