#pragma once

namespace fnv_00a744d0 { struct NiTriStrips; }
struct A74CB0Matrix3;
struct A74CB0Point3;
struct SceneFactoryObject;
struct Vec3Local;
struct XfRSLocal;

// 0x00a74230
void *FUN_00a74230();
// 0x00a744c0
void FUN_00a744c0();
// 0x00a744d0
namespace fnv_00a744d0 { ::fnv_00a744d0::NiTriStrips *CreateNiTriShapeX(); }
// 0x00a74500
void FUN_00a74500();
// 0x00a74750
::SceneFactoryObject *CreateSceneFactoryObject();
// 0x00a74880
void FUN_00a74880(unsigned short, const float *, float *, const float *);
// 0x00a74900
void FUN_00a74900(unsigned short, const ::Vec3Local *, ::Vec3Local *, const ::XfRSLocal *);
// 0x00a74bc0
void FUN_00a74bc0(unsigned short, ::Vec3Local *, ::Vec3Local *, ::XfRSLocal *);
// 0x00a74cb0
void FUN_00a74cb0(unsigned short, const ::A74CB0Point3 *, ::A74CB0Point3 *, const ::A74CB0Matrix3 *);
// 0x00a74d90
void FUN_00a74d90(void *);
