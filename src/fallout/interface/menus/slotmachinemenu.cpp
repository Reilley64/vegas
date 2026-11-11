
// src/fallout/interface/menus/slotmachinemenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/slotmachinemenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/simple_list_node_view.h"
#include "fnv/game_timer.h"
#include <cstdint>
#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/ActorValueOwner.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatState.h"
#include "fnv/decl/ContainerOperation.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_00504e00_shell.h"
#include "fnv/decl/FUN_00504e20_shell.h"
#include "fnv/decl/FUN_00504e40_shell.h"
#include "fnv/decl/FUN_00504e60_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_00572160_shell.h"
#include "fnv/decl/FUN_007316d0_Class.h"
#include "fnv/decl/FUN_00737e30_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00a01290_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00c4f270_Class.h"
#include "fnv/decl/FUN_00c4f2d0_class.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/Menu.h"
#include "fnv/decl/MultiBoundManagerB5D.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/PickupSoundActorView.h"
#include "fnv/decl/SSN_b5.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESQuest.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/Target2180.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TimeCounter.h"
#include "fnv/decl/TopicMenuController.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_004818e0__FUN_004818e0_t.h"
#include "fnv/decl/fnv_007fd640__FUN_007fd640Class.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00969b20__TimeRefresh.h"
#include "fnv/decl/fnv_00969b80__FUN_00969b80_class.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005a6000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_007c2000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01025000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_01049000.h"
#include "fnv/symbols_01054000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
struct SlotMachineMenu
{
    int FUN_007c0800();
};

// @fnv 0x007c0800
int SlotMachineMenu::FUN_007c0800()
{
    return 0x438;
}

// @fnv 0x007c1440
int __cdecl FUN_007c1440()
{
    return 0x438;
}

struct FUN_007c0840Host
{
    void FUN_007c0870();
    void* FUN_007c0840(unsigned int);
};
struct FUN_007c1450_shell
{
    int m[0x2a];
    char FUN_007c1450();
};
// @fnv 0x007c1450
char FUN_007c1450_shell::FUN_007c1450()
{
    for (int i = 0; i < 10; ++i)
    {
        if (m[0x28 + i] == 0)
            return 0;
    }
    return 1;
}

namespace fnv_007c0810 {
class Tile;
struct SlotMachineMenu
{
    char pad[0xa0];
    Tile* m_pTiles[40];
    void SetTile(int id, Tile* tile);
};

// @fnv 0x007c0810
void SlotMachineMenu::SetTile(int aiIndex, Tile* tile)
{
    if (aiIndex >= 0 && aiIndex < 10)
    {
        m_pTiles[aiIndex] = tile;
    }
}
}  // namespace fnv_007c0810

struct FUN_007c5760_shell
{
    int pad[0x3a];
    int m_aiValues[3];
    int FUN_007c5760();
};
// @fnv 0x007c5760
int FUN_007c5760_shell::FUN_007c5760()
{
    int wildcount = 0;
    for (int i = 0; i < 3; i++)
    {
        if (m_aiValues[i] == 12)
            wildcount++;
    }
    if (m_aiValues[0] == m_aiValues[1] && m_aiValues[0] == m_aiValues[2] && m_aiValues[1] % 2 == 0)
        return 6;
    else if (wildcount == 2)
        return 5;
    else if (wildcount == 1)
        return 4;
    else if (m_aiValues[0] == 12 || m_aiValues[1] == 12 || m_aiValues[2] == 12)
        return 2;
    else if ((m_aiValues[1] == m_aiValues[2] && m_aiValues[1] % 2 == 0) ||
             (m_aiValues[0] == m_aiValues[2] && m_aiValues[0] % 2 == 0) ||
             (m_aiValues[1] == m_aiValues[0] && m_aiValues[0] % 2 == 0))
        return 1;
    else
        return 0;
}

class GlobalObject_0040c150
{
};
struct FNStub
{
};
class Tile
{
public:
    void Set(int, int);
public:
    static float GetInterfaceScale();
};
extern int* DAT_011da9a8;

struct FUN_007c5e60_shell
{
    void* m_pVtbl;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
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
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    Tile* m_tile;
    void UpdateTileText();
};

// @fnv 0x007c5e60
void FUN_007c5e60_shell::UpdateTileText()
{
    char tstring[260];
    int ilen;
    int i;

    ::FUN_00406d00(tstring, 0x104, "%s %s%i", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)(DAT_011da9ac + 0x18))))->FUN_00408da0())), ((const char *)(reinterpret_cast<::StartMenu *>(&(::g_011d3e08))->GetMenuTitle())),
               DAT_011da9a8[1]);
    ilen = ((int)(::FUN_0044a670(tstring)));
    if (ilen < 0x17)
    {
        ::FUN_00406d00(tstring, 0x104, DAT_01012058, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)(DAT_011da9ac + 0x18))))->FUN_00408da0())),
                   ((const char *)(reinterpret_cast<::StartMenu *>(&(::g_011d3e08))->GetMenuTitle())));
        for (i = 0; i < 0x17 - ilen; i++)
        {
            tstring[ilen + (i - 1)] = ' ';
            tstring[ilen + i] = 0;
        }
        ::FUN_00406d00(tstring, 0x104, "%s%i", tstring, DAT_011da9a8[1]);
    }
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_tile))->FUN_00a01350(DAT_011da99c, (char *)(tstring), true);
}

struct AnimIdle;
struct Accum_00733500;

struct S148c0
{
    void FUN_007148c0(intptr_t, int);
};

struct MiddleLowProcess
{
    Accum_00733500* GetProcessInteger();
};

struct BSFaceGenNiNode
{
    void* GetAnimationData();
};

struct GO
{
    unsigned int value;

    GO(intptr_t);
    ~GO();
    operator unsigned int() const;
    void operator=(void*);
};

struct GlobalObject_00633c90 : GO
{
};

struct Mgr_00733500
{
};

struct NiAdditionalGeometryData
{
    static void* GetShadowSceneNodeForIndex(int);
};

class BSShaderAccumulator;
class NiCamera;
struct BSShaderRenderUtility
{
public:
    static void SetRenderCamera(::NiCamera *, ::BSShaderAccumulator *, bool);
};

struct Accum_00733500
{
};



// @fnv 0x007c19c0
void FUN_007c19c0()
{
    ((::S148c0 *)(::FUN_0043c4b0()))->FUN_007148c0(0, 4);

    AnimIdle* go = ((::AnimIdle *)(::FUN_0045c670()));
    Accum_00733500* accum = ((MiddleLowProcess*)go)->GetProcessInteger();
    reinterpret_cast<::FUN_00c4f270_Class *>((accum))->FUN_00c4f270(1);

    AnimIdle* anim2 = (AnimIdle*)(uintptr_t)::g_011da9d0;
    ::UpdateCameraFrustum((::NiCamera *)(anim2), g_011db5ec_arg1);

    GO selected((int)((reinterpret_cast<::fnv_007fd640::FUN_007fd640Class *>((((::Mgr_00733500 *)(::fnv_004b7210::FUN_004b7210()))))->FUN_007fd640())));
    reinterpret_cast<::FUN_004a0fd0_shell *>((accum))->FUN_004a0fd0((::NiNode *)(::AnimIdle *)((AnimIdle*)(uintptr_t)selected));

    AnimIdle* anim = anim2 ? anim2 : (AnimIdle*)((BSFaceGenNiNode*)go)->GetAnimationData();

    ::FUN_00b6bee0(anim, NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1), (::BSShaderAccumulator *)(accum));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(anim), (::BSShaderAccumulator *)(::AnimIdle *)((AnimIdle*)(uintptr_t)selected), false);

    reinterpret_cast<::FUN_004a0fd0_shell *>((accum))->FUN_004a0fd0((::NiNode *)(::AnimIdle *)(0));
    selected = 0;
    reinterpret_cast<::FUN_00c4f2d0_class *>((accum))->FUN_00c4f2d0();
}

class NiFixedString
{
  public:
    const char* m_psz;
    NiFixedString(const char*) noexcept;
    ~NiFixedString();
};
struct NiUpdateData
{
    float m_00;
    int m_04;
    float m_08;
    NiUpdateData(float, bool, int);
};
struct NiBoundW7
{
};
struct CtrlObj
{
};
struct AVObj
{
};
struct NiNodeW7
{
    virtual void Vf00();
    virtual void Vf01();
    virtual void Vf02();
    virtual void Vf03();
    virtual void Vf04();
    virtual void Vf05();
    virtual void Vf06();
    virtual void Vf07();
    virtual void Vf08();
    virtual void Vf09();
    virtual void Vf10();
    virtual void Vf11();
    virtual void Vf12();
    virtual void Vf13();
    virtual void Vf14();
    virtual void Vf15();
    virtual void Vf16();
    virtual void Vf17();
    virtual void Vf18();
    virtual void Vf19();
    virtual void Vf20();
    virtual void Vf21();
    virtual void Vf22();
    virtual void Vf23();
    virtual void Vf24();
    virtual void Vf25();
    virtual void Vf26();
    virtual void Vf27();
    virtual void Vf28();
    virtual void Vf29();
    virtual void Vf30();
    virtual void Vf31();
    virtual void Vf32();
    virtual void Vf33();
    virtual void Vf34();
    virtual void Vf35();
    virtual void Vf36();
    virtual void Vf37();
    virtual void Vf38();
    virtual void Vf39();
    virtual void Vf40();
    virtual void Vf41();
    virtual void Vf42();
    virtual void Vf43();
    virtual void Vf44();
    virtual void Vf45();
    virtual void Vf46();
    virtual void Vf47();
    virtual void Vf48();
    virtual void Vf49();
    virtual void Vf50();
    virtual void Vf51();
    virtual void Vf52();
    virtual void Vf53();
    virtual void Vf54();
    virtual void Vf55(void*, int);
};
struct ShadowSceneNode : NiNodeW7
{
};
ShadowSceneNode* __cdecl FUN_00450b80(int);
struct GObjW7
{
};
struct GlobalObject_00633c90;
struct MatW7
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    MatW7 FUN_0043f8d0(MatW7*);
};
struct NiMemObject
{
};
struct FUN_00a5ecb0 : NiMemObject
{
    int m[0x2b];
    FUN_00a5ecb0(unsigned int);
};
extern float DAT_0107678c;
struct MenuW7
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    AVObj* m_104;
    AVObj* m_108[3];
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    CtrlObj* m_134;
    CtrlObj* m_138;
    CtrlObj* m_13c;
    CtrlObj* m_140;
    CtrlObj* m_144;
    CtrlObj* m_148[3];
    void InitPayoutMenu();
    void FUN_007c4d70();
};
static const char kPayoutIn[] = "Payout_In";
struct FUN_007c56e0_shell
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
    int sourceValues[10];
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
    int valueCount;
    int unkD4;
    int unkD8;
    int savedResults[3];
    int currentResults[3];

    void FUN_007c56e0();
};


// @fnv 0x007c56e0
void FUN_007c56e0_shell::FUN_007c56e0()
{
    for (int i = 0; i < 3; ++i)
    {
        savedResults[i] = currentResults[i];
        currentResults[i] = sourceValues[((int)(::GetRandomNumberInRange(0, valueCount * 2 - 1)))];
    }

    reinterpret_cast<::FUN_007c5760_shell *>(this)->FUN_007c5760();
}

class PlayerCharacter
{
};

struct SlotModelSource
{
    virtual void Vf00();
    virtual void Vf01();
    virtual void Vf02();
    virtual void Vf03();
    virtual void Vf04();
    virtual const char* GetModelPath();
};
struct SlotModelList
{
};

struct ModelLoader
{
};

struct SlotShadowNode
{
    virtual void Vf00();
    virtual void Vf01();
    virtual void Vf02();
    virtual void Vf03();
    virtual void Vf04();
    virtual void Vf05();
    virtual void Vf06();
    virtual void Vf07();
    virtual void Vf08();
    virtual void Vf09();
    virtual void Vf10();
    virtual void Vf11();
    virtual void Vf12();
    virtual void Vf13();
    virtual void Vf14();
    virtual void Vf15();
    virtual void Vf16();
    virtual void Vf17();
    virtual void Vf18();
    virtual void Vf19();
    virtual void Vf20();
    virtual void Vf21();
    virtual void Vf22();
    virtual void Vf23();
    virtual void Vf24();
    virtual void Vf25();
    virtual void Vf26();
    virtual void Vf27();
    virtual void Vf28();
    virtual void Vf29();
    virtual void Vf30();
    virtual void Vf31();
    virtual void Vf32();
    virtual void Vf33();
    virtual void Vf34();
    virtual void Vf35();
    virtual void Vf36();
    virtual void Vf37();
    virtual void Vf38();
    virtual void Vf39();
    virtual void Vf40();
    virtual void Vf41();
    virtual void Vf42();
    virtual void Vf43();
    virtual void Vf44();
    virtual void Vf45();
    virtual void Vf46();
    virtual void Vf47();
    virtual void Vf48();
    virtual void Vf49();
    virtual void Vf50();
    virtual void Vf51();
    virtual void Vf52();
    virtual void Vf53();
    virtual void Vf54();
    virtual void Vf55();
    virtual void Vf56();
    virtual void Vf57();
    virtual void AttachRoot(void* node);
};

struct SlotSceneNode
{
};

struct NiNodeRef
{
};

struct SlotNiPointer
{
    void* m_pObject;
    ~SlotNiPointer();
    SlotNiPointer& operator=(void* obj);
};

struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};

struct FUN_007c0870 : Menu_007a8b10
{
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    void* m_104;
    void* m_reels[3];
    SlotNiPointer m_reelNodes[8];
    void* m_134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    void* m_reelControllers[3];
    virtual ~FUN_007c0870();
};
// Calls FUN_007c0870, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x007c0840
void* FUN_007c0840Host::FUN_007c0840(unsigned int flags)
{
    reinterpret_cast<::FUN_007c0870 *>(this)->FUN_007c0870::~FUN_007c0870();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x007c0870
FUN_007c0870::~FUN_007c0870()
{
    reinterpret_cast<::fnv_00969b20::TimeRefresh *>((::_g_thePlayer))->FUN_00969b20();
    reinterpret_cast<::FUN_0045a5e0_shell *>((::g_modelLoader))->FUN_0045a5e0((char *)(((::SlotModelSource *)(reinterpret_cast<::FUN_00504e00_shell *>((((SlotModelList*)DAT_011da9ac)))->FUN_00504e00(7)))->GetModelPath()));
    reinterpret_cast<::FUN_0045a5e0_shell *>((::g_modelLoader))->FUN_0045a5e0((char *)("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel01.NIF"));
    reinterpret_cast<::FUN_0045a5e0_shell *>((::g_modelLoader))->FUN_0045a5e0((char *)("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel02.NIF"));
    reinterpret_cast<::FUN_0045a5e0_shell *>((::g_modelLoader))->FUN_0045a5e0((char *)("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel03.NIF"));
    ((SlotShadowNode*)FUN_00450b80(1))->AttachRoot(((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)&::g_011da9fc))))));
    reinterpret_cast<::MultiBoundManagerB5D *>((((SlotSceneNode*)FUN_00450b80(1))))->FUN_00b5d180();
    reinterpret_cast<::FUN_00572160_shell *>((((NiNodeRef*)((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)&::g_011da9fc))))))))->FUN_00572160();
    m_104 = 0;
    (GO&)::g_011da9d0 = 0;
    (GO&)::g_011da9fc = 0;
    m_134 = 0;
    for (int i = 0; i < 3; i++)
    {
        m_reels[i] = 0;
        m_reelControllers[i] = 0;
    }
    for (int j = 0; j < 8; j++)
    {
        m_reelNodes[j] = 0;
    }
    DAT_011da9ac = 0;
    DAT_011da9a4 = 0;
}

namespace fnv_007c0a40 {
struct FUN_00733f50
{
    void* owner;
    int count;
    int flags;

    FUN_00733f50();
};
typedef FUN_00733f50 Record;
struct RecordList
{
    bool FUN_008256d0();
    void FUN_00726c60(Record**);
    void FUN_005ae3d0(Record**);
};
struct Setting
{
};
struct CasinoData
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
    int limit;
};
struct StringField
{
};
struct Casino
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual void vfe4();
    virtual void vfe8();
    virtual void vfec();
    virtual void vff0();
    virtual void vff4();
    virtual void vff8();
    virtual void vffc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual const char* GetName();
    int unk04;
    int unk08;
    void* unk0c;
    int unk10;
    int unk14;
    StringField name;
};
struct Player
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
    struct Stats
    {
    } stats;
};
struct GameMenu;
struct GameTile
{
};
struct GameMenu
{
    virtual ~GameMenu();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual int Type();
    void* unk04;
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
    GameTile* tilea0;
    GameTile* tilea4;
    GameTile* tilea8;
    GameTile* tileac;
    GameTile* tileb0;
    GameTile* tileb4;
    GameTile* tileb8;
    GameTile* tilebc;
    GameTile* tilec0;
    GameTile* tilec4;
    int stat;
    int wager;
    bool LoadAssets();
};
struct TileManager
{
    struct Reader
    {
    };
};
struct BSSoundHandleEx
{
    int id;
    int state;
    int flags;
    ~BSSoundHandleEx();
};
struct BSAudio
{
  public:
    BSSoundHandleEx GetSoundHandleByEditorID(const char*, unsigned int);
};
extern const char DAT_01076694[];
extern const char DAT_01076670[];
extern const char DAT_01076618[];
extern const char DAT_01076600[];
extern const char DAT_010765f0[];
extern const char DAT_010765d8[];

// Validates casino wager/limit/threshold, finds or creates the casino record, opens the casino menu and fills its tiles, returning the menu tile or null.
// @fnv 0x007c0a40
GameTile* __cdecl FUN_007c0a40(char* casino, int wager, int mode, int threshold)
{
    GameMenu* oldMenu = (GameMenu*)((void *)(::FUN_00a09030(0x438)));
    TileManager::Reader* tile = (TileManager::Reader*)((::Mgr_00733500 *)(::fnv_004b7210::FUN_004b7210()));
    DAT_011a0828 = mode;
    DAT_011a082c = wager;
    DAT_011da9ac = casino;
    DAT_011da9a8 = 0;
    RecordList* node = ((::fnv_007c0a40::RecordList *)(::FUN_005a6260((char *)((*reinterpret_cast<::fnv_007c0a40::Player * *>(&::_g_thePlayer))))));
    while (node && *((::fnv_007c0a40::FUN_00733f50 **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))
    {
        if (!(*((::fnv_007c0a40::FUN_00733f50 **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))->owner || !((intptr_t)(::FUN_004839c0((unsigned int)(uintptr_t)((*((::fnv_007c0a40::FUN_00733f50 **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))->owner)))))
        {
            ::DispatchMessageToSink((const char *)(DAT_01076694), 0, (const char *)(::DAT_01049638), 0, ::DAT_010162c0, 0);
            return 0;
        }
        if (((void *)(((Casino*)DAT_011da9ac)->unk0c)) == (*((::fnv_007c0a40::FUN_00733f50 **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)))->owner)
        {
            DAT_011da9a8 = (int*)*((::fnv_007c0a40::FUN_00733f50 **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item));
            break;
        }
        if (!((::fnv_007c0a40::RecordList *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())))
            break;
        node = ((::fnv_007c0a40::RecordList *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    if (!DAT_011da9a8)
    {
        Record* pNewRecord = new Record;
        pNewRecord->owner = ((void *)(((Casino*)DAT_011da9ac)->unk0c));
        pNewRecord->count = 0;
        node = ((::fnv_007c0a40::RecordList *)(::FUN_005a6260((char *)((*reinterpret_cast<::fnv_007c0a40::Player * *>(&::_g_thePlayer))))));
        if (!node || node->FUN_008256d0())
            node->FUN_00726c60(&pNewRecord);
        else
            node->FUN_005ae3d0(&pNewRecord);
        DAT_011da9a8 = (int*)pNewRecord;
    }
    if (((bool)(reinterpret_cast<::fnv_00969b80::FUN_00969b80_class *>(((*reinterpret_cast<::fnv_007c0a40::Player * *>(&::_g_thePlayer))))->FUN_00969b80())))
    {
        char message[260];
        ::FUN_00406d00(message, 260, ::DAT_01070c58, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d2ac0))))->GetMenuTitle())), ((int)(reinterpret_cast<::TimeCounter *>(((*reinterpret_cast<::fnv_007c0a40::Player * *>(&::_g_thePlayer))))->FUN_00969b40())));
        ::DispatchMessageToSink((const char *)(message), 0, (const char *)(::DAT_01049638), 0, ::DAT_010162c0, 0);
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c0a40::BSSoundHandleEx &)(((::fnv_007c0a40::BSAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID(::DAT_01025cc4, 0x121)))->FUN_00ad8830(false);
        return 0;
    }
    if (((Record*)DAT_011da9a8)->count >= ((::fnv_007c0a40::CasinoData *)(reinterpret_cast<::FUN_00504e60_shell *>((((Casino*)DAT_011da9ac)))->FUN_00504e60()))->limit)
    {
        char message[260];
        ::FUN_00406d00(message, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d3abc))))->GetMenuTitle())));
        ::DispatchMessageToSink((const char *)(message), 0, (const char *)(::DAT_01049638), 0, ::DAT_010162c0, 0);
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c0a40::BSSoundHandleEx &)(((::fnv_007c0a40::BSAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID(::DAT_01025cc4, 0x121)))->FUN_00ad8830(false);
        return 0;
    }
    if (reinterpret_cast<::CombatState *>(((*reinterpret_cast<::fnv_007c0a40::Player * *>(&::_g_thePlayer))))->GetInventoryItemCount((::TESForm *)(void *)(((void *)(reinterpret_cast<::FUN_007316d0_Class *>((((Casino*)DAT_011da9ac)))->FUN_007316d0())))) < DAT_011a082c)
    {
        char message[260];
        ::FUN_00406d00(message, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d2424))))->GetMenuTitle())));
        ::DispatchMessageToSink((const char *)(message), 0, (const char *)(::DAT_01049638), 0, ::DAT_010162c0, 0);
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c0a40::BSSoundHandleEx &)(((::fnv_007c0a40::BSAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID(::DAT_01025cc4, 0x121)))->FUN_00ad8830(false);
        return 0;
    }
    if (((Record*)DAT_011da9a8)->count < threshold && threshold != 0)
    {
        char message[260];
        ::FUN_00406d00(message, 260, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d3594))))->GetMenuTitle())));
        ::DispatchMessageToSink((const char *)(message), 0, (const char *)(::DAT_01049638), 0, ::DAT_010162c0, 0);
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c0a40::BSSoundHandleEx &)(((::fnv_007c0a40::BSAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID(::DAT_01025cc4, 0x121)))->FUN_00ad8830(false);
        return 0;
    }
    if (oldMenu)
        delete oldMenu;
    GameTile* manager = ((::fnv_007c0a40::GameTile *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::fnv_007c0a40::GameTile *)(reinterpret_cast<::InterfaceManager *>((tile))->FUN_00586150()))))->FUN_00a01b00({})));
    (*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4)) = ((::fnv_007c0a40::GameMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((manager))->FUN_00a03c90()));
    if ((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4)) && (*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->Type() == FUN_007c1440() && DAT_011da9ac)
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))))->FUN_00a1dc70((::TileMenu *)(manager), false);
        if (!((bool)(reinterpret_cast<::FUN_007c1450_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))))->FUN_007c1450())))
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (reinterpret_cast<::TileListBoxCalls *>((manager))->GetFloat(0xfa7) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((manager))->GetFloat(0xfa7) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((manager))->FUN_00a012d0(0xfad, ::Tile::GetInterfaceScale(), {});
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c0a40::BSSoundHandleEx &)(((::fnv_007c0a40::BSAudio *)(::FUN_00453a70()))->GetSoundHandleByEditorID(DAT_01076600, 0x121)))->FUN_00ad8830(false);
        (*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->stat = reinterpret_cast<::ActorValueOwner *>(&((*reinterpret_cast<::fnv_007c0a40::Player * *>(&::_g_thePlayer))->stats))->GetActorValueAsInteger((::ActorValue::Index)(11));
        (*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->wager = DAT_011a082c;
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilea0))->FUN_00a01350(DAT_011da99c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d3804))))->GetMenuTitle()))), true);
        reinterpret_cast<::FUN_00a01290_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilea0))->SetTraitAndReset(::fnv_007c06f0::g_traitX, 1.0f);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilea0))->Set(::fnv_007c06f0::g_traitX, DAT_011a082c);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilea4))->FUN_00a01350(DAT_011da99c, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d3300))))->GetMenuTitle()))), true);
        reinterpret_cast<::FUN_00a01290_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilea4))->SetTraitAndReset(::fnv_007c06f0::g_traitX, 1.0f);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilea4))->Set(::fnv_007c06f0::g_traitX,
                                           reinterpret_cast<::CombatState *>(((*reinterpret_cast<::fnv_007c0a40::Player * *>(&::_g_thePlayer))))->GetInventoryItemCount((::TESForm *)(void *)(((void *)(reinterpret_cast<::FUN_007316d0_Class *>((((Casino*)DAT_011da9ac)))->FUN_007316d0())))));
        char label[64];
        if (((int)(::FUN_0044a670(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((Casino*)DAT_011da9ac)->name))->FUN_00408da0()))))))
            ::FUN_00406d00(label, 64, DAT_01012058, ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((Casino*)DAT_011da9ac)->name))->FUN_00408da0())),
                       ((const char *)(reinterpret_cast<::StartMenu *>(&(::g_011d3e08))->GetMenuTitle())));
        else
            ::FUN_00406d00(label, 64, DAT_010765f0, ((Casino*)DAT_011da9ac)->GetName());
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilea8))->FUN_00a01350(DAT_011da99c, (char *)(label), true);
        reinterpret_cast<::Tile *>((((::fnv_007c0a40::GameTile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilea8), DAT_010765d8)))))->Set(0xfa3, 0);
        reinterpret_cast<::FUN_007c5e60_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))))->UpdateTileText();
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tileac))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d2fd0))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tileb0))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d3354))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tileb4))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d487c))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tileb8))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d4054))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilebc))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d37f8))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilec4))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d387c))))->GetMenuTitle()))), true);
        if ((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilec0)
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->tilec0))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c0a40::Setting *>(&::g_011d33fc))))->GetMenuTitle()))), true);
        if (!(*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->LoadAssets())
        {
            ::FUN_007c2420();
            return 0;
        }
        reinterpret_cast<::MenuW7 *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))))->InitPayoutMenu();
        reinterpret_cast<::Menu *>(((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))))->SetMenuVisibility(0);
        return manager;
    }
    else if ((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4)) && ((::fnv_007c0a40::GameTile *)((*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4))->unk04)))
        delete (*reinterpret_cast<::fnv_007c0a40::GameMenu * *>(&::DAT_011da9a4));
    return 0;
}
}  // namespace fnv_007c0a40

namespace fnv_007c2c70 {
struct MenuTile
{
};

struct TileHolder
{
    MenuTile* GetTile(int id);
};


struct GenericGet
{
};

struct BSStr : GenericGet
{
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    BSStr();
    ~BSStr();
};

struct GameSetting
{
};

struct RgbaColor
{
    float r;
    float g;
    float b;
    RgbaColor(float a, int b1, int b2);
};

struct ColorList
{
};

struct ColorOwner
{
};

struct ColorArray : GenericGet
{
};

struct Timer
{
};

struct PlayerData
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
    int m_28;
};

struct ProgressObj
{
};

struct Player
{
};

struct InvItem;
struct DataHandler
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual void vF4();
    virtual void vF8();
    virtual void vFC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void AddItem(intptr_t item, int a1, int count, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
    InvItem* GetName(int item, int a, int b);
};

struct CapsChange
{
    int unk00;
    int unk04;
    int unk08;
    CapsChange();
    ~CapsChange();
};

struct AudioPlaybackHandle
{
    int unk00;
    int unk04;
    int unk08;
    ~AudioPlaybackHandle();
};

struct AudioMgr
{
    AudioPlaybackHandle GetHandle(const char* name, int flags, int a);
};

struct AnimSeq
{
};

struct Anim
{
};

struct HudMenu
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
    MenuTile* m_a0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    MenuTile* m_c4;
};

unsigned char __cdecl IsMenuVisible(void* tile);

extern float DAT_011daa30;
extern int DAT_011daa2c;

struct SlotMenu
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void* GetTile();
    void* unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_uiContentCount;
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
    int m_result;
    int unkA0;
    MenuTile* m_a4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    MenuTile* m_c4;
    int unkC8;
    int m_bet;
    int unkD0;
    int m_caps;
    bool m_d8;
    int unkDC;
    int unkE0;
    int unkE4;
    int m_e8;
    int unkEC;
    int unkF0;
    int m_lastTime;
    unsigned char m_f8;
    int unkFC;
    unsigned char m_100;
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
    Anim* m_134;
    AnimSeq* m_138;
    AnimSeq* m_13c;
    AnimSeq* m_140;
    AnimSeq* m_144;
    AnimSeq* m_148;

    void StartSpin();
    void StopReels();
    void Unused0();
    void Unused1();
    void Update();
};

// @fnv 0x007c2c70
void SlotMenu::Update()
{
    int dt = 0;
    float scale = 1.0f;
    unsigned char kKVis = IsMenuVisible(GetTile());
    if (m_lastTime == 0)
    {
        dt = 0;
        DAT_011daa30 = 0.0f;
        DAT_011daa2c = 0;
    }
    else if (kKVis)
    {
        dt = ((int)(::fnv::timer::Time())) - m_lastTime;
        if (DAT_011daa2c != m_uiContentCount)
        {
            DAT_011daa30 = 0.0f;
        }
        else
        {
            DAT_011daa30 += dt / 1000.0;
        }
    }
    int tmp = 0;
    m_lastTime = ((int)(::fnv::timer::Time()));
    DAT_011daa2c = m_uiContentCount;
    if (!kKVis)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((((::fnv_007c2c70::MenuTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::fnv_007c2c70::TileHolder *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0045cd60()))))->FUN_00a012d0(255.0f, 1, {});
    }
    switch (m_uiContentCount)
    {
    case 7:
        if (((int)(this->unk24)) != 2)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((((::fnv_007c2c70::MenuTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::fnv_007c2c70::TileHolder *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0045cd60()))))->FUN_00a012d0(255.0f, 1, {});
            reinterpret_cast<::Tile *>((((::fnv_007c2c70::MenuTile *)(this->unk04))))->Set(0x1772, 1);
            reinterpret_cast<::FUN_00a1d910_shell *>(this)->FUN_00a1d910();
            int diff;
            if ((diff = m_caps - reinterpret_cast<::CombatState *>(((*reinterpret_cast<::fnv_007c2c70::DataHandler * *>(&::_g_thePlayer))))->GetInventoryItemCount((::TESForm *)(((std::intptr_t)(reinterpret_cast<::FUN_007316d0_Class *>((((Player*)DAT_011da9ac)))->FUN_007316d0()))))) < 0)
            {
                (*reinterpret_cast<::fnv_007c2c70::DataHandler * *>(&::_g_thePlayer))->AddItem(((intptr_t)(reinterpret_cast<::FUN_007316d0_Class *>((((Player*)DAT_011da9ac)))->FUN_007316d0())), 0, -diff, 0, 0, 0, 0, 0, 1, 0);
                BSStr msg;
                ::FUN_00406f60((::FUN_00406f90_this *)(::fnv_007c2c70::BSStr *)(&msg), "%i %s%s %s", -diff, ::FUN_00482720((::TESForm *)(((std::intptr_t)(reinterpret_cast<::FUN_007316d0_Class *>((((Player*)DAT_011da9ac)))->FUN_007316d0())))),
                             ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d3114))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d3db4))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)((const char*)((void *)(::FUN_00559450((int *)&(msg))))), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds"),
                            (const char *)(((::fnv_007c2c70::InvItem *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::fnv_007c2c70::DataHandler * *>(&::_g_thePlayer))))->FUN_008adcf0((::TESBoundObject *)(((const char *)(reinterpret_cast<::FUN_007316d0_Class *>((((Player*)DAT_011da9ac)))->FUN_007316d0()))), 1, 0)))), 2.0f, 0);
            }
            else if (diff > 0)
            {
                CapsChange change;
                reinterpret_cast<::fnv_004818e0::FUN_004818e0_t *>(&(change))->FUN_004818e0((::TESObject *)(((std::intptr_t)(reinterpret_cast<::FUN_007316d0_Class *>((((Player*)DAT_011da9ac)))->FUN_007316d0()))), diff, (::ContainerItemExtra *)(0));
                if (DAT_011da9a8[1] < ((int)(reinterpret_cast<::FUN_00737e30_shell *>((((Player*)DAT_011da9ac)))->GetFieldAt210())))
                {
                    reinterpret_cast<::ContainerOperation *>(&(change))->FUN_004821a0((::TESObjectREFR *)((*reinterpret_cast<::fnv_007c2c70::DataHandler * *>(&::_g_thePlayer))), 0);
                }
                else
                {
                    reinterpret_cast<::ContainerOperation *>(&(change))->FUN_004821a0((::TESObjectREFR *)((*reinterpret_cast<::fnv_007c2c70::DataHandler * *>(&::_g_thePlayer))), 1);
                    BSStr msg2;
                    ::FUN_00406f60((::FUN_00406f90_this *)(::fnv_007c2c70::BSStr *)(&msg2), "%i %s%s %s\n%s", diff, ::FUN_00482720((::TESForm *)(((std::intptr_t)(reinterpret_cast<::FUN_007316d0_Class *>((((Player*)DAT_011da9ac)))->FUN_007316d0())))),
                                 ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d3114))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d4e7c))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d3abc))))->GetMenuTitle())));
                    ::DispatchMessageToSink((const char *)((const char*)((void *)(::FUN_00559450((int *)&(msg2))))), 0,
                                (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_very_happy.dds"),
                                (const char *)(((::fnv_007c2c70::InvItem *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::fnv_007c2c70::DataHandler * *>(&::_g_thePlayer))))->FUN_008adcf0((::TESBoundObject *)(((const char *)(reinterpret_cast<::FUN_007316d0_Class *>((((Player*)DAT_011da9ac)))->FUN_007316d0()))), 1, 0)))), 2.0f, 0);
                }
            }
            if (m_100)
            {
                ProgressObj* progress = ((::fnv_007c2c70::ProgressObj *)(reinterpret_cast<::FUN_00504e40_shell *>((((Player*)DAT_011da9ac)))->FUN_00504e40()));
                if (progress != 0)
                {
                    reinterpret_cast<::TESQuest *>((progress))->SetEnabled(1);
                }
            }
        }
        break;
    case 0:
        m_uiContentCount = 6;
        break;
    case 1:
        if (m_138 != 0 && m_148 != 0)
        {
            if (m_13c != 0)
            {
                reinterpret_cast<::NiControllerManager *>((m_134))->StopSequence((::NiControllerSequence *)(m_13c), 0.0f);
            }
            if (DAT_011daa30 > 1.0)
            {
                reinterpret_cast<::Tile *>((m_c4))->Set(0xfa3, 0);
            }
            RgbaColor c0(DAT_011daa30, 1, 0);
            RgbaColor C5(DAT_011daa30, 1, 0);
            RgbaColor c2(DAT_011daa30, 1, 0);
            RgbaColor C(DAT_011daa30, 1, 0);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_007c2c70::ColorList *)(reinterpret_cast<::NiNode *>((((ColorOwner*)((void *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_007c2c70::ColorArray *>(&::g_011da9fc)))))))))->GetAt({})))))->FUN_00a59c60(0);
            if (DAT_011daa30 == 0.0 && reinterpret_cast<::TileListBoxCalls *>((m_a4))->GetFloat(::fnv_007c06f0::g_traitX) > 0.0)
            {
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c2c70::AudioPlaybackHandle &)(((::fnv_007c2c70::AudioMgr *)(::FUN_00453a70()))->GetHandle("GameSlotsPullLever", 0x121, 0)))->FUN_00ad8830({});
                m_f8 = 1;
            }
            if (DAT_011daa30 == 0.0 || reinterpret_cast<::TileListBoxCalls *>((m_a4))->GetFloat(::fnv_007c06f0::g_traitX) > 0.0)
            {
                reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_007c2c70::ColorList *)(reinterpret_cast<::NiNode *>((((ColorOwner*)((void *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_007c2c70::ColorArray *>(&::g_011da9fc)))))))))->GetAt({})))))->FUN_00a59c60(1);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_007c2c70::ColorList *)(reinterpret_cast<::NiNode *>((((ColorOwner*)((void *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_007c2c70::ColorArray *>(&::g_011da9fc)))))))))->GetAt({})))))->FUN_00a59c60(2);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_007c2c70::ColorList *)(reinterpret_cast<::NiNode *>((((ColorOwner*)((void *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_007c2c70::ColorArray *>(&::g_011da9fc)))))))))->GetAt({})))))->FUN_00a59c60(3);
            }
            if (DAT_011daa30 >= reinterpret_cast<::FUN_00508100_shell *>((m_138))->FUN_00508100() && m_f8 == 1)
            {
                m_f8 = 0;
                StopReels();
            }
            if (DAT_011daa30 >= reinterpret_cast<::FUN_00508100_shell *>((m_138))->FUN_00508100() && DAT_011daa30 >= reinterpret_cast<::FUN_00508100_shell *>((m_148))->FUN_00508100())
            {
                m_uiContentCount = 2;
                StartSpin();
            }
        }
        break;
    case 3:
        if (m_13c != 0)
        {
            reinterpret_cast<::NiControllerManager *>((m_134))->ActivateControllerSequence((::NiControllerSequence *)(m_13c), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            if (m_138 != 0)
            {
                reinterpret_cast<::NiControllerManager *>((m_134))->StopSequence((::NiControllerSequence *)(m_138), 0.0f);
            }
            RgbaColor C2(DAT_011daa30, 1, 0);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_007c2c70::ColorList *)(reinterpret_cast<::NiNode *>((((ColorOwner*)((void *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_007c2c70::ColorArray *>(&::g_011da9fc)))))))))->GetAt({})))))->FUN_00a59c60(0);
            if (DAT_011daa30 == 0.0)
            {
                if (m_result == 4)
                {
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c2c70::AudioPlaybackHandle &)(((::fnv_007c2c70::AudioMgr *)(::FUN_00453a70()))->GetHandle("GAMESlotsWinSmall", 0x121, 0)))->FUN_00ad8830({});
                }
                else if (m_result == 5)
                {
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c2c70::AudioPlaybackHandle &)(((::fnv_007c2c70::AudioMgr *)(::FUN_00453a70()))->GetHandle("GAMESlotsWinMed", 0x121, 0)))->FUN_00ad8830({});
                }
                else if (m_result == 6)
                {
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c2c70::AudioPlaybackHandle &)(((::fnv_007c2c70::AudioMgr *)(::FUN_00453a70()))->GetHandle("GAMESlotsWinJackpot", 0x121, 0)))->FUN_00ad8830({});
                }
            }
            if (DAT_011daa30 > 1.0)
            {
                reinterpret_cast<::Tile *>((m_c4))->Set(0xfa3, 0);
            }
            if (DAT_011daa30 >= reinterpret_cast<::FUN_00508100_shell *>((m_13c))->FUN_00508100())
            {
                reinterpret_cast<::NiControllerManager *>((m_134))->StopSequence((::NiControllerSequence *)(m_13c), 0.0f);
                if (m_138 != 0)
                {
                    reinterpret_cast<::NiControllerManager *>((m_134))->ActivateControllerSequence((::NiControllerSequence *)(m_138), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                }
                int total = ((::fnv_007c2c70::PlayerData *)(reinterpret_cast<::FUN_00504e60_shell *>((((Player*)DAT_011da9ac)))->FUN_00504e60()))->m_28;
                int cur = DAT_011da9a8[1];
                int iDX = ((short*)DAT_011da9a8)[4];
                for (int i = 1; i < 5; i++)
                {
                    if (i <= iDX)
                    {
                        m_100 = 0;
                    }
                    else if (total * (i * 0.25) <= cur)
                    {
                        ((short*)DAT_011da9a8)[4] = (short)i;
                        m_100 = 1;
                    }
                }
                if (m_100)
                {
                    ::FUN_007c2420();
                }
                else
                {
                    m_uiContentCount = 6;
                }
            }
        }
        else
        {
            m_uiContentCount = 6;
        }
        break;
    case 4:
        if (m_140 == 0)
        {
            break;
        }
        if (DAT_011daa30 == 0.0)
        {
            reinterpret_cast<::Tile *>((m_c4))->Set(0xfa3, 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_c4))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d387c))))->GetMenuTitle()))), 1);
            reinterpret_cast<::NiControllerManager *>((m_134))->DeactivateAllSequences(0.0f);
            reinterpret_cast<::NiControllerManager *>((m_134))->ActivateControllerSequence((::NiControllerSequence *)(m_140), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
        }
        if (DAT_011daa30 <= reinterpret_cast<::FUN_00508100_shell *>((m_140))->FUN_00508100())
        {
            RgbaColor c(DAT_011daa30, 1, 0);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_007c2c70::ColorList *)(reinterpret_cast<::NiNode *>((((ColorOwner*)((void *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_007c2c70::ColorArray *>(&::g_011da9fc)))))))))->GetAt({})))))->FUN_00a59c60(0);
        }
        else
        {
            reinterpret_cast<::NiControllerManager *>((m_134))->StopSequence((::NiControllerSequence *)(m_140), 0.0f);
        }
        break;
    case 5:
        if (m_144 == 0)
        {
            break;
        }
        if (DAT_011daa30 == 0.0)
        {
            reinterpret_cast<::Tile *>((m_c4))->Set(0xfa3, 0);
            reinterpret_cast<::NiControllerManager *>((m_134))->DeactivateAllSequences(0.0f);
            reinterpret_cast<::NiControllerManager *>((m_134))->ActivateControllerSequence((::NiControllerSequence *)(m_144), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
        }
        if (DAT_011daa30 <= reinterpret_cast<::FUN_00508100_shell *>((m_144))->FUN_00508100())
        {
            RgbaColor c(DAT_011daa30, 1, 0);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_007c2c70::ColorList *)(reinterpret_cast<::NiNode *>((((ColorOwner*)((void *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_007c2c70::ColorArray *>(&::g_011da9fc)))))))))->GetAt({})))))->FUN_00a59c60(0);
        }
        else
        {
            reinterpret_cast<::NiControllerManager *>((m_134))->StopSequence((::NiControllerSequence *)(m_144), 0.0f);
            reinterpret_cast<::NiControllerManager *>((m_134))->ActivateControllerSequence((::NiControllerSequence *)(m_138), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            m_uiContentCount = 6;
        }
        break;
    case 2: {
        int won = 0;
        m_result = reinterpret_cast<::FUN_007c5760_shell *>(this)->FUN_007c5760();
        if (m_result == 6)
        {
            switch (m_e8)
            {
            case 12:
                won = m_bet * 10;
                m_caps += won;
                break;
            case 0:
                won = m_bet * 10;
                m_caps += won;
                break;
            case 2:
                won = m_bet * 20;
                m_caps += won;
                break;
            case 4:
                won = m_bet * 30;
                m_caps += won;
                break;
            case 6:
                won = m_bet * 40;
                m_caps += won;
                break;
            case 8:
                won = m_bet * 60;
                m_caps += won;
                break;
            case 10:
                won = m_bet * 100;
                m_caps += won;
                break;
            default:
                m_caps -= m_bet;
                break;
            }
        }
        else if (m_result == 5)
        {
            won = m_bet * 5;
            m_caps += won;
        }
        else if (m_result == 4)
        {
            won = m_bet * 2;
            m_caps += won;
        }
        else
        {
            won = -m_bet;
            m_caps += won;
        }
        reinterpret_cast<::FUN_00a01290_shell *>((m_a4))->SetTraitAndReset(::fnv_007c06f0::g_traitX, 1.0f);
        reinterpret_cast<::Tile *>((m_a4))->Set(::fnv_007c06f0::g_traitX, m_caps);
        DAT_011da9a8[1] += won;
        reinterpret_cast<::FUN_007c5e60_shell *>(this)->UpdateTileText();
        if (m_result > 3)
        {
            char text[0x104];
            if (m_d8)
            {
                ::FUN_00406d00(text, 0x104, "%s %d %s%s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d3a98))))->GetMenuTitle())), won, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d5050))))->GetMenuTitle())),
                          ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d3114))))->GetMenuTitle())));
            }
            else
            {
                ::FUN_00406d00(text, 0x104, "%s %d %s%s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d2ff4))))->GetMenuTitle())), won, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d5050))))->GetMenuTitle())),
                          ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d3114))))->GetMenuTitle())));
            }
            reinterpret_cast<::FUN_00a01290_shell *>(((*reinterpret_cast<::fnv_007c2c70::HudMenu * *>(&::DAT_011da9a4))->m_c4))->SetTraitAndReset(0xfc4, 1.0f);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c2c70::HudMenu * *>(&::DAT_011da9a4))->m_c4))->FUN_00a01350(0xfc4, (char *)(text), 1);
            reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_007c2c70::HudMenu * *>(&::DAT_011da9a4))->m_c4))->Set(0xfa3, 1);
            m_uiContentCount = 3;
        }
        else
        {
            char text2[0x104];
            if (m_d8)
            {
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c2c70::AudioPlaybackHandle &)(((::fnv_007c2c70::AudioMgr *)(::FUN_00453a70()))->GetHandle("GAMESlotsLose", 0x121, 0)))->FUN_00ad8830({});
                ::FUN_00406d00(text2, 0x104, "%s %d %s%s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d25e0))))->GetMenuTitle())), -won, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d5050))))->GetMenuTitle())),
                          ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d3114))))->GetMenuTitle())));
            }
            else
            {
                ::FUN_00406d00(text2, 0x104, "%s %d %s%s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d3474))))->GetMenuTitle())), -won, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d5050))))->GetMenuTitle())),
                          ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d3114))))->GetMenuTitle())));
            }
            reinterpret_cast<::FUN_00a01290_shell *>(((*reinterpret_cast<::fnv_007c2c70::HudMenu * *>(&::DAT_011da9a4))->m_c4))->SetTraitAndReset(0xfc4, 1.0f);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::fnv_007c2c70::HudMenu * *>(&::DAT_011da9a4))->m_c4))->FUN_00a01350(0xfc4, (char *)(text2), 1);
            reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_007c2c70::HudMenu * *>(&::DAT_011da9a4))->m_c4))->Set(0xfa3, 1);
            m_uiContentCount = 6;
        }
        break;
    }
    case 6:
        if (DAT_011daa30 > 1.0)
        {
            reinterpret_cast<::Tile *>((m_c4))->Set(0xfa3, 0);
        }
        if (m_caps < m_bet)
        {
            m_bet = 1;
            reinterpret_cast<::FUN_00a01290_shell *>(((*reinterpret_cast<::fnv_007c2c70::HudMenu * *>(&::DAT_011da9a4))->m_a0))->SetTraitAndReset(::fnv_007c06f0::g_traitX, 1.0f);
            reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_007c2c70::HudMenu * *>(&::DAT_011da9a4))->m_a0))->Set(::fnv_007c06f0::g_traitX, m_bet);
        }
        if (m_caps == 0)
        {
            char text3[0x104];
            ::FUN_00406d00(text3, 0x104, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_007c2c70::GameSetting *>(&::g_011d2424))))->GetMenuTitle())));
            ::DispatchMessageToSink((const char *)(text3), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds"), (int)(0), 2.0f, 0);
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c2c70::AudioPlaybackHandle &)(((::fnv_007c2c70::AudioMgr *)(::FUN_00453a70()))->GetHandle("UIPopUpMessageGeneral", 0x121, 0)))->FUN_00ad8830({});
            ::FUN_007c2420();
        }
        break;
    }
}
}  // namespace fnv_007c2c70

struct ReelTexture
{
    void* value;
};
struct ReelProperty
{
    virtual void v0();
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
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
    virtual void SetTexture(int, int, void*);
};
struct ReelNode
{
};
struct ReelMenu
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
    int savedResults[3];
    int currentResults[3];
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    ReelNode* reels[3];
    ReelTexture textures[8];
    void FUN_007c40b0();
};
// @fnv 0x007c1af0
void MenuW7::InitPayoutMenu()
{
    ((GO&)::g_011da9fc) = new FUN_00a5ecb0(0);
    ((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)(void*)&::g_011da9fc)))))->Vf55(m_104, 1);
    ((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)(void*)&::g_011da9fc)))))->Vf55(m_108[0], 1);
    ((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)(void*)&::g_011da9fc)))))->Vf55(m_108[1], 1);
    ((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)(void*)&::g_011da9fc)))))->Vf55(m_108[2], 1);
    MatW7 xObjB;
    MatW7 objC7;
    reinterpret_cast<::FUN_00524ac0_shell *>(&(xObjB))->FUN_00524ac0(1.5707963705062866f);
    reinterpret_cast<::FUN_004a0c90_shell *>(&(objC7))->FUN_004a0c90(1.5707963705062866f);
    MatW7 rotation = xObjB.FUN_0043f8d0(&objC7);
    reinterpret_cast<::FUN_0043fa80_s *>((((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)(void*)&::g_011da9fc)))))))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)((const void*)&rotation)));
    reinterpret_cast<::FUN_004bc1f0_S *>((((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)(void*)&::g_011da9fc)))))))->FUN_004bc1f0(DAT_0105478c, DAT_0107678c, 0.0f);
    NiUpdateData upd1(0.0f, false, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)(void*)&::g_011da9fc)))))))->FUN_00a59c60((std::intptr_t)&(upd1));
    CtrlObj* xPCtrl = ((::CtrlObj *)(reinterpret_cast<::MyHost *>((m_104))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f36ac))))));
    if (xPCtrl != 0)
    {
        m_134 = xPCtrl;
        m_138 = ((::CtrlObj *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((m_134))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Forward")))));
        m_13c = ((::CtrlObj *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((m_134))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Backward")))));
        m_140 = ((::CtrlObj *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((m_134))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString(kPayoutIn)))));
        m_144 = ((::CtrlObj *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((m_134))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Payout_Out")))));
        reinterpret_cast<::NiControllerManager *>((m_134))->DeactivateAllSequences(0.0f);
        if (m_138 != 0)
        {
            reinterpret_cast<::NiControllerManager *>((m_134))->ActivateControllerSequence((::NiControllerSequence *)(m_138), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
        }
        ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(m_104));
    }
    CtrlObj* arr12[3];
    CtrlObj* aarr2[3];
    int oI;
    for (oI = 0; oI < 3; oI++)
    {
        arr12[oI] = ((::CtrlObj *)(reinterpret_cast<::MyHost *>((m_108[oI]))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f36ac))))));
    }
    int jX;
    for (jX = 0; jX < 3; jX++)
    {
        if (arr12[jX] != 0)
        {
            aarr2[jX] = arr12[jX];
            m_148[jX] = ((::CtrlObj *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((aarr2[jX]))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Forward")))));
            reinterpret_cast<::NiControllerManager *>((aarr2[jX]))->DeactivateAllSequences(0.0f);
            if (m_148[jX] != 0)
            {
                reinterpret_cast<::NiControllerManager *>((aarr2[jX]))->ActivateControllerSequence((::NiControllerSequence *)(m_148[jX]), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            }
            ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(m_108[jX]));
        }
    }
    NiUpdateData _upd2(0.0f, false, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)(void*)&::g_011da9fc)))))))->FUN_00a59c60((std::intptr_t)&(_upd2));
    ((GO&)::g_011da9d0) = ((void *)(reinterpret_cast<::Target2180 *>(this)->FUN_007c2180()));
    FUN_00450b80(1)->Vf55(((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)(void*)&::g_011da9fc))))), 1);
    float fTemp0 = reinterpret_cast<::Twin_0084d030 *>((((::NiBoundW7 *)(reinterpret_cast<::FUN_0043d450_Owner *>((((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)(void*)&::g_011da9fc)))))))->FUN_0043d450()))))->GetStoredFloatValue() * 3.0;
    reinterpret_cast<::SSN_b5 *>((FUN_00450b80(1)))->FUN_00b5ca70((::Node_b5 *)(::NiNodeW7 *)(((::NiNodeW7 *)(::FUN_00559450((int *)(((GObjW7*)(void*)&::g_011da9fc)))))), fTemp0);
    FUN_007c4d70();
    reinterpret_cast<::ReelMenu *>(this)->FUN_007c40b0();
}
// For each reel whose current result differs from the saved result, computes texture indices and sets the texture on the Cylinder nodes' property.
// @fnv 0x007c40b0
void ReelMenu::FUN_007c40b0()
{
    int reel4, delta8, a6, b, c3, d_, e, f7, g2, _h;
    char name6[260];
    ReelNode* node9;
    ReelProperty* propA;
    for (reel4 = 0; reel4 < 3; reel4++)
    {
        if (delta8 = currentResults[reel4] - savedResults[reel4])
        {
            if (currentResults[reel4] % 2 == 0)
            {
                a6 = currentResults[reel4] / 2 + 3;
                e = currentResults[reel4] / 2 + 4;
                c3 = currentResults[reel4] / 2 + 5;
                g2 = currentResults[reel4] / 2 + 6;
                b = d_ = f7 = _h = 7;
                if (a6 > 6)
                    a6 -= 7;
                if (e > 6)
                    e -= 7;
                if (c3 > 6)
                    c3 -= 7;
                if (g2 > 6)
                    g2 -= 7;
            }
            else
            {
                b = (currentResults[reel4] + 3) / 2;
                d_ = (currentResults[reel4] + 4) / 2;
                f7 = (currentResults[reel4] + 5) / 2;
                _h = (currentResults[reel4] + 6) / 2;
                a6 = e = c3 = g2 = 7;
                if (b > 6)
                    b -= 7;
                if (d_ > 6)
                    d_ -= 7;
                if (f7 > 6)
                    f7 -= 7;
                if (_h > 6)
                    _h -= 7;
            }
            ::FUN_00406d00(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 4 > 13 ? 2 * reel4 + 4 - 14 : 2 * reel4 + 4);
            node9 = ((::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name6))));
            propA =
                (!((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                     ? 0
                     : ((((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12)
                            ? 1
                            : 0))
                    ? ((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, ((void *)(::FUN_00559450((int *)&(textures[a6])))));
            ::FUN_00406d00(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 5 > 13 ? 2 * reel4 + 5 - 14 : 2 * reel4 + 5);
            node9 = ((::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name6))));
            propA =
                (!((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                     ? 0
                     : ((((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12)
                            ? 1
                            : 0))
                    ? ((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, ((void *)(::FUN_00559450((int *)&(textures[b])))));
            ::FUN_00406d00(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 6 > 13 ? 2 * reel4 + 6 - 14 : 2 * reel4 + 6);
            node9 = ((::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name6))));
            propA =
                (!((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                     ? 0
                     : ((((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12)
                            ? 1
                            : 0))
                    ? ((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, ((void *)(::FUN_00559450((int *)&(textures[e])))));
            ::FUN_00406d00(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 7 > 13 ? 2 * reel4 + 7 - 14 : 2 * reel4 + 7);
            node9 = ((::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name6))));
            propA =
                (!((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                     ? 0
                     : ((((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12)
                            ? 1
                            : 0))
                    ? ((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, ((void *)(::FUN_00559450((int *)&(textures[d_])))));
            ::FUN_00406d00(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 8 > 13 ? 2 * reel4 + 8 - 14 : 2 * reel4 + 8);
            node9 = ((::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name6))));
            propA =
                (!((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                     ? 0
                     : ((((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12)
                            ? 1
                            : 0))
                    ? ((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, ((void *)(::FUN_00559450((int *)&(textures[c3])))));
            ::FUN_00406d00(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 9 > 13 ? 2 * reel4 + 9 - 14 : 2 * reel4 + 9);
            node9 = ((::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name6))));
            propA =
                (!((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                     ? 0
                     : ((((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12)
                            ? 1
                            : 0))
                    ? ((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, ((void *)(::FUN_00559450((int *)&(textures[f7])))));
            ::FUN_00406d00(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 10 > 13 ? 2 * reel4 + 10 - 14 : 2 * reel4 + 10);
            node9 = ((::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name6))));
            propA =
                (!((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                     ? 0
                     : ((((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12)
                            ? 1
                            : 0))
                    ? ((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, ((void *)(::FUN_00559450((int *)&(textures[g2])))));
            ::FUN_00406d00(name6, 260, "Cylinder0%i:%i", 6 - reel4,
                       2 * reel4 + 11 > 13 ? 2 * reel4 + 11 - 14 : 2 * reel4 + 11);
            node9 = ((::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name6))));
            propA =
                (!((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                     ? 0
                     : ((((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12)
                            ? 1
                            : 0))
                    ? ((::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node9))->FUN_00a59d30(3)))
                    : 0;
            if (propA)
                propA->SetTexture(0, 0, ((void *)(::FUN_00559450((int *)&(textures[_h])))));
        }
    }
}

namespace fnv_007c4d70 {
static const char kCylinderFormat[] = "Cylinder0%i:%i";
struct ReelProperty
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void SetTexture(int, int, void*);
    int Type();
};
struct ReelNode
{
};
struct ReelTexture
{
    void* value;
    operator void*() const;
};
struct ReelMenu
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
    int previous[3];
    int current[3];
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    void* reels[3];
    ReelTexture textures[8];
    void FUN_007c4d70();
};
// For each of the 3 reels whose current value changed, computes cylinder indices and sets the texture on each matching reel node property.
// @fnv 0x007c4d70
void ReelMenu::FUN_007c4d70()
{
    int reel4;
    int delta8;
    ReelProperty* propertyA;
    int a8;
    int b2;
    int c2;
    char name[260];
    int dA;
    int e_;
    int f5;
    ReelNode* node;
    for (reel4 = 0; reel4 < 3; reel4++)
    {
        if (delta8 = current[reel4] - previous[reel4])
        {
            if (current[reel4] % 2 == 0)
            {
                f5 = current[reel4] / 2;
                e_ = current[reel4] / 2 + 1;
                c2 = current[reel4] / 2 - 1;
                dA = 7;
                b2 = a8 = dA;
                if (e_ > 6)
                    e_ -= 7;
                if (c2 < 0)
                    c2 += 7;
            }
            else
            {
                b2 = (current[reel4] + 1) / 2;
                a8 = (current[reel4] + 3) / 2;
                dA = (current[reel4] - 1) / 2;
                c2 = 7;
                f5 = e_ = c2;
                if (b2 > 6)
                    b2 -= 7;
                if (a8 > 6)
                    a8 -= 7;
                if (dA < 0)
                    dA += 7;
            }
            ::FUN_00406d00(name, 260, kCylinderFormat, 6 - reel4, (2 * reel4 + 3 > 13 ? 2 * reel4 - 11 : 2 * reel4 + 3));
            node = ((::fnv_007c4d70::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name))));
            propertyA =
                (!((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3))) ? false
                                       : (((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12))
                    ? ((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[a8]);
            ::FUN_00406d00(name, 260, kCylinderFormat, 6 - reel4, (2 * reel4 + 2 > 13 ? 2 * reel4 - 12 : 2 * reel4 + 2));
            node = ((::fnv_007c4d70::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name))));
            propertyA =
                (!((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3))) ? false
                                       : (((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12))
                    ? ((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[e_]);
            ::FUN_00406d00(name, 260, kCylinderFormat, 6 - reel4, (2 * reel4 + 1 > 13 ? 2 * reel4 - 13 : 2 * reel4 + 1));
            node = ((::fnv_007c4d70::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name))));
            propertyA =
                (!((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3))) ? false
                                       : (((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12))
                    ? ((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[b2]);
            ::FUN_00406d00(name, 260, kCylinderFormat, 6 - reel4, 2 * reel4);
            node = ((::fnv_007c4d70::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name))));
            propertyA =
                (!((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3))) ? false
                                       : (((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12))
                    ? ((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[f5]);
            ::FUN_00406d00(name, 260, kCylinderFormat, 6 - reel4, (2 * reel4 - 1 < 0 ? 2 * reel4 + 13 : 2 * reel4 - 1));
            node = ((::fnv_007c4d70::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name))));
            propertyA =
                (!((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3))) ? false
                                       : (((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12))
                    ? ((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[dA]);
            ::FUN_00406d00(name, 260, kCylinderFormat, 6 - reel4, (2 * reel4 - 2 < 0 ? 2 * reel4 + 12 : 2 * reel4 - 2));
            node = ((::fnv_007c4d70::ReelNode *)(::FUN_004aae30((::NiAVObject *)(reels[reel4]), (::NiFixedString *)(name))));
            propertyA =
                (!((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3))) ? false
                                       : (((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))))->GetMinLevel())) <= 12))
                    ? ((::fnv_007c4d70::ReelProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((node))->FUN_00a59d30(3)))
                    : 0;
            if (propertyA)
                propertyA->SetTexture(0, 0, textures[c2]);
        }
    }
}
}  // namespace fnv_007c4d70

struct Settings
{
    int unk00;
    int unk04;
    int stopCount0;
    int stopCount1;
    int stopCount2;
    int stopCount3;
    int stopCount4;
    int stopCount5;
    int stopCount6;
};
struct SettingsOwner
{
};
struct Sound
{
    int id;
    int state;
    int unk08;
    ~Sound();
};
struct Audio
{
    Sound GetSoundByEditorID(const char*, unsigned int);
};
struct Reels
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
    int symbols[28];
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
    int count;
    int unkD4;
    int unkD8;
    int saved[3];
    int current[3];
    bool InitReels();
};
// @fnv 0x007c16b0
bool Reels::InitReels()
{
    int filled = 0;
    {
        int index;
        for (index = 0; index < 28; index++)
            symbols[index] = 14;
    }
    int symbol = 0;
    int countsA[7];
    int tempA;
    tempA = ((::Settings *)(reinterpret_cast<::FUN_00504e60_shell *>(((*reinterpret_cast<::SettingsOwner * *>(&::DAT_011da9ac))))->FUN_00504e60()))->stopCount0;
    countsA[0] = tempA;
    tempA = ((::Settings *)(reinterpret_cast<::FUN_00504e60_shell *>(((*reinterpret_cast<::SettingsOwner * *>(&::DAT_011da9ac))))->FUN_00504e60()))->stopCount1;
    countsA[1] = tempA;
    tempA = ((::Settings *)(reinterpret_cast<::FUN_00504e60_shell *>(((*reinterpret_cast<::SettingsOwner * *>(&::DAT_011da9ac))))->FUN_00504e60()))->stopCount2;
    countsA[2] = tempA;
    tempA = ((::Settings *)(reinterpret_cast<::FUN_00504e60_shell *>(((*reinterpret_cast<::SettingsOwner * *>(&::DAT_011da9ac))))->FUN_00504e60()))->stopCount3;
    countsA[3] = tempA;
    tempA = ((::Settings *)(reinterpret_cast<::FUN_00504e60_shell *>(((*reinterpret_cast<::SettingsOwner * *>(&::DAT_011da9ac))))->FUN_00504e60()))->stopCount4;
    countsA[4] = tempA;
    tempA = ((::Settings *)(reinterpret_cast<::FUN_00504e60_shell *>(((*reinterpret_cast<::SettingsOwner * *>(&::DAT_011da9ac))))->FUN_00504e60()))->stopCount5;
    countsA[5] = tempA;
    tempA = ((::Settings *)(reinterpret_cast<::FUN_00504e60_shell *>(((*reinterpret_cast<::SettingsOwner * *>(&::DAT_011da9ac))))->FUN_00504e60()))->stopCount6;
    countsA[6] = tempA;
    count = 7;
    {
        int scan;
        for (scan = 0; scan < 7; scan++)
            if (countsA[scan] == 0)
                count = count - 1;
    }
    while (filled < 28)
    {
        int previous8 = filled;
        symbol = 0;
        int kindVal;
        for (kindVal = 0; kindVal < 7; kindVal++)
        {
            if (countsA[kindVal] != 0)
            {
                symbols[filled] = symbol;
                filled = filled + 1;
                symbol = symbol + 1;
                symbols[filled] = symbol;
                filled = filled + 1;
                countsA[kindVal] = countsA[kindVal] - 1;
            }
            symbol = symbol + 1;
        }
        if (previous8 == filled)
        {
            char message[260];
            ::FUN_00406d00(
                message, 260,
                "Casino Form is not setup properly. # of stops for the slot reels must sum to 14. Exiting out of Slot machine menu.");
            ::DispatchMessageToSink((const char *)(message), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds"), (int)(0), 2.0f,
                           false);
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::Sound &)(((::Audio *)(::FUN_00453a70()))->GetSoundByEditorID("UIPopUpMessageGeneral", 0x121)))->FUN_00ad8830(false);
            FUN_007c2420();
            return false;
        }
    }
    {
        int reelX;
        for (reelX = 0; reelX < 3; reelX++)
        {
            current[reelX] = reelX * 2;
            saved[reelX] = 14;
        }
    }
    return true;
}

struct SlotTextureName
{
};
struct SlotModelName
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual const char* GetPath();
};
struct SlotAssets
{
};
struct SlotTextureLoader
{
};
struct SlotModelLoader
{
};
struct SlotMachineAssets
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
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
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    bool loading;
    void* machine;
    void* reel1;
    void* reel2;
    void* reel3;
    void* symbols[7];
    void* special;
    bool LoadAssets();
};
// @fnv 0x007c1490
bool SlotMachineAssets::LoadAssets()
{
    if (DAT_011da9ac)
    {
        char path[260];
        char normalized[260];
        for (int i = 0; i < 7; ++i)
        {
            if (DAT_011da9ac)
            {
                ::FUN_00406d00(path, 260, "%s%s", "Textures\\",
                             ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::SlotTextureName *)(reinterpret_cast<::FUN_00504e20_shell *>((reinterpret_cast<SlotAssets*>(DAT_011da9ac)))->FUN_00504e20(i)))))->FUN_00408da0())));
                ::ConvertLocalizedString(path, normalized, 260);
                reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::SlotTextureLoader * *>(&::g_TES))))->FUN_004568c0(normalized, (*(::TexPtr< ::NiSourceTexture> *)(&symbols[i])), false, false);
            }
        }
        ::FUN_00406d00(path, 260, "%sNV_SlotMachine-Symbol%s.dds", "Textures\\terminals\\NV_SlotMachine\\", "S");
        ::ConvertLocalizedString(path, normalized, 260);
        reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::SlotTextureLoader * *>(&::g_TES))))->FUN_004568c0(normalized, (*(::TexPtr< ::NiSourceTexture> *)(&special)), false, false);
        machine = ((void *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::SlotModelLoader * *>(&::g_modelLoader))))->FUN_00447080((char *)(((::SlotModelName *)(reinterpret_cast<::FUN_00504e00_shell *>((reinterpret_cast<SlotAssets*>(DAT_011da9ac)))->FUN_00504e00(7)))->GetPath()), 0,
                                             true, false, false, false)));
        reel1 = ((void *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::SlotModelLoader * *>(&::g_modelLoader))))->FUN_00447080((char *)("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel01.NIF"), 0, true,
                                           false, false, false)));
        reel2 = ((void *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::SlotModelLoader * *>(&::g_modelLoader))))->FUN_00447080((char *)("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel02.NIF"), 0, true,
                                           false, false, false)));
        reel3 = ((void *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>(((*reinterpret_cast<::SlotModelLoader * *>(&::g_modelLoader))))->FUN_00447080((char *)("Meshes\\terminals\\NV_SlotMachine\\NV_SlotMachine-Reel03.NIF"), 0, true,
                                           false, false, false)));
        loading = false;
        return reinterpret_cast<::Reels *>(this)->InitReels();
    }
    return false;
}

#include <stdlib.h>
struct SlotReelLogic
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
    int values[0x27];
    int iTolerance;  // 0xc8
    int unkCC;
    int iValueCount;  // 0xd0
    int unkD4;
    bool bChanged;  // 0xd8
    int unkDC;
    int unkE0;
    int unkE4;
    int reels[3];  // 0xe8

    int FUN_007c56e0();
    bool AdjustReels(int a);
};

// @fnv 0x007c58f0
bool SlotReelLogic::AdjustReels(int a)
{
    int base = abs((iTolerance - 5) * 10);
    if (((int)(::GetRandomNumberInRange(0, 100))) + base > 100)
    {
        int r0 = reels[0];
        int R = reels[1];
        int r2 = reels[2];
        if (iTolerance - 5 >= 0)
        {
            switch (a)
            {
            case 0:
                while (FUN_007c56e0() < a)
                {
                }
                return AdjustReels(reinterpret_cast<::FUN_007c5760_shell *>(this)->FUN_007c5760());
                break;
            case 2:
                if (reels[0] == 12)
                {
                    reels[1] = values[((int)(::GetRandomNumberInRange(0, iValueCount))) * 2];
                    reels[2] = values[((int)(::GetRandomNumberInRange(0, iValueCount))) * 2];
                }
                else if (reels[1] == 12)
                {
                    reels[0] = values[((int)(::GetRandomNumberInRange(0, iValueCount))) * 2];
                    reels[2] = values[((int)(::GetRandomNumberInRange(0, iValueCount))) * 2];
                }
                else
                {
                    reels[0] = values[((int)(::GetRandomNumberInRange(0, iValueCount))) * 2];
                    reels[1] = values[((int)(::GetRandomNumberInRange(0, iValueCount))) * 2];
                }
                if (reinterpret_cast<::FUN_007c5760_shell *>(this)->FUN_007c5760() > a)
                {
                    return true;
                }
                break;
            case 4: {
                int wild = 0;
                int odd2 = -1;
                int diff = 0;
                for (int i = 0; i < 3; i++)
                {
                    switch (reels[i])
                    {
                    case 12:
                        wild = i;
                    }
                    if (reels[i] % 2)
                    {
                        odd2 = i;
                    }
                }
                int prevM = (wild - 1 >= 0) ? wild - 1 : 2;
                int next = (wild + 1 < 2) ? wild + 1 : 0;
                diff = abs(reels[prevM] - reels[next]);
                if (diff <= iTolerance && odd2 < 0)
                {
                    reels[prevM] = reels[next];
                    return true;
                }
                else if (diff <= iTolerance)
                {
                    if (prevM == odd2)
                    {
                        reels[prevM] = reels[next];
                    }
                    else
                    {
                        reels[next] = reels[prevM];
                    }
                    return true;
                }
                break;
            }
            case 1:
            case 5:
                if (reels[0] == reels[1])
                {
                    int k = iTolerance - 5;
                    int d = abs(reels[0] - reels[2]);
                    d = d * d;
                    if (d <= iTolerance)
                    {
                        reels[2] = reels[0];
                        return true;
                    }
                }
                else if (reels[0] == reels[2])
                {
                    int k = iTolerance - 5;
                    int d = abs(reels[0] - reels[1]);
                    d = d * d;
                    if (d <= iTolerance)
                    {
                        reels[1] = reels[0];
                        return true;
                    }
                }
                else
                {
                    int k = iTolerance - 5;
                    int d = abs(reels[1] - reels[0]);
                    d = d * d;
                    if (d <= iTolerance)
                    {
                        reels[0] = reels[1];
                        return true;
                    }
                }
                break;
            }
        }
        else
        {
            switch (a)
            {
                break;
            case 6:
                reels[0] = reels[1] = reels[2] = (reels[0] + 1 > 6) ? 0 : reels[0] + 1;
                bChanged = true;
                break;
            case 4:
            case 5:
                for (int j = 0; j < 3; j++)
                {
                    if (reels[j] == 12)
                    {
                        reels[j] = 13;
                    }
                }
                bChanged = true;
                break;
            }
        }
    }
    return false;
}

namespace fnv_007c2460 {
struct SlotsTile
{
};
struct FUN_0041a250
{
    unsigned int id, flags;
    void* data;
    ~FUN_0041a250();
};
struct SlotsAudio
{
    FUN_0041a250 FUN_00ad7550(const char*, int, int);
};
struct SlotsMenu
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
    int state;
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
    int result;
    SlotsTile* tile;
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
    int bet;
    int unkd0;
    int funds;
    bool won;
    unsigned char unkd9, unkda, unkdb;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int soundIndex;
    int FUN_007c56e0();
    void FUN_007c2460(int, void*);
};
// Processes input actions for the slots menu, adjusting the bet, starting a spin, or transitioning between states based on the current state.
// @fnv 0x007c2460
void SlotsMenu::FUN_007c2460(int action, void* target)
{
    if (state == 6)
    {
        switch (action)
        {
        case 8:
            ::FUN_007c2420();
            break;
        case 3:
            if (funds < bet)
                break;
            soundIndex = 1;
            result = FUN_007c56e0();
            won = reinterpret_cast<::SlotReelLogic *>(this)->AdjustReels(result);
            result = reinterpret_cast<::FUN_007c5760_shell *>(this)->FUN_007c5760();
            state = 1;
            ::TopicMenuController::IncrementMiscStat(42);
            break;
        case 4: {
            int iOldBet = bet;
            if (bet < 10)
                bet += 1;
            else if (bet < 40)
                bet += 5;
            else if (bet < 100)
                bet += 10;
            else if (bet < 500)
                bet += 25;
            else
                bet += 100;
            if (bet > funds)
                bet = funds;
            if (bet > ::fnv_007c0a40::DAT_011a0828)
                bet = ::fnv_007c0a40::DAT_011a0828;
            reinterpret_cast<::FUN_00a01290_shell *>(((*reinterpret_cast<::fnv_007c2460::SlotsMenu * *>(&::DAT_011da9a4))->tile))->SetTraitAndReset(::fnv_007c06f0::g_traitX, 1.0f);
            reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_007c2460::SlotsMenu * *>(&::DAT_011da9a4))->tile))->Set(::fnv_007c06f0::g_traitX, bet);
            if (iOldBet != bet)
            {
                char sound[260];
                ::FUN_00406d00(sound, 260, "GAMESlotsIncreaseBet0%i", soundIndex);
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c2460::FUN_0041a250 &)(((::fnv_007c2460::SlotsAudio *)(::FUN_00453a70()))->FUN_00ad7550(sound, 289, 0)))->FUN_00ad8830({});
                soundIndex = soundIndex + 1 > 3 ? 1 : soundIndex + 1;
            }
            break;
        }
        case 5: {
            int iOldBet = bet;
            if (bet <= 10)
                bet -= 1;
            else if (bet <= 40)
                bet = bet % 5 ? bet / 5 * 5 : bet - 5;
            else if (bet <= 100)
                bet = bet % 10 ? bet / 10 * 10 : bet - 10;
            else if (bet <= 500)
                bet = bet % 25 ? bet / 25 * 25 : bet - 25;
            else
                bet = bet % 100 ? bet / 100 * 100 : bet - 100;
            if (bet < ::fnv_007c0a40::DAT_011a082c)
                bet = ::fnv_007c0a40::DAT_011a082c;
            reinterpret_cast<::FUN_00a01290_shell *>(((*reinterpret_cast<::fnv_007c2460::SlotsMenu * *>(&::DAT_011da9a4))->tile))->SetTraitAndReset(::fnv_007c06f0::g_traitX, 1.0f);
            reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_007c2460::SlotsMenu * *>(&::DAT_011da9a4))->tile))->Set(::fnv_007c06f0::g_traitX, bet);
            if (iOldBet != bet)
            {
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c2460::FUN_0041a250 &)(((::fnv_007c2460::SlotsAudio *)(::FUN_00453a70()))->FUN_00ad7550("GAMESlotsDecreaseBet", 289, 0)))->FUN_00ad8830({});
                soundIndex = 1;
            }
            break;
        }
        case 6:
            state = 4;
            break;
        case 7:
            if (bet != ::fnv_007c0a40::DAT_011a0828)
            {
                bet = ::fnv_007c0a40::DAT_011a0828;
                if (bet > funds)
                    bet = funds;
                reinterpret_cast<::FUN_00a01290_shell *>(((*reinterpret_cast<::fnv_007c2460::SlotsMenu * *>(&::DAT_011da9a4))->tile))->SetTraitAndReset(::fnv_007c06f0::g_traitX, 1.0f);
                reinterpret_cast<::Tile *>(((*reinterpret_cast<::fnv_007c2460::SlotsMenu * *>(&::DAT_011da9a4))->tile))->Set(::fnv_007c06f0::g_traitX, bet);
                char sound[260];
                ::FUN_00406d00(sound, 260, "GAMESlotsIncreaseBet0%i", soundIndex);
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_007c2460::FUN_0041a250 &)(((::fnv_007c2460::SlotsAudio *)(::FUN_00453a70()))->FUN_00ad7550(sound, 289, 0)))->FUN_00ad8830({});
                soundIndex = soundIndex + 1 > 3 ? 1 : soundIndex + 1;
            }
            break;
        }
    }
    else if (state == 4)
        state = 5;
}
}  // namespace fnv_007c2460

#include "generated/data/fallout/interface/menus/slotmachinemenu.inc"
