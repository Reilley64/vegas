// src/gamebryo2.2/corelibs/nimain/nishaderdeclaration.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nishaderdeclaration.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_00a5d3a0.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/symbols_00aa1000.h"
struct NiRefObject
{
    virtual ~NiRefObject();
};

struct NiShaderDeclaration : NiRefObject
{
    NiShaderDeclaration* __thiscall FUN_00ee88e0(unsigned int flags);
};

extern int DAT_011011ec;

// @fnv 0x00ee88e0
NiShaderDeclaration* __thiscall NiShaderDeclaration::FUN_00ee88e0(unsigned int flags)
{
    *reinterpret_cast<void**>(this) = &DAT_011011ec;
    reinterpret_cast<class ::FUN_00a5d3d0 *>(this)->FUN_00a5d3d0::~FUN_00a5d3d0();
    if (flags & 1)
        ::FUN_00aa1460(this, 8);
    return this;
}

extern int DAT_011010ec;
struct BaseStub
{
};
struct FUN_00ee8500
{
    char _pad[40];
    FUN_00ee8500();
};
// Calls the base constructor, installs DAT_011010ec as the vtable pointer, and zeroes the byte at offset 8 and the dwords from offset 12 through 36.
// @fnv 0x00ee8500
FUN_00ee8500::FUN_00ee8500()
{
    new ((void *)(((BaseStub*)this))) struct ::FUN_00a5d3a0();
    *(volatile unsigned char*)((char*)this + 8) = 0;
    *(volatile unsigned int*)this = (unsigned int)&DAT_011010ec;
    *(volatile unsigned int*)((char*)this + 12) = 0;
    *(volatile unsigned int*)((char*)this + 16) = 0;
    *(volatile unsigned int*)((char*)this + 20) = 0;
    *(volatile unsigned int*)((char*)this + 24) = 0;
    *(volatile unsigned int*)((char*)this + 28) = 0;
    *(volatile unsigned int*)((char*)this + 32) = 0;
    *(volatile unsigned int*)((char*)this + 36) = 0;
}
