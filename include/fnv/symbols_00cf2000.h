#pragma once
#include <cstdint>

struct DetailLess;
struct MotionMat4;
struct MotionState_cls;
struct ShapeDetail;

// 0x00cf2020
void SetMotionState(const ::MotionMat4 *, ::MotionState_cls *);
// 0x00cf2160
int FUN_00cf2160(uintptr_t, uintptr_t);
// 0x00cf2ed0
void QuickSortShapeDetails(::ShapeDetail **, int, int, ::DetailLess);
