#pragma once

class TESPackage;
struct Pair8;

// 0x006705b0
int FUN_006705b0(int, int);
// 0x00670670
int FindPairValue(int, ::Pair8 *, int);
// 0x00670700
bool IsScaledValueAboveThreshold(float, float);
// 0x00670b90
::TESPackage *CreatePackageByType(int);
