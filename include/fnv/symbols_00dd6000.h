#pragma once
#include <cstdint>

struct Arg;
struct Contact;
struct PlaneSet;
struct PointResult;
struct S00dd6380_PlaneSet;
struct S00dd6380_PointResult;
struct hkBool;
struct hkVector4;
template <class> struct hkArray;

// 0x00dd6270
int ProcessArg(::Arg *, intptr_t);
// 0x00dd6380
int FUN_00dd6380(::S00dd6380_PlaneSet *, int, int, int, ::S00dd6380_PointResult *);
// 0x00dd6510
int FUN_00dd6510(const ::hkVector4 *, ::PlaneSet *, int, int, ::PointResult *, ::PointResult *);
// 0x00dd66d0
::hkBool FUN_00dd66d0(const ::hkVector4 *, ::hkArray< ::hkVector4> *, int, int, ::hkVector4 *, ::hkArray< ::Contact> *);
// 0x00dd6ea0
unsigned char *LessThan(unsigned char *, const unsigned int *, const unsigned int *);
