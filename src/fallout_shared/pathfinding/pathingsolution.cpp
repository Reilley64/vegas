// fallout_shared/pathfinding/pathingsolution.cpp: PathingSolution, OwnS, DelS, HermiteStub and more (34 functions)

#include "fnv_result_slot.h"
#include <cstdint>
#include <new>
#include "fnv/decl/BGSSaveGameBuffer.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BSSimpleArray_006cefa0.h"
#include "fnv/decl/BSSimpleArray_PathingAvoidNode_1024.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/C42CE30.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_006dc890_Class.h"
#include "fnv/decl/FUN_006e2350_shell.h"
#include "fnv/decl/FUN_006e8fc0_Class.h"
#include "fnv/decl/FUN_006e9000_Class.h"
#include "fnv/decl/FUN_006e90a0_class.h"
#include "fnv/decl/FUN_006e9410_class.h"
#include "fnv/decl/FUN_006e9470_cls.h"
#include "fnv/decl/FUN_006f50b0_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_00865db0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/LoadHolder6F51.h"
#include "fnv/decl/LoadedRefHolder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_FUN_006b05a0.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005a4000.h"
#include "fnv/symbols_006e7000.h"
#include "fnv/symbols_008b6000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0106d000.h"
#include "pathingsolution_types_PathingSolution.h"

// Initializes the PathingSolution object by setting two local sentinel values to -1 and clearing the boolean member.
// @fnv 0x006e7650
PathingSolution::PathingSolution()
{
    volatile int first;
    volatile int second;
    second = -1;
    first = -1;
    m_bHasValidPath = false;
}

struct DelS
{
    void FUN_006e7720();
    void* FUN_006e76f0(unsigned int flags);
};
struct PSClearStub
{
    void Clear(bool);
};
struct PSNodeStub
{
    void FUN_006cf120(bool);
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};

// Clears the three members of the pathing solution, sets member1's two values to -1 and clears the flag.
// @fnv 0x006e77b0
void ResetPathingSolution(PathingSolution* self)
{
    reinterpret_cast<::BSSimpleArray_006cefa0 *>((((PSClearStub*)&self->member1)))->FreeArray(true);
    ((PSNodeStub*)&self->member2)->FUN_006cf120(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)&self->member3)))->Clear(true);
    self->member1.firstValue = -1;
    self->member1.secondValue = -1;
    self->m_bHasValidPath = false;
}

struct FUN_006e78b0_shell : public PathingSolution
{
    void* FUN_006e78b0(unsigned int);
};
// @fnv 0x006e7800
float PathingSolution::CalculatePathLength()
{
    struct Stack
    {
        NiPoint3 thirdPoint;
        NiPoint3 secondPoint;
        NiPoint3 firstPoint;
        unsigned int index;
        unsigned int count;
        PacketNodeRecord* second;
        PacketNodeRecord* first;
        float distance;
    } stack;
    stack.distance = 0.0f;
    stack.count = ::FUN_005a4320((char *)this);
    for (stack.index = 1; stack.index < stack.count; ++stack.index)
    {
        stack.first = ((::PacketNodeRecord *)(reinterpret_cast<::FUN_006e78b0_shell *>(this)->FUN_006e78b0(stack.index - 1)));
        if (reinterpret_cast<::PathingGraphNode *>((stack.first))->IsTransitionNode())
            continue;
        stack.second = ((::PacketNodeRecord *)(reinterpret_cast<::FUN_006e78b0_shell *>(this)->FUN_006e78b0(stack.index)));
        stack.distance += reinterpret_cast<::FUN_00589850_Class *>((((::PathingPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((((::PathingDoorRef *)&(reinterpret_cast<::TaskQueueInterface *>((((::PathingDoorRef *)(reinterpret_cast<::BaseProcess *>((stack.second))->GetCurrentProcessData()))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>())))))->FUN_00439ef0({}, *(const ::NiPoint3 *)nullptr)))))->FUN_00589850();
    }
    return stack.distance;
}

struct PathBuilder
{
};

struct FUN_006e7970_shell : public PathingSolution
{
    void* FUN_006e7970(unsigned int);
};

void* FUN_006e8f80(void* this_ptr);

struct Dummy_006e8f80
{
    void* FUN_006e8f80(unsigned int aiIndex);
};

struct FUN_00457990_shell
{
};

struct FUN_006e7990_shell
{
    float FUN_006e7990(int);
};

// Returns 0.0f if the index is at or past the last element, otherwise computes a value from the positions of the element at the index and the next one.
// @fnv 0x006e7990
float FUN_006e7990_shell::FUN_006e7990(int aiIndex)
{
    if (aiIndex >= ((int)(::GetObjectFlags((char *)this))) - 1)
        return 0.0f;
    NiPoint3 loc1;
    NiPoint3 loc2;
    NiPoint3 loc3;
    return reinterpret_cast<::NiPoint3 *>((((FUN_00457990_shell*)((::PathingPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((((::PathingDoorRef *)&(reinterpret_cast<::TaskQueueInterface *>((((::PathingDoorRef *)(reinterpret_cast<::BaseProcess *>((((::PacketNodeRecord *)(reinterpret_cast<::FUN_006e7970_shell *>(this)->FUN_006e7970(aiIndex)))))->GetCurrentProcessData()))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>())))))->FUN_00439ef0({}, *(const ::NiPoint3 *)nullptr))))))->ComputeMagnitude();
}

struct BaseS
{
    char pad[0x14];
    BaseS();
    ~BaseS();
};
struct MemS
{
    char pad[0x18];
    MemS();
};
struct FUN_006e7b60 : BaseS
{
    MemS m1;
    MemS m2;
    FUN_006e7b60();
};
// Constructs the object by running the BaseS constructor and default-constructing its two MemS members.
// @fnv 0x006e7b60
FUN_006e7b60::FUN_006e7b60()
{}


// Sets two NiPoint3 values at offsets 0 and 0xc of pThis to _NiPoint3_ZERO and returns pThis.
// @fnv 0x006e7bd0
void* InitZeroPoints(void* pThis)
{
    *(NiPoint3*)pThis = ::NiPoint3::ZERO;
    *(NiPoint3*)((char*)pThis + 0xc) = ::NiPoint3::ZERO;
    return pThis;
}

void FUN_006e7c40(void* pThis, float arg);

// @fnv 0x006e7c20
void FUN_006e7c20(void* pThis, float arg)
{
    FUN_006e7c40(pThis, arg);
}

struct HermiteStub
{
    float t;
    float a;
    float b;
    float c;
    float d;
    void FUN_006e7c40(float t);
};
// @fnv 0x006e7c40
void HermiteStub::FUN_006e7c40(float tp)
{
    float t2;
    float t3;
    float tt;
    t = tp;
    tt = tp;
    t2 = tt * tt;
    t3 = t2 * tt;
    c = t3 * DAT_0106d4c8 + t2 * 3.0;
    a = -c + 1.0;
    d = t3 - t2;
    b = d - t2 + tt;
}

struct _S_006e7d10_vec
{
    float x, y, z;
};

struct _S_006e7d10
{
    _S_006e7d10_vec a;
    _S_006e7d10_vec b;
};

struct _Arg_006e7d10
{
    const _S_006e7d10* p;
};

struct SubS
{
};
struct RetS
{
    float v[3];
};
struct OwnS
{
    char pad[0x14];
    SubS s1;
    char pad2[0x17];
    SubS s2;
    RetS FUN_006e7d60(const _S_006e7d10*, const _S_006e7d10*);
    RetS FUN_006e7cc0(const _S_006e7d10* a, const _S_006e7d10* b);
};
// Calls FUN_006e7d10 on s1 with a and on s2 with b, then returns FUN_006e7d60(a, b).
// @fnv 0x006e7cc0
RetS OwnS::FUN_006e7cc0(const _S_006e7d10* apFirst, const _S_006e7d10* apSecond)
{
    ::FUN_006e7d10((::_S_006e7d10 *)&(s1), ::_Arg_006e7d10{apFirst});
    ::FUN_006e7d10((::_S_006e7d10 *)&(s2), ::_Arg_006e7d10{apSecond});
    return FUN_006e7d60(apFirst, apSecond);
}

// Copies the two vector members a and b from the pointed-to struct into this struct and returns this.
// @fnv 0x006e7d10
_S_006e7d10* FUN_006e7d10(_S_006e7d10* this_ptr, _Arg_006e7d10 aSource)
{
    this_ptr->a = aSource.p->a;
    this_ptr->b = aSource.p->b;
    return this_ptr;
}

struct NP3S
{
    float x;
    float y;
    float z;
};
struct LocS
{
};
struct M24
{
    NP3S a;
    NP3S b;
    M24();
    M24(const M24&);
};
struct OwnS2
{
    char pad[4];
    LocS loc;
    char pad2[0x27];
    NP3S tangent;
    M24 GetLocationAndTangent();
};
// Builds an M24 from the object's location and tangent and returns it.
// @fnv 0x006e7e10
M24 OwnS2::GetLocationAndTangent()
{
    M24 m;
    m.a = (*(::NP3S *)&(reinterpret_cast<::TaskQueueInterface *>(&(loc))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>())));
    m.b = tangent;
    return m;
}

struct blob12
{
    char b[12];
};
struct SplineInterpolator
{
    void SetParameter(float);
    void SetKeyData(void*, void*);
    struct blob12 Interpolate();
    struct blob12 Interpolate(float);
    struct blob12 Interpolate(void*, void*, float);
    struct blob12 Interpolate(void*, void*);
    bool FindPointOnSpline(float, float, bool, float*, NiPoint3*, float);
    float ApproxLength(float, float, unsigned int);
    struct blob12 InterpolateNoZ(void*, void*);
    void* __vecDelDtor(unsigned int);
    char SplinePath[20];
    char Key1[24];
    char Key2[24];
};
struct PathingControlPoint
{
    NiPoint3 Location;
    NiPoint3 Tangent;
};
struct FUN_006e8450_shell : public SplineInterpolator
{
    void FUN_006e8450(void*, void*);
};

struct FUN_006e7d10_caller
{
};

// Forwards each of the two key arguments to the corresponding key object's FUN_006e7d10 method.
// @fnv 0x006e8450
void FUN_006e8450_shell::FUN_006e8450(void* aKey1, void* aKey2)
{
    ::FUN_006e7d10((::_S_006e7d10 *)(reinterpret_cast<FUN_006e7d10_caller*>(this->Key1)), ::_Arg_006e7d10{(const ::_S_006e7d10 *)aKey1});
    ::FUN_006e7d10((::_S_006e7d10 *)(reinterpret_cast<FUN_006e7d10_caller*>(this->Key2)), ::_Arg_006e7d10{(const ::_S_006e7d10 *)aKey2});
}

namespace fnv_006e8f60 {
class PathBuilder
{
  public:
    void* FUN_006e8f40(unsigned int);
    void* FUN_006e8f60(unsigned int aiIndex);
};

// @fnv 0x006e8f60
void* PathBuilder::FUN_006e8f60(unsigned int aiIndex)
{
    return FUN_006e8f40(aiIndex);
}
}  // namespace fnv_006e8f60

struct S3e60
{
    bool FUN_006e8fa0(unsigned int f);
public:
    bool FUN_006a1400(unsigned int);
public:
    void** FUN_006a7ad0(unsigned int);
};
struct FUN_006e9080
{
    char b[0x18];
    ~FUN_006e9080();
};
struct FUN_006e9260
{
    char b[0x10];
    ~FUN_006e9260();
};
struct FUN_00438690
{
    char b[8];
    ~FUN_00438690();
};
struct EBase
{
    virtual ~EBase();
    char b[4];
};
struct FUN_006e7720 : public EBase
{
    FUN_006e9080 m1;
    FUN_006e9260 m2;
    FUN_00438690 m3;
    virtual ~FUN_006e7720();
};
// Calls FUN_006e7720, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006e76f0
void* DelS::FUN_006e76f0(unsigned int flags)
{
    reinterpret_cast<::FUN_006e7720 *>(this)->::FUN_006e7720::~FUN_006e7720();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x44);
    return this;
}
// @fnv 0x006e7720
FUN_006e7720::~FUN_006e7720()
{
    ::ResetPathingSolution((::PathingSolution *)(::FUN_006e7720 *)(this));
}

namespace fnv_006e78d0 {
struct FUN_006e78d0_shell : public PathingSolution
{
    float GetTotalPathLength();
};

struct FUN_006e7970_shell
{
};
struct SizeH
{
};
struct NiPoint3H
{
};
// Sums the lengths of the segments between consecutive path nodes and returns the total length.
// @fnv 0x006e78d0
float FUN_006e78d0_shell::GetTotalPathLength()
{
    float ftotalLength = 0.0f;
    PacketNodeRecord* plastNode;
    PacketNodeRecord* pnextNode;
    unsigned int isize = ::GetObjectFlags((char *)(((SizeH*)this)));
    for (unsigned int i = 1; i < isize; i++)
    {
        plastNode = (PacketNodeRecord*)reinterpret_cast<::FUN_006e7970_shell *>((((FUN_006e7970_shell*)this)))->FUN_006e7970(i - 1);
        pnextNode = (PacketNodeRecord*)reinterpret_cast<::FUN_006e7970_shell *>((((FUN_006e7970_shell*)this)))->FUN_006e7970(i);
        NiPoint3 a;
        NiPoint3 b;
        NiPoint3 c;
        ftotalLength += reinterpret_cast<::NiPoint3 *>((void *)(((NiPoint3H*)((::PathingPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((((::PathingDoorRef *)&(reinterpret_cast<::TaskQueueInterface *>((((::PathingDoorRef *)(reinterpret_cast<::BaseProcess *>((pnextNode))->GetCurrentProcessData()))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>())))))->FUN_00439ef0({}, *(const ::NiPoint3 *)nullptr))))))->ComputeMagnitude();
    }
    return ftotalLength;
}
}  // namespace fnv_006e78d0

struct _ref_006815c0
{
    float x;
    float y;
    float z;
    _ref_006815c0();
};
struct FUN_006e7d60_stub
{
    _ref_006815c0 FUN_006e7d60(char* p3, char* p4);
};
// Computes a vector from two structures by calling ComputeWeightedSum on each of the x, y and z component pairs.
// @fnv 0x006e7d60
_ref_006815c0 FUN_006e7d60_stub::FUN_006e7d60(char* pFirst, char* pSecond)
{
    _ref_006815c0 vecResult;
    vecResult.x = reinterpret_cast<::FUN_006e9000_Class *>(this)->ComputeWeightedSum((float*)pFirst, (float*)pSecond, (float*)(pFirst + 0xc), (float*)(pSecond + 0xc));
    vecResult.y = reinterpret_cast<::FUN_006e9000_Class *>(this)->ComputeWeightedSum((float*)(pFirst + 4), (float*)(pSecond + 4), (float*)(pFirst + 0x10),
                                     (float*)(pSecond + 0x10));
    {
        float a = 0.0f;
        float b = 0.0f;
        vecResult.z = reinterpret_cast<::FUN_006e9000_Class *>(this)->ComputeWeightedSum((float*)(pFirst + 8), (float*)(pSecond + 8), &b, &a);
    }
    return vecResult;
}

struct FUN_006e8f40_shell
{
    void* m_pVtbl;
    char* m_pBuffer;
    std::intptr_t FUN_006e8f40(std::intptr_t a) const;
};
// @fnv 0x006e78b0
void* FUN_006e78b0_shell::FUN_006e78b0(unsigned int aiIndex)
{
    return ((void *)(reinterpret_cast<::FUN_006e8f40_shell *>((((PathBuilder*)&this->member1)))->FUN_006e8f40(aiIndex)));
}

// @fnv 0x006e8f40
std::intptr_t FUN_006e8f40_shell::FUN_006e8f40(std::intptr_t aiIndex) const
{
    return aiIndex * 0x30 + reinterpret_cast<std::intptr_t>(m_pBuffer);
}

namespace fnv_006e7e70 {
struct blob12
{
    char b[12];
};
struct SplineInterpolator
{
    void SetParameter(float);
    void SetKeyData(void*, void*);
    struct blob12 Interpolate();
    struct blob12 Interpolate(float);
    struct blob12 Interpolate(void*, void*, float);
    struct blob12 Interpolate(void*, void*);
    bool FindPointOnSpline(float, float, bool, float*, NiPoint3*, float);
    float ApproxLength(float, float, unsigned int);
    struct blob12 InterpolateNoZ(void*, void*);
    void* __vecDelDtor(unsigned int);
    char SplinePath[20];
    char Key1[24];
    char Key2[24];
};
struct FUN_006e7e70_shell : public PathingSolution
{
    bool FUN_006e7e70(float, float, bool, float*, NiPoint3*);
};

struct ArrSI
{
};
struct FUN_0052d240_obj
{
    ~FUN_0052d240_obj();
};
PathingGraphNode* FUN_006e8480(PathingSolution*);
struct PathingSplineKeyS
{
    float fData[6];
};
struct OwnS2
{
    PathingSplineKeyS GetLocationAndTangent();
};
struct Dummy_006e8f80
{
    void* FUN_006e8f80(unsigned int);
};
struct PathingLocationExt
{
};
PathingLocationExt& FUN_00717e50(PathingGraphNode*);
struct BSSplineS
{
    void* pData[5];
};
struct FUN_006e7b60
{
    FUN_006e7b60();
    ~FUN_006e7b60();
    bool FindPointAtDistance(float, float, bool, float*, NiPoint3*, float);
    float MeasurePathLength(float, float, unsigned int);
    BSSplineS SplinePath;
    PathingSplineKeyS Key1;
    PathingSplineKeyS Key2;
};

// Walks the spline segments forward or backward from afCurrentParameter by afDist, writing the resulting parameter and point to the output pointers.
// @fnv 0x006e7e70
bool FUN_006e7e70_shell::FUN_006e7e70(float afCurrentParameter, float afDist, bool abForward, float* apNewParameter,
                                      NiPoint3* apNewPoint)
{
    if (!::GetObjectFlags((char*)this))
        return false;
    if (abForward)
    {
        bool bfound;
        int isize = ::GetObjectFlags((char*)this) - 1;
        if (afCurrentParameter >= isize)
        {
            if (apNewParameter)
                *apNewParameter = isize;
            if (apNewPoint)
                *apNewPoint = reinterpret_cast<::TaskQueueInterface *>((void *)&(FUN_00717e50(((::PathingGraphNode *)(reinterpret_cast<::S_FUN_006b05a0 *>((this))->FUN_006b05a0())))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>());
            return false;
        }
        int icurrentSpline = (int)afCurrentParameter;
        float fcurrentParam = afCurrentParameter;
        float fdist = afDist;
        FUN_006e7b60 spline;
        reinterpret_cast<::FUN_006e8450_shell *>(&(spline))->FUN_006e8450(
            (void *)&(const ::fnv_006e7e70::PathingSplineKeyS &)(((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline))->GetLocationAndTangent()),
            (void *)&(const ::fnv_006e7e70::PathingSplineKeyS &)(((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline + 1))->GetLocationAndTangent()));
        bfound = spline.FindPointAtDistance(fcurrentParam - icurrentSpline, fdist, abForward, apNewParameter,
                                            apNewPoint, 1.0f);
        while (!bfound)
        {
            fdist -= spline.MeasurePathLength(fcurrentParam - icurrentSpline, 1.0f, 2);
            ++icurrentSpline;
            fcurrentParam = icurrentSpline;
            if (icurrentSpline >= isize - 1)
            {
                if (apNewParameter)
                    *apNewParameter = isize;
                if (apNewPoint)
                    *apNewPoint = reinterpret_cast<::TaskQueueInterface *>((void *)&(FUN_00717e50(((::PathingGraphNode *)(reinterpret_cast<::S_FUN_006b05a0 *>((this))->FUN_006b05a0())))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>());
                return false;
            }
            reinterpret_cast<::FUN_006e8450_shell *>(&(spline))->FUN_006e8450(
                (void *)&(const ::fnv_006e7e70::PathingSplineKeyS &)(((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline))->GetLocationAndTangent()),
                (void *)&(const ::fnv_006e7e70::PathingSplineKeyS &)(((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline + 1))->GetLocationAndTangent()));
            bfound = spline.FindPointAtDistance(0.0f, fdist, abForward, apNewParameter, apNewPoint, 1.0f);
        }
        if (apNewParameter)
            *apNewParameter += icurrentSpline;
        return true;
    }
    else
    {
        bool bfound;
        int isize = ::GetObjectFlags((char*)this) - 1;
        if (afCurrentParameter <= 0.0)
        {
            if (apNewParameter)
                *apNewParameter = 0.0f;
            if (apNewPoint)
                *apNewPoint = reinterpret_cast<::TaskQueueInterface *>((void *)&(FUN_00717e50(FUN_006e8480(this))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>());
            return false;
        }
        int icurrentSpline = (int)afCurrentParameter;
        if (icurrentSpline < 0)
            icurrentSpline = 0;
        if (icurrentSpline >= (int)((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&member2)))->GetName())) - 1)
            --icurrentSpline;
        float fcurrentParam = afCurrentParameter;
        float fdist = afDist;
        FUN_006e7b60 spline;
        reinterpret_cast<::FUN_006e8450_shell *>(&(spline))->FUN_006e8450(
            (void *)&(const ::fnv_006e7e70::PathingSplineKeyS &)(((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline))->GetLocationAndTangent()),
            (void *)&(const ::fnv_006e7e70::PathingSplineKeyS &)(((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline + 1))->GetLocationAndTangent()));
        bfound = spline.FindPointAtDistance(fcurrentParam - icurrentSpline, fdist, abForward, apNewParameter,
                                            apNewPoint, 1.0f);
        while (!bfound)
        {
            fdist -= spline.MeasurePathLength(0.0f, fcurrentParam - icurrentSpline, 2);
            --icurrentSpline;
            fcurrentParam = icurrentSpline + 1;
            if (icurrentSpline < 0)
            {
                if (apNewParameter)
                    *apNewParameter = 0.0f;
                if (apNewPoint)
                    *apNewPoint = reinterpret_cast<::TaskQueueInterface *>((void *)&(FUN_00717e50(FUN_006e8480(this))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>());
                return false;
            }
            reinterpret_cast<::FUN_006e8450_shell *>(&(spline))->FUN_006e8450(
                (void *)&(const ::fnv_006e7e70::PathingSplineKeyS &)(((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline))->GetLocationAndTangent()),
                (void *)&(const ::fnv_006e7e70::PathingSplineKeyS &)(((OwnS2*)((Dummy_006e8f80*)&member2)->FUN_006e8f80(icurrentSpline + 1))->GetLocationAndTangent()));
            bfound = spline.FindPointAtDistance(1.0f, fdist, abForward, apNewParameter, apNewPoint, 1.0f);
        }
        if (apNewParameter)
            *apNewParameter += icurrentSpline;
        return true;
    }
}
}  // namespace fnv_006e7e70

struct ArrHelper
{
};
struct FUN_006e8480_shell
{
    char _pad[32];
    ArrHelper m;
    void* FUN_006e8480();
};
// Returns 0 when m.FUN_0076b610() is true, otherwise returns m.FUN_006e8fc0().
// @fnv 0x006e8480
void* FUN_006e8480_shell::FUN_006e8480()
{
    if (reinterpret_cast<::FUN_0076b610_Class *>((void *)&(m))->FUN_0076b610())
    {
        return 0;
    }
    return reinterpret_cast<::FUN_006e8fc0_Class *>(&(m))->FUN_006e8fc0();
}

struct HelperA
{
    char data[16];
};
struct HelperB
{
    char data[32];
};
struct MyClass
{
    char _0[8];
    HelperA ha;
    int m18;
    int m1c;
    HelperB hb;
    unsigned char m40;
    void FUN_006e8ab0(MyClass* p);
};
// @fnv 0x006e8ab0
void MyClass::FUN_006e8ab0(MyClass* apTarget)
{
    apTarget->m18 = m18;
    apTarget->m1c = m1c;
    apTarget->m40 = m40;
    reinterpret_cast<::FUN_006e9410_class *>(&(ha))->FUN_006e9410(&apTarget->ha);
    reinterpret_cast<::FUN_006e9470_cls *>(&(hb))->FUN_006e9470((::FUN_006e9470_Helper *)(void *)(&apTarget->hb));
}

struct PathingGraphNode;
struct BSSimpleArray_PathingNode_1024
{
    void* m_pVtbl;
    char* m_pBase;
    PathingGraphNode* FUN_006e8f80(unsigned int aiIndex);
};
// @fnv 0x006e7970
void* FUN_006e7970_shell::FUN_006e7970(unsigned int aiIndex)
{
    return ((void *)(reinterpret_cast<::BSSimpleArray_PathingNode_1024 *>((((Dummy_006e8f80*)&this->member2)))->FUN_006e8f80(aiIndex)));
}
// @fnv 0x006e8fa0
bool S3e60::FUN_006e8fa0(unsigned int auiFlag)
{
    return ((bool)(reinterpret_cast<::BSSimpleArray_PathingNode_1024 *>((void *)this)->FUN_006e8f80(auiFlag)));
}
// @fnv 0x006e8f80
PathingGraphNode* BSSimpleArray_PathingNode_1024::FUN_006e8f80(unsigned int aiIndex)
{
    return (PathingGraphNode*)(m_pBase + aiIndex * 0x3C);
}

namespace fnv_006e9ab0 {
struct RetS
{
    int _a[3];
};
struct OwnS
{
    char _pad[48];
    RetS FUN_006e9ab0(float);
    RetS FUN_006e7d60(std::intptr_t, std::intptr_t);
};
// @fnv 0x006e9ab0
RetS OwnS::FUN_006e9ab0(float f)
{
    ::FUN_006e7c20(this, f);
    return FUN_006e7d60((std::intptr_t)((char*)this + 0x14), (std::intptr_t)((char*)this + 0x2c));
}
}  // namespace fnv_006e9ab0

namespace fnv_006e7a10 {
struct blob12
{
    char b[12];
};
struct SplineInterpolator
{
    void SetParameter(float);
    void SetKeyData(void*, void*);
    struct blob12 Interpolate();
    struct blob12 Interpolate(float);
    struct blob12 Interpolate(void*, void*, float);
    struct blob12 Interpolate(void*, void*);
    bool FindPointOnSpline(float, float, bool, float*, NiPoint3*, float);
    float ApproxLength(float, float, unsigned int);
    struct blob12 InterpolateNoZ(void*, void*);
    void* __vecDelDtor(unsigned int);
    char SplinePath[20];
    char Key1[24];
    char Key2[24];
};
struct FUN_006e7a10_shell : public PathingSolution
{
    void GetLocationAtSplineParameter(float, NiPoint3*);
};

struct StageItemNode;
struct FUN_006e7970_shell
{
};
struct NP3S
{
    float x;
    float y;
    float z;
};
struct LocS
{
};
struct M24
{
    float k[6];
};
struct RetS
{
    float x;
    float y;
    float z;
};
struct OwnS2
{
    M24 GetLocationAndTangent();
};
struct FUN_0052d240_obj
{
    ~FUN_0052d240_obj();
    int SplinePath[5];
    int Key1[6];
    int Key2[6];
};
struct FUN_006e7b60 : public FUN_0052d240_obj
{
    FUN_006e7b60();
};
struct OwnS
{
    RetS FUN_006e7cc0(const M24&, const M24&);
};

// Clamps the spline parameter to the last node and returns the interpolated location between the surrounding nodes into aOutLoc.
// @fnv 0x006e7a10
void FUN_006e7a10_shell::GetLocationAtSplineParameter(float afCurrentSplineParameter, NiPoint3* aOutLoc)
{
    unsigned int uiNodeIndex = (int)afCurrentSplineParameter;
    float remainder = afCurrentSplineParameter - uiNodeIndex;
    int isize = ::GetObjectFlags((char*)this) - 1;
    if ((int)uiNodeIndex >= isize)
    {
        *(NP3S*)aOutLoc = (*(::fnv_006e7a10::NP3S *)&(reinterpret_cast<::TaskQueueInterface *>((((LocS*)((::fnv_006e7a10::StageItemNode *)(reinterpret_cast<::BaseProcess *>((reinterpret_cast<::FUN_006e7970_shell *>((((FUN_006e7970_shell*)this)))->FUN_006e7970(isize)))->GetCurrentProcessData())))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>())));
        return;
    }
    FUN_006e7b60 spline;
    ::FUN_006e7c20(&spline, remainder);
    *(RetS*)aOutLoc =
        ((OwnS*)&spline)
            ->FUN_006e7cc0(
                ((OwnS2*)reinterpret_cast<::FUN_006e7970_shell *>((((FUN_006e7970_shell*)this)))->FUN_006e7970(uiNodeIndex))->GetLocationAndTangent(),
                ((OwnS2*)reinterpret_cast<::FUN_006e7970_shell *>((((FUN_006e7970_shell*)this)))->FUN_006e7970(uiNodeIndex + 1))->GetLocationAndTangent());
}
}  // namespace fnv_006e7a10

namespace fnv_006e84b0 {
struct blob12
{
    char b[12];
};
struct SplineInterpolator
{
    void SetParameter(float);
    void SetKeyData(void*, void*);
    struct blob12 Interpolate();
    struct blob12 Interpolate(float);
    struct blob12 Interpolate(void*, void*, float);
    struct blob12 Interpolate(void*, void*);
    bool FindPointOnSpline(float, float, bool, float*, NiPoint3*, float);
    float ApproxLength(float, float, unsigned int);
    struct blob12 InterpolateNoZ(void*, void*);
    void* __vecDelDtor(unsigned int);
    char SplinePath[20];
    char Key1[24];
    char Key2[24];
};
struct FUN_006e84b0_shell : public PathingSolution
{
    float GetSplineLengthAtParameter(float);
};

struct M24
{
    float f[6];
};
struct OwnS2
{
    M24 GetLocationAndTangent();
};
struct FUN_006e7b60
{
    FUN_006e7b60();
    float fData[17];
};
struct FUN_0052d240_obj : public FUN_006e7b60
{
    FUN_0052d240_obj() : FUN_006e7b60()
    {}
    ~FUN_0052d240_obj();
};
struct FUN_006e8450_shell
{
};
struct FUN_006e9af0_S
{
    float MeasurePathLength(float, float, unsigned int);
};
struct FUN_006e7970_shell
{
};
struct FUN_008b6800_S
{
};
struct FUN_006e78d0_S
{
};

// @fnv 0x006e84b0
float FUN_006e84b0_shell::GetSplineLengthAtParameter(float afParameter)
{
    if (::GetObjectFlags((char *)(((FUN_008b6800_S*)this))) == 0)
        return 0.0f;
    if (afParameter >= ::GetObjectFlags((char *)(((FUN_008b6800_S*)this))) - 1)
        return reinterpret_cast<::fnv_006e78d0::FUN_006e78d0_shell *>((((FUN_006e78d0_S*)this)))->GetTotalPathLength();
    int inode = (int)afParameter;
    float ftotalLength = 0.0f;
    FUN_0052d240_obj spline;
    for (int i = 0; i < inode; ++i)
    {
        reinterpret_cast<::FUN_006e8450_shell *>((((FUN_006e8450_shell*)&spline)))->FUN_006e8450((void *)&(const ::fnv_006e84b0::M24 &)(((::fnv_006e84b0::OwnS2 *)(reinterpret_cast<::FUN_006e7970_shell *>((((FUN_006e7970_shell*)this)))->FUN_006e7970(i)))->GetLocationAndTangent()),
                           (void *)&(const ::fnv_006e84b0::M24 &)(((::fnv_006e84b0::OwnS2 *)(reinterpret_cast<::FUN_006e7970_shell *>((((FUN_006e7970_shell*)this)))->FUN_006e7970(i + 1)))->GetLocationAndTangent()));
        ftotalLength += ((FUN_006e9af0_S*)&spline)->MeasurePathLength(0.0f, 1.0f, 2);
    }
    reinterpret_cast<::FUN_006e8450_shell *>((((FUN_006e8450_shell*)&spline)))->FUN_006e8450((void *)&(const ::fnv_006e84b0::M24 &)(((::fnv_006e84b0::OwnS2 *)(reinterpret_cast<::FUN_006e7970_shell *>((((FUN_006e7970_shell*)this)))->FUN_006e7970(inode)))->GetLocationAndTangent()),
                       (void *)&(const ::fnv_006e84b0::M24 &)(((::fnv_006e84b0::OwnS2 *)(reinterpret_cast<::FUN_006e7970_shell *>((((FUN_006e7970_shell*)this)))->FUN_006e7970(inode + 1)))->GetLocationAndTangent()));
    ftotalLength += ((FUN_006e9af0_S*)&spline)->MeasurePathLength(0.0f, afParameter - inode, 2);
    return ftotalLength;
}
}  // namespace fnv_006e84b0

namespace fnv_006e8680 {
void __cdecl FUN_005330e0(float&, float, float);
struct FUN_006e7990_shell
{
    float FindSegmentAtFraction(float, float, unsigned int*);
};
// @fnv 0x006e8680
float FUN_006e7990_shell::FindSegmentAtFraction(float afPosition, float afScale, unsigned int* piNode)
{
    bool bFound;
    float fTotal;
    float fDistance;
    float fSequenceTimeRatio;
    FUN_005330e0(afPosition, 0.0f, 1.0f);
    fDistance = afPosition * afScale;
    fTotal = 0.0f;
    bFound = false;
    *piNode = 0;
    fSequenceTimeRatio = 0.0f;
    for (unsigned int i = 0; i < ((int)(::GetObjectFlags((char *)this))) - 1; ++i)
    {
        float fSeg = reinterpret_cast<::FUN_006e7990_shell *>(this)->FUN_006e7990(i);
        if (fTotal + fSeg >= fDistance)
        {
            *piNode = i;
            fSequenceTimeRatio = fSeg != ::_DAT_01012060 ? (fDistance - fTotal) / fSeg : 0.0;
            bFound = true;
            break;
        }
        fTotal += fSeg;
    }
    if (!bFound)
    {
        *piNode = ((int)(::GetObjectFlags((char *)this))) - 2;
        fSequenceTimeRatio = 1.0f;
    }
    return *piNode + fSequenceTimeRatio;
}
}  // namespace fnv_006e8680

struct Actor;
struct BGSSaveFormBuffer;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiQuaternion;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    void SetChangeFlags(struct blob4);
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
struct PathingAvoidanceNode
{
    float GetAvoidanceAtPoint(NiPoint3*);
    int GetType();
    void* GetPoint1();
    void* GetPoint2();
    float GetRadius();
    float GetCost();
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    NiPoint3 m_kLocation;
    NiPoint3 TwoComponentVector;
    float fRadius;
    float m_fPathingCostCur;
    int eType;
};
struct FUN_006e8d50_shell : public PathingSolution
{
    void FUN_006e8d50(BGSLoadFormBuffer*);
};

struct FUN_006f5100_shell
{
};
struct FUN_006e23b0_shell
{
};
struct FUN_006dc910_shell
{
    void LoadPathingAvoidNode(BGSLoadFormBuffer*);
};
struct FUN_006e90a0_shell
{
};
struct FUN_006e9280_shell
{
    void FUN_006e9280(unsigned int, bool);
};
struct FUN_006a1400_shell
{
};
struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};
struct FUN_006a7ad0_shell
{
    void** m_ppVirtualMethodTable;
    unsigned int* pBuffer;
    unsigned int iSize;
    unsigned int iCapacity;
};
struct PathingAvoidNodeArray
{
    int pad[6];
    PathingAvoidNodeArray();
    ~PathingAvoidNodeArray();
    void SetSize(unsigned int, bool);
};

// Loads pathing solution data from a BGSLoadFormBuffer: fixed fields, then virtual nodes, pathing nodes, avoid nodes, and door IDs when version >= 0x12.
// @fnv 0x006e8d50
void FUN_006e8d50_shell::FUN_006e8d50(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_bHasValidPath), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->member1.firstValue), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->member1.secondValue), 4);
    {
        unsigned int isaveGameCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apLoadGameBuffer))->FUN_00864a60();
        reinterpret_cast<::FUN_006e90a0_class *>((((FUN_006e90a0_shell*)&this->member1)))->FUN_006e90a0(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            FUN_006f5100_shell* virtualNode = ((::FUN_006f5100_shell *)(reinterpret_cast<::fnv_006e8f60::PathBuilder *>((((FUN_006e90a0_shell*)&this->member1)))->FUN_006e8f60(i)));
            reinterpret_cast<::LoadHolder6F51 *>((virtualNode))->FUN_006f5100(apLoadGameBuffer);
        }
    }
    {
        unsigned int isaveGameCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apLoadGameBuffer))->FUN_00864a60();
        ((FUN_006e9280_shell*)((char*)this + 0x20))->FUN_006e9280(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            FUN_006e23b0_shell* pathingNode = ((::FUN_006e23b0_shell *)(reinterpret_cast<::S3e60 *>((((FUN_006e9280_shell*)&this->member2)))->FUN_006e8fa0(i)));
            reinterpret_cast<::LoadedRefHolder *>((pathingNode))->FUN_006e23b0(apLoadGameBuffer);
        }
    }
    PathingAvoidNodeArray avoidNodeArray;
    {
        unsigned int isaveGameCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apLoadGameBuffer))->FUN_00864a60();
        reinterpret_cast<::BSSimpleArray_PathingAvoidNode_1024 *>(&(avoidNodeArray))->SetSize(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            FUN_006dc910_shell* avoidNode = ((::FUN_006dc910_shell *)(reinterpret_cast<::S3e60 *>((((FUN_006a1400_shell*)&avoidNodeArray)))->FUN_006a1400(i)));
            avoidNode->LoadPathingAvoidNode(apLoadGameBuffer);
        }
    }
    if (apLoadGameBuffer->GetVersion() >= 0x12)
    {
        unsigned int isaveGameCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apLoadGameBuffer))->FUN_00864a60();
        reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>((((_Mem_20a4*)&this->member3)))->FUN_006f2290(isaveGameCount, true);
        for (unsigned int i = 0; i < isaveGameCount; i++)
        {
            unsigned int* puiDoorID = &((FUN_006a7ad0_shell*)((char*)this + 0x30))->pBuffer[i];
            reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0(puiDoorID);
        }
    }
}

struct PathVec3
{
    float x;
    float y;
    float z;
};

struct PathVecHelper
{
};

struct PathMagHelper
{
};

void PathClampHelper(float* t, float lo, float hi);

class FUN_006e9af0_cls
{
  public:
    float MeasurePathLength(float a, float b, unsigned int n);
};

// @fnv 0x006e9af0
float FUN_006e9af0_cls::MeasurePathLength(float afStart, float afEnd, unsigned int uiSteps)
{
    float sum_2;
    PathVec3 p9;
    unsigned int idx;
    PathVec3 p3;
    PathVec3 p5;
    float t;

    *reinterpret_cast<::fnv_006e9ab0::RetS *>(&p9) = reinterpret_cast<::fnv_006e9ab0::OwnS *>((this))->FUN_006e9ab0(afStart);
    sum_2 = 0.0f;
    for (idx = 0; idx < uiSteps; idx++)
    {
        t = (afEnd - afStart) * (float)(idx + 1) / (float)uiSteps + afStart;
        PathClampHelper(&t, 0.0f, 1.0f);
        *reinterpret_cast<::fnv_006e9ab0::RetS *>(&p5) = reinterpret_cast<::fnv_006e9ab0::OwnS *>((this))->FUN_006e9ab0(t);
        reinterpret_cast<::FUN_00439ef0_class *>((((PathVecHelper*)&p5)))->FUN_00439ef0((::NiPoint3 *)(::PathVec3 *)(&p3), (*(const ::NiPoint3 *)(&p9)));
        sum_2 = sum_2 + reinterpret_cast<::NiPoint3 *>((((PathMagHelper*)&p3)))->ComputeMagnitude();
        p9 = p5;
    }
    return sum_2;
}

struct Vec
{
    float x, y, z;
    Vec();
};

struct Key
{
    float x, y, z, tx, ty, tz;
};
struct Node
{
    Key GetLocationAndTangent();
};
struct Location
{
};
struct Tail
{
};
struct SplinePath
{
    float unk00, unk04, unk08, unk0c, unk10;
    SplinePath();
    ~SplinePath();
    Key first, second;

    bool FindPointOnSpline(float, float, bool, float*, Vec*, float);
};
struct Solution
{
    Vec GetPointAtDistance(float position, float distance);
};
struct SaveBuffer
{
};
struct SaveEntryA
{
};
struct SaveEntryB
{
};
struct SaveEntryC
{
    void SaveGame(SaveBuffer*);
};
struct CountView
{
};
struct SaveArrayA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct SaveArrayB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct SaveArrayD
{
    void** m_ppVirtualMethodTable;
    unsigned int* pBuffer;
    int unk08;
    int unk0c;
};
struct AvoidArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    AvoidArray();
    ~AvoidArray();
};
struct SaveSolution
{
    int unk00;
    int unk04;
    SaveArrayA first;
    int unk18;
    int unk1c;
    SaveArrayB second;
    SaveArrayD fourth;
    unsigned char flags;
    void FUN_006e8b10(SaveBuffer* buffer);
};
// Writes flags, unk18 and unk1c to the buffer, then serializes the counts and entries of first, second, a local AvoidArray and fourth.
// @fnv 0x006e8b10
void SaveSolution::FUN_006e8b10(SaveBuffer* buffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&flags, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk18, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk1c, 4, 0);
    unsigned int countA9 = &first ? ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((CountView*)&first)))->GetName())) : 0;
    reinterpret_cast<::BGSSaveGameBuffer *>((buffer))->FUN_00865f60(countA9);
    for (unsigned int indexA = 0; indexA < countA9; ++indexA)
    {
        SaveEntryA* entryA8 = ((::SaveEntryA *)(reinterpret_cast<::fnv_006e8f60::PathBuilder *>(&(first))->FUN_006e8f60(indexA)));
        reinterpret_cast<::FUN_006f50b0_shell *>((entryA8))->FUN_006f50b0((::BGSSaveFormBuffer *)(buffer));
    }
    {
        unsigned int countB8 = &second ? ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((CountView*)&second)))->GetName())) : 0;
        reinterpret_cast<::BGSSaveGameBuffer *>((buffer))->FUN_00865f60(countB8);
        for (unsigned int indexB6 = 0; indexB6 < countB8; ++indexB6)
        {
            SaveEntryB* entryB9 = ((::SaveEntryB *)(reinterpret_cast<::S3e60 *>(&(second))->FUN_006e8fa0(indexB6)));
            reinterpret_cast<::FUN_006e2350_shell *>((entryB9))->FUN_006e2350((::BGSSaveFormBuffer *)(buffer));
        }
    }
    AvoidArray avoided5;
    {
        unsigned int countCA = &avoided5 ? ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((CountView*)&avoided5)))->GetName())) : 0;
        reinterpret_cast<::BGSSaveGameBuffer *>((buffer))->FUN_00865f60(countCA);
        for (unsigned int indexC5 = 0; indexC5 < countCA; ++indexC5)
        {
            SaveEntryC* entryC2 = ((::SaveEntryC *)(reinterpret_cast<::S3e60 *>(&(avoided5))->FUN_006a1400(indexC5)));
            reinterpret_cast<::FUN_006dc890_Class *>((entryC2))->FUN_006dc890((::BGSSaveFormBuffer *)(buffer));
        }
    }
    {
        unsigned int countD8 = &fourth ? ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((CountView*)&fourth)))->GetName())) : 0;
        reinterpret_cast<::BGSSaveGameBuffer *>((buffer))->FUN_00865f60(countD8);
        for (unsigned int indexD = 0; indexD < countD8; ++indexD)
        {
            unsigned int& entryD3 = fourth.pBuffer[indexD];
            reinterpret_cast<::FUN_00865db0_shell *>((buffer))->FUN_00865db0(entryD3, 0);
        }
    }
}

void __cdecl FUN_005330e0(float& arfValue, float afMin, float afMax);

struct FUN_004a7290_point
{
};

struct FUN_006e9830_shell
{
    char pad[0x14];
    NiPoint3 kStart;
    char padCur[0x2c - 0x20];
    NiPoint3 kEnd;
    NiPoint3 FUN_006e9ab0(float afT);
    bool FindPointAtDistance(float afT, float afDistance, bool abForward, float* apfOutT, NiPoint3* apkOutPoint,
                             float afTolerance);
};
// Walks the spline nodes from the given position until the remaining distance is consumed, returning the interpolated point or the tail location.
// @fnv 0x006e8790
Vec Solution::GetPointAtDistance(float position, float distance)
{
    if (!::GetObjectFlags((char *)this))
        return (const Vec&)::NiPoint3::ZERO;
    if (position >= ::GetObjectFlags((char *)this) - 1)
        return (*(::Vec *)&(reinterpret_cast<::TaskQueueInterface *>((((::Location *)(reinterpret_cast<::BaseProcess *>((((::Tail *)(reinterpret_cast<::S_FUN_006b05a0 *>(this)->FUN_006b05a0()))))->GetCurrentProcessData()))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>())));
    float remaining7 = distance;
    int index = (int)position;
    float parameterTmp = position - index;
    Key next2 = ((::Node *)(reinterpret_cast<::FUN_006e7970_shell *>(this)->FUN_006e7970(index + 1)))->GetLocationAndTangent();
    Key current = ((::Node *)(reinterpret_cast<::FUN_006e7970_shell *>(this)->FUN_006e7970(index)))->GetLocationAndTangent();
    SplinePath spline3;
    reinterpret_cast<::FUN_006e8450_shell *>((((SplinePath*)&spline3)))->FUN_006e8450(&current, &next2);
    float lengthVal = reinterpret_cast<::FUN_006e9af0_cls *>((((SplinePath*)&spline3)))->MeasurePathLength(parameterTmp, 1.0f, 2);
    while (index < (int)(::GetObjectFlags((char *)this) - 2) && lengthVal < remaining7)
    {
        remaining7 -= lengthVal;
        index = index + 1;
        ::FUN_006e7d10((::_S_006e7d10 *)&(current), (*(::_Arg_006e7d10 *)&(next2)));
        ::FUN_006e7d10((::_S_006e7d10 *)&(next2), (*(::_Arg_006e7d10 *)&(const ::Key &)(((::Node *)(reinterpret_cast<::FUN_006e7970_shell *>(this)->FUN_006e7970(index + 1)))->GetLocationAndTangent())));
        reinterpret_cast<::FUN_006e8450_shell *>((((SplinePath*)&spline3)))->FUN_006e8450(&current, &next2);
        parameterTmp = 0.0f;
        lengthVal = reinterpret_cast<::FUN_006e9af0_cls *>((((SplinePath*)&spline3)))->MeasurePathLength(0.0f, 1.0f, 2);
    }
    if (lengthVal > remaining7)
    {
        float result6;
        Vec point2;
        if (!(int)reinterpret_cast<::FUN_006e9830_shell *>((((SplinePath*)&spline3)))->FindPointAtDistance(parameterTmp, remaining7, true, &result6, (::NiPoint3 *)(::Vec *)(&point2), 10.0f))
        {
            point2 = (const Vec&)next2;
        }
        return point2;
    }
    else
    {
        return (*(::Vec *)&(reinterpret_cast<::TaskQueueInterface *>((((::Location *)(reinterpret_cast<::BaseProcess *>((((::Tail *)(reinterpret_cast<::S_FUN_006b05a0 *>(this)->FUN_006b05a0()))))->GetCurrentProcessData()))))->QueueActorAnimationTask(::ResultSlot<::NiPoint3>())));
    }
}

// Binary-searches the segment parameter so the point is within tolerance of afDistance from the point at afT, writing the found t and point to the outputs.
// @fnv 0x006e9830
bool FUN_006e9830_shell::FindPointAtDistance(float afT, float afDistance, bool abForward, float* apfOutT,
                                             NiPoint3* apkOutPoint, float afTolerance)
{
    if (afDistance <= afTolerance)
    {
        *apkOutPoint = FUN_006e9ab0(afT);
        *apfOutT = afT;
        return true;
    }

    float kFMaxSqr = (afDistance + afTolerance) * (afDistance + afTolerance);
    float fNewMinSqr = (afDistance - afTolerance) * (afDistance - afTolerance);
    FUN_005330e0(afT, 0.0f, 1.0f);

    float fMin;
    float fHigh2;
    float fCurrentAmountNext;
    if (abForward)
    {
        fMin = afT;
        fCurrentAmountNext = fHigh2 = 1.0f;
    }
    else
    {
        fMin = 0.0f;
        fHigh2 = afT;
        fCurrentAmountNext = fMin;
    }

    NiPoint3 _kOrigin = FUN_006e9ab0(afT);
    NiPoint3 kPoint = abForward ? kEnd : kStart;
    bool bFound = false;
    while (!bFound)
    {
        kPoint = FUN_006e9ab0(fCurrentAmountNext);
        NiPoint3 kOffset = _kOrigin - kPoint;
        float _fLength = reinterpret_cast<::TESCombatStyle *>((void *)(((const FUN_004a7290_point*)&kOffset)))->UpdateCombatStyle();
        if ((_fLength < fNewMinSqr && abForward) || (_fLength > kFMaxSqr && !abForward))
        {
            if (fCurrentAmountNext >= 0.99f)
            {
                bFound = false;
                break;
            }
            else
                fMin = fCurrentAmountNext;
        }
        else if ((_fLength > kFMaxSqr && abForward) || (_fLength < fNewMinSqr && !abForward))
        {
            if (fCurrentAmountNext <= 0.01f)
            {
                bFound = false;
                break;
            }
            else
                fHigh2 = fCurrentAmountNext;
        }
        else
        {
            bFound = true;
            break;
        }
        fCurrentAmountNext = (fMin + fHigh2) * 0.5;
    }

    if (!bFound)
    {
        if (abForward)
        {
            *apfOutT = 1.0f;
            *apkOutPoint = kEnd;
        }
        else
        {
            *apfOutT = 0.0f;
            *apkOutPoint = kStart;
        }
        return false;
    }
    else
    {
        *apfOutT = fCurrentAmountNext;
        *apkOutPoint = kPoint;
        return true;
    }
}

#include "generated/data/fallout_shared/pathfinding/pathingsolution.inc"
