
// src/havok/common/base/memory/router/hkmemoryrouter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/router/hkmemoryrouter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "havok/hkMemoryRouter.h"
#include <cstdint>
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/symbols_01268000.h"
struct FUN_00c85690_Allocator
{
    virtual void unk00();
    virtual void* Allocate(unsigned int size);
};

struct FUN_00c85690_Header
{
    FUN_00c85690_Allocator* allocator;
    uintptr_t size;
    int unk08;
    int unk0C;
};

// Allocates size plus a header from allocator, stores size and allocator in the header, and returns the pointer past the header.
// @fnv 0x00c85690
void* __cdecl AllocateWithHeader(FUN_00c85690_Allocator* allocator, uintptr_t size)
{
    FUN_00c85690_Header* header = (FUN_00c85690_Header*)allocator->Allocate(size + sizeof(FUN_00c85690_Header));
    header->size = size;
    header->allocator = allocator;
    return header + 1;
}

struct Child
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void Release();
};
struct Owner
{
    int unk00, unk04, unk08;
    Child* child0C;
    Child* child10;
    Child* child14;
    Child* child18;
    Child* child1C;
    void ReleaseChildren();
};
// Releases the five Child objects held by the Owner (child0C, child10, child14, child18, child1C).
// @fnv 0x00c856f0
void Owner::ReleaseChildren()
{
    child14->Release();
    child1C->Release();
    child10->Release();
    child18->Release();
    child0C->Release();
}

class MemHeap
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void Free(char* block, unsigned int size);
};

// If p is non-null, clears the field at p-0x10 and calls heap->Free on the block at p minus the offset stored at p-8, with size from p-0xc plus 0x10.
// @fnv 0x00c85660
void __cdecl FUN_00c85660(MemHeap* heap, char* apBlock)
{
    if (apBlock == 0)
    {
        return;
    }
    unsigned int size = *(unsigned int*)(apBlock - 0xc) + 0x10;
    char* block = apBlock - *(unsigned int*)(apBlock - 8);
    *(unsigned int*)(apBlock - 0x10) = 0;
    heap->Free(block, size);
}

struct FNV_Dispatch
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08(void* block, unsigned int size);
};

struct FNV_BlockHeader
{
    unsigned int m_iObjectReferenceCount;
    unsigned int m_iElementCount;
};

// If data is non-null, clears the block header's first field and dispatches the header with its size plus 0x10 to owner->unk08.
// @fnv 0x00c856c0
void FUN_00c856c0(FNV_Dispatch* owner, char* data)
{
    if (data == 0)
        return;

    FNV_BlockHeader* header = (FNV_BlockHeader*)(data - 0x10);
    unsigned int size = header->m_iElementCount + 0x10;
    header->m_iObjectReferenceCount = 0;
    owner->unk08(header, size);
}

struct ReturnType
{
    int unk00;
    unsigned short unk04;
};

struct Pool
{
    virtual void unk00();
    virtual ReturnType* Alloc(unsigned int nbytes);
};

struct Holder
{
};


// @fnv 0x0056d280
ReturnType* __cdecl FUN_0056d280(unsigned int nbytes)
{
    ReturnType* result;
    {
        Pool* pool = ((::Pool *)(reinterpret_cast<::MagicCaster_shell *>((static_cast<Holder*>(::FUN_00c85750())))->FUN_0044edb0()));
        result = pool->Alloc(nbytes);
    }
    result->unk04 = (unsigned short)nbytes;
    return result;
}

#include "generated/data/havok/common/base/memory/router/hkmemoryrouter.inc"
