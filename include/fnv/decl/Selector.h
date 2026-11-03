#pragma once
#include <cstdint>

struct Reference;

struct Selector {
public:
    // 0x005195e0
    void *FindRandomSelection(::Reference *, std::intptr_t);
};
