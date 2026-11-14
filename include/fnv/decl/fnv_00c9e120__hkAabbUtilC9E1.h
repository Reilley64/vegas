#pragma once

namespace fnv_00c9e120 { struct hkAabbC9E1; }
namespace fnv_00c9e120 { struct hkTransformC9E1; }
namespace fnv_00c9e120 { struct hkVector4C9E1; }

namespace fnv_00c9e120 {
struct hkAabbUtilC9E1 {
public:
    // 0x00c9e120
    static void ComputeAabbFromTransform(const ::fnv_00c9e120::hkTransformC9E1 &, const ::fnv_00c9e120::hkVector4C9E1 &, float, ::fnv_00c9e120::hkAabbC9E1 &);
};
}
