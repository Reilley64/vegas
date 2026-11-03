#pragma once

class NiRenderer;
struct NiPixelFormat;

struct NiDepthStencilBuffer {
public:
    // 0x00a9fe90
    static ::NiDepthStencilBuffer *Create(unsigned int, unsigned int, ::NiRenderer *, const ::NiPixelFormat &, unsigned int);
};
