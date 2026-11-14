#pragma once
#include <cstdint>

class AnimationKey;
struct FloatRecord_b5532;
struct MyStream;
struct S00a26b40_Key;
struct SObj;
struct SStream;

// 0x00a26b00
bool AreRecordsEqual(::FloatRecord_b5532 *, ::FloatRecord_b5532 *);
// 0x00a26b40
float InterpolateKey(float, const ::S00a26b40_Key *, uintptr_t, unsigned int, unsigned int *, unsigned char);
// 0x00a26df0
void FUN_00a26df0(::MyStream *, void *);
// 0x00a26e20
int RegisterFloatKeyOps();
// 0x00a26ef0
void WriteFloatToStream(::SStream *, ::SObj *);
// 0x00a26f30
bool FUN_00a26f30(const ::AnimationKey &, const ::AnimationKey &);
// 0x00a26f80
void FUN_00a26f80(float *, const float *);
// 0x00a26fe0
void FUN_00a26fe0(float, const float *, const float *, float *);
