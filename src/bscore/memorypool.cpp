#include <cstdint>
#include <cstddef>
// bscore/memorypool.cpp: MemoryPool (13 functions)

#include <cstring>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00aa6650_Class.h"
#include "fnv/decl/FUN_00aa6680_class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NodeSorter.h"
#include "fnv/decl/VirtualReservationSearch.h"
#include "fnv/symbols_00aa6000.h"
#include "fnv/symbols_01000000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/memory_pool.h"

// @fnv 0x00aa6e00
void MemoryPool::PushFreeBlock(void* apBlock)
{
    MemoryPool__FreePoolBlock* block = reinterpret_cast<MemoryPool__FreePoolBlock*>(apBlock);
    block->m_pPreviousBlock = 0;
    block->pNext = m_pFreeBlockHead;
    if (m_pFreeBlockHead)
        m_pFreeBlockHead->m_pPreviousBlock = block;
    m_pFreeBlockHead = block;
    ++m_uiFreeBlockCount;
}

// @fnv 0x00aa6db0
unsigned int MemoryPool::FUN_00aa6db0()
{
    for (unsigned int i = 0; i < m_uiPageCount; ++i)
    {
        if (m_pPageBlockCounts[i] == 0xFFFF)
        {
            return i;
        }
    }
    return 0xFFFFFFFF;
}

// Unlinks node from its doubly linked list by patching its neighbours' pointers and decrementing count.
// @fnv 0x00aa6e60
void MemoryPool::UnlinkNode(MemoryPool__FreePoolBlock* node)
{
    if (node->m_pPreviousBlock != 0)
    {
        node->m_pPreviousBlock->pNext = node->pNext;
    }
    if (node->pNext != 0)
    {
        node->pNext->m_pPreviousBlock = node->m_pPreviousBlock;
    }
    m_uiFreeBlockCount--;
}

struct FUN_00aa6eb0_shell : public MemoryPool
{
    void FUN_00aa6eb0(unsigned int, bool);
};

struct Helper_00aa6eb0
{
};

struct DoublyLinkedListNode
{
    DoublyLinkedListNode* pPrev;
    DoublyLinkedListNode* pNext;
};

// @fnv 0x00aa6980
void MemoryPool::RegisterInPools()
{
    unsigned int index = m_uiAllocationSize >> 2;
    ::DAT_011f67b8[index] = this;
    unsigned int count = m_uiPoolSize >> 24;
    if (m_uiPoolSize % 0x1000000 != 0)
        count++;
    {
        uintptr_t base = reinterpret_cast<uintptr_t>(m_pPoolBase) >> 24;
        for (unsigned int i = 0; i < count; i++)
            ms_pPoolAddressMap[base + i] = this;
    }
}

struct FUN_00aa6c70_shell : public MemoryPool
{
    void FUN_00aa6c70(void*);
};

// @fnv 0x00aa6c70
void FUN_00aa6c70_shell::FUN_00aa6c70(void* apPointer)
{
    unsigned int ipageIndex;
    int u1, u2;
    if (!apPointer)
        return;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_kCriticalSection))->FUN_0040fbf0((char *)("MemoryPool::Free"));
    PushFreeBlock(apPointer);
    ipageIndex = (unsigned int)(((char*)apPointer - (char*)m_pPoolBase) >> 12);
    m_pPageBlockCounts[ipageIndex]--;
    {
        RecursiveSpinLock* pl = &m_kCriticalSection;
        pl->m_uiRecursionCount = pl->m_uiRecursionCount - 1;
        if (pl->m_uiRecursionCount == 0)
            pl->m_uiOwningThreadID = 0;
    }
}

namespace fnv_00aa6f90 {
struct FUN_00aa6f90_shell : public MemoryPool
{
    void FUN_00aa6f90();
};

struct FUN_00aa6eb0_shell
{
};
// @fnv 0x00aa6f90
void FUN_00aa6f90_shell::FUN_00aa6f90()
{
    bool blistSorted;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_kCriticalSection))->FUN_0040fbf0((char *)("MemoryPool::FreeUnusedPagesForAllPools()"));
    blistSorted = false;
    for (unsigned int i = 0; i < m_uiPageCount; i++)
    {
        if (m_pPageBlockCounts[i] == 0)
        {
            int u1, u2;
            if (!blistSorted)
            {
                FUN_00aa7260();
                blistSorted = true;
            }
            reinterpret_cast<::FUN_00aa6eb0_shell *>((((FUN_00aa6eb0_shell*)this)))->FUN_00aa6eb0(i, false);
        }
    }
    {
        RecursiveSpinLock* pl = &m_kCriticalSection;
        pl->m_uiRecursionCount = pl->m_uiRecursionCount - 1;
        if (pl->m_uiRecursionCount == 0)
            pl->m_uiOwningThreadID = 0;
    }
}
}  // namespace fnv_00aa6f90

namespace fnv_00aa6aa0 {
struct FUN_00aa6aa0_shell : public MemoryPool
{
    void* FUN_00aa6aa0(unsigned int);
};

struct MemoryPool_PCP
{
};
// Locks the pool, allocates a new page and free list if empty, pops a free block, updates page usage, and returns the block or null.
// @fnv 0x00aa6aa0
void* FUN_00aa6aa0_shell::FUN_00aa6aa0(unsigned int requested)
{
    void* pmem;
    {
        char* pfirstFreePage;
        {
            unsigned int ientriesPerPage;
            {
                unsigned int inewPageIndex;
                {
                    unsigned int i;
                    {
                        MemoryPool__FreePoolBlock* ptemp;
                        {
                            unsigned int ipageIndex;
                            {
                                int d1;
                                {
                                    int d2;
                                    {
                                        RecursiveSpinLock* l1;
                                        {
                                            RecursiveSpinLock* l2;
                                            {
                                                RecursiveSpinLock* l3;
                                                reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_kCriticalSection))->FUN_0040fbf0((char *)("MemoryPool::Allocate"));
                                                if (!m_pFreeBlockHead)
                                                {
                                                    inewPageIndex = FUN_00aa6db0();
                                                    if (inewPageIndex == -1)
                                                    {
                                                        l1 = &m_kCriticalSection;
                                                        l1->m_uiRecursionCount--;
                                                        if (!l1->m_uiRecursionCount)
                                                            l1->m_uiOwningThreadID = 0;
                                                        return 0;
                                                    }
                                                    pfirstFreePage = 0;
                                                    ientriesPerPage = 0x1000 / m_uiAllocationSize;
                                                    if (!reinterpret_cast<::MemoryPool *>((((MemoryPool_PCP*)this)))->CommitPage(inewPageIndex, pfirstFreePage))
                                                    {
                                                        l2 = &m_kCriticalSection;
                                                        l2->m_uiRecursionCount--;
                                                        if (!l2->m_uiRecursionCount)
                                                            l2->m_uiOwningThreadID = 0;
                                                        return 0;
                                                    }
                                                    m_pPageBlockCounts[inewPageIndex] = 0;
                                                    for (i = 0; i < ientriesPerPage; i++)
                                                        PushFreeBlock(pfirstFreePage + i * m_uiAllocationSize);
                                                    m_uiAllocatedPageCount++;
                                                    if (m_uiAllocatedPageCount > m_uiPeakPageCount)
                                                        m_uiPeakPageCount = m_uiAllocatedPageCount;
                                                }
                                                pmem = 0;
                                                if (m_pFreeBlockHead)
                                                {
                                                    pmem = m_pFreeBlockHead;
                                                    ptemp = m_pFreeBlockHead;
                                                    m_pFreeBlockHead = m_pFreeBlockHead->pNext;
                                                    UnlinkNode(ptemp);
                                                    ipageIndex = (unsigned int)((char*)pmem - m_pPoolBase) >> 12;
                                                    m_pPageBlockCounts[ipageIndex]++;
                                                }
                                                l3 = &m_kCriticalSection;
                                                l3->m_uiRecursionCount--;
                                                if (!l3->m_uiRecursionCount)
                                                    l3->m_uiOwningThreadID = 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return pmem;
}
}  // namespace fnv_00aa6aa0

struct MemoryManager
{
};


struct PoolInfo
{
    const char* f0;
    unsigned int f1;
    unsigned int f2;
    unsigned int f3;
    unsigned int f4;
    unsigned int f5;
    unsigned int f6;
    unsigned int f7;
    unsigned int f8;
    unsigned int f9;
};

// Builds a PoolInfo from the pool's fields, computing f1 from the page count and f9 as f5 divided by the block size minus the free block count.
// @fnv 0x00aa6d00
PoolInfo MemoryPool::GetPoolInfo()
{
    PoolInfo info;
    std::memset(&info, 0, sizeof(PoolInfo));
    info.f0 = pDescription;
    info.f1 = m_uiPageCount * 2 + 0x80;
    info.f2 = m_uiAllocationSize;
    info.f3 = m_uiPoolSize;
    info.f4 = m_uiPageCount;
    info.f5 = m_uiAllocatedPageCount << 12;
    info.f6 = m_uiAllocatedPageCount;
    info.f7 = m_uiPeakPageCount;
    info.f8 = m_uiFreeBlockCount;
    info.f9 = info.f5 / m_uiAllocationSize - m_uiFreeBlockCount;
    return info;
}

// @fnv 0x00aa6eb0
void FUN_00aa6eb0_shell::FUN_00aa6eb0(unsigned int aiPageIndex, bool abSortRequired)
{
    char* ppageAddress = this->m_pPoolBase + (aiPageIndex << 12);
    if (abSortRequired)
    {
        FUN_00aa7260();
    }
    DoublyLinkedListNode* pfirstFreeBlock = (DoublyLinkedListNode*)ppageAddress;
    unsigned int ientriesPerPage = 0x1000 / this->m_uiAllocationSize;
    DoublyLinkedListNode* plastFreeBlock =
        (DoublyLinkedListNode*)(ppageAddress + (ientriesPerPage - 1) * this->m_uiAllocationSize);

    if (pfirstFreeBlock->pPrev != 0)
    {
        pfirstFreeBlock->pPrev->pNext = plastFreeBlock->pNext;
    }
    else
    {
        *(DoublyLinkedListNode**)&this->m_pFreeBlockHead = plastFreeBlock->pNext;
    }

    if (plastFreeBlock->pNext != 0)
    {
        plastFreeBlock->pNext->pPrev = pfirstFreeBlock->pPrev;
    }

    this->m_uiFreeBlockCount -= ientriesPerPage;
    reinterpret_cast<::FUN_00aa6650_Class *>((((Helper_00aa6eb0*)this)))->FreeMemory(aiPageIndex, ppageAddress);
    (this->m_pPageBlockCounts)[aiPageIndex] = 0xffff;
    this->m_uiAllocatedPageCount -= 1;
}

// If more than one block is free, replaces the free list by the result of SortList on it.
// @fnv 0x00aa7260
void MemoryPool::FUN_00aa7260()
{
    if (m_uiFreeBlockCount > 1)
    {
        m_pFreeBlockHead = ((MemoryPool__FreePoolBlock *)(reinterpret_cast<::NodeSorter *>(this)->SortList((::LinkedNode *)(m_pFreeBlockHead))));
    }
}

struct MemoryPool;

// @fnv 0x00aa6800
MemoryPool::~MemoryPool()
{
    if (m_pPoolBase)
    {
        reinterpret_cast<::FUN_00aa6680_class *>(this)->FreeAllocation();
        ClearPoolSlots();
    }
    void* block = m_pPageBlockCounts;
    reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(block);
}

// Clears the pool entry indexed by the block size >> 2 and zeroes count slots starting at the pool base >> 24, where count is the pool size >> 24 plus one if the pool size has a remainder.
// @fnv 0x00aa6a10
void MemoryPool::ClearPoolSlots()
{
    unsigned int count;
    unsigned int base = m_uiAllocationSize >> 2;
    ::DAT_011f67b8[base] = 0;

    count = m_uiPoolSize >> 24;
    if (m_uiPoolSize % 0x01000000u)
        count++;

    uintptr_t index = reinterpret_cast<uintptr_t>(m_pPoolBase) >> 24;
    for (unsigned int i = 0; i < count; i++)
    {
        ms_pPoolAddressMap[index + i] = 0;
    }
}

namespace fnv_00aa66a0 {
struct PageRefCount66a0
{
    unsigned short iCount;
};
}  // namespace fnv_00aa66a0

// Initializes a memory pool: rounds the block size, allocates the page ref-count array, computes reserve counts and sets each page count to 0xffff.
// @fnv 0x00aa66a0
MemoryPool::MemoryPool(unsigned int aiBlockSize, unsigned int aiPoolSize, const char* apDesc)
    : pDescription(apDesc), m_pPoolBase(0), m_pFreeBlockHead(0), m_uiPeakPageCount(0), m_pPageBlockCounts(0),
      m_uiPoolSize(aiPoolSize), m_uiFreeBlockCount(0), m_uiAllocatedPageCount(0)
{
    unsigned int nA;
    unsigned int i;
    m_kCriticalSection.m_uiOwningThreadID = 0;
    m_kCriticalSection.m_uiRecursionCount = 0;
    m_uiPageCount = aiPoolSize >> 12;
    m_uiAllocationSize = aiBlockSize;
    if (m_uiAllocationSize)
        m_uiAllocationSize = (m_uiAllocationSize + 3) & ~3;
    reinterpret_cast<::VirtualReservationSearch *>(this)->FUN_00aa65b0();
    if (!m_pPoolBase)
        return;
    m_pPageBlockCounts = (unsigned short*)new fnv_00aa66a0::PageRefCount66a0[aiPoolSize >> 12];
    nA = 0x1000 / m_uiAllocationSize;
    iFirstReserve = nA / 6;
    iSecondReserve = nA - iFirstReserve;
    for (i = 0; i < m_uiPageCount; i++)
        m_pPageBlockCounts[i] = 0xffff;
    RegisterInPools();
}

#include "generated/data/bscore/memorypool.inc"
