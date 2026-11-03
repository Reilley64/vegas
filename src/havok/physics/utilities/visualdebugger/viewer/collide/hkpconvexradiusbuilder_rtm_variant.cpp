// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_01268000.h"
namespace bounding_plane_rework {
struct Transform
{
    __m128 rotation0, rotation1, rotation2, translation;
};
struct __declspec(align(16)) BoundVector
{
    float x, y, z, w;
};
struct Bounds
{
    BoundVector minimum, maximum;
};
struct Shape
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void getBounds(const Transform*, float, Bounds*);
};
struct Allocator;
struct Holder
{
    int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
};
extern Holder* FUN_00c85750();
struct PlaneArray
{
    __m128* data;
    int size, capacity;
};
// @fnv 0x00de3200
static __declspec(noinline) void FUN_00de3200(Shape* shape, PlaneArray* planes, float radius)
{
    Bounds bounds;
    shape->getBounds(&(*reinterpret_cast<const ::bounding_plane_rework::Transform *>(&::DAT_01268370)), radius, &bounds);
    Holder* holder = FUN_00c85750();
    Allocator* allocationHeap = holder->allocator;
    int wanted = planes->size + 6;
    int capacity = planes->capacity & 0x3fffffff;
    if (capacity < wanted)
    {
        int doubled = capacity + capacity;
        if (wanted < doubled)
            wanted = doubled;
        ::FUN_00c908c0((::SpawnedObject *)(allocationHeap), (::SpawnedArray *)(planes), wanted, 16);
    }
    planes->size += 6;
    int start = planes->size;
    planes->data[start - 6] = _mm_setr_ps(1.0f, 0.0f, 0.0f, -bounds.maximum.x);
    planes->data[start - 5] = _mm_setr_ps(0.0f, 1.0f, 0.0f, -bounds.maximum.y);
    planes->data[start - 4] = _mm_setr_ps(0.0f, 0.0f, 1.0f, -bounds.maximum.z);
    planes->data[start - 3] = _mm_setr_ps(-1.0f, 0.0f, 0.0f, bounds.minimum.x);
    planes->data[start - 2] = _mm_setr_ps(0.0f, -1.0f, 0.0f, bounds.minimum.y);
    planes->data[start - 1] = _mm_setr_ps(0.0f, 0.0f, -1.0f, bounds.minimum.z);
}
extern "C" void planeBuilderWitness(Shape* shape, PlaneArray* planes, float radius)
{
    FUN_00de3200(shape, planes, radius);
}

}
