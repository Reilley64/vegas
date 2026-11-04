#pragma once

class Ni2DBuffer;
class NiPixelFormat;
struct DepthDevice;

class NiDX9AdditionalDepthStencilBufferData {
public:
    // 0x00e7d9d0
    static ::NiDX9AdditionalDepthStencilBufferData *Create(::DepthDevice *, ::Ni2DBuffer **, const ::NiPixelFormat *, unsigned int);
};
