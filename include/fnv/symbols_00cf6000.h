#pragma once

namespace fnv_00cf6080 { struct S_00cf6080_Listener; }
struct CF63C0Class;
struct CF63C0Writer;
struct Container;
struct Destination;
struct FNV_C60d0_Sink;
struct FNV_C60d0_Walker;
struct FNV_Cf62b0_Obj;
struct FUN_00cf6980_class;
struct FUN_00d46f70_Obj;
struct Format;
struct Meta64;
struct Node;
struct SceneNode;
struct Thing;
struct Writer64;
struct hkBool;

// 0x00cf6030
void WriteToDestination(void *, unsigned int, struct ::Format *, ::Destination *);
// 0x00cf6080
namespace fnv_00cf6080 { void FUN_00cf6080(int, void *, int, int, int, ::fnv_00cf6080::S_00cf6080_Listener *); }
// 0x00cf60d0
extern "C" void FUN_00cf60d0(void *, void *, ::FNV_C60d0_Walker *, ::FNV_C60d0_Sink *);
// 0x00cf6170
unsigned char *FUN_00cf6170(unsigned char *, ::FUN_00d46f70_Obj *);
// 0x00cf61c0
int GetThingValue(::Thing *);
// 0x00cf62b0
unsigned char *GetFlagByState(unsigned char *, ::FNV_Cf62b0_Obj *);
// 0x00cf6330
::hkBool FUN_00cf6330(const ::Container *);
// 0x00cf6380
unsigned char *FUN_00cf6380(unsigned char *, ::SceneNode *);
// 0x00cf63c0
void WriteObjectArray(void *, const ::CF63C0Class &, const void *, int, ::CF63C0Writer &);
// 0x00cf6580
void WriteReflectedMembers(void *, ::Meta64 *, ::Writer64 *);
// 0x00cf6920
void FUN_00cf6920(void *, ::Node *, void *);
// 0x00cf6980
void FUN_00cf6980(::FUN_00cf6980_class *);
// 0x00cf69a0
void FUN_00cf69a0(int *);
// 0x00cf69b0
int *FUN_00cf69b0();
