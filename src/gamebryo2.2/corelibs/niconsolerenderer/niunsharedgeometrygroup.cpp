
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Placeholder declarations

#include <new>
#include <cstring>
#include "fnv/decl/FUN_00e98710_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00e98000.h"
#include "fnv/symbols_010f1000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01400000.h"
struct NiUnsharedGeometryGroup
{
    void* m_ppVirtualMethodTable;
    virtual ~NiUnsharedGeometryGroup();
    void* Destroy(unsigned int flags);
};

// Restores the vtable, clears the global pointer if it refers to this object, calls FUN_00e98710, and optionally deletes the object.
// @fnv 0x00e94d30
void* NiUnsharedGeometryGroup::Destroy(unsigned int flags)
{
    NiUnsharedGeometryGroup* pThis = this;
    *(void**)pThis = &DAT_010f1008;
    if (pThis == *(void**)&(*reinterpret_cast<int *>(&::DAT_0126fa34)))
        *(void**)&(*reinterpret_cast<int *>(&::DAT_0126fa34)) = 0;
    static_cast<::FUN_00e98710_cls *>(nullptr)->FUN_00e98710();
    if (flags & 1)
        ::FUN_00aa1460(pThis, 0xc);
    return pThis;
}

struct Direct3DDeviceInterface;
struct NiGeometryBufferData;
struct NiGeometryData;
struct NiGeometryGroup;
struct NiScreenTexture;
struct NiSkinInstance;
struct NiVBChip;

struct P03MM
{
};
struct NiGeometryBufferData
{
    NiGeometryBufferData();
};
struct S
{
    void CreateScreenTextureBufferData(NiScreenTexture* pkScreenTexture);
};
// @fnv 0x00e94de0
void S::CreateScreenTextureBufferData(NiScreenTexture* pkScreenTexture)
{
    if (*(int*)((char*)pkScreenTexture + 0x1c) == 0)
    {
        void* pMemory = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(0x54);
        NiGeometryBufferData* pkBuffData = pMemory ? new (pMemory) NiGeometryBufferData() : 0;
        *(int*)((char*)pkBuffData + 0x3c) = 4;
        *(NiGeometryBufferData**)((char*)pkScreenTexture + 0x1c) = pkBuffData;
        *(int*)((char*)pkBuffData + 4) = (int)&DAT_01400000;
        ::FUN_00e98730((int)this, (int)(pkBuffData), {});
    }
}

struct FakeVB
{
    virtual void F0();
    virtual void F1();
    virtual unsigned long Release();
};
// Releases the vertex buffer chip for the given stream index, clears its slot and deletes the chip.
// @fnv 0x00e94ee0
void FUN_00e94ee0(NiGeometryBufferData* pkBuffData, unsigned int uiStreamIndex)
{
    NiVBChip* pkChip;
    if (uiStreamIndex < *(unsigned int*)((char*)pkBuffData + 0x20))
    {
        pkChip = ((NiVBChip**)*(void**)((char*)pkBuffData + 0x28))[uiStreamIndex];
        if (pkChip)
        {
            if (*(FakeVB**)((char*)pkChip + 8))
                ((FakeVB*)*(void**)((char*)pkChip + 8))->Release();
            if (uiStreamIndex < *(unsigned int*)((char*)pkBuffData + 0x20))
                ((NiVBChip**)*(void**)((char*)pkBuffData + 0x28))[uiStreamIndex] = 0;
            *(void**)((char*)pkChip + 8) = 0;
            ::FUN_00aa1460(pkChip, 0x20);
        }
    }
}

struct NiGeometryGroup
{
    void RemoveObject(NiGeometryBufferData*);
};
struct NiDynamicGeometryGroup : NiGeometryGroup
{
    void FUN_00e950f0(NiGeometryData* pkData);
};
struct Deleter
{
    virtual ~Deleter();
};
// Removes pkData's buffer data from the group, clears its buffer array, deletes it, and nulls the pointer.
// @fnv 0x00e950f0
void NiDynamicGeometryGroup::FUN_00e950f0(NiGeometryData* pkData)
{
    NiGeometryBufferData* pkBuffData = *(NiGeometryBufferData**)((char*)pkData + 0x34);
    if (pkBuffData)
    {
        NiGeometryGroup::RemoveObject(pkBuffData);
        if (*(void**)((char*)pkBuffData + 0x28))
            std::memset(*(void**)((char*)pkBuffData + 0x28), 0, *(unsigned int*)((char*)pkBuffData + 0x20) * 4);
        delete (Deleter*)pkBuffData;
        *(NiGeometryBufferData**)((char*)pkData + 0x34) = 0;
    }
}

namespace fnv_00e95140 {
struct Direct3DDeviceInterface;
struct NiGeometryBufferData;
struct NiGeometryData;
struct NiGeometryGroup;
struct NiScreenTexture;
struct NiSkinInstance;
struct NiVBChip;

struct NiGeometryGroup
{
    void RemoveObject(NiGeometryBufferData*);
};
struct NiGeometryBufferData
{
    virtual ~NiGeometryBufferData();
    char _pad04[28];
    unsigned int m_uiRegisterStreamCount;
    unsigned int _pad24;
    NiVBChip** m_ppkVertexBuffers;
};
struct NiDynamicGeometryGroup : NiGeometryGroup
{
    void FUN_00e95140(NiGeometryData* pkData);
};
// Removes the geometry buffer data stored at offset 0x28 of pkData, clears its chip array, deletes it and nulls the pointer.
// @fnv 0x00e95140
void NiDynamicGeometryGroup::FUN_00e95140(NiGeometryData* pkData)
{
    NiGeometryBufferData* pkBuffData = *(NiGeometryBufferData**)((char*)pkData + 0x28);
    if (pkBuffData)
    {
        NiGeometryGroup::RemoveObject(pkBuffData);
        if (pkBuffData->m_ppkVertexBuffers)
            std::memset(pkBuffData->m_ppkVertexBuffers, 0, pkBuffData->m_uiRegisterStreamCount * 4);
        delete pkBuffData;
        *(NiGeometryBufferData**)((char*)pkData + 0x28) = 0;
    }
}
}  // namespace fnv_00e95140

namespace fnv_00e95190 {
struct NiGeometryGroup
{
    void RemoveObject(NiGeometryBufferData*);
};
struct NiDynamicGeometryGroup : NiGeometryGroup
{
    void FUN_00e95190(NiGeometryData* pkData);
};
struct DeleteHelper
{
    virtual ~DeleteHelper();
};
// @fnv 0x00e95190
void NiDynamicGeometryGroup::FUN_00e95190(NiGeometryData* pkData)
{
    NiGeometryBufferData* pkBuffData = *(NiGeometryBufferData**)((char*)pkData + 0x1c);
    if (pkBuffData)
    {
        RemoveObject(pkBuffData);
        void* p = *(void**)((char*)pkBuffData + 0x28);
        if (p)
            std::memset(p, 0, *(unsigned int*)((char*)pkBuffData + 0x20) * 4);
        delete (DeleteHelper*)pkBuffData;
        *(NiGeometryBufferData**)((char*)pkData + 0x1c) = 0;
    }
}
}  // namespace fnv_00e95190

struct Direct3DDeviceInterface;
struct NiGeometryBufferData;
struct NiGeometryData;
struct NiGeometryGroup;
struct NiScreenTexture;
struct NiSkinInstance;
struct NiVBChip;
void FUN_00e94ee0(NiGeometryBufferData* pkBuffData, unsigned int uiStream);
struct BufEntry
{
    int unk00;
    int unk04;
    int unk08;
    FakeVB* unk0C;
    FakeVB* unk10;
    int unk14;
};
struct OwnerEntry
{
    int unk00;
    int unk04;
    int unk08;
};
template <class TVAL> struct MapItem
{
    MapItem* m_pkNext;
    const char* m_key;
    TVAL m_val;
};
template <class TVAL> struct StrMap
{
    typedef MapItem<TVAL> Item;
    virtual ~StrMap();
    virtual unsigned int KeyToHashIndex(const char* key) const;
    unsigned int m_uiHashSize;
    Item** m_ppkHashTable;
    unsigned int m_uiCount;

    bool RemoveAt(const char* key);

    Item* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    void GetNext(Item*& pos, const char*& key, TVAL& val) const
    {
        Item* item = pos;
        key = item->m_key;
        val = item->m_val;
        if (item->m_pkNext)
        {
            pos = item->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(item->m_key);
        for (++i; i < m_uiHashSize; i++)
        {
            Item* p = m_ppkHashTable[i];
            if (p)
            {
                pos = p;
                return;
            }
        }
        pos = 0;
    }
};
template <class T> struct PtrArray
{
    virtual ~PtrArray();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    unsigned short GetAllocatedSize() const
    {
        return m_usMaxSize;
    }
    T GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    T RemoveAt(unsigned int i)
    {
        if (i >= m_usSize)
            return 0;
        T e = m_pBase[i];
        m_pBase[i] = 0;
        if (e != 0)
            m_usESize--;
        if (i == (unsigned short)(m_usSize - 1))
            m_usSize--;
        return e;
    }
};
struct BufferManager
{
    int unk00;
    int unk04;
    int unk08;
    StrMap<BufEntry*> m_kBuffers;
    StrMap<OwnerEntry*> m_kOwners;
    PtrArray<BufEntry*> m_kBufArray;
    PtrArray<OwnerEntry*> m_kOwnerArray;

    void ClearBuffers();
};
// @fnv 0x00e94f30
void BufferManager::ClearBuffers()
{
    StrMap<BufEntry*>::Item* pos = m_kBuffers.GetFirstPos();
    while (pos)
    {
        const char* key;
        BufEntry* val;
        m_kBuffers.GetNext(pos, key, val);
        m_kBuffers.RemoveAt(key);
        if (val)
        {
            FakeVB* vb = val->unk10;
            if (vb)
                vb->Release();
            vb = val->unk0C;
            if (vb)
                vb->Release();
            ::FUN_00aa1460(val, sizeof(BufEntry));
        }
    }

    StrMap<OwnerEntry*>::Item* pOwnerPos = m_kOwners.GetFirstPos();
    while (pOwnerPos)
    {
        const char* key;
        OwnerEntry* val;
        m_kOwners.GetNext(pOwnerPos, key, val);
        val->unk08 = 0;
    }

    for (unsigned int i = 0; i < m_kBufArray.GetAllocatedSize(); i++)
    {
        BufEntry* p = m_kBufArray.RemoveAt(i);
        if (p)
        {
            FakeVB* vb = p->unk10;
            if (vb)
                vb->Release();
            vb = p->unk0C;
            if (vb)
                vb->Release();
            ::FUN_00aa1460(p, sizeof(BufEntry));
        }
        m_kOwnerArray.GetAt(i)->unk08 = 0;
    }
}

struct IDirect3DVertexBuffer9_E94;
struct IDirect3DDevice9_E94
{
    virtual long QueryInterface(void*, void**);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual long TestCooperativeLevel();
    virtual unsigned int GetAvailableTextureMem();
    virtual long EvictManagedResources();
    virtual long GetDirect3D(void**);
    virtual long GetDeviceCaps(void*);
    virtual long GetDisplayMode(unsigned int, void*);
    virtual long GetCreationParameters(void*);
    virtual long SetCursorProperties(unsigned int, unsigned int, void*);
    virtual void SetCursorPosition(int, int, unsigned long);
    virtual int ShowCursor(int);
    virtual long CreateAdditionalSwapChain(void*, void**);
    virtual long GetSwapChain(unsigned int, void**);
    virtual unsigned int GetNumberOfSwapChains();
    virtual long Reset(void*);
    virtual long Present(const void*, const void*, void*, const void*);
    virtual long GetBackBuffer(unsigned int, unsigned int, int, void**);
    virtual long GetRasterStatus(unsigned int, void*);
    virtual long SetDialogBoxMode(int);
    virtual void SetGammaRamp(unsigned int, unsigned long, const void*);
    virtual void GetGammaRamp(unsigned int, void*);
    virtual long CreateTexture(unsigned int, unsigned int, unsigned int, unsigned long, int, int, void**,
                                         void**);
    virtual long CreateVolumeTexture(unsigned int, unsigned int, unsigned int, unsigned int, unsigned long,
                                               int, int, void**, void**);
    virtual long CreateCubeTexture(unsigned int, unsigned int, unsigned long, int, int, void**, void**);
    virtual long CreateVertexBuffer(unsigned int Length, unsigned long Usage, unsigned long FVF, int Pool,
                                              IDirect3DVertexBuffer9_E94** ppVB, void** pSharedHandle);
};
class NiMemObject_E94
{
  public:
};
class NiVBChipE94 : public NiMemObject_E94
{
  public:
    NiVBChipE94()
    {
        m_pkTreeBlock = 0;
        m_uiPosition = 0;
        m_pkOwningStream = 0;
        m_pkPrev = 0;
        m_uiSize = 0;
        m_pkNext = 0;
        m_uiValueBeforeCount = 0;
        m_pUserData = 0;
    }
    void* m_pkTreeBlock;
    unsigned int m_uiPosition;
    IDirect3DVertexBuffer9_E94* m_pkOwningStream;
    NiVBChipE94* m_pkPrev;
    NiVBChipE94* m_pkNext;
    unsigned int m_uiSize;
    unsigned int m_uiValueBeforeCount;
    void* m_pUserData;
};
struct NiBuffDataE94
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_uiGroupIndex;
    int unk10;
    bool m_bIsInitialized;
    int unk18;
    unsigned int m_uiVertexCount;
    unsigned int m_uiRegisterStreamCount;
    unsigned int* m_puiVertexStrides;
    unsigned int GetVertexStride(unsigned int uiStream) const
    {
        return uiStream < m_uiRegisterStreamCount ? m_puiVertexStrides[uiStream] : 0;
    }
};
class NiUnsharedGeometryGroupE94
{
  public:
    void* m_ppVirtualMethodTable;
    int unk04;
    IDirect3DDevice9_E94* m_pDirect3DDevice;
    NiVBChipE94* FUN_00e94e30(NiBuffDataE94* pkBuffData, unsigned int uiStream);
};

// Creates a D3D vertex buffer sized for the stream and returns a new NiVBChipE94 wrapping it with the given size and owning stream.
// @fnv 0x00e94e30
NiVBChipE94* NiUnsharedGeometryGroupE94::FUN_00e94e30(NiBuffDataE94* pkBuffData, unsigned int uiStream)
{
    unsigned int uiVertexCount = pkBuffData->m_uiVertexCount;
    unsigned int uiVBSize = pkBuffData->GetVertexStride(uiStream) * uiVertexCount;
    unsigned int uiUsage = 0x8;
    if (pkBuffData->m_bIsInitialized)
        uiUsage = 0x8 | 0x10;
    IDirect3DVertexBuffer9_E94* pkVB;
    m_pDirect3DDevice->CreateVertexBuffer(uiVBSize, uiUsage, pkBuffData->m_uiGroupIndex, DAT_0126f0d0 ? 0 : 1, &pkVB,
                                          0);
    IDirect3DVertexBuffer9_E94* pkNewVB = pkVB;
    NiVBChipE94* pkChip = new NiVBChipE94;
    if (pkChip)
    {
        pkChip->m_pkOwningStream = pkNewVB;
        pkChip->m_uiSize = uiVBSize;
        pkChip->m_pkTreeBlock = 0;
        pkChip->m_uiPosition = 0;
        pkChip->m_pkPrev = 0;
        pkChip->m_pkNext = 0;
    }
    return pkChip;
}

#include "generated/data/gamebryo2.2/corelibs/niconsolerenderer/niunsharedgeometrygroup.inc"
