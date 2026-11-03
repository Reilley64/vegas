// Source layout: MemoryManager. PC corrections are in generate_headers.py.
#ifndef FNV_MEMORYMANAGER_H
#define FNV_MEMORYMANAGER_H
#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "layout_support.h"
// Partial PC prefix through m_bPoolAllocationEnabled; sizeof is the prefix, not the runtime allocation.
#pragma pack(push, 4)
class MemoryManager
{
  public:
    unsigned int layoutPadding0[74];
    unsigned char layoutPadding128;
    bool m_bPoolAllocationEnabled;  // +0x129
    unsigned short layoutPadding12A;
    static MemoryManager& Instance();
    void CreatePool(unsigned int blockSize, unsigned int poolSize, char* description);
    void* Allocate(unsigned int size);
    void Deallocate(void* pointer);
    void* Reallocate(void* pointer, unsigned int size);
    unsigned int Size(const void* pointer);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MemoryManager) == 0x12C);
FNV_STATIC_ASSERT(offsetof(MemoryManager, m_bPoolAllocationEnabled) == 0x129);
#endif
