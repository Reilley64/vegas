// fallout_shared/magic/effectitemlist.cpp: EffectItemList, EILStandIn, EffectListCmp, EffectItemListFind and more (28 functions)

#include <new>
#include <cmath>
#include <cstdio>
#include "fnv/decl/BGSDebris.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00403be0_cls.h"
#include "fnv/decl/FUN_00403f80_shell.h"
#include "fnv/decl/FUN_00404210_t.h"
#include "fnv/decl/FUN_004042a0_shell.h"
#include "fnv/decl/FUN_00404390_shell.h"
#include "fnv/decl/FUN_00404420_shell.h"
#include "fnv/decl/FUN_004044d0_shell.h"
#include "fnv/decl/FUN_00406de0.h"
#include "fnv/decl/FUN_0065c110_t.h"
#include "fnv/decl/FUN_0065c490_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008a0c20_shell.h"
#include "fnv/decl/Map62d0.h"
#include "fnv/decl/PerkEntryConditionSet.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00722f60__SL.h"
#include "fnv/decl/fnv_007e0b20__FUN_007e0b20_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008c4330__FUN_008c4330_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011d6000.h"
#include "fnv/symbols_011de000.h"
#include "effectitemlist.h"

// Out-of-line reference for the inline ActorPathHandler::CompleteNoPathUpdate so the
// translation unit emits the method body attributed to the header.
ActorPathHandler::PATH_HANDLER_RESULT CallNoPathUpdate(ActorPathHandler* pHandler, float fSeconds)
{
    return pHandler->CompleteNoPathUpdate(fSeconds);
}

// @fnv 0x00405d80
bool FUN_00405d80(int* pThis)
{
    return pThis[3] > 0;
}

namespace MagicEffectSystem {
struct _Type
{
    enum Type
    {
    };
};
}

struct EffectSetting
{
    int GetArchetype();
};

// @fnv 0x004064b0
bool IsArchetypeFlagSet(EffectSetting* pThis)
{
    return ::HasEffectArchetypeFlag((*(int *)&(const ::MagicEffectSystem::_Type::Type &)((MagicEffectSystem::_Type::Type)pThis->GetArchetype())), 0x7c);
}

struct Actor;
struct EffectSetting;
struct MagicItem;
struct Script;
struct PerkEntryConditionSet;
struct TESFile;
struct TESForm;
struct blob8
{
    char b[8];
};
struct EffectItem
{
    void Save();
    bool Load(TESFile*, char*);
    void Copy(EffectItem*);
    bool Compare(EffectItem*);
    bool MatchesEffect(EffectItem*);
    void InitItem(TESForm*);
    struct blob8 GetEffectString(MagicItem*, float);
    struct blob8 GetEffectString(int, float, bool, bool, bool);
    char* GetIcon();
    bool SetMagnitude(int);
    bool SetArea(int);
    bool SetDuration(int);
    bool SetRange(int);
    int IsAssociatedItemUsed();
    bool IsActorValueUsed();
    bool IsScriptEffect();
    bool IsDisabled();
    bool IsHostile();
    void SetHostile(bool);
    bool IsScriptBasedEffect();
    void GetEffectName(char*);
    struct blob8 GetEffectName();
    int GetEffectID();
    int GetAffectedActorValue();
    void SetActorValueIndex(int);
    Script* GetScript();
    float GetRawCost();
    PerkEntryConditionSet* GetConditions();
    void PausePlayback(PerkEntryConditionSet*);
    void SetEffectAt(EffectSetting*);
    void Initialize(EffectSetting*);
    void* __vecDelDtor(unsigned int);
    char data[20];
    EffectSetting* m_pEffectSetting;
    float m_fCost;
    char Conditions[8];
public:
    bool IsDetrimental();
};

struct EffectItemList_shell
{
    EffectItem* FindCostliestEffectItem(int, int);
};

// @fnv 0x004065e0
int FUN_004065e0(EffectItemList_shell* pthis)
{
    int eresult = -1;
    EffectItem* peffect = pthis->FindCostliestEffectItem(3, 0);
    if (peffect)
    {
        eresult = peffect->GetEffectID();
    }
    return eresult;
}


// @fnv 0x00406ce0
float __cdecl FUN_00406ce0(float afValue)
{
    return static_cast<float>(std::floor(afValue));
}


// Calls _vsprintf_s to format the variadic arguments following apFormat into apString1 using aiSize as the buffer size.
// @fnv 0x00406d00
int __cdecl FUN_00406d00(char* apString1, int aiSize, const char* apFormat, ...)
{
    char* vList = (char*)(&apFormat + 1);
    return std::vsnprintf(apString1, aiSize, apFormat, vList);
}


// @fnv 0x00406d70
bool __cdecl FUN_00406d70(int aiIndex, int aiFlag)
{
    return ((*reinterpret_cast<unsigned int * (*)[]>(&::g_011d61c8))[aiIndex][0x11] & aiFlag) != 0;
}

struct EI;
struct LN
{
};
struct HX
{
    EI* FUN_00406ee0(unsigned char);
};
// @fnv 0x00406ee0
EI* HX::FUN_00406ee0(unsigned char aiIndex)
{
    unsigned char uiCurrentIndex = 0;
    LN* pCurrentElementNext = this ? (LN*)((char*)this + 4) : 0;
    while (pCurrentElementNext)
    {
        if (uiCurrentIndex == aiIndex)
            return *((::EI **)(new ((void *)(pCurrentElementNext)) ::Vec3()));
        uiCurrentIndex++;
        pCurrentElementNext = ((::LN *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
    ::FUN_005b5e40(
        );
    return 0;
}


// @fnv 0x00407000
int __cdecl FUN_00407000(char* apString1, const char* apFormat, char* aList)
{
    return std::vsprintf(apString1, apFormat, aList);
}

class RecursiveSpinLock
{
  public:
    RecursiveSpinLock();
};

extern int DAT_01070020;

// @fnv 0x0071f540
void* ConstructWithVTable(void* apObject)
{
    new ((void *)(reinterpret_cast<RecursiveSpinLock*>(reinterpret_cast<char*>(apObject) + 4))) ::fnv_00722f60::SL();
    *reinterpret_cast<int**>(apObject) = &DAT_01070020;
    return apObject;
}

extern int DAT_01011cf4;
extern int DAT_01011d0c;
namespace stand {
struct TESFullName
{
    TESFullName();
    ~TESFullName();
    void* vt0;
    char pad0[8];
};
}
struct FUN_004056a0
{
    FUN_004056a0();
    ~FUN_004056a0();
    void* vt1;
};
struct FUN_00402c90 : public stand::TESFullName, public FUN_004056a0
{
    FUN_00402c90();
};
// Sets the two vtable pointers of the object to DAT_01011d0c and DAT_01011cf4.
// @fnv 0x00402c90
FUN_00402c90::FUN_00402c90()
{
    vt0 = &DAT_01011d0c;
    vt1 = &DAT_01011cf4;
}

namespace fnv_00405f30 {
struct LN
{
    bool _ref_008256d0();
};
struct EIHelper
{
};
struct EILPad
{
    int vtbl;
};
struct EILStandIn : EILPad, LN
{
    bool HasNonDetrimentalEffect();
};
// @fnv 0x00405f30
bool EILStandIn::HasNonDetrimentalEffect()
{
    EILStandIn* pCurrentElementNext = this;
    if (pCurrentElementNext->_ref_008256d0())
        return false;
    bool bfound = false;
    while (pCurrentElementNext && !bfound)
    {
        EffectItem* pitem = *((::EffectItem **)(new ((void *)(pCurrentElementNext)) ::Vec3()));
        if (pitem && reinterpret_cast<::FUN_0084e3a0_Class *>((((EIHelper*)pitem)))->FUN_0084e3a0() == 2 && !reinterpret_cast<::EffectItem *>((((EIHelper*)pitem)))->IsDetrimental())
            bfound = true;
        pCurrentElementNext = (EILStandIn*)((::fnv_00405f30::LN *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
    return bfound;
}
}  // namespace fnv_00405f30

struct EffectItemHeader
{
    int header;
};
struct EffectItemDetrimental
{
};
struct EffectItemNode
{
    EffectItem* item;
    EffectItemNode* next;
    bool _ref_008256d0();
};

class EffectItem;
struct EffectItemList : public EffectItemHeader, public EffectItemNode
{
    bool FUN_00405da0();
public:
    void AddItem(::EffectItem *);
};

// @fnv 0x00405da0
bool EffectItemList::FUN_00405da0()
{
    EffectItemList* pCurrentElementNext = this;
    if (pCurrentElementNext->_ref_008256d0())
        return false;
    while (pCurrentElementNext)
    {
        EffectItem* pitem = *((::EffectItem **)(new ((void *)(pCurrentElementNext)) ::Vec3()));
        if (pitem && !reinterpret_cast<::EffectItem *>((((EffectItemDetrimental*)pitem)))->IsDetrimental() && !pitem->IsHostile())
            return false;
        pCurrentElementNext = static_cast<EffectItemList*>(((::EffectItemNode *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070())));
    }
    return true;
}

namespace fnv_00406340 {
struct EffectItemHeader
{
    int header;
};
struct EffectItemNode
{
    EffectItem* item;
    EffectItemNode* next;
    void _ref_0063f7b0();
};
struct EffectItemDeleter
{
    ~EffectItemDeleter();
};

struct EffectItemList : public EffectItemHeader, public EffectItemNode
{
    void FUN_00406340();
};

// @fnv 0x00406340
void EffectItemList::FUN_00406340()
{
    EffectItemList* pCurrentElementNext = this;
    while (pCurrentElementNext)
    {
        EffectItem* pitem = *((::EffectItem **)(new ((void *)(pCurrentElementNext)) ::Vec3()));
        if (pitem)
        {
            delete (EffectItemDeleter*)pitem;
            pCurrentElementNext->_ref_0063f7b0();
        }
        else
        {
            pCurrentElementNext = static_cast<EffectItemList*>(((::fnv_00406340::EffectItemNode *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070())));
        }
    }
}
}  // namespace fnv_00406340

namespace fnv_00403ca0 {
class EffectSetting;
struct EffectItem
{
};
struct FUN_00403ba0
{
    FUN_00403ba0();
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;
};
struct PerkEntryConditionSet
{
    PerkEntryConditionSet();
    ~PerkEntryConditionSet();
    void* pHead;
    void* pNext;
};

struct FUN_00403ca0
{
    FUN_00403ba0 data;
    EffectSetting* m_pEffectSetting;
    float m_fCost;
    PerkEntryConditionSet Conditions;
    FUN_00403ca0(EffectItem* other);
};

// @fnv 0x00403ca0
FUN_00403ca0::FUN_00403ca0(EffectItem* pEffectItem)
{
    reinterpret_cast<::FUN_00403be0_cls *>(this)->FUN_00403be0((::InterfaceManager *)(::fnv_00403ca0::EffectSetting *)(((::fnv_00403ca0::EffectSetting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((pEffectItem))->FUN_00825c00()))));
    m_pEffectSetting = 0;
    reinterpret_cast<::FUN_00404210_t *>(this)->CopyFrom((::FUN_00404210_t *)(pEffectItem));
}
}  // namespace fnv_00403ca0

namespace fnv_004062a0 {
struct EffectItem;
struct EffectItemDetrimental
{
};
struct EffectItemNode
{
    bool FUN_008256d0();
    EffectItem* item;
    EffectItemNode* next;
};

struct EffectItemList : public EffectItemNode
{
    virtual ~EffectItemList();
    bool HasDetrimentalEffect();
};

// @fnv 0x004062a0
bool EffectItemList::HasDetrimentalEffect()
{
    bool bDetrimental = false;
    EffectItemList* pCurrentElementNext = this;
    if (pCurrentElementNext->FUN_008256d0())
        return false;
    while (pCurrentElementNext && !bDetrimental)
    {
        EffectItem* pitem = *((::fnv_004062a0::EffectItem **)(new ((void *)(pCurrentElementNext)) ::Vec3()));
        if (pitem && reinterpret_cast<::EffectItem *>((reinterpret_cast<EffectItemDetrimental*>(pitem)))->IsDetrimental())
            bDetrimental = true;
        pCurrentElementNext = static_cast<EffectItemList*>(((::fnv_004062a0::EffectItemNode *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070())));
    }
    return bDetrimental;
}
}  // namespace fnv_004062a0

namespace fnv_004064d0 {
struct MagicEffectEntry
{
};
struct EffectItemDetrimental
{
};
struct EffectItemNode
{
    bool FUN_008256d0();
    EffectItem* item;
    EffectItemNode* next;
};

struct EffectItemList : public EffectItemNode
{
    virtual ~EffectItemList();
    EffectItem* FindCostliestEffectItem(int aeRange, bool abAreaOnly);
};

// Scans the effect list for the non-detrimental item with the highest cost matching the range (and area if requested), returning it or null.
// @fnv 0x004064d0
EffectItem* EffectItemList::FindCostliestEffectItem(int aeRange, bool abAreaOnly)
{
    EffectItemList* pCurrentElementNext;
    EffectItem* pBestItem;
    int imaxCost;
    pBestItem = 0;
    pCurrentElementNext = this;
    if (pCurrentElementNext->FUN_008256d0())
        return 0;
    imaxCost = -1;
    while (pCurrentElementNext)
    {
        EffectItem* pitem;
        int iItemCost;
        pitem = *((::EffectItem **)(new ((void *)(pCurrentElementNext)) ::Vec3()));
        iItemCost = (int)reinterpret_cast<::FUN_00403f80_shell *>((pitem))->GetModifiedCost(0);
        if (!reinterpret_cast<::EffectItem *>((reinterpret_cast<EffectItemDetrimental*>(pitem)))->IsDetrimental() && iItemCost > imaxCost)
        {
            if (abAreaOnly ? reinterpret_cast<::FUN_00404420_shell *>((pitem))->FUN_00404420() > 0 : 1)
            {
                if (aeRange == 3 ||
                    (aeRange != 3 && ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<MagicEffectEntry*>(pitem)))->FUN_0084e3a0())) == aeRange))
                {
                    pBestItem = pitem;
                    imaxCost = iItemCost;
                }
            }
        }
        pCurrentElementNext = static_cast<EffectItemList*>(((::fnv_004064d0::EffectItemNode *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070())));
    }
    return pBestItem;
}
}  // namespace fnv_004064d0

struct Fake406e40
{
    void* FUN_00406e40(unsigned int);
};
// Calls FUN_00406de0, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00406e40
void* Fake406e40::FUN_00406e40(unsigned int flags)
{
    reinterpret_cast<::FUN_00406de0 *>(this)->FUN_00406de0::~FUN_00406de0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Mid93
{
    virtual void f0();
    virtual void f1();
    virtual int f2(int);
};
struct Obj93
{
    char _p[0xA4];
    Mid93 m;
    void GetTwoValues(float*, float*);
};
// Stores FUN_008a0c20(this) into *p2 and the result of m.f2(46) into *p1.
// @fnv 0x0093abe0
void Obj93::GetTwoValues(float* pfValue, float* pfResult)
{
    *pfResult = reinterpret_cast<::FUN_008a0c20_shell *>((this))->FUN_008a0c20();
    *pfValue = (float)m.f2(46);
}

namespace fnv_00405fe0 {
struct EffectItem_acc : EffectItem
{
};

struct BSSimpleList_Standin
{
    bool _ref_008256d0();
};

struct EffectItemList : public BSSimpleList_Standin
{
    virtual ~EffectItemList();
    int m_iEffectCount;

    bool FUN_00405fe0();
};

// @fnv 0x00405fe0
bool EffectItemList::FUN_00405fe0()
{
    EffectItemList* pCurrentElementNext = this;
    if (pCurrentElementNext->_ref_008256d0())
        return false;

    bool bfound = false;
    while (pCurrentElementNext && !bfound)
    {
        EffectItem* pitem = *((::EffectItem **)(new ((void *)(pCurrentElementNext)) ::Vec3()));
        if (pitem && reinterpret_cast<::FUN_0084e3a0_Class *>((((EffectItem_acc*)pitem)))->FUN_0084e3a0() == 1 && !reinterpret_cast<::EffectItem *>((((EffectItem_acc*)pitem)))->IsDetrimental())
            bfound = true;

        pCurrentElementNext = (EffectItemList*)((::fnv_00405fe0::BSSimpleList_Standin *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
    return bfound;
}
}  // namespace fnv_00405fe0

namespace fnv_00406090 {
class EffectItem
{
  public:
};

class BSSimpleList
{
  public:
    bool _ref_008256d0();
};

class EffectItemListPrefix
{
  public:
    int m_prefix;
};

class EffectItemList : public EffectItemListPrefix, public BSSimpleList
{
  public:
    bool FUN_00406090();
};

// @fnv 0x00406090
bool EffectItemList::FUN_00406090()
{
    EffectItemList* pCurrentElementNext;
    bool bfound;

    pCurrentElementNext = this;

    if (pCurrentElementNext->_ref_008256d0())
        return false;

    bfound = false;

    while (pCurrentElementNext && !bfound)
    {
        EffectItem* pitem;

        pitem = *((::fnv_00406090::EffectItem **)(new ((void *)(pCurrentElementNext)) ::Vec3()));

        if (pitem && !reinterpret_cast<::FUN_0084e3a0_Class *>((pitem))->FUN_0084e3a0() && !reinterpret_cast<::EffectItem *>((pitem))->IsDetrimental())
            bfound = true;

        pCurrentElementNext = (EffectItemList*)((::fnv_00406090::BSSimpleList *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }

    return bfound;
}
}  // namespace fnv_00406090

struct EffectItemCmp
{
    bool Compare(EffectItemCmp*);
};

struct EffectListHdr
{
    int header;
};
struct EffectListNode
{
    EffectItemCmp* item;
    EffectListNode* next;
    int GetSize();
    bool IsEmpty();
};
struct EffectListCmp : public EffectListHdr, public EffectListNode
{
    bool FUN_00405a00(EffectListCmp* apOther);
};

// Returns true if the two effect lists differ.
// @fnv 0x00405a00
bool EffectListCmp::FUN_00405a00(EffectListCmp* apOther)
{
    if (apOther->GetSize() != GetSize())
        return true;
    if (!IsEmpty())
    {
        EffectListCmp* pNodeA = this;
        EffectListCmp* pNodeB = apOther;
        while (pNodeA)
        {
            EffectItemCmp* pItemB = *((::EffectItemCmp **)(new ((void *)(pNodeA)) ::Vec3()));
            EffectItemCmp* pElement = *((::EffectItemCmp **)(new ((void *)(pNodeB)) ::Vec3()));
            if (pItemB && pElement && reinterpret_cast<::FUN_004042a0_shell *>((pItemB))->IsDifferentFrom((::EffectItem *)(pElement)))
                return true;
            pNodeA = static_cast<EffectListCmp*>(((::EffectListNode *)(reinterpret_cast<::Callees *>((pNodeA))->FUN_00726070())));
            pNodeB = static_cast<EffectListCmp*>(((::EffectListNode *)(reinterpret_cast<::Callees *>((pNodeB))->FUN_00726070())));
        }
    }
    return false;
}


class B5B10ItemCopy
{
  public:
    B5B10ItemCopy(EffectItem* pkSource);

    static void* operator new(unsigned int uiSize)
    {
        return FUN_00401000(uiSize);
    }
    static void operator delete(void* pvMem);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

class B5B10Owner
{
  public:
    void CopyItemsFromList(EffectItemList* pkList);
};

// Clears the owner, then walks the linked EffectItemList and adds a B5B10ItemCopy for each non-null EffectItem.
// @fnv 0x00405b10
void B5B10Owner::CopyItemsFromList(EffectItemList* pkList)
{
    reinterpret_cast<::fnv_00406340::EffectItemList *>(this)->FUN_00406340();
    EffectItemList* pkNode = pkList;
    while (pkNode)
    {
        EffectItem* pkItem = *((::EffectItem **)(new ((void *)(pkNode)) ::Vec3()));
        if (pkItem)
        {
            B5B10ItemCopy* pkCopy = new B5B10ItemCopy(pkItem);
            reinterpret_cast<::EffectItemList *>(this)->AddItem((::EffectItem *)(pkCopy));
        }
        pkNode = static_cast<EffectItemList*>(((::EffectItemNode *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070())));
    }
}

struct EffectSetting_6140
{
};

struct EffectItem_6140
{
};

struct EffectItemNode_6140
{
    EffectItem_6140* item;
    EffectItemNode_6140* next;
    bool _ref_008256d0();
};

struct EffectItemList_6140 : public EffectItemHeader, public EffectItemNode_6140
{
    bool HasNonDetrimentalEffectWithFlag(unsigned int auiFlag);
};

// @fnv 0x00406140
bool EffectItemList_6140::HasNonDetrimentalEffectWithFlag(unsigned int auiFlag)
{
    EffectItemList_6140* pNode2 = this;
    if (pNode2->_ref_008256d0())
        return false;
    bool bResultTmp = false;
    while (pNode2 && !bResultTmp)
    {
        EffectItem_6140* pItem = *((::EffectItem_6140 **)(new ((void *)(pNode2)) ::Vec3()));
        if (pItem && reinterpret_cast<::S3e60 *>((((::EffectSetting_6140 *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((pItem))->FUN_00825c00()))))->FUN_00403e60(auiFlag) && !reinterpret_cast<::EffectItem *>((pItem))->IsDetrimental())
        {
            bResultTmp = true;
        }
        pNode2 = static_cast<EffectItemList_6140*>(((::EffectItemNode_6140 *)(reinterpret_cast<::Callees *>((pNode2))->FUN_00726070())));
    }
    return bResultTmp;
}

class Entry406
{
  public:
};


class List406
{
  public:
    bool IsEmpty();
};

class Head406
{
  public:
    int unk00;
};

class Node406 : public Head406, public List406
{
  public:
    Entry406* FindEntryByTimeStamp();
};

// Walks the node list and returns the first entry whose GetTimeStamp equals GetUsageMonitorEntry406(), or null.
// @fnv 0x00406200
Entry406* Node406::FindEntryByTimeStamp()
{
    Entry406* pkResult = 0;
    Node406* pkNode = this;
    while (pkNode && !pkNode->IsEmpty() && !pkResult)
    {
        Entry406* pkEntry = *((::Entry406 **)(new ((void *)(pkNode)) ::Vec3()));
        if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((pkEntry))->FUN_00825c00() == ((unsigned int)(::FUN_00408b50())))
            pkResult = pkEntry;
        else
            pkNode = static_cast<Node406*>(((::List406 *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070())));
    }
    return pkResult;
}

struct S_004063e0 : EffectItemList
{
    float GetTotalCost(Actor* actor);
};
// @fnv 0x004063e0
float S_004063e0::GetTotalCost(Actor* actor)
{
    float total;
    EffectItemList* p5 = this;
    if (p5->_ref_008256d0())
        return 0.0f;
    total = 0.0f;
    while (p5)
    {
        EffectItem* item = *((::EffectItem **)(new ((void *)(p5)) ::Vec3()));
        if (!reinterpret_cast<::EffectItem *>((reinterpret_cast<EffectItemDetrimental*>(item)))->IsDetrimental())
            total += reinterpret_cast<::FUN_00403f80_shell *>((item))->GetModifiedCost(actor);
        p5 = static_cast<EffectItemList*>(((::EffectItemNode *)(reinterpret_cast<::Callees *>((p5))->FUN_00726070())));
    }
    return total < ::_DAT_01012060 ? 0.0f : FUN_00404040(total);
}

struct EffectItemListFind
{
    int header;
    EffectItemNode node;
    unsigned char FindEffectItemIndex(int aiFormID);
};

// @fnv 0x00406e70
unsigned char EffectItemListFind::FindEffectItemIndex(int aiFormID)
{
    unsigned char idx3 = 0;
    EffectItemNode* cur = this ? &node : 0;
    while (cur != 0)
    {
        if (aiFormID == (int)*((::EffectItem **)(new ((void *)(cur)) ::Vec3())))
        {
            return idx3;
        }
        idx3++;
        cur = ((::EffectItemNode *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
    }
    ::FUN_005b5e40(
        );
    return 0;
}

struct FaceGenStr
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;
    FaceGenStr();
    ~FaceGenStr();
    operator const char*() const;
};

struct FaceGenModel
{
};

template <class T> struct FaceGenPtr
{
    T* m_pObject;
    FaceGenPtr(T* apObject);
    ~FaceGenPtr();
    operator T*() const;
};

struct FaceGenEntry
{
    int unk00;
    int unk04;
    FaceGenPtr<FaceGenModel> m_pRenderedNodeEntry;
};

struct FaceGenMap
{
};

struct FaceGenLog
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
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void AddLine(FaceGenStr* apLine, bool abFlag);
};

struct FaceGenCache
{
    int unk00;
    FaceGenMap kMap;
    void FUN_0064fe80(FaceGenLog* apLog);
};

// Iterates the cache map and logs each entry's ref count, key, texture size and data size, warning and optionally adding the line to apLog.
// @fnv 0x0064fe80
void FaceGenCache::FUN_0064fe80(FaceGenLog* apLog)
{
    void* pPos3 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(kMap))->GetFirstPos();
    const char* pKey2;
    FaceGenPtr<FaceGenEntry> spEntry3(0);
    while (pPos3)
    {
        reinterpret_cast<::Map62d0 *>(&(kMap))->FUN_00559120((::MapItem62d0 *&)(pPos3), (void *&)(pKey2), (::Helper62d0 &)(spEntry3));
        if (spEntry3)
        {
            FaceGenStr kLine;
            ::FUN_00406f60((::FUN_00406f90_this *)(::FaceGenStr *)(&kLine), "FACEGEN:\t%3d\t%s\t%iKB\t%iKB\r\n",
                         ((int)(reinterpret_cast<::Callees *>((((FaceGenModel*)((FaceGenEntry*)spEntry3)->m_pRenderedNodeEntry)))->FUN_00726070())) - 1, pKey2,
                         reinterpret_cast<::FUN_0065c110_t *>((((FaceGenModel*)((FaceGenEntry*)spEntry3)->m_pRenderedNodeEntry)))->GetEGMSize() >> 10,
                         reinterpret_cast<::FUN_0065c490_cls *>((((FaceGenModel*)((FaceGenEntry*)spEntry3)->m_pRenderedNodeEntry)))->FUN_0065c490() >> 10);
            ::FUN_005b5e40();
            if (apLog)
                apLog->AddLine(&kLine, true);
        }
    }
}

struct Text
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    ~Text();
    operator const char*() const;
};
struct Condition
{
};
struct Setting
{
};
struct EI
{
    int magnitude;
    int area;
    int duration;
    int range;
    int actorValue;
    Text EffectName();
};
struct Node
{
    EI* item;
    Node* next;
};
struct ListBase
{
    Node head;
};
struct TempList : ListBase
{
    virtual void Stub();
    TempList();
    ~TempList();
};
struct Player
{
    double _ref_008bebb0();
    double _ref_008bec80();
};
bool FUN_00406d70(int, int);
int strcat_s(char*, unsigned int, const char*);
struct Description : ListBase
{
    virtual bool First();
    virtual bool Second();
    void BuildDescription(char*, unsigned int);
};
static const char kDurationFormat[] = "%s %+i(%.1f%c)";
// @fnv 0x00406620
void Description::BuildDescription(char* acBuffer, unsigned int size)
{
    char bufferA[128];
    {
        bool s = false;
        TempList p9;
        bool i = First();
        bool hA = Second();
        bool aA = false;
        *acBuffer = 0;
        bufferA[0] = 0;
        for (Node* nodeB = this ? &head : 0; nodeB && *((::EI **)(new ((void *)(nodeB)) ::Vec3())); nodeB = ((::Node *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070())))
        {
            if (reinterpret_cast<::EffectItem *>(((*((::EI **)(new ((void *)(nodeB)) ::Vec3())))))->IsScriptBasedEffect())
                continue;
            if (!((::Condition *)(reinterpret_cast<::BGSDebris *>(((*((::EI **)(new ((void *)(nodeB)) ::Vec3())))))->GetDataList())) ||
                reinterpret_cast<::PerkEntryConditionSet *>((((::Condition *)(reinterpret_cast<::BGSDebris *>(((*((::EI **)(new ((void *)(nodeB)) ::Vec3())))))->GetDataList()))))->ContainsTrait((::TESObjectREFR *)((*reinterpret_cast<::Player * *>(&::_g_thePlayer))), (::TESObjectREFR *)(0), (*(bool *)(&s)), 0))
            {
                if (reinterpret_cast<::S3e60 *>((((::Setting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*((::EI **)(new ((void *)(nodeB)) ::Vec3())))))->FUN_00825c00()))))->FUN_00403e60(0x2000))
                {
                    ::TaskQueueInterface::CopyStringToBuffer(bufferA, 128, (*((::EI **)(new ((void *)(nodeB)) ::Vec3())))->EffectName());
                    if (aA)
                    {
                        strcat_s(acBuffer, size, "\n");
                        strcat_s(acBuffer, size, bufferA);
                    }
                    else
                    {
                        strcat_s(acBuffer, size, bufferA);
                        aA = true;
                    }
                }
                else
                    reinterpret_cast<::fnv_007e0b20::FUN_007e0b20_shell *>(&(p9))->AddEffectItem((::EffectItem *)(*((::EI **)(new ((void *)(nodeB)) ::Vec3()))));
            }
        }
        for (Node* current5 = (Node*)(ListBase*)&p9; current5 && *((::EI **)(new ((void *)(current5)) ::Vec3()));
             current5 = ((::Node *)(reinterpret_cast<::Callees *>((current5))->FUN_00726070())))
        {
            if ((*((::EI **)(new ((void *)(current5)) ::Vec3())))->magnitude && (*((::EI **)(new ((void *)(current5)) ::Vec3())))->actorValue != -1)
            {
                int iValueVal = (*((::EI **)(new ((void *)(current5)) ::Vec3())))->actorValue;
                int kAMagnitude = (*((::EI **)(new ((void *)(current5)) ::Vec3())))->magnitude;
                float pDuration2 = (float)(*((::EI **)(new ((void *)(current5)) ::Vec3())))->duration;
                char hUnit4 = 's';
                if (pDuration2 >= 3600.0)
                {
                    pDuration2 /= 3600.0;
                    hUnit4 = 'h';
                }
                else if (pDuration2 >= 60.0)
                {
                    pDuration2 /= 60.0;
                    hUnit4 = 'm';
                }
                if (FUN_00406d70(iValueVal, 0x200))
                    kAMagnitude = -kAMagnitude;
                if (i)
                {
                    float scaled5 = kAMagnitude * (*reinterpret_cast<::Player * *>(&::_g_thePlayer))->_ref_008bebb0();
                    if (iValueVal == 16)
                        ::ApplyPerkModifiers(12, (::Actor *)((*reinterpret_cast<::Player * *>(&::_g_thePlayer))), &scaled5);
                    kAMagnitude = (int)scaled5;
                }
                if (hA && iValueVal != 54)
                {
                    float scaledOther4 = kAMagnitude * (*reinterpret_cast<::Player * *>(&::_g_thePlayer))->_ref_008bec80();
                    if (iValueVal == 16)
                        ::ApplyPerkModifiers(12, (::Actor *)((*reinterpret_cast<::Player * *>(&::_g_thePlayer))), &scaledOther4);
                    kAMagnitude = (int)scaledOther4;
                }
                if (iValueVal == 54 && kAMagnitude > 0)
                    kAMagnitude = (int)floor(kAMagnitude * reinterpret_cast<::fnv_008c4330::FUN_008c4330_cls *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_008c4330());
                if (hA && iValueVal == 54)
                {
                    float multiplier6 = 1.0f;
                    ::ApplyPerkModifiers(44, (::Actor *)((*reinterpret_cast<::Player * *>(&::_g_thePlayer))), &multiplier6);
                    kAMagnitude = (int)(kAMagnitude * multiplier6);
                }
                if (kAMagnitude >= 0 && kAMagnitude < 1)
                    kAMagnitude = 1;
                if (*acBuffer)
                    strcat_s(acBuffer, 128, ", ");
                if ((*((::EI **)(new ((void *)(current5)) ::Vec3())))->duration)
                {
                    if (pDuration2 != floor(pDuration2))
                        ::FUN_00406d00(bufferA, 128, kDurationFormat, ::FUN_0066eb00((::ActorValue::Index)(iValueVal)), kAMagnitude, pDuration2,
                                  hUnit4);
                    else
                        ::FUN_00406d00(bufferA, 128, "%s %+i(%d%c)", ::FUN_0066eb00((::ActorValue::Index)(iValueVal)), kAMagnitude,
                                  ::FUN_00406d90(pDuration2), hUnit4);
                }
                else
                    ::FUN_00406d00(bufferA, 128, "%s %+i", ::FUN_0066eb00((::ActorValue::Index)(iValueVal)), kAMagnitude);
                strcat_s(acBuffer, size, bufferA);
            }
        }
    }
}
