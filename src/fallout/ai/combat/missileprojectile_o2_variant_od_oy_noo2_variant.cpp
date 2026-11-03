
// src/fallout/ai/combat/missileprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/combat/missileprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/missileprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/missileprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/missileprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/missileprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstdint>
#include <new>
#include "fnv/decl/A5D2C0Object.h"
#include "fnv/decl/C8DAC0Owner.h"
#include "fnv/decl/CB2FC0Object.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Class_007f68a0.h"
#include "fnv/decl/ExtraDataList.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_0045bb20_cls.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3c20.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_004a46b0_class.h"
#include "fnv/decl/FUN_004ad240_c.h"
#include "fnv/decl/FUN_004fd420_shell.h"
#include "fnv/decl/FUN_00508070_class.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_008126e0_shell.h"
#include "fnv/decl/FUN_008b42e0_shell.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_008d8b80Class.h"
#include "fnv/decl/FUN_009669c0_Class.h"
#include "fnv/decl/FUN_009b7010_shell.h"
#include "fnv/decl/FUN_009ba320_shell.h"
#include "fnv/decl/FUN_009ba3d0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00c89c80_obj.h"
#include "fnv/decl/GlobalObject_008c71b0.h"
#include "fnv/decl/ImageSpaceEffectParam.h"
#include "fnv/decl/LoadProjectile52.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/MobileObject.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/Owner89730.h"
#include "fnv/decl/P3.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Projectile.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/S0062aea0_Vector.h"
#include "fnv/decl/S50.h"
#include "fnv/decl/S_009c8c40.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/SceneC8E.h"
#include "fnv/decl/TESObjectREFR.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_dummy_476a80.h"
#include "fnv/decl/bhkRigidBody_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_005de0a0__FUN_005de0a0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00979260__Projectile.h"
#include "fnv/decl/fnv_009ba660__MissileActor.h"
#include "fnv/decl/fnv_009bf470__Ref9bf.h"
#include "fnv/decl/fnv_00cbdcb0__CBDCB0Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00491000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ad000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b4000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_009b7000.h"
#include "fnv/symbols_009c5000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_01196000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01272000.h"
struct FUN_009ba4d0_shell
{
    char const* const* GetArg1Ptr();
};
extern "C" void __cdecl FUN_00c89640(void*);
extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);
struct bhkConstraint
{
    virtual ~bhkConstraint();
    void* DestroyConstraint(unsigned int);
};
struct BGSLoadFormBuffer
{
};
struct BeamProjectile
{
};
struct MissileProjectile : BeamProjectile
{
    void FUN_009baad0(BGSLoadFormBuffer*);
};
struct BGSProjectile
{
};
struct FUN_009b7c90_shell : BGSProjectile
{
    bool FUN_009b7c90();
};
extern "C" void __cdecl _delete(void*, unsigned int);
struct bhkHingeConstraint : bhkConstraint
{
    void* FUN_009ba520(unsigned int);
};
struct TlsBlock_t
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
    int m_2b4;
};
extern __declspec(thread) TlsBlock_t g_tlsBlock;
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};
void* __cdecl FUN_00aa13e0(unsigned int size);
class OwnerBase_t
{
  public:
    OwnerBase_t();
    virtual void unkB0();
    virtual ~OwnerBase_t();
    unsigned int m_04;
    unsigned int m_08;

};
class ChainA_t : public OwnerBase_t
{
  public:
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_t()
    {
        m_0c = 0;
        ::DAT_01268188 += 1;
    }
};
class SpawnedObject_t : public ChainA_t
{
  public:
    virtual void unkD2();
    SpawnedObject_t()
    {
        ::DAT_01268434 += 1;
    }
};
struct FUN_00cbdd60_cls
{
    int unk00;
    int unk04;
    SpawnedObject_t* FUN_00cbdd60(unsigned int arg);
};
struct S_cbde40_Tls
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
};
__declspec(thread) S_cbde40_Tls g_tls_cbde40;
struct S_cbde40_Guard
{
    int saved;
    S_cbde40_Guard()
    {
        saved = (*reinterpret_cast<::S_cbde40_Tls *>(&::g_tlsBlock)).unk2B4;
        (*reinterpret_cast<::S_cbde40_Tls *>(&::g_tlsBlock)).unk2B4 = 0x10;
    }
    ~S_cbde40_Guard()
    {
        (*reinterpret_cast<::S_cbde40_Tls *>(&::g_tlsBlock)).unk2B4 = saved;
    }
};
struct S_cbde40_Pool
{
};
extern int DAT_0108ff98;
struct S_cbde40_Base
{
    int unk00;
};
struct S_cbde40_Obj
{
    int* unk00;
    S_cbde40_Base base;
    int unk08;
    int unk0c;
    int unk10;
};
struct S_cbde40
{
    int unk00;
    int unk04;
    int unk08;
    S_cbde40_Base* unk0c;
    S_cbde40_Base* FUN_00cbde40(bool* created);
};

namespace fnv_009b90b0 {
struct Obj;
struct Big;
struct V9;

struct V
{
    float x;
    float y;
    float z;
    void FUN_0062aea0();
};

struct V5
{
    float a;
    float b;
    float c;
    float d;
    float e;
    void FUN_0062aea0();
};

struct V6
{
    V5 q;
    float f;
};

struct V9
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    V9* FUN_0043f8d0(V9* out, V9* b);
};

struct Xform
{
    V9 rot;
    V pos;
    float scale;
    Xform* FUN_0062c250(Xform* out, Xform* b);
    V* FUN_00524c40(V* out, V* b);
};

struct Vec3
{
    float x;
    int y;
    int z;
};

struct Str
{
    int p;
    Str(int s);
    ~Str();
};

struct Ctrl
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Ctrl(float f);
    ~Ctrl();
};

struct Item
{
    unsigned char unk00;
    unsigned char unk01;
};

struct Arr
{
    Item** FUN_00877a30(unsigned int i);
};

struct Rec
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
};

struct List
{
};

struct ListH
{
};

struct Big
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
    void FUN_004a3f70(int a);
};

struct __declspec(align(16)) Res
{
    int unk00[200];
    Res();
    ~Res();
};

void* FUN_00aa13e0(unsigned int n);

struct Path
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Path();
    ~Path();
};

struct PathRef
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    PathRef(Path* p);
};

void* FUN_00aa13e0(unsigned int n);

struct Name
{
    char buf[64];
    Name(int a);
};

struct Color
{
    float r;
    float g;
    float b;
    float a;
};

struct Handle
{
    int val;
};

struct HandleSrc
{
    int val;
};

struct Sub
{
    int unk00;
    bool FUN_008256d0();
};

struct Obj
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual Obj* vfc();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual Obj* vf9c(const Str& s);
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void vfb8(V* v);
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void vfc8(Big* b);
    virtual void v051();
    virtual void vfd0(Obj* a, int b, int c, int d, int e);
    virtual void v053();
    virtual void v054();
    virtual void vfdc(Obj* a, int b);
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool vf100();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual Obj* vf1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual V* vf1f4();
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
    virtual void vf2a4();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float vf2bc(int a);
    void RemoveLimb(int a);
    unsigned int FUN_0043b480();
    HandleSrc* FUN_0070c440(int* out);
    HandleSrc* FUN_00931ed0(int* out);
    Obj* FUN_0043b4f0(int* out);
    void FUN_00c6e390(V5* v);
};

struct Owner
{
    Obj* unk00;
    V unk04;
    int pad10;
    int pad14;
    int pad18;
    int pad1C;
    int pad20;
    int unk24;
    unsigned char unk28;
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Arr unk20;
};

struct Glob
{
};



struct Actor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual Obj* vfc();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual Obj* vf9c(const Str& s);
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void vfb8(V* v);
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void vfc8(Big* b);
    virtual void v051();
    virtual void vfd0(Obj* a, int b, int c, int d, int e);
    virtual void v053();
    virtual void v054();
    virtual void vfdc(Obj* a, int b);
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool vf100();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual Obj* vf1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual V* vf1f4();
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
    virtual void vf2a4();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float vf2bc(int a);
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
    Sub unk88;
    unsigned char unk8C;
    unsigned char unk8D;
    unsigned char unk8E;
    unsigned char unk8F;
    unsigned char unk90;
    unsigned char unk91;
    unsigned char unk92;
    unsigned char unk93;
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
    float unk158;

    void FUN_009b90b0();
};

struct VRes
{
    void FUN_0053d280();
};

// @fnv 0x009b90b0
void Actor::FUN_009b90b0()
{
    static float s_offset = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009b90b0::Glob *>(&::originalRuntimeFloatSetting399))))));
    bool noMove = reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_009b90b0::Glob * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10();
    if (!unk88.FUN_008256d0())
    {
        Obj* p24 = vf1d0();
        Obj* p28 = p24->vfc();
        Owner* owner = (Owner*)*((::fnv_009b90b0::Obj **)(new ((void *)&(unk88)) ::Vec3()));
        unk158 = 10.0f;
        if (unk150 == 4)
        {
            owner = (Owner*)(((::fnv_009b90b0::Obj *)(reinterpret_cast<::Callees *>(&(unk88))->FUN_00726070())) ? *((::fnv_009b90b0::Obj **)(new ((void *)(((::fnv_009b90b0::Obj *)(reinterpret_cast<::Callees *>(&(unk88))->FUN_00726070())))) ::Vec3())) : 0);
        }
        if (owner && owner->unk00 && owner->unk00->vf100())
        {
            if (owner->unk28)
                return;
            Obj* p34 = owner->unk00;
            if (reinterpret_cast<::TESObjectREFR *>((p34))->IsLimbMissing(owner->unk24))
            {
                Holder* p38 = (Holder*)((::fnv_009b90b0::Obj *)(reinterpret_cast<::ExtraDataList *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_005d43c0_ *>((p34))->FUN_005d43c0()))))->GetDismemberedLimbs()));
                bool found = false;
                for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(p38->unk20))->GetName())); i++)
                {
                    if ((*p38->unk20.FUN_00877a30(i))->unk00 == (char)owner->unk24 &&
                        (*p38->unk20.FUN_00877a30(i))->unk01)
                        found = true;
                }
                Obj* p48 = owner->unk00 ? owner->unk00->vf1d0() : 0;
                if (p48 && !found)
                {
                    int p4c = (*reinterpret_cast<int (*)[]>((void *)&::DAT_01196d6c))[owner->unk24];
                    Obj* p60 = p48 ? p48->vf9c(Str(p4c)) : 0;
                    float f64 = reinterpret_cast<::FUN_008d01e0_Class *>((p60))->FUN_008d01e0();
                    if (p60 == 0)
                    {
                        unk90 = 0;
                        return;
                    }
                    {
                        Ctrl ctrl(1.0f);
                        reinterpret_cast<::FUN_004ad240_c *>(&(ctrl))->SetScale(1.0f);
                        Obj* p84 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::A5D2C0Object *>((p60))->FUN_00a5d2c0((*(::A5D2C0CloningProcess *)(&ctrl)))));
                        p34->RemoveLimb(owner->unk24);
                        p60 = p84;
                        reinterpret_cast<::TaskQueueInterface *>((p60))->QueueActorDisarm(0);
                        reinterpret_cast<::FUN_00440490_shell *>((p60))->FUN_00440490(f64);
                        Obj* p88 = p60->vfc();
                        if (p88)
                        {
                            for (unsigned int j = 0; j < p88->FUN_0043b480(); j++)
                            {
                                Obj* p90 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::NiNode *>((p88))->GetAt(j)));
                                if (p90 && ::FUN_004910d0((::NiAVObject *)(p90)))
                                    ::FUN_004ade40((::NiNode *)(p88), (::NiAVObject *)(p90), (::NiAVObject *)(p88), 0);
                            }
                        }
                        Vec3 v9c;
                        new ((void *)&(v9c)) ::NiUpdateData(0.0f, 0, 0);
                        reinterpret_cast<::FUN_00a59c60_cls *>((p60))->FUN_00a59c60((std::intptr_t)(&v9c));
                        Obj* pa0 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                        if (pa0)
                            pa0->vfd0(p60, 1, 0, 0, 1);
                        reinterpret_cast<::FUN_00440460_S *>((p60))->FUN_00440460((const ::V3 *)(void *)(&(*reinterpret_cast<int *>((void *)&::NiPoint3::ZERO))));
                        reinterpret_cast<::FUN_0043fa80_s *>((p60))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&(*reinterpret_cast<int *>(&::DAT_011a9448)))));
                        if (p88 && ((int)(reinterpret_cast<::S_FUN_0045bc00 *>((p88))->FUN_0045bc00(0))))
                        {
                            Xform xd4 = *((::fnv_009b90b0::Xform *)(::FUN_00461130((int)(((::fnv_009b90b0::Obj *)(reinterpret_cast<::NiNode *>((p88))->GetAt(0)))))));
                            if (!noMove)
                                reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)(::fnv_009b90b0::V *)(&owner->unk04));
                            reinterpret_cast<::fnv_009bf470::Ref9bf *>(this)->UpdateNodeTransform(0, 0);
                            Vec3 ve0;
                            new ((void *)&(ve0)) ::NiUpdateData(0.0f, 0, 0);
                            p28->vfb8((V*)&ve0);
                            Xform x114 = *((::fnv_009b90b0::Xform *)(::FUN_00461130((int)(p28))));
                            Xform x148;
                            reinterpret_cast<::_dummy_476a80 *>(&(x148))->FUN_00476a80();
                            reinterpret_cast<::FUN_008b42e0_shell *>(&(x114))->InvertTransform((::NiTransform *)(::fnv_009b90b0::Xform *)(&x148));
                            Xform x17c;
                            xd4 = *x148.FUN_0062c250(&x17c, &xd4);
                            xd4.pos.y -= s_offset;
                            reinterpret_cast<::FUN_00440460_S *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::NiNode *>((p88))->GetAt(0)))))->FUN_00440460((const ::V3 *)(void *)(&xd4.pos));
                            reinterpret_cast<::FUN_0043fa80_s *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::NiNode *>((p88))->GetAt(0)))))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&xd4)));
                            reinterpret_cast<::FUN_00440490_shell *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::NiNode *>((p88))->GetAt(0)))))->FUN_00440490(xd4.scale);
                        }
                        p28->vfdc(p60, 1);
                        ::AssignFixedString((char *)(p60), ::FUN_009b7cb0(), {});
                        ::FUN_00c69f50((::S_00c69f50_Obj *)(p60), 1, 1);
                        ::FUN_00c6a350((::NiAVObject *)(p60), 4, 1, 1, 1);
                        Vec3 v188;
                        new ((void *)&(v188)) ::NiUpdateData(0.0f, 0, 0);
                        reinterpret_cast<::FUN_00a59c60_cls *>((p28))->FUN_00a59c60((std::intptr_t)(&v188));
                        bool blocked = false;
                        if (p60)
                        {
                            int p190 = 0;
                            Obj* p194 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                            Big big;
                            new ((void *)&(big)) ::FUN_004a3c20();
                            V v25c;
                            new ((void *)&(v25c)) ::Vec3();
                            V v268;
                            new ((void *)&(v268)) ::Vec3();
                            v25c = *vf1f4();
                            V9 m28c;
                            new ((void *)&(m28c)) ::Vec3();
                            reinterpret_cast<::FUN_004a0c90_shell *>(&(m28c))->FUN_004a0c90(vf2bc(0));
                            V9 m2b0;
                            new ((void *)&(m2b0)) ::Vec3();
                            reinterpret_cast<::FUN_00524ac0_shell *>(&(m2b0))->FUN_00524ac0(reinterpret_cast<::MobileObject *>(this)->GetLooking());
                            V9 m2d4;
                            m28c = *m28c.FUN_0043f8d0(&m2d4, &m2b0);
                            reinterpret_cast<::FUN_00439f50_class *>(&(m28c))->FUN_00439f50(1, (::NiPoint3 *)(::fnv_009b90b0::V *)(&v268));
                            reinterpret_cast<::FUN_004a0c10_s *>(&(v268))->FUN_004a0c10();
                            V t2e0;
                            V t2ec;
                            reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(big))->FUN_004a3da0((void *)(((::fnv_009b90b0::V *)(reinterpret_cast<::FUN_00439ef0_class *>(&(v25c))->FUN_00439ef0((::NiPoint3 *)(::fnv_009b90b0::V *)(&t2ec), (*(const ::NiPoint3 *)(((::fnv_009b90b0::V *)(reinterpret_cast<::FUN_0045bb20_cls *>(&(v268))->ApplyScaled((::FUN_0045bb20_target *)(::fnv_009b90b0::V *)(&t2e0), 512.0f))))))))));
                            V t2f8;
                            reinterpret_cast<::Class_007f68a0 *>(&(big))->FUN_007f68a0((*(const ::NiPoint3 *)(((::fnv_009b90b0::V *)(reinterpret_cast<::FUN_0045bb20_cls *>(&(v268))->ApplyScaled((::FUN_0045bb20_target *)(::fnv_009b90b0::V *)(&t2f8), 1024.0f))))));
                            {
                                Res res;
                                reinterpret_cast<::FUN_004a3fb0_shell *>(&(big))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::fnv_009b90b0::Res *)(&res));
                                bool ok = ::FUN_009c5ba0((::World9C *)(::fnv_009b90b0::Big *)(&big), (::NiAVObject9C *)(p60), 0, 1);
                                if (ok && ((int)(reinterpret_cast<::Callees *>((((::fnv_009b90b0::List *)(::FUN_00460140((int)(((::fnv_009b90b0::ListH *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(big))->FUN_008cdd90()))))))))->FUN_00726070())) > 0)
                                    p190 = ((int)(::FUN_004b5820((::FormLike *)(((::fnv_009b90b0::Rec *)(reinterpret_cast<::FUN_004a46b0_class *>((((::fnv_009b90b0::List *)(::FUN_00460140((int)(((::fnv_009b90b0::ListH *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(big))->FUN_008cdd90()))))))))->GetEntryAt(0)))->unk50))));
                            }
                            if (p190)
                            {
                                Obj* p628 = ((::fnv_009b90b0::Obj *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::fnv_009b90b0::Obj *)(vf1d0()))));
                                Obj* p630 = p628 ? ((::fnv_009b90b0::Obj *)(::fnv_006fa820::FUN_006fa820((const char *)(p628)))) : 0;
                                Obj* p634 = ((::fnv_009b90b0::Obj *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::fnv_009b90b0::Obj *)((Obj*)p190))));
                                Obj* p63c = p634 ? ((::fnv_009b90b0::Obj *)(::fnv_006fa820::FUN_006fa820((const char *)(p634)))) : 0;
                                if (p63c && p63c != p630)
                                {
                                    Path path;
                                    reinterpret_cast<::fnv_00cbdcb0::CBDCB0Owner *>(&(path))->EnsureChild();
                                    reinterpret_cast<::FUN_009ba320_shell *>(&(path))->FUN_009ba320((uintptr_t)(p63c), (uintptr_t)(p630));
                                    Name n690(::FUN_004b4f00((::TESDataHandler *)(((::fnv_009b90b0::Obj *)(::FUN_004ae750((void *)(p63c)))))));
                                    Name n6d0(::FUN_004b4f00((::TESDataHandler *)(((::fnv_009b90b0::Obj *)(::FUN_004ae750((void *)(p630)))))));
                                    reinterpret_cast<::CB2FC0Object *>((((::fnv_009b90b0::Obj *)(new ((void *)&(n690)) ::Vec3()))))->FUN_00cb2fc0();
                                    reinterpret_cast<::CB2FC0Object *>((((::fnv_009b90b0::Obj *)(new ((void *)&(n6d0)) ::Vec3()))))->FUN_00cb2fc0();
                                    V v6dc;
                                    new ((void *)&(v6dc)) ::Vec3();
                                    reinterpret_cast<::FUN_00439f50_class *>(&(((::fnv_009b90b0::Xform *)(::FUN_00461130((int)(vf1d0()))))->rot))->FUN_00439f50(1, (::NiPoint3 *)(::fnv_009b90b0::V *)(&v6dc));
                                    V5 v6f0;
                                    new ((void *)&(v6f0)) ::Vec3();
                                    ::CopyCharacterControllerVector((::bhkCharacterController *)(::fnv_009b90b0::V5 *)(&v6f0), (*(const ::NiPoint3 *)(&v6dc)));
                                    reinterpret_cast<::S0062aea0_Vector *>(&(v6f0))->FUN_0062aea0();
                                    Xform x724 = *((::fnv_009b90b0::Xform *)(::FUN_00461130((int)(vf1d0()))));
                                    V v730;
                                    V v73c;
                                    V v748;
                                    reinterpret_cast<::FUN_0045bb20_cls *>((((::fnv_009b90b0::V *)(reinterpret_cast<::P3 *>(&((*reinterpret_cast<::fnv_009b90b0::Glob *>(&::DAT_011a9478))))->FUN_004a0bd0((::P3 *)(::fnv_009b90b0::V *)(&v73c))))))->ApplyScaled((::FUN_0045bb20_target *)(::fnv_009b90b0::V *)(&v730), s_offset);
                                    x724.FUN_00524c40(&v748, &v730);
                                    V6 v760;
                                    new ((void *)&(v760)) ::Vec3();
                                    ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&v760)), (*(const ::fnv_004a3e00::NiPoint3 *)(&v748)));
                                    reinterpret_cast<::FUN_009ba3d0_shell *>(&(path))->FUN_009ba3d0((int)(&n690), (int)(&n6d0), (int)(&v760.q), (int)(&v6f0));
                                    PathRef* ref = new PathRef(&path);
                                    reinterpret_cast<::SceneC8E *>((p63c))->FUN_00c8ef80((::NiObjectC8E *)(ref));
                                    reinterpret_cast<::C8DAC0Owner *>((p63c))->UpdateMatchingNodes(((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())));
                                    Obj* p774 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                                    Big big2;
                                    new ((void *)&(big2)) ::FUN_004a3c20();
                                    V v83c;
                                    new ((void *)&(v83c)) ::Vec3();
                                    V v848;
                                    new ((void *)&(v848)) ::Vec3();
                                    v83c = *vf1f4();
                                    V9 m86c;
                                    new ((void *)&(m86c)) ::Vec3();
                                    reinterpret_cast<::FUN_004a0c90_shell *>(&(m86c))->FUN_004a0c90(vf2bc(0));
                                    V9 m890;
                                    new ((void *)&(m890)) ::Vec3();
                                    reinterpret_cast<::FUN_00524ac0_shell *>(&(m890))->FUN_00524ac0(reinterpret_cast<::MobileObject *>(this)->GetLooking());
                                    V9 m8b4;
                                    m86c = *m86c.FUN_0043f8d0(&m8b4, &m890);
                                    reinterpret_cast<::FUN_00439f50_class *>(&(m86c))->FUN_00439f50(1, (::NiPoint3 *)(::fnv_009b90b0::V *)(&v848));
                                    reinterpret_cast<::FUN_004a0c10_s *>(&(v848))->FUN_004a0c10();
                                    Handle h;
                                    new ((void *)&(h)) ::GlobalObject_008c71b0(0);
                                    int t8bc;
                                    if (((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
                                    {
                                        h.val = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_0070c440(&t8bc)->val;
                                    }
                                    else
                                    {
                                        reinterpret_cast<::FUN_004a39f0_shell *>(&(h))->FUN_004a39f0(6);
                                        Obj* p8c0;
                                        int t8c4;
                                        if (((::fnv_009b90b0::Obj *)(::FUN_00874480((char *)this))) && (p8c0 = ((::fnv_009b90b0::Obj *)(::FUN_00874480((char *)this))), p8c0->vf100()))
                                            reinterpret_cast<::FUN_0059ce80_shell *>(&(h))->FUN_0059ce80(((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((((::fnv_009b90b0::Obj *)(::FUN_00874480((char *)this)))->FUN_00931ed0(&t8c4)))->FUN_004a3a20())));
                                        else
                                            reinterpret_cast<::FUN_0059ce80_shell *>(&(h))->FUN_0059ce80(((int)(::FUN_005dbe10())));
                                    }
                                    V v8e0;
                                    reinterpret_cast<::FUN_0045bb20_cls *>(&(v848))->ApplyScaled((::FUN_0045bb20_target *)(::fnv_009b90b0::V *)(&v8e0), (float)(reinterpret_cast<::fnv_00979260::Projectile *>(this)->GetFirstLightParameter() - reinterpret_cast<::FUN_00508070_class *>(this)->FUN_00508070()));
                                    big2.FUN_004a3f70(h.val);
                                    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(big2))->FUN_004a3da0((void *)(&v83c));
                                    reinterpret_cast<::Class_007f68a0 *>(&(big2))->FUN_007f68a0((*(const ::NiPoint3 *)(&v8e0)));
                                    Res res2;
                                    reinterpret_cast<::FUN_004a3fb0_shell *>(&(big2))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::fnv_009b90b0::Res *)(&res2));
                                    Obj* pc04 = ((::fnv_009b90b0::Obj *)(reinterpret_cast<::FUN_004543c0_cls *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
                                    pc04->vfc8(&big2);
                                    if (0)
                                    {
                                        Color c;
                                        new ((void *)&(c)) ::ImageSpaceEffectParam(1.0f, 0.5f, 0.5f, 1.0f);
                                        V tc20;
                                        int c24 = ((int)(::fnv_004b3890::FUN_004b3890((*(const class class ::FUN_006815c0 *)(&v83c)), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), (*(const class class ::FUN_006815c0 *)(((::fnv_009b90b0::V *)(reinterpret_cast<::Point3Offset *>(&(v83c))->ProjectileLaunched((::NiPoint3 *)(::fnv_009b90b0::V *)(&tc20), (::NiPoint3 *)(::fnv_009b90b0::V *)(&v8e0)))))), (*(const ::fnv_004b3890::FUN_004a7800 *)(&c)), 1)));
                                        reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::fnv_009b90b0::Glob * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(c24), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009b90b0::Glob *>(&::g_011f210c)))))));
                                    }
                                    for (int k = 0; !blocked && k < ((int)(reinterpret_cast<::Callees *>((((::fnv_009b90b0::List *)(::FUN_00460140((int)(((::fnv_009b90b0::ListH *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(big2))->FUN_008cdd90()))))))))->FUN_00726070()));
                                         k++)
                                    {
                                        Rec rec;
                                        reinterpret_cast<::S50 *>(&(rec))->FUN_00696c30((::S50 *)(::fnv_009b90b0::Rec *)(((::fnv_009b90b0::Rec *)(reinterpret_cast<::FUN_004a46b0_class *>((((::fnv_009b90b0::List *)(::FUN_00460140((int)(((::fnv_009b90b0::ListH *)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(&(big2))->FUN_008cdd90()))))))))->GetEntryAt(k)))));
                                        int pc94 = ((int)(::FUN_004b5820((::FormLike *)(rec.unk50))));
                                        Obj* pc98 = ((::fnv_009b90b0::Obj *)(::FUN_004b5a80((const void *)(((int)(::FUN_004b59f0((const void *)(rec.unk50))))))));
                                        Obj* pc9c = ((::fnv_009b90b0::Obj *)(::FUN_0056f930((::NiAVObject *)(pc94))));
                                        int tca0;
                                        int type = pc98 ? reinterpret_cast<::FUN_0043b4d0_shell *>((pc98->FUN_0043b4f0(&tca0)))->FUN_0043b4d0() : 0;
                                        if (pc98 &&
                                            (type == 1 || type == 2 || type == 9 || type == 0x11 || type == 0xd ||
                                             type == 0x14) &&
                                            (reinterpret_cast<::bhkRigidBody_shell *>((pc98))->FUN_00517630() == 5 || reinterpret_cast<::bhkRigidBody_shell *>((pc98))->FUN_00517630() == 4))
                                        {
                                            blocked = true;
                                        }
                                        else if (pc98 && pc9c != (Obj*)this && pc9c && pc9c != owner->unk00)
                                        {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        owner->unk28 = 1;
                        if (blocked)
                        {
                            if (((int)(reinterpret_cast<::FUN_008d8b80Class *>(this)->FUN_008d8b80())))
                                reinterpret_cast<::FUN_008126e0_shell *>(this)->SetWhich(0);
                            ::FUN_00c69f50((::S_00c69f50_Obj *)(p60), 1, 1);
                            ::FUN_00c6a350((::NiAVObject *)(p60), 4, 1, 1, 1);
                            if (((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
                            {
                                int tcac;
                                ::FUN_00c6a3d0(p60, ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_0070c440(&tcac)))->FUN_004a3a20())), 1, 1);
                                if (!noMove)
                                {
                                    reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)(::fnv_009b90b0::V *)(&owner->unk04));
                                    V5 vcc0;
                                    new ((void *)&(vcc0)) ::Vec3();
                                    ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&vcc0)), (*(const ::fnv_004a3e00::NiPoint3 *)(&owner->unk04)));
                                    ((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_00c6e390(&vcc0);
                                }
                                reinterpret_cast<::fnv_009bf470::Ref9bf *>(this)->UpdateNodeTransform(0, 0);
                            }
                            if (!noMove)
                                unk90 = 0;
                        }
                        else
                        {
                            if (!noMove)
                                reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)(::fnv_009b90b0::V *)(&owner->unk04));
                            reinterpret_cast<::fnv_009bf470::Ref9bf *>(this)->UpdateNodeTransform(0, 0);
                            reinterpret_cast<::fnv_005de0a0::FUN_005de0a0_shell *>(this)->FUN_005de0a0(4, 1);
                            vf2a4();
                            ::FUN_00c69f50((::S_00c69f50_Obj *)(p60), 1, 1);
                            int tcc4;
                            ::FUN_00c6a3d0(p28, ((int)(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>((p34->FUN_00931ed0(&tcc4)))->FUN_004a3a20())), 1, 1);
                            ::FUN_00c6a350((::NiAVObject *)(p28), 1, 1, 1, 1);
                            ::FUN_00c6a0b0((::NiAVObject *)(p28), 1, 1, 0);
                            V vcd0;
                            {
                                V vcdc;
                                V vce8;
                                ((VRes*)((::fnv_009b90b0::V *)(reinterpret_cast<::FUN_0045bb20_cls *>((((::fnv_009b90b0::V *)&(reinterpret_cast<::FUN_009b7010_shell *>(this)->FUN_009b7010((*(::NiPoint3 *)(&vce8)))))))->ApplyScaled((::FUN_0045bb20_target *)(::fnv_009b90b0::V *)(&vcdc), reinterpret_cast<::FUN_009669c0_Class *>(this)->FUN_009669c0()))))
                                    ->FUN_0053d280();
                            }
                            ::FUN_0062b8d0(p28, &vcd0, 1);
                            if (((::fnv_009b90b0::Obj *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(&((*reinterpret_cast<::fnv_009b90b0::Glob *>(&::g_011f2250))))->FUN_007af430())) == (Obj*)this)
                                reinterpret_cast<::S_009c8c40 *>(&((*reinterpret_cast<::fnv_009b90b0::Glob *>(&::g_011f2250))))->SetValue(0);
                        }
                    }
                    return;
                }
            }
            reinterpret_cast<::Projectile *>(this)->FUN_009bc8f0();
            return;
        }
    }
    unk150 = 4;
    reinterpret_cast<::fnv_009ba660::MissileActor *>(this)->HandleMissileImpact();
}
}  // namespace fnv_009b90b0
