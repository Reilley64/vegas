#pragma once
#include <cstdint>

struct Context;
struct Input;
struct Limits;
struct ListE061;
struct Node;
struct S_00e062a0_Mesh;
struct Vec3;

// 0x00e06010
void FUN_00e06010(unsigned char *);
// 0x00e06070
void ProcessInput(::Context **, ::Input *, void *, bool, int *, bool *);
// 0x00e061c0
void ProcessListBlocks(intptr_t, ::ListE061 *);
// 0x00e062a0
void SwapMeshRecords(void *, ::S_00e062a0_Mesh *);
// 0x00e06480
extern "C" void FUN_00e06480();
// 0x00e06b20
void FUN_00e06b20(::Node *);
// 0x00e06b50
void AdjustLimits(::Limits *, ::Limits *, ::Limits *);
// 0x00e06f20
int ClassifyVec3Region(const ::Vec3 *);
