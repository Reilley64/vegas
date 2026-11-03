#pragma once

class NiPoint3;
class PathingLocation;
namespace fnv_006da7c0 { struct CellOps; }

// 0x006da420
::NiPoint3 FUN_006da420(float, const ::PathingLocation &, float);
// 0x006da7c0
namespace fnv_006da7c0 { float FUN_006da7c0(::fnv_006da7c0::CellOps *, const ::NiPoint3 &, int, unsigned int); }
