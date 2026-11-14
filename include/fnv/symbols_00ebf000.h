#pragma once

namespace fnv_00ebff30 { struct TileGrid; }
struct EffectStackEBF;
struct FnvD3DDevice;
struct FnvD3DTexture;
struct Struct_00ebfd20;
struct TiledTexture;

// 0x00ebf7d0
::FnvD3DTexture *CreateZeroedTexture(::FnvD3DDevice *, int, int, unsigned int, unsigned int, unsigned int);
// 0x00ebf8e0
::Struct_00ebfd20 *CreateTiledTexture(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
// 0x00ebfd20
void ReleaseInterfaceArray(::Struct_00ebfd20 *);
// 0x00ebfda0
int LockNextTile(::TiledTexture *, void **, int *, unsigned int *, unsigned int *, unsigned int *, unsigned int *);
// 0x00ebff00
void ApplyLastEffect(::EffectStackEBF *);
// 0x00ebff30
namespace fnv_00ebff30 { void FUN_00ebff30(::fnv_00ebff30::TileGrid *, float, float, float, float); }
