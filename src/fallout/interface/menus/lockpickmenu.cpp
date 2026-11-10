
// src/fallout/interface/menus/lockpickmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/lockpickmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fallout/interface/menu_fields.h"
#include "fnv/game_timer.h"
#include "fnv/result_slot.h"
#include <cstdint>
#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/ActorValueOwner.h"
#include "fnv/decl/ActorX.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C1540Menu.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CamLook.h"
#include "fnv/decl/CombatState.h"
#include "fnv/decl/Controller.h"
#include "fnv/decl/Dummy_00a239e0.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0047d7c0_Class.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a0fd0_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_00507700_cls.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_00532e40_s.h"
#include "fnv/decl/FUN_00532ec0.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/FUN_00733fd0_shell.h"
#include "fnv/decl/FUN_007408d0_Class.h"
#include "fnv/decl/FUN_00759450_shell.h"
#include "fnv/decl/FUN_0078e090_class.h"
#include "fnv/decl/FUN_0078e0f0.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_00915d20_shell.h"
#include "fnv/decl/FUN_00a01290_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00a23390_t.h"
#include "fnv/decl/FUN_00a25810_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00c4f270_Class.h"
#include "fnv/decl/FUN_00c4f2d0_class.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/KarmaActor.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/LockExtraData.h"
#include "fnv/decl/Menu.h"
#include "fnv/decl/MersenneTwister.h"
#include "fnv/decl/MiddleLowProcess.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/P3.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/S0042fa20.h"
#include "fnv/decl/S148c0.h"
#include "fnv/decl/S8840.h"
#include "fnv/decl/SSN_b5.h"
#include "fnv/decl/S_00a04150_Class.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TileFloatList.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TopicMenuController.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_Cam_00712e60.h"
#include "fnv/decl/fnv_00447080__FUN_00447080_shell.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_005691b0__P01RefA.h"
#include "fnv/decl/fnv_005692a0__FUN_005692a0_shell.h"
#include "fnv/decl/fnv_005789b0__FUN_005789b0_shell.h"
#include "fnv/decl/fnv_00718930__LLD_PlayerCharacter.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_007fd640__FUN_007fd640Class.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00970b30__Cls.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/decl/fnv_00a328b0__SeqExt.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_0047e000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005d4000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00648000.h"
#include "fnv/symbols_00670000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_0075b000.h"
#include "fnv/symbols_0078e000.h"
#include "fnv/symbols_00790000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00b6b000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_01034000.h"
#include "fnv/symbols_01066000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_01071000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01203000.h"
struct LockPickMenu
{
    int FUN_0078da90();
};

// @fnv 0x0078da90
int LockPickMenu::FUN_0078da90()
{
    return 0x3f6;
}

namespace fnv_0078daa0 {
class Tile
{
  public:
    void* m_pRenderedNodeEntry;
};

struct LockPickMenu
{
    Tile* m_pTiles[64];
    void SetTile(int id, Tile* tile);
};

// Stores tile into the menu's tile array at index id when id is in [0,16).
// @fnv 0x0078daa0
void LockPickMenu::SetTile(int id, Tile* tile)
{
    if (id >= 0 && id < 16)
    {
        (&this->m_pTiles[11])[id] = tile;
    }
}
}  // namespace fnv_0078daa0

// @fnv 0x0078e080
int FUN_0078e080()
{
    return 1014;
}

struct LockPickMenuProxy
{
    void* FUN_0078dad0(unsigned int);
};
// Calls FUN_0078e0f0 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0078dad0
void* LockPickMenuProxy::FUN_0078dad0(unsigned int flags)
{
    reinterpret_cast<struct ::FUN_0078e0f0 *>((this))->FUN_0078e0f0::~FUN_0078e0f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Proc_S
{
};
class Tile
{
public:
    void Set(int, int);
public:
    static float GetInterfaceScale();
};
struct FUN_007902b0_shell
{
    void FUN_007902b0(int, Tile*);
};
// If aiID is 13, gets the next entry from FUN_004b7210 and calls Set(0xfa9, 0.0f, true) on it as a Tile.
// @fnv 0x007902b0
void FUN_007902b0_shell::FUN_007902b0(int aiID, Tile* apTarget)
{
    if (aiID == 13)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<Tile*>(((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((reinterpret_cast<Proc_S*>(((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0045cd60())))))->FUN_00a012d0(0xfa9, 0.0f, true);
    }
}

namespace fnv_007902f0 {
class Tile
{
};
struct Proc_S
{
};
struct Target
{
    void FUN_007902f0(int aiID, Tile* apTarget);
};
// If aiID equals 0xD, gets the next object from FUN_004b7210 and calls Set(0xFA9, 255.0f, true) on it as a Tile.
// @fnv 0x007902f0
void Target::FUN_007902f0(int aiID, Tile* apTarget)
{
    if (aiID == 0xD)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((((Tile*)((void *)(reinterpret_cast<::FUN_0045cd60_shell *>((((Proc_S*)((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0045cd60())))))->FUN_00a012d0(0xFA9, 255.0f, true);
    }
}
}  // namespace fnv_007902f0

struct NiPoint3
{
    float x, y, z;
    NiPoint3(float, float, float);
};
struct ThreeByThreeMatrix
{
    float values[3][3];
    ThreeByThreeMatrix();
    NiPoint3 FUN_004b4500(const NiPoint3&);
public:
    void SetYRotation(float);
public:
    ::ThreeByThreeMatrix operator+(const ::ThreeByThreeMatrix &) const;
};
struct NiUpdateData
{
    float time;
    bool updateControllers, multithreaded, updateTransforms, updateBounds, updateProperties;
    NiUpdateData(float, bool, bool);
};
struct Object
{
};
struct ObjectRef
{
};
struct Manager
{
};
struct ValueTile
{
};
struct LockPickState
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
    ValueTile* tile;
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
    ThreeByThreeMatrix rotation;
    NiPoint3 position;
    void UpdateLockRotation(float amount);
};
namespace fnv_00790f40 {
struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    int m_iUnk08;
    NiUpdateData(float afTime, bool abUpdateControllers, bool abIsMultiThreaded);
};

class NiAVObject
{
};

class NiNode
{
  public:
    NiAVObject* GetAt(unsigned int auiIndex);
};

struct NiNodePointer
{
    NiNode* m_pObject;
};


struct Sequence
{
};

struct FUN_00790f40_cls
{
    int unk00[35];
    float m_fSequenceTime;
    int unk90[4];
    Sequence* m_pSequence;
    void AdvanceSequence(float afDelta);
};

// @fnv 0x00790f40
void FUN_00790f40_cls::AdvanceSequence(float afDelta)
{
    float fSequenceTimeRatio = (float)((m_fSequenceTime + afDelta) / 90.0);
    NiUpdateData kData(0.0f, true, false);
    if (m_pSequence)
    {
        reinterpret_cast<::fnv_00a328b0::SeqExt *>((m_pSequence))->FUN_00a328b0((float)(reinterpret_cast<::FUN_00759450_shell *>((m_pSequence))->FUN_00759450() +
                                     (reinterpret_cast<::FUN_00508100_shell *>((m_pSequence))->FUN_00508100() - reinterpret_cast<::FUN_00759450_shell *>((m_pSequence))->FUN_00759450()) * fSequenceTimeRatio), {});
        reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_00790f40::NiNode *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_00790f40::NiNodePointer *>(&::g_011da24c))))))->GetAt(0)))->FUN_00a59c60((std::intptr_t)&(kData));
    }
}
}  // namespace fnv_00790f40


struct SingletonGetter
{
};

struct ProcBase
{
};

struct ObjB
{
    char pad[0xb4];
    void* unkB4;
};

struct ObjC
{
};

struct ObjD
{
};

struct Guard : SingletonGetter
{
    int unk00;

    Guard(void* p);
    ~Guard();
    void FUN_0066b0d0(int);
};


// @fnv 0x0078e7c0
void __cdecl FUN_0078e7c0()
{
    void* v6;
    void* v14;
    void* v18;
    void* v1c3;
    void* v24;

    if (((void *)(::FUN_00559450((int *)(reinterpret_cast<SingletonGetter*>(&(*reinterpret_cast<::Manager *>(&::g_011da24c))))))) == 0)
    {
        return;
    }
    reinterpret_cast<::S148c0 *>((reinterpret_cast<ProcBase*>(((void *)(::FUN_0043c4b0())))))->FUN_007148c0({}, {});
    v6 = ((void *)(::FUN_0045c670()));
    v1c3 = ((void *)((reinterpret_cast<ObjB*>(v6))->unkB4));
    reinterpret_cast<::FUN_00c4f270_Class *>((reinterpret_cast<ObjC*>(v1c3)))->FUN_00c4f270(1);
    v18 = ((void *)(::FUN_00559450((int *)(reinterpret_cast<SingletonGetter*>(&(*reinterpret_cast<char *>(&::g_011da224)))))));
    ::UpdateCameraFrustum((::NiCamera *)(v18), ::g_011db5ec_arg1);
    Guard g(((void *)(reinterpret_cast<::fnv_007fd640::FUN_007fd640Class *>((reinterpret_cast<ObjD*>(((void *)(::fnv_004b7210::FUN_004b7210())))))->FUN_007fd640())));
    reinterpret_cast<::FUN_004a0fd0_shell *>((reinterpret_cast<ObjC*>(v1c3)))->FUN_004a0fd0((::NiNode *)(void *)(((void *)(::FUN_00559450((int *)&(g))))));
    if (v18 != 0)
    {
        v24 = v18;
    }
    else
    {
        v24 = ((void *)(reinterpret_cast<::BSFaceGenNiNode *>((reinterpret_cast<ObjB*>(v6)))->GetAnimationData()));
    }
    v14 = v24;
    ::FUN_00b6bee0(v14, (void *)(((std::intptr_t)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)))), (::BSShaderAccumulator *)(v1c3));
    ::BSShaderRenderUtility::SetRenderCamera((::NiCamera *)(v14), (::BSShaderAccumulator *)(void *)(((void *)(::FUN_00559450((int *)&(g))))), 0);
    reinterpret_cast<::FUN_004a0fd0_shell *>((reinterpret_cast<ObjC*>(v1c3)))->FUN_004a0fd0((::NiNode *)(void *)(0));
    g.FUN_0066b0d0(0);
    reinterpret_cast<::FUN_00c4f2d0_class *>((reinterpret_cast<ObjC*>(v1c3)))->FUN_00c4f2d0();
}

namespace fnv_0078e900 {
// Stand-in types are named after the game function whose constructor they wrap.
struct FUN_00416870
{  // 3-float vector
    float unk00;
    float unk04;
    float unk08;
    FUN_00416870(float, float, float);
};
struct FUN_00414430
{  // 4-float rectangle (viewport)
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    FUN_00414430(float, float, float, float);
};
struct FUN_00a71b70
{  // frustum: four edges, near, far, orthographic flag
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    bool unk18;
    FUN_00a71b70(int);
};
struct FUN_0043d410
{  // small 12-byte value object
    float unk00;
    int unk04;
    int unk08;
    FUN_0043d410(float, int, int);
};
struct Setting
{
};
struct Renderer
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
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
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual float vf64();  // vtable slot 0x100: returns the far-plane distance
};
struct FUN_00aa13e0
{  // allocator base: supplies the class operator new
};
struct FUN_00a712f0 : FUN_00aa13e0
{  // camera object, size 0x114
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
    FUN_00a712f0();
};
struct FUN_0078e900_shell
{
    FUN_00a712f0* FUN_0078e900();
};


// Builds a camera: viewport, frustum from a field-of-view setting and the
// screen aspect ratio, far/near ratio, and a default orientation.
// Local names are chosen only to reproduce the original stack layout:
//   b = camera, f = viewport rect, c = frustum, g = aspect ratio,
//   d = frustum scale, e = view angle, a = trailing value object.
// @fnv 0x0078e900
FUN_00a712f0* FUN_0078e900_shell::FUN_0078e900()
{
    float g;
    FUN_00a712f0* b = new FUN_00a712f0;
    FUN_00414430 f(0.0f, 1.0f, 1.0f, 0.0f);
    float d;
    reinterpret_cast<::_Cam_00712e60 *>((b))->FUN_00712e60((*(const ::_Rect16_00712e60 *)(&f)));
    FUN_00a71b70 c(0);
    float e;
    c.unk14 = ((::fnv_0078e900::Renderer *)(::FUN_0045c670()))->vf64();
    c.unk10 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0078e900::Setting *>(&::g_01203144))))));
    reinterpret_cast<::FUN_00507700_cls *>((b))->FUN_00507700(c.unk14 / c.unk10);
    g = (double)(::DAT_011f9426 ? ::DAT_011f9434 : ::FUN_004dc200()) / ((int)(::FUN_004dc1f0()));
    d = ::DAT_01016264;
    e = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0078e900::Setting *>(&::g_01203150)))))) * ::DAT_01023128 * (*reinterpret_cast<double *>(&::DAT_01070c80));
    c.unk00 = -::FUN_0057dd70(e) * d;
    c.unk04 = ::FUN_0057dd70(e) * d;
    c.unk0c = -::FUN_0057dd70(e) * g * d;
    c.unk08 = ::FUN_0057dd70(e) * g * d;
    c.unk18 = false;
    reinterpret_cast<::NiCamera *>((b))->UpdateViewFrustum((*(const ::NiFrustum *)(&c)));
    reinterpret_cast<::CamLook *>((b))->SetLookAt((const ::CamPoint &)((const ::fnv_0078e900::FUN_00416870 &)(FUN_00416870(0.0f, 0.0f, 1.0f))), (const ::CamPoint &)((const ::fnv_0078e900::FUN_00416870 &)(FUN_00416870(0.0f, 0.0f, 1.0f))));
    reinterpret_cast<::FUN_00733fd0_shell *>((b))->FUN_00733fd0(1.0f);
    FUN_0043d410 a(0.0f, 0, 0);
    reinterpret_cast<::FUN_00a59c60_cls *>((b))->FUN_00a59c60((std::intptr_t)(&a));
    return b;
}
}  // namespace fnv_0078e900


// @fnv 0x00790290
int __cdecl FUN_00790290()
{
    return ((((unsigned char)(::FUN_00709d40())) != 0 ? -1 : 0) & 8) + 0x14;
}

template <> class BSStringT<char>
{
  public:
    char* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
    BSStringT();
    ~BSStringT();
};

struct LockTile
{
};

struct LockAnimNode
{
};
extern LockAnimNode* g_apLockNodes0_011a0328[5];
extern LockAnimNode* g_apLockNodes1_011a033c[5];
extern LockAnimNode* g_apLockNodes2_011a0350[5];
extern LockAnimNode* g_apLockNodes3_011a0364[5];

struct PathingActorState
{
    int unk00, unk04, unk08;
    int iBreakCount;
};
struct LockRef
{
};

struct ActorValueOwnerStandIn
{
};
struct PlayerStandIn
{
    char pad00[0xa4];
    ActorValueOwnerStandIn kAVOwner;
};

struct RNG
{
};
struct StringSetting
{
};
float __cdecl FUN_00404010(float afA, float afB);

extern int g_iPickAngle_011da208;
extern int g_iDriverAngle_011da20c;

static const char s_szLockBroken[] = "LOCK BROKEN!  :(";
static const char s_szForceFailIcon[] = "Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds";
static const char s_szForceFailSound[] = "UILockpickingForceFail";
static const char s_szIntFormat[] = "%d";
extern const char g_szLockPickEnd[] = "";

struct LockPickMenuImpl
{
    char pad00[0x28];
    int unk28;
    char pad2c[0x3c - 0x2c];
    LockTile* unk3c;
    char pad40[0x48 - 0x40];
    LockTile* unk48;
    char pad4c[0x58 - 0x4c];
    LockTile* unk58;
    char pad5c[0x64 - 0x5c];
    LockTile* unk64;
    char pad68[4];
    LockRef* unk6c;
    int unk70;
    int unk74;
    char pad78[0x88 - 0x78];
    int unk88;
    char pad8c[4];
    float unk90;
    char pad94[4];
    unsigned char unk98;

    void HandleLockPickAction(int aiCode, int aiUnused);
};

// @fnv 0x00790330
void LockPickMenuImpl::HandleLockPickAction(int aiCode, int aiUnused)
{
    int iStep = 5;
    switch (aiCode)
    {
    case 10:
        FUN_0078e0d0();
        break;
    case 9: {
        float fPerk = 0.0f;
        ::ApplyPerkModifiers(0x20, (::Actor *)((*reinterpret_cast<::PlayerStandIn * *>(&::_g_thePlayer))), &fPerk);
        if (::MersenneTwister::GetRandomGenerator()->GetRandomUInt(100) <
            (unsigned int)::fnv_00648d30::FUN_00648d30(reinterpret_cast<::ActorValueOwner *>(&((*reinterpret_cast<::PlayerStandIn * *>(&::_g_thePlayer))->kAVOwner))->GetActorValueAsInteger((::ActorValue::Index)(0x24)), ::DAT_011da28c[unk70]))
        {
            unk98 = 1;
            unk90 = 90.0f;
            unk28 = 3;
        }
        else if (!unk6c && fPerk == 0.0)
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((unk58))->FUN_00a01350(0xfc4, (char *)(s_szLockBroken), true);
            reinterpret_cast<::Tile *>((unk58))->Set(0xfa3, 1);
            unk28 = 6;
        }
        else
        {
            ((::PathingActorState *)(reinterpret_cast<::FUN_00569160_shell *>((unk6c))->FUN_00569160()))->iBreakCount++;
            reinterpret_cast<::fnv_005789b0::FUN_005789b0_shell *>((unk6c))->FUN_005789b0();
            ::DispatchMessageToSink((const char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011d3e98))))->GetMenuTitle()))), 0, (const char *)(s_szForceFailIcon), (const char *)(s_szForceFailSound), 2.0f, 0);
            FUN_0078e0d0();
        }
        break;
    }
    case 3:
    case 5: {
        int m_eRange = ::DAT_011da28c[unk70 + 1] - ::DAT_011da28c[unk70];
        float fT =
            FUN_00404010(FUN_0040ebd0((float)(unk74 - ::DAT_011da28c[unk70]) / (m_eRange * 2.0f), 1.0f), 0.0f);
        int iDelta = (aiCode != 5 ? 1 : -1) * iStep;
        BSStringT<char> kStr;
        g_iPickAngle_011da208 += iDelta;
        unk88 += iDelta / 2;
        ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT<char> *)(&kStr), s_szIntFormat, g_iPickAngle_011da208);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((unk3c))->FUN_00a01350(0xfc4, (char *)(((const char *)(::FUN_00559450((int *)&(kStr))))), true);
        reinterpret_cast<::S0042fa20 *>((g_apLockNodes0_011a0328[unk70]))->FUN_0045ce80(*((int *)&(::FUN_0043d4d0((int *)(g_apLockNodes0_011a0328[unk70])))) +
                                                     (int)(iDelta * (1.0f - fT)));
        reinterpret_cast<::S0042fa20 *>((g_apLockNodes1_011a033c[unk70]))->FUN_0045ce80(*((int *)&(::FUN_0043d4d0((int *)(g_apLockNodes1_011a033c[unk70])))) +
                                                     (int)(iDelta * fT));
        for (int i = 0; i < 6; i++)
        {
            LockTile* pTile = ((::LockTile *)(reinterpret_cast<::TileFloatList *>((unk64))->FUN_00a03eb0(i + 0x11)));
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb1, reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfb1) + iDelta, {});
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfa1, reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfa1) - iDelta / 2, {});
        }
        break;
    }
    case 6:
    case 8: {
        int iRange7 = ::DAT_011da28c[unk70 + 1] - ::DAT_011da28c[unk70];
        float fT2_2 =
            FUN_00404010(FUN_0040ebd0((float)(unk74 - ::DAT_011da28c[unk70]) / (iRange7 * 2.0f), 1.0f), 0.0f);
        int iDeltaX = (aiCode != 8 ? 1 : -1) * iStep;
        BSStringT<char> kStrTmp;
        g_iDriverAngle_011da20c += iDeltaX;
        unk88 += iDeltaX;
        ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT<char> *)(&kStrTmp), s_szIntFormat, g_iDriverAngle_011da20c);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((unk48))->FUN_00a01350(0xfc4, (char *)(((const char *)(::FUN_00559450((int *)&(kStrTmp))))), true);
        reinterpret_cast<::S0042fa20 *>((g_apLockNodes2_011a0350[unk70]))->FUN_0045ce80(*((int *)&(::FUN_0043d4d0((int *)(g_apLockNodes2_011a0350[unk70])))) +
                                                     (int)(iDeltaX * (1.0f - fT2_2)));
        reinterpret_cast<::S0042fa20 *>((g_apLockNodes3_011a0364[unk70]))->FUN_0045ce80(*((int *)&(::FUN_0043d4d0((int *)(g_apLockNodes3_011a0364[unk70])))) +
                                                     (int)(iDeltaX * fT2_2));
        for (int j = 1; j < 6; j++)
        {
            LockTile* pTile2 = ((::LockTile *)(reinterpret_cast<::TileFloatList *>((unk64))->FUN_00a03eb0(j + 0x11)));
            reinterpret_cast<::FUN_00a012d0_t *>((pTile2))->FUN_00a012d0(0xfb1, reinterpret_cast<::TileListBoxCalls *>((pTile2))->GetFloat(0xfb1) + 2.0 * j * iDeltaX / 5.0, {});
            reinterpret_cast<::FUN_00a012d0_t *>((pTile2))->FUN_00a012d0(0xfa1, reinterpret_cast<::TileListBoxCalls *>((pTile2))->GetFloat(0xfa1) - j * iDeltaX / 5.0, {});
        }
        break;
    }
    }
}

extern float DAT_0102978c;
extern double DAT_01072310;
extern double DAT_010356f8;
extern char DAT_0107462c;
extern float DAT_011da2c0;

class OSGlobals
{
};

struct FooA
{
};
struct DummyA
{
};

float __cdecl FUN_006494b0(float a0, float a1);
float __cdecl FUN_00404010(float a0, float a1);

struct Checker
{
};

struct BSSoundHandleEx
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    ~BSSoundHandleEx();
};
struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char* id, unsigned int a1);
};
struct BSAudioS_
{
};

class Tile;
struct TileList
{
};
struct ArgObj
{
};
struct Obj64 : ArgObj
{
    int m_iWordAt00;
    TileList m_iWordAt04;
};
struct Obj : ArgObj
{
};

struct C
{
    int m_00[25];
    Obj64* m_64;
    Obj* m_68;
    int m_6c[6];
    float m_84;
    int m_88;
    int m_8c;
    float m_90;
    void FUN_007908f0();
};

// Computes a sound value from game state, clamps it, plays a sound on threshold crossings, stores it, and updates m_90 from nearby tiles.
// @fnv 0x007908f0
void C::FUN_007908f0()
{
    float RunSeventhVirtualOperation = 0.0f;
    long cnt4 = 0;
    float denom;
    denom = DAT_0102978c;
    if (FUN_004b71d0())
    {
        cnt4 = reinterpret_cast<::FUN_00a23390_t *>((((FooA*)((void *)(reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720())))))->GetAxisState(0, 7);
        if (FUN_00408820((float)cnt4) <= ::DAT_010718f0)
        {
            cnt4 = 0;
        }
        RunSeventhVirtualOperation = (float)(FUN_006494b0((float)cnt4 / denom, ::DAT_01017718) * DAT_01072310);
    }
    else
    {
        RunSeventhVirtualOperation = (float)((double)reinterpret_cast<::Dummy_00a239e0 *>((((DummyA*)((void *)(reinterpret_cast<::FUN_00877720_shell *>((::g_osGlobals))->FUN_00877720())))))->FUN_00a239e0(1) *
                                             (((double)(::InterfaceManager::UpdateInterfaceState())) / ((double)(::FUN_00706e50()))));
    }
    float kVal = reinterpret_cast<::TileListBoxCalls *>((m_68))->GetFloat((intptr_t)(*reinterpret_cast<void * *>(&::fnv_0078eb50::xg_iTileId2_11da1fc))) + RunSeventhVirtualOperation;
    int remA8 = (int)reinterpret_cast<::TileListBoxCalls *>((m_68))->GetFloat((intptr_t)(*reinterpret_cast<void * *>(&::fnv_0078eb50::xg_iTileId2_11da1fc))) % 100;
    int val3 = (int)kVal % 100;
    kVal = FUN_00404010(kVal, 0.0f);
    kVal = FUN_0040ebd0(kVal, reinterpret_cast<::TileListBoxCalls *>((m_64))->GetFloat(0xfb1));

    if (((RunSeventhVirtualOperation > ::_DAT_01012060 && remA8 > val3) ||
         (RunSeventhVirtualOperation < ::_DAT_01012060 && val3 > remA8)) &&
        ((int)(::MersenneTwister::GetRandomGenerator()->GetRandomUInt({}))) == 0)
    {
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID(&DAT_0107462c, 0x101)))->FUN_00ad8830(false);
    }
    else if (RunSeventhVirtualOperation != ::_DAT_01012060 && DAT_011da2c0 == ::_DAT_01012060)
    {
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::BSSoundHandleEx &)(::FUN_00453a70()->GetSoundHandleByEditorID(&DAT_0107462c, 0x101)))->FUN_00ad8830(false);
    }
    reinterpret_cast<::FUN_00a012d0_t *>((m_68))->FUN_00a012d0((intptr_t)(*reinterpret_cast<void * *>(&::fnv_0078eb50::xg_iTileId2_11da1fc)), kVal, true);
    DAT_011da2c0 = RunSeventhVirtualOperation;
    reinterpret_cast<::LockPickState *>(this)->UpdateLockRotation(kVal);
    float x9 = (float)FUN_00408820(kVal - m_84);
    if (x9 < (float)m_88)
    {
        uintptr_t res4;
        float aV5;
        void* elem9 = ((void *)(::FUN_00559450((int *)&(m_64->m_iWordAt04))));
        aV5 = reinterpret_cast<::TileListBoxCalls *>((m_64))->GetFloat(0xfb1);
        res4 = 0;
        while (elem9 != 0)
        {
            Tile* bestElem6 = ((::Tile *)(reinterpret_cast<::ListStandIn *>(&(m_64->m_iWordAt04))->FUN_0057cbe0((int **)&(elem9))));
            float a3 = (float)(reinterpret_cast<::TileListBoxCalls *>((((ArgObj*)bestElem6)))->GetFloat(0xfb1) / DAT_01011590);
            if (a3 < aV5 && x9 < a3)
            {
                aV5 = a3;
                res4 = (intptr_t)bestElem6;
            }
        }
        if (res4 != 0)
        {
            m_90 = (float)((1.0 - (reinterpret_cast<::TileListBoxCalls *>((((ArgObj*)(void*)res4)))->GetFloat(0xfaa) - DAT_010356f8) / DAT_01034208) *
                           ::DAT_01066808);
            reinterpret_cast<::FUN_00a012d0_t *>((m_68))->FUN_00a012d0(0xfb2, reinterpret_cast<::TileListBoxCalls *>((((ArgObj*)(void*)res4)))->GetFloat(0xfb2), true);
            reinterpret_cast<::FUN_00a012d0_t *>((m_68))->FUN_00a012d0(0xfb3, reinterpret_cast<::TileListBoxCalls *>((((ArgObj*)(void*)res4)))->GetFloat(0xfb3), true);
            reinterpret_cast<::FUN_00a012d0_t *>((m_68))->FUN_00a012d0(0xfb4, reinterpret_cast<::TileListBoxCalls *>((((ArgObj*)(void*)res4)))->GetFloat(0xfb4), true);
        }
    }
    else
    {
        float resultB_2;
        resultB_2 = (float)(((double)m_88 + x9 - reinterpret_cast<::TileListBoxCalls *>((m_64))->GetFloat(0xfb1)) /
                            ((double)m_88 * DAT_01011590 - reinterpret_cast<::TileListBoxCalls *>((m_64))->GetFloat(0xfb1)));
        m_90 = (float)(resultB_2 * ::runtimeInitializationDouble5);
        reinterpret_cast<::FUN_00a012d0_t *>((m_68))->FUN_00a012d0(0xfb2, reinterpret_cast<::TileListBoxCalls *>((m_64))->GetFloat(0xfb2), true);
        reinterpret_cast<::FUN_00a012d0_t *>((m_68))->FUN_00a012d0(0xfb3, reinterpret_cast<::TileListBoxCalls *>((m_64))->GetFloat(0xfb3), true);
        reinterpret_cast<::FUN_00a012d0_t *>((m_68))->FUN_00a012d0(0xfb4, reinterpret_cast<::TileListBoxCalls *>((m_64))->GetFloat(0xfb4), true);
    }
}

// InitLockInterface v1 worker20: faithful transcription from capstone ORIG
struct ModelLoader
{
};
struct SetHelper
{
    int m_00;
    int m_04;
    int m_08;
};
class NiAVObject;
class NiNode
{
public:
    ::NiAVObject *GetAt(unsigned int);
};
// Rotates the lock object by an angle derived from amount and tile->FUN_00a011b0(0xfb1), then applies the rotation and position and updates it.
// @fnv 0x00790df0
void LockPickState::UpdateLockRotation(float amount)
{
    Object* object;
    {
        ThreeByThreeMatrix matrix;
        object = ((::Object *)(reinterpret_cast<::NiNode *>((((::ObjectRef *)(::FUN_00559450((int *)&((*reinterpret_cast<::Manager *>(&::g_011da24c))))))))->GetAt({})));
        NiUpdateData kUpdateData(0.0f, false, false);
        NiPoint3 offset = (*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::P3 *>(&(position))->FUN_004a0bd0({})))))->ProjectileLaunched((::NiPoint3 *)&(const ::NiPoint3 &)(NiPoint3(0.0f, 0.0f, 0.6f)), {})));
        reinterpret_cast<::ThreeByThreeMatrix *>(&(matrix))->SetYRotation((float)((amount / reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(0xfb1) * -180.0 + 90.0) * 0.01745329238474369));
        reinterpret_cast<::FUN_00440460_S *>((object))->FUN_00440460((const ::V3 *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(const ::NiPoint3 &)((*(::NiPoint3 *)(reinterpret_cast<::Point3Offset *>(&(position))->ProjectileLaunched((::NiPoint3 *)&(offset), {})))))->FUN_00439ef0((::NiPoint3 *)&(const ::NiPoint3 &)(matrix.FUN_004b4500(offset)), *(const ::NiPoint3 *)nullptr)))));
        matrix = reinterpret_cast<::ThreeByThreeMatrix *>(&(matrix))->operator+(rotation);
        reinterpret_cast<::FUN_0043fa80_s *>((object))->FUN_0043fa80(matrix);
        reinterpret_cast<::FUN_00a59c60_cls *>((object))->FUN_00a59c60((std::intptr_t)&(kUpdateData));
    }
}
struct SortNode
{
    SortNode* FUN_00a5ecb0(unsigned int a);
};
class NiMemObject
{
  public:
};
class NiSortAdjustNode : public NiMemObject
{
  public:
    NiSortAdjustNode(unsigned int a);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
};
extern "C" void* __cdecl FUN_00aa13e0(unsigned int n);
struct Glob
{
    void FUN_0066b0d0(void* p);
};
struct MatA
{
    int m_00[9];
};
struct MatB
{
    int m_00[9];
};
struct MatrixResult
{
    int values[9];
};
struct Comb
{
    MatrixResult FUN_0043f8d0(void* a);
};
struct UpdData
{
    float time;
    bool updateControllers, multithreaded, updateTransforms, updateBounds, updateProperties;
    void FUN_0043d410(float a, bool b, bool c);
};
struct AVObj
{
};
class NiFixedString
{
  public:
    void* m_00;
    NiFixedString(const char* s);
    ~NiFixedString();
};
struct CtrlNode
{
};
struct ChildObj
{
};
struct TimeObj
{
};
struct SceneNode
{
};
struct VObj
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3c();
    virtual void f40();
    virtual void f44();
    virtual void f48();
    virtual void f4c();
    virtual void f50();
    virtual void f54();
    virtual void f58();
    virtual void f5c();
    virtual void f60();
    virtual void f64();
    virtual void f68();
    virtual void f6c();
    virtual void f70();
    virtual void f74();
    virtual void f78();
    virtual void f7c();
    virtual void f80();
    virtual void f84();
    virtual void f88();
    virtual void f8c();
    virtual void f90();
    virtual void f94();
    virtual void f98();
    virtual void f9c();
    virtual void fa0();
    virtual void fa4();
    virtual void fa8();
    virtual void fac();
    virtual void fb0();
    virtual void fb4();
    virtual void fb8();
    virtual void fbc();
    virtual void fc0();
    virtual void fc4();
    virtual void fc8();
    virtual void fcc();
    virtual void fd0();
    virtual void fd4();
    virtual void fd8();
    virtual void m_dc(void* a, int b);
};
struct Mat9
{
    int d[9];
};
struct ThisCls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    CtrlNode* m_9c;
    ChildObj* m_a0;
    CtrlNode* m_a4;
    ChildObj* m_a8;
    int m_ac;
    ChildObj* m_b0;
    Mat9 m_b4;
    NiPoint3 m_d8;
    void InitLockInterface();
};

// Loads the lock interface and bobby pin NIFs, sets up their scene nodes and controllers, and attaches the resulting node to the scene.
// @fnv 0x0078e1c0
void ThisCls::InitLockInterface()
{
    void* pin;
    pin = ((void *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080((char *)("Meshes\\Terminals\\LockInterface01.NIF"), 0, true, false, false, false)));
    void* idx;
    idx = ((void *)(reinterpret_cast<::fnv_00447080::FUN_00447080_shell *>((::g_modelLoader))->FUN_00447080((char *)("Meshes\\Terminals\\BobbyPin01.NIF"), 0, true, false, false, false)));
    *(Mat9*)&m_b4 = *(Mat9*)&(*reinterpret_cast<unsigned char *>(&::DAT_011a9448));
    {
        SetHelper n;
        m_d8 = *((::NiPoint3 *)(reinterpret_cast<::FUN_00416870_t *>(&(n))->FUN_00416870(0.0f, 0.0f, -1.6f)));
    }
    reinterpret_cast<::FUN_00440460_S *>((((NiNode*)idx)))->FUN_00440460((const ::V3 *)&(m_d8));
    reinterpret_cast<::FUN_0043fa80_s *>((((NiNode*)idx)))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&m_b4)));
    ((Glob*)&(*reinterpret_cast<::Manager *>(&::g_011da24c)))->FUN_0066b0d0(new NiSortAdjustNode(0));
    ((VObj*)((void *)(::FUN_00559450((int *)(((Glob*)&(*reinterpret_cast<::Manager *>(&::g_011da24c))))))))->m_dc(pin, 1);
    ((VObj*)((void *)(::FUN_00559450((int *)(((Glob*)&(*reinterpret_cast<::Manager *>(&::g_011da24c))))))))->m_dc(idx, 1);
    MatA ptr;
    MatB z;
    reinterpret_cast<::FUN_00524ac0_shell *>(&(ptr))->FUN_00524ac0(1.57079637f);
    reinterpret_cast<::FUN_004a0c90_shell *>(&(z))->FUN_004a0c90(1.57079637f);
    reinterpret_cast<::FUN_0043fa80_s *>((((NiNode*)((void *)(::FUN_00559450((int *)(((Glob*)&(*reinterpret_cast<::Manager *>(&::g_011da24c))))))))))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&ResultSlot(((Comb*)&ptr)->FUN_0043f8d0(&z)))));
    reinterpret_cast<::FUN_004bc1f0_S *>((((NiNode*)((void *)(::FUN_00559450((int *)(((Glob*)&(*reinterpret_cast<::Manager *>(&::g_011da24c))))))))))->FUN_004bc1f0(125.0f, 0.0f, 0.0f);
    UpdData i;
    new ((void *)&(i)) ::NiUpdateData(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((NiNode*)((void *)(::FUN_00559450((int *)(((Glob*)&(*reinterpret_cast<::Manager *>(&::g_011da24c))))))))))->FUN_00a59c60((std::intptr_t)(&i));
    void* s;
    s = ((void *)(reinterpret_cast<::MyHost *>((((AVObj*)pin)))->FUN_00a5c570((const ::MyRTTI *)(void *)(&(*reinterpret_cast<void * *>(&::g_011f36ac))))));
    CtrlNode* r;
    if (!!s)
    {
        r = (CtrlNode*)s;
        m_9c = (CtrlNode*)((void *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((r))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Forward")))));
        m_a0 = (ChildObj*)((void *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((r))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Backward")))));
        reinterpret_cast<::NiControllerManager *>((r))->DeactivateAllSequences(0.0f);
        if (!!m_9c)
        {
            reinterpret_cast<::NiControllerManager *>((r))->ActivateControllerSequence((::NiControllerSequence *)(m_9c), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
        }
        if (!!m_a0)
        {
            reinterpret_cast<::FUN_007408d0_Class *>((m_a0))->FUN_007408d0(2);
        }
        ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(pin));
    }
    void* cnt;
    cnt = ((void *)(reinterpret_cast<::MyHost *>((((AVObj*)idx)))->FUN_00a5c570((const ::MyRTTI *)(void *)(&(*reinterpret_cast<void * *>(&::g_011f36ac))))));
    if (!!cnt)
    {
        m_a4 = (CtrlNode*)cnt;
        m_a8 = (ChildObj*)((void *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((m_a4))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Forward")))));
        m_ac = (int)((reinterpret_cast<::fnv_0047a520::Fn47a520 *>((m_a4))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Backward")))));
        m_b0 = (ChildObj*)((void *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((m_a4))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Left")))));
        reinterpret_cast<::NiControllerManager *>((m_a4))->DeactivateAllSequences(0.0f);
        if (!!m_a8)
        {
            reinterpret_cast<::NiControllerManager *>((m_a4))->ActivateControllerSequence((::NiControllerSequence *)(m_a8), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
        }
        if (!!m_b0)
        {
            reinterpret_cast<::FUN_007408d0_Class *>((m_b0))->FUN_007408d0(2);
        }
        ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(idx));
    }
    ((Glob*)&(*reinterpret_cast<char *>(&::g_011da224)))->FUN_0066b0d0(((void *)(reinterpret_cast<::fnv_0078e900::FUN_0078e900_shell *>(this)->FUN_0078e900())));
    ((VObj*)((std::intptr_t)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))->m_dc(((void *)(::FUN_00559450((int *)(((Glob*)&(*reinterpret_cast<::Manager *>(&::g_011da24c))))))), 1);
    float val;
    val = (float)(reinterpret_cast<::Twin_0084d030 *>((((TimeObj*)((::NiPoint3 *)(reinterpret_cast<::FUN_0043d450_Owner *>((((AVObj*)((void *)(::FUN_00559450((int *)(((Glob*)&(*reinterpret_cast<::Manager *>(&::g_011da24c))))))))))->FUN_0043d450())))))->GetStoredFloatValue() * 3.0);
    reinterpret_cast<::SSN_b5 *>((((SceneNode*)((std::intptr_t)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1))))))->FUN_00b5ca70((::Node_b5 *)(void *)(((void *)(::FUN_00559450((int *)(((Glob*)&(*reinterpret_cast<::Manager *>(&::g_011da24c)))))))), val);
}

struct ImageSpaceEffectParam
{
    float r, g, b, a;
    ImageSpaceEffectParam(float, float, float, float);
    ImageSpaceEffectParam ScaleVector4(float);
};
struct StrMem
{
    char* data;
    unsigned short length, capacity;
    StrMem();
    ~StrMem();
};
struct PickTile
{
};
struct PickTemplate
{
};
struct PickWrapper
{
};
struct PickRandom
{
};

struct PickMenu
{
    int unk00;
    void* unk04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    PickTile* unk3c;
    int unk40, unk44;
    PickTile* unk48;
    int unk4c, unk50, unk54, unk58, unk5c, unk60;
    PickTile* unk64;
    int unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    float unk84;
    int unk88;
    void UpdateSweetSpot();
};
// Interpolates pick and driver angles from lock nodes, updates the two angle labels, and builds six sweet-spot tiles with fading colors.
// @fnv 0x00791000
void PickMenu::UpdateSweetSpot()
{
    float fraction;
    int angle = DAT_011da28c[unk70 + 1] - DAT_011da28c[unk70];
    fraction = FUN_00404010(FUN_0040ebd0((float)(unk74 - DAT_011da28c[unk70]) / ((float)angle * 2.0f), 1.0f), 0.0f);
    int range = 0;
    int start = 6;
    ImageSpaceEffectParam end(0.0f, 1.0f, 0.0f, 1.0f);
    ImageSpaceEffectParam color(1.0f, 0.0f, 0.0f, 1.0f);
    ImageSpaceEffectParam count = end;
    reinterpret_cast<::S_00a04150_Class *>((unk64))->FUN_00a04150();
    StrMem text;
    g_iPickAngle_011da208 =
        (int)(*((int *)&(::FUN_0043d4d0((int *)(g_apLockNodes0_011a0328[unk70])))) +
              (*((int *)&(::FUN_0043d4d0((int *)(g_apLockNodes1_011a033c[unk70])))) - *((int *)&(::FUN_0043d4d0((int *)(g_apLockNodes0_011a0328[unk70]))))) *
                  fraction);
    g_iDriverAngle_011da20c =
        (int)(*((int *)&(::FUN_0043d4d0((int *)(g_apLockNodes2_011a0350[unk70])))) +
              (*((int *)&(::FUN_0043d4d0((int *)(g_apLockNodes3_011a0364[unk70])))) - *((int *)&(::FUN_0043d4d0((int *)(g_apLockNodes2_011a0350[unk70]))))) *
                  fraction);
    ::FUN_00406f60((::FUN_00406f90_this *)(::StrMem *)(&text), "%d", g_iPickAngle_011da208);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((unk3c))->FUN_00a01350(0xfc4, (char *)(((const char *)(::FUN_00559450((int *)&(text))))), true);
    ::FUN_00406f60((::FUN_00406f90_this *)(::StrMem *)(&text), "%d", g_iDriverAngle_011da20c);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((unk48))->FUN_00a01350(0xfc4, (char *)(((const char *)(::FUN_00559450((int *)&(text))))), true);
    unk88 = g_iDriverAngle_011da20c + g_iPickAngle_011da208 / 2;
    unk84 = reinterpret_cast<::TileListBoxCalls *>((unk64))->GetFloat(0xfb1) * ::MersenneTwister::GetRandomGenerator()->Float0To1();
    unk84 = FUN_0040ebd0(FUN_00404010(unk84, (float)unk88), reinterpret_cast<::TileListBoxCalls *>((unk64))->GetFloat(0xfb1) - unk88);
    range = (int)(unk84 - g_iPickAngle_011da208 / 2);
    for (int i = 0; i < 6; i++)
    {
        PickTile* tile = ((::PickTile *)(reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((::PickTemplate *)(reinterpret_cast<::Twin_00639b40 *>((((::PickWrapper *)(this->unk04))))->GetEntryPoint()))))->FUN_00a1ddb0({}, {}, {})));
        reinterpret_cast<::Tile *>((tile))->Set(0xfaa, i + 17);
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfb1, (unk84 - range) * 2.0f, true);
        reinterpret_cast<::Tile *>((tile))->Set(0xfa1, range);
        reinterpret_cast<::Tile *>((tile))->Set(0xfad, start);
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfb2, (float)(count.r * 255.0), true);
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfb3, (float)(count.g * 255.0), true);
        reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfb4, (float)(count.b * 255.0), true);
        range -= g_iDriverAngle_011da20c / 5;
        start--;
        count = (*(::ImageSpaceEffectParam *)(reinterpret_cast<::FUN_00532e40_s *>(&(end))->AddDelta((::FUN_00532e40_s *)&(const ::ImageSpaceEffectParam &)((*(::ImageSpaceEffectParam *)(reinterpret_cast<::FUN_00532ec0 *>(&(color))->SUB((::FUN_00532ec0_v4 *)&(end), *(const ::FUN_00532ec0_v4 *)nullptr))).ScaleVector4((float)((i + 1) / 5.0))), {})));
    }
}

struct LKSoundHandle
{
    unsigned int m_uiID;
    unsigned int m_uiState;
    unsigned int m_uiValue1;
    ~LKSoundHandle();
};

class LKAudio
{
  public:
    LKSoundHandle FUN_00ad7550(const char* pcName, int iFlags);
};

class LKSelection
{
  public:
    virtual ~LKSelection();
};

class LKTile
{
  public:
};

struct LKMenuFile
{
};
struct LKInterface
{
};

class LKMenu
{
  public:
    virtual ~LKMenu();
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
    virtual int GetID();  // +0x34
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
    LKTile* m_pkSkillTile;  // +0x2c
    LKTile* m_pkHealthBar;  // +0x30
    LKTile* m_pkLevelTile;  // +0x34
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    LKTile* m_pkSkillLabel;  // +0x50
    LKTile* m_pkLevelLabel;  // +0x54
    int unk58;
    LKTile* m_pkHealthLabel;  // +0x5c
    int unk60;
    int unk64;
    int unk68;
    LockRef* m_pkLockRef;  // +0x6c
    int m_iLockLevel;      // +0x70
    int m_iPickCount;      // +0x74

};

struct LKRef
{
};
struct LKPlayer
{
};


int FUN_00406d50(char* pcBuffer, unsigned int uiSize, const char* pcText);

// Creates the lockpick UI menu from lockpick_menu.xml, sets skill, level, and pick count labels, and returns the menu tile or null on failure.
// @fnv 0x0078db00
LKTile* CreateLockpickMenu(LockRef* pkLockRef, int aiLockLevel, bool bDebug)
{
    char acMessageVal[260];
    char acLabel[64];
    LKSelection* pkSelection = ((::LKSelection *)(::FUN_00a09030(0x3f6)));
    LKInterface* pkInterfaceVal = (LKInterface*)((void *)(::fnv_004b7210::FUN_004b7210()));
    int iLockLevelNum = pkLockRef ? ::LockExtraData::ConvertLockLevel(reinterpret_cast<::fnv_005691b0::P01RefA *>((((LKRef*)pkLockRef)))->FUN_005691b0()) : aiLockLevel;
    iLockLevelNum = MinInt(FUN_00647b70(iLockLevelNum, 0), 4);
    if (pkLockRef && reinterpret_cast<::ActorValueOwner *>(&((*reinterpret_cast<::PlayerStandIn * *>(&::_g_thePlayer))->kAVOwner))->GetActorValueAsInteger((::ActorValue::Index)(0x24)) < ::DAT_011da28c[iLockLevelNum])
    {
        ::FUN_00406d00(acMessageVal, 0x104, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011d1efc))))->GetMenuTitle())), ::DAT_011da28c[iLockLevelNum]);
        ::DispatchMessageToSink((const char *)(acMessageVal), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_padlock.dds"), (int)(0), 2.0f, 0);
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::LKSoundHandle &)(((::LKAudio *)(::FUN_00453a70()))->FUN_00ad7550("UIPopUpMessageGeneral", 0x121)))->FUN_00ad8830(false);
        return 0;
    }
    if (pkSelection)
        delete pkSelection;
    LKTile* pkMenuTileNew = ((::LKTile *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::LKMenuFile *)(reinterpret_cast<::InterfaceManager *>((pkInterfaceVal))->FUN_00586150()))))->FUN_00a01b00({})));
    (*reinterpret_cast<::LKMenu * *>(&::DAT_011da204)) = (LKMenu*)((::LKTile *)(reinterpret_cast<::FUN_00a03c90_shell *>((pkMenuTileNew))->FUN_00a03c90()));
    if ((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204)) && (*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->GetID() == FUN_0078e080())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))))->FUN_00a1dc70((::TileMenu *)(pkMenuTileNew), 0);
        if (!((bool)(reinterpret_cast<::FUN_0078e090_class *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))))->FUN_0078e090())))
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (reinterpret_cast<::TileListBoxCalls *>((pkMenuTileNew))->GetFloat(0xfa7) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((pkMenuTileNew))->GetFloat(0xfa7) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((pkMenuTileNew))->FUN_00a012d0(0xfad, ::Tile::GetInterfaceScale(), 1);
        (*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_pkLockRef = pkLockRef;
        (*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_iLockLevel = iLockLevelNum;
        reinterpret_cast<::Tile *>((((::LKTile *)((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->unk04))))->Set(FUN_00a01860("_DebugMode"), bDebug);
        ::FUN_00406d00(acLabel, 0x40, "%d", (*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_iPickCount);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_pkSkillTile))->FUN_00a01350(DAT_011da1f8, (char *)(acLabel), 1);
        ::FUN_00406d00(acLabel, 0x40, "%s [%d", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011d345c))))->GetMenuTitle())),
                     ::fnv_00648d30::FUN_00648d30(reinterpret_cast<::ActorValueOwner *>(&((*reinterpret_cast<::PlayerStandIn * *>(&::_g_thePlayer))->kAVOwner))->GetActorValueAsInteger((::ActorValue::Index)(0x24)),
                                  ::DAT_011da28c[(*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_iLockLevel]));
        FUN_00406d50(acLabel, 0x40, "%]");
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_pkSkillLabel))->FUN_00a01350(0xfc4, (char *)(acLabel), 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_pkLevelTile))->FUN_00a01350(DAT_011da1f8,
                                                  (char *)(((const char *)(reinterpret_cast<::StartMenu *>(((*reinterpret_cast<StringSetting * (*)[]>(&::DAT_01184a98))[(*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_iLockLevel]))->GetMenuTitle()))), 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_pkHealthLabel))->FUN_00a01350(0xfc4, (char *)("PICK HEALTH: 100%"), 1);
        reinterpret_cast<::FUN_00a01290_shell *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_pkHealthBar))->SetTraitAndReset(DAT_011da1f8, 1.0f);
        reinterpret_cast<::Tile *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_pkHealthBar))->Set(
            DAT_011da1f8, pkLockRef ? reinterpret_cast<::CombatState *>((((LKPlayer*)(*reinterpret_cast<::PlayerStandIn * *>(&::_g_thePlayer)))))->GetInventoryItemCount((::TESForm *)((*reinterpret_cast<intptr_t *>(&::g_pLockpickItem)))) : 0);
        if (FUN_00408b20(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011c3cb4))))->GetMenuTitle())), "ENGLISH"))
        {
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::LKTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pkMenuTileNew))->FUN_00a03da0((char *)("LPM_SkillTitle"))))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011d4d2c))))->GetMenuTitle()))), 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::LKTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pkMenuTileNew))->FUN_00a03da0((char *)("LPM_PickCountTitle"))))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011d4360))))->GetMenuTitle()))), 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::LKTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((pkMenuTileNew))->FUN_00a03da0((char *)("LPM_LevelTitle"))))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011d25bc))))->GetMenuTitle()))), 1);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->m_pkLevelLabel))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting *>(&::g_011d33fc))))->GetMenuTitle()))), 1);
        }
        reinterpret_cast<::ThisCls *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))))->InitLockInterface();
        reinterpret_cast<::PickMenu *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))))->UpdateSweetSpot();
        reinterpret_cast<::Menu *>(((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))))->SetMenuVisibility(0);
        return pkMenuTileNew;
    }
    else
    {
        if ((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204)) && ((::LKTile *)((*reinterpret_cast<::LKMenu * *>(&::DAT_011da204))->unk04)))
            delete (*reinterpret_cast<::LKMenu * *>(&::DAT_011da204));
    }
    return 0;
}

class xMenuBase
{
  public:
    int m_aiBase[9];
    xMenuBase();
    ~xMenuBase();
    virtual void Handle();
};

class xBlock24
{
  public:
    int m_ai[9];
    xBlock24();
};

class xAVOwner
{
  public:
};
class xPlayerL
{
  public:
    int m_aiPad[0x29];
    xAVOwner m_kAV;
};
struct xSetting
{
};

class xLevelMenu : public xMenuBase
{
  public:
    int m_i28;
    int m_aiPad1[0x12];
    int m_i74;
    float m_f78;
    int m_i7c;
    int m_i80;
    int m_aiPad2[2];
    float m_f8c;
    int m_i90;
    float m_f94;
    bool m_b98;
    bool m_b99;
    int m_i9c;
    int m_iA0;
    int m_iA4;
    int m_iA8;
    int m_iAC;
    int m_iB0;
    xBlock24 m_kB4;
    xBlock24 m_kD8;
    xLevelMenu();
    virtual void Handle();
};

// Initializes xLevelMenu by reading trait indices and player AV value, then sets default member values.
// @fnv 0x0078d930
xLevelMenu::xLevelMenu()
{
    ::DAT_011da1f8 = ::FUN_00a00940("_Value", -1);
    ::fnv_0078eb50::xg_iTileId2_11da1fc = ::FUN_00a00940("_x", -1);
    m_i74 = reinterpret_cast<::ActorValueOwner *>(&((*reinterpret_cast<::xPlayerL * *>(&::_g_thePlayer))->m_kAV))->GetActorValueAsInteger((::ActorValue::Index)(0x24));
    m_f78 = (float)m_i74;
    m_f8c = 0.0f;
    m_f94 = 1.0f + m_f78 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::originalRuntimeFloatSetting806))))));
    m_i28 = 0;
    m_b98 = false;
    m_i9c = 0;
    m_iA0 = 0;
    m_iA8 = 0;
    m_iAC = 0;
    m_iB0 = 0;
    m_b99 = false;
    m_i80 = 0;
}

namespace fnv_0078eb50 {
struct xUpdateData
{
    xUpdateData(float, bool, bool);
    float m_t;
    bool m_kPointA, m_kPointB, m_iThirdValue, m_iFourthElementInteger, m_usTrailingValue;
};
struct xPoint3
{
    float x, y, z;
};
struct xMat3
{
    float m[9];
};
struct xRTTI
{
    int m_iWordAt00;
};
struct xSeq
{
};
struct xCtrlMgr
{
};
struct xAV
{
};
struct xNodePtr
{
};
struct xTile
{
};
struct xMenuMode
{
};
struct xIface
{
    char m_auiShapeKeys[0x4d4];
    xMenuMode m_4d4;
};
struct xControls
{
};
struct xOS
{
};
struct ClockSource
{
};
struct xSound
{
    xSound();
    ~xSound();
    xSound& operator=(const xSound&);
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xAudio
{
    xSound FUN_00ad7550(const char*, unsigned int);
};
struct xStrSetting
{
};
struct xFltSetting
{
};
struct xForm
{
    int FUN_00401170();
};
struct xLock
{
    int m_iWordAt00, m_iWordAt04, m_8, m_iThirdValue, m_10;
};
struct xFaction : xForm
{
};

struct xAVOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetAV(int);
};

struct xNPC : xForm
{
    char m_auiShapeKeys[0x100];
    xAVOwner m_100;
};
struct xPlayer;
struct xRef : xForm
{
    bool FUN_00573170(xPlayer*, int, int, int);
};
struct xCrimeMgr
{
};

struct xPlayer
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
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void RemoveItem(void*, int, int, int, int, int, int, int, int, int);
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290(int);
    char m_auiShapeKeys[0x208];
    bool m_20c;
};

extern float xg_fElapsed_11da2ac;
extern int xg_iLastState_11da2a8;
extern bool xg_bMsg_11da2a4;
extern int xg_iDir_11a0394;
bool xF702450(int);

static const char s_szIcon[] = "Interface\\Icons\\Message Icons\\glow_message_vaultboy_surprised.dds";
static const char s_szEnter[] = "UILockpickingEnter";
static const char s_szTurn[] = "UILockpickingCylinderTurn";
static const char s_szSqueakA[] = "UILockpickingCylinderSqueakA";
static const char s_szSqueakB[] = "UILockpickingCylinderSqueakB";
static const char s_szUnlock[] = "UILockpickingUnlock";
static const char s_szOpened[] = "LOCK OPENED!  :D";
static const char s_szStop[] = "UILockpickingCylinderStop";
static const char s_szTension[] = "UILockpickingPickTensionLPM";
static const char s_szHealthFmt[] = "PICK HEALTH: %d%s";
static const char s_szPercent[] = "%";
static const char s_szBreak[] = "UILockpickingPickBreak";
static const char s_szHealthFull[] = "PICK HEALTH: 100%";
extern const char s_litEnd78eb50[] = "";

struct xLockPickMenu
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
    virtual int v13();

    int m_pad04[9];
    int m_28;
    int m_2c;
    xTile* m_30;
    int m_pad34[9];
    xTile* m_58;
    xTile* m_5c;
    int m_60;
    xTile* m_64;
    xTile* m_68;
    xRef* m_6c;
    int m_70;
    int m_74;
    float m_78;
    int m_7c;
    int m_80;
    int m_84, m_88;
    float m_8c;
    float m_90;
    float m_94;
    bool m_98;
    bool m_99;
    xSeq* m_9c;
    xSeq* m_a0;
    xCtrlMgr* m_a4;
    xSeq* m_a8;
    xSeq* m_ac;
    xSeq* m_b0;
    xMat3 m_b4;
    xPoint3 m_d8;
    void FUN_0078eb50();
};

// Updates the lockpicking menu state machine, advancing sequences, adjusting tension, and handling lock success or pick breakage.
// @fnv 0x0078eb50
void xLockPickMenu::FUN_0078eb50()
{
    int qSVM = 0;
    float qrEZrs = 1.0f;
    static xSound s_kTension;
    bool qpqRa = xF702450(v13());
    if (m_80 == 0)
    {
        qSVM = 0;
        xg_fElapsed_11da2ac = 0.0f;
        xg_iLastState_11da2a8 = 0;
    }
    else
    {
        qSVM = ((int)(::fnv::timer::Time())) - m_80;
        if (xg_iLastState_11da2a8 != m_28)
            xg_fElapsed_11da2ac = 0.0f;
        else
            xg_fElapsed_11da2ac += qSVM / 1000.0;
    }
    m_80 = ((int)(::fnv::timer::Time()));
    xg_iLastState_11da2a8 = m_28;
    if (m_99)
    {
        if (qpqRa && reinterpret_cast<::S8840 *>(&(((::fnv_0078eb50::xIface *)(::fnv_004b7210::FUN_004b7210()))->m_4d4))->FUN_00718840(::FUN_00790290()))
            m_99 = false;
        else
            return;
    }
    if (!qpqRa)
        reinterpret_cast<::FUN_00a012d0_t *>((((::fnv_0078eb50::xTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::fnv_0078eb50::xIface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0045cd60()))))->FUN_00a012d0(0xfa9, 255.0f, true);
    int qsSDDgz = 0;
    int qfTOqo = 0x7fff;
    if (::FUN_004b71d0())
    {
        qsSDDgz = reinterpret_cast<::FUN_00a23390_t *>((((::fnv_0078eb50::xControls *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0078eb50::xOS * *>(&::g_osGlobals))))->FUN_00877720()))))->GetAxisState(0, 9);
        if (((float)(::FUN_00408820((float)qsSDDgz))) <= 8689.0)
            qsSDDgz = 0;
        qrEZrs = -qsSDDgz / 32767.0;
    }
    switch (m_28)
    {
    case 0:
        if (m_9c && m_a8)
        {
            xUpdateData UPD0(xg_fElapsed_11da2ac, true, false);
            xUpdateData UPD1(xg_fElapsed_11da2ac, true, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_0078eb50::xAV *)(reinterpret_cast<::NiNode *>((((::fnv_0078eb50::xAV *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0078eb50::xNodePtr *>(&::g_011da24c))))))))->GetAt(0)))))->FUN_00a59c60((std::intptr_t)&(UPD0));
            if (xg_fElapsed_11da2ac == 0.0 || !m_6c || reinterpret_cast<::TileListBoxCalls *>((m_30))->GetFloat(::DAT_011da1f8) > 0.0)
                reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_0078eb50::xAV *)(reinterpret_cast<::NiNode *>((((::fnv_0078eb50::xAV *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0078eb50::xNodePtr *>(&::g_011da24c))))))))->GetAt(1)))))->FUN_00a59c60((std::intptr_t)&(UPD1));
            if (xg_fElapsed_11da2ac == 0.0 && m_6c)
            {
                if (reinterpret_cast<::TileListBoxCalls *>((m_30))->GetFloat(::DAT_011da1f8) <= 0.0)
                    ::DispatchMessageToSink((const char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0078eb50::xStrSetting *>(&::g_011d34ec))))->GetMenuTitle()))), 0, (const char *)(s_szIcon), (int)(0), 2.0f, 0);
                else
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_0078eb50::xSound &)(((::fnv_0078eb50::xAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szEnter, 0x121)))->FUN_00ad8830(false);
            }
            if (reinterpret_cast<::FUN_00508100_shell *>((m_9c))->FUN_00508100() <= xg_fElapsed_11da2ac)
            {
                xCtrlMgr* qArxcFu =
                    (xCtrlMgr*)((void *)(reinterpret_cast<::MyHost *>((((::fnv_0078eb50::xAV *)(reinterpret_cast<::NiNode *>((((::fnv_0078eb50::xAV *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0078eb50::xNodePtr *>(&::g_011da24c))))))))->GetAt(0)))))->FUN_00a5c570((const ::MyRTTI *)(const ::fnv_0078eb50::xRTTI *)(&(*reinterpret_cast<::fnv_0078eb50::xRTTI *>(&::g_011f36ac))))));
                xAV* qAhbO = ((::fnv_0078eb50::xAV *)(reinterpret_cast<::NiNode *>((((::fnv_0078eb50::xAV *)(reinterpret_cast<::NiNode *>((((::fnv_0078eb50::xAV *)(reinterpret_cast<::NiNode *>((((::fnv_0078eb50::xAV *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0078eb50::xNodePtr *>(&::g_011da24c))))))))->GetAt(0)))))->GetAt(0)))))->GetAt(2)));
                xPoint3 qxQHW = (*(const ::fnv_0078eb50::xPoint3 *)&(reinterpret_cast<::NiAVObject *>((qAhbO))->FUN_0043c490()));
                m_28 = 2;
                reinterpret_cast<::NiControllerManager *>((qArxcFu))->StopSequence((::NiControllerSequence *)(m_9c), 0.0f);
                reinterpret_cast<::NiControllerManager *>((qArxcFu))->ActivateControllerSequence((::NiControllerSequence *)(m_a0), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::NiControllerManager *>((m_a4))->StopSequence((::NiControllerSequence *)(m_a8), 0.0f);
                reinterpret_cast<::NiControllerManager *>((m_a4))->ActivateControllerSequence((::NiControllerSequence *)(m_ac), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            }
        }
        break;
    case 1:
        if (m_a8)
        {
            xUpdateData UPDB(xg_fElapsed_11da2ac, true, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_0078eb50::xAV *)(reinterpret_cast<::NiNode *>((((::fnv_0078eb50::xAV *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0078eb50::xNodePtr *>(&::g_011da24c))))))))->GetAt(1)))))->FUN_00a59c60((std::intptr_t)&(UPDB));
            if (reinterpret_cast<::FUN_00508100_shell *>((m_a8))->FUN_00508100() <= xg_fElapsed_11da2ac)
            {
                m_28 = 2;
                reinterpret_cast<::NiControllerManager *>((m_a4))->StopSequence((::NiControllerSequence *)(m_a8), 0.0f);
                reinterpret_cast<::NiControllerManager *>((m_a4))->ActivateControllerSequence((::NiControllerSequence *)(m_ac), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            }
        }
        break;
    case 2:
        if (((bool)(::fnv_005d4a40::FUN_005d4a40())) && !reinterpret_cast<::S8840 *>(&(((::fnv_0078eb50::xIface *)(::fnv_004b7210::FUN_004b7210()))->m_4d4))->FUN_00718840(::FUN_00790290()))
        {
            m_99 = reinterpret_cast<::TutorialMessageGate718 *>(&(((::fnv_0078eb50::xIface *)(::fnv_004b7210::FUN_004b7210()))->m_4d4))->FUN_00718630(::FUN_00790290(), ::FUN_0078e080(), 0);
        }
        else if (qpqRa)
        {
            if (!m_6c || reinterpret_cast<::TileListBoxCalls *>((m_30))->GetFloat(::DAT_011da1f8) > 0.0)
            {
                if ((::FUN_004b71d0() && qrEZrs > 0.0) || (!::FUN_004b71d0() && reinterpret_cast<::C1540Menu *>(this)->FUN_00791540(true)))
                {
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_0078eb50::xSound &)(((::fnv_0078eb50::xAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szTurn, 0x121)))->FUN_00ad8830(false);
                    m_28 = 3;
                }
                reinterpret_cast<::C *>(this)->FUN_007908f0();
            }
            if (m_8c > 0.0)
            {
                float OLD2 = m_8c;
                m_8c -= qSVM * 90 / 1000.0;
                m_8c = ::FUN_00404010(m_8c, 0.0f);
                reinterpret_cast<::fnv_00790f40::FUN_00790f40_cls *>(this)->AdvanceSequence(0.0f);
                if (m_8c < 30.0 && OLD2 > 30.0)
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_0078eb50::xSound &)(((::fnv_0078eb50::xAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szSqueakA, 0x101)))->FUN_00ad8830(false);
                if (m_8c < 60.0 && OLD2 > 60.0)
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_0078eb50::xSound &)(((::fnv_0078eb50::xAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szSqueakB, 0x101)))->FUN_00ad8830(false);
            }
        }
        break;
    case 3:
        if (!m_98 &&
            (!qpqRa || (::FUN_004b71d0() && qrEZrs <= 0.0) || (!::FUN_004b71d0() && !reinterpret_cast<::C1540Menu *>(this)->FUN_00791540(false))))
        {
            reinterpret_cast<::FUN_00a25810_Class *>((((::fnv_0078eb50::xControls *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0078eb50::xOS * *>(&::g_osGlobals))))->FUN_00877720()))))->ResetTargetState();
            m_28 = 2;
        }
        else
        {
            float OLD3 = m_8c;
            if (m_98)
                qrEZrs = 1.0f;
            if (m_8c <= m_90)
            {
                m_8c += qSVM * 90 * qrEZrs / 1000.0;
                m_8c = ::FUN_0040ebd0(m_8c, m_90);
            }
            reinterpret_cast<::fnv_00790f40::FUN_00790f40_cls *>(this)->AdvanceSequence(0.0f);
            if (::FUN_004b71d0())
                reinterpret_cast<::Controller *>((((::fnv_0078eb50::xControls *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0078eb50::xOS * *>(&::g_osGlobals))))->FUN_00877720()))))->FUN_00a255b0(0.1f, 0.0f, 0xfa, 0x7d, 3, 1, 0);
            if (OLD3 < 30.0 && m_8c > 30.0)
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_0078eb50::xSound &)(((::fnv_0078eb50::xAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szSqueakA, 0x101)))->FUN_00ad8830(false);
            if (OLD3 < 60.0 && m_8c > 60.0)
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_0078eb50::xSound &)(((::fnv_0078eb50::xAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szSqueakB, 0x101)))->FUN_00ad8830(false);
            if (m_8c >= m_90)
            {
                if (m_8c >= 90.0)
                {
                    if (m_6c)
                    {
                        ::TopicMenuController::IncrementMiscStat(4);
                        if (((::fnv_0078eb50::xLock *)(reinterpret_cast<::FUN_00569160_shell *>((m_6c))->FUN_00569160()))->m_10 == 0)
                        {
                            (*reinterpret_cast<::fnv_0078eb50::xPlayer * *>(&::_g_thePlayer))->v290(::FUN_006705b0(3, m_70));
                            ((::fnv_0078eb50::xLock *)(reinterpret_cast<::FUN_00569160_shell *>((m_6c))->FUN_00569160()))->m_10++;
                            reinterpret_cast<::fnv_005789b0::FUN_005789b0_shell *>((m_6c))->FUN_005789b0();
                        }
                        if (((::fnv_0078eb50::xForm *)(reinterpret_cast<::OwnerLookupView *>((m_6c))->FUN_00567790())))
                        {
                            xForm* OWNER = ((::fnv_0078eb50::xForm *)(reinterpret_cast<::OwnerLookupView *>((m_6c))->FUN_00567790()));
                            void* CRIME = 0;
                            if (OWNER->FUN_00401170() == 8)
                            {
                                xFaction* FACA = (xFaction*)OWNER;
                                CRIME = ((void *)(reinterpret_cast<::fnv_00970b30::Cls *>(&((*reinterpret_cast<::fnv_0078eb50::xCrimeMgr *>(&::g_011e0e80))))->FUN_00970b30((::fnv_00970b30::TESFaction *)(FACA), 1, 1)));
                            }
                            else
                            {
                                xNPC* NPCA = (xNPC*)OWNER;
                                CRIME = ((void *)(reinterpret_cast<::Holder *>(&((*reinterpret_cast<::fnv_0078eb50::xCrimeMgr *>(&::g_011e0e80))))->FUN_00970a20(NPCA, 1)));
                            }
                            if (CRIME)
                            {
                                reinterpret_cast<::FUN_00915d20_shell *>(((*reinterpret_cast<::fnv_0078eb50::xPlayer * *>(&::_g_thePlayer))))->FUN_00915d20(1);
                                reinterpret_cast<::ActorX *>(((*reinterpret_cast<::fnv_0078eb50::xPlayer * *>(&::_g_thePlayer))))->FUN_008bfa40((::RefObj *)(CRIME), 0, 0, 0, (::TESForm *)(OWNER));
                            }
                            else
                            {
                                bool BOUNTY = false;
                                if (OWNER && OWNER->FUN_00401170() == 8)
                                {
                                    xFaction* FACB = (xFaction*)OWNER;
                                    if (!reinterpret_cast<::FUN_0047d7c0_Class *>((FACB))->FUN_0047d7c0())
                                        BOUNTY = true;
                                }
                                else if (OWNER)
                                {
                                    xNPC* NPCB = (xNPC*)OWNER;
                                    if (NPCB)
                                    {
                                        int DISP = ::fnv_0047e040::FUN_0047e040(NPCB->m_100.GetAV(0x17));
                                        if (DISP != 2 && DISP != 4)
                                            BOUNTY = true;
                                    }
                                }
                                if (BOUNTY)
                                    reinterpret_cast<::KarmaActor *>(((*reinterpret_cast<::fnv_0078eb50::xPlayer * *>(&::_g_thePlayer))))->FUN_0094fd30((int)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0078eb50::xFltSetting *>(&::originalRuntimeFloatSetting282)))))));
                            }
                        }
                        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_0078eb50::xSound &)(((::fnv_0078eb50::xAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szUnlock, 0x101)))->FUN_00ad8830(false);
                        reinterpret_cast<::fnv_005692a0::FUN_005692a0_shell *>((m_6c))->FUN_005692a0();
                        if (m_6c->FUN_00401170() == 0x1c)
                            (*reinterpret_cast<::fnv_0078eb50::xPlayer * *>(&::_g_thePlayer))->m_20c = true;
                        if (((::fnv_0078eb50::xForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_6c))->FUN_007af430())) && ((::fnv_0078eb50::xForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((m_6c))->FUN_007af430()))->FUN_00401170() == 0x1b)
                            ::FUN_0075b6e0(1);
                        m_6c->FUN_00573170((*reinterpret_cast<::fnv_0078eb50::xPlayer * *>(&::_g_thePlayer)), 0, 0, 1);
                        if (m_6c->FUN_00401170() == 0x1c)
                            (*reinterpret_cast<::fnv_0078eb50::xPlayer * *>(&::_g_thePlayer))->m_20c = false;
                        ::FUN_0078e0d0();
                    }
                    else
                    {
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_58))->FUN_00a01350(0xfc4, (char *)(s_szOpened), true);
                        reinterpret_cast<::Tile *>((m_58))->Set(0xfa3, 1);
                        if (!m_6c)
                            reinterpret_cast<::Tile *>((m_30))->Set(::DAT_011da1f8, 0);
                        xg_bMsg_11da2a4 = true;
                        m_28 = 6;
                    }
                }
                else
                {
                    reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_0078eb50::xSound &)(((::fnv_0078eb50::xAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szStop, 0x101)))->FUN_00ad8830(false);
                    reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::fnv_0078eb50::xSound &)(s_kTension))->operator=((const ::SoundPlaybackHandle &)((const ::fnv_0078eb50::xSound &)(((::fnv_0078eb50::xAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szTension, 1))));
                    reinterpret_cast<::FUN_00ad8830_shell *>(&(s_kTension))->FUN_00ad8830(true);
                    m_28 = 4;
                }
                reinterpret_cast<::FUN_00a25810_Class *>((((::fnv_0078eb50::xControls *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0078eb50::xOS * *>(&::g_osGlobals))))->FUN_00877720()))))->ResetTargetState();
            }
        }
        break;
    case 4:
        if (!qpqRa || (::FUN_004b71d0() && qrEZrs <= 0.0) ||
            (!::FUN_004b71d0() && !reinterpret_cast<::C1540Menu *>(this)->FUN_00791540(false)))
        {
            reinterpret_cast<::SoundPlaybackHandle *>(&(s_kTension))->StopWithFade(500);
            reinterpret_cast<::FUN_00a25810_Class *>((((::fnv_0078eb50::xControls *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0078eb50::xOS * *>(&::g_osGlobals))))->FUN_00877720()))))->ResetTargetState();
            m_28 = 2;
        }
        else
        {
            xUpdateData qxWmVch(0.0f, true, false);
            float qQMZREG = qSVM / 1000.0;
            char qJDuOZ[0x20];
            if (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0078eb50::xFltSetting *>(&::g_011d41c8)))))) != 0.0)
                m_94 -= qQMZREG / *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0078eb50::xFltSetting *>(&::g_011d41c8))))));
            m_94 = ::FUN_00404010(m_94, 0.0f);
            reinterpret_cast<::fnv_00790f40::FUN_00790f40_cls *>(this)->AdvanceSequence(xg_iDir_11a0394 * 0.25);
            if (::FUN_004b71d0())
                reinterpret_cast<::Controller *>((((::fnv_0078eb50::xControls *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0078eb50::xOS * *>(&::g_osGlobals))))->FUN_00877720()))))->FUN_00a255b0(0.5f, 0.0f, 0xfa, 0, 0, 0, 0);
            if (m_ac)
            {
                reinterpret_cast<::fnv_00a328b0::SeqExt *>((m_ac))->FUN_00a328b0(reinterpret_cast<::FUN_00759450_shell *>((m_ac))->FUN_00759450() + (1.0 - m_94) * (reinterpret_cast<::FUN_00508100_shell *>((m_ac))->FUN_00508100() - reinterpret_cast<::FUN_00759450_shell *>((m_ac))->FUN_00759450()),
                                   0);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_0078eb50::xAV *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0078eb50::xNodePtr *>(&::g_011da24c))))))))->FUN_00a59c60((std::intptr_t)&(qxWmVch));
            }
            reinterpret_cast<::LockPickState *>(this)->UpdateLockRotation(reinterpret_cast<::TileListBoxCalls *>((m_68))->GetFloat(xg_iTileId2_11da1fc) + xg_iDir_11a0394 * 2.5);
            xg_iDir_11a0394 = -xg_iDir_11a0394;
            ::FUN_00406d00(qJDuOZ, 0x20, s_szHealthFmt, (int)::InventoryStackRecord::RoundToNearestStep(m_94 * 100.0, 1.0f), s_szPercent);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_5c))->FUN_00a01350(0xfc4, (char *)(qJDuOZ), true);
            if (m_94 <= 0.0)
            {
                reinterpret_cast<::SoundPlaybackHandle *>(&(s_kTension))->StopWithFade(100);
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::fnv_0078eb50::xSound &)(((::fnv_0078eb50::xAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szBreak, 0x101)))->FUN_00ad8830(false);
                if (m_6c)
                    (*reinterpret_cast<::fnv_0078eb50::xPlayer * *>(&::_g_thePlayer))->RemoveItem((*reinterpret_cast<void * *>(&::g_pLockpickItem)), 0, 1, 0, 0, 0, 0, 0, 1, 0);
                reinterpret_cast<::FUN_00a012d0_t *>((m_30))->FUN_00a012d0(::DAT_011da1f8, reinterpret_cast<::TileListBoxCalls *>((m_30))->GetFloat(::DAT_011da1f8) - 1.0, true);
                reinterpret_cast<::NiControllerManager *>((m_a4))->StopSequence((::NiControllerSequence *)(m_ac), 0.0f);
                reinterpret_cast<::NiControllerManager *>((m_a4))->ActivateControllerSequence((::NiControllerSequence *)(m_b0), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                reinterpret_cast<::FUN_00a25810_Class *>((((::fnv_0078eb50::xControls *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::fnv_0078eb50::xOS * *>(&::g_osGlobals))))->FUN_00877720()))))->ResetTargetState();
                m_28 = 5;
            }
        }
        break;
    case 5:
        if (m_b0 && qpqRa)
        {
            xUpdateData UPD5(xg_fElapsed_11da2ac, true, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_0078eb50::xAV *)(reinterpret_cast<::NiNode *>((((::fnv_0078eb50::xAV *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0078eb50::xNodePtr *>(&::g_011da24c))))))))->GetAt(1)))))->FUN_00a59c60((std::intptr_t)&(UPD5));
            if (reinterpret_cast<::FUN_00508100_shell *>((m_b0))->FUN_00508100() <= xg_fElapsed_11da2ac)
                m_28 = 6;
        }
        break;
    case 6:
        if (xg_fElapsed_11da2ac >= 1.0 && qpqRa)
        {
            reinterpret_cast<::Tile *>((m_58))->Set(0xfa3, 0);
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_5c))->FUN_00a01350(0xfc4, (char *)(s_szHealthFull), true);
            m_94 = 1.0f + m_78 * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_0078eb50::xFltSetting *>(&::originalRuntimeFloatSetting806))))));
            m_8c = 0.0f;
            reinterpret_cast<::fnv_00790f40::FUN_00790f40_cls *>(this)->AdvanceSequence(0.0f);
            reinterpret_cast<::FUN_00a012d0_t *>((m_68))->FUN_00a012d0(xg_iTileId2_11da1fc, reinterpret_cast<::TileListBoxCalls *>((m_64))->GetFloat(0xfb1) / 2.0, true);
            reinterpret_cast<::FUN_00440460_S *>((((::fnv_0078eb50::xAV *)(reinterpret_cast<::NiNode *>((((::fnv_0078eb50::xAV *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0078eb50::xNodePtr *>(&::g_011da24c))))))))->GetAt(1)))))->FUN_00440460((const ::V3 *)&(m_d8));
            reinterpret_cast<::FUN_0043fa80_s *>((((::fnv_0078eb50::xAV *)(reinterpret_cast<::NiNode *>((((::fnv_0078eb50::xAV *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0078eb50::xNodePtr *>(&::g_011da24c))))))))->GetAt(1)))))->FUN_0043fa80((const ::ThreeByThreeMatrix &)(m_b4));
            reinterpret_cast<::NiControllerManager *>((m_a4))->DeactivateAllSequences(0.0f);
            reinterpret_cast<::NiControllerManager *>((m_a4))->ActivateControllerSequence((::NiControllerSequence *)(m_a8), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            if (xg_bMsg_11da2a4)
            {
                reinterpret_cast<::PickMenu *>(this)->UpdateSweetSpot();
                xg_bMsg_11da2a4 = false;
            }
            if (m_6c && reinterpret_cast<::TileListBoxCalls *>((m_30))->GetFloat(::DAT_011da1f8) == 0.0)
            {
                ::DispatchMessageToSink((const char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0078eb50::xStrSetting *>(&::g_011d34ec))))->GetMenuTitle()))), 0, (const char *)(s_szIcon), (int)(0), 2.0f, 0);
                reinterpret_cast<::Tile *>((m_58))->Set(0xfa3, 0);
                xUpdateData UPD6(0.0f, true, false);
                reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_0078eb50::xAV *)(reinterpret_cast<::NiNode *>((((::fnv_0078eb50::xAV *)(::FUN_00559450((int *)&((*reinterpret_cast<::fnv_0078eb50::xNodePtr *>(&::g_011da24c))))))))->GetAt(1)))))->FUN_00a59c60((std::intptr_t)&(UPD6));
                m_28 = 2;
            }
            else
            {
                m_28 = 1;
            }
        }
        break;
    case 7:
        if (((int)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType())) != 2)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((((::fnv_0078eb50::xTile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((::fnv_0078eb50::xIface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_0045cd60()))))->FUN_00a012d0(0xfa9, 255.0f, true);
            reinterpret_cast<::fnv_00718930::LLD_PlayerCharacter *>((((::fnv_0078eb50::xIface *)(::fnv_004b7210::FUN_004b7210()))))->FUN_00718930(1);
            reinterpret_cast<::Tile *>((((::fnv_0078eb50::xTile *)(reinterpret_cast<::Callees *>(this)->FUN_00726070()))))->Set(0x1772, 1);
            reinterpret_cast<::FUN_00a1d910_shell *>(this)->FUN_00a1d910();
        }
        break;
    }
}
}  // namespace fnv_0078eb50

#include "generated/data/fallout/interface/menus/lockpickmenu.inc"
