#pragma once
#include <cstdint>

class Setting;

// 0x00403940
uintptr_t FUN_00403940(unsigned int, unsigned int);
// 0x00403ba0
int *FUN_00403ba0(int *);
// 0x00403c80
bool HasEffectArchetypeFlag(int, unsigned int);
// 0x00403d30
void FUN_00403d30(void *, int, unsigned int);
// 0x00403e20
float &FUN_00403e20(Setting *);
// The value 4 bytes into the setting, where the 32-bit layout has it. No
// object defines this form; calls whose argument is not shown to be a
// setting of the shared class stay on it (VEGAS-116). Do not define it,
// alias it or add calls to it; a call moves to the form above when its
// argument is shown to be a shared-class setting. It is removed with the last
// tabled call.
float &FUN_00403e20(float *);
