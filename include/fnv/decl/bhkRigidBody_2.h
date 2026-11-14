#pragma once

struct NiPoint3;
class NiQuaternion;

class bhkRigidBody {
public:
    // 0x0062ab20
    float GetBodyMass();
    // 0x00c8d0f0
    ::NiPoint3 &GetPosition(::NiPoint3 &);
    // 0x00c8d130
    ::NiQuaternion &GetRotation(::NiQuaternion &);
    // 0x00c8d170
    void SetPosition(const ::NiPoint3 &);
    // 0x00c8d1a0
    void SetRotation(const ::NiQuaternion &);
    // 0x00c8d1d0
    void FUN_00c8d1d0(const ::NiPoint3 &, const ::NiQuaternion &);
};
