#pragma once
#include <cstdint>

#include <cstdint>

class NiPoint3;
namespace CircleIntersection { struct Circle; }
namespace CircleIntersection { struct Line; }
namespace CircleIntersection { struct Result; }
namespace ns6b { struct V3; }
struct FUN_006ba7e0_cls;
struct Pt3;
struct TanPoint3;
struct ThreeDimensionalVector;
struct TwoComponentVector;

// 0x006ba010
bool FUN_006ba010(const ::NiPoint3 *, const ::NiPoint3 *, const ::NiPoint3 *, const ::NiPoint3 *);
// 0x006ba100
namespace fnv_006ba100 { bool FUN_006ba100(const ::NiPoint3 *, const ::NiPoint3 *, const ::NiPoint3 *, const ::NiPoint3 *, ::NiPoint3 *); }
// 0x006ba240
bool FUN_006ba240(const ::ThreeDimensionalVector *, const ::ThreeDimensionalVector *, const ::ThreeDimensionalVector *, const ::ThreeDimensionalVector *, ::ThreeDimensionalVector *);
// 0x006ba3d0
::TwoComponentVector *FUN_006ba3d0(::TwoComponentVector *, ::TwoComponentVector *, ::TwoComponentVector *, ::TwoComponentVector *, ::TwoComponentVector *);
// 0x006ba550
::NiPoint3 FUN_006ba550(const ::NiPoint3 &, const ::NiPoint3 &, const ::NiPoint3 &, const ::NiPoint3 &);
// 0x006ba6e0
bool FUN_006ba6e0(const ::ns6b::V3 &, const ::ns6b::V3 &, const ::ns6b::V3 &, const ::ns6b::V3 &, ::ns6b::V3 *);
// 0x006ba7e0
bool FUN_006ba7e0(std::uintptr_t, ::FUN_006ba7e0_cls *, std::uintptr_t, ::FUN_006ba7e0_cls *, ::NiPoint3 *);
// 0x006ba8c0
bool ComputeCircleTangents(const ::TanPoint3 &, float, const ::TanPoint3 &, ::TanPoint3 &, ::TanPoint3 &);
// 0x006ba9e0
bool FUN_006ba9e0(const ::Pt3 &, const ::Pt3 &, const ::Pt3 &, float);
// 0x006bab00
bool FUN_006bab00(const ::Pt3 &, float, const ::Pt3 &, const ::Pt3 &);
// 0x006bac20
namespace CircleIntersection { bool IntersectLineCircle(::CircleIntersection::Circle *, const ::CircleIntersection::Line *, ::CircleIntersection::Result *); }
