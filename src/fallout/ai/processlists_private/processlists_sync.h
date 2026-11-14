// Unit-private PC declarations. Sources: JohnnyGuitarNVSE Bethesda
// C++03 spelling only; no community implementation bodies are included.
#ifndef FNV_PROCESSLISTS_PRIVATE_SYNC_H
#define FNV_PROCESSLISTS_PRIVATE_SYNC_H

#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/SemaphoreWaitReceiver.h"
#include "processlists_layout_support.h"

class FNV_ALIGN(32) RecursiveSpinLock
{
  public:
    RecursiveSpinLock();
    ~RecursiveSpinLock();

    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;

    void Lock(const char* apName = 0);  // PC 0040FBF0
    bool TryLock();
    void Unlock();  // PC 0040FBA0
    bool IsLocked() const;

  private:
    RecursiveSpinLock(const RecursiveSpinLock&);
    RecursiveSpinLock& operator=(const RecursiveSpinLock&);
public:
    void FUN_0040fba0();
};

class LockPrimitive
{
  public:
    LockPrimitive();
    ~LockPrimitive();

    unsigned int m_uiLockState;

    void Lock();
    bool TryLock();
    void Unlock();
    bool IsLocked() const;
};

class CountingSemaphore
{
  public:
    CountingSemaphore();
    CountingSemaphore(unsigned int auiCount);
    CountingSemaphore(unsigned int auiCount, unsigned int auiMaxCount);
    ~CountingSemaphore();

    unsigned int ItemUpdateArray;
    void* hSemaphore;
    unsigned int uiMaxCount;

    bool Test();
};
#endif
