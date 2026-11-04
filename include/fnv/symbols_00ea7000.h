#pragma once

class SweepPoint;
namespace fnv_00ea7530 { struct BoxBVStub; }
namespace fnv_00ea7530 { struct SphereBVStub; }
namespace fnv_00ea7530 { struct Vec3; }
struct CollisionBox;
struct NiBoundingVolume;
struct Pt3;
struct SweepBox;

// 0x00ea7490
::NiBoundingVolume *FUN_00ea7490(void *);
// 0x00ea7530
namespace fnv_00ea7530 { bool IntersectsSphereAndBox(float, const ::fnv_00ea7530::BoxBVStub &, const ::fnv_00ea7530::Vec3 &, const ::fnv_00ea7530::SphereBVStub &, const ::fnv_00ea7530::Vec3 &); }
// 0x00ea7730
void ClampPositionToBoxes(float, const ::CollisionBox *, const ::Pt3 *, const ::CollisionBox *, const ::Pt3 *, const float *, ::Pt3 *);
// 0x00ea7d40
bool FUN_00ea7d40(float, const ::SweepBox &, const ::SweepPoint &, const ::SweepBox &, const ::SweepPoint &, float &, ::SweepPoint &, bool, ::SweepPoint &, ::SweepPoint &);
