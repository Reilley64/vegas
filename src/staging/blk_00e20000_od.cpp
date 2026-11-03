
// src/staging/blk_00e20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "fnv/symbols_00c85000.h"
#include <intrin.h>
#include "fnv/symbols_00c90000.h"
#include "../../include/layout_support.h"
#include <xmmintrin.h>
#include <new>
#include <windows.h>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/D04B90World.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00e39e50_cls.h"
#include "fnv/decl/fnv_00e2cfe0__TrianglePlane.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d04000.h"
#include "fnv/symbols_00d1d000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_010c3000.h"
#include "fnv/symbols_010cc000.h"
#include "fnv/symbols_010db000.h"
#include "fnv/symbols_010ed000.h"
#include "fnv/symbols_011b3000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/decl/RotationRows.h"
#include "fnv/symbols_00d1b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0104e000.h"
#include <math.h>
#include <math.h>
#include "fnv/symbols_simd.h"
#include <cmath>
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_0104d000.h"

extern "C" {
void _ReadWriteBarrier();
}

struct Vertex { __m128 position; __m128 supportA; __m128 supportB; int flags; int unk34; int unk38; int unk3c; };

struct Face;

struct Edge {
    Vertex* vertex;
    Edge* next;
    Edge* opposite;
    Face* face;
};

struct Face {
    __m128 normal;
    Edge edges[3];
    float distance;
    int flags;
    int unk48;
    int unk4c;
    __declspec(noinline) Vertex* ComputePlane();
};

static __forceinline __m128 dot3(__m128 a, __m128 b) {
    __m128 v = _mm_mul_ps(a,b);
    return _mm_add_ss(_mm_shuffle_ps(v,v,0xaa), _mm_add_ss(_mm_shuffle_ps(v,v,0x55),v));
}
Vertex* Face::ComputePlane() {
    Vertex* first = edges[0].vertex;
    __m128 a = _mm_sub_ps(first->position,edges[1].vertex->position);
    __m128 b = _mm_sub_ps(edges[1].vertex->position,edges[2].vertex->position);
    __m128 n = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a,a,0xc9),_mm_shuffle_ps(b,b,0xd2)),_mm_mul_ps(_mm_shuffle_ps(a,a,0xd2),_mm_shuffle_ps(b,b,0xc9)));
    __m128 len = dot3(n,n);
    __m128 inv = _mm_rsqrt_ss(len);
    __m128 scale = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(::fnv_00c88020::DAT_01016248),inv), _mm_sub_ss(_mm_set_ss(::DAT_01017718), _mm_mul_ss(_mm_mul_ss(len,inv),inv)));
    scale = _mm_andnot_ps(_mm_cmpeq_ss(len,_mm_set_ss(::DAT_01011d78)), scale);
    normal = n;
    _ReadWriteBarrier();
    normal = _mm_mul_ps(n,_mm_shuffle_ps(scale,scale,0));
    float d;
    _mm_store_ss(&d,dot3(normal,first->position));
    distance = d;
    return first;
}

struct InitEntry { int vertexOffset; int faceOffset; int edgeOffset; };

struct Hull {
    int unk00; int unk04; int unk08; int unk0c;
    int faceCount; int unk14; int unk18; int unk1c;
    Vertex vertices[55];
    Face* freeFaces[100];
    Face faces[4];
    void FUN_00e2d440();
};

// @fnv 0x00e2d440
void Hull::FUN_00e2d440() {
    faceCount = 4;
    InitEntry* init = DAT_010ed0f0;
    Face* end = faces + 4;
    for (Face* face = faces; face != end; ++face) {
        face->edges[0].next = &face->edges[1];
        face->edges[1].next = &face->edges[2];
        face->flags = 0;
        face->edges[2].next = &face->edges[0];
        for (Edge* edge = face->edges; edge < face->edges + 3; ++edge) {
            edge->face = face;
            edge->vertex = (Vertex*)((char*)vertices + init->vertexOffset);
            edge->opposite = (Edge*)((char*)&faces[0].edges[0] + init->faceOffset + init->edgeOffset);
            ++init;
        }
    }
    Face* begin = faces;
    Face* last = &faces[3];
    reinterpret_cast<::fnv_00e2cfe0::TrianglePlane *>((last))->ComputePlane();
    float d;
    _mm_store_ss(&d,dot3(_mm_sub_ps(vertices[0].position,vertices[1].position),last->normal));
    if (d > 0.0f) {
        faces[2].edges[0].vertex = &vertices[1];
        faces[1].edges[0].vertex = &vertices[1];
        begin->edges[0].vertex = &vertices[1];
        last->edges[0].vertex = &vertices[0];
        faces[1].edges[1].vertex = &vertices[0];
        begin->edges[2].vertex = &vertices[0];
    }
    Face* face = begin;
    int i = 3;
    do { reinterpret_cast<::fnv_00e2cfe0::TrianglePlane *>((face))->ComputePlane(); ++face; } while (--i >= 0);
}

struct E29Src { int idx[4]; int n; };

struct E29SrcList { E29Src* data; int count; };

struct E29Item { __m128 a; __m128 b; char flag20; int val24; };

struct E29Out1 { E29Item item; void* ptr30; int one34; int zero38; char unk3c; char flag3d; };

struct E29Out2 { E29Item items[4]; int count; char flagC4; void* ptrs[4]; int unkD8; int unkDC; int zeros[4]; int unkF0; };

// @fnv 0x00e29a10
void FUN_00e29a10(E29SrcList* src, const __m128* posA, const __m128* posB, char* base, E29Out1* out1, int* outCount1, E29Out2* out2, int* outCount2)
{
    int n1 = 0;
    int n2 = 0;
    int count = src->count;
    E29Out2* o2 = out2;
    E29Out1* o1 = out1;
    for (int i = 0; i < count; ++i) {
        E29Src* s = &src->data[i];
        int n = s->n;
        if (n == 1) {
            int k = s->idx[0];
            o1->item.a = posA[k];
            o1->item.b = posB[k];
            o1->item.val24 = 0;
            o1->item.flag20 = 0;
            o1->ptr30 = base + k * 0x60;
            o1->one34 = 1;
            o1->zero38 = 0;
            o1->flag3d = 0;
            o1++;
            n1++;
        } else {
            for (int j = 0; j < n; ++j) {
                int k = s->idx[j];
                o2->items[j].a = posA[k];
                o2->items[j].b = posB[k];
                o2->items[j].val24 = 0;
                o2->items[j].flag20 = 0;
                o2->ptrs[j] = base + k * 0x60;
                o2->zeros[j] = 0;
            }
            o2->count = n;
            o2->flagC4 = 0;
            o2++;
            n2++;
        }
    }
    *outCount1 = n1;
    *outCount2 = n2;
}

namespace fnv_00e2ab00 {
extern "C" { void _ReadWriteBarrier(); }

// @fnv 0x00e2ab00
__m128* FUN_00e2ab00(__m128* src, __m128* out1, __m128* out2) {
    out1[0] = src[0];
    out2[0] = src[1];
    out1[1] = src[3];
    out2[1] = src[4];
    out1[2] = src[6];
    out2[2] = src[7];

    __m128 d0 = src[9];
    _ReadWriteBarrier();
    __m128 a2 = out1[2];
    __m128 a0 = out1[0];
    __m128 d1 = src[10];
    __m128 a1 = out1[1];
    __m128 t2 = _mm_shuffle_ps(a2, d0, 0x44);
    __m128 t1 = _mm_shuffle_ps(a0, a1, 0xEE);
    __m128 t3 = _mm_shuffle_ps(a2, d0, 0xEE);
    __m128 t0 = _mm_shuffle_ps(a0, a1, 0x44);
    out1[0] = _mm_shuffle_ps(t0, t2, 0x88);
    out1[2] = _mm_shuffle_ps(t1, t3, 0x88);
    out1[1] = _mm_shuffle_ps(t0, t2, 0xDD);

    __m128 b0 = out2[0];
    __m128 b1 = out2[1];
    __m128 b2 = out2[2];
    __m128 u0 = _mm_shuffle_ps(b0, b1, 0x44);
    __m128 u1 = _mm_shuffle_ps(b0, b1, 0xEE);
    __m128 u2 = _mm_shuffle_ps(b2, d1, 0x44);
    __m128 u3 = _mm_shuffle_ps(b2, d1, 0xEE);
    out2[0] = _mm_shuffle_ps(u0, u2, 0x88);
    out2[1] = _mm_shuffle_ps(u0, u2, 0xDD);
    out2[2] = _mm_shuffle_ps(u1, u3, 0x88);
    return out1;
}
}

// namespace fnv_00e2ab00


struct Router_e3a1 {
    int unk00, unk04, unk08, unk0C;
    void* m_pStreamAllocator;
};


struct __declspec(align(16)) Key_e3a1 {
    float m_ax, m_ay, m_az, m_aw;
    float m_bx, m_by, m_bz, m_bw;
};

template <class T> struct hkArray_e3a1 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void AddBack(const T& t)
    {
        Router_e3a1* router = static_cast<Router_e3a1*>(::FUN_00c85750());
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(router->m_pStreamAllocator), (::AudioStream *)(void *)(this), sizeof(T));
        new (&m_data[m_iElementCount]) T(t);
        m_iElementCount++;
    }
};

struct Track_e3a1 {
    int unk00, unk04;
    int m_numKeys;
    int m_pRayCursor;
    hkArray_e3a1<Key_e3a1> m_keys;
    void FUN_00e3a1e0(int numKeys);
};

// @fnv 0x00e3a1e0
void Track_e3a1::FUN_00e3a1e0(int numKeys)
{
    m_pRayCursor = numKeys;
    m_numKeys = 0;
    for (int i = 0; i < m_pRayCursor; i++) {
        Key_e3a1 key;
        reinterpret_cast<::FUN_00e39e50_cls *>(&(key))->FUN_00e39e50();
        m_keys.AddBack(key);
    }
}

void __cdecl FUN_00d1bb50(void*, void*, void*, void*, void*, void*, void*, void*, void*, int) throw();

typedef __m128 FourFloatVector;

__forceinline FourFloatVector packFractions(float x,float y,float z,float w) { FourFloatVector v; v[0]=x; v[1]=y; v[2]=z; v[3]=w; return v; }

struct RaySource {
    FourFloatVector from, to;
    unsigned char enable; unsigned char unk21; unsigned short unk22;
    unsigned filter;
    unsigned unk28, unk2c;
};

struct RayBatch {
    RaySource rays[4];
    unsigned type;
    unsigned char flag; unsigned char unkc5; unsigned short unkc6;
    void* filters[4];
    unsigned unkd8, unkdc;
    void* hits[4];
};

struct LocalRay {
    FourFloatVector from, to;
    unsigned char enable; unsigned char unk21; unsigned short unk22;
    unsigned filter;
    unsigned unk28, unk2c;
    void* userFilter;
    int one; void* zero;
    unsigned char hit, flag; unsigned short unk3e;
    __forceinline void assign(const RaySource& s) { from=s.from; to=s.to; enable=s.enable; filter=s.filter; }
};

struct RayCollectorBase {
    void* vtable;
    int mode;
    float fraction;
    unsigned char hit; unsigned char unk0d; unsigned short unk0e;
};

struct Collector {
    void* vt0; void* vt1; void* vt2;
    RayCollectorBase ray;
    LocalRay* input; LocalRay* input2;
    void* filter; void* filter2;
    unsigned unk2c;
    FourFloatVector normal;
    FourFloatVector point;
    unsigned unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    unsigned unk70, unk74, unk78, unk7c;
    __forceinline LocalRay* setup(LocalRay* r, const RaySource& source, void* f, int m, unsigned char flag) {
        r->userFilter=f; filter=f; filter2=f;
        r->from=source.from; r->to=source.to;
        r->enable=source.enable; r->filter=source.filter;
        r->flag=flag; r->one=1; r->zero=0;
        input2=r; input=r;
ray.mode=m;         return r;
    }
    __forceinline void init() {
        ray.fraction = 1.0f; vt0 = &DAT_010dbaf8; vt1 = &DAT_010dbae4; vt2 = &DAT_010dbad8; ray.vtable = &DAT_010dbacc;
        unk50 = 0; unk54 = 0; unk60 = 0; ray.hit = 0;
    }
};

struct Bundle {
    FourFloatVector fromX, fromY, fromZ, toX, toY, toZ;
    void* dispatch;
};

struct FractionValues { float x,y,z,w; };

struct FractionArg { FourFloatVector* ptr; };

struct Owner { unsigned unk00, unk04, unk08, unk0c; void* context; };

// @fnv 0x00e2b510
void __cdecl FUN_00e2b510(Owner* owner, RayBatch* input, int mode, FourFloatVector& fractions) {
    if (!owner) return;
    Bundle bundle;
    FUN_00d1bb50(&bundle, &input->rays[0].from, &input->rays[0].to,
        &input->rays[1].from, &input->rays[1].to, &input->rays[2].from,
        &input->rays[2].to, &input->rays[3].from, &input->rays[3].to, 15);
    LocalRay rays[4];
    rays[0].hit=0; rays[1].hit=0; rays[2].hit=0; rays[3].hit=0;
    Collector collectors[4];
    collectors[0].init(); collectors[1].init(); collectors[2].init(); collectors[3].init();
    float values[4];
    RayCollectorBase* pointers[4];
    for (int i = 0; i < 4; i++) {
        rays[i].userFilter = input->filters[i];
        collectors[i].filter = rays[i].userFilter;
        collectors[i].filter2 = rays[i].userFilter;
        rays[i].assign(input->rays[i]);
        rays[i].flag = input->flag;
        rays[i].one = 1;
        rays[i].zero = 0;
        collectors[i].ray.mode = mode;
        collectors[i].input2 = &rays[i];
        collectors[i].input = &rays[i];
        values[i] = fractions[i];
        pointers[i] = &collectors[i].ray;
    }
    bundle.dispatch = (*reinterpret_cast<void * (*)[]>(&::DAT_011b3830))[input->type];
    ::FUN_00d1d490();
    for (int i = 0; i < 4; i++) input->hits[i] = rays[i].zero;
    fractions = _mm_setr_ps(values[0], values[1], values[2], values[3]);
    volatile Collector* p = collectors + 4;
    int n = 3;
    do {
        --p;
        p->ray.vtable = &DAT_010ccfac; p->vt2 = &DAT_010ccfa0;
        p->vt1 = &DAT_010ccf8c; p->vt0 = &DAT_010c3bb8;
    } while (--n >= 0);
}

extern "C" void _ReadWriteBarrier(void);

unsigned __int64 __cdecl __rdtsc(void);

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct ProfRec2
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
    const char* m_pName2;
};

struct ProfBuf
{
    DWORD unk00;
    char* m_pCur;
    DWORD unk08;
    char* m_pRecordEnd;
};

class ScrapAllocator
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* Alloc(int& aiSize);
    virtual void Free(void* p, unsigned int size);
};

struct ScrapHolder
{
    DWORD unk00, unk04, unk08, unk0C;
    ScrapAllocator* m_pAllocationContext;
};

template <class T> struct ScrapArr
{
    T* m_pData;
    int m_uiLogicalSize;
    unsigned int m_uiCap;
};

class JobTarget
{
public:
};

struct __declspec(align(16)) AutoJob
{
    unsigned char m_cType;
    unsigned char m_c01;
    unsigned char m_c02;
    unsigned char m_c03;
    unsigned short m_sSize;
    short m_s06;
    int unk08;
    int unk0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int unk1C;
    int* m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    float m_f38;
    float m_f3C;
    int m_i40;
    int m_i44;
    int unk48;
    int m_i4C;
    int unk50;
    int m_i54;
    int m_i58;
    JobTarget* m_p5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
};

__forceinline void InitJob(AutoJob& j)
{
    j.m_cType = 7;
    j.m_c01 = 3;
    j.m_c02 = 2;
    j.m_sSize = 0x70;
    j.m_s06 = -1;
    j.m_i10 = 0;
    j.m_i18 = 0;
    j.m_c02 = 1;
    j.m_i14 = 0;
    j.m_i64 = 0;
    j.m_i68 = 0;
}

struct JobSource
{
    DWORD unk00, unk04, unk08, unk0C;
    JobTarget* m_p10;
    int m_i14;
    int unk18;
    int m_i1C;
    int unk20;
    int m_i24;
    int unk28;
    int m_i2C;
    int unk30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
};

class JobQueue
{
public:
};

class JobWaiter
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Start(JobQueue* m_pPrimaryTaskProcessor, int iType);
    virtual void Wait();
};

struct SplitOut
{
    int unk00, unk04, unk08, unk0C;
};

struct SplitResult
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
};

void __cdecl FUN_00e29b80(intptr_t a, intptr_t b, int n, void* p1, void* p2, void* p3, SplitResult* pOut);

__forceinline void ProfMark(const char* pName)
{
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = (ProfRec*)pBuf->m_pCur;
        pRec->m_pName = pName;
        { unsigned int ticks;
ticks = (unsigned int)__rdtsc();
pRec->m_iTick = ticks; }
        pBuf->m_pCur = (char*)(pRec + 1);
    }
}

__forceinline void ProfMark2(const char* pName, const char* pName2)
{
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec2* pRec = (ProfRec2*)pBuf->m_pCur;
        pRec->m_pName = pName;
        pRec->m_pName2 = pName2;
        { unsigned int ticks;
ticks = (unsigned int)__rdtsc();
pRec->m_iTick = ticks; }
        pBuf->m_pCur = (char*)(pRec + 1);
    }
}

template <class T> __forceinline T* BufAlloc(ScrapAllocator* pAlloc, int& n)
{
    int bytes = n * sizeof(T);
    T* p = (T*)pAlloc->Alloc(bytes);
    n = bytes / (int)sizeof(T);
    return p;
}

template <class T> __forceinline void ArrInit(T*& rData, unsigned int& rCap, int n)
{
    ScrapHolder* pHolder = ((ScrapHolder*)static_cast<Router_e3a1*>(::FUN_00c85750()));
    ScrapAllocator* pAlloc = pHolder->m_pAllocationContext;
    int cap = n;
    rData = cap ? BufAlloc<T>(pAlloc, cap) : 0;
    rCap = cap ? cap : 0x80000000;
}

template <class T> __forceinline void ArrFree(T* pData, unsigned int uiCap)
{
    ScrapHolder* pHolder = ((ScrapHolder*)static_cast<Router_e3a1*>(::FUN_00c85750()));
    ScrapAllocator* pAlloc = pHolder->m_pAllocationContext;
    if ((uiCap & 0x80000000) == 0)
        pAlloc->Free(pData, (uiCap & 0x3fffffff) * sizeof(T));
}

template <class T> __forceinline void ArrClearFree(ScrapArr<T>& arr)
{
    ScrapHolder* pHolder = ((ScrapHolder*)static_cast<Router_e3a1*>(::FUN_00c85750()));
    ScrapAllocator* pAlloc = pHolder->m_pAllocationContext;
    unsigned int cap = arr.m_uiCap;
    arr.m_uiLogicalSize = 0;
    if ((cap & 0x80000000) == 0)
        pAlloc->Free(arr.m_pData, (cap & 0x3fffffff) * sizeof(T));
    arr.m_pData = 0;
    arr.m_uiCap = 0x80000000;
}

// @fnv 0x00e2a390
void __cdecl FUN_00e2a390(int a, int b, int n, float f1, float f2, JobSource* pSrc,
                          JobQueue* m_pPrimaryTaskProcessor, JobWaiter* pWaiter, int iParam, bool bAuto)
{
    if (bAuto)
    {
        ProfMark2("LtAutoJob", "StAddJobs");
        int off1 = pSrc->m_i24;
        int off2 = pSrc->m_i2C;
        for (int i = 0; i < 8; i++)
        {
            AutoJob job;
            job.m_cType = 7;
            job.m_c01 = 3;
            job.m_sSize = 0x70;
            job.m_s06 = -1;
            job.m_i10 = 0;
            job.m_i18 = 0;
            job.m_c02 = 1;
            job.m_i14 = 0;
            job.m_i20 = (int*)0;
            job.m_i24 = i;
            job.m_i28 = 0;
            job.m_i2C = a;
            job.m_i30 = b;
            job.m_i34 = n;
            job.m_f38 = f1;
            job.m_f3C = f2;
            job.m_i40 = iParam;
            job.m_i44 = off1;
            job.m_i4C = off2;
            job.m_i54 = pSrc->m_i1C;
            job.m_i58 = pSrc->m_i14;
            job.m_p5C = pSrc->m_p10;
            job.m_i60 = pSrc->m_i34;
            job.m_i64 = pSrc->m_i38;
            job.m_i68 = pSrc->m_i3C;
            job.m_i6C = pSrc->m_i40;
            reinterpret_cast<::D04B90World *>((m_pPrimaryTaskProcessor))->AddObjectCopy((const ::D04B90Object *)(::AutoJob *)(&job), (void *)(1));
            off1 += n << 6;
            off2 += n << 8;
        }
        pWaiter->Start(m_pPrimaryTaskProcessor, 0xb);
        ProfMark("StWaitThreads");
        pWaiter->Wait();
        ProfMark("lt");
        ::FUN_00d04380((void *)(pSrc->m_p10), {});
        return;
    }

    ProfMark("TtCPUSplit");
    SplitOut* pData1;
    unsigned int uiCap1;
    SplitOut* pData2;
    unsigned int uiCap2;
    ScrapArr<int>* pData3;
    int iSize3;
    unsigned int uiCap3;
    int* pData4;
    unsigned int uiCap4;
    int* pData5;
    unsigned int uiCap5;
    {
    ArrInit(pData1, uiCap1, n);
    ArrInit(pData2, uiCap2, n);
    {
        ScrapHolder* pHolder = ((ScrapHolder*)static_cast<Router_e3a1*>(::FUN_00c85750()));
        int cap = 8;
        pData3 = cap ? BufAlloc<ScrapArr<int> >(pHolder->m_pAllocationContext, cap) : 0;
        iSize3 = cap;
        uiCap3 = cap ? cap : 0x80000000;
    }
    for (int k = 0; k < iSize3; k++)
    {
        ScrapArr<int>* pElem = &pData3[k];
        if (pElem != 0)
        {
            pElem->m_pData = 0;
            pElem->m_uiLogicalSize = 0;
            pElem->m_uiCap = 0x80000000;
        }
    }
    SplitResult out;
    FUN_00e29b80(a, b, n, pData1, pData2, pData3, &out);
    ArrInit(pData4, uiCap4, 8);
    ArrInit(pData5, uiCap5, 8);

    int off1 = pSrc->m_i24;
    int off2 = pSrc->m_i2C;
    for (int j = 0; j < 8; j++)
    {
        if (pData3[j].m_uiLogicalSize == 0)
            continue;
        {
            AutoJob job;
            InitJob(job);
            job.m_i20 = pData3[j].m_pData;
            job.m_i28 = pData3[j].m_uiLogicalSize;
            job.m_i2C = a;
            job.m_i30 = b;
            job.m_i34 = n;
            job.m_f38 = f1;
            job.m_f3C = f2;
            job.m_i40 = iParam;
            job.m_i44 = off1;
            job.m_i4C = off2;
            job.m_i54 = pSrc->m_i1C;
            job.m_i58 = pSrc->m_i14;
            job.m_p5C = pSrc->m_p10;
            job.m_i60 = pSrc->m_i34;
            job.m_i64 = pSrc->m_i38;
            job.m_i68 = pSrc->m_i3C;
            job.m_i6C = pSrc->m_i40;
            reinterpret_cast<::D04B90World *>((m_pPrimaryTaskProcessor))->AddObjectCopy((const ::D04B90Object *)(::AutoJob *)(&job), (void *)(1));
            off1 += n << 6;
            off2 += n << 8;
        }
    }
    }
    ProfMark("Et");
    ProfMark("TtAutoBundleJobs");
    pWaiter->Start(m_pPrimaryTaskProcessor, 0xb);
    pWaiter->Wait();
    ::FUN_00d04380((void *)(pSrc->m_p10), {});
    ProfMark("Et");

    ArrFree(pData5, uiCap5);
    ArrFree(pData4, uiCap4);
    {
        ScrapAllocator* pAlloc = ((ScrapHolder*)static_cast<Router_e3a1*>(::FUN_00c85750()))->m_pAllocationContext;
        for (int k = 0; k < iSize3; k++)
            ArrClearFree(pData3[k]);
        if ((uiCap3 & 0x80000000) == 0)
            pAlloc->Free(pData3, (uiCap3 & 0x3fffffff) * sizeof(ScrapArr<int>));
    }
    ArrFree(pData2, uiCap2);
    ArrFree(pData1, uiCap1);
}

namespace SplineMax {
struct Vec { __m128 value; };
struct Points { Vec* data; int count; int capacity; };
}

// @fnv 0x00e314c0
SplineMax::Vec __cdecl FUN_00e314c0(const SplineMax::Points& input)
{
    SplineMax::Vec result = input.data[0];
    const int count = input.count;
    for (int i = 1; i < count; ++i)
        result.value = _mm_max_ps(result.value, input.data[i].value);
    return result;
}

struct MinVec4 {
    __m128 m_vComponents;
    void setMin4(const MinVec4& a, const MinVec4& b) { m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents); }
};

struct MinVec4Array {
    MinVec4* m_data;
    int m_iElementCount;
};

// @fnv 0x00e31470
MinVec4 __cdecl FUN_00e31470(const MinVec4Array& arr)
{
    MinVec4 r = arr.m_data[0];
    for (int i = 1; i < arr.m_iElementCount; i++)
        r.setMin4(r, arr.m_data[i]);
    return r;
}

struct ConvexShapeStub
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
    virtual void GetSupportingVertex(const __m128* dir, __m128* out);
};

struct SupportResult
{
    __m128 pointA;
    __m128 pointB;
    __m128 normal;
};

struct TransformStub
{
    __m128 col0;
    __m128 col1;
    __m128 col2;
    __m128 translation;
};

static const __m128 kNegMask = {-0.0f, -0.0f, -0.0f, -0.0f};

// @fnv 0x00e2da40
static void FUN_00e2da40(ConvexShapeStub* self, ConvexShapeStub* other, SupportResult* result, const __m128* dir,
                         const TransformStub* xf)
{
    __m128 negDir = _mm_xor_ps(*dir, kNegMask);
    __m128 a;
    self->GetSupportingVertex(&negDir, &a);
    __m128 c0 = xf->col0;
    __m128 c2 = xf->col2;
    __m128 c1 = xf->col1;
    {
        __m128 tmp = _mm_unpacklo_ps(c0, c1);
        __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(tmp, c2);
        tmp = _mm_movehl_ps(c0, tmp);
        c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
        c2 = ctmp;
    }
    __m128 localDir = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*dir, *dir, 0x55), c1), _mm_mul_ps(_mm_shuffle_ps(*dir, *dir, 0x00), c0)),
        _mm_mul_ps(_mm_shuffle_ps(*dir, *dir, 0xaa), c2));
    __m128 b;
    other->GetSupportingVertex(&localDir, &b);
    __m128 bw = _mm_add_ps(
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0x55), xf->col1), _mm_mul_ps(_mm_shuffle_ps(b, b, 0x00), xf->col0)),
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xaa), xf->col2), xf->translation));
    __m128 d = _mm_mul_ps(_mm_sub_ps(a, bw), *dir);
    float dist;
    _mm_store_ss(&dist, _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d)));
    float* w = (float*)&result->normal;
    if (dist > w[3])
    {
        result->normal = *dir;
        result->pointA = a;
        result->pointB = b;
        w[3] = dist;
    }
}

void CallerOfIt(ConvexShapeStub* s, ConvexShapeStub* o, SupportResult* r, const __m128* d, const TransformStub* x)
{
    FUN_00e2da40(s, o, r, d, x);
    FUN_00e2da40(o, s, r, d + 1, x);
    FUN_00e2da40(s, s, r, d + 2, x);
}

// @fnv 0x00e31180
void FUN_00e31180(const float* base, int stride, int count, int mul, int offset, __m128** dst)
{
    for (int i = 0; i < count; i++)
        (*dst)[i] = _mm_setr_ps(base[(stride * mul + offset) + i * stride], 0.0f, 0.0f, 0.0f);
}

class __declspec(align(16)) hkVector4E3B
{
  public:
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }

    __m128 m_vComponents;
};

class hkRotationE3B
{
  public:
    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }

    hkVector4E3B m_kColumn0;
    hkVector4E3B m_kColumn1;
    hkVector4E3B m_kColumn2;
};

class ChildE3B
{
  public:
};

class FrameE3B
{
  public:
    void FUN_00e3b630(const void* pSource);

    int m_unk[8];
    hkRotationE3B m_rotation;
    ChildE3B m_pChildAtom;
};

// @fnv 0x00e3b630
void FrameE3B::FUN_00e3b630(const void* pSource)
{
    m_rotation.setIdentity();
    reinterpret_cast<::RotationRows *>(&(m_pChildAtom))->FUN_00cb2d90((void *)(pSource));
}



void __cdecl FUN_00e2a390(int a, int b, int n, float f1, float f2, JobSource* pSrc, JobQueue* m_pPrimaryTaskProcessor, JobWaiter* pWaiter, int iParam, bool bAuto);

struct S00e29b80_Allocator;

struct S00e29b80_Router
{
    int unk00, unk04, unk08, unk0C;
    S00e29b80_Allocator* m_pStreamAllocator;
    S00e29b80_Allocator& heap() { return *m_pStreamAllocator; }
    static __forceinline S00e29b80_Router& GetMonitorStream() { return *(S00e29b80_Router*)static_cast<Router_e3a1*>(::FUN_00c85750()); }
};

struct S00e29b80_HeapAllocator
{
    S00e29b80_Allocator& get(const void*) { return S00e29b80_Router::GetMonitorStream().heap(); }
};


typedef __m128 S00e29b80_QuadReal;

typedef float hkReal;

typedef int hkBool32;

class S00e29b80_SimdReal
{
public:
    S00e29b80_SimdReal(const S00e29b80_QuadReal& x) : m_vValue(x) {}
    S00e29b80_SimdReal(hkReal x) { m_vValue = _mm_load_ss(&x); }
    S00e29b80_SimdReal() {}
    operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline const S00e29b80_QuadReal& getQuad() const { return m_vValue; }
private:
    S00e29b80_QuadReal m_vValue;
};

class S00e29b80_Comparison
{
public:
    enum S00e29b80_Mask { MASK_NONE = 0, MASK_X = 1, MASK_Y = 2, MASK_Z = 4, MASK_W = 8 };
    __forceinline hkBool32 anyIsSet(S00e29b80_Mask m) const { return _mm_movemask_ps(m_uiMask) & m; }
    S00e29b80_QuadReal m_uiMask;
};

class S00e29b80_Vector4
{
public:
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void setSub4(const S00e29b80_Vector4& v0, const S00e29b80_Vector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline S00e29b80_SimdReal dot3(const S00e29b80_Vector4& a) const
    {
        S00e29b80_QuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        S00e29b80_QuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00e29b80_Comparison compareLessThanZero4() const
    {
        S00e29b80_Vector4 zero; zero.setZero4();
        S00e29b80_Comparison m; m.m_uiMask = _mm_cmplt_ps(m_vComponents, zero.m_vComponents);
        return m;
    }
    __forceinline S00e29b80_SimdReal fastNormalizeWithLength3()
    {
        S00e29b80_QuadReal len2 = this->dot3(*this).getQuad();
        S00e29b80_QuadReal approx = _mm_rsqrt_ss(len2);
        approx = _mm_shuffle_ps(approx, approx, 0);
        m_vComponents = _mm_mul_ps(m_vComponents, approx);
        return _mm_mul_ss(len2, approx);
    }
    S00e29b80_QuadReal m_vComponents;
};

namespace S00e29b80_hkMath {
    inline hkReal pow(hkReal r, hkReal s) { return ::powf(r, s); }
}

template <typename T>
struct S00e29b80_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void GrowArrayCapacity(S00e29b80_Allocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)(void *)(&alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }
    __forceinline void reserve(int size) { GrowArrayCapacity(S00e29b80_HeapAllocator().get(this), size); }
    __forceinline void pushBackUnchecked(const T& t)
    {
        T* p = m_data + m_iElementCount;
        for (int i = 0; i < 1; ++i)
        {
            p[i] = t;
        }
        m_iElementCount++;
    }
};

// @fnv 0x00e29b80
void __cdecl FUN_00e29b80(intptr_t a, intptr_t b, int numRays, void* p1, void* p2, void* p3, SplitResult* pOut)
{
    for (int i = 0; i < numRays; i++)
    {
        S00e29b80_Vector4& v = ((S00e29b80_Vector4*)p1)[i];
        v.setSub4(((const S00e29b80_Vector4*)b)[i], ((const S00e29b80_Vector4*)a)[i]);
        ((S00e29b80_SimdReal*)p2)[i] = v.fastNormalizeWithLength3();
        ((S00e29b80_SimdReal*)p2)[i] = S00e29b80_hkMath::pow(((S00e29b80_SimdReal*)p2)[i], 2.0f);
    }

    for (int i = 0; i < 8; i++)
    {
        ((int*)pOut)[i] = 0;
        ((S00e29b80_Array<int>*)p3)[i].reserve(numRays);
    }

    for (int i = 0; i < numRays; i++)
    {
        S00e29b80_Comparison c = ((S00e29b80_Vector4*)p1)[i].compareLessThanZero4();
        int octIdx = 0;
        octIdx += c.anyIsSet(S00e29b80_Comparison::MASK_X) ? 1 : 0;
        octIdx += c.anyIsSet(S00e29b80_Comparison::MASK_Y) ? 2 : 0;
        octIdx += c.anyIsSet(S00e29b80_Comparison::MASK_Z) ? 4 : 0;
        ((int*)pOut)[octIdx]++;
        ((S00e29b80_Array<int>*)p3)[octIdx].pushBackUnchecked(i);
    }
}

typedef float hkReal;

typedef __m128 hkQuadReal;

class S2db70_SimdReal
{
public:
    S2db70_SimdReal(const hkQuadReal& x) : m_vValue(x) {}
    S2db70_SimdReal(hkReal x) { m_vValue = _mm_load_ss(&x); }
    __forceinline hkQuadReal broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const hkQuadReal& getQuad() const { return m_vValue; }
private:
    hkQuadReal m_vValue;
};

typedef const S2db70_SimdReal& S2db70_SimdRealParameter;

class S2db70_Vector4
{
public:
    hkQuadReal m_vComponents;
    inline void operator=(const S2db70_Vector4& v) { m_vComponents = v.m_vComponents; }
    inline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    inline void setAdd4(const S2db70_Vector4& v0, const S2db70_Vector4& v1) { m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents); }
    inline void setSub4(const S2db70_Vector4& v0, const S2db70_Vector4& v1) { m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents); }
    inline void mul4(S2db70_SimdRealParameter s) { m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents); }
    inline void setNeg4(const S2db70_Vector4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0); }
    inline void setCross(const S2db70_Vector4& v0, const S2db70_Vector4& v1)
    {
        hkQuadReal cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        hkQuadReal cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    inline S2db70_SimdReal dot3(const S2db70_Vector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    inline S2db70_SimdReal lengthInverse3() const
    {
        const hkQuadReal half = _mm_set_ss(0.5f);
        const hkQuadReal three = _mm_set_ss(3.0f);
        const hkQuadReal zero = _mm_set_ss(0.0f);
        const hkQuadReal len2 = this->dot3(*this).getQuad();
        const hkQuadReal len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const hkQuadReal approx = _mm_rsqrt_ss(len2);
        const hkQuadReal refined = _mm_mul_ss(
            _mm_mul_ss(half, approx),
            _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    inline void normalize3()
    {
        hkQuadReal lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    inline hkReal& operator()(int a) { return reinterpret_cast<hkReal*>(&m_vComponents)[a]; }
    inline const hkReal& operator()(int a) const { return reinterpret_cast<const hkReal*>(&m_vComponents)[a]; }
};

struct S2db70_Transform { S2db70_Vector4 m_kColumn0, m_kColumn1, m_kColumn2, m_vTranslation; };

struct S2db70_Shape
{
    virtual void unk00();
    virtual void GetSupportPoint(const S2db70_Vector4& dir, S2db70_Vector4& out) const;
};

struct S2db70_Sample
{
    S2db70_Vector4 m_vFirstVector;
    S2db70_Vector4 m_vSecondVector;
    S2db70_Vector4 m_vHitNormal;
    hkReal& getDistance() { return m_vHitNormal(3); }
};

struct S2db70_Out
{
    S2db70_Vector4 m_vPointOnShapeA;
    S2db70_Vector4 m_vPointOnShapeB;
    hkReal m_fClosestPointDistanceSquared;
};

static __forceinline hkReal S2db70_fabs(hkReal r) { return (float)fabs(r); }

static __forceinline void S2db70_calculatePerpendicularVector(const S2db70_Vector4& vectorIn, S2db70_Vector4& biVectorOut)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = S2db70_fabs(vectorIn(0));
    hkReal a1 = S2db70_fabs(vectorIn(1));
    hkReal a2 = S2db70_fabs(vectorIn(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    biVectorOut.setZero4();
    biVectorOut(ok1) = vectorIn(ok2);
    biVectorOut(ok2) = -vectorIn(ok1);
}

static __declspec(noinline) void FUN_00e2da40(const S2db70_Shape* shapeA, const S2db70_Shape* shapeB, const S2db70_Transform& aTb, const S2db70_Vector4& dir, S2db70_Sample& sample)
{
    S2db70_Vector4 negDir; negDir.setNeg4(dir);
    S2db70_Vector4 dirInB;
    dirInB.m_vComponents = _mm_add_ps(_mm_add_ps(
        _mm_mul_ps(_mm_shuffle_ps(dir.m_vComponents, dir.m_vComponents, 0x55), aTb.m_kColumn1.m_vComponents),
        _mm_mul_ps(_mm_shuffle_ps(dir.m_vComponents, dir.m_vComponents, 0x00), aTb.m_kColumn0.m_vComponents)),
        _mm_mul_ps(_mm_shuffle_ps(dir.m_vComponents, dir.m_vComponents, 0xaa), aTb.m_kColumn2.m_vComponents));
    S2db70_Vector4 pointA;
    shapeA->GetSupportPoint(negDir, pointA);
    S2db70_Vector4 pointB;
    shapeB->GetSupportPoint(dirInB, pointB);
    S2db70_Vector4 pointBinA;
    pointBinA.m_vComponents = _mm_add_ps(_mm_add_ps(
        _mm_mul_ps(_mm_shuffle_ps(pointB.m_vComponents, pointB.m_vComponents, 0x55), aTb.m_kColumn1.m_vComponents),
        _mm_mul_ps(_mm_shuffle_ps(pointB.m_vComponents, pointB.m_vComponents, 0x00), aTb.m_kColumn0.m_vComponents)),
        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(pointB.m_vComponents, pointB.m_vComponents, 0xaa), aTb.m_kColumn2.m_vComponents), aTb.m_vTranslation.m_vComponents));
    S2db70_Vector4 diff; diff.setSub4(pointA, pointBinA);
    hkReal dist;
    _mm_store_ss(&dist, diff.dot3(dir).getQuad());
    if (sample.getDistance() - dist < 0.0f)
    {
        sample.m_vHitNormal = dir;
        sample.getDistance() = dist;
        sample.m_vFirstVector = pointA;
        sample.m_vSecondVector = pointB;
    }
}

// @fnv 0x00e2db70
extern "C" void FUN_00e2db70(const S2db70_Shape* shapeA, const S2db70_Shape* shapeB, const S2db70_Transform& aTb,
                  S2db70_Vector4& pointAinA, S2db70_Vector4& pointBinB, S2db70_Out& out)
{
    S2db70_Sample sample;
    sample.getDistance() = ::DAT_0104e148;

    const S2db70_Vector4* axis = &(*reinterpret_cast<::S2db70_Transform *>(&::DAT_01268370)).m_kColumn0;
    for (int i = 0; i < 3; i++)
    {
        S2db70_Vector4 dir = *axis;
        axis++;
        FUN_00e2da40(shapeA, shapeB, aTb, dir, sample);
        dir.setNeg4(dir);
        FUN_00e2da40(shapeA, shapeB, aTb, dir, sample);
    }

    for (hkReal eps = 1.0f; eps > 0.001f; )
    {
        eps *= 0.99f;
        S2db70_Vector4 perp;
        S2db70_calculatePerpendicularVector(sample.m_vHitNormal, perp);
        perp.normalize3();
        S2db70_Vector4 cross; cross.setCross(sample.m_vHitNormal, perp);
        perp.mul4(eps);
        cross.mul4(eps);

        S2db70_Vector4 d0; d0.setAdd4(sample.m_vHitNormal, perp);
        S2db70_Vector4 d1; d1.setSub4(sample.m_vHitNormal, perp);
        S2db70_Vector4 d2; d2.setAdd4(sample.m_vHitNormal, cross);
        S2db70_Vector4 d3; d3.setSub4(sample.m_vHitNormal, cross);
        S2db70_SimdReal invLen = d0.lengthInverse3();
        d0.mul4(invLen);
        d1.mul4(invLen);
        d2.mul4(invLen);
        d3.mul4(invLen);

        FUN_00e2da40(shapeA, shapeB, aTb, d0, sample);
        FUN_00e2da40(shapeA, shapeB, aTb, d1, sample);
        FUN_00e2da40(shapeA, shapeB, aTb, d2, sample);
        FUN_00e2da40(shapeA, shapeB, aTb, d3, sample);
        eps *= 0.5f;
    }

    pointAinA = sample.m_vFirstVector;
    pointBinB = sample.m_vSecondVector;
    out.m_vPointOnShapeA = sample.m_vHitNormal;
    out.m_vPointOnShapeB = sample.m_vFirstVector;
    out.m_fClosestPointDistanceSquared = sample.getDistance();
}

struct AvgSrc
{
    const float* values;
    int count;
};

// @fnv 0x00e31410
__m128* FUN_00e31410(__m128* out, AvgSrc* s)
{
    int m = s->count;
    __m128 sum = _mm_setzero_ps();
    *out = sum;
    int n = m;
    if (m > 0)
    {
        const float* p = s->values;
        do
        {
            sum = _mm_add_ps(_mm_load_ps(p), sum);
            p += 4;
            --m;
        } while (m != 0);
        *out = sum;
    }
    _ReadWriteBarrier();
    float inv = 1.0f / (float)n;
    __m128 t = _mm_load_ss(&inv);
    *out = _mm_mul_ps(_mm_shuffle_ps(t, t, 0), *out);
    return out;
}

static __forceinline __m128 inverseSpan(__m128 a, __m128 b) { return _mm_div_ss(_mm_load_ss(&DAT_01012068),_mm_add_ss(a,b)); }

// @fnv 0x00e33670
void FUN_00e33670(float t, int unused, const float* knots, const __m128* ctrl, __m128* out)
{
    float f;
    f = t - knots[1];
    __m128 left1 = _mm_load_ss(&f);
    f = knots[2] - t;
    __m128 right1 = _mm_load_ss(&f);
    __m128 inv = inverseSpan(right1,left1);
    __m128 n01 = _mm_mul_ss(right1, inv);
    f = t - knots[0];
    __m128 left2 = _mm_load_ss(&f);
    f = knots[3] - t;
    __m128 right2 = _mm_load_ss(&f);
    __m128 zero = _mm_load_ss(&::DAT_01011d78);
    __m128 a = _mm_div_ss(_mm_add_ss(zero,n01), _mm_add_ss(right1,left2));
    __m128 b0 = _mm_add_ss(zero,_mm_mul_ss(right1,a));
    __m128 b1left = _mm_mul_ss(left2,a);
    __m128 b = _mm_div_ss(_mm_mul_ss(left1,inv), _mm_add_ss(right2,left1));
    __m128 b1 = _mm_add_ss(b1left,_mm_mul_ss(right2,b));
    __m128 b2 = _mm_mul_ss(left1,b);
    *out = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b1,b1,0),ctrl[1]),_mm_mul_ps(_mm_shuffle_ps(b0,b0,0),ctrl[0])),_mm_mul_ps(_mm_shuffle_ps(b2,b2,0),ctrl[2]));
}

struct Invert6Vector
{
    union
    {
        __m128 quad;
        float component[4];
    };
    __forceinline void multiply(float factor)
    {
        __m128 scalar = _mm_load_ss(&factor);
        quad = _mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), quad);
    }
    __forceinline void addMultiple(float factor, const Invert6Vector& source)
    {
        __m128 scalar = _mm_load_ss(&factor);
        quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), source.quad), quad);
    }
};

struct Invert6Block
{
    Invert6Vector column[3];
    __forceinline void setZero()
    {
        column[0].quad = _mm_setzero_ps();
        column[1].quad = _mm_setzero_ps();
        column[2].quad = _mm_setzero_ps();
    }
    __forceinline void setIdentity()
    {
        column[0].quad = _mm_setzero_ps();
        column[1].quad = _mm_setzero_ps();
        _mm_store_ps(column[2].component, _mm_setzero_ps());
        column[0].component[0] = 1.0f;
        column[1].component[1] = 1.0f;
        column[2].component[2] = 1.0f;
    }
};

struct Invert6Matrix
{
    Invert6Block block[2][2];
    __forceinline Invert6Matrix(const Invert6Matrix& source)
    {
        block[0][0].column[0].quad = source.block[0][0].column[0].quad;
        block[0][0].column[1].quad = source.block[0][0].column[1].quad;
        block[0][0].column[2].quad = source.block[0][0].column[2].quad;
        block[0][1].column[0].quad = source.block[0][1].column[0].quad;
        block[0][1].column[1].quad = source.block[0][1].column[1].quad;
        block[0][1].column[2].quad = source.block[0][1].column[2].quad;
        block[1][0].column[0].quad = source.block[1][0].column[0].quad;
        block[1][0].column[1].quad = source.block[1][0].column[1].quad;
        block[1][0].column[2].quad = source.block[1][0].column[2].quad;
        block[1][1].column[0].quad = source.block[1][1].column[0].quad;
        block[1][1].column[1].quad = source.block[1][1].column[1].quad;
        block[1][1].column[2].quad = source.block[1][1].column[2].quad;
    }
    void FUN_00e29620(const Invert6Matrix& source);
};

// @fnv 0x00e29620
void Invert6Matrix::FUN_00e29620(const Invert6Matrix& source)
{
    Invert6Matrix temporary = source;
    block[0][0].setIdentity();
    block[0][1].setZero();
    block[1][0].setZero();
    block[1][1].setIdentity();
    for (int b = 0; b < 2; ++b)
    {
        for (int i = 0; i < 3; ++i)
        {
            float inverse = 1.0f / temporary.block[b][b].column[i].component[i];
            temporary.block[0][b].column[i].multiply(inverse);
            temporary.block[1][b].column[i].multiply(inverse);
            block[0][b].column[i].multiply(inverse);
            block[1][b].column[i].multiply(inverse);
            for (int k = 0; k < 2; ++k)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (k != b || j != i)
                    {
                        float factor = -temporary.block[b][k].column[j].component[i];
                        temporary.block[0][k].column[j].addMultiple(factor, temporary.block[0][b].column[i]);
                        temporary.block[1][k].column[j].addMultiple(factor, temporary.block[1][b].column[i]);
                        block[0][k].column[j].addMultiple(factor, block[0][b].column[i]);
                        block[1][k].column[j].addMultiple(factor, block[1][b].column[i]);
                    }
                }
            }
        }
    }
}

static void FUN_00e2da40(ConvexShapeStub* self, ConvexShapeStub* other, SupportResult* result, const __m128* dir,
                         const TransformStub* xf);

void CallerOfIt(ConvexShapeStub* s, ConvexShapeStub* o, SupportResult* r, const __m128* d, const TransformStub* x);

struct hkVector4E33
{
    __m128 m_vComponents;
};

__forceinline float ReadScalar(const float& x)
{
    return x;
}

// @fnv 0x00e33440
void __cdecl FUN_00e33440(float u, int iDegree, const float* pfKnots, const hkVector4E33* pkControlPoints,
                          hkVector4E33& kOut)
{
    float N[4];
    float right[4];
    float left[4];

    float* negativeOffsets = left;
    N[0] = 1.0f;
    int iSpan = iDegree - 1;
    for (int j = 1; j <= iDegree; j++)
    {
        left[j] = u - pfKnots[iSpan + 1 - j];
        right[j] = pfKnots[iSpan + j] - u;
        float saved = 0.0f;
        for (int r = 0; r < j; r++)
        {
            float temp = ReadScalar(N[r]) / (right[r + 1] + ReadScalar(negativeOffsets[j - r]));
            N[r] = saved + right[r + 1] * temp;
            saved = ReadScalar(negativeOffsets[j - r]) * temp;
        }
        N[j] = saved;
    }

    __m128 sum = _mm_setzero_ps();
    for (int i = 0; i <= iDegree; i++)
    {
        __m128 w = _mm_load_ss(&N[i]);
        sum = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(w, w, 0), pkControlPoints[i].m_vComponents), sum);
    }
    kOut.m_vComponents = sum;
}

typedef __m128 S2d6c0_Simd;

using ::fnv_00c88020::DAT_01016248;

struct S2d6c0_Vector
{
    S2d6c0_Simd m_vComponents;

    __forceinline float dot3(const S2d6c0_Vector& o) const
    {
        S2d6c0_Simd x = _mm_mul_ps(m_vComponents, o.m_vComponents);
        S2d6c0_Simd r = _mm_add_ss(_mm_shuffle_ps(x, x, 0xaa), _mm_add_ss(_mm_shuffle_ps(x, x, 0x55), x));
        float f;
        _mm_store_ss(&f, r);
        return f;
    }
    __forceinline void setMul4(float s, const S2d6c0_Vector& v)
    {
        m_vComponents = _mm_mul_ps(_mm_load_ps1(&s), v.m_vComponents);
    }
    __forceinline void addMul4(float s, const S2d6c0_Vector& v)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&s),_mm_load_ss(&s),0), v.m_vComponents), m_vComponents);
    }
    __forceinline void normalize3()
    {
        S2d6c0_Simd x = _mm_mul_ps(m_vComponents, m_vComponents);
        S2d6c0_Simd r = _mm_add_ss(_mm_shuffle_ps(x, x, 0xaa), _mm_add_ss(_mm_shuffle_ps(x, x, 0x55), x));
        S2d6c0_Simd e = _mm_rsqrt_ss(r);
        S2d6c0_Simd ret = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                                _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(r, e), e)));
        S2d6c0_Simd inv = _mm_andnot_ps(_mm_cmpeq_ss(r, _mm_set_ss(0.0f)), ret);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), m_vComponents);
    }
};

struct S2d6c0_ScalarResult { float value; };

static inline S2d6c0_ScalarResult S2d6c0_sqrt(float x) { S2d6c0_ScalarResult r; r.value=(float)sqrt(x); return r; }

// @fnv 0x00e2d6c0
extern "C" void __cdecl FUN_00e2d6c0(::Hull* a, ::Hull* b, S2d6c0_Vector* out,
                          ::Face** pa, ::Face** pb)
{
    float best = ::DAT_0104da48;
    float eb = 0.0f;
    float t;
    t = 0.0f;
    for (int i = a->faceCount - 1; i >= 0; i--)
    {
        ::Face* v;
        v = &a->faces[i];
        if (v->distance * v->distance > best)
            continue;
        for (int j = b->faceCount - 1; 1 <= j; j--)
        {
            ::Face* bestS = &b->faces[j];
            if (bestS->distance * bestS->distance > best)
                continue;
            float dot = ((const S2d6c0_Vector&)bestS->normal).dot3((const S2d6c0_Vector&)v->normal);
            if (DAT_0102295c > dot)
                continue;
            float ra = v->distance;
            float rb = bestS->distance;
            float u;
            u = ra - dot * rb;
            float b;
            b = rb - dot * ra;
            float q;
            float d;
            float s;
            if (u > 1.192092896e-07f)
            {
                if (b > 1.192092896e-07f)
                {
                    float x;
                    float y;
                    if (b < u)
                    {
                        float ea = b / u;
                        q = 1.0f / (1.0f + ea * dot);
                        s = q * ea;
                        y = ra / (1.0f + ea * dot);
                        x = ea * y;
                    }
                    else
                    {
                        float ea = u / b;
                        s = 1.0f / (1.0f + ea * dot);
                        q = ea * s;
                        x = rb / (1.0f + ea * dot);
                        y = ea * x;
                    }
                    y = y + dot * x;
                    d = y * y + (1.0f - dot * dot) * x * x;
                }
                else if (rb > 0.0f)
                {
                    q = 1.0f;
                    s = 0.0f;
                    d = ra * ra;
                }
                else
                {
                    goto parallel;
                }
            }
            else if (ra > 1.192092896e-07f)
            {
                q = 0.0f;
                s = 1.0f;
                d = rb * rb;
            }
            else
            {
            parallel:
                q = 0.5f;
                s = 0.5f;
                d = -dot * dot;
            }
            if (d < best)
            {
                eb = q;
                *pa = v;
                t = s;
                *pb = bestS;
                best = d;
            }
        }
    }
    out->setMul4(eb, (const S2d6c0_Vector&)(*pa)->normal);
    out->addMul4(t, (const S2d6c0_Vector&)(*pb)->normal);
    out->normalize3();
    float dd = (0.0 > best) ? 0.0f : best;
    out->m_vComponents[3] = S2d6c0_sqrt(dd).value;
}


// @fnv 0x00e33760
void FUN_00e33760(float t, int unused, const float* knots, const __m128* ctrl, __m128* out)
{
    float f;
    __m128 left[4], right[4];

    f = t - knots[2];
    left[1] = _mm_load_ss(&f);
    f = knots[3] - t;
    right[1] = _mm_load_ss(&f);
    __m128 inv = inverseSpan(right[1], left[1]);
    __m128 n12 = _mm_mul_ss(right[1], inv);
    f = t - knots[1];
    left[2] = _mm_load_ss(&f);
    f = knots[4] - t;
    right[2] = _mm_load_ss(&f);
    __m128 zero = _mm_load_ss(&::DAT_01011d78);
    __m128 n03 = _mm_div_ss(_mm_add_ss(zero, n12), _mm_add_ss(right[1], left[2]));
    __m128 n22 = _mm_div_ss(_mm_mul_ss(left[1], inv), _mm_add_ss(right[2], left[1]));
    f = t - knots[0];
    left[3] = _mm_load_ss(&f);
    f = knots[5] - t;
    right[3] = _mm_load_ss(&f);
    __m128 b0t = _mm_div_ss(_mm_add_ss(zero, _mm_mul_ss(right[1], n03)), _mm_add_ss(right[1], left[3]));
    __m128 b0 = _mm_add_ss(zero, _mm_mul_ss(right[1], b0t));
    __m128 n13 =
        _mm_div_ss(_mm_add_ss(_mm_mul_ss(left[2], n03), _mm_mul_ss(right[2], n22)), _mm_add_ss(right[2], left[2]));
    __m128 rightTerm = _mm_mul_ss(right[2], n13);
    __m128 b1 = _mm_add_ss(_mm_mul_ss(left[3], b0t), rightTerm);
    __m128 n23 = _mm_div_ss(_mm_mul_ss(left[1], n22), _mm_add_ss(right[3], left[1]));
    __m128 b2left = _mm_mul_ss(left[2], n13);
    __m128 b2right = _mm_mul_ss(right[3], n23);
    __m128 b3 = _mm_mul_ss(left[1], n23);
    __m128 b2 = _mm_add_ss(b2left, b2right);
    __m128 sum = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b1, b1, 0), ctrl[1]),
                                                  _mm_mul_ps(_mm_shuffle_ps(b0, b0, 0), ctrl[0])),
                                       _mm_mul_ps(_mm_shuffle_ps(b2, b2, 0), ctrl[2])),
                            _mm_mul_ps(_mm_shuffle_ps(b3, b3, 0), ctrl[3]));
    *out = sum;
}

#include "generated/data/staging/blk_00e20000_od_o2_nood_variant.inc"
