#pragma once

namespace fnv_00a2d000 { struct QuatKey; }
namespace fnv_00a2d1d0 { struct FloatRecord_b5532; }
namespace fnv_00a2d260 { struct KeyPair8; }
namespace fnv_00a2d4a0 { struct InsertPositionKey; }
struct A2D6C0RotKey;
struct FNVAnim;
struct FUN_00a2d200_arg;
struct FUN_00a2d470_Entry;
struct Key415;
struct KeyData;
struct KeyOut;
struct Point415;
struct SObj;
struct SStream;
struct UHelper;

// 0x00a2d000
namespace fnv_00a2d000 { bool FUN_00a2d000(float, ::fnv_00a2d000::QuatKey **, unsigned int *); }
// 0x00a2d140
int FUN_00a2d140();
// 0x00a2d1d0
namespace fnv_00a2d1d0 { bool FUN_00a2d1d0(::fnv_00a2d1d0::FloatRecord_b5532 *, ::fnv_00a2d1d0::FloatRecord_b5532 *); }
// 0x00a2d1e0
void CopyFloat2(float *, const float *);
// 0x00a2d200
void FUN_00a2d200(float, ::FUN_00a2d200_arg *, ::FUN_00a2d200_arg *, float *);
// 0x00a2d230
void FUN_00a2d230(::SStream *, ::SObj *, unsigned int);
// 0x00a2d260
namespace fnv_00a2d260 { bool InsertKeyPair(float, ::fnv_00a2d260::KeyPair8 **, unsigned int *); }
// 0x00a2d360
int FUN_00a2d360();
// 0x00a2d3f0
void SelectKeyVec(float, const ::KeyData *, const ::KeyData *, ::KeyOut *);
// 0x00a2d420
void FUN_00a2d420(float, const ::Key415 &, const ::Key415 &, ::Point415 &);
// 0x00a2d470
void FUN_00a2d470(int, ::FUN_00a2d470_Entry *, unsigned int);
// 0x00a2d4a0
namespace fnv_00a2d4a0 { bool FUN_00a2d4a0(float, ::fnv_00a2d4a0::InsertPositionKey *&, unsigned int &); }
// 0x00a2d5b0
namespace fnv_00a2d5b0 { void FUN_00a2d5b0(int, int); }
// 0x00a2d610
int FUN_00a2d610();
// 0x00a2d670
void FUN_00a2d670(::FNVAnim *, unsigned int, unsigned int);
// 0x00a2d680
bool FUN_00a2d680(::UHelper *, ::UHelper *);
// 0x00a2d690
namespace fnv_00a2d690 { void FUN_00a2d690(void *, void *, unsigned int); }
// 0x00a2d6c0
bool FUN_00a2d6c0(float, ::A2D6C0RotKey *&, unsigned int &);
// 0x00a2d810
int FUN_00a2d810();
// 0x00a2d8a0
void FUN_00a2d8a0();
// 0x00a2de70
void ShutdownAnimationClasses();
