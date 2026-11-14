// fallout_shared/tesconditionfunctions_conditionfn_BGSQuestObjective.h: declares BGSQuestObjective, _State
#ifndef CONDITIONFN_BGSQUESTOBJECTIVE_DECLARATIONS_H
#define CONDITIONFN_BGSQUESTOBJECTIVE_DECLARATIONS_H

#include "tesconditionfunctions_conditionfn_dep_layout_support.h"

// PC declaration and member facts: public JohnnyGuitarNVSE BGSQuestObjective.hpp.
// Methods below are reconstructed solely from the supplied complete PC assembly.
class BGSQuestObjective
{
  public:
    BGSQuestObjective();
    virtual ~BGSQuestObjective();
    struct _State
    {
        enum State
        {
            DORMANT = 0,
            DISPLAYED = 1,
            COMPLETED = 2,
            COMPLETED_DISPLAYED = 3
        };
    };
    typedef _State::State State;
    unsigned int uiIndex;
    BSStringT<char> QuestObjectiveEntry;
    TESQuest* m_pOwnerQuest;
    BSSimpleList<RegionObjectEntry*> kTargets;
    bool bInitialized;
    State eState;
    bool GetCompleted() const;
    bool GetDisplayed() const;
};
#endif
