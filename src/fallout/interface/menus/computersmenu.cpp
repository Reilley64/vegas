
// src/fallout/interface/menus/computersmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/computersmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fallout/interface/tile_fields.h"
#include <cstdint>
#include "fnv/simple_list_node_view.h"
#include "fallout/interface/menu_fields.h"
#include <new>
#include "fnv/decl/AGOwner.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AudioClass_ae5680.h"
#include "fnv/decl/BSFaceGenKeyframe.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00461150_shell.h"
#include "fnv/decl/FUN_00470440.h"
#include "fnv/decl/FUN_004ed8c0_shell.h"
#include "fnv/decl/FUN_00501270_shell.h"
#include "fnv/decl/FUN_00501830_shell.h"
#include "fnv/decl/FUN_00501ae0_shell.h"
#include "fnv/decl/FUN_005e8d40_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00700110_cls.h"
#include "fnv/decl/FUN_007001f0_Class.h"
#include "fnv/decl/FUN_007190e0_cls.h"
#include "fnv/decl/FUN_0071aa60_class.h"
#include "fnv/decl/FUN_007242c0_shell.h"
#include "fnv/decl/FUN_00726cf0.h"
#include "fnv/decl/FUN_0073ac90_shell.h"
#include "fnv/decl/FUN_00759450_shell.h"
#include "fnv/decl/FUN_00759d80_Class.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_007b5330_Class.h"
#include "fnv/decl/FUN_007ffaf0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00a00e90_shell.h"
#include "fnv/decl/FUN_00a00f30_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a07530_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FontManager.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/LBList.h"
#include "fnv/decl/LBList_7314c0.h"
#include "fnv/decl/ListOwner.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/P03Value.h"
#include "fnv/decl/PerkEntryConditionSet.h"
#include "fnv/decl/PlayerCharacter.h"
#include "fnv/decl/PlayerNoteStub.h"
#include "fnv/decl/RenderTile.h"
#include "fnv/decl/S8840.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/SystemColorManager.h"
#include "fnv/decl/TextLayout__Font.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/TwTypewriter.h"
#include "fnv/decl/VLList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_005bd5c0__FUN_005bd5c0_shell.h"
#include "fnv/decl/fnv_0075b020__FUN_0075b020_cls.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a09200__Value_00a09200.h"
#include "fnv/decl/fnv_00a09410__EvalValue.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/sa040a0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_00721000.h"
#include "fnv/symbols_00726000.h"
#include "fnv/symbols_00757000.h"
#include "fnv/symbols_00759000.h"
#include "fnv/symbols_007ff000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0119f000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/image_space_effect_param.h"
class Tile
{
  public:
    Tile* pParent;
public:
    void Set(int, int);
public:
    bool GetSpeechChallengeFailure();
public:
    static float GetInterfaceScale();
public:
    void SetSpeechChallengeFailure(bool);
};

struct ComputersMenu
{
    char _base[0x28];
    Tile* m_pTiles[64];
    void FUN_00754c00(int aiID, Tile* apTile);
};

// Stores apTile into the tile slot at index aiID when aiID is in [0, 0x10).
// @fnv 0x00754c00
void ComputersMenu::FUN_00754c00(int aiID, Tile* apTile)
{
    if (aiID >= 0 && aiID < 0x10)
    {
        m_pTiles[aiID] = apTile;
    }
}

namespace fnv_00757a10 {
struct ComputersMenu
{
    int GetMenuId();
};

// @fnv 0x00757a10
int ComputersMenu::GetMenuId()
{
    return 0x421;
}
}  // namespace fnv_00757a10

// @fnv 0x00757e20
int FUN_00757e20()
{
    return 0x421;
}

struct FUN_00757e80_shell
{
    char pad00[0xa5];
    unsigned char unka5;

    unsigned char IsFlagBitSet();
};

// @fnv 0x00757e80
unsigned char FUN_00757e80_shell::IsFlagBitSet()
{
    return ((this->unka5 & 4) != 0);
}

struct FUN_00758390_shell
{
    char pad00[0x74];
    signed char m_74;
    bool FUN_00758390();
};

// @fnv 0x00758390
bool FUN_00758390_shell::FUN_00758390()
{
    return (this->m_74 & 2) != 0;
}

struct FUN_00758a60_shell
{
    char m_74;
    bool FUN_00758a60();
    char pad01[0x73];
    char unk74;
};

// @fnv 0x00758a60
bool FUN_00758a60_shell::FUN_00758a60()
{
    return (this->unk74 & 4) != 0;
}

namespace fnv_007596a0 {
class Tile
{
};
extern char $SG7172[];

// @fnv 0x007596a0
void __cdecl FUN_007596a0(Tile* apTile, void* apMenuItem)
{
    if (apTile)
        reinterpret_cast<::Tile *>((apTile))->Set(::FUN_00a00940($SG7172, -1), 1);
}
}  // namespace fnv_007596a0

struct S757a20
{
    void FUN_00757a50();
    void* FUN_00757a20(unsigned int);
};
struct FUN_00757e30_Class
{
    char _pad[0x28];
    Tile* arr[16];
    bool HasAllTiles(int* p);
};
// Checks that all 16 entries of arr are non-null, returning 0 on the first null and 1 otherwise.
// @fnv 0x00757e30
bool FUN_00757e30_Class::HasAllTiles(int* piIndex)
{
    for (*piIndex = 0; *piIndex < 0x10; (*piIndex)++)
    {
        if (arr[*piIndex] == 0)
            return 0;
    }
    return 1;
}

struct FUN_00758350_shell
{
    char m_6c[4];
    bool FUN_00758350();
    char pad04[0x68];
    int unk6c;
    char pad70[0x4];
    signed char unk74;
};
// Returns true when the int at offset 0x6c is nonzero and bit 0 of the byte at offset 0x74 is set.
// @fnv 0x00758350
bool FUN_00758350_shell::FUN_00758350()
{
    return this->unk6c && ((this->unk74 & 1));
}

struct Helper98
{
    void _ref_0063f7b0();
};
struct DispHelper
{
};
void __cdecl RefreshF57EA0TerminalMenu();
struct FUN_00758a80_shell
{
    char pad00[0xa8];
    int unka8;

    void FUN_00758a80();
};
struct StartMenu
{
    char const* GetMenuTitle();
};
extern StartMenu* DAT_01189e94[];
struct Host
{
    char _pad[0xA6];
    unsigned char mA6;
    char const* FUN_00758fe0();
};
// @fnv 0x00758fe0
char const* Host::FUN_00758fe0()
{
    return mA6 < 10 ? DAT_01189e94[mA6]->GetMenuTitle() : 0;
}

struct GlobalObject_0048f200
{
    GlobalObject_0048f200();
};
GlobalObject_0048f200::GlobalObject_0048f200()
{}
struct FUN_00759760_shell : GlobalObject_0048f200
{
    FUN_00759760_shell();
};
// @fnv 0x00759760
FUN_00759760_shell::FUN_00759760_shell()
{}

struct S_7597c0
{
    int FUN_007597c0(int);
};
extern S_7597c0* DAT_011d9338;
// Calls FUN_007597c0(1) on DAT_011d9338 if non-null, then sets DAT_011d9338 to null.
// @fnv 0x00759780
void FUN_00759780()
{
    S_7597c0* b = DAT_011d9338;
    S_7597c0* a = b;
    a ? a->FUN_007597c0(1) : 0;
    DAT_011d9338 = 0;
}

struct FUN_007597c0_shell
{
    void FUN_007597f0();
    void* FUN_007597c0(unsigned int flags);
};
// Calls FUN_007597f0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x007597c0
void* FUN_007597c0_shell::FUN_007597c0(unsigned int flags)
{
    FUN_007597f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Holder
{
    void FUN_00759850();
};
namespace fnv_007597f0 {
struct GlobalObject_0048f200
{
    ~GlobalObject_0048f200();
};
struct FUN_007597f0 : GlobalObject_0048f200
{
    ~FUN_007597f0();
};
// Destructor that calls FUN_00759850 on this object before the base GlobalObject_0048f200 destructor runs.
// @fnv 0x007597f0
FUN_007597f0::~FUN_007597f0()
{
    ((::Holder*)this)->FUN_00759850();
}
}  // namespace fnv_007597f0

struct ArrHelper
{
};
struct ScriptObj
{
};
struct ListBase
{
    ScriptObj* RemoveHead();
};
struct FUN_007598a0_shell
{
    void* FUN_007598a0(unsigned int flags);
};
// @fnv 0x00759850
void Holder::FUN_00759850()
{
    while (!reinterpret_cast<::FUN_0076b610_Class *>((void *)(((ArrHelper*)this)))->FUN_0076b610())
    {
        ScriptObj* pB = ((ListBase*)this)->RemoveHead();
        ScriptObj* pA = pB;
        pA ? ((std::intptr_t)(reinterpret_cast<::FUN_007598a0_shell *>((pA))->FUN_007598a0(1))) : 0;
    }
}
// Calls FUN_00726cf0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007598a0
void* FUN_007598a0_shell::FUN_007598a0(unsigned int flags)
{
    reinterpret_cast<::FUN_00726cf0 *>(this)->FUN_00726cf0::~FUN_00726cf0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Flt
{
    operator unsigned int();
};
struct TL
{
};
struct NoArgumentMethodObject
{
};
struct TileProcessor
{
    void* head;

    void ProcessAllTiles();
};
// @fnv 0x00759f50
void TileProcessor::ProcessAllTiles()
{
    void* piter = head;
    while (piter)
    {
        reinterpret_cast<::FUN_00700110_cls *>((((NoArgumentMethodObject*)((::Tile *)(reinterpret_cast<::ListStandIn *>((((TL*)this)))->FUN_0057cbe0((int **)&(piter)))))))->FUN_00700110();
    }
}


struct FUN_0075aa20_shell
{
    void FUN_0075a060();
    void* FUN_0075aa20(unsigned int flags);
};

struct FUN_007583b0_shell
{
    char _pad[0x74];
    signed char m_74;
    void SetFlag4(bool aFlag);
};

// @fnv 0x007583b0
void FUN_007583b0_shell::SetFlag4(bool aFlag)
{
    if (aFlag)
        m_74 |= 4;
    else
        m_74 &= ~4;
}

class BSSimpleList
{
};

struct FUN_0075aa50_shell
{
};

struct FUN_0075a5e0_shell
{
    char _pad[4];
    BSSimpleList m_kNode;
    void FUN_0075a5e0(int(__cdecl* f)(void*, void*));
};

struct InterfaceH
{
    static bool __cdecl GetSelectedTargetIndex(int);
};
struct TV
{
};
struct FUN_007583f0_shell
{
    char _pad[0x30];
    Tile* pTile30;
    char _pad2[0xbc - 0x34];
    const char* m_pText;
    bool HandleButtonInput(int aiButton, float afValue);
};

// @fnv 0x007583f0
bool FUN_007583f0_shell::HandleButtonInput(int aiButton, float afValue)
{
    if (InterfaceH::GetSelectedTargetIndex(0x421))
    {
        switch (aiButton)
        {
        case 0xa:
            if (reinterpret_cast<::sa040a0::Owner *>((reinterpret_cast<TV*>(pTile30)))->IsAllChildrenFlag0())
            {
                m_pText = 0;
                (*(void(**)(FUN_007583f0_shell*, int, int))(*(intptr_t*)this + 0xc))(this, 2, 0);
            }
            else
            {
                reinterpret_cast<FUN_00758a80_shell*>(this)->FUN_00758a80();
            }
            return true;
        }
    }
    return false;
}

struct FUN_00a01230_shell
{
    bool IsTraitNonZero(int);
};

struct FUN_0075ab20_shell
{
    char _pad[0x0C];
    Tile* m_pTile;
    bool IsTileTraitEnabled();
};

extern int DAT_011d93d8;
extern int DAT_011d93dc;

// Returns true when m_pTile is set and its trait lookup for the cached "_enabled" trait index succeeds.
// @fnv 0x0075ab20
bool FUN_0075ab20_shell::IsTileTraitEnabled()
{
    static int trait = ::FUN_00a00940("_enabled", -1);

    return m_pTile && reinterpret_cast<FUN_00a01230_shell*>(m_pTile)->IsTraitNonZero(trait);
}


struct M788
{
};

struct GO
{
    operator unsigned int();
};

struct NiTPointerList
{
};

struct FUN_006ffe80_shell
{
    void FUN_006ffe80(intptr_t, intptr_t);
};

struct FUN_00726db0_class
{
    bool FUN_00726db0(bool);
};

struct FUN_00759eb0
{
    char _pad[0x2c];

    FUN_00759eb0(char const*);
};

struct FUN_007b5330_shell
{
};

struct FUN_00759da0_shell : FUN_007b5330_shell
{
    void InsertAtPosition(char const*, intptr_t, intptr_t, int);
};

// @fnv 0x00759da0
void FUN_00759da0_shell::InsertAtPosition(char const* aParam1, intptr_t aParam2, intptr_t aParam3, int aParam4)
{
    FUN_00759eb0* pNewObject = new FUN_00759eb0(aParam1);

    reinterpret_cast<FUN_006ffe80_shell*>(pNewObject)->FUN_006ffe80(aParam2, aParam3);

    if (aParam4 == -1)
    {
        reinterpret_cast<::FUN_004ed8c0_shell *>((reinterpret_cast<M788*>(this)))->FUN_004ed8c0((int *)(void *)(reinterpret_cast<void*>(&pNewObject)));
    }
    else
    {
        uintptr_t pNode = reinterpret_cast<GO*>(this)->operator unsigned int();

        for (int i = 0; pNode != 0 && i < aParam4; ++i)
        {
            pNode = reinterpret_cast<uintptr_t>(
                ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>((reinterpret_cast<NiTPointerList*>(this)))->DereferenceIfNotNull((int **)(void *)(reinterpret_cast<void*>(pNode))))));
        }

        if (pNode != 0)
        {
            reinterpret_cast<::FUN_007b5330_Class *>((this))->FUN_007b5330((intptr_t)(reinterpret_cast<void*>(pNode)), (int *)(void *)(reinterpret_cast<void*>(&pNewObject)));
        }
        else
        {
            reinterpret_cast<::FUN_004ed8c0_shell *>((reinterpret_cast<M788*>(this)))->FUN_004ed8c0((int *)(void *)(reinterpret_cast<void*>(&pNewObject)));
        }
    }

    reinterpret_cast<FUN_00726db0_class*>(pNewObject)->FUN_00726db0(false);
}

struct MenuBase
{
    virtual ~MenuBase();
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
};
struct Obj68
{
    int a;
    ~Obj68();
};
struct SList
{
    void* head;
    void* next;
    ~SList();
};
struct BStr
{
    char* p;
    short len;
    short max;
    ~BStr();
};
struct SoundH
{
    int a;
    int b;
    int c;
    ~SoundH();
};
struct SysColorMgr
{
};
void FUN_00759780();
struct FUN_00757a50 : MenuBase
{
    Obj68 m68;
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
    SList list98;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    BStr strB4;
    int unkbc;
    int unkc0;
    SoundH sounds[3];
    virtual ~FUN_00757a50();
};
// Calls FUN_00757a50, then if bit 0 of flags is set calls _Deallocate on this, and returns this.
// @fnv 0x00757a20
void* S757a20::FUN_00757a20(unsigned int flags)
{
    reinterpret_cast<::FUN_00757a50 *>(this)->FUN_00757a50::~FUN_00757a50();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00757a50
FUN_00757a50::~FUN_00757a50()
{
    (*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)) = 0;
    FUN_00759780();
    reinterpret_cast<::FileMatchList *>(&(list98))->RemoveAll();
    for (int i = 0; i < 3; i++)
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(sounds[i]))->FUN_00ad88f0();
        reinterpret_cast<::SoundPlaybackHandle *>(&(sounds[i]))->Release();
    }
    reinterpret_cast<::FUN_007190e0_cls *>((((::SysColorMgr *)(::FUN_00718b60()))))->ApplyToChild(3, (intptr_t)(&DAT_011d934c));
}

struct BlinkValue
{
    void FUN_00a0a270(float, bool);
};
struct TraitValueCollection
{
};
struct BlinkMenu
{
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
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    TraitValueCollection* tile;
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
    BlinkValue* value;
    void UpdateBlink();
};
// Toggles the blink value between 0 and 1 once the tick interval elapses, or fetches the value from the tile if missing.
// @fnv 0x007585a0
void BlinkMenu::UpdateBlink()
{
    static unsigned int nextTick = 0;
    static float interval = reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(::FUN_00a00940("_blink_interval", -1));
    if (((unsigned int)(::FUN_00457fe0())) > nextTick && value)
    {
        value->FUN_00a0a270(reinterpret_cast<::BSFaceGenKeyframe *>((value))->GetTime() == 1.0 ? 0.0f : 1.0f, true);
        nextTick = ((unsigned int)(::FUN_00457fe0())) + interval;
    }
    else if (!value)
    {
        value = ((::BlinkValue *)(reinterpret_cast<::FUN_00a00e90_shell *>((tile))->FindTraitValue(4003)));
    }
}

struct BSStringT
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT(const char* apStr);
    ~BSStringT();
    BSStringT& operator+=(const char* apStr);
    operator const char*() const;
};

struct TileValue;

struct MenuTile
{
};


struct NoteFlags
{
};

struct NoteEntry
{
    BSStringT kName;
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
    NoteFlags kFlags;
};

struct GameSettingString
{
    const char* String();
};

struct NoteTextSetter
{
};

// Sets the tile's enabled state and text from a note entry, marking unread notes as read and applying the text setter when shown.
// @fnv 0x00759560
void UpdateNoteTile(MenuTile* apTile, NoteEntry* apEntry)
{
    if (apTile)
    {
        BSStringT kText("> ");
        int iState = 1;
        bool bShow = true;
        reinterpret_cast<::Tile *>((apTile))->Set(::FUN_00a00940("_enabled", -1), 0);
        if (apEntry && reinterpret_cast<::PerkEntryConditionSet *>(&(apEntry->kFlags))->ContainsTrait((::TESObjectREFR *)(0), (::TESObjectREFR *)(0)))
        {
            if (reinterpret_cast<::FUN_00758a60_shell *>((apEntry))->FUN_00758a60())
            {
                iState = 2;
                reinterpret_cast<::FUN_007583b0_shell *>((apEntry))->SetFlag4(false);
            }
            kText += apEntry->kName;
        }
        else if (!apEntry)
        {
            kText += (*reinterpret_cast<::GameSettingString *>(&::g_011d2cb8)).String();
        }
        else
        {
            bShow = false;
        }
        reinterpret_cast<::Tile *>((apTile))->Set(0xfd6, iState);
        if (bShow)
        {
            reinterpret_cast<::FUN_00759da0_shell *>((((::NoteTextSetter *)(::GetStorageSingleton()))))->InsertAtPosition({}, {}, {}, {});
        }
    }
}

struct FUN_00759760_storage : FUN_00759760_shell
{
    int unk00;
    int unk04;
    int unk08;
};
// Allocates a FUN_00759760_storage instance into DAT_011d9338 if it is null, then returns DAT_011d9338.
// @fnv 0x007596d0
S_7597c0* __cdecl GetStorageSingleton()
{
    if (!DAT_011d9338)
        DAT_011d9338 = reinterpret_cast<S_7597c0*>(new FUN_00759760_storage());
    return DAT_011d9338;
}

// Destructor: release the entries, unregister this object, then the entry list member is destroyed.

class A060EntryList
{
  public:
    ~A060EntryList();
    void* m_pkHead;
    void* m_pkTail;
};

class FUN_0075a060;

class FUN_0075a060
{
  public:
    virtual ~FUN_0075a060();
    void Clear();

    A060EntryList m_kEntries;
};
// Calls FUN_0075a060, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0075aa20
void* FUN_0075aa20_shell::FUN_0075aa20(unsigned int flags)
{
    reinterpret_cast<::FUN_0075a060 *>(this)->FUN_0075a060::~FUN_0075a060();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Shell
{
};

struct ParamShell
{
};


class SetTileHelper
{
  public:
    char _pad[0x10];
    Tile* m_pTile10;

    bool FUN_0075a610(Tile* apTile);
};

struct b9165Obj
{
};

struct b9165Inner
{
    b9165Obj* m_00;
    char unk04[4];
    unsigned char m_08;
};

struct b9165Ref
{
    b9165Inner* p;
};

struct b9165Node
{
    char unk00[0x18];
};

struct FUN_0075aa50_cls
{
    char unk00[4];
    b9165Node m_04;
    unsigned short m_1c;
    char unk1e[2];
    float m_20;
    void UpdateScrollItems();
    void ResetAndProcessNodes();
};
// Sorts the list using the given comparison function, then calls ResetAndProcessNodes on this object.
// @fnv 0x0075a5e0
void FUN_0075a5e0_shell::FUN_0075a5e0(int(__cdecl* f)(void*, void*))
{
    reinterpret_cast<::ItemChangeList *>(&(m_kNode))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(f));
    reinterpret_cast<::FUN_0075aa50_cls *>((reinterpret_cast<FUN_0075aa50_shell*>(this)))->ResetAndProcessNodes();
}

// Refresh the terminal menu tile; if the rendered menu is showing this menu's scene, refresh the rendered terminal too.

class InterfaceManager;
class NiNode;

class F57EA0Tile
{
  public:
};

class FORenderedMenu
{
  public:
    virtual ~FORenderedMenu();
    NiNode* GetSceneNode();
};

class FORenderedTerminal : public FORenderedMenu
{
  public:
};

class F57EA0Menu
{
  public:
};



// @fnv 0x00757ea0
void RefreshF57EA0TerminalMenu()
{
    if (g_pF57EA0TerminalMenu)
    {
        ::FUN_007ffe40();
        reinterpret_cast<::FUN_00a012d0_t *>((((::F57EA0Tile *)(reinterpret_cast<::MenuFields *>((g_pF57EA0TerminalMenu))->tile))))->FUN_00a012d0(0xfc1, ::DAT_01016264, true);
        if (reinterpret_cast<::InterfaceManager *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->GetActiveRenderedMenu() &&
            reinterpret_cast<::InterfaceManager *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->GetActiveRenderedMenu()->GetSceneNode() ==
                ((::NiNode *)(reinterpret_cast<::TileFields *>((((::F57EA0Tile *)(reinterpret_cast<::MenuFields *>((g_pF57EA0TerminalMenu))->tile))))->renderedNode)))
        {
            FORenderedTerminal* pkTerminal =
                dynamic_cast<FORenderedTerminal*>(reinterpret_cast<::InterfaceManager *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->GetActiveRenderedMenu());
            reinterpret_cast<::FUN_007ffaf0_shell *>((pkTerminal))->FUN_007ffaf0();
        }
        reinterpret_cast<::Tile *>((((::F57EA0Tile *)(reinterpret_cast<::MenuFields *>((g_pF57EA0TerminalMenu))->tile))))->Set(0x1772, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>((g_pF57EA0TerminalMenu))->FUN_00a1d910();
    }
}

namespace fnv_00758470 {
struct InterfaceManager;
struct S8840
{
};
struct InterfaceManager
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
    S8840 unk4d4;
};
struct HH84
{
    void ProcessQueue();
};
struct Tile_Set_Helper
{
};
class TESObjectREFR;
template <class T> struct ListBox
{
    void Traverse(void (*f)(Tile*, T), int, int);
};
extern unsigned int DAT_011d93c4;
struct CompMenu
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
    Tile_Set_Helper* tile3c;
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
    ListBox<TESObjectREFR*> list68;
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
    unsigned int unka0;
    int unka4;
    int unka8;
    int unkac;
    int iStateB0;
    int unkb4;
    int unkb8;
    int unkbc;
    bool bC0;
    bool bC1;
    char unkc2;
    char unkc3;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    HH84* pE8;
    void FUN_00758470();
    void RefreshDisplay();
};
// @fnv 0x00758470
void CompMenu::FUN_00758470()
{
    if ((bC0 && !reinterpret_cast<::S8840 *>(&(((::fnv_00758470::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->unk4d4))->FUN_00718840(0x18)) || unk24 == 2)
        return;
    pE8->ProcessQueue();
    reinterpret_cast<::BlinkMenu *>(this)->UpdateBlink();
    if (!reinterpret_cast<::FUN_00620b80_shell *>((pE8))->GetReferenceFlags())
    {
        if (iStateB0 < 2)
        {
            if (iStateB0 == 0)
            {
                DAT_011d93c4 = ((unsigned int)(::FUN_00457fe0())) + 2000;
                iStateB0 = 1;
            }
            else if (iStateB0 == 1)
            {
                if (((unsigned int)(::FUN_00457fe0())) > DAT_011d93c4)
                    RefreshDisplay();
            }
        }
        else if (bC1)
        {
            reinterpret_cast<::LBList_7314c0 *>(&(list68))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(((void (&)(Tile *, fnv_00758470::TESObjectREFR *))::fnv_007596a0::FUN_007596a0)), 0, 0x7fffffff);
            bC1 = 0;
        }
    }
    if (unka0 && ((unsigned int)(::FUN_00457fe0())) > unka0)
    {
        unka0 = 0;
        reinterpret_cast<::Tile *>((tile3c))->Set(0xfa3, 0);
    }
}
}  // namespace fnv_00758470

struct CHValue
{
};

struct CHTile
{
};

struct CHString
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;

    CHString();
    ~CHString();
};


struct CHSetting
{
    const char* GetString();
};

struct CHUIntSetting
{
};

struct CHCondition
{
};

struct CHChallenge;

struct CHListNode
{
    CHChallenge* pItem;
    CHListNode* pNext;

};

struct CHDescription
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual const char* Get(CHChallenge* apForm, unsigned int auiChunk);
};

struct CHChallenge
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
    CHCondition kCondition;
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
    CHDescription kDescription;

};

struct CHSimpleList
{
    CHChallenge* pItem;
    CHListNode* pNext;

    void AddHead(CHChallenge*& arItem);
};

struct CHListBox
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Clear();
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

};

struct CHDisplay
{
};


struct CHMenu
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
    CHTile* pTile44;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    CHTile* pTile64;
    CHListBox kListBox;
    CHSimpleList kRecent;
    short unkA0;
    short unkA2;
    int unkA4;
    CHChallenge* pChallenge;
    void* pSubject;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    char unkC0;
    bool bRefreshed;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    CHDisplay* pDisplay;

    void FUN_007586e0(bool abAddRecent);
};
// @fnv 0x00758a80
void FUN_00758a80_shell::FUN_00758a80()
{
    ((Helper98*)((char*)this + 0x98))->_ref_0063f7b0();
    this->unka8 = *(((int *)(&reinterpret_cast<::SimpleListNodeView*>(((Helper98*)((char*)this + 0x98)))->m_item)));
    if (this->unka8 != 0)
        reinterpret_cast<::CHMenu *>((((DispHelper*)this)))->FUN_007586e0(0);
    else
        RefreshF57EA0TerminalMenu();
}

class TESSound
{
  public:
};

class TESDescription;
class BGSNote
{
  public:
    TESSound* FUN_005e9100();
public:
    ::TESDescription *GetNoteDescription();
};

struct BSAudio
{
  public:
};

struct FUN_00483710
{
    int unk;
    int unkCur;
    int unkValue;

    ~FUN_00483710();
};

struct FUN_00ad73b0_t
{
    FUN_00483710 FUN_00ad73b0(unsigned int auiFormID, unsigned int auiFlags);
};

struct Shell_759030
{
    void PlayNoteSound(BGSNote* apNote);
};

// @fnv 0x00759030
void Shell_759030::PlayNoteSound(BGSNote* apNote)
{
    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const struct ::FUN_00483710 &)(((FUN_00ad73b0_t*)::FUN_00453a70())
        ->FUN_00ad73b0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apNote->FUN_005e9100()))->FUN_0084e3a0())), 0x101)))->FUN_00ad8830(false);
}

struct Setting
{
};
struct TextTile
{
};
struct TextString
{
    char* text;
    unsigned short len, capacity;
    operator const char*() const;
public:
    bool FUN_004037f0(const char *, unsigned int);
};
namespace TextLayout {
struct Layout
{
    Layout(int, int, int, int, int);
    ~Layout();
    operator const char*() const;
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int consumed;
    int unk1c;
    int unk20;
    int unk24;
};
}
struct TextFont
{
};
struct TextFonts
{
};
struct TextAnimator
{
    void Clear();
};
struct TextSource;
struct TextSourceInterface
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual const char* GetText(TextSource*, int, int);
};
struct TextSource
{
};
struct TextMenu
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    TextTile* field2c;
    TextTile* field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    TextTile* field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    TextTile* field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    int fielda0;
    int fielda4;
    int fielda8;
    int fieldac;
    int fieldb0;
    TextString buffer;
    const char* fieldbc;
    int fieldc0;
    int fieldc4;
    int fieldc8;
    int fieldcc;
    int fieldd0;
    int fieldd4;
    int fieldd8;
    int fielddc;
    int fielde0;
    int fielde4;
    TextAnimator* fielde8;

    void SetTextSource(TextSource*);
};

// Clears the animator, configures tiles, fetches and formats the source text into a layout, then advances the text pointer past the consumed characters.
// @fnv 0x007590c0
void TextMenu::SetTextSource(TextSource* source)
{
    reinterpret_cast<::TileProcessor *>((fielde8))->ProcessAllTiles();
    DAT_0119f278 = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011d4bb8)))))) > 0 ? 1000 / *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011d4bb8)))))) : 1000;
    reinterpret_cast<::Tile *>((field2c))->Set(0xfa3, 0);
    reinterpret_cast<::Tile *>((field30))->Set(0xfa9, 0);
    reinterpret_cast<::Tile *>((field30))->Set(0xfa3, 1);
    if (fieldbc == 0)
    {
        reinterpret_cast<::TextString *>(&(buffer))->FUN_004037f0(((::TextSourceInterface *)(reinterpret_cast<::BGSNote *>((source))->GetNoteDescription()))->GetText(source, 0x4d414e54, 0), {});
        fieldbc = buffer;
    }
    int lines = (int)(((double)(reinterpret_cast<::TileListBoxCalls *>((field60))->GetFloat(0xfbc))) -
                      ((double)(reinterpret_cast<::TileListBoxCalls *>((field44))->GetFloat(0xfb0))) / reinterpret_cast<::FUN_00759450_shell *>((((::TextFont *)(reinterpret_cast<::fnv_005bd5c0::FUN_005bd5c0_shell *>((((::TextFonts *)(::FontManager::Instance()))))->FUN_005bd5c0((int)((double)(reinterpret_cast<::TileListBoxCalls *>((field44))->GetFloat(0xfb9))) - 1)))))->FUN_00759450()) +
                1;
    TextLayout::Layout textLayout((int)((double)(reinterpret_cast<::TileListBoxCalls *>((field60))->GetFloat(0xfba))), 0, 0, lines, 10);
    reinterpret_cast<::TextLayout::Font *>((((::TextFont *)(reinterpret_cast<::fnv_005bd5c0::FUN_005bd5c0_shell *>((((::TextFonts *)(::FontManager::Instance()))))->FUN_005bd5c0((int)((double)(reinterpret_cast<::TileListBoxCalls *>((field60))->GetFloat(0xfb9))) - 1)))))->FUN_00a12fb0(fieldbc, &textLayout);
    reinterpret_cast<::FUN_00759da0_shell *>((fielde8))->InsertAtPosition(textLayout, (intptr_t)(reinterpret_cast<::FUN_00a00f30_shell *>((field60))->FUN_00a00f30(0xfc4)), (intptr_t)(reinterpret_cast<::FUN_00a00e90_shell *>((field60))->FindTraitValue(0xfa3)), -1);
    fieldbc += FUN_0042f5a0(textLayout.consumed, ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((void *)&(buffer))->FUN_004048e0())));
    if (!*fieldbc)
        fieldbc = 0;
}

namespace fnv_007598d0 {
struct TextTile
{
};
struct QueueText
{
    char pad[0x24];
    const char* unk24;
    ~QueueText();
    const char* FUN_00458b50();
};
struct TextQueue
{
    QueueText* PopFrontScript();
    void ProcessQueue();
};
struct TextSound
{
    int id;
    int state;
    int flags;
    ~TextSound();
};
struct TextAudioManager
{
};
struct QueueMenu
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
    TextTile* previousTile;
    TextTile* positionTile;
    TextTile* activeTile;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    TextTile* modeTile;
    Shell selection;
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
    int mode;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    TextSound unusedSound;
    TextSound advanceSound;
    TextSound promptSound;
};
extern unsigned int DAT_011d93d4;
extern const char DAT_01072118[];
// @fnv 0x007598d0
void TextQueue::ProcessQueue()
{
    bool hasTrait = false;
    while (!reinterpret_cast<::FUN_0076b610_Class *>((void *)this)->FUN_0076b610() && ((unsigned int)(::FUN_00457fe0())) > DAT_011d93d4)
    {
        if (((bool)(reinterpret_cast<::FUN_00759d80_Class *>(((*((::fnv_007598d0::QueueText **)(reinterpret_cast<::FUN_0073ac90_shell *>(this)->FUN_0073ac90())))))->FUN_00759d80())))
        {
            QueueText* removed = PopFrontScript();
            if (!reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))->mode)
            {
                if (removed && *removed->FUN_00458b50() == *DAT_01072118)
                    reinterpret_cast<::FUN_00ad8830_shell *>(&(reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))->promptSound))->FUN_00ad8830(false);
                DAT_011d93d4 = ((unsigned int)(::FUN_00457fe0())) + 500;
            }
            else if (removed && ((::fnv_007598d0::TextTile *)(reinterpret_cast<::FUN_007001f0_Class *>((removed))->FUN_007001f0())) == reinterpret_cast<QueueMenu*>((*reinterpret_cast<intptr_t *>(&::g_pF57EA0TerminalMenu)))->activeTile)
            {
                reinterpret_cast<::Tile *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))->modeTile))->Set(0xfa3, 1);
            }
            delete removed;
        }
        else
        {
            int x;
            {
                TextTile* tile;
                {
                    int y;
                    {
                        unsigned int oldLength = 0;
                        unsigned int newLength = 0;
                        if (!reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))->mode &&
                            *(*((::fnv_007598d0::QueueText **)(reinterpret_cast<::FUN_0073ac90_shell *>(this)->FUN_0073ac90())))->FUN_00458b50() == *DAT_01072118)
                        {
                            oldLength = ::FUN_0044a670(((const char *)((*((::fnv_007598d0::QueueText **)(reinterpret_cast<::FUN_0073ac90_shell *>(this)->FUN_0073ac90())))->unk24)));
                            reinterpret_cast<::TwTypewriter *>(((*((::fnv_007598d0::QueueText **)(reinterpret_cast<::FUN_0073ac90_shell *>(this)->FUN_0073ac90())))))->FUN_006ffea0();
                            newLength = ::FUN_0044a670(((const char *)((*((::fnv_007598d0::QueueText **)(reinterpret_cast<::FUN_0073ac90_shell *>(this)->FUN_0073ac90())))->unk24)));
                            for (unsigned int index = 0; index < newLength - oldLength; index++)
                            {
                                unsigned int offset =
                                    ((uintptr_t)(reinterpret_cast<::MagicCaster_shell *>(((*((::fnv_007598d0::QueueText **)(reinterpret_cast<::FUN_0073ac90_shell *>(this)->FUN_0073ac90())))))->FUN_0044edb0())) * index / (newLength - oldLength);
                                reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::fnv_007598d0::TextSound &)((*(::fnv_007598d0::TextSound *)(reinterpret_cast<::AudioClass_ae5680 *>((((::fnv_007598d0::TextAudioManager *)(::FUN_00ad9060()))))->ResolveAudioHandle((::Handle_ae5680 *)("UIHackingCharSingle"), 0x121, offset)))))->SchedulePlayback({}, {});
                            }
                        }
                        else
                        {
                            reinterpret_cast<::TwTypewriter *>(((*((::fnv_007598d0::QueueText **)(reinterpret_cast<::FUN_0073ac90_shell *>(this)->FUN_0073ac90())))))->FUN_006ffea0();
                            reinterpret_cast<::FUN_00ad8830_shell *>(&(reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))->advanceSound))->FUN_00ad8830(false);
                        }
                        x = 0;
                        y = 0;
                        tile = ((::fnv_007598d0::TextTile *)(reinterpret_cast<::FUN_007001f0_Class *>(((*((::fnv_007598d0::QueueText **)(reinterpret_cast<::FUN_0073ac90_shell *>(this)->FUN_0073ac90())))))->FUN_007001f0()));
                        hasTrait = reinterpret_cast<::FUN_00a00f30_shell *>((tile))->FUN_00a00f30(0xfba) != 0;
                        for (TextTile* parent = tile;
                             parent &&
                             parent != ((::fnv_007598d0::TextTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))->positionTile))->FUN_0045cd60()));
                             parent = ((::fnv_007598d0::TextTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((parent))->FUN_0045cd60())))
                        {
                            x += (int)reinterpret_cast<::TileListBoxCalls *>((parent))->GetFloat(0xfa1);
                            y += (int)reinterpret_cast<::TileListBoxCalls *>((parent))->GetFloat(0xfa2);
                        }
                        reinterpret_cast<::RenderTile *>((tile))->FUN_00a04640(false);
                        if (reinterpret_cast<::ListOwner *>(&(reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))
                                ->selection))->ContainsKey((void *)(reinterpret_cast<Tile*>(tile))))
                        {
                            reinterpret_cast<::Tile *>((tile))->SetSpeechChallengeFailure(false);
                            reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))
                                ->positionTile))->FUN_00a012d0(
                                    0xfa1,
                                    x + reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(reinterpret_cast<int>(((::FUN_00a00940("_text_width", -1))))),
                                    true);
                            reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))
                                ->positionTile))->FUN_00a012d0(
                                    0xfa2, y + reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(reinterpret_cast<int>(((::FUN_00a00940("_text_y", -1))))),
                                    true);
                        }
                        else if (!hasTrait)
                        {
                            reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))
                                ->positionTile))->FUN_00a012d0(0xfa1, x + reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(0xfb1), true);
                            reinterpret_cast<::Tile *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))->positionTile))->Set(0xfa2, y);
                        }
                        break;
                    }
                }
            }
        }
    }
    if (reinterpret_cast<::FUN_0076b610_Class *>((void *)this)->FUN_0076b610() || hasTrait)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))
            ->positionTile))->FUN_00a012d0(
                0xfa1,
                reinterpret_cast<::TileListBoxCalls *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))->previousTile))->GetFloat(0xfa1) +
                    (reinterpret_cast<::sa040a0::Owner *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))->previousTile))->IsAllChildrenFlag0()
                         ? reinterpret_cast<::TileListBoxCalls *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))->previousTile))->GetFloat(0xfb1)
                         : 0.0f),
                true);
        reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))
            ->positionTile))->FUN_00a012d0(
                0xfa2, reinterpret_cast<::TileListBoxCalls *>((reinterpret_cast<QueueMenu*>((*reinterpret_cast<int *>(&::g_pF57EA0TerminalMenu)))->previousTile))->GetFloat(0xfa2), true);
    }
}
}  // namespace fnv_007598d0


struct LBTile;

struct LBTileValue
{
};

struct LBTileMenu
{
};

struct LBTile
{
};

struct LBItem
{
    LBTile* pTile;
    int iObject;
    int iUnk08;
    LBItem(LBTile* apTile, const int& arObject);
};

struct LBItemList
{
    LBItem* pFirst;
    void* pNext;
};

struct LBListBox
{
    virtual void v00();
    LBItemList kList;
    LBTile* pParentTile;
    LBTile* pSelected;
    LBTile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;

    LBTile* AddItem(intptr_t aiObject, const char* apText, int(__cdecl* apSort)(LBItem*, LBItem*),
                    const char* apTemplateName);
};
// Resets the display and list box, optionally adds the current challenge to the recent list, and rebuilds the challenge lines and tiles.
// @fnv 0x007586e0
void CHMenu::FUN_007586e0(bool abAddRecent)
{
    if (!pChallenge)
        return;

    CHString kText;
    reinterpret_cast<::TileProcessor *>((pDisplay))->ProcessAllTiles();
    kListBox.Clear();
    if (abAddRecent)
        kRecent.AddHead(pChallenge);
    (*reinterpret_cast<unsigned int *>(&::DAT_0119f278)) = (*((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::CHUIntSetting *>(&::g_011d3de4)))))) > 0) ? 1000 / *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::CHUIntSetting *>(&::g_011d3de4)))))) : 1000;

    const char* pDescription = pChallenge->kDescription.Get(pChallenge, 0x43534544);
    CHValue* pTextValue = ((::CHValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((pTile44))->FUN_00a00f30(0xfc4)));
    if (pDescription && *pDescription && (!reinterpret_cast<::sa040a0::Owner *>((pTile44))->IsAllChildrenFlag0() || ::FUN_00408b20(pDescription, ((const char *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pTextValue))->FUN_0084e3a0())))))
    {
        reinterpret_cast<::Tile *>((pTile64))->Set(0xfa3, 0);
        reinterpret_cast<::FUN_00759da0_shell *>((pDisplay))->InsertAtPosition(pDescription, (intptr_t)(pTextValue), (intptr_t)(((::CHValue *)(reinterpret_cast<::FUN_00a00e90_shell *>((pTile44))->FindTraitValue(0xfa3)))), -1);
    }

    for (CHListNode* pIter = ((::CHListNode *)(reinterpret_cast<::FUN_00461150_shell *>((pChallenge))->FUN_00461150())); pIter && *((::CHChallenge **)(&reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item)); pIter = ((::CHListNode *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070())))
    {
        if (reinterpret_cast<::PerkEntryConditionSet *>(&((*((::CHChallenge **)(&reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item)))->kCondition))->ContainsTrait((::TESObjectREFR *)(pSubject), (::TESObjectREFR *)(0)))
        {
            CHTile* pItemTile = ((::CHTile *)(reinterpret_cast<::LBListBox *>(&(kListBox))->AddItem((intptr_t)(*((::CHChallenge **)(&reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item))), (const char *)(0), (int (*)(LBItem *, LBItem *))(0), (const char *)(0))));
            reinterpret_cast<::Tile *>((pItemTile))->Set(::FUN_00a00940("_enabled", -1), 0);
            reinterpret_cast<::Tile *>((pItemTile))->Set(0xfd6, reinterpret_cast<::FUN_00758a60_shell *>(((*((::CHChallenge **)(&reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item)))))->FUN_00758a60() ? 2 : 1);
            ::FUN_00406f60((::FUN_00406f90_this *)(::CHString *)(&kText), "%s%s", "> ", ((const char *)(::FUN_00559450((int *)((*((::CHChallenge **)(&reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item))))))));
            reinterpret_cast<::FUN_00759da0_shell *>((pDisplay))->InsertAtPosition(((const char *)(::FUN_00559450((int *)&(kText)))), (intptr_t)(((::CHValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((pItemTile))->FUN_00a00f30(0x1004)))), (intptr_t)(((::CHValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((pItemTile))->FUN_00a00f30(0xfa3)))), -1);
        }
        reinterpret_cast<::FUN_007583b0_shell *>(((*((::CHChallenge **)(&reinterpret_cast<::SimpleListNodeView*>(pIter)->m_item)))))->SetFlag4(false);
    }

    if (((::CHListNode *)(reinterpret_cast<::Callees *>(&(kRecent))->FUN_00726070())))
    {
        CHTile* pEmptyTile = ((::CHTile *)(reinterpret_cast<::LBListBox *>(&(kListBox))->AddItem((int)(0), (const char *)(0), (int (*)(LBItem *, LBItem *))(0), (const char *)(0))));
        reinterpret_cast<::Tile *>((pEmptyTile))->Set(::FUN_00a00940("_enabled", -1), 0);
        ::FUN_00406f60((::FUN_00406f90_this *)(::CHString *)(&kText), "%s%s", "> ", (*reinterpret_cast<::CHSetting *>(&::g_011d2cb8)).GetString());
        reinterpret_cast<::FUN_00759da0_shell *>((pDisplay))->InsertAtPosition(((const char *)(::FUN_00559450((int *)&(kText)))), (intptr_t)(((::CHValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((pEmptyTile))->FUN_00a00f30(0x1004)))), (intptr_t)(((::CHValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((pEmptyTile))->FUN_00a00f30(0xfa3)))), -1);
    }
    bRefreshed = true;
}

// @fnv 0x0075a110
LBTile* LBListBox::AddItem(intptr_t aiObject, const char* apText, int(__cdecl* apSort)(LBItem*, LBItem*),
                           const char* apTemplateName)
{
    if (pParentTile && (pTemplateName || apTemplateName))
    {
        LBTile* pTile = ((::LBTile *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::LBTileMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((pParentTile))->FUN_00a03c90()))))->FUN_00a1ddb0((::Tile *)(pParentTile),
                                                                    (char *)(apTemplateName ? apTemplateName : pTemplateName), (::Tile *)(0))));
        if (!reinterpret_cast<::FUN_00a00f30_shell *>((pTile))->FUN_00a00f30(0xfaa))
            reinterpret_cast<::Tile *>((pTile))->Set(0xfaa, -1);
        if (apText)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((pTile))->FUN_00a01350(0xfc4, (char *)(apText), true);
        if (apSort)
        {
            reinterpret_cast<::FUN_00470440 *>(&(kList))->FUN_007a7eb0((::BGSPerkEntry *)(::LBItem *)(new LBItem(pTile, aiObject)), (int (*)(BGSPerkEntry *, BGSPerkEntry *))(apSort));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
                reinterpret_cast<::FUN_0075aa50_cls *>(this)->ResetAndProcessNodes();
        }
        else
        {
            reinterpret_cast<::Callees *>(&(kList))->FUN_00905820((void *)&(const ::LBItem *const &)(new LBItem(pTile, aiObject)));
            if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(0))
            {
                reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(pTile));
                reinterpret_cast<::FUN_0075aa50_cls *>(this)->UpdateScrollItems();
            }
            reinterpret_cast<::Tile *>((pTile))->Set(0xfac, usItemCount++);
        }
        if (::GetRaceCount((char *)this) == 1 && reinterpret_cast<::TileListBoxCalls *>((pParentTile))->GetFloat(::FUN_00a00940("_number_of_visible_items", -1)) > 0.0)
        {
            LBTileValue* pAction = ((::LBTileValue *)(reinterpret_cast<::FUN_00a00e90_shell *>((pParentTile))->FindTraitValue(0xfb0)));
            reinterpret_cast<::fnv_00a09200::Value_00a09200 *>((pAction))->RemoveFromReactions();
            reinterpret_cast<::AGOwner *>((pAction))->FUN_00a09130(0x7d0, (::Tile *)(pTile), 0xfb0);
            reinterpret_cast<::P03Value *>((pAction))->AppendFloatAction(0x7d3, reinterpret_cast<::TileListBoxCalls *>((pParentTile))->GetFloat(::FUN_00a00940("_number_of_visible_items", -1)));
            reinterpret_cast<::fnv_00a09410::EvalValue *>((pAction))->FUN_00a09410(0);
        }
        return pTile;
    }
    else
        return 0;
}

struct OwnedObject
{
    virtual ~OwnedObject();
};
struct OwnedText
{
    ~OwnedText();
};
struct AnimationEntry
{
    OwnedObject* object;
    OwnedText* text;
};
struct AnimationNode
{
    ~AnimationNode();
};
struct AnimationTile
{
};
struct AnimationList
{
    int unk00;
    AnimationEntry* entry;
    AnimationNode* node;
    AnimationTile* tile;
    Tile* currentTile;
    int unk14;
    int unk18;
    unsigned short count;
    unsigned short unk1e;
    float elapsed;
    void ClearEntries();
};

struct MyTile : FUN_00a01230_shell
{
};

struct MyInner
{
    MyTile* m_00;
};

struct MyRef
{
    MyInner* p;
};

struct MyNode
{
    void* m_item;
    MyNode* m_next;
};

struct MyListBox
{
    virtual void* v00();
    virtual void* v04();
    virtual void* v08();
    virtual void* v0c();
    virtual void* v10();
    virtual MyTile* FUN_0075a955(int, int);

    MyNode m_kNode;
    MyTile* m_tile0c;
    MyTile* m_tile10;
    int m_unk14;
    int m_unk18;
    unsigned short m_count1c;

    MyTile* GetScrollTargetTile(int a1);
};

// Resolves a scroll direction into a step, finds the enabled tile at the clamped index in the list, and returns it unless it is the current tile.
// @fnv 0x0075a680
MyTile* MyListBox::GetScrollTargetTile(int aiScrollCode)
{
    MyTile* pFound_ = 0;
    int iTileIndex = 0;

    switch (aiScrollCode)
    {
    case 2:
        iTileIndex = 1;
        break;
    case 1:
        iTileIndex = -1;
        break;
    case 15:
        iTileIndex =
            m_tile0c ? (int)::InventoryStackRecord::RoundToNearestStep(
                           -reinterpret_cast<::TileListBoxCalls *>((m_tile0c))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((m_tile0c))->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                     : 0;
        break;
    case 16:
        iTileIndex =
            m_tile0c ? (int)::InventoryStackRecord::RoundToNearestStep(
                           reinterpret_cast<::TileListBoxCalls *>((m_tile0c))->GetFloat(0xfb0) / reinterpret_cast<::TileListBoxCalls *>((m_tile0c))->GetFloat(FUN_00a01860("_scroll_delta")), 1.0f)
                     : 0;
        break;
    default:
        break;
    }

    if (reinterpret_cast<::FUN_0075ab20_shell *>(this)->IsTileTraitEnabled() && iTileIndex && m_count1c)
    {
        int maxIdxTmp = m_count1c - 1;
        int curIdx;
        if (m_tile10)
        {
            int selIdx = (int)reinterpret_cast<::TileListBoxCalls *>((m_tile10))->GetFloat(0xfac);
            curIdx = selIdx + iTileIndex;
            if (curIdx < 0)
                curIdx = 0;
            else if (curIdx > maxIdxTmp)
                curIdx = maxIdxTmp;
        }
        else
        {
            if (iTileIndex > 0)
                curIdx = 0;
            else
                curIdx = maxIdxTmp;
        }

        while (1)
        {
            for (MyNode* pNodeA = this ? &m_kNode : 0; !pFound_ && pNodeA && ((::MyRef *)(reinterpret_cast<::SimpleListNodeView*>(pNodeA)->m_item))->p;
                 pNodeA = ((::MyNode *)(reinterpret_cast<::Callees *>((pNodeA))->FUN_00726070())))
            {
                if (reinterpret_cast<::TileListBoxCalls *>((((::MyRef *)(reinterpret_cast<::SimpleListNodeView*>(pNodeA)->m_item))->p->m_00))->GetFloat(0xfac) == (float)curIdx)
                {
                    pFound_ = ((::MyRef *)(reinterpret_cast<::SimpleListNodeView*>(pNodeA)->m_item))->p->m_00;
                }
            }

            if (pFound_ && !pFound_->IsTraitNonZero((int)((::FUN_00a00940("_enabled", -1)))))
            {
                pFound_ = 0;
                if (iTileIndex > 0 && ++curIdx > maxIdxTmp)
                {
                    curIdx = maxIdxTmp - 1;
                    while ((!pFound_ || !pFound_->IsTraitNonZero((int)((::FUN_00a00940("_enabled", -1))))) && curIdx >= 0)
                    {
                        pFound_ = FUN_0075a955(curIdx--, 0);
                    }
                    break;
                }
                else if (iTileIndex < 0 && --curIdx < 0)
                {
                    curIdx = 1;
                    while ((!pFound_ || !pFound_->IsTraitNonZero((int)((::FUN_00a00940("_enabled", -1))))) &&
                           curIdx <= maxIdxTmp)
                    {
                        pFound_ = FUN_0075a955(curIdx++, 0);
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

    return (pFound_ != m_tile10) ? pFound_ : 0;
}

struct ScrollListHelper
{
};

struct ScrollTileHelper
{
};

struct FUN_0075b020_cls
{
};

struct ScrollData
{
    int unk00;
    int unk04;
    int unk08;
    TraitValueCollection* pTile0c;
    int unk10;
    ScrollListHelper* pTile14;
};


// Computes the number of scroll items from the tile value and m_20, sets _scroll_delta on the tile and _number_of_items on the list.
// @fnv 0x0075aef0
void FUN_0075aa50_cls::UpdateScrollItems()
{
    float fTimeOffset;
    int iNumberOfItems;
    if (((ScrollData*)this)->pTile0c != 0)
    {
        fTimeOffset = reinterpret_cast<::TileListBoxCalls *>((((ScrollData*)this)->pTile0c))->GetFloat(0xfb0);
        iNumberOfItems = 1;

        if (m_20 > ::_DAT_01012060 && fTimeOffset > ::_DAT_01012060)
        {
            if (m_20 > fTimeOffset)
            {
                iNumberOfItems =
                    FUN_00647b70((int)FUN_004e4430(
                                     ((float)((unsigned int)(reinterpret_cast<::fnv_0075b020::FUN_0075b020_cls *>((((FUN_0075b020_cls*)this)))->FUN_0075b020())) * (m_20 - fTimeOffset)) / m_20) +
                                     1,
                                 2);
            }

            if (iNumberOfItems > 1)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((((ScrollTileHelper*)((ScrollData*)this)->pTile0c)))->FUN_00a012d0(FUN_00a01860("_scroll_delta"), (m_20 - fTimeOffset) / (iNumberOfItems - 1), true);
            }
        }

        if (((ScrollData*)this)->pTile14 != 0)
        {
            reinterpret_cast<::Tile *>((((ScrollData*)this)->pTile14))->Set(FUN_00a01860("_number_of_items"), iNumberOfItems);
        }
    }
}

namespace fnv_00757b70 {
struct Terminal;
struct Ref
{
};
struct Terminal
{
};
struct Colors
{
    bool Get(int, int*);
};
struct OpenTile;
struct ListUI
{
    void Initialize(OpenTile*, const char*);
};
struct SoundUI
{
};
struct OpenMenu
{
    virtual ~OpenMenu();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual int ID();
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
    OpenTile* root;
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
    ListUI list;
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
    Terminal* terminal;
    Ref* ref;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    unsigned char unkc0;
    unsigned char unkc1;
    unsigned char unkc2;
    unsigned char unkc3;
    SoundUI sound;
    void Populate();
    void Alternate();
    void Show(int);
};
struct OpenTile
{
    float Value(int);
};
struct KeyState
{
};
struct UI
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    unsigned char unkc0;
    unsigned char unkc1;
    unsigned char unkc2;
    unsigned char unkc3;
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
    KeyState keys;
};
// @fnv 0x00757b70
OpenTile* CreateComputerMenu(Ref* reference)
{
    OpenMenu* oldMenu = ((::fnv_00757b70::OpenMenu *)(::FUN_00a09030(::FUN_00757e20())));
    if (oldMenu)
    {
        delete oldMenu;
    }
    reinterpret_cast<::SystemColorManager *>((((::fnv_00757b70::Colors *)(::FUN_00718b60()))))->GetColor(3, (*(::NiColor *)(&::DAT_011d934c)));
    Terminal* terminal = ((::fnv_00757b70::Terminal *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()));
    if (reinterpret_cast<::FUN_00757e80_shell *>((terminal))->IsFlagBitSet())
        reinterpret_cast<::FUN_007190e0_cls *>((((::fnv_00757b70::Colors *)(::FUN_00718b60()))))->ApplyToChild(3, (intptr_t)&(const ::ImageSpaceEffectParam &)(::ImageSpaceEffectParam(1.0f, 1.0f, 1.0f, 0.0f)));
    float defaultValue = ::Tile::GetInterfaceScale();
    OpenTile* aTile = ((::fnv_00757b70::OpenTile *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::fnv_00757b70::OpenTile *)(reinterpret_cast<::InterfaceManager *>((((::fnv_00757b70::UI *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00586150()))))->FUN_00a01b00((void *)("Data\\Menus\\computers_menu.xml"))));
    OpenMenu* menu = ((::fnv_00757b70::OpenMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((aTile))->FUN_00a03c90()));
    if (menu && menu->ID() == ::FUN_00757e20())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((menu))->FUN_00a1dc70((::TileMenu *)(aTile), false);
        (*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu)) = menu;
        int iMissingIndex;
        if (!reinterpret_cast<::FUN_00757e30_Class *>(((*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu))))->HasAllTiles(&iMissingIndex))
        {
            ::FUN_005b5e40();
            return 0;
        }
        else if (!reference)
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (reinterpret_cast<::TileListBoxCalls *>((aTile))->GetFloat(0xfa7) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((aTile))->GetFloat(0xfa7) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((aTile))->FUN_00a012d0(0xfad, defaultValue, true);
        (*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu))->unkc0 = ((unsigned char)(reinterpret_cast<::TutorialMessageGate718 *>(&(((::fnv_00757b70::UI *)(::fnv_004b7210::FUN_004b7210()))->keys))->FUN_00718630(0x18, ::FUN_00757e20(), 0x200)));
        (*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu))->ref = reference;
        (*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu))->terminal = terminal;
        (*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu))->list.Initialize((*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu))->root, "computers_file_template");
        reinterpret_cast<::FUN_00ad8830_shell *>(&((*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu))->sound))->FUN_00ad8830(false);
        if (reinterpret_cast<::FUN_00501ae0_shell *>(((*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu))->terminal))->FUN_00501ae0((::TESObjectREFR *)((*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu))->ref)))
            (*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu))->Populate();
        else
            (*reinterpret_cast<::fnv_00757b70::OpenMenu * *>(&::g_pF57EA0TerminalMenu))->Alternate();
        menu->Show(0);
        return aTile;
    }
    else
    {
        if (menu && menu->unk04)
        {
            delete menu;
        }
    }
    return 0;
}
}  // namespace fnv_00757b70

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
    HighlightTile* root;
    HighlightTile* selected;
    void UpdateHighlight();
};
// @fnv 0x0075a610
bool SetTileHelper::FUN_0075a610(Tile* apTile)
{
    if (reinterpret_cast<::FUN_0075ab20_shell *>((((Shell*)this)))->IsTileTraitEnabled() &&
        (apTile == 0 || (reinterpret_cast<::ListOwner *>((((Shell*)this)))->ContainsKey((void *)(apTile)) &&
                         reinterpret_cast<::FUN_00a01230_shell *>((((ParamShell*)apTile)))->IsTraitNonZero((int)((::FUN_00a00940("_enabled", -1)))))))
    {
        m_pTile10 = apTile;
        reinterpret_cast<::HighlightList *>((((Shell*)this)))->UpdateHighlight();
        return true;
    }
    else
    {
        return false;
    }
}
// @fnv 0x0075aa50
void FUN_0075aa50_cls::ResetAndProcessNodes()
{
    m_1c = 0;
    m_20 = 0.0f;
    for (b9165Node* cur = this != 0 ? &m_04 : 0; cur != 0 && ((::b9165Ref *)(reinterpret_cast<::SimpleListNodeView*>(cur)->m_item))->p != 0; cur = ((::b9165Node *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070())))
    {
        if (((::b9165Ref *)(reinterpret_cast<::SimpleListNodeView*>(cur)->m_item))->p->m_08 == 0)
        {
            reinterpret_cast<::Tile *>((((::b9165Ref *)(reinterpret_cast<::SimpleListNodeView*>(cur)->m_item))->p->m_00))->Set(0xfac, m_1c++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(((::b9165Ref *)(reinterpret_cast<::SimpleListNodeView*>(cur)->m_item))->p->m_00));
        }
    }
    UpdateScrollItems();
    reinterpret_cast<::HighlightList *>(this)->UpdateHighlight();
}
// Clears the object's entry list, then unregisters the object via A060Unregister.
// @fnv 0x0075a060
FUN_0075a060::~FUN_0075a060()
{
    reinterpret_cast<::AnimationList *>(this)->ClearEntries();
    ::fnv_007211c0::FUN_007211c0((int *)(::FUN_0075a060 *)(this));
}
// Deletes the node chain and entry, optionally their object/text, resets count and elapsed, clears the tile filter, and resets currentTile.
// @fnv 0x0075a3b0
void AnimationList::ClearEntries()
{
    while (node && *((::AnimationEntry **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))
    {
        AnimationNode* next = ((::AnimationNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        if (!::fnv_007a2070::s_bAllowDetach)
            delete (*((::AnimationEntry **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))->object;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete (*((::AnimationEntry **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))->text;
        delete *((::AnimationEntry **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item));
        reinterpret_cast<::CombatProcedure *>((node))->Initialize((::CombatController *)(0));
        delete node;
        node = next;
    }
    if (entry)
    {
        if (!::fnv_007a2070::s_bAllowDetach)
            delete entry->object;
        if (reinterpret_cast<::FUN_007242c0_shell *>(this)->FUN_007242c0(1))
            delete entry->text;
        delete entry;
    }
    entry = 0;
    count = 0;
    elapsed = 0.0f;
    if (tile)
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(FUN_00a01860("_num_filtered"), 0.0f, true);
    reinterpret_cast<::FUN_0075aa50_cls *>(this)->UpdateScrollItems();
    currentTile = 0;
    reinterpret_cast<::HighlightList *>(this)->UpdateHighlight();
}
// @fnv 0x0075abd0
void HighlightList::UpdateHighlight()
{
    static int highlightY = ::FUN_00a00940("_highlight_y", -1);
    static int selectedHeight = ::FUN_00a00940("_selected_height", -1);
    if (root)
    {
        if (selected)
        {
            HighlightValue* heightValue = ((::HighlightValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((root))->FUN_00a00f30(highlightY)));
            HighlightValue* yValue = ((::HighlightValue *)(reinterpret_cast<::FUN_00a00f30_shell *>((root))->FUN_00a00f30(selectedHeight)));
            reinterpret_cast<::AGOwner *>((heightValue))->FUN_00a09130(2000, (::Tile *)(selected), 4002);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((heightValue))->FUN_00a09410(0);
            reinterpret_cast<::AGOwner *>((yValue))->FUN_00a09130(2000, (::Tile *)(selected), 4016);
            reinterpret_cast<::fnv_00a09410::EvalValue *>((yValue))->FUN_00a09410(0);
            if (reinterpret_cast<::Tile *>((selected))->GetSpeechChallengeFailure())
            {
                HighlightTile* box = ((::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(root), "lb_highlight_box")));
                if (box)
                {
                    HighlightTile* edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("top"))));
                    if (edge)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(true);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((box))->FUN_0071aa60(true);
                    reinterpret_cast<::FUN_00a07530_shell *>((box))->FUN_00a07530(8);
                }
            }
            else
            {
                HighlightTile* box = ((::HighlightTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(root), "lb_highlight_box")));
                if (box)
                {
                    HighlightTile* edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("top"))));
                    if (edge)
                    {
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("bottom"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("left"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                        edge = ((::HighlightTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((box))->FUN_00a03da0((char *)("right"))));
                        reinterpret_cast<::FUN_0071aa60_class *>((edge))->FUN_0071aa60(false);
                        reinterpret_cast<::FUN_00a07530_shell *>((edge))->FUN_00a07530(8);
                    }
                    reinterpret_cast<::FUN_0071aa60_class *>((box))->FUN_0071aa60(false);
                    reinterpret_cast<::FUN_00a07530_shell *>((box))->FUN_00a07530(8);
                }
            }
        }
        else
        {
            reinterpret_cast<::Tile *>((root))->Set(highlightY, -1);
            reinterpret_cast<::Tile *>((root))->Set(selectedHeight, 0);
        }
    }
}

struct MyMenuTile
{
};

class GlobalObject_0040c150
{
  public:
    const char* FUN_00403df0();
};

extern GlobalObject_0040c150 g_011d3d78;
extern GlobalObject_0040c150 g_011d4978;


struct MyDisplay
{
};

struct ChallengeMenu
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
    MyMenuTile* pTile28;
    int unk2C;
    int unk30;
    MyMenuTile* pTile34;
    MyMenuTile* pTile38;
    int unk3C;
    int unk40;
    int unk44;
    MyMenuTile* pTile48;
    MyMenuTile* pTile4C;
    MyMenuTile* pTile50;
    MyMenuTile* pTile54;
    MyMenuTile* pTile58;
    MyMenuTile* pTile5C;
    int unk60;
    int unk64;
    CHListBox kListBox;
    CHSimpleList kRecent;
    short unkA0;
    short unkA2;
    int unkA4;
    Host* pChallenge;
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
    MyDisplay* pDisplay;

    void RefreshDisplay();
};

// @fnv 0x00758d30
void ChallengeMenu::RefreshDisplay()
{
    reinterpret_cast<::Tile *>((this->pTile5C))->Set(0xFAF, 0);
    reinterpret_cast<::TileProcessor *>((this->pDisplay))->ProcessAllTiles();
    reinterpret_cast<::Tile *>((this->pTile4C))->Set(0xFA3, 0);
    reinterpret_cast<::Tile *>((this->pTile50))->Set(0xFA3, 0);
    reinterpret_cast<::Tile *>((this->pTile54))->Set(0xFA3, 0);
    reinterpret_cast<::Tile *>((this->pTile58))->Set(0xFA3, 0);
    reinterpret_cast<::CHMenu *>((this))->FUN_007586e0(1);

    reinterpret_cast<::FUN_00759da0_shell *>((this->pDisplay))->InsertAtPosition(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&(g_011d3d78))->IsDLCAvailable())), (intptr_t)(reinterpret_cast<::FUN_00a00f30_shell *>((this->pTile34))->FUN_00a00f30(0xFC4)),
                                     (intptr_t)(reinterpret_cast<::FUN_00a00e90_shell *>((this->pTile34))->FindTraitValue(0xFA3)), 0);
    reinterpret_cast<::FUN_00a012d0_t *>((this->pTile34))->FUN_00a012d0(
        0xFA1,
        (reinterpret_cast<::TileListBoxCalls *>((((::MyMenuTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((this->pTile34))->FUN_0045cd60()))))->GetFloat(0xFB1) - ::FUN_0044a670(g_011d3d78.FUN_00403df0()) * 17) / 2.0, 1);

    reinterpret_cast<::FUN_00759da0_shell *>((this->pDisplay))->InsertAtPosition(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&(g_011d4978))->IsDLCAvailable())), (intptr_t)(reinterpret_cast<::FUN_00a00f30_shell *>((this->pTile38))->FUN_00a00f30(0xFC4)),
                                     (intptr_t)(reinterpret_cast<::FUN_00a00e90_shell *>((this->pTile38))->FindTraitValue(0xFA3)), 1);
    reinterpret_cast<::FUN_00a012d0_t *>((this->pTile38))->FUN_00a012d0(
        0xFA1,
        (reinterpret_cast<::TileListBoxCalls *>((((::MyMenuTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((this->pTile38))->FUN_0045cd60()))))->GetFloat(0xFB1) - ::FUN_0044a670(g_011d4978.FUN_00403df0()) * 17) / 2.0, 1);

    reinterpret_cast<::FUN_00759da0_shell *>((this->pDisplay))->InsertAtPosition(this->pChallenge->FUN_00758fe0(), (intptr_t)(reinterpret_cast<::FUN_00a00f30_shell *>((this->pTile28))->FUN_00a00f30(0xFC4)),
                                     (intptr_t)(reinterpret_cast<::FUN_00a00e90_shell *>((this->pTile28))->FindTraitValue(0xFA3)), 2);
    reinterpret_cast<::FUN_00a012d0_t *>((this->pTile28))->FUN_00a012d0(
        0xFA1,
        (reinterpret_cast<::TileListBoxCalls *>((((::MyMenuTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((this->pTile28))->FUN_0045cd60()))))->GetFloat(0xFB1) - ::FUN_0044a670(this->pChallenge->FUN_00758fe0()) * 17) /
            2.0,
        1);

    reinterpret_cast<::FUN_00759da0_shell *>((this->pDisplay))->InsertAtPosition("> ", (intptr_t)(reinterpret_cast<::FUN_00a00f30_shell *>((this->pTile48))->FUN_00a00f30(0xFC4)), (intptr_t)(reinterpret_cast<::FUN_00a00e90_shell *>((this->pTile48))->FindTraitValue(0xFA3)),
                                     -1);
    this->unkB0 = 2;
}

#include <string.h>
class Menu
{
  public:
    Menu();
    virtual ~Menu();
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
struct ComputerEntryList
{
    ComputerEntryList();
    ~ComputerEntryList();
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
};
struct SL2
{
    SL2();
    ~SL2();
    void* head;
    void* next;
};
struct StrMem
{
    StrMem();
    ~StrMem();
    char* text;
    unsigned short length;
    unsigned short capacity;
};
struct BSSoundHandleEx
{
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    BSSoundHandleEx& operator=(const BSSoundHandleEx&);
    unsigned int id;
    unsigned int state;
    unsigned int sound;
};
struct ConstructorAudio
{
};
void PlayNoteSound();
void SetTextSource();
void UpdateNoteDisplay();

struct FUN_007577f0 : Menu
{
    Tile* tile28;
    Tile* tile2c;
    Tile* tile30;
    Tile* tile34;
    Tile* tile38;
    Tile* tile3c;
    Tile* tile40;
    Tile* tile44;
    Tile* tile48;
    Tile* tile4c;
    Tile* tile50;
    Tile* tile54;
    Tile* tile58;
    Tile* tile5c;
    Tile* tile60;
    Tile* tile64;
    ComputerEntryList entries;
    SL2 notes;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    StrMem text;
    int unkbc;
    bool unkc0;
    BSSoundHandleEx sounds[3];
    S_7597c0* manager;
    void (*callbackec)();
    void (*callbackf0)();
    void (*callbackf4)();
    int unkf8;
    FUN_007577f0();
    virtual ~FUN_007577f0();
};

// Initializes the hacking menu by zeroing tiles, setting up audio handles for fan hum and character sounds, and assigning callback functions.
// @fnv 0x007577f0
FUN_007577f0::FUN_007577f0()
{
    memset(&tile28, 0, 0x40);
    manager = GetStorageSingleton();
    callbackec = PlayNoteSound;
    callbackf0 = SetTextSource;
    callbackf4 = UpdateNoteDisplay;
    unkf8 = 0;
    ConstructorAudio* audio = ((::ConstructorAudio *)(::FUN_00ad9060()));
    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(sounds[0]))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)((*(::BSSoundHandleEx *)(reinterpret_cast<::AudioClass_ae5680 *>((audio))->ResolveAudioHandle((::Handle_ae5680 *)("UIHackingFanHumLP"), 0x31, {}))))));
    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(sounds[1]))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)((*(::BSSoundHandleEx *)(reinterpret_cast<::AudioClass_ae5680 *>((audio))->ResolveAudioHandle((::Handle_ae5680 *)("UIHackingCharScroll"), 0x21, {}))))));
    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::BSSoundHandleEx &)(sounds[2]))->operator=((const ::SoundPlaybackHandle &)((const ::BSSoundHandleEx &)((*(::BSSoundHandleEx *)(reinterpret_cast<::AudioClass_ae5680 *>((audio))->ResolveAudioHandle((::Handle_ae5680 *)("UIHackingCharEnter"), 0x21, {}))))));
    unka0 = 0;
    unka4 = 0;
    unka8 = 0;
    unkac = 0;
    unkb0 = 0;
    unkbc = 0;
    unkc0 = false;
}

bool DispatchMessageToSink(const char *, int, const char *, const char *, float, unsigned char);

namespace fnv_00757f70 {
struct TileF;
struct Value
{
    char pad[0xc];
    const char* unk0C;
};
struct TileF
{
};
struct BStr
{
    void* m_data;
    int m_len;
    BStr();
    ~BStr();
};
struct NameObj
{
};
struct Note
{
    void* m_n0[18];
    NameObj m_name;
};
struct Obj
{
    void* m_00;
    void* m_04;
    BStr m_str;
    void* m_rest[23];
    Note* m_note;
    void* m_70;
};
struct ListObj
{
    void* m_items[14];
};
struct SoundObj
{
    void* m_s0;
    void* m_s4;
    void* m_s8;
};
struct Mgr
{
};
struct Player
{
};
struct SettingObj
{
    const char* FUN_00403df0();
};
struct TickObj
{
};
extern unsigned char DAT_011d93c0;
struct HostF
{
    void* m_pFirstNode[10];
    TileF* m_pTiles[16];
    ListObj m_kNode;
    int m_a0;
    int m_a4;
    void* m_a8;
    void* m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    unsigned char m_c0;
    unsigned char m_c1;
    unsigned char m_c2[26];
    SoundObj m_sound;
    Mgr* m_pManager;
    typedef void (HostF::*Handler)(Note*);
    Handler m_handlers[16];
    void FUN_00757f70(int a1, TileF* a2);
};
// Processes a tile index and optional tile pointer, updates tile and note display state, and may dispatch a note message to the player.
// @fnv 0x00757f70
void HostF::FUN_00757f70(int aiTileIndex, TileF* apTile)
{
    if (!apTile && aiTileIndex >= 0 && aiTileIndex < 16)
        apTile = m_pTiles[aiTileIndex];
    int id = aiTileIndex;
    bool flag4 = false;
    Value* val;
    Obj* obj;
    if (id == 2)
    {
        reinterpret_cast<::TileProcessor *>((m_pManager))->ProcessAllTiles();
        if (m_bc != 0)
        {
            reinterpret_cast<::TextMenu *>(this)->SetTextSource((::TextSource *)(0));
            flag4 = true;
        }
        else
        {
            reinterpret_cast<::Tile *>((m_pTiles[2]))->Set(0xfa3, 0);
            reinterpret_cast<::Tile *>((m_pTiles[1]))->Set(0xfa3, 1);
            if (DAT_011d93c0)
            {
                reinterpret_cast<::CHMenu *>(this)->FUN_007586e0(0);
            }
            else
            {
                if (!reinterpret_cast<::sa040a0::Owner *>((m_pTiles[7]))->IsAllChildrenFlag0())
                {
                    reinterpret_cast<::Tile *>((m_pTiles[15]))->Set(0xfa3, 0);
                    val = ((::fnv_00757f70::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((m_pTiles[7]))->FUN_00a00f30(0xfc4)));
                    reinterpret_cast<::FUN_00759da0_shell *>((m_pManager))->InsertAtPosition(((const char *)(val->unk0C)), (intptr_t)(val), (intptr_t)(reinterpret_cast<::FUN_00a00e90_shell *>((m_pTiles[7]))->FindTraitValue(0xfa3)), -1);
                }
                reinterpret_cast<::LBList_7314c0 *>(&(m_kNode))->FUN_007314c0((void (*)(LBTile_7314c0 *, void *))(void (*)(fnv_00757f70::TileF *, void *))(&((void (&)(fnv_00757f70::TileF *, void *))::UpdateNoteTile)), 0, 0x7fffffff);
                m_c1 = 1;
            }
        }
        reinterpret_cast<::FUN_00ad8830_shell *>(&(m_sound))->FUN_00ad8830(false);
    }
    else if (id == 13 && m_b0 < 2)
    {
        reinterpret_cast<::ChallengeMenu *>(this)->RefreshDisplay();
    }
    else
    {
        if (reinterpret_cast<::ListOwner *>(&(m_kNode))->ContainsKey((void *)(apTile)))
        {
            reinterpret_cast<::FUN_00ad8830_shell *>(&(m_sound))->FUN_00ad8830(false);
            obj = ((::fnv_00757f70::Obj *)(reinterpret_cast<::LBList *>(&(m_kNode))->FindItemData((::Tile *)(apTile))));
            if (!obj)
            {
                reinterpret_cast<::FUN_00758a80_shell *>(this)->FUN_00758a80();
            }
            else if (obj->m_70)
            {
                reinterpret_cast<::FUN_007583b0_shell *>((obj))->SetFlag4(true);
                reinterpret_cast<::FUN_00501830_shell *>((obj))->FUN_00501830((::Script *)(m_ac));
                m_a8 = obj->m_70;
                reinterpret_cast<::CHMenu *>(this)->FUN_007586e0(1);
            }
            else
            {
                reinterpret_cast<::FUN_007583b0_shell *>((obj))->SetFlag4(true);
                reinterpret_cast<::FUN_00501830_shell *>((obj))->FUN_00501830((::Script *)(m_ac));
                if (((const char *)(::FUN_00559450((int *)&(obj->m_str)))))
                {
                    reinterpret_cast<::FUN_00759da0_shell *>((m_pManager))->InsertAtPosition(((const char *)(::FUN_00559450((int *)&(obj->m_str)))), (intptr_t)(((::fnv_00757f70::Value *)(reinterpret_cast<::FUN_00a00f30_shell *>((m_pTiles[5]))->FUN_00a00f30(0xfc4)))),
                                                 (intptr_t)(reinterpret_cast<::FUN_00a00e90_shell *>((m_pTiles[5]))->FindTraitValue(0xfa3)), 0);
                    m_a0 = ((unsigned int)(::FUN_00457fe0())) + *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00757f70::TickObj *>(&::g_011d3e50)))))) * 1000;
                }
                if (obj->m_note)
                {
                    if (reinterpret_cast<::FUN_00758350_shell *>((obj))->FUN_00758350() && !reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::fnv_00757f70::Player * *>(&::_g_thePlayer))))->HasNote((::BGSNote *)(obj->m_note)))
                    {
                        reinterpret_cast<::PlayerNoteStub *>(((*reinterpret_cast<::fnv_00757f70::Player * *>(&::_g_thePlayer))))->FUN_00966a70((::NoteStub *)(obj->m_note), 0);
                        {
                            BStr str;
                            ::FUN_00406f60((::FUN_00406f90_this *)(::fnv_00757f70::BStr *)(&str), (*reinterpret_cast<::fnv_00757f70::SettingObj *>(&::g_011d3ca0)).FUN_00403df0(), ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(obj->m_note->m_name))->FUN_00408da0())));
                            ::DispatchMessageToSink(((const char *)(::FUN_00559450((int *)&(str)))), 0,
                                                  "Interface\\Icons\\Message Icons\\glow_message_giftbox.dds", 0, 2.0f,
                                                  false);
                        }
                    }
                    if (m_handlers[reinterpret_cast<::FUN_005e8d40_shell *>((obj->m_note))->GetNoteType()])
                        (this->*m_handlers[reinterpret_cast<::FUN_005e8d40_shell *>((obj->m_note))->GetNoteType()])(obj->m_note);
                    DAT_011d93c0 = reinterpret_cast<::FUN_00758390_shell *>((obj))->FUN_00758390();
                    flag4 = true;
                }
                else
                {
                    if (reinterpret_cast<::FUN_00758390_shell *>((obj))->FUN_00758390())
                        reinterpret_cast<::CHMenu *>(this)->FUN_007586e0(0);
                }
            }
        }
    }
    if (!flag4)
        DAT_011d93c0 = 0;
}
}  // namespace fnv_00757f70

namespace fnv_00758ad0 {
struct StrMem
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    StrMem();
    ~StrMem();
};
struct TimingSetting
{
};
struct TextSetting
{
    const char* FUN_00403df0();
};
struct TextTile
{
};
struct TerminalReference
{
};
struct TerminalTextMenu
{
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
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    TextTile* introTile;
    TextTile* promptTile;
    TextTile* headerTile;
    TextTile* passwordTile;
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
    TerminalReference* terminal;
    void* reference;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    FUN_00759da0_shell* animation;
    void BuildAnimation();
};

// Inserts intro, prompt, header, and password tiles into the terminal animation sequence using timing settings and tile trait values.
// @fnv 0x00758ad0
void TerminalTextMenu::BuildAnimation()
{
    unsigned int promptDelay;
    {
        StrMem text;
        unsigned int introDelay = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00758ad0::TimingSetting *>(&::g_011d3de4)))))) > 0 ? 1000 / *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00758ad0::TimingSetting *>(&::g_011d3de4)))))) : 1000;
        promptDelay = *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00758ad0::TimingSetting *>(&::g_011d4e4c)))))) > 0 ? 1000 / *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00758ad0::TimingSetting *>(&::g_011d4e4c)))))) : 1000;
        ::DAT_0119f278 = introDelay;
        animation->InsertAtPosition(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00758ad0::TextSetting *>(&::g_011d3a38))))->IsDLCAvailable())), (intptr_t)reinterpret_cast<::FUN_00a00f30_shell *>((introTile))->FUN_00a00f30(0xfc4),
                                    (intptr_t)reinterpret_cast<::FUN_00a00e90_shell *>((introTile))->FindTraitValue(0xfa3), -1);
        ::DAT_0119f278 = promptDelay;
        ::FUN_00406f60((::FUN_00406f90_this *)(::fnv_00758ad0::StrMem *)(&text), "%s%s", "> ", (*reinterpret_cast<::fnv_00758ad0::TextSetting *>(&::g_011d2ee0)).FUN_00403df0());
        animation->InsertAtPosition(((const char *)(::FUN_00559450((int *)&(text)))), (intptr_t)reinterpret_cast<::FUN_00a00f30_shell *>((promptTile))->FUN_00a00f30(0xfc4),
                                    (intptr_t)reinterpret_cast<::FUN_00a00e90_shell *>((promptTile))->FindTraitValue(0xfa3), -1);
        ::DAT_0119f278 = introDelay;
        animation->InsertAtPosition(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::fnv_00758ad0::TextSetting *>(&::g_011d430c))))->IsDLCAvailable())), (intptr_t)reinterpret_cast<::FUN_00a00f30_shell *>((headerTile))->FUN_00a00f30(0xfc4),
                                    (intptr_t)reinterpret_cast<::FUN_00a00e90_shell *>((headerTile))->FindTraitValue(0xfa3), -1);
        ::DAT_0119f278 = promptDelay;
        char password[16];
        ::FUN_00403d30(password, 0, 16);
        ::FUN_00403d30(password, '*', reinterpret_cast<::FUN_00501270_shell *>((terminal))->FUN_00501270((::TESObjectREFR *)(reference)));
        ::FUN_00406f60((::FUN_00406f90_this *)(::fnv_00758ad0::StrMem *)(&text), "%s%s", "> ", password);
        animation->InsertAtPosition(((const char *)(::FUN_00559450((int *)&(text)))), (intptr_t)reinterpret_cast<::FUN_00a00f30_shell *>((passwordTile))->FUN_00a00f30(0xfc4),
                                    (intptr_t)reinterpret_cast<::FUN_00a00e90_shell *>((passwordTile))->FindTraitValue(0xfa3), -1);
    }
}
}  // namespace fnv_00758ad0

#include "generated/data/fallout/interface/menus/computersmenu.inc"
