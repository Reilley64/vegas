
// src/gamebryo2.2/corelibs/nimain/niintegersextradata_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niintegersextradata.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include <cstdint>
#include "fnv/decl/ExtraDataObject.h"
#include "fnv/decl/ExtraDataStrings.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/FUN_00a99800_shell.h"
#include "fnv/decl/FUN_00c545d0_cls.h"
#include "fnv/decl/FUN_00c54b70_cls.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_010a0000.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/symbols_01203000.h"
#include "niintegersextradata_decls.h"
struct NiFixedString
{
};
struct NiAVObject
{
};
extern NiFixedString* DAT_012031c0;
struct FUN_00c543e0_shell : NiAVObject
{
    void FUN_00c543e0();
};
struct FUN_00c54d60_shell
{
    int* FUN_00c54d60();
};
struct FUN_00c54030_shell
{
    int FUN_00c54030(int param_1);
};


// @fnv 0x00a99940
char const* const* __cdecl FUN_00a99940()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f5f24));
}

struct FUN_00a7b300_shell
{
    void FUN_00a7b300();
};
struct FUN_00a99950_shell
{
    int vtbl;
    int f04;
    int f08;
    int f0c;
    int f10;
    void FUN_00a99950();
};
// @fnv 0x00a99950
void FUN_00a99950_shell::FUN_00a99950()
{
    void* p = *(void**)((char*)this + 0x10);
    *(intptr_t*)this = (intptr_t)&(*reinterpret_cast<int *>(&::fnv_00a99a50::DAT_010a0c7c));
    ::FUN_00aa10f0(p);
    this->f10 = 0;
    ((FUN_00a7b300_shell*)this)->FUN_00a7b300();
}

struct PB_00a7b2e0
{
};
struct PB_00a99800
{
};
struct ST_00a99980 : NiExtraData
{
    ST_00a99980* FUN_00a99980(int a, intptr_t b);
};
// @fnv 0x00a99980
ST_00a99980* ST_00a99980::FUN_00a99980(int a, intptr_t b)
{
    reinterpret_cast<::ExtraDataObject *>((((PB_00a7b2e0*)this)))->FUN_00a7b2e0();
    *(intptr_t*)this = (intptr_t)&(*reinterpret_cast<int *>(&::fnv_00a99a50::DAT_010a0c7c));
    *(int*)((char*)this + 0x10) = 0;
    reinterpret_cast<::FUN_00a99800_shell *>((((PB_00a99800*)this)))->AssignPointerArray(a, (const void *)(b));
    return this;
}

struct BSFadeNode
{
    static void* operator new(size_t);
};
struct NiExtraDataShell : NiExtraData
{
};
// @fnv 0x00a99a10
NiExtraData* FUN_00a99a10()
{
    NiExtraData* data = static_cast<NiExtraData*>(BSFadeNode::operator new(0x14));
    if (data)
    {
        reinterpret_cast<::ExtraDataObject *>((static_cast<NiExtraDataShell*>(data)))->FUN_00a7b2e0();
        data->baseData[0] = reinterpret_cast<uintptr_t>(&(*reinterpret_cast<int *>(&::fnv_00a99a50::DAT_010a0c7c)));
        data->baseData[4] = 0;
        data->baseData[3] = 0;
        return data;
    }
    return 0;
}

namespace fnv_00a99a50 {
void __cdecl FUN_00a7b300();
struct FUN_00a99a50_shell
{
    intptr_t vtbl;
    int a;
    int b;
    int c;
    intptr_t d;
    void FUN_00a7b300();
    FUN_00a99a50_shell* FUN_00a99a50(int);
    void __cdecl operator delete(void* p, size_t);
};
// @fnv 0x00a99a50
FUN_00a99a50_shell* FUN_00a99a50_shell::FUN_00a99a50(int flag)
{
    vtbl = (intptr_t)&DAT_010a0c7c;
    ::FUN_00aa10f0((void*)d);
    d = 0;
    reinterpret_cast<::FUN_00a7b300_shell *>(this)->FUN_00a7b300();
    if (flag & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}
}  // namespace fnv_00a99a50

struct Extra_00a998e0
{
    unsigned char _pad0[12];
    unsigned int m_uiSize;
    int* m_piValue;
    bool FUN_00a998e0(Extra_00a998e0* pObject);
};
// @fnv 0x00a998e0
bool Extra_00a998e0::FUN_00a998e0(Extra_00a998e0* pObject)
{
    Extra_00a998e0* pExtra = pObject;
    unsigned int i;
    if (!pExtra)
        return false;
    if (m_uiSize != pExtra->m_uiSize)
        return false;
    if (m_piValue && !pExtra->m_piValue)
        return false;
    if (!m_piValue && pExtra->m_piValue)
        return false;
    if (m_piValue)
    {
        for (i = 0; i < m_uiSize; i++)
        {
            if (m_piValue[i] != pExtra->m_piValue[i])
                return false;
        }
    }
    return true;
}

struct FUN_00a99870_shell : public NiExtraData
{
    unsigned int m_uiSize;
    int* m_piValue;
    void FUN_00a99870(FUN_00a99870_shell* pDest, void* pCloning);
};
// @fnv 0x00a99870
void FUN_00a99870_shell::FUN_00a99870(FUN_00a99870_shell* pDest, void* pCloning)
{
    reinterpret_cast<::FUN_00a7b330_shell *>(this)->FUN_00a7b330((::NiBinaryExtraData *)(pDest), (::CloningProcess *)(pCloning));
    if (m_piValue && m_uiSize > 0)
    {
        pDest->m_uiSize = m_uiSize;
        pDest->m_piValue = (int*)::FUN_00aa1070(m_uiSize * 4);
        for (unsigned int i = 0; i < m_uiSize; ++i)
            pDest->m_piValue[i] = m_piValue[i];
    }
    else
    {
        pDest->m_piValue = 0;
        pDest->m_uiSize = 0;
    }
}

template <class T> class NiTPrimitiveArray
{
  public:
    void* m_ppVirtualMethodTable;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    inline void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element)
                m_usESize++;
        }
        else if (element)
        {
            if (!m_pBase[uiIndex])
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex])
                m_usESize--;
        }
        m_pBase[uiIndex] = element;
    }
    inline unsigned int Add(const T& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }
};

typedef NiTPrimitiveArray<char*> NiViewerStringsArray;



struct NiIntegersExtraDataView : NiExtraData
{
    unsigned int m_uiSize;
    int* m_piValue;
    void FUN_00a99b20(NiViewerStringsArray* pkStrings);
};

// @fnv 0x00a99b20
void NiIntegersExtraDataView::FUN_00a99b20(NiViewerStringsArray* pkStrings)
{
    reinterpret_cast<::ExtraDataStrings *>(this)->FUN_00a7b580((::StrArr *)(pkStrings));
    pkStrings->Add(::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_011f5f24))));
    pkStrings->Add(::FUN_00a7d510("m_uiSize", m_uiSize));
    for (unsigned int i = 0; i < m_uiSize; i++)
        pkStrings->Add(::FUN_00a7d4d0("m_piValue[i]", m_piValue[i]));
}

class NiPSysBaseA99
{
  public:
    NiPSysBaseA99() throw();
    virtual ~NiPSysBaseA99();

    static void* operator new(size_t uiSize);
    static void operator delete(void* pvMem);

    int unk04, unk08;
};

class NiPSysDerivedA99 : public NiPSysBaseA99
{
  public:
    NiPSysDerivedA99() throw()
    {
        m_pkSecond = 0;
        m_pkFirst = 0;
    }
    virtual ~NiPSysDerivedA99();

    void* m_pkFirst;
    void* m_pkSecond;
};

class NiPSysOwnerA99
{
  public:
    NiPSysBaseA99* FUN_00a999b0(void* pvProcess);
};

// @fnv 0x00a999b0
NiPSysBaseA99* NiPSysOwnerA99::FUN_00a999b0(void* pvProcess)
{
    NiPSysDerivedA99* pkClone = new NiPSysDerivedA99;
    reinterpret_cast<::FUN_00a99870_shell *>(this)->FUN_00a99870((::FUN_00a99870_shell *)(pkClone), pvProcess);
    return pkClone;
}
