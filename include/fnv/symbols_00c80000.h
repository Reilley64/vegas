#pragma once
#include <cstdint>

struct NiObject;
class ProbeObj;
struct ArenaManagedOwner;
struct ArenaOwner;
struct DispatchContainer;
struct MyNode;
struct SceneObject;
struct SceneObjectLocal;
struct SpawnedPtrArray;
struct TreeNode_cls;
struct WalkNode_c804;
struct WalkNode_cls;
struct WorkNode_cls;
struct WorkStack_cls;

// 0x00c80020
int FUN_00c80020(::DispatchContainer *);
// 0x00c80090
bool FUN_00c80090(struct ::ProbeObj *);
// 0x00c80130
void EnsureArenaAllocated(::ArenaOwner *);
// 0x00c80240
void FUN_00c80240(::ArenaManagedOwner *);
// 0x00c802d0
::MyNode *FUN_00c802d0(::MyNode *);
// 0x00c80330
void SetFlagRecursive(bool, ::WalkNode_cls *);
// 0x00c803a0
void FUN_00c803a0(::SceneObject *, float);
// 0x00c804d0
void FUN_00c804d0(::WalkNode_c804 *, unsigned int);
// 0x00c806b0
void *FUN_00c806b0(void *, const void *, bool);
// 0x00c80700
void ProcessControllerList(::WalkNode_cls *);
// 0x00c80930
void CollectTreeResultValues(::TreeNode_cls *, ::SpawnedPtrArray *);
// 0x00c809e0
void AppendSpawnedPtr(void *, ::SpawnedPtrArray *);
// 0x00c80c00
::NiObject *FUN_00c80c00(::WorkNode_cls *, ::WorkStack_cls *, uintptr_t, unsigned int);
// 0x00c80ce0
void FUN_00c80ce0(::SceneObjectLocal *, int);
