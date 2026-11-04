#pragma once

class NiPoint3;

class NiPlane {
public:
    // 0x00439090
    bool operator==(const ::NiPlane &);
    // 0x00a69940
    NiPlane();
    // 0x00a69970
    NiPlane(const ::NiPoint3 &, float);
    // 0x00a69990
    NiPlane(const ::NiPoint3 &, const ::NiPoint3 &);
};
