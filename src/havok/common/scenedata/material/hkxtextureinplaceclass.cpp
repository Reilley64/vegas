
// src/havok/common/scenedata/material/hkxtextureinplaceclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/material/hkxtextureinplaceclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/fnv_00e01750__FUN_00e01750.h"
struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl FUN_00c85750();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    CpuObject* DestroyIfFlagged(unsigned int flags);
};
// @fnv 0x00e017a0
CpuObject* CpuObject::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::fnv_00e01750::FUN_00e01750 *>(this)->fnv_00e01750::FUN_00e01750::~FUN_00e01750();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
