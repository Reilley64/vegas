// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
struct CpuObject
{
    void* value;
    void FUN_00e10a10(void* value);
};
// @fnv 0x00e10a10
void CpuObject::FUN_00e10a10(void* value)
{
    this->value = value;
}

// Moved from hkpprimitivedrawer_rtm_variant.cpp (VEGAS-15).
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01064000.h"
#include "fnv/symbols_010c4000.h"

namespace ArrowDraw {

extern const __m128 DAT_010c71e0;

struct ArrowDrawVector
{
    __m128 m;
    void add(const ArrowDrawVector& a)
    {
        m = _mm_add_ps(m, a.m);
    }
    ArrowDrawVector& operator=(const ArrowDrawVector& a)
    {
        m = a.m;
        return *this;
    }
};

struct ArrowDrawQuaternion
{
    float x, y, z, w;
    void FUN_00cb2450(int axis, float angle);
};

struct ArrowDrawTarget
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void edge(const ArrowDrawVector* a, const ArrowDrawVector* b, int c, int d, int e);
};

struct ArrowDrawObject : ::CpuObject
{
    void FUN_00e11180(const ArrowDrawVector* p1, int p2, const ArrowDrawVector* p3, int p4, float p5, int p6, int p7);
    void FUN_00e10d50(const ArrowDrawVector* a0, int a1, const ArrowDrawVector* a2, int a3, float a4, int a5, int a6);
};

static __forceinline __m128 Hk_e10d50_splat(float f)
{
    __m128 v = _mm_load_ss(&f);
    return _mm_shuffle_ps(v, v, 0);
}

static __forceinline __m128 Hk_e10d50_rot(const __m128& q, __m128 v)
{
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 ww = _mm_add_ps(DAT_010c71e0, _mm_mul_ps(w, w));
    __m128 r = _mm_mul_ps(v, ww);
    __m128 p = _mm_mul_ps(q, v);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    __m128 d = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    d = _mm_shuffle_ps(d, d, 0);
    r = _mm_add_ps(r, _mm_mul_ps(d, q));
    __m128 c = _mm_sub_ps(
        _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(v, v, 0xd2)),
        _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2),
                                  _mm_shuffle_ps(v, v, 0xc9)));
    r = _mm_add_ps(r, _mm_mul_ps(w, c));
    return _mm_add_ps(r, r);
}

// @fnv 0x00e10d50
void ArrowDrawObject::FUN_00e10d50(const ArrowDrawVector* a0, int a1, const ArrowDrawVector* a2, int a3, float a4,
                                   int a5, int a6)
{
    ArrowDrawVector p1, p2;
    ArrowDrawQuaternion q1, q2;
    p1.m = _mm_add_ps(_mm_mul_ps(Hk_e10d50_splat(a4), ((const ArrowDrawVector*)a1)->m),
                                     a0->m);
    ((ArrowDrawTarget*)value)->edge(a0, &p1, a3, a5, a6);
    q1.FUN_00cb2450((int)a2, ::DAT_01064f60);
    q2.FUN_00cb2450((int)a2, ::DAT_01016b78);
    double na = -a4;
    __m128 r1 = Hk_e10d50_rot(*(__m128*)&q1, ((const ArrowDrawVector*)a1)->m);
    volatile float s = (float)(na * DAT_010c4ab0);
    ArrowDrawTarget* nextSink = (ArrowDrawTarget*)value;
    p2.m = _mm_add_ps(_mm_mul_ps(Hk_e10d50_splat(s), r1), p1.m);
    nextSink->edge(&p1, &p2, a3, a5, a6);
    __m128 r2 = Hk_e10d50_rot(*(__m128*)&q2, r1);
    p2.m = _mm_add_ps(_mm_mul_ps(Hk_e10d50_splat(s), r2), p1.m);
    ((ArrowDrawTarget*)value)->edge(&p1, &p2, a3, a5, a6);
}

}

// Moved from hkpprimitivedrawer_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/ArrowDraw__ArrowDrawObject.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101f000.h"

typedef float hkReal;

class __declspec(align(16)) hkVector4
{
  public:
    hkVector4()
    {}
    hkVector4(const hkVector4& v)
    {
        m_v = v.m_v;
    }
    void setSubMul4(const hkVector4& a, const hkVector4& b, hkReal r)
    {
        __m128 s = _mm_load_ss(&r);
        s = _mm_shuffle_ps(s, s, 0);
        m_v = _mm_sub_ps(a.m_v, _mm_mul_ps(s, b.m_v));
    }
    __m128 m_v;
};

class hkMatrix3
{
  public:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

class hkDisplayHandlerE10B
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void DisplayLine(const hkVector4& start, const hkVector4& end, int color, int id, int tag);
};

class AxisDisplayOwner
{
  public:
    hkDisplayHandlerE10B* m_handler;
    void FUN_00e10bf0(const hkVector4& pos, const hkMatrix3& rot, hkReal size, int color, int id, int tag);
};

// @fnv 0x00e10bf0
void AxisDisplayOwner::FUN_00e10bf0(const hkVector4& pos, const hkMatrix3& rot, hkReal size, int color, int id, int tag)
{
    hkVector4 x = rot.m_kColumn0;
    hkVector4 y = rot.m_kColumn1;
    hkVector4 z = rot.m_kColumn2;
    hkVector4 start;
    hkVector4 end;
    start.setSubMul4(pos, x, size);
    end.setSubMul4(pos, x, -size);
    m_handler->DisplayLine(start, end, color, id, tag);
    start.setSubMul4(pos, y, size);
    end.setSubMul4(pos, y, -size);
    m_handler->DisplayLine(start, end, color, id, tag);
    start.setSubMul4(pos, z, size);
    end.setSubMul4(pos, z, -size);
    m_handler->DisplayLine(start, end, color, id, tag);
}

extern "C" void _ReadWriteBarrier();

struct FNV_Allocator
{
    virtual void unk00();
    virtual void unk04();
};
struct FNV_AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FNV_Allocator* m_pAllocator;
};
static inline FNV_AllocHolder* getMemoryRouter() { return static_cast<FNV_AllocHolder*>(::FUN_00c85750()); }
char* __cdecl FUN_00c85690(FNV_Allocator* alloc, int size);
void __cdecl FUN_00c856c0(FNV_Allocator* owner, char* data);


struct __declspec(align(16)) Quat
{
    float x, y, z, w;
    void FUN_00cb2450(const __m128* axis, float angle);
};

struct Drawer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void Line(void* a, void* b, int c, int d, int e);
};

struct VectorArg
{
    __m128* p;
    VectorArg(__m128* v) : p(v)
    {}
    operator __m128*() const
    {
        return p;
    }
};

struct CircleDrawer
{
    Drawer* drawer;
    void FUN_00e10f60(float angle, __m128* base, __m128* a10, VectorArg a14, int count, int a1c, float a20, int a24,
                      int a28);
};

static __forceinline __m128 RotateInitial(const Quat& quat, const __m128& vector)
{
    const __m128& v = vector;
    __m128 q = *(const __m128*)&quat;
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 factor = _mm_add_ps(*(const __m128*)(*reinterpret_cast<float (*)[4]>((void *)&::DAT_010c71e0)), _mm_mul_ps(w, w));
    __m128 scaled = _mm_mul_ps(v, factor);
    __m128 m = _mm_mul_ps(q, v);
    __m128 sumxy = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), sumxy);
    __m128 d = _mm_shuffle_ps(dot, dot, 0);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(d, q));
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(v, v, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(v, v, 0xc9));
    __m128 cross = _mm_sub_ps(first, second);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(w, cross));
    return _mm_add_ps(scaled, scaled);
}

static __forceinline __m128 Rotate(const Quat& quat, const __m128& vector)
{
    __m128 v = vector;
    __m128 q = *(const __m128*)&quat;
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 factor = _mm_add_ps(*(const __m128*)(*reinterpret_cast<float (*)[4]>((void *)&::DAT_010c71e0)), _mm_mul_ps(w, w));
    __m128 scaled = _mm_mul_ps(v, factor);
    __m128 m = _mm_mul_ps(q, v);
    __m128 sumxy = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), sumxy);
    __m128 d = _mm_shuffle_ps(dot, dot, 0);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(d, q));
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(v, v, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(v, v, 0xc9));
    __m128 cross = _mm_sub_ps(first, second);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(w, cross));
    return _mm_add_ps(scaled, scaled);
}

// @fnv 0x00e10f60
void CircleDrawer::FUN_00e10f60(float angle, __m128* base, __m128* a10, VectorArg a14, int count, int a1c, float a20,
                                int a24, int a28)
{
    FNV_AllocHolder* h = getMemoryRouter();
    FNV_Allocator* allocator = h->m_pAllocator;
    char* buf = FUN_00c85690(allocator, count * 16);
    float r = a20 / angle;
    Quat q1;
    q1.FUN_00cb2450(a14, angle);
    Quat q2;
    float ang2 = (float)(DAT_0101ff48 / (double)count);
    __m128* direction = a10;
    q2.FUN_00cb2450(direction, ang2);
    __m128 v = RotateInitial(q1, *direction);
    __m128* center = base;
    __m128* out = (__m128*)buf;
    for (int i = 0; i < count; i++)
    {
        out[i] = *center;
        _ReadWriteBarrier();
        out[i] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&r), _mm_load_ss(&r), 0), v), out[i]);
        v = Rotate(q2, v);
    }
    for (int i = 0; i < count; i++)
    {
        drawer->Line(base, buf + i * 16, a1c, a24, a28);
        drawer->Line(buf + i * 16, buf + (((i + 1) % count) * 16), a1c, a24, a28);
    }
    h = getMemoryRouter();
    FUN_00c856c0(h->m_pAllocator, buf);
}
namespace fnv_00e11180 {

struct PlaneDrawVector
{
    __m128 m;
    void add(const PlaneDrawVector& a)
    {
        m = _mm_add_ps(m, a.m);
    }
    PlaneDrawVector& operator=(const PlaneDrawVector& a)
    {
        m = a.m;
        return *this;
    }
};

struct PlaneDrawQuaternion
{
    float x, y, z, w;
    void FUN_00cb2450(int p2, float angle);
};

struct PlaneDrawTarget
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void edge(const PlaneDrawVector* a, const PlaneDrawVector* b, int p4, int p6, int p7);
};

static inline __m128 PlaneDrawDot3(__m128 t)
{
    __m128 a = _mm_shuffle_ps(t, t, 0x55);
    a = _mm_add_ss(a, t);
    __m128 b = _mm_shuffle_ps(t, t, 0xaa);
    return _mm_add_ss(b, a);
}

extern const double DAT_010eacc0;

static __forceinline __m128 PlaneDrawRotate(__m128 q, __m128 p)
{
    __m128 nh = (*reinterpret_cast<const __m128 *>((void *)&::DAT_010c71e0));
    __m128 qw = _mm_shuffle_ps(q, q, 0xff);
    __m128 factor = _mm_add_ps(nh, _mm_mul_ps(qw, qw));
    __m128 sum = _mm_mul_ps(p, factor);
    __m128 dot = PlaneDrawDot3(_mm_mul_ps(q, p));
    dot = _mm_shuffle_ps(dot, dot, 0);
    sum = _mm_add_ps(sum, _mm_mul_ps(dot, q));
    __m128 cp0 =
        _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(p, p, 0xd2));
    __m128 cp1 =
        _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(p, p, 0xc9));
    __m128 cross = _mm_sub_ps(cp0, cp1);
    sum = _mm_add_ps(sum, _mm_mul_ps(qw, cross));
    return _mm_add_ps(sum, sum);
}

struct PlaneDrawObject : CpuObject
{
    void FUN_00e11180(const PlaneDrawVector* p1, int p2, const PlaneDrawVector* p3, int p4, float p5, int p6, int p7);
};

// @fnv 0x00e11180
void PlaneDrawObject::FUN_00e11180(const PlaneDrawVector* p1, int p2, const PlaneDrawVector* p3, int p4, float p5,
                                   int p6, int p7)
{
    float s = (float)((double)p5 * DAT_010eacc0);
    PlaneDrawVector L;
    PlaneDrawVector P1v;
    __m128 t = _mm_load_ss(&s);
    __m128 splat = _mm_shuffle_ps(t, t, 0);
    *(__m128*)&L = _mm_mul_ps(splat, *(const __m128*)p3);
    PlaneDrawQuaternion D1;
    D1.FUN_00cb2450(p2, ::fnv_00a10770::DAT_0101ff38);
    PlaneDrawQuaternion D2;
    D2.FUN_00cb2450(p2, ::DAT_01064f60);

    L.m = PlaneDrawRotate(*(__m128*)&D2, L.m);
    P1v.m = p1->m;
    PlaneDrawVector A[4];
    for (int i = 0; i < 4; ++i)
    {
        A[i] = P1v;
        A[i].add(L);
        L.m = PlaneDrawRotate(*(__m128*)&D1, L.m);
    }

    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[0], &A[1], p4, p6, p7);
    }
    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[1], &A[2], p4, p6, p7);
    }
    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[2], &A[3], p4, p6, p7);
    }
    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[3], &A[0], p4, p6, p7);
    }
    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[0], &A[2], p4, p6, p7);
    }
    {
        PlaneDrawTarget* sk = (PlaneDrawTarget*)this->value;
        sk->edge(&A[1], &A[3], p4, p6, p7);
    }

    __m128 ll = *(const __m128*)&L;
    __m128 sq2 = _mm_mul_ps(ll, ll);
    __m128 dot = PlaneDrawDot3(sq2);
    __m128 r = dot;
    r = _mm_rsqrt_ss(r);
    __m128 mask = _mm_cmpeq_ss(dot, _mm_set_ss(::DAT_01011d78));
    __m128 dr = _mm_mul_ss(_mm_mul_ss(dot, r), r);
    __m128 t3 = _mm_sub_ss(_mm_set_ss(::DAT_01017718), dr);
    __m128 scale =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(::fnv_00c88020::DAT_01016248), r), t3);
    __m128 sel = _mm_andnot_ps(mask, scale);
    __m128 spl = sel;
    spl = _mm_shuffle_ps(spl, sel, 0);
    *(__m128*)&L = _mm_mul_ps(spl, ll);

    reinterpret_cast<::ArrowDraw::ArrowDrawObject *>((this))->FUN_00e10d50((const ::ArrowDraw::ArrowDrawVector *)(p1), p2, (const ::ArrowDraw::ArrowDrawVector *)(const ::fnv_00e11180::PlaneDrawVector *)(&L), p4, p5, p6, p7);
}
}  // namespace fnv_00e11180
#include "fnv/symbols_simd.h"

// Moved from hkpprimitivedrawer_gs_nogs_variant_rtm_variant.cpp (VEGAS-15).
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_00cb2e30_cls.h"

struct hkRotation
{
    __m128 c0;
    __m128 c1;
    __m128 c2;

};

struct DisplayTarget
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
    virtual void DisplayLine(const hkVector4* a, const hkVector4* b, int c, int d, int e);
};

struct CpuObjectDerived : CpuObject
{
    void FUN_00e10a20(const hkVector4* center, hkVector4* axis, hkVector4* perp, float startAngle, float endAngle,
                      float radius, int numSegments, int a8, int a9, int a10);
};

// @fnv 0x00e10a20
void CpuObjectDerived::FUN_00e10a20(const hkVector4* center, hkVector4* axis, hkVector4* perp, float startAngle,
                                    float endAngle, float radius, int numSegments, int a8, int a9, int a10)
{
    perp->normalize3();
    axis->normalize3();
    hkRotation rot;
    reinterpret_cast<::FUN_00cb2e30_cls *>(&(rot))->SpawnSnap((int)(axis), startAngle);
    __m128 rad4 = _mm_load_ss(&radius);
    rad4 = _mm_shuffle_ps(rad4, rad4, 0);
    hkVector4 cur;
    cur.m_vComponents = _mm_mul_ps(rad4, perp->m_vComponents);
    cur.FUN_00c7f700(&rot, &cur);
    cur.m_vComponents = _mm_add_ps(center->m_vComponents, cur.m_vComponents);
    float stepAngle = (endAngle - startAngle) / numSegments;
    reinterpret_cast<::FUN_00cb2e30_cls *>(&(rot))->SpawnSnap((int)(axis), stepAngle);
    for (int i = 0; i < numSegments; ++i)
    {
        hkVector4 next;
        next.m_vComponents = _mm_sub_ps(cur.m_vComponents, center->m_vComponents);
        next.FUN_00c7f700(&rot, &next);
        next.m_vComponents = _mm_add_ps(center->m_vComponents, next.m_vComponents);
        ((DisplayTarget*)value)->DisplayLine(&cur, &next, a8, a9, a10);
        cur.m_vComponents = next.m_vComponents;
    }
}
#include "generated/data/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_rtm_variant.inc"
#include "generated/data/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_ehsc_nogs_noehsc_variant_rtm_variant.inc"
