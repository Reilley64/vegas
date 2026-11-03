// include/havok/hkMemoryRouter.h - the per-thread memory router FUN_00c85750 returns (hkMemoryRouter::getInstance).
#ifndef FNV_HAVOK_HKMEMORYROUTER_H
#define FNV_HAVOK_HKMEMORYROUTER_H

#include "fnv/symbols_00c85000.h"

// Allocator interface the router points to, in Havok's virtual slot order (32-bit vtable offsets).
class hkMemoryAllocator
{
  public:
    struct MemoryStatistics;

    virtual ~hkMemoryAllocator();                                                     // +0x0
    virtual void* blockAlloc(int numBytes);                                           // +0x4
    virtual void blockFree(void* p, int numBytes);                                    // +0x8
    virtual void* bufAlloc(int& reqNumBytesInOut);                                    // +0xc
    virtual void bufFree(void* p, int numBytes);                                      // +0x10
    virtual void* bufRealloc(void* pOld, int oldNumBytes, int& reqNumBytesInOut);     // +0x14
    virtual void blockAllocBatch(void** ptrsOut, int numPtrs, int blockSize);         // +0x18
    virtual void blockFreeBatch(void** ptrsIn, int numPtrs, int blockSize);           // +0x1c
    virtual void getMemoryStatistics(MemoryStatistics& u);                            // +0x20
    virtual int getAllocatedSize(const void* obj, int numBytes);                      // +0x24
    virtual void resetPeakMemoryStatistics();                                         // +0x28

    template <typename T> T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * int(sizeof(T));
        void* p = bufAlloc(n);
        reqNumInOut = n / int(sizeof(T));
        return static_cast<T*>(p);
    }

    template <typename T> void _bufFree(void* p, int numElem)
    {
        bufFree(p, numElem * int(sizeof(T)));
    }
};

// Offsets are the 32-bit release's.
struct hkMemoryRouter
{
    char* m_stackCurrent;        // +0x0, next free byte of the thread's stack allocator
    void* m_stack04;             // +0x4, rest of the stack allocator state
    void* m_stack08;             // +0x8
    hkMemoryAllocator* m_temp;   // +0xc
    hkMemoryAllocator* m_heap;   // +0x10
    hkMemoryAllocator* m_debug;  // +0x14
    hkMemoryAllocator* m_solver; // +0x18

    hkMemoryAllocator& temp()
    {
        return *m_temp;
    }

    hkMemoryAllocator& heap()
    {
        return *m_heap;
    }

    hkMemoryAllocator& solver()
    {
        return *m_solver;
    }

    static hkMemoryRouter& getInstance()
    {
        return *static_cast<hkMemoryRouter*>(::FUN_00c85750());
    }
};

#endif
