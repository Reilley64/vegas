
// src/staging/blk_00ea0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00ebf000.h"
#include "fnv/symbols_00ec0000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_0126f000.h"
#include "../../include/layout_support.h"

// Returns the smallest power of two greater than or equal to value, or value itself when it is 2 or less.
// @fnv 0x00ebfc80
unsigned int __cdecl RoundUpToPowerOfTwo(unsigned int value)
{
    if (value > 16)
    {
        if (value > 64)
        {
            if (value > 128)
            {
                if (value > 256)
                {
                    if (value > 512)
                    {
                        return 1024;
                    }
                    else
                    {
                        return 512;
                    }
                }
                else
                {
                    return 256;
                }
            }
            else
            {
                return 128;
            }
        }
        else
        {
            if (value > 32)
            {
                return 64;
            }
            else
            {
                return 32;
            }
        }
    }
    else
    {
        if (value > 4)
        {
            if (value > 8)
            {
                return 16;
            }
            else
            {
                return 8;
            }
        }
        else
        {
            if (value > 2)
            {
                return 4;
            }
        }
    }
    return value;
}

struct Interface_00ebfd20
{
    virtual void Unk00() = 0;
    virtual void Unk04() = 0;
    virtual unsigned long Release() = 0;
};

struct Struct_00ebfd20
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    Interface_00ebfd20** unk40;
};

struct Standin_011f6238
{
};


// Releases each interface pointer in the array at unk40, clears the array pointer, and calls FUN_00aa4060 on the struct.
// @fnv 0x00ebfd20
void __cdecl ReleaseInterfaceArray(Struct_00ebfd20* pStruct)
{
    if (pStruct->unk40 != 0)
    {
        for (unsigned int i = 0; i < pStruct->unk20; i++)
        {
            if (pStruct->unk40[i] != 0)
            {
                pStruct->unk40[i]->Release();
            }
        }
        pStruct->unk40 = 0;
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::Standin_011f6238 *>(&::g_memoryManager))))->FUN_00aa4060(pStruct);
    }
}

struct FnvLockedRect
{
    int Pitch;
    void* pBits;
};

struct FnvD3DTexture
{
    virtual long QueryInterface(void* riid, void** ppv);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual long GetDevice(void** ppDevice);
    virtual long SetPrivateData(void* guid, const void* data, unsigned long size, unsigned long flags);
    virtual long GetPrivateData(void* guid, void* data, unsigned long* size);
    virtual long FreePrivateData(void* guid);
    virtual unsigned long SetPriority(unsigned long priority);
    virtual unsigned long GetPriority();
    virtual void PreLoad();
    virtual int GetType();
    virtual unsigned long SetLOD(unsigned long lod);
    virtual unsigned long GetLOD();
    virtual unsigned long GetLevelCount();
    virtual long SetAutoGenFilterType(int filterType);
    virtual int GetAutoGenFilterType();
    virtual void GenerateMipSubLevels();
    virtual long GetLevelDesc(unsigned int level, void* desc);
    virtual long GetSurfaceLevel(unsigned int level, void** surface);
    virtual long LockRect(unsigned int level, FnvLockedRect* lockedRect, const void* rect,
                                    unsigned long flags);
    virtual long UnlockRect(unsigned int level);
};

struct FnvD3DDevice
{
    virtual long QueryInterface(void* riid, void** ppv);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual long TestCooperativeLevel();
    virtual unsigned int GetAvailableTextureMem();
    virtual long EvictManagedResources();
    virtual long GetDirect3D(void** ppD3D);
    virtual long GetDeviceCaps(void* caps);
    virtual long GetDisplayMode(unsigned int swapChain, void* mode);
    virtual long GetCreationParameters(void* params);
    virtual long SetCursorProperties(unsigned int x, unsigned int y, void* bitmap);
    virtual void SetCursorPosition(int x, int y, unsigned long flags);
    virtual int ShowCursor(int show);
    virtual long CreateAdditionalSwapChain(void* params, void** swapChain);
    virtual long GetSwapChain(unsigned int index, void** swapChain);
    virtual unsigned int GetNumberOfSwapChains();
    virtual long Reset(void* params);
    virtual long Present(const void* src, const void* dst, void* wnd, const void* dirty);
    virtual long GetBackBuffer(unsigned int swapChain, unsigned int index, int type, void** surface);
    virtual long GetRasterStatus(unsigned int swapChain, void* status);
    virtual long SetDialogBoxMode(int enable);
    virtual void SetGammaRamp(unsigned int swapChain, unsigned long flags, const void* ramp);
    virtual void GetGammaRamp(unsigned int swapChain, void* ramp);
    virtual long CreateTexture(unsigned int width, unsigned int height, unsigned int levels,
                                         unsigned long usage, int format, int pool, FnvD3DTexture** texture,
                                         void** sharedHandle);
};


extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

// @fnv 0x00ebf7d0
FnvD3DTexture* __cdecl CreateZeroedTexture(FnvD3DDevice* device, int format, int unused, unsigned int bytesPerPixel,
                                           unsigned int width, unsigned int height)
{
    FnvD3DTexture* texture = 0;
    FnvLockedRect lockedRect3;
    char* row;
    unsigned int rowSize5;
    unsigned int y4;
    bool bDefaultPoolB;
    bool bDynamic;
    if (device->CreateTexture(width, height, 1, 0x200, format, 0, &texture, 0) >= 0)
        goto locked;
    bDefaultPoolB = DAT_0126f0d0;
    bDynamic = DAT_0126f0d0;
    if (device->CreateTexture(width, height, 1, bDynamic ? 0x200 : 0, format, bDefaultPoolB ? 0 : 1, &texture, 0) >= 0)
    {
    locked:
        if (texture->LockRect(0, &lockedRect3, 0, 0) >= 0)
        {
            row = (char*)lockedRect3.pBits;
            rowSize5 = width * bytesPerPixel;
            for (y4 = 0; y4 < height; y4++)
            {
                fnv_zlib_memset(row, 0, rowSize5);
                row += lockedRect3.Pitch;
            }
            texture->UnlockRect(0);
        }
    }
    return texture;
}

struct GridAllocator : Standin_011f6238
{
};
void* __cdecl FUN_00ec61c0(void* destination, int value, unsigned int bytes);

// Allocates a tiled texture object, computes tile grid counts and edge sizes, creates a texture per tile, and frees everything if any tile creation fails.
// @fnv 0x00ebf8e0
Struct_00ebfd20* __cdecl CreateTiledTexture(void* device, unsigned int width, unsigned int height,
                                            unsigned int bytesPerPixel, unsigned int tileSize, unsigned int format)
{
    // Local spellings and declaration order preserve the original MSVC9 stack layout.
    Struct_00ebfd20* pitch;                                           // Allocated grid descriptor.
    unsigned int edgeWidth = (width * bytesPerPixel + 15) & ~15u;     // Aligned image row pitch.
    unsigned int column = RoundUpToPowerOfTwo(width % tileSize);      // Rounded width of the partial column.
    unsigned int edgePitch = RoundUpToPowerOfTwo(height % tileSize);  // Rounded height of the partial row.
    unsigned int next = column * bytesPerPixel;                       // Maximum required row pitch.
    if (next < edgeWidth)
        next = edgeWidth;
    unsigned int row = height > edgePitch ? height : edgePitch;  // Maximum required height.
    // Total number of full and partial tiles.
    unsigned int i = ((width + tileSize - 1) / tileSize) * ((height + tileSize - 1) / tileSize);
    pitch = (Struct_00ebfd20*)reinterpret_cast<::MemoryManagerStandIn *>((((GridAllocator*)&(*reinterpret_cast<::Standin_011f6238 *>(&::g_memoryManager)))))->FUN_00aa3e40(0x48 + i * 4);
    if (!pitch)
        return 0;
    FUN_00ec61c0(pitch, 0, 0x48);
    pitch->unk40 = (Interface_00ebfd20**)((char*)pitch + 0x48);
    pitch->unk00 = (int)device;
    pitch->unk20 = i;
    pitch->unk1C = edgeWidth;
    pitch->unk0C = width;
    pitch->unk10 = height;
    pitch->unk08 = bytesPerPixel;
    pitch->unk24 = width / tileSize;
    pitch->unk28 = height / tileSize;
    pitch->unk2C = column;
    pitch->unk30 = edgePitch;
    pitch->unk34 = width % tileSize;
    pitch->unk38 = height % tileSize;
    pitch->unk3C = tileSize;
    pitch->unk04 = format;
    Interface_00ebfd20** maxHeight = pitch->unk40;  // Next tile output slot.
    unsigned int edgeHeight, count, grid;           // Column, row, and cleanup index, respectively.
    // Allocate full rows, followed by any partial right edge.
    for (count = 0; count < pitch->unk28; count++)
    {
        for (edgeHeight = 0; edgeHeight < pitch->unk24; edgeHeight++)
        {
            *maxHeight =
                ((::Interface_00ebfd20 *)(::CreateZeroedTexture((::FnvD3DDevice *)(device), pitch->unk04, pitch->unk1C, pitch->unk08, pitch->unk3C, pitch->unk3C)));
            maxHeight++;
        }
        if (pitch->unk2C)
        {
            *maxHeight =
                ((::Interface_00ebfd20 *)(::CreateZeroedTexture((::FnvD3DDevice *)(device), pitch->unk04, pitch->unk1C, pitch->unk08, pitch->unk2C, pitch->unk3C)));
            maxHeight++;
        }
    }
    // Allocate the partial bottom row, including its bottom-right corner.
    if (pitch->unk30)
    {
        for (edgeHeight = 0; edgeHeight < pitch->unk24; edgeHeight++)
        {
            *maxHeight =
                ((::Interface_00ebfd20 *)(::CreateZeroedTexture((::FnvD3DDevice *)(device), pitch->unk04, pitch->unk1C, pitch->unk08, pitch->unk3C, pitch->unk30)));
            maxHeight++;
        }
        if (pitch->unk2C)
        {
            *maxHeight =
                ((::Interface_00ebfd20 *)(::CreateZeroedTexture((::FnvD3DDevice *)(device), pitch->unk04, pitch->unk1C, pitch->unk08, pitch->unk2C, pitch->unk30)));
            maxHeight++;
        }
    }
    // A failed tile allocation releases every tile already created.
    for (grid = 0; grid < pitch->unk20; grid++)
    {
        if (!pitch->unk40[grid])
        {
            for (grid = 0; grid < pitch->unk20; grid++)
            {
                if (pitch->unk40[grid])
                {
                    pitch->unk40[grid]->Release();
                    pitch->unk40[grid] = 0;
                }
            }
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::Standin_011f6238 *>(&::g_memoryManager))))->FUN_00aa4060(pitch);
            return 0;
        }
    }
    pitch->unk18 = 0;
    return pitch;
}

struct IUnknownEBF
{
    virtual long QueryInterface(const void* riid, void** ppvObject);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual long Apply(unsigned long uiFlags);
};

struct EffectStackEBF
{
    int unk00, unk04, unk08, unk0C, unk10;
    int m_iArrayLength;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    IUnknownEBF** m_ppkStack;
};

// @fnv 0x00ebff00
void __cdecl ApplyLastEffect(EffectStackEBF* pkStack)
{
    pkStack->m_ppkStack[pkStack->m_iArrayLength - 1]->Apply(0);
}

struct D3DLOCKED_RECT
{
    int Pitch;
    void* pBits;
};

struct IDirect3DTexture9_stub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual int LockRect(unsigned int Level, D3DLOCKED_RECT* pLockedRect, const void* pRect,
                                   unsigned int Flags);
};

struct TiledTexture
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int u14;
    int unk18;
    int unk1c;
    unsigned int u20;
    unsigned int u24;
    unsigned int u28;
    unsigned int u2c;
    unsigned int u30;
    int unk34;
    int unk38;
    unsigned int u3c;
    IDirect3DTexture9_stub** ppTextures;
};

// Locks the next texture in ppTextures, writes pBits/pPitch and tile coordinates, and advances u14.
// @fnv 0x00ebfda0
int __cdecl LockNextTile(TiledTexture* apTiledTexture, void** ppBits, int* pPitch, unsigned int* pX, unsigned int* pY,
                         unsigned int* pW, unsigned int* pH)
{
    D3DLOCKED_RECT p;
    unsigned int c3;
    unsigned int l3;
    unsigned int k;

    if (apTiledTexture->u14 < apTiledTexture->u20)
    {
        if (apTiledTexture->ppTextures[apTiledTexture->u14]->LockRect(0, &p, 0, 0) < 0)
        {
            goto fail;
        }
        if (ppBits)
        {
            *ppBits = p.pBits;
        }
        if (pPitch)
        {
            *pPitch = p.Pitch;
        }
        k = (apTiledTexture->u2c != 0) + apTiledTexture->u24;
        l3 = apTiledTexture->u14 / k;
        c3 = apTiledTexture->u14 - k * l3;
        if (pX)
        {
            *pX = c3 * apTiledTexture->u3c;
        }
        if (pY)
        {
            *pY = l3 * apTiledTexture->u3c;
        }
        if (pW)
        {
            *pW = (c3 >= apTiledTexture->u24) ? apTiledTexture->u2c : apTiledTexture->u3c;
        }
        if (pH)
        {
            *pH = (l3 >= apTiledTexture->u28) ? apTiledTexture->u30 : apTiledTexture->u3c;
        }
        apTiledTexture->u14 = apTiledTexture->u14 + 1;
        return 1;
    }
    else
    {
    fail:
        apTiledTexture->u14 = 0;
        return 0;
    }
}

namespace fnv_00ebff30 {
#include <d3d9.h>

struct TileGrid
{
    IDirect3DDevice9* device;
    unsigned int unk04;
    unsigned int height;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int width;
    unsigned int unk20;
    unsigned int columns;
    unsigned int rows;
    unsigned int edgeWidth;
    unsigned int edgeHeight;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int tileSize;
    IDirect3DBaseTexture9** textures;
};

// Renders a grid of textured tiles and optional edge strips to the D3D device using the textures in the TileGrid.
// @fnv 0x00ebff30
void __cdecl FUN_00ebff30(TileGrid* grid, float startX, float startY, float scaleX, float scaleY)
{
    ::FUN_00ec0460((::FUN_00ec0460_cls *)(grid->device));
    grid->device->SetRenderState(D3DRS_ZENABLE, 0);
    grid->device->SetRenderState(D3DRS_ZWRITEENABLE, 0);
    grid->device->SetRenderState(D3DRS_COLORWRITEENABLE, 15);
    float x;
    unsigned int row;
    {
        unsigned int column;
        float stepY;
        {
            float y;
            float stepX;
            {
                unsigned int tileArea;
                unsigned int remainder;
                {
                    IDirect3DBaseTexture9** texture;
                    texture = grid->textures;
                    tileArea = grid->tileSize * grid->height;
                    remainder = grid->width * grid->tileSize - grid->columns * grid->tileSize * grid->height;
                    stepX = grid->tileSize * scaleX;
                    stepY = grid->tileSize * scaleY;
                    y = startY;
                    for (row = 0; row < grid->rows; row++)
                    {
                        x = startX;
                        for (column = 0; column < grid->columns; column++)
                        {
                            grid->device->SetTexture(0, *texture);
                            texture++;
                            ::DrawTexturedQuad((::EC0280Device *)(grid->device), x, y, scaleX, scaleY, grid->tileSize, grid->tileSize);
                            x += stepX;
                        }
                        if (grid->edgeWidth != 0)
                        {
                            grid->device->SetTexture(0, *texture);
                            texture++;
                            ::DrawTexturedQuad((::EC0280Device *)(grid->device), x, y, scaleX, scaleY, grid->edgeWidth, grid->tileSize);
                        }
                        y += stepY;
                    }
                    if (grid->edgeHeight != 0)
                    {
                        x = startX;
                        for (column = 0; column < grid->columns; column++)
                        {
                            grid->device->SetTexture(0, *texture);
                            texture++;
                            ::DrawTexturedQuad((::EC0280Device *)(grid->device), x, y, scaleX, scaleY, grid->tileSize, grid->edgeHeight);
                            x += stepX;
                        }
                        if (grid->edgeWidth != 0)
                        {
                            grid->device->SetTexture(0, *texture);
                            texture++;
                            ::DrawTexturedQuad((::EC0280Device *)(grid->device), x, y, scaleX, scaleY, grid->edgeWidth, grid->edgeHeight);
                        }
                    }
                    grid->device->SetRenderState(D3DRS_ZENABLE, 1);
                    grid->device->SetRenderState(D3DRS_ZWRITEENABLE, 1);
                    grid->device->SetTexture(0, 0);
                }
            }
        }
    }
}
}  // namespace fnv_00ebff30
