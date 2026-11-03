
// src/havok/common/scenedata/attributes/hkxattributegroup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxattributegroup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/Cb0StringCopy.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00cb0a80_class.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FUN_00e3f8e0.h"
#include "fnv/decl/FUN_00e5cdb0_class.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00d2c000.h"
#include "fnv/symbols_010ec000.h"
#include "fnv/symbols_01268000.h"
#include "havok/hkxAttributeGroup.h"


struct FUN_00cb0c00_class
{
};

class hkReferencedObject
{
  public:
};

struct hkMemoryAllocatorE5CD;


struct FUN_00cb0bd0
{
    char* m_pcString;
    FUN_00cb0bd0(const FUN_00cb0bd0& kOther) throw();
    ~FUN_00cb0bd0() throw()
    {
        ::FUN_00cb0c00((int)(((FUN_00cb0c00_class*)this)));
    }
};

struct hkRefVariantE5CD
{
    hkReferencedObject* m_pRetainedObject;
    hkRefVariantE5CD(const hkRefVariantE5CD& kOther) throw()
    {
        if (kOther.m_pRetainedObject)
            reinterpret_cast<::FUN_00c90510_class *>((kOther.m_pRetainedObject))->FUN_00c90510();
        m_pRetainedObject = kOther.m_pRetainedObject;
    }
    ~hkRefVariantE5CD() throw()
    {
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
};

struct hkxAttributeE5CD
{
    FUN_00cb0bd0 m_name;
    hkRefVariantE5CD m_uiFilterValue;
};

template <typename T> __forceinline void hkDestructE5CD(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}

template <typename T> __forceinline void hkConstructWithArrayE5CD(T* t, int n, const T* s)
{
    for (int i = 0; i < n; ++i)
        new (t + i) T(s[i]);
}

struct hkArrayE5CD
{
    hkxAttributeE5CD* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(hkMemoryAllocatorE5CD& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewSize, sizeof(hkxAttributeE5CD));
        }
    }
    void SpliceArray(hkMemoryAllocatorE5CD& kAlloc, int iIndex, int iNumDel, const hkxAttributeE5CD* pkInsert,
                     int iNumToInsert);
};

// Replaces iNumDel elements at iIndex with iNumToInsert copies of pkInsert, growing the array if needed and shifting the tail.
// @fnv 0x00e5cdb0
void hkArrayE5CD::SpliceArray(hkMemoryAllocatorE5CD& kAlloc, int iIndex, int iNumDel, const hkxAttributeE5CD* pkInsert,
                              int iNumToInsert)
{
    int iNewSize = m_iElementCount + iNumToInsert - iNumDel;
    int iNumToMove = m_iElementCount - iIndex - iNumDel;
    if (iNewSize > getCapacity())
        GrowArrayCapacity(kAlloc, iNewSize);
    hkDestructE5CD(m_data + iIndex, iNumDel);
    FUN_00d2cc70(m_data + iIndex + iNumToInsert, m_data + iIndex + iNumDel, iNumToMove * sizeof(hkxAttributeE5CD));
    hkConstructWithArrayE5CD(m_data + iIndex, iNumToInsert, pkInsert);
    m_iElementCount = iNewSize;
}

// Adapted from unverified 2026-10-25 attempts by two prior contributors.
struct NameReference
{
    unsigned int encoded;
};
struct TextWriter
{
    void** virtualMethods;
};
extern "C" const char str_010c9308[];
typedef void(* WriteMethod)(TextWriter*, const char*, int);
struct AttributeFormatter
{
    int unknown00;
    int unknown04;
    TextWriter* output;
    AttributeFormatter* WriteName(NameReference* name);
};
// Writes the string at the encoded address when encoded is nonzero; otherwise writes str_010c9308, then returns this.
// @fnv 0x00cc05a0
AttributeFormatter* AttributeFormatter::WriteName(NameReference* name)
{
    if (name->encoded & ~1u)
    {
        const char* text = (const char*)(name->encoded & ~1u);
        void** methods = output->virtualMethods;
        int length = reinterpret_cast<::FUN_00cb0a80_class *>((name))->FUN_00cb0a80();
        ((WriteMethod)methods[4])(output, text, length);
    }
    else
    {
        TextWriter* writer = output;
        ((WriteMethod)writer->virtualMethods[4])(writer, str_010c9308, 6);
    }
    return this;
}

#include <xmmintrin.h>
struct __declspec(align(16)) HMat4
{
    __m128 c0, c1, c2, c3;
};
struct MatrixHolder
{
    int type;
    int flags;
    HMat4* matrix;
};
struct AttrLookup
{
    MatrixHolder* CallWithGlobalObject(const char* name);
    int GetAttributeMatrix(const char* name, bool verbose, HMat4* result);
};
struct MessageBuilder
{
    int storage;
    int length;
    int capacity;
};
struct AssertHandler
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void assertFailure(int enabled, unsigned int code, void* msg, const char* source, unsigned int line);
};
extern "C" char DAT_010ecd74[];
// Copies the named attribute's matrix into result when found; if missing, optionally reports an assertion failure and returns 1.
// @fnv 0x00e5cc00
int AttrLookup::GetAttributeMatrix(const char* apAttributeName, bool verbose, HMat4* result)
{
    MatrixHolder* attribute = CallWithGlobalObject(apAttributeName);
    if (attribute)
    {
        __m128* source = reinterpret_cast<__m128*>(attribute->matrix);
        __m128* output = reinterpret_cast<__m128*>(result);
        output[0] = source[0];
        output[1] = source[1];
        output[2] = source[2];
        output[3] = source[3];
        return 0;
    }
    if (verbose)
    {
        __declspec(align(16)) void* scratch[0x80];
        MessageBuilder message;
        new ((void *)&(message)) ::FUN_00cb1600(reinterpret_cast<char*>(scratch), 0x200);
        reinterpret_cast<::SinkOwner *>((((::MessageBuilder *)(reinterpret_cast<::AttributeFormatter *>((((::MessageBuilder *)(reinterpret_cast<::SinkOwner *>((((::MessageBuilder *)(reinterpret_cast<::SinkOwner *>((((::MessageBuilder *)(reinterpret_cast<::SinkOwner *>(&(message))->FUN_00cc01c0(DAT_010ecd74)))))->FUN_00cc01c0(apAttributeName)))))->FUN_00cc01c0(::str_010eccfc)))))->WriteName((::NameReference *)(::AttrLookup *)(this))))))->FUN_00cc01c0(::str_010ecd0c);
        (*reinterpret_cast<::AssertHandler * *>(&::DAT_01268360))->assertFailure(1, 0xabbaab81, scratch, ::str_010eccc8, 0xc4);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(message))->FUN_00cc00e0::~FUN_00cc00e0();
    }
    return 1;
}

struct RefObj
{
};

struct Inner
{
};

struct Elem
{
    Inner inner;
    RefObj* ref;
};

struct NewElem
{
    int a;
    int b;
};

struct Allocator
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct ElemArray
{
    Elem* data;
    int size;
    int capacityAndFlags;

};

struct S00e5cce0_Class
{
    int unk00;
    ElemArray arr;

    S00e5cce0_Class& FUN_00e5cce0(const S00e5cce0_Class& o);
};

Allocator* __cdecl FUN_00c85750(void);

static __forceinline void destructElems(Elem* data, int n)
{
    for (int i = 0; i < n; i++)
    {
        Elem& e = data[i];
        if (e.ref != 0)
        {
            reinterpret_cast<::hkReferencedObjectC905 *>((e.ref))->FUN_00c905b0();
        }
        e.ref = 0;
        ::FUN_00cb0c00((int)&(e.inner));
    }
}

static __forceinline void constructElems(NewElem* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (&p[i] != 0)
        {
            new ((void *)&(p[i])) ::FUN_00e3f8e0();
        }
    }
}

// Calls FUN_00cb0c30(o), destroys existing elements, then copies o.arr via FUN_00e5cec0 and returns *this.
// @fnv 0x00e5cce0
S00e5cce0_Class& S00e5cce0_Class::FUN_00e5cce0(const S00e5cce0_Class& aOther)
{
    reinterpret_cast<::Cb0StringCopy *>(this)->FUN_00cb0c30((const ::CB0StringPtr &)(aOther));
    ElemArray& s = arr;
    Allocator* pAllocator = FUN_00c85750();
    int alloc = pAllocator->unk10;
    int n = 0;
    int iCapacity = s.capacityAndFlags & 0x3fffffff;
    if (iCapacity < n)
    {
        int iNewCapacity = iCapacity + iCapacity;
        ::FUN_00c908c0((::SpawnedObject *)(alloc), (::SpawnedArray *)(::ElemArray *)(&s), n < iNewCapacity ? iNewCapacity : n, 8);
    }

    destructElems(s.data, s.size);
    constructElems((NewElem*)(s.data + s.size), 0 - s.size);
    s.size = 0;

    int iCount = aOther.arr.size;
    if (iCount != 0)
    {
        Elem* src = aOther.arr.data;
        int a = FUN_00c85750()->unk10;
        reinterpret_cast<::FUN_00e5cdb0_class *>(&(s))->FUN_00e5cec0(a, 0, (int)(src), iCount);
    }
    return *this;
}

#include "generated/data/havok/common/scenedata/attributes/hkxattributegroup.inc"
