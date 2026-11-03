// NiRenderedTexture.cpp: NiRenderedTexture (6 functions)

#include "fnv/decl/FUN_00a5c240_shell.h"
#include "fnv/symbols_00a5f000.h"
#include "fnv/symbols_00a8f000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011ab000.h"
#include "fnv/symbols_011f4000.h"
#include "NiRenderedTexture.h"

// @fnv 0x00a7fc00
NiRenderedTexture* NiRenderedTexture::Create(const NiFixedString& name, unsigned int width, unsigned int height,
                                             NiRenderer* renderer, NiTexture::TextureFormatPreferences& preferences,
                                             Ni2DBuffer::MultiSamplePreference msaa, NiRenderedTexture* reuseTexture,
                                             unsigned int aliasOffset)
{
    if (!renderer)
        return 0;
    NiDX9Renderer* dxRenderer = static_cast<NiDX9Renderer*>(renderer);
    bool dimensionsPowerOfTwo = false;
    if (width)
    {
        dimensionsPowerOfTwo = (width & (width - 1)) == 0;
        if (dimensionsPowerOfTwo)
        {
            if (height)
                dimensionsPowerOfTwo = (height & (height - 1)) == 0;
            else
                dimensionsPowerOfTwo = false;
        }
    }
    if (!dimensionsPowerOfTwo)
    {
        if (!(dxRenderer->Unk_28() & 8) && !(dxRenderer->Unk_28() & 4))
            return 0;
    }
    NiRenderedTexture* texture = new NiRenderedTexture;
    texture->m_kTextureFormatPreferences = preferences;
    texture->m_pReuseTexture = reuseTexture;
    texture->m_uiAliasOffset = aliasOffset;
    Ni2DBuffer* buffer = ((::Ni2DBuffer *)(::CreateObjA8F260(width, height)));
    Ni2DBuffer* oldBuffer = texture->m_spRenderTargetBuffer.m_pObject;
    if (oldBuffer != buffer)
    {
        if (oldBuffer && InterlockedDecrement(reinterpret_cast<volatile long*>(&oldBuffer->m_uiRefCount)) == 0)
            oldBuffer->DeleteThis();
        texture->m_spRenderTargetBuffer.m_pObject = buffer;
        if (buffer)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&buffer->m_uiRefCount));
    }
    texture->m_bUseDepthBuffer = ::DAT_011f4ac0;
    texture->m_ePixelFormat = (*reinterpret_cast<::_D3DFORMAT *>(&::DAT_011ab3c8));
    texture->m_bUseMipMaps = ::DAT_011ab3c4;
    if (!dxRenderer->CreateRenderedTexture(texture, msaa))
    {
        delete texture;
        return 0;
    }
    texture->m_eMultiSamplePreference = msaa;
    texture->m_pReuseTexture = 0;
    return texture;
}

// Declarations needed
// InterlockedDecrement might be needed if not in headers, but let's assume it is or use a helper if needed.
// The error log didn't complain about InterlockedDecrement, only LONG.


// Need to declare InterlockedDecrement if it's not found.
// extern "C" long __cdecl InterlockedDecrement(long*);

// @fnv 0x00a7fd30
void* __fastcall DestroyRenderedTexture(NiRenderedTexture* self, int, unsigned char flags)
{
    void* p30 = *(void**)((char*)self + 0x30);
    if (p30)
    {
        // InterlockedDecrement((long*)((char*)p30 + 4))
        // The assembly uses a call to an address.
        // If I use InterlockedDecrement, it matches the semantics.
        if (InterlockedDecrement((long*)((char*)p30 + 4)) == 0)
        {
            void** vtbl = *(void***)p30;
            ((void(__thiscall*)(void*))vtbl[1])(p30);
        }
    }

    void* p24 = *(void**)((char*)self + 0x24);
    *(void**)self = &DAT_0109b944;
    if (p24)
    {
        void** vtbl24 = *(void***)p24;
        ((void(__thiscall*)(void*, int))vtbl24[0])(p24, 1);
    }

    ::FUN_00a5f800((::TextureListView *)(self));
    reinterpret_cast<::FUN_00a5c240_shell *>((self))->DestroyFogProperty();

    if (flags & 1)
    {
        ::FUN_00aa1460(self, 0x48);
    }

    return self;
}

struct FUN_00a7fbd0_shell : public NiRenderedTexture
{
    void* FUN_00a7fbd0();
};


// @fnv 0x00a7fbd0
void* FUN_00a7fbd0_shell::FUN_00a7fbd0()
{
    return reinterpret_cast<void*>(const_cast<char const**>((*reinterpret_cast<const char *const (*)[]>(&::g_011f4ac4))));
}

struct FUN_00a7fbe0_shell : public NiRenderedTexture
{
    unsigned int FUN_00a7fbe0();
};

// @fnv 0x00a7fbe0
unsigned int FUN_00a7fbe0_shell::FUN_00a7fbe0()
{
    void* p = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x30);
    if (p)
        return *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(p) + 8);
    return 0;
}

struct FUN_00a7fbf0_shell : public NiRenderedTexture
{
    unsigned int FUN_00a7fbf0();
};

// @fnv 0x00a7fbf0
unsigned int FUN_00a7fbf0_shell::FUN_00a7fbf0()
{
    NiRenderedTexture* this_ = static_cast<NiRenderedTexture*>(this);
    void* ptr = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this_) + 0x30);
    if (ptr)
        return *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(ptr) + 0xc);
    return 0;
}

struct FnvCpu_FUN_00be0b90_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    int value;
    int FUN_00be0b90();
};
// @fnv 0x00be0b90
int FnvCpu_FUN_00be0b90_CpuObject::FUN_00be0b90()
{
    return value;
}
