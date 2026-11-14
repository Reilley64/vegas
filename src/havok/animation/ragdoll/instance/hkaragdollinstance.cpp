
// src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/instance/hkaragdollinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <new>
#include <cstdint>
#include "fnv/decl/FUN_005611c0_t.h"
#include "fnv/decl/FUN_00c86490_Class.h"
#include "fnv/decl/Quat74.h"
#include "fnv/decl/S_00ce5070_QsTransform.h"
#include "fnv/symbols_00ce0000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0104d000.h"
#include <math.h>
#include "fnv/decl/C74C20Quat.h"
#include "fnv/symbols_00ce2000.h"
#include <cstddef>
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00ca8860_cls.h"
#include "fnv/decl/Mgr.h"
#include "fnv/decl/TW.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpConstraintInstanceCF3F.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00ce1000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010cb000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "havok/hkaRagdollInstance.h"

class hkQsTransformC17;
void FUN_00ce18d0(intptr_t a, hkQsTransformC17* pkPoseOut);


struct FUN_00ce2430_Transform
{
    unsigned char pad[0x30];
};

struct FUN_00ce2430_Data
{
    unsigned char pad[0x1c];
    int count;
};

struct FUN_00ce2430_Class
{
    unsigned char pad[0x2c];
    FUN_00ce2430_Data* data;

    void ApplyValueToTransforms(float, FUN_00ce2430_Transform*);
};

struct MemoryManager
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void release(void* object, unsigned short value);
};

struct MemoryRouter
{
    void* ReportDiagnostic;
    void* unused1;
    void* unused2;
    void* FlushUsageData;
    MemoryManager* manager;
};

struct FUN_00ce29b0_standin
{
    void FUN_00ce2600();
    void* Destroy(unsigned char deletingFlag);
};

MemoryRouter* _D1A0E0GetMemoryRouter();

// @fnv 0x00ce29b0
void* FUN_00ce29b0_standin::Destroy(unsigned char deletingFlag)
{
    FUN_00ce2600();

    if (deletingFlag & 1)
    {
        MemoryRouter* router = _D1A0E0GetMemoryRouter();
        router->manager->release(this, *(unsigned short*)((unsigned char*)this + 4));
    }

    return this;
}


struct FnvVtObj
{
    intptr_t m_vptr;

    FnvVtObj* FUN_00ce25f0(unsigned int unusedArg);
};

// @fnv 0x00ce25f0
FnvVtObj* FnvVtObj::FUN_00ce25f0(unsigned int unusedArg)
{
    m_vptr = (intptr_t)&::DAT_010cb830;
    return this;
}

struct ReferenceObject : hkReferencedObject
{
};
struct ArrayAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void* allocateBuffer(int& bytes);
    virtual void freeBuffer(void* buffer, int bytes);
};
struct ArrayRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    ArrayAllocator* m_pStreamAllocator;
};
template <class T> struct ObjectArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void assign(const ObjectArray& source)
    {
        ArrayAllocator* heap = static_cast<ArrayRouter*>(::FUN_00c85750())->m_pStreamAllocator;
        int capacity = m_iCapacityState & 0x3fffffff;
        if (capacity < source.m_iElementCount)
        {
            if (!(m_iCapacityState & 0x80000000))
                heap->freeBuffer(m_data, capacity * (int)sizeof(T));
            int bytes = source.m_iElementCount * (int)sizeof(T);
            m_data = (T*)heap->allocateBuffer(bytes);
            m_iCapacityState = bytes / (int)sizeof(T);
        }
        m_iElementCount = source.m_iElementCount;
        int count = m_iElementCount;
        T* destination = m_data;
        const T* input = source.m_data;
        for (int i = 0; i < count; ++i)
            destination[i] = input[i];
    }
};
struct RagdollInstance : hkReferencedObject
{
    ObjectArray<ReferenceObject*> m_ppRigidBodies;
    ObjectArray<ReferenceObject*> m_ppConstraints;
    ObjectArray<int> m_kBoneMap;
    ReferenceObject* m_pSkeleton;
    void FUN_00ce22c0(const ObjectArray<ReferenceObject*>& bodies, const ObjectArray<ReferenceObject*>& constraints,
                      ReferenceObject* skeleton);
};
// @fnv 0x00ce22c0
void RagdollInstance::FUN_00ce22c0(const ObjectArray<ReferenceObject*>& bodies,
                                   const ObjectArray<ReferenceObject*>& constraints, ReferenceObject* skeleton)
{
    if (skeleton)
        reinterpret_cast<::FUN_00c90510_class *>((skeleton))->FUN_00c90510();
    if (m_pSkeleton)
        reinterpret_cast<::hkReferencedObjectC905 *>((m_pSkeleton))->FUN_00c905b0();
    m_pSkeleton = skeleton;
    m_ppRigidBodies.assign(bodies);
    m_ppConstraints.assign(constraints);
    for (int i = 0; i < m_ppRigidBodies.m_iElementCount; ++i)
        if (m_ppRigidBodies[i])
            reinterpret_cast<::FUN_00c90510_class *>((m_ppRigidBodies[i]))->FUN_00c90510();
    for (int i = 0; i < m_ppConstraints.m_iElementCount; ++i)
        if (m_ppConstraints[i])
            reinterpret_cast<::FUN_00c90510_class *>((m_ppConstraints[i]))->FUN_00c90510();
}

namespace fnv_00ce2600 {
extern int DAT_010cb830;
struct FnvRefObject
{
};
struct FnvMemoryManager
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void release(void*, unsigned int) throw();
};
struct FnvRouter
{
    void* a;
    void* b;
    void* c;
    void* d;
    FnvMemoryManager* manager;
};
struct FnvArray
{
    void** data;
    int size;
    unsigned int capacityAndFlags;
    ~FnvArray() throw()
    {
        FnvRouter* router = static_cast<FnvRouter*>(::FUN_00c85750());
        FnvMemoryManager* mgr = router->manager;
        unsigned int cap = capacityAndFlags;
        size = 0;
        if (!(cap & 0x80000000u))
            mgr->release(data, (cap & 0x3fffffffu) * 4);
        data = 0;
        capacityAndFlags = 0x80000000u;
    }
};
struct FnvParent
{
    void* vtbl;
    unsigned short flags;
    short references;
    ~FnvParent() throw()
    {
        vtbl = &(*reinterpret_cast<int *>(&::DAT_0102e388));
    }
};
struct FUN_00ce2600 : FnvParent
{
    FnvArray bodies, constraints, mapping;
    FnvRefObject* skeleton;
    ~FUN_00ce2600() throw();
};
// @fnv 0x00ce2600
FUN_00ce2600::~FUN_00ce2600() throw()
{
    vtbl = &::DAT_010cb830;
    for (int i = 0; i < bodies.size; ++i)
        reinterpret_cast<::hkReferencedObjectC905 *>((((FnvRefObject*)bodies.data[i])))->FUN_00c905b0();
    for (int j = 0; j < constraints.size; ++j)
        reinterpret_cast<::hkReferencedObjectC905 *>((((FnvRefObject*)constraints.data[j])))->FUN_00c905b0();
    if (skeleton)
        reinterpret_cast<::hkReferencedObjectC905 *>((skeleton))->FUN_00c905b0();
    skeleton = 0;
}
}  // namespace fnv_00ce2600

struct FUN_00ce26f0_ObjectC
{
};

struct FUN_00ce26f0_ObjectB
{
    void* unk00;
    void* unk04;
    FUN_00ce26f0_ObjectC* unk08;
};

struct FUN_00ce26f0_ObjectA
{
    FUN_00ce26f0_ObjectB* unk00;
};

struct FUN_00ce26f0_Class
{
    int unk00;
    int unk04;
    FUN_00ce26f0_ObjectA* unk08;

    void FUN_00ce26f0(FUN_00ce2430_Transform* a);
};

// Calls FUN_00c91020 and passes its result to ApplyValueToTransforms when the nested pointer exists; otherwise calls FUN_00ce18d0.
// @fnv 0x00ce26f0
void FUN_00ce26f0_Class::FUN_00ce26f0(FUN_00ce2430_Transform* apTransform)
{
    FUN_00ce26f0_ObjectB* object = this->unk08->unk00;
    FUN_00ce26f0_ObjectC* target = object != 0 ? object->unk08 : 0;

    if (target == 0)
    {
        ::FUN_00ce18d0((intptr_t)(this), (::hkQsTransformC17 *)(apTransform));
        return;
    }

    reinterpret_cast<::FUN_00ce2430_Class *>((this))->ApplyValueToTransforms(reinterpret_cast<::CpuObject *>((target))->FUN_00c91020(), apTransform);
}

typedef std::size_t hk_size_tR;
class hkMemoryAllocatorR
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterR
{
    void* m_aiEntries;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorR* m_pStreamAllocator;
    hkMemoryAllocatorR& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterR& __cdecl GetMemoryRouterR() throw();
template <typename T> struct hkArrayR
{
    hkArrayR() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArrayR() throw()
    {
        hkMemoryAllocatorR& kAlloc = GetMemoryRouterR().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
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
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocatorR& kAlloc = GetMemoryRouterR().heap();
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T> __forceinline T* hkAllocateStackR(int n)
{
    hkMemoryRouterR& kRouter = GetMemoryRouterR();
    char* pcCur = (char*)kRouter.m_aiEntries;
    kRouter.m_aiEntries = pcCur + ((n * sizeof(T) + 0x7f) & ~0x7f);
    return (T*)pcCur;
}
template <typename T> __forceinline void hkDeallocateStackR(T* p)
{
    GetMemoryRouterR().m_aiEntries = p;
}
template <typename T> struct hkLocalArrayR : public hkArrayR<T>
{
    __forceinline hkLocalArrayR(int n) throw()
    {
        T* pLocal = hkAllocateStackR<T>(n);
        this->m_data = pLocal;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = pLocal;
    }
    __forceinline ~hkLocalArrayR() throw()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        hkDeallocateStackR(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};
class hkReferencedObjectR
{
  public:
    virtual ~hkReferencedObjectR() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpRigidBodyR : public hkReferencedObjectR
{
  public:
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual hkpRigidBodyR* clone() const throw();
};
class hkpConstraintInstanceR : public hkReferencedObjectR
{
  public:
    hkpConstraintInstanceR* clone(hkpRigidBodyR* pkEntityA, hkpRigidBodyR* pkEntityB, int eCloneMode) const throw();
};
class hkaSkeletonR : public hkReferencedObjectR
{
  public:
    const char* m_name;
    hkArrayR<short> m_kParentIndices;
};
class hkaRagdollInstanceR : public hkReferencedObjectR
{
  public:
    __forceinline void* operator new(std::size_t uiBytes)
    {
        hkReferencedObjectR* b =
            static_cast<hkReferencedObjectR*>(GetMemoryRouterR().heap().AllocateMemoryBlock(uiBytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(uiBytes);
        return b;
    }
    void operator delete(void* p, hk_size_tR uiBytes);
    hkaRagdollInstanceR(const hkArrayR<hkpRigidBodyR*>& kRigidBodies,
                        const hkArrayR<hkpConstraintInstanceR*>& kConstraints, const hkaSkeletonR* pkSkeleton,
                        const hkArrayR<int>& kBoneToRigidBodyMap) throw();
    hkaRagdollInstanceR* FUN_00ce2730(int eMode) const throw();
    const hkaSkeletonR* getSkeleton() const
    {
        return m_pSkeleton;
    }
    hkArrayR<hkpRigidBodyR*> m_ppRigidBodies;
    hkArrayR<hkpConstraintInstanceR*> m_ppConstraints;
    hkArrayR<int> m_kBoneMap;
    const hkaSkeletonR* m_pSkeleton;
};

// Clones the ragdoll's rigid bodies and constraints, builds a new hkaRagdollInstanceR from them, and returns it.
// @fnv 0x00ce2730
hkaRagdollInstanceR* hkaRagdollInstanceR::FUN_00ce2730(int aeCloneMode) const throw()
{
    const int iNumRigidBodies = m_ppRigidBodies.GetLogicalSize();
    const int iNumConstraints = m_ppConstraints.GetLogicalSize();
    hkLocalArrayR<hkpRigidBodyR*> kNewRigidBodies(iNumRigidBodies);
    kNewRigidBodies.SetSizeAndGrow(iNumRigidBodies);
    hkLocalArrayR<hkpConstraintInstanceR*> kNewConstraints(iNumConstraints);
    kNewConstraints.SetSizeAndGrow(iNumConstraints);
    for (int rb = 0; rb < iNumRigidBodies; rb++)
        kNewRigidBodies[rb] = m_ppRigidBodies[rb]->clone();
    for (int c = 0; c < iNumConstraints; c++)
    {
        hkpRigidBodyR* pkChildRb = kNewRigidBodies[c + 1];
        hkpRigidBodyR* pkParentRb = kNewRigidBodies[m_pSkeleton->m_kParentIndices[c + 1]];
        kNewConstraints[c] = ((::hkpConstraintInstanceR *)(reinterpret_cast<::hkpConstraintInstanceCF3F *>((void *)(m_ppConstraints[c]))->FUN_00cf3fa0((::hkpEntity *)(pkChildRb), (::hkpEntity *)(pkParentRb), aeCloneMode)));
    }
    hkaRagdollInstanceR* pkNewInstance =
        new hkaRagdollInstanceR(kNewRigidBodies, kNewConstraints, getSkeleton(), m_kBoneMap);
    for (int rb = 0; rb < iNumRigidBodies; rb++)
        reinterpret_cast<::hkReferencedObjectC905 *>((void *)(kNewRigidBodies[rb]))->FUN_00c905b0();
    for (int c = 0; c < iNumConstraints; c++)
        reinterpret_cast<::hkReferencedObjectC905 *>((void *)(kNewConstraints[c]))->FUN_00c905b0();
    return pkNewInstance;
}

#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
struct FUN_00ce14b0_standin
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
    __m128 unk10;
    unsigned short unk20;
    unsigned short unk22;
    unsigned short unk24;

    void FUN_00ce14b0(unsigned short a, unsigned short b, unsigned short c, const void* data);
};

// @fnv 0x00ce14b0
void FUN_00ce14b0_standin::FUN_00ce14b0(unsigned short auwFirst, unsigned short auwSecond, unsigned short auwThird,
                                        const void* data)
{
    unsigned short second = auwSecond;
    unsigned short third = auwThird;

    unk20 = auwFirst;
    unk22 = second;
    unk00 = 0;
    unk04 = 0;
    unk08 = 0x80000000;
    unk24 = third;

    __m128 value = *reinterpret_cast<const __m128*>(data);
    unk10 = value;
}

struct FUN_00ce1680_Body
{
    void* unk00;
    void* unk04;
    void* unk08;
};

struct FUN_00c94bd0_Obj
{
};

struct FUN_00c97d30_Obj
{
};

struct CollisionEntity;
struct CallRet
{
public:
    void FUN_00c946e0(::CollisionEntity *, int, int);
};

class FUN_00ce1680_Ragdoll : public hkReferencedObject
{
  public:
    hkArray<void*> m_ppRigidBodies;
    hkArray<void*> m_ppConstraints;
    hkArray<hkInt32> m_kBoneMap;
    hkaSkeleton* m_pSkeleton;

    int FUN_00ce1680(void* world, unsigned char flag);
};

// Passes rigid bodies and constraints to world methods; when flag is nonzero, calls another world method for each body.
// @fnv 0x00ce1680
int FUN_00ce1680_Ragdoll::FUN_00ce1680(void* world, unsigned char flag)
{
    FUN_00ce1680_Body* firstBody = (FUN_00ce1680_Body*)m_ppRigidBodies.m_data[0];

    if (firstBody && firstBody->unk08)
        return 1;

    reinterpret_cast<::TW *>((((FUN_00c94bd0_Obj*)world)))->FUN_00c94bd0((::TE *const *)(m_ppRigidBodies.m_data), m_ppRigidBodies.m_iElementCount, (::TEA)(1));

    for (int iConstraintIndex = 0; iConstraintIndex < m_ppConstraints.m_iElementCount; ++iConstraintIndex)
    {
        reinterpret_cast<::Mgr *>((((FUN_00c97d30_Obj*)world)))->FUN_00c97d30((::Item *)(m_ppConstraints.m_data[iConstraintIndex]));
    }

    if (flag)
    {
        int bodyCount = m_ppRigidBodies.m_iElementCount;
        int bodyIndex = 0;

        if (bodyCount > 0)
        {
            do
            {
                ((CallRet*)world)->FUN_00c946e0((::CollisionEntity *)(m_ppRigidBodies.m_data[bodyIndex]), 1, 0);
            } while (++bodyIndex < bodyCount);
        }
    }

    return 0;
}

extern int DAT_010cb830;
struct RouterRef_ce24
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    ArrayAllocator* m_pStreamAllocator;
    ArrayAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

template <class T> struct hkArray_ce24
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void SetSizeAndGrow(int n)
    {
        ArrayAllocator& heap = (*static_cast<RouterRef_ce24*>(::FUN_00c85750())).heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = 2 * cap;
            ::FUN_00c908c0((::SpawnedObject *)(::ArrayAllocator *)(&heap), (::SpawnedArray *)(void *)(this), n < cap2 ? cap2 : n, sizeof(T));
        }
        m_iElementCount = n;
    }
};

struct Skeleton_ce24
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    int m_iBoneCount;
};

struct RagdollInstance_ce24
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    hkArray_ce24<ReferenceObject*> m_ppRigidBodies;
    hkArray_ce24<ReferenceObject*> m_ppConstraints;
    hkArray_ce24<int> m_kBoneMap;
    Skeleton_ce24* m_pSkeleton;
    RagdollInstance_ce24* FUN_00ce2470(const hkArray_ce24<ReferenceObject*>& bodies,
                                       const hkArray_ce24<ReferenceObject*>& constraints, Skeleton_ce24* skeleton);
};

// Initializes a RagdollInstance_ce24 with the given rigid bodies, constraints, and skeleton, and returns the instance.
// @fnv 0x00ce2470
RagdollInstance_ce24* RagdollInstance_ce24::FUN_00ce2470(const hkArray_ce24<ReferenceObject*>& bodies,
                                                         const hkArray_ce24<ReferenceObject*>& constraints,
                                                         Skeleton_ce24* skeleton)
{
    m_vtbl = &DAT_010cb830;
    m_sReferenceCount = 1;
    m_ppRigidBodies.init();
    m_ppConstraints.init();
    m_kBoneMap.init();
    m_pSkeleton = 0;
    reinterpret_cast<::RagdollInstance *>(this)->FUN_00ce22c0((const ::ObjectArray< ::ReferenceObject *> &)(bodies), (const ::ObjectArray< ::ReferenceObject *> &)(constraints), (::ReferenceObject *)(skeleton));
    m_kBoneMap.SetSizeAndGrow(skeleton->m_iBoneCount);
    for (int i = 0; i < skeleton->m_iBoneCount; i++)
        m_kBoneMap[i] = i;
    return this;
}

extern "C"
{
}

void __cdecl FUN_00ce2d10(uintptr_t p0, void* p1, uintptr_t p2, int p3, uintptr_t p4);

struct Vec4x3
{
    __m128 r0;
    __m128 r1;
    __m128 r2;
};

// Reserves stack space for count Vec4x3 values, transforms each source entry with SIMD, calls FUN_00ce2d10, then restores the stack cursor.
// @fnv 0x00ce2f40
void __cdecl FUN_00ce2f40(uintptr_t arg0, uintptr_t arg1, uintptr_t arg2, int count, uintptr_t arg4)
{
    void** cursor = (void**)static_cast<ArrayRouter*>(::FUN_00c85750());
    unsigned char* pMatBase = (unsigned char*)*cursor;
    unsigned int size = (unsigned int)((count * 3) << 4) + 0x7f;
    size &= 0xffffff80u;
    *cursor = pMatBase + size;

    if (count > 0)
    {
        const Vec4x3* s = (const Vec4x3*)arg1;
        Vec4x3* d = (Vec4x3*)pMatBase;
        for (int i = 0; i < count; i++)
        {
            __m128 b = s[i].r1;
            __m128 a = s[i].r0;

            __m128 ab = _mm_mul_ps(a, b);
            __m128 vCross = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
            __m128 cb = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
            vCross = _mm_sub_ps(vCross, cb);
            __m128 vW = _mm_shuffle_ps(b, b, 0xff);
            vCross = _mm_mul_ps(vCross, vW);
            __m128 t1 = _mm_add_ss(_mm_shuffle_ps(ab, ab, 0x55), ab);
            __m128 vDot = _mm_add_ss(_mm_shuffle_ps(ab, ab, 0xaa), t1);
            __m128 t5 = _mm_mul_ps(vW, vW);
            t5 = _mm_add_ps(t5, ::DAT_010c71e0);
            t5 = _mm_mul_ps(t5, a);
            __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(vDot, vDot, 0), b);
            t5 = _mm_add_ps(t5, t2);
            vCross = _mm_add_ps(vCross, t5);
            __m128 res = _mm_add_ps(vCross, vCross);
            d[i].r0 = res;
            res = _mm_xor_ps(res, ::DAT_010c44d0);
            d[i].r0 = res;

            __m128 k = _mm_xor_ps(s[i].r1, ::DAT_010c4c00);
            d[i].r1 = k;

            __m128 c = s[i].r2;
            __m128 x = _mm_unpackhi_ps(c, ::DAT_010c7170);
            x = _mm_shuffle_ps(c, x, 0xc4);
            __m128 vRcp = _mm_rcp_ps(x);
            __m128 tt = _mm_mul_ps(vRcp, x);
            tt = _mm_mul_ps(tt, vRcp);
            __m128 vRecip = _mm_add_ps(vRcp, vRcp);
            vRecip = _mm_sub_ps(vRecip, tt);
            vRecip = _mm_and_ps(vRecip, ::DAT_010c4c10);
            d[i].r2 = vRecip;
        }
    }

    FUN_00ce2d10(arg0, (void*)pMatBase, arg2, count, arg4);
    void** cursor2 = (void**)static_cast<ArrayRouter*>(::FUN_00c85750());
    *cursor2 = pMatBase;
}


struct UnkCall
{
};

struct hkpMotion
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
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void SetTranslationalVelocity(const hkVector4& vel);
    virtual void SetRotationalVelocity(const hkVector4& vel);
    int unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
};

struct hkpRigidBody : public UnkCall
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc;
    hkpMotion m_pMotionState;

    void SetTranslationalVelocity(const hkVector4& vel)
    {
        reinterpret_cast<::hkpEntityC9C *>(this)->FUN_00c9c1d0();
        m_pMotionState.SetTranslationalVelocity(vel);
    }
    void SetRotationalVelocity(const hkVector4& vel)
    {
        reinterpret_cast<::hkpEntityC9C *>(this)->FUN_00c9c1d0();
        m_pMotionState.SetRotationalVelocity(vel);
    }
};

struct hkaBone
{
    hkStringPtr m_name;
    hkBool m_bLockTranslation;
};

struct hkaSkeleton : public hkReferencedObject
{
  public:
    hkStringPtr m_name;
    hkArray<hkInt16> m_kParentIndices;
    hkArray<hkaBone> m_kBones;
};

struct PoseW
{
    const hkQsTransform* p;
    PoseW(const hkQsTransform* q) : p(q)
    {}
};
struct RagdollHelper : public hkaRagdollInstance
{
    void FUN_00ce1560(PoseW pose);
};

// Sets mapped rigid-body transforms from pose and sets each velocity to zero when not all four components are within epsilon of zero.
// @fnv 0x00ce1560
void RagdollHelper::FUN_00ce1560(PoseW pose)
{
    int numBones = m_pSkeleton->m_kBones.m_iElementCount;
    const hkVector4& zero = *(const hkVector4*)&DAT_01267e30;
    int i = 0;
    if (numBones <= 0)
        return;
    const hkQsTransform* cursor = pose.p;
    do
    {
        int rbIndex = m_kBoneMap.m_data[i];
        if (rbIndex >= 0)
        {
            hkpRigidBody* rb = (hkpRigidBody*)m_ppRigidBodies.m_data[rbIndex];
            if (rb)
            {
                reinterpret_cast<::FUN_00ca8860_cls *>((rb))->FUN_00ca8860((intptr_t)&(cursor->m_vTranslation), (intptr_t)&(cursor->m_rotation));

                __m128 kZeroVec = *(const __m128*)&zero;
                __m128 kLinVel = *(const __m128*)&rb->m_pMotionState.m_kTranslationalVelocity;
                __m128 eps = _mm_set1_ps(::AngularDashpotApplyD4DCB0::DAT_01017d00);
                __m128 kDiffLin = _mm_sub_ps(kZeroVec, kLinVel);
                __m128 kAbsLin = _mm_and_ps(kDiffLin, *(const __m128*)&(*reinterpret_cast<float *>((void *)&::DAT_01017d10)));
                __m128 kCmpLin = _mm_cmple_ps(kAbsLin, eps);
                if ((_mm_movemask_ps(kCmpLin) & 0xf) != 0xf)
                {
                    rb->SetTranslationalVelocity(zero);
                    kZeroVec = *(const __m128*)&zero;
                }

                __m128 kAngVel = *(const __m128*)&rb->m_pMotionState.m_kAngularVelocity;
                __m128 kDiffAng = _mm_sub_ps(kZeroVec, kAngVel);
                __m128 kAbsAng = _mm_and_ps(kDiffAng, *(const __m128*)&(*reinterpret_cast<float *>((void *)&::DAT_01017d10)));
                __m128 kCmpAng = _mm_cmple_ps(kAbsAng, eps);
                if ((_mm_movemask_ps(kCmpAng) & 0xf) != 0xf)
                {
                    rb->SetRotationalVelocity(zero);
                }
            }
        }
        cursor = *static_cast<const hkQsTransform* volatile*>(&cursor);
        ++i;
        ++cursor;
    } while (i < numBones);
}

template <class T> struct InitArray : ObjectArray<T>
{
    InitArray()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
    }
};

struct FUN_00ce2510
{
    void* m_vptr;
    short m_iWordAt04;
    short m_6;
    InitArray<void*> m_ppRigidBodies;
    InitArray<void*> m_ppConstraints;
    InitArray<int> m_kBoneMap;
    int m_2c;

    FUN_00ce2510(intptr_t a, intptr_t b, intptr_t c, ObjectArray<int>* d);
};

// Sets the vtable and reference count, calls FUN_00ce22c0, and assigns m_kBoneMap from the provided array.
// @fnv 0x00ce2510
FUN_00ce2510::FUN_00ce2510(intptr_t a, intptr_t b, intptr_t c, ObjectArray<int>* apBoneMap) : m_vptr(&DAT_010cb830), m_6(1)
{
    m_2c = 0;

    reinterpret_cast<::RagdollInstance *>(this)->FUN_00ce22c0((*(const ::ObjectArray< ::ReferenceObject *> *)(a)), (*(const ::ObjectArray< ::ReferenceObject *> *)(b)), (::ReferenceObject *)(c));
    m_kBoneMap.assign(*apBoneMap);
}
// FUN_00ce0d30 - build orthonormal basis from 3 indexed points, convert to quaternion via FUN_00cb26e0

  // 0.5f
  // 0.0f
  // 3.0f

struct VecF
{
    float x, y, z, w;
};

struct Elem
{
    VecF v;
    float pad[8];
};

struct ThisX
{
    unsigned char pad[0x20];
    short m_i0;
    short m_i1;
    short m_i2;
};

class FUN_00827200_class
{
  public:
    float m_00, m_04, m_08, m_0c;
    void FUN_00cb26e0(intptr_t);
};

static __forceinline __m128 Dot3(__m128 v)
{
    __m128 sq = _mm_mul_ps(v, v);
    __m128 t = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    return _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), t);
}

static __forceinline __m128 Normalize(__m128 v)
{
    __m128 dot = Dot3(v);
    __m128 e = _mm_rsqrt_ss(dot);
    __m128 q = _mm_mul_ss(_mm_mul_ss(dot, e), e);
    __m128 three = _mm_set_ss(::DAT_01017718);
    __m128 half = _mm_set_ss(::fnv_00c88020::DAT_01016248);
    __m128 mask = _mm_cmpeq_ss(dot, _mm_set_ss(::DAT_01011d78));
    __m128 f = _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, q)));
    return _mm_mul_ps(_mm_shuffle_ps(f, f, 0), v);
}

static __forceinline __m128 Cross(__m128 a, __m128 b)
{
    __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    return _mm_sub_ps(t2, t1);
}

// @fnv 0x00ce0d30
void FUN_00ce0d30(ThisX* th, void* edx_unused, const Elem* points, VecF* out)
{
    VecF p0 = points[th->m_i0].v;
    VecF p1 = points[th->m_i1].v;
    VecF p2 = points[th->m_i2].v;

    __m128 e1 = _mm_sub_ps(_mm_load_ps(&p1.x), *(__m128*)&p0.x);
    __m128 n1 = Normalize(e1);
    __m128 e2 = _mm_sub_ps(_mm_load_ps(&p2.x), *(__m128*)&p0.x);
    __m128 n2 = Normalize(e2);
    __m128 c = Normalize(Cross(n2, n1));
    __m128 c2 = Normalize(Cross(c, n1));
    __m128 b = Cross(n1, c2);

    FUN_00827200_class obj;
    VecF axes[3];
    _mm_store_ps(&axes[0].x, c2);
    _mm_store_ps(&axes[1].x, b);
    _mm_store_ps(&axes[2].x, n1);
    obj.FUN_00cb26e0((intptr_t)&axes[0]);
    _mm_store_ps(&out->x, _mm_load_ps(&obj.m_00));
}

struct __declspec(align(16)) Pose32
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float unk14;
    int unk18;
    int unk1C;
};
struct SubObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* unk10;
};
struct Owner
{
    Pose32* data;
    int count;
    int capacity;
    int unk0C;
    SubObj sub;
    int FUN_00ce1420(void* pose, int arg2, float time);
};

struct __declspec(align(16)) Quaternion
{
    __m128 value;
    void FUN_00cb26e0(const __m128* matrix);
    void FUN_00c66320(const Quaternion& a, const Quaternion& b);
};
static __m128 cross3(__m128 a, __m128 b)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}
static __m128 dot3(__m128 a, __m128 b)
{
    __m128 v = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v));
}
static __declspec(noinline) void FUN_00ce0ff0(SubObj* object, Pose32* pose)
{
    __m128 axis = _mm_load_ps(reinterpret_cast<float*>(object));
    __declspec(align(16)) float absAxis[4];
    _mm_store_ps(absAxis, _mm_andnot_ps(_mm_set1_ps(-0.0f), axis));
    int major;
    if (absAxis[0] > absAxis[1])
        major = absAxis[0] > absAxis[2] ? 0 : 2;
    else
        major = absAxis[1] > absAxis[2] ? 1 : 2;
    __declspec(align(16)) float basis[4] = {0, 0, 0, 0};
    basis[(major + 1) % 3] = 1.0f;
    __m128 vector = _mm_load_ps(basis);
    __m128 q = _mm_load_ps(reinterpret_cast<float*>(pose));
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 d = dot3(q, vector);
    __m128 rotated = _mm_add_ps(_mm_mul_ps(cross3(q, vector), w),
                                _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), _mm_set1_ps(-0.5f)), vector),
                                           _mm_mul_ps(_mm_shuffle_ps(d, d, 0), q)));
    rotated = _mm_add_ps(rotated, rotated);
    __m128 third = cross3(rotated, axis);
    __m128 length = dot3(third, third);
    __m128 inverse = _mm_rsqrt_ss(length);
    inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inverse),
                         _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(length, inverse), inverse)));
    inverse = _mm_andnot_ps(_mm_cmpeq_ss(length, _mm_setzero_ps()), inverse);
    third = _mm_mul_ps(third, _mm_shuffle_ps(inverse, inverse, 0));
    __m128 matrix[3] = {cross3(axis, third), axis, third};
    Quaternion orient;
    orient.FUN_00cb26e0(matrix);
    Quaternion conjugate;
    conjugate.value = _mm_xor_ps(orient.value, _mm_set_ps(0.0f, -0.0f, -0.0f, -0.0f));
    Quaternion result;
    ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(result), nullptr, (const ::fnv_00c66320::__m128 *)&(conjugate), (const ::fnv_00c66320::__m128 *)&(*reinterpret_cast<Quaternion*>(pose)));
    _mm_store_ps(reinterpret_cast<float*>(pose), result.value);
}

// @fnv 0x00ce1420
int Owner::FUN_00ce1420(void* pose, int arg2, float time)
{
    Pose32 poseData;
    poseData.unk14 = time;
    poseData.unk10 = arg2;
    ::FUN_00ce0d30((::ThisX *)this, pose, (const ::Elem *)(::Pose32 *)(&poseData), {});
    FUN_00ce0ff0(&sub, &poseData);
    ArrayRouter* router = static_cast<ArrayRouter*>(::FUN_00c85750());
    if (count == (capacity & 0x3FFFFFFF))
        ::ResizeAudioStream((::AudioAllocator *)(router->m_pStreamAllocator), (::AudioStream *)(void *)(this), 0x20);
    Pose32* destination = data + count;
    if (destination != 0)
        *destination = poseData;
    count += 1;
    return count - 1;
}


class hkQuaternionCE2;

class hkVector4CE2
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4CE2& operator=(const hkVector4CE2& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4CE2& a, const hkVector4CE2& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4CE2& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4CE2& a, const hkVector4CE2& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4CE2& a, const hkVector4CE2& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4CE2& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4CE2& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, ::DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4CE2& v1, const hkVector4CE2& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4CE2& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4CE2& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionCE2& q, const hkVector4CE2& dir);
    void setRotatedInverseDir(const hkQuaternionCE2& q, const hkVector4CE2& dir);
};

struct hkRotationCE2
{
    hkVector4CE2 m_kColumn0;
    hkVector4CE2 m_kColumn1;
    hkVector4CE2 m_kColumn2;
};

struct hkTransformCE2
{
    hkRotationCE2 m_rotation;
    hkVector4CE2 m_vTranslation;
};

class hkQuaternionCE2
{
  public:
    hkVector4CE2 m_vec;

    void set(const hkRotationCE2& kRotationBasis);

    __forceinline void SetConjugate(const hkQuaternionCE2& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionCE2& q0, const hkQuaternionCE2& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

__forceinline void hkVector4CE2::SetRotatedDirection(const hkQuaternionCE2& quat, const hkVector4CE2& direction)
{
    hkVector4CE2 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4CE2 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, ::DAT_010c71e0);
    hkVector4CE2 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CE2 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4CE2::setRotatedInverseDir(const hkQuaternionCE2& quat, const hkVector4CE2& direction)
{
    hkVector4CE2 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4CE2 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, ::DAT_010c71e0);
    hkVector4CE2 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CE2 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformCE2
{
  public:
    hkVector4CE2 m_vTranslation;
    hkQuaternionCE2 m_rotation;
    hkVector4CE2 m_vScale;

    __forceinline void SetConjugate(const hkQsTransformCE2& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4CE2 s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void setIdentity()
    {
        m_vTranslation.m_vComponents = _mm_setzero_ps();
        m_rotation.m_vec.m_vComponents = ::DAT_010c71b0;
        m_vScale.m_vComponents = _mm_set_ps1(1.0f);
    }
    __declspec(noinline) void SetFromTransform(const hkTransformCE2& kTransform)
    {
        m_rotation.set(kTransform.m_rotation);
        m_vTranslation = kTransform.m_vTranslation;
        m_vScale.m_vComponents = DAT_010c7170;
    }
    __forceinline void SetProduct(const hkQsTransformCE2& t1, const hkQsTransformCE2& t2)
    {
        hkVector4CE2 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(m_rotation), nullptr, (const ::fnv_00c66320::__m128 *)&(t1.m_rotation), (const ::fnv_00c66320::__m128 *)&(t2.m_rotation));
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};

struct hkaSkeletonCE2
{
    int unk00;
    int unk04;
    int unk08;
    short* m_kParentIndices;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    hkQsTransformCE2* m_kReferencePose;
};

// Accumulated scale of a bone and all its parents in the reference pose.
__declspec(noinline) void __cdecl MultiplyBoneScales(const hkaSkeletonCE2* pkSkeleton, const hkQsTransformCE2* pkPose,
                                                     int iBone, hkVector4CE2& kScaleOut)
{
    hkVector4CE2 kScale;
    kScale.m_vComponents = DAT_010c7170;
    while (iBone != -1)
    {
        kScale.m_vComponents = _mm_mul_ps(pkPose[iBone].m_vScale.m_vComponents, kScale.m_vComponents);
        iBone = pkSkeleton->m_kParentIndices[iBone];
    }
    kScaleOut = kScale;
}

struct RigidBodyCE2
{
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
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    hkTransformCE2 m_kMotionTransform;
};

class FUN_00ce2000Owner
{
  public:
    int unk00;
    int unk04;
    RigidBodyCE2** m_ppBodies;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* m_piBoneToBody;
    int unk24;
    int unk28;
    hkaSkeletonCE2* m_pkSkeleton;

    void FUN_00ce2000(int iBone, hkQsTransformCE2& kOut);
};

// @fnv 0x00ce2000
void FUN_00ce2000Owner::FUN_00ce2000(int iBone, hkQsTransformCE2& kOut)
{
    int iBody = m_piBoneToBody[iBone];
    if (iBody >= 0)
    {
        RigidBodyCE2* pkBody = m_ppBodies[iBody];
        if (pkBody)
        {
            reinterpret_cast<::S_00ce5070_QsTransform *>(&(kOut))->FUN_00ce5070((const ::S_00ce5070_Transform &)(pkBody->m_kMotionTransform));
            MultiplyBoneScales(m_pkSkeleton, m_pkSkeleton->m_kReferencePose, iBone, kOut.m_vScale);
            return;
        }
    }

    hkQsTransformCE2 kParent;
    int iParent = m_pkSkeleton->m_kParentIndices[iBone];
    if (iParent >= 0)
        FUN_00ce2000(iParent, kParent);
    else
        kParent.setIdentity();
    kOut.SetProduct(kParent, m_pkSkeleton->m_kReferencePose[iBone]);
}


class hkQuaternionC21;

class hkVector4C21
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4C21& operator=(const hkVector4C21& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4C21& a, const hkVector4C21& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4C21& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4C21& a, const hkVector4C21& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4C21& a, const hkVector4C21& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4C21& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4C21& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, ::DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4C21& v1, const hkVector4C21& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4C21& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4C21& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionC21& q, const hkVector4C21& dir);
    void setRotatedInverseDir(const hkQuaternionC21& q, const hkVector4C21& dir);
};

struct hkRotationC21
{
    hkVector4C21 m_kColumn0;
    hkVector4C21 m_kColumn1;
    hkVector4C21 m_kColumn2;
};

struct hkTransformC21
{
    hkRotationC21 m_rotation;
    hkVector4C21 m_vTranslation;
};

class hkQuaternionC21
{
  public:
    hkVector4C21 m_vec;

    void set(const hkRotationC21& kRotationBasis);

    __forceinline void SetConjugate(const hkQuaternionC21& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionC21& q0, const hkQuaternionC21& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

__forceinline void hkVector4C21::SetRotatedDirection(const hkQuaternionC21& quat, const hkVector4C21& direction)
{
    hkVector4C21 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4C21 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, ::DAT_010c71e0);
    hkVector4C21 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4C21 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4C21::setRotatedInverseDir(const hkQuaternionC21& quat, const hkVector4C21& direction)
{
    hkVector4C21 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4C21 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, ::DAT_010c71e0);
    hkVector4C21 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4C21 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformC21
{
  public:
    hkVector4C21 m_vTranslation;
    hkQuaternionC21 m_rotation;
    hkVector4C21 m_vScale;

    __forceinline void SetConjugate(const hkQsTransformC21& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4C21 s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void setIdentity()
    {
        m_vTranslation.m_vComponents = _mm_setzero_ps();
        m_rotation.m_vec.m_vComponents = ::DAT_010c71b0;
        m_vScale.m_vComponents = _mm_set_ps1(1.0f);
    }
    __declspec(noinline) void SetFromTransform(const hkTransformC21& kTransform)
    {
        m_rotation.set(kTransform.m_rotation);
        m_vTranslation = kTransform.m_vTranslation;
        m_vScale.m_vComponents = DAT_010c7170;
    }
    __forceinline void SetProduct(const hkQsTransformC21& t1, const hkQsTransformC21& t2)
    {
        hkVector4C21 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(m_rotation), nullptr, (const ::fnv_00c66320::__m128 *)&(t1.m_rotation), (const ::fnv_00c66320::__m128 *)&(t2.m_rotation));
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};

struct hkaSkeletonC21
{
    int unk00;
    int unk04;
    int unk08;
    short* m_kParentIndices;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    hkQsTransformC21* m_kReferencePose;
};

// Accumulated scale of a bone and all its parents in the reference pose.
__declspec(noinline) void __cdecl MultiplyBoneScales(const hkaSkeletonC21* pkSkeleton, const hkQsTransformC21* pkPose,
                                                     int iBone, hkVector4C21& kScaleOut)
{
    hkVector4C21 kScale;
    kScale.m_vComponents = DAT_010c7170;
    while (iBone != -1)
    {
        kScale.m_vComponents = _mm_mul_ps(pkPose[iBone].m_vScale.m_vComponents, kScale.m_vComponents);
        iBone = pkSkeleton->m_kParentIndices[iBone];
    }
    kScaleOut = kScale;
}

struct MotionStateC21
{
};

struct RigidBodyC21
{
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
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    MotionStateC21 m_kMotionState;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    hkTransformC21 m_kMotionTransform;
};
class hkQsTransformC21;


class FUN_00ce2150Owner
{
  public:
    int unk00;
    int unk04;
    RigidBodyC21** m_ppBodies;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* m_piBoneToBody;
    int unk24;
    int unk28;
    hkaSkeletonC21* m_pkSkeleton;

    void FUN_00ce2150(int iBone, float fTime, hkQsTransformC21& kOut);
};

// @fnv 0x00ce2150
void FUN_00ce2150Owner::FUN_00ce2150(int iBone, float fTime, hkQsTransformC21& kOut)
{
    int iBody = m_piBoneToBody[iBone];
    if (iBody >= 0)
    {
        RigidBodyC21* pkBody = m_ppBodies[iBody];
        if (pkBody)
        {
            hkTransformC21 kTransform;
            reinterpret_cast<::FUN_00c86490_Class *>((void *)&(pkBody->m_kMotionState))->SweepTransform(fTime, (void *)&(kTransform));
            reinterpret_cast<::S_00ce5070_QsTransform *>(&(kOut))->FUN_00ce5070((const ::S_00ce5070_Transform &)(kTransform));
            MultiplyBoneScales(m_pkSkeleton, m_pkSkeleton->m_kReferencePose, iBone, kOut.m_vScale);
            return;
        }
    }

    {
        hkQsTransformC21 kParent;
        int iParent = m_pkSkeleton->m_kParentIndices[iBone];
        if (iParent >= 0)
            FUN_00ce2150(iParent, fTime, kParent);
        else
            kParent.setIdentity();
        kOut.SetProduct(kParent, m_pkSkeleton->m_kReferencePose[iBone]);
    }
}
struct Xf12a0
{
    __m128 t, r, s;
    __forceinline void setIdentity()
    {
        t = _mm_setzero_ps();
        r = _mm_load_ps((const float*)&::DAT_010c71b0);
        s = _mm_set1_ps(1.0f);
    }
};
__declspec(align(16)) struct Q4
{
    float x, y, z, w;
};

struct Ce0d30Obj
{
};
struct Ce74Obj
{
};
struct Ceb2Obj
{
    void FUN_00cb2450(void* axis, float angle);
};
struct Ce12a0Self
{
    int unk00, unk04, unk08, unk0c;
    void* unk10;
    int unk14, unk18, unk1c;
    short idx0, idx1, idx2;
};

class Ce12a0Host
{
  public:
    void FUN_00ce12a0(void* a1, void* a2, Xf12a0* a3, Xf12a0* a4);
};

struct SimdNumber
{
    __m128 value;
    __forceinline SimdNumber(__m128 n) : value(n)
    {}
};
struct MathVec
{
    __m128 value;
    __forceinline SimdNumber dot(const MathVec& other) const
    {
        __m128 products = _mm_mul_ps(value, other.value);
        __m128 partial = _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products);
        return SimdNumber(_mm_add_ss(_mm_shuffle_ps(products, products, 0xaa), partial));
    }
    __forceinline void cross(const MathVec& a, const MathVec& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(first, second);
    }
    __forceinline void rotate(const MathVec& q, const MathVec& b)
    {
        __m128 half = _mm_load_ps((const float*)&::DAT_010c71e0);
        __m128 scalar = _mm_shuffle_ps(q.value, q.value, 0xff);
        __m128 factor = _mm_add_ps(half, _mm_mul_ps(scalar, scalar));
        __m128 base = _mm_mul_ps(b.value, factor);
        SimdNumber product = q.dot(b);
        __m128 splat = _mm_shuffle_ps(product.value, product.value, 0);
        base = _mm_add_ps(base, _mm_mul_ps(splat, q.value));
        MathVec crossed;
        crossed.cross(q, b);
        base = _mm_add_ps(base, _mm_mul_ps(scalar, crossed.value));
        value = _mm_add_ps(base, base);
    }
};

// @fnv 0x00ce12a0
void Ce12a0Host::FUN_00ce12a0(void* a1, void* a2, Xf12a0* a3, Xf12a0* a4)
{
    Ce12a0Self* self = (Ce12a0Self*)this;
    Q4 q0, q1;

    ::FUN_00ce0d30((::ThisX *)(((Ce0d30Obj*)self)), a1, (const ::Elem *)(void *)(&q0), {});
    ::FUN_00ce0d30((::ThisX *)(((Ce0d30Obj*)self)), a2, (const ::Elem *)(void *)(&q1), {});

    a4->setIdentity();
    int index = self->idx0;
    a4->t = ((Xf12a0*)a2)[index].t;
    reinterpret_cast<::Quat74 *>((((Ce74Obj*)&a4->r)))->FUN_00c74ac0((*(const ::Quat74 *)(&q1)), (*(const ::Quat74 *)(&q0)));

    MathVec rotated;
    rotated.rotate(*(MathVec*)&a4->r, *(MathVec*)&((Xf12a0*)a1)[index].t);
    a4->t = _mm_sub_ps(a4->t, rotated.value);

    a3->setIdentity();
    a3->t = a4->t;
    a3->r = a4->r;
    a3->s = a4->s;

    {
        __declspec(align(16)) float angle;
        Q4 axis;
        reinterpret_cast<::hkQuaternion *>((((Ceb2Obj*)&a3->r)))->FUN_00cb2ca0((*(const ::hkVector4 *)(&self->unk10)), (*(::hkQuaternion *)(&axis)), (*(float *)(&angle)));
        ((Ceb2Obj*)&a3->r)->FUN_00cb2450(&self->unk10, angle);
    }
}

extern const float DAT_0104da4c;

struct ByteResult
{
    char value;
    ByteResult(bool b) : value(b)
    {}
};

struct VectorTest
{
    __m128 m_data;

    ByteResult FUN_00ce1500() const;
};

// @fnv 0x00ce1500
ByteResult VectorTest::FUN_00ce1500() const
{
    __m128 v = m_data;
    float scale = DAT_0104da4c;
    __m128 a = _mm_mul_ps(v, v);
    __m128 b = _mm_shuffle_ps(a, a, 0x55);
    __m128 c = _mm_shuffle_ps(a, a, 0xaa);
    b = _mm_add_ss(b, a);
    c = _mm_add_ss(c, b);
    c = _mm_sqrt_ss(c);
    __m128 r = c;
    float f;
    _mm_store_ss(&f, r);
    return ByteResult(f > scale);
}


class hkQuaternionC18;

class hkVector4C18
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4C18& operator=(const hkVector4C18& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4C18& a, const hkVector4C18& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4C18& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4C18& a, const hkVector4C18& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4C18& a, const hkVector4C18& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4C18& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4C18& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, ::DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4C18& v1, const hkVector4C18& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4C18& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4C18& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionC18& q, const hkVector4C18& dir);
    void setRotatedInverseDir(const hkQuaternionC18& q, const hkVector4C18& dir);
};

class hkQuaternionC18
{
  public:
    hkVector4C18 m_vec;

    __forceinline void SetConjugate(const hkQuaternionC18& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionC18& q0, const hkQuaternionC18& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

__forceinline void hkVector4C18::SetRotatedDirection(const hkQuaternionC18& quat, const hkVector4C18& direction)
{
    hkVector4C18 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4C18 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, ::DAT_010c71e0);
    hkVector4C18 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4C18 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4C18::setRotatedInverseDir(const hkQuaternionC18& quat, const hkVector4C18& direction)
{
    hkVector4C18 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4C18 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, ::DAT_010c71e0);
    hkVector4C18 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4C18 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformC18
{
  public:
    hkVector4C18 m_vTranslation;
    hkQuaternionC18 m_rotation;
    hkVector4C18 m_vScale;

    __forceinline void SetConjugate(const hkQsTransformC18& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.m_vComponents = _mm_xor_ps(m_vTranslation.m_vComponents, ::DAT_010c44d0);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4C18 s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void SetProduct(const hkQsTransformC18& t1, const hkQsTransformC18& t2)
    {
        hkVector4C18 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(m_rotation), nullptr, (const ::fnv_00c66320::__m128 *)&(t1.m_rotation), (const ::fnv_00c66320::__m128 *)&(t2.m_rotation));
        m_vScale.m_vComponents = _mm_mul_ps(m_vScale.m_vComponents, t1.m_vScale.m_vComponents);
    }
    __forceinline void SetMulInverse(const hkQsTransformC18& a, const hkQsTransformC18& b)
    {
        hkQsTransformC18 h;
        h.SetConjugate(a);
        SetProduct(h, b);
    }
};

struct hkaSkeletonC18
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_iBoneCount;
};

class RagdollMapperC18
{
  public:
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
    hkaSkeletonC18* m_pkSkeleton;

    void FUN_00ce18f0(hkQsTransformC18* pkPoseOut, const hkQsTransformC18& kWorldFromModel);
};

// @fnv 0x00ce18f0
void RagdollMapperC18::FUN_00ce18f0(hkQsTransformC18* pkPoseOut, const hkQsTransformC18& kWorldFromModel)
{
    ::FUN_00ce18d0((intptr_t)this, (::hkQsTransformC17 *)(pkPoseOut));
    int iNumBones = m_pkSkeleton->m_iBoneCount;
    hkQsTransformC18 kModelFromWorld;
    kModelFromWorld.SetConjugate(kWorldFromModel);
    for (int i = 0; i < iNumBones; i++)
        pkPoseOut[i].SetProduct(kModelFromWorld, pkPoseOut[i]);
}

// Near miss: two load-encodings remain under accepted GS- flags and RTM.

struct hkVec4
{
    __m128 m_vComponents;
};
struct hkRot3
{
    hkVec4 m_kColumn0, m_kColumn1, m_kColumn2;
};
struct hkQuat
{
    hkVec4 m_vec;
    void FUN_00cb26e0(const hkRot3& r);
    void FUN_00c66320(const hkQuat& a, const hkQuat& b);
};
// @fnv 0x00ce0ff0
static __declspec(noinline) void FUN_00ce0ff0(const hkVec4& dir, hkQuat& q)
{
    hkVec4 perp;
    perp.m_vComponents = _mm_setzero_ps();
    hkVec4 a;
    a.m_vComponents = _mm_and_ps(dir.m_vComponents, DAT_01017d10);
    const float* f = (const float*)&a;
    int major;
    if (f[0] < f[1])
        major = (f[1] < f[2]) ? 2 : 1;
    else
        major = (f[0] < f[2]) ? 2 : 0;
    ((float*)&perp)[(major + 1) % 3] = 1.0f;

    __m128 qv = q.m_vec.m_vComponents;
    __m128 w = _mm_shuffle_ps(qv, qv, 0xff);
    __m128 d = dot3(qv, perp.m_vComponents);
    __m128 r0 = _mm_mul_ps(cross3(qv, perp.m_vComponents), w);
    __m128 t = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), ::DAT_010c71e0), perp.m_vComponents);
    t = _mm_add_ps(t, _mm_mul_ps(_mm_shuffle_ps(d, d, 0), qv));
    __m128 r = _mm_add_ps(r0, t);
    r = _mm_add_ps(r, r);

    __m128 dirQuad = dir.m_vComponents;
    __m128 c = cross3(r, dirQuad);

    const __m128 half = _mm_set_ss(0.5f);
    const __m128 three = _mm_set_ss(3.0f);
    const __m128 zero = _mm_set_ss(0.0f);

    const __m128 len2 = dot3(c, c);
    const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);

    const __m128 approx = _mm_rsqrt_ss(len2);
    const __m128 refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    __m128 s = _mm_andnot_ps(len2EqualsZero, refined);
    c = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), c);

    hkRot3 m;
    m.m_kColumn0.m_vComponents = cross3(dirQuad, c);
    m.m_kColumn1.m_vComponents = dirQuad;
    m.m_kColumn2.m_vComponents = c;
    hkQuat rq;
    reinterpret_cast<::FUN_00827200_class *>(&(rq))->FUN_00cb26e0((intptr_t)&(m));
    hkQuat inv;
    __m128 mask = DAT_010c4c00;
    _ReadWriteBarrier();
    __m128 value = rq.m_vec.m_vComponents;
    _ReadWriteBarrier();
    inv.m_vec.m_vComponents = _mm_xor_ps(value, mask);
    hkQuat res;
    ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(res), nullptr, (const ::fnv_00c66320::__m128 *)&(inv), (const ::fnv_00c66320::__m128 *)&(q));
    q.m_vec.m_vComponents = res.m_vec.m_vComponents;
}
class ScalarLane
{
    __m128 data;

  public:
    ScalarLane(const __m128& v) : data(v)
    {}
    operator float() const
    {
        float scalar;
        _mm_store_ss(&scalar, data);
        return scalar;
    }
};

struct PoseVector
{
    union
    {
        __m128 q;
        float component[4];
    };
    PoseVector()
    {}
    PoseVector(const __m128& v) : q(v)
    {}
    PoseVector(const PoseVector& other) : q(other.q)
    {}
    __forceinline void operator=(const PoseVector& other)
    {
        q = other.q;
    }
    ScalarLane dot(const PoseVector& other) const
    {
        __m128 product = _mm_mul_ps(q, other.q);
        __m128 pair = _mm_add_ps(_mm_shuffle_ps(product, product, 0x4e), product);
        __m128 swapped = _mm_shuffle_ps(pair, pair, 0xb1);
        return _mm_add_ps(pair, swapped);
    }
    __forceinline void cross(const PoseVector& a, const PoseVector& b)
    {
        q = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2)),
                       _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9)));
    }
    __forceinline void normalize()
    {
        __m128 square = _mm_mul_ps(q, q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(square, square, 0x55), square);
        __m128 length = _mm_add_ss(_mm_shuffle_ps(square, square, 0xaa), xy);
        __m128 estimate = _mm_rsqrt_ss(length);
        __m128 zero = _mm_cmpeq_ss(length, _mm_setzero_ps());
        __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(length, estimate), estimate));
        __m128 scale = _mm_andnot_ps(zero, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction));
        q = _mm_mul_ps(q, _mm_shuffle_ps(scale, scale, 0));
    }
};

struct PoseBasis
{
    PoseVector x, y, z;
};
struct PoseRotation
{
    PoseVector vector;
    PoseRotation()
    {}
    __forceinline void operator=(const PoseRotation& other)
    {
        vector = other.vector;
    }
    void FUN_00cb26e0(const PoseBasis& basis);
    void FUN_00c66320(const PoseRotation& a, const PoseRotation& b);
};

static __declspec(noinline) void FUN_00ce0ff0(const PoseVector& axis, PoseRotation& value)
{
    PoseVector side;
    side.q = _mm_setzero_ps();
    PoseVector magnitudes;
    magnitudes.q = _mm_andnot_ps(_mm_set1_ps(-0.0f), axis.q);
    int major = magnitudes.component[0] < magnitudes.component[1]
                    ? (magnitudes.component[1] < magnitudes.component[2] ? 2 : 1)
                    : (magnitudes.component[0] < magnitudes.component[2] ? 2 : 0);
    side.component[(major + 1) % 3] = 1.0f;
    __m128 rotation = value.vector.q;
    __m128 real = _mm_shuffle_ps(rotation, rotation, 0xff);
    __m128 factor = _mm_add_ps(_mm_set1_ps(-0.5f), _mm_mul_ps(real, real));
    __m128 product = _mm_mul_ps(rotation, side.q);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    __m128 result = _mm_add_ps(_mm_mul_ps(side.q, factor), _mm_mul_ps(_mm_shuffle_ps(sum, sum, 0), rotation));
    PoseVector perpendicular;
    perpendicular.cross(value.vector, side);
    result = _mm_add_ps(result, _mm_mul_ps(real, perpendicular.q));
    side.q = _mm_add_ps(result, result);
    PoseVector up;
    up.cross(side, axis);
    up.normalize();
    side.cross(axis, up);
    PoseBasis basis;
    basis.x = side;
    basis.y = axis;
    basis.z = up;
    PoseRotation frame;
    frame.FUN_00cb26e0(basis);
    PoseRotation inverse;
    inverse.vector.q = _mm_xor_ps(frame.vector.q, _mm_set_ps(0.0f, -0.0f, -0.0f, -0.0f));
    PoseRotation composed;
    composed.FUN_00c66320(inverse, value);
    value = composed;
}

struct CandidatePose
{
    PoseRotation reference;
    const void* binding;
    float time;
};
struct PoseMatcher
{
    hkArray<CandidatePose> candidates;
    PoseVector axis;
    short rootBone, otherBone, thirdBone;
    int FUN_00ce11f0(const hkQsTransform* pose, float& error) const;
};

inline float magnitude(float value)
{
    return fabsf(value);
}

// @fnv 0x00ce11f0
int PoseMatcher::FUN_00ce11f0(const hkQsTransform* pose, float& error) const
{
    PoseRotation orientation;
    ::FUN_00ce0d30((::ThisX *)this, (void *)(pose), (const ::Elem *)&(orientation), {});
    FUN_00ce0ff0(axis, orientation);
    int selected = -1;
    error = ::DAT_0104da48;
    for (int index = 0; index < candidates.m_iElementCount; ++index)
    {
        float distance = 1.0f - magnitude(orientation.vector.dot(candidates.m_data[index].reference.vector));
        if (distance < error)
        {
            selected = index;
            error = distance;
        }
    }
    return selected;
}


class hkQuaternionC17;

class hkVector4C17
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4C17& operator=(const hkVector4C17& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4C17& a, const hkVector4C17& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4C17& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4C17& a, const hkVector4C17& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4C17& a, const hkVector4C17& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4C17& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4C17& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, ::DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4C17& v1, const hkVector4C17& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4C17& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline void setReciprocal4(const hkVector4C17& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionC17& q, const hkVector4C17& dir);
    void setRotatedInverseDir(const hkQuaternionC17& q, const hkVector4C17& dir);
};

struct hkRotationC17
{
    hkVector4C17 m_kColumn0;
    hkVector4C17 m_kColumn1;
    hkVector4C17 m_kColumn2;
};

struct hkTransformC17
{
    hkRotationC17 m_rotation;
    hkVector4C17 m_vTranslation;
};

class hkQuaternionC17
{
  public:
    hkVector4C17 m_vec;

    void set(const hkRotationC17& kRotationBasis);

    __forceinline void SetConjugate(const hkQuaternionC17& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void FUN_00c66320(const hkQuaternionC17& q0, const hkQuaternionC17& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
        __m128 aw = _mm_shuffle_ps(a, a, 0xff);
        __m128 bw = _mm_shuffle_ps(b, b, 0xff);
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), 0xc4);
    }
};

__forceinline void hkVector4C17::SetRotatedDirection(const hkQuaternionC17& quat, const hkVector4C17& direction)
{
    hkVector4C17 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, 0xff);
    hkVector4C17 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, ::DAT_010c71e0);
    hkVector4C17 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4C17 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformC17
{
  public:
    hkVector4C17 m_vTranslation;
    hkQuaternionC17 m_rotation;
    hkVector4C17 m_vScale;

    __declspec(noinline) void FUN_00ce5070(const hkTransformC17& kTransform)
    {
        m_rotation.set(kTransform.m_rotation);
        m_vTranslation = kTransform.m_vTranslation;
        m_vScale.m_vComponents = DAT_010c7170;
    }
    __forceinline void SetProduct(const hkQsTransformC17& t1, const hkQsTransformC17& t2)
    {
        hkVector4C17 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(m_rotation), nullptr, (const ::fnv_00c66320::__m128 *)&(t1.m_rotation), (const ::fnv_00c66320::__m128 *)&(t2.m_rotation));
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};

struct hkaSkeletonC17
{
    int unk00;
    int unk04;
    int unk08;
    short* m_kParentIndices;
    int unk10;
    int unk14;
    int unk18;
    int m_iBoneCount;
    int unk20;
    hkQsTransformC17* m_kReferencePose;
};

extern "C" void __cdecl MultiplyBoneScales(const hkaSkeletonC17*, const hkQsTransformC17*, int, hkVector4C17&);

struct RigidBodyC17
{
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
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    hkTransformC17 m_kMotionTransform;
};
class hkQsTransformC17;


class Ragdoll4
{
  public:
    int unk00;
    int unk04;
    RigidBodyC17** m_ppBodies;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* m_piBoneToBody;
    int unk24;
    int unk28;
    hkaSkeletonC17* m_pkSkeleton;

    void FUN_00ce1760(hkQsTransformC17* pkPoseOut, const hkQsTransformC17& kRoot, const hkQsTransformC17* pkLocalPose);
};

// @fnv 0x00ce1760
void Ragdoll4::FUN_00ce1760(hkQsTransformC17* pkPoseOut, const hkQsTransformC17& kRoot,
                            const hkQsTransformC17* pkLocalPose)
{
    if (!pkLocalPose)
        pkLocalPose = m_pkSkeleton->m_kReferencePose;

    for (int i = 0; i < m_pkSkeleton->m_iBoneCount; i++)
    {
        int iBody = m_piBoneToBody[i];
        if (iBody >= 0)
        {
            RigidBodyC17* pkBody = m_ppBodies[iBody];
            if (pkBody)
            {
                reinterpret_cast<::S_00ce5070_QsTransform *>(&(pkPoseOut[i]))->FUN_00ce5070((const ::S_00ce5070_Transform &)(pkBody->m_kMotionTransform));
                MultiplyBoneScales(m_pkSkeleton, m_pkSkeleton->m_kReferencePose, i, pkPoseOut[i].m_vScale);
                continue;
            }
        }

        int iParent = m_pkSkeleton->m_kParentIndices[i];
        hkQsTransformC17 kParent;
        (iParent >= 0) ? (kParent = pkPoseOut[iParent]) : (kParent = kRoot);
        pkPoseOut[i].SetProduct(kParent, pkLocalPose[i]);
    }
}namespace fnv_00ce1ad0 {
#include <xmmintrin.h>


struct __declspec(align(16)) FUN_005611c0_t;

struct __declspec(align(16)) hkVec4
{
    float x, y, z, w;

    const __m128& get() const
    {
        return reinterpret_cast<const __m128&>(x);
    }
    void set(__m128 v)
    {
        reinterpret_cast<__m128&>(x) = v;
    }

    void SetRotatedDirection(const FUN_005611c0_t& quat, const hkVec4& direction);
    void setAdd4(const hkVec4& a, const hkVec4& b)
    {
        set(_mm_add_ps(a.get(), b.get()));
    }
    void setMul4(const hkVec4& a, const hkVec4& b)
    {
        set(_mm_mul_ps(a.get(), b.get()));
    }
    bool equals4(const float* v) const
    {
        __m128 t = _mm_and_ps(_mm_sub_ps(_mm_load_ps(v), get()), _mm_load_ps(&(*reinterpret_cast<const float *>((void *)&::DAT_01017d10))));
        __m128 eps = _mm_set1_ps(1e-3f);
        return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 0xf) == 0xf;
    }
};

struct __declspec(align(16)) FUN_005611c0_t
{
    float x, y, z, w;

    const __m128& get() const
    {
        return reinterpret_cast<const __m128&>(x);
    }

    void FUN_00c66320(const FUN_005611c0_t* q0, const FUN_005611c0_t* q1);
};

__forceinline void hkVec4::SetRotatedDirection(const FUN_005611c0_t& quat, const hkVec4& direction)
{
    __m128 q = quat.get();
    __m128 dir = direction.get();
    __m128 qreal = _mm_shuffle_ps(q, q, 0xff);
    __m128 ret = _mm_mul_ps(_mm_add_ps(_mm_load_ps(&(*reinterpret_cast<const float *>((void *)&::DAT_010c71e0))), _mm_mul_ps(qreal, qreal)), dir);
    __m128 x2 = _mm_mul_ps(q, dir);
    __m128 d = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    ret = _mm_add_ps(ret, _mm_mul_ps(_mm_shuffle_ps(d, d, 0), q));
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(dir, dir, 0xd2)),
                              _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(dir, dir, 0xc9)));
    ret = _mm_add_ps(ret, _mm_mul_ps(qreal, cross));
    set(_mm_add_ps(ret, ret));
}

struct RagQsTransform
{
    hkVec4 m_vTranslation;
    FUN_005611c0_t m_rotation;
    hkVec4 m_vScale;

    __forceinline void SetProduct(const RagQsTransform& t1, const RagQsTransform& t2)
    {
        hkVec4 extraTrans;
        extraTrans.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(extraTrans, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(m_rotation), nullptr, (const ::fnv_00c66320::__m128 *)(&t1.m_rotation), (const ::fnv_00c66320::__m128 *)(const ::fnv_00ce1ad0::FUN_005611c0_t *)(&t2.m_rotation));
        m_vScale.set(_mm_mul_ps(_mm_load_ps(&t1.m_vScale.x), t2.m_vScale.get()));
    }
};

struct RagMotion
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void SetTranslationalVelocity(const float* v);
    virtual void SetRotationalVelocity(const float* v);
};

struct UnkCall
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
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    RagMotion m_pMotionState;
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
    __m128 m_kTranslationalVelocity;
    __m128 m_kAngularVelocity;


    void SetTranslationalVelocity(const float* v)
    {
        reinterpret_cast<::hkpEntityC9C *>(this)->FUN_00c9c1d0();
        m_pMotionState.SetTranslationalVelocity(v);
    }
    void SetRotationalVelocity(const float* v)
    {
        reinterpret_cast<::hkpEntityC9C *>(this)->FUN_00c9c1d0();
        m_pMotionState.SetRotationalVelocity(v);
    }
};

struct RagSkeleton
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_kBones;
    int m_iBoneCount;
};

struct RagInstance
{
    int unk00;
    int unk04;
    UnkCall** m_ppRigidBodies;
    int m_iRigidBodyCount;
    int m_rigidBodiesCap;
    void** m_ppConstraints;
    int m_iConstraintCount;
    int m_constraintsCap;
    int* m_kBoneMap;
    int m_numMap;
    int m_mapCap;
    RagSkeleton* m_pSkeleton;

    UnkCall* getRigidBodyOfBone(int b) const
    {
        int rbIdx = m_kBoneMap[b];
        if (rbIdx < 0)
            return 0;
        return m_ppRigidBodies[rbIdx];
    }

    void FUN_00ce1ad0(const RagQsTransform* pose, const RagQsTransform& worldFromModel);
};

static __forceinline bool equals4(const __m128& a, const float* v)
{
    __m128 t =
        _mm_and_ps(_mm_sub_ps(reinterpret_cast<const __m128&>(*v), a), reinterpret_cast<const __m128&>((*reinterpret_cast<const float *>((void *)&::DAT_01017d10))));
    __m128 eps = _mm_set1_ps(1e-3f);
    return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 0xf) == 0xf;
}

// @fnv 0x00ce1ad0
void RagInstance::FUN_00ce1ad0(const RagQsTransform* pose, const RagQsTransform& worldFromModel)
{
    int numBones = m_pSkeleton->m_iBoneCount;
    for (int b = 0; b < numBones; b++, pose++)
    {
        UnkCall* rb = getRigidBodyOfBone(b);
        if (rb)
        {
            RagQsTransform rbWorld;
            rbWorld.SetProduct(worldFromModel, *pose);
            reinterpret_cast<::FUN_005611c0_t *>(&(rbWorld.m_rotation))->FUN_005611c0();
            reinterpret_cast<::FUN_00ca8860_cls *>((rb))->FUN_00ca8860((intptr_t)(&rbWorld.m_vTranslation), (intptr_t)(&rbWorld.m_rotation));

            const float* zero = &::DAT_01267e30;
            if (!equals4(rb->m_kTranslationalVelocity, zero))
                rb->SetTranslationalVelocity(zero);
            if (!equals4(rb->m_kAngularVelocity, zero))
                rb->SetRotationalVelocity(zero);
        }
    }
}
}
extern float DAT_01017d00;

namespace PoseVelocityDetails {

static const float DAT_01017d00 = 0.001f;

struct __declspec(align(16)) PoseVelocity_QuadFloats
{
    float x, y, z, w;
};
struct __declspec(align(16)) PoseVelocity_QuadBits
{
    unsigned x, y, z, w;
};
static const PoseVelocity_QuadFloats PoseVelocity_halfBias = {-0.5f, -0.5f, -0.5f, -0.5f};
static const PoseVelocity_QuadBits DAT_01017d10 = {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff};

struct PoseVelocity_ScalarLane
{
    PoseVelocity_ScalarLane()
    {}
    PoseVelocity_ScalarLane(float x)
    {
        value = _mm_load_ss(&x);
    }
    __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }

    PoseVelocity_ScalarLane(const __m128& q) : value(q)
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
    const __m128& getQuad() const
    {
        return value;
    }
    __m128 value;
};

class PoseVelocity_QuadValue
{
    __m128 lanes;

  public:
    __forceinline operator __m128() const
    {
        return lanes;
    }
    __forceinline void operator=(const __m128& value)
    {
        lanes = value;
    }
};
struct PoseVelocity_MyVector4
{
    PoseVelocity_QuadValue quad;

    PoseVelocity_MyVector4()
    {}
    void operator=(const __m128& q)
    {
        quad = q;
    }
    __forceinline PoseVelocity_ScalarLane dot4(const PoseVelocity_MyVector4& other) const
    {
        __m128 product = _mm_mul_ps(quad, other.quad);
        __m128 pairs = _mm_add_ps(_mm_shuffle_ps(product, product, 78), product);
        __m128 opposite = _mm_shuffle_ps(pairs, pairs, 177);
        return _mm_add_ps(pairs, opposite);
    }
    __forceinline PoseVelocity_ScalarLane length3() const
    {
        return _mm_sqrt_ss(dot3(*this).getQuad());
    }
    __forceinline void normalize(int dimensions)
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 square = dimensions == 3 ? dot3(*this).getQuad() : dot4(*this).getQuad();
        const __m128 isZero = _mm_cmpeq_ss(square, zero);
        const __m128 estimate = _mm_rsqrt_ss(square);
        const __m128 refined = _mm_mul_ss(_mm_mul_ss(half, estimate),
                                          _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(square, estimate), estimate)));
        PoseVelocity_ScalarLane reciprocal(_mm_andnot_ps(isZero, refined));
        quad = _mm_mul_ps(reciprocal.splat(), quad);
    }
    __forceinline void combine(const PoseVelocity_MyVector4& xyz, const PoseVelocity_MyVector4& real)
    {
        quad = _mm_shuffle_ps(xyz.quad, _mm_unpackhi_ps(xyz.quad, real.quad), 196);
    }
    __forceinline void setAdd4(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b)
    {
        quad = _mm_add_ps(a.quad, b.quad);
    }
    __forceinline void setSub4(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b)
    {
        quad = _mm_sub_ps(a.quad, b.quad);
    }
    __forceinline void setMul4(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b)
    {
        quad = _mm_mul_ps(a.quad, b.quad);
    }
    __forceinline void mul4(const PoseVelocity_ScalarLane& s)
    {
        quad = _mm_mul_ps(s.splat(), quad);
    }
    __forceinline void setZero4()
    {
        quad = _mm_setzero_ps();
    }
    __forceinline void broadcastFrom(const PoseVelocity_MyVector4& source, int lane)
    {
        if (lane == 3)
            quad = _mm_shuffle_ps(source.quad, source.quad, 255);
        else
            quad = _mm_shuffle_ps(source.quad, source.quad, 0);
    }
    __forceinline void broadcastLow()
    {
        quad = _mm_shuffle_ps(quad, quad, 0);
    }
    __forceinline void addProduct(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b)
    {
        quad = _mm_add_ps(quad, _mm_mul_ps(a.quad, b.quad));
    }
    __forceinline void addProduct(const PoseVelocity_ScalarLane& a, const PoseVelocity_MyVector4& b)
    {
        quad = _mm_add_ps(quad, _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0), b.quad));
    }
    __forceinline void sumProduct(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b,
                                  const PoseVelocity_MyVector4& c)
    {
        quad = _mm_add_ps(a.quad, _mm_mul_ps(b.quad, c.quad));
    }
    __forceinline PoseVelocity_ScalarLane dot3(const PoseVelocity_MyVector4& other) const
    {
        __m128 products = _mm_mul_ps(quad, other.quad);
        __m128 firstPair = _mm_add_ss(_mm_shuffle_ps(products, products, 85), products);
        return _mm_add_ss(_mm_shuffle_ps(products, products, 170), firstPair);
    }
    __forceinline void crossOf(const PoseVelocity_MyVector4& a, const PoseVelocity_MyVector4& b)
    {
        __m128 firstProduct = _mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 201), _mm_shuffle_ps(b.quad, b.quad, 210));
        __m128 secondProduct = _mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 210), _mm_shuffle_ps(b.quad, b.quad, 201));
        quad = _mm_sub_ps(firstProduct, secondProduct);
    }
    __forceinline void SetRotatedDirection(const PoseVelocity_MyVector4& q, const PoseVelocity_MyVector4& v)
    {
        PoseVelocity_MyVector4 bias;
        bias.quad = *reinterpret_cast<const __m128*>(&PoseVelocity_halfBias);
        PoseVelocity_MyVector4 realPart;
        realPart.broadcastFrom(q, 3);
        PoseVelocity_MyVector4 realFactor;
        realFactor.sumProduct(bias, realPart, realPart);
        PoseVelocity_MyVector4 accum;
        accum.setMul4(v, realFactor);
        PoseVelocity_MyVector4 projection;
        projection.quad = q.dot3(v).value;
        projection.broadcastLow();
        accum.addProduct(projection, q);
        PoseVelocity_MyVector4 cross;
        cross.crossOf(q, v);
        accum.addProduct(realPart, cross);
        setAdd4(accum, accum);
    }
    __forceinline bool equals4(const PoseVelocity_MyVector4& other, float epsilon) const
    {
        PoseVelocity_MyVector4 difference;
        difference.setSub4(*this, other);
        difference.quad = _mm_and_ps(difference.quad, *reinterpret_cast<const __m128*>(&DAT_01017d10));
        PoseVelocity_MyVector4 eps;
        eps.quad = _mm_set_ps1(epsilon);
        __m128 comparison = _mm_cmple_ps(difference.quad, eps.quad);
        return (_mm_movemask_ps(comparison) & 15) == 15;
    }
};

struct PoseVelocity_MyQuaternion
{
    PoseVelocity_MyVector4 m_vec;
    inline void FUN_00c66320(const PoseVelocity_MyQuaternion& a, const PoseVelocity_MyQuaternion& b);
    inline void FUN_005611c0();
    inline void FUN_00c74ac0(const PoseVelocity_MyQuaternion& a, const PoseVelocity_MyQuaternion& b);
    inline void FUN_00c74c90(PoseVelocity_MyVector4& axis);
    inline float GetAngle();

    __forceinline bool hasValidAxis() const
    {
        return float(m_vec.length3()) > 1.192092896e-7f;
    }
};

inline void PoseVelocity_MyQuaternion::FUN_005611c0()
{
    m_vec.normalize(4);
}
inline void PoseVelocity_MyQuaternion::FUN_00c66320(const PoseVelocity_MyQuaternion& first,
                                                    const PoseVelocity_MyQuaternion& second)
{
    PoseVelocity_MyVector4 imaginary;
    imaginary.crossOf(first.m_vec, second.m_vec);
    PoseVelocity_ScalarLane firstReal(_mm_shuffle_ps(first.m_vec.quad, first.m_vec.quad, 255));
    imaginary.addProduct(firstReal, second.m_vec);
    PoseVelocity_ScalarLane secondReal(_mm_shuffle_ps(second.m_vec.quad, second.m_vec.quad, 255));
    imaginary.addProduct(secondReal, first.m_vec);
    PoseVelocity_MyVector4 dot;
    dot.quad = first.m_vec.dot3(second.m_vec).splat();
    PoseVelocity_MyVector4 real;
    real.setMul4(first.m_vec, second.m_vec);
    real.quad = _mm_sub_ps(real.quad, dot.quad);
    m_vec.combine(imaginary, real);
}
inline void PoseVelocity_MyQuaternion::FUN_00c74ac0(const PoseVelocity_MyQuaternion& first,
                                                    const PoseVelocity_MyQuaternion& second)
{
    PoseVelocity_MyVector4 imaginary;
    imaginary.crossOf(second.m_vec, first.m_vec);
    PoseVelocity_ScalarLane firstReal(_mm_shuffle_ps(first.m_vec.quad, first.m_vec.quad, 255));
    imaginary.quad = _mm_sub_ps(imaginary.quad, _mm_mul_ps(firstReal.splat(), second.m_vec.quad));
    PoseVelocity_ScalarLane secondReal(_mm_shuffle_ps(second.m_vec.quad, second.m_vec.quad, 255));
    imaginary.addProduct(secondReal, first.m_vec);
    PoseVelocity_MyVector4 real;
    real.quad = first.m_vec.dot4(second.m_vec).splat();
    m_vec.combine(imaginary, real);
}
inline void PoseVelocity_MyQuaternion::FUN_00c74c90(PoseVelocity_MyVector4& output)
{
    PoseVelocity_MyVector4 axis;
    axis = m_vec;
    axis.normalize(3);
    if (_mm_movemask_ps(_mm_cmplt_ps(m_vec.quad, _mm_setzero_ps())) & 8)
    {
        static const PoseVelocity_QuadBits sign = {0x80000000, 0x80000000, 0x80000000, 0x80000000};
        axis.quad = _mm_xor_ps(axis.quad, *reinterpret_cast<const __m128*>(&sign));
    }
    output = axis;
}
extern "C" double __cdecl acos(double);
extern "C" double __cdecl fabs(double);
inline float PoseVelocity_safeAcos(float input)
{
    if ((float)fabs(input) >= 1.0f)
        return input > 0.0f ? 0.0f : 3.14159265358979f;
    return (float)acos(input);
}
inline float PoseVelocity_MyQuaternion::GetAngle()
{
    float value = (float)fabs(reinterpret_cast<const float*>(&m_vec)[3]);
    value = PoseVelocity_safeAcos(value);
    value *= 2.0f;
    return value;
}

struct PoseVelocity_MyQsTransform
{
    PoseVelocity_MyVector4 m_vTranslation;
    PoseVelocity_MyQuaternion m_rotation;
    PoseVelocity_MyVector4 m_vScale;

    __forceinline void SetProduct(const PoseVelocity_MyQsTransform& a, const PoseVelocity_MyQsTransform& b)
    {
        PoseVelocity_MyVector4 translated;
        translated.SetRotatedDirection(a.m_rotation.m_vec, b.m_vTranslation);
        m_vTranslation.setAdd4(a.m_vTranslation, translated);
        m_rotation.FUN_00c66320(a.m_rotation, b.m_rotation);
        m_vScale.setMul4(a.m_vScale, b.m_vScale);
    }
};

struct PoseVelocity_RagdollPoseUpdater : public hkaRagdollInstance
{
    void FUN_00ce1ca0(const PoseVelocity_MyQsTransform* poseA, const PoseVelocity_MyQsTransform& worldFromModelA,
                      const PoseVelocity_MyQsTransform* poseB, const PoseVelocity_MyQsTransform& worldFromModelB,
                      float deltaTime);
};

// @fnv 0x00ce1ca0
void PoseVelocity_RagdollPoseUpdater::FUN_00ce1ca0(const PoseVelocity_MyQsTransform* poseA,
                                                   const PoseVelocity_MyQsTransform& worldFromModelA,
                                                   const PoseVelocity_MyQsTransform* poseB,
                                                   const PoseVelocity_MyQsTransform& worldFromModelB, float deltaTime)
{
    float inverseDeltaTime;
    long boneCount = m_pSkeleton->m_kBones.m_iElementCount;
    inverseDeltaTime = 1.0f / deltaTime;
    for (int i = 0; i < boneCount; ++i)
    {
        int bodyIndex = m_kBoneMap.m_data[i];
        if (bodyIndex >= 0)
        {
            hkpRigidBody* body;
            body = (hkpRigidBody*)m_ppRigidBodies.m_data[bodyIndex];
            if ((bool)body)
            {
                PoseVelocity_MyQsTransform worldPoseA;
                worldPoseA.SetProduct(worldFromModelA, poseA[i]);
                reinterpret_cast<::FUN_005611c0_t *>(&(worldPoseA.m_rotation))->FUN_005611c0();

                PoseVelocity_MyQsTransform worldPoseB;
                worldPoseB.SetProduct(worldFromModelB, poseB[i]);
                reinterpret_cast<::FUN_005611c0_t *>(&(worldPoseB.m_rotation))->FUN_005611c0();

                reinterpret_cast<::FUN_00ca8860_cls *>((body))->FUN_00ca8860((intptr_t)&(reinterpret_cast<const hkVector4&>(worldPoseB.m_vTranslation)),
                                   (intptr_t)&(reinterpret_cast<const hkQuaternion&>(worldPoseB.m_rotation)));

                PoseVelocity_MyVector4 linearVelocity;
                linearVelocity.setSub4(worldPoseB.m_vTranslation, worldPoseA.m_vTranslation);
                linearVelocity.mul4(inverseDeltaTime);
                if (!linearVelocity.equals4(
                        reinterpret_cast<const PoseVelocity_MyVector4&>(body->m_pMotionState.m_kTranslationalVelocity),
                        DAT_01017d00))
                {
                    reinterpret_cast<::hkpEntityC9C *>((body))->FUN_00c9c1d0();
                    body->m_pMotionState.SetTranslationalVelocity(reinterpret_cast<const hkVector4&>(linearVelocity));
                }

                PoseVelocity_MyQuaternion relativeRotation;
                reinterpret_cast<::Quat74 *>(&(relativeRotation))->FUN_00c74ac0((const ::Quat74 &)(worldPoseB.m_rotation), (const ::Quat74 &)(worldPoseA.m_rotation));
                reinterpret_cast<::FUN_005611c0_t *>(&(relativeRotation))->FUN_005611c0();

                PoseVelocity_MyVector4 angularVelocity;
                if (!relativeRotation.hasValidAxis())
                {
                    angularVelocity.setZero4();
                }
                else
                {
                    float angle = reinterpret_cast<::C74C20Quat *>(&(relativeRotation))->GetAngle();
                    relativeRotation.FUN_00c74c90(angularVelocity);
                    angularVelocity.mul4(angle * inverseDeltaTime);
                }

                if (!angularVelocity.equals4(
                        reinterpret_cast<const PoseVelocity_MyVector4&>(body->m_pMotionState.m_kAngularVelocity),
                        DAT_01017d00))
                {
                    reinterpret_cast<::hkpEntityC9C *>((body))->FUN_00c9c1d0();
                    body->m_pMotionState.SetRotationalVelocity(reinterpret_cast<const hkVector4&>(angularVelocity));
                }
            }
        }
    }
}

}


// @fnv 0x00ce18d0
void FUN_00ce18d0(intptr_t a, hkQsTransformC17* pkPoseOut)
{
    reinterpret_cast<::Ragdoll4 *>((a))->FUN_00ce1760(pkPoseOut, *(const ::hkQsTransformC17 *)(&DAT_01268700), nullptr);
}

// Iterates over data->count entries, calling FUN_00ce2150 with each index, value and successive transform.
// @fnv 0x00ce2430
void FUN_00ce2430_Class::ApplyValueToTransforms(float value, FUN_00ce2430_Transform* transforms)
{
    int count = this->data->count;

    for (int i = 0; i < count; ++i)
    {
        reinterpret_cast<::FUN_00ce2150Owner *>((this))->FUN_00ce2150(i, value, (*(::hkQsTransformC21 *)(transforms)));
        ++transforms;
    }
}

#include "generated/data/havok/animation/ragdoll/instance/hkaragdollinstance.inc"
