// src/havok/common/base/system/io/istream/hkistream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/istream/hkistream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00dcc160_cls.h"
struct Allocator
{
    virtual void first();
    virtual void second();
    virtual void Free(void* memory, unsigned short bytes);
};
struct Manager
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Allocator* allocator;
};
struct Record
{
    void* vtable00;
    unsigned short unk04;
    Record* FUN_00dcca30(unsigned int flags);
};
// Calls FUN_00dcc160, then if bit 0 of flags is set frees this through the manager's allocator using unk04 as size, and returns this.
// @fnv 0x00dcca30
Record* Record::FUN_00dcca30(unsigned int flags)
{
    reinterpret_cast<::FUN_00dcc160_cls *>(this)->FUN_00dcc160();
    if (flags & 1)
    {
        Manager* manager = static_cast<Manager*>(::FUN_00c85750());
        Allocator* allocator = manager->allocator;
        unsigned short size = unk04;
        allocator->Free(this, size);
    }
    return this;
}
