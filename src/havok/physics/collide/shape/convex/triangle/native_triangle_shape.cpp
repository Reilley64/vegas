#include "havok/hkpTriangleShape.h"

// 00de10b0 construction and 00dccf60 vertex publication, expressed as a
// complete native object instead of installing a numerical vtable in bytes.
hkpTriangleShape::hkpTriangleShape(hkReal radius, hkUint16 weldingInfo, hkUint8 weldingType,
                                 const hkVector4& a, const hkVector4& b, const hkVector4& c) noexcept
    : m_kWeldingInfo(weldingInfo), m_eWeldingType(weldingType), m_ucWeldingPadding(0),
      m_kVertexA(a), m_kVertexB(b), m_kVertexC(c), m_kVertexTransform{0, 0, 0, 0}
{
    m_ulUserData = 0;
    m_type = 3;
    m_fSphereRadius = radius;
}

const hkVector4& hkpTriangleShape::getVertex(int index) const noexcept
{
    // Separate members are not an array; do not reproduce (&vertexA)[index].
    if (index == 0) return m_kVertexA;
    if (index == 1) return m_kVertexB;
    return m_kVertexC;
}
