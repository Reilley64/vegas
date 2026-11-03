#pragma once

struct NiPoint3;

class BGSTerrainManager {
public:
    // 0x00441110
    unsigned int GetMinLevel();
    // 0x006fca90
    void FUN_006fca90(const ::NiPoint3 &, int);
};
