#pragma once

struct FnvCpu_FUN_00d9f6b0_CpuInterface;
struct Header;
struct Manager;
struct Motion;
struct Params;
struct Point;
struct Result;
struct State;

// 0x00d9f250
extern "C" void FUN_00d9f250(const ::Point &, float, ::Params &, ::Motion *, ::Motion *, ::Manager *, ::Result &);
// 0x00d9f6b0
void FUN_00d9f6b0(::FnvCpu_FUN_00d9f6b0_CpuInterface *);
// 0x00d9f6d0
void FUN_00d9f6d0(void **);
// 0x00d9f6e0
void *FUN_00d9f6e0();
// 0x00d9f6f0
int FUN_00d9f6f0(void *, const ::Header *, const ::State *, int, float *);
// 0x00d9fb40
void FUN_00d9fb40(unsigned char *, int);
// 0x00d9fcf0
void FUN_00d9fcf0(unsigned int *, int, unsigned int *);
