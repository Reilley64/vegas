
// src/havok/common/scenedata/mesh/hkxmeshsection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxmeshsection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/SinkOwner.h"
#include "fnv/symbols_01268000.h"
#include "fnv/decl/E673F0Geometry.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/FUN_00e3dfb0_cls.h"
#include "fnv/decl/IndexSource_e67420.h"
#include "fnv/decl/ScriptRecordList.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "havok/hkxMeshSection.h"

extern int DAT_010e9b7c;
struct IndexArray
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    IndexArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct FUN_00e61720
{
    void* m_vptr;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pMeshVertexBuffer;
    IndexArray m_kIndexBuffers;
    void* m_iMaterialIndex;
    IndexArray m_kUserChannels;
    FUN_00e61720(void* arg);
};
inline void* operator new(unsigned int, void* p)
{
    return p;
}

class hkMemoryAllocatorE6;

class hkMemoryRouterE6
{
  public:
    static hkMemoryRouterE6& GetMonitorStream();
    hkMemoryAllocatorE6& heap()
    {
        return *m_pStreamAllocator;
    }
    void* m_aiEntries;
    void* m_pTemp;
    void* m_pDebugAllocator;
    void* m_pSolver;
    hkMemoryAllocatorE6* m_pStreamAllocator;
};

class hkReferencedObjectE6
{
  public:
    virtual ~hkReferencedObjectE6();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

template <class T> class hkRefPtrE6
{
  public:
    hkRefPtrE6(const hkRefPtrE6& rp)
    {
        if (rp.m_pRetainedObject)
            reinterpret_cast<::FUN_00c90510_class *>((void *)(rp.m_pRetainedObject))->FUN_00c90510();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~hkRefPtrE6()
    {
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
    __forceinline hkRefPtrE6& operator=(const hkRefPtrE6& rp)
    {
        if (rp.m_pRetainedObject)
            reinterpret_cast<::FUN_00c90510_class *>((void *)(rp.m_pRetainedObject))->FUN_00c90510();
        if (m_pRetainedObject)
            reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pRetainedObject))->FUN_00c905b0();
        m_pRetainedObject = rp.m_pRetainedObject;
        return *this;
    }
    T* m_pRetainedObject;
};

class hkRefVariantE6 : public hkRefPtrE6<hkReferencedObjectE6>
{
  public:
    hkRefVariantE6(const hkRefVariantE6& o) : hkRefPtrE6<hkReferencedObjectE6>(o)
    {}
    __forceinline hkRefVariantE6& operator=(const hkRefVariantE6& o)
    {
        if (this != &o)
        {
            hkReferencedObjectE6* p = o.m_pRetainedObject;
            if (p)
                reinterpret_cast<::FUN_00c90510_class *>((void *)(p))->FUN_00c90510();
            if (m_pRetainedObject)
                reinterpret_cast<::hkReferencedObjectC905 *>((void *)(m_pRetainedObject))->FUN_00c905b0();
            m_pRetainedObject = p;
        }
        return *this;
    }
};

template <class T> class hkArrayE6
{
  public:
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline hkArrayE6& operator=(const hkArrayE6& a)
    {
        hkMemoryAllocatorE6& alloc = hkMemoryRouterE6::GetMonitorStream().heap();
        int oldSize = m_iElementCount;
        int newSize = a.m_iElementCount;
        int copiedSize = newSize > oldSize ? oldSize : newSize;
        if (getCapacity() < newSize)
        {
            int cap2 = 2 * getCapacity();
            int newCap = newSize < cap2 ? cap2 : newSize;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), newCap, sizeof(T));
        }
        T* pDestroy = m_data + newSize;
        for (int i = 0; i < oldSize - newSize; i++)
            pDestroy[i].~T();
        const T* pSrc = a.m_data;
        T* pDst = m_data;
        for (int i = 0; i < copiedSize; i++)
            pDst[i] = pSrc[i];
        pSrc = a.m_data + copiedSize;
        pDst = m_data + copiedSize;
        for (int i = 0; i < newSize - copiedSize; i++)
            new (&pDst[i]) T(pSrc[i]);
        m_iElementCount = newSize;
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkxVertexBufferE6;
class hkxIndexBufferE6;
class hkxMaterialE6;

class hkxMeshSectionE6 : public hkReferencedObjectE6
{
  public:
    hkxMeshSectionE6& FUN_00e61770(const hkxMeshSectionE6& o);
    hkRefPtrE6<hkReferencedObjectE6> m_pMeshVertexBuffer;
    hkArrayE6<hkRefPtrE6<hkReferencedObjectE6> > m_kIndexBuffers;
    hkRefPtrE6<hkReferencedObjectE6> m_iMaterialIndex;
    hkArrayE6<hkRefVariantE6> m_kUserChannels;
};
// @fnv 0x00e61720
FUN_00e61720::FUN_00e61720(void* arg)
    : m_vptr(&DAT_010e9b7c), m_sReferenceCount(1), m_pMeshVertexBuffer(0), m_kIndexBuffers(), m_iMaterialIndex(0),
      m_kUserChannels()
{
    reinterpret_cast<::hkxMeshSectionE6 *>(this)->FUN_00e61770((*(const ::hkxMeshSectionE6 *)(arg)));
}

// @fnv 0x00e61770
hkxMeshSectionE6& hkxMeshSectionE6::FUN_00e61770(const hkxMeshSectionE6& o)
{
    m_usMemSizeAndFlags = o.m_usMemSizeAndFlags;
    m_sReferenceCount = o.m_sReferenceCount;
    m_pMeshVertexBuffer = o.m_pMeshVertexBuffer;
    m_kIndexBuffers = o.m_kIndexBuffers;
    m_iMaterialIndex = o.m_iMaterialIndex;
    m_kUserChannels = o.m_kUserChannels;
    return *this;
}

class hkxIndexBuffer
{
  public:
};
struct MeshSection : public hkxMeshSection
{
    void FUN_00e61420(unsigned int position, unsigned int& a, unsigned int& b, unsigned int& c) const;
};
// Finds the index buffer containing the primitive at position and retrieves its vertex indices into a, b, and c.
// @fnv 0x00e61420
void MeshSection::FUN_00e61420(unsigned int aiPrimitiveIndex, unsigned int& aiVertexA, unsigned int& aiVertexB,
                               unsigned int& aiVertexC) const
{
    int start = 0;
    for (int i = 0; i < m_kIndexBuffers.m_iElementCount; i++)
    {
        hkxIndexBuffer* pIndexBuffer = m_kIndexBuffers.m_data[i];
        int iPrimitiveCount = reinterpret_cast<::E673F0Geometry *>((void *)(pIndexBuffer))->GetPrimitiveCount();
        if (aiPrimitiveIndex < (unsigned)(start + iPrimitiveCount))
        {
            reinterpret_cast<::IndexSource_e67420 *>((void *)(pIndexBuffer))->FUN_00e67420(aiPrimitiveIndex - start, (unsigned int *)&(aiVertexA), (unsigned int *)&(aiVertexB), (unsigned int *)&(aiVertexC));
            return;
        }
        start += iPrimitiveCount;
    }
}

#include <xmmintrin.h>
template <class T> struct hkArray_e614
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void SetSizeAndGrow(int n)
    {
        hkMemoryAllocatorE6& alloc = hkMemoryRouterE6::GetMonitorStream().heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = 2 * cap;
            ::FUN_00c908c0((::SpawnedObject *)&(alloc), (::SpawnedArray *)(void *)(this), n < cap2 ? cap2 : n, sizeof(T));
        }
        m_iElementCount = n;
    }
};

struct VertexDesc_e614
{
    int unk00, unk04;
    int m_iElementIndex;
};

struct VertexFormat_e614
{
};

struct VertexBuffer_e614
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int m_iStridedVertexCount;
    int unk48, unk4C, unk50, unk54, unk58;
    VertexFormat_e614 m_eVertexFormat;
};

struct Mesh_e614
{
    int unk00, unk04;
    VertexBuffer_e614* m_pMeshVertexBuffer;
    void FUN_00e61480(hkArray_e614<__m128>& positions);
};

// Copies vertex position vectors from the mesh vertex buffer into the positions array, growing it as needed.
// @fnv 0x00e61480
void Mesh_e614::FUN_00e61480(hkArray_e614<__m128>& positions)
{
    VertexBuffer_e614* pVertexBuffer = m_pMeshVertexBuffer;
    if (!pVertexBuffer)
        return;
    VertexDesc_e614* desc = ((::VertexDesc_e614 *)(reinterpret_cast<::ScriptRecordList *>(&(pVertexBuffer->m_eVertexFormat))->FindByTypeAndOccurrence(1, 0)));
    int numVertices = pVertexBuffer->m_iStridedVertexCount;
    if (!desc || numVertices <= 0)
        return;
    const char* src = ((const char *)(reinterpret_cast<::FUN_00e3dfb0_cls *>((pVertexBuffer))->FUN_00e3dfb0((::FUN_00e3dfb0_arg *)(desc))));
    int stride = desc->m_iElementIndex;
    int base = positions.m_iElementCount;
    positions.SetSizeAndGrow(base + numVertices);
    for (int i = 0; i < numVertices; i++)
    {
        positions.m_data[base + i] = *(const __m128*)src;
        src += stride;
    }
}


struct hkGeometryTriangle
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
};

struct hkGeometryData
{
    hkArray<hkVector4> m_kVertices;
    hkArray<hkGeometryTriangle> m_uiTriangleCount;
};

struct hkContainerAllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* unk10;
};

hkContainerAllocHolder* FUN_00c85750();
void ResizeAudioStream(void* alloc, void* array, int elemSize);

class hkErrStreamData
{
  public:
    hkErrStreamData(void* buf, int size) throw();
    ~hkErrStreamData() throw();
    hkErrStreamData& operator<<(const char* str) throw();
    void* unk00;
    int unk04;
    void* unk08;
};

class hkErrorData
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};


static inline void PushBackTriangle(hkArray<hkGeometryTriangle>& arr, const hkGeometryTriangle& t)
{
    hkContainerAllocHolder* holder = FUN_00c85750();
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(holder->unk10, &arr, sizeof(hkGeometryTriangle));
    arr.m_data[arr.m_iElementCount++] = t;
}

class hkxMeshSectionImpl : public hkxMeshSection
{
  public:
    void FUN_00e61480(hkGeometryData& geometry);
    void FUN_00e61530(hkGeometryData& geometry, int materialIndex);
};

// @fnv 0x00e61530
void hkxMeshSectionImpl::FUN_00e61530(hkGeometryData& geometry, int materialIndex)
{
    FUN_00e61480(geometry);

    for (int ib = 0; ib < m_kIndexBuffers.m_iElementCount; ib++)
    {
        hkxIndexBuffer* ibuffer = m_kIndexBuffers.m_data[ib];
        int numIndices = ibuffer->m_kIndices16.m_iElementCount | ibuffer->m_kIndices32.m_iElementCount;
        bool is16 = ibuffer->m_kIndices16.m_iElementCount > 0;

        int ci = 0;
        while (ci < numIndices)
        {
            hkGeometryTriangle tri;
            switch (ibuffer->m_eIndexType)
            {
            case 1:
                tri.m_kPointA = is16 ? ibuffer->m_kIndices16.m_data[ci] : ibuffer->m_kIndices32.m_data[ci];
                tri.m_kPointB = is16 ? ibuffer->m_kIndices16.m_data[ci + 1] : ibuffer->m_kIndices32.m_data[ci + 1];
                tri.m_iThirdValue = is16 ? ibuffer->m_kIndices16.m_data[ci + 2] : ibuffer->m_kIndices32.m_data[ci + 2];
                ci += 3;
                break;
            case 2:
                if (ci < 2)
                {
                    ci++;
                    continue;
                }
                if (ci == 2)
                {
                    tri.m_kPointA = is16 ? ibuffer->m_kIndices16.m_data[0] : ibuffer->m_kIndices32.m_data[0];
                    tri.m_kPointB = is16 ? ibuffer->m_kIndices16.m_data[1] : ibuffer->m_kIndices32.m_data[1];
                    tri.m_iThirdValue = is16 ? ibuffer->m_kIndices16.m_data[2] : ibuffer->m_kIndices32.m_data[2];
                    ci = 3;
                }
                else
                {
                    hkGeometryTriangle& last = geometry.m_uiTriangleCount.m_data[geometry.m_uiTriangleCount.m_iElementCount - 1];
                    tri.m_kPointA = last.m_iThirdValue;
                    tri.m_kPointB = last.m_kPointB;
                    tri.m_iThirdValue = is16 ? ibuffer->m_kIndices16.m_data[ci] : ibuffer->m_kIndices32.m_data[ci];
                    ci++;
                }
                break;
            default: {
                char buf[512];
                hkErrStreamData ostr(buf, sizeof(buf));
                reinterpret_cast<::SinkOwner *>((void *)&(const ::hkErrStreamData &)(ostr))->FUN_00cc01c0("Unsupported index buffer type - Ignoring");
                (*reinterpret_cast<::hkErrorData * *>(&::DAT_01268360))->message(1, 0xabbaa883, buf, ".\\Mesh\\hkxMeshSection.cpp", 141);
            }
                ci = numIndices;
                continue;
            }

            tri.m_iMaterialIndex = materialIndex;
            PushBackTriangle(geometry.m_uiTriangleCount, tri);
        }
    }
}
