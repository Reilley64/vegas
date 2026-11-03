#pragma once

class hkpCdBody;
class hkpCdPointCollector;
struct CollisionAgentContext;
struct S_00d3d3e0_P1P;
struct S_00d3d3e0_P2P;
struct S_00d3d3e0_P3P;
struct S_00d3dca0_Obj;

// 0x00d3d040
void FlipAndDispatchCollector(void *, void *, int, int);
// 0x00d3d1a0
void *CreateRetObj(int, char **, int, int);
// 0x00d3d240
void *CreateTargetAgent(void *, void *, void *, void *);
// 0x00d3d3e0
void FUN_00d3d3e0(::S_00d3d3e0_P1P, ::S_00d3d3e0_P2P, int, ::S_00d3d3e0_P3P);
// 0x00d3d8c0
void FUN_00d3d8c0(const ::hkpCdBody &, const ::hkpCdBody &, const ::CollisionAgentContext &, ::hkpCdPointCollector &);
// 0x00d3dca0
void FUN_00d3dca0(::S_00d3dca0_Obj *);
// 0x00d3dd00
void FUN_00d3dd00(intptr_t, intptr_t, int, int);
// 0x00d3dd50
void QueryD3DCollector(int, int, int, int);
