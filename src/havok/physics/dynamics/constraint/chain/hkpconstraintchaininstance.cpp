
// src/havok/physics/dynamics/constraint/chain/hkpconstraintchaininstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/hkpconstraintchaininstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00c91140_Class.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpWorldDecomp.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb3000.h"
#include "havok/hkpConstraintChainInstance.h"
#include "havok/hkpEntity.h"
#include "havok/hkpWorld.h"

struct FUN_00c91120
{
    void ExecutePendingOperations();
};
struct FUN_00c91140
{
};
struct FUN_00c97510
{
};
struct FUN_00cb3da0
{
};
struct FUN_00dd0460 : hkpConstraintChainInstance
{
    void EntityRemovedCallback(void*);
};
// @fnv 0x00dd0460
void FUN_00dd0460::EntityRemovedCallback(void* a)
{
    hkpWorld* w = static_cast<hkpWorld*>(static_cast<hkpEntity*>(a)->m_pOwningWorld);
    ++w->m_iCriticalOperationsLockCount;
    reinterpret_cast<::hkpWorldDecomp *>((w))->FUN_00c97510((::hkpAction *)(m_pAction));
    ::FUN_00cb3da0((::S_00cb3da0_Ctx *)(w), this);
    if (--w->m_iCriticalOperationsLockCount == 0 && !w->m_bBlockExecutingPendingOperations)
    {
        if (w->m_iPendingOperationCount)
            ((FUN_00c91120*)w)->ExecutePendingOperations();
        if (w->m_iPendingOperationQueueCount == 1 && w->m_iQueuedOperationCount)
            reinterpret_cast<::FUN_00c91140_Class *>((((FUN_00c91140*)w)))->FUN_00c91140();
    }
}

class hkMemoryAllocatorDD04;

struct hkMemoryRouterDD04
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDD04* m_pStreamAllocator;
    hkMemoryAllocatorDD04& heap()
    {
        return *m_pStreamAllocator;
    }
};



template <class T> __forceinline void constructWithCopyDD04(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayDD04
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorDD04& kAlloc = (*static_cast<hkMemoryRouterDD04*>(::FUN_00c85750())).heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyDD04(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkReferencedObjectDD04
{
  public:
};

class hkpPhantomOverlapDD04
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkReferencedObjectDD04* m_pHeadNode[2];
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    hkArrayDD04<hkReferencedObjectDD04*> m_kTrackedObjects;

    void AddReferencedObject(hkReferencedObjectDD04* pkObject);
};

// @fnv 0x00dd04d0
void hkpPhantomOverlapDD04::AddReferencedObject(hkReferencedObjectDD04* pkObject)
{
    int iSlot = m_kTrackedObjects.m_iElementCount;
    if (iSlot < 2 && m_pHeadNode[iSlot] == 0)
    {
        m_pHeadNode[iSlot] = pkObject;
        reinterpret_cast<::FUN_00c90510_class *>((pkObject))->FUN_00c90510();
    }
    m_kTrackedObjects.AddBack(pkObject);
    reinterpret_cast<::FUN_00c90510_class *>((pkObject))->FUN_00c90510();
}

class hkMemoryAllocatorDD05
{
  public:
    virtual ~hkMemoryAllocatorDD05() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDD05
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDD05* m_pStreamAllocator;
    hkMemoryAllocatorDD05& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDD05 {

}

template <class T> class hkArrayDD05
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayDD05() throw()
    {
        hkMemoryAllocatorDD05& kAlloc = (*static_cast<hkMemoryRouterDD05*>(::FUN_00c85750())).heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00d1df70 : public hkReferencedObject
{
  public:
};

class FUN_00cf40b0
{
  public:
    virtual ~FUN_00cf40b0() throw();
    int unk04[13];
};

class FUN_00dd05c0 : public FUN_00cf40b0
{
  public:
    hkArrayDD05<FUN_00d1df70*> m_children;
    FUN_00d1df70* m_pOwnerObject;

    virtual ~FUN_00dd05c0() throw();
};

// @fnv 0x00dd05c0
FUN_00dd05c0::~FUN_00dd05c0() throw()
{
    for (int i = 0; i < m_children.m_iElementCount; i++)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_children.m_data[i]))->FUN_00c905b0();
    reinterpret_cast<::hkReferencedObjectC905 *>((m_pOwnerObject))->FUN_00c905b0();
}

namespace fnv_00dd0630 {
struct FnvCpu_FUN_00dd0630_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00dd0630_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00dd0630_CpuAllocator* allocator;
};

struct FnvCpu_FUN_00dd0630_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00dd05c0();
    FnvCpu_FUN_00dd0630_CpuObject* Destroy(unsigned int flags);
};
// Calls FUN_00dd05c0, and if flags has bit 0 set, frees this via the allocator from FUN_00c85750, then returns this.
// @fnv 0x00dd0630
FnvCpu_FUN_00dd0630_CpuObject* FnvCpu_FUN_00dd0630_CpuObject::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00dd05c0 *>(this)->FUN_00dd05c0::~FUN_00dd05c0();
    if (flags & 1)
    {
        FnvCpu_FUN_00dd0630_CpuAllocatorHolder* holder = static_cast<FnvCpu_FUN_00dd0630_CpuAllocatorHolder*>(::FUN_00c85750());
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00dd0630

namespace fnv_00dd0530 {
class hkMemoryAllocatorDD05
{
  public:
    virtual ~hkMemoryAllocatorDD05() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDD05
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorDD05* m_pStreamAllocator;

    hkMemoryAllocatorDD05& heap()
    {
        return *m_pStreamAllocator;
    }
};



namespace hkDD05 {
class hkRefObj
{
  public:
    hkRefObj() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual void unkVirtual00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(size_t nbytes)
    {
        hkRefObj* b = static_cast<hkRefObj*>((*static_cast<hkMemoryRouterDD05*>(::FUN_00c85750())).heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
};

class hkpConstraintChainData : public hkRefObj
{
  public:
};
}

namespace FUN_00cb0a60 {
class hkStringPtr
{
  public:
    hkStringPtr() throw();
    const char* m_pcText;
};
}

namespace FUN_00cf3f40 {
class hkpConstraintInstance : public hkDD05::hkRefObj
{
  public:
    hkpConstraintInstance(int iPriority) throw();
    int unk08;
    hkDD05::hkpConstraintChainData* m_data;
    int unk10;
    void* m_kActorEntries[2];
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;
};
}

class hkpAction : public hkDD05::hkRefObj
{
  public:
    hkpAction() throw() : m_pOwningWorld(0), m_pCurrentSimulationIsland(0), m_ulUserData(0)
    {}
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned long m_ulUserData;
    FUN_00cb0a60::hkStringPtr m_name;
};

class hkpConstraintChainInstanceAction : public hkpAction
{
  public:
    hkpConstraintChainInstanceAction(FUN_00cf3f40::hkpConstraintInstance* pkInstance) throw()
        : m_pConstraintChainInstance(pkInstance)
    {}
    virtual void unkVirtual00();
    FUN_00cf3f40::hkpConstraintInstance* m_pConstraintChainInstance;
};

template <class T> class hkArrayDD05
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayDD05() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

namespace FUN_00dd0530 {
class hkpConstraintChainInstance : public FUN_00cf3f40::hkpConstraintInstance
{
  public:
    hkpConstraintChainInstance(hkDD05::hkpConstraintChainData* pkData);
    virtual void unkVirtual00();

    hkArrayDD05<void*> m_ppRigidBodies;
    hkpConstraintChainInstanceAction* m_pAction;
};

// Constructs a constraint chain instance from pkData, nulls actor entries, and creates its owning hkpConstraintChainInstanceAction.
// @fnv 0x00dd0530
hkpConstraintChainInstance::hkpConstraintChainInstance(hkDD05::hkpConstraintChainData* pkData)
    : FUN_00cf3f40::hkpConstraintInstance(1)
{
    m_data = pkData;
    reinterpret_cast<::FUN_00c90510_class *>((pkData))->FUN_00c90510();
    m_kActorEntries[0] = 0;
    m_kActorEntries[1] = 0;
    m_pAction = new hkpConstraintChainInstanceAction(this);
}
}
}  // namespace fnv_00dd0530
