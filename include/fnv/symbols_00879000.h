#pragma once

struct NiPoint3;

// 0x00879ca0
void SnapToGridCell(::NiPoint3 &);
// 0x00879d90
float FUN_00879d90();
// 0x00879da0
void WorldToCellOffset(const ::NiPoint3 &, bool, int &, int &);
