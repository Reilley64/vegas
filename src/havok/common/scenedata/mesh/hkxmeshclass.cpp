
// src/havok/common/scenedata/mesh/hkxmeshclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxmeshclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include "fnv/decl/FUN_00e3eaa0.h"
#include "fnv/symbols_00cb0000.h"
struct FUN_00cb0c00_class
{
    int unk00;
};
struct Allocator
{
    virtual void A();
    virtual void B();
    virtual void Free(void*, unsigned short);
};
struct Manager
{
    int unk00, unk04, unk08, unk0C;
    Allocator* unk10;
};
struct Owner
{
    virtual void V();
    unsigned short unk04, unk06;
    int unk08, unk0C, unk10;
    FUN_00cb0c00_class unk14;
    FUN_00cb0c00_class unk18;
    void* Destroy(unsigned int flags);
};
// @fnv 0x00e01ef0
void* Owner::Destroy(unsigned int flags)
{
    ::FUN_00cb0c00((intptr_t)&(unk18));
    ::FUN_00cb0c00((intptr_t)&(unk14));
    reinterpret_cast<::FUN_00e3eaa0 *>(this)->FUN_00e3eaa0::~FUN_00e3eaa0();
    if (flags & 1)
    {
        Manager* manager = static_cast<Manager*>(::FUN_00c85750());
        Allocator* allocator = manager->unk10;
        unsigned short size = unk04;
        allocator->Free(this, size);
    }
    return this;
}
