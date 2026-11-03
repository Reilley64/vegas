
// src/havok/physics/dynamics/constraint/hkpconstraintinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/hkpconstraintinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <xmmintrin.h>
#include <new>
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00cb0a60.h"
#include "fnv/decl/FnvCpu_FUN_00d541b0_CpuObject.h"
#include "fnv/decl/HingeClass.h"
#include "fnv/decl/MalleableGetterStandIn.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/decl/fnv_00cbe400__hkpHingeConstraintDataEx.h"
#include "fnv/decl/fnv_00d4e960__WheelConstraintLayout.h"
#include "fnv/decl/fnv_00d849a0__Cls_d849a0.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpPrismaticConstraintDataEx.h"
#include "fnv/decl/hkpRagdollConstraintDataBodySpace.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cb3000.h"
#include "fnv/symbols_00cdf000.h"
#include "fnv/symbols_00ce0000.h"
#include "fnv/symbols_00cf3000.h"
#include "fnv/symbols_00d06000.h"
#include "fnv/symbols_00d27000.h"
#include "fnv/symbols_00d84000.h"
#include "fnv/symbols_00d85000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010cc000.h"
#include "havok/hkpConstraintInstance.h"


struct FUN_00cf3d90_class
{
    void* m0;
    void* m1;
    void* m2;
    void* m3;
    void FUN_00cf3d90();
};

// @fnv 0x00cf3d90
void FUN_00cf3d90_class::FUN_00cf3d90()
{
    ::EnableConstraintsAndZeroArrays((::CE0020Target *)(void *)(this), (::CE0020Subject *)(m2));
}

struct FUN_00cf3070_class
{
    void* m0;
    void* m1;
    void* m2;
    void* m3;
    void* m4;
    void* m5;
    void* m6;
    void* m7;
    void* m8;
    void* m9;
    void* mA;
    void* mB;
    void* mC;
    void* mD;
    void* mE;
    void* mF;
    void* m10;
    void* m11;
    void* m12;
    void* m13;
    void* m14;
    void* m15;
    void* m16;
    void* m17;
    void* m18;
    void* m19;
    void* m1A;
    void* m1B;
    void* m1C;
    void* m1D;
    void* m1E;
    void* m1F;
    void* m20;
    void* m21;
    void* m22;
    void* m23;
    void* m24;
    void* m25;
    void* m26;
    void* m27;
    void* m28;
    void* m29;
    void* m2A;
    void* m2B;
    void* m2C;
    void* m2D;
    void* m2E;
    void* m2F;
    void* m30;
    void SetActive(bool);
};
// @fnv 0x00cf3070
void FUN_00cf3070_class::SetActive(bool active)
{
    *(char*)((char*)this + 0x1c) = active;
    void* p = this->mC;
    if (p)
        *(char*)((char*)p + 0x13) = active;
}

struct FUN_00cf3090_class
{
    void* m0;
    void* m1;
    void* m2;
    void* m3;
    void FUN_00cf3090(void* arg);
};
// If m2 is set, calls FUN_00cb3dd0 with the pointer at arg+8, this, and 1.
// @fnv 0x00cf3090
void FUN_00cf3090_class::FUN_00cf3090(void* arg)
{
    if (m2)
        ::FUN_00cb3dd0((::CB3DD0World *)(*(void**)((char*)arg + 8)), (::CB3DD0Entity *)(void *)(this), 1);
}

// @fnv 0x00cf3da0
void FUN_00cf3da0(void* self, int)
{
    ::FUN_00cdff60(self, (::ConstraintInput *)(*(void**)((char*)self + 8)));
}

struct DDCC60World
{
};
struct RefObj
{
};
struct FUN_00cf3000_class
{
    void* m0;
    void* m1;
    void* m2;
    void* m3;
    void* m4;
    void* m5;
    void ReplaceReference(void* arg1, void* arg2);
};
// @fnv 0x00cf3000
void FUN_00cf3000_class::ReplaceReference(void* apOldRef, void* apNewRef)
{
    int idx = (apOldRef != m5) ? 1 : 0;
    reinterpret_cast<::FUN_00c90510_class *>((((RefObj*)apNewRef)))->FUN_00c90510();
    if (apOldRef)
        reinterpret_cast<::hkReferencedObjectC905 *>((((DDCC60World*)apOldRef)))->FUN_00c905b0();
    (&m5)[idx] = apNewRef;
}

namespace fnv_00cf3040 {
struct DDCC60World
{
};
struct FUN_00cf3040_class
{
    void* m0;
    void* m1;
    void* m2;
    void* m3;
    void* m4;
    void* m5;
    void* m6;
    void* m7;
    void RemoveReferenceFromSlots(void* arg);
};
// Scans two pointers at this+0x14 and, when one matches the pointer at arg+0x24, calls removeReference on it and clears that slot.
// @fnv 0x00cf3040
void FUN_00cf3040_class::RemoveReferenceFromSlots(void* arg)
{
    for (int i = 0; i < 2; ++i)
    {
        DDCC60World* p = (DDCC60World*)*(&this->m5 + i);
        if (p == *(DDCC60World**)((char*)arg + 0x24))
        {
            reinterpret_cast<::hkReferencedObjectC905 *>((p))->FUN_00c905b0();
            *(void**)((char*)&this->m5 + i * 4) = 0;
        }
    }
}
}  // namespace fnv_00cf3040

namespace fnv_00cf3e60 {
struct RefObj
{
};

struct FUN_00cf3e60_class : public hkReferencedObject
{
    void* m_pOwnerObject;
    unsigned char m_ucUnknownByte[8];
    void* m_kActorEntries[8];

    void FUN_00cf3e60();
};

// @fnv 0x00cf3e60
void FUN_00cf3e60_class::FUN_00cf3e60()
{
    for (int i = 0; i < 2; ++i)
    {
        if (m_kActorEntries[i] == 0)
        {
            void* other = reinterpret_cast<void*>(reinterpret_cast<unsigned int>(m_kActorEntries[1]) ^
                                                  reinterpret_cast<unsigned int>(m_kActorEntries[0]) ^
                                                  reinterpret_cast<unsigned int>(m_kActorEntries[i]));

            if (other != 0)
            {
                void* constraint = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(other) + 0x08);

                if (constraint != 0)
                {
                    void* referenced = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(constraint) + 0x24);

                    m_kActorEntries[i] = referenced;
                    reinterpret_cast<::FUN_00c90510_class *>((reinterpret_cast<RefObj*>(referenced)))->FUN_00c90510();
                }
            }
        }
    }
}
}  // namespace fnv_00cf3e60

// @fnv 0x00cf2f90
void FUN_00cf2f90(int)
{}

// @fnv 0x00cf2fa0
void FUN_00cf2fa0(int)
{}

struct hkBoolCF2F
{
    char m_cBooleanValue;
    hkBoolCF2F(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkInnerCF2F
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    void* m_pOwnerObject;
};

struct hkLinkCF2F
{
    int m_00;
    int m_04;
    hkInnerCF2F* m_inner;
};

class FUN_00cf2fb0_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    hkLinkCF2F* m_link;
    void* m_pOwnerObject;

    hkBoolCF2F FUN_00cf2fb0() const;
};

// @fnv 0x00cf2fb0
hkBoolCF2F FUN_00cf2fb0_cls::FUN_00cf2fb0() const
{
    return m_pOwnerObject == 0 || (m_link->m_inner && m_pOwnerObject == m_link->m_inner->m_pOwnerObject);
}

namespace fnv_00cf2fe0 {
struct hkBoolCF2F
{
    char m_cBooleanValue;
    hkBoolCF2F(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};


class FUN_00cf2fe0_cls
{
  public:
    int m_00;

    hkBoolCF2F FUN_00cf2fe0() const;
};

// @fnv 0x00cf2fe0
hkBoolCF2F FUN_00cf2fe0_cls::FUN_00cf2fe0() const
{
    return ((int)(::FindModifierConstraintAtom((::hkpConstraintInstance *)(this), 0x1b))) == 0;
}
}  // namespace fnv_00cf2fe0

class hkObjCF30
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    void** m_items;
    unsigned short m_numItems;

    int indexOf(void* pv) const
    {
        for (int i = 0; i < m_numItems; i++)
        {
            if (m_items[i] == pv)
                return i;
        }
        return -1;
    }

    void FUN_00cf30b0(void* pv);
};

// Finds pv in m_items via indexOf and sets that slot to null.
// @fnv 0x00cf30b0
void hkObjCF30::FUN_00cf30b0(void* apItem)
{
    m_items[indexOf(apItem)] = 0;
}

struct hkVector4CF3D
{
    float x;
    float y;
    float z;
    float w;
};

class hkpEntityCF3D
{
  public:
    hkVector4CF3D unk00;
    hkVector4CF3D unk10;
    hkVector4CF3D unk20;
    hkVector4CF3D unk30;
    hkVector4CF3D unk40;
    hkVector4CF3D unk50;
    hkVector4CF3D unk60;
    hkVector4CF3D unk70;
    hkVector4CF3D unk80;
    hkVector4CF3D unk90;
    hkVector4CF3D unkA0;
    hkVector4CF3D unkB0;
    int unkC0;
    int unkC4;
    int unkC8;
    int m_cc;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char m_bFlag;
};

class hkpPairCF3D
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkpEntityCF3D* m_pEntityA;
    hkpEntityCF3D* m_pEntityB;

    int FUN_00cf3dd0() const;
};

// @fnv 0x00cf3dd0
int hkpPairCF3D::FUN_00cf3dd0() const
{
    const hkpEntityCF3D* pkEntity = m_pEntityA;
    if (pkEntity->m_bFlag != 5)
        return pkEntity->m_cc;
    return m_pEntityB->m_cc;
}

struct hkAllocatorCF3F
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterCF3F
{
    void* m_apvUnk00[4];
    hkAllocatorCF3F* m_pkHeap;
    hkAllocatorCF3F& heap()
    {
        return *m_pkHeap;
    }
};


struct hkBoolCF3F
{
    char m_bValue;
    hkBoolCF3F() throw()
    {}
};

class hkpConstraintData : public hkReferencedObject
{
  public:
};


struct FUN_00cb0c10_s
{
    char* m_pcString;
};

class FUN_00cf3ea0 : public hkpConstraintInstance
{
  public:
    static __forceinline void* operator new(size_t uiSize) throw()
    {
        void* p = static_cast<hkMemoryRouterCF3F*>(::FUN_00c85750())->heap().AllocateMemoryBlock(uiSize);
        ((unsigned short*)p)[2] = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();
    FUN_00cf3ea0(hkpEntity* pkEntityA, hkpEntity* pkEntityB, hkpConstraintData* pkData,
                 ConstraintPriority ePriority) throw();
};

class hkpConstraintInstanceCF3F : public hkpConstraintInstance
{
  public:
    hkBoolCF3F FUN_00cf2fb0() const throw();
    hkpConstraintData* getData() const
    {
        return m_data;
    }
    ConstraintPriority getPriority() const
    {
        return (ConstraintPriority)m_priority;
    }
    hkpConstraintInstance* FUN_00cf3fa0(hkpEntity* pkEntityA, hkpEntity* pkEntityB, int eMode) const throw();
};

// Creates a new constraint instance from this one according to eMode, copying the name and returning the new instance.
// @fnv 0x00cf3fa0
hkpConstraintInstance* hkpConstraintInstanceCF3F::FUN_00cf3fa0(hkpEntity* pkEntityA, hkpEntity* pkEntityB,
                                                               int eCloneMode) const throw()
{
    hkpConstraintInstance* pkInstance;
    if (eCloneMode == CLONE_INSTANCES_ONLY)
    {
        if (FUN_00cf2fb0().m_bValue)
        {
            hkpConstraintData* pkData = ((::hkpConstraintData *)(::FUN_00d85700((::Object858 *)(getData()))));
            pkInstance = new FUN_00cf3ea0(pkEntityA, 0, pkData, getPriority());
            reinterpret_cast<::hkReferencedObjectC905 *>((pkData))->FUN_00c905b0();
        }
        else
            pkInstance = new FUN_00cf3ea0(pkEntityA, pkEntityB, getData(), getPriority());
    }
    else if (eCloneMode == CLONE_DATAS_WITH_MOTORS)
    {
        hkpConstraintData* pkData = ((::hkpConstraintData *)(::FUN_00d858f0((::Object858 *)(getData()))));
        if (!pkData)
        {
            pkData = getData();
            reinterpret_cast<::FUN_00c90510_class *>((pkData))->FUN_00c90510();
        }
        pkInstance = new FUN_00cf3ea0(pkEntityA, pkEntityB, pkData, getPriority());
        reinterpret_cast<::hkReferencedObjectC905 *>((pkData))->FUN_00c905b0();
    }
    else
        pkInstance = new FUN_00cf3ea0(pkEntityA, pkEntityB, getData(), getPriority());
    reinterpret_cast<::SStringPtr *>((((FUN_00cb0c10_s*)&pkInstance->m_name)))->FUN_00cb0c10((const char*)((hkUlong)m_name & ~1));
    return pkInstance;
}

namespace fnv_00cf40b0 {



struct MemAllocator
{
    virtual void dummy0() throw();
    virtual void dummy1() throw();
    virtual void deallocate(void* p, int size) throw();
};

struct ThreadMemory
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    MemAllocator* m_pMemoryAllocator;
    inline void deallocate(void* p, int size) throw()
    {
        m_pMemoryAllocator->deallocate(p, size);
    }
};

static inline void hkDeallocate(void* p, int size) throw()
{
    ((ThreadMemory*)::FUN_00c85750())->deallocate(p, size);
}

struct FUN_00cb0c00_class
{
};

struct ModifierAtom
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short m_usModifierAtomSize;
    unsigned short unk12;
    ModifierAtom* m_pChildAtom;
};

struct FUN_00cf40b0_class : public hkpConstraintInstance
{
    void FUN_00cf40b0();
};

// @fnv 0x00cf40b0
void FUN_00cf40b0_class::FUN_00cf40b0()
{
    *(void**)this = &(*reinterpret_cast<void * *>((void *)&::sd6ae50::DAT_010cc040));
    ::FUN_00d85ef0((::ListenerOwner *)(void *)(this));
    if (m_kActorEntries[0])
        reinterpret_cast<::hkReferencedObjectC905 *>((m_kActorEntries[0]))->FUN_00c905b0();
    if (m_kActorEntries[1])
        reinterpret_cast<::hkReferencedObjectC905 *>((m_kActorEntries[1]))->FUN_00c905b0();
    ModifierAtom* mod = (ModifierAtom*)m_pConstraintModifier;
    if (mod != 0 && mod->m_type >= 0x17)
    {
        do
        {
            ModifierAtom* cur = mod;
            mod = cur->m_pChildAtom;
            hkDeallocate(cur, cur->m_usModifierAtomSize);
        } while (mod->m_type >= 0x17);
    }
    if (m_data)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_data))->FUN_00c905b0();
    ::FUN_00cb0c00((intptr_t)(((FUN_00cb0c00_class*)&m_name)));
    if ((m_kListeners.m_iCapacityState & 0x8000) == 0)
    {
        int capacity = m_kListeners.m_iCapacityState & 0x3fff;
        hkDeallocate(m_kListeners.m_data, capacity * 4);
    }
    *(void**)this = &::DAT_0102e388;
}
}  // namespace fnv_00cf40b0

namespace fnv_00cf4160 {
class hkMemoryAllocatorCF41
{
  public:
    virtual ~hkMemoryAllocatorCF41() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCF41
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF41* m_pStreamAllocator;
    hkMemoryAllocatorCF41& heap()
    {
        return *m_pStreamAllocator;
    }
};


class FUN_00cf40b0
{
  public:
    virtual ~FUN_00cf40b0() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        (*static_cast<hkMemoryRouterCF41*>(::FUN_00c85750())).heap().ReleaseBlock(p, static_cast<FUN_00cf40b0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00cf40b0* FUN_00cf4160(unsigned int uiFlags) throw();
};

// Destructs the object, then frees it via operator delete when uiFlags has bit 0 set, and returns this.
// @fnv 0x00cf4160
FUN_00cf40b0* FUN_00cf40b0::FUN_00cf4160(unsigned int uiFlags) throw()
{
    reinterpret_cast<::fnv_00cf40b0::FUN_00cf40b0_class *>((this))->FUN_00cf40b0();
    if (uiFlags & 1)
        FUN_00cf40b0::operator delete(this);
    return this;
}
}  // namespace fnv_00cf4160

struct hkpModifierConstraintAtom
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkpModifierConstraintAtom* m_pChildAtom;
};

// Walks the modifier atom chain of a constraint instance and returns the first atom whose m_type equals type, or null if none matches.
// @fnv 0x00d277c0
hkpModifierConstraintAtom* __cdecl FindModifierConstraintAtom(hkpConstraintInstance* aConstraintInstance,
                                                              unsigned int type)
{
    hkpModifierConstraintAtom* atom = aConstraintInstance->m_pConstraintModifier;
    if (!atom)
        return 0;

    while (atom->m_type != type)
    {
        if (atom->m_pChildAtom->m_type < 0x17)
            return 0;
        atom = atom->m_pChildAtom;
    }
    return atom;
}

extern "C" void _ReadWriteBarrier();

struct S00cf3df0_Arr
{
    void** m_data;
    unsigned short m_iElementCount;
    unsigned short m_cap;
    __forceinline void put(void* a)
    {
        unsigned short n = m_iElementCount;

        int i = 0;
        if (i < n)
        {
            void** d = m_data;
            void** p = d;
            do
            {
                if (*p == 0)
                {
                    if (i >= 0)
                    {
                        d[i] = a;
                        return;
                    }
                    break;
                }
                _ReadWriteBarrier();
                i++;
                p++;
            } while (i < m_iElementCount);
        }
        if (n == (m_cap & 0x3fff))
            ::FUN_00d06cb0((::GrowBuf *)(void *)(this), 4);
        m_data[m_iElementCount++] = a;
    }
};

struct S00cf3df0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S00cf3df0_Arr m_l;
    void Add(void* a);
};

// Adds the given pointer to the m_l array by calling m_l.put.
// @fnv 0x00cf3df0
void S00cf3df0_Obj::Add(void* apItem)
{
    m_l.put(apItem);
}

struct Matrix4f;
struct CVector
{
    __m128 m;
    void FUN_00c7f640(Matrix4f*, CVector*);
    void FUN_00c7f700(Matrix4f*, CVector*);
};
struct __declspec(align(16)) Matrix4f
{
    CVector c0, c1, c2, c3;
};
struct ConstraintReference;
struct ConstraintReferencedBase
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual unsigned getType() const;
    unsigned unk04;
};
struct ConstraintReference : ConstraintReferencedBase
{
    unsigned unk08, unk0c, unk10, unk14;
    ConstraintReference* child18;
    unsigned unk1c;
    Matrix4f a, b, c, d;
    unsigned unk120;
};
struct CPlaneData
{
    void* vptr;
    unsigned unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Matrix4f a;
    CVector axes[3];
    CVector position;
    unsigned char unkA0, unkA1, axis, unkA3;
};
struct CDirectData
{
    void* vptr;
    unsigned unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    CVector axis, position;
    float unk40, value;
};
struct CBoolean
{
    char b;
    CBoolean() throw()
    {}
    operator bool() const
    {
        return b != 0;
    }
};
struct CInstance
{
    unsigned unk00, unk04, unk08;
    ConstraintReference* data;
    CBoolean FUN_00cf2fb0();
    void FUN_00cf30f0(Matrix4f*);
};
static __forceinline void point(CVector& v, Matrix4f* t)
{
    v.FUN_00c7f640(t, &v);
}
static __forceinline void rotate(CVector& v, Matrix4f* t)
{
    v.FUN_00c7f700(t, &v);
}
static __forceinline CVector getVector(const CVector& s)
{
    return s;
}
static __forceinline void copyTransform(Matrix4f& d, const Matrix4f& s)
{
    CVector c0 = s.c0, c1 = s.c1, c2 = s.c2, c3 = s.c3;
    d.c0.m = c0.m;
    d.c1.m = c1.m;
    d.c2.m = c2.m;
    d.c3.m = c3.m;
}

// Applies the given Matrix4f transform to the constraint data referenced by this instance, dispatching on the constraint type.
// @fnv 0x00cf30f0
void CInstance::FUN_00cf30f0(Matrix4f* apTransform)
{
    if (!FUN_00cf2fb0())
        return;
    ConstraintReference* p = data;
    for (;;)
        switch (p->getType())
        {
        case 12:
            p = p->child18;
            break;
        case 13:
            p = ((::ConstraintReference *)(reinterpret_cast<::MalleableGetterStandIn *>((p))->FUN_00cdf6c0()));
            break;
        case 0:
            point(p->a.c1, apTransform);
            reinterpret_cast<::FnvCpu_FUN_00d541b0_CpuObject *>((p))->FUN_00d541b0((::FnvCpu_FUN_00d541b0_CpuData0 *)(::CVector *)(&p->a.c0), (::FnvCpu_FUN_00d541b0_CpuData1 *)(::CVector *)(&p->a.c1));
            return;
        case 1: {
            Matrix4f a, b;
            copyTransform(a, p->a);
            copyTransform(b, p->b);
            CVector ax = a.c0, bx = b.c0;
            point(b.c3, apTransform);
            rotate(bx, apTransform);
            reinterpret_cast<::fnv_00cbe400::hkpHingeConstraintDataEx *>((p))->FUN_00cbe400((*(const ::hkVector4 *)(&a.c3)), (*(const ::hkVector4 *)(&b.c3)), (*(const ::hkVector4 *)(&ax)), (*(const ::hkVector4 *)(&bx)));
            return;
        }
        case 2: {
            Matrix4f a, b;
            copyTransform(a, p->a);
            copyTransform(b, p->b);
            CVector ax = a.c0, bx = b.c0, ay = a.c1, by = b.c1;
            point(b.c3, apTransform);
            rotate(bx, apTransform);
            rotate(by, apTransform);
            reinterpret_cast<::HingeClass *>((p))->FUN_00cb8da0((*(const ::hkVector4_Havok *)(&a.c3)), (*(const ::hkVector4_Havok *)(&b.c3)), (*(const ::hkVector4_Havok *)(&ax)), (*(const ::hkVector4_Havok *)(&bx)), (*(const ::hkVector4_Havok *)(&ay)), (*(const ::hkVector4_Havok *)(&by)));
            return;
        }
        case 14: {
            CPlaneData* __restrict q = (CPlaneData*)p;
            CVector a = q->a.c3, b = q->position, axis = q->axes[q->axis];
            point(b, apTransform);
            rotate(axis, apTransform);
            reinterpret_cast<::fnv_00d849a0::Cls_d849a0 *>((p))->SetBasis((*(const ::fnv_00d849a0::Vec_d849a0 *)(&a)), (*(const ::fnv_00d849a0::Vec_d849a0 *)(&b)), (*(const ::fnv_00d849a0::Vec_d849a0 *)(&axis)));
            return;
        }
        case 6: {
            Matrix4f a, b;
            copyTransform(a, p->a);
            copyTransform(b, p->b);
            CVector ap = a.c0, aa = a.c1, at = a.c3, bp = b.c0, ba = b.c1, bt = b.c3;
            point(bt, apTransform);
            rotate(bp, apTransform);
            rotate(ba, apTransform);
            reinterpret_cast<::hkpPrismaticConstraintDataEx *>((p))->FUN_00d4fba0((*(const ::hkVector4 *)(&at)), (*(const ::hkVector4 *)(&bt)), (*(const ::hkVector4 *)(&ap)), (*(const ::hkVector4 *)(&bp)), (*(const ::hkVector4 *)(&aa)), (*(const ::hkVector4 *)(&ba)));
            return;
        }
        case 7: {
            Matrix4f a, b;
            copyTransform(a, p->a);
            copyTransform(b, p->b);
            Matrix4f& ta = p->a;
            Matrix4f& tb = p->b;
            CVector& b1 = tb.c1;
            point(b.c3, apTransform);
            rotate(b1, apTransform);
            rotate(tb.c0, apTransform);
            reinterpret_cast<::hkpRagdollConstraintDataBodySpace *>((p))->FUN_00cded30((*(const ::hkVector4 *)(&a.c3)), (*(const ::hkVector4 *)(&b.c3)), (*(const ::hkVector4 *)(&ta.c1)), (*(const ::hkVector4 *)(&b1)), (*(const ::hkVector4 *)(&ta.c0)), (*(const ::hkVector4 *)(&tb.c0)));
            return;
        }
        case 8: {
            CDirectData* q = (CDirectData*)p;
            CVector axis = q->axis, position = q->position;
            float value = q->value;
            point(position, apTransform);
            q->axis.m = axis.m;
            q->position.m = position.m;
            q->value = value;
            return;
        }
        case 9: {
            CVector a = p->a.c3, b = p->b.c3, ax = p->b.c0, ay = p->c.c3, by = p->d.c2;
            point(b, apTransform);
            CVector az = p->d.c3;
            rotate(ax, apTransform);
            rotate(by, apTransform);
            rotate(az, apTransform);
            reinterpret_cast<::fnv_00d4e960::WheelConstraintLayout *>((p))->FUN_00d4e960((*(const ::hkVector4 *)(&a)), (*(const ::hkVector4 *)(&b)), (*(const ::hkVector4 *)(&ay)), (*(const ::hkVector4 *)(&by)), (*(const ::hkVector4 *)(&ax)), (*(const ::hkVector4 *)(&az)));
            return;
        }
        default:
            return;
        }
}


struct TargetObj
{
    char pad[0x18];
    void* unk18;
};

struct ReceiverObj
{
    void FUN_00c7f640(void* pTarget, hkVector4* pVec);
};

class FUN_00cf3c90_cls
{
  public:
    char pad0[0xc];
    void* m_obj0C;
    char pad1[4];
    TargetObj* m_target14;
    TargetObj* m_target18;

    void FUN_00cf3c90(ReceiverObj* first, ReceiverObj* second);
};

// Copies two vectors obtained from m_obj0C, then calls FUN_00c7f640 on first and second with m_target14->unk18 and m_target18->unk18 and the matching vector.
// @fnv 0x00cf3c90
void FUN_00cf3c90_cls::FUN_00cf3c90(ReceiverObj* apFirstReceiver, ReceiverObj* apSecondReceiver)
{
    __declspec(align(16)) hkVector4 vFirstVec;
    *(__m128*)&vFirstVec = *(__m128*)((::hkVector4 *)(::GetDispatchTarget((::FNVDispatchNode *)(m_obj0C))));
    __declspec(align(16)) hkVector4 vSecondVec;
    *(__m128*)&vSecondVec = *(__m128*)((::hkVector4 *)(::GetShapeData((::ShapeD84D *)(m_obj0C))));

    void* pSecondTargetPtr = m_target18->unk18;
    apFirstReceiver->FUN_00c7f640(m_target14->unk18, &vFirstVec);
    apSecondReceiver->FUN_00c7f640(pSecondTargetPtr, &vSecondVec);
}

union FUN_00cf3d00_Vec4
{
    __m128 m;
};

struct FUN_00cf3d00_Alloc
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    FUN_00cf3d00_Vec4 unk20;
    FUN_00cf3d00_Vec4 unk30;
};

struct FUN_00cf3d00_Buf
{
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    unsigned short unk12;
    unsigned short unk14;
    unsigned short unk16;
    unsigned short unk18;
    unsigned short unk1A;
    unsigned short unk1C;
    unsigned short unk1E;
    FUN_00cf3d00_Vec4 unk20;
    FUN_00cf3d00_Vec4 unk30;
};

struct FUN_00cf3d00_Obj
{
    virtual void vf00();
    virtual FUN_00cf3d00_Buf* vf04(int size);
};

struct FUN_00cf3d00_Holder
{
    void* m0;
    void* m1;
    void* m2;
    void* m3;
    FUN_00cf3d00_Obj* m4;
};


struct FUN_00cf3d00_class
{
    void* m0;
    void* m1;
    void* m2;

    void SetVec4Pair(FUN_00cf3d00_Vec4* a, FUN_00cf3d00_Vec4* b);
};

// Stores a and b in unk20 and unk30 of the atom found by FindModifierConstraintAtom(this, 0x18), or of a new 0x40-byte buffer passed to FUN_00d27960.
// @fnv 0x00cf3d00
void FUN_00cf3d00_class::SetVec4Pair(FUN_00cf3d00_Vec4* a, FUN_00cf3d00_Vec4* b)
{
    FUN_00cf3d00_Alloc* pAtom = (FUN_00cf3d00_Alloc*)((void *)(::FindModifierConstraintAtom((::hkpConstraintInstance *)(void *)(this), 0x18)));

    if (pAtom != 0)
    {
        pAtom->unk20.m = a->m;
        pAtom->unk30.m = b->m;
        return;
    }

    FUN_00cf3d00_Holder* holder = (FUN_00cf3d00_Holder*)static_cast<hkMemoryRouterCF3F*>(::FUN_00c85750());
    FUN_00cf3d00_Buf* buf = holder->m4->vf04(0x40);

    if (buf != 0)
    {
        buf->unk00 = 0x18;
        buf->unk10 = 0x40;
    }
    else
    {
        buf = 0;
    }

    buf->unk20.m = a->m;
    buf->unk30.m = b->m;

    ::FUN_00d27960((::hkpConstraintInstance *)(void *)(this), (*(::hkpConstraintOwner *)(m2)), (::hkpModifierConstraintAtom *)(buf));
}


struct CF3F40Member
{
};

struct S00cf3f40_Obj
{
    void* m_vptr;
    unsigned short m_iWordAt04;
    short m_6;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    unsigned char m_1c;
    unsigned char m_1d;
    unsigned char m_1e;
    char m_1f;
    int m_20;
    short m_24;
    unsigned short m_26;
    CF3F40Member m_28;
    int m_2c;
    int m_30;
    int m_34;

    S00cf3f40_Obj* FUN_00cf3f40(bool flag);
};

// Sets the vtable pointer, zeroes most fields, sets m_6 to 1, m_1c to flag, m_1d to 1, m_26 to 0x8000, m_34 to -16, and calls m_28.FUN_00cb0a60().
// @fnv 0x00cf3f40
S00cf3f40_Obj* S00cf3f40_Obj::FUN_00cf3f40(bool flag)
{
    int z = 0;
    *(void* volatile*)&m_vptr = (void*)&(*reinterpret_cast<char *>((void *)&::sd6ae50::DAT_010cc040));
    m_10 = m_8 = z;
    *(volatile short*)&m_6 = 1;
    *(volatile unsigned char*)&m_1c = flag;
    *(volatile unsigned char*)&m_1d = 1;
    *(volatile unsigned char*)&m_1e = z;
    _ReadWriteBarrier();
    *(volatile int*)&m_20 = z;
    m_24 = 0;
    m_26 = 0x8000;
    new ((void *)&(m_28)) struct ::FUN_00cb0a60();
    m_2c = z;
    m_30 = z;
    m_34 = -16;
    return this;
}

struct ConstraintEnabledDispatch : public hkpConstraintInstance
{
    void FUN_00cf3db0(hkBool enabled);
};

// @fnv 0x00cf3db0
void ConstraintEnabledDispatch::FUN_00cf3db0(hkBool enabled)
{
    if (enabled)
    {
        reinterpret_cast<::FUN_00cf3d90_class *>(this)->FUN_00cf3d90();
    }
    else
    {
        ::FUN_00cf3da0((void *)this, {});
    }
}
