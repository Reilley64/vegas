// include/havok/hkMemoryRouter.h - the per-thread memory router FUN_00c85750 returns (hkMemoryRouter::getInstance).
#ifndef FNV_HAVOK_HKMEMORYROUTER_H
#define FNV_HAVOK_HKMEMORYROUTER_H

#include "fnv/symbols_00c85000.h"

// Native allocator interface. Slot comments identify retained source calls, not a host ABI.
class hkMemoryAllocator
{
  public:
    struct MemoryStatistics
    {
        int allocated = 0;
        int inUse = 0;
        int peakInUse = 0;
        int available = 0;
        int totalAvailable = 0;
        int largestBlock = 0;
    };

    enum MemoryState
    {
        MEMORY_STATE_OK,
        MEMORY_STATE_OUT_OF_MEMORY
    };

    virtual ~hkMemoryAllocator();                                                     // +0x0
    virtual void* blockAlloc(int numBytes) = 0;                                           // +0x4
    virtual void blockFree(void* p, int numBytes) = 0;                                    // +0x8
    virtual void* bufAlloc(int& reqNumBytesInOut);                                    // +0xc
    virtual void bufFree(void* p, int numBytes);                                      // +0x10
    virtual void* bufRealloc(void* pOld, int oldNumBytes, int& reqNumBytesInOut);     // +0x14
    virtual void blockAllocBatch(void** ptrsOut, int numPtrs, int blockSize);         // +0x18
    virtual void blockFreeBatch(void** ptrsIn, int numPtrs, int blockSize);           // +0x1c
    // Unidentified: the base version (0x00cbf260) passes its argument on to canAllocTotal.
    virtual bool forwardToCanAllocTotal(int numBytes);                                // +0x20
    virtual bool canAllocTotal(int numBytes);                                         // +0x24
    virtual void getMemoryStatistics(MemoryStatistics& u) = 0;                            // +0x28
    virtual int getAllocatedSize(const void* obj, int numBytes) = 0;                      // +0x2c
    virtual void resetPeakMemoryStatistics() = 0;                                         // +0x30

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
    hkMemoryRouter();
    hkMemoryRouter* Clear();
    char* m_stackCurrent;        // +0x0, next free byte of the thread's stack allocator
    void* m_stack04;             // +0x4, rest of the stack allocator state
    void* m_stack08;             // +0x8
    hkMemoryAllocator* m_temp;   // +0xc
    hkMemoryAllocator* m_heap;   // +0x10
    hkMemoryAllocator* m_debug;  // +0x14
    hkMemoryAllocator* m_solver; // +0x18
    hkMemoryAllocator* m_allocator; // backing allocator installed by the memory system
    int m_threadSlot = -1;               // record selected during thread initialization

    // Bump allocation from the thread's stack area; callers round numBytes as the original did.
    void* allocateStack(int numBytes)
    {
        char* p = m_stackCurrent;
        m_stackCurrent = p + numBytes;
        return p;
    }

    void deallocateStack(void* p)
    {
        m_stackCurrent = static_cast<char*>(p);
    }

    void shrinkAllocatedStack(void* p, int newSize)
    {
        m_stackCurrent = static_cast<char*>(p) + newSize;
    }

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
