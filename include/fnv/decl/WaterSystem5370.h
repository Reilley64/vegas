#pragma once

struct NiPoint3;
class TESObjectREFR;
struct WaterRotation;

class WaterSystem5370 {
public:
    // 0x004e5370
    bool RemoveWaterRef(::TESObjectREFR *, const ::NiPoint3 *, const ::WaterRotation *);
};
