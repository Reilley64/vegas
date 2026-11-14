#pragma once
#include <cstdint>

class NiFixedString;
class TESObjectREFR;
class NiAVObject;
struct ReferenceView;

// 0x004772e0
::NiFixedString *FUN_004772e0();
// 0x00477410
void FUN_00477410(unsigned int);
// 0x00477430
int FUN_00477430(::TESObjectREFR *);
// 0x00477560
bool FUN_00477560(::NiAVObject *);
// 0x00477bc0
unsigned int GetDestructionStageSelfDamage(::TESObjectREFR *, float);
// 0x00477ce0
namespace fnv_00477ce0 { void SetOrRemoveMapEntry(std::uintptr_t, unsigned int); }
// 0x00477d10
void FUN_00477d10(::ReferenceView *);
