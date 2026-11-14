#pragma once
#include <cstdint>

class StatsMenu__HealingOption;
struct Entry;

// 0x007e0480
void FUN_007e0480(int *, int *);
// 0x007e04e0
int CompareEntryText(const ::Entry *, const ::Entry *);
// 0x007e0510
namespace fnv_007e0510 { int CompareEntryNames(void *, void *); }
// 0x007e05f0
bool IsActorValueBelowPermanent(int *);
// 0x007e06b0
namespace fnv_007e06b0 { intptr_t GetStatusResult(); }
// 0x007e06f0
bool IsHealingOptionAvailable(::StatsMenu__HealingOption *);
// 0x007e07f0
void FUN_007e07f0(char *);
// 0x007e0850
namespace fnv_007e0850 { void FUN_007e0850(void *); }
