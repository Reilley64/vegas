#pragma once

namespace fnv_00ddd040 { struct S_P; }
namespace fnv_00ddd940 { struct TriangleShape; }
namespace fnv_00ddd940 { struct hkVector4; }
struct Hit;
struct NormalVector;
struct hkShapeInfoArrayW;
struct hkTransformW;
struct hkVector4;
struct hkVector4q;
struct hkpShapeCollectionW;

// 0x00ddd040
namespace fnv_00ddd040 { unsigned char *IsDotProductBelowThreshold(unsigned char *, ::fnv_00ddd040::S_P, ::fnv_00ddd040::S_P); }
// 0x00ddd0b0
::Hit FUN_00ddd0b0(const ::hkVector4 &, const ::hkVector4 &, int, const ::hkVector4 *, float *, float *);
// 0x00ddd5a0
void FUN_00ddd5a0(const float *, const float *, const float *);
// 0x00ddd620
void FUN_00ddd620(const ::NormalVector *, const ::NormalVector *, const ::NormalVector *, ::NormalVector *);
// 0x00ddd7e0
float FUN_00ddd7e0(const ::hkVector4q *, float *, float *);
// 0x00ddd940
namespace fnv_00ddd940 { void GenerateTrianglePlanes(::fnv_00ddd940::hkVector4 *, const ::fnv_00ddd940::TriangleShape *, float); }
// 0x00dddcd0
void FUN_00dddcd0(const ::hkTransformW &, ::hkpShapeCollectionW *, int, ::hkShapeInfoArrayW &, bool);
