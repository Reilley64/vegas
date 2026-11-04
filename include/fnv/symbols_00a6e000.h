#pragma once

class NiAVObject;
class NiDefaultAVObjectPalette;
class NiQuaternion;
struct S_00a6e8e0_Object;
struct S_00a6e8e0_Palette;

// 0x00a6e430
void FUN_00a6e430(::NiQuaternion *, int, float, const ::NiQuaternion &, const ::NiQuaternion &, const ::NiQuaternion &, const ::NiQuaternion &);
// 0x00a6e550
void AssignSharedPtr(void *, void *, void *);
// 0x00a6e870
void AddObjectToPalette(::NiAVObject *, ::NiDefaultAVObjectPalette *);
// 0x00a6e8e0
void FUN_00a6e8e0(::S_00a6e8e0_Object *, ::S_00a6e8e0_Palette *);
