
// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "fnv/symbols_00df2000.h"
#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <intrin.h>
#include <windows.h>
#include <new>
#include "fnv/decl/CB1A90Owner.h"
#include "fnv/decl/Dispatcher.h"
#include "fnv/decl/FUN_00c9bff0_Class.h"
#include "fnv/decl/FUN_00cb1a60_t.h"
#include "fnv/decl/FUN_00cb1fe0_t.h"
#include "fnv/decl/FUN_00d04350_cls.h"
#include "fnv/decl/FUN_00d04370_cls.h"
#include "fnv/decl/FUN_00d976d0_cls.h"
#include "fnv/decl/FUN_00d97970_cls.h"
#include "fnv/decl/FUN_00d9a4d0_Class.h"
#include "fnv/decl/FUN_00d9bed0_cls.h"
#include "fnv/decl/FUN_00d9c180.h"
#include "fnv/decl/FUN_00d9c7d0_C.h"
#include "fnv/decl/FnvCpu_FUN_00cd2a00_CpuObject.h"
#include "fnv/decl/ListWalker.h"
#include "fnv/decl/ObjectTable.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/SearchArray.h"
#include "fnv/decl/Tree_d978.h"
#include "fnv/decl/fnv_00c93820__hkpWorldC938.h"
#include "fnv/decl/fnv_00c93860__hkpWorldXc93860.h"
#include "fnv/decl/fnv_00c938a0__hkpWorldXc938a0.h"
#include "fnv/decl/fnv_00c93920__hkpWorldXc93920.h"
#include "fnv/decl/fnv_00cb1870__hkMapBaseCB18.h"
#include "fnv/decl/fnv_00d04b50__Owner.h"
#include "fnv/decl/fnv_00d97850__FUN_00d97850_cls.h"
#include "fnv/decl/hkWorldC917.h"
#include "fnv/decl/hkWorldC91F.h"
#include "fnv/decl/linear_cast_d9a2a0__PathBuilder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00d04000.h"
#include "fnv/symbols_00d08000.h"
#include "fnv/symbols_00d9d000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_0102f000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_01076000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010cc000.h"
#include "fnv/symbols_01268000.h"
struct FUN_00d08330 {
    void* m_p;
    FUN_00d08330(char);
};

// @fnv 0x00d08330
FUN_00d08330::FUN_00d08330(char acFlags)
{
    m_p = &DAT_010ccf7c;
    if (acFlags & 1)
        ::FUN_00401030(this);
}


struct FUN_00d08350 {
    void* m_p;
    void* Set(void* arg);
};

// Stores the address of DAT_010ccf8c into m_p and, if arg's low bit is set, deallocates self before returning it.
// @fnv 0x00d08350
void* FUN_00d08350::Set(void* arg)
{
    void* self = this;
    m_p = &DAT_010ccf8c;
    if (reinterpret_cast<uintptr_t>(arg) & 1)
        ::FUN_00401030(self);
    return self;
}

// hkpAabbTreeWorldManager fields read by the small setters below.
struct AabbTreeWorldManagerFields {
    char pad00[0x2c];
    char m_flag2c;           // +0x2c
    char pad2d[0x3];
    int m_value30;           // +0x30
    int m_value34;           // +0x34
    int m_shift38;           // +0x38
    char pad3c[0xc];
    int m_count48;           // +0x48
    char pad4c[0x4];
    unsigned char m_entries50[0x19];  // +0x50, a HashEntryTable
    char m_flag69;           // +0x69
};
// The hkpWorldObject and hkpCollidable fields the listeners read.
struct D08Collidable {
    char pad00[0x18];
    signed char m_broadPhaseType;  // +0x18, m_broadPhaseHandle.m_type
};
struct D08WorldObject {
    char pad00[0x10];
    D08Collidable m_collidable;    // +0x10
};
// Finds the object whose listener interface is the member at `offset`.
template <class Owner>
static __forceinline Owner* ownerOfListener(void* listener, size_t offset)
{
    return reinterpret_cast<Owner*>(static_cast<char*>(listener) - offset);
}
// Positions of the manager's listener interfaces inside the manager objects.
const size_t kPhantomListenerOffset = 0x14;
const size_t kEntityListListenerOffset = 0x18;
const size_t kFlaggedListenerOffset = 0x1c;
const size_t kEntityListenerOffset = 0x20;
struct FUN_00d083a0_class : AabbTreeWorldManagerFields {
    void FUN_00d083a0(int a);
};

// @fnv 0x00d083a0
void FUN_00d083a0_class::FUN_00d083a0(int aiValue)
{
    m_value30 = aiValue;
    m_value34 = (m_shift38 << 4) + aiValue;
}

struct FUN_00d08ff0_t {
    int a;
    int b;
    int c;
    int d;
};

struct FUN_00d0a150 {
    int* p;
    FUN_00d0a150(bool b);
};
// @fnv 0x00d0a150
FUN_00d0a150::FUN_00d0a150(bool abFree)
{
    p = &DAT_010ccfac;
    if (abFree & 1) ::FUN_00401030(this);
}


struct FUN_00d0a1a0 {
    int* a;
    int* b;
    FUN_00d0a1a0* Init(int p);
};

// Sets a and b to the addresses of two globals, frees this if p has bit 0 set, and returns this.
// @fnv 0x00d0a1a0
FUN_00d0a1a0* FUN_00d0a1a0::Init(int aiFlags)
{
    b = &DAT_010ccfac;
    a = &DAT_010ccfa0;
    if (aiFlags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00d08390
int FUN_00d08390(void* self, int, intptr_t value)
{
    static_cast<AabbTreeWorldManagerFields*>(self)->m_shift38 = (int)value;
    return (int)(value << 5);
}

struct HashEntryTable {  public:
    void clear();
};
struct FUN_00d08550_Class : AabbTreeWorldManagerFields {
    void FUN_00d08550();
};
// @fnv 0x00d08550
void FUN_00d08550_Class::FUN_00d08550()
{
    m_flag69 = 0;
    reinterpret_cast<::FUN_00cb1a60_t *>(&m_entries50)->ResetEntries();
}

struct FUN_00d08560_class : AabbTreeWorldManagerFields {
    void FUN_00d08560();
};
// @fnv 0x00d08560
void FUN_00d08560_class::FUN_00d08560()
{
    m_count48 = 0;
    m_flag2c = 0;
    m_flag69 = 0;
}

struct FUN_00d08940_class {
};

struct FUN_00d08a40_class {
    char pad0[8];
    char m_flag8;
    char pad9[0x43];
    char m_4c;
    char m_4d;
    void ProcessFlaggedEntries(void* arg);
};

struct FUN_00cd2a00_class {
};

// @fnv 0x00d083e0
void FUN_00d083e0(void* arg)
{
    FUN_00cd2a00_class* p = reinterpret_cast<FUN_00cd2a00_class*>(
        reinterpret_cast<char*>(arg) + reinterpret_cast<signed char*>(arg)[0x10]);
    reinterpret_cast<::FnvCpu_FUN_00cd2a00_CpuObject *>((p))->FUN_00cd2a00();
}

struct FUN_00d08a90_class {
    char pad0[4];
    char m_enabled4;
    char pad5[0x43];
    char m_flag48;
    char m_flag49;
    void FUN_00d08a90(void* arg);
};
struct FUN_00d08fb0_Class {
    char pad[0x54];
    char m_54;
    char m_55;
    void FUN_00d08fb0(char* arg);
    void FUN_00d08c90(char* arg);
};
void __cdecl FUN_00d08c90(void* self, int a);
struct FUN_00d08fd0_class {
    char pad[0x50];
    char m_50;
    char m_51;
    void FUN_00d08fd0(void* a);
    void FUN_00d08c90(int a);
};
struct FUN_00d0a130 {
    void* p;
    void* Set(char b);
};
// @fnv 0x00d0a130
void* FUN_00d0a130::Set(char abFree)
{
    p = &DAT_010ccfa0;
    if (abFree & 1)
        ::FUN_00401030(this);
    return this;
}

// add ecx,-0x14; jmp FUN_00d08570 : override in Derived forwards to the primary base's virtual.
struct PrimaryBase
{
    virtual void FUN_00d08570();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00d089c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
    virtual void FUN_00d089c0();
};

Derived::Derived()
{
}

namespace fnv_00d089d0 {
// add ecx,-0x14; jmp FUN_00d08570 : Derived's override forwards to the primary base's virtual.
struct PrimaryBase
{
    virtual void FUN_00d08570();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00d089d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
    virtual void FUN_00d089d0();
};

Derived::Derived()
{
}

// @fnv 0x00d089d0
void Derived::FUN_00d089d0()
{
    this->PrimaryBase::FUN_00d08570();
}
}  // namespace fnv_00d089d0

namespace fnv_00d089e0 {
struct Base {
    void FUN_00d08570();
};

struct Derived {
    void FUN_00d089e0();
};

// @fnv 0x00d089e0
void Derived::FUN_00d089e0()
{
    ownerOfListener<Base>(this, kEntityListListenerOffset)->FUN_00d08570();
}
}  // namespace fnv_00d089e0

struct FUN_00d0a1f0_Class {
    unsigned char unk00[0x68];
    unsigned char m_68;
    void FUN_00d0a1f0(unsigned char value);
};

// @fnv 0x00d0a1f0
void FUN_00d0a1f0_Class::FUN_00d0a1f0(unsigned char value) {
    m_68 = value;
}

// Empty function that takes an int argument and does nothing.
// @fnv 0x00d08380
void FUN_00d08380(int) {
}

struct FUN_00cd29f0_cls {
public:
    void FUN_00cd29f0(unsigned int);
};

struct FUN_00d08400_cls {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    signed char m_targetOffset;
};

// @fnv 0x00d08400
void __cdecl DispatchToOffsetTarget(FUN_00d08400_cls* pkObject, unsigned short usValue)
{
    reinterpret_cast<FUN_00cd29f0_cls*>(reinterpret_cast<char*>(pkObject) + pkObject->m_targetOffset)->FUN_00cd29f0(usValue);
}

struct __declspec(align(16)) hkVector4D084 {
    float x, y, z, w;
};

struct hkpWorldRayCastInputD084 {
    hkVector4D084 m_vFrom;
    hkVector4D084 m_vTo;
    bool m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
};

struct hkpShapeRayCastOutputD084 {
    hkVector4D084 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_pad18;
    int m_pad1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    hkpShapeRayCastOutputD084()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = 0xffffffff;
        m_uiShapeKeyIndex = 0;
    }
};

struct hkpWorldRayCastOutputD084 : public hkpShapeRayCastOutputD084 {
    const void* m_pRootCollidable;

    hkpWorldRayCastOutputD084() { m_pRootCollidable = 0; }
};

struct hkpRayHitCollectorD084;

class hkpRayShapeCollectionFilterD084 {
public:
    virtual ~hkpRayShapeCollectionFilterD084() throw();
};

class hkpRayCollidableFilterD084 {
public:
    virtual ~hkpRayCollidableFilterD084() throw();
};

class hkpCollidableCollidableFilterD084 {
public:
    virtual ~hkpCollidableCollidableFilterD084() throw();
};

class hkpShapeCollectionFilterD084 {
public:
    virtual ~hkpShapeCollectionFilterD084() throw();
};

class hkReferencedObjectD084 {
public:
    virtual ~hkReferencedObjectD084() throw();
    int m_usMemSizeAndFlags;
};

class hkpCollisionFilterD084 : public hkReferencedObjectD084, public hkpCollidableCollidableFilterD084, public hkpShapeCollectionFilterD084, public hkpRayShapeCollectionFilterD084, public hkpRayCollidableFilterD084 {
};

class hkpRayCastCollectorBaseD084 {
public:
    virtual void CollectRayHit() throw();
};

class hkpTreeCastCallbackD084 {
public:
    virtual float processLeaf() throw();
};

class FUN_00d9a040 : public hkpRayCastCollectorBaseD084, public hkpTreeCastCallbackD084 {
public:
    const hkpWorldRayCastInputD084* m_pRayCastInput;
    const hkpRayCollidableFilterD084* m_iFilter;
    const hkpRayShapeCollectionFilterD084* m_shapeFilter;
    hkpWorldRayCastOutputD084* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
    int m_1c;

    FUN_00d9a040() throw();
};

class hkpBroadPhaseCastCollectorD084 {
public:
    virtual void ReleaseCollector() throw();
};

class hkpWorldRayCasterD084 : public hkpBroadPhaseCastCollectorD084 {
public:
    const hkpWorldRayCastInputD084* m_pRayCastInput;
    const hkpRayCollidableFilterD084* m_iFilter;
    const hkpRayShapeCollectionFilterD084* m_shapeFilter;
    hkpWorldRayCastOutputD084* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
};

struct hkBoolD084 {
    char m_cBooleanValue;
    hkBoolD084(bool b) { m_cBooleanValue = (char)b; }
};

hkBoolD084 __cdecl FUN_00d98ca0(void* pkBroadPhase, const hkVector4D084& kFrom, const hkVector4D084& kTo, hkpWorldRayCasterD084* pkCaster) throw();
void __cdecl FUN_00d1bd00(void* pkTree, const hkVector4D084& kFrom, const hkVector4D084& kTo, hkpTreeCastCallbackD084* pkCaster, float fEarlyOut) throw();

class hkpRayCastQueryD084 {
public:
    int m_00;
    int m_04;
    int m_08;
    void* m_iValueAt40;
    void* m_pJobSemaphore;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    bool m_useTree;

    void CastRay(const hkpWorldRayCastInputD084& kInput, const hkpCollisionFilterD084* pkFilter, hkpRayHitCollectorD084* pkCollector) const throw();
};

// @fnv 0x00d08420
void hkpRayCastQueryD084::CastRay(const hkpWorldRayCastInputD084& kInput, const hkpCollisionFilterD084* pkFilter, hkpRayHitCollectorD084* pkCollector) const throw()
{
    FUN_00d9a040 kTreeCaster;
    kTreeCaster.m_pRayCastInput = &kInput;
    kTreeCaster.m_kCollector = pkCollector;
    kTreeCaster.m_iFilter = pkFilter;
    kTreeCaster.m_shapeFilter = pkFilter;
    hkpWorldRayCastOutputD084 kTreeOutput;
    kTreeCaster.m_pRayCastOutput = &kTreeOutput;

    if (m_pJobSemaphore) {
        hkpWorldRayCasterD084 kCaster;
        kCaster.m_pRayCastInput = &kInput;
        kCaster.m_kCollector = pkCollector;
        kCaster.m_iFilter = pkFilter;
        kCaster.m_shapeFilter = pkFilter;
        hkpWorldRayCastOutputD084 kOutput;
        kCaster.m_pRayCastOutput = &kOutput;
        FUN_00d98ca0(m_pJobSemaphore, kInput.m_vFrom, kInput.m_vTo, &kCaster);
    }
    if (m_useTree)
        FUN_00d1bd00(m_iValueAt40, kInput.m_vFrom, kInput.m_vTo, &kTreeCaster, 1.0f);
}

template <class T>
class hkArrayD085 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i) {
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

class hkBroadPhaseD085 {
public:
};

struct hkCollidableD085 {
    int unk00;
};

struct hkEntityD085 {
    int unk00[4];
    hkCollidableD085 m_kCollidable;
};

class hkHandlerD085 {
public:
    int unk00[3];
    hkBroadPhaseD085* m_pJobSemaphore;
    int unk10[5];
    bool m_enabled;
    char unk25[0x1f];
    hkArrayD085<hkCollidableD085*> m_kCollidables;

    unsigned short FUN_00d083e0(hkCollidableD085* c);
    void FUN_00d08570(hkEntityD085* entity);
};
// @fnv 0x00d089c0
void Derived::FUN_00d089c0()
{
    reinterpret_cast<::hkHandlerD085 *>((this))->FUN_00d08570({});
}

// @fnv 0x00d08570
void hkHandlerD085::FUN_00d08570(hkEntityD085* entity)
{
    hkCollidableD085* c = &entity->m_kCollidable;
    if (m_enabled) {
        unsigned short id = FUN_00d083e0(c);
        int i = m_kCollidables.indexOf(c);
        if (i == -1) {
            if (id != 0xffff)
                reinterpret_cast<::FUN_00d9c7d0_C *>((m_pJobSemaphore))->FUN_00d9c7d0((::NodeD9C7 *)(uintptr_t)(id));
        } else {
            m_kCollidables.removeAt(i);
        }
    }
}

struct PlaceTagD088 {};
inline void* operator new(size_t, void* p, PlaceTagD088) throw() { __assume(p != 0); return p; }
inline void operator delete(void*, void*, PlaceTagD088) throw() {}

template <class T>
struct hkArrayD088 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void pushBackUnchecked(const T& e)
    {
        new (&m_data[m_iElementCount], PlaceTagD088()) T(e);
        m_iElementCount++;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

struct hkBoolRetD088 {
    char m_cBooleanValue;
    hkBoolRetD088() throw() {}
};

class hkpEntityD088 {
public:
public:
    hkBoolRetD088 FUN_00c9bff0() const throw();
};

struct hkpCollidableD088 {
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    signed char m_iOwnerOffset;
    char m_pad11[3];
    unsigned int m_iOwnerObjectOffset;
    char m_type;

    hkpEntityD088* getOwner() const { return (hkpEntityD088*)((char*)this + m_iOwnerOffset); }
};

class hkpEntityListD088 {
public:
    char m_pad00[0x44];
    hkArrayD088<hkpCollidableD088*> m_kCollidables;
    char m_pad50[0xc];
    bool m_checkAll;
    char m_pad5d[3];
    int m_currentIndex;
    int m_maxChecksPerCall;

    __forceinline void checkCollidable(int i, hkArrayD088<hkpCollidableD088*>& kInactive)
    {
        hkpCollidableD088* pkCollidable = m_kCollidables.m_data[i];
        if (pkCollidable->m_type == 1) {
            hkpEntityD088* pkEntity = pkCollidable->getOwner();
            if (pkEntity && !(*(::hkBoolRetD088 *)(reinterpret_cast<::FUN_00c9bff0_Class *>((void *)(pkEntity))->FUN_00c9bff0({}))).m_cBooleanValue) {
                kInactive.pushBackUnchecked(m_kCollidables.m_data[i]);
                m_kCollidables.removeAt(i);
            }
        }
    }

    bool CheckCollidables(hkArrayD088<hkpCollidableD088*>& kInactive) throw();
};

// Moves inactive collidables from the list into kInactive, checking all entries when m_checkAll is set or up to m_maxChecksPerCall entries otherwise.
// @fnv 0x00d08800
bool hkpEntityListD088::CheckCollidables(hkArrayD088<hkpCollidableD088*>& kInactive) throw()
{
    if (m_checkAll) {
        for (int i = m_kCollidables.m_iElementCount - 1; i >= 0; i--)
            checkCollidable(i, kInactive);
        return true;
    }

    m_currentIndex = (m_currentIndex < m_kCollidables.m_iElementCount - 1) ? m_currentIndex : m_kCollidables.m_iElementCount - 1;
    int iNumChecked = 0;
    for (int j = 0; j < m_maxChecksPerCall; j++) {
        int i = m_currentIndex--;
        if (i < 0) {
            m_currentIndex = m_kCollidables.m_iElementCount;
            break;
        }
        checkCollidable(i, kInactive);
        iNumChecked++;
    }
    return iNumChecked == m_kCollidables.m_iElementCount;
}

struct hkObjectE02;
struct hkLoaderE02 {
};
struct Sink {
};
struct FUN_00d08940_shell {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    hkLoaderE02 loader;
    void FUN_00d08940(char const* name);
};
struct FlaggedEntrySource
{
    char unk00[0x48];
    char** m_entries;
    int m_iEntryCount;
};

// If m_flag8 is set, sets m_4d to 1 and m_4c to 0, then iterates the entries in arg and calls FUN_00d08940 on each whose byte at offset 0x28 equals 1.
// @fnv 0x00d08a40
void FUN_00d08a40_class::ProcessFlaggedEntries(void* arg)
{
    if (m_flag8)
    {
        int i;
        m_4d = 1;
        m_4c = 0;
        FlaggedEntrySource* p = (FlaggedEntrySource*)arg;
        for (i = 0; i < p->m_iEntryCount; i++)
        {
            D08Collidable* e = &reinterpret_cast<D08WorldObject*>(p->m_entries[i])->m_collidable;
            if (e->m_broadPhaseType == 1)
                ownerOfListener<::FUN_00d08940_shell>(this, kFlaggedListenerOffset)->FUN_00d08940((const char *)(e));
        }
    }
}
// @fnv 0x00d08a90
void FUN_00d08a90_class::FUN_00d08a90(void* arg)
{
    if (m_enabled4) {
        arg = &static_cast<D08WorldObject*>(arg)->m_collidable;
        m_flag49 = 1;
        m_flag48 = 0;
        ownerOfListener<::FUN_00d08940_shell>(this, kEntityListenerOffset)->FUN_00d08940((const char *)(arg));
    }
}
// Looks up name via loader.Get and, on success, passes the arena router's e field and name to the sink at offset 0x50.
// @fnv 0x00d08940
void FUN_00d08940_shell::FUN_00d08940(char const* name)
{
    hkObjectE02* obj;
    if (::LookupBucketValue((::DepthLimit *)&(loader), (uintptr_t)(name), (uintptr_t *)(&obj))) {
        reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>((reinterpret_cast<Sink*>(&this->loader)))->FUN_00cb1870(
            (*(::fnv_00cb1870::hkMemoryAllocatorCB18 *)(hkMemoryRouter::getInstance().m_heap)), reinterpret_cast<uintptr_t>(name), 1);
    }
}

struct FUN_00d9a4d0_class {
};
// The tree object whose entry index FUN_00d08c70 queries.
struct D08C70_Tree {
    char pad00[0x1c];
    FUN_00d9a4d0_class m_entryIndex;  // +0x1c
};
struct FUN_00d08c70_class {
    int unk00;
    int unk04;
    int unk08;
    D08C70_Tree* unk0C;
    void FUN_00d08c70(void* arg);
};
// Calls FUN_00d083e0 with arg to get a word, then passes it to the method at unk0C + 0x1c.
// @fnv 0x00d08c70
void FUN_00d08c70_class::FUN_00d08c70(void* arg)
{
    typedef unsigned short (*FunctionReturningWord)(void*);
    unsigned int value = ((FunctionReturningWord)&FUN_00d083e0)(arg);
    reinterpret_cast<::FUN_00d9a4d0_Class *>(&unk0C->m_entryIndex)->GetEntryOffset(value);
}




template <class T>
__forceinline void constructWithCopyD08C(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayD08C {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyD08C(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpEntityD08C;

void __cdecl DispatchToOffsetTarget(hkpEntityD08C* pkEntity, int iFlags);

class hkpEntityListD08C {
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
    bool m_enabled;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    hkArrayD08C<hkpEntityD08C*> m_kActorEntries;

    void FUN_00d08c90(hkpEntityD08C* pkEntity);
};
// @fnv 0x00d08fb0
void FUN_00d08fb0_Class::FUN_00d08fb0(char* arg)
{
    arg = reinterpret_cast<char*>(&reinterpret_cast<D08WorldObject*>(arg)->m_collidable);
    m_55 = 1;
    m_54 = 0;
    ownerOfListener<::hkpEntityListD08C>(this, kPhantomListenerOffset)->FUN_00d08c90((::hkpEntityD08C *)(arg));
}
// @fnv 0x00d08fd0
void FUN_00d08fd0_class::FUN_00d08fd0(void* a)
{
    m_51 = 1;
    m_50 = 0;
    ownerOfListener<::hkpEntityListD08C>(this, kEntityListListenerOffset)->FUN_00d08c90((::hkpEntityD08C *)(&static_cast<D08WorldObject*>(a)->m_collidable));
}

// If the list is enabled, applies flags 0xffff to pkEntity and appends it to the entity array.
// @fnv 0x00d08c90
void hkpEntityListD08C::FUN_00d08c90(hkpEntityD08C* pkEntity)
{
    if (m_enabled) {
        DispatchToOffsetTarget(pkEntity, 0xffff);
        m_kActorEntries.AddBack(pkEntity);
    }
}

namespace fnv_00d08cf0 {

struct MyArray {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    MyArray() : m_data(0), m_iElementCount(0), m_iCapacityState((int)0x80000000) {}
};

struct MyMapBase {
    void* m_table;
    int m_iCapacityFlags;
    int m_iPairCount;
    MyMapBase() : m_table(0), m_iCapacityFlags(0), m_iPairCount(-1) {}
};

struct Semaphore {
    void* handle;
};

struct Class0xd9c180 {
};

struct ListenerManager {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74;
    char* unk78;

};

struct MyBase1
{
    virtual void FUN_00d08570();
    virtual void vfunc1_1();
    virtual void vfunc1_2();
    virtual void vfunc1_3();
    virtual void vfunc1_4();
    virtual void vfunc1_5();
    virtual void vfunc1_6();
    short unk04;
    short unk06;
    int unk08;
    void* unk0C;
    int unk10;
    MyBase1() {
        this->unk0C = 0;
        this->unk10 = 0;
        this->unk06 = 1;
    }
};

struct MyBase2
{
    virtual void FUN_00d089c0();
    virtual void vfunc2_1();
    virtual void vfunc2_2();
    virtual void vfunc2_3();
    virtual void vfunc2_4();
    virtual void vfunc2_5();
};

struct MyBase3
{
    virtual void FUN_00d089e0();
    virtual void vfunc3_1();
    virtual void vfunc3_2();
    virtual void vfunc3_3();
};

struct MyBase4
{
    virtual void vfunc4_0();
    virtual void vfunc4_1();
    virtual void vfunc4_2();
    virtual void vfunc4_3();
};

struct MyBase5
{
    virtual void vfunc5_0();
    virtual void vfunc5_1();
    virtual void vfunc5_2();
    virtual void vfunc5_3();
};

struct FUN_00d08cf0 : MyBase1, MyBase2, MyBase3, MyBase4, MyBase5
{
    char unk24;
    char unk25;
    char unk26;
    char unk27;
    ListenerManager* unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    void* unk3c;
    float unk40;
    MyArray unk44;
    MyMapBase unk50;
    char unk5c;
    char unk5d;
    char unk5e;
    char unk5f;
    int unk60;
    int unk64;
    char unk68;
    char unk69;
    char unk6a;
    char unk6b;
    void* unk6c;

    FUN_00d08cf0(ListenerManager* a1, int a2, float a3);
    virtual void FUN_00d08570();
    virtual void FUN_00d089c0();
    virtual void FUN_00d089e0();
    virtual void vfunc4_0();
    virtual void vfunc5_0();

};

// @fnv 0x00d08cf0
FUN_00d08cf0::FUN_00d08cf0(ListenerManager* apListenerManager, int a2, float afValue)
    : unk28(apListenerManager)
{
    hkMemoryRouter* audio = &hkMemoryRouter::getInstance();
    reinterpret_cast<::FUN_00cb1fe0_t *>(&(this->unk50))->EnsureCapacity(reinterpret_cast<intptr_t>(audio->m_heap), 0);
    this->unk30 = 0;
    this->unk34 = 0;
    hkMemoryRouter* pAudio = &hkMemoryRouter::getInstance();
    this->unk3c = pAudio->m_heap->blockAlloc(0x10);
    hkMemoryRouter* audio3 = &hkMemoryRouter::getInstance();
    void* pSemaphore = audio3->m_heap->blockAlloc(4);
    if (pSemaphore) {
        pSemaphore = ((void *)(reinterpret_cast<::FUN_00d04350_cls *>((((Semaphore*)pSemaphore)))->Create(0, 1000)));
    } else {
        pSemaphore = 0;
    }
    this->unk6c = pSemaphore;
    __declspec(align(16)) float fValue = afValue;
    this->unk40 = fValue;
    this->unk08 = 1;
    this->unk10 = 0;
    this->unk0C = 0;
    if (a2 == 0) {
        this->unk24 = 1;
    } else if (a2 == 1) {
        this->unk24 = 0;
    }
    reinterpret_cast<::fnv_00c93820::hkpWorldC938 *>((this->unk28))->FUN_00c93820((::fnv_00c93820::hkpEntityListenerC938 *)(void *)((MyBase2*)this));
    reinterpret_cast<::fnv_00c93860::hkpWorldXc93860 *>((this->unk28))->FUN_00c93860((::fnv_00c93860::hkpEntityListenerXc93860 *)(void *)((MyBase3*)this));
    reinterpret_cast<::fnv_00c938a0::hkpWorldXc938a0 *>((this->unk28))->FUN_00c938a0((::fnv_00c938a0::hkpEntityListenerXc938a0 *)(void *)((MyBase4*)this));
    reinterpret_cast<::fnv_00c93920::hkpWorldXc93920 *>((this->unk28))->FUN_00c93920((::fnv_00c93920::hkpEntityListenerXc93920 *)(void *)((MyBase5*)this));
    if (this->unk24) {
        char* edi = this->unk28->unk78 + 0x20;
        hkMemoryRouter* audio4 = &hkMemoryRouter::getInstance();
        void* pObj = audio4->m_heap->blockAlloc(0x80);
        if (pObj) {
            pObj = ((void *)(new ((void *)(((Class0xd9c180*)pObj))) ::FUN_00d9c180((const ::S_00d9c180_Vec *)(edi), (const ::S_00d9c180_Vec *)(void *)(edi + 0x10), (const ::S_00d9c180_Vec *)(void *)(edi + 0x20))));
        } else {
            pObj = 0;
        }
        this->unk0C = pObj;
    }
    this->unk5c = 0;
    this->unk68 = 0;
    this->unk60 = 0;
    this->unk64 = 0x1e;
    reinterpret_cast<::FUN_00d08560_class *>((this))->FUN_00d08560();
}
}  // namespace fnv_00d08cf0

class hkObjD099 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void* m_28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    void* m_48;

    void FUN_00d099a0(void* a, void* c, void* d);
};

struct FUN_00d0a1e0_class {
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
    char unk68;
    char FUN_00d0a1e0();
};
// @fnv 0x00d0a1e0
char FUN_00d0a1e0_class::FUN_00d0a1e0() {
    return unk68;
}

namespace fnv_00d0a240 {

struct FnvCpu_FUN_00d0a240_CpuObject {
    unsigned int unk00;
    unsigned short size;
    void Destructor();
    FnvCpu_FUN_00d0a240_CpuObject* FUN_00d0a240(unsigned int flags);
};
// @fnv 0x00d0a240
FnvCpu_FUN_00d0a240_CpuObject* FnvCpu_FUN_00d0a240_CpuObject::FUN_00d0a240(unsigned int flags)
{
    Destructor();
    if (flags & 1) {
        hkMemoryRouter* pAllocatorHolder = &hkMemoryRouter::getInstance();
        pAllocatorHolder->m_heap->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00d0a240

extern int DAT_010ccfcc;
extern int DAT_010ccfe0;
extern int DAT_010ccfec;
__declspec(align(16)) struct S00d08740_coll {
    const void* m_00;
    const void* m_04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_24;
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
    float m_80;
};
struct S00d08740_cls {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    char m_24;
    char m_25;
    char m_26;
    char m_27;
    void Collect(void* kFrom, void* kTo, void* pkRoot, void* pkFilter, void* pkShapeFilter, void* pkOutput, void* pkCollector);
};



namespace fnvc_adapt {  }

enum hkResultD089 { HK_SUCCESS = 0, HK_FAILURE = 1 };

class hkMapBaseD089 {
public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

};

class OwnerD089 {
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
    hkMapBaseD089 m_map;

    void FUN_00d08980(const void* key);
};

// Looks up key in m_map and, if the lookup fails, calls FUN_00cb1870 on the map with key and -1.
// @fnv 0x00d08980
void OwnerD089::FUN_00d08980(const void* key)
{
    uintptr_t dummy;
    if (::LookupBucketValue((::DepthLimit *)&(m_map), (uintptr_t)key, &dummy) != 0)
        reinterpret_cast<::fnv_00cb1870::hkMapBaseCB18 *>(&(m_map))->FUN_00cb1870(
            *reinterpret_cast<::fnv_00cb1870::hkMemoryAllocatorCB18 *>(&hkMemoryRouter::getInstance().heap()), (uintptr_t)key, ~uintptr_t(0));
}

struct hkpCollidableD08 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int m_broadPhaseId;
    signed char m_cBroadPhaseType;
};

struct hkpEntityD08 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkpCollidableD08 m_kCollidable;
};

struct hkpSimulationIslandD08 {
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
    hkpEntityD08** m_kActorEntries;
    int m_iActorEntryCount;
};

class hkpPrimaryD08 {
public:
    virtual ~hkpPrimaryD08();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

class hkpIslandListenerD08 {
public:
    virtual void islandAddedCallback(hkpSimulationIslandD08* island);
    virtual void FUN_00d089f0(hkpSimulationIslandD08* island);
};

class TrackerD08 : public hkpPrimaryD08, public hkpIslandListenerD08 {
public:
    int unk20;
    bool m_enabled;
    char unk25;
    short unk26;
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
    bool m_dirty;
    bool m_needsUpdate;

    virtual void FUN_00d089f0(hkpSimulationIslandD08* island);
};

// When enabled, marks the tracker for update and calls FUN_00d08980 on each broad-phase-type-1 collidable in the island's actor entries.
// @fnv 0x00d089f0
void TrackerD08::FUN_00d089f0(hkpSimulationIslandD08* island)
{
    if (m_enabled) {
        m_needsUpdate = true;
        m_dirty = false;
        for (int i = 0; i < island->m_iActorEntryCount; i++) {
            hkpCollidableD08* collidable = &island->m_kActorEntries[i]->m_kCollidable;
            if (collidable->m_cBroadPhaseType == 1)
                reinterpret_cast<::OwnerD089 *>(this)->FUN_00d08980(collidable);
        }
    }
}

namespace fnv_00d08e80 {
extern "C" void* DAT_010cd078;
extern "C" void* DAT_010cd05c;
extern "C" void* DAT_010cd044;
extern "C" void* DAT_010cd034;
extern "C" void* DAT_010cd024;


namespace fnvc_adapt {  }

struct Cls_00c917a0 {  };
struct Cls_00c917f0 {  };
struct Cls_00c91840 {  };
struct Cls_00c918e0 {  };
struct Cls_00d97850 {  };
struct Cls_00d04370 {  };
struct Cls_00cb1a90 {  };
struct Cls_00a29680 {  };

struct Virt_d08e80 {
    virtual ~Virt_d08e80();
};

struct Arr_d08e80 {
    void* m_data;
    int m_iElementCount;
    int m_capFlags;
    ~Arr_d08e80() {
        hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0) {
            a.bufFree(m_data, (m_capFlags & 0x3fffffff) * 4);
        }
        m_data = 0;
        m_capFlags = 0x80000000;
    }
    void destroy() { this->~Arr_d08e80(); }
};

struct Tgt_d08e80 {
    void* vtbl00;
    int unk04;
    int unk08;
    Virt_d08e80* unk0C;
    Cls_00d97850* unk10;
    void* vtbl14;
    void* vtbl18;
    void* vtbl1C;
    void* vtbl20;
    int unk24;
    void* unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    void* unk3C;
    int unk40;
    Arr_d08e80 m_aiIndexedValues;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    Cls_00d04370* unk6C;

    void Destructor();
};

// Destroys the object by releasing heap blocks, clearing buffers, and resetting vtable pointers to their initial values.
// @fnv 0x00d08e80
void Tgt_d08e80::Destructor()
{
    vtbl00 = &DAT_010cd078;
    vtbl14 = &DAT_010cd05c;
    vtbl18 = &DAT_010cd044;
    vtbl1C = &DAT_010cd034;
    vtbl20 = &DAT_010cd024;

    reinterpret_cast<::hkWorldC917 *>((((Cls_00c917a0*)unk28)))->FUN_00c917a0(&vtbl14);
    reinterpret_cast<::hkWorldC91F *>((((Cls_00c917f0*)unk28)))->FUN_00c917f0(&vtbl18);
    reinterpret_cast<::ObjectTable *>((((Cls_00c91840*)unk28)))->RemovePointer(&vtbl1C);
    reinterpret_cast<::SearchArray *>((((Cls_00c918e0*)unk28)))->ClearValue((&vtbl20));

    if (unk0C) {
        delete unk0C;
    }

    Cls_00d97850* p10 = unk10;
    if (p10) {
        reinterpret_cast<::fnv_00d97850::FUN_00d97850_cls *>((p10))->ClearBuffers();
        hkMemoryRouter::getInstance().heap().blockFree(p10, 0x50);
    }

    void* pBlock3C = unk3C;
    hkMemoryRouter::getInstance().heap().blockFree(pBlock3C, 0x10);

    Cls_00d04370* pBlock6C = unk6C;
    if (pBlock6C) {
        reinterpret_cast<::FUN_00d04370_cls *>((pBlock6C))->FUN_00d04370();
        hkMemoryRouter::getInstance().heap().blockFree(pBlock6C, 4);
    }

    reinterpret_cast<::CB1A90Owner *>((((Cls_00cb1a90*)&unk50)))->ProcessArgument((::CB1A90Argument *)(hkMemoryRouter::getInstance().m_heap));
    ::FUN_00a29680();

    m_aiIndexedValues.destroy();

    vtbl20 = &DAT_010ccf7c;
    vtbl1C = (void*)&::DAT_0104de10;
    vtbl00 = (void*)&(*reinterpret_cast<int *>(&::DAT_0102e388));
    vtbl18 = (void*)&(*reinterpret_cast<int *>(&::DAT_0104e3d0));
    vtbl14 = (void*)&(*reinterpret_cast<void * *>(&::str_0102f13c));
}
}  // namespace fnv_00d08e80

extern int DAT_010ccfcc;
struct S00d0a490_cls {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* m_10;
    void CallSubroutine(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6);
};

// @fnv 0x00d083c0
void __cdecl FUN_00d083c0()
{
}

struct hkpEntityB90 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_kCollidable;
};
struct hkpSimulationIslandB90 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44;
    hkArrayD08C<hkpEntityB90*> m_kActorEntries;
};
struct hkpWorldB90 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkpSimulationIslandB90* m_pFixedIsland;
    hkpEntityB90* m_pFixedRigidBody;
    int unk28, unk2C, unk30;
    hkArrayD08C<hkpSimulationIslandB90*> m_kActiveSimulationIslands;
};

// Appends pointers to the m_kCollidable field of every active and fixed island actor, except the fixed rigid body, into out.
// @fnv 0x00d08b90
void __cdecl FUN_00d08b90(hkArrayD08C<int*>& out, hkpWorldB90* world)
{
    const hkArrayD08C<hkpSimulationIslandB90*>& islands = world->m_kActiveSimulationIslands;
    for (int i = 0; i < islands.m_iElementCount; i++) {
        for (int j = 0; j < islands.m_data[i]->m_kActorEntries.m_iElementCount; j++)
            out.AddBack(&islands.m_data[i]->m_kActorEntries.m_data[j]->m_kCollidable);
    }
    hkpSimulationIslandB90* fixedIsland = world->m_pFixedIsland;
    hkpEntityB90* fixedBody = world->m_pFixedRigidBody;
    for (int k = 0; k < fixedIsland->m_kActorEntries.m_iElementCount; k++) {
        hkpEntityB90* body = fixedIsland->m_kActorEntries.m_data[k];
        if (body != fixedBody)
            out.AddBack(&body->m_kCollidable);
    }
}

extern char DAT_010cd234[];
extern char DAT_010c41f8[];
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
struct MonitorEvent { const char* tag; unsigned int time; unsigned int extra; };
struct MonitorStream { int unk00; MonitorEvent* current; int unk08; MonitorEvent* end; };
struct UpdateOwner {
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
    bool initialized;
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
    bool dirty;
    void FUN_00d0a060(void*, void*);
};
namespace fnv_00d0a1d0 {
// sub ecx,4; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (4).
struct PrimaryBase
{
    virtual void FUN_00d0a1d0();
};

struct SecondaryBase
{
    virtual void FUN_00d0a1d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0a1d0
    virtual void FUN_00d0a1d0();
};

Derived::Derived()
{
}
}  // namespace fnv_00d0a1d0

// FUN_00d0a200 : MSVC this-adjusting thunk  (sub ecx, 0x14 ; jmp <impl>)
struct A1_00d0a200 {
    A1_00d0a200();
    virtual void FUN_00d0a200();
    char pad[0x10];
};
struct A2_00d0a200 {
    A2_00d0a200();
    virtual void FUN_00d0a200();
};
struct Own_00d0a200 : A1_00d0a200, A2_00d0a200 {
    Own_00d0a200();
    virtual void key_fn();
// @fnv 0x00d0a200
    void FUN_00d0a200();
};
Own_00d0a200::Own_00d0a200() { }
void Own_00d0a200::key_fn() { }
Own_00d0a200* make_00d0a200() { static Own_00d0a200 o; return &o; }

namespace fnv_00d0a210 {
// sub ecx,0x18; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x18).
struct PrimaryBase
{
    virtual void FUN_00d0a210();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SecondaryBase
{
    virtual void FUN_00d0a210();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0a210
    virtual void FUN_00d0a210();
};

Derived::Derived()
{
}
}  // namespace fnv_00d0a210

namespace fnv_00d0a220 {
// sub ecx,0x1c; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x1c).
struct PrimaryBase
{
    virtual void FUN_00d0a220();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct SecondaryBase
{
    virtual void FUN_00d0a220();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0a220
    virtual void FUN_00d0a220();
};

Derived::Derived()
{
}
}  // namespace fnv_00d0a220

// Adjustor thunk: the secondary-base (+0x20) vtable entry for an override defined on the derived class.

class D0A230Primary {
public:
    virtual void FUN_00d0a230();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class D0A230Secondary {
public:
    virtual void FUN_00d0a230();
};

class D0A230Listener : public D0A230Primary, public D0A230Secondary {
public:
    D0A230Listener();
// @fnv 0x00d0a230
    virtual void FUN_00d0a230();
};

D0A230Listener::D0A230Listener()
{
}

namespace fnv_00d085e0 {
extern "C" void _ReadWriteBarrier();

extern "C" char str_010cd014[], str_010cd004[], str_010ccff4[];
extern "C" unsigned __int64 __rdtsc();
struct MyBool0 { int m_v; MyBool0(bool b) { m_v = (int)b; } };
__declspec(noalias) void __cdecl bpv(void*, void*, const hkVector4D084&, const hkVector4D084&, hkpWorldRayCasterD084*) throw();
union Scratch { volatile unsigned int tick; unsigned int result; Scratch() {} };
struct OtherObject { int unk00, unk04, unk08, unk0c, unk10, unk14; };
struct Trace16 { const char* eventName; unsigned int time; unsigned int unk08; const char* category; };
struct Trace12 { const char* eventName; unsigned int time; unsigned int unk08; };
struct TLSBuffer { int unk00; unsigned char* current; int unk08; unsigned char* finish; };
struct FUN_00d085e0_class {
    int unk00, unk04, unk08;
    void* arg0c;
    void* arg10;
    int unk14, unk18, unk1c, unk20;
    char flag24;
    void FUN_00d085e0(const hkpWorldRayCastInputD084& input, const OtherObject* b, hkpWorldRayCastOutputD084* c);
};

// Performs a broad-phase ray cast via bpv and an optional tree cast, recording trace events to a TLS buffer.
// @fnv 0x00d085e0
void FUN_00d085e0_class::FUN_00d085e0(const hkpWorldRayCastInputD084& input, const OtherObject* apFilters, hkpWorldRayCastOutputD084* apRayCastOutput)
{
    Scratch scratch;
    class FUN_00d9a040 ctx;
    ctx.m_pRayCastOutput = apRayCastOutput;
    ctx.m_pRayCastInput = &input;
    if (apFilters) {
        const_cast<const hkpRayCollidableFilterD084* volatile&>(ctx.m_iFilter) = (const hkpRayCollidableFilterD084*) &apFilters->unk14;
        const_cast<const hkpRayShapeCollectionFilterD084* volatile&>(ctx.m_shapeFilter) = (const hkpRayShapeCollectionFilterD084*) &apFilters->unk10;
    } else {
        const_cast<const hkpRayCollidableFilterD084* volatile&>(ctx.m_iFilter) = (const hkpRayCollidableFilterD084*) 0;
        const_cast<const hkpRayShapeCollectionFilterD084* volatile&>(ctx.m_shapeFilter) = (const hkpRayShapeCollectionFilterD084*) 0;
    }
    TLSBuffer* pTlsBuffer = (TLSBuffer*)TlsGetValue(::DAT_0126835c);
    volatile Trace16* e = (Trace16*)pTlsBuffer->current;
    if ((unsigned char*)e < pTlsBuffer->finish) {
        e->eventName = str_010cd014;
        e->category = str_010cd004;
        _ReadWriteBarrier();
        scratch.tick = (unsigned int)__rdtsc(); e->time = scratch.tick;
        pTlsBuffer->current = (unsigned char*)(&e[1]);
    }

    void* tls = arg10;
    if (tls) {
        hkpWorldRayCasterD084 broadPhase;
        broadPhase.m_kCollector = 0;
        broadPhase.m_pRayCastOutput = apRayCastOutput;
        broadPhase.m_pRayCastInput = &input;
        if (apFilters) {
            const_cast<const hkpRayCollidableFilterD084* volatile&>(broadPhase.m_iFilter) = (const hkpRayCollidableFilterD084*) &apFilters->unk14;
            const_cast<const hkpRayShapeCollectionFilterD084* volatile&>(broadPhase.m_shapeFilter) = (const hkpRayShapeCollectionFilterD084*) &apFilters->unk10;
        } else {
            const_cast<const hkpRayCollidableFilterD084* volatile&>(broadPhase.m_iFilter) = (const hkpRayCollidableFilterD084*) 0;
            const_cast<const hkpRayShapeCollectionFilterD084* volatile&>(broadPhase.m_shapeFilter) = (const hkpRayShapeCollectionFilterD084*) 0;
        }
        bpv(&scratch.result, tls, input.m_vFrom, input.m_vTo, &broadPhase);
    }
    pTlsBuffer = (TLSBuffer*)TlsGetValue(::DAT_0126835c);
    volatile Trace12* p = (Trace12*)pTlsBuffer->current;
    if ((unsigned char*)p < pTlsBuffer->finish) {
        p->eventName = str_010ccff4;
        _ReadWriteBarrier();
        scratch.tick = (unsigned int)__rdtsc(); p->time = scratch.tick;
        pTlsBuffer->current = (unsigned char*)(&p[1]);
    }
    if (flag24) {
        FUN_00d1bd00(arg0c, input.m_vFrom, input.m_vTo, static_cast<hkpTreeCastCallbackD084*>(&ctx), 1.0f);
    }
    pTlsBuffer = (TLSBuffer*)TlsGetValue(::DAT_0126835c);
    volatile Trace12* pTrace12 = (Trace12*)pTlsBuffer->current;
    if ((unsigned char*)pTrace12 < pTlsBuffer->finish) {
        pTrace12->eventName = ::str_01076f38;
        _ReadWriteBarrier();
        scratch.tick = (unsigned int)__rdtsc(); pTrace12->time = scratch.tick;
        pTlsBuffer->current = (unsigned char*)(&pTrace12[1]);
    }
}
}  // namespace fnv_00d085e0

extern const char str_010cd130[];
extern const char str_010cd124[];
extern const char str_010cd11c[];
extern const char str_010cd104[];
extern const char str_010cd0fc[];
extern const char str_010cd0f4[];
extern const char str_010cd0e0[];
extern const char str_010cd0d0[];
extern const char str_010cd0c4[];
extern const char str_010cd0b8[];

struct S00d094a0_Cmd { const char* m_name; unsigned m_uiCommandId; int m_08; const char* m_detail; };
struct S00d094a0_Stream { char* m_00; char* m_kRayEnd; char* m_08; char* m_capEnd; };

union CountPhase { volatile unsigned ticks; int bytes; };
union StreamPhase { S00d094a0_Stream* stream; int capacity; };
struct CapPair {StreamPhase pointer;int capacity2;};
__forceinline void S00d094a0_beginList(const char* name, const char* detail)
{
    S00d094a0_Stream* t = (S00d094a0_Stream*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    S00d094a0_Cmd* p = (S00d094a0_Cmd*)t->m_kRayEnd;
    if ((char*)p < t->m_capEnd) {
        p->m_name = name;
        p->m_detail = detail;
        _ReadWriteBarrier();
        unsigned stamp;
        stamp = static_cast<unsigned int>(__rdtsc());
        p->m_uiCommandId = stamp;
        t->m_kRayEnd = reinterpret_cast<char*>(p + 1);
    }
}
__forceinline void S00d094a0_timer(const char* name)
{
    S00d094a0_Stream* t = (S00d094a0_Stream*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    S00d094a0_Cmd* p = (S00d094a0_Cmd*)t->m_kRayEnd;
    if ((char*)p < t->m_capEnd) {
        p->m_name = name;
        _ReadWriteBarrier();
        unsigned stamp;
        stamp = static_cast<unsigned int>(__rdtsc());
        p->m_uiCommandId = stamp;
        t->m_kRayEnd = (char*)&p->m_detail;
    }
}

__forceinline hkMemoryAllocator& S00d094a0_heap() { return hkMemoryRouter::getInstance().heap(); }

__forceinline void* reserveExternal(void*& data, int& capacity, int& bytes, int n) {
    hkMemoryAllocator& a = S00d094a0_heap();
    bytes=n*4;
    void* p=a.bufAlloc(bytes);
    int amount=bytes/4;
    data=p;
    capacity=amount;
    if(!capacity) capacity=0x80000000;
    return p;
}
struct __declspec(align(16)) S00d094a0_Vec { float x, y, z, w; };
struct __declspec(align(16)) S00d094a0_Desc {
    int m_uiItemCount; char m_04; char m_isMt; short m_06; int m_08; int m_0c;
    S00d094a0_Vec m_kMinimumCorner;
    S00d094a0_Vec m_kMaximumCorner;
};
struct S00d094a0_Tree {
    void* m_00; int m_04; int m_08; int m_0c; int m_10; int m_14; int m_18; void* m_1c;
    int total() const { return m_14 + m_18; }
};
struct S00d094a0_Shape {
    virtual void f00(); virtual void f04(); virtual void f08(); virtual void f0c();
    virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1c();
    virtual void f20(); virtual void f24(); virtual void f28(); virtual void f2c();
    virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3c();
    virtual void getAabb(S00d094a0_Vec*, S00d094a0_Vec*);
};
struct S00d094a0_Input { void** m_00; int m_04; };
struct S00d094a0_Ctx {
    int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c;
    int u20; int u24; int u28; int u2c; int u30; int u34; int u38; int u3c;
    int u40; int u44; int u48; int u4c; int u50; int u54;
    S00d094a0_Shape* m_pCollisionShape;
    int u5c; int u60; int u64; int u68; int u6c; int u70; int u74;
    void* m_78;
};
struct S00d094a0_Job;
struct S00d094a0_Queue {   };
struct S00d094a0_Sync {
    virtual void f00(); virtual void f04(); virtual void f08();
    virtual void signal(S00d094a0_Queue*, int); virtual void wait();
};
struct S00d094a0_Helper {  };
struct S00d094a0_JobHead {
    __declspec(align(16)) char m_00;
    char m_01; char m_02;
    short m_04; short m_06;
    S00d094a0_JobHead() {}
    __forceinline S00d094a0_JobHead(char kind, char sub, short size, char spu)
        : m_00(sub), m_01(kind), m_02(spu), m_04(size), m_06(-1) {}
};
struct S00d094a0_QueryJob : S00d094a0_JobHead {
    void* m_10; int* m_14; int* m_18; void* m_1c;
    S00d094a0_QueryJob() {}
    __forceinline S00d094a0_QueryJob(char sub, short size)
        : S00d094a0_JobHead(3,sub,size,0), m_10(0), m_18(0) {
        m_02=1; m_14=0;
    }
};
struct S00d094a0_DistJob : S00d094a0_QueryJob {
    void* m_20; void* m_24; void* m_28; void* m_2c;
    void* m_30; void* m_34;
    int m_38; int m_3c; int m_40;
    S00d094a0_DistJob() {}
    __forceinline S00d094a0_DistJob(int* header) : S00d094a0_QueryJob(3,0x50),m_30(0) { m_14=header; }
};
struct S00d094a0_Job : S00d094a0_DistJob {
    void** m_50;
    S00d094a0_Job() {}
    __forceinline void init(int* header,S00d094a0_Ctx* ctx) { m_06=-1; m_14=header; m_04=0x60; m_1c=ctx->m_78; m_01=3; m_18=0; m_02=1; m_00=6; m_30=0; }
    __forceinline S00d094a0_Job(int* header,S00d094a0_Ctx* ctx) : S00d094a0_DistJob(header) {
        m_00=6; m_04=0x60; m_1c=ctx->m_78;
    }
};
struct __declspec(align(16)) S00d094a0_Build {
    S00d094a0_Desc desc;
    int m_30; int m_uiItemCount; void* m_buf1; void* m_buf2;
    S00d094a0_Job job;
};
struct S00d094a0_Fallback {
    int m_00; int m_04; int m_08;
};

struct S00d094a0_Owner {
    int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c;
    int u20; int u24; int u28; int u2c;
    void* m_30; void* m_34; int u38; int* m_3c;
    int u40; int u44; int u48; int u4c; int u50; int u54; int u58; int u5c;
    int u60; int u64; int u68;
    S00d094a0_Helper* m_6c;
    void FUN_00d094a0(S00d094a0_Tree** tree, S00d094a0_Input* input, S00d094a0_Ctx* ctx, S00d094a0_Queue* queue, S00d094a0_Sync* sync);
};
// @fnv 0x00d099a0
void hkObjD099::FUN_00d099a0(void* a, void* c, void* d)
{
    if (m_48)
        reinterpret_cast<::S00d094a0_Owner *>(this)->FUN_00d094a0((::S00d094a0_Tree **)(int *)(&m_10), (::S00d094a0_Input *)(a), (::S00d094a0_Ctx *)(m_28), (::S00d094a0_Queue *)(c), (::S00d094a0_Sync *)(d));
}


template<class T> struct S00d094a0_TempArray {
    T* data; int size; int flags;
    __forceinline S00d094a0_TempArray(int count) {
        hkMemoryAllocator& heap=S00d094a0_heap();
        T* pointer=count?heap._bufAlloc<T>(count):0;
        int cap=count?count:0x80000000;
        data=pointer;size=count;flags=cap;
    }
    __forceinline void release() {hkMemoryAllocator& heap=S00d094a0_heap(); if(!(flags&0x80000000))heap.bufFree(data,(flags&0x3fffffff)*sizeof(T));}
    __forceinline T* begin(){return data;}
};

// @fnv 0x00d094a0
void S00d094a0_Owner::FUN_00d094a0(S00d094a0_Tree** tree, S00d094a0_Input* input, S00d094a0_Ctx* ctx, S00d094a0_Queue* queue, S00d094a0_Sync* sync) {
    if(sync && queue && input->m_04>=32) {
        S00d094a0_beginList(str_010cd130,str_010cd124);
        const int count=input->m_04;
        S00d094a0_Desc desc;
        reinterpret_cast<::FUN_00d976d0_cls *>(&(desc))->FUN_00d976d0(); desc.m_uiItemCount=count;desc.m_isMt=1;
        ctx->m_pCollisionShape->getAabb(&desc.m_kMinimumCorner,&desc.m_kMaximumCorner);
        if(*tree)reinterpret_cast<::Tree_d978 *>(((*tree)))->FUN_00d978d0((*(const ::Cinfo_d978 *)(&desc)));
        else {S00d094a0_Tree* p=(S00d094a0_Tree*)S00d094a0_heap().blockAlloc(0x50);*tree=p?((::S00d094a0_Tree *)(reinterpret_cast<::FUN_00d97970_cls *>((p))->Init((uintptr_t)(&desc)))):0;}
        *m_3c=4;
        S00d094a0_TempArray<int> arrayA(4);
        S00d094a0_TempArray<int> arrayB(4);
        S00d094a0_Job task(m_3c,ctx);
        task.m_10=m_6c;task.m_50=input->m_00;
        task.m_20=m_30;task.m_24=m_34;
        task.m_30=arrayA.begin();task.m_34=arrayB.begin();
        task.m_38=(*tree)->m_10;task.m_28=(*tree)->m_00;
        task.m_3c=(*tree)->total();task.m_2c=(*tree)->m_1c;task.m_40=(*tree)->m_18;
        S00d094a0_timer(str_010cd11c);
        S00d094a0_beginList(str_010cd104,str_010cd0fc);
        reinterpret_cast<::fnv_00d04b50::Owner *>((queue))->FUN_00d04b50(&task,0);
        S00d094a0_timer(str_010cd0f4);
        sync->signal(queue,3);reinterpret_cast<::Dispatcher *>((queue))->FUN_00d051b0();
        S00d094a0_timer(str_010cd0e0);
        sync->wait();S00d094a0_timer(str_010cd0d0);
        ::FUN_00d04380((void *)(m_6c), {});S00d094a0_timer(str_010cd0c4);
        ::FUN_00d9d950((::S9d950_Owner *)(*tree),count,(const ::S9d950_Box *)(task.m_30),(const int *)(task.m_34));
        S00d094a0_timer(str_01076f38);S00d094a0_timer(str_010cd0b8);S00d094a0_timer(str_01076f38);
        arrayB.release();arrayA.release();
    } else {
        S00d094a0_Fallback fallback;reinterpret_cast<::ListWalker *>(&(fallback))->InitWalker((::ItemListRec *)(input),(::CtxRec *)(ctx));
        const int count=((int)(reinterpret_cast<::Owner *>(&(fallback))->FUN_00d9e000()));
        S00d094a0_Desc desc;reinterpret_cast<::FUN_00d976d0_cls *>(&(desc))->FUN_00d976d0();desc.m_uiItemCount=count;desc.m_isMt=0;
        ctx->m_pCollisionShape->getAabb(&desc.m_kMinimumCorner,&desc.m_kMaximumCorner);
        if(*tree)reinterpret_cast<::Tree_d978 *>(((*tree)))->FUN_00d978d0((*(const ::Cinfo_d978 *)(&desc)));
        else {S00d094a0_Tree* p=(S00d094a0_Tree*)S00d094a0_heap().blockAlloc(0x50);*tree=p?((::S00d094a0_Tree *)(reinterpret_cast<::FUN_00d97970_cls *>((p))->Init((uintptr_t)(&desc)))):0;}
        ::FillAabbArray((::S_00d9dab0_Coll *)(::S00d094a0_Fallback *)(&fallback),0,count,(::S_00d9dab0_Aabb16 *)(m_30));::DrawIfCountPositive(&m_30,(::DrawParams *)(*tree));
    }
}

namespace fnv_00d0a170 {

class hkKdTreeCastCollector {
public:
    virtual ~hkKdTreeCastCollector() throw() {}
};

class CollectorD0A1 : public hkKdTreeCastCollector {
public:
    int unk04, unk08, unk0C, unk10, unk14;

    static void operator delete(void* p)
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(CollectorD0A1));
    }
    CollectorD0A1* FUN_00d0a170(unsigned int uiFlags);
};

// Destroys the hkKdTreeCastCollector base and, when uiFlags has bit 0 set, frees the CollectorD0A1 object via operator delete.
// @fnv 0x00d0a170
CollectorD0A1* CollectorD0A1::FUN_00d0a170(unsigned int uiFlags)
{
    this->hkKdTreeCastCollector::~hkKdTreeCastCollector();
    if (uiFlags & 1)
        CollectorD0A1::operator delete(this);
    return this;
}
}  // namespace fnv_00d0a170

namespace fnv_00d0b0d0 {

template <class T>
class hkArrayD0B0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD0B0() throw()
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkD0B0 {
    class hkBaseObject {
    public:
        virtual ~hkBaseObject() throw() {}
    };

    class hkReferencedObject : public hkBaseObject {
    public:
        unsigned short m_usMemSizeAndFlags;
        short m_sReferenceCount;
        void FUN_00c905b0() throw();
    };
}

class hkpWorldPostSimulationListener {
public:
    virtual ~hkpWorldPostSimulationListener() throw() {}
};

namespace hkD0B0 {
    class ListenerD0B0 : public hkReferencedObject, public hkpWorldPostSimulationListener {
    };

    struct Elem12D0B0 {
        int unk00, unk04, unk08;
    };

    struct Elem16D0B0 {
        int unk00, unk04, unk08, unk0C;
    };
}

class FUN_00d0b0d0 {
public:
    ~FUN_00d0b0d0();

    hkD0B0::ListenerD0B0 m_kListener;
    int unk0C, unk10;
    hkArrayD0B0<hkD0B0::Elem12D0B0> m_kFirst;
    hkArrayD0B0<hkD0B0::Elem16D0B0> m_kSecond;
    hkArrayD0B0<hkD0B0::Elem12D0B0> m_kThird;
};

// Destroys the FUN_00d0b0d0 object, allowing member destructors to run.
// @fnv 0x00d0b0d0
FUN_00d0b0d0::~FUN_00d0b0d0()
{
}
}  // namespace fnv_00d0b0d0

struct Target {
    int unk00;
};

struct Item1 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Target m_target;
};

struct Item2 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Target m_target;
};



template <typename T>
struct hkArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(hkMemoryRouter* h, T val) {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff)) {
            ::ResizeAudioStream((::AudioAllocator *)(h->m_heap), (::AudioStream *)(void *)(this), sizeof(T));
        }
        T* slot = m_data + m_iElementCount;
        __assume(slot != 0);
        new (slot) T(val);
        ++m_iElementCount;
    }
};

struct SubStruct1 {
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
    hkArray<Item1*> m_items;
};

struct Container {
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
    hkArray<SubStruct1*> m_array1;
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
    hkArray<Item2*> m_array2;
};

// Gathers Target pointers from m_array1 items and m_array2 entries into out, skipping m_array2 entries whose m_target.unk00 is zero.
// @fnv 0x00d08ac0
void FUN_00d08ac0(hkArray<Target*>* out, void* container) {
    Container* c = static_cast<Container*>(container);
    for (int containerHandle = 0; containerHandle < c->m_array1.m_iElementCount; containerHandle++) {
        for (int j = 0; j < c->m_array1.m_data[containerHandle]->m_items.m_iElementCount; j++) {
            out->AddBack(&hkMemoryRouter::getInstance(), &c->m_array1.m_data[containerHandle]->m_items.m_data[j]->m_target);
        }
    }
    for (int k = 0; k < c->m_array2.m_iElementCount; k++) {
        if (c->m_array2.m_data[k]->m_target.unk00) {
            out->AddBack(&hkMemoryRouter::getInstance(), &c->m_array2.m_data[k]->m_target);
        }
    }
}

// Clears self->b, then calls FUN_00d08ac0 and FUN_00d08b90 with self and arg.
// @fnv 0x00d08ff0
void FUN_00d08ff0(FUN_00d08ff0_t* self, void* arg)
{
    self->b = 0;
    FUN_00d08ac0((hkArray<Target*>*)self, arg);
    FUN_00d08b90(*(hkArrayD08C<int*>*)self, (hkpWorldB90*)arg);
}

struct MarkerBuf {
    char* unk0;
    char* m_cursor;
    char* unk8;
    char* m_kRayEnd;
};

// Monitor-stream timer records: a name, the low tick count, and for the begin-list form a second name.
struct MarkerRec12 {
    const char* name;
    unsigned int stamp;
    unsigned int unk;
};
struct MarkerRec16 {
    const char* name;
    unsigned int stamp;
    unsigned int unk;
    const char* name2;
};
extern void* DAT_00fdf044;
extern char DAT_010cd224;
extern char DAT_010cd154;
extern char DAT_010cd14c;
extern char DAT_010cd140;
extern char DAT_010cd214;

struct D9bed0Cls {
};
struct D09020Cls {
};
struct ActiveTreeBuilder {
};
struct TreeCleanMarker {
};

struct TempArr {
    int* m_data;
    int m_iElementCount;
    int m_capFlags;
    void destroy()
    {
        hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0)
            a.bufFree(m_data, (m_capFlags & 0x3fffffff) * int(sizeof(int)));
    }
};

struct EntListSelf {
    int unk00;
    int unk04;
    int unk08;
    D9bed0Cls* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    bool m_enabled;
    void* m_28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    hkpEntityD08C** m_entData;
    int m_entSize;
    int m_entCap;

    void FUN_00d09df0(void* p1, void* p2);
};

static __forceinline void mark16(MarkerBuf* buf, char* name, char* name2, volatile unsigned int* stampOut)
{
    MarkerRec16* cur = (MarkerRec16*)buf->m_cursor;
    if ((char*)cur < buf->m_kRayEnd) {
        cur->name = name;
        cur->name2 = name2;
        _ReadWriteBarrier();
        *stampOut = (unsigned int)__rdtsc();
        cur->stamp = *stampOut;
        buf->m_cursor = reinterpret_cast<char*>(cur + 1);
    }
}
static __forceinline void mark12(MarkerBuf* buf, char* name, volatile unsigned int* stampOut)
{
    MarkerRec12* cur = (MarkerRec12*)buf->m_cursor;
    if ((char*)cur < buf->m_kRayEnd) {
        cur->name = name;
        _ReadWriteBarrier();
        *stampOut = (unsigned int)__rdtsc();
        cur->stamp = *stampOut;
        buf->m_cursor = reinterpret_cast<char*>(cur + 1);
    }
}


namespace RaycasterRework {

class FUN_00d9a040 : public hkpRayCastCollectorBaseD084,
                     public hkpTreeCastCallbackD084 {
public:
    const hkpWorldRayCastInputD084* m_pRayCastInput;
    const hkpRayCollidableFilterD084* m_iFilter;
    const hkpRayShapeCollectionFilterD084* m_shapeFilter;
    hkpWorldRayCastOutputD084* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
    float m_fEarlyOutHitFraction;

    FUN_00d9a040() throw();
};

// Default constructor that nulls all hkpRayCast pointers and sets m_fEarlyOutHitFraction to 1.0f.
// @fnv 0x00d9a040
FUN_00d9a040::FUN_00d9a040() throw()
    : m_pRayCastInput(0), m_iFilter(0), m_shapeFilter(0), m_pRayCastOutput(0),
      m_kCollector(0), m_fEarlyOutHitFraction(1.0f)
{
}

}

// Moved from hkpaabbtreeworldmanager_ehsc_noehsc_variant.cpp (VEGAS-15).
#include "fnv/decl/S00d9c610_AabbTree.h"
void FUN_00d08ff0(FUN_00d08ff0_t* self, void* arg);
int FUN_00d08390(void* self, int, intptr_t value);
void FUN_00d083e0(void* arg);
void FUN_00d08380(int);
void __cdecl DispatchToOffsetTarget(FUN_00d08400_cls* pkObject, unsigned short usValue);
template <class T>
void __cdecl FUN_00d083c0();
void __cdecl FUN_00d08b90(hkArrayD08C<int*>& out, hkpWorldB90* world);

struct PEv { const char* name; unsigned tick; unsigned extra; };
struct PLEv : PEv { const char* first; };
struct PCEv { const char* name; float value; };
struct ProfileStream {
    int unk00;
    PEv* cursor;
    int unk08;
    PEv* end;
    void begin(const char* name, const char* first) {
        PLEv* event = (PLEv*)cursor;
        if (event < (PLEv*)end) {
            event->name = name;
            event->first = first;
            unsigned int ticks;
            ticks = static_cast<unsigned int>(__rdtsc());
            event->tick = ticks;
            cursor = (PEv*)(event + 1);
        }
    }
    void timerT(const char* name) {
        PEv* event = cursor;
        if (event < end) {
            event->name = name;
            unsigned int ticks;
            ticks = static_cast<unsigned int>(__rdtsc());
            event->tick = ticks;
            cursor = event + 1;
        }
    }
    void count(const char* name, float value) {
        PCEv* event = (PCEv*)cursor;
        if (event < (PCEv*)end) {
            event->name = name;
            event->value = value;
            cursor = (PEv*)(event + 1);
        }
    }
};

extern void* DAT_00fdf044;
struct Node;
struct NodeArrayBase {
    Node** data;
    int size;
    int capacity;
    NodeArrayBase() : data(0), size(0), capacity(0x80000000) {}
    Node*& operator[](int index) { return data[index]; }
    int GetLogicalSize() const { return size; }
    void clear() { size=0; }
    void pushBackUnchecked(Node* const& value) { data[size]=value; ++size; }
    void removeAt(int index) { --size; if (size!=index) data[index]=data[size]; }
    void ClearAndRelease(hkMemoryAllocator& alloc) {
        clear();
        if ((capacity&0x80000000)==0) alloc.bufFree(data,(capacity&0x3fffffff)*int(sizeof(Node*)));
        data=0;
        capacity=0x80000000;
    }
};
struct NodeHeapArray : NodeArrayBase {
    ~NodeHeapArray() { ClearAndRelease(hkMemoryRouter::getInstance().heap()); }
};
struct NodeArray : NodeHeapArray {
    char* saved;
    NodeArray(int count) {
        char* memory=(char*)hkMemoryRouter::getInstance().allocateStack((count*int(sizeof(Node*))+127)&~127);
        data=(Node**)memory;
        capacity=count|0x80000000;
        saved=memory;
    }
    ~NodeArray() {
        if (saved==(char*)data) clear();
        hkMemoryRouter::getInstance().deallocateStack(saved);
    }
};
struct __declspec(align(16)) Bounds { float minX,minY,minZ,minW,maxX,maxY,maxZ,maxW; };
struct Shape {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6();
    virtual void getBounds(void*, float, Bounds*);
};
struct Node {
    Shape* shape;
    int unk04;
    void* transform;
    int unk0c; signed char ownerOffset; unsigned char unk11; unsigned short unk12; unsigned int tag;
    unsigned char active;
 void getBounds(Bounds& bounds) const { shape->getBounds(transform, 0.0f, &bounds); }
};
struct Tree {
};
struct ScanToken;
struct ByteTruth {
    char value;
    ByteTruth(bool x) : value((char)x) {}
    operator bool() const { return value != 0; }
};
struct TablePair { uintptr_t key; uintptr_t value; };
struct MapStorage {
    TablePair* elem; int numElems; int hashMod;
    ScanToken* first() const {
        int index=0;
        for (; index <= hashMod; ++index) if (elem[index].key != ~uintptr_t(0)) break;
        return (ScanToken*)(uintptr_t)index;
    }
    ScanToken* next(ScanToken* token) const {
        int index=(int)(uintptr_t)token+1;
        for (; index <= hashMod; ++index) if (elem[index].key != ~uintptr_t(0)) break;
        return (ScanToken*)(uintptr_t)index;
    }
    ByteTruth valid(ScanToken* token) const { return (int)(uintptr_t)token <= hashMod; }
    uintptr_t key(ScanToken* token) const { return elem[(int)(uintptr_t)token].key; }
    uintptr_t value(ScanToken* token) const { return elem[(int)(uintptr_t)token].value; }
};
struct EntryMap {
    MapStorage table;
    ScanToken* GetFirstIterator() const { return table.first(); }
    ScanToken* getNext(ScanToken* token) const { return table.next(token); }
    ByteTruth isValid(ScanToken* token) const { return table.valid(token); }
    Node* GetIteratorKey(ScanToken* token) const { return (Node*)table.key(token); }
    int getValue(ScanToken* token) const { return (int)table.value(token); }
};
void __cdecl DispatchToOffsetTarget(Node*, unsigned short);
struct ArrayHeader { int a; int b; int c; };
struct UpdateState {
    int unk00; int unk04; int unk08; Tree* tree;
    FUN_00d08ff0_t gather;
    int unk20;
    unsigned char incremental;
    void* gatherMode;
    int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40;
    NodeHeapArray nodes;
    EntryMap entries;
    unsigned char fullScan; int scanStart; int scanLimit;
    unsigned char unk68; unsigned char dirty;
    __declspec(noinline) bool CheckCollidables(NodeArrayBase&);
    unsigned short FUN_00d083e0(Node*);
    bool isActive(int& value, Node* node) { unsigned short id = FUN_00d083e0(node); return value == 1 && id != 0xffff; }
    void FUN_00d08c90(Node*);
    void FUN_00d099d0(void* arg1, void* arg2);
};
struct CommandTimingEntry {
    const char* m_pCommandName; unsigned m_uiStartTicks; unsigned m_uiEndTicks;
    __forceinline void setTime() {
        unsigned int ticks;
        ticks = static_cast<unsigned int>(__rdtsc());
        m_uiStartTicks = ticks;
    }
};
struct TimedNameRecord : CommandTimingEntry { const char* m_pFirst; };
struct CommandFilterEntry { const char* m_pCommandName; float m_uiFilterValue; };
struct MonitorStreamD099 {
    char* m_kRayStart; char* m_kRayEnd; char* m_pRayCursor; char* m_pCurrentCommand;
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
    char* GetStreamEnd() { return m_kRayEnd; }
    void setEnd(char* e) { m_kRayEnd = e; }
    static MonitorStreamD099& GetMonitorStream() { return *(MonitorStreamD099*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))); }
};
static __forceinline void hkTimerBeginList(const char* name, const char* first) {
    MonitorStreamD099& mStream = MonitorStreamD099::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        TimedNameRecord* h = (TimedNameRecord*)mStream.GetStreamEnd();
        h->m_pCommandName = name;
        h->m_pFirst = first;
        h->setTime();
        mStream.setEnd(reinterpret_cast<char*>(h + 1));
    }
}
static __forceinline void hkTimerSplit(const char* name) {
    MonitorStreamD099& mStream = MonitorStreamD099::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        CommandTimingEntry* h = (CommandTimingEntry*)mStream.GetStreamEnd();
        h->m_pCommandName = name;
        h->setTime();
        mStream.setEnd(reinterpret_cast<char*>(h + 1));
    }
}
static __forceinline void hkAddValue(const char* name, float value) {
    MonitorStreamD099& mStream = MonitorStreamD099::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        CommandFilterEntry* h = (CommandFilterEntry*)mStream.GetStreamEnd();
        h->m_pCommandName = name;
        h->m_uiFilterValue = value;
        mStream.setEnd(reinterpret_cast<char*>(h + 1));
    }
}
// @fnv 0x00d099d0
void UpdateState::FUN_00d099d0(void* arg1, void* arg2) {
    NodeArray inactive(nodes.GetLogicalSize());
    bool changed = false;
    if (incremental) {
        hkTimerBeginList("LtIncrementalBuild", "StClear Tree");
        hkTimerSplit("StFind Inactivated");
        if (dirty) {
            changed = reinterpret_cast<::hkpEntityListD088 *>(this)->CheckCollidables((::hkArrayD088< ::hkpCollidableD088 *> &)(inactive));
            hkTimerSplit("StUpdate Inactive Tree");
            Tree* t = tree;
            for (int i=0;i<inactive.GetLogicalSize();++i) {
                    Node* node = inactive[i];
                    Bounds bounds;
                    node->getBounds(bounds);
                    hkAddValue("MiNum of Added Nodes", 1.0f);
                    DispatchToOffsetTarget(inactive[i], reinterpret_cast<::S00d9c610_AabbTree *>((t))->FUN_00d9c610((*(const ::S00d9c610_Aabb *)(&bounds)), node));
            }
            dirty = false;
        }
        hkTimerSplit("StFind Activated");
        Tree* currentTree = tree;
        for (ScanToken* it = entries.GetFirstIterator(); entries.isValid(it); it = entries.getNext(it)) {
            Node* node = entries.GetIteratorKey(it);
            int state = entries.getValue(it);
            if (isActive(state, node) && node->active == 1) {
                hkAddValue("MiNum of Removed Nodes", 1.0f);
                reinterpret_cast<::FUN_00d9c7d0_C *>((currentTree))->FUN_00d9c7d0((::NodeD9C7 *)(uintptr_t)(FUN_00d083e0(node)));
                reinterpret_cast<::hkpEntityListD08C *>(this)->FUN_00d08c90((::hkpEntityD08C *)(node));
            }
        }
        hkTimerSplit("StUpdate Active");
        reinterpret_cast<::hkObjD099 *>(this)->FUN_00d099a0((void *)&(nodes), (void *)(arg1), (void *)(arg2));
        hkTimerSplit("lt");
    } else {
        hkTimerBeginList("LtDynamicBuild", "StGather");
        nodes.clear();
        FUN_00d08ff0((FUN_00d08ff0_t*)&nodes, gatherMode);
        hkTimerSplit("StClear");
        hkTimerSplit("StRebuild");
        reinterpret_cast<::S00d094a0_Owner *>(this)->FUN_00d094a0((::S00d094a0_Tree **)(::FUN_00d08ff0_t *)(&gather), (::S00d094a0_Input *)&(nodes), (::S00d094a0_Ctx *)(gatherMode), (::S00d094a0_Queue *)(arg1), (::S00d094a0_Sync *)(arg2));
        hkTimerSplit("lt");
    }
    ((FUN_00d08550_Class*)this)->FUN_00d08550();
    if (changed) dirty = true;
}

struct BodyOwner {
    hkBoolRetD088 FUN_00c9bff0() const;
};
static __forceinline BodyOwner* getBodyOwner(Node* node) {
    return node->active==1 ? (BodyOwner*)((char*)node+node->ownerOffset) : 0;
}
__declspec(noinline) bool UpdateState::CheckCollidables(NodeArrayBase& output) {
    if (fullScan) {
        for (int index=nodes.GetLogicalSize()-1;index>=0;--index) {
            BodyOwner* owner=getBodyOwner(nodes[index]);
            if (owner) {
                bool active=owner->FUN_00c9bff0().m_cBooleanValue!=0;
                if (!active) {
                    output.pushBackUnchecked(nodes[index]);
                    nodes.removeAt(index);
                }
            }
        }
        return true;
    } else {
        int last=nodes.GetLogicalSize()-1;
        scanStart=scanStart<last?scanStart:last;
        int scanned=0;
        for (int count=0;count<scanLimit;++count) {
            int index=scanStart--;
            if (index<0) {scanStart=nodes.GetLogicalSize(); break;}
            BodyOwner* owner=getBodyOwner(nodes[index]);
            if (owner) {
                bool active=owner->FUN_00c9bff0().m_cBooleanValue!=0;
                if (!active) {
                    output.pushBackUnchecked(nodes[index]);
                    nodes.removeAt(index);
                }
            }
            ++scanned;
        }
        return scanned==nodes.GetLogicalSize();
    }
}

// Moved from hkpaabbtreeworldmanager_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
#include "fnv/decl/AabbTree16.h"
#include "fnv/symbols_01011000.h"

#include <xmmintrin.h>
#include "fnv/symbols_simd.h"

void __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* arr, int newCap, int elemSize);

struct S00d09020_Vec
{
    __m128 m_vComponents;
    void mul(const S00d09020_Vec& b)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, b.m_vComponents);
    }
    void mulR(const S00d09020_Vec& b)
    {
        m_vComponents = _mm_mul_ps(b.m_vComponents, m_vComponents);
    }
    void sub(const S00d09020_Vec& b)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, b.m_vComponents);
    }
    void SetProduct(const S00d09020_Vec& a, const S00d09020_Vec& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct S00d09020_Aabb
{
    S00d09020_Vec m_kMinimumCorner;
    S00d09020_Vec m_kMaximumCorner;
};

struct S00d09020_Shape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void getAabb(int a, float tol, S00d09020_Aabb* out);
};

struct S00d09020_Elem
{
    S00d09020_Shape* m_pCollisionShape;
    int unk04;
    int m_08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int m_kMinimumCorner[4];
    unsigned int m_kMaximumCorner[4];
};

struct S00d09020_Arg
{
    S00d09020_Elem** m_data;
    int m_iElementCount;
};

template <class T> struct S00d09020_Arr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S00d09020_Arr() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~S00d09020_Arr()
    {
        hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void reserve(int n)
    {
        hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int c = cap * 2;
            FUN_00c908c0(&a, this, n < c ? c : n, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

template <class T> struct S00d09020_Local : public S00d09020_Arr<T>
{
    T* m_pStackAllocation;
    S00d09020_Local(int n)
    {
        char* top = (char*)hkMemoryRouter::getInstance().allocateStack(int((n * sizeof(T) + 0x7f) & ~0x7f));
        this->m_data = (T*)top;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = (T*)top;
    }
    ~S00d09020_Local()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        hkMemoryRouter::getInstance().deallocateStack(mem);
    }
};

struct S00d09020_Builder
{
};

struct D090Rows
{
    S00d09020_Vec m_offset;
    S00d09020_Vec m_unused;
    S00d09020_Vec m_vScale;
};
struct D090Phase
{
    S00d09020_Vec m_pHeadNode;
    S00d09020_Vec m_iSecondInteger;
    D090Rows m_rows;
};
struct S00d09020_Inner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74;
    D090Phase* m_78;
};

__forceinline void S00d09020_trace(const char* tag, volatile unsigned int& ticks)
{
    MonitorStream* s = (MonitorStream*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    MonitorEvent* e = s->current;
    if (e < s->end)
    {
        e->tag = tag;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        e->time = ticks;
        s->current = e + 1;
    }
}

__forceinline void S00d09020_set(S00d09020_Vec& v, float x, float y, float z, float w)
{
    v.m_vComponents = _mm_setr_ps(x, y, z, w);
}

struct S00d09020_This
{
    int unk00;
    int unk04;
    int unk08;
    S00d09020_Builder* m_builder;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    S00d09020_Inner* m_inner;
    void FUN_00d09020(S00d09020_Arg* arg, void* p2, void* p3);
};

// @fnv 0x00d09020
void S00d09020_This::FUN_00d09020(S00d09020_Arg* arg, void* p2, void* p3)
{
    union BuilderTime
    {
        S00d09020_Builder* ptr;
        volatile unsigned int tick;
    } builder;
    builder.ptr = m_builder;
    volatile unsigned int timestamp;
    int n = arg->m_iElementCount;

    S00d09020_Local<S00d09020_Aabb> aabbs(n);
    aabbs.SetSizeAndGrow(n);
    S00d09020_Local<S00d09020_Elem*> elems(n);
    elems.SetSizeAndGrow(n);

    {
        MonitorStream* s = (MonitorStream*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
        MonitorEvent* e = s->current;
        if (e < s->end)
        {
            e->tag = "Ttprepare";
            _ReadWriteBarrier();
            timestamp = (unsigned int)__rdtsc();
            e->time = timestamp;
            s->current = e + 1;
        }
    }
    const D090Rows& xf = m_inner->m_78->m_rows;
    for (int i = 0; i < n; i++)
    {
        const unsigned int* q = arg->m_data[i]->m_kMinimumCorner;
        S00d09020_Aabb* base = aabbs.m_data;
        if (q[0] <= q[4])
        {
            S00d09020_Aabb* out = &base[i];
            S00d09020_Vec retained;
            S00d09020_set(retained, (float)q[0], (float)q[1], (float)q[2], 0.0f);
            out->m_kMinimumCorner.m_vComponents = retained.m_vComponents;
            S00d09020_set(out->m_kMaximumCorner, (float)q[4], (float)q[5], (float)q[6], 0.0f);
            __m128 scale = xf.m_vScale.m_vComponents;
            __m128 t = _mm_shuffle_ps(scale, _mm_unpackhi_ps(scale, ::DAT_010c7170), 0xc4);
            __m128 r = _mm_rcp_ps(t);
            __m128 inv = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, t), r));
            __m128 product = inv;
            product = _mm_mul_ps(product, retained.m_vComponents);
            out->m_kMinimumCorner.m_vComponents = product;
            S00d09020_Vec* hi = (S00d09020_Vec*)out + 1;
            hi->m_vComponents = _mm_mul_ps(hi->m_vComponents, inv);
            out->m_kMinimumCorner.m_vComponents =
                _mm_sub_ps(_mm_load_ps((const float*)&out->m_kMinimumCorner), xf.m_offset.m_vComponents);
            out->m_kMaximumCorner.sub(xf.m_offset);
        }
        else
        {
            arg->m_data[i]->m_pCollisionShape->getAabb(arg->m_data[i]->m_08, 0.0f, &base[i]);
        }
        elems.m_data[i] = arg->m_data[i];
    }
    {
        MonitorStream* s = (MonitorStream*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
        MonitorEvent* e = s->current;
        if (e < s->end)
        {
            e->tag = DAT_010c41f8;
            _ReadWriteBarrier();
            timestamp = (unsigned int)__rdtsc();
            e->time = timestamp;
            s->current = e + 1;
        }
    }

    S00d09020_Arr<unsigned short> ids;
    {
        MonitorStream* s = (MonitorStream*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
        MonitorEvent* e = s->current;
        if (e < s->end)
        {
            e->tag = "Ttbuild";
            _ReadWriteBarrier();
            timestamp = (unsigned int)__rdtsc();
            e->time = timestamp;
            s->current = e + 1;
        }
    }
    if (n > 0)
        reinterpret_cast<::AabbTree16 *>((builder.ptr))->FUN_00d9ce50((const ::TreeAabb *)(aabbs.m_data), (const int *)(elems.m_data), n, (::TreeArray<unsigned short> *)(::S00d09020_Arr<unsigned short> *)(&ids));
    {
        MonitorStream* s = (MonitorStream*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
        MonitorEvent* e = s->current;
        if (e < s->end)
        {
            e->tag = DAT_010c41f8;
            _ReadWriteBarrier();
            builder.tick = (unsigned int)__rdtsc();
            e->time = builder.tick;
            s->current = e + 1;
        }
    }

    for (int j = 0; j < n; j++)
        DispatchToOffsetTarget((FUN_00d08400_cls*)arg->m_data[j], ids.m_data[j]);
}

// Moved from hkpaabbtreeworldmanager_rtm_variant.cpp (VEGAS-15).
#include "fnv/symbols_01016000.h"
template <typename T>
void FUN_00d08ac0(hkArray<Target*>* out, void* container);

struct FloatPtr {float* p; FloatPtr(float* q):p(q){} };
struct Scalar {
 __m128 value;
 Scalar(float f) { value=_mm_load_ss(&f); }
 Scalar(__m128 v) { value=v; }
 __m128 spread() const { return _mm_shuffle_ps(value,value,0); }
 operator float() const { float f;_mm_store_ss(&f,value);return f; }
};
struct __declspec(align(16)) Vector {
 union { __m128 value; float x; };
 void set(__m128 a) { value=a; }
 __m128 get() const { return value; }
 void interpolate(const Vector& a,const Vector& b,const Scalar& scale);
 void add(const Vector& a,const Vector& b) { value=_mm_add_ps(a.value,b.value); }
 void sub(const Vector& a,const Vector& b) { value=_mm_sub_ps(a.value,b.value); }
 void scale(const Scalar& s) { value=_mm_mul_ps(s.spread(),value); }
};
struct Triple { Vector avg,mid,half; };
struct Pair { Vector low,high; };
struct Vertex { __m128 value; float unk10; float unk14; };
struct MatrixData {int f00,f04,f08,f0c,f10,f14;int f18,f1c;__m128 a,b,c;};
struct Transform {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c; __m128 m_vTranslation;};
struct Obj;
struct Engine {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6();
 virtual void getBounds(Transform* transform, float value, Pair* out);
 int unk04,unk08,unk0c;
};
struct Obj {Engine* m_eng;int unk04;Transform* m_kMotionTransform;};
struct CollectorState {
 void* unk00;
 Vertex* m_pVertex;
 void* m_arg4;
 void* volatile m_arg7;
 void* m_arg8;
 Obj* m_obj;
 int m_18;
 int unk1c;
 int f20,f24; union { int f28bits; float f28; }; int f2c,f30,f34,f38,f3c;
 __m128 m40,m50,m60,m70;
 float f80,f84;
 float* m_88;
 void FUN_00d984b0(void* arg1, Obj* arg2, Vertex* arg3, void* arg4, MatrixData* arg5, FloatPtr arg6, void* volatile arg7, void* volatile arg8);
};
extern "C" const __m128 DAT_010ec7f0={1,1,1,1};
extern "C" const float DAT_01016248=0.5f;
inline void Vector::interpolate(const Vector& a,const Vector& b,const Scalar& scale) {
 __m128 weight=scale.spread();
 __m128 opposite=_mm_sub_ps(DAT_010ec7f0,weight);
 value=_mm_add_ps(_mm_mul_ps(opposite,a.value),_mm_mul_ps(b.value,weight));
}
namespace SimpleQuad { class ByteAnswer { public: unsigned char m_value; }; }
// @fnv 0x00d984b0
void CollectorState::FUN_00d984b0(void* arg1, Obj* arg2, Vertex* arg3, void* arg4, MatrixData* arg5, FloatPtr arg6, void* volatile arg7, void* volatile arg8)
{
    m_arg7=arg7;
    m_arg8=arg8;
    m_arg4=arg4;
    m_pVertex=arg3;
    m_obj=arg2;
    m_18=arg2->m_eng->unk0c;
    f20=arg5->f00; f24=arg5->f04; f28bits=arg5->f08; f2c=arg5->f0c; f30=arg5->f10; f34=arg5->f14;
    m40=arg5->a; m50=arg5->b; m60=arg5->c;
    m_88=arg6.p;
    struct Metrics {float distance,radius;}; Metrics metrics;
    metrics.radius = arg3->unk14;
    Vector diff;
    m70=_mm_sub_ps(arg3->value,arg2->m_kMotionTransform->m_vTranslation);
    diff.set(m70);
    __m128 sq=_mm_mul_ps(m70,m70);
    __m128 y=_mm_shuffle_ps(sq,sq,0x55);
    __m128 z=_mm_shuffle_ps(sq,sq,0xaa);
    __m128 sum;
    sum = _mm_add_ss(z,_mm_add_ss(y,sq));
    __m128 root=_mm_sqrt_ss(sum);
    _mm_store_ss(&metrics.distance,root);f84=metrics.distance;
    Pair out;
    f28=metrics.radius;
    arg2->m_eng->getBounds(arg2->m_kMotionTransform,arg3->unk14,&out);

    Pair* box=&out;
    Triple temp;
    temp.avg.interpolate(box->low,box->high,Scalar(DAT_01016248));
    temp.mid.add(temp.avg,diff);
    temp.half.sub(box->high,box->low);
    temp.half.scale(Scalar(DAT_01016248));
    f80=arg3->unk10;
    ::FUN_00df2750((const ::SimpleQuad::PTree *)arg1, *(::SimpleQuad::PCast *)&temp, (::SimpleQuad::PCollector *)this, *arg6.p);
}
#include "generated/data/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.inc"


// Records a monitor event, calls FUN_00d09df0 on first update or FUN_00d099d0 otherwise, sets dirty, and records a closing monitor event.
// @fnv 0x00d0a060
void UpdateOwner::FUN_00d0a060(void* a, void* b) {
    void* (*getTls)(unsigned long) = TlsGetValue;
    MonitorStream* stream = (MonitorStream*)getTls((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    MonitorEvent* event = stream->current;
    if (event < stream->end) {
        event->tag = DAT_010cd234;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        event->time = stamp;
        stream->current = event + 1;
    }
    dirty = true;
    if (!initialized) {
        reinterpret_cast<::EntListSelf *>(this)->FUN_00d09df0(a,b);
        initialized = true;
        MonitorStream* tail = (MonitorStream*)getTls((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
        MonitorEvent* e = tail->current;
        if (e < tail->end) {
            e->tag = DAT_010c41f8;
            _ReadWriteBarrier();
            volatile unsigned int stamp = (unsigned int)__rdtsc();
            e->time = stamp;
            tail->current = e + 1;
        }
        return;
    }
    reinterpret_cast<::UpdateState *>(this)->FUN_00d099d0(a, b);
    MonitorStream* tail = (MonitorStream*)getTls((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    MonitorEvent* e = tail->current;
    if (e < tail->end) {
        e->tag = DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        e->time = stamp;
        tail->current = e + 1;
    }
}

// Builds the active tree for this entity list, dispatching to targets and optionally updating the tree with the provided parameters.
// @fnv 0x00d09df0
void EntListSelf::FUN_00d09df0(void* p1, void* p2)
{
    volatile unsigned int stamp;
    MarkerBuf* (*getBuf)(int) = (MarkerBuf* (*)(int))DAT_00fdf044;
    TempArr arr;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_capFlags = (int)0x80000000;

    mark16(getBuf((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))), "LtActiveTree", &DAT_010cd154, &stamp);

    m_entSize = 0;
    FUN_00d08ac0((hkArray<Target*>*)&m_entData, m_28);
    if (!m_enabled)
        FUN_00d08b90(*(hkArrayD08C<int*>*)&m_entData, (hkpWorldB90*)m_28);

    for (int i = 0; i < m_entSize; i++)
        DispatchToOffsetTarget(m_entData[i], 0xffff);

    mark12(getBuf((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))), &DAT_010cd14c, &stamp);
    mark12(getBuf((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))), &DAT_010cd140, &stamp);

    reinterpret_cast<::hkObjD099 *>((((ActiveTreeBuilder*)this)))->FUN_00d099a0(&m_entData, p1, p2);

    mark12(getBuf((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))), &(*reinterpret_cast<char *>((void *)&::str_01076f38)), &stamp);

    if (m_enabled) {
        mark16(getBuf((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))), &DAT_010cd214, &DAT_010cd154, &stamp);
        arr.m_iElementCount = 0;
        FUN_00d08b90(*(hkArrayD08C<int*>*)&arr, (hkpWorldB90*)m_28);
        mark12(getBuf((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))), &DAT_010cd14c, &stamp);
        reinterpret_cast<::FUN_00d9bed0_cls *>((m_0c))->FUN_00d9bed0();
        mark12(getBuf((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))), &DAT_010cd140, &stamp);
        reinterpret_cast<::S00d09020_This *>((((D09020Cls*)this)))->FUN_00d09020((::S00d09020_Arg *)(&arr), p1, p2);
        mark12(getBuf((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))), &(*reinterpret_cast<char *>((void *)&::str_01076f38)), (volatile unsigned int*)&p2);
    }

    reinterpret_cast<::FUN_00d08550_Class *>((((TreeCleanMarker*)this)))->FUN_00d08550();

    arr.destroy();
}

// If m_10 or m_24 is set, builds a local S00d08740_coll with DAT_0104da4c and calls FUN_00d984b0 or FUN_00d9a2a0 with the given pointers.
// @fnv 0x00d08740
void S00d08740_cls::Collect(void* kFrom, void* kTo, void* pkRoot, void* pkFilter, void* pkShapeFilter, void* pkOutput, void* pkCollector)
{
    if (m_10) {
        CollectorState kCollector;
        kCollector.unk00 = &DAT_010ccfcc;
        kCollector.f24 = 0;
        kCollector.f80 = ::DAT_0104da4c;
        kCollector.FUN_00d984b0(m_10, (Obj*)kFrom, (Vertex*)kTo, pkRoot, (MatrixData*)pkFilter, FloatPtr((float*)pkShapeFilter), pkOutput, pkCollector);
    }
    if (m_24) {
        S00d08740_coll kCollector;
        kCollector.m_00 = &DAT_010ccfec;
        kCollector.m_04 = &DAT_010ccfe0;
        kCollector.m_24 = 0;
        kCollector.m_80 = ::DAT_0104da4c;
        reinterpret_cast<::linear_cast_d9a2a0::PathBuilder *>(&(kCollector))->FUN_00d9a2a0(m_0c, (::linear_cast_d9a2a0::Param2 *)(kFrom), (::linear_cast_d9a2a0::Param3 *)(kTo), pkRoot, (::linear_cast_d9a2a0::Embedded5 *)(pkFilter), pkShapeFilter, pkOutput, pkCollector);
    }
}

// Initialises a local collector with DAT_010ccfcc and DAT_0104da4c, then calls FUN_00d984b0 with m_10 and the seven arguments.
// @fnv 0x00d0a490
void S00d0a490_cls::CallSubroutine(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6)
{
    CollectorState o;
    o.unk00 = &DAT_010ccfcc;
    o.f80 = ::DAT_0104da4c;
    o.f24 = 0;
    o.FUN_00d984b0(m_10, (Obj*)a0, (Vertex*)a1, a2, (MatrixData*)a3, FloatPtr((float*)a4), a5, a6);
}
