#pragma once

class NiPixelFormat {
public:
    // 0x00a76540
    bool operator==(const ::NiPixelFormat &) const;
    // 0x00a765c0
    bool operator!=(const ::NiPixelFormat &) const;
    // 0x00a7cca0
    NiPixelFormat();
};
