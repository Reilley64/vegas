#pragma once
#include <cstdint>

class NiAVObject;
struct NiPick;
struct NiPoint3;
namespace fnv_004b2800 { struct NiPick; }
struct Color87;
struct FUN_004a7800;
struct Mesh87;
struct NiTriShape;
struct Vec87;

// 0x004b2780
bool FUN_004b2780(::NiPick *, intptr_t, intptr_t, float, intptr_t, bool);
// 0x004b2800
namespace fnv_004b2800 { bool PickObjectsInRadius(::fnv_004b2800::NiPick *, const ::NiPoint3 &, const ::NiPoint3 &, float, ::NiAVObject *); }
// 0x004b29b0
::NiTriShape *CreateOctahedron(float, const struct ::FUN_004a7800 *, bool);
// 0x004b2eb0
::Mesh87 *CreateBoxMesh(const ::Vec87 &, const ::Vec87 &, const ::Vec87 &, const ::Vec87 &, const ::Vec87 &, const ::Vec87 &, const ::Vec87 &, const ::Vec87 &, const ::Color87 &, bool);
