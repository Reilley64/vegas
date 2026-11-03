#pragma once

class BillboardNode;
class NiPoint3;

// 0x00a7e770
::BillboardNode *FUN_00a7e770();
// 0x00a7e960
void NormalizePoints(::NiPoint3 *, unsigned int, unsigned int);
// 0x00a7ec90
void AddScaledPoints(::NiPoint3 *, float, const ::NiPoint3 *, unsigned int);
