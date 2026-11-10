#pragma once

class RotationMatrix3x3;

struct Vector3D {
public:
    // 0x00b12890
    ::Vector3D operator*(const ::RotationMatrix3x3 &) const;
};
