#pragma once
#include <cstdint>

#include <cstdint>

class FUN_00c4b470_owner;
class NiObjectC4BB;
struct NiPoint3;
struct ThreeByThreeMatrix;
namespace fnv_00c4b500 { struct Node; }
struct C4B0C0_Obj;
struct Mat3;
class NiCamera;
struct ObjQ;
struct Plane;
struct Pt;
struct ResultQ;
struct Source;

// 0x00c4b0c0
::C4B0C0_Obj *FUN_00c4b0c0();
// 0x00c4b310
::ResultQ *FUN_00c4b310(::ObjQ *, const char *, bool);
// 0x00c4b470
intptr_t FUN_00c4b470(::FUN_00c4b470_owner *, void **, unsigned char);
// 0x00c4b500
namespace fnv_00c4b500 { void FUN_00c4b500(::fnv_00c4b500::Node *); }
// 0x00c4b600
::Mat3 FUN_00c4b600(::Pt);
// 0x00c4b8a0
::ThreeByThreeMatrix FUN_00c4b8a0(::NiPoint3);
// 0x00c4bb40
void *FUN_00c4bb40(::NiObjectC4BB *);
// 0x00c4bf40
void FUN_00c4bf40(::Source *, ::Plane *, ::NiCamera *);
