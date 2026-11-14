#pragma once

class NiAVObject;
namespace fnv_00c88520 { struct SceneObject; }
struct FNVTraversalNode;
struct FNVTraversalOutput;
struct Filter;
struct SceneNode;

// 0x00c884c0
void AccumulateParentTransforms(::FNVTraversalNode *, ::FNVTraversalNode *, ::FNVTraversalOutput *);
// 0x00c88520
namespace fnv_00c88520 { void FUN_00c88520(::fnv_00c88520::SceneObject *, ::fnv_00c88520::SceneObject *); }
// 0x00c88810
void UpdateChainCollision(::NiAVObject *);
// 0x00c88a40
void FUN_00c88a40(bool, ::Filter, ::SceneNode *, ::SceneNode *, bool);
