#pragma once

struct MotionObj;
struct Object;
struct SplitIsland_Arg0;
struct SplitIsland_Arg1;
struct SplitIsland_Arg2Vec;

// 0x00cb6060
void FUN_00cb6060(::SplitIsland_Arg0 *, ::SplitIsland_Arg1 *, ::SplitIsland_Arg2Vec *, void *);
// 0x00cb6e70
void PropagateStateToChildren(::Object *, int *);
// 0x00cb6f30
void FUN_00cb6f30(::Object *);
// 0x00cb6f70
void FUN_00cb6f70(::MotionObj *, int, int, int, int, int, int, int, int);
