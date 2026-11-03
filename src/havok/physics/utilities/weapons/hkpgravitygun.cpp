
// src/havok/physics/utilities/weapons/hkpgravitygun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpgravitygun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include <cmath>
#include "fnv/decl/FUN_00c7f690_cls.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00ca88e0_cls.h"
#include "fnv/decl/MotionMassView.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/decl/World_e45e.h"
#include "fnv/decl/fnv_00c91f70__RayWorld.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpGravityGunE45.h"
#include "havok/hkpGravityGun.h"

struct FUN_00e45fb0_class
{
    void FUN_00e45fb0(int, int, int);
};

// @fnv 0x00e45fb0
void FUN_00e45fb0_class::FUN_00e45fb0(int, int, int)
{
    if (*(int*)((char*)this + 0x24) != 0)
        reinterpret_cast<::World_e45e *>(this)->FUN_00e45e60(0);
}

struct DDCC60World
{
    void removeReference();
};

struct FUN_00e45fc0_class
{
    unsigned char m_unknown[0x20];
    DDCC60World** m_kExternalLinks;
    int m_sReferenceCount;

    void RemoveAllReferences(int);
};

// @fnv 0x00e45fc0
void FUN_00e45fc0_class::RemoveAllReferences(int)
{
    int i = 0;
    if (m_sReferenceCount > 0)
    {
        do
        {
            reinterpret_cast<::hkReferencedObjectC905 *>((m_kExternalLinks[i]))->FUN_00c905b0();
            ++i;
        } while (i < m_sReferenceCount);
    }
    m_sReferenceCount = 0;
}

struct hkFinishLoadedObjectFlagE463
{
    int m_bFinishing;
};

template <class T> class hkArrayE463
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE463() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class FUN_00e466a0
{
  public:
    FUN_00e466a0(hkFinishLoadedObjectFlagE463 flag);
    virtual ~FUN_00e466a0();

    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    hkUint8 m_type;
    const char* m_name;
    hkUint8 m_uiKeyboardKey;
    hkArrayE463<void*> m_kListeners;
};

class hkpRigidBodyE463;

class FUN_00e46300 : public FUN_00e466a0
{
  public:
    hkArrayE463<hkpRigidBodyE463*> m_kPickedBodies;

    FUN_00e46300(hkFinishLoadedObjectFlagE463 flag);
    virtual ~FUN_00e46300();
};

// @fnv 0x00e46300
FUN_00e46300::FUN_00e46300(hkFinishLoadedObjectFlagE463 flag) : FUN_00e466a0(flag)
{
    if (flag.m_bFinishing)
        m_type = 3;
}

namespace fnv_00e46340 {
class hkMemoryAllocatorE463
{
  public:
    virtual ~hkMemoryAllocatorE463() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterE463
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE463* m_pStreamAllocator;
    hkMemoryAllocatorE463& heap()
    {
        return *m_pStreamAllocator;
    }
};
static inline hkMemoryRouterE463& getMemoryRouter() { return *static_cast<hkMemoryRouterE463*>(::FUN_00c85750()); }

template <class T> __forceinline void destructE463(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayE463
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayE463() throw()
    {
        ClearAndRelease(getMemoryRouter().heap());
    }
    __forceinline void clear()
    {
        destructE463(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorE463& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00cb0c00_class
{
  public:
    const char* m_pcText;

    void FUN_00cb0c00() throw();
    ~FUN_00cb0c00_class()
    {
        FUN_00cb0c00();
    }
};

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectE463
{
  public:
    virtual ~hkReferencedObjectE463() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        getMemoryRouter().heap().ReleaseBlock(p, static_cast<hkReferencedObjectE463*>(p)->m_usMemSizeAndFlags);
    }
};

class FUN_00e466e0 : public hkReferencedObjectE463
{
  public:
    int m_08;
    FUN_00cb0c00_class m_name;
    int m_10;
    hkArrayE463<FUN_00d1df70*> m_children;

    virtual ~FUN_00e466e0() throw();
};

class hkDerivedE463 : public FUN_00e466e0
{
  public:
    hkArrayE463<int> m_iSlotIds;

    hkDerivedE463* DestroyAndFree(unsigned int uiFlags) throw();
};

// Destroys the object and, when bit 0 of uiFlags is set, frees its memory via operator delete; returns this.
// @fnv 0x00e46340
hkDerivedE463* hkDerivedE463::DestroyAndFree(unsigned int uiFlags) throw()
{
    this->hkDerivedE463::~hkDerivedE463();
    if (uiFlags & 1)
        hkDerivedE463::operator delete(this);
    return this;
}
}  // namespace fnv_00e46340


namespace MathUtilities {
inline hkReal fabs(hkReal r)
{
    return static_cast<hkReal>(::fabs(r));
}
}

struct GGVector4
{
    __m128 m_vComponents;

    void operator=(const GGVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    hkReal& operator()(int i)
    {
        return m_vComponents[i];
    }
};

struct GGMotion
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    GGVector4 m_vCenterOfMass0;
    GGVector4 m_vCenterOfMass1;
    hkReal GetMassValue() const;
};

struct GGCollidable
{
    int c00;
    int c04;
    int c08;
    int c0c;
    int c10;
    int c14;
    int c18;
    int c1c;
    int c20;
    int c24;
    int c28;
    int c2c;
    int c30;
    int c34;
    int c38;
    int c3c;
    int c40;
    int c44;
    int c48;
    int c4c;
    int c50;
    int c54;
    int c58;
    int c5c;
    int c60;
    int c64;
    int c68;
    int c6c;
    int c70;
    int c74;
    int c78;
    int c7c;
    int c80;
    int c84;
    int c88;
    int c8c;
    int c90;
    int c94;
    int c98;
    int c9c;
    int ca0;
    int ca4;
    int ca8;
    int cac;
    int cb0;
    int cb4;
    int cb8;
    int cbc;
    int cc0;
    int cc4;
    int cc8;
    int ccc;
};

struct GGRigidBody
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    GGCollidable m_kCollidable;
    GGMotion m_pMotionState;

    const GGVector4& getCenterOfMassInWorld() const
    {
        return m_pMotionState.m_vCenterOfMass1;
    }
    const GGCollidable* getCollidable() const
    {
        return &m_kCollidable;
    }
    hkReal GetMassValue() const
    {
        return reinterpret_cast<::MotionMassView *>((void *)&(m_pMotionState))->FUN_00c86430();
    }
};

struct GGEntityArray
{
    GGRigidBody** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct GGSimulationIsland
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
    GGEntityArray m_kActorEntries;
};

struct GGIslandArray
{
    GGSimulationIsland** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct GGWorldRayCastInput
{
    GGVector4 m_vFrom;
    GGVector4 m_vTo;
    hkBool m_bEnableShapeCollectionFilter;
    hkUint32 m_uiFilterInfo;
    GGWorldRayCastInput() : m_bEnableShapeCollectionFilter(false), m_uiFilterInfo(0)
    {}
};

struct GGRayHitCollector
{
    virtual void CollectRayHit(const void* cdBody, const void* hitInfo) = 0;
    hkReal m_fEarlyOutHitFraction;

    GGRayHitCollector()
    {
        reset();
    }
    void reset()
    {
        m_fEarlyOutHitFraction = 1.0f;
    }
};

struct GGShapeRayCastCollectorOutput
{
    GGVector4 m_vHitNormal;
    hkReal m_fHitFraction;
    hkInt32 m_iExtraInfo;
    int unk18;
    int unk1c;

    GGShapeRayCastCollectorOutput()
    {
        reset();
    }
    void reset()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
    }
};

struct GGShapeRayCastOutput : GGShapeRayCastCollectorOutput
{
    hkUint32 m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4c;

    GGShapeRayCastOutput()
    {
        reset();
    }
    void reset()
    {
        GGShapeRayCastCollectorOutput::reset();
        m_uiShapeKeys[0] = 0xffffffff;
        m_uiShapeKeyIndex = 0;
    }
};

struct GGWorldRayCastOutput : GGShapeRayCastOutput
{
    const GGCollidable* m_pRootCollidable;

    GGWorldRayCastOutput()
    {
        reset();
    }
    void reset()
    {
        m_pRootCollidable = 0;
        GGShapeRayCastOutput::reset();
    }
};

struct GGClosestRayHitCollector : GGRayHitCollector
{
    GGWorldRayCastOutput m_kClosestHit;

    GGClosestRayHitCollector()
    {
        reset();
    }
    void reset()
    {
        m_kClosestHit.reset();
        GGRayHitCollector::reset();
    }
    virtual void CollectRayHit(const void* cdBody, const void* hitInfo);
};

struct GGWorld
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
    GGIslandArray m_kActiveSimulationIslands;
    GGIslandArray m_kInactiveSimulationIslands;

};

struct GGTransform
{
    GGVector4 m_kColumn0, m_kColumn1, m_kColumn2;
    GGVector4 m_vTranslation;
};

struct GravityGun : hkpGravityGun
{
    bool isGrabbed(const GGRigidBody* body) const
    {
        for (int i = 0; i < m_kPickedBodies.m_iElementCount; i++)
        {
            if (m_kPickedBodies.m_data[i] == body)
            {
                return true;
            }
        }
        return false;
    }

    GGRigidBody* FUN_00e45a60(const GGTransform& viewTransform, const GGRigidBody* characterBody, const GGWorld* world);
};

// Finds the best rigid body to grab by scoring candidates in active and inactive islands, then ray-casting to verify line of sight.
// @fnv 0x00e45a60
GGRigidBody* GravityGun::FUN_00e45a60(const GGTransform& viewTransform, const GGRigidBody* characterBody,
                                      const GGWorld* world)
{
    GGRigidBody* pickedBody = 0;
    hkReal bestValue = 0.35f;

    const GGIslandArray* islands = &world->m_kActiveSimulationIslands;
    for (int iIslandSet = 0; iIslandSet < 2; iIslandSet++)
    {
        for (int i = 0; i < islands->m_iElementCount; i++)
        {
            GGSimulationIsland* island = islands->m_data[i];
            for (int e = 0; e < island->m_kActorEntries.m_iElementCount; e++)
            {
                GGRigidBody* body = island->m_kActorEntries.m_data[e];
                const GGVector4& vCenterOfMass = body->getCenterOfMassInWorld();

                GGVector4 posInView;
                reinterpret_cast<::FUN_00c7f690_cls *>(&(posInView))->FUN_00c7f690((const ::S_00c7f690_M *)&(viewTransform), (const ::S_00c7f690_V *)&(vCenterOfMass));

                hkReal x = posInView(0);
                if (x < 0.1f || x > m_fMaxPickDistance || body == characterBody)
                {
                    continue;
                }

                hkReal value = MathUtilities::fabs(posInView(2)) + MathUtilities::fabs(posInView(1));
                value = value / (x + 1.0);

                if (body->GetMassValue() > m_fMaxPickMass)
                {
                    value += 0.1f;
                }

                if (value > bestValue)
                {
                    continue;
                }

                if (isGrabbed(body))
                {
                    continue;
                }

                {
                    GGClosestRayHitCollector collector;
                    GGWorldRayCastInput input;
                    input.m_vFrom = viewTransform.m_vTranslation;
                    input.m_vTo = vCenterOfMass;

                    reinterpret_cast<::fnv_00c91f70::RayWorld *>((void *)(world))->FUN_00c91f70((const void *)&(input), (void *)&(collector));

                    if (collector.m_kClosestHit.m_pRootCollidable == 0 ||
                        collector.m_kClosestHit.m_pRootCollidable == body->getCollidable())
                    {
                        bestValue = value;
                        pickedBody = body;
                    }
                }
            }
        }
        islands = &world->m_kInactiveSimulationIslands;
    }
    return pickedBody;
}

struct DDCC60World;

struct __declspec(align(16)) MyVec
{
    float x, y, z, w;
};

struct GunArg3
{
    int unk000, unk004, unk008, unk00c;
    int unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c;
    int unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c;
    int unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c;
    int unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c;
    int unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac;
    int unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc;
    int unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec;
    int unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c;
    int unk110, unk114, unk118, unk11c;
    MyVec unk120;
};

struct GunTransform
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    MyVec m_vTranslation;
};

struct GunListener
{
    virtual void func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func4();
    virtual void gunAction(const MyVec& from, const MyVec* to = 0);
};

struct hkTransform;
struct hkpRigidBody;
struct hkpGravityGunEx : public hkpGravityGun
{
    void FUN_00e46080(GunTransform* a4, GunArg3* a3, DDCC60World* world);

    void FUN_00e46140(hkReal dt, DDCC60World* world, GunArg3* a3, GunTransform* a4, bool b1, bool b2);
public:
    void FUN_00e45c90(float, const ::hkTransform &, ::hkpRigidBody *);
public:
    __declspec(noinline) void FUN_00e45c90(float dTime, const hkTransform& transform, hkpRigidBody* otherRb);
};

// Dispatches a gun action to listeners based on b1/b2 and picked-body capacity, then calls FUN_00e45c90 with dt, a4, a3.
// @fnv 0x00e46140
void hkpGravityGunEx::FUN_00e46140(hkReal dt, DDCC60World* world, GunArg3* a3, GunTransform* apGunTransform, bool b1,
                                   bool b2)
{
    MyVec v1;
    MyVec v2;

    if (b1)
    {
        reinterpret_cast<::hkpGravityGunE45 *>(this)->FUN_00e45ee0((int)(apGunTransform), (int)(a3), (int)(world));
        *(__m128*)&v1 = *(__m128*)&a3->unk120;
        for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
        {
            ((GunListener*)m_kListeners.m_data[i])->gunAction(v1, 0);
        }
    }
    else if (b2)
    {
        if (m_kPickedBodies.m_iElementCount != m_iMaxPickedBodies)
        {
            FUN_00e46080(apGunTransform, a3, world);
            *(__m128*)&v2 = *(__m128*)&apGunTransform->m_vTranslation;
            *(__m128*)&v1 = *(__m128*)&a3->unk120;
            for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
            {
                ((GunListener*)m_kListeners.m_data[i])->gunAction(v2, &v1);
            }
        }
        else
        {
            reinterpret_cast<::FUN_00e45fb0_class *>(this)->FUN_00e45fb0((int)(apGunTransform), (int)(a3), (int)(world));
            *(__m128*)&v2 = *(__m128*)&a3->unk120;
            for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
            {
                ((GunListener*)m_kListeners.m_data[i])->gunAction(v2, 0);
            }
        }
    }

    reinterpret_cast<::hkpGravityGunEx *>(this)->FUN_00e45c90(dt, (*(const ::hkTransform *)(apGunTransform)), (::hkpRigidBody *)(a3));
}

class hkMemoryAllocatorE460;

struct hkMemoryRouterE460
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE460* m_pStreamAllocator;
};

namespace hkRouterE460 {
static inline hkMemoryRouterE460& getMemoryRouter() { return *static_cast<hkMemoryRouterE460*>(::FUN_00c85750()); }
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct hkBoolE460
{
    char m_cBooleanValue;
    hkBoolE460()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

template <class T> __forceinline void constructWithCopyE460(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArrayE460
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouterE460& router = hkRouterE460::getMemoryRouter();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        constructWithCopyE460<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct hkSimdRealE460
{
    __m128 m_vValue;
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct hkVector4E460
{
    __m128 m_vComponents;
    hkSimdRealE460 getW() const
    {
        hkSimdRealE460 r;
        r.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }
};

class hkEntityE460
{
  public:
    int unk00[104];
    hkVector4E460 m_vec1a0;

    void FUN_00c90510();
};

class hkWorldE460
{
  public:
    int unk00[8];
    hkArrayE460<hkEntityE460*> m_kActorEntries;

    void FUN_00e46000(hkEntityE460* e);
};

// Calls e->FUN_00c90510, appends e to m_kActorEntries, then calls e->FUN_00ca88e0 with the w component of m_vec1a0 times 100.
// @fnv 0x00e46000
void hkWorldE460::FUN_00e46000(hkEntityE460* apEntity)
{
    reinterpret_cast<::FUN_00c90510_class *>((apEntity))->FUN_00c90510();
    m_kActorEntries.AddBack(apEntity);
    float w = apEntity->m_vec1a0.getW();
    float f = (float)(w * 100.0);
    reinterpret_cast<::FUN_00ca88e0_cls *>((apEntity))->FUN_00ca88e0(f);
}


class hkStringPtrE462
{
  public:
    char* m_pcText;
    void operator=(const char* pcString)
    {
        reinterpret_cast<::SStringPtr *>(this)->FUN_00cb0c10(pcString);
    }
};

template <class T> class hkArrayE462
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE462() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct __declspec(align(16)) hkVector4E462
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

class hkpFirstPersonGunListenerE462;
class hkpRigidBodyE462;

class FUN_00e46660
{
  public:
    virtual ~FUN_00e46660() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    hkStringPtrE462 m_name;
    unsigned char m_uiKeyboardKey;
    hkArrayE462<hkpFirstPersonGunListenerE462*> m_kListeners;

    FUN_00e46660() throw();
};

class FUN_00e46260 : public FUN_00e46660
{
  public:
    hkArrayE462<hkpRigidBodyE462*> m_kPickedBodies;
    int m_iMaxPickedBodies;
    float m_fMaxPickMass;
    float m_fMaxPickDistance;
    float m_fPickAngle;
    float m_fHoldDistance;
    hkVector4E462 m_kGrabPosition;
    hkVector4E462 m_kTargetPosition;

    FUN_00e46260() throw();
    virtual ~FUN_00e46260() throw();
};

// Constructs a GravityGun object, initializing pick limits, grab and target positions, and setting the type and name fields.
// @fnv 0x00e46260
FUN_00e46260::FUN_00e46260() throw()
    : m_iMaxPickedBodies(10), m_fMaxPickMass(200.0f), m_fMaxPickDistance(50.0f), m_fPickAngle(100.0f),
      m_fHoldDistance(50.0f)
{
    m_type = 3;
    m_name = "GravityGun";
    m_kGrabPosition.set(2.5f, 0.6f, 0.0f);
    m_kTargetPosition.set(0.0f, 1.0f, 0.0f);
}

// Moved from hkpgravitygun_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
#include "fnv/symbols_01016000.h"

struct Body_e45e
{
    int unk[0x1a0 / 4];
    __m128 m_kInertiaAndMassInv;
    float getMassInv() const
    {
        float w;
        _mm_store_ss(&w, _mm_shuffle_ps(m_kInertiaAndMassInv, m_kInertiaAndMassInv, 0xff));
        return w;
    }
};

struct World_e45e
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    Body_e45e** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    Body_e45e* FUN_00e45e60(int index);
};
// @fnv 0x00e45e60
Body_e45e* World_e45e::FUN_00e45e60(int index)
{
    Body_e45e** volatile* pdata = (Body_e45e * * volatile*)&m_data;
    Body_e45e* body = (*pdata)[index];
    m_iElementCount--;
    int n = (m_iElementCount - index) * 4;
    Body_e45e** data = *pdata;
    char* dst = (char*)&data[index];
    const char* src = (const char*)&data[index + 1];
    for (int i = 0; i < n; i += 4)
        *(unsigned int*)(dst + i) = *(const unsigned int*)(src + i);
    reinterpret_cast<::FUN_00ca88e0_cls *>((body))->FUN_00ca88e0((float)(body->getMassInv() * DAT_01016408));
    reinterpret_cast<::hkReferencedObjectC905 *>((body))->FUN_00c905b0();
    return body;
}

// Moved from hkpgravitygun_rtm_variant.cpp (VEGAS-15).
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_01012000.h"

extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_mm_load_ss, _mm_load_ps, _mm_shuffle_ps, _mm_mul_ps, _mm_store_ss, _mm_store_ps)

struct UnkCall
{
};

struct TargetBody
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C(hkVector4*);
};

struct Target : public UnkCall
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

    TargetBody body;

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

    hkVector4 unk1A0;
};

struct GravityGunQ
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
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    hkVector4 unk44;
    hkVector4 unk54;

};

struct ImpulseVector : hkVector4
{
    __forceinline void mul(float factor)
    {
        hkVector4& out = *this;
        __m128 scalar = _mm_load_ss(&factor);
        __m128 vector = _mm_load_ps((const float*)&out);
        __m128 broadcast = _mm_shuffle_ps(scalar, scalar, 0);
        _mm_store_ps((float*)&out, _mm_mul_ps(broadcast, vector));
    }
};

// @fnv 0x00e46080
void hkpGravityGunEx::FUN_00e46080(GunTransform* a4, GunArg3* a3, DDCC60World* world)
{
    hkVector4* direction = (hkVector4*)a4;
    int argC = (int)a3;
    int arg10 = (int)world;
    GravityGunQ* gq = (GravityGunQ*)this;
    Target* target = ((::Target *)(reinterpret_cast<::GravityGun *>((gq))->FUN_00e45a60((*(const ::GGTransform *)(direction)), (const ::GGRigidBody *)(argC), (const ::GGWorld *)(arg10))));

    if (target != 0)
    {
        __m128 massVector = _mm_load_ps((const float*)&target->unk1A0);
        massVector = _mm_shuffle_ps(massVector, massVector, 0xff);

        float mass;
        _mm_store_ss(&mass, massVector);

        if (!(gq->unk30 * mass < ::g_01012070))
        {
            if (gq->unk24 < gq->unk2C)
            {
                reinterpret_cast<::hkWorldE460 *>((gq))->FUN_00e46000((::hkEntityE460 *)(target));
                return;
            }
        }

        ImpulseVector impulse;
        _mm_store_ps((float*)&impulse, _mm_load_ps((const float*)direction));
        impulse.mul(-gq->unk38);
        reinterpret_cast<::hkpEntityC9C *>((target))->FUN_00c9c1d0();
        target->body.vf4C(&impulse);
    }
}

// Moved from hkpgravitygun_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).
// src/havok/physics/utilities/weapons/hkpgravitygun_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/weapons/hkpgravitygun_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/utilities/weapons/hkpgravitygun_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/weapons/hkpgravitygun.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/weapons/hkpgravitygun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpgravitygun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/GravityGun.h"
#include "fnv/symbols_01011000.h"

struct ObjE45
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
    unsigned short unk28;
    unsigned char unk2a;
};

struct MotionE45
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void SetCollisionShape(const hkVector4& impulse);
};

struct BodyE45
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
    MotionE45 m_pMotionState;
};

struct ViewE45
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
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    __m128 m_kTranslationalVelocity;
};

extern "C" void _ReadWriteBarrier(void);

static inline __m128 bcastE45(const float& f)
{
    __m128 s = _mm_load_ss(&f);
    return _mm_shuffle_ps(s, s, 0);
}

struct hkpGravityGunE45 : public hkpGravityGun
{
    void FUN_00e45ee0(int dirSlot, int viewSlot, int p3Slot);
};

// @fnv 0x00e45ee0
void hkpGravityGunE45::FUN_00e45ee0(int dirSlot, int viewSlot, int p3Slot)
{
    union
    {
        __m128 q;
        float f[4];
    } v;
    if (m_kPickedBodies.m_iElementCount != 0)
    {
        ObjE45* body = ((::ObjE45 *)(reinterpret_cast<::World_e45e *>(this)->FUN_00e45e60(0)));
        v.q = _mm_mul_ps(bcastE45(m_fHoldDistance), *(const __m128*)dirSlot);
        v.f[1] = (float)(v.f[1] + DAT_01011588);
        v.q = _mm_add_ps(((const ViewE45*)viewSlot)->m_kTranslationalVelocity, v.q);
        reinterpret_cast<::FUN_005616d0_Owner *>((body))->OnTrigger((::TriggerContext *)((int)&v));
        body->unk2a = 6;
    }
    else
    {
        BodyE45* body = ((::BodyE45 *)(reinterpret_cast<::GravityGun *>(this)->FUN_00e45a60((*(const ::GGTransform *)(dirSlot)), (const ::GGRigidBody *)(viewSlot), (const ::GGWorld *)(p3Slot))));
        if (body)
        {
            __m128 dir = *(const __m128*)dirSlot;
            v.q = dir;
            v.q = _mm_mul_ps(bcastE45(m_fPickAngle), v.q);
            reinterpret_cast<::hkpEntityC9C *>((body))->FUN_00c9c1d0();
            body->m_pMotionState.SetCollisionShape(*(const hkVector4*)&v);
        }
    }
}
#include "fnv/symbols_simd.h"
struct hkSimdRealEx
{
    __m128 m_vValue;
    __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    hkSimdRealEx(const __m128& v) : m_vValue(v)
    {}
    operator float() const
    {
        float value;
        _mm_store_ss(&value, m_vValue);
        return value;
    }
    hkSimdRealEx(float f)
    {
        m_vValue = _mm_load_ss(&f);
    }
};
struct hkVector4Ex : public hkVector4
{
    hkVector4Ex()
    {}
    hkVector4Ex(const hkVector4Ex& a)
    {
        *(__m128*)this = *(__m128*)&a;
    }
    hkVector4Ex& operator=(const hkVector4Ex& a)
    {
        *(__m128*)this = *(__m128*)&a;
        return *this;
    }
    __declspec(noinline) void FUN_00c7f640(const hkTransform& t, const hkVector4& in)
    {
        __m128 v = *(__m128*)&in;
        __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), *(__m128*)&t.m_rotation.m_kColumn1);
        __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), *(__m128*)&t.m_rotation.m_kColumn0);
        __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), *(__m128*)&t.m_rotation.m_kColumn2);
        *(__m128*)this = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, *(__m128*)&t.m_vTranslation));
    }
    void setAddMul4(const hkVector4& a, const hkVector4& b, const hkSimdRealEx& s)
    {
        __m128 sv = s.broadcast();
        *(__m128*)this = _mm_add_ps(*(__m128*)&a, _mm_mul_ps(sv, *(__m128*)&b));
    }
    void setInterpolate4(const hkVector4& a, const hkVector4& b, const hkSimdRealEx& t)
    {
        __m128 tv = t.broadcast();
        __m128 one_minus_t = _mm_sub_ps(::DAT_010ec7f0, tv);
        *(__m128*)this = _mm_add_ps(_mm_mul_ps(one_minus_t, *(__m128*)&a), _mm_mul_ps(tv, *(__m128*)&b));
    }
    bool equals4(const hkVector4& a, float eps = 0.001f) const
    {
        __m128 diff = _mm_sub_ps(*(__m128*)this, *(__m128*)&a);
        __m128 absDiff = _mm_and_ps(diff, DAT_01017d10);
        __m128 eps_v = _mm_set1_ps(eps);
        return (_mm_movemask_ps(_mm_cmple_ps(absDiff, eps_v)) & 0xf) == 0xf;
    }
    hkSimdRealEx lengthSquared3() const
    {
        __m128 v = *(__m128*)this;
        __m128 mul = _mm_mul_ps(v, v);
        __m128 shuf1 = _mm_shuffle_ps(mul, mul, 0x55);
        __m128 add1 = _mm_add_ss(shuf1, mul);
        __m128 shuf2 = _mm_shuffle_ps(mul, mul, 0xaa);
        __m128 add2 = _mm_add_ss(shuf2, add1);
        return hkSimdRealEx(add2);
    }
};
struct hkpMotion
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0c();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1c();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2c();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3c();
    virtual void SetTranslationalVelocity(const hkVector4&);
    virtual void SetRotationalVelocity(const hkVector4&);
    int unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    hkVector4Ex m_vContactPosition;  // 0x60
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    hkVector4Ex m_kTranslationalVelocity;  // 0xd0
    hkVector4Ex m_kAngularVelocity;        // 0xe0
};
struct hkpRigidBody
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, selfUnk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc;
    hkpMotion m_pMotionState;  // 0xe0
};
// @fnv 0x00e45c90
__declspec(noinline) void hkpGravityGunEx::FUN_00e45c90(float dTime, const hkTransform& transform,
                                                        hkpRigidBody* otherRb)
{
    for (int i = 0; i < m_kPickedBodies.m_iElementCount; ++i)
    {
        const double gain = 0.4f;
        float invDTime = (float)(gain / dTime);
        hkVector4Ex localPos;
        localPos.setAddMul4(m_kGrabPosition, m_kTargetPosition, (float)i);
        hkVector4Ex targetPos;
        targetPos.FUN_00c7f640(transform, localPos);
        hkpRigidBody* rb = (hkpRigidBody*)m_kPickedBodies.m_data[i];
        hkVector4Ex newLinearVelocity = rb->m_pMotionState.m_kTranslationalVelocity;
        newLinearVelocity.setInterpolate4(rb->m_pMotionState.m_kTranslationalVelocity,
                                          otherRb->m_pMotionState.m_kTranslationalVelocity, 0.8f);
        __m128 deltaPos = _mm_sub_ps(*(__m128*)&targetPos, *(__m128*)&rb->m_pMotionState.m_vContactPosition);
        __m128 invDTimeVec = hkSimdRealEx(invDTime).broadcast();
        *(__m128*)&newLinearVelocity = _mm_add_ps(_mm_mul_ps(deltaPos, invDTimeVec), *(__m128*)&newLinearVelocity);
        if (!newLinearVelocity.equals4(rb->m_pMotionState.m_kTranslationalVelocity))
        {
            reinterpret_cast<::hkpEntityC9C *>((rb))->FUN_00c9c1d0();
            rb->m_pMotionState.SetTranslationalVelocity(newLinearVelocity);
        }
        const float minSq = 1.0f;
        hkVector4Ex newAngularVelocity;
        *(__m128*)&newAngularVelocity =
            _mm_mul_ps(hkSimdRealEx(0.8f).broadcast(), *(__m128*)&rb->m_pMotionState.m_kAngularVelocity);
        if (float(newAngularVelocity.lengthSquared3()) > minSq)
        {
            if (!newAngularVelocity.equals4(rb->m_pMotionState.m_kAngularVelocity))
            {
                reinterpret_cast<::hkpEntityC9C *>((rb))->FUN_00c9c1d0();
                rb->m_pMotionState.SetRotationalVelocity(newAngularVelocity);
            }
        }
    }
}
