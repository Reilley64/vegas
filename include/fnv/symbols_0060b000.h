#pragma once
#include <cstdint>

struct C60BE00Allocator;
struct C60BE00Element;

// 0x0060bb70
void FUN_0060bb70(int, int, const float *);
// 0x0060bba0
void FUN_0060bba0(int, int, intptr_t);
// 0x0060bc10
void FillRange(void *, void *, void *, void *);
// 0x0060be00
void FUN_0060be00(::C60BE00Element *, ::C60BE00Element *, ::C60BE00Element *, ::C60BE00Allocator *);
// 0x0060be80
void CallWithFlagByte(void *, void *, void *, unsigned char);
// 0x0060bed0
void FUN_0060bed0(void *, void *, void *);
