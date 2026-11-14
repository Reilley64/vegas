
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00e806c0.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0126f000.h"
class NiD3DShaderConstantMap
{
  public:
    void* Destroy(unsigned int flags);
};

extern "C" void __cdecl FUN_00e87690();

// Calls FUN_00e87690, then if bit 0 of flags is set calls __Dummy_00b6fef0 on this with 0x44, and returns this.
// @fnv 0x00b7e410
void* NiD3DShaderConstantMap::Destroy(unsigned int flags)
{
    FUN_00e87690();
    if (flags & 1)
    {
        ::FUN_00aa1460(this, 0x44);
    }
    return this;
}


struct FUN_00e80610_shell
{
    void FUN_00e80610();
};

// @fnv 0x00e80610
void FUN_00e80610_shell::FUN_00e80610()
{
    DAT_0126f74c = 0;
    *(int*)((char*)this + 0x38) = 0;
}


// @fnv 0x00e7c680
const char* const* __cdecl FUN_00e7c680()
{
    return &(*reinterpret_cast<const char *const *>(&::g_0126f754));
}

struct NiD3DShader
{
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x00e7c690
void* NiD3DShader::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00e806c0 *>(this)->FUN_00e806c0::~FUN_00e806c0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x3c);
    return this;
}
