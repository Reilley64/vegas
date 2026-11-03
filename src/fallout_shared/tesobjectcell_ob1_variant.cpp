
// src/fallout_shared/tesobjectcell_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/tesobjectcell.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include <windows.h>
#include <cmath>
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00b5a9a0_List.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_01203000.h"
#include "tesobjectcell_packet.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
NiAVObject* FUN_0054f4f0();


inline double NiAbs(float fValue)
{
    return (float)std::fabs(fValue);
}
inline float NiFunc(float fValue)
{
    return (float)std::cos(fValue);
}

__forceinline double AbsRef(const float& value)
{
    return (float)std::fabs(value);
}
__forceinline float ComputeAbs(const float& y)
{
    float arg1 = y;
    float context = AbsRef(arg1);
    return context;
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    void Set(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3 operator-(float f) const
    {
        return NiPoint3(x - f, y - f, z - f);
    }
};
struct NiPoint3Ex : NiPoint3
{
    NiPoint3Ex operator-(const NiPoint3& b) const
    {
        NiPoint3Ex result;
        result.x = x - b.x;
        result.y = y - b.y;
        result.z = z - b.z;
        return result;
    }
};

struct FUN_004b4600_Class
{
    void FUN_004b4600();
};
struct M_004b4500 : FUN_004b4600_Class
{
    union
    {
        struct
        {
            float m00, m01, m02, m10, m11, m12, m20, m21, m22;
        };
        float entry[3][3];
    };
    M_004b4500 Inverse()
    {
        M_004b4500 inverse;
        if (!reinterpret_cast<::ThreeByThreeMatrix *>(this)->Inverse((*(::ThreeByThreeMatrix *)(&inverse))))
            inverse.FUN_004b4600();
        return inverse;
    }
    NiPoint3 FUN_004b4500(const NiPoint3* p)
    {
        NiPoint3 result;
        result.x = m00 * p->x + m01 * p->y + m02 * p->z;
        result.y = m10 * p->x + m11 * p->y + m12 * p->z;
        result.z = m20 * p->x + m21 * p->y + m22 * p->z;
        return result;
    }
};
struct SphereInput : NiPoint3Ex
{
    float radius;
};
struct BoxInput
{
    unsigned int kind;
    unsigned int flags;
    NiPoint3 center;
    float halfWidth;
    float halfDepth;
    M_004b4500 rotation;
    unsigned char FUN_00c34890(const SphereInput* sphere);
};

// @fnv 0x00c34890
unsigned char BoxInput::FUN_00c34890(const SphereInput* sphere)
{
    float halfA;
    M_004b4500 rotationB = rotation.Inverse();
    NiPoint3 point7 = rotationB.FUN_004b4500(&(*sphere - center));
    NiPoint3 bound;
    float radius6;
    {
        point7.x = NiAbs(point7.x);
        point7.y = NiAbs(point7.y);
        point7.z = NiAbs(point7.z);
        radius6 = sphere->radius;
        reinterpret_cast<::FUN_00416870_t *>(&(bound))->FUN_00416870(point7.x - radius6, point7.y - radius6, point7.z - radius6);
    }
    if (!(bound.x <= halfWidth) || !(bound.z <= halfDepth) || !(bound.y <= 0.0))
        return false;
    halfA = radius6 * NiFunc(ComputeAbs(bound.y) / radius6);
    return (point7.x - halfA <= halfWidth && point7.y - halfA <= halfDepth) ? 1 : 0;
}

extern int(* DAT_00fdf1c0)(void*);
extern int(* DAT_00fdf1c4)(void*);

struct NiRefObject
{
    virtual void v0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        DAT_00fdf1c0(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!DAT_00fdf1c4(&m_uiRefCount))
            DeleteThis();
    }
};

template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointer(const NiPointer& ptr)
    {
        m_pObject = ptr.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer& FUN_0066b0d0(T* pObject);
};

template <class T> struct NiTListItem
{
    NiTListItem* m_pkNext;
    NiTListItem* m_pkPrev;
    T m_element;
};

typedef NiTListItem<NiPointer<NiRefObject> > Item;

struct NiTPointerAllocator
{
    unsigned int m_uiCount;
};

struct NiTPointerListBase
{
    Item* m_pkHead;
    Item* m_pkTail;
    NiTPointerAllocator m_kItemCount;
    NiPointer<NiRefObject> FUN_00c5c160();
    NiPointer<NiRefObject> FUN_00c5c290();
    void DeleteItem(Item* pkItem)
    {
        int unused[5];  // compiled-out debug locals of the inlined helper
        pkItem->m_element.FUN_0066b0d0(0);
        reinterpret_cast<::FUN_0045cee0_shell *>(&(m_kItemCount))->FUN_0045cee0(pkItem);
        m_kItemCount.m_uiCount--;
    }
    NiPointer<NiRefObject> FUN_00c5bfb0(Item*& kPos);
};

// @fnv 0x00c5bfb0
NiPointer<NiRefObject> NiTPointerListBase::FUN_00c5bfb0(Item*& kPos)
{
    Item* pkNode = kPos;
    if (pkNode == m_pkHead)
    {
        kPos = pkNode->m_pkNext;
        return FUN_00c5c160();
    }
    if (pkNode == m_pkTail)
    {
        kPos = 0;
        return FUN_00c5c290();
    }
    Item* pkPrev = pkNode->m_pkPrev;
    Item* pkNext = pkNode->m_pkNext;
    kPos = pkNext;
    if (pkPrev)
        pkPrev->m_pkNext = pkNext;
    if (pkNext)
        pkNext->m_pkPrev = pkPrev;
    NiPointer<NiRefObject> element = pkNode->m_element;
    DeleteItem(pkNode);
    return element;
}

#include <windows.h>
struct RefObj5b
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};


template <class T> class SmartPtr5b
{
  public:
    T* m_pObject;

    SmartPtr5b(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~SmartPtr5b()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    SmartPtr5b& FUN_006e5cc0(const SmartPtr5b& rhs)
    {
        if (m_pObject != rhs.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = rhs.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct ListItem5b
{
    ListItem5b* m_pNext;
    ListItem5b* m_pListObject;
    SmartPtr5b<RefObj5b> m_element;
};

struct Alloc5b
{
};

struct List5b
{
    ListItem5b* m_pHead;
    ListItem5b* m_pTail;
    Alloc5b m_kItemCount;

    ListItem5b* GetHeadPos() const
    {
        return m_pHead;
    }
    RefObj5b* GetNext(ListItem5b*& pos) const
    {
        RefObj5b* const& e = pos->m_element.m_pObject;
        pos = pos->m_pNext;
        return e;
    }


    void AddHead(const SmartPtr5b<RefObj5b>& element)
    {
        ListItem5b* pkNode = ((::ListItem5b *)(reinterpret_cast<::FUN_0043a010_shell *>(&(m_kItemCount))->FUN_0043a010()));
        pkNode->m_element.FUN_006e5cc0(element);
        reinterpret_cast<::FUN_00b5a9a0_List *>(this)->FUN_00b5a9a0((::FUN_00b5a9a0_Node *)(pkNode));
    }

    SmartPtr5b<RefObj5b> FUN_00c5bfb0(ListItem5b*& pos);
};

struct Owner5b
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
    List5b m_list50;
    List5b m_list5c;
    void FUN_00c5b1c0(RefObj5b* p);
};

// @fnv 0x00c5b1c0
void Owner5b::FUN_00c5b1c0(RefObj5b* p)
{
    if (!p)
        return;
    EnterCriticalSection(&(*reinterpret_cast<::_RTL_CRITICAL_SECTION *>(&::DAT_01203328)));
    ListItem5b* pos = m_list50.GetHeadPos();
    while (pos)
    {
        RefObj5b* cur = m_list50.GetNext(pos);
        if (cur == p)
            break;
    }
    if (!pos)
    {
        m_list50.AddHead(p);
        pos = m_list5c.GetHeadPos();
        while (pos)
        {
            ListItem5b* saved2 = pos;
            RefObj5b* cur = m_list5c.GetNext(pos);
            if (cur == p)
            {
                m_list5c.FUN_00c5bfb0(saved2);
            }
        }
    }
    LeaveCriticalSection(&(*reinterpret_cast<::_RTL_CRITICAL_SECTION *>(&::DAT_01203328)));
}

namespace fnv_00c5b370 {

struct RefObject
{
    virtual ~RefObject();
    virtual void DeleteThis();
    long refCount;

    inline void IncRefCount()
    {
        InterlockedIncrement(&refCount);
    }
    inline void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            DeleteThis();
    }
};

template <class T> class NiPointer
{
  public:
    T* m_p;
    inline NiPointer(T* p = 0) : m_p(p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    inline ~NiPointer()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    inline operator T*() const
    {
        return m_p;
    }
    inline NiPointer& operator=(const NiPointer& o)
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
};

struct ItemNode
{
    ItemNode* next;
    ItemNode* prev;
    NiPointer<RefObject> item;
};

struct NodePool
{
};

struct ItemList
{
    int unk00;
    int unk04;
    NodePool pool;
    inline void AddTail(const NiPointer<RefObject>& ref)
    {
        ItemNode* pNode = ((::fnv_00c5b370::ItemNode *)(reinterpret_cast<::FUN_0043a010_shell *>(&(pool))->FUN_0043a010()));
        pNode->item = ref;
        reinterpret_cast<::FUN_00b5a9a0_List *>(this)->FUN_00b5a9a0((::FUN_00b5a9a0_Node *)(pNode));
    }
};

struct PendingList
{
    ItemNode* head;
    NiPointer<RefObject> FUN_00c5bfb0(ItemNode** iter);
    inline ItemNode* GetHead() const
    {
        return head;
    }
    inline NiPointer<RefObject>& GetNext(ItemNode*& iter)
    {
        NiPointer<RefObject>& item = iter->item;
        iter = iter->next;
        return item;
    }
};


struct ItemQueue
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
    PendingList pending;
    int unk54;
    int unk58;
    ItemList items;
    void FUN_00c5b370(RefObject* obj);
};

// @fnv 0x00c5b370
void ItemQueue::FUN_00c5b370(RefObject* obj)
{
    EnterCriticalSection(&(*reinterpret_cast<char *>(&::DAT_01203328)));
    items.AddTail(obj);
    RefObject* p;
    ItemNode* it;
    ItemNode* cur;
    it = pending.GetHead();
    while (it)
    {
        cur = it;
        p = pending.GetNext(it);
        if (p == obj)
        {
            pending.FUN_00c5bfb0(&cur);
            break;
        }
    }
    LeaveCriticalSection(&(*reinterpret_cast<char *>(&::DAT_01203328)));
}
}  // namespace fnv_00c5b370
