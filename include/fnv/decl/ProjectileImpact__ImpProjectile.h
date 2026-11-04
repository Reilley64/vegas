#pragma once
#include <cstdint>

namespace ProjectileImpact { struct ImpPoint; }
namespace ProjectileImpact { struct ImpTarget; }

namespace ProjectileImpact {
struct ImpProjectile {
public:
    // 0x009c20e0
    void ApplyImpact(::ProjectileImpact::ImpTarget *, ::ProjectileImpact::ImpPoint *, ::ProjectileImpact::ImpPoint *, intptr_t, int);
};
}
