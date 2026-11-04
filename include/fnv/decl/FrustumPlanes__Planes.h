#pragma once

namespace FrustumPlanes { struct Frustum; }
namespace FrustumPlanes { struct Transform; }

namespace FrustumPlanes {
struct Planes {
public:
    // 0x00a74e10
    void SetFromFrustum(const ::FrustumPlanes::Frustum *, const ::FrustumPlanes::Transform *);
};
}
