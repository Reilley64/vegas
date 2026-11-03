#pragma once

#include <cstdint>

struct RenderTarget_b6d170;

struct RTManager_b6d170 {
public:
    // 0x00b6d170
    ::RenderTarget_b6d170 *CreateRenderTarget(std::intptr_t, unsigned int, unsigned int, int, int, unsigned int, int, int, int, int);
};
