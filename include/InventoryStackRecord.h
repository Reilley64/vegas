#ifndef FNV_ITEMCHANGE_H
#define FNV_ITEMCHANGE_H

#include "layout_support.h"
class InventoryStackRecord
{
  public:
    BSSimpleList<ExtraDataList*>* m_pExtraDataLists;  // +0x0
    int m_iCountChange;                               // +0x4
    TESBoundObject* m_pItemObject;                    // +0x8
};
#endif
