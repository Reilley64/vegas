#pragma once

namespace fnv_004b3570 { struct NiPoint3V; }
namespace fnv_004b3570 { struct NiTriShape; }
namespace fnv_004b3570 { struct RgbaColor; }
namespace fnv_004b3890 { struct FUN_004a7800; }
namespace fnv_004b3890 { struct FUN_00a746e0; }
struct FUN_006815c0;
struct Geometry;
struct NiLines;
struct NiPoint3;
struct RgbaColor;

// 0x004b3570
namespace fnv_004b3570 { ::fnv_004b3570::NiTriShape *FUN_004b3570(::fnv_004b3570::NiPoint3V, ::fnv_004b3570::NiPoint3V, ::fnv_004b3570::NiPoint3V, const ::fnv_004b3570::RgbaColor &, bool); }
// 0x004b3890
namespace fnv_004b3890 { ::fnv_004b3890::FUN_00a746e0 *FUN_004b3890(const class ::FUN_006815c0 &, const ::fnv_004b3890::FUN_004a7800 &, const class ::FUN_006815c0 &, const ::fnv_004b3890::FUN_004a7800 &, bool); }
// 0x004b3ab0
float LinearInterpolate(float, float, float, float, float);
// 0x004b3ae0
::NiPoint3 *FUN_004b3ae0(::NiPoint3 *, const ::NiPoint3 &, const float *);
// 0x004b3b90
::NiLines *CreateSquareLines(float, const ::RgbaColor &, bool);
// 0x004b3e60
bool MatchGeometryVertices(::Geometry *, ::Geometry *, float, float, bool);
