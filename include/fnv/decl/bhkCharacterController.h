#pragma once

struct NiPoint3;

class bhkCharacterController {
public:
    // 0x00560d30
    float &GetVectorElement(int);
    // 0x00561630
    void FUN_00561630(const ::NiPoint3 &);
    // 0x00c6fa20
    bool FUN_00c6fa20();
};
