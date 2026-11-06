// Shared native sphere construction and state, not a serialized object layout.
#ifndef FNV_HAVOK_HKPSPHERESHAPE_H
#define FNV_HAVOK_HKPSPHERESHAPE_H

#include "hkBase.h"
#include "hkpConvexShape.h"
class hkpSphereShape : public hkpConvexShape
{
  public:
    hkpSphereShape() = default; // Retained for unported finishing paths.
    explicit hkpSphereShape(hkReal radius);
    hkReal getRadius() const noexcept { return m_fSphereRadius; }
    hkUint32 m_aiValuesD34[3];  // Legacy, unreflected state.
};
#endif
