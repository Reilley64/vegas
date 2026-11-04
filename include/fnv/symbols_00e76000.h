#pragma once

struct FUN_00e76c30_Info;
struct NiD3DVertexDeclaration;
struct NiRenderer;

// 0x00e76700
::NiD3DVertexDeclaration *FUN_00e76700(::NiRenderer *, unsigned int, unsigned int);
// 0x00e76c30
unsigned int FUN_00e76c30(::FUN_00e76c30_Info *);
// 0x00e76e30
unsigned int ConvertVertexComponents(::FUN_00e76c30_Info *);
