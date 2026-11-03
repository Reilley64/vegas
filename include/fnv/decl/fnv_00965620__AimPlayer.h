#pragma once

namespace fnv_00965620 { struct AimObject; }
namespace fnv_00965620 { struct NiPoint3_ext; }

namespace fnv_00965620 {
struct AimPlayer {
public:
    // 0x00965620
    void UpdateAim(::fnv_00965620::AimObject *, ::fnv_00965620::AimObject *, float *, float *, const ::fnv_00965620::NiPoint3_ext *, float, float);
};
}
