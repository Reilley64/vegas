#pragma once

class FnvHolder;
namespace fnv_00c66320 { union __m128; }
namespace fnv_00cb94a0 { struct MyHost; }
namespace fnv_00dd62e0 { struct VectorArray; }
namespace fnv_00dd62e0 { union __m128; }
namespace fnv_00e2ab00 { union __m128; }
struct AvgSrc;
struct BodyPair;
struct ClosestPointResult;
struct CompressedTree;
struct D986Result;
struct E29Out1;
struct E29Out2;
struct E29SrcList;
struct FNVPair8;
struct FNVVec16;
struct FUN_00dcedd0_Record;
struct Jacobian409;
struct LeafCollector;
struct MetaEntry;
struct MyPoint;
struct Obj;
struct ObjF;
struct Obj_t;
struct Out;
struct SweepOut;
struct Owner;
struct Pair409;
struct PivotPair;
struct QueryInput;
struct RayBatch;
struct SegCtx;
struct VecNode;
struct Vector4f;
struct VertexRecord;

// 0x00c66320
namespace fnv_00c66320 { void FUN_00c66320(::fnv_00c66320::__m128 *, void *, const ::fnv_00c66320::__m128 *, const ::fnv_00c66320::__m128 *); }
// 0x00c6ccc0
extern "C" void SubtractScalarFloat(::__m128 *, const ::__m128 *, const ::__m128 *);
// 0x00c6cce0
extern "C" void AddScalarFloat(::__m128 *, const ::__m128 *, const ::__m128 *);
// 0x00c8e940
void GetScalarAndVector(void *, ::__m128 *, float *);
// 0x00cac890
void FUN_00cac890(::VecNode *, int, const ::__m128 *);
// 0x00cb94a0
namespace fnv_00cb94a0 { void FUN_00cb94a0(::fnv_00cb94a0::MyHost *, const ::__m128 *, float); }
// 0x00cd72a0
void ComputeInverseLengths(::__m128 *, float *);
// 0x00ce01c0
void FUN_00ce01c0(::__m128 *);
// 0x00ce2ca0
void FUN_00ce2ca0(void *, ::__m128 *, const ::__m128 *, const ::__m128 *);
// 0x00ce5560
void FUN_00ce5560(const ::VertexRecord *, int, ::__m128 *, ::__m128 *);
// 0x00cec7f0
void FUN_00cec7f0(const ::__m128 *, volatile int, ::__m128 *, ::__m128 *);
// 0x00cf14a0
void ApplyDelta(::__m128 *, ::Obj *);
// 0x00cf1f80
void FUN_00cf1f80(const ::__m128 &, const ::__m128 &, ::Obj_t *);
// 0x00d1bd00
void FUN_00d1bd00(::CompressedTree *, const ::__m128 *, const ::__m128 *, ::LeafCollector *, float);
// 0x00d21f10
void SetGlobalVectors(int, int, const ::__m128 *, int, const ::__m128 *);
// 0x00d231b0
int FUN_00d231b0(const ::__m128 *, const ::__m128 *, const ::__m128 *, const ::__m128 *, ::ClosestPointResult *);
// 0x00d39150
void FUN_00d39150(::BodyPair *, void *, ::QueryInput *, ::__m128 *);
// 0x00d5beb0
::__m128 *FUN_00d5beb0(::__m128 *, ::MyPoint *, int, int, float);
// 0x00d679c0
int FUN_00d679c0(const ::__m128 *);
// 0x00d6c970
void FUN_00d6c970(::PivotPair, ::SegCtx *, ::__m128 *);
// 0x00d6cd70
void FUN_00d6cd70(const ::__m128 &, const ::Pair409 &, ::Jacobian409 &, float &);
// 0x00d74c70
void FUN_00d74c70(const ::__m128 *, float, float *);
// 0x00d975d0
unsigned int PackFloatsToUInt(const ::__m128 *);
// 0x00d98630
::D986Result FUN_00d98630(const ::__m128 *, const ::__m128 *, int);
// 0x00db4ca0
float FUN_00db4ca0(void *, const float *, const ::__m128 *, float, float, float, float, int, ::SweepOut *);
// 0x00dced90
namespace fnv_00dced90 { void FUN_00dced90(const ::__m128 *, const ::__m128 *, char **); }
// 0x00dcedd0
void FUN_00dcedd0(const ::__m128 *, unsigned int, ::FUN_00dcedd0_Record **);
// 0x00dcee10
void WriteVector(::__m128 *, ::__m128 *, ::__m128 **);
// 0x00dd62e0
namespace fnv_00dd62e0 { void FUN_00dd62e0(::fnv_00dd62e0::VectorArray *, int, int, int, ::fnv_00dd62e0::__m128 *); }
// 0x00ddd6f0
int FUN_00ddd6f0(const ::__m128 *, const ::__m128 *, int, ::__m128 *, int *);
// 0x00df0870
void FUN_00df0870(int, ::ObjF *__restrict, unsigned char *, ::__m128 *, void **);
// 0x00df32d0
void FUN_00df32d0(::MetaEntry *, ::Vector4f *, ::__m128 *, unsigned int, unsigned int);
// 0x00df3330
int FUN_00df3330(::FNVPair8 *, ::FNVVec16 *, ::__m128 *, unsigned int, unsigned int, int);
// 0x00df5d20
::__m128 *FUN_00df5d20(::__m128 *, const ::__m128 *, ::__m128 *, ::__m128 *);
// 0x00e29380
void FUN_00e29380(::__m128 *, const ::__m128 *);
// 0x00e29510
void FUN_00e29510(::__m128 *, const ::__m128 *, const ::__m128 *);
// 0x00e29a10
void FUN_00e29a10(::E29SrcList *, const ::__m128 *, const ::__m128 *, char *, ::E29Out1 *, int *, ::E29Out2 *, int *);
// 0x00e2ab00
namespace fnv_00e2ab00 { ::__m128 *FUN_00e2ab00(::__m128 *, ::__m128 *, ::__m128 *); }
// 0x00e2b510
void FUN_00e2b510(::Owner *, ::RayBatch *, int, ::__m128 &);
// 0x00e31180
void FUN_00e31180(const float *, int, int, int, int, ::__m128 **);
// 0x00e31410
::__m128 *FUN_00e31410(::__m128 *, ::AvgSrc *);
// 0x00e5ad40
int FUN_00e5ad40(::FnvHolder *, ::__m128 *, ::__m128 *);
// 0x01017d10
extern const ::__m128 DAT_01017d10;
// 0x010c44d0
extern const ::__m128 DAT_010c44d0;
// 0x010c4c00
extern ::__m128 DAT_010c4c00;
// 0x010c4c10
extern ::__m128 DAT_010c4c10;
// 0x010c7160
extern ::__m128 DAT_010c7160;
// 0x010c7170
extern ::__m128 DAT_010c7170;
// 0x010c7190
extern const ::__m128 DAT_010c7190;
// 0x010c71b0
extern const ::__m128 DAT_010c71b0;
// 0x010c71c0
extern ::__m128 DAT_010c71c0;
// 0x010c71d0
extern ::__m128 DAT_010c71d0;
// 0x010c71e0
extern const ::__m128 DAT_010c71e0;
// 0x010c7200
extern ::__m128 DAT_010c7200;
// 0x010cbfc0
extern ::__m128 DAT_010cbfc0;
// 0x010cd670
extern ::__m128 DAT_010cd670;
// 0x010ce1c0
extern ::__m128 DAT_010ce1c0;
// 0x010d3da0
extern const ::__m128 DAT_010d3da0;
// 0x010ec7b0
extern const ::__m128 C14;
// 0x010ec7f0
extern "C" extern const ::__m128 DAT_010ec7f0;
// 0x010ec810
extern const ::__m128 C17;
// 0x011b6d70
extern const ::__m128 DAT_011b6d70;
// 0x01268380
extern ::__m128 DAT_01268380;
// 0x01268390
extern ::__m128 DAT_01268390;
// 0x01268460
extern "C" extern __m128 DAT_01268460[];
