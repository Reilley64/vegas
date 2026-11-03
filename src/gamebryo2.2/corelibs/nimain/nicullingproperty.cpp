
// src/gamebryo2.2/corelibs/nimain/nicullingproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nicullingproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include <new>
#include "fnv/decl/FUN_00a5c200.h"
#include "fnv/decl/FUN_00a62a40_this.h"
#include "fnv/decl/NiSingleShaderMaterialLibrary.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a5d000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f5000.h"
struct GlobalObjectO2_00a7b610;

// @fnv 0x00a8f520
GlobalObjectO2_00a7b610* __cdecl FUN_00a8f520()
{
    return &::g_011f5d20;
}

struct BSFadeNode
{
    static void* __cdecl operator new(size_t);
};

struct FUN_00a8fce0_shell
{
};

// Allocates a 0x14-byte BSFadeNode, runs its constructor, and stores the resulting pointer in DAT_011f5e40 (or 0 if allocation fails).
// @fnv 0x00a8fd80
void __cdecl FUN_00a8fd80()
{
    void* p = BSFadeNode::operator new(0x14);
    if (p)
    {
        FUN_00a8fce0_shell* pFadeNode = reinterpret_cast<FUN_00a8fce0_shell*>(p);
        DAT_011f5e40 = (int)((void *)(reinterpret_cast<::NiSingleShaderMaterialLibrary *>((pFadeNode))->FUN_00a8fce0()));
    }
    else
    {
        DAT_011f5e40 = 0;
    }
}

extern int DAT_0109f68c;
class NiStream;
struct NiProperty
{
    NiProperty();
    void* m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    unsigned short m_flags;
public:
    void LoadBinary(::NiStream &);
};
struct CloningProcess
{
    void* m_pCloneMap;
};
struct NiCullingProperty : NiProperty
{
    NiCullingProperty* FUN_00a8f530(CloningProcess& kCloning);
};
// Allocates a NiCullingProperty, initialises its vtable and flags, runs the cloning routine, then copies m_flags and returns it.
// @fnv 0x00a8f530
NiCullingProperty* NiCullingProperty::FUN_00a8f530(CloningProcess& kCloning)
{
    NiCullingProperty* p = static_cast<NiCullingProperty*>(BSFadeNode::operator new(0x1c));
    if (p)
    {
        new ((void *)(p)) struct ::FUN_00a5c200();
        p->m_flags &= 0xfffe;
        p->m_vtbl = &DAT_0109f68c;
    }
    else
        p = 0;
    ::FUN_00a5d7a0();
    p->m_flags = m_flags;
    return p;
}

namespace fnv_00a8f650 {
struct NiBinaryStream
{
    int _0;
    int m_iPos;
    int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct NiStream
{
    char _0[0x24c];
    NiBinaryStream* m_pUnderlyingStream;
};
struct NiProperty
{
    virtual void LoadBinary(NiStream&);
    char _pad[0x14];
};
struct NiCullingProperty : NiProperty
{
    unsigned short m_usFlags;
    void FUN_00a8f650(NiStream&);
};
// Calls NiProperty::LoadBinary then reads 2 bytes from the stream into m_usFlags, advancing the stream position.
// @fnv 0x00a8f650
void NiCullingProperty::FUN_00a8f650(NiStream& stream)
{
    reinterpret_cast<::NiProperty *>(this)->LoadBinary((::NiStream &)(stream));
    NiBinaryStream* __restrict input = stream.m_pUnderlyingStream;
    unsigned int size = 2;
    input->m_iPos += input->m_pfnRead(input, &m_usFlags, 2, &size, 1);
}
}  // namespace fnv_00a8f650

extern void* __cdecl FUN_00aa13e0(unsigned int);
extern int DAT_0109f68c;

struct NiPropertyMem;
struct NiPropertyVTable
{
    void* reserved;
    void(* dispose)(NiPropertyMem*);
};
struct NiPropertyMem
{
    void* vtable;
    volatile long refs;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short flags;

    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
        {
            static_cast<NiPropertyVTable*>(vtable)->dispose(this);
        }
    }
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
};
struct NiPointerProperty
{
    NiPropertyMem* pointer;
    __forceinline void operator=(NiPropertyMem* fresh)
    {
        if (pointer != fresh)
        {
            if (pointer)
                pointer->DecRefCount();
            pointer = fresh;
            if (pointer)
                pointer->IncRefCount();
        }
    }
};
struct GlobalObjectO2_00a7b610
{
    int unk00;
    int unk04;
    NiPointerProperty cullingProperty;
};

// Allocates a NiPropertyMem, initialises it via FUN_00a5c200, clears flag bit 0, sets its vtable, and assigns it to g_011f5d20.cullingProperty.
// @fnv 0x00a8f5b0
void __cdecl CreateCullingProperty()
{
    NiPropertyMem* allocated = static_cast<NiPropertyMem*>(FUN_00aa13e0(sizeof(NiPropertyMem)));
    NiPropertyMem* fresh;
    if (allocated)
    {
        new ((void *)(allocated)) struct ::FUN_00a5c200();
        allocated->flags &= 0xfffe;
        allocated->vtable = &DAT_0109f68c;
        fresh = allocated;
    }
    else
    {
        fresh = 0;
    }
    ::g_011f5d20.cullingProperty = fresh;
}

struct NiRefCountedObj
{
    virtual void v00();
    virtual void Destroy();
    long m_iRefCount;
};


// If the global ref-counted object exists, decrements its reference count, destroys it when the count reaches zero, and clears the global pointer.
// @fnv 0x00a8f620
void __cdecl FUN_00a8f620()
{
    if (DAT_011f5d28 != 0)
    {
        NiRefCountedObj* p = DAT_011f5d28;
        if (InterlockedDecrement(&DAT_011f5d28->m_iRefCount) == 0)
        {
            p->Destroy();
        }
        DAT_011f5d28 = 0;
    }
}

void* __cdecl FUN_00aa1070(unsigned int bytes);

struct FUN_00a7b690
{
    virtual void baseVirtual();
    FUN_00a7b690();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
};

struct FNV_A90A50_ArrayBase
{
    virtual void arrayVirtual();
    void* data;
    unsigned short length;
    unsigned short allocated;
    unsigned short size;
    unsigned short capacity;
    FNV_A90A50_ArrayBase()
    {
        length = 4;
        capacity = 4;
        allocated = 0;
        size = 0;
        data = FUN_00aa1070(16);
    }
};

struct FNV_A90A50_Array : FNV_A90A50_ArrayBase
{
    virtual void arrayVirtual();
    FNV_A90A50_Array()
    {}
};

struct FUN_00a90a50 : FUN_00a7b690
{
    unsigned char unk58;
    unsigned char unk59;
    unsigned short unk5a;
    unsigned int unk5c;
    FNV_A90A50_Array member60;
    virtual void baseVirtual();
    FUN_00a90a50();
};

// Constructor that zero-initialises unk58, unk59 and unk5c and default-constructs the member60 array.
// @fnv 0x00a90a50
FUN_00a90a50::FUN_00a90a50() : unk58(0), unk59(0), unk5c(0)
{}

class BA8F690StringArray
{
  public:
    virtual ~BA8F690StringArray();

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};



class BA8F690Property
{
  public:
    void GetViewerStrings(BA8F690StringArray* pkStrings);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned char m_ucFlags;
};

// Appends the class name and a "bCulled" string derived from bit 0 of m_ucFlags to the viewer string array.
// @fnv 0x00a8f690
void BA8F690Property::GetViewerStrings(BA8F690StringArray* pkStrings)
{
    reinterpret_cast<::FUN_00a62a40_this *>(this)->AppendString((::StrArr *)(pkStrings));
    pkStrings->Add(FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_011f5d20))));
    bool bCulled = (m_ucFlags & 1) != 0;
    pkStrings->Add(FUN_00a7d370("bCulled", bCulled));
}

extern int DAT_0109f68c;
// Allocates a NiProperty, clears the low bit of the 0x18 field, sets the vtable to DAT_0109f68c, and returns it.
// @fnv 0x00a8f580
NiProperty* __cdecl CreateProperty()
{
    NiProperty* pProperty = (NiProperty*)BSFadeNode::operator new(0x1c);
    if (pProperty)
    {
        new (pProperty) NiProperty();
        pProperty->m_flags &= 0xFFFE;
        *(void**)pProperty = (void*)&DAT_0109f68c;
        return pProperty;
    }
    return 0;
}

#include "generated/data/gamebryo2.2/corelibs/nimain/nicullingproperty.inc"
