
// src/havok/physics/utilities/actions/mousespring/hkpmousespringaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/mousespring/hkpmousespringaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <xmmintrin.h>
#include <new>
#include "fnv/decl/FUN_00cd8160.h"
#include "fnv/decl/FUN_00d2b260.h"
#include "fnv/decl/FUN_00d2b2b0_class.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_00cd4000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101b000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_01268000.h"
#include "havok/hkpMouseSpringAction.h"

struct FUN_00d2b1f0
{
    void EntityRemovedCallback(int);
};

struct FUN_00cbb1c0 : FUN_00d2b1f0
{
    void Method(int);
};

// @fnv 0x00cbb1c0
void FUN_00cbb1c0::Method(int aiValue)
{
    EntityRemovedCallback(aiValue);
    *(int*)((char*)this + 0x18) = 0;
}

struct FUN_00cbb1b0_Class
{
    char pad0[0x48];
    hkReal m_fMaxRelativeForce;
    void FUN_00cbb1b0(hkReal a);
};

// @fnv 0x00cbb1b0
void FUN_00cbb1b0_Class::FUN_00cbb1b0(hkReal a)
{
    m_fMaxRelativeForce = a;
}


// @fnv 0x00cbb8a0
const void* __cdecl FUN_00cbb8a0()
{
    return &::g_01268a14;
}

#include "fnv/symbols_simd.h"

extern int DAT_010c8e94;
extern const char str_011b1f3c[];

struct Ms_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int* n);
    virtual void ReturnMemory(void* p, int n);
};
struct Ms_Tls
{
    int u0;
    int u1;
    int u2;
    int u3;
    Ms_Heap* heap;
};
static inline Ms_Tls* getMemoryRouter() { return static_cast<Ms_Tls*>(::FUN_00c85750()); }

struct Ms_ArrInit
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
};
struct Ms_Arr
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
};

struct Ms_Sphere
{
    int v0;
    int v1;
    int v2;
    int type;
    float radius;
    int u5;
    int u6;
    int u7;
};
struct Ms_Xf
{
    __m128 c0;
    __m128 c1;
    __m128 c2;
    __m128 t;
};
struct Ms_Body
{
    int u0;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    int u11;
    int u12;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    void FUN_00cd2d80(Ms_Sphere* s, Ms_Xf* x, int parent);
};

struct Ms_Input
{
    int i0;
    int i1;
    int i2;
    int i3;
    int i4;
    int i5;
    int i6;
    int i7;
    __m128 q0;
    __m128 q1;
    __m128 q2;
};
struct Ms_Coll
{
    int* vptr;
    float early;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    float dist;
    int hit;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    int u20;
    int u21;
    int u22;
    int key;
    int u24;
    int u25;
    int u26;
    int u27;
    int u28;
    int u29;
    int u30;
    int u31;
};

struct Ms_Shape
{
    int u0;
    int u1;
    int u2;
    int type;
};
struct Ms_Disp
{
    int unk00;
};
struct Ms_World
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
    Ms_Input* input;
    int unk7c;
    Ms_Disp* disp;
};
struct Ms_Ent
{
    int u0;
    int u1;
    Ms_World* world;
    int u3;
    Ms_Shape* shape;
};
typedef void(__cdecl* Ms_Fn)(Ms_Body*, void*, Ms_Input*, Ms_Coll*);
struct Ms_B
{
};
struct Ms_N
{
};
struct Fv
{
    float x;
    float y;
    float z;
    float w;
};
struct Ms_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Fv pos;
    Fv mouse;
    float damping;
    float elasticity;
    float maxRel;
    float objDamping;
    int shapeKey;
    Ms_ArrInit cb;
    Ms_cls* FUN_00cbb560(__m128* a0, __m128* a1, float a2, float a3, float a4, Ms_Ent* a5, Ms_Arr* a6);
};

namespace fnv_00cbb790 {
struct hkAllocatorCBB7
{
    virtual void V0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void V2() throw();
    virtual void* AllocateBufferWithSize(int& iNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCBB7
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    hkAllocatorCBB7* m_pStreamAllocator;
};
static inline void* getMemoryRouter() { return ::FUN_00c85750(); }
inline hkAllocatorCBB7& heapCBB7()
{
    return *((hkMemoryRouterCBB7*)getMemoryRouter())->m_pStreamAllocator;
}

template <typename T> inline void copyCBB7(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

template <typename T> struct hkArrayCBB7
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline hkArrayCBB7& operator=(const hkArrayCBB7& kOther)
    {
        hkAllocatorCBB7& kAlloc = heapCBB7();
        if (getCapacity() < kOther.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int iNumBytes = kOther.m_iElementCount * sizeof(T);
            m_data = (T*)kAlloc.AllocateBufferWithSize(iNumBytes);
            m_iCapacityState = iNumBytes / (int)sizeof(T);
        }
        m_iElementCount = kOther.m_iElementCount;
        copyCBB7(m_data, kOther.m_data, m_iElementCount);
        return *this;
    }
};

struct __declspec(align(16)) hkVector4CBB7
{
    __m128 m_vComponents;
    void operator=(const hkVector4CBB7& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class hkpEntity;

class FUN_00cbb4e0 : public hkpUnaryAction
{
  public:
    hkUint32 m_1c;
    hkVector4CBB7 m_kMousePositionInWorld;
    hkVector4CBB7 m_kGrabPointInBodySpace;
    hkReal m_fSpringDamping;
    hkReal m_fSpringElasticity;
    hkReal m_fMaxRelativeForce;
    hkReal m_fTau;
    hkUint32 m_uiCollisionShapeKey;
    hkArrayCBB7<void*> m_kAppliedCallbacks;

    FUN_00cbb4e0(hkpEntity* pkEntity) throw();

    void* operator new(size_t uiSize)
    {
        hkMemoryRouterCBB7* pkRouter = (hkMemoryRouterCBB7*)getMemoryRouter();
        hkReferencedObject* pkObj = (hkReferencedObject*)pkRouter->m_pStreamAllocator->AllocateMemoryBlock(uiSize);
        pkObj->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return pkObj;
    }

    FUN_00cbb4e0* CloneForEntity(const hkArrayCBB7<hkpEntity*>& kNewEntities,
                                 const hkArrayCBB7<void*>& kNewPhantoms) const throw();
};

// Creates a copy of this action for a single entity, returning null if the entity count is not one or any phantoms are present.
// @fnv 0x00cbb790
FUN_00cbb4e0* FUN_00cbb4e0::CloneForEntity(const hkArrayCBB7<hkpEntity*>& kNewEntities,
                                           const hkArrayCBB7<void*>& kNewPhantoms) const throw()
{
    if (kNewEntities.GetLogicalSize() != 1)
        return 0;
    if (kNewPhantoms.GetLogicalSize() != 0)
        return 0;

    FUN_00cbb4e0* pkAction = new FUN_00cbb4e0(kNewEntities[0]);
    pkAction->m_kMousePositionInWorld = m_kMousePositionInWorld;
    pkAction->m_kGrabPointInBodySpace = m_kGrabPointInBodySpace;
    pkAction->m_fSpringDamping = m_fSpringDamping;
    pkAction->m_fSpringElasticity = m_fSpringElasticity;
    pkAction->m_fMaxRelativeForce = m_fMaxRelativeForce;
    pkAction->m_fTau = m_fTau;
    pkAction->m_ulUserData = m_ulUserData;
    pkAction->m_uiCollisionShapeKey = m_uiCollisionShapeKey;
    pkAction->m_kAppliedCallbacks = m_kAppliedCallbacks;
    return pkAction;
}
}  // namespace fnv_00cbb790

class FUN_00d01a60
{
  public:
    FUN_00d01a60();
    int unk00[11];
};


class hkpCdBodyCD2D
{
  public:
    hkpCdBodyCD2D(const void* shape, const void* motionState)
    {
        m_pCollisionShape = shape;
        m_pMotionState = motionState;
        m_parent = 0;
        m_uiCollisionShapeKey = 0xffffffff;
    }
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyCD2D* m_parent;
};

class hkpBroadPhaseHandleCD2D
{
  public:
    hkpBroadPhaseHandleCD2D()
    {
        m_iOwnerObjectOffset = 0;
    }
    unsigned int m_iOwnerObjectOffset;
};

class hkpTypedBroadPhaseHandleCD2D : public hkpBroadPhaseHandleCD2D
{
  public:
    hkpTypedBroadPhaseHandleCD2D(int type)
    {
        m_type = (signed char)type;
        m_ucObjectQualityType = -1;
        m_uiCollisionFilterData = 0;
        m_iOwnerOffset = 0x7f;
    }
    void SetOwnerPointer(void* owner)
    {
        int offset = (int)((char*)owner - (char*)this);
        m_iOwnerOffset = (signed char)offset;
    }
    signed char m_type;
    signed char m_iOwnerOffset;
    signed char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
};

class FUN_00cd2d80 : public hkpCdBodyCD2D
{
  public:
    FUN_00cd2d80(const void* shape, const void* motionState, int type);

    signed char m_iOwnerOffset;
    signed char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    hkpTypedBroadPhaseHandleCD2D m_kBroadPhaseHandle;
    FUN_00d01a60 m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;
};
// Initializes the Ms_cls object with position, mouse, and damping parameters, copies an array, and computes a shape key via a collision test against the world.
// @fnv 0x00cbb560
Ms_cls* Ms_cls::FUN_00cbb560(__m128* apPos, __m128* apMouse, float afDamping, float afElasticity, float afObjDamping,
                             Ms_Ent* apEnt, Ms_Arr* apArr)
{
    new ((void *)(((Ms_B*)this))) ::FUN_00d2b260((::FUN_00c90510_Entity *)(apEnt), 0);
    *(int**)this = &DAT_010c8e94;
    _mm_store_ps(&pos.x, *apPos);
    _mm_store_ps(&mouse.x, *apMouse);
    damping = afDamping;
    elasticity = afElasticity;
    objDamping = afObjDamping;
    cb.init();
    maxRel = 250.0f;
    if (apArr)
    {
        Ms_Heap& h = *getMemoryRouter()->heap;
        int cap = cb.m_cap & 0x3fffffff;
        if (cap < apArr->m_iElementCount)
        {
            if ((cb.m_cap & 0x80000000) == 0)
                h.ReturnMemory(cb.m_data, cap * 4);
            int n = apArr->m_iElementCount * 4;
            cb.m_data = (int*)h.AllocateBufferWithSize(&n);
            cb.m_cap = n / 4;
        }
        int cnt = apArr->m_iElementCount;
        cb.m_iElementCount = cnt;
        int* dst = cb.m_data;
        int* src = apArr->m_data;
        for (int i = 0; i < cnt; i++)
            dst[i] = src[i];
    }
    Ms_World* w = apEnt->world;
    shapeKey = -1;
    if (w)
    {
        Ms_Sphere sph;
        new ((void *)&(sph)) ::FUN_00cd8160(1.0f);
        Ms_Xf* ident = ((::Ms_Xf *)(::FUN_00cd4b50()));
        Ms_Xf xf;
        xf.c0 = ident->c0;
        xf.c1 = ident->c1;
        xf.c2 = ident->c2;
        xf.t = *apMouse;
        Ms_Body body;
        new ((void *)&(body)) ::FUN_00cd2d80(&sph, &xf, 0);
        Ms_Disp* d = w->disp;
        unsigned char t = *((unsigned char*)d + (((sph.type + 13) << 5) + apEnt->shape->type));
        Ms_Fn fn = *(Ms_Fn*)((char*)d + t * 20 + 0x9a8);
        Ms_Input in;
        Ms_Input* src = w->input;
        in.i0 = src->i0;
        in.i1 = src->i1;
        in.i2 = src->i2;
        in.i3 = src->i3;
        in.i4 = src->i4;
        in.i5 = src->i5;
        in.q0 = src->q0;
        in.q1 = src->q1;
        in.q2 = src->q2;
        Ms_Coll coll;
        coll.dist = ::DAT_0104da48;
        coll.early = ::DAT_0104da48;
        coll.vptr = &DAT_010c476c;
        coll.hit = 0;
        fn(&body, &apEnt->shape, &in, &coll);
        if (coll.hit)
            shapeKey = coll.key;
    }
    reinterpret_cast<::SStringPtr *>((((Ms_N*)&unk14)))->FUN_00cb0c10(str_011b1f3c);
    return this;
}

// Constructs the body from shape and motionState, builds the broad phase handle with type, sets its owner pointer, and sets a default allowed penetration depth.
// @fnv 0x00cd2d80
FUN_00cd2d80::FUN_00cd2d80(const void* apCollisionShape, const void* motionState, int aiBroadPhaseType)
    : hkpCdBodyCD2D(apCollisionShape, motionState), m_iOwnerOffset(0), m_kBroadPhaseHandle(aiBroadPhaseType),
      m_fAllowedPenetrationDepth(DAT_01012054)
{
    m_kBroadPhaseHandle.SetOwnerPointer(this);
    m_uiForceCollideOntoPpu = 0;
    m_uiShapeSizeOnSpu = 0;
}

struct Ms_Tls;

struct Ms_HeapX
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void* p, unsigned short n);
    virtual void v0c();
    virtual void v10(int p, int n);
};

struct Cls
{
    void* m_vt;          // 0x00
    int m_04;            // 0x04 (word)
    char m_pad08[0x4c];  // to 0x54
    int m_54;
    int m_58;
    int m_5c;
    Cls* FUN_00cbb8b0(int flags);
};

// Clears the array at m_54 and releases its buffer unless flagged, calls FUN_00d2b2b0, and frees this through the TLS heap when bit 0 of flags is set.
// @fnv 0x00cbb8b0
Cls* Cls::FUN_00cbb8b0(int flags)
{
    Ms_Tls* tls = getMemoryRouter();
    Ms_HeapX* heap = *(Ms_HeapX**)&tls->heap;
    int n = m_5c;
    m_58 = 0;
    if (!((unsigned int)n & 0x80000000u))
        heap->v10(m_54, (n & 0x3fffffff) * 4);
    m_54 = 0;
    m_5c = 0x80000000;
    reinterpret_cast<::FUN_00d2b2b0_class *>(this)->FUN_00d2b2b0();
    if (flags & 1)
    {
        Ms_Tls* tls2 = getMemoryRouter();
        Ms_HeapX* heap2 = *(Ms_HeapX**)&tls2->heap;
        heap2->v08(this, (unsigned short)m_04);
    }
    return this;
}




struct __declspec(align(16)) hkVector4CBB1
{
    __m128 m_vComponents;
    void operator=(const hkVector4CBB1& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class UnkCall
{
  public:
    int unk00;
    int unk04;
    int m_pOwningWorld;

};

class hkpPositionTrackerCBB1
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    UnkCall* m_pOwnerObject;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkVector4CBB1 m_vContactPosition;

    void FUN_00cbb150(const hkVector4CBB1& kPosition);
};

// @fnv 0x00cbb150
void hkpPositionTrackerCBB1::FUN_00cbb150(const hkVector4CBB1& kPosition)
{
    __m128 d = _mm_sub_ps(kPosition.m_vComponents, m_vContactPosition.m_vComponents);
    d = _mm_and_ps(d, DAT_01017d10);
    __m128 eps = _mm_load_ps1(&::AngularDashpotApplyD4DCB0::DAT_01017d00);
    int iMask = _mm_movemask_ps(_mm_cmple_ps(d, eps));
    if ((iMask & 7) != 7)
    {
        if (m_pOwnerObject && m_pOwnerObject->m_pOwningWorld)
            reinterpret_cast<::hkpEntityC9C *>((m_pOwnerObject))->FUN_00c9c1d0();
    }
    m_vContactPosition = kPosition;
}

struct FUN_00cbb4e0
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0C;
    unsigned int unk10;
    hkStringPtr m_name;
    void* m_pEntity;
    unsigned int unk1C;
    hkVector4 m_kMousePositionInWorld;
    hkVector4 m_kGrabPointInBodySpace;
    hkReal m_fSpringDamping;
    hkReal m_fSpringElasticity;
    hkReal m_fMaxRelativeForce;
    hkReal m_fTau;
    unsigned int m_uiCollisionShapeKey;
    hkArray<char> m_kAppliedCallbacks;
    FUN_00cbb4e0(void* arg);
};
// Initializes the hkpMouseSpringAction fields with default spring constants, zeroed vectors, and the action name.
// @fnv 0x00cbb4e0
FUN_00cbb4e0::FUN_00cbb4e0(void* arg)
{
    new ((void *)(((Ms_B*)this))) ::FUN_00d2b260(static_cast<::FUN_00c90510_Entity *>(arg), 0);
    m_fSpringDamping = ::fnv_00c88020::DAT_01016248;
    unk00 = (void*)&DAT_010c8e94;
    m_fSpringElasticity = DAT_01017870;
    __m128 zero = _mm_setzero_ps();
    m_fMaxRelativeForce = DAT_0101b2d0;
    m_fTau = ::g_011cc6cc_arg1;
    *(char* volatile*)&m_kAppliedCallbacks.m_data = 0;
    *(volatile int*)&m_kAppliedCallbacks.m_iElementCount = 0;
    *(volatile int*)&m_kAppliedCallbacks.m_iCapacityState = 0x80000000;
    _mm_store_ps((float*)&m_kMousePositionInWorld, zero);
    _mm_store_ps((float*)&m_kGrabPointInBodySpace, zero);
    m_uiCollisionShapeKey = 0xFFFFFFFF;
    reinterpret_cast<::SStringPtr *>((((Ms_N*)&m_name)))->FUN_00cb0c10("hkpMouseSpringAction");
}

// Moved from hkpmousespringaction_rtm_variant.cpp (VEGAS-15).
#include <cmath>
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/FUN_00561800_Class.h"
#include "fnv/decl/FUN_00c7f750_shell.h"
#include "fnv/decl/MProduct.h"
#include "fnv/decl/MotionMassView.h"
#include "fnv/decl/S00cd4cc0_M.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_0106c000.h"
const void* __cdecl FUN_00cbb8a0();



struct hkStepInfo
{
    hkReal m_uiStartTime;
    hkReal m_fEndTime;
    hkReal m_fTimeStep;
    hkReal m_fInverseDeltaTime;
};

struct FUN_00ca86c0_class
{
    void* FUN_00ca86c0();
};

struct FUN_00cdf250_class
{
};

struct Vector4Ext : hkVector4
{
    void FUN_00c7f640(const hkTransform* t, const hkVector4* v);
};

struct Matrix3Ext : FUN_00cdf250_class, hkMatrix3
{
    void Subtract(const hkMatrix3* a);
};

struct MotionExt
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual void unk8();
    virtual void unk9();
    virtual void GetLocalInverseInertia(hkMatrix3* out);
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void ApplyImpulseAtPoint(const hkVector4* impulse, const hkVector4* point);

    int unk04;
    int unk08;
    int unk0c;
    hkTransform m_kMotionTransform;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    hkVector4 m_centerOfMassInWorld;
    hkVector4 unk70;
    hkVector4 unk80;
    hkVector4 unk90;
    hkVector4 unka0;
    hkVector4 unkb0;
    hkVector4 m_kInertiaAndMassInv;
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;

};

struct RigidBodyExt : FUN_00ca86c0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 unk10;
    hkVector4 unk20;
    hkVector4 unk30;
    hkVector4 unk40;
    hkVector4 unk50;
    hkVector4 unk60;
    hkVector4 unk70;
    hkVector4 unk80;
    hkVector4 unk90;
    hkVector4 unka0;
    hkVector4 unkb0;
    hkVector4 unkc0;
    hkVector4 unkd0;
    MotionExt m_pMotionState;

    void FUN_00ca0c40(const hkVector4* point, hkVector4* outVel);
};

typedef void(__cdecl* MouseSpringCallback)(hkpMouseSpringAction*, const hkStepInfo&, const hkVector4&);

struct MouseSpringActionExt : hkpMouseSpringAction
{
    void FUN_00cbb1e0(const hkStepInfo& stepInfo);
};

// @fnv 0x00cbb1e0
void MouseSpringActionExt::FUN_00cbb1e0(const hkStepInfo& stepInfo)
{
    Vector4Ext impulse;
    Vector4Ext worldPos;
    Vector4Ext r;
    Vector4Ext angVel;
    struct MassAndVelocity
    {
        Matrix3Ext K;
        Vector4Ext lin;
        Vector4Ext ang;
    } work;
    Vector4Ext deltaPos;
    Matrix3Ext crossR;
    struct InertiaProducts
    {
        Matrix3Ext tempMat1;
        Matrix3Ext inertiaInvWorld;
        Matrix3Ext tempMat2;
    } matrices;
    float maxImpulse;
    float lenSq;

    RigidBodyExt* rb = (RigidBodyExt*)m_pEntity;

    worldPos.FUN_00c7f640(&rb->m_pMotionState.m_kMotionTransform, &m_kMousePositionInWorld);

    *(__m128*)&deltaPos = _mm_sub_ps(*(__m128*)&worldPos, *(__m128*)&m_kGrabPointInBodySpace);

    MotionExt* motion = rb->FUN_00ca86c0() ? static_cast<MotionExt*>(rb->FUN_00ca86c0()) : &rb->m_pMotionState;

    __m128 invMassVec =
        _mm_shuffle_ps(*(__m128*)&motion->m_kInertiaAndMassInv, *(__m128*)&motion->m_kInertiaAndMassInv, 0xff);
    _mm_store_ss(&maxImpulse, invMassVec);

    *(__m128*)&r = _mm_sub_ps(*(__m128*)&worldPos, *(__m128*)&rb->m_pMotionState.m_centerOfMassInWorld);

    reinterpret_cast<::S00cd4cc0_M *>(&(crossR))->FUN_00cd4cc0((const float *)(const ::hkVector4 *)(&r));

    motion->GetLocalInverseInertia(&matrices.inertiaInvWorld);

    *(__m128*)&work.K.m_kColumn0 = _mm_setzero_ps();
    work.K.m_kColumn0.x = maxImpulse;
    *(__m128*)&work.K.m_kColumn1 = _mm_setzero_ps();
    work.K.m_kColumn1.y = maxImpulse;
    *(__m128*)&work.K.m_kColumn2 = _mm_setzero_ps();
    work.K.m_kColumn2.z = maxImpulse;

    reinterpret_cast<::MProduct *>(&(matrices.tempMat1))->FUN_00cd55b0((*(const ::MProduct *)((int*)&crossR)), (*(const ::MProduct *)(&matrices.inertiaInvWorld)));
    reinterpret_cast<::MProduct *>(&(matrices.tempMat2))->FUN_00cd55b0((*(const ::MProduct *)((int*)&matrices.tempMat1)), (*(const ::MProduct *)(&crossR)));

    work.K.Subtract(&matrices.tempMat2);

    if (reinterpret_cast<::hkMatrix3 *>(&(work.K))->FUN_00cd4f10(DAT_0106c288) == 0)
    {
        *(__m128*)&work.lin = *(__m128*)&rb->m_pMotionState.m_kTranslationalVelocity;
        __m128 dampLoad1 = _mm_load_ss(&m_fTau);
        __m128 dampSplat1 = _mm_shuffle_ps(dampLoad1, dampLoad1, 0);
        *(__m128*)&work.lin = _mm_mul_ps(*(__m128*)&work.lin, dampSplat1);
        reinterpret_cast<::FUN_005616d0_Owner *>((rb))->OnTrigger((::TriggerContext *)(&work.lin));

        *(__m128*)&work.ang = *(__m128*)&rb->m_pMotionState.m_kAngularVelocity;
        __m128 dampLoad2 = _mm_load_ss(&m_fTau);
        __m128 dampSplat2 = _mm_shuffle_ps(dampLoad2, dampLoad2, 0);
        *(__m128*)&work.ang = _mm_mul_ps(*(__m128*)&work.ang, dampSplat2);
        reinterpret_cast<::FUN_00561800_Class *>((rb))->FUN_00561800((::FUN_00561730_Obj *)(&work.ang));

        rb->FUN_00ca0c40(&worldPos, &r);

        float springFactor = m_fSpringElasticity * stepInfo.m_fInverseDeltaTime;
        __m128 term1 =
            _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&springFactor), _mm_load_ss(&springFactor), 0), *(__m128*)&deltaPos);
        *(__m128*)&angVel = term1;
        __m128 sdLoad = _mm_load_ss(&m_fSpringDamping);
        __m128 sdSplat = _mm_shuffle_ps(sdLoad, sdLoad, 0);
        __m128 term2 = _mm_mul_ps(sdSplat, *(__m128*)&r);
        *(__m128*)&angVel = _mm_add_ps(term2, term1);

        reinterpret_cast<::FUN_00c7f750_shell *>(&(impulse))->FUN_00c7f750((float *)(&work.K), (float *)(&angVel));

        *(__m128*)&impulse = _mm_xor_ps(*(__m128*)&impulse, *(__m128*)&(*reinterpret_cast<::hkVector4 *>((void *)&::DAT_010c44d0)));

        __m128 sq = _mm_mul_ps(*(__m128*)&impulse, *(__m128*)&impulse);
        __m128 y = _mm_shuffle_ps(sq, sq, 0x55);
        __m128 xy = _mm_add_ss(y, sq);
        __m128 z = _mm_shuffle_ps(sq, sq, 0xaa);
        __m128 xyz = _mm_add_ss(z, xy);
        _mm_store_ss(&lenSq, xyz);

        maxImpulse = reinterpret_cast<::MotionMassView *>((motion))->FUN_00c86430();
        maxImpulse = stepInfo.m_fTimeStep * maxImpulse * m_fMaxRelativeForce;

        if (lenSq > maxImpulse * maxImpulse)
        {
            float sqrtLen = (float)sqrt(lenSq);
            float invLen = 1.0f / sqrtLen;
            float scale = invLen * maxImpulse;
            *(__m128*)&impulse =
                _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&scale), _mm_load_ss(&scale), 0), *(__m128*)&impulse);
        }

        reinterpret_cast<::hkpEntityC9C *>((rb))->FUN_00c9c1d0();
        rb->m_pMotionState.ApplyImpulseAtPoint(&impulse, &worldPos);

        for (int i = 0; i < m_kAppliedCallbacks.m_iElementCount; ++i)
        {
            ((MouseSpringCallback*)m_kAppliedCallbacks.m_data)[i](this, stepInfo, impulse);
        }
    }
}
#include "generated/data/havok/physics/utilities/actions/mousespring/hkpmousespringaction.inc"
