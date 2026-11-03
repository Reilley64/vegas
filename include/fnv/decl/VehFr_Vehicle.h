#pragma once

struct VehFr_FrictionParams;
struct VehFr_Ground;

struct VehFr_Vehicle {
public:
    // 0x00e38140
    void FUN_00e38140(float, ::VehFr_FrictionParams &, ::VehFr_Ground &);
};
