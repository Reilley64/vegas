#pragma once

struct NiPoint3;

struct ScreenCamera {
public:
    // 0x00a6fc50
    bool ProjectToScreen(const ::NiPoint3 &, float &, float &, float) const;
};
