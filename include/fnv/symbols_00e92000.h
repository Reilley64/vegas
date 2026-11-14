#pragma once
#include <cstdint>

namespace fnv_00e92ee0 { struct NiD3DVertexShader; }
namespace fnv_00e92f30 { class NiD3DPixelShader; }
struct Lst;
struct Nd;
struct Program;

// 0x00e92eb0
::Program *FUN_00e92eb0();
// 0x00e92ee0
namespace fnv_00e92ee0 { bool FUN_00e92ee0(::fnv_00e92ee0::NiD3DVertexShader *); }
// 0x00e92f30
namespace fnv_00e92f30 { bool FUN_00e92f30(::fnv_00e92f30::NiD3DPixelShader *); }
// 0x00e92f70
void FUN_00e92f70(intptr_t);
// 0x00e92fe0
intptr_t FUN_00e92fe0(::Lst *, intptr_t, ::Nd **);
