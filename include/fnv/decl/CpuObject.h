#pragma once
#include <cstdint>

struct CpuObject {
public:
    // 0x00b6d120
    int FUN_00b6d120();
    // 0x00c91020
    float FUN_00c91020();
    // 0x00cac910
    uintptr_t FUN_00cac910();
    // 0x00d872e0
    int FUN_00d872e0(int);
    // 0x00dba670
    bool FUN_00dba670();
    // 0x00ddcd70
    ::CpuObject *DestroyOrFree(unsigned int);
    // 0x00de4900
    float FUN_00de4900();
    // 0x00e00c40
    ::CpuObject *FUN_00e00c40(unsigned int);
    // 0x00e10a10
    void FUN_00e10a10(int);
    // 0x00eea560
    void FUN_00eea560(int);
};
