
// src/havok/animation/ragdoll/utils/hkaragdollutils_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/ragdoll/utils/hkaragdollutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/ragdoll/utils/hkaragdollutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/utils/hkaragdollutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>
#include "fnv/decl/Cb0StringCopy.h"
#include "fnv/decl/FUN_00cb0a60.h"
#include "fnv/decl/FUN_00ce2510.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/decl/S_00ce5070_QsTransform.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cea000.h"
#include "fnv/symbols_00d74000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/symbols_01268000.h"
extern "C"
{
    int __cdecl FUN_00ce9db0(void*, void*);
    int __cdecl FUN_00ce9e90(void*);
}

// @fnv 0x00cea7c0
int __cdecl FUN_00cea7c0(void* p1, void* p2, void* p3)
{
    if (FUN_00cea030(p1, p2))
        return 1;
    if (FUN_00ce9db0(p2, p3))
        return 1;
    if (FUN_00ce9e90(p2))
        return 1;
    return 0;
}

struct Item
{
    int unk00[11];
    int unk2c;
};
struct Container
{
    int unk00[2];
    Item** items;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct Counter
{
    int unk00[12];
    int unk30;
};
void __cdecl FUN_00ce9fa0(Container* c, int value, Counter* counter);
struct Inner
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual int getSomething();
};
struct Obj
{
    char pad0[0xc];
    Inner* inner;
};
struct hkErrStream
{
    void* p1;
    void* p2;
    void* p3;
    hkErrStream(void* buf, int size) throw();
    ~hkErrStream() throw();
    hkErrStream& operator<<(const char* str) throw();
};
struct hkError
{
    virtual ~hkError() throw();
    virtual void unk0();
    virtual void unk1();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};
static bool IsSupportedRagdollConstraint(Obj* obj, bool reportError) throw();
void caller(Obj* obj);
struct SpawnedAllocator
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct SpawnedGlobal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};
SpawnedGlobal* __cdecl FUN_00c85750() throw();
struct SpawnedObject
{
    int unk00;
    unsigned short m_size04;
};
struct SourceRecord
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
    int m_i2c;
};
int __cdecl SpawnObjectFromRecord(SourceRecord* src);

#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
struct StringRef
{
    const char* text;
    StringRef() throw()
    {
        new ((void *)this) struct ::FUN_00cb0a60();
    }
};
struct Bone
{
    StringRef name;
    bool lockTranslation;
};
struct Quaternion
{
    __m128 value;
    __forceinline const __m128& getVector() const
    {
        return value;
    }
    __declspec(noinline) void FUN_00c66320(const Quaternion*, const Quaternion*) throw();
};

extern "C" void FUN_00ec408c(unsigned int);
void Quaternion::FUN_00c66320(const Quaternion* first, const Quaternion* second) throw()
{
    unsigned int cookie = ::__security_cookie;
    __m128 a = first->value;
    __m128 b = second->value;
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                              _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
    __m128 aw = _mm_shuffle_ps(a, a, 0xff);
    __m128 bw = _mm_shuffle_ps(b, b, 0xff);
    __m128 xyz = _mm_add_ps(_mm_add_ps(_mm_mul_ps(aw, b), cross), _mm_mul_ps(bw, a));
    __m128 product = _mm_mul_ps(a, b);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    __m128 scalar = _mm_sub_ps(product, _mm_shuffle_ps(sum, sum, 0));
    value = _mm_shuffle_ps(xyz, _mm_unpackhi_ps(xyz, scalar), 0xc4);
    FUN_00ec408c(cookie);
}
struct Transform
{
    __m128 translation;
    __forceinline const __m128& getTranslation() const
    {
        return translation;
    }
    Quaternion rotation;
    __m128 scale;
    __forceinline const __m128& getScale() const
    {
        return scale;
    }
};
struct SimdVector
{
    __m128 quad;
    __forceinline SimdVector()
    {}
    __forceinline SimdVector(__m128 inputValue) : quad(inputValue)
    {}
    __forceinline operator __m128() const
    {
        return quad;
    }
};
static __forceinline void composeTransforms(Transform& destination, const Transform& parent, const Transform& child)
{
    SimdVector qForward = parent.rotation.value;
    SimdVector wForward = _mm_shuffle_ps(qForward, qForward, 0xff);
    SimdVector vForward = child.translation;
    __m128 dotForward = _mm_mul_ps(vForward, qForward);
    __m128 dForward = _mm_add_ss(_mm_shuffle_ps(dotForward, dotForward, 0x55), dotForward);
    dForward = _mm_add_ss(_mm_shuffle_ps(dotForward, dotForward, 0xaa), dForward);
    __m128 crossForward =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(qForward, qForward, 0xc9), _mm_shuffle_ps(vForward, vForward, 0xd2)),
                   _mm_mul_ps(_mm_shuffle_ps(qForward, qForward, 0xd2), _mm_shuffle_ps(vForward, vForward, 0xc9)));
    __m128 tForward = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(wForward, wForward), DAT_010c71e0), vForward);
    crossForward = _mm_mul_ps(crossForward, wForward);
    tForward = _mm_add_ps(tForward, _mm_mul_ps(_mm_shuffle_ps(dForward, dForward, 0), qForward));
    tForward = _mm_add_ps(crossForward, tForward);
    destination.translation = _mm_add_ps(_mm_add_ps(tForward, tForward), parent.translation);
    ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(destination.rotation), (void *)(&parent.rotation), (const ::fnv_00c66320::__m128 *)(const ::Quaternion *)(&child.rotation), {});
    destination.scale = _mm_mul_ps(child.scale, parent.scale);
}
template <class T> struct Array
{
    T* data;
    int size;
    int capacity;
    Array() throw() : data(0), size(0), capacity(0x80000000)
    {}
    void reserve(SpawnedAllocator* allocator, int count) throw()
    {
        int available = capacity & 0x3fffffff;
        if (available < count)
        {
            int grown = available * 2;
            if (count >= grown)
                grown = count;
            ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(void *)(this), grown, sizeof(T));
        }
    }
    void reserve(int count) throw()
    {
        SpawnedGlobal* holder = FUN_00c85750();
        reserve(holder->m_pAllocator, count);
    }
    void resize(int count) throw()
    {
        reserve(count);
        size = count;
    }
    __forceinline void SetSizeAndGrow(int count) throw();
};
static __forceinline void destroyBones(Bone* bone, int count) throw()
{
    for (int i = 0; i < count; ++i)
    {
        ::FUN_00cb0c00((int)(bone));
        ++bone;
    }
}
static __forceinline void constructBones(Bone* bone, int count) throw()
{
    for (int i = 0; i < count; ++i, ++bone)
    {
        if (bone)
        {
            new ((void *)&(bone->name)) struct ::FUN_00cb0a60();
            bone->lockTranslation = false;
        }
    }
}
template <> __forceinline void Array<Bone>::SetSizeAndGrow(int count) throw()
{
    reserve(count);
    destroyBones(data + count, size - count);
    constructBones(data + size, count - size);
    size = count;
}
struct SkeletonHeader
{
    const void* vtable;
    unsigned short memorySize;
    unsigned short references;
    __forceinline SkeletonHeader() throw() : references(1), memorySize(0x48)
    {
        vtable = &(*reinterpret_cast<unsigned int *>(&::DAT_010c4dec));
    }
};
struct Skeleton : SkeletonHeader
{
    StringRef name;
    Array<short> parents;
    Array<Bone> bones;
    Array<Transform> pose;
    Array<StringRef> floatSlots;
    Array<int> localFrames;
    __forceinline Skeleton() throw()
    {}
    __forceinline void* operator new(unsigned int bytes)
    {
        SpawnedGlobal* holder = FUN_00c85750();
        SpawnedAllocator* allocator = holder->m_pAllocator;
        Skeleton* result = static_cast<Skeleton*>(allocator->allocate(bytes));
        result->memorySize = static_cast<unsigned short>(bytes);
        return result;
    }
};
struct RigidBody
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
    const char* name;
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    Transform transform;
};
struct BodyList
{
    RigidBody** data;
    int size;
    int capacity;
};
struct Constraint
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    RigidBody* parent;
};
struct ConstraintList
{
    Constraint** data;
    int size;
    int capacity;
};

// @fnv 0x00ceb2c0
Skeleton* __cdecl FUN_00ceb2c0(BodyList* bodies, ConstraintList* constraints) throw()
{
    Skeleton* result = new Skeleton;
    int count = bodies->size;
    result->bones.SetSizeAndGrow(count);
    result->parents.resize(count);
    result->pose.resize(count);
    for (int i = 0; i < count; ++i)
    {
        int parentIndex = -1;
        if (i)
        {
            RigidBody* parent = constraints->data[i - 1]->parent;
            for (int j = 0; j < i; ++j)
            {
                if (bodies->data[j] == parent)
                {
                    parentIndex = j;
                    break;
                }
            }
        }
        result->parents.data[i] = (short)parentIndex;
        RigidBody* body = bodies->data[i];
        Bone& currentBone = result->bones.data[i];
        if (parentIndex >= 0)
        {
            RigidBody* parent = bodies->data[parentIndex];
            Transform childPose, parentPose;
            reinterpret_cast<::S_00ce5070_QsTransform *>(&(childPose))->FUN_00ce5070((*(const ::S_00ce5070_Transform *)(&body->transform)));
            reinterpret_cast<::S_00ce5070_QsTransform *>(&(parentPose))->FUN_00ce5070((*(const ::S_00ce5070_Transform *)(&parent->transform)));
            Transform& output = result->pose.data[i];
            const __m128& q = parentPose.rotation.value;
            SimdVector w = _mm_shuffle_ps(q, q, 0xff);
            SimdVector v = parentPose.getTranslation();
            SimdVector dot = _mm_mul_ps(q, v);
            SimdVector d = _mm_add_ss(_mm_shuffle_ps(dot, dot, 0x55), dot);
            d = _mm_add_ss(_mm_shuffle_ps(dot, dot, 0xaa), d);
            __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)),
                                      _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9)));
            cross = _mm_mul_ps(cross, w);
            SimdVector t = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
            t = _mm_add_ps(t, _mm_mul_ps(_mm_shuffle_ps(d, d, 0), q));
            t = _mm_add_ps(cross, t);
            Transform inversePose;
            t = _mm_add_ps(t, t);
            t = _mm_xor_ps(t, DAT_010c44d0);
            inversePose.translation = t;
            inversePose.rotation.value = _mm_xor_ps(q, ::DAT_010c4c00);
            __m128 scale = parentPose.scale;
            __m128 scaleWithOne = _mm_shuffle_ps(scale, _mm_unpackhi_ps(scale, ::DAT_010c7170), 0xc4);
            __m128 reciprocal = _mm_rcp_ps(scaleWithOne);
            __m128 inverseScale = _mm_and_ps(_mm_sub_ps(_mm_add_ps(reciprocal, reciprocal),
                                                        _mm_mul_ps(_mm_mul_ps(reciprocal, scaleWithOne), reciprocal)),
                                             ::DAT_010c4c10);
            inversePose.scale = inverseScale;
            composeTransforms(output, inversePose, childPose);
        }
        else
        {
            reinterpret_cast<::S_00ce5070_QsTransform *>(&(result->pose.data[i]))->FUN_00ce5070((*(const ::S_00ce5070_Transform *)(&body->transform)));
        }
        const char* name = reinterpret_cast<const char*>(reinterpret_cast<unsigned int>(body->name) & ~1u);
        if (name)
            reinterpret_cast<::SStringPtr *>(&(currentBone.name))->FUN_00cb0c10(name);
        else
        {
            int buffer[128];
            hkErrStream stream(buffer, 512);
            reinterpret_cast<::SinkOwner *>((void *)&(const ::hkErrStream &)(stream))->FUN_00cc01c0("Rigid Body name could not be found");
            (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabbacc14, reinterpret_cast<const char*>(buffer), ".\\Utils\\hkaRagdollUtils.cpp",
                                  558);
        }
        currentBone.lockTranslation = i != 0;
    }
    if (result->bones.size > 0)
        reinterpret_cast<::Cb0StringCopy *>(&(result->name))->FUN_00cb0c30((*(const ::CB0StringPtr *)(result->bones.data)));
    return result;
}
