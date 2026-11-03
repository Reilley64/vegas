// src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Moved from hkpsimplecollisionresponse_gs_nogs_variant.cpp (VEGAS-15).
// src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <math.h>

#include "fnv/decl/MProduct.h"
#include "fnv/decl/S_00cd4b60.h"
#include "fnv/symbols_00df5000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
class D9Scalar
{
    __m128 value;

  public:
    __forceinline D9Scalar()
    {}
    __forceinline D9Scalar(const __m128& x) : value(x)
    {}
    __forceinline __m128 quad() const
    {
        return value;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};

struct D9Matrix;
struct D9Rotation;
struct __declspec(align(16)) D9Vector
{
    __m128 unk00;
    __forceinline D9Vector()
    {}
    __forceinline D9Vector(float x, float y, float z, float w = 0.0f)
    {
        unk00 = _mm_setr_ps(x, y, z, w);
    }
    __forceinline D9Vector(const __m128& value)
    {
        unk00 = value;
    }
    __forceinline D9Vector(const D9Vector& value)
    {
        unk00 = value.unk00;
    }
    __forceinline void operator=(const D9Vector& value)
    {
        unk00 = value.unk00;
    }
    __forceinline void operator=(const __m128& value)
    {
        unk00 = value;
    }
    operator __m128() const
    {
        return unk00;
    }
    __forceinline float& component(int i)
    {
        return reinterpret_cast<float*>(&unk00)[i];
    }
    __forceinline const float& component(int i) const
    {
        return reinterpret_cast<const float*>(&unk00)[i];
    }
    __forceinline void subtract(const D9Vector& a, const D9Vector& b)
    {
        unk00 = _mm_sub_ps(a.unk00, b.unk00);
    }
    __forceinline void broadcast(const D9Vector& a, int i)
    {
        if (i == 0)
            unk00 = _mm_shuffle_ps(a.unk00, a.unk00, 0);
        else if (i == 1)
            unk00 = _mm_shuffle_ps(a.unk00, a.unk00, 0x55);
        else
            unk00 = _mm_shuffle_ps(a.unk00, a.unk00, 0xaa);
    }
    __forceinline void multiply(const D9Vector& a, const D9Vector& b)
    {
        unk00 = _mm_mul_ps(a.unk00, b.unk00);
    }
    __forceinline void zero()
    {
        unk00 = _mm_setzero_ps();
    }
    __forceinline D9Scalar dot(const D9Vector& a) const
    {
        __m128 products = _mm_mul_ps(unk00, a.unk00);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products);
        return _mm_add_ss(_mm_shuffle_ps(products, products, 0xaa), xy);
    }
    __forceinline D9Scalar inverseLength() const
    {
        const __m128 half = _mm_set_ss(::fnv_00c88020::DAT_01016248);
        const __m128 three = _mm_set_ss(DAT_01017718);
        const __m128 zero = _mm_set_ss(DAT_01011d78);
        const __m128 square = dot(*this).quad();
        const __m128 empty = _mm_cmpeq_ss(square, zero);
        const __m128 approximation = _mm_rsqrt_ss(square);
        const __m128 improved =
            _mm_mul_ss(_mm_mul_ss(half, approximation),
                       _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(square, approximation), approximation)));
        return _mm_andnot_ps(empty, improved);
    }
    __forceinline void normalize3()
    {
        __m128 inverse = inverseLength().splat();
        unk00 = _mm_mul_ps(inverse, unk00);
    }
    __forceinline void cross(const D9Vector& a, const D9Vector& b)
    {
        __m128 positive = _mm_mul_ps(_mm_shuffle_ps(a.unk00, a.unk00, 0xc9), _mm_shuffle_ps(b.unk00, b.unk00, 0xd2));
        __m128 negative = _mm_mul_ps(_mm_shuffle_ps(a.unk00, a.unk00, 0xd2), _mm_shuffle_ps(b.unk00, b.unk00, 0xc9));
        unk00 = _mm_sub_ps(positive, negative);
    }
    inline void inverseRotate(const D9Rotation& matrix, const D9Vector& vector);
    inline void rotate(const D9Rotation& matrix, const D9Vector& vector);
};
struct D9Matrix
{
    D9Vector unk00, unk10, unk20;
    __forceinline D9Matrix()
    {}
    __forceinline D9Matrix(const D9Matrix& other)
    {
        unk00 = other.unk00;
        unk10 = other.unk10;
        unk20 = other.unk20;
    }
    __forceinline D9Vector& column(int i)
    {
        return (&unk00)[i];
    }
    __forceinline const D9Vector& column(int i) const
    {
        return (&unk00)[i];
    }
};
struct __declspec(align(16)) D9Rotation : D9Matrix
{
};
inline void D9Vector::inverseRotate(const D9Rotation& matrix, const D9Vector& vector)
{
    __m128 x = matrix.column(0).unk00, y = matrix.column(1).unk00, z = matrix.column(2).unk00;
    {
        __m128 low, last;
        low = _mm_unpacklo_ps(x, y);
        last = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), z, 0xe4);
        x = _mm_movelh_ps(low, z);
        y = _mm_shuffle_ps(_mm_movehl_ps(x, low), z, 0xd4);
        z = last;
    }
    const __m128 vx = _mm_shuffle_ps(vector.unk00, vector.unk00, 0);
    const __m128 px = _mm_mul_ps(x, vx);
    const __m128 vy = _mm_shuffle_ps(vector.unk00, vector.unk00, 0x55);
    const __m128 py = _mm_mul_ps(y, vy);
    const __m128 vz = _mm_shuffle_ps(vector.unk00, vector.unk00, 0xaa);
    const __m128 pz = _mm_mul_ps(z, vz);
    unk00 = _mm_add_ps(_mm_add_ps(px, py), pz);
}
inline void D9Vector::rotate(const D9Rotation& matrix, const D9Vector& vector)
{
    __m128 vx = _mm_shuffle_ps(vector.unk00, vector.unk00, 0);
    __m128 px = _mm_mul_ps(matrix.column(0).unk00, vx);
    __m128 vy = _mm_shuffle_ps(vector.unk00, vector.unk00, 0x55);
    __m128 py = _mm_mul_ps(matrix.column(1).unk00, vy);
    __m128 vz = _mm_shuffle_ps(vector.unk00, vector.unk00, 0xaa);
    __m128 pz = _mm_mul_ps(matrix.column(2).unk00, vz);
    unk00 = _mm_add_ps(_mm_add_ps(px, py), pz);
}
struct D9Shape
{
    D9Vector unk00, unk10, unk20, unk30, unk40;
    D9Rotation unk50;
    D9Vector& center()
    {
        return unk40;
    }
    D9Rotation& rotation()
    {
        return unk50;
    }
};
struct D9Contact
{
    D9Vector unk00, unk10;
    const D9Vector& position() const
    {
        return unk00;
    }
    const D9Vector& normal() const
    {
        return unk10;
    }
};
struct D9Row
{
    D9Vector unk00;
    D9Matrix unk10;
    D9Vector unk40;
    const void* unk50;
};
struct D9Pair
{
    D9Vector unk00, unk10;
};
struct D9Solver
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3c();
    virtual void f40(const D9Contact&, D9Row&, D9Pair&, D9Row&, D9Pair&);
    virtual void f44(const D9Contact&, float, D9Row&, D9Pair&, D9Row&, D9Pair&);
};
struct D9Body
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned char unke8;
    unsigned char unke9;
    unsigned char unkea;
    unsigned char unkeb;
    unsigned char unkec;
    unsigned char unked;
    unsigned char unkee;
    unsigned char unkef;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    __m128 unk1b0, unk1c0;
};
struct D9Equation
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
};
inline float D9Abs(float value)
{
    return (float)fabs(value);
}
__forceinline void D9Perpendicular(const D9Vector& normal, D9Vector& out)
{
    int minimum = 0, first = 1, second = 2;
    float x = D9Abs(normal.component(0));
    float y = D9Abs(normal.component(1));
    float z = D9Abs(normal.component(2));
    if (y < x)
    {
        first = 0;
        minimum = 1;
        x = y;
    }
    if (z < x)
    {
        second = minimum;
        minimum = 2;
    }
    out.zero();
    out.component(first) = normal.component(second);
    out.component(second) = -normal.component(first);
}
struct Basis
{
    D9Vector unk00, unk10, unk20;
    __forceinline void setNormalBasis(const D9Vector& normal)
    {
        unk00 = normal;
        D9Perpendicular(normal, unk10);
        unk10.normalize3();
        unk20.cross(normal, unk10);
    }
};
extern void __cdecl FUN_00df5950(const D9Row&, const D9Row&, const Basis&, D9Equation&);
// @fnv 0x00d9ee50
void __cdecl FUN_00d9ee50(D9Solver* solver, const D9Contact& contact, void* parameters, D9Body* ownerA, D9Body* ownerB,
                          D9Shape* accumulatorA, D9Shape* accumulatorB, float& result)
{
    D9Row inputs[2];
    D9Pair velocities[2];
    {
        D9Shape* accumulator = accumulatorA;
        D9Body* owner = ownerA;
        for (int index = 0; index < 2; ++index)
        {
            D9Row& input = inputs[index];
            D9Pair& velocity = velocities[index];
            input.unk40 = accumulator->unk30;
            const D9Vector& center = accumulator->center();
            input.unk00.subtract(contact.position(), center);
            const D9Vector& inverseMasses = accumulator->unk30;
            velocity.unk00 = accumulator->unk10;
            {
                D9Rotation rotation(accumulator->rotation());
                velocity.unk10.inverseRotate(rotation, accumulator->unk20);
                reinterpret_cast<::S_00cd4b60 *>(&(rotation))->FUN_00cd4b60();
                D9Matrix scaled;
                D9Vector sx, sy, sz;
                sx.broadcast(inverseMasses, 0);
                sy.broadcast(inverseMasses, 1);
                sz.broadcast(inverseMasses, 2);
                scaled.column(0).multiply(sx, rotation.column(0));
                scaled.column(1).multiply(sy, rotation.column(1));
                scaled.column(2).multiply(sz, rotation.column(2));
                reinterpret_cast<::MProduct *>(&(input.unk10))->FUN_00cd55b0((const ::MProduct &)(scaled), (const ::MProduct &)(accumulator->rotation()));
            }
            input.unk50 = &owner->unkf0;
            accumulator = accumulatorB;
            owner = ownerB;
        }
    }
    D9Equation equation;
    Basis basis;
    basis.setNormalBasis(contact.normal());
    solver->f40(contact, inputs[0], velocities[0], inputs[1], velocities[1]);
    FUN_00df5950(inputs[0], inputs[1], basis, equation);
    result = ::FUN_00df5f80((::ContactConstraint *)&(equation), (::ContactParams *)(parameters), (void *)&(velocities[0]), (void *)&(velocities[1]));
    solver->f44(contact, result, inputs[0], velocities[0], inputs[1], velocities[1]);
    accumulatorA->unk10 = velocities[0].unk00;
    if (ownerA->unke8 != 5)
    {
        ownerA->unk1b0 = velocities[0].unk00;
        ownerA->unk1c0 = velocities[0].unk10;
    }
    accumulatorB->unk10 = velocities[1].unk00;
    if (ownerB->unke8 != 5)
    {
        ownerB->unk1b0 = velocities[1].unk00;
        ownerB->unk1c0 = velocities[1].unk10;
    }
    {
        D9Shape* accumulator = accumulatorA;
        for (int index = 0; index < 2; accumulator = accumulatorB, ++index)
            accumulator->unk20.rotate(accumulator->rotation(), velocities[index].unk10);
    }
}

// Moved from hkpsimplecollisionresponse_rtm_variant.cpp (VEGAS-15).
#include "fnv/symbols_simd.h"

class Scalar
{
    __m128 value;

  public:
    Scalar()
    {}
    Scalar(const __m128& x) : value(x)
    {}
    Scalar(float x)
    {
        value = _mm_load_ss(&x);
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline const __m128& get() const
    {
        return value;
    }
};

class Vector
{
  public:
    __m128 q;
    __forceinline Vector()
    {}
    __forceinline Vector(const Vector& x) : q(x.q)
    {}
    __forceinline Vector(const __m128& x) : q(x)
    {}
    __forceinline void operator=(const Vector& x)
    {
        q = x.q;
    }
    __forceinline void operator=(const __m128& x)
    {
        q = x;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&q)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&q)[i];
    }
    __forceinline void zero()
    {
        q = _mm_setzero_ps();
    }
    __forceinline void subtract(const Vector& a, const Vector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void scale(const Scalar& a)
    {
        q = _mm_mul_ps(a.splat(), q);
    }
    __forceinline void product(const Scalar& a, const Vector& b)
    {
        q = _mm_mul_ps(a.splat(), b.q);
    }
    __forceinline void interpolate(const Vector& a, const Vector& b, const Scalar& t)
    {
        __m128 f = t.splat();
        __m128 inv = _mm_sub_ps(::DAT_010ec7f0, f);
        q = _mm_add_ps(_mm_mul_ps(inv, a.q), _mm_mul_ps(f, b.q));
    }
    __forceinline Scalar dot(const Vector& b) const
    {
        __m128 squares = _mm_mul_ps(q, b.q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares);
        return _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), xy);
    }
    __forceinline Scalar inverseLength() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 squared = dot(*this).get();
        const __m128 mask = _mm_cmpeq_ss(squared, zero);
        const __m128 rough = _mm_rsqrt_ss(squared);
        const __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, rough), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, rough), rough)));
        return _mm_andnot_ps(mask, refined);
    }
    __forceinline void normalize()
    {
        __m128 inv = inverseLength().splat();
        q = _mm_mul_ps(inv, q);
    }
    __forceinline void cross(const Vector& a, const Vector& b)
    {
        const __m128 qa = a.q;
        const __m128 qb = b.q;
        __m128 forward = _mm_mul_ps(_mm_shuffle_ps(qa, qa, 0xc9), _mm_shuffle_ps(qb, qb, 0xd2));
        __m128 reverse = _mm_mul_ps(_mm_shuffle_ps(qa, qa, 0xd2), _mm_shuffle_ps(qb, qb, 0xc9));
        q = _mm_sub_ps(forward, reverse);
    }
};
struct Matrix
{
    Vector col0, col1, col2;
    __forceinline Vector& column(int i)
    {
        return (&col0)[i];
    }
};
struct Transform
{
    Matrix rotation;
    Vector translation;
};
struct Sweep
{
    Vector center0, center1, rotation0, rotation1, localCenter;
    __forceinline float inverseTime() const
    {
        return center1(3);
    }
    __forceinline float fraction(float t) const
    {
        float f = (t - center0(3)) * inverseTime();
        return f;
    }
};
struct MotionState
{
    Transform transform;
    Sweep swept;
    Vector deltaAngle;
    float radius;
    unsigned short dampingLinear, dampingAngular;
    float timeFactor;
    unsigned int packedRotation;
};
struct Input
{
    Vector relative;
    Matrix inertia;
    Vector inverseMass;
    const Transform* transform;
};
struct Velocity
{
    Vector linear, angular;
};
struct AlignedDynamicArray
{
    Matrix jacobian, inverseJacobian;
    Vector inverseMass;
    float mass;
    const Transform* transform;
};
struct Constraint
{
    AlignedDynamicArray body0, body1;
    Matrix basis, inverseMass, mass;
};
struct Point
{
    Vector position, normal;
    __forceinline const Vector& pos() const
    {
        return position;
    }
    __forceinline const Vector& dir() const
    {
        return normal;
    }
};
struct Params
{
    float friction, restitution, maxImpulse, externalVelocity, extraVelocity, extraSlope;
    unsigned char breached;
};
struct Result
{
    float impulse, velocityA, velocityB;
};
struct RefObject
{
    virtual void slot00();
    unsigned short memorySize, referenceCount;
};
struct Motion : RefObject
{
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void inverseInertia(Matrix&) const;
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void setLinear(const Vector&);
    virtual void setAngular(const Vector&);
    unsigned char type, counter;
    unsigned short inactive0, inactive1;
    MotionState state;
    Vector inverseMass, linear, angular;
    __forceinline const Transform& transform() const
    {
        return state.transform;
    }
    __forceinline MotionState* motionState()
    {
        return &state;
    }
    __forceinline const Vector& linearVelocity() const
    {
        return linear;
    }
    __forceinline const Vector& angularVelocity() const
    {
        return angular;
    }
};
struct Manager
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void begin(const Point&, Input&, Velocity&, Input&, Velocity&);
    virtual void end(const Point&, float, Input&, Velocity&, Input&, Velocity&);
};
extern "C" void __cdecl FUN_00df5950(const Input&, const Input&, const Matrix&, Constraint&);
extern "C" float __cdecl FUN_00df5f80(const Constraint&, Params&, Velocity&, Velocity&);
extern "C" void __cdecl FUN_00df5e80(const Constraint&, Velocity&, Velocity&, Vector&);

static __forceinline void centerAt(const MotionState& ms, float time, Vector& center)
{
    float f = ms.swept.fraction(time);
    center.interpolate(ms.swept.center0, ms.swept.center1, f);
}
static __forceinline void velocityOf(const MotionState& ms, Vector& linear, Vector& angular)
{
    linear.subtract(ms.swept.center1, ms.swept.center0);
    linear.scale(ms.swept.inverseTime());
    angular.product(ms.swept.inverseTime(), ms.deltaAngle);
}
static __forceinline float absolute(float f)
{
    return fabsf(f);
}
static __forceinline void perpendicular(const Vector& normal, Vector& tangent)
{
    int smallest = 0, left = 1, right = 2;
    float x = absolute(normal(0));
    float y = absolute(normal(1));
    float z = absolute(normal(2));
    if (y < x)
    {
        left = 0;
        smallest = 1;
        x = y;
    }
    if (z < x)
    {
        right = smallest;
        smallest = 2;
    }
    tangent.zero();
    tangent(left) = normal(right);
    tangent(right) = -normal(left);
}
static __forceinline void makeBasis(const Vector& normal, Matrix& basis)
{
    basis.column(0) = normal;
    perpendicular(normal, basis.column(1));
    basis.column(1).normalize();
    basis.column(2).cross(normal, basis.column(1));
}

// @fnv 0x00d9f250
extern "C" void __cdecl FUN_00d9f250(const Point& point, float time, Params& params, Motion* a, Motion* b, Manager* mgr,
                                     Result& result)
{
    Input ia;
    {
        ia.inverseMass = a->inverseMass;
        Vector center;
        centerAt(*a->motionState(), time, center);
        ia.relative.subtract(point.pos(), center);
        a->inverseInertia(ia.inertia);
        ia.transform = &a->transform();
    }
    Input ib;
    {
        ib.inverseMass = b->inverseMass;
        Vector center;
        centerAt(*b->motionState(), time, center);
        ib.relative.subtract(point.pos(), center);
        b->inverseInertia(ib.inertia);
        ib.transform = &b->transform();
    }
    Velocity va, vb;
    va.linear = a->linearVelocity();
    va.angular = a->angularVelocity();
    vb.linear = b->linearVelocity();
    vb.angular = b->angularVelocity();
    Velocity oa, ob;
    velocityOf(*a->motionState(), oa.linear, oa.angular);
    velocityOf(*b->motionState(), ob.linear, ob.angular);
    Constraint info;
    Matrix basis;
    makeBasis(point.dir(), basis);
    mgr->begin(point, ia, va, ib, vb);
    FUN_00df5950(ia, ib, basis, info);
    result.impulse = FUN_00df5f80(info, params, va, vb);
    mgr->end(point, result.impulse, ia, va, ib, vb);
    {
        Vector pa, pb;
        FUN_00df5e80(info, oa, vb, pa);
        FUN_00df5e80(info, va, ob, pb);
        result.velocityA = pa(0);
        result.velocityB = pb(0);
    }
    if (a->type != 5)
    {
        a->setLinear(va.linear);
        a->setAngular(va.angular);
    }
    if (b->type != 5)
    {
        b->setLinear(vb.linear);
        b->setAngular(vb.angular);
    }
}

namespace ConstraintInit {
extern "C" void _ReadWriteBarrier(void);
typedef __m128 hkQuadReal;
typedef float hkReal;
namespace MathUtilities {
template <typename T> inline T max2(T x, T y)
{
    return x > y ? x : y;
}
}
namespace AlgorithmUtilities {
template <typename T> inline void swap(T& x, T& y)
{
    T t(x);
    x = y;
    y = t;
}
}

class RealLane
{
  public:
    hkQuadReal q;
    RealLane()
    {}
    RealLane(const hkQuadReal& v) : q(v)
    {}
    RealLane(float x)
    {
        q = _mm_load_ss(&x);
    }
    const hkQuadReal& quad() const
    {
        return q;
    }
    hkQuadReal spread() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
static __forceinline RealLane operator/(const RealLane& a, const RealLane& b)
{
    return _mm_div_ss(a.quad(), b.quad());
}
static __forceinline void maximumLane(const RealLane& a, const RealLane& b, RealLane& result)
{
    result = _mm_max_ps(a.quad(), b.quad());
}

class hkMatrix3;
class hkVector4
{
  public:
    hkQuadReal m_vComponents;

    void cofactor(const hkVector4& b, const hkVector4& a)
    {
        hkQuadReal p = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                  _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        hkQuadReal n = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                  _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(p, n);
    }
    RealLane inner3(const hkVector4& v) const
    {
        hkQuadReal terms = _mm_mul_ps(m_vComponents, v.m_vComponents);
        hkQuadReal xy = _mm_add_ss(_mm_shuffle_ps(terms, terms, 0x55), terms);
        return _mm_add_ss(_mm_shuffle_ps(terms, terms, 0xaa), xy);
    }
    void scaled(const hkQuadReal& scale, const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(scale, v.m_vComponents);
    }

    hkReal& operator()(int i)
    {
        return ((hkReal*)&m_vComponents)[i];
    }
    const hkReal& operator()(int i) const
    {
        return ((const hkReal*)&m_vComponents)[i];
    }
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    void add4(const hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    void setCross(const hkVector4& v0, const hkVector4& v1)
    {
        const hkQuadReal b = v1.m_vComponents;
        const hkQuadReal a = v0.m_vComponents;
        m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                                   _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
    }
    inline void _setMul3(const hkMatrix3& r, const hkVector4& v);
};
class hkMatrix3
{
  public:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    const hkVector4& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    hkReal& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }
    void operator=(const hkMatrix3& m)
    {
        m_kColumn0 = m.m_kColumn0;
        m_kColumn1 = m.m_kColumn1;
        m_kColumn2 = m.m_kColumn2;
    }
    void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
    void addTo(hkMatrix3& dst) const
    {
        dst.m_kColumn0.m_vComponents = _mm_add_ps(dst.m_kColumn0.m_vComponents, m_kColumn0.m_vComponents);
        dst.m_kColumn1.m_vComponents = _mm_add_ps(dst.m_kColumn1.m_vComponents, m_kColumn1.m_vComponents);
        dst.m_kColumn2.m_vComponents = _mm_add_ps(dst.m_kColumn2.m_vComponents, m_kColumn2.m_vComponents);
    }
    __forceinline void SetProduct(const hkMatrix3& a, const hkMatrix3& b)
    {
        const hkQuadReal c0 = a.m_kColumn0.m_vComponents;
        const hkQuadReal c1 = a.m_kColumn1.m_vComponents;
        const hkQuadReal c2 = a.m_kColumn2.m_vComponents;
        for (int i = 2; i >= 0; i--)
        {
            const hkQuadReal t = b.getColumn(i).m_vComponents;
            const hkQuadReal xb = _mm_shuffle_ps(t, t, 0x00);
            const hkQuadReal yb = _mm_shuffle_ps(t, t, 0x55);
            const hkQuadReal zb = _mm_shuffle_ps(t, t, 0xaa);
            getColumn(i).m_vComponents =
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(xb, c0), _mm_mul_ps(yb, c1)), _mm_mul_ps(zb, c2));
        }
    }
    __forceinline void setMul2(const hkMatrix3& a, const hkMatrix3& b)
    {
        const hkQuadReal& c1 = a.getColumn(1).m_vComponents;
        const hkQuadReal& c0 = a.getColumn(0).m_vComponents;
        const hkQuadReal& c2 = a.getColumn(2).m_vComponents;

        for (int i = 2; i >= 0; i--)
        {
            hkQuadReal t = b.getColumn(i).m_vComponents;
            hkQuadReal x = _mm_shuffle_ps(t, t, 0x00);
            hkQuadReal p = _mm_mul_ps(c0, x);
            hkQuadReal y = _mm_shuffle_ps(t, t, 0x55);
            hkQuadReal q = _mm_mul_ps(c1, y);
            hkQuadReal z = _mm_shuffle_ps(t, t, 0xaa);
            hkQuadReal w = _mm_mul_ps(c2, z);
            getColumn(i).m_vComponents = _mm_add_ps(_mm_add_ps(p, q), w);
        }
    }
    void transpose()
    {
        AlgorithmUtilities::swap(m_kColumn1(0), m_kColumn0(1));
        AlgorithmUtilities::swap(m_kColumn2(0), m_kColumn0(2));
        AlgorithmUtilities::swap(m_kColumn2(1), m_kColumn1(2));
    }
};
inline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkQuadReal t = v.m_vComponents;
    hkQuadReal xb = _mm_shuffle_ps(t, t, 0x00);
    hkQuadReal r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, xb);
    hkQuadReal yb = _mm_shuffle_ps(t, t, 0x55);
    hkQuadReal r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, yb);
    hkQuadReal zb = _mm_shuffle_ps(t, t, 0xaa);
    hkQuadReal r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, zb);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
static __forceinline hkQuadReal hkCross(const hkQuadReal& a, const hkQuadReal& b)
{
    const hkQuadReal cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    const hkQuadReal cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}
extern const double DAT_010da2b0;
extern const double DAT_010da2a8;
extern const float DAT_010da2a0;
struct BodyInput
{
    hkVector4 m_r;
    hkMatrix3 m_kInverseInertiaMatrix;
    hkVector4 m_vel;
    int m_50;
};
struct BodyResult
{
    hkMatrix3 m_pJacobian;
    hkMatrix3 m_ij;
    hkVector4 m_vel;
    hkReal m_fViscosityFriction;
    int m_74;
    int unk78;
    int unk7C;
};
struct SolverResult
{
    BodyResult m_apEntities[2];
    hkMatrix3 m_axes;
    hkMatrix3 m_kFirstMatrix;
    hkMatrix3 m_kSecondMatrix;
};
static __forceinline hkQuadReal hkDot3q(const hkQuadReal& a, const hkQuadReal& b)
{
    const hkQuadReal x2 = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
}
static __forceinline void inverseSymmetric(const hkMatrix3& m, float eps, hkMatrix3& inv)
{

    const hkVector4& central = m.getColumn(0);
    hkVector4 r0;
    r0.cofactor(m.getColumn(2), m.getColumn(1));
    hkVector4 r1;
    r1.cofactor(central, m.getColumn(2));
    hkVector4 r2;
    r2.cofactor(m.getColumn(1), central);
    RealLane minimum(eps * eps * eps);
    RealLane determinant = central.inner3(r0);
    maximumLane(determinant, minimum, determinant);
    RealLane inverse = reinterpret_cast<const RealLane&>((*reinterpret_cast<__m128 *>(&::DAT_010c7170))) / determinant;
    hkQuadReal factor = inverse.spread();
    inv.getColumn(0).scaled(factor, r0);
    inv.getColumn(1).scaled(factor, r1);
    inv.getColumn(2).scaled(factor, r2);
}
// @fnv 0x00df5950
extern "C" void __cdecl FUN_00df5950(const BodyInput* bodyA, const BodyInput* bodyB, const hkMatrix3& axes,
                                     SolverResult* out)
{
    hkReal sumInvMass = bodyA->m_vel(3) + bodyB->m_vel(3);
    out->m_kFirstMatrix.setZero();
    out->m_kFirstMatrix(0, 0) = sumInvMass;
    out->m_kFirstMatrix(1, 1) = sumInvMass;
    out->m_kFirstMatrix(2, 2) = sumInvMass;
    out->m_axes = axes;
    const BodyInput* body = bodyA;
    for (int i = 0; i < 2; i++)
    {
        BodyResult& bo = out->m_apEntities[i];
        bo.m_pJacobian.m_kColumn0.setCross(body->m_r, axes.m_kColumn0);
        bo.m_pJacobian.m_kColumn1.setCross(body->m_r, axes.m_kColumn1);
        bo.m_pJacobian.m_kColumn2.setCross(body->m_r, axes.m_kColumn2);
        bo.m_ij.SetProduct(body->m_kInverseInertiaMatrix, bo.m_pJacobian);
        bo.m_pJacobian.transpose();
        hkMatrix3 tmp;
        tmp.setMul2(bo.m_pJacobian, bo.m_ij);
        tmp.addTo(out->m_kFirstMatrix);
        bo.m_vel = body->m_vel;
        bo.m_fViscosityFriction = 1.0f / MathUtilities::max2(body->m_vel(3), 1e-11f);
        bo.m_74 = body->m_50;
        body = bodyB;
    }
    hkMatrix3& m = out->m_kFirstMatrix;
    hkMatrix3& inv = out->m_kSecondMatrix;
    inverseSymmetric(m, 1e-11f, inv);
    _ReadWriteBarrier();
    hkMatrix3* __restrict mass = &m;
    hkReal a = (*mass)(0, 0);
    (*mass)(3, 0) = 1.0f / (a < DAT_010da2b0 ? 1e-11f : a);
    hkReal b = (*mass)(2, 2) * (*mass)(1, 1) - (*mass)(1, 2) * (*mass)(2, 1);
    (*mass)(3, 1) = 1.0f / (b < DAT_010da2a8 ? DAT_010da2a0 : b);
}

}
#include "generated/data/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse_rtm_variant.inc"
