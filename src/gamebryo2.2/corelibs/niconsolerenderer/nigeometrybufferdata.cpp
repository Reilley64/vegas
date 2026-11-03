// gamebryo2.2/corelibs/niconsolerenderer/nigeometrybufferdata.cpp: NiGeometryBufferData, RendererData, NiSlotSetE8E (8 functions)

#include <cstddef>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_010f0000.h"
#include "fnv/symbols_011f6000.h"
#include "nigeometrybufferdata.h"

// @fnv 0x00e8eee0
void NiGeometryBufferData::ReleaseBuffers()
{
    if (m_pkIndexBuffer)
    {
        m_pkIndexBuffer->Release();
        m_pkIndexBuffer = NULL;
    }

    m_uiPrimitiveCount = 0;
}

struct FUN_00e8f0f0_shell : public NiGeometryBufferData
{
    void DestroyGeometryBufferData();
};

extern int DAT_010f0170;

struct UnknownVtable08
{
    void(__thiscall* pfn0)(void*);
    void(__thiscall* pfn1)(void*);
    void(__thiscall* pfn2)(void*);
    void(__thiscall* pfn3)(void*);
    void(__thiscall* pfn4)(void*);
    void(__thiscall* pfn5)(void*);
    void(__thiscall* pfn6)(void*);
    void(__thiscall* pfn7)(void*, void*, unsigned int);
};

struct UnknownComVtable
{
    void(__stdcall* QueryInterface)(void*, void*, void**);
    unsigned long(__stdcall* AddRef)(void*);
    unsigned long(__stdcall* Release)(void*);
};

struct UnknownComObj
{
    UnknownComVtable* lpVtbl;
};

// @fnv 0x00e8f0f0
void FUN_00e8f0f0_shell::DestroyGeometryBufferData()
{
    *reinterpret_cast<void**>(this) = &(*reinterpret_cast<void * *>(&::NiGeometryBufferData_vtable));

    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x08))
    {
        for (unsigned int i = 0; i < *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x20); ++i)
        {
            void* p = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x08);
            (*reinterpret_cast<UnknownVtable08**>(p))->pfn7(p, this, i);
        }
    }

    UnknownComObj* pIB = *reinterpret_cast<UnknownComObj**>(reinterpret_cast<char*>(this) + 0x34);
    if (pIB)
    {
        pIB->lpVtbl->Release(pIB);
        *reinterpret_cast<UnknownComObj**>(reinterpret_cast<char*>(this) + 0x34) = 0;
    }

    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x30) = 0;
    ::FUN_00aa10f0(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x28));
    ::FUN_00aa10f0(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x24));

    UnknownComObj* pDecl = *reinterpret_cast<UnknownComObj**>(reinterpret_cast<char*>(this) + 0x10);
    if (pDecl)
    {
        pDecl->lpVtbl->Release(pDecl);
    }

    *reinterpret_cast<void**>(this) = &DAT_010f0170;
}

namespace fnv_00e8f170 {
struct FUN_00e8f0f0_shell
{
};
struct MemoryManager
{
};
// Calls the object's destructor, then frees the object via g_memoryManager when _flags has bit 0 set, and returns _this.
// @fnv 0x00e8f170
void* __fastcall FUN_00e8f170(void* _this, int, unsigned int auiFlags)
{
    reinterpret_cast<::FUN_00e8f0f0_shell *>((((FUN_00e8f0f0_shell*)_this)))->DestroyGeometryBufferData();
    if (auiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00e8f170::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(_this);
    return _this;
}
}  // namespace fnv_00e8f170

struct P03MM
{
};
extern int DAT_010f0170;
struct RendererData
{
    void* FUN_00e8ee80(unsigned int);
};
// Sets the object's vtable pointer to DAT_010f0170 and, if bit 0 of a1 is set, deallocates the object via g_memoryManager, then returns this.
// @fnv 0x00e8ee80
void* RendererData::FUN_00e8ee80(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_010f0170;
    if (auiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

struct IUnk_00e8f010
{
    virtual void __stdcall f0();
    virtual void __stdcall f1();
    virtual unsigned long __stdcall Release();
};
struct C_00e8f010
{
    char _pad[12];
    int m_iThirdValue;
    IUnk_00e8f010* m_10;
    void FUN_00e8f010(int);
};
// @fnv 0x00e8f010
void C_00e8f010::FUN_00e8f010(int a)
{
    m_iThirdValue = a;
    if (m_10)
    {
        m_10->Release();
        m_10 = 0;
    }
}

struct FakeCOM_00e8f040
{
    virtual void __stdcall Dummy() = 0;
    virtual void __stdcall AddRef() = 0;
    virtual void __stdcall Release() = 0;
};
struct Holder_00e8f040
{
    char _pad[12];
    int unkC;
    FakeCOM_00e8f040* ptr10;
    void SetComPointer(FakeCOM_00e8f040* p);
};
// Releases the old COM pointer, stores p and AddRefs it when different, then resets unkC to 0.
// @fnv 0x00e8f040
void Holder_00e8f040::SetComPointer(FakeCOM_00e8f040* apCom)
{
    if (apCom != ptr10)
    {
        if (ptr10)
            ptr10->Release();
        ptr10 = apCom;
        if (apCom)
            apCom->AddRef();
    }
    unkC = 0;
}

extern "C" void* __cdecl MemMoveE8E(void* pvDest, const void* pvSrc, unsigned int uiSize);
extern "C" void* __cdecl MemSetE8E(void* pvDest, int iValue, unsigned int uiSize);

class NiMemManagerE8E
{
  public:
};


class NiSlotSetE8E;

class NiSlotListenerE8E
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void SlotRemoved(NiSlotSetE8E* pkSet, unsigned int uiSlot);
};

class NiSlotSetE8E
{
  public:
    void* m_ppVirtualMethodTable;
    int unk04;
    NiSlotListenerE8E* m_pkListener;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiSize;
    unsigned int* m_puiFlags;
    void** m_ppvSlots;

    void FUN_00e8ef10(unsigned int uiNewSize);
};

// Resizes the slot and flag arrays to uiNewSize, copying existing entries, zeroing new ones, notifying the listener of removed slots, and freeing the old arrays.
// @fnv 0x00e8ef10
void NiSlotSetE8E::FUN_00e8ef10(unsigned int uiNewSize)
{
    if (uiNewSize == m_uiSize)
        return;

    void** ppvNewSlots = (void**)::FUN_00aa1070(uiNewSize * sizeof(void*));
    unsigned int* puiNewFlags = (unsigned int*)::FUN_00aa1070(uiNewSize * sizeof(unsigned int));

    if (uiNewSize < m_uiSize)
    {
        MemMoveE8E(ppvNewSlots, m_ppvSlots, uiNewSize * sizeof(void*));
        MemMoveE8E(puiNewFlags, m_puiFlags, uiNewSize * sizeof(unsigned int));
        if (m_pkListener)
        {
            for (unsigned int i = uiNewSize; i < m_uiSize; i++)
                m_pkListener->SlotRemoved(this, i);
        }
    }
    else
    {
        MemMoveE8E(ppvNewSlots, m_ppvSlots, m_uiSize * sizeof(void*));
        MemMoveE8E(puiNewFlags, m_puiFlags, m_uiSize * sizeof(unsigned int));
        MemSetE8E(ppvNewSlots + m_uiSize, 0, (uiNewSize - m_uiSize) * sizeof(void*));
        MemSetE8E(puiNewFlags + m_uiSize, 0, (uiNewSize - m_uiSize) * sizeof(unsigned int));
    }

    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::NiMemManagerE8E *>(&::g_memoryManager))))->FUN_00aa4060(m_ppvSlots);
    ::FUN_00aa10f0(m_puiFlags);
    m_ppvSlots = ppvNewSlots;
    m_puiFlags = puiNewFlags;
    m_uiSize = uiNewSize;
}

struct S00e8f080_Obj : public NiGeometryBufferData
{
    bool IsKindEnabled(int kind);
    bool bit(int n) const
    {
        return ((m_uiValue1 >> n) & 1) != 0;
    }
};

// Returns whether a geometry buffer data kind is enabled by checking bit fields in m_uiValue1.
// @fnv 0x00e8f080
bool S00e8f080_Obj::IsKindEnabled(int kind)
{
    bool r;
    switch (kind)
    {
    case 4:
        r = bit(22);
        return r;
    case 3:
        r = bit(23);
        return r;
    case 13:
    case 14:
        r = bit(21);
        return r;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        return (unsigned int)(kind - 5) < (m_uiValue1 >> 24);
    }
    return false;
}
