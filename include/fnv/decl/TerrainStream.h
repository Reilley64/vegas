#pragma once

class TerrainRefProxy;

class TerrainStream {
public:
    // 0x006fd080
    void PushRef(::TerrainRefProxy *);
};
