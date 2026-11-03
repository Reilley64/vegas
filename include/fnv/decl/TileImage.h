#pragma once

class NiAVObject;

class TileImage {
public:
    // 0x0078cdf0
    void UpdateTileImage();
    // 0x00a20610
    void SetTexture(::NiAVObject *);
};
