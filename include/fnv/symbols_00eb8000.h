#pragma once
#include <cstdint>

struct PhysObj_eb83b0;
struct Point3;
struct S_00eb8250_Edges;
struct S_00eb8250_Tri;

// 0x00eb8250
int FUN_00eb8250(::S_00eb8250_Edges *, ::S_00eb8250_Tri *, intptr_t, float, intptr_t, intptr_t);
// 0x00eb83b0
int ComputeContactTime(::PhysObj_eb83b0 *, ::PhysObj_eb83b0 *, float *, ::Point3 *);
