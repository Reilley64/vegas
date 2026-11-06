// include/havok/hkBase.h - Havok 7.1 value types used by the generated class headers (gen_havok_headers.py, 2026-10-17).
#ifndef FNV_HAVOK_HKBASE_H
#define FNV_HAVOK_HKBASE_H
#include <stdint.h>
typedef float hkReal;
typedef signed char hkInt8;
typedef unsigned char hkUint8;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef int hkInt32;
typedef unsigned int hkUint32;
typedef int64_t hkInt64;
typedef uint64_t hkUint64;
typedef uintptr_t hkUlong;
typedef intptr_t hkLong;
typedef char hkBool;
typedef short hkHalf;
typedef char* hkStringPtr;
class hkClass;
class hkClassEnum;
struct hkVector4
{
    hkReal x, y, z, w;
};  // 16 bytes (SIMD-aligned in the PC build)
struct hkVector4;
struct hkQuaternion
{
    hkVector4 m_vec;
public:
    void FUN_00cb2ca0(const ::hkVector4 &, ::hkQuaternion &, float &) const;
};  // 16
struct hkMatrix3
{
    hkVector4 m_kColumn0, m_kColumn1, m_kColumn2;
public:
    int FUN_00cd4f10(float);
};  // 48
struct hkRotation : hkMatrix3
{
};  // 48
struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};  // 64
struct hkQsTransform
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
};  // 48
struct hkMatrix4
{
    hkVector4 m_kColumn0, m_kColumn1, m_kColumn2, m_kColumn3;
public:
    void FUN_00de8e50(const ::hkMatrix4 &);
};  // 64
template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};  // 12
template <class T> struct hkSimpleArray
{
    T* m_data;
    int m_iElementCount;
};  // 8
struct hkVariant
{
    void* m_object;
    const hkClass* m_class;
};  // 8
struct hkHomogeneousArray
{
    const hkClass* m_class;
    void* m_data;
    int m_iElementCount;
};  // 12
class hkBaseObject
{
  public:
    virtual ~hkBaseObject();
};  // 4 (vtable)
#endif
