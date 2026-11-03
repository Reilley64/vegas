
// src/staging/blk_00720000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include "runtime/crt.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00725c20_shell.h"
#include "fnv/decl/FUN_00726920_StandIn.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/TargetClass.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/VLList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/filt72c__F2Menu.h"
#include "fnv/decl/fnv_00726210__ListBox726210.h"
#include "fnv/decl/fnv_00726530__FUN_00726530_t.h"
#include "fnv/decl/fnv_0072c880__HLListItem.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00721000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011d8000.h"
#include "../../include/layout_support.h"

struct FUN_00726d50_class
{
    void SetFlags(int a, int b);
    void FUN_00726d50(bool a);
};

// @fnv 0x00726d50
void FUN_00726d50_class::FUN_00726d50(bool a)
{
    SetFlags(2, a);
}

extern int DAT_01070660;

struct GlobalObject_00869f00
{
    void* p;
    void Clear(bool);
    void InitFromGlobal();
};

void GlobalObject_00869f00::Clear(bool)
{}

// @fnv 0x0072ce90
void GlobalObject_00869f00::InitFromGlobal()
{
    p = &DAT_01070660;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}


// @fnv 0x00730490
void FUN_00730490(char* apString, int aiSize)
{
    fnv::crt::strlwr_s(apString, aiSize);
}

struct BSS
{
    ~BSS();
};
struct FUN_00726cf0 : BSS
{
    void* m_p;
    ~FUN_00726cf0();
};
// Destructor that deallocates the pointer stored at offset 0x24 of this object.
// @fnv 0x00726cf0
FUN_00726cf0::~FUN_00726cf0()
{
    ::FUN_00401030(*(void**)((char*)this + 0x24));
}

// @fnv 0x00726d70
void FUN_00726d50_class::SetFlags(int auiFlags, int abSet)
{
    if (*(unsigned char*)&abSet)
        *(unsigned char*)((char*)this + 0x28) |= auiFlags;
    else
        *(unsigned char*)((char*)this + 0x28) &= ~auiFlags;
}

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};
struct StandIn
{
    void* vtable;
    StandIn* Initialize();
};
// Sets the vtable to DAT_01070660, calls FUN_006b3eb0 with 0 and 0, and returns this.
// @fnv 0x0072ce30
StandIn* StandIn::Initialize()
{
    vtable = &DAT_01070660;
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return this;
}

struct GlobalObject_0072ce30
{
    ~GlobalObject_0072ce30();
    void* DestroyAndFree(unsigned int flags);
};

// Runs the destructor on this object, frees it with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x0072ce60
void* GlobalObject_0072ce30::DestroyAndFree(unsigned int flags)
{
    reinterpret_cast<::GlobalObject_00869f00 *>((this))->InitFromGlobal();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct ListX
{
    ~ListX();
};
struct p07
{
};
struct FUN_007308e0 : public ListX
{
    virtual ~FUN_007308e0();
    void FUN_00730950();
};
// Calls FUN_00730950, then passes this to p07::FUN_007211c0.
// @fnv 0x007308e0
FUN_007308e0::~FUN_007308e0()
{
    FUN_00730950();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}

struct Calendar
{
};

// Compares the days passed of two Calendar objects, returning 1 if the first is less, -1 if greater, and 0 if equal.
// @fnv 0x0073b6e0
int CompareCalendarDays(Calendar** apCalendarA, Calendar** apCalendarB)
{
    int daysA = reinterpret_cast<::FUN_009611e0_shell *>(((*apCalendarA)))->FUN_009611e0();
    int daysB = reinterpret_cast<::FUN_009611e0_shell *>(((*apCalendarB)))->FUN_009611e0();
    if (daysA < daysB)
        return 1;
    else if (daysA > daysB)
        return -1;
    else
        return 0;
}

struct TileValue_00a0a270
{
    void FUN_00a0a270(float a, bool b);
};
struct FUN_00726db0_class
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    TileValue_00a0a270* m_t;
    void FUN_00726db0(bool a);
};
// If m_t is set, calls FUN_00a0a270 on it with 1.0f when a is true and 0.0f otherwise, passing true.
// @fnv 0x00726db0
void FUN_00726db0_class::FUN_00726db0(bool abEnabled)
{
    if (m_t)
        m_t->FUN_00a0a270(abEnabled ? 1.0f : 0.0f, true);
}


struct TGF
{
};

struct VATSMenu
{
    void* p0;
    int p1;
    void* p2;
    TGF* tile;

    unsigned int GetFilteredCount();
};

// @fnv 0x00726b40
unsigned int VATSMenu::GetFilteredCount()
{
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(numFiltered);
}

struct FUN_0073ac90_shell
{
    void* m_pHead;
    void* FUN_0073ac90();
};
// @fnv 0x0073ac90
void* FUN_0073ac90_shell::FUN_0073ac90()
{
    return (char*)(void*)*(void**)this + 8;
}

struct Target_b9969
{
};

struct Inner_b9969
{
    Target_b9969* m_00;
    int m_04;
    unsigned char m_08;
};

struct Node_b9969
{
};

struct FUN_00725aa0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    float m_20;

    void ProcessSlots();
};

class Tile
{
  public:
    void Set(int value, int count);
};
struct FUN_00725f40_shell
{
    int unk00;
    int unk04;
    int unk08;
    Tile* unk0c;
    int unk10;
    Tile* unk14;
    int unk18;
    int unk1c;
    float unk20;
    void FUN_00725f40();
};
// Resets m_1c and m_20, iterates the node list calling Call(0xfac, m_1c++) and Log on each slot with m_08 == 0, then calls Finish1 and Finish2.
// @fnv 0x00725aa0
void FUN_00725aa0_cls::ProcessSlots()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (Node_b9969* cur = this ? (Node_b9969*)&unk04 : 0; cur != 0 && *((::Inner_b9969 **)(new ((void *)(cur)) ::Vec3())) != 0; cur = ((::Node_b9969 *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070())))
    {
        if ((*((::Inner_b9969 **)(new ((void *)(cur)) ::Vec3())))->m_08 == 0)
        {
            reinterpret_cast<::Tile *>(((*((::Inner_b9969 **)(new ((void *)(cur)) ::Vec3())))->m_00))->Set(0xfac, m_1c++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)((*((::Inner_b9969 **)(new ((void *)(cur)) ::Vec3())))->m_00));
        }
    }
    reinterpret_cast<::FUN_00725f40_shell *>(this)->FUN_00725f40();
    reinterpret_cast<::FUN_00725c20_shell *>(this)->UpdateHighlightTiles();
}
// Reads a float from unk0c, computes a scroll delta from unk20 versus that value, and writes it plus an item count to unk0c and unk14.
// @fnv 0x00725f40
void FUN_00725f40_shell::FUN_00725f40()
{
    if (unk0c != 0)
    {
        float iStack_c = reinterpret_cast<::TileListBoxCalls *>((unk0c))->GetFloat(0xfb0);
        {

            int iItemCount = 1;

            if (unk20 > ::_DAT_01012060 && iStack_c > ::_DAT_01012060)
            {
                if (unk20 > iStack_c)
                {
                    iItemCount = FUN_00647b70(
                        (int)FUN_004e4430((float)(unsigned int)reinterpret_cast<::FUN_00726920_StandIn *>(this)->FUN_00726920() * (unk20 - iStack_c) / unk20) + 1, 2);
                }
                if (iItemCount > 1)
                {
                    reinterpret_cast<::FUN_00a012d0_t *>((unk0c))->FUN_00a012d0(FUN_00a01860("_scroll_delta"), (unk20 - iStack_c) / (iItemCount - 1), true);
                }
            }
            if (unk14 != 0)
            {
                unk14->Set(FUN_00a01860("_number_of_items"), iItemCount);
            }
        }
    }
}

struct FNVNodeLink
{
};

struct FNVObj
{
};

struct FUN_00726090_cls
{
    int unk00;
    void* m_04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1E;
    float m_20;

    void FUN_00726090();
};

// Clears m_1c and m_20, notifies and removes each linked object whose byte at offset 8 is zero, then calls Flush and Reset.
// @fnv 0x00726090
void FUN_00726090_cls::FUN_00726090()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (FNVNodeLink* cur = this ? (FNVNodeLink*)&this->m_04 : 0; cur != 0 && *((void ***)(new ((void *)(cur)) ::Vec3())) != 0;
         cur = ((::FNVNodeLink *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070())))
    {
        if (((unsigned char*)*((void ***)(new ((void *)(cur)) ::Vec3())))[8] == 0)
        {
            reinterpret_cast<::Tile *>((((FNVObj*)**((void ***)(new ((void *)(cur)) ::Vec3())))))->Set(0xfac, m_1c++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(**((void ***)(new ((void *)(cur)) ::Vec3()))));
        }
    }
    reinterpret_cast<::fnv_00726530::FUN_00726530_t *>(this)->FUN_00726530();
    reinterpret_cast<::fnv_00726210::ListBox726210 *>(this)->FUN_00726210();
}

// @fnv 0x007273e0
int __cdecl FUN_007273e0()
{
    return (int)1077u;
}

struct Fnv72c700Obj
{
};

struct Fnv72c700Holder
{
    Fnv72c700Obj* m_00;
    int m_04;
    unsigned char m_08;
};

struct Fnv72c700Node
{
};

struct FUN_0072c700_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1e;
    float m_20;

    void FUN_0072c700();
};

struct FUN_0072cba0_cls
{
    int unk00;
    int unk04;
    int unk08;
    Tile* unk0c;
    int unk10;
    Tile* unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1e;
    float m_20;

    void FUN_0072cba0();
};
// @fnv 0x0072c700
void FUN_0072c700_cls::FUN_0072c700()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (Fnv72c700Node* cur = this != 0 ? (Fnv72c700Node*)&this->unk04 : 0; cur != 0 && *((::Fnv72c700Holder **)(new ((void *)(cur)) ::Vec3())) != 0;
         cur = ((::Fnv72c700Node *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070())))
    {
        if ((*((::Fnv72c700Holder **)(new ((void *)(cur)) ::Vec3())))->m_08 == 0)
        {
            reinterpret_cast<::Tile *>(((*((::Fnv72c700Holder **)(new ((void *)(cur)) ::Vec3())))->m_00))->Set(0xfac, m_1c++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)((*((::Fnv72c700Holder **)(new ((void *)(cur)) ::Vec3())))->m_00));
        }
    }
    reinterpret_cast<::FUN_0072cba0_cls *>(this)->FUN_0072cba0();
    reinterpret_cast<::fnv_0072c880::HLListItem *>(this)->FUN_0072c880();
}

// Computes a scroll item count from the tile's float at 0xfb0 versus m_20 and stores _scroll_delta and _number_of_items on the tiles.
// @fnv 0x0072cba0
void FUN_0072cba0_cls::FUN_0072cba0()
{
    if (unk0c)
    {
        float fCurrentAmountNext = reinterpret_cast<::TileListBoxCalls *>((unk0c))->GetFloat(0xfb0);
        int iCount = 1;
        if (m_20 > ::_DAT_01012060 && fCurrentAmountNext > ::_DAT_01012060)
        {
            if (m_20 > fCurrentAmountNext)
            {
                iCount = FUN_00647b70((int)FUN_004e4430((float)(((unsigned int)(reinterpret_cast<::filt72c::F2Menu *>(this)->FUN_0072cd80())) * (m_20 - fCurrentAmountNext) / m_20)) + 1, 2);
            }
            if (iCount > 1)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((unk0c))->FUN_00a012d0(FUN_00a01860("_scroll_delta"), (float)((m_20 - fCurrentAmountNext) / (iCount - 1)), true);
            }
        }
        if (unk14)
        {
            unk14->Set(FUN_00a01860("_number_of_items"), iCount);
        }
    }
}

struct InvExtraList;

struct InvExtraListList
{
    void AddHead(InvExtraList*& arItem);
};

struct InvBoundObject;

struct InvEntry
{
    InvExtraListList* pExtendData;
    int iCountDelta;
    InvBoundObject* pType;

    InvEntry(InvBoundObject* apType, int aiCount);
};

struct InvEntryList
{
    InvEntry* pItem;
    InvEntryList* pNext;

    void AddTail(InvEntry*& arItem);
};


struct InvOwner
{
    int unk000;
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
    int iMarkerA8;
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
    int* pCurrent;
    InvEntryList kListA;
    InvEntryList kListB;

    void AddOrUpdateEntryCount(int aiCount);
};

// Finds the pending inventory entry in the active list, adds aiCount to its count, or creates a new entry with the pending type and extra data and appends it.
// @fnv 0x0072faa0
void InvOwner::AddOrUpdateEntryCount(int aiCount)
{
    InvEntryList* pList3 = (pCurrent == &iMarkerA8) ? &kListB : &kListA;
    InvEntry* pEntry3 = ((::InvEntry *)(reinterpret_cast<::TargetClass *>(this)->FindMatchingEntry((::ListNode *)(pList3), (::EntryEx *)((*reinterpret_cast<::InvEntry * *>(&::DAT_011d8fa8))))));
    InvExtraList* pExtra3 = (pEntry3 && ((::InvExtraListList *)(::FUN_00559450((int *)(pEntry3))))) ? *((::InvExtraList **)(new ((void *)(((::InvExtraListList *)(::FUN_00559450((int *)(pEntry3)))))) ::Vec3())) : 0;

    if (pEntry3)
    {
        reinterpret_cast<::CombatProcedure *>((pEntry3))->Initialize((::CombatController *)(intptr_t)(((int)(uintptr_t)(reinterpret_cast<::Callees *>((pEntry3))->FUN_00726070())) + aiCount));
    }
    else
    {
        InvExtraList* pPendingExtra = ((*reinterpret_cast<::InvEntry * *>(&::DAT_011d8fa8)) && ((::InvExtraListList *)(::FUN_00559450((int *)((*reinterpret_cast<::InvEntry * *>(&::DAT_011d8fa8)))))))
                                          ? *((::InvExtraList **)(new ((void *)(((::InvExtraListList *)(::FUN_00559450((int *)((*reinterpret_cast<::InvEntry * *>(&::DAT_011d8fa8)))))))) ::Vec3()))
                                          : 0;
        pEntry3 = new InvEntry(((::InvBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<::InvEntry * *>(&::DAT_011d8fa8))))->GetName())), aiCount);
        if (pPendingExtra)
            ((::InvExtraListList *)(::FUN_00559450((int *)(pEntry3))))->AddHead(pPendingExtra);
        reinterpret_cast<::Callees *>((pList3))->FUN_00905820((void *)&(pEntry3));
    }
}
