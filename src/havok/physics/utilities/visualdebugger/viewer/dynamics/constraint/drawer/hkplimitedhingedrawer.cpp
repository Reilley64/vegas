
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkplimitedhingedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkplimitedhingedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/hkpConstraintDrawer.h"
#include "havok/hkUlong.h"
#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/DE44C0Object.h"
#include "fnv/decl/FUN_00de4530Owner.h"
#include "fnv/decl/SetupTarget.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cab000.h"
extern const double DAT_01097800;
struct Matrix;
struct __declspec(align(16)) Vector
{
    __m128 value;
    void FUN_00c7f640(const Matrix*, const Vector*);
    void FUN_00c7f700(const void*, const Vector*);
};
struct AxisPair
{
    Vector axis, other;
};
struct Matrix
{
    Vector x, y, z, t;
};
struct Shape
{
};
struct Array
{
    Shape** data;
    int size;
    int capacity;
};
struct LineScratch
{
    Vector end, base, axis;
};
union DrawWork
{
    LineScratch line;
    Array shapes;
};
struct Display
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
    virtual void line(const Vector*, const Vector*, unsigned, hkUlong, int);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void geometry(Array*, unsigned, hkUlong, int);
};
struct DisplayContext
{
    int a, b, c, d;
};
struct Data
{
    Vector v00, v10, v20, v30, v40, v50, v60, v70, v80, v90, va0, vb0;
    char c0, c1, enabled, c3;
    float minimum, maximum;
};
struct Input
{
    int a, b, c;
    Data* data;
};
struct Viewer
{
    float length, scale;
    int f08, f0c, f10, f14, flags;
    float multiplier;
    int f20, f24, f28, f2c, f30, f34, f38, f3c;
    Vector pivot, origin;
    Vector m60, m70, m80, m90, ma0, mb0;
    DisplayContext context;
    Shape shape;
    void FUN_00de7a70(Input*, Display*, hkUlong, int);
};
__forceinline __m128 broadcast(float value)
{
    float low = value;
    return _mm_load_ps1(&low);
}
__forceinline __m128 broadcastScalar(float value)
{
    float low = value;
    __m128 v = _mm_load_ss(&low);
    return _mm_shuffle_ps(v, v, 0);
}
// Draws lines via display->line and, when data->enabled and the range is small, a shape via display->geometry, using vectors transformed from input->data.
// @fnv 0x00de7a70
void Viewer::FUN_00de7a70(Input* input, Display* display, hkUlong id, int tag)
{
    Data* data = input->data;
    reinterpret_cast<::CpuObject *>(&(context))->FUN_00e10a10((display));
    Matrix first, second;
    reinterpret_cast<hkpConstraintDrawer*>(this)->FUN_00de47e0(input, &first, &second);
    origin.FUN_00c7f640(&first, &data->v90);
    pivot.FUN_00c7f640(&second, &data->v50);
    reinterpret_cast<::FUN_00de4530Owner *>(this)->FUN_00de4530(id, tag);
    reinterpret_cast<::DE44C0Object *>(this)->FUN_00de44c0(id, tag);
    AxisPair axes;
    DrawWork scratch;
    axes.axis.FUN_00c7f700(&m90, &data->v60);
    axes.other.FUN_00c7f700(&m90, &data->v80);
    display->line(&pivot, &origin, 0xffff0000, id, tag);
    {
        float distance = length * multiplier;
        scratch.line.axis.value =
            _mm_add_ps(origin.value, _mm_mul_ps(broadcastScalar(0.75 * distance), axes.axis.value));
        scratch.line.base.value =
            _mm_add_ps(origin.value, _mm_mul_ps(broadcastScalar(DAT_01097800 * distance), axes.axis.value));
        display->line(&scratch.line.base, &scratch.line.axis, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), id, tag);
    }
    {
        scratch.line.axis.FUN_00c7f700(&m60, &data->v20);
        float distance = length * multiplier;
        scratch.line.base.value =
            _mm_add_ps(pivot.value, _mm_mul_ps(broadcastScalar(0.75 * distance), scratch.line.axis.value));
        scratch.line.end.value =
            _mm_add_ps(pivot.value, _mm_mul_ps(broadcastScalar(DAT_01097800 * distance), scratch.line.axis.value));
        display->line(&scratch.line.end, &scratch.line.base, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), id, tag);
    }
    if (data->enabled)
    {
        float high = data->maximum, low = data->minimum;
        if (high - low < 100000000376832.0)
        {
            reinterpret_cast<::SetupTarget *>(&(shape))->FUN_00de4950(scale * multiplier, low, high, flags, (*(const ::Vec4 *)(&origin)), (*(const ::Vec4 *)(&axes.axis)), (*(const ::Vec4 *)(&axes.other)));
            scratch.shapes.data = 0;
            scratch.shapes.size = 0;
            scratch.shapes.capacity = 0x80000000;
            hkMemoryRouter* router = &hkMemoryRouter::getInstance();
            hkMemoryAllocator* allocator = router->m_heap;
            int capacity = scratch.shapes.capacity & 0x3fffffff;
            if (capacity < 1)
            {
                capacity *= 2;
                if (capacity <= 1)
                    capacity = 1;
                ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(::Array *)(&scratch.shapes), capacity, 4);
            }
            scratch.shapes.size = 1;
            scratch.shapes.data[0] = &shape;
            display->geometry(&scratch.shapes, 0xffffffff, id, tag);
            router = &hkMemoryRouter::getInstance();
            allocator = router->m_heap;
            scratch.shapes.size = 0;
            if ((scratch.shapes.capacity & 0x80000000) == 0)
                allocator->bufFree(scratch.shapes.data, (scratch.shapes.capacity & 0x3fffffff) * 4);
        }
    }
    {
        float distance = length * multiplier;
        scratch.line.base.value = origin.value;
        scratch.line.end.value = scratch.line.base.value;
        scratch.line.end.value =
            _mm_add_ps(scratch.line.end.value, _mm_mul_ps(broadcastScalar(0.5 * distance), axes.other.value));
        display->line(&scratch.line.base, &scratch.line.end, 0xffffff00, id, tag);
    }
    {
        scratch.line.axis.FUN_00c7f700(&m60, &data->v40);
        float distance = length * multiplier;

        float magnitude = float(0.75 * distance);
        __m128 squared = _mm_mul_ps(scratch.line.axis.value, scratch.line.axis.value);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
        sum = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), sum);
        __m128 inv = _mm_rsqrt_ss(sum);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 half = _mm_set_ss(0.5f);
        __m128 factor = _mm_mul_ss(_mm_mul_ss(half, inv), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(sum, inv), inv)));
        factor = _mm_andnot_ps(_mm_cmpeq_ss(sum, zero), factor);
        scratch.line.axis.value = _mm_mul_ps(_mm_shuffle_ps(factor, factor, 0), scratch.line.axis.value);
        scratch.line.base.value = pivot.value;
        scratch.line.end.value = pivot.value;
        scratch.line.end.value =
            _mm_add_ps(scratch.line.end.value, _mm_mul_ps(broadcastScalar(magnitude), scratch.line.axis.value));
        display->line(&scratch.line.base, &scratch.line.end, 0xffffff00, id, tag);
    }
}

#include "generated/data/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkplimitedhingedrawer.inc"
