#pragma once

struct WRCamera;

struct WRWaterManager {
public:
    // 0x004eaf80
    void UpdateWaterReflection(::WRCamera *);
};
