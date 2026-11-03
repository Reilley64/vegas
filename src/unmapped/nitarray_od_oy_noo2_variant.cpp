
// src/unmapped/nitarray_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/unmapped/nitarray.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <windows.h>
#include "fnv/decl/C89AC0_Owner.h"
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_009a4ef0_Class.h"
#include "fnv/decl/FUN_00a413d0_cls.h"
#include "fnv/decl/MaterialUploadState.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/Obj_00c89b60.h"
#include "fnv/decl/Owner_9bf0.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/symbols_004b0000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b7c000.h"
#include "fnv/symbols_011f6000.h"
struct NiD3DShaderFactory
{
    void UpdateShaderMaterialCache(void*);
};
struct NiD3DRenderState
{
    void FUN_00e87980(void*);
};
struct FUN_009ba5f0_shell
{
};
struct FUN_00c89c80_obj
{
    void CopyFromSource(unsigned int uiMaxSize);
};
struct MemoryManager
{
    void* Allocate(unsigned int auiSize) throw();
};
struct KeyPair
{
    void* m_pFirst;
    void* m_pSecond;

    static void* operator new(unsigned int auiSize) throw()
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(auiSize);
    }

    KeyPair(void* apFirst, void* apSecond) throw() : m_pFirst(apFirst), m_pSecond(apSecond)
    {}
};
struct FUN_00a41520_cls
{
    int unk00;
    int unk04;
    unsigned short m_uCapacity;
    unsigned short m_uCount;
    unsigned short m_u0c;
    unsigned short m_uGrowStep;

    void FUN_00a90180(unsigned int auiNewSize);
    void FUN_00ba3aa0(unsigned int auiIndex, KeyPair** appEntry);

    bool FUN_00a41520(void* apFirst, void* apSecond);
};
struct MM
{
};
class NiNode;
template <class T> struct NiPointer
{
    T* ptr;
    ~NiPointer();
    static void __cdecl operator delete[](void* memory)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(memory);
    }
};
struct S_Interface
{
    static KeyPair** Allocate(unsigned int auiCount)
    {
        return (KeyPair**)FUN_00aa1070(sizeof(KeyPair*) * auiCount);
    }
};
struct C89CD0Target
{
};
struct C89CD0Holder
{
    int unk00;
    int unk04;
    C89CD0Target* m_pkTarget;

    void ProcessTarget(void* arg);
};
struct Target
{
};
struct FUN_00c89cf0_cls
{
    int unk00;
    int unk04;
    Target* m_pFlagTarget;

    void DispatchToTarget(void* apArg);
};

struct RefHolder
{
    void* m_pObject;
    RefHolder(const RefHolder& apOther);
    ~RefHolder();
    operator void*() const;
};

struct RefList
{
    RefHolder& GetAt(unsigned int auiIndex);
    unsigned int Add(const RefHolder& apRef);
};

// @fnv 0x00869420
void __cdecl FUN_00869420(RefList* apSource, RefList* apTarget)
{
    for (unsigned int i = 0; i < reinterpret_cast<::FUN_00658930_class *>((void *)(apSource))->GetShortAtOffsetA(); i = i + 1)
    {
        RefHolder spRef(apSource->GetAt(i));
        if (spRef)
        {
            apTarget->Add(spRef);
        }
    }
}


class NiRefObjectA47
{
  public:
    virtual ~NiRefObjectA47();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }

    long m_uiRefCount;
};

template <class T> class NiPointerA47
{
  public:
    NiPointerA47(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerA47()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerA47& operator=(const NiPointerA47& ptr)
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiPointerA47& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator!=(const NiPointerA47& ptr) const
    {
        return m_pObject != ptr.m_pObject;
    }

    T* m_pObject;
};

typedef NiPointerA47<NiRefObjectA47> NiObjectPtrA47;


class NiTObjectArrayA47
{
  public:
    virtual ~NiTObjectArrayA47();

    NiObjectPtrA47* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_0060bef0(unsigned int uiMaxSize);
};

// @fnv 0x0060bef0
void NiTObjectArrayA47::FUN_0060bef0(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (reinterpret_cast<::DummyStruct_00631820 *>((void *)&(const ::NiPointerA47< ::NiRefObjectA47> &)(m_pBase[i]))->IsNotEqual((const ::DummyStruct_00631820 &)((const ::NiPointerA47< ::NiRefObjectA47> &)(NiObjectPtrA47(0)))))
            {
                m_pBase[i] = NiObjectPtrA47(0);
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    NiObjectPtrA47* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = ((::NiPointerA47< ::NiRefObjectA47> *)(::FUN_005e0ba0(m_usMaxSize)));
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = NiObjectPtrA47(0);
    }
    else
    {
        m_pBase = 0;
    }
    ::FUN_004b0220((int)(pSaveBase));
}

namespace fnv_009a5a70 {
struct ItemList
{
};
struct SpawnedObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    SpawnedObject();
    ~SpawnedObject();
};
struct FUN_009a5a70_cls
{
    void FUN_009a5a70(ItemList* list);
};
// @fnv 0x009a5a70
void FUN_009a5a70_cls::FUN_009a5a70(ItemList* list)
{
    unsigned int count = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((list))->FUN_00864a60()));
    for (unsigned int index = 0; index < count; ++index)
    {
        bool failed = false;
        SpawnedObject* object = new SpawnedObject;
        void* output;
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((list))->FUN_008648e0((unsigned int *)(void **)(&output));
        reinterpret_cast<::FUN_00537e90 *>((object))->SetQuantity((unsigned int)(output));
        reinterpret_cast<::FUN_009a4ef0_Class *>((object))->FUN_009a4ef0((::BGSLoadFormBuffer *)(list));
        if (output == 0)
            failed = true;
        if (!failed)
            reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700((unsigned int)(output), (unsigned int)(object));
        else
            delete object;
    }
}
}  // namespace fnv_009a5a70
