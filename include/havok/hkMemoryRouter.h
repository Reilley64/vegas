// include/havok/hkMemoryRouter.h - the per-thread memory router FUN_00c85750 returns (hkMemoryRouter::getInstance).
#ifndef FNV_HAVOK_HKMEMORYROUTER_H
#define FNV_HAVOK_HKMEMORYROUTER_H

#include "fnv/symbols_00c85000.h"

// Allocator interface the router points to; the slots units call are blockAlloc (+0x4) and blockFree (+0x8).
class hkMemoryAllocator
{
  public:
    virtual ~hkMemoryAllocator();
    virtual void* blockAlloc(int numBytes);
    virtual void blockFree(void* p, int numBytes);
};

// Offsets are the 32-bit release's.
struct hkMemoryRouter
{
    char* m_stackCurrent;      // +0x0, next free byte of the thread's stack allocator
    void* m_stack04;           // +0x4, rest of the stack allocator state
    void* m_stack08;           // +0x8
    void* m_stack0c;           // +0xc
    hkMemoryAllocator* m_heap; // +0x10

    hkMemoryAllocator& heap()
    {
        return *m_heap;
    }

    static hkMemoryRouter& getInstance()
    {
        return *static_cast<hkMemoryRouter*>(::FUN_00c85750());
    }
};

#endif
