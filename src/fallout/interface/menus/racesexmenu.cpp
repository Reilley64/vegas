
// src/fallout/interface/menus/racesexmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/racesexmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fallout/interface/tile_fields.h"
#include "fnv/result_slot.h"
#include "fnv/simple_list_node_view.h"
#include "fnv/inventory_entry_fields.h"
#include "fnv/av_object_fields.h"
#include <cstdint>
#include <new>
#include <cstring>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/ActiveEffectCollection.h"
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/AudioClass_ae5680.h"
#include "fnv/decl/BGSDehydrationStage.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSFaceGenManager.h"
#include "fnv/decl/BSFaceGenModel.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/ButtonDevice.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DecalStub.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004169d0_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0043c610_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_00456520_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a8090_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004ed8c0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00539f20_Class.h"
#include "fnv/decl/FUN_0059f610Class.h"
#include "fnv/decl/FUN_005e7a60_cls.h"
#include "fnv/decl/FUN_005fc4d0_shell.h"
#include "fnv/decl/FUN_005fc5f0_shell.h"
#include "fnv/decl/FUN_005fdf40_shell.h"
#include "fnv/decl/FUN_005fdf60_shell.h"
#include "fnv/decl/FUN_005fdf80_shell.h"
#include "fnv/decl/FUN_005fdfa0_shell.h"
#include "fnv/decl/FUN_00601800_shell.h"
#include "fnv/decl/FUN_00602130_shell.h"
#include "fnv/decl/FUN_00602170_shell.h"
#include "fnv/decl/FUN_006031e0_shell.h"
#include "fnv/decl/FUN_00603200_shell.h"
#include "fnv/decl/FUN_00604250_shell.h"
#include "fnv/decl/FUN_0060b240_shell.h"
#include "fnv/decl/FUN_00613790_shell.h"
#include "fnv/decl/FUN_00613870_Class.h"
#include "fnv/decl/FUN_00624700_shell.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_00642660_shell.h"
#include "fnv/decl/FUN_006546c0_Class.h"
#include "fnv/decl/FUN_0065a840_t.h"
#include "fnv/decl/FUN_0065a910_shell.h"
#include "fnv/decl/FUN_0065a970_shell.h"
#include "fnv/decl/FUN_0070ec70_class.h"
#include "fnv/decl/FUN_0073ac90_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_007adcc0_class.h"
#include "fnv/decl/FUN_007b3810Class.h"
#include "fnv/decl/FUN_007b52a0_class.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_007b5330_Class.h"
#include "fnv/decl/FUN_007fed10.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00874460_cls.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0088d7d0_shell.h"
#include "fnv/decl/FUN_008c2b60_shell.h"
#include "fnv/decl/FUN_00944300_class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_0095e5f0_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00a00f30_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a0b110_shell.h"
#include "fnv/decl/FUN_00a23390_t.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a6e960_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad88b0_h.h"
#include "fnv/decl/FaceNpc.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/FocusManager.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/Light7FD.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MagicTargetDispel.h"
#include "fnv/decl/MenuDriver.h"
#include "fnv/decl/ModListOwner.h"
#include "fnv/decl/MyHack.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiTPointerListBase.h"
#include "fnv/decl/PlayerCharacter.h"
#include "fnv/decl/RaceAppearance__Race.h"
#include "fnv/decl/RenderTile.h"
#include "fnv/decl/S00a67410.h"
#include "fnv/decl/S00b5d9f0_Owner.h"
#include "fnv/decl/S654.h"
#include "fnv/decl/S9fb0.h"
#include "fnv/decl/S_00a592c0_Matrix3.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESNPC_Sub.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TESRace.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/TileFloatList.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0043ecb0__FUN_0043ecb0_shell.h"
#include "fnv/decl/fnv_0043ed90__AttachTask.h"
#include "fnv/decl/fnv_00496940__FUN_00496940_shell.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_006505d0__FUN_006505d0_class.h"
#include "fnv/decl/fnv_006546e0__FUN_006546e0_Class.h"
#include "fnv/decl/fnv_007181d0__FUN_007181d0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_0088c830__ThisC.h"
#include "fnv/decl/fnv_008a6840__FUN_008a6840_shell.h"
#include "fnv/decl/fnv_008a6970__FUN_008a6970_shell.h"
#include "fnv/decl/fnv_008b78c0__FUN_008b78c0_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a1d9e0__FUN_00a1d9e0_shell.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/sa040a0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00469000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004ea000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00603000.h"
#include "fnv/symbols_00607000.h"
#include "fnv/symbols_00615000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00651000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_00655000.h"
#include "fnv/symbols_00656000.h"
#include "fnv/symbols_00657000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00764000.h"
#include "fnv/symbols_007ad000.h"
#include "fnv/symbols_007df000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a04000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a6e000.h"
#include "fnv/symbols_00ad9000.h"
#include "fnv/symbols_00af6000.h"
#include "fnv/symbols_00afd000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_0104a000.h"
#include "fnv/symbols_01055000.h"
#include "fnv/symbols_01075000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011db000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_01202000.h"

// The leading fields of a race and sex menu option.
struct RaceSexOptionFields
{
    void* tile;
    unsigned int id;
    std::intptr_t value;
};
struct RaceSexMenu
{
    int FUN_007ac4f0();
};

// @fnv 0x007ac4f0
int RaceSexMenu::FUN_007ac4f0()
{
    return 0x40c;
}

// @fnv 0x007ac9c0
int __cdecl FUN_007ac9c0()
{
    return 0x40c;
}

struct FUN_007b2550_shell
{
    char pad00[0xe4];
    unsigned char unke4;

    void SetByteAtOffsetE4(unsigned char param);
};

// @fnv 0x007b2550
void FUN_007b2550_shell::SetByteAtOffsetE4(unsigned char ucValue)
{
    this->unke4 = ucValue;
}

struct FUN_007b2570_shell
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
    char FUN_007b2570();
};

struct C
{
    void* m_iFourthElementInteger;
    void* m_usTrailingValue;
    void* m_f;
};

// @fnv 0x007b2570
char FUN_007b2570_shell::FUN_007b2570()
{
    return m_iFourthElementInteger && ((C*)m_iFourthElementInteger)->m_f;
}

struct FUN_007b3720_shell
{
    char pad00[0x1d8];
    int unk1d8;

    void FUN_007b3720(int value);
};

// @fnv 0x007b3720
void FUN_007b3720_shell::FUN_007b3720(int value)
{
    this->unk1d8 = value;
}

struct TGF
{
};

struct RaceSexMenu_MenuOption
{
    TGF* pTGF;
    void FUN_007b3840(int& aiLow, int& aiHigh);
};

// If pTGF is set, reads floats 0x1006 and 0x1007 from it and stores them as ints into aiLow and aiHigh.
// @fnv 0x007b3840
void RaceSexMenu_MenuOption::FUN_007b3840(int& aiLow, int& aiHigh)
{
    if (pTGF)
    {
        aiLow = (int)reinterpret_cast<::TileListBoxCalls *>((pTGF))->GetFloat(0x1006);
        aiHigh = (int)reinterpret_cast<::TileListBoxCalls *>((pTGF))->GetFloat(0x1007);
    }
}

struct FUN_007b3b80_shell
{
    void FUN_007b3b80(intptr_t a, int b);
};

struct Tile
{
public:
    void Set(int, int);
public:
    static float GetInterfaceScale();
};


struct FUN_007b4180_shell
{
    Tile* m_tile;
    void SetSelected();
};

// @fnv 0x007b4180
void FUN_007b4180_shell::SetSelected()
{
    if (m_tile)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((m_tile))->FUN_00a012d0(::FUN_00a00940("_selected", -1), 1.0f, true);
    }
}

struct FUN_007ac530_shell
{
    void FUN_007ac560();
    void* FUN_007ac530(unsigned int);
};
// Calls FUN_007ac560, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007ac530
void* FUN_007ac530_shell::FUN_007ac530(unsigned int flags)
{
    FUN_007ac560();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_007b3af0_shell
{
    void FUN_007b3af0();
};
struct FUN_007ac700_shell
{
    void* FUN_007ac700(unsigned int flags);
};
namespace fnv_007acb30 {
struct FUN_007acb30_shell
{
    void* FUN_007acb30(unsigned int flags);
};
// Calls FUN_007fed10, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x007acb30
void* FUN_007acb30_shell::FUN_007acb30(unsigned int flags)
{
    reinterpret_cast<::FUN_007fed10 *>(this)->FUN_007fed10::~FUN_007fed10();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_007acb30


struct ArrSI
{
    char pad[8];
    void* unk08;
};

class TESEffectShader;
struct MiddleHighProcess
{
    uintptr_t GetAnimation();
public:
    void AssignEffectShader(::TESEffectShader *);
};

// Returns 1 if si is non-null, has flags, and DAT_011da634's process animation equals si's flags; otherwise 0.
// @fnv 0x007ad8d0
char __cdecl IsAnimationMatch(ArrSI* pArrSI)
{
    int result;
    if (pArrSI && ((std::uintptr_t)(pArrSI->unk08)) && DAT_011da634 && *(int*)((char*)DAT_011da634 + 0xd8) &&
        ((MiddleHighProcess*)*(intptr_t*)((char*)DAT_011da634 + 0xd8))->GetAnimation() == ((std::uintptr_t)(pArrSI->unk08)))
        result = 1;
    else
        result = 0;
    return (char)result;
}

struct FUN_007ae160_Obj
{
    TGF* pTGF;
    bool IsSelected();
};
// Returns true when pTGF is non-null and its _selected float equals 2.0.
// @fnv 0x007ae160
bool FUN_007ae160_Obj::IsSelected()
{
    return pTGF && (reinterpret_cast<::TileListBoxCalls *>((pTGF))->GetFloat(::FUN_00a00940("_selected", -1)) == 2.0);
}

struct FUN_007b3740_shell
{
    TGF* m_pTGF;
    int GetFloat1005();
};

// @fnv 0x007b3740
int FUN_007b3740_shell::GetFloat1005()
{
    return (int)reinterpret_cast<::TileListBoxCalls *>((m_pTGF))->GetFloat(0x1005);
}

struct Tile_Set_Helper
{
};
struct TileValueAccessor
{
    Tile* m_tile;
    void FUN_007b3890(int aiLow, int aiHigh);
};
namespace fnv_007b3970 {
struct Tile_Set_Helper
{
};
struct FUN_007b3970_shell
{
    Tile_Set_Helper* m_tile;
    void SetTileEnabled(bool abEnabled);
};
// If m_tile is set, calls Set on it with the "_enabled" key and abEnabled.
// @fnv 0x007b3970
void FUN_007b3970_shell::SetTileEnabled(bool abEnabled)
{
    if (m_tile)
        reinterpret_cast<::Tile *>((m_tile))->Set(::FUN_00a00940("_enabled", -1), abEnabled);
}
}  // namespace fnv_007b3970

struct S007b39b0
{
    TGF* m_iWordAt00;
    int GetPosition();
};
// @fnv 0x007b39b0
int S007b39b0::GetPosition()
{
    return (int)reinterpret_cast<::TileListBoxCalls *>((m_iWordAt00))->GetFloat(::FUN_00a00940("_position", -1));
}

extern const char $SG2670[];

struct FUN_007b4140_shell
{
    Tile* m_tile;
    void SetTileValue();
};

// @fnv 0x007b4140
void FUN_007b4140_shell::SetTileValue()
{
    if (m_tile)
        reinterpret_cast<::FUN_00a012d0_t *>((m_tile))->FUN_00a012d0(::FUN_00a00940($SG2670, -1), DAT_010162c0, true);
}

struct Flt
{
    operator unsigned int() const;
};
struct TL
{
};
struct S
{
    Tile* FUN_007b41c0(intptr_t);
};
// Walks the linked list starting at the value stored in this, returning the first Tile whose first int equals a, or 0 if none matches.
// @fnv 0x007b41c0
Tile* S::FUN_007b41c0(intptr_t a)
{
    void* cur = (void*)(uintptr_t)(*(Flt*)this);
    while (cur)
    {
        Tile* item = ((::Tile *)(reinterpret_cast<::ListStandIn *>((((TL*)this)))->FUN_0057cbe0((int **)&(cur))));
        if (*(int*)item == a)
            return item;
    }
    return 0;
}

namespace fnv_007b4210 {
struct Flt
{
    operator unsigned int();
};
struct TL
{
};
struct TileValueAccessor
{
    int _00;
    unsigned int _04;
};
struct FUN_007b4210_shell
{
    void* head;

    TileValueAccessor* FindByColor(unsigned int);
};
// Walks the tile list from this object, returning the first entry whose _04 equals aiColor, or null if none matches.
// @fnv 0x007b4210
TileValueAccessor* FUN_007b4210_shell::FindByColor(unsigned int aiColor)
{
    void* piter;
    TileValueAccessor* popt;
    piter = head;
    while (piter)
    {
        popt = (TileValueAccessor*)(Tile*)((::Tile *)(reinterpret_cast<::ListStandIn *>((((TL*)this)))->FUN_0057cbe0((int **)&(piter))));
        if (popt->_04 == aiColor)
            return popt;
    }
    return 0;
}
}  // namespace fnv_007b4210

struct FUN_007b4900_shell
{
    int m0;
    int m1;
    int m2;
    FUN_007b4900_shell* FUN_007b4900();
};
// Sets m0 and m2 to zero and returns this.
// @fnv 0x007b4900
FUN_007b4900_shell* FUN_007b4900_shell::FUN_007b4900()
{
    m0 = 0;
    m2 = 0;
    return this;
}

struct FUN_007b5300_param
{
    int _0;
    int _4;
};

// A node of NiTList.
struct NiTListItemFields
{
    NiTListItemFields* m_pkNext;
    NiTListItemFields* m_pkPrev;
    void* m_element;
};
struct FUN_007b5300_shell
{
    int GetSecondField(FUN_007b5300_param* p);
};
// Returns the second field of the given parameter struct, or 0 if the pointer is null.
// @fnv 0x007b5300
int FUN_007b5300_shell::GetSecondField(FUN_007b5300_param* p)
{
    return p ? p->_4 : 0;
}

namespace fnv_007ac500 {
struct Tile;
struct RaceSexMenu
{
    char pad[0x78];
    Tile* m_pTiles[24];
    void SetTile(int aiID, Tile* apTile);
};

// @fnv 0x007ac500
void RaceSexMenu::SetTile(int aiID, Tile* apTile)
{
    if (aiID >= 0 && aiID < 6)
        m_pTiles[aiID] = apTile;
}
}  // namespace fnv_007ac500

struct FUN_007adc30_shell
{
    char _pad[0x4];
    void* unk04;
    char pad08[0x20];
    void* unk28;
    char pad2c[0x5c];
    void* unk88;
    void* unk8c;
    char pad90[0x5c];
    unsigned int m_flags;
    bool FUN_007adc30(int trait);
};

// Returns whether the bit for the given trait index is set in m_flags.
// @fnv 0x007adc30
bool FUN_007adc30_shell::FUN_007adc30(int trait)
{
    return (m_flags & (1 << trait)) != 0;
}

struct TileHelper
{
};
struct BSAudio
{
};
struct OptList
{
};
struct FORenderedMenu
{
};
class Tile;
struct InterfaceManager
{
    FORenderedMenu* GetActiveRenderedMenu();
public:
    ::Tile *FUN_00586150();
};
struct FUN_007af180_shell : FUN_007adc30_shell
{
    bool FUN_007af180(intptr_t aeList);
    char padf0[0x30];
    int unk120;
};
struct TESActorBase
{
    int GetSex();
};
struct HairResult
{
    int a;
    int b;
};
struct FUN_004ac110_shell
{
    HairResult* FUN_004ac110();
};
struct GlobalObject_00869f00
{
    void* vtable;
    void** data;
    unsigned int size;
    unsigned int capacity;
};
struct MenuOption2
{
};
struct FUN_007af610_shell
{
    char pad00[0x30];
    MenuOption2* pOptions;
    char pad34[0xa4];
    void* pNPC;
    GlobalObject_00869f00 hairs;
    void UpdateHairMenuOption();
};
// @fnv 0x007af610
void FUN_007af610_shell::UpdateHairMenuOption()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((&hairs))->Clear(false);
    ::fnv_00603280::FUN_00603280((intptr_t)(((FUN_004ac110_shell*)pNPC)->FUN_004ac110()),
                 ((TESActorBase*)pNPC)->GetSex(),
                 (intptr_t)(&hairs));
    MenuOption2* popt = ((::MenuOption2 *)(reinterpret_cast<::fnv_007b4210::FUN_007b4210_shell *>((pOptions))->FindByColor(0x18)));
    if (reinterpret_cast<::FUN_0076b610_Class *>((&hairs))->FUN_0076b610())
    {
        reinterpret_cast<::fnv_007b3970::FUN_007b3970_shell *>((popt))->SetTileEnabled(false);
    }
    else
    {
        reinterpret_cast<::fnv_007b3970::FUN_007b3970_shell *>((popt))->SetTileEnabled(true);
        reinterpret_cast<::TileValueAccessor *>((popt))->FUN_007b3890(true, hairs.size);
    }
}

namespace fnv_007b1ca0 {
struct TESNPC;
struct TESEyes;
struct TESHair
{
};
struct FUN_005fdf40_shell
{
};
struct FUN_005fc5f0_shell
{
};
struct TESActorBase
{
    int GetSex();
};
struct HairNode
{
};
struct TESRace
{
    TESEyes* GetReferencedValue();
};
struct FUN_004ac110_shell
{
    TESRace* FUN_004ac110();
};
struct TESNPC
{
    TESHair* GetHair();
};
struct FUN_007adc60_shell
{
    void FUN_007adc60(int, bool);
};
struct FUN_007b1ca0_t
{
    char pad[0xd8];
    TESNPC* pNPC;
    void RebuildFaceGen(int);
    void UpdateEyeTextures();
    void UpdateHairAndEyes();
};

// @fnv 0x007b1ca0
void FUN_007b1ca0_t::UpdateHairAndEyes()
{
    if (!reinterpret_cast<::FUN_005fdfa0_shell *>((pNPC->GetHair()))->IsHairValidForNPC((::TESNPC *)(pNPC)))
    {
        TESHair* m_pHair = ((::fnv_007b1ca0::TESHair *)(reinterpret_cast<::FUN_00613870_Class *>((((FUN_004ac110_shell*)pNPC)->FUN_004ac110()))->FUN_00613870(((TESActorBase*)pNPC)->GetSex())));
        for (HairNode* pNode = ((::fnv_007b1ca0::HairNode *)(::FUN_0045bb80((intptr_t)(((FUN_004ac110_shell*)pNPC)->FUN_004ac110()))));
             m_pHair == 0 && pNode && *((::fnv_007b1ca0::TESHair **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item)); pNode = ((::fnv_007b1ca0::HairNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070())))
        {
            if (reinterpret_cast<::FUN_005fdf40_shell *>((((FUN_005fdf40_shell*)*((::fnv_007b1ca0::TESHair **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item)))))->FUN_005fdf40())
            {
                if ((((TESActorBase*)pNPC)->GetSex() == 0 && reinterpret_cast<::FUN_005fdf60_shell *>(((*((::fnv_007b1ca0::TESHair **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item)))))->FUN_005fdf60()) ||
                    (((TESActorBase*)pNPC)->GetSex() == 1 && reinterpret_cast<::FUN_005fdf80_shell *>(((*((::fnv_007b1ca0::TESHair **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item)))))->IsFlag4Clear()))
                    m_pHair = *((::fnv_007b1ca0::TESHair **)(&reinterpret_cast<::SimpleListNodeView*>(pNode)->m_item));
            }
        }
        reinterpret_cast<::FUN_006031e0_shell *>((pNPC))->SetHair((::TESHair *)(m_pHair));
        RebuildFaceGen(1);
    }
    if (!reinterpret_cast<::FUN_005fc5f0_shell *>((((FUN_005fc5f0_shell*)((MiddleHighProcess*)pNPC)->GetAnimation())))->CanBeNPC((::TESNPC *)(pNPC)))
    {
        reinterpret_cast<::FUN_00603200_shell *>((pNPC))->SetEyes((::TESEyes *)(::fnv_007b1ca0::TESEyes *)(((FUN_004ac110_shell*)pNPC)->FUN_004ac110()->GetReferencedValue()));
        UpdateEyeTextures();
    }
    ((FUN_007adc60_shell*)this)->FUN_007adc60(0, true);
    ((FUN_007adc60_shell*)this)->FUN_007adc60(1, true);
}
}  // namespace fnv_007b1ca0

struct NiUpdateData
{
    float f;
    bool b;
    bool c;
    NiUpdateData(float, bool, bool);
};
class NiAVObject;
struct NiNode
{
    void Update(NiUpdateData const&);
public:
    ::NiAVObject *GetAt(unsigned int);
};
struct PC_00605d70
{
    NiNode* GetNode(bool);
};
struct ShadowSceneNode
{
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* __cdecl GetShadowSceneNodeForIndex(int);
};
struct FUN_007fd660_shell
{
};
struct FUN_007b1ae0_shell
{
    void UpdateShadowSceneNode();
};
// Updates the shadow scene node for the player's node, then updates the node and, if a condition holds, calls FUN_007fd660 with 1.0f.
// @fnv 0x007b1ae0
void FUN_007b1ae0_shell::UpdateShadowSceneNode()
{
    int pad;
    reinterpret_cast<::S00b5d9f0_Owner *>((NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3)))->FUN_00b5d9f0((::S00b5d9f0_Obj *)(::NiNode *)(((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::PC_00605d70 * *>(&::_g_thePlayer))))->FUN_00950bb0(false)))), false);
    NiUpdateData data(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((reinterpret_cast<NiNode*>(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(3))))->FUN_00a59c60((std::intptr_t)&(data));
    if (((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->GetActiveRenderedMenu())
        reinterpret_cast<::Light7FD *>((reinterpret_cast<FUN_007fd660_shell*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->GetActiveRenderedMenu())))->FUN_007fd660(1.0f);
}

struct IMStandIn
{
};
struct InputFocusController
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    IMStandIn* m_20;
    bool SetFocus(bool abFocus);
};
// @fnv 0x007b3fd0
bool InputFocusController::SetFocus(bool abFocus)
{
    bool bret = false;
    if (abFocus)
    {
        if (m_20 && *(void**)m_20)
        {
            reinterpret_cast<::FocusManager *>((reinterpret_cast<IMStandIn*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00715860((::FocusTile *)((std::intptr_t)*(void**)m_20), 0xfc3, 1);
            bret = true;
        }
    }
    else
    {
        reinterpret_cast<::FocusManager *>((reinterpret_cast<IMStandIn*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00715860((::FocusTile *)(0), 0xfc3, 1);
        m_20 = 0;
        bret = true;
    }
    return bret;
}

struct FUN_007b5180_shell : FUN_007af610_shell
{
    char _pad[0x30];
    void* unk30;
    char pad34[0x90];
    MenuOption2* m_pCurrentOption;
    void HandleOptionSelection();
    void CreateMenuOption();
};
struct FUN_00601830_shell
{
};
struct FUN_007adc60_shell
{
    void FUN_007adc60(int, bool);
};
struct FUN_007b18f0_shell
{
    void HandleMenuKey(int);
};
struct FUN_007b1e70_shell
{
    void UpdateFaceGen(int, int, int);
};
struct FUN_007b25a0_shell
{
    void FUN_007b25a0();
};
struct FUN_007b51f0_shell : FUN_007adc30_shell
{
    void FUN_007b51f0();
};
// @fnv 0x007b51f0
void __cdecl FUN_007b51f0()
{
    if (DAT_011da634)
    {
        if (ConsumeByteAtE4() == 1 || ((FUN_007adc30_shell*)DAT_011da634)->FUN_007adc30(7))
        {
            reinterpret_cast<::FaceNpc *>((((FUN_00601830_shell*)(void*)(*((char**)DAT_011da634 + 0xd8 / 4)))))->RandomizeFace(1, 0, 1);
            ((FUN_007adc60_shell*)DAT_011da634)->FUN_007adc60(7, true);
            ((FUN_007b18f0_shell*)DAT_011da634)->HandleMenuKey(0x22);
            ((FUN_007b18f0_shell*)DAT_011da634)->HandleMenuKey(0x23);
            ((FUN_007b1e70_shell*)DAT_011da634)->UpdateFaceGen(1, 1, 0);
            ((FUN_007b25a0_shell*)DAT_011da634)->FUN_007b25a0();
            ((FUN_007adc60_shell*)DAT_011da634)->FUN_007adc60(8, false);
            ((FUN_007adc60_shell*)DAT_011da634)->FUN_007adc60(9, false);
        }
    }
}

struct _ref_006815c0_shell
{
};

struct FUN_007b1e50_shell
{
    unsigned char _pad[0xa8];
    _ref_006815c0_shell m_ref;

    int GetReferencedValue();
};

// @fnv 0x007b1e50
int FUN_007b1e50_shell::GetReferencedValue()
{
    return *((int *)(&reinterpret_cast<::SimpleListNodeView*>(&(m_ref))->m_item));
}

struct Menu
{
public:
    void SetMenuVisibility(bool);
};
struct InterfaceManager_helper
{
};
struct TileH
{
};
struct TileNode
{
};
struct Tile_Helper
{
};
struct Str6a70
{
    Str6a70& operator=(const char*);
};
extern const char DAT_010759bc[];
class TileMenu;
struct FUN_00a1dc70_shell
{
public:
    void FUN_00a1dc70(::TileMenu *, bool);
};
struct SettingT_GameSettingCollection_
{
};
struct GlobalObject_0040c150
{
};
struct StrH
{
};
struct GlobalObject_004037b0
{
};
int __cdecl FUN_004b7220();
struct Actor
{
};
class TESObjectREFR;
struct InventoryChanges
{
    ArrSI* FUN_004c8c10(unsigned int, int);
public:
    static ::InventoryChanges *CreateForReference(::TESObjectREFR *);
};
struct RaceInit
{
    void SetupRaceMenu(int);
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
struct FUN_007ac9f0
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
    FUN_007ac9f0();
};
struct MagicHitEffect
{
};
struct NiPick
{
    void FUN_00705fc0(void*);
};
struct Im7181
{
};
// 0x00984f60 is a folded field setter; on rendered menus it stores the menu tile.
struct RenderedMenuTileView
{
    char pad[0x18];
    void* pTile;
};
// @fnv 0x007ac730
Tile* __cdecl GetOrCreateMenuTile(intptr_t param)
{
    Tile* previous = ((::Tile *)(::FUN_00a09030(FUN_007ac9c0())));
    if (previous)
        return previous;
    Tile* tile = reinterpret_cast<::fnv_00a01b00::TileLoader *>((((TileH*)reinterpret_cast<::InterfaceManager *>((((InterfaceManager_helper*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00586150())))->FUN_00a01b00((void *)(DAT_010759bc));
    if (tile)
    {
        DAT_011da634 = reinterpret_cast<::FUN_00a03c90_shell *>((((TileH*)tile)))->FUN_00a03c90();
        ((FUN_00a1dc70_shell*)DAT_011da634)->FUN_00a1dc70((::TileMenu *)(tile), false);
        if (!(unsigned int)(*reinterpret_cast<::Flt *>(&::g_011da70c)))
        {
            *(Str6a70*)&(*reinterpret_cast<::Flt *>(&::g_011da70c)) = ((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&::g_011d35c4)))->GetMenuTitle()));
            *(Str6a70*)&(*reinterpret_cast<::Flt *>(&::g_011da700)) = ((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&::g_011d34b0)))->GetMenuTitle()));
            *(Str6a70*)&::g_011da6f4 = ((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&::g_011d1fec)))->GetMenuTitle()));
            if (FUN_004b7220() != 3)
            {
                reinterpret_cast<::FUN_007b52a0_class *>((((StrH*)&(*reinterpret_cast<::Flt *>(&::g_011da70c)))))->FUN_007b52a0();
                reinterpret_cast<::FUN_007b52a0_class *>((((StrH*)&(*reinterpret_cast<::Flt *>(&::g_011da700)))))->FUN_007b52a0();
                reinterpret_cast<::FUN_007b52a0_class *>((((StrH*)&::g_011da6f4)))->FUN_007b52a0();
            }
        }
        DAT_011da688 = ((unsigned char)(reinterpret_cast<::fnv_008a6970::FUN_008a6970_shell *>(((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))->FUN_008a6970()));
        reinterpret_cast<::fnv_008a6840::FUN_008a6840_shell *>(((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))->FUN_008a6840(0);
        InventoryChanges* inventory = ::InventoryChanges::CreateForReference((::TESObjectREFR *)((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))));
        for (unsigned int i = 0; i < 20; i++)
        {
            switch (i)
            {
            case 0:
            case 1:
            case 5:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 14:
            case 15:
                DAT_011da638[i] = inventory->FUN_004c8c10(i, 0);
                if (DAT_011da638[i])
                    reinterpret_cast<::FUN_0088d7d0_shell *>(((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))->FUN_0088d7d0((::TESBoundObject *)(void *)((void*)((std::uintptr_t)((DAT_011da638[i])->unk08))), 1, (::ExtraDataList *)(void *)(0), 0, 0, 1);
                break;
            }
        }
        ((RaceInit*)DAT_011da634)->SetupRaceMenu(param);
        if (*::g_011db620.Bool())
        {
            ::fnv_00a04200::FUN_00a04200(false);
            FUN_007ac9f0* pRenderData = new FUN_007ac9f0;
            reinterpret_cast<::MiddleHighProcess *>((pRenderData))->AssignEffectShader((::TESEffectShader *)(param));
            reinterpret_cast<RenderedMenuTileView*>(pRenderData)->pTile = tile;
            ((NiPick*)pRenderData)->FUN_00705fc0(((::NiNode *)(reinterpret_cast<::TileFields *>((((TileNode*)tile)))->renderedNode)));
            reinterpret_cast<::fnv_007181d0::FUN_007181d0_shell *>((((Im7181*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->SetRenderedMenu((::fnv_007181d0::FORenderedMenu *)((std::intptr_t)pRenderData));
        }
    }
    return tile;
}

struct Obj0
{
};

struct Obj1
{
    int FUN_00603b50();
};

struct Holder
{
    char _pad[0xd8];
    Obj1* m_d8;
};

// Returns 1 if p and DAT_011da634 and its m_d8 are non-null and m_d8's FUN_00603b50 equals p's FUN_0044ddc0, else 0.
// @fnv 0x007ad860
unsigned char __cdecl FUN_007ad860(Obj0* pObject)
{
    int r;
    if (pObject != 0 && ((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((pObject))->GetName())) != 0 && DAT_011da634 != 0 && ((Holder*)DAT_011da634)->m_d8 != 0 &&
        ((Holder*)DAT_011da634)->m_d8->FUN_00603b50() == ((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((pObject))->GetName())))
    {
        r = 1;
    }
    else
    {
        r = 0;
    }
    return r;
}

struct FUN_007ad940_Holder
{
    char unk00[0xd8];
    void* m_d8;
};

int FUN_005f0cc0(void* self);

// @fnv 0x007ad940
unsigned char __cdecl FUN_007ad940(int aiValue)
{
    int result;
    if (aiValue != 0 && DAT_011da634 != 0 && ((FUN_007ad940_Holder*)DAT_011da634)->m_d8 != 0 &&
        ((FUN_005f0cc0(((FUN_007ad940_Holder*)DAT_011da634)->m_d8) == 0 && ((std::intptr_t)(reinterpret_cast<::Callees *>((aiValue))->FUN_00726070())) == 0x15) ||
         (FUN_005f0cc0(((FUN_007ad940_Holder*)DAT_011da634)->m_d8) == 1 && ((std::intptr_t)(reinterpret_cast<::Callees *>((aiValue))->FUN_00726070())) == 0x16)))
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return (unsigned char)result;
}

struct FUN_007ad9c0_Sub
{
    bool Probe();
};

struct FUN_007ad9c0_Owner
{
};

struct FUN_007ad9c0_Arg
{
};

// Returns 1 when a1 is non-null and DAT_011da634's sub at offset 0xd8 fails Probe and its Lookup equals a1->Value(); otherwise 0.
// @fnv 0x007ad9c0
char __cdecl IsArgValueInSubLookup(FUN_007ad9c0_Arg* a1)
{
    int result;
    if (a1 != 0 && DAT_011da634 != 0 && *(void**)((char*)DAT_011da634 + 0xd8) != 0 &&
        ((::FUN_007ad9c0_Sub *)(reinterpret_cast<::FUN_00602170_shell *>((((FUN_007ad9c0_Owner*)*(void**)((char*)DAT_011da634 + 0xd8))))->FUN_00602170()))->Probe() == false &&
        *((int *)(&reinterpret_cast<::SimpleListNodeView*>(((::FUN_007ad9c0_Sub *)(reinterpret_cast<::FUN_00602170_shell *>((((FUN_007ad9c0_Owner*)*(void**)((char*)DAT_011da634 + 0xd8))))->FUN_00602170())))->m_item)) == ((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((a1))->GetName())))
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return (char)result;
}

struct RSTile
{
};

struct RSOptionList
{
};

struct RSMenu
{
    int unk00;
    void* unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    RSOptionList* optionLists[4];
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
    RSTile* tile8C;

    void Refresh();
    int GetCurrentPage();
    void Accept();
};

struct RSIM
{
};

struct RSItem
{
    ~RSItem();
};

struct RSPlayer
{
};



// @fnv 0x007ada40
void __cdecl UpdateRaceSexMenu()
{
    if ((*reinterpret_cast<::RSMenu * *>(&::DAT_011da634)))
    {
        if (reinterpret_cast<::FUN_007adc30_shell *>(((*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))))->FUN_007adc30(9))
        {
            (*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))->Refresh();
            reinterpret_cast<::FUN_007adc60_shell *>(((*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))))->FUN_007adc60(9, false);
        }
        if (ConsumeByteAtE4() == 1)
        {
            if (::FUN_004b71d0())
            {
                if (!reinterpret_cast<::InputFocusController *>(((*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))->optionLists[(*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))->GetCurrentPage()]))->SetFocus(true))
                {
                    if (reinterpret_cast<::sa040a0::Owner *>(((*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))->tile8C))->IsAllChildrenFlag0())
                    {
                        reinterpret_cast<::FocusManager *>((((::RSIM *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00715860((::FocusTile *)((*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))->tile8C), 0xfc3, 1);
                    }
                    else
                    {
                        reinterpret_cast<::ModListOwner *>(((*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))->optionLists[(*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))->GetCurrentPage()]))->FUN_007b4410();
                        (*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))->Accept();
                    }
                }
            }
        }
        else
        {
            ::fnv_007df4e0::UpdateStatsMenuLevelText();
            reinterpret_cast<::Tile *>((((::RSTile *)((*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))->unk04))))->Set(0x1772, 1);
            reinterpret_cast<::fnv_00a1d9e0::FUN_00a1d9e0_shell *>(((*reinterpret_cast<::RSMenu * *>(&::DAT_011da634))))->FUN_00a1d9e0();
            (*reinterpret_cast<::RSMenu * *>(&::DAT_011da634)) = 0;
            if (::FUN_00705100())
            {
                ::StartDialogueForTopic((::TESTopic *)(((std::intptr_t)(::fnv_0061a2d0::GetTopicSubTypeName(5, 4)))));
            }
            for (int i = 0; i < 20; i++)
            {
                if ((*reinterpret_cast<RSItem * (*)[20]>(&::DAT_011da638))[i])
                {
                    reinterpret_cast<::fnv_0088c830::ThisC *>(((*reinterpret_cast<::RSPlayer * *>(&::_g_thePlayer))))->FUN_0088c830((::fnv_0088c830::FormC *)(void *)(((void *)(reinterpret_cast<::Twin_0044ddc0 *>(((*reinterpret_cast<RSItem * (*)[20]>(&::DAT_011da638))[i]))->GetName()))), 1, 0, true, false, true);
                    delete (*reinterpret_cast<RSItem * (*)[20]>(&::DAT_011da638))[i];
                    (*reinterpret_cast<RSItem * (*)[20]>(&::DAT_011da638))[i] = 0;
                }
            }
            reinterpret_cast<::fnv_008a6840::FUN_008a6840_shell *>(((*reinterpret_cast<::RSPlayer * *>(&::_g_thePlayer))))->FUN_008a6840((*reinterpret_cast<bool *>(&::DAT_011da688)));
            reinterpret_cast<::FUN_007adcc0_class *>(((*reinterpret_cast<::RSPlayer * *>(&::_g_thePlayer))))->SetAllow(true);
        }
    }
}

class HighProcess7AE
{
  public:
};

class Tile7AE
{
  public:
};

class TileList7AE
{
  public:
};

class Timer7AE
{
  public:
};


class StatsMenu7AE
{
  public:
    int GetCurrentPage();
    void FUN_007ae1b0(int iType, HighProcess7AE* pkProcess);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24;
    TileList7AE* m_apkLists[10];
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4;
    float m_fTime;
    int m_iValue;
    HighProcess7AE* m_pkProcess;
    Tile7AE* m_pkTile;
};

// For type 0x69 stores the process and its level tile value; for type 1 stores the interface timer time.
// @fnv 0x007ae1b0
void StatsMenu7AE::FUN_007ae1b0(int iType, HighProcess7AE* pkProcess)
{
    switch (iType)
    {
    case 0x69:
        m_pkProcess = pkProcess;
        m_pkTile = ((::Tile7AE *)(reinterpret_cast<::S *>((m_apkLists[GetCurrentPage()]))->FUN_007b41c0(((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((pkProcess))->FUN_0045cd60())))));
        m_iValue = reinterpret_cast<::FUN_007b3740_shell *>((m_pkTile))->GetFloat1005();
    case 1:
        m_fTime = reinterpret_cast<::MyHack *>((((::Timer7AE *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007697f0();
    }
}

class TESNPC;
struct TESFullName
{
};
struct Hair
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    TESFullName fullName;
};
struct HairNode
{
};
struct TESDataHandler
{
};
struct HairOption
{
};
struct HairOptions
{
    HairOption* FUN_007b3b80(const char*, int);
};
struct HairMenu
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
    HairOptions* options;
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
    TESNPC* npc;
    void PopulateHairOptions();
};
class B7AF450NPC;

class B7AF450Texture
{
  public:
};

class B7AF450Eyes
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    B7AF450Texture m_kTexture;

};

class B7AF450EyesNode
{
  public:
};

class B7AF450DataHandler
{
  public:
};

class B7AF450ListItem
{
  public:
};

class B7AF450ListBox
{
  public:
    B7AF450ListItem* AddItem(const char* pcText, int iType);
};


class B7AF450RaceMenu
{
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
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    B7AF450ListBox* m_pkListBox;
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
    B7AF450NPC* m_pkNPC;

    void PopulateEyesList();
};

// SyncListItemTemplate: thiscall, /MT /Od /GS /EHsc. Two guarded blocks on flags from this->m_34 / this->m_d8.
struct Opt34
{
};
struct D8Obj
{
    int FUN_005f0cc0();
};
struct SpStr
{
    void* m_ptr;
    int m_len;
    SpStr();
    ~SpStr();
};
struct StrTable
{
};

struct FUN_007af520_cls
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
    Opt34* m_34;
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
    D8Obj* m_d8;
    void SyncListItemTemplate();
};

namespace fnv_007af900 {
struct BSStringTChar
{
    char* data;
    unsigned short length;
    unsigned short capacity;
    BSStringTChar();
    ~BSStringTChar();
    operator const char*() const;
};
struct SettingT_GameSettingCollection_
{
};
struct GameSettingCollection
{
    bool GetSetting(const char*, SettingT_GameSettingCollection_**);
};
struct HairOption
{
};
struct HairOptionList
{
};
struct GlobalObject_0040c150
{
};
struct HairMenu
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
    HairOptionList* unk40;
    void ApplyHairOption(HairOption* option);
    void FUN_007afa40(int);
    void FUN_007b3660();
};
// @fnv 0x007af900
void HairMenu::ApplyHairOption(HairOption* option)
{
    if (!option)
        return;
    if (((std::intptr_t)(reinterpret_cast<::Callees *>((option))->FUN_00726070())) == 29)
    {
        SettingT_GameSettingCollection_* setting = 0;
        SettingT_GameSettingCollection_* valueSetting = 0;
        bool found;
        {
            BSStringTChar name;
            ::FUN_00406f60((::FUN_00406f90_this *)(::fnv_007af900::BSStringTChar *)(&name), "iHairColor%02d", reinterpret_cast<::FUN_007b3740_shell *>((option))->GetFloat1005());
            found = ((::fnv_007af900::GameSettingCollection *)(::GetGameSettingCollection()))->GetSetting(name, &valueSetting);
            ::FUN_00406f60((::FUN_00406f90_this *)(::fnv_007af900::BSStringTChar *)(&name), "sHairColor%d", reinterpret_cast<::FUN_007b3740_shell *>((option))->GetFloat1005());
            found = ((::fnv_007af900::GameSettingCollection *)(::GetGameSettingCollection()))->GetSetting(name, &setting);
            reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(((const char *)(reinterpret_cast<::StartMenu *>((setting))->GetMenuTitle())));
            FUN_007afa40(*((int *)&(::FUN_0043d4d0((int *)(valueSetting)))));
        }
    }
    else
    {
        reinterpret_cast<::FUN_007b3810Class *>((((::fnv_007af900::HairOption *)(reinterpret_cast<::fnv_007b4210::FUN_007b4210_shell *>((unk40))->FindByColor(29)))))->FUN_007b3810(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007af900::GlobalObject_0040c150 *>(&::g_011d3528))))->GetMenuTitle())));
    }
    FUN_007b3660();
}
}  // namespace fnv_007af900

struct FUN_007afa40_mgr
{
};
struct FUN_00726070_shell
{
};
struct FUN_007afa40_cls
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    FUN_007afa40_mgr* m_40;
    void FUN_007afa40(unsigned int value);
};

class B7B18F0Menu
{
  public:
    void HandleMenuKey(int iKey);
};

struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix FUN_0043f8d0(const Matrix&) const;
};
struct SceneObject
{
};
struct ScenePointer
{
};
struct ScaleObject
{
};
struct Target
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
    int unk0cc;
    int unk0d0;
    ScenePointer scene;
    ScaleObject* scale;
    bool FUN_007b1970(float, bool);
};
// @fnv 0x007b1970
bool Target::FUN_007b1970(float offset, bool force)
{
    Matrix p = *((::Matrix *)(::FUN_006a9540((char *)(((::SceneObject *)(::FUN_00559450((int *)&(scene))))))));
    float s, a, i;
    reinterpret_cast<::S_00a592c0_Matrix3 *>(&(p))->DecomposeToEulerAngles(s, a, i);
    float h = i - offset;
    if (h < 0.0)
        h += 6.2831854820251465;
    else if (h > 6.2831854820251465)
        h -= 6.2831854820251465;
    if (i == h && !force)
        return false;
    reinterpret_cast<::FUN_004a0c90_shell *>(&(p))->FUN_004a0c90(h);
    Matrix f = (*reinterpret_cast<::Matrix *>(&::DAT_011f4248));
    reinterpret_cast<::FUN_00642660_shell *>(&(f))->SetMatrixElement(0, 0, reinterpret_cast<::FUN_00604250_shell *>((scale))->GetWeight());
    reinterpret_cast<::FUN_00642660_shell *>(&(f))->SetMatrixElement(1, 1, reinterpret_cast<::FUN_00604250_shell *>((scale))->GetWeight());
    reinterpret_cast<::FUN_00642660_shell *>(&(f))->SetMatrixElement(2, 2, reinterpret_cast<::FUN_00944300_class *>((scale))->FUN_00944300());
    p = p.FUN_0043f8d0(f);
    reinterpret_cast<::FUN_0043fa80_s *>((((::SceneObject *)(::FUN_00559450((int *)&(scene))))))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&p)));
    reinterpret_cast<::FUN_007b1ae0_shell *>(this)->UpdateShadowSceneNode();
    return true;
}

namespace fnv_007b2b50 {
struct StringB50
{
    char* text;
    unsigned short length, capacity;
    StringB50();
    ~StringB50();
};
struct FixedB50
{
    char* text;
    FixedB50(const char*);
    ~FixedB50();
    operator const char*() const;
};
struct ColorB50
{
    float r, g, b, a;
    ColorB50(float, float, float, float);
};
struct PropertyB50
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    ColorB50 color;
};
struct PointB50
{
    float x, y, z;
    PointB50(float, bool, bool);
};
struct NodeB50
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual NodeB50* v01c();
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
    virtual NodeB50* v09c(const FixedB50&);
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
    virtual void v0e8(NodeB50*);
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    unsigned FUN_0043b480();
};
struct PtrB50
{
    NodeB50* ptr;
    PtrB50(NodeB50*);
    ~PtrB50();
    PtrB50& operator=(NodeB50*);
    operator NodeB50*() const;
};
struct SnapshotB50
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9c;
    unsigned unka0;
    unsigned unka4;
    unsigned unka8;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    unsigned unkc8;
    unsigned unkcc;
    unsigned unkd0;
    unsigned unkd4;
    unsigned unkd8;
    unsigned unkdc;
    unsigned unke0;
    unsigned unke4;
    unsigned unke8;
    SnapshotB50();
    ~SnapshotB50();
};
struct BaseB50
{
    void UpdateFaceGenHairVisibility(void*, bool);
};
struct FaceB50
{
};
struct ObjectB50
{
};
struct ControllerB50
{
};
struct AnimationB50
{
};
struct PlayerB50
{
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
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual NodeB50* v1ac(bool);
    virtual NodeB50* v1b0(bool);
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual FaceB50* v37c();
    int FUN_0087f4c0();
};
struct DataB50
{
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
    virtual void v048(int);
};
struct HostB50
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    DataB50* data;
    bool RebuildFaceGen(bool);
};
int __cdecl FUN_004564f0(const char*, const char*, unsigned);
// @fnv 0x007b2b50
bool HostB50::RebuildFaceGen(bool rebuild)
{
    int k = 0;
    PtrB50 e(0);
    PtrB50 eb(0);
    StringB50 c, f, cf, q, ba;

    NodeB50* b;

    AnimationB50* j;

    if (!(*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer))->v1ac(false))
        return false;
    data->v048(2048);
    if (rebuild)
    {
        char p[32];
        SnapshotB50 i;
        reinterpret_cast<::RaceAppearance::Race *>(((*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer))->v37c()))->BuildAppearance((::RaceAppearance::NPC *)(::fnv_007b2b50::BaseB50 *)(((::fnv_007b2b50::BaseB50 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer))))->FUN_007af430()))), (::RaceAppearance::Output *)(::fnv_007b2b50::SnapshotB50 *)(&i), (*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer))->FUN_0087f4c0(), false);
        NodeB50* h = (*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer))->v1ac(false);
        NodeB50* cf = (*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer))->v1b0(false);
        for (int i = 0; i < 2; i++)
        {
            NodeB50* part = h->v09c(FixedB50(::BSFaceGenManager::BuildFaceGenPartPath(p, i)));
            if (part)
                h->v0e8(part);
        }
        ::fnv_00655320::BuildHairFaceGenNodes((::fnv_00655320::BSFaceGenNiNode **)(::fnv_007b2b50::NodeB50 **)(&h), (::fnv_00655320::BSFaceGenNiNode **)(::fnv_007b2b50::NodeB50 **)(&cf), (::fnv_00655320::FaceGenData *)(::fnv_007b2b50::SnapshotB50 *)(&i), false);
        j = ((::fnv_007b2b50::AnimationB50 *)(reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer))))->GetAnimation(false)));
        void* a = ((void *)(::fnv_00537bd0::GetStringAtOffset((const char *)(((::fnv_007b2b50::ControllerB50 *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((j))->FUN_00496940()))))));
        if (a)
        {
            ObjectB50* object = ((::fnv_007b2b50::ObjectB50 *)(::FUN_00653270((const ::NiRTTI *)(unsigned int *)(&(*reinterpret_cast<unsigned int *>(&::g_011f4a04))), (::NiObject *)(a))));
            if (object)
                reinterpret_cast<::FUN_00a6e960_shell *>((object))->FUN_00a6e960();
        }
        ((::fnv_007b2b50::BaseB50 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer))))->FUN_007af430()))->UpdateFaceGenHairVisibility((*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer)), false);
        for (int i = 0; i < 2; i++)
        {
            NodeB50* part = h->v09c(FixedB50(::BSFaceGenManager::BuildFaceGenPartPath(p, i)));
            if (part)
            {
                ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(part), 0, 0);
                PropertyB50* color = ((::fnv_007b2b50::PropertyB50 *)(reinterpret_cast<::FUN_00a59d30_C *>((part))->FUN_00a59d30(3)));
                PropertyB50* typed = (!color ? false : ((int)(color->unk1c)) == 8) ? color : 0;
                unsigned property = reinterpret_cast<::FUN_004169d0_shell *>((data))->FUN_004169d0();
                if (typed)
                    typed->color = ColorB50((unsigned char)(property & 255) / 255.0,
                                            (unsigned char)(((unsigned short)property >> 8) & 255) / 255.0,
                                            (unsigned char)((property >> 16) & 255) / 255.0, 1);
                else
                {
                    PropertyB50* otherTyped = (!color ? false : ((int)(color->unk1c)) == 12) ? color : 0;
                    if (otherTyped)
                        otherTyped->color = ColorB50((unsigned char)(property & 255) / 255.0,
                                                     (unsigned char)(((unsigned short)property >> 8) & 255) / 255.0,
                                                     (unsigned char)((property >> 16) & 255) / 255.0, 1);
                }
            }
        }
        reinterpret_cast<::FUN_00a5a040_Class *>((h))->FUN_00a5a040();
    }
    else
    {
        unsigned count = (*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer))->v1ac(false)->FUN_0043b480();
        for (unsigned i = 0; i < count; i++)
        {
            b = ((::fnv_007b2b50::NodeB50 *)(reinterpret_cast<::NiNode *>(((*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer))->v1ac(false)))->GetAt(i)));
            bool hair = b && !FUN_004564f0((*(::fnv_007b2b50::FixedB50 *)(reinterpret_cast<::TESTopicInfoData *>((b))->GetLinkToList())), "FaceGenHair", ::FUN_0044a670("FaceGenHair"));
            bool accessory =
                !hair && b && !FUN_004564f0((*(::fnv_007b2b50::FixedB50 *)(reinterpret_cast<::TESTopicInfoData *>((b))->GetLinkToList())), "FaceGenAccessory", ::FUN_0044a670("FaceGenAccessory"));
            if (hair || accessory)
            {
                eb = b->v01c();
                if ((NodeB50*)eb)
                {
                    if (hair)
                        ::fnv_00653470::FUN_00653470((::fnv_00653470::NiGeometry *)(::fnv_007b2b50::NodeB50 *)(eb), reinterpret_cast<::FUN_00602130_shell *>((data))->FUN_00602130());
                    PropertyB50* color = ((::fnv_007b2b50::PropertyB50 *)(reinterpret_cast<::FUN_00a59d30_C *>((((NodeB50*)eb)))->FUN_00a59d30(3)));
                    PropertyB50* typed = (!color ? false : ((int)(color->unk1c)) == 8) ? color : 0;
                    if (typed)
                    {
                        unsigned property = reinterpret_cast<::FUN_004169d0_shell *>((data))->FUN_004169d0();
                        typed->color = ColorB50((unsigned char)(property & 255) / 255.0,
                                                (unsigned char)(((unsigned short)property >> 8) & 255) / 255.0,
                                                (unsigned char)((property >> 16) & 255) / 255.0, 1);
                    }
                    else
                    {
                        PropertyB50* otherTyped = (!color ? false : ((int)(color->unk1c)) == 12) ? color : 0;
                        if (otherTyped)
                        {
                            unsigned property = reinterpret_cast<::FUN_004169d0_shell *>((data))->FUN_004169d0();
                            otherTyped->color = ColorB50((unsigned char)(property & 255) / 255.0,
                                                         (unsigned char)(((unsigned short)property >> 8) & 255) / 255.0,
                                                         (unsigned char)((property >> 16) & 255) / 255.0, 1);
                        }
                    }
                }
            }
        }
    }
    PointB50 l(0, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((*reinterpret_cast<::fnv_007b2b50::PlayerB50 * *>(&::_g_thePlayer))->v1ac(false)))->FUN_00a59c60((std::intptr_t)&(l));
    reinterpret_cast<::FUN_007b1ae0_shell *>(this)->UpdateShadowSceneNode();
    return true;
}
}  // namespace fnv_007b2b50

struct Trait
{
    void FUN_00a0a270(float value, unsigned int update);
};
struct TileFor3760
{
};
struct MenuOptionFor3760
{
    TileFor3760* tile;
    bool FUN_007b3760(int value);
};
// @fnv 0x007b3890
void TileValueAccessor::FUN_007b3890(int aiLow, int aiHigh)
{
    if (m_tile)
    {
        reinterpret_cast<::Tile *>((((Tile_Set_Helper*)m_tile)))->Set(0x1006, aiLow);
        reinterpret_cast<::Tile *>((((Tile_Set_Helper*)m_tile)))->Set(0x1007, aiHigh);
        if (reinterpret_cast<::FUN_007b3740_shell *>(this)->GetFloat1005() < aiLow)
            reinterpret_cast<::MenuOptionFor3760 *>(this)->FUN_007b3760(aiLow);
        if (reinterpret_cast<::FUN_007b3740_shell *>(this)->GetFloat1005() > aiHigh)
            reinterpret_cast<::MenuOptionFor3760 *>(this)->FUN_007b3760(aiHigh);
    }
}
// @fnv 0x007b5180
void FUN_007b5180_shell::CreateMenuOption()
{
    int ilow;
    int ihigh;
    UpdateHairMenuOption();
    m_pCurrentOption = ((::MenuOption2 *)(reinterpret_cast<::fnv_007b4210::FUN_007b4210_shell *>((((MenuOption2*)this->unk30)))->FindByColor(0x18)));
    ((RaceSexMenu_MenuOption*)m_pCurrentOption)->FUN_007b3840(ilow, ihigh);
    reinterpret_cast<::MenuOptionFor3760 *>((((TileValueAccessor*)m_pCurrentOption)))->FUN_007b3760(ilow);
    HandleOptionSelection();
    m_pCurrentOption = 0;
}
// @fnv 0x007afa40
void FUN_007afa40_cls::FUN_007afa40(unsigned int uiPackedValue)
{
    void* cur = ((void *)(::FUN_00559450((int *)(m_40))));
    while (cur != 0)
    {
        void* item = *((void **)(reinterpret_cast<::ListStandIn *>((m_40))->FUN_0057cbe0((int **)(void **)(&cur))));
        switch (((std::intptr_t)(reinterpret_cast<::Callees *>((((FUN_00726070_shell*)item)))->FUN_00726070())))
        {
        case 0x1e:
            reinterpret_cast<::MenuOptionFor3760 *>((((TileValueAccessor*)item)))->FUN_007b3760((unsigned char)(uiPackedValue & 0xff));
            break;
        case 0x1f:
            reinterpret_cast<::MenuOptionFor3760 *>((((TileValueAccessor*)item)))->FUN_007b3760((unsigned char)((((unsigned short)uiPackedValue) >> 8) & 0xff));
            break;
        case 0x20:
            reinterpret_cast<::MenuOptionFor3760 *>((((TileValueAccessor*)item)))->FUN_007b3760((unsigned char)((uiPackedValue >> 16) & 0xff));
            break;
        }
    }
}

// Clamps value between the option's min and max, and if it differs from the current value, updates the tile and its trait, returning true.
// @fnv 0x007b3760
bool MenuOptionFor3760::FUN_007b3760(int value)
{
    if (tile != 0)
    {
        int currentValue = reinterpret_cast<::FUN_007b3740_shell *>(this)->GetFloat1005();
        int fTargetUpperBound, fMinimumInputValue;
        reinterpret_cast<::RaceSexMenu_MenuOption *>(this)->FUN_007b3840(fTargetUpperBound, fMinimumInputValue);
        if (value < fTargetUpperBound)
            value = fTargetUpperBound;
        if (value > fMinimumInputValue)
            value = fMinimumInputValue;
        if (currentValue != value)
        {
            reinterpret_cast<::Tile *>((tile))->Set(0x1005, value);
            Trait* trait = ((struct ::Trait *)(reinterpret_cast<::FUN_00a00f30_shell *>((tile))->FUN_00a00f30(0x1009)));
            if (reinterpret_cast<::FUN_0084e3a0_Class *>((trait))->FUN_0084e3a0() == 0)
                trait->FUN_00a0a270((float)value, 1);
            return true;
        }
    }
    return false;
}


struct OptionValueReader
{
    TGF* m_iWordAt00;
    unsigned int ReadOptionValue();
};

// @fnv 0x007b3900
unsigned int OptionValueReader::ReadOptionValue()
{
    if (m_iWordAt00 != 0)
    {
        float f = reinterpret_cast<::TileListBoxCalls *>((m_iWordAt00))->GetFloat(0x100a);
        return (f <= ::g_01012070) ? 1 : (unsigned int)f;
    }
    else
    {
        return 0;
    }
}

extern "C" const char str_01075b5c[];

struct FUN_0048f200
{
    int unk00;
    int unk04;
    int unk08;
    FUN_0048f200();
    ~FUN_0048f200();
};

struct PropertyObject : Tile_Set_Helper
{
};
struct InterfaceRoot
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
    void* unk78;
};
struct FUN_007b39e0 : FUN_0048f200
{
    int unk0c;
    int unk10;
    PropertyObject* unk14;
    float unk18;
    int unk1c;
    int unk20;
    FUN_007b39e0(int low, intptr_t high);
};
// @fnv 0x007b39e0
FUN_007b39e0::FUN_007b39e0(int low, intptr_t high)
{
    unk10 = 20;
    unk0c = 20;
    unk18 = 0.0f;
    unk1c = 0;
    unk14 = ((::PropertyObject *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((InterfaceRoot*)DAT_011da634)))->FUN_00a1ddb0((::Tile *)(((InterfaceRoot*)DAT_011da634)->unk78), (char *)(str_01075b10), (::Tile *)(0))));
    reinterpret_cast<::Tile *>((unk14))->Set(0x1004, low);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((unk14))->FUN_00a01350(0xfc4, (char *)(high), true);
    reinterpret_cast<::Tile *>((unk14))->Set(0xfaf, 0);
    reinterpret_cast<::Tile *>((unk14))->Set(FUN_00a00940(str_01075b5c, -1), 1);
    reinterpret_cast<::RenderTile *>((unk14))->FUN_00a04640(false);
    unk20 = 0;
}

struct S_007b3af0_Item
{
    virtual ~S_007b3af0_Item();
};
struct S_007b3af0_Base
{
    int unk00;
    ~S_007b3af0_Base();
};
struct FUN_007b3af0 : S_007b3af0_Base
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_007b3af0_Item* m_item;
    ~FUN_007b3af0();
};
struct TempString_007b3bb0
{
    void* unk00;
    void* unk04;
    TempString_007b3bb0();
    ~TempString_007b3bb0();
};
extern const char DAT_01075b28[];
struct SelectedOption_007b3bb0
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int value0c;
    int unk10;
    TGF* pTGF;
};
struct Menu_007b3bb0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    TGF* pTGF;
    intptr_t AddFloatOption(const char* input, SelectedOption_007b3bb0* selected);
};
// RaceSex menu: add a slider option (range [iLow, iHigh], initial value) whose thumb width covers
// fSequenceTimeRatio of the range, at least one step.

class B3CA0Tile
{
  public:
};

class B3CA0SliderOption
{
  public:
    B3CA0Tile* m_pkTile;

};


class B3CA0Menu
{
  public:
    B3CA0SliderOption* FUN_007b3ca0(intptr_t m_uiSoundID, int iParent, int iLow, int iHigh, int iValue, float fSequenceTimeRatio);
};

struct LocalTile
{
    virtual ~LocalTile();
};
struct Date
{
    LocalTile* tile;
    ~Date();
};
struct OptionList
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    Date* selected;
    operator void*() const;
    void FUN_0057c730(Date*&);
    void RemoveOptionById(int id);
};
// Removes the option whose id matches, updates selected, then repositions remaining options using the _top_bound value.
// @fnv 0x007b3dd0
void OptionList::RemoveOptionById(int id)
{
    void* pos = *this;
    while (pos)
    {
        Date* option = ((::Date *)(reinterpret_cast<::ListStandIn *>(this)->FUN_0057cbe0((int **)&(pos))));
        if (((std::intptr_t)(reinterpret_cast<::Callees *>((option))->FUN_00726070())) == id)
        {
            if (selected == option)
            {
                selected = pos ? ((::Date *)(reinterpret_cast<::FUN_006317a0_struct *>(this)->AddEight((intptr_t)(pos)))) : ((::Date *)(reinterpret_cast<::InventoryStackRecord *>(this)->GetPayloadAddress()));
                ::FUN_00706ff0((intptr_t)(selected->tile));
            }
            delete option->tile;
            delete option;
            FUN_0057c730(option);
            break;
        }
    }
    while (pos)
    {
        void* prev = ((void *)((pos ? (void *)(reinterpret_cast<::NiTListItemFields *>(pos)->m_pkPrev) : 0)));
        Date* current = prev ? ((::Date *)(reinterpret_cast<::FUN_006317a0_struct *>(this)->AddEight((intptr_t)(prev)))) : 0;
        Date* before = ((::Date *)(reinterpret_cast<::ListStandIn *>(this)->FUN_0057cbe0((int **)&(pos))));
        reinterpret_cast<::FUN_00a012d0_t *>((before->tile))->FUN_00a012d0(0xfa2,
                          current ? ((double)(reinterpret_cast<::TileListBoxCalls *>((current->tile))->GetFloat(0xfa2))) + ((double)(reinterpret_cast<::TileListBoxCalls *>((current->tile))->GetFloat(0xfb0)))
                                  : ((double)(reinterpret_cast<::TileListBoxCalls *>((((::LocalTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((before->tile))->FUN_0045cd60()))))->GetFloat(FUN_00a00940("_top_bound", -1)))),
                          true);
        reinterpret_cast<::RenderTile *>((before->tile))->FUN_00a04640(false);
    }
}

struct FUN_007b4050_shell
{
    int unknown00, unknown04, unknown08, currentValue, previousValue;
    TGF* control;
    void CopyControlValues(FUN_007b4050_shell* other);
};
// Reads control's float at 0x1004 into other->currentValue and other->control's float at 0x1004 into previousValue.
// @fnv 0x007b4050
void FUN_007b4050_shell::CopyControlValues(FUN_007b4050_shell* other)
{
    previousValue = (unsigned int)reinterpret_cast<::TileListBoxCalls *>((other->control))->GetFloat(0x1004);
    other->currentValue = (unsigned int)reinterpret_cast<::TileListBoxCalls *>((control))->GetFloat(0x1004);
}

struct TileList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct S_007b40d0_Owner : TileList
{
    bool(__cdecl* m1c)(Tile* item);
    void ApplyToAllTiles();
};
// If m1c is set, walks the tile list and calls SetTileValue on items where m1c returns true, otherwise SetSelected.
// @fnv 0x007b40d0
void S_007b40d0_Owner::ApplyToAllTiles()
{
    if (m1c)
    {
        void* pos = ((void *)(::FUN_00559450((int *)this)));
        while (pos)
        {
            Tile* item = ((::Tile *)(reinterpret_cast<::ListStandIn *>(this)->FUN_0057cbe0((int **)&(pos))));
            if (m1c(item))
                ((FUN_007b4140_shell*)item)->SetTileValue();
            else
                ((FUN_007b4180_shell*)item)->SetSelected();
        }
    }
}

struct Item
{
    virtual ~Item();
};

struct NodeT
{
    Item* m_item;
    ~NodeT();
};

struct FUN_007b45b0_shell
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;

    void FUN_007b45b0();
};
// @fnv 0x007af450
void B7AF450RaceMenu::PopulateEyesList()
{
    reinterpret_cast<::FUN_007b45b0_shell *>((m_pkListBox))->FUN_007b45b0();
    for (B7AF450EyesNode* pkIter = ((::B7AF450EyesNode *)&(reinterpret_cast<::NiAVObject *>(((*reinterpret_cast<::B7AF450DataHandler * *>(&::g_dataHandler))))->FUN_0043c490())); pkIter && *((::B7AF450Eyes **)(&reinterpret_cast<::SimpleListNodeView*>(pkIter)->m_item));
         pkIter = ((::B7AF450EyesNode *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070())))
    {
        if (reinterpret_cast<::FUN_005fc4d0_shell *>(((*((::B7AF450Eyes **)(&reinterpret_cast<::SimpleListNodeView*>(pkIter)->m_item)))))->IsFlagSet() && reinterpret_cast<::FUN_005fc5f0_shell *>(((*((::B7AF450Eyes **)(&reinterpret_cast<::SimpleListNodeView*>(pkIter)->m_item)))))->CanBeNPC((::TESNPC *)(m_pkNPC)))
            reinterpret_cast<::TESRegionGrassObject *>((m_pkListBox->AddItem(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)&((*((::B7AF450Eyes **)(&reinterpret_cast<::SimpleListNodeView*>(pkIter)->m_item)))->m_kTexture))->FUN_00408da0())), 0x21)))->AssignLandTexture((::TESLandTexture *)(*((::B7AF450Eyes **)(&reinterpret_cast<::SimpleListNodeView*>(pkIter)->m_item))));
    }
    reinterpret_cast<::S_007b40d0_Owner *>((m_pkListBox))->ApplyToAllTiles();
    reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(1, false);
}
// @fnv 0x007ac700
void* FUN_007ac700_shell::FUN_007ac700(unsigned int flags)
{
    reinterpret_cast<::FUN_007b3af0 *>((((FUN_007b3af0_shell*)this)))->FUN_007b3af0::~FUN_007b3af0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Deletes m_item, clears it to null, then calls FUN_007b45b0.
// @fnv 0x007b3af0
FUN_007b3af0::~FUN_007b3af0()
{
    delete m_item;
    m_item = 0;
    reinterpret_cast<::FUN_007b45b0_shell *>(this)->FUN_007b45b0();
}

// Iterates the list from FUN_00559450, deleting each node's m_item and the node, then calls FUN_004ed900 and clears m_20.
// @fnv 0x007b45b0
void FUN_007b45b0_shell::FUN_007b45b0()
{
    void* it = ((void *)(::FUN_00559450((int *)this)));
    while (it != 0)
    {
        NodeT* node = ((::NodeT *)(reinterpret_cast<::ListStandIn *>(this)->FUN_0057cbe0((int **)&(it))));
        delete node->m_item;
        delete node;
    }
    reinterpret_cast<::NiTPointerListBaseRaw *>(this)->FUN_004ed900();
    m_20 = 0;
}

// Race/sex menu initialization.
class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};
class BSFaceGenNiNode;
class TESNPC : public TESBoundObject
{
  public:
    int FUN_005f0cc0();
public:
    void ResetFaceGen();
public:
    void CopyActorBaseData(::TESNPC *);
public:
    void GetFaceGenNodes(::BSFaceGenNiNode *&, ::BSFaceGenNiNode *&);
};
struct InitPlayer
{
};
struct BSStringTChar
{
    void* data;
    unsigned short length, capacity;
    BSStringTChar();
    ~BSStringTChar();
};
struct InitSetting
{
};
struct InitTile
{
};
struct InitItem
{
};
struct InitOptions
{
    InitItem* FUN_007b3b80(const char*, int);
};
struct InitForm
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    struct Name
    {
    } name;
};
struct InitNode
{
};
struct InitData
{
};

struct InitString
{
};
struct InitSub
{
    int unk00, unk04, unk08;
};
struct InitManager
{
};
struct InitRootManager
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
    InitManager messages;
};

extern const char DAT_01063ab4[];
extern const char DAT_010692d0[];
extern const char DAT_01075ae4[];
extern const char DAT_01075adc[];
extern const char DAT_01075ad4[];
extern const char DAT_01075acc[];
extern const char DAT_01075aac[];
extern const char DAT_01075a74[];
extern const char DAT_01075a4c[];
extern const char DAT_01074e34[];
struct InitRaceMenu
{
    int unk000;
    InitTile* tile;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    FUN_007b39e0* options[20];
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    InitTile* display;
    int unk08c;
    BSStringTChar title;
    BSStringTChar question;
    float valuea0;
    float valuea4;
    float valuea8;
    float valueac;
    float valueb0;
    float valueb4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    float valuec8;
    int unk0cc;
    float valued0;
    int unk0d4;
    TESNPC* npc;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    InitSub sub0;
    InitSub sub1;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    void SetupRaceMenu(int mode);
};
struct Tile7
{
};
struct MenuOption7
{
};
struct OptionList7
{
};
struct IM7
{
};

struct RaceSexMenu7
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
    OptionList7* optionLists[5];
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
    Tile7* tile7c;
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
    float fLastTime;
    int iBase;
    Tile7* pActiveTile;
    MenuOption7* pActiveOption;
    int GetCurrentPage();
    void HandleOptionSelection();
    void FUN_007ae240(int aiID, Tile7* apTile);
};

// @fnv 0x007ae240
void RaceSexMenu7::FUN_007ae240(int aiID, Tile7* apTile)
{
    float fDelta2 = reinterpret_cast<::MyHack *>((((::IM7 *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007697f0() - fLastTime;
    if (fDelta2 != 0.0)
    {
        if (aiID == 0x69 && apTile)
        {
            int iPage = GetCurrentPage();
            MenuOption7* pOption = ((::MenuOption7 *)(reinterpret_cast<::S *>((optionLists[iPage]))->FUN_007b41c0((intptr_t)(((::Tile7 *)(reinterpret_cast<::FUN_0045cd60_shell *>((apTile))->FUN_0045cd60()))))));
            if (pOption)
            {
                int iLow6;
                int iHigh;
                reinterpret_cast<::RaceSexMenu_MenuOption *>((pOption))->FUN_007b3840(iLow6, iHigh);
                float fRatio = fDelta2 / reinterpret_cast<::TileListBoxCalls *>((((::Tile7 *)(reinterpret_cast<::TileFloatList *>((((::Tile7 *)(reinterpret_cast<::FUN_0045cd60_shell *>((apTile))->FUN_0045cd60()))))->FUN_00a03eb0(0x65)))))->GetFloat(0xfb1);
                if (reinterpret_cast<::MenuOptionFor3760 *>((pOption))->FUN_007b3760(::InventoryStackRecord::RoundToNearestStep(iBase + (iHigh - iLow6) * fRatio, 1.0f)))
                {
                    pActiveOption = pOption;
                    pActiveTile = apTile;
                    HandleOptionSelection();
                }
            }
        }
        else if (aiID == 1)
        {
            static float sfWidth = reinterpret_cast<::TileListBoxCalls *>((tile7c))->GetFloat(0xfb1);
            reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(5, reinterpret_cast<::Target *>(this)->FUN_007b1970(fDelta2 / sfWidth * 6.2831854820251465, 0));
            fLastTime = reinterpret_cast<::MyHack *>((((::IM7 *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007697f0();
        }
    }
}

namespace AppearanceInput {
struct Sound
{
    unsigned int unk0, unk4, unk8;
};
struct Input
{
};
struct OS
{
};
struct Interface
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    void* selected;
};
bool FUN_00702450(int);
int FUN_0072fa60(int);
extern int DAT_011a07b0, DAT_011a07ac;
extern double DAT_01075af8, DAT_01075af0;
extern float DAT_01075aec;
struct Menu
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void Select(int, int);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual int Id();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    void* zoomTile;
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
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    int dragX, dragY;
    float desired, velocity, current;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    Sound sounds[4];
    bool UpdateProgress(float, int);
    void HandleOptionSelection();
    void HandlePendingTileAction();
    void UpdateZoomAndScroll();
};
// Per frame, while the menu is active, drives zoom/scroll velocity from input and plays or stops the four sounds based on state.
// @fnv 0x007ae420
void Menu::UpdateZoomAndScroll()
{
    if (FUN_00702450(Id()))
    {
        for (unsigned int i = 0; i < 4; i++)
            if (((std::intptr_t)(sounds[i].unk8)) == 3)
                reinterpret_cast<::FUN_00ad8830_shell *>(&(sounds[i]))->FUN_00ad8830(0);
        static unsigned int previous = ((unsigned int)(::FUN_00457fe0()));
        unsigned int time = ((unsigned int)(::FUN_00457fe0()));
        if (::FUN_004b71d0())
        {
            int horizontalSlot1 = 0;
            int verticalSlot17 = 0;
            horizontalSlot1 = reinterpret_cast<::FUN_00a23390_t *>((((::AppearanceInput::Input *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::AppearanceInput::OS * *>(&::g_osGlobals))))->FUN_00877720()))))->GetAxisState(0, 9);
            verticalSlot17 = reinterpret_cast<::FUN_00a23390_t *>((((::AppearanceInput::Input *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::AppearanceInput::OS * *>(&::g_osGlobals))))->FUN_00877720()))))->GetAxisState(0, 10);
            int absXSlot10 = FUN_0072fa60(horizontalSlot1);
            int absYSlot39 = FUN_0072fa60(verticalSlot17);
            reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(5, 0);
            reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(6, 0);
            if (absYSlot39 > 8689 && absYSlot39 > absXSlot10)
            {
                int span = DAT_011a07b0 - 8689;
                int amountSlot0 = span - (DAT_011a07b0 - ::MinInt(absYSlot39, DAT_011a07b0));
                velocity += amountSlot0 * DAT_01075af8 / span * (time - previous);
                reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(
                    6, UpdateProgress((verticalSlot17 > ::_DAT_01012060 ? -1 : 1) * velocity * (time - previous), 0));
            }
            else
            {
                if (absXSlot10 > 8689 && absXSlot10 > absYSlot39)
                {
                    float ratio = horizontalSlot1 > 0 ? (float)(horizontalSlot1 - 8689) / (DAT_011a07b0 - 8689)
                                                      : (float)(-horizontalSlot1 - 8689) / (DAT_011a07ac + 8689);
                    reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(5, reinterpret_cast<::Target *>(this)->FUN_007b1970(ratio * DAT_01075af0 * (time - previous) / ::DAT_01017b70, 0));
                }
                velocity = 0.0f;
            }
            if (reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(5) && !reinterpret_cast<::SoundPlaybackHandle *>(&(sounds[3]))->IsPlaying())
                reinterpret_cast<::FUN_00ad8830_shell *>(&(sounds[3]))->FUN_00ad8830(0);
            else if (!reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(5) && reinterpret_cast<::SoundPlaybackHandle *>(&(sounds[3]))->IsPlaying())
                reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(sounds[3]))->FUN_00ad88f0();
            if (reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(6) && !reinterpret_cast<::SoundPlaybackHandle *>(&(sounds[2]))->IsPlaying())
                reinterpret_cast<::FUN_00ad8830_shell *>(&(sounds[2]))->FUN_00ad8830(0);
            else if (!reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(6) && reinterpret_cast<::SoundPlaybackHandle *>(&(sounds[2]))->IsPlaying())
                reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(sounds[2]))->FUN_00ad88f0();
            if (dragY && reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(4))
            {
                HandleOptionSelection();
                dragY = 0;
                dragX = 0;
            }
        }
        else
        {
            reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(6, 0);
            if (((int)(reinterpret_cast<::FUN_0070ec70_class *>((((::AppearanceInput::Interface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0070ec70())) && ((::AppearanceInput::Interface *)(::fnv_004b7210::FUN_004b7210()))->selected)
            {
                bool up = ((int)(reinterpret_cast<::FUN_0070ec70_class *>((((::AppearanceInput::Interface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0070ec70())) > ::_DAT_01012060;
                if (((::AppearanceInput::Interface *)(::fnv_004b7210::FUN_004b7210()))->selected == zoomTile)
                {
                    desired += up ? DAT_01075aec : ::g_x;
                    desired = ::FUN_00404010(::FUN_0040ebd0(desired, 1.0f), 0.0f);
                }
                else
                {
                    if (up)
                        Select(2, 0);
                    else
                        Select(3, 0);
                }
            }
            if (current < desired)
            {
                velocity += (time - previous) * DAT_01075af8;
                float increase = (time - previous) * velocity;
                if (desired < current + increase)
                    increase = desired - current;
                reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(6, UpdateProgress(increase, 0));
            }
            else if (current > desired)
            {
                velocity -= (time - previous) * DAT_01075af8;
                float decrease = (time - previous) * velocity;
                if (desired > current + decrease)
                    decrease = desired - current;
                reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(6, UpdateProgress(decrease, 0));
            }
            else
                velocity = 0.0f;
            if (reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(6) && !reinterpret_cast<::SoundPlaybackHandle *>(&(sounds[2]))->IsPlaying())
                reinterpret_cast<::FUN_00ad8830_shell *>(&(sounds[2]))->FUN_00ad8830(0);
            else if (!reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(6) && reinterpret_cast<::SoundPlaybackHandle *>(&(sounds[2]))->IsPlaying())
                reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(sounds[2]))->FUN_00ad88f0();
            if (reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(5) && !reinterpret_cast<::SoundPlaybackHandle *>(&(sounds[3]))->IsPlaying())
                reinterpret_cast<::FUN_00ad8830_shell *>(&(sounds[3]))->FUN_00ad8830(0);
            else if (!reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(5) && reinterpret_cast<::SoundPlaybackHandle *>(&(sounds[3]))->IsPlaying())
                reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(sounds[3]))->FUN_00ad88f0();
            reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(5, 0);
            if (dragY && ((::AppearanceInput::Input *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::AppearanceInput::OS * *>(&::g_osGlobals))))->FUN_00877720())) && reinterpret_cast<::ButtonDevice *>((((::AppearanceInput::Input *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::AppearanceInput::OS * *>(&::g_osGlobals))))->FUN_00877720()))))->FUN_00a23a50(0, 2))
                HandlePendingTileAction();
        }
        previous = time;
    }
    else
    {
        for (unsigned int j = 0; j < 4; j++)
            if (((std::intptr_t)(sounds[j].unk8)) == 1)
                reinterpret_cast<::FUN_00ad88b0_h *>(&(sounds[j]))->FUN_00ad88b0();
    }
}
}

struct Tile67
{
};
struct Option67
{
};
struct Sound67
{
    int unk00, unk04, unk08;
    ~Sound67();
};
struct Audio67
{
    Sound67 FUN_00ad7550(const char*, int, int);
};
struct Value67
{
};
struct Input67
{
};
struct Interface67
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
    struct Tile67* unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    Tile67* focused;
};
struct Setting67
{
};
struct String67
{
};
extern char DAT_0106f380[], DAT_01075b00[];
bool FUN_00702450(int);
int FUN_0072fa60(int);
void UpdateRaceSexMenu();
struct Menu67
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Activate(int, Tile67*);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int Id();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Option67* options[20];
    Tile67* parent;
    int unk7c, unk80, unk84;
    Tile67* left;
    Tile67* right;
    int unk90, unk94;
    String67 message;
    int FUN_007dcc00();
    bool HandleAction(int, int);
};
struct StatsMenuItem
{
};
struct StatsMenuItemList
{
};
struct StatsMenuTile
{
};
class StatsMenu
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    StatsMenuItemList* m_pageLists[2];
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    StatsMenuTile* m_minusTile;
    StatsMenuTile* m_plusTile;
    int FUN_007dcc00();
    void UpdateMinusPlusTiles();
};
// @fnv 0x007af180
bool FUN_007af180_shell::FUN_007af180(intptr_t aeList)
{
    if (aeList < 20)
    {
        reinterpret_cast<::Tile *>(((*(Tile_Set_Helper**)&this->unk04)))->Set(0x1004, aeList);
        reinterpret_cast<::ModListOwner *>((((OptList**)&this->unk28)[aeList]))->FUN_007b4410();
        if (aeList == 5 && FUN_007adc30(0))
            reinterpret_cast<::HairMenu *>(this)->PopulateHairOptions();
        else if (aeList == 8 && FUN_007adc30(1))
            reinterpret_cast<::B7AF450RaceMenu *>(this)->PopulateEyesList();
        else if (aeList == 3)
            reinterpret_cast<::FUN_007af520_cls *>(this)->SyncListItemTemplate();
        reinterpret_cast<::StatsMenu *>(this)->UpdateMinusPlusTiles();
        if (((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->GetActiveRenderedMenu() && aeList < 4)
            reinterpret_cast<::MenuDriver *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->GetActiveRenderedMenu()))->UpdateSlotSelection(aeList);
        reinterpret_cast<::Tile *>(((*(Tile_Set_Helper**)&this->unk88)))->Set(0xfa3, reinterpret_cast<::FUN_0084e3a0_Class *>((((OptList**)&this->unk28)[aeList]))->FUN_0084e3a0() < 20);
        reinterpret_cast<::Tile *>(((*(Tile_Set_Helper**)&this->unk8c)))->Set(0xfa3, ((std::intptr_t)(reinterpret_cast<::MagicCaster_shell *>((((BSAudio**)&this->unk28)[aeList]))->FUN_0044edb0())) < 20 ||
                             aeList == this->unk120);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*(TileHelper**)&this->unk8c)))->FUN_00a01350(0xfc4, (char *)((const char*)(uintptr_t)(aeList == this->unk120 ? (*reinterpret_cast<::Flt *>(&::g_011da70c)) : (*reinterpret_cast<::Flt *>(&::g_011da700)))),
                  true);
        return true;
    }
    else
        return false;
}
// Scans the current page's items for entries returning -1 or 1 and toggles the minus and plus tiles accordingly.
// @fnv 0x007af6b0
void StatsMenu::UpdateMinusPlusTiles()
{
    StatsMenuItem* pos;
    StatsMenuItemList* pOwner = m_pageLists[FUN_007dcc00()];
    pos = ((::StatsMenuItem *)(::FUN_00559450((int *)(pOwner))));
    bool foundPlus;
    {
        bool foundMinus = false;
        foundPlus = false;
        ::fnv_00a04200::FUN_00a04200(0);
        while (pos && (!foundMinus || !foundPlus))
        {
            switch (reinterpret_cast<::S007b39b0 *>(((*((::StatsMenuItem **)(reinterpret_cast<::ListStandIn *>((pOwner))->FUN_0057cbe0((int **)&(pos)))))))->GetPosition())
            {
            case -1:
                foundMinus = true;
                break;
            case 1:
                foundPlus = true;
                break;
            }
        }
        reinterpret_cast<::Tile *>((m_minusTile))->Set(0xFA3, foundMinus);
        reinterpret_cast<::Tile *>((m_plusTile))->Set(0xFA3, foundPlus);
    }
}

struct B10355_Elem
{
    B10355_Elem();
    ~B10355_Elem();
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
};

struct B10355_Obj2
{
};

struct B10355_Node
{
    void* unk00;
    struct B10355_Obj2* unk04;
};

struct B10355_Holder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    B10355_Node m10c;
    void U1(void* p);
    intptr_t U3();
};

struct B10355_Param
{
};


struct FUN_007af770_cls
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    B10355_Holder* m_d8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    int unk124;
    void ApplyParam(B10355_Param* p);
};

// @fnv 0x007af770
void FUN_007af770_cls::ApplyParam(B10355_Param* apParam)
{
    B10355_Elem arr[4];
    m_d8->U1(arr);
    float F = reinterpret_cast<::FUN_007b3740_shell *>((apParam))->GetFloat1005() / 10.0;
    ::FUN_00652320((::FG652_Mat *)(arr), ((int)(reinterpret_cast<::RaceSexOptionFields *>((apParam))->id)) != 0x22, 0, ((int)(reinterpret_cast<::RaceSexOptionFields *>((apParam))->value)), F);
    m_d8->U1((void*)&unk124);
    ::FUN_00652e00((MatrixProxy (*)[2])(((std::intptr_t)(reinterpret_cast<::S9fb0 *>((m_d8->m10c.unk04))->FUN_005d9fb0({})))), (MatrixProxy (*)[2])(m_d8->U3()), (MatrixProxy (*)[2])(arr), ((std::intptr_t)(reinterpret_cast<::FUN_00601800_shell *>((m_d8))->FUN_00601800())));
    reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(8, true);
    if (((std::intptr_t)(reinterpret_cast<::RaceSexOptionFields *>((apParam))->id)) == 0x23)
    {
        reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(9, true);
    }
}

struct FaceMorphDescriptor
{
    int group;
    const char* name;
    float minimum, maximum;
};
struct MorphSetting
{
};
struct MorphData
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    MorphData();
    ~MorphData();
};
struct MorphRace
{
};
struct MorphRaceLink
{
};
struct FaceActor
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
    MorphRaceLink race;
    int FUN_005f0cc0();
};
struct MorphMenuOption
{
};
struct MorphMenuList
{
};
struct FaceMorphMenu
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
    MorphMenuList* lists[20];
    unsigned int unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unkA0, unkA4, unkA8, unkAc,
        unkB0, unkB4, unkB8, unkBc, unkC0, unkC4, unkC8, unkCc, unkD0, unkD4;
    FaceActor* actor;
    void BuildMorphOptions();
};
struct SliderOption : MenuOptionFor3760
{
};
struct FUN_00449610
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_00449610();
    ~FUN_00449610();
};
struct SliderName
{
};
struct SliderNameRef
{
};
struct SliderActor
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108;
    SliderNameRef name;
    int FUN_005f0cc0();
};
struct SliderMenu
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    FUN_007afa40_mgr* optionLists[39];
    SliderOption* selected;
    int unkc8, unkcc, unkd0, unkd4;
    SliderActor* actor;
    bool ClampSliderOptions(int iFrom, int iTo, int bForward);
};
// @fnv 0x007b18f0
void B7B18F0Menu::HandleMenuKey(int iKey)
{
    bool bOk = false;
    unsigned int uiCounter = 0;
    if (iKey == 0x22)
    {
        do
        {
            bOk = reinterpret_cast<::SliderMenu *>(this)->ClampSliderOptions(10, 0x13, false);
        } while (bOk && uiCounter++ < 3);
    }
    else if (iKey == 0x23)
    {
        do
        {
            bOk = reinterpret_cast<::SliderMenu *>(this)->ClampSliderOptions(0x13, 0x14, true);
        } while (bOk && uiCounter++ < 3);
    }
}
// @fnv 0x007b16d0
bool SliderMenu::ClampSliderOptions(int iStartIndex, int iEndIndex, int bForward)
{
    bool changed = false;
    for (int i = iStartIndex; i < iEndIndex; i++)
    {
        void* position = ((void *)(::FUN_00559450((int *)(optionLists[i]))));
        while (position)
        {
            SliderOption* option = (SliderOption*)*((void **)(reinterpret_cast<::ListStandIn *>((optionLists[i]))->FUN_0057cbe0((int **)(void **)(&position))));
            if (option && (((std::intptr_t)(reinterpret_cast<::Callees *>((option))->FUN_00726070())) == 0x22 || ((std::intptr_t)(reinterpret_cast<::Callees *>((option))->FUN_00726070())) == 0x23))
            {
                FUN_00449610 values[4];
                ::FUN_00652af0((CoordArray (*)[2])(reinterpret_cast<::S9fb0 *>((((::SliderName *)(reinterpret_cast<::Callees *>(&(actor->name))->FUN_00726070()))))->FUN_005d9fb0(actor->FUN_005f0cc0())), (CoordArray (*)[2])(void *)(reinterpret_cast<::FUN_00601800_shell *>((actor))->FUN_00601800()),
                             (CoordArray (*)[2])(values), 0, 0.0f);
                {
                    int low, high;
                    {
                        int value = (int)(::GetMorphCoordinateValue((char *)(values), bForward, 0, ((int)(reinterpret_cast<::RaceSexOptionFields *>((option))->value))) * 10.0);
                        reinterpret_cast<::RaceSexMenu_MenuOption *>((option))->FUN_007b3840(low, high);
                        if (value < low)
                        {
                            option->FUN_007b3760(low);
                            changed = true;
                        }
                        else if (value > high)
                        {
                            option->FUN_007b3760(high);
                            changed = true;
                        }
                        else if (option != selected)
                        {
                            option->FUN_007b3760(value);
                        }
                    }
                }
            }
        }
    }
    return changed;
}


struct PlayerStandIn
{
};

struct PosTarget
{
};

struct PosTargetPtr
{
    PosTarget* m_pObject;
    operator PosTarget*() const;
};

struct RaceSexMenuCamera
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
    float fStartX;
    float fStartY;
    float fStartZ;
    float fEndX;
    float fEndY;
    float fEndZ;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    float fProgress;
    PosTargetPtr m_spTargetObject;

    bool UpdateProgress(float afDelta, bool abForce);
};

// Advances fProgress by afDelta clamped to [0,1]; if it changed or abForce, interpolates the start/end position, applies it, and returns true.
// @fnv 0x007b1b60
bool RaceSexMenuCamera::UpdateProgress(float afDelta, bool abForce)
{
    float fOldProgress = fProgress;
    fProgress = FUN_00404010(0.0f, FUN_0040ebd0(1.0f, fProgress + afDelta));
    if (fOldProgress == fProgress && !abForce)
        return false;
    reinterpret_cast<::FUN_004bc1f0_S *>((((PosTarget*)m_spTargetObject)))->FUN_004bc1f0((fEndX - fStartX) * fProgress + fStartX, (fEndY - fStartY) * fProgress + fStartY,
                       reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((void *)(((PlayerStandIn*)(*reinterpret_cast<::PC_00605d70 * *>(&::_g_thePlayer)))))->GetActorHeight() * ((fEndZ - fStartZ) * fProgress + fStartZ));
    reinterpret_cast<::FUN_007b1ae0_shell *>(this)->UpdateShadowSceneNode();
    return true;
}

struct AppearanceObject
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual AppearanceObject* AsNode();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual AppearanceObject* AsGeometry();
    unsigned int FUN_0043b480();

};
struct FaceModel
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
    virtual FaceModel* AsFaceModel();
};
struct SkinObject
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
    virtual void Remove(AppearanceObject*);
};
struct SkinRoot : AppearanceObject
{
};
struct AppearanceProcess
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
    virtual void Refresh();
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
    virtual void slot488();
    virtual void slot48c();
    virtual void slot490();
    virtual void slot494();
    virtual void slot498();
    virtual void slot49c();
    virtual void slot4a0();
    virtual void slot4a4();
    virtual void slot4a8();
    virtual void slot4ac();
    virtual void slot4b0();
    virtual void slot4b4();
    virtual void slot4b8();
    virtual void slot4bc();
    virtual void slot4c0();
    virtual void slot4c4();
    virtual void slot4c8();
    virtual void slot4cc();
    virtual void slot4d0();
    virtual void slot4d4();
    virtual void slot4d8();
    virtual void slot4dc();
    virtual void slot4e0();
    virtual void slot4e4();
    virtual void slot4e8();
    virtual void slot4ec();
    virtual void slot4f0();
    virtual void slot4f4();
    virtual void slot4f8();
    virtual void slot4fc();
    virtual void slot500();
    virtual void slot504();
    virtual void slot508();
    virtual void slot50c();
    virtual void slot510();
    virtual void slot514();
    virtual void slot518();
    virtual void slot51c();
    virtual void slot520();
    virtual void slot524();
    virtual void slot528();
    virtual void slot52c();
    virtual void slot530();
    virtual void slot534();
    virtual void slot538();
    virtual void slot53c();
    virtual void slot540();
    virtual void slot544();
    virtual void slot548();
    virtual void slot54c();
    virtual void slot550();
    virtual void slot554();
    virtual void slot558();
    virtual void slot55c();
    virtual void slot560();
    virtual void slot564();
    virtual void slot568();
    virtual void slot56c();
    virtual void slot570();
    virtual void slot574();
    virtual void slot578();
    virtual void slot57c();
    virtual void slot580();
    virtual void slot584();
    virtual void slot588();
    virtual void slot58c();
    virtual void slot590();
    virtual void slot594();
    virtual void slot598();
    virtual void slot59c();
    virtual void slot5a0();
    virtual void slot5a4();
    virtual void slot5a8();
    virtual void slot5ac();
    virtual void slot5b0();
    virtual void slot5b4();
    virtual void slot5b8();
    virtual void slot5bc();
    virtual void slot5c0();
    virtual void slot5c4();
    virtual void slot5c8();
    virtual void slot5cc();
    virtual void slot5d0();
    virtual void slot5d4();
    virtual void slot5d8();
    virtual void slot5dc();
    virtual void slot5e0();
    virtual void slot5e4();
    virtual void slot5e8();
    virtual void slot5ec();
    virtual void slot5f0();
    virtual void slot5f4();
    virtual void slot5f8();
    virtual void slot5fc();
    virtual void slot600();
    virtual void slot604();
    virtual void slot608();
    virtual void slot60c();
    virtual void slot610();
    virtual void slot614();
    virtual void slot618();
    virtual void slot61c();
    virtual void slot620();
    virtual void slot624();
    virtual void slot628();
    virtual void slot62c();
    virtual void slot630();
    virtual void slot634();
    virtual void slot638();
    virtual void slot63c();
    virtual void slot640();
    virtual void slot644();
    virtual void slot648();
    virtual void slot64c();
    virtual void slot650();
    virtual void slot654();
    virtual void slot658();
    virtual void slot65c();
    virtual void slot660();
    virtual void slot664();
    virtual void slot668();
    virtual void slot66c();
    virtual void slot670();
    virtual void slot674();
    virtual void slot678();
    virtual void slot67c();
    virtual void slot680();
    virtual void slot684();
    virtual void slot688();
    virtual void slot68c();
    virtual void slot690();
    virtual void slot694();
    virtual void slot698();
    virtual void slot69c();
    virtual void slot6a0();
    virtual void slot6a4();
    virtual void slot6a8();
    virtual void slot6ac();
    virtual void slot6b0();
    virtual void slot6b4();
    virtual void slot6b8();
    virtual void slot6bc();
    virtual void slot6c0();
    virtual void slot6c4();
    virtual void slot6c8();
    virtual void slot6cc();
    virtual void slot6d0();
    virtual void slot6d4();
    virtual void slot6d8();
    virtual void slot6dc();
    virtual void slot6e0();
    virtual void slot6e4();
    virtual void slot6e8();
    virtual void slot6ec();
    virtual void slot6f0();
    virtual void slot6f4();
    virtual void slot6f8();
    virtual void slot6fc();
    virtual void slot700();
    virtual void slot704();
    virtual void slot708();
    virtual void slot70c();
    virtual void slot710();
    virtual void slot714();
    virtual void slot718();
    virtual void slot71c();
    virtual void slot720();
    virtual void slot724();
    virtual void slot728();
    virtual void slot72c();
    virtual void slot730();
    virtual void slot734();
    virtual void slot738();
    virtual void slot73c();
    virtual void slot740();
    virtual void slot744();
    virtual void slot748();
    virtual void slot74c();
    virtual void slot750();
    virtual void slot754();
    virtual void slot758();
    virtual void slot75c();
    virtual void slot760();
    virtual void slot764();
    virtual void slot768();
    virtual void slot76c();
    virtual void slot770();
    virtual void slot774();
    virtual void slot778();
    virtual void slot77c();
    virtual void slot780();
    virtual void slot784();
    virtual void slot788();
    virtual void slot78c();
    virtual void slot790();
    virtual void ResetA(int);
    virtual void slot798();
    virtual void ResetB(int);
    virtual void slot7a0();
    virtual void ResetC(int);
};
struct AppearancePlayer
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
    virtual SkinRoot* RootA(int);
    virtual SkinRoot* RootB(int);
    AppearanceObject* GetNode(bool);
};
struct AppearanceNPC
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
    virtual void SetFlags(int);
    void FUN_00603ad0(void*);
};
struct ShaderProperty
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
    virtual void SetTexture(int, void*);
};
struct AppearanceAnimation
{
};
struct AppearanceManager
{
};
struct AppearanceName
{
    operator const char*() const;
};
struct FaceCoordinate
{
    int a, b, c, d, e, f, g, h;
    FaceCoordinate();
    ~FaceCoordinate();
};
struct TexturePointer
{
    void* texture;
    TexturePointer(void*);
    ~TexturePointer();
    operator void*();
};
int __cdecl _mbsnicmp(const char*, const char*, unsigned int);
struct AppearanceMenu
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
    int unk0cc;
    int unk0d0;
    int unk0d4;
    AppearanceNPC* npc;
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
    int faceData;
    void UpdateFaceGen(bool remove, bool shape, bool texture);
};
// @fnv 0x007b1e70
void AppearanceMenu::UpdateFaceGen(bool remove, bool shape, bool texture)
{
    if (!(*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))->RootA(0) || !(*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))->RootB(0))
        return;
    npc->SetFlags(0x800);
    if (remove)
    {
        AppearanceObject* second = ((::AppearanceObject *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))))->FUN_00950bb0(false)));
        AppearanceObject* root = second ? second->AsNode() : 0;
        if (root)
        {
            void* manager = 0;
            if (((::AppearanceAnimation *)(reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))))->GetAnimation(false))) && ((::AppearanceManager *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((((::AppearanceAnimation *)(reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))))->GetAnimation(false)))))->FUN_00496940())))
                manager = ((void *)(::fnv_00537bd0::GetStringAtOffset((const char *)(((::AppearanceManager *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((((::AppearanceAnimation *)(reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))))->GetAnimation(false)))))->FUN_00496940()))))));
            SkinRoot* controller;
            void* skin = manager;
            controller = (*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))->RootB(0);
            if (controller && ((::SkinObject *)(reinterpret_cast<::NiAVObjectFields *>((controller))->m_pkParent)))
            {
                ::FUN_00a6e8e0((::S_00a6e8e0_Object *)(controller), (::S_00a6e8e0_Palette *)(skin));
                ((::AppearanceProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))))->GetBaseTexture()))->ResetB(0);
                ((::SkinObject *)(reinterpret_cast<::NiAVObjectFields *>((controller))->m_pkParent))->Remove(controller);
            }
            controller = (*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))->RootA(0);
            if (controller && ((::SkinObject *)(reinterpret_cast<::NiAVObjectFields *>((controller))->m_pkParent)))
            {
                ::FUN_00a6e8e0((::S_00a6e8e0_Object *)(controller), (::S_00a6e8e0_Palette *)(skin));
                ((::AppearanceProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))))->GetBaseTexture()))->ResetA(0);
                ((::AppearanceProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))))->GetBaseTexture()))->ResetC(0);
                ((::SkinObject *)(reinterpret_cast<::NiAVObjectFields *>((controller))->m_pkParent))->Remove(controller);
            }
        }
        if (((::AppearanceProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))))->GetBaseTexture())))
            ((::AppearanceProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))))->GetBaseTexture()))->Refresh();
        reinterpret_cast<::TESNPC *>((npc))->ResetFaceGen();
        intptr_t first = 0;
        intptr_t node = first;
        reinterpret_cast<::TESNPC *>((npc))->GetFaceGenNodes((*(::BSFaceGenNiNode * *)(&node)), (*(::BSFaceGenNiNode * *)(&first)));
        reinterpret_cast<::TESNPC_Sub *>((npc))->AttachHeadModels((::TESObjectREFR *)((*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))), (::BipedAnim *)(void *)(((void *)(reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))))->FUN_00950b00(false)))), (::BSFaceGenNiNode *)(node), (::BSFaceGenNiNode *)(first));
    }
    else
    {
        FaceCoordinate coordinates[4];
        FaceCoordinate modified[4];
        npc->FUN_00603ad0(coordinates);
        if (shape)
            ::FUN_00652e00((MatrixProxy (*)[2])(void *)(&faceData), (MatrixProxy (*)[2])(coordinates), (MatrixProxy (*)[2])(modified), 0);
        SkinRoot* controller = (*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))->RootA(0);
        for (int pass = 0; pass < 2; pass++)
        {
            if (shape)
                reinterpret_cast<::FUN_007b2550_shell *>((controller))->SetByteAtOffsetE4(1);
            unsigned int count = controller->FUN_0043b480();
            for (unsigned int index = 0; index < count; index++)
            {
                AppearanceObject* geometry = ((::AppearanceObject *)(reinterpret_cast<::NiNode *>((controller))->GetAt(index)));
                AppearanceObject* model = geometry ? geometry->AsGeometry() : 0;
                if (!model)
                    continue;
                FaceModel* extra = ((::FaceModel *)(::GetGeomExtraData((::NiTriBasedGeom *)(model))));
                FaceModel* object = extra ? extra->AsFaceModel() : 0;
                if (!object)
                    continue;
                if (shape)
                    reinterpret_cast<::FUN_0065a970_shell *>((object))->ApplyMorphs((::FaceGenCoordinate *)(modified), (::NiTriBasedGeom *)(model), 0);
                if (texture && !_mbsnicmp((*(::AppearanceName *)(reinterpret_cast<::TESTopicInfoData *>((model))->GetLinkToList())), "FaceGenFace", strlen("FaceGenFace")))
                {
                    ShaderProperty* generated;
                    {
                        ShaderProperty* property = ((::ShaderProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((geometry))->FUN_00a59d30(3)));
                        generated =
                            (!property ? 0 : (((int)(reinterpret_cast<::BGSTerrainManager *>((property))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((property))->GetMinLevel())) <= 12 ? 1 : 0))
                                ? property
                                : 0;
                    }
                    if (!generated)
                        continue;
                    TexturePointer pkTexture(0);
                    if (!((unsigned char)(reinterpret_cast<::FUN_007b2570_shell *>((object))->FUN_007b2570())))
                        reinterpret_cast<::FUN_0065a840_t *>((object))->FUN_0065a840();
                    reinterpret_cast<::BSFaceGenModel *>((object))->ApplyTextureCoordinate((::FaceGenCoordinates *)(coordinates), (::NiPointer< ::NiTexture> &)(pkTexture), ((unsigned int)(::FUN_006151d0())));
                    generated->SetTexture(1, pkTexture);
                }
            }
            controller = (*reinterpret_cast<::AppearancePlayer * *>(&::_g_thePlayer))->RootB(0);
        }
    }
    reinterpret_cast<::FUN_007b1ae0_shell *>(this)->UpdateShadowSceneNode();
}

class Player511;
class Process511
{
  public:
    virtual void Virtual000();
    virtual void Virtual004();
    virtual void Virtual008();
    virtual void Virtual00c();
    virtual void Virtual010();
    virtual void Virtual014();
    virtual void Virtual018();
    virtual void Virtual01c();
    virtual void Virtual020();
    virtual void Virtual024();
    virtual void Virtual028();
    virtual void Virtual02c();
    virtual void Virtual030();
    virtual void Virtual034();
    virtual void Virtual038();
    virtual void Virtual03c();
    virtual void Virtual040();
    virtual void Virtual044();
    virtual void Virtual048();
    virtual void Virtual04c();
    virtual void Virtual050();
    virtual void Virtual054();
    virtual void Reset();
    virtual void Virtual05c();
    virtual void Virtual060();
    virtual void Virtual064();
    virtual void Virtual068();
    virtual void Virtual06c();
    virtual void Virtual070();
    virtual void Virtual074();
    virtual void Virtual078();
    virtual void Virtual07c();
    virtual void Virtual080();
    virtual void Virtual084();
    virtual void Virtual088();
    virtual void Virtual08c();
    virtual void Virtual090();
    virtual void Virtual094();
    virtual void Virtual098();
    virtual void Virtual09c();
    virtual void Virtual0a0();
    virtual void Virtual0a4();
    virtual void Virtual0a8();
    virtual void Virtual0ac();
    virtual void Virtual0b0();
    virtual void Virtual0b4();
    virtual void Virtual0b8();
    virtual void Virtual0bc();
    virtual void Virtual0c0();
    virtual void Virtual0c4();
    virtual void Virtual0c8();
    virtual void Virtual0cc();
    virtual void Virtual0d0();
    virtual void Virtual0d4();
    virtual void Virtual0d8();
    virtual void Virtual0dc();
    virtual void Virtual0e0();
    virtual void Virtual0e4();
    virtual void Virtual0e8();
    virtual void Virtual0ec();
    virtual void Virtual0f0();
    virtual void Virtual0f4();
    virtual void Virtual0f8();
    virtual void Virtual0fc();
    virtual void Virtual100();
    virtual void Virtual104();
    virtual void Virtual108();
    virtual void Virtual10c();
    virtual void Virtual110();
    virtual void Virtual114();
    virtual void Virtual118();
    virtual void Virtual11c();
    virtual void Virtual120();
    virtual void Virtual124();
    virtual void Virtual128();
    virtual void Virtual12c();
    virtual void Virtual130();
    virtual void Virtual134();
    virtual void Virtual138();
    virtual void Virtual13c();
    virtual void Virtual140();
    virtual void Virtual144();
    virtual void Virtual148();
    virtual void Virtual14c();
    virtual void Virtual150();
    virtual void Virtual154();
    virtual void Virtual158();
    virtual void Virtual15c();
    virtual void Virtual160();
    virtual void Virtual164();
    virtual void Virtual168();
    virtual void Virtual16c();
    virtual void Virtual170();
    virtual void Virtual174();
    virtual void Virtual178();
    virtual void Virtual17c();
    virtual void Virtual180();
    virtual void Virtual184();
    virtual void Virtual188();
    virtual void Virtual18c();
    virtual void Virtual190();
    virtual void Virtual194();
    virtual void Virtual198();
    virtual void Virtual19c();
    virtual void Virtual1a0();
    virtual void Virtual1a4();
    virtual void Virtual1a8();
    virtual void Virtual1ac();
    virtual void Virtual1b0();
    virtual void Virtual1b4();
    virtual void Virtual1b8();
    virtual void Virtual1bc();
    virtual void Virtual1c0();
    virtual void Virtual1c4();
    virtual void Virtual1c8();
    virtual void Virtual1cc();
    virtual void Virtual1d0();
    virtual void Virtual1d4();
    virtual void Virtual1d8();
    virtual void Virtual1dc();
    virtual void Virtual1e0();
    virtual void Virtual1e4();
    virtual void Virtual1e8();
    virtual void Virtual1ec();
    virtual void Virtual1f0();
    virtual void Virtual1f4();
    virtual void Virtual1f8();
    virtual void Virtual1fc();
    virtual void Virtual200();
    virtual void Virtual204();
    virtual void Virtual208();
    virtual void Virtual20c();
    virtual void Virtual210();
    virtual void Virtual214();
    virtual void Virtual218();
    virtual void Virtual21c();
    virtual void Virtual220();
    virtual void Virtual224();
    virtual void Virtual228();
    virtual void Virtual22c();
    virtual void Virtual230();
    virtual void Virtual234();
    virtual void Virtual238();
    virtual void Virtual23c();
    virtual void Virtual240();
    virtual void Virtual244();
    virtual void Virtual248();
    virtual void Virtual24c();
    virtual void Virtual250();
    virtual void Virtual254();
    virtual void Virtual258();
    virtual void Virtual25c();
    virtual void Virtual260();
    virtual void Virtual264();
    virtual void Virtual268();
    virtual void Virtual26c();
    virtual void Virtual270();
    virtual void Virtual274();
    virtual void Virtual278();
    virtual void Virtual27c();
    virtual void Virtual280();
    virtual void Virtual284();
    virtual void Virtual288();
    virtual void Virtual28c();
    virtual void Virtual290();
    virtual void Virtual294();
    virtual void Virtual298();
    virtual void Virtual29c();
    virtual void Virtual2a0();
    virtual void Virtual2a4();
    virtual void Virtual2a8();
    virtual void Virtual2ac();
    virtual void Virtual2b0();
    virtual void Virtual2b4();
    virtual void Virtual2b8();
    virtual void Virtual2bc();
    virtual void Virtual2c0();
    virtual void Virtual2c4();
    virtual void Virtual2c8();
    virtual void Virtual2cc();
    virtual void Virtual2d0();
    virtual void Virtual2d4();
    virtual void Virtual2d8();
    virtual void Virtual2dc();
    virtual void Virtual2e0();
    virtual void Virtual2e4();
    virtual void Virtual2e8();
    virtual void Virtual2ec();
    virtual void Virtual2f0();
    virtual void Virtual2f4();
    virtual void Virtual2f8();
    virtual void Virtual2fc();
    virtual void Virtual300();
    virtual void Virtual304();
    virtual void Virtual308();
    virtual void Virtual30c();
    virtual void Virtual310();
    virtual void Virtual314();
    virtual void Virtual318();
    virtual void Virtual31c();
    virtual void Virtual320();
    virtual void Virtual324();
    virtual void Virtual328();
    virtual void Virtual32c();
    virtual void Virtual330();
    virtual void Virtual334();
    virtual void Virtual338();
    virtual void Virtual33c();
    virtual void Virtual340();
    virtual void Virtual344();
    virtual void Virtual348();
    virtual void Virtual34c();
    virtual void Virtual350();
    virtual void Virtual354();
    virtual void Virtual358();
    virtual void Virtual35c();
    virtual void Virtual360();
    virtual void Virtual364();
    virtual void Virtual368();
    virtual void Virtual36c();
    virtual void Virtual370();
    virtual void Virtual374();
    virtual void Virtual378();
    virtual void Virtual37c();
    virtual void Virtual380();
    virtual void Virtual384();
    virtual void Virtual388();
    virtual void Virtual38c();
    virtual void Virtual390();
    virtual void Virtual394();
    virtual void Virtual398();
    virtual void Virtual39c();
    virtual void Virtual3a0();
    virtual void Virtual3a4();
    virtual void Virtual3a8();
    virtual void Virtual3ac();
    virtual void Virtual3b0();
    virtual void Virtual3b4();
    virtual void Virtual3b8();
    virtual void Virtual3bc();
    virtual void Virtual3c0();
    virtual void Virtual3c4();
    virtual void Virtual3c8();
    virtual void Virtual3cc();
    virtual void Virtual3d0();
    virtual void Virtual3d4();
    virtual void Virtual3d8();
    virtual void Virtual3dc();
    virtual void Virtual3e0();
    virtual void Virtual3e4();
    virtual void Virtual3e8();
    virtual void Virtual3ec();
    virtual void Virtual3f0();
    virtual void Virtual3f4();
    virtual void Virtual3f8();
    virtual void Virtual3fc();
    virtual void Virtual400();
    virtual void Virtual404();
    virtual void Virtual408();
    virtual void Virtual40c();
    virtual void Virtual410();
    virtual void Virtual414();
    virtual void Virtual418();
    virtual void Virtual41c();
    virtual void Virtual420();
    virtual void Virtual424();
    virtual void Virtual428();
    virtual void Virtual42c();
    virtual void Virtual430();
    virtual void Virtual434();
    virtual void Virtual438();
    virtual void Virtual43c();
    virtual void Virtual440();
    virtual void Virtual444();
    virtual void Virtual448();
    virtual void Virtual44c();
    virtual void Virtual450();
    virtual void Virtual454();
    virtual void Virtual458();
    virtual void Virtual45c();
    virtual void Virtual460();
    virtual void SetOwner(Player511*);
    virtual void SetMode(int);
};
class Root511
{
  public:
    virtual void Virtual000();
    virtual void Virtual004();
    virtual void Virtual008();
    virtual void Virtual00c();
    virtual void Virtual010();
    virtual void Virtual014();
    virtual void Virtual018();
    virtual void Virtual01c();
    virtual void Virtual020();
    virtual void Refresh();
    virtual void Update();
};
struct NiAVObject511
{
};
struct Node511
{
};
class Player511
{
  public:
    virtual void Virtual000();
    virtual void Virtual004();
    virtual void Virtual008();
    virtual void Virtual00c();
    virtual void Virtual010();
    virtual void Virtual014();
    virtual void Virtual018();
    virtual void Virtual01c();
    virtual void Virtual020();
    virtual void Virtual024();
    virtual void Virtual028();
    virtual void Virtual02c();
    virtual void Virtual030();
    virtual void Virtual034();
    virtual void Virtual038();
    virtual void Virtual03c();
    virtual void Virtual040();
    virtual void Virtual044();
    virtual void Virtual048();
    virtual void Virtual04c();
    virtual void Virtual050();
    virtual void Virtual054();
    virtual void Virtual058();
    virtual void Virtual05c();
    virtual void Virtual060();
    virtual void Virtual064();
    virtual void Virtual068();
    virtual void Virtual06c();
    virtual void Virtual070();
    virtual void Virtual074();
    virtual void Virtual078();
    virtual void Virtual07c();
    virtual void Virtual080();
    virtual void Virtual084();
    virtual void Virtual088();
    virtual void Virtual08c();
    virtual void Virtual090();
    virtual void Virtual094();
    virtual void Virtual098();
    virtual void Virtual09c();
    virtual void Virtual0a0();
    virtual void Virtual0a4();
    virtual void Virtual0a8();
    virtual void Virtual0ac();
    virtual void Virtual0b0();
    virtual void Virtual0b4();
    virtual void Virtual0b8();
    virtual void Virtual0bc();
    virtual void Virtual0c0();
    virtual void Virtual0c4();
    virtual void Virtual0c8();
    virtual void Virtual0cc();
    virtual void Virtual0d0();
    virtual void Virtual0d4();
    virtual void Virtual0d8();
    virtual void Virtual0dc();
    virtual void Virtual0e0();
    virtual void Virtual0e4();
    virtual void Virtual0e8();
    virtual void Virtual0ec();
    virtual void Virtual0f0();
    virtual void Virtual0f4();
    virtual void Virtual0f8();
    virtual void Virtual0fc();
    virtual void Virtual100();
    virtual void Virtual104();
    virtual void Virtual108();
    virtual void Virtual10c();
    virtual void Virtual110();
    virtual void Virtual114();
    virtual void Virtual118();
    virtual void Virtual11c();
    virtual void Virtual120();
    virtual void Virtual124();
    virtual void Virtual128();
    virtual void Virtual12c();
    virtual void Virtual130();
    virtual void Virtual134();
    virtual void Virtual138();
    virtual void Virtual13c();
    virtual void Virtual140();
    virtual void Virtual144();
    virtual void Virtual148();
    virtual void Virtual14c();
    virtual void Virtual150();
    virtual void Virtual154();
    virtual void Virtual158();
    virtual void Virtual15c();
    virtual void Virtual160();
    virtual void Virtual164();
    virtual void Virtual168();
    virtual void Virtual16c();
    virtual void Virtual170();
    virtual void Virtual174();
    virtual void Virtual178();
    virtual void Virtual17c();
    virtual void Virtual180();
    virtual void Virtual184();
    virtual void Virtual188();
    virtual void Virtual18c();
    virtual void Virtual190();
    virtual void Virtual194();
    virtual void Virtual198();
    virtual void Virtual19c();
    virtual void Virtual1a0();
    virtual void Virtual1a4();
    virtual void Virtual1a8();
    virtual int HasStateA(int);
    virtual int HasStateB(int);
    Matrix FUN_0056fac0(const Matrix&);
};
struct IOManager
{
};
class QHeadLocal
{
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
    int unk2c;
    int unk30;
    int unk34;
    QHeadLocal(TESNPC*, int);
    ~QHeadLocal();
};
struct Menu511
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
    TESNPC* npc;
    void FUN_007b25a0();
};
// @fnv 0x007acb60
void InitRaceMenu::SetupRaceMenu(int mode)
{
    const char* names[20];
    if (((double)(reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(0xfa7))) == 6006.0 || ((double)(reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(0xfa7))) == 102.0)
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfad, ::Tile::GetInterfaceScale(), {});
    reinterpret_cast<::TutorialMessageGate718 *>(&(((InitRootManager*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->messages))->FUN_00718630(15, (unsigned int)(FUN_007ac9c0()), 0x200);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::InitTile *)(this->tile))))->FUN_00a01350(0x1005, (char *)(DAT_01063ab4), true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::InitTile *)(this->tile))))->FUN_00a01350(0x1006, (char *)(DAT_010692d0), true);
    npc = dynamic_cast<TESNPC*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*reinterpret_cast<::InitPlayer * *>(&::_g_thePlayer))))->FUN_007af430())));
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((display))->FUN_00a01350(0xfc4, (char *)(((const char *)(::FUN_00559450((int *)&((*reinterpret_cast<::InitString *>(&::g_011da6f4))))))), true);
    {
        BSStringTChar aLabelStrings[4];
        {
            int page;
            {
                unsigned int color;
                {
                    InitItem* slider;
                    {
                        switch (mode)
                        {
                        case 2:
                        case 3:
                            reinterpret_cast<::TextString *>(&(aLabelStrings[0]))->FUN_004037f0(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d1f38))))->GetMenuTitle())), 0);
                            reinterpret_cast<::TextString *>(&(aLabelStrings[1]))->FUN_004037f0(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d20dc))))->GetMenuTitle())), 0);
                            reinterpret_cast<::TextString *>(&(aLabelStrings[2]))->FUN_004037f0(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d2058))))->GetMenuTitle())), 0);
                            reinterpret_cast<::TextString *>(&(aLabelStrings[3]))->FUN_004037f0(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d43d8))))->GetMenuTitle())), 0);
                            break;
                        default:
                            ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringTChar *)(&aLabelStrings[0]), DAT_01075ae4, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d1f38))))->GetMenuTitle())));
                            ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringTChar *)(&aLabelStrings[1]), DAT_01075adc, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d20dc))))->GetMenuTitle())));
                            ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringTChar *)(&aLabelStrings[2]), DAT_01075ad4, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d2058))))->GetMenuTitle())));
                            ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringTChar *)(&aLabelStrings[3]), DAT_01075acc, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d43d8))))->GetMenuTitle())));
                            break;
                        }
                        names[0] = ((const char *)(::FUN_00559450((int *)&(aLabelStrings[0]))));
                        names[1] = ((const char *)(::FUN_00559450((int *)&(aLabelStrings[1]))));
                        names[2] = ((const char *)(::FUN_00559450((int *)&(aLabelStrings[2]))));
                        names[3] = ((const char *)(::FUN_00559450((int *)&(aLabelStrings[3]))));
                        names[4] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d36e4))))->GetMenuTitle()));
                        names[5] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d22d4))))->GetMenuTitle()));
                        names[6] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d4a74))))->GetMenuTitle()));
                        names[7] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StrTable *>(&::g_011d23a0))))->GetMenuTitle()));
                        names[8] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d31c8))))->GetMenuTitle()));
                        names[9] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d26d0))))->GetMenuTitle()));
                        names[10] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d3eb0))))->GetMenuTitle()));
                        names[11] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d4480))))->GetMenuTitle()));
                        names[12] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d4318))))->GetMenuTitle()));
                        names[13] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d3084))))->GetMenuTitle()));
                        names[14] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d4d20))))->GetMenuTitle()));
                        names[15] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d4180))))->GetMenuTitle()));
                        names[16] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d3078))))->GetMenuTitle()));
                        names[17] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d50e0))))->GetMenuTitle()));
                        names[18] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d3618))))->GetMenuTitle()));
                        names[19] = ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d2250))))->GetMenuTitle()));
                        for (int i = 0; i < 20; i++)
                        {
                            options[i] = new FUN_007b39e0(i, (intptr_t)names[i]);
                        }
                        reinterpret_cast<::BGSDehydrationStage *>((((InitOptions*)options[0])))->FUN_0050f9a0((::SpellItem *)(void *)((void*)FUN_007ad940));
                        reinterpret_cast<::BGSDehydrationStage *>((((InitOptions*)options[1])))->FUN_0050f9a0((::SpellItem *)(void *)((void*)((char (&)(int))::IsHairMatching)));
                        reinterpret_cast<::BGSDehydrationStage *>((((InitOptions*)options[5])))->FUN_0050f9a0((::SpellItem *)(void *)((void*)(unsigned char(__cdecl*)(Obj0*))FUN_007ad860));
                        reinterpret_cast<::BGSDehydrationStage *>((((InitOptions*)options[8])))->FUN_0050f9a0((::SpellItem *)(void *)((void*)IsAnimationMatch));
                        reinterpret_cast<::BGSDehydrationStage *>((((InitOptions*)options[7])))->FUN_0050f9a0((::SpellItem *)(void *)((void*)IsArgValueInSubLookup));
                        reinterpret_cast<::FUN_007b3b80_shell *>((((InitOptions*)options[0])))->FUN_007b3b80((intptr_t)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d37ec))))->IsDLCAvailable()))), 21);
                        reinterpret_cast<::FUN_007b3b80_shell *>((((InitOptions*)options[0])))->FUN_007b3b80((intptr_t)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d2d3c))))->IsDLCAvailable()))), 22);
                        for (InitNode* pRaceNode = ((::InitNode *)(::FUN_004ea950((intptr_t)(((InitData*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))));
                             pRaceNode && *((::InitForm **)(&reinterpret_cast<::SimpleListNodeView*>(pRaceNode)->m_item)); pRaceNode = ((::InitNode *)(reinterpret_cast<::Callees *>((pRaceNode))->FUN_00726070())))
                        {
                            if (reinterpret_cast<::FUN_0059f610Class *>(((*((::InitForm **)(&reinterpret_cast<::SimpleListNodeView*>(pRaceNode)->m_item)))))->FUN_0059f610())
                                reinterpret_cast<::TESRegionGrassObject *>((((InitOptions*)options[1])
                                    ->FUN_007b3b80(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&((*((::InitForm **)(&reinterpret_cast<::SimpleListNodeView*>(pRaceNode)->m_item)))->name))->FUN_00408da0())), 23)))->AssignLandTexture((::TESLandTexture *)(*((::InitForm **)(&reinterpret_cast<::SimpleListNodeView*>(pRaceNode)->m_item))));
                        }
                        reinterpret_cast<::B3CA0Menu *>((((InitOptions*)options[2])))->FUN_007b3ca0((intptr_t)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d3ff4))))->IsDLCAvailable()))), 24, 1, 20, 0x80000001, 0.25f);
                        reinterpret_cast<::Menu_007b3bb0 *>((((InitOptions*)options[2])))->AddFloatOption(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d36e4))))->IsDLCAvailable())), (::SelectedOption_007b3bb0 *)(::InitOptions *)(((InitOptions*)options[4])));
                        reinterpret_cast<::FUN_007b3b80_shell *>((((InitOptions*)options[2])))->FUN_007b3b80((intptr_t)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d3d48))))->IsDLCAvailable()))), 25);
                        slider = ((::InitItem *)(reinterpret_cast<::B3CA0Menu *>((((InitOptions*)options[2])))->FUN_007b3ca0((intptr_t)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d4084))))->IsDLCAvailable()))), 26, 1, 10, 0x80000001, 0.25f)));
                        reinterpret_cast<::FUN_007b3810Class *>((slider))->FUN_007b3810(DAT_01020770);
                        reinterpret_cast<::Menu_007b3bb0 *>((((InitOptions*)options[3])))->AddFloatOption(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d22d4))))->IsDLCAvailable())), (::SelectedOption_007b3bb0 *)(::InitOptions *)(((InitOptions*)options[5])));
                        reinterpret_cast<::Menu_007b3bb0 *>((((InitOptions*)options[3])))->AddFloatOption(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d4a74))))->IsDLCAvailable())), (::SelectedOption_007b3bb0 *)(::InitOptions *)(((InitOptions*)options[6])));
                        if (!npc->FUN_005f0cc0())
                            reinterpret_cast<::Menu_007b3bb0 *>((((InitOptions*)options[3])))->AddFloatOption(((const char *)(reinterpret_cast<::DownloadableContentManager *>((((InitSetting*)&(*reinterpret_cast<::StrTable *>(&::g_011d23a0)))))->IsDLCAvailable())),
                                                 (::SelectedOption_007b3bb0 *)(::InitOptions *)(((InitOptions*)options[7])));
                        else
                            reinterpret_cast<::FUN_0041fd00_shell *>((((InitOptions*)options[7])))->FUN_0041fd00(3);
                        reinterpret_cast<::Menu_007b3bb0 *>((((InitOptions*)options[4])))->AddFloatOption(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d26d0))))->IsDLCAvailable())), (::SelectedOption_007b3bb0 *)(::InitOptions *)(((InitOptions*)options[9])));
                        reinterpret_cast<::Menu_007b3bb0 *>((((InitOptions*)options[4])))->AddFloatOption(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d2250))))->IsDLCAvailable())), (::SelectedOption_007b3bb0 *)(::InitOptions *)(((InitOptions*)options[19])));
                        reinterpret_cast<::Menu_007b3bb0 *>((((InitOptions*)options[4])))->AddFloatOption(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d31c8))))->IsDLCAvailable())), (::SelectedOption_007b3bb0 *)(::InitOptions *)(((InitOptions*)options[8])));
                        color = reinterpret_cast<::FUN_004169d0_shell *>((npc))->FUN_004169d0();
                        reinterpret_cast<::FUN_007b3810Class *>((((::InitItem *)(reinterpret_cast<::B3CA0Menu *>((((InitOptions*)options[6])))->FUN_007b3ca0((intptr_t)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d3ff4))))->IsDLCAvailable()))), 29, 0, 15, 0x80000001, 0.25f)))))->FUN_007b3810(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d3528))))->GetMenuTitle())));
                        reinterpret_cast<::B3CA0Menu *>((((InitOptions*)options[6])))->FUN_007b3ca0((intptr_t)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d2a84))))->IsDLCAvailable()))), 30, 0, 255, (unsigned char)(color & 255),
                                           0.125f);
                        reinterpret_cast<::B3CA0Menu *>((((InitOptions*)options[6])))->FUN_007b3ca0((intptr_t)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d25a4))))->IsDLCAvailable()))), 31, 0, 255,
                                           (unsigned char)(((unsigned short)color >> 8) & 255), 0.125f);
                        reinterpret_cast<::B3CA0Menu *>((((InitOptions*)options[6])))->FUN_007b3ca0((intptr_t)(((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d2d48))))->IsDLCAvailable()))), 32, 0, 255,
                                           (unsigned char)((color >> 16) & 255), 0.125f);
                        for (InitNode* pBeardNode = ((::InitNode *)(reinterpret_cast<::FUN_00624700_shell *>((((InitData*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->FUN_00624700()));
                             pBeardNode && *((::InitForm **)(&reinterpret_cast<::SimpleListNodeView*>(pBeardNode)->m_item)); pBeardNode = ((::InitNode *)(reinterpret_cast<::Callees *>((pBeardNode))->FUN_00726070())))
                        {
                            if (((bool)(reinterpret_cast<::FUN_005e7a60_cls *>(((*((::InitForm **)(&reinterpret_cast<::SimpleListNodeView*>(pBeardNode)->m_item)))))->FUN_005e7a60())))
                                reinterpret_cast<::TESRegionGrassObject *>((((InitOptions*)options[7])
                                    ->FUN_007b3b80(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&((*((::InitForm **)(&reinterpret_cast<::SimpleListNodeView*>(pBeardNode)->m_item)))->name))->FUN_00408da0())), 28)))->AssignLandTexture((::TESLandTexture *)(*((::InitForm **)(&reinterpret_cast<::SimpleListNodeView*>(pBeardNode)->m_item))));
                        }
                        for (int j = 10; j < 19; j++)
                            reinterpret_cast<::Menu_007b3bb0 *>((((InitOptions*)options[9])))->AddFloatOption(names[j], (::SelectedOption_007b3bb0 *)(::InitOptions *)(((InitOptions*)options[j])));
                        reinterpret_cast<::FaceMorphMenu *>(this)->BuildMorphOptions();
                        BSStringTChar doneLabel;
                        switch (mode)
                        {
                        case 2:
                            reinterpret_cast<::TextString *>(&(title))->FUN_004037f0(DAT_01075aac, 0);
                            reinterpret_cast<::TextString *>(&(doneLabel))->FUN_004037f0(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d43d8))))->GetMenuTitle())), 0);
                            page = 3;
                            unk120 = page;
                            valuea0 = -7.4f;
                            valuea4 = 80.0f;
                            valuea8 = -0.84f;
                            valueac = -12.4f;
                            valueb0 = 135.0f;
                            valueb4 = -0.8f;
                            break;
                        case 3:
                            reinterpret_cast<::TextString *>(&(title))->FUN_004037f0(DAT_01075a74, 0);
                            reinterpret_cast<::TextString *>(&(doneLabel))->FUN_004037f0(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d2058))))->GetMenuTitle())), 0);
                            page = 2;
                            unk120 = page;
                            valuea0 = -5.2f;
                            valuea4 = 55.0f;
                            valuea8 = -0.84f;
                            valueac = -12.4f;
                            valueb0 = 135.0f;
                            valueb4 = -0.77f;
                            reinterpret_cast<::FUN_007af610_shell *>(this)->UpdateHairMenuOption();
                            break;
                        default:
                            reinterpret_cast<::TextString *>(&(title))->FUN_004037f0(DAT_01075a4c, 0);
                            reinterpret_cast<::TextString *>(&(doneLabel))->FUN_004037f0(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d454c))))->GetMenuTitle())), 0);
                            reinterpret_cast<::FUN_007b4050_shell *>((((InitOptions*)options[0])))->CopyControlValues((::FUN_007b4050_shell *)(::InitOptions *)(((InitOptions*)options[1])));
                            reinterpret_cast<::FUN_007b4050_shell *>((((InitOptions*)options[1])))->CopyControlValues((::FUN_007b4050_shell *)(::InitOptions *)(((InitOptions*)options[2])));
                            reinterpret_cast<::FUN_007b4050_shell *>((((InitOptions*)options[2])))->CopyControlValues((::FUN_007b4050_shell *)(::InitOptions *)(((InitOptions*)options[3])));
                            unk120 = 3;
                            page = 0;
                            valuea0 = -4.7f;
                            valuea4 = 55.0f;
                            valuea8 = -0.84f;
                            valueac = -11.4f;
                            valueb0 = 135.0f;
                            valueb4 = -0.8f;
                            reinterpret_cast<::FUN_007af610_shell *>(this)->UpdateHairMenuOption();
                            break;
                        }
                        if (FUN_004b7220() != 1)
                            ::FUN_004afad0((::BSStringT_layout *)&(doneLabel));
                        ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringTChar *)(&question), DAT_01074e34, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::InitSetting *>(&::g_011d4108))))->GetMenuTitle())), ((const char *)(::FUN_00559450((int *)&(doneLabel)))));
                        valued0 = FUN_00404010(0.0f, FUN_0040ebd0(1.0f, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::InitSetting *>(&::g_011da6cc))))))));
                        valuec8 = valued0;
                        reinterpret_cast<::S_007b40d0_Owner *>((((InitOptions*)options[0])))->ApplyToAllTiles();
                        reinterpret_cast<::S_007b40d0_Owner *>((((InitOptions*)options[1])))->ApplyToAllTiles();
                        reinterpret_cast<::S_007b40d0_Owner *>((((InitOptions*)options[7])))->ApplyToAllTiles();
                        reinterpret_cast<::FUN_00ad8830_shell *>(&(sub0))->FUN_00ad8830(0);
                        reinterpret_cast<::FUN_00ad8830_shell *>(&(sub1))->FUN_00ad8830(0);
                        reinterpret_cast<::FUN_007af180_shell *>(this)->FUN_007af180(page);
                        reinterpret_cast<::Menu *>(this)->SetMenuVisibility(0);
                    }
                }
            }
        }
    }
}
// @fnv 0x007afaf0
void FaceMorphMenu::BuildMorphOptions()
{
    FaceMorphDescriptor shape[] = {
        {12, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d1ecc))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {12, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d3504))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {12, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d3840))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {16, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d4b34))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {16, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d228c))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {16, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d32dc))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {18, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d46f0))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {18, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d4714))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {18, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d3150))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {18, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d3a8c))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {13, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d4384))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {13, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d4e88))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {13, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d49f0))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {10, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d2ca0))))->GetMenuTitle())), ::DAT_0104a494, DAT_010162c0},
        {20, 0, 0.0f, 0.0f},
        {10, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d35a0))))->GetMenuTitle())), ::DAT_0104a494, DAT_010162c0},
        {11, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d4e88))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {11, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d3a8c))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {11, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d3720))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {17, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d240c))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {17, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d2514))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {17, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d2778))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {17, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d32dc))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {15, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d34a4))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {15, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d22e0))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {14, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d3660))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {14, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d4384))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {14, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d2e44))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {14, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d2dfc))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {14, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d4900))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {14, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d23e8))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), ::DAT_01017718},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {14, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d32a0))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), ::DAT_01017718},
        {20, 0, 0.0f, 0.0f},
    };
    FaceMorphDescriptor tone[] = {
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d2b80))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d3b80))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d3078))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d4174))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d2304))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d4300))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d4c30))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {20, 0, 0.0f, 0.0f},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d4d20))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d5104))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d33e4))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d2928))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
        {19, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011d5098))))->GetMenuTitle())), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6a4))))->FUN_00450410(), reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::MorphSetting *>(&::g_011da6dc))))->FUN_00450410()},
    };
    MorphData morphs[4];
    ::FUN_00652af0((CoordArray (*)[2])(void *)(((void *)(reinterpret_cast<::S9fb0 *>((((::MorphRace *)(reinterpret_cast<::Callees *>(&(actor->race))->FUN_00726070()))))->FUN_005d9fb0(actor->FUN_005f0cc0())))), (CoordArray (*)[2])(void *)(reinterpret_cast<::FUN_00601800_shell *>((actor))->FUN_00601800()), (CoordArray (*)[2])(morphs), 0,
                 0.0f);
    for (intptr_t index = 0; index < (((void *)(::BSFaceGenManager::GetFaceGenManager())), ((int)(::fnv_006521b0::FUN_006521b0(0, 0)))); ++index)
    {
        if (shape[index].group < 20 && shape[index].name)
        {
            float value = ::GetMorphCoordinateValue((char *)(morphs), 0, 0, index);
            value = FUN_00404010(FUN_0040ebd0(value, shape[index].maximum), shape[index].minimum);
            MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[shape[index].group]))->FUN_007b3ca0(
                (intptr_t)(shape[index].name), 34, static_cast<int>(shape[index].minimum * 10.0),
                static_cast<int>(shape[index].maximum * 10.0), static_cast<int>(value * 10.0), 0.25f)));
            reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
            reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(index));
        }
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 29);
        value = FUN_00404010(FUN_0040ebd0(value, tone[29].maximum), tone[29].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[29].group]))->FUN_007b3ca0(
            (intptr_t)(tone[29].name), 35, static_cast<int>(tone[29].minimum * 10.0), static_cast<int>(tone[29].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(29));
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 28);
        value = FUN_00404010(FUN_0040ebd0(value, tone[28].maximum), tone[28].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[28].group]))->FUN_007b3ca0(
            (intptr_t)(tone[28].name), 35, static_cast<int>(tone[28].minimum * 10.0), static_cast<int>(tone[28].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(28));
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 30);
        value = FUN_00404010(FUN_0040ebd0(value, tone[30].maximum), tone[30].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[30].group]))->FUN_007b3ca0(
            (intptr_t)(tone[30].name), 35, static_cast<int>(tone[30].minimum * 10.0), static_cast<int>(tone[30].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(30));
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 31);
        value = FUN_00404010(FUN_0040ebd0(value, tone[31].maximum), tone[31].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[31].group]))->FUN_007b3ca0(
            (intptr_t)(tone[31].name), 35, static_cast<int>(tone[31].minimum * 10.0), static_cast<int>(tone[31].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(31));
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 8);
        value = FUN_00404010(FUN_0040ebd0(value, tone[8].maximum), tone[8].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[8].group]))->FUN_007b3ca0(
            (intptr_t)(tone[8].name), 35, static_cast<int>(tone[8].minimum * 10.0), static_cast<int>(tone[8].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(8));
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 9);
        value = FUN_00404010(FUN_0040ebd0(value, tone[9].maximum), tone[9].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[9].group]))->FUN_007b3ca0(
            (intptr_t)(tone[9].name), 35, static_cast<int>(tone[9].minimum * 10.0), static_cast<int>(tone[9].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(9));
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 18);
        value = FUN_00404010(FUN_0040ebd0(value, tone[18].maximum), tone[18].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[18].group]))->FUN_007b3ca0(
            (intptr_t)(tone[18].name), 35, static_cast<int>(tone[18].minimum * 10.0), static_cast<int>(tone[18].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(18));
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 27);
        value = FUN_00404010(FUN_0040ebd0(value, tone[27].maximum), tone[27].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[27].group]))->FUN_007b3ca0(
            (intptr_t)(tone[27].name), 35, static_cast<int>(tone[27].minimum * 10.0), static_cast<int>(tone[27].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(27));
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 22);
        value = FUN_00404010(FUN_0040ebd0(value, tone[22].maximum), tone[22].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[22].group]))->FUN_007b3ca0(
            (intptr_t)(tone[22].name), 35, static_cast<int>(tone[22].minimum * 10.0), static_cast<int>(tone[22].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(22));
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 5);
        value = FUN_00404010(FUN_0040ebd0(value, tone[5].maximum), tone[5].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[5].group]))->FUN_007b3ca0(
            (intptr_t)(tone[5].name), 35, static_cast<int>(tone[5].minimum * 10.0), static_cast<int>(tone[5].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(5));
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 6);
        value = FUN_00404010(FUN_0040ebd0(value, tone[6].maximum), tone[6].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[6].group]))->FUN_007b3ca0(
            (intptr_t)(tone[6].name), 35, static_cast<int>(tone[6].minimum * 10.0), static_cast<int>(tone[6].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(6));
    }
    {
        float value = ::GetMorphCoordinateValue((char *)(morphs), 1, 0, 3);
        value = FUN_00404010(FUN_0040ebd0(value, tone[3].maximum), tone[3].minimum);
        MorphMenuOption* option = ((::MorphMenuOption *)(reinterpret_cast<::B3CA0Menu *>((lists[tone[3].group]))->FUN_007b3ca0(
            (intptr_t)(tone[3].name), 35, static_cast<int>(tone[3].minimum * 10.0), static_cast<int>(tone[3].maximum * 10.0),
            static_cast<int>(value * 10.0), 0.25f)));
        reinterpret_cast<::FUN_007b3810Class *>((option))->FUN_007b3810(::DAT_01020770);
        reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(3));
    }
    reinterpret_cast<::B7B18F0Menu *>(this)->HandleMenuKey(34);
    reinterpret_cast<::B7B18F0Menu *>(this)->HandleMenuKey(35);
    if (reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(8))
    {
        reinterpret_cast<::AppearanceMenu *>(this)->UpdateFaceGen(1, 1, 0);
        reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(8, false);
    }
    if (reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(9))
    {
        reinterpret_cast<::Menu511 *>(this)->FUN_007b25a0();
        reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(9, false);
    }
}
// @fnv 0x007b25a0
void Menu511::FUN_007b25a0()
{
    ::FUN_006570e0((::QueryObject *)(::HairOption *)(((::HairOption *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*reinterpret_cast<::Player511 * *>(&::_g_thePlayer))))->FUN_007af430()))));
    DAT_011c5cb4 = true;
    ((::Process511 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::Player511 * *>(&::_g_thePlayer))))->GetBaseTexture()))->Reset();
    ((::Process511 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::Player511 * *>(&::_g_thePlayer))))->GetBaseTexture()))->SetMode(3);
    ((::Process511 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::Player511 * *>(&::_g_thePlayer))))->GetBaseTexture()))->SetOwner((*reinterpret_cast<::Player511 * *>(&::_g_thePlayer)));
    if (!(*reinterpret_cast<::Player511 * *>(&::_g_thePlayer))->HasStateB(0) && !(*reinterpret_cast<::Player511 * *>(&::_g_thePlayer))->HasStateA(0))
    {
        QHeadLocal head(npc, 0);
        reinterpret_cast<::fnv_0043ecb0::FUN_0043ecb0_shell *>(&(head))->FUN_0043ecb0();
        reinterpret_cast<::FUN_0043c610_shell *>(&(head))->RunVirtualMethod28();
        reinterpret_cast<::fnv_0043ed90::AttachTask *>(&(head))->FUN_0043ed90((::fnv_0043ed90::RefActor *)((*reinterpret_cast<::Player511 * *>(&::_g_thePlayer))), (intptr_t)(((void *)(reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::Player511 * *>(&::_g_thePlayer))))->FUN_00950b00(false)))));
    }
    DAT_011c5cb4 = false;
    Node511* node = ((::Node511 *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::Player511 * *>(&::_g_thePlayer))))->FUN_00950bb0(true)));
    Node511* matrix = node;
    NiAVObject511* object = ((::NiAVObject511 *)(reinterpret_cast<::NiNode *>((matrix))->GetAt(0)));
    Matrix node2 = (*reinterpret_cast<::Matrix *>(&::DAT_011a9448));
    reinterpret_cast<::FUN_0043fa80_s *>((object))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&ResultSlot((*reinterpret_cast<::Player511 * *>(&::_g_thePlayer))->FUN_0056fac0(node2)))));
    reinterpret_cast<::FUN_00456520_Class *>((DAT_01202d98))->FUN_00456520();
    reinterpret_cast<::FUN_007b1ae0_shell *>(this)->UpdateShadowSceneNode();
    ((::Root511 *)(::fnv_00705990::FUN_00705990()))->Update();
    ((::Root511 *)(::fnv_00705990::FUN_00705990()))->Refresh();
}

struct NavTile
{
};
struct NavItem
{
    NavTile* tile;
};
struct NavController
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Navigate(int, int);
};
struct NavList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NavItem* selected;
    void* FUN_0049c680(NavItem*&, int);
    bool FUN_007b4260(int);
};
// @fnv 0x007af300
void HairMenu::PopulateHairOptions()
{
    reinterpret_cast<::FUN_007b45b0_shell *>((options))->FUN_007b45b0();
    HairOption* pChosenOption = 0;
    for (HairNode* node = ((::HairNode *)(reinterpret_cast<::FUN_00613790_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_00613790())); node && *((::Hair **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)); node = ((::HairNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
    {
        if (reinterpret_cast<::FUN_005fdf40_shell *>(((*((::Hair **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))))->FUN_005fdf40() && reinterpret_cast<::FUN_005fdfa0_shell *>(((*((::Hair **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))))->IsHairValidForNPC(npc))
        {
            HairOption* option = options->FUN_007b3b80(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&((*((::Hair **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))->fullName))->FUN_00408da0())), 27);
            reinterpret_cast<::TESRegionGrassObject *>((option))->AssignLandTexture((::TESLandTexture *)(*((::Hair **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item))));
            if (!pChosenOption && ((bool)(::FUN_007ad860((::Obj0 *)(option)))))
                pChosenOption = option;
        }
    }
    reinterpret_cast<::StatsMenu *>(this)->UpdateMinusPlusTiles();
    while (pChosenOption && pChosenOption != ((::HairOption *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((options))->FUN_007af430())) && reinterpret_cast<::NavList *>((options))->FUN_007b4260(2))
    {
    }
    reinterpret_cast<::S_007b40d0_Owner *>((options))->ApplyToAllTiles();
    reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(0, false);
}
// @fnv 0x007aecb0
bool Menu67::HandleAction(int action, int argument)
{
    if (FUN_00702450(Id()))
    {
        if (action >= 0)
        {
            int key = reinterpret_cast<::FUN_00a23390_t *>((((::Value67 *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::Input67 * *>(&::g_osGlobals))))->FUN_00877720()))))->GetAxisState({}, {});
            reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(4, action != 4 && action != 3 && FUN_0072fa60(key) < 0x1ea9);
        }
        switch (action)
        {
        case 10:
            if (reinterpret_cast<::FUN_007af180_shell *>(this)->FUN_007af180(reinterpret_cast<::FUN_0084e3a0_Class *>((options[FUN_007dcc00()]))->FUN_0084e3a0()))
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::Sound67 &)(((::Audio67 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_0106f380, 0x121, 0)))->FUN_00ad8830({});
            return true;
        case 13:
        case 14: {
            int iOptionIndex = FUN_007dcc00();
            while (iOptionIndex >= 4)
                iOptionIndex = reinterpret_cast<::FUN_0084e3a0_Class *>((options[iOptionIndex]))->FUN_0084e3a0();
            bool bChanged = action == 13 ? reinterpret_cast<::FUN_007af180_shell *>(this)->FUN_007af180(reinterpret_cast<::FUN_0084e3a0_Class *>((options[iOptionIndex]))->FUN_0084e3a0())
                                         : reinterpret_cast<::FUN_007af180_shell *>(this)->FUN_007af180(((intptr_t)(reinterpret_cast<::MagicCaster_shell *>((options[iOptionIndex]))->FUN_0044edb0())));
            if (bChanged)
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::Sound67 &)(((::Audio67 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01075b00, 0x121, 0)))->FUN_00ad8830({});
            else if (action == 14)
                ::fnv_00703e80::FUN_00703e80(((const char *)(::FUN_00559450((int *)&(message)))), (const char *)(0), (const char *)(0), UpdateRaceSexMenu, 1, 0x12, 0.0f, 0.0f,
                             ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting67 *>(&::g_011d3684))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting67 *>(&::g_011d34f8))))->GetMenuTitle())), 0);
            return true;
        }
        case 3:
        case 4:
        case 15:
        case 16: {
            Tile67* tile = ((Interface67*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->unkbc;
            if (!tile && !FUN_004b71d0())
            {
                tile = ((Interface67*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->focused;
                while (tile && ((::Tile67 *)(reinterpret_cast<::FUN_0045cd60_shell *>((tile))->FUN_0045cd60())) != parent)
                    tile = ((::Tile67 *)(reinterpret_cast<::FUN_0045cd60_shell *>((tile))->FUN_0045cd60()));
            }
            if (tile == left && action == 3 && reinterpret_cast<::sa040a0::Owner *>((right))->IsAllChildrenFlag0())
            {
                ::FUN_00706ff0((intptr_t)(right));
                return true;
            }
            else if (tile == right && action == 4 && reinterpret_cast<::sa040a0::Owner *>((left))->IsAllChildrenFlag0())
            {
                ::FUN_00706ff0((intptr_t)(left));
                return true;
            }
            else if (tile)
            {
                int trait7;
                if (action == 15)
                    trait7 = 0x66;
                else if (action == 16)
                    trait7 = 0x67;
                else if (action == 3)
                    trait7 = 0x68;
                else if (action == 4)
                    trait7 = 0x64;
                else
                    return false;
                Tile67* pDestination = ((::Tile67 *)(reinterpret_cast<::TileFloatList *>((tile))->FUN_00a03eb0(trait7)));
                if (pDestination)
                {
                    Activate(trait7, pDestination);
                    return true;
                }
            }
        }
        case 1:
            return reinterpret_cast<::NavList *>((options[FUN_007dcc00()]))->FUN_007b4260(action);
        case 2:
            if (((Interface67*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->unkbc == left ||
                ((Interface67*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))->unkbc == right || reinterpret_cast<::NavList *>((options[FUN_007dcc00()]))->FUN_007b4260(action))
                return true;
            else if (reinterpret_cast<::sa040a0::Owner *>((left))->IsAllChildrenFlag0())
            {
                reinterpret_cast<::InputFocusController *>((options[FUN_007dcc00()]))->SetFocus(0);
                ::FUN_00706ff0((intptr_t)(left));
                return true;
            }
            else if (reinterpret_cast<::sa040a0::Owner *>((right))->IsAllChildrenFlag0())
            {
                reinterpret_cast<::InputFocusController *>((options[FUN_007dcc00()]))->SetFocus(0);
                ::FUN_00706ff0((intptr_t)(right));
                return true;
            }
            break;
        }
    }
    return false;
}
// Moves the selection according to direction, retries navigation up to 100 times, then updates the selected tile.
// @fnv 0x007b4260
bool NavList::FUN_007b4260(int direction)
{
    void* position;
    bool previousVal = direction == 1 || direction == 15;
    bool bResult = true;
    switch (direction)
    {
    case 1:
    case 2: {
        position = FUN_0049c680(selected, 0);
        if (position)
        {
            position = previousVal ? ((void *)((position ? (void *)(reinterpret_cast<::NiTListItemFields *>(position)->m_pkPrev) : 0))) : ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(this)->DereferenceIfNotNull((int **)(position))));
        }
        else
        {
            position = previousVal ? reinterpret_cast<::Callees *>(this)->FUN_00726070() : ((void *)(::FUN_00559450((int *)this)));
        }
        if (position)
        {
            selected = ((::NavItem *)(reinterpret_cast<::FUN_006317a0_struct *>(this)->AddEight((intptr_t)(position))));
        }
        else
        {
            bResult = false;
        }
        break;
    }
    case 16:
        selected = ((::NavItem *)(reinterpret_cast<::InventoryStackRecord *>(this)->GetPayloadAddress()));
        break;
    case 15:
        selected = ((::NavItem *)(reinterpret_cast<::FUN_0073ac90_shell *>(this)->FUN_0073ac90()));
        break;
    default:
        return false;
    }
    if (selected && selected->tile)
    {
        int attempts = 100;
        while (attempts-- && !reinterpret_cast<::sa040a0::Owner *>((selected->tile))->IsAllChildrenFlag0())
        {
            reinterpret_cast<NavController*>(DAT_011da634)->Navigate(previousVal ? 2 : 3, 0);
        }
        ::FUN_00706ff0((intptr_t)(selected->tile));
    }
    return bResult;
}

struct OptTile
{
    void Refresh(bool);
};
struct OptEntry
{
    OptTile* tile;
    unsigned int kind;
    int unk08;
    OptEntry();
};
struct Root4650
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
    void* parent;
};
struct List4650
{
    int unk00, unk04, unk08, unk0c, unk10;
    OptTile* tile;
    float height;
    int unk1c;
    OptEntry* selected;
    void* Find(OptEntry*&, void*);
    OptEntry* CreateEntry(const char*, const char*, unsigned int, void*);
};
// @fnv 0x007b3b80
void FUN_007b3b80_shell::FUN_007b3b80(intptr_t aiArg1, int aiArg2)
{
    reinterpret_cast<::List4650 *>(this)->CreateEntry((const char *)(aiArg1), "RSM_list_item_template", aiArg2, (void *)(0));
}
// @fnv 0x007b3bb0
intptr_t Menu_007b3bb0::AddFloatOption(const char* input, SelectedOption_007b3bb0* selected)
{
    TempString_007b3bb0 text;
    ::FUN_00406f60((::FUN_00406f90_this *)(::TempString_007b3bb0 *)(&text), DAT_01075b28, input, 0x3e);
    selected->value0c = (unsigned int)reinterpret_cast<::TileListBoxCalls *>((pTGF))->GetFloat(0x1004);
    return ((intptr_t)(reinterpret_cast<::List4650 *>(this)->CreateEntry((const char *)(::FUN_00559450((int *)&(text))), ::str_01075b10, (unsigned int)reinterpret_cast<::TileListBoxCalls *>((selected->pTGF))->GetFloat(0x1004), 0)));
}
// @fnv 0x007b3ca0
B3CA0SliderOption* B3CA0Menu::FUN_007b3ca0(intptr_t m_uiSoundID, int iParent, int iLow, int iHigh, int iValue, float afFraction)
{
    if (afFraction < 0.0)
        afFraction = 0.0f;
    if (afFraction > 1.0)
        afFraction = 1.0f;

    B3CA0SliderOption* pkOption = ((::B3CA0SliderOption *)(reinterpret_cast<::List4650 *>(this)->CreateEntry((const char *)(m_uiSoundID), "RSM_slider_option_template", iParent, (void *)(0))));
    reinterpret_cast<::TileValueAccessor *>((pkOption))->FUN_007b3890(iLow, iHigh);
    reinterpret_cast<::MenuOptionFor3760 *>((pkOption))->FUN_007b3760(iValue);
    reinterpret_cast<::FUN_00a012d0_t *>((pkOption->m_pkTile))->FUN_00a012d0(0x1008, ::InventoryStackRecord::RoundToNearestStep((float)(iHigh - iLow + 1) * afFraction, 1.0f), true);
    return pkOption;
}
// Creates a new OptEntry tile from text and template, inserts or appends it, repositions following entries, updates height, and selects it if none is selected.
// @fnv 0x007b4650
OptEntry* List4650::CreateEntry(const char* text, const char* templ, unsigned int kind, void* pos)
{
    if (!text || !(*reinterpret_cast<::Root4650 * *>(&::DAT_011da634)) || !(*reinterpret_cast<::Root4650 * *>(&::DAT_011da634))->parent || !tile)
        return 0;
    OptEntry* entry7 = new OptEntry;
    int index = (int)reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(0x1004);
    entry7->kind = kind;
    entry7->tile = ((::OptTile *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>(((*reinterpret_cast<::Root4650 * *>(&::DAT_011da634))))->FUN_00a1ddb0((::Tile *)((*reinterpret_cast<::Root4650 * *>(&::DAT_011da634))->parent), (char *)(templ), (::Tile *)(0))));
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((entry7->tile))->FUN_00a01350(0xfc4, (char *)(text), true);
    reinterpret_cast<::Tile *>((entry7->tile))->Set(0x1004, index);
    reinterpret_cast<::Tile *>((entry7->tile))->Set(0xfaf, 1);
    if (pos)
        reinterpret_cast<::FUN_007b5330_Class *>(this)->FUN_007b5330((intptr_t)(pos), (int *)&(entry7));
    else
        reinterpret_cast<::FUN_004ed8c0_shell *>(this)->FUN_004ed8c0((int *)&(entry7));
    pos = Find(entry7, 0);
    while (pos)
    {
        void* prev2 = ((void *)((pos ? (void *)(reinterpret_cast<::NiTListItemFields *>(pos)->m_pkPrev) : 0)));
        OptEntry* beforeB = prev2 ? ((::OptEntry *)(reinterpret_cast<::FUN_006317a0_struct *>(this)->AddEight((intptr_t)(prev2)))) : 0;
        OptEntry* current5 = ((::OptEntry *)(reinterpret_cast<::ListStandIn *>(this)->FUN_0057cbe0((int **)&(pos))));
        reinterpret_cast<::FUN_00a012d0_t *>((current5->tile))->FUN_00a012d0(0xfa2,
                              beforeB ? reinterpret_cast<::TileListBoxCalls *>((beforeB->tile))->GetFloat(0xfa2) + reinterpret_cast<::TileListBoxCalls *>((beforeB->tile))->GetFloat(0xfb0)
                                      : reinterpret_cast<::TileListBoxCalls *>((((::OptTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((current5->tile))->FUN_0045cd60()))))->GetFloat(::FUN_00a00940("_top_bound", -1)),
                              true);
        reinterpret_cast<::RenderTile *>((current5->tile))->FUN_00a04640(false);
    }
    height = FUN_00404010(height, reinterpret_cast<::TileListBoxCalls *>((entry7->tile))->GetFloat(0xfb0));
    if (index < 4 && entry7->kind < 4)
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((entry7->tile))->FUN_00a01350(0xfcb, (char *)("UIPipBoyMode"), true);
    if (!selected)
    {
        selected = entry7;
        reinterpret_cast<::FUN_00a012d0_t *>((entry7->tile))->FUN_00a012d0(0xfd6, DAT_010162c0, true);
    }
    return entry7;
}

namespace fnv_007b4930 {
struct PendingTile : LocalTile
{
};
struct PendingOption : MenuOptionFor3760
{
};
struct PendingMenu
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
    PendingTile* pendingTile;
    PendingOption* pendingOption;
    void HandleOptionSelection();
    void HandlePendingTileAction();
};

// @fnv 0x007b4930
void PendingMenu::HandlePendingTileAction()
{
    if (pendingTile && pendingOption)
    {
        int action = (int)((double)(reinterpret_cast<::TileListBoxCalls *>((pendingTile))->GetFloat(0xfaa)));
        bool changed = false;
        if (((std::intptr_t)(reinterpret_cast<::Callees *>((pendingOption))->FUN_00726070())) == 29 && (action == 100 || action == 104) &&
            ::FUN_00469880((void *)(((const unsigned char *)(reinterpret_cast<::FUN_00a011f0_shell *>((static_cast<PendingTile*>(((::LocalTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((pendingTile))->FUN_0045cd60())))))->FUN_00a011f0(0x1009)))),
                    (void *)(reinterpret_cast<const unsigned char*>(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StrTable *>(&::g_011d3528))))->GetMenuTitle()))))) == 0)
        {
            changed = true;
        }
        else if (action == 100)
        {
            changed = pendingOption->FUN_007b3760(reinterpret_cast<::FUN_007b3740_shell *>((pendingOption))->GetFloat1005() - ((int)(reinterpret_cast<::OptionValueReader *>((pendingOption))->ReadOptionValue())));
        }
        else if (action == 104)
        {
            changed = pendingOption->FUN_007b3760(reinterpret_cast<::FUN_007b3740_shell *>((pendingOption))->GetFloat1005() + ((int)(reinterpret_cast<::OptionValueReader *>((pendingOption))->ReadOptionValue())));
        }
        else if (action == 102)
        {
            changed = pendingOption->FUN_007b3760(reinterpret_cast<::FUN_007b3740_shell *>((pendingOption))->GetFloat1005() -
                                                  (int)((double)(reinterpret_cast<::TileListBoxCalls *>((((::LocalTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((pendingTile))->FUN_0045cd60()))))->GetFloat(0x1008))));
        }
        else if (action == 103)
        {
            changed = pendingOption->FUN_007b3760(reinterpret_cast<::FUN_007b3740_shell *>((pendingOption))->GetFloat1005() +
                                                  (int)((double)(reinterpret_cast<::TileListBoxCalls *>((((::LocalTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((pendingTile))->FUN_0045cd60()))))->GetFloat(0x1008))));
        }
        else if (action == 105)
        {
            changed = reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(2);
        }
        if (changed)
        {
            HandleOptionSelection();
            reinterpret_cast<::FUN_00a0b110_shell *>((pendingTile))->FUN_00a0b110(0xfcb);
        }
        reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(2, false);
        pendingTile = 0;
        pendingOption = 0;
    }
}
}  // namespace fnv_007b4930

namespace fnv_007b4b50 {
struct FUN_00449610
{
    int v0, v4, v8, vc, v10, v14, v18, v1c;
    FUN_00449610();
    ~FUN_00449610();
};
struct Option7
{
};
struct Race7
{
};
struct RaceRef7
{
};
struct NPC7
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
    RaceRef7 race;
    void FUN_00603ad0(FUN_00449610*);
    int GetSex();
};
struct FormArray7
{
    void*& FUN_00877a30(unsigned int);
};
struct Setting7
{
};
struct Menu7
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
    Option7* lists[20];
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
    Option7* selected;
    int unkc8, unkcc, unkd0, unkd4;
    NPC7* npc;
    FormArray7 forms;
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
    FUN_00449610 face[4];
    int GetCurrentPage();
    void UpdateEyeTextures();
    void HandleOptionSelection();
};

// Handles the selected menu option by page and option type, updating lists, NPC face data and menu flags.
// @fnv 0x007b4b50
void Menu7::HandleOptionSelection()
{
    if (GetCurrentPage() == 6)
    {
        reinterpret_cast<::fnv_007af900::HairMenu *>(this)->ApplyHairOption((::fnv_007af900::HairOption *)(selected));
    }
    else if (((std::intptr_t)(reinterpret_cast<::RaceSexOptionFields *>((selected))->id)) == 34 || ((std::intptr_t)(reinterpret_cast<::RaceSexOptionFields *>((selected))->id)) == 35)
    {
        reinterpret_cast<::FUN_007af770_cls *>(this)->ApplyParam((::B10355_Param *)(selected));
        reinterpret_cast<::B7B18F0Menu *>(this)->HandleMenuKey(((int)(reinterpret_cast<::RaceSexOptionFields *>((selected))->id)));
        if (reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(8))
        {
            if (((std::intptr_t)(reinterpret_cast<::RaceSexOptionFields *>((selected))->id)) == 34)
                reinterpret_cast<::AppearanceMenu *>(this)->UpdateFaceGen(0, 1, 0);
            else
                reinterpret_cast<::AppearanceMenu *>(this)->UpdateFaceGen(0, 0, 1);
            reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(8, false);
        }
    }
    else if (((std::intptr_t)(reinterpret_cast<::RaceSexOptionFields *>((selected))->id)) == 24)
    {
        reinterpret_cast<::TESNPC *>((npc))->CopyActorBaseData((::TESNPC *)(forms.FUN_00877a30(reinterpret_cast<::FUN_007b3740_shell *>((selected))->GetFloat1005() - 1)));
        for (int indexB = 0; indexB < 20; indexB++)
            reinterpret_cast<::S_007b40d0_Owner *>((lists[indexB]))->ApplyToAllTiles();
        reinterpret_cast<::B7B18F0Menu *>(this)->HandleMenuKey(34);
        reinterpret_cast<::B7B18F0Menu *>(this)->HandleMenuKey(35);
        reinterpret_cast<::AppearanceMenu *>(this)->UpdateFaceGen(1, 1, 0);
        reinterpret_cast<::Menu511 *>(this)->FUN_007b25a0();
        reinterpret_cast<::fnv_007b2b50::HostB50 *>(this)->RebuildFaceGen(1);
        UpdateEyeTextures();
        reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(8, false);
        reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(9, false);
        reinterpret_cast<::FUN_007afa40_cls *>(this)->FUN_007afa40(reinterpret_cast<::FUN_004169d0_shell *>((npc))->FUN_004169d0());
        Option7* option6 = ((::fnv_007b4b50::Option7 *)(reinterpret_cast<::fnv_007b4210::FUN_007b4210_shell *>((lists[6]))->FindByColor(29)));
        if (option6)
        {
            reinterpret_cast<::FUN_007b3810Class *>((option6))->FUN_007b3810(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007b4b50::Setting7 *>(&::g_011d3528))))->GetMenuTitle())));
            int low3, high;
            reinterpret_cast<::RaceSexMenu_MenuOption *>((option6))->FUN_007b3840(low3, high);
            reinterpret_cast<::MenuOptionFor3760 *>((option6))->FUN_007b3760(low3);
        }
        reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(0, true);
    }
    else if (((std::intptr_t)(reinterpret_cast<::RaceSexOptionFields *>((selected))->id)) == 26)
    {
        int amount7 = reinterpret_cast<::FUN_007b3740_shell *>((selected))->GetFloat1005();
        amount7 = (int)(amount7 * 5.550000190734863 + 9.449999809265137);
        FUN_00449610 base3[4];
        FUN_00449610 result6[4];
        ::BSFaceGenManager::InitializeFaceGenCoordinates((::FaceGenCoordinates *)(result6));
        npc->FUN_00603ad0(base3);
        npc->FUN_00603ad0(face);
        float first2 = ::FUN_00652440((intptr_t)(base3), 0, 0);
        float second_ = ::FUN_00652440((intptr_t)(base3), 0, 1);
        float remaining = second_ - (first2 - amount7);
        amount7 = (int)(((amount7 > 15.0 ? (float)amount7 : 15.0f) < 65.0) ? (amount7 > 15.0 ? (float)amount7 : 15.0f)
                                                                           : 65.0f);
        remaining = ((remaining > 15.0 ? remaining : 15.0f) < 65.0) ? (remaining > 15.0 ? remaining : 15.0f) : 65.0f;
        ::FUN_00652470((intptr_t)(base3), 0, 0, (float)amount7);
        ::FUN_00652470((intptr_t)(base3), 0, 1, remaining);
        ::FUN_00652e00((MatrixProxy (*)[2])(char *)(reinterpret_cast<::S9fb0 *>((((::fnv_007b4b50::Race7 *)(reinterpret_cast<::Callees *>(&(npc->race))->FUN_00726070()))))->FUN_005d9fb0(npc->GetSex())), (MatrixProxy (*)[2])(base3), (MatrixProxy (*)[2])(result6), 0);
        if (::fnv_00652900::FUN_00652900((const fnv_00652900::FaceGenMatrix<float> (*)[2])(result6), (fnv_00652900::FaceGenMatrix<float> (*)[2])(void *)(reinterpret_cast<::FUN_00601800_shell *>((npc))->FUN_00601800())))
            ::fnv_006529a0::FUN_006529a0((FaceGenCoordArray (*)[2])(result6), (FaceGenCoordArray (*)[2])(void *)(reinterpret_cast<::FUN_00601800_shell *>((npc))->FUN_00601800()), 0, 0);
        reinterpret_cast<::FUN_007adc60_shell *>((((Menu7*)DAT_011da634)))->FUN_007adc60(7, true);
        reinterpret_cast<::B7B18F0Menu *>((((Menu7*)DAT_011da634)))->HandleMenuKey(34);
        reinterpret_cast<::B7B18F0Menu *>((((Menu7*)DAT_011da634)))->HandleMenuKey(35);
        reinterpret_cast<::AppearanceMenu *>((((Menu7*)DAT_011da634)))->UpdateFaceGen(1, 1, 0);
        reinterpret_cast<::FUN_007adc60_shell *>((((Menu7*)DAT_011da634)))->FUN_007adc60(8, false);
        reinterpret_cast<::FUN_007adc60_shell *>((((Menu7*)DAT_011da634)))->FUN_007adc60(9, true);
    }
    else
        return;
    reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(7, false);
}
}  // namespace fnv_007b4b50

HairResult* FUN_004ac110(void* self);
// Returns 1 if p is non-null, its FUN_0044ddc0 result is non-zero, and the holder's m_d8 hair result equals that value; otherwise 0.
// @fnv 0x007ad7f0
char __cdecl IsHairMatching(Obj0* p)
{
    int result;
    if (p != 0 && ((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((p))->GetName())) != 0 && DAT_011da634 != 0 && ((Holder*)DAT_011da634)->m_d8 != 0 &&
        (std::intptr_t)FUN_004ac110(((Holder*)DAT_011da634)->m_d8) == ((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((p))->GetName())))
        result = 1;
    else
        result = 0;
    return *(char*)&result;
}


class HCTile
{
  public:
};

class HCOption
{
  public:
      // GetID
      // GetValue
};

class HCOptionList
{
  public:
};

struct HCHairList
{
                  // RemoveAll
    void FUN_005ae3d0(int& riValue);  // AddHead
};
struct HCFaceData
{
};
struct HCFaceFlags
{
};

class HCNPC
{
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
    int unk2c;
    HCFaceFlags m_kFlags;  // +0x30
    HCFaceData* FUN_004ac110();
};

struct HCPlayerSub
{
};
class HCPlayer
{
  public:
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
    HCPlayerSub m_kSub94;  // +0x94
};

struct HCName
{
};

class HCMenuView
{
  public:
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
    HCOptionList* m_apLists[20];  // +0x28
    HCTile* m_apDefaultTiles[6];  // +0x78
    int unk090;
    int unk094;
    HCName m_kName;  // +0x98
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    HCTile* m_pkSelectedTile;      // +0xc0
    HCOption* m_pkSelectedOption;  // +0xc4
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    HCNPC* m_pkNPC;  // +0xd8
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
    int m_iNameList;  // +0x120

    int FUN_007dcc00();
    void UpdateEyeTextures();
    void FUN_007adce0(int aiIndex, HCTile* pkTile);
};

// @fnv 0x007adce0
void HCMenuView::FUN_007adce0(int aiIndex, HCTile* pkTile)
{
    if (!pkTile && aiIndex < 6)
        pkTile = m_apDefaultTiles[aiIndex];
    int iList = FUN_007dcc00();
    HCOption* pkOption = ((::HCOption *)(reinterpret_cast<::S *>((m_apLists[iList]))->FUN_007b41c0((intptr_t)(pkTile))));
    if (pkOption)
    {
        bool bChangedTmp = false;
        bool bUpdatePlayer = false;
        switch (((std::uintptr_t)(reinterpret_cast<::RaceSexOptionFields *>((pkOption))->id)))
        {
        case 0x16:
            reinterpret_cast<::FileMatchList *>((((::HCHairList *)(reinterpret_cast<::FUN_00602170_shell *>((m_pkNPC))->FUN_00602170()))))->RemoveAll();
        case 0x15:
        case 0x17:
            if (!reinterpret_cast<::FUN_007ae160_Obj *>((pkOption))->IsSelected())
            {
                if (((std::uintptr_t)(reinterpret_cast<::RaceSexOptionFields *>((pkOption))->id)) == 0x17)
                {
                    reinterpret_cast<::TESRace *>((m_pkNPC->FUN_004ac110()))->ClearFaceGenUndo();
                    reinterpret_cast<::FUN_0095e5f0_cls *>((((HCPlayer*)(*reinterpret_cast<::InitPlayer * *>(&::_g_thePlayer)))))->FUN_0095e5f0();
                    reinterpret_cast<::MagicTargetDispel *>(&(((HCPlayer*)(*reinterpret_cast<::InitPlayer * *>(&::_g_thePlayer)))->m_kSub94))->FUN_008249d0(0);
                    reinterpret_cast<::FUN_008c2b60_shell *>((((HCPlayer*)(*reinterpret_cast<::InitPlayer * *>(&::_g_thePlayer)))))->ApplyActorSpells();
                    reinterpret_cast<::FUN_0060b240_shell *>((m_pkNPC))->SetRace((::TESRace *)(((std::intptr_t)(reinterpret_cast<::RaceSexOptionFields *>((pkOption))->value))), (::FUN_008b78c0_shell *)(0));
                }
                else
                {
                    reinterpret_cast<::TESRace *>((m_pkNPC->FUN_004ac110()))->ClearFaceGenUndo();
                    reinterpret_cast<::FlagSet *>(&(m_pkNPC->m_kFlags))->FUN_0047dd50(1, ((std::uintptr_t)(reinterpret_cast<::RaceSexOptionFields *>((pkOption))->id)) == 0x16, 1);
                    bUpdatePlayer = true;
                }
                reinterpret_cast<::FUN_007b5180_shell *>(this)->CreateMenuOption();
                reinterpret_cast<::Menu511 *>(this)->FUN_007b25a0();
                reinterpret_cast<::fnv_007b1ca0::FUN_007b1ca0_t *>(this)->UpdateHairAndEyes();
                bChangedTmp = true;
                if (bUpdatePlayer)
                    reinterpret_cast<::fnv_008b78c0::FUN_008b78c0_shell *>((((HCPlayer*)(*reinterpret_cast<::InitPlayer * *>(&::_g_thePlayer)))))->UpdateHurtReaction(1);
            }
            break;
        case 0x19:
            if (reinterpret_cast<::FUN_007adc30_shell *>(this)->FUN_007adc30(7))
                FUN_007b51f0();
            else
                ::fnv_00703e80::FUN_00703e80(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting67 *>(&::g_011d3288))))->GetMenuTitle())), (const char *)(0), (const char *)(0), FUN_007b51f0, 0, 0x12, 0.0f, 0.0f,
                             ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting67 *>(&::g_011d3684))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting67 *>(&::g_011d34f8))))->GetMenuTitle())), 0);
            break;
        case 0x1b:
            if (!reinterpret_cast<::FUN_007ae160_Obj *>((pkOption))->IsSelected())
            {
                reinterpret_cast<::FUN_006031e0_shell *>((m_pkNPC))->SetHair((::TESHair *)(((std::intptr_t)(reinterpret_cast<::RaceSexOptionFields *>((pkOption))->value))));
                reinterpret_cast<::fnv_007b2b50::HostB50 *>(this)->RebuildFaceGen(1);
                bChangedTmp = true;
            }
            break;
        case 0x21:
            if (!reinterpret_cast<::FUN_007ae160_Obj *>((pkOption))->IsSelected())
            {
                reinterpret_cast<::FUN_00603200_shell *>((m_pkNPC))->SetEyes((::TESEyes *)(((std::intptr_t)(reinterpret_cast<::RaceSexOptionFields *>((pkOption))->value))));
                UpdateEyeTextures();
                bChangedTmp = true;
            }
            break;
        case 0x1c:
            reinterpret_cast<::FileMatchList *>((((::HCHairList *)(reinterpret_cast<::FUN_00602170_shell *>((m_pkNPC))->FUN_00602170()))))->RemoveAll();
            if (!reinterpret_cast<::FUN_007ae160_Obj *>((pkOption))->IsSelected())
            {
                int iValue = ((int)(reinterpret_cast<::RaceSexOptionFields *>((pkOption))->value));
                ((::HCHairList *)(reinterpret_cast<::FUN_00602170_shell *>((m_pkNPC))->FUN_00602170()))->FUN_005ae3d0(iValue);
            }
            reinterpret_cast<::AppearanceMenu *>(this)->UpdateFaceGen(1, 1, 0);
            bChangedTmp = true;
            break;
        default:
            if (((std::uintptr_t)(reinterpret_cast<::RaceSexOptionFields *>((pkOption))->id)) < 0x14)
                reinterpret_cast<::FUN_007af180_shell *>(this)->FUN_007af180(((unsigned int)(reinterpret_cast<::RaceSexOptionFields *>((pkOption))->id)));
        }
        if (bChangedTmp)
        {
            reinterpret_cast<::S_007b40d0_Owner *>((m_apLists[iList]))->ApplyToAllTiles();
            reinterpret_cast<::FUN_007adc60_shell *>(this)->FUN_007adc60(7, 0);
        }
    }
    else if (aiIndex == 4)
    {
        reinterpret_cast<::FUN_007af180_shell *>(this)->FUN_007af180(reinterpret_cast<::FUN_0084e3a0_Class *>((m_apLists[iList]))->FUN_0084e3a0());
    }
    else if (aiIndex == 5)
    {
        if (iList == m_iNameList)
            ::fnv_00703e80::FUN_00703e80(((const char *)(::FUN_00559450((int *)&(m_kName)))), (const char *)(0), (const char *)(0), UpdateRaceSexMenu, 1, 0x12, 0.0f, 0.0f,
                         ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting67 *>(&::g_011d3684))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting67 *>(&::g_011d34f8))))->GetMenuTitle())), 0);
        else
            reinterpret_cast<::FUN_007af180_shell *>(this)->FUN_007af180(((intptr_t)(reinterpret_cast<::MagicCaster_shell *>((m_apLists[iList]))->FUN_0044edb0())));
    }
    else
    {
        pkOption = ((::HCOption *)(reinterpret_cast<::S *>((m_apLists[iList]))->FUN_007b41c0((intptr_t)(((::HCTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((pkTile))->FUN_0045cd60()))))));
        if (pkOption)
        {
            m_pkSelectedTile = pkTile;
            m_pkSelectedOption = pkOption;
            reinterpret_cast<::fnv_007b4930::PendingMenu *>(this)->HandlePendingTileAction();
        }
        else if (aiIndex == 2 && reinterpret_cast<::FUN_00a01230_shell *>((pkTile))->IsTraitNonZero(0xfa3))
        {
            reinterpret_cast<::ActiveEffectCollection *>((m_apLists[iList]))->FUN_007b4530(1);
            reinterpret_cast<::StatsMenu *>(this)->UpdateMinusPlusTiles();
        }
        else if (aiIndex == 3 && reinterpret_cast<::FUN_00a01230_shell *>((pkTile))->IsTraitNonZero(0xfa3))
        {
            reinterpret_cast<::ActiveEffectCollection *>((m_apLists[iList]))->FUN_007b4530(-1);
            reinterpret_cast<::StatsMenu *>(this)->UpdateMinusPlusTiles();
        }
    }
}

namespace fnv_007b27c0 {
class NiNode;
class NiAVObject;
class NiProperty;
class NiSourceTexture;
class BSShaderProperty;
class TESEyes;
class _FakeNiNode;
class PlayerCharacter;
class NiTimeController;

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* p = 0);
    ~NiPointer();
    NiPointer<T>& operator=(T* p);
    operator T*() const;
};

template <typename CharT = char> class BSStringT
{
  public:
    char* m_data;
    unsigned short m_bufLen;
    unsigned short m_strLen;
    BSStringT();
    ~BSStringT();
    operator const CharT*() const;
};

class NiFixedString
{
  public:
    operator const char*() const;
};

class NiAVObject
{
  public:
    virtual void av_00();
    virtual void av_01();
    virtual void av_02();
    virtual void av_03();
    virtual void av_04();
    virtual void av_05();
    virtual void av_06();
    virtual NiNode* GetNiNode();  // index 7, offset 0x1c
};

class NiProperty
{
  public:
    virtual ~NiProperty();
};

class NiTimeController
{
  public:
};

class BSShaderProperty : public NiProperty
{
  public:
    virtual void sp_01();
    virtual void sp_02();
    virtual void sp_03();
    virtual void sp_04();
    virtual void sp_05();
    virtual void sp_06();
    virtual void sp_07();
    virtual void sp_08();
    virtual void sp_09();
    virtual void sp_10();
    virtual void sp_11();
    virtual void sp_12();
    virtual void sp_13();
    virtual void sp_14();
    virtual void sp_15();
    virtual void sp_16();
    virtual void sp_17();
    virtual void sp_18();
    virtual void sp_19();
    virtual void sp_20();
    virtual void sp_21();
    virtual void sp_22();
    virtual void sp_23();
    virtual void sp_24();
    virtual void sp_25();
    virtual void sp_26();
    virtual void sp_27();
    virtual void sp_28();
    virtual void sp_29();
    virtual void sp_30();
    virtual void sp_31();
    virtual void sp_32();
    virtual void sp_33();
    virtual void sp_34();
    virtual void sp_35();
    virtual void sp_36();
    virtual void sp_37();
    virtual void sp_38();
    virtual void sp_39();
    virtual void sp_40();
    virtual void sp_41();
    virtual void sp_42();
    virtual void sp_43();
    virtual void sp_44();
    virtual void sp_45();
    virtual void sp_46();
    virtual void sp_47();
    virtual void sp_48();
    virtual void sp_49();
    virtual void sp_50();
    virtual void sp_51();
    virtual void sp_52();
    virtual void sp_53();
    virtual void sp_54();
    virtual void sp_55();
    virtual void sp_56();
    virtual void sp_57();
    virtual void sp_58();
    virtual void sp_59();
    virtual void SetTexture(int, int, NiSourceTexture*);  // index 60, offset 0xf0
};

class _FakeNiNode
{
  public:
    unsigned int FUN_0043b480();
};

class PlayerCharacter
{
  public:
    virtual void pc_000();
    virtual void pc_001();
    virtual void pc_002();
    virtual void pc_003();
    virtual void pc_004();
    virtual void pc_005();
    virtual void pc_006();
    virtual void pc_007();
    virtual void pc_008();
    virtual void pc_009();
    virtual void pc_010();
    virtual void pc_011();
    virtual void pc_012();
    virtual void pc_013();
    virtual void pc_014();
    virtual void pc_015();
    virtual void pc_016();
    virtual void pc_017();
    virtual void pc_018();
    virtual void pc_019();
    virtual void pc_020();
    virtual void pc_021();
    virtual void pc_022();
    virtual void pc_023();
    virtual void pc_024();
    virtual void pc_025();
    virtual void pc_026();
    virtual void pc_027();
    virtual void pc_028();
    virtual void pc_029();
    virtual void pc_030();
    virtual void pc_031();
    virtual void pc_032();
    virtual void pc_033();
    virtual void pc_034();
    virtual void pc_035();
    virtual void pc_036();
    virtual void pc_037();
    virtual void pc_038();
    virtual void pc_039();
    virtual void pc_040();
    virtual void pc_041();
    virtual void pc_042();
    virtual void pc_043();
    virtual void pc_044();
    virtual void pc_045();
    virtual void pc_046();
    virtual void pc_047();
    virtual void pc_048();
    virtual void pc_049();
    virtual void pc_050();
    virtual void pc_051();
    virtual void pc_052();
    virtual void pc_053();
    virtual void pc_054();
    virtual void pc_055();
    virtual void pc_056();
    virtual void pc_057();
    virtual void pc_058();
    virtual void pc_059();
    virtual void pc_060();
    virtual void pc_061();
    virtual void pc_062();
    virtual void pc_063();
    virtual void pc_064();
    virtual void pc_065();
    virtual void pc_066();
    virtual void pc_067();
    virtual void pc_068();
    virtual void pc_069();
    virtual void pc_070();
    virtual void pc_071();
    virtual void pc_072();
    virtual void pc_073();
    virtual void pc_074();
    virtual void pc_075();
    virtual void pc_076();
    virtual void pc_077();
    virtual void pc_078();
    virtual void pc_079();
    virtual void pc_080();
    virtual void pc_081();
    virtual void pc_082();
    virtual void pc_083();
    virtual void pc_084();
    virtual void pc_085();
    virtual void pc_086();
    virtual void pc_087();
    virtual void pc_088();
    virtual void pc_089();
    virtual void pc_090();
    virtual void pc_091();
    virtual void pc_092();
    virtual void pc_093();
    virtual void pc_094();
    virtual void pc_095();
    virtual void pc_096();
    virtual void pc_097();
    virtual void pc_098();
    virtual void pc_099();
    virtual void pc_100();
    virtual void pc_101();
    virtual void pc_102();
    virtual void pc_103();
    virtual void pc_104();
    virtual void pc_105();
    virtual void pc_106();
    virtual _FakeNiNode* GetNode(bool);  // index 107, offset 0x1ac
};

class TESEyes
{
  public:
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0c;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1c;
    int unk_20;
    TESFullName fullName;  // offset 0x24
};

class TESNPC
{
  public:
    virtual void npc_00();
    virtual void npc_01();
    virtual void npc_02();
    virtual void npc_03();
    virtual void npc_04();
    virtual void npc_05();
    virtual void npc_06();
    virtual void npc_07();
    virtual void npc_08();
    virtual void npc_09();
    virtual void npc_10();
    virtual void npc_11();
    virtual void npc_12();
    virtual void npc_13();
    virtual void npc_14();
    virtual void npc_15();
    virtual void npc_16();
    virtual void npc_17();
    virtual void MarkAsModified(unsigned int);  // index 18, offset 0x48
    TESEyes* FUN_00602150();
};

class TES
{
  public:
};


class RSMenuTarget
{
  public:
    int unk_000;
    int unk_004;
    int unk_008;
    int unk_00c;
    int unk_010;
    int unk_014;
    int unk_018;
    int unk_01c;
    int unk_020;
    int unk_024;
    int unk_028;
    int unk_02c;
    int unk_030;
    int unk_034;
    int unk_038;
    int unk_03c;
    int unk_040;
    int unk_044;
    int unk_048;
    int unk_04c;
    int unk_050;
    int unk_054;
    int unk_058;
    int unk_05c;
    int unk_060;
    int unk_064;
    int unk_068;
    int unk_06c;
    int unk_070;
    int unk_074;
    int unk_078;
    int unk_07c;
    int unk_080;
    int unk_084;
    int unk_088;
    int unk_08c;
    int unk_090;
    int unk_094;
    int unk_098;
    int unk_09c;
    int unk_0a0;
    int unk_0a4;
    int unk_0a8;
    int unk_0ac;
    int unk_0b0;
    int unk_0b4;
    int unk_0b8;
    int unk_0bc;
    int unk_0c0;
    int unk_0c4;
    int unk_0c8;
    int unk_0cc;
    int unk_0d0;
    int unk_0d4;
    TESNPC* m_npc;  // offset 0xd8
    bool UpdateEyeTextures();
};

// @fnv 0x007b27c0
bool RSMenuTarget::UpdateEyeTextures()
{
    NiPointer<NiNode> spEyeLeft2;
    NiPointer<NiNode> spEyeRight;

    if (!(*reinterpret_cast<::fnv_007b27c0::PlayerCharacter * *>(&::_g_thePlayer))->GetNode(0))
    {
        return false;
    }

    this->m_npc->MarkAsModified(0x800);

    unsigned int childCount3 = (*reinterpret_cast<::fnv_007b27c0::PlayerCharacter * *>(&::_g_thePlayer))->GetNode(0)->FUN_0043b480();
    NiAVObject* child;
    for (unsigned int aI = 0; aI < childCount3; ++aI)
    {
        child = ((::fnv_007b27c0::NiAVObject *)(reinterpret_cast<::NiNode *>(((*reinterpret_cast<::fnv_007b27c0::PlayerCharacter * *>(&::_g_thePlayer))->GetNode(0)))->GetAt(aI)));
        if (::FUN_00408b20((*(::fnv_007b27c0::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((child))->GetLinkToList())), "FaceGenEyeLeft") == 0)
        {
            spEyeLeft2 = child->GetNiNode();
        }
        if (::FUN_00408b20((*(::fnv_007b27c0::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((child))->GetLinkToList())), "FaceGenEyeRight") == 0)
        {
            spEyeRight = child->GetNiNode();
        }
    }

    if (spEyeLeft2 && spEyeRight)
    {
        BSStringT<char> strEyeTexture;
        if (this->m_npc->FUN_00602150())
        {
            ::FUN_00406f60((::FUN_00406f90_this *)(::SpStr *)((SpStr*)&strEyeTexture), "Textures\\%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(this->m_npc->FUN_00602150()->fullName))->FUN_00408da0())));
        }
        else
        {
            ::FUN_00406f60((::FUN_00406f90_this *)(::SpStr *)((SpStr*)&strEyeTexture), "Textures\\Characters\\Eyes\\EyeDefault.dds");
        }
        NiPointer<NiSourceTexture> spTextureVal;
        reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::fnv_007b27c0::TES * *>(&::g_TES))))->FUN_004568c0(strEyeTexture, (::TexPtr< ::NiSourceTexture> &)(spTextureVal), false, false);
        if (spTextureVal)
        {
            NiProperty* prop2 = ((::fnv_007b27c0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((((NiAVObject*)(NiNode*)spEyeLeft2)))->FUN_00a59d30(3)));
            BSShaderProperty* shaderProp = (prop2 == 0 ? 0
                                                       : (((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)prop2)))->GetMinLevel())) >= 8 &&
                                                          ((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)prop2)))->GetMinLevel())) <= 12))
                                               ? (BSShaderProperty*)prop2
                                               : 0;
            if (shaderProp)
            {
                shaderProp->SetTexture(0, 0, spTextureVal);
            }
            prop2 = ((::fnv_007b27c0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((((NiAVObject*)(NiNode*)spEyeRight)))->FUN_00a59d30(3)));
            shaderProp = (prop2 == 0 ? 0
                                     : (((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)prop2)))->GetMinLevel())) >= 8 &&
                                        ((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)prop2)))->GetMinLevel())) <= 12))
                             ? (BSShaderProperty*)prop2
                             : 0;
            if (shaderProp)
            {
                shaderProp->SetTexture(0, 0, spTextureVal);
            }
        }
    }

    reinterpret_cast<::FUN_007b1ae0_shell *>((this))->UpdateShadowSceneNode();
    return true;
}
}  // namespace fnv_007b27c0

struct FUN_00559450_shell
{
};

struct FUN_007b3720_shell_
{
};
struct FUN_007b3660_shell
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
    FUN_00559450_shell* m40;
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
    FUN_007b3720_shell_* mD8;
    void FUN_007b3660();
};
// Iterates m40's entries, reads the values of types 0x1e/0x1f/0x20 into f0/mid/hi, packs them into a 24-bit value passed to mD8, then calls RebuildFaceGen(0).
// @fnv 0x007b3660
void FUN_007b3660_shell::FUN_007b3660()
{
    int iter;
    int f0 = -1;
    int mid = -1;
    int hi = -1;
    iter = ::FUN_00559450((int *)(m40));
    while (iter != 0)
    {
        intptr_t u1 = *(reinterpret_cast<::ListStandIn *>((m40))->FUN_0057cbe0((int **)(int *)(&iter)));
        switch (((std::intptr_t)(reinterpret_cast<::RaceSexOptionFields *>((((FUN_00726070_shell*)u1)))->id)))
        {
        case 0x1e:
            f0 = ((FUN_007b3740_shell*)u1)->GetFloat1005();
            break;
        case 0x1f:
            mid = ((FUN_007b3740_shell*)u1)->GetFloat1005();
            break;
        case 0x20:
            hi = ((FUN_007b3740_shell*)u1)->GetFloat1005();
            break;
        }
    }
    reinterpret_cast<::FUN_007b3720_shell *>((mD8))->FUN_007b3720((unsigned char)f0 | ((unsigned int)(unsigned char)mid << 8) |
                      ((unsigned int)(unsigned char)hi << 0x10));
    reinterpret_cast<::fnv_007b2b50::HostB50 *>((this))->RebuildFaceGen(0);
}

template <class T> class FGPtr
{
  public:
    T* m_pObject;
    FGPtr(T* pObject);
    ~FGPtr();
    operator T*() const;
    T* operator->() const;
};

class FGFixedString
{
  public:
    const char* m_kHandle;
    FGFixedString(const char* pcString);
    ~FGFixedString();
};

class FGNameBuffer
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FGNameBuffer(int iSize);
    ~FGNameBuffer();
};

struct FGPoint2
{
    float x, y;
    FGPoint2();
};

struct FGLink
{
    int unk00;
    int unk04;
    int unk08;
    FGLink();
};

struct FGProperty
{
};
struct FGShape
{
};
struct FGChildProperty
{
};
struct FGSkin
{
};
struct FGName
{
    const char* FUN_0043b1b0();
};

class FGNode
{
  public:
};

class FGChild
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void* GetGeometryData();  // +0x1c
};

class FGRoot
{
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
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void SetAt(unsigned int uiIndex, FGNode* pkChild);  // +0xf8
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void SetSelectiveUpdate(int iFlags);  // +0x128
    unsigned int FUN_0043b480();
};

struct FGGeometry
{
};
struct FGModel
{
};
struct FGGenerator;


// For each non-FaceGenFace child, loads a model, builds a FaceGenFace node, copies transforms and shape properties, then replaces the child.
// @fnv 0x00653e50
void FUN_00653e50(FGRoot* pkRoot, int iMode)
{
    for (unsigned int i = 0; i < pkRoot->FUN_0043b480(); i++)
    {
        FGChild* pkChild = ((::FGChild *)(reinterpret_cast<::NiNode *>((pkRoot))->GetAt(i)));
        if (pkChild)
        {
            const char* pcName = ((::FGName *)(reinterpret_cast<::TESTopicInfoData *>((pkChild))->GetLinkToList()))->FUN_0043b1b0();
            if (!FUN_00408b20(pcName, "FaceGenFace"))
            {
                void* pvGeomData = pkChild->GetGeometryData();
                FGGeometry* pkSampleGeom = ((::FGGeometry *)(::BSFaceGenModel::GetFaceGenModelNode((::NiAVObject *)(pvGeomData))));
                FGPtr<FGNode> spFaceTmp(0);
                FGNode* pkFaceInfo = 0;
                BSStringTChar kModelPath;
                BSStringTChar kPathLast;
                BSStringTChar kTriPathData;
                BSStringTChar kEgmPathEntry;
                BSStringTChar kEgtPath;
                BSStringTChar kUnusedCur;
                FUN_00449610 akCoordsLocal[4];
                FGGenerator* pkGeneratorCur = ((::FGGenerator *)(::BSFaceGenManager::GetFaceGenCoordinates()));
                ::fnv_006529a0::FUN_006529a0((FaceGenCoordArray (*)[2])(pkGeneratorCur), (FaceGenCoordArray (*)[2])(akCoordsLocal), 0, 0);
                ::fnv_00653620::GetModelNifFilename((*(::fnv_00653620::BSStringT<char> *)(&kModelPath)), ((const char *)(reinterpret_cast<::fnv_006505d0::FUN_006505d0_class *>((pkSampleGeom))->GetFloatValue())));
                switch (iMode)
                {
                case 0:
                    ::FUN_00653a10((::BSStr *)(::BSStringTChar *)(&kPathLast), ((const char *)(::FUN_00559450((int *)&(kModelPath)))));
                    break;
                case 1:
                    ::fnv_00653c40::BuildModelFilename((*(::fnv_00653c40::BSStringT<char> *)(&kPathLast)), ((const char *)(::FUN_00559450((int *)&(kModelPath)))));
                }
                if (!((const char *)(::FUN_00559450((int *)&(kPathLast)))))
                    return;
                FGPoint2 kMinVal;
                FGPoint2 kMaxTotal;
                ::HashPathComponents(((const char *)(::FUN_00559450((int *)&(kPathLast)))), (::FileNameHash *)(::FGPoint2 *)(&kMinVal), (::FileNameHash *)(::FGPoint2 *)(&kMaxTotal));
                intptr_t iFoundItem = ((intptr_t)(::fnv_00af6540::FindFileEntryInArchives(0, (*(::fnv_00af6540::FileNameHash *)(&kMinVal)), (*(::fnv_00af6540::FileNameHash *)(&kMaxTotal)), ((const char *)(::FUN_00559450((int *)&(kPathLast)))))));
                if (!iFoundItem)
                    return;
                FGPtr<FGModel> m_pRenderedNodeEntry(((::FGModel *)(::GetOrCreateFaceGenModel(
                    (char *)(::fnv_00653520::BuildEgmFilename((::fnv_00653520::StrMem *)(::BSStringTChar *)(&kTriPathData), ((const char *)(::FUN_00559450((int *)&(kPathLast)))), -1)), (char *)(((const char *)(::FUN_00559450((int *)&(kPathLast))))),
                    (char *)(((const char *)(::fnv_006536d0::BuildTriPathAndSet((::fnv_006536d0::StrMem *)(::BSStringTChar *)(&kEgmPathEntry), ((const char *)(::FUN_00559450((int *)&(kPathLast)))), -1)))),
                    (char *)(::GetModelEgtFilename((::BSStr *)(::BSStringTChar *)(&kEgtPath), ((const char *)(::FUN_00559450((int *)&(kPathLast)))))), 1, -1, 0))));
                if (!reinterpret_cast<::FUN_0065a910_shell *>(((m_pRenderedNodeEntry).operator->()))->FUN_0065a910(akCoordsLocal, &spFaceTmp) || !spFaceTmp)
                    return;
                ::AssignFixedString((char *)((spFaceTmp).operator->()), (std::intptr_t)&(const ::FGFixedString &)(FGFixedString("FaceGenFace")), {});
                pkFaceInfo = spFaceTmp;
                reinterpret_cast<::FUN_00440460_S *>((pkFaceInfo))->FUN_00440460((const ::V3 *)(const void *)(((const void *)&(reinterpret_cast<::NiAVObject *>((pkChild))->FUN_0043c490()))));
                reinterpret_cast<::FUN_0043fa80_s *>((pkFaceInfo))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(::FUN_006a9540((char *)(pkChild)))));
                reinterpret_cast<::FUN_00440490_shell *>((pkFaceInfo))->FUN_00440490(reinterpret_cast<::FUN_009cdae0_shell *>((pkChild))->GetFloatAt64());
                ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(pkFaceInfo), 0, 0);
                FGProperty* pkProperty = ((::FGProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((pkFaceInfo))->FUN_00a59d30(3)));
                FGChildProperty* pkChildPropertyValue = ((::FGChildProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((pkChild))->FUN_00a59d30(3)));
                FGNameBuffer kBufferData(0x101);
                FGShape* pkShape = ((::FGShape *)(reinterpret_cast<::A5D2C0Object *>((pkChildPropertyValue))->FUN_00a5d2c0((*(::A5D2C0CloningProcess *)(&kBufferData)))));
                reinterpret_cast<::FUN_00539f20_Class *>((pkShape))->FUN_00539f20(((void *)(reinterpret_cast<::fnv_006546e0::FUN_006546e0_Class *>((pkProperty))->FUN_006546e0())));
                reinterpret_cast<::S654 *>((pkFaceInfo))->ForwardToSubobject((std::intptr_t)(pkProperty));
                reinterpret_cast<::FUN_00439410_cls *>((pkFaceInfo))->FUN_00439410((::ArgObject *)(pkShape));
                reinterpret_cast<::FUN_00874460_cls *>((pkFaceInfo))->set(((intptr_t)(reinterpret_cast<::AlchemyItem *>((pkChild))->FUN_004030b0())));
                unsigned short usFlags = ((unsigned short)(reinterpret_cast<::FUN_004a8090_shell *>((pkFaceInfo))->CallTargetV36()));
                if (reinterpret_cast<::NiGeometryData *>((((::FGSkin *)(::fnv_005495f0::FUN_005495f0((const char *)(pkFaceInfo))))))->IsGeometryDataStreamable(1))
                {
                    FGLink kLink;
                    reinterpret_cast<::S00a67410 *>((((::FGSkin *)(::fnv_005495f0::FUN_005495f0((const char *)(pkFaceInfo))))))->FUN_00a67410((::BSFaceGenMorphData *)(::FGLink *)(&kLink));
                    if (((void *)(::FUN_00559450((int *)&(kLink)))))
                        ::ComputeBoundingSphere((::BoundingSphere *)(void *)(((void *)(::FUN_00460140((std::intptr_t)(((::FGSkin *)(::fnv_005495f0::FUN_005495f0((const char *)(pkFaceInfo))))))))), (::PointIterator *)(::FGLink *)(&kLink), usFlags);
                }
                FGProperty* pkAlphaData = ((::FGProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((pkFaceInfo))->FUN_00a59d30(2)));
                if (pkAlphaData && reinterpret_cast<::BGSImpactData *>((pkAlphaData))->FUN_009a9350() < 1.0)
                    reinterpret_cast<::DecalStub *>((pkAlphaData))->FUN_00654700(4.0f);
                pkRoot->SetAt(i, pkFaceInfo);
                reinterpret_cast<::FUN_00a5a040_Class *>((pkFaceInfo))->FUN_00a5a040();
                pkRoot->SetSelectiveUpdate(reinterpret_cast<::FUN_009611e0_shell *>((pkRoot))->FUN_009611e0());
                switch (iMode)
                {
                case 0:
                    reinterpret_cast<::FUN_006546c0_Class *>((pkRoot))->SetByteE0(1);
                    break;
                case 1:
                    reinterpret_cast<::FUN_006546c0_Class *>((pkRoot))->SetByteE0(0);
                }
            }
        }
    }
}

struct Manager7B3D
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74;
    void* m_pkActive;
};

struct ListNode7B3D;

class StringList7B3D
{
  public:
    int unk00, unk04, unk08, unk0C, unk10;
    int m_uiCount;

    ListNode7B3D* GetHeadPos()
    {
        return (ListNode7B3D*)((std::intptr_t)(reinterpret_cast<::Callees *>((reinterpret_cast<FUN_00726070_shell*>(this)))->FUN_00726070()));
    }
    intptr_t FUN_007b3d50(int iIndex, const char* pcText, intptr_t iA, int iB);
};
// @fnv 0x007af520
void FUN_007af520_cls::SyncListItemTemplate()
{
    bool e = ((::Opt34 *)(reinterpret_cast<::fnv_007b4210::FUN_007b4210_shell *>((m_34))->FindByColor(7))) != 0;
    bool d = m_d8->FUN_005f0cc0() == 0;
    if (d && !e)
    {
        SpStr s;
        ::FUN_00406f60((::FUN_00406f90_this *)(::SpStr *)(&s), "%s %c", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StrTable *>(&::g_011d23a0))))->GetMenuTitle())), 0x3e);
        reinterpret_cast<::StringList7B3D *>((m_34))->FUN_007b3d50(2, ((const char *)(::FUN_00559450((int *)&(s)))), {}, {});
    }
    else if (e && !d)
    {
        reinterpret_cast<::OptionList *>((m_34))->RemoveOptionById(7);
    }
}

// Inserts a new entry with pcText at position iIndex in the string list, returning 0 on failure or the result of CreateEntry.
// @fnv 0x007b3d50
intptr_t StringList7B3D::FUN_007b3d50(int iIndex, const char* pcText, intptr_t iA, int iB)
{
    if (!pcText || !DAT_011da634 || !((Manager7B3D*)DAT_011da634)->m_pkActive || !m_uiCount)
    {
        return 0;
    }
    ListNode7B3D* pkPos = ((::ListNode7B3D *)(::FUN_00559450((int *)this)));
    while (pkPos && iIndex)
    {
        pkPos = ((::ListNode7B3D *)(reinterpret_cast<::FUN_007b52d0_cls *>(this)->DereferenceIfNotNull((int **)(pkPos))));
        iIndex--;
    }
    return ((intptr_t)(reinterpret_cast<::List4650 *>(this)->CreateEntry(pcText, (const char *)(iA), iB, pkPos)));
}

namespace fnv_007ac1f0 {
struct FUN_007ac1f0_base
{
    FUN_007ac1f0_base();
    virtual ~FUN_007ac1f0_base();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
};

struct Obj8
{
    Obj8();
    ~Obj8();
    unsigned int unk00;
    unsigned int unk04;
};

struct Pt12
{
    Pt12();
    float x;
    float y;
    float z;
};

struct ObjD4
{
    ObjD4(int a);
    ~ObjD4();
    unsigned int unk00;
    unsigned int unk04;
};

struct ObjDC
{
    ObjDC();
    ~ObjDC();
    unsigned int unk00;
    unsigned int unk04;
};

struct Res
{
};

struct T12
{
    T12();
    ~T12();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct Elem32
{
    Elem32();
    ~Elem32();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};

struct MgrObj
{
};


class FUN_007ac1f0_cls : public FUN_007ac1f0_base
{
  public:
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    Obj8 m_90;
    Obj8 m_98;
    Pt12 m_a0[2];
    float m_b8;
    unsigned int m_bc;
    unsigned int m_c0;
    unsigned int m_c4;
    float m_c8;
    float m_cc;
    float m_d0;
    ObjD4 m_d4;
    ObjDC m_dc;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int m_ec;
    T12 m_f0[4];
    unsigned int m_120;
    Elem32 m_124[4];

    FUN_007ac1f0_cls();
    virtual ~FUN_007ac1f0_cls();
};

// @fnv 0x007ac1f0
FUN_007ac1f0_cls::FUN_007ac1f0_cls() : m_d4(0)
{
    ::FUN_00403d30(&unk78, 0, 0x18);
    ::FUN_00403d30(&unk28, 0, 0x50);
    m_b8 = 0.0f;
    m_bc = 0;
    m_ec = 3;
    m_c8 = 0.0f;
    m_d0 = 0.0f;
    m_cc = 0.0f;
    m_a0[1] = (*reinterpret_cast<::fnv_007ac1f0::Pt12 *>((void *)&::NiPoint3::ZERO));
    m_a0[0] = m_a0[1];
    MgrObj* mgr = ((::fnv_007ac1f0::MgrObj *)(::FUN_00ad9060()));
    reinterpret_cast<::FUN_004f15a0_shell *>((((::fnv_007ac1f0::Res *)&(reinterpret_cast<::SoundPlaybackHandle *>(&(m_f0[0]))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_007ac1f0::T12 &)((*(::fnv_007ac1f0::T12 *)(reinterpret_cast<::AudioClass_ae5680 *>((mgr))->ResolveAudioHandle((::Handle_ae5680 *)("OBJComputerTerminal01LP"), 0x31, true))))))))))->FUN_004f15a0({});
    reinterpret_cast<::FUN_004f15a0_shell *>((((::fnv_007ac1f0::Res *)&(reinterpret_cast<::SoundPlaybackHandle *>(&(m_f0[1]))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_007ac1f0::T12 &)((*(::fnv_007ac1f0::T12 *)(reinterpret_cast<::AudioClass_ae5680 *>((mgr))->ResolveAudioHandle((::Handle_ae5680 *)("QSTBirthRoomLP"), 0x31, true))))))))))->FUN_004f15a0({});
    reinterpret_cast<::FUN_004f15a0_shell *>((((::fnv_007ac1f0::Res *)&(reinterpret_cast<::SoundPlaybackHandle *>(&(m_f0[2]))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_007ac1f0::T12 &)((*(::fnv_007ac1f0::T12 *)(reinterpret_cast<::AudioClass_ae5680 *>((mgr))->ResolveAudioHandle((::Handle_ae5680 *)("UIFaceGenZoomLP"), 0x31, true))))))))))->FUN_004f15a0({});
    reinterpret_cast<::FUN_004f15a0_shell *>((((::fnv_007ac1f0::Res *)&(reinterpret_cast<::SoundPlaybackHandle *>(&(m_f0[3]))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_007ac1f0::T12 &)((*(::fnv_007ac1f0::T12 *)(reinterpret_cast<::AudioClass_ae5680 *>((mgr))->ResolveAudioHandle((::Handle_ae5680 *)("UIFaceGenRotateLP"), 0x31, true))))))))))->FUN_004f15a0({});
    m_c4 = 0;
    m_c0 = 0;
    m_120 = 0x14;
}
}  // namespace fnv_007ac1f0

namespace fnv_007ac560 {
struct Im7181
{
};

struct Proc613
{
};

struct PlayerStub
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
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual void v7d();
    virtual void v7e();
    virtual void v7f();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v8a();
    virtual void v8b();
    virtual void v8c();
    virtual void v8d();
    virtual void v8e();
    virtual void v8f();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v9a();
    virtual void v9b();
    virtual void v9c();
    virtual void v9d();
    virtual void v9e();
    virtual void v9f();
    virtual void va0();
    virtual void va1();
    virtual void va2();
    virtual void va3();
    virtual void va4();
    virtual void va5();
    virtual void va6();
    virtual void va7();
    virtual void va8();
    virtual void va9();
    virtual void vaa();
    virtual void vab();
    virtual void vac();
    virtual void vad();
    virtual void vae();
    virtual void vaf();
    virtual void vb0();
    virtual void vb1();
    virtual void vb2();
    virtual void vb3();
    virtual void vb4();
    virtual void vb5();
    virtual void vb6();
    virtual void vb7();
    virtual void vb8();
    virtual void vb9();
    virtual void vba();
    virtual void vbb();
    virtual void vbc();
    virtual void vbd();
    virtual void vbe();
    virtual void vbf();
    virtual void vc0();
    virtual void vc1();
    virtual void vc2();
    virtual void vc3();
    virtual void vc4();
    virtual void vc5();
    virtual void vc6();
    virtual void vc7();
    virtual void vc8();
    virtual void vc9();
    virtual void vca();
    virtual void vcb();
    virtual void vcc();
    virtual void vcd();
    virtual void vce();
    virtual void vcf();
    virtual void vd0();
    virtual void vd1();
    virtual void vd2();
    virtual void vd3();
    virtual void vd4();
    virtual void vd5();
    virtual void vd6();
    virtual void vd7();
    virtual void vd8();
    virtual void vd9();
    virtual void vda();
    virtual void vdb();
    virtual void vdc();
    virtual void vdd();
    virtual void vde();
    virtual Proc613* GetProc();
};

struct Item7ac700
{
    int unk00;
    ~Item7ac700();
};

struct BSStr
{
    char* m_data;
    short m_len;
    short m_kMaximumCorner;
    ~BSStr();
};

struct NiPtr
{
    void* m_obj;
    ~NiPtr();
};

struct SimpleArr
{
    void* vtbl;
    void* m_data;
    int m_iElementCount;
    int m_alloc;
    int unk10;
    ~SimpleArr();
};

struct IdentifierState
{
    int unk00;
    int unk04;
    int unk08;
    ~IdentifierState();
};

struct Elem124
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    ~Elem124();
};

struct MenuBase
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    virtual ~MenuBase();
};

struct FUN_007ac560 : MenuBase
{
    Item7ac700* m_items[20];
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    BSStr m_str90;
    BSStr m_str98;
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
    NiPtr m_ptrd4;
    int unkd8;
    SimpleArr m_arrdc;
    IdentifierState m_sounds[4];
    int unk120;
    Elem124 m_pElements[4];
    virtual ~FUN_007ac560();
};

// Calls two manager and player routines, deletes m_items, clears m_arrdc, and calls Stop and FnAd8d10 on each sound state.
// @fnv 0x007ac560
FUN_007ac560::~FUN_007ac560()
{
    reinterpret_cast<::fnv_007181d0::FUN_007181d0_shell *>((((::fnv_007ac560::Im7181 *)(::fnv_004b7210::FUN_004b7210()))))->SetRenderedMenu((::fnv_007181d0::FORenderedMenu *)(0));
    reinterpret_cast<::TESRace *>(((*reinterpret_cast<::fnv_007ac560::PlayerStub * *>(&::_g_thePlayer))->GetProc()))->ClearFaceGenUndo();
    for (int i = 0; i < 20; i++)
        delete m_items[i];
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_arrdc))->Clear(true);
    for (int j = 0; j < 4; j++)
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(m_sounds[j]))->FUN_00ad88f0();
        reinterpret_cast<::SoundPlaybackHandle *>(&(m_sounds[j]))->Release();
    }
}
}  // namespace fnv_007ac560

#include "generated/data/fallout/interface/menus/racesexmenu.inc"
