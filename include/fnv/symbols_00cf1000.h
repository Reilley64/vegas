#pragma once

namespace fnv_00cf1270 { struct BlobObject; }
namespace fnv_00cf1270 { struct BlobStream; }
namespace fnv_00cf1710 { struct hkSweptTransformL; }
namespace fnv_00cf1710 { struct hkTransformL; }
struct FUN_008cd6a0_Class;
struct S_00cf10f0_Arr4;
struct S_00cf10f0_Stream;
struct hkSweptTransformL;
struct hkTransformL;

// 0x00cf10f0
int LoadIntArray(::S_00cf10f0_Stream *, ::S_00cf10f0_Arr4 *);
// 0x00cf1270
namespace fnv_00cf1270 { int ReadBlobObject(::fnv_00cf1270::BlobStream *, ::fnv_00cf1270::BlobObject **); }
// 0x00cf1480
void FUN_00cf1480(float, float, int *);
// 0x00cf1510
void FUN_00cf1510(const ::hkSweptTransformL &, float, ::hkTransformL &);
// 0x00cf1710
namespace fnv_00cf1710 { void FUN_00cf1710(const ::fnv_00cf1710::hkSweptTransformL &, float, float, ::fnv_00cf1710::hkTransformL &); }
// 0x00cf1b10
void FUN_00cf1b10(float, ::FUN_008cd6a0_Class *);
// 0x00cf1d50
void UpdateRotationInterpolation(float, ::FUN_008cd6a0_Class *);
