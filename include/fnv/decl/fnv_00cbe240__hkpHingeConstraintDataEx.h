#pragma once

struct hkTransform;
struct hkVector4;

namespace fnv_00cbe240 {
struct hkpHingeConstraintDataEx {
public:
    // 0x00cbe240
    void SetLocalTransforms(const ::hkTransform &, const ::hkTransform &, const ::hkVector4 &, const ::hkVector4 &);
};
}
