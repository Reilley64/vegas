
// src/havok/physics/utilities/visualdebugger/hkpphysicscontext.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/hkpphysicscontext.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include "generated/data/vtables.h"
#include <new>
#include "fnv/decl/Debugger836.h"
#include "fnv/decl/FUN_00c90b80.h"
#include "fnv/decl/FUN_00c91180_Class.h"
#include "fnv/decl/FUN_00c91190_Class.h"
#include "fnv/decl/FUN_00c929e0_ThisClass.h"
#include "fnv/decl/Src_00c91c50.h"
#include "fnv/decl/fnv_00c937e0__hkpWorldXc937e0.h"
#include "fnv/decl/fnv_00c93820__hkpWorldC938.h"
#include "fnv/decl/fnv_00c93860__hkpWorldXc93860.h"
#include "fnv/decl/fnv_00cd1330__FUN_00cd1330_cls.h"
#include "fnv/decl/hkOwnerXc937a0.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkWorldC917.h"
#include "fnv/decl/hkWorldC9175.h"
#include "fnv/decl/hkWorldC91F.h"
#include "fnv/decl/hkWorldXc91700.h"
#include "fnv/decl/hkWorldXc91a70.h"
#include "fnv/decl/hkpWorld_Listener.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d63000.h"
#include "fnv/symbols_00d64000.h"
#include "fnv/symbols_00d66000.h"
#include "fnv/symbols_00d68000.h"
#include "fnv/symbols_010cb000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01269000.h"
void __cdecl FUN_00d6ad40();
void __cdecl FUN_00d6a850();
void __cdecl RegisterCenterOfMass();
void __cdecl RegisterConstraintsProcessFactory();
void __cdecl RegisterContactPointsInactive();
void __cdecl DispatchStateHandler();
void __cdecl RegisterToiCounter();
void __cdecl RegisterInertiaTensors();
void __cdecl RegisterShapesProcess();
void __cdecl FUN_00d651c0();
void __cdecl FUN_00d63da0();
void __cdecl RegisterSnapshotCommands();
void __cdecl RegisterWeldingViewer();

// @fnv 0x00cd1ed0
void __cdecl FUN_00cd1ed0()
{
    FUN_00d6ad40();
    FUN_00d6a850();
    RegisterCenterOfMass();
    RegisterConstraintsProcessFactory();
    ::RegisterConvexRadius();
    ::fnv_00d688d0::RegisterContactPointsActive();
    RegisterContactPointsInactive();
    DispatchStateHandler();
    RegisterToiCounter();
    RegisterInertiaTensors();
    ::RegisterMousePicking();
    ::RegisterPhantomsProcess();
    RegisterShapesProcess();
    FUN_00d651c0();
    ::fnv_00d64630::RegisterSweptTransformsTask();
    FUN_00d63da0();
    ::fnv_00d63400::InitWorldMemory();
    RegisterSnapshotCommands();
    RegisterWeldingViewer();
}

struct Owner
{
};
// hkpPhysicsContext: hkReferencedObject, its hkProcessContext part at +0x08 (owner at +0x0c), six listener parts
// at +0x54..+0x68, then its worlds at +0x6c.
struct PhysicsContext;
struct PhysicsContextRefObject
{
    void* m_vtbl;
    int m_memSizeAndRefCount;
};
struct PhysicsContextProcessPart
{
    void* m_vtbl;
    Owner* m_owner;
    int unk08[0x11];
    PhysicsContext* context();
};
struct PhysicsContextListener54
{
    void* m_vtbl;
};
struct PhysicsContextListener58
{
    void* m_vtbl;
};
struct PhysicsContextListener5c
{
    void* m_vtbl;
    PhysicsContext* context();
};
struct PhysicsContextListener60
{
    void* m_vtbl;
};
struct PhysicsContextListener64
{
    void* m_vtbl;
    PhysicsContext* context();
};
struct PhysicsContextListener68
{
    void* m_vtbl;
    PhysicsContext* context();
};
struct PhysicsContext : PhysicsContextRefObject, PhysicsContextProcessPart, PhysicsContextListener54,
                        PhysicsContextListener58, PhysicsContextListener5c, PhysicsContextListener60,
                        PhysicsContextListener64, PhysicsContextListener68
{
    void** m_worlds;
    int m_worldCount;
};
inline PhysicsContext* PhysicsContextProcessPart::context()
{
    return static_cast<PhysicsContext*>(this);
}
inline PhysicsContext* PhysicsContextListener5c::context()
{
    return static_cast<PhysicsContext*>(this);
}
inline PhysicsContext* PhysicsContextListener64::context()
{
    return static_cast<PhysicsContext*>(this);
}
inline PhysicsContext* PhysicsContextListener68::context()
{
    return static_cast<PhysicsContext*>(this);
}

struct FUN_00cd1f60_cls : PhysicsContextListener5c
{
    void FUN_00cd1f60(void*);
};
// @fnv 0x00cd1f60
void FUN_00cd1f60_cls::FUN_00cd1f60(void* value)
{
    Owner* owner = context()->m_owner;
    if (owner)
        reinterpret_cast<::Debugger836 *>((owner))->UntrackObject(value);
}

struct CD1FA0Target
{
};

struct CD1FA0Primary
{
    virtual void vfunc00();

    CD1FA0Target* m_target;
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
};

struct CD1FA0Listener
{
    virtual void FUN_00cd1fa0(void* value);
};

struct CD1FA0Object : CD1FA0Primary, CD1FA0Listener
{
    virtual void FUN_00cd1fa0(void* value);
};

// @fnv 0x00cd1fa0
void CD1FA0Object::FUN_00cd1fa0(void* value)
{
    if (m_target)
        reinterpret_cast<::Debugger836 *>((m_target))->UntrackObject(value);
}

namespace fnv_00cd1ff0 {
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int GetType();
};
struct Event
{
    int a, b, c;
    Obj* obj;
};
struct Owner
{
};
struct Sub : ::PhysicsContextListener64
{
    void DispatchEventToOwner(Event* e);
};

// If the event's object exists and its GetType() is not 11, forwards the event to the owner stored before this sub-object.
// @fnv 0x00cd1ff0
void Sub::DispatchEventToOwner(Event* pEvent)
{
    ::Owner* owner = context()->m_owner;
    if (owner)
    {
        Obj* o = pEvent->obj;
        if (o && o->GetType() != 11)
            reinterpret_cast<::Debugger836 *>(context()->m_owner)->UntrackObject(pEvent);
    }
}
}  // namespace fnv_00cd1ff0

namespace fnv_00cd2020 {
struct GlobalObjectO2_00d472a0
{
    int x;
};
struct FUN_00cd12b0_cls
{
};
struct Context : ::PhysicsContextListener68
{
    void FUN_00cd2020(void* value);
};
// Forwards value to the context owner's AddElementAndNotify with the Actions category and zero flags, if an owner exists.
// @fnv 0x00cd2020
void Context::FUN_00cd2020(void* value)
{
    FUN_00cd12b0_cls* target = reinterpret_cast<FUN_00cd12b0_cls*>(context()->m_owner);
    if (target)
        reinterpret_cast<::fnv_00cd1330::FUN_00cd1330_cls *>((target))->AddElementAndNotify(value, &::g_012690d4, "Actions", 0);
}
}  // namespace fnv_00cd2020

struct FUN_00cd10a0_Class
{
};
struct FUN_00cd2040_Class : ::PhysicsContextListener68
{
    void ForwardToTarget(void* value);
};
// Reads the context's owner and, if non-null, forwards value to its UntrackObject method.
// @fnv 0x00cd2040
void FUN_00cd2040_Class::ForwardToTarget(void* value)
{
    FUN_00cd10a0_Class* target = reinterpret_cast<FUN_00cd10a0_Class*>(context()->m_owner);
    if (target)
        reinterpret_cast<::Debugger836 *>((target))->UntrackObject(value);
}

struct Prefix
{
    virtual void slot();
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    unsigned int f34;
    unsigned int f38;
    unsigned int f3c;
    unsigned int f40;
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    unsigned int f54;
    int FUN_00cd2260(int value);
};
struct FUN_00cd2460_class;
struct Secondary
{
    virtual int FUN_00cd2460(int value);
};
struct FUN_00cd2460_class : Prefix, Secondary
{
};
// @fnv 0x00cd2460
int Secondary::FUN_00cd2460(int value)
{
    return reinterpret_cast<Prefix*>(reinterpret_cast<char*>(this) - sizeof(Prefix))->FUN_00cd2260(value);
}

struct PointerArray
{
    void** data;
    int count;
    int capacity;
};
struct Candidate
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
    PointerArray items;
    void FindOrAddPointer(void* value);
};
// Searches items for value and returns its index; if absent, appends value to items and returns the new slot pointer.
// @fnv 0x00cd2470
void Candidate::FindOrAddPointer(void* value)
{
    PointerArray* array = &items;
    int index = 0;
    int count = array->count;
    if (count > 0)
    {
        void** ppEntry = array->data;
        do
        {
            if (*ppEntry == value)
                goto found;
            ++index;
            ++ppEntry;
        } while (index < count);
    }
    goto append;
found:
    if (index >= 0)
        return;
append:
    hkMemoryRouter* state = &hkMemoryRouter::getInstance();
    if (array->count == (array->capacity & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(state->m_heap), (::AudioStream *)(array), sizeof(void*));
    void** slot = array->data + array->count;
    *slot = value;
    ++array->count;
}

namespace fnv_00cd27f0 {
struct FUN_00cd27f0
{
    virtual void v0() = 0;
    int unk04;
    void** buffer2;
    int unk0c;
    int count2;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    void** buffer1;
    volatile int unk30;
    int count1;
    virtual ~FUN_00cd27f0();
};
// @fnv 0x00cd27f0
FUN_00cd27f0::~FUN_00cd27f0()
{
    hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
    hkMemoryAllocator* device = holder->m_heap;
    int count = count1;
    unk30 = 0;
    if ((unsigned int)count & 0x80000000)
        goto skipFirstRelease;
    {
        unsigned int bytes = (count & 0x3fffffff) * sizeof(void*);
        device->bufFree(buffer1, bytes);
    }
skipFirstRelease:
    buffer1 = 0;
    count1 = 0x80000000;
    holder = &hkMemoryRouter::getInstance();
    device = holder->m_heap;
    int secondCount = count2;
    unk0c = 0;
    if ((unsigned int)secondCount & 0x80000000)
        goto skipSecondRelease;
    {
        unsigned int bytes = (secondCount & 0x3fffffff) * sizeof(void*);
        device->bufFree(buffer2, bytes);
    }
skipSecondRelease:
    buffer2 = 0;
    count2 = 0x80000000;
}
}  // namespace fnv_00cd27f0

namespace fnv_00cd2900 {
struct FUN_00cd2900_owner
{
    int unk00;
    unsigned short unk04;
    void FUN_00cd2690();
    void* DestroyIfFlagged(unsigned flags);
};
// Calls FUN_00cd2690, and if bit 0 of flags is set, deletes this via the manager's deleteObject interface, then returns this.
// @fnv 0x00cd2900
void* FUN_00cd2900_owner::DestroyIfFlagged(unsigned flags)
{
    FUN_00cd2690();
    if (flags & 1)
    {
        hkMemoryRouter* manager = &hkMemoryRouter::getInstance();
        manager->m_heap->blockFree(this, unk04);
    }
    return this;
}
}  // namespace fnv_00cd2900

class GlobalObjectO2_00d472a0;
class Handler
{
  public:
};
struct Receiver : PhysicsContextListener5c
{
    void DispatchEntityPayload(void* input);
};
// If the context's owner is set, forwards input, a global, "Entities" and the id input+0x10 (the entity's collidable) to it.
// @fnv 0x00cd1f30
void Receiver::DispatchEntityPayload(void* input)
{
    Handler* handler = reinterpret_cast<Handler*>(context()->m_owner);
    if (handler)
        reinterpret_cast<::fnv_00cd1330::FUN_00cd1330_cls *>((handler))->AddElementAndNotify(input, &g_012688c8, "Entities", reinterpret_cast<hkUlong>(input) + 0x10);
}

struct CD1F70Stats
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_childStats;
};


struct CD1F70Collection
{
};

class CD1F70Primary
{
  public:
    virtual void unk00();

    CD1F70Collection* m_kPhantoms;
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
};

class CD1F70Secondary
{
  public:
    virtual void CollectPhantoms(CD1F70Stats* stats);
};

class CD1F70World : public CD1F70Primary, public CD1F70Secondary
{
  public:
    virtual void CollectPhantoms(CD1F70Stats* stats);
};

// If the collection pointer is set, forwards stats to its child-stats collector under the "Phantoms" name.
// @fnv 0x00cd1f70
void CD1F70World::CollectPhantoms(CD1F70Stats* stats)
{
    if (m_kPhantoms)
        reinterpret_cast<::fnv_00cd1330::FUN_00cd1330_cls *>((m_kPhantoms))->AddElementAndNotify(stats, &::g_0126902c, "Phantoms", reinterpret_cast<hkUlong>(&stats->m_childStats));
}

struct CD1FB0Collector
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual int getType();
};

struct CD1FB0Stats
{
    int unk00;
    int unk04;
    int unk08;
    CD1FB0Collector* m_kCollector;
};


struct CD1FB0Collection
{
};

class CD1FB0Primary
{
  public:
    virtual void unk00();

    CD1FB0Collection* m_ppConstraints;
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
};

class CD1FB0Secondary
{
  public:
    virtual void CollectConstraints(CD1FB0Stats* stats);
};

class CD1FB0World : public CD1FB0Primary, public CD1FB0Secondary
{
  public:
    virtual void CollectConstraints(CD1FB0Stats* stats);
};

// @fnv 0x00cd1fb0
void CD1FB0World::CollectConstraints(CD1FB0Stats* stats)
{
    if (m_ppConstraints)
    {
        CD1FB0Collector* collector = stats->m_kCollector;
        if (collector && collector->getType() != 11)
            reinterpret_cast<::fnv_00cd1330::FUN_00cd1330_cls *>((m_ppConstraints))->AddElementAndNotify(stats, &::g_0126908c, "Constraints", 0);
    }
}

struct CD2050World
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
    void** m_kTrackedObjects;
    int m_numObjects;

    int FindObjectIndex(void* object) const;
};

// Searches the object array for the given pointer and returns its index, or -1 if not found.
// @fnv 0x00cd2050
int CD2050World::FindObjectIndex(void* object) const
{
    for (int i = 0; i < m_numObjects; i++)
    {
        if (m_kTrackedObjects[i] == object)
            return i;
    }
    return -1;
}

struct S_00cd2080_Listener
{
    virtual void unk00() throw();
    virtual void unk04() throw();
    virtual void onEvent(void* item) throw();
};

struct S_00cd2080_Quad
{
    int a, b;
};
struct S_00cd2080_Element
{
    virtual ~S_00cd2080_Element() throw();
    int unk04[59];
};

struct S_00cd2080_Lists
{
    int unk00;
    int unk04;
    void** m_08;
    int m_0c;
    int m_10;
    void** m_14;
    int m_18;
    int m_1c;
    void** m_20;
    int m_24;
    int m_28;
    void** m_2c;
    int m_30;
    int m_34;

};

struct S_00cd2080_Param
{
};

struct S_00cd2080_Class
{
    int unk00;
    int unk04;
    int unk08;
    CD1FA0Target* m_target;
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
    S_00cd2080_Listener m_listener0;
    S_00cd2080_Listener m_listener1;
    S_00cd2080_Listener m_listener2;
    S_00cd2080_Listener m_listener3;
    S_00cd2080_Param** m_params;
    int m_paramCount;
    int m_paramCapacity;
    S_00cd2080_Element* m_elements;
    int m_elementCount;
    int m_elementCapacity;

    void FUN_00cd2080(S_00cd2080_Param* param) throw();
};

// @fnv 0x00cd2080
void S_00cd2080_Class::FUN_00cd2080(S_00cd2080_Param* param) throw()
{
    if (!this->m_target)
        return;
    if (!param)
        return;

    S_00cd2080_Listener* pListener0;
    S_00cd2080_Listener* pListener1;
    S_00cd2080_Listener* pListener3;
    S_00cd2080_Listener* pListener2;
    reinterpret_cast<::hkWorldC917 *>((param))->FUN_00c917a0(pListener0 = &this->m_listener0);
    reinterpret_cast<::hkWorldC91F *>((param))->FUN_00c917f0(pListener1 = &this->m_listener1);
    reinterpret_cast<::hkWorldXc91700 *>((param))->FUN_00c91700(pListener3 = &this->m_listener3);
    reinterpret_cast<::hkWorldC9175 *>((param))->FUN_00c91750(pListener2 = &this->m_listener2);

    int idx;
    int count = this->m_paramCount;
    int i = 0;
    while (i < count)
    {
        if (this->m_params[i] == param)
        {
            idx = i;
            goto done_search;
        }
        i += 1;
    }
    idx = -1;
done_search:

    if (this->m_target && idx != -1)
    {
        reinterpret_cast<::Debugger836 *>((this->m_target))->UntrackObject(&this->m_elements[idx]);
        this->m_elements[idx].~S_00cd2080_Element();
        this->m_elementCount--;
        if (this->m_elementCount != idx)
        {
            S_00cd2080_Quad* src = (S_00cd2080_Quad*)&this->m_elements[this->m_elementCount];
            S_00cd2080_Quad* dst = (S_00cd2080_Quad*)&this->m_elements[idx];
            for (int k = 0; k < 30; k++)
                dst[k] = src[k];
        }
    }

    S_00cd2080_Lists* lists = ((::S_00cd2080_Lists *)(reinterpret_cast<::FUN_00c929e0_ThisClass *>((param))->FUN_00c929e0()));
    for (int iItem = 0; iItem < lists->m_0c; iItem++)
    {
        pListener0->onEvent(lists->m_08[iItem]);
    }
    for (int iItem = 0; iItem < lists->m_30; iItem++)
    {
        pListener1->onEvent(lists->m_2c[iItem]);
    }
    for (int iItem = 0; iItem < lists->m_24; iItem++)
    {
        pListener3->onEvent(lists->m_20[iItem]);
    }
    for (int iItem = 0; iItem < lists->m_18; iItem++)
    {
        pListener2->onEvent(lists->m_14[iItem]);
    }
    reinterpret_cast<::hkReferencedObjectC905 *>((lists))->FUN_00c905b0();
}

template <typename T> struct CD2210Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

struct CD2210Listener;

struct CD2210World
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
    CD2210Array<CD2210Listener*> m_kListeners;

    void RemoveListener(CD2210Listener* listener);
};

// Finds the listener in the array and removes it if present.
// @fnv 0x00cd2210
void CD2210World::RemoveListener(CD2210Listener* listener)
{
    int i = m_kListeners.indexOf(listener);
    if (i >= 0)
        m_kListeners.removeAt(i);
}

struct CD2260Object;

struct CD2260Interface
{
    virtual void vfunc00();
};

struct CD2260Object
{
};

struct CD2260Listener
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void objectRemovedCallback(CD2260Object* object);
};

template <typename T> struct CD2260Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

class CD2260Primary
{
  public:
    virtual void vfunc00();

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
};

class CD2260World : public CD2260Primary, public CD2260Interface
{
  public:
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    CD2260Array<CD2260Object*> m_kTrackedObjects;
    int unk78;
    int unk7C;
    int unk80;
    CD2260Array<CD2260Listener*> m_kListeners;

    void FUN_00cd2260(CD2260Object* object);
};

// If object is in the array, removes this as its owner, notifies listeners via objectRemovedCallback, calls removeInternal and removes it from the array.
// @fnv 0x00cd2260
void CD2260World::FUN_00cd2260(CD2260Object* object)
{
    int index = m_kTrackedObjects.indexOf(object);
    if (index >= 0)
    {
        reinterpret_cast<::hkWorldXc91a70 *>((object))->FUN_00c91a70(this);
        for (int i = 0; i < m_kListeners.m_iElementCount; i++)
            m_kListeners.m_data[i]->objectRemovedCallback(object);
        reinterpret_cast<::S_00cd2080_Class *>(this)->FUN_00cd2080((::S_00cd2080_Param *)(object));
        m_kTrackedObjects.removeAt(index);
    }
}

struct CD22Listener
{
    virtual void vfunc00();
    virtual void Notify(void* item);
};

struct CD22Elem
{
};

struct CD22Array
{
    CD22Elem* data;
    int count;
    unsigned int cap;
};

struct CD22Table
{
    int unk00;
    int unk04;
    void** items08;
    int count0C;
    int unk10;
    void** items14;
    int count18;
    int unk1C;
    void** items20;
    int count24;
    int unk28;
    void** items2C;
    int count30;
};

struct CD22Registry
{
};

struct CD22Owner
{
};


struct CD22Object
{
    int unk00;
    int unk04;
    int unk08;
    CD22Owner* m_0c;
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
    CD22Listener m_5c;
    CD22Listener m_60;
    CD22Listener m_64;
    CD22Listener m_68;
    int unk6C;
    int unk70;
    int unk74;
    CD22Array m_78;
    void RegisterWithRegistry(CD22Registry* reg);
};


// @fnv 0x00cd22f0
void CD22Object::RegisterWithRegistry(CD22Registry* reg)
{
    if (m_0c == 0)
        return;
    if (reg == 0)
        return;

    reinterpret_cast<::FUN_00c91180_Class *>((reg))->IncrementCounter();
    reinterpret_cast<::fnv_00c93820::hkpWorldC938 *>((reg))->FUN_00c93820((::fnv_00c93820::hkpEntityListenerC938 *)(void *)(&m_5c));
    reinterpret_cast<::fnv_00c93860::hkpWorldXc93860 *>((reg))->FUN_00c93860((::fnv_00c93860::hkpEntityListenerXc93860 *)(void *)(&m_60));
    reinterpret_cast<::hkOwnerXc937a0 *>((reg))->FUN_00c937a0(&m_68);
    reinterpret_cast<::fnv_00c937e0::hkpWorldXc937e0 *>((reg))->FUN_00c937e0((::fnv_00c937e0::hkpEntityListenerXc937e0 *)(void *)(&m_64));

    CD22Array* pArray = &m_78;
    hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
    if (pArray->count == (int)(pArray->cap & 0x3fffffff))
    {
        ::ResizeAudioStream((::AudioAllocator *)(holder->m_heap), (::AudioStream *)(pArray), 0xf0);
    }

    CD22Elem* pNewElem = (CD22Elem*)((char*)pArray->data + pArray->count * 0xf0);
    if (pNewElem != 0)
    {
        new ((void *)(pNewElem)) ::FUN_00c90b80();
    }

    CD22Elem* e = (CD22Elem*)((char*)pArray->data + pArray->count * 0xf0);
    pArray->count++;
    reinterpret_cast<::Src_00c91c50 *>((reg))->FUN_00c91c50((::Dst_00c91c50 *)(e));

    if (m_0c != 0)
    {
        reinterpret_cast<::fnv_00cd1330::FUN_00cd1330_cls *>((m_0c))->AddElementAndNotify(e, &::g_01269104, ::g_01269104_arg0, 0);
    }

    CD22Table* tbl = ((::CD22Table *)(reinterpret_cast<::FUN_00c929e0_ThisClass *>((reg))->FUN_00c929e0()));
    for (int i = 0; i < tbl->count0C; ++i)
    {
        ((CD22Listener*)&m_5c)->Notify(tbl->items08[i]);
    }
    for (int i = 0; i < tbl->count30; ++i)
    {
        ((CD22Listener*)&m_60)->Notify(tbl->items2C[i]);
    }
    for (int i = 0; i < tbl->count24; ++i)
    {
        ((CD22Listener*)&m_68)->Notify(tbl->items20[i]);
    }
    for (int i = 0; i < tbl->count18; ++i)
    {
        ((CD22Listener*)&m_64)->Notify(tbl->items14[i]);
    }
    reinterpret_cast<::hkReferencedObjectC905 *>((tbl))->FUN_00c905b0();
    reinterpret_cast<::FUN_00c91190_Class *>((reg))->FUN_00c91190();
}

struct SpawnedCallee
{
};

struct FUN_00cd24d0_cls : PhysicsContextProcessPart
{
    void FUN_00cd24d0(Owner* value);
};

// hkProcessContext::setOwner: if an owner was set, calls FUN_00cd2080 on each world, stores the owner, then calls RegisterWithRegistry on each world when the owner is non-null.
// @fnv 0x00cd24d0
void FUN_00cd24d0_cls::FUN_00cd24d0(Owner* value)
{
    PhysicsContext* ctx = context();
    if (m_owner != 0)
    {
        for (int i = 0; i < ctx->m_worldCount; ++i)
        {
            reinterpret_cast<::S_00cd2080_Class *>(ctx)->FUN_00cd2080((::S_00cd2080_Param *)(ctx->m_worlds[i]));
        }
    }

    m_owner = value;

    if (value != 0)
    {
        for (int i = 0; i < ctx->m_worldCount; ++i)
        {
            reinterpret_cast<::CD22Object *>(ctx)->RegisterWithRegistry((::CD22Registry *)(ctx->m_worlds[i]));
        }
    }
}

struct FUN_00c93a60_cls
{
};

struct Sink
{
    virtual void vfunc00();
    virtual void vfunc04(void* value);
};

struct FUN_00cd2530_cls
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
    PointerArray m_items;
    int unk78;
    int unk7C;
    int unk80;
    Sink** m_sinks;
    int m_sinkCount;

    void AddItem(void* value);
};

// If value is not already in m_items, appends it, notifies each sink via vfunc04 and calls RegisterWithRegistry.
// @fnv 0x00cd2530
void FUN_00cd2530_cls::AddItem(void* pItem)
{
    PointerArray* items = &m_items;
    int count = items->count;
    int idx = 0;
    if (count > 0)
    {
        void** p = items->data;
        do
        {
            if (*p == pItem)
            {
                goto found;
            }
            ++p;
            ++idx;
        } while (idx < count);
    }
    goto notFound;

found:
    if (idx >= 0)
    {
        return;
    }

notFound:
    FUN_00c93a60_cls* obj = (FUN_00c93a60_cls*)pItem;
    FUN_00cd2530_cls* self = this;
    void* param = self != 0 ? (char*)&self->unk58 : 0;
    reinterpret_cast<::hkpWorld_Listener *>((obj))->FUN_00c93a60(param);

    hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
    if (items->count == (items->capacity & 0x3fffffff))
    {
        ::ResizeAudioStream((::AudioAllocator *)(holder->m_heap), (::AudioStream *)(items), sizeof(void*));
    }
    int n = *(int volatile*)&items->count;
    void** volatile* ppData = &items->data;
    void** slot = (*ppData) + n;
    *slot = pItem;
    items->count++;

    for (int i = 0; i < m_sinkCount; ++i)
    {
        m_sinks[i]->vfunc04(pItem);
    }

    reinterpret_cast<::CD22Object *>(this)->RegisterWithRegistry((::CD22Registry *)(pItem));
}

struct FUN_00cd2870_cls
{
    int unk00;
    int unk04;


    FUN_00cd2870_cls* FUN_00cd2870(unsigned int aFlags);
};

// @fnv 0x00cd2870
FUN_00cd2870_cls* FUN_00cd2870_cls::FUN_00cd2870(unsigned int aFlags)
{
    reinterpret_cast<::fnv_00cd27f0::FUN_00cd27f0 *>(this)->fnv_00cd27f0::FUN_00cd27f0::~FUN_00cd27f0();
    if (aFlags & 1)
    {
        ::FUN_00401030(this);
    }
    return this;
}

struct CD2890Class
{
    const char* m_name;
};


struct CD2890World
{
    virtual const CD2890Class* FUN_00cd2890() const;
};

// @fnv 0x00cd2890
const CD2890Class* CD2890World::FUN_00cd2890() const
{
    return &(*reinterpret_cast<const ::CD2890Class *>(&::fnv_00e0f800::DAT_010cb2c0));
}

struct hkBaseObject
{
    virtual void destroy();
    virtual void b04();
    virtual void b08();
};

struct hkReferencedObject : hkBaseObject
{
    unsigned short memSizeAndFlags;
    short refCount;

    hkReferencedObject()
    {
        refCount = 1;
    }
    virtual void r04();
    virtual void r08();
};

struct InplaceArray6
{
    void* data;
    int size;
    unsigned int capacityAndFlags;
    void* buffer0;
    void* buffer1;
    void* buffer2;
    void* buffer3;
    void* buffer4;
    void* buffer5;

    InplaceArray6()
    {
        size = 0;
        data = &buffer0;
        capacityAndFlags = 0x80000006u;
    }
};

struct EmptyArray
{
    void* data;
    int size;
    unsigned int capacityAndFlags;

    EmptyArray()
    {
        data = 0;
        size = 0;
        capacityAndFlags = 0x80000000u;
    }
};

struct hkProcessContext : hkBaseObject
{
    int m_04;
    InplaceArray6 m_08;
    InplaceArray6 m_2c;

    hkProcessContext() : m_04(0)
    {}
    virtual void p04();
    virtual void p08();
};

struct hkpWorldDeletionListener : hkBaseObject
{
    virtual void destroy();
    virtual void w04();
    virtual void w08();
};

struct hkpEntityListener : hkBaseObject
{
    virtual void destroy();
    virtual void e04();
    virtual void e08();
    virtual void e0c();
    virtual void e10();
    virtual void e14();
};

struct hkpPhantomListener : hkBaseObject
{
    virtual void destroy();
    virtual void p04();
    virtual void p08();
    virtual void p0c();
    virtual void p10();
};

struct hkpConstraintListener : hkBaseObject
{
    virtual void destroy();
    virtual void c04();
    virtual void c08();
    virtual void c0c();
    virtual void c10();
    virtual void c14();
    virtual void c18();
};

struct hkpActionListener : hkBaseObject
{
    virtual void destroy();
    virtual void a04();
    virtual void a08();
};

struct FUN_00cd25d0 : hkReferencedObject,
                      hkProcessContext,
                      hkpWorldDeletionListener,
                      hkpEntityListener,
                      hkpPhantomListener,
                      hkpConstraintListener,
                      hkpActionListener
{
    EmptyArray m_6c;
    EmptyArray m_78;
    EmptyArray m_84;

    FUN_00cd25d0();
    virtual void d04();
    virtual void d08();
};

// Constructs the object; the base classes and member arrays are initialized by their own constructors.
// @fnv 0x00cd25d0
FUN_00cd25d0::FUN_00cd25d0()
{}

class hkMemoryAllocatorD269
{
  public:
    virtual ~hkMemoryAllocatorD269() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void unk0C() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

inline hkMemoryAllocatorD269& heapD269(hkMemoryRouter* pkState)
{
    return *(hkMemoryAllocatorD269*)pkState->m_heap;
}

template <class T> class hkArrayD269
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }

    static __forceinline void destruct(T* t, int n)
    {
        for (int i = 0; i < n; i++)
            t[i].~T();
    }

    __forceinline void _clearAndDeallocate(hkMemoryAllocatorD269& alloc)
    {
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    __forceinline ~hkArrayD269() throw()
    {
        _clearAndDeallocate(heapD269(&hkMemoryRouter::getInstance()));
    }
};

class hkReferencedObjectD269
{
  public:
    virtual ~hkReferencedObjectD269() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class BaseD269_08
{
  public:
    virtual ~BaseD269_08() throw();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    int unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
};

class ListenerD269_58
{
  public:
    virtual ~ListenerD269_58() throw()
    {}
};
class ListenerD269_5C
{
  public:
    virtual ~ListenerD269_5C() throw()
    {}
};
class ListenerD269_60
{
  public:
    virtual ~ListenerD269_60() throw()
    {}
};
class ListenerD269_64
{
  public:
    virtual ~ListenerD269_64() throw()
    {}
};
class ListenerD269_68
{
  public:
    virtual ~ListenerD269_68() throw()
    {}
};

class ElementD269
{
  public:
    virtual ~ElementD269() throw();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
};

class FUN_00cd2690 : public hkReferencedObjectD269,
                     public BaseD269_08,
                     public ListenerD269_58,
                     public ListenerD269_5C,
                     public ListenerD269_60,
                     public ListenerD269_64,
                     public ListenerD269_68
{
  public:
    virtual ~FUN_00cd2690() throw();


    hkArrayD269<void*> m_kTrackedObjects;
    hkArrayD269<ElementD269> m_elements;
    hkArrayD269<void*> m_kListeners;
};

// Destructor that iterates m_kTrackedObjects in reverse and calls FUN_00cd2260 on each element.
// @fnv 0x00cd2690
FUN_00cd2690::~FUN_00cd2690() throw()
{
    for (int i = m_kTrackedObjects.GetLogicalSize() - 1; i >= 0; i--)
        reinterpret_cast<::CD2260World *>(this)->FUN_00cd2260((::CD2260Object *)(m_kTrackedObjects[i]));
}

struct Block8CD2A
{
    int a, b;
};
inline void memMoveCD2A(void* pvDst, const void* pvSrc, int iNumBytes)
{
    const Block8CD2A* s = (const Block8CD2A*)pvSrc;
    Block8CD2A* d = (Block8CD2A*)pvDst;
    int k = 0;
    for (int i = 0; i < iNumBytes; i += 8)
    {
        d[k] = s[k];
        k++;
    }
}

template <typename T> struct hkArrayCD2A
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
    void removeAtAndCopy(int iIndex)
    {
        m_iElementCount--;
        memMoveCD2A(m_data + iIndex, m_data + iIndex + 1, (m_iElementCount - iIndex) * sizeof(T));
    }
};

struct ValueCD2A
{
    int m_kPointA;
    int m_kPointB;
    ValueCD2A() : m_kPointA(0), m_kPointB(0)
    {}
};

struct EntryCD2A
{
    int m_key;
    int m_unk04;
    ValueCD2A m_uiFilterValue;
};

class OwnerCD2A
{
  public:
    int unk00[0x78 / 4];
    hkArrayCD2A<EntryCD2A> m_entries;

    ValueCD2A FUN_00cd2a50(int iKey);
};

// @fnv 0x00cd2a50
ValueCD2A OwnerCD2A::FUN_00cd2a50(int iKey)
{
    for (int i = 0; i < m_entries.GetLogicalSize(); i++)
    {
        if (m_entries[i].m_key == iKey)
        {
            EntryCD2A kEntry = m_entries[i];
            m_entries.removeAtAndCopy(i);
            return kEntry.m_uiFilterValue;
        }
    }
    return ValueCD2A();
}

struct FUN_00cd1e70
{
    virtual ~FUN_00cd1e70();
};

// @fnv 0x00cd1e70
FUN_00cd1e70::~FUN_00cd1e70()
{}

struct FUN_00cd1e90_cls
{
    int unk04;
    virtual ~FUN_00cd1e90_cls();
};

// @fnv 0x00cd1e90
FUN_00cd1e90_cls::~FUN_00cd1e90_cls()
{}

// sub ecx,0x58; jmp target == MSVC adjustor thunk (second base's vtable slot, this moved back by sizeof(PrimaryBase)=0x58).
struct PrimaryBase
{
    virtual void FUN_00cd28a0();
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
};

struct SecondaryBase
{
    virtual void FUN_00cd28a0();
};

struct ThunkOwner : PrimaryBase, SecondaryBase
{
    ThunkOwner();
// @fnv 0x00cd28a0
    virtual void FUN_00cd28a0();
};

ThunkOwner::ThunkOwner()
{}

// FUN_00cd28b0: MSVC this-adjusting thunk.
//
// The original is 8 bytes:  sub ecx, 0x5c ; jmp 0x00cd2900
// That is the adjustor thunk MSVC emits for a virtual function that a
// derived class overrides for a SECONDARY base: calling through the
// secondary base's vftable passes the base subobject's `this`, so the
// thunk walks it back to the derived object and tail-jumps to the shared
// override.
//
// To make the compiler produce exactly that symbol we need
//   * two bases that both declare the same virtual (so the derived class
//     overrides one function for both of them -> one adjustor per base),
//   * the second base placed at offset 0x5c (the first base is padded to
//     0x5c bytes),
//   * the override DECLARED ONLY, so that the thunk is the single defined
//     function symbol carrying the name FUN_00cd28b0,
//   * a defined key function in the derived class, so that its vftable
//     (which references the thunk) is emitted in this translation unit.
struct AdjBase1
{
    AdjBase1();
    virtual void FUN_00cd28b0();
    char pad[0x58];  // vptr + 0x58 -> size 0x5c, so AdjBase2 lands at +0x5c
};

struct AdjBase2
{
    AdjBase2();
// @fnv 0x00cd28b0
    virtual void FUN_00cd28b0();
};

struct AdjOwner : AdjBase1, AdjBase2
{
    AdjOwner();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void FUN_00cd28b0();    // the shared override - declared only
};

AdjOwner::AdjOwner()
{}
void AdjOwner::key_fn()
{}

AdjOwner* make_adj_owner()
{
    static AdjOwner o;
    return &o;
}

namespace fnv_00cd28c0 {
// sub ecx,0x60; jmp DestroyIfFlagged == MSVC adjustor thunk (second base's vtable slot, this moved back by sizeof(PrimaryBase)=0x60).
struct PrimaryBase
{
    virtual void FUN_00cd28c0();
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
};

struct SecondaryBase
{
    virtual void FUN_00cd28c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cd28c0
    virtual void FUN_00cd28c0();
};

Derived::Derived()
{}
}  // namespace fnv_00cd28c0

namespace fnv_00cd28d0 {
// sub ecx,0x64; jmp target: MSVC adjustor thunk. PrimaryBase is 0x64 bytes (vptr + 24 ints),
// so the second base sits at +0x64 and the thunk subtracts 0x64 from this.
struct PrimaryBase
{
    virtual void FUN_00cd28d0();
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
};

struct SecondaryBase
{
    virtual void FUN_00cd28d0();
};

struct SpawnedObject : PrimaryBase, SecondaryBase
{
    SpawnedObject();
// @fnv 0x00cd28d0
    virtual void FUN_00cd28d0();
};

SpawnedObject::SpawnedObject()
{}
}  // namespace fnv_00cd28d0

struct CD28E0Primary
{
    virtual void vfunc00();
    virtual void FUN_00cd28e0();

    int unk04;
};

struct CD28E0Secondary
{
    virtual void FUN_00cd28e0();
};

struct CD28E0Object : CD28E0Primary, CD28E0Secondary
{
    CD28E0Object();

// @fnv 0x00cd28e0
    virtual void FUN_00cd28e0();
};

CD28E0Object::CD28E0Object()
{}

// sub ecx,0x68; jmp target == MSVC adjustor thunk for a secondary base slot.
struct CD28F0Primary
{
    virtual void FUN_00cd28f0();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
};

struct CD28F0Secondary
{
    virtual void FUN_00cd28f0();
};

struct CD28F0Derived : CD28F0Primary, CD28F0Secondary
{
    CD28F0Derived();
// @fnv 0x00cd28f0
    virtual void FUN_00cd28f0();
};

CD28F0Derived::CD28F0Derived()
{}

struct FUN_00cd1eb0_StandIn
{
    void* unk00;
    void* FUN_00cd1eb0(int param);
};


// @fnv 0x00cd1eb0
void* FUN_00cd1eb0_StandIn::FUN_00cd1eb0(int aiFlags)
{
    unk00 = fnv_vftable_DFFA90ListenerE;
    if (aiFlags & 1)
    {
        FUN_00401030(this);
    }
    return this;
}
