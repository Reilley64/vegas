// include/havok/hkxIndexBuffer.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x2C.
#ifndef FNV_HAVOK_HKXINDEXBUFFER_H
#define FNV_HAVOK_HKXINDEXBUFFER_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkxIndexBuffer : public hkReferencedObject
{
  public:
    enum IndexType
    {
        INDEX_TYPE_INVALID = 0,
        INDEX_TYPE_TRI_LIST = 1,
        INDEX_TYPE_TRI_STRIP = 2,
        INDEX_TYPE_TRI_FAN = 3,
        INDEX_TYPE_MAX_ID = 4
    };
    hkInt8 m_eIndexType;  // +0x8 (IndexType)
    char pad9[0x3];
    hkArray<hkUint16> m_kIndices16;  // +0xC
    hkArray<hkUint32> m_kIndices32;  // +0x18
    hkUint32 m_uiVertexBaseOffset;   // +0x24
    hkUint32 m_fRestLength;          // +0x28
};
#endif
