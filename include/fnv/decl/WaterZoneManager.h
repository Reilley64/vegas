#pragma once

class TESObjectREFR;
class WaterSurface;

class WaterZoneManager {
public:
    // 0x004e59f0
    ::WaterSurface *GetWaterZone(::TESObjectREFR *, ::TESObjectREFR *, float);
    // 0x004e5df0
    void UpdateWaterZone(::TESObjectREFR *, ::TESObjectREFR *, float);
};
