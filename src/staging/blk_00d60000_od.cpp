
// src/staging/blk_00d60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00dcf000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010cc000.h"
#include <xmmintrin.h>
#include <math.h>
#include "fnv/symbols_00dce000.h"
#include "fnv/symbols_010d3000.h"
#include "fnv/symbols_simd.h"
#include "fnv/symbols_00d6a000.h"
#include "fnv/symbols_00d6b000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/symbols_01267000.h"

namespace sd6ae50 {


struct FinishLoadedObjectFlag
{
    int m_iFinishing;
};

struct LoadedMember
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    LoadedMember(FinishLoadedObjectFlag kFlag);
};

struct __declspec(align(16)) LoadedObject
{
    const char* m_pVtbl;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int m_uiLogicalSize;
    unsigned short m_usCapacity;
    unsigned short m_usFlags;
    LoadedMember m_kMember;

    LoadedObject(FinishLoadedObjectFlag kFlag)
        : m_pVtbl(DAT_010cc040), m_uiLogicalSize(0), m_usCapacity(0), m_usFlags(0x8000), m_kMember(kFlag)
    {}
};

// @fnv 0x00d6ae50
const char* FUN_00d6ae50()
{
    FinishLoadedObjectFlag kFlag;
    kFlag.m_iFinishing = 0;
    LoadedObject kObject(kFlag);
    return kObject.m_pVtbl;
}

}

struct FUN_00d6aec0_seed
{
    int v;
};

__declspec(align(16)) class FUN_00d6aec0_obj
{
  public:
    FUN_00d6aec0_obj(FUN_00d6aec0_seed s) throw();
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
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
};

// @fnv 0x00d6aec0
int FUN_00d6aec0() throw()
{
    FUN_00d6aec0_obj obj((FUN_00d6aec0_seed()));
    return obj.unk00;
}

union Basis
{
    struct
    {
        __m128 x;
        __m128 y;
        __m128 z;
    };
};

struct FUN_004b4ab0_Class
{
    union
    {
        __m128 value;
    };
    void FUN_004b4ab0(int basis, int vector);
    void FUN_00c7f700(const Basis* basis, const FUN_004b4ab0_Class* vector);
};

struct MotionInput
{
    float scale;
    __m128 directionA;
    __m128 directionB;
    __m128 axis;
    __m128 position;
    __m128 target;
    float maxLength;
    __m128 translation;
};

static __forceinline float scalar(__m128 a)
{
    float value;
    _mm_store_ss(&value, a);
    return value;
}

static __forceinline __m128 cross3(const __m128& a, const __m128& b)
{
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    return _mm_sub_ps(first, _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}

static __forceinline __m128 dot3(__m128 a)
{
    __m128 squares = _mm_mul_ps(a, a);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares);
    return _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), sum);
}

static __forceinline __m128 normalized3(__m128 a)
{
    __m128 lengthSquared = dot3(a);
    __m128 inverseLength = _mm_rsqrt_ss(lengthSquared);
    __m128 correction =
        _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(lengthSquared, inverseLength), inverseLength));
    __m128 refined = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inverseLength), correction);
    refined = _mm_andnot_ps(_mm_cmpeq_ss(lengthSquared, _mm_set_ss(DAT_01011d78)), refined);
    return _mm_mul_ps(_mm_shuffle_ps(refined, refined, 0), a);
}

static __forceinline void buildBasis(const MotionInput* input, __m128 normal, Basis& basis)
{
    __m128 side = normalized3(cross3(normal, input->axis));
    __m128 up = normalized3(cross3(side, input->axis));
    basis.x = side;
    basis.y = up;
    basis.z = input->axis;
}

// @fnv 0x00d6aef0
void __cdecl FUN_00d6aef0(const MotionInput* input, float outputBits)
{
    __m128 a = input->directionA, b = input->directionB;
    __m128 t = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2));
    __m128 normal = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)), t);
    if ((double)scalar(dot3(normal)) < 0.00000011920928955078125f)
        return;
    {
        normal = normalized3(normal);
        union Workspace
        {
            struct
            {
                FUN_004b4ab0_Class position;
                __m128 delta;
                Basis basis;
            };
        } workspace;
        buildBasis(input, normal, workspace.basis);
        workspace.position.value = _mm_sub_ps(input->position, input->translation);
        workspace.position.FUN_004b4ab0((int)&workspace.basis, (int)&workspace.position);
        workspace.delta = _mm_sub_ps(input->target, workspace.position.value);
        float distanceSquared;
        _mm_store_ss(&distanceSquared, dot3(workspace.delta));
        __m128 movement;
        if (distanceSquared * input->scale * input->scale > (double)input->maxLength * input->maxLength)
        {
            float length = (float)sqrt(distanceSquared);
            float inverse = 1.0f / length;
            float scale = inverse * input->maxLength;
            movement = _mm_mul_ps(_mm_set1_ps(scale), workspace.delta);
        }
        else
        {
            movement = _mm_mul_ps(_mm_set1_ps(input->scale), workspace.delta);
        }
        workspace.position.value = _mm_add_ps(movement, workspace.position.value);
        FUN_004b4ab0_Class* output = *reinterpret_cast<FUN_004b4ab0_Class* const*>(&outputBits);
        output->FUN_00c7f700(&workspace.basis, &workspace.position);
        __m128 translation = _mm_load_ps(reinterpret_cast<const float*>(&input->translation));
        __m128 transformed = _mm_load_ps(reinterpret_cast<const float*>(&output->value));
        _mm_store_ps(reinterpret_cast<float*>(&output->value), _mm_add_ps(translation, transformed));
    }
}

struct Vec4
{
    __m128 m_vComponents;
};

struct BodySource
{
    Vec4 m_000, m_010, m_020, m_030, m_040, m_050, m_060, m_070;
    Vec4 m_080, m_090, m_0a0, m_0b0, m_0c0, m_0d0, m_0e0, m_0f0;
    Vec4 m_100, m_110, m_120, m_130;
    Vec4 m_140;
    Vec4 m_150;
    Vec4 m_160;
    Vec4 m_170;
    Vec4 m_180;
    Vec4 m_190;
    Vec4 m_1a0;
    Vec4 m_1b0;
    Vec4 m_1c0;
};

struct BodyList
{
    int m_iElementCount;
    BodySource** m_data;
};

struct BodyOut
{
    Vec4 m_00;
    Vec4 m_10;
    Vec4 m_20;
    Vec4 m_30;
};

// @fnv 0x00d6b4b0
void FUN_00d6b4b0(BodyList* list, BodyOut* out)
{
    for (int i = 0; i < list->m_iElementCount; i++)
    {
        BodySource* src = list->m_data[i];
        out[i].m_20.m_vComponents = src->m_1b0.m_vComponents;
        out[i].m_30.m_vComponents = src->m_1c0.m_vComponents;
        out[i].m_00.m_vComponents = src->m_140.m_vComponents;
        out[i].m_10.m_vComponents = src->m_160.m_vComponents;
    }
}

struct __declspec(align(16)) V16
{
    float x, y, z, w;
};

struct __declspec(align(16)) D6Vec3
{
    V16 a;
    V16 b;
    V16 c;
};

struct D6Owner
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
    V16 f30;
};

struct D6Idx
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char idx02;
};

extern "C" V16* __cdecl D6GetArray(void);

// @fnv 0x00d6c030
static __declspec(noinline) void FUN_00d6c030(D6Owner* a, V16* b, D6Idx* c, void* d, void* e)
{
    D6Vec3 s;
    *(__m128*)&s.a = *(__m128*)&a->f30;
    *(__m128*)&s.b = *(__m128*)&b[3];
    *(__m128*)&s.c = *(__m128*)&b[c->idx02];
    ::FUN_00dcf280((::Input_dcf280 *)(::D6Vec3 *)(&s), (::S_00dcf100_Cfg *)(d), (::Jacobian_dcf280 **)(e));
}

volatile D6Owner* g_d6Owner;

volatile D6Idx* g_d6Idx;

volatile void* g_d6D;

volatile void* g_d6E;

extern "C" __declspec(noinline) void d6c030_dummy_caller(void)
{
    FUN_00d6c030((D6Owner*)g_d6Owner, D6GetArray(), (D6Idx*)g_d6Idx, (void*)g_d6D, (void*)g_d6E);
}

struct hkVector4
{
    __m128 m_vComponents;
};

struct hkQuaternion
{
    hkVector4 m_vec;
    void FUN_00d6bec0(const hkQuaternion& q, hkVector4& out) const;
};

// @fnv 0x00d6bec0
void hkQuaternion::FUN_00d6bec0(const hkQuaternion& q, hkVector4& out) const
{
    out.m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q.m_vec.m_vComponents, q.m_vec.m_vComponents, 0xd2),
                                              _mm_shuffle_ps(m_vec.m_vComponents, m_vec.m_vComponents, 0xc9)),
                                   _mm_mul_ps(_mm_shuffle_ps(q.m_vec.m_vComponents, q.m_vec.m_vComponents, 0xc9),
                                              _mm_shuffle_ps(m_vec.m_vComponents, m_vec.m_vComponents, 0xd2)));
    __m128 w = _mm_shuffle_ps(q.m_vec.m_vComponents, q.m_vec.m_vComponents, 0xff);
    out.m_vComponents = _mm_sub_ps(out.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(w, w, 0), m_vec.m_vComponents));
    __m128 tw = _mm_shuffle_ps(m_vec.m_vComponents, m_vec.m_vComponents, 0xff);
    out.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(tw, tw, 0), q.m_vec.m_vComponents), out.m_vComponents);
    out.m_vComponents = _mm_add_ps(out.m_vComponents, out.m_vComponents);
    __m128 d = _mm_mul_ps(q.m_vec.m_vComponents, m_vec.m_vComponents);
    d = _mm_add_ps(_mm_shuffle_ps(d, d, 0x4e), d);
    d = _mm_add_ps(_mm_shuffle_ps(d, d, 0xb1), d);
    if (_mm_movemask_ps(d) & 1)
        out.m_vComponents = _mm_xor_ps(out.m_vComponents, *(const __m128*)(*reinterpret_cast<const unsigned int (*)[4]>((void *)&::DAT_010c44d0)));
}

namespace fnv_00d6c470 {
struct FaceCode
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char index;
};
union ThreeVectors
{
    struct
    {
        __m128 x;
        __m128 y;
        __m128 z;
    };
};

// @fnv 0x00d6c470
static __declspec(noinline) void FUN_00d6c470(const FaceCode* face, const __m128* normals, const unsigned char* points,
                                              int a, int b)
{
    unsigned int index = face->index;
    unsigned int first = ::DAT_010d33c1[index];
    unsigned int second = ::DAT_010d33c2[index];
    ThreeVectors basis;
    basis.x = normals[index];
    basis.z = *reinterpret_cast<const __m128*>(points + first);
    basis.y = *reinterpret_cast<const __m128*>(points + second);
    ::FUN_00dcee80((*(const ::S_00dcee80_Info *)(&basis)), (*(const ::S_00dcee80_QueryIn *)(a)), (*(::S_00dcee80_QueryOut *)(b)));
    basis.z = *reinterpret_cast<const __m128*>(points + second);
    basis.y = _mm_xor_ps(::DAT_010c44d0, *reinterpret_cast<const __m128*>(points + first));
    ::FUN_00dcee80((*(const ::S_00dcee80_Info *)(&basis)), (*(const ::S_00dcee80_QueryIn *)(a)), (*(::S_00dcee80_QueryOut *)(b)));
}
const FaceCode* volatile inputFace;
const __m128* volatile inputNormals;
const unsigned char* volatile inputPoints;
volatile int inputA, inputB;
extern "C" const FaceCode* getFace();
extern "C" const __m128* getNormals();
extern "C" const unsigned char* getPoints();
extern "C" int getA();
extern "C" int getB();
void invoke()
{
    FUN_00d6c470(getFace(), getNormals(), getPoints(), getA(), getB());
}
}

// namespace fnv_00d6c470

struct Span
{
    unsigned char u0;
    unsigned char u1;
    unsigned char start;
    unsigned char count;
};

struct Box
{
    char* p;
};

struct Triple
{
    __m128 second;
    __m128 first;
    __m128 third;
};

// @fnv 0x00d6c500
static __declspec(noinline) void FUN_00d6c500(Span* span, int a1, Box base, Box p10, int a2)
{
    char* b = base.p;
    for (int i = span->start; i < span->start + span->count; ++i)
    {
        Triple t;
        t.first = *(__m128*)(b + DAT_010d33c0[i]);
        t.second = *(__m128*)(b + DAT_010d33c0[i + 1]);
        t.third = *(__m128*)(p10.p + DAT_010d33c0[i + 2]);
        ::FUN_00dcee80((*(const ::S_00dcee80_Info *)(&t.second)), (*(const ::S_00dcee80_QueryIn *)(a1)), (*(::S_00dcee80_QueryOut *)(a2)));
    }
}

Span* g_span;

int g_a1;

Box g_base;

Box g_p10;

int g_a2;

int g_sink;

void zz_call()
{
    FUN_00d6c500(g_span, g_a1, g_base, g_p10, g_a2);
    g_sink = 1;
}

void FUN_00d6c030(D6Owner* a, V16* b, D6Idx* c, void* d, void* e);

extern "C" void _ReadWriteBarrier();

struct hkQuaternionD6B5;

struct Vec
{
    __m128 m_vComponents;
    __forceinline __m128& quad()
    {
        return m_vComponents;
    }
    __forceinline const __m128& quad() const
    {
        return m_vComponents;
    }
    __forceinline void SetRotatedDirection(const hkQuaternionD6B5& q, const Vec& d);
    __forceinline void setRotatedTranslation(const hkQuaternionD6B5& q, const Vec& d);
    __forceinline void setAdd4(const Vec& a, const Vec& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const Vec& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const Vec& a, const Vec& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct hkQuaternionD6B5
{
    __m128 m_vComponents;
    void FUN_00cb2850(const hkQuaternionD6B5&, const hkQuaternionD6B5&, float);
};

struct Transform
{
    Vec position;
    hkQuaternionD6B5 rotation;
    Vec scale;
    __forceinline void SetProduct(const Transform& a, const Transform& b);
};

struct Pose
{
    Vec position;
    hkQuaternionD6B5 rotation;
};

struct OutputPair
{
    Transform world;
    Transform local;
};

struct Binding
{
    int count;
    BodySource** nodes;
    short* parents;
    int* indices;
    float* weights;
};

struct Weight
{
    float value;
    float unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
};

__forceinline __m128 rotate(__m128 q, __m128 v)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 p = _mm_mul_ps(v, q);
    __m128 y = _mm_shuffle_ps(p, p, 0x55);
    y = _mm_add_ss(y, p);
    __m128 z = _mm_shuffle_ps(p, p, 0xaa);
    __m128 d = _mm_add_ss(z, y);
    __m128 cross =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9)),
                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)));
    __m128 r = _mm_add_ps(
        _mm_mul_ps(cross, w),
        _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), (*reinterpret_cast<__m128 *>((void *)&::DAT_010c71e0))), v),
                          _mm_mul_ps(_mm_shuffle_ps(d, d, 0), q)));
    return _mm_add_ps(r, r);
}
__forceinline void Vec::SetRotatedDirection(const hkQuaternionD6B5& quat, const Vec& direction)
{
    __m128 qreal = _mm_shuffle_ps(quat.m_vComponents, quat.m_vComponents, 0xff);
    __m128 p = _mm_mul_ps(quat.m_vComponents, direction.m_vComponents);
    __m128 y = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    __m128 d = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), y);
    __m128 cross = _mm_sub_ps(
        _mm_mul_ps(_mm_shuffle_ps(quat.m_vComponents, quat.m_vComponents, 0xc9),
                          _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0xd2)),
        _mm_mul_ps(_mm_shuffle_ps(quat.m_vComponents, quat.m_vComponents, 0xd2),
                          _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0xc9)));
    __m128 r = _mm_add_ps(
        _mm_mul_ps(cross, qreal),
        _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(qreal, qreal), (*reinterpret_cast<__m128 *>((void *)&::DAT_010c71e0))),
                                            direction.m_vComponents),
                          _mm_mul_ps(_mm_shuffle_ps(d, d, 0), quat.m_vComponents)));
    m_vComponents = _mm_add_ps(r, r);
}
__forceinline void Vec::setRotatedTranslation(const hkQuaternionD6B5& quat, const Vec& direction)
{
    __m128 qreal = _mm_shuffle_ps(quat.m_vComponents, quat.m_vComponents, 0xff);
    __m128 p = _mm_mul_ps(_mm_load_ps(reinterpret_cast<const float*>(&quat.m_vComponents)), direction.m_vComponents);
    __m128 y = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    __m128 d = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), y);
    __m128 cross = _mm_sub_ps(
        _mm_mul_ps(_mm_shuffle_ps(quat.m_vComponents, quat.m_vComponents, 0xc9),
                          _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0xd2)),
        _mm_mul_ps(_mm_shuffle_ps(quat.m_vComponents, quat.m_vComponents, 0xd2),
                          _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0xc9)));
    __m128 r = _mm_add_ps(
        _mm_mul_ps(cross, qreal),
        _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(qreal, qreal), (*reinterpret_cast<__m128 *>((void *)&::DAT_010c71e0))),
                                            direction.m_vComponents),
                          _mm_mul_ps(_mm_shuffle_ps(d, d, 0), quat.m_vComponents)));
    m_vComponents = _mm_add_ps(r, r);
}
__forceinline void Transform::SetProduct(const Transform& a, const Transform& b)
{
    Vec extra;
    extra.setRotatedTranslation(a.rotation, b.position);
    position.setAdd4(extra, a.position);
    ::fnv_00c66320::FUN_00c66320((__m128 *)&(rotation), nullptr, (const __m128 *)&(a.rotation), (const __m128 *)&(b.rotation));
    scale.setMul4(a.scale, b.scale);
}
__forceinline __m128 blendPosition(const Vec& position, const Vec& target, float weight)
{
    __m128 scalar = _mm_load_ss(&weight);
    __m128 t = _mm_shuffle_ps(scalar, scalar, 0);
    return _mm_add_ps(_mm_mul_ps(_mm_sub_ps((*reinterpret_cast<__m128 *>((void *)&::DAT_010ec7f0)), t), position.quad()),
                             _mm_mul_ps(t, target.quad()));
}

// @fnv 0x00d6b510
static __declspec(noinline) void FUN_00d6b510(Binding* binding, Weight* weights, const Transform* root,
                                              Transform* output, const Transform* __restrict transforms)
{
    for (int i = 0; i < binding->count; ++i)
    {
        const Transform& input = transforms[i];
        Transform& outWorld = output[2 * i];
        Transform& outLocal = output[2 * i + 1];
        int parentIndex = binding->parents[i];
        const Transform* parent = parentIndex >= 0 ? &output[2 * parentIndex + 1] : root;
        outLocal.SetProduct(*parent, input);
        Pose local;
        local.rotation = outLocal.rotation;
        local.position = outLocal.position;
        int weightIndex = binding->indices ? binding->indices[i] : 0;
        if (weightIndex == -1)
            continue;
        float weight = weights[weightIndex].value;
        if (binding->weights)
            weight = (float)(weight * binding->weights[i]);
        if (weight > 0.0f && parentIndex >= 0)
        {
            BodySource* node = binding->nodes[parentIndex];
            Transform reference;
            reference.position = *reinterpret_cast<const Vec*>(&node->m_120);
            reference.scale.quad() = _mm_set_ps1(1.0f);
            reference.rotation = *reinterpret_cast<const hkQuaternionD6B5*>(&node->m_160);
            Transform composed;
            composed.SetProduct(reference, input);
            local.rotation.FUN_00cb2850(local.rotation, composed.rotation, weight);
            local.position.quad() = blendPosition(local.position, composed.position, weight);
        }
        Vec offset;
        offset.SetRotatedDirection(local.rotation, *reinterpret_cast<const Vec*>(&binding->nodes[i]->m_170));
        outWorld.position.setAdd4(offset, local.position);
        outWorld.rotation.m_vComponents = local.rotation.m_vComponents;
        outWorld.scale.quad() = _mm_load_ps(&DAT_01267e30);
    }
}

void RunCompose_d6b510(Binding* binding, Weight* weights, const Transform* root, Transform* output,
                       const Transform* __restrict transforms)
{
    FUN_00d6b510(binding, weights, root, output, transforms);
}
