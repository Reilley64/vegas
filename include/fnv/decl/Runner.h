#pragma once

#include <cstdint>

struct A8;
struct SLoc;

struct Runner {
public:
    // 0x005e0d20
    bool RunScript(::A8 *, void *, ::SLoc *, std::intptr_t, bool, char, char, float);
};
