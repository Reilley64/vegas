
// src/havok/physics/collide/filter/list/hkpcollisionfilterlistclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/filter/list/hkpcollisionfilterlistclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
struct FUN_00e012f0_class;



struct FUN_00e012f0_class
{
    int unk00;
    unsigned short m4;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00e012f0_class* InitialiseAndNotify(unsigned int flags);
};

extern "C" void __cdecl FUN_00e49f40();
typedef void(* InitialiseFunction)(FUN_00e012f0_class*);

// Calls FUN_00e49f40 on this, then if flags has bit 0 set, frees this (m4 bytes) to the heap allocator, and returns this.
// @fnv 0x00e012f0
FUN_00e012f0_class* FUN_00e012f0_class::InitialiseAndNotify(unsigned int flags)
{
    reinterpret_cast<InitialiseFunction>(FUN_00e49f40)(this);
    if (flags & 1)
    {
        hkMemoryRouter::getInstance().heap().blockFree(this, m4);
    }
    return this;
}
