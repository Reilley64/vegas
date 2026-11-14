// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NICONTROLLERSEQUENCE_IDTAG_H
#define FNV_NICONTROLLERSEQUENCE_IDTAG_H

#include "layout_support.h"
#include "NiFixedString.h"
class NiControllerSequence__IDTag;
class NiControllerSequence__IDTag
{
  public:
    NiControllerSequence__IDTag& operator=(const NiControllerSequence__IDTag&);
    NiFixedString m_kAVObjectName;    // +0x0, 4 bytes
    NiFixedString m_kPropertyType;    // +0x4, 4 bytes
    NiFixedString m_kCtlrType;        // +0x8, 4 bytes
    NiFixedString m_kCtlrID;          // +0xC, 4 bytes
    NiFixedString m_kInterpolatorID;  // +0x10, 4 bytes
    // IDTag
    // const NiFixedString& __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(const NiFixedString&)
    // const NiFixedString& __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(const NiFixedString&)
    // const NiFixedString& __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(const NiFixedString&)
    // const NiFixedString& __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(const NiFixedString&)
    // const NiFixedString& __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(const NiFixedString&)
    // NiControllerSequence::IDTag& __cdecl NiControllerSequence::IDTag::*(const NiControllerSequence::IDTag&)
    // void __cdecl NiControllerSequence::IDTag::*()
    // bool __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*(NiStream&)
    // void __cdecl NiControllerSequence::IDTag::*(NiStream&)
    // void __cdecl NiControllerSequence::IDTag::*(NiStream&, void*&)
    // void __cdecl NiControllerSequence::IDTag::*(NiStringPalette*, NiStream&)
    // bool __cdecl NiControllerSequence::IDTag::*(const NiControllerSequence::IDTag&)
    // bool __cdecl NiControllerSequence::IDTag::*()
    // bool __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*()
    // void __cdecl NiControllerSequence::IDTag::*()
    // void* __cdecl NiControllerSequence::IDTag::*(unsigned int)
};
#endif
