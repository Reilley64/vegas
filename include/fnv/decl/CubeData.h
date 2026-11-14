#pragma once

class Texture;
struct PixelFormat;

class CubeData {
public:
    // 0x00e900c0
    ::PixelFormat *CreateSurface(::Texture *);
};
