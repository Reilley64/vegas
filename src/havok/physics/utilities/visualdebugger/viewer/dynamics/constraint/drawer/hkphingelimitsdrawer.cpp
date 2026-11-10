// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Moved from hkphingelimitsdrawer_rtm_variant.cpp (VEGAS-15).

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/hkpConstraintDrawer.h"
#include "havok/hkUlong.h"
#include "havok/hkMemoryRouter.h"
#include <new>
#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/DE44C0Object.h"
#include "fnv/decl/FUN_00de4530Owner.h"
#include "fnv/symbols_00cab000.h"
#include "fnv/symbols_0106d000.h"


static __forceinline __m128 splat(const float& f)
{
    __m128 t = _mm_load_ss(&f);
    return _mm_shuffle_ps(t, t, 0);
}

static __forceinline __m128 splatRounded(double f)
{
    float scalar = (float)f;
    __m128 t = _mm_load_ss(&scalar);
    return _mm_shuffle_ps(t, t, 0);
}

struct Visitor
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void displayLine(void* start, void* end, int color, hkUlong id, int tag); // vtable slot 9
};

struct Src
{
    int u00;
    int u04;
    int u08;
    unsigned char* m0c;
};

struct Mat4
{
    __m128 r0, r1, r2, r3;
};
struct Mat3
{
    __m128 r0, r1, r2;
};

struct Vec
{
    __m128 v;
    void FUN_00c7f640(Mat4* m, void* p);
    void FUN_00c7f700(Mat3* m, void* p);
};

struct Holder
{
    void* p;
};


struct T
{
    float f00;
    float u04, u08, u0c, u10, u14, u18;
    float f1c;
    __m128 m20;
    __m128 m30;
    Vec m40;
    Vec m50;
    Mat3 m60;
    Mat3 m90;
    Holder mc;
    void FUN_00de6d80(Src* a1, Visitor* a2, hkUlong a3, int a4);
};



// @fnv 0x00de6d80
void T::FUN_00de6d80(Src* a1, Visitor* a2, hkUlong a3, int a4)
{
    struct Work
    {
        Vec va;
        Vec vb;
        Mat4 matA;
        Mat4 matB;
        __m128 buf[12];
    } w;
    unsigned char* e = a1->m0c;
    reinterpret_cast<::CpuObject *>(&(mc))->FUN_00e10a10((a2));
    reinterpret_cast<hkpConstraintDrawer*>(this)->FUN_00de47e0(a1, &w.matA, &w.matB);
    m50.FUN_00c7f640(&w.matA, e + 0x90);
    m40.FUN_00c7f640(&w.matB, e + 0x50);
    reinterpret_cast<::DE44C0Object *>(this)->FUN_00de44c0(a3, a4);
    reinterpret_cast<::FUN_00de4530Owner *>(this)->FUN_00de4530(a3, a4);
    w.vb.FUN_00c7f700(&m90, e + ((((int)e[0xa2] + 1) % 3) + 6) * 16);
    w.va.FUN_00c7f700(&m90, e + ((((int)e[0xa2] + 2) % 3) + 6) * 16);
    float s = f1c * f00;
    float t = s;
    float sd = s + t;
    float s2 = (float)(::DAT_0106d4c8 * s);
    __m128 base = m50.v;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            __m128 x = i ? w.vb.v : w.va.v;
            __m128* __restrict ptry = i ? &w.va.v : &w.vb.v;
            __m128 y = *ptry;
            __m128* p = &w.buf[i * 6 + (j + 1) * 2 + 1];
            _mm_store_ps((float*)(p - 1), base);
            _mm_store_ps((float*)p, base);
            float ty = (float)((double)j * 1.4f * s);
            _mm_store_ps((float*)(p - 1), _mm_add_ps(_mm_mul_ps(splat(sd), x), p[-1]));
            _mm_store_ps((float*)p, _mm_add_ps(_mm_mul_ps(splat(s2), x), p[0]));
            _mm_store_ps((float*)(p - 1), _mm_add_ps(_mm_mul_ps(splatRounded(ty), y), p[-1]));
            _mm_store_ps((float*)p, _mm_add_ps(_mm_mul_ps(splatRounded(ty), y), p[0]));
        }
    }
    __m128* q = w.buf;
    int n = 6;
    do
    {
        a2->displayLine(q, q + 1, ((int)(::PackColorBigEndian(0.8f, 0.8f, 0.8f, 1.0f))), a3, a4);
        q += 2;
    } while (--n);
    a2->displayLine(&m40, &m20, ((int)(::PackColorBigEndian(0.3f, 0.3f, 0.8f, 1.0f))), a3, a4);
}

// Moved from hkphingelimitsdrawer_ehsc_noehsc_variant_rtm_variant.cpp (VEGAS-15).

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer_ehsc_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer_ehsc_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstddef>
#include "fnv/decl/SetupTarget.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_01267000.h"
namespace HingeLimitsDrawing {
typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef uintptr_t hkUlong;
typedef intptr_t hkLong;
enum hkResult
{
    HK_SUCCESS = 0,
    HK_FAILURE = 1
};
typedef size_t hk_size_t;
__forceinline hkLong __cdecl hkGetByteOffset(const void* base, const void* pntr)
{
    return hkLong(pntr) - hkLong(base);
}
__forceinline int __cdecl hkGetByteOffsetInt(const void* base, const void* pntr)
{
    return static_cast<int>(hkGetByteOffset(base, pntr));
}
class FinishingFlag
{
  public:
    FinishingFlag() : m_bFinishing(0)
    {}
    int m_bFinishing;
};
class hkClass;
class hkBool
{
  public:
    typedef char CompileTimeTrueType;

  private:
    char m_cBooleanValue;
};
template <typename ENUM, typename STORAGE> class hkEnum
{
  public:
    hkEnum()
    {}
    hkEnum(ENUM e)
    {
        m_kStorage = static_cast<STORAGE>(e);
    }
    operator ENUM() const
    {
        return static_cast<ENUM>(m_kStorage);
    }

  private:
    STORAGE m_kStorage;
};
template <typename TYPE> class ValueWrapper
{
  public:
    __forceinline ValueWrapper()
    {}

  private:
    TYPE m_kStorage;
};
template <typename T> struct TypeSizeConstant
{
    enum
    {
        val = sizeof(T)
    };
};
class hkBaseObject
{
  public:
    static const struct ClassMemberDescriptor Members[];
    __forceinline virtual ~hkBaseObject()
    {}

  public:
    __forceinline hkBaseObject()
    {}
};
class hkReferencedObject : public hkBaseObject
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        hkReferencedObject* b = static_cast<hkReferencedObject*>(
            hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        ;
        return b;
    }

  public:
    enum
    {
        MASK_MEMSIZE = 0x7fff
    };
    hkUint16 m_usMemSizeAndFlags;

  public:
    hkReferencedObject(class FinishingFlag flag)
    {}
};
template <bool N> struct BooleanTypeConstant
{
    typedef BooleanTypeConstant<N> type;
    enum
    {
        result = N
    };
};
typedef BooleanTypeConstant<true> hkTypeIsPod;
template <typename T>
struct IsPodType : public BooleanTypeConstant<(sizeof(*static_cast<T*>(0) == *static_cast<const hkTypeIsPod*>(0)) ==
                                               sizeof(hkBool::CompileTimeTrueType))>
{
};
template <typename T> struct IsPodType<T*> : public hkTypeIsPod
{
};
class HavokArrayUtilities
{
  public:
    template <typename T> static __forceinline void construct(T* t, int n, hkTypeIsPod);
    template <typename T> static __forceinline void destruct(T* t, int n, hkTypeIsPod);
};
template <typename T> __forceinline void HavokArrayUtilities::destruct(T* t, int n, hkTypeIsPod)
{}
struct RouterHeapAllocatorProvider
{
    hkMemoryAllocator& get(const void*)
    {
        return hkMemoryRouter::getInstance().heap();
    }
};
template <typename T> class HavokElementArray
{
  public:
    typedef HavokElementArray<T> ThisType;
    __forceinline HavokElementArray();

  protected:
    __forceinline HavokElementArray(const HavokElementArray& a)
    {
        ;
    }

  public:
    __forceinline void _useExternalArray(T*, int cap);
    __forceinline ~HavokElementArray();
    __forceinline T& operator[](int i);
    __forceinline int getCapacity() const;
    __forceinline void clear();
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc);
    __forceinline void reserve(hkMemoryAllocator& alloc, int n);
    __forceinline void _setSize(hkMemoryAllocator& alloc, int size);

  protected:
    __forceinline HavokElementArray<T>& copyFromArray(hkMemoryAllocator&, const HavokElementArray<T>& src, hkTypeIsPod);

  public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        FLAG_MASK = int(0xC0000000),
        DONT_DEALLOCATE_FLAG = int(0x80000000),
        FORCE_SIGNED = -1
    };

  protected:
    friend class hkStatisticsCollector;
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

  public:
    HavokElementArray(FinishingFlag f)
    {}
};
template <typename T, typename Allocator = RouterHeapAllocatorProvider> class hkArray : public HavokElementArray<T>
{
  public:
    typedef Allocator AllocatorType;
    __forceinline hkArray() : HavokElementArray<T>()
    {}
    __forceinline ~hkArray();

  protected:
    __forceinline hkArray(const hkArray& a);

  public:
    __forceinline hkArray& operator=(const HavokElementArray<T>& a);
    __forceinline void ClearAndRelease()
    {
        HavokElementArray<T>::_clearAndDeallocate(AllocatorType().get(this));
    }
    __forceinline void SetSizeAndGrow(int size)
    {
        HavokElementArray<T>::_setSize(AllocatorType().get(this), size);
    }
};
template <typename T> __forceinline T& HavokElementArray<T>::operator[](int i)
{
    ;
    return m_data[i];
}
template <typename T> __forceinline int HavokElementArray<T>::getCapacity() const
{
    return (m_iCapacityState & static_cast<int>(CAPACITY_MASK));
}
template <typename T> __forceinline void HavokElementArray<T>::reserve(hkMemoryAllocator& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int cap2 = 2 * capacity;
        int newSize = (n < cap2) ? cap2 : n;
        ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(T));
    }
}
template <typename T> __forceinline void HavokElementArray<T>::clear()
{
    HavokArrayUtilities::destruct(m_data, m_iElementCount, typename IsPodType<T>::type());
    m_iElementCount = 0;
}
template <typename T>
__forceinline HavokElementArray<T>::HavokElementArray() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
{}
template <typename T> __forceinline HavokElementArray<T>::~HavokElementArray()
{
    ;
    ;
}
template <typename T> __forceinline void HavokElementArray<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
    {
        alloc._bufFree<T>(m_data, getCapacity());
    }
    m_data = 0;
    m_iCapacityState = DONT_DEALLOCATE_FLAG;
}
template <typename T> __forceinline void HavokElementArray<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    reserve(alloc, n);
    m_iElementCount = n;
}
template <typename T, typename Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    ClearAndRelease();
}
typedef __m128 hkQuadReal;
class VectorComponentValue
{
  public:
    VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    VectorComponentValue(hkReal x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    hkQuadReal m_vValue;
};
typedef const VectorComponentValue& hkSimdRealParameter;
class hkRotation;
class hkTransform;
struct hkQsTransform;
struct hkVector4
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline void operator=(const hkVector4& v);
    __forceinline void add4(const hkVector4& a);
    __forceinline void setMul4(hkSimdRealParameter r, const hkVector4& a);
    __forceinline void addMul4(hkSimdRealParameter r, const hkVector4& a);
    void FUN_00c7f700(const hkRotation& a, const hkVector4& b);
    void FUN_00c7f640(const hkTransform& a, const hkVector4& b);
    __forceinline VectorComponentValue dot3(const hkVector4& a) const;
    __forceinline VectorComponentValue lengthInverse3() const;
    __forceinline void normalize3();
    __forceinline static const hkVector4& __cdecl getZero();

  private:
    hkQuadReal m_vComponents;

  public:
    operator hkQuadReal() const
    {
        return m_vComponents;
    }
};
class hkMatrix3
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline const hkVector4& getColumn(int i) const;

  protected:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
};
class hkTransform
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  private:
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};
inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}
inline void hkVector4::add4(const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}
inline void hkVector4::setMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}
inline void hkVector4::addMul4(hkSimdRealParameter r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
inline VectorComponentValue hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))), xySum);
}
inline VectorComponentValue hkVector4::lengthInverse3() const
{
    const hkQuadReal half = _mm_set_ss(0.5f);
    const hkQuadReal three = _mm_set_ss(3.0f);
    const hkQuadReal zero = _mm_set_ss(0.0f);
    const hkQuadReal len2 = this->dot3(*this).getQuad();
    const hkQuadReal len2EqualsZero = _mm_cmpeq_ss(len2, zero);
    const hkQuadReal approx = _mm_rsqrt_ss(len2);
    const hkQuadReal refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    return _mm_andnot_ps(len2EqualsZero, refined);
}
inline void hkVector4::normalize3()
{
    hkQuadReal lenInv = lengthInverse3().broadcast();
    m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
}
inline const hkVector4& __cdecl hkVector4::getZero()
{

    return (*reinterpret_cast<::HingeLimitsDrawing::hkVector4 *>(&::DAT_01267e30));
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
struct GenericConstraintAtomScheme
{
};
class SixteenWordFloatRecord;
class QueryResultSchema;
class hkpConstraintOwner;
class hkpConstraintData : public hkReferencedObject
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        hkReferencedObject* b = static_cast<hkReferencedObject*>(
            hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        ;
        return b;
    }
    hkpConstraintData(FinishingFlag f) : hkReferencedObject(f)
    {}

  protected:
    friend class ConstraintInstance;

  public:
    virtual void BuildJacobian(const SixteenWordFloatRecord& in, QueryResultSchema& out)
    {
        ;
    }
    struct ConstraintInfo : public GenericConstraintAtomScheme
    {
        __forceinline void* __cdecl operator new(std::size_t nbytes)
        {
            ;
            void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(hkpConstraintData::ConstraintInfo));
            }
        }
        __forceinline void* __cdecl operator new(std::size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](std::size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        struct hkpConstraintAtom* m_kBridgeAtoms;
        hkUint32 m_usSizeOfAllAtoms;
    };

  public:
    hkUlong m_ulUserData;
};
class hkpEntity;
class hkpConstraintInstance : public hkReferencedObject
{
  public:
    static const struct ClassMemberDescriptor Members[];
    enum ConstraintPriority
    {
        PRIORITY_INVALID,
        PRIORITY_PSI,
        PRIORITY_SIMPLIFIED_TOI_UNUSED,
        PRIORITY_TOI,
        PRIORITY_TOI_HIGHER,
        PRIORITY_TOI_FORCED,
    };
    enum OnDestructionRemapInfo
    {
        ON_DESTRUCTION_REMAP = 0,
        ON_DESTRUCTION_REMOVE = 1,
        ON_DESTRUCTION_RESET_REMOVE = 2,
    };

  protected:
    hkpConstraintInstance(ConstraintPriority priority);

  public:
    inline hkpEntity* getEntityA() const;
    inline const hkpConstraintData* getData() const;

  public:
    inline hkpConstraintOwner* getOwner() const;

  public:
    class SmallArraySerializeOverrideType
    {
      public:
        __forceinline void* __cdecl operator new(std::size_t nbytes)
        {
            ;
            void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                hkMemoryRouter::getInstance().heap().blockFree(
                    p, sizeof(hkpConstraintInstance::SmallArraySerializeOverrideType));
            }
        }
        __forceinline void* __cdecl operator new(std::size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](std::size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        static const struct ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();
        struct DefaultStruct;
        void* m_data;
        hkUint16 m_iElementCount;
        hkUint16 m_iCapacityState;
    };

  private:
    friend class ConstraintInstanceOwner;

  protected:
    friend class hkpSimpleContactConstraintData;
    class hkpConstraintOwner* m_pOwnerObject;
    class hkpConstraintData* m_data;

  public:
    hkEnum<ConstraintPriority, hkUint8> m_priority;

  protected:
    hkBool m_bWantRuntime;

  public:
    hkEnum<OnDestructionRemapInfo, hkUint8> m_eDestructionRemapInfo;
};
inline const hkpConstraintData* hkpConstraintInstance::getData() const
{
    return m_data;
}
class hkDebugDisplayHandler;
class DebugDisplayHandlerHolder
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  protected:
    hkDebugDisplayHandler* m_pDisplayHandler;

  public:
    DebugDisplayHandlerHolder();
};
class ConstraintDrawer
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }

  protected:

  private:
    hkReal m_fLineLength;
    hkReal m_fArcRadius;
    hkReal m_fConeAngle;
    hkReal m_fPlaneAngle;
    hkReal m_fPlaneRadius;
    hkReal m_iPlaneCount;
    int m_iArcSegmentCount;
    hkReal m_vScale;

  protected:
    hkReal getLineLengthForDraw()
    {
        return m_vScale * m_fLineLength;
    }
    hkReal getArcRadiusForDraw()
    {
        return m_vScale * m_fArcRadius;
    }
    int getNumArcSegmentsForDraw()
    {
        return m_iArcSegmentCount;
    }

  protected:
    hkVector4 m_vFirstConstraintPivot;
    hkVector4 m_vSecondConstraintPivot;
    hkVector4 m_vVectorAtOffset40;
    hkVector4 m_vVectorAtOffset50;
    hkRotation m_kFirstRotation;
    hkRotation m_kSecondRotation;
    DebugDisplayHandlerHolder m_kDisplayGeometry;
};
class hkDisplayGeometry : public hkReferencedObject
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        hkReferencedObject* b = static_cast<hkReferencedObject*>(
            hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        ;
        return b;
    }

  protected:
    hkTransform m_kMotionTransform;
};
class hkDisplaySemiCircle : public hkDisplayGeometry
{
  public:
    hkDisplaySemiCircle(const hkVector4& center, const hkVector4& normal, const hkVector4& startPerp,
                        const hkReal thetaMin, const hkReal thetaMax, const hkReal radius, const int numSegments);

  protected:
    hkVector4 m_vHitNormal;
};
class HingeConstraintDrawer : public ConstraintDrawer
{
  public:
    __forceinline void* __cdecl operator new(std::size_t nbytes)
    {
        ;
        void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline void __cdecl operator delete(void* p)
    {
        if (p)
        {
            ;
            hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(HingeConstraintDrawer));
        }
    }
    __forceinline void* __cdecl operator new(std::size_t n, void* p)
    {
        ;
        return p;
    }
    __forceinline void* __cdecl operator new[](std::size_t, void* p)
    {
        return p;
    }
    __forceinline void __cdecl operator delete(void*, void*)
    {}
    __forceinline void __cdecl operator delete[](void*, void*)
    {}
    class CommandArgument;
    __forceinline void drawHinge(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, hkUlong id,
                                 int tag);

  protected:
    hkDisplaySemiCircle m_fAngularLimit;
};
struct hkpConstraintAtom
{
  public:
    enum AtomType
    {
        TYPE_INVALID = 0,
        TYPE_BRIDGE,
        TYPE_SET_LOCAL_TRANSFORMS,
        TYPE_SET_LOCAL_TRANSLATIONS,
        TYPE_SET_LOCAL_ROTATIONS,
        TYPE_BALL_SOCKET,
        TYPE_STIFF_SPRING,
        TYPE_LIN,
        TYPE_LIN_SOFT,
        TYPE_LIN_LIMIT,
        TYPE_LIN_FRICTION,
        TYPE_LIN_MOTOR,
        TYPE_2D_ANG,
        TYPE_ANG,
        TYPE_ANG_LIMIT,
        TYPE_TWIST_LIMIT,
        TYPE_CONE_LIMIT,
        TYPE_ANG_FRICTION,
        TYPE_ANG_MOTOR,
        TYPE_RAGDOLL_MOTOR,
        TYPE_PULLEY,
        TYPE_OVERWRITE_PIVOT,
        TYPE_CONTACT,
        TYPE_MODIFIER_SOFT_CONTACT,
        TYPE_MODIFIER_MASS_CHANGER,
        TYPE_MODIFIER_VISCOUS_SURFACE,
        TYPE_MODIFIER_MOVING_SURFACE,
        TYPE_MODIFIER_IGNORE_CONSTRAINT,
        TYPE_MODIFIER_CENTER_OF_MASS_CHANGER,
        TYPE_MAX
    };

  public:
    __forceinline enum AtomType getType() const
    {
        return m_type;
    }

  protected:
    hkpConstraintAtom(enum AtomType type) : m_type(type)
    {}

  public:
    hkpConstraintAtom(FinishingFlag f)
    {}

  private:
    hkpConstraintAtom();

  public:
    hkEnum<AtomType, hkUint16> m_type;
};
struct hkpSetLocalRotationsConstraintAtom : public hkpConstraintAtom
{
    hkpSetLocalRotationsConstraintAtom() : hkpConstraintAtom(TYPE_SET_LOCAL_ROTATIONS)
    {}
    hkpSetLocalRotationsConstraintAtom(FinishingFlag f) : hkpConstraintAtom(f)
    {}
    hkRotation m_kRotationA;
    hkRotation m_kRotationB;
};
struct hkp2dAngConstraintAtom : public hkpConstraintAtom
{
    hkp2dAngConstraintAtom() : hkpConstraintAtom(TYPE_2D_ANG)
    {}
    hkp2dAngConstraintAtom(FinishingFlag f) : hkpConstraintAtom(f)
    {}
};
struct hkpAngLimitConstraintAtom : public hkpConstraintAtom
{
    hkpAngLimitConstraintAtom() : hkpConstraintAtom(TYPE_ANG_LIMIT), m_bLimitEnabled(true)
    {}
    hkpAngLimitConstraintAtom(FinishingFlag f) : hkpConstraintAtom(f)
    {}
    hkUint8 m_bLimitEnabled;
    hkReal m_fMinAngle;
    hkReal m_fMaxAngle;
};
class hkpHingeLimitsData : public hkpConstraintData
{
  public:
    static const struct ClassMemberDescriptor Members[];
    inline hkReal getMaxAngularLimit() const;
    inline hkReal getMinAngularLimit() const;

  public:
    struct Atoms
    {
        __forceinline void* __cdecl operator new(std::size_t nbytes)
        {
            ;
            void* obj = hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                hkMemoryRouter::getInstance().heap().blockFree(p, sizeof(hkpHingeLimitsData::Atoms));
            }
        }
        __forceinline void* __cdecl operator new(std::size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](std::size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        static const struct ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();
        struct DefaultStruct;
        struct hkpSetLocalRotationsConstraintAtom m_kLocalRotations;
        struct hkpAngLimitConstraintAtom m_kAngularLimit;
        struct hkp2dAngConstraintAtom m_kTwoDimensionalAngular;
        enum Axis
        {
            AXIS_AXLE = 0,
            AXIS_PERP_TO_AXLE_1 = 1,
            AXIS_PERP_TO_AXLE_2 = 2
        };
        Atoms()
        {}
        const hkpConstraintAtom* getAtoms() const
        {
            return &m_kLocalRotations;
        }
        int getSizeOfAllAtoms() const
        {
            return hkGetByteOffsetInt(this, &m_kTwoDimensionalAngular + 1);
        }
        Atoms(FinishingFlag f) : m_kLocalRotations(f), m_kAngularLimit(f), m_kTwoDimensionalAngular(f)
        {}
    };
    __declspec(align(16)) struct Atoms m_kBridgeAtoms;

  public:
    virtual void PopulateInfo(ConstraintInfo& infoOut) const;

  public:
    hkpHingeLimitsData(FinishingFlag f) : hkpConstraintData(f), m_kBridgeAtoms(f)
    {}
};
inline hkReal hkpHingeLimitsData::getMaxAngularLimit() const
{
    return m_kBridgeAtoms.m_kAngularLimit.m_fMaxAngle;
}
inline hkReal hkpHingeLimitsData::getMinAngularLimit() const
{
    return m_kBridgeAtoms.m_kAngularLimit.m_fMinAngle;
}
class hkDebugDisplayHandler
{
  public:
    enum Command
    {
        HK_STEP = 0x00,
        HK_ADD_GEOMETRY,
        HK_UPDATE_GEOMETRY,
        HK_SET_COLOR_GEOMETRY,
        HK_REMOVE_GEOMETRY,
        HK_DISPLAY_GEOMETRY_WITH_TRANSFORM,
        HK_DISPLAY_GEOMETRY,
        HK_DISPLAY_POINT,
        HK_DISPLAY_LINE,
        HK_DISPLAY_TEXT,
        HK_SEND_STATISTICS_DUMP_DEPRICATED,
        HK_HOLD_IMMEDIATE,
        HK_ADD_CAMERA,
        HK_UPDATE_CAMERA,
        HK_REMOVE_CAMERA,
        HK_SEND_MEMSTATS_DUMP,
        HK_ADD_GEOMETRY_INSTANCE,
        HK_DISPLAY_TEXT_3D,
        HK_UPDATE_BEHAVIOR,
        HK_LIST_BEHAVIORS,
        HK_DISPLAY_ANNOTATION,
    };
    virtual ~hkDebugDisplayHandler()
    {}
    virtual hkResult AddDisplayGeometry(const HavokElementArray<hkDisplayGeometry*>& geometries, const hkTransform& transform,
                                 hkUlong id, int tag, hkUlong shapeIdHint) = 0;
    virtual hkResult ReplaceGeometry(hkUlong origianalGeomId, const hkTransform& transform, hkUlong id, int tag,
                                     hkUlong shapeIdHint) = 0;
    virtual hkResult SetGeometryColor(int color, hkUlong id, int tag) = 0;
    virtual hkResult m_bUpdateGeometry(const hkTransform& transform, hkUlong id, int tag) = 0;
    virtual hkResult RemoveGeometry(hkUlong id, int tag, hkUlong shapeIdHint) = 0;
    virtual hkResult DisplayCamera(const hkVector4& from, const hkVector4& to, const hkVector4& up, hkReal nearPlane,
                                   hkReal farPlane, hkReal fov, const char* name) = 0;
    virtual hkResult DisplayBehaviorGraph(const HavokElementArray<int>& wordVarIdx, const HavokElementArray<int>& wordStack,
                                          const HavokElementArray<int>& quadVarIdx, const HavokElementArray<hkVector4>& quadStack,
                                          const HavokElementArray<char*>& activeNodes, const HavokElementArray<int>& activeStateIds,
                                          const HavokElementArray<int>& activeTransitions,
                                          const HavokElementArray<hkQsTransform>& transforms) = 0;
    virtual hkResult DisplayPoint(const hkVector4& position, int colour, hkUlong id, int tag) = 0;
    virtual hkResult DisplayLine(const hkVector4& start, const hkVector4& end, int color, hkUlong id, int tag) = 0;
    virtual hkResult DisplayTriangle(const hkVector4& a, const hkVector4& b, const hkVector4& c, int colour, hkUlong id,
                                     int tag) = 0;
    virtual hkResult displayText(const char* text, int color, hkUlong id, int tag) = 0;
    virtual hkResult Display3DText(const char* text, const hkVector4& pos, int color, hkUlong id, int tag) = 0;
    virtual hkResult DisplayAnnotation(const char* text, hkUlong id, int tag)
    {
        return HK_SUCCESS;
    }
    virtual hkResult DisplayGeometryList(const HavokElementArray<hkDisplayGeometry*>& geometries, int color, hkUlong id,
                                         int tag) = 0;
};
class hkColor
{
  public:
    static int __cdecl rgbFromChars(unsigned char red, unsigned char green, unsigned char blue,
                                    unsigned char alpha = 0xff);

  public:
    enum ExtendedColors
    {
        MAROON = 0xFF800000,
        DARKRED = 0xFF8B0000,
        RED = 0xFFFF0000,
        LIGHTPINK = 0xFFFFB6C1,
        CRIMSON = 0xFFDC143C,
        PALEVIOLETRED = 0xFFDB7093,
        HOTPINK = 0xFFFF69B4,
        DEEPPINK = 0xFFFF1493,
        MEDIUMVIOLETRED = 0xFFC71585,
        PURPLE = 0xFF800080,
        DARKMAGENTA = 0xFF8B008B,
        ORCHID = 0xFFDA70D6,
        THISTLE = 0xFFD8BFD8,
        PLUM = 0xFFDDA0DD,
        VIOLET = 0xFFEE82EE,
        FUCHSIA = 0xFFFF00FF,
        MAGENTA = 0xFFFF00FF,
        MEDIUMORCHID = 0xFFBA55D3,
        DARKVIOLET = 0xFF9400D3,
        DARKORCHID = 0xFF9932CC,
        BLUEVIOLET = 0xFF8A2BE2,
        INDIGO = 0xFF4B0082,
        MEDIUMPURPLE = 0xFF9370DB,
        SLATEBLUE = 0xFF6A5ACD,
        MEDIUMSLATEBLUE = 0xFF7B68EE,
        DARKBLUE = 0xFF00008B,
        MEDIUMBLUE = 0xFF0000CD,
        BLUE = 0xFF0000FF,
        NAVY = 0xFF000080,
        MIDNIGHTBLUE = 0xFF191970,
        DARKSLATEBLUE = 0xFF483D8B,
        ROYALBLUE = 0xFF4169E1,
        CORNFLOWERBLUE = 0xFF6495ED,
        LIGHTSTEELBLUE = 0xFFB0C4DE,
        ALICEBLUE = 0xFFF0F8FF,
        GHOSTWHITE = 0xFFF8F8FF,
        LAVENDER = 0xFFE6E6FA,
        DODGERBLUE = 0xFF1E90FF,
        STEELBLUE = 0xFF4682B4,
        DEEPSKYBLUE = 0xFF00BFFF,
        SLATEGRAY = 0xFF708090,
        LIGHTSLATEGRAY = 0xFF778899,
        LIGHTSKYBLUE = 0xFF87CEFA,
        SKYBLUE = 0xFF87CEEB,
        LIGHTBLUE = 0xFFADD8E6,
        TEAL = 0xFF008080,
        DARKCYAN = 0xFF008B8B,
        DARKTURQUOISE = 0xFF00CED1,
        CYAN = 0xFF00FFFF,
        MEDIUMTURQUOISE = 0xFF48D1CC,
        CADETBLUE = 0xFF5F9EA0,
        PALETURQUOISE = 0xFFAFEEEE,
        LIGHTCYAN = 0xFFE0FFFF,
        AZURE = 0xFFF0FFFF,
        LIGHTSEAGREEN = 0xFF20B2AA,
        TURQUOISE = 0xFF40E0D0,
        POWDERBLUE = 0xFFB0E0E6,
        DARKSLATEGRAY = 0xFF2F4F4F,
        AQUAMARINE = 0xFF7FFFD4,
        MEDIUMSPRINGGREEN = 0xFF00FA9A,
        MEDIUMAQUAMARINE = 0xFF66CDAA,
        SPRINGGREEN = 0xFF00FF7F,
        MEDIUMSEAGREEN = 0xFF3CB371,
        SEAGREEN = 0xFF2E8B57,
        LIMEGREEN = 0xFF32CD32,
        DARKGREEN = 0xFF006400,
        GREEN = 0xFF008000,
        LIME = 0xFF00FF00,
        FORESTGREEN = 0xFF228B22,
        DARKSEAGREEN = 0xFF8FBC8F,
        LIGHTGREEN = 0xFF90EE90,
        PALEGREEN = 0xFF98FB98,
        MINTCREAM = 0xFFF5FFFA,
        HONEYDEW = 0xFFF0FFF0,
        CHARTREUSE = 0xFF7FFF00,
        LAWNGREEN = 0xFF7CFC00,
        OLIVEDRAB = 0xFF6B8E23,
        DARKOLIVEGREEN = 0xFF556B2F,
        YELLOWGREEN = 0xFF9ACD32,
        GREENYELLOW = 0xFFADFF2F,
        BEIGE = 0xFFF5F5DC,
        LINEN = 0xFFFAF0E6,
        LIGHTGOLDENRODYELLOW = 0xFFFAFAD2,
        OLIVE = 0xFF808000,
        YELLOW = 0xFFFFFF00,
        LIGHTYELLOW = 0xFFFFFFE0,
        IVORY = 0xFFFFFFF0,
        DARKKHAKI = 0xFFBDB76B,
        KHAKI = 0xFFF0E68C,
        PALEGOLDENROD = 0xFFEEE8AA,
        WHEAT = 0xFFF5DEB3,
        GOLD = 0xFFFFD700,
        LEMONCHIFFON = 0xFFFFFACD,
        PAPAYAWHIP = 0xFFFFEFD5,
        DARKGOLDENROD = 0xFFB8860B,
        GOLDENROD = 0xFFDAA520,
        ANTIQUEWHITE = 0xFFFAEBD7,
        CORNSILK = 0xFFFFF8DC,
        OLDLACE = 0xFFFDF5E6,
        MOCCASIN = 0xFFFFE4B5,
        NAVAJOWHITE = 0xFFFFDEAD,
        ORANGE = 0xFFFFA500,
        BISQUE = 0xFFFFE4C4,
        TAN = 0xFFD2B48C,
        DARKORANGE = 0xFFFF8C00,
        BURLYWOOD = 0xFFDEB887,
        SADDLEBROWN = 0xFF8B4513,
        SANDYBROWN = 0xFFF4A460,
        BLANCHEDALMOND = 0xFFFFEBCD,
        LAVENDERBLUSH = 0xFFFFF0F5,
        SEASHELL = 0xFFFFF5EE,
        FLORALWHITE = 0xFFFFFAF0,
        SNOW = 0xFFFFFAFA,
        PERU = 0xFFCD853F,
        PEACHPUFF = 0xFFFFDAB9,
        CHOCOLATE = 0xFFD2691E,
        SIENNA = 0xFFA0522D,
        LIGHTSALMON = 0xFFFFA07A,
        CORAL = 0xFFFF7F50,
        DARKSALMON = 0xFFE9967A,
        MISTYROSE = 0xFFFFE4E1,
        ORANGERED = 0xFFFF4500,
        SALMON = 0xFFFA8072,
        TOMATO = 0xFFFF6347,
        ROSYBROWN = 0xFFBC8F8F,
        PINK = 0xFFFFC0CB,
        INDIANRED = 0xFFCD5C5C,
        LIGHTCORAL = 0xFFF08080,
        BROWN = 0xFFA52A2A,
        FIREBRICK = 0xFFB22222,
        BLACK = 0xFF000000,
        DIMGRAY = 0xFF696969,
        GRAY = 0xFF808080,
        DARKGRAY = 0xFFA9A9A9,
        SILVER = 0xFFC0C0C0,
        LIGHTGREY = 0xFFD3D3D3,
        GAINSBORO = 0xFFDCDCDC,
        WHITESMOKE = 0xFFF5F5F5,
        WHITE = 0xFFFFFFFF,
        GREY = 0xff888888,
        GREY25 = 0xff404040,
        GREY50 = 0xff808080,
        GREY75 = 0xffc0c0c0,
    };
};
__forceinline void HingeConstraintDrawer::drawHinge(hkpConstraintInstance* constraint,
                                                    hkDebugDisplayHandler* displayHandler, hkUlong id, int tag)
{
    const hkpHingeLimitsData* lhinge = static_cast<const hkpHingeLimitsData*>(constraint->getData());
    reinterpret_cast<::CpuObject *>(&(m_kDisplayGeometry))->FUN_00e10a10((displayHandler));
    hkTransform refLocalToWorld;
    hkTransform attLocalToWorld;
    reinterpret_cast<hkpConstraintDrawer*>(this)->FUN_00de47e0(constraint, &refLocalToWorld, &attLocalToWorld);
    m_vVectorAtOffset50.FUN_00c7f640(refLocalToWorld, hkVector4::getZero());
    m_vVectorAtOffset40.FUN_00c7f640(attLocalToWorld, hkVector4::getZero());
    reinterpret_cast<::FUN_00de4530Owner *>(this)->FUN_00de4530(id, tag);
    reinterpret_cast<::DE44C0Object *>(this)->FUN_00de44c0(id, tag);
    const hkVector4* baseA = &lhinge->m_kBridgeAtoms.m_kLocalRotations.m_kRotationA.getColumn(0);
    const hkVector4* baseB = &lhinge->m_kBridgeAtoms.m_kLocalRotations.m_kRotationB.getColumn(0);
    hkVector4 axisInWorld;
    axisInWorld.FUN_00c7f700(m_kSecondRotation, baseB[0]);
    hkVector4 axisPerpInWorld;
    axisPerpInWorld.FUN_00c7f700(m_kSecondRotation, baseB[2]);
    displayHandler->DisplayLine(m_vVectorAtOffset40, m_vVectorAtOffset50, hkColor::RED, id, tag);
    {
        hkVector4 startAxis, endAxis;
        endAxis.setMul4(getLineLengthForDraw() * 0.75, axisInWorld);
        endAxis.add4(m_vVectorAtOffset50);
        startAxis.setMul4(getLineLengthForDraw() * -0.75, axisInWorld);
        startAxis.add4(m_vVectorAtOffset50);
        displayHandler->DisplayLine(startAxis, endAxis, ((int)(::PackColorBigEndian(0.f, .5f, 1.f, 1.f))), id, tag);
    }
    {
        hkReal thetaMax = lhinge->getMaxAngularLimit();
        hkReal thetaMin = lhinge->getMinAngularLimit();
        reinterpret_cast<::SetupTarget *>(&(m_fAngularLimit))->FUN_00de4950(getArcRadiusForDraw(), thetaMin, thetaMax, getNumArcSegmentsForDraw(),
                                     (const ::Vec4 &)(m_vVectorAtOffset50), (const ::Vec4 &)(axisInWorld), (const ::Vec4 &)(axisPerpInWorld));
        hkArray<hkDisplayGeometry*> geometry;
        geometry.SetSizeAndGrow(1);
        geometry[0] = &m_fAngularLimit;
        displayHandler->DisplayGeometryList(geometry, hkColor::WHITE, id, tag);
    }
    {
        hkVector4 start;
        hkVector4 end;
        start = m_vVectorAtOffset50;
        end = start;
        end.addMul4(getLineLengthForDraw() * 0.75, axisPerpInWorld);
        displayHandler->DisplayLine(start, end, hkColor::YELLOW, id, tag);
        hkVector4 axisPerpA;
        axisPerpA.FUN_00c7f700(m_kFirstRotation, baseA[2]);
        axisPerpA.normalize3();
        start = m_vVectorAtOffset40;
        end = start;
        end.addMul4(getLineLengthForDraw() * 0.5, axisPerpA);
        displayHandler->DisplayLine(start, end, hkColor::YELLOW, id, tag);
    }
}
// @fnv 0x00de5fe0
extern "C" __declspec(noinline) void FUN_00de5fe0(HingeConstraintDrawer* drawer, hkpConstraintInstance* constraint,
                                                  hkDebugDisplayHandler* handler, hkUlong id, int tag)
{
    drawer->drawHinge(constraint, handler, id, tag);
}

}
