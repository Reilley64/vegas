#pragma once
#include <cstdint>

namespace fnv_00ce55d0 { struct ScaleParams; }
namespace fnv_00ce55d0 { struct hkQsTransformq; }
namespace fnv_00ce5e60 { struct hkQsTransformq; }
namespace fnv_00ce5e60 { struct hkaSkeletonq; }
namespace fnv_00ce5e60 { union hkVector4q; }
namespace fnv_00ce5fe0 { struct BonePairInfo; }
namespace fnv_00ce5fe0 { struct hkQsTransform; }
namespace fnv_00ce5fe0 { struct hkaSkeleton; }
struct CE5F90QsTransform;

// 0x00ce5300
void FUN_00ce5300();
// 0x00ce55d0
namespace fnv_00ce55d0 { void FUN_00ce55d0(const ::fnv_00ce55d0::ScaleParams *, int, const ::fnv_00ce55d0::hkQsTransformq *, int, const ::fnv_00ce55d0::hkQsTransformq *, int, ::fnv_00ce55d0::hkQsTransformq *, ::fnv_00ce55d0::hkQsTransformq *); }
// 0x00ce5a70
namespace fnv_00ce5a70 { void FUN_00ce5a70(::CE5F90QsTransform *, const ::CE5F90QsTransform *, const ::CE5F90QsTransform *, intptr_t, float, float); }
// 0x00ce5e60
namespace fnv_00ce5e60 { void FUN_00ce5e60(const ::fnv_00ce5e60::hkaSkeletonq *, const ::fnv_00ce5e60::hkQsTransformq *, short, short, float *, ::fnv_00ce5e60::hkVector4q *); }
// 0x00ce5f90
void FUN_00ce5f90(::CE5F90QsTransform *, const ::CE5F90QsTransform *, short, const ::CE5F90QsTransform *, short, intptr_t, float, float);
// 0x00ce5fe0
namespace fnv_00ce5fe0 { void FUN_00ce5fe0(const void *, const ::fnv_00ce5fe0::hkaSkeleton *, const ::fnv_00ce5fe0::hkQsTransform *, short, short, const ::fnv_00ce5fe0::hkaSkeleton *, const ::fnv_00ce5fe0::hkQsTransform *, short, short, ::fnv_00ce5fe0::BonePairInfo *); }
