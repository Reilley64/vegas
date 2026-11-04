#pragma once

class NiObjectNET;
class NiQuatTransform;

class NiBlendAccumTransformInterpolator {
public:
    // 0x00a397b0
    bool UpdateAccumulatedTransform(float, ::NiObjectNET *, ::NiQuatTransform &);
};
