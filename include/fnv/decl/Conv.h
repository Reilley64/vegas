#pragma once

struct PixelData;
struct SrcData;

struct Conv {
public:
    // 0x00a8be70
    ::PixelData *ConvertTexture(::SrcData *);
};
