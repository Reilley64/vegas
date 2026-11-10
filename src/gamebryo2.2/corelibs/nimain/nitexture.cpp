// gamebryo2.2/corelibs/nimain/nitexture.cpp: NiObjectNET, NiTexture, Elements (13 functions)

#include "fnv/symbols_00a47000.h"
#include <cstdint>
#include <new>
#include "fnv/decl/FUN_00a5c200.h"
#include "fnv/decl/FUN_00a5c240_shell.h"
#include "fnv/decl/GeomData.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/S.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a62000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f5000.h"
#include "fnv/symbols_011f6000.h"
#include "nitexture_match.h"

// Removes the extra-data entry at index under a critical section, releasing its reference and shifting the remaining entries down.
// @fnv 0x00a5b990
void NiObjectNET::DeleteExtraData(unsigned short index)
{
    fnv_EnterCriticalSection(&(*reinterpret_cast<unsigned char *>(&::DAT_011f4380)));
    if (index >= m_usExtraDataCount)
    {
        fnv_LeaveCriticalSection(&(*reinterpret_cast<unsigned char *>(&::DAT_011f4380)));
        return;
    }

    if (m_ppExtraData[index])
    {
        NiExtraData* extra = m_ppExtraData[index];
        if (InterlockedDecrement(&extra->m_uiRefCount) == 0)
            extra->DeleteThis();
    }

    for (unsigned short i = index; i < m_usExtraDataCount - 1; ++i)
        m_ppExtraData[i] = m_ppExtraData[i + 1];
    --m_usExtraDataCount;
    m_ppExtraData[m_usExtraDataCount] = 0;
    fnv_LeaveCriticalSection(&(*reinterpret_cast<unsigned char *>(&::DAT_011f4380)));
}

// @fnv 0x00a47350
void NiTexture::LoadBinary(NiStream& stream)
{
    NiObjectNET::LoadBinary(stream);
}

extern int DAT_010983bc;

class BSFadeNode
{
  public:
};

class NiProperty : public BSFadeNode
{
  public:
    NiProperty();
    char pad[0x18];
};

// Allocates a 0x18-byte NiProperty, runs its constructor, installs the vtable at DAT_010983bc, and returns it (or null on allocation failure).
// @fnv 0x00a47380
void* __cdecl FUN_00a47380()
{
    NiProperty* p = (NiProperty*)::operator new(0x18);
    if (p)
    {
        new ((void *)(p)) struct ::FUN_00a5c200();
        *(int**)p = &DAT_010983bc;
        return p;
    }
    return 0;
}

struct MemoryManager
{
};

struct Pool00a91290
{
    int a, b, c, d, e, f;
};


// Allocates a Pool00a91290, zeroes its first four fields, sets the last two to 8, and stores it in DAT_011f5e50 (or null on failure).
// @fnv 0x00a91290
void __cdecl FUN_00a91290()
{
    Pool00a91290* p = (Pool00a91290*)reinterpret_cast<::MemoryManagerStandIn *>(&(g_memoryManager))->FUN_00aa3e40(sizeof(Pool00a91290));
    if (p)
    {
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        p->e = 8;
        p->f = 8;
        DAT_011f5e50 = p;
        return;
    }
    DAT_011f5e50 = 0;
}

struct GlobalObjectO2_00a7b610;
// Returns a pointer to the global object g_011f3f38, ignoring both arguments.
// @fnv 0x00a47370
GlobalObjectO2_00a7b610* FUN_00a47370(void*, int)
{
    return &::g_011f3f38;
}

// @fnv 0x00a473b0
void* FUN_00a473b0(void* self, int, unsigned int flags)
{
    reinterpret_cast<::FUN_00a5c240_shell *>((self))->DestroyFogProperty();
    if (flags & 1)
        ::FUN_00aa1460(self, 0x18);
    return self;
}

struct ActorCombatGroup;
template <class T> class NiTMallocInterface
{
};
template <class T, class A> class NiTArray
{
  public:
    void* m_vtbl;
    unsigned int m_pad4;
    unsigned short m_usMaxSize;
    unsigned short m_usESize;
    unsigned short m_usPadC;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
typedef NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> > CGArray;
struct FUN_00a62a40_this
{
};
// @fnv 0x00a62a40
void FUN_00a62a40(FUN_00a62a40_this* self, int, CGArray* apArray)
{
    reinterpret_cast<::S *>((self))->FUN_00a5ca80((::StrArray *)(apArray));
    ActorCombatGroup* pEntry = ((::ActorCombatGroup *)(::FUN_00a7d330((*reinterpret_cast<const char *const *>(&::g_011f450c)))));
    unsigned int n = apArray->m_usESize;
    if (n >= apArray->m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>((apArray))->SetSize(n + apArray->m_usGrowBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((apArray))->SetAt(n, (char *&)(pEntry));
    unsigned char* st = *reinterpret_cast<unsigned char**>(reinterpret_cast<unsigned char*>(self) + 0x24);
    pEntry = ((::ActorCombatGroup *)(::FUN_00a7d4d0("State", st ? st[0x5b] : 0)));
    n = apArray->m_usESize;
    if (n >= apArray->m_usMaxSize)
        reinterpret_cast<::ViewerStrings *>((apArray))->SetSize(n + apArray->m_usGrowBy);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((apArray))->SetAt(n, (char *&)(pEntry));
}

struct TexInfo
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    char m_c14;
    char m_c15;
    int m_i18;
};

class FUN_00a62670_cls
{
  public:
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    TexInfo* m_pObjectInfo;
    int FUN_00a62670();
};

// @fnv 0x00a62670
int FUN_00a62670_cls::FUN_00a62670()
{
    unsigned int result = 0;
    if (m_pObjectInfo != 0)
    {
        result = (unsigned char)m_pObjectInfo->m_c15;
        result >>= 3;
        result *= (unsigned int)m_pObjectInfo->m_i10;
        result *= (unsigned int)m_pObjectInfo->m_i0C;
    }
    return (int)result;
}

// Lazy-initialised dispatch to the cached handler routine.
// The handler pointer is stored in a global slot on first use.
typedef int(__cdecl* DispatchFn)(int, int);

extern DispatchFn DAT_011a9600;
extern int GetTextureForType(int, int);

// Returns 0 when a2's high bit is clear; otherwise lazily installs GetTextureForType as DAT_011a9600 and calls it with a1 and a2.
// @fnv 0x00a62a10
int __cdecl DispatchIfHighBitSet(int a1, int a2, int aUnused)
{
    if ((a2 & 0x80000000u) == 0)
        return 0;

    if (!DAT_011a9600)
        DAT_011a9600 = GetTextureForType;
    return DAT_011a9600(a1, a2);
}

struct TextureColor
{
    float r, g, b, a;
    TextureColor()
    {}
    TextureColor(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha)
    {}
};
struct TextureCacheEntry
{
    int value;
    void FUN_00a5f860(intptr_t);
};
// Looks up a cached texture for a type index, generating it from per-type color pairs via CreateCheckerboardTexture when not yet cached, and returns the cached value.
// @fnv 0x00a62690
int GetTextureForType(int unused, int type)
{
    unsigned int index = (unsigned int)type & 0x7fffffff;
    if (index >= 10)
        return 0;
    unsigned int mode = 1;
    if (!(*reinterpret_cast<TextureCacheEntry (*)[10]>(&::g_aspObjects_11f4514))[index].value)
    {
        TextureColor firstColor, secondColor;
        switch (type)
        {
        default:
            firstColor = TextureColor(1.0f, 0.0f, 1.0f, 1.0f);
            secondColor = TextureColor(1.0f, 0.0f, 1.0f, 1.0f);
            break;
        case (int)0x80000001u:
            firstColor = TextureColor(0.0f, 0.0f, 1.0f, 1.0f);
            secondColor = TextureColor(1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case (int)0x80000002u:
            firstColor = TextureColor(0.0f, 1.0f, 0.0f, 1.0f);
            secondColor = TextureColor(1.0f, 0.0f, 0.0f, 1.0f);
            mode = 6;
            break;
        case (int)0x80000003u:
            firstColor = TextureColor(0.0f, 1.0f, 1.0f, 1.0f);
            secondColor = TextureColor(1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case (int)0x80000004u:
            firstColor = TextureColor(1.0f, 0.0f, 0.0f, 1.0f);
            secondColor = TextureColor(1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case (int)0x80000006u:
            firstColor = TextureColor(0.0f, 1.0f, 1.0f, 1.0f);
            secondColor = TextureColor(0.0f, 1.0f, 1.0f, 1.0f);
            break;
        case (int)0x80000007u:
            firstColor = TextureColor(0.0f, 1.0f, 0.0f, 1.0f);
            secondColor = TextureColor(1.0f, 1.0f, 0.0f, 1.0f);
            mode = 6;
            break;
        case (int)0x80000008u:
            firstColor = TextureColor(0.0f, 1.0f, 0.0f, 1.0f);
            secondColor = TextureColor(1.0f, 0.0f, 1.0f, 1.0f);
            mode = 6;
            break;
        case (int)0x80000009u:
            firstColor = TextureColor(0.0f, 1.0f, 0.0f, 1.0f);
            secondColor = TextureColor(0.0f, 1.0f, 1.0f, 1.0f);
            mode = 6;
            break;
        }
        (*reinterpret_cast<TextureCacheEntry (*)[10]>(&::g_aspObjects_11f4514))[index].FUN_00a5f860(((intptr_t)(::CreateCheckerboardTexture((*(const ::CheckerColor *)(&firstColor)), (*(const ::CheckerColor *)(&secondColor)), (*(const ::NiPixelFormat *)((*reinterpret_cast<const char (*)[]>(&::gNiPoint3StartupDst)))), mode))));
    }
    return (*reinterpret_cast<TextureCacheEntry (*)[10]>(&::g_aspObjects_11f4514))[index].value;
}

// @fnv 0x00a47360
void FUN_00a47360_shell::FUN_00a47360(::NiStream& kStream)
{
    reinterpret_cast<::NiObjectNET *>(this)->LinkObject(kStream);
}

struct FUN_00a62660_cls
{
    int unk00;
    int unk04;
    int m_08;
    const int& FUN_00a62660();
};

// @fnv 0x00a62660
const int& FUN_00a62660_cls::FUN_00a62660()
{
    return m_08;
}

namespace sa912d0 {

template <class T> class ViewerArray
{
  public:
    void FUN_0096ad30(unsigned int uiMaxSize);
    void FUN_0096ae90(unsigned int uiIndex, const T& element);

    unsigned int Add(const T& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(element));
        return uiIndex;
    }

    void* m_pvVtable;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
typedef ViewerArray<char*> ViewerStrings;


class ElementsBase
{
  public:
};

class Elements : public ElementsBase
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    bool m_bPixelAccurate;
    unsigned char unk059;
    unsigned char unk05a;
    unsigned char unk05b;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    unsigned short m_usNumElements;

    void FUN_00a912d0(ViewerStrings* pkStrings);
};

// Calls base RegisterFields, then adds class name, m_bPixelAccurate, and m_usNumElements to pkStrings.
// @fnv 0x00a912d0
void Elements::FUN_00a912d0(ViewerStrings* pkStrings)
{
    reinterpret_cast<::GeomData *>(this)->RegisterFields((::StrArr *)(pkStrings));
    pkStrings->Add(::FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_011f5e54))));
    pkStrings->Add(::FUN_00a7d370("m_bPixelAccurate", m_bPixelAccurate));
    unsigned int n = m_usNumElements;
    pkStrings->Add(::FUN_00a7d510("Num Elements", n));
}

}

#include "generated/data/gamebryo2.2/corelibs/nimain/nitexture.inc"
