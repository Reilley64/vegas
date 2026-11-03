
// src/havok/physics/dynamics/entity/hkpentity.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/hkpentity.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include <new>
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include "fnv/decl/FNVWorldObject.h"
#include "fnv/decl/FUN_00d01ae0_shell.h"
#include "fnv/decl/FUN_00d1dff0.h"
#include "fnv/decl/FlagState.h"
#include "fnv/decl/WorldWithPending.h"
#include "fnv/decl/hkMapD01A.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00c9c000.h"
#include "fnv/symbols_00c9d000.h"
#include "fnv/symbols_00cb5000.h"
#include "fnv/symbols_00cb6000.h"
#include "fnv/symbols_00cf6000.h"
#include "fnv/symbols_00cff000.h"
#include "fnv/symbols_00d06000.h"
#include "fnv/symbols_00d1a000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010c5000.h"
#include "fnv/symbols_010c6000.h"
#include "fnv/symbols_01268000.h"
#include "havok/hkpEntity.h"
#include "havok/hkpWorld.h"
#include "havok/hkpConstraintInstance.h"

// @fnv 0x00c9c380
int FUN_00c9c380(void* self, int)
{
    const hkpEntity* entity = static_cast<const hkpEntity*>(self);
    return entity->m_kSlaveConstraints.m_iElementCount + entity->m_eSmallArraySerializeOverrideType.m_iElementCount;
}

// The first fields of Havok's hkConstraintInternal (0x30 bytes in the 32-bit build).
struct hkConstraintInternalC9C
{
    hkpConstraintInstance* m_constraint;
    hkpEntity* m_entities[2];
    void* m_atoms;
    unsigned char m_pad10[0x12];
    unsigned short m_slaveIndex;
    unsigned char m_pad24[0xc];
};

struct FUN_00c9c3c0_Class : hkpEntity
{
    hkpConstraintInstance* GetEntryAt(int index);
};

// Returns the constraint at index from the master constraints if index is below their count, otherwise from the slave constraints.
// @fnv 0x00c9c3c0
hkpConstraintInstance* FUN_00c9c3c0_Class::GetEntryAt(int index)
{
    if (index < m_eSmallArraySerializeOverrideType.m_iElementCount)
        return static_cast<hkConstraintInternalC9C*>(m_eSmallArraySerializeOverrideType.m_data)[index].m_constraint;
    return m_kSlaveConstraints.m_data[index - m_eSmallArraySerializeOverrideType.m_iElementCount];
}

struct FUN_00c9c1a0_Value
{
    int m_00;
    int m_04;
    int m_08;
};

struct FUN_00c9c1a0_Item
{
    FUN_00c9c1a0_Value* m_00;
    int m_04;
};

struct FUN_00c9c1a0_Class
{
    char m_auiShapeKeys[0x60];
    FUN_00c9c1a0_Item* m_60;
    int m_64;

    int FindValueByKey(int value);
};

// Scans the m_60 item array for an entry whose m_04 equals value + 0x10 and returns that entry's m_00->m_08, or 0 if none matches.
// @fnv 0x00c9c1a0
int FUN_00c9c1a0_Class::FindValueByKey(int value)
{
    int index = 0;
    if (m_64 > 0)
    {
        int key = value + 0x10;
        FUN_00c9c1a0_Item* item = m_60;
        do
        {
            if (item->m_04 == key)
                return item->m_00->m_08;
            ++index;
            ++item;
        } while (index < m_64);
    }
    return 0;
}




struct FUN_00c9d490_Class
{
    void* m_00;
    unsigned short m_04;

    void FUN_00c9cf60();
    void* FUN_00c9d490(int flags);
};

// @fnv 0x00c9d490
void* FUN_00c9d490_Class::FUN_00c9d490(int flags)
{
    FUN_00c9cf60();

    if (flags & 1)
    {
        hkMemoryRouter::getInstance().heap().blockFree(this, m_04);
    }

    return this;
}

// @fnv 0x00c9c020
void* FUN_00c9c020(hkpEntity* entity)
{
    return &entity->m_eSmallArraySerializeOverrideType;
}

struct CpuObject
{
    char* FUN_00c9c030();
};
// @fnv 0x00c9c030
char* CpuObject::FUN_00c9c030()
{
    return reinterpret_cast<char*>(&reinterpret_cast<hkpEntity*>(this)->m_eSmallArraySerializeOverrideType);
}

namespace fnv_00c9c3f0 {
struct CpuObject
{
    char* FUN_00c9c3f0();
};
// @fnv 0x00c9c3f0
char* CpuObject::FUN_00c9c3f0()
{
    return reinterpret_cast<char*>(&reinterpret_cast<hkpEntity*>(this)->m_kSlaveConstraints);
}
}  // namespace fnv_00c9c3f0


struct FUN_00c9bfa0_Class : hkpEntity
{
    void FUN_00c9bfa0();
};


// If the entity is in a world and has a shape, calls FUN_00d1a330 with the world's collision input, a pointer to this, and 1.
// @fnv 0x00c9bfa0
void FUN_00c9bfa0_Class::FUN_00c9bfa0()
{
    if (m_pOwningWorld && m_kCollidable.m_pCollisionShape)
    {
        hkpEntity* self = this;
        ::FUN_00d1a330((const ::CollisionContext *)(static_cast<hkpWorld*>(m_pOwningWorld)->m_pCollisionInput), (::EntityNode *const *)&self, 1);
    }
}

struct hkWorldOperationBaseC9C3
{
    unsigned char m_type;
};

class hkpEntityC9C3;

struct hkWorldOperationC9C3 : public hkWorldOperationBaseC9C3
{
    hkpEntityC9C3* m_pEntity;

    hkWorldOperationC9C3()
    {
        m_type = 0x21;
    }
};

class hkpWorldC9C3
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int m_iCriticalOperationsLockCount;

    bool areCriticalOperationsLocked() const
    {
        return m_iCriticalOperationsLockCount != 0;
    }
};

class hkpEntityC9C3
{
  public:
    int unk00;
    int unk04;
    hkpWorldC9C3* m_pOwningWorld;

    void FUN_00c9c300();
};

struct WorldOp
{
    unsigned char m_type;
    void* m_pEntity;
};

struct World_Class : public hkpWorld
{
};

struct FUN_00c9c240_holder : public hkpEntity
{
    void FUN_00c9c240();
    void FUN_00c9c340();
};

// @fnv 0x00c9c340
void FUN_00c9c240_holder::FUN_00c9c340()
{
    World_Class* world = (World_Class*)m_pOwningWorld;
    if (world && world->m_iCriticalOperationsLockCount)
    {
        WorldOp op;
        op.m_pEntity = this;
        op.m_type = 0x22;
        reinterpret_cast<::WorldWithPending *>((world))->FUN_00c91160();
        return;
    }
    FUN_00c9c240();
}

struct FUN_00c9c390_Class : hkpEntity
{
    hkpConstraintInstance* GetEntry(int index);
};
// Returns the constraint at index from the master constraints if index is below their count, otherwise from the slave constraints.
// @fnv 0x00c9c390
hkpConstraintInstance* FUN_00c9c390_Class::GetEntry(int index)
{
    if (index < m_eSmallArraySerializeOverrideType.m_iElementCount)
        return static_cast<hkConstraintInternalC9C*>(m_eSmallArraySerializeOverrideType.m_data)[index].m_constraint;
    return m_kSlaveConstraints.m_data[index - m_eSmallArraySerializeOverrideType.m_iElementCount];
}

class GlobalObjectO2_00d472a0;

class hkStatisticsCollector
{
  public:
    virtual ~hkStatisticsCollector();
    virtual void beginObject(const char* name, const hkClass* cls, const void* obj);
    virtual void endObject();
    virtual void addChildObject(const char* name, const void* obj, int flags);
    virtual void AddObjectInstance(const char* name, const void* obj);
    virtual void AddMemoryChunk(int type, const char* name, const void* chunk, int usedSize, int allocatedSize);
    int unk04;
    int unk08;
    int unk0c;
    bool m_clearDontDeallocate;
};

class hkpEntityExtendedListeners
{
  public:
    hkpEntitySmallArraySerializeOverrideType m_kContactListenerArray;
    hkpEntitySmallArraySerializeOverrideType m_kEntityListenerArray;
};


class hkpEntityStats : public hkpEntity
{
  public:
    void CollectStats(hkStatisticsCollector* collector, const hkClass* cls) const;
};

// Reports the entity's constraint, collision, listener and motion data to the statistics collector, skipping flagged arrays unless m_clearDontDeallocate is set.
// @fnv 0x00c9c400
void hkpEntityStats::CollectStats(hkStatisticsCollector* collector, const hkClass* cls) const
{
    collector->AddMemoryChunk(3, "constraintsSlave", m_kSlaveConstraints.m_data, m_kSlaveConstraints.m_iElementCount * 4,
                              (m_kSlaveConstraints.m_iCapacityState & 0x3fffffff) * 4);
    ::WriteReflectedMembers((void *)(this), (::Meta64 *)(&g_012688c8), (::Writer64 *)(collector));
    if ((m_kContactListeners.m_iCapacityState & 0x8000) == 0 || collector->m_clearDontDeallocate)
    {
        collector->AddMemoryChunk(3, "CollisionListnr", m_kContactListeners.m_data, m_kContactListeners.m_iElementCount * 4,
                                  (m_kContactListeners.m_iCapacityState & 0x3fff) * 4);
    }
    if (m_pExtendedListeners)
    {
        const hkpEntitySmallArraySerializeOverrideType& entityListeners = m_pExtendedListeners->m_kEntityListenerArray;
        if ((entityListeners.m_iCapacityState & 0x8000) == 0 || collector->m_clearDontDeallocate)
        {
            collector->AddMemoryChunk(3, "EntityListeners", entityListeners.m_data, entityListeners.m_iElementCount * 4,
                                      (entityListeners.m_iCapacityState & 0x3fff) * 4);
        }
        const hkpEntitySmallArraySerializeOverrideType& activationListeners =
            m_pExtendedListeners->m_kContactListenerArray;
        if ((activationListeners.m_iCapacityState & 0x8000) == 0 || collector->m_clearDontDeallocate)
        {
            collector->AddMemoryChunk(3, "ActivatonListners", activationListeners.m_data,
                                      activationListeners.m_iElementCount * 4,
                                      (activationListeners.m_iCapacityState & 0x3fff) * 4);
        }
    }
    collector->addChildObject("SavedMotion", m_pMotionState.m_pSavedMotion, 0);
    reinterpret_cast<::FNVWorldObject *>((void *)this)->WriteToStream((::hkStreamWriter *)(collector), &g_01268808);
}


template <typename T> class hkSmallArrayC9C5
{
  public:
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    unsigned short getCapacity() const
    {
        return (unsigned short)(m_iCapacityState & 0x3fff);
    }
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void AddBack(const T& t)
    {
        if (m_iElementCount == getCapacity())
            ::FUN_00d06cb0((::GrowBuf *)(void *)(this), sizeof(T));
        m_data[m_iElementCount++] = t;
    }
};

class hkOwnerC9C5
{
  public:
    int unk000[0x80];
    hkSmallArrayC9C5<void*> m_slots;

    void AddSlot(void* p);
};

// Finds the first null entry in m_slots and replaces it with p, or appends p if no null entry exists.
// @fnv 0x00c9c540
void hkOwnerC9C5::AddSlot(void* apSlot)
{
    int i = m_slots.indexOf(0);
    if (i >= 0)
        m_slots.m_data[i] = apSlot;
    else
        m_slots.AddBack(apSlot);
}

struct hkpLinkedCollidableD250 : hkpEntity
{
};

struct hkpAgentEntryD250 : hkpConstraintInstance
{
};

struct hkEntryLessD250
{
    const hkpEntity* m_key;

    const hkpLinkedCollidableD250* getPartner(const hkpAgentEntryD250* pkEntry) const
    {
        return reinterpret_cast<const hkpLinkedCollidableD250*>(reinterpret_cast<uintptr_t>(pkEntry->m_kActorEntries[1]) ^
                                                                reinterpret_cast<uintptr_t>(pkEntry->m_kActorEntries[0]) ^
                                                                reinterpret_cast<uintptr_t>(m_key));
    }

    bool operator()(const hkpAgentEntryD250* pkA, const hkpAgentEntryD250* pkB) const
    {
        if (pkA->m_uiUniqueId < pkB->m_uiUniqueId)
        {
            return true;
        }
        if (pkA->m_uiUniqueId > pkB->m_uiUniqueId)
        {
            return false;
        }
        return getPartner(pkA)->m_uiUniqueId < getPartner(pkB)->m_uiUniqueId;
    }
};

struct FUN_00c9c860_Shell : hkpEntity
{
    void UpdateNodeSlotIndices();
};
// @fnv 0x00c9c860
void FUN_00c9c860_Shell::UpdateNodeSlotIndices()
{
    if (m_pMotionState.m_type != 5)
    {
        return;
    }
    if (m_kSlaveConstraints.m_iElementCount > 1)
    {
        ::FUN_00c9d250(reinterpret_cast<::hkpAgentEntryD250 **>(m_kSlaveConstraints.m_data), 0, m_kSlaveConstraints.m_iElementCount - 1,
                       ::hkEntryLessD250{this});
    }
    for (int i = 0; i < m_kSlaveConstraints.m_iElementCount; ++i)
    {
        hkpConstraintInstance* node = m_kSlaveConstraints.m_data[i];
        FUN_00c9c860_Shell* owner = reinterpret_cast<FUN_00c9c860_Shell*>(reinterpret_cast<uintptr_t>(node->m_kActorEntries[1]) ^
                                                                          reinterpret_cast<uintptr_t>(node->m_kActorEntries[0]) ^
                                                                          reinterpret_cast<uintptr_t>(this));
        hkConstraintInternalC9C* internals = static_cast<hkConstraintInternalC9C*>(owner->m_eSmallArraySerializeOverrideType.m_data);
        for (int k = 0; k < owner->m_eSmallArraySerializeOverrideType.m_iElementCount; ++k)
        {
            if (internals[k].m_constraint == node)
            {
                internals[k].m_slaveIndex = (unsigned short)i;
                break;
            }
        }
    }
}

class hkpShape;
class hkLocalFrame;
class hkpConstraintInstance;
class hkpEntityExtendedListeners;

extern const int DAT_010c6f7c;

struct hkpMaterialC9CC : public hkpMaterial
{
    hkpMaterialC9CC()
    {
        m_fSlipAngle = 0.5f;
        m_fElasticity = 0.4f;
    }
};

struct hkSmallArrayC9CC : public hkpEntitySmallArraySerializeOverrideType
{
    hkSmallArrayC9CC()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x8000;
    }
};

template <class T> struct hkArrayC9CC : public hkArray<T>
{
    hkArrayC9CC()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
    }
};

struct hkpSpuCollisionCallbackC9CC : public hkpEntitySpuCollisionCallback
{
    hkpSpuCollisionCallbackC9CC()
    {
        m_pCallbackData = 0;
        m_pRayCursor = 0;
        m_uiCallbackType = hkpEntity::SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS;
        m_bCallbackEnabled = 1;
    }
};

class __declspec(novtable) hkpMaxSizeMotionC9CC : public hkpMaxSizeMotion
{
  public:
    hkpMaxSizeMotionC9CC()
    {
        m_pSavedMotion = 0;
        *(const int**)this = &::g_unk010c6c64;
    }
};

template <class T> struct hkRefPtrC9CC
{
    T* m_pRetainedObject;
    hkRefPtrC9CC() : m_pRetainedObject(0)
    {}
};

class FUN_00cd2ce0 : public hkpWorldObject
{
  public:
    FUN_00cd2ce0(const hkpShape* pkShape, int iType) throw();
};

class __declspec(novtable) hkpEntityBaseC9CC : public FUN_00cd2ce0
{
  public:
    hkpEntityBaseC9CC(const hkpShape* pkShape) throw() : FUN_00cd2ce0(pkShape, hkpWorldObject::BROAD_PHASE_ENTITY)
    {
        *(const int**)this = &DAT_010c6f7c;
    }
};

class __declspec(novtable) FUN_00c9cce0 : public hkpEntityBaseC9CC
{
  public:
    hkpMaterialC9CC m_iMaterialIndex;
    void* m_pEntityUserData;
    hkReal m_fBulletSpread;
    void* m_pShape;
    hkUint32 m_uiFilterInfo;
    hkUint16 m_usStorageIndex;
    hkUint16 m_usNextProcessCallbackDelay;
    hkSmallArrayC9CC m_eSmallArraySerializeOverrideType;
    hkArrayC9CC<hkpConstraintInstance*> m_kSlaveConstraints;
    hkArrayC9CC<hkUint8> m_pByteBuffer;
    void* m_pSimulationIsland;
    hkInt8 m_iAutoRemoveLevel;
    hkUint8 m_ucNumShapeKeysInContactPointProperties;
    hkUint8 m_ucResponseModifierFlags;
    hkUint32 m_uiUniqueId;
    hkpSpuCollisionCallbackC9CC m_kSpuCollisionCallback;
    hkpMaxSizeMotionC9CC m_pMotionState;
    hkSmallArrayC9CC m_kContactListeners;
    hkSmallArrayC9CC m_ppActions;
    hkRefPtrC9CC<hkLocalFrame> m_pLocalFrame;
    hkpEntityExtendedListeners* m_pExtendedListeners;

    FUN_00c9cce0(const hkpShape* pkShape) throw();
};

// Constructs an hkpEntity from a shape, initialising its material, motion, arrays and listener pointers to defaults.
// @fnv 0x00c9cce0
FUN_00c9cce0::FUN_00c9cce0(const hkpShape* pkShape) throw() : hkpEntityBaseC9CC(pkShape)
{
    m_usStorageIndex = 0xffff;
    m_fBulletSpread = 1.0f;
    m_pSimulationIsland = 0;
    m_pExtendedListeners = 0;
    m_pEntityUserData = 0;
    m_uiFilterInfo = 0;
    m_ucNumShapeKeysInContactPointProperties = 0;
    m_pShape = 0;
    m_uiUniqueId = 0xffffffff;
}

extern int DAT_010c6bec;

struct MotionStateObject
{
    void* volatile m_ppVirtualMethodTable;
    MotionStateObject* FUN_00c9d100(int enabled);
};

// @fnv 0x00c9d100
MotionStateObject* MotionStateObject::FUN_00c9d100(int enabled)
{
    m_ppVirtualMethodTable = &DAT_010c59f4;
    if (enabled != 0)
    {
        *reinterpret_cast<volatile float*>(&enabled) = 1.0f;
        reinterpret_cast<hkpMotion*>(this)->m_fGravityFactor =
            static_cast<hkHalf>(enabled >> 16);
    }
    m_ppVirtualMethodTable = &DAT_010c6bec;
    return this;
}


struct FnvCpu_FUN_00c9d160_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00d1dff0();
    FnvCpu_FUN_00c9d160_CpuObject* FUN_00c9d160(unsigned int flags);
};
// @fnv 0x00c9d160
FnvCpu_FUN_00c9d160_CpuObject* FnvCpu_FUN_00c9d160_CpuObject::FUN_00c9d160(unsigned int flags)
{
    reinterpret_cast<::FUN_00d1dff0 *>(this)->setMotion();
    if (flags & 1)
    {
        hkMemoryRouter::getInstance().heap().blockFree(this, size);
    }
    return this;
}

struct FUN_00c9d190
{
    void* volatile m_vtbl;
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
    short unk118;
    short unk11a;
    short unk11c;
    short unk11e;
    FUN_00c9d190(int flag);
};
// Sets the vtable pointer to DAT_010c59f4, optionally writes the high half of 1.0f to unk11e, then sets the vtable to DAT_010c6d54.
// @fnv 0x00c9d190
FUN_00c9d190::FUN_00c9d190(int flag)
{
    m_vtbl = &DAT_010c59f4;
    if (flag)
    {
        float one = 1.0f;
        unk11e = (short)(*(int*)&one >> 16);
    }
    m_vtbl = &(*reinterpret_cast<int *>(&::DAT_010c6d54));
}

class MotionGravityBase : public hkpKeyframedRigidMotion
{
  public:
    explicit MotionGravityBase(int initialize)
    {
        if (initialize)
        {
            float gravityFactor = 1.0f;
            volatile short& storedGravityFactor = m_fGravityFactor;
            storedGravityFactor = static_cast<short>(*reinterpret_cast<int*>(&gravityFactor) >> 16);
        }
    }
};
class KeyframedMotionReset : public MotionGravityBase
{
  public:
    explicit KeyframedMotionReset(int initialize) : MotionGravityBase(initialize)
    {}
    KeyframedMotionReset* FUN_00c9d1c0(int initialize);
};
// Placement-constructs a KeyframedMotionReset at this address with the given initialize flag and returns this.
// @fnv 0x00c9d1c0
KeyframedMotionReset* KeyframedMotionReset::FUN_00c9d1c0(int initialize)
{
    __assume(this != 0);
    new (this) KeyframedMotionReset(initialize);
    return this;
}



namespace hkRouterC9D3 {

}

template <typename T> inline void hkDeallocateChunkC9D3(T* p, int n)
{
    hkMemoryRouter::getInstance().heap().blockFree(p, n * sizeof(T));
}

template <typename T> class hkSmallArrayC9D3
{
  public:
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    ~hkSmallArrayC9D3() throw()
    {
        if ((m_iCapacityState & 0x8000) == 0)
            hkDeallocateChunkC9D3(m_data, m_iCapacityState & 0x3fff);
    }
};

class FUN_00c9d340
{
  public:
    hkSmallArrayC9D3<void*> m_pHeadNode;
    hkSmallArrayC9D3<void*> m_iSecondInteger;

    ~FUN_00c9d340() throw();
};

// Destructor for a pair of small arrays; the body is empty because the member arrays free themselves.
// @fnv 0x00c9d340
FUN_00c9d340::~FUN_00c9d340() throw()
{}

namespace fnv_00c9d460 {

struct FnvCpu_FUN_00c9d460_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00c9d3b0();
    FnvCpu_FUN_00c9d460_CpuObject* FUN_00c9d460(unsigned int flags);
};
// @fnv 0x00c9d460
FnvCpu_FUN_00c9d460_CpuObject* FnvCpu_FUN_00c9d460_CpuObject::FUN_00c9d460(unsigned int flags)
{
    FUN_00c9d3b0();
    if (flags & 1)
    {
        hkMemoryRouter::getInstance().heap().blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00c9d460

namespace fnv_00d1f780 {



template <class T> class hkArrayD1F7
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00d08130
{
  public:
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    ~FUN_00d08130() throw();
};

class FUN_00d1f780 : public FUN_00d08130
{
  public:
    virtual ~FUN_00d1f780() throw();

    hkArrayD1F7<void*> m_ppData;
};

// Destructor that releases the array member by freeing its heap buffer and resetting it.
// @fnv 0x00d1f780
FUN_00d1f780::~FUN_00d1f780() throw()
{
    m_ppData.ClearAndRelease();
}
}  // namespace fnv_00d1f780

struct S00c92a80_Obj
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c(int a, int b, void* c, void* d, int n);
    int unk04[5];
    float m_f18;  // +0x18
};

struct __declspec(align(16)) S00c92a80_Range
{
    float lo;
    float hi;
    float range;
    float inv;
    S00c92a80_Range(float b, float a)
    {
        lo = a;
        hi = b;
        range = b - a;
        inv = range == 0.0f ? 0.0f : 1.0f / range;
    }
};

struct S00c92a80_cls
{
    int unk00;
    int unk04;
    S00c92a80_Obj* obj;
    void FUN_00c92a80(int a0, int a1);
};

// Reads a float from obj, builds a S00c92a80_Range, and calls obj->v1c with a0, a1, this, the range, and 1.
// @fnv 0x00c92a80
void S00c92a80_cls::FUN_00c92a80(int a0, int a1)
{
    float b = obj->m_f18;
    float a = obj->m_f18;
    S00c92a80_Range r(b, a);
    obj->v1c(a0, a1, this, &r, 1);
}

struct c9bfd0_ptr
{
    int p00, p04, p08, p0c, p10, p14, p18, p1c, p20;
    unsigned short p24;
    unsigned char p26;
};

struct c9bfd0_base
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    int u20, u24, u28, u2c, u30, u34, u38, u3c;
    int u40, u44, u48, u4c, u50, u54, u58, u5c;
    int u60, u64, u68, u6c, u70, u74, u78, u7c;
    int u80, u84, u88, u8c, u90, u94, u98, u9c;
    int uA0, uA4, uA8, uAc, uB0, uB4, uB8, uBc;
    int uC0, uC4, uC8;
    c9bfd0_ptr* uCc;
};

// @fnv 0x00c9bfd0
static __declspec(noinline) c9bfd0_ptr* FUN_00c9bfd0(c9bfd0_base* self, c9bfd0_ptr* out)
{
    c9bfd0_ptr* p = self->uCc;
    if (!p)
        *(unsigned char*)out = 0;
    else
        *(unsigned char*)out = (p->p26 >> 2) & 3;
    return out;
}

extern "C" c9bfd0_ptr* c9bfd0_out_val(void);
void c9bfd0_caller(c9bfd0_base* self)
{
    (void)FUN_00c9bfd0(self, c9bfd0_out_val());
}

// hkpSimulationIsland bit fields in the byte at +0x26.
struct IslandActivationBits
{
    char pad00[0x26];
    unsigned char m_isInActiveIslandsArray : 2;
    unsigned char m_activeMark : 2;
    unsigned char m_tmpActiveMark : 2;
    unsigned char m_inIntegrateJob : 2;
};
struct FUN_00c9bff0_Class
{
    int unk00;
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
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    void* m_cc;

    unsigned char* FUN_00c9bff0(unsigned char* out);
};

// Writes a 2-bit value extracted from byte 0x26 of m_cc into out, or 0 if m_cc is null.
// @fnv 0x00c9bff0
unsigned char* FUN_00c9bff0_Class::FUN_00c9bff0(unsigned char* out)
{
    if (m_cc == 0)
    {
        *out = 0;
        return out;
    }
    *out = static_cast<IslandActivationBits*>(m_cc)->m_activeMark;
    return out;
}

class hkpShapeContainerC9C0
{
  public:
    virtual void vfn_00();
    virtual int GetNumChildShapes() const;
};

class hkpShapeC9C0
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual const hkpShapeContainerC9C0* GetShapeContainer() const;
    int unk04;
    int unk08;
    int m_type;
};

struct hkpCollisionDispatcherC9C0
{
    int unk000[0x110 / 4];
    int m_shapeFlags[1];
};

struct hkpWorldC9C0
{
    int unk00[0x80 / 4];
    hkpCollisionDispatcherC9C0* m_pDispatcher;
};

class hkBoundingVolumeC9C0
{
  public:
    int m_dirty;
    int unk04, unk08, unk0C;
    int m_pChildShapeAabbs;
    int unk14, unk18, unk1C, unk20;
    int m_data;

    void Reset(int iNumChildren)
    {
        reinterpret_cast<::FUN_00d01ae0_shell *>(this)->FUN_00d01ae0(iNumChildren);
        m_dirty = 1;
        m_pChildShapeAabbs = 0;
    }
};

class hkpEntityC9C0
{
  public:
    int unk00[0x30 / 4];
    hkBoundingVolumeC9C0 m_boundingVolume;
    int unk58[(0xe8 - 0x58) / 4];
    unsigned char m_bFlag;

    void UpdateBoundingVolume(const hkpWorldC9C0* pkWorld, const hkpShapeC9C0* pkShape);
};

// Frees the current bounding volume storage, then resets it from pkShape's container when the shape flags indicate a container shape.
// @fnv 0x00c9c040
void hkpEntityC9C0::UpdateBoundingVolume(const hkpWorldC9C0* pkWorld, const hkpShapeC9C0* pkShape)
{
    if (m_boundingVolume.m_data)
        reinterpret_cast<::hkMapD01A *>(&(m_boundingVolume))->FreeStorage();
    if (!pkWorld || !pkShape)
        return;

    int iShapeFlags = pkWorld->m_pDispatcher->m_shapeFlags[pkShape->m_type];
    bool m_bIsOptional = false;
    const hkpShapeContainerC9C0* pkContainer;
    if (iShapeFlags & 0x80)
    {
        pkContainer = pkShape->GetShapeContainer();
    }
    else if (iShapeFlags & 0x100)
    {
        pkContainer = pkShape->GetShapeContainer();
        m_bIsOptional = true;
    }
    else
    {
        return;
    }

    if ((m_bFlag == 5 || m_bFlag == 4) && m_bIsOptional)
        return;

    m_boundingVolume.Reset(pkContainer->GetNumChildShapes());
    if (m_bFlag == 5)
        reinterpret_cast<::FUN_00c9bfa0_Class *>(this)->FUN_00c9bfa0();
}

namespace fnv_00c9c0f0 {
template <class T> class hkSmallArrayC9C0
{
  public:
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
            {
                return i;
            }
        }
        return -1;
    }
};

class hkpListenerC9C0;

class hkpWorldC9C0
{
  public:
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
    int unk210;
    hkSmallArrayC9C0<hkpListenerC9C0*>* m_kListeners;

    void RemoveListener(hkpListenerC9C0* listener);
};

// Finds the given listener in m_kListeners and sets its slot to 0.
// @fnv 0x00c9c0f0
void hkpWorldC9C0::RemoveListener(hkpListenerC9C0* listener)
{
    hkSmallArrayC9C0<hkpListenerC9C0*>& listeners = *m_kListeners;
    int i = listeners.indexOf(listener);
    listeners.m_data[i] = 0;
}
}  // namespace fnv_00c9c0f0

template <class T> class hkSmallArrayC9C1
{
  public:
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};

class hkOwnerC9C1
{
  public:
    int unk000[128];
    hkSmallArrayC9C1<void*> m_entries;

    void FUN_00c9c140(void* entry);
};

// Sets the entry at the index found by indexOf to 0 in m_entries.
// @fnv 0x00c9c140
void hkOwnerC9C1::FUN_00c9c140(void* entry)
{
    m_entries.m_data[m_entries.indexOf(entry)] = 0;
}

struct hkBoolC9C
{
    char m_cBooleanValue;
    hkBoolC9C(char b)
    {
        m_cBooleanValue = b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkpSimulationIslandC9C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned short unk24;
    unsigned char m_isSparse : 1;
    unsigned char m_bActionListCleanupNeeded : 1;
    unsigned char m_bActiveMark : 2;
    hkBoolC9C isActive() const
    {
        return hkBoolC9C(m_bActiveMark);
    }
};

struct hkpWorldC9C
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    unsigned char unk304;
    unsigned char m_bWantDeactivation;
    unsigned char m_frameA;
    unsigned char m_frameB;
};


class hkpMotionC9C
{
  public:
    virtual ~hkpMotionC9C();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];

};

class hkpEntityC9C
{
  public:
    virtual ~hkpEntityC9C();
    int unk04;
    hkpWorldC9C* m_pOwningWorld;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    hkpSimulationIslandC9C* m_pSimulationIsland;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    hkpMotionC9C m_pMotionState;

    void FUN_00c9c1d0();
};
// @fnv 0x00c9c300
void hkpEntityC9C3::FUN_00c9c300()
{
    if (m_pOwningWorld && m_pOwningWorld->areCriticalOperationsLocked())
    {
        hkWorldOperationC9C3 kOp;
        kOp.m_pEntity = this;
        reinterpret_cast<::WorldWithPending *>((m_pOwningWorld))->FUN_00c91160();
        return;
    }
    reinterpret_cast<::hkpEntityC9C *>(this)->FUN_00c9c1d0();
}

// @fnv 0x00c9c1d0
void hkpEntityC9C::FUN_00c9c1d0()
{
    hkBoolC9C active(0);
    if (m_pSimulationIsland)
        active = m_pSimulationIsland->isActive();
    if (!active && m_pMotionState.m_type != 5 && m_pOwningWorld)
    {
        m_pMotionState.m_ausDeactivationNumInactiveFrames[0] = 0;
        m_pMotionState.m_ausDeactivationNumInactiveFrames[1] = 0;
        ::fnv_00cb5500::AddEntryToList(m_pOwningWorld, (::fnv_00cb5500::Entry *)(m_pSimulationIsland));
        reinterpret_cast<::FlagState *>(&(m_pMotionState))->SetFlagBits(m_pOwningWorld->m_bWantDeactivation, m_pOwningWorld->m_frameA,
                                   m_pOwningWorld->m_frameB);
    }
}


namespace fnvc_adapt {

}

template <class T> class hkSmallArrayC9C6
{
  public:
    hkSmallArrayC9C6() : m_data(0), m_iElementCount(0), m_iCapacityState(0x8000)
    {}

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }

    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
};

struct ListenersC9C6
{
    static void* operator new(size_t nbytes)
    {
        return hkMemoryRouter::getInstance().heap().blockAlloc(nbytes);
    }

    hkSmallArrayC9C6<void*> m_pHeadNode;
    hkSmallArrayC9C6<void*> m_iSecondInteger;
};

class HostC9C6
{
  public:
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
    int unk210;
    ListenersC9C6* m_pkListeners;

    void FUN_00c9c670(void* pvListener);
};

// Ensures m_pkListeners is allocated, then nulls the entry for pvListener in m_pkListeners->m_iSecondInteger.
// @fnv 0x00c9c670
void HostC9C6::FUN_00c9c670(void* pvListener)
{
    if (!m_pkListeners)
        m_pkListeners = new ListenersC9C6;
    hkSmallArrayC9C6<void*>& kArray = m_pkListeners->m_iSecondInteger;
    kArray[kArray.indexOf(pvListener)] = 0;
}

namespace fnv_00c9c7c0 {


namespace fnvc_adapt {

}

template <class T> class hkArrayC9C7
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkMemoryRouter::getInstance().heap(), n);
        m_iElementCount = n;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkpConstraintInstanceC9C7;

struct hkConstraintInternalC9C7
{
    hkpConstraintInstanceC9C7* m_pHavokConstraint;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};

class hkpEntityC9C7
{
  public:
    int unk000[0xac / 4];
    hkConstraintInternalC9C7* m_eSmallArraySerializeOverrideType;
    unsigned short m_constraintsMasterSize;
    unsigned short m_constraintsMasterCapacity;
    hkpConstraintInstanceC9C7** m_kSlaveConstraints;
    int m_constraintsSlaveSize;

    void CollectConstraints(hkArrayC9C7<hkpConstraintInstanceC9C7*>& constraints);
};

// @fnv 0x00c9c7c0
void hkpEntityC9C7::CollectConstraints(hkArrayC9C7<hkpConstraintInstanceC9C7*>& constraints)
{
    constraints.SetSizeAndGrow(::FUN_00c9c380((void *)this, {}));
    int k = 0;
    for (int i = 0; i < m_constraintsMasterSize; i++)
        constraints[k++] = m_eSmallArraySerializeOverrideType[i].m_pHavokConstraint;
    for (int i = 0; i < m_constraintsSlaveSize; i++)
        constraints[k++] = m_kSlaveConstraints[i];
}
}  // namespace fnv_00c9c7c0

class hkLocalFrame;
class hkpConstraintInstance;
class hkpEntityExtendedListeners;
extern const int DAT_010c6f7c;
struct hkFinishLoadedObjectFlagC9CE
{
    int m_bFinishing;
};
struct hkSmallArrayC9CE : public hkpEntitySmallArraySerializeOverrideType
{
    hkSmallArrayC9CE()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x8000;
    }
};
template <class T> struct hkArrayC9CE : public hkArray<T>
{
    hkArrayC9CE()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
    }
};
inline void setHalfC9CE(hkHalf& kHalf, const float& f)
{
    int t = ((const int*)&f)[0];
    kHalf = hkHalf(t >> 16);
}
class __declspec(novtable) hkpMotionC9CE : public hkpMaxSizeMotion
{
  public:
    hkpMotionC9CE(int flag)
    {
        *(int**)this = &DAT_010c59f4;
        if (flag)
            setHalfC9CE(m_fGravityFactor, 1.0f);
    }
};
class __declspec(novtable) hkpMaxSizeMotionC9CE : public hkpMotionC9CE
{
  public:
    hkpMaxSizeMotionC9CE(int flag) : hkpMotionC9CE(flag)
    {
        *(const int**)this = &::g_unk010c6c64;
    }
};
class FUN_00c9d1c0
{
  public:
    FUN_00c9d1c0(int flag) throw();
};
class FUN_00c9d100
{
  public:
    FUN_00c9d100(int flag) throw();
};
class FUN_00c9d130
{
  public:
    FUN_00c9d130(int flag) throw();
};
class FUN_00c9d1f0
{
  public:
    FUN_00c9d1f0(int flag) throw();
};
class FUN_00c9d220
{
  public:
    FUN_00c9d220(int flag) throw();
};
class FUN_00cd2c50 : public hkpWorldObject
{
  public:
    FUN_00cd2c50(int flag) throw();
};
class __declspec(novtable) hkpEntityBaseC9CE : public FUN_00cd2c50
{
  public:
    hkpEntityBaseC9CE(int flag) throw() : FUN_00cd2c50(flag)
    {
        *(const int**)this = &DAT_010c6f7c;
    }
};
class __declspec(novtable) FUN_00c9ce00 : public hkpEntityBaseC9CE
{
  public:
    hkpMaterial m_iMaterialIndex;
    void* m_pEntityUserData;
    hkReal m_fBulletSpread;
    void* m_pShape;
    hkUint32 m_uiFilterInfo;
    hkUint16 m_usStorageIndex;
    hkUint16 m_usNextProcessCallbackDelay;
    hkSmallArrayC9CE m_eSmallArraySerializeOverrideType;
    hkArrayC9CE<hkpConstraintInstance*> m_kSlaveConstraints;
    hkArrayC9CE<hkUint8> m_pByteBuffer;
    void* m_pSimulationIsland;
    hkInt8 m_iAutoRemoveLevel;
    hkUint8 m_ucNumShapeKeysInContactPointProperties;
    hkUint8 m_ucResponseModifierFlags;
    hkUint32 m_uiUniqueId;
    hkpEntitySpuCollisionCallback m_kSpuCollisionCallback;
    hkpMaxSizeMotionC9CE m_pMotionState;
    hkSmallArrayC9CE m_kContactListeners;
    hkSmallArrayC9CE m_ppActions;
    hkLocalFrame* m_pLocalFrame;
    hkpEntityExtendedListeners* m_pExtendedListeners;

    FUN_00c9ce00(int flag) throw();
};
// Constructs the base and m_pMotionState from flag, then if flag is set re-constructs m_pMotionState as the motion class matching its m_type.
// @fnv 0x00c9ce00
FUN_00c9ce00::FUN_00c9ce00(int flag) throw() : hkpEntityBaseC9CE(*(volatile int*)&flag), m_pMotionState(flag)
{
    if (flag)
    {
        switch (m_pMotionState.m_type)
        {
        case hkpMotion::MOTION_SPHERE_INERTIA:
            ::new (&m_pMotionState) FUN_00c9d190(flag);
            break;
        case hkpMotion::MOTION_BOX_INERTIA:
            ::new (&m_pMotionState) FUN_00c9d1c0(flag);
            break;
        case hkpMotion::MOTION_KEYFRAMED:
            ::new (&m_pMotionState) FUN_00c9d100(flag);
            break;
        case hkpMotion::MOTION_FIXED:
            ::new (&m_pMotionState) FUN_00c9d130(flag);
            break;
        case hkpMotion::MOTION_THIN_BOX_INERTIA:
            ::new (&m_pMotionState) FUN_00c9d1f0(flag);
            break;
        case hkpMotion::MOTION_CHARACTER:
            ::new (&m_pMotionState) FUN_00c9d220(flag);
            break;
        }
    }
}

namespace fnv_00c9d130 {
struct FinishLoadedFlag
{
    int m_bFinishing;
};
struct PackedHalf
{
    short bits;
    void operator=(float f)
    {
        int value = *(int*)&f;
        bits = (short)(value >> 16);
    }
};
class FinishableBase
{
  public:
    FinishableBase(FinishLoadedFlag flag)
    {
        if (flag.m_bFinishing)
        {
            PackedHalf* scale = reinterpret_cast<PackedHalf*>(&reinterpret_cast<hkpMotion*>(this)->m_fGravityFactor);
            *scale = 1.0f;
        }
    }
    virtual ~FinishableBase() throw();
};
class FUN_00c9d130 : public FinishableBase
{
  public:
    FUN_00c9d130(FinishLoadedFlag flag) throw();
    virtual ~FUN_00c9d130() throw();
};
// Constructs the object by delegating to the FinishableBase constructor with the provided FinishLoadedFlag.
// @fnv 0x00c9d130
FUN_00c9d130::FUN_00c9d130(FinishLoadedFlag flag) throw() : FinishableBase(flag)
{}
}  // namespace fnv_00c9d130

namespace fnv_00c9d220 {
struct MotionCtorBase : public hkpMotion
{
    virtual ~MotionCtorBase();
    MotionCtorBase(int flag)
    {
        if (flag)
        {
            *reinterpret_cast<float*>(&flag) = 1.0f;
            volatile short& gravityFactor = m_fGravityFactor;
            gravityFactor = static_cast<short>(flag >> 16);
        }
    }
};
struct FUN_00c9d220 : public MotionCtorBase
{
    virtual ~FUN_00c9d220();
    FUN_00c9d220(int flag);
};
// Constructs a motion object by delegating to MotionCtorBase with the given flag.
// @fnv 0x00c9d220
FUN_00c9d220::FUN_00c9d220(int flag) : MotionCtorBase(flag)
{}
}  // namespace fnv_00c9d220

// Recursively sorts the hkpAgentEntryD250 array in place using the quicksort algorithm with the hkEntryLessD250 comparator.
// @fnv 0x00c9d250
void __cdecl FUN_00c9d250(hkpAgentEntryD250** pArr, int aiLow, int aiHigh, hkEntryLessD250 cmpLess)
{
    int i, iRight;
    hkpAgentEntryD250* x;

begin:
    i = aiLow;
    iRight = aiHigh;
    x = pArr[(aiLow + aiHigh) >> 1];

    do
    {
        while (cmpLess(pArr[i], x))
            i++;
        while (cmpLess(x, pArr[iRight]))
            iRight--;

        if (iRight >= i)
        {
            if (iRight != i)
            {
                __declspec(align(16)) hkpAgentEntryD250* t = pArr[iRight];
                pArr[iRight] = pArr[i];
                pArr[i] = t;
            }
            i++;
            iRight--;
        }
    } while (i <= iRight);

    if (aiLow < iRight)
        FUN_00c9d250(pArr, aiLow, iRight, cmpLess);
    if (i < aiHigh)
    {
        aiLow = i;
        goto begin;
    }
}

struct FUN_00c9c700_Array
{
    int* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
    int unk08;
    unsigned short unk0C;
    unsigned short unk0E;
};


struct FUN_00c9c700_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    FUN_00c9c700_Array* unk214;

    void FUN_00c9c700(int value);
};

// Initializes the internal array if needed, then inserts value into the first empty slot or appends it, growing capacity when full.
// @fnv 0x00c9c700
void FUN_00c9c700_Class::FUN_00c9c700(int value)
{
    if (unk214 == 0)
    {
        FUN_00c9c700_Array* array = static_cast<FUN_00c9c700_Array*>(hkMemoryRouter::getInstance().heap().blockAlloc(0x10));

        if (array != 0)
        {
            array->m_data = 0;
            array->m_iElementCount = 0;
            array->m_iCapacityState = 0x8000;
            array->unk08 = 0;
            array->unk0C = 0;
            array->unk0E = 0x8000;
        }
        else
        {
            array = 0;
        }

        unk214 = array;
    }

    FUN_00c9c700_Array* array = unk214;
    int index = 0;

    if (0 < array->m_iElementCount)
    {
        int* data = array->m_data;
        int* p = data;
        do
        {
            if (*p == 0)
            {
                if (index >= 0)
                {
                    data[index] = value;
                    return;
                }
                break;
            }
            ++index;
            ++p;
        } while (index < unk214->m_iElementCount);
    }

    if (array->m_iElementCount == (array->m_iCapacityState & 0x3fff))
        ::FUN_00d06cb0((::GrowBuf *)(array), 4);

    array->m_data[array->m_iElementCount] = value;
    ++array->m_iElementCount;
}

struct hkBoolQ
{
    hkBoolQ(int b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

template <class T> struct hkArrayQ
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkpSimulationIslandQ
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned char unk24;
    unsigned char m_bSplitCheckRequested : 2;
    unsigned char m_bSparseEnabled : 2;
    unsigned char m_flags25hi : 4;
    unsigned char m_flags26lo : 2;
    unsigned char m_bActiveMark : 2;
    unsigned char m_flags26hi : 4;
    unsigned char unk27;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    hkArrayQ<hkpEntity*> m_kActorEntries;

    hkBoolQ isActive() const
    {
        return m_bActiveMark;
    }
};

// If the island is active: runs PropagateStateToChildren when split-check or sparse is set, sets each entity's reference position w to FLT_MAX, then calls AddItemToContainer.
// @fnv 0x00c9c240
void FUN_00c9c240_holder::FUN_00c9c240()
{
    hkpSimulationIslandQ* island = (hkpSimulationIslandQ*)m_pSimulationIsland;
    if (island)
    {
        unsigned char act = island->m_bActiveMark;
        unsigned char* pact = &act;
        if (*pact)
        {
            if (island->m_bSplitCheckRequested || island->m_bSparseEnabled)
            {
                hkpWorld* world = (hkpWorld*)m_pOwningWorld;
                hkUint32 minIslandSize = world->m_uiMinDesiredIslandSize;
                world->m_uiMinDesiredIslandSize = 0;
                ((hkpSimulationIslandQ*)m_pSimulationIsland)->m_bSparseEnabled = 0;
                ((hkpSimulationIslandQ*)m_pSimulationIsland)->m_bSplitCheckRequested = 1;
                ::PropagateStateToChildren((::Object *)(m_pOwningWorld),
                                         (int *)(::hkpSimulationIslandQ *)((hkpSimulationIslandQ*)m_pSimulationIsland));
                ((hkpWorld*)m_pOwningWorld)->m_uiMinDesiredIslandSize = minIslandSize;
            }
            island = (hkpSimulationIslandQ*)m_pSimulationIsland;
            int i = 0;
            if (island->m_kActorEntries.GetLogicalSize() > 0)
            {
                hkpEntity** entities = island->m_kActorEntries.m_data;
                do
                {
                    hkpEntity* entity = *entities++;
                    entity->m_pMotionState.m_akDeactivationReferencePositions[0].w = 3.40282e+38f;
                    entity->m_pMotionState.m_akDeactivationReferencePositions[1].w = 3.40282e+38f;
                } while (++i < island->m_kActorEntries.GetLogicalSize());
            }
            ::fnv_00cb5420::AddItemToContainer((::fnv_00cb5420::S_00cb5420_Container *)(m_pOwningWorld), (::fnv_00cb5420::S_00cb5420_Item *)(island));
        }
    }
}

namespace fnv_00c9d1f0 {
namespace hkC9D1 {

struct FinishingFlag
{
    int m_bFinishing;
};

class hkHalf
{
    short m_uiFilterValue;

  public:
    hkHalf& operator=(float f)
    {
        int t = ((const int*)&f)[0];
        m_uiFilterValue = (short)(t >> 16);
        return *this;
    }
};

class hkpMotion
{
  public:
    hkpMotion(FinishingFlag flag)
    {
        if (flag.m_bFinishing)
            m_fGravityFactor = 1.0f;
    }
    virtual ~hkpMotion();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    short unk11C;
    hkHalf m_fGravityFactor;
};

class hkpBoxMotion : public hkpMotion
{
  public:
    hkpBoxMotion(FinishingFlag flag) : hkpMotion(flag)
    {}
    virtual ~hkpBoxMotion();
};

}

namespace FUN_00c9d1f0 {

class hkpThinBoxMotion : public hkC9D1::hkpMotion
{
  public:
    hkpThinBoxMotion(hkC9D1::FinishingFlag flag);
    virtual ~hkpThinBoxMotion();
};

// @fnv 0x00c9d1f0
hkpThinBoxMotion::hkpThinBoxMotion(hkC9D1::FinishingFlag flag) : hkC9D1::hkpMotion(flag)
{}

}
}  // namespace fnv_00c9d1f0

namespace fnv_00c9c8f0 {

struct FnvRA
{
    virtual ~FnvRA();
    int m4;
};
struct FnvRB
{
    int x;
};
struct FnvRef : FnvRA, FnvRB
{
    virtual ~FnvRef();
};
struct FnvSmall
{
    void** data;
    unsigned short size;
    unsigned short flags;
    __forceinline void releaseMem(int elem)
    {
        if (!(flags & 0x8000))
        {
            unsigned c = flags & 0x3fff;
            void* d = data;
            hkMemoryRouter* router = &hkMemoryRouter::getInstance();
            hkMemoryAllocator* mem = router->m_heap;
            mem->blockFree(d, c * elem);
        }
    }
    __forceinline void clearAndDealloc(int elem)
    {
        releaseMem(elem);
        size = 0;
        data = 0;
        flags = (flags & 0xc000) | 0x8000;
    }
    __forceinline void clearIfEmpty(bool& used)
    {
        for (int i = 0; i < size; ++i)
            if (data[i])
            {
                used = true;
                return;
            }
        clearAndDealloc(4);
    }
    __forceinline bool hasAny()
    {
        for (int i = 0; i < size; ++i)
            if (data[i])
                return true;
        return false;
    }
    __forceinline bool clearIfEmpty()
    {
        for (int i = 0; i < size; ++i)
            if (data[i])
                return true;
        clearAndDealloc(4);
        return false;
    }
};
struct FnvArray
{
    void* data;
    int size;
    int flags;
};
struct FnvTwo
{
    FnvSmall one;
    FnvSmall two;
    __forceinline void destroy()
    {
        two.releaseMem(4);
        one.releaseMem(4);
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        hkMemoryAllocator* mem = router->m_heap;
        mem->blockFree(this, 16);
    }
};
struct EntityRebuild
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    int unk58;
    int unk5c;
    void* p60;
    int n64;
    int f68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    FnvRef* p98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    FnvSmall master;
    FnvArray slave;
    FnvArray runtime;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    FnvSmall contact;
    FnvSmall actions;
    int localFrame;
    FnvTwo* extended;
    void FUN_00c9c8f0();
};
// Deletes p98 after FUN_00c9c140, then frees storage of p60, master, slave, runtime, contact, actions and extended when each is empty.
// @fnv 0x00c9c8f0
void EntityRebuild::FUN_00c9c8f0()
{
    FnvRef* old = p98;
    if (old)
    {
        reinterpret_cast<::hkOwnerC9C1 *>((old))->FUN_00c9c140({});
        delete old;
        p98 = 0;
    }
    if (n64 == 0)
    {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        hkMemoryAllocator* mem = router->m_heap;
        int f = f68;
        n64 = 0;
        if (!(f & 0x80000000))
            mem->bufFree(p60, (f & 0x3fffffff) * 8);
        p60 = 0;
        f68 = 0x80000000;
    }
    if (master.size == 0)
        master.clearAndDealloc(48);
    if (slave.size == 0)
    {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        hkMemoryAllocator* mem = router->m_heap;
        int f = slave.flags;
        slave.size = 0;
        if (!(f & 0x80000000))
            mem->bufFree(slave.data, (f & 0x3fffffff) * 4);
        slave.data = 0;
        slave.flags = 0x80000000;
    }
    if (runtime.size == 0)
    {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        hkMemoryAllocator* mem = router->m_heap;
        int f = runtime.flags;
        runtime.size = 0;
        if (!(f & 0x80000000))
            mem->bufFree(runtime.data, f & 0x3fffffff);
        runtime.data = 0;
        runtime.flags = 0x80000000;
    }
    contact.clearIfEmpty();
    bool usedContact = false;
    FnvTwo* pExtended = extended;
    if (pExtended)
    {
        pExtended->one.clearIfEmpty(usedContact);
    }
    bool usedAction = false;
    pExtended = extended;
    if (pExtended)
    {
        pExtended->two.clearIfEmpty(usedAction);
    }
    if (!usedContact && !usedAction)
    {
        pExtended = extended;
        if (pExtended)
            pExtended->destroy();
        extended = 0;
    }
    if (actions.size == 0)
        actions.clearAndDealloc(4);
}
}  // namespace fnv_00c9c8f0

namespace fnv_00c9cf60 {




template <class T> class hkArrayC9CF
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayC9CF() throw()
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

template <class T> class hkSmallArrayC9CF
{
  public:
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    ~hkSmallArrayC9CF() throw()
    {
        if ((m_iCapacityState & 0x8000) == 0)
        {
            int iCapacity = m_iCapacityState & 0x3fff;
            T* pData = m_data;
            hkMemoryRouter::getInstance().heap().blockFree(pData, iCapacity * sizeof(T));
        }
    }
};

struct hkConstraintInternalC9CF
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
};

struct hkReferencedObjectC9CF
{
};

template <class T> struct hkRefPtrC9CF
{
    T* m_pRetainedObject;

    ~hkRefPtrC9CF() throw()
    {
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
};

class FUN_00d1dff0
{
  public:
    ~FUN_00d1dff0() throw();

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    int unkF0, unkF4, unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
};

class FUN_00c9d340
{
  public:
    ~FUN_00c9d340() throw();
    static void operator delete(void* p, size_t uiNumBytes)
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, uiNumBytes);
    }

    int unk00, unk04, unk08, unk0C;
};

struct hkReferencedObjectBaseC9CF
{
    virtual ~hkReferencedObjectBaseC9CF() throw();
    int m_usMemSizeAndFlags;
};

struct hkpContactListenerC9CF
{
    int unk00;
};

struct LimitUtilC9CF : public hkReferencedObjectBaseC9CF, public hkpContactListenerC9CF
{
    virtual ~LimitUtilC9CF() throw();
};

struct OwnerC9CF
{
};


namespace FUN_00c9d3b0 {
class hkpWorldObject
{
  public:
    virtual ~hkpWorldObject() throw();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88;
};
}

class FUN_00c9cf60 : public FUN_00c9d3b0::hkpWorldObject
{
  public:
    virtual ~FUN_00c9cf60() throw();

    int unk8C, unk90, unk94;
    LimitUtilC9CF* m_pEntityUserData;
    float m_fBulletSpread;
    void* m_pShape;
    unsigned int m_uiFilterInfo;
    unsigned short m_usStorageIndex;
    unsigned short m_usNextProcessCallbackDelay;
    hkSmallArrayC9CF<hkConstraintInternalC9CF> m_eSmallArraySerializeOverrideType;
    hkArrayC9CF<void*> m_kSlaveConstraints;
    hkArrayC9CF<unsigned char> m_pByteBuffer;
    void* m_pSimulationIsland;
    int unkD0;
    unsigned int m_uiUniqueId;
    int unkD8, unkDC;
    FUN_00d1dff0 m_pMotionState;
    hkSmallArrayC9CF<void*> m_kContactListeners;
    hkSmallArrayC9CF<void*> m_ppActions;
    hkRefPtrC9CF<hkReferencedObjectC9CF> m_pLocalFrame;
    FUN_00c9d340* m_pExtendedListeners;
    int unk218, unk21C;
};

// Destructor: if m_pEntityUserData is set, passes it to FUN_00c9c140 and deletes it; calls DeleteCallbacks(this); deletes m_pExtendedListeners if set.
// @fnv 0x00c9cf60
FUN_00c9cf60::~FUN_00c9cf60() throw()
{
    LimitUtilC9CF* pkUtil = m_pEntityUserData;
    if (pkUtil)
    {
        reinterpret_cast<::hkOwnerC9C1 *>((((OwnerC9CF*)this)))->FUN_00c9c140(pkUtil);
        delete pkUtil;
        m_pEntityUserData = 0;
    }
    ::DeleteCallbacks((::ProfOwner *)(void *)(this));
    if (m_pExtendedListeners)
        delete m_pExtendedListeners;
}
}  // namespace fnv_00c9cf60

namespace fnv_00c9d3b0 {




template <class T> class hkArrayC9D3
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayC9D3() throw()
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace FUN_00cb0c00 {
class hkStringPtr
{
  public:
    ~hkStringPtr() throw();
    const char* m_pcText;
};
}

namespace hkC9D3 {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
}

namespace hkC9D3 {
struct hkpPropertyC9D3
{
    unsigned int m_key;
    unsigned int m_uiAlignmentPadding;
    unsigned int m_valueLo;
    unsigned int m_valueHi;
};

struct hkpLinkedCollidableEntryC9D3
{
    void* m_pAgentEntry;
    void* m_pCollidable;
};
}

namespace FUN_00c9d3b0 {
class hkpWorldObject : public hkC9D3::hkReferencedObject
{
  public:
    virtual ~hkpWorldObject();

    void* m_pOwningWorld;
    unsigned long m_ulUserData;
    hkC9D3::hkReferencedObject* m_pCollisionShape;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    hkArrayC9D3<hkC9D3::hkpLinkedCollidableEntryC9D3> m_kCollisionEntries;
    int m_uiThreadId;
    int m_usMarkedForWrite;
    FUN_00cb0c00::hkStringPtr m_name;
    hkArrayC9D3<hkC9D3::hkpPropertyC9D3> m_kProperties;
    hkC9D3::hkReferencedObject* m_kNextStreamField;
};

// Releases the collision shape and next stream field references held by the hkpWorldObject.
// @fnv 0x00c9d3b0
hkpWorldObject::~hkpWorldObject()
{
    if (m_pCollisionShape)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pCollisionShape))->FUN_00c905b0();
    if (m_kNextStreamField)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_kNextStreamField))->FUN_00c905b0();
}
}
}  // namespace fnv_00c9d3b0
