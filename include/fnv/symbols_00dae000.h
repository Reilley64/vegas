#pragma once

struct Manager;
struct Manifold;
struct ProcessOutput;
struct S_00dad640_Set;
struct S_00dae220_Set;
struct WorkData;

// 0x00dae220
void FUN_00dae220(int, ::S_00dae220_Set *);
// 0x00dae340
void FUN_00dae340(::S_00dad640_Set *, unsigned int);
// 0x00dae3a0
void FUN_00dae3a0(::Manifold &, const ::WorkData &, int, ::ProcessOutput &, ::Manager *);
