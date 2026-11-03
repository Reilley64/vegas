#pragma once

namespace fnv_00cbeaf0 { struct hkAabb; }
struct BoundsArg;
struct PointArrayArg;
struct PointBoundsOutput;
struct SweptTransformSamples;
struct hkMotionStateq;

// 0x00cbeaf0
namespace fnv_00cbeaf0 { void FUN_00cbeaf0(const float *, int, int, ::fnv_00cbeaf0::hkAabb &); }
// 0x00cbeb70
void FUN_00cbeb70(void *, int, ::PointBoundsOutput);
// 0x00cbebf0
void FUN_00cbebf0(::PointArrayArg, int, ::BoundsArg);
// 0x00cbec90
void FUN_00cbec90(const ::hkMotionStateq *, ::SweptTransformSamples *);
