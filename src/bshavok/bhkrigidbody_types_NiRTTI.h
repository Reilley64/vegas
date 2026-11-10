// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIRTTI_H
#define FNV_NIRTTI_H

#include "layout_support.h"
struct NiRTTI;
struct NiRTTI
{
  public:
    const char* m_pcName;       // +0x0, 4 bytes
    const NiRTTI* m_pBaseRTTI;  // +0x4, 4 bytes
    // void __cdecl NiRTTI::*(const char*, const NiRTTI*)
    // const char* __cdecl NiRTTI::*()
    // const NiRTTI* __cdecl NiRTTI::*()
};
#endif
