#pragma once

#include <cstdint>

struct E6D310Geometry;
struct E6D310StripSet;

struct E6D310Renderer {
public:
    // 0x00e6d310
    void FUN_00e6d310(::E6D310StripSet *, ::E6D310Geometry *, std::intptr_t);
};
