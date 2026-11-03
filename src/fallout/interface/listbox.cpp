
// src/fallout/interface/listbox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/listbox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/BSS.h"
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
#include "fnv/decl/FUN_007d9e80_Class.h"
#include "fnv/decl/FUN_00a00e90_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01290_shell.h"
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
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ListScrollHost.h"
#include "fnv/decl/P03Value.h"
#include "fnv/decl/StatsMenu.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/W004702f0.h"
#include "fnv/decl/filt7a8__F7Menu.h"
#include "fnv/decl/fnv_00726530__FUN_00726530_t.h"
#include "fnv/decl/fnv_007d9590__ListBox_SaveLoad.h"
#include "fnv/decl/fnv_007d9ee0__ListBox_Option.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a09200__Value_00a09200.h"
#include "fnv/decl/fnv_00a09410__EvalValue.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/decl/p07__FUN_007643c0.h"
#include "fnv/decl/p07__FUN_007d6f80.h"
#include "fnv/decl/q72__Menu.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_00721000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_007d8000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_0106f000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/decl/C7D8EE0List.h"
#include "fnv/decl/FUN_007a80e0_cls.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/fnv_00a01000__FUN_00a01000_shell.h"
#include "fnv/decl/fnv_00a1b020__FUN_00a1b020_t.h"
#include "fnv/decl/list71a__L71Menu.h"
#include "fnv/symbols_006b3000.h"
#include "fnv/symbols_00a0a000.h"
#include "fnv/symbols_011f6000.h"
struct G2
{
    void AddHead(int**);
};


// @fnv 0x00721130
void AddToHeadList(int* arg)
{
    (*reinterpret_cast<::G2 *>(&::g_011d8b54)).AddHead(&arg);
}

namespace fnv_007211c0 {
struct DummyNode
{
};
DummyNode g_011d8b54;

// @fnv 0x007211c0
void FUN_007211c0(int* p)
{
    reinterpret_cast<::ItemChangeListNode *>((void *)&((*reinterpret_cast<::fnv_007211c0::DummyNode *>(&::g_011d8b54))))->FUN_00905330((*(::InventoryStackRecord *const *)(&p)));
}
}  // namespace fnv_007211c0

struct GlobalObject_00869f00
{
};

extern int DAT_010703b4;

struct FUN_00723f30_shell : GlobalObject_00869f00
{
    void FUN_00723f30();
};

// @fnv 0x00723f30
void FUN_00723f30_shell::FUN_00723f30()
{
    *(int*)this = (int)&DAT_010703b4;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};

struct FUN_00723f50_shell : AX
{
    int* vtable;
    AX* FUN_00723f50();
};

// Sets the vtable pointer and calls FUN_006b3eb0 with 0, 0, then returns this.
// @fnv 0x00723f50
AX* FUN_00723f50_shell::FUN_00723f50()
{
    vtable = &DAT_010703c8;
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return this;
}

namespace fnv_00723f80 {
struct GlobalObject_00869f00
{
};


struct FUN_00723f80_shell
{
    void FUN_00723f80();
};

// @fnv 0x00723f80
void FUN_00723f80_shell::FUN_00723f80()
{
    *(void**)this = (void*)&::DAT_010703c8;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_00723f80

namespace fnv_00724020 {
struct GlobalObject_00869f00
{
    char* m_str;
    void FUN_00724020();
};

// @fnv 0x00724020
void GlobalObject_00869f00::FUN_00724020()
{
    m_str = "`Br";
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_00724020

namespace fnv_00724040 {
struct AX
{
    virtual ~AX();
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_00724040();
};

// Sets the object's vtable pointer to DAT_01070404, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00724040
AX* AX::FUN_00724040()
{
    *reinterpret_cast<unsigned int*>(this) = reinterpret_cast<unsigned int>(&(*reinterpret_cast<unsigned int *>(&::DAT_01070404)));
    FUN_006b3eb0(0, 0);
    return this;
}
}  // namespace fnv_00724040


struct FUN_00724140_shell
{
    void FUN_00722880();
    void* Destroy(unsigned int flags);
};

struct FUN_007a51c0_shell
{
};


struct FUN_007a61f0_shell
{
    void* FUN_007a61f0(unsigned int flags);
};

// Calls FUN_007a51c0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x007a61f0
void* FUN_007a61f0_shell::FUN_007a61f0(unsigned int flags)
{
    reinterpret_cast<::FUN_007a51c0_cls *>((((FUN_007a51c0_shell*)this)))->FUN_007a51c0_cls::~FUN_007a51c0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_007a62e0_shell
{
    int a;
    int b;
    char c;
    FUN_007a62e0_shell* FUN_007a62e0(int param2, int* param3);
};

// Stores param2 in a, the first int pointed to by param3 in b, sets c to 0, and returns this.
// @fnv 0x007a62e0
FUN_007a62e0_shell* FUN_007a62e0_shell::FUN_007a62e0(int param2, int* pSource)
{
    a = param2;
    b = *pSource;
    c = 0;
    return this;
}

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
    bool SetSelection(Tile* apItem, int apSelect);
    bool FUN_007d8d80(Tile* apSelectItem);
};

// @fnv 0x007d8d80
bool ListBox::FUN_007d8d80(Tile* apSelectItem)
{
    return SetSelection(apSelectItem, 1);
}

struct FUN_007d8e80_shell
{
    void* FUN_007d8e80(unsigned int flags);
};


// Calls FUN_007d6f80 on this, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x007d8e80
void* FUN_007d8e80_shell::FUN_007d8e80(unsigned int flags)
{
    reinterpret_cast<::p07::FUN_007d6f80 *>((this))->p07::FUN_007d6f80::~FUN_007d6f80();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_007d8eb0_shell
{
    void FUN_007d7d30();
    void* FUN_007d8eb0(unsigned int flags);
};


struct BSSimpleList
{
};

struct FUN_00721410_class
{
    BSSimpleList list;
    void FUN_00721410(void* param);
};

namespace fnv_00722370 {
struct BSSimpleList
{
};

struct FUN_00724f00_shell
{
    void RefreshTiles();
};

struct FUN_00722370_shell
{
    BSSimpleList m_kNode;
    void FUN_00722370(int* pParam);
};

// Sorts the BSSimpleList at offset 4 using the given compare function, then calls RefreshTiles on this object.
// @fnv 0x00722370
void FUN_00722370_shell::FUN_00722370(int* pCompare)
{
    reinterpret_cast<::ItemChangeList *>((reinterpret_cast<BSSimpleList*>(reinterpret_cast<char*>(this) + 4)))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(int (*)(void *, void *))(reinterpret_cast<int(__cdecl*)(void*, void*)>(pCompare)));
    reinterpret_cast<FUN_00724f00_shell*>(this)->RefreshTiles();
}
}  // namespace fnv_00722370

namespace fnv_00722b20 {
struct BSSimpleList
{
};
struct FUN_007254d0_t
{
    void FUN_007254d0();
};

struct FUN_00722b20_shell
{
    void* m_auiShapeKeys;
    BSSimpleList m_kNode;
    void FUN_00722b20(int(__cdecl* fp)(void*, void*));
};

// Sorts the list using the given comparison function, then calls FUN_007254d0 on this object.
// @fnv 0x00722b20
void FUN_00722b20_shell::FUN_00722b20(int(__cdecl* fp)(void*, void*))
{
    reinterpret_cast<::ItemChangeList *>(&(m_kNode))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(fp));
    reinterpret_cast<FUN_007254d0_t*>(this)->FUN_007254d0();
}
}  // namespace fnv_00722b20

extern "C" char str_010703dc[];

struct FUN_00723fa0_shell : AX
{
    int* vtable;
    FUN_00723fa0_shell* FUN_00723fa0();
};

// Sets the vtable pointer to str_010703dc, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00723fa0
FUN_00723fa0_shell* FUN_00723fa0_shell::FUN_00723fa0()
{
    vtable = (int*)&str_010703dc;
    FUN_006b3eb0(0, 0);
    return this;
}

struct FUN_00723ff0_shell : AX
{
    int* vtable;
    FUN_00723ff0_shell* Constructor();
};

// @fnv 0x00723ff0
FUN_00723ff0_shell* FUN_00723ff0_shell::Constructor()
{
    vtable = (int*)"`Br";
    FUN_006b3eb0(0, 0);
    return this;
}


struct FUN_00724070_shell : GlobalObject_00869f00
{
    void FUN_00724070();
};

// @fnv 0x00724070
void FUN_00724070_shell::FUN_00724070()
{
    *(int*)this = (int)&DAT_01070404;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

struct FUN_007241d0_shell : FUN_00723f30_shell
{
    void* FUN_007241d0(unsigned int flags);
};

// Calls the base cleanup, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x007241d0
void* FUN_007241d0_shell::FUN_007241d0(unsigned int flags)
{
    this->FUN_00723f30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00724290_shell
{
    void* FUN_00724290(unsigned int flags);
};

// Calls FUN_00724070, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00724290
void* FUN_00724290_shell::FUN_00724290(unsigned int flags)
{
    reinterpret_cast<::FUN_00724070_shell *>(this)->FUN_00724070();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_007242c0_shell
{
    bool FUN_007242c0(unsigned int flags);
};

// Returns whether the bit at position flags is set in the 16-bit value at offset 0x2c of this object.
// @fnv 0x007242c0
bool FUN_007242c0_shell::FUN_007242c0(unsigned int uiFlagIndex)
{
    return (*(unsigned short*)((char*)this + 0x2c) & (1 << uiFlagIndex)) != 0;
}

struct VATSMenu
{
public:
    unsigned int Create();
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
    unsigned int FUN_0071ae60();
};
// @fnv 0x0071ae60
unsigned int FUN_0071ae60_shell::FUN_0071ae60()
{
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>(((*(TGF**)(this + 3))))->GetFloat(numFiltered);
}

void __cdecl FUN_00724930();
struct FUN_00721bc0_shell
{
    int x;
    void FUN_00721bc0(int(__cdecl* param)(void*, void*));
    void FUN_00724930();
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
// Returns true when the tile exists and its menu equals the given menu.
// @fnv 0x00723030
bool FUN_00723030_Holder::IsTileMenu(Menu* apMenu)
{
    return _t && apMenu == reinterpret_cast<::FUN_00a03c90_shell *>((_t))->FUN_00a03c90();
}

struct FUN_00725aa0_shell
{
};
struct FUN_00723310_shell
{
    BSSimpleList list;
    void FUN_00723310(int(__cdecl* cmp)(void*, void*));
};
// Sorts the list at offset 4 using the given comparator, then calls ProcessSlots on this object.
// @fnv 0x00723310
void FUN_00723310_shell::FUN_00723310(int(__cdecl* cmp)(void*, void*))
{
    reinterpret_cast<::ItemChangeList *>((((BSSimpleList*)((char*)this + 4))))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(cmp));
    reinterpret_cast<::FUN_00725aa0_cls *>((((FUN_00725aa0_shell*)this)))->ProcessSlots();
}

struct FUN_00723ac0_shell
{
    void FUN_00723ac0(void* param);
};
// Sorts the BSSimpleList at this+4 using the given comparison function, then calls FUN_00726090.
// @fnv 0x00723ac0
void FUN_00723ac0_shell::FUN_00723ac0(void* pCompareFunc)
{
    reinterpret_cast<::ItemChangeList *>((((BSSimpleList*)((char*)this + 4))))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(int (*)(void *, void *))((int(__cdecl*)(void*, void*))pCompareFunc));
    reinterpret_cast<::FUN_00726090_cls *>(this)->FUN_00726090();
}

struct FUN_00723f00_shell : AX
{
    int* vtable;
    FUN_00723f00_shell* FUN_00723f00();
};
// Sets the vtable pointer, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x00723f00
FUN_00723f00_shell* FUN_00723f00_shell::FUN_00723f00()
{
    vtable = &DAT_010703b4;
    FUN_006b3eb0(0, 0);
    return this;
}

struct FUN_00723fd0_shell : GlobalObject_00869f00
{
    void FUN_00723fd0();
};

// @fnv 0x00723fd0
void FUN_00723fd0_shell::FUN_00723fd0()
{
    *(char**)(void*)this = str_010703dc;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

struct FUN_00724090_shell
{
    void* FUN_00724090(unsigned int flags);
};

struct FUN_00721920_shell
{
    void FUN_00721920();
};
struct FUN_007240e0_shell
{
    void* FUN_007240e0(unsigned int flags);
};
struct FUN_00724110_This
{
    void* FUN_00724110(unsigned int flags);
};
struct S_00724170
{
    void FUN_00723070();
    void* FUN_00724170(unsigned int flags);
};
struct FUN_007241a0_shell
{
    void* FUN_007241a0(unsigned int flags);
};
struct Helper_00723fd0
{
};

struct FUN_00724230_shell
{
    void* FUN_00724230(unsigned int flags);
};

// Calls FUN_00723fd0 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00724230
void* FUN_00724230_shell::FUN_00724230(unsigned int flags)
{
    reinterpret_cast<::FUN_00723fd0_shell *>((((Helper_00723fd0*)this)))->FUN_00723fd0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00724260_shell
{
    void* FUN_00724260(unsigned int flags);
};
// Calls FUN_00724020, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00724260
void* FUN_00724260_shell::FUN_00724260(unsigned int flags)
{
    reinterpret_cast<::fnv_00724020::GlobalObject_00869f00 *>(this)->FUN_00724020();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Member_007a8b10
{
    ~Member_007a8b10();
};
struct FUN_007643c0_p07 : Member_007a8b10
{
    Member_007a8b10* DestroySelf(unsigned int flags);
};
// Runs the base destructor, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00764e10
Member_007a8b10* FUN_007643c0_p07::DestroySelf(unsigned int flags)
{
    reinterpret_cast<::p07::FUN_007643c0 *>((this))->p07::FUN_007643c0::~FUN_007643c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BSSimpleList;
struct FUN_007a6480_shell
{
    void FUN_007a6480();
};
struct FUN_007a22a0_shell
{
    void FUN_007a22a0(int(__cdecl* cmp)(void*, void*));
};
// Sorts the BSSimpleList at offset 4 using cmp, then calls FUN_007a6480 on this.
// @fnv 0x007a22a0
void FUN_007a22a0_shell::FUN_007a22a0(int(__cdecl* cmp)(void*, void*))
{
    reinterpret_cast<::ItemChangeList *>((((BSSimpleList*)((char*)this + 4))))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(cmp));
    ((FUN_007a6480_shell*)this)->FUN_007a6480();
}

struct FUN_007a30a0_Holder
{
    int* FindNodeValue(int, unsigned char);
    int FUN_007a30a0(int, unsigned char);
};
// Calls FindNodeValue with the given arguments and returns the pointed-to int, or 0 if the returned pointer is null.
// @fnv 0x007a30a0
int FUN_007a30a0_Holder::FUN_007a30a0(int param1, unsigned char param2)
{
    int* p = FindNodeValue(param1, param2);
    return p ? *p : 0;
}

struct FUN_007a80e0_shell
{
    int* InitSceneNodes();
};
struct FUN_007a5700_shell
{
    int* FUN_007a5700(int(__cdecl* cmp)(void*, void*));
};
// Sorts the BSSimpleList at offset 4 using cmp, then returns the result of InitSceneNodes on this object.
// @fnv 0x007a5700
int* FUN_007a5700_shell::FUN_007a5700(int(__cdecl* cmp)(void*, void*))
{
    reinterpret_cast<::ItemChangeList *>((reinterpret_cast<BSSimpleList*>(reinterpret_cast<char*>(this) + 4)))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(cmp));
    return reinterpret_cast<FUN_007a80e0_shell*>(this)->InitSceneNodes();
}

struct FUN_007a1aa0_shell
{
    void FUN_007a1aa0();
};
struct FUN_007a6100_shell : FUN_007a1aa0_shell
{
    void* FUN_007a6100(unsigned int flags);
};
// @fnv 0x007a6100
void* FUN_007a6100_shell::FUN_007a6100(unsigned int flags)
{
    FUN_007a1aa0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_007a6130_This
{
    void* FUN_007a6130(unsigned int flags);
};
// @fnv 0x007a6130
void* FUN_007a6130_This::FUN_007a6130(unsigned int flags)
{
    reinterpret_cast<::FUN_007a1d60_cls *>(this)->FUN_007a1d60_cls::~FUN_007a1d60_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_007a6190Owner
{
    void* FUN_007a6190(unsigned int flags);
};
// Calls FUN_007a37b0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x007a6190
void* FUN_007a6190Owner::FUN_007a6190(unsigned int flags)
{
    reinterpret_cast<::FUN_007a37b0 *>(this)->FUN_007a37b0::~FUN_007a37b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_007a86b0_Item
{
    int a;
    int b;
};
struct FUN_007a63b0_holder
{
    void FUN_007a63b0(FUN_007a86b0_Item*, unsigned int);
};
// Calls FUN_007a86b0(0) on each of the count items in arr.
// @fnv 0x007a63b0
void FUN_007a63b0_holder::FUN_007a63b0(FUN_007a86b0_Item* apItems, unsigned int count)
{
    for (int i = 0; i < count; ++i)
        reinterpret_cast<::BSS *>(&(apItems[i]))->FUN_007a86b0(0);
}

struct FUN_007a63f0_shell
{
    void FUN_007a63f0(unsigned int requested, unsigned int savedSize);
};
struct FUN_007d9000_shell
{
};
struct FUN_007d7a80_shell
{
    void FUN_007d7a80(int a);
};
void __cdecl UpdateSaveLoadList();
struct FUN_007d8420_shell
{
    BSSimpleList list;
    void SortList(int(__cdecl* cmp)(void*, void*));
    void UpdateSaveLoadList();
};
// Sorts the list at offset 4 using the given comparison function, then calls UpdateSaveLoadList.
// @fnv 0x007d8420
void FUN_007d8420_shell::SortList(int(__cdecl* cmp)(void*, void*))
{
    reinterpret_cast<::ItemChangeList *>((((BSSimpleList*)((char*)this + 4))))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(cmp));
    reinterpret_cast<::fnv_007d9590::ListBox_SaveLoad *>(this)->UpdateSaveLoadList();
}

struct FUN_007a6fa0_shell
{
    int* FindNodeValue(int* a, unsigned char b);
};
struct FUN_007d86c0_shell
{
    int* FUN_007d86c0(int* apItem, unsigned char apSelect);
};
// @fnv 0x007d86c0
int* FUN_007d86c0_shell::FUN_007d86c0(int* apItem, unsigned char apSelect)
{
    FUN_007a6fa0_shell* result = (FUN_007a6fa0_shell*)((FUN_007a6fa0_shell*)this)->FindNodeValue(apItem, apSelect);
    return result ? *(int**)((char*)result + 4) : 0;
}

struct NavMeshSearchLOSArray
{
    int _00;
    void* data;
    int size;
    int capacity;
    void FUN_007d8e20(bool);
};
// @fnv 0x007d8e20
void NavMeshSearchLOSArray::FUN_007d8e20(bool freeStorage)
{
    if (data)
    {
        reinterpret_cast<::FUN_007d9e80_Class *>(this)->FUN_007d9e80((::FUN_005aa3f0_Class *)(data), size);
        if (freeStorage)
        {
            ::FUN_006a8500((::DummyClass_006a8500 *)this);
            data = 0;
            capacity = 0;
        }
        size = 0;
    }
}

namespace fnv_007a3cf0 {
struct BSSimpleList
{
};

struct FUN_007a3cf0_shell
{
    char pad[4];
    BSSimpleList m_kNode;
    void FUN_007a3cf0(int(__cdecl* compare)(void*, void*));
};

struct FUN_007a7260_shell
{
};

// @fnv 0x007a3cf0
void FUN_007a3cf0_shell::FUN_007a3cf0(int(__cdecl* compare)(void*, void*))
{
    reinterpret_cast<::ItemChangeList *>(&(m_kNode))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(compare));
    reinterpret_cast<::q72::Menu *>((reinterpret_cast<FUN_007a7260_shell*>(this)))->FUN_007a7260();
}
}  // namespace fnv_007a3cf0

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

// @fnv 0x0071ad30
void ListBox_71ad30::UpdateScrollPages()
{
    if (m_pListTile)
    {
        int inumPages;
        float flistHeight;
        flistHeight = reinterpret_cast<::TileListBoxCalls *>((((TGF*)m_pListTile)))->GetFloat(0xfb0);
        inumPages = 1;
        if (m_fFirstListValue > 0 && flistHeight > 0)
        {
            if (m_fFirstListValue > flistHeight)
                inumPages = FUN_00647b70((int)FUN_004e4430(((FUN_0071ae60_shell*)this)->FUN_0071ae60() *
                                                           (m_fFirstListValue - flistHeight) / m_fFirstListValue) +
                                             1,
                                         2);
            if (inumPages > 1)
                reinterpret_cast<::FUN_00a012d0_t *>((((TileF*)m_pListTile)))->FUN_00a012d0(FUN_00a01860("_scroll_delta"), (m_fFirstListValue - flistHeight) / (inumPages - 1), true);
        }
        if (m_pHighlightedTile)
            reinterpret_cast<::Tile *>((((Tile_Set_Helper*)m_pHighlightedTile)))->Set(FUN_00a01860("_number_of_items"), inumPages);
    }
}

namespace fnv_00723890 {
struct InventoryStackRecord
{
    ~InventoryStackRecord();
};
struct TileV
{
    virtual ~TileV();
};
struct ListBoxItem
{
    TileV* tile;
    InventoryStackRecord* object;
};
struct List_009e03e0
{
    ~List_009e03e0();
};
struct TileF
{
};
struct FUN_00723890_this
{
    int unk00;
    ListBoxItem* m_item;
    List_009e03e0* m_next;
    TileF* tile;
    int field10;
    int unk14;
    int unk18;
    short field1c;
    float field20;
    void FUN_00726210();
    void FUN_00723890();
};

// @fnv 0x00723890
void FUN_00723890_this::FUN_00723890()
{
    while (m_next && *((::fnv_00723890::ListBoxItem **)(new ((void *)(m_next)) ::Vec3())))
    {
        List_009e03e0* next = ((::fnv_00723890::List_009e03e0 *)(reinterpret_cast<::Callees *>((m_next))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::fnv_00723890::ListBoxItem **)(new ((void *)(m_next)) ::Vec3())))->tile;
        if (((FUN_007242c0_shell*)this)->FUN_007242c0(1))
            delete (*((::fnv_00723890::ListBoxItem **)(new ((void *)(m_next)) ::Vec3())))->object;
        delete *((::fnv_00723890::ListBoxItem **)(new ((void *)(m_next)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((m_next))->Initialize((::CombatController *)(0));
        delete m_next;
        m_next = next;
    }
    if (m_item)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete m_item->tile;
        if (((FUN_007242c0_shell*)this)->FUN_007242c0(1))
            delete m_item->object;
        delete m_item;
    }
    m_item = 0;
    field1c = 0;
    field20 = 0.0f;
    if (tile)
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(::FUN_00a01860("_num_filtered"), 0.0f, true);
    reinterpret_cast<::fnv_00726530::FUN_00726530_t *>(this)->FUN_00726530();
    field10 = 0;
    FUN_00726210();
}
}  // namespace fnv_00723890

namespace fnv_007d74f0 {
extern int DAT_011dac6c;
extern int DAT_011dac70;
struct Tile_Set_Helper
{
};
struct FUN_007d74f0_shell
{
    void FUN_007d74f0(bool abVal);
};
// Sets the "_enabled" trait on the tile via the helper at this+0xc.
// @fnv 0x007d74f0
void FUN_007d74f0_shell::FUN_007d74f0(bool abVal)
{
    static int s_trait = ::FUN_00a00940("_enabled", -1);
    reinterpret_cast<::Tile *>((((Tile_Set_Helper*)*(char**)((char*)this + 0xc))))->Set(s_trait, abVal);
}
}  // namespace fnv_007d74f0

struct TileSet
{
};
struct FUN_007d8810_shell
{
    void* m0;
    void* m4;
    void* m8;
    TileSet* mC;
    void FUN_007d8810(bool abVal);
};
// Sets the _enabled trait on the TileSet at mC to abVal using the cached trait ID.
// @fnv 0x007d8810
void FUN_007d8810_shell::FUN_007d8810(bool abVal)
{
    static int sTraitID = ::FUN_00a00940("_enabled", -1);
    reinterpret_cast<::Tile *>((mC))->Set(sTraitID, abVal);
}

extern int DAT_011d95ac;
extern int DAT_011d95b0;
struct FUN_00765340_shell : VATSMenu
{
    int pad[3];
    TGF* tile;
    unsigned int GetUnfilteredCount();
};
// @fnv 0x00765340
unsigned int FUN_00765340_shell::GetUnfilteredCount()
{
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(numFiltered);
}

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

// Returns the difference between the current count and the tile's float value for the _num_filtered setting.
// @fnv 0x007d8700
unsigned int FUN_007d8700_shell::GetFilteredItemCount()
{
    static int numFiltered = ::FUN_00a00940("_num_filtered", -1);
    return ::GetRaceCount((char *)this) - (unsigned int)reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(numFiltered);
}

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

// @fnv 0x00721060
FUN_00721060::FUN_00721060()
{
    vptr = &DAT_01070220;

    m_pHighlightedTile = 0;
    m_pSelectedTile = 0;
    m_pListTile = 0;
    pTemplateName = 0;

    usFlags = 0;
    m_usSelectedIndex = 0;

    m_fThirdListValue = 0.0f;
    m_fSecondListValue = 0.0f;
    m_fFirstListValue = 0.0f;

    reinterpret_cast<::FlagS *>((((ListBox_SetSelectedTile_shell*)this)))->FUN_007a1950((unsigned int)(0), true);

    AddToHeadList((int*)this);
}

namespace fnv_00722f60 {
struct FUN_007240c0
{
    char* value;

    FUN_007240c0();
};

struct SL
{
    unsigned char data[8];

    SL();
    ~SL();
};

struct ListBox_TESQuest_SetSelectedTile_Helper
{
};

extern char str_01070364[];

struct FUN_00722f60 : public FUN_007240c0
{
    SL sl;
    int field0c;
    int field10;
    int field14;
    int field18;
    short field1c;
    float field20;
    float field24;
    float field28;
    short field2c;

    FUN_00722f60();
};

FUN_007240c0::FUN_007240c0()
{}

SL::SL()
{}

SL::~SL()
{}

// Initializes the object's fields to zero, sets value to str_01070364, calls SetSelectedTile(0, true) and AddToHeadList.
// @fnv 0x00722f60
FUN_00722f60::FUN_00722f60()
{
    value = str_01070364;

    field14 = 0;
    field10 = 0;
    field0c = 0;
    field18 = 0;
    field2c = 0;
    field1c = 0;
    field28 = 0.0f;
    field24 = 0.0f;
    field20 = 0.0f;

    reinterpret_cast<::FlagS *>((reinterpret_cast<ListBox_TESQuest_SetSelectedTile_Helper*>(this)))->FUN_007a1950((unsigned int)(0), true);
    AddToHeadList(reinterpret_cast<int*>(this));
}
}  // namespace fnv_00722f60

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

    void UpdateHighlightTiles();
};

namespace fnv_007a43a0 {
struct FUN_007240c0
{
    int _padding;
    FUN_007240c0();
};

struct SL
{
    int _padding[2];
    SL();
    ~SL();
};

extern int DAT_010755bc[];

struct FUN_007a43a0_ListBoxHelper
{
};

struct FUN_007a43a0 : FUN_007240c0, SL
{
    int field_0c;
    int field_10;
    int field_14;
    int field_18;
    short field_1c;
    float field_20;
    float field_24;
    float field_28;
    short field_2c;

    FUN_007a43a0();
};

// Initialises the object's fields to zero, sets the vtable, clears the selected tile and calls AddToHeadList.
// @fnv 0x007a43a0
FUN_007a43a0::FUN_007a43a0() : FUN_007240c0(), SL()
{
    *(int**)this = DAT_010755bc;
    field_14 = 0;
    field_10 = 0;
    field_0c = 0;
    field_18 = 0;
    field_2c = 0;
    field_1c = 0;
    field_28 = 0.0f;
    field_24 = 0.0f;
    field_20 = 0.0f;

    reinterpret_cast<::FlagS *>((reinterpret_cast<FUN_007a43a0_ListBoxHelper*>(this)))->FUN_007a1950((unsigned int)(0), true);
    AddToHeadList((int*)this);
}
}  // namespace fnv_007a43a0

struct Tile_IsTrue_helper
{
};

struct FUN_007a6bd0_shell
{
    char _base[0x0c];
    Tile* m_pListTile;
    bool FUN_007a6bd0();
};

struct FUN_007a79b0_shell
{
    char _pad[12];
    Tile* m_pListTile;
    bool FUN_007a79b0();
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
// Calls FUN_00721150, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00724090
void* FUN_00724090_shell::FUN_00724090(unsigned int flags)
{
    reinterpret_cast<::FUN_00721150_cls *>(this)->FUN_00721150_cls::~FUN_00721150_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

int __cdecl FUN_00a00940(const char*, int);

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

    bool SelectObject(SelectedObject* object);
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

// Initializes the object's vtable pointer, clears its Tile pointers, template name, flags, and float fields, then calls FUN_007a1950 and AddToHeadList.
// @fnv 0x00721850
FUN_00721850_cls::FUN_00721850_cls()
{
    vptr = &DAT_010702ec;
    m_pHighlightedTile = 0;
    m_pSelectedTile = 0;
    m_pListTile = 0;
    pTemplateName = 0;
    usFlags = 0;
    m_usSelectedIndex = 0;
    m_fThirdListValue = 0.0f;
    m_fSecondListValue = 0.0f;
    m_fFirstListValue = 0.0f;
    reinterpret_cast<::FlagS *>((((FUN_00721850_shell*)this)))->FUN_007a1950(0, 1);
    AddToHeadList((int*)this);
}

struct CleanupMember_00721920
{
    ~CleanupMember_00721920();
};

struct FUN_00721920
{
    virtual ~FUN_00721920();
    CleanupMember_00721920 cleanup;
};
// Calls FUN_00721920 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007240e0
void* FUN_007240e0_shell::FUN_007240e0(unsigned int flags)
{
    reinterpret_cast<::FUN_00721920 *>((((FUN_00721920_shell*)this)))->FUN_00721920::~FUN_00721920();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


namespace fnv_00721bf0 {
const char* __cdecl FUN_00a00940(const char*, int);
struct TileLink
{
    bool IsTraitNonZero(const char*);
};
struct TargetMenu
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    TileLink* selected;
    bool IsScrollBarTraitEnabled();
    bool ContainsKey(TileLink*);
    void UpdateTraitDisplay();
    bool FUN_00721bf0(TileLink*);
};
// @fnv 0x00721bf0
bool TargetMenu::FUN_00721bf0(TileLink* item)
{
    if (IsScrollBarTraitEnabled() &&
        (item == 0 || (ContainsKey(item) && item->IsTraitNonZero(((const char *)(::FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1)))))))
    {
        selected = item;
        UpdateTraitDisplay();
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_00721bf0


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
// Calls FUN_007220d0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00724110
void* FUN_00724110_This::FUN_00724110(unsigned int flags)
{
    reinterpret_cast<::FUN_007220d0_cls *>(this)->FUN_007220d0_cls::~FUN_007220d0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


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
    void FUN_00725080();
    int unk14;
    int unk18;
    unsigned short usItemCount;
    float m_fFirstListValue;
};
// @fnv 0x007220d0
FUN_007220d0_cls::~FUN_007220d0_cls()
{
    reinterpret_cast<::LBListBox *>(this)->FUN_00722140();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}

int __cdecl FUN_00a00940(const char*, int);

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
    void FUN_00725080();
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

// @fnv 0x007227b0
FUN_007227b0_cls::FUN_007227b0_cls()
{
    vptr = (int*)"P+r";
    unk14 = 0;
    unk10 = 0;
    unk0c = 0;
    unk18 = 0;
    w2c = 0;
    w1c = 0;
    f28 = 0.0f;
    f24 = 0.0f;
    f20 = 0.0f;
    reinterpret_cast<::FlagS *>((((FUN_007227b0_target*)this)))->FUN_007a1950(0, 1);
    AddToHeadList((int*)this);
}

struct Member_00722880
{
    ~Member_00722880();
};

Member_00722880::~Member_00722880()
{}

struct Helper_007228f0
{
    void Call();
};

void Helper_007228f0::Call()
{}


struct FUN_00722880
{
    virtual ~FUN_00722880();
    Member_00722880 member4;
};
// Calls FUN_00722880, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00724140
void* FUN_00724140_shell::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00722880 *>(this)->FUN_00722880::~FUN_00722880();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Calls Call on the object, then passes this to FUN_007211c0.
// @fnv 0x00722880
FUN_00722880::~FUN_00722880()
{
    ((Helper_007228f0*)this)->Call();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}

namespace fnv_00722b50 {
struct Entry
{
    bool IsTraitNonZero(void*);
};
struct Holder
{
    int unk00, unk04, unk08, unk0c;
    Entry* selected;
    bool FUN_007255a0();
    bool ContainsKey(Entry*);
    void UpdateSpeechChallengeTrait();
    bool SelectEntry(Entry*);
};
extern "C" void* __cdecl FUN_00a00940(const void*, int);
// @fnv 0x00722b50
bool Holder::SelectEntry(Entry* pEntry)
{
    if (FUN_007255a0() && (!pEntry || (ContainsKey(pEntry) && pEntry->IsTraitNonZero(((void *)(::FUN_00a00940((const char *)(const void *)(&(*reinterpret_cast<int *>((void *)&::kListBoxEnabled))), -1)))))))
    {
        selected = pEntry;
        UpdateSpeechChallengeTrait();
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_00722b50

struct FUN_0046ffb0
{
    ~FUN_0046ffb0();
};
struct FUN_00723070
{
    virtual ~FUN_00723070();
    FUN_0046ffb0 cleanupMember;
};
// Calls FUN_00723070, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00724170
void* S_00724170::FUN_00724170(unsigned int flags)
{
    reinterpret_cast<::FUN_00723070 *>(this)->FUN_00723070::~FUN_00723070();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00723340 {
struct FUN_00723340_arg
{
    bool IsTraitNonZero(void* param);
};

void* __cdecl FUN_00a00940(const char* name, int len);

struct FUN_00723340_cls
{
    char unk00[0x10];
    FUN_00723340_arg* m_pArg;

    bool FUN_00725b70();
    bool ContainsKey(FUN_00723340_arg* arg);
    bool FUN_00723340(FUN_00723340_arg* arg);
};

// @fnv 0x00723340
bool FUN_00723340_cls::FUN_00723340(FUN_00723340_arg* arg)
{
    if (FUN_00725b70() && (arg == 0 || (ContainsKey(arg) && arg->IsTraitNonZero(((void *)(::FUN_00a00940("_enabled", -1)))))))
    {
        m_pArg = arg;
        reinterpret_cast<::FUN_00725c20_shell *>(this)->UpdateHighlightTiles();
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_00723340

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

// Initialises the object's vtable pointer and zeroes its integer, short and float members, then calls FUN_007a1950(0, 1) and AddToHeadList.
// @fnv 0x00723750
FUN_00723750::FUN_00723750()
{
    *(void**)this = &DAT_0107038c;
    this->m_14 = 0;
    this->m_10 = 0;
    this->m_0c = 0;
    this->m_18 = 0;
    this->m_2c = 0;
    this->m_1c = 0;
    this->m_28 = 0.0f;
    this->m_24 = 0.0f;
    this->m_20 = 0.0f;
    reinterpret_cast<::FlagS *>((this))->FUN_007a1950(0, 1);
    AddToHeadList((int*)this);
}


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
// Calls FUN_00723820, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007241a0
void* FUN_007241a0_shell::FUN_007241a0(unsigned int flags)
{
    reinterpret_cast<::FUN_00723820_cls *>(this)->FUN_00723820_cls::~FUN_00723820_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00723820
FUN_00723820_cls::~FUN_00723820_cls()
{
    reinterpret_cast<::fnv_00723890::FUN_00723890_this *>(this)->FUN_00723890();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}


int __cdecl FUN_00a00940(const char* pcTrait, int iIndex);

class B23AF0Tile
{
  public:
};

class B23AF0ListBox
{
  public:
    void Refresh();
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
// Walks the linked list from head and returns true if any item's key equals key, otherwise false.
// @fnv 0x007242f0
bool ListOwner::ContainsKey(int key)
{
    ListLink* current = this ? &head : 0;
    for (; current && *((::ListItem **)(new ((void *)(current)) ::Vec3())); current = ((::ListLink *)(reinterpret_cast<::Callees *>((current))->FUN_00726070())))
    {
        if ((*((::ListItem **)(new ((void *)(current)) ::Vec3())))->key == key)
        {
            return true;
        }
    }
    return false;
}

struct FUN_00724360_Item
{
};

struct FUN_00724360_Obj
{
    void FUN_00700320(unsigned int a, unsigned int b);
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
    void FUN_00724800();
};
// Sorts the list at offset 4 using the given comparator, then calls FUN_00724360.
// @fnv 0x00721410
void FUN_00721410_class::FUN_00721410(void* pComparator)
{
    reinterpret_cast<::ItemChangeList *>((reinterpret_cast<BSSimpleList*>(reinterpret_cast<char*>(this) + 4)))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(int (*)(void *, void *))((int(__cdecl*)(void*, void*))pComparator));
    reinterpret_cast<::FUN_00724360_cls *>(this)->FUN_00724360();
}

int __cdecl FUN_00a00940(const char* name, int value);
struct Item_00724430
{
};
struct Owner_00724430
{
    int unk00;
    int unk04;
    int unk08;
    Item_00724430* item;
    bool FUN_00724430();
};
struct Obj00724930
{
    void FUN_00700320(unsigned int a, int b);
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

    void UpdateTraitDisplay();
    void FUN_00724930();
};
// Sorts the BSSimpleList at offset 4 using the given comparison function, then calls FUN_00724930 on this object.
// @fnv 0x00721bc0
void FUN_00721bc0_shell::FUN_00721bc0(int(__cdecl* param)(void*, void*))
{
    reinterpret_cast<::ItemChangeList *>((reinterpret_cast<BSSimpleList*>((char*)this + 4)))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(param));
    reinterpret_cast<::FUN_00724930_cls *>((this))->FUN_00724930();
}


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

// @fnv 0x00724dd0
void VATSMenuView::FUN_00724dd0()
{
    if (pScrollTile)
    {
        float fScrollValue = reinterpret_cast<::TileListBoxCalls *>((pScrollTile))->GetFloat(0xfb0);
        int iItemCount = 1;
        if (fTotal > 0.0 && fScrollValue > 0.0)
        {
            if (fTotal > fScrollValue)
            {
                iItemCount = FUN_00647b70((int)FUN_004e4430(FUN_00726710() * (fTotal - fScrollValue) / fTotal) + 1, 2);
            }
            if (iItemCount > 1)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((((TileFloatSet*)pScrollTile)))->FUN_00a012d0(FUN_00a01860("_scroll_delta"), (fTotal - fScrollValue) / (iItemCount - 1), true);
            }
        }
        if (pCountTile)
        {
            reinterpret_cast<::Tile *>((pCountTile))->Set(FUN_00a01860("_number_of_items"), iItemCount);
        }
    }
}

struct TileProxy
{
    void FUN_00700320(int, int);
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
// @fnv 0x00722140
void LBListBox::FUN_00722140()
{
    while (pNext && *((::LBItem **)(new ((void *)(pNext)) ::Vec3())))
    {
        LBNode* next = ((::LBNode *)(reinterpret_cast<::Callees *>((pNext))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
        {
            delete (*((::LBItem **)(new ((void *)(pNext)) ::Vec3())))->tile;
        }
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
        {
            delete (*((::LBItem **)(new ((void *)(pNext)) ::Vec3())))->extra;
        }
        delete *((::LBItem **)(new ((void *)(pNext)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((pNext))->Initialize((::CombatController *)(0));
        delete pNext;
        pNext = next;
    }
    if (pItem)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
        {
            delete pItem->tile;
        }
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
        {
            delete pItem->extra;
        }
        delete pItem;
    }
    pItem = 0;
    usItemCount = 0;
    m_fFirstListValue = 0.0f;
    if (m_pListTile)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((m_pListTile))->FUN_00a012d0(FUN_00a01860("_num_filtered"), 0.0f, true);
    }
    reinterpret_cast<::OwnerProxy *>(this)->FUN_007253a0();
    unk10 = 0;
    FUN_00725080();
}
// Reads a value from tile0c, computes a scroll delta from range and that value, applies it to tile0c, and passes the count to tile14.
// @fnv 0x007253a0
void OwnerProxy::FUN_007253a0()
{
    if (tile0c)
    {
        float p = reinterpret_cast<::TileListBoxCalls *>((tile0c))->GetFloat(4016);
        int h = 1;
        if (range > 0.0 && p > 0.0)
        {
            if (range > p)
            {
                h = FUN_00647b70((int)FUN_004e4430(((unsigned int)(reinterpret_cast<::VATSMenu *>(this)->FUN_007267c0())) * (range - p) / range) + 1, 2);
            }
            if (h > 1)
                reinterpret_cast<::FUN_00a012d0_t *>((tile0c))->FUN_00a012d0(FUN_00a01860("_scroll_delta"), (range - p) / (h - 1), true);
        }
        if (tile14)
            reinterpret_cast<::Tile *>((tile14))->Set(FUN_00a01860("_number_of_items"), h);
    }
}

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

int __cdecl FUN_00a00940(const char* name, int len);

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
// @fnv 0x00725970
void S725970::FUN_00725970()
{
    int n;
    float f6;
    if (tileA)
    {
        f6 = reinterpret_cast<::TileListBoxCalls *>((tileA))->GetFloat(0xfb0);
        n = 1;
        if (fVal > 0.0 && f6 > 0.0)
        {
            if (fVal > f6)
                n = FUN_00647b70((int)FUN_004e4430((float)(unsigned int)reinterpret_cast<::FilteredList *>(this)->FUN_00726870() * (fVal - f6) / fVal) + 1, 2);
            if (n > 1)
                reinterpret_cast<::FUN_00a012d0_t *>((tileA))->FUN_00a012d0(FUN_00a01860(str_0106f90c), (fVal - f6) / (n - 1), true);
        }
        if (tileB)
            reinterpret_cast<::Tile *>((tileB))->Set(FUN_00a01860(str_0106f8f8), n);
    }
}


int __cdecl FUN_00a00940(const char* pcTrait, int iIndex);

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
// Initialises the object's vtable, clears its pointers, flags, indices and floats, then calls FUN_007a1950(0,1) and AddToHeadList.
// @fnv 0x00730810
FUN_00730810::FUN_00730810()
{
    vptr = &DAT_01070890;
    scrollbar = 0;
    selected = 0;
    container = 0;
    templateName = 0;
    flags = 0;
    nextIndex = 0;
    lastScrollbar = 0.0f;
    lastSelection = 0.0f;
    totalHeight = 0.0f;
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950(0, 1);
    ::AddToHeadList((int *)(::FUN_00730810 *)(this));
}

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

int __cdecl FUN_00a00940(const char* s, int n);

int __cdecl FUN_00a00940(const char*, int);

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
    int* FindItemData(int* key);
};
// Walks the head node list, comparing each item's key to *key, and returns the matching item's data pointer or 0.
// @fnv 0x007a22d0
int* Owner::FindItemData(int* piKey)
{
    Node* iter = this ? &head : 0;
    for (; iter && *((::Item **)(new ((void *)(iter)) ::Vec3())); iter = ((::Node *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070())))
    {
        if ((*((::Item **)(new ((void *)(iter)) ::Vec3())))->key == *piKey)
        {
            return (*((::Item **)(new ((void *)(iter)) ::Vec3())))->data;
        }
    }
    return 0;
}


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

int __cdecl FUN_00a00940(const char* name, int len);

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

// Initializes the tile list's pointers, flags, counts and scroll values to zero, then clears the selection and calls AddToHeadList on this.
// @fnv 0x007a27f0
FUN_007a27f0_cls::FUN_007a27f0_cls()
{
    m_pkSelected = 0;
    m_pkScrollBar = 0;
    m_pkParentTile = 0;
    m_pkTemplate = 0;
    m_sFlags = 0;
    m_sItemCount = 0;
    m_fItemHeight = 0.0f;
    m_fScrollMax = 0.0f;
    m_fScrollPos = 0.0f;
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950((unsigned int)(0), true);
    ::AddToHeadList((int *)(void *)(this));
}

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

// @fnv 0x007a36e0
FUN_007a36e0_cls::FUN_007a36e0_cls() : FUN_007240c0(), m_04()
{
    vptr = (int*)&DAT_01075594;
    m_14 = 0;
    m_10 = 0;
    m_0c = 0;
    m_18 = 0;
    m_2c = 0;
    m_1c = 0;
    m_28 = 0.0f;
    m_24 = 0.0f;
    m_20 = 0.0f;
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950(0, 1);
    AddToHeadList((int*)this);
}

struct FUN_007a6310_Elem8
{
    int a;
    int b;
    FUN_007a6310_Elem8();
};


struct FUN_007a6310_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void ConstructElements(int arr, unsigned int count);
};
// @fnv 0x007a63f0
void FUN_007a63f0_shell::FUN_007a63f0(unsigned int uiRequestedSize, unsigned int savedSize)
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 12) = 0;
    if (savedSize > uiRequestedSize)
    {
        uiRequestedSize = savedSize;
    }
    if (uiRequestedSize > 0)
    {
        *(int*)((char*)this + 4) =
            ((int(*)(void*, unsigned int))(*(int**)(*(int*)this + 4)))((void*)this, uiRequestedSize);
        *(int*)((char*)this + 12) = uiRequestedSize;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::FUN_007a6310_cls *>(this)->ConstructElements(*(int*)((char*)this + 4), savedSize);
        *(int*)((char*)this + 8) = savedSize;
    }
}

// Default-constructs count FUN_007a6310_Elem8 objects in place at arr.
// @fnv 0x007a6310
void FUN_007a6310_cls::ConstructElements(int apElements, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        new (&((FUN_007a6310_Elem8*)apElements)[i]) FUN_007a6310_Elem8();
    }
}

namespace fnv_007a6480 {
struct FUN_00700320_shell
{
    void FUN_00700320(unsigned int a, unsigned int b);
};

struct Inner
{
    void FUN_00700320(unsigned int a, unsigned int b);
};

struct Obj
{
    Inner* inner;
    int unk04;
    unsigned char flag08;
};

struct Holder
{
    Obj* obj;
};

struct Node
{
};

struct FUN_007a6480_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short unk1c;
    float unk20;

    void AccumulateTileHeight(Inner* p);
    void FUN_007a6920();
    void FUN_007a6600();
    void FUN_007a6480();
};

// @fnv 0x007a6480
void FUN_007a6480_cls::FUN_007a6480()
{
    unk1c = 0;
    unk20 = 0.0f;
    for (Node* cur = this ? (Node*)&unk04 : 0; cur != 0 && ((::fnv_007a6480::Holder *)(new ((void *)(cur)) ::Vec3()))->obj != 0; cur = ((::fnv_007a6480::Node *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070())))
    {
        if (((::fnv_007a6480::Holder *)(new ((void *)(cur)) ::Vec3()))->obj->flag08 == 0)
        {
            reinterpret_cast<::Tile *>((((::fnv_007a6480::Holder *)(new ((void *)(cur)) ::Vec3()))->obj->inner))->Set(0xfac, unk1c++);
            AccumulateTileHeight(((::fnv_007a6480::Holder *)(new ((void *)(cur)) ::Vec3()))->obj->inner);
        }
    }
    FUN_007a6920();
    FUN_007a6600();
}
}  // namespace fnv_007a6480

int __cdecl FUN_00a00940(const char*, int);

struct FUN_00a01230_shell
{
    bool IsTraitNonZero(int);
};
// Returns true if the tile pointer is non-null and its _enabled trait evaluates to true.
// @fnv 0x007a6bd0
bool FUN_007a6bd0_shell::FUN_007a6bd0()
{
    static int enabledTrait = ::FUN_00a00940("_enabled", -1);

    return m_pListTile != 0 && reinterpret_cast<::FUN_00a01230_shell *>((reinterpret_cast<Tile_IsTrue_helper*>(m_pListTile)))->IsTraitNonZero(enabledTrait);
}
// Returns true if the stored Tile pointer is non-null and its _enabled trait evaluates to true.
// @fnv 0x007a79b0
bool FUN_007a79b0_shell::FUN_007a79b0()
{
    static int userTrait = ::FUN_00a00940("_enabled", -1);

    return m_pListTile && reinterpret_cast<::FUN_00a01230_shell *>((static_cast<Tile_IsTrue_shell*>(m_pListTile)))->IsTraitNonZero(userTrait);
}
// If the list box is enabled and the tile is null or contained and passes the enabled check, stores it as m_pkSelected, refreshes, and returns true.
// @fnv 0x00723af0
bool B23AF0ListBox::FUN_00723af0(B23AF0Tile* pkTile)
{
    if (reinterpret_cast<::B726160Menu *>(this)->FUN_00726160() && (!pkTile || (reinterpret_cast<::ListOwner *>(this)->ContainsKey((int)(pkTile)) && reinterpret_cast<::FUN_00a01230_shell *>((pkTile))->IsTraitNonZero(FUN_00a00940(kListBoxEnabled, -1)))))
    {
        m_pkSelected = pkTile;
        Refresh();
        return true;
    }
    else
    {
        return false;
    }
}
// @fnv 0x00724430
bool Owner_00724430::FUN_00724430()
{
    static int selectedValue = FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1);
    return item != 0 && reinterpret_cast<::FUN_00a01230_shell *>((item))->IsTraitNonZero(selectedValue);
}
// Returns 1 if m_0c is non-null and its IsTraitNonZero returns true for the cached "_enabled" setting, otherwise 0.
// @fnv 0x007255a0
unsigned char FUN_007255a0_cls::FUN_007255a0()
{
    static int enabledRef = FUN_00a00940("_enabled", -1);
    return (m_0c != 0 && reinterpret_cast<::FUN_00a01230_shell *>((m_0c))->IsTraitNonZero(enabledRef)) ? 1 : 0;
}
// Returns true if m_pkTile exists and its GetBool returns true for the cached s_iEnabled setting.
// @fnv 0x00726160
bool B726160Menu::FUN_00726160()
{
    static int s_iEnabled = FUN_00a00940(kListBoxEnabled, -1);
    return m_pkTile && reinterpret_cast<::FUN_00a01230_shell *>((m_pkTile))->IsTraitNonZero(s_iEnabled);
}
// @fnv 0x00730e20
bool FUN_00730e20_cls::FUN_00730e20()
{
    static void* sKey = (void*)FUN_00a00940("_enabled", -1);
    return (m_0c != 0 && reinterpret_cast<::FUN_00a01230_shell *>((m_0c))->IsTraitNonZero((int)(sKey))) ? 1 : 0;
}
// Returns true if m_pTile0c is set and its IsTraitNonZero check passes for the cached s_trait value.
// @fnv 0x00764e40
bool Cls_764e40::FUN_00764e40()
{
    static int s_trait = FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1);
    return m_pTile0c && reinterpret_cast<::FUN_00a01230_shell *>((m_pTile0c))->IsTraitNonZero(s_trait);
}

struct FUN_007a6550_shell
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a01230_shell* target;

    bool FUN_007a6550();
};

// Returns true when target is non-null and its IsTraitNonZero check passes for the cached value from FUN_00a00940(str_01070244, -1).
// @fnv 0x007a6550
bool FUN_007a6550_shell::FUN_007a6550()
{
    static int value = FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1);
    return target != 0 && target->IsTraitNonZero(value);
}

namespace fnv_007a6fa0 {
struct TileValue
{
};
struct ListNode
{
    bool FUN_008256d0();
};
struct ListOwner
{
    int ownerData;
    ListNode firstNode;
    int* FindNodeValue(unsigned int requested, unsigned char byIndex);
};
// Walks the node list by index or by matching trait 0xfac against requested, returning the node's value pointer or null.
// @fnv 0x007a6fa0
int* ListOwner::FindNodeValue(unsigned int requested, unsigned char byIndex)
{
    if (firstNode.FUN_008256d0())
        return 0;
    ListNode* node = this ? &firstNode : 0;
    if (byIndex)
    {
        unsigned int index = 0;
        while (node != 0 && index++ != requested)
            node = ((::fnv_007a6fa0::ListNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    else
    {
        while (node != 0 && reinterpret_cast<::TileListBoxCalls *>(((**((::fnv_007a6fa0::TileValue ***)(new ((void *)(node)) ::Vec3())))))->GetFloat(0xfac) != requested)
            node = ((::fnv_007a6fa0::ListNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    return node ? (int*)*((::fnv_007a6fa0::TileValue ***)(new ((void *)(node)) ::Vec3())) : 0;
}
}  // namespace fnv_007a6fa0

struct FUN_00a01230_Target
{
};

int FUN_00a00940(const char* name, int len);

struct FUN_007a7330_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a01230_Target* m_0c;

    unsigned char FUN_007a7330();
};

// Returns 1 if m_0c is non-null and its IsTraitNonZero returns true for the cached "_enabled" handle, otherwise 0.
// @fnv 0x007a7330
unsigned char FUN_007a7330_cls::FUN_007a7330()
{
    static int s_handle = FUN_00a00940("_enabled", -1);
    return (m_0c != 0 && reinterpret_cast<::FUN_00a01230_shell *>((m_0c))->IsTraitNonZero(s_handle)) ? 1 : 0;
}

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

int __cdecl FUN_00a00940(const char* s, int n);

// @fnv 0x007a81b0
bool FUN_007a81b0_cls::FUN_007a81b0()
{
    static void* sKey = (void*)FUN_00a00940("_enabled", -1);
    return (m_0c != 0 && reinterpret_cast<::FUN_00a01230_shell *>((m_0c))->IsTraitNonZero((int)(sKey))) ? 1 : 0;
}

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
// Constructor: sets the vtable, zero-initialises the fields, calls FUN_007a1950 with null and true, then AddToHeadList on this.
// @fnv 0x007d7c60
FUN_007d7c60::FUN_007d7c60()
{
    vtbl00 = &DAT_01077094;
    unk14 = 0;
    unk10 = 0;
    unk0C = 0;
    unk18 = 0;
    unk2C = 0;
    unk1C = 0;
    unk28 = 0.0f;
    unk24 = 0.0f;
    unk20 = 0.0f;
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950((unsigned int)(0), true);
    ::AddToHeadList((int *)(void *)(this));
}

struct Member_0046ffb0
{
    ~Member_0046ffb0();
};
Member_0046ffb0::~Member_0046ffb0()
{}


struct FUN_007d7d30
{
    Member_0046ffb0 m;
    void FUN_007d81f0();
    virtual ~FUN_007d7d30();
};
// @fnv 0x007d8eb0
void* FUN_007d8eb0_shell::FUN_007d8eb0(unsigned int flags)
{
    reinterpret_cast<::FUN_007d7d30 *>(this)->FUN_007d7d30::~FUN_007d7d30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Calls FUN_007d81f0 on this, then passes this to FUN_007211c0.
// @fnv 0x007d7d30
FUN_007d7d30::~FUN_007d7d30()
{
    this->FUN_007d81f0();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}


struct FUN_007d8da0_cls
{
    void FUN_007d8da0(bool bFlag);
};

// Iterates the list starting at this+4 and calls FUN_007d8d80 on each tile, skipping entries whose byte at offset 8 is set when bFlag is true.
// @fnv 0x007d8da0
void FUN_007d8da0_cls::FUN_007d8da0(bool abSkipFlagged)
{
    for (void* cur = (this != 0) ? (void*)((char*)this + 4) : 0; cur != 0 && *((void **)(new ((void *)(cur)) ::Vec3())) != 0;
         cur = reinterpret_cast<::Callees *>((cur))->FUN_00726070())
    {
        if (!abSkipFlagged || ((unsigned char*)*((void **)(new ((void *)(cur)) ::Vec3())))[8] == 0)
        {
            ((ListBox*)this)->FUN_007d8d80((Tile*)*(void**)*((void **)(new ((void *)(cur)) ::Vec3())));
        }
    }
}

int __cdecl FUN_00a00940(const char*, int);
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
    void FUN_007d9460();
};
// @fnv 0x007d9460
void HeightList::FUN_007d9460()
{
    if (container)
    {
        float count = reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0);
        int height = 1;
        if (totalHeight > 0.0 && count > 0.0)
        {
            if (totalHeight > count)
                height = FUN_00647b70((int)FUN_004e4430(reinterpret_cast<::fnv_007d9ee0::ListBox_Option *>(this)->FUN_007d9ee0() * (totalHeight - count) / totalHeight) + 1, 2);
            if (height > 1)
                reinterpret_cast<::FUN_00a012d0_t *>((((TileF*)container)))->FUN_00a012d0(FUN_00a01860(str_0106f90c), (totalHeight - count) / (height - 1), true);
        }
        if (scrollbar)
            reinterpret_cast<::Tile *>((scrollbar))->Set(FUN_00a01860(str_0106f8f8), height);
    }
}

namespace fnv_007d9660 {
int FUN_00a00940(const char*, int);
struct SelectionTile
{
    void FUN_00700320(int, int);
};
struct SelectionList
{
    bool FUN_007d9660(SelectionTile*, int);
};
// Checks the list and item, reads the item's _selected trait, and sets, clears, or toggles it based on operation, returning whether it changed.
// @fnv 0x007d9660
bool SelectionList::FUN_007d9660(SelectionTile* item, int operation)
{
    if (::fnv_007d88a0::FUN_007d88a0((void *)this) && item && reinterpret_cast<::ListOwner *>(this)->ContainsKey((int)(item)))
    {
        static int selectedTrait = ::FUN_00a00940("_selected", -1);
        bool selected = reinterpret_cast<::FUN_00a01230_shell *>((item))->IsTraitNonZero(selectedTrait);
        switch (operation)
        {
        case 0:
            if (!selected)
            {
                reinterpret_cast<::Tile *>((item))->Set(selectedTrait, true);
                return true;
            }
            break;
        case 1:
            if (selected)
            {
                reinterpret_cast<::Tile *>((item))->Set(selectedTrait, false);
                return true;
            }
            break;
        case 2:
            reinterpret_cast<::Tile *>((item))->Set(selectedTrait, !selected);
            return true;
        }
    }
    return false;
}
}  // namespace fnv_007d9660


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

// @fnv 0x007d9d50
void ListBoxScroll::FUN_007d9d50()
{
    if (m_pListTile)
    {
        float m_fGlyphExtent = reinterpret_cast<::TileListBoxCalls *>((m_pListTile))->GetFloat(0xfb0);
        int iNumItems2 = 1;
        if (m_fFirstListValue > 0.0 && m_fGlyphExtent > 0.0)
        {
            if (m_fFirstListValue > m_fGlyphExtent)
            {
                iNumItems2 = FUN_00647b70(
                    int(FUN_004e4430(reinterpret_cast<::FUN_007d8700_shell *>(this)->GetFilteredItemCount() * (m_fFirstListValue - m_fGlyphExtent) / m_fFirstListValue)) + 1,
                    2);
            }
            if (iNumItems2 > 1)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((m_pListTile))->FUN_00a012d0(FUN_00a01860("_scroll_delta"), (m_fFirstListValue - m_fGlyphExtent) / (iNumItems2 - 1), true);
            }
        }
        if (m_pHighlightedTile)
        {
            reinterpret_cast<::Tile *>((m_pHighlightedTile))->Set(FUN_00a01860("_number_of_items"), iNumItems2);
        }
    }
}

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
// @fnv 0x00851540
void RecordList::FUN_00851540()
{
    OwnedRecordList* current = head;
    while (current != 0)
    {
        delete *((::OwnedRecord **)(new ((void *)(current)) ::Vec3()));
        current = ((::OwnedRecordList *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
    }
    if (head != 0)
    {
        reinterpret_cast<::FileMatchList *>((head))->RemoveAll();
        delete head;
        head = 0;
    }
    count = 0;
}

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
    Tile* FUN_0071a320(InventoryEntry*, const char*, int, int);
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

// Clears DAT_011dace0, deletes the four owned pointers p74/p80/p7c/p78, then calls FUN_0071f8c0.
// @fnv 0x0071f700
FUN_0071f700::~FUN_0071f700()
{
    (*reinterpret_cast<int *>(&::StatsMenu::ms_pInventoryMenu)) = 0;
    delete p74;
    delete p80;
    delete p7c;
    delete p78;
    FUN_0071f8c0();
}

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
    void FUN_00724800();
    void FUN_007211e0();
};
// @fnv 0x00721150
FUN_00721150_cls::~FUN_00721150_cls()
{
    reinterpret_cast<::OwnerS *>(this)->FUN_007211e0();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}

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
// @fnv 0x007214b0
NavigationTile* NavigationList::FUN_007214b0(unsigned int action)
{
    NavigationTile* result = 0;
    int delta = 0;
    switch (action)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta = container
                    ? (int)::InventoryStackRecord::RoundToNearestStep(
                          -reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a01860(str_0106f90c)), 1.0f)
                    : 0;
        break;
    case 16:
        delta = container
                    ? (int)::InventoryStackRecord::RoundToNearestStep(
                          reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a01860(str_0106f90c)), 1.0f)
                    : 0;
        break;
    }
    if (reinterpret_cast<::Owner_00724430 *>(this)->FUN_00724430() && delta && count)
    {
        int last = count - 1;
        int current;
        int index;
        NavigationNode* node;
        if (selected)
        {
            index = (int)reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfac);
            if ((current = index + delta) < 0)
                current = 0;
            else if (current > last)
                current = last;
        }
        else
        {
            if (delta > 0)
                current = 0;
            else
                current = last;
        }
        while (true)
        {
            for (node = this; !result && node && *((::NavigationItem **)(new ((void *)(node)) ::Vec3())); node = ((::NavigationNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*((::NavigationItem **)(new ((void *)(node)) ::Vec3())))->tile))->GetFloat(0xfac) == current)
                    result = (*((::NavigationItem **)(new ((void *)(node)) ::Vec3())))->tile;
            }
            if (result && !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1)))
            {
                result = 0;
                if (delta > 0 && ++current > last)
                {
                    current = last - 1;
                    while ((!result || !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1))) && current >= 0)
                    {
                        result = GetAt(current--, false);
                    }
                    break;
                }
                else if (delta < 0 && --current < 0)
                {
                    current = 1;
                    while ((!result || !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1))) && current <= last)
                    {
                        result = GetAt(current++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return result != selected ? result : 0;
}


struct LBClearList : LBListBox
{
    void FUN_00721990();
};
// Calls FUN_00721990, then passes this to FUN_007211c0.
// @fnv 0x00721920
FUN_00721920::~FUN_00721920()
{
    reinterpret_cast<::LBClearList *>(this)->FUN_00721990();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}

// @fnv 0x00721990
void LBClearList::FUN_00721990()
{
    while (pNext && *((::LBItem **)(new ((void *)(pNext)) ::Vec3())))
    {
        LBNode* pListNode = ((::LBNode *)(reinterpret_cast<::Callees *>((pNext))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::LBItem **)(new ((void *)(pNext)) ::Vec3())))->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::LBItem **)(new ((void *)(pNext)) ::Vec3())))->extra;
        delete *((::LBItem **)(new ((void *)(pNext)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((pNext))->Initialize((::CombatController *)(0));
        delete pNext;
        pNext = pListNode;
    }

    if (pItem)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete pItem->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete pItem->extra;
        delete pItem;
    }
    pItem = 0;
    usItemCount = 0;
    m_fFirstListValue = 0.0f;
    if (m_pListTile)
        reinterpret_cast<::FUN_00a012d0_t *>((m_pListTile))->FUN_00a012d0(::FUN_00a01860("_num_filtered"), 0.0f, true);
    reinterpret_cast<::VATSMenuView *>(this)->FUN_00724dd0();
    unk10 = 0;
    reinterpret_cast<::FUN_00724930_cls *>(this)->UpdateTraitDisplay();
}


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

// Computes a target index from the action delta, scans sibling nodes for a matching enabled tile, and returns it unless it equals m_pSelected.
// @fnv 0x00721c60
Tile_721c60* Class_721c60::FUN_00721c60(int action)
{
    Tile_721c60* pTargetTile2 = 0;
    int iDelta = 0;

    switch (action)
    {
    case 2:
        iDelta = 1;
        break;
    case 1:
        iDelta = -1;
        break;
    case 15:
        iDelta = m_pScrollBar ? (int)::InventoryStackRecord::RoundToNearestStep(-reinterpret_cast<::TileListBoxCalls *>((m_pScrollBar))->GetFloat(0xfb0) /
                                                      reinterpret_cast<::TileListBoxCalls *>((m_pScrollBar))->GetFloat(FUN_00a01860(str_0106f90c)),
                                                  1.0f)
                              : 0;
        break;
    case 16:
        iDelta = m_pScrollBar ? (int)::InventoryStackRecord::RoundToNearestStep(reinterpret_cast<::TileListBoxCalls *>((m_pScrollBar))->GetFloat(0xfb0) /
                                                      reinterpret_cast<::TileListBoxCalls *>((m_pScrollBar))->GetFloat(FUN_00a01860(str_0106f90c)),
                                                  1.0f)
                              : 0;
        break;
    }

    if (IsScrollBarTraitEnabled() && iDelta != 0 && m_usItemCount != 0)
    {
        int iIndex;
        int iMaxIndex2 = m_usItemCount - 1;
        int iCurIndex5;
        Node_721c60* pIter;

        if (m_pSelected)
        {
            iCurIndex5 = (int)reinterpret_cast<::TileListBoxCalls *>((m_pSelected))->GetFloat(0xfac);
            if ((iIndex = iCurIndex5 + iDelta) < 0)
            {
                iIndex = 0;
            }
            else if (iIndex > iMaxIndex2)
            {
                iIndex = iMaxIndex2;
            }
        }
        else if (iDelta > 0)
        {
            iIndex = 0;
        }
        else
        {
            iIndex = iMaxIndex2;
        }

        while (true)
        {
            for (pIter = this; !pTargetTile2 && pIter && *((::Item_721c60 **)(new ((void *)(pIter)) ::Vec3())); pIter = ((::Node_721c60 *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*((::Item_721c60 **)(new ((void *)(pIter)) ::Vec3())))->tile))->GetFloat(0xfac) == iIndex)
                {
                    pTargetTile2 = (*((::Item_721c60 **)(new ((void *)(pIter)) ::Vec3())))->tile;
                }
            }

            if (pTargetTile2 && !reinterpret_cast<::FUN_00a01230_shell *>((pTargetTile2))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1)))
            {
                pTargetTile2 = 0;
                if (iDelta > 0 && ++iIndex > iMaxIndex2)
                {
                    iIndex = iMaxIndex2 - 1;
                    while ((!pTargetTile2 || !reinterpret_cast<::FUN_00a01230_shell *>((pTargetTile2))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1))) &&
                           iIndex >= 0)
                    {
                        pTargetTile2 = VFunc14(iIndex--, false);
                    }
                    break;
                }
                else if (iDelta < 0 && --iIndex < 0)
                {
                    iIndex = 1;
                    while ((!pTargetTile2 || !reinterpret_cast<::FUN_00a01230_shell *>((pTargetTile2))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1))) &&
                           iIndex <= iMaxIndex2)
                    {
                        pTargetTile2 = VFunc14(iIndex++, false);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    return pTargetTile2 != m_pSelected ? pTargetTile2 : 0;
}

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

// @fnv 0x00722000
FUN_00722000::FUN_00722000()
{
    vptr = &DAT_01070314;
    m_pHighlightedTile = 0;
    m_pSelectedTile = 0;
    m_pListTile = 0;
    pTemplateName = 0;
    usFlags = 0;
    m_usSelectedIndex = 0;
    m_fThirdListValue = 0.0f;
    m_fSecondListValue = 0.0f;
    m_fFirstListValue = 0.0f;
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950(0, 1);
    ::AddToHeadList((int *)(void *)(this));
}

struct ListBox_007228f0 : LBListBox
{
    void FUN_007228f0();
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
// Calls FUN_007230e0 then FUN_007211c0 on this object during destruction.
// @fnv 0x00723070
FUN_00723070::~FUN_00723070()
{
    reinterpret_cast<::ListBoxClear *>(this)->FUN_007230e0();
    ::fnv_007211c0::FUN_007211c0((int *)(::FUN_00723070 *)(this));
}

// @fnv 0x007230e0
void ListBoxClear::FUN_007230e0()
{
    while (pNext && *((::LBItem **)(new ((void *)(pNext)) ::Vec3())))
    {
        LBNode* next = ((::LBNode *)(reinterpret_cast<::Callees *>((pNext))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::LBItem **)(new ((void *)(pNext)) ::Vec3())))->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::LBItem **)(new ((void *)(pNext)) ::Vec3())))->extra;
        delete *((::LBItem **)(new ((void *)(pNext)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((pNext))->Initialize((::CombatController *)(0));
        delete pNext;
        pNext = next;
    }
    if (pItem)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete pItem->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete pItem->extra;
        delete pItem;
    }
    pItem = 0;
    usItemCount = 0;
    m_fFirstListValue = 0.0f;
    if (m_pListTile)
        reinterpret_cast<::FUN_00a012d0_t *>((m_pListTile))->FUN_00a012d0(FUN_00a01860("_num_filtered"), 0.0f, true);
    reinterpret_cast<::FUN_00725f40_shell *>(this)->FUN_00725f40();
    m_pSelectedTile = 0;
    reinterpret_cast<::FUN_00725c20_shell *>(this)->UpdateHighlightTiles();
}


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

// @fnv 0x00723b60
TileHeight* ListBoxHelper::FUN_00723b60(int code)
{
    TileHeight* delta3 = 0;
    int found = 0;
    int aIdx2;
    int count3;
    int base2;
    ListNode* node;

    switch (code)
    {
    case 2:
        found = 1;
        break;
    case 1:
        found = -1;
        break;
    case 15:
        found = m_0c != 0 ? (int)::InventoryStackRecord::RoundToNearestStep((float)((double)-reinterpret_cast<::TileListBoxCalls *>((m_0c))->GetFloat(0xfb0) /
                                                      reinterpret_cast<::TileListBoxCalls *>((m_0c))->GetFloat(FUN_00a01860(str_0106f90c))),
                                              1.0f)
                          : 0;
        break;
    case 16:
        found =
            m_0c != 0
                ? (int)::InventoryStackRecord::RoundToNearestStep(
                      (float)((double)reinterpret_cast<::TileListBoxCalls *>((m_0c))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((m_0c))->GetFloat(FUN_00a01860(str_0106f90c))), 1.0f)
                : 0;
        break;
    }

    if (reinterpret_cast<::B726160Menu *>(this)->FUN_00726160() && found != 0 && m_1c != 0)
    {
        count3 = m_1c - 1;
        if (m_10 != 0)
        {
            base2 = (int)reinterpret_cast<::TileListBoxCalls *>((m_10))->GetFloat(0xfac);
            aIdx2 = base2 + found;
            if (aIdx2 < 0)
            {
                aIdx2 = 0;
            }
            else if (aIdx2 > count3)
            {
                aIdx2 = count3;
            }
        }
        else
        {
            if (found > 0)
                aIdx2 = 0;
            else
                aIdx2 = count3;
        }

        while (1)
        {
            node = this != 0 ? &head : 0;
            for (; delta3 == 0 && node != 0 && *((::Entry **)(new ((void *)(node)) ::Vec3())) != 0; node = ((::ListNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*(TileHeight**)(*((::Entry **)(new ((void *)(node)) ::Vec3()))))))->GetFloat(0xfac) == (float)aIdx2)
                {
                    delta3 = *(TileHeight**)(*((::Entry **)(new ((void *)(node)) ::Vec3())));
                }
            }

            if (delta3 != 0 && !reinterpret_cast<::FUN_00a01230_shell *>((((FUN_00a01230_cls*)delta3)))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1)))
            {
                delta3 = 0;
                if (found > 0 && ++aIdx2 > count3)
                {
                    aIdx2 = count3 - 1;
                    while (
                        (delta3 == 0 || !reinterpret_cast<::FUN_00a01230_shell *>((((FUN_00a01230_cls*)delta3)))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1))) &&
                        aIdx2 >= 0)
                    {
                        delta3 = GetItemAt(aIdx2--, 0);
                    }
                    break;
                }
                else if (found < 0 && --aIdx2 < 0)
                {
                    aIdx2 = 1;
                    while (
                        (delta3 == 0 || !reinterpret_cast<::FUN_00a01230_shell *>((((FUN_00a01230_cls*)delta3)))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1))) &&
                        aIdx2 <= count3)
                    {
                        delta3 = GetItemAt(aIdx2++, 0);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    return (delta3 != m_10) ? delta3 : 0;
}

int __cdecl FUN_00a00940(const char*, int);
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
public:
    void UpdateHighlight_007a8260();
};
namespace fnv_00724800 {

struct LBTile
{
};

struct ListBoxScroll
{
    void* vtable;
    void* pListItem;
    void* pListNext;
    LBTile* m_pListTile;
    LBTile* pSelected;
    LBTile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;
    void FUN_00724800();
};

// @fnv 0x00724800
void ListBoxScroll::FUN_00724800()
{
    if (m_pListTile)
    {
        int iNumItems2;
        float m_fGlyphExtent = reinterpret_cast<::TileListBoxCalls *>((m_pListTile))->GetFloat(0xfb0);
        iNumItems2 = 1;
        if (m_fFirstListValue > 0.0 && m_fGlyphExtent > 0.0)
        {
            if (m_fFirstListValue > m_fGlyphExtent)
            {
                iNumItems2 = ::FUN_00647b70(
                    (int)::FUN_004e4430((float)reinterpret_cast<::VATSMenu *>(this)->Create() * (m_fFirstListValue - m_fGlyphExtent) / m_fFirstListValue) + 1,
                    2);
            }
            if (iNumItems2 > 1)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((m_pListTile))->FUN_00a012d0(::FUN_00a01860("_scroll_delta"), (m_fFirstListValue - m_fGlyphExtent) / (iNumItems2 - 1), true);
            }
        }
        if (m_pHighlightedTile)
        {
            reinterpret_cast<::Tile *>((m_pHighlightedTile))->Set(::FUN_00a01860("_number_of_items"), iNumItems2);
        }
    }
}
}  // namespace fnv_00724800

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
    void UpdateScroll();
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
// @fnv 0x007223a0
bool ListBox_7223a0::FUN_007223a0(Tile_7223a0* apTile)
{
    if (reinterpret_cast<::C4FD0ListBox *>(this)->FUN_00724fd0() && (!apTile || (reinterpret_cast<::ListOwner *>(this)->ContainsKey((int)(apTile)) && reinterpret_cast<::FUN_00a01230_shell *>((apTile))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1)))))
    {
        m_pSelected = apTile;
        FUN_00725080();
        return true;
    }
    else
    {
        return false;
    }
}

// Returns true if m_pkTile exists and its _enabled trait value is set, using a cached trait ID.
// @fnv 0x00724fd0
bool C4FD0ListBox::FUN_00724fd0()
{
    static int s_iEnabledTrait = ::FUN_00a00940("_enabled", -1);
    return m_pkTile && reinterpret_cast<::FUN_00a01230_shell *>((m_pkTile))->IsTraitNonZero(s_iEnabledTrait);
}
class AGListItem
{
  public:
    virtual ~AGListItem();
    int m_iIndex;
    AGListItem* m_pNext;
    AGListItem() : m_iIndex(2000), m_pNext(0)
    {}
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
public:
    void *FUN_004bcd10();
};

namespace fnv_00725080 {
struct HighlightValue
{
};
struct HighlightTile
{
    HighlightValue* FUN_00a00f30(int);
    void FUN_00a07530(int);
    void FUN_00700320(int, int);
};
struct HighlightList
{
    int unk00;
    int unk04;
    int unk08;
    HighlightTile* container;
    HighlightTile* selected;
    void FUN_00725080();
};
// Updates the highlight and height values on the container's selected tile and toggles the child box elements based on the selected tile's state.
// @fnv 0x00725080
void HighlightList::FUN_00725080()
{
    static int highlight = FUN_00a00940(str_0106f8c0, -1);
    static int height = FUN_00a00940(str_0106f8ac, -1);
    if (container)
    {
        if (selected)
        {
            HighlightValue* pHighlightValue = container->FUN_00a00f30(highlight);
            HighlightValue* value = container->FUN_00a00f30(height);
            reinterpret_cast<::AGOwner *>((pHighlightValue))->FUN_00a09130(2000, (Tile*)selected, 4002);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pHighlightValue))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((value))->FUN_00a09130(2000, (Tile*)selected, 4016);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((value))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((selected))->GetSpeechChallengeFailure())
            {
                HighlightTile* box = ((::fnv_00725080::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(container), str_0106f898)));
                if (box)
                {
                    HighlightTile* child = ((::fnv_00725080::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)(str_0106f894))));
                    if (child)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        child->FUN_00a07530(8);
                        child = ((::fnv_00725080::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)(str_0106f88c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        child->FUN_00a07530(8);
                        child = ((::fnv_00725080::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)(str_0106f884))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        child->FUN_00a07530(8);
                        child = ((::fnv_00725080::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)(str_0106f87c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        child->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((box))->FUN_0071aa60(true);
                    box->FUN_00a07530(8);
                }
            }
            else
            {
                HighlightTile* box = ((::fnv_00725080::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(container), str_0106f898)));
                if (box)
                {
                    HighlightTile* child = ((::fnv_00725080::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)(str_0106f894))));
                    if (child)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        child->FUN_00a07530(8);
                        child = ((::fnv_00725080::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)(str_0106f88c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        child->FUN_00a07530(8);
                        child = ((::fnv_00725080::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)(str_0106f884))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        child->FUN_00a07530(8);
                        child = ((::fnv_00725080::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)(str_0106f87c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        child->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((box))->FUN_0071aa60(false);
                    box->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((container))->Set(highlight, -1);
            reinterpret_cast<::Tile *>((container))->Set(height, 0);
        }
    }
}
}  // namespace fnv_00725080

struct FUN_00a00f30_shell
{
    void* FUN_00a00f30(int);
};
struct FUN_00a07530_shell
{
    void FUN_00a07530(int);
};
// @fnv 0x00725c20
void FUN_00725c20_shell::UpdateHighlightTiles()
{
    static int highlightY = ::FUN_00a00940(str_0106f8c0, -1);
    static int selectedHeight = ::FUN_00a00940(str_0106f8ac, -1);

    TileValue* pHighlightY;
    TileValue* pSelectedHeight;

    if (highlightTile != 0)
    {
        if (selectedTile != 0)
        {
            pHighlightY = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)highlightTile)))->FUN_00a00f30(highlightY)));
            pSelectedHeight = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)highlightTile)))->FUN_00a00f30(selectedHeight)));

            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)pHighlightY)))->FUN_00a09130(0x7d0, selectedTile, 0xfa2);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)pHighlightY)))->FUN_00a09410(0);

            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)pSelectedHeight)))->FUN_00a09130(0x7d0, selectedTile, 0xfb0);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)pSelectedHeight)))->FUN_00a09410(0);

            if (reinterpret_cast<::Tile *>((((Tile_GetSpeechChallengeFailure_helper*)selectedTile)))->GetSpeechChallengeFailure())
            {
                Tile* pHighlightBox = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(highlightTile), str_0106f898)));
                if (pHighlightBox != 0)
                {
                    Tile* pChild = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)pHighlightBox)))->FUN_00a03da0((char *)(str_0106f894));
                    if (pChild != 0)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)pChild)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)pChild)))->FUN_00a07530(8);

                        pChild = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)pHighlightBox)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)pChild)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)pChild)))->FUN_00a07530(8);

                        pChild = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)pHighlightBox)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)pChild)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)pChild)))->FUN_00a07530(8);

                        pChild = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)pHighlightBox)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)pChild)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)pChild)))->FUN_00a07530(8);
                    }

                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)pHighlightBox)))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)pHighlightBox)))->FUN_00a07530(8);
                }
            }
            else
            {
                Tile* pHighlightBox = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(highlightTile), str_0106f898)));
                if (pHighlightBox != 0)
                {
                    Tile* pChild = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)pHighlightBox)))->FUN_00a03da0((char *)(str_0106f894));
                    if (pChild != 0)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)pChild)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)pChild)))->FUN_00a07530(8);

                        pChild = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)pHighlightBox)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)pChild)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)pChild)))->FUN_00a07530(8);

                        pChild = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)pHighlightBox)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)pChild)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)pChild)))->FUN_00a07530(8);

                        pChild = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)pHighlightBox)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)pChild)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)pChild)))->FUN_00a07530(8);
                    }

                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)pHighlightBox)))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)pHighlightBox)))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)highlightTile)))->Set(highlightY, -1);
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)highlightTile)))->Set(selectedHeight, 0);
        }
    }
}
// @fnv 0x00721440
bool FUN_00721440_class::SelectObject(SelectedObject* object)
{
    if (reinterpret_cast<::Owner_00724430 *>(this)->FUN_00724430() && (!object || (reinterpret_cast<::ListOwner *>(this)->ContainsKey((int)(object)) && reinterpret_cast<::FUN_00a01230_shell *>((object))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1)))))
    {
        selected = object;
        reinterpret_cast<::HighlightList *>(this)->FUN_007244e0();
        return true;
    }
    else
    {
        return false;
    }
}
// @fnv 0x007211e0
void OwnerS::FUN_007211e0()
{
    while (pHead != 0 && *((::ItemS **)(new ((void *)(pHead)) ::Vec3())) != 0)
    {
        NodeS* nextNode;
        NodeS* tile;
        ItemS* tileObj;
        ExtraObj* zArg;
        ExtraObj* pTile;
        TileObjV* itemPtr;
        TileObjV* curNode;
        NodeS* deadNode = ((::NodeS *)(reinterpret_cast<::Callees *>((pHead))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
        {
            itemPtr = (*((::ItemS **)(new ((void *)(pHead)) ::Vec3())))->curNode;
            curNode = itemPtr;
            curNode ? curNode->Del(1) : 0;
        }
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
        {
            zArg = (*((::ItemS **)(new ((void *)(pHead)) ::Vec3())))->extra;
            pTile = zArg;
            pTile ? pTile->FUN_004459e0(1) : 0;
        }
        tileObj = *((::ItemS **)(new ((void *)(pHead)) ::Vec3()));
        ::FUN_00401030(tileObj);
        reinterpret_cast<::CombatProcedure *>((pHead))->Initialize((::CombatController *)(0));
        nextNode = pHead;
        tile = nextNode;
        tile ? ((void *)(reinterpret_cast<::W004702f0 *>((tile))->FUN_004702f0(1))) : 0;
        pHead = deadNode;
    }
    if (pSingle != 0)
    {
        ItemS* secondTile;
        ExtraObj* nxt;
        ExtraObj* extraB;
        TileObjV* tileTmpPtr;
        TileObjV* singleItem;
        if (!::fnv_007a2070::s_bAllowDetach)
        {
            tileTmpPtr = pSingle->curNode;
            singleItem = tileTmpPtr;
            singleItem ? singleItem->Del(1) : 0;
        }
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
        {
            nxt = pSingle->extra;
            extraB = nxt;
            extraB ? extraB->FUN_004459e0(1) : 0;
        }
        secondTile = pSingle;
        ::FUN_00401030(secondTile);
    }
    pSingle = 0;
    m_usPassCountLocal = 0;
    m_fGlyphExtent = 0.0f;
    if (pTile != 0)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(FUN_00a01860("_num_filtered"), 0.0f, true);
    }
    FUN_00724800();
    m10 = 0;
    reinterpret_cast<::HighlightList *>(this)->FUN_007244e0();
}
// @fnv 0x007244e0
void HighlightList::FUN_007244e0()
{
    static int index = FUN_00a00940(str_0106f8c0, -1);
    static int value = FUN_00a00940(str_0106f8ac, -1);
    if (container)
    {
        if (selected)
        {
            HighlightValue* indexValue4 = ((::HighlightValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((container))->FUN_00a00f30(index)));
            HighlightValue* selectedValue6 = ((::HighlightValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((container))->FUN_00a00f30(value)));
            reinterpret_cast<::AGOwner *>((indexValue4))->FUN_00a09130(2000, (::Tile *)(selected), 4002);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((indexValue4))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((selectedValue6))->FUN_00a09130(2000, (::Tile *)(selected), 4016);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((selectedValue6))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((selected))->GetSpeechChallengeFailure())
            {
                HighlightTile* failureBox7 = ((::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(container), str_0106f898)));
                if (failureBox7)
                {
                    HighlightTile* failureChild3 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((failureBox7))->FUN_00a03da0((char *)(str_0106f894))));
                    if (failureChild3)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((failureChild3))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((failureChild3))->FUN_00a07530(8);
                        failureChild3 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((failureBox7))->FUN_00a03da0((char *)(str_0106f88c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((failureChild3))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((failureChild3))->FUN_00a07530(8);
                        failureChild3 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((failureBox7))->FUN_00a03da0((char *)(str_0106f884))));
                        reinterpret_cast<::FUN_0071aa60_class *>((failureChild3))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((failureChild3))->FUN_00a07530(8);
                        failureChild3 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((failureBox7))->FUN_00a03da0((char *)(str_0106f87c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((failureChild3))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((failureChild3))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((failureBox7))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((failureBox7))->FUN_00a07530(8);
                }
            }
            else
            {
                HighlightTile* normalBox = ((::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(container), str_0106f898)));
                if (normalBox)
                {
                    HighlightTile* normalChild4 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((normalBox))->FUN_00a03da0((char *)(str_0106f894))));
                    if (normalChild4)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((normalChild4))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((normalChild4))->FUN_00a07530(8);
                        normalChild4 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((normalBox))->FUN_00a03da0((char *)(str_0106f88c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((normalChild4))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((normalChild4))->FUN_00a07530(8);
                        normalChild4 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((normalBox))->FUN_00a03da0((char *)(str_0106f884))));
                        reinterpret_cast<::FUN_0071aa60_class *>((normalChild4))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((normalChild4))->FUN_00a07530(8);
                        normalChild4 = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((normalBox))->FUN_00a03da0((char *)(str_0106f87c))));
                        reinterpret_cast<::FUN_0071aa60_class *>((normalChild4))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((normalChild4))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((normalBox))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((normalBox))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((container))->Set(index, -1);
            reinterpret_cast<::Tile *>((container))->Set(value, 0);
        }
    }
}
// Sets the selected and index trait tile values, then shows or hides the speech-challenge failure child tiles based on GetSpeechChallengeFailure.
// @fnv 0x00724ab0
void FUN_00724930_cls::UpdateTraitDisplay()
{
    static int selectedTrait = ::FUN_00a00940(str_0106f8c0, -1);
    static int indexTrait = ::FUN_00a00940(str_0106f8ac, -1);
    if (unk0c)
    {
        if (unk10)
        {
            TileValue* selectedValue = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)unk0c)))->FUN_00a00f30(selectedTrait)));
            TileValue* sVertexIndex = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)unk0c)))->FUN_00a00f30(indexTrait)));
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)selectedValue)))->FUN_00a09130(2000, (Tile*)unk10, 4002);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)selectedValue)))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)sVertexIndex)))->FUN_00a09130(2000, (Tile*)unk10, 4016);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)sVertexIndex)))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((((Tile_GetSpeechChallengeFailure_helper*)unk10)))->GetSpeechChallengeFailure())
            {
                Tile* parent = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)((Tile*)unk0c), str_0106f898)));
                if (parent)
                {
                    Tile* child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child)))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)parent)))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)parent)))->FUN_00a07530(8);
                }
            }
            else
            {
                Tile* parent = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)((Tile*)unk0c), str_0106f898)));
                if (parent)
                {
                    Tile* child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child)))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)parent)))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)parent)))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)unk0c)))->Set(selectedTrait, -1);
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)unk0c)))->Set(indexTrait, 0);
        }
    }
}
struct FUN_007254d0_t
{
    int unk00;
    int unk04;
    int unk08;
    Tile* container;
    Tile* selected;
    void UpdateSpeechChallengeTrait();
};
// @fnv 0x007228f0
void ListBox_007228f0::FUN_007228f0()
{
    while (this->pNext != 0 && *((::LBItem **)(new ((void *)(this->pNext)) ::Vec3())) != 0)
    {
        LBNode* pNext = ((::LBNode *)(reinterpret_cast<::Callees *>((this->pNext))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
        {
            delete (*((::LBItem **)(new ((void *)(this->pNext)) ::Vec3())))->tile;
        }
        if (reinterpret_cast<::FUN_007242c0_shell *>((this))->FUN_007242c0(1))
        {
            delete (*((::LBItem **)(new ((void *)(this->pNext)) ::Vec3())))->extra;
        }
        delete *((::LBItem **)(new ((void *)(this->pNext)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((this->pNext))->Initialize((::CombatController *)(0));
        delete this->pNext;
        this->pNext = pNext;
    }
    if (this->pItem != 0)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
        {
            delete this->pItem->tile;
        }
        if (reinterpret_cast<::FUN_007242c0_shell *>((this))->FUN_007242c0(1))
        {
            delete this->pItem->extra;
        }
        delete this->pItem;
    }
    this->pItem = 0;
    this->usItemCount = 0;
    this->m_fFirstListValue = 0.0f;
    if (this->m_pListTile != 0)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((this->m_pListTile))->FUN_00a012d0(FUN_00a01860("_num_filtered"), 0.0f, true);
    }
    reinterpret_cast<::S725970 *>((this))->FUN_00725970();
    this->unk10 = 0;
    reinterpret_cast<::FUN_007254d0_t *>((this))->UpdateSpeechChallengeTrait();
}
// @fnv 0x00725650
void FUN_007254d0_t::UpdateSpeechChallengeTrait()
{
    static int selectedTrait = FUN_00a00940(str_0106f8c0, -1);
    static int failedTrait = FUN_00a00940(str_0106f8ac, -1);
    if (container)
    {
        if (selected)
        {
            void* selectedValue = ((FUN_00a00f30_shell*)container)->FUN_00a00f30(selectedTrait);
            void* pFailedTraitValue = ((FUN_00a00f30_shell*)container)->FUN_00a00f30(failedTrait);
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)selectedValue)))->FUN_00a09130(0x7d0, selected, 0xfa2);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)selectedValue)))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)pFailedTraitValue)))->FUN_00a09130(0x7d0, selected, 0xfb0);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)pFailedTraitValue)))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((((Tile_GetSpeechChallengeFailure_helper*)selected)))->GetSpeechChallengeFailure())
            {
                Tile* parent = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(container), str_0106f898)));
                if (parent)
                {
                    Tile* child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        ((FUN_00a07530_shell*)child)->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        ((FUN_00a07530_shell*)child)->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        ((FUN_00a07530_shell*)child)->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        ((FUN_00a07530_shell*)child)->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)parent)))->FUN_0071aa60(true);
                    ((FUN_00a07530_shell*)parent)->FUN_00a07530(8);
                }
            }
            else
            {
                Tile* parent = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(container), str_0106f898)));
                if (parent)
                {
                    Tile* child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        ((FUN_00a07530_shell*)child)->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        ((FUN_00a07530_shell*)child)->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        ((FUN_00a07530_shell*)child)->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)parent)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        ((FUN_00a07530_shell*)child)->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)parent)))->FUN_0071aa60(false);
                    ((FUN_00a07530_shell*)parent)->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((((Tile_Set_Helper*)container)))->Set(selectedTrait, -1);
            reinterpret_cast<::Tile *>((((Tile_Set_Helper*)container)))->Set(failedTrait, 0);
        }
    }
}

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
// Maps a navigation key to a scroll delta, finds the matching enabled tile by index, and returns it unless it is already selected.
// @fnv 0x007233b0
LBKTile* LBKListBox::GetTileByKey(int aiKey)
{
    LBKTile* pTile = 0;
    int iDelta_ = 0;

    switch (aiKey)
    {
    case 2:
        iDelta_ = 1;
        break;
    case 1:
        iDelta_ = -1;
        break;
    case 15:
        iDelta_ = pParentTile
                      ? (int)::InventoryStackRecord::RoundToNearestStep(
                            -reinterpret_cast<::TileListBoxCalls *>((pParentTile))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((pParentTile))->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                      : 0;
        break;
    case 16:
        iDelta_ = pParentTile
                      ? (int)::InventoryStackRecord::RoundToNearestStep(
                            reinterpret_cast<::TileListBoxCalls *>((pParentTile))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((pParentTile))->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                      : 0;
        break;
    }

    if (reinterpret_cast<::FUN_00725b70_cls *>(this)->FUN_00725b70() && iDelta_ && usItemCount)
    {
        int iLast7 = usItemCount - 1;
        int kINew;
        if (pSelected)
        {
            int iCurrent = (int)reinterpret_cast<::TileListBoxCalls *>((pSelected))->GetFloat(0xfac);
            if ((kINew = iCurrent + iDelta_) < 0)
                kINew = 0;
            else if (kINew > iLast7)
                kINew = iLast7;
        }
        else
        {
            if (iDelta_ > 0)
                kINew = 0;
            else
                kINew = iLast7;
        }

        while (1)
        {
            for (LBKNode* pIter = this; !pTile && pIter && *((::LBKItem **)(new ((void *)(pIter)) ::Vec3())); pIter = ((::LBKNode *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*((::LBKItem **)(new ((void *)(pIter)) ::Vec3())))->pTile))->GetFloat(0xfac) == kINew)
                    pTile = (*((::LBKItem **)(new ((void *)(pIter)) ::Vec3())))->pTile;
            }
            if (pTile && !reinterpret_cast<::FUN_00a01230_shell *>((pTile))->IsTraitNonZero(FUN_00a00940("_enabled", -1)))
            {
                pTile = 0;
                if (iDelta_ > 0 && ++kINew > iLast7)
                {
                    kINew = iLast7 - 1;
                    while ((!pTile || !reinterpret_cast<::FUN_00a01230_shell *>((pTile))->IsTraitNonZero(FUN_00a00940("_enabled", -1))) && kINew >= 0)
                        pTile = GetTileByIndex(kINew--, 0);
                    break;
                }
                else if (iDelta_ < 0 && --kINew < 0)
                {
                    kINew = 1;
                    while ((!pTile || !reinterpret_cast<::FUN_00a01230_shell *>((pTile))->IsTraitNonZero(FUN_00a00940("_enabled", -1))) && kINew <= iLast7)
                        pTile = GetTileByIndex(kINew++, 0);
                    break;
                }
            }
            else
                break;
        }
    }
    return pTile != pSelected ? pTile : 0;
}

int __cdecl FUN_00a00940(const char* s, int n);

// Returns true when m_0c is non-null and its IsTraitNonZero lookup of the static "_enabled" key succeeds.
// @fnv 0x00725b70
bool FUN_00725b70_cls::FUN_00725b70()
{
    static void* sKey = (void*)FUN_00a00940("_enabled", -1);
    return (m_0c != 0 && reinterpret_cast<::FUN_00a01230_shell *>((m_0c))->IsTraitNonZero((int)(sKey))) ? 1 : 0;
}

namespace fnv_00726210 {
struct FUN_00a07530_shell
{
};

struct ListBox726210
{
    int unk00;
    int unk04;
    int unk08;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    void FUN_00726210();
};

// @fnv 0x00726210
void ListBox726210::FUN_00726210()
{
    static int traitHighlightY = ::FUN_00a00940(str_0106f8c0, -1);
    static int traitSelectedHeight = ::FUN_00a00940(str_0106f8ac, -1);
    if (m_pListTile != 0)
    {
        if (m_pSelectedTile != 0)
        {
            TileValue* valHighlightY = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)m_pListTile)))->FUN_00a00f30(traitHighlightY)));
            TileValue* valSelectedHeight = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)m_pListTile)))->FUN_00a00f30(traitSelectedHeight)));
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)valHighlightY)))->FUN_00a09130(2000, m_pSelectedTile, 4002);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)valHighlightY)))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)valSelectedHeight)))->FUN_00a09130(2000, m_pSelectedTile, 4016);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)valSelectedHeight)))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((((Tile_GetSpeechChallengeFailure_helper*)m_pSelectedTile)))->GetSpeechChallengeFailure())
            {
                Tile* box = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(m_pListTile), str_0106f898)));
                if (box != 0)
                {
                    Tile* child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child != 0)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((FUN_00a07530_shell*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((FUN_00a07530_shell*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((FUN_00a07530_shell*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((FUN_00a07530_shell*)child)))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)box)))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((((FUN_00a07530_shell*)box)))->FUN_00a07530(8);
                }
            }
            else
            {
                Tile* box = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(m_pListTile), str_0106f898)));
                if (box != 0)
                {
                    Tile* child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child != 0)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((FUN_00a07530_shell*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((FUN_00a07530_shell*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((FUN_00a07530_shell*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((FUN_00a07530_shell*)child)))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)box)))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((((FUN_00a07530_shell*)box)))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)m_pListTile)))->Set(traitHighlightY, -1);
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)m_pListTile)))->Set(traitSelectedHeight, 0);
        }
    }
}
}  // namespace fnv_00726210

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
    VLPoint3 GetStringDimensions(const char* apText, int aiFont, float afWrapWidth, int aiFlags);
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
// @fnv 0x00724360
void FUN_00724360_cls::FUN_00724360()
{
    FUN_00724360_Item* cur;

    m_1c = 0;
    m_20 = 0.0f;
    for (cur = (FUN_00724360_Item*)((this != 0) ? (char*)&this->unk04 : 0); cur != 0 && *((int **)(new ((void *)(cur)) ::Vec3())) != 0;
         cur = (FUN_00724360_Item*)reinterpret_cast<::Callees *>((cur))->FUN_00726070())
    {
        if (((unsigned char*)*((int **)(new ((void *)(cur)) ::Vec3())))[8] == 0)
        {
            reinterpret_cast<::Tile *>((((FUN_00724360_Obj*)**((int **)(new ((void *)(cur)) ::Vec3())))))->Set(0xfac, (unsigned int)m_1c++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(**((int **)(new ((void *)(cur)) ::Vec3()))));
        }
    }
    FUN_00724800();
    reinterpret_cast<::HighlightList *>(this)->FUN_007244e0();
}
// @fnv 0x00724930
void FUN_00724930_cls::FUN_00724930()
{
    m_1c = 0;
    m_20 = 0.0f;
    Node00724930* cur;
    for (cur = this != 0 ? (Node00724930*)&this->unk04 : 0; cur != 0 && *((::Item00724930 **)(new ((void *)(cur)) ::Vec3())) != 0;
         cur = ((::Node00724930 *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070())))
    {
        if ((*((::Item00724930 **)(new ((void *)(cur)) ::Vec3())))->flag08 == 0)
        {
            reinterpret_cast<::Tile *>(((*((::Item00724930 **)(new ((void *)(cur)) ::Vec3())))->unk00))->Set(0xfac, m_1c++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)((*((::Item00724930 **)(new ((void *)(cur)) ::Vec3())))->unk00));
        }
    }
    reinterpret_cast<::VATSMenuView *>(this)->FUN_00724dd0();
    UpdateTraitDisplay();
}
// Resets the count and scroll, assigns sequential indices to visible item tiles, adds them, then sorts tiles and updates the scroll.
// @fnv 0x00724f00
void ListBox724::RefreshTiles()
{
    m_usElementCount = 0;
    m_fScroll = 0.0f;
    for (ItemList724* pkNode = this; pkNode && *((::Item724 **)(new ((void *)(pkNode)) ::Vec3())); pkNode = ((::ItemList724 *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070())))
    {
        if (!(*((::Item724 **)(new ((void *)(pkNode)) ::Vec3())))->m_bHidden)
        {
            reinterpret_cast<::Tile *>(((*((::Item724 **)(new ((void *)(pkNode)) ::Vec3())))->m_pkTile))->Set(0xfac, m_usElementCount++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)((*((::Item724 **)(new ((void *)(pkNode)) ::Vec3())))->m_pkTile));
        }
    }
    reinterpret_cast<::OwnerProxy *>(this)->FUN_007253a0();
    UpdateScroll();
}

// Sets the tile's _y to fTotalHeight, measures the child text tile's height if unset, stores it in trait 0xfb0 and adds it to fTotalHeight.
// @fnv 0x007269d0
void VLList::AccumulateTileHeight(VLTile* apTile)
{
    float fHeight4 = 0.0f;
    reinterpret_cast<::FUN_00a012d0_t *>((apTile))->FUN_00a012d0(::FUN_00a00940("_y", -1), fTotalHeight, true);
    fHeight4 = reinterpret_cast<::TileListBoxCalls *>((apTile))->GetFloat(0xfb0);
    if (fHeight4 == 0.0)
    {
        VLTile* pText = 0;
        VLListNode* pPosVal = ((::VLListNode *)(reinterpret_cast<::Callees *>(&(apTile->kChildren))->FUN_00726070()));
        while (pPosVal && !pText)
        {
            VLTile* pChild2 = apTile->kChildren.GetNext(pPosVal);
            if (pChild2->GetType() == 0x387)
                pText = pChild2;
        }
        if (pText)
        {
            float fWrapWidth = reinterpret_cast<::TileListBoxCalls *>((pText))->GetFloat(0xfba);
            fHeight4 = ((::VLFontManager *)(::FontManager::Instance()))
                           ->GetStringDimensions(reinterpret_cast<::FUN_00a011f0_shell *>((pText))->FUN_00a011f0(0xfc4), (int)reinterpret_cast<::TileListBoxCalls *>((pText))->GetFloat(0xfb9),
                                                 (fWrapWidth > 0.0) ? fWrapWidth : 3.402823466e+38F, 0)
                           .y;
            fHeight4 += reinterpret_cast<::TileListBoxCalls *>((apTile))->GetFloat(::FUN_00a01860("_VerticalSpacing"));
        }
    }
    reinterpret_cast<::FUN_00a012d0_t *>((apTile))->FUN_00a012d0(0xfb0, fHeight4, false);
    fTotalHeight += fHeight4;
}

struct Tile050;
struct Value050
{
};
struct Menu050
{
};
struct Tile050
{
    void FUN_00700320(int, int);
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
extern "C" char kListBoxNumFiltered[];
// @fnv 0x00754690
Tile050* Owner050::AddListEntry(int data, const char* text, int compare, const char* name)
{
    if (container && (templateName || name))
    {
        Tile050* tile = ((::Tile050 *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::Menu050 *)(reinterpret_cast<::FUN_00a03c90_shell *>((container))->FUN_00a03c90()))))->FUN_00a1ddb0((::Tile *)(container), (char *)(name ? name : templateName), (::Tile *)(0))));
        if (!reinterpret_cast<::FUN_00a00f30_shell *>((tile))->FUN_00a00f30(0xfaa))
            reinterpret_cast<::Tile *>((tile))->Set(0xfaa, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(0xfc4, (char *)(text), true);
        if (compare)
        {
            reinterpret_cast<::FUN_00470440 *>(&(entries))->FUN_007a7eb0((::BGSPerkEntry *)(::FUN_007a62e0 *)(new FUN_007a62e0(tile, &data)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(compare));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::FUN_00724360_cls *>(this)->FUN_00724360();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(entries))->FUN_00905820((void *)&(const ::FUN_007a62e0 *const &)(new FUN_007a62e0(tile, &data)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(tile));
                reinterpret_cast<::fnv_00724800::ListBoxScroll *>(this)->FUN_00724800();
            }
            reinterpret_cast<::Tile *>((tile))->Set(0xfac, count++);
        }
        if (((unsigned int)(::GetRaceCount((char *)this))) == 1 && reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a00940(kListBoxNumFiltered, -1)) > 0.0)
        {
            Value050* value = ((::Value050 *)(reinterpret_cast<::FUN_00a00e90_shell *>((container))->FindTraitValue(0xfb0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((value))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((value))->FUN_00a09130(0x7d0, (::Tile *)(tile), 0xfb0);
            reinterpret_cast<::P03Value *>((value))->AppendFloatAction(0x7d3, reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a00940(kListBoxNumFiltered, -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((value))->FUN_00a09410(0);
        }
        return tile;
    }
    else
        return 0;
}

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
int FUN_00a00940(const char*, int);
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

    void UpdateHighlightTile();
};

// @fnv 0x00764ef0
void Cls_764ef0::UpdateHighlightTile()
{
    static int trait1 = FUN_00a00940(str_0106f8c0, -1);
    static int trait2 = FUN_00a00940(str_0106f8ac, -1);

    if (highlightTile)
    {
        if (selectedTile)
        {
            TileValue* val1 = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)highlightTile)))->FUN_00a00f30(trait1)));
            TileValue* val2 = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)highlightTile)))->FUN_00a00f30(trait2)));
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)val1)))->FUN_00a09130(0x7d0, selectedTile, 0xfa2);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)val1)))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)val2)))->FUN_00a09130(0x7d0, selectedTile, 0xfb0);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)val2)))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((((Tile_GetSpeechChallengeFailure_helper*)selectedTile)))->GetSpeechChallengeFailure())
            {
                Tile* box1 = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(highlightTile), str_0106f898)));
                if (box1)
                {
                    Tile* child1 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box1)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child1)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child1)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child1)))->FUN_00a07530(8);
                        child1 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box1)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child1)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child1)))->FUN_00a07530(8);
                        child1 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box1)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child1)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child1)))->FUN_00a07530(8);
                        child1 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box1)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child1)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child1)))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)box1)))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)box1)))->FUN_00a07530(8);
                }
            }
            else
            {
                Tile* box2 = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(highlightTile), str_0106f898)));
                if (box2)
                {
                    Tile* child2 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box2)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child2)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child2)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child2)))->FUN_00a07530(8);
                        child2 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box2)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child2)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child2)))->FUN_00a07530(8);
                        child2 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box2)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child2)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child2)))->FUN_00a07530(8);
                        child2 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box2)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child2)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child2)))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)box2)))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)box2)))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)highlightTile)))->Set(trait1, -1);
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)highlightTile)))->Set(trait2, 0);
        }
    }
}

struct ScrollTile
{
    void FUN_00700320(int, int);
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
// @fnv 0x00764430
ItemTile* IntListBox::FUN_00764430(int data, const char* text, int(__cdecl* compare)(BoxItem*, BoxItem*),
                                   const char* name)
{
    if (container && (templateName || name))
    {
        ItemTile* tile_2 = ((::ItemTile *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::ItemMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((container))->FUN_00a03c90()))))->FUN_00a1ddb0((::Tile *)(container), (char *)(name ? name : templateName), (::Tile *)(0))));
        ItemValue* value;
        if (!reinterpret_cast<::FUN_00a00f30_shell *>((tile_2))->FUN_00a00f30(0xfaa))
            reinterpret_cast<::Tile *>((tile_2))->Set(0xfaa, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile_2))->FUN_00a01350(0xfc4, (char *)(text), true);
        if (compare)
        {
            reinterpret_cast<::FUN_00470440 *>(&(items))->FUN_007a7eb0((::BGSPerkEntry *)(::BoxItem *)(new BoxItem(tile_2, &data)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(compare));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::C764930ListMenu *>(this)->RebuildVisibleTiles();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(items))->FUN_00905820((void *)&(const ::BoxItem *const &)(new BoxItem(tile_2, &data)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(tile_2));
                reinterpret_cast<::ScrollList *>(this)->FUN_00765210();
            }
            reinterpret_cast<::Tile *>((tile_2))->Set(0xfac, nextIndex++);
        }
        if (::GetRaceCount((char *)this) == 1 && reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxNumFiltered)), -1)) > 0.0)
        {
            value = ((::ItemValue *)(reinterpret_cast<::FUN_00a00e90_shell *>((container))->FindTraitValue(0xfb0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((value))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((value))->FUN_00a09130(0x7d0, (::Tile *)(tile_2), 0xfb0);
            reinterpret_cast<::P03Value *>((value))->AppendFloatAction(0x7d3, reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxNumFiltered)), -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((value))->FUN_00a09410(0);
        }
        return tile_2;
    }
    else
        return 0;
}
// @fnv 0x007646d0
void ClearOwner::FUN_007646d0()
{
    while (next && *((::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3())))
    {
        ClearNode* following = ((::ClearNode *)(reinterpret_cast<::Callees *>((next))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3())))->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3())))->extra;
        delete *((::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((next))->Initialize((::CombatController *)(0));
        delete next;
        next = following;
    }
    if (item)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete item->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete item->extra;
        delete item;
    }
    item = 0;
    count = 0;
    height = 0.0f;
    if (container)
        reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(FUN_00a01860(str_0106f8d0), 0.0f, true);
    reinterpret_cast<::ScrollList *>(this)->FUN_00765210();
    selection = 0;
    reinterpret_cast<::Cls_764ef0 *>(this)->UpdateHighlightTile();
}
// Resets the visible count and scroll, adds each non-hidden item's tile with its index, then updates the scroll bar and selection.
// @fnv 0x00764930
void C764930ListMenu::RebuildVisibleTiles()
{
    m_usNumVisible = 0;
    m_fScroll = 0.0f;
    for (C764930ListNode* pkNode = this; pkNode && ((::C764930Item *)(new ((void *)(pkNode)) ::Vec3())); pkNode = ((::C764930ListNode *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070())))
    {
        if (!((::C764930Item *)(new ((void *)(pkNode)) ::Vec3()))->m_bHidden)
        {
            reinterpret_cast<::Tile *>((((::C764930Item *)(new ((void *)(pkNode)) ::Vec3()))->m_pkTile))->Set(0xfac, m_usNumVisible++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(((::C764930Item *)(new ((void *)(pkNode)) ::Vec3()))->m_pkTile));
        }
    }
    reinterpret_cast<::ScrollList *>(this)->FUN_00765210();
    reinterpret_cast<::Cls_764ef0 *>(this)->UpdateHighlightTile();
}
// Computes a scrollbar height from total and container count, stores the scroll delta on the container and the item count on the scrollbar.
// @fnv 0x00765210
void ScrollList::FUN_00765210()
{
    if (container)
    {
        float count = reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0);
        int height = 1;
        if (total > 0.0 && count > 0.0)
        {
            if (total > count)
            {
                height = FUN_00647b70((int)FUN_004e4430(reinterpret_cast<::FUN_00765340_shell *>(this)->GetUnfilteredCount() * (total - count) / total) + 1, 2);
            }
            if (height > 1)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(FUN_00a01860("_scroll_delta"), (total - count) / (height - 1), true);
            }
        }
        if (scrollbar)
        {
            reinterpret_cast<::Tile *>((scrollbar))->Set(FUN_00a01860("_number_of_items"), height);
        }
    }
}

namespace fnv_007a2070 {

struct ClearTile
{
    virtual ~ClearTile();
};
struct ClearPayload
{
    ~ClearPayload();
};
struct ClearTilePayloadPair
{
    ClearTile* tile;
    ClearPayload* payload;
};
struct ClearNode
{
    ~ClearNode();
};
struct ClearList
{
    int unk00;
    ClearTilePayloadPair* head;
    ClearNode* tail;
    TileF* container;
    void* selected;
    void* scrollBar;
    const char* templateName;
    unsigned short count;
    float scrollPosition;
    void FUN_007a6920();
    void FUN_007a6600();
    void FUN_007a2070();
};

// @fnv 0x007a2070
void ClearList::FUN_007a2070()
{
    while (tail && *((::fnv_007a2070::ClearTilePayloadPair **)(new ((void *)(tail)) ::Vec3())))
    {
        ClearNode* next = ((::fnv_007a2070::ClearNode *)(reinterpret_cast<::Callees *>((tail))->FUN_00726070()));
        if (!s_bAllowDetach)
            delete (*((::fnv_007a2070::ClearTilePayloadPair **)(new ((void *)(tail)) ::Vec3())))->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::fnv_007a2070::ClearTilePayloadPair **)(new ((void *)(tail)) ::Vec3())))->payload;
        delete *((::fnv_007a2070::ClearTilePayloadPair **)(new ((void *)(tail)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((tail))->Initialize((::CombatController *)(0));
        delete tail;
        tail = next;
    }
    if (head)
    {
        if (!s_bAllowDetach)
            delete head->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete head->payload;
        delete head;
    }
    head = 0;
    count = 0;
    scrollPosition = 0.0f;
    if (container)
        reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(FUN_00a01860("_num_filtered"), 0.0f, true);
    FUN_007a6920();
    selected = 0;
    FUN_007a6600();
}
}  // namespace fnv_007a2070

namespace fnv_007a2450 {
struct NavigationTile
{
};
struct NavigationRow
{
    NavigationTile* tile;
};
struct NavigationLink
{
    NavigationRow* row;
    NavigationLink* next;
};
struct NavigationVirtual
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual NavigationTile* GetTile(unsigned int index, bool scroll);
};
int FUN_00a00940(const char* name, int fallback);
struct NavigationList : NavigationVirtual, NavigationLink
{
    NavigationTile* container;
    NavigationTile* selected;
    unsigned int unk14, unk18;
    unsigned short count, unk1e;
    NavigationTile* GetNavigationTileForEvent(unsigned int event);
};

// Maps a navigation event to a scroll delta, finds the tile at the resulting index that is enabled, and returns it unless it equals selected.
// @fnv 0x007a2450
NavigationTile* NavigationList::GetNavigationTileForEvent(unsigned int event)
{
    NavigationTile* foundVal = 0;
    int delta8 = 0;
    switch (event)
    {
    case 2:
        delta8 = 1;
        break;
    case 1:
        delta8 = -1;
        break;
    case 15:
        delta8 = container ? (int)::InventoryStackRecord::RoundToNearestStep(-reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) /
                                                   reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(::FUN_00a01860("_scroll_delta")),
                                               1.0f)
                           : 0;
        break;
    case 16:
        delta8 = container ? (int)::InventoryStackRecord::RoundToNearestStep(reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) /
                                                   reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(::FUN_00a01860("_scroll_delta")),
                                               1.0f)
                           : 0;
        break;
    }
    if (reinterpret_cast<::FUN_007a6550_shell *>(this)->FUN_007a6550() && delta8 && count)
    {
        int maximumTmp = count - 1;
        int index;
        if (selected)
        {
            int current5 = (int)reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfac);
            index = current5 + delta8;
            if (index < 0)
                index = 0;
            else if (index > maximumTmp)
                index = maximumTmp;
        }
        else if (delta8 > 0)
        {
            index = 0;
        }
        else
        {
            index = maximumTmp;
        }
        while (true)
        {
            for (NavigationLink* link = static_cast<NavigationLink*>(this); !foundVal && link && *((::fnv_007a2450::NavigationRow **)(new ((void *)(link)) ::Vec3()));
                 link = ((::fnv_007a2450::NavigationLink *)(reinterpret_cast<::Callees *>((link))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*((::fnv_007a2450::NavigationRow **)(new ((void *)(link)) ::Vec3())))->tile))->GetFloat(0xfac) == index)
                    foundVal = (*((::fnv_007a2450::NavigationRow **)(new ((void *)(link)) ::Vec3())))->tile;
            }
            if (foundVal && !reinterpret_cast<::FUN_00a01230_shell *>((foundVal))->IsTraitNonZero(::FUN_00a00940("_enabled", -1)))
            {
                foundVal = 0;
                if (delta8 > 0 && ++index > maximumTmp)
                {
                    index = maximumTmp - 1;
                    while ((!foundVal || !reinterpret_cast<::FUN_00a01230_shell *>((foundVal))->IsTraitNonZero(::FUN_00a00940("_enabled", -1))) && index >= 0)
                    {
                        foundVal = GetTile(index--, false);
                    }
                    break;
                }
                else if (delta8 < 0 && --index < 0)
                {
                    index = 1;
                    while ((!foundVal || !reinterpret_cast<::FUN_00a01230_shell *>((foundVal))->IsTraitNonZero(::FUN_00a00940("_enabled", -1))) &&
                           index <= maximumTmp)
                    {
                        foundVal = GetTile(index++, false);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return foundVal != selected ? foundVal : 0;
}
}  // namespace fnv_007a2450

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

    void FUN_007a73e0();
    void FUN_007a3ac0();
};

// @fnv 0x007a3ac0
void FUN_007a3ac0_ListBox::FUN_007a3ac0()
{
    while (pNext && *((::LBItem **)(new ((void *)(pNext)) ::Vec3())))
    {
        LBNode* pListNode = ((::LBNode *)(reinterpret_cast<::Callees *>((pNext))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::LBItem **)(new ((void *)(pNext)) ::Vec3())))->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::LBItem **)(new ((void *)(pNext)) ::Vec3())))->extra;
        delete *((::LBItem **)(new ((void *)(pNext)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((pNext))->Initialize((::CombatController *)(0));
        delete pNext;
        pNext = pListNode;
    }

    if (pItem)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete pItem->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete pItem->extra;
        delete pItem;
    }
    pItem = 0;

    usItemCount = 0;
    m_fFirstListValue = 0.0f;
    if (m_pListTile)
        reinterpret_cast<::FUN_00a012d0_t *>((m_pListTile))->FUN_00a012d0(FUN_00a01860("_num_filtered"), 0.0f, true);
    reinterpret_cast<::FUN_007a7700_Menu *>(this)->FUN_007a7700();
    unk10 = 0;
    FUN_007a73e0();
}

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
float RoundStep(float, float step = 1.0f);
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
// @fnv 0x007a4000
NavTile* Navigation::FUN_007a4000(int key)
{
    NavTile* result = 0;
    int delta = 0;
    switch (key)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta =
            container ? (int)RoundStep(-reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(::FUN_00a01860("_scroll_delta"))) : 0;
        break;
    case 16:
        delta =
            container ? (int)RoundStep(reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(::FUN_00a01860("_scroll_delta"))) : 0;
        break;
    }
    if (((bool)(reinterpret_cast<::FUN_007a7330_cls *>(this)->FUN_007a7330())) && delta && count)
    {
        int maximum = count - 1;
        int index;
        if (selected)
        {
            int current = (int)reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfac);
            index = current + delta;
            if (index < 0)
                index = 0;
            else if (index > maximum)
                index = maximum;
        }
        else if (delta > 0)
            index = 0;
        else
            index = maximum;
        while (true)
        {
            NavNode* node;
            for (node = this ? &items : 0; !result && node && *((::NavItem **)(new ((void *)(node)) ::Vec3())); node = ((::NavNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*((::NavItem **)(new ((void *)(node)) ::Vec3())))->tile))->GetFloat(0xfac) == index)
                    result = (*((::NavItem **)(new ((void *)(node)) ::Vec3())))->tile;
            }
            if (result && !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(::FUN_00a00940("_enabled", -1)))
            {
                result = 0;
                if (delta > 0 && ++index > maximum)
                {
                    index = maximum - 1;
                    while ((!result || !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(::FUN_00a00940("_enabled", -1))) && index >= 0)
                    {
                        result = At(index--, false);
                    }
                    break;
                }
                else if (delta < 0 && --index < 0)
                {
                    index = 1;
                    while ((!result || !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(::FUN_00a00940("_enabled", -1))) && index <= maximum)
                    {
                        result = At(index++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return result != selected ? result : 0;
}

namespace fnv_007a54d0 {
struct ClearExtra
{
    ~ClearExtra();
};
struct ClearTileExtraPair
{
    LBTileObj* tile;
    ClearExtra* extra;
};
struct ClearNode
{
    ~ClearNode();
};
struct ClearListBox
{
    void* vtable;
    ClearTileExtraPair* item;
    ClearNode* next;
    TileProxy* container;
    void* selected;
    void* scrollbar;
    const char* templateName;
    unsigned short itemCount;
    float totalHeight;
    void FUN_007a54d0();
};
// @fnv 0x007a54d0
void ClearListBox::FUN_007a54d0()
{
    while (next && *((::fnv_007a54d0::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3())))
    {
        ClearNode* following = ((::fnv_007a54d0::ClearNode *)(reinterpret_cast<::Callees *>((next))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::fnv_007a54d0::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3())))->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
        {
            delete (*((::fnv_007a54d0::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3())))->extra;
        }
        delete *((::fnv_007a54d0::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((next))->Initialize((::CombatController *)(0));
        delete next;
        next = following;
    }
    if (item)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete item->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
        {
            delete item->extra;
        }
        delete item;
    }
    item = 0;
    itemCount = 0;
    totalHeight = 0.0f;
    if (container)
        reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(FUN_00a01860("_num_filtered"), 0.0f, true);
    reinterpret_cast<::ListScrollHost *>(this)->FUN_007a8580();
    selected = 0;
    reinterpret_cast<::HighlightList *>(this)->UpdateHighlight_007a8260();
}
}  // namespace fnv_007a54d0

namespace fnv_007a5ad0 {
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
int FUN_00a00940(const char*, int);
struct NavList : NavNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual NavTile* GetAt(unsigned int, bool);
    NavTile* container;
    NavTile* selected;
    int scrollbar;
    int templateName;
    unsigned short count;
    NavTile* GetNavigationTarget(int action);
};
// @fnv 0x007a5ad0
NavTile* NavList::GetNavigationTarget(int action)
{
    NavTile* result = 0;
    int delta = 0;
    switch (action)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta =
            container
                ? (int)((double)(::InventoryStackRecord::RoundToNearestStep(
                      (float)(-((double)(reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0))) / ((double)(reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(::FUN_00a01860("_scroll_delta"))))), 1.0f)))
                : 0;
        break;
    case 16:
        delta =
            container
                ? (int)((double)(::InventoryStackRecord::RoundToNearestStep(
                      (float)(((double)(reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0))) / ((double)(reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(::FUN_00a01860("_scroll_delta"))))), 1.0f)))
                : 0;
        break;
    }
    if (reinterpret_cast<::FUN_007a81b0_cls *>(this)->FUN_007a81b0() && delta && count)
    {
        int maxIndex = count - 1;
        int index;
        if (selected)
        {
            int oldIndex = (int)((double)(reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfac)));
            index = oldIndex + delta;
            if (index < 0)
                index = 0;
            else if (index > maxIndex)
                index = maxIndex;
        }
        else if (delta > 0)
            index = 0;
        else
            index = maxIndex;
        while (true)
        {
            for (NavNode* node = static_cast<NavNode*>(this); !result && node && *((::fnv_007a5ad0::NavItem **)(new ((void *)(node)) ::Vec3()));
                 node = ((::fnv_007a5ad0::NavNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                if (((double)(reinterpret_cast<::TileListBoxCalls *>(((*((::fnv_007a5ad0::NavItem **)(new ((void *)(node)) ::Vec3())))->tile))->GetFloat(0xfac))) == index)
                    result = (*((::fnv_007a5ad0::NavItem **)(new ((void *)(node)) ::Vec3())))->tile;
            }
            if (result && !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(::FUN_00a00940("_enabled", -1)))
            {
                result = 0;
                if (delta > 0 && ++index > maxIndex)
                {
                    index = maxIndex - 1;
                    while ((!result || !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(::FUN_00a00940("_enabled", -1))) && index >= 0)
                    {
                        result = GetAt(index--, false);
                    }
                    break;
                }
                else if (delta < 0 && --index < 0)
                {
                    index = 1;
                    while ((!result || !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(::FUN_00a00940("_enabled", -1))) && index <= maxIndex)
                    {
                        result = GetAt(index++, false);
                    }
                    break;
                }
            }
            else
                break;
        }
    }
    return result != selected ? result : 0;
}
}  // namespace fnv_007a5ad0

namespace fnv_007a5e70 {
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
    HighlightTile* scrollbar;
    void FUN_007a5e70();
};
// @fnv 0x007a5e70
void HighlightList::FUN_007a5e70()
{
    if (selected && scrollbar && container && reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) > 0.0)
    {
        bool above = reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfa2) < 0.0;
        bool changed = reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfa2) + reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfb0) > reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0);
        bool below = above || changed;
        while (reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfac) >= 0.0 && (above || changed))
        {
            int previous = above ? -1 : 1;
            float direction = reinterpret_cast<::TileListBoxCalls *>((scrollbar))->GetFloat(FUN_00a01860("_current_value"));
            reinterpret_cast<::FUN_00a012d0_t *>((scrollbar))->FUN_00a012d0(FUN_00a01860("_current_value"), direction + previous, false);
            if (direction == reinterpret_cast<::TileListBoxCalls *>((scrollbar))->GetFloat(FUN_00a01860("_current_value")))
            {
                ::FUN_005b5e40(
                    );
                break;
            }
            above = reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfa2) < 0.0;
            changed = reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfa2) + reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfb0) > reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0);
        }
        if (below)
            reinterpret_cast<::FUN_00a01290_shell *>((scrollbar))->SetTraitAndReset(FUN_00a01860("_SetInCode"), 1.0f);
    }
}
}  // namespace fnv_007a5e70

struct ListBox_7a6600
{
    int unk00;
    int unk04;
    int unk08;
    Tile* highlightTile;
    Tile* selectedTile;

    void FUN_007a6600();
};
// @fnv 0x007a23e0
bool FUN_007a23e0_cls::FUN_007a23e0(FUN_007a23e0_arg* arg)
{
    if (reinterpret_cast<::FUN_007a6550_shell *>(this)->FUN_007a6550() && (arg == 0 || (reinterpret_cast<::ListOwner *>(this)->ContainsKey((int)(arg)) && reinterpret_cast<::FUN_00a01230_shell *>((arg))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1)))))
    {
        m_10 = arg;
        reinterpret_cast<::ListBox_7a6600 *>(this)->FUN_007a6600();
        return true;
    }
    else
    {
        return false;
    }
}

// Applies trait values to the highlight tile and shows or hides the speech-challenge box and its children based on the selected tile's speech challenge failure.
// @fnv 0x007a6600
void ListBox_7a6600::FUN_007a6600()
{
    static int trait1 = FUN_00a00940(str_0106f8c0, -1);
    static int trait2 = FUN_00a00940(str_0106f8ac, -1);

    if (highlightTile)
    {
        if (selectedTile)
        {
            TileValue* val1 = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)highlightTile)))->FUN_00a00f30(trait1)));
            TileValue* val2 = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)highlightTile)))->FUN_00a00f30(trait2)));
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)val1)))->FUN_00a09130(0x7d0, selectedTile, 0xfa2);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)val1)))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)val2)))->FUN_00a09130(0x7d0, selectedTile, 0xfb0);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)val2)))->FUN_00a09410(0);

            if (reinterpret_cast<::Tile *>((((Tile_GetSpeechChallengeFailure_helper*)selectedTile)))->GetSpeechChallengeFailure())
            {
                Tile* box1 = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(highlightTile), str_0106f898)));
                if (box1)
                {
                    Tile* child1 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box1)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child1)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child1)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child1)))->FUN_00a07530(8);
                        child1 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box1)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child1)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child1)))->FUN_00a07530(8);
                        child1 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box1)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child1)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child1)))->FUN_00a07530(8);
                        child1 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box1)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child1)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child1)))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)box1)))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)box1)))->FUN_00a07530(8);
                }
            }
            else
            {
                Tile* box2 = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(highlightTile), str_0106f898)));
                if (box2)
                {
                    Tile* child2 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box2)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child2)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child2)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child2)))->FUN_00a07530(8);
                        child2 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box2)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child2)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child2)))->FUN_00a07530(8);
                        child2 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box2)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child2)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child2)))->FUN_00a07530(8);
                        child2 = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box2)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child2)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)child2)))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)box2)))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((((TAN*)box2)))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)highlightTile)))->Set(trait1, -1);
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)highlightTile)))->Set(trait2, 0);
        }
    }
}

namespace fnv_007a6920 {
struct ScrollTile
{
    void FUN_00700320(int, int);
};
struct ScrollList
{
    unsigned int unk00, unk04, unk08;
    ScrollTile* container;
    unsigned int unk10;
    ScrollTile* scrollbar;
    unsigned int unk18, unk1c;
    float totalHeight;
    void FUN_007a6920();
};
// Computes a scroll step from totalHeight and the container's count, applies it via _scroll_delta, and sets _number_of_items on the scrollbar.
// @fnv 0x007a6920
void ScrollList::FUN_007a6920()
{
    if (container)
    {
        float count = reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0);
        int height = 1;
        if (totalHeight > 0.0 && count > 0.0)
        {
            if (totalHeight > count)
                height = FUN_00647b70((int)FUN_004e4430(((unsigned int)(reinterpret_cast<::filt7a8::F7Menu *>(this)->FUN_007a86e0())) * (totalHeight - count) / totalHeight) + 1, 2);
            if (height > 1)
                reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(FUN_00a01860("_scroll_delta"), (totalHeight - count) / (height - 1), true);
        }
        if (scrollbar)
            reinterpret_cast<::Tile *>((scrollbar))->Set(FUN_00a01860("_number_of_items"), height);
    }
}
}  // namespace fnv_007a6920

namespace fnv_007a73e0 {
struct HighlightTile;
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
    void FUN_007a73e0();
};
// Binds the highlight and selected-height traits to the selected tile and toggles the lb_highlight_box borders based on the speech challenge failure state.
// @fnv 0x007a73e0
void HighlightList::FUN_007a73e0()
{
    static int highlightY = FUN_00a00940("_highlight_y", -1);
    static int selectedHeight = FUN_00a00940("_selected_height", -1);
    if (container)
    {
        if (selected)
        {
            HighlightValue* height = ((::fnv_007a73e0::HighlightValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((container))->FUN_00a00f30(highlightY)));
            HighlightValue* y = ((::fnv_007a73e0::HighlightValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((container))->FUN_00a00f30(selectedHeight)));
            reinterpret_cast<::AGOwner *>((height))->FUN_00a09130(2000, (::Tile *)(selected), 4002);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((height))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((y))->FUN_00a09130(2000, (::Tile *)(selected), 4016);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((y))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((selected))->GetSpeechChallengeFailure())
            {
                HighlightTile* box = (HighlightTile*)((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)((Tile*)container), "lb_highlight_box")));
                if (box)
                {
                    HighlightTile* child = ((::fnv_007a73e0::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("top"))));
                    if (child)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::fnv_007a73e0::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::fnv_007a73e0::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::fnv_007a73e0::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((box))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((box))->FUN_00a07530(8);
                }
            }
            else
            {
                HighlightTile* box = (HighlightTile*)((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)((Tile*)container), "lb_highlight_box")));
                if (box)
                {
                    HighlightTile* child = ((::fnv_007a73e0::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("top"))));
                    if (child)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::fnv_007a73e0::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::fnv_007a73e0::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::fnv_007a73e0::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((box))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((box))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((container))->Set(highlightY, -1);
            reinterpret_cast<::Tile *>((container))->Set(selectedHeight, 0);
        }
    }
}
}  // namespace fnv_007a73e0

namespace fnv_007d7290 {
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
struct ClearList
{
    int unk00;
    ClearTileExtraPair* item;
    ClearNode* next;
    ClearContainer* container;
    int selected;
    int unk14;
    int unk18;
    unsigned short count;
    float height;
    void UpdateHighlightBox();
    void FUN_007d7290();
};
// Deletes every node and item in the list, resets count, height and selection, and updates the container's _num_filtered value.
// @fnv 0x007d7290
void ClearList::FUN_007d7290()
{
    while (next && *((::fnv_007d7290::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3())))
    {
        ClearNode* following = ((::fnv_007d7290::ClearNode *)(reinterpret_cast<::Callees *>((next))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::fnv_007d7290::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3())))->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::fnv_007d7290::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3())))->extra;
        delete *((::fnv_007d7290::ClearTileExtraPair **)(new ((void *)(next)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((next))->Initialize((::CombatController *)(0));
        delete next;
        next = following;
    }
    if (item)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete item->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete item->extra;
        delete item;
    }
    item = 0;
    count = 0;
    height = 0.0f;
    if (container)
        reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(::FUN_00a01860("_num_filtered"), 0.0f, true);
    reinterpret_cast<::HeightList *>(this)->FUN_007d9460();
    selected = 0;
    UpdateHighlightBox();
}
}  // namespace fnv_007d7290

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
// @fnv 0x007d7a80
void FUN_007d7a80_shell::FUN_007d7a80(int a)
{
    reinterpret_cast<::SelectionList *>((((FUN_007d9000_shell*)this)))->ApplySelectionAction((::SelectionTile *)(a), 0);
}
// If the list is ready and contains the item, reads its _selected state and sets it to 1, 0 or toggled depending on action 0/1/2, returning true on success.
// @fnv 0x007d9000
bool SelectionList::ApplySelectionAction(SelectionTile* item, int action)
{
    if (reinterpret_cast<::D7580ListBox *>(this)->FUN_007d7580() && item && reinterpret_cast<::ListOwner *>(this)->ContainsKey((int)(item)))
    {
        static int selected = FUN_00a00940("_selected", -1);
        bool value = reinterpret_cast<::FUN_00a01230_shell *>((item))->IsTraitNonZero(selected);
        switch (action)
        {
        case 0:
            if (!value)
            {
                reinterpret_cast<::Tile *>((item))->Set(selected, 1);
                return true;
            }
            break;
        case 1:
            if (value)
            {
                reinterpret_cast<::Tile *>((item))->Set(selected, 0);
                return true;
            }
            break;
        case 2:
            reinterpret_cast<::Tile *>((item))->Set(selected, !value);
            return true;
        }
    }
    return false;
}

// Returns true when m_pkTile exists and its _enabled trait bool value is set.
// @fnv 0x007d7580
bool D7580ListBox::FUN_007d7580()
{
    static int s_iEnabledTrait = ::FUN_00a00940("_enabled", -1);
    return m_pkTile && reinterpret_cast<::FUN_00a01230_shell *>((m_pkTile))->IsTraitNonZero(s_iEnabledTrait);
}

namespace fnv_007d7da0 {
struct ItemTile;
struct ItemValue
{
};
struct ItemMenu
{
};
struct ItemTile
{
    float GetFloat(int);
};
struct BoxEntry
{
    ItemTile* tile;
    int* data;
    char flag;
    BoxEntry(ItemTile*, int*);
};
struct BoxEntries
{
    BoxEntry* item;
    BoxEntries* next;
};
extern "C" const char kListBoxNumFiltered[];
int __cdecl FUN_00a00940(const char*, int);
struct ItemBox
{
    int unk00;
    BoxEntries entries;
    ItemTile* container;
    ItemTile* selected;
    ItemTile* scrollbar;
    const char* templateName;
    unsigned short nextIndex;
    ItemTile* FUN_007d7da0(int, const char*, int(__cdecl*)(BoxEntry*, BoxEntry*), const char*);
};
// Creates a tile in the container's menu, sets its values, inserts it into entries (sorted or appended), and updates the filtered-count value when in mode 1.
// @fnv 0x007d7da0
ItemTile* ItemBox::FUN_007d7da0(int data, const char* text, int(__cdecl* compare)(BoxEntry*, BoxEntry*),
                                const char* name)
{
    if (container && (templateName || name))
    {
        ItemTile* tile = ((::fnv_007d7da0::ItemTile *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::fnv_007d7da0::ItemMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((container))->FUN_00a03c90()))))->FUN_00a1ddb0((::Tile *)(container), (char *)(name ? name : templateName), (::Tile *)(0))));
        if (!((::fnv_007d7da0::ItemValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((tile))->FUN_00a00f30(0xfaa))))
            reinterpret_cast<::Tile *>((tile))->Set(0xfaa, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(0xfc4, (char *)(text), true);
        if (compare)
        {
            reinterpret_cast<::FUN_00470440 *>(&(entries))->FUN_007a7eb0((::BGSPerkEntry *)(::fnv_007d7da0::BoxEntry *)(new BoxEntry(tile, &data)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(compare));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::fnv_007d9590::ListBox_SaveLoad *>(this)->UpdateSaveLoadList();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(entries))->FUN_00905820((void *)&(const ::fnv_007d7da0::BoxEntry *const &)(new BoxEntry(tile, &data)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(tile));
                reinterpret_cast<::ListBoxScroll *>(this)->FUN_007d9d50();
            }
            reinterpret_cast<::Tile *>((tile))->Set(0xfac, nextIndex++);
        }
        if (::GetRaceCount((char *)this) == 1 && container->GetFloat(FUN_00a00940(kListBoxNumFiltered, -1)) > 0.0)
        {
            ItemValue* value = ((::fnv_007d7da0::ItemValue *)(reinterpret_cast<::FUN_00a00e90_shell *>((container))->FindTraitValue(0xfb0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((value))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((value))->FUN_00a09130(0x7d0, (::Tile *)(tile), 0xfb0);
            reinterpret_cast<::P03Value *>((value))->AppendFloatAction(0x7d3, container->GetFloat(FUN_00a00940(kListBoxNumFiltered, -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((value))->FUN_00a09410(0);
        }
        return tile;
    }
    else
        return 0;
}
}  // namespace fnv_007d7da0

namespace fnv_007d81f0 {
struct ClearNode
{
    ~ClearNode();
};
struct ClearList
{
    void* vtable;
    LBItem* item;
    ClearNode* next;
    TileF* container;
    void* selected;
    void* scrollbar;
    const char* templateName;
    unsigned short itemCount;
    float totalHeight;
    void FUN_007d97a0();
    void FUN_007d81f0();
};
// @fnv 0x007d81f0
void ClearList::FUN_007d81f0()
{
    while (next && *((::LBItem **)(new ((void *)(next)) ::Vec3())))
    {
        ClearNode* following = ((::fnv_007d81f0::ClearNode *)(reinterpret_cast<::Callees *>((next))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::LBItem **)(new ((void *)(next)) ::Vec3())))->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::LBItem **)(new ((void *)(next)) ::Vec3())))->extra;
        delete *((::LBItem **)(new ((void *)(next)) ::Vec3()));
        reinterpret_cast<::CombatProcedure *>((next))->Initialize((::CombatController *)(0));
        delete next;
        next = following;
    }
    if (item)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete item->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete item->extra;
        delete item;
    }
    item = 0;
    itemCount = 0;
    totalHeight = 0.0f;
    if (container)
        reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(FUN_00a01860(str_0106f8d0), 0.0f, true);
    reinterpret_cast<::ListBoxScroll *>(this)->FUN_007d9d50();
    selected = 0;
    FUN_007d97a0();
}
}  // namespace fnv_007d81f0

struct P240Tile
{
    void FUN_00700320(int, int);
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
    P240Tile* SelectLast();
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

namespace fnv_007d89c0 {
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
    virtual NavigationTile* GetTile(int last, bool select);
};
struct NavigationList : NavigationBase, NavigationNode
{
    NavigationTile* container;
    NavigationTile* selected;
    NavigationTile* scrollbar;
    const char* templateName;
    unsigned short count;
    NavigationTile* FUN_007d89c0(int direction);
};
// @fnv 0x007d89c0
NavigationTile* NavigationList::FUN_007d89c0(int direction)
{
    NavigationTile* tile = 0;
    int step = 0;
    switch (direction)
    {
    case 2:
        step = 1;
        break;
    case 1:
        step = -1;
        break;
    case 15:
        step = container
                   ? (int)::InventoryStackRecord::RoundToNearestStep(
                         -reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a01860(str_0106f90c)), 1.0f)
                   : 0;
        break;
    case 16:
        step = container
                   ? (int)::InventoryStackRecord::RoundToNearestStep(
                         reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a01860(str_0106f90c)), 1.0f)
                   : 0;
        break;
    }
    if (::fnv_007d88a0::FUN_007d88a0((void *)this) && step && count)
    {
        int index = count - 1;
        int last;
        if (selected)
        {
            int current = (int)reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfac);
            if ((last = current + step) < 0)
                last = 0;
            else if (last > index)
                last = index;
        }
        else
        {
            if (step > 0)
                last = 0;
            else
                last = index;
        }
        while (true)
        {
            for (NavigationNode* node = this; !tile && node && *((::fnv_007d89c0::NavigationItem **)(new ((void *)(node)) ::Vec3())); node = ((::fnv_007d89c0::NavigationNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*((::fnv_007d89c0::NavigationItem **)(new ((void *)(node)) ::Vec3())))->tile))->GetFloat(0xfac) == last)
                    tile = (*((::fnv_007d89c0::NavigationItem **)(new ((void *)(node)) ::Vec3())))->tile;
            }
            if (tile && !reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1)))
            {
                tile = 0;
                if (step > 0 && ++last > index)
                {
                    last = index - 1;
                    while ((!tile || !reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1))) && last >= 0)
                        tile = GetTile(last--, false);
                    break;
                }
                else if (step < 0 && --last < 0)
                {
                    last = 1;
                    while ((!tile || !reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1))) && last <= index)
                        tile = GetTile(last++, false);
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return tile != selected ? tile : 0;
}
}  // namespace fnv_007d89c0

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

// @fnv 0x007d9140
void ListBoxExt::UpdateHighlightBox()
{
    static int s_highlightY = FUN_00a00940("_highlight_y", -1);
    static int s_selectedHeight = FUN_00a00940("_selected_height", -1);

    if (tile0c)
    {
        if (tile10)
        {
            TileValue* valSelectedHeight;
            TileValue* valHighlightY;
            valHighlightY = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((tile0c))->FUN_00a00f30(s_highlightY)));
            valSelectedHeight = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((tile0c))->FUN_00a00f30(s_selectedHeight)));
            reinterpret_cast<::AGOwner *>((valHighlightY))->FUN_00a09130(0x7d0, tile10, 0xfa2);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((valHighlightY))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((valSelectedHeight))->FUN_00a09130(0x7d0, tile10, 0xfb0);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((valSelectedHeight))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((tile10))->GetSpeechChallengeFailure())
            {
                TileExt* highlightBox = (TileExt*)((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(tile0c), "lb_highlight_box")));
                if (highlightBox)
                {
                    TileExt* child = ((::TileExt *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((highlightBox))->FUN_00a03da0((char *)("top"))));
                    if (child)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::TileExt *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((highlightBox))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::TileExt *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((highlightBox))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::TileExt *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((highlightBox))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((highlightBox))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((highlightBox))->FUN_00a07530(8);
                }
            }
            else
            {
                TileExt* highlightBox = (TileExt*)((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(tile0c), "lb_highlight_box")));
                if (highlightBox)
                {
                    TileExt* child = ((::TileExt *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((highlightBox))->FUN_00a03da0((char *)("top"))));
                    if (child)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::TileExt *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((highlightBox))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::TileExt *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((highlightBox))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                        child = ((::TileExt *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((highlightBox))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((child))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((child))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((highlightBox))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((highlightBox))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((tile0c))->Set(s_highlightY, -1);
            reinterpret_cast<::Tile *>((tile0c))->Set(s_selectedHeight, 0);
        }
    }
}

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
// Applies predicate to each list item, hides matches, renumbers visible tiles, updates the container count and reselects a tile.
// @fnv 0x007d8450
void P240Owner::ApplyFilter(bool(__cdecl* predicate)(void*))
{
    int iHiddenCount = 0;
    int iSelectedIndex = -1;
    static int trait = FUN_00a00940(str_0106f8d0, -1);
    count = 0;
    height = 0.0f;
    for (P240List* node = this; node && *((::P240Item **)(new ((void *)(node)) ::Vec3())); node = ((::P240List *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        (*((::P240Item **)(new ((void *)(node)) ::Vec3())))->hidden = predicate && predicate((*((::P240Item **)(new ((void *)(node)) ::Vec3())))->data);
        if ((*((::P240Item **)(new ((void *)(node)) ::Vec3())))->hidden)
        {
            if ((*((::P240Item **)(new ((void *)(node)) ::Vec3())))->tile == selected)
            {
                iSelectedIndex = (int)reinterpret_cast<::TileListBoxCalls *>(((*((::P240Item **)(new ((void *)(node)) ::Vec3())))->tile))->GetFloat(0xfac);
                selected = 0;
            }
            reinterpret_cast<::Tile *>(((*((::P240Item **)(new ((void *)(node)) ::Vec3())))->tile))->Set(0xfac, -1);
            ++iHiddenCount;
        }
        else
        {
            if (iSelectedIndex >= 0 && count == iSelectedIndex)
                selected = (*((::P240Item **)(new ((void *)(node)) ::Vec3())))->tile;
            reinterpret_cast<::Tile *>(((*((::P240Item **)(new ((void *)(node)) ::Vec3())))->tile))->Set(0xfac, count++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)((*((::P240Item **)(new ((void *)(node)) ::Vec3())))->tile));
        }
    }
    reinterpret_cast<::Tile *>((container))->Set(trait, iHiddenCount);
    reinterpret_cast<::ListBoxScroll *>(this)->FUN_007d9d50();
    if (!selected && iSelectedIndex >= 0)
        selected = v5(iSelectedIndex, false);
    if (!selected && iSelectedIndex >= 0)
        selected = SelectLast();
    reinterpret_cast<::ListBoxX *>(this)->FUN_007d97a0();
}
// If active and the tile is null or contained and enabled, sets m_pkSelected to the tile, updates the selection and returns true; otherwise returns false.
// @fnv 0x007d8950
bool C7D8950ListBox::FUN_007d8950(C7D8950Tile* pkTile)
{
    if (::fnv_007d88a0::FUN_007d88a0((void *)this) && (!pkTile || (reinterpret_cast<::ListOwner *>(this)->ContainsKey((int)(pkTile)) && reinterpret_cast<::FUN_00a01230_shell *>((pkTile))->IsTraitNonZero(::FUN_00a00940("_enabled", -1)))))
    {
        m_pkSelected = pkTile;
        reinterpret_cast<::ListBoxX *>(this)->FUN_007d97a0();
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x007d97a0
void ListBoxX::FUN_007d97a0()
{
    static int traitHighlightY = ::FUN_00a00940(str_0106f8c0, -1);
    static int traitSelectedHeight = ::FUN_00a00940(str_0106f8ac, -1);
    if (m_pListTile != 0)
    {
        if (m_pSelectedTile != 0)
        {
            TileValue* valHighlightY = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)m_pListTile)))->FUN_00a00f30(traitHighlightY)));
            TileValue* valSelectedHeight = ((::TileValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((((Tile_GetValue_helper*)m_pListTile)))->FUN_00a00f30(traitSelectedHeight)));
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)valHighlightY)))->FUN_00a09130(2000, m_pSelectedTile, 4002);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)valHighlightY)))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((((FUN_00a09130_shell*)valSelectedHeight)))->FUN_00a09130(2000, m_pSelectedTile, 4016);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((((FUN_00a09410_shell*)valSelectedHeight)))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((((Tile_GetSpeechChallengeFailure_helper*)m_pSelectedTile)))->GetSpeechChallengeFailure())
            {
                Tile* box = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(m_pListTile), str_0106f898)));
                if (box != 0)
                {
                    Tile* child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child != 0)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TileX2*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TileX2*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TileX2*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TileX2*)child)))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)box)))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((((TileX2*)box)))->FUN_00a07530(8);
                }
            }
            else
            {
                Tile* box = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(m_pListTile), str_0106f898)));
                if (box != 0)
                {
                    Tile* child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f894));
                    if (child != 0)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TileX2*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f88c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TileX2*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f884));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TileX2*)child)))->FUN_00a07530(8);
                        child = reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((Tile_GetChildByName_helper*)box)))->FUN_00a03da0((char *)(str_0106f87c));
                        reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)child)))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((((TileX2*)child)))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((((Tile_FUN_0071aa60_helper*)box)))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((((TileX2*)box)))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)m_pListTile)))->Set(traitHighlightY, -1);
            reinterpret_cast<::Tile *>((((Tile_Set_helper*)m_pListTile)))->Set(traitSelectedHeight, 0);
        }
    }
}

namespace fnv_007d9ac0 {
struct TileObj
{
    virtual int FirstVirtual(int);
};
struct SubObjX
{
    int FUN_004459e0(int);
};
struct ListBoxItem_t
{
    TileObj* f0;
    SubObjX* f4;
    unsigned char f8;
};
struct FUN_004ee7d0_node
{
    ListBoxItem_t* item;
    FUN_004ee7d0_node* next;
};
struct TileCX
{
};
struct IMObjX
{
};

struct LBThis
{
    void* vtbl;
    FUN_004ee7d0_node head;
    TileCX* container;
    TileObj* selected;
    void UpdateSaveLoadList();
    bool RemoveItemNode(FUN_004ee7d0_node* p1, FUN_004ee7d0_node* p2);
};

// @fnv 0x007d9ac0
bool LBThis::RemoveItemNode(FUN_004ee7d0_node* pNodeToRemove, FUN_004ee7d0_node* p2)
{
    if (pNodeToRemove)
    {
        TileObj* selObj;
        TileObj* selTmp;
        SubObjX* elemA;
        SubObjX* had;
        ListBoxItem_t* itemB;
        if ((*((::fnv_007d9ac0::ListBoxItem_t **)(new ((void *)(pNodeToRemove)) ::Vec3())))->f0 == selected)
        {
            selected = ((::fnv_007d9ac0::FUN_004ee7d0_node *)(reinterpret_cast<::Callees *>((pNodeToRemove))->FUN_00726070())) ? (*((::fnv_007d9ac0::ListBoxItem_t **)(new ((void *)(((::fnv_007d9ac0::FUN_004ee7d0_node *)(reinterpret_cast<::Callees *>((pNodeToRemove))->FUN_00726070())))) ::Vec3())))->f0
                                                     : ((p2 && p2 != pNodeToRemove) ? (*((::fnv_007d9ac0::ListBoxItem_t **)(new ((void *)(p2)) ::Vec3())))->f0 : 0);
            if (selected)
            {
                reinterpret_cast<::FocusManager *>((((IMObjX*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00715860((::FocusTile *)((int)selected), 0xfc3, 1);
            }
        }
        if (container && (*((::fnv_007d9ac0::ListBoxItem_t **)(new ((void *)(pNodeToRemove)) ::Vec3())))->f8)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(::FUN_00a01860("_num_filtered"),
                                    reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(::FUN_00a01860("_num_filtered")) - 1.0, true);
        }
        selTmp = (*((::fnv_007d9ac0::ListBoxItem_t **)(new ((void *)(pNodeToRemove)) ::Vec3())))->f0;
        selObj = selTmp;
        (void)(selObj ? selObj->FirstVirtual(1) : 0);
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
        {
            had = (*((::fnv_007d9ac0::ListBoxItem_t **)(new ((void *)(pNodeToRemove)) ::Vec3())))->f4;
            elemA = had;
            (void)(elemA ? elemA->FUN_004459e0(1) : 0);
        }
        itemB = *((::fnv_007d9ac0::ListBoxItem_t **)(new ((void *)(pNodeToRemove)) ::Vec3()));
        ::FUN_00401030(itemB);
        if (pNodeToRemove == (this ? &head : 0))
        {
            if (head.next)
            {
                p2 = head.next;
                head.next = ((::fnv_007d9ac0::FUN_004ee7d0_node *)(reinterpret_cast<::Callees *>((p2))->FUN_00726070()));
                head.item = *((::fnv_007d9ac0::ListBoxItem_t **)(new ((void *)(p2)) ::Vec3()));
                reinterpret_cast<::CombatProcedure *>((p2))->Initialize((::CombatController *)(0));
                FUN_004ee7d0_node* node2 = p2;
                FUN_004ee7d0_node* nodeA = node2;
                (void)(nodeA ? ((int)(reinterpret_cast<::W004702f0 *>((nodeA))->FUN_004702f0(1))) : 0);
            }
            else
            {
                head.item = 0;
            }
        }
        else
        {
            reinterpret_cast<::CombatProcedure *>((p2))->Initialize((::CombatController *)((unsigned int)((::fnv_007d9ac0::FUN_004ee7d0_node *)(reinterpret_cast<::Callees *>((pNodeToRemove))->FUN_00726070()))));
            reinterpret_cast<::CombatProcedure *>((pNodeToRemove))->Initialize((::CombatController *)(0));
            FUN_004ee7d0_node* nodeBTmp = pNodeToRemove;
            FUN_004ee7d0_node* nodeB = nodeBTmp;
            (void)(nodeB ? ((int)(reinterpret_cast<::W004702f0 *>((nodeB))->FUN_004702f0(1))) : 0);
        }
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
        {
            reinterpret_cast<::fnv_007d9590::ListBox_SaveLoad *>(this)->UpdateSaveLoadList();
        }
        return true;
    }
    return false;
}
}  // namespace fnv_007d9ac0

namespace fnv_007e1190 {
struct EntryTile;
struct TileAction
{
};
struct CreatedTile
{
};
struct EntryTile
{
    void FUN_00700320(int trait, int value);
};
struct FUN_007a62e0
{
    EntryTile* tile;
    int data;
    unsigned char selected;
    FUN_007a62e0(EntryTile*, int*);
};
struct EntryListNode
{
    FUN_007a62e0* item;
    EntryListNode* next;
};
struct LBH
{
    void* vtable;
    EntryListNode entries;
    EntryTile* container;
    EntryTile* selected;
    EntryTile* scrollbar;
    const char* templateName;
    unsigned short itemCount;
    EntryTile* FUN_007e1190(int data, const char* text, int comparator, const char* name);
};
// @fnv 0x007e1190
EntryTile* LBH::FUN_007e1190(int data, const char* text, int comparator, const char* name)
{
    if (container && (templateName || name))
    {
        EntryTile* tile = ((::fnv_007e1190::EntryTile *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::fnv_007e1190::CreatedTile *)(reinterpret_cast<::FUN_00a03c90_shell *>((container))->FUN_00a03c90()))))->FUN_00a1ddb0({}, {}, {})));
        if (!reinterpret_cast<::FUN_00a00f30_shell *>((tile))->FUN_00a00f30(0xfaa))
            reinterpret_cast<::Tile *>((tile))->Set(0xfaa, -1);
        if (text)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(0xfc4, (char *)(text), true);
        if (comparator)
        {
            reinterpret_cast<::FUN_00470440 *>(&(entries))->FUN_007a7eb0((::BGSPerkEntry *)(::fnv_007e1190::FUN_007a62e0 *)(new FUN_007a62e0(tile, &data)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(comparator));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::ListBox724 *>(this)->RefreshTiles();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(entries))->FUN_00905820((void *)&(const ::fnv_007e1190::FUN_007a62e0 *const &)(new FUN_007a62e0(tile, &data)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(tile));
                reinterpret_cast<::OwnerProxy *>(this)->FUN_007253a0();
            }
            reinterpret_cast<::Tile *>((tile))->Set(0xfac, itemCount++);
        }
        if (::GetRaceCount((char *)this) == 1 && reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxNumFiltered)), -1)) > 0.0)
        {
            TileAction* value = ((::fnv_007e1190::TileAction *)(reinterpret_cast<::FUN_00a00e90_shell *>((container))->FindTraitValue(0xfb0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((value))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((value))->FUN_00a09130(0x7d0, (::Tile *)(tile), 0xfb0);
            reinterpret_cast<::P03Value *>((value))->AppendFloatAction(0x7d3, reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxNumFiltered)), -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((value))->FUN_00a09410(0);
        }
        return tile;
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_007e1190

struct ContNode;
bool FUN_008256d0(ContNode*);
struct N6815c0
{
};

struct RList71a5 : RemovalList
{
    bool RemoveTile(LBTileObj* tile);
};
// @fnv 0x0071a200
void FunctionOwner::FUN_0071a200(int entryType)
{
    TemporaryList selected;
    {
        ListNode* matched;
        ListNode* current;
        current = this ? &entries : 0;
        for (; current && *((::Entry **)(new ((void *)(current)) ::Vec3())); current = ((::ListNode *)(reinterpret_cast<::Callees *>((current))->FUN_00726070())))
        {
            if ((*((::Entry **)(new ((void *)(current)) ::Vec3())))->property)
            {
                if (((int)(reinterpret_cast<::Twin_0044ddc0 *>(((*((::Entry **)(new ((void *)(current)) ::Vec3())))->property))->GetName())) == entryType)
                {
                    selected.FUN_005ae3d0(((::Entry **)(new ((void *)(current)) ::Vec3())));
                }
            }
        }
        matched = &selected;
        for (; matched && *((::Entry **)(new ((void *)(matched)) ::Vec3())); matched = ((::ListNode *)(reinterpret_cast<::Callees *>((matched))->FUN_00726070())))
        {
            reinterpret_cast<::RList71a5 *>(this)->RemoveTile((::LBTileObj *)((*((::Entry **)(new ((void *)(matched)) ::Vec3())))->id));
        }
    }
    reinterpret_cast<::FileMatchList *>(&(selected))->RemoveAll();
}

// @fnv 0x0071a5c0
bool RList71a5::RemoveTile(LBTileObj* tile)
{
    if (!tile || FUN_008256d0((ContNode*)&item))
        return false;
    RemovalNode* posCur = this;
    RemovalNode* prev = this;
    while (posCur && (*((::RemovalItem **)(new ((void *)(((N6815c0*)posCur))) ::Vec3())))->tile != tile)
    {
        prev = posCur;
        posCur = ((::RemovalNode *)(reinterpret_cast<::Callees *>((posCur))->FUN_00726070()));
    }
    return RemoveNode(posCur, prev);
}

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
// @fnv 0x00722410
Tile118* Box118::FUN_00722410(unsigned int action)
{
    Tile118* pFound = 0;
    int delta8 = 0;
    switch (action)
    {
    case 2:
        delta8 = 1;
        break;
    case 1:
        delta8 = -1;
        break;
    case 15:
        delta8 = scroll ? (int)::InventoryStackRecord::RoundToNearestStep(
                              -reinterpret_cast<::TileListBoxCalls *>((scroll))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((scroll))->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                        : 0;
        break;
    case 16:
        delta8 = scroll ? (int)::InventoryStackRecord::RoundToNearestStep(
                              reinterpret_cast<::TileListBoxCalls *>((scroll))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((scroll))->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                        : 0;
        break;
    }
    if (reinterpret_cast<::C4FD0ListBox *>(this)->FUN_00724fd0() && delta8 && count)
    {
        int maximum = count - 1;
        int iCurrent;
        if (selected)
        {
            int iPrevious = (int)reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfac);
            iCurrent = iPrevious + delta8;
            if (iCurrent < 0)
                iCurrent = 0;
            else if (iCurrent > maximum)
                iCurrent = maximum;
        }
        else
        {
            if (delta8 > 0)
                iCurrent = 0;
            else
                iCurrent = maximum;
        }
        while (true)
        {
            for (Node118* node = this ? &head : 0; !pFound && node && ((::Item118 *)(new ((void *)(node)) ::Vec3())); node = ((::Node118 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>((((::Item118 *)(new ((void *)(node)) ::Vec3()))->tile))->GetFloat(0xfac) == iCurrent)
                    pFound = ((::Item118 *)(new ((void *)(node)) ::Vec3()))->tile;
            }
            if (pFound && !reinterpret_cast<::FUN_00a01230_shell *>((pFound))->IsTraitNonZero(FUN_00a00940(kListBoxEnabled, -1)))
            {
                pFound = 0;
                if (delta8 > 0 && ++iCurrent > maximum)
                {
                    iCurrent = maximum - 1;
                    while ((!pFound || !reinterpret_cast<::FUN_00a01230_shell *>((pFound))->IsTraitNonZero(FUN_00a00940(kListBoxEnabled, -1))) && iCurrent >= 0)
                        pFound = GetTile(iCurrent--, 0);
                    break;
                }
                else if (delta8 < 0 && --iCurrent < 0)
                {
                    iCurrent = 1;
                    while ((!pFound || !reinterpret_cast<::FUN_00a01230_shell *>((pFound))->IsTraitNonZero(FUN_00a00940(kListBoxEnabled, -1))) &&
                           iCurrent <= maximum)
                        pFound = GetTile(iCurrent++, 0);
                    break;
                }
            }
            else
                break;
        }
    }
    return pFound != selected ? pFound : 0;
}

struct Tile_71a
{
    void FUN_00700320(unsigned int auiTrait, int aiValue);
};
struct ListItem_71a
{
    Tile_71a* pTile;
    int unk04;
    bool m_bFiltered;
};
template <class T> struct SimpleList_71a
{
    T m_item;
    SimpleList_71a<T>* m_pkNext;
    T& FUN_006815c0();
    SimpleList_71a<T>* FUN_00726070();
};
struct ListBoxBase_71a
{
    void* m_vtbl;
};
struct ListBox_71a : ListBoxBase_71a, SimpleList_71a<ListItem_71a*>
{
    Tile_71a* m_pListTile;
    Tile_71a* pSelected;
    Tile_71a* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;
    float m_fFirstListValue;
    void UpdateItems();
};
int FUN_00a00940(const char* pcName, int iDefault);
struct TileZ;
struct TileZ
{
    void FUN_00700320(int m_uiSoundID, int iVal);
};
struct ItemZ
{
};
struct ListBoxZ
{
    char pad[0xc];
    TileZ* m_pkTile;
    ItemZ* m_pkItem;
    void FUN_0071a740();
};
// @fnv 0x00719ef0
void InventoryListBox::PopulateInventoryList(InventoryOwner* owner, bool(__cdecl* filter)(InventoryEntry*), int sort,
                                             void(__cdecl* callback)(Tile*, InventoryEntry*), bool split, bool include)
{
    if (!owner || !container || !templateName)
        return;
    ClearItems();
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950(1, true);
    bool a = reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0);
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950(0, false);
    InventoryList* h;
    InventoryChanges* p;
    reinterpret_cast<::FUN_00575510_shell *>((owner))->FUN_00575510(include, (void **)(::InventoryList **)(&h), (::SelectedObject **)(::InventoryChanges **)(&p));
    if (h && p)
    {
        InventoryEntry* entry = ((::InventoryEntry *)(reinterpret_cast<::Host_004d4b00 *>((p))->GetNextInventoryEntry((::Iterator_004d4b00 *)(h))));
        while (entry)
        {
            if (!filter || !filter(entry))
            {
                TESFullName* s;
                unsigned int i;
                Tile* a;
                int p = 0;
                int h = ((int)(reinterpret_cast<::Callees *>((entry))->FUN_00726070()));
                do
                {
                    s = dynamic_cast<TESFullName*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((entry))->GetName())));
                    i = ::FUN_0044a670(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((s))->FUN_00408da0())));
                    char name[128];
                    ::TaskQueueInterface::CopyStringToBuffer(name, i + 1, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((s))->FUN_00408da0())));
                    if (((bool)(reinterpret_cast<::FUN_004bd820_stand *>((entry))->FUN_004bd820())))
                        strcat_s(name, i + 2, "+");
                    if (split)
                    {
                        if (p > 0)
                        {
                            InventoryEntry* single = new InventoryEntry;
                            reinterpret_cast<::FUN_004bc810_cls *>((single))->FUN_004bc810((::FUN_004bc810_cls *)(entry));
                            entry = single;
                            reinterpret_cast<::CombatProcedure *>((entry))->Initialize((::CombatController *)(1));
                        }
                        else if (h > 1)
                        {
                            reinterpret_cast<::CombatProcedure *>((entry))->Initialize((::CombatController *)(1));
                        }
                        ++p;
                    }
                    a = FUN_0071a320(entry, name, sort, 0);
                    if (callback)
                        callback(a, entry);
                } while (split && p < h);
            }
            entry = ((::InventoryEntry *)(reinterpret_cast<::Host_004d4b00 *>((p))->GetNextInventoryEntry((::Iterator_004d4b00 *)(h))));
        }
        delete h;
    }
    if (sort)
        reinterpret_cast<::ListBox_71a *>(this)->UpdateItems();
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950(0, a);
}
// @fnv 0x0071aaa0
bool RemovalList::RemoveNode(RemovalNode* node, RemovalNode* previous)
{
    if (node)
    {
        if ((*((::RemovalItem **)(new ((void *)(node)) ::Vec3())))->tile == selected)
        {
            selected = ((::RemovalNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())) ? (*((::RemovalItem **)(new ((void *)(((::RemovalNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))) ::Vec3())))->tile
                                            : ((previous && previous != node) ? (*((::RemovalItem **)(new ((void *)(previous)) ::Vec3())))->tile : 0);
            if (selected)
                reinterpret_cast<::FocusManager *>((((::RemovalInterface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00715860((::FocusTile *)(selected), 0xfc3, 1);
        }
        if (container && (*((::RemovalItem **)(new ((void *)(node)) ::Vec3())))->counted)
            reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(FUN_00a01860(str_0106f8d0),
                                    reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a01860(str_0106f8d0)) - 1.0, true);
        delete (*((::RemovalItem **)(new ((void *)(node)) ::Vec3())))->tile;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::RemovalItem **)(new ((void *)(node)) ::Vec3())))->extra;
        delete *((::RemovalItem **)(new ((void *)(node)) ::Vec3()));
        if (node == static_cast<RemovalNode*>(this))
        {
            if (next)
            {
                previous = next;
                next = ((::RemovalNode *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
                item = *((::RemovalItem **)(new ((void *)(previous)) ::Vec3()));
                reinterpret_cast<::CombatProcedure *>((previous))->Initialize((::CombatController *)(::RemovalNode *)(0));
                delete previous;
            }
            else
            {
                item = 0;
            }
        }
        else
        {
            reinterpret_cast<::CombatProcedure *>((previous))->Initialize((::CombatController *)(::RemovalNode *)(((::RemovalNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()))));
            reinterpret_cast<::CombatProcedure *>((node))->Initialize((::CombatController *)(::RemovalNode *)(0));
            delete node;
        }
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            reinterpret_cast<::ListBox_71a *>(this)->UpdateItems();
        return true;
    }
    return false;
}
// Resets the item count and a float, assigns trait 0xfac with an incrementing index to each unflagged list item's tile, then calls UpdateScrollPages and FUN_0071a740.
// @fnv 0x0071a670
void ListBox_71a::UpdateItems()
{
    usItemCount = 0;
    m_fFirstListValue = 0.0f;
    for (SimpleList_71a<ListItem_71a*>* pNode = this; pNode && ((::ListItem_71a *)(new ((void *)(pNode)) ::Vec3())); pNode = ((::SimpleList_71a< ::ListItem_71a *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070())))
    {
        if (!((::ListItem_71a *)(new ((void *)(pNode)) ::Vec3()))->m_bFiltered)
        {
            reinterpret_cast<::Tile *>((((::ListItem_71a *)(new ((void *)(pNode)) ::Vec3()))->pTile))->Set(0xfac, usItemCount++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(((::ListItem_71a *)(new ((void *)(pNode)) ::Vec3()))->pTile));
        }
    }
    reinterpret_cast<::ListBox_71ad30 *>(this)->UpdateScrollPages();
    reinterpret_cast<::ListBoxZ *>(this)->FUN_0071a740();
}
// Sets highlight and selected-height properties from m_pkItem, then sets the highlight box and its sides visible according to the item's boolean result.
// @fnv 0x0071a740
void ListBoxZ::FUN_0071a740()
{
    static int s_iHighlightY = FUN_00a00940("_highlight_y", -1);
    static int s_iSelectedHeight = FUN_00a00940("_selected_height", -1);
    if (m_pkTile)
    {
        if (m_pkItem)
        {
            TileZ* pkHighlight_zkij = ((::TileZ *)(reinterpret_cast<::FUN_00a00f30_shell *>((m_pkTile))->FUN_00a00f30(s_iHighlightY)));
            TileZ* pkHeight_dxa = ((::TileZ *)(reinterpret_cast<::FUN_00a00f30_shell *>((m_pkTile))->FUN_00a00f30(s_iSelectedHeight)));
            reinterpret_cast<::AGOwner *>((pkHighlight_zkij))->FUN_00a09130(0x7d0, (::Tile *)(m_pkItem), 0xfa2);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pkHighlight_zkij))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((pkHeight_dxa))->FUN_00a09130(0x7d0, (::Tile *)(m_pkItem), 0xfb0);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pkHeight_dxa))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((m_pkItem))->GetSpeechChallengeFailure())
            {
                TileZ* pkBox = ((::TileZ *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(m_pkTile), "lb_highlight_box")));
                if (pkBox)
                {
                    TileZ* pkSide = ((::TileZ *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pkBox))->FUN_00a03da0((char *)("top"))));
                    if (pkSide)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((pkSide))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pkSide))->FUN_00a07530(8);
                        pkSide = ((::TileZ *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pkBox))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pkSide))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pkSide))->FUN_00a07530(8);
                        pkSide = ((::TileZ *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pkBox))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pkSide))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pkSide))->FUN_00a07530(8);
                        pkSide = ((::TileZ *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pkBox))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pkSide))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((pkSide))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((pkBox))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((pkBox))->FUN_00a07530(8);
                }
            }
            else
            {
                TileZ* pkBox = ((::TileZ *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(m_pkTile), "lb_highlight_box")));
                if (pkBox)
                {
                    TileZ* pkSide = ((::TileZ *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pkBox))->FUN_00a03da0((char *)("top"))));
                    if (pkSide)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((pkSide))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pkSide))->FUN_00a07530(8);
                        pkSide = ((::TileZ *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pkBox))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pkSide))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pkSide))->FUN_00a07530(8);
                        pkSide = ((::TileZ *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pkBox))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pkSide))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pkSide))->FUN_00a07530(8);
                        pkSide = ((::TileZ *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pkBox))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((pkSide))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((pkSide))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((pkBox))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((pkBox))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((m_pkTile))->Set(s_iHighlightY, -1);
            reinterpret_cast<::Tile *>((m_pkTile))->Set(s_iSelectedHeight, 0);
        }
    }
}

int __cdecl FUN_00a00940(const char* name, int fallback);

// Returns whether m_pScrollBar exists and has the trait identified by str_01070244 set to a non-zero value.
// @fnv 0x00724a00
bool Class_721c60::IsScrollBarTraitEnabled()
{
    static int enabledTrait = FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1);
    return m_pScrollBar && reinterpret_cast<::FUN_00a01230_shell *>((m_pScrollBar))->IsTraitNonZero(enabledTrait);
}

struct FUN_007d7670_Tile
{
};
struct FUN_007d7670_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_007d7670_Tile* m_pkSelected;

    bool FUN_007d7670(FUN_007d7670_Tile* pkTile);
};
// When the class is active, assigns pkTile if null or contained with a nonzero trait, then updates the highlight box.
// @fnv 0x007d7670
bool FUN_007d7670_cls::FUN_007d7670(FUN_007d7670_Tile* pkTile)
{
    if (reinterpret_cast<::D7580ListBox *>(this)->FUN_007d7580() && (!pkTile || (reinterpret_cast<::ListOwner *>(this)->ContainsKey((int)(pkTile)) && reinterpret_cast<::FUN_00a01230_shell *>((pkTile))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1)))))
    {
        m_pkSelected = pkTile;
        reinterpret_cast<::ListBoxExt *>(this)->UpdateHighlightBox();
        return true;
    }
    else
    {
        return false;
    }
}

namespace list71a {
struct L71Tile;
struct L71Value
{
};
struct L71Created;
struct L71Tile
{
    void FUN_00700320(int id, int value);
};
struct L71Created
{
};
struct L71Item
{
    int unk00;
    int unk04;
    int unk08;
    L71Item(L71Tile* tile, int& data);
};
struct L71List
{
    int unk00;
    int unk04;
};
struct L71Menu
{
    int unk00;
    L71List kItems;
    L71Tile* pRoot;
    int unk10;
    int unk14;
    L71Tile* pTemplate;
    unsigned short m_usPassCountLocal;
    L71Tile* FUN_0071a320(int data, const char* text, int (*compare)(L71Item*, L71Item*), L71Tile* tmpl);
};
}
using namespace list71a;

// Creates a tile under pRoot, optionally sets trait 0xfc4, inserts it into kItems, and updates menu layout and trait 0xfb0.
// @fnv 0x0071a320
L71Tile* L71Menu::FUN_0071a320(int data, const char* apLabel, int (*compare)(L71Item*, L71Item*), L71Tile* apTemplate)
{
    L71Tile* pTile;
    L71Value* pTraitValue;

    if (pRoot && (pTemplate || apTemplate))
    {
        pTile = ((::list71a::L71Tile *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::list71a::L71Created *)(reinterpret_cast<::FUN_00a03c90_shell *>((pRoot))->FUN_00a03c90()))))->FUN_00a1ddb0({}, {}, {})));
        if (!((int)(reinterpret_cast<::FUN_00a00f30_shell *>((pTile))->FUN_00a00f30(0xfaa))))
        {
            reinterpret_cast<::Tile *>((pTile))->Set(0xfaa, -1);
        }
        if (apLabel)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pTile))->FUN_00a01350(0xfc4, (char *)(apLabel), 1);
        }
        if (compare)
        {
            reinterpret_cast<::FUN_00470440 *>(&(kItems))->FUN_007a7eb0((::BGSPerkEntry *)(::list71a::L71Item *)(new L71Item(pTile, data)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(compare));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::ListBox_71a *>(this)->UpdateItems();
            }
        }
        else
        {
            reinterpret_cast<::Callees *>(&(kItems))->FUN_00905820((void *)&(const ::list71a::L71Item *const &)(new L71Item(pTile, data)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(pTile));
                reinterpret_cast<::ListBox_71ad30 *>(this)->UpdateScrollPages();
            }
            reinterpret_cast<::Tile *>((pTile))->Set(0xfac, m_usPassCountLocal++);
        }
        if (::GetRaceCount((char *)this) == 1 && reinterpret_cast<::TileListBoxCalls *>((pRoot))->GetFloat(FUN_00a00940("_number_of_visible_items", -1)) > 0.0)
        {
            pTraitValue = ((::list71a::L71Value *)(reinterpret_cast<::FUN_00a00e90_shell *>((pRoot))->FindTraitValue(0xfb0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((pTraitValue))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((pTraitValue))->FUN_00a09130(0x7d0, (::Tile *)(pTile), 0xfb0);
            reinterpret_cast<::P03Value *>((pTraitValue))->AppendFloatAction(0x7d3, reinterpret_cast<::TileListBoxCalls *>((pRoot))->GetFloat(FUN_00a00940("_number_of_visible_items", -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pTraitValue))->FUN_00a09410(0);
        }
        return pTile;
    }
    else
    {
        return 0;
    }
}

namespace scroll722 {
struct S722Tile
{
};
struct S722Entry
{
    S722Tile* pTile;
};
struct S722Node
{
    S722Entry* pItem;
    S722Node* pNext;
};
struct MenuBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual S722Tile* GetItemTile(int index, int a);
};
struct S722Menu : public MenuBase, public S722Node
{
    S722Tile* m_pHighlightedTile;
    S722Tile* pSelected;
    int unk14;
    int unk18;
    unsigned short m_usPassCountLocal;
    S722Tile* FUN_00722bc0(int code);
};
}
using namespace scroll722;

// Finds a tile at the index offset derived from code and returns it unless it matches pSelected.
// @fnv 0x00722bc0
S722Tile* S722Menu::FUN_00722bc0(int code)
{
    S722Tile* pFound5 = 0;
    int iDelta = 0;

    switch (code)
    {
    case 2:
        iDelta = 1;
        break;
    case 1:
        iDelta = -1;
        break;
    case 15:
        iDelta = m_pHighlightedTile
                     ? (int)::InventoryStackRecord::RoundToNearestStep(-reinterpret_cast<::TileListBoxCalls *>((m_pHighlightedTile))->GetFloat(0xfb0) /
                                             reinterpret_cast<::TileListBoxCalls *>((m_pHighlightedTile))->GetFloat(FUN_00a01860("_scroll_delta")),
                                         1.0f)
                     : 0;
        break;
    case 16:
        iDelta = m_pHighlightedTile
                     ? (int)::InventoryStackRecord::RoundToNearestStep(reinterpret_cast<::TileListBoxCalls *>((m_pHighlightedTile))->GetFloat(0xfb0) /
                                             reinterpret_cast<::TileListBoxCalls *>((m_pHighlightedTile))->GetFloat(FUN_00a01860("_scroll_delta")),
                                         1.0f)
                     : 0;
        break;
    }
    if (((bool)(reinterpret_cast<::FUN_007255a0_cls *>(this)->FUN_007255a0())) && iDelta && m_usPassCountLocal)
    {
        int iLastB = m_usPassCountLocal - 1;
        int iIndex;
        if (pSelected)
        {
            int iCurrent5 = (int)reinterpret_cast<::TileListBoxCalls *>((pSelected))->GetFloat(0xfac);
            if ((iIndex = iCurrent5 + iDelta) < 0)
            {
                iIndex = 0;
            }
            else if (iIndex > iLastB)
            {
                iIndex = iLastB;
            }
        }
        else if (iDelta > 0)
        {
            iIndex = 0;
        }
        else
        {
            iIndex = iLastB;
        }
        while (1)
        {
            for (S722Node* pNode4 = this; !pFound5 && pNode4 && *((::scroll722::S722Entry **)(new ((void *)(pNode4)) ::Vec3()));
                 pNode4 = ((::scroll722::S722Node *)(reinterpret_cast<::Callees *>((pNode4))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*((::scroll722::S722Entry **)(new ((void *)(pNode4)) ::Vec3())))->pTile))->GetFloat(0xfac) == iIndex)
                {
                    pFound5 = (*((::scroll722::S722Entry **)(new ((void *)(pNode4)) ::Vec3())))->pTile;
                }
            }
            if (pFound5 && !reinterpret_cast<::FUN_00a01230_shell *>((pFound5))->IsTraitNonZero(FUN_00a00940("_enabled", -1)))
            {
                pFound5 = 0;
                if (iDelta > 0 && ++iIndex > iLastB)
                {
                    iIndex = iLastB - 1;
                    while ((!pFound5 || !reinterpret_cast<::FUN_00a01230_shell *>((pFound5))->IsTraitNonZero(FUN_00a00940("_enabled", -1))) && iIndex >= 0)
                    {
                        pFound5 = GetItemTile(iIndex--, 0);
                    }
                    break;
                }
                else if (iDelta < 0 && --iIndex < 0)
                {
                    iIndex = 1;
                    while ((!pFound5 || !reinterpret_cast<::FUN_00a01230_shell *>((pFound5))->IsTraitNonZero(FUN_00a00940("_enabled", -1))) && iIndex <= iLastB)
                    {
                        pFound5 = GetItemTile(iIndex++, 0);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return pFound5 != pSelected ? pFound5 : 0;
}

struct LBTile_7314c0
{
};
struct LBItem_7314c0
{
    LBTile_7314c0* tile;
    void* object;
};
struct LBNode_7314c0
{
    LBItem_7314c0* item;
    LBNode_7314c0* next;
};
struct LBBase_7314c0
{
    virtual void VFunc00();
};
struct LBList_7314c0 : LBBase_7314c0, LBNode_7314c0
{
    void FUN_007314c0(void(__cdecl* callback)(LBTile_7314c0*, void*), int minIndex, int maxIndex);
};
// Iterates the linked list, calling callback on each tile whose index is within [minIndex, maxIndex).
// @fnv 0x007314c0
void LBList_7314c0::FUN_007314c0(void(__cdecl* callback)(LBTile_7314c0*, void*), int minIndex, int maxIndex)
{
    for (LBNode_7314c0* node = this;
         node && *((::LBItem_7314c0 **)(new ((void *)(node)) ::Vec3())) && (int)reinterpret_cast<::TileListBoxCalls *>(((*((::LBItem_7314c0 **)(new ((void *)(node)) ::Vec3())))->tile))->GetFloat(0xFAC) < maxIndex;
         node = ((::LBNode_7314c0 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        if ((int)reinterpret_cast<::TileListBoxCalls *>(((*((::LBItem_7314c0 **)(new ((void *)(node)) ::Vec3())))->tile))->GetFloat(0xFAC) >= minIndex)
            callback((*((::LBItem_7314c0 **)(new ((void *)(node)) ::Vec3())))->tile, (*((::LBItem_7314c0 **)(new ((void *)(node)) ::Vec3())))->object);
    }
}

namespace scroll764 {
struct S764Tile
{
};
struct S764Entry
{
    S764Tile* pTile;
};
struct S764Node
{
    S764Entry* pItem;
    S764Node* pNext;
};
struct MenuBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual S764Tile* GetItemTile(int index, int a);
};
struct S764Menu : public MenuBase, public S764Node
{
    S764Tile* m_pHighlightedTile;
    S764Tile* pSelected;
    int unk14;
    int unk18;
    unsigned short m_usPassCountLocal;
    S764Tile* FUN_00764a70(int code);
};
}
using namespace scroll764;

// Finds an enabled tile at an index offset derived from code and returns it, or 0 if it matches pSelected.
// @fnv 0x00764a70
S764Tile* S764Menu::FUN_00764a70(int aiScrollCode)
{
    S764Tile* pFound5 = 0;
    int iDelta = 0;

    switch (aiScrollCode)
    {
    case 2:
        iDelta = 1;
        break;
    case 1:
        iDelta = -1;
        break;
    case 15:
        iDelta = m_pHighlightedTile
                     ? (int)::InventoryStackRecord::RoundToNearestStep(-reinterpret_cast<::TileListBoxCalls *>((m_pHighlightedTile))->GetFloat(0xfb0) /
                                             reinterpret_cast<::TileListBoxCalls *>((m_pHighlightedTile))->GetFloat(FUN_00a01860("_scroll_delta")),
                                         1.0f)
                     : 0;
        break;
    case 16:
        iDelta = m_pHighlightedTile
                     ? (int)::InventoryStackRecord::RoundToNearestStep(reinterpret_cast<::TileListBoxCalls *>((m_pHighlightedTile))->GetFloat(0xfb0) /
                                             reinterpret_cast<::TileListBoxCalls *>((m_pHighlightedTile))->GetFloat(FUN_00a01860("_scroll_delta")),
                                         1.0f)
                     : 0;
        break;
    }
    if (reinterpret_cast<::Cls_764e40 *>(this)->FUN_00764e40() && iDelta && m_usPassCountLocal)
    {
        int iLastB = m_usPassCountLocal - 1;
        int iIndex;
        if (pSelected)
        {
            int iCurrent5 = (int)reinterpret_cast<::TileListBoxCalls *>((pSelected))->GetFloat(0xfac);
            if ((iIndex = iCurrent5 + iDelta) < 0)
            {
                iIndex = 0;
            }
            else if (iIndex > iLastB)
            {
                iIndex = iLastB;
            }
        }
        else if (iDelta > 0)
        {
            iIndex = 0;
        }
        else
        {
            iIndex = iLastB;
        }
        while (1)
        {
            for (S764Node* pNode4 = this; !pFound5 && pNode4 && *((::scroll764::S764Entry **)(new ((void *)(pNode4)) ::Vec3()));
                 pNode4 = ((::scroll764::S764Node *)(reinterpret_cast<::Callees *>((pNode4))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*((::scroll764::S764Entry **)(new ((void *)(pNode4)) ::Vec3())))->pTile))->GetFloat(0xfac) == iIndex)
                {
                    pFound5 = (*((::scroll764::S764Entry **)(new ((void *)(pNode4)) ::Vec3())))->pTile;
                }
            }
            if (pFound5 && !reinterpret_cast<::FUN_00a01230_shell *>((pFound5))->IsTraitNonZero(FUN_00a00940("_enabled", -1)))
            {
                pFound5 = 0;
                if (iDelta > 0 && ++iIndex > iLastB)
                {
                    iIndex = iLastB - 1;
                    while ((!pFound5 || !reinterpret_cast<::FUN_00a01230_shell *>((pFound5))->IsTraitNonZero(FUN_00a00940("_enabled", -1))) && iIndex >= 0)
                    {
                        pFound5 = GetItemTile(iIndex--, 0);
                    }
                    break;
                }
                else if (iDelta < 0 && --iIndex < 0)
                {
                    iIndex = 1;
                    while ((!pFound5 || !reinterpret_cast<::FUN_00a01230_shell *>((pFound5))->IsTraitNonZero(FUN_00a00940("_enabled", -1))) && iIndex <= iLastB)
                    {
                        pFound5 = GetItemTile(iIndex++, 0);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return pFound5 != pSelected ? pFound5 : 0;
}

int __cdecl FUN_00a00940(const char* name, int len);
struct TileChk_a3f90
{
};
struct MenuChk_a3f90
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    TileChk_a3f90* unk10;
    bool FUN_007a3f90(TileChk_a3f90* tile);
};
// If FUN_007a7330 is true and tile is null or contained with a nonzero trait, assigns unk10, calls FUN_007a73e0, and returns true.
// @fnv 0x007a3f90
bool MenuChk_a3f90::FUN_007a3f90(TileChk_a3f90* tile)
{
    if (((bool)(reinterpret_cast<::FUN_007a7330_cls *>(this)->FUN_007a7330())) && (!tile || (reinterpret_cast<::ListOwner *>(this)->ContainsKey((int)(tile)) && reinterpret_cast<::FUN_00a01230_shell *>((tile))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1)))))
    {
        unk10 = tile;
        reinterpret_cast<::fnv_007a73e0::HighlightList *>(this)->FUN_007a73e0();
        return true;
    }
    else
    {
        return false;
    }
}

namespace menu7a5 {
struct FUN_007240c0
{
    FUN_007240c0();
    virtual void v00();
};
struct FUN_0096a2d0
{
    int unk00;
    int unk04;
    FUN_0096a2d0();
    ~FUN_0096a2d0();
};
struct FUN_007a50f0 : public FUN_007240c0, public FUN_0096a2d0
{
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_usPassCountLocal;
    short unk1e;
    float fX;
    float fY;
    float fZ;
    unsigned short usIndex;
    FUN_007a50f0();
    virtual void v00();
};

}
using namespace menu7a5;

// @fnv 0x007a50f0
FUN_007a50f0::FUN_007a50f0()
{
    unk14 = 0;
    unk10 = 0;
    unk0c = 0;
    unk18 = 0;
    usIndex = 0;
    m_usPassCountLocal = 0;
    fZ = 0.0f;
    fY = 0.0f;
    fX = 0.0f;
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950(0, 1);
    ::AddToHeadList((int *)(::menu7a5::FUN_007240c0 *)(this));
}

struct Target_007a5a60
{
};

struct Owner_007a5a60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Target_007a5a60* m_pkTarget;
    bool FUN_007a5a60(Target_007a5a60* pkTarget);
};

// When FUN_007a81b0 is true and pkTarget is null or contained with a nonzero _enabled trait, assigns m_pkTarget and calls UpdateHighlight.
// @fnv 0x007a5a60
bool Owner_007a5a60::FUN_007a5a60(Target_007a5a60* pkTarget)
{
    if (reinterpret_cast<::FUN_007a81b0_cls *>(this)->FUN_007a81b0() &&
        (!pkTarget || (reinterpret_cast<::ListOwner *>(this)->ContainsKey((int)(pkTarget)) && reinterpret_cast<::FUN_00a01230_shell *>((pkTarget))->IsTraitNonZero(FUN_00a00940("_enabled", -1)))))
    {
        m_pkTarget = pkTarget;
        reinterpret_cast<::HighlightList *>(this)->UpdateHighlight_007a8260();
        return true;
    }
    else
    {
        return false;
    }
}

struct Tile_7d76e0
{
};
struct Item_7d76e0
{
    Tile_7d76e0* tile;
};
struct Node_7d76e0
{
    Item_7d76e0* item;
    Node_7d76e0* next;
};
struct Base_7d76e0
{
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual Tile_7d76e0* VFunc14(int index, bool flag);
};
struct Class_7d76e0 : Base_7d76e0, Node_7d76e0
{
    Tile_7d76e0* container;
    Tile_7d76e0* selected;
    Tile_7d76e0* scrollbar;
    const char* templateName;
    unsigned short count;

    Tile_7d76e0* FUN_007d76e0(int action);
};

// Finds a tile at the index offset derived from action and returns it unless it matches selected.
// @fnv 0x007d76e0
Tile_7d76e0* Class_7d76e0::FUN_007d76e0(int action)
{
    Tile_7d76e0* result = 0;
    int delta = 0;
    switch (action)
    {
    case 2:
        delta = 1;
        break;
    case 1:
        delta = -1;
        break;
    case 15:
        delta = container
                    ? (int)::InventoryStackRecord::RoundToNearestStep(
                          -reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a01860(str_0106f90c)), 1.0f)
                    : 0;
        break;
    case 16:
        delta = container
                    ? (int)::InventoryStackRecord::RoundToNearestStep(
                          reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(FUN_00a01860(str_0106f90c)), 1.0f)
                    : 0;
        break;
    }
    if (reinterpret_cast<::D7580ListBox *>(this)->FUN_007d7580() && delta != 0 && count != 0)
    {
        int newIdx;
        int maxIdx = count - 1;
        int curIdx;
        if (selected != 0)
        {
            curIdx = (int)reinterpret_cast<::TileListBoxCalls *>((selected))->GetFloat(0xfac);
            if ((newIdx = curIdx + delta) < 0)
            {
                newIdx = 0;
            }
            else if (newIdx > maxIdx)
            {
                newIdx = maxIdx;
            }
        }
        else
        {
            if (delta > 0)
            {
                newIdx = 0;
            }
            else
            {
                newIdx = maxIdx;
            }
        }
        while (true)
        {
            Node_7d76e0* node;
            for (node = this; !result && node && *((::Item_7d76e0 **)(new ((void *)(node)) ::Vec3())); node = ((::Node_7d76e0 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>(((*((::Item_7d76e0 **)(new ((void *)(node)) ::Vec3())))->tile))->GetFloat(0xfac) == newIdx)
                {
                    result = (*((::Item_7d76e0 **)(new ((void *)(node)) ::Vec3())))->tile;
                }
            }
            if (result && !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1)))
            {
                result = 0;
                if (delta > 0 && ++newIdx > maxIdx)
                {
                    newIdx = maxIdx - 1;
                    while ((!result || !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1))) && newIdx >= 0)
                    {
                        result = VFunc14(newIdx--, false);
                    }
                    break;
                }
                else if (delta < 0 && (newIdx -= 1) < 0)
                {
                    newIdx = 1;
                    while ((!result || !reinterpret_cast<::FUN_00a01230_shell *>((result))->IsTraitNonZero(FUN_00a00940((*reinterpret_cast<char (*)[]>((void *)&::kListBoxEnabled)), -1))) && newIdx <= maxIdx)
                    {
                        result = VFunc14(newIdx++, false);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return result != selected ? result : 0;
}

extern int FUN_01070418[];

struct FUN_007240c0_shell
{
    int* vtable;
    void* FUN_007240c0();
};

// @fnv 0x007240c0
void* FUN_007240c0_shell::FUN_007240c0()
{
    vtable = FUN_01070418;
    return this;
}

struct FUN_00723f80
{
    virtual ~FUN_00723f80();
};

FUN_00723f80::~FUN_00723f80()
{}

struct FUN_00724200 : FUN_00723f80
{
    virtual ~FUN_00724200();
};

// @fnv 0x00724200
FUN_00724200::~FUN_00724200()
{}

int __cdecl strcpy_s(char*, unsigned int, const char*);

struct TileValue_00a0a270;
struct TileValueOwner_00a01000
{
};

class AGMemoryManager
{
  public:
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
#include "generated/data/fallout/interface/listbox.inc"
#include "generated/data/fallout/interface/listbox_ob1_variant.inc"
