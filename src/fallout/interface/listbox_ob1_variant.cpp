
// src/fallout/interface/listbox_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout/interface/listbox.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/interface/listbox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/listbox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/BSS.h"
#include "fnv/decl/C7D8EE0List.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_004bc810_cls.h"
#include "fnv/decl/FUN_004bd820_stand.h"
#include "fnv/decl/FUN_00575510_shell.h"
#include "fnv/decl/FUN_0071aa60_class.h"
#include "fnv/decl/FUN_00725aa0_cls.h"
#include "fnv/decl/FUN_00725f40_shell.h"
#include "fnv/decl/FUN_00726090_cls.h"
#include "fnv/decl/FUN_007a1d60_cls.h"
#include "fnv/decl/FUN_007a37b0.h"
#include "fnv/decl/FUN_007a51c0_cls.h"
#include "fnv/decl/FUN_007a7700_Menu.h"
#include "fnv/decl/FUN_007a80e0_cls.h"
#include "fnv/decl/FUN_007d9e80_Class.h"
#include "fnv/decl/FUN_00a00e90_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FilteredList.h"
#include "fnv/decl/FlagS.h"
#include "fnv/decl/FocusManager.h"
#include "fnv/decl/FontManager.h"
#include "fnv/decl/Host_004d4b00.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/ListBox_71a.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/P03Value.h"
#include "fnv/decl/StatsMenu.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/W004702f0.h"
#include "fnv/decl/fnv_00723890__FUN_00723890_this.h"
#include "fnv/decl/fnv_00724020__GlobalObject_00869f00.h"
#include "fnv/decl/fnv_00724800__ListBoxScroll.h"
#include "fnv/decl/fnv_00725080__HighlightList.h"
#include "fnv/decl/fnv_00726210__ListBox726210.h"
#include "fnv/decl/fnv_007a6480__FUN_007a6480_cls.h"
#include "fnv/decl/fnv_007a6fa0__ListOwner.h"
#include "fnv/decl/fnv_007a73e0__HighlightList.h"
#include "fnv/decl/fnv_007d81f0__ClearList.h"
#include "fnv/decl/fnv_007d9660__SelectionList.h"
#include "fnv/decl/fnv_007d9ee0__ListBox_Option.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00a01000__FUN_00a01000_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a09200__Value_00a09200.h"
#include "fnv/decl/fnv_00a09410__EvalValue.h"
#include "fnv/decl/fnv_00a1b020__FUN_00a1b020_t.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/decl/list71a__L71Menu.h"
#include "fnv/decl/p07__FUN_007d6f80.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006b3000.h"
#include "fnv/symbols_00721000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_007d8000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a0a000.h"
#include "fnv/symbols_0106f000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011f6000.h"
struct G2
{
    void AddHead(int**);
};
struct GlobalObject_00869f00
{
};
extern int DAT_010703b4;
struct FUN_00723f30_shell : GlobalObject_00869f00
{
    void FUN_00723f30();
};
struct AX
{
};
struct FUN_00723f50_shell : AX
{
    int* vtable;
    AX* FUN_00723f50();
};
struct FUN_00724140_shell
{
    void __thiscall FUN_00722880();
    void* __thiscall Destroy(unsigned int flags);
};
struct FUN_007a51c0_shell
{
};
struct FUN_007a61f0_shell
{
    void* FUN_007a61f0(unsigned int flags);
};
struct FUN_007a62e0_shell
{
    int a;
    int b;
    char c;
    FUN_007a62e0_shell* __thiscall FUN_007a62e0(int param2, int* param3);
};
struct RecursiveLock;
struct Menu;
struct NiAVObject;
struct NiNode;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;
struct BGSSaveLoadFileEntry;
struct ListBox
{
    bool FUN_007d8d80(Tile* apSelectItem);
};
struct FUN_007d8e80_shell
{
    void* FUN_007d8e80(unsigned int flags);
};
struct FUN_007d8eb0_shell
{
    void __thiscall FUN_007d7d30();
    void* __thiscall FUN_007d8eb0(unsigned int flags);
};
struct BSSimpleList
{
};
struct FUN_00721410_class
{
    BSSimpleList list;
    void __thiscall FUN_00721410(void* param);
};
extern "C" char str_010703dc[];
struct FUN_00723fa0_shell : AX
{
    int* vtable;
    FUN_00723fa0_shell* __thiscall FUN_00723fa0();
};
struct FUN_00723ff0_shell : AX
{
    int* vtable;
    FUN_00723ff0_shell* Constructor();
};
struct FUN_00724070_shell : GlobalObject_00869f00
{
    void FUN_00724070();
};
struct FUN_007241d0_shell : FUN_00723f30_shell
{
    void* __thiscall FUN_007241d0(unsigned int flags);
};
struct FUN_00724290_shell
{
    void* __thiscall FUN_00724290(unsigned int flags);
};
struct FUN_007242c0_shell
{
    bool __thiscall FUN_007242c0(unsigned int flags);
};
struct VATSMenu
{
public:
    int FUN_007267c0();
};
struct TGF
{
};
extern int DAT_011d8cd8;
extern int DAT_011d8cdc;
struct FUN_0071ae60_shell : VATSMenu
{
    TGF* tile;
    unsigned int __thiscall FUN_0071ae60();
};
void __cdecl FUN_00724930();
struct FUN_00721bc0_shell
{
    int x;
    void __thiscall FUN_00721bc0(int(__cdecl* param)(void*, void*));
    void __thiscall FUN_00724930();
};
struct Tile
{
public:
    void Set(int, int);
public:
    void Set(int, unsigned int);
public:
    bool GetSpeechChallengeFailure();
};
struct FUN_00723030_Holder
{
    int _p0;
    int _p1;
    int _p2;
    Tile* _t;
    bool IsTileMenu(Menu* p);
};
struct FUN_00725aa0_shell
{
};
struct FUN_00723310_shell
{
    BSSimpleList list;
    void __thiscall FUN_00723310(int(__cdecl* cmp)(void*, void*));
};
struct FUN_00723ac0_shell
{
    void __thiscall FUN_00723ac0(void* param);
};
struct FUN_00723f00_shell : AX
{
    int* vtable;
    FUN_00723f00_shell* __thiscall FUN_00723f00();
};
struct FUN_00723fd0_shell : GlobalObject_00869f00
{
    void __thiscall FUN_00723fd0();
};
struct FUN_00724090_shell
{
    void* __thiscall FUN_00724090(unsigned int flags);
};
struct FUN_00721920_shell
{
    void __thiscall FUN_00721920();
};
struct FUN_007240e0_shell
{
    void* __thiscall FUN_007240e0(unsigned int flags);
};
struct FUN_00724110_This
{
    void* __thiscall FUN_00724110(unsigned int flags);
};
struct S_00724170
{
    void __thiscall FUN_00723070();
    void* __thiscall FUN_00724170(unsigned int flags);
};
struct FUN_007241a0_shell
{
    void* __thiscall FUN_007241a0(unsigned int flags);
};
struct Helper_00723fd0
{
};
struct FUN_00724230_shell
{
    void* __thiscall FUN_00724230(unsigned int flags);
};
struct FUN_00724260_shell
{
    void* __thiscall FUN_00724260(unsigned int flags);
};
struct Member_007a8b10
{
    ~Member_007a8b10();
};
struct FUN_007643c0_p07 : Member_007a8b10
{
    Member_007a8b10* __thiscall DestroySelf(unsigned int flags);
};
struct BSSimpleList;
struct FUN_007a6480_shell
{
};
struct FUN_007a22a0_shell
{
    void __thiscall FUN_007a22a0(int(__cdecl* cmp)(void*, void*));
};
struct FUN_007a30a0_Holder
{
    int __thiscall FUN_007a30a0(int, unsigned char);
};
struct FUN_007a80e0_shell
{
};
struct FUN_007a5700_shell
{
    int* __thiscall FUN_007a5700(int(__cdecl* cmp)(void*, void*));
};
struct FUN_007a1aa0_shell
{
    void FUN_007a1aa0();
};
struct FUN_007a6100_shell : FUN_007a1aa0_shell
{
    void* __thiscall FUN_007a6100(unsigned int flags);
};
struct FUN_007a6130_This
{
    void* __thiscall FUN_007a6130(unsigned int flags);
};
struct FUN_007a6190Owner
{
    void* __thiscall FUN_007a6190(unsigned int flags);
};
struct FUN_007a86b0_Item
{
    int a;
    int b;
};
struct FUN_007a63b0_holder
{
    void __thiscall FUN_007a63b0(FUN_007a86b0_Item*, unsigned int);
};
struct FUN_007a63f0_shell
{
    void __thiscall FUN_007a63f0(unsigned int requested, unsigned int savedSize);
};
struct FUN_007d9000_shell
{
};
struct FUN_007d7a80_shell
{
    void __thiscall FUN_007d7a80(int a);
};
void __cdecl UpdateSaveLoadList();
struct FUN_007d8420_shell
{
    BSSimpleList list;
    void __thiscall SortList(int(__cdecl* cmp)(void*, void*));
    void __thiscall UpdateSaveLoadList();
};
struct FUN_007a6fa0_shell
{
};
struct FUN_007d86c0_shell
{
    int* __thiscall FUN_007d86c0(int* apItem, unsigned char apSelect);
};
struct NavMeshSearchLOSArray
{
    int _00;
    void* data;
    int size;
    int capacity;
    void FUN_007d8e20(bool);
};
struct Tile_Set_Helper
{
};
struct TileF
{
};
struct ListBoxBase
{
    virtual ~ListBoxBase();
};
struct ListBox_71ad30 : ListBoxBase
{
    void* pListItem;
    void* pListNext;
    Tile* m_pListTile;
    Tile* pSelected;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;
    void UpdateScrollPages();
};
struct TileSet
{
};
struct FUN_007d8810_shell
{
    void* m0;
    void* m4;
    void* m8;
    TileSet* mC;
    void __thiscall FUN_007d8810(bool abVal);
};
extern int DAT_011d95ac;
extern int DAT_011d95b0;
struct FUN_00765340_shell : VATSMenu
{
    int pad[3];
    TGF* tile;
    unsigned int __thiscall GetUnfilteredCount();
};
extern int DAT_011dac94;
extern int DAT_011dac98;
struct FUN_007d8700_shell : VATSMenu
{
    int pad0;
    int pad1;
    int pad2;
    TGF* tile;
    unsigned int GetFilteredItemCount();
};
struct FUN_007240c0
{
    int* vptr;
    FUN_007240c0();
};
struct SL
{
    int a;
    int b;
    SL();
    ~SL();
};
struct ListBox_SetSelectedTile_shell
{
};
extern int DAT_01070220;
extern unsigned int _data_011c16bc;
struct FUN_00721060 : FUN_007240c0
{
    SL sl;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;

    FUN_00721060();
};
struct TileValue;
struct Tile_GetValue_helper
{
};
struct Tile_GetChildByName_helper
{
};
struct Tile_FUN_0071aa60_helper
{
};
struct Tile_GetSpeechChallengeFailure_helper
{
};
struct Tile_Set_helper
{
};
struct TAN
{
};
struct FUN_00a09130_shell
{
};
struct FUN_00a09410_shell
{
};
struct FUN_00725c20_shell
{
    char padding_000[0x0c];
    Tile* highlightTile;
    Tile* selectedTile;

    void __thiscall UpdateHighlightTiles();
};
struct Tile_IsTrue_helper
{
};
struct FUN_007a6bd0_shell
{
    char _base[0x0c];
    Tile* m_pListTile;
    bool __thiscall FUN_007a6bd0();
};
struct FUN_007a79b0_shell
{
    char _pad[12];
    Tile* m_pListTile;
    bool __thiscall FUN_007a79b0();
};
struct Tile_IsTrue_shell : Tile
{
};
struct EntryProperty
{
};
struct Entry
{
    int id;
    EntryProperty* property;
};
struct ListNode
{
    Entry* item;
    ListNode* next;
};
struct TemporaryList : ListNode
{
    TemporaryList();
    ~TemporaryList();
    void FUN_005ae3d0(Entry** item);
};
struct FunctionOwner
{
    int unk00;
    ListNode entries;
    void FUN_0071a200(int entryType);
};
struct SubObject_00721150
{
    ~SubObject_00721150();
};
struct FUN_00721150_cls
{
    virtual ~FUN_00721150_cls();
    SubObject_00721150 m_04;

};
struct SelectedObject
{
};
struct FUN_00721440_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SelectedObject* selected;

    bool __thiscall SelectObject(SelectedObject* object);
};
extern int DAT_010702ec;
struct FUN_00721850_shell
{
};
struct FUN_00721850_cls : FUN_007240c0
{
    SL sl;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;

    FUN_00721850_cls();
};
struct CleanupMember_00721920
{
    ~CleanupMember_00721920();
};
struct FUN_00721920
{
    virtual ~FUN_00721920();
    CleanupMember_00721920 cleanup;
};
struct SubObj_007220d0
{
    int unk00;
    ~SubObj_007220d0();
};
class FUN_007220d0_cls
{
  public:
    SubObj_007220d0 m_sub04;

    virtual ~FUN_007220d0_cls();
};
struct LBTileObj
{
    virtual ~LBTileObj();
};
struct LBExtraObj
{
    ~LBExtraObj();
};
struct LBItem
{
    LBTileObj* tile;
    LBExtraObj* extra;
};
struct LBNode
{
    ~LBNode();
};
struct LBTile
{
};
struct LBListBox
{
    void* vtbl;
    LBItem* pItem;
    LBNode* pNext;
    LBTile* m_pListTile;
    int unk10;
    void FUN_00722140();
    int unk14;
    int unk18;
    unsigned short usItemCount;
    float m_fFirstListValue;
};
struct Tile_7223a0
{
};
struct ListBox_7223a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Tile_7223a0* m_pSelected;
    bool FUN_007223a0(Tile_7223a0* apTile);
};
// FUN_007227b0: constructor of a object with a base (vptr), a member sub-object
// with its own ctor/dtor (state -1..0 EH frame), a few int/word/float fields and
// a post-init call on this followed by a cdecl call with this.
struct FUN_007227b0_sub
{
    int unk00;
    int unk04;
    FUN_007227b0_sub();
    ~FUN_007227b0_sub();
};
struct FUN_007227b0_target
{
};
struct FUN_007227b0_cls : FUN_007240c0
{
    FUN_007227b0_sub sub;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short w1c;
    float f20;
    float f24;
    float f28;
    unsigned short w2c;

    FUN_007227b0_cls();
};
struct Member_00722880
{
    ~Member_00722880();
};
Member_00722880::~Member_00722880()
{}
struct Helper_007228f0
{
    void __thiscall Call();
};
void Helper_007228f0::Call()
{}
struct FUN_00722880
{
    virtual ~FUN_00722880();
    Member_00722880 member4;
};
struct FUN_0046ffb0
{
    ~FUN_0046ffb0();
};
struct FUN_00723070
{
    virtual ~FUN_00723070();
    FUN_0046ffb0 cleanupMember;
};
extern char DAT_0107038c;
struct FUN_00723750 : FUN_007240c0, SL
{
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    short m_1c;
    float m_20;
    float m_24;
    float m_28;
    short m_2c;

    FUN_00723750();
};
class Member_00723820
{
  public:
    ~Member_00723820();
};
class FUN_00723820_cls
{
  public:
    virtual ~FUN_00723820_cls();
    Member_00723820 m_04;
};
class B23AF0Tile
{
  public:
};
class B23AF0ListBox
{
  public:
    bool FUN_00723af0(B23AF0Tile* pkTile);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    B23AF0Tile* m_pkSelected;
};
struct ListItem
{
    int key;
};
struct ListLink
{
    ListItem* item;
    ListLink* next;
};
struct ListOwner
{
    int unknown00;
    ListLink head;
    bool ContainsKey(int key);
};
struct FUN_00724360_Item
{
};
struct FUN_00724360_Obj
{
};
struct FUN_00724360_cls
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
    void FUN_00724360();
};
struct Item_00724430
{
};
struct Owner_00724430
{
    int unk00;
    int unk04;
    int unk08;
    Item_00724430* item;
    bool __thiscall FUN_00724430();
};
struct Obj00724930
{
};
struct Item00724930
{
    Obj00724930* unk00;
    int unk04;
    unsigned char flag08;
};
struct Node00724930
{
};
struct FUN_00724930_cls
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

    void __thiscall UpdateTraitDisplay();
    void FUN_00724930();
};
struct TileFloatGet
{
};
struct TileFloatSet
{
};
struct TileI
{
};
struct VATSMenuView
{
    int unk00;
    int unk04;
    int unk08;
    TileFloatGet* pScrollTile;
    int unk10;
    TileI* pCountTile;
    int unk18;
    int unk1C;
    float fTotal;
    unsigned int FUN_00726710();
    void FUN_00724dd0();
};
struct TileProxy
{
};
struct OwnerProxy
{
    int unk00, unk04, unk08;
    TileProxy* tile0c;
    int unk10;
    TileProxy* tile14;
    int unk18, unk1c;
    float range;
    void FUN_007253a0();
};
struct FUN_00a01230_cls
{
};
struct FUN_007255a0_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a01230_cls* m_0c;
    unsigned char FUN_007255a0();
};
struct TileA
{
};
struct S725970
{
    int unk00;
    int unk04;
    int unk08;
    TileA* tileA;
    int unk10;
    TileA* tileB;
    int unk18;
    int unk1C;
    float fVal;
    void FUN_00725970();
};
class B726160Tile
{
  public:
};
class B726160Menu
{
  public:
    int unk00;
    int unk04;
    int unk08;
    B726160Tile* m_pkTile;
    bool FUN_00726160();
};
struct Parent
{
    void* vptr;
    Parent();
};
struct Section
{
    unsigned int count;
    unsigned int capacity;
    Section();
    ~Section();
};
struct FUN_00730810 : Parent
{
    Section section;
    void* container;
    void* selected;
    void* scrollbar;
    const char* templateName;
    unsigned short nextIndex;
    float totalHeight;
    float lastSelection;
    float lastScrollbar;
    unsigned short flags;
    FUN_00730810();
};
extern void* DAT_01070890;
struct FUN_00730e20_inner
{
};
struct FUN_00730e20_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00730e20_inner* m_0c;
    bool FUN_00730e20();
};
struct Tile_764e40
{
};
struct Cls_764e40
{
    int unk00;
    int unk04;
    int unk08;
    Tile_764e40* m_pTile0c;
    bool FUN_00764e40();
};
struct Item
{
    int* data;
    int key;
};
struct Node
{
};
struct Owner
{
    int unk00;
    Node head;
    int* __thiscall FindItemData(int* key);
};
struct FUN_007a23e0_arg
{
    int unk00;
};
struct FUN_007a23e0_cls
{
    int unk00[4];
    FUN_007a23e0_arg* m_10;
    bool FUN_007a23e0(FUN_007a23e0_arg* arg);
};
class B7A27F0Tile;
class B7A27F0Base
{
  public:
    B7A27F0Base();
    virtual void VFunc00();
};
class B7A27F0List
{
  public:
    B7A27F0List();
    ~B7A27F0List();

    void* m_pvItem;
    B7A27F0List* m_pkNext;
};
class FUN_007a27f0_cls : public B7A27F0Base, public B7A27F0List
{
  public:
    FUN_007a27f0_cls();
    virtual void VFunc00();


    void* m_pkParentTile;
    void* m_pkScrollBar;
    void* m_pkSelected;
    void* m_pkTemplate;
    short m_sItemCount;
    short unk1E;
    float m_fScrollPos;
    float m_fScrollMax;
    float m_fItemHeight;
    short m_sFlags;
};
extern int DAT_01075594;
struct FUN_007a36e0_m4
{
    int m_00;
    FUN_007a36e0_m4();
    ~FUN_007a36e0_m4();
};
struct FUN_007a36e0_cls : FUN_007240c0
{
    FUN_007a36e0_m4 m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    unsigned short m_1c;
    float m_20;
    float m_24;
    float m_28;
    unsigned short m_2c;


    FUN_007a36e0_cls();
};
struct FUN_007a6310_Elem8
{
    int a;
    int b;
    FUN_007a6310_Elem8();
};
void* __cdecl operator new(unsigned int size, void* where);
void __cdecl operator delete(void* p, void* where);
struct FUN_007a6310_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void __thiscall ConstructElements(int arr, unsigned int count);
};
struct FUN_00a01230_shell
{
    bool __thiscall IsTraitNonZero(int);
};
struct FUN_007a6550_shell
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a01230_shell* target;

    bool __thiscall FUN_007a6550();
};
struct FUN_00a01230_Target
{
};
struct FUN_007a7330_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a01230_Target* m_0c;

    unsigned char FUN_007a7330();
};
struct FUN_007a81b0_target
{
};
struct FUN_007a81b0_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_007a81b0_target* m_0c;
    bool FUN_007a81b0();
};
extern int DAT_01077094;
struct FUN_007240c0_Base
{
    const void* vtbl00;
    FUN_007240c0_Base();
};
struct FUN_0096a2d0_List
{
    int unk00;
    int unk04;
    FUN_0096a2d0_List();
    ~FUN_0096a2d0_List()
    {}
};
struct FUN_007d7c60 : FUN_007240c0_Base
{
    FUN_0096a2d0_List list04;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    short unk1C;
    float unk20;
    float unk24;
    float unk28;
    short unk2C;
    FUN_007d7c60();
};
struct Member_0046ffb0
{
    ~Member_0046ffb0();
};
Member_0046ffb0::~Member_0046ffb0()
{}
struct FUN_007d7d30
{
    Member_0046ffb0 m;
    virtual ~FUN_007d7d30();
};
struct FUN_007d8da0_cls
{
    void FUN_007d8da0(bool bFlag);
};
struct SelectionTile
{
};
struct SelectionList
{
    bool ApplySelectionAction(SelectionTile* item, int action);
};
struct TileHeight
{
};
struct HeightList
{
    int unk00;
    int unk04;
    int unk08;
    TileHeight* container;
    int unk10;
    Tile_Set_Helper* scrollbar;
    int unk18;
    int unk1c;
    float totalHeight;
    void __thiscall FUN_007d9460();
};
struct TileX
{
};
struct ListBoxScrollBase
{
    virtual ~ListBoxScrollBase();
};
struct ListBoxScroll : ListBoxScrollBase
{
    void* pListItem;
    void* pListNext;
    TileX* m_pListTile;
    TileX* pSelected;
    TileX* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;

    void FUN_007d9d50();
};
struct OwnedRecord
{
    ~OwnedRecord();
};
struct OwnedRecordList
{
    ~OwnedRecordList();
};
struct RecordList
{
    OwnedRecordList* head;
    unsigned int count;
    void FUN_00851540();
};
int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl strcat_s(char*, unsigned int, const char*);
class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};
class TESFullName
{
  public:
    virtual ~TESFullName();
};
struct InventoryEntry
{
    TESBoundObject* object;
    int count;
    void* extra;
    InventoryEntry();
};
struct InventoryList
{
    ~InventoryList();
};
struct InventoryChanges
{
};
struct InventoryOwner
{
};
struct InventoryListBox
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void ClearItems();
    void* item;
    void* next;
    Tile* container;
    Tile* selected;
    Tile* scrollbar;
    const char* templateName;
    void PopulateInventoryList(InventoryOwner*, bool(__cdecl*)(InventoryEntry*), int,
                               void(__cdecl*)(Tile*, InventoryEntry*), bool, bool);
};
struct RemovalItem
{
    LBTileObj* tile;
    LBExtraObj* extra;
    bool counted;
};
struct RemovalNode
{
    RemovalItem* item;
    RemovalNode* next;
    ~RemovalNode();
};
struct RemovalHeader
{
    int vtable;
};
struct RemovalList : RemovalHeader, RemovalNode
{
    TileProxy* container;
    LBTileObj* selected;
    bool RemoveNode(RemovalNode* node, RemovalNode* previous);
};
struct RemovalInterface
{
};
struct MenuBase_71f700
{
    virtual ~MenuBase_71f700();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
struct Elem_71f700
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~Elem_71f700();
};
struct List68_71f700
{
    int unk00;
    int unk04;
    int unk08;
    ~List68_71f700();
};
struct Owned_71f700
{
    int unk00;
    ~Owned_71f700();
};
struct Effects_71f700
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
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    ~Effects_71f700();
};
struct ListBoxA_71f700
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
    ~ListBoxA_71f700();
};
struct ListBoxB_71f700
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
    ~ListBoxB_71f700();
};
struct ListBoxC_71f700
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
    ~ListBoxC_71f700();
};
struct ListBoxD_71f700
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
    ~ListBoxD_71f700();
};
struct ListBoxE_71f700
{
    ~ListBoxE_71f700();
};
void FUN_0071f8c0();
struct FUN_0071f700 : MenuBase_71f700
{
    Elem_71f700 elems[4];
    List68_71f700 list68;
    Owned_71f700* p74;
    Owned_71f700* p78;
    Owned_71f700* p7c;
    Owned_71f700* p80;
    Effects_71f700 effects;
    ListBoxA_71f700 list180;
    ListBoxA_71f700 list1b0;
    ListBoxB_71f700 list1e0;
    ListBoxC_71f700 list210;
    ListBoxD_71f700 list240;
    ListBoxE_71f700 list270;
    virtual ~FUN_0071f700();
};
struct TileObjV
{
    virtual void* Del(unsigned int flags);
};
struct ExtraObj
{
    void* FUN_004459e0(unsigned int flags);
};
struct ItemS
{
    TileObjV* curNode;
    ExtraObj* extra;
};
struct TileS
{
};
struct NodeS
{
};
struct OwnerS
{
    void* vptr00;
    ItemS* pSingle;
    NodeS* pHead;
    TileS* pTile;
    int m10;
    int m14;
    int m18;
    unsigned short m_usPassCountLocal;
    unsigned short us1e;
    float m_fGlyphExtent;
    void FUN_007211e0();
};
struct NavigationTile
{
};
struct NavigationItem
{
    NavigationTile* tile;
};
struct NavigationNode
{
    NavigationItem* item;
    NavigationNode* next;
};
struct NavigationBase
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual NavigationTile* GetAt(int current, bool select);
};
struct NavigationList : NavigationBase, NavigationNode
{
    NavigationTile* container;
    NavigationTile* selected;
    NavigationTile* scrollbar;
    const char* templateName;
    unsigned short count;
    NavigationTile* FUN_007214b0(unsigned int action);
};
struct LBClearList : LBListBox
{
    void FUN_00721990();
};
struct Tile_721c60
{
};
struct Item_721c60
{
    Tile_721c60* tile;
};
struct Node_721c60
{
    Item_721c60* item;
    Node_721c60* next;
};
struct Base_721c60
{
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual Tile_721c60* VFunc14(int index, bool flag);
};
struct Class_721c60 : Base_721c60, Node_721c60
{
    Tile_721c60* m_pScrollBar;
    Tile_721c60* m_pSelected;
    int unk14;
    int unk18;
    unsigned short m_usItemCount;

    bool IsScrollBarTraitEnabled();
    Tile_721c60* FUN_00721c60(int action);
};
extern int DAT_01070314;
struct FUN_00722000 : FUN_007240c0
{
    SL sl;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;


    FUN_00722000();
};
struct ListBox_007228f0 : LBListBox
{
};
struct ListBoxClear
{
    void* vtable;
    LBItem* pItem;
    LBNode* pNext;
    TileF* m_pListTile;
    LBTileObj* m_pSelectedTile;
    void* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;

    void FUN_007230e0();
};
struct LBKTile
{
};
struct LBKItem
{
    LBKTile* pTile;
};
struct LBKNode
{
    LBKItem* pItem;
    LBKNode* pNext;
};
struct LBKBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual LBKTile* GetTileByIndex(int aiIndex, int aiUnk);
};
struct LBKListBox : LBKBase, LBKNode
{
    LBKTile* pParentTile;
    LBKTile* pSelected;
    LBKTile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;

    LBKTile* GetTileByKey(int aiKey);
};
struct ListBoxHelper
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual TileHeight* GetItemAt(int index, int flag);
    ListNode head;
    TileHeight* m_0c;
    TileHeight* m_10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    TileHeight* FUN_00723b60(int code);
};
struct HighlightValue
{
};
struct HighlightTile
{
};
struct HighlightList
{
    int unk00;
    int unk04;
    int unk08;
    HighlightTile* container;
    HighlightTile* selected;
    void FUN_007244e0();
};
class Tile724
{
  public:
};
struct Item724
{
    Tile724* m_pkTile;
    int unk04;
    bool m_bHidden;
};
class ItemList724
{
  public:

    Item724* m_pkItem;
    ItemList724* m_pkNext;
};
class MenuBase724
{
  public:
    virtual void vfn00();
};
class ListBox724 : public MenuBase724, public ItemList724
{
  public:
    void RefreshTiles();

    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_usElementCount;
    unsigned short unk1E;
    float m_fScroll;
};
// Whether the list box tile is enabled (trait id resolved once and cached).
class C4FD0Tile
{
  public:
};
class C4FD0ListBox
{
  public:
    int unk00;
    int unk04;
    int unk08;
    C4FD0Tile* m_pkTile;

    bool FUN_00724fd0();
};
struct FUN_00a00f30_shell
{
    void* FUN_00a00f30(int);
};
struct FUN_00a07530_shell
{
    void FUN_00a07530(int);
};
struct FUN_007254d0_t
{
    int unk00;
    int unk04;
    int unk08;
    Tile* container;
    Tile* selected;
    void UpdateSpeechChallengeTrait();
};
struct FUN_00725b70_inner
{
};
struct FUN_00725b70_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00725b70_inner* m_0c;
    bool FUN_00725b70();
};
struct VLPoint3
{
    float x;
    float y;
    float z;
};
struct VLTile;
struct VLListNode;
struct VLTileList
{
    VLTile*& GetNext(VLListNode*& arpPos);
};
struct VLTile
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int GetType();

    VLTileList kChildren;

};
struct VLFontManager
{
};
struct VLList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float fTotalHeight;

    void AccumulateTileHeight(VLTile* apTile);
};
struct Tile050;
struct Value050
{
};
struct Menu050
{
};
struct Tile050
{
};
struct FUN_007a62e0
{
    Tile050* tile;
    int data;
    bool flag;
    FUN_007a62e0(Tile050*, int*);
};
struct List050
{
    FUN_007a62e0* item;
    List050* next;
};
struct Owner050
{
    int unk00;
    List050 entries;
    Tile050* container;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short count;
    Tile050* AddListEntry(int, const char*, int, const char*);
};
struct ItemTile;
struct ItemValue
{
};
struct ItemMenu
{
};
struct ItemTile
{
};
struct BoxItem
{
    ItemTile* tile;
    int data;
    char flag;
    BoxItem(ItemTile*, int*);
};
struct ItemList
{
    BoxItem* item;
    ItemList* next;
};
struct IntListBox
{
    int unk00;
    ItemList items;
    ItemTile* container;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short nextIndex;
    ItemTile* FUN_00764430(int, const char*, int(__cdecl*)(BoxItem*, BoxItem*), const char*);
};
struct ClearTile
{
    virtual ~ClearTile();
};
struct ClearExtra
{
    ~ClearExtra();
};
struct ClearTileExtraPair
{
    ClearTile* tile;
    ClearExtra* extra;
};
struct ClearNode
{
    ~ClearNode();
};
struct ClearContainer
{
};
struct ClearOwner
{
    int unk00;
    ClearTileExtraPair* item;
    ClearNode* next;
    ClearContainer* container;
    int selection;
    int unk14;
    int unk18;
    unsigned short count;
    float height;
    void FUN_007646d0();
};
class C764930Tile
{
  public:
};
struct C764930Item
{
    C764930Tile* m_pkTile;
    int unk04;
    bool m_bHidden;
};
class C764930ListNode
{
  public:

    C764930Item* m_pkItem;
    C764930ListNode* m_pkNext;
};
class C764930MenuBase
{
  public:
    virtual ~C764930MenuBase();
};
class C764930ListMenu : public C764930MenuBase, public C764930ListNode
{
  public:

    void RebuildVisibleTiles();

    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_usNumVisible;
    unsigned short unk1E;
    float m_fScroll;
};
struct Cls_764ef0
{
    int unk00;
    int unk04;
    int unk08;
    Tile* highlightTile;
    Tile* selectedTile;

    void __thiscall UpdateHighlightTile();
};
struct ScrollTile
{
};
struct ScrollList
{
    int unk00;
    int unk04;
    int unk08;
    ScrollTile* container;
    int unk10;
    ScrollTile* scrollbar;
    int unk18;
    int unk1c;
    float total;
    void FUN_00765210();
};
class FUN_007a3ac0_ListBox
{
  public:
    void* vtbl;
    LBItem* pItem;
    LBNode* pNext;
    LBTile* m_pListTile;
    int unk10;
    int unk14;
    int unk18;
    unsigned short usItemCount;
    float m_fFirstListValue;

    void FUN_007a3ac0();
};
struct NavTile
{
};
struct NavItem
{
    NavTile* tile;
};
struct NavNode
{
    NavItem* item;
    NavNode* next;
};
struct Navigation
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual NavTile* At(int, bool);
    NavNode items;
    NavTile* container;
    NavTile* selected;
    int unk14;
    int unk18;
    unsigned short count;
    NavTile* FUN_007a4000(int key);
};
struct ListBox_7a6600
{
    int unk00;
    int unk04;
    int unk08;
    Tile* highlightTile;
    Tile* selectedTile;

    void __thiscall FUN_007a6600();
};
// Whether the list box tile is enabled (trait id resolved once and cached).
class D7580Tile
{
  public:
};
class D7580ListBox
{
  public:
    int unk00;
    int unk04;
    int unk08;
    D7580Tile* m_pkTile;

    bool FUN_007d7580();
};
struct P240Tile
{
};
struct P240Item
{
    P240Tile* tile;
    void* data;
    bool hidden;
};
struct P240List
{
    P240Item* item;
    P240List* next;
};
struct P240Base
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual P240Tile* v5(int, bool);
};
struct P240Owner : P240Base, P240List
{
    P240Tile* container;
    P240Tile* selected;
    P240Tile* scrollbar;
    const char* templateName;
    unsigned short count;
    float height;
    void ApplyFilter(bool(__cdecl* predicate)(void*));
};
// Selects a tile in the list box when the box is active and the tile is null or an enabled member of the list.
class C7D8950Tile
{
  public:
};
class C7D8950ListBox
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C7D8950Tile* m_pkSelected;

    bool FUN_007d8950(C7D8950Tile* pkTile);
};
struct TileValue
{
};
struct TileExt : Tile
{
};
struct ListBoxExt
{
    int unk00;
    int unk04;
    int unk08;
    TileExt* tile0c;
    TileExt* tile10;

    void UpdateHighlightBox();
};
struct TileX2
{
};
struct ListBoxX
{
    int unk00;
    int unk04;
    int unk08;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    void FUN_007d97a0();
};
struct ContNode;
bool __fastcall FUN_008256d0(ContNode*);
struct N6815c0
{
};
struct RList71a5 : RemovalList
{
    bool RemoveTile(LBTileObj* tile);
};
struct Tile118
{
};
struct Item118
{
    Tile118* tile;
};
struct Node118
{
    Item118* item;
    Node118* next;
};
struct Box118
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual Tile118* GetTile(int, int);
    Node118 head;
    Tile118* scroll;
    Tile118* selected;
    int unk14, unk18;
    unsigned short count, flags;
    Tile118* FUN_00722410(unsigned int action);
};

struct TileValue_00a0a270;
struct TileValueOwner_00a01000
{
};

class AGMemoryManager
{
  public:
};
class AGListItem
{
  public:
    virtual ~AGListItem();
    int m_iIndex;
    AGListItem* m_pNext;
    AGListItem() : m_iIndex(2000), m_pNext(0)
    {}
    static void* operator new(unsigned int uiSize)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::AGMemoryManager *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize);
    }
    static void operator delete(void* p);
};
class AGValueItem : public AGListItem
{
  public:
    virtual ~AGValueItem();
    TileValue* m_pIntegerData;
    AGValueItem()
    {}
};
class AGOwner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AGValueItem* m_pHead;
    void FUN_00a09130(int iIndex, Tile* pTile, int iValue);
};

// @fnv 0x00a09130
void AGOwner::FUN_00a09130(int iIndex, Tile* pTile, int iValue)
{
    AGValueItem* pLast = m_pHead;
    AGValueItem* pItem = new AGValueItem;
    pItem->m_iIndex = iIndex;
    pItem->m_pIntegerData = (TileValue*)((::TileValue_00a0a270 *)(reinterpret_cast<::fnv_00a01000::FUN_00a01000_shell *>((((TileValueOwner_00a01000*)pTile)))->GetOrCreateTraitValue(iValue)));
    if (pLast)
    {
        while (pLast->m_pNext)
            pLast = (AGValueItem*)pLast->m_pNext;
        pLast->m_pNext = pItem;
    }
    else
    {
        m_pHead = pItem;
    }
    ::fnv_00a0a130::FUN_00a0a130((int)(pItem->m_pIntegerData), (int)(this));
}
