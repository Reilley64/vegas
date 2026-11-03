
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00aa1000.h"
struct NiD3DShaderConstantManager
{
    virtual ~NiD3DShaderConstantManager();
    void* __thiscall Destroy(unsigned int flags);
};

void __cdecl FUN_00e989c0();

// @fnv 0x00e98a70
void* __thiscall NiD3DShaderConstantManager::Destroy(unsigned int flags)
{
    FUN_00e989c0();
    if (flags & 1)
    {
        ::FUN_00aa1460(this, 0x88);
    }
    return this;
}
