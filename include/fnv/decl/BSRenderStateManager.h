#pragma once

enum BSRENDERSTATE_LOCK;

class BSRenderStateManager {
public:
    // 0x00b97fa0
    static void SetDepthBufferEnabled(bool, ::BSRENDERSTATE_LOCK);
    // 0x00b98380
    static void SetColorWriteMask(unsigned int, ::BSRENDERSTATE_LOCK);
};
