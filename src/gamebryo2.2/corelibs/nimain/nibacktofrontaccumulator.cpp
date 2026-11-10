// gamebryo2.2/corelibs/nimain/nibacktofrontaccumulator.cpp: NiBackToFrontAccumulator, BackToFront_aa0 (12 functions)

#include <cstdint>
#include "generated/data/vtables.h"
#include "fnv/list_node.h"
#include <new>
#include "fnv/decl/BSShaderLightingProperty.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/decl/FUN_00ba87d0_Class.h"
#include "fnv/decl/NiAccumulator.h"
#include "fnv/decl/NiRenderer.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_0043a000.h"
#include "fnv/symbols_00a88000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_010a2000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "nibacktofrontaccumulator_decls.h"

// @fnv 0x00aa0fc0
NiBackToFrontAccumulator::NiBackToFrontAccumulator()
{
    *(void**)this = fnv_vftable_DAT_010a2304;
    m_pkAccumulationCamera = 0;
}

// Returns the median of the three values at indices left, mid and right in the array.
// @fnv 0x00aa0a20
float NiBackToFrontAccumulator::GetPivotValue(int left, int right)
{
    int mid = (left + right) >> 1;
    if (m_pfGeometrySortValues[left] < m_pfGeometrySortValues[mid])
    {
        if (m_pfGeometrySortValues[mid] < m_pfGeometrySortValues[right])
            return m_pfGeometrySortValues[mid];
        if (m_pfGeometrySortValues[left] < m_pfGeometrySortValues[right])
            return m_pfGeometrySortValues[right];
        return m_pfGeometrySortValues[left];
    }
    if (m_pfGeometrySortValues[left] < m_pfGeometrySortValues[right])
        return m_pfGeometrySortValues[left];
    if (m_pfGeometrySortValues[mid] < m_pfGeometrySortValues[right])
        return m_pfGeometrySortValues[right];
    return m_pfGeometrySortValues[mid];
}

// @fnv 0x00aa0b40
void NiBackToFrontAccumulator::QuickSort(int left, int right)
{
    if (right > left)
    {
        int iLeft = left - 1;
        int i = right + 1;
        float pivot = GetPivotValue(left, right);
        for (;;)
        {
            do
            {
                --i;
            } while (m_pfGeometrySortValues[i] > pivot);
            do
            {
                ++iLeft;
            } while (m_pfGeometrySortValues[iLeft] < pivot);
            if (iLeft >= i)
                break;
            void* item = m_ppGeometries[iLeft];
            m_ppGeometries[iLeft] = m_ppGeometries[i];
            m_ppGeometries[i] = item;
            float fTempDepth = m_pfGeometrySortValues[iLeft];
            m_pfGeometrySortValues[iLeft] = m_pfGeometrySortValues[i];
            m_pfGeometrySortValues[i] = fTempDepth;
        }
        if (i == right)
            QuickSort(left, i - 1);
        else
        {
            QuickSort(left, i);
            QuickSort(i + 1, right);
        }
    }
}

struct NiObject;
// @fnv 0x00aa0ae0
unsigned char FUN_00aa0ae0(NiObject* pkObject)
{
    unsigned char r = ((unsigned char)(reinterpret_cast<::FUN_00ba87d0_Class *>((pkObject))->FUN_00ba87d0({})));
    return r != 0;
}

// @fnv 0x00aa0e50
const char* __cdecl FUN_00aa0e50()
{
    return (*reinterpret_cast<const char (*)[]>(&::g_011f6058));
}

struct S_00aa0d00_Renderer;
struct S_00aa0d00_Item
{
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_1a();
    virtual void vfn_1b();
    virtual void vfn_1c();
    virtual void vfn_1d();
    virtual void vfn_1e();
    virtual void vfn_1f();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_2a();
    virtual void vfn_2b();
    virtual void vfn_2c();
    virtual void vfn_2d();
    virtual void vfn_2e();
    virtual void vfn_2f();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37(S_00aa0d00_Renderer* r);
};
struct S_00aa0d00_Node
{
    S_00aa0d00_Node* next;
    S_00aa0d00_Node* prev;
    void* data;
};
struct S_00aa0d00_Pool
{
    S_00aa0d00_Node* head;
};
struct S_00aa0d00_Aux
{
    int unk00;
};

struct S_00aa0d00_Base
{
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_1a();
    virtual void vfn_1b();
    virtual void vfn_1c();
    virtual void vfn_1d();
    virtual void vfn_1e();
    virtual void vfn_1f();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_a4();
    int unk04;
    int unk08;
    S_00aa0d00_Node* head;
    S_00aa0d00_Node* tail;
    unsigned int count;
    int unk18;
    unsigned int numItems;
    int unk20;
    S_00aa0d00_Item** items;
    int unk28;
    unsigned int cur;
    void ReleaseAllItems();
};

// If a renderer is set, calls vfn_a4, releases each item via vfn_37, returns all nodes to the free list, then calls FUN_00aa0fe0.
// @fnv 0x00aa0d00
void S_00aa0d00_Base::ReleaseAllItems()
{
    S_00aa0d00_Renderer* r = (*reinterpret_cast<::S_00aa0d00_Renderer * *>(&::NiRenderer::ms_pRenderer));
    if (r)
    {
        vfn_a4();
        cur = numItems;
        S_00aa0d00_Item* item = 0;
        if (cur)
        {
            item = items[--cur];
        }
        while (item)
        {
            item->vfn_37(r);
            item = 0;
            if (cur)
            {
                item = items[--cur];
            }
        }
        while (count)
        {
            S_00aa0d00_Node* pNode = head;
            head = pNode->next;
            if (head)
                head->prev = 0;
            else
                tail = 0;
            pNode->data = 0;
            pNode->prev = 0;
            fnv::list::DestroyNode(pNode);
            count--;
        }
        reinterpret_cast<::NiAccumulator *>(this)->ClearCamera();
    }
}


class AA0F30Object
{
  public:
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

    ~AA0F30Object();
    AA0F30Object* DestroyAndFree(unsigned int uiFlags);
};

class BSFaceGenMorphData
{
  public:
};

class CloningProcess;

class FUN_00aa0fc0 : public BSFaceGenMorphData
{
  public:
    FUN_00aa0fc0() throw();
    virtual void v00();
    unsigned int m_uiRefCount;
    void* m_pkAccumulationCamera;
};

struct ItemList_aa0
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    ItemList_aa0()
    {
        m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }
};

class BackToFront_aa0 : public FUN_00aa0fc0
{
  public:
    ItemList_aa0 m_kUnsortedGeometryList;
    ItemList_aa0* m_pkItemsToSortAndRender;
    int m_iGeometryCount;
    int m_iGeometryCapacity;
    void** m_ppGeometries;
    float* m_pfGeometrySortValues;
    int m_iCurrentItem;

    BackToFront_aa0()
        : m_pkItemsToSortAndRender(0), m_iGeometryCount(0), m_iGeometryCapacity(0), m_ppGeometries(0),
          m_pfGeometrySortValues(0)
    {}
    virtual void v00();

    BackToFront_aa0* FUN_00aa0f50(CloningProcess& kCloning);
};

// @fnv 0x00aa0f50
BackToFront_aa0* BackToFront_aa0::FUN_00aa0f50(CloningProcess& kCloning)
{
    BackToFront_aa0* pkObject = new BackToFront_aa0;
    ::FUN_00aa1000();
    return pkObject;
}

struct FUN_00aa0ac0_shell
{
    void FUN_00aa0ac0(::NiStream& kStream);
};

// @fnv 0x00aa0ac0
void FUN_00aa0ac0_shell::FUN_00aa0ac0(::NiStream& kStream)
{
    reinterpret_cast<::FUN_00a88a40_shell *>(this)->FUN_00a88a40(kStream);
}


extern int DAT_010a2304;


struct C_00aa0dc0 : NiBackToFrontAccumulator
{
    void FUN_00aa0dc0();
};
// Scalar deleting destructor.
// Runs the destructor, then frees this object with AA0F30DeleteSized when uiFlags has bit 0 set, and returns this.
// @fnv 0x00aa0f30
AA0F30Object* AA0F30Object::DestroyAndFree(unsigned int uiFlags)
{
    reinterpret_cast<::C_00aa0dc0 *>((this))->FUN_00aa0dc0();
    if (uiFlags & 1)
        ::FUN_00aa1460(this, sizeof(AA0F30Object));
    return this;
}

// Frees geometry arrays, moves unsorted list nodes to a global free list, updates the vtable, and calls FUN_00a5d3d0.
// @fnv 0x00aa0dc0
void C_00aa0dc0::FUN_00aa0dc0()
{
    NiBackToFrontAccumulator* self = this;

    *(uintptr_t*)self = (uintptr_t)&(*reinterpret_cast<int *>(&::kVtbl_NiBackToFrontAccumulator));
    ::FUN_00aa10f0(self->m_ppGeometries);
    ::FUN_00aa10f0(self->m_pfGeometrySortValues);

    while (self->m_kUnsortedGeometryList.m_uiCount != 0)
    {
        S_00aa0d00_Node* item = (S_00aa0d00_Node*)self->m_kUnsortedGeometryList.m_pkHead;

        self->m_kUnsortedGeometryList.m_pkHead = (NiBackToFrontListItem*)item->next;
        if (self->m_kUnsortedGeometryList.m_pkHead != 0)
        {
            self->m_kUnsortedGeometryList.m_pkHead->m_pkPrevious = 0;
        }
        else
        {
            self->m_kUnsortedGeometryList.m_pkTail = 0;
        }

        item->data = 0;
        item->prev = 0;
        fnv::list::DestroyNode(item);

        --self->m_kUnsortedGeometryList.m_uiCount;
    }

    reinterpret_cast<::BSShaderLightingProperty *>(&(self->m_kUnsortedGeometryList))->ClearLights();
    *(uintptr_t*)self = (uintptr_t)&DAT_010a2304;
    reinterpret_cast<class ::FUN_00a5d3d0 *>((self))->FUN_00a5d3d0::~FUN_00a5d3d0();
}


class NiPoint3
{
  public:
    float x;
    float y;
    float z;

    float operator*(const NiPoint3& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};

class ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];

    void GetCol(unsigned int uiCol, NiPoint3& col) const
    {
        col.x = m_afEntries[0][uiCol];
        col.y = m_afEntries[1][uiCol];
        col.z = m_afEntries[2][uiCol];
    }
};

class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};

class NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;

    const NiPoint3& GetNavMeshData() const
    {
        return m_kCenter;
    }
};


class NiAVObject
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiBound* m_pWorldBound;

    const NiBound& GetBoundingVolume() const
    {
        return m_pWorldBound ? *m_pWorldBound : ::g_defaultBound;
    }
};

class NiCamera
{
  public:
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
    NiTransform m_kWorldSpaceTransform;

    NiPoint3 GetWorldTranslation() const
    {
        NiPoint3 kDVector;
        m_kWorldSpaceTransform.m_kOrientation.GetCol(0, kDVector);
        return kDVector;
    }
};

class FUN_00aa0c00_cls : public NiBackToFrontAccumulator
{
  public:
    void SortGeometriesBackToFront();
};

// Collects geometry pointers from m_pkGeometryList, computes their dot-product sort values against the camera view direction, and calls FUN_00aa0b40 to sort them.
// @fnv 0x00aa0c00
void FUN_00aa0c00_cls::SortGeometriesBackToFront()
{
    if (!m_pkGeometryList)
        m_pkGeometryList = &m_kUnsortedGeometryList;

    m_iGeometryCount = m_pkGeometryList->m_uiCount;
    if (m_iGeometryCount == 0)
        return;

    if (m_iGeometryCount > m_iGeometryCapacity)
    {
        ::FUN_00aa10f0(m_ppGeometries);
        m_iGeometryCapacity = m_iGeometryCount;
        m_ppGeometries = (void**)::FUN_00aa1070(m_iGeometryCapacity * sizeof(void*));
        ::FUN_00aa10f0(m_pfGeometrySortValues);
        m_pfGeometrySortValues = (float*)::FUN_00aa1070(m_iGeometryCapacity * sizeof(float));
    }

    NiBackToFrontListItem* pkPos = m_pkGeometryList->m_pkHead;
    NiPoint3 kViewDir = ((NiCamera*)m_pkAccumulationCamera)->GetWorldTranslation();

    for (int i = 0; i < m_iGeometryCount; i++)
    {
        void** ppkElement = &pkPos->m_pInventoryEntryData;
        pkPos = pkPos->m_pkNext;
        m_ppGeometries[i] = *ppkElement;
        m_pfGeometrySortValues[i] = (*(const ::NiPoint3 *)(new ((void *)&((*(const ::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((void *)(((NiAVObject*)m_ppGeometries[i])))->FUN_0043d450())))) ::Vec3())) * kViewDir;
    }

    reinterpret_cast<::NiBackToFrontAccumulator *>(this)->QuickSort(0, m_iGeometryCount - 1);
}

struct NiBackToFrontItemsArg
{
    void** m_ppGeometries;
    int m_iArrayLength;
};

typedef PoolAllocatorBase<NiBackToFrontListItem> NiBackToFrontItemPool;


static inline NiBackToFrontListItem* NewListItem()
{
    return fnv::list::ConstructNode<NiBackToFrontListItem>();
}

static inline void AddNodeTail(NiBackToFrontGeometryList& kList, NiBackToFrontListItem* pkNode)
{
    pkNode->m_pkNext = 0;
    pkNode->m_pkPrevious = kList.m_pkTail;
    if (kList.m_pkTail)
        kList.m_pkTail->m_pkNext = pkNode;
    else
        kList.m_pkHead = pkNode;
    kList.m_pkTail = pkNode;
    kList.m_uiCount++;
}

static inline void AddTail(NiBackToFrontGeometryList& kList, void* element)
{
    NiBackToFrontListItem* pkNode = NewListItem();
    pkNode->m_pInventoryEntryData = element;
    AddNodeTail(kList, pkNode);
}

struct FUN_00aa0e60_cls : NiBackToFrontAccumulator
{
    void AddGeometries(NiBackToFrontItemsArg* pkArg);
};

// Appends each geometry pointer in pkArg->m_ppGeometries to m_kUnsortedGeometryList via AddTail.
// @fnv 0x00aa0e60
void FUN_00aa0e60_cls::AddGeometries(NiBackToFrontItemsArg* pkArg)
{
    unsigned int ItemUpdateArray = pkArg->m_iArrayLength;
    for (unsigned int uiIndex = 0; uiIndex < ItemUpdateArray; uiIndex++)
    {
        AddTail(m_kUnsortedGeometryList, pkArg->m_ppGeometries[uiIndex]);
    }
}
