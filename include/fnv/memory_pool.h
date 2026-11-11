#ifndef FNV_MEMORY_POOL_H
#define FNV_MEMORY_POOL_H

// MemoryPool: the engine's pool of equal blocks, cut from pages of one
// reserved address range. A free block holds the two links of the free list.
//
// This is the one shared declaration of the class. It declares the members
// that build/units.json gives an address under the class's name. The header
// has no body: each member is defined by the unit that owns its address.
//
// No production code constructs this class. MemoryManager::CreateMemoryPool
// builds fnv::memory::FixedPool instead (docs/native-engine-heaps.md).
struct MemoryPool__FreePoolBlock
{
    MemoryPool__FreePoolBlock* m_pPreviousBlock;
    MemoryPool__FreePoolBlock* pNext;
};

// The owning unit's copy of the lock. The lock has no shared declaration yet.
class RecursiveSpinLock
{
  public:
    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    unsigned char layoutPadding8[24];

};

class MemoryPool
{
  public:
    const char* pDescription;
    char* m_pPoolBase;
    MemoryPool__FreePoolBlock* m_pFreeBlockHead;
    unsigned char layoutPaddingC[20];
    RecursiveSpinLock m_kCriticalSection;
    unsigned int m_uiAllocationSize;
    unsigned int m_uiPeakPageCount;
    unsigned short* m_pPageBlockCounts;
    unsigned int m_uiPageCount;
    unsigned int m_uiPoolSize;
    unsigned int m_uiFreeBlockCount;
    unsigned int m_uiAllocatedPageCount;
    unsigned int iFirstReserve;
    unsigned int iSecondReserve;
    unsigned char layoutPadding64[28];

    // Owned by src/bscore/memorypool.cpp.
    ~MemoryPool();                            // 0x00aa6800
    MemoryPool(unsigned int aiBlockSize, unsigned int aiPoolSize, const char* apDesc); // 0x00aa66a0
    void PushFreeBlock(void* pointer);        // 0x00aa6e00
    unsigned int FUN_00aa6db0();              // 0x00aa6db0
    void UnlinkNode(MemoryPool__FreePoolBlock* node); // 0x00aa6e60
    void FUN_00aa7260();                      // 0x00aa7260
    void RegisterInPools();                   // 0x00aa6980
    // Owned by src/bscore/console/memorypool_console_h_unit.cpp.
    bool CommitPage(unsigned int, char *&);   // 0x00aa6610
};

#endif
