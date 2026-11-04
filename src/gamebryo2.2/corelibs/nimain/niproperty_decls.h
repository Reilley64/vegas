// Private declarations for gamebryo2.2/corelibs/nimain/niproperty.cpp.
//
// (lookup type NiBinaryStream) and carries the stream read helper used by
// the nimain property units.
#ifndef FNV_NIPROPERTY_DECLS_H
#define FNV_NIPROPERTY_DECLS_H

#include "NiObject.h"
#include "niproperty_types_NiStream.h"

class NiExtraData;
class NiTimeController;

class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;               // +0x0, 4 bytes
    unsigned int m_uiStreamFlags;  // +0x4, 4 bytes
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*,
                                     unsigned int);  // +0x8, 4 bytes
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*,
                                      unsigned int);  // +0xC, 4 bytes

    template <class T> void Read(T& value)
    {
        unsigned int size = sizeof(T);
        m_uiStreamFlags += m_pfnRead(this, &value, sizeof(T), &size, 1);
    }
};

// NiObjectNET and NiProperty use the canonical nimain unit idiom (see
// nitexture_match.h): members with their canonical names and a non-virtual
// LoadBinary(NiStream&).  NiProperty::LoadBinary calls the base directly.
class NiObjectNET : public NiObject
{
  public:
    NiFixedString m_kName;                       // +0x8
    NiPointer<NiTimeController> m_pControllers;  // +0xC
    NiExtraData** m_ppExtraData;                 // +0x10
    unsigned short m_usExtraDataCount;           // +0x14
    unsigned short m_usMaxSize;                  // +0x16
    void LoadBinary(NiStream&);
};

class NiProperty : public NiObjectNET
{
  public:
    void LoadBinary(NiStream&);
};

#endif