#pragma once

struct A290A0Key;
struct A290A0Stream;
struct A29FE0Block;
struct A29FE0Context;
struct AnimationKey;
struct CompareBlock;
struct Elem48;
struct Helper;
struct NiColorA_K;
struct NiColorKey_K;
struct Outer;
struct RgbaColor;
struct SObj;
struct SStream;

// 0x00a290a0
::A290A0Key *FUN_00a290a0(::A290A0Stream *, unsigned int);
// 0x00a29110
int FUN_00a29110();
// 0x00a291a0
bool FUN_00a291a0(const ::Helper *, const ::Helper *);
// 0x00a291d0
void StoreGlobalByte(int, int, int, unsigned char *);
// 0x00a291e0
float FUN_00a291e0();
// 0x00a29250
bool InterpolateBooleanKey(float, const ::AnimationKey *, unsigned int, unsigned int, unsigned int *, unsigned char);
// 0x00a29470
extern "C" unsigned char FUN_00a29470(float, const void *, int, unsigned int, unsigned char);
// 0x00a294f0
int FUN_00a294f0();
// 0x00a29550
int FUN_00a29550(int, int);
// 0x00a295f0
void WriteEnabledFlag(::SStream *, ::SObj *);
// 0x00a29660
void FUN_00a29660(void *, ::Outer *);
// 0x00a29680
void FUN_00a29680();
// 0x00a296c0
::RgbaColor InterpolateColor(float, const char *, unsigned int, unsigned int, unsigned int *, unsigned char);
// 0x00a298f0
::NiColorA_K FUN_00a298f0(float, ::NiColorKey_K *, unsigned int, unsigned int, unsigned char);
// 0x00a299c0
bool CompareHelpers(const ::Helper *, const ::Helper *);
// 0x00a299f0
int FUN_00a299f0();
// 0x00a29b10
void FUN_00a29b10(float, const void *, const void *, void *);
// 0x00a29c20
bool FUN_00a29c20(const void *, const ::CompareBlock *);
// 0x00a29cf0
void CopyKeyData(void *, void *);
// 0x00a29db0
::Elem48 *FUN_00a29db0(unsigned int);
// 0x00a29e00
namespace fnv_00a29e00 { void DispatchEntryCallbacks(void *); }
// 0x00a29e40
bool UpdateArrayElements(float, void **, int *);
// 0x00a29fe0
void ReadBlockEntries(::A29FE0Context *, ::A29FE0Block *);
