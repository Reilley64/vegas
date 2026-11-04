#pragma once

struct NiPixelFormatMasks {
public:
    // 0x00a7cd20
    static ::NiPixelFormatMasks CreateFromMasks(unsigned char, unsigned int, unsigned int, unsigned int, unsigned int);
};
