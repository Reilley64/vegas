// fallout/interface/menumanager.cpp: MenuSystem, TutorialMenu, QuantityMenu, StatsMenu and more (50 functions)

#include <cstdint>
#include <new>
#include "fnv/simple_list_node_view.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0071f570_ModelList.h"
#include "fnv/decl/FUN_0071f600.h"
#include "fnv/decl/FUN_0071f700.h"
#include "fnv/decl/FUN_00723fd0_shell.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_007b8f10_Class.h"
#include "fnv/decl/FUN_007e9130_cls.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S725970.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/VLList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a1c520__FUN_00a1c520.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "menumanager_decls.h"
#include "fnv/decl/FUN_004fd3a0_shell.h"
#include "fnv/decl/Script.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_00704000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00716000.h"
#include "fnv/symbols_0073a000.h"
#include "fnv/symbols_0075b000.h"
#include "fnv/symbols_0076b000.h"
#include "fnv/symbols_00784000.h"
#include "fnv/symbols_00788000.h"
#include "fnv/symbols_007cb000.h"

// Creates and returns a new menu instance matching the given menu class, warning and returning 0 for unknown classes.
// @fnv 0x0071e420
Menu* MenuSystem::GetMenuById(int menuClass)
{
    switch (menuClass)
    {
    case 1047:
        return new FUN_0075f070;
    case 1001:
        return new CompanionWheelMenu;
    case 1059:
        return new ContainerMenu;
    case 1023:
        return new MapMenu;
    case 1002:
        return new InventoryMenu;
    case 1003:
        return new FUN_0071f340;
    case 1004:
        return new FUN_0076bb40;
    case 1007:
        return new FUN_00788440;
    case 1008:
        return new FUN_0075b0d0;
    case 1053:
        return new BarterMenu;
    case 1009:
        return new FUN_007617a0;
    case 1012:
        return new SleepWaitMenu;
    case 1013:
        return new FUN_007cb330;
    case 1014:
        return new LockPickMenu;
    case 1016:
        return new FUN_00720a10;
    case 1026:
        return new BookMenu;
    case 1027:
        return new LevelUpMenu;
    case 1036:
        return new RaceSexMenu;
    case 1035:
        return new RepairMenu;
    case 1061:
        return new ItemModMenu;
    case 1058:
        return new RepairServicesMenu;
    case 1055:
        return new HackingMenu;
    case 1057:
        return new ComputersMenu;
    case 1054:
        return new FUN_0071fbf0;
    case 1056:
        return new VATSMenu;
    case 1048:
        return new TraitMenu;
    case 1060:
        return new FUN_00720170;
    case 1075:
        return new CharGenMenu;
    case 1074:
        return new FUN_00720550;
    case 1076:
        return new TraitSelectMenu;
    case 1080:
        return new SlotMachineMenu;
    case 1081:
        return new BlackJackMenu;
    case 1084:
        return new RouletteMenu;
    case 1082:
        return new LoveTesterMenu;
    case 1083:
        return new CaravanMenu;
    case 1077:
        return new RecipeMenu;
    case 1051:
        return new MessageMenu;
    default:
        ::FUN_005b5e40();
        return 0;
    }
}

// Returns the singleton instance, creating it and calling ResizeMenuByClassArray on first request when create is true.
// @fnv 0x0071e290
MenuSystem* MenuSystem::Instance(bool create)
{
    if (create && !DAT_011d8d54)
    {
        DAT_011d8d54 = new MenuSystem;
        DAT_011d8d54->ResizeMenuByClassArray();
        return DAT_011d8d54;
    }
    else
        return DAT_011d8d54;
}

// @fnv 0x0071e400
void MenuSystem::ResizeMenuByClassArray()
{
    reinterpret_cast<::ViewerStrings *>(&(g_menuByClassArray))->SetSize(84);
}

// @fnv 0x0071e340
MenuSystem::MenuSystem()
{
    ResizeMenuByClassArray();
}

struct FUN_006317a0_struct
{
    intptr_t AddEight(intptr_t param_1);
};

// @fnv 0x006317a0
intptr_t FUN_006317a0_struct::AddEight(intptr_t aiValue)
{
    return aiValue + 8;
}

struct FUN_0071e3e0_shell
{
    void FUN_0071e3e0();
};

void FUN_0071e3f0();

// @fnv 0x0071e3e0
void FUN_0071e3e0_shell::FUN_0071e3e0()
{
    FUN_0071e3f0();
}

// @fnv 0x0071e3f0
void FUN_0071e3f0()
{
    DAT_011d8d54 = 0;
}

struct StatsMenu
{
    void* FUN_0071f6d0(unsigned int flags);
};

// Calls FUN_0071f700, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x0071f6d0
void* StatsMenu::FUN_0071f6d0(unsigned int flags)
{
    reinterpret_cast<::FUN_0071f700 *>(this)->FUN_0071f700::~FUN_0071f700();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0071feb0_shell
{
    int FUN_0071feb0();
};

// @fnv 0x0071feb0
int FUN_0071feb0_shell::FUN_0071feb0()
{
    return 0x41e;
}

struct FUN_00720100_shell
{
    int FUN_00720100();
};

// @fnv 0x00720100
int FUN_00720100_shell::FUN_00720100()
{
    return 0x420;
}

struct FUN_00720320_shell
{
    int GetClass();
};

// @fnv 0x00720320
int FUN_00720320_shell::GetClass()
{
    return 0x424;
}

struct FUN_00720760_shell
{
    int FUN_00720760();
};

// @fnv 0x00720760
int FUN_00720760_shell::FUN_00720760()
{
    return 0x432;
}

// @fnv 0x00720df0
int __cdecl FUN_00720df0()
{
    return 0x3ff;
}

struct TGF
{
};
struct VATSMenuView
{
    char pad[0xc];
    TGF* tile;
    unsigned int FUN_00726710();
};
// Returns the result of GetRaceCount on this minus tile's float value at the _num_filtered setting.
// @fnv 0x00726710
unsigned int VATSMenuView::FUN_00726710()
{
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);
    return GetRaceCount((char*)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(numFiltered);
}

class Tile;
class NiNode;
template <class T> class NiPointer
{
  public:
    ~NiPointer();
    NiPointer<T>& operator=(T* pObject);
    T* m_pObject;
};
struct SoundPlaybackHandle
{
    ~SoundPlaybackHandle();
    unsigned int uiSoundID;
    bool m_bLooping;
    unsigned int uiState;
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
    Tile* pRootTile;
    void* pExtraHead;
    void* pExtraNext;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int uiMenuID;
    unsigned int uiVisibility;
};
struct FUN_0071fef0 : public Menu_007a8b10
{
    Tile* tile028;
    Tile* tile02C;
    Tile* tile030;
    Tile* tile034;
    Tile* tile038;
    Tile* tile03C;
    Tile* tile040;
    Tile* tile044;
    Tile* tile048;
    Tile* tile04C;
    Tile* tile050;
    Tile* tile054;
    Tile* tile058;
    Tile* tile05C;
    Tile* tile060;
    Tile* tile064;
    Tile* tile068;
    Tile* tile06C;
    Tile* tile070;
    Tile* tile074;
    Tile* tile078;
    Tile* tile07C;
    Tile* tile080;
    Tile* tile084;
    Tile* tile088;
    Tile* tile08C;
    Tile* tile090;
    SoundPlaybackHandle kSound094;
    SoundPlaybackHandle kSound0A0;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    NiPointer<NiNode> spNodes[6];
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    NiPointer<NiNode> spNode0F0;
    NiPointer<NiNode> spNode0F4;
    virtual ~FUN_0071fef0();
};
// Clears the global NiNode pointers and the menu's spNode0F0 pointer by assigning null to them.
// @fnv 0x0071fef0
FUN_0071fef0::~FUN_0071fef0()
{
    (*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011dadb4)) = 0;
    (*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011dade8)) = 0;
    (*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011dae5c)) = 0;
    spNode0F0 = 0;
}

namespace fnv_00720170 {
class Tile;
class NiNode;
template <class T> class NiPointer
{
  public:
    NiPointer();
    ~NiPointer();
    T* m_pObject;
};
struct Menu_007a8b10
{
    Menu_007a8b10();
    virtual ~Menu_007a8b10();
    Tile* pRootTile;
    void* pExtraHead;
    void* pExtraNext;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int uiMenuID;
    unsigned int uiVisibility;
};
struct FUN_007203c0
{
    FUN_007203c0();
    ~FUN_007203c0();
    Tile* pTile;
    Tile* pLabel;
    Tile* pValue;
    unsigned int uiIndex;
    float fValue;
    float fMin;
    float fScaledValue;
    unsigned int uiFlags;
};
struct FUN_00720170_t : public Menu_007a8b10
{
    Tile* m_pTiles[8];
    int iSelected;
    int iCount;
    float fScroll;
    bool m_bDecalsEnabled;
    void* pTarget;
    void* pCurrent;
    FUN_007203c0 kEntries[9];
    NiPointer<NiNode> spNodes180[11];
    NiPointer<NiNode> spNodes1AC[4];
    NiPointer<NiNode> spNodes1BC[2];
    NiPointer<NiNode> spNodes1C4[2];
    NiPointer<NiNode> spNodes1CC[2];
    NiPointer<NiNode> spNodes1D4[2];
    NiPointer<NiNode> spNodes1DC[2];
    FUN_00720170_t();
    virtual ~FUN_00720170_t();
};
// Zeroes the tile array and initializes the menu's selection, count, scroll, and target pointers.
// @fnv 0x00720170
FUN_00720170_t::FUN_00720170_t()
{
    ::FUN_00403d30(m_pTiles, 0, sizeof(m_pTiles));
    pCurrent = 0;
    iSelected = 0;
    iCount = 1;
    fScroll = 0.0f;
    m_bDecalsEnabled = true;
    pTarget = 0;
}
}  // namespace fnv_00720170

namespace fnv_00720420 {
class Tile;
class NiNode;
template <class T> class NiPointer
{
  public:
    ~NiPointer();
    T* m_pObject;
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
    Tile* pRootTile;
    void* pExtraHead;
    void* pExtraNext;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int uiMenuID;
    unsigned int uiVisibility;
};
struct FUN_007203c0
{
    ~FUN_007203c0();
    Tile* pTile;
    Tile* pLabel;
    Tile* pValue;
    unsigned int uiIndex;
    float fValue;
    float fMin;
    float fScaledValue;
    unsigned int uiFlags;
};
struct FUN_00720420 : public Menu_007a8b10
{
    Tile* tile028;
    Tile* tile02C;
    Tile* tile030;
    Tile* tile034;
    Tile* tile038;
    Tile* tile03C;
    Tile* tile040;
    Tile* tile044;
    Tile* tile048;
    Tile* tile04C;
    Tile* tile050;
    Tile* tile054;
    Tile* tile058;
    Tile* tile05C;
    FUN_007203c0 kEntries[9];
    NiPointer<NiNode> spNodes180[11];
    NiPointer<NiNode> spNodes1AC[4];
    NiPointer<NiNode> spNodes1BC[2];
    NiPointer<NiNode> spNodes1C4[2];
    NiPointer<NiNode> spNodes1CC[2];
    NiPointer<NiNode> spNodes1D4[2];
    NiPointer<NiNode> spNodes1DC[2];
    virtual ~FUN_00720420();
};
// Empty destructor for the menu class; the compiler-generated member destructors run implicitly.
// @fnv 0x00720420
FUN_00720420::~FUN_00720420()
{}
}  // namespace fnv_00720420

namespace fnv_00720860 {
class Tile;
class NiNode;
template <class T> class NiPointer
{
  public:
    ~NiPointer();
    T* m_pObject;
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
    Tile* pRootTile;
    void* pExtraHead;
    void* pExtraNext;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int uiMenuID;
    unsigned int uiVisibility;
};
struct FUN_00723fd0
{
    ~FUN_00723fd0();
    void* pHead;
    void* pNext;
    unsigned int ItemUpdateArray;
    unsigned int uiFlags;
};
struct FUN_00724020
{
    ~FUN_00724020();
    void* pHead;
    void* pNext;
    unsigned int ItemUpdateArray;
    unsigned int uiFlags;
};
struct FUN_00720800
{
    ~FUN_00720800();
    Tile* pTile;
    Tile* pLabel;
    Tile* pValue;
    unsigned int uiIndex;
    float fValue;
    float fMin;
    float fScaledValue;
    unsigned int uiFlags;
};
struct FUN_00720860 : public Menu_007a8b10
{
    Tile* tile028;
    Tile* tile02C;
    Tile* tile030;
    Tile* tile034;
    Tile* tile038;
    Tile* tile03C;
    Tile* tile040;
    Tile* tile044;
    Tile* tile048;
    Tile* tile04C;
    Tile* tile050;
    Tile* tile054;
    Tile* tile058;
    Tile* tile05C;
    Tile* tile060;
    FUN_00723fd0 kList064;
    FUN_00724020 kList074;
    FUN_00720800 kEntries[9];
    FUN_00720800 kEntry1A4;
    NiPointer<NiNode> spNodes1C4[11];
    NiPointer<NiNode> spNodes1F0[4];
    NiPointer<NiNode> spNodes200[2];
    NiPointer<NiNode> spNodes208[2];
    NiPointer<NiNode> spNodes210[2];
    NiPointer<NiNode> spNodes218[2];
    NiPointer<NiNode> spNodes220[2];
    NiPointer<NiNode> spNodes228[2];
    virtual ~FUN_00720860();
};
// Destructor for the menu class; the body is empty and member destructors run implicitly.
// @fnv 0x00720860
FUN_00720860::~FUN_00720860()
{}
}  // namespace fnv_00720860

namespace fnv_00720e60 {
struct RecursiveLock;
class NiAVObject;
class NiNode;
class Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct FUN_00720e60_shell : public MenuSystem
{
    Menu* FindTopMenu();
};

struct TGF
{
};
struct FUN_006317a0_struct
{
};
struct IMH;
class Tile
{
};
struct IMH
{
};
struct Flt
{
    operator unsigned int() const;
};
template <class T> struct NiTPointerList
{
    void* DereferenceIfNotNull(void*) const;
};
class TESObjectREFR;
struct FUN_004ee7d0_node
{
};
struct BSThread
{
};

// @fnv 0x00720e60
Menu* FUN_00720e60_shell::FindTopMenu()
{
    Menu* ptop = 0;
    float fMaxDepth = -100000000.0f;
    void* pListElem = (void*)(uintptr_t)*(Flt*)((char*)((::fnv_00720e60::Tile *)(reinterpret_cast<::InterfaceManager *>((((::fnv_00720e60::IMH *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00586150())) + 4);
    while (pListElem)
    {
        Tile* pmenutile =
            *(Tile**)reinterpret_cast<::FUN_006317a0_struct *>((((FUN_006317a0_struct*)((char*)((::fnv_00720e60::Tile *)(reinterpret_cast<::InterfaceManager *>((((::fnv_00720e60::IMH *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00586150())) + 4))))->AddEight((intptr_t)pListElem);
        Menu* pmenu = 0;
        if (pmenutile)
            pmenu = reinterpret_cast<::FUN_00a03c90_shell *>((pmenutile))->FUN_00a03c90();
        if (pmenu && ((::fnv_00720e60::FUN_004ee7d0_node *)(reinterpret_cast<::Callees *>((((FUN_004ee7d0_node*)pmenu)))->FUN_00726070())))
        {
            if (reinterpret_cast<::TileListBoxCalls *>((((TGF*)((::fnv_00720e60::FUN_004ee7d0_node *)(reinterpret_cast<::Callees *>((((FUN_004ee7d0_node*)pmenu)))->FUN_00726070())))))->GetFloat(0xfad) > fMaxDepth &&
                reinterpret_cast<::TileListBoxCalls *>((((TGF*)((::fnv_00720e60::FUN_004ee7d0_node *)(reinterpret_cast<::Callees *>((((FUN_004ee7d0_node*)pmenu)))->FUN_00726070())))))->GetFloat(0xfa7) != 6008.0 &&
                reinterpret_cast<::ActorMover *>((((BSThread*)pmenu)))->GetCurrentMoveModeType() != 2 && reinterpret_cast<::ActorMover *>((((BSThread*)pmenu)))->GetCurrentMoveModeType() != 4)
            {
                fMaxDepth = reinterpret_cast<::TileListBoxCalls *>((((TGF*)((::fnv_00720e60::FUN_004ee7d0_node *)(reinterpret_cast<::Callees *>((((FUN_004ee7d0_node*)pmenu)))->FUN_00726070())))))->GetFloat(0xfad);
                ptop = pmenu;
            }
        }
        pListElem = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>((void *)(((NiTPointerList<TESObjectREFR*>*)((char*)((::fnv_00720e60::Tile *)(reinterpret_cast<::InterfaceManager *>((((::fnv_00720e60::IMH *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00586150())) + 4))))->DereferenceIfNotNull((int **)(pListElem))));
    }
    return ptop;
}
}  // namespace fnv_00720e60

class Tile
{
  public:
    virtual ~Tile();  // polymorphic: its RTTI is used (rtti_fix.py)
    void Set(int, int);
};
struct ListBoxItem_t
{
    Tile* pTile;
    void* pObject;
    bool m_bFiltered;
};
struct FUN_004ee7d0_node
{
    ListBoxItem_t* pItem;
    FUN_004ee7d0_node* pNext;
};
struct ListBoxBase_t
{
    virtual ~ListBoxBase_t();
};
struct FUN_007254d0_t : public ListBoxBase_t, public FUN_004ee7d0_node
{
    Tile* pParentTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float fTotalHeight;
    void FUN_007254d0();
    void UpdateSpeechChallengeTrait();
};

// @fnv 0x007254d0
void FUN_007254d0_t::FUN_007254d0()
{
    usItemCount = 0;
    fTotalHeight = 0.0f;
    FUN_004ee7d0_node* pnode;
    for (pnode = this; pnode && *((::ListBoxItem_t **)(&reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item)); pnode = ((::FUN_004ee7d0_node *)(pnode->pNext)))
    {
        if (!(*((::ListBoxItem_t **)(&reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item)))->m_bFiltered)
        {
            (*((::ListBoxItem_t **)(&reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item)))->pTile->Set(0xfac, usItemCount++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)((*((::ListBoxItem_t **)(&reinterpret_cast<::SimpleListNodeView*>(pnode)->m_item)))->pTile));
        }
    }
    reinterpret_cast<::S725970 *>(this)->FUN_00725970();
    UpdateSpeechChallengeTrait();
}

namespace fnv_00726530 {
class Tile
{
};
struct ListBoxBase_t
{
    virtual ~ListBoxBase_t();
};
struct BSSimpleList_t
{
    void* pItem;
    BSSimpleList_t* pNext;
};
struct FUN_00726530_t : public ListBoxBase_t, public BSSimpleList_t
{
    Tile* m_pListTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;
    void FUN_00726530();
};

// @fnv 0x00726530
void FUN_00726530_t::FUN_00726530()
{
    if (m_pListTile)
    {
        float flistHeight = reinterpret_cast<::TileListBoxCalls *>((m_pListTile))->GetFloat(0xfb0);
        int inumPages = 1;
        if (m_fFirstListValue > 0.0 && flistHeight > 0.0)
        {
            if (m_fFirstListValue > flistHeight)
                inumPages = ::FUN_00647b70(
                    (int)::FUN_004e4430(reinterpret_cast<::VATSMenu *>(this)->GetFilteredCount() * (m_fFirstListValue - flistHeight) / m_fFirstListValue) + 1,
                    2);
            if (inumPages > 1)
                reinterpret_cast<::FUN_00a012d0_t *>((m_pListTile))->FUN_00a012d0(::FUN_00a01860("_scroll_delta"), (m_fFirstListValue - flistHeight) / (inumPages - 1),
                                 true);
        }
        if (m_pHighlightedTile)
            reinterpret_cast<::Tile *>((m_pHighlightedTile))->Set(::FUN_00a01860("_number_of_items"), inumPages);
    }
}
}  // namespace fnv_00726530

namespace fnv_007b8d30 {
class Tile;
class NiNode;
template <class T> class NiPointer
{
  public:
    NiPointer(T* pObject = 0);
    ~NiPointer();
    T* m_pObject;
};
template <class T> class BSSimpleList
{
  public:
    BSSimpleList();
    T m_item;
    BSSimpleList<T>* m_pkNext;
};
struct Menu_007a8b10
{
    Menu_007a8b10();
    virtual ~Menu_007a8b10();
    Tile* pRootTile;
    void* pExtraHead;
    void* pExtraNext;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int uiMenuID;
    unsigned int uiVisibility;
};
struct FUN_007b9000
{
    FUN_007b9000();
    ~FUN_007b9000();
    Tile* m_pTiles[25];
};
struct PC7d
{
    char pad[0x630];
    void* unk630;
};
struct FUN_007b8d30_t : public Menu_007a8b10
{
    int iMode;
    Tile* m_pTiles[11];
    int m_iEntryCount;
    FUN_007b9000 kEntries[159];
    BSSimpleList<void*>* pList;
    Tile* pEntryTiles[61];
    int iSelected;
    Tile* pTile3F74;
    Tile* pTile3F78;
    NiPointer<NiNode> m_pController;
    Tile* pTiles3F80[4];
    float fScrollX;
    float fScrollY;
    Tile* pTiles3F98[15];
    float fPosX;
    float fPosY;
    float fPosZ;
    int iValue3FE0;
    int iValue3FE4;
    int iValue3FE8;
    int iValue3FEC;
    int iValue3FF0;
    int iValue3FF4;
    int iValue3FF8;
    int iValue3FFC;
    int iValue4000;
    int iValue4004;
    int iValue4008;
    bool bFlag400C;
    bool bFlag400D;
    void* pPlayerData;
    FUN_007b8d30_t();
    virtual ~FUN_007b8d30_t();
};
// @fnv 0x007b8d30
FUN_007b8d30_t::FUN_007b8d30_t()
{
    ::DAT_011da870 = ::FUN_00a00940("_Value", -1);
    ::DAT_011da86c = ::FUN_00a00940("_X", -1);
    pList = new BSSimpleList<void*>;
    iMode = 4;
    iSelected = 0;
    bFlag400D = false;
    m_iEntryCount = 0;
    fPosX = 0.0f;
    fPosY = 0.0f;
    fPosZ = 0.0f;
    iValue3FE0 = 0;
    iValue3FE4 = 0;
    iValue3FE8 = 0;
    iValue3FFC = 0;
    iValue3FEC = 0;
    iValue3FF0 = 0;
    iValue3FF4 = 0;
    iValue3FF8 = 0;
    fScrollX = 0.0f;
    fScrollY = 0.0f;
    pPlayerData = ((void *)((*reinterpret_cast<::fnv_007b8d30::PC7d * *>(&::_g_thePlayer))->unk630));
}
}  // namespace fnv_007b8d30

namespace fnv_0071e3b0 {

struct FUN_0071e3e0_shell
{
};

struct FUN_0071e3b0_shell : FUN_0071e3e0_shell
{
    void* FUN_0071e3b0(unsigned int flags);
};

// Calls FUN_0071e3e0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x0071e3b0
void* FUN_0071e3b0_shell::FUN_0071e3b0(unsigned int flags)
{
    reinterpret_cast<::FUN_0071e3e0_shell *>(this)->FUN_0071e3e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0071e3b0

struct FUN_0071f2d0_shell
{
    int FUN_0071f2d0();
};

// @fnv 0x0071f2d0
int FUN_0071f2d0_shell::FUN_0071f2d0()
{
    return 0x423;
}

struct FUN_00720330_shell
{
    void* FUN_00720330(unsigned int flags);
    void FUN_00720420();
};


// @fnv 0x00720330
void* FUN_00720330_shell::FUN_00720330(unsigned int flags)
{
    reinterpret_cast<::fnv_00720420::FUN_00720420 *>(this)->fnv_00720420::FUN_00720420::~FUN_00720420();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00720770_shell
{
    void* FUN_00720770(unsigned int flags);
    void* FUN_00720860();
};


// Calls FUN_00720860, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00720770
void* FUN_00720770_shell::FUN_00720770(unsigned int flags)
{
    reinterpret_cast<::fnv_00720860::FUN_00720860 *>(this)->fnv_00720860::FUN_00720860::~FUN_00720860();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

class Tile;
struct TutorialMenu
{
    char _0x28[0x28];
    Tile* m_pTiles[8];
    void SetTile(int aiID, Tile* apTile);
};

// @fnv 0x007209e0
void TutorialMenu::SetTile(int aiID, Tile* apTile)
{
    if (aiID >= 0 && aiID < 8)
        m_pTiles[aiID] = apTile;
}

struct QuantityMenu
{
    int FUN_00720a30();
};

// @fnv 0x00720a30
int QuantityMenu::FUN_00720a30()
{
    return 0x3f8;
}

class ActiveEffect;
class Actor;
struct ActorCause;
struct ActorMover;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
class BGSEncounterZone;
struct BGSExplosion;
struct ExplosionForm;
class BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
class BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
class BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
class BSExtraData;
class BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CellMopp;
struct CombatController;
struct CombatCoverMap;
struct ActorCombatGroup;
struct CombatTargetMap;
struct CombatThreatMap;
struct ContinuousBeamProjectile;
struct Crime;
struct GameFormRecord;
class DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
class EffectItem;
class ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryChanges;
class InventoryStackRecord;
struct CellDataNode;
class MagicCaster;
class MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
class MagicTarget;
class MapMarkerData;
class MobileObject;
class Point3Offset;
class NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
class NiControllerSequence;
class NiFixedString;
class NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
class NiNode;
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
class PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
class Projectile;
class QueuedFile;
struct ReferenceLightData;
class LockExtraData;
struct ReferenceIntersectionData;
class RagDollData;
class Script;
struct ScriptLocals;
struct SpellItem;
class TESActorBase;
struct TESAmmo;
class TESBoundObject;
struct TESClass;
struct TESCombatStyle;
class TESContainer;
struct TESFaction;
class TESFile;
class TESForm;
struct TESGlobal;
class TESIdleForm;
class TESModel;
class TESObject;
class TESObjectARMO;
class TESObjectBOOK;
class TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
class TESObjectREFR;
class TESObjectWEAP;
class TESPackage;
struct TESRace;
struct TESSkill;
class TESSound;
class TESTopic;
class TESTopicInfo;
class TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;
class bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct CombatManager
{
    void ResetFormData();
    void ClearData(bool);
    static void Create();
    static void Destroy();
    void Update(bool);
    void UpdateCombatGroups(bool);
    void UpdateCombatants();
    void ResetTargetMap();
    CombatController* AddCombatant(Actor*, Actor*, unsigned int, bool);
    CombatController* AddCombatantToGroup(Actor*, ActorCombatGroup*);
    CombatController* AddPretendCombatant(Actor*, TESPackage*);
    unsigned int GetCombatGroupTargetCount(Actor*, unsigned int*);
    bool CheckShouldFlee(Actor*, Actor*);
    void AssignCombatTarget(Actor*, Actor*);
    bool GetWanttoHelpGroup(Actor*, Actor*);
    bool CanActorJoinCombat(Actor*, Actor*);
    void AddCombatGroupTarget(ActorCombatGroup*, Actor*);
    void NotifyCombatGroupRemovedTarget(ActorCombatGroup*, Actor*);
    void AddCombatGroupMember(ActorCombatGroup*, Actor*);
    void NotifyCombatGroupRemovedMember(ActorCombatGroup*, Actor*);
    bool CanActorBeAffectedByExplosion(Actor*, BGSExplosion*, void*, float);
    void SetActivatePickReference(TESObjectREFR*);
    void DrawDebugText(IDebugText*);
    void DisplayCombatGroupDebugText(IDebugText*, TESObjectREFR*);
    void DisplaySpectatorDebugText(IDebugText*, TESObjectREFR*);
    bool IsCombatActive();
    void AddLocalActor(Actor*);
    void RemoveLocalActor(Actor*);
    void TargetLocalActor(Actor*, ActorCombatGroup*);
    void UntargetLocalActor(Actor*, ActorCombatGroup*);
    unsigned int FindCombatGroupForActor(struct blob12, float, float, Actor*, unsigned int*, unsigned int*,
                                         unsigned int*, unsigned int*);
    CombatThreatMap* GetThreatMap();
    CombatCoverMap* GetCoverMap();
    CombatTargetMap* GetTargetMap();
    void SaveGame(BGSSaveGameBuffer*);
    void LoadGame(BGSLoadGameBuffer*);
    void InitLoadGame(BGSLoadGameBuffer*);
    void ApplyLoadBuffer(BGSLoadGameBuffer*);
    void Revert(BGSLoadGameBuffer*);
    unsigned int GetCombatGroupCount();
    ActorCombatGroup* GetCombatGroupByIndex(unsigned int);
    ActorCombatGroup* GetCombatGroup(unsigned int);
    ActorCombatGroup* GetPlayerCombatGroup();
    ActorCombatGroup* SplitPlayerCombatGroup(Actor*);
    void* __vecDelDtor(unsigned int);
    char m_kCombatGroups[16];
    void* m_pActorCombatGroupMap;
    CombatThreatMap* m_pThreatMap;
    CombatCoverMap* m_pCoverMap;
    CombatTargetMap* m_pTargetMap;
    char m_kFourByteManagerData[4];
    char m_kFirstEightByteManagerData[8];
    char m_kSecondEightByteManagerData[8];
    unsigned int m_uiDebugFlags;
    char m_spDebugRootNode[4];
};
class BaseFormComponent
{
  public:
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
namespace ActorValue { enum Index; }
class ActorValueOwner
{
  public:
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
public:
    int GetActorValueAsInteger(::ActorValue::Index);
public:
    float GetActorValueFloatByIndex(::ActorValue::Index);
};
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
struct FUN_008d0300_shell : public CombatManager
{
    bool FUN_008d0300(Actor*, Actor*);
};

// @fnv 0x008d0300
bool FUN_008d0300_shell::FUN_008d0300(Actor* apAttacker, Actor* apTarget)
{
    return false;
}

struct S0071e3b0
{
};
// If DAT_011d8d54 is set, calls its FUN_0071e3b0(1) method and then clears DAT_011d8d54.
// @fnv 0x0071e360
void FUN_0071e360()
{
    if (DAT_011d8d54)
    {
        S0071e3b0* p1 = (S0071e3b0*)DAT_011d8d54;
        S0071e3b0* p2 = p1;
        void* r;
        if (p2)
            r = reinterpret_cast<::fnv_0071e3b0::FUN_0071e3b0_shell *>((p2))->FUN_0071e3b0(1);
        else
            r = 0;
        DAT_011d8d54 = 0;
    }
}

namespace fnv_0071f2e0 {
struct TutorialMenu
{
    void* DestroyTutorialMenu(unsigned int);
};
// Calls DestroyMenu, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0071f2e0
void* TutorialMenu::DestroyTutorialMenu(unsigned int flags)
{
    reinterpret_cast<::S *>(this)->DestroyMenu();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0071f2e0

struct S0071f670
{
    void* FUN_0071f670(unsigned int);
};
// Calls FUN_0071f570, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0071f670
void* S0071f670::FUN_0071f670(unsigned int flags)
{
    reinterpret_cast<::FUN_0071f570_ModelList *>(this)->FUN_0071f570_ModelList::~FUN_0071f570_ModelList();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct StatusEffectList
{
    void* FUN_0071f6a0(unsigned int);
};
// Calls FUN_0071f600, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0071f6a0
void* StatusEffectList::FUN_0071f6a0(unsigned int flags)
{
    reinterpret_cast<::FUN_0071f600 *>(this)->FUN_0071f600::~FUN_0071f600();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_0071fec0 {
struct FUN_0071fef0
{
    virtual ~FUN_0071fef0();
    void* FUN_0071fec0(unsigned int);
};
// Runs the destructor, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0071fec0
void* FUN_0071fef0::FUN_0071fec0(unsigned int flags)
{
    reinterpret_cast<::FUN_0071fef0 *>((this))->::FUN_0071fef0::~FUN_0071fef0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0071fec0

struct FUN_00720010_shell
{
    int FUN_00720010(int a);
};
// Returns a-1 when a is in 1..0x12, otherwise returns 0x12.
// @fnv 0x00720010
int FUN_00720010_shell::FUN_00720010(int aiValue)
{
    return (aiValue > 0 && aiValue <= 0x12) ? aiValue - 1 : 0x12;
}

struct Cls_720110
{
    void* FUN_00720110(unsigned int);
};
// Calls FUN_007e9130, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00720110
void* Cls_720110::FUN_00720110(unsigned int flags)
{
    reinterpret_cast<::FUN_007e9130_cls *>(this)->FUN_007e9130_cls::~FUN_007e9130_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

extern int _data_011c16bc;
struct FUN_00723f30_shell
{
    void FUN_00723f30();
};
struct FUN_00723f80
{
    ~FUN_00723f80();
};
struct FUN_007203c0 : FUN_00723f80
{
    char _pad[16];
    FUN_00723f30_shell fld10;
    ~FUN_007203c0();
};
// Destructor that calls FUN_00723f30 on the fld10 member.
// @fnv 0x007203c0
FUN_007203c0::~FUN_007203c0()
{
    fld10.FUN_00723f30();
}

extern int _data_011c16bc;
struct FUN_00724040
{
    char _d[16];
    FUN_00724040();
    ~FUN_00724040();
};
struct FUN_00723fa0
{
    FUN_00723fa0();
};
struct FUN_007207a0 : FUN_00724040
{
    FUN_00723fa0 m;
    FUN_007207a0();
};
// Empty constructor for a class that inherits FUN_00724040 and contains a FUN_00723fa0 member.
// @fnv 0x007207a0
FUN_007207a0::FUN_007207a0()
{}

struct FUN_00724070
{
    char _pad[16];
    ~FUN_00724070();
};
struct Helper_00723fd0
{
    void FUN_00723fd0();
};
struct FUN_00720800 : public FUN_00724070
{
    Helper_00723fd0 m;
    ~FUN_00720800();
};
// @fnv 0x00720800
FUN_00720800::~FUN_00720800()
{
    reinterpret_cast<::FUN_00723fd0_shell *>(&(m))->FUN_00723fd0();
}

namespace fnv_00720a40 {
struct QuantityMenu
{
    void FUN_00720a70();
    void* FUN_00720a40(unsigned int);
};
// @fnv 0x00720a40
void* QuantityMenu::FUN_00720a40(unsigned int flags)
{
    FUN_00720a70();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00720a40

namespace fnv_00720a70 {
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
struct FUN_00720a70_Host
{
    void FUN_00720a70();
};
// Sets the object's first field to the string "@\nr", clears DAT_011da618, then calls the Menu_007a8b10 destructor on this.
// @fnv 0x00720a70
void FUN_00720a70_Host::FUN_00720a70()
{
    *(const char**)this = "@\nr";
    DAT_011da618 = 0;
    reinterpret_cast<::fnv_00a1c520::FUN_00a1c520 *>((((Menu_007a8b10*)this)))->fnv_00a1c520::FUN_00a1c520::~FUN_00a1c520();
}
}  // namespace fnv_00720a70

namespace fnv_00720e00 {
class Tile
{
  public:
    virtual ~Tile();
};
struct FakeMgr
{
    bool DestroyMenuByClass(int aiMenuClass);
};
// Looks up a Tile for the given menu class, deletes it if found, and returns whether it existed.
// @fnv 0x00720e00
bool FakeMgr::DestroyMenuByClass(int aiMenuClass)
{
    Tile* pmenu = ((::fnv_00720e00::Tile *)(::FUN_00a09030(aiMenuClass)));
    if (pmenu)
    {
        delete pmenu;
        return true;
    }
    return false;
}
}  // namespace fnv_00720e00

class Tile;
struct S0071
{
    unsigned char _pad[0x2c];
    Tile* m_pTiles[18];
    void FUN_0071ffe0(int, Tile*);
};
// Stores apTile in the slot returned by FUN_00720010(aiID) when aiID is in 1..0x12.
// @fnv 0x0071ffe0
void S0071::FUN_0071ffe0(int aiID, Tile* apTile)
{
    if (aiID > 0 && aiID <= 0x12)
    {
        m_pTiles[reinterpret_cast<::FUN_00720010_shell *>(this)->FUN_00720010(aiID)] = apTile;
    }
}

class Tile;
struct FUN_00720140_Holder
{
    char _pad[0x28];
    Tile* m_pTiles[32];
    void FUN_00720140(int aiID, Tile* apTile);
};
// Stores apTile into the holder's tile slot indexed by aiID when aiID is between 1 and 0x1F.
// @fnv 0x00720140
void FUN_00720140_Holder::FUN_00720140(int aiID, Tile* apTile)
{
    if (aiID > 0 && aiID <= 0x1F)
    {
        m_pTiles[aiID] = apTile;
    }
}

struct FUN_00723f50
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    FUN_00723f50();
    ~FUN_00723f50();
};

struct FUN_00723f00
{
    int unk00;

    FUN_00723f00();
    ~FUN_00723f00();
};

struct FUN_00720360 : public FUN_00723f50
{
    FUN_00723f00 unk10;

    FUN_00720360();
    ~FUN_00720360();
};

// Initializes a FUN_00720360 object, constructing its FUN_00723f50 base and FUN_00723f00 member.
// @fnv 0x00720360
FUN_00720360::FUN_00720360()
{}

extern int DAT_010701c4;

struct MenuBaseCtorCaller
{
};

// @fnv 0x00720a10
FUN_00720a10::FUN_00720a10()
{
    new ((void *)(reinterpret_cast<MenuBaseCtorCaller*>(this))) ::Menu();
    *(void**)this = (void*)&DAT_010701c4;
}

struct FUN_007df140_Sub
{
    int unk00;
    int unk04;
    int unk08;

    FUN_007df140_Sub();
    ~FUN_007df140_Sub();
};

struct FUN_007df140_Tail
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    FUN_007df140_Tail();
};

struct FUN_007df140_cls
{
    int m_00;
    FUN_007df140_Sub m_04;
    FUN_007df140_Tail m_10;

    FUN_007df140_cls(int aValue);
};

// Initializes the object's first field with the given value.
// @fnv 0x007df140
FUN_007df140_cls::FUN_007df140_cls(int aValue)
{
    m_00 = aValue;
}

struct FUN_00a1c4a0
{
    FUN_00a1c4a0();
    ~FUN_00a1c4a0();
    virtual void v00();
    int unkCur;
    int unkValue;
    int unk0C;
    int uNewnk;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct FUN_00723750
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0C;
    int uNewnk;
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

    FUN_00723750();
    ~FUN_00723750();
};

struct FUN_009ca4a0
{
    int unk;

    FUN_009ca4a0();
    ~FUN_009ca4a0();
};

class Tile;

struct FUN_00720040 : public FUN_00a1c4a0
{
    Tile* m_pTiles[32];
    int unkA;
    int unkAC;
    FUN_00723750 unkB;
    bool unkF;
    int unkFC;
    int uTmpnk;
    bool unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    FUN_009ca4a0 unk11C;

    FUN_00720040();
};

// @fnv 0x00720040
FUN_00720040::FUN_00720040()
{
    FUN_00403d30(m_pTiles, 0, sizeof(m_pTiles));
    unkF = false;
    unk104 = false;
    unk108 = 0;
}

namespace fnv_00720550 {
namespace Reconstructed {
class Menu
{
  public:
    Menu();
    virtual ~Menu();
    unsigned int rootTile, extraHead, extraNext, state10, state14, state18, state1C, menuID, visibility;
};
struct MenuList
{
    unsigned int head, tail, count, capacity;
    MenuList();
    ~MenuList();
};
struct MenuSelection
{
    unsigned int head, tail, count, selected;
    MenuSelection();
    ~MenuSelection();
};
struct MenuEntry
{
    unsigned int tile, object, flags, value, minimum, maximum, step, selected;
    MenuEntry();
    ~MenuEntry();
};
template <class T> class NiPointer
{
  public:
    T* object;
    NiPointer();
    ~NiPointer();
};
struct SceneNode;
struct FUN_00720550 : Menu
{
    unsigned int tiles[8];
    unsigned int selectedTile;
    unsigned int mode;
    float elapsed;
    bool active;
    unsigned int currentIndex;
    unsigned int currentObject;
    unsigned int currentTile;
    MenuList list;
    MenuSelection selection;
    MenuEntry entries[9];
    MenuEntry currentEntry;
    NiPointer<SceneNode> nodes[11];
    NiPointer<SceneNode> effects[4];
    NiPointer<SceneNode> pair200[2];
    NiPointer<SceneNode> pair208[2];
    NiPointer<SceneNode> pair210[2];
    NiPointer<SceneNode> pair218[2];
    NiPointer<SceneNode> pair220[2];
    NiPointer<SceneNode> pair228[2];
    FUN_00720550();
    virtual ~FUN_00720550();
};
// Initializes the menu: clears the tiles array, zeroes the current object/tile/index and selected tile, sets mode to 1, elapsed to 0.0 and active to true.
// @fnv 0x00720550
FUN_00720550::FUN_00720550()
{
    ::FUN_00403d30(tiles, 0, sizeof(tiles));
    currentObject = 0;
    currentTile = 0;
    selectedTile = 0;
    mode = 1;
    elapsed = 0.0f;
    active = true;
    currentIndex = 0;
}
}
}  // namespace fnv_00720550

struct FUN_00720f90_shell
{
    bool FUN_00720f90(int param_1);
};

struct NiPtrStub
{
    void* pObject;
};

struct ListStandIn
{
    int* FUN_0057cbe0(int** cursor);
};

struct VtMenu
{
    virtual void vt00();
    virtual void vt01();
    virtual void vt02();
    virtual void vt03();
    virtual void vt04();
    virtual void vt05();
    virtual void vt06();
    virtual void vt07();
    virtual void vt08();
    virtual void vt09();
    virtual void vt10();
    virtual void vt11();
    virtual void vt12();
    virtual int vt13();
};

struct TileStub
{
};

struct GetKindStub
{
};

struct FUN_00a01230_shell
{
    bool IsTraitNonZero(int);
};

struct InterfaceManager_helper
{
};


// @fnv 0x00720f90
bool FUN_00720f90_shell::FUN_00720f90(int param_1)
{
    int* cursor = (int*)((void *)(::FUN_00559450((int *)(((NiPtrStub*)((char*)((void *)(reinterpret_cast<::InterfaceManager *>((((InterfaceManager_helper*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00586150())) + 4))))));
    while (cursor)
    {
        intptr_t item = *((ListStandIn*)((char*)((void *)(reinterpret_cast<::InterfaceManager *>((((InterfaceManager_helper*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00586150())) + 4))
                        ->FUN_0057cbe0(&cursor);
        VtMenu* menu = 0;
        if (item)
            menu = ((::VtMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((((TileStub*)item)))->FUN_00a03c90()));
        if (menu)
        {
            if (((::FUN_004ee7d0_node *)(((FUN_004ee7d0_node*)menu)->pNext)))
            {
                if (menu->vt13() == param_1)
                {
                    if (((FUN_00a01230_shell*)((::FUN_004ee7d0_node *)(((FUN_004ee7d0_node*)menu)->pNext)))->IsTraitNonZero(0xfa3) &&
                        ((int)(reinterpret_cast<::ActorMover *>((((GetKindStub*)menu)))->GetCurrentMoveModeType())) != 2)
                        return true;
                    else
                        return false;
                }
            }
        }
    }
    return false;
}

extern MenuSystem* DAT_011d8d54;
class ActorCombatGroup;
template <class T> class NiTMallocInterface;

// 0x00720aa0  838 bytes  /MT /Od /Oy- /GS /EHsc /Gy /GF
// thiscall (ret 4), one int arg: fetch the cached menu for that class, delete
// it, then build the class's menu through an if/else-if chain over the ids.


class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};

class TESObjectBOOK : public TESBoundObject
{
};

int FUN_00720df0();

struct Mgr20
{
    void* FUN_00720aa0(int menuClass);
};

// @fnv 0x00720aa0
void* Mgr20::FUN_00720aa0(int menuClass)
{
    Tile* pMenu = ((::Tile *)(::FUN_00a09030(menuClass)));
    bool bFlag = ((bool)(::IsStartMenuFlag1Set()));
    if (pMenu)
    {
        delete pMenu;
    }
    pMenu = 0;

    if (FUN_00720df0() == menuClass)
    {
        pMenu = ((::Tile *)(::fnv_00704140::FUN_00704140()));
        ::fnv_007164c0::FUN_007164c0((intptr_t)(((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))), reinterpret_cast<::TileListBoxCalls *>((pMenu))->GetFloat(0xfc1));
        reinterpret_cast<::TESRecipe *>((((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))))->SetRequiredSkill((::ActorValue::Index)(8));
    }
    else if (menuClass == 0x40b)
    {
        pMenu = ((::Tile *)(::fnv_00704490::FUN_00704490()));
        ::fnv_007164c0::FUN_007164c0((intptr_t)(((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))), reinterpret_cast<::TileListBoxCalls *>((pMenu))->GetFloat(0xfc1));
        reinterpret_cast<::TESRecipe *>((((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))))->SetRequiredSkill((::ActorValue::Index)(8));
    }
    else if (menuClass == 0x425)
    {
        pMenu = ((::Tile *)(::fnv_007046c0::FUN_007046c0()));
        ::fnv_007164c0::FUN_007164c0((intptr_t)(((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))), reinterpret_cast<::TileListBoxCalls *>((pMenu))->GetFloat(0xfc1));
        reinterpret_cast<::TESRecipe *>((((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))))->SetRequiredSkill((::ActorValue::Index)(8));
    }
    else if (menuClass == 0x3ea)
    {
        pMenu = ::fnv_007048c0::CreateInventoryMenuIfModifierKey();
        ::fnv_007164c0::FUN_007164c0((intptr_t)(((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))), reinterpret_cast<::TileListBoxCalls *>((pMenu))->GetFloat(0xfc1));
        reinterpret_cast<::TESRecipe *>((((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))))->SetRequiredSkill((::ActorValue::Index)(8));
    }
    else if (menuClass == 0x3eb)
    {
        pMenu = ((::Tile *)(::fnv_00704be0::FUN_00704be0()));
        ::fnv_007164c0::FUN_007164c0((intptr_t)(((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))), reinterpret_cast<::TileListBoxCalls *>((pMenu))->GetFloat(0xfc1));
        reinterpret_cast<::TESRecipe *>((((::Tile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenu))->FUN_00a03c90()))))->SetRequiredSkill((::ActorValue::Index)(8));
    }
    else if (menuClass == 0x3ec)
    {
        pMenu = FUN_0076bfe0();
    }
    else if (FUN_0070ede0() == menuClass && ::InitStartMenu(bFlag, false))
    {
        pMenu = ((::Tile *)(::FUN_00a09030(menuClass)));
    }
    else if (menuClass == 0x3ef)
    {
        pMenu = ::CreateLoadingMenuTile((::TESForm *)(void *)(0), true, false);
    }
    else if (menuClass == 0x403)
    {
        pMenu = ((::Tile *)(::fnv_00784c80::FUN_00784c80()));
    }
    else if (menuClass == 0x3f0)
    {
        ContainerMenu* pContainer = dynamic_cast<ContainerMenu*>(((::Tile *)(::FUN_00a09030(0x3f0))));
        if (pContainer)
        {
            pMenu = ((::Tile *)(::FUN_0075b310((::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::FUN_004fd3a0_shell *>((((Tile*)pContainer)))->FUN_004fd3a0()))), 1)));
        }
    }
    else if (menuClass == 0x402)
    {
        BookMenu* pBookMenu = dynamic_cast<BookMenu*>(((::Tile *)(::FUN_00a09030(0x3f0))));
        if (pBookMenu)
        {
            char* data = reinterpret_cast<::Script *>((((Tile*)pBookMenu)))->GetData();
            TESObjectBOOK* pBookForm = dynamic_cast<TESObjectBOOK*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESBoundObject*)data)))->FUN_007af430())));
            delete (Tile*)pBookMenu;
            pMenu = ::FUN_0073ad50((::TESObjectBOOK *)(pBookForm), (::TESObjectREFR *)(data));
        }
    }

    return pMenu;
}
#include "generated/data/fallout/interface/menumanager.inc"
