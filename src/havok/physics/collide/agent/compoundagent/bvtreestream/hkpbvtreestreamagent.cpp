
// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
#include "fnv/symbols_00c85000.h"
#include "havok/hkMemoryRouter.h"
#include <cstddef>
#include <new>
#include "fnv/decl/Agent.h"
#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/decl/FUN_00d43880_cls.h"
#include "fnv/decl/FUN_00d440f0.h"
#include "fnv/decl/S_00d43cd0.h"
#include "fnv/symbols_00d06000.h"
#include "fnv/symbols_00d2d000.h"
#include "fnv/symbols_00d2e000.h"
#include "fnv/symbols_00d30000.h"
#include "fnv/symbols_00d31000.h"
#include "fnv/symbols_00d97000.h"
#include "fnv/symbols_00da3000.h"
#include "fnv/symbols_00da4000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010ce000.h"
void __cdecl FUN_00d312f0(void*, void*, void*, void*);

struct FUN_00d2dd30_class
{
    void FUN_00d2dd30(void* a, void* b, void* c, void* d);
};

// @fnv 0x00d2dd30
void FUN_00d2dd30_class::FUN_00d2dd30(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    FUN_00d312f0(apArg1, apArg2, apArg3, apArg4);
}


struct FUN_00d2ddd0_class
{
    void FUN_00d2ddd0(void* a);
};

// @fnv 0x00d2ddd0
void FUN_00d2ddd0_class::FUN_00d2ddd0(void* aiValue)
{
    ::FUN_00da3510((*(::AgentSectorPointerArray *)((char*)this + 0x30)), (*static_cast<::CollisionAgentContext *>(aiValue)));
}

extern "C" void __cdecl FUN_00d31110(void*, void*, void*, void*);
// @fnv 0x00d2dd50
extern "C" void FUN_00d2dd50(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    FUN_00d31110(apArg1, apArg2, apArg3, apArg4);
}

struct OperationAdapter
{
    void FUN_00d2dd70(void* a, void* b, void* c, void* d, void* e);
};
// Forwards all five arguments to FUN_00d30f50.
// @fnv 0x00d2dd70
void OperationAdapter::FUN_00d2dd70(void* a, void* b, void* c, void* d, void* e)
{
    ::FUN_00d30f50((*(const ::S_00d30f50_CdBody *)(a)), (*(const ::S_00d30f50_CdBody *)(b)), (*(const ::S_00d30f50_LinearCastInput *)(c)), (*(::S_00d30f50_CdPointCollector *)(d)), (::S_00d30f50_CdPointCollector *)(e));
}

struct FUN_00d2dda0_class
{
    virtual void finish(int);
    int unk04;
    void* unk08;
    void* unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void FUN_00d2dda0(void* value);
};
// Passes unk0c, unk08 and value to FUN_00da42b0 with &unk30, then calls finish(1).
// @fnv 0x00d2dda0
void FUN_00d2dda0_class::FUN_00d2dda0(void* value)
{
    ::FUN_00da42b0((::BlockPoolArray *)(void *)(&unk30), static_cast<::S_00da40e0_Dispatcher *>(unk0c), static_cast<::S_00da40e0_ContactMgr *>(unk08), (*static_cast<::S_00da40e0_ConstraintOwner *>(value)));
    finish(1);
}

struct FUN_00d2ddf0_Class
{
    void FUN_00d2ddf0(float a, float b, void* c);
};
// Calls FUN_00da35f0 with the subobject at offset 0x30 of this object and the three arguments.
// @fnv 0x00d2ddf0
void FUN_00d2ddf0_Class::FUN_00d2ddf0(float a, float b, void* c)
{
    ::FUN_00da35f0((::Da35Stream ***)(void *)((char*)this + 0x30), a, b, (void **)(c));
}

struct RefObj
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct Obj : RefObj
{
    int pad[14];
    Obj* FUN_00d2def0(int, int, int, int);
};

inline void* hkAlloc(int n)
{
    RefObj* p = static_cast<RefObj*>(hkMemoryRouter::getInstance().heap().blockAlloc(n));
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}

// Allocates a sizeof(Obj) block from the audio heap and calls FUN_00d2def0 on it with the four arguments, returning its result.
// @fnv 0x00d2df50
void* __cdecl FUN_00d2df50(int aiArg0, int aiArg1, int aiArg2, int aiArg3)
{
    return ((Obj*)hkAlloc(sizeof(Obj)))->FUN_00d2def0(aiArg0, aiArg1, aiArg2, aiArg3);
}


struct Conversion
{
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};
struct Registry
{
};
// @fnv 0x00d2e760
void FUN_00d2e760(Registry* registry)
{
    Conversion conversionEntry;
    conversionEntry.convert = ((void (&)())::FUN_00d2e680);
    conversionEntry.create = ((void (&)())::FUN_00d2e970);
    conversionEntry.copy = ((void (&)())::FUN_00d2e9b0);
    conversionEntry.destroy = ((void (&)())::FUN_00d2e9f0);
    conversionEntry.enabled = true;
    conversionEntry.supported = true;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((registry))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::Conversion *)(&conversionEntry), 8, 24);
    conversionEntry.convert = ((void (&)())::FUN_00d2df50);
    conversionEntry.create = (void (*)())FUN_00d312f0;
    conversionEntry.copy = (void (*)())FUN_00d31110;
    conversionEntry.destroy = ((void (&)())::FUN_00d30f50);
    conversionEntry.enabled = false;
    conversionEntry.supported = true;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((registry))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::Conversion *)(&conversionEntry), 24, 8);
}

typedef void*(__cdecl* S_00d2e8e0_CreateFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_GetPenetrationsFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_GetClosestPointsFunc)(void*, void*, void*, void*);
typedef void(__cdecl* S_00d2e8e0_LinearCastFunc)(void*, void*, void*, void*, void*);

void FUN_00d2e970(void*, void*, void*, void*);

struct S_00d2e8e0_AgentFuncs
{
    S_00d2e8e0_CreateFunc m_pCreateFunc;
    S_00d2e8e0_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    S_00d2e8e0_GetClosestPointsFunc m_pGetPenetrationsFunc;
    S_00d2e8e0_LinearCastFunc m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct S_00d2e8e0_Dispatcher
{
};

// Fills an agent function table twice and registers it with the dispatcher for type pairs (8,0x16) and (0x16,8).
// @fnv 0x00d2e8e0
void FUN_00d2e8e0(S_00d2e8e0_Dispatcher* dispatcher)
{
    S_00d2e8e0_AgentFuncs f;
    f.m_pCreateFunc = ((void *(&)(void *, void *, void *, void *))::FUN_00d2e7f0);
    f.m_pQueryPenetrationsFunc = FUN_00d2e970;
    f.m_pGetPenetrationsFunc = ((void (&)(void *, void *, void *, void *))::FUN_00d2e9b0);
    f.m_pLinearCastFunc = ((void (&)(void *, void *, void *, void *, void *))::FUN_00d2e9f0);
    f.m_bIsFlipped = true;
    f.m_bIsPredictive = true;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((dispatcher))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(f), 8, 0x16);

    f.m_pCreateFunc = ((void *(&)(void *, void *, void *, void *))::fnv_00d2e5a0::FUN_00d2e5a0);
    f.m_pQueryPenetrationsFunc = (S_00d2e8e0_GetPenetrationsFunc)FUN_00d312f0;
    f.m_pGetPenetrationsFunc = FUN_00d31110;
    f.m_pLinearCastFunc = ((void (&)(void *, void *, void *, void *, void *))::FUN_00d30f50);
    f.m_bIsFlipped = false;
    f.m_bIsPredictive = true;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((dispatcher))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(f), 0x16, 8);
}


struct D2E9B0CollectorBase
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    float m_fEarlyOutDistance;

    D2E9B0CollectorBase() : m_fEarlyOutDistance(::DAT_0104da48)
    {}
};

struct D2E9B0Collector : D2E9B0CollectorBase
{
    void* m_iData;

    D2E9B0Collector(void* iData) : m_iData(iData)
    {}

    virtual void unk00();
    virtual void unk04();
};

// Constructs a D2E9B0Collector from d and passes it with b, a, c to FUN_00d31110.
// @fnv 0x00d2e9b0
void __cdecl FUN_00d2e9b0(void* aiArg1, void* aiArg2, void* aiArg3, void* aiData)
{
    D2E9B0Collector collector(aiData);
    FUN_00d31110(aiArg2, aiArg1, aiArg3, &collector);
}

struct hkpSymmetricAgentFlipCollector
{
    virtual void dispose();
    virtual void collect(float value);
    virtual void process(void* value);
    float threshold;
    void* object;
};
struct Context
{
    void FUN_00d2edd0(void* first, void* second, void* third, void* fourth);
};
// Builds a collector with threshold DAT_0104da48 and object fourth, then calls FUN_00d43880 with second, first, third and the collector.
// @fnv 0x00d2edd0
void Context::FUN_00d2edd0(void* first, void* second, void* third, void* fourth)
{
    hkpSymmetricAgentFlipCollector collector;
    collector.threshold = ::DAT_0104da48;
    collector.object = fourth;
    reinterpret_cast<::FUN_00d43880_cls *>(this)->FUN_00d43880(static_cast<::ShapeHolder *>(second), first, third, &collector);
}

extern "C" const char str_010ce828[];

struct VisitTarget
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void Visit(int kind, const char* name, void* data, unsigned int size, int extra)
    {}
    int unk04;
    char** m_08;
    int unk0C;
    unsigned char m_10;
};

struct PackedBuffer
{
    void* m_ptr;
    unsigned int m_uiItemCount;
    unsigned int m_flag;
};

struct BufOwner
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
    PackedBuffer m_buf;
    void VisitPackedBuffer(VisitTarget* target, int flags);
};

// @fnv 0x00d2de90
void BufOwner::VisitPackedBuffer(VisitTarget* target, int flags)
{
    PackedBuffer* pBuffer = &m_buf;
    unsigned int uiFlags = pBuffer->m_flag;
    if ((uiFlags & 0x80000000u) == 0 || target->m_10 != 0)
    {
        void* p = pBuffer->m_ptr;
        unsigned int uiByteSize = (uiFlags & 0x3fffffffu) * 4;
        int mem = ::fnv_00d06f80::FUN_00d06f80(static_cast<const char*>(p), uiByteSize);
        target->Visit(3, str_010ce828, pBuffer->m_ptr, pBuffer->m_uiItemCount * 4, mem);
    }
    ::FUN_00d97250((::Hdr *)(pBuffer), target->m_08, (::Logger *)(target));
}


struct Collector
{
    const void* vtable;
    char flip;
    void* collector;
};

// Builds a Collector on the stack with the given collector and vtable, then calls FUN_00d312f0 with bodyB, bodyA, arg3 and the Collector.
// @fnv 0x00d2e970
void __cdecl FUN_00d2e970(void* bodyA, void* bodyB, void* arg3, void* orig_collector)
{
    Collector c;
    c.collector = orig_collector;
    c.flip = 0;
    c.vtable = &(*reinterpret_cast<const void * *>(&::DAT_010ce81c));
    FUN_00d312f0(bodyB, bodyA, arg3, &c);
}

struct FUN_00d2eb50_nib
{
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct FUN_00d2eb50_cls
{
    unsigned short m_w00;
    unsigned short m_w02;
    unsigned short m_w04;
    unsigned char m_unk06;
    unsigned char m_unk07;
    unsigned char m_b08;
    unsigned char m_b09;
    FUN_00d2eb50_nib m_nib0a;
    void SwapFields();
};

// @fnv 0x00d2eb50
void FUN_00d2eb50_cls::SwapFields()
{
    unsigned char lo = m_nib0a.lo;
    m_nib0a.lo = m_nib0a.hi;
    m_nib0a.hi = lo;

    unsigned char t = m_b08;
    m_b08 = m_b09;
    m_b09 = t;

    unsigned short* w = (unsigned short*)this;
    unsigned int uiIndex = (unsigned int)m_b08 + (unsigned int)m_b09 - 1;
    unsigned short first = w[0];
    unsigned short usTemp = w[uiIndex];
    w[0] = usTemp;
    w[uiIndex] = first;

    if ((unsigned char)(m_b08 & m_b09) == 2)
    {
        unsigned short a = m_w02;
        m_w02 = m_w04;
        m_w04 = a;
    }
}

namespace fnv_00d2ebb0 {

struct FUN_00d2ebb0_tmp
{
    const void* vt;
    unsigned char flag;
    unsigned int a4;
};

struct FUN_00d2dd30_obj
{
};

struct FUN_00d2ebb0_cls
{
    void DispatchWithFlag(void* a1, void* a2, void* a3, unsigned int a4);
};

// Builds a temporary holding a4 and a zero flag with a vtable pointer, then forwards a2, a1, a3 and the temporary to FUN_00d2dd30.
// @fnv 0x00d2ebb0
void FUN_00d2ebb0_cls::DispatchWithFlag(void* a1, void* a2, void* a3, unsigned int a4)
{
    FUN_00d2ebb0_tmp t;
    t.a4 = a4;
    t.flag = 0;
    t.vt = &::DAT_010ce81c;
    reinterpret_cast<::FUN_00d2dd30_class *>((((FUN_00d2dd30_obj*)this)))->FUN_00d2dd30(a2, a1, a3, &t);
}
}  // namespace fnv_00d2ebb0

struct CpuCallData
{
    void* descriptor;
    float bound;
    void* value;
};
struct CpuObject
{
    void DispatchWithBoundData(void*, void*, void*, void*);
};
// Builds a CpuCallData from fourth, DAT_0104da48 and DAT_010ce7fc, then forwards second, first, third and the data to FUN_00d2dd50.
// @fnv 0x00d2ebf0
void CpuObject::DispatchWithBoundData(void* first, void* second, void* third, void* fourth)
{
    CpuCallData data;
    data.value = fourth;
    data.bound = ::DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    ::FUN_00d2dd50(second, first, third, &data);
}

struct CallTarget_00d2de20
{
    int FUN_00d2de20(int, int, int, int);
};
struct SearchObject
{
    int CallTarget(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d2ec30
int SearchObject::CallTarget(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00d2de20*)this)->FUN_00d2de20((int)arg1, (int)arg0, (int)arg2, (int)arg3);
    return (int)callResult0;
}

namespace fnv_00d2ed70 {
struct CallTarget_00d43f10
{
    int FUN_00d43f10(int, int, int, int);
};
struct SearchObject
{
    int FUN_00d2ed70(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d2ed70
int SearchObject::FUN_00d2ed70(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00d43f10*)this)->FUN_00d43f10((int)arg1, (int)arg0, (int)arg2, (int)arg3);
    return (int)callResult0;
}
}  // namespace fnv_00d2ed70

// Havok style body collector: a virtual table pointer, an "active" flag and a payload pointer.
struct hkpCollectorBase
{
    char active;
    hkpCollectorBase()
    {
        active = 0;
    }
};

struct hkpSymmetricAgentFlipBodyCollector : hkpCollectorBase
{
    virtual void addBody();
    virtual void reset();
    void* payload;
};

// Game side wrapper that fills the collector and hands it to the query routine.
struct FUN_00d43cd0_class
{
    void FUN_00d2ed90(void* a1, void* a2, void* a3, void* a4);
};

// Builds a flip-body collector holding a4 and forwards a2, a1, a3 and the collector to ProcessCollisionEntries.
// @fnv 0x00d2ed90
void FUN_00d43cd0_class::FUN_00d2ed90(void* a1, void* a2, void* a3, void* apPayload)
{
    hkpSymmetricAgentFlipBodyCollector collector;
    collector.payload = apPayload;
    reinterpret_cast<::S_00d43cd0 *>((this))->ProcessCollisionEntries((*(const ::S_00d43cd0_CdBody *)(a2)), (*(const ::S_00d43cd0_CdBody *)(a1)), (*(const ::S_00d43cd0_Input *)(a3)), (*(::S_00d43cd0_Collector *)(&collector)));
}

#include <xmmintrin.h>

struct FUN_00d2de20_obj
{
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual int vSlot10();
};

struct __declspec(align(16)) ArgPack
{
    int m_00;
    void* m_04;
    int unk08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
};

struct FUN_00d2de20_cls
{
    int unk00;
    int unk04;
    int m_08;
    int unk0C;
    __m128 m_10;
    __m128 m_20;
    int m_30;

    void FUN_00d2de20(int a0, FUN_00d2de20_obj** a1, int a2, int a3);
};

// Zeroes m_10 and m_20, builds an ArgPack from a0, a1, a2, m_08, a3 and the vSlot10 result, then calls FUN_00da48e0 with m_30 and the pack.
// @fnv 0x00d2de20
void FUN_00d2de20_cls::FUN_00d2de20(int a0, FUN_00d2de20_obj** a1, int a2, int a3)
{
    m_10 = _mm_setzero_ps();
    m_20 = _mm_setzero_ps();
    ArgPack args;
    int r = (*a1)->vSlot10();
    args.m_00 = a0;
    args.m_04 = a1;
    args.m_10 = a2;
    args.m_14 = m_08;
    args.m_0C = r;
    args.m_18 = a3;
    ::FUN_00da48e0((&m_30), (&args));
}

extern int DAT_010ce838;

struct FUN_00d2def0_cls
{
    const void* m_vptr;
    unsigned short unk04;
    unsigned short m_06;
    void* m_08;
    int m_0c;
    __m128 m_10;
    __m128 m_20;
    int m_30;
    int m_34;
    unsigned int m_38;

    FUN_00d2def0_cls* FUN_00d2def0(void* a1, void* a2, int* a3, void* a4);
};

// Initializes the object's block pool fields, sets m_0c from a3, zeroes m_10 and m_20, and calls InitBlockPool on the pool block.
// @fnv 0x00d2def0
FUN_00d2def0_cls* FUN_00d2def0_cls::FUN_00d2def0(void* a1, void* apUnused, int* piSource, void* a4)
{
    m_06 = 1;
    m_08 = a4;
    m_vptr = &DAT_010ce838;
    int* pBlockPool = &m_30;
    *pBlockPool = 0;
    pBlockPool[1] = 0;
    pBlockPool[2] = 0x80000000;
    m_0c = *piSource;
    m_10 = _mm_setzero_ps();
    m_20 = _mm_setzero_ps();
    ::InitBlockPool((::BlockPoolArray *)(pBlockPool));
    return this;
}


struct __declspec(align(16)) Key_d2e9
{
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union
    {
        __m128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9
{
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    void* m_uiFilterValue;
};


// Copies input, XORs its m_vComponents with DAT_010c44d0, builds a Record_d2e9 with a4, and calls FUN_00d30f50 with an optional second record when a5 is non-zero.
// @fnv 0x00d2e9f0
void __cdecl FUN_00d2e9f0(void* a2, void* a1, const Input_d2e9* input, void* aiRecordValue, void* aiOptionalRecordValue)
{
    Input_d2e9 local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d2e9 rec;
    rec.m_vtbl = &(*reinterpret_cast<unsigned int *>(&::UNK_010ce80c));
    rec.m_fScalar = ::DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = aiRecordValue;

    if (aiOptionalRecordValue != 0)
    {
        Record_d2e9 rec2;
        rec2.m_vtbl = &(*reinterpret_cast<unsigned int *>(&::UNK_010ce80c));
        rec2.m_fScalar = ::DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = aiOptionalRecordValue;
        ::FUN_00d30f50((*static_cast<const ::S_00d30f50_CdBody *>(a1)), (*static_cast<const ::S_00d30f50_CdBody *>(a2)), (*(const ::S_00d30f50_LinearCastInput *)(&local)), (*(::S_00d30f50_CdPointCollector *)(&rec)), (::S_00d30f50_CdPointCollector *)(::Record_d2e9 *)(&rec2));
    }
    else
    {
        ::FUN_00d30f50((*static_cast<const ::S_00d30f50_CdBody *>(a1)), (*static_cast<const ::S_00d30f50_CdBody *>(a2)), (*(const ::S_00d30f50_LinearCastInput *)(&local)), (*(::S_00d30f50_CdPointCollector *)(&rec)), (::S_00d30f50_CdPointCollector *)(::Record_d2e9 *)(0));
    }
}

namespace fnv_00d2ec50 {

extern __m128 DAT_010c4c00;

struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
    void FUN_00d2df90(int a, int b, int c, Simplex* s);
};

struct Agent : AgentBase
{
    void FUN_00d2ec50(int a, int b, int c, Simplex* s);
};

// Calls base FUN_00d2df90 with a and b swapped, post-processes the new simplex vertices, and swaps the dimension fields and ids if the closest distance changed.
// @fnv 0x00d2ec50
void Agent::FUN_00d2ec50(int a, int b, int c, Simplex* apSimplex)
{
    SimplexVertex* v = apSimplex->m_kRayEnd;
    float oldDistance = apSimplex->m_fClosestPointDistanceSquared;
    AgentBase::FUN_00d2df90(b, a, c, apSimplex);
    for (; v < apSimplex->m_kRayEnd; v++)
    {
        const __m128* pb = &v->m_kPointB;
        __m128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != apSimplex->m_fClosestPointDistanceSquared)
    {
        __m128* n = &apSimplex->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = apSimplex->m_dims.m_ucLowNibble;
            apSimplex->m_dims.m_ucLowNibble = apSimplex->m_dims.m_ucHighNibble;
            apSimplex->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = apSimplex->m_ucDimensionA;
            apSimplex->m_ucDimensionA = apSimplex->m_ucDimensionB;
            apSimplex->m_ucDimensionB = t;
        }
        int last = apSimplex->m_ucDimensionA + apSimplex->m_ucDimensionB - 1;
        unsigned short usId0 = apSimplex->m_ids[0];
        apSimplex->m_ids[0] = apSimplex->m_ids[last];
        apSimplex->m_ids[last] = usId0;
        if ((apSimplex->m_ucDimensionA & apSimplex->m_ucDimensionB) == 2)
        {
            unsigned short usId1 = apSimplex->m_ids[1];
            apSimplex->m_ids[1] = apSimplex->m_ids[2];
            apSimplex->m_ids[2] = usId1;
        }
    }
}
}  // namespace fnv_00d2ec50
#include "fnv/symbols_simd.h"

namespace fnv_00d2ef30 {

struct Head50
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};

struct Vector4f
{
    int x, y, z, w;
};

struct Tail10
{
    int unk00, unk04, unk08, unk0c;
};

struct QueryCtx
{
    Head50 head;
    Vector4f vec;
    Tail10 tail;
};

struct Handle
{
    int value;
};

__declspec(align(16)) struct QueryObj
{
    const void* vtable;
    float scale;
    int unk08;
    int unk0c;
    Vector4f vec;
    int extra;
    void Init(const Vector4f& v, int e)
    {
        vtable = &(*reinterpret_cast<unsigned int *>(&::UNK_010ce80c));
        scale = ::DAT_0104da48;
        vec = v;
        extra = e;
    }
};

struct FUN_00d2dd70_class
{
    void FUN_00d2ef30(Handle p1, Handle p2, QueryCtx* ctx, int e1, int e2);
};

// @fnv 0x00d2ef30
void FUN_00d2dd70_class::FUN_00d2ef30(Handle p1, Handle p2, QueryCtx* ctx, int aiExtra1, int aiExtra2)
{
    QueryObj q2;
    QueryObj q1;
    float s = ::DAT_0104da48;
    __m128 v = *(const __m128*)&ctx->vec;
    q1.scale = s;
    __m128 neg = _mm_xor_ps(v, *(const __m128*)&(*reinterpret_cast<unsigned int *>((void *)&::DAT_010c44d0)));
    QueryCtx local = *ctx;
    *(__m128*)&local.vec = neg;
    q1.vec = ctx->vec;
    q1.extra = aiExtra1;
    q1.vtable = &(*reinterpret_cast<unsigned int *>(&::UNK_010ce80c));
    if (aiExtra2)
    {
        q2.Init(ctx->vec, aiExtra2);
        reinterpret_cast<::OperationAdapter *>(this)->FUN_00d2dd70((*(void * *)&(const ::fnv_00d2ef30::Handle &)(p2)), (*(void * *)&(const ::fnv_00d2ef30::Handle &)(p1)), &local, &q1, &q2);
    }
    else
    {
        reinterpret_cast<::OperationAdapter *>(this)->FUN_00d2dd70((*(void * *)&(const ::fnv_00d2ef30::Handle &)(p2)), (*(void * *)&(const ::fnv_00d2ef30::Handle &)(p1)), &local, &q1, 0);
    }
}
}  // namespace fnv_00d2ef30

namespace fnv_00d2f000 {

struct S_00d2f000_V4
{
    unsigned x, y, z, w;
};

struct S_00d2f000_Input
{
    unsigned unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38,
        unk3C, unk40, unk44, unk48, unk4C;
    union
    {
        __m128 m_q50;
        S_00d2f000_V4 m_v50;
    };
    unsigned unk60, unk64, unk68, unk6C;
};

struct S_00d2f000_Base
{
    float m_f04;
    unsigned unk08, unk0C;
    S_00d2f000_V4 m_v10;
    void* m_p20;
    unsigned unk24, unk28, unk2C;
    S_00d2f000_Base()
    {}
    S_00d2f000_Base(float f, const S_00d2f000_V4& v, void* p)
    {
        m_f04 = f;
        m_v10 = v;
        m_p20 = p;
    }
};

struct __declspec(align(16)) S_00d2f000_Flip : public S_00d2f000_Base
{
    S_00d2f000_Flip()
    {}
    S_00d2f000_Flip(float f, const S_00d2f000_V4& v, void* p) : S_00d2f000_Base(f, v, p)
    {}
    virtual void vtbl00(void);
    virtual void vtbl04(void);
};

struct FUN_00d2f000_class
{
    void LinearCastFlip(void* a1, void* a2, S_00d2f000_Input* in, void* a4, void* a5);
};

// Copies in with its vector at +0x50 sign-flipped, builds a record from a4 (and a5 if non-zero), and calls linearCast(a2, a1, ...).
// @fnv 0x00d2f000
void FUN_00d2f000_class::LinearCastFlip(void* a1, void* a2, S_00d2f000_Input* in, void* a4, void* a5)
{
    __m128 v = in->m_q50;
    __m128 mask = ::DAT_010c44d0;
    S_00d2f000_Input local = *in;
    local.m_q50 = _mm_xor_ps(v, mask);
    S_00d2f000_Flip fr;
    fr.m_f04 = ::DAT_0104da48;
    fr.m_v10 = in->m_v50;
    fr.m_p20 = a4;

    if (a5 != 0)
    {
        S_00d2f000_Flip fl;
        fl.m_f04 = ::DAT_0104da48;
        fl.m_v10 = in->m_v50;
        fl.m_p20 = a5;
        reinterpret_cast<::Agent *>((this))->FUN_00d43aa0(static_cast<::Holder *>(a2), a1, &local, &fr, &fl);
    }
    else
        reinterpret_cast<::Agent *>((this))->FUN_00d43aa0(static_cast<::Holder *>(a2), a1, &local, &fr, nullptr);
}
}  // namespace fnv_00d2f000

namespace fnv_00d2e5a0 {



struct Dispatch
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual int Select(void* a, void* b, void* c);
};

struct Arg3Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Dispatch* m_pDispatch;
};

struct FUN_00d2def0_cls
{
};

struct FUN_00d440f0_cls
{
};

struct SpawnedObject
{
    virtual ~SpawnedObject() throw()
    {}
    unsigned short m_iElementCount;
};

// Allocates and constructs a 0x40 or 0x38 byte object chosen by a3's Select(a1, a2, a3) when a4 is non-zero; with a4 zero it builds a 0x40 one and destructs it.
// @fnv 0x00d2e5a0
void* FUN_00d2e5a0(void* a1, void* a2, void* a3, void* a4)
{
    if (a4 != 0)
    {
        Arg3Obj* o3 = (Arg3Obj*)a3;
        int r = o3->m_pDispatch->Select(a1, a2, a3);
        switch (r)
        {
        case 0:
        case 2: {
            SpawnedObject* obj = static_cast<SpawnedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(0x40));
            obj->m_iElementCount = 0x40;
            return ((void *)(reinterpret_cast<::FUN_00d2def0_cls *>((((FUN_00d2def0_cls*)obj)))->FUN_00d2def0(a1, a2, (int *)(a3), a4)));
        }
        case 1: {
            SpawnedObject* obj = static_cast<SpawnedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(0x38));
            obj->m_iElementCount = 0x38;
            return ((void *)(new ((void *)(((FUN_00d440f0_cls*)obj))) ::FUN_00d440f0((*(const ::CdBodyS *)(a1)), (*(const ::CdBodyS *)(a2)), (*(const ::CollisionInputS *)(a3)), (::ContactMgrS *)(a4))));
        }
        default:
            return 0;
        }
    }

    SpawnedObject* obj = static_cast<SpawnedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(0x40));
    obj->m_iElementCount = 0x40;
    reinterpret_cast<::FUN_00d2def0_cls *>((((FUN_00d2def0_cls*)obj)))->FUN_00d2def0(a2, a1, (int *)(a3), (int)(0));
    obj->SpawnedObject::~SpawnedObject();
    return obj;
}
}  // namespace fnv_00d2e5a0



namespace fnv_00d2e6d0 {
struct RegEntry
{
    void* fn0;
    void* fn1;
    void* fn2;
    void* fn3;
    bool b0;
    bool b1;
};

struct TargetClass
{
};


// Fills a RegEntry with four function pointers and two flags and passes it to obj->FUN_00cfbbe0 with (8, 0x12), then again with different pointers and (0x12, 8).
// @fnv 0x00d2e6d0
void __cdecl FUN_00d2e6d0(TargetClass* obj)
{
    RegEntry entry;
    entry.fn0 = (void*)((void (&)())::FUN_00d2e680);
    entry.fn1 = (void*)((void (&)())::FUN_00d2e970);
    entry.fn2 = (void*)((void (&)())::FUN_00d2e9b0);
    entry.fn3 = (void*)((void (&)())::FUN_00d2e9f0);
    entry.b0 = true;
    entry.b1 = true;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((obj))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::fnv_00d2e6d0::RegEntry *)(&entry), 8, 0x12);

    entry.fn0 = (void*)((void (&)())::FUN_00d2df50);
    entry.fn1 = (void*)FUN_00d312f0;
    entry.fn2 = (void*)FUN_00d31110;
    entry.fn3 = (void*)((void (&)())::FUN_00d30f50);
    entry.b0 = false;
    entry.b1 = true;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((obj))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::fnv_00d2e6d0::RegEntry *)(&entry), 0x12, 8);
}
}  // namespace fnv_00d2e6d0

namespace fnv_00d2eae0 {
// ---------------------------------------------------------------------------
// The agent object that the game tears down in FUN_00d2eae0.
//
// The first word of the object holds the vtable pointer.  While the agent is
// alive the pointer refers to the table of the agent class, once the agent
// has been released it is reset to the table of the base class.
// ---------------------------------------------------------------------------

// A vtable: a list of function pointers.
struct VTable
{
    void* entries[4];
};

struct hkpBvTreeStreamAgent
{
    const VTable* vtbl;    // +0x00
    unsigned short id;     // +0x04
    unsigned short unk06;  // +0x06
    void* unk08;           // +0x08
    int unk0c;             // +0x0c
    int unk10;             // +0x10
    int unk14;             // +0x14
    int unk18;             // +0x18
    int unk1c;             // +0x1c
    int unk20;             // +0x20
    int unk24;             // +0x24
    int unk28;             // +0x28
    int unk2c;             // +0x2c
    void* buffer;          // +0x30
    int unk34;             // +0x34
    int unk38;             // +0x38

    void* FUN_00d2eae0(unsigned int flags);
};

// The functions the vtables of the agent class and of its base class point
// at (the game keeps them in the tables).
void __cdecl AgentRelease(void* agent, unsigned short id);
void __cdecl AgentFlush(void* buffer, int bytes);

// The vtables of the agent class and of its base class.
static const VTable g_vtblAgent = {
    {(void*)&AgentRelease, (void*)&AgentFlush, (void*)&AgentRelease, (void*)&AgentFlush}};

static const VTable g_vtblBase = {{(void*)&AgentFlush, (void*)&AgentRelease, (void*)&AgentFlush, (void*)&AgentRelease}};

// The handler that owns the agents.

// The global that hands out the manager of the agents.


// Resets the vtable, frees its buffer through the handler if owned, and if flags bit 0 is set calls the handler's release(this, id); returns this.
// @fnv 0x00d2eae0
void* hkpBvTreeStreamAgent::FUN_00d2eae0(unsigned int flags)
{
    vtbl = &g_vtblAgent;

    hkMemoryAllocator& handler = hkMemoryRouter::getInstance().heap();

    int count = unk38;
    unk34 = 0;
    if (!(count & 0x80000000))
        handler.bufFree(buffer, (count & 0x3fffffff) * 4);

    buffer = 0;
    unk38 = 0x80000000;
    vtbl = &g_vtblBase;

    if (flags & 1)
    {
        hkMemoryRouter::getInstance().heap().blockFree(this, id);
    }

    return this;
}
}  // namespace fnv_00d2eae0

struct StreamDispatchInput;
struct Selector
{
    virtual void Unknown0() = 0;
    virtual void Unknown1() = 0;
    virtual void Unknown2() = 0;
    virtual int Classify(void* second, void* first, StreamDispatchInput* context) = 0;
};
struct StreamDispatchInput
{
    unsigned int unk00, unk04, unk08, unk0c;
    Selector* selector;
};
extern "C" void* g_010ce8b0[];
extern "C" void* g_010ce874[];
struct Header
{
    void** vtable;
    unsigned short size, unk06;
};
struct Obj56 : Header
{
};
struct Obj64 : Header
{
};
static __forceinline Obj56* Create56(void* second, void* first, StreamDispatchInput* context, void* flags)
{
    Obj56* obj = static_cast<Obj56*>(hkMemoryRouter::getInstance().heap().blockAlloc(0x38));
    obj->size = 0x38;
    new ((void *)(obj)) ::FUN_00d440f0((*(const ::CdBodyS *)(second)), (*(const ::CdBodyS *)(first)), (*(const ::CollisionInputS *)(context)), static_cast<::ContactMgrS *>(flags));
    obj->vtable = g_010ce8b0;
    return obj;
}
static __forceinline Obj64* Create64(void* second, void* first, StreamDispatchInput* context, void* flags)
{
    Obj64* obj = static_cast<Obj64*>(hkMemoryRouter::getInstance().heap().blockAlloc(0x40));
    obj->size = 0x40;
    reinterpret_cast<::FUN_00d2def0_cls *>((obj))->FUN_00d2def0(second, first, (int *)(context), flags);
    obj->vtable = g_010ce874;
    return obj;
}
// Creates an Obj56 or Obj64 stream object based on the selector's classification, or a default Obj64 when flags is zero.
// @fnv 0x00d2e7f0
Header* FUN_00d2e7f0(void* first, void* second, StreamDispatchInput* context, void* flags)
{
    if (flags)
    {
        switch (context->selector->Classify(second, first, context))
        {
        case 1:
            return Create56(second, first, context, flags);
        case 0:
        case 2:
            return Create64(second, first, context, flags);
        default:
            return 0;
        }
    }
    return Create64(second, first, context, 0);
}

// Moved from hkpbvtreestreamagent_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).

// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/CollectionProcessAgent.h"
void FUN_00d2e8e0(S_00d2e8e0_Dispatcher* dispatcher);
struct S2ee10_Ref
{
    void* p;
};

struct S2ee10_Vec4;

struct S2ee10_Simd
{
    __m128 m_vValue;
};

struct S2ee10_Vec4
{
    __m128 m_vComponents;
    inline void setNeg4(const S2ee10_Vec4& v);
    inline S2ee10_Simd getSimdAt3() const
    {
        S2ee10_Simd r;
        r.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }
    inline void addMul4(const S2ee10_Simd& r, const S2ee10_Vec4& a)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(r.m_vValue, a.m_vComponents), m_vComponents);
    }
};

inline void S2ee10_Vec4::setNeg4(const S2ee10_Vec4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, (*reinterpret_cast<const ::S2ee10_Vec4 *>(&::DAT_010c4c00)).m_vComponents);
}

struct S2ee10_ContactPoint
{
    S2ee10_Vec4 m_vContactPosition;
    S2ee10_Vec4 m_vSeparatingNormal;
    S2ee10_Vec4 m_extra;
};

struct S2ee10_GskCache
{
    unsigned short m_kVertices[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    unsigned char m_flagsLo : 4;
    unsigned char m_flagsHi : 4;

    inline void flip()
    {
        unsigned char lo = m_flagsLo;
        m_flagsLo = m_flagsHi;
        m_flagsHi = lo;
        unsigned char d = m_ucDimensionA;
        m_ucDimensionA = m_ucDimensionB;
        m_ucDimensionB = d;
        int idx = m_ucDimensionA + m_ucDimensionB - 1;
        unsigned short v0 = m_kVertices[0];
        m_kVertices[0] = m_kVertices[idx];
        m_kVertices[idx] = v0;
        if ((m_ucDimensionA & m_ucDimensionB) == 2)
        {
            unsigned short t = m_kVertices[1];
            m_kVertices[1] = m_kVertices[2];
            m_kVertices[2] = t;
        }
    }
};

struct S2ee10_ToiInfo
{
    S2ee10_Vec4 m_vSeparatingNormal;
    float m_uiCommandId;
    int unk14;
    int unk18;
    int unk1c;
    S2ee10_GskCache m_kGskCache;

    inline void flip()
    {
        m_vSeparatingNormal.setNeg4(m_vSeparatingNormal);
        m_kGskCache.flip();
    }
};

struct S2ee10_Output
{
    S2ee10_ContactPoint* m_pAlignedPairData;
    int m_pConstraintOwner;
    int m_potentials;
    int unk0c;
    S2ee10_ContactPoint m_akContactPoints[256];
    S2ee10_Vec4 unk3010;
    S2ee10_ToiInfo m_fTimeOfImpact;
};

struct hkpCdBody;
struct CollisionAgentContext;
class hkpAgentBase
{
  public:
public:
    void FUN_00d437a0(S2ee10_Ref bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input, S2ee10_Output& output);
};

class hkpSymmetricAgentT : public hkpAgentBase
{
  public:
    void FUN_00d2ee10(const hkpCdBody& bodyA, S2ee10_Ref bodyB, const CollisionAgentContext& input,
                      S2ee10_Output& output);
};

// @fnv 0x00d2ee10
void hkpSymmetricAgentT::FUN_00d2ee10(const hkpCdBody& bodyA, S2ee10_Ref bodyB, const CollisionAgentContext& input,
                                      S2ee10_Output& output)
{
    float oldTime = output.m_fTimeOfImpact.m_uiCommandId;
    S2ee10_ContactPoint* cp = output.m_pAlignedPairData;
    reinterpret_cast<::CollectionProcessAgent *>(this)->FUN_00d437a0((*(::ShapeArg * *)&(const ::S2ee10_Ref &)(bodyB)), const_cast<hkpCdBody*>(&bodyA), const_cast<CollisionAgentContext*>(&input), &output);
    for (; cp < output.m_pAlignedPairData; cp++)
    {
        cp->m_vContactPosition.addMul4(cp->m_vSeparatingNormal.getSimdAt3(), cp->m_vSeparatingNormal);
        cp->m_vSeparatingNormal.setNeg4(cp->m_vSeparatingNormal);
    }
    if (oldTime != output.m_fTimeOfImpact.m_uiCommandId)
    {
        __m128 n = _mm_load_ps((const float*)&output.m_fTimeOfImpact.m_vSeparatingNormal);
        output.m_fTimeOfImpact.m_vSeparatingNormal.m_vComponents = _mm_xor_ps(n, (*reinterpret_cast<const ::S2ee10_Vec4 *>(&::DAT_010c4c00)).m_vComponents);
        output.m_fTimeOfImpact.m_kGskCache.flip();
    }
}

// Moved from hkpbvtreestreamagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).
#include <intrin.h>
#include <windows.h>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00cb21e0_shell.h"
#include "fnv/decl/hkTransformCB22.h"
#include "fnv/symbols_00d88000.h"
#include "fnv/symbols_01268000.h"

extern "C" void __cdecl __debugbreak(void);
typedef float hkReal;
typedef signed int hkInt32;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef uintptr_t hkUlong;
enum hkResult
{
HK_SUCCESS=0,
HK_FAILURE=1
};
typedef size_t hk_size_t;
typedef hkReal hkTime;
class FinishingFlag
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
typedef char CompileTimeTrueType;
typedef int CompileTimeFalseType;inline hkBool(bool b)
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
__forceinline ValueWrapper(TYPE e)
:m_kStorage(e)
{
}
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline TYPE operator->()const
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
template<typename T>struct TypeSizeConstant{enum{val=sizeof(T)};};
struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();protected:
ValueWrapper<void*>m_next;
ValueWrapper<void*>m_kRayStart;
ValueWrapper<void*>m_kRayEnd;};
class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline virtual ~hkBaseObject(){}
public:
__forceinline hkBaseObject(){}
};
class hkStatisticsCollector;
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
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
template<bool N>struct BooleanTypeConstant{typedef BooleanTypeConstant<N>type;enum{result=N};};
typedef BooleanTypeConstant<true>hkTypeIsPod;
typedef BooleanTypeConstant<false>hkTypeIsClass;
template<typename T>
hkBool::CompileTimeFalseType operator==(const T&,const hkTypeIsPod&);
template<typename T>
struct IsPodType:public BooleanTypeConstant<(sizeof(*static_cast<T*>(0)==*static_cast<const hkTypeIsPod*>(0))==sizeof(hkBool::CompileTimeTrueType))>{};
template<>struct IsPodType<hkUint32>:public hkTypeIsPod{};
class HavokArrayUtilities
{
public:
template<typename T>static __forceinline void construct(T*t,int n,hkTypeIsPod);
template<typename T>static __forceinline void constructWithCopy(T*t,int n,const T&tcopy,hkTypeIsPod);
template<typename T>static __forceinline void destruct(T*t,int n,hkTypeIsPod);
template<typename T>static __forceinline void destruct(T*t,int n,hkTypeIsClass);};
template<typename T>
__forceinline void HavokArrayUtilities::constructWithCopy(T*t,int n,const T&tcopy,hkTypeIsPod)
{
for(int i=0;i<n;++i)
{
t[i]=tcopy;
}
}
template<typename T>
__forceinline void HavokArrayUtilities::destruct(T*t,int n,hkTypeIsPod)
{
}
struct RouterHeapAllocatorProvider
{
hkMemoryAllocator&get(const void*){return hkMemoryRouter::getInstance().heap();}
};
template<typename T>
class HavokElementArray
{
public:
typedef HavokElementArray<T>ThisType;
__forceinline HavokElementArray(T*buffer,int size,int capacity);
protected:
__forceinline HavokElementArray(const HavokElementArray&a){;}
public:
__forceinline void _useExternalArray(T*,int cap);
__forceinline ~HavokElementArray();
__forceinline int GetLogicalSize()const;
__forceinline int getCapacity()const;
__forceinline void clear();
__forceinline void _clearAndDeallocate(hkMemoryAllocator&alloc);
__forceinline void pushBackUnchecked(const T&e);
typedef T*iterator;
__forceinline iterator begin();
protected:
__forceinline HavokElementArray<T>&copyFromArray(hkMemoryAllocator&,const HavokElementArray<T>&src,hkTypeIsPod);
public:
enum
{
CAPACITY_MASK=int(0x3FFFFFFF),
FLAG_MASK=int(0xC0000000),
DONT_DEALLOCATE_FLAG=int(0x80000000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
T*m_data;
int m_iElementCount;
int m_iCapacityState;
public:
HavokElementArray(FinishingFlag f){}
};
template<typename T,typename Allocator=RouterHeapAllocatorProvider>
class hkArray:public HavokElementArray<T>
{
public:
typedef Allocator AllocatorType;__forceinline ~hkArray();
__forceinline hkArray(T*buffer,int size,int capacity):HavokElementArray<T>(buffer,size,capacity){}
protected:
__forceinline hkArray(const hkArray&a);
public:
__forceinline hkArray&operator=(const HavokElementArray<T>&a);
__forceinline void ClearAndRelease(){HavokElementArray<T>::_clearAndDeallocate(AllocatorType().get(this));}
};
template<typename T,unsigned N,typename Allocator=RouterHeapAllocatorProvider>
class hkInplaceArray:public hkArray<T,Allocator>
{
public:
typedef hkInplaceArray<T,N,Allocator>mytype;
explicit __forceinline hkInplaceArray(int size=0);
__forceinline ~hkInplaceArray(){}
public:
T m_kStorage[N];
public:
hkInplaceArray(FinishingFlag f):hkArray<T,Allocator>(f){}
};
template<typename T>
__forceinline int HavokElementArray<T>::GetLogicalSize()const
{
return m_iElementCount;
}
template<typename T>
__forceinline int HavokElementArray<T>::getCapacity()const
{
return(m_iCapacityState&static_cast<int>(CAPACITY_MASK));
}
template<typename T>
__forceinline void HavokElementArray<T>::clear()
{
HavokArrayUtilities::destruct(m_data,m_iElementCount,typename IsPodType<T>::type());
m_iElementCount=0;
}
template<typename T>
__forceinline HavokElementArray<T>::HavokElementArray(T*ptr,int size,int capacity)
:m_data(ptr),
m_iElementCount(size),
m_iCapacityState(capacity | DONT_DEALLOCATE_FLAG)
{
;
;
}
template<typename T>
__forceinline HavokElementArray<T>::~HavokElementArray()
{
;
;
}
template<typename T>
__forceinline void HavokElementArray<T>::_clearAndDeallocate(hkMemoryAllocator&alloc)
{
clear();
if((m_iCapacityState&DONT_DEALLOCATE_FLAG)==0)
{
alloc._bufFree<T>(m_data,getCapacity());
}
m_data=0;
m_iCapacityState=DONT_DEALLOCATE_FLAG;
}
template<typename T>
__forceinline void HavokElementArray<T>::pushBackUnchecked(const T&t)
{
;
HavokArrayUtilities::constructWithCopy(m_data+m_iElementCount,1,t,typename IsPodType<T>::type());
m_iElementCount++;
}
template<typename T>
typename HavokElementArray<T>::iterator HavokElementArray<T>::begin()
{
return m_data;
}
template<typename T,typename Allocator>
__forceinline hkArray<T,Allocator>::~hkArray()
{
ClearAndRelease();
}
template<typename T,unsigned N,typename Allocator>
__forceinline hkInplaceArray<T,N,Allocator>::hkInplaceArray(int size)
:hkArray<T,Allocator>(m_kStorage,size,N)
{
}

;
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
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;
class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;
class Vector4Comparison
{
public:
enum Mask
{
MASK_NONE=0,
MASK_X=1,
MASK_Y=2,
MASK_XY=3,
MASK_Z=4,
MASK_XZ=5,
MASK_YZ=6,
MASK_XYZ=7,
MASK_W=8,
MASK_XW=9,
MASK_YW=10,
MASK_XYW=11,
MASK_ZW=12,
MASK_XZW=13,
MASK_YZW=14,
MASK_XYZW=15
};
__forceinline void setAnd(hkVector4ComparisonParameter a,hkVector4ComparisonParameter b){m_uiMask=_mm_and_ps(a.m_uiMask,b.m_uiMask);}
__forceinline hkBool32 allAreSet(Mask m)const{return(_mm_movemask_ps(m_uiMask)&m)==m;}
private:
hkQuadReal m_uiMask;
friend class hkVector4;};
class hkRotation;
class hkTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
__forceinline void setAll3(hkReal x);
__forceinline void setZero4();
__forceinline void add4(const hkVector4&a);
__forceinline void setAdd4(const hkVector4&a,const hkVector4&b);
__forceinline void sub4(const hkVector4&a);
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void setMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void addMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void setCross(const hkVector4&a,const hkVector4&b);
__forceinline Vector4Comparison compareLessThanEqual4(hkVector4Parameter a)const;
__forceinline void setNeg4(const hkVector4&v);
__forceinline void setMin4(const hkVector4&a,const hkVector4&b);
__forceinline void setMax4(const hkVector4&a,const hkVector4&b);
__forceinline void _setRotatedInverseDir(const hkRotation&a,const hkVector4&b);
__forceinline void _setTransformedInversePos(const hkTransform&a,const hkVector4&b);
__forceinline hkReal&operator()(int i);
__forceinline const hkReal&operator()(int i)const;
__forceinline const hkQuadReal&getQuad()const;
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
class hkQuaternion
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
hkVector4 m_vec;
protected:
void setFlippedRotation(const hkVector4&from);};
class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline hkMatrix3(){}
__forceinline const hkVector4&getColumn(int i)const;
protected:
hkVector4 m_kColumn0;
hkVector4 m_kColumn1;
hkVector4 m_kColumn2;};
class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline hkTransform(){}
__forceinline const hkVector4&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};
class hkSweptTransform
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline void _approxTransformAt(hkTime time,hkTransform&transformOut)const;
__forceinline hkReal getInvDeltaTime()const;
public:
hkVector4 m_vCenterOfMass0;
hkVector4 m_vCenterOfMass1;
hkQuaternion m_qRotation0;
hkQuaternion m_qRotation1;
hkVector4 m_vCenterOfMassLocal;};
inline const hkQuadReal&hkVector4::getQuad()const
{
return m_vComponents;
}
inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4::setAll3(hkReal a)
{
m_vComponents=_mm_set_ps1(a);
}
inline void hkVector4::setZero4()
{
m_vComponents=_mm_setzero_ps();
}
inline void hkVector4::add4(const hkVector4&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4::setAdd4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::sub4(const hkVector4&v)
{
m_vComponents=_mm_sub_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_mul_ps(r.broadcast(),v1.m_vComponents);
}
inline void hkVector4::addMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
}
inline void hkVector4::setCross(const hkVector4&v0,const hkVector4&v1)
{
hkQuadReal cross0;
cross0=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))));
hkQuadReal cross1;
cross1=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))));
m_vComponents=_mm_sub_ps(cross0,cross1);}
inline Vector4Comparison hkVector4::compareLessThanEqual4(const hkVector4&a)const
{
Vector4Comparison m;m.m_uiMask=_mm_cmple_ps(m_vComponents,a.m_vComponents);
return m;
}
extern "C" const char str_010ce7d4[];
inline void hkVector4::setNeg4(const hkVector4&v)
{
m_vComponents=_mm_xor_ps(v.m_vComponents,::DAT_010c44d0);
}
inline void hkVector4::setMin4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=_mm_min_ps(a.getQuad(),b.getQuad());
}
inline void hkVector4::setMax4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=_mm_max_ps(a.getQuad(),b.getQuad());
}
inline void hkVector4::_setRotatedInverseDir(const hkRotation&r,const hkVector4&b)
{
hkQuadReal c0=r.getColumn(0).m_vComponents;
hkQuadReal c1=r.getColumn(1).m_vComponents;
hkQuadReal c2=r.getColumn(2).m_vComponents;
{hkQuadReal _tmp,_ctmp;_tmp=_mm_unpacklo_ps(c0,c1);_ctmp=_mm_shuffle_ps(_mm_unpackhi_ps(c0,c1),c2,(((3)<<6)|((2)<<4)|((1)<<2)|((0))));c0=_mm_movelh_ps(_tmp,c2);c1=_mm_shuffle_ps(_mm_movehl_ps(c0,_tmp),c2,(((3)<<6)|((1)<<4)|((1)<<2)|((0))));c2=_ctmp;};
const hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=_mm_mul_ps(c0,b0);
const hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=_mm_mul_ps(c1,b1);
const hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=_mm_mul_ps(c2,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),r2);}
inline void hkVector4::_setTransformedInversePos(const hkTransform&a,const hkVector4&b)
{
hkVector4 t0;t0.setSub4(b,a.getTranslation());
_setRotatedInverseDir(a.getRotation(),t0);
}
inline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
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
hkReal hkSweptTransform::getInvDeltaTime()const
{
return m_vCenterOfMass1(3);
}
class StringCursor
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
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
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32 m_uiStartTicks;
hkUint32 m_uiEndTicks;
__forceinline void setTime();
};
struct TimedNameRecord:public StringCursor::CommandTimingEntry
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(StringCursor::TimedNameRecord));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pFirst;
};};
void StringCursor::CommandTimingEntry::setTime()
{
hkUint32 ticks;
ticks = static_cast<unsigned int>(__rdtsc());
m_uiStartTicks=ticks;
}
class hkMotionState
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkTransform&getTransform()const;
inline const hkSweptTransform&getSweptTransform()const;
protected:
hkTransform m_kMotionTransform;
class hkSweptTransform m_kSweptTransform;
public:
hkVector4 m_kDeltaAngle;
hkReal m_fObjectRadius;};
const hkTransform&hkMotionState::getTransform()const
{
return m_kMotionTransform;
}
const hkSweptTransform&hkMotionState::getSweptTransform()const
{
return m_kSweptTransform;
}
class hkAabb
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline hkBool contains(const hkAabb&other)const;
public:
hkVector4 m_kMinimumCorner;
hkVector4 m_kMaximumCorner;};
hkBool hkAabb::contains(const hkAabb&other)const
{
Vector4Comparison mincomp=m_kMinimumCorner.compareLessThanEqual4(other.m_kMinimumCorner);
Vector4Comparison maxcomp=other.m_kMaximumCorner.compareLessThanEqual4(m_kMaximumCorner);
Vector4Comparison both;both.setAnd(mincomp,maxcomp);
return both.allAreSet(Vector4Comparison::MASK_XYZ)!=0;}
typedef hkUint16 hkContactPointId;
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
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline void getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const;
virtual hkReal getMaximumProjection(const hkVector4&direction)const;
virtual const hkpShapeContainer*GetShapeContainer()const{return 0;}
virtual bool isConvex()const{return false;}
struct PhysicsShape
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(hkpShape::PhysicsShape));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
bool m_bIsConvex;
bool m_bIsConvexPiece;
bool m_bIsComposite;
};
virtual int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const;
protected:
virtual void CalculateAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const=0;
virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const=0;
virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
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
void hkpShape::getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const
{
CalculateAabb(localToWorld,tolerance,out);
}
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
__forceinline const hkMotionState*GetMotionState()const;
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;};
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkMotionState*hkpCdBody::GetMotionState()const
{
return static_cast<const hkMotionState*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
struct GskAgentInput;
class hkpContactMgr;
class hkpConstraintOwner;
struct AgentProcessingInput
{
AgentProcessingInput():m_pAdditionalCollidableBody(0){}
ValueWrapper<const hkpCdBody*>m_pBodyA;
ValueWrapper<const hkpCdBody*>m_pBodyB;
ValueWrapper<const hkpCdBody*>m_pAdditionalCollidableBody;
ValueWrapper<const GskAgentInput*>m_pRayCastInput;
ValueWrapper<hkpContactMgr*>m_pContactManager;
hkTransform m_kTransform;};
struct AgentSubtypeMarker:public AgentProcessingInput
{
ValueWrapper<hkReal>m_fSubtypeValue;
hkVector4 m_vSubtypePosition;};
struct CollisionQualityInfo
{
__declspec(align(16))hkReal m_fMinimumCollisionSeparation;
hkReal m_fMinimumExtraSeparation;
hkReal m_fMaximumExtraSeparation;
hkReal m_fTimeOfImpactSeparation;
ValueWrapper<hkBool32>m_iQualityInfoValue10;};
class hkpCollisionFilter;
class hkpConvexListFilter;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;
ValueWrapper<const hkpCollisionFilter*>m_iFilter;
ValueWrapper<const hkpConvexListFilter*>m_pConvexListCollisionFilter;
struct AabbBoundsAndScale
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(CollisionAgentContext::AabbBoundsAndScale));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kAabbMin;
hkVector4 m_kAabbMaximum;
hkVector4 m_kAabbScale;
};
AabbBoundsAndScale m_aiValues;};
struct WorldOperationEntry;
struct ShapeSweepParameters;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}__forceinline void __cdecl operator delete(void*p){hkReferencedObject*b=static_cast<hkReferencedObject*>(p);;hkMemoryRouter::getInstance().heap().blockFree(p,b->m_usMemSizeAndFlags);}__forceinline void*__cdecl operator new(std::size_t,void*p){return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){__debugbreak();return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){__debugbreak();}class CommandArgument;
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector)=0;
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector)=0;
virtual void linearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&castCollector,hkpCdPointCollector*startCollector)=0;
public:
virtual void FUN_00d2df90(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&result)=0;
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
};
class hkStepInfo
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}public:
__declspec(align(16))ValueWrapper<hkTime>m_uiStartTime;
ValueWrapper<hkTime>m_fEndTime;
ValueWrapper<hkReal>m_fTimeStep;};
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable ValueWrapper<CollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};
class hkpBvTreeAgent:public hkpCollisionAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);
static void __cdecl m_pVirtualFunction2(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);
virtual void linearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&collector,hkpCdPointCollector*startCollector);
static void __cdecl m_pVirtualFunction3(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&collector,hkpCdPointCollector*startCollector);
virtual void FUN_00d2df90(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void cleanup(hkpConstraintOwner&info);
static void __cdecl setUseAabbCaching(hkBool useIt);
static hkBool __cdecl getUseAabbCaching();
public:
static hkBool ms_bUseAabbCaching;
virtual void ProcessContactPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpConstraintOwner&constraintOwner);
virtual void RemovePoint(const CollisionAgentContext&input);
virtual void WarpTime(hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
__forceinline static hkResult __cdecl BuildCollisionHitList(
const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkTransform&bTa,
const hkVector4&linearTimInfo,const GskAgentInput&input,
hkAabb*cachedAabb,hkArray<hkpShapeKey>&hitListOut);
public:
hkpBvTreeAgent(hkpContactMgr*mgr);
protected:
void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
static hkpCollisionAgent*__cdecl CreateBvTreeAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&env,hkpContactMgr*mgr);
void ProcessCollisionPartners(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpConstraintOwner&constraintOwner);
__forceinline void prepareCollisionPartnersProcess(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,hkpConstraintOwner&constraintOwner);
static void __cdecl CalculateAabbForLinearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkAabb&aabbOut);
static void __cdecl CalculateAabbForCollision(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkAabb&aabbOut);
~hkpBvTreeAgent(){}
struct BvTreeAgentTrack
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(hkpBvTreeAgent::BvTreeAgentTrack));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkpShapeKey m_key;
hkInt32 m_iValueAtOffset4;
hkpCollisionAgent*m_pCollisionAgent;
hkpShapeKey&GetIteratorKey(){return m_key;}
void setKey(hkpShapeKey&key){m_key=key;}
};
hkArray<BvTreeAgentTrack>m_kEntries;
hkAabb m_kBoundingBox;
static hkBool ms_bUseAabbCache;
static hkpCollisionAgent*__cdecl createShapeBvAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createBvTreeShapeAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createBvBvAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
};
struct hkpAgent1nSector
{
enum{SECTOR_SIZE=512,NET_SECTOR_SIZE=SECTOR_SIZE-16};};
struct AgentSectorPointerArray
{
hkArray<hkpAgent1nSector*>m_kSectors;};
class hkpBvTreeStreamAgent:public hkpCollisionAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
static void __cdecl registerConvexListAgent(hkpCollisionDispatcher*dispatcher);
static void __cdecl registerMultiRayAgent(hkpCollisionDispatcher*dispatcher);
virtual void FUN_00d2df90(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void cleanup(hkpConstraintOwner&info);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);
virtual void linearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&collector,hkpCdPointCollector*startCollector);
virtual void ProcessContactPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpConstraintOwner&constraintOwner);
virtual void RemovePoint(const CollisionAgentContext&input);
virtual void WarpTime(hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
protected:
hkResult prepareCollisionPartnersProcess(AgentSubtypeMarker&input,hkArray<hkpShapeKey>&hitList);
hkpBvTreeStreamAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
~hkpBvTreeStreamAgent(){}
void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
public:
static hkpCollisionAgent*__cdecl createShapeBvAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createBvTreeShapeAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl dispatchBvTreeConvexList(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl dispatchConvexListBvTree(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
protected:
hkpCollisionDispatcher*m_pCollisionDispatcher;
hkAabb m_kBoundingBox;
AgentSectorPointerArray m_kAgentNnTrack;
};

template <class Agent> struct hkpSymmetricAgent : Agent
{
    hkpSymmetricAgent(const hkpCdBody& a, const hkpCdBody& b, const CollisionAgentContext& c, hkpContactMgr* d) : Agent(b, a, c, d)
    {}
};

// Allocates the agent from the heap allocator, records its size in the memory-size field, and constructs a hkpSymmetricAgent<hkpBvTreeStreamAgent> in place.
// @fnv 0x00d2e680
hkpSymmetricAgent<hkpBvTreeStreamAgent>* __cdecl FUN_00d2e680(void* a, void* b, void* c, void* d)
{
    const int size = sizeof(hkpSymmetricAgent<hkpBvTreeStreamAgent>);
    void* object = hkMemoryRouter::getInstance().heap().blockAlloc(size);
    static_cast<hkReferencedObject*>(object)->m_usMemSizeAndFlags = size;
    return new (object) hkpSymmetricAgent<hkpBvTreeStreamAgent>(*static_cast<const hkpCdBody*>(a), *static_cast<const hkpCdBody*>(b),
                                                                *static_cast<const CollisionAgentContext*>(c), static_cast<hkpContactMgr*>(d));
}

class hkpBvTreeShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
enum BvTreeType
{
BVTREE_MOPP,
BVTREE_TRISAMPLED_HEIGHTFIELD,
BVTREE_USER,
BVTREE_MAX
};
virtual void GetObbHits(const hkTransform&obbTransform,const hkVector4&obbExtent,hkReal tolerance,hkArray<hkpShapeKey>&hits)const=0;
virtual void GetAabbHits(const hkAabb&aabb,hkArray<hkpShapeKey>&hits)const=0;
public:
hkEnum<BvTreeType,hkUint8>m_uiUserData;};
namespace MotionUtilities
{
__forceinline void __cdecl calcTimInfo(const hkMotionState&ms0,const hkMotionState&ms1,hkReal deltaTime,hkVector4&timOut);}
void __cdecl MotionUtilities::calcTimInfo(const hkMotionState&ms0,const hkMotionState&ms1,hkReal deltaTime,hkVector4&timOut)
{
const hkSweptTransform&st0=ms0.getSweptTransform();
const hkSweptTransform&st1=ms1.getSweptTransform();
hkVector4 diff0;diff0.setSub4(st0.m_vCenterOfMass0,st0.m_vCenterOfMass1);
hkVector4 diff1;diff1.setSub4(st1.m_vCenterOfMass1,st1.m_vCenterOfMass0);
hkReal f0=deltaTime*st0.getInvDeltaTime();
hkReal f1=deltaTime*st1.getInvDeltaTime();
timOut.setMul4(f0,diff0);
timOut.addMul4(f1,diff1);
timOut(3)=f0*ms0.m_kDeltaAngle(3)*ms0.m_fObjectRadius+f1*ms1.m_kDeltaAngle(3)*ms1.m_fObjectRadius;}
namespace AlgorithmUtilities
{template<typename T>
class less
{
public:
__forceinline hkBool32 operator()(const T&a,const T&b)
{
return(a<b);
}
};
template<typename T>
__forceinline void __cdecl quickSort(T*pArr,int iSize)
{
quickSort(pArr,iSize,less<T>());
}
template<typename T,typename L>
void __cdecl QuickSortSubrange(T*pArr,int d,int h,L cmpLess);}
namespace AlgorithmUtilities {
template<typename T,typename L>
void __cdecl quickSort(T*pArr,int iSize,L cmpLess)
{
if(iSize>1)
{
int low=0;
int high=iSize-1;
QuickSortSubrange(pArr,low,high,cmpLess);
}
}
}
__forceinline bool hkHasMemoryAvailable(int id,int size)
{
bool hasAvailable=hkMemoryRouter::getInstance().heap().canAllocTotal(size);
return hasAvailable;
}
hkResult __cdecl hkpBvTreeAgent::BuildCollisionHitList(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkTransform&bTa,
const hkVector4&linearTimInfo,const GskAgentInput&input,
hkAabb*cachedAabb,hkArray<hkpShapeKey>&hitListOut)
{
hkAabb aabb;
{
const hkMotionState*msA=bodyA.GetMotionState();
const hkMotionState*msB=bodyB.GetMotionState();
hkVector4 timInfo;timInfo._setRotatedInverseDir(bodyB.getTransform().getRotation(),linearTimInfo);
hkVector4 aabbExtents;
if(input.m_pCollisionQualityInfo->m_iQualityInfoValue10.val())
{
const hkReal secOrdErrA=(msA->m_kDeltaAngle(3)+msB->m_kDeltaAngle(3))*msA->m_fObjectRadius;
const hkReal secOrdErrB=msB->m_kDeltaAngle(3)*msB->m_kDeltaAngle(3)*msB->m_fObjectRadius;
const hkReal checkEpsilon=input.m_fScalar*0.5+(secOrdErrA+secOrdErrB);
bodyA.getShape()->getAabb(bTa,checkEpsilon,aabb);
hkVector4 massCenterAinB;
{
hkVector4 radius4;
radius4.setAll3(input.m_fScalar*0.5+msA->m_fObjectRadius+secOrdErrB);
massCenterAinB._setTransformedInversePos(bodyB.getTransform(),msA->getSweptTransform().m_vCenterOfMass1);
hkVector4 maxR;maxR.setAdd4(massCenterAinB,radius4);
hkVector4 minR;minR.setSub4(massCenterAinB,radius4);
aabb.m_kMinimumCorner.setMax4(aabb.m_kMinimumCorner,minR);
aabb.m_kMaximumCorner.setMin4(aabb.m_kMaximumCorner,maxR);
}
aabbExtents.setSub4(aabb.m_kMaximumCorner,aabb.m_kMinimumCorner);
{
if(msB->m_kDeltaAngle(3)>0.0)
{
hkVector4 relPos;relPos.setSub4(massCenterAinB,msB->getSweptTransform().m_vCenterOfMassLocal);
hkVector4 offsetOut;offsetOut.setCross(relPos,msB->m_kDeltaAngle);
hkReal f=input.m_pStepInfo.m_fTimeStep*msB->getSweptTransform().getInvDeltaTime();
timInfo.addMul4(f,offsetOut);
}
hkVector4 zero;zero.setZero4();
hkVector4 minPath;minPath.setMin4(zero,timInfo);
hkVector4 maxPath;maxPath.setMax4(zero,timInfo);
aabb.m_kMinimumCorner.add4(minPath);
aabb.m_kMaximumCorner.add4(maxPath);
}
}
else
{
const hkReal checkEpsilon=input.m_fScalar*0.5;
bodyA.getShape()->getAabb(bTa,checkEpsilon,aabb);
aabbExtents.setSub4(aabb.m_kMaximumCorner,aabb.m_kMinimumCorner);
}
if(cachedAabb)
{
if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(cachedAabb->contains(aabb)))->FUN_005609f0())
{
return HK_FAILURE;
}
hkVector4 zero;zero.setZero4();
hkVector4 minPath;minPath.setMin4(zero,timInfo);
hkVector4 maxPath;maxPath.setMax4(zero,timInfo);
hkVector4 expand4;expand4.setAll3(input.m_fScalar*0.5);
aabb.m_kMinimumCorner.sub4(expand4);
aabb.m_kMaximumCorner.add4(expand4);
const hkReal maxExpand=0.4f;
const hkReal framesLookAhead=-2.0f;
hkVector4 minExtentPath;minExtentPath.setMul4(framesLookAhead,maxPath);
hkVector4 maxExtentPath;maxExtentPath.setMul4(framesLookAhead,minPath);
hkVector4 maxExpand4;maxExpand4.setMul4(maxExpand,aabbExtents);
maxExtentPath.setMin4(maxExtentPath,maxExpand4);
hkVector4 minExpand4;minExpand4.setNeg4(maxExpand4);
minExtentPath.setMax4(minExtentPath,minExpand4);
aabb.m_kMinimumCorner.add4(minExtentPath);
aabb.m_kMaximumCorner.add4(maxExtentPath);
*cachedAabb=aabb;
}
}
const hkpBvTreeShape*bvB=static_cast<const hkpBvTreeShape*>(bodyB.getShape());
bvB->GetAabbHits(aabb,hitListOut);
return HK_SUCCESS;}
// @fnv 0x00d2df90
void hkpBvTreeStreamAgent::FUN_00d2df90(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&output)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::TimedNameRecord*h=reinterpret_cast<StringCursor::TimedNameRecord*>(mStream.GetStreamEnd());h->m_pCommandName="L" "t" "BvTree3";h->m_pFirst="S" "t" "QueryTree";h->setTime();mStream.setEnd((char*)(h+1));}};
AgentSubtypeMarker in3;
{
in3.m_pBodyA=&bodyA;
in3.m_pBodyB=&bodyB;
in3.m_pContactManager=m_pContactManager;
in3.m_pRayCastInput=&input;
const hkMotionState*msA=bodyA.GetMotionState();
const hkMotionState*msB=bodyB.GetMotionState();
MotionUtilities::calcTimInfo(*msA,*msB,input.m_pStepInfo.m_fTimeStep,in3.m_vSubtypePosition);
reinterpret_cast<::hkTransformCB22 *>(&(in3.m_kTransform))->FUN_00cb22f0((const ::hkTransformCB22 &)(msA->getTransform()),(const ::hkTransformCB22 &)(msB->getTransform()));
}
hkInplaceArray<hkpShapeKey,128>hitList;
hitList.pushBackUnchecked(0xffffffff);
hkResult prepareSuccessful;
{
hkTransform bTa;reinterpret_cast<::FUN_00cb21e0_shell *>(&(bTa))->FUN_00cb21e0((const ::Matrix44 *)&(in3.m_kTransform));
prepareSuccessful=hkpBvTreeAgent::BuildCollisionHitList(bodyA,bodyB,bTa,in3.m_vSubtypePosition,input,&m_kBoundingBox,hitList);
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName=str_010ce7d4;h->setTime();mStream.setEnd((char*)(h+1));}};
if(prepareSuccessful==HK_SUCCESS)
{
int newMemNeeded=(hitList.GetLogicalSize()/ 4+1-m_kAgentNnTrack.m_kSectors.GetLogicalSize())*hkpAgent1nSector::SECTOR_SIZE;
if(!hkHasMemoryAvailable(3,newMemNeeded))
{
::FUN_00d88040((*(int *)&(const ::hkMemoryAllocator::MemoryState &)(hkMemoryAllocator::MEMORY_STATE_OUT_OF_MEMORY)));
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="l" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
AlgorithmUtilities::quickSort(hitList.begin(),hitList.GetLogicalSize());
;
const hkpBvTreeShape*bvB=static_cast<const hkpBvTreeShape*>(bodyB.getShape());
const hkpShapeContainer*shapeContainer=bvB->GetShapeContainer();
::fnv_00da4aa0::FUN_00da4aa0((::fnv_00da4aa0::Q30 &)(m_kAgentNnTrack),(const ::fnv_00da4aa0::Q14 &)(in3),(const ::fnv_00da4aa0::Q24 *)(shapeContainer),hitList.begin(),(::fnv_00da4aa0::Q6 &)(output));
}
else
{
const hkpBvTreeShape*bvB=static_cast<const hkpBvTreeShape*>(bodyB.getShape());
const hkpShapeContainer*shapeContainer=bvB->GetShapeContainer();
::fnv_00da4aa0::FUN_00da4aa0((::fnv_00da4aa0::Q30 &)(m_kAgentNnTrack),(const ::fnv_00da4aa0::Q14 &)(in3),(const ::fnv_00da4aa0::Q24 *)(shapeContainer),0,(::fnv_00da4aa0::Q6 &)(output));
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="l" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
#include "generated/data/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.inc"
