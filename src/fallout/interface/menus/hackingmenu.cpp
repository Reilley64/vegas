
// src/fallout/interface/menus/hackingmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/hackingmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include <cctype>
#include <cstdint>
#include <cstring>
#include "fnv/decl/ActorValueOwner.h"
#include "fnv/decl/AudioClass_ae5680.h"
#include "fnv/decl/B766A50Menu.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004ed8c0_shell.h"
#include "fnv/decl/FUN_00501270_shell.h"
#include "fnv/decl/FUN_00700110_cls.h"
#include "fnv/decl/FUN_007079f0_shell.h"
#include "fnv/decl/FUN_007190e0_cls.h"
#include "fnv/decl/FUN_00726d50_class.h"
#include "fnv/decl/FUN_00757e80_shell.h"
#include "fnv/decl/FUN_00759d80_Class.h"
#include "fnv/decl/FUN_00759f20_shell.h"
#include "fnv/decl/FUN_00766a10_shell.h"
#include "fnv/decl/FUN_0076b560.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_007ffaf0_shell.h"
#include "fnv/decl/FUN_00a00e90_shell.h"
#include "fnv/decl/FUN_00a00f30_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a013d0_shell.h"
#include "fnv/decl/FUN_00a01440_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/HKMenu.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/Menu.h"
#include "fnv/decl/NiPick.h"
#include "fnv/decl/NiTPointerListBase.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/PlayerCharShell.h"
#include "fnv/decl/S8840.h"
#include "fnv/decl/ScriptList.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/SystemColorManager.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TermHack.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TopicMenuController.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/TwTypewriter.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008c0ec0__Target.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_00501000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005a0000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00670000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_00757000.h"
#include "fnv/symbols_0076b000.h"
#include "fnv/symbols_007ff000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a04000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0119f000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
struct FUN_006ffe80_shell
{
    int x;
    int y;
    int a;
    int b;
    void FUN_006ffe80(int a, int b);
public:
    void FUN_006ffe10();
};

// @fnv 0x006ffe80
void FUN_006ffe80_shell::FUN_006ffe80(int aiFirst, int aiSecond)
{
    this->a = aiFirst;
    this->b = aiSecond;
}

struct HackingMenu
{
    int FUN_00765870();
};

// @fnv 0x00765870
int HackingMenu::FUN_00765870()
{
    return 0x41f;
}

namespace fnv_00765880 {
struct Tile;

struct HackingMenu
{
    unsigned char m_00[0x10c];
    Tile* m_pTiles[32];
    void SetTile(int aiID, Tile* apTile);
};

// Stores apTile into the tile slot array at index aiID when aiID is in [0, 8).
// @fnv 0x00765880
void HackingMenu::SetTile(int aiID, Tile* apTile)
{
    if (aiID >= 0 && aiID < 8)
    {
        m_pTiles[aiID] = apTile;
    }
}
}  // namespace fnv_00765880

namespace fnv_007658b0 {

struct HackingMenu
{
    HackingMenu();
    ~HackingMenu();
    void* Destroy(unsigned int flags);
};

// Calls the HackingMenu destructor and, when bit 0 of flags is set, deallocates this; returns this.
// @fnv 0x007658b0
void* HackingMenu::Destroy(unsigned int flags)
{
    HackingMenu::~HackingMenu();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_007658b0

// @fnv 0x00766a40
int __cdecl FUN_00766a40()
{
    return 0x41f;
}

namespace fnv_00767ff0 {
struct HackingMenu
{
    HackingMenu();
    void ClearTilePayloadPair();
    void FUN_00767ff0(int, void*);
    // ...
    bool m_bHackingInProgress;
    void* coordinate;
};

// @fnv 0x00767ff0
void HackingMenu::FUN_00767ff0(int aiID, void* apTarget)
{
    ClearTilePayloadPair();
    ((char*)this)[0x1d8] = 0;
    *(int*)((char*)this + 0x1c0) = 0;
}
}  // namespace fnv_00767ff0

struct WeatherEntry;

struct BSSimpleList
{
};


struct FUN_007687b0_shell : BSSimpleList
{
    void SortWeatherEntries();
};

// @fnv 0x007687b0
void FUN_007687b0_shell::SortWeatherEntries()
{
    reinterpret_cast<::ItemChangeList *>((this))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(int (*)(WeatherEntry *, WeatherEntry *))(&((int (&)(WeatherEntry *, WeatherEntry *))::FUN_0076b2e0)));
}

// Returns the larger of the two unsigned byte arguments.
// @fnv 0x0076af60
char MaxByte(unsigned char a, unsigned char b)
{
    return a > b ? a : b;
}


// @fnv 0x0076b2e0
unsigned int __cdecl FUN_0076b2e0()
{
    return ::FUN_005a00a0(2) * 2 - 1;
}

class FORenderedMenu;
class Tile;
struct InterfaceManager
{
    static float __cdecl UpdateInterfaceState();
    int FUN_00747d00();
public:
    ::Tile *FUN_00586150();
public:
    ::FORenderedMenu *GetActiveRenderedMenu();
};

// @fnv 0x00747d00
int InterfaceManager::FUN_00747d00()
{
    return (int)(UpdateInterfaceState() / 2.0 + *(float*)((char*)this + 0x2c));
}


struct HackingMenu;

struct FUN_0076a510_shell : HackingMenu
{
    void FUN_0076a510();
    void FUN_0076a540();
};

// Calls FUN_0076a540 when gm_GetTickCount() exceeds the tick value stored at this+0x1d0.
// @fnv 0x0076a510
void FUN_0076a510_shell::FUN_0076a510()
{
    if (((unsigned int)(::FUN_00457fe0())) > *(unsigned int*)((char*)this + 0x1d0))
    {
        FUN_0076a540();
    }
}

struct StrMem
{
    StrMem();
    ~StrMem();
};
struct FUN_00726c90 : StrMem
{
    FUN_00726c90();
};
// Constructs the object by calling FUN_006ffe10.
// @fnv 0x00726c90
FUN_00726c90::FUN_00726c90()
{
    reinterpret_cast<::FUN_006ffe80_shell *>(this)->FUN_006ffe10();
}

struct ListX
{
    ~ListX();
};
struct FUN_00765810 : ListX
{
    void FreeAll();
    ~FUN_00765810();
};
// @fnv 0x00765810
FUN_00765810::~FUN_00765810()
{
    FreeAll();
}

struct FUN_0076b560_shell
{
    void* FUN_00765b50(unsigned int flags);
};
// Calls FUN_0076b560, then frees this with Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00765b50
void* FUN_0076b560_shell::FUN_00765b50(unsigned int flags)
{
    reinterpret_cast<::FUN_0076b560 *>(this)->FUN_0076b560::~FUN_0076b560();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void __cdecl UpdateD766AA0Menu();
struct FUN_00767b80_shell
{
    bool HandleButton10(int, float);
};
// If aiButton is 10, stores 4 at offset 0x1c4, calls UpdateD766AA0Menu and returns true; otherwise returns false.
// @fnv 0x00767b80
bool FUN_00767b80_shell::HandleButton10(int aiButton, float afValue)
{
    if (aiButton == 10)
    {
        *(int*)((char*)this + 0x1c4) = 4;
        UpdateD766AA0Menu();
        return true;
    }
    return false;
}

struct T7021b0
{
};
struct C7687d0
{
    void FUN_007687d0();
};

struct FUN_00768920_shell
{
    void* p;
    void* q;
    void FUN_00768920(void* n);
};
// @fnv 0x00768920
void FUN_00768920_shell::FUN_00768920(void* n)
{
    void* pOldBuffer = p;
    void* pNewBuffer;
    ::FUN_00401030(pOldBuffer);
    q = n;
    pNewBuffer = ::FUN_00401000((unsigned int)n);
    p = pNewBuffer;
}

struct FUN_00768a10_shell : HackingMenu
{
    unsigned int CountMatchingChars(const char* a, const char* b);
};
// Returns 0 if either string is null, otherwise counts positions up to the shorter length where the two strings have equal characters.
// @fnv 0x00768a10
unsigned int FUN_00768a10_shell::CountMatchingChars(const char* pcStringA, const char* pcStringB)
{
    if (!pcStringA || !pcStringB)
        return 0;
    unsigned int icnt = 0;
    unsigned int ilen = FUN_0042f5a0(::FUN_0044a670(pcStringA), ::FUN_0044a670(pcStringB));
    for (unsigned int i = 0; i < ilen; ++i)
    {
        if (pcStringA[i] == pcStringB[i])
            ++icnt;
    }
    return icnt;
}

struct FUN_007694f0_shell
{
    void FUN_00726c90();
    int FUN_007694f0();
};

// Calls FUN_00726c90, then zeroes the int fields at offsets 0x30 and 0x2c and returns this.
// @fnv 0x007694f0
int FUN_007694f0_shell::FUN_007694f0()
{
    new ((void *)this) ::FUN_00726c90();
    *(int*)((char*)this + 0x30) = 0;
    *(int*)((char*)this + 0x2c) = 0;
    return (int)this;
}

struct Struct0076ae30
{
    unsigned char* buf;
    unsigned int cnt;
    int FindByteIndices(int, unsigned char*);
};
// Scans buf for bytes equal to v, writes their indices into out, and returns how many were found.
// @fnv 0x0076ae30
int Struct0076ae30::FindByteIndices(int aiValue, unsigned char* pIndices)
{
    unsigned char c = 0;
    for (unsigned int i = 0; i < cnt; i++)
    {
        if (buf[i] == aiValue)
        {
            pIndices[c++] = (unsigned char)i;
        }
    }
    return c;
}

struct Struct0076b090
{
    int field0;
    Struct0076b090* Construct(int);
};
struct STR_0076b200
{
    void* f0;
    unsigned int f4;
    STR_0076b200* AssignFrom(STR_0076b200*);
};
// @fnv 0x0076b200
STR_0076b200* STR_0076b200::AssignFrom(STR_0076b200* apSource)
{
    reinterpret_cast<::FUN_00768920_shell *>(this)->FUN_00768920((void *)(apSource->f4));
    __memcpy(f0, apSource->f0, f4);
    return this;
}

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};
struct G2
{
    void AddHead(int*);
};
struct FUN_0076b240_shell
{
    void FUN_0076b240(const char* s);
};
// @fnv 0x0076b240
void FUN_0076b240_shell::FUN_0076b240(const char* apString)
{
    unsigned int size = ::FUN_0044a670(apString) + 1;
    char* buffer = new char[size];
    TaskQueueInterface::CopyStringToBuffer(buffer, size, apString);
    reinterpret_cast<G2*>(this)->AddHead(reinterpret_cast<int*>(&buffer));
}

namespace fnv_0076b2a0 {
struct FUN_0076b2a0_shell
{
    void* m_p;
    void FUN_0063f7b0();
    void FreeAll();
};
// Repeatedly deallocates the object at m_p and calls FUN_0063f7b0 until m_p becomes null.
// @fnv 0x0076b2a0
void FUN_0076b2a0_shell::FreeAll()
{
    while (m_p)
    {
        void* p = m_p;
        ::FUN_00401030(p);
        FUN_0063f7b0();
    }
}
}  // namespace fnv_0076b2a0

struct Tile
{
    void Set(int, int);
public:
    void SetName(const char *);
public:
    void Set(int, unsigned int);
public:
    static float GetInterfaceScale();
};
struct FUN_00759f20_holder
{
};
struct FUN_00768020_holder
{
    char _pad0[0xE0];
    FUN_00759f20_holder _anim;
    char _pad1[0x114 - 0xE0 - 1];
    Tile* _tile;
    void FUN_00768020();
};
// @fnv 0x00768020
void FUN_00768020_holder::FUN_00768020()
{
    reinterpret_cast<::FUN_00759f20_shell *>(&(_anim))->AssignString((const char *)(0));
    _tile->Set(0x1005, -1);
    _tile->Set(0x1008, -1);
}

struct MyHack
{
    unsigned char _pad0[0x4AC];
    float f4AC;
    unsigned char _pad1[0x20];
    float f4D0;
    float FUN_007697f0();
};
// Returns f4AC multiplied by 1280.0, divided by the result of FUN_004dc1f0, then multiplied by f4D0.
// @fnv 0x007697f0
float MyHack::FUN_007697f0()
{
    return (float)(f4AC * 1280.0 / ((int)(::FUN_004dc1f0())) * f4D0);
}

struct FUN_00768970_shell
{
    void FormatHexWord(unsigned short v, char* dst);
};

// Writes "0x" followed by the four hex digits of v (most significant first) into dst and null-terminates it.
// @fnv 0x00768970
void FUN_00768970_shell::FormatHexWord(unsigned short ausValue, char* pDest)
{
    __memcpy(pDest, "0x", 2);
    for (int i = 0; i < 4; i++)
    {
        unsigned char c;
        c = (ausValue & (0xf << (i * 4))) >> (i * 4);
        pDest[5 - i] = c < 10 ? c + 0x30 : c + 0x37;
    }
    pDest[6] = 0;
}

struct TGF
{
};

struct TileHelper
{
};

struct FUN_00767bb0_entry
{
    unsigned char _pad[0x2c];
    TGF* value;
};

struct FUN_00767bb0_shell
{
    unsigned char _pad[0x28];
    FUN_00767bb0_entry* entries[46];

    TGF* FUN_00767bb0(unsigned int a, unsigned int b);
};

// Scans 46 entries for one whose value is non-null, passes a check, and whose floats at 0xfac and 0x1004 equal a and b; returns that value or null.
// @fnv 0x00767bb0
TGF* FUN_00767bb0_shell::FUN_00767bb0(unsigned int a, unsigned int b)
{
    for (unsigned int i = 0; i < 46; ++i)
    {
        if (entries[i]->value != 0 && reinterpret_cast<::FUN_00a01230_shell *>((reinterpret_cast<TileHelper*>(entries[i]->value)))->IsTraitNonZero(0xfaf) &&
            reinterpret_cast<::TileListBoxCalls *>((void *)(entries[i]->value))->GetFloat(0xfac) == a && reinterpret_cast<::TileListBoxCalls *>((void *)(entries[i]->value))->GetFloat(0x1004) == b)
        {
            return entries[i]->value;
        }
    }

    return 0;
}

void* __cdecl operator new(unsigned int);

struct FUN_00702220
{
    void* pData;
    unsigned int ItemUpdateArray;
    ~FUN_00702220();
};

struct SL : public FUN_00702220
{
    SL();
};

FUN_00702220::~FUN_00702220()
{}

SL::SL()
{}

struct FUN_00768810
{
    STR_0076b200* pItems;
    unsigned int uiSize;

    FUN_00768810(unsigned int aiSize);
};

// Stores aiSize, allocates an SL array of that size, and initializes each element via FUN_00768920(uiSize).
// @fnv 0x00768810
FUN_00768810::FUN_00768810(unsigned int aiSize)
{
    unsigned int i;

    uiSize = aiSize;
    pItems = reinterpret_cast<STR_0076b200*>(new SL[aiSize]);

    for (i = 0; i < uiSize; ++i)
        reinterpret_cast<::FUN_00768920_shell *>(&(pItems[i]))->FUN_00768920((void *)(uiSize));
}

struct FUN_007021b0_cls
{
    void FUN_00702220();
    void* DestroyOrFree(unsigned int flags);
};
// Reads a pointer from this, and if it is non-null calls its DestroyOrFree with 3.
// @fnv 0x007687d0
void C7687d0::FUN_007687d0()
{
    T7021b0* q;
    {
        T7021b0* a = *reinterpret_cast<T7021b0**>(this);
        q = a;
    }
    q ? ((int)(reinterpret_cast<::FUN_007021b0_cls *>((q))->DestroyOrFree(3))) : 0;
}

extern "C" void FUN_00ec5fce(void* object, int elementSize, int count, void (FUN_007021b0_cls::*callback)());


// Destroys the object's elements and optionally frees the allocation, returning the object or its base pointer depending on flags.
// @fnv 0x007021b0
void* FUN_007021b0_cls::DestroyOrFree(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_00ec5fce(this, 0x8, reinterpret_cast<int*>(this)[-1], &FUN_007021b0_cls::FUN_00702220);

        if (flags & 1)
        {
            ::FUN_00401030(reinterpret_cast<char*>(this) - 4);
        }

        return reinterpret_cast<char*>(this) - 4;
    }

    reinterpret_cast<::FUN_00702220 *>(this)->FUN_00702220::~FUN_00702220();

    if (flags & 1)
    {
        ::FUN_00401030(this);
    }

    return this;
}

class NiNode;

class TileD766
{
  public:
};

class TileNU
{
  public:
};

class FORenderedMenu
{
  public:
    virtual ~FORenderedMenu();
};

class FORenderedTerminal : public FORenderedMenu
{
  public:
};

class BSAudio
{
  public:
    NiNode* GetSynchTime();
};

class InterfaceManager;

class FUN_00766aa0_Menu
{
  public:
};



// @fnv 0x00766aa0
void __cdecl UpdateD766AA0Menu()
{
    if (g_pkD766AA0Menu)
    {
        FUN_007ffe40();
        reinterpret_cast<::FUN_00a012d0_t *>((((::TileNU *)(reinterpret_cast<::Callees *>((g_pkD766AA0Menu))->FUN_00726070()))))->FUN_00a012d0(0xfc1, ::DAT_01016264, true);
        if (reinterpret_cast<::InterfaceManager *>(((*reinterpret_cast<::InterfaceManager * *>(&::g_pGame))))->GetActiveRenderedMenu())
        {
            if (((BSAudio*)reinterpret_cast<::InterfaceManager *>(((*reinterpret_cast<::InterfaceManager * *>(&::g_pGame))))->GetActiveRenderedMenu())->GetSynchTime() ==
                ((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((TileD766*)((::TileNU *)(reinterpret_cast<::Callees *>((g_pkD766AA0Menu))->FUN_00726070())))))->FUN_0056c7f0())))
            {
                FORenderedTerminal* pkTerminal =
                    dynamic_cast<FORenderedTerminal*>(reinterpret_cast<::InterfaceManager *>(((*reinterpret_cast<::InterfaceManager * *>(&::g_pGame))))->GetActiveRenderedMenu());
                reinterpret_cast<::FUN_007ffaf0_shell *>((pkTerminal))->FUN_007ffaf0();
            }
        }
        reinterpret_cast<::Tile *>((((TileD766*)((::TileNU *)(reinterpret_cast<::Callees *>((g_pkD766AA0Menu))->FUN_00726070())))))->Set(0x1772, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>((g_pkD766AA0Menu))->FUN_00a1d910();
        ::DAT_011d95c0 = ((unsigned int)(::FUN_00457fe0())) + 8000;
    }
}

extern int DAT_010729c8;
struct ValueRow
{
};
struct EntryListNode
{
};
struct FUN_00767ef0_shell
{
    void AddValueRows(unsigned int count, const unsigned int* values);
};
// Adds count to the 0xfac value of each existing row, then creates count new rows with descending 0xfac values and the given values at 0xfc4, appending each.
// @fnv 0x00767ef0
void FUN_00767ef0_shell::AddValueRows(unsigned int count, const unsigned int* puiValues)
{
    ValueRow* item;
    {
        int iterator = ::FUN_00559450((int *)(((EntryListNode*)((char*)this + 0x168))));
        while (iterator != 0)
        {
            item = *(((::ValueRow **)(reinterpret_cast<::ListStandIn *>((((EntryListNode*)((char*)this + 0x168))))->FUN_0057cbe0((int **)(int *)(&iterator)))));
            reinterpret_cast<::FUN_00a012d0_t *>((item))->FUN_00a012d0(0xfac, reinterpret_cast<::TileListBoxCalls *>((item))->GetFloat(0xfac) + float(count), {});
        }
    }
    for (unsigned int index = 0; index < count; ++index)
    {
        item = ((::ValueRow *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>(this)->FUN_00a1ddb0((::Tile *)(*(void**)((char*)this + 0x118)), (char *)(int *)(&DAT_010729c8), (::Tile *)(0))));
        reinterpret_cast<::Tile *>((item))->Set(0xfac, count - index - 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((item))->FUN_00a01350(0xfc4, (char *)(puiValues[index]), 1);
        reinterpret_cast<::FUN_004ed8c0_shell *>((((EntryListNode*)((char*)this + 0x168))))->FUN_004ed8c0((int *)(::ValueRow **)(&item));
    }
}

struct Entry
{
    unsigned char* data;
    unsigned int count;
};
struct FUN_007687d0
{
    Entry* entries;
    unsigned int count;
    ~FUN_007687d0();
    FUN_007687d0 FUN_0076af90(unsigned char* result, int j);
};
struct Context
{
    unsigned int FUN_00769520(FUN_007687d0* input);
};

struct GameCc
{
};

struct GameRoot
{
    unsigned char _pad0[0xcc];
    GameCc* m_cc;
};


struct FUN_00769700_cls
{
    unsigned char _pad0[0x1cc];
    int m_1cc;
    int GetScaledValue();
};

// Calls UnkCallA/UnkCallB, picks m_1cc or a game value as result, then returns -1 if result is outside [a,b] or (result-a)/17.
// @fnv 0x00769700
int FUN_00769700_cls::GetScaledValue()
{
    int result = 0;
    ::fnv_004b7210::FUN_004b7210();
    if (::FUN_004b71d0())
    {
        result = m_1cc;
    }
    else
    {
        result = (int)(reinterpret_cast<::FUN_007079f0_shell *>((g_pGame))->FUN_007079f0() ? reinterpret_cast<::MyHack *>((g_pGame))->FUN_007697f0() : (float)reinterpret_cast<::InterfaceManager *>((g_pGame))->FUN_00747d00());
    }
    int a = (int)reinterpret_cast<::FUN_00a013d0_shell *>((g_pGame->m_cc))->GetTotalFloat();
    int b = (int)((double)a + reinterpret_cast<::TileListBoxCalls *>((g_pGame->m_cc))->GetFloat(0xfb1) - ::g_01012070);
    return (a > result || result > b) ? -1 : (result - a) / 17;
}


struct TileV
{
};

struct SoundHandleV
{
};

struct HackingMenuV
{
    int unk00;
    TileV* tile04;
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
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    TileV* tile120;
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
    SoundHandleV sound150;
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
    unsigned int amount1B8;
    int unk1BC;
    int unk1C0;
    int state1C4;
    int unk1C8;
    int unk1CC;
    unsigned int nextTick1D0;

    void FUN_0076a3f0();
};

// @fnv 0x0076a3f0
void HackingMenuV::FUN_0076a3f0()
{
    if (((unsigned int)(::FUN_00457fe0())) > nextTick1D0)
    {
        const unsigned int delay = 50;
        reinterpret_cast<::FUN_00a012d0_t *>((tile04))->FUN_00a012d0(0x1005,
                         reinterpret_cast<::TileListBoxCalls *>((tile04))->GetFloat(0x1005) +
                             amount1B8 * (nextTick1D0 ? (((unsigned int)(::FUN_00457fe0())) - nextTick1D0) / delay + 1 : 1),
                         true);
        nextTick1D0 = ((unsigned int)(::FUN_00457fe0())) + delay;
        reinterpret_cast<::FUN_00ad8830_shell *>(&(sound150))->FUN_00ad8830(false);
    }
    if (reinterpret_cast<::FUN_00a01440_shell *>((tile120))->GetAccumulatedFloat() + reinterpret_cast<::TileListBoxCalls *>((tile120))->GetFloat(0xfb0) < ::_DAT_01012060)
    {
        reinterpret_cast<::Tile *>((tile04))->Set(0x1006, 1);
        state1C4 = 4;
    }
}

extern int DAT_011a0104;
extern char* DAT_011a0100;

struct FUN_0076a670_cls
{
    void FUN_0076a670(int a1, const char* s);
};

// @fnv 0x0076a670
void FUN_0076a670_cls::FUN_0076a670(int a1, const char* pcSource)
{
    int idx = 1;
    int r6 = ((int)(std::uintptr_t)(std::strchr((char *)(DAT_011a0104), pcSource[0])));
    if (r6 != 0)
    {
        while (1)
        {
            if (pcSource[idx] == 0 || std::isalpha(pcSource[idx]) != 0)
            {
                idx = 1;
                break;
            }
            else
            {
                if (pcSource[idx] == DAT_011a0100[r6 - DAT_011a0104])
                {
                    idx++;
                    break;
                }
            }
            idx++;
        }
    }
    ::__memcpy((void *)(a1), pcSource, idx);
}

extern "C" char str_01072108;
struct Fade
{
    int state;
    int flags;
    float amount;
    void FUN_00a0a270(float value, int enabled);
};
struct Resources
{
};
struct Widget
{
};
struct HackingMenuDecomp : HackingMenu
{
    void UpdateFade();
};
// Toggles the fade at offset 0x1d4 between 0 and 1 on a timer, creating it from resource 0xfa3 when absent, unless menu state 4 with widget 0x1006 is active.
// @fnv 0x0076a9d0
void HackingMenuDecomp::UpdateFade()
{
    static float delay = reinterpret_cast<::TileListBoxCalls *>(((*reinterpret_cast<Resources**>(reinterpret_cast<char*>(this) + 0x11c))))->GetFloat(::FUN_00a00940(&str_01072108, -1));
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1c4) == 4 && reinterpret_cast<::FUN_00a01230_shell *>((((::Widget *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->IsTraitNonZero({}))
    {
        return;
    }
    else
    {
        static unsigned int nextUpdate = 0;
        if (((unsigned int)(::FUN_00457fe0())) > nextUpdate && *reinterpret_cast<Fade**>(reinterpret_cast<char*>(this) + 0x1d4) != 0)
        {
            (*reinterpret_cast<Fade**>(reinterpret_cast<char*>(this) + 0x1d4))
                ->FUN_00a0a270(
                    (*reinterpret_cast<Fade**>(reinterpret_cast<char*>(this) + 0x1d4))->amount == 1.0 ? 0.0f : 1.0f, 1);
            nextUpdate = static_cast<unsigned int>(((unsigned int)(::FUN_00457fe0())) + delay);
        }
        else if (*reinterpret_cast<Fade**>(reinterpret_cast<char*>(this) + 0x1d4) == 0)
        {
            *reinterpret_cast<Fade**>(reinterpret_cast<char*>(this) + 0x1d4) =
                ((::Fade *)(reinterpret_cast<::FUN_00a00e90_shell *>(((*reinterpret_cast<Resources**>(reinterpret_cast<char*>(this) + 0x11c))))->FindTraitValue(0xfa3)));
        }
    }
}

struct Node
{
};
extern int __cdecl FUN_00ec62c0();
struct Menu0076ab40
{
    unsigned int unk000;
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
    Node* active;
    Node* root;
    void UpdateActiveNodeProperty();
};
// @fnv 0x0076ab40
void Menu0076ab40::UpdateActiveNodeProperty()
{
    Node* selected;
    int total;
    {
        int multiplier = 0;
        total = 0;
        if (reinterpret_cast<::FUN_00a01230_shell *>((root))->IsTraitNonZero(0xfa3))
        {
            selected = ((::Node *)(reinterpret_cast<::FUN_00a011f0_shell *>((root))->FUN_00a011f0(0xfc4)));
            if (selected)
                multiplier = ((int)(::FUN_0044a670((const char *)(selected))));
        }
        for (Node* current = root; current && current != ((::Node *)(reinterpret_cast<::FUN_0045cd60_shell *>((active))->FUN_0045cd60())); current = ((::Node *)(reinterpret_cast<::FUN_0045cd60_shell *>((current))->FUN_0045cd60())))
        {
            reinterpret_cast<::TileListBoxCalls *>((current))->GetFloat(0xfa1);
            total += FUN_00ec62c0();
        }
        reinterpret_cast<::Tile *>((active))->Set(0xfa1, multiplier * 17 + total);
    }
}

// BuildHackingGuessTemplate - hacking menu guess template formatting
struct FUN_00a1ddb0_res
{
    int FUN_00700300();
};

struct FUN_00a1ddb0_owner
{
};


struct FUN_0044ddc0_sub
{
};

class FUN_004037b0_tmp
{
  public:
    int m_00;
    int m_04;
    FUN_004037b0_tmp();
    ~FUN_004037b0_tmp();
};


struct FUN_0076ad50_cls
{
    unsigned char _pad0[0x110];
    char* m110;
    unsigned char _pad1[0x174 - 0x110 - 4];
    FUN_0044ddc0_sub m174;
    void BuildHackingGuessTemplate();
};

// @fnv 0x0076ad50
void FUN_0076ad50_cls::BuildHackingGuessTemplate()
{
    FUN_00a1ddb0_res* p = ((::FUN_00a1ddb0_res *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>(((*reinterpret_cast<::FUN_00a1ddb0_owner * *>(&::g_pkD766AA0Menu))))->FUN_00a1ddb0((::Tile *)(m110), (char *)("hacking_guess_template"), (::Tile *)(void *)(0))));
    reinterpret_cast<::Tile *>((p))->Set(0xfac, ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m174))->GetName())));
    reinterpret_cast<::FUN_004ed8c0_shell *>(&(m174))->FUN_004ed8c0((int *)(::FUN_00a1ddb0_res **)(&p));
    {
        FUN_004037b0_tmp nameBuf;
        ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&nameBuf), "%s_%d", p->FUN_00700300(), ((int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m174))->GetName())));
        reinterpret_cast<::Tile *>((p))->SetName((const char *)(::FUN_00559450((int *)&(nameBuf))));
    }
}

struct FUN_0076ae90_cls
{
    unsigned char* buf;
    unsigned int cnt;
    unsigned int FUN_0076ae90();
};
// Scans input entries for the smallest value, recursing into sub-entries when it exceeds 2, and returns the combined result plus one.
// @fnv 0x00769520
unsigned int Context::FUN_00769520(FUN_007687d0* input)
{
    unsigned char minimum = 255;
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Callees *>((input))->FUN_00726070())); ++i)
    {
        unsigned char current = ((int)(reinterpret_cast<::FUN_0076ae90_cls *>(&(((::Entry *)(::FUN_00559450((int *)(input))))[i]))->FUN_0076ae90()));
        if (current < minimum)
            minimum = current;
    }
    if (minimum == 255)
    {
        return 0;
    }
    else if (minimum <= 2)
    {
        return minimum + 1;
    }
    else
    {
        unsigned int best = ((unsigned int)(reinterpret_cast<::Callees *>((input))->FUN_00726070()));
        for (unsigned int outer = 0; outer < ((unsigned int)(reinterpret_cast<::Callees *>((input))->FUN_00726070())); ++outer)
        {
            if (((int)(reinterpret_cast<::FUN_0076ae90_cls *>(&(((::Entry *)(::FUN_00559450((int *)(input))))[outer]))->FUN_0076ae90())) == minimum)
            {
                unsigned int worst = 0;
                for (unsigned int inner = 0; inner < ((unsigned int)(reinterpret_cast<::Callees *>((input))->FUN_00726070())); ++inner)
                {
                    unsigned char results[32];
                    if (reinterpret_cast<::Struct0076ae30 *>(&(((::Entry *)(::FUN_00559450((int *)(input))))[outer]))->FindByteIndices(inner, results) == minimum)
                    {
                        FUN_007687d0 a = input->FUN_0076af90(results, minimum);
                        unsigned int j = FUN_00769520(&a);
                        worst = FUN_00403940(worst, j);
                    }
                }
                if (worst != 0)
                    best = FUN_0042f5a0(best, worst);
                if (best <= 2)
                    return best + 1;
            }
        }
        return best + 1;
    }
}


struct FUN_0076ae90_tbl
{
    unsigned int cap;
    unsigned char table[0x20];
};

// Counts occurrences of each byte below 0x20 in buf and folds the counts into a running result via MaxByte.
// @fnv 0x0076ae90
unsigned int FUN_0076ae90_cls::FUN_0076ae90()
{
    unsigned int i;
    unsigned int j;
    FUN_0076ae90_tbl t_;
    unsigned char result2;

    t_.cap = 0x20;
    result2 = 0;
    ::FUN_00403d30(t_.table, 0, 0x20);
    for (i = 0; i < cnt; i++)
    {
        if ((unsigned int)buf[i] < 0x20)
        {
            t_.table[buf[i]]++;
        }
    }
    for (j = 0; j < 0x20; j++)
    {
        result2 = MaxByte(result2, t_.table[j]);
    }
    return result2;
}

struct ArrElem
{
    void* f0;
    unsigned int f4;
    ArrElem();
    ~ArrElem();
};

struct ElemArray
{
    ArrElem* pItems;
    unsigned int uiSize;

    ElemArray* CopyFrom(ElemArray* src);
};
// Resets field0 to 0, calls CopyFrom with a, and returns this.
// @fnv 0x0076b090
Struct0076b090* Struct0076b090::Construct(int aiValue)
{
    field0 = 0;
    reinterpret_cast<::ElemArray *>(this)->CopyFrom((::ElemArray *)(aiValue));
    return this;
}

// @fnv 0x0076b0c0
ElemArray* ElemArray::CopyFrom(ElemArray* src)
{
    uiSize = src->uiSize;
    delete[] pItems;
    pItems = new ArrElem[src->uiSize];
    for (unsigned int i = 0; i < uiSize; i++)
        reinterpret_cast<::STR_0076b200 *>(&(pItems[i]))->AssignFrom((::STR_0076b200 *)(::ArrElem *)(&src->pItems[i]));
    return this;
}

struct MenuBase
{
    MenuBase();
    virtual ~MenuBase();
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};
struct AnimState
{
    AnimState();
    ~AnimState();
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};
struct Sound
{
    int id;
    int state;
    int flags;
    Sound();
    ~Sound();
    Sound& operator=(const Sound&);
};
struct ListState
{
    int a;
    int b;
    int c;
    ListState();
    ~ListState();
};
struct PairState
{
    int a;
    int b;
    PairState();
    ~PairState();
};
struct AudioManager
{
};
struct FUN_007654f0 : MenuBase
{
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
    int unkDC;
    AnimState anim;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    Sound sounds[5];
    ListState list168;
    ListState list174;
    PairState pair180;
    ListState list188;
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
    char unk1D8;
    char unk1D9;
    char unk1DA;
    FUN_007654f0();
    virtual ~FUN_007654f0();
};
static const char scrollSound[] = "UIHackingCharScroll";
// @fnv 0x007654f0
FUN_007654f0::FUN_007654f0()
{
    unk1B4 = 0;
    unk1B8 = 30;
    ::FUN_00403d30(&unk10C, 0, 32);
    unk19C = 0;
    unk1A4 = 0;
    unk1A0 = 0;
    unk1AC = 0;
    unk1A8 = 0;
    unk1CC = 0;
    unk1B0 = 0;
    unk1C4 = 0;
    unk1BC = -1;
    unk1C8 = 0;
    unk1C0 = 0;
    unk1DA = 0;
    unk1D9 = 0;
    unk1D8 = 0;
    unk1D0 = 0;
    unk1D4 = 0;
    AudioManager* audio = ((::AudioManager *)(::FUN_00ad9060()));
    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::Sound &)(sounds[0]))->operator=((const ::SoundPlaybackHandle &)((const ::Sound &)((*(::Sound *)(reinterpret_cast<::AudioClass_ae5680 *>((audio))->ResolveAudioHandle((::Handle_ae5680 *)("UIHackingFanHumLP"), 49, {}))))));
    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::Sound &)(sounds[1]))->operator=((const ::SoundPlaybackHandle &)((const ::Sound &)((*(::Sound *)(reinterpret_cast<::AudioClass_ae5680 *>((audio))->ResolveAudioHandle((::Handle_ae5680 *)("UIHackingPassGood"), 33, {}))))));
    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::Sound &)(sounds[2]))->operator=((const ::SoundPlaybackHandle &)((const ::Sound &)((*(::Sound *)(reinterpret_cast<::AudioClass_ae5680 *>((audio))->ResolveAudioHandle((::Handle_ae5680 *)("UIHackingPassBad"), 33, {}))))));
    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::Sound &)(sounds[3]))->operator=((const ::SoundPlaybackHandle &)((const ::Sound &)((*(::Sound *)(reinterpret_cast<::AudioClass_ae5680 *>((audio))->ResolveAudioHandle((::Handle_ae5680 *)(scrollSound), 33, {}))))));
    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::Sound &)(sounds[4]))->operator=((const ::SoundPlaybackHandle &)((const ::Sound &)((*(::Sound *)(reinterpret_cast<::AudioClass_ae5680 *>((audio))->ResolveAudioHandle((::Handle_ae5680 *)("UIHackingCharEnter"), 33, {}))))));
    ::FUN_00403d30(&unk28, 0, 184);
}

struct ScriptObj
{
    virtual int Call0(int);
};
struct ListM
{
    int f00;
    int f04;
    int f08;
    ~ListM();
    ScriptObj* RemoveHead();
};
struct EntObj
{
    void* FUN_00765b50(unsigned int);
};
struct ObjE0
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    ~ObjE0();
};
struct SndX
{
};
struct BSSoundHandleEx : SndX
{
    int f00;
    int f04;
    int f08;
    ~BSSoundHandleEx();
};
struct SubM
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    ~SubM();
};
struct SettingValue
{
    int v;
};
struct SettingColl
{
};
struct SysColorMgr
{
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
struct FUN_007658e0 : Menu_007a8b10
{
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    EntObj* entries[46];
    ObjE0 mE0;
    BSSoundHandleEx snd[5];
    ListM list1;
    ListM list2;
    FUN_00765810 m180;
    int f184;
    SubM m188;
    void* ptr1B0;
    ~FUN_007658e0();
};
// @fnv 0x007658e0
FUN_007658e0::~FUN_007658e0()
{
    ScriptObj* head7;
    ScriptObj* objTmp;
    ScriptObj* head4;
    ScriptObj* obj2;
    EntObj* ent2;
    EntObj* entCopy2;
    int i8;
    unsigned int jB;
    while (!reinterpret_cast<::FUN_0076b610_Class *>(&(list1))->FUN_0076b610())
    {
        head7 = list1.RemoveHead();
        objTmp = head7;
        objTmp ? objTmp->Call0(1) : 0;
    }
    while (!reinterpret_cast<::FUN_0076b610_Class *>(&(list2))->FUN_0076b610())
    {
        head4 = list2.RemoveHead();
        obj2 = head4;
        obj2 ? obj2->Call0(1) : 0;
    }
    reinterpret_cast<::NiTPointerListBase *>(&(m188))->FUN_004ed900();
    DAT_011d95c0 = ((unsigned int)(::FUN_00457fe0())) + ((::SettingValue *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingColl *>(&::g_011d0b90))))))->v;
    reinterpret_cast<::fnv_0076b2a0::FUN_0076b2a0_shell *>(&(m180))->FreeAll();
    void* ptrTmp = ptr1B0;
    ::FUN_00401030(ptrTmp);
    (*reinterpret_cast<::FUN_00a1ddb0_owner * *>(&::g_pkD766AA0Menu)) = 0;
    for (i8 = 0; i8 < 5; i8++)
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(snd[i8]))->FUN_00ad88f0();
        reinterpret_cast<::SoundPlaybackHandle *>(&(snd[i8]))->Release();
    }
    for (jB = 0; jB < 46; jB++)
    {
        ent2 = entries[jB];
        entCopy2 = ent2;
        entCopy2 ? reinterpret_cast<::FUN_0076b560_shell *>((entCopy2))->FUN_00765b50(1) : 0;
    }
    reinterpret_cast<::FUN_007190e0_cls *>((((::SysColorMgr *)(::FUN_00718b60()))))->ApplyToChild({}, {});
}

struct HackTile
{
};
struct HackEntry
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
    HackTile* tile;
};
struct HackList
{
    char* data;
    HackList* next;
};
struct HackMenu
{
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
    HackEntry* entries[46];
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;

    HackList words;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    const char* selected;
    int unk1a0;
    int unk1a4;
    unsigned int count;
    unsigned int dotCount;
    unsigned int* positions;
    void RemoveRandomWord();
};
// Picks a random word matching selected, fills its menu tile with dots up to dotCount, shifts positions, frees the word and decrements count.
// @fnv 0x0076a730
void HackMenu::RemoveRandomWord()
{
    unsigned int index;
    unsigned int iter;
    HackList* word;
    unsigned int position3;
    unsigned int aRow;
    HackTile* tile_2;
    char text[20];
    do
    {
        index = ::FUN_005a00a0(count);
        iter = index;
        word = &words;
        while (iter--)
            word = ((::HackList *)(reinterpret_cast<::Callees *>((word))->FUN_00726070()));
    } while (!FUN_00408b20(*((char **)(new ((void *)(word)) ::Vec3())), selected));
    aRow = 4;
    for (position3 = positions[index]; position3 > 12; position3 -= 12)
        ++aRow;
    tile_2 = entries[aRow]->tile;
    ++aRow;
    __memcpy(text, reinterpret_cast<::FUN_00a011f0_shell *>((tile_2))->FUN_00a011f0(0xfc4), 20);
    for (iter = 0; iter < dotCount && position3 < 12; ++iter)
    {
        text[position3 + 7] = '.';
        ++position3;
    }
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile_2))->FUN_00a01350(0xfc4, (char *)(text), true);
    if (entries[aRow] && entries[aRow]->tile && reinterpret_cast<::FUN_00a01230_shell *>((entries[aRow]->tile))->IsTraitNonZero(0xfaf) && iter < dotCount)
    {
        position3 = 0;
        tile_2 = entries[aRow]->tile;
        __memcpy(text, reinterpret_cast<::FUN_00a011f0_shell *>((tile_2))->FUN_00a011f0(0xfc4), 20);
        while (iter++ < dotCount)
        {
            text[position3 + 7] = '.';
            ++position3;
        }
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile_2))->FUN_00a01350(0xfc4, (char *)(text), true);
    }
    for (; index < count - 1; ++index)
        positions[index] = positions[index + 1];
    positions[index] = 0x198;
    char* deleted = *((char **)(new ((void *)(word)) ::Vec3()));
    ::FUN_00401030(deleted);
    reinterpret_cast<::ItemChangeListNode *>(&(words))->FUN_00905330((*(::InventoryStackRecord *const *)(((char **)(new ((void *)(word)) ::Vec3())))));
    --count;
}

namespace fnv_0076ac10 {

struct HTile
{
};

struct HackEntry
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
    HTile* tile;
};

struct HackMenuStub
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
    HTile* tile11C;
    void PositionTileFromEntry(HackEntry* entry);
};

// Computes x/y from the entry's tile string length and float values plus ancestor tiles, then sets them on tile11C.
// @fnv 0x0076ac10
void HackMenuStub::PositionTileFromEntry(HackEntry* entry)
{
    if (!entry || !entry->tile)
        return;
    const char* text = reinterpret_cast<::FUN_00a011f0_shell *>((entry->tile))->FUN_00a011f0(0xfc4);
    int len4 = (text && *text != ' ') ? ::FUN_0044a670(text) : 0;
    int x8 = reinterpret_cast<::TileListBoxCalls *>((entry->tile))->GetFloat(0xfa1) + len4 * 0x11;
    int y = reinterpret_cast<::TileListBoxCalls *>((entry->tile))->GetFloat(0xfa2);
    HTile* parent;
    for (parent = ((::fnv_0076ac10::HTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((entry->tile))->FUN_0045cd60())); parent && parent != ((::fnv_0076ac10::HTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((tile11C))->FUN_0045cd60()));
         parent = ((::fnv_0076ac10::HTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((parent))->FUN_0045cd60())))
    {
        x8 += (int)reinterpret_cast<::TileListBoxCalls *>((parent))->GetFloat(0xfa1);
        y += (int)reinterpret_cast<::TileListBoxCalls *>((parent))->GetFloat(0xfa2);
    }
    reinterpret_cast<::Tile *>((tile11C))->Set(0xfa1, x8);
    reinterpret_cast<::Tile *>((tile11C))->Set(0xfa2, y);
}
}  // namespace fnv_0076ac10

struct FUN_00759eb0
{
    FUN_00759eb0(const char*);
    ~FUN_00759eb0();
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
};
struct SettingRef
{
};
struct TileValue
{
};
struct ConstructorTile : FUN_00a1ddb0_res
{
};
struct ConstructorMenu : FUN_00a1ddb0_owner
{
    unsigned int unk000;
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
    char* root;
};
extern const char DAT_0107293c[];
extern const char DAT_010692d0[];
struct FUN_0076b300 : FUN_00759eb0
{
    ConstructorTile* tile;
    ConstructorTile* label;
    FUN_0076b300(const char*, char*, const char*, int, unsigned char);
};
// @fnv 0x0076b300
FUN_0076b300::FUN_0076b300(const char* name, char* parent, const char* path, int value, unsigned char kind)
    : FUN_00759eb0(name)
{
    label = 0;
    tile = 0;
    if (!(*reinterpret_cast<::FUN_00a1ddb0_owner * *>(&::g_pkD766AA0Menu)))
        return;
    unsigned int counts[3];
    counts[0] = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingRef *>(&::g_011d3dc0))))));
    counts[1] = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingRef *>(&::g_011d4e4c))))));
    counts[2] = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingRef *>(&::g_011d3510))))));
    {
        unsigned int randomValue = counts[kind] > 1 ? ::InventoryStackRecord::RoundToNearestStep(1000.0 / counts[kind], 1.0f) : 1000.0f;
        reinterpret_cast<::FUN_00766a10_shell *>(this)->SetCapacity(randomValue);
        tile = static_cast<ConstructorTile*>(((::FUN_00a1ddb0_res *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>(((*reinterpret_cast<::FUN_00a1ddb0_owner * *>(&::g_pkD766AA0Menu))))->FUN_00a1ddb0((::Tile *)(parent), (char *)(path), (::Tile *)(void *)(0)))));
        if (tile)
        {
            reinterpret_cast<::FUN_006ffe80_shell *>(this)->FUN_006ffe80(((int)(reinterpret_cast<::FUN_00a00f30_shell *>((tile))->FUN_00a00f30(0xfc4))), ((int)(reinterpret_cast<::FUN_00a00e90_shell *>((tile))->FindTraitValue(0xfa3))));
            if (kind == 1)
            {
                label = static_cast<ConstructorTile*>(
                    ((::FUN_00a1ddb0_res *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>(((*reinterpret_cast<::FUN_00a1ddb0_owner * *>(&::g_pkD766AA0Menu))))->FUN_00a1ddb0((::Tile *)(static_cast<ConstructorMenu*>((*reinterpret_cast<::FUN_00a1ddb0_owner * *>(&::g_pkD766AA0Menu)))->root), (char *)(DAT_0107293c), (::Tile *)(void *)(0)))));
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((label))->FUN_00a01350(0xfc4, (char *)(DAT_010692d0), true);
            }
            if (value >= 0)
            {
                reinterpret_cast<::Tile *>((tile))->Set(0xfa2, value);
                int width =
                    static_cast<int>(reinterpret_cast<::TileListBoxCalls *>((((::TileValue *)(reinterpret_cast<::Callees *>((static_cast<ConstructorMenu*>((*reinterpret_cast<::FUN_00a1ddb0_owner * *>(&::g_pkD766AA0Menu)))))->FUN_00726070()))))->GetFloat(0x1007));
                if (label)
                {
                    reinterpret_cast<::Tile *>((label))->Set(0xfa1, width);
                    reinterpret_cast<::Tile *>((label))->Set(0xfa2, value);
                    reinterpret_cast<::Tile *>((tile))->Set(0xfa1, width + ::FUN_0044a670(DAT_010692d0) * 17);
                }
                else
                {
                    reinterpret_cast<::Tile *>((tile))->Set(0xfa1, width);
                }
            }
        }
    }
}

// Adapted from prior contributor's code (credited in packet.json)
extern "C" void* __cdecl FUN_00afdf20(const char*, unsigned int, unsigned int, unsigned int);
extern char str_01072a34[];
extern char str_01072a00[];
extern char str_010729e8[];
void __cdecl UpdateD766AA0Menu();

struct PathStorage
{
    StrMem str;
    void* ownedBuffer;
};
struct FUN_00680890 : FUN_00765810
{
    void* m_item;
    void* m_next;
    FUN_00680890();
};
struct StrMemMethods : StrMem
{
    void FUN_00438390(const char*);
};
struct WordsView : FUN_00765810
{
    void FUN_00680890();
    void FUN_0076b240(const char*);
    void SortWeatherEntries();
};
struct FileObj
{
    virtual ~FileObj();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual unsigned char FUN_20(int, int);
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual int FUN_34(char*, int, int);
};
struct EntryRow
{
};
struct MatrixWrapper : FUN_007687d0
{
    MatrixWrapper(unsigned int);
};
struct FUN_00768070_shell : FUN_00768a10_shell
{
    void SelectWordSet(unsigned int);
};

// @fnv 0x00768070
void FUN_00768070_shell::SelectWordSet(unsigned int requestedCount)
{
    unsigned int attacker;
    int ahead;
    char* aimed;
    int ammo;
    unsigned int bracket;
    WordsView* currentNode;
    int row;
    char* chosen;
    PathStorage dataFileName;
    FileObj* openedFile = 0;
    struct FUN_00680890 available;
    unsigned int startTicks = ((unsigned int)(::FUN_00457fe0()));
    attacker = 0;
    ammo = 8;
    int threat = 10;
    unsigned int qty = (requestedCount - 2) / *(unsigned int*)((char*)this + 0x1ac) + 1;
    ahead = 0;
    if (*(unsigned int*)((char*)this + 0x1ac) == 0)
        return;
    ((StrMemMethods*)&dataFileName.str)->FUN_00438390(str_01072a34);
    openedFile = (FileObj*)FUN_00afdf20(((const char *)(::FUN_00559450((int *)(((StrMemMethods*)&dataFileName.str))))), 0, 0x4000, 0x100);
    if (!openedFile || !openedFile->FUN_20(0, 0))
    {
        ::FUN_005b5e40();
        UpdateD766AA0Menu();
        return;
    }
    char line[32];
    while (true)
    {
        memset(line, 0, 32);
        if (openedFile->FUN_34(line, 32, 32) == 0)
        {
            break;
        }
        else
        {
            if (!line[0])
                continue;
        }
        if (::FUN_0044a670(line) == *(unsigned int*)((char*)this + 0x1ac))
            ((FUN_0076b240_shell*)&available)->FUN_0076b240(line);
    }
    delete openedFile;
    ((FUN_007687b0_shell*)&available)->SortWeatherEntries();
    ((FUN_007687b0_shell*)&available)->SortWeatherEntries();
    ((FUN_007687b0_shell*)&available)->SortWeatherEntries();
    while (1)
    {
        unsigned int limit = ((unsigned int)(::FUN_00457fe0())) + 100;
        while (((unsigned int)(::FUN_00457fe0())) < limit && ++attacker)
        {
            reinterpret_cast<::fnv_0076b2a0::FUN_0076b2a0_shell *>((((WordsView*)((char*)this + 0x180))))->FreeAll();
            *(unsigned int*)((char*)this + 0x1a8) = 0;
            ((FUN_007687b0_shell*)&available)->SortWeatherEntries();
            for (currentNode = (WordsView*)&available; *(unsigned int*)((char*)this + 0x1a8) < requestedCount &&
                                                       currentNode && (chosen = *((char **)(new ((void *)(currentNode)) ::Vec3())));
                 currentNode = ((::WordsView *)(reinterpret_cast<::Callees *>((currentNode))->FUN_00726070())))
            {
                bool accepted = true;
                unsigned char similarities[8];
                memset(similarities, 0, sizeof(similarities));
                for (WordsView* selected = ((WordsView*)((char*)this + 0x180));
                     accepted && selected && (aimed = *((char **)(new ((void *)(selected)) ::Vec3()))); selected = ((::WordsView *)(reinterpret_cast<::Callees *>((selected))->FUN_00726070())))
                {
                    unsigned int similarity = CountMatchingChars(chosen, aimed);
                    if (similarity == *(unsigned int*)((char*)this + 0x1ac))
                    {
                        accepted = false;
                    }
                    else if (*(unsigned int*)((char*)this + 0x1a8) < requestedCount - 1)
                    {
                        accepted = (similarity > 0 || ::FUN_005a00a0(10) < (unsigned int)ahead);
                    }
                    else
                    {
                        accepted = (similarity >= 8 || ++similarities[similarity] <= qty);
                    }
                }
                if (accepted)
                {
                    ((FUN_0076b240_shell*)((WordsView*)((char*)this + 0x180)))->FUN_0076b240(chosen);
                    ++*(unsigned int*)((char*)this + 0x1a8);
                }
            }
            if (*(unsigned int*)((char*)this + 0x1a8) == requestedCount)
                break;
        }
        if (*(unsigned int*)((char*)this + 0x1a8) == requestedCount)
        {
            break;
        }
        else
        {
            if (++ahead == 10)
            {
                ahead = 0;
                if (++qty > (requestedCount >> 1))
                    break;
            }
        }
    }
    ((FUN_007687b0_shell*)((WordsView*)((char*)this + 0x180)))->SortWeatherEntries();
    ((FUN_007687b0_shell*)((WordsView*)((char*)this + 0x180)))->SortWeatherEntries();
    ((FUN_007687b0_shell*)((WordsView*)((char*)this + 0x180)))->SortWeatherEntries();
    ((FUN_007687b0_shell*)((WordsView*)((char*)this + 0x180)))->SortWeatherEntries();
    bracket = ::FUN_005a00a0(*(unsigned int*)((char*)this + 0x1a8));
    currentNode = ((WordsView*)((char*)this + 0x180));
    for (int index = 0; (unsigned int)index < bracket; ++index)
        currentNode = ((::WordsView *)(reinterpret_cast<::Callees *>((currentNode))->FUN_00726070()));
    *(char**)((char*)this + 0x19c) = *((char **)(new ((void *)(currentNode)) ::Vec3()));
    ::FUN_0040fbe0();
    MatrixWrapper bonus(*(unsigned int*)((char*)this + 0x1a8));
    row = 0;
    for (currentNode = ((WordsView*)((char*)this + 0x180)); currentNode && *((char **)(new ((void *)(currentNode)) ::Vec3()));
         currentNode = ((::WordsView *)(reinterpret_cast<::Callees *>((currentNode))->FUN_00726070())))
    {
        int columnIndex = 0;
        for (WordsView* col = ((WordsView*)((char*)this + 0x180)); col && *((char **)(new ((void *)(col)) ::Vec3()));
             col = ((::WordsView *)(reinterpret_cast<::Callees *>((col))->FUN_00726070())))
        {
            ((unsigned char *)(::FUN_00559450((int *)(((EntryRow*)&((::Entry *)(::FUN_00559450((int *)&(bonus))))[row])))))[columnIndex] =
                (currentNode == col) ? 0xFF
                                     : this->CountMatchingChars(*((char **)(new ((void *)(currentNode)) ::Vec3())), *((char **)(new ((void *)(col)) ::Vec3())));
            ++columnIndex;
        }
        ++row;
    }
    *(void**)((char*)this + 0x1a0) = (void*)reinterpret_cast<::Context *>((this))->FUN_00769520(&bonus);
    *(void**)((char*)this + 0x1a0) = (void*)::FUN_00403940(4, *(unsigned int*)((char*)this + 0x1a0));
    *(void**)((char*)this + 0x1a4) = *(void**)((char*)this + 0x1a0);
}

struct Text83
{
    char* data;
    unsigned short length, capacity;
    Text83();
    ~Text83();
};
struct Setting83
{
};
struct Tile83
{
};
struct Entry83
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    Tile83* tile;
    int unk30;
    Entry83(const char*, Tile83*, const char*, int, int);
    Entry83();
    ~Entry83();
    void* FUN_00765b50(int);
};
struct Node83
{
    char* item;
    Node83* next;
    void FUN_0063f7b0();
};
void operator delete(void*);
void* operator new[](unsigned int);
void operator delete[](void*);
struct Hack83
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
    Entry83* entries[46];
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    Tile83* tile10c;
    Tile83* tile110;
    Tile83* tile114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    Node83 words;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    char* password;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int* positions;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    Tile83* tile1c8;
    int unk1cc;
    void BuildHackingPasswordFile();
};
// Clears the entry list, rebuilds the intro entries, generates a random password buffer from the word list, and creates one entry per 12-character chunk.
// @fnv 0x00768aa0
void Hack83::BuildHackingPasswordFile()
{
    for (unsigned int i = 0; i < 46 && entries[i]; i++)
        delete entries[i];
    ::FUN_00403d30(entries, 0, 184);
    Text83 text24x17;
    ::FUN_00406f60((::FUN_00406f90_this *)(::Text83 *)(&text24x17), "%d %s", unk1a0, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting83 *>(&::g_011d2e20))))->GetMenuTitle())));
    entries[0] = new Entry83(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::Setting83 *>(&::g_011d33cc))))->IsDLCAvailable())), tile110, "hacking_intro_template", unk1b4, 0);
    entries[1] = new Entry83(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::Setting83 *>(&::g_011d430c))))->IsDLCAvailable())), tile110, "hacking_intro_template", unk1b4 + unk1b8, 0);
    entries[2] = new Entry83(((const char *)(::FUN_00559450((int *)&(text24x17)))), tile110, "hacking_intro_template", unk1b4 + unk1b8 * 3, 0);
    reinterpret_cast<::FUN_00a012d0_t *>((tile110))->FUN_00a012d0(4101, reinterpret_cast<::TileListBoxCalls *>((entries[2]->tile))->GetFloat(4001) + ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(text24x17))->FUN_004048e0())) * 17, {});
    reinterpret_cast<::FUN_00a012d0_t *>((tile110))->FUN_00a012d0(4102, reinterpret_cast<::TileListBoxCalls *>((entries[2]->tile))->GetFloat(4002), {});
    entries[3] = new Entry83;
    reinterpret_cast<::FUN_006ffe80_shell *>((entries[3]))->FUN_006ffe80(0, ((int)(reinterpret_cast<::FUN_00a00f30_shell *>((tile110))->FUN_00a00f30(4100))));
    int entryIndex7x39 = 4;
    for (unsigned int i = 0; i < (unsigned int)unk1a4; i++)
        reinterpret_cast<::FUN_0076ad50_cls *>(this)->BuildHackingGuessTemplate();
    unsigned int alphabetSize17x2 = FUN_0044a670("!@#$%^*()_+=-`[]{}|;':,./<>?\\\"");
    int spacing35x61 = 2;
    int bufferSize12x1 = 409;
    char bufferx3[409];
    if (!unk1a8)
        return;
    delete[] positions;
    positions = new int[unk1a8];
    unsigned int attempts8x10 = 0;
    while (true)
    {
        for (unsigned int fill18 = 0; fill18 < 408; fill18++)
            bufferx3[fill18] = "!@#$%^*()_+=-`[]{}|;':,./<>?\\\""[::FUN_005a00a0(alphabetSize17x2)];
        bufferx3[408] = 0;
        Node83* node15 = &words;
        int wordIndex4 = 0;
        unsigned int failures12 = 0;
        while (node15 && *((char **)(new ((void *)(node15)) ::Vec3())) && failures12 < 100)
        {
            int position4 = ::FUN_005a00a0(409 - unk1ac - 2);
            bool free16 = true;
            for (int j = -2; free16 && j < unk1ac + 2; j++)
                free16 = !(position4 + j >= 0 && bufferx3[position4 + j] >= 'A' && bufferx3[position4 + j] <= 'Z');
            if (free16)
            {
                ::__memcpy(bufferx3 + position4, *((char **)(new ((void *)(node15)) ::Vec3())), unk1ac);
                positions[wordIndex4] = position4;
                wordIndex4++;
                node15 = ((::Node83 *)(reinterpret_cast<::Callees *>((node15))->FUN_00726070()));
                failures12 = 0;
            }
            else
                failures12++;
        }
        if (failures12)
        {
            attempts8x10++;
            if (attempts8x10 <= 4)
                continue;
            else
            {
                ::FUN_005b5e40(
                    );
                while (*((char **)(new ((void *)(node15)) ::Vec3())))
                {
                    if (password == *((char **)(new ((void *)(node15)) ::Vec3())))
                        password = *((char **)(new ((void *)(node15)) ::Vec3()));
                    delete[] *((char **)(new ((void *)(node15)) ::Vec3()));
                    node15->FUN_0063f7b0();
                    unk1a8--;
                    positions[wordIndex4] = 408;
                    wordIndex4++;
                }
                for (Node83* walk = &words; walk; walk = ((::Node83 *)(reinterpret_cast<::Callees *>((walk))->FUN_00726070())))
                    if (((::Node83 *)(reinterpret_cast<::Callees *>((walk))->FUN_00726070())) == node15)
                        reinterpret_cast<::CombatProcedure *>((walk))->Initialize((::CombatController *)(0));
            }
        }
        else
            break;
    }
    int row104x2 = 0;
    int column9x68 = 0;
    char* current28x7 = bufferx3;
    char* end47x7 = bufferx3 + 408;
    while (current28x7 < end47x7)
    {
        char backup = 0;
        if (end47x7 - current28x7 > 12)
        {
            backup = current28x7[12];
            current28x7[12] = 0;
        }
        char address[8];
        reinterpret_cast<::FUN_00768970_shell *>(this)->FormatHexWord((unsigned short)current28x7, address);
        ::FUN_00406f60((::FUN_00406f90_this *)(::Text83 *)(&text24x17), "%s %s", address, current28x7);
        entries[entryIndex7x39] =
            new Entry83(((const char *)(::FUN_00559450((int *)&(text24x17)))), tile114, "hacking_password_file_template", -1, 2);
        reinterpret_cast<::Tile *>((entries[entryIndex7x39]->tile))->Set(4012, row104x2);
        reinterpret_cast<::Tile *>((entries[entryIndex7x39]->tile))->Set(4100, column9x68);
        ::fnv_004b7210::FUN_004b7210();
        if (FUN_004b71d0() && !row104x2 && !column9x68)
        {
            tile1c8 = entries[entryIndex7x39]->tile;
            unk1cc = (int)(reinterpret_cast<::FUN_00a013d0_shell *>((tile1c8))->GetTotalFloat() + 119.0);
        }
        row104x2++;
        if (row104x2 == 17)
        {
            row104x2 = 0;
            column9x68++;
        }
        entryIndex7x39++;
        if (end47x7 - current28x7 > 12)
            current28x7[12] = backup;
        current28x7 += 12;
    }
    reinterpret_cast<::Tile *>((tile10c))->Set(4003, 0);
    unk1c4 = 1;
}

namespace s767610 {

struct Tile
{
};

struct InterfaceManager
{
};

bool FUN_00702450(int iMenuID);

struct HackingState
{
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
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    Tile* m_pkSelected;
};


class HackingMenu
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void HandleClick(int m_uiSoundID, int iUnk);

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
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int m_iStage;
    Tile* m_pkCursorTile;
    int m_iCursorIndex;
    int unk1d0;
    int unk1d4;
    bool m_bBlink;

    bool HandleKey(int iKey, int iUnused);
};

// Handles key input for the hacking menu, moving the cursor tile or triggering a click based on the current stage and key code.
// @fnv 0x00767610
bool HackingMenu::HandleKey(int iKey, int iUnused)
{
    if (!((::s767610::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->FUN_004b71d0())
        return false;
    if (FUN_00702450(0x41f))
    {
        (*reinterpret_cast<::s767610::HackingState * *>(&::g_pGame))->m_pkSelected = m_pkCursorTile;
        if (m_iStage < 2 && iKey == 9)
        {
            HandleClick(-1, 0);
            return true;
        }
        else if (m_iStage == 2)
        {
            switch (iKey)
            {
            case 4: {
                int iSavedIndex = m_iCursorIndex;
                bool bWord = (m_pkCursorTile && reinterpret_cast<::FUN_00a011f0_shell *>((m_pkCursorTile))->FUN_00a011f0(0xfc4))
                                 ? (std::isalpha(reinterpret_cast<::FUN_00a011f0_shell *>((m_pkCursorTile))->FUN_00a011f0(0xfc4)[reinterpret_cast<::FUN_00769700_cls *>(this)->GetScaledValue()]) ? 1 : 0)
                                 : 0;
                m_iCursorIndex -= 0x11;
                while (bWord && reinterpret_cast<::FUN_00769700_cls *>(this)->GetScaledValue() >= 7 &&
                       std::isalpha(reinterpret_cast<::FUN_00a011f0_shell *>((m_pkCursorTile))->FUN_00a011f0(0xfc4)[reinterpret_cast<::FUN_00769700_cls *>(this)->GetScaledValue()]))
                    m_iCursorIndex -= 0x11;
                if (reinterpret_cast<::FUN_00769700_cls *>(this)->GetScaledValue() < 7)
                {
                    if (reinterpret_cast<::TileListBoxCalls *>((m_pkCursorTile))->GetFloat(0x1004) > 0.0)
                    {
                        int iColIndex = (int)reinterpret_cast<::TileListBoxCalls *>((m_pkCursorTile))->GetFloat(0xfac);
                        int iNewRow = (int)reinterpret_cast<::TileListBoxCalls *>((m_pkCursorTile))->GetFloat(0x1004) - 1;
                        Tile* pkFound = ((::s767610::Tile *)(reinterpret_cast<::FUN_00767bb0_shell *>(this)->FUN_00767bb0(iColIndex, iNewRow)));
                        if (pkFound)
                        {
                            m_bBlink = false;
                            m_pkCursorTile = pkFound;
                            m_iCursorIndex =
                                (int)(reinterpret_cast<::FUN_00a013d0_shell *>((m_pkCursorTile))->GetTotalFloat() + reinterpret_cast<::TileListBoxCalls *>((m_pkCursorTile))->GetFloat(0xfb1) - 17.0);
                        }
                        else
                        {
                            m_iCursorIndex = iSavedIndex;
                        }
                    }
                    else
                    {
                        m_iCursorIndex = iSavedIndex;
                    }
                }
                else
                {
                    m_bBlink = false;
                }
                return true;
            }
            case 3: {
                int iSavedIndex = m_iCursorIndex;
                bool bWord = (m_pkCursorTile && reinterpret_cast<::FUN_00a011f0_shell *>((m_pkCursorTile))->FUN_00a011f0(0xfc4))
                                 ? (std::isalpha(reinterpret_cast<::FUN_00a011f0_shell *>((m_pkCursorTile))->FUN_00a011f0(0xfc4)[reinterpret_cast<::FUN_00769700_cls *>(this)->GetScaledValue()]) ? 1 : 0)
                                 : 0;
                m_iCursorIndex += 0x11;
                while (bWord && reinterpret_cast<::FUN_00769700_cls *>(this)->GetScaledValue() != -1 &&
                       std::isalpha(reinterpret_cast<::FUN_00a011f0_shell *>((m_pkCursorTile))->FUN_00a011f0(0xfc4)[reinterpret_cast<::FUN_00769700_cls *>(this)->GetScaledValue()]))
                    m_iCursorIndex += 0x11;
                if (reinterpret_cast<::FUN_00769700_cls *>(this)->GetScaledValue() == -1)
                {
                    if (reinterpret_cast<::TileListBoxCalls *>((m_pkCursorTile))->GetFloat(0x1004) < 1.0)
                    {
                        int iColIndex = (int)reinterpret_cast<::TileListBoxCalls *>((m_pkCursorTile))->GetFloat(0xfac);
                        int iNewRow = (int)reinterpret_cast<::TileListBoxCalls *>((m_pkCursorTile))->GetFloat(0x1004) + 1;
                        Tile* pkFound = ((::s767610::Tile *)(reinterpret_cast<::FUN_00767bb0_shell *>(this)->FUN_00767bb0(iColIndex, iNewRow)));
                        if (pkFound)
                        {
                            m_bBlink = false;
                            m_pkCursorTile = pkFound;
                            m_iCursorIndex = (int)(reinterpret_cast<::FUN_00a013d0_shell *>((m_pkCursorTile))->GetTotalFloat() + 119.0);
                        }
                        else
                        {
                            m_iCursorIndex = iSavedIndex;
                        }
                    }
                    else
                    {
                        m_iCursorIndex = iSavedIndex;
                    }
                }
                else
                {
                    m_bBlink = false;
                }
                return true;
            }
            case 1: {
                int iColumn = (int)reinterpret_cast<::TileListBoxCalls *>((m_pkCursorTile))->GetFloat(0xfac);
                if (iColumn > 0)
                {
                    m_bBlink = false;
                    m_pkCursorTile = ((::s767610::Tile *)(reinterpret_cast<::FUN_00767bb0_shell *>(this)->FUN_00767bb0(iColumn - 1, (unsigned int)reinterpret_cast<::TileListBoxCalls *>((m_pkCursorTile))->GetFloat(0x1004))));
                    return true;
                }
                break;
            }
            case 2: {
                int iColumn = (int)reinterpret_cast<::TileListBoxCalls *>((m_pkCursorTile))->GetFloat(0xfac);
                if (iColumn < 0x10)
                {
                    m_bBlink = false;
                    m_pkCursorTile = ((::s767610::Tile *)(reinterpret_cast<::FUN_00767bb0_shell *>(this)->FUN_00767bb0(iColumn + 1, (unsigned int)reinterpret_cast<::TileListBoxCalls *>((m_pkCursorTile))->GetFloat(0x1004))));
                    return true;
                }
                break;
            }
            }
        }
    }
    return false;
}

}

bool __cdecl FUN_00702450(int);
struct Sub4D4
{
};
struct Mgr4B7210
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
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    Sub4D4 m4D4;
};
struct Tile120
{
};
struct Global11d95bc
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
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    Tile120* mCC;
};
struct SubE0
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
};
struct Entry28
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
    void* tile2C;
};
struct Snd150
{
    int unk00;
    int unk04;
    int unk08;
};

struct DummyClass
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
    Entry28* entries[46];
    SubE0 mE0;
    int unk10C;
    int unk110;
    Tile120* m114;
    int unk118;
    Tile120* m11C;
    Tile120* m120;
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
    Snd150 m150;
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
    int m1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    Tile120* unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    char unk1D8;
    char unk1D9;
    unsigned char unk1DA;
    void FUN_00769830();
    void FUN_00767c90();
};

// Updates tile state based on unk1C4, handling fade, entry positioning, and active node property updates.
// @fnv 0x00767c90
void DummyClass::FUN_00767c90()
{
    unsigned int bbb;
    int j;
    if (unk24 != 1 || !FUN_00702450(FUN_00766a40()) ||
        (unk1DA && !reinterpret_cast<::S8840 *>(&(((Mgr4B7210*)((void *)(::fnv_004b7210::FUN_004b7210())))->m4D4))->FUN_00718840(0x13)))
    {
        return;
    }
    if ((((void *)(::fnv_004b7210::FUN_004b7210())), FUN_004b71d0()))
    {
        (*reinterpret_cast<::Global11d95bc * *>(&::g_pGame))->mCC = unk1C8;
    }
    reinterpret_cast<::TwTypewriter *>(&(mE0))->FUN_006ffea0();
    reinterpret_cast<::HackingMenuDecomp *>(this)->UpdateFade();
    switch (unk1C4)
    {
    case 0:
        FUN_00769830();
        break;
    case 1:
        for (bbb = 0; bbb < 46; ++bbb)
        {
            if (entries[bbb] && !((bool)(reinterpret_cast<::FUN_00759d80_Class *>((entries[bbb]))->FUN_00759d80())))
            {
                reinterpret_cast<::FUN_00ad8830_shell *>(&(m150))->FUN_00ad8830(false);
                reinterpret_cast<::TwTypewriter *>((entries[bbb]))->FUN_006ffea0();
                reinterpret_cast<::fnv_0076ac10::HackMenuStub *>(this)->PositionTileFromEntry((::fnv_0076ac10::HackEntry *)(entries[bbb]));
                break;
            }
        }
        if (bbb == 46)
        {
            Tile120* i;
            j = 0;
            for (i = m120; i && i != ((::Tile120 *)(reinterpret_cast<::FUN_0045cd60_shell *>((m11C))->FUN_0045cd60())); i = ((::Tile120 *)(reinterpret_cast<::FUN_0045cd60_shell *>((i))->FUN_0045cd60())))
            {
                j += (int)reinterpret_cast<::TileListBoxCalls *>((i))->GetFloat(0xfa2);
            }
            reinterpret_cast<::Tile *>((m11C))->Set(0xfa2, j);
            unk1C4 = 2;
        }
        break;
    case 2:
        reinterpret_cast<::Menu0076ab40 *>(this)->UpdateActiveNodeProperty();
        if (m1A0 == 1)
        {
            reinterpret_cast<::TwTypewriter *>((entries[1]))->FUN_006ffea0();
        }
        if ((*reinterpret_cast<::Global11d95bc * *>(&::g_pGame))->mCC && ((::Tile120 *)(reinterpret_cast<::FUN_0045cd60_shell *>(((*reinterpret_cast<::Global11d95bc * *>(&::g_pGame))->mCC))->FUN_0045cd60())) == m114)
        {
            reinterpret_cast<::HKMenu *>(this)->UpdateHighlight();
        }
        break;
    case 3:
        reinterpret_cast<::Menu0076ab40 *>(this)->UpdateActiveNodeProperty();
        reinterpret_cast<::HackingMenuV *>(this)->FUN_0076a3f0();
        break;
    case 4:
        reinterpret_cast<::Menu0076ab40 *>(this)->UpdateActiveNodeProperty();
        if (m1A0 && unk24 != 2)
        {
            reinterpret_cast<::FUN_0076a510_shell *>(this)->FUN_0076a510();
        }
        break;
    }
}

namespace H769769 {

struct H769Sound
{
    int unk00;
    int unk04;
    int unk08;
    ~H769Sound();
};
struct H769Player
{
    int unk00;
    int unk04;
    int unk08;
};
struct H769TileV
{
};
struct H769Line
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
    H769TileV* pText;
    H769TileV* kArgumentPosition;
};
struct H769Menu
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
    H769Line* pLines[14];
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
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    H769Player kFailSound;
    H769Player kSuccessSound;
    void FUN_00769830();
};
struct H769Audio
{
};
}
using namespace H769769;
extern unsigned int DAT_011d969c;
extern int DAT_011d9694;

// @fnv 0x00769830
void H769Menu::FUN_00769830()
{
    int i;

    for (i = 0; i < 14; i++)
    {
        if (((unsigned int)(::FUN_00457fe0())) > DAT_011d95c0)
        {
            reinterpret_cast<::Tile *>((pLines[0]->pText))->Set(0xfa3, 0);
        }
        else
        {
            reinterpret_cast<::Tile *>((pLines[0]->pText))->Set(0xfa3, 1);
        }
        if (pLines[i] && !((bool)(reinterpret_cast<::FUN_00759d80_Class *>((pLines[i]))->FUN_00759d80())))
        {
            if (pLines[i]->kArgumentPosition)
            {
                if (!reinterpret_cast<::FUN_00a01230_shell *>((pLines[i]->kArgumentPosition))->IsTraitNonZero(0xfa3))
                {
                    reinterpret_cast<::Tile *>((pLines[i]->kArgumentPosition))->Set(0xfa3, 1);
                    DAT_011d969c = ((unsigned int)(::FUN_00457fe0())) + 1000;
                }
                if (((unsigned int)(::FUN_00457fe0())) > DAT_011d969c)
                {
                    unsigned int uiStart4 = FUN_0044a670(reinterpret_cast<::FUN_00a011f0_shell *>((pLines[i]->pText))->FUN_00a011f0(0xfc4));
                    reinterpret_cast<::TwTypewriter *>((pLines[i]))->FUN_006ffea0();
                    unsigned int uiEnd = FUN_0044a670(reinterpret_cast<::FUN_00a011f0_shell *>((pLines[i]->pText))->FUN_00a011f0(0xfc4));
                    for (unsigned int j6 = 0; j6 < uiEnd - uiStart4; j6++)
                    {
                        static int s_iTypeTime =
                            (int)(*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingRef *>(&::g_011d4e4c)))))) > 1
                                      ? ::InventoryStackRecord::RoundToNearestStep((float)(1000.0 / *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingRef *>(&::g_011d4e4c))))))), 1.0f)
                                      : 1000.0f);
                        unsigned int uiDelay = j6 * s_iTypeTime / (uiEnd - uiStart4);
                        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::H769769::H769Sound &)((*(::H769769::H769Sound *)(reinterpret_cast<::AudioClass_ae5680 *>((((::H769769::H769Audio *)(::FUN_00ad9060()))))->ResolveAudioHandle((::Handle_ae5680 *)("UIHackingCharSingle"), 0x121, uiDelay)))))->SchedulePlayback({}, {});
                    }
                    if (((bool)(reinterpret_cast<::FUN_00759d80_Class *>((pLines[i]))->FUN_00759d80())))
                    {
                        reinterpret_cast<::FUN_00ad8830_shell *>(&(kSuccessSound))->FUN_00ad8830(0);
                        DAT_011d969c = ((unsigned int)(::FUN_00457fe0())) + 500;
                    }
                }
            }
            else if (((unsigned int)(::FUN_00457fe0())) > DAT_011d969c)
            {
                reinterpret_cast<::TwTypewriter *>((pLines[i]))->FUN_006ffea0();
                reinterpret_cast<::FUN_00ad8830_shell *>(&(kFailSound))->FUN_00ad8830(0);
            }
            reinterpret_cast<::fnv_0076ac10::HackMenuStub *>(this)->PositionTileFromEntry((::fnv_0076ac10::HackEntry *)(pLines[i]));
            break;
        }
    }
    if (i == 14 && ((unsigned int)(::FUN_00457fe0())) > DAT_011d969c)
    {
        reinterpret_cast<::Hack83 *>(this)->BuildHackingPasswordFile();
    }
}

// FUN_0076a540 - HackingMenu: open a hacking terminal menu tile.
// Adapted to the current pack (HackingMenu is fieldless; shell types by address).
extern char DAT_01072b00;

struct MenuPX
{
};
struct TilePX
{
};
struct FTerminalPX : FORenderedTerminal
{
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBc;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCc;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDc;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    FTerminalPX();
};
struct TileStatics
{
};


// Creates a computer menu tile, updates tile statics, and attaches it to a rendered terminal, creating a new FTerminalPX if none exists.
// @fnv 0x0076a540
void FUN_0076a510_shell::FUN_0076a540()
{
    (*(Tile**)((char*)this + 4))->Set(0x1772, 1);
    reinterpret_cast<::FUN_00a1d910_shell *>((((FUN_00766aa0_Menu*)this)))->FUN_00a1d910();
    if (*(int*)((char*)this + 0x194))
    {
        TilePX* pTile = ((::TilePX *)(::fnv_00757b70::CreateComputerMenu((::fnv_00757b70::Ref *)(*(const char**)((char*)this + 0x198)))));
        ::FUN_00867a20((void *)(((::MenuPX *)(reinterpret_cast<::FUN_00a03c90_shell *>((pTile))->FUN_00a03c90()))));
        ::fnv_00a04200::FUN_00a04200(false);
        FORenderedTerminal* r = dynamic_cast<FORenderedTerminal*>(FUN_00707ad0());
        if (!r)
        {
            ::FUN_005b5e40();
            r = new FTerminalPX;
        }
        reinterpret_cast<::TESPackage *>((((FTerminalPX*)r)))->SetProcedureType((::PACKAGE_PROCEDURE_TYPE)(pTile));
        reinterpret_cast<::NiPick *>((((FTerminalPX*)r)))->FUN_00705fc0(((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((pTile))->FUN_0056c7f0())));
    }
}

namespace grid76a {
struct G7Row
{
    unsigned char* pData;
    int iCount;
};
struct G7Grid
{
    G7Row* m_pRows;
    int iCount;
    G7Grid(unsigned char size);
    G7Grid(const G7Grid& other);
    ~G7Grid();
    G7Grid FUN_0076af90(const unsigned char* order, unsigned char size);
};
}
using namespace grid76a;

// Creates a new G7Grid by reordering rows and columns of this grid according to the given permutation order.
// @fnv 0x0076af90
G7Grid G7Grid::FUN_0076af90(const unsigned char* order, unsigned char size)
{
    G7Grid kResult(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            ((unsigned char *)(::FUN_00559450((int *)&(((::grid76a::G7Row *)(::FUN_00559450((int *)&(kResult))))[i]))))[j] = ((unsigned char *)(::FUN_00559450((int *)&(m_pRows[order[i]]))))[order[j]];
        }
    }
    return kResult;
}

namespace fnv_00765b80 {
struct Menu84;
struct Tile84;
struct Ref84;
struct Base84
{
};
struct Ref84
{
};
struct Color84
{
    float r, g, b, a;
    Color84(float, float, float, float);
};
struct Palette84
{
};
struct Setting84
{
};
struct Values84
{
};
struct Player84
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
    Values84 values;
};
struct Keys84
{
};
struct Interface84
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
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    Keys84 keys;
};
struct Tile84
{
};
struct Entry84
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    Tile84* tile;
    int unk30;
    Entry84(const char*, Tile84*, const char*, int, int);
};
struct Text84
{
    int unk00, unk04, unk08, unk0c;
};
struct Scroll84
{
};
struct Menu84
{
    virtual ~Menu84();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int Type();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Entry84* entries[46];
    Text84 text;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    Tile84* tile10c;
    int unk110;
    int unk114;
    int unk118;
    Tile84* tile11c;
    Tile84* tile120;
    Tile84* tile124;
    Tile84* tile128;
    Scroll84 scroll;
    unsigned char unk12d, unk12e, unk12f;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    Base84* terminal;
    Ref84* reference;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    unsigned char unk1d8, unk1d9;
    bool key;
    unsigned char unk1db;
};
void* operator new(unsigned int);
void operator delete(void*);
// Creates and configures the hacking menu from hacking_menu.xml, populating entries based on terminal difficulty and skill.
// @fnv 0x00765b80
Tile84* FUN_00765b80(Ref84* reference)
{
    Menu84* old40 = ((::fnv_00765b80::Menu84 *)(::FUN_00a09030(FUN_00766a40())));
    if (old40)
        delete old40;
    (*reinterpret_cast<::fnv_00765b80::Interface84 * *>(&::g_pGame)) = ((::fnv_00765b80::Interface84 *)(::fnv_004b7210::FUN_004b7210()));
    float screen13 = ::Tile::GetInterfaceScale();
    reinterpret_cast<::SystemColorManager *>((((::fnv_00765b80::Palette84 *)(::FUN_00718b60()))))->GetColor(3, (*(::NiColor *)(&(*reinterpret_cast<::fnv_00765b80::Color84 *>(&::DAT_011d9674)))));
    Base84* terminal14 = ((::fnv_00765b80::Base84 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()));
    if (((bool)(reinterpret_cast<::FUN_00757e80_shell *>((terminal14))->IsFlagBitSet())))
        reinterpret_cast<::FUN_007190e0_cls *>((((::fnv_00765b80::Palette84 *)(::FUN_00718b60()))))->ApplyToChild(3, (int)&(const ::fnv_00765b80::Color84 &)(Color84(1.0f, 1.0f, 1.0f, 0.0f)));
    (*reinterpret_cast<unsigned int *>(&::DAT_0119f27c)) = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d42d0))))));
    (*reinterpret_cast<unsigned int *>(&::DAT_0119f280)) = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d2934))))));
    Tile84* tile4 = ((::fnv_00765b80::Tile84 *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::fnv_00765b80::Tile84 *)(reinterpret_cast<::InterfaceManager *>(((*reinterpret_cast<::fnv_00765b80::Interface84 * *>(&::g_pGame))))->FUN_00586150()))))->FUN_00a01b00({})));
    Menu84* menu24 = ((::fnv_00765b80::Menu84 *)(reinterpret_cast<::FUN_00a03c90_shell *>((tile4))->FUN_00a03c90()));
    if (menu24 && menu24->Type() == FUN_00766a40())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((menu24))->FUN_00a1dc70((::TileMenu *)(tile4), 0);
        (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu)) = menu24;
        int missing1;
        if (!reinterpret_cast<::B766A50Menu *>(((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))))->HasAllSlots((*(int *)(&missing1))))
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (reinterpret_cast<::TileListBoxCalls *>((tile4))->GetFloat(4007) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((tile4))->GetFloat(4007) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((tile4))->FUN_00a012d0(4013, screen13, 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile124))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d31bc))))->GetMenuTitle()))), 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile128))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d30e4))))->GetMenuTitle()))), 1);
        Base84* base14 = reference ? ((::fnv_00765b80::Base84 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430())) : 0;
        if (base14 && reinterpret_cast<::PlayerCharShell *>(((*reinterpret_cast<::fnv_00765b80::Player84 * *>(&::_g_thePlayer))))->GetTerminalAccessResult((::TESObjectREFR *)(reference)) == 2)
        {
            reinterpret_cast<::Tile *>((tile4))->Set(4102, 1);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1c4 = 4;
            reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile11c))->Set(4003, 0);
        }
        else
        {
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->terminal = base14;
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->reference = reference;
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1ac =
                (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->terminal ? ((int)(reinterpret_cast<::FUN_00501270_shell *>(((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->terminal))->FUN_00501270((::TESObjectREFR *)((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->reference)))) : 12;
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1ac = ::FUN_0042f5a0(12, (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1ac);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->key = reinterpret_cast<::TutorialMessageGate718 *>(&((*reinterpret_cast<::fnv_00765b80::Interface84 * *>(&::g_pGame))->keys))->FUN_00718630(19, FUN_00766a40(), 512);
            float skill5 = reinterpret_cast<::ActorValueOwner *>(&((*reinterpret_cast<::fnv_00765b80::Player84 * *>(&::_g_thePlayer))->values))->GetActorValueFloatByIndex((::ActorValue::Index)(40));
            ::ApplyPerkModifiers(30, (::Actor *)((*reinterpret_cast<::fnv_00765b80::Player84 * *>(&::_g_thePlayer))), &skill5);
            unsigned int maximum12 = ::FUN_0042f5a0(20, *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d3318)))))));
            unsigned int minimum17 = ::FUN_0042f5a0(maximum12, *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d3c4c)))))));
            float difficulty4 =
                ::FUN_0040ebd0(100.0f, ::FUN_00404010(0.0f, reinterpret_cast<::TermHack *>(((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->terminal))->FUN_005017a0((::TESObjectREFR *)(reference))));
            float delta2 = ::FUN_00404010(0.0f, skill5 - difficulty4);
            float denominator55 = 100.0 - difficulty4;
            float fraction41 = denominator55 != 0.0 ? 1.0f - delta2 / denominator55 : 0.5;
            unsigned int count7 = minimum17 + (unsigned int)::InventoryStackRecord::RoundToNearestStep((maximum12 - minimum17) * fraction41, 1.0f);
            if (count7 > 20)
                count7 = 20;
            reinterpret_cast<::FUN_00768070_shell *>(((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))))->SelectWordSet(count7);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile4))->FUN_00a01350(4100, (char *)(">"), 1);
            reinterpret_cast<::FUN_006ffe80_shell *>(&((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->text))->FUN_006ffe80(((int)(reinterpret_cast<::FUN_00a00f30_shell *>(((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile120))->FUN_00a00f30(4036))),
                                            ((int)(reinterpret_cast<::FUN_00a00e90_shell *>(((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile120))->FindTraitValue(4003))));
            if (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d4e4c)))))) > 0)
                reinterpret_cast<::FUN_00766a10_shell *>(&((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->text))->SetCapacity((unsigned int)::InventoryStackRecord::RoundToNearestStep(1000.0 / *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d4e4c)))))), 1.0f));
            const char* name9 = "hacking_intro_template";
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[0] =
                new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d3f58))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9, (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4, 0);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[1] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d3a38))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                   (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 2, 0);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[2] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d3c64))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                   (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 4, 1);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[3] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d4c00))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                   (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 6, 0);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[4] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d4d5c))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                   (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 8, 1);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[5] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d3030))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                   (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 9, 1);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[6] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d4b94))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                   (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 11, 0);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[7] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d1f44))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                   (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 12, 0);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[8] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d1d9c))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                   (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 13, 0);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[9] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d306c))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                   (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 14, 0);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[10] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d484c))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                    (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 15, 0);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[11] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d4f18))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                    (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 16, 0);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[12] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d4690))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                    (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 17, 0);
            (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->entries[13] = new Entry84(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00765b80::Setting84 *>(&::g_011d2130))))->IsDLCAvailable())), (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->tile10c, name9,
                                                    (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b4 + (*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->unk1b8 * 19, 1);
        }
        reinterpret_cast<::FUN_00ad8830_shell *>(&((*reinterpret_cast<::fnv_00765b80::Menu84 * *>(&::g_pkD766AA0Menu))->scroll))->FUN_00ad8830(0);
        reinterpret_cast<::Menu *>((menu24))->SetMenuVisibility(0);
        return tile4;
    }
    else if (menu24 && reinterpret_cast<::Callees *>((menu24))->FUN_00726070())
        delete menu24;
    return 0;
}
}  // namespace fnv_00765b80

namespace fnv_00766b80 {
struct HackTile
{
    void* data;
    const char* Text();
};
struct HackSound
{
    unsigned int id;
    int a, b;
    void Fade(int, int);
};
struct HackString
{
    char* data;
    unsigned short length, capacity;
    HackString();
    ~HackString();
    operator const char*() const;
};
struct HackSetting
{
};
struct HackList
{
    int a, b, c;
    struct HackItem* RemoveTail();
};
struct HackNumberList
{
    int a, b, c;
};
struct HackItem
{
    virtual ~HackItem();
};
struct HackForm
{
    unsigned int Type();
};
struct HackRef
{
};
struct HackTarget
{
};
struct HackPlayer
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
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
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
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual void slot3e4();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual void slot3f8();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41c();
    virtual void slot420();
    virtual void slot424();
    virtual void slot428();
    virtual void slot42c();
    virtual void slot430();
    virtual void slot434();
    virtual void slot438();
    virtual void slot43c();
    virtual void slot440();
    virtual void slot444();
    virtual void slot448();
    virtual void slot44c();
    virtual void slot450();
    virtual void slot454();
    virtual void slot458();
    virtual void slot45c();
    virtual void slot460();
    virtual void slot464();
    virtual void slot468();
    virtual void slot46c();
    virtual void slot470();
    virtual void slot474();
    virtual void slot478();
    virtual void slot47c();
    virtual void slot480();
    virtual void slot484();
    virtual void Reward(int);
};
struct HackMenu
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    HackTile* tiles[46];
    HackTile text;
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
    HackTile* buttons[8];
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    HackSound success;
    HackSound fail;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    HackSound select;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    HackList list;
    unsigned int unk180;
    unsigned int unk184;
    HackNumberList used;
    HackTarget* target;
    HackRef* ref;
    const char* password;
    unsigned int attempts;
    unsigned int maxAttempts;
    int mode;
    unsigned int answer;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    int state;
    HackTile* selected;
    unsigned int unk1cc;
    unsigned int deadline;
    unsigned int unk1d4;
    bool changed;
    bool special;
    void FUN_00766b80(int index, HackTile* tile);
};
// Handles a tile click by comparing the entered word to the password, updating the display, and triggering success or failure outcomes based on the match result.
// @fnv 0x00766b80
void HackMenu::FUN_00766b80(int aiButtonIndex, HackTile* tile)
{
    ::fnv_004b7210::FUN_004b7210();
    if (::FUN_004b71d0())
        tile = selected;
    if (!tile && aiButtonIndex >= 0 && aiButtonIndex < 8)
        tile = buttons[aiButtonIndex];
    if (state == 0)
    {
        if (((unsigned int)(::FUN_00457fe0())) > ::DAT_011d95c0)
            reinterpret_cast<::Hack83 *>(this)->BuildHackingPasswordFile();
        return;
    }
    else if (state == 1)
    {
        for (unsigned int iter = 0; iter < 46; iter++)
            if (tiles[iter])
                reinterpret_cast<::FUN_00700110_cls *>((tiles[iter]))->FUN_00700110();
    }
    else if (state == 2 && tile && ((::fnv_00766b80::HackTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((tile))->FUN_0045cd60())) == buttons[2])
    {
        reinterpret_cast<::FUN_00700110_cls *>(&(text))->FUN_00700110();
        const char* word = text.Text();
        if (word && *word)
        {
            reinterpret_cast<::FUN_00ad8830_shell *>(&(select))->FUN_00ad8830(false);
            unsigned int matched = reinterpret_cast<::FUN_00768a10_shell *>(this)->CountMatchingChars(word, password);
            if (!std::isalpha(*word) && ::FUN_0044a670(word) > 1)
            {
                HackString c[3];
                unsigned int j;
                ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&c[0]), "%s%s", ">", word);
                if (mode == 1)
                {
                    ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&c[1]), "%s%s", ">", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d26dc))))->GetMenuTitle())));
                    j = 2;
                }
                else if (special || ::FUN_005a00a0(4))
                {
                    reinterpret_cast<::HackMenu *>(this)->RemoveRandomWord();
                    reinterpret_cast<::ScriptList *>(&(used))->FUN_0076b660((unsigned int *)&(const unsigned int &)(12 * (unsigned int)(reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(0x1004) * 17.0 + reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(0xfac)) + ((unsigned int)(reinterpret_cast<::FUN_00769700_cls *>(this)->GetScaledValue())) - 7));
                    ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&c[1]), "%s%s", ">", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d1e78))))->GetMenuTitle())));
                    j = 2;
                }
                else
                {
                    if (attempts == 1)
                    {
                        reinterpret_cast<::FUN_00759f20_shell *>((tiles[1]))->AssignString(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d430c))))->IsDLCAvailable())));
                        reinterpret_cast<::FUN_00726d50_class *>((tiles[1]))->FUN_00726d50(false);
                        reinterpret_cast<::FUN_00700110_cls *>((tiles[1]))->FUN_00700110();
                    }
                    ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&c[1]), "%s%s", ">", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d47e0))))->GetMenuTitle())));
                    ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&c[2]), "%s%s", ">", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d4f6c))))->GetMenuTitle())));
                    attempts = maxAttempts;
                    special = true;
                    reinterpret_cast<::ScriptList *>(&(used))->FUN_0076b660((unsigned int *)&(const unsigned int &)(12 * (unsigned int)(reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(0x1004) * 17.0 + reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(0xfac)) + ((unsigned int)(reinterpret_cast<::FUN_00769700_cls *>(this)->GetScaledValue())) - 7));
                    while (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(list))->GetName())) < maxAttempts)
                        reinterpret_cast<::FUN_0076ad50_cls *>(this)->BuildHackingGuessTemplate();
                    j = 3;
                }
                const char* e[3] = {c[0], c[1], c[2]};
                reinterpret_cast<::FUN_00767ef0_shell *>(this)->AddValueRows(j, (const unsigned int *)(e));
            }
            else if (matched == answer)
            {
                HackString c[5];
                ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&c[0]), "%s%s", ">", word);
                ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&c[1]), "%s%s", ">", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d2604))))->GetMenuTitle())));
                ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&c[2]), "%s%s", ">", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d3444))))->GetMenuTitle())));
                ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&c[3]), "%s%s", ">", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d4858))))->GetMenuTitle())));
                ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&c[4]), "%s%s", ">", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d4ae0))))->GetMenuTitle())));
                const char* e[5] = {c[0], c[1], c[2], c[3], c[4]};
                reinterpret_cast<::FUN_00767ef0_shell *>(this)->AddValueRows(5, (const unsigned int *)(e));
                reinterpret_cast<::SoundPlaybackHandle *>(&(success))->SchedulePlayback(250, 0);
                deadline = ((unsigned int)(::FUN_00457fe0())) + 3000;
                state = 4;
                if (target)
                {
                    ::FUN_005018b0((::Script *)(ref), true);
                    (*reinterpret_cast<::fnv_00766b80::HackPlayer * *>(&::_g_thePlayer))->Reward(::FUN_006705b0(2, reinterpret_cast<::FUN_00501270_shell *>((target))->FUN_005011a0((::TESObjectREFR *)(ref))));
                    HackForm* owner = ((::fnv_00766b80::HackForm *)(reinterpret_cast<::OwnerLookupView *>((ref))->FUN_00567790()));
                    if (owner)
                    {
                        int zero = 0;
                        if (owner->Type() == 8)
                        {
                            HackForm* faction = owner;
                        }
                        else
                        {
                            HackForm* npc = owner;
                        }
                        reinterpret_cast<::fnv_008c0ec0::Target *>(((*reinterpret_cast<::fnv_00766b80::HackPlayer * *>(&::_g_thePlayer))))->UpdateTargetUnits((int)(ref), (int)(owner), -1);
                    }
                }
                ::TopicMenuController::IncrementMiscStat(5);
            }
            else
            {
                HackString lines3[4];
                ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&lines3[0]), "%s%s", ">", word);
                ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&lines3[1]), "%s%s", ">", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d26dc))))->GetMenuTitle())));
                --attempts;
                if (attempts)
                {
                    ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&lines3[2]), "%s%d/%d %s.", ">", matched, answer, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d2b2c))))->GetMenuTitle())));
                    const char* values3[3] = {lines3[0], lines3[1], lines3[2]};
                    reinterpret_cast<::FUN_00767ef0_shell *>(this)->AddValueRows(3, (const unsigned int *)(values3));
                    if (attempts == 1)
                    {
                        reinterpret_cast<::FUN_00759f20_shell *>((tiles[1]))->AssignString(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d1f74))))->IsDLCAvailable())));
                        reinterpret_cast<::FUN_00700110_cls *>((tiles[1]))->FUN_00700110();
                        reinterpret_cast<::FUN_00726d50_class *>((tiles[1]))->FUN_00726d50(true);
                    }
                }
                else
                {
                    ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&lines3[2]), "%s%s", ">", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d3144))))->GetMenuTitle())));
                    ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&lines3[3]), "%s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d339c))))->GetMenuTitle())));
                    const char* values4[4] = {lines3[0], lines3[1], lines3[2], lines3[3]};
                    reinterpret_cast<::FUN_00767ef0_shell *>(this)->AddValueRows(4, (const unsigned int *)(values4));
                    state = 3;
                    if (target)
                        ::SetScriptLockState((::Script *)(ref), true);
                }
                reinterpret_cast<::SoundPlaybackHandle *>(&(fail))->SchedulePlayback(250, 0);
                delete list.RemoveTail();
            }
            HackString status;
            ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&status), "%d %s", attempts, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_00766b80::HackSetting *>(&::g_011d2e20))))->GetMenuTitle())));
            reinterpret_cast<::FUN_00759f20_shell *>((tiles[2]))->AssignString(status);
            reinterpret_cast<::FUN_00700110_cls *>((tiles[2]))->FUN_00700110();
            reinterpret_cast<::FUN_00768020_holder *>(this)->FUN_00768020();
            changed = true;
        }
    }
}
}  // namespace fnv_00766b80
