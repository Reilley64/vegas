
// src/havok/physics/dynamics/action/hkpunaryaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/action/hkpunaryaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <new>
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00cb0a60.h"
#include "fnv/decl/ListenerC92B.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpWorldDecomp.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00c97000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010cc000.h"
#include "havok/hkpUnaryAction.h"

struct FUN_00c97510
{
};

struct FUN_00d2b1f0 : hkpUnaryAction
{
    void EntityRemovedCallback(hkpEntity*);
};

// @fnv 0x00d2b1f0
void FUN_00d2b1f0::EntityRemovedCallback(hkpEntity*)
{
    if (m_pOwningWorld)
        reinterpret_cast<::hkpWorldDecomp *>(m_pOwningWorld)->FUN_00c97510(this);
}

extern int DAT_010ce528;

struct DDCC60World
{
};

struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};

struct FUN_00d2b2b0_class : hkpUnaryAction
{
    void FUN_00d2b2b0();
};

// Resets the vtable, releases the world reference if present, then destroys the lock and resets the vtable again.
// @fnv 0x00d2b2b0
void FUN_00d2b2b0_class::FUN_00d2b2b0()
{
    *(void**)this = &DAT_010ce528;

    if (m_pEntity)
    {
        reinterpret_cast<::hkReferencedObjectC905 *>(m_pEntity)->FUN_00c905b0();
        m_pEntity = 0;
    }

    *(void**)this = &DAT_010cc2fc;
    ::FUN_00cb0c00(&m_name);
    *(void**)this = &::DAT_0102e388;
}

struct hkMemoryManager
{
    virtual void FUN_00d4d950_0() = 0;
    virtual void FUN_00d4d950_1() = 0;
    virtual void free(void* object, unsigned int size) = 0;
};

struct NineIntegerRecord
{
    unsigned char padding[0x10];
    hkMemoryManager* memoryManager;
};

NineIntegerRecord* _D1A0E0GetMemoryRouter();

struct Action
{
    virtual void FUN_00d4d950_2() = 0;
    unsigned short size;

    Action* FUN_00d4d950(unsigned char flags);
};

// Calls FUN_00d2b2b0, then if flags bit 0 is set frees this via the memory router's memory manager, and returns this.
// @fnv 0x00d4d950
Action* Action::FUN_00d4d950(unsigned char flags)
{
    static_cast<::FUN_00d2b2b0_class *>(nullptr)->FUN_00d2b2b0();

    if (flags & 1)
    {
        NineIntegerRecord* router = _D1A0E0GetMemoryRouter();
        router->memoryManager->free(this, size);
    }

    return this;
}

class hkpWorld;

class hkpEntity : public hkReferencedObject
{
  public:
};

class hkpWorld
{
  public:
};

class UnaryActionHelper : public hkpUnaryAction
{
  public:
    void SetEntity(hkpEntity* entity);
};

// @fnv 0x00d2b210
void UnaryActionHelper::SetEntity(hkpEntity* entity)
{
    if (m_pEntity)
    {
        if (hkpWorld* world = (hkpWorld*)m_pOwningWorld)
        {
            ::fnv_00c976a0::RemoveActionFromEntity((::fnv_00c976a0::hkpActionC976 *)(world), (::fnv_00c976a0::hkpEntityC976 *)(::hkpUnaryAction *)(this));
        }
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pEntity))->FUN_00c905b0();
        m_pEntity = 0;
    }
    m_pEntity = entity;
    reinterpret_cast<::FUN_00c90510_class *>((m_pEntity))->FUN_00c90510();
    if (hkpWorld* world = (hkpWorld*)m_pOwningWorld)
    {
        reinterpret_cast<::ListenerC92B *>((world))->FUN_00c92bd0((::EntityC92B *)(::hkpUnaryAction *)(this), (::WorldC92B *)(m_pEntity));
    }
}

struct FUN_00cb0a60_Field
{
    unsigned int value;
};
struct FUN_00c90510_Entity
{
};
struct FUN_00d2b260
{
    void* vptr;
    unsigned short memSizeAndFlags;
    short referenceCount;
    void* world;
    void* island;
    unsigned int userData;
    FUN_00cb0a60_Field name;
    FUN_00c90510_Entity* entity;
    FUN_00d2b260(FUN_00c90510_Entity* entity, unsigned int userData);
};
// @fnv 0x00d2b260
FUN_00d2b260::FUN_00d2b260(FUN_00c90510_Entity* apEntity, unsigned int auiUserData)
{
    referenceCount = 1;
    userData = auiUserData;
    vptr = &DAT_010cc2fc;
    world = 0;
    island = 0;
    new ((void *)&(name)) struct ::FUN_00cb0a60();
    vptr = &DAT_010ce528;
    entity = apEntity;
    if (apEntity)
        reinterpret_cast<::FUN_00c90510_class *>((apEntity))->FUN_00c90510();
}

class hkMemoryAllocatorXd2b2f0;

struct hkMemoryRouterXd2b2f0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXd2b2f0* m_pStreamAllocator;
    hkMemoryAllocatorXd2b2f0& heap()
    {
        return *m_pStreamAllocator;
    }
};



template <class T> __forceinline void constructWithCopyXd2b2f0(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayXd2b2f0
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
        hkMemoryAllocatorXd2b2f0& kAlloc = (*static_cast<hkMemoryRouterXd2b2f0*>(::FUN_00c85750())).heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyXd2b2f0(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkObjXd2b2f0
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_uiFilterValue;

    void AppendPointer(hkArrayXd2b2f0<void*>& kArray);
};

// Appends the object's stored pointer to the given array.
// @fnv 0x00d2b2f0
void hkObjXd2b2f0::AppendPointer(hkArrayXd2b2f0<void*>& kArray)
{
    kArray.AddBack(m_uiFilterValue);
}
