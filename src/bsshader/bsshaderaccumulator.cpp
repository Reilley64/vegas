// bsshader/bsshaderaccumulator.cpp: BSShaderAccumulator, AccumWIP, AccumS, Candidate and more (38 functions)

#include <windows.h>
#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/AlphaList.h"
#include "fnv/decl/BB97550Shader.h"
#include "fnv/decl/BSBatchRenderer_AlphaDepth.h"
#include "fnv/decl/BSRenderedTexture.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BatchRenderer.h"
#include "fnv/decl/CameraState4E9.h"
#include "fnv/decl/DispatchOwner.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/FUN_00b63bf0_cls.h"
#include "fnv/decl/FUN_00b63e90_cls.h"
#include "fnv/decl/FUN_00c4ed40_cls.h"
#include "fnv/decl/FUN_00c4edb0_Class.h"
#include "fnv/decl/Lighting30Shader.h"
#include "fnv/decl/Manager.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiRenderer.h"
#include "fnv/decl/Pool.h"
#include "fnv/decl/RefractionImageSpaceEffect.h"
#include "fnv/decl/RenderOwner.h"
#include "fnv/decl/S_00b601a0_Map.h"
#include "fnv/decl/S_00c4ed70_Class.h"
#include "fnv/decl/S_00c4edf0_cls.h"
#include "fnv/decl/TextureOwnerB63.h"
#include "fnv/decl/TextureOwnerB63D.h"
#include "fnv/decl/TextureRenderer.h"
#include "fnv/decl/fnv_00b9a3c0__FUN_00b9a3c0_shell.h"
#include "fnv/decl/fnv_00b9af60__Renderer_af60.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b55000.h"
#include "fnv/symbols_00b63000.h"
#include "fnv/symbols_00b64000.h"
#include "fnv/symbols_00b65000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_00b7a000.h"
#include "fnv/symbols_00b97000.h"
#include "fnv/symbols_00b98000.h"
#include "fnv/symbols_00b99000.h"
#include "fnv/symbols_00b9a000.h"
#include "fnv/symbols_00ba8000.h"
#include "fnv/symbols_00bd9000.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01073000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_010ad000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011fa000.h"
#include "fnv/symbols_011ff000.h"
#include "fnv/symbols_01200000.h"
#include "bsshaderaccumulator_types.h"

// offset-exact local views to dodge the task headers' mutually conflicting
// into the unit header and declare the methods on the real classes
// (BSShaderAccumulator, BSBatchRenderer__GeometryGroup).
struct GroupView
{
    unsigned char m_ucEntryType;
    void RenderGroup(bool bFlag);
};

struct BRView
{
    unsigned char pad[0x3C];
    GroupView* m_pGeometryGroups[13];
};

class AccumWIP : public BSShaderAccumulator
{
  public:
    void SetShaderPassEnabled(unsigned int uiRenderPassIndex, bool bFlag);
    void RenderPassGroup(int eFirst, int eLast, bool bFlag, int iGroup);
};

#include "bsshaderaccumulator_batchrenderer.h"
#include "MemoryManager.h"


typedef BSSimpleList<unsigned short> BSShaderAccumulatorPassIndexList;

// @fnv 0x00b64ec0
template <> void BSSimpleList<unsigned short>::RemoveAll()
{
    while (m_pkNext)
    {
        BSSimpleList<unsigned short>* next = m_pkNext->m_pkNext;
        m_pkNext->m_pkNext = 0;
        BSSimpleList<unsigned short>* current = m_pkNext;
        if (current)
        {
            current->RemoveAll();
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(current);
        }
        m_pkNext = next;
    }
    m_item = 0;
}

// Iterates over the active passes and calls RemoveAll on each pass's list.
// @fnv 0x00b65580
void BSShaderAccumulator::ClearActivePasses()
{
    for (unsigned int i = 0; i < m_uiRendererCount; ++i)
        m_pGroupRenderer[i]->m_kActivePassList.RemoveAll();
}

struct NiPoint3;
struct NiStream;
struct NiBound
{
    void SetGridPosition(float, float, float);
    void SetGridPosition(void*);
    void* GetNavMeshData();
    void SetRadius(float);
    float GetRadius();
    void SetCenterAndRadius(void*, float);
    void ComputeFromPoints(int, void*);
    void Update(void*);
    void Update(void*, void*);
    void ComputeMinimalBound(void*);
    void Merge(void*);
    int WhichSide(void*);
    static bool TestIntersect(float, void*, void*, void*, void*);
    static bool FindIntersect(float, void*, void*, void*, void*, float*, NiPoint3*, bool, NiPoint3*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    char m_kCenter[12];
    float m_fBoundRadius;
};
struct FUN_00b63500_shell : public BSShaderAccumulator
{
    void RenderBound(void*, bool);
};

__declspec(thread) char tls_data[0x2c0];

struct BatchRendererDummy
{
    __forceinline void AddBoundToRenderGroup(void* aBound, bool abZPrePass, void* pkCamera, bool bFlag)
    {
        ((void(*)(void*, void*, bool, void*, bool))((void (&)(void *, int, void *, bool, void *, bool))::fnv_00b9ac80::AddSortedGroup))(this, aBound, abZPrePass, pkCamera, bFlag);
    }
};

// @fnv 0x00b63500
void FUN_00b63500_shell::RenderBound(void* aBound, bool abZPrePass)
{
    unsigned int uiIndex = *(unsigned int*)&tls_data[0x2bc] % this->m_uiRendererCount;
    BatchRendererDummy* m_pGroupRenderer = *(BatchRendererDummy**)((char*)this + uiIndex * 4 + 0x174);
    m_pGroupRenderer->AddBoundToRenderGroup(aBound, abZPrePass, *(void**)&this->m_pkAccumulationCamera,
                                            this->m_bSkipObjectsWithFlag14);
}


// @fnv 0x00b64e30
void FUN_00b64e30(AccumWIP* pAccumWIP)
{
    if (*reinterpret_cast<unsigned char*>(&pAccumWIP->m_bFlagAfterInteger) &&
        *reinterpret_cast<int*>(&pAccumWIP->m_eRenderMode) != 8)
    {
        float fVal = DAT_01200458;
        if (!DAT_011ad80f)
        {
            fVal = 0.0f;
        }
        ::FUN_00b97e30(0, 1);
        ::fnv_00b98320::SendFloatAdd(fVal, 1);
        pAccumWIP->SetShaderPassEnabled(2, true);
        pAccumWIP->SetShaderPassEnabled(3, true);
        --DAT_011ff9dc;
        ::FUN_00b97e30(1, 0);
        --DAT_011ff9e4;
        ::fnv_00b98320::SendFloatAdd(0.0f, 0);
    }
}

class BSBatchRenderer__GeometryGroup
{
  public:
    ~BSBatchRenderer__GeometryGroup();
    void ClearPassTextureSlots();
};

class BSShaderLightingProperty
{
  public:
    void ClearLights();
};

struct AlphaGroupNode
{
    AlphaGroupNode* m_pkNext;
    AlphaGroupNode* m_pkPrev;
    BSBatchRenderer__GeometryGroup* m_pkItem;
};

struct AlphaGeometryList
{
    AlphaGroupNode* m_pkHead;
    AlphaGroupNode* m_pkTail;
    unsigned int m_uiCount;

    AlphaGroupNode* GetHeadPos() const
    {
        return m_pkHead;
    }
    BSBatchRenderer__GeometryGroup*& GetNext(AlphaGroupNode*& pkPos) const
    {
        BSBatchRenderer__GeometryGroup*& rItem = pkPos->m_pkItem;
        pkPos = pkPos->m_pkNext;
        return rItem;
    }
};

struct BSBatchRendererView
{
    unsigned char pad00[0x70];
    BSBatchRenderer__GeometryGroup* pAlphaGroups[2];  // +0x70
    AlphaGeometryList kAlphaGroupLists[2];            // +0x78
    unsigned int uiAlphaGroupCounts[2];               // +0x90
};

// @fnv 0x00b64f20
void FUN_00b64f20(BSBatchRendererView* pThis, int, unsigned int uiIndex)
{
    pThis->pAlphaGroups[uiIndex]->ClearPassTextureSlots();

    AlphaGeometryList* pkList = &pThis->kAlphaGroupLists[uiIndex];
    AlphaGroupNode* pkIter = pkList->GetHeadPos();
    while (pkIter)
    {
        BSBatchRenderer__GeometryGroup* pkGroup = pkList->GetNext(pkIter);
        if (pkGroup)
        {
            pkGroup->~BSBatchRenderer__GeometryGroup();
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(pkGroup);
        }
    }

    reinterpret_cast<BSShaderLightingProperty*>(pkList)->ClearLights();
    pThis->uiAlphaGroupCounts[uiIndex] = 0;
}

class RecursiveSpinLock
{
  public:
    unsigned int value;
};


struct Item_00b655b0
{
    unsigned char pad[0x14];
    void* ptr;
};

struct Self_00b655b0
{
    unsigned char pad[0x140];
    PoolAllocatorBase<unsigned int>::LinkedListEntry* head;
    PoolAllocatorBase<unsigned int>::LinkedListEntry* tail;
    unsigned int count;
};

// Pops every node from the list, frees each node's element and payload, and returns the nodes to a free pool.
// @fnv 0x00b655b0
void FUN_00b655b0(Self_00b655b0* self)
{
    while (self->count != 0)
    {
        Item_00b655b0* item = (Item_00b655b0*)self->head->m_element;
        if (item)
        {
            void* sub = item->ptr;
            if (sub)
            {
                reinterpret_cast<::FUN_00c4ed40_cls *>((sub))->FUN_00c4ed40();
                reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(sub);
                item->ptr = 0;
            }
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(item);
        }
        PoolAllocatorBase<unsigned int>::LinkedListEntry* node = self->head;
        PoolAllocatorBase<unsigned int>::LinkedListEntry* next = node->m_pkNext;
        self->head = next;
        if (next)
        {
            next->m_pUserData = 0;
        }
        else
        {
            self->tail = 0;
        }
        node->m_element = 0;
        reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80))))->FUN_0040fbf0((char *)(0));
        node->m_pUserData = 0;
        node->m_pkNext = (*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58));
        (*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58)) = node;
        if (--DAT_011c5f84 == 0)
        {
            (*reinterpret_cast<::RecursiveSpinLock *>(&::g_011c5f80)).value = 0;
        }
        --self->count;
    }
}

struct BSBatchRenderer__PassList
{
};

extern const void* const* vftable_BSBatchRenderer__PassList;

// @fnv 0x00b656b0
void FUN_00b656b0(BSBatchRenderer__PassList* pThis, int)
{
    *(volatile unsigned int*)pThis = (unsigned int)&vftable_BSBatchRenderer__PassList;
    reinterpret_cast<::FUN_00b63e90_cls *>((pThis))->ReleasePoolNodes();
    *(unsigned int*)((char*)pThis + 0xc) = *(unsigned int*)((char*)pThis + 4);
    *(unsigned int*)((char*)pThis + 4) = 0;
    *(unsigned int*)((char*)pThis + 8) = 0;
    *(unsigned int*)((char*)pThis + 0x10) = 0;
    reinterpret_cast<::FUN_00b63e90_cls *>((pThis))->ReleasePoolNodes();
}

struct NodePoolView
{
    unsigned int m_uiCount;
    void* AddHead();
};

// If bFlag is set, allocates a node via AddHead, links it before the current head at p+0x10, updates the count and returns true.
// @fnv 0x00b65a90
bool __cdecl InsertNodeAtHead(void* pList, void* data, void* arg3, void* arg4, int bInsert)
{
    if (!bInsert)
        return true;
    char* p = (char*)pList;
    NodePoolView* pHead = (NodePoolView*)(p + 0x14);
    void* node = ((void *)(reinterpret_cast<::FUN_0043a010_shell *>((pHead))->FUN_0043a010()));
    *(void**)((char*)node + 8) = data;
    *(void**)((char*)node) = 0;
    *(void**)((char*)node + 4) = *(void**)(p + 0x10);
    void* oldHead = *(void**)(p + 0x10);
    if (oldHead)
    {
        *(void**)oldHead = node;
        ++pHead->m_uiCount;
        *(void**)(p + 0x10) = node;
        return true;
    }
    ++pHead->m_uiCount;
    *(void**)(p + 0x0C) = node;
    *(void**)(p + 0x10) = node;
    return true;
}

struct V42
{
    virtual ~V42()
    {}
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual void f22()
    {}
    virtual void f23()
    {}
    virtual void f24()
    {}
    virtual void f25()
    {}
    virtual void f26()
    {}
    virtual void f27()
    {}
    virtual void f28()
    {}
    virtual void f29()
    {}
    virtual void f30()
    {}
    virtual void f31()
    {}
    virtual void f32()
    {}
    virtual void f33()
    {}
    virtual void f34()
    {}
    virtual void f35()
    {}
    virtual void f36()
    {}
    virtual void f37()
    {}
    virtual void f38()
    {}
    virtual void f39()
    {}
    virtual void f40()
    {}
};

extern void FUN_00b64f90(void*);

enum BSRENDERSTATE_LOCK;
struct BSRenderStateManager
{
public:
    static void SetDepthBufferEnabled(bool, ::BSRENDERSTATE_LOCK);
public:
    static void SetColorWriteMask(unsigned int, ::BSRENDERSTATE_LOCK);
};

// @fnv 0x00b65e80
void __cdecl FUN_00b65e80(void* pObject)
{
    if (*(int*)((unsigned char*)pObject + 8))
    {
        *(int*)((unsigned char*)pObject + 0x18) = 0;
        reinterpret_cast<V42*>(pObject)->f40();
        FUN_00b64f90(pObject);
        ::BSRenderStateManager::SetDepthBufferEnabled(0, (::BSRENDERSTATE_LOCK)(0));
    }
}

struct NiGPUProgram : public NiRefObject
{
};
struct NiRenderer;
class BSShader;
struct BloodSplatterBeamShader
{
public:
    static ::BSShader *CreateShader_00bd23f0();
};
struct ReleaseStub
{
};
struct TlsBlock
{
    char pad[0x2b4];
    int poolMode;
};
__declspec(thread) TlsBlock g_tlsBlock;
struct PoolModeGuard
{
    int saved;
    PoolModeGuard(int mode)
    {
        saved = g_tlsBlock.poolMode;
        g_tlsBlock.poolMode = mode;
    }
    ~PoolModeGuard()
    {
        g_tlsBlock.poolMode = saved;
    }
};
extern NiPointer<NiGPUProgram> DAT_011f956c;
// If a renderer exists, creates the shader when missing and then calls DrawSlots(0) on it.
// @fnv 0x00b55a10
void FUN_00b55a10()
{
    if (::DAT_011f9508)
    {
        if (!DAT_011f956c.m_pObject)
        {
            PoolModeGuard guard(5);
            DAT_011f956c = ((::NiGPUProgram *)(::BloodSplatterBeamShader::CreateShader_00bd23f0()));
        }
        if (DAT_011f956c.m_pObject)
            reinterpret_cast<::RenderOwner *>((((ReleaseStub*)DAT_011f956c.m_pObject)))->DrawSlots((void *)(0));
    }
}

struct FUN_00b63090_shell : public BSShaderAccumulator
{
    void DispatchBatchRenderer();
};

struct BatchStub
{
};
struct AccumStub
{
    char pad[0x174];
    BatchStub* m_pBatchRenderer[1];
};
extern __declspec(thread) unsigned int g_threadIndex;
// @fnv 0x00b63090
void FUN_00b63090_shell::DispatchBatchRenderer()
{
    AccumStub* a = reinterpret_cast<AccumStub*>(this);
    unsigned int count = this->m_uiRendererCount;
    reinterpret_cast<::BSBatchRenderer *>((a->m_pBatchRenderer[g_threadIndex % count]))->ReleaseGeometryGroups();
}

namespace fnv_00b63620 {
struct QueryStub
{
};
struct QEntry
{
    QueryStub* query;
    bool flag;
    char pad[15];
};
struct AccumStub
{
    char pad[0x40];
    bool m_b40;
    char pad2[7];
    QEntry m_aEntries[3];
};
// For each of the three entries, queries the stub, releases and deallocates it, clears the pointer and flag, then clears m_b40.
// @fnv 0x00b63620
void FUN_00b63620(AccumStub* self)
{
    for (int i = 0; i < 3; ++i)
    {
        unsigned int uiData = 0;
        if (self->m_aEntries[i].query)
        {
            reinterpret_cast<::S_00c4edf0_cls *>((self->m_aEntries[i].query))->FUN_00c4edf0((int)(&uiData), 1);
            QueryStub* q = self->m_aEntries[i].query;
            if (q)
            {
                reinterpret_cast<::FUN_00c4ed40_cls *>((q))->FUN_00c4ed40();
                reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(q);
            }
            self->m_aEntries[i].query = 0;
            self->m_aEntries[i].flag = false;
        }
    }
    self->m_b40 = false;
}
}  // namespace fnv_00b63620

struct RenderQuery;
struct RenderQueryVolume
{
    char Center[12];
    float fRadius;
    unsigned int m_uiLightCount;
    RenderQuery* m_pRenderQuery;
    bool m_bQueryStateBeforePending;
    bool m_bQueryPending;
    bool m_bQueryStateAfterPending;
    char _pad_1b[1];
    unsigned int m_uiQueryFlags;
};
struct FUN_00b63680_shell : public BSShaderAccumulator
{
    bool CheckVolumeState(unsigned int, bool);
};

extern bool DAT_011f9fc3;
extern bool DAT_011f9fc4;
struct QueryStub
{
};
struct VolNode
{
    VolNode* next;
    int pad;
    RenderQueryVolume* vol;
};
struct AccumView
{
    char pad[0x140];
    VolNode* head;
    char pad2[8];
    unsigned int cachedId;
    bool cachedResult;
};

// Looks up a volume by id in the accumulator's list, optionally runs its query, and returns/caches the volume's boolean state.
// @fnv 0x00b63680
bool FUN_00b63680_shell::CheckVolumeState(unsigned int uiVolumeId, bool abRunQuery)
{
    AccumView* v = reinterpret_cast<AccumView*>(this);
    if (uiVolumeId == v->cachedId)
        return v->cachedResult;
    VolNode* pNode = v->head;
    RenderQueryVolume* vol;
    RenderQueryVolume** ppVolume;
    for (;;)
    {
        if (!pNode)
            return false;
        ppVolume = &pNode->vol;
        pNode = pNode->next;
        vol = *ppVolume;
        if (vol && vol->m_uiLightCount == uiVolumeId)
            break;
    }
    if (vol->m_bQueryPending)
    {
        if (abRunQuery)
        {
            if (DAT_011f9fc3 && vol->m_pRenderQuery)
            {
                int r;
                do
                {
                    r = ((unsigned char)(reinterpret_cast<::S_00c4edf0_cls *>((reinterpret_cast<QueryStub*>(vol->m_pRenderQuery)))->FUN_00c4edf0((int)(reinterpret_cast<unsigned int*>(&abRunQuery)), 1)));
                } while (r == 1);
                if (r == 0)
                {
                    unsigned int d = *reinterpret_cast<unsigned int*>(&abRunQuery);
                    vol->m_bQueryStateBeforePending = d == 0;
                    vol->m_uiQueryFlags = d;
                }
                else
                {
                    RenderQuery* q = vol->m_pRenderQuery;
                    if (q)
                    {
                        reinterpret_cast<::FUN_00c4ed40_cls *>((q))->FUN_00c4ed40();
                        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(q);
                    }
                    vol->m_pRenderQuery = 0;
                    vol->m_bQueryStateBeforePending = false;
                    vol->m_uiQueryFlags = 999999;
                }
            }
            else if (DAT_011f9fc4)
            {
                vol->m_bQueryStateBeforePending = false;
                vol->m_uiQueryFlags = 999999;
            }
            vol->m_bQueryPending = false;
        }
        if (vol->m_bQueryPending)
            return vol->m_bQueryStateBeforePending;
    }
    v->cachedId = uiVolumeId;
    v->cachedResult = vol->m_bQueryStateBeforePending;
    return vol->m_bQueryStateBeforePending;
}

namespace fnv_00b63a50 {
struct BatchStub
{
};
struct AccumStub
{
    char pad[8];
    int m_i8;
    char pad2[0x25];
    unsigned char m_c31;
    char pad3[0x142];
    BatchStub* m_pBatchRenderer[6];
    unsigned int m_uiCount;
};
// Calls FUN_00b99a10 on each of the m_uiCount batch renderers, passing m_i8 and m_c31.
// @fnv 0x00b63a50
void FUN_00b63a50(AccumStub* pAccum)
{
    for (unsigned int i = 0; i < pAccum->m_uiCount; ++i)
        ::FUN_00b99a10((char *)(pAccum->m_pBatchRenderer[i]), pAccum->m_i8, pAccum->m_c31, {});
}
}  // namespace fnv_00b63a50

namespace fnv_00b65570 {
struct BSShaderLightingProperty
{
};
// @fnv 0x00b65570
void FUN_00b65570(char* self, int unused)
{
    reinterpret_cast<::BSShaderLightingProperty *>((reinterpret_cast<BSShaderLightingProperty*>(self + 0xc)))->ClearLights();
}
}  // namespace fnv_00b65570

struct GlobalObjectO2_00a7b610;
// @fnv 0x00b65a80
GlobalObjectO2_00a7b610* __cdecl FUN_00b65a80()
{
    return &::g_011fa000;
}

// @fnv 0x00b665a0
void __cdecl FUN_00b665a0(void* p)
{
    ::fnv_00b65ae0::FUN_00b65ae0((::AccumWIP *)(p));
    ::fnv_00b65c60::FUN_00b65c60((::AccumWIP *)(p));
}

namespace fnv_00b64f90 {
struct RecursiveSpinLock
{
    unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
};
typedef PoolAllocatorBase<unsigned int> PoolAlloc;
struct ListNode
{
    ListNode* m_pkNext;
    ListNode* m_pkPrev;
    unsigned int m_element;
};
struct PtrList
{
    ListNode* m_pkHead;
    ListNode* m_pkTail;
    unsigned int m_uiCount;
    void RemoveHead()
    {
        ListNode* pkNode = m_pkHead;
        m_pkHead = pkNode->m_pkNext;
        if (m_pkHead)
            m_pkHead->m_pkPrev = 0;
        else
            m_pkTail = 0;
        pkNode->m_element = 0;
        reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_00b64f90::RecursiveSpinLock *>(&::g_011c5f80))))->FUN_0040fbf0((char *)(0));
        pkNode->m_pkPrev = 0;
        pkNode->m_pkNext = (ListNode*)(*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58));
        (*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58)) = (PoolAlloc::LinkedListEntry*)pkNode;
        if (--(*reinterpret_cast<::fnv_00b64f90::RecursiveSpinLock *>(&::g_011c5f80)).m_uiRecursionCount == 0)
            (*reinterpret_cast<::fnv_00b64f90::RecursiveSpinLock *>(&::g_011c5f80)).m_uiOwningThreadID = 0;
        m_uiCount--;
    }
};
struct PassRef
{
    void* pPass;
    unsigned short usIndex;
};
struct AccumS
{
    char pad00[0xc];
    PtrList kList;
    PtrList* pList;
    unsigned int ItemUpdateArray;
    char pad20[4];
    void** ppArray;
    char pad28[4];
    unsigned int uiIter;
    char pad30[0x1a4 - 0x30];
    PassRef kPass;
    void* Next()
    {
        if (uiIter)
            return ppArray[--uiIter];
        return 0;
    }
    void* First()
    {
        uiIter = ItemUpdateArray;
        if (uiIter)
            return ppArray[--uiIter];
        return 0;
    }
    void FUN_00b64f90();
};

// Calls FUN_00b988e0, applies FUN_00b994f0 to each pass from First/Next, then drains pList or kList and calls FUN_00b988e0 again.
// @fnv 0x00b64f90
void AccumS::FUN_00b64f90()
{
    ::fnv_00b988e0::FUN_00b988e0();
    for (void* p = First(); p; p = Next())
    {
        kPass.pPass = p;
        ::fnv_00b994f0::FUN_00b994f0((::fnv_00b994f0::Pass_b994f0 *)(void *)(&kPass), kPass.usIndex, 1, 1, 1);
    }
    if (pList)
    {
        while (pList->m_uiCount)
            pList->RemoveHead();
    }
    else
    {
        while (kList.m_uiCount)
            kList.RemoveHead();
    }
    ::fnv_00b988e0::FUN_00b988e0();
}
}  // namespace fnv_00b64f90

namespace fnv_00b656e0 {
void __cdecl NiFree(void*);
void FUN_00ba8cd0(char*);
struct RecursiveSpinLock
{
    unsigned int m_uiOwningThreadID;
};
struct OMNode
{
    OMNode* m_pkNext;
    void* m_pUserData;
    unsigned int m_element;
};
typedef PoolAllocatorBase<unsigned int>::LinkedListEntry OMAllocNode;
class BSShaderLightingProperty
{
  public:
};
struct OMList
{
    OMNode* m_pkHead;
    OMNode* m_pkTail;
    unsigned int m_uiCount;
    ~OMList()
    {
        reinterpret_cast<::BSShaderLightingProperty *>((((BSShaderLightingProperty*)this)))->ClearLights();
    }
    void RemoveHead()
    {
        OMNode* pkNode = m_pkHead;
        m_pkHead = pkNode->m_pkNext;
        if (m_pkHead)
            m_pkHead->m_pUserData = 0;
        else
            m_pkTail = 0;
        pkNode->m_element = 0;
        reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_00b656e0::RecursiveSpinLock *>(&::g_011c5f80))))->FUN_0040fbf0((char *)(0));
        pkNode->m_pUserData = 0;
        pkNode->m_pkNext = (OMNode*)(*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58));
        (*reinterpret_cast<::PoolAllocatorBase<unsigned int>::LinkedListEntry * *>(&::DAT_011c5f58)) = (OMAllocNode*)pkNode;
        if (--::DAT_011c5f84 == 0)
            (*reinterpret_cast<::fnv_00b656e0::RecursiveSpinLock *>(&::g_011c5f80)).m_uiOwningThreadID = 0;
        m_uiCount--;
    }
};
class BSBatchRenderer__PassList
{
  public:
    virtual ~BSBatchRenderer__PassList();
    void* m_pkHead;
    void* m_pkTail;
    void* m_pkFree;
    unsigned int m_uiCount;
    void Reset()
    {
        reinterpret_cast<::FUN_00b63e90_cls *>(this)->ReleasePoolNodes();
        m_pkFree = m_pkHead;
        m_pkHead = 0;
        m_pkTail = 0;
        m_uiCount = 0;
    }
};
struct OMRef
{
    virtual void V0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct OMRefPtr
{
    OMRef* m_pObject;
    ~OMRefPtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    OMRefPtr& operator=(OMRef* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                InterlockedIncrement(&m_pObject->m_uiRefCount);
        }
        return *this;
    }
};
class NiTMapBaseStub
{
  public:
    virtual ~NiTMapBaseStub()
    {
        reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
        NiFree(m_ppkHashTable);
    }
    void RemoveAll();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
class OMMap : public NiTMapBaseStub
{
  public:
    virtual ~OMMap()
    {
        reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
    }
};
struct OMMember1a4
{
    char pad[0x10];
    ~OMMember1a4()
    {
        ::FUN_00ba8cd0((char*)this);
    }
};
struct OMPolyObj
{
    virtual void* Destroy(unsigned int);
};
struct OMObjC4
{
    ~OMObjC4()
    {
        reinterpret_cast<::FUN_00c4ed40_cls *>((this))->FUN_00c4ed40();
    }
    static void operator delete(void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(p);
    }
};
struct OMObjD9
{
    ~OMObjD9()
    {
        ::FUN_00bd9150(this);
    }
    static void operator delete(void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(p);
    }
};
struct OMData140
{
    char pad[0x14];
    OMObjC4* m_p14;
    static void operator delete(void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(p);
    }
};
struct OMPod
{
    char c;
    static void operator delete[](void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(p);
    }
};
struct OMCS
{
    _RTL_CRITICAL_SECTION m_kCS;
    ~OMCS()
    {
        DeleteCriticalSection(&m_kCS);
    }
};
struct FUN_00a9b4a0
{
    virtual ~FUN_00a9b4a0();
    char pad[0x88];
};
struct OMSlot48
{
    OMObjC4* m_p;
    char pad[0x10];
};
struct FUN_00b656e0 : public FUN_00a9b4a0
{
    OMPod* m_p8c;
    OMList m_kList90;
    BSBatchRenderer__PassList m_aPassA[4];
    BSBatchRenderer__PassList m_aPassB[4];
    OMRefPtr m_sp13c;
    OMList m_kList140;
    char pad14c[0x24];
    OMObjD9* m_p170;
    OMPolyObj* m_p174;
    OMPolyObj* m_p178;
    OMPod* m_p17c;
    OMPod* m_p180;
    OMPod* m_p184;
    OMPod* m_p188;
    char pad18c[0xc];
    OMRefPtr m_sp198;
    unsigned int m_u19c;
    OMRefPtr m_sp1a0;
    OMMember1a4 m_k1a4;
    OMMap m_kMap1b4;
    char pad1c4[0x3c];
    OMCS m_kCS;
    virtual ~FUN_00b656e0();
};
// @fnv 0x00b656e0
FUN_00b656e0::~FUN_00b656e0()
{
    for (int i = 0; i < 4; i++)
    {
        m_aPassA[i].Reset();
        m_aPassB[i].Reset();
    }
    delete[] m_p8c;
    while (m_kList140.m_uiCount)
    {
        OMData140* pkData = (OMData140*)m_kList140.m_pkHead->m_element;
        if (pkData)
        {
            if (pkData->m_p14)
            {
                delete pkData->m_p14;
                pkData->m_p14 = 0;
            }
            delete pkData;
        }
        m_kList140.RemoveHead();
    }
    m_sp13c = 0;
    OMSlot48* pkSlots = (OMSlot48*)((char*)this + 0x48);
    for (int iSlotIndex = 0; iSlotIndex < 3; iSlotIndex++)
    {
        if (pkSlots[iSlotIndex].m_p)
        {
            delete pkSlots[iSlotIndex].m_p;
            pkSlots[iSlotIndex].m_p = 0;
        }
    }
    if (m_p170)
    {
        delete m_p170;
        m_p170 = 0;
    }
    if (m_p174)
        m_p174->Destroy(1);
    if (m_p178)
        m_p178->Destroy(1);
    delete[] m_p17c;
    delete[] m_p180;
    delete[] m_p184;
    delete[] m_p188;
    m_sp1a0 = 0;
    reinterpret_cast<::S_00b601a0_Map *>(&(m_kMap1b4))->FUN_00b601a0();
    m_sp198 = 0;
}
}  // namespace fnv_00b656e0

namespace fnv_00b65c60 {
struct NiRenderTargetGroup;
struct NiRenderer
{
    void SetCurrentCamera(NiCamera*);
};
struct BSRenderedTexture
{
};
struct BSTextureManager
{
};
struct ImageSpaceManager
{
};
struct BSRenderStateManager
{
};
struct AccumStub
{
    bool FUN_00b63120(int, int);
    void UpdatePasses(bool);
};

// @fnv 0x00b65c60
void FUN_00b65c60(AccumWIP* apAccum)
{
    if (*((unsigned char*)&apAccum->m_bUseFirstPersonCamera) && ((AccumStub*)apAccum)->FUN_00b63120(0x288, 0x2ce))
    {
        if ((*reinterpret_cast<::fnv_00b65c60::BSRenderedTexture * *>(&::DAT_011f9438)))
        {
            ::BSRenderedTexture::EndAllAndResetRendererState();
            if (!(*reinterpret_cast<::fnv_00b65c60::BSRenderedTexture * *>(&::DAT_011f943c)))
                (*reinterpret_cast<::fnv_00b65c60::BSRenderedTexture * *>(&::DAT_011f943c)) = ((::fnv_00b65c60::BSRenderedTexture *)(reinterpret_cast<::Pool *>(((*reinterpret_cast<::fnv_00b65c60::BSTextureManager * *>(&::DAT_011f91a8))))->FUN_00b6e110((unsigned int)((*reinterpret_cast<::fnv_00b65c60::NiRenderer * *>(&::DAT_011f9508))), 5, 0, (unsigned int)(0), 0)));
            reinterpret_cast<::BB97550Shader *>(((*reinterpret_cast<::fnv_00b65c60::ImageSpaceManager * *>(&::DAT_011f91ac))))->FUN_00b97550(0x22, (int)((*reinterpret_cast<::fnv_00b65c60::NiRenderer * *>(&::DAT_011f9508))), (int)((*reinterpret_cast<::fnv_00b65c60::BSRenderedTexture * *>(&::DAT_011f9438))), (int)((*reinterpret_cast<::fnv_00b65c60::BSRenderedTexture * *>(&::DAT_011f943c))), 0, true);
            ::FUN_00b6b8d0(0, (::NiRenderTargetGroup *)(::fnv_00b65c60::NiRenderTargetGroup *)(((::fnv_00b65c60::NiRenderTargetGroup *)(reinterpret_cast<::BSRenderedTexture *>(((*reinterpret_cast<::fnv_00b65c60::BSRenderedTexture * *>(&::DAT_011f9438))))->GetGroup()))));
        }
        reinterpret_cast<::CameraState4E9 *>(((*reinterpret_cast<::fnv_00b65c60::NiRenderer * *>(&::DAT_011f9508))))->SetFromCamera((*(const ::Camera4E9 *)(*(NiCamera**)&apAccum->m_pkAccumulationCamera)));
    }
    apAccum->RenderPassGroup(0x288, 0x289, false, -1);
    apAccum->RenderPassGroup(0x28a, 0x2ab, false, -1);
    apAccum->RenderPassGroup(0x2ac, 0x2ce, false, -1);
    if (*((unsigned char*)&apAccum->m_bUseFirstPersonCamera))
    {
        reinterpret_cast<::Manager *>(((*reinterpret_cast<::fnv_00b65c60::BSTextureManager * *>(&::DAT_011f91a8))))->FUN_00b6da10((::Item *)((*reinterpret_cast<::fnv_00b65c60::BSRenderedTexture * *>(&::DAT_011f943c))));
        (*reinterpret_cast<::fnv_00b65c60::BSRenderedTexture * *>(&::DAT_011f943c)) = 0;
    }
    apAccum->SetShaderPassEnabled(9, true);
    if (*((unsigned char*)&apAccum->m_bFourthBooleanFlagBeforeInteger))
        ((AccumStub*)apAccum)->UpdatePasses(true);
    else
        ((AccumStub*)apAccum)->UpdatePasses(false);
    ::BSRenderStateManager::SetDepthBufferEnabled(false, (::BSRENDERSTATE_LOCK)(0));
    ::BSRenderStateManager::SetDepthBufferEnabled(false, (::BSRENDERSTATE_LOCK)(0));
    apAccum->RenderPassGroup(0x2cf, 0x2d7, false, -1);
    apAccum->SetShaderPassEnabled(1, false);
}
}  // namespace fnv_00b65c60

namespace fnv_00b65ae0 {
struct GO
{
    void operator=(void*);
};
struct AccumView
{
    void UpdatePasses(bool);
};

// @fnv 0x00b65ae0
void __cdecl FUN_00b65ae0(AccumWIP* pAccum)
{
    if (pAccum->m_pkAccumulationCamera)
    {
        unsigned char* raw = (unsigned char*)pAccum;
        int mode = *(int*)(raw + 0x19c);
        if (mode == 8)
        {
            pAccum->RenderPassGroup(6, mode, false, -1);
            pAccum->RenderPassGroup(0x1d3, 0x1d6, false, -1);
            pAccum->ClearActivePasses();
            return;
        }
        if (mode == 7)
        {
            pAccum->RenderPassGroup(0x10, 0x13, false, -1);
            pAccum->RenderPassGroup(0x1c8, 0x1cb, false, -1);
            pAccum->ClearActivePasses();
            return;
        }
        pAccum->SetShaderPassEnabled(10, false);
        if (::DAT_011f9fc1 && *(int*)(raw + 0x19c) != 7)
        {
            (*reinterpret_cast<::fnv_00b65ae0::GO *>(&::DAT_011fa008)) = ((void *)(::CreateRenderPassesNode()));
            ::DAT_011f9fc1 = false;
        }
        if (*(bool*)(raw + 0x164))
        {
            pAccum->RenderPassGroup(1, 0x237, false, -1);
            ::UpdateSpawnedObjectFlags(0, 0, 0, 0, 0, 0, 0);
            pAccum->RenderPassGroup(0x238, 0x25b, false, -1);
            ::UpdateSpawnedObjectFlags(1, 0, 0, 0, 0, 0, 0);
        }
        else
        {
            pAccum->RenderPassGroup(1, 0x25b, false, -1);
        }
        int saved = ::DAT_011a9608;
        ::DAT_011a9608 = 1;
        pAccum->SetShaderPassEnabled(0, false);
        ::DAT_011a9608 = saved;
        ::FUN_00b64e30((::AccumWIP *)(((AccumView*)pAccum)));
        pAccum->RenderPassGroup(0x25c, 0x287, false, -1);
        ::fnv_00b63a50::FUN_00b63a50((::fnv_00b63a50::AccumStub *)(((AccumView*)pAccum)));
        if (*(bool*)(raw + 0x167))
            ((AccumView*)pAccum)->UpdatePasses(false);
        else
            ((AccumView*)pAccum)->UpdatePasses(true);
    }
}
}  // namespace fnv_00b65ae0

struct NiUpdateData
{
    float fTime;
    bool bUpdate;
    bool bRender;
    bool bInterpolate;
    bool bTimeToDie;
    bool bVisible;
};

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

struct NiAVObject : A51BF0Base
{
};

struct NiNode : NiAVObject
{
    unsigned char m_auiShapeKeys[0xAC];

    NiNode(unsigned short);
    void Update(NiUpdateData const&);
};

struct NiGlobalStringTable
{
    static char* __cdecl AddString(char const*);
};

extern unsigned int _data_011c16bc;


struct NiFixedString
{
    char* m_pString;

    NiFixedString(char* pString) : m_pString(pString)
    {}

    ~NiFixedString()
    {
        if (m_pString != ::DAT_0109b220)
            ::FUN_00c45830((::MyRef *)(void *)(m_pString - 8));
    }
};

// Creates a NiNode named "RenderPasses", initializes a NiUpdateData with zeroed flags, updates the node, and returns it.
// @fnv 0x00b63420
NiNode* __cdecl CreateRenderPassesNode()
{
    NiUpdateData UpdateData;
    NiNode* pNode = new NiNode(0);
    int i = 0;

    {
        NiFixedString fixedString(NiGlobalStringTable::AddString("RenderPasses"));
        ::AssignFixedString((char *)(pNode), (int)&(fixedString), {});
    }

    UpdateData.fTime = 0.0f;
    UpdateData.bUpdate = false;
    UpdateData.bRender = false;
    UpdateData.bInterpolate = false;
    UpdateData.bTimeToDie = false;
    UpdateData.bVisible = false;

    reinterpret_cast<::FUN_00a59c60_cls *>((pNode))->FUN_00a59c60((int)&(UpdateData));
    return pNode;
}

struct QueryLocal
{
    unsigned int handle;
    QueryLocal();
    static void* operator new(unsigned int size)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(size);
    }
    static void operator delete(void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(p);
    }
};
struct FUN_00c4ecf0 : QueryLocal
{
    FUN_00c4ecf0();
};
struct ShaderStageLocal
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
    virtual void Reset();
};
struct ShaderLocal
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    ShaderStageLocal* stage30;
    ShaderStageLocal* stage34;
};
struct ManagerLocal
{
};
void __cdecl FUN_00ba8ec0(void*, void*, unsigned short, unsigned char, bool, bool);
struct FUN_00ba8cd0 : BSShaderProperty__RenderPass
{
    FUN_00ba8cd0(void* geometry, unsigned short pass, unsigned char hint, bool first, bool last)
    {
        FUN_00ba8ec0(this, geometry, pass, hint, first, last);
    }
    ~FUN_00ba8cd0();
};
struct Candidate : BSShaderAccumulator
{
    void RenderGeometryPass(void* geometry, unsigned int index, void* camera);
};
// @fnv 0x00b64bf0
void Candidate::RenderGeometryPass(void* geometry, unsigned int index, void* camera)
{
    if (m_bSkipGeometryPass || index >= 3 || m_akRenderQueryStates[index].m_bQueryPending)
        return;
    if (!m_akRenderQueryStates[index].m_pRenderQuery)
    {
        m_akRenderQueryStates[index].m_pRenderQuery = reinterpret_cast<RenderQuery*>(new FUN_00c4ecf0);
    }
    if (m_akRenderQueryStates[index].m_pRenderQuery)
    {
        ShaderLocal* shader = ((::ShaderLocal *)(::FUN_00b55560((void *)(1))));
        ::FUN_00b7a870(9);
        shader->stage34->Reset();
        shader->stage30->Reset();
        reinterpret_cast<::S_00c4ed70_Class *>((reinterpret_cast<QueryLocal*>(m_akRenderQueryStates[index].m_pRenderQuery)))->FUN_00c4ed70();
        reinterpret_cast<::CameraState4E9 *>(((*reinterpret_cast<::ManagerLocal * *>(&::NiRenderer::ms_pRenderer))))->SetFromCamera((*(const ::Camera4E9 *)(camera)));
        FUN_00ba8cd0 pass(geometry, 9, 1, false, false);
        ::fnv_00b994f0::FUN_00b994f0((::fnv_00b994f0::Pass_b994f0 *)(void *)(&pass), 9, 0, 0, 0);
        reinterpret_cast<::FUN_00c4edb0_Class *>((reinterpret_cast<QueryLocal*>(m_akRenderQueryStates[index].m_pRenderQuery)))->FUN_00c4edb0();
        m_akRenderQueryStates[index].m_bQueryPending = true;
        m_akRenderQueryStates[index].m_uiQueryResult = 0;
    }
    else
    {
        m_akRenderQueryStates[index].m_fQueryValue = 0.0f;
        m_akRenderQueryStates[index].m_bQueryPending = false;
        m_akRenderQueryStates[index].m_uiQueryResult = 0;
    }
}

struct FUN_00b65ec0_sub
{
    void End();
};

struct FUN_00b65ec0_item
{
    char pad_00[0x2c];
    FUN_00b65ec0_sub sub;
};

class FUN_00b65ec0_cls
{
  public:
    char pad_000[0x174];
    FUN_00b65ec0_item* m_items[6];
    unsigned int m_uiItemCount;

    void Reset(unsigned int a, unsigned int b, int c, int d);
    void FUN_00b65ec0();
};

struct RenderBatch : BSBatchRenderer
{
};
struct RenderGroup
{
    unsigned int flags;
    unsigned int count;
    RenderBatch* renderer;
};
struct RenderAccumulator : BSShaderAccumulator
{
    void FUN_00b63770(unsigned int first, unsigned int last, bool flag, int group);
};
// @fnv 0x00b639e0
void AccumWIP::SetShaderPassEnabled(unsigned int uiGroupIndex, bool bFlag)
{
    GroupView* pkGroup = reinterpret_cast<BRView*>(m_pGroupRenderer[0])->m_pGeometryGroups[uiGroupIndex];
    if (!pkGroup)
        return;
    if ((pkGroup->m_ucEntryType & 1u) > 0)
    {
        for (unsigned int i = 0; i < m_uiRendererCount; ++i)
        {
            ::FUN_00b9a4d0((::FUN_00b9a4d0_Obj *)(reinterpret_cast<BRView*>(m_pGroupRenderer[i])->m_pGeometryGroups[uiGroupIndex]), bFlag, {});
        }
    }
    else
    {
        reinterpret_cast<::RenderAccumulator *>(this)->FUN_00b63770(1, 0x2F1, bFlag, (int)uiGroupIndex);
    }
}
// Calls Begin on each item's sub with 0x2f0 and 0x2f1, then Reset, then End on each item's sub.
// @fnv 0x00b65ec0
void FUN_00b65ec0_cls::FUN_00b65ec0()
{
    unsigned int a;
    unsigned int b;
    unsigned int i = 0;
    if (m_uiItemCount > 0)
    {
        a = 0x2f0;
        b = 0x2f1;
        do
        {
            reinterpret_cast<::FUN_00b63bf0_cls *>(&(m_items[i]->sub))->AppendItem((const unsigned short *)(unsigned int *)(&a));
            reinterpret_cast<::FUN_00b63bf0_cls *>(&(m_items[i]->sub))->AppendItem((const unsigned short *)(unsigned int *)(&b));
            ++i;
        } while (i < m_uiItemCount);
    }
    reinterpret_cast<::RenderAccumulator *>(this)->FUN_00b63770(0x2f0, 0x2f1, 0, -1);
    for (i = 0; i < m_uiItemCount; ++i)
    {
        m_items[i]->sub.End();
    }
}
// Runs each renderer's passes in priority order, choosing the next pass by pass id, sub-index and flag, then finalizes the groups.
// @fnv 0x00b63770
void RenderAccumulator::FUN_00b63770(unsigned int uiFirstPass, unsigned int last, bool flag, int group)
{
    RenderBatch* renderers[2];
    RenderGroup* groups[2];
    if ((*reinterpret_cast<bool *>(&::DAT_011f94a6)))
        ::Lighting30Shader::InvalidateShaderConstants();
    if (group > -1)
    {
        for (unsigned int i = 0; i < m_uiRendererCount; ++i)
        {
            groups[i] = (RenderGroup*)m_pGroupRenderer[i]->m_pGeometryGroups[group];
            renderers[i] = groups[i]->renderer;
        }
    }
    else
    {
        for (unsigned int i = 0; i < m_uiRendererCount; ++i)
        {
            renderers[i] = (RenderBatch*)m_pGroupRenderer[i];
            groups[i] = 0;
        }
    }
    for (unsigned int i = 0; i < m_uiRendererCount; ++i)
    {
        m_puiRendererOutput[i] = 0;
        if (renderers[i])
        {
            renderers[i]->m_uiPassCount = uiFirstPass;
            renderers[i]->m_uiBucketCount = last;
            m_pbRendererResults[i] =
                reinterpret_cast<::BSBatchRenderer *>((renderers[i]))->FindPassBucket((*(unsigned int *)(&m_puiRendererOutput[i])), (*(int *)(&m_piRendererOutput[i])), (*(bool *)(&m_pbRendererOutput[i])));
        }
        else
        {
            m_pbRendererResults[i] = false;
        }
    }
    for (;;)
    {
        bool active = m_pbRendererResults[0];
        unsigned int selected = 0;
        for (unsigned int i = 1; i < m_uiRendererCount; ++i)
        {
            if (!active && m_pbRendererResults[i])
            {
                active = true;
                selected = i;
            }
            else if (m_pbRendererResults[i] &&
                     (m_puiRendererOutput[i] < m_puiRendererOutput[selected] ||
                      (m_puiRendererOutput[i] == m_puiRendererOutput[selected] &&
                       (m_piRendererOutput[i] < m_piRendererOutput[selected] ||
                        (m_piRendererOutput[i] == m_piRendererOutput[selected] && m_pbRendererOutput[i])))))
            {
                selected = i;
            }
        }
        if (!active)
            break;
        unsigned int pass = m_puiRendererOutput[selected];
        if (((pass >= 0x1c4 && pass <= 0x1c7) || (pass >= 0x231 && pass <= 0x234) ||
             (pass >= 0x284 && pass <= 0x287)) &&
            (m_bFirstSpecialPassFlag || m_bSecondSpecialPassFlag))
        {
            m_pbRendererResults[selected] = reinterpret_cast<::fnv_00b9a3c0::FUN_00b9a3c0_shell *>((renderers[selected]))->FUN_00b9a3c0(
                (*(unsigned int *)(&m_puiRendererOutput[selected])), (*(int *)(&m_piRendererOutput[selected])), (*(bool *)(&m_pbRendererOutput[selected])), false);
        }
        else
        {
            m_pbRendererResults[selected] = reinterpret_cast<::BatchRenderer *>((renderers[selected]))->FUN_00b9a120(
                (*(unsigned int *)(&m_puiRendererOutput[selected])), (*(int *)(&m_piRendererOutput[selected])), (*(bool *)(&m_pbRendererOutput[selected])), flag);
        }
    }
    for (unsigned int i = 0; i < m_uiRendererCount; ++i)
    {
        if (groups[i])
            reinterpret_cast<::BSBatchRenderer__GeometryGroup *>((groups[i]))->ClearPassTextureSlots();
    }
    ::fnv_00b988e0::FUN_00b988e0();
}

class BSShaderAccumulatorPassIndexList_W : public BSSimpleList<unsigned short>
{
  public:
    void FUN_00b64f10();
};
// @fnv 0x00b64f10
void BSShaderAccumulatorPassIndexList_W::FUN_00b64f10()
{
    RemoveAll();
}

struct FlagB
{
    bool b;
    FlagB(bool x) : b(x)
    {}
};
struct PassX
{
};
struct ViewX
{
    int pad0, pad1;
    void* m8;
    int pad[9];
    char c30;
    bool m31;
    char pad2[0x174 - 0x32];
    PassX* m_apPass[2];
    char pad3[0x18c - 0x17c];
    int m18c;
    void UpdatePasses(void* p);
};
// Runs both passes while either returns a value above the float minimum, then finalizes each active pass.
// @fnv 0x00b650c0
void ViewX::UpdatePasses(void* p)
{
    ::fnv_00b988e0::FUN_00b988e0();
    float afValues[2];
    afValues[0] = reinterpret_cast<::BSBatchRenderer_AlphaDepth *>((m_apPass[0]))->ComputeAlphaDepth((int)(p), (::SortCamera *)(m8), (*(bool *)&(const ::FlagB &)(FlagB(m31))));
    if (m18c == 2)
        afValues[1] = reinterpret_cast<::BSBatchRenderer_AlphaDepth *>((m_apPass[1]))->ComputeAlphaDepth((int)(p), (::SortCamera *)(m8), (*(bool *)&(const ::FlagB &)(FlagB(m31))));
    else
        afValues[1] = DAT_01015f5c;
    while (afValues[0] > -3.4028234663852886e+38 || afValues[1] > -3.4028234663852886e+38)
    {
        int i = (afValues[0] > afValues[1]) ? 0 : 1;
        reinterpret_cast<::fnv_00b9af60::Renderer_af60 *>((m_apPass[i]))->UpdateVisibility((int)(p), (::fnv_00b9af60::Cam_af60 *)(m8), m31, afValues[1 - i]);
        afValues[i] = reinterpret_cast<::BSBatchRenderer_AlphaDepth *>((m_apPass[i]))->ComputeAlphaDepth((int)(p), (::SortCamera *)(m8), (*(bool *)&(const ::FlagB &)(FlagB(m31))));
    }
    ::FUN_00b64f20((::BSBatchRendererView *)(m_apPass[0]), (int)(p), {});
    if (m18c == 2)
        ::FUN_00b64f20((::BSBatchRendererView *)(m_apPass[1]), (int)(p), {});
    ::fnv_00b988e0::FUN_00b988e0();
}

struct RefVolSrc
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    float f0c;
};

struct RefVolItem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    float f0c;
    unsigned int key;
    unsigned int unk14;
    unsigned char b18;
    unsigned char b19;
    unsigned char b1a;
    unsigned char pad1b;
    unsigned int unk1c;
};

struct RefVolNode
{
    RefVolNode* m_pkNext;
    RefVolNode* m_pkPrev;
    RefVolItem* m_element;
};

struct RefVolAlloc
{
    unsigned int m_uiCount;
    RefVolNode* LinkedListEntry();
};

struct RefVolList
{
    RefVolNode* m_pkHead;
    RefVolNode* m_pkTail;
    RefVolAlloc m_kItemCount;

    RefVolItem*& GetNext(void*& pos)
    {
        RefVolItem*& r = ((RefVolNode*)pos)->m_element;
        pos = ((RefVolNode*)pos)->m_pkNext;
        return r;
    }
    RefVolNode* GetHeadPos()
    {
        return m_pkHead;
    }
};

class RefVolAccum : public BSShaderAccumulator
{
  public:
    void UpdateOrAddItem(unsigned int key, const RefVolSrc* src, bool flag);
};

// @fnv 0x00b65f60
void RefVolAccum::UpdateOrAddItem(unsigned int key, const RefVolSrc* src, bool flag)
{
    RefVolList* list = (RefVolList*)&m_kReferenceVolumeList;
    void* pos = list->GetHeadPos();
    while (pos)
    {
        RefVolItem* item = list->GetNext(pos);
        if (item && item->key == key)
        {
            item->unk00 = src->unk00;
            item->unk04 = src->unk04;
            item->unk08 = src->unk08;
            item->f0c = src->f0c;
            item->b1a = flag;
            return;
        }
    }

    RefVolItem* item;
    RefVolItem* pNewItem = (RefVolItem*)reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(0x20);
    if (pNewItem)
    {
        float f = src->f0c;
        pNewItem->unk00 = src->unk00;
        pNewItem->unk04 = src->unk04;
        pNewItem->unk08 = src->unk08;
        pNewItem->f0c = f;
        pNewItem->key = key;
        pNewItem->unk14 = 0;
        pNewItem->b18 = 0;
        pNewItem->b19 = 0;
        pNewItem->b1a = 1;
        pNewItem->unk1c = 0;
        item = pNewItem;
    }
    else
    {
        item = 0;
    }

    RefVolNode* newNode = ((::RefVolNode *)(reinterpret_cast<::FUN_0043a010_shell *>(&(list->m_kItemCount))->FUN_0043a010()));
    newNode->m_element = item;
    newNode->m_pkPrev = 0;
    newNode->m_pkNext = list->m_pkHead;
    if (list->m_pkHead)
    {
        list->m_pkHead->m_pkPrev = newNode;
    }
    else
    {
        list->m_pkTail = newNode;
    }
    list->m_kItemCount.m_uiCount++;
    list->m_pkHead = newNode;
}

struct ShPoint3
{
    float x;
    float y;
    float z;
};
struct ShColor
{
    float r;
    float g;
    float b;
    float a;
    ShColor(float fR = 0.0f, float fG = 0.0f, float fB = 0.0f, float fA = 0.0f) : r(fR), g(fG), b(fB), a(fA)
    {}
};
struct ShMatrix3
{
    float m_afEntries[3][3];
    void GetCol(unsigned int uiCol, ShPoint3& kCol) const
    {
        kCol.x = m_afEntries[0][uiCol];
        kCol.y = m_afEntries[1][uiCol];
        kCol.z = m_afEntries[2][uiCol];
    }
};
struct ShFrustum
{
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
};
struct ShRect
{
    float m_fMinimumU;
    float m_fMaximumU;
    float m_fMinimumV;
    float m_fMaximumV;
};
struct ShCamera
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    ShMatrix3 m_kWorldRotate;
    ShPoint3 m_kWorldTranslate;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    ShFrustum m_kViewFrustum;
    int unkF8;
    int unkFC;
    ShRect m_kPort;
};
struct ShRenderer
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void SetBackgroundColor(const ShColor& kColor);
    virtual void v0B0();
    virtual void GetBackgroundColor(ShColor& kColor);
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void Do_SetCameraData(const ShPoint3& kWorldLoc, const ShPoint3& kWorldDir, const ShPoint3& kWorldUp,
                                  const ShPoint3& kWorldRight, const ShFrustum& kFrustum, const ShRect& kPort);
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int m_iRendererState;
    int unk204;
    bool m_bInsideRenderTarget;

    __forceinline void SetCurrentCamera(const ShPoint3& kWorldLoc, const ShMatrix3& kWorldRot,
                                        const ShFrustum& kFrustum, const ShRect& kPort)
    {
        ShPoint3 kWorldPosition, kUp, kRight;
        kWorldRot.GetCol(2, kRight);
        kWorldRot.GetCol(1, kUp);
        kWorldRot.GetCol(0, kWorldPosition);
        if ((m_iRendererState == 1 || m_iRendererState == 2) && m_bInsideRenderTarget == true)
            Do_SetCameraData(kWorldLoc, kWorldPosition, kUp, kRight, kFrustum, kPort);
    }
};
struct ShManager
{
};

struct FUN_00b64a00_Pass
{
    int unk00;
    int unk04;
    ShCamera* m_pkAccumulationCamera;
    void FUN_00b64a00(ShCamera* pkCamera, ShCamera* pkOther);
};
// @fnv 0x00b65550
void BSShaderAccumulator::SetupDepth(NiCamera* camera, NiCamera* firstPersonCamera, BSRenderedTexture*)
{
    reinterpret_cast<::FUN_00b64a00_Pass *>(this)->FUN_00b64a00((::ShCamera *)(camera), (::ShCamera *)(firstPersonCamera));
}

// Sets a white background, configures the accumulation camera, and issues pass commands, optionally using pkOther's frustum.
// @fnv 0x00b64a00
void FUN_00b64a00_Pass::FUN_00b64a00(ShCamera* pkCamera, ShCamera* pkOther)
{
    ShRenderer* pkRenderer = (*reinterpret_cast<::ShRenderer * *>(&::NiRenderer::ms_pRenderer));
    ShColor kSaved;
    pkRenderer->GetBackgroundColor(kSaved);
    pkRenderer->SetBackgroundColor(ShColor(1.0f, 1.0f, 1.0f, 1.0f));

    ShManager* pkManager = ((::ShManager *)(::BSShaderManager::GetSceneDepthRenderedTexture()));
    if ((*reinterpret_cast<::ShRenderer * *>(&::NiRenderer::ms_pRenderer))->m_iRendererState)
        ::BSRenderedTexture::EndAllAndResetRendererState();
    ::FUN_00b6b8d0(7, (::NiRenderTargetGroup *)(((int)(reinterpret_cast<::BSRenderedTexture *>((pkManager))->GetGroup()))));

    m_pkAccumulationCamera = pkCamera;
    pkRenderer->SetCurrentCamera(m_pkAccumulationCamera->m_kWorldTranslate, m_pkAccumulationCamera->m_kWorldRotate,
                                 m_pkAccumulationCamera->m_kViewFrustum, m_pkAccumulationCamera->m_kPort);
    reinterpret_cast<::AccumWIP *>(this)->SetShaderPassEnabled(0xb, 0);

    if (pkOther)
    {
        pkRenderer->SetCurrentCamera(m_pkAccumulationCamera->m_kWorldTranslate, m_pkAccumulationCamera->m_kWorldRotate,
                                     pkOther->m_kViewFrustum, m_pkAccumulationCamera->m_kPort);
        reinterpret_cast<::AccumWIP *>(this)->SetShaderPassEnabled(0xc, 0);
    }

    ::BSRenderedTexture::EndAllAndResetRendererState();
    pkRenderer->SetBackgroundColor(kSaved);
}

namespace fnv_00b651e0 {
struct ShPoint3
{
    float x;
    float y;
    float z;
};
struct ShColor
{
    float r;
    float g;
    float b;
    float a;
    ShColor(float fR = 0.0f, float fG = 0.0f, float fB = 0.0f, float fA = 0.0f) : r(fR), g(fG), b(fB), a(fA)
    {}
};
struct ShMatrix3
{
    float m_afEntries[3][3];
    void GetCol(unsigned int uiCol, ShPoint3& kCol) const
    {
        kCol.x = m_afEntries[0][uiCol];
        kCol.y = m_afEntries[1][uiCol];
        kCol.z = m_afEntries[2][uiCol];
    }
};
struct ShFrustum
{
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
};
struct ShRect
{
    float m_fMinimumU;
    float m_fMaximumU;
    float m_fMinimumV;
    float m_fMaximumV;
};
struct ShCamera
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    ShMatrix3 m_kWorldRotate;
    ShPoint3 m_kWorldTranslate;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    ShFrustum m_kViewFrustum;
    int unkF8;
    int unkFC;
    ShRect m_kPort;
};
struct ShRenderer
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void SetBackgroundColor(const ShColor& kColor);
    virtual void v0B0();
    virtual void GetBackgroundColor(ShColor& kColor);
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void Do_SetCameraData(const ShPoint3& kWorldLoc, const ShPoint3& kWorldDir, const ShPoint3& kWorldUp,
                                  const ShPoint3& kWorldRight, const ShFrustum& kFrustum, const ShRect& kPort);
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int m_iRendererState;
    int unk204;
    bool m_bInsideRenderTarget;

    __forceinline void SetCurrentCamera(const ShPoint3& kWorldLoc, const ShMatrix3& kWorldRot,
                                        const ShFrustum& kFrustum, const ShRect& kPort)
    {
        ShPoint3 kWorldPosition, kUp, kRight;
        kWorldRot.GetCol(2, kRight);
        kWorldRot.GetCol(1, kUp);
        kWorldRot.GetCol(0, kWorldPosition);
        if ((m_iRendererState == 1 || m_iRendererState == 2) && m_bInsideRenderTarget == true)
            Do_SetCameraData(kWorldLoc, kWorldPosition, kUp, kRight, kFrustum, kPort);
    }
};
struct ShManager
{
};

struct Sh651_BaseA
{
    virtual void v00();
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
};
struct Sh651_BaseB
{
    int unk00;
};
struct Sh651_Accum : Sh651_BaseA, Sh651_BaseB
{
};
struct Sh651_Cam
{
    int unk00;
    char unk04;
    bool m_bValueAt0C;
    short unk06;
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    ShColor m_kFogTint;
};
struct Sh651_Scene
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
    Sh651_Cam* m_pkCam;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    Sh651_BaseB* m_pkAccum;
};
struct Sh651_Holder
{
    int unk00;
    int unk04;
    Sh651_Scene* m_pkScene;
};

struct Sh651_Pass;
void __cdecl FUN_00ba8ec0(Sh651_Pass* pkPass, int a, int b, int c, int d, int e);
struct Sh651_Pass
{
    int unk00;
    unsigned short m_usPass;
    short unk06;
    int unk08;
    int unk0C;
    Sh651_Pass()
    {
        FUN_00ba8ec0(this, 0, 0, 1, 0, 0);
    }
    void Apply();
    void Apply(unsigned short usPass);
    ~Sh651_Pass();
};
inline void Sh651_Pass::Apply()
{
    (*reinterpret_cast<::fnv_00b651e0::Sh651_Pass * *>(&::DAT_011f91e0)) = this;
    (*reinterpret_cast<int *>(&::DAT_011f91e4)) = m_usPass;
}
inline void Sh651_Pass::Apply(unsigned short usPass)
{
    (*reinterpret_cast<::fnv_00b651e0::Sh651_Pass * *>(&::DAT_011f91e0)) = this;
    m_usPass = usPass;
    (*reinterpret_cast<int *>(&::DAT_011f91e4)) = m_usPass;
}
inline void SetPass651(Sh651_Pass* p)
{
    (*reinterpret_cast<int *>(&::DAT_011f91e4)) = p->m_usPass;
    (*reinterpret_cast<::fnv_00b651e0::Sh651_Pass * *>(&::DAT_011f91e0)) = p;
}
struct Sh651_Geom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_eRequestType;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    ShColor m_kFogTint;
    int GetType() const
    {
        return m_eRequestType;
    }
    int IsType() const
    {
        int b = GetType() == 0x16;
        return b;
    }
};
static Sh651_Geom* Sh651_Cast(Sh651_Geom* pkG)
{
    return (pkG && pkG->IsType()) ? pkG : 0;
}
struct Sh651_Item
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void Render(ShRenderer* pkRenderer);
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    Sh651_Geom* m_pkGeom;
};
struct Sh651_Node
{
    Sh651_Node* m_pkNext;
    int unk04;
    Sh651_Item* m_pkItem;
};
struct Sh651_List
{
    Sh651_Node* m_pkHead;
    int unk04;
    unsigned int m_uiCount;
    Sh651_Item* GetNext(Sh651_Node*& pkPos) const
    {
        Sh651_Item* const& pkElement = pkPos->m_pkItem;
        pkPos = pkPos->m_pkNext;
        return pkElement;
    }
};
struct Sh651_Batch
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void Prepare();
    int unk04;
    ShCamera* m_pkAccumulationCamera;
    int unk0C;
    int unk10;
    int unk14;
    Sh651_List* m_pkList;
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    Sh651_List m_kList;
    bool FUN_00b651e0(ShCamera* pkCamera, ShManager* pkManager);
};

// Renders items whose geometry passes the type check, issuing selected passes and updating fog state.
// @fnv 0x00b651e0
bool Sh651_Batch::FUN_00b651e0(ShCamera* pkCamera, ShManager* pkManager)
{
    unsigned int ItemUpdateArray = m_kList.m_uiCount;
    if (ItemUpdateArray > 0)
    {
        if ((*reinterpret_cast<::fnv_00b651e0::ShRenderer * *>(&::NiRenderer::ms_pRenderer))->m_iRendererState)
            ::BSRenderedTexture::EndAllAndResetRendererState();
        ShRenderer* pkRenderer = (*reinterpret_cast<::fnv_00b651e0::ShRenderer * *>(&::NiRenderer::ms_pRenderer));
        ShColor kSaved;
        ShManager* pkAccumMgr = ((::fnv_00b651e0::ShManager *)(reinterpret_cast<::TextureOwnerB63 *>((static_cast<Sh651_Accum*>((*reinterpret_cast<::fnv_00b651e0::Sh651_Holder * *>(&::DAT_011f91ac))->m_pkScene->m_pkAccum)))->FUN_00b63c60()));
        Sh651_Pass kPass;
        bool bFlag = ::DAT_011ad80e;
        ShCamera* pkSavedCamera = m_pkAccumulationCamera;
        m_pkAccumulationCamera = pkCamera;
        pkRenderer->GetBackgroundColor(kSaved);
        pkRenderer->SetBackgroundColor(ShColor(0.0f, 0.0f, 0.0f, 1.0f));
        m_pkList = &m_kList;
        Prepare();
        kPass.m_usPass = 0x25b;
        Sh651_Node* pkNode = m_kList.m_pkHead;
        while (pkNode)
        {
            Sh651_Item* pkItem = m_kList.GetNext(pkNode);
            Sh651_Geom* pkGeom = pkItem->m_pkGeom;
            if (pkGeom && pkGeom->IsType())
            {
                pkGeom = pkItem->m_pkGeom;
                if (pkGeom)
                {
                    ::FUN_00b6b8d0(3, (::NiRenderTargetGroup *)(((int)(reinterpret_cast<::BSRenderedTexture *>((pkAccumMgr))->GetGroup()))));
                    pkRenderer->SetCurrentCamera(
                        m_pkAccumulationCamera->m_kWorldTranslate, m_pkAccumulationCamera->m_kWorldRotate,
                        m_pkAccumulationCamera->m_kViewFrustum, m_pkAccumulationCamera->m_kPort);
                    if (bFlag)
                    {
                        SetPass651(&kPass);
                        pkItem->Render((*reinterpret_cast<::fnv_00b651e0::ShRenderer * *>(&::NiRenderer::ms_pRenderer)));
                    }
                    else
                    {
                        kPass.m_usPass = 0x25a;
                        SetPass651(&kPass);
                        pkItem->Render((*reinterpret_cast<::fnv_00b651e0::ShRenderer * *>(&::NiRenderer::ms_pRenderer)));
                        kPass.m_usPass = 0x259;
                        SetPass651(&kPass);
                        pkItem->Render((*reinterpret_cast<::fnv_00b651e0::ShRenderer * *>(&::NiRenderer::ms_pRenderer)));
                    }
                    ::BSRenderedTexture::EndAllAndResetRendererState();
                    ::FUN_00b6b8d0(0, (::NiRenderTargetGroup *)(((int)(reinterpret_cast<::BSRenderedTexture *>((pkManager))->GetGroup()))));
                    ShColor kColor = pkGeom->m_kFogTint;
                    Sh651_Cam* pkCam = (*reinterpret_cast<::fnv_00b651e0::Sh651_Holder * *>(&::DAT_011f91ac))->m_pkScene->m_pkCam;
                    pkCam->m_bValueAt0C = true;
                    pkCam->m_kFogTint = kColor;
                    reinterpret_cast<::BB97550Shader *>(((*reinterpret_cast<::fnv_00b651e0::Sh651_Holder * *>(&::DAT_011f91ac))))->FUN_00b97550(0xd, (int)(pkRenderer), (int)(pkManager), (int)(pkManager), 0, 1);
                }
            }
        }
        reinterpret_cast<::BSShaderLightingProperty *>(&(m_kList))->ClearLights();
        pkRenderer->SetBackgroundColor(kSaved);
        m_pkAccumulationCamera = pkSavedCamera;
        reinterpret_cast<::TextureOwnerB63D *>((static_cast<Sh651_Accum*>((*reinterpret_cast<::fnv_00b651e0::Sh651_Holder * *>(&::DAT_011f91ac))->m_pkScene->m_pkAccum)))->FUN_00b63d10();
    }
    return ItemUpdateArray > 0;
}
}  // namespace fnv_00b651e0

struct QueryEntry_b64d
{
    void* m_pkQuery;
    bool m_bPending;
    float m_fVisibility;
    unsigned int m_uiPixels;
    unsigned int m_uiWaitFrames;
};

class QueryOwner_b64d
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38;
    unsigned int m_uiPixels;
    bool m_bWaiting;
    float m_fVisibility;
    QueryEntry_b64d m_akEntries[3];

    void UpdateQueries();
};

enum BSRENDERSTATE_LOCK
{
};

struct NP
{
    NP& operator=(void*);
};

void FUN_00b64e30(AccumWIP*);

class AccumWIP2 : public AccumWIP
{
  public:
};

struct VtblSlot41
{
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual void dummy22();
    virtual void dummy23();
    virtual void dummy24();
    virtual void dummy25();
    virtual void dummy26();
    virtual void dummy27();
    virtual void dummy28();
    virtual void dummy29();
    virtual void dummy30();
    virtual void dummy31();
    virtual void dummy32();
    virtual void dummy33();
    virtual void dummy34();
    virtual void dummy35();
    virtual void dummy36();
    virtual void dummy37();
    virtual void dummy38();
    virtual void dummy39();
    virtual void dummy40();
    virtual void slot41();
};

// Renders accumulation render passes for acc, toggling UpdatePasses based on a byte at offset 0x167 and disabling the depth buffer for a second pass group.
// @fnv 0x00b65dc0
void __cdecl RenderAccumulationPasses(AccumWIP2* apAccumWIP)
{
    if (!apAccumWIP->m_pkAccumulationCamera)
        return;

    if (DAT_011f9fc1)
    {
        DAT_011fa008 = ((void *)(::CreateRenderPassesNode()));
        DAT_011f9fc1 = false;
    }

    *(int*)((char*)apAccumWIP + 0x18) = 0;
    ((VtblSlot41*)apAccumWIP)->slot41();

    reinterpret_cast<::RenderAccumulator *>((apAccumWIP))->FUN_00b63770(1, 0x287, false, -1);
    FUN_00b64e30(apAccumWIP);
    ::fnv_00b63a50::FUN_00b63a50((::fnv_00b63a50::AccumStub *)(apAccumWIP));

    if (*(char*)&apAccumWIP->m_bFourthBooleanFlagBeforeInteger)
        reinterpret_cast<::ViewX *>((apAccumWIP))->UpdatePasses((void *)(0));
    else
        reinterpret_cast<::ViewX *>((apAccumWIP))->UpdatePasses((void *)(1));

    if (*(char*)&apAccumWIP->m_bFourthBooleanFlagBeforeInteger)
        reinterpret_cast<::ViewX *>((apAccumWIP))->UpdatePasses((void *)(1));
    else
        reinterpret_cast<::ViewX *>((apAccumWIP))->UpdatePasses((void *)(0));

    ::BSRenderStateManager::SetDepthBufferEnabled(false, (::BSRENDERSTATE_LOCK)((BSRENDERSTATE_LOCK)0));
    reinterpret_cast<::RenderAccumulator *>((apAccumWIP))->FUN_00b63770(0x2cf, 0x2d7, false, -1);
    apAccumWIP->ClearActivePasses();
}

extern "C" void _ReadWriteBarrier(void);
struct S00b66050_heap
{
};

struct S00b66050_obj
{
};

struct S00b66050_entry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_key;
    S00b66050_obj* m_ptr;
};

struct S00b66050_node
{
    S00b66050_node* m_next;
    unsigned int unk04;
    S00b66050_entry* m_data;
};

struct S00b66050_list
{
    S00b66050_node* m_pFirstNode;
};


class S00b66050_cls
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    S00b66050_list m_kNode;

    void RemoveEntry(unsigned int key);
};

// Finds the entry with the given key in the linked list, frees its object and the entry itself, then removes the node from the list.
// @fnv 0x00b66050
void S00b66050_cls::RemoveEntry(unsigned int key)
{
    S00b66050_node* node = m_kNode.m_pFirstNode;
    if (node == 0)
    {
        return;
    }
    unsigned int uiKey = key;
    while (node != 0)
    {
        S00b66050_entry*& slot = node->m_data;
        node = node->m_next;
        S00b66050_entry* entry = slot;
        key = (unsigned int)entry;
        if (entry != 0 && entry->m_key == uiKey)
        {
            if (entry->m_ptr != 0)
            {
                _ReadWriteBarrier();
                S00b66050_obj* p = entry->m_ptr;
                if (p != 0)
                {
                    reinterpret_cast<::FUN_00c4ed40_cls *>((p))->FUN_00c4ed40();
                    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::S00b66050_heap *>(&::g_memoryManager))))->FUN_00aa4060(p);
                }
                entry->m_ptr = 0;
            }
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::S00b66050_heap *>(&::g_memoryManager))))->FUN_00aa4060(entry);
            reinterpret_cast<::AlphaList *>(&(m_kNode))->FUN_00e7db70(&key);
            return;
        }
    }
}

class RenderQuery
{
  public:
};
class SunQueryAccum : public BSShaderAccumulator
{
  public:
    void PollQuery(unsigned int index);
};
// Processes pending query entries, aggregates visibility and pixel counts, and resets entries when no queries are waiting.
// @fnv 0x00b64d60
void QueryOwner_b64d::UpdateQueries()
{
    float fMaxVisibility = 0.0f;
    unsigned int uiMinPixels = 0x7fffffff;
    bool bAllDone = true;
    for (int i = 0; i < 3; i++)
    {
        if (m_akEntries[i].m_bPending)
        {
            reinterpret_cast<::SunQueryAccum *>(this)->PollQuery(i);
            if (m_akEntries[i].m_bPending)
            {
                m_akEntries[i].m_uiWaitFrames++;
                m_bWaiting = true;
                bAllDone = false;
            }
        }
        if (m_akEntries[i].m_fVisibility > 0.0f || m_akEntries[i].m_uiPixels > 0)
        {
            if (m_akEntries[i].m_uiPixels < uiMinPixels)
                uiMinPixels = m_akEntries[i].m_uiPixels;
            float fVisibility = m_akEntries[i].m_fVisibility;
            if (fVisibility > fMaxVisibility)
                fMaxVisibility = fVisibility;
        }
    }
    if (bAllDone)
    {
        m_bWaiting = false;
        m_fVisibility = fMaxVisibility;
        if (uiMinPixels < 10)
            m_fVisibility = 1.0f;
        m_uiPixels = uiMinPixels;
        for (int i = 0; i < 3; i++)
        {
            m_akEntries[i].m_fVisibility = 0.0f;
            m_akEntries[i].m_uiPixels = 0;
        }
    }
}
// Polls a pending render query, stores its value when status is 1, and releases it for other nonzero statuses.
// @fnv 0x00b63540
void SunQueryAccum::PollQuery(unsigned int uiSlot)
{
    if (uiSlot >= 3)
        return;
    if (!m_akRenderQueryStates[uiSlot].m_bQueryPending)
        return;
    if (!m_akRenderQueryStates[uiSlot].m_pRenderQuery)
        return;
    unsigned int count;
    unsigned char status = ((unsigned char)(reinterpret_cast<::DispatchOwner *>((m_akRenderQueryStates[uiSlot].m_pRenderQuery))->FUN_00c4ee40((int)(&count), 1)));
    if (status == 1)
    {
        if (count == 0)
        {
            m_akRenderQueryStates[uiSlot].m_fQueryValue = 1.0f;
        }
        else
        {
            unsigned int limited = count > 1500u ? 1500u : count;
            float visibility = 1.0f - (double)(float)limited / ::DAT_010737c8;
            m_akRenderQueryStates[uiSlot].m_fQueryValue = visibility;
        }
        m_akRenderQueryStates[uiSlot].m_uiQueryFlags = count;
        m_akRenderQueryStates[uiSlot].m_bQueryPending = false;
    }
    else if (status != 0)
    {
        RenderQuery* query = m_akRenderQueryStates[uiSlot].m_pRenderQuery;
        if (query)
        {
            reinterpret_cast<::FUN_00c4ed40_cls *>((query))->FUN_00c4ed40();
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(query);
        }
        m_akRenderQueryStates[uiSlot].m_pRenderQuery = 0;
        m_akRenderQueryStates[uiSlot].m_bQueryPending = false;
    }
}

namespace fnv_00b64570 {
struct RenderFrustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool orthographic;
};
struct RenderVector
{
    float x, y, z;
};
struct RenderRect
{
    float left, right, top, bottom;
    RenderRect(float a, float b, float c, float d) : left(a), right(b), top(c), bottom(d)
    {}
};
struct RenderSurface
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
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void SetData(void*);
    virtual void slotb0();
    virtual void* GetData();
};
struct TextureView
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
    NiPointer<NiRefObject> texture;
};
struct TextureProvider
{
};
struct ProviderNode
{
    unsigned int unk00, unk04;
    TextureProvider* provider;
};
struct ProviderRoot
{
    unsigned int unk00, unk04;
    ProviderNode* node;
};
struct RenderManagerView
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void SetRect(RenderRect const&);
    virtual void slot0b0();
    virtual void GetRect(RenderRect&);
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void SetCamera(RenderVector const&, RenderVector const&, RenderVector const&, RenderVector const&,
                           RenderFrustum const&, RenderRect const&);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    __forceinline void SetupCamera(RenderVector const& p, RenderVector const& a, RenderVector const& b,
                                   RenderVector const& c, RenderFrustum const& f, RenderRect const& v)
    {
        if ((mode == 1 || mode == 2) && cameraEnabled == 1)
            SetCamera(p, a, b, c, f, v);
    }
    unsigned int mode;
    unsigned int unk204;
    bool cameraEnabled;
};
struct CameraView
{
    float field000;
    float field004;
    float field008;
    float field00c;
    float field010;
    float field014;
    float field018;
    float field01c;
    float field020;
    float field024;
    float field028;
    float field02c;
    float field030;
    float field034;
    float field038;
    float field03c;
    float field040;
    float field044;
    float field048;
    float field04c;
    float field050;
    float field054;
    float field058;
    float field05c;
    float field060;
    float field064;
    float field068;
    float field06c;
    float field070;
    float field074;
    float field078;
    float field07c;
    float field080;
    float field084;
    float field088;
    RenderVector position;
    float field098;
    float field09c;
    float field0a0;
    float field0a4;
    float field0a8;
    float field0ac;
    float field0b0;
    float field0b4;
    float field0b8;
    float field0bc;
    float field0c0;
    float field0c4;
    float field0c8;
    float field0cc;
    float field0d0;
    float field0d4;
    float field0d8;
    RenderFrustum frustum;
    float field0f8;
    float field0fc;
    RenderRect viewport;
    RenderVector const& GetPosition() const
    {
        return position;
    }
    RenderFrustum const& GetFrustum() const
    {
        return frustum;
    }
    RenderRect const& GetViewport() const
    {
        return viewport;
    }
    RenderVector GetUp() const
    {
        RenderVector v;
        v.x = field070;
        v.y = field07c;
        v.z = field088;
        return v;
    }
    RenderVector GetRight() const
    {
        RenderVector v;
        v.x = field06c;
        v.y = field078;
        v.z = field084;
        return v;
    }
    RenderVector GetDirection() const
    {
        RenderVector v;
        v.x = field068;
        v.y = field074;
        v.z = field080;
        return v;
    }
};
struct CountView
{
    unsigned short unk00, count;
};
struct LightingShaderView
{
};
struct DepthAccumulator : BSShaderAccumulator
{
    bool FUN_00b64570(NiCamera* camera, TextureView* target);
};
// Processes geometry groups using a depth surface and may update a lighting shader texture; restores the saved rectangle and camera.
// @fnv 0x00b64570
bool DepthAccumulator::FUN_00b64570(NiCamera* camera, TextureView* target)
{
    if (!target)
        return false;
    bool changedRect = false;
    bool rendered = false;
    RenderRect oldRect(0, 0, 0, 0);
    const NiCamera* savedCamera = m_pkAccumulationCamera;
    m_pkAccumulationCamera = camera;
    RenderManagerView* renderer = (RenderManagerView*)(*reinterpret_cast<::fnv_00b64570::RenderManagerView * *>(&::NiRenderer::ms_pRenderer));
    TextureView* depth = ((::fnv_00b64570::TextureView *)(reinterpret_cast<::RefractionImageSpaceEffect *>(((*reinterpret_cast<::fnv_00b64570::ProviderRoot * *>(&::DAT_011f91ac))->node->provider))->GetRefractionTexture(false)));
    ::BSRenderStateManager::SetColorWriteMask(15, (::BSRENDERSTATE_LOCK)(0));
    int preCount = 0;
    for (unsigned int i = 0; i < m_uiRendererCount; ++i)
        preCount += ((CountView*)m_pGroupRenderer[i]->m_pGeometryGroups[8])->count;
    if (depth && preCount > 0)
    {
        RenderSurface* source = ((::fnv_00b64570::RenderSurface *)(reinterpret_cast<::BSRenderedTexture *>((target))->GetGroup()));
        RenderSurface* destination = ((::fnv_00b64570::RenderSurface *)(reinterpret_cast<::BSRenderedTexture *>((depth))->GetGroup()));
        destination->SetData(source->GetData());
        renderer->GetRect(oldRect);
        renderer->SetRect(RenderRect(0.5f, 0.5f, 0, 0));
        changedRect = true;
        if (((RenderManagerView*)(*reinterpret_cast<::fnv_00b64570::RenderManagerView * *>(&::NiRenderer::ms_pRenderer)))->mode)
            ::BSRenderedTexture::EndAllAndResetRendererState();
        ::FUN_00b6b8d0(0, (::NiRenderTargetGroup *)(::fnv_00b64570::RenderSurface *)(((::fnv_00b64570::RenderSurface *)(reinterpret_cast<::BSRenderedTexture *>((depth))->GetGroup()))));
        renderer->SetupCamera(
            ((CameraView*)m_pkAccumulationCamera)->position, ((CameraView*)m_pkAccumulationCamera)->GetDirection(),
            ((CameraView*)m_pkAccumulationCamera)->GetRight(), ((CameraView*)m_pkAccumulationCamera)->GetUp(),
            ((CameraView*)m_pkAccumulationCamera)->frustum, ((CameraView*)m_pkAccumulationCamera)->viewport);
        reinterpret_cast<::AccumWIP *>(this)->SetShaderPassEnabled(8, false);
        rendered = true;
    }
    for (unsigned int i = 0; i < m_uiRendererCount; ++i)
        reinterpret_cast<::BSBatchRenderer__GeometryGroup *>((((CountView*)m_pGroupRenderer[i]->m_pGeometryGroups[8])))->ClearPassTextureSlots();
    unsigned int count = 0;
    for (unsigned int i = 0; i < m_uiRendererCount; ++i)
        count += ((CountView*)m_pGroupRenderer[i]->m_pGeometryGroups[6])->count;
    if (count > 0)
    {
        if (!rendered)
        {
            bool fallback = false;
            if (!depth)
            {
                depth = ((::fnv_00b64570::TextureView *)(reinterpret_cast<::RefractionImageSpaceEffect *>(((*reinterpret_cast<::fnv_00b64570::ProviderRoot * *>(&::DAT_011f91ac))->node->provider))->GetRefractionTexture(true)));
                fallback = true;
            }
            RenderSurface* source = ((::fnv_00b64570::RenderSurface *)(reinterpret_cast<::BSRenderedTexture *>((target))->GetGroup()));
            RenderSurface* destination = ((::fnv_00b64570::RenderSurface *)(reinterpret_cast<::BSRenderedTexture *>((depth))->GetGroup()));
            destination->SetData(source->GetData());
            renderer->GetRect(oldRect);
            renderer->SetRect(RenderRect(0.5f, 0.5f, 0, 0));
            changedRect = true;
            ::BSRenderedTexture::EndAllAndResetRendererState();
            ::FUN_00b6b8d0(fallback ? 1 : 0, (::NiRenderTargetGroup *)(::fnv_00b64570::RenderSurface *)(((::fnv_00b64570::RenderSurface *)(reinterpret_cast<::BSRenderedTexture *>((depth))->GetGroup()))));
            const NiCamera*& activeCamera = m_pkAccumulationCamera;
            renderer->SetupCamera(((CameraView*)m_pkAccumulationCamera)->position,
                                  ((CameraView*)activeCamera)->GetDirection(), ((CameraView*)activeCamera)->GetRight(),
                                  ((CameraView*)activeCamera)->GetUp(), ((CameraView*)activeCamera)->frustum,
                                  ((CameraView*)activeCamera)->viewport);
        }
        reinterpret_cast<::AccumWIP *>(this)->SetShaderPassEnabled(6, false);
        if (::DAT_011f9fc2)
        {
            NiRefObject* texture =
                (depth ? depth->texture : (const NiPointer<NiRefObject>&)NiPointer<NiRefObject>()).m_pObject;
            LightingShaderView* shader = ((::fnv_00b64570::LightingShaderView *)(::FUN_00b55560((void *)(9))));
            reinterpret_cast<::TextureRenderer *>((shader))->AddTexture((::NiTexture *)(texture));
        }
    }
    if (rendered || count > 0)
        ::BSRenderedTexture::EndAllAndResetRendererState();
    if (depth)
    {
        RenderSurface* source = ((::fnv_00b64570::RenderSurface *)(reinterpret_cast<::BSRenderedTexture *>((target))->GetGroup()));
        RenderSurface* destination = ((::fnv_00b64570::RenderSurface *)(reinterpret_cast<::BSRenderedTexture *>((depth))->GetGroup()));
        destination->SetData(source->GetData());
    }
    if (changedRect)
        renderer->SetRect(oldRect);
    m_pkAccumulationCamera = savedCamera;
    return false;
}
}  // namespace fnv_00b64570

struct LocalCriticalSection
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14;
    LocalCriticalSection()
    {
        InitializeCriticalSection(this);
    }
    ~LocalCriticalSection();
};

inline void* operator new[](unsigned n)
{
    return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(n);
}
struct NiAlphaProperty
{
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    NiAlphaProperty();
    virtual ~NiAlphaProperty();
};
struct SunTest
{
    void* query;
    bool waiting;
    float percent;
    unsigned pixels, frame;
    SunTest() : query(0), waiting(false), percent(0), pixels(0), frame(0)
    {}
};
struct List12
{
    void* head;
    void* tail;
    unsigned count;
    List12()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
    ~List12();
};
struct PassList20
{
    void* head;
    void* tail;
    void* next;
    unsigned count;
    PassList20();
    virtual ~PassList20();
};
struct FUN_00ba8ec0
{
    void* geometry;
    unsigned short pass;
    unsigned char hint, first, last, num, max, extra;
    void* lights;
    FUN_00ba8ec0(void*, unsigned short, bool, unsigned char, ...);
    ~FUN_00ba8ec0();
};
struct RefObject
{
    virtual void f0();
    virtual void f1();
    long refs;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            f1();
    }
};
struct RefPtr
{
    RefObject* object;
    RefPtr(RefObject* p = 0) : object(p)
    {
        if (object)
            InterlockedIncrement(&object->refs);
    }
    ~RefPtr()
    {
        if (object)
            object->DecRefCount();
    }
    void clear()
    {
        if (object)
        {
            object->DecRefCount();
            object = 0;
        }
    }
};
struct FUN_00bd9120
{
    void* state;
    static void* operator new(unsigned n)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(n);
    }
    FUN_00bd9120();
};
void* __cdecl FUN_00aa13e0(unsigned);
struct FUN_00b9a5b0
{
    void* vtable;
    unsigned refs;
    void* renderPasses;
    void* mapVtable;
    unsigned hashSize;
    void* table;
    unsigned mapCount;
    unsigned passCount, firstPass, lastPass;
    void* renderer;
    unsigned short activePass;
    void* nextPass;
    int grouping;
    bool zPrePass;
    void* geometryGroups[13];
    void* alphaGroups[2];
    List12 alphaLists[2];
    void* currentGroups[2];
    static void* operator new(unsigned n)
    {
        return FUN_00aa13e0(n);
    }
    FUN_00b9a5b0(unsigned, int);
};
void* __cdecl FUN_00aa1070(unsigned);
void* __cdecl FUN_00aa13e0(unsigned);
extern void* DAT_010adfd8[];
void* __cdecl FUN_00ec61c0(void*, int, unsigned);
struct Map16
{
    void** vtable;
    unsigned size;
    void* table;
    unsigned count;
    Map16()
    {
        vtable = (*reinterpret_cast<void * (*)[]>(&::DAT_010adfbc));
        size = 37;
        count = 0;
        table = FUN_00aa1070(148);
        unsigned bytes = size * 4;
        FUN_00ec61c0(table, 0, bytes);
        vtable = DAT_010adfd8;
    }
    ~Map16();
};
extern void** vftable_BSShaderAccumulator;
extern void* DAT_010adfd8[];
struct LocalColor
{
    float r, g, b, a;
    LocalColor(float R, float G, float B, float A) : r(R), g(G), b(B), a(A)
    {}
};
struct FUN_00b660d0 : NiAlphaProperty
{
    unsigned mode;
    bool world, cache, depth;
    unsigned sunPixels;
    bool sunWaiting;
    float sunPercent;
    SunTest sun[3];
    bool accumulate, firstPerson, noShader;
    unsigned short queryCount, querySize;
    void** queries;
    List12 fog;
    PassList20 rendered[4], renderedFirst[4];
    RefPtr bound;
    List12 volumes;
    unsigned lastRef;
    bool lastResult;
    LocalColor silhouette;
    bool reflection, refraction, cellWater, underwater;
    int waterHeight;
    bool decals;
    FUN_00bd9120* instance;
    FUN_00b9a5b0* batch;
    FUN_00b9a5b0* batch2;
    unsigned* passes;
    int* buckets;
    bool* firsts;
    bool* actives;
    unsigned batchCount, passCount;
    void* scene;
    RefPtr waterTarget;
    int renderMode;
    RefPtr shadow;
    struct FUN_00ba8ec0 alpha;
    Map16 room;
    int unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc, unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8,
        unk1fc;
    LocalCriticalSection crit;
    FUN_00b660d0(int, unsigned, unsigned);
    virtual ~FUN_00b660d0();
};
struct RenderTLS
{
    unsigned int unknown000;
    unsigned int unknown004;
    unsigned int unknown008;
    unsigned int unknown00c;
    unsigned int unknown010;
    unsigned int unknown014;
    unsigned int unknown018;
    unsigned int unknown01c;
    unsigned int unknown020;
    unsigned int unknown024;
    unsigned int unknown028;
    unsigned int unknown02c;
    unsigned int unknown030;
    unsigned int unknown034;
    unsigned int unknown038;
    unsigned int unknown03c;
    unsigned int unknown040;
    unsigned int unknown044;
    unsigned int unknown048;
    unsigned int unknown04c;
    unsigned int unknown050;
    unsigned int unknown054;
    unsigned int unknown058;
    unsigned int unknown05c;
    unsigned int unknown060;
    unsigned int unknown064;
    unsigned int unknown068;
    unsigned int unknown06c;
    unsigned int unknown070;
    unsigned int unknown074;
    unsigned int unknown078;
    unsigned int unknown07c;
    unsigned int unknown080;
    unsigned int unknown084;
    unsigned int unknown088;
    unsigned int unknown08c;
    unsigned int unknown090;
    unsigned int unknown094;
    unsigned int unknown098;
    unsigned int unknown09c;
    unsigned int unknown0a0;
    unsigned int unknown0a4;
    unsigned int unknown0a8;
    unsigned int unknown0ac;
    unsigned int unknown0b0;
    unsigned int unknown0b4;
    unsigned int unknown0b8;
    unsigned int unknown0bc;
    unsigned int unknown0c0;
    unsigned int unknown0c4;
    unsigned int unknown0c8;
    unsigned int unknown0cc;
    unsigned int unknown0d0;
    unsigned int unknown0d4;
    unsigned int unknown0d8;
    unsigned int unknown0dc;
    unsigned int unknown0e0;
    unsigned int unknown0e4;
    unsigned int unknown0e8;
    unsigned int unknown0ec;
    unsigned int unknown0f0;
    unsigned int unknown0f4;
    unsigned int unknown0f8;
    unsigned int unknown0fc;
    unsigned int unknown100;
    unsigned int unknown104;
    unsigned int unknown108;
    unsigned int unknown10c;
    unsigned int unknown110;
    unsigned int unknown114;
    unsigned int unknown118;
    unsigned int unknown11c;
    unsigned int unknown120;
    unsigned int unknown124;
    unsigned int unknown128;
    unsigned int unknown12c;
    unsigned int unknown130;
    unsigned int unknown134;
    unsigned int unknown138;
    unsigned int unknown13c;
    unsigned int unknown140;
    unsigned int unknown144;
    unsigned int unknown148;
    unsigned int unknown14c;
    unsigned int unknown150;
    unsigned int unknown154;
    unsigned int unknown158;
    unsigned int unknown15c;
    unsigned int unknown160;
    unsigned int unknown164;
    unsigned int unknown168;
    unsigned int unknown16c;
    unsigned int unknown170;
    unsigned int unknown174;
    unsigned int unknown178;
    unsigned int unknown17c;
    unsigned int unknown180;
    unsigned int unknown184;
    unsigned int unknown188;
    unsigned int unknown18c;
    unsigned int unknown190;
    unsigned int unknown194;
    unsigned int unknown198;
    unsigned int unknown19c;
    unsigned int unknown1a0;
    unsigned int unknown1a4;
    unsigned int unknown1a8;
    unsigned int unknown1ac;
    unsigned int unknown1b0;
    unsigned int unknown1b4;
    unsigned int unknown1b8;
    unsigned int unknown1bc;
    unsigned int unknown1c0;
    unsigned int unknown1c4;
    unsigned int unknown1c8;
    unsigned int unknown1cc;
    unsigned int unknown1d0;
    unsigned int unknown1d4;
    unsigned int unknown1d8;
    unsigned int unknown1dc;
    unsigned int unknown1e0;
    unsigned int unknown1e4;
    unsigned int unknown1e8;
    unsigned int unknown1ec;
    unsigned int unknown1f0;
    unsigned int unknown1f4;
    unsigned int unknown1f8;
    unsigned int unknown1fc;
    unsigned int unknown200;
    unsigned int unknown204;
    unsigned int unknown208;
    unsigned int unknown20c;
    unsigned int unknown210;
    unsigned int unknown214;
    unsigned int unknown218;
    unsigned int unknown21c;
    unsigned int unknown220;
    unsigned int unknown224;
    unsigned int unknown228;
    unsigned int unknown22c;
    unsigned int unknown230;
    unsigned int unknown234;
    unsigned int unknown238;
    unsigned int unknown23c;
    unsigned int unknown240;
    unsigned int unknown244;
    unsigned int unknown248;
    unsigned int unknown24c;
    unsigned int unknown250;
    unsigned int unknown254;
    unsigned int unknown258;
    unsigned int unknown25c;
    unsigned int unknown260;
    unsigned int unknown264;
    unsigned int unknown268;
    unsigned int unknown26c;
    unsigned int unknown270;
    unsigned int unknown274;
    unsigned int unknown278;
    unsigned int unknown27c;
    unsigned int unknown280;
    unsigned int unknown284;
    unsigned int unknown288;
    unsigned int unknown28c;
    unsigned int unknown290;
    unsigned int unknown294;
    unsigned int unknown298;
    unsigned int unknown29c;
    unsigned int unknown2a0;
    unsigned int unknown2a4;
    unsigned int unknown2a8;
    unsigned int unknown2ac;
    unsigned int unknown2b0;
    unsigned int unknown2b4;
    unsigned int unknown2b8;
    unsigned int poolState;
};
extern __declspec(thread) RenderTLS g_renderTLS;
// @fnv 0x00b660d0
FUN_00b660d0::FUN_00b660d0(int flags, unsigned count, unsigned pass)
    : silhouette(0, 0, 0, 0), alpha(0, 0x2f5, true, 0, 0)
{
    accumulate = true;
    firstPerson = false;
    noShader = true;
    queries = (void**)reinterpret_cast<::MemoryManagerStandIn *>(&(::g_memoryManager))->FUN_00aa3e40(200);
    queryCount = 0;
    querySize = 50;
    for (int i = 0; i < 50; i++)
        queries[i] = 0;
    reinterpret_cast<::BSShaderLightingProperty *>(&(fog))->ClearLights();
    sunPercent = 1;
    sunWaiting = false;
    sunPixels = 0;
    for (int j = 0; j < 3; j++)
    {
        sun[j].query = 0;
        sun[j].waiting = false;
        sun[j].percent = 0;
        sun[j].pixels = 0;
        sun[j].frame = 0;
    }
    lastRef = 0;
    lastResult = false;
    instance = new FUN_00bd9120;
    batchCount = count;
    passCount = pass;
    batch = new FUN_00b9a5b0(passCount, flags);
    if (batchCount == 2)
    {
        batch2 = new FUN_00b9a5b0(passCount, flags);
    }
    else
        batch2 = 0;
    passes = new unsigned[batchCount];
    buckets = new int[batchCount];
    firsts = new bool[batchCount];
    actives = new bool[batchCount];
    renderMode = 0;
    shadow.clear();
    g_renderTLS.poolState = 0;
    decals = true;
    waterTarget.clear();
    depth = false;
    silhouette = LocalColor(0.3f, 0.3f, 0.3f, 1.0f);
}
