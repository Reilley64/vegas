#pragma once

struct BoneLODControllerArray;
struct BoneWeights;
struct MergeItems;
struct ScriptProgram;
template <class> struct BoneArray;

// 0x00a839d0
void FUN_00a839d0(unsigned char, ::MergeItems *);
// 0x00a83d40
void BuildBoneLODControllerSets(::ScriptProgram *, ::BoneWeights *, ::BoneArray< ::BoneLODControllerArray *> *, unsigned int *);
