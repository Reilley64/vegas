// include/havok/hkpRemoveTerminalsMoppModifier.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKPREMOVETERMINALSMOPPMODIFIER_H
#define FNV_HAVOK_HKPREMOVETERMINALSMOPPMODIFIER_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpRemoveTerminalsMoppModifier : public hkReferencedObject
{
  public:
    char pad8[0x4];
    hkArray<hkUint32> m_kRemovedTerminalIds;  // +0xC
    void* m_pTerminalIdsToRemove;             // +0x18
};
#endif
