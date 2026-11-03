
// src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkphavoksnapshot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "havok/hkUlong.h"
#include "fnv/symbols_00c85000.h"
#include <new>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00d47770.h"
#include "fnv/decl/FUN_00d49750.h"
#include "fnv/decl/FUN_00d4bab0.h"
#include "fnv/decl/FUN_00d4c220_s.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/HostType.h"
#include "fnv/decl/ReferencedObjectHolder.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/decl/fnv_00d4aa70__FUN_00d4aa70.h"
#include "fnv/decl/fnv_00d4c250__FUN_00d4c250.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d48000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_01268000.h"
struct Object
{
    void* unk00;
    unsigned short unk04;
    void FUN_00cc0ae0();
    Object* FUN_00cc0dd0(unsigned int flags);
};
// Calls FUN_00cc0ae0, and if flags has bit 0 set, notifies the interface from FUN_00c85750 with this and unk04; returns this.
// @fnv 0x00cc0dd0
Object* Object::FUN_00cc0dd0(unsigned int flags)
{
    FUN_00cc0ae0();
    if (flags & 1)
    {
        hkMemoryRouter* state = &hkMemoryRouter::getInstance();
        state->m_heap->blockFree(this, unk04);
    }
    return this;
}

struct D481D0StringPtr
{
    const char* m_pcText;

    D481D0StringPtr();
    void operator=(const char* s);
};

struct D481D0Class
{
};

struct D481D0ReferencedObject;

struct D481D0RefVariant
{
    D481D0ReferencedObject* m_ptr;

    D481D0RefVariant() : m_ptr(0)
    {}
public:
    void set(D481D0ReferencedObject* obj, const D481D0Class* pClassInfo);
};

struct FUN_00d481d0
{
    D481D0StringPtr m_name;
    D481D0StringPtr m_pClassName;
    D481D0RefVariant m_pReferencedResource;

    FUN_00d481d0(const char* name, D481D0ReferencedObject* object, const D481D0Class* pClassInfo);
};

// Stores the name, binds the object with its class, and caches the class name (or null) from the reference variant.
// @fnv 0x00d481d0
FUN_00d481d0::FUN_00d481d0(const char* name, D481D0ReferencedObject* object, const D481D0Class* apClass)
{
    reinterpret_cast<::SStringPtr *>((void *)&(const ::D481D0StringPtr &)(m_name))->FUN_00cb0c10(name);
    reinterpret_cast<::FUN_00d47770 *>(&(m_pReferencedResource))->SetObject((::hkReferencedObject *)(object), reinterpret_cast<intptr_t>(apClass));
    reinterpret_cast<::SStringPtr *>((void *)&(const ::D481D0StringPtr &)(m_pClassName))->FUN_00cb0c10(((const ::D481D0Class *)(reinterpret_cast<::ReferencedObjectHolder *>((void *)&(m_pReferencedResource))->FUN_00d477a0())) ? reinterpret_cast<::FnvClassNameNode *>((void *)(((const ::D481D0Class *)(reinterpret_cast<::ReferencedObjectHolder *>((void *)&(m_pReferencedResource))->FUN_00d477a0()))))->FUN_00d46d40() : 0);
}

struct CC0D30Result
{
    CC0D30Result();

    int m_iResultCode;
    int m_data;
};

struct CC0D30Registry
{
    int unk00;
};


CC0D30Result __cdecl FUN_00cc0bc0(const void* data, const CC0D30Registry& registry, const void* pClassInfo, void* out,
                                  int flags);

// @fnv 0x00cc0d30
CC0D30Result __cdecl FUN_00cc0d30(const void* data, const void* pClassInfo, void* out, int flags)
{
    return FUN_00cc0bc0(data, (*reinterpret_cast<::CC0D30Registry *>(&::g_01268b9c)), pClassInfo, out, flags);
}

struct S_00cc0d60_R
{
    char v;
    S_00cc0d60_R()
    {}
};
struct S_00cc0d60_A
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};
S_00cc0d60_R* FUN_00cc0d30(void** pa, S_00cc0d60_A* a, void* b, int c, int d);
// @fnv 0x00cc0d60
S_00cc0d60_R FUN_00cc0d60(void* a2, void* a3, int a4, int a5, int a6)
{
    S_00cc0d60_R res;
    void* c;
    c = a2;
    if (c && a3)
    {
        S_00cc0d60_A obj;
        new ((void *)&(obj)) ::FUN_00d4c220_s();
        reinterpret_cast<::HostType *>(&(obj))->FUN_00d4c2d0((::ClientType *)(c), a6);
        char r = FUN_00cc0d30(&a2, &obj, a3, a4, a5)->v;
        reinterpret_cast<::fnv_00d4c250::FUN_00d4c250 *>(&(obj))->fnv_00d4c250::FUN_00d4c250::~FUN_00d4c250();
        res.v = r;
    }
    else
    {
        res.v = 0;
    }
    return res;
}

struct Allocator
{
    virtual void* unk0();
    virtual void* allocate(unsigned int size);
};

// The leading members of hkpSampledHeightFieldShape (include/havok/hkpSampledHeightFieldShape.h, which this unit
// cannot include: its own hkBool and hkStringPtr differ from hkBase.h's).
struct SampledHeightFieldHead
{
    enum HeightFieldType
    {
        HEIGHTFIELD_USER = 2
    };
    void* m_pVtable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkUlong m_ulUserData;
    unsigned int m_type;
    int m_iXResolution;
    int m_iZResolution;
    float m_fHeightScale;
    unsigned char m_bUseProjectionBasedHeight;
    unsigned char m_ucHeightFieldType;
};

struct hkBool
{
    char m_kPointB;
    hkBool()
    {}
    hkBool(bool b) : m_kPointB(b)
    {}
    operator bool() const
    {
        return m_kPointB != 0;
    }
};

struct PtrList;

struct SnapshotBackOwner
{
    char m_before[0x24];
    void* m_object;  // +0x24
};
struct SnapshotBackLinked
{
    void* m_vtbl;
    int m_memSizeAndRefCount;
    SnapshotBackOwner* m_owner;  // +0x8
};

struct PtrList
{
    void** m_00;
    unsigned int m_04;
    unsigned int m_08;

    void** Add(void* o)
    {
        unsigned int i = m_04;
        void** slot = &m_00[i];
        *slot = o;
        if (slot == 0)
        {
            return 0;
        }
        m_04++;
        return slot;
    }
};

struct Obj70
{
    unsigned int unk00;
    unsigned short m_04;
};

struct Obj110
{
    unsigned int unk00;
    unsigned short m_04;
};

struct Obj80
{
    unsigned int unk00;
    unsigned short m_04;
};

struct TypeMatcher
{
    hkBool FUN_00d46d80(void* v);
};

struct GlobalObjectO2_00d472a0 : TypeMatcher
{
};

struct FUN_00cc08f0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    PtrList m_08;

    void FUN_00cc08f0(void** a1, void** a2);
};

// Checks type matchers on *a2, allocates and links a new object into m_08, or clears the pointer when the back-reference matches.
// @fnv 0x00cc08f0
void FUN_00cc08f0_cls::FUN_00cc08f0(void** a1, void** a2)
{
    void** cur = a2;

    if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(::g_01268f2c.FUN_00d46d80(*cur)))->FUN_005609f0())
    {
        if (*cur != (void*)&::g_01268eb4)
        {
            void* v = *a1;
            hkMemoryRouter* h = &hkMemoryRouter::getInstance();
            Obj70* o = (Obj70*)((Allocator*)h->m_heap)->allocate(0x70);
            o->m_04 = 0x70;
            o = ((::Obj70 *)(new ((void *)(o)) ::FUN_00d4bab0((*(const ::FUN_00dcd310 *)(v)))));
            PtrList* list = &m_08;
            hkMemoryRouter* h2 = &hkMemoryRouter::getInstance();
            if (list->m_04 == (list->m_08 & 0x3fffffff))
            {
                ::ResizeAudioStream((::AudioAllocator *)(h2->m_heap), (::AudioStream *)(list), sizeof(void*));
            }
            list->Add(o);
            *a1 = o;
            *a2 = (void*)&::g_01268eb4;
            cur = a2;
        }
    }
    if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(::g_01268e24.FUN_00d46d80(*cur)))->FUN_005609f0())
    {
        if (*cur != (void*)&::g_01268d4c)
        {
            void* v = *a1;
            hkMemoryRouter* h = &hkMemoryRouter::getInstance();
            Obj110* o = (Obj110*)((Allocator*)h->m_heap)->allocate(0x110);
            o->m_04 = 0x110;
            o = ((::Obj110 *)(new ((void *)(o)) ::fnv_00d4aa70::FUN_00d4aa70((const ::fnv_00d4aa70::FUN_00d569c0 *)(v))));
            PtrList* list = &m_08;
            hkMemoryRouter* h2 = &hkMemoryRouter::getInstance();
            if (list->m_04 == (list->m_08 & 0x3fffffff))
            {
                ::ResizeAudioStream((::AudioAllocator *)(h2->m_heap), (::AudioStream *)(list), sizeof(void*));
            }
            list->Add(o);
            *a1 = o;
            *a2 = (void*)&::g_01268d4c;
            return;
        }
    }
    if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(::g_01268c5c.FUN_00d46d80(*cur)))->FUN_005609f0())
    {
        void* v = *a1;
        if (static_cast<const SampledHeightFieldHead*>(v)->m_ucHeightFieldType == SampledHeightFieldHead::HEIGHTFIELD_USER)
        {
            hkMemoryRouter* h = &hkMemoryRouter::getInstance();
            Obj80* o = (Obj80*)((Allocator*)h->m_heap)->allocate(0x80);
            o->m_04 = 0x80;
            o = ((::Obj80 *)(new ((void *)(o)) ::FUN_00d49750((::HeightFieldSource *)(v))));
            PtrList* list = &m_08;
            hkMemoryRouter* h2 = &hkMemoryRouter::getInstance();
            if (list->m_04 == (list->m_08 & 0x3fffffff))
            {
                ::ResizeAudioStream((::AudioAllocator *)(h2->m_heap), (::AudioStream *)(list), sizeof(void*));
            }
            list->Add(o);
            *a1 = o;
            *a2 = (void*)&::g_01268c14;
        }
        return;
    }
    if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(::g_01268bcc.FUN_00d46d80(*cur)))->FUN_005609f0())
    {
        void* v = *a1;
        SnapshotBackOwner* back = static_cast<SnapshotBackLinked*>(v)->m_owner;
        if (back != 0 && back->m_object == v)
        {
            *a1 = 0;
            *cur = 0;
        }
    }
}

namespace fnv_00cc0ae0 {
struct PooledItem
{
    virtual void v00(int aiFlags);
};



extern int DAT_010c93e4;

struct FUN_00cc0ae0_cls
{
    const void* m_vptr00;
    unsigned int unk04;
    PooledItem** m_pItems;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void FUN_00cc0ae0();
};

// Sets the vtable pointer, calls v00(1) on each non-null item, frees the item array, empties it, and sets the vtable pointer to DAT_0102e388.
// @fnv 0x00cc0ae0
void FUN_00cc0ae0_cls::FUN_00cc0ae0()
{
    m_vptr00 = &DAT_010c93e4;
    for (int i = 0; i < m_iArrayLength; i++)
    {
        PooledItem* item = m_pItems[i];
        if (item != 0)
        {
            item->v00(1);
        }
    }
    hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
    hkMemoryAllocator* alloc = holder->m_heap;
    unsigned int cap = m_uCapBits;
    m_iArrayLength = 0;
    if ((cap & 0x80000000u) == 0)
    {
        alloc->bufFree(m_pItems, (cap & 0x3fffffffu) * (int)sizeof(m_pItems[0]));
    }
    m_pItems = 0;
    m_uCapBits = 0x80000000u;
    *(const void* volatile*)&m_vptr00 = &::DAT_0102e388;
}
}  // namespace fnv_00cc0ae0

namespace fnv_00cc0b50 {
struct SlotRec
{
    unsigned short m_u0;
    unsigned short m_flag;
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
};

struct SpawnedObject
{
    virtual void* v00();
    SlotRec m_slot;
    SpawnedObject()
    {
        m_slot.m_flag = 1;
        m_slot.m_kPointA = 0;
        m_slot.m_kPointB = 0;
        m_slot.m_iThirdValue = 0x80000000;
    }
};


struct InputBool223
{
    unsigned char value;
    inline operator bool() const
    {
        return value != 0;
    }
};
// Calls FUN_00d485a0 with a2, a3, a4, (bool)a5 and ctx (or a local object if null), stores whether it returned 0 into *out, and returns out.
// @fnv 0x00cc0b50
unsigned char* FUN_00cc0b50(unsigned char* apResult, unsigned int a2, unsigned int a3, unsigned int a4,
                            InputBool223 abFlag, unsigned int unk2c, SpawnedObject* ctx)
{
    SpawnedObject* pCtx = ctx;
    SpawnedObject localCtx;
    if (pCtx == 0)
    {
        pCtx = &localCtx;
    }
    int r = ::FUN_00d485a0(a2, a3, a4, (bool)abFlag, reinterpret_cast<intptr_t>(pCtx));
    *apResult = (unsigned char)(r == 0);
    reinterpret_cast<::fnv_00cc0ae0::FUN_00cc0ae0_cls *>(&(localCtx))->FUN_00cc0ae0();
    return apResult;
}
}  // namespace fnv_00cc0b50

// Moved from hkphavoksnapshot_ehsc_noehsc_variant.cpp (VEGAS-15).

// src/havok/physics/utilities/serialize/hkphavoksnapshot_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkphavoksnapshot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>
#include "fnv/decl/FUN_00d46d40_s.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00cc0000.h"

inline hkMemoryRouter* getRouter()
{
    return &hkMemoryRouter::getInstance();
}

struct HavokElementArray;

struct hkClassS
{
};
struct hkReferencedObjectS
{
};
struct hkStringPtr
{
    const char* m_pcText;
    hkStringPtr();
    ~hkStringPtr();
    void operator=(const char* s);
};
struct hkRefVariantS
{
    hkReferencedObjectS* m_pRetainedObject;
    hkRefVariantS() : m_pRetainedObject(0)
    {}
    __forceinline ~hkRefVariantS()
    {
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
};
struct NamedVariantS
{
    hkStringPtr m_name;
    hkStringPtr m_pClassName;
    hkRefVariantS m_pReferencedResource;

    __forceinline NamedVariantS()
    {}
    __forceinline ~NamedVariantS()
    {}

    __forceinline void set(const char* name, const void* object, const hkClassS* pClassInfo)
    {
        reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(m_name))->FUN_00cb0c10(name);
        reinterpret_cast<::FUN_00d47770 *>(&(m_pReferencedResource))->SetObject((::hkReferencedObject *)(object), reinterpret_cast<intptr_t>(pClassInfo));
        reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(m_pClassName))->FUN_00cb0c10(((const ::hkClassS *)(reinterpret_cast<::ReferencedObjectHolder *>((void *)&(m_pReferencedResource))->FUN_00d477a0())) ? reinterpret_cast<::FnvClassNameNode *>((void *)(((const ::hkClassS *)(reinterpret_cast<::ReferencedObjectHolder *>((void *)&(m_pReferencedResource))->FUN_00d477a0()))))->FUN_00d46d40() : 0);
    }
};
template <typename T> __forceinline void destruct(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

struct NamedVariantArray
{
    NamedVariantS* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline NamedVariantArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~NamedVariantArray()
    {
        hkMemoryAllocator& a = getRouter()->heap();
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(NamedVariantS));
    }
    __forceinline NamedVariantS& AllocatePair()
    {
        hkMemoryAllocator& a = getRouter()->heap();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&a), (::AudioStream *)(void *)(this), sizeof(NamedVariantS));
        new (m_data + m_iElementCount) NamedVariantS();
        return m_data[m_iElementCount++];
    }
};
struct hkRootLevelContainerS
{
    NamedVariantArray m_kNamedVariants;
    __forceinline hkRootLevelContainerS()
    {}
    __forceinline ~hkRootLevelContainerS()
    {}
};
struct hkResultS
{
    int m_pClassEnum;
    hkResultS();
};
hkResultS __cdecl FUN_00cc0b50(const void* object, const void* pClassInfo, int a3, int a4, int a5, int a6);

// @fnv 0x00cc0bc0
hkResultS __cdecl FUN_00cc0bc0(const void* object, const hkClassS& pClassInfo, int a3, int a4, int a5)
{
    hkRootLevelContainerS container;
    container.m_kNamedVariants.AllocatePair().set(reinterpret_cast<::FnvClassNameNode *>((void *)&(pClassInfo))->FUN_00d46d40(), object, &pClassInfo);
    return FUN_00cc0b50(&container, &(*reinterpret_cast<int *>(&::g_01268b54)), a3, a4, a5, 0);
}

// Moved from hkphavoksnapshot_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
#include "fnv/decl/FUN_00d61700_cls.h"
#include "fnv/decl/FUN_00d61df0_cls.h"
#include "fnv/decl/hkStringD618.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_01044000.h"
#include "fnv/symbols_01063000.h"
#include "fnv/symbols_011b3000.h"

#include <windows.h>
namespace DirectoryMemory {
}
__forceinline hkMemoryAllocator& tempAllocator()
{
    return hkMemoryRouter::getInstance().temp();
}
void __cdecl reserveDirectoryBuffer(hkMemoryAllocator&, void*, int, int);

template <class T> struct DirArrayBase
{
    T* data;
    int count;
    int capacityFlags;
    __forceinline DirArrayBase(T* p, int n, int capacity) : data(p), count(n), capacityFlags(capacity | 0x80000000)
    {}
    __forceinline ~DirArrayBase()
    {}
    __forceinline int capacity() const
    {
        return capacityFlags & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& allocator, int n)
    {
        int old = capacity();
        if (old < n)
        {
            int doubled = old * 2;
            reserveDirectoryBuffer(allocator, this, n < doubled ? doubled : n, sizeof(T));
        }
    }
    __forceinline void resize(hkMemoryAllocator& allocator, int n)
    {
        reserve(allocator, n);
        count = n;
    }
    __forceinline void release(hkMemoryAllocator& allocator)
    {
        count = 0;
        if ((capacityFlags & 0x80000000) == 0)
            allocator._bufFree<T>(data, capacity());
        data = 0;
        capacityFlags = 0x80000000;
    }
};
template <class T> struct DirTempArray : DirArrayBase<T>
{
    __forceinline DirTempArray(T* p, int n, int capacity) : DirArrayBase<T>(p, n, capacity)
    {}
    __forceinline ~DirTempArray()
    {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        hkMemoryAllocator* allocator = router->m_temp;
        this->count = 0;
        if ((this->capacityFlags & 0x80000000) == 0)
            allocator->bufFree(this->data, this->capacityFlags & 0x3fffffff);
        this->data = 0;
        this->capacityFlags = 0x80000000;
    }
    __forceinline void resize(int n)
    {
        DirArrayBase<T>::resize(tempAllocator(), n);
    }
};
template <class T, unsigned N> struct DirInlineArray : DirTempArray<T>
{
    T storage[N];
    __forceinline DirInlineArray() : DirTempArray<T>(storage, 0, N)
    {}
    __forceinline ~DirInlineArray()
    {}
};
struct DirectoryString
{
    DirInlineArray<char, 128> chars;
    __forceinline ~DirectoryString()
    {}
    inline int length() const
    {
        return chars.count - 1;
    }
    inline const char* text() const
    {
        return chars.data;
    }
    inline operator const char*() const
    {
        return chars.data;
    }
    inline void setLength(int n)
    {
        chars.resize(n + 1);
        chars.data[n] = 0;
    }
};

struct InitBuffer : DirectoryString
{
    __forceinline ~InitBuffer()
    {}
    InitBuffer()
    {
        setLength(0);
        chars.data[0] = 0;
    }
};
struct FUN_00d61a50 : DirectoryString
{
    __forceinline ~FUN_00d61a50()
    {}
    FUN_00d61a50(const char*);
};

struct DirectoryFlags
{
    unsigned bits;
    inline DirectoryFlags()
    {}
    inline DirectoryFlags(unsigned b) : bits(b)
    {}
};
struct DirectoryItem
{
    const char* name;
    unsigned modified;
    DirectoryFlags flags;
};
struct DirectoryArray
{
    DirectoryItem* data;
    int count, capacityFlags;
    __forceinline DirectoryItem& expand(hkMemoryAllocator& allocator)
    {
        if (count == (capacityFlags & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)&(allocator), (::AudioStream *)(void *)(this), sizeof(DirectoryItem));
        return data[count++];
    }
};
struct DirectoryOutput
{
    DirectoryArray entries;
    hkMemoryAllocator* allocator;
    __forceinline void add(const char* name, DirectoryFlags flags, unsigned modified = 0)
    {
        DirectoryItem& item = entries.expand(*allocator);
        item.name = ::FUN_00cb1160(name, (void *)&(*allocator));
        item.flags = flags;
        item.modified = modified;
    }
    __forceinline void addDirectory(const char* name)
    {
        add(name, 2);
    }
    __forceinline void addFile(const char* name, unsigned modified = 0)
    {
        add(name, 1, modified);
    }
};
typedef const char*(__cdecl* DirectoryConvert)(const char*, DirectoryString&);
extern const char DAT_0101ffbc[], DAT_010a2560[];
struct DirectoryBool
{
    char value;
    inline DirectoryBool()
    {}
    inline DirectoryBool(bool b)
    {
        value = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return value != 0;
    }
    inline DirectoryBool& operator=(bool b)
    {
        value = static_cast<char>(b);
        return *this;
    }
};
enum DirectoryResult
{
    DirectorySuccess,
    DirectoryFailure
};

// @fnv 0x00da25a0
DirectoryResult __cdecl FUN_00da25a0(const char* input, DirectoryOutput& listing)
{
    InitBuffer path;
    {
        FUN_00d61a50 normalized(input);
        if (normalized.length() > 0)
        {
            reinterpret_cast<::hkStringD618 *>(&(normalized))->ReplaceChar('\\', '/', 1);
            if (!reinterpret_cast<::FUN_00d61700_cls *>((void *)&(normalized))->EndsWith((char *)(DAT_01063cbc)))
                reinterpret_cast<::FUN_00d61df0_cls *>(&(normalized))->FUN_00d61df0(reinterpret_cast<intptr_t>(DAT_01063cbc));
            (*reinterpret_cast<const char *(**)(const char *, DirectoryString &)>(&::DAT_011b3dc0))(normalized.text(), path);
        }
    }
    DWORD attrs = GetFileAttributesA(path);
    if (attrs == INVALID_FILE_ATTRIBUTES)
        return DirectoryFailure;
    bool valid = (attrs & FILE_ATTRIBUTE_DIRECTORY) != 0;
    if (!valid)
        return DirectoryFailure;
    if (path.length())
        reinterpret_cast<::FUN_00d61df0_cls *>(&(path))->FUN_00d61df0(reinterpret_cast<intptr_t>(DAT_0101ffbc));
    WIN32_FIND_DATAA found;
    HANDLE handle = FindFirstFileA(path, &found);
    DirectoryBool more = handle != INVALID_HANDLE_VALUE;
    while (more)
    {
        if (::fnv_00cb0fa0::FUN_00cb0fa0(found.cFileName, DAT_01044c28) && ::fnv_00cb0fa0::FUN_00cb0fa0(found.cFileName, DAT_010a2560))
        {
            bool directory = (found.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
            if (directory)
            {
                listing.addDirectory(found.cFileName);
            }
            else
            {
                LARGE_INTEGER epoch = {0};
                epoch.QuadPart = 0x19db1ded53e8000LL;
                __int64 seconds = (*(__int64*)&found.ftLastWriteTime - epoch.QuadPart) / 10000000;
                listing.addFile(found.cFileName, (unsigned)seconds);
            }
        }
        more = FindNextFileA(handle, &found) != 0;
    }
    FindClose(handle);
    return DirectorySuccess;
}

#include "generated/data/havok/physics/utilities/serialize/hkphavoksnapshot.inc"
