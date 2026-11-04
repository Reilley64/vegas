#pragma once

#include <cstdint>

class NiPoint3;
class PathingLocation;
class TESObjectCELL;
class TESSound;
class TESWorldSpace;
struct Vec3;

// 0x006d9100
bool GetPathingLocationNormal(::PathingLocation &, ::NiPoint3 &);
// 0x006d9350
int FUN_006d9350(void *, std::intptr_t, float, ::TESSound *);
// 0x006d93d0
bool DoBoundsOverlap(const ::NiPoint3 *, const ::NiPoint3 *, const ::NiPoint3 *, const ::NiPoint3 *);
// 0x006d9480
bool IsPathingLocationClear(::PathingLocation *, float);
// 0x006d97b0
bool FUN_006d97b0(const ::NiPoint3 &, ::TESObjectCELL *, ::TESWorldSpace *, void *);
// 0x006d9830
bool GetNavMeshHeight(::PathingLocation *, float *);
// 0x006d99a0
::Vec3 FUN_006d99a0(float, ::PathingLocation *, ::PathingLocation *, float);
