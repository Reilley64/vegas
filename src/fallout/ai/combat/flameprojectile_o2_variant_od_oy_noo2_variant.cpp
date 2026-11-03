
// src/fallout/ai/combat/flameprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/ai/combat/flameprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/flameprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/flameprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/flameprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/flameprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/Class_007f68a0.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3c20.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_00508070_class.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_00632ce0_Class.h"
#include "fnv/decl/FUN_00645ce0_class.h"
#include "fnv/decl/GlobalObject_008c71b0.h"
#include "fnv/decl/ImageSpaceEffectParam.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/LoadProjectile52.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MobileObject.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_005de0a0__FUN_005de0a0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_00979260__Projectile.h"
#include "fnv/decl/fnv_009bda10__ProjectileRuntime.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_00874000.h"
#include "fnv/symbols_009c0000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
struct Flt
{
    operator unsigned int() const;
};
struct FUN_009b3cb0_shell
{
    unsigned int FUN_009b3cb0();
};
struct BGSLoadFormBuffer
{
};
struct BeamProjectile
{
};
struct FlameProjectile : BeamProjectile
{
    FlameProjectile();
    void FUN_009b3f00(BGSLoadFormBuffer* apLoadGameBuffer);
};
// placeholder declarations
struct FUN_009b32b0_shell
{
    void ConfigureFlags();
};
struct FUN_005de0a0_shell
{
};
struct FUN_009bda10_shell
{
};

#include <xmmintrin.h>
struct FilterKey
{
    unsigned int m_uiCurrentValue;
    FilterKey();
};
struct NiPoint3
{
    float x, y, z;
    NiPoint3();
    NiPoint3 operator-(const NiPoint3& kPt) const;
    NiPoint3 operator+(const NiPoint3& kPt) const;
    NiPoint3 operator*(float fScalar) const;
};
struct NiMatrix33
{
    float rows[9];
    NiMatrix33* FUN_0043f8d0(NiMatrix33* result, NiMatrix33* rhs);
};
struct __declspec(align(16)) VisualState
{
    __m128 m_quad000;
    unsigned unk010, unk014, unk018, unk01c, unk020, unk024, unk028, unk02c;
    unsigned unk030, unk034, unk038, unk03c, unk040, unk044, unk048, unk04c;
    unsigned unk050, unk054, unk058, unk05c, unk060, unk064, unk068, unk06c;
    unsigned unk070, unk074, unk078, unk07c, unk080, unk084, unk088, unk08c;
    unsigned unk090, unk094, unk098, unk09c, unk0a0, unk0a4, unk0a8, unk0ac;
};
struct Handle
{
    unsigned int id;
};
struct Controller
{
};
struct Source
{
    Controller* FUN_009b3cb0();
};
struct AttachedObject
{
    unsigned int* FUN_0070c440(unsigned int* out);
};
struct BoundForm;
struct FireObject
{
    virtual void fo000();
    virtual void fo004();
    virtual void fo008();
    virtual void fo00c();
    virtual void fo010();
    virtual void fo014();
    virtual void fo018();
    virtual void fo01c();
    virtual void fo020();
    virtual void fo024();
    virtual void fo028();
    virtual void fo02c();
    virtual void fo030();
    virtual void fo034();
    virtual void fo038();
    virtual void fo03c();
    virtual void fo040();
    virtual void fo044();
    virtual void fo048();
    virtual void fo04c();
    virtual void fo050();
    virtual void fo054();
    virtual void fo058();
    virtual void fo05c();
    virtual void fo060();
    virtual void fo064();
    virtual void fo068();
    virtual void fo06c();
    virtual void fo070();
    virtual void fo074();
    virtual void fo078();
    virtual void fo07c();
    virtual void fo080();
    virtual void fo084();
    virtual void fo088();
    virtual void fo08c();
    virtual void fo090();
    virtual void fo094();
    virtual void fo098();
    virtual void fo09c();
    virtual void fo0a0();
    virtual void fo0a4();
    virtual void fo0a8();
    virtual void fo0ac();
    virtual void fo0b0();
    virtual void fo0b4();
    virtual void fo0b8();
    virtual void fo0bc();
    virtual void fo0c0();
    virtual void fo0c4();
    virtual void fo0c8();
    virtual void fo0cc();
    virtual void fo0d0();
    virtual void fo0d4();
    virtual void fo0d8();
    virtual void fo0dc();
    virtual void fo0e0();
    virtual void fo0e4();
    virtual void fo0e8();
    virtual void fo0ec();
    virtual void fo0f0();
    virtual void fo0f4();
    virtual void fo0f8();
    virtual void fo0fc();
    virtual bool IsEnabled();
    BoundForm* FUN_00931ed0();
};
struct BoundForm
{
    FilterKey FUN_004a3a20();
};
struct ActorRef
{
};
struct Tester
{
    virtual void t000();
    virtual void t004();
    virtual void t008();
    virtual void t00c();
    virtual void t010();
    virtual void t014();
    virtual void t018();
    virtual void t01c();
    virtual void t020();
    virtual void t024();
    virtual void t028();
    virtual void t02c();
    virtual void t030();
    virtual void t034();
    virtual void t038();
    virtual void t03c();
    virtual void t040();
    virtual void t044();
    virtual void t048();
    virtual void t04c();
    virtual void t050();
    virtual void t054();
    virtual void t058();
    virtual void t05c();
    virtual void t060();
    virtual void t064();
    virtual void t068();
    virtual void t06c();
    virtual void t070();
    virtual void t074();
    virtual void t078();
    virtual void t07c();
    virtual void t080();
    virtual void t084();
    virtual void t088();
    virtual void t08c();
    virtual void t090();
    virtual void t094();
    virtual void t098();
    virtual void t09c();
    virtual void t0a0();
    virtual void t0a4();
    virtual void t0a8();
    virtual void t0ac();
    virtual void t0b0();
    virtual void t0b4();
    virtual void t0b8();
    virtual void t0bc();
    virtual void t0c0();
    virtual void t0c4();
    virtual bool Query(VisualState* state);
};
struct GameObject
{
};
struct FlagSetting
{
    unsigned char* FUN_00408d60();
};
struct FloatSetting
{
};
struct ImpactManager
{
};
struct ImpactData
{
    unsigned unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    unsigned unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    unsigned unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    unsigned unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    unsigned unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    unsigned unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    unsigned unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    unsigned unk1a0, unk1a4, unk1a8, unk1ac, unk1b0, unk1b4, unk1b8, unk1bc;
    unsigned unk1c0, unk1c4, unk1c8, unk1cc, unk1d0, unk1d4, unk1d8, unk1dc;
    unsigned unk1e0, unk1e4, unk1e8, unk1ec, unk1f0, unk1f4, unk1f8, unk1fc;
    unsigned unk200, unk204, unk208, unk20c, unk210, unk214, unk218, unk21c;
    unsigned unk220, unk224, unk228, unk22c, unk230, unk234, unk238, unk23c;
    unsigned unk240, unk244, unk248, unk24c, unk250, unk254, unk258, unk25c;
    unsigned unk260, unk264, unk268, unk26c, unk270, unk274, unk278, unk27c;
    unsigned unk280, unk284, unk288, unk28c, unk290, unk294, unk298, unk29c;
    unsigned unk2a0, unk2a4, unk2a8, unk2ac, unk2b0, unk2b4, unk2b8, unk2bc;
    unsigned unk2c0, unk2c4, unk2c8, unk2cc, unk2d0, unk2d4, unk2d8, unk2dc;
    unsigned unk2e0, unk2e4, unk2e8, unk2ec, unk2f0, unk2f4, unk2f8, unk2fc;
    unsigned unk300, unk304, unk308, unk30c, unk310, unk314, unk318, unk31c;
    void FUN_004a3a70();
    void FUN_004a3bc0();
    ImpactData()
    {
        FUN_004a3a70();
    }
    ~ImpactData()
    {
        FUN_004a3bc0();
    }
};
struct Color4
{
    float r, g, b, a;
};
extern const FilterKey& FUN_005dbe10();
extern void GenerateSpherePoints(NiPoint3*, int, NiPoint3, float, float, float, float, float);
struct ProjectileEffect
{
    virtual ~ProjectileEffect();
    virtual void pe004();
    virtual void pe008();
    virtual void pe00c();
    virtual void pe010();
    virtual void pe014();
    virtual void pe018();
    virtual void pe01c();
    virtual void pe020();
    virtual void pe024();
    virtual void pe028();
    virtual void pe02c();
    virtual void pe030();
    virtual void pe034();
    virtual void pe038();
    virtual void pe03c();
    virtual void pe040();
    virtual void pe044();
    virtual void pe048();
    virtual void pe04c();
    virtual void pe050();
    virtual void pe054();
    virtual void pe058();
    virtual void pe05c();
    virtual void pe060();
    virtual void pe064();
    virtual void pe068();
    virtual void pe06c();
    virtual void pe070();
    virtual void pe074();
    virtual void pe078();
    virtual void pe07c();
    virtual void pe080();
    virtual void pe084();
    virtual void pe088();
    virtual void pe08c();
    virtual void pe090();
    virtual void pe094();
    virtual void pe098();
    virtual void pe09c();
    virtual void pe0a0();
    virtual void pe0a4();
    virtual void pe0a8();
    virtual void pe0ac();
    virtual void pe0b0();
    virtual void pe0b4();
    virtual void pe0b8();
    virtual void pe0bc();
    virtual void pe0c0();
    virtual void pe0c4();
    virtual void pe0c8();
    virtual void pe0cc();
    virtual void pe0d0();
    virtual void pe0d4();
    virtual void pe0d8();
    virtual void pe0dc();
    virtual void pe0e0();
    virtual void pe0e4();
    virtual void pe0e8();
    virtual void pe0ec();
    virtual void pe0f0();
    virtual void pe0f4();
    virtual void pe0f8();
    virtual void pe0fc();
    virtual void pe100();
    virtual void pe104();
    virtual void pe108();
    virtual void pe10c();
    virtual void pe110();
    virtual void pe114();
    virtual void pe118();
    virtual void pe11c();
    virtual void pe120();
    virtual void pe124();
    virtual void pe128();
    virtual void pe12c();
    virtual void pe130();
    virtual void pe134();
    virtual void pe138();
    virtual void pe13c();
    virtual void pe140();
    virtual void pe144();
    virtual void pe148();
    virtual void pe14c();
    virtual void pe150();
    virtual void pe154();
    virtual void pe158();
    virtual void pe15c();
    virtual void pe160();
    virtual void pe164();
    virtual void pe168();
    virtual void pe16c();
    virtual void pe170();
    virtual void pe174();
    virtual void pe178();
    virtual void pe17c();
    virtual void pe180();
    virtual void pe184();
    virtual void pe188();
    virtual void pe18c();
    virtual void pe190();
    virtual void pe194();
    virtual void pe198();
    virtual void pe19c();
    virtual void pe1a0();
    virtual void pe1a4();
    virtual void pe1a8();
    virtual void pe1ac();
    virtual void pe1b0();
    virtual void pe1b4();
    virtual void pe1b8();
    virtual void pe1bc();
    virtual void pe1c0();
    virtual void pe1c4();
    virtual void pe1c8();
    virtual void pe1cc();
    virtual void pe1d0();
    virtual void pe1d4();
    virtual void pe1d8();
    virtual void pe1dc();
    virtual void pe1e0();
    virtual void pe1e4();
    virtual void pe1e8();
    virtual void pe1ec();
    virtual void pe1f0();
    virtual NiPoint3* GetFiringPosition();
    virtual void pe1f8();
    virtual void pe1fc();
    virtual void pe200();
    virtual void pe204();
    virtual void pe208();
    virtual void pe20c();
    virtual void pe210();
    virtual void pe214();
    virtual void pe218();
    virtual void pe21c();
    virtual void pe220();
    virtual void pe224();
    virtual void pe228();
    virtual void pe22c();
    virtual void pe230();
    virtual void pe234();
    virtual void pe238();
    virtual void pe23c();
    virtual void pe240();
    virtual void pe244();
    virtual void pe248();
    virtual void pe24c();
    virtual void pe250();
    virtual void pe254();
    virtual void pe258();
    virtual void pe25c();
    virtual void pe260();
    virtual void pe264();
    virtual void pe268();
    virtual void pe26c();
    virtual void pe270();
    virtual void pe274();
    virtual void pe278();
    virtual void pe27c();
    virtual void pe280();
    virtual void pe284();
    virtual void pe288();
    virtual void pe28c();
    virtual void pe290();
    virtual void pe294();
    virtual void pe298();
    virtual void pe29c();
    virtual void pe2a0();
    virtual void pe2a4();
    virtual void pe2a8();
    virtual void pe2ac();
    virtual void pe2b0();
    virtual void pe2b4();
    virtual void pe2b8();
    virtual float GetProjectileSpread(int iMode);
    Controller* FUN_009b3cb0();
    bool FUN_009b36f0();
};
struct EmitterProperties
{
};
// @fnv 0x009b36f0
bool ProjectileEffect::FUN_009b36f0()
{
    if (!((::ActorRef *)(reinterpret_cast<::LowProcess *>(this)->GetTarget())) || !((::BoundForm *)(reinterpret_cast<::FUN_004543c0_cls *>((((::ActorRef *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0())))
        return false;
    bool emitted = false;
    void* pWorld = ((::BoundForm *)(reinterpret_cast<::FUN_004543c0_cls *>((((::ActorRef *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_004543c0()));
    VisualState visual;
    new ((void *)&(visual)) ::FUN_004a3c20();
    NiPoint3 position;
    NiPoint3 direction;
    position = *GetFiringPosition();
    NiMatrix33 rotation;
    new ((void *)&(rotation)) ::Vec3();
    reinterpret_cast<::FUN_004a0c90_shell *>(&(rotation))->FUN_004a0c90(GetProjectileSpread(0));
    NiMatrix33 spin;
    new ((void *)&(spin)) ::Vec3();
    reinterpret_cast<::FUN_00524ac0_shell *>(&(spin))->FUN_00524ac0(reinterpret_cast<::MobileObject *>(this)->GetLooking());
    NiMatrix33 result;
    rotation = *rotation.FUN_0043f8d0(&result, &spin);
    reinterpret_cast<::FUN_00439f50_class *>(&(rotation))->FUN_00439f50(1, &direction);
    reinterpret_cast<::FUN_004a0c10_s *>(&(direction))->FUN_004a0c10();
    Handle objectHandle;
    new ((void *)&(objectHandle)) ::GlobalObject_008c71b0(0);
    if (((::AttachedObject *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0())))
    {
        unsigned int handleId;
        objectHandle.id = *((::AttachedObject *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))->FUN_0070c440(&handleId);
    }
    else
    {
        reinterpret_cast<::FUN_004a39f0_shell *>(&(objectHandle))->FUN_004a39f0(6);
        if (((::FireObject *)(::FUN_00874480((char *)this))) && ((::FireObject *)(::FUN_00874480((char *)this)))->IsEnabled())
        {
            reinterpret_cast<::FUN_0059ce80_shell *>(&(objectHandle))->FUN_0059ce80((unsigned int)&(const ::FilterKey &)(((::FireObject *)(::FUN_00874480((char *)this)))->FUN_00931ed0()->FUN_004a3a20()));
        }
        else
        {
            reinterpret_cast<::FUN_0059ce80_shell *>(&(objectHandle))->FUN_0059ce80((unsigned int)&(FUN_005dbe10()));
        }
    }
    if (((::Controller *)(reinterpret_cast<::FUN_009b3cb0_shell *>(this)->FUN_009b3cb0())) && ((void *)(reinterpret_cast<::Twin_0044ddc0 *>((((::Controller *)(reinterpret_cast<::FUN_009b3cb0_shell *>(this)->FUN_009b3cb0()))))->GetName())))
        reinterpret_cast<::InterfaceManager *>(&(visual))->FUN_00500a20((::Tile *)(void *)(((void *)(reinterpret_cast<::Twin_0044ddc0 *>((((::Controller *)(reinterpret_cast<::FUN_009b3cb0_shell *>(this)->FUN_009b3cb0()))))->GetName()))));
    int iNumPoints = 4;
    NiPoint3 points[4];
    GenerateSpherePoints(points, 3, position, GetProjectileSpread(0), reinterpret_cast<::MobileObject *>(this)->GetLooking(), reinterpret_cast<::FUN_00645ce0_class *>(this)->GetField154(),
                         reinterpret_cast<::PathingRequest *>((((EmitterProperties*)((::GameObject *)(reinterpret_cast<::Actor *>(this)->GetActorBase())))))->GetActorRadius(), ((float)(::FUN_004a4240())));
    points[3] = position + direction * (float)(((double)(reinterpret_cast<::fnv_00979260::Projectile *>(this)->GetFirstLightParameter())) - ((double)(reinterpret_cast<::FUN_00508070_class *>(this)->FUN_00508070())));
    ::FUN_004a3f70((char *)&(visual), (::Flt)(objectHandle.id));
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(visual))->FUN_004a3da0(&position);
    for (int i = 0; i < 4; ++i)
    {
        reinterpret_cast<::Class_007f68a0 *>(&(visual))->FUN_007f68a0(points[i] - position);
        ImpactData impact;
        reinterpret_cast<::FUN_004a3fb0_shell *>(&(visual))->FUN_004a3fb0((::hkpAllRayHitCollector *)(void *)(&impact));
        Tester* tester = (Tester*)((::BoundForm *)(reinterpret_cast<::FUN_004543c0_cls *>((((::ActorRef *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::GameObject * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004543c0()));
        bool accepted = tester->Query(&visual);
        if (accepted)
            accepted = ::FUN_009c0d80((::Scene *)(::VisualState *)(&visual), (::Controller *)(void *)(this), 0, (float *)(0), 0, DAT_01016970) != 0;
        if (accepted)
            emitted = true;
        if (*(*reinterpret_cast<::FlagSetting *>(&::g_011f20ec)).FUN_00408d60())
        {
            Color4 greenColor;
            Color4 yellowColor;
            Color4* pColor = ((bool)(reinterpret_cast<::FUN_00632ce0_Class *>(&(visual))->FUN_00632ce0())) ? ((::Color4 *)(new ((void *)&(greenColor)) ::ImageSpaceEffectParam(1.0f, 0.0f, 0.0f, 1.0f)))
                                                   : ((::Color4 *)(new ((void *)&(yellowColor)) ::ImageSpaceEffectParam(1.0f, 1.0f, 0.0f, 1.0f)));
            __declspec(align(16)) Color4 color = *pColor;
            void* marker = ((void *)(::fnv_004b3890::FUN_004b3890((*(const class class ::FUN_006815c0 *)(&position)), (*(const ::fnv_004b3890::FUN_004a7800 *)(&color)), (*(const class class ::FUN_006815c0 *)(&points[i])), (*(const ::fnv_004b3890::FUN_004a7800 *)(&color)), 1)));
            reinterpret_cast<::FUN_00458e20_shell *>(((*reinterpret_cast<::ImpactManager * *>(&::g_TES))))->FUN_00458e20((::NiAVObject *)(marker), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::g_011f210c)))))));
        }
    }
    return emitted;
}
