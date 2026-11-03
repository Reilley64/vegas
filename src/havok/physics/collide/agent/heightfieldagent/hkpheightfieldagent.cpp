
// src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "havok/hkMemoryRouter.h"
#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
#include <intrin.h>
#include <windows.h>
#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/decl/hkTransformCB22.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d31000.h"
#include "fnv/symbols_00d32000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_01076000.h"
#include "fnv/symbols_010ce000.h"
#include "fnv/symbols_01268000.h"




struct SizeSource {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
    virtual int GetCount();
};

struct SourceRef {
    SizeSource* m_p;
};

struct hkArrayU16 {
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void init() { m_data = 0; m_iElementCount = 0; m_iCapacityState = 0x80000000; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator* alloc = &hkMemoryRouter::getInstance().heap();
        int c = m_iCapacityState & 0x3fffffff;
        if (c < n) {
            c = c * 2;
            ::FUN_00c908c0((::SpawnedObject *)&(*alloc), (::SpawnedArray *)(void *)(this), n < c ? c : n, 2);
        }
    }
    __forceinline void SetSizeAndGrow(int n, const unsigned short& fill)
    {
        reserve(n);
        int num = n - m_iElementCount;
        unsigned short* p = m_data + m_iElementCount;
        for (int i = 0; i < num; ++i) {
            p[i] = fill;
        }
        m_iElementCount = n;
    }
};

struct FUN_00d32060_Class {
    void* m_vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_flag;
    hkArrayU16 m_aiIndexedValues;

    FUN_00d32060_Class* Init(const SourceRef& src, const void* b, const void* c, void* flag);
};

// Sets the vtable, flag and count fields, initialises the array, and if flag is set fills it with 0xffff up to src.m_p->GetCount().
// @fnv 0x00d32060
FUN_00d32060_Class* FUN_00d32060_Class::Init(const SourceRef& aSource, const void* aiUnused1, const void* aiUnused2, void* aiFlags)
{
    m_sReferenceCount = 1;
    m_flag = aiFlags;
    m_vtbl = DAT_010ceaa8;
    m_aiIndexedValues.init();
    if (aiFlags) {
        int n = aSource.m_p->GetCount();
        m_aiIndexedValues.SetSizeAndGrow(n, 0xffff);
    }
    return this;
}

namespace fnv_00d32110 {



struct TargetObj {
    int unk00;
    unsigned short size;
};

// Allocates a FUN_00d32060_Class-sized TargetObj from the heap allocator, records its size, and returns the result of FUN_00d32060(a1, a2, a3, a4).
// @fnv 0x00d32110
TargetObj* AllocateTargetObj(void* apArg1, void* apArg2, void* apArg3, void* apArg4) {
    TargetObj* obj = (TargetObj*)hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(::FUN_00d32060_Class));
    obj->size = sizeof(::FUN_00d32060_Class);
    return ((::fnv_00d32110::TargetObj *)(reinterpret_cast<::FUN_00d32060_Class *>((obj))->Init((*static_cast<const ::SourceRef *>(apArg1)), apArg2, apArg3, apArg4)));
}
}  // namespace fnv_00d32110

struct D323B0CollectorBase;
void __cdecl FUN_00d317d0(const void* a1, const void* a2, const void* a3, void* a4);
void __cdecl FUN_00d319e0(const void* a, const void* b, const void* c, D323B0CollectorBase* collector);
extern "C" void __cdecl FUN_00d31d30(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
// @fnv 0x00d32170
void FUN_00d32170(void* apArg1, void* apArg2, void* apArg3, void* apArg4) {
    FUN_00d319e0(apArg1, apArg2, apArg3, static_cast<D323B0CollectorBase*>(apArg4));
}

typedef void (*S_00d321e0_Func)();


struct S_00d321e0_AgentFuncs {
    S_00d321e0_Func m_pCreateFunc;
    S_00d321e0_Func m_pQueryPenetrationsFunc;
    S_00d321e0_Func m_pGetPenetrationsFunc;
    S_00d321e0_Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct S_00d321e0_Dispatcher {
};

// @fnv 0x00d321e0
void FUN_00d321e0(S_00d321e0_Dispatcher* dispatcher)
{
    {
        S_00d321e0_AgentFuncs af;
        af.m_pCreateFunc = ((void (&)())::fnv_00d32190::FUN_00d32190);
        af.m_pQueryPenetrationsFunc = ((void (&)())::FUN_00d32370);
        af.m_pGetPenetrationsFunc = ((void (&)())::FUN_00d323b0);
        af.m_pLinearCastFunc = ((void (&)())::fnv_00d323f0::FUN_00d323f0);
        af.m_bIsFlipped = true;
        af.m_bIsPredictive = true;
        reinterpret_cast<::FUN_00cfbbe0_cls *>((dispatcher))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(af), 0x19, 0x1a);
    }
    {
        S_00d321e0_AgentFuncs af;
        af.m_pCreateFunc = ((void (&)())::fnv_00d32110::AllocateTargetObj);
        af.m_pQueryPenetrationsFunc = ((void (&)())::FUN_00d317d0);
        af.m_pGetPenetrationsFunc = ((void (&)())::FUN_00d319e0);
        af.m_pLinearCastFunc = ((void (&)())::FUN_00d31d30);
        af.m_bIsFlipped = false;
        af.m_bIsPredictive = true;
        reinterpret_cast<::FUN_00cfbbe0_cls *>((dispatcher))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(af), 0x1a, 0x19);
    }
}


struct D323B0CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    float m_fEarlyOutDistance;

    D323B0CollectorBase() : m_fEarlyOutDistance(::DAT_0104da48) {}
};

struct D323B0Collector : D323B0CollectorBase {
    void* m_iData;

    D323B0Collector(void* iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};


// Constructs a D323B0Collector from d and passes it with b, a, c to FUN_00d319e0.
// @fnv 0x00d323b0
void __cdecl FUN_00d323b0(const void* aiArg1, const void* aiArg2, const void* aiArg3, void* aiData)
{
    D323B0Collector collector(aiData);
    FUN_00d319e0(aiArg2, aiArg1, aiArg3, &collector);
}

struct Handler {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void invoke(unsigned short item, int value);
};
struct Owner {
    virtual void clear(unsigned int mode);
    int unk04;
    Handler* callback;
    unsigned short* indices;
    int count;
    void NotifyAndClear(int value);
};
// Invokes callback->invoke for each non-0xffff entry in indices, then calls clear(1).
// @fnv 0x00d31770
void Owner::NotifyAndClear(int value) {
    if (callback) {
        for(int index=0; index<count; ++index) {
            unsigned short item=indices[index];
            if(item!=0xffff)
                callback->invoke(item,value);
        }
    }
    clear(1);
}

// Forwards all five arguments unchanged to FUN_00d31d30.
// @fnv 0x00d32030
extern "C" void FUN_00d32030(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4)
{
    FUN_00d31d30(arg0, arg1, arg2, arg3, arg4);
}

// @fnv 0x00d32150
extern "C" void FUN_00d32150(void* arg0, void* arg1, void* arg2, void* arg3)
{
    FUN_00d317d0(arg0, arg1, arg2, arg3);
}


struct FUN_00d32370_cls {
    void* vt;
    unsigned char flag;
    void* d;
};

// Builds a FUN_00d32370_cls with vt set to DAT_010ce81c and d set to a4, then calls FUN_00d317d0 with a2, a1, a3 and the struct.
// @fnv 0x00d32370
void __cdecl FUN_00d32370(const void* aiArg1, const void* aiArg2, const void* aiArg3, void* a4) {
    FUN_00d32370_cls local;
    local.flag = 0;
    local.d = a4;
    local.vt = &DAT_010ce81c;
    FUN_00d317d0(aiArg2, aiArg1, aiArg3, &local);
}

#include <xmmintrin.h>
namespace fnv_00d323f0 {
struct FourFloatVector { float x, y, z, w; };
struct __declspec(align(16)) CopyPacket {
    void* unk00;
    unsigned int unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c;
    FourFloatVector orientation;
    unsigned int unk60, unk64, unk68, unk6c;
};
struct Argument {
    const void* vtable;
    float scale;
    unsigned int unk08, unk0c;
    FourFloatVector orientation;
    void* identifier;
    unsigned int unk24, unk28, unk2c;
};

// Copies a CopyPacket with its orientation sign-flipped and calls FUN_00d31d30 with one or two Argument descriptors built from the source.
// @fnv 0x00d323f0
void __cdecl FUN_00d323f0(void* a, void* b, const CopyPacket* source, void* id1, void* id2) {
    __m128 orient = _mm_load_ps(&source->orientation.x);
    __m128 inverted = _mm_xor_ps(orient, ::DAT_010c44d0);
    Argument first;
    first.scale = ::DAT_0104da48;
    CopyPacket copy = *source;
    _mm_store_ps(&copy.orientation.x, inverted);
    const void* vptr = &UNK_010ce80c;
    first.vtable = vptr;
    first.orientation = source->orientation;
    first.identifier = id1;
    if (id2) {
        Argument second;
        second.vtable = vptr;
        second.scale = ::DAT_0104da48;
        second.orientation = source->orientation;
        second.identifier = id2;
        FUN_00d31d30(b, a, &copy, &first, &second);
    } else {
        FUN_00d31d30(b, a, &copy, &first, 0);
    }
}
}  // namespace fnv_00d323f0

#include "fnv/symbols_simd.h"
extern const char DAT_010cea38[];
extern const char DAT_010cea7c[];
extern const char DAT_010cea6c[];
extern const char DAT_010cea60[];
extern const char DAT_010cea54[];
extern const char DAT_010cea48[];
extern const char str_010cea1c[];


struct MonitorCommand {
    const char* name;
    unsigned int time;
    unsigned int timeHi;
    const char* subName;
};
struct StringCursor {
    int unk00;
    char* m_memPos;
    int unk08;
    char* m_memEnd;

    static __forceinline StringCursor& GetMonitorStream() {
        return *(StringCursor*)TlsGetValue(DAT_0126835c);
    }
    __forceinline void timerBegin(const char* name1, const char* name2) {
        if (m_memPos < m_memEnd) {
            MonitorCommand* cmd = (MonitorCommand*)m_memPos;
            cmd->name = name1;
            cmd->subName = name2;
            unsigned int ticks;
            ticks = static_cast<unsigned int>(__rdtsc());
            cmd->time = ticks;
            m_memPos = (char*)(cmd + 1);
        }
    }
    __forceinline void timerSplit(const char* name) {
        if (m_memPos < m_memEnd) {
            MonitorCommand* cmd = (MonitorCommand*)m_memPos;
            cmd->name = name;
            unsigned int ticks;
            ticks = static_cast<unsigned int>(__rdtsc());
            cmd->time = ticks;
            m_memPos = (char*)&cmd->subName;
        }
    }
    __forceinline void timerEnd(const char* name) { timerSplit(name); }
};

struct hkTransform;

struct hkVector4 {
    union { __m128 m_vComponents; struct { float x,y,z,w; }; };

    __forceinline void SetRotatedDirection(const hkTransform& a, const hkVector4& b);
    __forceinline void SetTransformedPoint(const hkTransform& a, const hkVector4& b);
};

struct hkTransform {
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;

    hkTransform() {}
    __forceinline hkTransform(const hkTransform& other) {
        m_kColumn0.m_vComponents=other.m_kColumn0.m_vComponents;
        m_kColumn1.m_vComponents=other.m_kColumn1.m_vComponents;
        m_kColumn2.m_vComponents=other.m_kColumn2.m_vComponents;
        m_vTranslation.m_vComponents=other.m_vTranslation.m_vComponents;
    }
};

__forceinline void hkVector4::SetRotatedDirection(const hkTransform& a, const hkVector4& b) {
    __m128 y = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    __m128 x = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    __m128 z = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, a.m_kColumn1.m_vComponents), _mm_mul_ps(x, a.m_kColumn0.m_vComponents)), _mm_mul_ps(z, a.m_kColumn2.m_vComponents));
}

__forceinline void hkVector4::SetTransformedPoint(const hkTransform& a, const hkVector4& b) {
    __m128 y = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    __m128 x = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    __m128 z = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, a.m_kColumn1.m_vComponents), _mm_mul_ps(x, a.m_kColumn0.m_vComponents)), _mm_add_ps(_mm_mul_ps(z, a.m_kColumn2.m_vComponents), a.m_vTranslation.m_vComponents));
}

__forceinline void transformSphere(hkVector4& __restrict out, const hkTransform& __restrict a, const hkVector4& __restrict sphere) {
    __m128 y = _mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0x55);
    __m128 x = _mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0x00);
    __m128 z = _mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0xaa);
    __m128 pos = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, a.m_kColumn1.m_vComponents), _mm_mul_ps(x, a.m_kColumn0.m_vComponents)), _mm_add_ps(_mm_mul_ps(z, a.m_kColumn2.m_vComponents), a.m_vTranslation.m_vComponents));
    __m128 unpck = _mm_unpackhi_ps(pos, sphere.m_vComponents);
    out.m_vComponents = _mm_shuffle_ps(pos, unpck, 0xc4);
}

struct hkSphere : hkVector4 {};

__forceinline void transformSpheres(const hkTransform& tr, const hkSphere* src, int count, hkSphere* dst) {
    hkTransform local = tr;
    int i = count - 1;
    do {
        hkVector4 value;
        value.SetTransformedPoint(local,src[i]);
        value.m_vComponents = _mm_shuffle_ps(value.m_vComponents,_mm_unpackhi_ps(value.m_vComponents,src[i].m_vComponents),0xc4);
        dst[i].m_vComponents = value.m_vComponents;
    } while (--i >= 0);
}

struct hkpShape {
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
    virtual int getNumCollisionSpheres();
    virtual const hkSphere* getCollisionSpheres(hkSphere* sphereBuffer);
};

struct CollisionSphereData {
    __forceinline void setSpheres(const hkSphere* p){ m_kSpheres=p; }
    const hkSphere* m_kSpheres;
    int m_iSphereCount;
    float m_fScalar;
};

struct hkpHeightFieldShape {
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
    virtual void CollideSpheres(const CollisionSphereData& input, hkSphere* hitResults);
};

struct hkMotionState {
    hkTransform m_kMotionTransform;
};

struct hkpCdBody {
    const hkpShape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    const hkMotionState* m_pMotionState;
};

struct CollisionAgentContext {
    int unk00;
    int unk04;
    float m_fScalar;
};

struct hkContactPoint {
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
};

struct ContactPointPair {
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
    ContactPointPair() {}
    __forceinline ContactPointPair(const hkpCdBody* a, const hkpCdBody* b) : m_pBodyA(a), m_pBodyB(b) {}
};

struct hkpCdPointCollector {
    virtual void v00();
    virtual void AddCdPoint(const ContactPointPair& point);
};

struct CollisionScratch { hkTransform transform; ContactPointPair contact; };

struct hkpCdBodyPairCollector {
    virtual void v00();
    virtual void AddCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
};

// @fnv 0x00d317d0
void __cdecl FUN_00d317d0(const void* a1, const void* a2, const void* a3, void* a4)
{
    const hkpCdBody* bodyA = static_cast<const hkpCdBody*>(a1);
    const hkpCdBody* bodyB = static_cast<const hkpCdBody*>(a2);
    const CollisionAgentContext* input = static_cast<const CollisionAgentContext*>(a3);
    hkpCdBodyPairCollector* collector = (hkpCdBodyPairCollector*)a4;

    StringCursor::GetMonitorStream().timerBegin("LtHeightField", "StGetSpheres");

    const hkpShape* shapeA = bodyA->m_pCollisionShape;
    hkpHeightFieldShape* shapeB = (hkpHeightFieldShape*)bodyB->m_pCollisionShape;
    hkTransform aTb;
    reinterpret_cast<::hkTransformCB22 *>(&(aTb))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(bodyB->m_pMotionState)), (*(const ::hkTransformCB22 *)(bodyA->m_pMotionState)));

    int count = ((hkpShape*)shapeA)->getNumCollisionSpheres();

    hkSphere* sphereBuffer = static_cast<hkSphere*>(hkMemoryRouter::getInstance().allocateStack((count * 16 + 127) & ~127));

    const hkSphere* spheres = ((hkpShape*)shapeA)->getCollisionSpheres(sphereBuffer);
    transformSpheres(aTb, spheres, count, sphereBuffer);

    StringCursor::GetMonitorStream().timerSplit("StCollide");

    hkSphere* hitResults = static_cast<hkSphere*>(hkMemoryRouter::getInstance().allocateStack((count * 16 + 127) & ~127));
    {
        const CollisionAgentContext* __restrict in = input;
        CollisionSphereData shB;
        shB.m_kSpheres = sphereBuffer;
        shB.m_iSphereCount = count;
        shB.m_fScalar = in->m_fScalar;
        shapeB->CollideSpheres(shB, hitResults);
    }

    StringCursor::GetMonitorStream().timerSplit(str_010cea1c);

    const hkSphere* hit = hitResults;
    for (int i = count - 1; i >= 0; ++hit, --i) {
        if (hit->w < 0.0f) {
            collector->AddCdBodyPair(*bodyA, *bodyB);
            break;
        }
    }

    hkMemoryRouter::getInstance().deallocateStack(hitResults);
    hkMemoryRouter::getInstance().deallocateStack(sphereBuffer);

    StringCursor::GetMonitorStream().timerEnd("lt");
}

namespace fnv_00d32190 {



extern char DAT_010ceaf4[];

struct FUN_00d32190_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;

};

// Allocates a FUN_00d32060_Class-sized object via m_pAllocator, records its size in m_w04, calls FUN_00d32060, and sets m_vptr to DAT_010ceaf4.
// @fnv 0x00d32190
FUN_00d32190_cls* __cdecl FUN_00d32190(const void* a1, const void* a2, const void* a3, void* a4)
{
    FUN_00d32190_cls* obj = (FUN_00d32190_cls*)hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(::FUN_00d32060_Class));
    obj->m_w04 = sizeof(::FUN_00d32060_Class);
    reinterpret_cast<::FUN_00d32060_Class *>((obj))->Init((*static_cast<const ::SourceRef *>(a2)), a1, a3, a4);
    obj->m_vptr = DAT_010ceaf4;
    return obj;
}
}  // namespace fnv_00d32190

// Moved from hkpheightfieldagent_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
#include "fnv/symbols_010c4000.h"

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern char DAT_010cea14[];

union CastVector {
    __m128 v;
    struct { float x,y,z,w; };
    template<int mask> __forceinline void broadcast(const CastVector& s) { v=_mm_shuffle_ps(s.v,s.v,mask); }
    __forceinline void mul(const CastVector& a,const CastVector& b) { v=_mm_mul_ps(a.v,b.v); }
    __forceinline void add(const CastVector& a,const CastVector& b) { v=_mm_add_ps(a.v,b.v); }
};
struct CastTransform {
    CastVector r0,r1,r2,translation;
};
static __forceinline void transformVector(CastVector& out,const CastTransform& t,const CastVector& in) {
    CastVector x,y,z,tx,ty,tz,xy,zt;
    x.broadcast<0>(in);
    y.broadcast<0x55>(in);
    z.broadcast<0xaa>(in);
    tx.mul(x,t.r0);
    ty.mul(y,t.r1);
    tz.mul(z,t.r2);
    xy.add(tx,ty);
    zt.add(tz,t.translation);
    out.add(xy,zt);
}
struct CastBody;
struct CastInput {
    void* dispatcher; void* filter; void* quality;
    float tolerance; float weldTolerance; float allowedPenetration;
    int broadPhaseMode; int collisionMode;
    void* config; void* constraintOwner; void* world; void* query;
    int queryFlags; int filterInfo; int material; int shapeKey;
    float time; float deltaTime; int flags; int mode;
    CastVector path;
    float maxExtraPenetration;
};
struct SphereCastInput {
    CastVector from,to;
    int filterInfo,filterInfoB;
    int shapeKey,shapeKeyB;
    float radius,maxExtraPenetration;
    int flags,mode;
};
struct CastCollector {
    char* vtable;
    float earlyOut;
    int flags,mode;
    CastVector worldPosition;
    float radius;
    int filterInfo,shapeKey,material;
    CastVector path;
    CastBody* body;
    void* output;
    int flags2,mode2;
};
struct CastShape {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual int count();
    virtual CastVector* getSpheres(void*);
};
struct SphereCastInput;
struct CastCollector;
struct CastHeightField {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void CastSphere(const SphereCastInput&,const CastBody&,CastCollector&) const;
};
struct CastBody {
    CastShape* shape;
    int shapeKey;
    CastTransform* transform;
};
struct TimerEventShort { const char* name; unsigned time, timeHi; };
struct TimerEvent : TimerEventShort { const char* first; };
struct CastWork {
    CastTransform relativeTransform;
};
struct TimerStream { void* begin; TimerEvent* current; void* capacity; TimerEvent* end; };
static __forceinline void event(TimerStream* stream,const char* name) {
    TimerEvent* e=stream->current;
    if(e<stream->end) {
        e->name=name;
        unsigned int stamp;
        stamp = static_cast<unsigned int>(__rdtsc());
        e->time=stamp;
        stream->current=(TimerEvent*)(static_cast<TimerEventShort*>(e)+1);
    }
}
// @fnv 0x00d31d30
extern "C" void __cdecl FUN_00d31d30(void* arg0,void* arg1,void* arg2,void* arg3,void* arg4) {
    TimerStream* stream=(TimerStream*)TlsGetValue(DAT_0126835c);
    TimerEvent* e=stream->current;
    if(e<stream->end) {
        e->name="LtHeightField";
        e->first="StClosestPoints";
        unsigned int stamp;
        stamp = static_cast<unsigned int>(__rdtsc());
        e->time=stamp;
        stream->current=e+1;
    }
    CastBody* bodyA=(CastBody*)arg0;
    CastBody* bodyB=(CastBody*)arg1;
    CastInput* input=(CastInput*)arg2;
    if(arg4) ::FUN_00d319e0(arg0,arg1,arg2,static_cast<::D323B0CollectorBase *>(arg4));
    event((TimerStream*)TlsGetValue(DAT_0126835c),"StGetSpheres");
    CastShape* shape=bodyA->shape;
    CastHeightField* __restrict heightField=(CastHeightField*)bodyB->shape;
    CastTransform relativeTransform;
    reinterpret_cast<::hkTransformCB22 *>(&(relativeTransform))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(bodyB->transform)),(*(const ::hkTransformCB22 *)(bodyA->transform)));
    int count=shape->count();
    hkMemoryRouter& scratch=hkMemoryRouter::getInstance();
    void* savedStack=scratch.allocateStack((count*16+127)&~127);
    __m128 c0=bodyB->transform->r0.v;
    __m128 c1=bodyB->transform->r1.v;
    __m128 c2=bodyB->transform->r2.v;
    __m128 path; (void)path;
    {
        __m128 lo=_mm_unpacklo_ps(c0,c1);
        __m128 ct=_mm_shuffle_ps(_mm_unpackhi_ps(c0,c1),c2,0xe4);
        c0=_mm_movelh_ps(lo,c2);
        c1=_mm_shuffle_ps(_mm_movehl_ps(c0,lo),c2,0xd4);
        c2=ct;
    }
    path=input->path.v;
    __m128 b0=_mm_shuffle_ps(path,path,0);
    __m128 p0=_mm_mul_ps(c0,b0);
    __m128 b1=_mm_shuffle_ps(path,path,0x55);
    __m128 p1=_mm_mul_ps(c1,b1);
    __m128 b2=_mm_shuffle_ps(path,path,0xaa);
    __m128 p2=_mm_mul_ps(c2,b2);
    __m128 localPath=_mm_add_ps(_mm_add_ps(p0,p1),p2);
    CastVector* spheres=shape->getSpheres(savedStack);
    event((TimerStream*)TlsGetValue(DAT_0126835c),"StCastSpheres");
    {
    SphereCastInput sphereInput;
    CastCollector collector;
    sphereInput.filterInfo=0;
    sphereInput.filterInfoB=0;
    sphereInput.maxExtraPenetration=input->maxExtraPenetration;
    collector.vtable=DAT_010cea14;
    collector.earlyOut=1.0f;
    collector.path=input->path;
    collector.body=bodyA;
    collector.output=arg3;
    if(count>0) { int remaining=count; do {
        CastVector sphere;
        sphere.v=spheres->v;
        sphereInput.radius=spheres->w;
        double radius=spheres->w;
        CastVector transformed;
        transformVector(transformed,relativeTransform,sphere);
        sphereInput.from.v=transformed.v;
        sphereInput.to.v=_mm_add_ps(sphereInput.from.v,localPath);
        CastVector worldPosition;
        transformVector(worldPosition,*bodyA->transform,sphere);
        collector.worldPosition.v=worldPosition.v;
        collector.radius=radius;
        heightField->CastSphere(sphereInput,*bodyB,collector);
        ++spheres;
    } while(--remaining); }
    hkMemoryRouter::getInstance().deallocateStack(savedStack);
    event((TimerStream*)TlsGetValue(DAT_0126835c),"lt");
    }
}
namespace fnv_00d324e0 {
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern char DAT_010ceae0[];
struct TimerEvent { const char* tag; unsigned int time; unsigned int unused; };
struct TimerStream { int unk00; TimerEvent* next; int unk08; TimerEvent* end; };
static __forceinline void timer(const char* tag) {
    TimerStream* s = (TimerStream*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    TimerEvent* p = s->next;
    if (p < s->end) {
        p->tag = tag;
        unsigned int t;
        t = static_cast<unsigned int>(__rdtsc());
        p->time = t;
        s->next = p + 1;
    }
}
struct Matrix {
    __m128 c0,c1,c2,c3;
};
struct SphereQuery {
    __m128* spheres; int count; float tolerance;
    SphereQuery(__m128* s,int n,float t):spheres(s),count(n),tolerance(t) {}
};
struct ShapeD {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28();
    virtual void query(const SphereQuery& q, __m128* out);
    virtual const __m128* spheres(__m128* buffer);
};
struct BodyD { ShapeD* shape; int unk04; const Matrix* transform; };
struct InputD { int unk00,unk04; float tolerance; };
struct ContactD { __m128 position; __m128 normal; unsigned int id; int unk24,unk28,unk2c; };
struct OutputD { ContactD* next; int constraint; };
struct ManagerD {
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual unsigned short add(const BodyD&, const BodyD&, const InputD&, OutputD&, int, ContactD*);
    virtual void v10(); virtual void remove(unsigned short id, int constraint);
};
static __forceinline __m128* reserve(int n) {
    int bytes = (n * 16 + 127) & -128;
    return static_cast<__m128*>(hkMemoryRouter::getInstance().allocateStack(bytes));
}
static __forceinline __m128 point(const Matrix& m, __m128 v) {
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0x55),m.c1), _mm_mul_ps(_mm_shuffle_ps(v,v,0),m.c0)),
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0xaa),m.c2),m.c3));
}
static __forceinline __m128 direction(const Matrix& m, __m128 v) {
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0x55),m.c1), _mm_mul_ps(_mm_shuffle_ps(v,v,0),m.c0)),
                     _mm_mul_ps(_mm_shuffle_ps(v,v,0xaa),m.c2));
}
struct AgentD {
    void* vtable; int unk04; ManagerD* manager; unsigned short* ids; int count; int capacity;
    void FUN_00d324e0(const BodyD& a, const BodyD& b, const InputD& input, OutputD& output);
};
// @fnv 0x00d324e0
void AgentD::FUN_00d324e0(const BodyD& a, const BodyD& b, const InputD& input, OutputD& output) {
    timer(DAT_010ceae0);
    ShapeD* shapeA = a.shape;
    ShapeD* shapeB = b.shape;
    Matrix relative;
    reinterpret_cast<::hkTransformCB22 *>(&(relative))->FUN_00cb22f0((const ::hkTransformCB22 &)(*b.transform),(const ::hkTransformCB22 &)(*a.transform));
    int n = count;
    __m128* transformed = reserve(n);
    unsigned short* id = ids;
    const __m128* src = shapeA->spheres(transformed);
    int last = n - 1;
    int j = last;
    const __m128 c0 = relative.c0;
    const __m128 c1 = relative.c1;
    const __m128 c2 = relative.c2;
    const __m128 c3 = relative.c3;
    const __m128* s = src + last;
    int delta = (char*)transformed - (char*)src;
    do {
        __m128 sphere = *s;
        __m128 v = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(sphere,sphere,0x55),c1), _mm_mul_ps(_mm_shuffle_ps(sphere,sphere,0),c0)),
                             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(sphere,sphere,0xaa),c2),c3));
        *(__m128*)((char*)s + delta) = _mm_shuffle_ps(v,_mm_unpackhi_ps(v,sphere),0xc4);
        --j;
        --s;
    } while (j >= 0);
    __m128* planes = reserve(n);
    shapeB->query(SphereQuery(transformed,n,input.tolerance),planes);
    float tolerance = input.tolerance;
    __m128* p = planes;
    __m128* sphere = transformed;
    for (int i = last; i >= 0; ++p,++sphere,++id,--i) {
        if (((float*)p)[3] > tolerance) {
            if (*id != 0xffff) {
                manager->remove(*id,output.constraint);
                *id = 0xffff;
            }
        } else {
            ContactD* c = output.next;
            float negW = -((float*)sphere)[3];
            __m128 pos = _mm_add_ps(_mm_mul_ps(_mm_set1_ps(negW),*p),*sphere);
            c->position = point(*b.transform,pos);
            c->normal = direction(*b.transform,*p);
            ((float*)&c->normal)[3] = ((float*)p)[3];
            if (*id == 0xffff) {
                *id = manager->add(a,b,input,output,0,c);
                if (*id != 0xffff) ++output.next;
            } else ++output.next;
            c->id = *id;
        }
    }
    hkMemoryRouter::getInstance().deallocateStack(planes);
    hkMemoryRouter::getInstance().deallocateStack(transformed);
    timer(::DAT_010c41f8);
}
}  // namespace fnv_00d324e0

// Moved from hkpheightfieldagent_rtm_variant.cpp (VEGAS-15).

// @fnv 0x00d319e0
void __cdecl FUN_00d319e0(const void* a, const void* b, const void* c, D323B0CollectorBase* collector)
{
    const hkpCdBody* bodyA = static_cast<const hkpCdBody*>(a);
    const hkpCdBody* bodyB = static_cast<const hkpCdBody*>(b);
    const CollisionAgentContext* input = static_cast<const CollisionAgentContext*>(c);

    StringCursor::GetMonitorStream().timerBegin(DAT_010cea38, DAT_010cea7c);

    const hkpShape* shapeA = bodyA->m_pCollisionShape;
    hkpHeightFieldShape* shapeB = (hkpHeightFieldShape*)bodyB->m_pCollisionShape;
    CollisionScratch scratch;
    reinterpret_cast<::hkTransformCB22 *>(&(scratch.transform))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(bodyB->m_pMotionState)), (*(const ::hkTransformCB22 *)(bodyA->m_pMotionState)));

    int count = ((hkpShape*)shapeA)->getNumCollisionSpheres();

    hkSphere* sphereBuffer = static_cast<hkSphere*>(hkMemoryRouter::getInstance().allocateStack((count * 16 + 127) & ~127));

    StringCursor::GetMonitorStream().timerSplit(DAT_010cea6c);

    const hkSphere* spheres = ((hkpShape*)shapeA)->getCollisionSpheres(sphereBuffer);

    StringCursor::GetMonitorStream().timerSplit(DAT_010cea60);

    transformSpheres(scratch.transform, spheres, count, sphereBuffer);

    StringCursor::GetMonitorStream().timerSplit(DAT_010cea54);

    const CollisionAgentContext* __restrict in = input;
    hkSphere* hitResults = static_cast<hkSphere*>(hkMemoryRouter::getInstance().allocateStack((count * 16 + 127) & ~127));
    {
        CollisionSphereData shB;
        shB.m_kSpheres = sphereBuffer;
        shB.m_iSphereCount = count;
        shB.m_fScalar = in->m_fScalar;
        shapeB->CollideSpheres(shB, hitResults);
    }

    StringCursor::GetMonitorStream().timerSplit(DAT_010cea48);

    float tolerance = in->m_fScalar;
    const hkSphere* __restrict hitPtr = hitResults;
    const hkSphere* __restrict spherePtr = sphereBuffer;
    for (int i = count - 1; i >= 0; ++hitPtr, ++spherePtr, --i) {
        const hkSphere& __restrict hit = *hitPtr;
        if (hit.w <= tolerance) {
            ContactPointPair& point = scratch.contact;
            point.m_pBodyA = bodyA;
            point.m_pBodyB = bodyB;
            float distToPoint = -spherePtr->w - hit.w;

            hkVector4 posInB;
            __m128 dist4 = _mm_load_ss(&distToPoint);
            dist4 = _mm_shuffle_ps(dist4,dist4,0);
            posInB.m_vComponents = _mm_add_ps(_mm_mul_ps(dist4, hit.m_vComponents), spherePtr->m_vComponents);

            point.m_kPoint.m_vContactPosition.SetTransformedPoint(bodyB->m_pMotionState->m_kMotionTransform, posInB);
            point.m_kPoint.m_vSeparatingNormal.SetRotatedDirection(bodyB->m_pMotionState->m_kMotionTransform, hit);
            point.m_kPoint.m_vSeparatingNormal.w = hit.w;

            ((hkpCdPointCollector*)collector)->AddCdPoint(point);
        }
    }

    hkMemoryRouter::getInstance().deallocateStack(hitResults);
    hkMemoryRouter::getInstance().deallocateStack(sphereBuffer);

    StringCursor::GetMonitorStream().timerEnd(::str_01076f38);
}

struct Scale {
    __m128 value;
    Scale(float f) { value = _mm_load_ss(&f); }
    __forceinline __m128 repeated() const { return _mm_shuffle_ps(value,value,0); }
};
static __forceinline void S_combine(hkVector4& out, const hkVector4& start, const hkVector4& direction, const Scale& amount) {
    out.m_vComponents = _mm_add_ps(start.m_vComponents, _mm_mul_ps(amount.repeated(), direction.m_vComponents));
}
static __forceinline void S_accumulate(hkVector4& out, const Scale& amount, const hkVector4& direction) {
    out.m_vComponents = _mm_add_ps(out.m_vComponents, _mm_mul_ps(amount.repeated(), direction.m_vComponents));
}
static __forceinline void S_rotate(hkVector4& out, const hkTransform& matrix, const hkVector4& input) {
    __m128 first = _mm_mul_ps(matrix.m_kColumn0.m_vComponents, _mm_shuffle_ps(input.m_vComponents,input.m_vComponents,0));
    __m128 second = _mm_mul_ps(matrix.m_kColumn1.m_vComponents, _mm_shuffle_ps(input.m_vComponents,input.m_vComponents,0x55));
    __m128 third = _mm_mul_ps(matrix.m_kColumn2.m_vComponents, _mm_shuffle_ps(input.m_vComponents,input.m_vComponents,0xaa));
    out.m_vComponents = _mm_add_ps(_mm_add_ps(first, second), third);
}

struct S_00d32270_In;
struct S_00d32270_Target
{
    virtual void v00();
    virtual void v04(struct S_00d32270_In* in);
    float m_04;
};

struct S_00d32270_Q
{
    int unk00;
    int unk04;
    hkTransform* m_08;
};

struct S_00d32270_P
{
    hkVector4 v00;
    float f10;
};

struct S_00d32270_cls
{
    int unk00;
    float m_04;
    int unk08;
    int unk0c;
    hkVector4 m_10;
    float m_20;
    int unk24;
    int unk28;
    int unk2c;
    hkVector4 m_30;
    int m_40;
    S_00d32270_Target* m_44;
    void FUN_00d32270(S_00d32270_Q* q, S_00d32270_P* p);
};

struct S_00d32270_In
{
    hkVector4 a;
    hkVector4 b;
    int m40;
    S_00d32270_Q* q;
    S_00d32270_In(int a, S_00d32270_Q* b) : m40(a), q(b) {}
};

static __forceinline float S_min(float a, float b) { return (b < a) ? b : a; }

// @fnv 0x00d32270
void S_00d32270_cls::FUN_00d32270(S_00d32270_Q* q, S_00d32270_P* p)
{
    __declspec(align(16)) S_00d32270_In in(m_40, q);
    float s = -m_20;
    float t = p->f10;
    S_combine(in.a, m_10, m_30, Scale(p->f10));
    S_rotate(in.b, *q->m_08, p->v00);
    S_accumulate(in.a, Scale(s), in.b);
    in.b.w = t;
    m_44->v04(&in);
    float o = m_44->m_04;
    m_04 = S_min(m_04, o);
}
#include "generated/data/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent.inc"
#include "generated/data/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent_gs_ehsc_nogs_noehsc_variant.inc"
#include "generated/data/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent_rtm_variant.inc"
