#include "AutoMemContext.h"

// src/fallout/ai/combat/explosion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/explosion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/havok_array_view.h"
#include "fnv/game_timer.h"
#include "fnv/tls.h"
#include <cstdint>
#include <new>
#include "fnv/decl/B930700Actor.h"
#include "fnv/decl/BSFadeNode.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/Cl537.h"
#include "fnv/decl/FUN_0040a1e0_shell.h"
#include "fnv/decl/FUN_00422220_shell.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_00477950_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004fb810_shell.h"
#include "fnv/decl/FUN_004fb970_class.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00622570_Class.h"
#include "fnv/decl/FUN_006317a0_struct.h"
#include "fnv/decl/FUN_00644930_shell.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_00865db0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_009acd00_Class.h"
#include "fnv/decl/FUN_009b1260_Class.h"
#include "fnv/decl/FUN_009b12d0_Class.h"
#include "fnv/decl/FUN_009d9f40_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00cbc920.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/HandlerView.h"
#include "fnv/decl/Holder0057c400.h"
#include "fnv/decl/Host096d450.h"
#include "fnv/decl/ImageSpaceModifierInstanceForm.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MagicItem.h"
#include "fnv/decl/MagicTarget.h"
#include "fnv/decl/Owner009b11c0.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/S_009b13a0_Cls.h"
#include "fnv/decl/ScriptList.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_0054ca90__Cell.h"
#include "fnv/decl/fnv_0056fa90__Holder.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_0092ed60__FNVCurrent.h"
#include "fnv/decl/fnv_00932880__FUN_00932880_shell.h"
#include "fnv/decl/fnv_00932a00__FUN_00932a00_t.h"
#include "fnv/decl/fnv_00932b70__FUN_00932b70_shell.h"
#include "fnv/decl/fnv_00932d60__FUN_00932d60_shell.h"
#include "fnv/decl/fnv_009ac940__FUN_009ac940.h"
#include "fnv/decl/fnv_009b2940__WaterActor.h"
#include "fnv/decl/fnv_009d9f20__FUN_009d9f20_shell.h"
#include "fnv/decl/fnv_00c5b370__ItemQueue.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b2000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00578000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_008d1000.h"
#include "fnv/symbols_009ad000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/FUN_00c9c390_Class.h"
#include "fnv/decl/NiObject.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/decl/SoundPlayback.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_00689000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00c9c000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_011b2000.h"
#include "fnv/symbols_01204000.h"
#include "fnv/symbols_01267000.h"
#include <math.h>
#include <xmmintrin.h>
#include "fnv/decl/FUN_00c867d0_cls.h"
#include "fnv/decl/FUN_00c86800_Class.h"
#include "fnv/decl/FUN_00c868b0_cls.h"
#include "fnv/decl/HashTableBase.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/Wrapper86b80.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/fnv_00c86790__Holder.h"
#include "fnv/decl/fnv_00cbc7b0__FUN_00cbc7b0_cls.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_01272000.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSXFlags_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004dfec0_Class.h"
#include "fnv/decl/FUN_00507610_Class.h"
#include "fnv/decl/FUN_005076c0Class.h"
#include "fnv/decl/FUN_00507e10_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_0056d360_Class.h"
#include "fnv/decl/FUN_00622290_cls.h"
#include "fnv/decl/FUN_006e4340_Class.h"
#include "fnv/decl/FUN_00810550_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00c6b980_cls.h"
#include "fnv/decl/FUN_00cbc740.h"
#include "fnv/decl/MersenneTwister.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/SceneC8E.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_0056f110__FUN_0056f110_class.h"
#include "fnv/decl/s005468d0__Owner.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00448000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005c1000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/decl/Actor9af.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/Class_007f68a0.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00452370_shell.h"
#include "fnv/decl/FUN_00457880_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a3fe0_shell.h"
#include "fnv/decl/FUN_004a40a0_Class.h"
#include "fnv/decl/FUN_004a40c0_Class.h"
#include "fnv/decl/FUN_004a41c0.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_004a51b0_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004fb7d0_shell.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_006205a0_Class.h"
#include "fnv/decl/FUN_006233c0.h"
#include "fnv/decl/FUN_0062e150_cls.h"
#include "fnv/decl/FUN_00632d40_shell.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0068a810_class.h"
#include "fnv/decl/FUN_0068a830_shell.h"
#include "fnv/decl/FUN_008aff10_obj.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009acce0_shell.h"
#include "fnv/decl/FUN_00c84f10_cls.h"
#include "fnv/decl/FnCls.h"
#include "fnv/decl/GlobalObject_008c71b0.h"
#include "fnv/decl/Owner623.h"
#include "fnv/decl/S50.h"
#include "fnv/decl/S819.h"
#include "fnv/decl/S_00c9f1e0_Obj.h"
#include "fnv/decl/ScreenSplatter.h"
#include "fnv/decl/ShadowLightData.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Unk.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_004a40e0__FUN_004a40e0.h"
#include "fnv/decl/fnv_004a4220__FUN_004a4220Class.h"
#include "fnv/decl/fnv_00623090__Host.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009b00a0__Obj082.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a1000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_009b2000.h"
#include "fnv/symbols_00c7f000.h"
#include "fnv/symbols_00cbd000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011f4000.h"
struct ActorCause
{
};
class NiPointer
{
  public:
    NiPointer& operator=(ActorCause*);
};
struct FUN_009ac170_shell
{
    char m_auiShapeKeys[0xd0];
    NiPointer m_actorCause;
    void FUN_009ac170(ActorCause* apActorCause);
};

struct Explosion
{
    virtual ~Explosion();
    void* Destroy(unsigned int flags);
};


struct NiRTTI;
struct bhkLiquidAction
{
    const NiRTTI* GetRTTI() const;
};


// @fnv 0x009ae240
const NiRTTI* bhkLiquidAction::GetRTTI() const
{
    return &(*reinterpret_cast<::NiRTTI *>(&::g_01268420));
}

class NavMesh;

struct NavMeshPtr
{
    NavMesh* FUN_00458b50();
};

NavMesh* NavMeshPtr::FUN_00458b50()
{
    return 0;
}

struct FUN_009afc30_shell
{
    NavMeshPtr m_navMeshPtr;
    NavMesh* FUN_009afc30();
};

// @fnv 0x009afc30
NavMesh* FUN_009afc30_shell::FUN_009afc30()
{
    return ((NavMeshPtr*)((char*)this + 8))->FUN_00458b50();
}

namespace fnv_009b2770 {
struct BGSLoadFormBuffer;

class MobileObject
{
};

struct Explosion : MobileObject
{
    void FUN_009b2770(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x009b2770
void Explosion::FUN_009b2770(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::fnv_00932d60::FUN_00932d60_shell *>(this)->FUN_00932d60((::fnv_00932d60::BGSLoadFormBuffer *)(apLoadGameBuffer));
}
}  // namespace fnv_009b2770

struct BSOcclusionPlane
{
    int IsNotCulled();
};

// @fnv 0x009ad5f0
int BSOcclusionPlane::IsNotCulled()
{
    return !((intptr_t)(reinterpret_cast<::LowProcess *>((void *)this)->GetTarget()));
}

struct FUN_009afbb0_shell
{
    virtual ~FUN_009afbb0_shell();
    void* FUN_009afbb0(unsigned int flags);
};

extern "C" void __cdecl FUN_009afbe0(void*);

struct FUN_00621100_shell
{
    void SetVtable(void);
};

struct FUN_009afc10_shell
{
    void FUN_009afc10();
};
// Calls FUN_009afc10, then if bit 0 of flags is set calls FUN_009afbe0 on this, and returns this.
// @fnv 0x009afbb0
void* FUN_009afbb0_shell::FUN_009afbb0(unsigned int flags)
{
    reinterpret_cast<::FUN_009afc10_shell *>(this)->FUN_009afc10();
    if (flags & 1)
        FUN_009afbe0(this);
    return this;
}

// @fnv 0x009afc10
void FUN_009afc10_shell::FUN_009afc10()
{
    ((FUN_00621100_shell*)this)->SetVtable();
}

struct FUN_009afc50_shell
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    NavMesh* FUN_009afc30();
};

// @fnv 0x009afc50
NavMesh* FUN_009afc50_shell::FUN_009afc30()
{
    return m_navMeshPtr.FUN_00458b50();
}

void __cdecl FUN_009ac940(void*);
struct FUN_009ac910_shell
{
    void FUN_009ac940();
    void* FUN_009ac910(unsigned int flags);
};
// Calls FUN_009ac940, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009ac910
void* FUN_009ac910_shell::FUN_009ac910(unsigned int flags)
{
    reinterpret_cast<::fnv_009ac940::FUN_009ac940 *>(this)->fnv_009ac940::FUN_009ac940::~FUN_009ac940();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00cbc920_shell
{
};
struct StandIn
{
    void* FUN_009ae250(unsigned int);
};
// Calls FUN_00cbc920 on this, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x009ae250
void* StandIn::FUN_009ae250(unsigned int flags)
{
    reinterpret_cast<::FUN_00cbc920 *>((((FUN_00cbc920_shell*)this)))->FUN_00cbc920::~FUN_00cbc920();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x40);
    return this;
}

struct Twin_0084d030
{
    float GetStoredFloatValue();
};
struct GameTimerRecord : Twin_0084d030
{
};
struct VCall190
{
    virtual void f0(float);
    virtual void f1(float);
    virtual void f2(float);
    virtual void f3(float);
    virtual void f4(float);
    virtual void f5(float);
    virtual void f6(float);
    virtual void f7(float);
    virtual void f8(float);
    virtual void f9(float);
    virtual void f10(float);
    virtual void f11(float);
    virtual void f12(float);
    virtual void f13(float);
    virtual void f14(float);
    virtual void f15(float);
    virtual void f16(float);
    virtual void f17(float);
    virtual void f18(float);
    virtual void f19(float);
    virtual void f20(float);
    virtual void f21(float);
    virtual void f22(float);
    virtual void f23(float);
    virtual void f24(float);
    virtual void f25(float);
    virtual void f26(float);
    virtual void f27(float);
    virtual void f28(float);
    virtual void f29(float);
    virtual void f30(float);
    virtual void f31(float);
    virtual void f32(float);
    virtual void f33(float);
    virtual void f34(float);
    virtual void f35(float);
    virtual void f36(float);
    virtual void f37(float);
    virtual void f38(float);
    virtual void f39(float);
    virtual void f40(float);
    virtual void f41(float);
    virtual void f42(float);
    virtual void f43(float);
    virtual void f44(float);
    virtual void f45(float);
    virtual void f46(float);
    virtual void f47(float);
    virtual void f48(float);
    virtual void f49(float);
    virtual void f50(float);
    virtual void f51(float);
    virtual void f52(float);
    virtual void f53(float);
    virtual void f54(float);
    virtual void f55(float);
    virtual void f56(float);
    virtual void f57(float);
    virtual void f58(float);
    virtual void f59(float);
    virtual void f60(float);
    virtual void f61(float);
    virtual void f62(float);
    virtual void f63(float);
    virtual void f64(float);
    virtual void f65(float);
    virtual void f66(float);
    virtual void f67(float);
    virtual void f68(float);
    virtual void f69(float);
    virtual void f70(float);
    virtual void f71(float);
    virtual void f72(float);
    virtual void f73(float);
    virtual void f74(float);
    virtual void f75(float);
    virtual void f76(float);
    virtual void f77(float);
    virtual void f78(float);
    virtual void f79(float);
    virtual void f80(float);
    virtual void f81(float);
    virtual void f82(float);
    virtual void f83(float);
    virtual void f84(float);
    virtual void f85(float);
    virtual void f86(float);
    virtual void f87(float);
    virtual void f88(float);
    virtual void f89(float);
    virtual void f90(float);
    virtual void f91(float);
    virtual void f92(float);
    virtual void f93(float);
    virtual void f94(float);
    virtual void f95(float);
    virtual void f96(float);
    virtual void f97(float);
    virtual void f98(float);
    virtual void f99(float);
    virtual void f100(float);
    virtual void f101(float);
    virtual void f102(float);
    virtual void f103(float);
    virtual void f104(float);
    virtual void f105(float);
    virtual void f106(float);
    virtual void f107(float);
    virtual void f108(float);
    virtual void f109(float);
    virtual void f110(float);
    virtual void f111(float);
    virtual void f112(float);
    virtual void f113(float);
    virtual void f114(float);
    virtual void f115(float);
    virtual void f116(float);
    virtual void f117(float);
    virtual void f118(float);
    virtual void f119(float);
    virtual void f120(float);
    virtual void f121(float);
    virtual void f122(float);
    virtual void f123(float);
    virtual void f124(float);
    virtual void f125(float);
    virtual void f126(float);
    virtual void f127(float);
    virtual void f128(float);
    virtual void f129(float);
    virtual void f130(float);
    virtual void f131(float);
    virtual void f132(float);
    virtual void f133(float);
    virtual void f134(float);
    virtual void f135(float);
    virtual void f136(float);
    virtual void f137(float);
    virtual void f138(float);
    virtual void f139(float);
    virtual void f140(float);
    virtual void f141(float);
    virtual void f142(float);
    virtual void f143(float);
    virtual void f144(float);
    virtual void f145(float);
    virtual void f146(float);
    virtual void f147(float);
    virtual void f148(float);
    virtual void f149(float);
    virtual void f150(float);
    virtual void f151(float);
    virtual void f152(float);
    virtual void f153(float);
    virtual void f154(float);
    virtual void f155(float);
    virtual void f156(float);
    virtual void f157(float);
    virtual void f158(float);
    virtual void f159(float);
    virtual void f160(float);
    virtual void f161(float);
    virtual void f162(float);
    virtual void f163(float);
    virtual void f164(float);
    virtual void f165(float);
    virtual void f166(float);
    virtual void f167(float);
    virtual void f168(float);
    virtual void f169(float);
    virtual void f170(float);
    virtual void f171(float);
    virtual void f172(float);
    virtual void f173(float);
    virtual void f174(float);
    virtual void f175(float);
    virtual void f176(float);
    virtual void f177(float);
    virtual void f178(float);
    virtual void f179(float);
    virtual void f180(float);
    virtual void f181(float);
    virtual void f182(float);
    virtual void f183(float);
    virtual void f184(float);
    virtual void f185(float);
    virtual void f186(float);
    virtual void f187(float);
    virtual void f188(float);
    virtual void f189(float);
    virtual void f190(float);
};
struct FUN_009ae580_shell : VCall190
{
    char m_auiShapeKeys[0x84];
    float m_fFirstFloatValue;
    void FUN_009ae580(float afDelta);
};
// @fnv 0x009ae580
void FUN_009ae580_shell::FUN_009ae580(float afDelta)
{
    float fdelta = ::fnv::timer::Seconds();
    f190(fdelta);
    m_fFirstFloatValue += fdelta;
}

struct BSAudio
{
};
BSAudio* __cdecl _FUN_00c85750();
struct UnkObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, int);
};
// @fnv 0x009afbe0
void __cdecl FUN_009afbe0(void* a1)
{
    if (a1 != 0)
    {
        UnkObj* v = (UnkObj*)((void *)(reinterpret_cast<::MagicCaster_shell *>((_FUN_00c85750()))->FUN_0044edb0()));
        v->f2(a1, 0x18);
    }
}

struct H00622570
{
};
struct S009afc70
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    void* FUN_009afc70(void*);
};
// Calls FUN_00622570 on a1 with true when m_navMeshPtr.FUN_00458b50() returns a value greater than 0, then returns a1.
// @fnv 0x009afc70
void* S009afc70::FUN_009afc70(void* apTarget)
{
    reinterpret_cast<::FUN_00622570_Class *>((((H00622570*)apTarget)))->FUN_00622570((intptr_t)m_navMeshPtr.FUN_00458b50() > 0);
    return apTarget;
}

class BGSRagdoll;
template <typename T> class BSSimpleList
{
  public:
    virtual void F00()
    {}
    virtual void F01()
    {}
    virtual void F02()
    {}
    virtual void F03()
    {}
    virtual void F04()
    {}
    virtual void F05()
    {}
    virtual void F06()
    {}
    virtual void F07()
    {}
    virtual void F08()
    {}
    virtual void F09()
    {}
    virtual void F10()
    {}
    virtual void F11()
    {}
    virtual void F12()
    {}
    virtual void F13()
    {}
    virtual void F14()
    {}
    virtual void F15()
    {}
    virtual void F16()
    {}
    virtual void F17()
    {}
    virtual void F18()
    {}
    virtual void F19()
    {}
    virtual void F20()
    {}
    virtual void F21(int)
    {}
};
class TESDataHandler
{
};
struct FUN_009b0d30_shell
{
    void FUN_009b0d30(int);
public:
    void FUN_00c9c1d0();
};
// @fnv 0x009b0d30
void FUN_009b0d30_shell::FUN_009b0d30(int a1)
{
    reinterpret_cast<::hkpEntityC9C *>((this))->FUN_00c9c1d0();
    ((::BSSimpleList< ::BGSRagdoll *> *)(reinterpret_cast<::FUN_009d9f40_Class *>((reinterpret_cast<TESDataHandler*>(this)))->FUN_009d9f40()))->F21(a1);
}

struct RetObj
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
    virtual bool vf37();
};
class TESActorBase;
enum ACTOR_LIFE_STATE;
enum SEX;
enum SIT_SLEEP_STATE;
class Actor
{
  public:
    bool FUN_00565690();
public:
    ::TESActorBase *GetActorBase();
public:
    bool IsSneaking();
    ::SEX GetSex();
    void FUN_00884c60();
    void SetActorLifeState(::ACTOR_LIFE_STATE);
    bool IsMoving();
    bool IsVisible(int);
    void FUN_008c00e0(::TESObjectREFR *, int, int);
    void AddDefaultSpells();
    void ConfigureActorState(bool, bool);
    void UpdateActorPresentation();
    void SetCurrentSitSleepState(::SIT_SLEEP_STATE);
    void FUN_0095e6f0(intptr_t);
};
// Returns true if _FNV_GetObjectReference() is non-null and its vf37() call returns true, otherwise false.
// @fnv 0x00565690
bool Actor::FUN_00565690()
{
    return ((::RetObj *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) ? ((::RetObj *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))->vf37() : false;
}

struct Standin77900
{
public:
    float FUN_00477900();
};
struct Setting_S
{
};
struct BGSExplosion : Standin77900
{
    char _pad[0xA0];
    float m_fSphereRadius;
    float GetScaledValue();
};
// @fnv 0x009ad5a0
float BGSExplosion::GetScaledValue()
{
    return (float)(reinterpret_cast<::FUN_00477950_shell *>(this)->HasAnyFlags(1) ? (double)m_fSphereRadius
                                  : (double)(m_fSphereRadius * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting818))))))));
}

struct FUN_009ae0f0
{
    char _pad[8];
    float m8;
    float mC;
    float m10;
    float m14;
    FUN_009ae0f0();
};
// Calls FUN_00537bb0, then sets m8 to runtimeFloatSettingDefault247 and mC, m10, m14 to 15.0f, 64.0f, 15.0f.
// @fnv 0x009ae0f0
FUN_009ae0f0::FUN_009ae0f0()
{
    reinterpret_cast<::Cl537 *>(this)->FUN_00537bb0();
    m8 = runtimeFloatSettingDefault247;
    mC = 15.0f;
    m10 = 64.0f;
    m14 = 15.0f;
}

struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
};
struct BGSLoadGameBuffer
{
};
class TESForm
{
  public:
    virtual ~TESForm();
};
class TESObjectWEAP : public TESForm
{
};
struct FUN_00825ad0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int uiFormID18;
    unsigned int uiFormID1C;
    unsigned int uiFormID20;
    FUN_00825ad0(void* apOwner);
};
struct MobileObject_9b22c0
{
    virtual ~MobileObject_9b22c0();
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
};
struct FUN_009b22c0_shell : MobileObject_9b22c0
{
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
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
    ActorCause* m_pActorCause;
    bool unkD4;
    bool m_bFlagD5;
    bool m_bFlagD6;
    bool m_bFlagD7;
    bool unkD8;
    bool unkD9;
    unsigned short unkDA;
    FUN_00825ad0* m_pEffectInstance;
    TESObjectWEAP* m_pFiringWeapon;
    int m_iValueE4;
    float unkE8[3];
    float unkF4[3];
    int unk100;
    void FUN_009b22c0(BGSLoadFormBuffer* apLoadGameBuffer);
};
struct Vec3f
{
    float x;
    float y;
    float z;
};
void* Callee0053d280(void* p);
struct FUN_005762b0_cls
{
    virtual void vf0()
    {}
    virtual void vf1()
    {}
    virtual void vf2()
    {}
    virtual void vf3()
    {}
    virtual void vf4()
    {}
    virtual void vf5()
    {}
    virtual void vf6()
    {}
    virtual void vf7()
    {}
    virtual void vf8()
    {}
    virtual void vf9()
    {}
    virtual void vf10()
    {}
    virtual void vf11()
    {}
    virtual void vf12()
    {}
    virtual void vf13()
    {}
    virtual void vf14()
    {}
    virtual void vf15()
    {}
    virtual void vf16()
    {}
    virtual void vf17()
    {}
    virtual void vf18()
    {}
    virtual void vf19()
    {}
    virtual void vf20()
    {}
    virtual void vf21()
    {}
    virtual void vf22()
    {}
    virtual void vf23()
    {}
    virtual void vf24()
    {}
    virtual void vf25()
    {}
    virtual void vf26()
    {}
    virtual void vf27()
    {}
    virtual void vf28()
    {}
    virtual void vf29()
    {}
    virtual void vf30()
    {}
    virtual void vf31()
    {}
    virtual void vf32()
    {}
    virtual void vf33()
    {}
    virtual void vf34()
    {}
    virtual void vf35()
    {}
    virtual void vf36()
    {}
    virtual void vf37()
    {}
    virtual void vf38()
    {}
    virtual void vf39()
    {}
    virtual void vf40()
    {}
    virtual void vf41()
    {}
    virtual void vf42()
    {}
    virtual void vf43()
    {}
    virtual void vf44()
    {}
    virtual void vf45()
    {}
    virtual void vf46()
    {}
    virtual void vf47()
    {}
    virtual void vf48()
    {}
    virtual void vf49()
    {}
    virtual void vf50()
    {}
    virtual void vf51()
    {}
    virtual void vf52()
    {}
    virtual void vf53()
    {}
    virtual void vf54()
    {}
    virtual void vf55()
    {}
    virtual void vf56()
    {}
    virtual void vf57()
    {}
    virtual void vf58()
    {}
    virtual void vf59()
    {}
    virtual void vf60()
    {}
    virtual void vf61()
    {}
    virtual void vf62()
    {}
    virtual void vf63()
    {}
    virtual void vf64()
    {}
    virtual void vf65()
    {}
    virtual void vf66()
    {}
    virtual void vf67()
    {}
    virtual void vf68()
    {}
    virtual void vf69()
    {}
    virtual void vf70()
    {}
    virtual void vf71()
    {}
    virtual void vf72()
    {}
    virtual void vf73()
    {}
    virtual void vf74()
    {}
    virtual void vf75()
    {}
    virtual void vf76()
    {}
    virtual void vf77()
    {}
    virtual void vf78()
    {}
    virtual void vf79()
    {}
    virtual void vf80()
    {}
    virtual void vf81()
    {}
    virtual void vf82()
    {}
    virtual void vf83()
    {}
    virtual void vf84()
    {}
    virtual void vf85()
    {}
    virtual void vf86()
    {}
    virtual void vf87()
    {}
    virtual void vf88()
    {}
    virtual void vf89()
    {}
    virtual void vf90()
    {}
    virtual void vf91()
    {}
    virtual void vf92()
    {}
    virtual void vf93()
    {}
    virtual void vf94()
    {}
    virtual void vf95()
    {}
    virtual void vf96()
    {}
    virtual void vf97()
    {}
    virtual void vf98()
    {}
    virtual void vf99()
    {}
    virtual void vf100()
    {}
    virtual void vf101()
    {}
    virtual void vf102()
    {}
    virtual void vf103()
    {}
    virtual void vf104()
    {}
    virtual void vf105()
    {}
    virtual void vf106()
    {}
    virtual void vf107()
    {}
    virtual void vf108()
    {}
    virtual void vf109()
    {}
    virtual void vf110()
    {}
    virtual void vf111()
    {}
    virtual void vf112()
    {}
    virtual void vf113()
    {}
    virtual void vf114()
    {}
    virtual void vf115()
    {}
    virtual void vf116()
    {}
    virtual void vf117()
    {}
    virtual void* vf118(unsigned int* p, Vec3f* q, void* r)
    {
        return 0;
    }
    virtual void* vf119(Vec3f* p, Vec3f* q, float f)
    {
        return 0;
    }
    virtual void vf120()
    {}
    virtual void vf121()
    {}
    virtual void vf122()
    {}
    virtual void vf123()
    {}
    virtual void vf124()
    {}
    virtual void* vf125(int a, void* p)
    {
        return 0;
    }
    int FUN_005762b0(int a1);
};
// Calls vf125 with a1 and the result of a chain of vf118/vf119 calls on local Vec3f values, then passes that to Callee00439e90, and returns a1.
// @fnv 0x005762b0
int FUN_005762b0_cls::FUN_005762b0(int a1)
{
    Vec3f a2;
    Vec3f bTmp;
    Vec3f c;
    Vec3f d;
    reinterpret_cast<::Point3Offset *>((vf125(a1, Callee0053d280(((void *)(reinterpret_cast<::Point3Offset *>((vf118((unsigned int*)&d, &bTmp, vf119(&c, &a2, ::DAT_010162c0))))->ProjectileLaunched({}, {})))))))->ProjectileLaunched({}, {});
    return a1;
}


struct FUN_009ac550_cls : Standin77900
{
    char _pad[0x8b];
    float m_8C;
    float GetEffectiveValue();
};

// Returns m_8C, or m_8C multiplied by the float setting when HasAnyFlags(1) is zero.
// @fnv 0x009ac550
float FUN_009ac550_cls::GetEffectiveValue()
{
    return (float)((reinterpret_cast<::FUN_00477950_shell *>(this)->HasAnyFlags(1) != 0) ? (double)m_8C : (double)(m_8C * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting818))))))));
}


struct Ae140Vec
{
    int unk00;
    int unk04;
    int unk08;
    Ae140Vec();
};


struct Ae140Base
{
    virtual ~Ae140Base();
    int unk04;
    int unk08;
    int unk0c;
    Ae140Base();
};

struct FUN_009ae140_cls : Ae140Base
{
    virtual ~FUN_009ae140_cls();
    int m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    Ae140Vec m_24;
    Ae140Vec m_30;
    unsigned char m_3c;

    void Setup(unsigned int aArg);
    FUN_009ae140_cls(unsigned int aArg);
};

struct VectorHolder
{
    unsigned int handle;
    void FUN_006815c0();
    VectorHolder()
    {
        FUN_006815c0();
    }
};
struct BaseObject
{
    virtual ~BaseObject();
    unsigned int unk04;
    void FUN_00621060();
    BaseObject()
    {
        FUN_00621060();
    }
};
struct FUN_009afaf0 : BaseObject
{
    VectorHolder first;
    VectorHolder second;
    VectorHolder third;
    VectorHolder fourth;
    FUN_009afaf0(unsigned int firstValue, unsigned int secondValue);
    virtual ~FUN_009afaf0();
};
// Constructs the object and initialises its four VectorHolder members with firstValue, firstValue, secondValue and 0.
// @fnv 0x009afaf0
FUN_009afaf0::FUN_009afaf0(unsigned int firstValue, unsigned int secondValue)
{
    reinterpret_cast<::FUN_00537e90 *>(&(first))->SetQuantity(firstValue);
    reinterpret_cast<::FUN_00537e90 *>(&(second))->SetQuantity(firstValue);
    reinterpret_cast<::FUN_00537e90 *>(&(third))->SetQuantity(secondValue);
    reinterpret_cast<::FUN_00537e90 *>(&(fourth))->SetQuantity(0);
}

struct FUN_009afca0_holder
{
    void InvokeCallback(void* param);
};


// @fnv 0x009afca0
void FUN_009afca0_holder::InvokeCallback(void* param)
{
    ::DAT_01268430(param, this);
}

struct EntryRecord
{
    int category;
    int unk04;
    int result;
};
struct SearchNode
{
    EntryRecord** FUN_006815c0();
    bool FUN_008256d0();
};
struct MobileObjectBase
{
    virtual ~MobileObjectBase();
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84;
};
struct SearchOwner : MobileObjectBase
{
    unsigned int unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
    SearchNode entries;
    int* FindEntryResultByCategory(intptr_t category);
};
struct Vec3
{
    float x, y, z;
    Vec3();
    Vec3 ApplyScaled(float f) const;
};
// Walks the entries node chain until a matching category is found, returning a pointer to that entry's result or null.
// @fnv 0x009b1720
int* SearchOwner::FindEntryResultByCategory(intptr_t category)
{
    int* pResult = 0;
    SearchNode* node = &entries;
    while (pResult == 0 && node != 0 && !node->FUN_008256d0())
    {
        EntryRecord* entry = *((::EntryRecord **)(((::Vec3 *)(void *)(node))));
        if (entry != 0 && entry->category == category)
            pResult = &entry->result;
        node = ((::SearchNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    return pResult;
}

class TESForm;
class TESObjectREFR : public TESForm
{
};
struct CasterData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    void* pUnk18;
    void* pUnk1C;
    TESObjectREFR* pRef20;
};
struct ExplosionBase
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
    virtual void v95();
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
    virtual void OnLinksResolved();
};
struct Explosion_9b25b0 : ExplosionBase
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
    TESObjectREFR* pRefC8;
    TESObjectREFR* pRefCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    CasterData* m_pEffectInstance;
    void FUN_009b25b0(void* apBuffer);
};

// @fnv 0x009b25b0
void Explosion_9b25b0::FUN_009b25b0(void* apBuffer)
{
    reinterpret_cast<::fnv_00932b70::FUN_00932b70_shell *>(this)->FUN_00932b70((::fnv_00932b70::BGSLoadFormBuffer *)(apBuffer));
    pRefC8 = pRefC8 ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)(uintptr_t)pRefC8)) : 0;
    pRefCC = pRefCC ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)(uintptr_t)pRefCC)) : 0;
    if (m_pEffectInstance)
    {
        m_pEffectInstance->pUnk18 = m_pEffectInstance->pUnk18 ? ((void *)(::MagicItem::GetMagicItemByID((unsigned int)(uintptr_t)(m_pEffectInstance->pUnk18)))) : 0;
        m_pEffectInstance->pUnk1C = m_pEffectInstance->pUnk1C ? ((void *)(::MagicTarget::GetMagicTargetByID((uintptr_t)(m_pEffectInstance->pUnk1C)))) : 0;
        m_pEffectInstance->pRef20 =
            m_pEffectInstance->pRef20 ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)(uintptr_t)m_pEffectInstance->pRef20)) : 0;
    }
    if (((bool)(reinterpret_cast<::BSOcclusionPlane *>(this)->IsNotCulled())))
        OnLinksResolved();
}

struct GlobalObject_00633c90
{
    GlobalObject_00633c90(intptr_t v);
    ~GlobalObject_00633c90();
    int m_ptr;
    GlobalObject_00633c90& operator=(void* p);
};
struct GlobalObject_0096a2d0
{
    GlobalObject_0096a2d0();
    ~GlobalObject_0096a2d0();
    int m_item;
    int m_next;
};
struct GlobalObject_0041a250
{
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    int m_00;
    int m_04;
    int m_08;
};
struct GlobalObject_0042f730
{
    GlobalObject_0042f730(void* p);
    ~GlobalObject_0042f730();
    int m_ptr;
};
struct GlobalObject_006815c0
{
    GlobalObject_006815c0();
    float x;
    float y;
    float z;
};

struct Base1_9abf30
{
    virtual ~Base1_9abf30();
    virtual void bvtbl00();
    int bf04;
    int bf08;
    int bf0c;
    int bf10;
    int bf14;
};
struct Base2_9abf30
{
    virtual void wvtbl00();
};

struct FUN_0092eb50 : Base1_9abf30, Base2_9abf30
{
    FUN_0092eb50();
    virtual ~FUN_0092eb50();
};

struct FUN_009abf30 : FUN_0092eb50
{
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
    float m_88;
    float m_8c;
    float m_90;
    float m_94;
    float m_98;
    float m_9c;
    GlobalObject_00633c90 m_a0;
    GlobalObject_0096a2d0 m_a4;
    GlobalObject_0041a250 m_ac;
    GlobalObject_0041a250 m_b8;
    GlobalObject_00633c90 m_c4;
    int m_c8;
    int m_cc;
    GlobalObject_0042f730 m_d0;
    unsigned char m_d4;
    unsigned char m_d5;
    unsigned char m_d6;
    unsigned char m_d7;
    unsigned char m_d8;
    unsigned char m_d9;
    unsigned char m_da;
    unsigned char m_db;
    int m_dc;
    int m_e0;
    int m_e4;
    GlobalObject_006815c0 m_e8;
    GlobalObject_006815c0 m_f4;
    float m_100;
    FUN_009abf30();
    virtual ~FUN_009abf30();
};

namespace fnv_009ac200 {
struct PrimaryC
{
    virtual ~PrimaryC();
    int u04, u08, u0c, u10, u14;
};
struct SecondaryC
{
    virtual ~SecondaryC();
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
};
struct MobileC : PrimaryC, SecondaryC
{
    MobileC();
    virtual ~MobileC();
};
struct MatrixC
{
    float a, b, c, d, e, f, g, h, i;
};
struct ExplosionFormC
{
};
struct SmartC
{
    void* ptr;
    SmartC(void*);
    ~SmartC();
    SmartC& operator=(void*);
};
struct ListC
{
    void* head;
    void* next;
    ListC();
    ~ListC();
};
struct TripleC
{
    int a, b, c;
    TripleC();
    ~TripleC();
};
struct CauseC
{
    void* ptr;
    CauseC(void*);
    ~CauseC();
    CauseC& operator=(void*);
};
struct PointC
{
    float x, y, z;
    PointC();
};
struct OwnerC
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual bool IsSpecial();
};
extern PointC NiPoint3_ZERO;
struct FUN_009ac200 : MobileC
{
    float age, lifetime, timer, radius, force, scale;
    SmartC object;
    ListC list;
    TripleC first, second;
    SmartC another;
    OwnerC* owner;
    int unkCC;
    CauseC cause;
    bool flagD4, flagD5, flagD6, flagD7, flagD8, flagD9;
    short unkDA;
    FUN_00825ad0* caster;
    void* weapon;
    int frames;
    PointC position, velocity;
    float finalValue;
    virtual ~FUN_009ac200();
    FUN_009ac200(void*, OwnerC*, void*, Vec3f, MatrixC);
};
// @fnv 0x009ac200
FUN_009ac200::FUN_009ac200(void* form, OwnerC* source, void* parent, Vec3f location, MatrixC rotation)
    : object(0), another(0), cause(0)
{
    u68 = 0;
    owner = source;
    reinterpret_cast<::B930700Actor *>(this)->SetParentCellAndUpdateController((::B930700Cell *)(parent));
    reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)&(location));
    reinterpret_cast<::fnv_0056fa90::Holder *>(this)->FUN_0056fa90((*(float *)&(const ::fnv_009ac200::MatrixC &)(rotation)), {}, {}, {}, {}, {}, {}, {}, {});
    flagD8 = false;
    if (form)
    {
        reinterpret_cast<::Fn575690 *>(this)->FUN_00575690(form);
        radius = reinterpret_cast<::Standin77900 *>((((::fnv_009ac200::ExplosionFormC *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_00477900();
        force = reinterpret_cast<::FUN_009ac550_cls *>((((::fnv_009ac200::ExplosionFormC *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetEffectiveValue();
        flagD8 = reinterpret_cast<::FUN_00477950_shell *>((((::fnv_009ac200::ExplosionFormC *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->HasAnyFlags(64);
        if (reinterpret_cast<::FUN_00477950_shell *>((((::fnv_009ac200::ExplosionFormC *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->HasAnyFlags(2))
            reinterpret_cast<::fnv_0056fa90::Holder *>(this)->FUN_0056fa90((*(float *)&(const ::fnv_009ac200::MatrixC &)((*reinterpret_cast<::fnv_009ac200::MatrixC *>(&::DAT_011a9448)))), {}, {}, {}, {}, {}, {}, {}, {});
    }
    frames = 0;
    lifetime = ::DAT_01017718;
    timer = 0.0f;
    age = 0.0f;
    scale = 1.0f;
    object = 0;
    another = 0;
    cause = 0;
    weapon = 0;
    flagD4 = false;
    flagD5 = false;
    flagD6 = false;
    flagD7 = false;
    flagD9 = false;
    caster = source && source->IsSpecial() ? 0 : new FUN_00825ad0(this);
    position = NiPoint3_ZERO;
    velocity = NiPoint3_ZERO;
    finalValue = ::DAT_01012054;
}
}  // namespace fnv_009ac200

// When the reference's 3D is loaded, run a world update on its root node with the current time.


class B17A0UpdateData
{
  public:
    B17A0UpdateData(float fTime, bool m_bUpdateEnabled, bool bIsMultiThreaded);

    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
};

class B17A0Node
{
  public:
};

class B17A0Ref
{
  public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00C();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01C();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02C();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03C();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04C();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05C();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06C();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07C();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08C();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09C();
    virtual void Unk0A0();
    virtual void Unk0A4();
    virtual void Unk0A8();
    virtual void Unk0AC();
    virtual void Unk0B0();
    virtual void Unk0B4();
    virtual void Unk0B8();
    virtual void Unk0BC();
    virtual void Unk0C0();
    virtual void Unk0C4();
    virtual void Unk0C8();
    virtual void Unk0CC();
    virtual void Unk0D0();
    virtual void Unk0D4();
    virtual void Unk0D8();
    virtual void Unk0DC();
    virtual void Unk0E0();
    virtual void Unk0E4();
    virtual void Unk0E8();
    virtual void Unk0EC();
    virtual void Unk0F0();
    virtual void Unk0F4();
    virtual void Unk0F8();
    virtual void Unk0FC();
    virtual void Unk100();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10C();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void Unk11C();
    virtual void Unk120();
    virtual void Unk124();
    virtual void Unk128();
    virtual void Unk12C();
    virtual void Unk130();
    virtual void Unk134();
    virtual void Unk138();
    virtual void Unk13C();
    virtual void Unk140();
    virtual void Unk144();
    virtual void Unk148();
    virtual void Unk14C();
    virtual void Unk150();
    virtual void Unk154();
    virtual void Unk158();
    virtual void Unk15C();
    virtual void Unk160();
    virtual void Unk164();
    virtual void Unk168();
    virtual void Unk16C();
    virtual void Unk170();
    virtual void Unk174();
    virtual void Unk178();
    virtual void Unk17C();
    virtual void Unk180();
    virtual void Unk184();
    virtual void Unk188();
    virtual void Unk18C();
    virtual void Unk190();
    virtual void Unk194();
    virtual void Unk198();
    virtual void Unk19C();
    virtual void Unk1A0();
    virtual void Unk1A4();
    virtual void Unk1A8();
    virtual void Unk1AC();
    virtual void Unk1B0();
    virtual void Unk1B4();
    virtual void Unk1B8();
    virtual void Unk1BC();
    virtual void Unk1C0();
    virtual void Unk1C4();
    virtual void Unk1C8();
    virtual void Unk1CC();
    virtual B17A0Node* Get3D();

    void Update3D(int iUnused);
};

// If the 3D is loaded and present, builds update data from the current time and updates the 3D node.
// @fnv 0x009b17a0
void B17A0Ref::Update3D(int iUnused)
{
    if (((bool)(reinterpret_cast<::BSOcclusionPlane *>(this)->IsNotCulled())) && Get3D())
    {
        B17A0UpdateData kData(::fnv_00563f30::DAT_011c3c08, true, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((Get3D()))->FUN_00a59c60((std::intptr_t)&(kData));
    }
}

// FUN_009b2790 v01 - worker7 data round
struct BGSLoadFormBuffer;

class MobileObject
{
  public:
    virtual void Revert(BGSLoadFormBuffer* apBuffer);
};

struct AC_0042f730;
struct Holder0042f780
{
    int m_00;
    Holder0042f780* FUN_0042f780(AC_0042f730* p);
};
// @fnv 0x009ac170
void FUN_009ac170_shell::FUN_009ac170(ActorCause* apActorCause)
{
    reinterpret_cast<::Holder0042f780 *>((void *)&(const ::NiPointer &)(m_actorCause))->FUN_0042f780((::AC_0042f730 *)(apActorCause));
}
// @fnv 0x009b22c0
void FUN_009b22c0_shell::FUN_009b22c0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::fnv_00932a00::FUN_00932a00_t *>(this)->FUN_00932a00((::fnv_00932a00::BGSLoadFormBuffer *)(apLoadGameBuffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk88), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk8C), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk94), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk98), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unkD4), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_iValueE4), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk90), 4);
    if (apLoadGameBuffer->GetVersion() >= 0xe)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk9C), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unkD8), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unkD9), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(unkE8), 0xc);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(unkF4), 0xc);
    }
    if (apLoadGameBuffer->GetVersion() >= 0x14)
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk100), 4);
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&unkC8));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&unkCC));
    m_pFiringWeapon =
        dynamic_cast<TESObjectWEAP*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((((BGSLoadGameBuffer*)apLoadGameBuffer)))->FUN_008648a0()));
    int iactorCauseID = -1;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iactorCauseID), 4);
    reinterpret_cast<::Holder0042f780 *>((void *)&(const ::NiPointer &)(reinterpret_cast<NiPointer&>(m_pActorCause)))->FUN_0042f780((::AC_0042f730 *)(::ActorCause *)(((::ActorCause *)(::FindStateByValue(iactorCauseID)))));
    bool bhasCaster = true;
    if (apLoadGameBuffer->GetVersion() >= 7)
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bhasCaster), 1);
    if (bhasCaster)
    {
        if (!m_pEffectInstance)
            m_pEffectInstance = new FUN_00825ad0(this);
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&m_pEffectInstance->uiFormID18));
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&m_pEffectInstance->uiFormID1C));
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&m_pEffectInstance->uiFormID20));
    }
    if (m_iValueE4 > 0)
    {
        m_bFlagD5 = true;
        m_bFlagD6 = true;
        m_bFlagD7 = true;
    }
}

struct HeadW7
{
};

struct ListW7
{
    int m_00;
    bool _ref_008256d0();
    void _ref_0063f7b0();
};

struct Vec3W7
{
    float x;
    float y;
    float z;
};

struct OwnerW7 : MobileObject
{
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    int f58;
    int f5C;
    int f60;
    int f64;
    int f68;
    int f6C;
    int f70;
    int f74;
    int f78;
    int f7C;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    float m_9c;
    int fA0;
    ListW7 m_kNode;
    int fA8;
    int fAC;
    int fB0;
    int fB4;
    int fB8;
    int fBC;
    int fC0;
    int fC4;
    int fC8;
    int fCC;
    Holder0042f780 m_cause;
    char m_d4;
    char m_d5;
    char m_d6;
    char m_d7;
    char m_d8;
    char m_d9;
    char fDA;
    char fDB;
    int fDC;
    int fE0;
    int fE4;
    Vec3W7 m_e8;
    Vec3W7 m_f4;

    void FUN_009b2790(BGSLoadFormBuffer* apBuffer);
};

struct FUN_00438fc0_file;
struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
public:
    bool FUN_004390c0(const ::NiPoint3 &);
    float GetLengthSquared();
public:
    unsigned char ReadFromFile(::FUN_00438fc0_file *);
    ::NiPoint3 &Subtract(const ::NiPoint3 &);
    ::NiPoint3 Cross(const ::NiPoint3 &) const;
    ::NiPoint3 CrossProduct(const ::NiPoint3 &) const;
    ::NiPoint3 *ScaleTo(::NiPoint3 *, float);
    char *FUN_00a59af0(const char *);
    ::NiPoint3 &FUN_00b2a1c0(const ::NiPoint3 &);
};
// Initialises the object's fields to defaults, calls Setup with aArg, and increments g_ae140Count.
// @fnv 0x009ae140
FUN_009ae140_cls::FUN_009ae140_cls(unsigned int aArg)
{
    m_10 = 0;
    m_14 = 0.0f;
    m_18 = 0.0f;
    m_1c = 0.0f;
    m_20 = 0.0f;
    m_24 = (*reinterpret_cast<::Ae140Vec *>((void *)&::NiPoint3::ZERO));
    m_30 = (*reinterpret_cast<::Ae140Vec *>((void *)&::NiPoint3::ZERO));
    m_3c = 1;
    Setup(aArg);
    ++::DAT_0126841c;
}
// @fnv 0x009abf30
FUN_009abf30::FUN_009abf30() : m_a0(0), m_c4(0), m_d0(0)
{
    m_68 = 0;
    m_e4 = 0;
    m_88 = 0.0f;
    m_8c = 0.0f;
    m_90 = 0.0f;
    m_94 = 0.0f;
    m_98 = 0.0f;
    m_9c = 1.0f;
    m_a0 = 0;
    m_c4 = 0;
    reinterpret_cast<::Holder0042f780 *>(&(m_d0))->FUN_0042f780((::AC_0042f730 *)(void *)(0));
    m_c8 = 0;
    m_cc = 0;
    m_e0 = 0;
    m_d4 = 0;
    m_d5 = 0;
    m_d6 = 0;
    m_d7 = 0;
    m_d8 = 0;
    m_d9 = 0;
    m_dc = 0;
    m_e8 = *(GlobalObject_006815c0*)&(*reinterpret_cast<::Vec3f *>((void *)&::NiPoint3::ZERO));
    m_f4 = *(GlobalObject_006815c0*)&(*reinterpret_cast<::Vec3f *>((void *)&::NiPoint3::ZERO));
    m_100 = -1.0f;
}
// @fnv 0x009b2790
void OwnerW7::FUN_009b2790(BGSLoadFormBuffer* apBuffer)
{
    MobileObject::Revert(apBuffer);
    m_d4 = 0;
    m_d5 = 0;
    m_d6 = 0;
    m_d7 = 0;
    m_cause.FUN_0042f780(0);
    m_9c = 1.0f;
    m_d8 = 0;
    m_d9 = 0;
    m_e8 = (*reinterpret_cast<::Vec3W7 *>((void *)&::NiPoint3::ZERO));
    m_f4 = (*reinterpret_cast<::Vec3W7 *>((void *)&::NiPoint3::ZERO));
    while (!m_kNode._ref_008256d0())
    {
        HeadW7* head = *((::HeadW7 **)(((::Vec3 *)(void *)&(m_kNode))));
        HeadW7* toFree = head;
        toFree ? reinterpret_cast<::FUN_009ac910_shell *>((toFree))->FUN_009ac910(1) : 0;
        m_kNode._ref_0063f7b0();
    }
}
struct MatrixWater
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    MatrixWater();
};
using ::AutoMemContext;
struct SaveX
{
};
class HighProcess
{
  public:
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
    HighProcess();
};
struct SceneX
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SceneX* AsNode();
    virtual SceneX* AsFade();
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
    virtual void Attach(SceneX*, bool);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
};
struct IdFlagState
{
    int id, flags, state;
    IdFlagState();
    ~IdFlagState();
    void operator=(const IdFlagState&);
};
struct AudioX
{
    IdFlagState FUN_00ad7550(const char*, unsigned);
};
struct SettingX
{
    unsigned char* FUN_00408d60();
};
extern SettingX DAT_011c7ae8;
struct RefX;
struct BaseX
{
};
struct CellX
{
};
struct ActorProcX
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void React(RefX*, NiPoint3, int*, int, unsigned);
};
struct ActorX
{
public:
    void FUN_009b1090();
};
struct ActorPtrX
{
};
struct RefX
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
    virtual void SetFlags(unsigned);
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
    virtual ActorPtrX* GetActor();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
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
    virtual void Initialize();
    virtual void v114();
    virtual void v115();
    virtual SceneX* GetScene();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const NiPoint3& GetPosition();
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
    HighProcess* process;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    float animationTime;
    float radius;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    IdFlagState soundAC;
    IdFlagState soundB8;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    bool disabled;

    void UpdateExplosion();
};
struct ExtraX
{
};
struct HandlerX
{
};
struct ProcessListsX
{
};
struct ListX
{
};
extern ListX DAT_011c7b8c;
struct TesX
{
};
#include "fnv/image_space_effect_param.h"
void FUN_00689210(CellX*, float, const char*, MatrixWater, NiPoint3, float, int, int);
struct Obj;
struct P1;
struct P2Vtbl;
struct Node;
struct This
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
    float f8c;
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
    virtual void v95();
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
    virtual void W1c8(int a);
    virtual void v115();
    virtual Obj* W1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* W1f4();
    void FUN_009ad670();
public:
    void FUN_009cc510();
    float FUN_00b12720(const ::NiPoint3 &);
    void InitShaderParams();
    void FUN_00c84e20(unsigned int *);
    void FUN_00ca4e50(intptr_t, intptr_t);
    void FUN_00dba690();
    void FUN_00de59f0(::P1 *, ::P2Vtbl *, int, int);
    void PushFront(::Node *volatile);
};
// Updates an explosion reference: scales by distance, spawns effects, updates cell membership, reacts actors, plays splash sounds and applies image-space effects.
// @fnv 0x009acd60
void RefX::UpdateExplosion()
{
    AutoMemContext memory3(49, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\Combat\\Explosion.cpp", 376);
    bool loading4 = reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::SaveX * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10();
    bool newProcess2 = (bool)(unsigned char)(process == 0);
    if (newProcess2)
        process = new HighProcess;
    float distance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3 &)(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))->GetPosition() - GetPosition())))->ComputeMagnitude();
    float scaled = ComputeSquaredRatioComplement(reinterpret_cast<::FUN_00644930_shell *>(this)->FUN_00644930(), distance);
    if (scaled > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting1030)))))) && !disabled)
        ::ImageSpaceModifierInstanceForm::Trigger((::TESImageSpaceModifier *)(void *)(((void *)(::FUN_009ad630()))), 1.0f, (::NiAVObject *)(::SceneX *)(0));
    reinterpret_cast<::fnv_009b2940::WaterActor *>(this)->FUN_009b2940();
    reinterpret_cast<::This *>(this)->FUN_009ad670();
    if (((bool)(reinterpret_cast<::BSOcclusionPlane *>(this)->IsNotCulled())))
        reinterpret_cast<::FUN_009acd00_Class *>(this)->FUN_009acd00();
    else
    {
        if (!loading4 && ((void *)(reinterpret_cast<::FUN_004fd380_shell *>((((::BaseX *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_004fd380())))
            reinterpret_cast<::HandlerView *>(((*reinterpret_cast<::HandlerX * *>(&::g_dataHandler))))->PlaceObjectReference((::TESBoundObject *)(void *)(((void *)(reinterpret_cast<::FUN_004fd380_shell *>((((::BaseX *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_004fd380()))), (::NiPoint3 *)&(GetPosition()), (::NiPoint3 *)&((*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>(this)->GetData()))),
                                               (::TESObjectCELL *)(::CellX *)(((::CellX *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))), (::TESWorldSpace *)(void *)(((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(this)->FUN_00575d70()))), (::TESObjectREFR *)(0), (const char *)(0), (::TESForm *)(0));
        if (!loading4 && reinterpret_cast<::BGSExplosion *>((((::BaseX *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetScaledValue() > 0.0 && reinterpret_cast<::FUN_008d01e0_Class *>((((::BaseX *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_008d01e0() > 0.0)
        {
            reinterpret_cast<::S_009b13a0_Cls *>(this)->FUN_009b13a0();
            reinterpret_cast<::FUN_00422220_shell *>((((::ExtraX *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00422220(reinterpret_cast<::BGSExplosion *>((((::BaseX *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->GetScaledValue());
            SetFlags(0x40000000);
        }
        reinterpret_cast<::FUN_009b1260_Class *>(this)->UpdateCastSound();
        Initialize();
        CellX* cell = ((::CellX *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
        if (cell)
        {
            if (!loading4)
                reinterpret_cast<::fnv_0054ca90::Cell *>((cell))->FUN_0054ca90((::fnv_0054ca90::Ref *)(::RefX *)(this));
            reinterpret_cast<::CellView *>((cell))->FUN_00548230((::RefView *)(::RefX *)(this), false);
        }
        SceneX* sceneB = GetScene();
        if (sceneB)
            reinterpret_cast<::TaskQueueInterface *>((sceneB))->QueueActorDisarm(scaled > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting1030)))))) && !disabled);
        if (sceneB && ((::SceneX *)(reinterpret_cast<::TESObjectCELL *>((cell))->GetDynamicNode())))
            ((::SceneX *)(reinterpret_cast<::TESObjectCELL *>((cell))->GetDynamicNode()))->Attach(sceneB, true);
        SceneX* node7 = sceneB ? sceneB->AsNode() : 0;
        SceneX* fade9 = node7 ? node7->AsFade() : 0;
        if (fade9)
            ::FUN_00476ab0((::BSFadeNode_Dummy *)(fade9));
        animationTime = ::GetAnimValueByPrefix((::NiObj6220 *)(sceneB), "SpecialIdle_AreaEffect", "Hit");
    }
    if (!loading4)
    {
        ActorPtrX* actorPointer = GetActor();
        if (actorPointer && ((::ActorX *)(::FUN_00559450((int *)(actorPointer)))) && ((::ActorProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((::ActorX *)(::FUN_00559450((int *)(actorPointer))))))->GetBaseTexture())))
        {
            ActorX* actor = ((::ActorX *)(::FUN_00559450((int *)(actorPointer))));
            ((::ActorProcX *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->React((RefX*)actor, GetPosition(), reinterpret_cast<::FUN_004fb810_shell *>((((::BaseX *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_004fb810(), 2,
                                         reinterpret_cast<::BSFadeNode *>(this)->FUN_009ad610());
        }
        reinterpret_cast<::ActorX *>(this)->FUN_009b1090();
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(soundAC))->IsValid() || reinterpret_cast<::SoundPlaybackHandle *>(&(soundB8))->IsValid())
            ::UpdateDistanceFade(radius * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::originalRuntimeFloatSetting1068)))))), GetPosition());
        if (((::CellX *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && reinterpret_cast<::FUN_004fb970_class *>(this)->GetByteAtOffsetD9())
        {
            NiPoint3 position8 = GetPosition();
            position8.z = reinterpret_cast<::FUN_005471e0_shell *>((((::CellX *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_005471e0();
            float size_2 = reinterpret_cast<::FUN_00644930_shell *>(this)->FUN_00644930() / *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingX *>(&::g_011d0da4))))));
            MatrixWater rotationA;
            reinterpret_cast<::FUN_004a0c90_shell *>(&(rotationA))->FUN_004a0c90(((float)(::FUN_004a4240())));
            FUN_00689210(((::CellX *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::RefX * *>(&::_g_thePlayer))))->GetTarget())), 1.0f, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingX *>(&::g_011d0ce4))))->GetMenuTitle())), rotationA, position8, size_2,
                         7, 0);
            IdFlagState sound;
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::IdFlagState &)(sound))->operator=((const ::SoundPlaybackHandle &)((const ::IdFlagState &)(((::AudioX *)(::FUN_00453a70()))->FUN_00ad7550("CWaterExplosionSplash", 0x102))));
            if (reinterpret_cast<::SoundPlaybackHandle *>(&(sound))->IsValid())
            {
                reinterpret_cast<::FUN_00ad8b60_h *>(&(sound))->FUN_00ad8b60(position8.x, position8.y, position8.z);
                reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(false);
            }
        }
    }
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingX *>(&::g_011d0a78)))))) > 0)
    {
        ImageSpaceEffectParam params(1.0f, 1.0f, 1.0f, 0.65f);
        SceneX* effect2 = ((::SceneX *)(::CreateOctahedron(2.5f, (const struct ::FUN_004a7800 *)(const ::ImageSpaceEffectParam *)(&params), 1)));
        reinterpret_cast<::FUN_00a5a040_Class *>((effect2))->FUN_00a5a040();
        reinterpret_cast<::FUN_00440460_S *>((effect2))->FUN_00440460((const ::V3 *)&(GetPosition()));
        reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::TesX * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(effect2), 10.0f);
    }
    if (newProcess2)
        reinterpret_cast<::Host096d450 *>(&((*reinterpret_cast<::ProcessListsX *>(&::g_011e0e80))))->FUN_0096d450((::MobileObject *)(::RefX *)(this), 0, false, 0, (::MobileObject *)(false));
    if (*DAT_011c7ae8.FUN_00408d60())
    {
        reinterpret_cast<::ScriptList *>(&(DAT_011c7b8c))->FUN_0076b660((unsigned int *)&(const ::RefX *const &)(this));
    }
}

struct DRNode;

struct DRObject3D
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual DRNode* GetAsNode();
};

struct DRController
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
    virtual void Stop();
};

template <class T> struct DRPointer
{
    T* m_pObject;

    ~DRPointer();
    operator T*() const;
    T* operator->() const;
    DRPointer& operator=(T* apObject);
};

struct DRItem
{
    ~DRItem();
};

struct DRItemList
{
    DRItem* pItem;
    DRItemList* pNext2;

    ~DRItemList();
    bool IsEmpty();
    void RemoveHead();
};

struct DRSoundHandle
{
    int unk00;
    int unk04;
    int unk08;

    ~DRSoundHandle();
};

struct DRCause;

struct DRCauseHolder
{
    DRCause* pCause;

    ~DRCauseHolder();
    DRCauseHolder& operator=(DRCause* apCause);
};

struct DRDeletable
{
    virtual ~DRDeletable();
};

struct DRPortalGraph
{
};

struct DRWorld
{
};

struct DRCell
{
};

struct DRDataHandler
{
};

struct DRSetting
{
    unsigned char* Bool();
};

struct DRRefList
{
    struct DRRef* RemovePos(void*& arpPos);
};


extern DRSetting g_kDRSetting;
extern DRRefList g_kDRRefList;

struct DRRefPrimary
{
    virtual ~DRRefPrimary();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct DRRefSecondary
{
    virtual void v00();
};

struct DRRef : DRRefPrimary, DRRefSecondary
{
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
    ~DRRef();
};

struct FUN_009ac5a0 : DRRef
{
    DRPointer<DRController> spController;
    DRItemList kItems;
    DRSoundHandle kSound1;
    DRSoundHandle kSound2;
    DRPointer<DRController> m_pController;
    int unkC8;
    int unkCC;
    DRCauseHolder kCause;
    int unkD4;
    int unkD8;
    DRDeletable* pOwned;

    virtual ~FUN_009ac5a0();
};
// Runs the Explosion destructor and, when flags has bit 0 set, deallocates this; returns this.
// @fnv 0x009ac1d0
void* Explosion::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_009ac5a0 *>(this)->FUN_009ac5a0::~FUN_009ac5a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x009ac5a0
FUN_009ac5a0::~FUN_009ac5a0()
{
    if (((::DRObject3D *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())) && ((::DRObject3D *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()))->GetAsNode() && ::FUN_005784b0((::NiNode *)(::DRNode *)(((::DRObject3D *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()))->GetAsNode())))
        ::fnv_00578170::FUN_00578170((::NiNode *)(::DRNode *)(((::DRObject3D *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()))->GetAsNode()));
    if (((::DRCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && ((::DRWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::DRCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())) && ((::DRCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())))
        ::FUN_00c69ee0((::NiAVObject *)(((::DRWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::DRCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()))), (bool)(((::DRObject3D *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()))), true);
    if (0)
    {
    }
    reinterpret_cast<::FUN_009b12d0_Class *>(this)->FUN_009b12d0();
    if (spController)
        spController->Stop();
    spController = 0;
    while (!kItems.IsEmpty())
    {
        delete *((::DRItem **)(((::Vec3 *)(void *)&(kItems))));
        kItems.RemoveHead();
    }
    if (!reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::DRDataHandler * *>(&::g_dataHandler))))->FUN_004226e0())
        reinterpret_cast<::fnv_0092ed60::FNVCurrent *>(this)->FUN_0092ed60(false);
    reinterpret_cast<::Owner009b11c0 *>(this)->FUN_009b11c0();
    reinterpret_cast<::Holder0042f780 *>((void *)&(const ::DRCauseHolder &)(kCause))->FUN_0042f780((::AC_0042f730 *)(::DRCause *)(0));
    if (pOwned)
        delete pOwned;
    if (*g_kDRSetting.Bool())
    {
        void* pPos7 = ((void *)(::FUN_00559450((int *)&(g_kDRRefList))));
        void* pNext2 = 0;
        void* pFound = 0;
        bool bFound = false;
        while (pPos7 && !bFound)
        {
            pNext2 = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(&(g_kDRRefList))->DereferenceIfNotNull((int **)(pPos7))));
            if (pPos7)
            {
                DRRef* pRef = ((::DRRef *)(reinterpret_cast<::FUN_006317a0_struct *>(&(g_kDRRefList))->AddEight((intptr_t)(pPos7))));
                if (pRef == this)
                {
                    bFound = true;
                    pFound = pPos7;
                }
                pPos7 = pNext2;
            }
        }
        g_kDRRefList.RemovePos(pFound);
    }
    DRObject3D* p3D = ((::DRObject3D *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()));
    DRCell* pCell4 = ((::DRCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
    if (pCell4)
    {
        DRPortalGraph* pGraph = ((::DRPortalGraph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((pCell4))->FUN_009d9f20()));
        if (pGraph)
            reinterpret_cast<::fnv_00c5b370::ItemQueue *>((pGraph))->FUN_00c5b370((::fnv_00c5b370::RefObject *)(p3D));
    }
}

struct BGSSaveFormBuffer
{
  public:
};
class SavedActorCause
{
  public:
};
class SavedActorCausePointer
{
  public:
    SavedActorCause* object;
};
class CasterReference
{
  public:
};
class CasterSource
{
  public:
    unsigned int RefreshItem();
};
class ExplosionCasterData
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    CasterReference* reference;
    CasterSource* source;
    void* weapon;
};
class ExplosionSave
{
  public:
    virtual ~ExplosionSave();
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
    int unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    void* unkC8;
    void* unkCC;
    SavedActorCausePointer actorCause;
    bool unkD4, unkD5, unkD6, unkD7, unkD8, unkD9;
    unsigned short unkDA;
    ExplosionCasterData* caster;
    void* weapon;
    int frameCount;
    Vec3f pointE8, pointF4;
    int unk100;
    void WriteToSaveBuffer(BGSSaveFormBuffer*);
};
// Writes explosion save fields, actor cause ID, and optional caster data to the save buffer.
// @fnv 0x009b2040
void ExplosionSave::WriteToSaveBuffer(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00932880::FUN_00932880_shell *>(this)->FUN_00932880((::fnv_00932880::BGSSaveFormBuffer *)(buffer));
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk88, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk8C, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk94, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk98, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unkD4, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&frameCount, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk90, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk9C, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unkD8, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unkD9, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&pointE8, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&pointF4, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk100, 4, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(unkC8), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(unkCC), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(weapon), 0);
    unsigned int causeID = ((::SavedActorCause *)(::FUN_00559450((int *)&(actorCause)))) ? reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((::SavedActorCause *)(::FUN_00559450((int *)&(actorCause))))))->FUN_00825c00() : -1;
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&causeID, 4, 0);
    bool casterPresent = caster;
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&casterPresent, 1, 0);
    if (casterPresent)
    {
        reinterpret_cast<::FUN_00865db0_shell *>((buffer))->FUN_00865db0(caster->reference ? ((unsigned int)(reinterpret_cast<::FUN_0040a1e0_shell *>((caster->reference))->FUN_0040a1e0())) : 0, 0);
        reinterpret_cast<::FUN_00865db0_shell *>((buffer))->FUN_00865db0(caster->source ? caster->source->RefreshItem() : 0, 0);
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(caster->weapon), 0);
    }
}

struct Base1
{
    int unk00;
};
struct Base2
{
    int unk04;
};
struct FUN_0057c400_shell
{
};
struct FUN_00576870_cls
{
    int unk00;
    FUN_0057c400_shell m_sub;
    Base1* FUN_00576870(intptr_t a);
};
struct Derived : Base1, Base2
{
};

// Calls m_sub.FUN_0057c400(a) and returns the result cast to Derived*.
// @fnv 0x00576870
Base1* FUN_00576870_cls::FUN_00576870(intptr_t a)
{
    return static_cast<Derived*>(((::Base2 *)(reinterpret_cast<::Holder0057c400 *>(&(m_sub))->FUN_0057c400(a))));
}

void __cdecl FUN_009afbe0(void* a1);

struct MemoryManager
{
};

struct Node00cbd500
{
    int unk00;
    int unk04;
    int unk08;
};

// @fnv 0x00cbd500
void FUN_00cbd500(Node00cbd500* p)
{
    p->unk08 = 0;
    reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(p);
}
extern "C" void _ReadWriteBarrier(void);

struct LiquidVec
{

    float x, y, z;

    bool FUN_004390c0(const LiquidVec&);


    bool operator==(LiquidVec v) const
    {
        return x == v.x && y == v.y && z == v.z;
    }

    LiquidVec& operator+=(const LiquidVec& v)
    {
        x = (x + v.x);
        y = (y + v.y);
        z = (z + v.z);
        return *this;
    }

    LiquidVec& operator-=(const LiquidVec& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    LiquidVec& operator*=(const float& s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    LiquidVec operator*(const float& s) const
    {
        LiquidVec r = {x * s, y * s, z * s};
        return r;
    }

    float LengthSq() const
    {
        return x * x + y * y + z * z;
    }

    float Dot(LiquidVec v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
};


struct LiquidVecOf : LiquidVec
{

    LiquidVecOf(__m128 v)
    {
        _mm_store_ss(&x, v);
        _mm_store_ss(&y, _mm_shuffle_ps(v, v, 0x55));
        _mm_store_ss(&z, _mm_shuffle_ps(v, v, 0xaa));
    }
};

struct LiquidFour
{

    __m128 value;

    LiquidFour()
    {}

    LiquidFour(const LiquidFour& v)
    {
        value = v.value;
    }

    LiquidFour& operator=(const LiquidFour& v)
    {
        value = v.value;
        return *this;
    }

    void Set4(float a, float b, float c, float d)
    {
        value = _mm_set_ps(a, b, c, d);
    }

    void Mul(float s)
    {
        value = _mm_mul_ps(_mm_set1_ps(s), value);
    }

    void MulD(double s)
    {
        value = _mm_mul_ps(_mm_set1_ps((float)s), value);
    }
};

struct LiquidContact
{
    LiquidFour position, normal;
    float NormalZ() const
    {
        return normal.value[2];
    }
};

struct LiquidTransform
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};

struct LiquidTarget
{

    unsigned unk0;

    unsigned unk4;

    unsigned unk8;

    unsigned unkc;

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

    LiquidTransform rotation;
};

struct LiquidBody;

struct LiquidLink
{
    unsigned unk00, unk04, unk08;
    LiquidBody* body;
};

struct LiquidOwner
{
    uintptr_t unk00, unk04, unk08, unk0c, unk10, unk14;
    LiquidLink* link;
    unsigned unk1c;
    LiquidFour force;
};

struct LiquidCast
{
};

struct __declspec(align(8)) LiquidResult
{
    LiquidCast* object;
    unsigned high;
};


LiquidResult* __cdecl FUN_00c85ef0(LiquidResult*, void*, const void*);





extern float DAT_011b2178, DAT_011b217c, DAT_011b2180, DAT_011b2184, DAT_011b2188, DAT_011b218c;

extern float DAT_01268428;


extern unsigned char DAT_0126842c;

struct LiquidRigid;

struct LiquidContactArray
{

    unsigned unk00;
    unsigned short count, unk06;

    unsigned unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;

    LiquidContact contacts[1];
};

struct LiquidConstraintData
{

    virtual void v0();

    virtual void v1();

    virtual void v2();

    virtual void v3();

    virtual void v4();

    virtual void v5();

    virtual void v6();

    virtual void v7();

    virtual int GetType();

    unsigned unk04, unk08;
    unsigned char* indices;

    unsigned unk10, unk14, unk18, unk1c, unk20, unk24;
    LiquidContactArray* contactData;

    unsigned short FUN_00cbc8f0(int);
};

struct LiquidConstraint
{
    unsigned unk00, unk04, unk08;
    LiquidConstraintData* data;
    unsigned unk10;
    LiquidRigid* first;
    LiquidRigid* second;
};

struct LiquidRigid
{

    unsigned unk00, unk04;
    struct LiquidWorld* world;

    unsigned unkc;

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

    unsigned unkec;

    unsigned unkf0;

    unsigned unkf4;

    unsigned unkf8;

    unsigned unkfc;

    unsigned unk100;

    unsigned unk104;

    unsigned unk108;

    unsigned unk10c;

    unsigned unk110;

    unsigned unk114;

    unsigned unk118;

    unsigned unk11c;

    unsigned unk120;

    unsigned unk124;

    unsigned unk128;

    unsigned unk12c;

    unsigned unk130;

    unsigned unk134;

    unsigned unk138;

    unsigned unk13c;

    unsigned unk140;

    unsigned unk144;

    unsigned unk148;

    unsigned unk14c;

    unsigned unk150;

    unsigned unk154;

    unsigned unk158;

    unsigned unk15c;

    unsigned unk160;

    unsigned unk164;

    unsigned unk168;

    unsigned unk16c;

    unsigned unk170;

    unsigned unk174;

    unsigned unk178;

    unsigned unk17c;

    unsigned unk180;

    unsigned unk184;

    unsigned unk188;

    unsigned unk18c;

    unsigned unk190;

    unsigned unk194;

    unsigned unk198;

    unsigned unk19c;

    unsigned unk1a0;

    unsigned unk1a4;

    unsigned unk1a8;

    unsigned unk1ac;

    LiquidFour velocity;

    void OnTrigger(const LiquidFour&);

    void FUN_00c9c1d0();


};

struct LiquidWorld
{
    void OnTrigger(const LiquidFour&);
    void FUN_00c9c1d0();
};

struct LiquidBody
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

    virtual const LiquidFour& GetPosition(LiquidFour& out);

    unsigned unk04;
    LiquidRigid* object;


    __forceinline void CopyPosition(LiquidVec& out)
    {
        LiquidFour v;
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&out)), (*(const ::hkVector4 *)(&GetPosition(v))));
    }
};

struct LiquidActionCandidate;

struct LiquidNode
{
    LiquidActionCandidate* data;
    LiquidNode* next;
};

struct LiquidMap
{
};


struct LiquidActionCandidate
{

    unsigned unk00, unk04;
    LiquidOwner* owner;
    unsigned unk0c;

    LiquidTarget* target;
    float radius, strength, impulse, unk20;

    LiquidVec position, normal;
    unsigned char pending;

    void FUN_00cbcbd0(LiquidLink*);

    __forceinline LiquidLink* GetLink()
    {
        return this && owner ? owner->link : (LiquidLink*)owner;
    }

    __forceinline LiquidLink* GetLink0()
    {
        LiquidLink* l = this && owner ? owner->link : 0;
        _ReadWriteBarrier();
        return l;
    }

    __forceinline LiquidBody* GetBody()
    {
        LiquidLink* l = GetLink0();
        return l ? l->body : 0;
    }

    void FUN_00cbccb0(float);
};

__forceinline float LiquidPick(bool c, float a, float b)
{
    return c ? a : b;
}

__forceinline float LiquidMin(float v, float m)
{
    return v > ::g_01012070 ? m : v;
}

__forceinline float LiquidMax(float v, float m)
{
    return v < ::DAT_01011598 ? m : v;
}

__declspec(noinline) bool LiquidVec::FUN_004390c0(const LiquidVec& p)
{
    bool a = x == p.x;
    bool b = y == p.y;
    bool c = z == p.z;
    return a & b & c;
}

// @fnv 0x00cbccb0
void LiquidActionCandidate::FUN_00cbccb0(float delta)

{

    LiquidVec force;
    force = (*reinterpret_cast<const ::LiquidVec *>((void *)&::NiPoint3::ZERO));

    LiquidLink* link = GetLink0();

    if (link)
    {

        LiquidBody* body = link->body;

        if (body)
        {

            if (!target)
            {

                LiquidResult lookup;

                LiquidRigid* obj = body->object;

                LiquidCast* found = FUN_00c85ef0(&lookup, obj, &(*reinterpret_cast<const unsigned int *>(&::g_01267b70)))->object;

                if (found)
                {

                    LiquidOwner* other = ((::LiquidOwner *)(reinterpret_cast<::NiObject *>((found))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<const unsigned int *>(&::g_012043f8))))));

                    if (other && other->unk08)
                    {

                        LiquidOwner* nested = (LiquidOwner*)other->unk08;

                        if (nested->link)
                            FUN_00cbcbd0(nested->link);
                    }
                }
            }

            LiquidVec bodyPosition;

            body->CopyPosition(bodyPosition);

            LiquidRigid* object = body->object;

            unsigned char gravity = DAT_0126842c;

            bool hasNormal = false;

            LiquidFour velocity = object ? object->velocity : (*reinterpret_cast<const ::LiquidFour *>(&::DAT_01267e30));

            LiquidContact contact;

            if (object && ::FUN_00c9c380((void *)(object), {}) && reinterpret_cast<::NiPoint3 *>(&(position))->FUN_004390c0((const ::NiPoint3 &)((*reinterpret_cast<const ::LiquidVec *>((void *)&::NiPoint3::ZERO)))))
            {

                for (int i = 0; reinterpret_cast<::NiPoint3 *>(&(position))->FUN_004390c0((const ::NiPoint3 &)((*reinterpret_cast<const ::LiquidVec *>((void *)&::NiPoint3::ZERO)))) && i < ::FUN_00c9c380((void *)(object), {}); ++i)
                {

                    LiquidConstraint* c = ((::LiquidConstraint *)(reinterpret_cast<::FUN_00c9c390_Class *>((object))->GetEntry(i)));

                    LiquidConstraintData* d = c->data;

                    if (d->GetType() == 11)
                    {

                        unsigned flags;

                        if (c->first == object && c->second)
                            flags = c->second->unk2c;

                        else if (c->second == object && c->first)
                            flags = c->first->unk2c;

                        else
                            continue;

                        if ((flags & 127) == 1 || (flags & 127) == 13)
                        {

                            LiquidContactArray* contacts = d->contactData;

                            if (contacts->count > 0)
                            {

                                contact = contacts->contacts[d->indices[d->FUN_00cbc8f0(0)]];

                                if (contact.NormalZ() < 0.5f)
                                {

                                    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&position)), (*(const ::hkVector4 *)(&contact.position)));

                                    ::FUN_004a3970((*(::NiPoint3_local *)(&normal)), (*(const ::hkVector4 *)(&contact.normal)));

                                    velocity.value = _mm_setr_ps(0.0f, 0.0f, 0.0f, 0.0f);
                                }
                            }
                        }
                    }
                }
            }

            float damping;

            if (!(position == (*reinterpret_cast<const ::LiquidVec *>((void *)&::NiPoint3::ZERO))))
            {

                LiquidVec difference = position;

                difference -= bodyPosition;

                gravity = true;
                hasNormal = true;

                float squared = difference.LengthSq();

                float distance = (float)sqrt(squared);

                if (distance > 0.0f)
                {

                    LiquidVec projected = normal;

                    projected *= normal.Dot(difference);

                    force.x = projected.x + force.x;
                    force.y = projected.y + force.y;
                    force.z = projected.z + force.z;
                }

                damping = DAT_011b2184;
            }
            else
                damping = DAT_011b2180;

            float exponent = (float)(damping * -1.0 * delta);

            float decay = exp(exponent);

            velocity.Mul(decay);

            if (gravity)
            {

                float vertical = -delta * DAT_011b218c * DAT_011b217c;

                velocity.value = _mm_add_ps(velocity.value, _mm_setr_ps(0.0f, 0.0f, vertical, 0.0f));
            }

            LiquidRigid* world = body->object;

            if (world)
            {

                ::FUN_00a29680();

                reinterpret_cast<::FUN_005616d0_Owner *>((world))->OnTrigger((::TriggerContext *)&(velocity));

                ::FUN_00a29680();
            }

            {

                LiquidNode* node = 0;

                reinterpret_cast<::A54440Hash *>(&((*reinterpret_cast<::LiquidMap *>(&::DAT_011b2190))))->FUN_00a53c30((::A54440Manager *)(target), (::A54440Manager **)&(node));

                for (; node; node = node->next)
                {

                    if (!node->next && !node->data)
                        break;

                    LiquidBody* otherBody = node->data->GetBody();

                    __m128 otherPosition = otherBody->GetPosition(contact.position).value;

                    float px, py, pz;

                    _mm_store_ss(&px, otherPosition);

                    _mm_store_ss(&py, _mm_shuffle_ps(otherPosition, otherPosition, 0x55));

                    _mm_store_ss(&pz, _mm_shuffle_ps(otherPosition, otherPosition, 0xaa));

                    LiquidVec raw = {px, py, pz};

                    LiquidVec otherPos = raw * DAT_011b2188;

                    LiquidVec difference = bodyPosition;

                    difference -= otherPos;

                    float distance = reinterpret_cast<::NiPoint3 *>(&(difference))->GetLengthSquared();

                    if (distance > 0 && radius + radius > distance)
                    {

                        float ratio = (radius - distance) / (radius * DAT_011b2178);

                        float hi = ratio > ::g_01012070 ? 1.0f : ratio;

                        float lo = hi < ::DAT_01011598 ? -0.5f : hi;

                        float scale = strength * lo;

                        LiquidVec push = {difference.x * scale, difference.y * scale, difference.z * scale};

                        if (hasNormal)
                        {

                            float dot = normal.Dot(push);

                            LiquidVec projected;
                            projected = normal * dot;

                            push -= projected;
                        }

                        force.x += push.x;
                        force.y += push.y;
                        force.z += push.z;
                    }
                }
            }

            if (target)
            {

                float neg = -impulse;
                LiquidVec push = (*reinterpret_cast<const ::LiquidVec *>((void *)&::DAT_011a9484)) * neg;

                LiquidVec rotated = {

                    target->rotation.xx * push.x + target->rotation.xy * push.y + target->rotation.xz * push.z,

                    target->rotation.yx * push.x + target->rotation.yy * push.y + target->rotation.yz * push.z,

                    target->rotation.zx * push.x + target->rotation.zy * push.y + target->rotation.zz * push.z};

                impulse *= 0.89999997615814209;

                force += rotated;
            }

            LiquidFour result;

            result.value[0] = (float)(force.x) * DAT_01268428;

            result.value[1] = force.y * DAT_01268428;

            result.value[2] = force.z * DAT_01268428;

            result.value[3] = 0;

            owner->force = result;

            if (!(force == (*reinterpret_cast<const ::LiquidVec *>((void *)&::NiPoint3::ZERO))))
            {

                LiquidRigid* world = body->object;

                if (world)
                {

                    ::FUN_00a29680();

                    reinterpret_cast<::hkpEntityC9C *>((world))->FUN_00c9c1d0();

                    ::FUN_00a29680();
                }
            }
        }
    }

    pending = 0;
}


struct P03MM
{
};
void __cdecl FUN_00cbc740();

struct FUN_00cbd4e0_shell
{
    char m_auiShapeKeys[0x14];
    void* FUN_00cbd4e0(unsigned char flag);
};

// @fnv 0x00cbd4e0
void* FUN_00cbd4e0_shell::FUN_00cbd4e0(unsigned char flag)
{
    FUN_00cbc740();
    if (flag & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}


struct FUN_00cbc650_obj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
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
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
};

struct FUN_00cbc650_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual FUN_00cbc650_obj* vGet(FUN_00cbc650_obj* volatile* pp);
    void FUN_00cbc650(FUN_00cbc650_obj* volatile a1);
};

// @fnv 0x00cbc650
void FUN_00cbc650_cls::FUN_00cbc650(FUN_00cbc650_obj* volatile a1)
{
    FUN_00cbc650_obj* obj = a1;
    reinterpret_cast<::fnv_00c86790::Holder *>(this)->FUN_00c86790((::fnv_00c86790::NiStream *)(obj));
    if (obj->m_1e5 != 1)
    {
        volatile unsigned int* p = (volatile unsigned int*)vGet(&a1);
        p[2] = _byteswap_ulong(p[2]);
        p[3] = _byteswap_ulong(p[3]);
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
    }
}

struct FUN_00cbc6a0_Data
{
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0C;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
};

struct FUN_00cbc6a0_Class
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
    virtual void FUN_00cbc6a0(unsigned char* arg);
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
    virtual FUN_00cbc6a0_Data* vf45(int* value);
};

// @fnv 0x00cbc6a0
void FUN_00cbc6a0_Class::FUN_00cbc6a0(unsigned char* arg)
{
    unsigned char value;
    FUN_00cbc6a0_Data* data = vf45((int*)&value);

    if (arg[0x1E4] != 1)
    {
        data->unk08 = _byteswap_ulong(data->unk08);
        data->unk0C = _byteswap_ulong(data->unk0C);
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
    }

    reinterpret_cast<::FUN_00c868b0_cls *>(this)->FUN_00c868b0((::C868_Iface *)(arg));

    if (arg[0x1E4] != 1)
    {
        data->unk08 = _byteswap_ulong(data->unk08);
        data->unk0C = _byteswap_ulong(data->unk0C);
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
    }
}

void* __cdecl FUN_00aa13e0(unsigned int size);
struct AutoMemContext_o2
{
    int oldContext;
    AutoMemContext_o2()
    {
        oldContext = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 16;
    }
    ~AutoMemContext_o2()
    {
        ::g_tlsBlock.memoryContext = oldContext;
    }
};
struct FUN_00cbc550_class
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
    FUN_00cbc550_class();
};
struct FUN_00cbca20_class
{
    FUN_00cbc550_class* FUN_00cbca20(intptr_t flags);
};
// @fnv 0x00cbca20
FUN_00cbc550_class* FUN_00cbca20_class::FUN_00cbca20(intptr_t flags)
{
    AutoMemContext_o2 context;
    FUN_00c876f0();
    FUN_00cbc550_class* result = new FUN_00cbc550_class();
    reinterpret_cast<::FUN_00c86800_Class *>(this)->FUN_00c86800((intptr_t)(result), (::FUN_00c86800_Table *)(flags));
    FUN_00c87700();
    return result;
}

struct HavokAllocator
{
    virtual void vf00();
    virtual void* allocate(int size);
    virtual void deallocate(void* p, int size);
};

struct HavokAllocatorContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HavokAllocator* m_alloc;
};

extern "C" HavokAllocatorContext* __cdecl FUN_00c85750();

struct HavokObj
{
    int unk00;
    short m_flags;
    short m_ref;
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

    static void* operator new(size_t size)
    {
        HavokAllocatorContext* tm = FUN_00c85750();
        HavokObj* p = (HavokObj*)tm->m_alloc->allocate(size);
        p->m_flags = (short)size;
        return p;
    }
    static void operator delete(void* p);

    HavokObj(void* a1, int a2);
};

struct DynCastHelper2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* unk18;
};

struct DynCastHelper1
{
    int unk00;
    int unk04;
    DynCastHelper2* unk08;
};

struct DynCastObj
{
};

struct GarbageCollectorObjectPtr
{
    DynCastObj* m_ptr;
    int m_unk04;
};


GarbageCollectorObjectPtr* __cdecl FUN_00c85ef0(GarbageCollectorObjectPtr* out, void* obj, const void* rtti);

struct ArgStruct
{
    int unk00;
    void* unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
};

struct TargetClass
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
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
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
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf8c(HavokObj* obj);
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vfbc(ArgStruct* arg);

    int unk04;
    int unk08;
    int unk0c;
    intptr_t unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;

    void FUN_00cbcbd0(void* p);
    void FUN_00cbd520(ArgStruct* arg);
};

// @fnv 0x00cbd520
void TargetClass::FUN_00cbd520(ArgStruct* arg)
{
    AutoMemContext_o2 memContext;

    this->unk1c = arg->unk08;
    this->unk20 = arg->unk0c;
    this->unk14 = arg->unk10;
    this->unk18 = arg->unk14;

    HavokObj* obj = new HavokObj(arg->unk04, 0);
    this->vf8c(obj);
    reinterpret_cast<::hkReferencedObjectC905 *>((obj))->FUN_00c905b0();

    GarbageCollectorObjectPtr gcPtr;
    void* pObj = arg->unk04;
    GarbageCollectorObjectPtr* res = FUN_00c85ef0(&gcPtr, pObj, &(*reinterpret_cast<const void * *>(&::g_01267b70)));
    if (res->m_ptr)
    {
        DynCastHelper1* dyn = ((::DynCastHelper1 *)(reinterpret_cast<::NiObject *>((res->m_ptr))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<const void * *>(&::g_012043f8))))));
        if (dyn && dyn->unk08 && dyn->unk08->unk18)
        {
            this->FUN_00cbcbd0(dyn->unk08->unk18);
        }
    }

    this->vfbc(arg);
}

class NiViewerStringArray
{
  public:
    virtual ~NiViewerStringArray();
    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
class FUN_00cbd650_base
{
  public:
};
class FUN_00cbd650_cls : public FUN_00cbd650_base
{
  public:
    void FUN_00cbd650(NiViewerStringArray* pkStrings);
};
// @fnv 0x00cbd650
void FUN_00cbd650_cls::FUN_00cbd650(NiViewerStringArray* pkStrings)
{
    AutoMemContext_o2 kContext;
    reinterpret_cast<::Wrapper86b80 *>(this)->FUN_00c86b80((::NiTPrimitiveArray<char *, ::NiTMallocInterface<char *>> *)(pkStrings));
    pkStrings->Add(FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_01268420))));
}

struct SmallAlignedState
{
    unsigned int unk00;
    void* unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    SmallAlignedState() : unk00(0), unk04(0), unk08(5000.0f), unk0c(15.0f), unk10(64.0f), unk14(15.0f)
    {}
};
struct StateAllocator
{
};
struct StateOwner
{
    unsigned int unk00;
    unsigned int unk04;
    void* unk08;
    SmallAlignedState* unk0c;
    unsigned int unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    SmallAlignedState* FUN_00cbcad0(bool* created);
};
// @fnv 0x00cbcad0
SmallAlignedState* StateOwner::FUN_00cbcad0(bool* created)
{
    AutoMemContext_o2 context;
    *created = !unk0c;
    if (*created)
    {
        unsigned char* raw = (unsigned char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::StateAllocator *>(&::g_memoryManager))))->FUN_00aa3e40(sizeof(SmallAlignedState) + 16);
        unsigned char offset = 16 - ((uintptr_t)raw & 15);
        raw += offset;
        raw[-1] = offset;
        SmallAlignedState* state = new (raw) SmallAlignedState;
        unk0c = state;
        if (unk08)
        {
            reinterpret_cast<::FUN_00c867d0_cls *>(this)->FUN_00c867d0((::FUN_00c867d0_out *)(state));
            state->unk08 = unk1c;
            state->unk0c = unk20;
            state->unk10 = unk14;
            state->unk14 = unk18;
        }
    }
    return unk0c;
}

struct ContextScope
{
    unsigned int saved;
    ContextScope(unsigned int old)
    {
        saved = old;
        ::g_tlsBlock.memoryContext = 16;
    }
    ~ContextScope()
    {
        ::g_tlsBlock.memoryContext = saved;
    }
};
struct CauseMap
{
};
struct CauseList
{
    void* unk00;
    void* unk04;
};
// @fnv 0x00cbcbd0
void TargetClass::FUN_00cbcbd0(void* p)
{
    unsigned int restore = ::g_tlsBlock.memoryContext;
    ContextScope scope(restore);
    if (p)
    {
        void* key = p;
        p = 0;
        unk10 = (intptr_t)key;
        reinterpret_cast<::A54440Hash *>(&((*reinterpret_cast<::CauseMap *>(&::DAT_011b2190))))->FUN_00a53c30((::A54440Manager *)(key), (::A54440Manager **)(void **)(&p));
        CauseList* list = (CauseList*)p;
        switch ((uintptr_t)list)
        {
        case 0: {
            CauseList* allocated = (CauseList*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::StateAllocator *>(&::g_memoryManager))))->FUN_00aa3e40(8);
            if (allocated != list)
            {
                allocated->unk00 = list;
                allocated->unk04 = list;
                list = allocated;
            }
            reinterpret_cast<::HashTableBase *>(&((*reinterpret_cast<::CauseMap *>(&::DAT_011b2190))))->InsertOrUpdate((uintptr_t)((void*)unk10), (uintptr_t)(list));
            if (list)
            {
                restore = *(volatile unsigned int*)&scope.saved;
            }
            else
            {
                scope.saved = *(volatile unsigned int*)&scope.saved;
                return;
            }
            break;
        }
        default:
            break;
        }
        if (list)
        {
            p = this;
            reinterpret_cast<::fnv_00cbc7b0::FUN_00cbc7b0_cls *>((list))->PushItem(&p);
        }
    }
restore_exit:
    scope.saved = restore;
cold_exit:;
}

struct AutoMemContext_o2_od_noo2
{
    int oldContext;
    AutoMemContext_o2_od_noo2()
    {
        oldContext = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 16;
    }
    ~AutoMemContext_o2_od_noo2()
    {
        ::g_tlsBlock.memoryContext = oldContext;
    }
};
struct Upd;
struct Sub
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Obj* V0c();
    virtual void* V10();
};
struct Chain
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void* V0c();
};
struct Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Chain* V0c();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void Vd0(Obj* a, int b, int c, int d, int e);
    virtual void v53();
    virtual void Vd8(Obj* a, int b);
    virtual void Vdc(void* a, int b);
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
    virtual void* V130();
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
    virtual void v95();
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
    virtual void V1c8();
    virtual void v115();
    virtual Obj* V1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* V1f4();
    bool FUN_004bae00();
    void Update(Upd* a);
};
struct SoundFile
{
    char* Get();
};
struct Proj
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
    SoundFile name;
};
struct Hand4;
struct Cell
{
public:
    Hand4* FUN_0043b4f0(Hand4* out);
};
struct SettingColl
{
};
extern char DAT_0108f1a8;
extern char DAT_0108f16c;
struct FixedStr
{
};
struct Eyes
{
};
struct Handler
{
    Eyes* Get();
};
struct TObj
{
};
void* __cdecl _ref_0084e3a0(Proj* a);
struct Local70
{
    float m0;
    float m1;
    float m2;
    float m3;
    float m4;
    float m5;
    float m6;
    float m7;
    float m8;
};
struct Extra
{
};
struct FloatConfiguredObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FloatConfiguredObject(float);
    ~FloatConfiguredObject();
};
void* __cdecl FUN_00aa13e0(unsigned int n);
struct BigObj : BSFadeNode
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
    BigObj(int);
    void* FUN_00a5ecb0(int a);
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
    virtual void Vdc(void* a, int b);
};
struct Rnd
{
    float F();
    float F(float a);
};
struct PathReq
{
};
struct InitObj : BSFadeNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    InitObj(void*);
    void* Init(void* a);
    void FUN_00c6b980(void* a);
};
struct Sphere : BSFadeNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Sphere(float, bool);
    void* Ctor(float a, int b);
};
struct __declspec(align(16)) Big
{
    __m128 unk00;
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
    Big();
    void FUN_0056f0f0(void* a);
    ~Big();
};
struct FilterValue
{
};
struct Temp622
{
    int unk00;
    FilterValue* Ctor(int a, void* b, int c);
};
struct Body : BSFadeNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Body(Big*);
    void* FUN_0056d380(Big* a);
    void FUN_00c6b980(void* a);
};
struct Acc : BSFadeNode
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
    Acc();
    void* Ctor();
};
struct S1fc
{
    int unk00;
    void Ctor();
    void* m04;
    float fa, fb, fc, fd;
};
extern float DAT_011a57fc;
extern float DAT_011a5800;
extern float DAT_011a5804;
extern float DAT_011a5808;
extern float DAT_011a580c;
extern float DAT_011a5810;
struct A140 : BSFadeNode
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
    A140(S1fc*);
    void* Ctor(S1fc* a);
};
struct Upd
{
    float time;
    bool updateControllers;
    bool isMultithreaded;
    int flags;
    void Ctor(float a, int b, int c);
};
struct NodeU
{
    void Update(Upd* a);
};
bool __cdecl FUN_004bae00(void* a);
struct Ctrl
{
};
struct Seq
{
};
struct Fade
{
};
// @fnv 0x009ad670
void This::FUN_009ad670()
{
    W1c8(0);
    Obj* obj = W1d0();
    if (obj)
    {
        float scale = 1.0f;
        if (((bool)(reinterpret_cast<::BSOcclusionPlane *>(this)->IsNotCulled())))
        {
            Chain* node = obj->V0c();
            Fade* fade = node ? (Fade*)((Sub*)node)->V10() : 0;
            if (fade)
                reinterpret_cast<::BSFadeNode *>((fade))->SetRange(DAT_01016970, DAT_01016970);
        }
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingColl *>(&::g_011d0fe4)))))) == 0)
        {
            TObj* named = (TObj*)((::Obj *)(::FUN_004aae30((::NiAVObject *)(obj), (::NiFixedString *)(void *)(&DAT_0108f1a8))));
            if (named)
            {
                scale = reinterpret_cast<::FUN_00644930_shell *>(this)->FUN_00644930() / reinterpret_cast<::NiPoint3 *>((((::Eyes *)&(reinterpret_cast<::NiAVObject *>((named))->FUN_0043c490()))))->ComputeMagnitude();
            }
            else
            {
                const char* name;
                if (reinterpret_cast<::BGSCameraPath *>((((::Proj *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->HasNameForWarning())
                {
                    Obj* base = (Obj*)((::Proj *)(reinterpret_cast<::Actor *>(this)->GetActorBase()));
                    name = (const char*)base->V130();
                }
                else
                    name = ((char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::Proj *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))->name))->FUN_00408da0()));
                ::FUN_005b5e40();
                scale = 1.0f;
            }
        }
        reinterpret_cast<::FUN_00440490_shell *>((obj))->FUN_00440490(scale);
        reinterpret_cast<::FUN_00440460_S *>((obj))->FUN_00440460((const ::V3 *)(::NiPoint3 *)(W1f4()));
        NiPoint3 angles = *((::NiPoint3 *)(reinterpret_cast<::TESRecipe *>(this)->GetData()));
        Local70 rotation;
        reinterpret_cast<::ThreeByThreeMatrix *>(&(rotation))->FUN_00a59780(angles.z, angles.y, angles.x);
        reinterpret_cast<::FUN_0043fa80_s *>((obj))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&rotation)));
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingColl *>(&::g_011d0fe4)))))) > 1)
        {
            reinterpret_cast<::PathingRequest *>((((PathReq*)((::Proj *)(reinterpret_cast<::Actor *>(this)->GetActorBase())))))->SetCenterRadius(DAT_011a5810);
            f8c = DAT_011a580c;
            NiPoint3 position = *W1f4();
            void* extra = ((void *)(reinterpret_cast<::NiAVObject *>((obj))->GetExtraData((*(const ::NiFixedString *)((void*)&(*(const ::FixedStr *)&(::FUN_00448a80())))))));
            if (extra)
            {
                Extra* flags = (Extra*)extra;
                reinterpret_cast<::BSXFlags_shell *>((flags))->FUN_00519230(0x10, 1);
            }
            for (int i = 0; i < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingColl *>(&::g_011d0fe4)))))); ++i)
            {
                FloatConfiguredObject guard(1.0f);
                BigObj* node = new BigObj(0);
                reinterpret_cast<::FUN_004bc1f0_S *>((node))->FUN_004bc1f0((float)(::MersenneTwister::GetRandomGenerator()->FUN_004dfec0() * 10.0),
                                   (float)(::MersenneTwister::GetRandomGenerator()->FUN_004dfec0() * 10.0),
                                   (float)(::MersenneTwister::GetRandomGenerator()->FUN_004dfec0() * 10.0 + 32.0));
                InitObj* collision = new InitObj(node);
                Sphere* shape = new Sphere(8.0f, 1);
                Big info;
                reinterpret_cast<::FUN_00507610_Class *>(&(info))->FUN_00507610(5.0f);
                reinterpret_cast<::FUN_006e4340_Class *>(&(info))->FUN_006e4340(0.0f);
                reinterpret_cast<::FUN_0056d360_Class *>(&(info))->FUN_0056d360(1);
                reinterpret_cast<::FUN_005076c0Class *>(&(info))->FUN_005076c0(1.0f);
                Temp622 filter;
                info.FUN_0056f0f0(((void *)(::FUN_00559450((int *)(((::FilterValue *)(reinterpret_cast<::FUN_00622290_cls *>(&(filter))->FUN_00622290(4, (intptr_t)(((void *)(::FUN_005dbe10()))), 0))))))));
                reinterpret_cast<::fnv_0056f110::FUN_0056f110_class *>(&(info))->FUN_0056f110((::fnv_0056f110::ScriptLocalsX *)(shape));
                Body* body = new Body(&info);
                reinterpret_cast<::FUN_00c6b980_cls *>((collision))->FUN_00c6b980((::World_c6b *)(body));
                obj->Vdc(node, 1);
                Acc* accumulator = new Acc;
                reinterpret_cast<::s005468d0::Owner *>((accumulator))->FUN_005468d0(0xe);
                node->Vdc(accumulator, 1);
                S1fc actionInfo;
                new ((void *)&(actionInfo)) ::FUN_009ae0f0();
                actionInfo.m04 = ((void *)(::FUN_004ae750((void *)(body))));
                actionInfo.fa = DAT_011a5808;
                actionInfo.fb = DAT_011a5804;
                actionInfo.fc = DAT_011a5800;
                actionInfo.fd = DAT_011a57fc;
                A140* action = new A140(&actionInfo);
                reinterpret_cast<::SceneC8E *>((body))->FUN_00c8ef80((::NiObjectC8E *)(action));
            }
            if (((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && ((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())))
            {
                reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0();
                ::FUN_00c69f50((::S_00c69f50_Obj *)(obj), 1, 1);
                Upd update;
                new ((void *)&(update)) ::NiUpdateData(0.0f, 0, 0);
                reinterpret_cast<::FUN_00a59c60_cls *>((obj))->FUN_00a59c60((std::intptr_t)(&update));
                Obj* world = (Obj*)((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                world->Vd0(obj, 1, 1, 0, 1);
            }
        }
        if (((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && ((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())))
        {
            reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0();
            ::FUN_00c69f50((::S_00c69f50_Obj *)(obj), 1, 1);
            Upd update;
            new ((void *)&(update)) ::NiUpdateData(0.0f, 0, 0);
            reinterpret_cast<::FUN_00a59c60_cls *>((obj))->FUN_00a59c60((std::intptr_t)(&update));
            Obj* world = (Obj*)((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
            world->Vd0(obj, 1, 1, 0, 1);
        }
        if (obj->V0c() && ::FUN_005784b0((::NiNode *)(void *)(obj->V0c())))
            ::FUN_00578060((::NodeView *)(void *)(obj->V0c()));
        if (((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) && ((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())) && ((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()))->FUN_004bae00())
        {
            Obj* world = (Obj*)((::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
            world->Vd8(obj, 1);
            ::EnsureLightingProperty((::AVObjectEx *)(obj));
        }
        Ctrl* ctrl = (Ctrl*)((void *)(::fnv_0043b230::FUN_0043b230((const char *)(obj))));
        if (!ctrl)
        {
            Ctrl* node = (Ctrl*)obj->V0c();
            if (node && ((int)(reinterpret_cast<::S_FUN_0045bc00 *>((node))->FUN_0045bc00(0))))
                ctrl = (Ctrl*)((void *)(::fnv_0043b230::FUN_0043b230((const char *)(((Obj*)((void *)(reinterpret_cast<::NiNode *>((node))->GetAt(0))))))));
        }
        Ctrl* manager = 0;
        while (ctrl)
        {
            if (::FUN_0043b300((const ::NiRTTI *)(void *)(&(*reinterpret_cast<void * *>(&::g_011f36ac))), (::NiAVObject *)(ctrl)))
            {
                manager = ctrl;
                break;
            }
            ctrl = (Ctrl*)((void *)(::fnv_004a8a90::FUN_004a8a90((char *)(ctrl))));
        }
        Seq* sequence;
        if (manager && (sequence = (Seq*)((void *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((manager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)(::FixedStr *)(((::FixedStr *)(::FUN_005c1490()))))))) != 0)
        {
            reinterpret_cast<::NiControllerManager *>((manager))->DeactivateAllSequences(0.0f);
            reinterpret_cast<::NiControllerManager *>((manager))->ActivateControllerSequence((::NiControllerSequence *)(sequence), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            reinterpret_cast<::TaskQueueInterface *>((manager))->QueueReferenceStateTask(1);
            ::SetNegatedGlobal((void *)(sequence));
            if (reinterpret_cast<::FUN_00507e10_shell *>(this)->FUN_00507e10() < reinterpret_cast<::FUN_00508100_shell *>((sequence))->FUN_00508100())
                reinterpret_cast<::FUN_00810550_class *>(this)->FUN_00810550(reinterpret_cast<::FUN_00508100_shell *>((sequence))->FUN_00508100());
        }
        else
            ::fnv_00a6d2d0::FUN_00a6d2d0((::fnv_00a6d2d0::TCTimeNode *)(obj));
    }
}

struct AutoMemContext_o2_od_oy_noo2
{
    int oldContext;
    AutoMemContext_o2_od_oy_noo2()
    {
        oldContext = ::g_tlsBlock.memoryContext;
        ::g_tlsBlock.memoryContext = 16;
    }
    ~AutoMemContext_o2_od_oy_noo2()
    {
        ::g_tlsBlock.memoryContext = oldContext;
    }
};
struct Vec4810;
struct Vec810
{
    float x, y, z;
    Vec810();
    Vec810 operator-(const Vec810&) const;
    Vec810& operator=(const Vec4810&);
};
Vec810 __cdecl FUN_004a3760(float, const Vec810&);
struct Hit810;
struct Snapshot810;
struct Query810;
struct Hit810
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    float unk10;
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
    Hit810(void*);
};
struct __declspec(align(16)) Snapshot810
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
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    unsigned unk1a0;
    unsigned unk1a4;
    unsigned unk1a8;
    unsigned unk1ac;
    unsigned unk1b0;
    unsigned unk1b4;
    unsigned unk1b8;
    unsigned unk1bc;
    unsigned unk1c0;
    unsigned unk1c4;
    unsigned unk1c8;
    unsigned unk1cc;
    unsigned unk1d0;
    unsigned unk1d4;
    unsigned unk1d8;
    unsigned unk1dc;
    unsigned unk1e0;
    unsigned unk1e4;
    unsigned unk1e8;
    unsigned unk1ec;
    unsigned unk1f0;
    unsigned unk1f4;
    unsigned unk1f8;
    unsigned unk1fc;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20c;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21c;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22c;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23c;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24c;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25c;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26c;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27c;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28c;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29c;
    unsigned unk2a0;
    unsigned unk2a4;
    unsigned unk2a8;
    unsigned unk2ac;
    unsigned unk2b0;
    unsigned unk2b4;
    unsigned unk2b8;
    unsigned unk2bc;
    unsigned unk2c0;
    unsigned unk2c4;
    unsigned unk2c8;
    unsigned unk2cc;
    unsigned unk2d0;
    unsigned unk2d4;
    unsigned unk2d8;
    unsigned unk2dc;
    unsigned unk2e0;
    unsigned unk2e4;
    unsigned unk2e8;
    unsigned unk2ec;
    unsigned unk2f0;
    unsigned unk2f4;
    unsigned unk2f8;
    unsigned unk2fc;
    unsigned unk300;
    unsigned unk304;
    unsigned unk308;
    unsigned unk30c;
    unsigned unk310;
    unsigned unk314;
    unsigned unk318;
    unsigned unk31c;
    Snapshot810();
    ~Snapshot810();
};
struct HitArray810
{
};
struct HitContainer810
{
    HitArray810* FUN_00460140();
};
struct __declspec(align(16)) Query810
{
    __m128 m_quad000;
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
    Query810();
    void FUN_004a3f70(unsigned);
};
struct Filter810
{
    unsigned value;
    Filter810(int);
};
struct Setting810
{
};
struct Position810
{
};
struct Object810
{
};
struct Body810
{
};
struct World810
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
    virtual void vc8(Query810*);
};
struct Cell810
{
};
struct Process810
{
};
struct Test810
{
};
struct Actor810
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
    virtual bool v100();
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
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual Body810* v1d0();
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
    virtual int v214();
};
struct Vec4810
{
    float x, y, z;
};
struct Array810
{
    Vec4810 ApplyScaled(float);
};
struct Host810
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
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    Array810 array;
    bool FUN_009b1810(Vec810, Actor810*);
};
struct Debug810
{
};
// @fnv 0x009b1810
bool Host810::FUN_009b1810(Vec810 pos, Actor810* actor)
{
    Object810* base = ((::Object810 *)(reinterpret_cast<::Actor *>(this)->GetActorBase()));
    if (reinterpret_cast<::FUN_00477950_shell *>((base))->HasAnyFlags(16))
        return true;
    Body810* body = actor ? actor->v1d0() : 0;
    if (actor == (*reinterpret_cast<::Actor810 * *>(&::_g_thePlayer)))
        body = ((::Body810 *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::Actor810 * *>(&::_g_thePlayer))))->FUN_00950bb0(0)));
    if (!body || !reinterpret_cast<::NiAVObject *>((body))->IsVisualObject())
        return false;
    World810* world = ((::Cell810 *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget())) ? ((::World810 *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell810 *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget()))))->FUN_004543c0())) : 0;
    if (!world)
        return false;
    unsigned mask = 0x26206;
    ::ShadowLightData::SetTargetMaskForSelection(39, mask);
    Vec810 points[7];
    points[0] = *((::Vec810 *)(((::Vec3 *)(void *)(((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))));
    bool multiple = false;
    if (actor->v100())
    {
        Actor810* checkActor = actor;
        if (checkActor->v214())
        {
            multiple = true;
            points[1] = points[0];
            points[1].z += reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
            points[2] = points[0];
            points[2].z -= reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
            points[3] = points[0];
            points[3].y += reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
            points[4] = points[0];
            points[4].y -= reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
            points[5] = points[0];
            points[5].x += reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
            points[6] = points[0];
            points[6].x -= reinterpret_cast<::Twin_0084d030 *>((((::Position810 *)(reinterpret_cast<::FUN_0043d450_Owner *>((body))->FUN_0043d450()))))->GetStoredFloatValue() * 2.0f;
        }
    }
    Query810 query;
    Filter810 filter(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(filter))->FUN_004a39f0(39);
    Actor810* checkActor = actor->v100() ? actor : 0;
    if (checkActor && ((::Process810 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((checkActor))->FUN_009306d0())))
        reinterpret_cast<::FUN_0059ce80_shell *>(&(filter))->FUN_0059ce80((uintptr_t)(((void *)(reinterpret_cast<::S819 *>((((::Process810 *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((checkActor))->FUN_009306d0()))))->FUN_00819250()))));
    else
        reinterpret_cast<::FUN_0059ce80_shell *>(&(filter))->FUN_0059ce80((uintptr_t)(((void *)(::FUN_005dbe10()))));
    reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::Vec810 &)(pos))->FUN_0063c8a0((void *)&(const ::Vec4810 &)(array.ApplyScaled(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting810 *>(&::originalRuntimeFloatSetting1032)))))))));
    query.FUN_004a3f70(filter.value);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(query))->FUN_004a3da0((void *)&(pos));
    reinterpret_cast<::FUN_004a3eb0_shell *>(&(query))->FUN_004a3eb0((void *)&(points[0]));
    Snapshot810 snapshot;
    reinterpret_cast<::FUN_004a3fb0_shell *>(&(query))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::Snapshot810 *)(&snapshot));
    bool blocked = false;
    world->vc8(&query);
    for (int i = 0; !blocked && i < HavokArraySize((((::HitArray810 *)(::FUN_00460140((intptr_t)(((::HitContainer810 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(query))->FUN_008cdd90())))))))); i++)
    {
        Hit810 hit(((void *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitArray810 *)(::FUN_00460140((intptr_t)(((::HitContainer810 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(query))->FUN_008cdd90()))))))))->GetEntryAt(i))));
        Vec810 dir = points[0] - pos;
        Vec810 delta = FUN_004a3760(hit.unk10, dir);
        if (!(*reinterpret_cast<::FUN_004a51b0_shell *>(&(array))->FUN_004a51b0(2) < -0.98) || !(((double)(reinterpret_cast<::NiPoint3 *>(&(delta))->ComputeMagnitude())) < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting810 *>(&::originalRuntimeFloatSetting1029))))))))
        {
            if (!(*reinterpret_cast<::Test810 **>(reinterpret_cast<char *>(this) + 0xc8)) || !reinterpret_cast<::FUN_00452370_shell *>(((*reinterpret_cast<::Test810 **>(reinterpret_cast<char *>(this) + 0xc8))))->FUN_00452370())
            {
                if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting810 *>(&::g_011d0a78)))))) > 0)
                    ::FUN_005b5e40();
                blocked = true;
            }
        }
    }
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting810 *>(&::g_011d0a78)))))) > 0)
    {
        ::ImageSpaceEffectParam color = blocked ? ::ImageSpaceEffectParam(1, 0, 0, 1) : ::ImageSpaceEffectParam(0, 1, 0, 1);
        void* line = ((void *)(::fnv_004b3890::FUN_004b3890((const class ::FUN_006815c0 &)(pos), (const ::fnv_004b3890::FUN_004a7800 &)(color), (const class ::FUN_006815c0 &)(points[0]), (const ::fnv_004b3890::FUN_004a7800 &)(color), 1)));
        reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::Debug810 * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(line), 25.0f);
    }
    if (multiple && blocked)
    {
        for (int i = 1; blocked && i < 7; i++)
        {
            blocked = false;
            Snapshot810 snapshot;
            reinterpret_cast<::FUN_004a3fb0_shell *>(&(query))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::Snapshot810 *)(&snapshot));
            reinterpret_cast<::FUN_004a3eb0_shell *>(&(query))->FUN_004a3eb0((void *)&(points[i]));
            world->vc8(&query);
            for (int j = 0; !blocked && j < HavokArraySize((((::HitArray810 *)(::FUN_00460140((intptr_t)(((::HitContainer810 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(query))->FUN_008cdd90())))))))); j++)
            {
                Hit810 hit(((void *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitArray810 *)(::FUN_00460140((intptr_t)(((::HitContainer810 *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(query))->FUN_008cdd90()))))))))->GetEntryAt(j))));
                Vec810 dir = points[j] - pos;
                Vec810 delta = FUN_004a3760(hit.unk10, dir);
                if (!(*reinterpret_cast<::FUN_004a51b0_shell *>(&(array))->FUN_004a51b0(2) < -0.98) || !(((double)(reinterpret_cast<::NiPoint3 *>(&(delta))->ComputeMagnitude())) < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting810 *>(&::originalRuntimeFloatSetting1029))))))))
                    blocked = true;
            }
        }
    }
    return !blocked;
}

struct Color4
{
    float r, g, b, a;
};

struct Color3
{
    float r, g, b;
};

struct Ptr4
{
    void* p;
};

struct Setting
{
};
extern int g_dummy;

struct FloatSetting
{
};

struct __declspec(align(16)) Elem70
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
    void* unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    Vec3* FUN_00460140();
};

struct HitInfo
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    int unk20[8];
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    Ptr4* unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
};

struct HitArray
{
    HitArray* FUN_00460140();
};

struct HitHolder
{
    HitArray* FUN_00460140();
};

struct Flag1
{
    char c;
};

struct Flag1Ptr
{
};

struct ResList
{
    void* p0;
    int i4;
    int i8;
    int iC;
    ResList(int v);
    ~ResList();
};

struct ProjList
{
    void* p0;
    int i4;
    int i8;
    int iC;
    int i10;
    int i14;
    ProjList(void* a, int b);
    ~ProjList();
};

struct Shape
{
};

struct Drawer
{
};

struct Params
{
    Vec3 unk00;
    Vec3 unk0C;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    void* unk28;
    int unk2C;
    void* unk30;
    int unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    int unk48;
    float unk4C;
    int unk50;
    float unk54;
    float unk58;
    int unk5C;
    Color3 unk60;
    int unk6C;
    char unk70;
    char unk71;
    char unk72;
    char unk73;
    char unk74;
    char unk75;
    char unk76;
    char unk77;
    int unk78;
    int unk7C;
    Params();
};

struct Mgr
{
};

struct Wrap4
{
    int v;
};

struct RefObj
{
    virtual void vf00();
};

struct Hand4
{
    void* p;
};
struct Hand8
{
    void* p;
    int i;
};


struct Proc
{
    virtual void vf00();
};

struct Owner
{
    virtual void vf00();
};

struct VTbl;

struct NodeRef
{
    unsigned int unk00;
    unsigned int unk04;
    RefObj* unk08;
    int unk0C;
};

struct NodeList
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
    void* unk10C;
    void* unk110;
    NodeList();
    ~NodeList();
};

struct Query
{
};

struct NameHolder
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual char* GetName();
};

struct Weap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    NameHolder unk18;
    void* FUN_006733e0();
    char FUN_004a4140();
    char CallMemberAtOffset54();
    char FUN_004a4100();
    char FUN_004a41e0();
    unsigned int pad1c[0xc];
    void* unk4c;
};

struct SndSrc
{
};

struct Snd
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    ~Snd();
};

struct WeapHolder
{
};

struct Picker
{
    virtual void vf00();
};

struct Proc2
{
};

struct Big4c0
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
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    Big4c0();
    ~Big4c0();
};

struct __declspec(align(16)) Big570
{
    __m128 quad00;
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
    Big570();
    void FUN_004a3f70(void* p);
};

struct PlayerX
{
};


struct CellPtr
{
    void* p;
};

Vec3 __cdecl FUN_004a3760(float f, const Vec3& v);
extern "C" bool __cdecl FUN_004b61d0(Vec3 p, PlayerX* pl, float f);
extern "C" float __cdecl FUN_00406cc0(float a);
extern "C" Sub* __cdecl FUN_00c85ef0(Hand8* out, void* a, void* b);
struct AudioMgr
{
    Snd FUN_00ad7480(void* a, SndSrc* b);
};

struct ProjCls
{
    virtual void vf00();
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
    CellPtr unkA0;
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
    bool unkD4;
    bool unkD5;
    bool unkD6;
    bool unkD7;
    bool unkD8;
    bool unkD9;
    unsigned short unkDA;
    unsigned int unkDC;
    unsigned int unkE0;
    int unkE4;
    Vec3 unkE8;
    Vec3 unkF4;
    void FUN_009ae6e0();
};

struct ProjVt
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
    virtual bool IsDead();
};

struct PickVt
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
    virtual bool Pick(Big570* p);
    virtual Owner* GetOwner();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual int GetId(int i);
};

struct SelfVt
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
    virtual Vec3* GetPos();
};

// @fnv 0x009ae6e0
void ProjCls::FUN_009ae6e0()
{
    if (((::Cell *)(::FUN_00559450((int *)&(unkA0)))) == 0)
        return;
    if (unkE4 > 0 && unkD6 && !unkD7)
        reinterpret_cast<::Actor9af *>(this)->FUN_009afef0();
    if (unkD5 && !unkD4)
    {
        unkD4 = 1;
        ResList res(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011d10a4)))))));
        ProjList list(((void *)(::FUN_00559450((int *)&(res)))), *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011d10a4)))))));
        ::FUN_00cbd960();
        reinterpret_cast<::S_00c9f1e0_Obj *>((((::Cell *)(::FUN_00559450((int *)&(unkA0))))))->FUN_00c9f1e0((::S_00c9f1e0_Range *)(::ProjList *)(&list));
        Flag1 fl;
        if (reinterpret_cast<::FUN_005609f0_shell *>((((::Flag1Ptr *)(reinterpret_cast<::S009afc70 *>(&(list))->FUN_009afc70(&fl)))))->FUN_005609f0())
            ::FUN_009b2e00(((void *)(::FUN_00559450((int *)&(res)))), ((intptr_t)(reinterpret_cast<::FUN_009afc50_shell *>(&(list))->FUN_009afc30())));
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011d0a78)))))) > 1)
        {
            for (int i = 0; i < ((intptr_t)(reinterpret_cast<::FUN_009afc50_shell *>(&(list))->FUN_009afc30())); i++)
            {
                Elem70 e;
                reinterpret_cast<::FUN_00632d40_shell *>(&(e))->FUN_00632d40((*(const ::FUN_00632d40_shell *)(((::Elem70 *)(reinterpret_cast<::FUN_009afc30_shell *>(&(list))->FUN_009afc30())) + i)));
                Vec3 a;
                ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&a)), (*(const ::hkVector4 *)(((::Vec3 *)(void *)&(e)))));
                Vec3 b;
                ::FUN_004a3970((*(::NiPoint3_local *)(&b)), (*(const ::hkVector4 *)(((::Vec3 *)(::FUN_00460140((intptr_t)&(e)))))));
                Color4 c;
                new ((void *)&(c)) ::ImageSpaceEffectParam(1.0f, 0.0f, 0.0f, ::g_011d86d4_arg1);
                Shape* s = ((::Shape *)(::CreateOctahedron(::DAT_01016088, (const struct ::FUN_004a7800 *)(const ::Color4 *)(&c), 1)));
                reinterpret_cast<::FUN_00a5a040_Class *>((s))->FUN_00a5a040();
                reinterpret_cast<::FUN_00440460_S *>((s))->FUN_00440460((const ::V3 *)(const ::Vec3 *)(&a));
                reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(s), ::DAT_01017b78);
                s = ((::Shape *)(::fnv_004b3890::FUN_004b3890((*(const class ::FUN_006815c0 *)(&a)), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), (*(const class ::FUN_006815c0 *)(&(*(::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(a))->ProjectileLaunched((::NiPoint3 *)&(const ::Vec3 &)(b.ApplyScaled(::DAT_01017b78)), {}))))), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), 1)));
                reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(s), ::DAT_01017b78);
            }
        }
        bool done = false;
        for (int j = 0; !done && j < ((intptr_t)(reinterpret_cast<::FUN_009afc50_shell *>(&(list))->FUN_009afc30())); j++)
        {
            Elem70 e;
            reinterpret_cast<::FUN_00632d40_shell *>(&(e))->FUN_00632d40((*(const ::FUN_00632d40_shell *)(((::Elem70 *)(reinterpret_cast<::FUN_009afc30_shell *>(&(list))->FUN_009afc30())) + j)));
            if (e.unk48)
            {
                void* r = ((void *)(::FUN_004b5820((::FormLike *)(e.unk48))));
                Proc* u = ((::Proc *)(::FUN_0056f930((::NiAVObject *)(r))));
                if (!u || !((ProjVt*)u)->IsDead())
                {
                    Vec3 pos;
                    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&pos)), (*(const ::hkVector4 *)(((::Vec3 *)(void *)&(e)))));
                    Vec3 dir;
                    ::FUN_004a3970((*(::NiPoint3_local *)(&dir)), (*(const ::hkVector4 *)(((::Vec3 *)(::FUN_00460140((intptr_t)&(e)))))));
                    Big4c0 q;
                    Big570 p;
                    Vec3 v = *((SelfVt*)this)->GetPos();
                    Vec3 w = FUN_004a3760(::DAT_010162c0, (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(pos))->FUN_00439ef0((::NiPoint3 *)&(v), *(const ::NiPoint3 *)nullptr))));
                    if (((double)(reinterpret_cast<::NiPoint3 *>((void *)&(w))->ComputeMagnitude())) < ::g_01012070)
                    {
                        reinterpret_cast<::NiPoint3 *>(&(v))->Subtract((const ::NiPoint3 &)((const ::Vec3 &)(dir.ApplyScaled(::g_011c9040_arg1))));
                        w = dir.ApplyScaled(::g_011db514_arg1);
                    }
                    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(p))->FUN_004a3da0((void *)(&v));
                    reinterpret_cast<::Class_007f68a0 *>(&(p))->FUN_007f68a0((*(const ::NiPoint3 *)(&w)));
                    Hand4 h4;
                    p.FUN_004a3f70(((::Cell *)(::FUN_00559450((int *)&(unkA0))))->FUN_0043b4f0(&h4)->p);
                    reinterpret_cast<::FUN_004a3fb0_shell *>(&(p))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::Big4c0 *)(&q));
                    int target = 0x24;
                    bool found = false;
                    if (((::Picker *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Proc2 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())))
                    {
                        Picker* pk = ((::Picker *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Proc2 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                        if (((PickVt*)pk)->Pick(&p))
                        {
                            bool stop = false;
                            for (int k = 0; !found && !stop && k < HavokArraySize((((::HitArray *)(::FUN_00460140((intptr_t)(((::HitHolder *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(p))->FUN_008cdd90()))))))));
                                 k++)
                            {
                                HitInfo h;
                                reinterpret_cast<::S50 *>(&(h))->FUN_00696c30((::S50 *)(((::HitInfo *)(reinterpret_cast<::FUN_004a46b0_class *>((((::HitArray *)(::FUN_00460140((intptr_t)(((::HitHolder *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(p))->FUN_008cdd90()))))))))->GetEntryAt(k)))));
                                void* r2 = ((void *)(::FUN_004b5820((::FormLike *)(h.unk50))));
                                Proc* u2 = ((::Proc *)(::FUN_0056f930((::NiAVObject *)(r2))));
                                if (r == r2)
                                {
                                    found = true;
                                    int last = -1;
                                    for (int m = 0; m < 8 && h.unk20[m] != -1; m++)
                                        last = h.unk20[m];
                                    Wrap4 wr;
                                    bool isActor =
                                        ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((((::Wrap4 *)(new ((void *)&(wr)) ::GlobalObject_008c71b0((intptr_t)(((void *)(::FUN_0043b540((char *)(((RefObj*)h.unk50)))))))))))->FUN_004a3a20())) == 1;
                                    if (isActor)
                                    {
                                        target = ((int)(reinterpret_cast<::FUN_00457880_Class *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_00457880((intptr_t)(&pos))));
                                    }
                                    else
                                    {
                                        Owner* ow = ((::Owner *)(::FUN_004a3a40((::TESObjectREFR *)(void *)(((void *)(::FUN_00559450((int *)(h.unk50))))))));
                                        if (ow)
                                            target = reinterpret_cast<::FUN_00c84f10_cls *>((ow))->FUN_00c84f10(last);
                                    }
                                }
                                else if (!u2 || !((ProjVt*)u2)->IsDead())
                                {
                                    stop = true;
                                }
                            }
                        }
                    }
                    if (found)
                    {
                        unkE8 = pos;
                        if (reinterpret_cast<::NiPoint3 *>((void *)&(unkF4))->FUN_004390c0((*(const ::NiPoint3 *)(&(*reinterpret_cast<::Vec3 *>((void *)&::NiPoint3::ZERO))))))
                            unkF4 = dir;
                        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::Setting *>(&::g_011d0a78)))))) > 1)
                        {
                            Color4 c;
                            new ((void *)&(c)) ::ImageSpaceEffectParam(0.0f, 1.0f, 0.0f, ::g_011d86d4_arg1);
                            Shape* s = ((::Shape *)(::CreateOctahedron(::DAT_0101712c, (const struct ::FUN_004a7800 *)(const ::Color4 *)(&c), 1)));
                            reinterpret_cast<::FUN_00a5a040_Class *>((s))->FUN_00a5a040();
                            reinterpret_cast<::FUN_00440460_S *>((s))->FUN_00440460((const ::V3 *)(const ::Vec3 *)(&unkE8));
                            reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(s), ::DAT_01017b78);
                            s = ((::Shape *)(::fnv_004b3890::FUN_004b3890((*(const class ::FUN_006815c0 *)(&unkE8)), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), (*(const class ::FUN_006815c0 *)(&(*(::Vec3 *)(reinterpret_cast<::Point3Offset *>((void *)&(unkE8))->ProjectileLaunched((::NiPoint3 *)&(const ::Vec3 &)(unkF4.ApplyScaled(::DAT_01017868)), {}))))), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), 1)));
                            reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(s), ::DAT_01017b78);
                        }
                        done = true;
                        Weap* wt = ((::Weap *)(reinterpret_cast<::FUN_004fb7d0_shell *>((((::WeapHolder *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))))->FUN_004fb7d0({})));
                        if (wt)
                        {
                            bool flag = true;
                            Vec3 dd = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(pos))->FUN_00439ef0((::NiPoint3 *)&(*((::Vec3 *)(::FUN_0045bb80((intptr_t)(((::PlayerX *)(::FUN_00524c90()))))))), *(const ::NiPoint3 *)nullptr)));
                            if (((bool)(::FUN_00525420())) || ((double)(reinterpret_cast<::NiPoint3 *>((void *)&(dd))->ComputeMagnitude())) > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting642)))))) ||
                                !FUN_004b61d0(pos, ((::PlayerX *)(::FUN_00524c90())), ::g_011db514_arg1))
                                flag = false;
                            void* proj = wt->FUN_006733e0();
                            if (proj)
                            {
                                float spd = ::RandomFloat(reinterpret_cast<::FUN_004a40a0_Class *>((wt))->FUN_004a40a0(), reinterpret_cast<::FUN_004a40c0_Class *>((wt))->GetModifierValue());
                                Query* qq = ((::Query *)(::ScreenSplatter::Activate(spd, 1)));
                                reinterpret_cast<::FUN_006233c0 *>((qq))->GetImpactDataForMaterial(0);
                                reinterpret_cast<::Unk *>((qq))->FUN_004a1a10(8, 0);
                                reinterpret_cast<::Unk *>((qq))->FUN_004a1a10(0x1d, 0);
                                Proc2* p2 = ((::Proc2 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
                                Picker* t = p2 ? ((::Picker *)(reinterpret_cast<::FUN_004543c0_cls *>((p2))->FUN_004543c0())) : 0;
                                if (t)
                                {
                                    reinterpret_cast<::Owner623 *>((qq))->FUN_006231a0((::NiNode623 *)(t));
                                    NodeList nl;
                                    reinterpret_cast<::fnv_00623090::Host *>((qq))->FUN_00623090((void *)(&pos), (::fnv_00623090::Vir *)(::NodeList *)(&nl));
                                    int n = HavokArraySize(reinterpret_cast<::TESTopicInfoData *>(&(nl))->GetLinkToList());
                                    float fade = ((float)(::FUN_004a4240()));
                                    char cc = (char)FUN_00406cc0(::RandomFloat(0.0f, ::DAT_0101e570));
                                    for (int k = 0; k < n; k++)
                                    {
                                        RefObj* ref = ((::NodeRef *)(reinterpret_cast<::FUN_0062e150_cls *>((((::NodeList *)(reinterpret_cast<::TESTopicInfoData *>(&(nl))->GetLinkToList()))))->FUN_0062e150(k)))->unk08;
                                        if (ref)
                                        {
                                            int id = target;
                                            int idx = ((::NodeRef *)(reinterpret_cast<::FUN_0062e150_cls *>((((::NodeList *)(reinterpret_cast<::TESTopicInfoData *>(&(nl))->GetLinkToList()))))->FUN_0062e150(k)))->unk0C;
                                            if (idx != -1)
                                            {
                                                Owner* ow = ((::Owner *)(::FUN_004a3a40((::TESObjectREFR *)(void *)(((void *)(::FUN_00559450((int *)(ref))))))));
                                                if (!ow)
                                                    continue;
                                                Owner* o2 = ((PickVt*)ow)->GetOwner();
                                                if (o2)
                                                    id = ((PickVt*)o2)->GetId(idx);
                                            }
                                            else
                                            {
                                                Owner* ow = ((::Owner *)(::FUN_004a3a40((::TESObjectREFR *)(void *)(((void *)(::FUN_00559450((int *)(ref))))))));
                                                if (!ow)
                                                    continue;
                                                id = reinterpret_cast<::FUN_006205a0_Class *>((ow))->FUN_006205a0();
                                            }
                                            if (id == target)
                                            {
                                                Wrap4 wr;
                                                bool isActor =
                                                    ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((((::Wrap4 *)(new ((void *)&(wr)) ::GlobalObject_008c71b0((intptr_t)(((void *)(::FUN_0043b540((char *)(ref))))))))))->FUN_004a3a20())) == 1;
                                                Sub* node = 0;
                                                if (isActor)
                                                {
                                                    void* a = ::FUN_004b59f0(ref);
                                                    if (a)
                                                    {
                                                        Hand8 hh;
                                                        node = (Sub*)((void *)(::FUN_00559450((int *)(FUN_00c85ef0(&hh, a, &(*reinterpret_cast<int *>(&::g_011f4a20)))))));
                                                        if (node && reinterpret_cast<::FUN_009611e0_shell *>((node))->FUN_009611e0())
                                                            node = (Sub*)reinterpret_cast<::FUN_009611e0_shell *>((node))->FUN_009611e0();
                                                    }
                                                }
                                                else
                                                {
                                                    node = ((::Sub *)(::FUN_00c7fa90((::S_Obj *)(ref))));
                                                }
                                                Proc* u3 = ((::Proc *)(::FUN_0056f930((::NiAVObject *)(node))));
                                                if (!isActor && (!u3 || !::IsAcousticSpaceFormTypeAllowed((::Refr_C *)(u3), 1)))
                                                    continue;
                                                Mgr* mg = ((::Mgr *)(reinterpret_cast<::FnCls *>(((*reinterpret_cast<::Drawer * *>(&::g_TES))))->FUN_004519d0((*(float *)&(const ::Vec3 &)(pos)), {}, {})));
                                                Params prm;
                                                prm.unk00 = unkE8;
                                                prm.unk0C = unkF4;
                                                prm.unk38 = spd;
                                                prm.unk3C = spd;
                                                prm.unk40 = reinterpret_cast<::FUN_008aff10_obj *>((wt))->GetNestedValue();
                                                prm.unk28 = node;
                                                prm.unk30 = proj;
                                                prm.unk44 = fade;
                                                prm.unk70 = cc;
                                                prm.unk75 = wt->FUN_004a4140();
                                                prm.unk74 = wt->CallMemberAtOffset54();
                                                prm.unk73 = wt->FUN_004a4100();
                                                prm.unk4C = reinterpret_cast<::FUN_004a41c0 *>((wt))->GetRadius();
                                                prm.unk76 = wt->FUN_004a41e0();
                                                prm.unk54 = reinterpret_cast<::fnv_004a40e0::FUN_004a40e0 *>((wt))->GetHealthRegeneration();
                                                prm.unk58 = reinterpret_cast<::BGSImpactData *>((wt))->FUN_009a9350();
                                                Color3 col;
                                                prm.unk60 = *((::Color3 *)(reinterpret_cast<::FUN_00416870_t *>(&(col))->FUN_00416870(
                                                    (float)(((unsigned char)((reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((wt))->GetNextFromSubobject()) & 0xff)) / ::DAT_0101e568),
                                                    (float)(((unsigned char)((((unsigned short)(reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((wt))->GetNextFromSubobject())) >>
                                                                              8) &
                                                                             0xff)) /
                                                            ::DAT_0101e568),
                                                    (float)(((unsigned char)(((reinterpret_cast<::fnv_004a4220::FUN_004a4220Class *>((wt))->GetNextFromSubobject()) >> 16) & 0xff)) /
                                                            ::DAT_0101e568))));
                                                reinterpret_cast<::FUN_004a3fe0_shell *>((mg))->FUN_004a3fe0(&prm, 1, 0);
                                            }
                                        }
                                    }
                                    qq = 0;
                                }
                            }
                            if (flag && !unkD9)
                            {
                                char* name = wt->unk18.GetName();
                                if (name && *name)
                                {
                                    Vec3 dv;
                                    switch (((intptr_t)(reinterpret_cast<::BGSCameraPath *>((wt))->GetPrevPath())))
                                    {
                                    case 0:
                                        dv = dir;
                                        reinterpret_cast<::FUN_004a0c10_s *>(&(dv))->FUN_004a0c10();
                                        break;
                                    case 1:
                                        dv = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((SelfVt*)this)->GetPos()))->FUN_00439ef0((::NiPoint3 *)&(pos), *(const ::NiPoint3 *)nullptr)));
                                        reinterpret_cast<::FUN_004a0c10_s *>(&(dv))->FUN_004a0c10();
                                        break;
                                    case 2: {
                                        Vec3 a = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((SelfVt*)this)->GetPos()))->FUN_00439ef0((::NiPoint3 *)&(pos), *(const ::NiPoint3 *)nullptr)));
                                        reinterpret_cast<::FUN_004a0c10_s *>(&(a))->FUN_004a0c10();
                                        Vec3 b = dir;
                                        reinterpret_cast<::FUN_004a0c10_s *>(&(b))->FUN_004a0c10();
                                        dv = (*(::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::Vec3 &)(FUN_004a3760((float)(reinterpret_cast<::FUN_004b6190_shell *>((void *)&(b))->DotProduct((void *)&(a)) * ::DAT_01011590), b)))->FUN_00439ef0((::NiPoint3 *)&(a), *(const ::NiPoint3 *)nullptr)));
                                        break;
                                    }
                                    default:
                                        dv = dir;
                                        reinterpret_cast<::FUN_004a0c10_s *>(&(dv))->FUN_004a0c10();
                                        break;
                                    }
                                    ::FUN_006890b0((::World *)(void *)(((::Proc2 *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))), reinterpret_cast<::FUN_00508100_shell *>((wt))->FUN_00508100(), (intptr_t)(name), dv, pos, 1.0f, 7, 0);
                                }
                            }
                            SndSrc* s1 = *reinterpret_cast<::SndSrc **>(&wt->unk4c);
                            if (s1)
                            {
                                Snd snd = ((::AudioMgr *)(::FUN_00453a70()))->FUN_00ad7480(((void *)(::FUN_00511840((char *)(s1)))), s1);
                                reinterpret_cast<::FUN_00ad8b60_h *>(&(snd))->FUN_00ad8b60(pos.x, pos.y, pos.z);
                                reinterpret_cast<::FUN_00ad8830_shell *>(&(snd))->FUN_00ad8830(0);
                            }
                            SndSrc* s2 = ((::SndSrc *)(reinterpret_cast<::FUN_0068a830_shell *>((wt))->GetGrass()));
                            if (s2)
                            {
                                Snd snd = ((::AudioMgr *)(::FUN_00453a70()))->FUN_00ad7480(((void *)(::FUN_00511840((char *)(s2)))), s2);
                                reinterpret_cast<::FUN_00ad8b60_h *>(&(snd))->FUN_00ad8b60(pos.x, pos.y, pos.z);
                                reinterpret_cast<::FUN_00ad8830_shell *>(&(snd))->FUN_00ad8830(0);
                            }
                        }
                    }
                }
            }
        }
        if (unkD5 && !unkD6)
            reinterpret_cast<::fnv_009b00a0::Obj082 *>(this)->ProcessHits();
    }
}
#include "generated/data/fallout/ai/combat/explosion.inc"
#include "generated/data/fallout/ai/combat/explosion_o2_nood_variant.inc"
#include "generated/data/fallout/ai/combat/explosion_o2_variant.inc"
#include "generated/data/fallout/ai/combat/explosion_o2_variant_od_noo2_variant.inc"
