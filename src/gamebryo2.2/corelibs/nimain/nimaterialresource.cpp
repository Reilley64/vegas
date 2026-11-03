
// src/gamebryo2.2/corelibs/nimain/nimaterialresource.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nimaterialresource.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00be0ae0
#include <new>
#include <cstddef>
#include "fnv/decl/FixedStringOwner.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0126f000.h"
char const* const* __cdecl FUN_00be0ae0()
{
    return &(*reinterpret_cast<const char *const *>(&::g_0126f9ac));
}

void* __cdecl operator new(std::size_t size, unsigned int flags);

struct FUN_00eea750_shell
{
    virtual ~FUN_00eea750_shell();
    void* Destroy(unsigned int flags);
};

// Calls ReleaseStrings, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00eea750
void* FUN_00eea750_shell::Destroy(unsigned int flags)
{
    static_cast<::FixedStringOwner *>(nullptr)->ReleaseStrings();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x2c);
    return this;
}

// 0x00be0ad0  mov eax,[ecx+0x1c]; ret
struct C00be0ad0
{
    char pad00[0x1c];
    int m1c;
    int FUN_00be0ad0();
};

// @fnv 0x00be0ad0
int C00be0ad0::FUN_00be0ad0()
{
    return m1c;
}

// @fnv 0x00eea510
void* FUN_00eea510(void* thisptr)
{
    return (char*)thisptr + 0x14;
}
