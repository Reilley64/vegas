
// src/havok/animation/animation/motionanalysis/hkafootstepanalysisinfoclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motionanalysis/hkafootstepanalysisinfoclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "fnv/decl/fnv_00e40fd0__Owner.h"
struct Allocator
{
    virtual void first();
    virtual void second();
    virtual void deallocate(void* object, unsigned short size);
};
struct Global
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Allocator* allocator;
};
struct FUN_00dfe4b0_Class
{
    int vtable;
    unsigned short size;
    int unk08;
    int unk0c;
    int unk10;
    void* DestroyOrReturnSelf(unsigned char flags);
};
// Calls ClearItems, and if bit 0 of flags is set, deallocates this through the global allocator; returns this.
// @fnv 0x00dfe4b0
void* FUN_00dfe4b0_Class::DestroyOrReturnSelf(unsigned char flags)
{
    reinterpret_cast<::fnv_00e40fd0::Owner *>(this)->ClearItems();
    if (flags & 1)
    {
        Global* global = static_cast<Global*>(::FUN_00c85750());
        global->allocator->deallocate(this, size);
    }
    return this;
}
