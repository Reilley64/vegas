
// src/fallout/ai/combat/explosion_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/fallout/ai/combat/explosion.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/fallout/ai/combat/explosion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/explosion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/BSFadeNode.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/Cl537.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00422220_shell.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_00477950_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004fb810_shell.h"
#include "fnv/decl/FUN_004fb970_class.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00622570_Class.h"
#include "fnv/decl/FUN_00644930_shell.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_009acd00_Class.h"
#include "fnv/decl/FUN_009b1260_Class.h"
#include "fnv/decl/FUN_009d9f40_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00c9c390_Class.h"
#include "fnv/decl/FUN_00cbc920.h"
#include "fnv/decl/HandlerView.h"
#include "fnv/decl/Host096d450.h"
#include "fnv/decl/ImageSpaceModifierInstanceForm.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MagicItem.h"
#include "fnv/decl/MagicTarget.h"
#include "fnv/decl/NiObject.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/decl/S_009b13a0_Cls.h"
#include "fnv/decl/ScriptList.h"
#include "fnv/decl/SoundPlayback.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/This_2.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_0054ca90__Cell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00932a00__FUN_00932a00_t.h"
#include "fnv/decl/fnv_00932b70__FUN_00932b70_shell.h"
#include "fnv/decl/fnv_009b2940__WaterActor.h"
#include "fnv/decl/hkpEntityC9C.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b2000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00689000.h"
#include "fnv/symbols_008d1000.h"
#include "fnv/symbols_009ad000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00c9c000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011b2000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01204000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
struct ActorCause
{
};
struct NiPointer
{
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
struct NavMesh;
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
struct BSOcclusionPlane
{
    int IsNotCulled();
};
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
struct FUN_009afc50_shell
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    NavMesh* FUN_009afc30();
};
void __cdecl FUN_009ac940(void*);
struct FUN_009ac910_shell
{
    void FUN_009ac940();
    void* FUN_009ac910(unsigned int flags);
};
struct FUN_00cbc920_shell
{
};
struct StandIn
{
    void* FUN_009ae250(unsigned int);
};
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
void __cdecl FUN_009afbe0(void* a1);
struct H00622570
{
};
struct S009afc70
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    void* FUN_009afc70(void*);
};
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
struct TESDataHandler
{
};
struct FUN_009b0d30_shell
{
    void FUN_00c9c1d0();
    void FUN_009b0d30(int);
};
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
struct Actor
{
    bool FUN_00565690();
public:
    ::TESActorBase *GetActorBase();
};
struct Standin77900
{
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
struct FUN_009ae0f0
{
    char _pad[8];
    float m8;
    float mC;
    float m10;
    float m14;
    FUN_009ae0f0();
};
void* __cdecl operator new(unsigned int);
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
struct FUN_009ac550_cls : Standin77900
{
    char _pad[0x8b];
    float m_8C;
    float GetEffectiveValue();
};
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
struct FUN_009afca0_holder
{
    void InvokeCallback(void* param);
};
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
    int* FindEntryResultByCategory(int category);
};
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
struct GlobalObject_00633c90
{
    GlobalObject_00633c90(int v);
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
// FUN_009b2790 v01 - worker7 data round
struct BGSLoadFormBuffer;
struct MobileObject
{
    virtual void Revert(BGSLoadFormBuffer* apBuffer);
};
struct AC_0042f730;
struct Holder0042f780
{
    int m_00;
    Holder0042f780* FUN_0042f780(AC_0042f730* p);
};
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
struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
public:
    bool FUN_004390c0(const ::NiPoint3 &);
public:
    float GetLengthSquared();
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};
struct MatrixWater
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    MatrixWater();
};
struct AutoMemContext
{
    int context;
    AutoMemContext(int, bool, const char*, int);
    ~AutoMemContext();
};
struct SaveX
{
};
struct HighProcess
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
struct ImageSpaceEffectParam
{
    float r, g, b, a;
    ImageSpaceEffectParam(float, float, float, float);
};

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

#include <math.h>
#include <xmmintrin.h>
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
        return normal.value.m128_f32[2];
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
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14;
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

            result.value.m128_f32[0] = (float)(force.x) * DAT_01268428;

            result.value.m128_f32[1] = force.y * DAT_01268428;

            result.value.m128_f32[2] = force.z * DAT_01268428;

            result.value.m128_f32[3] = 0;

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

#include "generated/data/fallout/ai/combat/explosion_o2_nood_variant.inc"
