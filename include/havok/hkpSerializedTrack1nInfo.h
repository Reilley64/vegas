// include/havok/hkpSerializedTrack1nInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKPSERIALIZEDTRACK1NINFO_H
#define FNV_HAVOK_HKPSERIALIZEDTRACK1NINFO_H

#include "hkBase.h"
class hkpAgent1nSector;
class hkpSerializedSubTrack1nInfo;
class hkpSerializedTrack1nInfo
{
  public:
    hkArray<hkpAgent1nSector*> m_kSectors;               // +0x0
    hkArray<hkpSerializedSubTrack1nInfo*> m_kSubTracks;  // +0xC
};
#endif
