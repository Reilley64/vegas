// Native triangle value with real shape lifetime.
#ifndef FNV_HAVOK_HKPTRIANGLESHAPE_H
#define FNV_HAVOK_HKPTRIANGLESHAPE_H

#include "hkBase.h"
#include "hkpConvexShape.h"
class hkpTriangleShape : public hkpConvexShape
{
  public:
    hkpTriangleShape(hkReal radius, hkUint16 weldingInfo, hkUint8 weldingType,
                     const hkVector4& a, const hkVector4& b, const hkVector4& c) noexcept;
    // index is one of 0, 1, 2.
    const hkVector4& getVertex(int index) const noexcept;
    hkReal getRadius() const noexcept { return m_fSphereRadius; }
    hkUint16 getWeldingInfo() const noexcept { return m_kWeldingInfo; }
    hkUint8 getWeldingType() const noexcept { return m_eWeldingType; }

    hkUint16 m_kWeldingInfo;
    hkUint8 m_eWeldingType;
    hkUint8 m_ucWeldingPadding;
    hkVector4 m_kVertexA;
    hkVector4 m_kVertexB;
    hkVector4 m_kVertexC;
    hkVector4 m_kVertexTransform;
};
#endif
