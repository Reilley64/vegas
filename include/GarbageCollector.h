// Source layout: GarbageCollector. PC corrections are in generate_headers.py.
#ifndef FNV_GARBAGECOLLECTOR_H
#define FNV_GARBAGECOLLECTOR_H

#include "layout_support.h"
class GarbageCollector
{
  public:
    static void Remove(TESObjectREFR* reference);
    static NiTObjectArray<TESObjectREFR*> ms_kReferencesQueuedForRemoval;
    static NiTObjectArray<TESObjectREFR*> ObjectGarbageB;
};
#endif
