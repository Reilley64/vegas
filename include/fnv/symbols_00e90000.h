#pragma once

struct NiDX9RenderedCubeMapData;
struct NiDX9Renderer;
struct NiRenderedCubeMap;
struct TexOwner;
struct TexRecord;

// 0x00e901a0
::NiDX9RenderedCubeMapData *FUN_00e901a0(::NiRenderedCubeMap *, ::NiDX9Renderer *);
// 0x00e904c0
::TexRecord *CreateDynamicTexture(::TexOwner *);
