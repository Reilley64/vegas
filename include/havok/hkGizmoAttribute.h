// include/havok/hkGizmoAttribute.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKGIZMOATTRIBUTE_H
#define FNV_HAVOK_HKGIZMOATTRIBUTE_H

#include "hkBase.h"
class hkGizmoAttribute
{
  public:
    enum GizmoType
    {
        POINT = 0,
        SPHERE = 1,
        PLANE = 2,
        ARROW = 3
    };
    hkBool m_bVisible;  // +0x0
    char pad1[0x3];
    char* m_pName;  // +0x4
    hkInt8 m_type;  // +0x8 (GizmoType)
    char pad9[0x3];
};
#endif
