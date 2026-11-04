#pragma once

struct FUN_00522df0_shell;
struct FootstepActor;
class TESSound;

// 0x008391b0
void PlayFootstepImpact(::FootstepActor *, int);
// 0x008397f0
void PlayBlockSound(int, ::FUN_00522df0_shell *, float, float, float, float, float, float);
// 0x00839ab0
namespace fnv_00839ab0 { void InitFootstepImpacts(); }
// 0x00839d30
void InitializeSlots();
// 0x00839e00
::TESSound *FUN_00839e00(int, float, float);
