
// src/havok/physics/collide/query/collector/raycollector/hkpclosestrayhitcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/raycollector/hkpclosestrayhitcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0059c000.h"
extern void __cdecl operator delete(void*);
struct HKPCloseStrayHitCollector
{
    void* __thiscall Destroy(unsigned int flags);
};
// Calls FUN_0059cf00 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x0059cf20
void* __thiscall HKPCloseStrayHitCollector::Destroy(unsigned int flags)
{
    ::FUN_0059cf00((void **)(void *)(this));
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
