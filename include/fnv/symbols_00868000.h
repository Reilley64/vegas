#pragma once

class NiAVObject;
struct AnimationObject;
struct NavMeshPtr;

// 0x00868330
void AddAnimationToGarbageCollector(::AnimationObject *);
// 0x00868490
void FUN_00868490(int);
// 0x00868660
void FUN_00868660(::NiAVObject *);
// 0x00868790
void AddNavMeshToGarbageCollector(::NavMeshPtr &);
// 0x00868d70
void FUN_00868d70(bool);
