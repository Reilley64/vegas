
// src/havok/common/scenedata/alignscene/hkalignscenetonodeoptions.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/alignscene/hkalignscenetonodeoptions.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <xmmintrin.h>
#include "fnv/decl/S_00e3ed00_Foo.h"
#include "fnv/symbols_00cb0000.h"
#include "havok/hkAlignSceneToNodeOptions.h"

struct Inner
{
};

struct FUN_00e4a540_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Inner* m_14;
    void FUN_00e4a540();
};

// @fnv 0x00e4a540
void FUN_00e4a540_cls::FUN_00e4a540()
{
    reinterpret_cast<::S_00e3ed00_Foo *>((m_14))->AppendToTraversalList({}, {});
}

class hkMemoryAllocatorE4AF
{
  public:
    virtual ~hkMemoryAllocatorE4AF() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE4AF
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    hkMemoryAllocatorE4AF* m_pStreamAllocator;
    hkMemoryAllocatorE4AF& heap()
    {
        return *m_pStreamAllocator;
    }
};

class FUN_00cb0c00_class
{
  public:
    const char* m_pcText;

    ~FUN_00cb0c00_class()
    {
        ::FUN_00cb0c00((intptr_t)this);
    }
};

class hkReferencedObjectE4AF
{
  public:
    virtual ~hkReferencedObjectE4AF() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        (*static_cast<hkMemoryRouterE4AF*>(::FUN_00c85750())).heap().ReleaseBlock(p, static_cast<hkReferencedObjectE4AF*>(p)->m_usMemSizeAndFlags);
    }
};

class hkAlignSceneToNodeOptionsE4AF : public hkReferencedObjectE4AF
{
  public:
    hkBool m_bOption1;
    hkBool m_bOption2;
    hkBool m_bOption3;
    hkBool m_bOption4;
    hkBool m_bOption5;
    hkBool m_bOption6;
    hkBool m_bOption7;
    hkInt32 m_iOptionValue;
    FUN_00cb0c00_class m_kNodeName;

    hkAlignSceneToNodeOptionsE4AF* FUN_00e4afa0(unsigned int uiFlags) throw();
};

// Destroys the object and, when uiFlags has bit 0 set, frees its memory via operator delete; returns this.
// @fnv 0x00e4afa0
hkAlignSceneToNodeOptionsE4AF* hkAlignSceneToNodeOptionsE4AF::FUN_00e4afa0(unsigned int uiFlags) throw()
{
    this->hkAlignSceneToNodeOptionsE4AF::~hkAlignSceneToNodeOptionsE4AF();
    if (uiFlags & 1)
        ::operator delete(this);
    return this;
}


struct HeapAllocE4
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
struct RouterE4
{
    int unk00, unk04, unk08, unk0c;
    HeapAllocE4* m_pStreamAllocator;
    HeapAllocE4& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};
struct Vec4E4
{
    __m128 m_vComponents;
    __forceinline Vec4E4& operator=(const Vec4E4& v) throw()
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void setZero4() throw()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline float& operator()(int i) throw()
    {
        return ((float*)&m_vComponents)[i];
    }
};
struct Matrix4E4
{
    Vec4E4 m_kColumn0, m_kColumn1, m_kColumn2, m_kColumn3;
    __forceinline void setIdentity() throw()
    {
        Vec4E4 zero;
        zero.setZero4();
        m_kColumn0 = zero;
        m_kColumn1 = zero;
        m_kColumn2 = zero;
        m_kColumn3 = zero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
        m_kColumn3(3) = 1.0f;
    }
};
struct MatArrE4
{
    Matrix4E4* m_data;
    int m_iElementCount;
    int m_cap;
};
struct PoseE4
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    MatArrE4 m_mats;
};
template <class T, int N> struct InplaceArrE4
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];
    __forceinline InplaceArrE4() throw()
    {
        static_cast<T* volatile&>(m_data) = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = N | 0x80000000;
    }
    __forceinline int GetLogicalSize() const throw()
    {
        return m_iElementCount;
    }
    __forceinline T& operator[](int i) throw()
    {
        return m_data[i];
    }
    __forceinline void release() throw()
    {
        HeapAllocE4& h = ((RouterE4*)&(*static_cast<hkMemoryRouterE4AF*>(::FUN_00c85750())))->heap();
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            h.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    __forceinline ~InplaceArrE4() throw()
    {
        release();
    }
};
struct NodeOpsE4
{
    int FUN_00e4a540(void* pSrc, InplaceArrE4<PoseE4*, 32>& arr) throw();
    int FUN_00e4a5a0(void* volatile pSrc, Matrix4E4* pOut, int iIndex);
};
// Initializes pOut, then passes one indexed matrix from each gathered pose to FUN_00de8e50; returns 1 when gathering returns nonzero.
// @fnv 0x00e4a5a0
int NodeOpsE4::FUN_00e4a5a0(void* volatile pSrc, Matrix4E4* pOut, int iIndex)
{
    InplaceArrE4<PoseE4*, 32> arr;
    void* source = pSrc;
    if (FUN_00e4a540(source, arr))
        return 1;
    pOut->setIdentity();
    for (int i = 0; i < arr.GetLogicalSize(); i++)
    {
        PoseE4* p = arr[i];
        int n = p->m_mats.m_iElementCount;
        int idx = (iIndex < n) ? iIndex : n - 1;
        reinterpret_cast<::hkMatrix4 *>((pOut))->FUN_00de8e50((const ::hkMatrix4 &)(p->m_mats.m_data[idx]));
    }
    return 0;
}
