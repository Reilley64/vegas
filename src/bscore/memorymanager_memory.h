// Source layout: MemoryManager. PC corrections are in generate_headers.py.
#ifndef FNV_MEMORYMANAGER_H
#define FNV_MEMORYMANAGER_H

#include <windows.h>
#include "fnv/ScrapHeapBuffer.h"
#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "layout_support.h"
#include "MemoryPool.h"
#include "IMemoryHeap.h"
template <class K, class V> class BSMapBase
{
  public:
    char data[16];
    bool GetAt(K, V&);
    void SetAt(K, V);
};
// Partial PC prefix through m_bPoolAllocationEnabled; sizeof is the prefix, not the runtime allocation.
class MemoryManager
{
  public:
    unsigned char layoutPadding0[0x114];
    BSMapBase<unsigned long, ScrapHeapBuffer*> threadScrapHeaps;
    char pad124[5];
    bool m_bPoolAllocationEnabled;  // +0x129
    unsigned char layoutPadding12A[2];
    static MemoryManager& Instance();
    ScrapHeapBuffer* GetGeneralAllocator();
    void CreatePool(unsigned int blockSize, unsigned int poolSize, char* description);
    void* Allocate(unsigned int size);
    void Deallocate(void* pointer);
    void* Reallocate(void* pointer, unsigned int size);
    unsigned int Size(const void* pointer);
public:
    void FUN_00866770();
public:
    void InitializeHeaps();
};
#endif

extern MemoryManager g_memoryManager;
enum
{
    kMinimumPoolBlockSize = 8,
    kPoolAddressRegionShift = 24
};
FNV_FORCEINLINE MemoryManager& MemoryManager::Instance()
{
    return g_memoryManager;
}

