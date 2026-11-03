#ifndef FNV_TESCONDITION_H
#define FNV_TESCONDITION_H
#include "layout_support.h"
class TESForm;
class PerkEntryConditionSet
{
  public:
    BSSimpleList<TESConditionItem*> m_kConditionItems;  // +0x0
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target);
    PerkEntryConditionSet();
    ~PerkEntryConditionSet();
    void InitializeConditionItems();
    void Load(TESFile* file);
public:
    void InitItem(::TESForm *);
public:
    bool Compare(::PerkEntryConditionSet *);
};
#endif
