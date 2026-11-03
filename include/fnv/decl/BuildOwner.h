#pragma once

struct BuildInput;
struct BuildResult;

struct BuildOwner {
public:
    // 0x00994f10
    ::BuildResult *BuildResultForInput(int, int, ::BuildInput *, bool);
};
