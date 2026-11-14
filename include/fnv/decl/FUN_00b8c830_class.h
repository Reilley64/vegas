#pragma once
#include <cstdint>

struct BSRenderedTexture;
struct HolderForAccum;

struct FUN_00b8c830_class {
public:
    // 0x00b8c830
    void RenderWithTextures(::HolderForAccum *, std::intptr_t, ::BSRenderedTexture *, ::BSRenderedTexture *, int, int);
};
