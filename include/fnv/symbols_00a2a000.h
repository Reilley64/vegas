#pragma once

#include <cstdint>

class A29F00Stream;
namespace fnv_00a2a5a0 { struct Elem; }
struct A2ABC0Stream;
struct A2AE90Light;
struct BezierKeyS;
struct ColorKey;
struct CopyBlk16;
struct FUN_00a2ab10_T;
struct FUN_00a6e330_StandIn;
struct LinPosKey;
struct LoadKey20;
struct LoadKey48;
struct NiColorKey_K;
struct Pt3;
struct Quaternion;
struct QuaternionKey;
struct S_00a2af70_P;
struct S_00a2af70_V;
struct S_a2c300_Stream;
struct TCBKeyS;
class TimedRotationKey;
struct VertexRecord;

// 0x00a2a070
::LoadKey48 *FUN_00a2a070(::A29F00Stream &, unsigned int);
// 0x00a2a0e0
void FUN_00a2a0e0(void *, void *, unsigned int);
// 0x00a2a110
int FUN_00a2a110();
// 0x00a2a1a0
void FUN_00a2a1a0(int, int);
// 0x00a2a1b0
::NiColorKey_K *FUN_00a2a1b0(unsigned int);
// 0x00a2a200
void InterpolateQuaternion(float, const ::QuaternionKey *, const ::QuaternionKey *, ::Quaternion *);
// 0x00a2a320
::LoadKey20 *FUN_00a2a320(::S_a2c300_Stream *, unsigned int);
// 0x00a2a390
bool FUN_00a2a390(float, ::TimedRotationKey *&, unsigned int &);
// 0x00a2a4d0
int FUN_00a2a4d0();
// 0x00a2a560
void FUN_00a2a560(float, const ::Pt3 *, const ::Pt3 *, float *);
// 0x00a2a5a0
namespace fnv_00a2a5a0 { ::fnv_00a2a5a0::Elem *CreateInitializedElems(std::intptr_t, unsigned int); }
// 0x00a2a600
void FUN_00a2a600(void *);
// 0x00a2a620
bool FUN_00a2a620(float, ::TCBKeyS **, unsigned int *);
// 0x00a2a720
int FUN_00a2a720();
// 0x00a2a7b0
void FUN_00a2a7b0(::CopyBlk16 *, const ::CopyBlk16 *);
// 0x00a2a7e0
bool FUN_00a2a7e0(void *, void *);
// 0x00a2a8e0
::VertexRecord *CreateVertexRecords(std::intptr_t, unsigned int);
// 0x00a2a940
bool InsertLinPosKey(float, ::LinPosKey **, unsigned int *);
// 0x00a2aa50
namespace fnv_00a2aa50 { void FUN_00a2aa50(int, int); }
// 0x00a2aab0
int FUN_00a2aab0();
// 0x00a2ab10
void FUN_00a2ab10(::FUN_00a2ab10_T *, const ::FUN_00a2ab10_T *);
// 0x00a2ab40
void *FUN_00a2ab40(unsigned int);
// 0x00a2ab90
void FUN_00a2ab90(float, const void *, const void *, ::FUN_00a6e330_StandIn *);
// 0x00a2abc0
void *FUN_00a2abc0(::A2ABC0Stream *, unsigned int);
// 0x00a2ac30
bool FUN_00a2ac30(float, ::ColorKey **, unsigned int *);
// 0x00a2ad80
int FUN_00a2ad80();
// 0x00a2ae10
void CopyFloatBlock(float *, const float *);
// 0x00a2ae90
bool IsLightEqual(::A2AE90Light *, ::A2AE90Light *);
// 0x00a2af30
::BezierKeyS *AllocateBezierKeys(unsigned int);
// 0x00a2af70
void FUN_00a2af70(float, ::S_00a2af70_P *, int, ::S_00a2af70_V *);
