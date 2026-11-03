// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
struct FUN_00e4dd90_shell
{
    void FUN_00e4dd90(float* output);
};
// If the object at offset 0x0c is set, writes four floats from its nested structure at offsets 0x10, 0x70, 0xd0 and 0x130 into output.
// @fnv 0x00e4dd90
void FUN_00e4dd90_shell::FUN_00e4dd90(float* output)
{
    if (*(int*)((unsigned char*)this + 0x0c) != 0)
    {
        output[0] = *(float*)(*(unsigned char**)(*(unsigned char**)((unsigned char*)this + 0x0c) + 0xc4) + 0x10);
        output[1] = *(float*)(*(unsigned char**)(*(unsigned char**)((unsigned char*)this + 0x0c) + 0xc4) + 0x70);
        output[2] = *(float*)(*(unsigned char**)(*(unsigned char**)((unsigned char*)this + 0x0c) + 0xc4) + 0xd0);
        output[3] = *(float*)(*(unsigned char**)(*(unsigned char**)((unsigned char*)this + 0x0c) + 0xc4) + 0x130);
    }
}

struct FUN_00e4dde0
{
    virtual void Vfn0();
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    FUN_00e4dde0();
};
// Constructor that zeroes unk0C, unk70, unk74, unk80, unk84, unk88 and unk8C.
// @fnv 0x00e4dde0
FUN_00e4dde0::FUN_00e4dde0()
{
    unk0C = 0;
    unk70 = 0;
    unk74 = 0;
    unk80 = 0;
    unk84 = 0;
    unk88 = 0;
    unk8C = 0;
}

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};


struct FUN_00e4e3c0
{
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
    int m_i6c;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;

    FUN_00e4e3c0();

// @fnv 0x00e4e3c0
    virtual ~FUN_00e4e3c0()
    {}

    static void operator delete(void* apMemory)
    {
        AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(apMemory, sizeof(FUN_00e4e3c0));
    }
};

FUN_00e4e3c0::FUN_00e4e3c0()
{
    m_i04 = 0;
}

// Moved from hkpcpukdtreeraycastjob_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpukdtreeraycastjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>
#include "fnv/decl/FUN_00d98390.h"
#include "fnv/decl/S_00d98300.h"

#include <xmmintrin.h>
__declspec(align(16)) struct Vec
{
    float x, y, z, w;
};
class HkVec4
{
  public:
    void operator=(const HkVec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const __m128& q)
    {
        m_vComponents = q;
    }
    operator __m128() const
    {
        return m_vComponents;
    }
    void setSub4(const HkVec4& a, const HkVec4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setRotatedInverseDir(const struct Mat3& r, const HkVec4& b);
    void SetRotatedVector(const struct Mat3& a, const HkVec4& b);
    void SetTransformedPosition(const struct Mat4& t, const HkVec4& b);
    void SetRotatedDirection(const struct Mat3& r, const HkVec4& b);
    __m128 m_vComponents;
};
struct Mat3
{
    HkVec4 c0;
    HkVec4 c1;
    HkVec4 c2;
    const HkVec4& getColumn(int x) const
    {
        return (&c0)[x];
    }
};
struct Mat4
{
    Mat3 rot;
    HkVec4 trans;
    const Mat3& getRotation() const
    {
        return rot;
    }
    const HkVec4& getTranslation() const
    {
        return trans;
    }
};
__forceinline void HkVec4::SetRotatedVector(const Mat3& a, const HkVec4& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void HkVec4::SetRotatedDirection(const Mat3& r, const HkVec4& v)
{
    SetRotatedVector(r, v);
}
__forceinline void HkVec4::setRotatedInverseDir(const Mat3& r, const HkVec4& b)
{
    __m128 c0 = r.getColumn(0).m_vComponents;
    __m128 c1 = r.getColumn(1).m_vComponents;
    __m128 c2 = r.getColumn(2).m_vComponents;
    {
        __m128 _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, 0xd4);
        c2 = _ctmp;
    }
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(c0, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(c1, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void HkVec4::SetTransformedPosition(const Mat4& t, const HkVec4& b)
{
    HkVec4 t0;
    t0.setSub4(b, t.getTranslation());
    setRotatedInverseDir(t.getRotation(), t0);
}
struct AItem
{
    HkVec4 r0;
    HkVec4 r1;
    float tail0;
    float tail1;
    float tail2;
    float tail3;
};

struct BoolResult
{
    char b;
};
class GuardInner
{

  public:
    virtual void Alpha();

    virtual BoolResult Query(void* f8, void* p1);
};

struct F04Obj
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    GuardInner inner;
};

__declspec(align(16)) struct FUN_009c1aa0_Class
{

  public:
    float x, y, z, w;

    float gate;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    float f44;
    float f48;

    FUN_009c1aa0_Class& FUN_009c1aa0(const FUN_009c1aa0_Class& src);
    bool DidHit() const
    {
        return gate < 1.0f;
    }
};

struct DestEntry
{

    union
    {
        __m128 row;
        int w0;
    } u;

    float gate;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    float f44;
    float f48;

    float f4c;
    union
    {
        void* field50;
        int info50;
    };

    int tail54;
    int tail58;
    int tail5c;
};

struct DestObj
{

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;

    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;

    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;

    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;

    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;

    char flagc0;
    char fc1;
    char fc2;
    char fc3;

    DestEntry* entries;
};

struct Mask
{
    __m128 q;
};
class HeadObj
{

  public:
    virtual void Alpha();

    virtual void Bravo();

    virtual void Charlie();

    virtual void Delta();

    virtual void Echo();

    virtual void Foxtrot();

    virtual void Golf();

    virtual void Hotel();

    virtual void India();

    virtual void Juliett();

    virtual Mask V28(void* mat, void* arr, const Mask& p2);

    int h04;
    int h08;
    int h0c;
    int h10;
    int h14;
    int h18;
    int h1c;
    int h20;

    int h24;
    int h28;
    int h2c;
    int h30;
    int h34;
    int h38;
    int h3c;
    int h40;

    int h44;
    int h48;
    int h4c;

    int field50;
};

struct Param
{
    HeadObj* head;
    int unk04;
    const void* motion;
    const Mat4& getTransform() const
    {
        return *static_cast<const Mat4*>(motion);
    }
    HeadObj* getShape() const
    {
        return head;
    }
};

class LocalArr
{

  public:
    FUN_009c1aa0_Class entries[4];


};

struct LocalGroup
{
    HkVec4 to;
    HkVec4 from;
    Mask result;
    LocalArr arr;
};
struct BundleInput
{
    HkVec4 from[3];
    HkVec4 to[3];
    unsigned int filterInfo;
    const void* filter;
};
struct Cls
{

    int unk00;

    F04Obj* f04;

    AItem* f08;

    DestObj* f0c;

    BundleInput work;

    int flags80[4];

    void FUN_00e4de10(Param* p1, const Mask& p2);
};

// @fnv 0x00e4de10
void Cls::FUN_00e4de10(Param* p1, const Mask& p2)
{
    HeadObj* head = p1->head;
    if (head)
    {
        const Mat4& transform = p1->getTransform();
        if (!f04 || f04->inner.Query(f08, p1).b)
        {
            work.from[0].SetTransformedPosition(transform, f08[0].r0);
            work.to[0].SetTransformedPosition(transform, f08[0].r1);
            work.from[1].SetTransformedPosition(transform, f08[1].r0);
            work.to[1].SetTransformedPosition(transform, f08[1].r1);
            work.from[2].SetTransformedPosition(transform, f08[2].r0);
            work.to[2].SetTransformedPosition(transform, f08[2].r1);
            HkVec4 tempFrom;
            tempFrom.SetTransformedPosition(transform, f08[3].r0);
            HkVec4 tempTo;
            tempTo.SetTransformedPosition(transform, f08[3].r1);
            {
                __m128 tmp3, tmp2, tmp1, tmp0;
                tmp0 = _mm_shuffle_ps((work.from[0]), (work.from[1]), 0x44);
                tmp2 = _mm_shuffle_ps((work.from[0]), (work.from[1]), 0xEE);
                tmp1 = _mm_shuffle_ps((work.from[2]), (tempFrom), 0x44);
                tmp3 = _mm_shuffle_ps((work.from[2]), (tempFrom), 0xEE);
                (work.from[0]) = _mm_shuffle_ps(tmp0, tmp1, 0x88);
                (work.from[1]) = _mm_shuffle_ps(tmp0, tmp1, 0xDD);
                (work.from[2]) = _mm_shuffle_ps(tmp2, tmp3, 0x88);
                (tempFrom) = _mm_shuffle_ps(tmp2, tmp3, 0xDD);
            }
            {
                __m128 tmp3, tmp2, tmp1, tmp0;
                tmp0 = _mm_shuffle_ps((work.to[0]), (work.to[1]), 0x44);
                tmp2 = _mm_shuffle_ps((work.to[0]), (work.to[1]), 0xEE);
                tmp1 = _mm_shuffle_ps((work.to[2]), (tempTo), 0x44);
                tmp3 = _mm_shuffle_ps((work.to[2]), (tempTo), 0xEE);
                (work.to[0]) = _mm_shuffle_ps(tmp0, tmp1, 0x88);
                (work.to[1]) = _mm_shuffle_ps(tmp0, tmp1, 0xDD);
                (work.to[2]) = _mm_shuffle_ps(tmp2, tmp3, 0x88);
                (tempTo) = _mm_shuffle_ps(tmp2, tmp3, 0xDD);
            }

            LocalArr bundleOutput;
            new ((void *)&(bundleOutput)) ::FUN_00d98390();
            reinterpret_cast<::S_00d98300 *>(&(bundleOutput))->ResetEntries();
            head->V28(&work, &bundleOutput, p2);
            for (int i = 0; i < 4; i++)
            {
                if (bundleOutput.entries[i].gate < 1.0f &&
                    (flags80[i] == 0 || bundleOutput.entries[i].gate < f0c->entries[i].gate))
                {
                    DestEntry* dst = &f0c->entries[i];
                    ((FUN_009c1aa0_Class*)dst)->FUN_009c1aa0(bundleOutput.entries[i]);
                    dst->info50 = *(int*)&(&bundleOutput.entries[i])[1].x;
                    f0c->entries[i].field50 = p1;
                    const Mat3& rot = transform.getRotation();
                    ((HkVec4&)f0c->entries[i].u.row).SetRotatedDirection(rot, (const HkVec4&)bundleOutput.entries[i]);
                    float v;
                    if (f0c->flagc0 != 0)
                        v = 0.0f;
                    else
                        v = f0c->entries[i].gate;
                    f0c->entries[i].gate = v;
                    flags80[i] = 1;
                }
            }
        }
    }
}

// Moved from hkpcpukdtreeraycastjob_rtm_variant.cpp (VEGAS-15).
#include "fnv/symbols_011b3000.h"

#include "fnv/symbols_simd.h"

struct Sub60
{
    __m128 v0;
    float f10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;

    Sub60()
    {
        f10 = 1.0f;
        unk14 = -1;
        unk40 = 0;
        unk20 = -1;
        unk50 = 0;
    }

    Sub60& operator=(const Sub60& o)
    {
        v0 = o.v0;
        f10 = o.f10;
        unk14 = o.unk14;
        unk18 = o.unk18;
        unk1C = o.unk1C;
        unk20 = o.unk20;
        unk24 = o.unk24;
        unk28 = o.unk28;
        unk2C = o.unk2C;
        unk30 = o.unk30;
        unk34 = o.unk34;
        unk38 = o.unk38;
        unk3C = o.unk3C;
        unk40 = o.unk40;
        unk50 = o.unk50;
        return *this;
    }
};

struct Sub30
{
    __m128 v0;
    __m128 v1;
    char c20;
    int i24;

    Sub30()
    {
        c20 = 0;
        i24 = 0;
    }

    Sub30& operator=(const Sub30& o)
    {
        v0 = o.v0;
        v1 = o.v1;
        c20 = o.c20;
        i24 = o.i24;
        return *this;
    }
};

struct InputStruct
{
    Sub30 items30[4];
    int count;
    char cC4;
    Sub60* ptrs[4];
    int unkD8;
    int unkDC;
    int saved[4];
};

struct LocalInput
{
    Sub30 items30[4];
    char flag;
    Sub60* ptr;
    int unkC8;
    int unkCC;
    int saved[4];
};

struct FloatMatrix3
{
    __m128 col0;
    __m128 col1;
    __m128 col2;
};

void __cdecl FUN_00d99570(unsigned char* out, void* a1, FloatMatrix3* m1, FloatMatrix3* m2, FUN_00e4dde0* obj,
                          int flag);

// @fnv 0x00e2acf0
void FUN_00e2acf0(void* a1, InputStruct* a2, void* a3, float* a4)
{
    if (!a1)
        return;

    const int count = a2->count;
    Sub60 items60[4];
    for (int j = 0; count > j; ++j)
        items60[j] = *a2->ptrs[j];

    LocalInput local;
    local.flag = a2->cC4;
    local.ptr = items60;
    for (int j = 0; j < a2->count; j++)
    {
        local.items30[j] = a2->items30[j];
        local.ptr[j].f10 = a4[j];
        local.saved[j] = a2->saved[j];
    }

    FUN_00e4dde0 obj;
    obj.unk04 = (int)a3;
    obj.unk08 = (int)a2;
    obj.unk0C = (int)&local;
    obj.unk70 = a2->items30[0].i24;
    obj.unk80 = a2->saved[0];
    obj.unk84 = a2->saved[1];
    obj.unk88 = a2->saved[2];
    obj.unk8C = a2->saved[3];

    FloatMatrix3 m1;
    FloatMatrix3 m2;
    ::fnv_00e2ab00::FUN_00e2ab00((__m128 *)(a2), (__m128 *)(::FloatMatrix3 *)(&m1), (__m128 *)(::FloatMatrix3 *)(&m2));

    unsigned char result;
    FUN_00d99570(&result, a1, &m1, &m2, &obj, DAT_011b3830[a2->count]);

    for (int k = 0; k < a2->count; k++)
    {
        *a2->ptrs[k] = items60[k];
        a2->saved[k] = local.saved[k];
    }

    ((FUN_00e4dd90_shell*)&obj)->FUN_00e4dd90(a4);
}
