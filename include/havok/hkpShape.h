// Shared native shape state. No original-release layout is assumed.
#ifndef FNV_HAVOK_HKPSHAPE_H
#define FNV_HAVOK_HKPSHAPE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpShape : public hkReferencedObject
{
  public:
    hkpShape() = default; // Retained for the not-yet-ported finishing paths.
    hkUint32 getType() const noexcept { return m_type; }
    hkUlong m_ulUserData;
    hkUint32 m_type;

  protected:
    explicit hkpShape(hkUint32 type) noexcept : m_ulUserData(0), m_type(type) {}
};
#endif
