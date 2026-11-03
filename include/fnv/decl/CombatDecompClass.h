#pragma once
#include <cstdint>

struct RetObjParam;

struct CombatDecompClass {
public:
    // 0x0099e060
    bool InitSubObject(::RetObjParam *, intptr_t, int, float, intptr_t);
};
