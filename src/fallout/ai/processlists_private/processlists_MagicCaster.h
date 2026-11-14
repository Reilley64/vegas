// Source layout: MagicCaster. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICCASTER_H
#define FNV_MAGICCASTER_H

#include "processlists_layout_support.h"
class MagicCaster
{
  public:
    MagicEffectCollection* apTargetLight;         // +0x4
    MagicCaster__State eState;  // +0x8
    virtual void CastSpellOnCaster(SpellItem* spell, bool immediate);
};
#endif
