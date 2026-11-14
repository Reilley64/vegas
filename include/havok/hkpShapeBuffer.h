// Scoped native triangle storage. A returned child is borrowed until the next
// retrieval into this buffer, or buffer destruction. No original buffer ABI.
#ifndef FNV_HAVOK_HKPSHAPEBUFFER_H
#define FNV_HAVOK_HKPSHAPEBUFFER_H
#include "hkpTriangleShape.h"
#include <optional>

class hkpShapeBuffer
{
  public:
    hkpShapeBuffer() = default;
    hkpShapeBuffer(const hkpShapeBuffer&) = delete;
    hkpShapeBuffer& operator=(const hkpShapeBuffer&) = delete;
    const hkpTriangleShape& setTriangle(hkReal radius, hkUint16 welding, hkUint8 weldingType,
                                      const hkVector4& a, const hkVector4& b, const hkVector4& c) noexcept
    {
        return triangle.emplace(radius, welding, weldingType, a, b, c);
    }

  private:
    std::optional<hkpTriangleShape> triangle;
};
#endif
