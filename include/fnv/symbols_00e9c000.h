#pragma once

class FUN_00e9c8c0_obj;
class FUN_00e9c950_cls_key;
namespace fnv_00e9c6f0 { struct ItemOwner; }
namespace fnv_00e9c6f0 { struct SpawnParam; }
namespace fnv_00e9cde0 { struct BVBase; }
namespace fnv_00e9cde0 { struct Vec3; }
struct DispatchObj_b4010;
struct FUN_00e9ca50_Object;
struct HalfSpace;
struct ItemOwner;
struct NiBoundingVolume;
struct PA;
struct PB;
struct S_00e9c490_Ctx;
struct S_00e9c490_Node;
struct S_00e9c490_Pt;
struct SpawnParam;
struct Sphere;
struct V3;
struct Vec3;
struct e9Obj;

// 0x00e9c490
bool FUN_00e9c490(::S_00e9c490_Pt *, ::S_00e9c490_Pt *, ::S_00e9c490_Ctx *, ::S_00e9c490_Node *);
// 0x00e9c680
bool FUN_00e9c680(int, int, ::SpawnParam *, ::ItemOwner *);
// 0x00e9c6f0
namespace fnv_00e9c6f0 { bool FUN_00e9c6f0(int, int, ::fnv_00e9c6f0::SpawnParam *, ::fnv_00e9c6f0::ItemOwner *); }
// 0x00e9c850
::NiBoundingVolume *FUN_00e9c850(unsigned int, int *);
// 0x00e9c8c0
bool CallConditionFunction(float, ::FUN_00e9c8c0_obj *, unsigned int, ::FUN_00e9c8c0_obj *, unsigned int);
// 0x00e9c950
int DispatchPairHandler(float, ::FUN_00e9c950_cls_key *, int, ::FUN_00e9c950_cls_key *, int, int, int, int, int, int);
// 0x00e9ca10
void DispatchByVirtualIndex(float, ::DispatchObj_b4010 *, int, int, int, int, int);
// 0x00e9ca50
void FUN_00e9ca50(float, ::FUN_00e9ca50_Object *, int, int, int, int, int, int, int, int, int, int);
// 0x00e9cab0
unsigned int FUN_00e9cab0(::e9Obj *);
// 0x00e9cd10
bool FUN_00e9cd10(float, ::HalfSpace *, ::Vec3 *, ::Sphere *, ::Vec3 *);
// 0x00e9cde0
namespace fnv_00e9cde0 { bool IsIntersectingFogPlane(float, const ::fnv_00e9cde0::BVBase &, const ::fnv_00e9cde0::Vec3 &, const ::fnv_00e9cde0::BVBase &, const ::fnv_00e9cde0::Vec3 &); }
// 0x00e9cf50
bool FUN_00e9cf50(float, ::PA *, ::V3 *, ::PB *, ::V3 *);
