
// src/havok/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include <cstddef>
#include <xmmintrin.h>
#include <intrin.h>
#include <windows.h>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/symbols_00d3b000.h"
#include "fnv/symbols_00daf000.h"
#include "fnv/symbols_01268000.h"
struct Callback
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void invoke(unsigned short, int);
};

struct FUN_00d3b3d0_Class
{
    virtual void release(int);
    int unk04;
    Callback* unk08;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    void InvokeCallbacksAndRelease(int);
};

// Calls invoke on unk08 for each of the three IDs at unk0C unless it is 0xffff, then releases the object.
// @fnv 0x00d3b3d0
void FUN_00d3b3d0_Class::InvokeCallbacksAndRelease(int value)
{
    unsigned short* id = &unk0C;
    int iRemaining = 3;
    do
    {
        unsigned short usId = *id;
        if (usId != 0xffff)
            unk08->invoke(usId, value);
        ++id;
        --iRemaining;
    } while (iRemaining != 0);

    if (this != 0)
        release(1);
}

typedef void (__cdecl* HandlerFn)();

void __cdecl FUN_00d3bd80();

struct HandlerSet {
    HandlerFn m_pfnFirst;
    HandlerFn m_pfnSecond;
    HandlerFn m_pfnThird;
    HandlerFn m_pfnFourth;
    char m_cFlagA;
    char m_cFlagB;
};

struct Registry {
};

// Fills a HandlerSet with four handler functions and zeroed flags, then registers it with the registry using 5 and 5.
// @fnv 0x00d3c010
void __cdecl RegisterHandlers(Registry* apRegistry)
{
    HandlerSet kHandlers;
    kHandlers.m_cFlagA = 0;
    kHandlers.m_cFlagB = 0;
    kHandlers.m_pfnFirst = ((void (&)())::fnv_00d3b380::FUN_00d3b380);
    kHandlers.m_pfnSecond = ((void (&)())::FUN_00d3b420);
    kHandlers.m_pfnThird = FUN_00d3bd80;
    kHandlers.m_pfnFourth = ((void (&)())::FUN_00daf8e0);

    reinterpret_cast<::FUN_00cfbbe0_cls *>((apRegistry))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::HandlerSet *)(&kHandlers), 5, 5);
}


struct D3B6D0Agent {
    virtual void ForwardToHandler(const void* a, const void* b, const void* c, void* d);
};

// @fnv 0x00d3b6d0
void D3B6D0Agent::ForwardToHandler(const void* apArg1, const void* apArg2, const void* apArg3, void* apArg4)
{
    ::FUN_00d3b420((::Capsule *)(apArg1), (::Capsule *)(apArg2), (void *)(apArg3), (::HitHandler *)(apArg4));
}



struct Vec4 { float x, y, z, w; };
union MatrixRow { Vec4 scalar; __m128 simd; };
struct Mat44 { Vec4 row0, row1, row2, row3; };
struct JointTransform {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float blend;
    float unk14;
    float unk18;
    float unk1C;
    float frameVectors[8];
};
struct TransformInput {
    JointTransform* bone;
    int unk04;
    const Mat44* matrix;
};
struct BlendParameter {
    float unk00;
    float unk04;
    float fraction;
};

void __cdecl FUN_00cd6260(const void* a, float fraction, const void* b, float weightA, float weightB, int flags);

// Transforms each bone's two frameVectors by its matrix, then calls FUN_00cd6260 with the results, each bone's blend value and the parameter's fraction.
// @fnv 0x00d3b8e0
static __declspec(noinline) void __cdecl FUN_00d3b8e0(TransformInput* first, TransformInput* second, const BlendParameter* parameter, int flags)
{
    JointTransform* firstBone = first->bone;
    JointTransform* secondBone = second->bone;
    __declspec(align(16)) __m128 firstResult[2];
    MatrixRow a0;
    a0.scalar = first->matrix->row0;
    MatrixRow a1;
    a1.scalar = first->matrix->row1;
    MatrixRow a2;
    a2.scalar = first->matrix->row2;
    MatrixRow a3;
    a3.scalar = first->matrix->row3;

    for (int index = 1; index >= 0; --index) {
        __m128 v = _mm_load_ps(firstBone->frameVectors + index * 4);
        __m128 xy = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), a1.simd),
                                _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), a0.simd));
        __m128 zw = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), a2.simd), a3.simd);
        firstResult[index] = _mm_add_ps(xy, zw);
    }

    __declspec(align(16)) __m128 secondResult[2];
    MatrixRow b0;
    b0.scalar = second->matrix->row0;
    MatrixRow b1;
    b1.scalar = second->matrix->row1;
    MatrixRow b2;
    b2.scalar = second->matrix->row2;
    MatrixRow b3;
    b3.scalar = second->matrix->row3;

    for (int index = 1; index >= 0; --index) {
        __m128 v = _mm_load_ps(secondBone->frameVectors + index * 4);
        __m128 xy = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), b1.simd),
                                _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), b0.simd));
        __m128 zw = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), b2.simd), b3.simd);
        secondResult[index] = _mm_add_ps(xy, zw);
    }

    volatile float fraction = parameter->fraction;
    volatile float weightB = secondBone->blend;
    volatile float weightA = firstBone->blend;
    FUN_00cd6260(firstResult, weightA, secondResult, weightB, fraction, flags);
}
TransformInput* volatile inputFirst;
TransformInput* volatile inputSecond;
const BlendParameter* volatile inputParameter;
volatile int inputFlags;
void invoke_transform() { FUN_00d3b8e0(inputFirst, inputSecond, inputParameter, inputFlags); }

typedef float hkReal;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef uintptr_t hkUlong;
enum hkResult
{
HK_SUCCESS=0,
HK_FAILURE=1
};
typedef size_t hk_size_t;class FinishingFlag
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
class hkMemoryAllocator
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
class hkTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVector4&b);
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
hkVector4 m_kMinimumCorner;};typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVector4 m_vContactPosition;
hkVector4 m_vSeparatingNormal;};class Vector4WithInt24W:public hkVector4
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
class hkpCollisionDispatcher;
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
inline hkpContactMgr*getContactMgr();};class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}};
class hkpCapsuleCapsuleAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl FUN_00d3bd80(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&pointDetails);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void cleanup(hkpConstraintOwner&info);
protected:
__forceinline hkpCapsuleCapsuleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createCapsuleCapsuleAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
protected:
hkContactPointId m_usContactPointId[3];
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
extern "C"
{
hkResult __cdecl FindCapsuleCapsuleContact(const hkVector4*capsA,hkReal capsARadius,const hkVector4*capsB,hkReal capsBRadius,hkReal collisionTolerance,hkContactPoint&pointOut);}
namespace hkVector4Util_S
{
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut);}
inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVector4*vectorsIn,int numVectors,hkVector4*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
vectorsOut[i]._setTransformedPos(unaliased,vectorsIn[i]);
}while(--i>=0);}
static __forceinline hkResult getClosestPointInternal(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkContactPoint&cpoint)
{
const hkpCapsuleShape*capsuleA=static_cast<const hkpCapsuleShape*>(bodyA.getShape());
const hkpCapsuleShape*capsuleB=static_cast<const hkpCapsuleShape*>(bodyB.getShape());
hkVector4 pA[2];hkVector4Util_S::TransformPointArray(bodyA.getTransform(),capsuleA->GetIndexedVertices(),2,pA);
hkVector4 pB[2];hkVector4Util_S::TransformPointArray(bodyB.getTransform(),capsuleB->GetIndexedVertices(),2,pB);
return FindCapsuleCapsuleContact(pA,capsuleA->getRadius(),pB,capsuleB->getRadius(),input.getTolerance(),cpoint);}
// @fnv 0x00d3bd80
void __cdecl hkpCapsuleCapsuleAgent::FUN_00d3bd80(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "CapsCaps";h->setTime();mStream.setEnd((char*)(h+1));}};
ContactPointPair event(bodyA,bodyB);
if(getClosestPointInternal(bodyA,bodyB,input,event.m_kPoint)==HK_SUCCESS)
{
collector.AddCdPoint(event);
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}


class CapsulePointRotation;
class CapsulePointTransform;

class CapsulePointVector {
public:
    __m128 m_vComponents;
    __forceinline __m128 quadValue() const { return m_vComponents; }
    __forceinline const __m128& quadReference() const { return m_vComponents; }
    __forceinline void getQuad(__m128& out) const { out = m_vComponents; }
    __forceinline void setQuad(__m128 value) { m_vComponents = value; }
    __forceinline void setVector(const CapsulePointVector& value) { m_vComponents = value.m_vComponents; }

    float& operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
    const float& operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
    __forceinline void _setTransformedPos(const CapsulePointTransform& t, const CapsulePointVector& b);
};

class CapsulePointRotation {
public:
    CapsulePointVector m_kColumn0;
    CapsulePointVector m_kColumn1;
    CapsulePointVector m_kColumn2;
    __forceinline CapsulePointRotation(const CapsulePointRotation& o) : m_kColumn0(o.m_kColumn0), m_kColumn1(o.m_kColumn1), m_kColumn2(o.m_kColumn2) {}
};

class CapsulePointTransform {
public:
    CapsulePointRotation m_rotation;
    CapsulePointVector m_vTranslation;
    __forceinline CapsulePointTransform(const CapsulePointTransform& o) : m_rotation(o.m_rotation), m_vTranslation(o.m_vTranslation) {}
};

__forceinline void CapsulePointVector::_setTransformedPos(const CapsulePointTransform& t, const CapsulePointVector& b)
{
    const CapsulePointRotation& r = t.m_rotation;
    __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    __m128 r0 = _mm_mul_ps(b0, r.m_kColumn0.m_vComponents);
    __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    __m128 r1 = _mm_mul_ps(b1, r.m_kColumn1.m_vComponents);
    __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    __m128 r2 = _mm_mul_ps(b2, r.m_kColumn2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.m_vTranslation.m_vComponents));
}

struct CapsulePointTransforms {
    static __forceinline void TransformPointArray(const CapsulePointTransform& t, const CapsulePointVector* vectorsIn, int numVectors, CapsulePointVector* vectorsOut, CapsulePointVector& scratch)
    {
        CapsulePointVector c0 = t.m_rotation.m_kColumn0;
        CapsulePointVector c1 = t.m_rotation.m_kColumn1;
        CapsulePointVector c2 = t.m_rotation.m_kColumn2;
        scratch = t.m_vTranslation;
        __m128 saved = _mm_load_ps(reinterpret_cast<const float*>(&scratch.m_vComponents));
        int i = numVectors - 1;
        do
        {
            const CapsulePointVector& b = vectorsIn[i];
            __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
            __m128 r0 = _mm_mul_ps(b0, c0.m_vComponents);
            __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
            __m128 r1 = _mm_mul_ps(b1, c1.m_vComponents);
            __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
            __m128 r2 = _mm_mul_ps(b2, c2.m_vComponents);
            vectorsOut[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, saved));
        } while (--i >= 0);
    }
    static __forceinline void transformPoints2(const CapsulePointTransform& t, const CapsulePointVector* vectorsIn, int numVectors, CapsulePointVector* vectorsOut)
    {
        vectorsOut[0] = t.m_rotation.m_kColumn0;
        __m128 saved = vectorsOut[0].m_vComponents;
        CapsulePointVector c1 = t.m_rotation.m_kColumn1;
        CapsulePointVector c2 = t.m_rotation.m_kColumn2;
        CapsulePointVector c3 = t.m_vTranslation;
        CapsulePointVector q1; q1.setQuad(_mm_load_ps(reinterpret_cast<const float*>(&c1.m_vComponents)));
        int i = numVectors - 1;
        do
        {
            const CapsulePointVector& b = vectorsIn[i];
            __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
            __m128 r0 = _mm_mul_ps(b0, saved);
            __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
            __m128 r1 = _mm_mul_ps(b1, q1.m_vComponents);
            __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
            __m128 r2 = _mm_mul_ps(b2, c2.m_vComponents);
            vectorsOut[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, c3.m_vComponents));
        } while (--i >= 0);
    }
};

extern "C" const char DAT_010d1074[];
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

struct CommandTimingEntry
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static MonitorStream* GetMonitorStream() { return (MonitorStream*)TlsGetValue(::DAT_0126835c); }
};

static const char s_kEndTimer[] = "Et";
static __forceinline void TimerMark(const char* name, volatile unsigned int& t)
{
    MonitorStream* s = MonitorStream::GetMonitorStream();
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        CommandTimingEntry* h = (CommandTimingEntry*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}



extern "C" hkResult __cdecl FUN_00cd6260(const CapsulePointVector* capsA, float capsARadius, const CapsulePointVector* capsB, float capsBRadius, float collisionTolerance, hkContactPoint& cpoint);

// Transforms two capsule endpoint pairs into world space, queries their contact point, and adds it to the collector on success.
// @fnv 0x00d3baf0
void FUN_00d3baf0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input, hkpCdPointCollector& collector)
{
    volatile unsigned int ticks;
    {
        MonitorStream* s = MonitorStream::GetMonitorStream();
        if (s->m_kRayEnd < s->m_pCurrentCommand)
        {
            CommandTimingEntry* h = (CommandTimingEntry*)s->m_kRayEnd;
            h->m_pCommandName = "TtCapsCaps";
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            h->m_uiStartTicks = ticks;
            s->m_kRayEnd = (char*)(h + 1);
        }
    }

    const hkpCapsuleShape* capsA = static_cast<const hkpCapsuleShape*>(bodyA.getShape());
    const hkpCapsuleShape* capsB = static_cast<const hkpCapsuleShape*>(bodyB.getShape());

    ContactPointPair event(bodyA, bodyB);
    CapsulePointVector capsAPoints[2];
    CapsulePointVector capsBPoints[2];
    CapsulePointTransforms::TransformPointArray((const CapsulePointTransform&)bodyA.getTransform(), (const CapsulePointVector*)capsA->GetIndexedVertices(), 2, &capsAPoints[0], capsBPoints[0]);

    CapsulePointTransforms::transformPoints2((const CapsulePointTransform&)bodyB.getTransform(), (const CapsulePointVector*)capsB->GetIndexedVertices(), 2, &capsBPoints[0]);

    hkResult result = FUN_00cd6260(capsAPoints, capsA->getRadius(), capsBPoints, capsB->getRadius(), input.getTolerance(), event.m_kPoint);
    if (result == HK_SUCCESS)
    {
        collector.AddCdPoint(event);
    }

    {
        MonitorStream* s = MonitorStream::GetMonitorStream();
        if (s->m_kRayEnd < s->m_pCurrentCommand)
        {
            CommandTimingEntry* h = (CommandTimingEntry*)s->m_kRayEnd;
            h->m_pCommandName = "Et";
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            h->m_uiStartTicks = ticks;
            s->m_kRayEnd = (char*)(h + 1);
        }
    }
}

// Moved from hkpcapsulecapsuleagent_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
#include "fnv/symbols_00d22000.h"
#include "fnv/symbols_00d3c000.h"
#include "fnv/symbols_010c4000.h"

extern "C" unsigned __int64 __rdtsc(void);
// The profiler keeps one 12 byte entry per marked call site in a per thread buffer.
// The entry holds the name of the marked site and a timestamp taken from the TSC.
struct ProfilerTls
{
    int unk00;
    char* unk04;  // write cursor
    char* unk08;
    char* unk0C;  // end of the buffer
};

// One row of a 4x4 matrix.  The rows are copied as raw dwords, so the
// stand-in keeps them as 32 bit words.
struct __declspec(align(16)) MatRow
{
    unsigned int c0, c1, c2, c3;
};

// The four rows of a transform matrix.  Row 0 of the source matrix is kept in
// the last slot, row 1 in the first one and so on (the rows are rotated).
struct MatSlots
{
    MatRow m0;  // slot 0  <- source row 1
    MatRow m1;  // slot 1  <- source row 2
    MatRow m2;  // slot 2  <- source row 3
    MatRow m3;  // slot 3  <- source row 0
};

// The two transformed segments: the ray (v2,v3) and the segment (v0,v1).
struct Segments
{
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    Vec4 v3;
};

// The two direction vectors of the ray and of the segment.
struct Rays
{
    Vec4 edge;
    Vec4 dir;
};

// Result of the ray / segment intersection.
struct RayHit
{
    Vec4 point;
    Vec4 point2;
    float distSq;
};

// A capsule: four points (the last two are the segment ends) plus its transform.
struct Capsule
{
    float* unk00;
    int unk04;
    float* unk08;
};

struct HitHandler
{
    virtual void slot00();
    virtual void slot04(Capsule*, Capsule*);
};

extern char DAT_010cefcc[];


template <class T> struct LazyPtr
{
    T* p;
    LazyPtr(T* q) : p(q)
    {}
    T* operator->() const
    {
        return p;
    }
    operator T*() const
    {
        return p;
    }
};
// @fnv 0x00d3b420
void __cdecl FUN_00d3b420(Capsule* pFirst, Capsule* pSecond, void* pUnused, HitHandler* pHandler)
{
    ProfilerTls* pTls = (ProfilerTls*)TlsGetValue((*reinterpret_cast<int *>(&::DAT_0126835c)));
    char* pCur = pTls->unk04;
    if (pCur < pTls->unk0C)
    {
        *(const char**)pCur = DAT_010cefcc;
        _ReadWriteBarrier();
        volatile unsigned ts = (unsigned)__rdtsc();
        *(unsigned*)(pCur + 4) = ts;
        pTls->unk04 = pCur + 12;
    }

    // The point arrays of both capsules and the transform matrices.
    const float* pSrc = pFirst->unk00;
    const float* pSrc2 = pSecond->unk00;

    // --- the transform matrix of the first capsule ---
    // The rows are kept rotated: row 0 ends up in the last slot.
    MatSlots mat;
    const MatRow* m = (const MatRow*)pFirst->unk08;
    const unsigned int* s = (const unsigned int*)m;
    unsigned int* d = (unsigned int*)&mat;
    mat.m3.c0 = m[0].c0;
    mat.m3.c1 = m[0].c1;
    mat.m3.c2 = m[0].c2;
    mat.m3.c3 = m[0].c3;
    mat.m0.c0 = m[1].c0;
    mat.m0.c1 = m[1].c1;
    mat.m0.c2 = m[1].c2;
    mat.m0.c3 = m[1].c3;
    mat.m1.c0 = m[2].c0;
    mat.m1.c1 = m[2].c1;
    mat.m1.c2 = m[2].c2;
    mat.m1.c3 = m[2].c3;
    mat.m2.c0 = m[3].c0;
    mat.m2.c1 = m[3].c1;
    mat.m2.c2 = m[3].c2;
    mat.m2.c3 = m[3].c3;

    Segments seg;

    // --- transform the two segment ends of the first capsule ---
    // The last two points of the capsule are the ends of its segment; they are
    // transformed by the matrix and written back into the segment slots.

    __m128 m0 = _mm_load_ps((const float*)&mat.m3);
    __m128 m1 = _mm_load_ps((const float*)&mat.m0);
    __m128 m2 = _mm_load_ps((const float*)&mat.m1);
    __m128 m3 = _mm_load_ps((const float*)&mat.m2);
    for (int i = 1; i >= 0; --i)
    {
        __m128 r = _mm_load_ps(pSrc + (i + 2) * 4);
        __m128 b = _mm_mul_ps(_mm_shuffle_ps(r, r, 0x55), m1);
        __m128 a = _mm_mul_ps(_mm_shuffle_ps(r, r, 0x00), m0);
        __m128 c = _mm_mul_ps(_mm_shuffle_ps(r, r, 0xaa), m2);
        *((__m128*)&seg.v2 + i) = _mm_add_ps(_mm_add_ps(b, a), _mm_add_ps(c, m3));
    }

    // --- the transform matrix of the second capsule ---
    m = (const MatRow*)pSecond->unk08;
    const unsigned int* s2 = (const unsigned int*)m;
    unsigned int* d2 = (unsigned int*)&mat;
    mat.m2.c0 = m[0].c0;
    mat.m2.c1 = m[0].c1;
    mat.m2.c2 = m[0].c2;
    mat.m2.c3 = m[0].c3;
    mat.m1.c0 = m[1].c0;
    mat.m1.c1 = m[1].c1;
    mat.m1.c2 = m[1].c2;
    mat.m1.c3 = m[1].c3;
    mat.m0.c0 = m[2].c0;
    mat.m0.c1 = m[2].c1;
    mat.m0.c2 = m[2].c2;
    mat.m0.c3 = m[2].c3;
    mat.m3.c0 = m[3].c0;
    mat.m3.c1 = m[3].c1;
    mat.m3.c2 = m[3].c2;
    mat.m3.c3 = m[3].c3;

    // --- transform the two segment ends of the second capsule ---

    m0 = _mm_load_ps((const float*)&mat.m2);
    m1 = _mm_load_ps((const float*)&mat.m1);
    m2 = _mm_load_ps((const float*)&mat.m0);
    m3 = _mm_load_ps((const float*)&mat.m3);
    for (int i = 1; i >= 0; --i)
    {
        __m128 r = _mm_load_ps(pSrc2 + (i + 2) * 4);
        __m128 b = _mm_mul_ps(_mm_shuffle_ps(r, r, 0x55), m1);
        __m128 a = _mm_mul_ps(_mm_shuffle_ps(r, r, 0x00), m0);
        __m128 c = _mm_mul_ps(_mm_shuffle_ps(r, r, 0xaa), m2);
        *((__m128*)&seg.v0 + i) = _mm_add_ps(_mm_add_ps(b, a), _mm_add_ps(c, m3));
    }

    // The direction of the two segments.
    Rays rays;
    *(__m128*)&rays.dir = _mm_sub_ps(*(const __m128*)&seg.v3, *(const __m128*)&seg.v2);
    *(__m128*)&rays.edge = _mm_sub_ps(*(const __m128*)&seg.v1, *(const __m128*)&seg.v0);

    // Intersect the ray with the segment.
    RayHit hit;
    ::FUN_00d22e40((*(const ::hkVector4 *)(&seg.v2)), (*(const ::hkVector4 *)(&rays.dir)), (*(const ::hkVector4 *)(&seg.v0)), (*(const ::hkVector4 *)(&rays.edge)), (*(::VectorPairResult *)(&hit)));

    // The two radii decide whether the capsules overlap.
    float t = pSrc[4] + pSrc2[4];
    if (hit.distSq < t * t)
    {
        pHandler->slot04(pFirst, pSecond);
    }

    // --- leave the profiler ---
    pTls = (ProfilerTls*)TlsGetValue((*reinterpret_cast<int *>(&::DAT_0126835c)));
    pCur = pTls->unk04;
    if (pCur < pTls->unk0C)
    {
        *(const char**)pCur = DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned ts = (unsigned)__rdtsc();
        *(unsigned*)(pCur + 4) = ts;
        pTls->unk04 = pCur + 12;
    }
}
namespace fnv_00d3b6f0 {
struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};
struct __declspec(align(16)) MatRow
{
    unsigned int c0, c1, c2, c3;
};
struct MatSlots
{
    MatRow m0, m1, m2, m3;
};
struct Segments
{
    Vec4 v0, v1, v2, v3;
};
struct Capsule
{
    float* unk00;
    int unk04;
    float* unk08;
};
struct Context
{
    int unk00, unk04;
    float scale;
};
struct TransformOutput
{
    float rows[3][8];
};
void __cdecl FUN_00cd58b0(const void*, float, const void*, float, TransformOutput*);
// @fnv 0x00d3b6f0
static __declspec(noinline) void FUN_00d3b6f0(Capsule* first, TransformOutput* dst, Context* context, Capsule* second)
{
    const float* nodeA = first->unk00;
    float scaleValue = context->scale;
    dst->rows[0][7] = scaleValue;
    dst->rows[1][7] = scaleValue;
    dst->rows[2][7] = scaleValue;
    const float* nodeB = second->unk00;
    Vec4 resultA[2], resultB[2];
    {
        MatRow row0, row1, row2, row3;
        const MatRow* m = (const MatRow*)first->unk08;
        row0.c0 = m[0].c0;
        row0.c1 = m[0].c1;
        row0.c2 = m[0].c2;
        row0.c3 = m[0].c3;
        row1.c0 = m[1].c0;
        row1.c1 = m[1].c1;
        row1.c2 = m[1].c2;
        row1.c3 = m[1].c3;
        row2.c0 = m[2].c0;
        row2.c1 = m[2].c1;
        row2.c2 = m[2].c2;
        row2.c3 = m[2].c3;
        row3.c0 = m[3].c0;
        row3.c1 = m[3].c1;
        row3.c2 = m[3].c2;
        row3.c3 = m[3].c3;
        __m128 r0 = *(const __m128*)&row0;
        __m128 r1 = *(const __m128*)&row1;
        __m128 r2 = *(const __m128*)&row2;
        __m128 r3 = *(const __m128*)&row3;
        for (int i = 1; i >= 0; --i)
        {
            __m128 v = _mm_load_ps(nodeA + (i + 2) * 4);
            __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), r1);
            __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), r0);
            __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), r2);
            *((__m128*)resultA + i) = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, r3));
        }
    }
    {
        MatRow row0, row1, row2, row3;
        const MatRow* m = (const MatRow*)second->unk08;
        row3.c0 = m[0].c0;
        row3.c1 = m[0].c1;
        row3.c2 = m[0].c2;
        row3.c3 = m[0].c3;
        row2.c0 = m[1].c0;
        row2.c1 = m[1].c1;
        row2.c2 = m[1].c2;
        row2.c3 = m[1].c3;
        row1.c0 = m[2].c0;
        row1.c1 = m[2].c1;
        row1.c2 = m[2].c2;
        row1.c3 = m[2].c3;
        row0.c0 = m[3].c0;
        row0.c1 = m[3].c1;
        row0.c2 = m[3].c2;
        row0.c3 = m[3].c3;
        __m128 r0 = *(const __m128*)&row3;
        __m128 r1 = *(const __m128*)&row2;
        __m128 r2 = *(const __m128*)&row1;
        __m128 r3 = *(const __m128*)&row0;
        for (int i = 1; i >= 0; --i)
        {
            __m128 v = _mm_load_ps(nodeB + (i + 2) * 4);
            __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), r1);
            __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), r0);
            __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), r2);
            *((__m128*)resultB + i) = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, r3));
        }
    }
    FUN_00cd58b0(resultA, nodeA[4], resultB, nodeB[4], dst);
}
Context* volatile contextSource;
Capsule* volatile firstSource;
TransformOutput* volatile outputSource;
Capsule* volatile secondSource;
void invokeTransform()
{
    FUN_00d3b6f0(firstSource, outputSource, contextSource, secondSource);
}
}  // namespace fnv_00d3b6f0

struct TimerEntry
{
    const char* tag;
    unsigned stamp;
    unsigned extra;
};

struct CapsuleShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
    int unk14;
    int unk18;
    int unk1C;
    Vec4 m_kVertexA;
    Vec4 m_kVertexB;

    const Vec4* GetIndexedVertices() const
    {
        return &m_kVertexA;
    }
};

struct CdBody
{
    CapsuleShape* m_pCollisionShape;
    int unk04;
    const MatSlots* m_kMotionState;
};

struct CollisionInput
{
    int unk00;
    int unk04;
    float m_fScalar;
};

struct PointResult
{
    struct
    {
        float x, y, z, w;
    } m_vHitNormal;
    float m_posAndDistX;
    float m_posAndDistY;
    float m_posAndDistZ;
    float m_fClosestPointDistanceSquared;
};

struct BasisRows
{
    MatRow row1, row0, row2;
};
union EndpointScratch
{
    MatRow row;
    Vec4 endpoints[2];
};
struct ContactWorkspace
{
    PointResult results[3];
    Vec4 verticesA[2];
};

struct AlignedPairData
{
    Vec4 m_vec0;
    Vec4 m_vec1;
    unsigned int m_usContactPointId;
    int unk24;
    int unk28;
    int unk2C;
};

struct Collector
{
    AlignedPairData* m_cur;
    int m_unk04;
};

struct MyCallback
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual unsigned short slot0C(const CdBody* a, const CdBody* b, const CollisionInput* c, Collector* d, int e,
                                  PointResult* f);
    virtual void slot10();
    virtual void invoke(unsigned short id, int unk);
};

extern "C" void __cdecl FUN_00cd58b0(const Vec4* verticesA, float radiusA, const Vec4* verticesB, float radiusB,
                                     PointResult* results);

struct Agent : FUN_00d3b3d0_Class
{
    void FUN_00d3c060(const CdBody* bodyA, const CdBody* bodyB, const CollisionInput* input, Collector* collector);
};

// @fnv 0x00d3c060
void Agent::FUN_00d3c060(const CdBody* bodyA, const CdBody* bodyB, const CollisionInput* input, Collector* collector)
{
    ProfilerTls* ms = (ProfilerTls*)TlsGetValue((*reinterpret_cast<int *>(&::DAT_0126835c)));
    {
        TimerEntry* cursor = (TimerEntry*)ms->unk04;
        if (cursor < (TimerEntry*)ms->unk0C)
        {
            cursor->tag = DAT_010cefcc;
            _ReadWriteBarrier();
            volatile unsigned timestamp = (unsigned)__rdtsc();
            cursor->stamp = timestamp;
            ms->unk04 = (char*)(cursor + 1);
        }
    }

    BasisRows basis;
    EndpointScratch scratch;
    ContactWorkspace contacts;

    float tol = input->m_fScalar;
    CapsuleShape* capA = bodyA->m_pCollisionShape;
    const MatSlots* transformA = bodyA->m_kMotionState;
    contacts.results[0].m_fClosestPointDistanceSquared = tol;
    contacts.results[1].m_fClosestPointDistanceSquared = tol;
    CapsuleShape* capB = bodyB->m_pCollisionShape;
    contacts.results[2].m_fClosestPointDistanceSquared = tol;

    {
        basis.row0.c0 = transformA->m0.c0;
        basis.row0.c1 = transformA->m0.c1;
        basis.row0.c2 = transformA->m0.c2;
        basis.row0.c3 = transformA->m0.c3;
        __m128 m0 = _mm_load_ps((const float*)&basis.row0);
        basis.row1.c0 = transformA->m1.c0;
        basis.row1.c1 = transformA->m1.c1;
        basis.row1.c2 = transformA->m1.c2;
        basis.row1.c3 = transformA->m1.c3;
        __m128 m1 = _mm_load_ps((const float*)&basis.row1);
        basis.row2.c0 = transformA->m2.c0;
        basis.row2.c1 = transformA->m2.c1;
        basis.row2.c2 = transformA->m2.c2;
        basis.row2.c3 = transformA->m2.c3;
        scratch.row.c0 = transformA->m3.c0;
        __m128 m2 = _mm_load_ps((const float*)&basis.row2);
        scratch.row.c1 = transformA->m3.c1;
        scratch.row.c2 = transformA->m3.c2;
        scratch.row.c3 = transformA->m3.c3;
        __m128 m3 = _mm_load_ps((const float*)&scratch.row);

        for (int i = 1; i >= 0; --i)
        {
            __m128 v = _mm_load_ps(&capA->GetIndexedVertices()[i].x);
            __m128 y = _mm_shuffle_ps(v, v, 0x55);
            __m128 x = _mm_shuffle_ps(v, v, 0x00);
            __m128 r0 = _mm_mul_ps(x, m0);
            __m128 r1 = _mm_mul_ps(y, m1);
            r1 = _mm_add_ps(r1, r0);

            __m128 z = _mm_shuffle_ps(v, v, 0xaa);
            __m128 r2 = _mm_mul_ps(z, m2);
            r2 = _mm_add_ps(r2, m3);

            __m128 res = _mm_add_ps(r1, r2);
            *((__m128*)contacts.verticesA + i) = res;
        }
    }

    {
        const MatSlots* transformB = bodyB->m_kMotionState;
        scratch.row.c0 = transformB->m0.c0;
        scratch.row.c1 = transformB->m0.c1;
        scratch.row.c2 = transformB->m0.c2;
        scratch.row.c3 = transformB->m0.c3;
        __m128 m0 = _mm_load_ps((const float*)&scratch.row);
        basis.row2.c0 = transformB->m1.c0;
        basis.row2.c1 = transformB->m1.c1;
        basis.row2.c2 = transformB->m1.c2;
        basis.row2.c3 = transformB->m1.c3;
        __m128 m1 = _mm_load_ps((const float*)&basis.row2);
        basis.row1.c0 = transformB->m2.c0;
        basis.row1.c1 = transformB->m2.c1;
        basis.row1.c2 = transformB->m2.c2;
        basis.row1.c3 = transformB->m2.c3;
        __m128 m2 = _mm_load_ps((const float*)&basis.row1);
        basis.row0.c0 = transformB->m3.c0;
        basis.row0.c1 = transformB->m3.c1;
        basis.row0.c2 = transformB->m3.c2;
        basis.row0.c3 = transformB->m3.c3;
        __m128 m3 = _mm_load_ps((const float*)&basis.row0);

        for (int i = 1; i >= 0; --i)
        {
            __m128 v = _mm_load_ps(&capB->GetIndexedVertices()[i].x);
            __m128 y = _mm_shuffle_ps(v, v, 0x55);
            __m128 x = _mm_shuffle_ps(v, v, 0x00);
            __m128 r0 = _mm_mul_ps(x, m0);
            __m128 r1 = _mm_mul_ps(y, m1);
            r1 = _mm_add_ps(r1, r0);

            __m128 z = _mm_shuffle_ps(v, v, 0xaa);
            __m128 r2 = _mm_mul_ps(z, m2);
            r2 = _mm_add_ps(r2, m3);

            __m128 res = _mm_add_ps(r1, r2);
            *((__m128*)scratch.endpoints + i) = res;
        }
    }

    FUN_00cd58b0(contacts.verticesA, capA->m_fSphereRadius, scratch.endpoints, capB->m_fSphereRadius, contacts.results);

    Collector* output = collector;
    PointResult* res = contacts.results;
    unsigned short* contactId = &this->unk0C;
    for (int i = 3; i != 0; --i)
    {
        const CollisionInput* collisionInput = input;
        if (res->m_fClosestPointDistanceSquared < collisionInput->m_fScalar)
        {
            if (*contactId == 0xffff)
            {
                *contactId = ((MyCallback*)this->unk08)->slot0C(bodyA, bodyB, collisionInput, output, 0, res);
                if (*contactId == 0xffff)
                {
                    goto next;
                }
            }
            AlignedPairData* outPoint = output->m_cur;
            __m128 normal = _mm_load_ps(&res->m_vHitNormal.x);
            output->m_cur = outPoint + 1;
            _mm_store_ps(&outPoint->m_vec0.x, normal);
            _mm_store_ps(&outPoint->m_vec1.x, _mm_load_ps(&res->m_posAndDistX));
            outPoint->m_usContactPointId = *contactId;
        }
        else
        {
            if (*contactId != 0xffff)
            {
                ((MyCallback*)this->unk08)->invoke(*contactId, output->m_unk04);
                *contactId = 0xffff;
            }
        }
    next:
        contactId++;
        res++;
    }

    ms = (ProfilerTls*)TlsGetValue((*reinterpret_cast<int *>(&::DAT_0126835c)));
    {
        TimerEntry* cursor = (TimerEntry*)ms->unk04;
        if (cursor < (TimerEntry*)ms->unk0C)
        {
            cursor->tag = DAT_010c41f8;
            _ReadWriteBarrier();
            volatile unsigned timestamp = (unsigned)__rdtsc();
            cursor->stamp = timestamp;
            ms->unk04 = (char*)(cursor + 1);
        }
    }
}
#include "generated/data/havok/physics/collide/agent/convexagent/capsulecapsule/hkpcapsulecapsuleagent_gs_ehsc_nogs_noehsc_variant.inc"
