#pragma once

struct CamPoint;

struct CamLook {
public:
    // 0x00a701b0
    bool SetLookAt(const ::CamPoint &, const ::CamPoint &);
};
