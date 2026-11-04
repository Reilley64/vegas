// Source layout: StatsMenu::StatusEffectList. PC corrections are in generate_headers.py.
#ifndef FNV_STATSMENU__STATUSEFFECTLIST_H
#define FNV_STATSMENU__STATUSEFFECTLIST_H

#include "layout_support.h"
class StatsMenu__StatusEffectList
{
  public:
    void** m_ppVirtualMethodTable;                                                                          // +0x0
    BSSimpleList<StatsMenu__StatusEffect*> bSSimpleList_StatsMenu__StatusEffect___Component;  // +0x4
};
#endif
