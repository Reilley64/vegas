// bscore/bssimplelist.cpp: TargetClass, ObsList, GList, ActList and more (39 functions)

#include <new>
#include "fnv/decl/ActorValueModifierList.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/EffectSettingList.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/LinkedListNode.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00430000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_011f6000.h"
#include "InventoryStackRecord.h"

// Reusable definitions from bscore/bssimplelist.inl. Explicit pointer-list
// instantiations below select the original linker-folded bodies.

// Default constructor for BSSimpleList that initializes m_item and m_pkNext to null.
// @fnv 0x0096a2d0
template <class T> BSSimpleList<T>::BSSimpleList() : m_item(0), m_pkNext(0)
{}

// Initializes m_item from item and sets m_pkNext to null.
// @fnv 0x00470440
template <class T> BSSimpleList<T>::BSSimpleList(T& item) : m_item(item), m_pkNext(0)
{}

// @fnv 0x00905820
template <class T> void BSSimpleList<T>::AddTail(T& item)
{
    if (!item)
        return;
    BSSimpleList<T>* tail = this;
    while (tail->m_pkNext)
        tail = tail->m_pkNext;
    if (tail->m_item)
        tail->m_pkNext = new BSSimpleList<T>(item);
    else
        tail->m_item = item;
}

// @fnv 0x006815c0
template <class T> T& BSSimpleList<T>::GetItem()
{
    return m_item;
}

// @fnv 0x00726070
template <class T> BSSimpleList<T>* BSSimpleList<T>::GetNext()
{
    return m_pkNext;
}

// Returns true when the BSSimpleList has no next node and no item.
// @fnv 0x008256d0
template <class T> bool BSSimpleList<T>::IsEmpty()
{
    return !m_pkNext && !m_item;
}

// Deletes every node after this one, then clears this node's m_item and next pointer.
// @fnv 0x00470470
template <class T> void BSSimpleList<T>::RemoveAll()
{
    while (m_pkNext)
    {
        BSSimpleList<T>* next = m_pkNext->m_pkNext;
        m_pkNext->m_pkNext = 0;
        delete m_pkNext;
        m_pkNext = next;
    }
    m_item = 0;
}

// @fnv 0x0046ffb0
template <class T> BSSimpleList<T>::~BSSimpleList()
{
    reinterpret_cast<::FileMatchList *>(this)->RemoveAll();
}

// @fnv 0x005ae3d0
template <class T> void BSSimpleList<T>::AddHead(T& item)
{
    if (!item)
        return;
    if (m_item)
    {
        BSSimpleList<T>* node = new BSSimpleList<T>(m_item);
        node->m_pkNext = m_pkNext;
        m_pkNext = node;
        m_item = item;
    }
    else
        m_item = item;
}

// When m_pkNext is nonnull, copies its item and successor into this node and deletes it; otherwise sets m_item to 0.
// @fnv 0x0063f7b0
template <class T> void BSSimpleList<T>::RemoveHead()
{
    if (m_pkNext)
    {
        BSSimpleList<T>* node = m_pkNext;
        m_pkNext = node->m_pkNext;
        m_item = node->m_item;
        node->m_pkNext = 0;
        delete node;
    }
    else
        m_item = 0;
}

template class BSSimpleList<InventoryStackRecord*>;

struct ListX
{
    ~ListX();
};
struct W004702f0 : ListX
{
    W004702f0* FUN_004702f0(unsigned int flags);
};
// Destroys the BSSimpleList base subobject and frees the object memory when the low bit of flags is set.
// @fnv 0x004702f0
W004702f0* W004702f0::FUN_004702f0(unsigned int flags)
{
    reinterpret_cast<::EffectSettingList *>(this)->EffectSettingList::~EffectSettingList();
    if (flags & 1)
    {
        ::FUN_00401030(this);
    }
    return this;
}

struct FUN_004818b0
{
    unsigned int a;
    void* b;
    void* c;
    FUN_004818b0();
};
// @fnv 0x004818b0
FUN_004818b0::FUN_004818b0()
{
    a = 1;
    b = 0;
    c = 0;
}

struct NiNode;
struct EqHelper
{
    bool operator==(NiNode*) const;
};
struct ObsList
{
    void* m_item;
    ObsList* m_pkNext;
    bool FUN_004a4460();
};
// Returns true when m_pkNext is null and this object compares equal to a null NiNode pointer.
// @fnv 0x004a4460
bool ObsList::FUN_004a4460()
{
    return (m_pkNext == 0 && reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::EqHelper &)(*reinterpret_cast<EqHelper*>(this)))->operator==((int)(0))) ? 1 : 0;
}

void* __cdecl operator new(unsigned int);

struct SL
{
    char pad[8];
    SL();
    ~SL();
};
struct B006815c0
{
    float x;
    float y;
    B006815c0();
};
struct FUN_004f7680 : public SL
{
    void* m_pScaleResult;
    bool m_bOwnsPointMemory;
    char pad0d[3];
    B006815c0 m_kMinimums;
    B006815c0 Maximums;
    unsigned int m_uiDistanceInsideAtMax;
    unsigned int iCount;

    FUN_004f7680(bool abOwnsPointMemory);
};

struct FUN_004bc550_t
{
    SL* m_00;
    void* m_04;
    int m_08;

    FUN_004bc550_t* FUN_004bc550(int a1, void* a2);
};

// Initialises the object by storing a1 in m_08, allocating a new SL into m_00, and storing a2 in m_04.
// @fnv 0x004bc550
FUN_004bc550_t* FUN_004bc550_t::FUN_004bc550(int aiValue, void* a2)
{
    m_08 = aiValue;
    m_00 = new SL();
    m_04 = a2;
    return this;
}

struct V3
{
    float x, y, z;
    V3();
};
struct FUN_004d9330
{
    char c;
    void* p;
    V3 v;
    FUN_004d9330();
};
// Initializes c to 0, p to null, and v to _NiPoint3_ZERO.
// @fnv 0x004d9330
FUN_004d9330::FUN_004d9330()
{
    c = 0;
    p = 0;
    v = (*reinterpret_cast<::V3 *>((void *)&::NiPoint3::ZERO));
}

struct GObj;
struct GNode
{
};
struct GList
{
    GObj* FUN_004f35b0(int key);
};
// Walks nodes from this pointer and returns the first object whose vtable slot 4 returns key, or null if none match.
// @fnv 0x004f35b0
GObj* GList::FUN_004f35b0(int key)
{
    GNode* node = reinterpret_cast<GNode*>(this);
    GObj* pObj = 0;
    while (node)
    {
        pObj = *((::GObj **)(new ((void *)(node)) ::Vec3()));
        if (pObj && reinterpret_cast<int(*)(GObj*)>((*reinterpret_cast<void***>(pObj))[4])(pObj) == key)
            return pObj;
        node = ((::GNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    return 0;
}


// @fnv 0x004f7680
FUN_004f7680::FUN_004f7680(bool abOwnsPointMemory)
{
    m_bOwnsPointMemory = abOwnsPointMemory;
    m_uiDistanceInsideAtMax = 0x400;
    iCount = 0;
    m_kMinimums.y = 3.4028234663852886e+38f;
    m_kMinimums.x = 3.4028234663852886e+38f;
    Maximums.y = ::DAT_01015f5c;
    Maximums.x = ::DAT_01015f5c;
    m_pScaleResult = 0;
}

struct StrMem
{
    char pad[8];
    StrMem();
    ~StrMem();
};
struct ScriptS
{
    char pad[84];
    ScriptS();
    ~ScriptS();
};
struct CondS
{
    char pad[8];
    CondS();
    ~CondS();
};
struct FUN_00500960
{
    StrMem ResponseText;
    StrMem m_kMenuText;
    ScriptS m_kScript;
    CondS Conditions;
    void* m_pNote;
    void* m_pTerminal;
    char cFlags;

    FUN_00500960();
};

struct FUN_00500910 : StrMem
{
    unsigned int a;
    unsigned int b;
    FUN_00500910();
};
// Constructor for FUN_00500910 that zero-initializes the two unsigned int members a and b.
// @fnv 0x00500910
FUN_00500910::FUN_00500910()
{
    a = 0;
    b = 0;
}

// Calls two script methods, clears header byte 0x10, and sets m_pNote, m_pTerminal, and cFlags to zero.
// @fnv 0x00500960
FUN_00500960::FUN_00500960()
{
    reinterpret_cast<::TESForm *>(&(m_kScript))->SetInitializationState(0);
    reinterpret_cast<::TESForm *>(&(m_kScript))->NotifySaveLoadGameOfFormChange();
    ((char*)((void *)(reinterpret_cast<::BGSCameraPath *>(&(m_kScript))->GetConditions())))[0x10] = 0;
    m_pNote = 0;
    m_pTerminal = 0;
    cFlags = 0;
}

struct FUN_00513d60
{
    void* a;
    bool b;
    void* c;
    FUN_00513d60();
};
// Initializes the struct's pointer and boolean members to null and false.
// @fnv 0x00513d60
FUN_00513d60::FUN_00513d60()
{
    a = 0;
    b = false;
    c = 0;
}

void* __cdecl operator new(unsigned int);

struct _FUN_0052aa80_shell
{
    bool operator!=(int) const;
};

struct Helper62d0 : public _FUN_0052aa80_shell
{
    void* operator=(void const*);
};

struct FUN_006317f0
{
    char pad[8];
    FUN_006317f0(const void*);
};

struct TargetClass
{
    Helper62d0 m_item;
    TargetClass* m_pkNext;

    void FUN_0052a9b0(const NiPointer<NiNode>& item);
};

// Appends a NiNode reference to the end of the linked list, reusing an empty slot or allocating a new node.
// @fnv 0x0052a9b0
void TargetClass::FUN_0052a9b0(const NiPointer<NiNode>& item)
{
    if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::NiPointer< ::NiNode> &)(item))->operator==((int)(0)))
        return;

    TargetClass* pkCur = this;
    while (pkCur->m_pkNext)
        pkCur = pkCur->m_pkNext;

    if (pkCur->m_item != 0)
    {
        pkCur->m_pkNext = (TargetClass*)new FUN_006317f0(&item);
    }
    else
    {
        pkCur->m_item = &item;
    }
}

struct FUN_00590b60
{
    StrMem a;
    CondS b;
    FUN_00590b60();
};
// @fnv 0x00590b60
FUN_00590b60::FUN_00590b60()
{}

struct TESForm;
struct FormFlagRecord
{
    TESForm* pForm;
    unsigned int iFlags;
};

struct ActNode
{
};
struct ActList
{
    void* pad0;
    void* pad1;
    ActNode* head;
    FormFlagRecord* FUN_005a90b0(TESForm* form, bool create);
};
// Returns a matching entry, or the last visited entry with a null form when create is true.
// @fnv 0x005a90b0
FormFlagRecord* ActList::FUN_005a90b0(TESForm* form, bool create)
{
    if (!head)
        return 0;
    FormFlagRecord* empty4;
    ActNode* cur = head;
    empty4 = 0;
    while (cur && *((::FormFlagRecord **)(new ((void *)(cur)) ::Vec3())))
    {
        FormFlagRecord* obj = *((::FormFlagRecord **)(new ((void *)(cur)) ::Vec3()));
        if (obj->pForm == form)
            return obj;
        if (obj->pForm == 0)
            empty4 = obj;
        cur = ((::ActNode *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
    }
    if (create)
        return empty4;
    else
        return 0;
}

struct RefList
{
    void* m_item;
    RefList* m_pkNext;
    bool FUN_005f65d0(void** item);
};
// Walks the linked list and returns true when a node's m_item matches the value pointed to by item.
// @fnv 0x005f65d0
bool RefList::FUN_005f65d0(void** item)
{
    const RefList* pNode = this;
    while (pNode && pNode->m_item != *item)
        pNode = pNode->m_pkNext;
    return pNode != 0;
}

struct TESTexture
{
    char b[8];
    TESTexture();
};
struct FUN_005fcf10
{
    StrMem a;
    StrMem b;
    TESTexture t;
    FUN_005fcf10();
};
// @fnv 0x005fcf10
FUN_005fcf10::FUN_005fcf10()
{}

struct TopicInfoArray
{
    char b[0x18];
    TopicInfoArray();
    ~TopicInfoArray();
};
struct Dummy_0061bf20
{
    char b[0x10];
};
Dummy_0061bf20* ConstructDummy(Dummy_0061bf20*);
struct FUN_00619740
{
    void* pQuest;
    TopicInfoArray arr;
    Dummy_0061bf20 d;
    void* m_pAlternateQuest;
    bool bInitialized;
    FUN_00619740();
};
// Constructs the embedded dummy, sets both quest pointers to null, and clears the initialized flag.
// @fnv 0x00619740
FUN_00619740::FUN_00619740()
{
    ConstructDummy(&d);
    pQuest = 0;
    m_pAlternateQuest = 0;
    bInitialized = false;
}

namespace fnv_00631540 {
void* __cdecl operator new(unsigned int);

struct _FUN_0052aa80_shell
{
    bool operator!=(int) const;
};

struct Helper62d0 : public _FUN_0052aa80_shell
{
    void* operator=(void const*);
};

struct FUN_006317f0
{
    char pad[8];
    FUN_006317f0(const void*);
};

struct TargetClass
{
    Helper62d0 m_item;
    TargetClass* m_pkNext;

    void FUN_00631540(const NiPointer<NiNode>& item);
};

// @fnv 0x00631540
void TargetClass::FUN_00631540(const NiPointer<NiNode>& item)
{
    if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::NiPointer< ::NiNode> &)(item))->operator==((int)(0)))
        return;

    if (reinterpret_cast<::_FUN_0052aa80_shell *>((void *)&(const ::fnv_00631540::_FUN_0052aa80_shell &)(m_item))->operator!=(0))
    {
        TargetClass* pkTmp = (TargetClass*)new FUN_006317f0(this);
        pkTmp->m_pkNext = m_pkNext;
        m_pkNext = pkTmp;
        m_item = &item;
    }
    else
    {
        m_item = &item;
    }
}
}  // namespace fnv_00631540

struct NodeValue
{
    void* value;
    bool operator==(void*) const;
    bool operator!=(const NodeValue&) const;
    NodeValue& operator=(const NodeValue&);
    NodeValue& operator=(void*);
};
struct ListReader
{
    NodeValue item;
    ListReader* next;
    ~ListReader();
    void FUN_00631620(const NodeValue& value);
};
// Removes the node whose item equals value; if it is the only node, clears item.
// @fnv 0x00631620
void ListReader::FUN_00631620(const NodeValue& value)
{
    if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::NodeValue &)(value))->operator==((int)(0)) || reinterpret_cast<::ObsList *>(this)->FUN_004a4460())
        return;
    ListReader* previous;
    ListReader* current = this;
    previous = this;
    while (current && reinterpret_cast<::DummyStruct_00631820 *>((void *)&(const ::NodeValue &)(current->item))->IsNotEqual((const ::DummyStruct_00631820 &)(value)))
    {
        previous = current;
        current = current->next;
    }
    if (current)
    {
        if (current == this)
        {
            if (next)
            {
                previous = next;
                next = previous->next;
                item = previous->item;
                previous->next = 0;
                delete previous;
            }
            else
                item = 0;
        }
        else
        {
            previous->next = current->next;
            current->next = 0;
            delete current;
        }
    }
}

namespace fnv_006317f0 {
struct SpObst
{
    void* obj;
    SpObst(unsigned int*);
};
struct FUN_006317f0 : SpObst
{
    void* next;
    FUN_006317f0(unsigned int*);
};
// @fnv 0x006317f0
FUN_006317f0::FUN_006317f0(unsigned int* p) : SpObst(p)
{
    next = 0;
}
}  // namespace fnv_006317f0

namespace fnv_0066e590 {
struct B006815c0
{
    char pad[12];
    B006815c0();
};

struct NiPoint3
{
    float x, y, z;
};

struct CombatTargetTimestamp
{
    float fTime;
    CombatTargetTimestamp(float);
};

extern float DAT_010673a0;

struct FUN_0066e590
{
    void* pActor;
    int m_eDetectionLevel;
    int iLevel;
    B006815c0 m_kActorPosition;
    char m_abyActorState[4];
    bool b360view;
    bool m_bCombatState;
    bool m_bHasLineOfSight;
    bool m_bIsDetected;
    int m_iDetectionValue;

    FUN_0066e590();
};

// Initializes actor reference, position, detection flags, and sets the timestamp to negative global time.
// @fnv 0x0066e590
FUN_0066e590::FUN_0066e590()
{
    ::FUN_004300a0((::CombatTargetTimestamp *)(::fnv_0066e590::CombatTargetTimestamp *)((CombatTargetTimestamp*)m_abyActorState));
    pActor = 0;
    m_eDetectionLevel = 0;
    m_bHasLineOfSight = false;
    m_bIsDetected = true;
    iLevel = -100;
    *(NiPoint3*)&m_kActorPosition = (*reinterpret_cast<const ::fnv_0066e590::NiPoint3 *>((void *)&::NiPoint3::ZERO));
    CombatTargetTimestamp timeStamp(-DAT_010673a0);
    *(CombatTargetTimestamp*)m_abyActorState = timeStamp;
    b360view = false;
    m_bCombatState = false;
    m_iDetectionValue = -100;
}
}  // namespace fnv_0066e590

struct FUN_007653f0_class
{
    void FUN_007653f0(void** apArray, int(__cdecl* apCompareFn)(const void*, const void*), int aiCount);
};

// Sorts apArray in place using a shell sort algorithm with a compare function apCompareFn over aiCount elements.
// @fnv 0x007653f0
void FUN_007653f0_class::FUN_007653f0(void** apArray, int(__cdecl* apCompareFn)(const void*, const void*), int aiCount)
{
    int igap = 0;
    int ileft = 0;
    int iright = aiCount - 1;

    for (igap = 1; igap <= (iright - ileft) / 9; igap = 3 * igap + 1)
    {
    }

    for (; igap > 0; igap /= 3)
    {
        for (int i = ileft + igap; i <= iright; ++i)
        {
            int j = i;
            void* pswap = apArray[i];
            while (j >= ileft + igap && apCompareFn(pswap, apArray[j - igap]) < 0)
            {
                apArray[j] = apArray[j - igap];
                j -= igap;
            }
            apArray[j] = pswap;
        }
    }
}

struct FlagS
{
    char pad[0x2c];
    unsigned short flags;
    void FUN_007a1950(unsigned int bit, bool on);
};
// Sets or clears the bit at position bit in the flags field depending on the on parameter.
// @fnv 0x007a1950
void FlagS::FUN_007a1950(unsigned int bit, bool on)
{
    if (on)
        flags |= (1 << bit);
    else
        flags &= ~(1 << bit);
}

struct Date
{
    virtual ~Date();
    void* FUN_007b3fa0(unsigned int flags);
};
// Destroys the Date object and, if the low bit of flags is set, frees the object memory via Deallocate, returning the original this pointer.
// @fnv 0x007b3fa0
void* Date::FUN_007b3fa0(unsigned int flags)
{
    reinterpret_cast<::TESForm *>((this))->ClearData();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Cur
{
};
struct TopicS
{
    char pad[0x20];
    Cur* cur;
    bool HasCur();
};
// Sets cur to the address at offset 0xC and returns whether it and its referenced integer are nonzero.
// @fnv 0x0083e0c0
bool TopicS::HasCur()
{
    cur = reinterpret_cast<Cur*>(reinterpret_cast<char*>(this) + 0xc);
    return (cur && *((int *)(new ((void *)(cur)) ::Vec3())) != 0) ? 1 : 0;
}

extern "C" void* __cdecl _alloca(unsigned int);

struct ItemChangeList : BSSimpleList<InventoryStackRecord*>
{

    int ItemsInList();



    void SortItems(int(__cdecl* compare)(InventoryStackRecord*, InventoryStackRecord*));
};

// Copies the list items into a stack buffer, sorts them with the given compare function, then rebuilds the linked list in sorted order.
// @fnv 0x0083fd60
void ItemChangeList::SortItems(int(__cdecl* compare)(InventoryStackRecord*, InventoryStackRecord*))
{

    int iStack6 = ItemsInList();

    InventoryStackRecord** puStack_10 = (InventoryStackRecord**)_alloca(iStack6 * 4 + 4);

    if (!puStack_10)
    {

        reinterpret_cast<::LinkedListNode *>(this)->FUN_007a8790((int (*)(void *, void *))(compare));

        return;
    }

    BSSimpleList<InventoryStackRecord*>* _puStack_18 = this;

    int iStack_20 = 0;

    for (; iStack_20 < iStack6; ++iStack_20, _puStack_18 = _puStack_18->m_pkNext)
    {

        puStack_10[iStack_20] = _puStack_18->m_item;
    }

    reinterpret_cast<::FUN_007653f0_class *>(this)->FUN_007653f0((void **)(puStack_10), (int (*)(const void *, const void *))(compare), iStack6);

    reinterpret_cast<::FileMatchList *>(this)->RemoveAll();

    _puStack_18 = this;

    BSSimpleList<InventoryStackRecord*>* puStack_1c = 0;

    for (int iStack_24 = 0; iStack_24 < iStack6; ++iStack_24)
    {

        if (iStack_24 > 0)
        {

            _puStack_18 = new BSSimpleList<InventoryStackRecord*>(puStack_10[iStack_24]);
        }
        else
        {

            _puStack_18->m_item = puStack_10[iStack_24];

            _puStack_18->m_pkNext = 0;
        }

        if (puStack_1c)
        {

            puStack_1c->m_pkNext = _puStack_18;
        }

        puStack_1c = _puStack_18;
    }
}

struct ItemChangeListNode
{
    InventoryStackRecord* m_item;
    ItemChangeListNode* m_pkNext;
    ~ItemChangeListNode();
    bool IsEmpty();
    void FUN_00905330(InventoryStackRecord* const& item);
};

// Removes a matching node; when it is the head, copies its successor into the head or clears the head, and otherwise unlinks and deletes it.
// @fnv 0x00905330
void ItemChangeListNode::FUN_00905330(InventoryStackRecord* const& item)
{
    if (!item || IsEmpty())
        return;
    ItemChangeListNode* pCur = this;
    ItemChangeListNode* pPrev3 = this;
    while (pCur && pCur->m_item != item)
    {
        pPrev3 = pCur;
        pCur = pCur->m_pkNext;
    }
    if (pCur)
    {
        if (pCur == this)
        {
            if (m_pkNext)
            {
                pPrev3 = m_pkNext;
                m_pkNext = pPrev3->m_pkNext;
                m_item = pPrev3->m_item;
                pPrev3->m_pkNext = 0;
                delete pPrev3;
            }
            else
            {
                m_item = 0;
            }
        }
        else
        {
            pPrev3->m_pkNext = pCur->m_pkNext;
            pCur->m_pkNext = 0;
            delete pCur;
        }
    }
}


struct List_009e03e0
{
    ~List_009e03e0();
    void _ref_0063f7b0();
};

struct FUN_00967290_struct
{
    char pad[0xd48];
    List_009e03e0* m_kNode;

    void FUN_00967290();
};

// @fnv 0x00967290
void FUN_00967290_struct::FUN_00967290()
{
    if (m_kNode)
    {
        void* item = 0;
        while (m_kNode && *((void **)(new ((void *)(m_kNode)) ::Vec3())))
        {
            item = *((void **)(new ((void *)(m_kNode)) ::Vec3()));
            void* pItem = item;
            ::FUN_00401030(pItem);
            m_kNode->_ref_0063f7b0();
        }
        delete m_kNode;
        m_kNode = 0;
    }
}

struct S_00aa3e40
{
};


struct S_00a0c7c0_Node
{
    void* m_item;
    S_00a0c7c0_Node* m_pkNext;
};

struct S_00a0c7c0_List
{
    void* m_item;
    S_00a0c7c0_Node* m_pkNext;

    void AddToHead(void** arg);
};

// Prepends the item pointed to by apItem to the front of this linked list, allocating a new node when the list is not empty.
// @fnv 0x00a0c7c0
void S_00a0c7c0_List::AddToHead(void** apItem)
{
    if (!*apItem)
        return;
    if (m_item)
    {
        S_00a0c7c0_Node* p2 = (S_00a0c7c0_Node*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::S_00aa3e40 *>(&::g_memoryManager))))->FUN_00aa3e40(8);
        S_00a0c7c0_Node* a = p2 ? (p2->m_item = m_item, p2->m_pkNext = 0, p2) : 0;
        S_00a0c7c0_Node* b5 = a;
        b5->m_pkNext = m_pkNext;
        m_pkNext = b5;
        m_item = *apItem;
    }
    else
    {
        m_item = *apItem;
    }
}

struct ModifierEntryView
{
};

struct ModifierFormView
{
    void* vtable;
    unsigned char formType;
    unsigned int formFlags;
    unsigned int formID;
    BSSimpleList<TESFile*> files;
};

struct ModifierNameView
{
    void* vtable;
    BSStringT<char> name;
};

struct ModifierDescriptionView
{
    void* vtable;
    unsigned int fileOffset;
};

struct ModifierIconView
{
    void* vtable;
    BSStringT<char> textureName;
};

struct ModifierActorValueView
{
    ModifierFormView form;
    ModifierNameView fullName;
    ModifierDescriptionView description;
    ModifierIconView icon;
    char* scriptName;
    BSStringT<char> abbreviation;
    unsigned int flags;
};

struct ModifierRoutingList : BSSimpleList<ModifierEntryView*>
{
    void FUN_00937380(ModifierEntryView* mod);
};

namespace ActorValue {
}

// Looks up the modifier key; calls the other routing method when info has bit 0 set, otherwise adds the entry at the head.
// @fnv 0x00937380
void ModifierRoutingList::FUN_00937380(ModifierEntryView* apEntry)
{
    if (!apEntry)
        return;
    char key = ((char)(reinterpret_cast<::FUN_009373f0_shell *>((apEntry))->FUN_009373f0()));
    ActorValueInfo* info = ((::ActorValueInfo *)(::FUN_0066e920((*(int *)&(const ::ActorValue::Index &)(static_cast<ActorValue::Index>(key))))));
    if (info && (reinterpret_cast<ModifierActorValueView*>(info)->flags & 1))
        reinterpret_cast<::ActorValueModifierList *>(this)->AddFastModifier(key, (::Modifier *)(apEntry));
    else
        AddHead(apEntry);
}
