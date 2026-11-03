// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01064000.h"
#include "fnv/symbols_010c4000.h"
struct CpuObject
{
    int value;
    void FUN_00e10a10(int value);
};

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

#include "generated/data/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_rtm_variant.inc"
