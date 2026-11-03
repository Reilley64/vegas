#pragma once

struct SortCamera;

struct BSBatchRenderer_AlphaDepth {
public:
    // 0x00b98c80
    float ComputeAlphaDepth(int, ::SortCamera *, bool);
};
