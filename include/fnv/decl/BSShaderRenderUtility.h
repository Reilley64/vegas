#pragma once

class BSShaderAccumulator;
class NiCamera;
class NiNode;

class BSShaderRenderUtility {
public:
    // 0x00469860
    bool IsRenderTargetId(unsigned int);
    // 0x00b6bb30
    static void SetAlphaOnNode(::NiNode *, float);
    // 0x00b6c0d0
    static void SetRenderCamera(::NiCamera *, ::BSShaderAccumulator *, bool);
};
