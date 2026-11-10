// Source layout: InventoryChanges. PC corrections are in generate_headers.py.
#ifndef FNV_INVENTORYCHANGES_H
#define FNV_INVENTORYCHANGES_H
#include "layout_support.h"
struct InventoryChanges
{
  public:
    BSSimpleList<InventoryStackRecord*>* m_pEntryList;  // +0x0
    TESObjectREFR* pRef;                      // +0x4
    float m_fTotalWeight;                     // +0x8
    float m_fArmorWeight;                     // +0xC
    bool m_bChanged;                          // +0x10
    unsigned char layoutPadding11;
    unsigned short layoutPadding12;
    InventoryChanges(TESObjectREFR* reference);
    static InventoryChanges* CreateForReference(TESObjectREFR* reference);
};
#endif
