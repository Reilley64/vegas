
// MSVC 2008 cl does not accept the .inl extension as a source file, so this identical unit is compiled as .cpp by the matcher; the .inl is the source of record.
//
//
// gamebryo2.2/corelibs/nicollision/niunionbv.inl
//
// Inline definitions for NiD3DShaderProgram: Nivid3D shader program
// wrappers over D3D9 GPU programs. A program object owns the compiled
// code block and the creator/device handles that produced it; the
// accessors below read out the stored descriptors.
//
// Standalone build: base chain sizes taken from the MSVC 2008 layout
// evidence - NiGPUProgram is 12 bytes and NiD3DShaderProgram is 44
// bytes, with m_uiProgramCodeSize at offset 20.
//

#include <cstdint>
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_00aa1000.h"
#include <cstring>
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/S_00e9cb10_Obj.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a30000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00e9c000.h"
#include <new>
typedef unsigned int NiUInt32;

class NiMemObject
{
};

class NiRefObject : public NiMemObject
{
  public:
    NiRefObject() : m_uiRefCount(0)
    {}

    virtual ~NiRefObject()
    {}

    virtual void DeleteThis()
    {
        delete this;
    }

  protected:
    NiUInt32 m_uiRefCount;
};

class NiGPUProgram : public NiRefObject
{
  public:
    enum ProgramType
    {
        PROGRAMTYPE_INVALID,
        PROGRAMTYPE_VERTEX,
        PROGRAMTYPE_PIXEL
    };

    ProgramType GetProgramType()
    {
        return m_iProgramType;
    }

  protected:
    ProgramType m_iProgramType;
};

class NiD3DShaderProgramCreator;
class Direct3DDeviceInterface;
class NiD3DRenderer;
class NiD3DRenderState;

class NiD3DShaderProgram : public NiGPUProgram
{
  public:
    NiUInt32 GetCodeSize() const;

  protected:
    char* m_pcProgramName;
    char* m_pcProfile;
    NiUInt32 m_uiProgramCodeSize;
    void* m_pProgramCode;
    NiD3DShaderProgramCreator* m_pCreator;
    Direct3DDeviceInterface* m_pD3DDevice;
    NiD3DRenderer* m_pShaderObject;
    NiD3DRenderState* m_pRenderState;
};

// @fnv 0x0DBBC10
NiUInt32 NiD3DShaderProgram::GetCodeSize() const
{
    return m_uiProgramCodeSize;
}

struct P03MM
{
public:
    void* Allocate(unsigned int);
};
struct S
{
    S* FUN_00e9ee60(void*);
};
// @fnv 0x00e9efb0
S* FUN_00e9efb0(void* self)
{
    S* p = (S*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(0x18);
    if (p)
        return p->FUN_00e9ee60(self);
    return 0;
}

// FUN_00e9ecc0 - 6-byte leaf stub of the retail binary.
//
// The original code is "mov eax, 4 ; ret": the function simply hands the
// constant 4 back to its caller.  A plain "return 4;" is folded by VC9 at the
// pack's /O1 into the shorter "push 4 ; pop eax ; ret" sequence, so the value
// is materialised from a relocated address expression instead.  That keeps
// the original six-byte "mov eax, <imm32> ; ret" shape byte for byte.
extern int g_fnv_00e9ecc0_value_anchor;

// @fnv 0x00e9ecc0
intptr_t FUN_00e9ecc0()
{
    return (intptr_t)(&g_fnv_00e9ecc0_value_anchor) + 4;
}

#pragma optimize("gty", on)
class S00e9e860_Item
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void Delete(unsigned char acFlags);
};

class S00e9e860_Obj
{
  public:
    int unk00;
    int unk04;
    S00e9e860_Item** m_ppItems;
    unsigned short unk0c;
    unsigned short m_uCount;
    unsigned short m_u10;
    void FUN_00e9e860();
};

// Deletes each item in m_ppItems, nulls the pointers, and resets m_uCount and m_u10 to zero.
// @fnv 0x00e9e860
void S00e9e860_Obj::FUN_00e9e860()
{
    {
        unsigned int iIndex = 0;
        if (iIndex < m_uCount)
        {
            do
            {
                S00e9e860_Item* p = m_ppItems[iIndex];
                if (p != 0)
                {
                    p->Delete(1);
                }
            } while (++iIndex < m_uCount);
        }
    }
    {
        unsigned short n = 0;
        if (n < m_uCount)
        {
            do
            {
                *(volatile unsigned int*)&m_ppItems[n++] = 0;
            } while (n < m_uCount);
        }
    }
    m_uCount = 0;
    m_u10 = 0;
}

S* FUN_00e9efb0(void* self);
intptr_t FUN_00e9ecc0();

struct E9EE20MemoryManager
{
};

class E9EE20Base
{
  public:
    virtual ~E9EE20Base()
    {}

};

class E9EE20Buffer
{
  public:
    virtual ~E9EE20Buffer()
    {
        ::FUN_00aa10f0(m_pResource);
    }

    void* m_pResource;
};

class FUN_00e9ee20 : public E9EE20Base
{
  public:
    virtual ~FUN_00e9ee20();

    E9EE20Buffer m_kBuffer;
};

// @fnv 0x00e9ee20
FUN_00e9ee20::~FUN_00e9ee20()
{
    reinterpret_cast<::S00e9e860_Obj *>(this)->FUN_00e9e860();
}


class A64330Obj
{
  public:
    int unk00;
    int** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;


    unsigned int FUN_00a64330(int* const& value);
};

// @fnv 0x00a64330
unsigned int A64330Obj::FUN_00a64330(int* const& value)
{
    int* element = value;

    if (element == 0)
        return 0xffffffffu;

    unsigned short i;
    for (i = 0; i < m_usSize; ++i)
    {
        if (m_pBase[i] == 0)
        {
            m_pBase[i] = element;
            ++m_usESize;
            return i;
        }
    }

    unsigned int uiSize = m_usSize;
    if (uiSize >= m_usMaxSize)
        reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00a90180(uiSize + m_usGrowBy);

    reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00ba3aa0(uiSize, (::KeyPair **)&(value));
    return uiSize;
}

struct ShaderObj
{
    virtual void SetSomething(unsigned int a1);
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    ShaderObj() throw();
};

// @fnv 0x00e9efe0
ShaderObj* __cdecl FUN_00e9efe0(unsigned int a1)
{
    ShaderObj* p = new ShaderObj;
    p->SetSomething(a1);
    return p;
}

struct Items
{
};
typedef unsigned int(__cdecl* ReadFn)(void*, unsigned int*, unsigned int, unsigned int*, unsigned int);
struct Stream
{
    unsigned int unused;
    unsigned int nread;
    ReadFn read;
};
struct Obj
{
    unsigned int unused;
    Items items;
    unsigned int* ptrs;
    unsigned short cap, n;
    void FUN_00e9f020(char* stream);
};
// @fnv 0x00e9f020
void Obj::FUN_00e9f020(char* stream)
{
    unsigned int num;
    ::FUN_00a89af0((intptr_t)this);
    Stream* in = *(Stream**)(stream + 0x24c);
    {
        unsigned int sz = 4;
        in->nread += in->read(in, &num, 4, &sz, 1);
    }
    for (unsigned int i = 0; i < num; ++i)
    {
        unsigned int item = ::FUN_00e9cab0((::e9Obj *)(stream));
        if (item)
        {
            unsigned int max = n;
            for (unsigned int j = 0; j < max; ++j)
            {
                if (item == ptrs[j])
                    goto found;
            }
            reinterpret_cast<::A64330Obj *>(&(items))->FUN_00a64330((*(int *const *)(&item)));
        found:;
        }
    }
}

struct E9E8C0Item
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual bool IsDifferent(E9E8C0Item* pkOther);
};

struct E9E8C0ItemList
{
    E9E8C0Item** m_ppkBase;
    unsigned short m_usUnk04;
    unsigned short m_usSize;

    E9E8C0Item*& GetAt(unsigned int ui)
    {
        return m_ppkBase[ui];
    }
    unsigned short GetSize() const
    {
        return m_usSize;
    }
};

class E9E8C0Array
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual int GetType();

    bool FUN_00e9e8c0(E9E8C0Array* pkOther);

  protected:
    int m_unk04;
    E9E8C0ItemList m_kUnsortedGeometryList;
};

// @fnv 0x00e9e8c0
bool E9E8C0Array::FUN_00e9e8c0(E9E8C0Array* pkOther)
{
    if (pkOther->GetType() != 4)
        return false;
    if (m_kUnsortedGeometryList.GetSize() != pkOther->m_kUnsortedGeometryList.GetSize())
        return false;
    for (unsigned int ui = 0; ui < m_kUnsortedGeometryList.GetSize(); ui++)
    {
        if (m_kUnsortedGeometryList.GetAt(ui)->IsDifferent(pkOther->m_kUnsortedGeometryList.GetAt(ui)))
            return false;
    }
    return true;
}

struct S_00e9e930_X
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void* a, void* b);
};
struct S_00e9e930_A
{
    int unk00;
    int unk04;
    void** m08;
};
struct S_00e9e930
{
    int unk00;
    int unk04;
    S_00e9e930_X** m08;
    unsigned short unk0C;
    unsigned short m0E;
    void FUN_00e9e930(S_00e9e930_A* a1, void* a2);
};
// @fnv 0x00e9e930
void S_00e9e930::FUN_00e9e930(S_00e9e930_A* a1, void* a2)
{
    for (unsigned int i = 0; i < m0E; i++)
    {
        S_00e9e930_X* obj = m08[i];
        void* arg = a1->m08[i];
        obj->v5(arg, a2);
    }
}

class NiBinaryStream
{
  public:
    typedef unsigned int (*NIBINARYSTREAM_WRITEFN)(NiBinaryStream* pThis, const void* pvBuffer, unsigned int uiBytes,
                                                   unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    NIBINARYSTREAM_WRITEFN m_pfnWrite;
};

class NiStream
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
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    NiBinaryStream* m_pBackingStream;
};

template <class T> __forceinline void SerializeValue(NiBinaryStream& kStream, const T& tValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&tValue, sizeof(T), &uiSize, 1);
}

class NiSavable
{
  public:
    virtual void v0();
    virtual void SaveBinary(NiStream& kStream);
};

class FUN_00e9ed50_cls
{
  public:
    void* m_pvVtbl;
    int unk04;
    NiSavable** m_ppSavableObjects;
    unsigned short unk0c;
    unsigned short m_usElementCount;

    void FUN_00e9ed50(NiStream& kStream);
};

// @fnv 0x00e9ed50
void FUN_00e9ed50_cls::FUN_00e9ed50(NiStream& kStream)
{
    reinterpret_cast<::S_00e9cb10_Obj *>(this)->SaveValueToStream((::S_00e9cb10_Stream *)&(kStream));

    unsigned int ItemUpdateArray = m_usElementCount;
    SerializeValue(*kStream.m_pBackingStream, ItemUpdateArray);

    for (unsigned int i = 0; i < m_usElementCount; i++)
    {
        NiSavable* pkObj = m_ppSavableObjects[i];
        if (pkObj)
            pkObj->SaveBinary(kStream);
    }
}

typedef unsigned int u32;
typedef unsigned short u16;

template <class T> class NiTPrimitiveArray
{
  public:
    virtual ~NiTPrimitiveArray();

    u32 GetSize() const
    {
        return m_usSize;
    }
    T GetAt(u32 uiIndex) const
    {
        return (uiIndex < m_usSize) ? m_pBase[uiIndex] : 0;
    }
    void SetSize(u32 uiMaxSize);
    void SetAt(u32 uiIndex, T& element);

    u32 Add(T& element)
    {
        u32 uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
        {
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        }
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, element);
        return uiIndex;
    }

    T* m_pBase;
    u16 m_usMaxSize;
    u16 m_usSize;
    u16 m_usESize;
    u16 m_usGrowBy;
};

class NiBoundingVolume
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void AddViewerStrings(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings);
};

class NiUnionBV
{
  public:
    void FUN_00e9f0b0(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings);

    u32 unk00;
    NiTPrimitiveArray<NiBoundingVolume*> m_kBoundingVolumes;
};

// @fnv 0x00e9f0b0
void NiUnionBV::FUN_00e9f0b0(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings)
{
    u32 uiLen = strlen(pcPrefix) + 12;
    char* pcString = (char*)FUN_00aa1070(uiLen);
    ::NiSprintf(pcString, uiLen, "%s = UNION_BV", pcPrefix);
    pkStrings->Add(pcString);

    for (u32 i = 0; i < m_kBoundingVolumes.GetSize(); i++)
    {
        char* pcChild = (char*)FUN_00aa1070(13);
        ::NiSprintf(pcChild, 13, "   child %i", i);
        m_kBoundingVolumes.GetAt(i)->AddViewerStrings(pcChild, pkStrings);
    }
}

namespace fnv_00e9edd0 {

template <class T_Data> class NiTMallocInterface
{
  public:
    static T_Data* Allocate(unsigned int auiCount)
    {
        return (T_Data*)::FUN_00aa1070(sizeof(T_Data) * auiCount);
    }
};

template <class T_Data, class TAlloc> class NiTArray
{
  public:
    NiTArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;

        if (m_usMaxSize > 0)
            m_pBase = TAlloc::Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~NiTArray();

  protected:
    T_Data* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
  public:
    NiTPrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : NiTArray<T, NiTMallocInterface<T> >(uiMaxSize, uiGrowBy)
    {}
    virtual ~NiTPrimitiveArray();
};

class NiShaderArrayOwner
{
  public:
    NiShaderArrayOwner();
    virtual ~NiShaderArrayOwner();

  protected:
    NiTPrimitiveArray<void*> m_kArray;
    void* m_pkEntry;
};

// @fnv 0x00e9edd0
NiShaderArrayOwner::NiShaderArrayOwner() : m_kArray(2, 1), m_pkEntry(0)
{}
}  // namespace fnv_00e9edd0


extern void* DAT_010f1778[];
extern void* DAT_010f17ac[];

struct NiCloneableQ
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual NiCloneableQ* Clone();
};

struct CloneArrayQ
{
    void** vtbl;
    NiCloneableQ** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

struct SViewQ
{
    void** vtbl;
    CloneArrayQ m_kArray;
};

// @fnv 0x00e9ee60
S* S::FUN_00e9ee60(void* pkOtherRaw)
{
    SViewQ* pkOther = (SViewQ*)pkOtherRaw;
    SViewQ* pkSelf = (SViewQ*)this;
    pkSelf->vtbl = DAT_010f1778;
    CloneArrayQ* pkArray = &pkSelf->m_kArray;
    pkArray->m_usMaxSize = 0;
    pkArray->m_usGrowBy = 1;
    pkArray->m_usSize = 0;
    pkArray->m_usESize = 0;
    pkArray->m_pBase = 0;
    pkArray->vtbl = DAT_010f17ac;
    reinterpret_cast<::FUN_00a41520_cls *>((pkArray))->FUN_00a90180(pkOther->m_kArray.m_usSize);
    for (unsigned int i = 0; i < pkOther->m_kArray.m_usSize; i++)
    {
        NiCloneableQ* p = pkOther->m_kArray.m_pBase[i];
        if (p)
        {
            NiCloneableQ* q = p->Clone();
            reinterpret_cast<::FUN_00a41520_cls *>((pkArray))->FUN_00ba3aa0(i, (::KeyPair **)&(q));
        }
    }
    return this;
}


class ImageSpaceTexture;
struct Item
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual ImageSpaceTexture* GetTexture();
};
struct TextureVTable
{
    void* vf00;
    void* vf04;
    void* vf08;
    void* vf0C;
    void* vf10;
    void* vf14;
    void* vf18;
    void* vf1C;
    void(* Attach)(ImageSpaceTexture*, Item*);
};
class ImageSpaceTexture
{
  public:
    TextureVTable* vtable;
};
struct Source
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int GetType();
    unsigned int unk04;
    Item** m_items;
    unsigned short unk0C;
    unsigned short m_uiItemCount;
};
struct TexArray
{
    void SetAt(unsigned int i, ImageSpaceTexture*& t);
};
struct TexCache
{
    void FUN_00e9ecd0(Source* src);
    unsigned int unk00;
    TexArray m_textures;
};
// @fnv 0x00e9ecd0
void TexCache::FUN_00e9ecd0(Source* src)
{
    if (src->GetType() == 4)
    {
        reinterpret_cast<::S00e9e860_Obj *>(this)->FUN_00e9e860();
        reinterpret_cast<::FUN_00a41520_cls *>(&(m_textures))->FUN_00a90180(src->m_uiItemCount);
        for (unsigned int i = 0; i < src->m_uiItemCount; i++)
        {
            Item* item = src->m_items[i];
            ImageSpaceTexture* value = item->GetTexture();
            TextureVTable* table = value->vtable;
            ImageSpaceTexture* tex = value;
            table->Attach(value, item);
            reinterpret_cast<::FUN_00a41520_cls *>(&(m_textures))->FUN_00ba3aa0(i, (::KeyPair **)&(tex));
        }
    }
}

struct Element365
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual int vf06();
};

struct Array365
{
    int unk00;
    int* unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;


    __forceinline void SetAt(unsigned int idx, int e)
    {
        if (idx >= unk0a)
        {
            unk0a = (unsigned short)(idx + 1);
            if (e)
                ++unk0c;
        }
        else if (e)
        {
            if (!unk04[idx])
                ++unk0c;
        }
        else
        {
            if (unk04[idx])
                --unk0c;
        }
        unk04[idx] = e;
    }
};

struct State365
{
    int unk00;
    Array365 arr;

    unsigned int unk14;
};

struct Source365
{
    int unk00;
    int unk04;
    Element365** unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    unsigned short GetSize() const
    {
        return unk0e;
    }

    State365* FUN_00e9eef0();
};

// @fnv 0x00e9eef0
State365* Source365::FUN_00e9eef0()
{
    State365* state = static_cast<State365*>(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(sizeof(State365)));

    unsigned int i = 0;
    if (state)
        state = ((::State365 *)(new ((void *)(state)) ::fnv_00e9edd0::NiShaderArrayOwner()));

    else
        state = 0;
    reinterpret_cast<::FUN_00a41520_cls *>(&(state->arr))->FUN_00a90180(GetSize());
    for (; i < GetSize(); i++)
        state->arr.SetAt(i, unk08[i]->vf06());
    return state;
}
