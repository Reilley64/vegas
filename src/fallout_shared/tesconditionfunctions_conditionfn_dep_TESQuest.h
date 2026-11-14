// Source layout: TESQuest. PC corrections are in generate_headers.py.
#ifndef TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESQUEST_H
#define TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESQUEST_H

#include "fnv/decl/FUN_0061af10_shell.h"
#include "tesconditionfunctions_conditionfn_dep_layout_support.h"
#include "tesconditionfunctions_conditionfn_dep_QUEST_DATA.h"
#include "tesconditionfunctions_conditionfn_dep_TESCondition.h"
#include "tesconditionfunctions_conditionfn_dep_TESForm.h"
#include "tesconditionfunctions_conditionfn_dep_TESFullName.h"
#include "tesconditionfunctions_conditionfn_dep_TESIcon.h"
#include "tesconditionfunctions_conditionfn_dep_TESScriptableForm.h"
class BGSQuestObjective;
class TESQuest : public TESForm
{
  public:
    TESScriptableForm tESScriptableFormComponent;    // +0x18
    TESIcon tESIconComponent;                        // +0x24
    TESFullName tESFullNameComponent;                // +0x30
    QuestData data;                                 // +0x3C
    BSSimpleList<QuestStage*> m_kStageList;       // +0x44
    BSSimpleList<BGSQuestObjective*> m_kObjectives;  // +0x4C
    PerkEntryConditionSet m_kInfoConditions;                  // +0x54
    ScriptLocals* m_pScriptLocals;                   // +0x5C
    unsigned char m_ucEnabled;                       // +0x60
    unsigned char layoutPadding61[3];
    PerkEntryConditionSet* GetConditions();
    ScriptLocals* GetScriptLocalData();
public:
    ::BGSQuestObjective *GetObjective(unsigned int);
public:
    bool HasStage(unsigned char);
public:
    unsigned int GetStageMask();
};
#endif
