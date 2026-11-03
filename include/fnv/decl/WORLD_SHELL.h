#pragma once

struct NiPoint3;

struct WORLD_SHELL {
public:
    // 0x005885f0
    void ProcessCellsInRadius(const ::NiPoint3 *, float, const ::NiPoint3 *, float, int, unsigned int);
};
