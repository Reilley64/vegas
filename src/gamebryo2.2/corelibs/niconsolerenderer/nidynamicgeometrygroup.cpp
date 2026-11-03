// gamebryo2.2/corelibs/niconsolerenderer/nidynamicgeometrygroup.cpp: NiDynamicGeometryGroup, SomeClass, UnsharedGroupStub, Group and more (17 functions)

#include <cstdint>
#include <new>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00e98710_cls.h"
#include "fnv/decl/HashTableBase.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/S_00b601a0_Map.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00e98000.h"
#include "fnv/symbols_010f0000.h"
#include "fnv/symbols_010f1000.h"
#include "fnv/symbols_011bf000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01400000.h"
#include "nidynamicgeometrygroup_decls.h"
// Constructs a NiDynamicGeometryGroup and initializes nextIndex to 0.
// @fnv 0x00e957b0
NiDynamicGeometryGroup::NiDynamicGeometryGroup() : nextIndex(0)
{}

struct NiStream;
struct NiObject
{
    virtual void LinkObject(NiStream&);
};
struct Direct3D9RenderSystem;
struct NiVBChip
{
    unsigned int m_uiPosition;
    NiObject* m_pkTreeBlock;
    NiStream* m_pkOwningStream;
};
struct NiGeometryBufferData
{
    char pad[0x20];
    unsigned int m_uiRegisterStreamCount;
    char pad2[4];
    NiVBChip** m_ppkVertexBuffers;
public:
    NiGeometryBufferData();
};
// @fnv 0x00e951e0
void FUN_00e951e0(NiGeometryBufferData* pkBuffData, unsigned int uiStream)
{
    if (uiStream < pkBuffData->m_uiRegisterStreamCount)
    {
        NiVBChip* pkChip = pkBuffData->m_ppkVertexBuffers[uiStream];
        if (pkChip)
        {
            if (pkChip->m_pkOwningStream)
            {
                ::FUN_00a89af0((intptr_t)(pkChip->m_pkTreeBlock));
                pkChip->m_pkOwningStream = 0;
            }
            if (uiStream < pkBuffData->m_uiRegisterStreamCount)
                pkBuffData->m_ppkVertexBuffers[uiStream] = 0;
        }
    }
}

struct BSFadeNode
{
    static void* __cdecl operator new(size_t);
};


// Returns the cached NiGeometryGroup singleton, constructing it with BSFadeNode::operator new and initialising it if DAT_0126fa34 is null.
// @fnv 0x00e94d70
NiGeometryGroup* __cdecl GetGeometryGroup()
{
    NiGeometryGroup* pkGroup = DAT_0126fa34;
    if (pkGroup == 0)
    {
        pkGroup = static_cast<NiGeometryGroup*>(BSFadeNode::operator new(0xc));
        if (pkGroup != 0)
        {
            pkGroup->NiGeometryGroup::NiGeometryGroup();
            *reinterpret_cast<void**>(pkGroup) = &(*reinterpret_cast<void * *>(&::DAT_010f1008));
            DAT_0126fa34 = pkGroup;
        }
        else
        {
            DAT_0126fa34 = 0;
        }
    }
    return DAT_0126fa34;
}

void __cdecl _NiFreeAlias(void*);
struct MM
{
};
extern int DAT_010f1034;
struct FUN_00e95780_shell
{
    void* _0;
    void* _4;
    void* FUN_00e95780(unsigned int);
};
// Frees the stored pointer via _NiFreeAlias, sets the first field to &DAT_010f1034, and deallocates this when f has bit 0 set.
// @fnv 0x00e95780
void* FUN_00e95780_shell::FUN_00e95780(unsigned int auiFlags)
{
    void* tmp = _4;
    _0 = (void*)&DAT_010f1034;
    _NiFreeAlias(tmp);
    if (auiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

void __cdecl operator delete(void*, size_t);
struct FUN_00e95b40_shell
{
    virtual ~FUN_00e95b40_shell();
    void* DestroyIfFlagged(unsigned int uiFlags);
};
// Stand-ins for the unnamed/undeclared entities used by this function.
struct NiTMapBaseStub
{
};


void __cdecl _NiFree(void*);


// Minimal polymorphic stand-in for the DynamicMap<NiVBChip> class hierarchy.
struct FUN_00e95380_shell
{
    void* m_pVftable;  // +0x00
    void* m_pUnk04;    // +0x04
    void* m_pUnk08;    // +0x08

    void* DestroyDynamicMap(unsigned int uiFlags);
};

// @fnv 0x00e95380
void* FUN_00e95380_shell::DestroyDynamicMap(unsigned int uiFlags)
{
    m_pVftable = &(*reinterpret_cast<void * *>(&::DAT_010f109c));
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    m_pVftable = &(*reinterpret_cast<void * *>(&::DAT_010f105c));
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    _NiFree(m_pUnk08);
    if (uiFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}

struct SomeClass
{
    void* vtbl;
    void** data;
    unsigned short capacity;
    unsigned short size;
    unsigned short firstFree;
    unsigned short grow;

    void* FUN_00a93c50(unsigned int uiIndex);
};

// Clears the element at uiIndex, decrements firstFree if it was non-null, shrinks size when removing the last slot, and returns the removed pointer.
// @fnv 0x00a93c50
void* SomeClass::FUN_00a93c50(unsigned int uiIndex)
{
    if (uiIndex >= size)
        return 0;

    void* element = data[uiIndex];
    data[uiIndex] = 0;
    if (element)
        firstFree--;

    if (uiIndex == (unsigned short)(size - 1))
        size--;

    return element;
}

struct Base_00b601a0
{
};

struct Base_00aa4060
{
};

extern "C" void __cdecl FUN_00aa10f0(intptr_t);
extern void* DAT_010f107c;
extern void* DAT_010f103c;

struct S_00e95300
{
    void* m_vftable;
    void* m_unk04;
    void* m_unk08;

    S_00e95300* FUN_00e95300(int param);
};

// @fnv 0x00e95300
S_00e95300* S_00e95300::FUN_00e95300(int aiFlags)
{
    m_vftable = &DAT_010f107c;
    reinterpret_cast<::S_00b601a0_Map *>((((Base_00b601a0*)this)))->FUN_00b601a0();
    m_vftable = &DAT_010f103c;
    reinterpret_cast<::S_00b601a0_Map *>((((Base_00b601a0*)this)))->FUN_00b601a0();
    FUN_00aa10f0((intptr_t)m_unk08);
    if (aiFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>((((Base_00aa4060*)&(*reinterpret_cast<void * *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    }
    return this;
}

namespace fnv_00e95500 {
struct MemoryManager
{
};
struct Buffer
{
    unsigned int unk00;
    const char* unk04;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50;
};
struct Destination
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned short index18, unk1a;
    Buffer* buffer1c;
};
struct FUN_00e95500_Class
{
    void EnsureBuffer(Destination*);
};
// If destination->buffer1c is null, allocates a 0x54-byte Buffer, initializes it, stores it in buffer1c, calls FUN_00e98730, and sets index18 to 0xffff.
// @fnv 0x00e95500
void FUN_00e95500_Class::EnsureBuffer(Destination* destination)
{
    if (destination->buffer1c == 0)
    {
        Buffer* ptr = static_cast<Buffer*>(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00e95500::MemoryManager *>(&::g_memoryManager))))->FUN_00aa3e40(0x54));
        Buffer* newBuffer = ptr ? ((::fnv_00e95500::Buffer *)(new ((void *)(ptr)) ::NiGeometryBufferData())) : 0;
        newBuffer->unk3c = 4;
        destination->buffer1c = newBuffer;
        newBuffer->unk04 = &(*reinterpret_cast<char *>(&::DAT_01400000));
        ::FUN_00e98730((intptr_t)this, (intptr_t)(newBuffer), {});
        destination->index18 = 0xffff;
    }
}
}  // namespace fnv_00e95500

struct RttiStub
{
    const char* m_pcName;
    const RttiStub* m_pBaseRTTI;
};

struct MemMgrStub
{
};


struct GeomDataStub
{
    virtual void V0();
    virtual void V1();
    virtual const RttiStub* GetRTTI() const;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    unsigned short unk0e;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    void* m_pkNormal;
    void* m_pkColor;
    int unk2c;
    int unk30;
    struct BuffDataStub* m_pkGeometryRendererData;
};


inline bool IsKindOfInline(const RttiStub* pkRTTI, GeomDataStub* pkObject)
{
    for (const RttiStub* p = pkObject->GetRTTI(); p; p = p->m_pBaseRTTI)
        if (p == pkRTTI)
            return true;
    return false;
}

struct BuffDataStub
{
    BuffDataStub() throw();
    static void* operator new(size_t uiSize)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::MemMgrStub *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize);
    }
    int unk00;
    unsigned int m_uiValue1;
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
    unsigned int m_uiType;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
};

struct PartitionStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned short unk20;
    unsigned short m_usStrips;
    int unk24;
    BuffDataStub* m_pkGeometryRendererData;
};

struct UnsharedGroupStub
{
    void CreateBufferData(GeomDataStub* pkData, bool bHasAnimation, PartitionStub* pkPartition);
};

// @fnv 0x00e953c0
void UnsharedGroupStub::CreateBufferData(GeomDataStub* pkData, bool abUnused, PartitionStub* pkPartition)
{
    BuffDataStub* pkBuffData;
    if (pkPartition)
    {
        if (pkPartition->m_pkGeometryRendererData)
            return;
        pkBuffData = new BuffDataStub;
        pkBuffData->m_uiType = (pkPartition->m_usStrips != 0) + 4;
        pkPartition->m_pkGeometryRendererData = pkBuffData;
    }
    else
    {
        if (pkData->m_pkGeometryRendererData)
            return;
        pkBuffData = new BuffDataStub;
        if (IsKindOfInline(&(*reinterpret_cast<const ::RttiStub *>(&::g_011f4a88)), pkData))
            pkBuffData->m_uiType = 4;
        else if (::FUN_0043b300((const ::NiRTTI *)(const ::RttiStub *)(&(*reinterpret_cast<const ::RttiStub *>(&::g_011f4a70))), (::NiAVObject *)(pkData)))
            pkBuffData->m_uiType = 5;
        pkData->m_pkGeometryRendererData = pkBuffData;
    }

    bool bColors = pkData->m_pkColor != 0;
    bool bHasNormals = pkData->m_pkNormal != 0;
    bool bBinormals = bHasNormals && (pkData->m_usFlags & 0xf000);
    unsigned int uiT = pkData->m_usFlags & 1;
    if (uiT > (unsigned int)(*reinterpret_cast<int *>(&::DAT_011bf558)))
        uiT = (*reinterpret_cast<int *>(&::DAT_011bf558));
    unsigned int uiFlags = 0;
    if (bColors)
        uiFlags = 0x400000;
    if (bHasNormals)
        uiFlags |= 0x800000;
    if (bBinormals)
        uiFlags |= 0x200000;
    pkBuffData->m_uiValue1 = (uiT << 24) | uiFlags;
    ::FUN_00e98730((intptr_t)this, (intptr_t)(pkBuffData), {});
    reinterpret_cast<::NiGeometryData *>((pkData))->SetDirtyFlags(0xffff);
}

struct ByteFlag
{
    union
    {
        bool value;
        unsigned int flags;
    };
    ByteFlag(bool b) : value(b)
    {}
};
struct MemoryAllocationProvider
{
};
struct Chip
{
    unsigned int index;
    MemoryAllocationProvider* set;
    void* buffer;
    unsigned int size;
    unsigned int offset;
    unsigned int stride;
};
MemoryAllocationProvider* __cdecl CreateBufferSetData(unsigned int, void*, unsigned int, unsigned int);
template <class T> struct Map
{
    unsigned int vtable, size;
    void* table;
    unsigned int count;
    bool FUN_00a53c30(unsigned int, T*&);
    void InsertOrUpdate(unsigned int, T*);
};
template <class T> struct Array
{
    unsigned int vtable;
    T** data;
    unsigned short capacity, size, firstFree, grow;
    void FUN_00a90180(unsigned int);
    void FUN_00ba3aa0(unsigned int, T* const&);
};
struct Data
{
    unsigned int unk00, unk04, unk08, key, unk10;
    bool flag;
    unsigned char unk15;
    unsigned short unk16;
    unsigned int unk18, stride, count;
    unsigned int* lengths;
    unsigned int unk28, unk2c, unk30, unk34, result;
};
struct Group
{
    unsigned int vtable, refs;
    void* device;
    Map<MemoryAllocationProvider> sets;
    Map<Chip> chips;
    Array<MemoryAllocationProvider> streamSets;
    Array<Chip> streamChips;
    unsigned int nextIndex;
    Chip* GetOrCreateChip(Data*, unsigned int);
};
struct NiMemObject
{
    static void* __cdecl operator new(size_t uiSize);
};
inline void* __cdecl operator new(size_t, void* pvMem) throw()
{
    return pvMem;
}
extern NiGeometryGroup* DAT_0126fa38;

// Creates the NiDynamicGeometryGroup singleton on first use and returns it.
// @fnv 0x00e95b10
NiGeometryGroup* __cdecl GetNiGeometryGroup() throw()
{
    if (!DAT_0126fa38)
        DAT_0126fa38 = new (NiMemObject::operator new(sizeof(NiDynamicGeometryGroup))) NiDynamicGeometryGroup;
    return DAT_0126fa38;
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct VertexBufferRef
{
    virtual void QueryInterface() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct BufferSetData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int size;
    VertexBufferRef* buffer;
    unsigned int unk10;
    unsigned int unk14;

    BufferSetData() : unk00(0), unk04(0), size(0), buffer(0), unk10(0)
    {}
    static void* operator new(size_t bytes)
    {
        return FUN_00aa13e0(bytes);
    }
    void SetBuffer(VertexBufferRef* value)
    {
        if (buffer)
            buffer->Release();
        if (value)
        {
            buffer = value;
            value->AddRef();
        }
        else
        {
            buffer = 0;
        }
    }
};

// @fnv 0x00e95230
MemoryAllocationProvider* __cdecl CreateBufferSetData(unsigned int size, void* buffer, unsigned int flags,
                                                      unsigned int kind)
{
    BufferSetData* set = new BufferSetData;
    if (set)
    {
        if (size & 15)
            size = (size & ~15U) + 32;
        set->size = size;
        set->SetBuffer((VertexBufferRef*)buffer);
        set->unk04 = flags;
        set->unk00 = kind;
    }
    return (MemoryAllocationProvider*)set;
}

namespace fnv_00e952c0 {
void _NiFreeAlias(void*);
struct MemoryManager
{
};
struct NiTMapBaseStub
{
    virtual void RemoveAll();
};
struct FUN_00e952c0 : NiTMapBaseStub
{
    int m_04;
    void* m_08;
    virtual ~FUN_00e952c0();
    static void operator delete(void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00e952c0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(p);
    }
};
// Destructor that calls RemoveAll and then frees the m_08 alias via _NiFreeAlias.
// @fnv 0x00e952c0
FUN_00e952c0::~FUN_00e952c0()
{
    RemoveAll();
    _NiFreeAlias(m_08);
}
}  // namespace fnv_00e952c0

namespace fnv_00e95340 {
void __cdecl _NiFreeAlias(void*);
struct MemoryManager
{
};
struct NiTMapBaseStub
{
};
struct FUN_00e95340
{
    int _04;
    void* _08;
    virtual ~FUN_00e95340();
    void operator delete(void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00e95340::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(p);
    }
};
// @fnv 0x00e95340
FUN_00e95340::~FUN_00e95340()
{
    reinterpret_cast<::S_00b601a0_Map *>((((NiTMapBaseStub*)this)))->FUN_00b601a0();
    _NiFreeAlias(_08);
}
}  // namespace fnv_00e95340

struct S_00e987c0_Stream
{
    void** vtable;
};

struct S_00e987c0_Device
{
    void** vtable;
};

typedef void(* FUN_00e987c0_StreamRelease)(S_00e987c0_Stream*);
typedef int(* FUN_00e987c0_Allocate)(S_00e987c0_Device*, unsigned int, unsigned int, void*, int, void*, int);

struct S_00e987c0_Class
{
    void* unk00;
    void* unk04;
    unsigned int unk08;
    S_00e987c0_Device* unk0c;
    S_00e987c0_Stream* unk10;
    unsigned int unk14;

    S_00e987c0_Stream* AllocateStream(unsigned int uiStream, unsigned int* lpOffset, unsigned int* lpFlags,
                                                 unsigned char bForceFallback, unsigned char bUseSpecialFlags);
};
// @fnv 0x00e95550
Chip* Group::GetOrCreateChip(Data* data, unsigned int stream)
{
    Chip* chip = 0;
    unsigned int count = data->count;
    unsigned int key = data->key;
    unsigned int length = stream < count ? data->lengths[stream] : 0;
    unsigned int stride = data->stride * length;
    unsigned int size = 0;
    unsigned int offset = 0;
    if (count > 1)
    {
        if (streamSets.capacity < count)
        {
            reinterpret_cast<::FUN_00a41520_cls *>(&(streamSets))->FUN_00a90180(count);
            reinterpret_cast<::FUN_00a41520_cls *>(&(streamChips))->FUN_00a90180(count);
        }
        if (nextIndex >= streamSets.capacity)
            nextIndex = 0;
        MemoryAllocationProvider* set = streamSets.data[nextIndex];
        if (!set)
        {
            set = CreateBufferSetData(2048, device, 0, 0);
            reinterpret_cast<::FUN_00a41520_cls *>(&(streamSets))->FUN_00ba3aa0(nextIndex, (::KeyPair **)&(set));
        }
        ByteFlag flag(data->flag);
        void* buffer = ((void *)(reinterpret_cast<::S_00e987c0_Class *>((set))->AllocateStream(stride, &size, &offset, true, (*(unsigned char *)&(const ::ByteFlag &)(flag)))));
        Chip* branchChip = streamChips.data[nextIndex];
        if (!branchChip)
        {
            branchChip = ((::Chip *)(::FUN_00537d60_Create(0, (uintptr_t)(buffer), size, stride, 0)));
            chip = branchChip;
            reinterpret_cast<::FUN_00a41520_cls *>(&(streamChips))->FUN_00ba3aa0(nextIndex, (::KeyPair **)&(chip));
        }
        else
        {
            branchChip->buffer = buffer;
            branchChip->size = size;
            branchChip->stride = stride;
        }
        branchChip->set = set;
        branchChip->offset = offset;
        data->result = 0;
        ++nextIndex;
        return branchChip;
    }
    else
    {
        MemoryAllocationProvider* set = 0;
        uintptr_t mapKey = key ? key : length | 0x80000000;
        if (!reinterpret_cast<::A54440Hash *>(&(sets))->FUN_00a53c30((::A54440Manager *)(mapKey), (::A54440Manager **)&(set)) || !set)
        {
            set = CreateBufferSetData(2048, device, key, 0);
            reinterpret_cast<::HashTableBase *>(&(sets))->InsertOrUpdate(mapKey, (uintptr_t)(set));
        }
        ByteFlag flag(data->flag);
        void* buffer = ((void *)(reinterpret_cast<::S_00e987c0_Class *>((set))->AllocateStream(stride, &size, &offset, false, (*(unsigned char *)&(const ::ByteFlag &)(flag)))));
        reinterpret_cast<::A54440Hash *>(&(chips))->FUN_00a53c30((::A54440Manager *)(mapKey), (::A54440Manager **)&(chip));
        Chip* result = chip;
        if (!result)
        {
            result = ((::Chip *)(::FUN_00537d60_Create(0, (uintptr_t)(buffer), size, stride, 0)));
            reinterpret_cast<::HashTableBase *>(&(chips))->InsertOrUpdate(mapKey, (uintptr_t)(result));
        }
        else
        {
            result->buffer = buffer;
            result->size = size;
            result->stride = stride;
        }
        result->set = set;
        result->offset = offset;
        data->result = size / length;
        return result;
    }
}

// Updates the stream size and allocation as needed, advances or resets the offset, sets flags, and returns the stream pointer.
// @fnv 0x00e987c0
S_00e987c0_Stream* S_00e987c0_Class::AllocateStream(unsigned int uiStream, unsigned int* lpOffset,
                                                               unsigned int* lpFlags, unsigned char bForceFallback,
                                                               unsigned char bUseSpecialFlags)
{
    if (unk08 < uiStream)
    {
        if (unk10 != 0)
        {
            FUN_00e987c0_StreamRelease pfnRelease = reinterpret_cast<FUN_00e987c0_StreamRelease>(unk10->vtable[2]);
            pfnRelease(unk10);
        }

        unk10 = 0;

        unsigned int uiSize = uiStream;
        if ((uiStream & 0x0f) != 0)
        {
            uiSize = (uiStream & 0xfffffff0u) + 0x20u;
        }
        unk08 = uiSize;
    }

    S_00e987c0_Stream** ppStream = &unk10;

    if (unk10 == 0)
    {
        unsigned int uiAllocationFlags = 0x208u;
        if (bUseSpecialFlags != 0)
        {
            uiAllocationFlags = 0x218u;
        }

        int iResult = (reinterpret_cast<FUN_00e987c0_Allocate>(reinterpret_cast<void**>(unk0c->vtable)[0x1a]))(
            unk0c, unk08, uiAllocationFlags, unk04, 0, static_cast<void*>(ppStream), 0);

        if (iResult >= 0)
        {
            unk14 = 0;
        }
    }

    if (bForceFallback == 0)
    {
        unsigned int uiCommitted = unk14;
        unsigned int uiRemaining = unk08 - uiCommitted;

        if (uiRemaining >= uiStream)
        {
            *lpOffset = uiCommitted;
            unk14 += uiStream;
            *lpFlags = 0x1000u;
            goto L_00b3;
        }
    }

    *lpOffset = 0;
    unk14 = uiStream;
    *lpFlags = 0x2000u;

L_00b3:
    if (*lpOffset == 0)
    {
        *lpFlags = 0x2000u;
    }

    return *ppStream;
}

extern unsigned int DAT_010f10c4;

struct ReleaseBuffer
{
    void** vtable;
};
typedef void(* ReleaseFn)(ReleaseBuffer*);
struct DynamicSetData
{
    unsigned int unk00, unk04, capacity;
    ReleaseBuffer* buffer0c;
    ReleaseBuffer* buffer10;
    unsigned int offset;
    void Destroy()
    {
        ReleaseBuffer* a = buffer10;
        if (a)
            ((ReleaseFn)a->vtable[2])(a);
        ReleaseBuffer* b = buffer0c;
        if (b)
            ((ReleaseFn)b->vtable[2])(b);
    }
};
struct DynamicChipData
{
    static void operator delete(void*, size_t);
    ~DynamicChipData()
    {
        buffer = 0;
    }
    unsigned int index;
    DynamicSetData* set;
    ReleaseBuffer* buffer;
    unsigned int size, offset, stride, unk18, unk1c;
};
template <class T> struct MapEntryData
{
    MapEntryData* next;
    const char* key;
    T* value;
};
template <class T> struct DynamicMapData;
template <class T> struct MapVtableData
{
    void* slot0;
    unsigned int(* hash)(DynamicMapData<T>*, const char*);
};
template <class T> struct DynamicMapData
{
    MapVtableData<T>* vtable;
    unsigned int size;
    MapEntryData<T>** table;
    unsigned int count;
    bool FUN_00e91fd0(const char*);
    void FUN_00b601a0();
    void Destroy(void* derivedVtable, void* baseVtable)
    {
        vtable = (MapVtableData<T>*)derivedVtable;
        reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
        vtable = (MapVtableData<T>*)baseVtable;
        reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
        _NiFree(table);
    }
    void* GetFirst() const
    {
        for (unsigned int i = 0; i < size; ++i)
            if (table[i])
                return table[i];
        return 0;
    }
    void GetNext(void*& pos, const char*& key, T*& value)
    {
        MapEntryData<T>* item = (MapEntryData<T>*)pos;
        key = item->key;
        value = item->value;
        if (item->next)
        {
            pos = item->next;
        }
        else
        {
            unsigned int i = vtable->hash(this, item->key);
            for (++i; i < size; i++)
            {
                item = table[i];
                if (item)
                {
                    pos = item;
                    return;
                }
            }
            pos = 0;
        }
    }
};
template <class T> struct DynamicArrayData
{
    void* vtable;
    T** data;
    unsigned short capacity, size, count, grow;
    T* RemoveAt(unsigned int i)
    {
        if (i >= size)
            return 0;
        T* value = data[i];
        data[i] = 0;
        if (value)
            --count;
        if (i == (unsigned short)(size - 1))
            --size;
        return value;
    }
};
struct DynamicGroupData
{
    void* vtable;
    unsigned int refs;
    void* device;
    DynamicMapData<DynamicSetData> sets;
    DynamicMapData<DynamicChipData> chips;
    DynamicArrayData<DynamicSetData> streamSets;
    DynamicArrayData<DynamicChipData> streamChips;
    unsigned int nextIndex;
    void FUN_00e95880();
};
// Calls FUN_00e95880, then deletes this with size 0x50 when bit 0 of uiFlags is set, and returns this.
// @fnv 0x00e95b40
void* FUN_00e95b40_shell::DestroyIfFlagged(unsigned int uiFlags)
{
    static_cast<::DynamicGroupData *>(nullptr)->FUN_00e95880();
    if (uiFlags & 1)
        operator delete(this, 0x50);
    return this;
}

// Iterates the set and chip maps and stream arrays, destroys entries, updates vtables, clears a matching global pointer, and calls FUN_00e98710.
// @fnv 0x00e95880
void DynamicGroupData::FUN_00e95880()
{
    vtable = &DAT_010f10c4;
    const char* key;
    DynamicSetData* set;
    DynamicChipData* chip;
    void* setPos = sets.GetFirst();
    while (setPos)
    {
        sets.GetNext(setPos, key, set);
        sets.FUN_00e91fd0(key);
        if (set)
        {
            set->Destroy();
            operator delete(set, sizeof(DynamicSetData));
        }
    }
    void* chipPos = chips.GetFirst();
    while (chipPos)
    {
        chips.GetNext(chipPos, key, chip);
        chips.FUN_00e91fd0(key);
        chip->buffer = 0;
        delete chip;
    }
    for (unsigned int i = 0; i < streamSets.capacity; ++i)
    {
        set = streamSets.RemoveAt(i);
        if (set)
        {
            set->Destroy();
            operator delete(set, sizeof(DynamicSetData));
        }
        chip = streamChips.RemoveAt(i);
        chip->buffer = 0;
        delete chip;
    }
    if (this == (void*)DAT_0126fa38)
        DAT_0126fa38 = 0;
    streamChips.vtable = &(*reinterpret_cast<unsigned int *>(&::DAT_010f0f7c));
    _NiFree(streamChips.data);
    streamSets.vtable = &DAT_010f1034;
    _NiFree(streamSets.data);
    chips.Destroy(&DAT_010f109c, &DAT_010f105c);
    sets.Destroy(&DAT_010f107c, &DAT_010f103c);
    reinterpret_cast<::FUN_00e98710_cls *>(this)->FUN_00e98710();
}

#include "generated/data/gamebryo2.2/corelibs/niconsolerenderer/nidynamicgeometrygroup.inc"
