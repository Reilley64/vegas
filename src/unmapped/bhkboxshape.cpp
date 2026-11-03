#include <cstddef>
#include <xmmintrin.h>
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_010c7000.h"
#include "fnv/symbols_01272000.h"
#include "fnv/tls.h"
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ThreadStateGuard
{
    int m_iSaved;
    ThreadStateGuard()
    {
        m_iSaved = g_tlsBlock.memoryContext;
        g_tlsBlock.memoryContext = 0x10;
    }
    ~ThreadStateGuard()
    {
        g_tlsBlock.memoryContext = m_iSaved;
    }
};

struct hkMemoryAllocatorX
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int);
    virtual void ReleaseBlock(void*, int);
};

struct hkMemoryRouterX
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorX* m_pHeap;
    hkMemoryAllocatorX& heap()
    {
        return *m_pHeap;
    }
};

hkMemoryRouterX* __cdecl FUN_00c85750();

struct hkVector4X
{
    __m128 m_vComponents;
    hkVector4X(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct SpawnSource
{
    int unk00, unk04, unk08, unk0C;
    float m_fVectorY, m_fVectorZ, m_fScalarPart, m_fVectorX;
};

struct SpawnedRefObject
{
    void* m_pVtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    static void* operator new(std::size_t n)
    {
        SpawnedRefObject* b = (SpawnedRefObject*)FUN_00c85750()->heap().AllocateMemoryBlock(n);
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    static void operator delete(void* p, std::size_t n)
    {
        FUN_00c85750()->m_pHeap->ReleaseBlock(p, n);
    }
    SpawnedRefObject(const hkVector4X&, float);
};

struct SpawnOwner
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
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35(SpawnedRefObject*);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(SpawnSource*);
    void FUN_00ca0190(SpawnSource*);
};

// @fnv 0x00ca0190
void SpawnOwner::FUN_00ca0190(SpawnSource* pSource)
{
    ThreadStateGuard kGuard;
    SpawnedRefObject* pObject = new SpawnedRefObject(
        hkVector4X(pSource->m_fVectorY, pSource->m_fVectorZ, pSource->m_fScalarPart, pSource->m_fVectorX),
        DAT_010c72bc);
    v35(pObject);
    reinterpret_cast<::hkReferencedObjectC905 *>((pObject))->FUN_00c905b0();
    v47(pSource);
}
