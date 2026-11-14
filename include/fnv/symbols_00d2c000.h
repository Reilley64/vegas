#pragma once
#include <cstdint>

struct FnvCpu_FUN_00d2c7d0_CpuInterface;
struct TargetObj;

// 0x00d2c7d0
void FUN_00d2c7d0(::FnvCpu_FUN_00d2c7d0_CpuInterface *);
// 0x00d2c840
void ConstructObjD2C840(void *, int);
// 0x00d2c8a0
const void *FUN_00d2c8a0();
// 0x00d2caa0
namespace fnv_00d2caa0 { void FUN_00d2caa0(void *, void *, uintptr_t); }
// 0x00d2cab0
void FUN_00d2cab0();
// 0x00d2cb70
void CopyMemoryBackward(void *, void *, unsigned int);
// 0x00d2cc70
void FUN_00d2cc70(void *, void *, unsigned int);
// 0x00d2cca0
void InitHookTable(::TargetObj *);
// 0x00d2cfb0
void *CpuJobThreadMain(void *);
