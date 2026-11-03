#pragma once
#include <cstdint>

class C11F0Object;
class C11F0Owner;
namespace fnv_00c81730 { struct bhkBlendCollisionObject; }
struct C11F0Color;
struct NiNode;
struct S00c81c50_Obj;
struct TreeNode_cls;

// 0x00c811f0
void AttachEmissiveMaterial(::C11F0Object *, ::C11F0Owner *, int, ::C11F0Color *);
// 0x00c812d0
int FUN_00c812d0(void *, void *);
// 0x00c81380
::NiNode *FUN_00c81380(float, float);
// 0x00c81730
namespace fnv_00c81730 { ::fnv_00c81730::bhkBlendCollisionObject *CreateBlendCollisionObject(); }
// 0x00c81b90
float GetFloatProperty(intptr_t, const char *);
// 0x00c81c50
void *FUN_00c81c50(::S00c81c50_Obj *);
// 0x00c81db0
void SetTreeValue(::TreeNode_cls *, unsigned int);
