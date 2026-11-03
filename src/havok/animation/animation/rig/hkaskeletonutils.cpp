
// src/havok/animation/animation/rig/hkaskeletonutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/rig/hkaskeletonutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstddef>
#include "fnv/decl/FUN_005611c0_t.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00cdd000.h"
#include "fnv/symbols_00ce0000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0104d000.h"
#include <xmmintrin.h>
#include <windows.h>
#include <new>
#include <cstring>
#include "fnv/decl/CC0280Writer.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00cde940_cls.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cbf000.h"
#include "fnv/symbols_00cde000.h"
#include "fnv/symbols_00d27000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_01268000.h"
struct FUN_00cdd3f0_s
{
    int a[6];
    int* field_0x18;
    int field_0x1c;
};

// @fnv 0x00cdd3f0
void FUN_00cdd3f0(struct FUN_00cdd3f0_s* pEntries)
{
    int n = pEntries->field_0x1c;
    for (int i = 0; i < n; ++i)
        *(char*)((char*)pEntries->field_0x18 + i * 8 + 4) = 0;
}

extern "C" void __cdecl FUN_00cddad0(int, int, int*, int, int);

// Calls FUN_00cddad0 with a, b, the address of DAT_01268700, c and d.
// @fnv 0x00cddcf0
void __cdecl CallWithGlobal(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    FUN_00cddad0(aiArg1, aiArg2, &DAT_01268700, aiArg3, aiArg4);
}

extern "C" void __cdecl FUN_00cddd20(void* a, void* b, void* c, void* d, void* e);

// Calls FUN_00cddd20 with a, b, the address of DAT_01268700, c and d.
// @fnv 0x00cddef0
void FUN_00cddef0(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    FUN_00cddd20(apArg1, apArg2, &DAT_01268700, apArg3, apArg4);
}


// @fnv 0x00ce00f0
void __cdecl FUN_00ce00f0(float afFirst, float afSecond)
{
    ::Atan2(afFirst, afSecond);
}

struct S_00cdd390_Entry
{
    unsigned int m_uiTaggedItem;
    int unk04;
};
struct S_00cdd390_Table
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00cdd390_Entry* m_pEntries;
    int m_iArrayLength;
    int GetCount() const
    {
        return m_iArrayLength;
    }
    void* GetAt(int i) const
    {
        return (void*)(m_pEntries[i].m_uiTaggedItem & ~1u);
    }
};
// Searches the table's entries for one matching pKey via pfnCompare (default CompareStringsCaseInsensitive) and returns its index, or -1 if none match.
// @fnv 0x00cdd390
short __cdecl FindIndexByKey(S_00cdd390_Table* pSearchEntries, const void* pKey,
                             int(__cdecl* pfnCompare)(const void*, const void*))
{
    int iCount = pSearchEntries->GetCount();
    if (!pfnCompare)
        pfnCompare = ((int (&)(const void *, const void *))::fnv_00cb0fe0::CompareStringsCaseInsensitive);
    for (short i = 0; i < iCount; i++)
    {
        if (pfnCompare(pKey, pSearchEntries->GetAt(i)) == 0)
            return i;
    }
    return -1;
}

template <class T> struct Array
{
    T* data;
    int size;
    int capacity;
    __forceinline T& operator[](int index)
    {
        return data[index];
    }
};
struct Hierarchy
{
    int unk00;
    int unk04;
    int unk08;
    Array<short> parents;
    void* nodes;
    int count;
};
// Clears flags up to root, marks root, then sets each later node's flag from whether its parent is flagged, and finally sets root to finalValue.
// @fnv 0x00cdd410
void __cdecl MarkHierarchyDescendants(Hierarchy* hierarchy, int root, unsigned char* flags, unsigned char finalValue)
{
    if (root > 0)
        std::memset(flags, 0, root);
    flags[root] = 1;
    for (int i = root + 1; i < hierarchy->count; ++i)
    {
        short& parent = hierarchy->parents[i];
        flags[i] = (parent >= 0 && flags[parent] != 0) ? 1 : 0;
    }
    flags[root] = finalValue;
}

struct Sequence
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    short* values;
    int count;
};
// Checks every value in sequence->values against limits->field_0x1c, writing true to result if all are in [0, limit) and false otherwise.
// @fnv 0x00cdd5b0
bool* __cdecl AreSequenceValuesInRange(bool* pbInRange, FUN_00cdd3f0_s* limits, Sequence* sequence)
{
    int i = 0;
    for (; i < sequence->count; ++i)
    {
        short value = sequence->values[i];
        if (value < 0 || value >= limits->field_0x1c)
        {
            *pbInRange = false;
            return pbInRange;
        }
    }
    *pbInRange = true;
    return pbInRange;
}

struct Msg
{
    int f0, f4, f8;
};
struct Logger
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Report(int a, int code, void* msg, const char* file, int line);
};
struct Names
{
    int pad[6];
    unsigned int* names;
    int count;
};
struct Track
{
    int pad[4];
    short* out;
    int cnt;
};
struct Src
{
    int pad[4];
    int n;
    int p14;
    int p18;
    unsigned int* arr;
    int f20;
};
struct Dst
{
    int pad[4];
    short* out;
    int cnt;
};

typedef int(__cdecl* CmpFn)(unsigned int, unsigned int);

// Validates that the binding and track names are initialized, then maps each track to a bone index by comparing names and writes the indices to dst->out.
// @fnv 0x00cdd880
int __cdecl MapTracksToBones(Names* names, Src* src, CmpFn cmp, Dst* dst)
{
    if (dst->cnt == 0 || dst->cnt != src->n)
    {
        int buf[0x80];
        Msg m;
        new ((void *)&(m)) ::FUN_00cb1600(buf, 0x200);
        reinterpret_cast<::SinkOwner *>(&(m))->FUN_00cc01c0("Binding is not initiialized");
        (*reinterpret_cast<::Logger * *>(&::DAT_01268360))->Report(1, 0x654e3435, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x1b7);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(m))->FUN_00cc00e0::~FUN_00cc00e0();
        return 1;
    }
    if (src->f20 != src->n)
    {
        int buf[0x80];
        Msg m;
        new ((void *)&(m)) ::FUN_00cb1600(buf, 0x200);
        reinterpret_cast<::SinkOwner *>(&(m))->FUN_00cc01c0("No track names present in animation");
        (*reinterpret_cast<::Logger * *>(&::DAT_01268360))->Report(1, 0x654e3437, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x1be);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(m))->FUN_00cc00e0::~FUN_00cc00e0();
        return 1;
    }
    int cnt = names->count;
    int i;
    for (i = 0; i < cnt; i++)
    {
        if ((names->names[i * 2] & ~1u) == 0)
        {
            int buf[0x80];
            Msg m;
            new ((void *)&(m)) ::FUN_00cb1600(buf, 0x200);
            reinterpret_cast<::CC0280Writer *>(&((*(::Msg *)(reinterpret_cast<::SinkOwner *>(&(m))->FUN_00cc01c0("No bone name for bone ")))))->WriteInt({});
            (*reinterpret_cast<::Logger * *>(&::DAT_01268360))->Report(1, 0x654e3437, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x1c8);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(m))->FUN_00cc00e0::~FUN_00cc00e0();
            return 1;
        }
    }
    for (int t = 0; t < src->n; t++)
    {
        bool found = false;
        unsigned int uiTrackKey = src->arr[t * 4] & ~1u;
        short j = 0;
        for (; j < names->count; j++)
        {
            unsigned int uiBoneName = names->names[j * 2] & ~1u;
            if (cmp(uiBoneName, uiTrackKey) == 0)
            {
                found = true;
                dst->out[t] = j;
            }
        }
        if (!found)
        {
            int buf[0x80];
            Msg m;
            new ((void *)&(m)) ::FUN_00cb1600(buf, 0x200);
            reinterpret_cast<::SinkOwner *>(&((*(::Msg *)(reinterpret_cast<::SinkOwner *>(&(m))->FUN_00cc01c0("No match for track ")))))->FUN_00cc01c0({});
            (*reinterpret_cast<::Logger * *>(&::DAT_01268360))->Report(1, 0x654e3438, buf, ".\\Rig\\hkaSkeletonUtils.cpp", 0x1de);
            reinterpret_cast<struct ::FUN_00cc00e0 *>(&(m))->FUN_00cc00e0::~FUN_00cc00e0();
            return 1;
        }
    }
    return 0;
}

struct HolderRec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_10;
};

struct ScanRec
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short* m_0c;
};

struct ScanObj
{
};

HolderRec* FUN_00c85750();

// @fnv 0x00cde3d0
unsigned char* WalkChainUntilLimit(unsigned char* pabResult, ScanRec* rec, short asLimit, short asStart, ScanObj* obj)
{
    short s = asStart;
    int idx = (unsigned short)s;
    int iCurrent = idx;
    short sLimit = asLimit;
    if (s > 0)
    {
        do
        {
            if ((short)idx == sLimit)
                break;
            HolderRec* h = FUN_00c85750();
            reinterpret_cast<::FUN_00cde940_cls *>((obj))->FUN_00cde940(h->m_10, 0, (int)(&iCurrent));
            idx = rec->m_0c[(short)idx];
            iCurrent = idx;
        } while ((short)idx > 0);
    }
    {
        int out;
        HolderRec* h = FUN_00c85750();
        reinterpret_cast<::FUN_00cde940_cls *>((obj))->FUN_00cde940(h->m_10, 0, (int)(&out));
    }
    *pabResult = ((short)idx >= 0);
    return pabResult;
}

namespace fnv_00cde450 {
struct S_00cde450_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n);
};

struct S_00cde450_Router
{
    char* m_fMinimumV;
    int unk04;
    int unk08;
    int unk0c;
    S_00cde450_Heap* m_pStreamAllocator;
    S_00cde450_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00cde450_Router* __cdecl FUN_00c85750();

struct S_00cde450_ByteArr;
struct S_00cde450_UShortArr;

struct S_00cde450_UShortArr
{
    unsigned short* m_data;
    int m_iElementCount;
    int m_cap;

    void AddBack(unsigned short v)
    {
        S_00cde450_Heap& h = FUN_00c85750()->heap();
        if (m_iElementCount == (m_cap & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)&(h), (::AudioStream *)(::fnv_00cde450::S_00cde450_UShortArr *)(this), 2);
        unsigned short* p = m_data + m_iElementCount;
        for (int k = 0; k < 1; k++)
            p[k] = v;
        m_iElementCount++;
    }
};

struct S_00cde450_ByteArr
{
    char* m_data;
    int m_iElementCount;
    int m_cap;
    char* m_pTrailingData;
};

static __forceinline void S_00cde450_SetSize(S_00cde450_ByteArr& a, int n)
{
    int diff = n - a.m_iElementCount;
    char* p = a.m_data + a.m_iElementCount;
    if (diff <= 0)
    {
        a.m_iElementCount = n;
        return;
    }
    std::memset(p, 0, diff);
    a.m_iElementCount = n;
}

struct S_00cde450_Graph
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short* parent;
    int unk10;
    int unk14;
    int unk18;
    int count;
};

// @fnv 0x00cde450
void __cdecl CollectReachableNodes(S_00cde450_Graph* g, short asStartIndex, S_00cde450_UShortArr* pOutList,
                                   bool abIncludeStart)
{
    int iNodeCount = g->count;
    S_00cde450_ByteArr bits;
    bits.m_data = 0;
    bits.m_iElementCount = 0;
    bits.m_cap = 0x80000000;
    {
        S_00cde450_Router* r = FUN_00c85750();
        char* top = r->m_fMinimumV;
        r->m_fMinimumV = top + ((iNodeCount + 0x7f) & ~0x7f);
        bits.m_cap = iNodeCount | 0x80000000;
        bits.m_data = top;
        bits.m_pTrailingData = top;
    }
    int n = g->count;
    {
        S_00cde450_Heap& h = FUN_00c85750()->heap();
        int c = bits.m_cap & 0x3fffffff;
        if (c < n)
            ::FUN_00c908c0((::SpawnedObject *)&(h), (::SpawnedArray *)(::fnv_00cde450::S_00cde450_ByteArr *)(&bits), (n < c * 2) ? c * 2 : n, 1);
    }
    S_00cde450_SetSize(bits, n);

    if (abIncludeStart)
        pOutList->AddBack(asStartIndex);
    bits.m_data[asStartIndex] = 1;
    short i = (unsigned short)(asStartIndex + 1);
    for (; i < g->count; i++)
    {
        short p = g->parent[i];
        if (p != -1 && bits.m_data[p])
        {
            bits.m_data[i] = 1;
            pOutList->AddBack(i);
        }
    }

    char* pAllocBase = bits.m_pTrailingData;
    if (pAllocBase == bits.m_data)
        bits.m_iElementCount = 0;
    FUN_00c85750()->m_fMinimumV = pAllocBase;
    S_00cde450_Heap& h2 = FUN_00c85750()->heap();
    bits.m_iElementCount = 0;
    if ((bits.m_cap & 0x80000000) == 0)
        h2.ReturnMemory(bits.m_data, bits.m_cap & 0x3fffffff);
}
}  // namespace fnv_00cde450


#include "fnv/symbols_simd.h"

struct __declspec(align(16)) V4
{
    __m128 q;
};
// For each of count entries, calls FUN_00cde740 on 0x30-byte slots at idx[i]*0x30 offsets in b1, b2, b3, passing w as a float vector.
// @fnv 0x00cdd550
void __cdecl FUN_00cdd550(unsigned int count, const short* idx, char* b1, char* b2, float w, char* b3)
{
    V4 v;
    v.q = _mm_load_ss(&w);
    for (unsigned int i = 0; i < count; i++)
    {
        int off = idx[i] * 0x30;
        ::FUN_00cde740((const ::PoseBlend *)(void *)(b1 + off), (const ::PoseBlend *)(void *)(b2 + off), (const ::Vec4f *)(::V4 *)(&v), (::PoseBlend *)(void *)(b3 + off));
    }
}


struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4& b) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, b.m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    }
    __forceinline void setMul4(__m128 r, const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(r, v.m_vComponents);
    }
    __forceinline void addMul4(__m128 r, const hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r, v.m_vComponents));
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void SetRotatedDirection(const hkVector4& quat, const hkVector4& direction)
    {
        const hkVector4& imag = quat;
        const __m128 qreal = _mm_shuffle_ps(quat.m_vComponents, quat.m_vComponents, 0xff);
        const __m128 q2minus1 = _mm_add_ps(_mm_mul_ps(qreal, qreal), DAT_010c71e0);
        hkVector4 ret;
        ret.setMul4(q2minus1, direction);
        const __m128 imagDotDir = imag.dot3(direction);
        ret.addMul4(_mm_shuffle_ps(imagDotDir, imagDotDir, 0), imag);
        hkVector4 imagCrossDir;
        imagCrossDir.setCross(imag, direction);
        ret.addMul4(qreal, imagCrossDir);
        setAdd4(ret, ret);
    }
    __forceinline void SetTransformedPoint(const struct hkQsTransform& t, const hkVector4& v);
    __forceinline hkVector4& operator=(const hkVector4& o)
    {
        m_vComponents = o.m_vComponents;
        return *this;
    }
    __forceinline void add4(const hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
};

struct hkQsTransform
{
    hkVector4 m_vTranslation;
    hkVector4 m_rotation;
    hkVector4 m_vScale;
};

__forceinline void hkVector4::SetTransformedPoint(const hkQsTransform& t, const hkVector4& v)
{
    SetRotatedDirection(t.m_rotation, v);
    add4(t.m_vTranslation);
}

typedef short hkInt16;

struct hkaBone
{
    const char* m_name;
    bool m_bLockTranslation;
};

struct hkaSkeleton
{
    void* vtbl;
    int m_usMemSizeAndFlags;
    const char* m_name;
    short* m_kParentIndices;
    int m_numParentIndices;
    int m_parentCap;
    hkaBone* m_kBones;
    int m_iBoneCount;
    int m_bonesCap;
    hkQsTransform* m_kReferencePose;
};

// For each bone with m_bLockTranslation, sets poseModel translation from the reference pose, rotated and offset by the parent's transform when a parent exists.
// @fnv 0x00cde1d0
void __cdecl FUN_00cde1d0(const hkaSkeleton* skeleton, hkQsTransform* poseModel)
{
    const int numBones = skeleton->m_iBoneCount;
    for (int i = 0; i < numBones; i++)
    {
        const short parent = skeleton->m_kParentIndices[i];
        if (skeleton->m_kBones[i].m_bLockTranslation)
        {
            const hkVector4& refTranslation = skeleton->m_kReferencePose[i].m_vTranslation;
            hkQsTransform& out = poseModel[i];
            if (parent != -1)
            {
                const hkQsTransform& p = poseModel[parent];
                out.m_vTranslation.SetRotatedDirection(p.m_rotation, refTranslation);
                poseModel[i].m_vTranslation.add4(p.m_vTranslation);
            }
            else
            {
                poseModel[i].m_vTranslation.m_vComponents = refTranslation.m_vComponents;
            }
        }
    }
}


extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern char DAT_010cb7dc[];

struct TimerEntry
{
    const char* tag;
    unsigned int stamp;
    unsigned int unk08;
};
struct Monitor
{
    int unk00;
    TimerEntry* current;
    int unk08;
    TimerEntry* end;
};
static __forceinline void timer(const char* tag)
{
    Monitor* monitor = static_cast<Monitor*>(TlsGetValue(DAT_0126835c));
    TimerEntry* entry = monitor->current;
    if (entry < monitor->end)
    {
        entry->tag = tag;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        entry->stamp = stamp;
        monitor->current = entry + 1;
    }
}

struct HkObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void Begin();
};
struct HkEntity
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int owner;
};
struct HkWorld
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
    virtual HkEntity* GetEntity();
};
struct Vec4
{
    float x;
    float y;
    float z;
    float w;
};
union __declspec(align(16)) VectorValue
{
    Vec4 scalar;
    __m128 quad;
};
struct Allocator
{
    virtual void v00();
    virtual void* Allocate(unsigned int);
};
struct AllocationService
{
    int unk00, unk04, unk08, unk0c;
    Allocator* volatile allocator;
};
struct Property
{
    unsigned short type, unk02;
    int unk04, unk08, unk0c;
    unsigned short size, unk12;
    int unk14, unk18, unk1c;
    __m128 vector;
    static void* operator new(std::size_t bytes)
    {
        AllocationService* service = reinterpret_cast<AllocationService*>(FUN_00c85750());
        return service->allocator->Allocate(bytes);
    }
    Property()
    {
        type = 0x1a;
        size = 0x30;
    }
};

// Stores a Vec4 into a Property's vector field on an HkEntity, XORing it with DAT_010c44d0 when the entity's owner matches the given owner.
// @fnv 0x00cdfcd0
void SetModifierConstraint(HkWorld* apWorld, int owner, HkObj* apObj, Vec4* apVec)
{
    HkEntity* e = apWorld->GetEntity();
    if (e)
    {
        apObj->Begin();
        timer(DAT_010cb7dc);
        VectorValue t;
        t.scalar = *apVec;
        if (e->owner == owner)
        {
            t.quad = _mm_xor_ps(t.quad, ::DAT_010c44d0);
        }
        Property* p = ((::Property *)(::FindModifierConstraintAtom((::hkpConstraintInstance *)(e), 0x1a)));
        if (p)
        {
            p->vector = t.quad;
        }
        else
        {
            p = new Property;
            p->vector = t.quad;
            ::FUN_00d27960((::hkpConstraintInstance *)(e), (*(::hkpConstraintOwner *)(apObj)), (::hkpModifierConstraintAtom *)(p));
        }
        timer(DAT_010c41f8);
    }
}

struct S_00cdd600_Obj
{
    int unk00;
    int unk04;
    int unk08;
    short* m0c;
};
struct S_00cdd600_Bone
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float scale[4];
};

struct S_00cdd600_Out
{
    __m128* p;
    __m128* val() const
    {
        return p;
    }
};
// Multiplies the scale vectors of a chain of bones starting at idx into r, then stores the result in out.
// @fnv 0x00cdd600
void __cdecl MultiplyBoneScales(S_00cdd600_Obj* obj, S_00cdd600_Bone* bones, int aiStartIndex, S_00cdd600_Out out)
{
    __m128 r = DAT_010c7170;
    for (; aiStartIndex != -1; aiStartIndex = obj->m0c[aiStartIndex])
        r = _mm_mul_ps(*(__m128*)bones[aiStartIndex].scale, r);
    *out.val() = r;
}

extern "C"
{


    void _ReadWriteBarrier(void);
}


struct Simd
{
    __m128 m;
    __forceinline float getReal() const
    {
        float f;
        _mm_store_ss(&f, m);
        return f;
    }
};
struct Vec
{
    __m128 m;
    __forceinline Simd lengthSquared() const
    {
        __m128 d = _mm_mul_ps(m, m);
        __m128 s = _mm_add_ps(d, _mm_shuffle_ps(d, d, 0x4e));
        Simd r;
        r.m = _mm_add_ps(s, _mm_shuffle_ps(s, s, 0xb1));
        return r;
    }
    __forceinline void mul(const Simd& factor)
    {
        m = _mm_mul_ps(_mm_shuffle_ps(factor.m, factor.m, 0), m);
    }
    __forceinline void SetProduct(const Simd& factor, const Vec& v)
    {
        m = _mm_mul_ps(factor.m, v.m);
    }
};
struct Item
{
    Vec translation;
    Vec rot;
    Vec scale;
};

// Normalizes the rot vectors of up to count Item entries in batches of four using SIMD, then handles any remaining items individually.
// @fnv 0x00cdd660
void FUN_00cdd660(Item* items, int count)
{
    int blocks = count / 4;
    if ((unsigned int)blocks > 0)
    {
        float a[4];
        float d3[4];
        do
        {
            Simd sq0 = items[0].rot.lengthSquared();
            _mm_store_ss(&a[0], sq0.m);
            d3[0] = a[0];
            Simd sq1 = items[1].rot.lengthSquared();
            _mm_store_ss(&a[1], sq1.m);
            d3[1] = a[1];
            Simd sq2 = items[2].rot.lengthSquared();
            _mm_store_ss(&a[2], sq2.m);
            d3[2] = a[2];
            Simd sq3 = items[3].rot.lengthSquared();
            _mm_store_ss(&a[3], sq3.m);
            d3[3] = a[3];

            __m128 len = _mm_load_ps(d3);
            __m128 x = _mm_rsqrt_ps(len);
            __m128 r2 = _mm_mul_ps(x, len);
            r2 = _mm_mul_ps(r2, x);
            __m128 sub;
            sub = _mm_sub_ps(::DAT_010c71c0, r2);
            __m128 j = _mm_mul_ps(::DAT_010c71d0, x);
            __m128 factor = _mm_mul_ps(sub, j);

            Simd sc0;
            sc0.m = factor;
            items[0].rot.mul(sc0);
            Simd sc1;
            sc1.m = _mm_shuffle_ps(factor, factor, 0x55);
            items[1].rot.mul(sc1);
            Simd sc2;
            sc2.m = _mm_shuffle_ps(factor, factor, 0xaa);
            __m128 res2 = _mm_mul_ps(_mm_shuffle_ps(sc2.m, sc2.m, 0), items[2].rot.m);
            Simd sc3;
            sc3.m = _mm_shuffle_ps(factor, factor, 0xff);
            items[2].rot.m = res2;
            _ReadWriteBarrier();
            items[3].rot.mul(sc3);
            _ReadWriteBarrier();

            items += 4;
        } while (--blocks);
    }

    int iRemainder = count % 4;
    if (iRemainder)
    {
        __m128 pObj = _mm_set_ss(0.0f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 half = _mm_set_ss(0.5f);
        __m128* p = &items->rot.m;
        int remaining = iRemainder;
        do
        {
            __m128 v;
            v = *p;
            __m128 d = _mm_mul_ps(v, v);
            __m128 s = _mm_add_ps(d, _mm_shuffle_ps(d, d, 0x4e));
            s = _mm_add_ps(s, _mm_shuffle_ps(s, s, 0xb1));

            __m128 r = _mm_rsqrt_ss(s);
            __m128 r2 = _mm_mul_ss(s, r);
            r2 = _mm_mul_ss(r2, r);
            __m128 j;
            j = _mm_mul_ss(half, r);
            __m128 sub = _mm_sub_ss(three, r2);
            __m128 factor = _mm_mul_ss(j, sub);

            __m128 zero = _mm_cmpeq_ss(s, pObj);
            factor = _mm_andnot_ps(zero, factor);
            __m128 d2 = _mm_shuffle_ps(factor, factor, 0x00);
            *p = _mm_mul_ps(d2, v);
            p = &(++items)->rot.m;
        } while (--remaining);
    }
}


class SReal
{
  public:
    SReal()
    {}
    SReal(const __m128& x) : m_vValue(x)
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

__forceinline __m128 approxReciprocal(__m128 r)
{
    __m128 e = _mm_rcp_ps(r);
    return _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, r), e));
}

struct QRot;

class QVec
{
  public:
    QVec()
    {}
    QVec(const __m128& q)
    {
        m_vComponents = q;
    }
    QVec(const QVec& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const QVec& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const __m128& q)
    {
        getQuad() = q;
    }
    operator __m128() const
    {
        return m_vComponents;
    }
    __m128& getQuad()
    {
        return m_vComponents;
    }
    const __m128& getQuad() const
    {
        return m_vComponents;
    }

    __forceinline void setAdd4(const QVec& a, const QVec& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const QVec& a, const QVec& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAddMul4(const QVec& a, const QVec& x, const QVec& y)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void addMul4(const QVec& x, const QVec& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void addMul4(const SReal& r, const QVec& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
    }
    __forceinline void sub4(const QVec& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void SetAllComponents(const SReal& r)
    {
        m_vComponents = _mm_shuffle_ps(r.getQuad(), r.getQuad(), 0x00);
    }
    __forceinline SReal lane(int i) const
    {
        switch (i)
        {
        case 0:
            return m_vComponents;
        case 1:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        case 3:
        default:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline void setNeg4(const QVec& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, ::DAT_010c44d0);
    }
    __forceinline void setNeg3(const QVec& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, *(const __m128*)&(*reinterpret_cast<const unsigned int (*)[4]>(&::DAT_010c4c00)));
    }
    __forceinline void setXYZ0(const QVec& xyz)
    {
        m_vComponents = _mm_and_ps(xyz, *(const __m128*)&(*reinterpret_cast<const unsigned int (*)[4]>(&::DAT_010c4c10)));
    }
    __forceinline void setXYZW(const QVec& xyz, const QVec& w)
    {
        m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, w.m_vComponents), 0xc4);
    }
    __forceinline void setReciprocal4(const QVec& v)
    {
        m_vComponents = approxReciprocal(v.m_vComponents);
    }
    __forceinline void setReciprocal3(const QVec& v)
    {
        QVec ones;
        ones.getQuad() = DAT_010c7170;
        QVec padded;
        padded.setXYZW(v, ones);
        setReciprocal4(padded);
    }
    __forceinline void setCross(const QVec& a, const QVec& b)
    {
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    __forceinline SReal dot3(const QVec& a) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    __forceinline void splat(int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x00);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        else if (i == 3)
            m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    __forceinline void setSplat(const QVec& v, int i)
    {
        if (i == 0)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        else if (i == 1)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        else if (i == 3)
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    void rotate(const QRot& q, const QVec& d);
    void rotateInverse(const QRot& q, const QVec& d);

  private:
    __m128 m_vComponents;
};

struct QRot
{
    QVec m_vec;
    __forceinline const QVec& imag() const
    {
        return m_vec;
    }
    __forceinline void SetConjugate(const QRot& q)
    {
        m_vec.setNeg3(q.imag());
    }
    inline void SetProduct(const QRot& a, const QRot& b);
};

inline void QRot::SetProduct(const QRot& a, const QRot& b)
{
    QVec v;
    v.setCross(a.imag(), b.imag());
    v.addMul4(a.m_vec.lane(3), b.imag());
    v.addMul4(b.m_vec.lane(3), a.imag());
    QVec d;
    d.SetAllComponents(a.m_vec.dot3(b.m_vec));
    QVec w;
    w.setMul4(a.m_vec, b.m_vec);
    w.sub4(d);
    m_vec.setXYZW(v, w);
}

__forceinline void QVec::rotate(const QRot& q, const QVec& d)
{
    QVec half;
    half.getQuad() = DAT_010c71e0;
    QVec w;
    w.setSplat(q.m_vec, 3);
    QVec w2;
    w2.setAddMul4(half, w, w);
    QVec out;
    out.setMul4(d, w2);
    QVec dp;
    dp.getQuad() = q.imag().dot3(d).getQuad();
    dp.splat(0);
    out.addMul4(dp, q.imag());
    QVec cr;
    cr.setCross(q.imag(), d);
    out.addMul4(w, cr);
    setAdd4(out, out);
}

__forceinline void QVec::rotateInverse(const QRot& q, const QVec& d)
{
    QVec half;
    half.getQuad() = DAT_010c71e0;
    QVec w;
    w.setSplat(q.m_vec, 3);
    QVec w2;
    w2.setAddMul4(half, w, w);
    QVec out;
    out.setMul4(d, w2);
    QVec dp;
    dp.getQuad() = q.imag().dot3(d).getQuad();
    dp.splat(0);
    out.addMul4(dp, q.imag());
    QVec cr;
    cr.setCross(d, q.imag());
    out.addMul4(w, cr);
    setAdd4(out, out);
}

struct QsXform
{
    QVec m_vTranslation;
    QRot m_rotation;
    QVec m_vScale;

    QsXform()
    {}

    __forceinline void SetConjugate(const QsXform& t)
    {
        m_vTranslation.rotateInverse(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        QVec inv;
        inv.setReciprocal3(t.m_vScale);
        m_vScale.setXYZ0(inv);
    }

    __forceinline void SetProduct(const QsXform& ab, const QsXform& bc)
    {
        QVec moved;
        moved.rotate(ab.m_rotation, bc.m_vTranslation);
        m_vTranslation.setAdd4(ab.m_vTranslation, moved);
        ::fnv_00c66320::FUN_00c66320((__m128 *)&(m_rotation), (void *)&(ab.m_rotation), (const __m128 *)&(bc.m_rotation), {});
        m_vScale.setMul4(ab.m_vScale, bc.m_vScale);
    }

    __forceinline void SetMulInverse(const QsXform& a, const QsXform& b)
    {
        QsXform inv;
        inv.SetConjugate(a);
        SetProduct(inv, b);
    }
};

__forceinline void toLocal(int count, const short* parents, const QsXform& root, const QsXform* world,
                           QsXform* localOut)
{
    for (int i = 0; i < count; i++)
    {
        const int p = parents[i];
        const QsXform& parentWorld = (p != -1) ? world[p] : root;
        localOut[i].SetMulInverse(parentWorld, world[i]);
    }
}

// Converts world-space QsXform transforms to local-space by calling toLocal with the given count, parents, root, world, and localOut arguments.
// @fnv 0x00cddd20
extern "C" void __cdecl FUN_00cddd20(void* aiCount, void* apParents, void* apRoot, void* apWorld, void* apLocalOut)
{
    toLocal((int)aiCount, (const short*)apParents, *(const QsXform*)apRoot, (const QsXform*)apWorld,
            (QsXform*)apLocalOut);
}
// ---------------------------------------------------------------------------
// FUN_00cdd480 - batch interpolation of 0x30 byte records.
//
//   arg1  number of records to process (compared unsigned)
//   arg2  first  record array   (0x30 byte stride)
//   arg3  second record array   (0x30 byte stride)
//   arg4  array of blend factors (float, one per record)
//   arg5  output record array   (0x30 byte stride)
//
// For every record the blend factor is put into a 16 byte, 16 byte aligned
// vector whose first component carries the factor; that vector is handed to
// FUN_00cde740, which broadcasts its first component and interpolates the
// three 4 x float blocks of the two 0x30 byte records into the output.
//
// The original code of this module was built with /GS- and with SSE code
// generation for scalar floats, so the vector is written through a plain
// 16 byte structure here: a __m128 local whose address is taken makes MSVC
// 2008 add a /GS stack cookie that the original does not have.
// ---------------------------------------------------------------------------

// The 16 byte vector that is passed to FUN_00cde740: the blend factor in
// component 0, the remaining components are zero.
struct __declspec(align(16)) FUN_00cde740_v4
{
    float x, y, z, w;
};

// One 0x30 byte record: three blocks of four floats.
struct FUN_00cde740_v
{
    float a0, a1, a2, a3;
    float b0, b1, b2, b3;
    float c0, c1, c2, c3;
};


// @fnv 0x00cdd480
void FUN_00cdd480(unsigned count, FUN_00cde740_v* a, FUN_00cde740_v* b, float* c, FUN_00cde740_v* d)
{
    for (unsigned i = 0; i < count; i++)
    {
        FUN_00cde740_v4 t;
        _mm_store_ps((float*)&t, _mm_load_ss(&c[i]));
        ::FUN_00cde740((const ::PoseBlend *)(::FUN_00cde740_v *)(a + i), (const ::PoseBlend *)(::FUN_00cde740_v *)(b + i), (const ::Vec4f *)(void *)(&t), (::PoseBlend *)(::FUN_00cde740_v *)(d + i));
    }
}

struct __declspec(align(16)) S_00cdd4f0_Vec
{
    float x, y, z, w;
};
// @fnv 0x00cdd4f0
void __cdecl FUN_00cdd4f0(unsigned int n, char* a, char* b, float f, char* c)
{
    S_00cdd4f0_Vec s;
    *(__m128*)&s = _mm_load_ss(&f);
    for (unsigned int i = 0; i < n; i++)
        ::FUN_00cde740((const ::PoseBlend *)(void *)(a + i * 48), (const ::PoseBlend *)(void *)(b + i * 48), (const ::Vec4f *)(::S_00cdd4f0_Vec *)(&s), (::PoseBlend *)(void *)(c + i * 48));
}


class hkQuaternionDAD;

class __declspec(align(16)) hkVector4DAD
{
  public:
    __forceinline void SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction);
    __forceinline void setAdd4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setCross(const hkVector4DAD& v1, const hkVector4DAD& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setBroadcast3(const hkVector4DAD& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline __m128 dot3(const hkVector4DAD& v) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }

    __m128 m_vComponents;
};

class hkQuaternionDAD
{
  public:
      // SetProduct
    const hkVector4DAD& getImag() const
    {
        return m_vec;
    }

    hkVector4DAD m_vec;
};

__forceinline void hkVector4DAD::SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction)
{
    hkVector4DAD qreal;
    qreal.setBroadcast3(quat.m_vec);
    hkVector4DAD q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);
    hkVector4DAD ret;
    ret.setMul4(q2minus1, direction);
    hkVector4DAD imagDotDir;
    imagDotDir.m_vComponents = quat.getImag().dot3(direction);
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4DAD imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

class hkQsTransformDAD
{
  public:
    __forceinline void SetProduct(const hkQsTransformDAD& t1, const hkQsTransformDAD& t2)
    {
        hkVector4DAD temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((__m128 *)&(m_rotation), (void *)&(t1.m_rotation), (const __m128 *)&(t2.m_rotation), {});
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }

    hkVector4DAD m_vTranslation;
    hkQuaternionDAD m_rotation;
    hkVector4DAD m_vScale;
};

// @fnv 0x00cddad0
extern "C" void __cdecl FUN_00cddad0(int numTransforms, int parentIndicesIn, int* worldFromModelIn, int poseLocalIn,
                                     int poseModelIn)
{
    for (int i = 0; i < numTransforms; i++)
    {
        const int parentId = ((const short*)parentIndicesIn)[i];
        const hkQsTransformDAD& worldFromParent = (-1 != parentId) ? ((hkQsTransformDAD*)poseModelIn)[parentId]
                                                                   : (*(const hkQsTransformDAD*)worldFromModelIn);
        ((hkQsTransformDAD*)poseModelIn)[i].SetProduct(worldFromParent, ((const hkQsTransformDAD*)poseLocalIn)[i]);
    }
}

namespace fnv_00cddbf0 {

class hkQuaternionDAD;

class __declspec(align(16)) hkVector4DAD
{
  public:
    __forceinline void SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction);
    inline hkVector4DAD& operator=(const hkVector4DAD& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void setAdd4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setCross(const hkVector4DAD& v1, const hkVector4DAD& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setBroadcast3(const hkVector4DAD& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline __m128 dot3(const hkVector4DAD& v) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }

    __m128 m_vComponents;
};

class hkQuaternionDAD
{
  public:
      // SetProduct
    const hkVector4DAD& getImag() const
    {
        return m_vec;
    }

    hkVector4DAD m_vec;
};

__forceinline void hkVector4DAD::SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction)
{
    hkVector4DAD qreal;
    qreal.setBroadcast3(quat.m_vec);
    hkVector4DAD q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), ::DAT_010c71e0);
    hkVector4DAD ret;
    ret.setMul4(q2minus1, direction);
    hkVector4DAD imagDotDir;
    imagDotDir.m_vComponents = quat.getImag().dot3(direction);
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4DAD imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

class hkQsTransformDAD
{
  public:
    __forceinline void SetProduct(const hkQsTransformDAD& t1, const hkQsTransformDAD& t2)
    {
        hkVector4DAD temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((__m128 *)&(m_rotation), (void *)&(t1.m_rotation), (const __m128 *)&(t2.m_rotation), {});
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }

    hkVector4DAD m_vTranslation;
    hkQuaternionDAD m_rotation;
    hkVector4DAD m_vScale;
};

// @fnv 0x00cddbf0
void __cdecl FUN_00cddbf0(int boneIndex, const short* parentIndices, const hkQsTransformDAD* poseLocal,
                          hkQsTransformDAD& poseModelOut)
{
    poseModelOut = poseLocal[boneIndex];
    for (int parentId = parentIndices[boneIndex]; parentId >= 0; parentId = parentIndices[parentId])
    {
        poseModelOut.SetProduct(poseLocal[parentId], poseModelOut);
    }
}
}  // namespace fnv_00cddbf0

namespace fnv_00cddf20 {

class hkQuaternionDAD;

class __declspec(align(16)) hkVector4DAD
{
  public:
    __forceinline void SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction);
    inline hkVector4DAD& operator=(const hkVector4DAD& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void setAdd4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setCross(const hkVector4DAD& v1, const hkVector4DAD& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setBroadcast3(const hkVector4DAD& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline __m128 dot3(const hkVector4DAD& v) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }

    __m128 m_vComponents;
};

class hkQuaternionDAD
{
  public:
      // SetProduct
    const hkVector4DAD& getImag() const
    {
        return m_vec;
    }

    hkVector4DAD m_vec;
};

__forceinline void hkVector4DAD::SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction)
{
    hkVector4DAD qreal;
    qreal.setBroadcast3(quat.m_vec);
    hkVector4DAD q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), ::DAT_010c71e0);
    hkVector4DAD ret;
    ret.setMul4(q2minus1, direction);
    hkVector4DAD imagDotDir;
    imagDotDir.m_vComponents = quat.getImag().dot3(direction);
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4DAD imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

class hkQsTransformDAD
{
  public:
    __forceinline void SetProduct(const hkQsTransformDAD& t1, const hkQsTransformDAD& t2)
    {
        hkVector4DAD temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((__m128 *)&(m_rotation), (void *)&(t1.m_rotation), (const __m128 *)&(t2.m_rotation), {});
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }

    hkVector4DAD m_vTranslation;
    hkQuaternionDAD m_rotation;
    hkVector4DAD m_vScale;
};

// @fnv 0x00cddf20
void __cdecl FUN_00cddf20(int numTransforms, const hkQsTransformDAD& transform, const hkQsTransformDAD* transformsIn,
                          hkQsTransformDAD* transformsOut)
{
    for (int i = 0; i < numTransforms; i++)
    {
        transformsOut[i].SetProduct(transform, transformsIn[i]);
    }
}
}  // namespace fnv_00cddf20

namespace fnv_00cde010 {

class hkQuaternionCDE;

class hkVector4CDE
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4CDE& operator=(const hkVector4CDE& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4CDE& a, const hkVector4CDE& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4CDE& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4CDE& a, const hkVector4CDE& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4CDE& a, const hkVector4CDE& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4CDE& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4CDE& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, ::DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4CDE& v1, const hkVector4CDE& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4CDE& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4CDE& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionCDE& q, const hkVector4CDE& dir);
    void setRotatedInverseDir(const hkQuaternionCDE& q, const hkVector4CDE& dir);
};

class hkQuaternionCDE
{
  public:
    hkVector4CDE m_vec;

    __forceinline void SetConjugate(const hkQuaternionCDE& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(::DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionCDE& q0, const hkQuaternionCDE& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

__forceinline void hkVector4CDE::SetRotatedDirection(const hkQuaternionCDE& quat, const hkVector4CDE& direction)
{
    hkVector4CDE qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4CDE q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, ::DAT_010c71e0);
    hkVector4CDE ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CDE imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4CDE::setRotatedInverseDir(const hkQuaternionCDE& quat, const hkVector4CDE& direction)
{
    hkVector4CDE qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4CDE q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, ::DAT_010c71e0);
    hkVector4CDE ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CDE imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformCDE
{
  public:
    hkVector4CDE m_vTranslation;
    hkQuaternionCDE m_rotation;
    hkVector4CDE m_vScale;

    __forceinline void SetConjugate(const hkQsTransformCDE& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4CDE s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, ::DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, ::DAT_010c4c10);
    }
    __forceinline void SetProduct(const hkQsTransformCDE& t1, const hkQsTransformCDE& t2)
    {
        hkVector4CDE temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((__m128 *)&(m_rotation), (void *)&(t1.m_rotation), (const __m128 *)&(t2.m_rotation), {});
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
    __forceinline void SetMulInverse(const hkQsTransformCDE& a, const hkQsTransformCDE& b)
    {
        hkQsTransformCDE h;
        h.SetConjugate(a);
        SetProduct(h, b);
    }
};

// @fnv 0x00cde010
void __cdecl FUN_00cde010(int iCount, const hkQsTransformCDE& kA, const hkQsTransformCDE* pkB, hkQsTransformCDE* pkOut)
{
    for (int i = 0; i < iCount; i++)
        pkOut[i].SetMulInverse(kA, pkB[i]);
}
}  // namespace fnv_00cde010

__declspec(align(16)) struct Vec4f
{
    float x;
    float y;
    float z;
    float w;
};

struct PoseBlend
{
    Vec4f pos;
    Vec4f rot;
    Vec4f scale;
};

extern const float DAT_01012054 = -1.0f;
extern const float DAT_0104da4c = 1.192092896e-07f;

static __m128 ld(const Vec4f& v)
{
    return _mm_load_ps(&v.x);
}

static void st(Vec4f& v, __m128 m)
{
    _mm_store_ps(&v.x, m);
}

static __m128 hsum4(__m128 p)
{
    __m128 h = _mm_add_ps(p, _mm_shuffle_ps(p, p, 0x4e));
    return _mm_add_ps(h, _mm_shuffle_ps(h, h, 0xb1));
}

static __forceinline __m128 blend(__m128 a, __m128 b, const Vec4f* tp)
{
    __m128 t = _mm_shuffle_ps(ld(*tp), ld(*tp), 0);
    __m128 omt = _mm_sub_ps(::DAT_010ec7f0, t);
    return _mm_add_ps(_mm_mul_ps(omt, a), _mm_mul_ps(b, t));
}
// @fnv 0x00cde740
void __cdecl FUN_00cde740(const PoseBlend* a, const PoseBlend* b, const Vec4f* tp, PoseBlend* out)
{
    st(out->pos, blend(ld(a->pos), ld(b->pos), tp));
    float dot;
    _mm_store_ss(&dot,
                 hsum4(_mm_mul_ps(reinterpret_cast<const __m128&>(a->rot), reinterpret_cast<const __m128&>(b->rot))));
    Vec4f qb = b->rot;
    __m128 vQuaternionSign;
    if (dot < 0.0f)
    {
        __m128 neg = _mm_load_ss(&DAT_01012054);
        neg = _mm_shuffle_ps(neg, neg, 0);
        vQuaternionSign = _mm_mul_ps(neg, ld(qb));
    }
    else
    {
        vQuaternionSign = ld(qb);
    }
    st(out->rot, blend(ld(a->rot), vQuaternionSign, tp));
    st(out->scale, blend(ld(a->scale), ld(b->scale), tp));
    _mm_store_ss(&dot, hsum4(_mm_mul_ps(ld(out->rot), ld(out->rot))));
    if (dot < DAT_0104da4c)
    {
        st(out->rot, ::DAT_010c71b0);
    }
    else
    {
        reinterpret_cast<::FUN_005611c0_t *>(&(out->rot))->FUN_005611c0();
    }
}

struct SkinFlagEntry
{
    int unk00;
    unsigned char m_bEnableState;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
};

struct SkinXformSet
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short* m_pIndices;
    int unk10;
    int unk14;
    SkinFlagEntry* m_pFlags;
    int m_uiItemCount;
};

struct SkinXformEntry
{
    __m128 v0;
    __m128 v1;
    __m128 v2;
};

// @fnv 0x00cde2d0
void __cdecl FUN_00cde2d0(SkinXformSet* set, const SkinXformEntry* input, SkinXformEntry* output)
{
    int count = set->m_uiItemCount;
    for (int index = 0; index < count; ++index)
    {
        short parent = (short)set->m_pIndices[index];
        SkinXformEntry& destination = output[index];
        if (set->m_pFlags[index].m_bEnableState)
        {
            if (parent != -1)
            {
                SkinXformEntry* parentEntry = output + parent;
                __m128 r = rotate(input[index].v0, parentEntry->v1);
                destination.v0 = _mm_add_ps(r, parentEntry->v0);
            }
            else
            {
                destination.v0 = input[index].v0;
            }
        }
    }
}

#include "generated/data/havok/animation/animation/rig/hkaskeletonutils.inc"
