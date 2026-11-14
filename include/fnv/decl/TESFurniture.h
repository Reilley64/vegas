#pragma once
#include <cstdint>

struct NiPoint3;

class TESFurniture {
public:
    // 0x005093f0
    bool GetCanSitOn();
    // 0x00509420
    bool GetCanSleepOn();
    // 0x00509450
    bool IsMarkerEnabled(unsigned int);
    // 0x005094f0
    static bool IsFurnitureSleepMarker(unsigned int);
    // 0x00509510
    static bool IsFurnitureSitMarker(unsigned int);
    // 0x00509920
    ::NiPoint3 GetMarkerOffset(uintptr_t, float);
};
