// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimationclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimationclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00e345a0_Obj.h"
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
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    CpuObject* FUN_00dfb8e0(unsigned int flags);
};
// @fnv 0x00dfb8e0
CpuObject* CpuObject::FUN_00dfb8e0(unsigned int flags)
{
    reinterpret_cast<::FUN_00e345a0_Obj *>(this)->FUN_00e345a0();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = static_cast<CpuAllocatorHolder*>(::FUN_00c85750());
        holder->allocator->Invoke(this, size);
    }
    return this;
}
