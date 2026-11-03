
// src/staging/blk_00ce0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_01012000.h"
#include "../../include/layout_support.h"
#include <new>
#include <windows.h>
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/S_00cfab30_this.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cf8000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_simd.h"

#pragma optimize("gty", on)

namespace InvalidateTimDetail {
struct Node;
struct Input;
typedef void(__cdecl* Invalidate)(Node*, void*, const Input&);
struct Method
{
    Invalidate invalidate;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
};
struct Input
{
    Method* methods;
};
struct __declspec(align(16)) Node
{
    unsigned char command;
    unsigned char agentType;
    unsigned short unk02;
    int unk04, unk08, unk0c, unk10, unk14;
    float time;
    int unk1c;
};
struct TimNode : Node
{
    __m128 normal;
};
}

// @fnv 0x00cfdbe0
void __cdecl FUN_00cfdbe0(InvalidateTimDetail::Node* node, const InvalidateTimDetail::Input& input)
{
    using namespace InvalidateTimDetail;
    switch (node->command)
    {
    case 2:
    case 6:
    case 10:
    case 14: {
        Invalidate action = input.methods[node->agentType + 0x49].invalidate;
        if (action)
            action(node, node + 1, input);
        break;
    }
    case 4:
    case 12: {
        TimNode* pTimNode = static_cast<TimNode*>(node);
        pTimNode->time = ::DAT_01012054;
        pTimNode->normal = _mm_setzero_ps();
        Invalidate action = input.methods[node->agentType + 0x49].invalidate;
        if (action)
            action(node, pTimNode + 1, input);
        break;
    }
    }
}

struct __declspec(align(16)) SortElem16
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

typedef bool(__cdecl* SortElemLess)(const SortElem16& a, const SortElem16& b);

// @fnv 0x00cf83c0
void __cdecl FUN_00cf83c0(SortElem16* pArr, int d, int h, SortElemLess cmpLess)
{
    int i, j;
    SortElem16 str;
begin:
    i = d;
    j = h;
    str = pArr[(d + h) >> 1];
    do
    {
        while (cmpLess(pArr[i], str))
            i++;
        while (cmpLess(str, pArr[j]))
            j--;
        if (j >= i)
        {
            if (j != i)
            {
                SortElem16* pj = &pArr[j];
                SortElem16* pi = &pArr[i];
                SortElem16 tmp = *pj;
                *pj = *pi;
                *pi = tmp;
            }
            j--;
            i++;
        }
    } while (i <= j);
    if (d < j)
    {
        FUN_00cf83c0(pArr, d, j, cmpLess);
    }
    if (i < h)
    {
        d = i;
        goto begin;
    }
}

struct QuaternionVector
{
    __m128 value;
    __declspec(noinline) void FUN_00c66320(const QuaternionVector* left, const QuaternionVector* right)
    {
        __m128 a = left->value;
        __m128 b = right->value;
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
        __m128 imag = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xff), a),
                                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xff), b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        value = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), 0xc4);
    }
};

struct Transform
{
    __m128 translation;
    QuaternionVector rotation;
    __m128 scale;
};

struct Par_00ce2d10
{
    __m128 translation;
    QuaternionVector rotation;
};

template <class T> struct PointerParam
{
    T* p;
    PointerParam(T* q) : p(q)
    {}
    operator T*() const
    {
        return p;
    }
    PointerParam& operator++()
    {
        ++p;
        return *this;
    }
    T* operator->() const
    {
        return p;
    }
};

// @fnv 0x00ce2d10
void __cdecl FUN_00ce2d10(const Transform* parents, PointerParam<const Transform> local, const short* indices,
                          int count, Transform* output)
{
    if (!indices)
    {
        for (int i = 0; i < count; ++i)
        {
            const Transform& l = local[i];
            const Transform& p = parents[i];
            __m128 v = l.translation;
            __m128 q = p.rotation.value;
            __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
            __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
            __m128 cross = _mm_sub_ps(t1, t2);
            __m128 w = _mm_shuffle_ps(q, q, 0xff);
            __m128 product = _mm_mul_ps(v, q);
            __m128 s55 = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
            __m128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), s55);
            __m128 rotated =
                _mm_add_ps(_mm_mul_ps(cross, w), _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v),
                                                            _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q)));
            output[i].translation = _mm_add_ps(_mm_add_ps(rotated, rotated), p.translation);
            ::fnv_00c66320::FUN_00c66320((__m128 *)&(output[i].rotation), nullptr, (const __m128 *)(&p.rotation), (const __m128 *)(const ::QuaternionVector *)(&l.rotation));
            output[i].scale = _mm_mul_ps(l.scale, p.scale);
        }
    }
    else
    {
        int i = 0;
        if (i >= count)
            return;
        const Transform* source = local.p;
        do
        {
            short index = indices[i];
            if (index >= 0)
            {
                Transform parent;
                parent.rotation.value = parents[index].rotation.value;
                parent.scale = parents[index].scale;
                parent.translation = parents[index].translation;
                __m128 v = source->translation;
                __m128 q = parent.rotation.value;
                __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
                __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
                __m128 cross = _mm_sub_ps(t1, t2);
                __m128 w = _mm_shuffle_ps(q, q, 0xff);
                __m128 product = _mm_mul_ps(v, q);
                __m128 s55 = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
                __m128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), s55);
                __m128 rotated = _mm_add_ps(_mm_mul_ps(cross, w),
                                            _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v),
                                                       _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q)));
                output[index].translation = _mm_add_ps(_mm_add_ps(rotated, rotated), parent.translation);
                ::fnv_00c66320::FUN_00c66320((__m128 *)&(output[index].rotation), nullptr, (const __m128 *)(&parent.rotation), (const __m128 *)(const ::QuaternionVector *)(&source->rotation));
                output[index].scale = _mm_mul_ps(source->scale, parent.scale);
                ++source;
            }
            else
            {
                ++source;
            }
            ++i;
        } while (i < count);
    }
}

struct Cls
{
    unsigned short m0, m2, m4, m6;
    __m128 v10, v20, v30, v40, v50, v60;
    Cls* FUN_00ce4a50(Cls* src);
};

// @fnv 0x00ce4a50
Cls* Cls::FUN_00ce4a50(Cls* src)
{
    m0 = src->m0;
    m2 = src->m2;
    m4 = src->m4;
    m6 = src->m6;
    v10 = src->v10;
    v20 = src->v20;
    v30 = src->v30;
    v40 = src->v40;
    v50 = src->v50;
    v60 = src->v60;
    return this;
}

struct SortRec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

typedef char*(__cdecl* SortCmp)(void* tag, const SortRec* lhs, const SortRec* rhs);

// @fnv 0x00cf8510
void __cdecl FUN_00cf8510(SortRec* a, int low, int high, SortCmp cmp)
{
    char tagLo;
    char tagHi;

    for (;;)
    {
        int j = high;
        int i = low;
        __declspec(align(16)) SortRec pivot = a[(i + j) >> 1];
        do
        {
            while (*cmp(&tagLo, &a[i], &pivot))
                ++i;
            while (*cmp(&tagHi, &pivot, &a[j]))
                --j;
            if (j < i)
                break;
            if (j != i)
            {
                SortRec& x = a[j];
                SortRec& y = a[i];
                __declspec(align(16)) SortRec t = x;
                x = y;
                y = t;
            }
            --j;
            ++i;
        } while (i <= j);
        if (low < j)
            ::FUN_00cf8510(a, low, j, cmp);
        if (i >= high)
            return;
        low = i;
    }
}

namespace fnv_00cfac20 {
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern char DAT_010cc678[];
struct S00cfac20_Vec
{
    __m128 q;
    void setMin4(const S00cfac20_Vec& a, const S00cfac20_Vec& b)
    {
        q = _mm_min_ps(a.q, b.q);
    }
    void setMax4(const S00cfac20_Vec& a, const S00cfac20_Vec& b)
    {
        q = _mm_max_ps(a.q, b.q);
    }
};
struct S00cfac20_Ray
{
    S00cfac20_Vec from;
    S00cfac20_Vec to;
    S00cfac20_Vec extra;
};
struct S00cfac20_Aabb
{
    S00cfac20_Vec mn;
    S00cfac20_Vec mx;
    void includePoint(const S00cfac20_Vec& p)
    {
        mn.setMin4(mn, p);
        mx.setMax4(mx, p);
    }
};
struct S00cfac20_Builder
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
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual int GetLogicalSize();
    virtual void v64();
    virtual void init(S00cfac20_Aabb* bounds, void* mem);
};
struct S00cfac20_Mon
{
    int unk00;
    char* cur;
    int unk08;
    char* end;
};
struct S00cfac20_Stack
{
    char* cur;
    char* alloc(int size)
    {
        char* r = cur;
        cur = r + ((size + 0x7f) & ~0x7f);
        return r;
    }
    void release(char* p)
    {
        cur = p;
    }
};
struct S00cfac20_Grp
{
    void FUN_00cfac20(S00cfac20_Builder* b, S00cfac20_Ray* rays, int count, void* ctx, char* out);
};
static inline void S00cfac20_timer(const char* name)
{
    S00cfac20_Mon* mon = (S00cfac20_Mon*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    char* p = mon->cur;
    if (p < mon->end)
    {
        *(const char**)p = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(p + 4) = t;
        p += 0xc;
        mon->cur = p;
    }
}
static __forceinline void S00cfac20_calcAabb(const S00cfac20_Ray* rays, int count, S00cfac20_Aabb& aabb)
{
    S00cfac20_Vec mn;
    mn.setMin4(rays->from, rays->to);
    aabb.mn.q = mn.q;
    aabb.mx.setMax4(rays->from, rays->to);
    const S00cfac20_Ray* p = rays + 1;
    int i = count - 2;
    if (i >= 0)
    {
        do
        {
            mn.setMin4(mn, p->to);
            aabb.mx.setMax4(aabb.mx, p->to);
            mn.setMin4(mn, p->from);
            aabb.mx.setMax4(aabb.mx, p->from);
            ++p;
        } while (--i >= 0);
        aabb.mn.q = mn.q;
    }
}
// @fnv 0x00cfac20
void S00cfac20_Grp::FUN_00cfac20(S00cfac20_Builder* b, S00cfac20_Ray* rays, int count, void* ctx, char* out)
{
    char* dst;
    int j;
    {
        S00cfac20_Mon* mon = (S00cfac20_Mon*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
        char* p = mon->cur;
        if (p < mon->end)
        {
            *(const char**)p = DAT_010cc678;
            _ReadWriteBarrier();
            *(volatile unsigned*)&dst = (unsigned)__rdtsc();
            *(unsigned int*)(p + 4) = *(volatile unsigned*)&dst;
            p += 0xc;
            mon->cur = p;
        }
    }
    S00cfac20_Aabb aabb;
    S00cfac20_calcAabb(rays, count, aabb);
    char* mem = ((S00cfac20_Stack*)FUN_00c85750())->alloc(b->GetLogicalSize());
    b->init(&aabb, mem);
    S00cfac20_Ray* r = rays;
    dst = out;
    for (j = count - 1; j >= 0; --j)
    {
        reinterpret_cast<::S_00cfab30_this *>(this)->RecordAndDispatch((::S_00cfab30_object *)(b), (::S_00cfab30_arg *)(::fnv_00cfac20::S00cfac20_Ray *)(r++), ctx, mem, dst);
        dst += 0x60;
    }
    ((S00cfac20_Stack*)FUN_00c85750())->release(mem);
    {
        S00cfac20_Mon* mon = (S00cfac20_Mon*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
        char* p = mon->cur;
        if (p < mon->end)
        {
            *(const char**)p = ::DAT_010c41f8;
            _ReadWriteBarrier();
            *(volatile unsigned*)&j = (unsigned)__rdtsc();
            *(unsigned int*)(p + 4) = *(volatile unsigned*)&j;
            p += 0xc;
            mon->cur = p;
        }
    }
}
}

// namespace fnv_00cfac20

typedef unsigned short hkUint16;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline hkVector4()
    {}
    __forceinline hkVector4(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkReferencedObject
{
};

template <class T> struct ReferenceCountedPointer
{
    T* m_pRetainedObject;

    __forceinline void operator=(const ReferenceCountedPointer& rp)
    {
        if (rp.m_pRetainedObject)
            reinterpret_cast<::FUN_00c90510_class *>((rp.m_pRetainedObject))->FUN_00c90510();
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);

    template <typename T> __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / int(sizeof(T));
        return static_cast<T*>(p);
    }

    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem * sizeof(T));
    }
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};


__forceinline hkMemoryAllocator& containerHeap()
{
    return static_cast<NineIntegerRecord*>(FUN_00c85750())->heap();
}

template <typename T> __forceinline void hkConstructWithArray(T* t, int n, const T* tcopy)
{
    for (int i = 0; i < n; ++i)
    {
        new (t + i) T(tcopy[i]);
    }
}

template <typename T> __forceinline void hkCopy(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
    {
        dst[i] = src[i];
    }
}

template <typename T> __forceinline void hkConstructWithArray2(T* t, int n, const T* tcopy)
{
    for (int i = 0; i < n; ++i)
    {
        new (t) T(*tcopy);
        ++t;
        ++tcopy;
    }
}

template <typename T> __forceinline void hkCopy2(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
    {
        *dst = *src;
        ++dst;
        ++src;
    }
}

template <typename T> struct hkArray
{
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }

    __forceinline void _copyFromArrayClass(hkMemoryAllocator& alloc, const hkArray& a)
    {
        int oldSize = m_iElementCount;
        int newSize = a.GetLogicalSize();
        int copiedSize = newSize > oldSize ? oldSize : newSize;

        GrowArrayCapacity(alloc, newSize);
        hkCopy(m_data, a.m_data, copiedSize);
        hkConstructWithArray(m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize);
        m_iElementCount = newSize;
    }

    __forceinline hkArray& operator=(const hkArray& a)
    {
        _copyFromArrayClass(containerHeap(), a);
        return *this;
    }

    __forceinline void _copyFromArrayPod(hkMemoryAllocator& alloc, const hkArray& a)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            {
                alloc._bufFree<T>(m_data, getCapacity());
            }
            int n = a.GetLogicalSize();
            m_data = alloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        hkCopy(m_data, a.m_data, m_iElementCount);
    }
};

struct VectorTriple
{
    hkVector4 a, b, c;
};

struct VertexInfo
{
    hkUint16 m_index0;
    hkUint16 m_index1;
    VectorTriple m_v;
};

struct FaceInfo
{
    hkUint16 m_index0;
    hkUint16 m_index1;
    hkUint16 m_index2;
    hkUint16 m_index3;
    VectorTriple m_kPointA;
    VectorTriple m_kPointB;
};

struct ShapeData
{
    ReferenceCountedPointer<hkReferencedObject> m_kFirstReferencedObject;
    ReferenceCountedPointer<hkReferencedObject> m_kSecondReferencedObject;
    hkArray<VertexInfo> m_kVertices;
    hkArray<FaceInfo> m_faces;
    hkArray<hkUint16> m_ppIndices;
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
    hkVector4 m_kCenterPosition;
    bool m_flag;
    int m_uiItemCount;

    ShapeData& FUN_00ce4ae0(const ShapeData& other);
};

// @fnv 0x00ce4ae0
ShapeData& ShapeData::FUN_00ce4ae0(const ShapeData& other)
{
    m_kFirstReferencedObject = other.m_kFirstReferencedObject;
    m_kSecondReferencedObject = other.m_kSecondReferencedObject;
    m_kVertices = other.m_kVertices;
    m_faces = other.m_faces;
    m_ppIndices._copyFromArrayPod(containerHeap(), other.m_ppIndices);
    m_kMinimumCorner = other.m_kMinimumCorner;
    m_kMaximumCorner = other.m_kMaximumCorner;
    m_kCenterPosition = other.m_kCenterPosition;
    m_flag = other.m_flag;
    m_uiItemCount = other.m_uiItemCount;
    return *this;
}

struct Vec4Target
{
    __m128 m_v0;
    __m128 m_v1;
};

__declspec(align(16)) struct Vec4Pod
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};

// @fnv 0x00ce2ca0
void FUN_00ce2ca0(void* unused, __m128* dst, const __m128* a, const __m128* b)
{
    dst[0] = _mm_add_ps(_mm_mul_ps(a[2], b[0]), a[0]);
    ::fnv_00c66320::FUN_00c66320((__m128 *)(dst + 1), nullptr, (const __m128 *)(a + 1), (const __m128 *)(b + 1));
    dst[2] = b[2];
}

struct FUN_00cf2280_cls
{
    __m128 m_00;
    __m128 m_10;
    __m128 m_20;
    __m128 m_30;
    __m128 m_40;

    void FUN_00cf2280(const __m128* a, const __m128* b);
};

// @fnv 0x00cf2280
void FUN_00cf2280_cls::FUN_00cf2280(const __m128* a, const __m128* b)
{
    m_00 = _mm_and_ps(*a, ::DAT_010c4c10);
    m_10 = _mm_and_ps(*a, ::DAT_010c4c10);
    m_20 = *b;
    m_30 = *b;
    m_40 = _mm_setzero_ps();
}

extern "C" void _ReadWriteBarrier(void);

unsigned __int64 __cdecl __rdtsc(void);

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct ProfBuf
{
    DWORD unk00;
    ProfRec* m_pCur;
    DWORD unk08;
    ProfRec* m_pRecordEnd;
};

struct RayInput
{
    __m128 m_vFrom;
    __m128 m_vTo;
    unsigned char m_bFlag;
};

struct RayCastQuery
{
    __m128 m_vFrom;
    int m_iOne;
    const __m128* m_pTo;
    int m_uiLogicalSize;
    int m_iZero;
};

class RayCaster;

class RayWorld
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void CastRay(RayCastQuery* q, RayCaster* c, int z);
};

class RayCaster
{
  public:
    void FUN_00cfaa40(RayWorld* world, RayInput* input, char* source, int a4);

    int unk00;
    RayInput* m_pInput;
    char* m_pSource14;
    int m_i0C;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    char* m_pSource10;
};

// @fnv 0x00cfaa40
void RayCaster::FUN_00cfaa40(RayWorld* world, RayInput* input, char* source, int a4)
{
    volatile DWORD tick;
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        pRec->m_pName = "TtRayCastSimpl";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }

    m_pInput = input;
    m_i0C = a4;
    m_pSource14 = source ? source + 0x14 : 0;
    if (input->m_bFlag)
        m_pSource10 = source ? source + 0x10 : 0;
    else
        m_pSource10 = 0;

    RayCastQuery q;
    __m128 from = _mm_load_ps((const float*)&input->m_vFrom);
    q.m_pTo = &input->m_vTo;
    q.m_iOne = 1;
    q.m_uiLogicalSize = 0x10;
    q.m_iZero = 0;
    _mm_store_ps((float*)&q.m_vFrom, from);
    world->CastRay(&q, this, 0);

    pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        pRec->m_pName = "Et";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }
}

#include "generated/data/staging/blk_00ce0000_od_o2_nood_variant.inc"
