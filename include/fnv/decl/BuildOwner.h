#pragma once
#include <cstdint>

struct BuildInput;
struct BuildResult;

struct BuildOwner {
public:
    // 0x00994f10
    ::BuildResult *BuildResultForInput(intptr_t, intptr_t, ::BuildInput *, bool);
};
