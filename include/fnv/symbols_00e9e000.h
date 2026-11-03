#pragma once

class SweepPlane;
class SweepPoint;
struct E9EB60_Item;
struct FNVItemHolder;
struct ItemArrayOwner;
struct MatchList;
struct NiBoundingVolume;
struct Seq9ea;
struct ShaderObj;

// 0x00e9e2c0
bool FUN_00e9e2c0(float, const ::SweepPlane &, const ::SweepPoint &, const ::SweepPoint &, const ::SweepPoint &, const ::SweepPoint &, const ::SweepPoint &, float &, ::SweepPoint &, bool, ::SweepPoint &, ::SweepPoint &);
// 0x00e9e780
::NiBoundingVolume *CreateBoundingVolumeAndCall(void *);
// 0x00e9e9e0
bool FindMatchingItemPair(float, ::ItemArrayOwner *, unsigned int, ::ItemArrayOwner *, unsigned int);
// 0x00e9ea70
bool FUN_00e9ea70(float, ::Seq9ea *, void *, void *, void *, void *, void *);
// 0x00e9eae0
bool FindItemByPredicate(float, ::FNVItemHolder *, int, int, int, int, int, int, int, int);
// 0x00e9eb60
bool FindMatchingPair(float, ::E9EB60_Item *, int, ::E9EB60_Item *, int, int, int, int, int, int);
// 0x00e9ec10
bool FUN_00e9ec10(float, ::MatchList *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
// 0x00e9efe0
::ShaderObj *FUN_00e9efe0(unsigned int);
