#pragma once
#include <cstdint>

struct Point4;
struct hkVector4;

// 0x00e33030
void DecodeSplineFrames(int *, int, int, int, int, void *);
// 0x00e33960
namespace fnv_00e33960 { void DecodeSplineFrame(const unsigned char **, int, float, float, unsigned char, intptr_t, ::hkVector4 *); }
// 0x00e33a30
void FUN_00e33a30(const unsigned char *&, int, float, float, unsigned int, int, ::Point4 *, intptr_t);
