#pragma once

namespace fnv_00cde450 { struct S_00cde450_Graph; }
namespace fnv_00cde450 { struct S_00cde450_UShortArr; }
struct PoseBlend;
struct ScanObj;
struct ScanRec;
struct SkinXformEntry;
struct SkinXformSet;
struct Vec4f;
struct hkQsTransform;
struct hkaSkeleton;

// 0x00cde1d0
void FUN_00cde1d0(const ::hkaSkeleton *, ::hkQsTransform *);
// 0x00cde2d0
void FUN_00cde2d0(::SkinXformSet *, const ::SkinXformEntry *, ::SkinXformEntry *);
// 0x00cde3d0
unsigned char *WalkChainUntilLimit(unsigned char *, ::ScanRec *, short, short, ::ScanObj *);
// 0x00cde450
namespace fnv_00cde450 { void CollectReachableNodes(::fnv_00cde450::S_00cde450_Graph *, short, ::fnv_00cde450::S_00cde450_UShortArr *, bool); }
// 0x00cde740
void FUN_00cde740(const ::PoseBlend *, const ::PoseBlend *, const ::Vec4f *, ::PoseBlend *);
// 0x00cde9f0
void FUN_00cde9f0(void *, int, float);
// 0x00cdea70
void FUN_00cdea70(int);
// 0x00cdea90
void FUN_00cdea90(int);
// 0x00cdeab0
void FUN_00cdeab0(int);
