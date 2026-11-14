// Private declaration copy; original: relay_work/queue/queue058/01_fallout_interface_menus_statsmenu_cpp/include/MagicTarget.h
// Source layout: MagicTarget. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICTARGET_H
#define FNV_MAGICTARGET_H

#include "statsmenu_layout_support.h"
class MagicTarget
{
  public:
    bool m_bLeadingFlag;  // +0x4
    bool m_bSecondFlag;         // +0x5
    unsigned char layoutPadding6[2];
    BSSimpleList<MagicEffectContext*> m_kActiveEffectList;  // +0x8
    virtual bool AddEffectToTarget(MagicCaster* caster, MagicItem* spell, ActiveEffect* effect, bool immediate);
};
#endif
