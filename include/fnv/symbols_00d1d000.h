#pragma once
#include <cstdint>

namespace fnv_00d1d5a0 { struct AabbTree; }
namespace fnv_00d1d5a0 { struct TreePairArray; }
struct AabbTree;
struct ClosestCollector;
struct Collider;
struct NodeTree;
struct RayVisitor;
struct Tree;
struct TreeVector4;
struct VectorQ;

// 0x00d1d0b0
void FUN_00d1d0b0(::NodeTree *, const ::TreeVector4 *, const ::TreeVector4 *, ::RayVisitor *, float);
// 0x00d1d490
int FUN_00d1d490();
// 0x00d1d4a0
int CallWithDefaults(void *, intptr_t, intptr_t);
// 0x00d1d4d0
int FUN_00d1d4d0(void *, void *, void *, void *);
// 0x00d1d500
int FUN_00d1d500(void *, const void *, void *);
// 0x00d1d530
extern "C" void FUN_00d1d530();
// 0x00d1d540
extern "C" void *FUN_00d1d540(void *, intptr_t, intptr_t, intptr_t);
// 0x00d1d570
extern "C" void *FUN_00d1d570(void *, intptr_t, intptr_t);
// 0x00d1d5a0
namespace fnv_00d1d5a0 { int FUN_00d1d5a0(::fnv_00d1d5a0::AabbTree *, ::fnv_00d1d5a0::AabbTree *, ::fnv_00d1d5a0::TreePairArray *); }
// 0x00d1d890
int FUN_00d1d890(::Tree *, ::Tree *, ::Collider *);
// 0x00d1dbb0
void FUN_00d1dbb0(::AabbTree *, const ::VectorQ &, ::ClosestCollector *);
