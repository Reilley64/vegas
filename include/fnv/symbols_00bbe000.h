#pragma once

namespace fnv_00bbe9c0 { class SolPosition; }
namespace fnv_00bbe9c0 { struct S00bbe9c0_Flags; }
namespace fnv_00bbe9c0 { struct S00bbe9c0_Obj; }
struct LightSource;
struct RenderContext;

// 0x00bbe9c0
namespace fnv_00bbe9c0 { void FUN_00bbe9c0(const ::fnv_00bbe9c0::SolPosition *, ::fnv_00bbe9c0::S00bbe9c0_Obj *, ::fnv_00bbe9c0::S00bbe9c0_Flags **, unsigned int); }
// 0x00bbecd0
void ApplyLightSource(::LightSource *, ::RenderContext *);
