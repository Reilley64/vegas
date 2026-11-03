#pragma once

#include <cstdint>

struct LocationLocal;

struct BuilderLocal {
public:
    // 0x006cd670
    bool FindPath(::LocationLocal *, ::LocationLocal *, int, std::intptr_t, std::intptr_t, int, int);
};
