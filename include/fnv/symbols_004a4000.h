#pragma once
#include <cstdint>

struct NiPoint3;
struct RgbaColor;
struct FUN_004a4650_ListBase;
struct FUN_004a5280;
struct Target004a4d40;

// 0x004a4040
char IsStartMenuFlag1Set();
// 0x004a4240
float FUN_004a4240();
// 0x004a4650
void FUN_004a4650(::FUN_004a4650_ListBase *);
// 0x004a4d40
void *FUN_004a4d40(::Target004a4d40 *);
// 0x004a4e90
void *FUN_004a4e90(int, ::NiPoint3 *, ::RgbaColor *);
// 0x004a4f80
::FUN_004a5280 *FUN_004a4f80(const float *, std::uintptr_t);
