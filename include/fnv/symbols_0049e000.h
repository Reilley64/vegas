#pragma once

struct Cell;
struct FUN_0049eed0_list;
struct FUN_0049eed0_target;
struct Pt;

// 0x0049e2f0
bool AreVectorsEqual(const float *, const float *, float);
// 0x0049e390
bool IsApproximatelyEqual(float, float, float);
// 0x0049eed0
bool AnyPointInListMatches(::FUN_0049eed0_list *, ::FUN_0049eed0_target *);
// 0x0049ef60
unsigned int GetCellCornerFlags(::Cell *, ::Pt);
