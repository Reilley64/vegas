#pragma once

class NiAVObject;
struct AVObj_552790;
struct SceneNode;

// 0x00552380
unsigned int FUN_00552380();
// 0x00552390
void FUN_00552390(::SceneNode *);
// 0x00552490
bool FUN_00552490(bool *);
// 0x005524d0
namespace fnv_005524d0 { unsigned char FUN_005524d0(); }
// 0x005524f0
void RunWithLock(void *);
// 0x00552570
namespace fnv_00552570 { void FUN_00552570(); }
// 0x005526f0
void UpdateSceneGraph(::NiAVObject *);
// 0x00552790
void UpdateControllersRecursive(::AVObj_552790 *);
// 0x00552ba0
int FUN_00552ba0();
