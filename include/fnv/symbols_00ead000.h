#pragma once

namespace sead090 { struct Node; }
struct BoundedObject;
struct FadeNodeEntry;
struct Vector3;

// 0x00ead090
namespace sead090 { ::sead090::Node *FUN_00ead090(); }
// 0x00ead0d0
::FadeNodeEntry *FUN_00ead0d0(::FadeNodeEntry *);
// 0x00eada70
bool RayIntersectsBound(::BoundedObject *, const ::Vector3 &, const ::Vector3 &);
