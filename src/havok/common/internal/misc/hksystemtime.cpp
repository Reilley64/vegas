// src/havok/common/internal/misc/hksystemtime.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/misc/hksystemtime.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include <xmmintrin.h>
#include <cstddef>
#include <new>
#include "fnv/symbols_00e29000.h"
#include <math.h>
#include "fnv/symbols_simd.h"
#include <ctime>
// @fnv 0x00e29910
int FUN_00e29910(void)
{
    return (int)std::time(0);
}

// ---- stand-ins for the analysed image's types
struct __declspec(align(16)) FNV_Vec4
{
    float x, y, z, w;
};
struct E29Src
{
    int idx[4];
    int n;
    static __forceinline void* operator new(size_t, void* place) throw()
    {
        return place;
    }
    static __forceinline void operator delete(void*, void*) throw()
    {}
    __forceinline E29Src(int index) throw()
    {
        idx[0] = index;
        idx[1] = 0;
        idx[2] = 0;
        idx[3] = 0;
        n = 1;
    }
    __forceinline E29Src() throw()
    {
        for (int x = 0; x < 4; x++)
            idx[x] = 0;
        n = 0;
    }
};
struct E29SrcList
{
    E29Src* data;
    int count;
    int cap;
    void* mem;
};

struct E29Item
{
    __m128 a;
    __m128 b;
    char flag20;
    int val24;
};
struct E29Out1
{
    E29Item item;
    void* ptr30;
    int one34;
    int zero38;
    char unk3c;
    char flag3d;
};
struct E29Out2
{
    E29Item items[4];
    int count;
    char flagC4;
    void* ptrs[4];
    int unkD8;
    int unkDC;
    int zeros[4];
    int unkF0;
};

struct FNV_MemObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Release(void* p, int size);  // vtable slot 4 (+0x10)
};

struct FNV_Ctx
{
    void* cur;  // +0x00 bump pointer
    int pad0;
    int pad1;
    int pad2;
    FNV_MemObj* obj;  // +0x10
};

extern "C" FNV_Ctx* FUN_00c85750() throw();
extern "C" bool FUN_00e29920(FNV_Vec4*, FNV_Vec4*, FNV_Vec4*, FNV_Vec4*, FNV_Vec4*, FNV_Vec4*, float, float) throw();

static __forceinline __m128 dot3(__m128 a, __m128 b)
{
    __m128 q = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q));
}
extern "C" __declspec(noinline) bool FUN_00e29920(FNV_Vec4* a, FNV_Vec4* b, FNV_Vec4* n, FNV_Vec4* a2, FNV_Vec4* b2,
                                                  FNV_Vec4* n2, float thresh, float limit) throw()
{
    float dot;
    _mm_store_ss(&dot, dot3(*(__m128*)n, *(__m128*)n2));
    if (dot < thresh)
        return false;
    __m128 d1 = _mm_sub_ps(*(__m128*)a2, *(__m128*)a);
    __m128 d2 = _mm_sub_ps(*(__m128*)b2, *(__m128*)b);
    float distance1;
    _mm_store_ss(&distance1, dot3(d1, d1));
    if (distance1 > limit)
        return false;
    float distance2;
    _mm_store_ss(&distance2, dot3(d2, d2));
    return !(distance2 > limit);
}

static __forceinline __m128 normalizeVector(FNV_Vec4& result, __m128 value)
{
    __m128 q = _mm_mul_ps(value, value);
    __m128 y = _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q);
    __m128 len = _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), y);
    __m128 inv = _mm_rsqrt_ss(len);
    __m128 scale = _mm_shuffle_ps(inv, inv, 0);
    __m128 distance = _mm_mul_ss(len, scale);
    _mm_store_ps(&result.x, _mm_mul_ps(scale, value));
    return distance;
}

// @fnv 0x00e2a010
void FUN_00e2a010(int corner, FNV_Vec4* A, FNV_Vec4* B, int n, float angle, float scale, char* a7, E29Out1* a8, int* a9,
                  E29Out2* a10, int* a11)
{
    float thresh = (float)fabs((float)cos((double)angle));
    E29SrcList list;
    list.count = 0;
    FNV_Ctx* ctx = FUN_00c85750();
    E29Src* recs = (E29Src*)ctx->cur;
    ctx->cur = (char*)recs + ((n * 5 * 4 + 0x7f) & ~0x7f);
    int cap = n | 0x80000000;
    list.data = recs;
    list.cap = cap;
    list.mem = recs;
    FNV_Vec4* pa = A;
    int i = 0;
    if (n > 0)
    {
        __m128 zero = _mm_setzero_ps();
        E29Src* cursor = recs;
        int off = (char*)B - (char*)A;
        do
        {
            FNV_Vec4 va = *pa;
            FNV_Vec4 vb = *(FNV_Vec4*)((char*)pa + off);
            __m128 delta = _mm_sub_ps(*(__m128*)&vb, *(__m128*)&va);
            int bits = _mm_movemask_ps(_mm_cmplt_ps(delta, zero));
            if ((bits & 4) + (bits & 2) + (bits & 1) != corner)
                goto next;
            FNV_Vec4 nrm1;
            float dist;
            _mm_store_ss(&dist, normalizeVector(nrm1, delta));
            float power = pow(dist, 2.0f);
            __m128 ang = _mm_load_ss(&power);

            {
                for (int k = 0; k < list.count; k++)
                {
                    E29Src* rec = &recs[k];
                    if (rec->n >= 4)
                        continue;
                    for (int j = 0; j < 1; j++)
                    {
                        int idx = rec->idx[j];
                        FNV_Vec4 va2 = A[idx];
                        FNV_Vec4 vb2 = B[idx];
                        __m128 d2 = _mm_sub_ps(*(__m128*)&vb2, *(__m128*)&va2);
                        FNV_Vec4 nrm2;
                        normalizeVector(nrm2, d2);
                        float sc;
                        _mm_store_ss(&sc, _mm_mul_ss(ang, _mm_load_ss(&scale)));
                        if (FUN_00e29920(&va, &vb, &nrm1, &va2, &vb2, &nrm2, thresh, sc))
                        {
                            rec->idx[rec->n] = i;
                            rec->n++;
                            goto next;
                        }
                    }
                }
            }
            {
                E29Src tmp;
                tmp.idx[tmp.n++] = i;
                new (cursor) E29Src(tmp);
                list.count++;
                cursor++;
            }
        next:
            i++;
            pa++;
        } while (i < n);
    }
    ::FUN_00e29a10(&list, (const __m128*)A, (const __m128*)B, a7, a8, a9, a10, a11);
    FUN_00c85750()->cur = recs;
    FNV_Ctx* holder = FUN_00c85750();
    FNV_MemObj* allocator = holder->obj;
    if ((list.cap & 0x80000000) == 0)
        allocator->Release(recs, (list.cap & 0x3fffffff) * 5 * 4);
}
typedef float S29cd0_hkReal;
typedef __m128 S29cd0_hkQuadReal;

class S29cd0_hkSimdReal
{
  public:
    __forceinline S29cd0_hkSimdReal(const S29cd0_hkQuadReal& x) : m_vValue(x)
    {}
    __forceinline S29cd0_hkSimdReal(S29cd0_hkReal x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline S29cd0_hkSimdReal()
    {}
    __forceinline operator S29cd0_hkReal() const
    {
        S29cd0_hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline S29cd0_hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const S29cd0_hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    S29cd0_hkQuadReal m_vValue;
};

class S29cd0_hkVector4
{
  public:
    __forceinline void operator=(const S29cd0_hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setSub4(const S29cd0_hkVector4& v0, const S29cd0_hkVector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline S29cd0_hkSimdReal dot3(const S29cd0_hkVector4& a) const
    {
        S29cd0_hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        S29cd0_hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline void fastNormalize3()
    {
        S29cd0_hkQuadReal len2 = this->dot3(*this).getQuad();
        S29cd0_hkSimdReal approx = _mm_rsqrt_ss(len2);
        m_vComponents = _mm_mul_ps(m_vComponents, approx.broadcast());
    }
    __forceinline S29cd0_hkSimdReal fastNormalizeWithLength3()
    {
        S29cd0_hkQuadReal len2 = this->dot3(*this).getQuad();
        S29cd0_hkQuadReal approx = _mm_rsqrt_ss(len2);
        approx = _mm_shuffle_ps(approx, approx, 0);
        m_vComponents = _mm_mul_ps(m_vComponents, approx);
        return _mm_mul_ss(len2, approx);
    }
    S29cd0_hkQuadReal m_vComponents;
};

class S29cd0_hkBool
{
  public:
    __forceinline S29cd0_hkBool()
    {}
    __forceinline S29cd0_hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    __forceinline S29cd0_hkBool& operator=(bool e)
    {
        m_cBooleanValue = static_cast<char>(e);
        return *this;
    }
    char m_cBooleanValue;
};

class S29cd0_hkMemoryAllocator
{
  public:
    virtual ~S29cd0_hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename TYPE> __forceinline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(TYPE);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};

class S29cd0_hkStackMemory
{
  public:
    __forceinline void* allocateStack(int numBytes, const char* what)
    {
        void* current = m_next;
        m_next = (char*)current + numBytes;
        return current;
    }
    __forceinline void deallocateStack(void* p)
    {
        m_next = p;
    }
    void* m_next;
    void* m_kRayStart;
    void* m_kRayEnd;
};

class S29cd0_hkMemoryRouter
{
  public:
    __forceinline S29cd0_hkStackMemory& stack()
    {
        return m_aiEntries;
    }
    __forceinline S29cd0_hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
    S29cd0_hkStackMemory m_aiEntries;
    S29cd0_hkMemoryAllocator* m_pTemp;
    S29cd0_hkMemoryAllocator* m_pStreamAllocator;
};
extern "C" S29cd0_hkMemoryRouter* __cdecl FUN_00c85750();

template <typename TYPE> __forceinline TYPE* S29cd0_hkAllocateStack(int n, const char* what = 0)
{
    S29cd0_hkMemoryRouter& mem = *FUN_00c85750();
    return static_cast<TYPE*>(mem.stack().allocateStack((n * sizeof(TYPE) + 127) & ~127, what));
}
template <typename TYPE> __forceinline void S29cd0_hkDeallocateStack(TYPE* ptr)
{
    FUN_00c85750()->stack().deallocateStack(static_cast<void*>(ptr));
}

struct S29cd0_hkContainerHeapAllocator
{
    __forceinline S29cd0_hkMemoryAllocator& get(const void*)
    {
        return FUN_00c85750()->heap();
    }
};

template <typename T> class S29cd0_hkArrayBase
{
  public:
    enum
    {
        CAPACITY_MASK = 0x3FFFFFFF,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };
    __forceinline S29cd0_hkArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void clear()
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            static_cast<T*>(m_data)[i].~T();
        }
        m_iElementCount = 0;
    }
    __forceinline void pushBackUnchecked(const T& t)
    {
        for (int i = 0; i < 1; ++i)
        {
            new (static_cast<void*>(m_data + m_iElementCount + i)) T(t);
        }
        m_iElementCount++;
    }
    __forceinline void _clearAndDeallocate(S29cd0_hkMemoryAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T, typename Allocator = S29cd0_hkContainerHeapAllocator>
class S29cd0_hkArray : public S29cd0_hkArrayBase<T>
{
  public:
    typedef Allocator AllocatorType;
    __forceinline S29cd0_hkArray() : S29cd0_hkArrayBase<T>()
    {}
    __forceinline ~S29cd0_hkArray()
    {
        ClearAndRelease();
    }
    __forceinline void ClearAndRelease()
    {
        S29cd0_hkArrayBase<T>::_clearAndDeallocate(AllocatorType().get(this));
    }
};

template <typename T> class S29cd0_hkLocalArray : public S29cd0_hkArray<T>
{
  public:
    __forceinline S29cd0_hkLocalArray(int capacity)
    {
        this->m_data = S29cd0_hkAllocateStack<T>(capacity);
        this->m_iCapacityState = capacity | S29cd0_hkArray<T>::DONT_DEALLOCATE_FLAG;
        m_pStackAllocation = this->m_data;
    }
    __forceinline S29cd0_hkBool wasReallocated() const
    {
        return m_pStackAllocation != this->m_data;
    }
    __forceinline ~S29cd0_hkLocalArray()
    {
        if (!wasReallocated())
        {
            S29cd0_hkArray<T>::clear();
        }
        S29cd0_hkDeallocateStack<T>(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};

struct S29cd0_int4
{
    __forceinline static void* operator new(std::size_t, void* p)
    {
        return p;
    }
    __forceinline static void operator delete(void*, void*)
    {}
    __forceinline S29cd0_int4()
    {
        for (int i = 0; i < 4; i++)
            m_ppIndices[i] = 0;
        m_iFirstInteger = 0;
    }
    __forceinline int& operator[](int i)
    {
        return m_ppIndices[i];
    }
    __forceinline const int& operator[](int i) const
    {
        return m_ppIndices[i];
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iFirstInteger;
    }
    __forceinline bool isFull() const
    {
        return m_iFirstInteger >= 4;
    }
    __forceinline void AddBack(int a)
    {
        m_ppIndices[m_iFirstInteger] = a;
        m_iFirstInteger++;
    }
    int m_ppIndices[4];
    int m_iFirstInteger;
};

struct S29cd0_hkpShapeRayCastCollectorOutput
{
    S29cd0_hkVector4 m_vHitNormal;
    S29cd0_hkReal m_fHitFraction;
    int m_iExtraInfo;
    int m_unk18;
    int m_unk1c;
};
struct S29cd0_hkpShapeRayCastOutput : public S29cd0_hkpShapeRayCastCollectorOutput
{
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};
struct S29cd0_hkpWorldRayCastOutput : public S29cd0_hkpShapeRayCastOutput
{
    const void* m_pRootCollidable;
};
struct S29cd0_hkpWorldRayCastInput
{
    S29cd0_hkVector4 m_vFrom;
    S29cd0_hkVector4 m_vTo;
    S29cd0_hkBool m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
};
struct S29cd0_hkpWorldRayCastCommand
{
    S29cd0_hkpWorldRayCastInput m_kRayCastQuery;
    S29cd0_hkpWorldRayCastOutput* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    S29cd0_hkBool m_bResultFlag;
    S29cd0_hkBool m_bUseCollector;
};
struct S29cd0_hkpWorldRayCastBundleCommand
{
    S29cd0_hkpWorldRayCastInput m_kRayCastQuery[4];
    int m_iRayCount;
    S29cd0_hkBool m_bUseCollector;
    S29cd0_hkpWorldRayCastOutput* m_pResultBuffer[4];
    __declspec(align(16)) int m_iResultCapacity[4];
    S29cd0_hkBool m_bResultFlag;
};

__declspec(noinline) void FUN_00e29a10(const S29cd0_hkLocalArray<S29cd0_int4>& clusters,
                                       const S29cd0_hkVector4* rayFrom, const S29cd0_hkVector4* rayTo,
                                       S29cd0_hkpWorldRayCastOutput* resultBuffer,
                                       S29cd0_hkpWorldRayCastCommand* singleCommandsOut, int& numSingleCommandsOut,
                                       S29cd0_hkpWorldRayCastBundleCommand* bundledCommandsOut,
                                       int& numBundledCommandsOut)
{
    S29cd0_hkpWorldRayCastOutput* output = resultBuffer;
    int numSingle = 0;
    int numBundled = 0;
    S29cd0_hkpWorldRayCastCommand* single = singleCommandsOut;
    S29cd0_hkpWorldRayCastBundleCommand* bundle = bundledCommandsOut;
    int numClusters = clusters.GetLogicalSize();
    for (int i = 0; i < numClusters; i++)
    {
        const S29cd0_int4& cluster = clusters[i];
        if (cluster.GetLogicalSize() == 1)
        {
            int rayIdx = cluster[0];
            single->m_kRayCastQuery.m_vFrom = rayFrom[rayIdx];
            single->m_kRayCastQuery.m_vTo = rayTo[rayIdx];
            single->m_kRayCastQuery.m_uiFilterInfo = 0;
            single->m_kRayCastQuery.m_bEnableShapeCollectionFilter = false;
            single->m_pResultBuffer = output + rayIdx;
            single->m_iResultCount = 1;
            single->m_iResultCapacity = 0;
            single->m_bUseCollector = false;
            single++;
            numSingle++;
        }
        else
        {
            int numActiveRays = cluster.GetLogicalSize();
            for (int j = 0; j < numActiveRays; j++)
            {
                int rayIdx = cluster[j];
                bundle->m_kRayCastQuery[j].m_vFrom = rayFrom[rayIdx];
                bundle->m_kRayCastQuery[j].m_vTo = rayTo[rayIdx];
                bundle->m_kRayCastQuery[j].m_uiFilterInfo = 0;
                bundle->m_kRayCastQuery[j].m_bEnableShapeCollectionFilter = false;
                bundle->m_pResultBuffer[j] = output + rayIdx;
                bundle->m_iResultCapacity[j] = 0;
            }
            bundle->m_iRayCount = numActiveRays;
            bundle->m_bUseCollector = false;
            bundle++;
            numBundled++;
        }
    }
    numSingleCommandsOut = numSingle;
    numBundledCommandsOut = numBundled;
}

// @fnv 0x00e29cd0
extern "C" void __cdecl FUN_00e29cd0(int* indices, int numIndices, const S29cd0_hkVector4* rayFrom,
                                     const S29cd0_hkVector4* rayTo, int numRays, S29cd0_hkReal angleVariance,
                                     S29cd0_hkReal distanceVariance2, S29cd0_hkpWorldRayCastOutput* resultBuffer,
                                     S29cd0_hkpWorldRayCastCommand* singleCommandsOut, int& numSingleCommandsOut,
                                     S29cd0_hkpWorldRayCastBundleCommand* bundledCommandsOut,
                                     int& numBundledCommandsOut)
{
    const S29cd0_hkReal cosVariance = fabsf(cosf(angleVariance));
    S29cd0_hkLocalArray<S29cd0_int4> clusters(numIndices);
    int* ptr = indices;
    for (int i = 0; i < numIndices; i++)
    {
        int rayIdx = *ptr;
        ptr++;
        S29cd0_hkVector4 from = rayFrom[rayIdx];
        S29cd0_hkVector4 to = rayTo[rayIdx];
        S29cd0_hkVector4 dir;
        dir.setSub4(to, from);
        S29cd0_hkSimdReal len2 = powf(dir.fastNormalizeWithLength3(), 2.0f);
        for (int c = 0; c < clusters.GetLogicalSize(); c++)
        {
            S29cd0_int4& cluster = clusters[c];
            if (cluster.isFull())
                continue;
            for (int j = 0; j < 1; j++)
            {
                int other = cluster[j];
                S29cd0_hkVector4 from1 = rayFrom[other];
                S29cd0_hkVector4 to1 = rayTo[other];
                S29cd0_hkVector4 dir1;
                dir1.setSub4(to1, from1);
                dir1.fastNormalize3();
                if (::RaySimilarityMath::FUN_00e29920((const ::RaySimilarityMath::RayVector &)(from), (const ::RaySimilarityMath::RayVector &)(to), (const ::RaySimilarityMath::RayVector &)(dir), (const ::RaySimilarityMath::RayVector &)(from1), (const ::RaySimilarityMath::RayVector &)(to1), (const ::RaySimilarityMath::RayVector &)(dir1), cosVariance,
                                 len2 * S29cd0_hkSimdReal(distanceVariance2)))
                {
                    cluster.AddBack(rayIdx);
                    goto NEXT_RAY;
                }
            }
        }
        {
            S29cd0_int4 newCluster;
            newCluster.AddBack(rayIdx);
            clusters.pushBackUnchecked(newCluster);
        }
    NEXT_RAY:;
    }
    FUN_00e29a10(clusters, rayFrom, rayTo, resultBuffer, singleCommandsOut, numSingleCommandsOut, bundledCommandsOut,
                 numBundledCommandsOut);
}
