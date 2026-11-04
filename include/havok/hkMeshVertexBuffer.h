// include/havok/hkMeshVertexBuffer.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKMESHVERTEXBUFFER_H
#define FNV_HAVOK_HKMESHVERTEXBUFFER_H
#include "hkBase.h"
#include "hkReferencedObject.h"
class hkMeshVertexBuffer : public hkReferencedObject
{
  public:
    enum Flags
    {
        ACCESS_READ = 1,
        ACCESS_WRITE = 2,
        ACCESS_READ_WRITE = 3,
        ACCESS_WRITE_DISCARD = 4,
        ACCESS_ELEMENT_ARRAY = 8
    };
    enum LockResult
    {
        RESULT_FAILURE = 0,
        RESULT_SUCCESS = 1,
        RESULT_IN_USE = 2
    };
};
#endif
