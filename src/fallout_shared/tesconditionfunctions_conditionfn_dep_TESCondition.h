#ifndef TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESCONDITION_H
#define TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESCONDITION_H

#include "tesconditionfunctions_conditionfn_dep_layout_support.h"
class PerkEntryConditionSet
{
  public:
    BSSimpleList<TESConditionItem*> m_kConditionItems;  // +0x0
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target);
    PerkEntryConditionSet();
    ~PerkEntryConditionSet();
    void InitializeConditionItems();
    void Load(TESFile* file);
};
#endif
