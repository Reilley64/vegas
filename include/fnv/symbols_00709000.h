#pragma once

#include <cstdint>

struct NiCamera;

// 0x00709470
void FUN_00709470(int, std::intptr_t, int, int, int);
// 0x007094f0
namespace s7094f0 { void FUN_007094f0(); }
// 0x00709840
void *FUN_00709840(void *);
// 0x00709ae0
void FUN_00709ae0();
// 0x00709af0
void FUN_00709af0();
// 0x00709b00
void FUN_00709b00();
// 0x00709b10
void FUN_00709b10();
// 0x00709b20
void FUN_00709b20();
// 0x00709b30
void FUN_00709b30();
// 0x00709b40
void FUN_00709b40();
// 0x00709b50
void FUN_00709b50(unsigned char, float, float, int);
// 0x00709bc0
bool FUN_00709bc0();
// 0x00709c00
bool FUN_00709c00();
// 0x00709c20
void FUN_00709c20(std::intptr_t);
// 0x00709c60
void FUN_00709c60(bool);
// 0x00709c80
void FUN_00709c80(bool);
// 0x00709ca0
void FUN_00709ca0();
// 0x00709cb0
void FUN_00709cb0();
// 0x00709d00
void FUN_00709d00();
// 0x00709d10
namespace fnv_00709d10 { bool FUN_00709d10(); }
// 0x00709d20
void FUN_00709d20(std::intptr_t);
// 0x00709d40
bool FUN_00709d40();
// 0x00709d50
void UpdateCameraFrustum(::NiCamera *, float);
// 0x00709fd0
void InitUIRoot(unsigned int, bool);
