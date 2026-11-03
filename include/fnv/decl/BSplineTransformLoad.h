#pragma once

class NiStream;

struct BSplineTransformLoad {
public:
    // 0x00a50500
    void LoadBSplineTransform(::NiStream &);
};
