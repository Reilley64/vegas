#pragma once

class A49B30Point3Interpolator;
class NiRotData;
namespace fnv_00a49d00 { struct TimedRotationKey; }
struct Derived;

// 0x00a49020
::Derived *FUN_00a49020();
// 0x00a49a30
::A49B30Point3Interpolator *FUN_00a49a30();
// 0x00a49d00
namespace fnv_00a49d00 { void GetRotKeyData(::NiRotData *, int, ::fnv_00a49d00::TimedRotationKey **, int *, int *, unsigned char *); }
