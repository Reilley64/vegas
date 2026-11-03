#pragma once
#include <cstdint>

class NiAVObject;
class NiPoint3;
struct FUN_0062bc10_obj;
struct MaterialSelector;
struct NiAVObject;
struct Node;
struct Object62BAE0;
struct Point3;
struct Point62BAE0;
struct SceneNode;
struct TESObjectREFR;
struct Vec3Arg;
struct WorldObject62b3;
struct bhkWorldObject;

// 0x0062b150
unsigned int FUN_0062b150(uintptr_t, uintptr_t);
// 0x0062b310
float GetObjectMass(::WorldObject62b3 *);
// 0x0062b4e0
::TESObjectREFR *FUN_0062b4e0(void *);
// 0x0062b520
float FUN_0062b520(float, ::bhkWorldObject *, bool);
// 0x0062b660
void SetCollisionScale(::SceneNode *, unsigned int, float, ::MaterialSelector *);
// 0x0062b8d0
void FUN_0062b8d0(void *, const void *, unsigned char);
// 0x0062b930
void FUN_0062b930(::NiAVObject *, ::Vec3Arg *, bool);
// 0x0062ba80
void FUN_0062ba80(void *, const ::NiPoint3 &, bool);
// 0x0062bae0
void FUN_0062bae0(::Object62BAE0 *, ::Point62BAE0 *, bool);
// 0x0062bc10
void FUN_0062bc10(::FUN_0062bc10_obj *);
// 0x0062bd00
void CountCollisionShapes(::NiAVObject *, unsigned int *, unsigned int *);
// 0x0062be90
float ComputeDistanceFactor(float, float);
// 0x0062bfb0
::Point3 *FUN_0062bfb0(::Point3 *, ::Node *);
