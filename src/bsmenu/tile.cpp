#include "global_string_header.h"
#include <new>
#include <cstddef>
// bsmenu/tile.cpp: Tile, Tile__FloatAction, LoadingMenu, TileListBoxCalls and more (86 functions)

#include <windows.h>
#include "fnv/symbols_0043b000.h"
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004e7560_shell.h"
#include "fnv/decl/FUN_00559a70_Class.h"
#include "fnv/decl/FUN_00a0c6c0_cls.h"
#include "fnv/decl/FUN_00a20650_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/Interface.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/Node185.h"
#include "fnv/decl/RMapBase.h"
#include "fnv/decl/S_00a0c7c0_List.h"
#include "fnv/decl/S_00adc830_Map.h"
#include "fnv/decl/SndStack70.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TextString.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_009ff000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a04000.h"
#include "fnv/symbols_00a07000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a1d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0103a000.h"
#include "fnv/symbols_0103c000.h"
#include "fnv/symbols_0106f000.h"
#include "fnv/symbols_01076000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "Tile__FloatAction.h"

// @fnv 0x00a0c000
float Tile__FloatAction::GetStoredFloatValue()
{
    return fValue;
}

#include "tile_packet_decls.h"

// Layout views for objects tile.cpp reaches through other types; the pads stand for members not named here.
struct DListNodeView
{
    DListNodeView* m_pNext;
    DListNodeView* m_pPrev;
    void* m_pItem;
};
struct NiNodeChildArrayView
{
    void* m_pVtbl;
    void** m_ppBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};
struct NiNodeChildrenView
{
    char pad00[0x9c];
    NiNodeChildArrayView m_kChildren;
};
struct TileShaderPropertyView
{
    char pad00[0x68];
    float m_afColor[4];
    float m_fAlpha;
};
struct TileTemplateView
{
    char pad00[0x8];
    DListNodeView* m_pItemHead;
};

#include "fnv/decl/FUN_00a7b300_shell.h"

namespace fnv_00a09410 {
struct EvalTile;
}

namespace fnv_00a09410 {
struct EvalValue;
}

namespace fnv_00a09410 {
struct EvalReference { int trait; EvalTile* tile; float value; const char* text; };
}

namespace fnv_00a09410 {
struct EvalAction {
 virtual float GetFloat();
 virtual EvalReference* GetReference();
 int operation; EvalAction* next;
};
}

namespace fnv_00a09410 {
struct EvalTile {
 virtual void v0(); virtual void v1(); virtual void v2();
 virtual void v3(); virtual void v4(); virtual void v5();
 virtual int ChangeValue(int,float,const char*);
 int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c;
 unsigned flags;
 __forceinline bool Flag(unsigned mask) { return (flags&mask)!=0; }
};
}

namespace fnv_00a09410 {
struct EvalValue {
 int m_iValueId; EvalTile* pTile; float fValue; char* pString; EvalAction* actions;
 __forceinline char* String() { return pString; }
 void FUN_00a09410(bool);
};
}

class NiAVObject;

struct FadeTile {
    virtual void V0(); virtual void V1(); virtual void V2(); virtual int GetType();
    int field04; int field08; int field0c; int field10; int field14; int field18; int field1c;
    int field20; int field24; FadeTile* parent; NiAVObject* model;
};

struct FadeRecord {
    float start; float end; unsigned int time; float duration; int trait; FadeTile* tile; unsigned int type;
};

struct LocalManager { void Deallocate(void*); void* Allocate(unsigned int); };

struct FadeList {
    FadeRecord* item; FadeList* next;
    ~FadeList() { RemoveAll(); }
    inline void RemoveAll() { while (next) { FadeList* after=next->next; next->next=0; delete next; next=after; } item=0; }
    inline void FUN_00a0cbe0(FadeRecord*& p) {
        if (!p || (!next && !item)) return;
        FadeList* cur=this; FadeList* prev=this;
        while(cur && cur->item != p) { prev=cur; cur=cur->next; }
        if(!cur) return;
        if(cur==this) { if(next) { prev=next; next=prev->next; item=prev->item; prev->next=0; delete prev; } else item=0; }
        else { prev->next=cur->next; cur->next=0; delete cur; }
    }
};

class Tile;

// namespace fnv_00a03f70

struct FUN_00a087d0_shell : public Tile {
    void FUN_00a087d0(Tile*, Tile*);
};


namespace fnv_00a01350 {
struct FUN_00a01350_shell : public Tile {
    void FUN_00a01350(int, char*, bool);
};
}


struct FUN_00a012d0_t {
    void FUN_00a012d0(int aiTrait, float afValue, bool abClearActions);
};


struct GO {
    GO& operator=(void*);
};

struct Member0C {
    char pad[0x28];
    intptr_t member_28;
    GO member_2c;
};

struct Member10 {
    char pad[0x18];
    void* member_18;
};

struct __declspec(novtable) Base_00a0abe0 {
    virtual ~Base_00a0abe0() {
        reinterpret_cast<::FUN_00a7b300_shell *>((this))->FUN_00a7b300();
    }
};

struct FUN_00a0abe0 : Base_00a0abe0 {
    char pad_04[0x08];
    Member0C* member_0c;
    Member10* member_10;

    virtual ~FUN_00a0abe0();
};

class Menu;

struct FUN_00a03c90_shell : public Tile {
    Menu* FUN_00a03c90();
};


// @fnv 0x00a01530
float Tile::GetInterfaceScale()
{
    return ::FUN_00a1dfb0();
}

// @fnv 0x00a0bae0
bool Tile::IsPointInside(float x,float y)
{
    return true;
}

// @fnv 0x0071aa80
bool Tile::GetSpeechChallengeFailure()
{
    return m_bSpeechChallengeFailure;
}

// @fnv 0x00a04620
void Tile::SetSpeechChallengeFailure(bool recursive)
{
    ::fnv_00a04200::FUN_00a04200(false);
}

// Sets the given trait to the integer value cast to float, delegating to the float overload with the third argument true.
// @fnv 0x00700320
void Tile::Set(int trait,int value)
{
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(trait,(float)value,true);
}

// @fnv 0x00a03c60
bool Tile::IsMenuRendered()
{
    Menu* menu=reinterpret_cast<::FUN_00a03c90_shell *>(this)->FUN_00a03c90(); bool rendered=menu->m_bIsSpecial; return rendered;
}

// Returns true if the bit at position trait is set in floatFlags.
// @fnv 0x00458110
bool LoadingMenu::GetFloat(int trait) { return (floatFlags & (1 << trait)) != 0; }

// Returns the element of the given list item and advances pos to the item's previous node.
// @fnv 0x00683520
Tile*& NiTPointerList<Tile*>::GetPrev(NiTListItem<Tile*>*& pos)
{
    Tile*& result=pos->m_element;
    pos=pos->m_pkPrev;
    return result;
}

// Sets the given trait to the given unsigned value by forwarding to the float overload with the third argument true.
// @fnv 0x00715c60
void Tile::Set(int trait,unsigned int value)
{
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(trait,(float)value,true);
}

struct NiStream;
struct blob8 { char b[8]; };
struct NiPoint2 {
    static struct blob8 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float Dot(void*);
    static void LoadBinary(NiStream*, NiPoint2*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint2*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float x;
    float y;
};
struct FUN_004e8880_shell : public NiPoint2 {
    struct blob8 Subtract();
};

namespace fnv_anon_tile {} using namespace fnv_anon_tile; namespace fnv_anon_tile {
struct NiPoint2_Sub : public NiPoint2 {
    NiPoint2* Subtract(NiPoint2* __ret, const NiPoint2& pt) const;
};
}

// Returns a copy of this NiPoint2 with pt's x and y subtracted from it.
// @fnv 0x004e8880
NiPoint2* NiPoint2_Sub::Subtract(NiPoint2* pResult, const NiPoint2& aPoint) const
{
    NiPoint2 result = *this;
    result.x -= aPoint.x;
    result.y -= aPoint.y;
    *pResult = result;
    return pResult;
}


extern "C" void* FUN_00718c90(void*);

struct Dummy_00718c90 {
    char pad[0x10];
    Dummy_00718c90() {
        FUN_00718c90(this);
    }
};

extern Dummy_00718c90* DAT_011d8a88;

// Returns the global Dummy_00718c90 instance, allocating and constructing it first if it is null.
// @fnv 0x00718b60
Dummy_00718c90* __cdecl FUN_00718b60()
{
    if (!DAT_011d8a88)
        DAT_011d8a88 = new Dummy_00718c90;
    return DAT_011d8a88;
}

struct FUN_00a011f0_shell : public Tile {
    char* FUN_00a011f0(int);
};

struct FUN_00a01230_shell : public Tile {
    bool IsTraitNonZero(int);
};

struct FUN_00a01290_shell : public Tile {
    void SetTraitAndReset(int, float);
};

// Sets the given trait to afValue and then immediately resets it to 0.0f, both with the third argument true.
// @fnv 0x00a01290
void FUN_00a01290_shell::SetTraitAndReset(int aiTrait, float afValue)
{
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(aiTrait, afValue, true);
    reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(aiTrait, 0.0f, true);
}

struct FUN_00a013d0_shell : public Tile {
    float GetTotalFloat();
};

// Sums GetFloat(0xfa1) for this tile and each linked tile whose GetFloat(0xfa8) is nonzero, returning the total.
// @fnv 0x00a013d0
float FUN_00a013d0_shell::GetTotalFloat()
{
    float fTotal = reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa1);
    Tile* ptile = ((Tile*)this)->m_pParent;
    while (ptile)
    {
        if (reinterpret_cast<::TileListBoxCalls *>((ptile))->GetFloat(0xfa8) != 0.0)
        {
            fTotal += reinterpret_cast<::TileListBoxCalls *>((ptile))->GetFloat(0xfa1);
        }
        ptile = ((Tile*)ptile)->m_pParent;
    }
    return fTotal;
}

struct FUN_00a01440_shell : public Tile {
    float GetAccumulatedFloat();
};


// Sums GetFloat(0xfa2) over this tile and its 0x28-linked chain, adding each linked tile's 0xfa2 when its 0xfa8 differs from gModifierZero.
// @fnv 0x00a01440
float FUN_00a01440_shell::GetAccumulatedFloat()
{
    float fTotal = reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa2);
    Tile* ptile = ((Tile*)this)->m_pParent;
    while (ptile != 0)
    {
        if (reinterpret_cast<::TileListBoxCalls *>((ptile))->GetFloat(0xfa8) != ::_DAT_01012060)
        {
            fTotal = reinterpret_cast<::TileListBoxCalls *>((ptile))->GetFloat(0xfa2) + fTotal;
        }
        ptile = ((Tile*)ptile)->m_pParent;
    }
    return fTotal;
}


// Copies characters before '(' into text and characters inside parentheses into apParam, then passes text to FUN_00a01860 and returns its result.
// @fnv 0x00a018d0
int __cdecl ParseTextAndParams(const char* apText, char* apParam)
{
    if (!apText || !*apText || !apParam)
        return 0x80000000;

    int iParamIndex = -1;
    char text[256];
    *apParam = 0;
    text[0] = 0;

    for (int a = 0; a < 0xff && apText[a]; ++a)
    {
        apParam[a + 1] = 0;
        text[a + 1] = 0;
        if (apText[a] == '(')
        {
            iParamIndex = 0;
        }
        else if (apText[a] == ')')
        {
            a = 0x100;
        }
        else if (iParamIndex >= 0)
        {
            apParam[iParamIndex] = apText[a];
            ++iParamIndex;
        }
        else
        {
            text[a] = apText[a];
        }
    }

    return FUN_00a01860(text);
}


// Finds the last '_' in apTraitName and returns FUN_00eca6d3 of the text after it, -1 if that text is empty, or 0 if there is no '_'.
// @fnv 0x00a01a20
int __cdecl FUN_00a01a20(const char* apTraitName)
{
    const char* plast_ = strrchr(apTraitName, '_');
    if (plast_) {
        return *(plast_ + 1) ? std::atoi(plast_ + 1) : -1;
    } else {
        return 0;
    }
}


// @fnv 0x00a044f0
void __cdecl FUN_00a044f0()
{
    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&::DAT_011f3330));
}

namespace fnv_00a04500 {
extern void (* const __imp__LeaveCriticalSection)(_RTL_CRITICAL_SECTION *);

// @fnv 0x00a04500
void __cdecl FUN_00a04500()
{
    __imp__LeaveCriticalSection(&(*reinterpret_cast<::_RTL_CRITICAL_SECTION *>(&::DAT_011f3330)));
}
}  // namespace fnv_00a04500

struct FUN_00a074d0_shell : public Tile {
    void FUN_00a074d0(int);
};


// @fnv 0x00a074d0
void FUN_00a074d0_shell::FUN_00a074d0(int aiFlag)
{
    if ((unsigned int)aiFlag > 0x3ff) {
        return;
    }
    unsigned int iold = ((Tile*)this)->m_uiFlags;
    ((Tile*)this)->m_uiFlags &= 0xfffffc00;
    ((Tile*)this)->m_uiFlags |= aiFlag;
    if (((Tile*)this)->m_uiFlags != iold) {
        ::FUN_00a07690((::FlaggedTile *)(::Tile *)(this));
    }
}

struct FUN_00a07530_shell : public Tile {
    void FUN_00a07530(int);
};


// ORs aiFlag into the flags at offset 0x30 when aiFlag is at most 0x3ff, and calls FUN_00a07690 if the flags changed.
// @fnv 0x00a07530
void FUN_00a07530_shell::FUN_00a07530(int aiFlag)
{
    if ((unsigned int)aiFlag > 0x3ff)
        return;
    unsigned int iold = ((Tile*)this)->m_uiFlags;
    ((Tile*)this)->m_uiFlags |= aiFlag;
    if (((Tile*)this)->m_uiFlags != iold)
        ::FUN_00a07690((::FlaggedTile *)(::Tile *)(this));
}

struct FUN_00a07ed0_shell : public Tile {
    bool FUN_00a07ed0(int);
};

struct FadeControlItem {
    char pad[0x10];
    int m_iValueId;
    Tile* pTile;
};

struct FadeControlNode {
    FadeControlItem* m_item;
    FadeControlNode* m_pkNext;
};


// Walks the DAT_011f3348 fade-control list and returns true if an item matches aiTrait and points to this tile.
// @fnv 0x00a07ed0
bool FUN_00a07ed0_shell::FUN_00a07ed0(int aiTrait)
{
    for (FadeControlNode* pfade = &(*reinterpret_cast<::FadeControlNode *>(&::fnv_00a00a30::DAT_011f3348)); pfade && pfade->m_item; pfade = pfade->m_pkNext) {
        if (pfade->m_item->m_iValueId == aiTrait && pfade->m_item->pTile == this) {
            return true;
        }
    }
    return false;
}

namespace fnv_00a07f30 {
struct FUN_00a07f30_shell : public Tile {
    float GetTraitFloat(int);
};

struct FadeItem_00a07f30 {
    int pad0;
    float m_fAlpha;
    int pad8;
    int padC;
    int m_iValueId;
    Tile* pTile;
};

struct FadeNode_00a07f30 {
    FadeItem_00a07f30* m_item;
    FadeNode_00a07f30* m_pkNext;
};


// @fnv 0x00a07f30
float FUN_00a07f30_shell::GetTraitFloat(int aiTrait)
{
    int iendValue = -1;
    for (FadeNode_00a07f30* pfade = &(*reinterpret_cast<::fnv_00a07f30::FadeNode_00a07f30 *>(&::fnv_00a00a30::DAT_011f3348)); pfade && pfade->m_item; pfade = pfade->m_pkNext) {
        if (pfade->m_item->m_iValueId == aiTrait && pfade->m_item->pTile == this) {
            iendValue = pfade->m_item->m_fAlpha;
        }
    }
    return iendValue == -1.0 ? reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(aiTrait) : iendValue;
}
}  // namespace fnv_00a07f30

namespace fnv_00a07fc0 {
struct FUN_00a07fc0_shell : public Tile {
    bool FUN_00a07fc0(int);
};


struct FadeControlDummy {
    float fStart;             // +0x00
    float m_fEndValue;               // +0x04
    unsigned int m_uiState; // +0x08
    float fDuration;          // +0x0c
    int m_iValueId;               // +0x10
    Tile* pTile;              // +0x14
    int iType;                // +0x18
};

struct FadeListDummy {
    FadeControlDummy* m_item;
    FadeListDummy* m_pkNext;
};


// @fnv 0x00a07fc0
bool FUN_00a07fc0_shell::FUN_00a07fc0(int aiTrait)
{
    for (FadeListDummy* pfade = &(*reinterpret_cast<::fnv_00a07fc0::FadeListDummy *>(&::fnv_00a00a30::DAT_011f3348)); pfade && pfade->m_item; pfade = pfade->m_pkNext)
    {
        if (pfade->m_item->m_iValueId == aiTrait && pfade->m_item->pTile == this)
        {
            if (pfade->m_item->iType != 1)
            {
                unsigned int now = GetTickCount();
                return ((float)(now - pfade->m_item->m_uiState) / pfade->m_item->fDuration >= 1.0) ? true : false;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
}  // namespace fnv_00a07fc0

struct NiNode;
struct TileX {
    char pad[0x28];
    TileX* pParent;
    NiNode* m_pRenderedNodeEntry;
    NiNode* GetNiNode();
};
// Walks up the parent chain until a tile with a non-null NiNode is found and returns that NiNode, or null if none exists.
// @fnv 0x00a089c0
NiNode* TileX::GetNiNode()
{
    TileX* ptile = this;
    NiNode* m;
    while (ptile && (m = ptile->m_pRenderedNodeEntry, !m)) {
        ptile = ptile->pParent;
    }
    if (ptile) {
        NiNode* a = ptile->m_pRenderedNodeEntry;
        if (a) {
            NiNode* b = ptile->m_pRenderedNodeEntry;
            return b;
        }
    }
    return 0;
}

struct FUN_00a0a0b0_shell : public Tile {
    void* FUN_00a0a0b0(int, int);
};


struct MemoryManager {
    void Deallocate(void*);
};
struct Tile3DStub {
    Tile3DStub* FUN_00a0bde0(unsigned int flags);
};
// Calls FUN_00a20650, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00a0bde0
Tile3DStub* Tile3DStub::FUN_00a0bde0(unsigned int flags)
{
    reinterpret_cast<::FUN_00a20650_cls *>(this)->FUN_00a20650_cls::~FUN_00a20650_cls();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(this);
    return this;
}

namespace fnv_00a0be10 {
struct MenuValueDescriptor {
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiValueId;
    char* m_pName;
};
struct FUN_00a0be10_shell : public MenuValueDescriptor {
    void FUN_00a0be10();
};

struct MemoryManager {  };
struct XMLStorageX : public MenuValueDescriptor {
    MenuValueDescriptor* FUN_00a0be10(unsigned int flags);
};
// @fnv 0x00a0be10
MenuValueDescriptor* XMLStorageX::FUN_00a0be10(unsigned int flags)
{
    if (m_pName) {
        char* p = m_pName;
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a0be10::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(p);
    }
    m_pName = 0;
    if (flags & 1) {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a0be10::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}
}  // namespace fnv_00a0be10

struct TV { bool IsVisible(); };
struct XL { void* head; void* RemovePos(void*&); };
// Iterates the tile list, and for each visible tile clears flags 0x800 and 0x1000, calls FUN_00a07690, and removes it from the list.
// @fnv 0x00a078e0
void FUN_00a078e0()
{
    void* xelem = (*reinterpret_cast<::XL *>(&::DAT_011f3324)).head;
    while (xelem) {
        Tile* ptile = (Tile*)((DListNodeView*)xelem)->m_pItem;
        char pad[0x20];
        if (((TV*)ptile)->IsVisible()) {
            0 ? (((Tile*)ptile)->m_uiFlags |= 0x800) : (((Tile*)ptile)->m_uiFlags &= ~0x800);
            0 ? (((Tile*)ptile)->m_uiFlags |= 0x1000) : (((Tile*)ptile)->m_uiFlags &= ~0x1000);
            ::FUN_00a07690((::FlaggedTile *)(ptile));
            (*reinterpret_cast<::XL *>(&::DAT_011f3324)).RemovePos(xelem);
        } else {
            xelem = xelem ? *(void**)xelem : 0;
        }
    }
}

struct FUN_00a079d0_shell : public Tile {
    void UpdateTileChildren();
};

struct ListNode_00a079d0 {
    ListNode_00a079d0* next;
    void* prev;
    Tile* item;
};

// Walks the linked list at this+4 and, for each Tile, calls FUN_00a07530(0x80) if IsTraitNonZero(0xfa6) is true, otherwise recurses into UpdateTileChildren.
// @fnv 0x00a079d0
void FUN_00a079d0_shell::UpdateTileChildren()
{
    ListNode_00a079d0* kPos;
    Tile* pitem;
    {
        ListNode_00a079d0* head = *(ListNode_00a079d0**)(&((Tile*)this)->m_kChildren);
        kPos = head;
    }
    while (kPos) {
        Tile** xelem = &kPos->item;
        kPos = kPos->next;
        pitem = *xelem;
        if (((FUN_00a01230_shell*)pitem)->IsTraitNonZero(0xfa6))
            ((FUN_00a07530_shell*)pitem)->FUN_00a07530(0x80);
        else
            ((FUN_00a079d0_shell*)pitem)->UpdateTileChildren();
    }
}

namespace fnv_00a0a270 {
struct MemoryManager {  };
struct VX { char pad[8]; float fValue; void* ptr; void RemoveFromReactions();  };
struct BW { bool v; };
struct FW { float f; };
// Stores afValue.f into fValue, frees ptr if set, optionally calls RemoveFromReactions, then calls FUN_00a09410 with whether the value changed or ptr was non-null.
// @fnv 0x00a0a270
void FUN_00a0a270(VX* self, FW afValue, BW abClearActions)
{
    bool bforceUpdate = self->fValue != afValue.f || self->ptr != 0;
    self->fValue = afValue.f;
    if (self->ptr) {
        void* p = self->ptr;
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a0a270::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(p);
        self->ptr = 0;
    }
    if (abClearActions.v)
        self->RemoveFromReactions();
    reinterpret_cast<::fnv_00a09410::EvalValue *>((self))->FUN_00a09410(bforceUpdate);
}
}  // namespace fnv_00a0a270

struct FUN_009ff600_shell : public Tile {
    void InitTile(Tile*, char*, Tile*);
};

struct StrMem;
struct NP_0081c630 { NP_0081c630& operator=(void*); };
struct TileStandIn_009ff600 {  };

// @fnv 0x009ff600
void FUN_009ff600_shell::InitTile(Tile* apParent, char* apName, Tile* apReplacedTile)
{
    ((Tile*)this)->m_pParent = 0;
    ((NP_0081c630*)&this->m_spNode)->operator=(0);
    {
        int aiPad1[10];
        StrMem* pName = (StrMem*)&this->m_kName;
        reinterpret_cast<::TextString *>((pName))->FUN_004037f0("", 0);
    }
    *((char*)&this->m_bSpeechChallengeFailure) = 0;
    ((Tile*)this)->m_uiFlags = 0;
    if (apParent)
        reinterpret_cast<::FUN_00a087d0_shell *>((((TileStandIn_009ff600*)this)))->FUN_00a087d0(apParent, apReplacedTile);
    if (apName)
    {
        int aiPad1[8];
        StrMem* pName = (StrMem*)&this->m_kName;
        reinterpret_cast<::TextString *>((pName))->FUN_004037f0(apName, 0);
    }
}

struct FUN_00a00e90_shell : public Tile {
    void* FindTraitValue(int);
};

// @fnv 0x00a00e90
void* FUN_00a00e90_shell::FindTraitValue(int aiTrait)
{
 unsigned int uiIndex;
 {
 Tile::Value* pFoundValue;
 {
 unsigned int uiSizeA;
 {
 unsigned int uiSizeB;
    pFoundValue = 0;
    uiIndex = 0;
    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&::DAT_011f3330));
    while ((uiSizeA = ((Tile*)this)->m_kValues.m_uiSize, uiIndex < uiSizeA)
           && ((Tile::Value**)((Tile*)this)->m_kValues.m_ppData)[uiIndex]->m_iValueId < aiTrait)
        uiIndex++;
    if ((uiSizeB = ((Tile*)this)->m_kValues.m_uiSize, uiIndex < uiSizeB)
        && ((Tile::Value**)((Tile*)this)->m_kValues.m_ppData)[uiIndex]->m_iValueId == aiTrait)
        pFoundValue = ((Tile::Value**)((Tile*)this)->m_kValues.m_ppData)[uiIndex];
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&::DAT_011f3330));
    return pFoundValue;
 }
 }
 }
}

namespace fnv_00a01000 {
struct FUN_00a01000_shell : public Tile {
    void* GetOrCreateTraitValue(int);
};

struct MemoryManager {  };
struct P09Value { int m_uiSoundID; void* pParent; float fValue; void* p0c; void* p10; };
void __cdecl FUN_00fda2a0();
struct P09Traits {
    unsigned int BinarySearch(P09Value*&, int (__cdecl*)(const void*, const void*));
    void InsertInSortedOrder(P09Value*&, int (__cdecl*)(const void*, const void*));
};
extern int DAT_011f338c;
extern void* DAT_011f3390;
extern float DAT_011f3394;
extern void* DAT_011f3398;
extern void* DAT_011f339c;
extern unsigned int DAT_011f33a0;
// Looks up a P09Value by aiTrait in the map at this+0x10, allocating and inserting a new one if absent, under a critical section.
// @fnv 0x00a01000
void* FUN_00a01000_shell::GetOrCreateTraitValue(int aiTrait)
{
    P09Value* preturnVal = 0;
    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&::DAT_011f3330));
    if (!(DAT_011f33a0 & 1)) {
        DAT_011f33a0 |= 1;
        DAT_011f338c = 0x80000000;
        DAT_011f3390 = 0;
        DAT_011f3394 = 0.0f;
        DAT_011f3398 = 0;
        DAT_011f339c = 0;
        std::atexit(FUN_00fda2a0);
    }
    unsigned int uifoundIndex = (unsigned int)-1;
    DAT_011f338c = aiTrait;
    {
        P09Value* pSearchKey = (P09Value*)&DAT_011f338c;
        uifoundIndex = ((P09Traits*)&this->m_kValues)->BinarySearch(pSearchKey, ((int (&)(const void *, const void *))::FUN_00a01160));
    }
    if (uifoundIndex != (unsigned int)-1) {
        preturnVal = ((P09Value**)((Tile*)this)->m_kValues.m_ppData)[uifoundIndex];
    } else {
        P09Value* pNew = (P09Value*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00a01000::MemoryManager *>(&::g_memoryManager))))->FUN_00aa3e40(0x14);
        P09Value* pInitValue = pNew ? (pNew->m_uiSoundID = 0x80000000, pNew->pParent = 0, pNew->fValue = 0.0f,
            pNew->p0c = 0, pNew->p10 = 0, pNew) : 0;
        preturnVal = pInitValue;
        preturnVal->m_uiSoundID = aiTrait;
        preturnVal->pParent = this;
        ((P09Traits*)&this->m_kValues)->InsertInSortedOrder(preturnVal, ((int (&)(const void *, const void *))::FUN_00a01160));
    }
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&::DAT_011f3330));
    return preturnVal;
}
}  // namespace fnv_00a01000

struct FUN_00a031b0_shell : public Tile {
    Tile* CreateMenuTiles(void*);
};

struct P09Item { int eType; float fValue; void* pName; int i0c; Tile* pTile; };
struct P09VTile { virtual void f0(); virtual void Init(Tile*, void*, int); };
struct P09TileS {   };
struct P09Setting { void* pVtbl; const char* volatile pValue; };
extern double DAT_01094a80;
// @fnv 0x00a031b0
Tile* FUN_00a031b0_shell::CreateMenuTiles(void* apTemplate)
{
 Tile* pfirst_tile;
 {
 P09Item* pitem;
 {
 char* xelem;
 {
 Tile* pparent;
 {
 Tile* ptile;
    pparent = this;
    pfirst_tile = 0;
    {
        char* pHead = (char*)((TileTemplateView*)apTemplate)->m_pItemHead;
        xelem = pHead;
    }
    pitem = 0;
    while (xelem) {
        {
            P09Item** ppData = (P09Item**)&((DListNodeView*)xelem)->m_pItem;
            xelem = *(char**)xelem;
            pitem = *ppData;
        }
        if (pitem->eType == 6) {
            ptile = ::fnv_00a00c20::FUN_00a00c20((int)pitem->fValue);
            if (!ptile) {
                ::FUN_005b5e40();
                return 0;
            }
            {
                void* pName = pitem->pName;
                ((P09VTile*)ptile)->Init(pparent, pName, 0);
            }
            if (pitem->fValue == DAT_01094a80) {
                reinterpret_cast<::FUN_00a012d0_t *>((ptile))->FUN_00a012d0(0xfaa, -1.0f, true);
                reinterpret_cast<::FUN_00a012d0_t *>((ptile))->FUN_00a012d0(0xfaf, 1.0f, true);
                reinterpret_cast<::FUN_00a012d0_t *>((ptile))->FUN_00a012d0(0xff5, -1.0f, true);
                reinterpret_cast<::FUN_00a012d0_t *>((ptile))->FUN_00a012d0(0xfb2, 255.0f, true);
                reinterpret_cast<::FUN_00a012d0_t *>((ptile))->FUN_00a012d0(0xfb3, 255.0f, true);
                reinterpret_cast<::FUN_00a012d0_t *>((ptile))->FUN_00a012d0(0xfb4, 255.0f, true);
                reinterpret_cast<::FUN_00a012d0_t *>((ptile))->FUN_00a012d0(0xfa9, 0.0f, true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((P09TileS*)ptile)))->FUN_00a01350(0xfcc, (char *)("solid.dds"), true);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((P09TileS*)ptile)))->FUN_00a01350(0xff9, (char *)(&(*reinterpret_cast<::P09Setting *>(&::g_011f3368)) ? (*reinterpret_cast<::P09Setting *>(&::g_011f3368)).pValue : 0), true);
                reinterpret_cast<::FUN_00a07530_shell *>((((P09TileS*)ptile)))->FUN_00a07530(0x20);
            }
            if (!pfirst_tile)
                pfirst_tile = ptile;
            pitem->pTile = ptile;
            pparent = ptile;
        } else if (pitem->eType == 7) {
            pparent = ((Tile*)pparent)->m_pParent;
        }
    }
    return pfirst_tile;
 }
 }
 }
 }
}

struct EmptyPolymorphicObject {
    void* __vecDelDtor(unsigned int);
    char _pad_0[1];
};
struct FUN_00a03d40_shell : public Tile {
    Tile* FUN_00a03d40();
};

void __cdecl FUN_00a044f0();
namespace fnv_00a04500 { void __cdecl FUN_00a04500(); }

// @fnv 0x00a03d40
Tile* FUN_00a03d40_shell::FUN_00a03d40()
{
    FUN_00a044f0();
    Tile* ptile = this;
    EmptyPolymorphicObject lock;
    Tile* r;
    {
        Tile* a;
        Tile* b;
        Tile* c;
        while (ptile && (a = ((Tile*)ptile)->m_pParent) != 0
               && (c = ((Tile*)(b = ((Tile*)ptile)->m_pParent))->m_pParent) != 0)
            ptile = ((Tile*)ptile)->m_pParent;
    }
    r = ptile;
    fnv_00a04500::FUN_00a04500();
    return r;
}

namespace fnv_00a077c0 {
struct NiTPointerListBase_00a077c0 { int iVal; void* AddHead(); };
extern NiTPointerListBase_00a077c0 DAT_011f332c;
struct FUN_004ed8c0_shell_00a077c0 {  };
extern void** DAT_011f3328;

// If apTile is valid, lacks flag 0x800 and is not the excluded list entry, adds it to DAT_011f332c, increments DAT_011f32d8, sets flag 0x800 and clears 0x1000.
// @fnv 0x00a077c0
void FUN_00a077c0(Tile* apTile)
{
    void* pNode;
    {
    int iUnused;
    {
    Tile* pTile1;
    {
    Tile* pTile2;
    {
    unsigned int uiFlags1;
    {
    unsigned int uiFlags2;
    if (apTile && !(bool)(int)((((Tile*)apTile)->m_uiFlags & 0x800) != 0)
        && ((bool)(int)(DAT_011f332c.iVal == 0) || apTile != DAT_011f3328[2]))
    {
        ::DAT_011f32d8++;
        pNode = ((void *)(reinterpret_cast<::FUN_0043a010_shell *>(&(DAT_011f332c))->FUN_0043a010()));
        ((DListNodeView*)pNode)->m_pItem = apTile;
        reinterpret_cast<::FUN_00559a70_Class *>(&((*reinterpret_cast<::fnv_00a077c0::FUN_004ed8c0_shell_00a077c0 *>(&::DAT_011f3324))))->FUN_00559a70(pNode);
        pTile1 = apTile;
        if (1)
        {
            ((Tile*)pTile1)->m_uiFlags |= 0x800;
            uiFlags1 = ((Tile*)pTile1)->m_uiFlags;
        }
        else
        {
            ((Tile*)pTile1)->m_uiFlags &= ~0x800;
            uiFlags1 = ((Tile*)pTile1)->m_uiFlags;
        }
        pTile2 = apTile;
        if (0)
        {
            ((Tile*)pTile2)->m_uiFlags |= 0x1000;
            uiFlags2 = ((Tile*)pTile2)->m_uiFlags;
        }
        else
        {
            ((Tile*)pTile2)->m_uiFlags &= ~0x1000;
            uiFlags2 = ((Tile*)pTile2)->m_uiFlags;
        }
    }
    }
    }
    }
    }
    }
}
}  // namespace fnv_00a077c0

namespace fnv_00a07c60 {
struct FUN_00a07c60_shell : public Tile {
    void StartFade(int, float, float, float, int);
};

struct MemoryManager {  };
struct P09Fade { float fStart; float m_fEndValue; unsigned long m_uiState; float fScaleMultiplier; int m_iValueId; Tile* pTile; int eType; };
struct FUN_00a0c7c0_Helper {  };
struct P09TileFade { void UpdateTrait(int); };
// Starts a fade on this tile: allocates a P09Fade, fills start/end/length/type and tick, sets flash traits for types 2 and 3, then queues it via DAT_011f3348.
// @fnv 0x00a07c60
void FUN_00a07c60_shell::StartFade(int aiTrait, float afStart, float afEnd, float afLength, int aeFadeType)
{
    P09Fade* pFade;
    if (afStart != afEnd && afLength > ::_DAT_01012060) {
        float ftotalFlashes;
        ((P09TileFade*)this)->UpdateTrait(aiTrait);
        {
            void* pMem = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00a07c60::MemoryManager *>(&::g_memoryManager))))->FUN_00aa3e40(0x1c);
            pFade = (P09Fade*)pMem;
        }
        pFade->pTile = this;
        pFade->m_iValueId = aiTrait;
        pFade->fStart = afStart;
        pFade->m_fEndValue = afEnd;
        pFade->fScaleMultiplier = afLength * 1000.0;
        {
            unsigned long ulFadeStartTimeTick = GetTickCount();
            pFade->m_uiState = ulFadeStartTimeTick;
        }
        pFade->eType = aeFadeType;
        if (aeFadeType == 3) {
            ftotalFlashes = afLength / ::DAT_01011588;
            int iFlash = ::FUN_00a00940("_FlashCount", -1);
            reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(iFlash, 0.0f, true);
            reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(::FUN_00a00940("_TotalFlashCount", -1), ftotalFlashes - 2.0, true);
            pFade->fScaleMultiplier = afLength / ftotalFlashes * 1000.0;
        }
        if (aeFadeType == 2) {
            int iFlash2 = ::FUN_00a00940("_FlashCount", -1);
            reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(iFlash2, 0.0f, true);
        }
        reinterpret_cast<::S_00a0c7c0_List *>(&((*reinterpret_cast<::fnv_00a07c60::FUN_00a0c7c0_Helper *>(&::fnv_00a00a30::DAT_011f3348))))->AddToHead((void **)(::fnv_00a07c60::P09Fade **)(&pFade));
        {
            int iPad0, iPad1, iPad2;
        }
    }
}
}  // namespace fnv_00a07c60

namespace fnv_00a07dc0 {
struct FUN_00a07dc0_shell : public Tile {
    void RemoveFadeItemsForTile(int);
};

class MemoryManager { public:  };
struct P03FadeItem { char pad[0x10]; int m_iValueId; Tile* pTile; };
struct P03FadeNode { P03FadeItem* item; P03FadeNode* next; };
struct P03FadeList { P03FadeItem* item; P03FadeNode* next;  };
struct FUN_00a0c7c0_Helper {  };
struct FUN_00ae83e0 { P03FadeItem* item; P03FadeNode* next; ~FUN_00ae83e0(); };
// @fnv 0x00a07dc0
void FUN_00a07dc0_shell::RemoveFadeItemsForTile(int aiTrait)
{
    FUN_00ae83e0 ptoBeDeleted = { 0, 0 };
    P03FadeNode* removeList;
    P03FadeNode* pDel;
    P03FadeItem* pfade;
    void* premove;
    for (removeList = (P03FadeNode*)&(*reinterpret_cast<::fnv_00a07dc0::P03FadeList *>(&::fnv_00a00a30::DAT_011f3348)); removeList && removeList->item; removeList = removeList->next) {
        if ((removeList->item->m_iValueId == aiTrait || aiTrait == (int)0x80000000) && removeList->item->pTile == this)
            reinterpret_cast<::S_00a0c7c0_List *>((((FUN_00a0c7c0_Helper*)&ptoBeDeleted)))->AddToHead((void **)(::Tile__TileTemplate **)((Tile__TileTemplate**)removeList));
    }
    for (pDel = (P03FadeNode*)&ptoBeDeleted; pDel && pDel->item; pDel = pDel->next) {
        pfade = pDel->item;
        reinterpret_cast<::FadeList *>(&((*reinterpret_cast<::fnv_00a07dc0::P03FadeList *>(&::fnv_00a00a30::DAT_011f3348))))->FUN_00a0cbe0((*(::FadeRecord * *)(&pfade)));
        premove = pfade;
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a07dc0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(premove);
    }
    { struct P03Pad { int a[18]; } aiPad; }
    reinterpret_cast<::Node185 *>((((BSSimpleList<unsigned char*>*)&ptoBeDeleted)))->FUN_00ae83e0();
}
}  // namespace fnv_00a07dc0

struct P03Node { P03Node* next; P03Node* prev; Tile* data; };
// Recursively searches apTarget and its linked child tiles for one whose name matches apName case-insensitively, returning the match or null.
// @fnv 0x00a08f20
Tile* __cdecl FindTileByName(Tile* apTarget, const char* apName)
{
    Tile* xelem;
    P03Node* pitem;
    if (!apTarget)
        return 0;
    {
        const char* pTileName = apTarget->m_kName.m_pString;
        if (pTileName) {
            const char* pTileName2 = apTarget->m_kName.m_pString;
            if (!fnv::crt::stricmp(pTileName2, apName))
                return apTarget;
        }
    }
    {
        P03Node* pHead = (P03Node*)apTarget->m_kChildren.m_pHead;
        pitem = pHead;
    }
    while (pitem) {
        Tile** ppData = &pitem->data;
        pitem = pitem->next;
        xelem = FindTileByName(*ppData, apName);
        if (xelem)
            return xelem;
    }
    return 0;
}

extern void* DAT_01094c2c;
extern void* DAT_01094c38;
struct P03MM {  };
struct P03Value { void AppendFloatAction(int aiActionType, float afValue); };
// Allocates a Tile__FloatAction with the given action type and value, then appends it to the end of the action list at this+0x10 or sets it as the head.
// @fnv 0x00a09080
void P03Value::AppendFloatAction(int aiActionType, float afValue)
{
    Tile__Action* pNew = (Tile__Action*)((Tile::Value*)this)->pAction;
    Tile__FloatAction* pMem;
    void* ptail = reinterpret_cast<::MemoryManagerStandIn *>((((P03MM*)&g_memoryManager)))->FUN_00aa3e40(0x10);
    Tile__FloatAction* pnewAction = ptail ? (((Tile__Action*)ptail)->m_ppVirtualMethodTable = (void**)&DAT_01094c38,
        ((Tile__Action*)ptail)->eActionType = (Tile__VALUE_ACTION)2000,
        ((Tile__Action*)ptail)->m_pActionSuccessor = 0,
        ((Tile__Action*)ptail)->m_ppVirtualMethodTable = (void**)&DAT_01094c2c,
        (Tile__FloatAction*)ptail) : 0;
    pMem = pnewAction;
    pMem->eActionType = (Tile__VALUE_ACTION)aiActionType;
    pMem->fValue = afValue;
    if (pNew) {
        while (pNew->m_pActionSuccessor)
            pNew = pNew->m_pActionSuccessor;
        pNew->m_pActionSuccessor = pMem;
    } else {
        ((Tile::Value*)this)->pAction = pMem;
    }
}

namespace fnv_00a09200 {
struct MemoryManager_00a09200 {  };
struct Value_00a09200;
struct Reaction_00a09200 { Value_00a09200* pValue; Reaction_00a09200* pNext; };
struct Action_00a09200 {
    virtual void v0();
    virtual unsigned long GetRef();
    int iType;
    Action_00a09200* pNext;
};
struct BSMapBase_00a09200 {
    bool GetAt(unsigned long, Reaction_00a09200*&);
};
struct Value_00a09200 {
    void RemoveFromReactions();
};

// Walks the action list, removes this value from each referenced reaction list, updates or clears the map entry, and deletes the actions.
// @fnv 0x00a09200
void Value_00a09200::RemoveFromReactions()
{
    Action_00a09200* pcurrAction;
    {
    Action_00a09200** ppcurrAction;
    {
    Reaction_00a09200* preactionListA;
    {
    Reaction_00a09200* pcurrReaction;
    {
    Reaction_00a09200** ppcurrReaction;
    {
    Reaction_00a09200* pOriginalHead;
    {
    void* pDeletedReaction;
    {
    void* pDeletedAction;
    {
    int aiPad[8];
    {
    int iActionIndex;
    ppcurrAction = (Action_00a09200**)&((Tile::Value*)this)->pAction;
    while ((pcurrAction = *ppcurrAction) != 0)
    {
        if (pcurrAction->GetRef())
        {
            preactionListA = 0;
            if (reinterpret_cast<::S_00adc830_Map *>(&((*reinterpret_cast<::fnv_00a09200::BSMapBase_00a09200 *>(&::g_kA0A220Handlers))))->GetAt(pcurrAction->GetRef(), (::S_00adc830_Entry *&)(preactionListA)))
            {
                ppcurrReaction = &preactionListA;
                pOriginalHead = *ppcurrReaction;
                while ((pcurrReaction = *ppcurrReaction) != 0)
                {
                    if (pcurrReaction->pValue != this)
                    {
                        ppcurrReaction = &pcurrReaction->pNext;
                    }
                    else
                    {
                        *ppcurrReaction = pcurrReaction->pNext;
                        pDeletedReaction = pcurrReaction;
                        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a09200::MemoryManager_00a09200 *>(&::g_memoryManager))))->FUN_00aa4060(pDeletedReaction);
                    }
                }
                if (!preactionListA)
                    reinterpret_cast<::RMapBase *>(&((*reinterpret_cast<::fnv_00a09200::BSMapBase_00a09200 *>(&::g_kA0A220Handlers))))->FUN_00a1e240(pcurrAction->GetRef());
                else if (preactionListA != pOriginalHead)
                    reinterpret_cast<::FUN_00a0c6c0_cls *>(&((*reinterpret_cast<::fnv_00a09200::BSMapBase_00a09200 *>(&::g_kA0A220Handlers))))->InsertOrUpdate(pcurrAction->GetRef(), (::AnimSequenceBase *)(preactionListA));
            }
        }
        *ppcurrAction = pcurrAction->pNext;
        pDeletedAction = pcurrAction;
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a09200::MemoryManager_00a09200 *>(&::g_memoryManager))))->FUN_00aa4060(pDeletedAction);
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
}
}  // namespace fnv_00a09200

namespace fnv_00a0ab70 {
struct MemoryManager {  };
struct StrMem {  char pad[8]; };
struct SoundMessageRecord {
    char pad[8];
    StrMem str;
};
struct OH2List {
    SoundMessageRecord* RemoveHead();
    char pad[8];
    unsigned int count;
};
struct OH2TileTemplate {
    char pad[8];
    OH2List list;
    void ClearList();
};
// @fnv 0x00a0ab70
void OH2TileTemplate::ClearList()
{
    SoundMessageRecord* p;
    {
        SoundMessageRecord* pMsg;
        {
            unsigned int count;
            {
                int inl[13];
                while ((count = list.count) != 0) {
                    pMsg = ((::fnv_00a0ab70::SoundMessageRecord *)(reinterpret_cast<::SndStack70 *>(&(list))->FUN_00ae7f90()));
                    p = pMsg;
                    p ? (reinterpret_cast<::TextString *>(&(p->str))->FUN_004037f0(0, 0), (((0, 1) & 1) ? reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a0ab70::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(p) : (void)0), p) : 0;
                }
            }
        }
    }
}
}  // namespace fnv_00a0ab70

struct NiGlobalStringTable { static char* __cdecl AddString(const char*);
};
struct TileTemplate_00a0af10 { char* m_kName; };
struct TemplateList_00a0af10 { TileTemplate_00a0af10* pItem; TemplateList_00a0af10* pNext; };

struct BuildStorage_00a0af10
{
    void* m_pVtbl;
    TemplateList_00a0af10 m_kTemplates;
    TileTemplate_00a0af10* FindTemplateByName(const char* pName);
};

// Looks up a template in m_kTemplates by name, comparing interned strings, and returns the matching template or null.
// @fnv 0x00a0af10
TileTemplate_00a0af10* BuildStorage_00a0af10::FindTemplateByName(const char* pName)
{
    char* nm;
    {
    TemplateList_00a0af10* pNode;
    {
    TileTemplate_00a0af10* pResult;
    {
    TileTemplate_00a0af10* pZero;
    {
    char* pOther;
    {
    TileTemplate_00a0af10* pTemplate;
    {
    bool bEqual;
    {
    long* pRef1;
    {
    long* pRef2;
    pNode = &m_kTemplates;
    if (!pName)
        nm = ::DAT_0109b220;
    else
        nm = NiGlobalStringTable::AddString(pName);
    while (pNode && pNode->pItem)
    {
        pTemplate = pNode->pItem;
        pOther = pTemplate->m_kName;
        if (nm == pOther)
            bEqual = true;
        else if (!pOther || !nm)
            bEqual = false;
        else
            bEqual = std::strcmp(nm, pOther) == 0;
        if (bEqual)
        {
            pResult = pNode->pItem;
            if (nm == ::DAT_0109b220)
            {
            }
            else
            {
                pRef1 = &((StringHeader*)nm - 1)->refs;
                InterlockedDecrement(pRef1);
            }
            return pResult;
        }
        pNode = pNode->pNext;
    }
    pZero = 0;
    if (nm == ::DAT_0109b220)
    {
    }
    else
    {
        pRef2 = &((StringHeader*)nm - 1)->refs;
        InterlockedDecrement(pRef2);
    }
    return pZero;
    }
    }
    }
    }
    }
    }
    }
    }
}

struct RgbaColor;
struct NiNode;
struct NiStream;
struct NiTexture;
struct TileShaderProperty;
struct blob4 { char b[4]; };
struct FUN_00a0b280_shell : public Tile {
    void ApplyAlphaAndColorToChildren(NiNode*, float, void*);
};

struct PropHelper {  };
struct OH3Color { float r, g, b, a; };
struct OH3Child {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual PropHelper* v6();
};
// @fnv 0x00a0b280
void FUN_00a0b280_shell::ApplyAlphaAndColorToChildren(NiNode* apNode, float afAlpha, void* apColor)
{
    if (!apNode)
        return;
    for (unsigned int ui = 0; ui < ((NiNodeChildrenView*)apNode)->m_kChildren.m_usSize; ui++) {
        OH3Child* pchild;
        PropHelper* pgeom;
        {
            void* pprop;
            char* ptsp;
            {
                OH3Child** pa = &((OH3Child**)((NiNodeChildrenView*)apNode)->m_kChildren.m_ppBase)[ui];
                {
                    OH3Child* pv = *pa;
                    pchild = pv;
                }
            }
            pgeom = pchild ? pchild->v6() : 0;
            if (pgeom) {
                pprop = ((void *)(reinterpret_cast<::FUN_00a59d30_C *>((pgeom))->FUN_00a59d30(3)));
                ptsp = (char*)pprop;
                ((TileShaderPropertyView*)ptsp)->m_fAlpha = afAlpha;
                *(OH3Color*)((TileShaderPropertyView*)ptsp)->m_afColor = *(OH3Color*)apColor;
            }
        }
    }
}

struct FUN_00a00f30_shell : public Tile {
    void* FUN_00a00f30(int);
};
// Returns the float value of the tile's value for the given trait, or 0.0f if no such value exists.
// @fnv 0x00a011b0
float TileListBoxCalls::GetFloat(int trait)
{
    Tile::Value* value=((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile*)this)))->FUN_00a00f30(trait)));
    if (value) { float result=value->fValue; return result; }
    return 0.0f;
}
// @fnv 0x00a011f0
char* FUN_00a011f0_shell::FUN_00a011f0(int trait) {
    Tile::Value* pvalue = ((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>(this)->FUN_00a00f30(trait)));
    if (pvalue) {
        char* result = pvalue->pcValue;
        return result;
    }
    return 0;
}
// Looks up the Value for aeTrait and returns whether its fValue is non-zero, or false if no Value exists.
// @fnv 0x00a01230
bool FUN_00a01230_shell::IsTraitNonZero(int aeTrait)
{
    Value* pvalue = ((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>(this)->FUN_00a00f30(aeTrait)));
    if (pvalue)
    {
        float fval = pvalue->fValue;
        return fval != 0.0;
    }
    return false;
}
// Builds a value name from the base trait name and ID, then returns the value looked up by that name.
// @fnv 0x00a0a0b0
void* FUN_00a0a0b0_shell::FUN_00a0a0b0(int aiBaseTrait, int aiID)
{
    char strValueName[260];
    const char* strBaseName = ((const char *)(::FUN_00a01a70(aiBaseTrait)));
    ::FUN_00406d00(strValueName, sizeof(strValueName), "%s%d", strBaseName, aiID);
    return ((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>(this)->FUN_00a00f30(FUN_00a01860(strValueName))));
}

void __cdecl FUN_00fda290();
extern void (*DAT_00fdf05c)(void*);
extern void (*DAT_00fdf100)(void*);
extern unsigned int DAT_011f3388;
extern unsigned int DAT_011f3374;
extern int DAT_011f3378;
extern float DAT_011f337c;
extern int DAT_011f3380;
extern int DAT_011f3384;

template<> class BSSimpleArray<Tile::Value*,8> {
public:
    void** m_ppVirtualMethodTable; Tile::Value** pBuffer; unsigned int iSize; unsigned int SimpleArrayStorage;
    unsigned int BinarySearch(Tile::Value*&, int (__cdecl*)(const void*, const void*));
};

// Locks a global, stores aiTrait in it, looks up the matching Tile::Value in the array at offset 0x10 and returns it, or null if not found.
// @fnv 0x00a00f30
void* FUN_00a00f30_shell::FUN_00a00f30(int aiTrait)
{
    Tile::Value* preturnVal = 0;
    DAT_00fdf05c(&(*reinterpret_cast<int *>(&::DAT_011f3330)));
    if (!(DAT_011f3388 & 1)) {
        DAT_011f3388 |= 1;
        DAT_011f3374 = 0x80000000;
        DAT_011f3378 = 0;
        DAT_011f337c = 0.0f;
        DAT_011f3380 = 0;
        DAT_011f3384 = 0;
        std::atexit(FUN_00fda290);
    }
    unsigned int uifoundIndex = 0xffffffff;
    DAT_011f3374 = aiTrait;
    {
        Tile::Value* pkey = (Tile::Value*)&DAT_011f3374;
        uifoundIndex = ((BSSimpleArray<Tile::Value*,8>*)&((Tile*)this)->m_kValues)->BinarySearch(pkey, ((int (&)(const void *, const void *))::FUN_00a01160));
    }
    if (uifoundIndex != 0xffffffff)
        preturnVal = ((Tile::Value**)((Tile*)this)->m_kValues.m_ppData)[uifoundIndex];
    DAT_00fdf100(&(*reinterpret_cast<int *>(&::DAT_011f3330)));
    return preturnVal;
}

namespace fnv_00a09330 {
class MemoryManager { public:  };
struct ScrapHeapBuffer;
template<class K, class V> struct BSMapBase {
    bool GetAt(K, V&);
    void FUN_00a1e240(K);
};
struct Action_00a09330 {
    virtual void v0();
    virtual void* GetValue();
    int pad4;
    Action_00a09330* pNext;
    void* pValue;
};
struct Reaction_00a09330 { char pad[0x10]; Action_00a09330* pActions; };
struct Node_00a09330 { Reaction_00a09330* pData; Node_00a09330* pNext; };
struct FUN_00a09330_shell {
    int m_iValueId;
    int iVal4;
    float fValue;
    void* pBuf;
    void ClearActionsAndFreeBuffer();
};
// Calls RemoveFromReactions, clears matching action values and frees the preaction list nodes, then frees pBuf and resets fValue and iVal4.
// @fnv 0x00a09330
void FUN_00a09330_shell::ClearActionsAndFreeBuffer()
{
    Node_00a09330* preactionListA = 0;
    reinterpret_cast<::fnv_00a09200::Value_00a09200 *>(this)->RemoveFromReactions();
    if (reinterpret_cast<::S_00adc830_Map *>(&((*reinterpret_cast<::fnv_00a09330::BSMapBase<unsigned long, ::fnv_00a09330::ScrapHeapBuffer *> *>(&::g_kA0A220Handlers))))->GetAt((unsigned long)this, (::S_00adc830_Entry *&)((ScrapHeapBuffer*&)preactionListA))) {
        while (preactionListA) {
            Action_00a09330* pcurrAction = preactionListA->pData->pActions;
            while (pcurrAction) {
                if (pcurrAction->GetValue() == this)
                    pcurrAction->pValue = 0;
                pcurrAction = pcurrAction->pNext;
            }
            Node_00a09330* premove = preactionListA;
            preactionListA = preactionListA->pNext;
            {
                void* pMem = premove;
                reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a09330::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(pMem);
            }
        }
        reinterpret_cast<::RMapBase *>(&((*reinterpret_cast<::fnv_00a09330::BSMapBase<unsigned long, ::fnv_00a09330::ScrapHeapBuffer *> *>(&::g_kA0A220Handlers))))->FUN_00a1e240((unsigned long)this);
    }
    if (pBuf) {
        void* pMem = pBuf;
        int unused[6];
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a09330::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(pMem);
    }
    fValue = 0.0f;
    iVal4 = 0;
}
}  // namespace fnv_00a09330

template<> class NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*> { public: void* AddHead(); };
struct NiTMapItem_00a0c900 { NiTMapItem_00a0c900* m_pkNext; const char* m_key; std::uintptr_t m_val; };
struct FUN_00a0c900_shell {
    virtual void v0();
    virtual unsigned int KeyToHashIndex(const char*);
    virtual bool IsKeysEqual(const char*, const char*);
    virtual void SetValue(NiTMapItem_00a0c900*, const char*, std::uintptr_t);
    unsigned int m_uiHashSize;
    NiTMapItem_00a0c900** m_ppkHashTable;
    unsigned int m_uiCount;
    bool m_bCopy;
    void FUN_00a0c900(const char* pcKey, std::uintptr_t val);
};
// @fnv 0x00a0c900
void FUN_00a0c900_shell::FUN_00a0c900(const char* pcKey, std::uintptr_t val)
{
    unsigned int uiIndex = KeyToHashIndex(pcKey);
    NiTMapItem_00a0c900* pkItem = m_ppkHashTable[uiIndex];
    unsigned int uiDepth = 0;
    while (pkItem) {
        uiDepth++;
        if (IsKeysEqual(pcKey, pkItem->m_key)) {
            int unused[7];
            if (!m_bCopy)
                pkItem->m_key = pcKey;
            pkItem->m_val = val;
            return;
        }
        pkItem = pkItem->m_pkNext;
    }
    pkItem = (NiTMapItem_00a0c900*)((void *)(reinterpret_cast<::FUN_0043a010_shell *>((((NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*>*)&m_uiCount)))->FUN_0043a010()));
    SetValue(pkItem, pcKey, val);
    pkItem->m_pkNext = m_ppkHashTable[uiIndex];
    m_ppkHashTable[uiIndex] = pkItem;
    m_uiCount++;
}

struct FUN_007000b0_shell {
    void FUN_007000b0();
};
struct FUN_007000d0_shell {
    void FUN_007000d0();
};
struct FUN_007000f0_shell {
    char pad00[0x28];
    unsigned char m_ucFlags;
    bool HasFlag(int mask);
};
// @fnv 0x007000b0
void FUN_007000b0_shell::FUN_007000b0()
{
    reinterpret_cast<::FUN_007000f0_shell *>(this)->HasFlag(1);
}
// @fnv 0x007000d0
void FUN_007000d0_shell::FUN_007000d0()
{
    reinterpret_cast<::FUN_007000f0_shell *>(this)->HasFlag(2);
}
// @fnv 0x007000f0
bool FUN_007000f0_shell::HasFlag(int mask)
{
    return (m_ucFlags & mask) != 0;
}

struct VATSMenu {
    char pad00[0xc];
    Tile* m_pTile;
    int FUN_007267c0();
};

// @fnv 0x007267c0
int VATSMenu::FUN_007267c0()
{
    static int iNumFilteredTrait = ::FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>(m_pTile)->GetFloat(iNumFilteredTrait);
}

// @fnv 0x00a01160
int __cdecl FUN_00a01160(int** pFirst, int** pSecond)
{
    int** pa = pFirst;
    int** pb = pSecond;
    if (**pa < **pb)
        return -1;
    if (**pa > **pb)
        return 1;
    return 0;
}


struct FUN_00a0baf0_class {
    void FUN_00a0baf0();
};

// @fnv 0x00a0baf0
void FUN_00a0baf0_class::FUN_00a0baf0()
{
    ::fnv_00a04500::FUN_00a04500();
}

struct TileText {
    const char* FUN_00a0bbe0();
};

// @fnv 0x00a0bbe0
const char* TileText::FUN_00a0bbe0()
{
    return "TEXT";
}

struct Tile3D
{
    virtual ~Tile3D();
    const char* FUN_00a0bdd0();
};

// @fnv 0x00a0bdd0
const char* Tile3D::FUN_00a0bdd0()
{
    return "3DAN";
}

struct FUN_00a0c060_shell {
    char pad00[0xc];
    int m_i0c;
    int GetField0C();
};
// @fnv 0x00a0c060
int FUN_00a0c060_shell::GetField0C()
{
    return m_i0c;
}

struct FUN_00a0c080_shell {
    const char* GetArg1String();
};
// @fnv 0x00a0c080
const char* FUN_00a0c080_shell::GetArg1String()
{
    return (*reinterpret_cast<const char (*)[]>(&::g_011f4a80));
}


struct FUN_00a0c090_Class {
    void* FUN_00a0c090(unsigned int flags);
};

// Calls FUN_00a0abe0, then if bit 0 of flags is set calls __Dummy_00b6fef0 with this and 0x14, and returns this.
// @fnv 0x00a0c090
void* FUN_00a0c090_Class::FUN_00a0c090(unsigned int flags)
{
    reinterpret_cast<::FUN_00a0abe0 *>((this))->FUN_00a0abe0::~FUN_00a0abe0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}

struct FUN_00a0d260_Class {
    int m_iWordAt00;
    int m_iWordAt04;
    unsigned int Modulo(unsigned int param);
};

// @fnv 0x00a0d260
unsigned int FUN_00a0d260_Class::Modulo(unsigned int auiValue) {
    return auiValue % m_iWordAt04;
}

struct FUN_00a04100_shell {
    int unk[10];
    Tile* pTile;
    bool FUN_00a04100();
};
// Walks the Tile chain via offset 0x28, checking GetFloat(0xfaa) against 110.0, and always returns false.
// @fnv 0x00a04100
bool FUN_00a04100_shell::FUN_00a04100()
{
    Tile* t = pTile;
    while (t) {
        if (reinterpret_cast<::TileListBoxCalls *>((t))->GetFloat(0xfaa) == 110.0)
            t = ((Tile*)t)->m_pParent;
    }
    return false;
}


struct NiTMapItem_ {
    char const* m_key;
    int m_uiFilterValue;
};

struct NiTStringTemplateMap_ {
    void* m_map;
    char pad[12];
    bool m_bCopy;
    void FUN_00a0d4a0(NiTMapItem_* pkItem);
};

// @fnv 0x00a0d4a0
void NiTStringTemplateMap_::FUN_00a0d4a0(NiTMapItem_* pkItem)
{
    if (m_bCopy)
        ::FUN_00aa10f0((void*)(pkItem->m_uiFilterValue));
}

struct FUN_00a011b0_cls {
};

struct FUN_0072ccd0_cls {
    int unk00;
    int unk04;
    int unk08;
    FUN_00a011b0_cls* m_0c;
    int FUN_0072ccd0();
};


// Returns GetRaceCount() minus the value FUN_00a011b0 computes from the static _num_filtered setting via m_0c.
// @fnv 0x0072ccd0
int FUN_0072ccd0_cls::FUN_0072ccd0()
{
    static int numFiltered = FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((m_0c))->GetFloat(numFiltered);
}

namespace fnv_0075b020 {
struct FUN_00a011b0_cls {
};

struct FUN_0075b020_cls {
    int unk00;
    int unk04;
    int unk08;
    FUN_00a011b0_cls* m_0c;
    int FUN_0075b020();
};


// Returns the result of GetRaceCount minus the value FUN_00a011b0 computes from the cached _num_filtered setting.
// @fnv 0x0075b020
int FUN_0075b020_cls::FUN_0075b020()
{
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((m_0c))->GetFloat(numFiltered);
}
}  // namespace fnv_0075b020

namespace fnv_007a71b0 {
struct FUN_00a011b0_cls {
};

struct FUN_007a71b0_cls {
    int unk00;
    int unk04;
    int unk08;
    FUN_00a011b0_cls* m_0c;
    int FUN_007a71b0();
};


// Returns the result of GetRaceCount minus the value FUN_00a011b0 computes from the cached "_num_filtered" setting.
// @fnv 0x007a71b0
int FUN_007a71b0_cls::FUN_007a71b0()
{
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((m_0c))->GetFloat(numFiltered);
}
}  // namespace fnv_007a71b0

struct RecurseItem;
struct RecurseNode;


float __cdecl FUN_00a01540(RecurseItem* self);

struct RecurseItem {
    void* unk00;
    RecurseNode* m_pkChildren;
};

struct RecurseNode {
    RecurseNode* m_pkNext;
    void* unk04;
    RecurseItem* m_pInventoryEntryData;
};

// @fnv 0x00a01540
float __cdecl FUN_00a01540(RecurseItem* self)
{
    float result2 = reinterpret_cast<::TileListBoxCalls *>((self))->GetFloat(0xfad);
    RecurseItem* child_ = 0;
    RecurseNode* pos5 = self->m_pkChildren;
    RecurseNode* cur = pos5;
    while (cur != 0) {
        RecurseItem* const& element3 = cur->m_pInventoryEntryData;
        cur = cur->m_pkNext;
        child_ = element3;
        if (reinterpret_cast<::TileListBoxCalls *>((self))->GetFloat(0xfa8) != ::_DAT_01012060) {
            float childF = reinterpret_cast<::TileListBoxCalls *>((self))->GetFloat(0xfad) + FUN_00a01540(child_);
            result2 = result2 > childF ? result2 : childF;
        } else {
            float childF = FUN_00a01540(child_);
            result2 = result2 > childF ? result2 : childF;
        }
    }
    return result2;
}

struct FNVSearchItem {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iKey10;
    void* m_pOwner14;
    int m_iValue18;
};

struct FNVSearchNode {
    FNVSearchItem* m_pInventoryEntryData;
    FNVSearchNode* m_pNext;
};


class FNVSearchOwner {
public:
    int FindValueByKey(int key);
};

// Walks the global search list and returns m_iValue18 of the first item whose m_iKey10 equals key and whose m_pOwner14 is this, else 0.
// @fnv 0x00a08070
int FNVSearchOwner::FindValueByKey(int key) {
    for (FNVSearchNode* node = &(*reinterpret_cast<::FNVSearchNode *>(&::fnv_00a00a30::DAT_011f3348)); node != 0 && node->m_pInventoryEntryData != 0; node = node->m_pNext) {
        if (node->m_pInventoryEntryData->m_iKey10 == key && node->m_pInventoryEntryData->m_pOwner14 == (void*)this) {
            return node->m_pInventoryEntryData->m_iValue18;
        }
    }
    return 0;
}

struct TileNode; struct TileNodeList { TileNodeList* next; TileNode* parent; TileNode* child; };
struct TileNode { void* virtualTable; TileNodeList* children;  };
// Recursively searches root and its child nodes for the first TileNode whose trait 0xFAA equals target, returning it or null.
// @fnv 0x00a08fb0
TileNode* __cdecl FindTileNodeByTrait(TileNode* root, int target) {
    TileNodeList* cursor;
    {
        TileNode* found;
        {
            if (root && reinterpret_cast<::TileListBoxCalls *>((root))->GetFloat(0xFAA) == target) return root;
            TileNodeList* head = root->children;
            cursor = head;
            while (cursor) {
                TileNode** ppLink = &cursor->child;
                cursor = cursor->next;
                found = FindTileNodeByTrait(*ppLink, target);
                if (found) return found;
            }
        }
    }
    return 0;
}

// Look up the handler list registered for a key and notify every handler in it.

struct A0A220Handler {
};

struct A0A220Node {
    A0A220Handler* m_pkItem;
    A0A220Node* m_pkNext;
};

struct A0A220HandlerMap {
    bool GetAt(unsigned int uiKey, A0A220Node*& rpkHead);
};


// Looks up the handler list for uiKey and calls Notify(0) on each handler in the chain.
// @fnv 0x00a0a220
void __cdecl NotifyHandlersByKey(unsigned int uiKey)
{
    A0A220Node* pkIter = 0;
    A0A220Handler* pkItem;  // declared but never used in this build
    unsigned int ItemUpdateArray;      // declared but never used in this build
    if (reinterpret_cast<::S_00adc830_Map *>(&(g_kA0A220Handlers))->GetAt(uiKey, (::S_00adc830_Entry *&)(pkIter))) {
        while (pkIter) {
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pkIter->m_pkItem))->FUN_00a09410(0);
            pkIter = pkIter->m_pkNext;
        }
    }
}

class InventoryMenuSetting {
public:
};
struct SystemLocaleState : InventoryMenuSetting {};
class GlobalObject_0040c150 : public InventoryMenuSetting {};
void __cdecl FUN_00730490(char*, int);
struct FUN_0055d520_shell { char* FUN_0055d520(); };
struct Menu_007301f0 {
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
    P09TileS* primaryTile;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    FUN_0055d520_shell* selectedObject;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int primaryCategory;
    int secondaryCategory;
    void UpdateTileText(P09TileS* tile);
};

// @fnv 0x007301f0
void Menu_007301f0::UpdateTileText(P09TileS* tile)
{
    char text[260];
    int selection = tile == primaryTile ? primaryCategory : secondaryCategory;
    bool isLocalized = FUN_00408b20(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SystemLocaleState *>(&::g_011c3cb4))))->GetMenuTitle())), "ENGLISH") != 0;
    switch (selection) {
    case 0:
        if (tile == primaryTile) {
            ::TaskQueueInterface::CopyStringToBuffer(text, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d4378))->GetMenuTitle())));
            if (!isLocalized)
                FUN_00730490(text, 260);
        } else {
            ::TaskQueueInterface::CopyStringToBuffer(text, 260, selectedObject->FUN_0055d520());
        }
        break;
    case 1:
        ::TaskQueueInterface::CopyStringToBuffer(text, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d29b8))))->GetMenuTitle())));
        if (!isLocalized)
            FUN_00730490(text, 260);
        break;
    case 2:
        ::TaskQueueInterface::CopyStringToBuffer(text, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d4d50))))->GetMenuTitle())));
        if (!isLocalized)
            FUN_00730490(text, 260);
        break;
    case 3:
        ::TaskQueueInterface::CopyStringToBuffer(text, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d40b4))))->GetMenuTitle())));
        if (!isLocalized)
            FUN_00730490(text, 260);
        break;
    case 4:
        ::TaskQueueInterface::CopyStringToBuffer(text, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InventoryMenuSetting *>(&::g_011d2acc))))->GetMenuTitle())));
        if (!isLocalized)
            FUN_00730490(text, 260);
        break;
    case 5:
        ::TaskQueueInterface::CopyStringToBuffer(text, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d4918))->GetMenuTitle())));
        if (!isLocalized)
            FUN_00730490(text, 260);
        break;
    }
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(0xfc4, (char *)(text), true);
}

namespace TraitRegistration {
extern unsigned char DAT_011d8c50;
extern char DAT_010345e4;
extern char DAT_0103c034;
extern char DAT_01044c0c;
extern char DAT_0106ec74;
extern char DAT_0106ec7c;
extern char DAT_0106f488;
extern char DAT_0106f490;
extern char DAT_0106fc9c;
extern char DAT_01076f20;
extern char DAT_01077c6c;
extern char DAT_01077c78;
extern char DAT_01078bc0;
extern char DAT_01086f50;
extern char DAT_0108dff8;
extern char DAT_01093f84;
extern char DAT_01093f8c;
extern char DAT_01093f98;
extern char DAT_01093fa0;
extern char DAT_01093fa8;
extern char DAT_01093fac;
extern char DAT_01093fb0;
extern char DAT_01093fc4;
extern char DAT_01093fcc;
extern char DAT_01093fd4;
extern char DAT_01093fdc;
extern char DAT_01093fe4;
extern char DAT_01093fe8;
extern char DAT_01093ff4;
extern char DAT_01094004;
extern char DAT_01094010;
extern char DAT_0109401c;
extern char DAT_01094028;
extern char DAT_01094034;
extern char DAT_01094040;
extern char DAT_0109404c;
extern char DAT_01094058;
extern char DAT_01094064;
extern char DAT_01094070;
extern char DAT_0109407c;
extern char DAT_01094088;
extern char DAT_01094090;
extern char DAT_0109409c;
extern char DAT_010940a8;
extern char DAT_010940b0;
extern char DAT_010940b8;
extern char DAT_010940c0;
extern char DAT_010940c8;
extern char DAT_010940d0;
extern char DAT_010940d8;
extern char DAT_010940e0;
extern char DAT_010940e8;
extern char DAT_010940f0;
extern char DAT_010940f8;
extern char DAT_01094100;
extern char DAT_01094108;
extern char DAT_01094110;
extern char DAT_01094118;
extern char DAT_01094120;
extern char DAT_01094128;
extern char DAT_01094130;
extern char DAT_01094138;
extern char DAT_01094144;
extern char DAT_01094150;
extern char DAT_01094158;
extern char DAT_01094168;
extern char DAT_01094178;
extern char DAT_01094184;
extern char DAT_01094190;
extern char DAT_0109419c;
extern char DAT_010941b0;
extern char DAT_010941c0;
extern char DAT_010941c4;
extern char DAT_010941cc;
extern char DAT_010941d8;
extern char DAT_010941e4;
extern char DAT_010941f0;
extern char DAT_010941f8;
extern char DAT_01094204;
extern char DAT_0109420c;
extern char DAT_01094218;
extern char DAT_01094220;
extern char DAT_01094228;
extern char DAT_0109422c;
extern char DAT_01094234;
extern char DAT_0109423c;
extern char DAT_01094244;
extern char DAT_01094250;
extern char DAT_0109425c;
extern char DAT_01094268;
extern char DAT_01094274;
extern char DAT_0109427c;
extern char DAT_01094284;
extern char DAT_01094290;
extern char DAT_0109429c;
extern char DAT_010942a8;
extern char DAT_010942b4;
extern char DAT_010942c0;
extern char DAT_010942cc;
extern char DAT_010942d8;
extern char DAT_010942e4;
extern char DAT_010942ec;
extern char DAT_010942f4;
extern char DAT_010942fc;
extern char DAT_01094308;
extern char DAT_01094314;
extern char DAT_01094320;
extern char DAT_01094330;
extern char DAT_0109433c;
extern char DAT_01094344;
extern char DAT_0109434c;
extern char DAT_01094358;
extern char DAT_01094364;
extern char DAT_01094370;
extern char DAT_01094378;
extern char DAT_01094384;
extern char DAT_0109438c;
extern char DAT_01094394;
extern char DAT_01094398;
extern char DAT_010943a0;
extern char DAT_010943a4;
extern char DAT_010943ac;
extern char DAT_010943b0;
extern char DAT_010943bc;
extern char DAT_010943c4;
extern char DAT_010943c8;
extern char DAT_010943cc;
extern char DAT_010943d4;
extern char DAT_010943d8;
extern char DAT_010943dc;
extern char DAT_010943e0;
extern char DAT_010943e4;
extern char DAT_010943e8;
extern char DAT_010943ec;
extern char DAT_010943f0;
extern char DAT_010943f8;
extern char DAT_010943fc;
extern char DAT_01094400;
extern char DAT_01094408;
extern char DAT_01094410;
extern char DAT_01094414;
extern char DAT_01094418;
extern char DAT_0109441c;
extern char DAT_01094428;
extern char DAT_01094438;
extern char DAT_01094448;
extern char DAT_01094458;
extern char DAT_01094468;
extern char DAT_0109447c;
extern char DAT_01094490;
extern char DAT_010944a4;
extern char DAT_010944bc;
extern char DAT_010944d0;
extern char DAT_010944dc;
extern char DAT_010944ec;
extern char DAT_010944fc;
extern char DAT_0109450c;
extern char DAT_0109451c;
extern char DAT_0109452c;
extern char DAT_01094544;
extern char DAT_01094554;
extern char DAT_01094564;
extern char DAT_01094574;
extern char DAT_01094580;
extern char DAT_0109458c;
extern char DAT_0109459c;
extern char DAT_010945ac;
extern char DAT_010945bc;
extern char DAT_010945c8;
extern char DAT_010945d8;
extern char DAT_010945e8;
extern char DAT_010945f8;
extern char DAT_01094604;
extern char DAT_01094614;
extern char DAT_01094624;
extern char DAT_01094634;
extern char DAT_01094644;
extern char DAT_01094654;
extern char DAT_01094664;
extern char DAT_01094674;
extern char DAT_01094684;
extern char DAT_01094690;
extern char DAT_0109469c;
extern char DAT_010946a4;
extern char DAT_010946ac;
extern char DAT_010946b8;
extern char DAT_010946c0;
extern char DAT_010946c8;
extern char DAT_010946cc;
extern char DAT_010946d0;
extern char DAT_010946d8;
extern char DAT_010946e0;
extern char DAT_010946ec;
extern char DAT_010946f8;
extern char DAT_01094704;
extern char DAT_01094710;
extern char DAT_0109471c;
extern char DAT_01094728;
extern char DAT_01094734;
extern char DAT_01094740;
extern char DAT_0109474c;
extern char DAT_01094758;
extern char DAT_0109476c;
extern char DAT_01094778;
extern char DAT_01094788;
extern char DAT_01094798;
extern char DAT_010947a8;
extern char DAT_010947b8;
extern char DAT_010947c8;
extern char DAT_010947d8;
extern char DAT_010947e4;
extern char DAT_010947f0;
extern char DAT_01094800;
extern char DAT_01094814;
extern char DAT_01094824;
extern char DAT_01094834;
extern char DAT_0109483c;
extern char DAT_01094844;
extern char DAT_0109484c;
extern char DAT_01094854;
extern char DAT_01094860;
extern char DAT_01094868;
// @fnv 0x009ff970
void FUN_009ff970(){
::FUN_009ff8a0(&DAT_01094868, -1);
::FUN_009ff8a0(&DAT_0106ec74, 0);
::FUN_009ff8a0(&DAT_0106ec7c, 1);
::FUN_009ff8a0(&DAT_01094860, 1);
::FUN_009ff8a0(&DAT_01094854, 2);
::FUN_009ff8a0(&DAT_0109484c, 4);
::FUN_009ff8a0(&DAT_01094844, 5);
::FUN_009ff8a0(&DAT_0109483c, 6);
::FUN_009ff8a0(&DAT_01094834, -1);
::FUN_009ff8a0(&DAT_01094824, 101);
::FUN_009ff8a0(&DAT_01094814, 102);
::FUN_009ff8a0(&DAT_01094800, 6008);
::FUN_009ff8a0(&DAT_010947f0, 103);
::FUN_009ff8a0(&DAT_0106f490, (unsigned char)(((*reinterpret_cast<unsigned char *>(&::DAT_011d8a84)) && bool(DAT_011d8c50 ? 0 : 1)) ? 1 : 0));
::FUN_009ff8a0(&DAT_010947e4, 0);
::FUN_009ff8a0(&DAT_0106f488, (unsigned char)(((*reinterpret_cast<unsigned char *>(&::DAT_011d8a84)) && bool(DAT_011d8c50 ? 0 : 1)) ? 1 : 0));
::FUN_009ff8a0(&DAT_010947d8, 1);
::FUN_009ff8a0(&DAT_010947c8, ::Interface::IsInterfaceOpen());
::FUN_009ff8a0(&DAT_010947b8, 110);
::FUN_009ff8a0(&DAT_010947a8, 111);
::FUN_009ff8a0(&DAT_01094798, 112);
::FUN_009ff8a0(&DAT_01094788, -1);
::FUN_009ff8a0(&DAT_01094778, 0);
::FUN_009ff8a0(&DAT_0109476c, -1);
::FUN_009ff8a0(&DAT_01094758, 9);
::FUN_009ff8a0(&DAT_0109474c, 9);
::FUN_009ff8a0(&DAT_01094740, 10);
::FUN_009ff8a0(&DAT_01094734, 11);
::FUN_009ff8a0(&DAT_01094728, 12);
::FUN_009ff8a0(&DAT_0109471c, 13);
::FUN_009ff8a0(&DAT_01094710, 14);
::FUN_009ff8a0(&DAT_01094704, 15);
::FUN_009ff8a0(&DAT_010946f8, 16);
::FUN_009ff8a0(&DAT_01077c78, 17);
::FUN_009ff8a0(&DAT_01077c6c, 18);
::FUN_009ff8a0(&DAT_010946ec, 17);
::FUN_009ff8a0(&DAT_010946e0, 18);
::FUN_009ff8a0(&DAT_010946d8, 902);
::FUN_009ff8a0(&DAT_010946d0, 905);
::FUN_009ff8a0(&DAT_010946cc, 904);
::FUN_009ff8a0(&DAT_010946c8, 904);
::FUN_009ff8a0(&DAT_010946c0, 901);
::FUN_009ff8a0(&DAT_010946b8, 906);
::FUN_009ff8a0(&DAT_010946ac, 999);
::FUN_009ff8a0(&DAT_0103c83c, 903);
::FUN_009ff8a0(&DAT_010946a4, 907);
::FUN_009ff8a0(&DAT_0109469c, 908);
::FUN_009ff8a0(&DAT_01094690, 1017);
::FUN_009ff8a0(&DAT_01094684, 1026);
::FUN_009ff8a0(&DAT_01094674, 1048);
::FUN_009ff8a0(&DAT_01094664, 1008);
::FUN_009ff8a0(&DAT_01094654, 1009);
::FUN_009ff8a0(&DAT_01094644, 1020);
::FUN_009ff8a0(&DAT_01094634, 1004);
::FUN_009ff8a0(&DAT_01094624, 1002);
::FUN_009ff8a0(&DAT_01094614, 1007);
::FUN_009ff8a0(&DAT_01094604, 1014);
::FUN_009ff8a0(&DAT_010945f8, 1023);
::FUN_009ff8a0(&DAT_010945e8, 1001);
::FUN_009ff8a0(&DAT_010945d8, 1059);
::FUN_009ff8a0(&DAT_010945c8, 1051);
::FUN_009ff8a0(&DAT_010945bc, 1013);
::FUN_009ff8a0(&DAT_010945ac, 1016);
::FUN_009ff8a0(&DAT_0109459c, 1036);
::FUN_009ff8a0(&DAT_0109458c, 1012);
::FUN_009ff8a0(&DAT_01094580, 1003);
::FUN_009ff8a0(&DAT_01094574, 1018);
::FUN_009ff8a0(&DAT_01094564, 1027);
::FUN_009ff8a0(&DAT_01094554, 1035);
::FUN_009ff8a0(&DAT_01094544, 1061);
::FUN_009ff8a0(&DAT_0109452c, 1058);
::FUN_009ff8a0(&DAT_0109451c, 1047);
::FUN_009ff8a0(&DAT_0109450c, 1053);
::FUN_009ff8a0(&DAT_010944fc, 1054);
::FUN_009ff8a0(&DAT_010944ec, 1055);
::FUN_009ff8a0(&DAT_010944dc, 1057);
::FUN_009ff8a0(&DAT_010944d0, 1056);
::FUN_009ff8a0(&DAT_010944bc, 1060);
::FUN_009ff8a0(&DAT_010944a4, 1075);
::FUN_009ff8a0(&DAT_01094490, 1074);
::FUN_009ff8a0(&DAT_0109447c, 1076);
::FUN_009ff8a0(&DAT_01094468, 1080);
::FUN_009ff8a0(&DAT_01094458, 1081);
::FUN_009ff8a0(&DAT_01094448, 1082);
::FUN_009ff8a0(&DAT_01094438, 1077);
::FUN_009ff8a0(&DAT_01094428, 1083);
::FUN_009ff8a0(&DAT_0109441c, 1084);
::FUN_009ff8a0(&DAT_01094418, 2010);
::FUN_009ff8a0(&DAT_01094414, 2001);
::FUN_009ff8a0(&DAT_01094410, 2018);
::FUN_009ff8a0(&DAT_01094408, 2009);
::FUN_009ff8a0(&DAT_01094400, 2000);
::FUN_009ff8a0(&DAT_010943fc, 2004);
::FUN_009ff8a0(&DAT_010943f8, 2014);
::FUN_009ff8a0(&DAT_010943f0, 2008);
::FUN_009ff8a0(&DAT_010943ec, 2012);
::FUN_009ff8a0(&DAT_010943e8, 2013);
::FUN_009ff8a0(&(*reinterpret_cast<char *>((void *)&::str_01076f38)), 2016);
::FUN_009ff8a0(&DAT_010943e4, 2017);
::FUN_009ff8a0(&DAT_010943e0, 2006);
::FUN_009ff8a0(&DAT_010943dc, 2005);
::FUN_009ff8a0(&DAT_010943d8, 2007);
::FUN_009ff8a0(&DAT_010943d4, 2003);
::FUN_009ff8a0(&DAT_010943cc, 2003);
::FUN_009ff8a0(&DAT_010943c8, 2015);
::FUN_009ff8a0(&DAT_010943c4, 2020);
::FUN_009ff8a0(&DAT_010943bc, 2021);
::FUN_009ff8a0(&DAT_010943b0, 2022);
::FUN_009ff8a0(&DAT_010943ac, 2019);
::FUN_009ff8a0(&DAT_01044c0c, 2023);
::FUN_009ff8a0(&DAT_010943a4, 2011);
::FUN_009ff8a0(&DAT_010943a0, 2002);
::FUN_009ff8a0(&DAT_01094398, 3002);
::FUN_009ff8a0(&DAT_01094394, 3003);
::FUN_009ff8a0(&DAT_0109438c, 3004);
::FUN_009ff8a0(&DAT_01094384, 3001);
::FUN_009ff8a0(&DAT_0103a454, 4009);
::FUN_009ff8a0(&DAT_01094378, 4050);
::FUN_009ff8a0(&DAT_01094370, 4020);
::FUN_009ff8a0(&DAT_01094364, 4085);
::FUN_009ff8a0(&DAT_01094358, 4022);
::FUN_009ff8a0(&DAT_0109434c, 4022);
::FUN_009ff8a0(&DAT_01094344, 4004);
::FUN_009ff8a0(&DAT_0109433c, 4039);
::FUN_009ff8a0(&DAT_01094330, 4043);
::FUN_009ff8a0(&DAT_01094320, 4072);
::FUN_009ff8a0(&DAT_01094314, 4011);
::FUN_009ff8a0(&DAT_01094308, 4032);
::FUN_009ff8a0(&DAT_010942fc, 4031);
::FUN_009ff8a0(&DAT_010942f4, 4032);
::FUN_009ff8a0(&DAT_010942ec, 4031);
::FUN_009ff8a0(&DAT_010942e4, 4014);
::FUN_009ff8a0(&DAT_010942d8, 4006);
::FUN_009ff8a0(&DAT_0103c034, 4013);
::FUN_009ff8a0(&DAT_010942cc, 4073);
::FUN_009ff8a0(&DAT_010942c0, 4078);
::FUN_009ff8a0(&DAT_010942b4, 4079);
::FUN_009ff8a0(&DAT_010942a8, 4074);
::FUN_009ff8a0(&DAT_0109429c, 4075);
::FUN_009ff8a0(&DAT_01094290, 4076);
::FUN_009ff8a0(&DAT_01094284, 4077);
::FUN_009ff8a0(&DAT_0109427c, 4080);
::FUN_009ff8a0(&DAT_01094274, 4081);
::FUN_009ff8a0(&DAT_01094268, 4034);
::FUN_009ff8a0(&DAT_0109425c, 4046);
::FUN_009ff8a0(&DAT_01094250, 4044);
::FUN_009ff8a0(&DAT_01094244, 4045);
::FUN_009ff8a0(&DAT_0109423c, 4025);
::FUN_009ff8a0(&DAT_01094234, 4019);
::FUN_009ff8a0(&DAT_0109422c, 4016);
::FUN_009ff8a0(&DAT_01094228, 4010);
::FUN_009ff8a0(&DAT_01094220, 4030);
::FUN_009ff8a0(&DAT_01094218, 4023);
::FUN_009ff8a0(&DAT_0109420c, 4052);
::FUN_009ff8a0(&DAT_01094204, 4087);
::FUN_009ff8a0(&DAT_010941f8, 4012);
::FUN_009ff8a0(&DAT_010941f0, 4008);
::FUN_009ff8a0(&DAT_010941e4, 4033);
::FUN_009ff8a0(&DAT_010941d8, 4035);
::FUN_009ff8a0(&DAT_010941cc, 4053);
::FUN_009ff8a0(&DAT_010941c4, 4029);
::FUN_009ff8a0(&DAT_010941c0, 4018);
::FUN_009ff8a0(&DAT_010941b0, 4047);
::FUN_009ff8a0(&DAT_0109419c, 4048);
::FUN_009ff8a0(&DAT_01094190, 4090);
::FUN_009ff8a0(&DAT_01094184, 4091);
::FUN_009ff8a0(&DAT_01094178, 4092);
::FUN_009ff8a0(&DAT_01094168, 4037);
::FUN_009ff8a0(&DAT_01094158, 4007);
::FUN_009ff8a0(&DAT_01094150, 4036);
::FUN_009ff8a0(&DAT_01094144, 4084);
::FUN_009ff8a0(&DAT_0108dff8, 4015);
::FUN_009ff8a0(&DAT_01094138, 4089);
::FUN_009ff8a0(&DAT_01094130, 4021);
::FUN_009ff8a0(&DAT_01094128, 4100);
::FUN_009ff8a0(&DAT_01094120, 4101);
::FUN_009ff8a0(&DAT_01094118, 4102);
::FUN_009ff8a0(&DAT_01094110, 4103);
::FUN_009ff8a0(&DAT_01094108, 4104);
::FUN_009ff8a0(&DAT_01094100, 4105);
::FUN_009ff8a0(&DAT_010940f8, 4106);
::FUN_009ff8a0(&DAT_010940f0, 4107);
::FUN_009ff8a0(&DAT_010940e8, 4108);
::FUN_009ff8a0(&DAT_010940e0, 4109);
::FUN_009ff8a0(&DAT_010940d8, 4110);
::FUN_009ff8a0(&DAT_010940d0, 4111);
::FUN_009ff8a0(&DAT_010940c8, 4112);
::FUN_009ff8a0(&DAT_010940c0, 4113);
::FUN_009ff8a0(&DAT_010940b8, 4114);
::FUN_009ff8a0(&DAT_010940b0, 4115);
::FUN_009ff8a0(&DAT_010940a8, 4116);
::FUN_009ff8a0(&DAT_0106fc9c, 4003);
::FUN_009ff8a0(&DAT_0109409c, 4082);
::FUN_009ff8a0(&DAT_01094090, 4083);
::FUN_009ff8a0(&DAT_01094088, 4017);
::FUN_009ff8a0(&DAT_0109407c, 4027);
::FUN_009ff8a0(&DAT_01094070, 4028);
::FUN_009ff8a0(&DAT_01094064, 4026);
::FUN_009ff8a0(&DAT_01094058, 4061);
::FUN_009ff8a0(&DAT_0109404c, 4062);
::FUN_009ff8a0(&DAT_01094040, 4063);
::FUN_009ff8a0(&DAT_01094034, 4064);
::FUN_009ff8a0(&DAT_01094028, 4065);
::FUN_009ff8a0(&DAT_0109401c, 4066);
::FUN_009ff8a0(&DAT_01094010, 4067);
::FUN_009ff8a0(&DAT_01094004, 4068);
::FUN_009ff8a0(&DAT_01093ff4, 4071);
::FUN_009ff8a0(&DAT_01093fe8, 4054);
::FUN_009ff8a0(&DAT_01093fe4, 4055);
::FUN_009ff8a0(&DAT_01093fdc, 4056);
::FUN_009ff8a0(&DAT_01093fd4, 4057);
::FUN_009ff8a0(&DAT_01093fcc, 4058);
::FUN_009ff8a0(&DAT_010345e4, 4001);
::FUN_009ff8a0(&DAT_01076f20, 4002);
::FUN_009ff8a0(&DAT_01093fc4, 4024);
::FUN_009ff8a0(&DAT_01093fb0, 4088);
::FUN_009ff8a0(&DAT_01086f50, 5005);
::FUN_009ff8a0(&DAT_01093fac, 5002);
::FUN_009ff8a0(&DAT_01093fa8, 5008);
::FUN_009ff8a0(&DAT_01093fa0, 5001);
::FUN_009ff8a0(&DAT_01078bc0, 5006);
::FUN_009ff8a0(&DAT_01093f98, 5004);
::FUN_009ff8a0(&DAT_01093f8c, 5009);
::FUN_009ff8a0(&DAT_01093f84, 5007);
}
}

struct MenuDepthController;
struct UpdateTreeNode;
struct UpdateNode { UpdateNode* next; UpdateNode* prev; UpdateTreeNode* data; };
struct MenuDepthController {
 virtual void m0(); virtual void SetDepth(int, UpdateTreeNode*);
 int unk04, unk08, unk0c, unk10, unk14;
 int depth;
};
struct UpdateTreeNode {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual int GetType();
 UpdateNode* children;
 int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
 UpdateTreeNode* parent;
 __forceinline UpdateTreeNode* GetParent() { return parent; }
 __forceinline UpdateNode* GetChildren() { return children; }
 UpdateTreeNode* FUN_00a037e0(int, float, const char*);
};
// @fnv 0x00a037e0
UpdateTreeNode* UpdateTreeNode::FUN_00a037e0(int trait, float value, const char* unused)
{
 UpdateTreeNode* aBound; MenuDepthController* aCurrent; float aLast; UpdateTreeNode* aReadObject;
 UpdateNode* aBipedNode; MenuDepthController* aOther; UpdateTreeNode* aContext; UpdateTreeNode* aList1; UpdateTreeNode* aPrevious; int aMargin; UpdateNode* aOuter2; UpdateTreeNode** aLocation;
 if (trait == 0xfa1 || trait == 0xfa2 || trait == 0xfad) {
  if (trait == 0xfad) {
   aLast = value;
   aReadObject = this;
   while ((aContext = aReadObject->parent) && (aList1 = aReadObject->parent, aPrevious = aList1->parent)) {
    if (reinterpret_cast<::TileListBoxCalls *>((aReadObject))->GetFloat(0xfa8) != 0.0) aLast += reinterpret_cast<::TileListBoxCalls *>((aReadObject))->GetFloat(0xfad);
    aReadObject = aReadObject->parent;
   }
   aCurrent = ((::MenuDepthController *)(reinterpret_cast<::FUN_00a03c90_shell *>(this)->FUN_00a03c90()));
   aBound = ((::UpdateTreeNode *)(reinterpret_cast<::FUN_00a03d40_shell *>(this)->FUN_00a03d40()));
   if (aCurrent && aBound && aBound != this && aCurrent && aLast > (aMargin = aCurrent->depth)) aCurrent->depth = (int)aLast;
  }
  if (reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa6) != 0.0) reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x80);
  reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(1); return this;
 }
 if (GetType() == 0x387 && (trait == 0xfba || trait == 0xfbb || trait == 0xfbc || trait == 0xff7 || trait == 0xfbd || trait == 0xfbe || trait == 0xfb9 || trait == 0xfb7)) {
  reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(2); return this;
 }
 if ((trait == 0xfb1 || trait == 0xfb0 || trait == 0xfc0 || trait == 0xfbf) && GetType() == 0x386) {
  if (reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa6) != 0.0) reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x80);
  reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x10); return this;
 }
 if (trait == 0xfa6 && (GetType() == 0x386 || GetType() == 0x385)) { reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x80); return this; }
 if (trait == 0xfae && (GetType() == 0x386 || GetType() == 0x387)) {
  reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x100);
  aOuter2 = children;
  aBipedNode = aOuter2;
  while (aBipedNode) {
   aLocation = &aBipedNode->data;
   aBipedNode = aBipedNode->next;
   reinterpret_cast<::FUN_00a012d0_t *>(((*aLocation)))->FUN_00a012d0(0xfae,reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfae),true);
  }
  return this;
 }
 if (trait == 0xfa3) { reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(4); return this; }
 if (trait == 0xfa9 || trait == 0xfb2 || trait == 0xfb3 || trait == 0xfb4 || trait == 0xff4 || trait == 0xff5) {
  if (GetType() == 0x386 || GetType() == 0x387) reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(8);
  return this;
 }
 if (trait == 0xfcc && GetType() == 0x386 && reinterpret_cast<::FUN_00a011f0_shell *>(this)->FUN_00a011f0(0xfcc)) { reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x20); return this; }
 if (trait == 0xfcc && GetType() == 0x388 && reinterpret_cast<::FUN_00a011f0_shell *>(this)->FUN_00a011f0(0xfcc)) { reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x40); return this; }
 if (trait == 0xfa8) { reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x200); return this; }
 if (trait == 0xfaa) {
  aOther = ((::MenuDepthController *)(reinterpret_cast<::FUN_00a03c90_shell *>(this)->FUN_00a03c90()));
  if (aOther) aOther->SetDepth((int)value,this);
 }
 if (trait == 0xffa || trait == 0xffb || trait == 0xffc) { reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(1); return this; }
 return 0;
}

namespace fnv_00a0a300 {

struct TileValueStr {
    int m_iValueId;
    Tile* pTile;
    float fValue;
    char* pString;
    void SetString(const char* apString, bool abUpdate);
};

// @fnv 0x00a0a300
void TileValueStr::SetString(const char* apString, bool abUpdate)
{
    const char* pCur;
    char* pOld;
    unsigned int uiLen6;
    char* pNew3;
    char* pDest4;
    bool kBChanged = (!pString && apString) || (pString && !apString) ||
                    (pString && apString && (pCur = pString, std::strcmp(pCur, apString)));
    if (pString) {
        pOld = pString;
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(pOld);
        pString = 0;
    }
    if (apString) {
        uiLen6 = std::strlen(apString);
        pNew3 = (char*)reinterpret_cast<::MemoryManagerStandIn *>((((P03MM*)&g_memoryManager)))->FUN_00aa3e40(uiLen6 + 1);
        pString = pNew3;
        pDest4 = pString;
        fnv::crt::strcpy_s(pDest4, uiLen6 + 1, apString);
    }
    fValue = 0.0f;
    if (abUpdate)
        reinterpret_cast<::fnv_00a09200::Value_00a09200 *>(this)->RemoveFromReactions();
    reinterpret_cast<::fnv_00a09410::EvalValue *>(this)->FUN_00a09410(kBChanged);
}
}  // namespace fnv_00a0a300

struct FUN_00a0d1b0_cls {
    int unk00;
    unsigned int m_04;

    unsigned int HashKey(const char* key);
};

// Computes a rolling hash of the lowercased characters of key and returns it modulo m_04.
// @fnv 0x00a0d1b0
unsigned int FUN_00a0d1b0_cls::HashKey(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        char c;
        hash = (hash << 5) + hash + (c = tolower(*key++));
    }
    return hash % m_04;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
#include "fnv/decl/Bound88.h"
#include "fnv/decl/FUN_00a8a670_shell.h"
#include <cmath>
#include "fnv/decl/AAOwner.h"
#include "fnv/decl/AE91F0Map.h"
#include "fnv/decl/AGOwner.h"
#include "fnv/decl/FGModel.h"
#include "fnv/decl/FUN_00403a00_class.h"
#include "fnv/decl/FUN_004ed8c0_shell.h"
#include "fnv/decl/FUN_00a1dd80_Class.h"
#include "fnv/decl/FUN_00a7b300_shell.h"
#include "fnv/decl/FUN_00aaa720_cls.h"
#include "fnv/decl/FUN_00ac5c00_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8d60_shell.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/FUN_00ae8010_cls.h"
#include "fnv/decl/FaceBinaryReadReceiver.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiRenderer.h"
#include "fnv/decl/ObjPtrArray.h"
#include "fnv/decl/Pn4afe.h"
#include "fnv/decl/RecursiveLock.h"
#include "fnv/decl/RgbaColor.h"
#include "fnv/decl/S00a0ca70_List.h"
#include "fnv/decl/S_00a0c9f0.h"
#include "fnv/decl/S_00ae8370_List.h"
#include "fnv/decl/SystemColorManager.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/Tile3DCalc.h"
#include "fnv/decl/TileModelsUpdateEntry.h"
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/decl/fnv_00709eb0__FUN_00709eb0_Class.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/fnv_00adddd0__FUN_00a1b940.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00416000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_00a02000.h"
#include "fnv/symbols_00a06000.h"
#include "fnv/symbols_00a0b000.h"
#include "fnv/symbols_00a1c000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a61000.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01073000.h"
#include "fnv/symbols_01094000.h"
#include "fnv/symbols_01272000.h"
#include "fnv/decl/FloatArr.h"
#include "fnv/decl/MenuValueDescriptor.h"
#include "fnv/decl/SoundPlayback.h"
#include "fnv/decl/fnv_006db720__FUN_006db720_Class.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a0a000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_0106c000.h"
#include <math.h>

struct FadeRecord;

class NiNode;

class NiExtraData;

class NiFixedString;

class NiAVObject {
public:
    virtual ~NiAVObject();
    virtual void* GetRTTI() const;
    virtual NiNode* IsFadeNode();
    virtual NiNode* IsSceneNode();
    virtual void* IsSwitchNode();
    virtual void* IsMultiBoundNode();
    virtual void* IsGeometry();
public:
    ::NiExtraData *GetExtraData(const ::NiFixedString &);
};

template<class T> class ChildPtr {
public:
    T* m_pObject;
    __forceinline operator T*() const { return m_pObject; }
};

template<class T> class ChildArray {
public:
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    __forceinline T& GetAt(unsigned int uiIndex) const { return m_pBase[uiIndex]; }
};

class NiNode : public NiAVObject {
public:
    char pad04[0x9c];
    ChildArray<ChildPtr<NiAVObject> > m_kChildren;
    ChildArray<ChildPtr<NiAVObject> >& GetChildren() { return m_kChildren; }
};

struct NiAVObject;

// namespace fnv_00a1e1d0



class NiFixedString {
public:
    char* text;
    __forceinline NiFixedString(const char* str) {
        if (str == 0) {
            text = ::DAT_0109b220;
            return;
        }
        text = ::NiGlobalStringTable::AddString(str);
    }
    __forceinline ~NiFixedString() {
        if (text == ::DAT_0109b220) {} else {
            char* p = text - 8;
            InterlockedDecrement((long volatile*)p);
        }
    }
};

class NiAVObject;



extern int DAT_011d8e64;
extern int DAT_011d8e68;
struct ListOwner {  };
struct FUN_00726920_StandIn { char pad0[0xc]; Tile* pTile; int FUN_00726920(); };
// @fnv 0x00726920
int FUN_00726920_StandIn::FUN_00726920()
{
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)(((ListOwner*)this))) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(numFiltered);
}

class StrMapW {
public:
    void* vtbl;
    unsigned int m_uiHashSize;
    unsigned int FUN_00a0d440(const char* pKey);
};
// Computes a hash of the pKey string and returns it modulo m_uiHashSize.
// @fnv 0x00a0d440
unsigned int StrMapW::FUN_00a0d440(const char* pKey)
{
    unsigned int uiHash = 0;
    while (*pKey)
    {
        char c = *pKey;
        uiHash = uiHash + (c + (uiHash << 5));
        pKey++;
    }
    return uiHash % m_uiHashSize;
}


struct FilteredList {
    int unk00;
    int unk04;
    int unk08;
    Tile* tile;
    unsigned int FUN_00726870();
};

// Returns the total race count minus the value stored in the tile's float field at the index resolved from the static string constant.
// @fnv 0x00726870
unsigned int FilteredList::FUN_00726870()
{
    static int s_iNumFiltered = FUN_00a00940(::str_0106f8d0, -1);
    return GetRaceCount((char*)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(s_iNumFiltered);
}

namespace filt72c {
struct F2Tile {
};
struct F2Menu {
    int unk00;
    int unk04;
    int unk08;
    F2Tile* pList;
    int FUN_0072cd80();
};
}
using namespace filt72c;

// Returns the number of races that are not filtered out by the _num_filtered trait.
// @fnv 0x0072cd80
int F2Menu::FUN_0072cd80()
{
    static int s_iNumFiltered = FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((pList))->GetFloat(s_iNumFiltered);
}

struct TraitSource {
};
struct ItemCounter {
    int unk00;
    int unk04;
    int unk08;
    TraitSource* tile;
    unsigned int FUN_007a8030();
};
// Returns the race count minus the trait value from the tile's TraitSource for the static trait id.
// @fnv 0x007a8030
unsigned int ItemCounter::FUN_007a8030() {
    static int trait = FUN_00a00940(::str_0106f8d0, -1);
    return ::GetRaceCount((char *)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(trait);
}

namespace filt7a8 {
struct F7Tile {
};
struct F7Menu {
    int unk00;
    int unk04;
    int unk08;
    F7Tile* pList;
    int FUN_007a86e0();
};
}
using namespace filt7a8;

// Returns the total race count minus the number of races filtered out by the _num_filtered trait.
// @fnv 0x007a86e0
int F7Menu::FUN_007a86e0()
{
    static int s_iNumFiltered = FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((pList))->GetFloat(s_iNumFiltered);
}


struct S00a014b0_Tile : Tile {
    float FUN_00a014b0();
};

// Adds this tile's 0xfad value, then linked tiles' values when 0xfa8 is nonzero or the next pointer matches FUN_00706cd0().
// @fnv 0x00a014b0
float S00a014b0_Tile::FUN_00a014b0()
{
    Tile* pChild;
    float fTotal = reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfad);
    pChild = ((Tile*)this)->m_pParent;
    while (pChild) {
        Tile* pNext2;
        if (reinterpret_cast<::TileListBoxCalls *>((pChild))->GetFloat(0xfa8) != ::_DAT_01012060 || (pNext2 = ((Tile*)pChild)->m_pParent, pNext2 == ::Interface::GetPrimaryInterfaceTile()))
            fTotal += reinterpret_cast<::TileListBoxCalls *>((pChild))->GetFloat(0xfad);
        pChild = ((Tile*)pChild)->m_pParent;
    }
    return fTotal;
}

namespace sa040a0 {

struct Child {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    Child* m_pkNext;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    unsigned int m_uiValue1;
};

struct Owner {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    Child* m_pkFirst;

    bool IsAllChildrenFlag0();
};

// Walks the m_pkFirst linked list of Child nodes and returns true if no node has bit 0 of m_uiValue1 set.
// @fnv 0x00a040a0
bool Owner::IsAllChildrenFlag0()
{
    Child* pkChild = m_pkFirst;
    bool bFound = false;
    while (!bFound && pkChild)
    {
        bFound |= (unsigned char)((pkChild->m_uiValue1 & 1) ? 1 : 0);
        pkChild = pkChild->m_pkNext;
    }
    return bFound == 0;
}

}


// @fnv 0x00a04510
void FUN_00a04510()
{
    int iCount;
    {
    void* xelem;
    {
    Tile* ptile;
    {
    int iTemp;
    {
    int aiPad[16];
    {
    int iPad2;
    {
    unsigned int uiFlags1;
    {
    unsigned int uiFlags2;
    iTemp = DAT_011f3320;
    iCount = DAT_011f32d4 + iTemp;
    if (iCount > 10)
        return;
    iCount = 11 - iCount;
    xelem = *(void**)&(*reinterpret_cast<::XL *>(&::DAT_011f3324));
    while (xelem && iCount)
    {
        ptile = (Tile*)((DListNodeView*)xelem)->m_pItem;
        if (ptile)
        {
            if (0)
            {
                ((Tile*)ptile)->m_uiFlags |= 0x800;
                uiFlags1 = ((Tile*)ptile)->m_uiFlags;
            }
            else
            {
                ((Tile*)ptile)->m_uiFlags &= ~0x800;
                uiFlags1 = ((Tile*)ptile)->m_uiFlags;
            }
            if (1)
            {
                ((Tile*)ptile)->m_uiFlags |= 0x1000;
                uiFlags2 = ((Tile*)ptile)->m_uiFlags;
            }
            else
            {
                ((Tile*)ptile)->m_uiFlags &= ~0x1000;
                uiFlags2 = ((Tile*)ptile)->m_uiFlags;
            }
            ::FUN_00a07690((::FlaggedTile *)(ptile));
        }
        (*reinterpret_cast<::XL *>(&::DAT_011f3324)).RemovePos(xelem);
        iCount = iCount - 1;
    }

    }

    }

    }

    }

    }

    }

    }
}

struct FUN_00bb79d0_class
{
    char pad00[0xac];
    bool m_bAc;
    void FUN_00bb79d0(bool value);
};

// @fnv 0x00bb79d0
void FUN_00bb79d0_class::FUN_00bb79d0(bool value)
{
    m_bAc = value;
}


struct NiPoint3;

struct NiPoint2;

struct NiBound
{
    float m_fCenter[3];
    float m_fBoundRadius;
};

struct SharedData_S
{
    char pad[0xc];
    int m_uiRefCount;
    void DecRefCount()
    {
        if (--m_uiRefCount == 0)
        {
            reinterpret_cast<::FUN_00a8a670_shell *>(this)->FUN_00a8a670();
            ::FUN_00aa1460(this, 0x10);
        }
    }
};

struct GeomData_S
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual SharedData_S* GetShared();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual unsigned short GetActiveVertexQuantity();
    int pad04;
    unsigned short m_usVertices;
    unsigned short pad0a;
    unsigned short m_usTrianglePoints;
    unsigned short pad0e;
    NiBound m_kBound;
    NiPoint3* m_pkVertex;
    NiPoint3* m_pkNormal;
    RgbaColor* m_pkColor;
    NiPoint2* m_pkTexture;
    void FUN_00a670c0(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, RgbaColor* pkColor,
                      NiPoint2* pkTexture, unsigned short usNumTextureSets, unsigned short eNBTMethod);
};

// @fnv 0x00a670c0
void GeomData_S::FUN_00a670c0(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal, RgbaColor* pkColor,
                              NiPoint2* pkTexture, unsigned short usNumTextureSets, unsigned short eNBTMethod)
{
    if (GetShared())
    {
        if (pkVertex != m_pkVertex)
            GetShared()->DecRefCount();
        if (pkNormal != m_pkNormal)
            GetShared()->DecRefCount();
        if (pkColor != m_pkColor)
            GetShared()->DecRefCount();
        if (pkTexture != m_pkTexture)
            GetShared()->DecRefCount();
    }
    else
    {
        if (pkVertex != m_pkVertex)
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(m_pkVertex);
        if (pkNormal != m_pkNormal)
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(m_pkNormal);
        if (pkColor != m_pkColor)
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(m_pkColor);
        if (pkTexture != m_pkTexture)
            reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(m_pkTexture);
    }
    m_usVertices = usVertices;
    m_pkVertex = pkVertex;
    m_pkNormal = pkNormal;
    unsigned short usActive = GetActiveVertexQuantity();
    if (usActive && m_pkVertex)
        reinterpret_cast<::Bound88 *>(&(m_kBound))->ComputeBoundingSphere(usActive, (const ::Vec88 *)(m_pkVertex));
    m_pkColor = pkColor;
    m_pkTexture = pkTexture;
    m_usTrianglePoints = (m_usTrianglePoints & 0xffe) | (usNumTextureSets & 1) | eNBTMethod;
}



class NiProperty;













struct FUN_00a08720_t {
    void FUN_00a08720(NiAVObject* apObject, float afPct);
};

// @fnv 0x00a08720
void FUN_00a08720_t::FUN_00a08720(NiAVObject* apObject, float afPct)
{
    NiNode* pnode2;
    unsigned int i;
    TileShaderProperty* ptsp;
    if (!apObject)
        return;
    pnode2 = apObject->IsSceneNode();
    for (i = 0; pnode2 && i < (&pnode2->GetChildren())->m_usSize; i++)
        FUN_00a08720((&pnode2->GetChildren())->GetAt(i), afPct);
    if (apObject->IsGeometry()) {
        ptsp = ((::TileShaderProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)apObject)))->FUN_00a59d30(3)));
        if (ptsp)
            ((TileShaderPropertyView*)ptsp)->m_fAlpha = afPct;
    }
}



struct SoundPlaybackHandle {
    void Clear();
    bool SchedulePlayback(unsigned int, int);
    bool Pause();
    int GetSoundType();
    float GetVolume();
    bool SetFrequency(float);
    bool SetPlaybackFrequency(float);
    bool SetFrequencyVariance(unsigned char);
    bool SetBalance(int);
    bool SetStaticAttenuation(unsigned short);
    int GetDuration();
    bool SetPosition(void*);
    bool SetPosition(float, float, float);
    bool SetBeamEnd(void*);
    bool SetBeamEnd(float, float, float);
    void SetDistanceRange(float, float);
    void SetSoundParameters(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void SetReverbAttenuation(unsigned short);
    bool SetBeamStart(float, float, float);
    unsigned int GetID();
    void Seek(unsigned int);
    void SetFollowsListener(bool);
    void SetCompletionCallback(int*, void*);
    void SetPlayCallback(int*, void*);
    static void SetAddMovingSoundCallback(int*);
    bool Release();
    bool StopWithFade(unsigned int);
    bool SetPlaybackTime(unsigned int);
    void SetTimeConstraints(unsigned char, unsigned char);
    void SetSynchStartTime(unsigned int);
    void IsSoundPlaying();
    void SetPriority(unsigned int);
    void SetAssumeSuccess(bool);
    int QState();
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    char _pad_5[3];
    int eState;
public:
    ::SoundPlaybackHandle &operator=(const ::SoundPlaybackHandle &);
public:
    bool IsPlaying() const;
public:
    bool IsValid() const;
};

struct FUN_00a0b110_shell : public Tile {
    void FUN_00a0b110(int);
};

struct BSSoundHandleEx {
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;

    BSSoundHandleEx() : m_uiSoundResourceID(0xffffffff), m_bLooping(false), eState(0) {}
    ~BSSoundHandleEx() {}

    BSSoundHandleEx& operator=(const BSSoundHandleEx& rhs) {
        m_uiSoundResourceID = rhs.m_uiSoundResourceID;
        m_bLooping = rhs.m_bLooping;
        eState = rhs.eState;
        return *this;
    }

};

struct BSAudio {
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};

inline BSAudio* GetAudio() {
    return DAT_011f6d98;
}

extern int DAT_01094e1c;

struct S00a0d390
{
    void* f0;
    int f4;
    void* f8;
    void FUN_00a0d390();
};

// @fnv 0x00a0d390
void S00a0d390::FUN_00a0d390()
{
    int pad1;
    int pad2;
    f0 = &DAT_01094e1c;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(f8);
}



// @fnv 0x00a0b110
void FUN_00a0b110_shell::FUN_00a0b110(int aiSoundType) {
    BSSoundHandleEx soundHand;
    const char* strSoundName = reinterpret_cast<FUN_00a011f0_shell*>(this)->FUN_00a011f0(aiSoundType);
    Menu* pmenu = reinterpret_cast<::FUN_00a03c90_shell *>(this)->FUN_00a03c90();

    if (pmenu && pmenu->m_iMenuState == 1 && strSoundName && *strSoundName) {
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(soundHand))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)(GetAudio()->GetSoundHandleByEditorID(strSoundName, 0x121))));
        reinterpret_cast<::FUN_00ad8830_shell *>(&(soundHand))->FUN_00ad8830(false);
    }
}

struct AutoTileLock_Local {
    AutoTileLock_Local() { FUN_00a044f0(); }
    ~AutoTileLock_Local() { ::fnv_00a04500::FUN_00a04500(); }
};

struct Tile_Helper {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int GetType();
};

struct TileMenu {
    char pad[0x3c];
    Menu* pMenu;
};

// @fnv 0x00a03c90
Menu* FUN_00a03c90_shell::FUN_00a03c90() {
    AutoTileLock_Local __my_auto_tile_lock;
    Tile* ptile = reinterpret_cast<FUN_00a03d40_shell*>(this)->FUN_00a03d40();
    if (ptile && reinterpret_cast<Tile_Helper*>(ptile)->GetType() == 0x389) {
        TileMenu* pmenu = (TileMenu*)ptile;
        if (pmenu)
            return pmenu->pMenu;
    }
    return 0;
}











// @fnv 0x00a0abe0
FUN_00a0abe0::~FUN_00a0abe0() {
    void* arg;
    void* local1;
    void* local2;
    if (member_0c) {
        local2 = member_10->member_18;
        member_0c->member_28 = ::tileext::FUN_00a01630((::tileext::ExtraNode *)(local2));
        Member0C* p = member_0c;
        p->member_2c = 0;
    }
    member_0c = 0;
}

struct Tile__TileTemplate {
    void Clear();
};

struct NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___ {
    ~NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___() {}
    void RemoveAll();
};

struct ItemList : NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___ {
    ~ItemList() {
        reinterpret_cast<::S_00ae8370_List *>(this)->FUN_00ae8370();
    }
};

struct BSFixedString_Local {
    char* m_str;
    ~BSFixedString_Local() {
        if (m_str == ::DAT_0109b220) {
        } else {
            long* p = &((StringHeader*)m_str - 1)->refs;
            InterlockedDecrement(p);
        }
    }
};

struct FUN_00a0c190 : Tile__TileTemplate {
    BSFixedString_Local m_str;
    ItemList m_items;

    ~FUN_00a0c190();
};

// @fnv 0x00a0c190
FUN_00a0c190::~FUN_00a0c190() {
    int v1; int v2; int v3;
    reinterpret_cast<::fnv_00a0ab70::OH2TileTemplate *>(this)->ClearList();
}

struct TileValue_00a0a270 {
    void FUN_00a0a270(float afValue, bool abClearActions);
};

struct TileValueOwner_00a01000 {
};



// @fnv 0x00a012d0
void FUN_00a012d0_t::FUN_00a012d0(int aiTrait, float afValue, bool abClearActions)
{
    TileValue_00a0a270* pvalue = ((::TileValue_00a0a270 *)(reinterpret_cast<::fnv_00a01000::FUN_00a01000_shell *>((((TileValueOwner_00a01000*)this)))->GetOrCreateTraitValue(aiTrait)));
    if (pvalue != 0)
    {
        AutoTileLock_Local __my_auto_tile_lock;
        pvalue->FUN_00a0a270(afValue, abClearActions);
    }
}

namespace fnv_00a01350 {
struct EmptyPolymorphicObject {
    void* __vecDelDtor(unsigned int);
    char _pad_0[1];
};


struct FUN_00a01350_Value;
struct FUN_00a01350_Obj {
};
struct FUN_00a01350_Value {
};

// @fnv 0x00a01350
void FUN_00a01350_shell::FUN_00a01350(int aiTrait, char* apValue, bool abClearActions)
{
    FUN_00a01350_Value* pvalue = ((::fnv_00a01350::FUN_00a01350_Value *)(reinterpret_cast<::fnv_00a01000::FUN_00a01000_shell *>((((FUN_00a01350_Obj*)this)))->GetOrCreateTraitValue(aiTrait)));
    if (pvalue) {
        AutoTileLock_Local __my_auto_tile_lock;
        reinterpret_cast<::fnv_00a0a300::TileValueStr *>((pvalue))->SetString(apValue, abClearActions);
    }
}
}

// namespace fnv_00a01350

class ScrapHeapBuffer;

template<class K, class V> struct BSMapEntry {
    BSMapEntry* m_pkNext;
    K m_key;
    V m_val;
};

template<class K, class V> struct BSMapBase {
    virtual ~BSMapBase();
    virtual unsigned int KeyToHashIndex(K key);
    virtual bool IsKeysEqual(K key1, K key2);
    unsigned int m_uiHashSize;
    BSMapEntry<K, V>** m_ppkHashTable;
    bool GetAt(K key, V& val)
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        BSMapEntry<K, V>* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem) {
            if (IsKeysEqual(pkItem->m_key, key)) {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
};

extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f32f4;

// @fnv 0x00a01860
intptr_t FUN_00a01860(const char* apText)
{
    AutoTileLock_Local __my_auto_tile_lock;
    int iret = 0x80000000;
    reinterpret_cast<::S_00adc830_Map *>(&(DAT_011f32f4))->GetAt((unsigned long)apText, (::S_00adc830_Entry *&)((ScrapHeapBuffer*&)iret));
    return iret;
}

namespace fnv_00a03da0 {
struct EmptyPolymorphicObject {
    void* __vecDelDtor(unsigned int);
    char _pad_0[1];
};
struct FUN_00a03da0_shell : public Tile {
    Tile* FUN_00a03da0(char*);
};


struct TileChildNode {
    TileChildNode* m_pkNext;
    TileChildNode* m_pkPrev;
    Tile* m_element;
};

struct TileChildList {
    TileChildNode* m_pkHead;
    TileChildNode* m_pkTail;
    unsigned int m_uiCount;
    TileChildNode* GetHeadPos() const { return m_pkHead; }
    Tile*& GetNext(TileChildNode*& kPos) const {
        Tile*& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
};

struct TileNameString {
    char* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
    char* c_str() const { return m_data; }
};

// @fnv 0x00a03da0
Tile* FUN_00a03da0_shell::FUN_00a03da0(char* apName)
{
    AutoTileLock_Local __my_auto_tile_lock;
    TileChildNode* xelem = ((TileChildList*)(&((Tile*)this)->m_kChildren))->GetHeadPos();
    while (xelem && apName) {
        Tile* ptile = ((TileChildList*)(&((Tile*)this)->m_kChildren))->GetNext(xelem);
        if (((TileNameString*)&ptile->m_kName)->c_str() &&
            !::std::strcmp(((TileNameString*)&ptile->m_kName)->c_str(), apName)) {
            return ptile;
        } else {
            Tile* pchild = ((FUN_00a03da0_shell*)ptile)->FUN_00a03da0(apName);
            if (pchild) {
                return pchild;
            }
        }
    }
    return 0;
}
}

// namespace fnv_00a03da0

namespace fnv_00a03f70 {
struct EmptyPolymorphicObject {
    void* __vecDelDtor(unsigned int);
    char _pad_0[1];
};
struct FUN_00a03f70_shell : public Tile {
    Tile* FUN_00a03f70(int, int*);
};

struct TileParent_00a03f70 {
    char pad[0x28];
    Tile* pParent;
    Tile* GetParent() { return pParent; }
};
struct TileAction_00a03f70 {
    virtual void v0();
    virtual Tile::Value* GetValue();
    int m_iValueId;
    TileAction_00a03f70* pNext;
};

// @fnv 0x00a03f70
Tile* FUN_00a03f70_shell::FUN_00a03f70(int aiTrait, int* aiType)
{
    AutoTileLock_Local __my_auto_tile_lock;
    Tile::Value* pvalue = ((::Tile::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>(this)->FUN_00a00f30(aiTrait)));
    Tile* preturnTile = 0;
    if (pvalue) {
        TileAction_00a03f70* pcurrAction = (TileAction_00a03f70*)pvalue->pAction;
        bool bfound = false;
        while (pcurrAction && !bfound) {
            if (pcurrAction->m_iValueId == 0x7e7 && pcurrAction->GetValue()) {
                preturnTile = pcurrAction->GetValue()->pTile;
                *aiType = pcurrAction->GetValue()->m_iValueId;
                bfound = true;
            }
            pcurrAction = pcurrAction->pNext;
        }
    }
    else if (((TileParent_00a03f70*)this)->GetParent()) {
        return ((FUN_00a03f70_shell*)((TileParent_00a03f70*)this)->GetParent())->FUN_00a03f70(aiTrait, aiType);
    }
    return preturnTile;
}
}



struct TileListNode_00a087d0 {
    TileListNode_00a087d0* m_pkNext;
    TileListNode_00a087d0* m_pkPrev;
    Tile* m_element;
};

TileListNode_00a087d0* NewItem_00a087d0();

struct TileChildList_00a087d0 {
    TileListNode_00a087d0* m_pkHead;
    TileListNode_00a087d0* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const { return m_pkHead; }
    Tile* GetNext(void*& kPos) const {
        Tile** pElement = &((TileListNode_00a087d0*)kPos)->m_element;
        kPos = ((TileListNode_00a087d0*)kPos)->m_pkNext;
        return *pElement;
    }
    void FUN_00a0ca70(void* kPos, Tile* const& element) {
        TileListNode_00a087d0* pkNode = NewItem_00a087d0();
        TileListNode_00a087d0* pkA = 0;
        TileListNode_00a087d0* pkB = 0;
        TileListNode_00a087d0* pkC = 0;
        pkNode->m_element = element;
        TileListNode_00a087d0* pkPrev = (TileListNode_00a087d0*)kPos;
        pkA = pkB = pkC = pkPrev;
        pkNode->m_pkPrev = pkPrev;
        pkNode->m_pkNext = pkPrev->m_pkNext;
        if (pkPrev->m_pkNext) pkPrev->m_pkNext->m_pkPrev = pkNode; else m_pkTail = pkNode;
        pkPrev->m_pkNext = pkNode;
        m_uiCount++;
    }
    void FUN_00a0c9f0(Tile* const& element) {
        TileListNode_00a087d0* pkNode = NewItem_00a087d0();
        TileListNode_00a087d0* pkA = 0;
        TileListNode_00a087d0* pkB = 0;
        TileListNode_00a087d0* pkC = 0;
        TileListNode_00a087d0* pkD = 0;
        pkA = pkB = pkC = pkD = pkNode;
        pkNode->m_element = element;
        pkNode->m_pkNext = 0;
        pkNode->m_pkPrev = m_pkTail;
        if (m_pkTail) m_pkTail->m_pkNext = pkNode; else m_pkHead = pkNode;
        m_pkTail = pkNode;
        m_uiCount++;
    }
};

struct TileFlags_00a087d0 {
    char pad[0x30];
    unsigned int uiFlags;
    bool GetFlag(unsigned int uiFlag) const { return !!(uiFlags & uiFlag); }
};

template<> class NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*> {
public:
    TileListNode_00a087d0* m_pkHead;
    TileListNode_00a087d0* m_pkTail;
    unsigned int m_uiCount;
    Script* Remove(Script*& element) {
        TileListNode_00a087d0* pkNode = m_pkHead;
        TileListNode_00a087d0* pkFound = 0;
        TileListNode_00a087d0* pkPrev = 0;
        TileListNode_00a087d0* pkNext = 0;
        Script* pResult = 0;
        unsigned int ItemUpdateArray = 0;
        while (pkNode) {
            if ((Script*)pkNode->m_element == element) { pkFound = pkNode; break; }
            pkNode = pkNode->m_pkNext;
        }
        if (!pkFound) return 0;
        pkPrev = pkFound->m_pkPrev;
        pkNext = pkFound->m_pkNext;
        if (pkPrev) pkPrev->m_pkNext = pkNext; else m_pkHead = pkNext;
        if (pkNext) pkNext->m_pkPrev = pkPrev; else m_pkTail = pkPrev;
        pResult = (Script*)pkFound->m_element;
        ItemUpdateArray = m_uiCount;
        m_uiCount = ItemUpdateArray - 1;
        NewItem_00a087d0();
        return pResult;
    }
};

typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*> ScriptList_00a087d0;

// @fnv 0x00a087d0
void FUN_00a087d0_shell::FUN_00a087d0(Tile* apParent, Tile* apReplacedTile)
{
    if (((Tile*)this)->m_pParent && !((TileFlags_00a087d0*)((Tile*)this)->m_pParent)->GetFlag(0x2000)) {
        reinterpret_cast<::FUN_00a012d0_t *>(((((Tile*)this)->m_pParent)))->FUN_00a012d0(0xfb6, (float)(reinterpret_cast<::TileListBoxCalls *>(((((Tile*)this)->m_pParent)))->GetFloat(0xfb6) - 1.0), true);
        ((ScriptList_00a087d0*)(&((Tile*)this)->m_pParent->m_kChildren))->Remove(const_cast<Script*&>(static_cast<Script* const&>((Script*)(Tile*)this)));
    }
    ((Tile*)this)->m_pParent = apParent;
    if (((Tile*)this)->m_pParent) {
        reinterpret_cast<::FUN_00a012d0_t *>(((((Tile*)this)->m_pParent)))->FUN_00a012d0(0xfb6, (float)(reinterpret_cast<::TileListBoxCalls *>(((((Tile*)this)->m_pParent)))->GetFloat(0xfb6) + 1.0), true);
        if (apReplacedTile) {
            void* xelem;
            void* xlast_elem;
            bool got_it = false;
            xlast_elem = 0;
            xelem = ((TileChildList_00a087d0*)(&((Tile*)this)->m_pParent->m_kChildren))->GetHeadPos();
            while (xelem) {
                xlast_elem = xelem;
                Tile* pitem = ((TileChildList_00a087d0*)(&((Tile*)this)->m_pParent->m_kChildren))->GetNext(xelem);
                if (pitem == apReplacedTile) {
                    ((ScriptList_00a087d0*)(&((Tile*)this)->m_pParent->m_kChildren))->Remove(const_cast<Script*&>(static_cast<Script* const&>((Script*)(Tile*)this)));
                    reinterpret_cast<::S00a0ca70_List *>((((TileChildList_00a087d0*)(&((Tile*)this)->m_pParent->m_kChildren))))->FUN_00a0ca70((::S00a0ca70_Node **)(xlast_elem), (const unsigned int *)&(const ::Tile *const &)(this));
                    got_it = true;
                    break;
                }
            }
            if (!got_it)
                reinterpret_cast<::S_00a0c9f0 *>((((TileChildList_00a087d0*)(&((Tile*)this)->m_pParent->m_kChildren))))->FUN_00a0c9f0((int *)&(const ::Tile *const &)(this));
        } else {
            reinterpret_cast<::S_00a0c9f0 *>((((TileChildList_00a087d0*)(&((Tile*)this)->m_pParent->m_kChildren))))->FUN_00a0c9f0((int *)&(const ::Tile *const &)(this));
        }
    }
}

struct TileCollection : FUN_00a0c190 {
    ~TileCollection() { int a; int b; int c; int d; int e; }
};

struct FUN_00a0ad40 {
    TileCollection* pTemplate;
    BSSimpleList<TileCollection*> xList;
    int iUnk0C;
    bool bOwns;
    ~FUN_00a0ad40();
};

// @fnv 0x00a0ad40
FUN_00a0ad40::~FUN_00a0ad40()
{
    if (pTemplate)
        delete pTemplate;
    iUnk0C = 0;
    if (bOwns) {
        BSSimpleList<TileCollection*>* pCurrentElementNext = &xList;
        while (pCurrentElementNext) {
            TileCollection* ptemp = pCurrentElementNext->m_item;
            if (ptemp)
                delete ptemp;
            pCurrentElementNext = pCurrentElementNext->m_pkNext;
        }
    }
    reinterpret_cast<::Node185 *>(&(xList))->FUN_00ae83e0();
}

namespace fnv_00a0b8d0 {
struct BSStr {
    void Clear() { reinterpret_cast<::TextString *>(this)->FUN_004037f0(0, 0); }
    ~BSStr() { Clear(); }
};
struct MemoryManager {
    void Deallocate(void*);
    static MemoryManager& GetSingleton();
};
inline void MemFree(void* p) { reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a0b8d0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(p); }
struct TileElement {
    int m_uiSoundID;
    int iType;
    BSStr kValue;
    ~TileElement() { char acBuffer[28]; }
    static void operator delete(void* p) { MemFree(p); }
};
extern TileElement* DAT_011f329c[10];
extern unsigned int DAT_011f32dc;
// @fnv 0x00a0b8d0
void __cdecl FUN_00a0b8d0(TileElement* apItem)
{
    if (DAT_011f32dc < 10) {
        DAT_011f329c[DAT_011f32dc] = apItem;
        DAT_011f32dc++;
    } else {
        delete apItem;
    }
}
}

// namespace fnv_00a0b8d0

void __cdecl FUN_009ff8a0(char const*, int);

extern int DAT_011a6d74;

extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f32f4;

// @fnv 0x00a00940
int __cdecl FUN_00a00940(char const* apString, int aiIndex)
{
    AutoTileLock_Local __my_auto_tile_lock;
    ScrapHeapBuffer* pData = 0;

    if (reinterpret_cast<::S_00adc830_Map *>(&(DAT_011f32f4))->GetAt(reinterpret_cast<unsigned long>(apString), (::S_00adc830_Entry *&)(pData)))
        return static_cast<int>(reinterpret_cast<std::uintptr_t>(pData));

    if (aiIndex == -1)
    {
        aiIndex = DAT_011a6d74;
        DAT_011a6d74 = DAT_011a6d74 + 1;
    }

    if (aiIndex >= 10000 && ::Tile::IsSpecialTileName(apString))
    {
        FUN_009ff8a0(apString, aiIndex);
        return aiIndex;
    }

    return 0x80000000;
}

class ScrapMapShell {
public:
};

class ScrapListShell {
public:
    void Add(int aiValue, ScrapHeapBuffer* apHeap);
};

struct FrameLocals {
    int unk00;
    int unk18;
    int unk1C;
    int unk20;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ScrapHeapBuffer* heap;
};

extern ScrapListShell DAT_011f3308;

// @fnv 0x009ff8a0
void __cdecl FUN_009ff8a0(char const* apName, int aiValue)
{
    FrameLocals locals;
    if (apName == 0 || *apName == 0) {
        return;
    }
    AutoTileLock_Local lock;
    reinterpret_cast<::FUN_00a0c900_shell *>((reinterpret_cast<ScrapMapShell*>(&DAT_011f32f4)))->FUN_00a0c900(apName, aiValue);
    if (::Tile::IsSpecialTileName(apName) && aiValue >= 10000) {
        if (DAT_011a6d74 <= aiValue) {
            DAT_011a6d74 = aiValue + 1;
        }
        locals.heap = ((::ScrapHeapBuffer *)(::FUN_00a01a20(apName)));
        if (locals.heap != 0) {
            reinterpret_cast<::FUN_00a0c6c0_cls *>(&(DAT_011f3308))->InsertOrUpdate(aiValue, (::AnimSequenceBase *)(locals.heap));
        }
    }
}

struct TileChildNode;
struct TileObject {
    void* unk00;
    TileChildNode* unk04;
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
    unsigned int uiFlags;
    bool GetFlag(unsigned int uiFlag) const { return !!(uiFlags & uiFlag); }
    void FUN_00a00b50();
};

struct TileChildNode {
    TileChildNode* pkNext;
    TileChildNode* pkPrev;
    TileObject* pTile;
};

// @fnv 0x00a00b50
void TileObject::FUN_00a00b50() {
    AutoTileLock_Local lock;
    if (!GetFlag(0x2000) && !GetFlag(0x4000)) {
        uiFlags |= 0x4000;
        TileChildNode* iter = unk04;
        TileChildNode* current = iter;
        while (current) {
            TileObject** pChild = &current->pTile;
            current = current->pkNext;
            (*pChild)->FUN_00a00b50();
        }
    }
}

struct MapIterator_00a0c850 {
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    BSMapEntry<unsigned long, ScrapHeapBuffer*>** m_ppkHashTable;
    void FUN_00a0c850(void** position, ScrapHeapBuffer** value, unsigned int* key) {
        typedef BSMapEntry<unsigned long, ScrapHeapBuffer*> Entry;
        Entry* current = (Entry*)*position;
        *key = current->m_key;
        *value = current->m_val;
        *position = current->m_pkNext;
        if (*position != 0) return;
        unsigned int bucket = ((BSMapBase<unsigned long, ScrapHeapBuffer*>*)this)->KeyToHashIndex(*key);
        for (++bucket; bucket < m_uiHashSize; ++bucket) {
            if (m_ppkHashTable[bucket] != 0) {
                *position = m_ppkHashTable[bucket];
                break;
            }
        }
    }
};

__forceinline BSMapEntry<unsigned long, ScrapHeapBuffer*>* FindFirstHeapEntry(
    BSMapBase<unsigned long, ScrapHeapBuffer*>& map)
{
    unsigned int bucketIndex = 0;
    for (; bucketIndex < map.m_uiHashSize; ++bucketIndex) {
        if (map.m_ppkHashTable[bucketIndex] != 0)
            return map.m_ppkHashTable[bucketIndex];
    }
    return 0;
}

// @fnv 0x00a01a70
ScrapHeapBuffer* __cdecl FUN_00a01a70(unsigned int requestedKey) {
    ScrapHeapBuffer* result;
    unsigned int key;
    void* position = FindFirstHeapEntry(DAT_011f32f4);
    while (position) {
        reinterpret_cast<::RecursiveLock *>((((MapIterator_00a0c850*)&DAT_011f32f4)))->Unlock((::BSCriticalSectionEntry **)(void **)(&position), (unsigned int *)(::ScrapHeapBuffer **)(&result), &key);
        if (key == requestedKey) return result;
    }
    return 0;
}

struct TileLockGuard {
    TileLockGuard() { FUN_00a044f0(); }
    ~TileLockGuard() { ::fnv_00a04500::FUN_00a04500(); }
};

struct FlaggedTile {
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
    unsigned int uiFlags;
    bool GetFlag(unsigned int uiFlag) const { return (uiFlags & uiFlag) != 0; }
    template<unsigned int F> void SetFlag(bool abSet) {
        abSet ? (uiFlags |= F) : (uiFlags &= ~F);
    }
};

struct TileListNode {
    TileListNode* m_pkNext;
    TileListNode* m_pkPrev;
    FlaggedTile* m_element;
};

TileListNode* NewTileListNode();

void FreeTileListNode(TileListNode* apNode);

struct TileList {
    TileListNode* m_pkHead;
    TileListNode* m_pkTail;
    unsigned int m_uiCount;
    void AddTail(FlaggedTile* const& element) {
        TileListNode* pkNode = NewTileListNode();
        TileListNode* pkA = 0;
        pkA = pkNode;
        pkNode->m_element = element;
        pkNode->m_pkNext = 0;
        pkNode->m_pkPrev = m_pkTail;
        if (m_pkTail) m_pkTail->m_pkNext = pkNode; else m_pkHead = pkNode;
        m_pkTail = pkNode;
        m_uiCount++;
    }
    FlaggedTile* Remove(FlaggedTile*& element) {
        TileListNode* pkNode = m_pkHead;
        TileListNode* pkFound = 0;
        TileListNode* pkPrev = 0;
        TileListNode* pkNext = 0;
        FlaggedTile* pResult = 0;
        unsigned int ItemUpdateArray = 0;
        TileListNode* pkX = 0;
        TileListNode* pkY = 0;
        TileListNode* pkZ = 0;
        pkX = pkY = pkZ = pkFound;
        while (pkNode) {
            if (pkNode->m_element == element) { pkFound = pkNode; break; }
            pkNode = pkNode->m_pkNext;
        }
        if (!pkFound) return 0;
        pkPrev = pkFound->m_pkPrev;
        pkNext = pkFound->m_pkNext;
        if (pkPrev) pkPrev->m_pkNext = pkNext; else m_pkHead = pkNext;
        if (pkNext) pkNext->m_pkPrev = pkPrev; else m_pkTail = pkPrev;
        pResult = pkFound->m_element;
        ItemUpdateArray = m_uiCount;
        m_uiCount = ItemUpdateArray - 1;
        FreeTileListNode(pkFound);
        return pResult;
    }
};

extern TileList g_kPendingTiles;

extern TileList g_kRemovedTiles;

// @fnv 0x00a07690
void __cdecl FUN_00a07690(FlaggedTile* apTile) {
    if (!apTile) return;
    TileLockGuard kLock;
    if (!apTile->GetFlag(0x400)) {
        reinterpret_cast<::FUN_004ed8c0_shell *>(&(g_kPendingTiles))->FUN_004ed8c0((int *)&(apTile));
        apTile->SetFlag<0x400>(true);
    }
    if (apTile->GetFlag(0x800)) {
        g_kRemovedTiles.Remove(apTile);
        apTile->SetFlag<0x800>(false);
    }
}

class A0B1F0Tile {
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
    ChildPtr<NiNode> m_spNode;

    NiNode* GetNode() const { return m_spNode; }
    TileShaderProperty* FUN_00a0b1f0();
};

static inline NiAVObject* A0B1F0GetChild(NiNode* pkNode, unsigned int uiIndex) {
    if (uiIndex >= pkNode->GetChildren().m_usSize)
        return 0;
    else
        return pkNode->GetChildren().GetAt(uiIndex);
}

// @fnv 0x00a0b1f0
TileShaderProperty* A0B1F0Tile::FUN_00a0b1f0() {
    TileShaderProperty* pkProperty = 0;
    NiNode* pkNode = GetNode();
    NiAVObject* pkCurrentObject = pkNode ? A0B1F0GetChild(pkNode, 0) : 0;
    if (pkCurrentObject)
        pkProperty = ((::TileShaderProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((reinterpret_cast<PropHelper*>(pkCurrentObject)))->FUN_00a59d30(3)));
    return pkProperty;
}

extern int DAT_01094d9c;

class FUN_00a0d220_pool {
public:
    void FUN_00aa4060(void* apMemory);
};

struct FUN_00a0d220_frame {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

struct FUN_00a0d220_cls {
    const void* m_vptr;
    int unk04;


    FUN_00a0d220_cls* FUN_00a0d220(unsigned int auiFlags);
};

// Claim: clm_0814eff69ec3418ebf5d -> FUN_00a0d280 (0x00a0d280, 24 bytes)
// Flags: /MT /Od /Oy- /GS /EHsc /Gy /Ob1
//
// Shape: a tiny member of the tile-template class.  The body only
// forwards to a method of the sub-object that lives at this+0x0C.  MSVC /Od
// spills 'this' into the frame (the slot sits below every named local) and
// reloads it with the sub-object adjustment right before the call:
//
//   push ebp / mov ebp,esp / sub esp,0x20
//   mov  [ebp-0x20],ecx
//   mov  ecx,[ebp-0x20]
//   add  ecx,0x0C
//   call FUN_0043a010
//
// The 0x20 frame comes from the 0x1C-byte scratch area the original kept in
// the frame, so the same-sized local is declared here.



// Callee reached through the embedded sub-object at this+0x0C.
struct Sub_0043a010 {
};

// 0x1C bytes of scratch space held in the caller's frame.
struct TileScratch_00a0d280 {
    int m_iScratch00;
    int m_iScratch04;
    int m_iScratch08;
    int m_iScratch0C;
    int m_iScratch10;
    int m_iScratch14;
    int m_iScratch18;
};

// Stand-in for the owning class: 0x0C bytes of leading members, then the
// embedded sub-object whose method is invoked.
struct FUN_00a0d280_cls {
    int m_00;
    int m_04;
    int m_08;
    Sub_0043a010 m_sub;

    void FUN_00a0d280();
};

// @fnv 0x00a0d280
void FUN_00a0d280_cls::FUN_00a0d280()
{
    TileScratch_00a0d280 scratch;
    (void)scratch;
    reinterpret_cast<::FUN_0043a010_shell *>(&(m_sub))->FUN_0043a010();
}

struct MM {
    void* Allocate(unsigned int auiSize);
};

class TileTemplate_00a0ae70 {
public:
    const char* m_name;
    void* m_pOwnerObject;
    int m_unk08;
    int m_unk0c;
    int m_unk10;

    TileTemplate_00a0ae70(const char* apName, void* apOwner) {
        m_name = ::DAT_0109b220;
        m_unk10 = 0;
        m_unk08 = 0;
        m_unk0c = 0;
        if (m_name != apName) {
            const char* pOld = m_name;
            m_name = NiGlobalStringTable::AddString(apName);
            if (pOld != ::DAT_0109b220) {
                InterlockedDecrement(&((StringHeader*)pOld - 1)->refs);
            }
        }
        m_pOwnerObject = apOwner;
    }
};

struct TemplateList_00a0ae70 {
    TileTemplate_00a0ae70* m_item;
    TemplateList_00a0ae70* m_pkNext;

    TemplateList_00a0ae70(TileTemplate_00a0ae70* apItem) : m_item(apItem), m_pkNext(0) {}

    void AddTail(TileTemplate_00a0ae70** apItem) {
        if (*apItem == 0) return;
        TemplateList_00a0ae70* pkNode = this;
        while (pkNode->m_pkNext != 0) {
            pkNode = pkNode->m_pkNext;
        }
        if (pkNode->m_item != 0) {
            TemplateList_00a0ae70* pkNew = new TemplateList_00a0ae70(*apItem);
            pkNode->m_pkNext = pkNew;
        } else {
            pkNode->m_item = *apItem;
        }
    }
};

struct Storage_00a0ae70 {
    int m_unk00;
    TemplateList_00a0ae70 m_kNode;
    TileTemplate_00a0ae70* m_pTileTemplate;
    bool m_owns;

    TileTemplate_00a0ae70* FUN_00a0ae70(const char* apName);
};

// @fnv 0x00a0ae70
TileTemplate_00a0ae70* Storage_00a0ae70::FUN_00a0ae70(const char* apName)
{
    TileTemplate_00a0ae70* pTemplate = new TileTemplate_00a0ae70(apName, this);
    m_kNode.AddTail(&pTemplate);
    return pTemplate;
}

struct TileShaderProperty { void FUN_00bb7a10(NiTexture* apTexture); };

struct A0B020Child {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
};

struct A0B020Node { A0B020Node* m_pkNext; A0B020Node* m_pkPrev; A0B020Child* m_element; };

struct A0B020List {
    A0B020Node* m_pkHead;
    A0B020Node* GetHeadPos() const { return m_pkHead; }
    A0B020Child*& GetNext(A0B020Node*& pos) { A0B020Child*& r = pos->m_element; pos = pos->m_pkNext; return r; }
};

class A0B020Tile {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual int GetType();
    A0B020List m_kChildList;
    int unk, unk0C, unkCur, unkValue, uNewnk, unk1C, uTmpnk, unk24, unk28;
    ChildPtr<NiNode> m_spNode;
    NiNode* GetNode() const { return m_spNode; }
    void FUN_00a0b020();
};

// @fnv 0x00a0b020
void A0B020Tile::FUN_00a0b020()
{
    A0B020Node* pos2;
    NiAVObject* pNewkChild;
    TileShaderProperty* pkProp;
    A0B020Child* pkTile;
    if (GetNode())
    {
        pNewkChild = A0B1F0GetChild(GetNode(), 0);
        if (GetType() == 0x386 && pNewkChild)
        {
            pkProp = ((::TileShaderProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((((PropHelper*)pNewkChild)))->FUN_00a59d30(3)));
            if (pkProp)
            {
                pkProp->FUN_00bb7a10(0);
                ((FUN_00a07530_shell*)this)->FUN_00a07530(0x20);
            }
        }
    }
    pos2 = m_kChildList.GetHeadPos();
    while (pos2)
    {
        pkTile = m_kChildList.GetNext(pos2);
        if (!((FUN_00a03c90_shell*)pkTile)->FUN_00a03c90()) pkTile->v07();
    }
}

extern int DAT_011f32dc;

extern void* DAT_011f329c[];

struct StrMem_00a0ba50 {
};

struct Item_00a0ba50 {
    int unk00;
    int unk04;
    StrMem_00a0ba50 m_str;
    int unk10;
    int unk14;

    ~Item_00a0ba50()
    {
        // The string helper's own frame slots stay reserved when its body is inlined away.
        char* pNewData;
        unsigned int uiNewLen;
        unsigned int uiOldLen;
        unsigned int uiMaxLen;
        char* pReferenceEntry;
        char* pNewText;
        int iExtra;
        int iAllocSize;
        reinterpret_cast<::TextString *>(&(m_str))->FUN_004037f0(0, 0);
    }

};

// @fnv 0x00a0ba50
void __cdecl FUN_00a0ba50()
{
    while (DAT_011f32dc-- != 0) {
        Item_00a0ba50* pItem = (Item_00a0ba50*)DAT_011f329c[DAT_011f32dc];
        delete pItem;
    }
    DAT_011f32dc = 0;
}

extern "C" void __cdecl FUN_00a04500();

struct TileSearchLock {
    TileSearchLock() { FUN_00a044f0(); }
    ~TileSearchLock() { ::fnv_00a04500::FUN_00a04500(); }
};

struct TileFloatList {
    void* m_vtbl;
    NiTListItem<Tile*>* m_pkHead;
    NiTListItem<Tile*>* GetHeadPos() const { return m_pkHead; }
    Tile*& GetNext(NiTListItem<Tile*>*& kPos) {
        Tile*& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
    Tile* FUN_00a03eb0(int iValue);
};

// @fnv 0x00a03eb0
Tile* TileFloatList::FUN_00a03eb0(int iValue)
{
    TileSearchLock kLock;
    NiTListItem<Tile*>* kPos = GetHeadPos();
    while (kPos) {
        Tile* pkTile = GetNext(kPos);
        if (reinterpret_cast<::TileListBoxCalls *>((pkTile))->GetFloat(0xfaa) == iValue)
            return pkTile;
    }
    return 0;
}

struct TilePool_ac80 {
    void* FUN_00aa3e40(unsigned int auiSize);
};

struct TileTemplateList_ac80 {
    TileCollection* m_item;
    TileTemplateList_ac80* m_pkNext;
    TileTemplateList_ac80() { m_item = 0; m_pkNext = 0; }
    ~TileTemplateList_ac80();
};

struct FixedString_ac80 {
    char* m_str;
    FixedString_ac80() { m_str = ::DAT_0109b220; }
    ~FixedString_ac80();
    FixedString_ac80& operator=(const char* apString) {
        if (m_str != apString) {
            char* iOld = m_str;
            m_str = NiGlobalStringTable::AddString(apString);
            if (iOld == ::DAT_0109b220) {
            } else {
                long* p = &((StringHeader*)iOld - 1)->refs;
                InterlockedDecrement(p);
            }
        }
        return *this;
    }
};

struct TemplateItemList_ac80 {
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    TemplateItemList_ac80() { m_uiCount = 0; m_pkHead = 0; m_pkTail = 0; }
    ~TemplateItemList_ac80();
};

struct TileTemplateNew_ac80 {
    FixedString_ac80 m_kName;
    void* m_pkOwnerManager;
    TemplateItemList_ac80 m_kUnsortedGeometryList;
    TileTemplateNew_ac80(const char* apName, void* apOwner) {
        m_kName = apName;
        m_pkOwnerManager = apOwner;
    }
};

struct FUN_00a0ac80 {
    TileCollection* pTemplate;
    TileTemplateList_ac80 xList;
    int iUnk0C;
    bool bOwns;
    FUN_00a0ac80();
};

// @fnv 0x00a0ac80
FUN_00a0ac80::FUN_00a0ac80()
{
    pTemplate = (TileCollection*)new TileTemplateNew_ac80("main", this);
    iUnk0C = 0;
    bOwns = true;
}

void FUN_00a044f0();

void FUN_00a04500();

class TileV;

class TileItemV
{
public:
    TileItemV* m_pkNext;
    TileItemV* m_pkPrev;
    TileV* m_element;
};

class TileValueV
{
public:
    int m_iValueId;
    TileValueV* m_pkNext;
    float fValue;
    const char* pString;
};

class FnvTileLock
{
public:
    FnvTileLock() { FUN_00a044f0(); }
    ~FnvTileLock() { ::fnv_00a04500::FUN_00a04500(); }
};

inline bool HasValue(TileValueV* pList, int m_iValueId)
{
    while (pList != 0 && pList->m_iValueId != m_iValueId)
        pList = pList->m_pkNext;
    return pList != 0;
}

class TileV : public FUN_00a07530_shell
{
public:
    int unk00;
    TileItemV* m_pkChildList;
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
    unsigned int unk30;
    TileItemV* GetHeadPos() { return m_pkChildList; }
    TileV*& GetNext(TileItemV*& pos) { TileV*& element = pos->m_element; pos = pos->m_pkNext; return element; }
    float GetFloat(int);
    void FUN_00a0b420(TileValueV* pValues, float fValue);
};

// @fnv 0x00a0b420
void TileV::FUN_00a0b420(TileValueV* pValues, float fValue)
{
    FnvTileLock aKLock;
    float f = reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xff4);
    if (f == 0.0)
        f = fValue;
    {
    int iValue3 = (int)f;
    if (HasValue(pValues, iValue3))
        FUN_00a07530(8);
    }
    TileItemV* pkIter = GetHeadPos();
    while (pkIter)
        GetNext(pkIter)->FUN_00a0b420(pValues, f);
}

struct Vec { float x,y,z; Vec() {} Vec(float a,float b,float c):x(a),y(b),z(c) {} Vec operator+(const Vec& v) const { return Vec(x+v.x,y+v.y,z+v.z); } Vec operator-(const Vec& v) const { return Vec(x-v.x,y-v.y,z-v.z); } };

struct Mat { float m00,m01,m02,m10,m11,m12,m20,m21,m22; void FUN_0043f850(float angle) { float sn,cs; FUN_004169a0(angle,sn,cs); float negativeSin=-sn; float cosine=cs; m00=cosine; m01=0; m02=negativeSin; m10=0; m11=1; m12=0; m20=sn; m21=0; m22=cosine; } Vec FUN_004b4500(const Vec* v) { return Vec(m00*v->x+m01*v->y+m02*v->z,m10*v->x+m11*v->y+m12*v->z,m20*v->x+m21*v->y+m22*v->z); } };

struct Rtti { const char* name; Rtti* parent; };

struct Scene {
 virtual void v0(); virtual void v1(); virtual Rtti* GetRTTI();
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
 Mat rotation; Vec translation;
 int unk64;
 int unk68;
 int unk6c;
 int unk70;
 int unk74;
 int unk78;
 int unk7c;
 int unk80;
 int unk84;
 int unk88;
 int unk8c;
 int unk90;
 int unk94;
 int unk98;
 int unk9c;
 Scene** children; unsigned short capacity; unsigned short size; unsigned short count;
 __forceinline Scene*& At(unsigned index) { return children[index]; }
 __forceinline unsigned Count() { return count; }
};

__forceinline void TranslateScene(Scene* object, Mat& rotation, const Vec& center, const Vec& pivot) {
 object->translation=(center+pivot)-rotation.FUN_004b4500(&pivot);
}
__forceinline void ReadSceneType(Scene* object, Rtti*& type, bool& valid) {
 type=object->GetRTTI();
 while(type) { if(type==&(*reinterpret_cast<::Rtti *>(&::g_011f4a40))) {valid=true;return;} type=type->parent; }
 valid=false;
}

struct TileWork;

struct Link { Link* next; Link* prev; TileWork* item; };

struct TileWorkList { Link* head; __forceinline Link* First() { return head; }
__forceinline TileWork* Next(Link*& pos) { TileWork** data=&pos->item; pos=pos->next; return *data; } };

struct TileWork {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual int Kind();
 Link* children;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 Scene* model;
 __forceinline Scene* Model() {return model;}
 void FUN_00a0b520();
};

// @fnv 0x00a0b520
void TileWork::FUN_00a0b520() {
 float local37;
 float local35;
 bool valid_31;
 Rtti* type3;
 Scene* objectX;
 Scene** sceneEntryX;
 Scene* model_2;
 Scene* node1;
 TileWork** local14;
 Link* first;
 Mat rotationA;
 Vec pivotA;
 Scene* found;
 unsigned indexB;
 Vec center;
 float depth_;
 Scene* rootUpdate6;
 float yg1;
 float heightSquaredX;
 float cy5;
 float cx2;
 float widthTmp;
 float x15;
 TileWork* childVal5;
 Link* pos2;
 first=children; pos2=first;
 while(pos2) {
 local14=&pos2->item; pos2=pos2->next; childVal5=*local14;
 if(childVal5) {
 x15=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(4001);
 yg1=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(4002);
 widthTmp=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(4091);
 heightSquaredX=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(4092);
 cx2=reinterpret_cast<::TileListBoxCalls *>((childVal5))->GetFloat(4001);
 cy5=reinterpret_cast<::TileListBoxCalls *>((childVal5))->GetFloat(4002);
 if(reinterpret_cast<::FUN_00a01230_shell *>(this)->IsTraitNonZero(4008)) { cx2+=x15; cy5+=yg1; }
 reinterpret_cast<::FUN_00a012d0_t *>((childVal5))->FUN_00a012d0(4091,x15+widthTmp-cx2,true);
 reinterpret_cast<::FUN_00a012d0_t *>((childVal5))->FUN_00a012d0(4092,yg1+heightSquaredX-cy5,true);
 reinterpret_cast<::FUN_00a012d0_t *>((childVal5))->FUN_00a012d0(4090,reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(4090),true);
 if(reinterpret_cast<::FUN_00a01230_shell *>((childVal5))->IsTraitNonZero(4008) && childVal5->Kind()==902) {
 depth_=reinterpret_cast<::TileListBoxCalls *>((childVal5))->GetFloat(4013);
 center=(*reinterpret_cast<const ::Vec *>((void *)&::NiPoint3::ZERO));
 node1=childVal5->model; node1->translation=center;
 center.x+=reinterpret_cast<::TileListBoxCalls *>((childVal5))->GetFloat(4001);
 center.z+=-reinterpret_cast<::TileListBoxCalls *>((childVal5))->GetFloat(4002);
 center.y+=depth_*DAT_0106f290;
 model_2=childVal5->model; rootUpdate6=model_2;
 for(indexB=0;rootUpdate6 && indexB<rootUpdate6->count;++indexB) {
 sceneEntryX=&rootUpdate6->children[indexB]; objectX=*sceneEntryX;
 if(!objectX) found=0;
 else {
 ReadSceneType(objectX,type3,valid_31);
 found=valid_31?objectX:0;
 }
 local37=reinterpret_cast<::TileListBoxCalls *>((childVal5))->GetFloat(4091);
 local35=-reinterpret_cast<::TileListBoxCalls *>((childVal5))->GetFloat(4092);
 {pivotA.x=local37; pivotA.y=0; pivotA.z=local35;}

 reinterpret_cast<::ThreeByThreeMatrix *>(&(rotationA))->SetYRotation(reinterpret_cast<::TileListBoxCalls *>((childVal5))->GetFloat(4090));
 if(found) {
 found->rotation=rotationA;
 TranslateScene(found,rotationA,center,pivotA);
 }
 }
 }
 childVal5->FUN_00a0b520();
 }
 }
}

inline unsigned int BSStringCapacityMaximum(unsigned int a, unsigned int b) { return a > b ? a : b; }



struct ReuseString {
    char* pString;
    unsigned short length;
    unsigned short capacity;
    ReuseString() { Init(); }
    void Init() { pString = 0; SetLength(0); SetMaxLength(0); }
    ~ReuseString() { reinterpret_cast<::TextString *>(this)->FUN_004037f0(0, 0); }
    void SetLength(unsigned int n) { length = n <= 65535 ? (unsigned short)n : 65535; }
    void SetMaxLength(unsigned int n) { capacity = n <= 65535 ? (unsigned short)n : 65535; }
    ReuseString& operator=(const char* str) { reinterpret_cast<::TextString *>(this)->FUN_004037f0(str, 0); return *this; }
    unsigned int MaxLength() { return capacity; }
    bool Set(const char* text, unsigned int size) {
        unsigned int newLength = text ? ::FUN_0044a670(text) : 0;
        unsigned int newCapacity = ::FUN_00403940(newLength, size);
        if (newCapacity <= MaxLength()) {
            if (newCapacity) {
                if (text) memcpy(pString, text, newLength + 1);
                else pString[0] = 0;
            } else {
                if (pString) { char* oldData = pString; delete oldData; }
                pString = 0;
                newCapacity = 0;
                SetMaxLength(newCapacity);
            }
        } else {
            char* oldString = pString;
            char* newString = new char[newCapacity + 1];
            pString = newString;
            if (text) memcpy(pString, text, newLength + 1);
            else pString[0] = 0;
            if (oldString) delete oldString;
            SetMaxLength(newCapacity);
        }
        SetLength(newLength);
        return newLength != 0;
    }
};

struct ReuseNode {
    int trait;
    float value;
    ReuseString text;
    std::intptr_t flags;
    void* owner;
    ReuseNode(int a, float f, const char* s, int b, void* c) {
        trait = a;
        value = f;
        reinterpret_cast<::TextString *>(&(text))->FUN_004037f0(s, 31);
        flags = b;
        owner = c;
    }
    void Init(int a, float f, const char* s, int b, void* c) {
        trait = a;
        value = f;
        text = s;
        flags = b;
        owner = c;
    }
};



// @fnv 0x00a0b950
ReuseNode* FUN_00a0b950(int a, float f, const char* s, int b, void* c) {
    ReuseNode* node;
    if ((unsigned int)DAT_011f32dc > 0) {
        DAT_011f32dc = DAT_011f32dc - 1;
        node = (ReuseNode*)DAT_011f329c[DAT_011f32dc];
        node->Init(a, f, s, b, c);
    } else {
        node = new ReuseNode(a, f, s, b, c);
    }
    return node;
}

struct Sub_00a0c020 {
    int unk00;
    int unk04;
    float unk08;

    float GetVal() { return unk08; }
};

struct Target_00a0c020 {
    int unk00;
    int unk04;
    int unk08;
    Sub_00a0c020* unk0c;

    float FUN_00a0c020();
};

// @fnv 0x00a0c020
float Target_00a0c020::FUN_00a0c020() {
    return unk0c ? unk0c->GetVal() : 0.0f;
}

struct S00ac5490_Str {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void Init(int a, int b);
    S00ac5490_Str* Set(const S00ac5490_Str* src, int a, void* g);
    __forceinline S00ac5490_Str(const S00ac5490_Str& o) {
        int e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17;
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(0, 0);
        Set(&o, 0, (*reinterpret_cast<void * *>(&::g_010173f0)));
    }
    ~S00ac5490_Str() { int g1, g2, g3, g4, g5; reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(1, 0); }
};

struct S00ac5490_Base {
    int unk04;
    S00ac5490_Base(S00ac5490_Str s);
    virtual ~S00ac5490_Base();
};

struct FUN_00ac5490 : public S00ac5490_Base {
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
    FUN_00ac5490(S00ac5490_Str a);
};

// @fnv 0x00ac5490
FUN_00ac5490::FUN_00ac5490(S00ac5490_Str a) : S00ac5490_Base(a)
{
    int d1;
    unk40 = 0;
    unk44 = 0;
}

struct _RTL_CRITICAL_SECTION;

class FUN_009ff340;

struct S009ff340_List { int FUN_0057c730(FUN_009ff340* const& p); };

extern char DAT_011f3330;

extern S009ff340_List DAT_011f3318;

extern S009ff340_List DAT_011f3324;

extern int DAT_011f32d8;

extern char str_01093f44[];

struct S009ff340_RefObj {
    virtual ~S009ff340_RefObj();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
    void DecRefCount() { if (!InterlockedDecrement(&m_iObjectReferenceCount)) DeleteThis(); }
};

struct S009ff340_Ptr {
    S009ff340_RefObj* m_obj;
    ~S009ff340_Ptr() { if (m_obj) m_obj->DecRefCount(); }
};

struct S009ff340_Str {
    int unk00;
    int unk04;
    int unk08;
    ~S009ff340_Str() { int scratch[13]; reinterpret_cast<::TextString *>(this)->FUN_004037f0((const char *)(0), 0); }
};

struct S009ff340_M10 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~S009ff340_M10() { reinterpret_cast<::fnv_00709eb0::FUN_00709eb0_Class *>(this)->InitAndClear(); }
};

void __cdecl S_00a04150_Free(void*);

struct S_00a04150_Elem {
    virtual ~S_00a04150_Elem();
};

struct S_00a04150_Node {
    S_00a04150_Node* m_pkNext;
    S_00a04150_Node* m_pkPrev;
    S_00a04150_Elem* m_element;
};

struct S_00a04150_List {
    S_00a04150_Node* m_pkHead;
    S_00a04150_Node* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const { return m_pkHead; }
    S_00a04150_Elem* GetNext(void*& kPos) const {
        S_00a04150_Elem*& element = ((S_00a04150_Node*)kPos)->m_element;
        kPos = ((S_00a04150_Node*)kPos)->m_pkNext;
        return element;
    }
    void FUN_004ed900() {
        S_00a04150_Node* pkDel;
        S_00a04150_Node* pkNext;
        S_00a04150_Node* pkPrev;
        S_00a04150_Node* pkCur;
        unsigned int ItemUpdateArray;
        while (m_pkHead) {
            pkDel = m_pkHead;
            pkCur = pkDel;
            pkNext = pkCur->m_pkNext;
            pkPrev = pkCur->m_pkPrev;
            m_pkHead = pkNext;
            if (pkNext) pkNext->m_pkPrev = pkPrev;
            pkDel->m_element = 0;
            S_00a04150_Free(pkDel);
            ItemUpdateArray = m_uiCount;
            m_uiCount = ItemUpdateArray - 1;
        }
        m_pkTail = 0;
    }
};

struct S009ff340_Empty {
    int unk00;
    ~S009ff340_Empty() {}
};

struct S009ff340_Base04 {
    int unk00;
    int unk04;
    S009ff340_Empty e;
    ~S009ff340_Base04() { reinterpret_cast<S_00a04150_List*>(this)->FUN_004ed900(); }
};

inline void S009ff340_Detach(S009ff340_RefObj* p) { int scratch[10]; ::FUN_00c45830((::MyRef *)(p)); }

class FUN_009ff340 : public S009ff340_Base04 {
public:
    virtual ~FUN_009ff340();
    S009ff340_M10 m10;
    S009ff340_Str m20;
    S009ff340_Ptr m2c;
    unsigned int flags;
    bool GetFlag(unsigned int m) { return (flags & m) != 0; }
    template<unsigned int M> void SetFlag(bool b) { b ? (flags |= M) : (flags &= ~M); }
    void FUN_009ff690();
    
};

// @fnv 0x009ff340
FUN_009ff340::~FUN_009ff340()
{
    EnterCriticalSection((_RTL_CRITICAL_SECTION*)&DAT_011f3330);
    ::ClearInterfaceRefs((unsigned int)(this));
    if (!GetFlag(0x2000)) {
        ::FUN_005b5e40();
        FUN_009ff690();
    }
    if (GetFlag(0x400))
        DAT_011f3318.FUN_0057c730(this);
    SetFlag<0x400>(false);
    if (DAT_011f3324.FUN_0057c730(this) && GetFlag(0x800))
        --DAT_011f32d8;
    SetFlag<0x800>(false);
    SetFlag<0x1000>(false);
    S009ff340_Detach(m2c.m_obj);
    LeaveCriticalSection((_RTL_CRITICAL_SECTION*)&DAT_011f3330);
}

namespace fnv_009ff690 {
__forceinline int GetMemoryContext() { return (*reinterpret_cast<int *>(&::currentAllocationContext)); }
__forceinline void SetMemoryContext(int context) { (*reinterpret_cast<int *>(&::currentAllocationContext)) = context; }
struct MemoryContextGuard {
    int previous;
    __forceinline MemoryContextGuard(int context) {
        previous = GetMemoryContext();
        SetMemoryContext(context);
    }
    __forceinline ~MemoryContextGuard() { SetMemoryContext(previous); }
};
void __cdecl FUN_00a044f0();
void __cdecl FUN_00a04500();
struct TileReleaseLock { __forceinline ~TileReleaseLock() { ::fnv_00a04500::FUN_00a04500(); } };
struct XmlAllocator {
    void* FUN_00aa3e40(unsigned int bytes);
    void FUN_00aa4060(void* memory);
};
struct ReleaseValue {
    __forceinline ~ReleaseValue();
};
struct ReleaseArray {
    void* vtable;
    ReleaseValue** buffer;
    unsigned int size;
    unsigned int capacity;
    __forceinline unsigned int GetSize() { return size; }
    inline void DestroyElements(ReleaseValue**, unsigned int count) {
        for (unsigned int index = 0; index < count; ++index) {}
    }
    void FreeStorage();
    inline void FUN_008454f0(bool freeMemory) {
        if (buffer) {
            DestroyElements(buffer, size);
            if (freeMemory) { FreeStorage(); buffer = 0; capacity = 0; }
            size = 0;
        }
    }
};
struct ReleaseNode {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void RemoveObject(ReleaseNode*);
    unsigned int references;
    void* name;
    void* extraData;
    unsigned short extraSize;
    unsigned short extraCapacity;
    unsigned int flags;
    ReleaseNode* parent;
    __forceinline ReleaseNode* GetParent() { return parent; }
};
struct ReleaseChild { virtual ~ReleaseChild(); };
struct ReleaseLink { ReleaseLink* next; ReleaseLink* prev; ReleaseChild* value; };
struct ChildPoolBlock { ChildPoolBlock* next; void* data; };
extern ChildPoolBlock* DAT_011c5f58;
unsigned int __cdecl gm_GetCurrentThreadId();
void __cdecl FUN_0040fca0(unsigned long);
void __cdecl FUN_0040fbe0(...);
struct ChildPoolLock {
    volatile long thread;
    unsigned int depth;
    inline void Lock(const char*) {
        unsigned int id = gm_GetCurrentThreadId();
        if (thread == id) ++depth;
        else {
            unsigned int retries = 0;
            while (FUN_0043b460(&thread, 0, id)) {
                ++retries;
                if (retries > 10000) FUN_0040fca0(1);
                else FUN_0040fca0(0);
            }
            FUN_0040fbe0();
            depth = 1;
        }
    }
    void Unlock();
};
extern ChildPoolLock g_011c5f80;
struct ChildAllocator {
    unsigned int count;
    __forceinline void Deallocate(void* pointer) {
        g_011c5f80.Lock(0);
        ChildPoolBlock* block = (ChildPoolBlock*)pointer;
        block->data = 0;
        block->next = DAT_011c5f58;
        DAT_011c5f58 = block;
        g_011c5f80.Unlock();
    }
};
struct ReleaseChildren {
    ReleaseLink* head; ReleaseLink* tail; ChildAllocator allocator;
    __forceinline unsigned int GetCount() { return allocator.count; }
    __forceinline void DeleteItem(ReleaseLink* item) {
        item->value = 0;
        allocator.Deallocate(item);
    }
    inline ReleaseChild* PopFrontScript() {
        ReleaseLink* old = head;
        head = head->next;
        if (head) head->prev = 0;
        else tail = 0;
        ReleaseChild* value = old->value;
        DeleteItem(old);
        --allocator.count;
        return value;
    }
};
struct ReleaseTile {
    void* vtable;
    ReleaseChildren children;
    ReleaseArray values;
    BSStringT<char> name;
    Tile* parent;
    NiPointer<ReleaseNode> node;
    unsigned int flags;
    void FUN_00a01750();
    void FUN_009ff690();
};
// @fnv 0x009ff690
void ReleaseTile::FUN_009ff690() {
    unsigned int i;
    MemoryContextGuard guard(13);
    ::FUN_00a044f0();
    TileReleaseLock lock;
    reinterpret_cast<::TileObject *>(this)->FUN_00a00b50();
    ::ClearInterfaceRefs((unsigned int)(this));
    flags |= 0x2000;
    FUN_00a01750();
    reinterpret_cast<::FUN_00a087d0_shell *>(this)->FUN_00a087d0(0, 0);
    for (i = 0; i < values.GetSize(); ++i) {
        delete values.buffer[i];
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(values))->Clear(true);
    reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>(this)->RemoveFadeItemsForTile(0x80000000);
    if (node && node->GetParent()) {
        node->GetParent()->RemoveObject(node);
    }
    while (children.GetCount()) {
        delete children.PopFrontScript();
    }
}
}

// namespace fnv_009ff690

namespace fnv_00a00a30 {
class MemoryManagerA00 {
public:
    void FUN_00aa4060(void* pvMem); // Deallocate
};


void __cdecl FUN_00a044f0(); // EnterCriticalSection on the menu lock
void __cdecl FUN_00a04500(); // LeaveCriticalSection

class TileTemplateA00 {
public:
    ~TileTemplateA00(); // FUN_00a0bb50
};

class FadeNodeA00 {
public:
};

template <class T> class SimpleListA00 {
public:
    ~SimpleListA00() {}

    void FUN_00ae83e0()
    {
        while (m_pkNext)
        {
            SimpleListA00<T>* pkNext = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            delete m_pkNext;
            m_pkNext = pkNext;
        }
        m_item = 0;
    }

    T m_item;
    SimpleListA00<T>* m_pkNext;
};

struct MapItemA00 {
    MapItemA00* m_pkNext;
    unsigned int m_key;
    void* m_val;
};

class MapA00 {
public:
    virtual ~MapA00();
    virtual unsigned int KeyToHashIndex(unsigned int key) const;
    virtual bool IsKeysEqual(unsigned int key1, unsigned int key2) const;
    virtual void SetValue(MapItemA00* pkItem, unsigned int key, void* val);
    virtual void ClearValue(MapItemA00* pkItem);
    virtual MapItemA00* NewItem();
    virtual void DeleteItem(MapItemA00* pkItem);

    void ClearAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItemA00* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }

    unsigned int m_uiHashSize;
    MapItemA00** m_ppkHashTable;
    unsigned int m_uiCount;
    int m_unk10;
};

extern MapA00 DAT_011f32f4;
extern MapA00 DAT_011f3308;
extern SimpleListA00<TileTemplateA00*> DAT_011f3350;
extern SimpleListA00<FadeNodeA00*> DAT_011f3348;

class MenuLockA00 {
public:
    MenuLockA00() { ::FUN_00a044f0(); }
    ~MenuLockA00() { ::fnv_00a04500::FUN_00a04500(); }
};

// @fnv 0x00a00a30
void __cdecl FUN_00a00a30()
{
    MenuLockA00 kLock;
    reinterpret_cast<::AE91F0Map *>(&(DAT_011f32f4))->ClearAll();
    reinterpret_cast<::AE91F0Map *>(&(DAT_011f3308))->ClearAll();

    for (SimpleListA00<TileTemplateA00*>* pkIter = &DAT_011f3350; pkIter && pkIter->m_item; pkIter = pkIter->m_pkNext)
    {
        delete pkIter->m_item;
    }
    reinterpret_cast<::Node185 *>(&(DAT_011f3350))->FUN_00ae83e0();

    for (SimpleListA00<FadeNodeA00*>* pkIter2 = &DAT_011f3348; pkIter2 && pkIter2->m_item; pkIter2 = pkIter2->m_pkNext)
    {
        delete pkIter2->m_item;
    }
    reinterpret_cast<::Node185 *>(&(DAT_011f3348))->FUN_00ae83e0();
}
}

// namespace fnv_00a00a30

namespace fnv_00a00c20 {
struct XmlAllocator {
    void* FUN_00aa3e40(unsigned int bytes);
    void FUN_00aa4060(void* memory);
};
struct NodeRef { void Assign(int); int value; };
struct SmallArray {
    void* data; unsigned short size; unsigned short capacity;
    __forceinline SmallArray(unsigned int count=0, unsigned int limit=0) {
        void* initialData = 0;
        unsigned int elementLimit = 0xffff;
        unsigned int initialSize = count > elementLimit ? elementLimit : count;
        unsigned int initialCapacity = limit > elementLimit ? elementLimit : limit;
        data = initialData; size = (unsigned short)initialSize; capacity = (unsigned short)initialCapacity;
    }
    ~SmallArray();
};
struct Tile3D {
    Tile3D();
    virtual ~Tile3D();
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; NodeRef unk2c; int unk30; int unk34; int unk38;
};
struct TileRect : Tile3D {
    __forceinline TileRect() {}
    virtual ~TileRect();
};
struct TileMenu : TileRect {
    __forceinline TileMenu() : unk3c(0) {}
    virtual ~TileMenu();
    int unk3c;
};
struct TileImage : Tile3D {
    TileImage();
    int unk3c; int unk40; int unk44;
};
struct TileText : Tile3D {
    __forceinline TileText(Tile3D* parent = 0) {
        if (parent) reinterpret_cast<::FUN_00a087d0_shell *>(this)->FUN_00a087d0((::Tile *)(parent), (::Tile *)(::fnv_00a00c20::Tile3D *)(0));
        unk48 = 0;
    }
    virtual ~TileText();
    int unk3c; int unk40; int unk44;
    char unk48;
};
struct FUN_00a0bc80 : Tile3D {
    inline FUN_00a0bc80() { unk2c.Assign(0); unk38=0; unk3c=0; }
    int unk3c; SmallArray first; SmallArray second;
};
struct FUN_00a21660 : TileImage {
    FUN_00a21660();
};
// @fnv 0x00a00c20
Tile* __cdecl FUN_00a00c20(int aiType)
{
    switch (aiType) {
    case 0x385: return (Tile*)new TileRect;
    case 0x386:
    case 0x38a: return (Tile*)new TileImage;
    case 0x388: return (Tile*)new FUN_00a0bc80;
    case 0x387: return (Tile*)new TileText;
    case 0x389: return (Tile*)new TileMenu;
    case 0x38c: return (Tile*)new FUN_00a21660;
    }
    return 0;
}
}

// namespace fnv_00a00c20

namespace tileext {

class ExtraObject {
public:
    virtual ~ExtraObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void* unk08;
    intptr_t m_iValue;
    void IncRefCount() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
    void DecRefCount() { if (!InterlockedDecrement((volatile long*)&m_uiRefCount)) DeleteThis(); }
};

extern const char* DAT_011f34cc;

void FUN_00a044f0();
void FUN_00a04500();

struct TileListLock {
    TileListLock() { ::FUN_00a044f0(); }
    ~TileListLock() { ::fnv_00a04500::FUN_00a04500(); }
};

struct ExtraNode {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ExtraNode* m_pParentNode;

    ExtraNode* GetParent() { return m_pParentNode; }
    static const char* GetKey() { return DAT_011f34cc; }
};

// @fnv 0x00a01630
intptr_t FUN_00a01630(ExtraNode* pkNode)
{
    TileListLock kLock;
    intptr_t iValue = 0;
    if (pkNode)
    {
        NiPointer<ExtraObject> spExtra = ((::tileext::ExtraObject *)(reinterpret_cast<::NiAVObject *>((pkNode))->GetExtraData((*(const ::NiFixedString *)(ExtraNode::GetKey())))));
        if (!spExtra && pkNode->GetParent())
            spExtra = ((::tileext::ExtraObject *)(reinterpret_cast<::NiAVObject *>((pkNode->GetParent()))->GetExtraData((*(const ::NiFixedString *)(ExtraNode::GetKey())))));
        if (spExtra)
            iValue = spExtra->m_iValue;
    }
    return iValue;
}

}

void __cdecl FUN_00a04500();

class MenuLockA01 {
public:
    MenuLockA01() { FUN_00a044f0(); }
    ~MenuLockA01() { ::fnv_00a04500::FUN_00a04500(); }
};

class RefObjectA01 {
public:
    virtual ~RefObjectA01();
    virtual void DeleteThis();

    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }

    long m_uiRefCount;
};

class ActionA01;

class ActionA01 : public RefObjectA01 {
public:
    int m_unk08;
    void* m_pkOwnerManager;
};

class ListA01 {
public:
    unsigned short GetCount() const { return m_usElementCount; }
    ActionA01* FindA(void* pKey) { return (ActionA01*)((::RefObjectA01 *)(reinterpret_cast<::NiAVObject *>(this)->GetExtraData((*(const ::NiFixedString *)(pKey))))); }
    ActionA01* FindN(void* pKey);
    RefObjectA01* FindR(void* pKey) { return ((::RefObjectA01 *)(reinterpret_cast<::NiAVObject *>(this)->GetExtraData((*(const ::NiFixedString *)(pKey))))); }

    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    unsigned short m_usElementCount;
};

extern void* DAT_011f34cc;

inline void* GetActionKeyA01() { return DAT_011f34cc; }

class TileA01 {
public:
    ListA01* GetList() const { return m_pkList; }
    ActionA01* FindAction(void* pKey) { ActionA01* pkFound = (ActionA01*)((::RefObjectA01 *)(reinterpret_cast<::NiAVObject *>((GetList()))->GetExtraData((*(const ::NiFixedString *)(pKey))))); return pkFound; }
    ActionA01* FindAction2() { ActionA01* pkFound = (ActionA01*)((::RefObjectA01 *)(reinterpret_cast<::NiAVObject *>((GetList()))->GetExtraData((*(const ::NiFixedString *)(GetActionKeyA01()))))); return pkFound; }
    void FUN_00a01750();

    int m_unk[11];
    ListA01* m_pkList;
};

inline void IncRefA01(ActionA01*& pkObject) { pkObject->IncRefCount(); }

inline void DecRefA01(ActionA01*& pkObject) { pkObject->DecRefCount(); }

inline ActionA01* ListA01::FindN(void* pKey)
{
    ActionA01* pkFound = (ActionA01*)((::RefObjectA01 *)(reinterpret_cast<::NiAVObject *>(this)->GetExtraData((*(const ::NiFixedString *)(pKey)))));
    return pkFound;
}

// @fnv 0x00a01750
void TileA01::FUN_00a01750()
{
    MenuLockA01 kLock;
    if (!GetList() || !GetList()->GetCount())
        return;

    NiPointer<ActionA01> spAction = (ActionA01*)((::RefObjectA01 *)(reinterpret_cast<::NiAVObject *>((GetList()))->GetExtraData((*(const ::NiFixedString *)(GetActionKeyA01())))));
    if (spAction)
        spAction->m_pkOwnerManager = 0;
}

namespace fnv_00a01e20 {
struct XmlAllocator {
    void* FUN_00aa3e40(unsigned int bytes);
    void FUN_00aa4060(void* memory);
};
struct FUN_00a0ac80;
typedef FUN_00a0ac80 XmlNode;
struct FUN_00a0ac80 {
    FUN_00a0ac80();
    XmlNode* m_pTreeNode;
    XmlNode* m_parent;
    XmlNode* m_iFirstChild;
    XmlNode* m_bSlotEnabled;
    unsigned int m_flags;
    void FUN_00a0a410(unsigned int kind, const char* name, unsigned int line, unsigned int flags);
};
struct XmlFile {
    unsigned int length;
    const char* data;
    ~XmlFile() {
        if (data) {
            const char* old = data;
            (*reinterpret_cast<::fnv_00a01e20::XmlAllocator *>(&::g_memoryManager)).FUN_00aa4060((void*)old);
        }
        data = 0;
    }
};
extern unsigned char DAT_011f32c8;
extern const char DAT_01094a08[];
extern const char DAT_01094a3c[];
extern const char DAT_010949f0[];
extern const char DAT_010949d8[];
extern const char DAT_010949b0[];
extern const char DAT_0109498c[];
extern const char DAT_01094970[];
extern const char DAT_01094934[];
extern const char DAT_01094904[];
extern const char DAT_010948dc[];
// @fnv 0x00a01e20
XmlNode* __cdecl FUN_00a01e20(const char* filename, const char* source, unsigned int sourceLength)
{
    XmlNode* root3 = 0;
    root3 = new XmlNode;
    XmlFile* sourceFile3 = 0;
    const char* text_2 = 0;
    unsigned int length = 0;
    int tokenLimit4 = 0x1000;
    int tokenLength3 = 0;
    if (source != 0) {
        text_2 = source;
        length = sourceLength;
    } else {
        sourceFile3 = ((::fnv_00a01e20::XmlFile *)(::GetOrLoadXML(filename, 0)));
        if (sourceFile3 != 0) {
            ::FUN_00a02d40((::Input02D40 *)(sourceFile3));
            text_2 = sourceFile3->data;
            length = sourceFile3->length;
        }
    }
    char value5[4096];
    char converted7[4096];
    char tag[128];
    value5[0] = 0;
    int aState = 0;
    int parameterType4 = 0;
    bool hasWhitespace8 = false;
    bool quotedB = false;
    bool kClosing = false;
    unsigned int line5 = 1;
    unsigned int offset_ = 0;
    for (offset_ = 0; offset_ < length; offset_++) {
        if (aState == 0) {
            if (text_2[offset_] == '<') {
                if (offset_ + 3 < length && text_2[offset_ + 1] == '!' &&
                    text_2[offset_ + 2] == '-' && text_2[offset_ + 3] == '-') {
                    hasWhitespace8 = false;
                    aState = 4;
                } else {
                    aState = 1;
                    tag[0] = 0;
                    kClosing = false;
                    tokenLength3 = 0;
                }
            }
        } else if (aState == 1) {
            if (tag[0] == 0 && text_2[offset_] == '/') {
                kClosing = true;
            } else if (text_2[offset_] == '>' ||
                       (offset_ + 1 < length && text_2[offset_] == '/' && text_2[offset_ + 1] == '>')) {
                if (tag[0] != 0 && kClosing) {
                    (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(1, tag, line5, 0);
                } else if (tag[0] != 0 && !kClosing) {
                    (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(0, tag, line5, 0);
                } else if (!hasWhitespace8) {
                    ::FUN_005b5e40();
                    DAT_011f32c8 = 1;
                    return 0;
                }
                tokenLength3 = 0;
                if (text_2[offset_] == '/')
                    aState = 2;
                else
                    aState = 3;
                hasWhitespace8 = false;
                line5++;
            } else if ((unsigned char)text_2[offset_] <= ' ') {
                if (tag[0] != 0) {
                    if (kClosing)
                        (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(1, tag, line5, 0);
                    else
                        (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(0, tag, line5, 0);
                    tokenLength3 = 0;
                    hasWhitespace8 = true;
                    line5++;
                }
            } else if (hasWhitespace8) {
                offset_--;
                aState = 5;
                hasWhitespace8 = false;
            } else {
                tag[tokenLength3] = text_2[offset_];
                tokenLength3++;
                tag[tokenLength3] = 0;
            }
        } else if (aState == 4) {
            if (offset_ + 2 < length && text_2[offset_] == '-' &&
                text_2[offset_ + 1] == '-' && text_2[offset_ + 2] == '>') {
                offset_ += 2;
                aState = 3;
                hasWhitespace8 = false;
            }
        } else if (aState == 5) {
            if (text_2[offset_] == '>' ||
                (offset_ + 1 < length && text_2[offset_] == '/' && text_2[offset_ + 1] == '>')) {
                ::FUN_005b5e40();
                DAT_011f32c8 = 1;
                return 0;
            } else if (text_2[offset_] == '=') {
                if (value5[0] == 0) {
                    ::FUN_005b5e40();
                    DAT_011f32c8 = 1;
                    return 0;
                }
                parameterType4 = ::FUN_00a01860(value5);
                value5[0] = 0;
                tokenLength3 = 0;
                aState = 6;
                hasWhitespace8 = false;
            } else if ((unsigned char)text_2[offset_] <= ' ') {
                if (value5[0] != 0) {
                    parameterType4 = ::FUN_00a01860(value5);
                    value5[0] = 0;
                    tokenLength3 = 0;
                    hasWhitespace8 = true;
                }
            } else if (hasWhitespace8) {
                ::FUN_005b5e40();
                DAT_011f32c8 = 1;
                return 0;
            } else {
                value5[tokenLength3] = text_2[offset_];
                tokenLength3++;
                value5[tokenLength3] = 0;
                if (tokenLength3 > tokenLimit4)
                    ::FUN_005b5e40();
            }
        } else if (aState == 6) {
            if (text_2[offset_] == '"') {
                quotedB = !quotedB;
            } else if (quotedB) {
                value5[tokenLength3] = text_2[offset_];
                tokenLength3++;
                value5[tokenLength3] = 0;
                if (tokenLength3 > tokenLimit4)
                    ::FUN_005b5e40();
            } else if (text_2[offset_] == '>' ||
                       (offset_ + 1 < length && text_2[offset_] == '/' && text_2[offset_ + 1] == '>')) {
                if (value5[0] != 0) {
                    (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(parameterType4, value5, line5, 0);
                } else if (!hasWhitespace8) {
                    ::FUN_005b5e40();
                    DAT_011f32c8 = 1;
                    return 0;
                }
                value5[0] = 0;
                tokenLength3 = 0;
                if (text_2[offset_] == '/')
                    aState = 2;
                else
                    aState = 3;
                hasWhitespace8 = false;
            } else if ((unsigned char)text_2[offset_] <= ' ') {
                if (value5[0] != 0) {
                    (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(parameterType4, value5, line5, 0);
                    value5[0] = 0;
                    tokenLength3 = 0;
                    hasWhitespace8 = true;
                }
            } else if (hasWhitespace8) {
                offset_--;
                aState = 5;
                hasWhitespace8 = false;
            } else {
                value5[tokenLength3] = text_2[offset_];
                tokenLength3++;
                value5[tokenLength3] = 0;
                if (tokenLength3 > tokenLimit4)
                    ::FUN_005b5e40();
            }
        } else if (aState == 2) {
            if (text_2[offset_] == '>') {
                (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(1, tag, line5, 0);
                aState = 3;
                tag[0] = 0;
            } else {
                ::FUN_005b5e40();
                DAT_011f32c8 = 1;
                return 0;
            }
        } else if (aState == 3) {
            if (text_2[offset_] == '<') {
                if (offset_ + 3 < length && text_2[offset_ + 1] == '!' &&
                    text_2[offset_ + 2] == '-' && text_2[offset_ + 3] == '-') {
                    hasWhitespace8 = false;
                    aState = 4;
                } else {
                    if (value5[0] != 0) {
                        for (tokenLength3 = ::std::strlen(value5) - 1;
                             (unsigned int)tokenLength3 >= 0 && (unsigned char)value5[tokenLength3] <= ' ';
                             tokenLength3--) {
                        }
                        value5[tokenLength3 + 1] = 0;
                        if (value5[0] == '&') {
                            if (value5[1] == '-') {
                                bool ok2 = ::fnv_007073d0::ResolveSettingString(value5, converted7);
                                if (ok2)
                                    (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(0xbb9, converted7, line5, 0);
                            } else {
                                (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(0xbb9, value5, line5, 0);
                            }
                        } else if (value5[0] != 0) {
                            (root3->m_bSlotEnabled ? root3->m_bSlotEnabled : root3->m_pTreeNode)->FUN_00a0a410(0xbb9, value5, line5, 1);
                        }
                    }
                    value5[0] = 0;
                    tokenLength3 = 0;
                    hasWhitespace8 = false;
                    kClosing = false;
                    aState = 1;
                    tag[0] = 0;
                }
            } else if (offset_ + 1 < length && text_2[offset_] == '/' && text_2[offset_ + 1] == '>') {
                ::FUN_005b5e40();
                DAT_011f32c8 = 1;
                return 0;
            } else if (text_2[offset_] == '>') {
                ::FUN_005b5e40();
                DAT_011f32c8 = 1;
                return 0;
            } else if ((unsigned char)text_2[offset_] > ' ' || hasWhitespace8 == true) {
                value5[tokenLength3] = text_2[offset_];
                tokenLength3++;
                value5[tokenLength3] = 0;
                if (tokenLength3 > tokenLimit4)
                    ::FUN_005b5e40();
                hasWhitespace8 = true;
            }
        }
    }
    if (sourceFile3)
        delete sourceFile3;
    return root3;
}
}

// namespace fnv_00a01e20

namespace fnv_00a04200 {
extern char DAT_011f3330;
inline int GetMemoryContext() { return (*reinterpret_cast<int *>(&::currentAllocationContext)); }
inline void SetMemoryContext(int value) { (*reinterpret_cast<int *>(&::currentAllocationContext)) = value; }
struct AutoMemContext {
    int previous;
    AutoMemContext(int value) { previous = GetMemoryContext(); SetMemoryContext(value); }
    ~AutoMemContext() { SetMemoryContext(previous); }
};
struct UpdateTreeNode {
    void* vtable;
    void* children;
    void* childTail;
    unsigned int childCount;
    void* values;
    unsigned int valueCount;
    unsigned int reservedValues;
    const char* name;
    void* unknown20;
    void* unknown24;
    void* pParent;
    void* GetParent() { void* parent = pParent; return parent; }
    void* model;
    unsigned int flags;
    unsigned char changed;
    bool FUN_00a04640(bool);
};
struct UpdateManager {
};
extern void* DAT_011f3320;
inline void* GetPendingTiles() { void* pending = DAT_011f3320; return pending; }
extern bool DAT_011f32c9;

// @fnv 0x00a04200
void __cdecl FUN_00a04200(bool update)
{
    AutoMemContext autoMemContext(13);
    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_011f3330));
    bool changed = false;
    DAT_011f32c9 = false;
    UpdateTreeNode* pTile;
    while (GetPendingTiles()) {
        pTile = ((::fnv_00a04200::UpdateTreeNode *)(::fnv_00a07580::FUN_00a07580(true)));
        if (!pTile || (pTile->flags & 0x6800) || !(pTile->flags & 0x3ff))
            continue;
        changed = pTile->FUN_00a04640(true);
        pTile->changed = pTile->changed | changed;
        if (changed)
            reinterpret_cast<::InterfaceManager *>(((*reinterpret_cast<::fnv_00a04200::UpdateManager * *>(&::DAT_011d8a80))))->AddTileIfAbsent((::Tile *)(pTile));
        if (pTile->GetParent() == ((void *)(::Interface::GetPrimaryInterfaceTile()))) {
            if (reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfa7) == 102.0)
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfa7, 6006.0f, true);
            else if (reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfa7) == 103.0)
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfa7, 6007.0f, true);
        }
    }
    if (DAT_011f32c9) {
        ::FUN_00a078e0();
        FUN_00a04200(update);
        LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_011f3330));
        return;
    }
    if (update) {
        AutoMemContext kRenderContext(13);
        reinterpret_cast<::TileModelsUpdateEntry *>(((*reinterpret_cast<::fnv_00a04200::UpdateManager * *>(&::DAT_011d8a80))))->FUN_00713e20();
    }
    if (::Interface::IsAnyMenuOpen()) {
        AutoMemContext refreshContext(13);
        ::FUN_00706db0(false);
        ::FUN_00a61cd0();
    }
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_011f3330));
}
}

// namespace fnv_00a04200

namespace fnv_00a07580 {
void __cdecl FUN_00a044f0();
void __cdecl FUN_00a04500();

struct LockGuard_00a07580 {
    LockGuard_00a07580() { ::FUN_00a044f0(); }
    ~LockGuard_00a07580() { ::fnv_00a04500::FUN_00a04500(); }
};

struct TileResult_00a07580 {
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
    unsigned int flags;
    void SetFlag(bool set) {
        int a1; int a2; int a3;
        set ? (flags |= 0x400) : (flags &= ~0x400);
    }
};

struct TileNode_00a07580 {
    TileNode_00a07580* next;
    void* prev;
    TileResult_00a07580* item;
};

struct TileQueue_00a07580 {
    TileNode_00a07580* head;
    int unk04;
    int count;
    TileResult_00a07580* PopFrontScript();
    bool IsEmpty() { return count == 0; }
    TileResult_00a07580* Front() { return head->item; }
};

extern TileQueue_00a07580 DAT_011f3318;

// @fnv 0x00a07580
TileResult_00a07580* FUN_00a07580(bool pop) {
    LockGuard_00a07580 guard;
    if (DAT_011f3318.IsEmpty()) {
        return 0;
    } else if (pop) {
        TileResult_00a07580* tile = DAT_011f3318.PopFrontScript();
        if (tile) {
            tile->SetFlag(false);
        }
        return tile;
    } else {
        return DAT_011f3318.Front();
    }
}
}

// namespace fnv_00a07580

struct ClipRect { int left, top, right, bottom; };

struct ClipProperty {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98;
    ClipRect clip;
};

struct ClipGeometry {  };

struct ClipArray;

inline void FUN_004afc80(ClipArray*);

struct ClipPointer {
    ClipGeometry* pointer;
    __forceinline ClipGeometry* operator->() { return pointer; }
};

struct ClipArray {
    void* vtable;
    ClipPointer* data;
    unsigned short capacity, size, count, grow;
    __forceinline ClipPointer& At(unsigned int index) { return data[index]; }
};

ClipPointer* __cdecl AllocateClipArray(unsigned int);

void __cdecl FreeClipArray(ClipPointer*);

inline void FUN_004afc80(ClipArray* array) {
    ClipPointer* oldData;
    unsigned short source;
    unsigned short destination;
    if (array->count == array->size) return;
    if (array->count) {
        destination = 0;
        for (source = 0; source < array->size; ++source) {
            if (array->data[source].pointer) {
                if (source != destination) array->data[destination] = array->data[source];
                ++destination;
            }
        }
    }
    oldData = array->data;
    array->capacity = array->size = array->count;
    if (array->capacity) {
        array->data = AllocateClipArray(array->capacity);
        for (source = 0; source < array->size; ++source)
            array->data[source] = oldData[source];
    } else array->data = 0;
    FreeClipArray(oldData);
}

struct ClipNode {
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98;
    ClipArray children;
};

struct ClipTile;

struct ClipListNode { ClipListNode* next; void* prev; ClipTile* item; };

struct ClipTile {
    void* vtable; ClipListNode* children;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    ClipNode* model;
    __forceinline ClipNode* Model() { return model; }
    void FUN_00a07a40(float left, float top, float right, float bottom);
};

__forceinline float ClipMax(float a, float b) { return a > b ? a : b; }

// @fnv 0x00a07a40
void ClipTile::FUN_00a07a40(float left, float top, float right, float bottom)
{
    ClipListNode* position;
    ClipTile* child;
    unsigned int index;
    ClipProperty* property;
    float width;
    float height;
    {
    ClipRect rect;
    ClipListNode* head = children;
    position = head;
    while (position) {
        ClipTile*& entry = position->item;
        position = position->next;
        child = entry;
        if (reinterpret_cast<::FUN_00a01230_shell *>((child))->IsTraitNonZero(0xfae)) {
            ClipNode* modelCheck = child->model;
            if (modelCheck) {
            index = 0;
            ClipNode* modelCompact = child->model;
            reinterpret_cast<::ObjPtrArray *>((&modelCompact->children))->FUN_004afc80();
            reinterpret_cast<::Pn4afe *>((&modelCompact->children))->TrimTrailingNullPointers();

            {
            while (index < child->Model()->children.count) {
                {
                property = ((::ClipProperty *)(reinterpret_cast<::FUN_00a59d30_C *>(((child->Model()->children.At(index)).operator->()))->FUN_00a59d30(3)));
                if (property) {
                    height = ::Interface::GetFourthInterfaceFloat();
                    width = ::Interface::GetThirdInterfaceFloat();
                    if (reinterpret_cast<::Tile *>(this)->IsMenuRendered()) {
                        height = FUN_00706e80();
                        width = FUN_00706e90();
                    }
                    rect.left = (int)ClipMax(left, 0.0f);
                    rect.top = (int)ClipMax(top, 0.0f);
                    rect.right = (int)(right < height ? right : height);
                    rect.bottom = (int)(bottom < width ? bottom : width);
                    property->clip = rect;
                    reinterpret_cast<::FUN_00bb79d0_class *>((property))->FUN_00bb79d0(true);
                }
                }
                ++index;
            }
        }
        }
        }
        child->FUN_00a07a40(left, top, right, bottom);
    }
    }
}

class SceneRefObject {
public:
    virtual ~SceneRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
    void DecRefCount() { if (!InterlockedDecrement((volatile long*)&m_uiRefCount)) DeleteThis(); }
};

class SceneNode;

class SceneParent {
public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void InsertChild(SceneNode* pkChild);
};

class SceneNode : public SceneRefObject {
public:
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    SceneParent* m_pParentNode;
    SceneParent* GetParent() { return m_pParentNode; }
};

class SceneNodeOwner {
public:
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
    NiPointer<SceneNode> m_spNode;
    SceneNode* GetNode() { return m_spNode; }
    void FUN_00a08a20();
};

// @fnv 0x00a08a20
void SceneNodeOwner::FUN_00a08a20()
{
    SceneNode* pkNode = GetNode();
    if (!pkNode)
        return;
    reinterpret_cast<::TileA01 *>(this)->FUN_00a01750();
    if (pkNode->GetParent())
        pkNode->GetParent()->InsertChild(pkNode);
    NiPointer<SceneNode> spHold = pkNode;
    m_spNode = 0;
    spHold = 0;
}

struct MenuArray {
    void* vtbl;
    int* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int GetSize() { return m_usSize; }
    int& GetAt(unsigned int index) { return m_pBase[index]; }
};

extern MenuArray DAT_011f3508;

// @fnv 0x00a09030
intptr_t __cdecl FUN_00a09030(int id)
{
    int result;
    if (id >= 0x3e9 && id <= 0x43c && DAT_011f3508.GetSize() > (unsigned int)(id - 0x3e9)) {
        result = DAT_011f3508.GetAt(id - 0x3e9);
    } else {
        result = 0;
    }
    return result;
}

namespace fnv_00a0a130 {
struct MemoryHeap_a0a130 {
    void* FUN_00aa3e40(unsigned int uiSize);
    void FUN_00aa4060(void* pvMem);
};

struct ListNode_a0a130 {
    int m_item;
    ListNode_a0a130* m_pkNext;
    ListNode_a0a130() { m_item = 0; m_pkNext = 0; }
};

struct ListMap_a0a130 {
};
extern ListMap_a0a130 DAT_011f3358;

// @fnv 0x00a0a130
void __cdecl FUN_00a0a130(intptr_t iKey, intptr_t iItem)
{
    ListNode_a0a130* pkNew = new ListNode_a0a130;
    ListNode_a0a130* pkCur = 0;
    pkNew->m_item = iItem;
    if (reinterpret_cast<::S_00adc830_Map *>(&(DAT_011f3358))->GetAt(iKey, (::S_00adc830_Entry *&)(pkCur))) {
        bool bFound = pkCur->m_item == iItem;
        while (pkCur->m_pkNext) {
            pkCur = pkCur->m_pkNext;
            bFound = pkCur->m_item == iItem;
        }
        if (!bFound)
            pkCur->m_pkNext = pkNew;
        else
            delete pkNew;
    } else {
        reinterpret_cast<::FUN_00a0c6c0_cls *>(&(DAT_011f3358))->InsertOrUpdate(iKey, (::AnimSequenceBase *)(pkNew));
    }
}
}

void __cdecl FUN_00a04500();

class MenuLockB35 {
public:
    MenuLockB35() { FUN_00a044f0(); }
    ~MenuLockB35() { ::fnv_00a04500::FUN_00a04500(); }
};

class TileB35;

class TileListB35 {
public:
    NiTListItem<TileB35*>* GetHeadPos() const { return m_pkHead; }
    TileB35*& GetNext(NiTListItem<TileB35*>*& pkPos)
    {
        TileB35*& pkElement = pkPos->m_element;
        pkPos = pkPos->m_pkNext;
        return pkElement;
    }

    NiTListItem<TileB35*>* m_pkHead;
};

class TileB35 {
public:
    void FUN_00a0b350(int iValue, float fDefault);

    void* m_pVTable;
    TileListB35 m_kChildList;
};

// @fnv 0x00a0b350
void TileB35::FUN_00a0b350(int iValue, float fDefault)
{
    MenuLockB35 kLock;
    float fValue = reinterpret_cast<::TileListBoxCalls *>((((Tile*)this)))->GetFloat(0xff4);
    if (fValue == ::_DAT_01012060)
        fValue = fDefault;
    if ((float)iValue == fValue)
        reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(8);

    NiTListItem<TileB35*>* pkPos = m_kChildList.GetHeadPos();
    while (pkPos)
        m_kChildList.GetNext(pkPos)->FUN_00a0b350(iValue, fValue);
}

unsigned int __cdecl FUN_0044a670(const char* text);

uintptr_t __cdecl FUN_00403940(unsigned int a, unsigned int b);

void* __cdecl FUN_00401000(unsigned int size);

void __cdecl FUN_00401030(void* p);

void* __cdecl FUN_00401460(void* dst, const void* src, unsigned int size);

template <> inline void BSStringT<char>::SetLength(unsigned int length)
{
    sLen = length <= 0xFFFF ? (unsigned short)length : 0xFFFF;
}

template <> inline void BSStringT<char>::SetMaxLength(unsigned int length)
{
    sMaxLen = length <= 0xFFFF ? (unsigned short)length : 0xFFFF;
}

template <> inline BSStringT<char>::BSStringT()
{
    pString = 0;
    SetLength(0);
    reinterpret_cast<::FUN_00403a00_class *>(this)->FUN_00403a00(0);
}

template <> inline bool BSStringT<char>::Set(const char* text, unsigned int length)
{
    unsigned int srcLen = text ? FUN_0044a670(text) : 0;
    unsigned int newLen = FUN_00403940(srcLen, length);
    unsigned int maxLen = MaxLength();
    if (newLen > maxLen) {
        char* oldString = pString;
        char* newString = (char*)FUN_00401000(newLen + 1);
        pString = newString;
        if (text)
            ::__memcpy(pString, text, srcLen + 1);
        else
            *pString = 0;
        if (oldString) {
            char* p = oldString;
            FUN_00401030(p);
        }
        reinterpret_cast<::FUN_00403a00_class *>(this)->FUN_00403a00(newLen);
    } else if (newLen) {
        if (text)
            ::__memcpy(pString, text, srcLen + 1);
        else
            *pString = 0;
    } else {
        if (pString) {
            char* p = pString;
            FUN_00401030(p);
        }
        pString = 0;
        newLen = 0;
        reinterpret_cast<::FUN_00403a00_class *>(this)->FUN_00403a00(newLen);
    }
    SetLength(srcLen);
    bool result = srcLen != 0;
    return result;
}

class FUN_00a0c220 {
public:
    FUN_00a0c220(int aiType, float afValue, const char* apText, int aiParam1, int aiParam2);
    int m_iType;
    float m_fValue;
    BSStringT<char> m_kText;
    int m_iParam1;
    int m_iParam2;
};

// @fnv 0x00a0c220
FUN_00a0c220::FUN_00a0c220(int aiType, float afValue, const char* apText, int aiParam1, int aiParam2)
{
    m_iType = aiType;
    m_fValue = afValue;
    reinterpret_cast<::TextString *>(&(m_kText))->FUN_004037f0(apText, 0x1F);
    m_iParam1 = aiParam1;
    m_iParam2 = aiParam2;
}

struct MemoryManagerD3C0 {
    void Deallocate(void* pvMem);
};

extern MemoryManagerD3C0 g_kMemoryManagerD3C0;

struct MapItemD3C0 {
    MapItemD3C0* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBaseD3C0 {
public:
    static void operator delete(void* pvMem) { g_kMemoryManagerD3C0.Deallocate(pvMem); }
    virtual ~MapBaseD3C0()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItemD3C0* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItemD3C0* pkItem);
    virtual MapItemD3C0* NewItem();
    virtual void DeleteItem(MapItemD3C0* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++) {
            while (m_ppkHashTable[i]) {
                MapItemD3C0* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    MapItemD3C0** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00a0d3c0 : public MapBaseD3C0 {
public:
    virtual ~FUN_00a0d3c0();
};

// @fnv 0x00a0d3c0
FUN_00a0d3c0::~FUN_00a0d3c0()
{
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
}

namespace fnv_00a1e1d0 {
struct A1E1D0_Pool { void FUN_00aa4060(void* p); };
struct FUN_00a0c190
{
    int m_00;
    ~FUN_00a0c190();
};
struct A1E1D0_Holder
{
    FUN_00a0c190* m_entry;
    void FUN_00a1e1d0(FUN_00a0c190* entry);
};
// @fnv 0x00a1e1d0
void A1E1D0_Holder::FUN_00a1e1d0(FUN_00a0c190* entry)
{
    if (m_entry)
        delete m_entry;
    m_entry = entry;
}
}



class FUN_00a7b2e0
{
public:
    const void** vtable;
    ~FUN_00a7b2e0();
    int m_04;
    int m_08;
    FUN_00a7b2e0();
};

class FUN_00a1f610 : public FUN_00a7b2e0
{
public:
    int m_0c;
    int m_10;
    FUN_00a1f610(int a, int b);
};

// @fnv 0x00a1f610
FUN_00a1f610::FUN_00a1f610(int a, int b)
    : FUN_00a7b2e0()
{
    vtable = DAT_01094cfc;
    m_0c = a;
    m_10 = b;
    ::AssignFixedString((char *)this, 0, (char **)&(const ::NiFixedString &)(NiFixedString("Tileptr")));
}

namespace fnv_00aaa7d0 {
// FUN_00aaa7d0 -- reads the "FRCTL001" fractal header through the archive stream.
//
// NOTE on the frame: the original reserves 0x54 bytes of frame that no instruction
// references.  They are the frames of two /Ob1 inline candidates that the compiler
// started to inline and then declined (it allocates their locals in the caller's
// frame anyway, see the "declined inline" reservation behaviour of VC9 /Od+/Ob1):
//   * the FUN_00ac5490 constructor (12 dwords) -- reserved after the bool temps,
//     which is what puts the argument-address temp at [ebp-0xc0] (-0x30).
//   * FractalHeader::FUN_00aaa720 (9 dwords) -- reserved after it, which is what
//     puts the discarded call-result temps at [ebp-0xe8..-0xf1] (-0x54).
// Both bodies below are therefore sized to reproduce those reservations (and are
// big enough that the inliner declines them instead of expanding them).
namespace std {
template<class T> struct char_traits {};
template<class T> struct allocator {};
template<class T, class Traits, class Alloc> struct basic_string {
    unsigned int allocator;
    union Storage { char buffer[16]; char* pointer; } storage;
    unsigned int length;
    unsigned int capacity;
    basic_string(const char*);
    void _Tidy(bool, unsigned int);
    basic_string& assign(const basic_string&, unsigned int, unsigned int);
    __forceinline basic_string(const basic_string& rhs) {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        assign(rhs, 0, ::g_010173f0);
    }
    __forceinline ~basic_string() { reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0); }
};

}
typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > GameString;

extern void* DAT_010a2c38[];
struct FUN_00aaaa80 {
    GameString signature;
    GameString filename;
    unsigned int flags;
    FUN_00aaaa80();
    virtual ~FUN_00aaaa80();
};
struct FUN_00ac5490 : FUN_00aaaa80 {
    void* file;
    void* archive;
    FUN_00ac5490(GameString signature);
    bool FUN_00ac5540(GameString filename, bool binary);
    __forceinline ~FUN_00ac5490() {
        reinterpret_cast<::FUN_00ac5c00_cls *>(this)->ClearHolders();
    }
};
struct FractalHeader {
    unsigned int width;
    unsigned int height;
    unsigned int values[2][2];
    void FUN_00aaa720();
};
struct FractalReaderA {  };
struct FractalReaderB {  };

inline FUN_00ac5490::FUN_00ac5490(GameString signature)
{
    ::std::uintptr_t c00, c01, c02, c03, c04, c05, c06, c07, c08, c09, c10;
    c00 = reinterpret_cast<::std::uintptr_t>(&signature); c01 = c00 + 1; c02 = c01 + 1; c03 = c02 + 1;
    c04 = c03 + 1; c05 = c04 + 1; c06 = c05 + 1; c07 = c06 + 1;
    c08 = c07 + 1; c09 = c08 + 1; c10 = c09 + 1;
}

inline void FractalHeader::FUN_00aaa720()
{
    int u00, u01, u02, u03, u04, u05, u06, u07, u08;
    u00 = 0; u01 = 1; u02 = 2; u03 = 3; u04 = 4; u05 = 5; u06 = 6; u07 = 7; u08 = 8;
    u00 = u01 + u02; u01 = u02 + u03; u02 = u03 + u04; u03 = u04 + u05; u04 = u05 + u06;
    u05 = u06 + u07; u06 = u07 + u08; u07 = u08 + u00; u08 = u00 + u01; u00 = u01 * u02;
    u01 = u02 * u03; u02 = u03 * u04; u03 = u04 * u05; u04 = u05 * u06; u05 = u06 * u07;
    u06 = u07 * u08; u07 = u08 * u00; u08 = u00 + u01; u00 = u01 + u02; u01 = u02 + u03;
}

// @fnv 0x00aaa7d0
bool __cdecl FUN_00aaa7d0(const GameString& filename, unsigned int* width,
    unsigned int* height, unsigned int values[2][2], FractalReaderA* a, FractalReaderB* b)
{
    FUN_00ac5490 stream("FRCTL001");
    if (!stream.FUN_00ac5540(filename, true))
        return false;
    FractalHeader header;
    if (!reinterpret_cast<::FaceBinaryReadReceiver *>(&(stream))->FUN_00ac5e00(&header, 1, 24))
        return false;
    reinterpret_cast<::FUN_00aaa720_cls *>(&(header))->FUN_00aaa720();
    *width = header.width;
    *height = header.height;
    for (unsigned int i = 0; i < 2; i++)
        for (unsigned int j = 0; j < 2; j++)
            values[i][j] = header.values[i][j];
    if (!reinterpret_cast<::AAOwner *>((a))->FUN_00aaac10((::AAStream *)(::fnv_00aaa7d0::FUN_00ac5490 *)(&stream), values))
        return false;
    if (!reinterpret_cast<::FGModel *>((b))->FUN_00aaaf10((::FGReader *)(::fnv_00aaa7d0::FUN_00ac5490 *)(&stream), (::FGSize *)(values)))
        return false;
    return true;
}
}

// namespace fnv_00aaa7d0

// Scalar deleting destructor of a Tile subclass: its inline destructor releases the tile's
// resources unless flag 0x2000 is set, then the Tile base destructor runs and the memory goes
// back to the game heap.
struct TileBaseA0BBF0 {
    virtual ~TileBaseA0BBF0();
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    unsigned int uiFlags;

    bool GetFlag(unsigned int uiFlag) const { return (uiFlags & uiFlag) != 0; }
};

struct FUN_00a0bbf0 : TileBaseA0BBF0 {
// @fnv 0x00a0bbf0
    virtual ~FUN_00a0bbf0()
    {
        if (!GetFlag(0x2000))
            reinterpret_cast<::fnv_009ff690::ReleaseTile *>(this)->FUN_009ff690();
    }
};

TileBaseA0BBF0* CreateTileA0BBF0()
{
    return new FUN_00a0bbf0;
}

namespace fnv_00a0c0c0 {
struct A0C0C0_String
{
    char* m_handle;
    A0C0C0_String(const A0C0C0_String& other) : m_handle(other.m_handle) {}
    ~A0C0C0_String();
    A0C0C0_String& operator=(const char* text);
};
inline A0C0C0_String& A0C0C0_String::operator=(const char* text)
{
    if (m_handle != text) {
        char* old = m_handle;
        m_handle = ::NiGlobalStringTable::AddString(text);
        if (old == (*reinterpret_cast<::fnv_00a0c0c0::A0C0C0_String *>(&::DAT_0109b220)).m_handle)
            return *this;
        long* header = &((StringHeader*)old - 1)->refs;
        InterlockedDecrement(header);
    }
    return *this;
}
struct A0C0C0_Range
{
    int m_kRayStart;
    int m_kRayEnd;
    int m_uiItemCount;
    A0C0C0_Range() { m_uiItemCount = 0; m_kRayStart = 0; m_kRayEnd = 0; }
    ~A0C0C0_Range();
};
struct A0C0C0_Entry
{
    A0C0C0_String m_name;
    int m_uiFilterValue;
    A0C0C0_Range m_range;
    A0C0C0_Entry(const char* name, int value);
};
// @fnv 0x00a0c0c0
A0C0C0_Entry::A0C0C0_Entry(const char* name, int value) : m_name((*reinterpret_cast<::fnv_00a0c0c0::A0C0C0_String *>(&::DAT_0109b220)))
{
    m_name = name;
    m_uiFilterValue = value;
}
}

// namespace fnv_00a0c0c0

struct A0D2A0_Item
{
    A0D2A0_Item* m_pkNext;
    const char* m_key;
    void* m_val;
};

struct A0D2A0_MapBase
{
    virtual ~A0D2A0_MapBase() { int unused[4]; (void)unused; ClearAll(); FUN_00aa10f0(m_ppkHashTable); }
    virtual void ClearAll();
    unsigned int m_uiHashSize;
    A0D2A0_Item** m_ppkHashTable;
    unsigned int m_uiCount;
};

struct A0D2A0_Map : A0D2A0_MapBase
{
    virtual ~A0D2A0_Map() { ClearAll(); }
};

struct A0D2A0_StringMap : A0D2A0_Map
{
    bool m_bCopy;
    virtual ~A0D2A0_StringMap();
};

// @fnv 0x00a0d220
FUN_00a0d220_cls* FUN_00a0d220_cls::FUN_00a0d220(unsigned int auiFlags)
{
    FUN_00a0d220_frame frame;
    m_vptr = &DAT_01094d9c;
    reinterpret_cast<::A0D2A0_StringMap *>(this)->A0D2A0_StringMap::~A0D2A0_StringMap();
    if (auiFlags & 1) {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00a0d220_pool *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}

// @fnv 0x00a0d2a0
A0D2A0_StringMap::~A0D2A0_StringMap()
{
    if (m_bCopy) {
        for (unsigned int i = 0; i < m_uiHashSize; i++) {
            A0D2A0_Item* item = m_ppkHashTable[i];
            while (item) {
                A0D2A0_Item* save = item;
                item = item->m_pkNext;
                FUN_00aa10f0((void*)save->m_key);
            }
        }
    }
}

struct S_00a04150_Class {
    int unk00;
    S_00a04150_List m_kNode;
    void FUN_00a04150();
};

// @fnv 0x00a04150
void S_00a04150_Class::FUN_00a04150()
{
    AutoTileLock_Local kLock;
    void* kPos = m_kNode.GetHeadPos();
    while (kPos) {
        delete m_kNode.GetNext(kPos);
    }
    m_kNode.FUN_004ed900();
}

namespace fnv_00a01b00 {
struct MemoryManager { void Deallocate(void*); };
extern void (*DAT_00fdf05c)(void*);
extern void (*DAT_00fdf100)(void*);
struct FUN_00a031b0_shell {  };
struct Tile__TileTemplate;

struct TemplateListNode {
    Tile__TileTemplate* pItem;
    TemplateListNode* pNext;
};

struct FUN_00a0ad40 {
    void* unk00;
    TemplateListNode kList;
    void* unk0c;
    bool bUnk10;

    ~FUN_00a0ad40();
};

extern unsigned int DAT_0126fd98;
extern unsigned char DAT_011f32c8;
struct TileManager {
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
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int criticalSection;
    void Enter() { DAT_00fdf05c(&criticalSection); }
    void Leave() { if(0){} DAT_00fdf100(&criticalSection); }
};
__forceinline TileManager* GetDebrisManager() { return (*reinterpret_cast<::fnv_00a01b00::TileManager * *>(&::NiRenderer::ms_pRenderer)); }

__forceinline int GetMemContext() { return (*reinterpret_cast<int *>(&::currentAllocationContext)); }
__forceinline void SetMemContext(int context) { (*reinterpret_cast<int *>(&::currentAllocationContext)) = context; }

struct AutoMemContext {
    int m_eOldContext;

    __forceinline AutoMemContext(int aeMemoryContext) {
        m_eOldContext = GetMemContext();
        SetMemContext(aeMemoryContext);
    }
    __forceinline ~AutoMemContext() {
        SetMemContext(m_eOldContext);
    }
};


struct FUN_00a1dd80_Class : public Menu {
};

struct TileLoader : public FUN_00a031b0_shell {
    void FUN_00a033b0(void*);
    Tile* FUN_00a01b00(void* arg0);
};

// @fnv 0x00a01b00
Tile* TileLoader::FUN_00a01b00(void* arg0) {
    AutoMemContext kContext(0xd);
    DAT_011f32c8 = 0;
    Tile* pTile7 = 0;
    FUN_00a0ad40* pTemplate = 0;
    bool bKeep_ = 0;

    pTemplate = ((::fnv_00a01b00::FUN_00a0ad40 *)(::fnv_00a01e20::FUN_00a01e20((const char *)(arg0), (const char *)(0), 0)));
    if (DAT_011f32c8)
        return 0;

    pTile7 = reinterpret_cast<::FUN_00a031b0_shell *>((this))->CreateMenuTiles(pTemplate->unk0c ? pTemplate->unk0c : pTemplate->unk00);
    if (DAT_011f32c8)
        return 0;

    ((TileLoader*)pTile7)->FUN_00a033b0(pTemplate->unk0c ? pTemplate->unk0c : pTemplate->unk00);
    if (DAT_011f32c8)
        return 0;

    FUN_00a1dd80_Class* pMenu = (FUN_00a1dd80_Class*)reinterpret_cast<::FUN_00a03c90_shell *>((pTile7))->FUN_00a03c90();
    if (pMenu) {
        TemplateListNode* pNode = &pTemplate->kList;
        while (pNode && pNode->pItem) {
            reinterpret_cast<::FUN_00a1dd80_Class *>((pMenu))->FUN_00a1dd80((::Tile__TileTemplate *)(pNode->pItem));
            pMenu->bUnk1d = !bKeep_;
            pTemplate->bUnk10 = bKeep_;
            if (DAT_011f32c8)
                return 0;
            pNode = pNode->pNext;
        }
    }

    if (!bKeep_) {
        delete pTemplate;
        pTemplate = 0;
    }

    GetDebrisManager()->Enter();
    if (pTile7) reinterpret_cast<::Tile *>((((TileLoader*)pTile7)))->SetSpeechChallengeFailure(false);
if(0){} GetDebrisManager()->Leave();

    DAT_011f32c8 = 0;
    return pTile7;
}
}

// namespace fnv_00a01b00

namespace fnv_00a0a410 {
extern "C" int __cdecl sscanf(const char*, const char*, ...);

inline unsigned int __cdecl FUN_0044a670(const char* value) { return strlen(value); }
unsigned int __cdecl FUN_00403940(unsigned int, unsigned int);
void* __cdecl FUN_00401000(unsigned int);
void __cdecl FUN_00401030(void*);
inline void* __cdecl FUN_00401460(void* d, const void* s, unsigned n) { return memcpy(d,s,n); }
inline void ReleaseParsedString(void* pointer) { FUN_00401030(pointer); }
extern double DAT_01094ce8, DAT_01094ca0, DAT_01094c98, DAT_01094c90, DAT_01094c88, DAT_01094c80;
extern const char DAT_01094ca8[], DAT_01094c58[];


struct ParsedText {
    char* text;
    unsigned short length;
    unsigned short capacity;
    bool FUN_004037f0(const char* source, unsigned int reserveMinimum) {
        unsigned int sourceLength = source ? FUN_0044a670(source) : 0;
        unsigned int allocatedLength = FUN_00403940(sourceLength, reserveMinimum);
        if (allocatedLength <= FUN_004039a0()) {
            if (allocatedLength) {
                if (source) FUN_00401460(text, source, sourceLength + 1);
                else text[0] = 0;
            } else {
                if (text) delete[] text;
                text = 0;
                allocatedLength = 0;
                FUN_00403a00(allocatedLength);
            }
        } else {
            char* old = text;
            text = new char[allocatedLength + 1];
            if (source) FUN_00401460(text, source, sourceLength + 1);
            else text[0] = 0;
            if (old) delete[] old;
            FUN_00403a00(allocatedLength);
        }
        FUN_004039c0(sourceLength);
        return sourceLength != 0;
    }
    unsigned int FUN_004048e0() const {
        return length == 0xffff ? FUN_0044a670(text) : length;
    }
    unsigned int FUN_004039a0() const { return capacity; }
    const char* FUN_00559450() const { return text; }
    void FUN_00403a00(unsigned int n) { capacity = n <= 0xffff ? (unsigned short)n : 0xffff; }
    void FUN_004039c0(unsigned int n) { length = n <= 0xffff ? (unsigned short)n : 0xffff; }
    bool FUN_00438470(const ParsedText& rhs) {
        unsigned int n = rhs.FUN_004048e0();
        if (n <= FUN_004039a0()) {
            if (n) FUN_00401460(text, rhs.FUN_00559450(), n + 1);
            else {
                if (text) delete[] text;
                text = 0;
                n = 0;
                FUN_00403a00(n);
            }
        } else {
            char* old = text;
            text = new char[n + 1];
            FUN_00401460(text, rhs.FUN_00559450(), n + 1);
            if (old) delete[] old;
            FUN_00403a00(n);
        }
        FUN_004039c0(n);
        return n != 0;
    }
    __forceinline ParsedText& operator=(const char* source) { reinterpret_cast<::TextString *>(this)->FUN_004037f0(source, 0); return *this; }
    __forceinline ParsedText& operator=(const ParsedText& source) { FUN_00438470(source); return *this; }
    ~ParsedText() { reinterpret_cast<::TextString *>(this)->FUN_004037f0(0, 0); }
};
struct ParsedToken {
    int kind;
    float value;
    ParsedText text;
    int integer;
    void* context;
    __forceinline void SetText(const char* value) {
        ParsedText* textObject = &text;
        reinterpret_cast<::TextString *>((textObject))->FUN_004037f0(value, 0);
    }
    __forceinline void CopyText(const ParsedText& value) {
        ParsedText* textObject = &text;
        textObject->FUN_00438470(value);
    }
};
struct ParsedNode {
    ParsedNode* next;
    ParsedNode* previous;
    ParsedToken* value;
};
unsigned int FUN_0040fc90();
void FUN_0040fca0(unsigned int);
void FUN_0040fbe0(...);
struct ParsedPoolLock {
    volatile long owner;
    unsigned int recursion;
    void FUN_0040fbf0(int) {
        unsigned int thread = FUN_0040fc90();
        if (owner == thread) ++recursion;
        else {
            unsigned int spins = 0;
            while (FUN_0043b460(&owner, 0, thread)) {
                ++spins;
                if (spins > 10000) FUN_0040fca0(1);
                else FUN_0040fca0(0);
            }
            FUN_0040fbe0();
            recursion = 1;
        }
    }
    void FUN_0040fba0() {
        FUN_0040fbe0();
        --recursion;
        if (!recursion) owner = 0;
    }
};
extern ParsedPoolLock DAT_011c5f80;
extern ParsedNode* DAT_011c5f58;
extern unsigned int DAT_01188f7c;
extern ParsedNode* DAT_011c5f54;
inline void FUN_0043a080() {
    DAT_011c5f58 = new ParsedNode[DAT_01188f7c];
    ParsedNode* node = DAT_011c5f58 + DAT_01188f7c - 1;
    node->next = 0;
    unsigned int index = 1;
    do {
        node = DAT_011c5f58 + index;
        node->next = node + 1;
    } while (index++ < DAT_01188f7c - 2);
    if (DAT_011c5f54) {
        DAT_011c5f58->next = DAT_011c5f54;
        DAT_011c5f54 = DAT_011c5f58;
    } else {
        DAT_011c5f54 = DAT_011c5f58;
        DAT_011c5f54->next = 0;
    }
    ++DAT_011c5f58;
}
struct ParsedAllocator {
    unsigned count;
    ParsedNode* FUN_0043a010() {
        DAT_011c5f80.FUN_0040fbf0(0);
        if (!DAT_011c5f58) FUN_0043a080();
        ParsedNode* node = DAT_011c5f58;
        DAT_011c5f58 = DAT_011c5f58->next;
        node->value = 0;
        node->next = 0;
        node->previous = 0;
        DAT_011c5f80.FUN_0040fba0();
        return node;
    }
    void FUN_0045cee0(ParsedNode* node) {
        DAT_011c5f80.FUN_0040fbf0(0);
        ParsedNode* item = node;
        item->previous = 0;
        item->next = DAT_011c5f58;
        DAT_011c5f58 = item;
        DAT_011c5f80.FUN_0040fba0();
    }
};
struct ParsedList {
    ParsedNode* head;
    ParsedNode* tail;
    ParsedAllocator allocator;
    __forceinline void* GetTailPosition() const { return tail; }
    __forceinline ParsedToken*& GetPrevious(void*& position) {
        ParsedToken*& element = static_cast<ParsedNode*>(position)->value;
        position = static_cast<ParsedNode*>(position)->previous;
        return element;
    }
    ParsedToken* PopFront() {
        ParsedNode* node = tail;
        tail = tail->previous;
        if (tail) tail->next = 0;
        else head = 0;
        ParsedToken* element = node->value;
        node->value = 0;
        allocator.FUN_0045cee0(node);
        --allocator.count;
        return element;
    }
    void FUN_00a11db0(ParsedNode* node) {
        node->next = 0;
        node->previous = tail;
        if (tail) tail->next = node;
        else head = node;
        tail = node;
        ++allocator.count;
    }
    inline ParsedNode* NewItem() { return ((::fnv_00a0a410::ParsedNode *)(reinterpret_cast<::FUN_0043a010_shell *>(&(allocator))->FUN_0043a010())); }
    __forceinline void Append(ParsedToken* const& token) {
        ParsedNode* node = NewItem();
        node->value = token;
        reinterpret_cast<::fnv_00adddd0::FUN_00a1b940 *>(this)->FUN_00a11db0((::fnv_00adddd0::MsgNode *)(node));
    }
};
struct ParsedParent {
    unsigned unk00, unk04, unk08;
    void* templateData;
    __forceinline void SetTileTemplate(void* value) {
        templateData = value;
    }
};
struct ParsedBuilder {
    unsigned unk00;
    ParsedParent* parent;
    ParsedList tokens;
    void FUN_00a0a410(int, const char*, void*, bool);
};


void FUN_00a0b8d0(ParsedToken* token) {
    if ((unsigned int)DAT_011f32dc < 10) ((ParsedToken**)DAT_011f329c)[DAT_011f32dc++] = token;
    else delete token;
}
extern float DAT_01094cf4;

// @fnv 0x00a0a410
void ParsedBuilder::FUN_00a0a410(int trait, const char* text, void* context, bool literal) {
    float value = DAT_01094cf4;
    if (!literal)
        value = (float)::FUN_00a01860(text);
    if (value == ::DAT_01094ba8 && (text[0] == '_' || (text[0] == '&' && text[1] == '_')))
        value = (float)::FUN_00a00940(text, -1);
    ParsedToken* createdToken16 = ((::fnv_00a0a410::ParsedToken *)(::FUN_00a0b950(trait, value, text, (int)value, context)));
    bool isNumericX = true;
    for (unsigned i = 0; i < strlen(text); ++i) {
        if ((text[i] < '0' || text[i] > '9') && text[i] != '-' && text[i] != '.') {
            isNumericX = false;
            break;
        }
    }
    if (isNumericX) {
        if (value == ::DAT_01094ba8)
            sscanf(text, ::str_01094cf0, &value);
        if (value == ::_DAT_01012060)
            sscanf(text, ::str_01094cf0, &value);
        createdToken16->text = ::DAT_01011584;
        createdToken16->value = value;
        createdToken16->integer = (int)value;
    }
    void* iteratorPosition8 = tokens.GetTailPosition();
    ParsedToken* lastToken15 = 0;
    ParsedToken* previousToken2 = 0;
    ParsedToken* thirdToken12 = 0;
    if (iteratorPosition8) lastToken15 = tokens.GetPrevious(iteratorPosition8);
    if (iteratorPosition8) previousToken2 = tokens.GetPrevious(iteratorPosition8);
    if (iteratorPosition8) thirdToken12 = tokens.GetPrevious(iteratorPosition8);
    if (trait == 3002 && lastToken15 && lastToken15->kind == 0 && lastToken15->value == DAT_01094ce8) {
        if (parent->templateData) {
            ::FUN_005b5e40();
        } else {
            parent->SetTileTemplate(((void *)(reinterpret_cast<::BuildStorage_00a0af10 *>((parent))->FindTemplateByName(text))));
            if (!parent->templateData) {
                parent->SetTileTemplate(((void *)(reinterpret_cast<::Storage_00a0ae70 *>((parent))->FUN_00a0ae70(text))));
            }
        }
        ::fnv_00a0b8d0::FUN_00a0b8d0((::fnv_00a0b8d0::TileElement *)(::fnv_00a0a410::ParsedToken *)(((::fnv_00a0a410::ParsedToken *)(reinterpret_cast<::FUN_00ae8010_cls *>(&(tokens))->PopFront()))));
        ::fnv_00a0b8d0::FUN_00a0b8d0((::fnv_00a0b8d0::TileElement *)(createdToken16));
    } else if (trait == 1 && value == DAT_01094ce8 && parent->templateData) {
        parent->SetTileTemplate(0);
        ::fnv_00a0b8d0::FUN_00a0b8d0((::fnv_00a0b8d0::TileElement *)(createdToken16));
    } else if (trait == 3002 && lastToken15 && lastToken15->kind == 0 &&
               lastToken15->value >= DAT_01094ca0 && lastToken15->value <= DAT_01094c98) {
        lastToken15->kind = 6;
        lastToken15->text = text;
        ::fnv_00a0b8d0::FUN_00a0b8d0((::fnv_00a0b8d0::TileElement *)(createdToken16));
    } else if (trait == 3002) {
        createdToken16->kind = 8;
        createdToken16->integer = 3002;
        tokens.Append(createdToken16);
    } else if (trait == 1 && lastToken15 && lastToken15->kind == 3001 && previousToken2 &&
               (previousToken2->kind == 4 || previousToken2->kind == 2) && previousToken2->value == value) {
        if ((createdToken16->value >= DAT_01094c90 && createdToken16->value <= DAT_01094c88) || createdToken16->integer >= 10000)
            previousToken2->kind = 8;
        else if (createdToken16->value >= ::DAT_01073490 && createdToken16->value <= DAT_01094c80)
            previousToken2->kind = 9;
        else {
            previousToken2->kind = -1;
            ::FUN_005b5e40();
        }
        previousToken2->integer = (int)previousToken2->value;
        previousToken2->value = lastToken15->value;
        previousToken2->text = lastToken15->text;
        ::fnv_00a0b8d0::FUN_00a0b8d0((::fnv_00a0b8d0::TileElement *)(::fnv_00a0a410::ParsedToken *)(((::fnv_00a0a410::ParsedToken *)(reinterpret_cast<::FUN_00ae8010_cls *>(&(tokens))->PopFront()))));
        ::fnv_00a0b8d0::FUN_00a0b8d0((::fnv_00a0b8d0::TileElement *)(createdToken16));
    } else if (trait == 1 && lastToken15 && lastToken15->kind == 3004 && previousToken2 &&
               previousToken2->kind == 3003 && thirdToken12 && thirdToken12->kind == 2 && thirdToken12->value == value) {
        thirdToken12->kind = 10;
        thirdToken12->integer = (int)thirdToken12->value;
        thirdToken12->value = lastToken15->value;
        thirdToken12->text = previousToken2->text;
        ::fnv_00a0b8d0::FUN_00a0b8d0((::fnv_00a0b8d0::TileElement *)(::fnv_00a0a410::ParsedToken *)(((::fnv_00a0a410::ParsedToken *)(reinterpret_cast<::FUN_00ae8010_cls *>(&(tokens))->PopFront()))));
        ::fnv_00a0b8d0::FUN_00a0b8d0((::fnv_00a0b8d0::TileElement *)(::fnv_00a0a410::ParsedToken *)(((::fnv_00a0a410::ParsedToken *)(reinterpret_cast<::FUN_00ae8010_cls *>(&(tokens))->PopFront()))));
        ::fnv_00a0b8d0::FUN_00a0b8d0((::fnv_00a0b8d0::TileElement *)(createdToken16));
    } else {
        if ((createdToken16->integer >= 4001 && createdToken16->integer <= 4125) || createdToken16->integer >= 10000) {
            if (createdToken16->kind == 0)
                createdToken16->kind = 4;
            else if (createdToken16->kind == 1)
                createdToken16->kind = 5;
        } else if (createdToken16->integer >= 2000 && createdToken16->integer <= 2025) {
            if (createdToken16->kind == 0)
                createdToken16->kind = 2;
            else if (createdToken16->kind == 1 && lastToken15)
                createdToken16->kind = 3;
        } else if (createdToken16->kind == 1 && createdToken16->value >= DAT_01094ca0 && createdToken16->value <= DAT_01094c98) {
            createdToken16->kind = 7;
        }
        tokens.Append(createdToken16);
    }
}
}

// namespace fnv_00a0a410

namespace tile_path_resolver {

struct UITile;

typedef ::NiTListItem<UITile*> TileItem;
typedef ::NiTListBase< ::NiTPointerAllocator<unsigned int>, UITile*> TileChildren;

struct TileMenuRoot {
    int unk00;
    UITile* m_pkTile;
    __forceinline UITile* GetTile() { return m_pkTile; }
};

struct UITile {
    int unk00;
    TileChildren m_kChildList;
    ::NiTObjectArray< ::Tile::Value*> m_kValues;
    ::BSStringT<char> m_kName;
    UITile* m_pParentNode;

    __forceinline UITile* GetParent() const { return m_pParentNode; }
    __forceinline unsigned int GetChildCount() const { return m_kChildList.m_kItemCount.m_uiCount; }
    __forceinline TileItem* GetHeadPos() const { return m_kChildList.m_pkHead; }
    __forceinline UITile*& GetNext(TileItem*& pos) {
        UITile*& element = pos->m_element;
        pos = pos->m_pkNext;
        return element;
    }
    __forceinline const char* GetName() const { return m_kName.pString; }
};



// @fnv 0x00a08b20
UITile* FUN_00a08b20(UITile* pTile, const char* pcPath)
{
    UITile* pResultTmp = 0;
    int m_iValueId;
    {
    char acName[0x800];
    acName[0] = 0;
    m_iValueId = ::ParseTextAndParams(pcPath, acName);

    switch (m_iValueId)
    {
    case 0x1391:
        return pTile->GetParent() ? pTile->GetParent()->GetParent() : 0;
    case 0x1389:
        return pTile->GetParent();
    case 0x138a:
        return pTile;
    case 0x1390:
        return ((::tile_path_resolver::TileMenuRoot *)(reinterpret_cast<::FUN_00a03c90_shell *>((pTile))->FUN_00a03c90()))->GetTile();
    case 0x138c:
        if (!acName[0] && pTile->GetParent()->GetChildCount())
        {
            TileItem* kPos = pTile->GetParent()->GetHeadPos();
            while (kPos)
            {
                if (pTile->GetParent()->GetNext(kPos) == pTile)
                    break;
            }
            if (kPos)
                return pTile->GetParent()->GetNext(kPos);
            else
                return pTile->GetParent()->m_kChildList.m_pkHead->m_element;
        }
        else if (acName[0] && pTile->GetParent()->GetChildCount())
        {
            TileItem* kPos2 = pTile->GetParent()->GetHeadPos();
            while (kPos2)
            {
                UITile* pChild = pTile->GetParent()->GetNext(kPos2);
                if (pChild->GetName() && !fnv::crt::stricmp(pChild->GetName(), acName))
                {
                    pResultTmp = pChild;
                    break;
                }
            }
            return pResultTmp;
        }
        else
            return 0;
    case 0x138d:
        if (!acName[0] && pTile->GetChildCount())
            return pTile->m_kChildList.m_pkHead->m_element;
        else if (pTile && acName[0] && pTile->GetChildCount())
            return ((::tile_path_resolver::UITile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pTile))->FUN_00a03da0((char *)(acName))));
        else
            return 0;
    case 0x138e:
        return ((::tile_path_resolver::UITile *)(::Interface::GetPrimaryInterfaceTile()));
    case 0x138f:
        return ((::tile_path_resolver::UITile *)(::Interface::GetSecondaryInterfaceTile()));
    default:
        if (pTile)
            pResultTmp = ((::tile_path_resolver::UITile *)(::FindTileByName((::Tile *)(::tile_path_resolver::UITile *)(((::tile_path_resolver::UITile *)(reinterpret_cast<::FUN_00a03d40_shell *>((pTile))->FUN_00a03d40()))), pcPath)));
        else
            pResultTmp = ((::tile_path_resolver::UITile *)(::FindTileByName((::Tile *)(::tile_path_resolver::UITile *)(((::tile_path_resolver::UITile *)(::Interface::GetPrimaryInterfaceTile()))), pcPath)));
        return pResultTmp;
    }
    }
}

}





struct FadePtr { FadeTile* ptr; inline FadeTile* operator->() const { return ptr; } };







extern FadeList DAT_011f3348;

intptr_t __cdecl FUN_00a01860(const char*);

struct FUN_00ae83e0 {
    FadeRecord* item; FUN_00ae83e0* next;
    ~FUN_00ae83e0();
    inline void RemoveAll() { while (next) { FUN_00ae83e0* after=next->next; next->next=0; delete next; next=after; } item=0; }
    inline void AddToHead(FadeRecord*& p) {
        if (!p) return;
        if (item) { FUN_00ae83e0* fresh = new FUN_00ae83e0; FUN_00ae83e0* node=fresh; node->item=item; node->next=0; node->next=next; next=node; }
        item=p;
    }

};

typedef FUN_00ae83e0 FadePending;

struct FadePendingClear { void FUN_00ae83e0(); };

extern const float DAT_01094c18;

extern const float DAT_01094c0c;

inline NiAVObject* modelOf(FadeTile* tile) { NiAVObject* model=tile->model; return model; }

inline unsigned tick() { unsigned time=GetTickCount(); return time; }

inline float minFloat(float a, float b) { return a < b ? a : b; }

inline float linear(float x, float x0, float x1, float y0, float y1) { return ((x-x0)/(x1-x0)) * (y1-y0) + y0; }

// @fnv 0x00a080d0
void __cdecl FUN_00a080d0()
{
    if ((unsigned char)((DAT_011f3348.next == 0 && DAT_011f3348.item == 0) ? 1 : 0)) return;
    float fraction5;
    FadeList* list6 = reinterpret_cast<FadeList*>(&DAT_011f3348);
    FadePending local2 = {0,0};
    FadeList* local1;
    float start13, local11, count1, total5, valueA9, valueB6, blend;
    int trait2;
    unsigned int type2;
    FadePending* pending3;
    FadeRecord* item;
    FadeRecord* local18;
    for (local1 = reinterpret_cast<FadeList*>(&DAT_011f3348); local1 && local1->item; local1=local1->next) {
        local11 = local1->item->end;
        start13 = local1->item->start;
        trait2 = local1->item->trait;
        switch (local1->item->type) {
        case 0: {
            fraction5 = (tick()-local1->item->time)/local1->item->duration;
            fraction5 = minFloat(fraction5, 1.0f);
            if (static_cast<FadeTile* volatile&>(local1->item->tile)->GetType() == 0x388 && trait2 == 0xfa9) {
                reinterpret_cast<::FUN_00a08720_t *>((local1->item->tile))->FUN_00a08720(modelOf(local1->item->tile),(start13+(local11-start13)*fraction5)/255.0);
            }
            reinterpret_cast<::FUN_00a012d0_t *>((local1->item->tile))->FUN_00a012d0(trait2,start13+(local11-start13)*fraction5,true);
            if (fraction5 >= 1.0) reinterpret_cast<::S_00a0c7c0_List *>(&(local2))->AddToHead((void **)&(local1->item));
            break;
        }
        case 1: case 2: case 3: {
            type2 = local1->item->type;
            count1 = reinterpret_cast<::TileListBoxCalls *>((local1->item->tile))->GetFloat(FUN_00a01860("_FlashCount"));
            total5 = reinterpret_cast<::TileListBoxCalls *>((local1->item->tile))->GetFloat(FUN_00a01860("_TotalFlashCount"));
            fraction5 = (tick()-local1->item->time)/local1->item->duration;
            if (fraction5 >= 1.0) {
                if ((type2==2 && count1 < 3.0) || (type2==3 && count1 < total5) || type2==1) {
                    local1->item->time=tick();
                    fraction5=0.0f;
                }
                if (type2==2 || type2==3) {
                    reinterpret_cast<::FUN_00a012d0_t *>((local1->item->tile))->FUN_00a012d0(FUN_00a01860("_FlashCount"),count1+1.0,true);
                    if (type2==2 && count1 > 3.0) reinterpret_cast<::FUN_00a012d0_t *>((local1->item->tile))->FUN_00a012d0(trait2,local11,true);
                    else if (type2==3 && count1>total5) {
                        reinterpret_cast<::FUN_00a012d0_t *>((local1->item->tile))->FUN_00a012d0(trait2,start13,true);
                        reinterpret_cast<::S_00a0c7c0_List *>(&(local2))->AddToHead((void **)&(local1->item));
                    }
                }
            }
            if (type2==2 && count1 >= 3.0) {
                valueA9 = start13+(local11-start13)*fraction5;
                reinterpret_cast<::FUN_00a012d0_t *>((local1->item->tile))->FUN_00a012d0(trait2,valueA9 > local11 ? local11:valueA9,true);
                if (valueA9 >= local11) reinterpret_cast<::S_00a0c7c0_List *>(&(local2))->AddToHead((void **)&(local1->item));
            } else {
                blend = 1.0f-(float)fabs((double)(float)(fraction5*::DAT_01011590-1.0));
                valueB6 = start13+(local11-start13)*blend;
                reinterpret_cast<::FUN_00a012d0_t *>((local1->item->tile))->FUN_00a012d0(trait2,valueB6,true);
            }
            break;
        }
        case 4: {
            fraction5=(tick()-local1->item->time)/local1->item->duration;
            if (fraction5 < 0.16665999591350555) {
                reinterpret_cast<::FUN_00a012d0_t *>((local1->item->tile))->FUN_00a012d0(trait2,linear(fraction5,0.0f,DAT_01094c18,start13,local11),true);
            } else if (fraction5 < 0.8333399891853333) {
                reinterpret_cast<::FUN_00a012d0_t *>((local1->item->tile))->FUN_00a012d0(trait2,local11,true);
            } else if (fraction5 >= 1.0) {
                reinterpret_cast<::FUN_00a012d0_t *>((local1->item->tile))->FUN_00a012d0(trait2,start13,true);
                reinterpret_cast<::S_00a0c7c0_List *>(&(local2))->AddToHead((void **)&(local1->item));
            } else {
                reinterpret_cast<::FUN_00a012d0_t *>((local1->item->tile))->FUN_00a012d0(trait2,linear(fraction5,DAT_01094c0c,1.0f,local11,start13),true);
            }
            break;
        }
        }
    }
    for (pending3=&local2; pending3 && pending3->item; pending3=pending3->next) {
        item=pending3->item;
        reinterpret_cast<FadeList*>(&DAT_011f3348)->FUN_00a0cbe0(item);
        local18=item;
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::LocalManager *>(&::g_memoryManager))))->FUN_00aa4060(local18);
    }
    reinterpret_cast<::Node185 *>(&(local2))->FUN_00ae83e0();
}

namespace fnv_00a033b0 {

extern const char str_01094b78[];

extern const char str_01094b4c[];

extern const char str_01094b18[];

extern const char str_01094aec[];

extern const char str_01094ac0[];

typedef unsigned short R_u16;

typedef unsigned int R_u32;



inline unsigned FUN_0044a670(const char* s){return strlen(s);}
struct R_Str {

    char* pString;

    R_u16 sLen;

    R_u16 sMaxLen;

    inline unsigned FUN_004048e0() const {return sLen==65535?FUN_0044a670(pString):sLen;}
    inline const char* FUN_00559450() const {return pString;}

};



struct R_Val {

    int trait;

    float fvalue;

    R_Str str;

    std::intptr_t m10;

    void* context;

};



struct R_Act { R_Act* next; R_Act* prev; R_Val* data; };



struct R_Menu {

    int unk00; int unk04;

    R_Act* acts;

};



struct R_Tile;

struct R_SetF {  };

struct R_SetS {  };

struct R_ValOwner {  };

struct R_P03 {  };

struct R_P09 {  };

struct R_P04 {  };

struct R_P08 {  };

struct R_HeapManager : FUN_00a0d220_pool { void* FUN_00aa3e40(unsigned); };
inline R_HeapManager* FUN_00401020(){return static_cast<R_HeapManager*>(&(*reinterpret_cast<::FUN_00a0d220_pool *>(&::g_memoryManager)));}
inline void* FUN_00401000(unsigned n){return FUN_00401020()->FUN_00aa3e40(n);}
inline void FUN_00401030(void*p){reinterpret_cast<::FNV_MemoryManager *>((FUN_00401020()))->FUN_00aa4060(p);}
inline void* FUN_00401460(void*dst,const void*src,unsigned n){return memcpy(dst,src,n);}

struct R_SH {

    char* pString; unsigned short sLen, sMaxLen;

    inline unsigned FUN_004039a0() const {return sMaxLen;}
    inline void FUN_00403a00(unsigned value) {sMaxLen=value<=65535?(unsigned short)value:65535;}
    inline void FUN_004039c0(unsigned value) {sLen=value<=65535?(unsigned short)value:65535;}
    inline bool FUN_00438470(const R_Str& src) {
        unsigned len=src.FUN_004048e0();
        char* old;
        if(len<=FUN_004039a0()) {
            if(len)FUN_00401460(pString,src.FUN_00559450(),len+1);
            else {
                if(pString){char* deleted=pString;FUN_00401030(deleted);}
                pString=0;len=0;FUN_00403a00(len);
            }
        } else {
            old=pString;
            char* allocated=(char*)FUN_00401000(len+1);
            pString=allocated;
            FUN_00401460(pString,src.FUN_00559450(),len+1);
            if(old){char* deletedOld=old;FUN_00401030(deletedOld);}
            FUN_00403a00(len);
        }
        FUN_004039c0(len);
        return len!=0;
    }

    inline R_SH& operator=(const R_Str& src){FUN_00438470(src);return *this;}

};

struct R_Vt4 { virtual void v0(); virtual void v1(); virtual void v2(); virtual int v3(); };



struct R_Tile {

    void** vtbl;

    int unk04; int unk08; int unk0c; int unk10;

    R_Val** parr;

    R_u32 count;

    int unk1c;

    R_Str str20;

    R_Tile* next28;

    int unk2c;

    R_u32 flags30;

};
















class C00a033b0 {

public:

    void FUN_00a033b0(R_Menu* a1);

};



// @fnv 0x00a033b0
void C00a033b0::FUN_00a033b0(R_Menu* a1)

{

    R_Tile* aw = 0;        // first tile

    R_Tile* ad = 0;        // current tile

    int aa = 0;            // current value index

    R_Val* ao;             // current value

    R_Act* ah;             // list head

    R_Act* af;               // list cursor

    unsigned an;           // loop counter

    int* aj;               // link result

    ah = (R_Act*)a1->acts;

    af = ah;

    ao = 0;

    while (af)

    {

        R_Val** Str = &af->data;

        af = af->next;

        ao = *Str;

        if (ao->trait == 6)

        {

            ad = (R_Tile*)ao->m10;

            if (!aw)

                aw = ad;

            reinterpret_cast<::FUN_00a07530_shell *>((((R_P08*)ad)))->FUN_00a07530(0x10000);

        }

        else if (ao->trait == 7)

        {

            unsigned n;

            if (ad->flags30 & 0x10000)

                ad->flags30 ^= 0x10000;

            EnterCriticalSection(reinterpret_cast<_RTL_CRITICAL_SECTION*>(&DAT_011f3330));

            for (an = 0; an < (n = ad->count); an++)

            {

                if (ad->parr[an]->trait != 4004)

                    reinterpret_cast<::fnv_00a09410::EvalValue *>((((R_P04*)ad->parr[an])))->FUN_00a09410(true);

            }

            LeaveCriticalSection(reinterpret_cast<_RTL_CRITICAL_SECTION*>(&DAT_011f3330));

            ad = ad->next28;

        }

        else if (ao->trait == 8)

        {

            R_Str* t3;

            const char* ax;

            if (ad)

            {

              if (!((ao->fvalue == ::DAT_01094ba8

                      && (((t3 = &ao->str)->sLen == 0xffff

                           ? strlen(ax = t3->pString)

                           : (unsigned int)t3->sLen) != 0))

                     || ao->m10 == 0xfc4

                     || ao->m10 == 0xfcc))

            {

                reinterpret_cast<::FUN_00a012d0_t *>((((R_SetF*)ad)))->FUN_00a012d0(ao->m10, ao->fvalue, true);

            }

            else

            {

                if (ao->m10 == 0xbba)

                {

                    *reinterpret_cast<R_SH*>(&ad->str20)=ao->str;

                }

                else if (ao->m10 == 0xfcc && ((R_Vt4*)ad)->v3() == 0x386)

                {

                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((R_SetS*)ad)))->FUN_00a01350(ao->m10, (char *)(ao->str.FUN_00559450()), true);

                    reinterpret_cast<::FUN_00a07530_shell *>((((R_P08*)ad)))->FUN_00a07530(0x20);

                }

                else

                {

                    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((R_SetS*)ad)))->FUN_00a01350(ao->m10, (char *)(ao->str.FUN_00559450()), true);

                }

            }

            }

            else

            {

                ::FUN_005b5e40();

            }

        }

        else if (ao->trait == 4)

        {

            aa = (int)ao->fvalue;

        }

        else if (ao->trait == 5)

        {

            aa = 0;

        }

        else if (ao->trait == 9)

        {

            if (aa)

                reinterpret_cast<::P03Value *>((((R_P03*)((::fnv_00a033b0::R_Val *)(reinterpret_cast<::fnv_00a01000::FUN_00a01000_shell *>((((R_ValOwner*)ad)))->GetOrCreateTraitValue(aa))))))->AppendFloatAction(ao->m10, ao->fvalue);

            else

                ::FUN_005b5e40();

        }

        else if (ao->trait == 0xA)

        {

            if (aa)

            {

                aj = (int*)((void *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(ad), ao->str.FUN_00559450())));

                if (aj)

                {

                    reinterpret_cast<::AGOwner *>((((R_P09*)((::fnv_00a033b0::R_Val *)(reinterpret_cast<::fnv_00a01000::FUN_00a01000_shell *>((((R_ValOwner*)ad)))->GetOrCreateTraitValue(aa))))))->FUN_00a09130(ao->m10, (::Tile *)(aj), fnv_FloatToInt(ao->fvalue));

                }

            }

            else

                ::FUN_005b5e40();

        }

        else if (ao->trait == 2)

        {

            if (aa)

            {

                reinterpret_cast<::P03Value *>((((R_P03*)((::fnv_00a033b0::R_Val *)(reinterpret_cast<::fnv_00a01000::FUN_00a01000_shell *>((((R_ValOwner*)ad)))->GetOrCreateTraitValue(aa))))))->AppendFloatAction(2024, (float)fnv_FloatToInt(ao->fvalue));

            }

            else

                ::FUN_005b5e40();

        }

        else if (ao->trait == 3)

        {

            if (aa)

            {

                reinterpret_cast<::P03Value *>((((R_P03*)((::fnv_00a033b0::R_Val *)(reinterpret_cast<::fnv_00a01000::FUN_00a01000_shell *>((((R_ValOwner*)ad)))->GetOrCreateTraitValue(aa))))))->AppendFloatAction(2025, (float)fnv_FloatToInt(ao->fvalue));

            }

            else

                ::FUN_005b5e40();

        }

    }

}
}

// namespace fnv_00a033b0

struct RenderAtlasSetting { int unk00; const char* pValue; __forceinline const char* GetValue() { return this ? pValue : 0; } };


struct RenderTLS { int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int heapIndex; };

struct RenderHeapScope {
    int saved;
    __forceinline RenderHeapScope() { { int current = (*reinterpret_cast<::RenderTLS *>(&::g_tlsBlock)).heapIndex; saved = current; } (*reinterpret_cast<::RenderTLS *>(&::g_tlsBlock)).heapIndex = 13; }
    __forceinline ~RenderHeapScope() { int restore = saved; (*reinterpret_cast<::RenderTLS *>(&::g_tlsBlock)).heapIndex = restore; }
};

struct RenderPoint2 { float x,y; __forceinline RenderPoint2(float a,float b):x(a),y(b){} };

struct RenderPoint3 {
    float x,y,z;
    __forceinline RenderPoint3() {}
    __forceinline RenderPoint3(float a,float b,float c):x(a),y(b),z(c){}
    RenderPoint3 operator+(const RenderPoint3&) const;
    RenderPoint3 operator-(const RenderPoint3&) const;
};

__forceinline void RenderSinCos(float angle,float& sine2,float& cosine2) {
    fnv_SinCos(angle,sine2,cosine2);
}

struct RenderMatrix { float xx,xy,xz,yx,yy,yz,zx,zy,zz;
    RenderPoint3 operator*(const RenderPoint3& point) const {
        RenderPoint3 product;
        product.x=xx*point.x+xy*point.y+xz*point.z;
        product.y=yx*point.x+yy*point.y+yz*point.z;
        product.z=zx*point.x+zy*point.y+zz*point.z;
        return product;
    }
    __forceinline void SetRotation(float angle) {
        float sine2,cosine2; RenderSinCos(angle,sine2,cosine2);
        xx=cosine2; xy=0.0f; xz=-sine2;
        yx=0.0f; yy=1.0f; yz=0.0f;
        zx=sine2; zy=0.0f; zz=cosine2;
    }
};

struct RenderRect { float left,right,top,bottom; __forceinline RenderRect():left(0),right(0),top(0),bottom(0){} };

struct RenderColor { float r,g,b,a;  };

struct RenderRTTI { void* name; RenderRTTI* parent; };

struct RenderTexture {
    virtual void v0(); virtual void Destroy();
    long refs;
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual unsigned int Width(); virtual unsigned int Height();
    __forceinline void IncRefCount() { InterlockedIncrement(&refs); }
    __forceinline void DecRefCount() { if (!InterlockedDecrement(&refs)) Destroy(); }
};

struct RenderPtr {
    RenderTexture* object;
    __forceinline RenderPtr(RenderTexture* p=0) { object=p; if(object) object->IncRefCount(); }
    __forceinline RenderPtr(const RenderPtr& p) { object=p.object; if(object) object->IncRefCount(); }
    __forceinline ~RenderPtr() { if(object) object->DecRefCount(); }
    __forceinline operator RenderTexture*() const { return object; }
    __forceinline RenderTexture* operator->() const { return object; }
};

struct RenderString { char* text; unsigned short len,maxLen; RenderString(const char*);  __forceinline ~RenderString(){ reinterpret_cast<::TextString *>(this)->FUN_004037f0(0,0); } __forceinline const char* String() const { return text; } };

struct RenderShader {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c; int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; RenderPtr texture;
    int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int textureMode;
    int unk090; int unk094; int unk098;
    struct ClipRect { int left,top,right,bottom; } clip;
    __forceinline RenderTexture* Texture() { RenderTexture* result=texture; return result; }
};

struct RenderData {
    int unk000,unk004; unsigned short vertexCount,unk00a,unk00c,flags;
    struct Bound {  } bound;
    int unk014,unk018,unk01c;
    RenderPoint3* vertices; int unk024,unk028; RenderPoint2* uvs;
     void Update(bool);
    __forceinline RenderPoint3* Vertices() { RenderPoint3* points=vertices; return points; }
    __forceinline RenderPoint2* UVs() { RenderPoint2* points=uvs; return points; }
    __forceinline unsigned short VertexCount() { return vertexCount; }
};

struct RenderObject;

struct RenderObjectRef {
    RenderObject* object;
    RenderObjectRef(RenderObject* value=0);
    ~RenderObjectRef();
    bool operator!=(const RenderObjectRef&) const;
    RenderObjectRef& operator=(const RenderObjectRef&);
};

RenderObjectRef* RenderAllocateChildren(unsigned int);

void RenderFreeChildren(RenderObjectRef*);

struct RenderObject {
    virtual void v0(); virtual void v1(); virtual RenderRTTI* GetRTTI(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual RenderObject* AsGeometry(); virtual void v8(); virtual RenderObject* AsNode();
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; int unk020; int unk024; int unk028; int unk02c; unsigned int flags;
    RenderMatrix rotation; RenderPoint3 translation;
    int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098;
    struct Children {
        void* vtable; RenderObjectRef* buffer; unsigned short capacity,size,end,grow;
        void Begin() {
            if(end==size) return;
            unsigned short index;
            if(end) {
                unsigned short output=0;
                for(index=0;index<size;++index) {
                    if(buffer[index]!=RenderObjectRef(0)) {
                        if(buffer[output]!=buffer[index]) buffer[output]=buffer[index];
                        ++output;
                    }
                }
            }
            RenderObjectRef* old=buffer;
            size=end; capacity=size;
            if(capacity>0) {
                buffer=RenderAllocateChildren(capacity);
                for(index=0;index<size;++index) buffer[index]=old[index];
            } else buffer=0;
            RenderFreeChildren(old);
        }
        void End() {
            while(size>0) {
                if(buffer[size-1]!=RenderObjectRef(0)) break;
                --size;
            }
        }
        __forceinline RenderObject* At(unsigned int idx) {
            RenderObjectRef* slot=buffer+idx; RenderObject* item=slot->object; return item;
        }
    } children;
    int unk0ac; int unk0b0; int unk0b4; RenderData* data;
    __forceinline void Transform(const RenderMatrix& matrix,const RenderPoint3& position,const RenderPoint3& center) {
        rotation=matrix; translation=RenderPoint3((position+center)-(matrix*center));
    }
    __forceinline void PrepareChildren() { reinterpret_cast<::ObjPtrArray *>(&(children))->FUN_004afc80(); reinterpret_cast<::Pn4afe *>(&(children))->TrimTrailingNullPointers(); }
    __forceinline RenderObject* GetAt(unsigned int idx) { return children.At(idx); }
    __forceinline RenderData* Data() { RenderData* result=data; return result; }
    __forceinline unsigned int ChildCount() { return children.end; }
    __forceinline RenderObject* GetChild(unsigned int idx) { if (children.size <= idx) return 0; else return children.At(idx); }
    __forceinline bool Hidden() { return (flags & 1)!=0; }
    __forceinline void SetHidden(bool value, unsigned int bit=1) { if (value) flags |= bit; else flags &= ~bit; }
};

__forceinline bool RenderHasType(RenderRTTI* type) {
    while(type) {
        if(type==&(*reinterpret_cast<::RenderRTTI *>(&::g_011f4a40))) return true;
        type=type->parent;
    }
    return false;
}
__forceinline RenderObject* RenderAsShape(RenderObject* object) {
    if(!object) return 0;
    return RenderHasType(object->GetRTTI()) ? object : 0;
}
__forceinline float RenderMaximum(float a,float b) { return b > a ? b : a; }
__forceinline float RenderMinimum(float a,float b) { return a < b ? a : b; }

struct RenderValue { int trait; void* owner; float value; char* string; void* extra; };

struct RenderTile {
    virtual void v0(); virtual void v1(); virtual void* HasModel(); virtual int Type();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void SetColor(RenderObject*,float,RenderColor*);
    int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c; const char* name; int unk024;
    RenderTile* parent; RenderObject* model; unsigned int flags;
    unsigned char unk034; bool speechFailure; unsigned short unk036;
    float textureScale; RenderPtr cachedTexture;
    float GetFloat(int);  RenderValue* GetValue(int); char* GetString(int);
      
       
       
    __forceinline RenderObject* Model() { RenderObject* result=model; return result; }
    __forceinline bool Flag(unsigned int bit) { return (flags & bit)!=0; }
    __forceinline float TextureScale() { float scale=textureScale; return scale; }
    __forceinline RenderPoint3 Center() {
        float x=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xffb); float y=-reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xffc);
        return RenderPoint3(x,0.0f,y);
    }
    __forceinline void UpdateText() { RenderTile* text=this; reinterpret_cast<::Tile3DCalc *>((text))->LoadTile(); }
    __forceinline RenderTile* Parent() { RenderTile* result=parent; return result; }
    __forceinline bool SpeechFailure() { bool result=speechFailure; return result; }
    __forceinline const char* Name() { const char* result=name; return result; }
    bool FUN_00a04640(bool clear);
};

extern bool renderVisibilityChanged;

extern int renderUpdateCount;

void RenderLoadTexture(const char*,float*,RenderPtr*,float,RenderPtr);

struct RenderColorManager {  static RenderColorManager* GetSingleton(); };

extern float renderSpeechRed;

extern const char renderDefaultTexture[];

extern const char renderEmpty[];

extern const char renderHighlight[];

extern const char* volatile renderDefaultAtlas;

// @fnv 0x00a04640
bool RenderTile::FUN_00a04640(bool clear) {
    EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_011f3330));
    bool changed=false;
    bool imageB;
    bool dynamicGeometry;
    if (flags & 0x3ff) {
        RenderHeapScope var1C;
        if (flags & 2) {
            reinterpret_cast<::SceneNodeOwner *>(this)->FUN_00a08a20();
            if (HasModel()) {
                if (Type()==0x387) ::SetFlagAtOffsetDC(true);
                changed=true;
                if(clear && (flags & 2)) flags ^= 2;
            }
        }
        if ((flags & 4) && Model()) {
            bool oldHiddenTmp=Model()->Hidden();
            Model()->SetHidden(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa3)==0.0);
            changed=true;
            if(oldHiddenTmp && oldHiddenTmp!=Model()->Hidden()) renderVisibilityChanged=true;
            if(clear && (flags & 4)) flags ^= 4;
        }
        if (::Interface::IsAnyMenuOpen() && Model()) {
            RenderObject* childVal5=Model()->GetChild(0);
            if(Type()==0x386 && childVal5) {
                RenderShader* var28=((::RenderShader *)(reinterpret_cast<::FUN_00a59d30_C *>((childVal5))->FUN_00a59d30(3)));
                if(var28) { reinterpret_cast<::TileShaderProperty *>((var28))->FUN_00bb7a10((::NiTexture *)(::RenderTexture *)(0)); reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x20); }
            }
        }
        imageB=(Type()==0x386 || Type()==0x38a);
        RenderRect sheet_2;
        sheet_2.bottom=-1.0f; sheet_2.left=-1.0f; sheet_2.right=-1.0f; sheet_2.top=-1.0f;
        if (imageB && (flags & 0x20) && Model()) {
            RenderObject* varE9=Model()->GetChild(0);
            if (imageB && varE9 && (Flag(0x1000) || reinterpret_cast<::sa040a0::Owner *>(this)->IsAllChildrenFlag0())) {
                RenderShader* varF9=((::RenderShader *)(reinterpret_cast<::FUN_00a59d30_C *>((varE9))->FUN_00a59d30(3)));
                if (varF9) {
                    RenderTile* tileA=this;
                    RenderPtr textureCheck9;
                    RenderValue* valueX2=((::RenderValue *)(reinterpret_cast<::FUN_00a00f30_shell *>(this)->FUN_00a00f30(0xfcc)));
                    void* extra11=0;
                    const char* var6c9=0;
                    bool fallbackX=false;
                    if(valueX2) { extra11=valueX2->extra; var6c9=valueX2->string; }
                    if((!var6c9 || !*var6c9) && !extra11) {
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(this)->FUN_00a01350(0xfcc,(char *)("Interface\\Shared\\empty.dds"),true);
                        var6c9=GetString(0xfcc);
                        fallbackX=true;
                    }
                    if(var6c9 && *var6c9) {
                        if(fallbackX || ((::RenderValue *)(reinterpret_cast<::FUN_00a00f30_shell *>(this)->FUN_00a00f30(0xff9)))) {
                            RenderString resolved4("");
                            const char* sheetName_=fallbackX ? reinterpret_cast<RenderAtlasSetting*>(&::g_011f3368)->GetValue() : GetString(0xff9);
                            ::FUN_00a06dd0(sheetName_,GetString(0xfcc),(::GameString<char> *)(::RenderString *)(&resolved4),(float *)(::RenderRect *)(&sheet_2));
                            RenderLoadTexture(resolved4.String(),&tileA->textureScale,&textureCheck9,reinterpret_cast<::TileListBoxCalls *>((tileA))->GetFloat(0xfb8),tileA->cachedTexture);
                        }
                        if(!textureCheck9) {
                            RenderLoadTexture(var6c9,&tileA->textureScale,&textureCheck9,reinterpret_cast<::TileListBoxCalls *>((tileA))->GetFloat(0xfb8),tileA->cachedTexture);
                        }
                    }
                    if(textureCheck9) {
                        reinterpret_cast<::TileShaderProperty *>((varF9))->FUN_00bb7a10((::NiTexture *)(::RenderTexture *)(textureCheck9));
                        if(reinterpret_cast<::FUN_00a01230_shell *>(this)->IsTraitNonZero(0xfb5)) varF9->textureMode=2; else varF9->textureMode=0;
                        float var4=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb8);
                        const char* pathY=GetString(0xfcc);
                        float width2=(float)textureCheck9->Width();
                        float heightSquaredX=(float)textureCheck9->Height();
                        if(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb5)==-1.0) {
                            if(!pathY || !*pathY || (*pathY==' ' && !pathY[1])) {
                                reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfcd,width2,true); reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfce,heightSquaredX,true);
                            } else {
                                reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfcd,width2/tileA->textureScale,true); reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfce,heightSquaredX/tileA->textureScale,true);
                            }
                            reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x10);
                            var4=-1.0f;
                        }
                        if(var4>=0.0) {
                            if(var4==0.0) var4=100.0f;
                            if(!pathY || !*pathY || (*pathY==' ' && !pathY[1])) {
                                reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfcd,width2*(var4/100.0),true); reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfce,heightSquaredX*(var4/100.0),true);
                            } else {
                                reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfcd,width2*(var4/100.0)/tileA->textureScale,true);
                                reinterpret_cast<::FUN_00a012d0_t *>(this)->FUN_00a012d0(0xfce,heightSquaredX*(var4/100.0)/tileA->textureScale,true);
                            }
                            reinterpret_cast<::FUN_00a07530_shell *>(this)->FUN_00a07530(0x10);
                        }
                        changed=true;
                        if(clear && (flags & 0x20)) flags ^= 0x20;
                    } else if(clear && !reinterpret_cast<::FUN_00a01230_shell *>(this)->IsTraitNonZero(0xfa3) && (flags & 0x20)) flags ^= 0x20;
                }
            }
        }
        dynamicGeometry=false;
        if ((flags & 0x10) && Model()) {
            RenderObject* childNode4=Model()->GetChild(0);
            RenderObject* geometryX=childNode4 ? childNode4->AsGeometry() : 0;
            RenderData* var8c3=geometryX ? geometryX->Data() : 0;
            if(var8c3 && (var8c3->flags & 0x7000)==0x4000) dynamicGeometry=true;
        }
        if ((flags & 0x10) && Model()) {
            RenderObject* childB=Model()->GetChild(0);
            float widthX=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb1);
            float var4cVal=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb0);
            float var64=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfc0);
            float var8=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfbf);
            RenderObject* geometry9=childB;
            if(geometry9 && Type()==0x386) {
                if(!dynamicGeometry && geometry9->Data()->Vertices()) {
                    RenderPoint3* verticesTmp=geometry9->Data()->Vertices();
                    verticesTmp[0]=RenderPoint3(0.0f,0.0f,0.0f);
                    verticesTmp[1]=RenderPoint3(0.0f,0.0f,-var4cVal);
                    verticesTmp[2]=RenderPoint3(widthX,0.0f,0.0f);
                    verticesTmp[3]=RenderPoint3(widthX,0.0f,-var4cVal);
                }
                float textureWidth4=widthX;
                float textureHeight2=var4cVal;
                RenderShader* propA=((::RenderShader *)(reinterpret_cast<::FUN_00a59d30_C *>((childB))->FUN_00a59d30(3)));
                if(propA && imageB && propA->Texture()) {
                    if(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb5)!=0.0) propA->textureMode=2; else propA->textureMode=0;
                    float zoom=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb8);
                    if(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb5)==-1.0) {
                        textureWidth4=propA->Texture()->Width()*(var4cVal/propA->Texture()->Height());
                    } else if(zoom>=0.0) {
                        if(zoom==0.0) zoom=100.0f;
                        const char* path2=GetString(0xfcc);
                        if(!path2 || !*path2 || (*path2==' ' && !path2[1])) {
                            textureWidth4=propA->Texture()->Width()*(zoom/100.0);
                            textureHeight2=propA->Texture()->Height()*(zoom/100.0);
                        } else {
                            RenderTile* tile14=this;
                            textureWidth4=propA->Texture()->Width()*(zoom/100.0)/tile14->TextureScale();
                            textureHeight2=propA->Texture()->Height()*(zoom/100.0)/tile14->TextureScale();
                        }
                    } else { textureWidth4=widthX; textureHeight2=var4cVal; }
                }
                RenderPoint2* var6c=geometry9->Data()->UVs();
                if(var6c) {
                    float left8=var64/textureWidth4;
                    float top2=var8/textureHeight2;
                    float uWidth4=widthX/textureWidth4;
                    float vHeight4=var4cVal/textureHeight2;
                    if(((::RenderValue *)(reinterpret_cast<::FUN_00a00f30_shell *>(this)->FUN_00a00f30(0xff9)))) {
                        RenderRect subrect4;
                        float sheetWidthXEx=0.0f;
                        float varC7=0.0f;
                        if(sheet_2.right!=-1.0 && sheet_2.bottom!=-1.0) subrect4=sheet_2;
                        else ::FUN_00a06dd0(GetString(0xff9),GetString(0xfcc),(::GameString<char> *)(::RenderString *)(0),(float *)(::RenderRect *)(&subrect4));
                        sheetWidthXEx=subrect4.right-subrect4.left;
                        varC7=subrect4.bottom-subrect4.top;
                        if(sheetWidthXEx>0.0 && varC7>0.0) {
                            left8=left8*sheetWidthXEx+subrect4.left;
                            top2=top2*varC7+subrect4.top;
                            uWidth4=sheetWidthXEx; vHeight4=varC7;
                        }
                        float var14=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb8);
                        if(var14>0.0) {
                            var14=(float)(var14/100.0);
                            uWidth4=(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb1)/reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfcd))*var14;
                            vHeight4=(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb0)/reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfce))*var14;
                        }
                    }
                    var6c[0]=RenderPoint2(left8,top2);
                    var6c[1]=RenderPoint2(left8,top2+vHeight4);
                    var6c[2]=RenderPoint2(left8+uWidth4,top2);
                    var6c[3]=RenderPoint2(left8+uWidth4,top2+vHeight4);
                }
                if(!dynamicGeometry) {
                    if(geometry9->Data()) reinterpret_cast<::NiGeometryData *>((geometry9->Data()))->SetDirtyFlags(9);
                    RenderPoint3* verticesCheck2=geometry9->Data()->Vertices();
                    reinterpret_cast<::Bound88 *>(&(geometry9->Data()->bound))->ComputeBoundingSphere(geometry9->Data()->VertexCount(),(const ::Vec88 *)(verticesCheck2));
                }
                changed=true;
                RenderData* data8=geometry9->Data();
                if(data8) data8->Update(false);
            }
            if(clear && (flags & 0x10)) flags ^= 0x10;
        }
        if((flags & 0x40) && Model()) {
            if(Type()==0x388) { RenderTile* text_=this; reinterpret_cast<::Tile3DCalc *>((text_))->LoadTile(); }
            changed=true;
            if(clear && (flags & 0x40)) flags ^= 0x40;
        }
        if((flags & 1) && Model()) {
            if(reinterpret_cast<::FUN_00a01230_shell *>(this)->IsTraitNonZero(0xfa8) || parent==((::RenderTile *)(::Interface::GetPrimaryInterfaceTile()))) {
                float depth_=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfad);
                RenderPoint3 position22=(*reinterpret_cast<::RenderPoint3 *>((void *)&::NiPoint3::ZERO));
                position22.x=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa1);
                position22.z=-reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa2);
                position22.y=(float)(depth_*::DAT_0106f290);
                if(parent==((::RenderTile *)(::Interface::GetPrimaryInterfaceTile()))) {
                    position22.x-=::Interface::UpdateInterfaceState()/2.0;
                    position22.z=(float)((position22.z+::Interface::GetFirstInterfaceFloat())-::Interface::GetFirstInterfaceFloat()/2.0);
                }
                Model()->translation=position22;
                if(flags & 0x200) {
                    RenderObject* node1=Model();
                    for(unsigned int index1=0; node1 && index1<node1->ChildCount(); ++index1) {
                        RenderObject* childValA=node1->GetChild(index1);
                        RenderObject* childNodeA=childValA ? childValA->AsNode() : 0;
                        if(childNodeA && !Flag(0x8000)) childNodeA->translation=(*reinterpret_cast<::RenderPoint3 *>((void *)&::NiPoint3::ZERO));
                    }
                }
                reinterpret_cast<::FUN_00a079d0_shell *>(this)->UpdateTileChildren();
            } else {
                float varCA=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfad);
                RenderPoint3 position5=(*reinterpret_cast<::RenderPoint3 *>((void *)&::NiPoint3::ZERO));
                Model()->translation=position5;
                position5.x+=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa1);
                position5.z+=-reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa2);
                position5.y+=varCA*::DAT_0106f290;
                RenderObject* node7=Model();
                for(unsigned int indexA6=0; node7 && indexA6<node7->ChildCount(); ++indexA6) {
                    RenderObject* shapeB=RenderAsShape(node7->children.At(indexA6));
                    RenderPoint3 center3=Center();
                    RenderMatrix rotationW5;
                    rotationW5.SetRotation(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xffa));
                    if(shapeB) shapeB->Transform(rotationW5,position5,center3);
                }
            }
            changed=true;
            if(clear && (flags & 1)) flags ^= 1;
        }
        if(clear && (flags & 0x200)) flags ^= 0x200;
        if(Model() && (flags & 0x80)) {
            float widthTmp=::Interface::GetFourthInterfaceFloat();
            float var50=::Interface::GetThirdInterfaceFloat();
            if(reinterpret_cast<::Tile *>(this)->IsMenuRendered()) { widthTmp=::FUN_00706e80(); var50=::FUN_00706e90(); }
            float scaleX3=widthTmp/::Interface::UpdateInterfaceState();
            float varF6=var50/::Interface::GetFirstInterfaceFloat();
            if(::FUN_00707a30((::QuantityData *)(void *)(((void *)(reinterpret_cast<::FUN_00a03c90_shell *>(this)->FUN_00a03c90()))))) scaleX3*=::Interface::GetInterfaceFloat();
            float leftNode7=reinterpret_cast<::FUN_00a013d0_shell *>(this)->GetTotalFloat();
            float topic2=reinterpret_cast<::FUN_00a01440_shell *>(this)->GetAccumulatedFloat();
            float rightA=(leftNode7+reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb1))*scaleX3;
            float varE7=(topic2+reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb0))*varF6;
            leftNode7*=scaleX3; topic2*=varF6;
            reinterpret_cast<::ClipTile *>(this)->FUN_00a07a40(leftNode7,topic2,rightA,varE7);
            changed=true;
            if(clear && (flags & 0x80)) flags ^= 0x80;
        }
        if(Model() && (flags & 0x100)) {
            RenderTile* clipParent=parent;
            while(clipParent) {
                if(reinterpret_cast<::FUN_00a01230_shell *>((clipParent))->IsTraitNonZero(0xfa6)) break;
                clipParent=clipParent->parent;
            }
            if(clipParent) {
                float widthTmp=::Interface::GetFourthInterfaceFloat();
                float var114=::Interface::GetThirdInterfaceFloat();
                if(reinterpret_cast<::Tile *>(this)->IsMenuRendered()) { widthTmp=::FUN_00706e80(); var114=::FUN_00706e90(); }
                float varF2=widthTmp/::Interface::UpdateInterfaceState();
                float var70=var114/::Interface::GetFirstInterfaceFloat();
                if(::FUN_00707a30((::QuantityData *)(void *)(((void *)(reinterpret_cast<::FUN_00a03c90_shell *>(this)->FUN_00a03c90()))))) varF2*=::Interface::GetInterfaceFloat();
                float leftNodeA=reinterpret_cast<::FUN_00a013d0_shell *>((clipParent))->GetTotalFloat();
                float topicCount8=reinterpret_cast<::FUN_00a01440_shell *>((clipParent))->GetAccumulatedFloat();
                float right5=(leftNodeA+reinterpret_cast<::TileListBoxCalls *>((clipParent))->GetFloat(0xfb1))*varF2;
                float var4c=(topicCount8+reinterpret_cast<::TileListBoxCalls *>((clipParent))->GetFloat(0xfb0))*var70;
                leftNodeA*=varF2; topicCount8*=var70;
                unsigned int indexB_=0;
                Model()->PrepareChildren();
                while(indexB_<Model()->ChildCount()) {
                    RenderObject* child_=Model()->GetAt(indexB_);
                    RenderShader* _prop=((::RenderShader *)(reinterpret_cast<::FUN_00a59d30_C *>((child_))->FUN_00a59d30(3)));
                    if(_prop) {
                        RenderShader::ClipRect rect24 = {
                            (int)RenderMaximum(0.0f,leftNodeA), (int)RenderMaximum(0.0f,topicCount8),
                            (int)RenderMinimum(right5,widthTmp), (int)RenderMinimum(var4c,var114)
                        };
                        _prop->clip=rect24;
                        reinterpret_cast<::FUN_00bb79d0_class *>((_prop))->FUN_00bb79d0(true);
                    }
                    ++indexB_;
                }
            }
            changed=true;
            if(clear && (flags & 0x100)) flags ^= 0x100;
        }
        if(flags & 8) {
            RenderColor color9;
            color9.r=1.0f; color9.g=1.0f; color9.b=1.0f; color9.a=1.0f;
            float alphaB=(float)(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfa9)/255.0);
            float brightness_=reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xff5);
            if(brightness_>=0.0) brightness_=(float)(brightness_/255.0);
            if(brightness_>=0.0) {
                int colorID5=0;
                RenderTile* ancestor3=this;
                while(ancestor3 && !((::RenderValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((ancestor3))->FUN_00a00f30(0xff4))) && reinterpret_cast<::TileListBoxCalls *>((ancestor3))->GetFloat(0xfaa)!=111.0) {
                    if(ancestor3->Parent() && ancestor3->Parent()->Parent() && !ancestor3->Parent()->Parent()->Parent() && reinterpret_cast<::TileListBoxCalls *>((ancestor3))->GetFloat(0xfaa)==110.0) {
                        colorID5=(int)reinterpret_cast<::TileListBoxCalls *>((ancestor3))->GetFloat(0xff4);
                        if(!colorID5) colorID5=(int)reinterpret_cast<::TileListBoxCalls *>((ancestor3->Parent()))->GetFloat(0xff4);
                        if(!colorID5) colorID5=1;
                        ancestor3=0; break;
                    }
                    ancestor3=ancestor3->parent;
                }
                if(ancestor3) colorID5=(int)reinterpret_cast<::TileListBoxCalls *>((ancestor3))->GetFloat(0xff4);
                if(reinterpret_cast<::SystemColorManager *>((((::RenderColorManager *)(::FUN_00718b60()))))->GetColor(colorID5,(::NiColor &)(color9))) reinterpret_cast<::RgbaColor *>(&(color9))->FUN_005321d0(brightness_);
                else brightness_=-1.0f;
            }
            if(brightness_==-1.0) {
                color9.r=(float)(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb2)/255.0);
                color9.g=(float)(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb3)/255.0);
                color9.b=(float)(reinterpret_cast<::TileListBoxCalls *>(this)->GetFloat(0xfb4)/255.0);
            }
            if(SpeechFailure()) {
                if(::std::strcmp(Name(),"lb_highlight_box")==0) {
                    color9.r=renderSpeechRed; color9.g=0.0f; color9.b=0.0f; alphaB=0.2f;
                } else if(Parent() && ::std::strcmp(Parent()->Name(),"lb_highlight_box")==0) {
                    color9.r=renderSpeechRed; color9.g=0.0f; color9.b=0.0f; alphaB=1.0f;
                }
            }
            SetColor(Model(),alphaB,&color9);
            if(clear && (flags & 8)) flags ^= 8;
        }
    }
    if(clear && (flags & 0x3ff)) ::fnv_00a077c0::FUN_00a077c0((::Tile *)(::RenderTile *)(this)); else ++renderUpdateCount;
    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(&DAT_011f3330));
    return changed;
}


namespace fnv_00a09410 {
struct P03MM { void* Allocate(unsigned int); void Deallocate(void*); };
__forceinline int GetMemoryContext() { return (*reinterpret_cast<int *>(&::currentAllocationContext)); }
__forceinline void SetMemoryContext(int value) { (*reinterpret_cast<int *>(&::currentAllocationContext))=value; }
struct ValueContext {
 int saved;
 __forceinline ValueContext() { saved=GetMemoryContext(); SetMemoryContext(13); }
 __forceinline ~ValueContext() { SetMemoryContext(saved); }
};
struct StackAllocation { virtual void Destroy(); virtual float* Allocate(unsigned); };
struct EvalStack {
 __forceinline unsigned GetSize() { return size; }
 __forceinline float& GetAt(unsigned index) { return data[index]; }
 int* vtable; float* data; unsigned size; unsigned capacity;
 inline void FUN_006b3eb0(unsigned reserved,unsigned initial) {
 data=0; size=0; capacity=0;
 if(initial>reserved) reserved=initial;
 if(reserved>0) { data=((StackAllocation*)this)->Allocate(reserved); capacity=reserved; }
 if(initial>0) { Construct(data,initial); size=initial; }
 }
 __forceinline void Construct(float* start,unsigned count) { for(unsigned i=0;i<count;++i) { operator new(sizeof(float),start+i); } }
 unsigned FUN_00761540();
 inline unsigned AppendFloat(float* value) {
 unsigned index=FUN_00761540();
 Construct(data+index,1);
 data[index]=*value;
 return index;
 }
 __forceinline EvalStack(unsigned start=0,unsigned growth=0) { vtable=&::fnv_006db720::DAT_0106cc64; FUN_006b3eb0(start,growth); }
 __forceinline ~EvalStack() { reinterpret_cast<::fnv_006db720::FUN_006db720_Class *>(this)->FUN_006db720(); }
 __forceinline void RemoveLast(unsigned count) {
  if(!size) return;
  for(unsigned i=0;i<count;++i) {}
  size-=count;
 }
};





struct TraitLookup {  };
__forceinline float Minimum(float a,float b) { return a<b?a:b; }
__forceinline float Maximum(float a,float b) { return a>b?a:b; }
__forceinline float FloorValue(float a) { return (float)std::floor(a); }
__forceinline float CeilValue(float a) { return (float)std::ceil(a); }
__forceinline float AbsValue(float a) { return (float)std::fabs(a); }
__forceinline double RoundMultiple(float a,const float& b) { float quotient=a/b; return ((int)quotient+(quotient-(int)quotient<0.5?0:1))*b; }

// @fnv 0x00a09410
void EvalValue::FUN_00a09410(bool update) {
 if((pTile->flags&0x10000) && m_iValueId!=4004) return;
 if(!pTile || pTile->Flag(0x4000)) return;

 char* newNumberText_;
 char* oldNumberTextTmp;
 char* newText;
 char* oldText4;
 int remaining;
 int digits2;
 int numberTmp;
 unsigned lengthVal3;
 float saved9;
 EvalReference* resolvedA;
 int lookup4;
 EvalReference* reference5;
 float operandTmp;
 const char* text3;
 int operationX;
 EvalAction* action43;
 bool changedVal3;
 float oldValue9;
 ValueContext context4_2;
 action43=actions;
 oldValue9=fValue;
 EvalStack stackVal;
 changedVal3=false;
 while(action43) {
  operandTmp=action43->GetFloat();
  text3=0;
  if(action43->GetReference()) {
   reference5=action43->GetReference();
   lookup4=0;
   text3=reference5->text;
   if(reference5->trait>=10000) reinterpret_cast<::S_00adc830_Map *>(&((*reinterpret_cast<::fnv_00a09410::TraitLookup *>(&::DAT_011f3308))))->GetAt(reference5->trait,(*(::S_00adc830_Entry * *)(&lookup4)));
   if(lookup4==-1) {
    resolvedA=((::fnv_00a09410::EvalReference *)(reinterpret_cast<::FUN_00a0a0b0_shell *>((reference5->tile))->FUN_00a0a0b0(reference5->trait,fnv_FloatToInt(fValue))));
    if(resolvedA) { operandTmp=resolvedA->value; text3=resolvedA->text; }
   }
  }
  operationX=action43->operation;
  if(operationX==2024) { reinterpret_cast<::FloatArr *>(&(stackVal))->AppendFloat(&fValue); fValue=0; }
  else if(operationX==2025) {
   saved9=stackVal.data[stackVal.size-1];
   operationX=fnv_FloatToInt(action43->GetFloat());
   operandTmp=fValue;
   fValue=saved9;
   stackVal.RemoveLast(1);
  }
  switch(operationX) {
   case 2000:
    if(text3) {
     lengthVal3=std::strlen(text3);
     changedVal3=!pString || std::strcmp(String(),text3);
     if(pString) { oldText4=pString; reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a09410::P03MM *>(&::g_memoryManager))))->FUN_00aa4060(oldText4); pString=0; }
     newText=(char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00a09410::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(lengthVal3+1); pString=newText;
     fnv::crt::strcpy_s(String(),lengthVal3+1,text3);
    } else fValue=operandTmp;
    break;
   case 2001: fValue+=operandTmp; break;
   case 2002: fValue-=operandTmp; break;
   case 2003: fValue*=operandTmp; break;
   case 2004: if(operandTmp!=0.0) fValue/=operandTmp; break;
   case 2005: fValue=Minimum(fValue,operandTmp); break;
   case 2006: fValue=Maximum(fValue,operandTmp); break;
   case 2007: if(operandTmp!=0.0) {
    fValue=fnv_FloatToInt(fValue)%fnv_FloatToInt(operandTmp);
   } break;
   case 2008: fValue=(double)FloorValue(fValue+operandTmp); break;
   case 2009: fValue=(double)CeilValue(fValue+operandTmp); break;
   case 2010: fValue=(double)AbsValue(fValue+operandTmp); break;
   case 2011: fValue=RoundMultiple(fValue,operandTmp); break;
   case 2012: fValue=fValue>operandTmp?1:0; break;
   case 2013: fValue=fValue>=operandTmp?1:0; break;
   case 2014: fValue=fValue==operandTmp?1:0; break;
   case 2015: fValue=fValue!=operandTmp?1:0; break;
   case 2016: fValue=fValue<operandTmp?1:0; break;
   case 2017: fValue=fValue<=operandTmp?1:0; break;
   case 2018:
    if(text3) fValue=fValue!=0.0 && text3?1:0;
    else fValue=fValue!=0.0 && operandTmp!=0.0?1:0;
    break;
   case 2019:
    if(text3) fValue=fValue!=0.0 || text3?1:0;
    else fValue=fValue!=0.0 || operandTmp!=0.0?1:0;
    break;
   case 2020:
    if(text3) fValue=!text3;
    else fValue=operandTmp==0.0?1:0;
    break;
   case 2021: if(operandTmp==0.0 && !text3) fValue=0; break;
   case 2022: if(operandTmp!=0.0 || text3) fValue=0; break;
  }
  action43=action43->next;
 }
 if(!pString) changedVal3=oldValue9!=fValue;
 if(oldValue9!=fValue && m_iValueId==4036) {
  numberTmp=fnv_FloatToInt(fValue);
  digits2=numberTmp==0;
  for(remaining=numberTmp;remaining;remaining/=10) ++digits2;
  if(numberTmp<0) ++digits2;
  if(!pString || (pString && std::strlen(String())!=digits2)) {
   oldNumberTextTmp=pString; reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a09410::P03MM *>(&::g_memoryManager))))->FUN_00aa4060(oldNumberTextTmp);
   newNumberText_=(char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00a09410::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(digits2+1); pString=newNumberText_;
  }
  ::FUN_00406d00(pString,digits2+1,::InventorySelection::DAT_01020764,numberTmp);
  changedVal3=true;
 }
 if(changedVal3 || update) {
  ::NotifyHandlersByKey((unsigned int)(this));
  if(pTile && !pTile->Flag(0x2000)) {
   if(!pTile->ChangeValue(m_iValueId,fValue,pString)) reinterpret_cast<::UpdateTreeNode *>((pTile))->FUN_00a037e0(m_iValueId,fValue,pString);
  }
 }
}
}

// namespace fnv_00a09410

struct Input02D40 { unsigned int m00; char* m04; };

typedef unsigned short U16_02D40;

extern char str_01094a64[], str_01094a4c[];

__forceinline int RenderCopyData(char* dest, unsigned capacity, const char* source) { return fnv::crt::strcpy_s(dest, capacity, source); }
__forceinline void CopyPrefix(char* dest, const char* source, const char* begin) {
    unsigned length = begin - source;
    fnv::crt::strncpy_s(dest, length + 1, source, length);
}
__forceinline void CopyMiddle(char* dest, const char* begin, unsigned skip, const char* next) {
    unsigned length = next - begin - skip;
    fnv::crt::strncpy_s(dest, length + 1, begin + skip, length);
}

template<class T> __forceinline unsigned StringLength(const T* text) { return std::strlen(text); }
__forceinline unsigned CapacityMaximum(unsigned a, unsigned b) { return a > b ? a : b; }

struct StrMem {
    union {
        struct { char* m00; unsigned short m04, m06; };
    };
    inline bool Set(const char*, unsigned int);
    inline StrMem& FUN_00404820(const char*);
    __forceinline void SetLength(unsigned int n) { m04 = n <= 65535U ? (unsigned short)n : 65535; }
    __forceinline void SetCapacity(unsigned int n) { m06 = n <= 65535U ? (unsigned short)n : 65535; }
    __forceinline unsigned MaxLength() const { return m06; }
    __forceinline void Init() { m00 = 0; SetLength(0); SetCapacity(0); }
    __forceinline StrMem() { Init(); }
    __forceinline ~StrMem() { reinterpret_cast<::TextString *>(this)->FUN_004037f0(0, 0); }
    __forceinline const char* String() const { return m00; }
    __forceinline unsigned int Length() const { return m04 == 65535 ? StringLength(m00) : m04; }
};

inline bool StrMem::Set(const char* text, unsigned int capacity) {
    unsigned int length = text ? StringLength(text) : 0;
    unsigned int needed = CapacityMaximum(length, capacity);
    unsigned int previousCapacity = MaxLength();
    char* previousBuffer = m00;
    if (needed <= previousCapacity) {
        if (needed) {
            if (text) ::__memcpy(previousBuffer, text, length + 1);
            else previousBuffer[0] = 0;
        } else {
            if (previousBuffer) delete[] previousBuffer;
            m00 = 0;
            needed = 0;
            SetCapacity(needed);
        }
    } else {
        char* old = previousBuffer;
        m00 = new char[needed + 1];
        if (text) ::__memcpy(m00, text, length + 1);
        else m00[0] = 0;
        if (old) delete[] old;
        SetCapacity(needed);
    }
    SetLength(length);
    return length != 0;
}

inline StrMem& StrMem::FUN_00404820(const char* text) {
    if (text) {
        const char* current = String();
        if (current) {
            unsigned int extra = text ? StringLength(text) : 0;
            unsigned int needed = Length() + extra;
            if (needed > MaxLength()) reinterpret_cast<::TextString *>(this)->FUN_004037f0(current, needed);
            ::__memcpy(m00 + Length(), text, extra + 1);
            SetLength(needed);
        } else reinterpret_cast<::TextString *>(this)->FUN_004037f0(text, 0);
    }
    return *this;
}

struct Record02D40 {
    unsigned int m00;
    char* m04;
    inline ~Record02D40() { reinterpret_cast<::MenuValueDescriptor *>(this)->MenuValueDescriptor::~MenuValueDescriptor(); }
};

// @fnv 0x00a02d40
bool __cdecl FUN_00a02d40(Input02D40* arg) {
    char* source3 = arg->m04;
    char* begin_2 = std::strstr((char *)(source3), str_01094a64);
    if (begin_2) {
        StrMem i;
        unsigned int h = arg->m00 + 1;
        char* p9 = new char[h];
        std::memset(p9, 0, h);
        CopyPrefix(p9, source3, begin_2);
        reinterpret_cast<::TextString *>(&(i))->FUN_004037f0(p9, 0x4000);
        bool a = false;
        while (!a) {
            StrMem tokenA;
            unsigned int skip = std::strchr((char *)(begin_2), '>') - begin_2 + 1;
            std::memset(p9, 0, h);
            char* context_2;
            fnv::crt::strtok_s(begin_2, (*reinterpret_cast<char (*)[]>(&::fnv_00ac9790::DAT_01021184)), &context_2);
            ::FUN_00406f60((::FUN_00406f90_this *)(::StrMem *)(&tokenA), str_01094a4c, fnv::crt::strtok_s(0, (*reinterpret_cast<char (*)[]>(&::fnv_00ac9790::DAT_01021184)), &context_2));
            Record02D40* record = ((::Record02D40 *)(::GetOrLoadXML(tokenA.String(), 0)));
            i.FUN_00404820(record->m04);
            delete record;
            char* next9 = std::strstr((char *)(begin_2 + skip), str_01094a64);
            std::memset(p9, 0, h);
            if (next9) {
                CopyMiddle(p9, begin_2, skip, next9);
                begin_2 = next9;
            } else {
                fnv::crt::strcpy_s(p9, h, begin_2 + skip);
                a = true;
            }
            i.FUN_00404820(p9);

        }
        delete[] arg->m04;
        arg->m04 = new char[i.Length() + 1];
        RenderCopyData(arg->m04, i.Length() + 1, i.String());
        arg->m00 = i.Length();
        delete[] p9;
        FUN_00a02d40(arg);
        return true;
    }
    return false;
}

#include "generated/data/bsmenu/tile.inc"
#include "generated/data/bsmenu/tile_ob1_variant.inc"
#include "generated/data/bsmenu/tile_ob1_variant_helpers_variant.inc"
