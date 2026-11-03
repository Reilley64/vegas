#ifndef FNV_TESCONDITION_H
#define FNV_TESCONDITION_H

#include "testopicinfo_topicinfo_layout_support.h"
class TESObjectREFR;
class PerkEntryConditionSet
{
  public:
    BSSimpleList<TESConditionItem*> m_kConditionItems;  // +0x0
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target);
    PerkEntryConditionSet();
    ~PerkEntryConditionSet();
    void InitializeConditionItems();
    void Load(TESFile* file);
    void InitItem(TESForm* owner);
public:
    bool ContainsTrait(::TESObjectREFR *, ::TESObjectREFR *, bool &, bool);
};
FNV_STATIC_ASSERT(sizeof(PerkEntryConditionSet) == 0x8);
FNV_STATIC_ASSERT(offsetof(PerkEntryConditionSet, m_kConditionItems) == 0x0);
#endif
