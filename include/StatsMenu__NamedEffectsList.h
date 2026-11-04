// Source layout: StatsMenu::NamedEffectsList. PC corrections are in generate_headers.py.
#ifndef FNV_STATSMENU__NAMEDEFFECTSLIST_H
#define FNV_STATSMENU__NAMEDEFFECTSLIST_H

#include "layout_support.h"
class StatsMenu__NamedEffectsList
{
  public:
    void** m_ppVirtualMethodTable;                                                      // +0x0
    BSSimpleList<EffectSetting*> bSSimpleList_EffectSetting___Component;  // +0x4
};
#endif
