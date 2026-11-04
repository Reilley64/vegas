// Source layout: NiPoint3. PC corrections are in generate_headers.py.
#ifndef FNV_NIPOINT3_H
#define FNV_NIPOINT3_H
#include "fnv/decl/FUN_004a0c10_s.h"
#include "layout_support.h"
struct FUN_00438fc0_file;
class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
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
    float Length() const;
    void Unitize();
    static const NiPoint3 ZERO;
    float GetLengthSquared();
    NiPoint3 CrossProduct(const NiPoint3& point) const;
public:
    unsigned char ReadFromFile(::FUN_00438fc0_file *);
public:
    bool FUN_004390c0(const ::NiPoint3 &);
public:
    ::NiPoint3 &Subtract(const ::NiPoint3 &);
public:
    float ComputeMagnitude() const;
public:
    char *FUN_00a59af0(const char *);
};
#endif
