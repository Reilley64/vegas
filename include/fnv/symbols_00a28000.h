#pragma once

class A281E0BezPosKey;
class A281E0Stream;
class TimedRotationKey;
struct A28260Key;
struct A28F00Elem;
struct Blk36;
struct FNVAnim;
struct FUN_00a289b0_Vec4;
struct NiStream;
struct Obj_a28;
struct SpawnTarget;
struct Spl_a28060_Key;
struct TCBRotKeyS;
struct UHelper;
struct Vec4_b5508;

// 0x00a28060
float FUN_00a28060(::Spl_a28060_Key *, int);
// 0x00a281e0
::A281E0BezPosKey *LoadBezPosKeys(::A281E0Stream &, unsigned int);
// 0x00a28260
void SaveKeyArray(::NiStream &, ::A28260Key *, unsigned int);
// 0x00a28680
int FUN_00a28680();
// 0x00a286e0
void FUN_00a286e0(unsigned int, unsigned int, unsigned int, ::Vec4_b5508 *);
// 0x00a28720
void FUN_00a28720(void *, void *);
// 0x00a289b0
::FUN_00a289b0_Vec4 *SampleKeyedVec4(::FUN_00a289b0_Vec4 *, float, char *, void *, unsigned int, unsigned char);
// 0x00a28a80
bool FUN_00a28a80(::Obj_a28 *, ::Obj_a28 *);
// 0x00a28ab0
void FUN_00a28ab0(::TimedRotationKey *, unsigned int, unsigned char);
// 0x00a28cb0
int FUN_00a28cb0();
// 0x00a28d40
void CopyBlk36(::Blk36 *, const ::Blk36 *);
// 0x00a28d90
void CallSpawnTarget(float, char *, char *, ::SpawnTarget *);
// 0x00a28dc0
void FUN_00a28dc0(::FNVAnim *, unsigned int, unsigned int);
// 0x00a28ea0
bool CompareBounds(::UHelper *, ::UHelper *);
// 0x00a28ed0
namespace fnv_00a28ed0 { void FUN_00a28ed0(void *, char *, unsigned int); }
// 0x00a28f00
::A28F00Elem *FUN_00a28f00(unsigned int);
// 0x00a28f50
bool FUN_00a28f50(float, ::TCBRotKeyS *&, unsigned int &);
