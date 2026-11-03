#pragma once

class NiPixelFormat;
enum _D3DFORMAT;

class NiD3DTextureData {
public:
    // 0x00e7bd20
    static ::_D3DFORMAT ConvertPixelFormatToD3DFormat(const ::NiPixelFormat &);
};
