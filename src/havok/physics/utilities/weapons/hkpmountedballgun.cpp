
// src/havok/physics/utilities/weapons/hkpmountedballgun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpmountedballgun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <new>
#include "fnv/decl/FUN_00e46f90.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_010ec000.h"
#include "havok/hkpMountedBallGun.h"

#include <xmmintrin.h>

struct FUN_00e46f90_Obj
{
};
struct HKStr
{
    void* m_p;
    void operator=(const char* s);
};
union HKVec
{
    __m128 v;
    struct
    {
        float x, y, z, w;
    };
};

struct MBG
{
    void* vfptr;
    unsigned short unk04;
    short unk06;
    unsigned char m_type;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    HKStr m_name;
    unsigned char m_uiKeyboardKey;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    void** m_listenerData;
    int m_listenerCount;
    int m_listenerCap;
    float m_fBulletRadius;
    float m_fBulletVelocity;
    float m_fBulletMass;
    float m_fBulletSpread;
    int m_iBulletBatchCount;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    HKVec m_kBulletDirection;
    void* m_pBulletQueue;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    HKVec m_vContactPosition;
};

struct FUN_00e45150_class
{
    MBG* Initialize(int a);
};

// Calls FUN_00e46f90 with a, sets the vtable, type 4 and the name "MountedBallGun", and stores a vector from DAT_01011d78 and DAT_01016410 in the final member.
// @fnv 0x00e45150
MBG* FUN_00e45150_class::Initialize(int a)
{
    MBG* self = (MBG*)this;
    new ((void *)(((FUN_00e46f90_Obj*)this))) ::FUN_00e46f90(a);
    self->vfptr = (void*)&(*reinterpret_cast<unsigned int *>(&::DAT_010ec004));
    self->m_type = 4;
    reinterpret_cast<::SStringPtr *>((void *)&(const ::HKStr &)(self->m_name))->FUN_00cb0c10("MountedBallGun");
    __m128 v = _mm_setr_ps(::DAT_01011d78, DAT_01016410, ::DAT_01011d78, ::DAT_01011d78);
    self->m_vContactPosition.v = v;
    return self;
}




inline hkMemoryRouter& getRouter()
{
    return hkMemoryRouter::getInstance();
}

template <typename T> inline T* hkAllocateChunkQ(int n)
{
    return (T*)getRouter().heap().blockAlloc(n * sizeof(T));
}

template <typename T> inline void hkDeallocateChunkQ(T* p, int n)
{
    getRouter().heap().blockFree(p, n * sizeof(T));
}

struct hkpRigidBody;

template <typename T> struct hkQueueQ
{
    T* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    int getCapacity() const
    {
        return m_pRayCursor;
    }
    void releaseMemory()
    {
        if (m_pRayCursor)
            hkDeallocateChunkQ<T>(m_data, m_pRayCursor);
    }
    void FUN_00e45460(int n);
};

// Grows the queue buffer to at least n elements, copying existing nodes and updating the head and tail indices.
// @fnv 0x00e45460
template <typename T> void hkQueueQ<T>::FUN_00e45460(int aiMinCapacity)
{
    if (getCapacity() < aiMinCapacity)
    {
        if (getCapacity() * 2 >= aiMinCapacity)
            aiMinCapacity = getCapacity() * 2;

        T* p = hkAllocateChunkQ<T>(aiMinCapacity);
        if (m_data != 0)
        {
            if (m_iNodeCount)
            {
                if (m_pTail <= m_pFirstNode)
                {
                    int numHead = m_pRayCursor - m_pFirstNode;
                    int numTail = m_pTail;
                    ::FUN_00cb1260(p, m_data + m_pFirstNode, numHead * sizeof(T));
                    ::FUN_00cb1260(p + numHead, m_data, numTail * sizeof(T));
                }
                else
                {
                    ::FUN_00cb1260(p, m_data + m_pFirstNode, m_iNodeCount * sizeof(T));
                }
            }
            m_pFirstNode = 0;
            m_pTail = m_iNodeCount;
        }
        releaseMemory();
        m_data = p;
        m_pRayCursor = aiMinCapacity;
    }
}

template struct hkQueueQ<hkpRigidBody*>;

// Moved from hkpmountedballgun_rtm_variant.cpp (VEGAS-15).
#include "fnv/decl/FUN_00c91620_Class.h"
#include "fnv/decl/FUN_00cd8160.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/S00ca8c90_Body.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpWorldC914.h"
#include "fnv/symbols_00cf0000.h"
#include "fnv/symbols_00e46000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01023000.h"

struct S00e451b0_ZScalar
{
    __m128 q;
    S00e451b0_ZScalar(float f) : q(_mm_load_ss(&f))
    {}
};
struct S00e451b0_ZInfo;
struct S00e451b0_ZSphere
{
    int unk00;
    unsigned short unk04;
    short unk06;
};
struct __declspec(align(16)) S00e451b0_ZInfo
{
    int unk00;
    S00e451b0_ZSphere* unk04;
    int unk08, unk0c;
    __m128 unk10, unk20, unk30, unk40, unk50, unk60, unk70, unk80;
    float unk90, unk94, unk98, unk9c, unkA0, unkA4, unkA8, unkAc, unkB0;
    unsigned char unkB4, unkB5, unkB6, unkB7;
    int unkB8, unkBc;
};
struct S00e451b0_ZBody
{
    int unk00;
    unsigned short unk04;
    short unk06;
    struct S00e451b0_ZWorld* unk08;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    __m128 unk40, unk50, unk60, unk70, unk80;
    int unk90, unk94, unk98;
    float unk9c;
};
struct S00e451b0_ZListener
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC(S00e451b0_ZBody*);
    virtual void v10(S00e451b0_ZBody*);
    virtual void v14(const hkVector4*, const __m128*);
};
struct S00e451b0_ZWorld
{
    int unk00, unk04, unk08, unk0c;
    hkVector4 unk10;
};
namespace ZMem {
}
struct __declspec(align(16)) S00e451b0_ZCastResult
{
    __m128 point, normal;
    unsigned int shapeKey;
    S00e451b0_ZBody* body;
};
int __cdecl FUN_00e464e0(S00e451b0_ZWorld*, const __m128*, float, const __m128*,
                         S00e451b0_ZCastResult*);
struct S00e451b0_ZQueue
{
    S00e451b0_ZBody** unk00;
    int unk04, unk08, unk0c, unk10;
    void FUN_00e45460(int);
    void push(S00e451b0_ZBody* body)
    {
        if (unk10 >= unk04)
        {
            if (unk04 == 0)
                FUN_00e45460(8);
            else
                FUN_00e45460(unk04 * 2);
        }
        if (unk0c == unk04)
            unk0c = 0;
        unk00[unk0c] = body;
        ++unk0c;
        ++unk10;
    }
    S00e451b0_ZBody* pop()
    {
        S00e451b0_ZBody* body = unk00[unk08++];
        if (unk08 == unk04)
            unk08 = 0;
        --unk10;
        return body;
    }
};
struct S00e451b0_ZGun : hkpMountedBallGun
{
    void FUN_00e451b0(S00e451b0_ZWorld*, const hkTransform*);
};
// @fnv 0x00e451b0
void S00e451b0_ZGun::FUN_00e451b0(S00e451b0_ZWorld* world, const hkTransform* transform)
{
    __m128 direction = *(const __m128*)&transform->m_rotation.m_kColumn0;
    __m128 start =
        _mm_add_ps(_mm_load_ps(&transform->m_vTranslation.x), direction);
    S00e451b0_ZScalar distance(200.0f);
    __m128 end = _mm_add_ps(
        _mm_mul_ps(_mm_shuffle_ps(distance.q, distance.q, 0), direction), start);
    S00e451b0_ZInfo info;
    reinterpret_cast<::Owner *>(&(info))->FUN_00cf5ea0();
    S00e451b0_ZSphere* sphere = (S00e451b0_ZSphere*)hkMemoryRouter::getInstance().heap().blockAlloc(0x20);
    sphere->unk04 = 0x20;
    sphere = ((::S00e451b0_ZSphere *)(new ((void *)(sphere)) ::FUN_00cd8160(m_fBulletRadius)));
    info.unk90 = m_fBulletMass;
    __m128 position = *(__m128*)&m_vContactPosition;
    info.unkB0 = 0.01f;
    info.unkA4 = 0.2f;
    const hkVector4* posPtr = &m_vContactPosition;
    info.unkA0 = 1.0f;
    info.unk04 = sphere;
    info.unkB7 = 6;
    info.unk10 = position;
    info.unkB4 = 2;
    ::FUN_00cf07a0(sphere, m_fBulletMass * 2.0f, (::Dest *)(::S00e451b0_ZInfo *)(&info));
    info.unk90 = m_fBulletMass;
    info.unk94 = 0.0f;
    info.unk98 = DAT_010231a8;
    S00e451b0_ZCastResult target;
    if (!FUN_00e464e0(world, &start, DAT_010181bc, &end, &target))
    {
        ::FUN_00e463d0((*(const ::hkVector4 *)(&info.unk10)), (*(const ::hkVector4 *)(&target.point)), (*(const ::hkVector4 *)(&world->unk10)), m_fBulletVelocity, (*(::hkVector4 *)(&info.unk30)));
    }
    else
    {
        __m128 speed = _mm_load_ss(&m_fBulletVelocity);
        info.unk30 = _mm_mul_ps(_mm_shuffle_ps(speed, speed, 0), direction);
    }
    __m128 hit = target.point;
    for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
        ((S00e451b0_ZListener**)m_kListeners.m_data)[i]->v14(posPtr, &hit);
    S00e451b0_ZBody* body = (S00e451b0_ZBody*)hkMemoryRouter::getInstance().heap().blockAlloc(0x220);
    body->unk04 = 0x220;
    body = ((::S00e451b0_ZBody *)(reinterpret_cast<::S00ca8c90_Body *>((body))->FUN_00ca8c90((*(const ::CInfo181 *)(&info)))));
    reinterpret_cast<::hkReferencedObjectC905 *>((info.unk04))->FUN_00c905b0();
    body->unk9c = m_fBulletSpread;
    for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
        ((S00e451b0_ZListener**)m_kListeners.m_data)[i]->vC(body);
    reinterpret_cast<::hkpWorldC914 *>((world))->FUN_00c914d0((::hkpEntityC914 *)(body), 1);
    ((S00e451b0_ZQueue*)m_pBulletQueue)->push(body);
    if (((S00e451b0_ZQueue*)m_pBulletQueue)->unk10 > m_iBulletBatchCount)
    {
        body = ((S00e451b0_ZQueue*)m_pBulletQueue)->pop();
        for (int i = m_kListeners.m_iElementCount - 1; i >= 0; --i)
            ((S00e451b0_ZListener**)m_kListeners.m_data)[i]->v10(body);
        if (body->unk08)
        {
            bool removed;
            reinterpret_cast<::FUN_00c91620_Class *>((body->unk08))->ProcessTarget((unsigned char *)(bool *)(&removed), (::FUN_00c91620_Target *)(body));
        }
        reinterpret_cast<::hkReferencedObjectC905 *>((body))->FUN_00c905b0();
    }
}
