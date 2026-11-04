// include/havok/hkMemoryResourceHandle.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKMEMORYRESOURCEHANDLE_H
#define FNV_HAVOK_HKMEMORYRESOURCEHANDLE_H

#include "hkBase.h"
#include "hkResourceHandle.h"
class hkMemoryResourceHandleExternalLink;
class hkReferencedObject;
class hkMemoryResourceHandle : public hkResourceHandle
{
  public:
    hkReferencedObject* m_pReferencedResource;                     // +0x8
    hkStringPtr m_name;                                            // +0xC
    hkArray<hkMemoryResourceHandleExternalLink> m_kExternalLinks;  // +0x10
};
#endif
