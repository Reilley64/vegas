#pragma once

class NiPoint2;
struct Obj3;
struct ObjA4;
struct RTItem;
struct RTKey;
struct Vec3;
struct Vec4;

// 0x00b596a0
int GetOrCreateItem(::RTKey *, unsigned int, ::RTItem **);
// 0x00b59890
void ClearMap();
// 0x00b59940
void ClearCachedEntryMap();
// 0x00b59ae0
void FUN_00b59ae0(void *, unsigned int, ::Obj3 *, ::ObjA4 *, ::Vec3 *, float *, unsigned short);
// 0x00b59d30
::NiPoint2 *FUN_00b59d30(::Vec4 *, ::NiPoint2 *, float *);
