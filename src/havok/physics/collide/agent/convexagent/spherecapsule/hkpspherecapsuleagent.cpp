
// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include <intrin.h>
#include <windows.h>
#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/symbols_00d23000.h"
#include "fnv/symbols_00d3a000.h"
#include "fnv/symbols_00d3e000.h"
#include "fnv/symbols_00d3f000.h"
#include "fnv/symbols_00daf000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010ce000.h"
#include "fnv/symbols_01268000.h"
struct S_00d3ef70_CdBody;
struct S_00d3ef70_Input;
struct S_00d3ef70_Agent;
struct S_00d3ef70_Collector;

typedef S_00d3ef70_Agent* (*S_00d3ef70_CreateFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, void*);
typedef void (*S_00d3ef70_GetPenetrationsFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_GetClosestPointsFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);
typedef void (*S_00d3ef70_LinearCastFunc)(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&, S_00d3ef70_Collector*);

struct S_00d3ef70_AgentFuncs {
    S_00d3ef70_CreateFunc m_pCreateFunc;
    S_00d3ef70_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    S_00d3ef70_GetClosestPointsFunc m_getClosestPointsFunc;
    S_00d3ef70_LinearCastFunc m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct S_00d3ef70_Dispatcher {
};

void FUN_00d3e330(const S_00d3ef70_CdBody&, const S_00d3ef70_CdBody&, const S_00d3ef70_Input&, S_00d3ef70_Collector&);


class InnerCls {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned short a, int b);
};

inline void InnerCls::v0() {}
inline void InnerCls::v1() {}
inline void InnerCls::v2() {}
inline void InnerCls::v3() {}
inline void InnerCls::v4() {}
inline void InnerCls::v5(unsigned short a, int b) { a; b; }

class FUN_00d3e2b0_cls {
public:
    virtual void v0(int a);
    int m_i04;
    InnerCls *m_pInner;
    unsigned short m_w0c;
    void FUN_00d3e2b0(int a1);
};

// @fnv 0x00d3e2b0
inline void FUN_00d3e2b0_cls::v0(int aiValue) { aiValue; }

void FUN_00d3e2b0_cls::FUN_00d3e2b0(int a1)
{
    if (m_w0c != 0xffff) {
        m_pInner->v5(m_w0c, a1);
    }
    v0(1);
}

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct ObjAllocator {
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct SmallRecord {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
};

extern char DAT_010cf018[];


// @fnv 0x00d3e2f0
void __cdecl FUN_00d3e2f0(int aiUnused1, int aiUnused2, int aiUnused3, int aiValue) {
    AllocHolder* pAllocHolder = static_cast<AllocHolder*>(::FUN_00c85750());
    ObjAllocator* allocator = (ObjAllocator*)pAllocHolder->m_pAllocator;
    SmallRecord* pRecord = (SmallRecord*)allocator->Alloc(0x10);
    pRecord->m_w04 = 0x10;
    pRecord->m_w06 = 1;
    pRecord->m_i08 = aiValue;
    pRecord->m_w0C = 0xffff;
    pRecord->m_vptr = DAT_010cf018;
}


// @fnv 0x00d3e510
void FUN_00d3e510(const void* a, const void* b, const void* c, void* d)
{
    ::FUN_00d3e330(*static_cast<const ::S_00d3ef70_CdBody *>(a), *static_cast<const ::S_00d3ef70_CdBody *>(b), *static_cast<const ::S_00d3ef70_Input *>(c), *static_cast<::S_00d3ef70_Collector *>(d));
}


struct FUN_00d3f040_tmp {
    const char* str;
    unsigned char flag;
    void* value;
};


// Builds a FUN_00d3f040_tmp with value a3, flag 0 and str pointing at DAT_010ce81c, then calls FUN_00d3e330(a1, a0, a2, &t).
// @fnv 0x00d3f040
void __cdecl FUN_00d3f040(const void* a0, const void* a1, const void* a2, void* uiValue)
{
    FUN_00d3f040_tmp t;
    t.value = uiValue;
    t.flag = 0;
    t.str = &DAT_010ce81c;
    ::FUN_00d3e330(*static_cast<const ::S_00d3ef70_CdBody *>(a1), *static_cast<const ::S_00d3ef70_CdBody *>(a0), *static_cast<const ::S_00d3ef70_Input *>(a2), (*(::S_00d3ef70_Collector *)(&t)));
}

struct AgentDispatchDescriptor {
    const void* dispatchTable;
    unsigned char isFlipped;
    void* volatile tag;
};
struct CollisionDispatcher {
    void FUN_00d3f000(void* bodyA, void* bodyB, void* volatile input, void* tag);
};
// Builds an AgentDispatchDescriptor with the given tag and a fixed dispatch table, then calls FUN_00d3e510 with the bodies swapped.
// @fnv 0x00d3f000
void CollisionDispatcher::FUN_00d3f000(void* bodyA, void* bodyB, void* volatile input, void* tag)
{
    AgentDispatchDescriptor descriptor;
    descriptor.tag = tag;
    descriptor.isFlipped = false;
    descriptor.dispatchTable = &DAT_010ce81c;
    ::FUN_00d3e510(bodyB, bodyA, input, &descriptor);
}


extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern const char str_010cf158[];

struct SphCap_Mon {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_cap;
    char* m_capMinus16;
};

struct SphCap_Timer {
    const char* m_name;
    unsigned int m_ticks;
    unsigned int m_unk08;
};

struct SphCap_Vector4 {
    __m128 m_vComponents;
};

struct SphCap_Transform {
    SphCap_Vector4 m_kColumn0;
    SphCap_Vector4 m_kColumn1;
    SphCap_Vector4 m_kColumn2;
    SphCap_Vector4 m_vTranslation;
};

struct __declspec(align(16)) SphCap_Vector4F {
    float x;
    float y;
    float z;
    float w;
};

struct SphCap_TransformF {
    SphCap_Vector4F c0;
    SphCap_Vector4F c1;
    SphCap_Vector4F c2;
    SphCap_Vector4F c3;
};

struct SphCap_SegResult {
    SphCap_Vector4 m_kClosestPoint;
};

struct SphCap_Frame {
    SphCap_SegResult closest;
    SphCap_Vector4F t0;
    SphCap_Vector4F t1;
    SphCap_Vector4F t2;
    SphCap_Vector4F t3;
    SphCap_Vector4 points[2];
};

struct SphCap_Shape {
    void* m_vtbl;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    float m_fSphereRadius;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    SphCap_Vector4 m_kVertexA;
    SphCap_Vector4 m_kVertexB;
};

struct S_00d3ef70_CdBody {
    const SphCap_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const SphCap_Transform* m_pMotionState;
};

struct S_00d3ef70_Collector {
    virtual void slot00();
    virtual void AddCdBodyPair(const S_00d3ef70_CdBody& a, const S_00d3ef70_CdBody& b);
};


struct Group1 {
    SphCap_Vector4F t0;
    SphCap_Vector4F t1;
};
struct Group2 {
    SphCap_Vector4F t2;
    SphCap_Vector4F t3;
};

// @fnv 0x00d3e330
void FUN_00d3e330(const S_00d3ef70_CdBody& bodyA, const S_00d3ef70_CdBody& bodyB, const S_00d3ef70_Input& input, S_00d3ef70_Collector& collector)
{
    {
        SphCap_Mon* mon = (SphCap_Mon*)TlsGetValue(DAT_0126835c);
        char* pos = mon->m_kRayEnd;
        if (pos < mon->m_capMinus16) {
            volatile unsigned int ticks;
            SphCap_Timer* t = (SphCap_Timer*)pos;
            t->m_name = str_010cf158;
            { unsigned int ticks;
ticks = static_cast<unsigned int>(__rdtsc());
t->m_ticks = ticks; }
            mon->m_kRayEnd = pos + sizeof(SphCap_Timer);
        }
    }

    SphCap_SegResult local_closest;
    Group1 group1;
    Group2 group2;
    SphCap_Vector4 local_points[2];

    SphCap_SegResult& closest = local_closest;
    const SphCap_Shape* sphere = bodyA.m_pCollisionShape;
    const SphCap_Vector4& spherePos = bodyA.m_pMotionState->m_vTranslation;
    const SphCap_Shape* capsule = bodyB.m_pCollisionShape;

    SphCap_Vector4 (&points)[2] = local_points;
    {
        const SphCap_Transform& tin = *bodyB.m_pMotionState;
        group1.t0 = *(const SphCap_Vector4F*)&tin.m_kColumn0;
        group1.t1 = *(const SphCap_Vector4F*)&tin.m_kColumn1;
        group2.t2 = *(const SphCap_Vector4F*)&tin.m_kColumn2;
        group2.t3 = *(const SphCap_Vector4F*)&tin.m_vTranslation;
        __m128 c0 = _mm_load_ps((const float*)&group1.t0);
        __m128 c1 = _mm_load_ps((const float*)&group1.t1);
        __m128 c2 = _mm_load_ps((const float*)&group2.t2);
        __m128 c3 = _mm_load_ps((const float*)&group2.t3);
        const SphCap_Vector4* in = &capsule->m_kVertexA;
        for (int i = 1; i >= 0; i--) {
            __m128 v = in[i].m_vComponents;
            __m128 b = _mm_shuffle_ps(v, v, 0x55);
            __m128 a = _mm_shuffle_ps(v, v, 0);
            __m128 c = _mm_shuffle_ps(v, v, 0xaa);
            points[i].m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(b, c1), _mm_mul_ps(a, c0)), _mm_add_ps(_mm_mul_ps(c, c2), c3));
        }
    }

    {
        ::FUN_00d230e0((const ::hkVector4D230 &)(spherePos), (const ::hkVector4D230 &)(points[0]), (const ::hkVector4D230 &)(points[1]), (::hkVector4D230 &)(closest));

        float radiusSum = capsule->m_fSphereRadius + sphere->m_fSphereRadius;
        __m128 d = _mm_sub_ps(closest.m_kClosestPoint.m_vComponents, spherePos.m_vComponents);
        d = _mm_mul_ps(d, d);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
        s = _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), s);
        float rr = radiusSum * radiusSum;
        float distSq;
        _mm_store_ss(&distSq, s);
        if (distSq < rr)
            collector.AddCdBodyPair(bodyA, bodyB);
    }

    {
        SphCap_Mon* mon = (SphCap_Mon*)TlsGetValue(DAT_0126835c);
        char* pos = mon->m_kRayEnd;
        if (pos < mon->m_capMinus16) {
            volatile unsigned int ticks;
            SphCap_Timer* t = (SphCap_Timer*)pos;
            t->m_name = ::DAT_010c41f8;
            { unsigned int ticks;
ticks = static_cast<unsigned int>(__rdtsc());
t->m_ticks = ticks; }
            mon->m_kRayEnd = pos + sizeof(SphCap_Timer);
        }
    }
}

// Moved from hkpspherecapsuleagent_rtm_variant.cpp (VEGAS-15).

// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/symbols_00c85000.h"

typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef uintptr_t hkUlong;
typedef size_t hk_size_t;
class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
typedef int hkBool32;
class hkBool
{
public:
typedef char CompileTimeTrueType;inline hkBool(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};
template<typename ENUM,typename STORAGE>
class hkEnum
{
public:
hkEnum()
{
}
hkEnum(ENUM e)
{
m_kStorage=static_cast<STORAGE>(e);
}
private:
STORAGE m_kStorage;};
template<typename TYPE>
class ValueWrapper
{
public:
__forceinline ValueWrapper(){}
__forceinline void operator=(TYPE e)
{
m_kStorage=e;
}
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline operator TYPE()const
{
return val();
}
private:
TYPE m_kStorage;};
template<typename T>
class hkThreadLocalData
{
public:
hkThreadLocalData()
{
m_slotID=TlsAlloc();
}
__forceinline T getData()const
{
return(T)(hkUlong)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};
namespace vc_attributes
{
enum YesNoMaybe
{
No=0x0fff0001,
Maybe=0x0fff0010,
Yes=0x0fff0100
};
enum AccessType
{
NoAccess=0,
Read=1,
Write=2,
ReadWrite=3
};
[repeatable]
[source_annotation_attribute(Parameter)]
struct PreAttribute
{
PreAttribute();
unsigned int Deref;
YesNoMaybe Valid;
YesNoMaybe Null;
YesNoMaybe Tainted;
AccessType Access;
size_t ValidElementsConst;
size_t ValidBytesConst;
const wchar_t*ValidElements;
const wchar_t*ValidBytes;
const wchar_t*ValidElementsLength;
const wchar_t*ValidBytesLength;
size_t WritableElementsConst;
size_t WritableBytesConst;
const wchar_t*WritableElements;
const wchar_t*WritableBytes;
const wchar_t*WritableElementsLength;
const wchar_t*WritableBytesLength;
size_t ElementSizeConst;
const wchar_t*ElementSize;
YesNoMaybe NullTerminated;
const wchar_t*Condition;
};};
const::vc_attributes::YesNoMaybe SA_Yes=::vc_attributes::Yes;
const::vc_attributes::YesNoMaybe SA_No=::vc_attributes::No;
const::vc_attributes::AccessType SA_Read=::vc_attributes::Read;
typedef::vc_attributes::PreAttribute SA_Pre;
class hkMemoryAllocator
{
public:
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};
struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();protected:
ValueWrapper<void*>m_next;};
class NineIntegerRecord
{
public:
typedef hkMemoryAllocator Allocator;
static NineIntegerRecord&__cdecl GetMonitorStream();inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
StringPointerTriple m_aiEntries;
Allocator*m_pTemp;
Allocator*m_pStreamAllocator;};
class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject(){}
};
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject(class FinishingFlag flag){}
};
typedef __m128 hkQuadReal;
class hkVector4;
typedef const hkVector4&hkVector4Parameter;
class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
VectorComponentValue(hkReal x)
{
m_vValue=_mm_load_ss(&x);
}
operator hkReal()const
{
hkReal s;
_mm_store_ss(&s,m_vValue);
return s;
}
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
__forceinline const hkQuadReal&getQuad()const
{
return m_vValue;
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;
namespace MathUtilities
{
inline hkReal __cdecl sqrt(hkReal r){return::sqrtf(r);}
inline hkReal __cdecl fabs(hkReal r){return::fabsf(r);}
}
class hkTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
__forceinline void setZero4();
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVector4&b);
__forceinline VectorComponentValue dot3(const hkVector4&a)const;
__forceinline VectorComponentValue lengthSquared3()const;
__forceinline VectorComponentValue lengthInverse3()const;
__forceinline void normalize3();
__forceinline hkReal&operator()(int i);
__forceinline const hkReal&operator()(int i)const;
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkVector4&getColumn(int i);
__forceinline const hkVector4&getColumn(int i)const;
protected:
hkVector4 m_kColumn0;
hkVector4 m_kColumn1;
hkVector4 m_kColumn2;};
class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkTransform(const hkTransform&r);
__forceinline const hkVector4&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};
inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4::setZero4()
{
m_vComponents=_mm_setzero_ps();
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
inline void hkVector4::_setTransformedPos(const hkTransform&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
inline VectorComponentValue hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline VectorComponentValue hkVector4::lengthSquared3()const
{
return this->dot3(*this);
}
inline VectorComponentValue hkVector4::lengthInverse3()const
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=this->dot3(*this).getQuad();
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
return _mm_andnot_ps(len2EqualsZero,refined);}
inline void hkVector4::normalize3()
{
hkQuadReal lenInv=lengthInverse3().broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
}
inline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline hkVector4&hkMatrix3::getColumn(int x)
{
return(&m_kColumn0)[x];
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVector4&hkTransform::getTranslation()const
{
return m_vTranslation;
}
const hkRotation&hkTransform::getRotation()const
{
return m_rotation;
}
hkTransform::hkTransform(const hkTransform&t)
{
const hkVector4 r0=t.m_rotation.getColumn(0);
const hkVector4 r1=t.m_rotation.getColumn(1);
const hkVector4 r2=t.m_rotation.getColumn(2);
const hkVector4 r3=t.m_rotation.getColumn(3);
m_rotation.getColumn(0)=r0;
m_rotation.getColumn(1)=r1;
m_rotation.getColumn(2)=r2;
m_rotation.getColumn(3)=r3;}
class StringCursor
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
{
return*(*reinterpret_cast<::hkThreadLocalData< ::StringCursor *> *>(&::DAT_0126835c)).getData();
}
public:
__forceinline char*__cdecl GetStreamStart(){return m_kRayStart.val();}
__forceinline char*__cdecl GetStreamEnd(){return m_kRayEnd.val();}
__forceinline char*__cdecl getCapacityMinus16(){return m_pCurrentCommand.val();}
__forceinline hkBool __cdecl memoryAvailable()
{
return GetStreamEnd()<getCapacityMinus16();
}
__forceinline void __cdecl setEnd(char*ptr){m_kRayEnd=ptr;}
public:
static void __cdecl init();
public:
ValueWrapper<char*>m_kRayStart;
ValueWrapper<char*>m_kRayEnd;
ValueWrapper<char*>m_pRayCursor;
ValueWrapper<char*>m_pCurrentCommand;
hkBool m_bFlag;
public:
struct Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32 m_uiStartTicks;
hkUint32 m_uiEndTicks;
__forceinline void setTime();
};};
void StringCursor::CommandTimingEntry::setTime()
{
hkUint32 ticks;
ticks = static_cast<unsigned int>(__rdtsc());
m_uiStartTicks=ticks;
}
class hkAabb
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVector4 m_kMinimumCorner;};
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkVector4&getPosition();
inline const hkVector4&getNormal()const;
inline hkVector4&getSeparatingNormal();
inline void setDistance(hkReal d);
protected:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVector4 m_vContactPosition;
hkVector4 m_vSeparatingNormal;};
inline const hkVector4&hkContactPoint::getNormal()const
{
return m_vSeparatingNormal;
}
inline hkVector4&hkContactPoint::getPosition()
{
return m_vContactPosition;
}
inline hkVector4&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}
inline void hkContactPoint::setDistance(hkReal d)
{
m_vSeparatingNormal(3)=d;
}
class Vector4WithInt24W:public hkVector4
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
enum CollisionShapeType
{
HK_SHAPE_INVALID=0,
HK_SHAPE_SPHERE,
HK_FIRST_SHAPE_TYPE=HK_SHAPE_SPHERE,
HK_SHAPE_CYLINDER,
HK_SHAPE_TRIANGLE,
HK_SHAPE_BOX,
HK_SHAPE_CAPSULE,
HK_SHAPE_CONVEX_VERTICES,
HK_SHAPE_COLLECTION,
HK_SHAPE_BV_TREE,
HK_SHAPE_LIST,
HK_SHAPE_MOPP,
HK_SHAPE_CONVEX_TRANSLATE,
HK_SHAPE_CONVEX_TRANSFORM,
HK_SHAPE_SAMPLED_HEIGHT_FIELD,
HK_SHAPE_EXTENDED_MESH,
HK_SHAPE_TRANSFORM,
HK_SHAPE_COMPRESSED_MESH,
HK_SHAPE_MAX_ID_SPU=HK_SHAPE_COMPRESSED_MESH+1,
HK_SHAPE_CONVEX,
HK_SHAPE_PACKED_CONVEX_VERTICES,
HK_SHAPE_MOPP_EMBEDDED,
HK_SHAPE_CONVEX_PIECE,
HK_SHAPE_MULTI_SPHERE,
HK_SHAPE_CONVEX_LIST,
HK_SHAPE_TRIANGLE_COLLECTION,
HK_SHAPE_MULTI_RAY,
HK_SHAPE_HEIGHT_FIELD,
HK_SHAPE_SPHERE_REP,
HK_SHAPE_BV,
HK_SHAPE_PLANE,
HK_SHAPE_PHANTOM_CALLBACK,
HK_SHAPE_USER0,
HK_SHAPE_USER1,
HK_SHAPE_USER2,
HK_SHAPE_MAX_ID,
HK_SHAPE_ALL=-1
};
class hkpCollisionDispatcher;
typedef hkUint32 hkpShapeKey;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
protected:
virtual void CalculateAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const=0;
public:
static void __cdecl resetShapeFunctions();
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<::CollisionShapeType,hkUint32>m_type;
public:
hkpShape(class FinishingFlag flag):hkReferencedObject(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;};
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
struct GskAgentInput;
class hkpContactMgr;
struct WorldOperationEntry;
class hkpConstraintOwner;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;};
class hkpCdBodyPairCollector;
struct ContactPointPair
{
ContactPointPair(const hkpCdBody&a,const hkpCdBody&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody&m_pBodyA;
const hkpCdBody&m_pBodyB;};
class hkpCdPointCollector
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
inline virtual ~hkpCdPointCollector();
virtual void AddCdPoint(const ContactPointPair&point)=0;
protected:
hkReal m_fEarlyOutDistance;};
class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
virtual void ProcessAgent(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&result)=0;
protected:
inline virtual ~hkpCollisionAgent();
protected:
hkpContactMgr*m_pContactManager;
public:
inline hkpContactMgr*getContactMgr();};
class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}};
class hkpSphereCapsuleAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&pointDetails);
static void __cdecl FUN_00d3ebe0(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void cleanup(hkpConstraintOwner&info);
protected:
__forceinline hkpSphereCapsuleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createSphereCapsuleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createCapsuleSphereAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
public:
enum ClosestPointResult
{
ST_CP_MISS,
ST_CP_HIT,
};
private:
static __forceinline ClosestPointResult getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&cpoint);
protected:
static ClosestPointResult __cdecl ComputeClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&cpoint);
hkContactPointId m_usContactPointId;
};

// Registers two collision agent function tables with the dispatcher for the type pairs (5,1) and (1,5).
// @fnv 0x00d3ef70
void FUN_00d3ef70(S_00d3ef70_Dispatcher* dispatcher)
{
    {
        S_00d3ef70_AgentFuncs agentFuncs;
        agentFuncs.m_pCreateFunc = ((S_00d3ef70_Agent *(&)(const S_00d3ef70_CdBody &, const S_00d3ef70_CdBody &, const S_00d3ef70_Input &, void *))::FUN_00d3e2f0);
        agentFuncs.m_pQueryPenetrationsFunc = ((void (&)(const S_00d3ef70_CdBody &, const S_00d3ef70_CdBody &, const S_00d3ef70_Input &, S_00d3ef70_Collector &))::FUN_00d3f040);
        agentFuncs.m_getClosestPointsFunc = ((void (&)(const S_00d3ef70_CdBody &, const S_00d3ef70_CdBody &, const S_00d3ef70_Input &, S_00d3ef70_Collector &))::FUN_00d3f4c0);
        agentFuncs.m_pLinearCastFunc = ((void (&)(const S_00d3ef70_CdBody &, const S_00d3ef70_CdBody &, const S_00d3ef70_Input &, S_00d3ef70_Collector &, S_00d3ef70_Collector *))::FUN_00d3ac80);
        agentFuncs.m_bIsFlipped = true;
        agentFuncs.m_bIsPredictive = false;
        reinterpret_cast<::FUN_00cfbbe0_cls *>((dispatcher))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(agentFuncs), 5, 1);
    }
    {
        S_00d3ef70_AgentFuncs agentFuncs;
        agentFuncs.m_pCreateFunc = ((S_00d3ef70_Agent *(&)(const S_00d3ef70_CdBody &, const S_00d3ef70_CdBody &, const S_00d3ef70_Input &, void *))::FUN_00d3e270);
        agentFuncs.m_pQueryPenetrationsFunc = FUN_00d3e330;
        agentFuncs.m_getClosestPointsFunc = ((void (&)(const S_00d3ef70_CdBody &, const S_00d3ef70_CdBody &, const S_00d3ef70_Input &, S_00d3ef70_Collector &))::hkpSphereCapsuleAgent::FUN_00d3ebe0);
        agentFuncs.m_pLinearCastFunc = ((void (&)(const S_00d3ef70_CdBody &, const S_00d3ef70_CdBody &, const S_00d3ef70_Input &, S_00d3ef70_Collector &, S_00d3ef70_Collector *))::FUN_00daf8e0);
        agentFuncs.m_bIsFlipped = false;
        agentFuncs.m_bIsPredictive = false;
        reinterpret_cast<::FUN_00cfbbe0_cls *>((dispatcher))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(agentFuncs), 1, 5);
    }
}
class hkpSphereRepShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual int GetNumCollisionSpheres()const=0;
public:
hkpSphereRepShape(CollisionShapeType type):hkpShape(type){}
hkpSphereRepShape(FinishingFlag flag):hkpShape(flag){m_type=HK_SHAPE_SPHERE_REP;}
};
class hkpConvexShape:public hkpSphereRepShape
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkReal getRadius()const;
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
protected:
inline hkpConvexShape(CollisionShapeType type,hkReal radius);
hkReal m_fSphereRadius;
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};
inline hkReal hkpConvexShape::getRadius()const
{
return m_fSphereRadius;
}
class hkpCapsuleShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkVector4*GetIndexedVertices()const;
public:
hkpCapsuleShape(FinishingFlag flag):hkpConvexShape(flag){m_type=HK_SHAPE_CAPSULE;}
protected:
hkVector4 m_kVertexA;};
const hkVector4*hkpCapsuleShape::GetIndexedVertices()const
{
return&m_kVertexA;
}
class hkpSphereShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
public:
hkpSphereShape(FinishingFlag flag):hkpConvexShape(flag){m_type=HK_SHAPE_SPHERE;}
};
namespace hkVector4Util_S
{
__forceinline void __cdecl calculatePerpendicularVector(const hkVector4&vectorIn,hkVector4&biVectorOut);
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut);}
inline void __cdecl hkVector4Util_S::calculatePerpendicularVector(const hkVector4&vectorIn,hkVector4&biVectorOut)
{
int min=0;
int ok1=1;
int ok2=2;
hkReal a0=MathUtilities::fabs(vectorIn(0));
hkReal a1=MathUtilities::fabs(vectorIn(1));
hkReal a2=MathUtilities::fabs(vectorIn(2));
if(a1<a0)
{
ok1=0;
min=1;
a0=a1;
}
if(a2<a0)
{
ok2=min;
min=2;
}
biVectorOut.setZero4();
biVectorOut(ok1)=vectorIn(ok2);
biVectorOut(ok2)=-vectorIn(ok1);}
inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
vectorsOut[i]._setTransformedPos(unaliased,vectorsIn[i]);
}while(--i>=0);}
class SegmentSegmentClosestPoint
{
public:
enum
{
CLSLS_POINTA_START=1,
CLSLS_POINTA_END=2,
CLSLS_POINTB_START=4,
CLSLS_POINTB_END=8
};
struct Vector4Wrapper
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(SegmentSegmentClosestPoint::Vector4Wrapper));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kClosestPoint;
};
};
__forceinline hkpSphereCapsuleAgent::ClosestPointResult hkpSphereCapsuleAgent::getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&cpoint)
{
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
const hkpCapsuleShape*capsuleB=static_cast<const hkpCapsuleShape*>(bodyB.getShape());
const hkVector4&posA=bodyA.getTransform().getTranslation();
hkVector4 capsB[2];hkVector4Util_S::TransformPointArray(bodyB.getTransform(),capsuleB->GetIndexedVertices(),2,capsB);
SegmentSegmentClosestPoint::Vector4Wrapper result;::FUN_00d230e0((const ::hkVector4D230 &)(posA),(const ::hkVector4D230 &)(capsB[0]),(const ::hkVector4D230 &)(capsB[1]),(::hkVector4D230 &)(result));
hkVector4 aMinusB;aMinusB.setSub4(posA,result.m_kClosestPoint);
const hkReal radiusSum=sphereA->getRadius()+capsuleB->getRadius();
const hkReal refDist=radiusSum+input.getTolerance();
hkReal distSquared=aMinusB.lengthSquared3();
if(distSquared>=refDist*refDist)
{
return ST_CP_MISS;
}
hkReal dist;
if(distSquared>0.0f)
{
dist=MathUtilities::sqrt(distSquared);
cpoint.getSeparatingNormal()=aMinusB;
}
else
{
dist=0.0f;
hkVector4 edge;edge.setSub4(capsB[1],capsB[0]);
hkVector4Util_S::calculatePerpendicularVector(edge,cpoint.getSeparatingNormal());
}
cpoint.getSeparatingNormal().normalize3();
cpoint.getPosition().setAddMul4(posA,cpoint.getNormal(),capsuleB->getRadius()-dist);
cpoint.setDistance(dist-radiusSum);
return ST_CP_HIT;}
// @fnv 0x00d3ebe0
void __cdecl hkpSphereCapsuleAgent::FUN_00d3ebe0(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "SphereCapsule";h->setTime();mStream.setEnd((char*)(h+1));}};
ContactPointPair event(bodyA,bodyB);
if(getClosestPointInl(bodyA,bodyB,input,event.m_kPoint))
{
collector.AddCdPoint(event);
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}

// Moved from hkpspherecapsuleagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"

#include <math.h>
extern "C" void _ReadWriteBarrier();
struct Vec4f { float x, y, z, w; __forceinline __m128& quad() { return *(__m128*)this; } __forceinline float& at(int i) { return (&x)[i]; } };
struct MatF { Vec4f v[4]; };
struct InnerP { float unk00, unk04, unk08, unk0c, f10; float unk14, unk18, unk1c; Vec4f endpoints[2]; };
struct Arg0S { InnerP* p; int unk04; Vec4f* q; };
struct Arg1S { InnerP* p; int unk04; MatF* mat; };
struct Arg2S { float unk00, unk04, f8; };
struct OutS { Vec4f pos; Vec4f n; };
static __forceinline bool compareValue(float a,float b) { return b>=a; }
static __forceinline void perpendicular(Vec4f& dst, Vec4f& d) {
        int low=0, side=1; volatile int third=2; int pick;
        float best=fabsf(d.x), ay=fabsf(d.y), az=fabsf(d.z);
        if(ay<best) {side=0;low=1;best=ay;}
        if(az<best) pick=low; else pick=third;
        dst.quad()=_mm_setzero_ps();
        dst.at(side)=d.at(pick);
        dst.at(pick)=-d.at(side);
}
static __forceinline float rootVal(float x){return sqrtf(x);}
static __forceinline void difference(Vec4f& dst, const Vec4f& a, const Vec4f& b){ dst.quad()=_mm_sub_ps(*(__m128*)&a,*(__m128*)&b); }
// @fnv 0x00d3e530
int __cdecl FUN_00d3e530(Arg0S* a0, Arg1S* a1, Arg2S* a2, OutS* out) {
    
    Vec4f* qp = a0->q + 3;
    InnerP* bp = a1->p;
    InnerP* ap = a0->p;
    Vec4f vc0 = a1->mat->v[0];
    Vec4f vc1 = a1->mat->v[1];
    Vec4f vc2 = a1->mat->v[2];
    Vec4f vc3 = a1->mat->v[3];
    __m128 c0 = *(__m128*)&vc0;
    __m128 c1 = *(__m128*)&vc1;
    __m128 c2 = *(__m128*)&vc2;
    __m128 c3 = *(__m128*)&vc3;
    Vec4f* inp = bp->endpoints;
    Vec4f t[2];
    for (int i = 1; i >= 0; i--) {
        __m128 v = _mm_load_ps((float*)&inp[i]);
        __m128 r = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1),
                                         _mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0)),
                              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2), c3));
        _mm_store_ps((float*)&t[i], r);
    }
    Vec4f res;
    ::FUN_00d230e0((*(const ::hkVector4D230 *)(qp)), (*(const ::hkVector4D230 *)(&t[0])), (*(const ::hkVector4D230 *)(&t[1])), (*(::hkVector4D230 *)(&res)));
    Vec4f diff;
    _mm_store_ps((float*)&diff, _mm_sub_ps(_mm_load_ps((float*)qp), _mm_load_ps((float*)&res)));
    float sum1 = ap->f10 + bp->f10;
    float S = a2->f8 + sum1;
    __m128 sq = _mm_mul_ps(_mm_load_ps((float*)&diff), _mm_load_ps((float*)&diff));
    __m128 s1 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    __m128 s2 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), s1);
    float lenSq;
    _mm_store_ss(&lenSq, s2);
if (compareValue(S*S,lenSq)) return 0;
    float D;
    if (lenSq > 0.0f) {
        D = sqrtf(lenSq);
        out->n.quad() = *(__m128*)&diff;
    } else {
        D = 0.0f;
        Vec4f d;
        difference(d,t[1],t[0]);
        perpendicular(out->n,d);
    }
    __m128 n = out->n.quad();
    __m128 nsq = _mm_mul_ps(n, n);
    __m128 nsum = _mm_add_ss(_mm_shuffle_ps(nsq, nsq, 0xaa), _mm_add_ss(_mm_shuffle_ps(nsq, nsq, 0x55), nsq));
    __m128 r = _mm_rsqrt_ss(nsum);
    __m128 factor = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(::fnv_00c88020::DAT_01016248), r),
                               _mm_sub_ss(_mm_set_ss(::DAT_01017718), _mm_mul_ss(_mm_mul_ss(nsum, r), r)));
    factor = _mm_andnot_ps(_mm_cmpeq_ss(nsum, _mm_set_ss(::DAT_01011d78)), factor);
    __m128 fn = _mm_mul_ps(_mm_shuffle_ps(factor, factor, 0), n);
    out->n.quad() = fn;
    _ReadWriteBarrier();
    float t1 = bp->f10 - D;
    __m128 pos = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&t1), _mm_load_ss(&t1), 0), _mm_load_ps((float*)&out->n)), _mm_load_ps((float*)qp));
    _mm_store_ps((float*)&out->pos,pos);
    out->n.w = D - sum1;
    return 1;
}
namespace fnv_00d3f080 {
typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef uintptr_t hkUlong;
enum hkResult
{
HK_SUCCESS=0,
HK_FAILURE=1
};
typedef size_t hk_size_t;
typedef hkReal hkTime;class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
class hkClass;
typedef int hkBool32;
class hkBool
{
public:
typedef char CompileTimeTrueType;inline hkBool(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};template<typename ENUM,typename STORAGE>
class hkEnum
{
public:
hkEnum()
{
}
hkEnum(ENUM e)
{
m_kStorage=static_cast<STORAGE>(e);
}
private:
STORAGE m_kStorage;};
template<typename TYPE>
class ValueWrapper
{
public:
__forceinline ValueWrapper(){}
__forceinline void operator=(TYPE e)
{
m_kStorage=e;
}
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline operator TYPE()const
{
return val();
}
private:
TYPE m_kStorage;};
template<typename T>
class hkThreadLocalData
{
public:
hkThreadLocalData()
{
m_slotID=TlsAlloc();
}
__forceinline T getData()const
{
return(T)(hkUlong)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};
namespace vc_attributes
{
enum YesNoMaybe
{
No=0x0fff0001,
Maybe=0x0fff0010,
Yes=0x0fff0100
};
enum AccessType
{
NoAccess=0,
Read=1,
Write=2,
ReadWrite=3
};
[repeatable]
[source_annotation_attribute(Parameter)]
struct PreAttribute
{
PreAttribute();
unsigned int Deref;
YesNoMaybe Valid;
YesNoMaybe Null;
YesNoMaybe Tainted;
AccessType Access;
size_t ValidElementsConst;
size_t ValidBytesConst;
const wchar_t*ValidElements;
const wchar_t*ValidBytes;
const wchar_t*ValidElementsLength;
const wchar_t*ValidBytesLength;
size_t WritableElementsConst;
size_t WritableBytesConst;
const wchar_t*WritableElements;
const wchar_t*WritableBytes;
const wchar_t*WritableElementsLength;
const wchar_t*WritableBytesLength;
size_t ElementSizeConst;
const wchar_t*ElementSize;
YesNoMaybe NullTerminated;
const wchar_t*Condition;
};};
const vc_attributes::YesNoMaybe SA_Yes=vc_attributes::Yes;
const vc_attributes::YesNoMaybe SA_No=vc_attributes::No;
const vc_attributes::AccessType SA_Read=vc_attributes::Read;
typedef vc_attributes::PreAttribute SA_Pre;class hkMemoryAllocator
{
public:
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();protected:
ValueWrapper<void*>m_next;};
class NineIntegerRecord
{
public:
typedef hkMemoryAllocator Allocator;
static NineIntegerRecord&__cdecl GetMonitorStream();inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
StringPointerTriple m_aiEntries;
Allocator*m_pTemp;
Allocator*m_pStreamAllocator;};
class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject(){}
};
class hkStatisticsCollector;
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
virtual ~hkReferencedObject(){}
virtual const hkClass*GetClassType()const;
virtual void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject(class FinishingFlag flag){}
};
typedef __m128 hkQuadReal;
class hkVector4;
typedef const hkVector4&hkVector4Parameter;
class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
VectorComponentValue(hkReal x)
{
m_vValue=_mm_load_ss(&x);
}
operator hkReal()const
{
hkReal s;
_mm_store_ss(&s,m_vValue);
return s;
}
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
__forceinline const hkQuadReal&getQuad()const
{
return m_vValue;
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;namespace MathUtilities
{
inline hkReal __cdecl sqrt(hkReal r){return sqrtf(r);}
inline hkReal __cdecl fabs(hkReal r){return fabsf(r);}
}
class hkTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
__forceinline void setZero4();
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVector4&b);
__forceinline VectorComponentValue dot3(const hkVector4&a)const;
__forceinline VectorComponentValue lengthSquared3()const;
__forceinline VectorComponentValue lengthInverse3()const;
__forceinline void normalize3();
__forceinline hkReal&operator()(int i);
__forceinline const hkReal&operator()(int i)const;
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkVector4&getColumn(int i);
__forceinline const hkVector4&getColumn(int i)const;
protected:
hkVector4 m_kColumn0;
hkVector4 m_kColumn1;
hkVector4 m_kColumn2;};class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkTransform(const hkTransform&r);
__forceinline const hkVector4&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4::setZero4()
{
m_vComponents=_mm_setzero_ps();
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
inline void hkVector4::_setTransformedPos(const hkTransform&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
inline VectorComponentValue hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline VectorComponentValue hkVector4::lengthSquared3()const
{
return this->dot3(*this);
}
inline VectorComponentValue hkVector4::lengthInverse3()const
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=this->dot3(*this).getQuad();
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
return _mm_andnot_ps(len2EqualsZero,refined);}
inline void hkVector4::normalize3()
{
hkQuadReal lenInv=lengthInverse3().broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
}
inline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline hkVector4&hkMatrix3::getColumn(int x)
{
return(&m_kColumn0)[x];
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVector4&hkTransform::getTranslation()const
{
return m_vTranslation;
}
const hkRotation&hkTransform::getRotation()const
{
return m_rotation;
}
hkTransform::hkTransform(const hkTransform&t)
{
const hkVector4 r0=t.m_rotation.getColumn(0);
const hkVector4 r1=t.m_rotation.getColumn(1);
const hkVector4 r2=t.m_rotation.getColumn(2);
const hkVector4 r3=t.m_rotation.getColumn(3);
m_rotation.getColumn(0)=r0;
m_rotation.getColumn(1)=r1;
m_rotation.getColumn(2)=r2;
m_rotation.getColumn(3)=r3;}
class StringCursor
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
{
extern hkThreadLocalData<StringCursor*>g_pMonitorStream;
return*g_pMonitorStream.getData();
}
public:
__forceinline char*__cdecl GetStreamStart(){return m_kRayStart.val();}
__forceinline char*__cdecl GetStreamEnd(){return m_kRayEnd.val();}
__forceinline char*__cdecl getCapacityMinus16(){return m_pCurrentCommand.val();}
__forceinline hkBool __cdecl memoryAvailable()
{
return GetStreamEnd()<getCapacityMinus16();
}
__forceinline void __cdecl setEnd(char*ptr){m_kRayEnd=ptr;}
public:
static void __cdecl init();
public:
ValueWrapper<char*>m_kRayStart;
ValueWrapper<char*>m_kRayEnd;
ValueWrapper<char*>m_pRayCursor;
ValueWrapper<char*>m_pCurrentCommand;
hkBool m_bFlag;
public:
struct Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32 m_uiStartTicks;
hkUint32 m_uiEndTicks;
__forceinline void setTime();
};};
void StringCursor::CommandTimingEntry::setTime()
{
hkUint32 ticks;
ticks = static_cast<unsigned int>(__rdtsc());
m_uiStartTicks=ticks;
}
class hkAabb
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVector4 m_kMinimumCorner;};typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkVector4&getPosition();
inline const hkVector4&getNormal()const;
inline hkVector4&getSeparatingNormal();
inline void setDistance(hkReal d);
protected:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVector4 m_vContactPosition;
hkVector4 m_vSeparatingNormal;};inline const hkVector4&hkContactPoint::getNormal()const
{
return m_vSeparatingNormal;
}
inline hkVector4&hkContactPoint::getPosition()
{
return m_vContactPosition;
}
inline hkVector4&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}
inline void hkContactPoint::setDistance(hkReal d)
{
m_vSeparatingNormal(3)=d;
}
class Vector4WithInt24W:public hkVector4
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
enum CollisionShapeType
{
HK_SHAPE_INVALID=0,
HK_SHAPE_SPHERE,
HK_FIRST_SHAPE_TYPE=HK_SHAPE_SPHERE,
HK_SHAPE_CYLINDER,
HK_SHAPE_TRIANGLE,
HK_SHAPE_BOX,
HK_SHAPE_CAPSULE,
HK_SHAPE_CONVEX_VERTICES,
HK_SHAPE_COLLECTION,
HK_SHAPE_BV_TREE,
HK_SHAPE_LIST,
HK_SHAPE_MOPP,
HK_SHAPE_CONVEX_TRANSLATE,
HK_SHAPE_CONVEX_TRANSFORM,
HK_SHAPE_SAMPLED_HEIGHT_FIELD,
HK_SHAPE_EXTENDED_MESH,
HK_SHAPE_TRANSFORM,
HK_SHAPE_COMPRESSED_MESH,
HK_SHAPE_MAX_ID_SPU=HK_SHAPE_COMPRESSED_MESH+1,
HK_SHAPE_CONVEX,
HK_SHAPE_PACKED_CONVEX_VERTICES,
HK_SHAPE_MOPP_EMBEDDED,
HK_SHAPE_CONVEX_PIECE,
HK_SHAPE_MULTI_SPHERE,
HK_SHAPE_CONVEX_LIST,
HK_SHAPE_TRIANGLE_COLLECTION,
HK_SHAPE_MULTI_RAY,
HK_SHAPE_HEIGHT_FIELD,
HK_SHAPE_SPHERE_REP,
HK_SHAPE_BV,
HK_SHAPE_PLANE,
HK_SHAPE_PHANTOM_CALLBACK,
HK_SHAPE_USER0,
HK_SHAPE_USER1,
HK_SHAPE_USER2,
HK_SHAPE_MAX_ID,
HK_SHAPE_ALL=-1
};
class hkpCollisionDispatcher;
typedef hkUint32 hkpShapeKey;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
protected:
virtual void CalculateAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const=0;
public:
static void __cdecl resetShapeFunctions();
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<CollisionShapeType,hkUint32>m_type;
public:
hkpShape(class FinishingFlag flag):hkReferencedObject(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;};
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
struct GskAgentInput;
struct WorldOperationEntry;
class hkpConstraintOwner;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;};
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;
class ConvexFeaturePairCache;class hkpContactMgr:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
enum Type
{
TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR,
TYPE_REPORT_CONTACT_MGR,
TYPE_CONVEX_LIST_CONTACT_MGR,
TYPE_NULL_CONTACT_MGR,
TYPE_USER_CONTACT_MGR,
TYPE_MAX
};__forceinline hkContactPointId addContactPoint(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp);
__forceinline void removeContactPoint(hkContactPointId cpId,hkpConstraintOwner&constraintOwner);
public:
virtual hkContactPointId CreateContactPoint(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp)=0;
virtual hkResult ReserveContactPoints(int numPoints)=0;
virtual void removeContactPointImpl(hkContactPointId cpId,hkpConstraintOwner&constraintOwner)=0;public:
Type m_type;};
hkContactPointId hkpContactMgr::addContactPoint(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp)
{
return CreateContactPoint(a,b,input,output,contactCache,cp);
}
void hkpContactMgr::removeContactPoint(hkContactPointId cpId,hkpConstraintOwner&constraintOwner)
{
removeContactPointImpl(cpId,constraintOwner);
}
struct ContactPointWithId
{
hkContactPoint m_kPoint;
ValueWrapper<hkUint32>m_usContactPointId;};
class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}__forceinline void __cdecl operator delete(void*p){hkReferencedObject*b=static_cast<hkReferencedObject*>(p);;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,b->m_usMemSizeAndFlags);}__forceinline void*__cdecl operator new(std::size_t,void*p){return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector)=0;
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector)=0;
virtual void linearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&castCollector,hkpCdPointCollector*startCollector)=0;
public:
virtual void FUN_00d3f080(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&result)=0;
virtual void cleanup(hkpConstraintOwner&info)=0;
virtual void ProcessContactPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpConstraintOwner&constraintOwner){}
virtual void RemovePoint(const CollisionAgentContext&input);
virtual void WarpTime(hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
virtual void removePoint(hkContactPointId idToRemove);
virtual void CommitPotentialContactPoint(hkContactPointId iContactPointId);
virtual void MarkContactPointAsZombie(hkContactPointId idTobecomeZombie);
protected:
inline virtual ~hkpCollisionAgent();
inline hkpCollisionAgent(hkpContactMgr*contactMgr);
protected:
hkpContactMgr*m_pContactManager;
public:
inline hkpContactMgr*getContactMgr();
};class hkStepInfo
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}public:
__declspec(align(16))ValueWrapper<hkTime>m_uiStartTime;};
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};enum{HK_MAX_CONTACT_POINT=256};
struct FourByteState;
struct CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
ValueWrapper<ContactPointWithId*>m_pAlignedPairData;
ValueWrapper<hkpConstraintOwner*>m_pConstraintOwner;};
struct WorldOperationEntry:public CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}inline ContactPointWithId*reserveContactPoints(int numberOfPoints=1)
{
return m_pAlignedPairData;
}
inline void commitContactPoints(int numberOfPoints=1)
{
m_pAlignedPairData=m_pAlignedPairData+numberOfPoints;
;
}
inline void abortContactPoints(int numberOfPoints=1)
{
}
public:
struct ContactPointAgentEntry
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(WorldOperationEntry::ContactPointAgentEntry));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
ContactPointWithId*m_vContactPoint;
FourByteState*m_pAgentEntry;
void*m_pUserData;
};
struct ContactPointBuffer
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(WorldOperationEntry::ContactPointBuffer));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
void reset()
{
m_pFirstFreeContactPoint=&m_akContactRecords[0];
m_ppFirstFreeContactPointer=&m_apContactPointPointers[0];
}
ContactPointAgentEntry*m_pFirstFreeContactPoint;
ContactPointWithId**m_ppFirstFreeContactPointer;
ContactPointWithId*m_apContactPointPointers[HK_MAX_CONTACT_POINT];
ContactPointAgentEntry m_akContactRecords[HK_MAX_CONTACT_POINT];
};
public:
ValueWrapper<ContactPointBuffer*>m_akContactRecords;};class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}virtual void linearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&collector,hkpCdPointCollector*startCollector);};
class hkpSphereCapsuleAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual inline void FUN_00d3f080(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&pointDetails);
static void __cdecl m_pVirtualFunction2(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void cleanup(hkpConstraintOwner&info);
protected:
__forceinline hkpSphereCapsuleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createSphereCapsuleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createCapsuleSphereAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
public:
enum ClosestPointResult
{
ST_CP_MISS,
ST_CP_HIT,
};
private:
static __forceinline ClosestPointResult getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&cpoint);
protected:
static ClosestPointResult __cdecl ComputeClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&cpoint);
hkContactPointId m_usContactPointId;
};
class hkpSphereRepShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual int GetNumCollisionSpheres()const=0;
public:
hkpSphereRepShape(CollisionShapeType type):hkpShape(type){}
hkpSphereRepShape(FinishingFlag flag):hkpShape(flag){m_type=HK_SHAPE_SPHERE_REP;}
};
class hkpConvexShape:public hkpSphereRepShape
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkReal getRadius()const;
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
protected:
inline hkpConvexShape(CollisionShapeType type,hkReal radius);
hkReal m_fSphereRadius;
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};inline hkReal hkpConvexShape::getRadius()const
{
return m_fSphereRadius;
}
class hkpCapsuleShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkVector4*GetIndexedVertices()const;
public:
hkpCapsuleShape(FinishingFlag flag):hkpConvexShape(flag){m_type=HK_SHAPE_CAPSULE;}
protected:
hkVector4 m_kVertexA;};const hkVector4*hkpCapsuleShape::GetIndexedVertices()const
{
return&m_kVertexA;
}
class hkpSphereShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
public:
hkpSphereShape(FinishingFlag flag):hkpConvexShape(flag){m_type=HK_SHAPE_SPHERE;}
};
namespace hkVector4Util_S
{
__forceinline void __cdecl calculatePerpendicularVector(const hkVector4&vectorIn,hkVector4&biVectorOut);
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut);}
inline void __cdecl hkVector4Util_S::calculatePerpendicularVector(const hkVector4&vectorIn,hkVector4&biVectorOut)
{
int min=0;
int ok1=1;
int ok2=2;
hkReal a0=MathUtilities::fabs(vectorIn(0));
hkReal a1=MathUtilities::fabs(vectorIn(1));
hkReal a2=MathUtilities::fabs(vectorIn(2));
if(a1<a0)
{
ok1=0;
min=1;
a0=a1;
}
if(a2<a0)
{
ok2=min;
min=2;
}
biVectorOut.setZero4();
biVectorOut(ok1)=vectorIn(ok2);
biVectorOut(ok2)=-vectorIn(ok1);}
inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
vectorsOut[i]._setTransformedPos(unaliased,vectorsIn[i]);
}while(--i>=0);}
class SegmentSegmentClosestPoint
{
public:
enum
{
CLSLS_POINTA_START=1,
CLSLS_POINTA_END=2,
CLSLS_POINTB_START=4,
CLSLS_POINTB_END=8
};
struct Vector4Wrapper
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(SegmentSegmentClosestPoint::Vector4Wrapper));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kClosestPoint;
};
};
__forceinline hkpSphereCapsuleAgent::ClosestPointResult hkpSphereCapsuleAgent::getClosestPointInl(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&cpoint)
{
const hkpSphereShape*sphereA=static_cast<const hkpSphereShape*>(bodyA.getShape());
const hkpCapsuleShape*capsuleB=static_cast<const hkpCapsuleShape*>(bodyB.getShape());
const hkVector4&posA=bodyA.getTransform().getTranslation();
hkVector4 capsB[2];hkVector4Util_S::TransformPointArray(bodyB.getTransform(),capsuleB->GetIndexedVertices(),2,capsB);
SegmentSegmentClosestPoint::Vector4Wrapper result;::FUN_00d230e0((const ::hkVector4D230 &)(posA),(const ::hkVector4D230 &)(capsB[0]),(const ::hkVector4D230 &)(capsB[1]),(::hkVector4D230 &)(result));
hkVector4 aMinusB;aMinusB.setSub4(posA,result.m_kClosestPoint);
const hkReal radiusSum=sphereA->getRadius()+capsuleB->getRadius();
const hkReal refDist=radiusSum+input.getTolerance();
hkReal distSquared=aMinusB.lengthSquared3();
if(distSquared>=refDist*refDist)
{
return ST_CP_MISS;
}
hkReal dist;
if(distSquared>0.0f)
{
dist=MathUtilities::sqrt(distSquared);
cpoint.getSeparatingNormal()=aMinusB;
}
else
{
dist=0.0f;
hkVector4 edge;edge.setSub4(capsB[1],capsB[0]);
hkVector4Util_S::calculatePerpendicularVector(edge,cpoint.getSeparatingNormal());
}
cpoint.getSeparatingNormal().normalize3();
cpoint.getPosition().setAddMul4(posA,cpoint.getNormal(),capsuleB->getRadius()-dist);
cpoint.setDistance(dist-radiusSum);
return ST_CP_HIT;}
// @fnv 0x00d3f080
void hkpSphereCapsuleAgent::FUN_00d3f080(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result)
{
;
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "SphereCapsule";h->setTime();mStream.setEnd((char*)(h+1));}};
ContactPointWithId*point=result.reserveContactPoints(1);
if(getClosestPointInl(bodyA,bodyB,input,point->m_kPoint))
{
if(m_usContactPointId==(0xffff))
{
m_usContactPointId=m_pContactManager->addContactPoint(bodyA,bodyB,input,result,0,point->m_kPoint);
}
if(m_usContactPointId !=(0xffff))
{
point->m_usContactPointId=m_usContactPointId;
result.commitContactPoints(1);
}
else
{
result.abortContactPoints(1);
}
}
else
{
result.abortContactPoints(1);
if(m_usContactPointId !=(0xffff))
{
m_pContactManager->removeContactPoint(m_usContactPointId,*result.m_pConstraintOwner.val());
m_usContactPointId=(0xffff);
}
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
struct hkEmitHelper:public hkpSphereCapsuleAgent
{
hkEmitHelper(const hkpCdBody&b,const CollisionAgentContext&i):hkpSphereCapsuleAgent(b,b,i,0){}
};
void hkEmitVtable(const hkpCdBody&b,const CollisionAgentContext&i){hkEmitHelper h(b,i);}
}  // namespace fnv_00d3f080

// Moved from hkpspherecapsuleagent_gs_nogs_variant_rtm_variant.cpp (VEGAS-15).
#include <cmath>


namespace fnv_00d3e850 {
static inline float hkMathSqrt(float r)
{
    volatile float v = (float)sqrt(r);
    return v;
}

static inline float hkMathFabs(float r, volatile float& v)
{
    v = (float)fabs(r);
    return v;
}

struct StringCursor
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

struct hkMonitorTimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct hkVector4
{
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return ((const float*)&m_vComponents)[i];
    }
    __m128 m_vComponents;
};

struct hkMatrix3
{
    inline void operator=(const hkMatrix3& m)
    {
        m_kColumn0 = m.m_kColumn0;
        m_kColumn1 = m.m_kColumn1;
        m_kColumn2 = m.m_kColumn2;
    }
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

struct hkRotation : hkMatrix3
{
    inline void operator=(const hkRotation& m)
    {
        hkMatrix3::operator=(m);
    }
};

struct hkTransform
{
    inline hkTransform(const hkTransform& t)
    {
        m_rotation.m_kColumn0 = t.m_rotation.m_kColumn0;
        m_rotation.m_kColumn1 = t.m_rotation.m_kColumn1;
        m_rotation.m_kColumn2 = t.m_rotation.m_kColumn2;
        m_vTranslation = t.m_vTranslation;
    }
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};

struct hkpShape
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
};

struct hkpConvexShape : hkpShape
{
    float m_fSphereRadius;
};

struct hkpSphereShape : hkpConvexShape
{
};

struct hkpCapsuleShape : hkpConvexShape
{
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kVertexA;
    hkVector4 m_kVertexB;
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const hkTransform* m_pMotionState;
    const hkpCdBody* m_parent;
};

struct CollisionAgentContext
{
    void* m_pCollisionDispatcher;
    void* m_iFilter;
    float m_fScalar;
};

struct hkContactPoint
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
};

struct ContactPointPair
{
    ContactPointPair(const hkpCdBody& a, const hkpCdBody& b) : m_pBodyA(a), m_pBodyB(b)
    {}
    hkContactPoint m_kPoint;
    const hkpCdBody& m_pBodyA;
    const hkpCdBody& m_pBodyB;
};

struct hkpCdPointCollector
{
    virtual void unk00();
    virtual void AddCdPoint(const ContactPointPair& event);
};


struct Vector4Wrapper
{
    hkVector4 m_kClosestPoint;
};


static inline void timerCommand(const char* name, volatile unsigned int& ticks)
{
    StringCursor* s = (StringCursor*)TlsGetValue(::DAT_0126835c);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        hkMonitorTimerCommand* h = (hkMonitorTimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_uiStartTicks = ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

// @fnv 0x00d3e850
void FUN_00d3e850(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input,
                            hkpCdPointCollector& collector)
{
    union
    {
        unsigned int startTicks;
        float distanceSquared;
        float minimumAbs;
    } scal0;
    struct
    {
        union
        {
            float radiusSum;
            unsigned int endTicks;
        };
        float absZ;
    } scal2;
    float absY;
    timerCommand("TtSphereCapsule", scal0.startTicks);

    const hkpSphereShape* sphereA = static_cast<const hkpSphereShape*>(bodyA.m_pCollisionShape);
    const hkpCapsuleShape* capsuleB = static_cast<const hkpCapsuleShape*>(bodyB.m_pCollisionShape);
    const hkVector4& posA = bodyA.m_pMotionState->m_vTranslation;
    union
    {
        hkVector4 column0;
        hkVector4 edge;
    } first;
    union
    {
        hkVector4 column2;
        hkVector4 separation;
    } second;
    union
    {
        hkVector4 translation;
        Vector4Wrapper result;
    } third;
    union
    {
        hkVector4 column1;
        hkVector4 endpoints[2];
    } fourth;
    ContactPointPair event(bodyA, bodyB);
    const hkTransform& tB = *bodyB.m_pMotionState;
    first.column0 = tB.m_rotation.m_kColumn0;
    reinterpret_cast<int*>(&fourth.column1.m_vComponents)[0] = reinterpret_cast<const int*>(&tB.m_rotation.m_kColumn1.m_vComponents)[0];
    reinterpret_cast<int*>(&fourth.column1.m_vComponents)[1] = reinterpret_cast<const int*>(&tB.m_rotation.m_kColumn1.m_vComponents)[1];
    reinterpret_cast<int*>(&fourth.column1.m_vComponents)[2] = reinterpret_cast<const int*>(&tB.m_rotation.m_kColumn1.m_vComponents)[2];
    __m128 c0 = _mm_load_ps(reinterpret_cast<float*>(&first.column0.m_vComponents));
    reinterpret_cast<int*>(&fourth.column1.m_vComponents)[3] = reinterpret_cast<const int*>(&tB.m_rotation.m_kColumn1.m_vComponents)[3];
    second.column2 = tB.m_rotation.m_kColumn2;
    __m128 c1 = _mm_load_ps(reinterpret_cast<float*>(&fourth.column1.m_vComponents));
    reinterpret_cast<int*>(&third.translation.m_vComponents)[0] = reinterpret_cast<const int*>(&tB.m_vTranslation.m_vComponents)[0];
    __m128 c2 = _mm_load_ps(reinterpret_cast<float*>(&second.column2.m_vComponents));
    reinterpret_cast<int*>(&third.translation.m_vComponents)[1] = reinterpret_cast<const int*>(&tB.m_vTranslation.m_vComponents)[1];
    reinterpret_cast<int*>(&third.translation.m_vComponents)[2] = reinterpret_cast<const int*>(&tB.m_vTranslation.m_vComponents)[2];
    reinterpret_cast<int*>(&third.translation.m_vComponents)[3] = reinterpret_cast<const int*>(&tB.m_vTranslation.m_vComponents)[3];
    __m128 tr = _mm_load_ps(reinterpret_cast<float*>(&third.translation.m_vComponents));
    const hkVector4* in = &capsuleB->m_kVertexA;
    int i = 1;
    do
    {
        __m128 v = in[i].m_vComponents;
        __m128 xb = _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0));
        __m128 yb = _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1));
        __m128 zb = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2));
        __m128 r0 = _mm_mul_ps(c0, xb);
        __m128 r1 = _mm_mul_ps(c1, yb);
        __m128 r2 = _mm_mul_ps(c2, zb);
        fourth.endpoints[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, tr));
    } while (--i >= 0);

    ::FUN_00d230e0((const ::hkVector4D230 &)(posA), (const ::hkVector4D230 &)(fourth.endpoints[0]), (const ::hkVector4D230 &)(fourth.endpoints[1]), (::hkVector4D230 &)(third.result));

    scal2.radiusSum = sphereA->m_fSphereRadius + capsuleB->m_fSphereRadius;
    float refDist = scal2.radiusSum + input.m_fScalar;

    second.separation.m_vComponents = _mm_sub_ps(posA.m_vComponents, third.result.m_kClosestPoint.m_vComponents);
    {
        __m128 len = _mm_mul_ps(second.separation.m_vComponents, second.separation.m_vComponents);
        __m128 s0 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(1, 1, 1, 1));
        __m128 s1 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(2, 2, 2, 2));
        _mm_store_ss(&scal0.distanceSquared, _mm_add_ss(s1, _mm_add_ss(s0, len)));
    }

    float refDist2 = refDist * refDist;
    if (!(scal0.distanceSquared >= refDist2))
    {
        float distance;
        hkVector4& normal = event.m_kPoint.m_vSeparatingNormal;
        if (scal0.distanceSquared > 0.0f)
        {
            distance = hkMathSqrt(scal0.distanceSquared);
            normal.m_vComponents = second.separation.m_vComponents;
        }
        else
        {
            distance = 0.0f;
            first.edge.m_vComponents = _mm_sub_ps(fourth.endpoints[1].m_vComponents, fourth.endpoints[0].m_vComponents);

            int min = 0;
            int ok1 = 1;
            int ok2 = 2;
            scal0.minimumAbs = hkMathFabs(first.edge(0), scal0.minimumAbs);
            absY = hkMathFabs(first.edge(1), scal2.absZ);
            scal2.absZ = hkMathFabs(first.edge(2), scal2.absZ);
            if (absY < scal0.minimumAbs)
            {
                ok1 = 0;
                min = 1;
                scal0.minimumAbs = absY;
            }
            if (scal2.absZ < scal0.minimumAbs)
            {
                ok2 = min;
                min = 2;
            }
            normal.m_vComponents = _mm_setzero_ps();
            normal(ok1) = first.edge(ok2);
            normal(ok2) = -first.edge(ok1);
        }

        {
            __m128 len = _mm_mul_ps(normal.m_vComponents, normal.m_vComponents);
            __m128 s0 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(1, 1, 1, 1));
            __m128 s1 = _mm_shuffle_ps(len, len, _MM_SHUFFLE(2, 2, 2, 2));
            __m128 len2 = _mm_add_ss(s1, _mm_add_ss(s0, len));
            __m128 e = _mm_rsqrt_ss(len2);
            __m128 eq = _mm_cmpeq_ss(len2, _mm_set_ss(0.0f));
            __m128 he = _mm_mul_ss(_mm_set_ss(0.5f), e);
            __m128 ee = _mm_mul_ss(_mm_mul_ss(len2, e), e);
            __m128 r = _mm_mul_ss(he, _mm_sub_ss(_mm_set_ss(3.0f), ee));
            r = _mm_andnot_ps(eq, r);
            hkVector4 broadcast;
            broadcast.m_vComponents = r;
            normal.m_vComponents =
                _mm_mul_ps(_mm_shuffle_ps(broadcast.m_vComponents, broadcast.m_vComponents, 0), normal.m_vComponents);
        }

        absY = capsuleB->m_fSphereRadius - distance;
        event.m_kPoint.m_vContactPosition.m_vComponents =
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&absY), _mm_load_ss(&absY), 0), normal.m_vComponents),
                       posA.m_vComponents);
        normal(3) = distance - scal2.radiusSum;
        collector.AddCdPoint(event);
    }

    timerCommand("Et", scal2.endTicks);
}
}  // namespace fnv_00d3e850
#include "generated/data/havok/physics/collide/agent/convexagent/spherecapsule/hkpspherecapsuleagent.inc"
