#pragma once

namespace fnv_009a8600 { struct NiPoint3; }
namespace fnv_009a8600 { class TESObjectREFR; }
namespace fnv_009a86e0 { class TESObjectREFR; }
namespace fnv_009a86e0 { struct NiPoint3Ex; }
namespace fnv_009a8d80 { struct S_009a8d80_Obj; }
namespace fnv_009a8d80 { struct S_009a8d80_P3; }
namespace s9a8050 { class Actor; }
namespace s9a8050 { struct NiPoint3; }
struct AimPoint;
struct BGSProjectile;
struct FUN_009a7f00_obj;
struct FUN_009a8df0_vec;
struct NiPoint3;
struct Point3A8AF0;
struct S_009a6d70_Actor;
struct S_009a6d70_Point;
struct S_009a82b0_Point3;
struct S_009a82b0_Ref;
struct S_009a8460_Actor;
class TESObjectREFR;
struct TrajActor;
struct TrajOut;
struct TrajRef;
struct Triple12;
struct Vec3;

// 0x009a8050
namespace s9a8050 { ::s9a8050::NiPoint3 FUN_009a8050(::s9a8050::Actor *); }
// 0x009a8250
::NiPoint3 FUN_009a8250(::TESObjectREFR *);
// 0x009a82b0
::S_009a82b0_Point3 GetAdjustedPosition(::S_009a82b0_Ref *);
// 0x009a8460
float FUN_009a8460(::S_009a8460_Actor *, int, bool);
// 0x009a8600
namespace fnv_009a8600 { ::fnv_009a8600::NiPoint3 GetTargetLocationWithOffset(::fnv_009a8600::TESObjectREFR *, int); }
// 0x009a8660
::Triple12 *GetTriple12(::Triple12 *, void *);
// 0x009a86e0
namespace fnv_009a86e0 { ::fnv_009a86e0::NiPoint3Ex ComputeRelativeFiringAngle(::fnv_009a86e0::TESObjectREFR *, ::fnv_009a86e0::TESObjectREFR *, float, float, int); }
// 0x009a87f0
::Vec3 *FUN_009a87f0(::Vec3 *, ::Vec3, const void *, float, float, int);
// 0x009a88e0
::S_009a6d70_Point FUN_009a88e0(::S_009a6d70_Actor *, ::NiPoint3);
// 0x009a8970
::NiPoint3 *FUN_009a8970(::NiPoint3 *, ::NiPoint3, ::NiPoint3, float, ::NiPoint3);
// 0x009a8af0
::Point3A8AF0 GetPitchYaw(::Point3A8AF0, ::Point3A8AF0);
// 0x009a8bf0
::TrajOut *ComputeTrajectory(::TrajOut *, ::TrajRef *, void *, void *, ::TrajActor *, float, bool);
// 0x009a8d80
namespace fnv_009a8d80 { ::fnv_009a8d80::S_009a8d80_P3 FUN_009a8d80(::TESObjectREFR *, const ::fnv_009a8d80::S_009a8d80_P3 *, ::fnv_009a8d80::S_009a8d80_Obj *, ::BGSProjectile *, float, bool); }
// 0x009a8df0
::FUN_009a8df0_vec *FUN_009a8df0(::FUN_009a8df0_vec *, int, ::FUN_009a8df0_vec, ::FUN_009a8df0_vec, ::FUN_009a8df0_vec *, ::FUN_009a7f00_obj *, float, unsigned char);
// 0x009a8f00
::AimPoint FUN_009a8f00(::AimPoint, ::AimPoint, ::AimPoint, float, float, bool);
