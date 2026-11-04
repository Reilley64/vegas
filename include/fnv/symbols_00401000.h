#pragma once
#include <cstdint>

class MemoryManager;
struct BGSDehydrationStage;

// 0x00401000
void *FUN_00401000(unsigned int);
// 0x00401020
::MemoryManager *FUN_00401020();
// 0x00401030
void FUN_00401030(void *);
// 0x00401080
void FUN_00401080(int *);
// 0x00401460
void *__memcpy(void *, const void *, unsigned int);
// 0x00401500
unsigned char FUN_00401500();
// 0x004016a0
void FUN_004016a0(::BGSDehydrationStage *);
// 0x004019a0
unsigned long WaitForSingleObjectEx(long *);
// 0x004019b0
float FUN_004019b0(float);
// 0x004019d0
float ConvertDoubleResult(float);
