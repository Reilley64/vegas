#pragma once

class NiAVObject;
class NiPoint2;
class TESImageSpaceModifier;
struct SpawnedObject;

// 0x00532220
void BlendImageSpaceModifiers(float, ::TESImageSpaceModifier *, ::TESImageSpaceModifier *, float, float, ::NiAVObject *, ::NiAVObject *);
// 0x00532f40
float *FUN_00532f40(float *, float, ::SpawnedObject *);
// 0x00532fd0
::NiPoint2 operator*(float, const ::NiPoint2 &);
// 0x00532ff0
::TESImageSpaceModifier *GetDefaultImageSpaceModifier();
