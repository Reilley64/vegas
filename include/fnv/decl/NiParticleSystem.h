#pragma once

struct NiParticleSystem {
public:
    // 0x00c1b020
    void SetSelectiveUpdateFlags(bool &, bool, bool &);
    // 0x00c31400
    void FindModifier();
};
