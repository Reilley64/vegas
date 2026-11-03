
// src/havok/physics/internal/collide/mopp/builder/mediator/cachedshape/hkpmoppcachedshapemediator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/mediator/cachedshape/hkpmoppcachedshapemediator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dd55d0
#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d54000.h"
int InitIntToZero(int, int* piValue)
{
    *piValue = 0;
    return 1;
}

// Copies five pointer-sized values from src to dst at offsets 0, 4, 8, 0xc and 0x10.
// @fnv 0x00dd5630
void CopyFivePointers(const void* apSource, void* apUnused1, void* apUnused2, void* apUnused3, void* apDest)
{
    *(void**)apDest = *(void**)apSource;
    *(void**)((char*)apDest + 4) = *(void**)((char*)apSource + 4);
    *(void**)((char*)apDest + 8) = *(void**)((char*)apSource + 8);
    *(void**)((char*)apDest + 0xc) = *(void**)((char*)apSource + 0xc);
    *(void**)((char*)apDest + 0x10) = *(void**)((char*)apSource + 0x10);
}

struct S_00d54cd0_Base
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct S_00d54cd0_All : S_00d54cd0_Base
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    void* unk14;
    int unk18;
    S_00d54cd0_All(void* world) throw();
    ~S_00d54cd0_All() throw();
};
struct S_00d54cd0_Closest : S_00d54cd0_Base
{
    void* unk8;
    int unkC;
    S_00d54cd0_Closest(void* world) throw();
    ~S_00d54cd0_Closest() throw();
};
struct S_00d54cd0_Input
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    char unk1C;
    char unk1D;
    char unk1E;
    char unk1F;
    char unk20;
};
struct S_00d54cd0_Result
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    bool unk2C;
};
// @fnv 0x00d54cd0
S_00d54cd0_Result* FUN_00d54cd0(void* world, S_00d54cd0_Input* pInput, void* out)
{
    S_00d54cd0_Result* r;
    if (pInput->unk20)
    {
        S_00d54cd0_All col(world);
        r = ((::S_00d54cd0_Result *)(::FUN_00d54a40(&col, world, (::Arg2Struct *)(pInput), (::SearchObject *)(out))));
    }
    else
    {
        S_00d54cd0_Closest col(world);
        r = ((::S_00d54cd0_Result *)(::FUN_00d54a40(&col, world, (::Arg2Struct *)(pInput), (::SearchObject *)(out))));
    }
    r->unk2C = pInput->unk1E == 0;
    return r;
}

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiBytes) throw();
};

struct AudioHolder
{
    char* unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

static inline AudioHolder* getMemoryRouter() { return static_cast<AudioHolder*>(::FUN_00c85750()); }

struct Record
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5c;
    int m_i60;
    int m_i64;
    int m_i68;
};

struct RecordArray
{
    Record* m_pRecords;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~RecordArray() throw()
    {
        AudioHolder* pHolder = getMemoryRouter();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->FreeArray(m_pRecords, (uCapacity & 0x3fffffff) * sizeof(Record));
        m_pRecords = 0;
        m_uCapacity = 0x80000000;
    }
};

struct RecordBase
{
    virtual void a00();
    int m_i04;

    virtual ~RecordBase() throw()
    {}
};

struct FUN_00dd5d90 : RecordBase
{
    RecordArray m_kArray;
    int m_iExtra;

    virtual ~FUN_00dd5d90() throw();
};

// Destructor that zeroes m_iExtra; the m_kArray member is destroyed afterwards by the compiler-generated code.
// @fnv 0x00dd5d90
FUN_00dd5d90::~FUN_00dd5d90() throw()
{
    m_iExtra = 0;
}

struct Item
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual bool v14();
};

struct Mgr
{
    virtual void v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c(int);
    virtual void v10();
    virtual Item* v14(int, int*);
};

class FUN_00dd5cd0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Mgr* m_pMgr;

    void ProcessItems(::Item_00dd5b00* a, int b);
};

class DD5D50ReferencedObject
{
  public:
    DD5D50ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct DD5D50Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    DD5D50Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct DD5D50Source
{
    virtual void unk00();
    virtual int getCount();
};

class FUN_00dd5d50 : public DD5D50ReferencedObject
{
  public:
    FUN_00dd5d50(DD5D50Source* source);
    virtual void unk00();

    DD5D50Array m_items;
    DD5D50Source* m_pObservedSource;
    int m_uiItemCount;
};

// @fnv 0x00dd5d50
FUN_00dd5d50::FUN_00dd5d50(DD5D50Source* source) : m_pObservedSource(source)
{
    m_uiItemCount = source->getCount();
}

struct FUN_00dd5660_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int FUN_00dd5660();
};

// @fnv 0x00dd5660
int FUN_00dd5660_cls::FUN_00dd5660()
{
    return unk18;
}


struct Vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct Vec4Bits
{
    unsigned int u0;
    unsigned int u1;
    unsigned int u2;
    unsigned int u3;
};


struct Src_00dd5b00
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
    virtual int v2c();
    virtual void v30(void* apDst);
};

struct Range_00dd5b00
{
    float m_fLo;
    float m_fHi;
};

struct Entry_00dd5b00
{
    int m_iOwnerObjectOffset;
    Range_00dd5b00 m_ranges[13];
};

struct Item_00dd5b00
{
    Vec4Bits m_kAxisEndPoints;
    Vec4Bits m_extra;
};

struct Vec_00dd5b00
{
    Entry_00dd5b00* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

struct Obj_00dd5b00
{
    int unk00;
    int unk04;
    Vec_00dd5b00 m_kNode;

    void ComputeAxisRanges(Src_00dd5b00* apSource, int aiId, Item_00dd5b00* apItems, int aiCount);
};
// Iterates count items from m_pMgr starting at m, calling ComputeAxisRanges on each item whose v14() is nonzero, advancing m via v0c.
// @fnv 0x00dd5cd0
void FUN_00dd5cd0_cls::ProcessItems(::Item_00dd5b00* aiArg1, int aiArg2)
{
    __declspec(align(16)) int slots[127];
    int i;
    int count = m_pMgr->v04();
    int m = m_pMgr->v08();
    if (count > 0)
    {
        i = count;
        do
        {
            Item* item = m_pMgr->v14(m, slots);
            if (item->v14())
            {
                reinterpret_cast<::Obj_00dd5b00 *>(this)->ComputeAxisRanges((::Src_00dd5b00 *)(item), m, aiArg1, aiArg2);
            }
            m = m_pMgr->v0c(m);
            i = i - 1;
        } while (i != 0);
    }
}

inline float Dot3_00dd5b00(const __m128& a, const __m128& b)
{
    __m128 m = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(m, m, 0x55);
    __m128 yx = _mm_add_ss(y, m);
    __m128 z = _mm_shuffle_ps(m, m, 0xaa);
    __m128 s = _mm_add_ss(z, yx);
    float f;
    _mm_store_ss(&f, s);
    return f;
}

// Fills scratch vectors from apSource, appends an entry, and stores each item's min and max of vertex dot product plus or minus w into that entry's ranges.
// @fnv 0x00dd5b00
void Obj_00dd5b00::ComputeAxisRanges(Src_00dd5b00* apSource, int aiId, Item_00dd5b00* apItems, int aiCount)
{
    int nVerts = apSource->v2c();
    AudioHolder* pHolder = getMemoryRouter();
    Vec4* m_pkDeltas = reinterpret_cast<Vec4*>(pHolder->unk00);
    pHolder->unk00 += (nVerts * sizeof(Vec4) + 0x7f) & ~0x7f;
    apSource->v30(m_pkDeltas);

    Vec_00dd5b00* pList = &m_kNode;
    AudioHolder* pGrow = getMemoryRouter();
    if (pList->m_iArrayLength == (int)(pList->m_uCapFlags & 0x3fffffff))
    {
        ::ResizeAudioStream(pGrow->m_pAllocator, (::AudioStream *)(pList), 0x6c);
    }
    Entry_00dd5b00* pEntry = &pList->m_pData[pList->m_iArrayLength++];
    pEntry->m_iOwnerObjectOffset = aiId;

    float zero = 0.0f;
    for (int i = 0; i < aiCount; i++)
    {
        int n = nVerts;
        float lo;
        float hi;
        if (n > 0)
        {
            float r = m_pkDeltas->w;
            __declspec(align(16)) Vec4Bits kBits;
            kBits = apItems[i].m_kAxisEndPoints;
            __m128 p = _mm_load_ps((const float*)&kBits);
            float fDot = Dot3_00dd5b00(_mm_load_ps((const float*)m_pkDeltas), p);
            lo = fDot - r;
            hi = fDot + r;
            if (n > 1)
            {
                Vec4* pv = m_pkDeltas + 1;
                n = n - 1;
                do
                {
                    r = pv->w;
                    float fDot2 = Dot3_00dd5b00(_mm_load_ps((const float*)pv), p);
                    float fLo2 = fDot2 - r;
                    float fHi2 = fDot2 + r;
                    if (fLo2 < lo)
                    {
                        lo = fLo2;
                    }
                    if (fHi2 > hi)
                    {
                        hi = fHi2;
                    }
                    pv++;
                } while (--n);
            }
        }
        else
        {
            lo = zero;
            hi = zero;
        }
        pEntry->m_ranges[i].m_fLo = lo;
        pEntry->m_ranges[i].m_fHi = hi;
    }

    pHolder = getMemoryRouter();
    pHolder->unk00 = reinterpret_cast<char*>(m_pkDeltas);
}

struct FUN_00dd5de0_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct FUN_00dd5de0_MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00dd5de0_Allocator* m_pStreamAllocator;

    FUN_00dd5de0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
static inline FUN_00dd5de0_MemoryRouter& getMemoryRouter() { return *static_cast<FUN_00dd5de0_MemoryRouter*>(::FUN_00c85750()); }
}

struct FUN_00dd5de0
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00dd5de0();
    virtual ~FUN_00dd5de0();

    static void operator delete(void* p, size_t nbytes)
    {
        FUN_00dd5de0* b = static_cast<FUN_00dd5de0*>(p);
        fnvc_adapt::getMemoryRouter().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00dd5de0
FUN_00dd5de0::FUN_00dd5de0()
{}

struct OutCollection
{
    virtual void Unknown0() = 0;
    virtual void Unknown1() = 0;
    virtual void* Begin() = 0;
    virtual void* Next(void*) = 0;
};
struct OutRecord
{
    void* handle;
    unsigned int index;
    unsigned int unk08, unk0c, unk10;
};
struct Owner
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    OutCollection* collection;
    int count;
    void FUN_00dd55f0(OutRecord* out);
};
// Iterates the collection and writes each element's handle and index into the out array.
// @fnv 0x00dd55f0
void Owner::FUN_00dd55f0(OutRecord* out)
{
    int n = count;
    void* current = collection->Begin();
    for (int i = 0; i < n; ++i)
    {
        out->handle = current;
        out->index = i;
        ++out;
        current = collection->Next(current);
    }
}

// Moved from hkpmoppcachedshapemediator_rtm_variant.cpp (VEGAS-15).
int InitIntToZero(int, int* piValue);
void CopyFivePointers(const void* apSource, void* apUnused1, void* apUnused2, void* apUnused3, void* apDest);

struct Entry
{
    int unk00;
    int index;
    Range_00dd5b00 iv;
    int unk10;
};

struct IntervalSet : Obj_00dd5b00
{

    void GetRange(const Entry& e, int axis, float& lo, float& hi) const
    {
        lo = m_kNode.m_pData[e.index].m_ranges[axis].m_fLo;
        hi = m_kNode.m_pData[e.index].m_ranges[axis].m_fHi;
    }

    void FUN_00dd5670(int a1, int axis, Entry* entries, int count, float* outMin, float* outMax);
};

// @fnv 0x00dd5670
void IntervalSet::FUN_00dd5670(int a1, int axis, Entry* entries, int count, float* outMin, float* outMax)
{
    float lo, hi;
    GetRange(entries[0], axis, lo, hi);
    entries[0].iv.m_fLo = lo;
    entries[0].iv.m_fHi = hi;
    float mn = lo;
    float mx = hi;
    for (int i = 1; i < count; i++)
    {
        GetRange(entries[i], axis, lo, hi);
        entries[i].iv.m_fLo = lo;
        entries[i].iv.m_fHi = hi;
        mn = (mn < lo) ? mn : lo;
        mx = (mx > hi) ? mx : hi;
    }
    *outMin = mn;
    *outMax = mx;
}

struct Ent
{
    int idx;
    int unk04, unk08, unk0c, unk10;
};
struct Lst
{
    int a;
    Ent e[1];
};
struct CachedRangeMediator : Obj_00dd5b00
{
    void FUN_00dd58d0(int unused, int k, Lst* l, int count, float* outMin, float* outMax);
};
// @fnv 0x00dd58d0
void CachedRangeMediator::FUN_00dd58d0(int unused, int k, Lst* l, int count, float* outMin, float* outMax)
{
    float mn = m_kNode.m_pData[l->e[0].idx].m_ranges[k].m_fLo;
    float mx = m_kNode.m_pData[l->e[0].idx].m_ranges[k].m_fHi;
    Ent* p = l->e;
    for (int i = 1; i < count; i++)
    {
        float a0 = m_kNode.m_pData[p[i].idx].m_ranges[k].m_fLo;
        float a1 = m_kNode.m_pData[p[i].idx].m_ranges[k].m_fHi;
        if (!(mn < a0))
            mn = a0;
        if (!(mx > a1))
            mx = a1;
    }
    *outMin = mn;
    *outMax = mx;
}
