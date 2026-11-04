#pragma once

class NiRenderTargetGroup;

class BSRenderedTexture {
public:
    // 0x00b6b260
    ::NiRenderTargetGroup *GetGroup();
    // 0x00b6b790
    static void EndAllAndResetRendererState();
};
