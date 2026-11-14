#ifndef FNV_BSCRITICALSECTION_H
#define FNV_BSCRITICALSECTION_H

#include "fnv/decl/S_0082f1f0_Lock.h"
#include "layout_support.h"
#include "_RTL_CRITICAL_SECTION.h"
class RecursiveLock
{
  public:
    _RTL_CRITICAL_SECTION CriticalSection;  // +0x0
    unsigned long m_uiFirstValue;           // +0x1C
    unsigned long m_uiSecondValue;          // +0x20
    int m_uiRecursionCount;                        // +0x24
};
#endif
