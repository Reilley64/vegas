#pragma once

namespace fnv_00c1dec0 { struct Point3; }
namespace fnv_00c1dec0 { struct SkinGeometry; }
namespace fnv_00c1dec0 { struct SkinInst; }

namespace fnv_00c1dec0 {
struct SkinEmitter {
public:
    // 0x00c1dec0
    bool GetRandomEmitterParticle(::fnv_00c1dec0::SkinInst *, ::fnv_00c1dec0::SkinGeometry *, ::fnv_00c1dec0::Point3 &, ::fnv_00c1dec0::Point3 &);
};
}
