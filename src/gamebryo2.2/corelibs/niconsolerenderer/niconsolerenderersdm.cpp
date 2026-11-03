
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_010f0000.h"
struct NiD3DShaderProgramCreatorHLSL
{
    unsigned int m_uiCompileFlags;
    void FUN_00e91ae0(unsigned int uiFlags);
};

// @fnv 0x00e91ae0
void NiD3DShaderProgramCreatorHLSL::FUN_00e91ae0(unsigned int uiFlags)
{
    ((unsigned int*)this)[1] = uiFlags;
}

namespace fnv_00e91c10 {

struct NiD3DShaderProgramCreatorHLSL
{
    void* m_vftable;
    ~NiD3DShaderProgramCreatorHLSL();
    void* Destroy(unsigned int flags);
};

// @fnv 0x00e91c10
void* NiD3DShaderProgramCreatorHLSL::Destroy(unsigned int flags)
{
    m_vftable = &(*reinterpret_cast<void * *>(&::DAT_010f0a68));
    if (flags & 1)
    {
        ::FUN_00aa1460(this, 8);
    }
    return this;
}
}  // namespace fnv_00e91c10

struct NiD3DShaderProgramCreator
{
    void* vtable;
    void* FUN_00e91be0(unsigned int);
};
// @fnv 0x00e91be0
void* NiD3DShaderProgramCreator::FUN_00e91be0(unsigned int flags)
{
    vtable = (void*)&DAT_010f0a68;
    if (flags & 1)
        ::FUN_00aa1460(this, 4);
    return this;
}

extern int DAT_010f0ac0;
struct Holder00e91c40
{
    int m0;
    int m4;
    void* m8;
    int mC;
    void* DestroyHolder(unsigned int);
};
// @fnv 0x00e91c40
void* Holder00e91c40::DestroyHolder(unsigned int auiFlags)
{
    void* p = m8;
    *(void**)this = (void*)&DAT_010f0ac0;
    ::FUN_00aa10f0(p);
    *(void**)this = (void*)&DAT_010f0a68;
    if (auiFlags & 1)
        ::FUN_00aa1460(this, 0x10);
    return this;
}
