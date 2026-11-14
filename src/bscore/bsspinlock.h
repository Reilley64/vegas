// Reconstructed bCore spin-lock (bscore/bsspinlock.h).
//
// object to 0x20). The remaining API (out-of-line Lock/TryLock/Unlock
// and the two static tunables) is declared from the cross-referenced
// original code: 0x0040fbf0 Lock(name), 0x0078d200 TryLock,
// 0x0040fba0 Unlock.
#ifndef BSCORE_BSSPINLOCK_H
#define BSCORE_BSSPINLOCK_H

#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0078d200_cls.h"
#include "layout_support.h"

class FNV_ALIGN(32) RecursiveSpinLock
{
  public:
    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    unsigned char layoutPadding8[24];

    void UnlockUnconditional();
    bool IsLocked();
    bool IsLockedByUs();
    void Wait();

    static unsigned int ms_uiFirstValue;
    static unsigned int ms_uiSecondValue;
public:
    void FUN_0040fba0();
};


// The process-wide bCore spin-lock.
RecursiveSpinLock g_spinLock;

// @fnv 0x0078d1f0
bool BSSpinLockGlobalTryLock()
{
    return reinterpret_cast<::FUN_0078d200_cls *>(&(g_spinLock))->FUN_0078d200();
}

#endif
