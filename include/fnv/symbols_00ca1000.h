#pragma once

struct CA1080_NodeList;
struct CA1080_PtrArray;
struct WalkArray;
struct WalkLeaf;

// 0x00ca1080
void CollectMixedTypeNodes(::CA1080_NodeList *, ::CA1080_PtrArray *);
// 0x00ca11e0
void CollectLeafObjects(::WalkLeaf *, ::WalkArray *, ::WalkArray *);
