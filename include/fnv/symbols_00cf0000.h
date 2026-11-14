#pragma once

#include <cstdint>

class CF4BC0Stream;
struct ArrayData;
struct Dest;
struct FUN_00cf08c0_VectorArray;
struct LinkedEntry;
struct Record;
struct S00cf0690_Mass;
struct S00cf0cf0_Arr;
struct S00cf0cf0_Obj;
struct S00cf0f40_Arr;
struct S00cf0f40_Owner;
struct StreamOwner;
struct StreamViewCF0;
struct TargetType;
struct Vector3;
struct hkMatrixCF0;

// 0x00cf0690
void FUN_00cf0690(void *, float, ::S00cf0690_Mass *);
// 0x00cf07a0
void FUN_00cf07a0(void *, float, ::Dest *);
// 0x00cf0860
int CollectValuesReversed(int *, int, ::LinkedEntry *);
// 0x00cf08c0
bool FUN_00cf08c0(const ::FUN_00cf08c0_VectorArray *, const ::FUN_00cf08c0_VectorArray *);
// 0x00cf0930
void FUN_00cf0930(void *, std::intptr_t, ::Vector3 *);
// 0x00cf09a0
void FUN_00cf09a0(::StreamOwner *, ::Record *);
// 0x00cf0b00
void FUN_00cf0b00(::StreamViewCF0 *, ::hkMatrixCF0 *);
// 0x00cf0cf0
int FUN_00cf0cf0(::S00cf0cf0_Obj *, ::S00cf0cf0_Arr *);
// 0x00cf0dc0
unsigned int FUN_00cf0dc0(::CF4BC0Stream &, ::TargetType *);
// 0x00cf0e90
extern "C" unsigned int SaveUIntArray(::CF4BC0Stream &, const ::ArrayData &);
// 0x00cf0f40
unsigned int FUN_00cf0f40(::S00cf0f40_Owner *, ::S00cf0f40_Arr *);
