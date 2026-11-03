// gamebryo2.2/corelibs/nimain/nialphaproperty.cpp: NiAlphaProperty (12 functions)

#include <windows.h>
#include <new>
#include <cstring>
#include "fnv/decl/FUN_00a5c200.h"
#include "fnv/decl/FUN_00a5d450_class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a5c000.h"
#include "fnv/symbols_00a5d000.h"
#include "fnv/symbols_00a62000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/symbols_011f6000.h"
#include "nialphaproperty_decls.h"

// @fnv 0x00a5cf90
void NiAlphaProperty::LoadBinary(NiStream& stream)
{
    NiProperty::LoadBinary(stream);
    if (stream.version < 0x0a000102)
    {
        m_uiObjectFlags = stream.propertyFlags & 0x3fff;
    }
    else
    {
        stream.input->Read(m_uiObjectFlags);
    }
    stream.input->Read(m_ucAlphaThreshold);
}

struct NiObject;
struct EqBase
{
public:
    bool FUN_00a62140(void *);
};
// @fnv 0x00a5cb10
unsigned char IsAlphaPropertyEqual(NiAlphaProperty* self, int, NiObject* pkObject)
{
    NiAlphaProperty* pkAlpha = reinterpret_cast<NiAlphaProperty*>(pkObject);
    return reinterpret_cast<EqBase*>(self)->FUN_00a62140(pkObject) &&
           ((unsigned char)pkAlpha->m_uiObjectFlags & 1) == ((unsigned char)self->m_uiObjectFlags & 1) &&
           (self->m_uiObjectFlags & 0x1e) == (pkAlpha->m_uiObjectFlags & 0x1e) &&
           (self->m_uiObjectFlags & 0x1e0) == (pkAlpha->m_uiObjectFlags & 0x1e0) &&
           ((unsigned char)(self->m_uiObjectFlags >> 9) & 1) == ((unsigned char)(pkAlpha->m_uiObjectFlags >> 9) & 1) &&
           (self->m_uiObjectFlags & 0x1c00) == (pkAlpha->m_uiObjectFlags & 0x1c00) &&
           self->m_ucAlphaThreshold == pkAlpha->m_ucAlphaThreshold &&
           ((unsigned char)(self->m_uiObjectFlags >> 13) & 1) == ((unsigned char)(pkAlpha->m_uiObjectFlags >> 13) & 1);
}

struct RefObj
{
    virtual void Destroy();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};
// If the global RefObj pointer is set, decrements its reference count and clears the pointer.
// @fnv 0x00a5cf60
void FUN_00a5cf60()
{
    if (DAT_011f4410)
    {
        DAT_011f4410->DecRefCount();
        DAT_011f4410 = 0;
    }
}

struct P03MM
{
};
void* _NiMalloc(unsigned int);
struct SdmBase
{
    unsigned int m_uiValueCount;
    void* m_data;
    int m_uiX;
    __forceinline SdmBase(unsigned int n) : m_uiValueCount(n), m_uiX(0)
    {
        m_data = _NiMalloc(0x94);
        std::memset(m_data, 0, m_uiValueCount * 4);
    }
    virtual ~SdmBase()
    {}
};
struct SdmDerived : SdmBase
{
    __forceinline SdmDerived() : SdmBase(0x25)
    {}
    virtual ~SdmDerived()
    {}
};
// Allocates 0x10 bytes, constructs an SdmDerived in place, stores it in DAT_011f5e34 and clears DAT_011f5d30.
// @fnv 0x00a8fa50
void CreateSdmDerived()
{
    void* pStorage = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(0x10);
    if (pStorage)
    {
        SdmDerived* p = new (pStorage) SdmDerived();
        DAT_011f5e34 = p;
        (*reinterpret_cast<bool *>(&::DAT_011f5d30)) = false;
        return;
    }
    DAT_011f5e34 = 0;
    (*reinterpret_cast<bool *>(&::DAT_011f5d30)) = false;
}

struct BSFadeNode
{
};
struct NiPropertyCtorStub
{
};

// Allocates a 0x1c-byte NiAlphaProperty, initialises its vtable and flags, and stores it in DAT_011f4410 with reference counting.
// @fnv 0x00a5cef0
void FUN_00a5cef0()
{
    char* pAlphaProperty = (char*)::operator new(0x1c);
    if (pAlphaProperty)
    {
        new ((void *)(((NiPropertyCtorStub*)pAlphaProperty))) struct ::FUN_00a5c200();
        unsigned short usFlags = 0xec;
        *(const void**)pAlphaProperty = vftable_NiAlphaProperty;
        *(unsigned short*)(pAlphaProperty + 0x18) = usFlags;
        pAlphaProperty[0x1a] = 0;
    }
    else
    {
        pAlphaProperty = 0;
    }

    if (DAT_011f4410 != (RefObj*)pAlphaProperty)
    {
        if (DAT_011f4410)
            DAT_011f4410->DecRefCount();
        DAT_011f4410 = (RefObj*)pAlphaProperty;
        if (pAlphaProperty)
            InterlockedIncrement(&((RefObj*)pAlphaProperty)->m_uiRefCount);
    }
}

struct A51BF0Base
{
};

// @fnv 0x00a5ceb0
NiAlphaProperty* __cdecl CreateNiAlphaProperty()
{
    NiAlphaProperty* p = (NiAlphaProperty*)::operator new(0x1c);
    if (p)
    {
        new ((void *)(((NiPropertyCtorStub*)p))) struct ::FUN_00a5c200();
        p->m_uiObjectFlags = 0xec;
        *(void**)p = vftable_NiAlphaProperty;
        p->m_ucAlphaThreshold = 0;
        return p;
    }
    return 0;
}

class A5D020BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A5D020BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A5D020BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A5D020Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    A5D020BinaryStream* m_pBackingStream;
};

template <class T>
inline void A5D020BinaryStreamSave(A5D020BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A5D020SaveBinary(A5D020Stream& kStream, const T& value)
{
    A5D020BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class A5D020Base
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

};

class A5D020Property : public A5D020Base
{
  public:
    unsigned short m_usFlags;
    unsigned char m_ucMode;

    void SaveToStream(A5D020Stream& kStream);
};

// SaveBinary
// Calls the base save routine, then writes m_usFlags and m_ucMode to the stream.
// @fnv 0x00a5d020
void A5D020Property::SaveToStream(A5D020Stream& kStream)
{
    ::FUN_00a5d7b0();
    A5D020SaveBinary(kStream, m_usFlags);
    A5D020SaveBinary(kStream, m_ucMode);
}

struct GlobalObjectO2_00a7b610
{
    const char* m_name;
};


struct StrArr
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usAlloced;
    unsigned short unk0C;
    unsigned short m_usGrowBy;


    unsigned int Add(char* pcElement)
    {
        unsigned int uiAlloced = m_usAlloced;
        unsigned int uiMaxSize = m_usMaxSize;
        if (uiAlloced >= uiMaxSize)
        {
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiAlloced + m_usGrowBy);
        }
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiAlloced, pcElement);
        return uiAlloced;
    }
};

class FUN_00a62a40_this : public A5D020Base
{
  public:
    void AppendString(StrArr* pkStrings);
};

class A5D080Property : public FUN_00a62a40_this
{
  public:
    unsigned short m_usFlags;
    unsigned char m_ucAlphaThreshold;

    bool GetAlphaBlending() const
    {
        return (m_usFlags & 1) != 0;
    }
    unsigned int GetSrcBlend() const
    {
        return (m_usFlags >> 1) & 0xF;
    }
    unsigned int GetDestBlend() const
    {
        return (m_usFlags >> 5) & 0xF;
    }
    bool GetAlphaTesting() const
    {
        return (m_usFlags >> 9) & 1;
    }
    unsigned int GetTestMode() const
    {
        return (m_usFlags >> 10) & 7;
    }
    unsigned char GetTestRef() const
    {
        return m_ucAlphaThreshold;
    }
    bool GetNoSorter() const
    {
        return (m_usFlags >> 13) & 1;
    }

    void AppendPropertyStrings(StrArr* pkStrings);
};

// Appends the base class strings plus formatted alpha, blend, test and sorter property strings to pkStrings.
// @fnv 0x00a5d080
void A5D080Property::AppendPropertyStrings(StrArr* pkStrings)
{
    FUN_00a62a40_this::AppendString(pkStrings);
    pkStrings->Add(FUN_00a7d330(::g_011f4408.m_name));
    pkStrings->Add(FUN_00a7d370("m_bAlpha", GetAlphaBlending()));
    pkStrings->Add(::GetAlphaBlendFuncName("m_eSrcBlend", GetSrcBlend()));
    pkStrings->Add(::GetAlphaBlendFuncName("m_eDestBlend", GetDestBlend()));
    pkStrings->Add(FUN_00a7d370("m_bAlphaTest", GetAlphaTesting()));
    pkStrings->Add(::FormatTestCondition("m_eTestMode", GetTestMode()));
    pkStrings->Add(FUN_00a7d410("m_ucTestRef", GetTestRef()));
    pkStrings->Add(FUN_00a7d370("m_bNoSorter", GetNoSorter()));
}


// @fnv 0x00a99e40
void __cdecl FUN_00a99e40()
{
    ::FUN_00a62130({}, {}, {});
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct S00a5ce30_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short unk18;
    unsigned char unk1a;
    S00a5ce30_cls* FUN_00a5ce30(int a0);
};

// @fnv 0x00a5ce30
S00a5ce30_cls* S00a5ce30_cls::FUN_00a5ce30(int a0)
{
    if (unk0c == 0 && (*reinterpret_cast<char *>(&::treeCloneActive)) == 0)
    {
        reinterpret_cast<::FUN_00a5d450_class *>((this))->CreateVertexBufferSet(a0, {});
        return this;
    }
    S00a5ce30_cls* n = (S00a5ce30_cls*)FUN_00aa13e0(0x1c);
    if (n)
    {
        new ((void *)(n)) struct ::FUN_00a5c200();
        *(int**)n = &(*reinterpret_cast<int *>(&::vftable_NiAlphaProperty));
        n->unk18 = 0xec;
        n->unk1a = 0;
    }
    else
    {
        n = 0;
    }
    ::FUN_00a5d7a0();
    n->unk18 = unk18;
    n->unk1a = unk1a;
    return n;
}

#include <string.h>

// Allocates a string and formats it as "pcPrefix = ALPHA_..." based on the eFunc index, returning the new string.
// @fnv 0x00a5cb90
char* GetAlphaBlendFuncName(const char* pcPrefix, int aiFuncIndex)
{
    char* pcString;
    unsigned int uiPrefixLen = (unsigned int)strlen(pcPrefix);

    pcString = (char*)_NiMalloc(uiPrefixLen + 0x16);

    switch (aiFuncIndex)
    {
    case 0:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_ONE", pcPrefix);
        break;
    case 1:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_ZERO", pcPrefix);
        break;
    case 2:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_SRCCOLOR", pcPrefix);
        break;
    case 3:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_INVSRCCOLOR", pcPrefix);
        break;
    case 4:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_DESTCOLOR", pcPrefix);
        break;
    case 5:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_INVDESTCOLOR", pcPrefix);
        break;
    case 6:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_SRCALPHA", pcPrefix);
        break;
    case 7:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_INVSRCALPHA", pcPrefix);
        break;
    case 8:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_DESTALPHA", pcPrefix);
        break;
    case 9:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_INVDESTALPHA", pcPrefix);
        break;
    case 10:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = ALPHA_SRCALPHASAT", pcPrefix);
        break;
    default:
        ::NiSprintf(pcString, uiPrefixLen + 0x16, "%s = UNKNOWN!!!", pcPrefix);
        break;
    }

    return pcString;
}


// Allocates a buffer and formats a string like "name = TEST_LESS" based on the test code, returning the buffer.
// @fnv 0x00a5cd00
char* FormatTestCondition(const char* name, int test)
{
    unsigned int length = (unsigned int)strlen(name);
    unsigned int size = length + 0x16;
    char* buffer = (char*)_NiMalloc(size);

    switch (test)
    {
    case 0:
        ::NiSprintf(buffer, size, "%s = TEST_ALWAYS", name);
        break;
    case 1:
        ::NiSprintf(buffer, size, "%s = TEST_LESS", name);
        break;
    case 2:
        ::NiSprintf(buffer, size, "%s = TEST_EQUAL", name);
        break;
    case 3:
        ::NiSprintf(buffer, size, "%s = TEST_LESSEQUAL", name);
        break;
    case 4:
        ::NiSprintf(buffer, size, "%s = TEST_GREATER", name);
        break;
    case 5:
        ::NiSprintf(buffer, size, "%s = TEST_NOTEQUAL", name);
        break;
    case 6:
        ::NiSprintf(buffer, size, "%s = TEST_GREATEREQUAL", name);
        break;
    case 7:
        ::NiSprintf(buffer, size, "%s = TEST_NEVER", name);
        break;
    default:
        ::NiSprintf(buffer, size, "%s = UNKNOWN!!!", name);
        break;
    }

    return buffer;
}

#include "generated/data/gamebryo2.2/corelibs/nimain/nialphaproperty.inc"
