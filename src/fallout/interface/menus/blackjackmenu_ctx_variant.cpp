
// blackjackmenu_ctx_variant.cpp: context variant of src/fallout/interface/menus/blackjackmenu.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/fallout/interface/menus/blackjackmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/blackjackmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/ActorValueOwner.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatState.h"
#include "fnv/decl/ContainerOperation.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_00504e40_shell.h"
#include "fnv/decl/FUN_00504e60_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_007316d0_Class.h"
#include "fnv/decl/FUN_00737e30_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00c4f270_Class.h"
#include "fnv/decl/FUN_00c4f2d0_class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/Menu.h"
#include "fnv/decl/MiddleLowProcess.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/PickupSoundActorView.h"
#include "fnv/decl/S00739970.h"
#include "fnv/decl/SSN_b5.h"
#include "fnv/decl/TESQuest.h"
#include "fnv/decl/Target2180.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TimeCounter.h"
#include "fnv/decl/TopicMenuController.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_004818e0__FUN_004818e0_t.h"
#include "fnv/decl/fnv_00731800__FUN_00731800.h"
#include "fnv/decl/fnv_00731d70__This731.h"
#include "fnv/decl/fnv_007395a0__FUN_007395a0_shell.h"
#include "fnv/decl/fnv_0073ab40__FUN_0073ab40_shell.h"
#include "fnv/decl/fnv_007fd640__FUN_007fd640Class.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
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
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005a6000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00733000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_0101c000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01025000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_0103a000.h"
#include "fnv/symbols_01049000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
struct FUN_007316f0_shell
{
    void ClearField();
};
struct BlackJackMenu
{
    int __thiscall FUN_00731790();
};
int __cdecl FUN_00733f80();
struct FUN_007399d0_shell
{
    void FUN_007399d0();
};
struct FUN_00734d30_shell
{
    int __thiscall HasFlag(int aFlag);
};
struct FUN_007317d0_shell
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
struct Helper731800
{
};
struct Proc_S
{
};
struct Tile
{
public:
    void Set(int, int);
public:
    static float GetInterfaceScale();
};
struct DAT_011d9050_S
{
    char _pad[0x28];
    int v28;
};
void FUN_00731d30();
struct Helper62d0
{
    void* operator=(const void*);
};
struct FUN_007324f0_shell
{
    int m0;
    int m4;
    int m8;
    int mC;
    FUN_007324f0_shell& operator=(const FUN_007324f0_shell&);
};
struct FUN_00733f50_shell
{
    int m0;
    int m1;
    short m2;
    FUN_00733f50_shell* FUN_00733f50();
};
struct FUN_00733f90_shell
{
    char __thiscall FUN_00733f90();
};
struct FUN_00738fb0_shell
{
    int __thiscall GetAdjustedValue(int a1);
};
struct NiAVObject
{
};
struct SceneObjectLookup
{
};
struct FUN_00739ad0_Holder
{
    char _pad[0xDB4];
    NiAVObject* m_pTreeNode;
    void __thiscall HideArrowNodes();
};
struct FUN_00733fd0_shell
{
    char _pad_0[0xf8];
    float m_fMinimum;  // +0xf8
    void __thiscall FUN_00733fd0(float fMin);
};
struct FUN_00734d50_holder
{
    unsigned char _pad[0xDB0];
    int _flags;
    void SetFlag(int flag, bool value);
};
class AnimIdle;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    NiPointer& operator=(T*);
    operator T*() const;
};
struct S148c0
{
    void FUN_007148c0(int, int);
};
struct Accum_00733500
{
};
struct Node_00733500
{
};
struct Mgr_00733500
{
};
class BSShaderAccumulator;
class NiCamera;
struct BSShaderRenderUtility
{
public:
    static void SetRenderCamera(::NiCamera *, ::BSShaderAccumulator *, bool);
};
void __cdecl FUN_00733500();
struct FUN_00739650_shell : FUN_00734d50_holder
{
    bool FUN_00739650(bool bFlag);
};
struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bForce;
    unsigned char _padding[6];

    NiUpdateData(float, bool, bool);
};
class NiAVObject;
struct NiNode
{
public:
    ::NiAVObject *GetAt(unsigned int);
};
struct LodObject
{
};
struct GO
{
    operator unsigned int() const;
};
extern char str_01070e34[];
extern char str_01070e20[];
extern char str_01070e0c[];
extern char str_01070dfc[];
extern char str_01070de8[];
extern char str_01070dd4[];
extern char str_01070dc4[];
extern char str_01070db0[];
extern char str_01070d9c[];
struct FUN_00738270_shell
{
    unsigned char _pad[0xdb8];
    NiAVObject* m_pCardObject1;
    NiAVObject* m_pCardObject2;
    NiAVObject* m_pCardObject3;

    void __thiscall UncullCardObjects();
};
struct StartMenu
{
};
struct FUN_00a01290_shell
{
    void __thiscall SetTraitAndReset(int, float);
};
struct P09TileS
{
};
struct Tile2
{
};
struct FUN_00738c30_shell
{
    void __thiscall FUN_00738c30(int, float);
};
struct BlackJackMenu_Layout
{
    char _pad[0x40];
    Tile* m40;
    Tile* m44;
    Tile* m48;
    Tile* m4C;
    Tile* m50;
    Tile* m54;
};
void __cdecl UpdateBetTiles(bool bBetTiles);
struct Padding16ByteBlock
{
    int _pad[4];
};
struct G2
{
    bool __thiscall _ref_008256d0();
    void __thiscall _ref_00726c60(Padding16ByteBlock* const& value);
    void __thiscall AddHead(Padding16ByteBlock* const& value);
};
struct SoundListView
{
};
struct FUN_007393f0_shell
{
    unsigned char _pad0[0x2c];
    int _handResult0;
    int _handResult1;
    unsigned char _pad1[0x5c];
    Padding16ByteBlock _deck[208];
    G2* _dealerHand;
    G2* _playerHand;


    void __thiscall DealInitialCards();
};
extern "C" void* _ReadWriteBarrier_unused;
struct SetBase
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;

    SetBase();
    virtual ~SetBase();
};
struct SetElem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SetElem();
    ~SetElem();
};
struct SetMgr
{
};
struct SetMgrB
{
};
struct SetMgrC
{
    void ClearField();
};
extern void* DAT_011d9048;
class FUN_007315e0 : public SetBase
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
    void* m74;
    unsigned int unk78;
    unsigned int m7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    SetElem m90[208];

    FUN_007315e0();
    virtual ~FUN_007315e0();
    void ClearField();
};
struct Member731710A
{
    int m_00;
    Member731710A(int v);
    ~Member731710A();
};
struct Member731710B
{
    int m_00;
    Member731710B(int v);
};
struct FUN_00731710_cls
{
    int m_00;
    int m_04;
    Member731710A m_08;
    Member731710B m_0c;

    FUN_00731710_cls();
};
struct Local12_cls
{
    int m0;
    int m4;
    int m8;
};
struct Node_cls
{
};
struct Tail2_cls
{
};
struct Tail1_cls
{
};
struct Mgr_cls
{
};
extern char str_01070e58[];
extern char str_01070e44[];
struct FUN_007399f0_cls
{
    unsigned char _pad0[0xdb4];
    int m_db4;

    void __thiscall FUN_007399f0();
};
struct ChipNodeX
{
};
struct UpdateDataX
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    short sPad;
    int iActionIndex;
    UpdateDataX(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};
struct RootNodeX
{
};
struct RootPtrX
{
    RootNodeX* m_pObject;
    operator RootNodeX*() const;
};
struct BlackJackChipsX
{
    char _pad00[0x6c];
    int iBet;
    char _pad70[0xdc4 - 0x70];
    ChipNodeX* apChips[12];
    void UpdateChipPositions();
};
struct String90
{
    const char* value;
    String90(const char*);
    ~String90();
};
struct Controller90
{
};
struct Bound90
{
};
struct Update90
{
    float time;
    bool update, force;
    unsigned short unk06;
    int unk08;
    Update90(float, bool, bool);
};
struct Property90;
struct Node90
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
    virtual void v0dc(Node90*, int);
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0(int, int, Node90*);
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
    Node90(int);
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct Pointer90
{
    Node90* p;
    Pointer90& FUN_0066b0d0(Node90*);
};
struct Loader90
{
};
struct Menu90
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
    Pointer90 scene;
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
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    Node90* rootdb4;
    Node90* rootdb8;
    Node90* rootdbc;
    Node90* rootdc0;
    Node90* cards[6];
    Node90* backs[6];
    Controller90* ctrldf4;
    Controller90* ctrldf8;
    Controller90* ctrldfc;
    Controller90* ctrle00;
    void* anime04;
    void* anime08;
    void* anime0c;
    void* anime10;
    void* anime14;
    void* anime18;
    void* anime1c;
    void* anime20;
    void* anime24;
    void* anime28;
    void* anime2c;
    void* anime30;
    void* anime34;
    void* anime38;
    void* anime3c;
    void* anime40;
    void* anime44;
    void* anime48;
    void* anime4c;
    void* anime50;
    void* anime54;
    void* anime58;
    void* anime5c;
    void* anime60;
    void* anime64;
    void* anime68;
    void* anime6c;
    void InitBlackjackScene();
};
struct FUN_00733f50
{
    int id;
    int amount;
    short flags;
    FUN_00733f50();
};
struct Node129
{
    bool FUN_008256d0();
    void FUN_00726c60(FUN_00733f50* const&);
    void FUN_005ae3d0(FUN_00733f50* const&);
};
struct Settings129
{
    const char* FUN_00403df0();
};
struct BSSoundHandleEx
{
    int id;
    int flags;
    int state;
    ~BSSoundHandleEx();
};
struct Audio129
{
    BSSoundHandleEx FUN_00ad7550(const char*, int);
};
struct Stats129
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
    int limit;
};
struct Name129
{
};
struct Casino129
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0C();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1C();
    virtual int v20();
    virtual int v24();
    virtual int v28();
    virtual int v2C();
    virtual int v30();
    virtual int v34();
    virtual int v38();
    virtual int v3C();
    virtual int v40();
    virtual int v44();
    virtual int v48();
    virtual int v4C();
    virtual int v50();
    virtual int v54();
    virtual int v58();
    virtual int v5C();
    virtual int v60();
    virtual int v64();
    virtual int v68();
    virtual int v6C();
    virtual int v70();
    virtual int v74();
    virtual int v78();
    virtual int v7C();
    virtual int v80();
    virtual int v84();
    virtual int v88();
    virtual int v8C();
    virtual int v90();
    virtual int v94();
    virtual int v98();
    virtual int v9C();
    virtual int vA0();
    virtual int vA4();
    virtual int vA8();
    virtual int vAC();
    virtual int vB0();
    virtual int vB4();
    virtual int vB8();
    virtual int vBC();
    virtual int vC0();
    virtual int vC4();
    virtual int vC8();
    virtual int vCC();
    virtual int vD0();
    virtual int vD4();
    virtual int vD8();
    virtual int vDC();
    virtual int vE0();
    virtual int vE4();
    virtual int vE8();
    virtual int vEC();
    virtual int vF0();
    virtual int vF4();
    virtual int vF8();
    virtual int vFC();
    virtual int v100();
    virtual int v104();
    virtual int v108();
    virtual int v10C();
    virtual int v110();
    virtual int v114();
    virtual int v118();
    virtual int v11C();
    virtual int v120();
    virtual int v124();
    virtual int v128();
    virtual int v12C();
    virtual const char* GetName();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Name129 name;
};
struct Tile129
{
};
struct Xml129
{
};
struct Interface129
{
};
struct Menu129
{
    virtual ~Menu129();
    virtual int v04();
    virtual int v08();
    virtual int v0C();
    virtual int v10();
    virtual int v14();
    virtual int v18();
    virtual int v1C();
    virtual int v20();
    virtual int v24();
    virtual int v28();
    virtual int v2C();
    virtual int v30();
    virtual int GetID();
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
    Tile129* tile34;
    Tile129* tile38;
    Tile129* tile3C;
    Tile129* tile40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int setting;
    int bet;
    void ClearField();
};
struct Mode129
{
};
struct Player129
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
    Mode129 mode;
};
extern int DAT_0119fe40, DAT_0119fe3c;
extern const char DAT_01070c38[], DAT_01070be0[], DAT_01070bc0[], DAT_01070ba8[];
struct Menu737e50
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
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    int unkdb4;
    NiAVObject* table;
    NiAVObject* hand;
    NiAVObject* split;
    void UpdateCulledNodes();
};
struct BlackjackButtonMenu
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int state;
    void UpdateButtonState(int);
};
struct BJCard
{
    int rank;
    int suit;
    int other;
    int ref;
    BJCard();
    ~BJCard();
    BJCard& operator=(const BJCard&);
};
int __cdecl FUN_00ec7d40(int);
struct BJDeck
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
    bool flag78;
    bool flag79;
    short unk7a;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    BJCard cards[209];
    int count;
    int DrawCard(void*, bool, bool);
};
class TESObjectREFR;
template <class C> class BSStringT
{
  public:
    operator const C*() const;
};
template <class T> class NiTPointerList
{
  public:
    T& AddEight(void* pos) const;
    void* DereferenceIfNotNull(void* pos) const;
    int* FUN_0073ac90();
};
struct FUN_00a012d0_t
{
    void FUN_00a012d0(int, float, bool);
};
struct Entry738c
{
    int m_00;
    NiTPointerList<TESObjectREFR*> m_kList;
};
struct Table738c
{
    char _pad[0x34];
    Entry738c* m_apEntries[1];
};
struct CardInfo
{
    int unk00;
    int unk04;
    Pointer90 unk08;
    Pointer90 unk0c;
};
struct TableNode : Node90
{
};
struct GlobalPtr
{
};
struct BlackjackMenuShell
{
    void FUN_007396e0(int a1, int a2, CardInfo* a3);
};
struct OwnQ
{
    int FUN_00738ff0(Node129* pList);
};
struct CardHand
{
    bool FUN_008256d0();
    void FUN_00726c60(CardInfo* const&);
    void FUN_005ae3d0(CardInfo* const&);
};
struct MenuGlobalView : Menu129
{
};
extern const char DAT_01070cc0[], DAT_01070ca4[], DAT_01070c88[];
struct InputMenu
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
    int result;
    int splitResult;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    P09TileS* text;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int bet;
    int splitBet;
    int funds;
    bool flag78;
    bool flag79;
    short unk7a;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    CardInfo cards[208];
    CardHand* dealer;
    CardHand* hand;
    CardHand* split;
    void HandleAction(int, void*);
    void ClearField();
};

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct FUN_0096a2d0
{
    BJCard* item;
    FUN_0096a2d0* next;
    FUN_0096a2d0();
};
struct GlobalObject_0041a250
{
    int id, flags, state;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
};
template <> class BSStringT<char>
{
  public:
    char* data;
    unsigned short length, capacity;
    BSStringT();
    ~BSStringT();
    operator const char*() const;
};
class TESContainer
{
  public:
    int unk00, unk04, unk08;
    TESContainer();
    ~TESContainer();
};
struct BooleanHandler
{
};
struct CasinoUpdate
{
};
struct PlayerUpdate
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
    virtual void Remove(void*, int, int, int, int, int, int, int, int, int);
};
struct TimeUpdate
{
};
bool __cdecl FUN_00702450(int);
struct InterfaceUpdate
{
};
struct SceneUpdate
{
};
struct ScenePointerUpdate
{
};
struct SequenceUpdate
{
};
struct SequenceUpdateHandler
{
};
extern float DAT_011d90e0;
extern int DAT_011d90dc;
extern const double DAT_01070d18;
extern const char DAT_01070d8c[], DAT_01070d74[], DAT_01070d5c[],
    DAT_01070d40[], DAT_01070d20[], DAT_01070d0c[], DAT_01070cf8[], DAT_01070ce4[];
struct BlackjackUpdate
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual int GetID();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int state;
    int playerResult;
    int splitResult;
    Tile129* tile34;
    Tile129* tile38;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    Tile129* message;
    int unk05c;
    float payoutMultiplier;
    float shuffleThreshold;
    int skill;
    int bet;
    int splitBet;
    int balance;
    bool luckyWin, luckyLose;
    short unk07a;
    int lastTime;
    bool reward;
    char unk081, unk082, unk083;
    int counts[3];
    BJCard cards[208];

    FUN_0096a2d0* dealer;
    FUN_0096a2d0* player;
    FUN_0096a2d0* split;
    int decks;
    int remaining;
    bool sounded;
    char unkda5, unkda6, unkda7;
    float soundTime;
    bool standSoft17;
    char unkdad, unkdae, unkdaf;
    int flags;
    NiAVObject* root;
    NiAVObject* hand;
    NiAVObject* splitHand;
    NiAVObject* dealerHand;
    int unkdc4;
    int unkdc8;
    int unkdcc;
    int unkdd0;
    int unkdd4;
    int unkdd8;
    int unkddc;
    int unkde0;
    int unkde4;
    int unkde8;
    int unkdec;
    int unkdf0;
    SequenceUpdateHandler* tableAnim;
    SequenceUpdateHandler* playerAnim;
    SequenceUpdateHandler* splitAnim;
    SequenceUpdateHandler* dealerAnim;
    SequenceUpdate* tableStart;
    SequenceUpdate* tableEnd;
    SequenceUpdate* playerSeq[8];
    SequenceUpdate* splitSeq[8];
    SequenceUpdate* dealerSeq[8];
    SequenceUpdate* revealSeq;
    void ClearField();
    void FUN_00734db0();
};

// @fnv 0x00734db0
void BlackjackUpdate::FUN_00734db0()
{
    int dt = 0;
    float speed = 1.0f;
    static GlobalObject_0041a250 sound;
    bool active = FUN_00702450(GetID());
    if (!lastTime)
    {
        player = new FUN_0096a2d0;
        split = new FUN_0096a2d0;
        dealer = new FUN_0096a2d0;
        dt = 0;
        DAT_011d90e0 = 0.0f;
        DAT_011d90dc = 0;
    }
    else if (active)
    {
        dt = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeUpdate *>(&::g_timeGlobal))))->FUN_00825c00())) - lastTime;
        if (dt > 1000)
            dt = 0;
        if (DAT_011d90dc != state)
            DAT_011d90e0 = 0.0f;
        else
            DAT_011d90e0 += dt / 1000.0;
    }
    lastTime = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeUpdate *>(&::g_timeGlobal))))->FUN_00825c00()));
    DAT_011d90dc = state;
    if (!active)
        ((::FUN_00a012d0_t *)(reinterpret_cast<::FUN_0045cd60_shell *>((((InterfaceUpdate*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0045cd60()))->FUN_00a012d0(0xfa9, 255.0f, true);
    switch (state)
    {
    case 13:
        if (DAT_011d90e0 < 1.0)
            break;
        if (((int)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType())) != 2)
        {
            ((::FUN_00a012d0_t *)(reinterpret_cast<::FUN_0045cd60_shell *>((((InterfaceUpdate*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0045cd60()))->FUN_00a012d0(0xfa9, 255.0f, true);
            reinterpret_cast<::Tile *>((((::Tile129 *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->Set(0x1772, 1);
            reinterpret_cast<::FUN_00a1d910_shell *>(this)->FUN_00a1d910();
            int difference =
                balance - reinterpret_cast<::CombatState *>((((PlayerUpdate*)(*reinterpret_cast<::SetMgrB * *>(&::_g_thePlayer)))))->GetInventoryItemCount((::TESForm *)(void *)(((void *)(reinterpret_cast<::FUN_007316d0_Class *>((((CasinoUpdate*)DAT_011d9058)))->FUN_007316d0()))));
            if (difference < 0)
            {
                ((PlayerUpdate*)(*reinterpret_cast<::SetMgrB * *>(&::_g_thePlayer)))
                    ->Remove(((void *)(reinterpret_cast<::FUN_007316d0_Class *>((((CasinoUpdate*)DAT_011d9058)))->FUN_007316d0())), 0, -difference, 0, 0, 0, 0, 0, 1, 0);
                BSStringT<char> msg;
                ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT<char> *)(&msg), DAT_0101c178, -difference,
                             ::FUN_00482720((::TESForm *)(void *)(((void *)(reinterpret_cast<::FUN_007316d0_Class *>((((CasinoUpdate*)DAT_011d9058)))->FUN_007316d0())))), (*reinterpret_cast<::Settings129 *>(&::g_011d3114)).FUN_00403df0(),
                             (*reinterpret_cast<::Settings129 *>(&::g_011d3db4)).FUN_00403df0());
                ::DispatchMessageToSink((int)(msg), 0, (int)(::g_011cba18_arg1),
                                      (int)reinterpret_cast<::PickupSoundActorView *>((((PlayerUpdate*)(*reinterpret_cast<::SetMgrB * *>(&::_g_thePlayer)))))->FUN_008adcf0((::TESBoundObject *)(void *)(((void *)(reinterpret_cast<::FUN_007316d0_Class *>((((CasinoUpdate*)DAT_011d9058)))->FUN_007316d0()))), 1, false),
                                      ::DAT_010162c0, 0);
            }
            else if (difference > 0)
            {
                TESContainer inventory;
                reinterpret_cast<::fnv_004818e0::FUN_004818e0_t *>(&(inventory))->FUN_004818e0((::TESObject *)(void *)(((void *)(reinterpret_cast<::FUN_007316d0_Class *>((((CasinoUpdate*)DAT_011d9058)))->FUN_007316d0()))), difference, (::ContainerItemExtra *)(void *)(0));
                if (DAT_011d9054->amount < ((int)(reinterpret_cast<::FUN_00737e30_shell *>((((CasinoUpdate*)DAT_011d9058)))->GetFieldAt210())))
                    reinterpret_cast<::ContainerOperation *>(&(inventory))->FUN_004821a0((::TESObjectREFR *)((*reinterpret_cast<::SetMgrB * *>(&::_g_thePlayer))), false);
                else
                {
                    reinterpret_cast<::ContainerOperation *>(&(inventory))->FUN_004821a0((::TESObjectREFR *)((*reinterpret_cast<::SetMgrB * *>(&::_g_thePlayer))), true);
                    BSStringT<char> msg2;
                    ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT<char> *)(&msg2), DAT_01070d8c, difference,
                                 ::FUN_00482720((::TESForm *)(void *)(((void *)(reinterpret_cast<::FUN_007316d0_Class *>((((CasinoUpdate*)DAT_011d9058)))->FUN_007316d0())))),
                                 (*reinterpret_cast<::Settings129 *>(&::g_011d3114)).FUN_00403df0(), (*reinterpret_cast<::Settings129 *>(&::g_011d4e7c)).FUN_00403df0(), (*reinterpret_cast<::Settings129 *>(&::g_011d3abc)).FUN_00403df0());
                    ::DispatchMessageToSink((int)(msg2), 0, (int)(::g_011cba00_arg1),
                                          (int)reinterpret_cast<::PickupSoundActorView *>((((PlayerUpdate*)(*reinterpret_cast<::SetMgrB * *>(&::_g_thePlayer)))))->FUN_008adcf0((::TESBoundObject *)(void *)(((void *)(reinterpret_cast<::FUN_007316d0_Class *>((((CasinoUpdate*)DAT_011d9058)))->FUN_007316d0()))), 1, false),
                                          ::DAT_010162c0, 0);
                }
            }
            if (reward)
            {
                BooleanHandler* quest = ((::BooleanHandler *)(reinterpret_cast<::FUN_00504e40_shell *>((((CasinoUpdate*)DAT_011d9058)))->FUN_00504e40()));
                if (quest)
                    reinterpret_cast<::TESQuest *>((quest))->SetEnabled(true);
            }
        }
        break;
    case 1: {
        int previous = counts[2];
        float half = reinterpret_cast<::FUN_00508100_shell *>((playerSeq[previous]))->FUN_00508100() / 2.0;
        static float endTime = reinterpret_cast<::FUN_00508100_shell *>((playerSeq[1]))->FUN_00508100();
        if (dealerSeq[previous] && playerSeq[previous])
        {
            if (DAT_011d90e0 > 1.0)
                reinterpret_cast<::Tile *>((message))->Set(0xfa3, 0);
            Update90 scene(DAT_011d90e0, true, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(0)))))->FUN_00a59c60((int)&(scene));
            if (DAT_011d90e0 == 0.0)
            {
                Update90 reset(0.0f, true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->FUN_00a59c60((int)&(reset));
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01070d74, 0x121)))->FUN_00ad8830(false);
                sounded = true;
                FUN_0096a2d0* p = player;
                FUN_0096a2d0* dealerNode = dealer;
                reinterpret_cast<::BlackjackMenuShell *>(this)->FUN_007396e0(0, 1, (::CardInfo *)(*((::BJCard **)(new ((void *)(p)) ::Vec3()))));
                p = ((::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
                reinterpret_cast<::BlackjackMenuShell *>(this)->FUN_007396e0(0, 2, (::CardInfo *)(*((::BJCard **)(new ((void *)(p)) ::Vec3()))));
                reinterpret_cast<::BlackjackMenuShell *>(this)->FUN_007396e0(2, 1, (::CardInfo *)(*((::BJCard **)(new ((void *)(dealerNode)) ::Vec3()))));
                dealerNode = ((::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((dealerNode))->FUN_00726070()));
                reinterpret_cast<::BlackjackMenuShell *>(this)->FUN_007396e0(2, 2, (::CardInfo *)(*((::BJCard **)(new ((void *)(dealerNode)) ::Vec3()))));
                reinterpret_cast<::NiControllerManager *>((playerAnim))->ActivateControllerSequence((::NiControllerSequence *)(playerSeq[1]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::NiControllerManager *>((dealerAnim))->ActivateControllerSequence((::NiControllerSequence *)(dealerSeq[1]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                endTime = reinterpret_cast<::FUN_00508100_shell *>((playerSeq[1]))->FUN_00508100();
            }
            if (counts[0] == 1)
            {
                Update90 pu(DAT_011d90e0, true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(1)))))->FUN_00a59c60((int)&(pu));
            }
            if (counts[2] == 1 && DAT_011d90e0 >= half)
            {
                if (sounded && DAT_011d90e0 < reinterpret_cast<::FUN_00508100_shell *>((playerSeq[1]))->FUN_00508100())
                {
                    sounded = false;
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01070d74, 0x121)))->FUN_00ad8830(false);
                }
                Update90 du(DAT_011d90e0 - half, true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(3)))))->FUN_00a59c60((int)&(du));
            }
            if (counts[0] == 2 && DAT_011d90e0 >= reinterpret_cast<::FUN_00508100_shell *>((playerSeq[1]))->FUN_00508100())
            {
                if (!sounded && DAT_011d90e0 < reinterpret_cast<::FUN_00508100_shell *>((playerSeq[1]))->FUN_00508100() + half)
                {
                    sounded = true;
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01070d74, 0x121)))->FUN_00ad8830(false);
                }
                Update90 pu2(DAT_011d90e0 - reinterpret_cast<::FUN_00508100_shell *>((playerSeq[previous]))->FUN_00508100(), true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(1)))))->FUN_00a59c60((int)&(pu2));
            }
            if (counts[2] == 2 && DAT_011d90e0 >= reinterpret_cast<::FUN_00508100_shell *>((playerSeq[1]))->FUN_00508100() + half)
            {
                if (sounded)
                {
                    sounded = false;
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01070d5c, 0x121)))->FUN_00ad8830(false);
                }
                Update90 du2(DAT_011d90e0 - (reinterpret_cast<::FUN_00508100_shell *>((playerSeq[1]))->FUN_00508100() + half), true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(3)))))->FUN_00a59c60((int)&(du2));
            }
            if (DAT_011d90e0 >= endTime)
            {
                if (counts[0] == 1)
                {
                    counts[0]++;
                    reinterpret_cast<::NiControllerManager *>((playerAnim))->StopSequence((::NiControllerSequence *)(playerSeq[previous]), 0.0f);
                    reinterpret_cast<::NiControllerManager *>((playerAnim))->ActivateControllerSequence((::NiControllerSequence *)(playerSeq[counts[0]]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                    endTime = reinterpret_cast<::FUN_00508100_shell *>((dealerSeq[1]))->FUN_00508100() + half;
                }
                else if (counts[2] == 1)
                {
                    counts[2]++;
                    reinterpret_cast<::NiControllerManager *>((dealerAnim))->StopSequence((::NiControllerSequence *)(dealerSeq[previous]), 0.0f);
                    reinterpret_cast<::NiControllerManager *>((dealerAnim))->ActivateControllerSequence((::NiControllerSequence *)(dealerSeq[counts[2]]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                    endTime = reinterpret_cast<::FUN_00508100_shell *>((playerSeq[1]))->FUN_00508100() + reinterpret_cast<::FUN_00508100_shell *>((dealerSeq[1]))->FUN_00508100();
                }
                else if (counts[0] == 2)
                {
                    counts[0]++;
                    reinterpret_cast<::NiControllerManager *>((playerAnim))->StopSequence((::NiControllerSequence *)(playerSeq[previous]), 0.0f);
                    endTime = reinterpret_cast<::FUN_00508100_shell *>((dealerSeq[1]))->FUN_00508100() + half + reinterpret_cast<::FUN_00508100_shell *>((dealerSeq[2]))->FUN_00508100();
                }
                else
                {
                    int value = reinterpret_cast<::OwnQ *>(this)->FUN_00738ff0((::Node129 *)(player));
                    if (value == 21)
                    {
                        playerResult = 5;
                        reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x20, true);
                    }
                    if (reinterpret_cast<::OwnQ *>(this)->FUN_00738ff0((::Node129 *)(dealer)) == 21)
                    {
                        reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x20, true);
                        if (playerResult == 5)
                            playerResult = 2;
                        else
                            playerResult = 1;
                    }
                    if (!((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x20))))
                        UpdateBetTiles(false);
                    if (balance >= bet * 2)
                    {
                        if (value == 11)
                            reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x40, true);
                        else
                            reinterpret_cast<::fnv_007395a0::FUN_007395a0_shell *>(this)->FUN_007395a0();
                    }
                    else
                    {
                        reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x40, false);
                        reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x100, false);
                        reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(4, false);
                    }
                    reinterpret_cast<::BlackjackButtonMenu *>(this)->UpdateButtonState(10);
                    endTime = 0.0f;
                    counts[2]++;
                    reinterpret_cast<::NiControllerManager *>((dealerAnim))->StopSequence((::NiControllerSequence *)(dealerSeq[previous]), 0.0f);
                    if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x20))))
                        state = 8;
                    else
                        state = 4;
                }
            }
        }
        break;
    }
    case 2: {
        bool onSplit = ((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x10)));
        if (onSplit)
        {
            if (!splitSeq[counts[1]])
                break;
        }
        else
        {
            if (!playerSeq[counts[0]])
                break;
        }
        if (DAT_011d90e0 > 1.0)
            reinterpret_cast<::Tile *>((message))->Set(0xfa3, 0);
        Update90 scene(DAT_011d90e0, true, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(0)))))->FUN_00a59c60((int)&(scene));
        if (DAT_011d90e0 == 0.0)
        {
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01070d74, 0x121)))->FUN_00ad8830(false);
            FUN_0096a2d0* curr = 0;
            BJCard* last = 0;
            int drawn = 0;
            int handId = 0;
            if (onSplit)
            {
                handId = 1;
                reinterpret_cast<::NiControllerManager *>((splitAnim))->ActivateControllerSequence((::NiControllerSequence *)(splitSeq[counts[1]]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                curr = split;
                while (curr && *((::BJCard **)(new ((void *)(curr)) ::Vec3())) && drawn != counts[1])
                {
                    last = *((::BJCard **)(new ((void *)(curr)) ::Vec3()));
                    curr = ((::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((curr))->FUN_00726070()));
                    drawn++;
                }
            }
            else
            {
                reinterpret_cast<::NiControllerManager *>((playerAnim))->ActivateControllerSequence((::NiControllerSequence *)(playerSeq[counts[0]]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                curr = player;
                while (curr && *((::BJCard **)(new ((void *)(curr)) ::Vec3())) && drawn != counts[0])
                {
                    last = *((::BJCard **)(new ((void *)(curr)) ::Vec3()));
                    curr = ((::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((curr))->FUN_00726070()));
                    drawn++;
                }
            }
            while (curr && *((::BJCard **)(new ((void *)(curr)) ::Vec3())) && drawn)
            {
                last = *((::BJCard **)(new ((void *)(curr)) ::Vec3()));
                curr = ((::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((curr))->FUN_00726070()));
                drawn++;
            }
            reinterpret_cast<::BlackjackMenuShell *>(this)->FUN_007396e0(handId, drawn, (::CardInfo *)(last));
        }
        Update90 hu(DAT_011d90e0, true, false);
        if (onSplit)
            reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(2)))))->FUN_00a59c60((int)&(hu));
        else
            reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(1)))))->FUN_00a59c60((int)&(hu));
        if ((onSplit && DAT_011d90e0 >= reinterpret_cast<::FUN_00508100_shell *>((splitSeq[counts[1]]))->FUN_00508100()) ||
            (!onSplit && DAT_011d90e0 >= reinterpret_cast<::FUN_00508100_shell *>((playerSeq[counts[0]]))->FUN_00508100()))
        {
            if (onSplit)
            {
                reinterpret_cast<::NiControllerManager *>((splitAnim))->StopSequence((::NiControllerSequence *)(splitSeq[counts[1]]), 0.0f);
                counts[1]++;
            }
            else
            {
                reinterpret_cast<::NiControllerManager *>((playerAnim))->StopSequence((::NiControllerSequence *)(playerSeq[counts[0]]), 0.0f);
                counts[0]++;
            }
            if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x4000))))
                state = 3;
            else if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x1000))))
                state = 8;
            else if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(8))) && ((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x400))) && ((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x800))))
                state = 8;
            else if (!((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(8))) && ((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x400))))
                state = 8;
            else
                state = 4;
        }
        break;
    }
    case 3:
        if (!splitSeq[1] || !splitSeq[2] || !playerSeq[2])
            break;
        if (counts[1] == 1)
        {
            reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x4000, true);
            reinterpret_cast<::S00739970 *>(this)->FUN_00739970(true);
            reinterpret_cast<::NiControllerManager *>((playerAnim))->ActivateControllerSequence((::NiControllerSequence *)(playerSeq[2]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            Update90 pu(0.0f, true, false);
            Update90 du(0.0f, true, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(3)))))->FUN_00a59c60((int)&(du));
            reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(1)))))->FUN_00a59c60((int)&(pu));
            reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x10, true);
            counts[0]--;
            state = 2;
        }
        else if (counts[0] == 2)
        {
            reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x10, false);
            state = 2;
        }
        else if (counts[1] == 2)
        {
            reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x10, true);
            state = 2;
        }
        else
        {
            reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x4000, false);
            reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x10, false);
            if (playerResult == 5 && splitResult == 5)
                state = 12;
            else
                state = 4;
        }
        break;
    case 7:
        if (playerSeq[0] && splitSeq[0] && dealerSeq[0])
        {
            if (DAT_011d90e0 > 1.0)
                reinterpret_cast<::Tile *>((message))->Set(0xfa3, 0);
            if (DAT_011d90e0 == 0.0 && !sounded)
            {
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01070d40, 0x121)))->FUN_00ad8830(false);
                Update90 reset(0.0f, true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->FUN_00a59c60((int)&(reset));
                reinterpret_cast<::NiControllerManager *>((tableAnim))->ActivateControllerSequence((::NiControllerSequence *)(tableStart), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::NiControllerManager *>((playerAnim))->ActivateControllerSequence((::NiControllerSequence *)(playerSeq[0]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::NiControllerManager *>((splitAnim))->ActivateControllerSequence((::NiControllerSequence *)(splitSeq[0]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::Menu737e50 *>(this)->UpdateCulledNodes();
            }
            if (!sounded && DAT_011d90e0 < reinterpret_cast<::FUN_00508100_shell *>((playerSeq[0]))->FUN_00508100())
            {
                Update90 tableUpdate(DAT_011d90e0, true, false);
                Update90 playerUpdate(DAT_011d90e0, true, false);
                Update90 splitUpdate(DAT_011d90e0, true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(0)))))->FUN_00a59c60((int)&(tableUpdate));
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(1)))))->FUN_00a59c60((int)&(playerUpdate));
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(2)))))->FUN_00a59c60((int)&(splitUpdate));
            }
            else if (sounded && DAT_011d90e0 - soundTime < reinterpret_cast<::FUN_00508100_shell *>((dealerSeq[0]))->FUN_00508100())
            {
                Update90 tableUpdate2(DAT_011d90e0 - soundTime, true, false);
                Update90 dealerUpdate(DAT_011d90e0 - soundTime, true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(0)))))->FUN_00a59c60((int)&(tableUpdate2));
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(3)))))->FUN_00a59c60((int)&(dealerUpdate));
            }
            if (DAT_011d90e0 >= reinterpret_cast<::FUN_00508100_shell *>((playerSeq[0]))->FUN_00508100() && !sounded)
            {
                reinterpret_cast<::NiControllerManager *>((tableAnim))->StopSequence((::NiControllerSequence *)(tableStart), 0.0f);
                reinterpret_cast<::NiControllerManager *>((tableAnim))->ActivateControllerSequence((::NiControllerSequence *)(tableEnd), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::NiControllerManager *>((dealerAnim))->ActivateControllerSequence((::NiControllerSequence *)(dealerSeq[0]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01070d20, 0x121)))->FUN_00ad8830(false);
                sounded = true;
                soundTime = DAT_011d90e0;
                Update90 tableUpdate2(0.0f, true, false);
                Update90 dealerUpdate(0.0f, true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(0)))))->FUN_00a59c60((int)&(tableUpdate2));
                reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(3)))))->FUN_00a59c60((int)&(dealerUpdate));
            }
            else if (DAT_011d90e0 - soundTime >= reinterpret_cast<::FUN_00508100_shell *>((dealerSeq[0]))->FUN_00508100() && sounded)
            {
                reinterpret_cast<::NiControllerManager *>((tableAnim))->StopSequence((::NiControllerSequence *)(tableEnd), 0.0f);
                reinterpret_cast<::NiControllerManager *>((dealerAnim))->StopSequence((::NiControllerSequence *)(dealerSeq[0]), 0.0f);
                reinterpret_cast<::NiControllerManager *>((tableAnim))->DeactivateAllSequences(0.0f);
                reinterpret_cast<::NiControllerManager *>((dealerAnim))->DeactivateAllSequences(0.0f);
                reinterpret_cast<::NiControllerManager *>((playerAnim))->DeactivateAllSequences(0.0f);
                reinterpret_cast<::NiControllerManager *>((splitAnim))->DeactivateAllSequences(0.0f);
                reinterpret_cast<::FUN_00738270_shell *>(this)->UncullCardObjects();
                reinterpret_cast<::FUN_007316f0_shell *>(this)->ClearField();
                reinterpret_cast<::S00739970 *>(this)->FUN_00739970(false);
                sounded = false;
                UpdateBetTiles(true);
                int limit = ((::Stats129 *)(reinterpret_cast<::FUN_00504e60_shell *>((((CasinoUpdate*)DAT_011d9058)))->FUN_00504e60()))->limit;
                int winnings = DAT_011d9054->amount;
                int curTier = DAT_011d9054->flags;
                for (int i = 1; i < 5; i++)
                {
                    if (i <= curTier)
                        reward = false;
                    else if (limit * (i * 0.25) <= winnings)
                    {
                        DAT_011d9054->flags = (short)i;
                        reward = true;
                    }
                }
                if (!reward)
                    state = 10;
                else
                    FUN_00731d30();
                for (int j = 0; j < 3; j++)
                    counts[j] = 1;
            }
        }
        else
            state = 10;
        break;
    case 8: {
        if (DAT_011d90e0 > 1.0)
            reinterpret_cast<::Tile *>((message))->Set(0xfa3, 0);
        if (!revealSeq)
        {
            state = 11;
            break;
        }
        Update90 su(DAT_011d90e0, true, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(0)))))->FUN_00a59c60((int)&(su));
        if (DAT_011d90e0 == 0.0)
        {
            reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x400, true);
            reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x800, true);
            reinterpret_cast<::FUN_00739ad0_Holder *>(this)->HideArrowNodes();
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01070d5c, 0x121)))->FUN_00ad8830(false);
            reinterpret_cast<::NiControllerManager *>((dealerAnim))->ActivateControllerSequence((::NiControllerSequence *)(revealSeq), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
        }
        if (DAT_011d90e0 < reinterpret_cast<::FUN_00508100_shell *>((revealSeq))->FUN_00508100())
        {
            Update90 du(DAT_011d90e0, true, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(3)))))->FUN_00a59c60((int)&(du));
        }
        if (DAT_011d90e0 >= reinterpret_cast<::FUN_00508100_shell *>((revealSeq))->FUN_00508100())
        {
            reinterpret_cast<::NiControllerManager *>((dealerAnim))->StopSequence((::NiControllerSequence *)(revealSeq), 0.0f);
            state = 11;
        }
        break;
    }
    case 9: {
        if (DAT_011d90e0 > 1.0)
            reinterpret_cast<::Tile *>((message))->Set(0xfa3, 0);
        if (!dealerSeq[counts[2]])
        {
            if (reinterpret_cast<::OwnQ *>(this)->FUN_00738ff0((::Node129 *)(dealer)) > 21 || ((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x2000))))
                state = 12;
            else
                state = 11;
            break;
        }
        Update90 su(DAT_011d90e0, true, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(0)))))->FUN_00a59c60((int)&(su));
        if (DAT_011d90e0 == 0.0)
        {
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01070d5c, 0x121)))->FUN_00ad8830(false);
            reinterpret_cast<::FUN_00739ad0_Holder *>(this)->HideArrowNodes();
            FUN_0096a2d0* curr = dealer;
            BJCard* last = 0;
            int drawn = 0;
            while (curr && *((::BJCard **)(new ((void *)(curr)) ::Vec3())))
            {
                last = *((::BJCard **)(new ((void *)(curr)) ::Vec3()));
                curr = ((::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((curr))->FUN_00726070()));
                drawn++;
            }
            if (last)
                reinterpret_cast<::BlackjackMenuShell *>(this)->FUN_007396e0(2, drawn, (::CardInfo *)(last));
            reinterpret_cast<::NiControllerManager *>((dealerAnim))->ActivateControllerSequence((::NiControllerSequence *)(dealerSeq[counts[2]]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
        }
        if (DAT_011d90e0 < reinterpret_cast<::FUN_00508100_shell *>((dealerSeq[counts[2]]))->FUN_00508100())
        {
            Update90 du(DAT_011d90e0, true, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::SceneUpdate *)(reinterpret_cast<::NiNode *>((((::SceneUpdate *)(::FUN_00559450((int *)(((ScenePointerUpdate*)&(*reinterpret_cast<::GO *>(&::g_011d9098)))))))))->GetAt(3)))))->FUN_00a59c60((int)&(du));
        }
        if (DAT_011d90e0 >= reinterpret_cast<::FUN_00508100_shell *>((dealerSeq[counts[2]]))->FUN_00508100())
        {
            reinterpret_cast<::NiControllerManager *>((dealerAnim))->StopSequence((::NiControllerSequence *)(dealerSeq[counts[2]]), 0.0f);
            counts[2]++;
            if (reinterpret_cast<::OwnQ *>(this)->FUN_00738ff0((::Node129 *)(dealer)) > 21 || ((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x2000))))
                state = 12;
            else
                state = 11;
        }
        break;
    }
    case 4:
        if (playerResult)
        {
            if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(8))))
            {
                if (splitResult)
                    state = 8;
            }
            else
                state = 8;
        }
        if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x400))))
        {
            if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(8))))
            {
                if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x800))))
                    state = 8;
            }
            else
                state = 8;
        }
        break;
    case 11: {
        reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x1000, true);
        if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(8))))
        {
            if (playerResult == 4 && splitResult == 4)
            {
                reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x2000, true);
                state = 12;
                break;
            }
        }
        else if (playerResult == 4 || playerResult == 6)
        {
            reinterpret_cast<::FUN_00734d50_holder *>(this)->SetFlag(0x2000, true);
            state = 12;
            break;
        }
        if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x20))))
        {
            state = 12;
            break;
        }
        int dealerTotal = reinterpret_cast<::OwnQ *>(this)->FUN_00738ff0((::Node129 *)(dealer));
        int chosen = 0;
        int count = 0;
        FUN_0096a2d0* node = dealer;
        bool soft = false;
        while (node && *((::BJCard **)(new ((void *)(node)) ::Vec3())))
        {
            count++;
            if ((*((::BJCard **)(new ((void *)(node)) ::Vec3())))->rank == 12)
                soft = true;
            node = ((::FUN_0096a2d0 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        if ((dealerTotal < 17 || (dealerTotal == 17 && soft && !standSoft17)) && count < 7)
        {
            chosen = reinterpret_cast<::BJDeck *>(this)->DrawCard(dealer, true, true);
            reinterpret_cast<::Callees *>((dealer))->FUN_00905820((void *)&(const ::BJCard *const &)(&cards[chosen]));
            state = 9;
        }
        else
            state = 12;
        break;
    }
    case 12: {
        ::TopicMenuController::IncrementMiscStat(41);
        int playerValue = reinterpret_cast<::OwnQ *>(this)->FUN_00738ff0((::Node129 *)(player));
        int dealerValue = reinterpret_cast<::OwnQ *>(this)->FUN_00738ff0((::Node129 *)(dealer));
        int payout = 0;
        char buf[260];
        if (!playerResult)
        {
            if ((playerValue > dealerValue && playerValue < 22) || (playerValue < 22 && dealerValue > 21))
                playerResult = 3;
            else if ((playerValue < dealerValue && dealerValue < 22) || playerValue > 21)
                playerResult = 1;
            else
                playerResult = 2;
        }
        if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(8))))
        {
            playerValue = reinterpret_cast<::OwnQ *>(this)->FUN_00738ff0((::Node129 *)(split));
            if (!splitResult)
            {
                if ((playerValue > dealerValue && playerValue < 22) || (playerValue < 22 && dealerValue > 21))
                    splitResult = 3;
                else if ((playerValue < dealerValue && dealerValue < 22) || playerValue > 21)
                    splitResult = 1;
                else
                    splitResult = 2;
            }
        }
        switch (playerResult)
        {
        case 1:
        case 4:
            payout += -bet;
            break;
        case 3:
            payout += bet;
            break;
        case 5:
            payout += (int)(bet * payoutMultiplier + DAT_01070d18);
            break;
        case 6:
            payout += -(int)(bet / 2.0 + DAT_01070d18);
            break;
        }
        switch (splitResult)
        {
        case 1:
        case 4:
            payout += -splitBet;
            break;
        case 3:
            payout += splitBet;
            break;
        case 5:
            payout += (int)(splitBet * payoutMultiplier + 0.5);
            break;
        }
        balance += payout;
        reinterpret_cast<::FUN_00a01290_shell *>((((BlackjackUpdate*)DAT_011d9050)->tile38))->SetTraitAndReset((int)DAT_011d9048, 1.0f);
        reinterpret_cast<::Tile *>((((BlackjackUpdate*)DAT_011d9050)->tile38))->Set((int)DAT_011d9048, balance);
        DAT_011d9054->amount += payout;
        reinterpret_cast<::fnv_0073ab40::FUN_0073ab40_shell *>(this)->UpdateTileText();
        if (payout > 0)
        {
            if (luckyWin)
                ::FUN_00406d00(buf, 260, DAT_01070d0c, (*reinterpret_cast<::Settings129 *>(&::g_011d3a98)).FUN_00403df0(), payout, (*reinterpret_cast<::Settings129 *>(&::g_011d5050)).FUN_00403df0(),
                             (*reinterpret_cast<::Settings129 *>(&::g_011d3114)).FUN_00403df0());
            else
                ::FUN_00406d00(buf, 260, DAT_01070d0c, (*reinterpret_cast<::Settings129 *>(&::g_011d2ff4)).FUN_00403df0(), payout, (*reinterpret_cast<::Settings129 *>(&::g_011d5050)).FUN_00403df0(),
                             (*reinterpret_cast<::Settings129 *>(&::g_011d3114)).FUN_00403df0());
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01070cf8, 0x121)))->FUN_00ad8830(false);
            reinterpret_cast<::FUN_00a01290_shell *>((((BlackjackUpdate*)DAT_011d9050)->message))->SetTraitAndReset(0xfc4, 1.0f);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((BlackjackUpdate*)DAT_011d9050)->message))->FUN_00a01350(0xfc4, (char *)(buf), true);
            reinterpret_cast<::Tile *>((((BlackjackUpdate*)DAT_011d9050)->message))->Set(0xfa3, 1);
        }
        else if (payout < 0)
        {
            if (luckyLose)
                ::FUN_00406d00(buf, 260, DAT_01070d0c, (*reinterpret_cast<::Settings129 *>(&::g_011d25e0)).FUN_00403df0(), -payout, (*reinterpret_cast<::Settings129 *>(&::g_011d5050)).FUN_00403df0(),
                             (*reinterpret_cast<::Settings129 *>(&::g_011d3114)).FUN_00403df0());
            else
                ::FUN_00406d00(buf, 260, DAT_01070d0c, (*reinterpret_cast<::Settings129 *>(&::g_011d3474)).FUN_00403df0(), -payout, (*reinterpret_cast<::Settings129 *>(&::g_011d5050)).FUN_00403df0(),
                             (*reinterpret_cast<::Settings129 *>(&::g_011d3114)).FUN_00403df0());
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01070ce4, 0x121)))->FUN_00ad8830(false);
            reinterpret_cast<::FUN_00a01290_shell *>((((BlackjackUpdate*)DAT_011d9050)->message))->SetTraitAndReset(0xfc4, 1.0f);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((BlackjackUpdate*)DAT_011d9050)->message))->FUN_00a01350(0xfc4, (char *)(buf), true);
            reinterpret_cast<::Tile *>((((BlackjackUpdate*)DAT_011d9050)->message))->Set(0xfa3, 1);
        }
        else
        {
            ::FUN_00406d00(buf, 260, DAT_01019f08, (*reinterpret_cast<::Settings129 *>(&::g_011d3f88)).FUN_00403df0());
            reinterpret_cast<::FUN_00a01290_shell *>((((BlackjackUpdate*)DAT_011d9050)->message))->SetTraitAndReset(0xfc4, 1.0f);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((BlackjackUpdate*)DAT_011d9050)->message))->FUN_00a01350(0xfc4, (char *)(buf), true);
            reinterpret_cast<::Tile *>((((BlackjackUpdate*)DAT_011d9050)->message))->Set(0xfa3, 1);
        }
        reinterpret_cast<::FileMatchList *>((player))->RemoveAll();
        reinterpret_cast<::FileMatchList *>((dealer))->RemoveAll();
        if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(8))))
        {
            reinterpret_cast<::FileMatchList *>((split))->RemoveAll();
            reinterpret_cast<::FUN_00a01290_shell *>((((BlackjackUpdate*)DAT_011d9050)->tile34))->SetTraitAndReset((int)DAT_011d9048, 1.0f);
            reinterpret_cast<::Tile *>((((BlackjackUpdate*)DAT_011d9050)->tile34))->Set((int)DAT_011d9048, bet);
            splitBet = 0;
        }
        if (((bool)(reinterpret_cast<::FUN_00734d30_shell *>(this)->HasFlag(0x80))))
        {
            bet /= 2;
            reinterpret_cast<::FUN_00a01290_shell *>((((BlackjackUpdate*)DAT_011d9050)->tile34))->SetTraitAndReset((int)DAT_011d9048, 1.0f);
            reinterpret_cast<::Tile *>((((BlackjackUpdate*)DAT_011d9050)->tile34))->Set((int)DAT_011d9048, bet);
        }
        if (balance < bet)
        {
            bet = balance;
            reinterpret_cast<::FUN_00a01290_shell *>((((BlackjackUpdate*)DAT_011d9050)->tile34))->SetTraitAndReset((int)DAT_011d9048, 1.0f);
            reinterpret_cast<::Tile *>((((BlackjackUpdate*)DAT_011d9050)->tile34))->Set((int)DAT_011d9048, bet);
        }
        state = 7;
        break;
    }
    case 10:
        if (remaining < decks * 52 * shuffleThreshold)
            reinterpret_cast<::FUN_007399d0_shell *>(this)->FUN_007399d0();
        if (DAT_011d90e0 > 1.0)
            reinterpret_cast<::Tile *>((message))->Set(0xfa3, 0);
        if (balance < bet)
        {
            bet = balance;
            reinterpret_cast<::FUN_00a01290_shell *>((((BlackjackUpdate*)DAT_011d9050)->tile34))->SetTraitAndReset((int)DAT_011d9048, 1.0f);
            reinterpret_cast<::Tile *>((((BlackjackUpdate*)DAT_011d9050)->tile34))->Set((int)DAT_011d9048, bet);
        }
        if (balance < DAT_0119fe40)
        {
            char warning[260];
            ::FUN_00406d00(warning, 260, (*reinterpret_cast<::Settings129 *>(&::g_011d2424)).FUN_00403df0());
            ::DispatchMessageToSink((int)(warning), 0, (int)(DAT_01049638), 0, ::DAT_010162c0, 0);
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(((::Audio129 *)(::FUN_00453a70()))->FUN_00ad7550(DAT_01025cc4, 0x121)))->FUN_00ad8830(false);
            FUN_00731d30();
        }
        break;
    }
}
