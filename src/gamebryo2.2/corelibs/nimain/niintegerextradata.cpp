// gamebryo2.2/corelibs/nimain/niintegerextradata.cpp: NiIntegerExtraData, ExtraDataOwner (7 functions)

#include <new>
#include "fnv/decl/ExtraDataObject.h"
#include "fnv/decl/ExtraDataStrings.h"
#include "fnv/decl/FUN_00a7b300_shell.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_010a0000.h"
#include "fnv/symbols_011f5000.h"
#include "niintegerextradata_decls.h"
// Calls NiExtraData::LoadBinary then reads m_iValue from the stream.
// @fnv 0x00a99d30
void NiIntegerExtraData::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    stream.m_pUnderlyingStream->Read(&m_iValue);
}


// @fnv 0x00a99c60
char const* const* __cdecl FUN_00a99c60()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f5f2c));
}


struct FUN_00a99c70_shell
{
    int* m_val;
    void FUN_00a99c70();
};

// @fnv 0x00a99c70
void FUN_00a99c70_shell::FUN_00a99c70()
{
    m_val = &DAT_010a0d24;
    static_cast<::FUN_00a7b300_shell *>(nullptr)->FUN_00a7b300();
}

struct BSFadeNode
{
};

struct NiExtraDataShell : NiExtraData
{
};

// @fnv 0x00a99cd0
NiExtraData* FUN_00a99cd0()
{
    NiExtraData* pExtraData = static_cast<NiExtraData*>(::operator new(0x10));
    if (pExtraData)
    {
        reinterpret_cast<::ExtraDataObject *>((static_cast<NiExtraDataShell*>(pExtraData)))->FUN_00a7b2e0();
        *reinterpret_cast<int**>(pExtraData) = &DAT_010a0d24;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(pExtraData) + 0xc) = 0;
        return pExtraData;
    }
    return 0;
}

struct FUN_00a99d00_shell
{
    void* Destroy(unsigned int);
};
// @fnv 0x00a99d00
void* FUN_00a99d00_shell::Destroy(unsigned int auiFlags)
{
    *(int**)this = &DAT_010a0d24;
    static_cast<::FUN_00a7b300_shell *>(nullptr)->FUN_00a7b300();
    if (auiFlags & 1)
        ::operator delete(this, 0x10);
    return this;
}

struct StrArr
{
    unsigned char m_pad00[8];
    unsigned short m_uiCapacity;
    unsigned short m_uiSize;
    unsigned char m_pad0C[2];
    unsigned short m_uiGrowSize;

};

struct A89C70StringArray : StrArr
{
};

struct A89C70Base
{
};


struct FUN_00a99d70_shell
{
    void FUN_00a99d70(A89C70StringArray*);
};

// Appends the base viewer strings plus a formatted "m_iValue" entry to the string array, growing it as needed.
// @fnv 0x00a99d70
void FUN_00a99d70_shell::FUN_00a99d70(A89C70StringArray* apViewerStrings)
{
    reinterpret_cast<::ExtraDataStrings *>((reinterpret_cast<A89C70Base*>(this)))->FUN_00a7b580((::StrArr *)(apViewerStrings));

    char* pString = static_cast<char*>(((void *)(::FUN_00a7d330((const char *)(void *)(const_cast<char*>((*reinterpret_cast<const char *const *>(&::g_011f5f2c))))))));

    unsigned int index = apViewerStrings->m_uiSize;
    if (index >= apViewerStrings->m_uiCapacity)
        reinterpret_cast<::ViewerStrings *>((apViewerStrings))->SetSize(index + apViewerStrings->m_uiGrowSize);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((apViewerStrings))->SetAt(index, pString);

    pString = FUN_00a7d4d0("m_iValue", *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x0c));

    index = apViewerStrings->m_uiSize;
    if (index >= apViewerStrings->m_uiCapacity)
        reinterpret_cast<::ViewerStrings *>((apViewerStrings))->SetSize(index + apViewerStrings->m_uiGrowSize);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((apViewerStrings))->SetAt(index, pString);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
struct ExtraDataOwner
{
    int unk00;
    int unk04;
    int unk08;
    int m_iValue;
    NiIntegerExtraData* CreateIntegerExtraData(unsigned int);
};
// @fnv 0x00a99c80
NiIntegerExtraData* ExtraDataOwner::CreateIntegerExtraData(unsigned int argument)
{
    NiIntegerExtraData* result;
    NiIntegerExtraData* allocated = (NiIntegerExtraData*)FUN_00aa13e0(16);
    if (allocated != 0)
    {
        reinterpret_cast<::ExtraDataObject *>((((NiExtraDataShell*)allocated)))->FUN_00a7b2e0();
        *(void**)allocated = &DAT_010a0d24;
        allocated->m_iValue = 0;
        result = allocated;
    }
    else
    {
        result = 0;
    }
    reinterpret_cast<::FUN_00a7b330_shell *>(this)->FUN_00a7b330((::NiBinaryExtraData *)(result), (::CloningProcess *)(argument));
    result->m_iValue = m_iValue;
    return result;
}
