#pragma once

class NiInterpolator;

class NiBlendInterpolator {
public:
    // 0x00a36970
    unsigned char AddInterpolatorItem(::NiInterpolator *, float, char, float);
    // 0x00a36a90
    void RemoveInterpolatorAt(unsigned char);
};
