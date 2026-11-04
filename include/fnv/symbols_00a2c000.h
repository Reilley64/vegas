#pragma once

namespace fnv_00a2c420 { struct FUN_00a2bdb0; }
namespace fnv_00a2cdc0 { struct BooleanKey; }
namespace fnv_00a2cdc0 { struct NiStream; }
struct A2C550Key;
struct A2CC60Entry;
struct A2CC60Stream;
struct A2CF60Elem;
struct BoolKeyS;
struct Entry64;
struct FUN_00a2bdb0;
struct FUN_00a2ca60_Obj;
struct FUN_00a2cc10_T;
struct FUN_00a2cc40_S;
struct FUN_00a2cf20_Payload;
struct FUN_00a2cf20_Value;
struct Key;
struct KeyframeElement;
struct NiStreamStandInW;
struct Quad64;
struct S_a2c300_Stream;
struct S_a2c390_Obj;
struct S_a2c390_Stream;
struct ScalarKeyA2;
struct ShapeValues;

// 0x00a2c130
void FUN_00a2c130(::Quad64 *, unsigned int, void *);
// 0x00a2c1b0
bool FUN_00a2c1b0(float, ::FUN_00a2bdb0 **, unsigned int *);
// 0x00a2c390
void LoadObjFields(::S_a2c390_Stream *, ::S_a2c390_Obj *);
// 0x00a2c420
namespace fnv_00a2c420 { ::fnv_00a2c420::FUN_00a2bdb0 *FUN_00a2c420(::S_a2c300_Stream *, unsigned int); }
// 0x00a2c490
void FUN_00a2c490(void *, ::Entry64 *, unsigned int);
// 0x00a2c4c0
int FUN_00a2c4c0();
// 0x00a2c550
bool FUN_00a2c550(const ::A2C550Key &, const ::A2C550Key &);
// 0x00a2c5d0
void CopyFloat7(float *, const float *);
// 0x00a2c610
void FUN_00a2c610(float, const ::ShapeValues *, const ::ShapeValues *, float *);
// 0x00a2c660
namespace fnv_00a2c660 { void *AllocateElem28Array(unsigned int); }
// 0x00a2c6a0
void FUN_00a2c6a0(::Key *, float, float, float, float);
// 0x00a2c7a0
void FUN_00a2c7a0(::Key *, unsigned int);
// 0x00a2c890
bool FUN_00a2c890(float, ::ScalarKeyA2 **, unsigned int *);
// 0x00a2ca60
void FUN_00a2ca60(::NiStreamStandInW *, ::FUN_00a2ca60_Obj *);
// 0x00a2caf0
::KeyframeElement *AllocateKeyframeElements(void *, unsigned int);
// 0x00a2cb50
void FUN_00a2cb50(void *, void *, unsigned int);
// 0x00a2cb80
int FUN_00a2cb80();
// 0x00a2cc10
void FUN_00a2cc10(::FUN_00a2cc10_T *, const ::FUN_00a2cc10_T *);
// 0x00a2cc30
bool FUN_00a2cc30(int, int);
// 0x00a2cc40
void SelectByteByThreshold(float, ::FUN_00a2cc40_S *, ::FUN_00a2cc40_S *, unsigned char *);
// 0x00a2cc60
void FUN_00a2cc60(::A2CC60Stream *, ::A2CC60Entry *, unsigned int);
// 0x00a2cc90
void *AllocateArr8Array(unsigned int);
// 0x00a2ccd0
bool FUN_00a2ccd0(float, ::BoolKeyS *&, unsigned int &);
// 0x00a2cdc0
namespace fnv_00a2cdc0 { ::fnv_00a2cdc0::BooleanKey *FUN_00a2cdc0(::fnv_00a2cdc0::NiStream &, unsigned int); }
// 0x00a2ce20
int FUN_00a2ce20();
// 0x00a2ced0
void *FUN_00a2ced0(unsigned int);
// 0x00a2cf20
void SelectPayloadByThreshold(float, ::FUN_00a2cf20_Value *, ::FUN_00a2cf20_Value *, ::FUN_00a2cf20_Payload *);
// 0x00a2cf60
::A2CF60Elem *FUN_00a2cf60(void *, unsigned int);
// 0x00a2cfd0
void FUN_00a2cfd0(void *, const unsigned char *, unsigned int);
