#pragma once

struct hkTransformq;

class hkSweptTransformq {
public:
    // 0x00cf22d0
    void Evaluate(float, ::hkTransformq &) const;
};
