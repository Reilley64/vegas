
// src/havok/common/base/object/hkreferencedobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/object/hkreferencedobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <cstddef>
#include <new>
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00c90000.h"
#include <xmmintrin.h>
#include <windows.h>
#include "fnv/decl/FUN_00d21ce0_cls.h"
#include "fnv/decl/FUN_00e5c490_cls.h"
#include "fnv/symbols_00cf4000.h"
#include "fnv/symbols_00e3e000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
#include "fnv/tls.h"
#include "havok/hkReferencedObject.h"

struct hkCriticalSectionDataC905 : CRITICAL_SECTION
{
};

struct hkReferencedObjectLockC905
{
    void* unk00;
    int unk04;
    int m_multiThreaded;
    int m_lLockCount;
    int unk10;
    int unk14;
    hkCriticalSectionDataC905 m_kCriticalSection;
};

struct FUN_00c903b0_class
{
    void** m_pVTable;
    short m_uiObjectFlags;
    short m_uCount;
    void ReleaseReference();
};

// @fnv 0x00c903b0
void FUN_00c903b0_class::ReleaseReference()
{
    if (m_uiObjectFlags)
    {
        --m_uCount;
        if (!m_uCount)
            ((void(*)(void*, int))m_pVTable[0])(this, 1);
    }
}

struct FUN_00c903a0_class
{
    void FUN_00c903a0();
};

// @fnv 0x00c903a0
void FUN_00c903a0_class::FUN_00c903a0()
{
    if ((*(short*)((char*)this + 4)) != 0)
        (*(short*)((char*)this + 6))++;
}

// @fnv 0x00c90410
void __cdecl FUN_00c90410(int v)
{
    reinterpret_cast<hkReferencedObjectLockC905*>(DAT_012681d4)->m_multiThreaded = v;
}


// @fnv 0x00c903d0
int* __cdecl FUN_00c903d0()
{
    return &(*reinterpret_cast<int *>(&::DAT_0102e388));
}

struct DDCC60World
{
};
struct RefObj
{
};
struct FUN_00cd29c0_class
{
    void FUN_00cd29c0(RefObj*);
};
struct FUN_00cdf6e0_class
{
    void** m_pVTable;
    short m_uiObjectFlags;
    short m_uCount;
    char m_auiShapeKeys[4];
    hkReferencedObject* m_pObject;
    void SetReferencedObject(hkReferencedObject* pObject);
};

struct FUN_00cdf6e0_Ref : hkReferencedObject
{
};

namespace fnv_00d47750 {
struct RefObj
{
    void FUN_00c90510();
};

struct FUN_00d47750_class
{
    RefObj* m_pObject;

    FUN_00d47750_class* AssignObject(RefObj** pObject);
};

// @fnv 0x00d47750
FUN_00d47750_class* FUN_00d47750_class::AssignObject(RefObj** pObject)
{
    RefObj* object = *pObject;
    if (object)
        object->FUN_00c90510();

    m_pObject = object;
    return this;
}
}  // namespace fnv_00d47750

class hkReferencedObjectC905 : public hkReferencedObject
{
  public:
    void FUN_00c905b0();
};

namespace fnv_00dee6f0 {
struct RefObj
{
    void FUN_00c90510();
};
struct FUN_00dee6f0_class
{
    void* m_pVTable;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    RefObj* m_pObject;
    void FUN_00dee6f0(RefObj* pObject);
};
// @fnv 0x00dee6f0
void FUN_00dee6f0_class::FUN_00dee6f0(RefObj* pNewObject)
{
    if (pNewObject)
        pNewObject->FUN_00c90510();
    if (m_pObject)
        ((::hkReferencedObjectC905*)m_pObject)->FUN_00c905b0();
    m_pObject = pNewObject;
}
}  // namespace fnv_00dee6f0

namespace fnv_00e3e840 {
struct FUN_00d1df70
{
    void RetainReference();
};

struct DDCC60World : public FUN_00d1df70
{
    void removeReference();
};

struct FUN_00e3e840_data
{
    DDCC60World* m_pWorld;
    int m_value0;
    int m_value1;
};

struct FUN_00e3e840_result
{
    DDCC60World* m_pWorld;

    void AssignObject(int* value);
};

struct FUN_00e5c4d0_class
{
    void FUN_00e5c4d0(FUN_00e3e840_data* data, int key);
};

struct FUN_00e3e840_class
{
    void* m_pUnknown0;
    void* m_pUnknown1;
    unsigned char* m_pItems;
    int m_uiItemCount;

    FUN_00e3e840_result* FindWorldByKey(FUN_00e3e840_result* result, int key);
};

// @fnv 0x00e3e840
FUN_00e3e840_result* FUN_00e3e840_class::FindWorldByKey(FUN_00e3e840_result* result, int key)
{
    FUN_00e3e840_data data;

    if (key != 0)
    {
        int index = 0;

        if (m_uiItemCount > 0)
        {
            int offset = 0;

            do
            {
                reinterpret_cast<FUN_00e5c4d0_class*>(m_pItems + offset)->FUN_00e5c4d0(&data, key);

                if (data.m_pWorld)
                {
                    data.m_pWorld->RetainReference();
                    result->m_pWorld = data.m_pWorld;
                    if (data.m_pWorld)
                        data.m_pWorld->removeReference();
                    return result;
                }

                data.m_pWorld = 0;
                ++index;
                offset += 16;
            } while (index < m_uiItemCount);
        }
    }

    data.m_value0 = 0;
    data.m_value1 = 0;
    result->AssignObject(&data.m_value0);
    return result;
}
}  // namespace fnv_00e3e840


// @fnv 0x00c90480
int __cdecl FUN_00c90480()
{
    return reinterpret_cast<hkReferencedObjectLockC905*>(DAT_012681d4)->m_multiThreaded;
}

struct Object_9bf0
{
};
struct Owner_9bf0
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Object_9bf0* m_object;
    void FUN_00c89bf0(Object_9bf0* next);
};
struct RestoreMode_9bf0
{
    int original;
    RestoreMode_9bf0() : original(g_tlsBlock.memoryContext)
    {
        g_tlsBlock.memoryContext = 0x10;
    }
    ~RestoreMode_9bf0()
    {
        g_tlsBlock.memoryContext = original;
    }
};
struct Obj
{
    void* a;
    unsigned short w;
    void Init();
};
struct Alloc
{
    virtual ~Alloc();
    virtual Obj* Allocate(unsigned n);
};
struct Mgr
{
    void* pad[4];
    Alloc* m_alloc;
    Obj* New(unsigned n)
    {
        return m_alloc->Allocate(n);
    }
};
// @fnv 0x00c903e0
void CreateAndInitObj()
{
    Obj* o = static_cast<Mgr*>(::FUN_00c85750())->New(sizeof(hkReferencedObjectLockC905));
    o->w = sizeof(hkReferencedObjectLockC905);
    o->Init();
}

extern int DAT_012681d8;

// Increments the TLS-guarded counter if the TLS slot holds the sentinel, otherwise enters the critical section, resets the counter to 1 and sets the TLS slot.
// @fnv 0x00c90490
void __cdecl EnterTlsGuard()
{
    hkReferencedObjectLockC905* st = reinterpret_cast<hkReferencedObjectLockC905*>(DAT_012681d4);
    if ((intptr_t)TlsGetValue(DAT_012681d8) == 0x23df4554)
    {
        st->m_lLockCount++;
        return;
    }
    EnterCriticalSection(&st->m_kCriticalSection);
    st->m_lLockCount = 1;
    TlsSetValue(DAT_012681d8, (void*)0x23df4554);
}



// @fnv 0x00c905b0
void hkReferencedObjectC905::FUN_00c905b0()
{
    if (m_usMemSizeAndFlags != 0)
    {
        if (m_sReferenceCount == 1)
        {
            m_sReferenceCount = 0;
            delete this;
            return;
        }
        hkReferencedObjectLockC905* pkLock = reinterpret_cast<hkReferencedObjectLockC905*>(DAT_012681d4);
        const unsigned long kTls = DAT_012681d8;
        if (pkLock->m_multiThreaded == 1 && TlsGetValue(kTls) != reinterpret_cast<void*>(0x23df4554))
        {
            if (TlsGetValue(kTls) == reinterpret_cast<void*>(0x23df4554))
            {
                pkLock->m_lLockCount++;
            }
            else
            {
                EnterCriticalSection(&pkLock->m_kCriticalSection);
                pkLock->m_lLockCount = 1;
                TlsSetValue(kTls, reinterpret_cast<void*>(0x23df4554));
            }
            m_sReferenceCount--;
            if (--pkLock->m_lLockCount <= 0)
            {
                TlsSetValue(kTls, 0);
                LeaveCriticalSection(&pkLock->m_kCriticalSection);
            }
        }
        else
        {
            m_sReferenceCount--;
        }
    }
}

struct ObjectRef
{
};
struct ThreadFlagGuard
{
    int previousFlag;
    ThreadFlagGuard() : previousFlag(g_tlsBlock.memoryContext)
    {
        g_tlsBlock.memoryContext = 16;
    }
    ~ThreadFlagGuard()
    {
        g_tlsBlock.memoryContext = previousFlag;
    }
};
struct FUN_00ca9b40_class
{
    void** m_pVTable;
    short m_uiObjectFlags;
    short m_uCount;
    int m_extraneousState;
    ObjectRef* m_pObject;
    void FUN_00ca9b40(ObjectRef* pObject);
};
struct DeviceCallback
{
    int unk00;
    int m_total;
    int(__cdecl* m_callback)(DeviceCallback*, void*, int, int*, int);
    __forceinline void Process(void* p)
    {
        int size = 4;
        m_total += m_callback(this, p, 4, &size, 1);
    }
};
struct Resource
{
};
struct DeviceOwner;
struct DeviceSubobject
{
};
struct DeviceOwner
{
    int unk00, unk04, unk08, unk0c;
    DeviceSubobject m_subobject;
    int unk14, unk18, m_payload;
};
struct InputObject
{
    DeviceCallback* GetCallback() const
    {
        return *reinterpret_cast<DeviceCallback* const*>(reinterpret_cast<const char*>(this) + 0x24c);
    }
};
struct FUN_00ca9ce0_class
{
    int unk00;
    DeviceOwner* m_pOwnerObject;
    void ProcessInput(InputObject*);
};
struct FUN_00d1df70
{
    void FUN_00c90510() throw();
};

template <class T> struct hkRefPtrE3EE
{
    T* m_pRetainedObject;

    hkRefPtrE3EE(const hkRefPtrE3EE& rp) throw()
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~hkRefPtrE3EE() throw()
    {
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pRetainedObject))->FUN_00c905b0();
    }
    void operator=(T* e) throw()
    {
        if (e)
            e->FUN_00c90510();
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = e;
    }
    void operator=(const hkRefPtrE3EE& rp) throw()
    {
        if (this != &rp)
            *this = rp.m_pRetainedObject;
    }
};

struct HeapEntryE3EE
{
    hkRefPtrE3EE<FUN_00d1df70> m_object;
    int m_primary;
    int m_secondary;
};

struct HeapLessE3EE
{
    bool operator()(const HeapEntryE3EE& kA, const HeapEntryE3EE& kB) const
    {
        return kB.m_primary > kA.m_primary || (kA.m_primary == kB.m_primary && kA.m_secondary < kB.m_secondary);
    }
};

// Restores the heap property by sifting the entry at index k down through the array using cmpLess.
// @fnv 0x00e3eec0
void __cdecl SiftDownHeap(HeapEntryE3EE* apEntries, int aiIndex, int aiCount, HeapLessE3EE aCompare)
{
    HeapEntryE3EE entryTemp = apEntries[aiIndex - 1];
    while (aiIndex <= aiCount / 2)
    {
        int child = 2 * aiIndex;
        if ((child < aiCount) && aCompare(apEntries[child - 1], apEntries[child]))
            child++;
        if (aCompare(entryTemp, apEntries[child - 1]))
        {
            apEntries[aiIndex - 1] = apEntries[child - 1];
            aiIndex = child;
        }
        else
        {
            break;
        }
    }
    apEntries[aiIndex - 1] = entryTemp;
}

struct Ref_00c89b60
{
};



struct Scope_00c89b60
{
    int saved;
    Scope_00c89b60()
    {
        saved = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = 0x10;
    }
    ~Scope_00c89b60()
    {
        g_tlsBlock.memoryContext = saved;
    }
};

struct Obj_00c89b60
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Ref_00c89b60* m_pReference;
    void FUN_00c89b60(Ref_00c89b60* r);
};

class hkMemoryAllocatorC904
{
  public:
    virtual ~hkMemoryAllocatorC904() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterC904
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    hkMemoryAllocatorC904* m_pStreamAllocator;

    hkMemoryAllocatorC904& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterC904 {
}

class hkRefObjC904
{
  public:
    virtual ~hkRefObjC904();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjC904()
    {
        m_sReferenceCount = 1;
    }

    static void* operator new(std::size_t nbytes)
    {
        hkRefObjC904* b = static_cast<hkRefObjC904*>((*static_cast<hkMemoryRouterC904*>(::FUN_00c85750())).heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class FUN_00c90830 : public hkRefObjC904
{
  public:
    FUN_00c90830() throw();

    int m_08;
    int unk0C[9];
};

namespace hkSingletonC904 {
}

static inline void replaceInstanceC904(FUN_00c90830* p)
{
    if ((*reinterpret_cast<::FUN_00c90830 * *>(&::DAT_012681d4)))
        reinterpret_cast<::FUN_00c903b0_class *>(((*reinterpret_cast<::FUN_00c90830 * *>(&::DAT_012681d4))))->ReleaseReference();
    (*reinterpret_cast<::FUN_00c90830 * *>(&::DAT_012681d4)) = p;
}

// Stores value into m_08 of the singleton, creating a FUN_00c90830 instance first if DAT_012681d4 is null.
// @fnv 0x00c90420
void __cdecl FUN_00c90420(int value)
{
    if (!(*reinterpret_cast<::FUN_00c90830 * *>(&::DAT_012681d4)))
    {
        FUN_00c90830* p = new FUN_00c90830();
        p->m_08 = value;
        replaceInstanceC904(p);
    }
    else
    {
        (*reinterpret_cast<::FUN_00c90830 * *>(&::DAT_012681d4))->m_08 = value;
    }
}

struct FUN_00c90510_class
{
    void** m_pVTable;
    short m_uiObjectFlags;
    short m_uCount;
    void FUN_00c90510();
};
// @fnv 0x00cd29c0
void FUN_00cd29c0_class::FUN_00cd29c0(RefObj* object)
{
    reinterpret_cast<::FUN_00c90510_class *>((object))->FUN_00c90510();
    DDCC60World* pOldWorld = *reinterpret_cast<DDCC60World**>(reinterpret_cast<unsigned char*>(this) + 0x84);
    if (pOldWorld)
        reinterpret_cast<::hkReferencedObjectC905 *>((pOldWorld))->FUN_00c905b0();
    *reinterpret_cast<RefObj**>(reinterpret_cast<unsigned char*>(this) + 0x84) = object;
}
// @fnv 0x00cdf6e0
void FUN_00cdf6e0_class::SetReferencedObject(hkReferencedObject* pObject)
{
    FUN_00cdf6e0_Ref* pNewRef = (FUN_00cdf6e0_Ref*)pObject;
    if (pNewRef)
        reinterpret_cast<::FUN_00c90510_class *>((pNewRef))->FUN_00c90510();
    FUN_00cdf6e0_Ref* pOldRef = (FUN_00cdf6e0_Ref*)m_pObject;
    if (pOldRef)
        reinterpret_cast<::hkReferencedObjectC905 *>((pOldRef))->FUN_00c905b0();
    m_pObject = pObject;
}
// @fnv 0x00c89bf0
void Owner_9bf0::FUN_00c89bf0(Object_9bf0* apObject)
{
    RestoreMode_9bf0 scoped;
    if (apObject)
        reinterpret_cast<::FUN_00c90510_class *>((apObject))->FUN_00c90510();
    if (m_object)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_object))->FUN_00c905b0();
    m_object = apObject;
}
// @fnv 0x00ca9b40
void FUN_00ca9b40_class::FUN_00ca9b40(ObjectRef* pObject)
{
    ThreadFlagGuard guard;
    if (pObject)
        reinterpret_cast<::FUN_00c90510_class *>((pObject))->FUN_00c90510();
    if (m_pObject)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pObject))->FUN_00c905b0();
    m_pObject = pObject;
}
// Sets m_pReference to r, calling FUN_00c90510 on the new reference and FUN_00c905b0 on the old one if present.
// @fnv 0x00c89b60
void Obj_00c89b60::FUN_00c89b60(Ref_00c89b60* apReference)
{
    Scope_00c89b60 s;
    if (apReference)
        reinterpret_cast<::FUN_00c90510_class *>((apReference))->FUN_00c90510();
    if (m_pReference)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pReference))->FUN_00c905b0();
    m_pReference = apReference;
}

extern int DAT_012681d8;
extern int(* DAT_00fdf044)(int);
extern int(* DAT_00fdf04c)(int, int);
extern void(* DAT_00fdf05c)(void*);
extern void(* DAT_00fdf100)(void*);

// @fnv 0x00c90510
void FUN_00c90510_class::FUN_00c90510()
{
    if (!m_uiObjectFlags)
        return;

    hkReferencedObjectLockC905* state = reinterpret_cast<hkReferencedObjectLockC905*>(DAT_012681d4);
    int one = 1;

    if (state->m_multiThreaded == one)
    {
        void*(* getValue)(unsigned long) = reinterpret_cast<void*(*)(unsigned long)>(DAT_00fdf044);
        uintptr_t value = (uintptr_t)getValue(DAT_012681d8);

        if (value != 0x23df4554)
        {
            value = (uintptr_t)getValue(DAT_012681d8);

            int(* setValue)(unsigned long, void*) = reinterpret_cast<int(*)(unsigned long, void*)>(DAT_00fdf04c);

            if (value == 0x23df4554)
            {
                state->m_lLockCount += one;
            }
            else
            {
                DAT_00fdf05c(&state->m_kCriticalSection);
                state->m_lLockCount = one;
                setValue(DAT_012681d8, (void*)(uintptr_t)0x23df4554);
            }

            m_uCount += one;
            --state->m_lLockCount;

            if (state->m_lLockCount <= 0)
            {
                setValue(DAT_012681d8, nullptr);
                DAT_00fdf100(&state->m_kCriticalSection);
            }

            return;
        }
    }

    m_uCount += one;
}

namespace fnv_00cc49b0 {
struct ShortPair
{
    int first;
    int second;
};
struct ByteFlag
{
    unsigned char value;
    ByteFlag(bool v) : value(v)
    {}
    ByteFlag(const ByteFlag& other) : value(other.value)
    {}
};
struct FUN_00c90510_class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24(ByteFlag flag, ShortPair* output);
};
struct FUN_00cc49b0_class;
struct FUN_00d21ce0_class
{
    int unk0c, unk10, unk14;
};
struct FUN_00cc49b0_class
{
    int unk00, unk04, unk08;
    FUN_00d21ce0_class subobject;
    FUN_00c90510_class* owner;
    unsigned short state;
    unsigned short substate;
    void FUN_00cc49b0(FUN_00c90510_class* value);
};
struct ScopedThreadState
{
    int previous;
    ScopedThreadState()
    {
        previous = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = 16;
    }
    ~ScopedThreadState()
    {
        g_tlsBlock.memoryContext = previous;
    }
};
// Retains value if present, releases owner if present, assigns value, copies two values from vf24, and calls subobject.FUN_00d21ce0(this).
// @fnv 0x00cc49b0
void FUN_00cc49b0_class::FUN_00cc49b0(FUN_00c90510_class* apOwner)
{
    ScopedThreadState thread;
    if (apOwner)
        reinterpret_cast<::FUN_00c90510_class *>((apOwner))->FUN_00c90510();
    if (owner)
        reinterpret_cast<::hkReferencedObjectC905 *>((owner))->FUN_00c905b0();
    owner = apOwner;
    ShortPair result;
    owner->vf24(ByteFlag(true), &result);
    state = (unsigned short)result.first;
    substate = (unsigned short)result.second;
    reinterpret_cast<::FUN_00d21ce0_cls *>(&(subobject))->FUN_00d21ce0(this);
}
}  // namespace fnv_00cc49b0

class NiBinaryStreamCC4
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamCC4*, void*, unsigned int, unsigned int*, unsigned int);

    template <class T> void Read(T& value)
    {
        unsigned int uiSize = sizeof(T);
        m_uiStreamFlags += m_pfnRead(this, &value, sizeof(T), &uiSize, 1);
    }
};

struct NiStream
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC;
    int unk1E0, unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC, unk200, unk204, unk208, unk20C;
    int unk210, unk214, unk218, unk21C, unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    int unk240, unk244, unk248;
    NiBinaryStreamCC4* m_pUnderlyingStream;
};

class hkRefCC4
{
  public:
};

class hkShapeCC4 : public hkRefCC4
{
};

class hkpWorldObjectCC4
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int m_iLayer;
    unsigned char m_ucFlags;

};

class FUN_00d53200_class
{
  public:
    virtual ~FUN_00d53200_class();
    void FUN_00c8a230(NiStream& kStream);
};
// @fnv 0x00ca9ce0
void FUN_00ca9ce0_class::ProcessInput(InputObject* input)
{
    reinterpret_cast<::FUN_00d53200_class *>(this)->FUN_00c8a230((*(::NiStream *)(input)));
    DeviceOwner* owner = m_pOwnerObject;
    Resource* resource = ((::Resource *)(::FUN_00cf4af0((*(::CF4BC0Stream *)(input)))));
    reinterpret_cast<::FUN_00ca9b40_class *>((owner))->FUN_00ca9b40((::ObjectRef *)(resource));
    reinterpret_cast<::FUN_00d21ce0_cls *>(&(owner->m_subobject))->FUN_00d21ce0(owner);
    reinterpret_cast<::hkReferencedObjectC905 *>((resource))->FUN_00c905b0();
    DeviceCallback* callback = input->GetCallback();
    callback->Process(&owner->m_payload);
}


class bhkWorldObjectCC4 : public FUN_00d53200_class
{
  public:
    hkpWorldObjectCC4* m_pPointer;

    void FUN_00cc4e10(NiStream& kStream);
};

// Reads a shape, attaches it to the hkpWorldObject, and deserializes its layer and flags from the stream.
// @fnv 0x00cc4e10
void bhkWorldObjectCC4::FUN_00cc4e10(NiStream& kStream)
{
    FUN_00c8a230(kStream);
    hkpWorldObjectCC4* pkObject = m_pPointer;
    hkShapeCC4* pkShape = ((::hkShapeCC4 *)(::FUN_00cf4af0((::CF4BC0Stream &)(kStream))));
    reinterpret_cast<::fnv_00cc49b0::FUN_00cc49b0_class *>((pkObject))->FUN_00cc49b0((::fnv_00cc49b0::FUN_00c90510_class *)(pkShape));
    reinterpret_cast<::hkReferencedObjectC905 *>((pkShape))->FUN_00c905b0();
    kStream.m_pUnderlyingStream->Read(pkObject->m_iLayer);
    kStream.m_pUnderlyingStream->Read(pkObject->m_ucFlags);
}

struct RcObject
{
};
struct SortEntry
{
    RcObject* object;
    int key;
    int value;
};
// Sorts an array of SortEntry in place using a heap sort, sifting down to build the heap and then extracting elements.
// @fnv 0x00e3eff0
void __cdecl HeapSort(SortEntry* entries, int count, int compare)
{
    int remaining = count;
    int index = count / 2;
    while (index > 0)
    {
        ::SiftDownHeap((::HeapEntryE3EE *)(entries), index, count, ::HeapLessE3EE());
        --index;
    }
    if (remaining >= 1)
    {
        SortEntry* last = &entries[remaining - 1];
        do
        {
            if (entries->object)
                reinterpret_cast<::FUN_00c90510_class *>((entries->object))->FUN_00c90510();
            SortEntry copyEntry = *entries;
            if (entries != last)
            {
                RcObject* GetObject = last->object;
                if (GetObject)
                    reinterpret_cast<::FUN_00c90510_class *>((GetObject))->FUN_00c90510();
                if (entries->object)
                    reinterpret_cast<::hkReferencedObjectC905 *>((entries->object))->FUN_00c905b0();
                entries->object = GetObject;
            }
            entries->key = last->key;
            entries->value = last->value;
            if (last != &copyEntry)
            {
                if (copyEntry.object)
                    reinterpret_cast<::FUN_00c90510_class *>((copyEntry.object))->FUN_00c90510();
                if (last->object)
                    reinterpret_cast<::hkReferencedObjectC905 *>((last->object))->FUN_00c905b0();
                last->object = copyEntry.object;
            }
            last->key = copyEntry.key;
            last->value = copyEntry.value;
            --remaining;
            --last;
            ::SiftDownHeap((::HeapEntryE3EE *)(entries), 1, remaining, ::HeapLessE3EE());
            if (copyEntry.object)
                reinterpret_cast<::hkReferencedObjectC905 *>((copyEntry.object))->FUN_00c905b0();
        } while (remaining >= 1);
    }
}

struct Resource_e3eb
{
};

template <class T> struct hkRefPtr_e3eb
{
    T* m_pRetainedObject;
    hkRefPtr_e3eb() throw() : m_pRetainedObject(0)
    {}
    hkRefPtr_e3eb(T* const& e) throw()
    {
        if (e)
            reinterpret_cast<::FUN_00c90510_class *>((e))->FUN_00c90510();
        m_pRetainedObject = e;
    }
    hkRefPtr_e3eb(const hkRefPtr_e3eb& rp) throw()
    {
        if (rp.m_pRetainedObject)
            reinterpret_cast<::FUN_00c90510_class *>((rp.m_pRetainedObject))->FUN_00c90510();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~hkRefPtr_e3eb() throw()
    {
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
};

struct Container_e3eb
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    Resource_e3eb* m_resource;
    int unk1C, unk20, unk24;
    Container_e3eb** m_children;
    int m_numChildren;
    hkRefPtr_e3eb<Resource_e3eb> FUN_00e3eb10(Resource_e3eb* target) throw();
};

// Recursively searches this container and its children for the given Resource_e3eb, returning a reference-counted pointer to it or an empty reference.
// @fnv 0x00e3eb10
hkRefPtr_e3eb<Resource_e3eb> Container_e3eb::FUN_00e3eb10(Resource_e3eb* apResource) throw()
{
    if (m_resource == apResource)
        return hkRefPtr_e3eb<Resource_e3eb>(m_resource);
    for (int i = 0; i < m_numChildren; i++)
    {
        hkRefPtr_e3eb<Resource_e3eb> found = m_children[i]->FUN_00e3eb10(apResource);
        if (found.m_pRetainedObject)
            return found;
    }
    return hkRefPtr_e3eb<Resource_e3eb>();
}

struct E5C4Obj
{
};

struct E5C4Ref
{
    E5C4Obj* p;
    E5C4Ref(const E5C4Ref& o)
    {
        if (o.p != 0)
        {
            reinterpret_cast<::FUN_00c90510_class *>((o.p))->FUN_00c90510();
        }
        p = o.p;
    }
};

struct E5C4Key
{
    E5C4Obj* p;
    E5C4Ref* AssignObject(int* tmp);
};

struct E5C4Entry
{
    int key;
    E5C4Ref val;
};

struct E5C4Foo
{
    int unk0;
    E5C4Entry* d;
    E5C4Ref FUN_00e5c4d0(E5C4Key k);
};

// Looks up an entry by key in d; if missing, assigns a new object via k.AssignObject, then returns a copy of the stored E5C4Ref.
// @fnv 0x00e5c4d0
E5C4Ref E5C4Foo::FUN_00e5c4d0(E5C4Key akKey)
{
    int bCreated = 0;
    volatile int tmp[2];
    tmp[0] = 0;
    int i = reinterpret_cast<::FUN_00e5c490_cls *>(this)->FindEntryIndex((uintptr_t)(((volatile E5C4Key&)akKey).p));
    tmp[0] = 0;
    tmp[1] = 0;
    E5C4Ref* slot;
    if (i < 0)
    {
        bCreated = 1;
        slot = akKey.AssignObject((int*)tmp);
    }
    else
    {
        slot = &d[i].val;
    }
    E5C4Ref r(*slot);
    if ((bCreated & 1) != 0 && akKey.p != 0)
    {
        reinterpret_cast<::hkReferencedObjectC905 *>((akKey.p))->FUN_00c905b0();
    }
    return r;
}

volatile intptr_t S00e3eba0_sink;
__declspec(noinline) void FUN_00c90510(void* self)
{
    S00e3eba0_sink = (intptr_t)self;
}
__declspec(noinline) void FUN_00c905b0(void* self)
{
    S00e3eba0_sink = (intptr_t)self + 1;
}
struct S00e3eba0_class
{
    void** m_pVTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_pShape;
    int unk1C;
    int unk20;
    int unk24;
    S00e3eba0_class** m_items;
    int m_uiItemCount;
    void ReplaceObject(hkReferencedObject* oldObject, hkReferencedObject* GetObject);
};
// If m_pShape equals oldObject, replaces it with GetObject; then recursively applies the operation to every item in m_items.
// @fnv 0x00e3eba0
void S00e3eba0_class::ReplaceObject(hkReferencedObject* oldObject, hkReferencedObject* apNewObject)
{
    if (m_pShape == (void*)oldObject)
    {
        _ReadWriteBarrier();
        if (m_pShape != (void*)apNewObject)
        {
            if (apNewObject)
                reinterpret_cast<::FUN_00c90510_class *>((apNewObject))->FUN_00c90510();
            if (m_pShape)
                reinterpret_cast<::hkReferencedObjectC905 *>((m_pShape))->FUN_00c905b0();
            m_pShape = apNewObject;
        }
    }
    for (int i = 0; i < m_uiItemCount; i++)
        m_items[i]->ReplaceObject(oldObject, apNewObject);
}

struct BatchReleaseObjectC907 : FUN_00c903b0_class
{
};
// Calls FUN_00c903b0 for each strided item, acquiring the critical section when multi-threaded mode is enabled and TLS lacks the marker.
// @fnv 0x00c90740
void __cdecl FUN_00c90740(void* items, int count, int stride)
{
    hkReferencedObjectLockC905* guard = (hkReferencedObjectLockC905*)DAT_012681d4;
    if (guard->m_multiThreaded != 0 && TlsGetValue(DAT_012681d8) != (void*)0x23df4554)
    {
        if (TlsGetValue(DAT_012681d8) == (void*)0x23df4554)
            ++guard->m_lLockCount;
        else
        {
            EnterCriticalSection(&guard->m_kCriticalSection);
            guard->m_lLockCount = 1;
            TlsSetValue(DAT_012681d8, (void*)0x23df4554);
        }
        if (count > 0)
        {
            char* item = (char*)items;
            do
            {
                reinterpret_cast<::FUN_00c903b0_class *>(((*((BatchReleaseObjectC907**)item))))->ReleaseReference();
                item += stride;
            } while (--count);
        }
        if (--guard->m_lLockCount <= 0)
        {
            TlsSetValue(DAT_012681d8, 0);
            LeaveCriticalSection(&guard->m_kCriticalSection);
        }
    }
    else
    {
        if (count > 0)
        {
            int remaining = count;
            int step = *(volatile int*)&stride;
            char* item = (char*)items;
            do
            {
                reinterpret_cast<::FUN_00c903b0_class *>(((*((BatchReleaseObjectC907**)item))))->ReleaseReference();
                item += step;
            } while (--remaining);
        }
    }
}

struct ReferenceIncrementC906 : hkReferencedObject
{
    __declspec(noinline) void FUN_00c903a0();
};

void ReferenceIncrementC906::FUN_00c903a0()
{
    if (m_usMemSizeAndFlags)
        ++m_sReferenceCount;
}

// Calls FUN_00c903a0 on each object, acquiring the critical section when multi-threaded mode is enabled and TLS lacks the marker.
// @fnv 0x00c90670
void __cdecl FUN_00c90670(const void* objects, int numObjects, int stride)
{
    hkReferencedObjectLockC905* lock = (hkReferencedObjectLockC905*)DAT_012681d4;
    if (lock->m_multiThreaded && (uintptr_t)TlsGetValue(DAT_012681d8) != 0x23df4554)
    {
        if ((uintptr_t)TlsGetValue(DAT_012681d8) == 0x23df4554)
        {
            lock->m_lLockCount++;
        }
        else
        {
            EnterCriticalSection(&lock->m_kCriticalSection);
            lock->m_lLockCount = 1;
            TlsSetValue(DAT_012681d8, (void*)0x23df4554);
        }
        for (int i = 0; i < numObjects; ++i)
        {
            reinterpret_cast<::FUN_00c903a0_class *>(((*(ReferenceIncrementC906**)objects)))->FUN_00c903a0();
            objects = (const char*)objects + stride;
        }
        --lock->m_lLockCount;
        if (lock->m_lLockCount <= 0)
        {
            TlsSetValue(DAT_012681d8, 0);
            LeaveCriticalSection(&lock->m_kCriticalSection);
        }
    }
    else
    {
        for (int i = 0; i < numObjects; ++i)
        {
            reinterpret_cast<::FUN_00c903a0_class *>(((*(ReferenceIncrementC906**)objects)))->FUN_00c903a0();
            objects = (const char*)objects + stride;
        }
    }
}

// Decrements the lock count and, when it is nonpositive, clears the TLS slot and leaves the critical section.
// @fnv 0x00c904e0
void __cdecl FUN_00c904e0()
{
    hkReferencedObjectLockC905* lock = reinterpret_cast<hkReferencedObjectLockC905*>(DAT_012681d4);
    lock->m_lLockCount = lock->m_lLockCount - 1;
    if (lock->m_lLockCount <= 0)
    {
        TlsSetValue(DAT_012681d8, 0);
        LeaveCriticalSection(&lock->m_kCriticalSection);
    }
}
struct FUN_00c90e60_cls
{
    int unk00;
    float m_fBoundRadius;
    float m_fOriginZ;
    float m_fHalfRadius;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    __m128 m_kRadiusOverHeight;
    __m128 m_kHeightOverRadius;
    float m_fHeightOverRadius;
    float m_fRadiusOverHeight;
    float m_fHeightOverHalfRadius;
    float m_fHalfRadiusOverHeight;
    void FUN_00c90e60(float fRadius, float m_fGlyphExtent);
};
// @fnv 0x00c90e60
void FUN_00c90e60_cls::FUN_00c90e60(float fRadius, float m_fGlyphExtent)
{
    m_fBoundRadius = fRadius;
    float fHalfRadius = fRadius * 0.5;
    m_fHalfRadius = fHalfRadius;
    m_fOriginZ = m_fGlyphExtent;
    m_fHeightOverRadius = m_fGlyphExtent / fRadius;
    m_fHeightOverHalfRadius = m_fGlyphExtent / fHalfRadius;
    m_fRadiusOverHeight = fRadius / m_fGlyphExtent;
    m_fHalfRadiusOverHeight = fHalfRadius / m_fGlyphExtent;
    m_kRadiusOverHeight = _mm_set1_ps(m_fRadiusOverHeight);
    m_kHeightOverRadius = _mm_set1_ps(m_fHeightOverRadius);
}

#include "generated/data/havok/common/base/object/hkreferencedobject.inc"
