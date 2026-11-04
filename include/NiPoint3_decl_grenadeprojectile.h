// Source layout: NiPoint3. PC corrections are in generate_headers.py.
#ifndef FNV_NIPOINT3_H
#define FNV_NIPOINT3_H

#include "fnv/decl/FUN_004a0c10_s.h"
#include "layout_support.h"
class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
    NiPoint3();
    NiPoint3 operator+(const NiPoint3& point) const;
    NiPoint3 operator-(const NiPoint3& point) const;
    NiPoint3 operator*(float scalar) const;
    NiPoint3& operator+=(const NiPoint3& point)
    {
        x += point.x;
        y += point.y;
        z += point.z;
        return *this;
    }
    NiPoint3& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }
    float Dot(const NiPoint3& point) const
    {
        return x * point.x + y * point.y + z * point.z;
    }
    static const NiPoint3 ZERO;
    float GetLengthSquared();
    NiPoint3 CrossProduct(const NiPoint3& point) const;
public:
    float ComputeMagnitude() const;
};
#endif
