#include "havok/hkpSphereShape.h"
#include "havok/hkpBallGun.h"
#include "havok/SphereConstruction.h"

// The existing sphere constructor, with native C++ lifetime/dispatch instead
// of installing a reconstructed vtable. A sphere owns no child resources.
hkpSphereShape::hkpSphereShape(hkReal radius)
{
    m_fSphereRadius = radius;
    m_ulUserData = 0;
    m_type = 1;
}

// This native owner constructs the complete type, including for callers that
// cannot include it alongside their unrelated legacy reconstruction views.
hkpSphereShape* havok::createSphere(float radius)
{
    return new hkpSphereShape(radius);
}

// Shared by the ball-gun and mounted-ball-gun production firing paths.
hkpSphereShape* hkpBallGun::createBulletShape() const
{
    return havok::createSphere(m_fBulletRadius);
}
