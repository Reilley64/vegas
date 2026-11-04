// include/havok/hkArrayTypeAttribute.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1.
#ifndef FNV_HAVOK_HKARRAYTYPEATTRIBUTE_H
#define FNV_HAVOK_HKARRAYTYPEATTRIBUTE_H
#include "hkBase.h"
class hkArrayTypeAttribute
{
  public:
    enum ArrayType
    {
        NONE = 0,
        POINTSOUP = 1,
        ENTITIES = 2
    };
    hkInt8 m_type;  // +0x0 (ArrayType)
};
#endif
