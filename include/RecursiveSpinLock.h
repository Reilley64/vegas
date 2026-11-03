#ifndef FNV_BSSPINLOCK_H
#define FNV_BSSPINLOCK_H
#include "layout_support.h"
class FNV_ALIGN(32) RecursiveSpinLock
{
  public:
    volatile unsigned int m_uiOwningThreadID;  // +0x0
    unsigned int m_uiRecursionCount;              // +0x4
    unsigned int layoutPadding8[6];
    void Lock(const char* name);
    FNV_FORCEINLINE void Unlock()
    {
        if (--m_uiRecursionCount == 0)
            m_uiOwningThreadID = 0;
    }
public:
    void FUN_0040fba0();
};
#endif
