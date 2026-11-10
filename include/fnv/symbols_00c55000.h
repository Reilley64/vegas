#pragma once

struct NiPoint3;
class NiTriShape;
namespace fnv_00c55170 { struct AvCaller; }
struct BoxColor;
struct C55010Obj;
struct CollisionShape;
struct FilterData;
struct NiExtraDataX;
struct Point3;

// 0x00c55010
::C55010Obj *FUN_00c55010();
// 0x00c55170
namespace fnv_00c55170 { ::NiExtraDataX *FUN_00c55170(::fnv_00c55170::AvCaller *); }
// 0x00c55920
::NiTriShape *FUN_00c55920(const ::NiPoint3 &, const ::BoxColor *);
// 0x00c55d50
::CollisionShape *FUN_00c55d50(::Point3 *, ::Point3 *, float, float, float, float, ::FilterData *, ::FilterData *);
