#ifndef FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_FNV_TESCONDITION_H
#define FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_FNV_TESCONDITION_H
#include "interface_rebase_layout_support.h"
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
