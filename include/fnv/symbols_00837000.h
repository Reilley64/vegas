#pragma once

class TESTopic;
namespace ImpactSound { struct ImpactData; }
struct FUN_008373d0_struct;
struct FootstepActor;
struct Node_00837410;
struct RadioState;

// 0x00837060
bool AdvanceConversation(::RadioState *, ::TESTopic *);
// 0x008373d0
::FUN_008373d0_struct *ClearStruct(::FUN_008373d0_struct *);
// 0x008373f0
void FUN_008373f0(void *);
// 0x00837410
void FUN_00837410(::Node_00837410 *);
// 0x008374b0
const char *FUN_008374b0(int);
// 0x008374e0
namespace fnv_008374e0 { void SetGlobalPointerAtOffset(int, const char *); }
// 0x00837520
void FUN_00837520();
// 0x00837550
namespace ImpactSound { void FUN_00837550(::ImpactSound::ImpactData *); }
// 0x00837cc0
void PlayFootstepSound(::FootstepActor *, int);
