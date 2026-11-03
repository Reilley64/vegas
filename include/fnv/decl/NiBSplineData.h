#pragma once

class NiBSplineBasisData;

class NiBSplineData {
public:
    // 0x00a526b0
    void CalculateSplineValue(float, float *, unsigned int, ::NiBSplineBasisData *, unsigned int, float, float);
};
