
// src/havok/physics/collide/util/welding/hkpmeshweldingutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/welding/hkpmeshweldingutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <xmmintrin.h>
#include <cmath>
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cbf000.h"
#include "fnv/symbols_00d2c000.h"
#include "fnv/symbols_00ddd000.h"
#include "fnv/symbols_00dde000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_01268000.h"
struct Record
{
    float x, y, key;
};
struct ComparisonResult
{
    bool value;
    ComparisonResult(bool result) : value(result)
    {}
    operator bool() const
    {
        return value;
    }
};
__declspec(noinline) ComparisonResult FUN_00ddcda0(const Record& left, const Record& right)
{
    return ComparisonResult(left.key > right.key);
}
inline void SwapRecords(Record& first, Record& second)
{
    __declspec(align(16)) Record temp = second;
    second = first;
    first = temp;
}
// Sorts a range of records in place by key using a pivot and recursive quicksort, comparing with FUN_00ddcda0 and swapping with SwapRecords.
// @fnv 0x00ddeb70
void FUN_00ddeb70(Record* records, int left, int right, int comparator)
{
    int i = left;
    int j = right;
    __declspec(align(16)) Record pivotRecord = records[(left + right) >> 1];
    do
    {
        while (FUN_00ddcda0(records[i], pivotRecord))
            ++i;
        while (FUN_00ddcda0(pivotRecord, records[j]))
            --j;
        if (j >= i)
        {
            if (j != i)
            {
                SwapRecords(records[i], records[j]);
            }
            --j;
            ++i;
        }
    } while (i <= j);
    if (left < j)
        FUN_00ddeb70(records, left, j, comparator);
    if (i < right)
        FUN_00ddeb70(records, i, right, comparator);
}

struct DynamicArray
{
    void FUN_00ddecb0(void* alloc, int index, const void* elems, int count);
};
struct S_00ddecf0_Key
{
    float t;
    float a;
    float b;
};
struct S_00ddecf0_Array
{
    S_00ddecf0_Key* m_data;
    int m_iElementCount;
};

struct S_00ddecf0
{
    int unk0;
    S_00ddecf0_Array m_keys;
    void InsertKey(float t, float a, float b);
};

extern double DAT_010cd5a8;


// @fnv 0x00dddc40
int GetIndexForValue(const hkVector4q* aiArg)
{
    int n;
    float tmp;
    tmp = ::FUN_00ddd7e0(aiArg, (float *)(int *)(&n), &tmp);
    float r = tmp;

    for (n = 0; n < 31; n++)
    {
        tmp = (float)((double)n * DAT_010cd5a8 - DAT_0101ff40);
        if (r <= tmp)
            goto done;
    }
    return n;
done:
    if (r > 0.0f)
    {
        if (tmp != r)
            n--;
    }
    return n;
}

struct Iface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual Iface* GetSub();
    virtual void* Query(unsigned int key, void* out);
};

struct FlagTag
{
    bool m_bValue;
    FlagTag(bool value) : m_bValue(value)
    {}
    FlagTag(const FlagTag& other) : m_bValue(other.m_bValue)
    {}
};

struct Mgr
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void Write(unsigned int hash, FlagTag value);
    virtual void Read(bool* out, unsigned int hash);
};


__declspec(align(16)) struct QueryBuffer
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
};


// Reads a flag, clears it, runs up to three sub-queries via FUN_00dde4c0, sets result false if any returns 1, then restores the flag.
// @fnv 0x00dde930
bool* CheckSubQueries(bool* result, unsigned int key, Iface* self)
{
    QueryBuffer queryBuf;
    void* sub = self->GetSub()->Query(key, &queryBuf);
    bool flag;
    (*reinterpret_cast<::Mgr * *>(&::DAT_01268360))->Read(&flag, 0xfe98751e);
    if (flag)
    {
        Mgr* mgr = (*reinterpret_cast<::Mgr * *>(&::DAT_01268360));
        mgr->Write(0xfe98751e, FlagTag(false));
    }
    *result = true;
    int n = 0;
    for (int i = 0; i < 3; i++)
    {
        if (::FUN_00dde4c0((::S00dde4c0_Mesh *)(self), (::S00dde4c0_Tri *)(sub), key, i, 0, (unsigned short *)(int *)(&n)) == 1)
        {
            *result = false;
            break;
        }
    }
    if (flag)
    {
        Mgr* mgr = (*reinterpret_cast<::Mgr * *>(&::DAT_01268360));
        mgr->Write(0xfe98751e, FlagTag(true));
    }
    return result;
}



struct S_00ddeab0_Elem
{
    int a, b, c;
    S_00ddeab0_Elem()
    {}
};

struct S_00ddeab0
{
    S_00ddeab0_Elem* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void GrowArrayCapacity(void* alloc, int numElems)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < numElems)
        {
            int cap2 = cap + cap;
            int newcap = (numElems < cap2) ? cap2 : numElems;
            ::FUN_00c908c0((::SpawnedObject *)(alloc), (::SpawnedArray *)(void *)(this), newcap, 12);
        }
    }

    void SpliceElements(void* alloc, int index, int numdel, const S_00ddeab0_Elem* p, int numtoinsert);
};
// @fnv 0x00ddecb0
void DynamicArray::FUN_00ddecb0(void* alloc, int index, const void* elems, int count)
{
    reinterpret_cast<::S_00ddeab0 *>(this)->SpliceElements(alloc, index, 0, static_cast<const ::S_00ddeab0_Elem *>(elems), count);
}

// Replaces numdel elements at index with numtoinsert copies from p, shifting the tail and growing the buffer if needed.
// @fnv 0x00ddeab0
void S_00ddeab0::SpliceElements(void* alloc, int index, int numdel, const S_00ddeab0_Elem* apElems, int aiNumInsert)
{
    int newsize = m_iElementCount - numdel + aiNumInsert;
    unsigned int numtomove = m_iElementCount - index - numdel;
    GrowArrayCapacity(alloc, newsize);
    ::FUN_00d2cc70(&m_data[index + aiNumInsert], (void *)(&m_data[index + numdel]), numtomove * 12);
    S_00ddeab0_Elem* dst = m_data + index;
    for (int i = 0; i < aiNumInsert; ++i)
    {
        new (&dst[i]) S_00ddeab0_Elem(apElems[i]);
    }
    m_iElementCount = newsize;
}

struct S_00ddecd0
{
    void FUN_00ddecd0(void* alloc, int index, const S_00ddecf0_Key* key);
};
// @fnv 0x00ddecf0
void S_00ddecf0::InsertKey(float t, float a, float b)
{
    int n = m_keys.m_iElementCount;
    for (int i = 0; i < n; i++)
    {
        if (m_keys.m_data[i].t < t)
        {
            n = i + 1;
            break;
        }
    }
    S_00ddecf0_Key key;
    key.t = t;
    key.a = a;
    key.b = b;
    reinterpret_cast<::S_00ddecd0 *>(&(m_keys))->FUN_00ddecd0(&(hkMemoryRouter::getInstance().heap()), n, &key);
}
// @fnv 0x00ddecd0
void S_00ddecd0::FUN_00ddecd0(void* aiArg1, int aiArg2, const S_00ddecf0_Key* aiArg3)
{
    reinterpret_cast<::DynamicArray *>(this)->FUN_00ddecb0(aiArg1, aiArg2, aiArg3, 1);
}

struct FourFloatVector
{
    float x, y, z, w;
};

struct Transform
{
    int pad[8];
    FourFloatVector v0;
    FourFloatVector v1;
    FourFloatVector v2;
};

struct ObjInner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Transform* GetTransform(unsigned int p1, void* buffer);
};

struct ObjOuter
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ObjInner* GetInner();
};

struct LocalBuffer
{
    __declspec(align(16)) int data[125];
};

char* IsDegenerateTriangle(char* out, const FourFloatVector* v0, const FourFloatVector* v1, const FourFloatVector* v2,
                           float eps);

// @fnv 0x00dde880
int __cdecl CheckTransformAndProcess(unsigned int p1, ObjOuter* pOuter, int p3, short* outWord)
{
    LocalBuffer buffer;
    char checkResult;

    ObjInner* inner = pOuter->GetInner();
    Transform* trans = inner->GetTransform(p1, &buffer);

    if (*IsDegenerateTriangle(&checkResult, &trans->v0, &trans->v1, &trans->v2, 1.0e-7f) != 0)
    {
        *outWord = 0;
        return 1;
    }

    int iResult = 0;
    int local2 = 0;
    for (int i = 0; i < 3; ++i)
    {
        int iRet = ::FUN_00dde4c0((::S00dde4c0_Mesh *)(pOuter), (::S00dde4c0_Tri *)(trans), p1, i, p3, (unsigned short *)(int *)(&iResult));
        if (iRet == 1)
        {
            local2 = iRet;
        }
    }
    *outWord = (short)iResult;
    return local2;
}

#include "fnv/symbols_simd.h"



class hkBoolDDCE
{
  public:
    hkBoolDDCE(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }

    char m_cBooleanValue;
};

struct hkVector4DDCE
{
    __m128 m_vComponents;

    bool equals3(const hkVector4DDCE& v) const
    {
        __m128 t = _mm_sub_ps(m_vComponents, v.m_vComponents);
        t = _mm_and_ps(t, DAT_01017d10);
        const __m128 eps = _mm_load_ps1(&::AngularDashpotApplyD4DCB0::DAT_01017d00);
        return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 7) == 7;
    }
};

struct hkTransformHolderDDCE
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkVector4DDCE m_kColumn0;
    hkVector4DDCE m_kColumn1;
    hkVector4DDCE m_kColumn2;
};

struct hkUtilDDCE
{
    static hkBoolDDCE FUN_00ddced0(const hkTransformHolderDDCE& kA, const hkTransformHolderDDCE& kB);
};

// Returns true when the three column vectors of kA and kB are all equal within epsilon, using hkVector4DDCE::equals3.
// @fnv 0x00ddced0
hkBoolDDCE hkUtilDDCE::FUN_00ddced0(const hkTransformHolderDDCE& kA, const hkTransformHolderDDCE& kB)
{
    return kA.m_kColumn0.equals3(kB.m_kColumn0) && kA.m_kColumn1.equals3(kB.m_kColumn1) &&
           kA.m_kColumn2.equals3(kB.m_kColumn2);
}

namespace fnv_00ddd940 {

typedef float hkReal;


struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }

    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, (*reinterpret_cast<__m128 *>(&::DAT_010c4c00)));
    }
    __forceinline void setCross(const hkVector4& v0, const hkVector4& v1)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline hkReal dot3(const hkVector4& v) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
        hkReal r;
        _mm_store_ss(&r, s);
        return r;
    }
    __forceinline void normalize3()
    {
        __m128 p = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
        r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }
};

struct TriangleShape
{
    int m_kHeader[8];
    hkVector4 m_kVertices[3];
};


// Builds five planes for a triangle: its normal, the negated normal, and three edge planes (edge crossed with normal, normalized), each offset by -radius.
// @fnv 0x00ddd940
void GenerateTrianglePlanes(hkVector4* planes, const TriangleShape* triangle, hkReal radius)
{
    hkVector4 normal;
    ::FUN_00ddd620((const ::NormalVector *)&(triangle->m_kVertices[0]), (const ::NormalVector *)&(triangle->m_kVertices[1]), (const ::NormalVector *)&(triangle->m_kVertices[2]), (::NormalVector *)&(normal));

    hkReal d = -radius;

    hkVector4 e0;
    e0.setSub4(triangle->m_kVertices[1], triangle->m_kVertices[0]);
    hkVector4 e1;
    e1.setSub4(triangle->m_kVertices[2], triangle->m_kVertices[1]);
    hkVector4 e2;
    e2.setSub4(triangle->m_kVertices[0], triangle->m_kVertices[2]);

    planes[0] = normal;
    planes[0](3) = d - planes[0].dot3(triangle->m_kVertices[0]);

    planes[1].setNeg3(normal);
    planes[1](3) = d - planes[1].dot3(triangle->m_kVertices[0]);

    planes[2].setCross(e0, normal);
    planes[2].normalize3();
    planes[2](3) = d - planes[2].dot3(triangle->m_kVertices[0]);

    planes[3].setCross(e1, normal);
    planes[3].normalize3();
    planes[3](3) = d - planes[3].dot3(triangle->m_kVertices[1]);

    planes[4].setCross(e2, normal);
    planes[4].normalize3();
    planes[4](3) = d - planes[4].dot3(triangle->m_kVertices[2]);
}
}  // namespace fnv_00ddd940

struct FUN_00ddea00_src
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    const void* unk40;
};

__declspec(align(16)) struct FUN_00ddea00_tmp
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
};

__declspec(align(16)) struct FUN_00ddea00_cls
{
    __m128 m_v00;
    __m128 m_v10;
    __m128 m_v20;
    __m128 m_v30;
    const void* m_i40;

    FUN_00ddea00_cls* CopyFromSource(const FUN_00ddea00_src* src);
};

// Copies all fields from the source struct into the __m128 members and m_i40 of this object, then returns this.
// @fnv 0x00ddea00
FUN_00ddea00_cls* FUN_00ddea00_cls::CopyFromSource(const FUN_00ddea00_src* src)
{
    FUN_00ddea00_tmp tmp;
    tmp.unk00 = src->unk00;
    tmp.unk04 = src->unk04;
    tmp.unk08 = src->unk08;
    tmp.unk0C = src->unk0C;
    tmp.unk10 = src->unk10;
    tmp.unk14 = src->unk14;
    tmp.unk18 = src->unk18;
    tmp.unk1C = src->unk1C;
    tmp.unk20 = src->unk20;
    tmp.unk24 = src->unk24;
    tmp.unk28 = src->unk28;
    tmp.unk2C = src->unk2C;
    tmp.unk30 = src->unk30;
    tmp.unk34 = src->unk34;
    tmp.unk38 = src->unk38;
    unsigned int uiLastWord = src->unk3C;
    m_v00 = *(__m128*)&tmp.unk00;
    m_v10 = *(__m128*)&tmp.unk10;
    m_v20 = *(__m128*)&tmp.unk20;
    tmp.unk3C = uiLastWord;
    m_v30 = *(__m128*)&tmp.unk30;
    m_i40 = src->unk40;
    return this;
}


// Rotates a's three vectors by index into out, then appends each b[i] not equal to out[0] or out[1] (else stores i in result[j]) and returns the count.
// @fnv 0x00ddd6f0
int __cdecl FUN_00ddd6f0(const __m128* apVectors, const __m128* b, int aiStartIndex, __m128* out, int* result)
{
    out[0] = apVectors[aiStartIndex % 3];
    out[1] = apVectors[(aiStartIndex + 1) % 3];
    out[2] = apVectors[(aiStartIndex + 2) % 3];
    int count = 3;
    int i = 0;
    __m128* append = out + 3;
    for (; i < 3; ++i)
    {
        __m128 current = b[i];
        for (int j = 0; j < 2; ++j)
        {
            __m128 d = _mm_sub_ps(out[j], current);
            __m128 p = _mm_mul_ps(d, d);
            __m128 y = _mm_shuffle_ps(p, p, 0x55);
            __m128 z = _mm_shuffle_ps(p, p, 0xaa);
            y = _mm_add_ss(y, p);
            z = _mm_add_ss(z, y);
            float distance;
            _mm_store_ss(&distance, z);
            if (distance == 0.0f)
            {
                result[j] = i;
                goto next;
            }
        }
        ++count;
        __m128* destination = append;
        ++append;
        *destination = current;
    next:;
    }
    return count;
}


extern const float DAT_01011d78;
extern const float DAT_01017718;
extern "C" const float DAT_01016248;

struct ScalarNormal
{
    __m128 q;
    ScalarNormal(__m128 value) : q(value)
    {}
    __m128 broadcast() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
struct NormalVector
{
    __m128 q;
    __forceinline void difference(const NormalVector& a, const NormalVector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void cross(const NormalVector& a, const NormalVector& b)
    {
        __m128 pos = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 201), _mm_shuffle_ps(b.q, b.q, 210));
        __m128 neg = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 210), _mm_shuffle_ps(b.q, b.q, 201));
        q = _mm_sub_ps(pos, neg);
    }
    __forceinline ScalarNormal dot(const NormalVector& v) const
    {
        __m128 square = _mm_mul_ps(q, v.q);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(square, square, 85), square);
        return ScalarNormal(_mm_add_ss(_mm_shuffle_ps(square, square, 170), sum));
    }
    __forceinline ScalarNormal inverseLength() const
    {
        __m128 half = _mm_set_ss(DAT_01016248);
        __m128 three = _mm_set_ss(DAT_01017718);
        __m128 zero = _mm_set_ss(DAT_01011d78);
        __m128 len = dot(*this).q;
        __m128 mask = _mm_cmpeq_ss(len, zero);
        __m128 approx = _mm_rsqrt_ss(len);
        __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, approx), approx));
        return ScalarNormal(_mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, approx), correction)));
    }
    __forceinline void normalize()
    {
        q = _mm_mul_ps(inverseLength().broadcast(), q);
    }
};
// Computes the normalized cross product of two triangle edge vectors (b-a) and (c-b) and stores the result in out.
// @fnv 0x00ddd620
void FUN_00ddd620(const NormalVector* apVertexA, const NormalVector* apVertexB, const NormalVector* apVertexC,
                  NormalVector* apNormal)
{
    NormalVector edges[2];
    edges[0].difference(*apVertexB, *apVertexA);
    edges[1].difference(*apVertexC, *apVertexB);
    NormalVector n;
    n.cross(edges[0], edges[1]);
    n.normalize();
    *apNormal = n;
}



struct KeyLess
{
};
template <typename T, typename L> inline void quickSort(T* pArr, int size, L cmpLess)
{
    if (size > 1)
        ::FUN_00ddeb70((::Record *)(pArr), 0, size - 1, (*(int *)&(const ::KeyLess &)(cmpLess)));
}
__declspec(noinline) ComparisonResult __cdecl AreZDiffering(const S_00ddecf0_Key& a, const S_00ddecf0_Key& b) throw()
{
    float delta = a.b - b.b;
    float distance = (float)fabs(delta);
    bool same = distance < ::AngularDashpotApplyD4DCB0::DAT_01017d00;
    return ComparisonResult(!same);
}

struct ArrayAllocator
{
    __forceinline hkMemoryAllocator& get(const void*) const
    {
        return hkMemoryRouter::getInstance().heap();
    }
};
template <typename T> struct SpanStorage
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline SpanStorage() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int capacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void dispose(hkMemoryAllocator& alloc)
    {
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            alloc._bufFree<T>(m_data, capacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void append(hkMemoryAllocator& alloc, const T& value)
    {
        if (m_iElementCount == capacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc), (::AudioStream *)(void *)(this), sizeof(T));
        T* dest = m_data + m_iElementCount;
        new (dest) T(value);
        ++m_iElementCount;
    }
};
template <typename T, typename A = ArrayAllocator> struct hkArray : SpanStorage<T>
{
    __forceinline hkArray()
    {}
    __forceinline ~hkArray()
    {
        dispose(A().get(this));
    }
    __forceinline void AddBack(const T& value)
    {
        append(A().get(this), value);
    }
};

static inline float clamp(float x, float lo, float hi)
{
    if (x < lo)
        return lo;
    if (x > hi)
        return hi;
    return x;
}

struct Track : public S_00ddecf0
{
    float FUN_00dded60();
};

// If m_keys is empty returns unk0; else sorts it, groups near-equal-b keys, and returns the smallest b of a group with summed a-t >= DAT_010290b8, or 0.
// @fnv 0x00dded60
float Track::FUN_00dded60()
{
    if (m_keys.m_iElementCount == 0)
        return *(float*)&unk0;
    quickSort(m_keys.m_data, m_keys.m_iElementCount, KeyLess());

    hkArray<S_00ddecf0_Key> spans;
    {
        int start = 0;
        for (int i = 1; i <= m_keys.m_iElementCount; i++)
        {
            if (i < m_keys.m_iElementCount && !AreZDiffering(m_keys.m_data[start], m_keys.m_data[i]))
                continue;
            int n = i - start;
            float sum = 0.0f;
            for (int k = 0; k < n; k++)
            {
                const S_00ddecf0_Key& key = m_keys.m_data[start + k];
                sum += key.a - key.t;
            }
            S_00ddecf0_Key key;
            key.b = m_keys.m_data[start].b;
            key.t = 0.0f;
            key.a = clamp(sum, 0.0f, 1.0f);
            spans.AddBack(key);
            start = i;
        }
    }
    float minLen = 3.14159274f;
    bool found = false;
    for (int j = 0; j < spans.GetLogicalSize(); ++j)
    {
        S_00ddecf0_Key* p = &spans[j];
        if (!(p->a - p->t < DAT_010290b8))
        {
            float len = p->b;
            if (!(minLen < len))
                minLen = len;
            found = true;
        }
    }
    return found ? minLen : 0.0f;
}

// FUN_00ddcf60 - "point A is close to one of the three points of the shape
// AND point B is close to one of them as well" test.
//
// The shape object holds three 4-float points at +0x20 / +0x30 / +0x40.
// A point counts as a hit when the x/y/z components of the difference are not
// (movmskps + "and 7" + "cmp 7").
//
// The result byte is written through the first argument; the argument pointer
// is handed back to the caller.

struct Vec4
{
    __m128 v;
};

struct Shape
{
    float unk00, unk04, unk08, unk0c;
    float unk10, unk14, unk18, unk1c;
    Vec4 p0, p1, p2;
};

// Stores true in *out when points a and b are each within a tolerance of one of the shape's points p0, p1, p2, and returns out.
// @fnv 0x00ddcf60
volatile unsigned char* __cdecl FUN_00ddcf60(volatile unsigned char* out, const Vec4* apPointA, const Vec4* apPointB,
                                             const Shape* apShape)
{
    __m128 pt = apShape->p0.v;
    __m128 q = apPointA->v;
    __m128 eps = _mm_load_ps1(&::AngularDashpotApplyD4DCB0::DAT_01017d00);
    __m128 mask = DAT_01017d10;

    bool v =
        (((_mm_movemask_ps(_mm_cmple_ps(_mm_and_ps(_mm_sub_ps(pt, q), mask), eps)) & 7) == 7) ||
         ((_mm_movemask_ps(_mm_cmple_ps(_mm_and_ps(_mm_sub_ps(apShape->p1.v, q), mask), eps)) & 7) == 7) ||
         ((_mm_movemask_ps(_mm_cmple_ps(_mm_and_ps(_mm_sub_ps(apShape->p2.v, q), mask), eps)) & 7) == 7)) &&
        (((_mm_movemask_ps(_mm_cmple_ps(_mm_and_ps(_mm_sub_ps(pt, apPointB->v), mask), eps)) & 7) == 7) ||
         ((_mm_movemask_ps(_mm_cmple_ps(_mm_and_ps(_mm_sub_ps(apShape->p1.v, apPointB->v), mask), eps)) & 7) == 7) ||
         ((_mm_movemask_ps(_mm_cmple_ps(_mm_and_ps(_mm_sub_ps(apShape->p2.v, apPointB->v), mask), eps)) & 7) == 7));

    *out = v;
    return out;
}


struct hkVector4q
{
    __m128 m_vComponents;

    hkVector4q()
    {}
    hkVector4q(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }

    __forceinline void normalize3()
    {
        __m128 p = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
        r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }

    __forceinline void setCross(const hkVector4q& a, const hkVector4q& b)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }

    __forceinline float dot3(const hkVector4q& v) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
        float r;
        _mm_store_ss(&r, s);
        return r;
    }
};

static __forceinline float hkAtan2(float y, float x)
{
    return ::Atan2(y, x);
}

// Computes the dihedral angle between two adjacent triangles via their normals and edge cross product, storing sin and cos outputs.
// @fnv 0x00ddd7e0
float FUN_00ddd7e0(const hkVector4q* apVertices, float* sinOut, float* cosOut)
{
    hkVector4q nA;
    hkVector4q nB;
    ::FUN_00ddd620((const ::NormalVector *)&(apVertices[0]), (const ::NormalVector *)&(apVertices[1]), (const ::NormalVector *)&(apVertices[2]), (::NormalVector *)&(nA));
    ::FUN_00ddd620((const ::NormalVector *)&(apVertices[1]), (const ::NormalVector *)&(apVertices[0]), (const ::NormalVector *)&(apVertices[3]), (::NormalVector *)&(nB));

    hkVector4q edge;
    edge.setSub4(apVertices[1], apVertices[0]);
    edge.normalize3();

    hkVector4q c;
    c.setCross(edge, nA);

    *sinOut = c.dot3(nB);
    *cosOut = nB.dot3(nA);
    return hkAtan2(*sinOut, *cosOut);
}

struct __declspec(align(16)) Row
{
    float x, y, z, w;
};
struct __declspec(align(16)) Matrix44
{
    Row row0, row1, row2, row3;
};

struct __declspec(align(16)) Item
{
    Matrix44 transform;
    const void* payload;
};


struct S00dde760_ScratchVector
{
    Item* elements;
    unsigned int size;
    unsigned int encodedCapacity;
    char* originalCursor;
};


// Copies DAT_01268370 into a local Item, allocates a scratch vector from the pool, and passes it to FUN_00dddcd0.
// @fnv 0x00dde760
void __cdecl FUN_00dde760(::hkpShapeCollectionW* a, const void* aiPayload, int c, bool d)
{
    Item item;
    _mm_store_ps(&item.transform.row0.x, _mm_load_ps(&(*reinterpret_cast<::Matrix44 *>(&::DAT_01268370)).row0.x));
    _mm_store_ps(&item.transform.row1.x, _mm_load_ps(&(*reinterpret_cast<::Matrix44 *>(&::DAT_01268370)).row1.x));
    _mm_store_ps(&item.transform.row2.x, _mm_load_ps(&(*reinterpret_cast<::Matrix44 *>(&::DAT_01268370)).row2.x));
    _mm_store_ps(&item.transform.row3.x, _mm_load_ps(&(*reinterpret_cast<::Matrix44 *>(&::DAT_01268370)).row3.x));
    item.payload = aiPayload;
    S00dde760_ScratchVector vector;
    vector.elements = 0;
    vector.size = 0;
    vector.encodedCapacity = 0x80000000;
    hkMemoryRouter& router = hkMemoryRouter::getInstance();
    char* cursor = static_cast<char*>(router.allocateStack(0x80));
    vector.elements = reinterpret_cast<Item*>(cursor);
    vector.encodedCapacity = 0x80000001;
    vector.originalCursor = cursor;
    if (vector.size == (vector.encodedCapacity & 0x3fffffff))
    {
        ::ResizeAudioStream((::AudioAllocator *)(&hkMemoryRouter::getInstance().heap()), (::AudioStream *)(void *)(&vector), 0x50);
    }
    Item* destination = vector.elements + vector.size;
    if (destination != 0)
        reinterpret_cast<FUN_00ddea00_cls*>(destination)
            ->CopyFromSource(reinterpret_cast<const FUN_00ddea00_src*>(&item));
    ++vector.size;
    ::FUN_00dddcd0((*(const ::hkTransformW *)(&(*reinterpret_cast<::Matrix44 *>(&::DAT_01268370)))), a, c, (*(::hkShapeInfoArrayW *)(&vector)), d);
    char* finalCursor = vector.originalCursor;
    if (finalCursor == reinterpret_cast<char*>(vector.elements))
        vector.size = 0;
    hkMemoryRouter::getInstance().deallocateStack(finalCursor);
    hkMemoryAllocator* currentAllocator = &hkMemoryRouter::getInstance().heap();
    vector.size = 0;
    if ((vector.encodedCapacity & 0x80000000u) == 0)
        currentAllocator->bufFree(vector.elements, (vector.encodedCapacity & 0x3fffffff) * 0x50);
}

// Moved from hkpmeshweldingutility_ehsc_noehsc_variant.cpp (VEGAS-15).
#include <new>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/hkTransformCB22.h"
#include "fnv/symbols_00ceb000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0103c000.h"
#include "fnv/symbols_010d7000.h"


extern char DAT_010d7f80;

class hkSimdRealW
{
  public:
    hkSimdRealW(const __m128& x) : m_vValue(x)
    {}
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

class hkBoolW
{
  public:
    inline hkBoolW()
    {}
    inline hkBoolW(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    inline hkBoolW& operator=(bool e)
    {
        m_cBooleanValue = static_cast<char>(e);
        return *this;
    }

  private:
    char m_cBooleanValue;
};

template <typename ENUM, typename STORAGE> class hkEnumW
{
  public:
    operator ENUM() const
    {
        return static_cast<ENUM>(m_kStorage);
    }
    hkBoolW operator==(ENUM e) const
    {
        return m_kStorage == static_cast<STORAGE>(e);
    }
    hkBoolW operator!=(ENUM e) const
    {
        return m_kStorage != static_cast<STORAGE>(e);
    }

  private:
    STORAGE m_kStorage;
};

enum hkpShapeTypeW
{
    HK_SHAPE_TRIANGLE_W = 3
};
enum hkCollectionTypeW
{
    COLLECTION_LIST_W = 1,
    COLLECTION_EXTENDED_MESH_W = 2,
    COLLECTION_TRISAMPLED_HEIGHTFIELD_W = 4,
    COLLECTION_USER_W = 5,
    COLLECTION_SIMPLE_MESH_W = 6
};

struct hkRotationW;
struct hkTransformW;

// hkVector4 (hkSseVector4.inl)
struct hkVector4W
{
    __m128 m_vComponents;

    inline void SetAllComponents(float a)
    {
        m_vComponents = _mm_set_ps1(a);
    }
    inline void setSub4(const hkVector4W& v0, const hkVector4W& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void setMin4(const hkVector4W& a, const hkVector4W& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    inline void setMax4(const hkVector4W& a, const hkVector4W& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    inline void setCross(const hkVector4W& v0, const hkVector4W& v1)
    {
        __m128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    inline hkSimdRealW dot3(const hkVector4W& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    inline hkSimdRealW lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot3(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    inline void normalize3()
    {
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    inline void _setMul3(const hkRotationW& a, const hkVector4W& b);
    inline void _setRotatedDir(const hkRotationW& r, const hkVector4W& v)
    {
        _setMul3(r, v);
    }
    inline void _setTransformedPos(const hkTransformW& t, const hkVector4W& b);
};

struct hkRotationW
{
    hkVector4W m_kColumn0;
    hkVector4W m_kColumn1;
    hkVector4W m_kColumn2;
    const hkVector4W& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
};

struct hkTransformW
{
    hkRotationW m_rotation;
    hkVector4W m_vTranslation;
    hkTransformW()
    {}
    const hkRotationW& getRotation() const
    {
        return m_rotation;
    }
    const hkVector4W& getTranslation() const
    {
        return m_vTranslation;
    }
};

inline void hkVector4W::_setMul3(const hkRotationW& a, const hkVector4W& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

inline void hkVector4W::_setTransformedPos(const hkTransformW& t, const hkVector4W& b)
{
    const hkRotationW& r = t.getRotation();
    __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    __m128 r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    __m128 r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    __m128 r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.getTranslation().m_vComponents));
}

struct hkAabbW
{
    hkVector4W m_kMinimumCorner;
    hkVector4W m_kMaximumCorner;
    hkAabbW()
    {}
    inline hkAabbW(const hkVector4W& p0, const hkVector4W& p1)
    {
        setEmpty();
        includePoint(p0);
        includePoint(p1);
    }
    inline void setEmpty()
    {
        m_kMinimumCorner.SetAllComponents(3.40282e+38f);
        m_kMaximumCorner.SetAllComponents(-3.40282e+38f);
    }
    inline void includePoint(const hkVector4W& point)
    {
        m_kMinimumCorner.setMin4(m_kMinimumCorner, point);
        m_kMaximumCorner.setMax4(m_kMaximumCorner, point);
    }
};

struct hkpTriangleShapeW
{
    int vtbl;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    hkEnumW<hkpShapeTypeW, unsigned int> m_type;
    int unk10, unk14, unk18, unk1c;
    hkVector4W m_kVertexA;
    hkVector4W m_kVertexB;
    hkVector4W m_kVertexC;
    hkpShapeTypeW getType() const
    {
        return m_type;
    }
    const hkVector4W& getVertex(int i) const
    {
        return (&m_kVertexA)[i];
    }
};

struct hkInplaceArrayW
{
    unsigned int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[128];
    inline hkInplaceArrayW(int size)
    {
        m_data = m_kStorage;
        m_iElementCount = size;
        m_iCapacityState = 128 | 0x80000000;
    }
    inline ~hkInplaceArrayW()
    {
        hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(unsigned int));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    unsigned int& operator[](int i)
    {
        return m_data[i];
    }
};

struct hkEntryW
{
    float a, b, c;
};

struct hkHistogramW
{
    float m_fScalar;
    hkEntryW* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    inline hkHistogramW(bool zeroTolerance)
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
        m_fScalar = zeroTolerance ? 0.0f : 3.14159265f;
    }
    inline ~hkHistogramW()
    {
        hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(hkEntryW));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct hkpShapeContainerW
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual const hkpTriangleShapeW* GetShapeForKey(unsigned int key, QueryBuffer& buffer) const;
};

struct hkpBvTreeShapeW
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual const hkpShapeContainerW* GetShapeContainer() const;
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void GetAabbHits(const hkAabbW& aabb, hkInplaceArrayW& hits) const;
};

struct hkShapeInfoW
{
    hkTransformW m_kMotionTransform;
    const hkpBvTreeShapeW* m_pCollisionShape;
};

struct hkShapeInfoArrayW
{
    hkShapeInfoW* m_data;
    int m_iElementCount;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    hkShapeInfoW& operator[](int i)
    {
        return m_data[i];
    }
};

struct hkpShapeCollectionContainerW
{
    virtual void v0();
    virtual void v1();
    virtual int GetFirstKey() const;
    virtual int GetNextShapeKey(int) const;
    virtual void v4();
    virtual const hkpTriangleShapeW* GetShapeForKey(int, QueryBuffer&) const;
};

struct hkpShapeCollectionW
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
    virtual void SetWeldingMode(int weldingType);
    virtual void SetWeldingInfo(int key, unsigned int weldingInfo);
    int unk04;
    int unk08;
    int unk0c;
    hkpShapeCollectionContainerW m_container;
    hkBoolW m_bDisableWelding;
    hkEnumW<hkCollectionTypeW, unsigned char> m_eCollectionType;
};

struct TextFormat
{
    char* data;
    int size;
    int capacityFlags;
};

struct ErrorManager
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int Report(int, unsigned, char*, const char*, int);
};

// hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal
__declspec(noinline) void __cdecl FUN_00ddd620(const hkVector4W& v0, const hkVector4W& v1, const hkVector4W& v2,
                                               hkVector4W& normal)
{
    hkVector4W e0;
    e0.setSub4(v1, v0);
    hkVector4W e1;
    e1.setSub4(v2, v1);
    normal.setCross(e0, e1);
    normal.normalize3();
}
hkBoolW __cdecl FUN_00ddcf60(const hkVector4W& v0, const hkVector4W& v1, const hkpTriangleShapeW* triangle);
float __cdecl FUN_00ddd5a0(const hkVector4W& normal, const hkVector4W& perp, const hkVector4W& otherNormal);
void __cdecl GenerateTrianglePlanes(hkVector4W* planes, const hkpTriangleShapeW* triangle, float tolerance);
hkBoolW __cdecl FUN_00ddd0b0(const hkVector4W& a, const hkVector4W& b, int numPlanes, const hkVector4W* planes,
                             float& tmin, float& tmax);
int __cdecl FindAngleIndex(float angle);
unsigned int __cdecl FUN_00ddcdd0(unsigned int combined, int edgeIndex, unsigned int code);

// hkIsEdgeInTrianglePlane
__declspec(noinline) hkBoolW __cdecl IsDotProductBelowThreshold(const hkVector4W& edge, const hkVector4W& normal)
{
    __m128 product = _mm_mul_ps(edge.m_vComponents, normal.m_vComponents);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 85), product);
    sum = _mm_add_ss(_mm_shuffle_ps(product, product, 170), sum);
    float scalar;
    _mm_store_ss(&scalar, sum);
    float magnitude = (float)fabs((double)scalar);
    return hkBoolW(magnitude < DAT_0103c7c8);
}

// @fnv 0x00dddcd0
void __cdecl FUN_00dddcd0(const hkTransformW& transform, hkpShapeCollectionW* collection, int weldingType,
                          hkShapeInfoArrayW& allShapes, bool weldOpenEdges)
{
    if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBoolW &)(collection->m_eCollectionType != COLLECTION_LIST_W))->FUN_005609f0() &&
        reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBoolW &)(collection->m_eCollectionType != COLLECTION_EXTENDED_MESH_W))->FUN_005609f0() &&
        reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBoolW &)(collection->m_eCollectionType != COLLECTION_SIMPLE_MESH_W))->FUN_005609f0() &&
        reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBoolW &)(collection->m_eCollectionType != COLLECTION_TRISAMPLED_HEIGHTFIELD_W))->FUN_005609f0() &&
        reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBoolW &)(collection->m_eCollectionType != COLLECTION_USER_W))->FUN_005609f0())
    {
        QueryBuffer messageStorage;
        char* message = reinterpret_cast<char*>(&messageStorage);
        TextFormat formatted;
        new ((void *)&(formatted)) ::FUN_00cb1600(message, 512);
        reinterpret_cast<::SinkOwner *>(&(formatted))->FUN_00cc01c0(&DAT_010d7f80);
        ((ErrorManager*)(*reinterpret_cast<::Mgr * *>(&::DAT_01268360)))->Report(1, 0x3f508c6a, message, &DAT_010d7f50, 271);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(formatted))->FUN_00cc00e0::~FUN_00cc00e0();
        return;
    }

    collection->SetWeldingMode(weldingType);
    if (weldingType == 6)
        return;
    collection->m_bDisableWelding = true;
    hkpShapeCollectionContainerW* container = &collection->m_container;
    for (int key = container->GetFirstKey(); key != -1; key = container->GetNextShapeKey(key))
    {
        QueryBuffer buffer;
        const hkpTriangleShapeW* triangle = container->GetShapeForKey(key, buffer);
        if (triangle->getType() != HK_SHAPE_TRIANGLE_W)
            continue;

        unsigned int weldingInfo = 0;
        hkVector4W triangleNormal;
        FUN_00ddd620(triangle->getVertex(0), triangle->getVertex(1), triangle->getVertex(2), triangleNormal);

        for (int edgeIndex = 0; edgeIndex < 3; edgeIndex++)
        {
            hkHistogramW histogram(weldOpenEdges);
            hkVector4W v0 = triangle->getVertex(edgeIndex);
            hkVector4W v1 = triangle->getVertex((edgeIndex + 1) % 3);
            hkVector4W v2 = triangle->getVertex((edgeIndex + 2) % 3);

            for (int shapeIndex = 0; shapeIndex < allShapes.GetLogicalSize(); shapeIndex++)
            {
                const hkShapeInfoW& info = allShapes[shapeIndex];
                const hkpBvTreeShapeW* bvTree = allShapes[shapeIndex].m_pCollisionShape;
                hkTransformW t;
                reinterpret_cast<::hkTransformCB22 *>(&(t))->FUN_00cb22f0((const ::hkTransformCB22 &)(info.m_kMotionTransform), (const ::hkTransformCB22 &)(transform));

                hkVector4W normal;
                normal._setRotatedDir(t.getRotation(), triangleNormal);
                hkVector4W a;
                a._setTransformedPos(t, v0);
                hkVector4W b;
                b._setTransformedPos(t, v1);
                hkVector4W c;
                c._setTransformedPos(t, v2);
                hkVector4W edge;
                edge.m_vComponents = _mm_sub_ps(b.m_vComponents, a.m_vComponents);
                edge.normalize3();

                hkInplaceArrayW hits(0);
                bvTree->GetAabbHits(hkAabbW(a, b), hits);

                for (int j = 0; j < hits.GetLogicalSize(); j++)
                {
                    unsigned int hitKey = hits[j];
                    const hkpShapeContainerW* shapeContainer = bvTree->GetShapeContainer();
                    QueryBuffer shapeBuffer;
                    const hkpTriangleShapeW* other = shapeContainer->GetShapeForKey(hitKey, shapeBuffer);
                    if (other->getType() != HK_SHAPE_TRIANGLE_W)
                        continue;

                    if (hkUtilDDCE::FUN_00ddced0(*(const hkTransformHolderDDCE*)triangle,
                                                 *(const hkTransformHolderDDCE*)other)
                            .m_cBooleanValue ||
                        reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBoolW &)(FUN_00ddcf60(b, c, other)))->FUN_005609f0() || reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBoolW &)(FUN_00ddcf60(c, a, other)))->FUN_005609f0())
                        continue;

                    hkVector4W otherNormal;
                    FUN_00ddd620(other->getVertex(0), other->getVertex(1), other->getVertex(2), otherNormal);
                    if (!reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBoolW &)(IsDotProductBelowThreshold(edge, otherNormal)))->FUN_005609f0())
                        continue;

                    hkVector4W perp;
                    perp.setCross(edge, normal);
                    perp.normalize3();
                    float angle = FUN_00ddd5a0(normal, perp, otherNormal);

                    hkVector4W planes[5];
                    GenerateTrianglePlanes(planes, other, 0.05f);
                    float tmin, tmax;
                    if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBoolW &)(FUN_00ddd0b0(a, b, 5, planes, tmin, tmax)))->FUN_005609f0())
                        reinterpret_cast<::S_00ddecf0 *>(&(histogram))->InsertKey(tmin, tmax, angle);
                }
            }
            weldingInfo = (unsigned short)FUN_00ddcdd0(weldingInfo, edgeIndex, FindAngleIndex(reinterpret_cast<::Track *>(&(histogram))->FUN_00dded60()));
        }
        collection->SetWeldingInfo(key, weldingInfo);
    }
}

// Moved from hkpmeshweldingutility_rtm_variant.cpp (VEGAS-15).
#include "fnv/decl/FUN_00cc02d0_cls.h"
#include "fnv/symbols_00ddc000.h"
#include "fnv/symbols_01014000.h"
volatile unsigned char* __cdecl FUN_00ddcf60(volatile unsigned char* out, const Vec4* a, const Vec4* b, const Shape* s);
void __cdecl FUN_00dde760(int a, int b, int c, int d);


extern const char str_010d7fc8[];
extern const char str_010d8004[];
extern const char str_010d8014[];

struct S00dde4c0_Vec
{
    __m128 q;
    __forceinline void setAll3(float v)
    {
        q = _mm_setr_ps(v, v, v, ::DAT_01011d78);
    }
};
struct S00dde4c0_Tri
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S00dde4c0_Vec v[3];
};
struct S00dde4c0_Aabb
{
    S00dde4c0_Vec mn;
    S00dde4c0_Vec mx;
};

struct S00dde4c0_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int type;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int data;
};
struct S00dde4c0_Src
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual S00dde4c0_Shape* getShape(int index, void* buffer);
};
struct S00dde4c0_Mesh
{
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual S00dde4c0_Src* getSource();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void query(S00dde4c0_Aabb* aabb, void* outArray);
};
struct S00dde4c0_Out
{
    hkVector4q v[6];
};

struct S00dde4c0_Array
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_kStorage[128];
    __forceinline S00dde4c0_Array()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000080;
    }
    __forceinline void finish()
    {
        release(hkMemoryRouter::getInstance().heap());
    }
    __forceinline void release(::hkMemoryAllocator& a)
    {
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            a._bufFree<int>(m_data, m_iCapacityState & 0x3fffffff);
    }
};
struct S00dde4c0_Buf
{
    int b[128];
};

struct S00dde4c0_Str
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S00dde4c0_Err
{
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void report(int a, unsigned int id, const char* msg, const char* file, int line);
};

unsigned int __cdecl FUN_00ddcdd0(unsigned int f, unsigned int idx, unsigned int v);

// @fnv 0x00dde4c0
int __cdecl FUN_00dde4c0(S00dde4c0_Mesh* mesh, S00dde4c0_Tri* tri, int skip, int idx, int checkWinding,
                         unsigned short* flags)
{
    const S00dde4c0_Vec* verts = tri->v;
    S00dde4c0_Array hits;
    {
        S00dde4c0_Aabb aabb;
        struct BoundsWork
        {
            S00dde4c0_Vec center;
            S00dde4c0_Vec lo;
        } work;
        work.center = verts[idx % 3];
        float eps = ::DAT_010141cc;
        work.lo.setAll3(-eps);
        __m128 low = work.lo.q;
        S00dde4c0_Vec hi;
        hi.setAll3(eps);
        aabb.mn.q = _mm_add_ps(low, work.center.q);
        aabb.mx.q = _mm_add_ps(hi.q, work.center.q);
        mesh->query(&aabb, &hits);
    }
    bool first = true;
    for (int i = hits.m_iElementCount - 1; i >= 0; i--)
    {
        int other = hits.m_data[i];
        if (other == skip)
            continue;
        S00dde4c0_Buf buffer;
        S00dde4c0_Shape* shape = mesh->getSource()->getShape(other, &buffer);
        if (shape->type != 3)
            continue;
        int winding[2];
        S00dde4c0_Out out;
        if (::FUN_00ddd6f0((const __m128 *)(verts), (const __m128 *)(const void *)(&shape->data), idx, &out.v[0].m_vComponents, winding) != 4)
            continue;
        if (checkWinding && winding[0] != (winding[1] + 1) % 3)
        {
            if (first)
            {
                S00dde4c0_Str sb;
                new ((void *)&(sb)) ::FUN_00cb1600(&buffer, 0x200);
                reinterpret_cast<::SinkOwner *>(&((*(::S00dde4c0_Str *)(reinterpret_cast<::FUN_00cc02d0_cls *>(&((*(::S00dde4c0_Str *)(reinterpret_cast<::SinkOwner *>(&((*(::S00dde4c0_Str *)(reinterpret_cast<::FUN_00cc02d0_cls *>(&((*(::S00dde4c0_Str *)(reinterpret_cast<::SinkOwner *>(&(sb))->FUN_00cc01c0(str_010d7fc8)))))->FUN_00cc02d0(skip)))))->FUN_00cc01c0(str_010d8004)))))->FUN_00cc02d0(other)))))->FUN_00cc01c0(str_010d8014);
                ((S00dde4c0_Err*)(*reinterpret_cast<::Mgr * *>(&::DAT_01268360)))->report(1, 0xabba751e, (const char*)&buffer, (*reinterpret_cast<const char (*)[]>(&::DAT_010d7f50)), 0x2c9);
                reinterpret_cast<struct ::FUN_00cc00e0 *>(&(sb))->FUN_00cc00e0::~FUN_00cc00e0();
            }
            first = false;
        }
        *flags = (unsigned short)FUN_00ddcdd0(*flags, idx, ::GetIndexForValue(out.v));
    }
    int result = !first;
    hits.finish();
    return result;
}
#include "generated/data/havok/physics/collide/util/welding/hkpmeshweldingutility.inc"
