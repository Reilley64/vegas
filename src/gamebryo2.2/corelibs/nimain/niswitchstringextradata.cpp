
// src/gamebryo2.2/corelibs/nimain/niswitchstringextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niswitchstringextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/ExtraDataObject.h"
#include "fnv/decl/ExtraDataStrings.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a64160_cls.h"
#include "fnv/decl/FUN_00a64ce0_shell.h"
#include "fnv/decl/FUN_00a7b2c0_shell.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a47000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/symbols_011f6000.h"
struct NiRTTI;


// @fnv 0x00a93740
NiRTTI* __cdecl FUN_00a93740()
{
    return &(*reinterpret_cast<::NiRTTI *>(&::g_011f5eac));
}

class NiStream;
struct NiExtraData
{
public:
    void LoadBinary(::NiStream &);
};

struct BSFadeNode
{
};

extern int DAT_0109ff64;

// @fnv 0x00a93870
void* __cdecl FUN_00a93870()
{
    void* p = ::operator new(0x18);
    if (p)
    {
        NiExtraData* pExtra = static_cast<NiExtraData*>(p);
        reinterpret_cast<::ExtraDataObject *>((pExtra))->FUN_00a7b2e0();
        *reinterpret_cast<int**>(p) = &DAT_0109ff64;
        reinterpret_cast<int*>(p)[4] = 0;
        reinterpret_cast<int*>(p)[3] = 0;
        reinterpret_cast<int*>(p)[5] = -1;
        return p;
    }
    return 0;
}

void __cdecl FUN_00a7b300();
struct NiRTTI;
struct NiFile;
struct FUN_00a93750_shell
{
    void* m_pData;
    NiRTTI* m_pRTTI;
    NiFile* m_pFile;
    unsigned int m_nCount;
    void** m_pEntryData;
    void FUN_00a93750();
};
// @fnv 0x00a93750
void FUN_00a93750_shell::FUN_00a93750()
{
    m_pData = &DAT_0109ff64;
    for (unsigned int i = 0; i < m_nCount; ++i)
        ::FUN_00aa10f0(m_pEntryData[i]);
    ::FUN_00aa10f0(m_pEntryData);
    m_pEntryData = 0;
    ((void(*)(void*))FUN_00a7b300)(this);
}


struct NiSwitchStringExtraData
{
    void* FUN_00a938b0(unsigned int flags);
};


// Calls FUN_00a93750, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00a938b0
void* NiSwitchStringExtraData::FUN_00a938b0(unsigned int flags)
{
    static_cast<::FUN_00a93750_shell *>(nullptr)->FUN_00a93750();
    if (flags & 1)
        ::FUN_00aa1460(this, 24);
    return this;
}

extern int DAT_0109f9b4;
struct MM
{
};
struct S_00a918e0
{
    void* f0;
    void* f4;
    void* FUN_00a918e0(unsigned int);
};
// @fnv 0x00a918e0
void* S_00a918e0::FUN_00a918e0(unsigned int auiFlags)
{
    void* v = f4;
    f0 = (void*)&DAT_0109f9b4;
    ::ReleaseObjectArray((::Obj00a47600 **)(v));
    if (auiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

struct StrArr
{
    void* m_pUnknown;
    char** m_pEntryData;
    unsigned short m_uiCapacity;
    unsigned short m_uiSize;
    unsigned short m_uiNonNullCount;
    unsigned short m_uiGrowSize;

};

typedef StrArr A89C70StringArray;

struct A89C70Base
{
};


struct FUN_00a93a60_shell
{
    void* m_pUnknown0;
    void* m_pUnknown1;
    void* m_pUnknown2;
    unsigned int m_uiSize;
    char** m_ppcValue;
    int m_iIndex;

    void FUN_00a93a60(StrArr* apViewerStrings);
};

// Appends viewer strings for the base object, m_uiSize, each m_ppcValue[i] and m_iIndex to the given string array.
// @fnv 0x00a93a60
void FUN_00a93a60_shell::FUN_00a93a60(StrArr* apViewerStrings)
{
    reinterpret_cast<::ExtraDataStrings *>((reinterpret_cast<A89C70Base*>(this)))->FUN_00a7b580(apViewerStrings);

    {
        char* value = ::FUN_00a7d330((const char *)(*(void**)&(*reinterpret_cast<::NiRTTI *>(&::g_011f5eac))));
        unsigned int index = apViewerStrings->m_uiSize;
        if (index >= apViewerStrings->m_uiCapacity)
        {
            reinterpret_cast<::ViewerStrings *>((apViewerStrings))->SetSize(index + apViewerStrings->m_uiGrowSize);
        }
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((apViewerStrings))->SetAt(index, value);

        value = ::FUN_00a7d510("m_uiSize", (unsigned int)(reinterpret_cast<char const*>(m_uiSize)));
        index = apViewerStrings->m_uiSize;
        if (index >= apViewerStrings->m_uiCapacity)
        {
            reinterpret_cast<::ViewerStrings *>((apViewerStrings))->SetSize(index + apViewerStrings->m_uiGrowSize);
        }
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>((apViewerStrings))->SetAt(index, value);

        for (unsigned int i = 0; i < m_uiSize; ++i)
        {
            value = ::fnv_00a7d5e0::FUN_00a7d5e0("m_ppcValue[i]", m_ppcValue[i]);
            index = apViewerStrings->m_uiSize;
            if (index >= apViewerStrings->m_uiCapacity)
            {
                reinterpret_cast<::ViewerStrings *>((apViewerStrings))->SetSize(index + apViewerStrings->m_uiGrowSize);
            }

            if (index >= apViewerStrings->m_uiSize)
            {
                apViewerStrings->m_uiSize = static_cast<unsigned short>(index + 1);
                if (value)
                {
                    ++apViewerStrings->m_uiNonNullCount;
                }
            }
            else
            {
                if (value)
                {
                    if (!apViewerStrings->m_pEntryData[index])
                    {
                        ++apViewerStrings->m_uiNonNullCount;
                    }
                }
                else
                {
                    if (apViewerStrings->m_pEntryData[index])
                    {
                        apViewerStrings->m_uiNonNullCount += static_cast<unsigned short>(0xffff);
                    }
                }
            }
            apViewerStrings->m_pEntryData[index] = value;
        }
    }

    {
        char* value = FUN_00a7d4d0("m_iIndex", m_iIndex);
        unsigned int index = apViewerStrings->m_uiSize;
        if (index >= apViewerStrings->m_uiCapacity)
        {
            reinterpret_cast<::ViewerStrings *>((apViewerStrings))->SetSize(index + apViewerStrings->m_uiGrowSize);
        }

        if (index >= apViewerStrings->m_uiSize)
        {
            apViewerStrings->m_uiSize = static_cast<unsigned short>(index + 1);
            if (value)
            {
                ++apViewerStrings->m_uiNonNullCount;
            }
        }
        else
        {
            if (value)
            {
                if (!apViewerStrings->m_pEntryData[index])
                {
                    ++apViewerStrings->m_uiNonNullCount;
                }
            }
            else
            {
                if (apViewerStrings->m_pEntryData[index])
                {
                    apViewerStrings->m_uiNonNullCount += static_cast<unsigned short>(0xffff);
                }
            }
        }
        apViewerStrings->m_pEntryData[index] = value;
    }
}

class A93680Strings
{
  public:
    bool Equals(A93680Strings* pkOther);

    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiSize;
    char** m_ppcStrings;
    int m_iType;
};

// @fnv 0x00a93680
bool A93680Strings::Equals(A93680Strings* pkOther)
{
    if (!pkOther)
        return false;
    if (m_uiSize != pkOther->m_uiSize)
        return false;
    if (m_iType != pkOther->m_iType)
        return false;
    if ((m_ppcStrings && !pkOther->m_ppcStrings) || (!m_ppcStrings && pkOther->m_ppcStrings))
        return false;
    if (m_ppcStrings)
    {
        for (unsigned int i = 0; i < m_uiSize; i++)
        {
            if ((m_ppcStrings[i] && !pkOther->m_ppcStrings[i]) || (!m_ppcStrings[i] && pkOther->m_ppcStrings[i]))
                return false;
            if (m_ppcStrings[i] && strcmp(m_ppcStrings[i], pkOther->m_ppcStrings[i]) != 0)
                return false;
        }
    }
    return true;
}

struct StrListObj
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    unsigned int m_uiCount;
    char** m_ppStrings;
    int m_iIndex;

    void CopyStringList(StrListObj* dst, void* arg2);
};


// @fnv 0x00a937a0
void StrListObj::CopyStringList(StrListObj* dst, void* arg2)
{
    reinterpret_cast<::FUN_00a7b330_shell *>(this)->FUN_00a7b330((::NiBinaryExtraData *)(dst), (::CloningProcess *)(arg2));
    if (m_ppStrings == 0 || m_uiCount <= 0)
    {
        dst->m_ppStrings = 0;
        dst->m_uiCount = 0;
        return;
    }
    dst->m_uiCount = m_uiCount;
    if (m_iIndex > -1 && m_iIndex < (int)m_uiCount)
    {
        dst->m_iIndex = m_iIndex;
    }
    else
    {
        dst->m_iIndex = -1;
    }
    dst->m_ppStrings = (char**)FUN_00aa1070(m_uiCount * 4);
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        if (m_ppStrings[i] != 0)
        {
            char* p = m_ppStrings[i];
            char* base = p + 1;
            char cChar;
            do
            {
                cChar = *p;
                p++;
            } while (cChar != 0);
            unsigned int uiLen = (unsigned int)(p - base);
            dst->m_ppStrings[i] = (char*)FUN_00aa1070(uiLen + 1);
            fnv::crt::strcpy_s((char *)(dst->m_ppStrings[i]), uiLen + 1, (const char *)(m_ppStrings[i]));
        }
        else
        {
            dst->m_ppStrings[i] = 0;
        }
    }
}

struct NiBinaryStreamView
{
    typedef unsigned int(__cdecl* READFN)(NiBinaryStreamView*, void*, unsigned int, unsigned int*, unsigned int);
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int m_uiBufferSize;
    READFN m_pfnRead;
    __forceinline unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                                          unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

struct NiStreamView
{
    __forceinline NiBinaryStreamView* Input()
    {
        return *reinterpret_cast<NiBinaryStreamView**>(reinterpret_cast<char*>(this) + 0x250);
    }
};

struct NiExtraDataView
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    char* m_pcName;
    unsigned int m_uiNumEntries;
    unsigned int* m_pLinkIds;
    unsigned int m_uiNumLinkIds;
    void LoadFromStream(NiStreamView& kStream);
};

template <class T> __forceinline void NiBinaryStreamLoad(NiBinaryStreamView& is, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    is.BinaryRead(pValue, sizeof(T) * uiNumEls, &uiSize, 1);
}
template <class T> __forceinline void ReadBinaryValue(NiStreamView& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.Input(), &value, 1);
}

// @fnv 0x00a939d0
void NiExtraDataView::LoadFromStream(NiStreamView& kStream)
{
    reinterpret_cast<::FUN_00a7b2c0_shell *>(this)->FUN_00a7b2c0((::NiStream &)(kStream));
    ReadBinaryValue(kStream, m_uiNumEntries);
    for (unsigned int i = 0; i < m_uiNumEntries; ++i)
        reinterpret_cast<::FUN_00a64160_cls *>(&(kStream))->FUN_00a64160((const char *)(m_pLinkIds[i]));
    ReadBinaryValue(kStream, m_uiNumLinkIds);
}

// Uses insights from unverified 2026-10-23 contributor attempt.
extern int DAT_0109ff64;
struct SSE_Node : NiExtraData
{
    void* m_vtbl;
    unsigned int unk04, unk08, unk0C, unk10;
    int unk14;
    SSE_Node() throw()
    {
        reinterpret_cast<::ExtraDataObject *>(this)->FUN_00a7b2e0();
        m_vtbl = &DAT_0109ff64;
        unk10 = 0;
        unk0C = 0;
        unk14 = -1;
    }
};
struct SSE_Owner : NiSwitchStringExtraData
{
    SSE_Node* CreateNode(unsigned int);
};
// @fnv 0x00a938d0
SSE_Node* SSE_Owner::CreateNode(unsigned int arg)
{
    SSE_Node* obj = new SSE_Node;
    reinterpret_cast<::StrListObj *>(this)->CopyStringList((::StrListObj *)(obj), (void *)(arg));
    return obj;
}


class NiBinaryStreamA939
{
  public:
    typedef unsigned int(__cdecl* READFN)(NiBinaryStreamA939* pkThis, void* pvBuffer, unsigned int uiBytes,
                                          unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    READFN m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStreamA939* pkStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    pkStream->BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

class NiObjectA939;

class NiStreamA939
{
  public:
    int unk000[0x24c / 4];
    NiBinaryStreamA939* m_pUnderlyingStream;

};

class NiExtraDataA939
{
  public:
    virtual void vfn_00();
    unsigned int m_uiRefCount;
    char* m_pcName;
};

class LinkArrayExtraA939 : public NiExtraDataA939
{
  public:
    unsigned int m_uiCount;
    NiObjectA939** m_ppkObjects;
    unsigned int m_uiValue1;

    void FUN_00a93930(NiStreamA939& kStream);
};

// Reads m_uiCount, allocates m_ppkObjects and loads each object via kStream, then reads m_uiValue1 from the underlying stream.
// @fnv 0x00a93930
void LinkArrayExtraA939::FUN_00a93930(NiStreamA939& kStream)
{
    reinterpret_cast<::NiExtraData *>(this)->LoadBinary((::NiStream &)(kStream));
    NiBinaryStreamLoad(kStream.m_pUnderlyingStream, &m_uiCount, 1);
    if (m_uiCount > 0)
    {
        m_ppkObjects = (NiObjectA939**)::FUN_00aa1070(m_uiCount * sizeof(NiObjectA939*));
        for (unsigned int i = 0; i < m_uiCount; i++)
            reinterpret_cast<::FUN_00a64ce0_shell *>(&(kStream))->FUN_00a64ce0((char **)(::NiObjectA939 **)(&m_ppkObjects[i]));
    }
    else
    {
        m_ppkObjects = 0;
    }
    NiBinaryStreamLoad(kStream.m_pUnderlyingStream, &m_uiValue1, 1);
}
