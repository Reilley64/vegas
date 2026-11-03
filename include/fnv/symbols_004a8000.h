#pragma once

#include <cstdint>

class TESObjectREFR;
struct BGSBodyPart;

// 0x004a8a90
namespace fnv_004a8a90 { const char *FUN_004a8a90(char *); }
// 0x004a8b00
std::uintptr_t FUN_004a8b00(::BGSBodyPart *);
// 0x004a8b40
void AddToRefCountIfNotFlagged(::TESObjectREFR *, int, int **);
// 0x004a8bb0
namespace fnv_004a8bb0 { void FUN_004a8bb0(float *, float *, bool, bool); }
// 0x004a8f20
int MinInt(int, int);
