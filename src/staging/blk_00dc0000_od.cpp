
// src/staging/blk_00dc0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "fnv/symbols_00c85000.h"
#include "havok/hkMemoryRouter.h"
#include "../../include/layout_support.h"
#include <xmmintrin.h>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_010c8000.h"
#include "fnv/symbols_simd.h"
#include <new>
#include "fnv/symbols_00cbf000.h"
#include "fnv/symbols_00dd6000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_0104d000.h"
#include <math.h>
#include <cmath>
#include "fnv/symbols_00dce000.h"

struct VecArray
{
    __m128* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

static __forceinline float distanceSquared(__m128 a, __m128 b)
{
    __m128 v = _mm_sub_ps(a, b);
    __m128 d = _mm_mul_ps(v, v);
    __m128 yx = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
    float r;
    _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), yx));
    return r;
}

// @fnv 0x00dd68d0
void __cdecl FUN_00dd68d0(float tol, VecArray* arr, int* outCount)
{
    __m128* cur = arr->m_data;
    int rem = arr->m_iElementCount - 1;
    __m128* out = arr->m_data;
    if (rem >= 0)
    {
        __m128* last = out - 1;
        while (rem >= 0)
        {
            __m128* lim = last;
            bool dup = false;
            for (; lim >= arr->m_data; --lim)
            {
                if ((*lim)[0] < (*cur)[0] - (double)0.01f)
                    break;
                if (distanceSquared(*lim, *cur) < tol)
                {
                    dup = true;
                    break;
                }
            }
            if (!dup)
            {
                __m128* dst = out;
                out++;
                last++;
                *dst = *cur;
            }
            else
            {
                for (int t = rem - 1; t >= 0; --t)
                {
                    if (!(distanceSquared(*lim, cur[1]) < tol))
                        break;
                    ++cur;
                    --rem;
                }
            }
            ++cur;
            --rem;
        }
    }
    *outCount = (int)(out - arr->m_data);
    int count = *outCount;
    hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().heap();
    int cap = arr->m_iCapacityState & 0x3fffffff;
    if (cap < count)
    {
        int cap2 = cap * 2;
        int newCap = (count < cap2) ? cap2 : count;
        ::FUN_00c908c0((::SpawnedObject *)(&alloc), (::SpawnedArray *)(arr), newCap, 16);
    }
    arr->m_iElementCount = count;
}

namespace fnv_00dd6a10 {

typedef __m128 Plane;

struct Triangle
{
    Plane plane;
    int v0, v1, v2;
    int unk1c;
};

struct Edge
{
    int a, b;
    Triangle* tri;
    int unk0c;
    Plane plane;

    void set(Triangle* t, int ia, int ib)
    {
        a = ia;
        b = ib;
        tri = t;
    }
};


template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct Arr_00dd6a10
{
    T* data;
    int size;
    int capacity;

    __forceinline int findEdge(const Edge& e) const
    {
        int i = 0;
        if (size <= 0)
            return -1;
        for (; i < size; i++)
        {
            const T& o = data[i];
            if ((o.a == e.a && o.b == e.b) || (o.b == e.a && o.a == e.b))
                return i;
        }
        return -1;
    }
    __forceinline void AddBack(const T& v)
    {
        hkMemoryRouter* h = &hkMemoryRouter::getInstance();
        if (size == (capacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(h->m_heap), (::AudioStream *)(void *)(this), sizeof(T));
        T* p = &data[size];
        if (p)
            *p = v;
        size++;
    }
    __forceinline void pushBackPlain(const T& v)
    {
        hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
        if (size == (capacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(&a), (::AudioStream *)(void *)(this), sizeof(T));
        hkConstructWithCopy(data + size, 1, v);
        size++;
    }
    __forceinline void clearAndFree()
    {
        hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
        size = 0;
        if ((capacity & 0x80000000) == 0)
            a.bufFree(data, (capacity & 0x3fffffff) * sizeof(T));
    }
};

typedef Arr_00dd6a10<Plane> PlaneArray;
typedef Arr_00dd6a10<Triangle> TriangleArray;
typedef Arr_00dd6a10<Edge> EdgeArray;

char* __cdecl FUN_00dd66d0(char* flag, Plane* plane, PlaneArray* vertices, int a, int b, Triangle* tri,
                           TriangleArray* out);

// @fnv 0x00dd6a10
void __cdecl FUN_00dd6a10(Edge* edgeIn, PlaneArray* vertices, EdgeArray* visited, PlaneArray* planes)
{
    Edge* edge = edgeIn;
    EdgeArray*& vr = visited;
    if (vr->findEdge(*edge) != -1)
        return;
    vr->AddBack(*edge);

    TriangleArray neighbours;
    neighbours.data = 0;
    neighbours.size = 0;
    neighbours.capacity = 0x80000000;
    char flag;
    if (*FUN_00dd66d0(&flag, &edge->plane, vertices, edge->a, edge->b, edge->tri, &neighbours))
    {
        planes->pushBackPlain(neighbours.data[0].plane);

        for (int i = 0; i < neighbours.size; i++)
        {
            Edge e1;
            e1.a = neighbours.data[i].v0;
            e1.b = neighbours.data[i].v2;
            e1.tri = &neighbours.data[i];
            ::fnv_00dd62e0::FUN_00dd62e0((::fnv_00dd62e0::VectorArray *)(vertices), e1.tri->v0, e1.tri->v2, e1.tri->v1, (__m128 *)(__m128 *)(&e1.plane));
            FUN_00dd6a10(&e1, vertices, vr, planes);
            Edge e2;
            e2.a = neighbours.data[i].v1;
            e2.b = neighbours.data[i].v2;
            e2.tri = &neighbours.data[i];
            ::fnv_00dd62e0::FUN_00dd62e0((::fnv_00dd62e0::VectorArray *)(vertices), e2.tri->v1, e2.tri->v2, e2.tri->v0, (__m128 *)(__m128 *)(&e2.plane));
            FUN_00dd6a10(&e2, vertices, vr, planes);
        }
    }
    neighbours.clearAndFree();
}
}

// namespace fnv_00dd6a10

struct FinishingFlag
{
    int m_bFinishing;
};

class __declspec(align(16)) S00dced70_Object
{
  public:
    S00dced70_Object(FinishingFlag flag);  // FUN_00d4dfc0
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dced70
const void* __cdecl FUN_00dced70()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00dced70_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

struct __declspec(align(16)) FUN_00dd1f00
{
    __m128 unk00;
    int unk10;
    float unk14;
    int unk18;
    int unk1c;
    FUN_00dd1f00(const FUN_00dd1f00& o);
};

// @fnv 0x00dd1f00
FUN_00dd1f00::FUN_00dd1f00(const FUN_00dd1f00& o)
{
    unk00 = o.unk00;
    unk10 = o.unk10;
    unk14 = o.unk14;
    unk18 = o.unk18;
    unk1c = o.unk1c;
}

namespace fnv_00dd62e0 {
extern const __m128 DAT_010c44d0;
struct VectorArray
{
    __m128* field_00;
};

// @fnv 0x00dd62e0
void __cdecl FUN_00dd62e0(VectorArray* self, int a, int b, int c, __m128* out)
{
    const __m128& x = self->field_00[b];
    const __m128& y = self->field_00[a];
    __m128& cross = *out;
    cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(x, x, 0xd2), _mm_shuffle_ps(y, y, 0xc9)),
                       _mm_mul_ps(_mm_shuffle_ps(x, x, 0xc9), _mm_shuffle_ps(y, y, 0xd2)));
    __m128 product = _mm_mul_ps(self->field_00[c], cross);
    float dot;
    _mm_store_ss(&dot, _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa),
                                  _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product)));
    if (dot > 0.0f)
        *out = _mm_xor_ps(cross, (*reinterpret_cast<const __m128 *>((void *)&::DAT_010c44d0)));
}
}

// namespace fnv_00dd62e0

struct Pair_00dd6c10
{
    int first;
    int second;

    static __forceinline Pair_00dd6c10 make(int a, int b)
    {
        Pair_00dd6c10 p;
        p.first = a;
        p.second = b;
        return p;
    }
    __forceinline bool operator==(const Pair_00dd6c10& o) const
    {
        return first == o.first && second == o.second;
    }
};


template <class T> struct Arr_00dd6c10
{
    T* data;
    int size;
    int capacity;
};

struct PairList_00dd6c10
{
    Pair_00dd6c10* data;
    int size;
    int capacity;
    Pair_00dd6c10 storage[32];

    __forceinline void init()
    {
        data = storage;
        size = 0;
        capacity = 0x80000020;
    }
    __forceinline int indexOf(const Pair_00dd6c10& t) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == t)
                return i;
        }
        return -1;
    }
    __forceinline void add(const Pair_00dd6c10& item)
    {
        hkMemoryRouter* h = &hkMemoryRouter::getInstance();
        if (size == (capacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(h->m_heap), (::AudioStream *)(void *)(this), sizeof(Pair_00dd6c10));
        Pair_00dd6c10* p = &data[size];
        if (p)
        {
            p->first = item.first;
            p->second = item.second;
        }
        size++;
    }
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& a)
    {
        size = 0;
        if ((capacity & 0x80000000) == 0)
            a.bufFree(data, (capacity & 0x3fffffff) * sizeof(Pair_00dd6c10));
    }
    __forceinline void clearAndFree()
    {
        _clearAndDeallocate(hkMemoryRouter::getInstance().heap());
    }
};

typedef Arr_00dd6c10<__m128> VecArr_00dd6c10;

static __forceinline float dot3_00dd6c10(const __m128& a, const __m128& b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    float r;
    _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s));
    return r;
}

static __forceinline __m128 cross_00dd6c10(__m128 b, __m128 a)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                      _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
}

static __forceinline __m128 cross2_00dd6c10(__m128 a, __m128 b)
{
    __m128 t0 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2));
    __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9));
    return _mm_sub_ps(t1, t0);
}

struct hkVector4q_00dd6c10
{
    __m128 m_vComponents;
    __forceinline void setCross(const hkVector4q_00dd6c10& v1, const hkVector4q_00dd6c10& v2)
    {
        __m128 positive = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 negative = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                     _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(positive, negative);
    }
};

static __forceinline bool lt_00dd6c10(const float& a, const float& b)
{
    return a < b;
}

static __forceinline bool gt_00dd6c10(const float& a, const float& b)
{
    return a > b;
}

extern const float DAT_010c8440 = -1.1920929e-07f;

extern const float DAT_010b9be8;

extern const __m128 DAT_010c44d0;

struct PlanePoint
{
    __m128 position;
    int plane0, plane1, plane2, unk1c;
    __forceinline void copyPlanes(const PlanePoint& other)
    {
        plane0 = other.plane0;
        plane1 = other.plane1;
        plane2 = other.plane2;
    }
};

int __cdecl FUN_00dd6380(VecArr_00dd6c10* vectors, int first, int second, int third, PlanePoint* point);

__declspec(noinline) int __cdecl FUN_00dd6510(const __m128* normal, VecArr_00dd6c10* vectors, int first, int second,
                                              PlanePoint* lower, PlanePoint* upper)
{
    lower->plane0 = lower->plane1 = lower->plane2 = -1;
    upper->plane0 = upper->plane1 = upper->plane2 = -1;
    bool initialized = false;
    for (int i = 0; i < vectors->size; ++i)
    {
        if (i == first || i == second)
            continue;
        PlanePoint point;
        if (FUN_00dd6380(vectors, first, second, i, &point) != 0)
            continue;
        if (!initialized)
        {
            __m128 scale = _mm_load_ss(&DAT_010b9be8);
            scale = _mm_shuffle_ps(scale, scale, 0);
            upper->position = _mm_add_ps(_mm_mul_ps(scale, *normal), point.position);
            lower->position = _mm_xor_ps(upper->position, DAT_010c44d0);
            initialized = true;
        }
        float topDistance = dot3_00dd6c10(_mm_sub_ps(upper->position, point.position), vectors->data[i]);
        if (topDistance > DAT_010c8440)
        {
            upper->position = point.position;
            upper->copyPlanes(point);
        }
        float bottomDistance = dot3_00dd6c10(_mm_sub_ps(lower->position, point.position), vectors->data[i]);
        if (bottomDistance > DAT_010c8440)
        {
            lower->position = point.position;
            lower->copyPlanes(point);
        }
    }
    if (lower->plane0 == -1)
    {
        if (upper->plane0 == -1)
            return 1;
        lower->copyPlanes(*upper);
    }
    if (upper->plane0 == -1)
    {
        if (lower->plane0 == -1)
            return 1;
        upper->copyPlanes(*lower);
    }
    return 0;
}

// @fnv 0x00dd6c10
int __cdecl FUN_00dd6c10(VecArr_00dd6c10* vectors, int* first, int* second, PlanePoint* q, PlanePoint* p)
{
    PairList_00dd6c10 visited;
    visited.init();
    hkVector4q_00dd6c10 normal;
    for (;;)
    {
        float best = ::DAT_0104e148;
        Pair_00dd6c10 bestPair = Pair_00dd6c10::make(-1, -1);
        for (int i = 0; i < vectors->size; i++)
        {
            for (int j = i + 1; j < vectors->size; j++)
            {
                float score = dot3_00dd6c10(vectors->data[i], vectors->data[j]);
                if (score > best && score < 0.8999999761581421 && visited.indexOf(Pair_00dd6c10::make(i, j)) == -1)
                {
                    best = score;
                    *first = i;
                    *second = j;
                    bestPair = Pair_00dd6c10::make(i, j);
                }
            }
        }
        if (bestPair.first == -1)
        {
            visited.clearAndFree();
            return 1;
        }
        visited.add(bestPair);
        normal.setCross(reinterpret_cast<const hkVector4q_00dd6c10&>(vectors->data[*first]),
                        reinterpret_cast<const hkVector4q_00dd6c10&>(vectors->data[*second]));
        if (FUN_00dd6510(&normal.m_vComponents, vectors, *first, *second, p, q) == 1)
        {
            visited.clearAndFree();
            return 1;
        }
        __m128 dm = _mm_mul_ps(_mm_sub_ps(p->position, q->position), normal.m_vComponents);
        float d;
        _mm_store_ss(&d, _mm_add_ss(_mm_shuffle_ps(dm, dm, 0xaa), _mm_add_ss(_mm_shuffle_ps(dm, dm, 0x55), dm)));
        if (gt_00dd6c10(d, DAT_010c8440))
            break;
    }
    visited.clearAndFree();
    return 0;
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkVector4
{
    __m128 m_vComponents;
};

struct VectorComponentValue
{
    __m128 m_vValue;
    VectorComponentValue(__m128 x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct Contact
{
    hkVector4 m_kPoint;
    hkVector4 m_vHitNormal;
};



template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void AddBack(const T& t)
    {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(router->m_heap), (::AudioStream *)(void *)(this), sizeof(T));
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
};

extern float DAT_0109afc4;

// @fnv 0x00dd66d0
hkBool __cdecl FUN_00dd66d0(const hkVector4* direction, hkArray<hkVector4>* planes, int skip1, int skip2,
                            hkVector4* position, hkArray<Contact>* contacts)
{
    float best = ::DAT_0104da48;
    bool found = false;
    for (int i = 0; i < planes->m_iElementCount; i++)
    {
        if (i == skip1 || i == skip2)
            continue;
        __m128 products = _mm_mul_ps(planes->m_data[i].m_vComponents, direction->m_vComponents);
        __m128 denomv = _mm_add_ss(_mm_shuffle_ps(products, products, 0xaa),
                                   _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products));
        float denom = VectorComponentValue(denomv);
        if (DAT_0109afc4 < denom)
        {
            position->m_vComponents[3] = 1.0f;
            __m128 dot = _mm_mul_ps(planes->m_data[i].m_vComponents, position->m_vComponents);
            __m128 sum = _mm_add_ps(_mm_shuffle_ps(dot, dot, 0x4e), dot);
            sum = _mm_add_ps(_mm_shuffle_ps(sum, sum, 0xb1), sum);
            float num = VectorComponentValue(_mm_sub_ss(DAT_010c7160, sum));
            float absDenom = (float)fabs(denom);
            float dist = num / absDenom;
            if (dist < best + DAT_01032980)
            {
                Contact contact;
                if (::FUN_00dd6380((::S00dd6380_PlaneSet *)(planes), skip1, skip2, i, (::S00dd6380_PointResult *)(::Contact *)(&contact)) == 0)
                {
                    found = true;
                    float diff = dist - best;
                    if ((float)fabs(diff) < DAT_01032980)
                    {
                        contacts->AddBack(contact);
                    }
                    else
                    {
                        contacts->m_iElementCount = 0;
                        contacts->AddBack(contact);
                        best = dist;
                    }
                }
            }
        }
    }
    return found;
}

static inline float Dot3(__m128 a, __m128 b)
{
    __m128 v = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    float f;
    _mm_store_ss(&f, _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), s));
    return f;
}

// @fnv 0x00ddd5a0
void __cdecl FUN_00ddd5a0(const float* a, const float* b, const float* c)
{
    __m128 scale = _mm_load_ps(c);
    float fB = Dot3(_mm_load_ps(b), scale);
    float fA = Dot3(_mm_load_ps(a), scale);
    ::Atan2(fB, fA);
}

struct S00dd2fd0_cls
{
    __m128 m_00;
};

// @fnv 0x00dd2fd0
static __declspec(noinline) void FUN_00dd2fd0(S00dd2fd0_cls* self, __m128* out, __m128* a1, __m128* a2)
{
    __m128 d = _mm_sub_ps(*a1, self->m_00);
    __m128 r = _mm_rcp_ps(d);
    __m128 t = _mm_mul_ps(_mm_mul_ps(r, d), r);
    r = _mm_sub_ps(_mm_add_ps(r, r), t);
    *a2 = _mm_mul_ps(*a1, r);
    *out = _mm_mul_ps(self->m_00, r);
    *out = _mm_xor_ps(*out, ::DAT_010c44d0);
}

void S00dd2fd0_wrap(S00dd2fd0_cls* self, __m128* out, __m128* a1, __m128* a2)
{
    FUN_00dd2fd0(self, out, a1, a2);
}

void __cdecl FUN_00dd68d0(float tol, VecArray* arr, int* outCount);

int __cdecl FUN_00dd6c10(VecArr_00dd6c10* vectors, int* first, int* second, PlanePoint* q, PlanePoint* p);

#pragma intrinsic(fabs)

struct TriangleProjectionData
{
    __m128 edge0;
    __m128 edge1;
    __m128 vertices[3];
};

// @fnv 0x00ddd2c0
int __cdecl FUN_00ddd2c0(const __m128* origin, const __m128* firstAxis, const __m128* secondAxis,
                         const TriangleProjectionData* triangle, const __m128* direction)
{
    float maximum = ::DAT_0104e148;
    const __m128* entry = origin;
    const __m128 center = *entry;
    entry = firstAxis;
    const __m128 axis = *entry;
    entry = triangle->vertices;
    const __m128* begin = entry;
    float minimum = ::DAT_0104da48;
    const __m128* vertex = begin;
    int remaining = 3;
    do
    {
        __m128 p = _mm_mul_ps(_mm_sub_ps(*vertex, center), axis);
        __m128 y = _mm_shuffle_ps(p, p, 0x55);
        __m128 z = _mm_shuffle_ps(p, p, 0xAA);
        y = _mm_add_ss(y, p);
        z = _mm_add_ss(z, y);
        float projection;
        _mm_store_ss(&projection, z);
        if (projection > maximum)
            maximum = projection;
        if (projection < minimum)
            minimum = projection;
        ++vertex;
    } while (remaining-- != 1);

    if (maximum > 0.01f || minimum < 0.01f)
    {
        if (maximum > 0.20000000298023224 && minimum < 0.20000000298023224)
            return 0;
        int useDirection = 1;
        if (!(fabsf(maximum) > fabsf(minimum)))
            useDirection = 0;
        float scale = (float)useDirection;
        __m128 p = _mm_mul_ps(*secondAxis, *direction);
        __m128 y = _mm_shuffle_ps(p, p, 0x55);
        __m128 z = _mm_shuffle_ps(p, p, 0xAA);
        y = _mm_add_ss(y, p);
        z = _mm_add_ss(z, y);
        z = _mm_mul_ss(z, _mm_load_ss(&scale));
        float directedProjection;
        _mm_store_ss(&directedProjection, z);
        if (directedProjection < 0.0f)
            return 1;
    }

    float secondMaximum = ::DAT_0104e148;
    float secondMinimum = ::DAT_0104da48;
    vertex = begin;
    remaining = 3;
    do
    {
        __m128 p = _mm_mul_ps(_mm_sub_ps(*vertex, center), *secondAxis);
        __m128 y = _mm_shuffle_ps(p, p, 0x55);
        __m128 z = _mm_shuffle_ps(p, p, 0xAA);
        y = _mm_add_ss(y, p);
        z = _mm_add_ss(z, y);
        float projection;
        _mm_store_ss(&projection, z);
        if (projection > secondMaximum)
            secondMaximum = projection;
        if (projection < secondMinimum)
            secondMinimum = projection;
        ++vertex;
    } while (remaining-- != 1);

    if (!(secondMaximum > 0.01f || secondMinimum < 0.01f))
        return 0;
    if (secondMaximum > 0.20000000298023224 && secondMinimum < 0.20000000298023224)
        return 0;
    int useDirection = 1;
    if (!(fabsf(secondMaximum) > fabsf(secondMinimum)))
        useDirection = 0;
    float scale = (float)useDirection;
    __m128 p = _mm_mul_ps(*firstAxis, *direction);
    __m128 y = _mm_shuffle_ps(p, p, 0x55);
    __m128 z = _mm_shuffle_ps(p, p, 0xAA);
    y = _mm_add_ss(y, p);
    z = _mm_add_ss(z, y);
    z = _mm_mul_ss(z, _mm_load_ss(&scale));
    float directedProjection;
    _mm_store_ss(&directedProjection, z);
    if (directedProjection > 0.0f)
        return 1;
    return 0;
}
