#pragma once
#include <cstdint>

struct Filter;
struct Item;
struct Magic;
struct Node;
struct Source;
struct Target;
struct Vec;

struct Caster {
public:
    // 0x00816f10
    void ApplyAreaEffect(::Magic *, ::Item *, std::intptr_t, ::Vec, ::Target *, ::Filter *, ::Node *, bool *, float);
    // 0x00d42cf0
    int ProcessSource(::Source *, int, int, int, int);
};
