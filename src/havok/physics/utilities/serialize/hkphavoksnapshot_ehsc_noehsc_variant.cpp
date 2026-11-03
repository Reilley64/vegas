
// src/havok/physics/utilities/serialize/hkphavoksnapshot_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/serialize/hkphavoksnapshot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/serialize/hkphavoksnapshot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_00d46d40_s.h"
#include "fnv/decl/FUN_00d47770.h"
#include "fnv/decl/FUN_00d49750.h"
#include "fnv/decl/FUN_00d4bab0.h"
#include "fnv/decl/FUN_00d4c220_s.h"
#include "fnv/decl/FnvClassNameNode.h"
#include "fnv/decl/HostType.h"
#include "fnv/decl/ReferencedObjectHolder.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/decl/fnv_00cc0ae0__FUN_00cc0ae0_cls.h"
#include "fnv/decl/fnv_00d4aa70__FUN_00d4aa70.h"
#include "fnv/decl/fnv_00d4c250__FUN_00d4c250.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cc0000.h"
#include "fnv/symbols_01268000.h"
struct CallbackInterface
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void notify(void*, unsigned short);
};
struct State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    CallbackInterface* interface10;
};
State* __cdecl FUN_00c85750();
struct Object
{
    void* unk00;
    unsigned short unk04;
    Object* FUN_00cc0dd0(unsigned int flags);
};
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
    void set(D481D0ReferencedObject* obj, const D481D0Class* pClassInfo);
};
struct FUN_00d481d0
{
    D481D0StringPtr m_name;
    D481D0StringPtr m_pClassName;
    D481D0RefVariant m_pReferencedResource;

    FUN_00d481d0(const char* name, D481D0ReferencedObject* object, const D481D0Class* pClassInfo);
};
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
struct Allocator
{
    virtual void* unk0();
    virtual void* allocate(unsigned int size);
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

struct hkMemoryAllocator
{
    virtual void reserved0();
    virtual void FunctionAtSlot4();
    virtual void VirtualFunction8();
    virtual void reservedC();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct hkMemoryRouterS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
inline hkMemoryRouterS* getRouter()
{
    return (hkMemoryRouterS*)FUN_00c85750();
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
        reinterpret_cast<::FUN_00d47770 *>(&(m_pReferencedResource))->SetObject((::hkReferencedObject *)(object), (int)(pClassInfo));
        reinterpret_cast<::SStringPtr *>((void *)&(const ::hkStringPtr &)(m_pClassName))->FUN_00cb0c10(((const ::hkClassS *)(reinterpret_cast<::ReferencedObjectHolder *>((void *)&(m_pReferencedResource))->FUN_00d477a0())) ? reinterpret_cast<::FnvClassNameNode *>((void *)(((const ::hkClassS *)(reinterpret_cast<::ReferencedObjectHolder *>((void *)&(m_pReferencedResource))->FUN_00d477a0()))))->FUN_00d46d40() : 0);
    }
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}

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
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(NamedVariantS));
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
