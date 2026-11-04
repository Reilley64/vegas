#pragma once
#include <cstdint>

struct Buffer;
struct Obj;
struct Vec;

struct ProjectileHit {
public:
    // 0x009bf5a0
    bool ProcessHit(::Obj *, const ::Vec &, const ::Vec &, ::Buffer *, intptr_t, intptr_t);
};
