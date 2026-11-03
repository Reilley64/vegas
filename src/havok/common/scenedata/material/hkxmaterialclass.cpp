
// src/havok/common/scenedata/material/hkxmaterialclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/material/hkxmaterialclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/fnv_00e3f110__FUN_00e3f110_cls.h"
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
    CpuObject* FUN_00dfd9e0(unsigned int flags);
};
// @fnv 0x00dfd9e0
CpuObject* CpuObject::FUN_00dfd9e0(unsigned int flags)
{
    reinterpret_cast<::fnv_00e3f110::FUN_00e3f110_cls *>(this)->Destroy();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
