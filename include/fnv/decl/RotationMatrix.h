#pragma once

struct RotationMatrix {
public:
    // 0x00a59400
    bool FUN_00a59400(float &, float &, float &);
    // 0x00b12ec0
    void SetRotationAxisAngle(float, float, float, float);
};
