
// src/havok/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <xmmintrin.h>
#include <new>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00c9e340.h"
#include "fnv/decl/FUN_00cf5640.h"
#include "fnv/decl/FUN_00d73400_cls.h"
#include "fnv/decl/Standin_2.h"
#include "fnv/decl/cf5990_TransformShape.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d73000.h"
#include "fnv/symbols_00d74000.h"
#include "fnv/symbols_01268000.h"
struct ShapeD738;
struct EntryD738;
struct ShapeRefEntity
{
    void* m_vtable;
    int m_memSizeAndFlags;
    void* m_world;
    void* m_userData;
    const ShapeD738* m_shape;
};

struct ShapeRefArray
{
    ShapeRefEntity** refs;
    int count;
};

struct ShapeData
{
    EntryD738* m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void FUN_00d738f0(const ShapeD738*);
    void FUN_00d74a20();
    ShapeData* FUN_00d74b20(ShapeRefArray* refs);
};

// Resets the three fields, forwards each ref's value at offset 0x10 to FUN_00d738f0, then calls FUN_00d74a20 and returns this.
// @fnv 0x00d74b20
ShapeData* ShapeData::FUN_00d74b20(ShapeRefArray* refs)
{
    m_kPointA = nullptr;
    m_kPointB = 0;
    m_iThirdValue = 0x80000000;
    for (int i = 0; i < refs->count; ++i)
        FUN_00d738f0(refs->refs[i]->m_shape);
    FUN_00d74a20();
    return this;
}

// RunContextOperation — __cdecl (caller pops its arguments).
//
// Builds a 12-byte context object on the stack, initializes it to
// (0, 0, 0x80000000), runs its setup pass, resets it, then delegates to the
// helper FUN_00d739f0 and stores its result through the caller's out pointer.
// Finally the context's cleanup pass runs and the function returns 0.

struct FUN_00d74420_Context
{
    int m_kPointA;  // +0x00
    int m_kPointB;  // +0x04
    int m_iThirdValue;  // +0x08, initialized to 0x80000000
    void FUN_00d74aa0();
};


// @fnv 0x00d74420
int RunContextOperation(const ::hkpShape* aiArg1, const ::Options* aiArg2, ::Results* aiArg3, const ::hkpShape** piOut)
{
    FUN_00d74420_Context ctx;
    ctx.m_kPointA = 0;
    ctx.m_kPointB = 0;
    ctx.m_iThirdValue = 0x80000000;
    reinterpret_cast<::ShapeData *>(&(ctx))->FUN_00d738f0(reinterpret_cast<const ShapeD738*>(aiArg1));
    reinterpret_cast<::ShapeData *>(&(ctx))->FUN_00d74a20();
    *piOut = ::FUN_00d739f0(aiArg1, *aiArg2, *reinterpret_cast<::D749Table *>(&ctx), *aiArg3);
    ctx.FUN_00d74aa0();
    return 0;
}




template <class T> __forceinline void constructWithCopyD748(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayD748
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD748() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayD748() throw()
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&kAlloc), (::AudioStream *)(void *)(this), sizeof(T));
        constructWithCopyD748(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpEntityD748;


// Appends pkEntity to a local hkArrayD748 and forwards it with iA and iB to RemapCollisionShapes, returning its result.
// @fnv 0x00d748d0
int __cdecl FUN_00d748d0(hkpEntityD748* pkEntity, void* iA, ::hkShapeOutputD748* iB) throw()
{
    hkArrayD748<hkpEntityD748*> kEntities;
    kEntities.AddBack(pkEntity);
    return ::RemapCollisionShapes((::hkShapeEntryArrayD748 *)&(kEntities), iA, iB);
}

struct D749Entry
{
    const void* m_key0;
    const void* m_uiFilterValue;
    int m_key1;
};

struct FUN_00c90510_Obj
{
};

class hkReferencedObject
{
};

class D749Table
{
  public:
    D749Entry* m_data;
    int m_uiItemCount;

    int SetEntryValue(const void* key, const void* value);
};

// Scans the table for an entry matching key in either key field, releases the old value, stores the new value, and returns 0 on success or 1 if not found.
// @fnv 0x00d749c0
int D749Table::SetEntryValue(const void* key, const void* value)
{
    int i = 0;
    if (m_uiItemCount > 0)
    {
        do
        {
            if (m_data[i].m_key0 == key || m_data[i].m_uiFilterValue == key)
                goto found;
            ++i;
        } while (i < m_uiItemCount);
    }
    return 1;
found:
    reinterpret_cast<::FUN_00c90510_class *>((((FUN_00c90510_Obj*)value)))->FUN_00c90510();
    const void* pOldValue = m_data[i].m_uiFilterValue;
    if (pOldValue)
        reinterpret_cast<::hkReferencedObjectC905 *>((((hkReferencedObject*)pOldValue)))->FUN_00c905b0();
    m_data[i].m_uiFilterValue = value;
    return 0;
}

struct FUN_00d74980_Class
{
    D749Entry* refs;
    int count;
    int FindMappedValue(const void* value);
};

// Scans the refs array in groups of three and returns the third entry of the first group whose first or second entry equals value, otherwise 0.
// @fnv 0x00d74980
int FUN_00d74980_Class::FindMappedValue(const void* value)
{
    for (int i = 0; i < count; ++i)
    {
        if (refs[i].m_key0 == value || refs[i].m_uiFilterValue == value)
            return refs[i].m_key1;
    }

    return 0;
}

#include "fnv/symbols_simd.h"

struct Shp_d74480;
namespace fnvc_adapt {
}
struct Shp_d74480
{
    void* vtbl;
    unsigned short GetAllocationSize;
    unsigned short refCount;
    int unk08;
    int type;
};
struct CacheEnt_d74480
{
    Shp_d74480* source;
    Shp_d74480* replacement;
    int unk08;
};
struct Cache_d74480
{
    CacheEnt_d74480* data;
    int count;
    int capacity;
};
struct ChildInfo_d74480
{
    Shp_d74480* shape;
    int unk04;
    int unk08;
    int unk0c;
};
struct Cont_d74480
{
    virtual void unk00();
    virtual int count();
    int unk04;
};
struct List_d74480 : Shp_d74480
{
    Cont_d74480 container;
    ChildInfo_d74480* children;
};
struct Convex_d74480 : Shp_d74480
{
    float radius;
    int unk14;
    Shp_d74480* child;
    int unk1c;
    __m128 translation;
};
struct Xform_d74480 : Shp_d74480
{
    int unk10;
    Shp_d74480* child;
    int unk18;
    int unk1c;
    __m128 unk20;
    __m128 transform;
};
extern int DAT_010d0e5c;
struct Arr_d74480
{
    Shp_d74480** data;
    int size;
    int capacity;
};

// Recursively processes a shape tree, replacing nodes with cached or newly allocated equivalents and storing results in the cache.
// @fnv 0x00d74480
Shp_d74480* __cdecl ProcessShape(Shp_d74480* shape, void* context, Cache_d74480* cache, void* settings)
{
    for (int i = 0; i < cache->count; ++i)
    {
        if (cache->data[i].source == shape)
        {
            Shp_d74480* found = cache->data[i].replacement;
            if (found)
            {
                reinterpret_cast<::FUN_00c90510_class *>((found))->FUN_00c90510();
                return found;
            }
            break;
        }
    }
    Shp_d74480* result;
    switch (shape->type)
    {
    case 9: {
        List_d74480* list = (List_d74480*)shape;
        int count = list->container.count();
        Arr_d74480 childShapes;
        childShapes.data = 0;
        childShapes.size = 0;
        childShapes.capacity = 0x80000000;
        bool bUnchanged = true;
        for (int i = 0; i < count; ++i)
        {
            Shp_d74480* pChild = list->children[i].shape;
            Shp_d74480* n = ProcessShape(pChild, context, cache, settings);
            hkMemoryRouter* pRouter = &hkMemoryRouter::getInstance();
            if (childShapes.size == (childShapes.capacity & 0x3fffffff))
                ::ResizeAudioStream((::AudioAllocator *)(::hkMemoryAllocator *)(&pRouter->heap()), (::AudioStream *)(void *)(&childShapes), sizeof(Shp_d74480*));
            childShapes.data[childShapes.size++] = n;
            if (n != pChild)
                bUnchanged = false;
        }
        if (bUnchanged)
        {
            for (int i = 0; i < count; ++i)
                reinterpret_cast<::hkReferencedObjectC905 *>((childShapes.data[i]))->FUN_00c905b0();
            reinterpret_cast<::FUN_00c90510_class *>((shape))->FUN_00c90510();
            hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
            childShapes.size = 0;
            if ((childShapes.capacity & 0x80000000) == 0)
                a.bufFree(childShapes.data, (childShapes.capacity & 0x3fffffff) * sizeof(Shp_d74480*));
            result = shape;
            break;
        }
        Shp_d74480* v = (Shp_d74480*)hkMemoryRouter::getInstance().heap().blockAlloc(0x70);
        v->GetAllocationSize = 0x70;
        v = ((::Shp_d74480 *)(new ((void *)(v)) ::FUN_00cf5640(childShapes.data, count, 1)));
        for (int i = 0; i < count; ++i)
            reinterpret_cast<::hkReferencedObjectC905 *>((childShapes.data[i]))->FUN_00c905b0();
        reinterpret_cast<::D749Table *>((cache))->SetEntryValue(shape, v);
        result = v;
        hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
        childShapes.size = 0;
        if ((childShapes.capacity & 0x80000000) == 0)
            a.bufFree(childShapes.data, (childShapes.capacity & 0x3fffffff) * sizeof(Shp_d74480*));
        break;
    }
    case 15: {
        Xform_d74480* xf = (Xform_d74480*)shape;
        Shp_d74480* pChild = xf->child;
        Shp_d74480* v = ProcessShape(pChild, context, cache, settings);
        Shp_d74480* n = v;
        if (pChild == v)
        {
            reinterpret_cast<::hkReferencedObjectC905 *>((v))->FUN_00c905b0();
            v = shape;
            reinterpret_cast<::FUN_00c90510_class *>((shape))->FUN_00c90510();
        }
        else
        {
            Shp_d74480* mem = (Shp_d74480*)hkMemoryRouter::getInstance().heap().blockAlloc(0x70);
            mem->GetAllocationSize = 0x70;
            v = ((::Shp_d74480 *)(reinterpret_cast<::cf5990_TransformShape *>((mem))->FUN_00cf5990((::hkpShape *)(n), (*(const ::hkTransform *)(&xf->transform)))));
            reinterpret_cast<::hkReferencedObjectC905 *>((n))->FUN_00c905b0();
            reinterpret_cast<::D749Table *>((cache))->SetEntryValue(shape, v);
        }
        result = ((::Shp_d74480 *)(::FUN_00d739f0((const ::hkpShape *)(v), (*(const ::Options *)(context)), (*(::D749Table *)(cache)), (*(::Results *)(settings)))));
        reinterpret_cast<::hkReferencedObjectC905 *>((v))->FUN_00c905b0();
        break;
    }
    case 12: {
        Convex_d74480* cv = (Convex_d74480*)shape;
        Shp_d74480* pChild = cv->child;
        Shp_d74480* v = ProcessShape(pChild, context, cache, settings);
        Shp_d74480* n = v;
        if (pChild == v)
        {
            reinterpret_cast<::hkReferencedObjectC905 *>((v))->FUN_00c905b0();
            v = shape;
            reinterpret_cast<::FUN_00c90510_class *>((shape))->FUN_00c90510();
        }
        else
        {
            Shp_d74480* mem = (Shp_d74480*)hkMemoryRouter::getInstance().heap().blockAlloc(0x60);
            mem->GetAllocationSize = 0x60;
            v = ((::Shp_d74480 *)(reinterpret_cast<::Standin *>((mem))->FUN_00d5d7a0((const ::hkpConvexShape *)(n), (*(const ::AlignedTransform *)(&cv->translation)), 1)));
            reinterpret_cast<::hkReferencedObjectC905 *>((n))->FUN_00c905b0();
            reinterpret_cast<::D749Table *>((cache))->SetEntryValue(shape, v);
        }
        result = ((::Shp_d74480 *)(::FUN_00d739f0((const ::hkpShape *)(v), (*(const ::Options *)(context)), (*(::D749Table *)(cache)), (*(::Results *)(settings)))));
        reinterpret_cast<::hkReferencedObjectC905 *>((v))->FUN_00c905b0();
        break;
    }
    case 11: {
        Convex_d74480* cv = (Convex_d74480*)shape;
        Shp_d74480* v;
        Shp_d74480* pChild = cv->child;
        Shp_d74480* n = ProcessShape(pChild, context, cache, settings);
        if (pChild == n)
        {
            reinterpret_cast<::hkReferencedObjectC905 *>((n))->FUN_00c905b0();
            v = shape;
            reinterpret_cast<::FUN_00c90510_class *>((shape))->FUN_00c90510();
        }
        else
        {
            Convex_d74480* pNewConvex = (Convex_d74480*)hkMemoryRouter::getInstance().heap().blockAlloc(0x30);
            pNewConvex->GetAllocationSize = 0x30;
            new ((void *)(pNewConvex)) ::FUN_00c9e340(11, ((Convex_d74480*)n)->radius, (::FUN_00d1df70 *)(n), 1);
            pNewConvex->vtbl = &DAT_010d0e5c;
            pNewConvex->translation = _mm_and_ps(cv->translation, DAT_010c4c10);
            pNewConvex->unk1c = 0;
            v = pNewConvex;
            reinterpret_cast<::hkReferencedObjectC905 *>((n))->FUN_00c905b0();
            reinterpret_cast<::D749Table *>((cache))->SetEntryValue(shape, v);
        }
        result = ((::Shp_d74480 *)(::FUN_00d739f0((const ::hkpShape *)(v), (*(const ::Options *)(context)), (*(::D749Table *)(cache)), (*(::Results *)(settings)))));
        reinterpret_cast<::hkReferencedObjectC905 *>((v))->FUN_00c905b0();
        break;
    }
    default:
        reinterpret_cast<::FUN_00c90510_class *>((shape))->FUN_00c90510();
        result = shape;
        break;
    }
    return result;
}

struct hkShapeEntryD748
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkReferencedObject* m_pCollisionShape;
};

struct hkShapeEntryArrayD748
{
    hkShapeEntryD748** m_data;
    int m_iElementCount;
};

struct hkShapeOutputD748
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct hkShapeMapD748
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void FUN_00d74aa0() throw();
};


// Remaps each collision shape in refs via ProcessShape, storing results back into the entries and releasing the old references.
// @fnv 0x00d74850
int __cdecl RemapCollisionShapes(hkShapeEntryArrayD748* refs, void* context, hkShapeOutputD748* out)
{
    reinterpret_cast<::FUN_00d73400_cls *>((out))->FUN_00d73400();
    hkShapeMapD748 map;
    reinterpret_cast<::ShapeData *>(&(map))->FUN_00d74b20((::ShapeRefArray *)(refs));
    for (int i = 0; i < refs->m_iElementCount; i++)
    {
        hkShapeEntryD748* entry = refs->m_data[i];
        hkReferencedObject* shape = entry->m_pCollisionShape;
        hkReferencedObject* pRemappedShape = ((::hkReferencedObject *)(::ProcessShape((::Shp_d74480 *)(shape), context, (::Cache_d74480 *)(::hkShapeMapD748 *)(&map), out)));
        reinterpret_cast<::hkReferencedObjectC905 *>((shape))->FUN_00c905b0();
        entry->m_pCollisionShape = pRemappedShape;
    }
    map.FUN_00d74aa0();
    return 0;
}

struct hkpShapeD737;
struct hkpListChildInfoD737
{
    const hkpShapeD737* m_pCollisionShape;
    unsigned int m_uiCollisionFilterData;
    int m_iShapeKey;
    int m_iChildShapeCount;
};
class hkpShapeContainerD737
{
  public:
    virtual ~hkpShapeContainerD737();
    virtual int GetNumChildShapes() const;
};
struct hkpShapeD737
{
    void* m_vtbl;
    int m_usMemSizeAndFlags;
    unsigned int m_ulUserData;
    int m_type;
};
struct hkpListShapeD737 : hkpShapeD737
{
    hkpShapeContainerD737 m_container;
    const hkpShapeD737* m_14;
    hkpListChildInfoD737* m_kChildInfoList;
};
struct hkpSingleD737 : hkpShapeD737
{
    int m_10;
    const hkpShapeD737* m_14;
    const hkpShapeD737* m_18;
};

template <class T> static __forceinline void PushBackD737(hkArrayD748<T>* a, const T& t)
{
    hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
    if (a->m_iElementCount == a->getCapacity())
        ::ResizeAudioStream((::AudioAllocator *)(void *)(&kAlloc), (::AudioStream *)(a), sizeof(T));
    constructWithCopyD748(a->m_data + a->m_iElementCount, 1, t);
    a->m_iElementCount++;
}

// Appends the child shapes of a shape to out: every list child for type 9, or the single child pointer for types 15, 12 and 11.
// @fnv 0x00d737d0
static __declspec(noinline) void FUN_00d737d0(const hkpShapeD737* shape, hkArrayD748<const hkpShapeD737*>* out)
{
    switch (shape->m_type)
    {
    case 9: {
        const hkpListShapeD737* list = (const hkpListShapeD737*)shape;
        for (int i = 0; i < list->m_container.GetNumChildShapes(); i++)
        {
            const hkpShapeD737* child = list->m_kChildInfoList[i].m_pCollisionShape;
            PushBackD737(out, child);
        }
    }
    break;
    case 15: {
        const hkpShapeD737* child = ((const hkpSingleD737*)shape)->m_14;
        PushBackD737(out, child);
    }
    break;
    case 12: {
        const hkpShapeD737* child = ((const hkpSingleD737*)shape)->m_18;
        PushBackD737(out, child);
    }
    break;
    case 11: {
        const hkpShapeD737* child = ((const hkpSingleD737*)shape)->m_18;
        PushBackD737(out, child);
    }
    break;
    }
}

void zz_probe_d737d0(const hkpShapeD737* shape, hkArrayD748<const hkpShapeD737*>* out)
{
    FUN_00d737d0(shape, out);
}

struct D74A20Ref
{
};

struct D74A20Entry
{
    D74A20Ref* m_kPointA;
    D74A20Ref* m_kPointB;
    int m_uiItemCount;
};

struct D74A20Array
{
    D74A20Entry* m_data;
    int m_iElementCount;
};

// @fnv 0x00d74a20
void ShapeData::FUN_00d74a20()
{
    D74A20Array* array = reinterpret_cast<D74A20Array*>(this);

    int index = array->m_iElementCount - 1;
    if (index < 0)
        return;

    while (index >= 0)
    {
        if (array->m_data[index].m_uiItemCount < 2)
        {
            if (array->m_data[index].m_kPointA != 0)
                reinterpret_cast<::hkReferencedObjectC905 *>((array->m_data[index].m_kPointA))->FUN_00c905b0();

            if (array->m_data[index].m_kPointB != 0)
                reinterpret_cast<::hkReferencedObjectC905 *>((array->m_data[index].m_kPointB))->FUN_00c905b0();

            for (int once = 0; once < 1; once++)
            {
                array->m_iElementCount--;
                int n = array->m_iElementCount;
                if (n != index)
                {
                    char* d = reinterpret_cast<char*>(array->m_data);
                    char* src = d + n * 12;
                    d += index * 12;
                    int* dst = reinterpret_cast<int*>(d);
                    int delta = (int)(src - d);
                    int count = 3;
                    do
                    {
                        *dst = *reinterpret_cast<int*>(reinterpret_cast<char*>(dst) + delta);
                        dst++;
                    } while (--count != 0);
                }
            }
        }

        index--;
    }
}



typedef __m128 hkQuadReal;
class VectorComponentValue
{
  public:
    VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    VectorComponentValue()
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    const hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    hkQuadReal m_vValue;
};
class hkTransform;
class hkRotation;
struct hkVector4
{
    __forceinline hkVector4()
    {}
    __forceinline hkVector4(float x, float y, float z, float w);
    __forceinline hkVector4(const hkVector4& v);
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    __forceinline const float& operator()(int a) const;
    __forceinline VectorComponentValue dot3(const hkVector4& a) const;
    __forceinline VectorComponentValue length3() const;
    void FUN_00c7f640(const hkTransform*, const hkVector4*);
    void FUN_00c7f700(const hkRotation&, const hkVector4&);
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void setXYZ0(const hkVector4& v)
    {
        m_vComponents = _mm_and_ps(v.m_vComponents, ::DAT_010c4c10);
    }
};

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkMatrix3
{
  public:
    __forceinline hkVector4& getColumn(int i);
    __forceinline const hkVector4& getColumn(int i) const;
    __forceinline float& operator()(int r, int c);
    __forceinline void setZero();
    __forceinline void setIdentity();
    inline void operator=(const hkMatrix3& a);
    hkVector4 m_kColumn0, m_kColumn1, m_kColumn2;
};
inline hkVector4& hkMatrix3::getColumn(int x)
{
    return (&m_kColumn0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
inline float& hkMatrix3::operator()(int r, int c)
{
    return getColumn(c)(r);
}
inline void hkMatrix3::operator=(const hkMatrix3& a)
{
    m_kColumn0 = a.getColumn(0);
    m_kColumn1 = a.getColumn(1);
    m_kColumn2 = a.getColumn(2);
}
inline void hkMatrix3::setZero()
{
    hkVector4 zero;
    zero.setZero4();
    getColumn(0) = zero;
    getColumn(1) = zero;
    getColumn(2) = zero;
}
inline void hkMatrix3::setIdentity()
{
    setZero();
    float one = 1.0f;
    (*this)(0, 0) = one;
    (*this)(1, 1) = one;
    (*this)(2, 2) = one;
}
class hkRotation : public hkMatrix3
{
  public:
    hkBool IsEqualWithinTolerance(const hkRotation& other, float epsilon) const;
    hkBool IsOrthonormal(float) const;
    hkBool FUN_00cb2d70() const;
    hkBool FUN_00cd4e00(const hkRotation&, float) const;
    __forceinline void setIdentity()
    {
        hkVector4 zero;
        zero.setZero4();
        m_kColumn0 = zero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1 = zero;
        m_kColumn1(1) = 1.0f;
        m_kColumn2 = zero;
        m_kColumn2(2) = 1.0f;
    }
};

class hkTransform
{
  public:
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
    __forceinline static const hkTransform& GetIdentityTransform()
    {
        return (*reinterpret_cast<const ::hkTransform *>(&::DAT_01268370));
    }
    __forceinline hkRotation& getRotation()
    {
        return m_rotation;
    }
    __forceinline const hkRotation& getRotation() const
    {
        return m_rotation;
    }
    __forceinline void setTranslation(const hkVector4& t)
    {
        m_vTranslation = t;
    }
    hkBool IsEqualWithinTolerance(const hkTransform& other, float epsilon) const;
    void SetProduct(const hkTransform& a, const hkTransform& b);
public:
    __forceinline hkTransform()
    {}
    __forceinline hkTransform(const hkTransform& t);
    __forceinline hkVector4& getTranslation();
    __forceinline const hkVector4& getTranslation() const;
    __forceinline void SetBodyOrientation(const hkRotation& r);
    __forceinline void setIdentity();
    hkBool FUN_00cb2160(const hkTransform&, float) const;
};



struct hkBaseObject
{
    virtual ~hkBaseObject();
};

struct CollapseRefObject : hkBaseObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    __forceinline void* operator new(size_t nbytes)
    {
        CollapseRefObject* b =
            static_cast<CollapseRefObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
};

enum CollisionShapeType
{
    HK_SHAPE_CONVEX_TRANSLATE = 0xb,
    HK_SHAPE_CONVEX_TRANSFORM = 0xc,
    HK_SHAPE_TRANSFORM = 0xf,
};

struct hkpShape : CollapseRefObject
{
    unsigned int m_ulUserData;
    int m_type;
    __forceinline int getType() const
    {
        return m_type;
    }
};

struct hkpConvexShape : hkpShape
{
    float m_fSphereRadius;
    __forceinline float getRadius() const
    {
        return m_fSphereRadius;
    }
};

struct hkpSingleShapeContainer
{
    virtual ~hkpSingleShapeContainer();
    const hkpShape* m_pContainedShape;
    __forceinline const hkpShape* getChild() const
    {
        return m_pContainedShape;
    }
};

struct hkpConvexTransformShapeBase : hkpConvexShape
{
    hkpSingleShapeContainer m_pContainedShape;
    int m_iChildShapeSize;
    hkpConvexTransformShapeBase(int type, float radius, const hkpConvexShape* childShape, int ref);
    __forceinline const hkpConvexShape* GetShapeForKey() const
    {
        return static_cast<const hkpConvexShape*>(m_pContainedShape.getChild());
    }
};

struct hkpConvexTranslateShape : hkpConvexTransformShapeBase
{
    hkVector4 m_vTranslation;
    __forceinline hkpConvexTranslateShape(const hkpConvexShape* childShape, const hkVector4& translation, int ref = 1)
        : hkpConvexTransformShapeBase(HK_SHAPE_CONVEX_TRANSLATE, childShape->getRadius(), childShape, ref)
    {
        m_vTranslation.setXYZ0(translation);
        m_iChildShapeSize = 0;
    }
    virtual ~hkpConvexTranslateShape();
    __forceinline const hkVector4& getTranslation() const
    {
        return m_vTranslation;
    }
};

struct hkpConvexTransformShape : hkpConvexTransformShapeBase
{
    hkTransform m_kMotionTransform;
    hkpConvexTransformShape(const hkpConvexShape* childShape, const hkTransform& transform, int ref = 1);
    __forceinline const hkTransform& getTransform() const
    {
        return m_kMotionTransform;
    }
};

struct hkQuaternion
{
    hkVector4 m_vec;
};

struct hkpTransformShape : hkpShape
{
    hkpSingleShapeContainer m_pContainedShape;
    int m_iChildShapeSize;
    hkQuaternion m_rotation;
    hkTransform m_kMotionTransform;
    hkpTransformShape(const hkpShape* childShape, const hkTransform& transform);
    __forceinline const hkpShape* GetShapeForKey() const
    {
        return m_pContainedShape.getChild();
    }
    __forceinline const hkTransform& getTransform() const
    {
        return m_kMotionTransform;
    }
};

// Applies a transform to a shape, collapsing identity results to the child shape or creating a new transform/convex shape wrapper.
// @fnv 0x00d73590
const hkpShape* __cdecl FUN_00d73590(const hkpShape* shape, const hkTransform& transform) throw()
{
    if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(transform.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f)))->FUN_005609f0())
    {
        reinterpret_cast<::FUN_00c90510_class *>((void *)(shape))->FUN_00c90510();
        return shape;
    }

    switch (shape->getType())
    {
    case HK_SHAPE_TRANSFORM: {
        const hkpTransformShape* pTransformShape = static_cast<const hkpTransformShape*>(shape);
        hkTransform combined;
        combined.SetProduct(transform, pTransformShape->getTransform());
        if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(combined.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f)))->FUN_005609f0())
        {
            const hkpShape* child = pTransformShape->GetShapeForKey();
            reinterpret_cast<::FUN_00c90510_class *>((void *)(child))->FUN_00c90510();
            return child;
        }
        return new hkpTransformShape(pTransformShape->GetShapeForKey(), combined);
    }
    case HK_SHAPE_CONVEX_TRANSFORM: {
        const hkpConvexTransformShape* cts = static_cast<const hkpConvexTransformShape*>(shape);
        hkTransform combined;
        combined.SetProduct(transform, cts->getTransform());
        if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(combined.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f)))->FUN_005609f0())
        {
            const hkpShape* child = cts->GetShapeForKey();
            reinterpret_cast<::FUN_00c90510_class *>((void *)(child))->FUN_00c90510();
            return child;
        }
        return new hkpConvexTransformShape(cts->GetShapeForKey(), combined);
    }
    case HK_SHAPE_CONVEX_TRANSLATE: {
        if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(transform.getRotation().IsEqualWithinTolerance(hkTransform::GetIdentityTransform().getRotation(), 0.001f)))->FUN_005609f0())
        {
            const hkpConvexTranslateShape* cts = static_cast<const hkpConvexTranslateShape*>(shape);
            hkTransform local;
            local.getRotation().setIdentity();
            local.setTranslation(cts->getTranslation());
            hkTransform combined;
            combined.SetProduct(transform, local);
            if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(combined.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f)))->FUN_005609f0())
            {
                const hkpShape* child = cts->GetShapeForKey();
                reinterpret_cast<::FUN_00c90510_class *>((void *)(child))->FUN_00c90510();
                return child;
            }
            return new hkpConvexTranslateShape(cts->GetShapeForKey(), cts->getTranslation());
        }
        break;
    }
    }

    return new hkpTransformShape(shape, transform);
}

template <class T> class hkArrayD74
{
  public:
    enum
    {
        DONT_DEALLOCATE_FLAG = 0x80000000,
        CAPACITY_MASK = 0x3fffffff
    };
    int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    void ClearAndRelease()
    {
        hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc.bufFree(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct RefPairD74
{
    hkReferencedObject* m_kPointA;
    hkReferencedObject* m_kPointB;
    int m_iThirdValue;
};
class RefPairListD74
{
  public:
    hkArrayD74<RefPairD74> m_pairs;
    void FUN_00d74aa0();
};
// Removes references from all pairs in m_pairs and then clears and releases the underlying array storage.
// @fnv 0x00d74aa0
void RefPairListD74::FUN_00d74aa0()
{
    for (int i = 0; i < m_pairs.m_iElementCount; i++)
    {
        if (m_pairs.m_data[i].m_kPointA)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pairs.m_data[i].m_kPointA))->FUN_00c905b0();
        if (m_pairs.m_data[i].m_kPointB)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pairs.m_data[i].m_kPointB))->FUN_00c905b0();
    }
    m_pairs.ClearAndRelease();
}

// Moved from hkptransformcollapseutil_ehsc_noehsc_variant.cpp (VEGAS-15).
#include "fnv/decl/CenteredPointBounds.h"
#include "fnv/decl/ConvexVertsQ_d59200.h"
#include "fnv/decl/FUN_00d22590_Class.h"
#include "fnv/decl/FUN_00d59bd0.h"
#include "fnv/decl/FnvCpu_FUN_00d58d50_CpuObject.h"
#include "fnv/decl/fnv_00d57aa0__S00d57aa0_Obj.h"
#include "fnv/decl/hkpCylinderShapeGetCylRadius.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_011b1000.h"
int RunContextOperation(int a1, int a2, int a3, int* out);

struct ShapeD738;
struct ShapeContainerD738
{
    virtual ~ShapeContainerD738();
    virtual int GetNumChildShapes() const;
};
struct ChildInfoD738
{
    ShapeD738* m_pCollisionShape;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
};
struct ShapeD738
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_type;
};
struct ListShapeD738 : ShapeD738
{
    ShapeContainerD738 m_container;
    int m_unk14;
    ChildInfoD738* m_kChildInfoList;
};
struct BvShapeD738 : ShapeD738
{
    int m_unk10;
    ShapeD738* m_pContainedShape;
};
struct WrapperShapeD738 : ShapeD738
{
    int m_unk10;
    int m_unk14;
    ShapeD738* m_pContainedShape;
};
struct EntryD738
{
    const ShapeD738* m_pCollisionShape;
    const void* m_unk04;
    int m_iObjectReferenceCount;
};

static __declspec(noinline) void FUN_00d737d0(ShapeD738* shape, hkArrayD748<ShapeD738*>* out)
{
    switch (shape->m_type)
    {
    case 9: {
        ListShapeD738* list = static_cast<ListShapeD738*>(shape);
        for (int i = 0; i < list->m_container.GetNumChildShapes(); i++)
            out->AddBack(list->m_kChildInfoList[i].m_pCollisionShape);
    }
    break;
    case 11:
        out->AddBack(static_cast<WrapperShapeD738*>(shape)->m_pContainedShape);
        break;
    case 12:
        out->AddBack(static_cast<WrapperShapeD738*>(shape)->m_pContainedShape);
        break;
    case 15:
        out->AddBack(static_cast<BvShapeD738*>(shape)->m_pContainedShape);
        break;
    }
}

static __forceinline int indexOfD738(ShapeData* self, const ShapeD738* value)
{
    for (int i = 0; i < self->m_kPointB; i++)
        if (self->m_kPointA[i].m_pCollisionShape == value)
            return i;
    return -1;
}

static __forceinline void addShapeD738(ShapeData* self, const ShapeD738* value)
{
    EntryD738 e;
    e.m_pCollisionShape = value;
    e.m_unk04 = nullptr;
    e.m_iObjectReferenceCount = 1;
    hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
    if (self->m_kPointB == (self->m_iThirdValue & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(void *)(&kAlloc), (::AudioStream *)(self), sizeof(EntryD738));
    new (self->m_kPointA + self->m_kPointB) EntryD738(e);
    self->m_kPointB++;

    reinterpret_cast<::FUN_00c90510_class *>((((FUN_00c90510_Obj*)value)))->FUN_00c90510();

    hkArrayD748<ShapeD738*> children;
    FUN_00d737d0(const_cast<ShapeD738*>(value), &children);
    for (int i = 0; i < children.m_iElementCount; i++)
        self->FUN_00d738f0(children.m_data[i]);
}

// @fnv 0x00d738f0
void ShapeData::FUN_00d738f0(const ShapeD738* value)
{
    int index = indexOfD738(this, value);
    if (index >= 0)
    {
        m_kPointA[index].m_iObjectReferenceCount++;
        return;
    }
    addShapeD738(this, value);
}

#include <math.h>
class hkTransform;
inline hkVector4::hkVector4(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}
inline hkVector4::hkVector4(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}
inline VectorComponentValue hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}
inline VectorComponentValue hkVector4::length3() const
{
    return _mm_sqrt_ss(this->dot3(*this).getQuad());
}
inline const float& hkVector4::operator()(int a) const
{
    return reinterpret_cast<const float*>(&m_vComponents)[a];
}
inline hkVector4& hkTransform::getTranslation()
{
    return m_vTranslation;
}
inline const hkVector4& hkTransform::getTranslation() const
{
    return m_vTranslation;
}
inline void hkTransform::SetBodyOrientation(const hkRotation& r)
{
    m_rotation = r;
}
inline void hkTransform::setIdentity()
{
    m_rotation.setIdentity();
    m_vTranslation.setZero4();
}
inline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.m_rotation.getColumn(0);
    const hkVector4 r1 = t.m_rotation.getColumn(1);
    const hkVector4 r2 = t.m_rotation.getColumn(2);
    const hkVector4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}
__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0);
    hkQuadReal r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    hkQuadReal r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    hkQuadReal r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1),
                                             _mm_add_ps(r2, t.getTranslation().m_vComponents));
}

__forceinline hkMemoryAllocator& heapAllocator()
{
    return hkMemoryRouter::getInstance().heap();
}
struct hkTypeIsPod
{
};
struct HavokArrayUtilities
{
    template <class T> static __forceinline void construct(T*, int, hkTypeIsPod)
    {}
    template <class T> static __forceinline void destruct(T*, int, hkTypeIsPod)
    {}
    template <class T> static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, hkTypeIsPod)
    {
        for (int i = 0; i < n; ++i)
            t[i] = tcopy;
    }
};
template <class T> class hkArrayBase739
{
  public:
    enum
    {
        DONT_DEALLOCATE_FLAG = 0x80000000,
        CAPACITY_MASK = 0x3fffffff
    };
    __forceinline hkArrayBase739() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}
    __forceinline ~hkArrayBase739()
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void clear()
    {
        HavokArrayUtilities::destruct(m_data, m_iElementCount, hkTypeIsPod());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc.bufFree(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)(void *)(&alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(hkMemoryAllocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        HavokArrayUtilities::destruct(m_data + n, m_iElementCount - n, hkTypeIsPod());
        HavokArrayUtilities::construct(m_data + m_iElementCount, n - m_iElementCount, hkTypeIsPod());
        m_iElementCount = n;
    }
    __forceinline void _pushBack(hkMemoryAllocator& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc), (::AudioStream *)(void *)(this), sizeof(T));
        HavokArrayUtilities::constructWithCopy(m_data + m_iElementCount, 1, t, hkTypeIsPod());
        m_iElementCount++;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <class T> class hkArray739 : public hkArrayBase739<T>
{
  public:
    __forceinline hkArray739()
    {}
    __forceinline ~hkArray739()
    {
        ClearAndRelease();
    }
    __forceinline void ClearAndRelease()
    {
        this->_clearAndDeallocate(heapAllocator());
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        this->_setSize(heapAllocator(), n);
    }
    __forceinline void AddBack(const T& t)
    {
        this->_pushBack(heapAllocator(), t);
    }
};
struct FloatArrayDescriptor
{
    const float* m_kVertices;
    int m_iStridedVertexCount;
    int m_iVertexStride;
};
__forceinline void* shapeNew(int nbytes)
{
    hkpShape* b = static_cast<hkpShape*>(heapAllocator().blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
    return b;
}
class hkpCapsuleShape : public hkpConvexShape
{
  public:
    int m_14, m_18, m_1c;
    hkVector4 m_kVertexA, m_kVertexB;
    const hkVector4* GetIndexedVertices() const
    {
        return &m_kVertexA;
    }
};
class hkpCylinderShape : public hkpConvexShape
{
  public:
    int m_14, m_18, m_1c;
    hkVector4 m_kVertexA, m_kVertexB;
    const hkVector4* GetIndexedVertices() const
    {
        return &m_kVertexA;
    }
};
class hkpConvexVerticesShape : public hkpConvexShape
{
  public:
};
class hkpBoxShape : public hkpConvexShape
{
  public:
    int m_14, m_18, m_1c;
    hkVector4 m_vHalfExtents;
    const hkVector4& getHalfExtents() const
    {
        return m_vHalfExtents;
    }
};
class hkpShapeContainer
{
  public:
    virtual ~hkpShapeContainer();
    virtual int GetNumChildShapes() const;
};
struct hkpListChildInfo
{
    const hkpShape* m_pCollisionShape;
    int m_iFilter, m_iShapeKey, m_iChildShapeCount;
};
class hkpListShape : public hkpShape
{
  public:
    hkpShapeContainer m_container;
    int m_14;
    hkArray739<hkpListChildInfo> m_kChildInfoList;
    const hkpShape* getChildShapeInl(int i) const
    {
        return m_kChildInfoList[i].m_pCollisionShape;
    }
};
struct Options
{
    int m_iFirstOptionValue, m_iSecondOptionValue;
    hkBool m_bOptionFlag;
};
struct Results
{
    int m_iFirstResult, m_iSecondResult, m_iThirdResult, m_numPropagatedTransformsInLists;
};
__forceinline void TransformPointArray(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                       hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
// @fnv 0x00d739f0
const hkpShape* FUN_00d739f0(const hkpShape* transformShape, const Options& options, D749Table& sharedShapeData,
                             Results& resultsOut)
{
    const int transformShapeType = transformShape->getType();
    hkTransform parentFromChild;
    const hkpShape* childShape = 0;
    switch (transformShapeType)
    {
    case 15: {
        const hkpTransformShape* tformshape = static_cast<const hkpTransformShape*>(transformShape);
        parentFromChild = tformshape->getTransform();
        childShape = tformshape->GetShapeForKey();
        break;
    }
    case 12: {
        const hkpConvexTransformShape* ctformshape = static_cast<const hkpConvexTransformShape*>(transformShape);
        parentFromChild = ctformshape->getTransform();
        childShape = ctformshape->GetShapeForKey();
        break;
    }
    case 11: {
        const hkpConvexTranslateShape* ctlateshape = static_cast<const hkpConvexTranslateShape*>(transformShape);
        parentFromChild.setIdentity();
        parentFromChild.setTranslation(ctlateshape->getTranslation());
        childShape = ctlateshape->GetShapeForKey();
        break;
    }
    default:
        reinterpret_cast<::FUN_00c90510_class *>((void *)(transformShape))->FUN_00c90510();
        return transformShape;
    }
    const int childShapeType = childShape->getType();
    if (childShapeType == 1)
        parentFromChild.SetBodyOrientation((*reinterpret_cast<::hkTransform *>(&::DAT_01268370)).getRotation());
    if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(parentFromChild.FUN_00cb2160((*reinterpret_cast<::hkTransform *>(&::DAT_01268370)), 1e-3f)))->FUN_005609f0())
    {
        resultsOut.m_iSecondResult++;
        reinterpret_cast<::FUN_00c90510_class *>((void *)(childShape))->FUN_00c90510();
        sharedShapeData.SetEntryValue(transformShape, childShape);
        return childShape;
    }
    bool allowChangesToChildShape = true;
    switch (options.m_iFirstOptionValue)
    {
    case 0:
        allowChangesToChildShape = true;
        break;
    case 1:
        allowChangesToChildShape = false;
        break;
    case 2:
        allowChangesToChildShape =
            reinterpret_cast<FUN_00d74980_Class&>(sharedShapeData).FindMappedValue(childShape) <
            options.m_iSecondOptionValue;
        break;
    }
    if (childShapeType == 9)
    {
        const hkpListShape* listShape = static_cast<const hkpListShape*>(childShape);
        if (!reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(options.m_bOptionFlag))->FUN_005609f0() && allowChangesToChildShape)
        {
            resultsOut.m_numPropagatedTransformsInLists++;
            hkArray739<const hkpShape*> newChildren;
            for (int i = 0; i < listShape->m_container.GetNumChildShapes(); i++)
            {
                const hkpShape* grandChildShape = listShape->getChildShapeInl(i);
                hkpTransformShape* wrapperMem = static_cast<hkpTransformShape*>(shapeNew(0x70));
                const hkpShape* childTransformShape = ((::hkpTransformShape *)(reinterpret_cast<::cf5990_TransformShape *>((wrapperMem))->FUN_00cf5990((::hkpShape *)(grandChildShape), (*(const ::hkTransform *)(&parentFromChild)))));
                const hkpShape* collapsedGrandChild =
                    FUN_00d739f0(childTransformShape, options, sharedShapeData, resultsOut);
                newChildren.AddBack(collapsedGrandChild);
                reinterpret_cast<::hkReferencedObjectC905 *>((void *)(childTransformShape))->FUN_00c905b0();
            }
            hkpListShape* newListMem = static_cast<hkpListShape*>(shapeNew(0x70));
            hkpListShape* newListShape = ((::hkpListShape *)(new ((void *)(newListMem)) ::FUN_00cf5640(newChildren.begin(), newChildren.GetLogicalSize(), 1)));
            for (int n = 0; n < newChildren.GetLogicalSize(); n++)
                reinterpret_cast<::hkReferencedObjectC905 *>((void *)(newChildren[n]))->FUN_00c905b0();
            sharedShapeData.SetEntryValue(transformShape, newListShape);
            return newListShape;
        }
        reinterpret_cast<::FUN_00c90510_class *>((void *)(transformShape))->FUN_00c90510();
        return transformShape;
    }
    if (allowChangesToChildShape)
    {
        switch (childShapeType)
        {
        case 5: {
            const hkpCapsuleShape* childCapsuleShape = static_cast<const hkpCapsuleShape*>(childShape);
            const hkVector4* childA = &childCapsuleShape->GetIndexedVertices()[0];
            const hkVector4* childB = &childCapsuleShape->GetIndexedVertices()[1];
            const float radius = childCapsuleShape->getRadius();
            hkVector4 parentA;
            parentA.FUN_00c7f640(&parentFromChild, childA);
            hkVector4 parentB;
            parentB.FUN_00c7f640(&parentFromChild, childB);
            hkpCapsuleShape* newCapsuleMem = static_cast<hkpCapsuleShape*>(shapeNew(0x40));
            hkpCapsuleShape* newCapsule = ((::hkpCapsuleShape *)(reinterpret_cast<::FUN_00d22590_Class *>((newCapsuleMem))->FUN_00d22590((const ::AlignedHKVector4 &)(parentA), (const ::AlignedHKVector4 &)(parentB), radius)));
            sharedShapeData.SetEntryValue(transformShape, newCapsule);
            resultsOut.m_iFirstResult++;
            return newCapsule;
        }
        case 2: {
            const hkpCylinderShape* childCylinderShape = static_cast<const hkpCylinderShape*>(childShape);
            const hkVector4* childA = &childCylinderShape->GetIndexedVertices()[0];
            const hkVector4* childB = &childCylinderShape->GetIndexedVertices()[1];
            const float cylRadius = reinterpret_cast<::hkpCylinderShapeGetCylRadius *>((void *)(childCylinderShape))->FUN_00d571a0();
            const float radius = childCylinderShape->getRadius();
            hkVector4 parentA;
            parentA.FUN_00c7f640(&parentFromChild, childA);
            hkVector4 parentB;
            parentB.FUN_00c7f640(&parentFromChild, childB);
            hkpCylinderShape* newCylinderMem = static_cast<hkpCylinderShape*>(shapeNew(0x60));
            hkpCylinderShape* newCylinder = ((::hkpCylinderShape *)(reinterpret_cast<::fnv_00d57aa0::S00d57aa0_Obj *>((newCylinderMem))->FUN_00d57aa0((const float *)&(parentA), (const float *)&(parentB), cylRadius, radius)));
            sharedShapeData.SetEntryValue(transformShape, newCylinder);
            resultsOut.m_iFirstResult++;
            return newCylinder;
        }
        case 6: {
            const hkpConvexVerticesShape* childCVShape = static_cast<const hkpConvexVerticesShape*>(childShape);
            hkArray739<hkVector4> vertices;
            reinterpret_cast<::ConvexVertsQ_d59200 *>((void *)(childCVShape))->FUN_00d59200((::VertArray96Q &)(vertices));
            TransformPointArray(parentFromChild, vertices.begin(), vertices.GetLogicalSize(), vertices.begin());
            FloatArrayDescriptor newverts;
            newverts.m_iStridedVertexCount = vertices.GetLogicalSize();
            newverts.m_iVertexStride = 16;
            newverts.m_kVertices = &vertices[0](0);
            const hkArray739<hkVector4>& planes = (*(const ::hkArray739< ::hkVector4> *)(reinterpret_cast<::FnvCpu_FUN_00d58d50_CpuObject *>((void *)(childCVShape))->FUN_00d58d50()));
            hkArray739<hkVector4> newplanes;
            newplanes.SetSizeAndGrow(planes.GetLogicalSize());
            hkVector4 pivotShift(parentFromChild.getTranslation());
            for (int p = 0; p < planes.GetLogicalSize(); p++)
            {
                hkVector4 plane;
                _mm_store_ps(reinterpret_cast<float*>(&plane.m_vComponents), planes[p].m_vComponents);
                const float newDist = plane(3) - pivotShift.dot3(plane);
                plane.FUN_00c7f700(parentFromChild.getRotation(), plane);
                plane(3) = newDist;
                newplanes[p] = plane;
            }
            hkpConvexVerticesShape* newCVShapeMem = static_cast<hkpConvexVerticesShape*>(shapeNew(0x70));
            hkpConvexVerticesShape* newCVShape =
                ((::hkpConvexVerticesShape *)(new ((void *)(newCVShapeMem)) ::FUN_00d59bd0((::InputValues *)&(newverts), (const ::ArrayD5A360< ::Vector4D5A360> &)(newplanes), childCVShape->getRadius())));
            sharedShapeData.SetEntryValue(transformShape, newCVShape);
            resultsOut.m_iFirstResult++;
            return newCVShape;
        }
        case 4: {
            const double& tol = ::DAT_01032980;
            if (!(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(parentFromChild.getRotation().IsOrthonormal(1e-3f)))->FUN_005609f0() && reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(parentFromChild.getRotation().FUN_00cb2d70()))->FUN_005609f0()))
                break;
            if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(parentFromChild.getRotation().FUN_00cd4e00((*reinterpret_cast<::hkTransform *>(&::DAT_01268370)).getRotation(), 1e-3f)))->FUN_005609f0())
                break;
            bool failedA = false;
            bool failedB = false;
            int map[3];
            for (int i = 0; i < 3; i++)
            {
                const hkVector4& axisRot = parentFromChild.getRotation().getColumn(i);
                bool passedA1 = false;
                for (int j = 0; j < 3; j++)
                {
                    const bool testA0 = fabsf(axisRot(j)) < tol;
                    const bool testA1 = fabsf(fabsf(axisRot(j)) - 1.0f) < tol;
                    if (!testA0 && !testA1)
                    {
                        failedA = true;
                        break;
                    }
                    if (testA1)
                    {
                        map[j] = i;
                        passedA1 = true;
                    }
                }
                if (!passedA1)
                    failedA = true;
                if (failedA)
                    break;
                float sum = 0.0f;
                for (int j = 0; j < 3; j++)
                    sum += fabsf(axisRot(j));
                failedB = !(sum - 1.0f < tol);
                if (failedB)
                    break;
            }
            if (failedA || failedB)
                break;
            const hkpBoxShape* childBoxShape = static_cast<const hkpBoxShape*>(childShape);
            const hkVector4& halfExtents = childBoxShape->getHalfExtents();
            hkVector4 newHalfExtents(halfExtents(map[0]), halfExtents(map[1]), halfExtents(map[2]), 0.0f);
            hkpBoxShape* newBoxShapeMem = static_cast<hkpBoxShape*>(shapeNew(0x30));
            hkpBoxShape* newBoxShape = ((::hkpBoxShape *)(reinterpret_cast<::CenteredPointBounds *>((newBoxShapeMem))->SetExtentsAndRadius((const float *)&(newHalfExtents), DAT_011b153c)));
            if (parentFromChild.getTranslation().length3() < tol)
            {
                sharedShapeData.SetEntryValue(transformShape, newBoxShape);
                resultsOut.m_iFirstResult++;
                return newBoxShape;
            }
            hkpConvexTranslateShape* newShapeMem = static_cast<hkpConvexTranslateShape*>(shapeNew(0x30));
            hkpConvexTranslateShape* pRemappedShape = ::new (static_cast<void*>(newShapeMem)) hkpConvexTranslateShape(newBoxShape, parentFromChild.getTranslation());
            reinterpret_cast<::hkReferencedObjectC905 *>((void *)(newBoxShape))->FUN_00c905b0();
            sharedShapeData.SetEntryValue(transformShape, pRemappedShape);
            resultsOut.m_iThirdResult++;
            return pRemappedShape;
        }
        }
    }
    switch (childShapeType)
    {
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 18: {
        const hkpConvexShape* childConvexShape = static_cast<const hkpConvexShape*>(childShape);
        hkBool translateOnly = parentFromChild.getRotation().FUN_00cd4e00((*reinterpret_cast<::hkTransform *>(&::DAT_01268370)).getRotation(), 1e-3f);
        if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(translateOnly))->FUN_005609f0() && transformShapeType != 11)
        {
            hkpConvexTranslateShape* newShapeMem = static_cast<hkpConvexTranslateShape*>(shapeNew(0x30));
            hkpConvexTranslateShape* pRemappedShape = ::new (static_cast<void*>(newShapeMem))
                hkpConvexTranslateShape(childConvexShape, parentFromChild.getTranslation());
            sharedShapeData.SetEntryValue(transformShape, pRemappedShape);
            resultsOut.m_iThirdResult++;
            return pRemappedShape;
        }
        if (transformShapeType == 15)
        {
            hkpConvexTransformShape* newShapeMem = static_cast<hkpConvexTransformShape*>(shapeNew(0x60));
            hkpConvexTransformShape* pRemappedShape = ((::hkpConvexTransformShape *)(reinterpret_cast<::Standin *>((newShapeMem))->FUN_00d5d7a0(childConvexShape, (*(const ::AlignedTransform *)(&parentFromChild)), 1)));
            sharedShapeData.SetEntryValue(transformShape, pRemappedShape);
            resultsOut.m_iThirdResult++;
            return pRemappedShape;
        }
    }
    }
    reinterpret_cast<::FUN_00c90510_class *>((void *)(transformShape))->FUN_00c90510();
    return transformShape;
}
