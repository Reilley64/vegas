
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00a5fc00
#include "fnv/decl/FUN_004a4cc0_shell.h"
#include "fnv/decl/FUN_00a5c240_shell.h"
#include "fnv/symbols_00a3d000.h"
#include "fnv/symbols_00a5f000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f4000.h"
const char* const* __cdecl FUN_00a5fc00()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f450c));
}

struct RgbaColor
{
};
struct Helper
{
    char _0[4];
    RgbaColor _4;
};
// Returns false if AreFloatsEqual(a, b) is false, otherwise returns the result of a->_4.FUN_004a4cc0(b->_4).
// @fnv 0x00a299c0
bool __cdecl CompareHelpers(Helper const* apLeft, Helper const* apRight)
{
    if (!((bool)(::AreFloatsEqual((const float *)(apLeft), (const float *)(apRight)))))
        return false;
    return reinterpret_cast<::FUN_004a4cc0_shell *>((void *)&(apLeft->_4))->FUN_004a4cc0((void *)&(apRight->_4));
}

struct RendererData
{
    virtual ~RendererData();
};
struct NiTexture
{
    int _00[9];
    RendererData* m_pTextureRendererData;
    int _28[2];
    void* Destroy(unsigned int);
};
// @fnv 0x00a60120
void* NiTexture::Destroy(unsigned int flags)
{
    *(void**)this = (void*)&DAT_0109b944;
    delete m_pTextureRendererData;
    ::FUN_00a5f800((::TextureListView *)(void *)(this));
    reinterpret_cast<::FUN_00a5c240_shell *>((this))->DestroyFogProperty();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x30);
    return this;
}
