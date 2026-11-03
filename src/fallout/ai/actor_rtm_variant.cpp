// src/fallout/ai/actor_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/actor.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C8DAC0Owner.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Dummy8879d0.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_00491180_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_00494710_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/FUN_00644a50_shell.h"
#include "fnv/decl/FUN_006d2c20_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087eeb0_shell.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_00884f80_shell.h"
#include "fnv/decl/FUN_00887a10_cls.h"
#include "fnv/decl/FUN_00887a80_Class.h"
#include "fnv/decl/FUN_00887ac0_class.h"
#include "fnv/decl/FUN_0088e0f0_shell.h"
#include "fnv/decl/FUN_008b70d0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_0096d490_shell.h"
#include "fnv/decl/FUN_0098adb0_shell.h"
#include "fnv/decl/FUN_009a1260_Class.h"
#include "fnv/decl/FUN_009c8d60_t.h"
#include "fnv/decl/InventoryChanges.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Manager.h"
#include "fnv/decl/NonActorMagicTarget.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/RagdollCtl.h"
#include "fnv/decl/RefVolAccum.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S0087ab50.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/ThisStub.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/bhkRigidBody_shell.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00494390__MovementAnimation.h"
#include "fnv/decl/fnv_004955c0__FUN_004955c0_t.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_00561580__FUN_00561580_Class.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00810610__FUN_00810610_Class.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_00886b30__A_00886b30.h"
#include "fnv/decl/fnv_00887af0__FUN_00887af0_class.h"
#include "fnv/decl/fnv_00887b40__FUN_00887b40_Class.h"
#include "fnv/decl/fnv_00895110__PickActor.h"
#include "fnv/decl/fnv_0089f580__ActorStub.h"
#include "fnv/decl/fnv_008b00c0__MobileObjectStandIn.h"
#include "fnv/decl/fnv_008be940__FloatValueProvider.h"
#include "fnv/decl/fnv_00932a00__FUN_00932a00_t.h"
#include "fnv/decl/fnv_00937c60__ModifierList_h.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00533000.h"
#include "fnv/symbols_00552000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b9000.h"
#include "fnv/symbols_005c5000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00621000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_007d1000.h"
#include "fnv/symbols_0087e000.h"
#include "fnv/symbols_00884000.h"
#include "fnv/symbols_00887000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00b4f000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c6c000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_00c9b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "Actor.h"

#include <xmmintrin.h>
namespace ActorUpdate3D {

struct NiPoint3
{
    float x, y, z;
    NiPoint3();
    NiPoint3(float afX, float afY, float afZ);
};

struct ThreeByThreeMatrix
{
    float m[9];
    ThreeByThreeMatrix();
    NiPoint3 FUN_004b4500(const NiPoint3& arPoint) const;
};

struct NiBound
{
    float fData[4];
};

struct AlignedRotation
{
    __m128 vec;
    AlignedRotation(float afA, float afB, float afC, float afD);
};

struct FormType
{
    int iData;
    FormType();
};

struct HandleRef
{
    int iData;
    HandleRef();
};

struct NiObject
{
};

struct NiNode
{
    virtual void vn000();
    virtual void vn001();
    virtual void vn002();
    virtual void vn003();
    virtual NiObject* FUN_vt10();
};

struct NiAVObject
{
};

struct ProfileMarker
{
};

struct Clock
{
};

struct ActorList
{
};

struct CombatController
{
};

struct Process
{
    virtual void vp000();
    virtual void vp001();
    virtual void vp002();
    virtual void vp003();
    virtual void vp004();
    virtual void vp005();
    virtual void vp006();
    virtual void vp007();
    virtual void vp008();
    virtual void vp009();
    virtual void FUN_vt28();
    virtual void vp00b();
    virtual void vp00c();
    virtual void vp00d();
    virtual void vp00e();
    virtual void vp00f();
    virtual void vp010();
    virtual void vp011();
    virtual void vp012();
    virtual void vp013();
    virtual void vp014();
    virtual void vp015();
    virtual void vp016();
    virtual void vp017();
    virtual void vp018();
    virtual void vp019();
    virtual void vp01a();
    virtual void vp01b();
    virtual void vp01c();
    virtual void vp01d();
    virtual void vp01e();
    virtual void vp01f();
    virtual void vp020();
    virtual void vp021();
    virtual void vp022();
    virtual void vp023();
    virtual void vp024();
    virtual void vp025();
    virtual void vp026();
    virtual void vp027();
    virtual void vp028();
    virtual void vp029();
    virtual void vp02a();
    virtual void vp02b();
    virtual void vp02c();
    virtual void vp02d();
    virtual void vp02e();
    virtual void vp02f();
    virtual void vp030();
    virtual void vp031();
    virtual void vp032();
    virtual void vp033();
    virtual void vp034();
    virtual void vp035();
    virtual void vp036();
    virtual void vp037();
    virtual void vp038();
    virtual void vp039();
    virtual void vp03a();
    virtual void vp03b();
    virtual void vp03c();
    virtual void vp03d();
    virtual void vp03e();
    virtual void vp03f();
    virtual void vp040();
    virtual void vp041();
    virtual void vp042();
    virtual void vp043();
    virtual void vp044();
    virtual void vp045();
    virtual void vp046();
    virtual void vp047();
    virtual void vp048();
    virtual void vp049();
    virtual void vp04a();
    virtual void vp04b();
    virtual void vp04c();
    virtual void vp04d();
    virtual void vp04e();
    virtual void vp04f();
    virtual void vp050();
    virtual void vp051();
    virtual void vp052();
    virtual void vp053();
    virtual void vp054();
    virtual void vp055();
    virtual void vp056();
    virtual void vp057();
    virtual void vp058();
    virtual void vp059();
    virtual void vp05a();
    virtual void vp05b();
    virtual void vp05c();
    virtual void vp05d();
    virtual void vp05e();
    virtual void vp05f();
    virtual void vp060();
    virtual void vp061();
    virtual void vp062();
    virtual void vp063();
    virtual void vp064();
    virtual void vp065();
    virtual void vp066();
    virtual void vp067();
    virtual void vp068();
    virtual void vp069();
    virtual void vp06a();
    virtual void vp06b();
    virtual void vp06c();
    virtual void vp06d();
    virtual void vp06e();
    virtual void vp06f();
    virtual void vp070();
    virtual void vp071();
    virtual void vp072();
    virtual void vp073();
    virtual void vp074();
    virtual void vp075();
    virtual void vp076();
    virtual void vp077();
    virtual void vp078();
    virtual void vp079();
    virtual void vp07a();
    virtual void vp07b();
    virtual void vp07c();
    virtual void vp07d();
    virtual void vp07e();
    virtual void vp07f();
    virtual void vp080();
    virtual void vp081();
    virtual void vp082();
    virtual void vp083();
    virtual void vp084();
    virtual void vp085();
    virtual void vp086();
    virtual void vp087();
    virtual void vp088();
    virtual void vp089();
    virtual void vp08a();
    virtual void vp08b();
    virtual void vp08c();
    virtual void vp08d();
    virtual void vp08e();
    virtual void vp08f();
    virtual void vp090();
    virtual void vp091();
    virtual void vp092();
    virtual void vp093();
    virtual void vp094();
    virtual void vp095();
    virtual void vp096();
    virtual void vp097();
    virtual void vp098();
    virtual void vp099();
    virtual void vp09a();
    virtual void vp09b();
    virtual void vp09c();
    virtual void vp09d();
    virtual void vp09e();
    virtual void vp09f();
    virtual void vp0a0();
    virtual void vp0a1();
    virtual void vp0a2();
    virtual CombatController* FUN_vt28c();
};

struct Holder
{
    virtual void vh000();
    virtual void vh001();
    virtual void vh002();
    virtual void vh003();
    virtual void vh004();
    virtual void vh005();
    virtual void vh006();
    virtual void vh007();
    virtual int FUN_vt20();
    virtual bool FUN_vt24(NiPoint3* apPos);
};

struct PathMover
{
};

struct LookTarget
{
};

struct CameraNode
{
};

struct LodManager
{
};

struct BaseForm
{
    int FUN_00401170();
};

struct Havok
{
};

struct Ragdoll
{
};

struct AnimSequence
{
};

struct AnimController
{
};

struct ListNode;

struct ChildPtr
{
};

struct ListNode
{
};

struct ShaderProp
{
};

struct ShaderData
{
};

struct PropertyHolder
{
    virtual void vr000();
    virtual void vr001();
    virtual void vr002();
    virtual void vr003();
    virtual void vr004();
    virtual void vr005();
    virtual void vr006();
    virtual void vr007();
    virtual void vr008();
    virtual void vr009();
    virtual void vr00a();
    virtual void vr00b();
    virtual void vr00c();
    virtual void vr00d();
    virtual void vr00e();
    virtual void vr00f();
    virtual void vr010();
    virtual ShaderProp* FUN_vt44();
};

struct FaceProp
{
};

struct GeomData
{
    virtual void vz000();
    virtual void vz001();
    virtual void vz002();
    virtual void vz003();
    virtual void vz004();
    virtual void vz005();
    virtual void vz006();
    virtual void vz007();
    virtual void vz008();
    virtual void vz009();
    virtual void vz00a();
    virtual void vz00b();
    virtual void vz00c();
    virtual void vz00d();
    virtual void vz00e();
    virtual void vz00f();
    virtual void vz010();
    virtual void vz011();
    virtual void vz012();
    virtual void vz013();
    virtual void vz014();
    virtual void vz015();
    virtual void vz016();
    virtual void vz017();
    virtual void vz018();
    virtual void vz019();
    virtual void vz01a();
    virtual void vz01b();
    virtual void vz01c();
    virtual void vz01d();
    virtual void vz01e();
    virtual void vz01f();
    virtual void vz020();
    virtual void vz021();
    virtual void vz022();
    virtual void vz023();
    virtual void vz024();
    virtual int FUN_vt94();
    FormType FUN_0043b4f0();
};

struct Geometry
{
};

struct FaceAnim
{
};

struct Actor;

extern Clock DAT_011f6394;

NiAVObject* __cdecl FUN_004ade00(NiNode* apRoot, const char* apName);
NiPoint3 __cdecl FUN_004a3760(float afScale, const NiPoint3& arPoint);

struct Actor
{
    virtual void va000();
    virtual void va001();
    virtual void va002();
    virtual void va003();
    virtual void va004();
    virtual void va005();
    virtual void va006();
    virtual void va007();
    virtual void va008();
    virtual void va009();
    virtual void va00a();
    virtual void va00b();
    virtual void va00c();
    virtual void va00d();
    virtual void va00e();
    virtual void va00f();
    virtual void va010();
    virtual void va011();
    virtual void FUN_vt48(int aiFlags);
    virtual void va013();
    virtual void va014();
    virtual void va015();
    virtual void va016();
    virtual void va017();
    virtual void va018();
    virtual void va019();
    virtual void va01a();
    virtual void va01b();
    virtual void va01c();
    virtual void va01d();
    virtual void va01e();
    virtual void va01f();
    virtual void va020();
    virtual void va021();
    virtual void va022();
    virtual void va023();
    virtual void va024();
    virtual void va025();
    virtual void va026();
    virtual void va027();
    virtual void va028();
    virtual void va029();
    virtual void va02a();
    virtual void va02b();
    virtual void va02c();
    virtual void va02d();
    virtual void va02e();
    virtual void va02f();
    virtual void va030();
    virtual void va031();
    virtual void va032();
    virtual void va033();
    virtual void va034();
    virtual void va035();
    virtual void va036();
    virtual void va037();
    virtual void va038();
    virtual void va039();
    virtual void va03a();
    virtual void va03b();
    virtual void va03c();
    virtual void va03d();
    virtual void va03e();
    virtual void va03f();
    virtual void va040();
    virtual void va041();
    virtual void va042();
    virtual void va043();
    virtual void va044();
    virtual void va045();
    virtual void va046();
    virtual void va047();
    virtual void va048();
    virtual void va049();
    virtual void va04a();
    virtual void va04b();
    virtual void va04c();
    virtual void va04d();
    virtual void va04e();
    virtual void va04f();
    virtual void va050();
    virtual void va051();
    virtual void va052();
    virtual void va053();
    virtual void va054();
    virtual void va055();
    virtual void va056();
    virtual void va057();
    virtual void va058();
    virtual void va059();
    virtual void va05a();
    virtual void va05b();
    virtual void va05c();
    virtual void va05d();
    virtual void va05e();
    virtual void va05f();
    virtual void va060();
    virtual void va061();
    virtual void va062();
    virtual void va063();
    virtual void va064();
    virtual void va065();
    virtual void va066();
    virtual void va067();
    virtual void va068();
    virtual void va069();
    virtual void va06a();
    virtual void va06b();
    virtual void va06c();
    virtual void va06d();
    virtual void va06e();
    virtual void va06f();
    virtual void va070();
    virtual void va071();
    virtual void va072();
    virtual void va073();
    virtual NiNode* FUN_vt1d0();
    virtual void va075();
    virtual void va076();
    virtual void va077();
    virtual void va078();
    virtual AnimController* FUN_vt1e4();
    virtual void va07a();
    virtual void va07b();
    virtual void va07c();
    virtual NiPoint3* FUN_vt1f4();
    virtual void va07e();
    virtual void va07f();
    virtual void va080();
    virtual void va081();
    virtual void va082();
    virtual void va083();
    virtual void va084();
    virtual void va085();
    virtual void va086();
    virtual void va087();
    virtual void va088();
    virtual void va089();
    virtual void va08a();
    virtual bool FUN_vt22c(int aiValue);
    virtual void va08c();
    virtual void va08d();
    virtual void va08e();
    virtual void va08f();
    virtual void va090();
    virtual void va091();
    virtual void va092();
    virtual void va093();
    virtual void FUN_vt250(float afDelta, NiPoint3* apPos, int aiValue);
    virtual void va095();
    virtual void va096();
    virtual void va097();
    virtual void va098();
    virtual void va099();
    virtual void va09a();
    virtual void va09b();
    virtual void va09c();
    virtual void va09d();
    virtual void va09e();
    virtual void va09f();
    virtual void va0a0();
    virtual void va0a1();
    virtual void va0a2();
    virtual void va0a3();
    virtual void va0a4();
    virtual void va0a5();
    virtual void va0a6();
    virtual void va0a7();
    virtual void FUN_vt2a0();
    virtual void va0a9();
    virtual void va0aa();
    virtual void va0ab();
    virtual void va0ac();
    virtual void va0ad();
    virtual void va0ae();
    virtual float FUN_vt2bc(int aiValue);
    virtual void va0b0();
    virtual void va0b1();
    virtual void va0b2();
    virtual void va0b3();
    virtual void va0b4();
    virtual void va0b5();
    virtual void va0b6();
    virtual void va0b7();
    virtual void va0b8();
    virtual void va0b9();
    virtual void va0ba();
    virtual void va0bb();
    virtual void va0bc();
    virtual void va0bd();
    virtual void va0be();
    virtual void va0bf();
    virtual void va0c0();
    virtual void va0c1();
    virtual void va0c2();
    virtual void va0c3();
    virtual void va0c4();
    virtual void va0c5();
    virtual void va0c6();
    virtual void va0c7();
    virtual void va0c8();
    virtual void va0c9();
    virtual void va0ca();
    virtual void va0cb();
    virtual void va0cc();
    virtual void va0cd();
    virtual void va0ce();
    virtual void va0cf();
    virtual void va0d0();
    virtual void va0d1();
    virtual void va0d2();
    virtual void va0d3();
    virtual void va0d4();
    virtual void va0d5();
    virtual void va0d6();
    virtual void va0d7();
    virtual void va0d8();
    virtual void va0d9();
    virtual void va0da();
    virtual void va0db();
    virtual void va0dc();
    virtual void va0dd();
    virtual void va0de();
    virtual void va0df();
    virtual void va0e0();
    virtual void va0e1();
    virtual void va0e2();
    virtual bool FUN_vt38c();
    virtual void va0e4();
    virtual void va0e5();
    virtual void va0e6();
    virtual void va0e7();
    virtual void va0e8();
    virtual void va0e9();
    virtual void va0ea();
    virtual void va0eb();
    virtual void va0ec();
    virtual void va0ed();
    virtual void va0ee();
    virtual void va0ef();
    virtual void va0f0();
    virtual void va0f1();
    virtual void va0f2();
    virtual void va0f3();
    virtual void va0f4();
    virtual void va0f5();
    virtual void va0f6();
    virtual void va0f7();
    virtual void va0f8();
    virtual void va0f9();
    virtual void va0fa();
    virtual void va0fb();
    virtual void va0fc();
    virtual void va0fd();
    virtual void va0fe();
    virtual void va0ff();
    virtual void va100();
    virtual void va101();
    virtual void va102();
    virtual void va103();
    virtual void va104();
    virtual void va105();
    virtual void va106();
    virtual void va107();
    virtual void va108();
    virtual void va109();
    virtual void va10a();
    virtual void va10b();
    virtual void va10c();
    virtual void va10d();
    virtual void va10e();
    virtual void va10f();
    virtual void va110();
    virtual void va111();
    virtual void va112();
    virtual void va113();
    virtual void va114();
    virtual void va115();
    virtual void va116();
    virtual void va117();
    virtual void va118();
    virtual void va119();
    virtual void va11a();
    virtual void va11b();
    virtual void va11c();
    virtual void va11d();
    virtual void va11e();
    virtual void va11f();
    virtual void va120();
    virtual void va121();
    virtual void va122();
    virtual void va123();
    virtual void va124();
    virtual void va125();
    virtual void va126();
    virtual void va127();
    virtual void va128();
    virtual void va129();
    virtual void va12a();
    virtual void va12b();
    virtual void va12c();
    virtual bool FUN_vt4b4();
    char pad04[0x20];
    float fScale24;
    char pad28[0x40];
    Process* pProcess;
    char pad6C[0x40];
    Havok* pHavok;
    Ragdoll* pRagdoll;
    char padB4[0x64];
    bool bResetPose;
    char pad119[0x77];
    Holder* pHolder;
    char pad194[4];

    int FUN_00931850();
    HandleRef FUN_00931ed0();
    void FUN_00886cb0(float afDelta, int aiUnused);
};

// @fnv 0x00886cb0
void Actor::FUN_00886cb0(float afDelta, int aiUnused)
{
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::ActorUpdate3D::ProfileMarker *>(&::g_011df69e))))->ClearData();
    float fTimeSinceScaleStart = afDelta;
    if (fTimeSinceScaleStart == ::_DAT_01012060 && !FUN_00931850())
    {
        if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::ActorUpdate3D::ActorList *>(&::g_011f2250))))->GetName())) == 4 && this == (*reinterpret_cast<::ActorUpdate3D::Actor * *>(&::DAT_011f21cc)))
            fTimeSinceScaleStart = reinterpret_cast<::Twin_0084d030 *>(&(DAT_011f6394))->GetStoredFloatValue() * reinterpret_cast<::FUN_009c8d60_t *>(&((*reinterpret_cast<::ActorUpdate3D::ActorList *>(&::g_011f2250))))->FUN_009c8d60();
        else
            fTimeSinceScaleStart = reinterpret_cast<::Twin_0084d030 *>(&(DAT_011f6394))->GetStoredFloatValue();
    }
    ::UpdateFlag800State((::Actor *)this);
    if (this != (*reinterpret_cast<::ActorUpdate3D::Actor * *>(&::_g_thePlayer)))
    {
        NiPoint3 kTarget = (*reinterpret_cast<::ActorUpdate3D::NiPoint3 *>((void *)&::NiPoint3::ZERO));
        int iTargetFlags = 0;
        if (!FUN_vt4b4() && !reinterpret_cast<::fnv_00886b30::A_00886b30 *>(this)->PlaceAtPosition((::fnv_00886b30::Pt3_00886b30 *)(::ActorUpdate3D::NiPoint3 *)(&kTarget)))
        {
            iTargetFlags = pHolder->FUN_vt20();
            if (!pHolder->FUN_vt24(&kTarget))
            {
                PathMover* pMover = ((::ActorUpdate3D::PathMover *)(reinterpret_cast<::FUN_008b70d0_shell *>(this)->FUN_008b70d0()));
                if (pMover)
                    reinterpret_cast<::fnv_00494390::MovementAnimation *>((pMover))->GetMovement((::fnv_00494390::MotionPoint *)(::ActorUpdate3D::NiPoint3 *)(&kTarget), (::fnv_00494390::MotionActor *)(void *)(this), 0, 1);
            }
        }
        LookTarget* pLook = ((::ActorUpdate3D::LookTarget *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
        if (pLook && ::FUN_00450ff0((void *)(pLook)) && !reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::ActorUpdate3D::Actor * *>(&::_g_thePlayer))))->IsSleepingOrResting())
        {
            FUN_vt250(fTimeSinceScaleStart, &kTarget, iTargetFlags);
        }
        else
        {
            ThreeByThreeMatrix kRotate;
            reinterpret_cast<::FUN_004a0c90_shell *>(&(kRotate))->FUN_004a0c90(((::ActorUpdate3D::NiPoint3 *)(reinterpret_cast<::TESRecipe *>(this)->GetData()))->z);
            reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)&(const ::ActorUpdate3D::NiPoint3 &)((*(::ActorUpdate3D::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(FUN_vt1f4()))->ProjectileLaunched((::NiPoint3 *)&(const ::ActorUpdate3D::NiPoint3 &)(kRotate.FUN_004b4500(kTarget)), {})))));
        }
    }
    if (((bool)(reinterpret_cast<::FUN_00493bb0_Class *>(this)->FUN_00493bb0())))
        reinterpret_cast<::fnv_008b00c0::MobileObjectStandIn *>(this)->UpdateControllerFlag();
    CombatController* pCombat = pProcess ? pProcess->FUN_vt28c() : 0;
    if (this != (*reinterpret_cast<::ActorUpdate3D::Actor * *>(&::_g_thePlayer)))
    {
        NiNode* p3D = FUN_vt1d0();
        if (this != (*reinterpret_cast<::ActorUpdate3D::Actor * *>(&::_g_thePlayer)) && p3D)
        {
            NiPoint3 kCameraPos;
            if (reinterpret_cast<::FUN_004eaf60_shell *>(((*reinterpret_cast<::ActorUpdate3D::Actor * *>(&::_g_thePlayer))))->FUN_004eaf60() && (*reinterpret_cast<::ActorUpdate3D::CameraNode * *>(&::DAT_011e07d4)))
                kCameraPos = *((::ActorUpdate3D::NiPoint3 *)(::FUN_0045bb80((int)((*reinterpret_cast<::ActorUpdate3D::CameraNode * *>(&::DAT_011e07d4))))));
            else if ((*reinterpret_cast<::ActorUpdate3D::CameraNode * *>(&::DAT_011e07d0)))
                kCameraPos = *((::ActorUpdate3D::NiPoint3 *)(::FUN_0045bb80((int)((*reinterpret_cast<::ActorUpdate3D::CameraNode * *>(&::DAT_011e07d0))))));
            else
                kCameraPos = (*(::ActorUpdate3D::NiPoint3 *)(reinterpret_cast<::Point3Offset *>((void *)(((::ActorUpdate3D::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>(((*reinterpret_cast<::ActorUpdate3D::Actor * *>(&::_g_thePlayer))))->GetAddTopicList()))))->ProjectileLaunched(
                    (::NiPoint3 *)&(const ::ActorUpdate3D::NiPoint3 &)(FUN_004a3760(reinterpret_cast<::fnv_008be940::FloatValueProvider *>(((*reinterpret_cast<::ActorUpdate3D::Actor * *>(&::_g_thePlayer))))->FUN_008be940(), (*reinterpret_cast<::ActorUpdate3D::NiPoint3 *>((void *)&::DAT_011a9484)))), {})));
            NiBound kBound = *((::ActorUpdate3D::NiBound *)(reinterpret_cast<::FUN_0043d450_Owner *>((p3D))->FUN_0043d450()));
            float fDistance =
                reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::ActorUpdate3D::NiPoint3 &)((*(::ActorUpdate3D::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kCameraPos))->FUN_00439ef0((::NiPoint3 *)&(*((::ActorUpdate3D::NiPoint3 *)(new ((void *)&(kBound)) ::Vec3()))), *(const ::NiPoint3 *)nullptr)))))->ComputeMagnitude() - reinterpret_cast<::Twin_0084d030 *>(&(kBound))->GetStoredFloatValue() * ::DAT_01021798;
            bool bFar = false;
            NiObject* pFade = p3D->FUN_vt10();
            if (pFade)
            {
                float fRatio = fDistance / ::FUN_007d1d00(3);
                bFar = fRatio > reinterpret_cast<::FUN_006d2c20_Class *>((pFade))->GetFloatAtOffsetB0();
            }
            LodManager* pLod = ((::ActorUpdate3D::LodManager *)(::FUN_00b4f5c0()));
            if (pLod && ((int)(::GetStringAtOffset13C((const char *)(pLod)))))
            {
                bool bVisible = bFar ? false : fDistance > ::_DAT_01012060;
                reinterpret_cast<::RefVolAccum *>((pLod))->UpdateOrAddItem(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0(), (const ::RefVolSrc *)(::ActorUpdate3D::NiBound *)(&kBound), bVisible);
            }
            if (pCombat)
                reinterpret_cast<::Dummy8879d0 *>((pCombat))->FUN_008879d0(bFar);
        }
    }
    if (pCombat)
        reinterpret_cast<::fnv_00810610::FUN_00810610_Class *>((pCombat))->FUN_00810610(((bool)(::FUN_00525420())));
    if (bResetPose && ((int)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())))
    {
        NiNode* pRoot = ((::ActorUpdate3D::NiNode *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()));
        if (pRoot)
        {
            bool bUpright = true;
            Actor* pCreature = 0;
            if (((::ActorUpdate3D::BaseForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))->FUN_00401170() == 0x2b)
                pCreature = this;
            if (pCreature && !pCreature->FUN_vt38c())
                bUpright = false;
            if (pHavok && ::FUN_00552490((bool *)(pHavok)))
                reinterpret_cast<::RagdollCtl *>((pHavok))->FUN_00c7c150(1);
            if (pRagdoll)
                reinterpret_cast<::Manager *>((pRagdoll))->FUN_00ca2ad0(pRoot, ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((void *)&(const ::ActorUpdate3D::HandleRef &)(FUN_00931ed0()))->FUN_004a3a20())));
            reinterpret_cast<::Actor *>(this)->SetActorLifeState((::ACTOR_LIFE_STATE)(1));
            FUN_vt2a0();
            if (bUpright)
            {
                ThreeByThreeMatrix kHeading;
                reinterpret_cast<::FUN_004a0c90_shell *>(&(kHeading))->FUN_004a0c90(FUN_vt2bc(0));
                NiPoint3 kForward(0.0f, 1.0f, 0.0f);
                kForward = kHeading.FUN_004b4500(kForward);
                ::FUN_00c9b670((::NiAVObject *)(pRoot), (*(const ::NiPoint3 *)(&kForward)), 1, 0.0f, 0);
                FUN_vt48(4);
                pProcess->FUN_vt28();
            }
            else
            {
                AnimController* pAnim = FUN_vt1e4();
                if (pAnim && reinterpret_cast<::FUN_00494710_shell *>((pAnim))->FUN_00494710(0xe0))
                {
                    reinterpret_cast<::fnv_004955c0::FUN_004955c0_t *>((pAnim))->FUN_004955c0(0x14, 0xe0, -1, 0.0f, -1);
                    AnimSequence* pSequence = ((::ActorUpdate3D::AnimSequence *)(reinterpret_cast<::FUN_00491040_shell *>((pAnim))->FUN_00491040(1)));
                    if (pSequence)
                    {
                        reinterpret_cast<::FUN_0098adb0_shell *>((pSequence))->FUN_0098adb0(reinterpret_cast<::FUN_00508100_shell *>((pSequence))->FUN_00508100());
                        reinterpret_cast<::FUN_00491180_shell *>((pAnim))->FUN_00491180((::TESObjectREFR *)(void *)(this), 0.0f, reinterpret_cast<::FUN_00508100_shell *>((pSequence))->FUN_00508100());
                        reinterpret_cast<::ThisStub *>((pAnim))->FUN_00493900(this);
                    }
                    reinterpret_cast<::fnv_0089f580::ActorStub *>(this)->TryMakeTargetThing();
                }
            }
            bResetPose = false;
        }
    }
    if (reinterpret_cast<::FUN_0087eeb0_shell *>(this)->FUN_0087eeb0() && !FUN_vt22c(0) && !((bool)(reinterpret_cast<::FUN_00437bd0_stub *>(this)->FUN_00437bd0())))
    {
        NiNode* pFaceRoot = FUN_vt1d0();
        NiAVObject* pObject = FUN_004ade00(pFaceRoot, ((const char *)(::FUN_0087e9a0())));
        bool bChanged = false;
        if (pObject)
        {
            int iObject = ((int)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((pObject))->FUN_006838b0()));
            Geometry* m_pShaderGeometry = (Geometry*)((void *)(::FUN_00653270((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_01267e64))), (::NiObject *)(((int)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((pObject))->FUN_006838b0()))))));
            if (m_pShaderGeometry)
            {
                GeomData* pData = ((::ActorUpdate3D::GeomData *)(::fnv_006fa820::FUN_006fa820((const char *)(m_pShaderGeometry))));
                ListNode* pIter = ((::ActorUpdate3D::ListNode *)(reinterpret_cast<::NonActorMagicTarget *>((pData))->GetActiveEffectList()));
                int iSkin = reinterpret_cast<::bhkRigidBody_shell *>((pData))->FUN_00517630();
                if (!((bool)(::FUN_00c8cce0(&iSkin))))
                {
                    ::FUN_00c6a350((::NiAVObject *)(pObject), 1, 1, 1, 1);
                    int iNewSkin = ((int)(::FUN_00621480((::HighProcess *)(pData->FUN_vt94()))));
                    reinterpret_cast<::C8DAC0Owner *>((pData))->UpdateMatchingNodes((void *)(iNewSkin));
                    bChanged = true;
                }
                FormType kType = pData->FUN_0043b4f0();
                if (reinterpret_cast<::FUN_0043b4d0_shell *>(&(kType))->FUN_0043b4d0() == 0x1d)
                    ::FUN_00c804d0((::WalkNode_c804 *)(pFaceRoot), 8);
                reinterpret_cast<::fnv_00561580::FUN_00561580_Class *>((pData))->FUN_00561580(1);
                while (pIter && ((::ActorUpdate3D::NiAVObject *)(::FUN_00559450((int *)(((::ActorUpdate3D::ChildPtr *)(new ((void *)(pIter)) ::Vec3())))))))
                {
                    FaceProp* pFace =
                        (FaceProp*)((void *)(::FUN_00653270((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_012683ec))), (::NiObject *)((int)((::ActorUpdate3D::NiAVObject *)(::FUN_00559450((int *)(((::ActorUpdate3D::ChildPtr *)(new ((void *)(pIter)) ::Vec3()))))))))));
                    if (pFace)
                    {
                        float fDesiredHeadingAngle = FUN_vt2bc(0);
                        AlignedRotation kRotationBasis(::FUN_005c53d0(fDesiredHeadingAngle), ::FUN_005b9e80(fDesiredHeadingAngle), 0.0f, 0.0f);
                        reinterpret_cast<::fnv_00887b40::FUN_00887b40_Class *>((pFace))->ForwardToScriptLocals(1);
                        reinterpret_cast<::fnv_00887af0::FUN_00887af0_class *>((pFace))->FUN_00887af0(&kRotationBasis);
                        break;
                    }
                    pIter = ((::ActorUpdate3D::ListNode *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
                }
                if (::FUN_008c7aa0())
                    reinterpret_cast<::S0087ab50 *>((((::ActorUpdate3D::FaceAnim *)(::TaskQueueInterface::GetSingleton()))))->SetPairIfEnabled({}, {});
                else
                    ::SetTlsValueAndReset((int)(pObject), 2);
            }
        }
        pObject = FUN_004ade00(pFaceRoot, ((const char *)(::FUN_00887a00())));
        if (pObject)
        {
            int iObject = ((int)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((pObject))->FUN_006838b0()));
            Geometry* m_pShaderGeometry = (Geometry*)((void *)(::FUN_00653270((const ::NiRTTI *)(int *)(&(*reinterpret_cast<int *>(&::g_01267e64))), (::NiObject *)(((int)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((pObject))->FUN_006838b0()))))));
            if (m_pShaderGeometry)
            {
                GeomData* pData = ((::ActorUpdate3D::GeomData *)(::fnv_006fa820::FUN_006fa820((const char *)(m_pShaderGeometry))));
                ListNode* pIter = ((::ActorUpdate3D::ListNode *)(reinterpret_cast<::NonActorMagicTarget *>((pData))->GetActiveEffectList()));
                int iSkin = reinterpret_cast<::bhkRigidBody_shell *>((pData))->FUN_00517630();
                if (!((bool)(::FUN_00c8cce0(&iSkin))))
                {
                    ::FUN_00c6a350((::NiAVObject *)(pObject), 1, 1, 1, 1);
                    int iNewSkin = ((int)(::FUN_00621480((::HighProcess *)(pData->FUN_vt94()))));
                    reinterpret_cast<::C8DAC0Owner *>((pData))->UpdateMatchingNodes((void *)(iNewSkin));
                    bChanged = true;
                }
                FormType kType = pData->FUN_0043b4f0();
                if (reinterpret_cast<::FUN_0043b4d0_shell *>(&(kType))->FUN_0043b4d0() == 0x1d)
                    ::FUN_00c804d0((::WalkNode_c804 *)(pFaceRoot), 8);
                reinterpret_cast<::fnv_00561580::FUN_00561580_Class *>((pData))->FUN_00561580(1);
                while (pIter && ((::ActorUpdate3D::NiAVObject *)(::FUN_00559450((int *)(((::ActorUpdate3D::ChildPtr *)(new ((void *)(pIter)) ::Vec3())))))))
                {
                    PropertyHolder* pProps = (PropertyHolder*)((::ActorUpdate3D::NiAVObject *)(::FUN_00559450((int *)(((::ActorUpdate3D::ChildPtr *)(new ((void *)(pIter)) ::Vec3()))))));
                    ShaderProp* pShader = pProps->FUN_vt44();
                    if (pShader)
                    {
                        ShaderData* m_pSPData = ((::ActorUpdate3D::ShaderData *)(reinterpret_cast<::FUN_00887a10_cls *>((pShader))->FUN_00887a10()));
                        float fScale = fScale24;
                        ::FUN_005330e0(&fScale, reinterpret_cast<::FUN_00644a50_shell *>((m_pSPData))->FUN_00644a50(), reinterpret_cast<::FUN_009a1260_Class *>((m_pSPData))->GetFloatAt0xC8());
                        reinterpret_cast<::FUN_00887a80_Class *>((pShader))->FUN_00887a80(1);
                        reinterpret_cast<::FUN_00887ac0_class *>((pShader))->FUN_00887ac0(fScale);
                        break;
                    }
                    pIter = ((::ActorUpdate3D::ListNode *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
                }
                if (::FUN_008c7aa0())
                    reinterpret_cast<::S0087ab50 *>((((::ActorUpdate3D::FaceAnim *)(::TaskQueueInterface::GetSingleton()))))->SetPairIfEnabled({}, {});
                else
                    ::SetTlsValueAndReset((int)(pObject), 2);
            }
        }
        if (bChanged)
            FUN_vt48(4);
    }
    reinterpret_cast<::TESForm *>(&((*reinterpret_cast<::ActorUpdate3D::ProfileMarker *>(&::g_011df69e))))->ClearData();
}

}

#include <string.h>
struct P164FormType
{
    int FUN_00401170();
};

extern const char DAT_0102fdc8[];
__if_not_exists(TESActorBase::TESActorBase)
{
    struct TESActorBase : TESForm
    {
    };
}
struct P164Flags
{
    unsigned int value;
};
struct P164Buffer
{
    virtual unsigned char GetVersion();
    unsigned int FUN_008648a0();
    P164Flags FUN_00428110();
};
struct P164Item
{
    ~P164Item();
};
struct P164Inventory
{
};
TESForm* __cdecl FUN_004839c0(unsigned int);
struct P164Modifier
{
};
struct ActorListEntry
{
    float value;
    TESForm* form;
};
struct P164List
{
    void FUN_005ae3d0(ActorListEntry*&);
};
struct P164Clock
{
};
struct P164Biped
{
};
struct P164State
{
};
struct P164Actor : Actor
{
    void FUN_008ab3a0(P164Buffer*);
    void FUN_008c1ac0(bool);
    void SetFlag40000000(bool);
};
struct P164ActorVirtual
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
    virtual P164Biped* GetBipedAnimation();
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
    virtual bool IsCharacter();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool IsDead(int);
};
struct P164Mover
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
    virtual void Load(P164Buffer*);
};
struct P164Process
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
    virtual P164Item* GetLoadedForm();
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
    virtual void Update(bool);
};
// @fnv 0x008ab3a0
void P164Actor::FUN_008ab3a0(P164Buffer* buffer)
{
    int oldState = reinterpret_cast<::FUN_004f8960_shell *>((((P164State*)this)))->FUN_004f8960();
    reinterpret_cast<::fnv_00932a00::FUN_00932a00_t *>(this)->FUN_00932a00((::fnv_00932a00::BGSLoadFormBuffer *)(buffer));
    m_eLifeState = (ACTOR_LIFE_STATE)oldState;
    reinterpret_cast<::FUN_00884f80_shell *>(this)->FUN_00884f80();
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ActorConditionAndAnimationState), 4);
    ActorConditionAndAnimationState = reinterpret_cast<::FUN_0096d490_shell *>(&((*reinterpret_cast<::P164Clock *>(&::g_011e0e80))))->FUN_0096d490() - ActorConditionAndAnimationState;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ActorStateFlags), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ActorReferenceData), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bFirstActorFlag), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bActorFlag), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fFirstValueAfterFlag), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bSecondBooleanValue), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_eAnimationGroup), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bHasUpdated), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ActorReferenceListData), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ActorBaseConfiguration), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bFlagBeforeActorBase), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ActorBaseReference), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bSecondActorFlag), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_iIntegerBeforeTwoFloatValues), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&BooleanIntegerTwoFloatData), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&IntegerFloatFlagSettings), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bFirstFlagAfterForm), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bFormFlag), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bMiddleFlagBeforeActorMover), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_iPackageState), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ActorProjectileState), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bFlagBeforeTwoBooleans), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bMiddleFlag), 1);
    if (buffer->GetVersion() >= 8)
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_eCriticalStage), 4);
    if (buffer->GetVersion() >= 9)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bActorListValid), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_iIntegerAfterActorListValid), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ActorStatusData), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_uiFirstValueAfterInteger), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_uiActorFlags), 4);
        FUN_008c1ac0(false);
        SetFlag40000000(false);
    }
    if (buffer->GetVersion() >= 13)
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_uiValueBeforeBooleanFields), 4);
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(&m_pActorReference));
    m_pActorBase = dynamic_cast<TESActorBase*>(FUN_004839c0(buffer->FUN_008648a0()));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(&m_pMobileObject));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::P164Flags &)(buffer->FUN_00428110()))->FUN_004280f0(0x400))
    {
        unsigned char lifeState = 0;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&lifeState), 1);
        m_eLifeState = (ACTOR_LIFE_STATE)lifeState;
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::P164Flags &)(buffer->FUN_00428110()))->FUN_004280f0(0x80000))
    {
        unsigned int count = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60()));
        for (unsigned int i = 0; i < count; ++i)
        {
            ActorListEntry* modifier = new ActorListEntry;
            reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(&modifier->form));
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(modifier), 4);
            ((P164List*)&m_kSecondPointerList)->FUN_005ae3d0(modifier);
        }
    }
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::P164Flags &)(buffer->FUN_00428110()))->FUN_004280f0(0x800000))
        reinterpret_cast<::fnv_00937c60::ModifierList_h *>((((P164Modifier*)&m_kFirstActorData)))->LoadModifiers((::fnv_00937c60::BGSLoadFormBuffer *)(buffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::P164Flags &)(buffer->FUN_00428110()))->FUN_004280f0(0x400000))
        reinterpret_cast<::fnv_00937c60::ModifierList_h *>((((P164Modifier*)&m_kSecondActorData)))->LoadModifiers((::fnv_00937c60::BGSLoadFormBuffer *)(buffer));
    ((P164Mover*)m_pActorMover)->Load(buffer);
    if (((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0())) && m_pBaseProcess)
    {
        P164Biped* inventory = ((P164ActorVirtual*)this)->GetBipedAnimation();
        P164Inventory* biped = ((::P164Inventory *)(::InventoryChanges::CreateForReference(this)));
        if (inventory && biped)
        {
            unsigned int slots[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
            unsigned int slotCount = 19;
            for (unsigned int slot = 0; slot < slotCount; ++slot)
            {
                TESForm* current = reinterpret_cast<::FUN_0088e0f0_shell *>((inventory))->FUN_0088e0f0(slot);
                P164Item* item = ((::P164Item *)(reinterpret_cast<::Target *>((biped))->FUN_004c8c10(slot, 0)));
                TESForm* equipped = item ? ((::TESForm *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName())) : 0;
                if (current)
                {
                    if (((P164FormType*)current)->FUN_00401170() == 12)
                        current = 0;
                    else if (current->Unk_3D())
                        current = 0;
                }
                if (current != equipped)
                {
                    ((P164Process*)m_pBaseProcess)->Update(true);
                    break;
                }
                delete item;
            }
        }
        else if (biped && ((P164ActorVirtual*)this)->IsCharacter() && reinterpret_cast<::MiddleHighProcess *>(this)->IsActorInCombat() &&
                 strstr(reinterpret_cast<::FUN_0055d520_shell *>(this)->FUN_0055d520(), DAT_0102fdc8))
        {
            P164Item* weapon = ((::P164Item *)(reinterpret_cast<::Target *>((biped))->FUN_004c8c10(5, 0)));
            TESForm* weaponForm = weapon ? ((::TESForm *)(reinterpret_cast<::Twin_0044ddc0 *>((weapon))->GetName())) : 0;
            if (((P164Process*)m_pBaseProcess)->GetLoadedForm() &&
                ((::TESForm *)(reinterpret_cast<::Twin_0044ddc0 *>((((P164Process*)m_pBaseProcess)->GetLoadedForm()))->GetName())) != weaponForm)
                ((P164Process*)m_pBaseProcess)->Update(true);
        }
    }
    if (!((P164ActorVirtual*)this)->IsDead(0) && m_eCriticalStage != 0)
        m_eCriticalStage = (ACTOR_CRITICAL_STAGE)0;
}

#include "generated/data/fallout/ai/actor_rtm_variant.inc"
