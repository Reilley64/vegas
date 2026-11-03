#pragma once

struct BufferPair;
struct DrawParams;
struct S9d950_Box;
struct S9d950_Owner;
struct S_00d9dab0_Aabb16;
struct S_00d9dab0_Coll;

// 0x00d9d800
namespace fnv_00d9d800 { void GetAudioPair(int *, int); }
// 0x00d9d840
void FreeBufferPair(::BufferPair *, int);
// 0x00d9d880
void MixChannels(void *, int *, intptr_t, int, int, int, int *);
// 0x00d9d950
void FUN_00d9d950(::S9d950_Owner *, int, const ::S9d950_Box *, const int *);
// 0x00d9dab0
void FillAabbArray(::S_00d9dab0_Coll *, int, int, ::S_00d9dab0_Aabb16 *);
// 0x00d9db30
void DrawIfCountPositive(void *, ::DrawParams *);
