// Source layout: GarbageCollector. PC corrections are in generate_headers.py.
#ifndef FNV_GARBAGECOLLECTOR_H
#define FNV_GARBAGECOLLECTOR_H

#include "fnv/symbols_011de000.h"
#include "processlists_layout_support.h"
class GarbageCollector
{
  public:
    static void Remove(TESObjectREFR* reference);
    static void Add(BSTempEffect* effect);
};
FNV_STATIC_ASSERT(sizeof(GarbageCollector) == 0x1);
#endif
