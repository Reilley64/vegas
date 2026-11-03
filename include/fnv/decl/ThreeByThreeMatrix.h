#pragma once

class NiPoint3;

class ThreeByThreeMatrix {
public:
    // 0x004168a0
    void MakeAxisAngleRotation(float, float, float, float);
    // 0x0043f850
    void SetYRotation(float);
    // 0x0043f8d0
    ::ThreeByThreeMatrix operator+(const ::ThreeByThreeMatrix &) const;
    // 0x004768c0
    ::ThreeByThreeMatrix Transpose();
    // 0x00476930
    void GetRow(unsigned int, ::NiPoint3 &);
    // 0x004b45b0
    ::ThreeByThreeMatrix *FUN_004b45b0(::ThreeByThreeMatrix *);
    // 0x004b46a0
    bool Inverse(::ThreeByThreeMatrix &);
    // 0x004d9ab0
    bool operator!=(const ::ThreeByThreeMatrix &) const;
    // 0x004d9ae0
    bool operator==(const ::ThreeByThreeMatrix &) const;
    // 0x00a59780
    void FUN_00a59780(float, float, float);
};
