#pragma once
#include <cstdint>

#include <cstdint>

struct ArcAngle;
struct ArcPoint3;
struct ArrayObj;
struct Elem12;
struct FUN_006d4ca0_Class;
struct ScrapHeapBuffer;
struct StackIdx;

// 0x006a1180
void FUN_006a1180(const ::ArcPoint3 &, float, const ::ArcAngle *, const ::ArcAngle *, int, int);
// 0x006a1330
void FUN_006a1330(const char *, std::intptr_t, std::intptr_t);
// 0x006a1440
::Elem12 &FUN_006a1440(::ArrayObj *, ::StackIdx);
// 0x006a1b00
void CallMethodOnObject(intptr_t, int);
// 0x006a1b80
unsigned char FUN_006a1b80(::FUN_006d4ca0_Class *, const ::FUN_006d4ca0_Class *);
// 0x006a1f90
void *FUN_006a1f90(unsigned int, ::ScrapHeapBuffer *);
