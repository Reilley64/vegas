#pragma once

class NiPoint3;
namespace fnv_00818310 { class ExplosionActor; }
namespace fnv_00818310 { struct ExplosionEffect; }

namespace fnv_00818310 {
struct ExplosionCaster {
public:
    // 0x00818310
    void ApplyExplosion(::fnv_00818310::ExplosionActor *, ::NiPoint3, ::fnv_00818310::ExplosionEffect *, float);
};
}
