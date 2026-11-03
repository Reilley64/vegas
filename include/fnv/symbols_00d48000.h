#pragma once
#include <cstdint>

struct FUN_00d48330_vt;
struct S00d48d30_Result;
struct S00d48d30_Stream;
struct S_00d483a0_Result;

// 0x00d48330
void FUN_00d48330(::FUN_00d48330_vt *);
// 0x00d48350
void FUN_00d48350(int *);
// 0x00d48360
int *FUN_00d48360();
// 0x00d483a0
::S_00d483a0_Result CheckMagicPair(unsigned int, unsigned int);
// 0x00d485a0
extern "C" int FUN_00d485a0(intptr_t, intptr_t, int, int, int);
// 0x00d48620
int FUN_00d48620(int, int, int);
// 0x00d48af0
void FUN_00d48af0(void *, int *);
// 0x00d48d30
intptr_t FUN_00d48d30(::S00d48d30_Stream *, ::S00d48d30_Result *, intptr_t);
