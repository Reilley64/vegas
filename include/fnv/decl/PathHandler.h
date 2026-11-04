#pragma once
#include <cstdint>

class NiPoint3;
struct PathingContext;

class PathHandler {
public:
    // 0x006ce8b0
    bool FindPath(const ::NiPoint3 &, const ::NiPoint3 &, ::PathingContext *, intptr_t);
};
