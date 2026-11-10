#pragma once

struct ThreeByThreeMatrix;

class NiQuaternion {
public:
    // 0x0064a290
    bool operator!=(const ::NiQuaternion &) const;
    // 0x00a38560
    void MakeUnitLength();
    // 0x00a6df40
    void FromRotationMatrix(const ::ThreeByThreeMatrix &);
    // 0x00a6e330
    void Slerp(float, const ::NiQuaternion &, const ::NiQuaternion &);
    // 0x011a9ea4
    static const ::NiQuaternion IDENTITY;
};
