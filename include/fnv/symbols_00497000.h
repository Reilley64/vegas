#pragma once
#include <cstdint>

class Actor;
class Animation;
namespace fnv_004975e0 { struct SavedAnim; }
struct FUN_004965d0;

// 0x004975e0
namespace fnv_004975e0 { void FUN_004975e0(void *, ::fnv_004975e0::SavedAnim *, std::intptr_t, float); }
// 0x004977e0
::FUN_004965d0 *LoadIdleAnimation(::Actor *, ::Animation *, float);
