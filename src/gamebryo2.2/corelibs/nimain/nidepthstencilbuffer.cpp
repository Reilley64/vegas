
// src/gamebryo2.2/corelibs/nimain/nidepthstencilbuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nidepthstencilbuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/fnv_00a8f1c0__FUN_00a8f1c0_cls.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f6000.h"
extern "C"
{
    struct NiRTTI;
}


// @fnv 0x00a9fe50
const NiRTTI* __cdecl FUN_00a9fe50()
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_011f603c));
}

extern int vftable_NiDepthStencilBuffer;
struct Helper
{
};
struct NiDepthStencilBuffer
{
    void* Destroy(unsigned int);
};
// Sets the vftable, calls FUN_00a8f1c0, and if flag bit 0 is set frees this with size 0x14, returning this.
// @fnv 0x00a9fe60
void* NiDepthStencilBuffer::Destroy(unsigned int auiFlags)
{
    *(void**)this = (void*)&vftable_NiDepthStencilBuffer;
    reinterpret_cast<::fnv_00a8f1c0::FUN_00a8f1c0_cls *>((((Helper*)this)))->FUN_00a8f1c0();
    if (auiFlags & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}
