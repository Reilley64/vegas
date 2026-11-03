
// src/fallout/ai/combat/grenadeprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/combat/grenadeprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/grenadeprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/grenadeprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "fnv/decl/Actor.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BeamEffect.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005de080_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00885bd0_St.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Projectile9c58.h"
#include "fnv/decl/ProjectileHit.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/bhkRigidBody_shell.h"
#include "fnv/decl/bhkUnaryAction.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00560000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_009c2000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_00c8c000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "grenadeprojectile_types.h"
struct S_004f15a0
{
};
struct GP_Base0
{
    virtual ~GP_Base0();
    char pad04[0x14];
};
struct GP_Base1
{
    virtual void f();
};
struct FUN_009bbc70 : public GP_Base0, public GP_Base1
{
    FUN_009bbc70(bool);
    virtual ~FUN_009bbc70();
    char pad1c[0x150 - 0x1c];
};
class FUN_009b3fa0 : public FUN_009bbc70
{
  public:
    bool bFlag150;
    FUN_009b3fa0(bool abFlag);
    virtual ~FUN_009b3fa0();
};
struct S4700
{
    bool FUN_009b4700(int, bool);
    virtual void f0(), f1(), f2(), f3(), f4(), f5(), f6(), f7(), f8(), f9(), f10(), f11(), f12(), f13(), f14(), f15(),
        f16(), f17(), f18(), f19(), f20(), f21(), f22(), f23(), f24(), f25(), f26(), f27(), f28(), f29(), f30(), f31(),
        f32(), f33(), f34(), f35(), f36(), f37(), f38(), f39(), f40(), f41(), f42(), f43(), f44(), f45(), f46(), f47(),
        f48(), f49(), f50(), f51(), f52(), f53(), f54(), f55(), f56(), f57(), f58(), f59(), f60(), f61(), f62(), f63(),
        f64();
    virtual void f65(), f66(), f67(), f68(), f69(), f70(), f71(), f72(), f73(), f74(), f75(), f76(), f77(), f78(),
        f79(), f80(), f81(), f82(), f83(), f84(), f85(), f86(), f87(), f88(), f89(), f90(), f91(), f92(), f93(), f94(),
        f95(), f96(), f97(), f98(), f99(), f100(), f101(), f102(), f103(), f104(), f105(), f106(), f107(), f108(),
        f109(), f110(), f111(), f112(), f113(), f114(), f115(), f116(), f117(), f118(), f119(), f120(), f121(), f122(),
        f123(), f124(), f125(), f126(), f127(), f128(), f129();
    virtual void f130(), f131(), f132(), f133(), f134(), f135(), f136(), f137(), f138(), f139(), f140(), f141(), f142(),
        f143(), f144(), f145(), f146(), f147(), f148(), f149(), f150(), f151(), f152(), f153(), f154(), f155(), f156(),
        f157(), f158(), f159(), f160(), f161(), f162(), f163(), f164(), f165(), f166(), f167(), f168(), f169(), f170(),
        f171(), f172(), f173(), f174(), f175(), f176(), f177(), f178(), f179(), f180(), f181(), f182(), f183(), f184(),
        f185(), f186(), f187(), f188(), f189(), f190(), f191(), f192(), f193(), f194();
    virtual void At30C();
};
struct NiAVObject;
struct Creature
{
};
struct FUN_009b4c70_shell : public Projectile
{
    void FUN_009b4c70();
};
struct BGSLoadFormBuffer;
struct C009c58e0
{
};
struct S009b4d10 : public FUN_009b3fa0
{
    void FUN_009b4d10(BGSLoadFormBuffer* apLoadGameBuffer);
};

#include <xmmintrin.h>

class NiColorA9B4
{
  public:
    NiColorA9B4();
    __m128 m_vComponents;
};

class GameModeState9B4
{
  public:
};

class ActorValueOwner9B4
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual int GetActorValue(int iAV);
};

class PlayerCharacter9B4
{
  public:
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
    ActorValueOwner9B4 m_kAVOwner;
};

class NiAVObject9B4
{
  public:
};

class NiNode9B4
{
  public:
};

class TESObjectREFR9B4
{
  public:
    virtual void vr000();
    virtual void vr004();
    virtual void vr008();
    virtual void vr00c();
    virtual void vr010();
    virtual void vr014();
    virtual void vr018();
    virtual void vr01c();
    virtual void vr020();
    virtual void vr024();
    virtual void vr028();
    virtual void vr02c();
    virtual void vr030();
    virtual void vr034();
    virtual void vr038();
    virtual void vr03c();
    virtual void vr040();
    virtual void vr044();
    virtual void vr048();
    virtual void vr04c();
    virtual void vr050();
    virtual void vr054();
    virtual void vr058();
    virtual void vr05c();
    virtual void vr060();
    virtual void vr064();
    virtual void vr068();
    virtual void vr06c();
    virtual void vr070();
    virtual void vr074();
    virtual void vr078();
    virtual void vr07c();
    virtual void vr080();
    virtual void vr084();
    virtual void vr088();
    virtual void vr08c();
    virtual void vr090();
    virtual void vr094();
    virtual void vr098();
    virtual void vr09c();
    virtual void vr0a0();
    virtual void vr0a4();
    virtual void vr0a8();
    virtual void vr0ac();
    virtual void vr0b0();
    virtual void vr0b4();
    virtual void vr0b8();
    virtual void vr0bc();
    virtual void vr0c0();
    virtual void vr0c4();
    virtual void vr0c8();
    virtual void vr0cc();
    virtual void vr0d0();
    virtual void vr0d4();
    virtual void vr0d8();
    virtual void vr0dc();
    virtual void vr0e0();
    virtual void vr0e4();
    virtual void vr0e8();
    virtual void vr0ec();
    virtual void vr0f0();
    virtual void vr0f4();
    virtual void vr0f8();
    virtual void vr0fc();
    virtual bool IsActor();
};

class HighProcess9B4
{
  public:
    bool IsReady();
};


class Actor9B4
{
  public:
    virtual void va000();
    virtual void va004();
    virtual void va008();
    virtual void va00c();
    virtual void va010();
    virtual void va014();
    virtual void va018();
    virtual void va01c();
    virtual void va020();
    virtual void va024();
    virtual void va028();
    virtual void va02c();
    virtual void va030();
    virtual void va034();
    virtual void va038();
    virtual void va03c();
    virtual void va040();
    virtual void va044();
    virtual void va048();
    virtual void va04c();
    virtual void va050();
    virtual void va054();
    virtual void va058();
    virtual void va05c();
    virtual void va060();
    virtual void va064();
    virtual void va068();
    virtual void va06c();
    virtual void va070();
    virtual void va074();
    virtual void va078();
    virtual void va07c();
    virtual void va080();
    virtual void va084();
    virtual void va088();
    virtual void va08c();
    virtual void va090();
    virtual void va094();
    virtual void va098();
    virtual void va09c();
    virtual void va0a0();
    virtual void va0a4();
    virtual void va0a8();
    virtual void va0ac();
    virtual void va0b0();
    virtual void va0b4();
    virtual void va0b8();
    virtual void va0bc();
    virtual void va0c0();
    virtual void va0c4();
    virtual void va0c8();
    virtual void va0cc();
    virtual void va0d0();
    virtual void va0d4();
    virtual void va0d8();
    virtual void va0dc();
    virtual void va0e0();
    virtual void va0e4();
    virtual void va0e8();
    virtual void va0ec();
    virtual void va0f0();
    virtual void va0f4();
    virtual void va0f8();
    virtual void va0fc();
    virtual void va100();
    virtual void va104();
    virtual void va108();
    virtual void va10c();
    virtual void va110();
    virtual void va114();
    virtual void va118();
    virtual void va11c();
    virtual void va120();
    virtual void va124();
    virtual void va128();
    virtual void va12c();
    virtual void va130();
    virtual void va134();
    virtual void va138();
    virtual void va13c();
    virtual void va140();
    virtual void va144();
    virtual void va148();
    virtual void va14c();
    virtual void va150();
    virtual void va154();
    virtual void va158();
    virtual void va15c();
    virtual void va160();
    virtual void va164();
    virtual void va168();
    virtual void va16c();
    virtual void va170();
    virtual void va174();
    virtual void va178();
    virtual void va17c();
    virtual void va180();
    virtual void va184();
    virtual void va188();
    virtual void va18c();
    virtual void va190();
    virtual void va194();
    virtual void va198();
    virtual void va19c();
    virtual void va1a0();
    virtual void va1a4();
    virtual void va1a8();
    virtual void va1ac();
    virtual void va1b0();
    virtual void va1b4();
    virtual void va1b8();
    virtual void va1bc();
    virtual void va1c0();
    virtual void va1c4();
    virtual void va1c8();
    virtual void va1cc();
    virtual void* Get3D();
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
    HighProcess9B4 m_kProcess;
    unsigned int unk8c;
    bool m_bFiring;

    bool FUN_009b4460(TESObjectREFR9B4* pkTarget, int a2, int a3, int a4, int a5, int a6);
};

// hkVector4::mul4(const hkVector4&): component-wise multiply in place.

struct hkVector4Mul
{
    __m128 m_vComponents;
    void FUN_009b4670(const hkVector4Mul& a);
};
// @fnv 0x009b4460
bool Actor9B4::FUN_009b4460(TESObjectREFR9B4* pkTarget, int a2, int a3, int a4, int a5, int a6)
{
    if (((int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::GameModeState9B4 *>(&::g_011f2250))))->GetName())) == 4)
    {
        NiNode9B4* pkNode = ((::NiNode9B4 *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(void *)(Get3D()))));
        if (pkNode)
        {
            NiAVObject9B4* pkObject = ((::NiAVObject9B4 *)(::fnv_006fa820::FUN_006fa820((const char *)(pkNode))));
            if (pkObject)
            {
                int iFlags = reinterpret_cast<::bhkRigidBody_shell *>((pkObject))->FUN_00517630();
                if (((bool)(::FUN_00c8cce0(&iFlags))))
                {
                    NiColorA9B4 kColor;
                    float fAlpha = ::DAT_010177e8;
                    fAlpha = (100 - (*reinterpret_cast<::PlayerCharacter9B4 * *>(&::_g_thePlayer))->m_kAVOwner.GetActorValue(0x23)) / 100.0 * fAlpha;
                    fAlpha = fAlpha + (double)0.1f;
                    reinterpret_cast<::bhkUnaryAction *>(&(kColor))->Set(fAlpha, fAlpha, fAlpha, 0.0f);
                    reinterpret_cast<::hkVector4Mul *>(&(kColor))->FUN_009b4670((*(const ::hkVector4Mul *)(((void *)&(::fnv_00560d80::FUN_00560d80((void *)(pkObject)))))));
                    reinterpret_cast<::S *>((pkObject))->FUN_00561690((int)(&kColor));
                }
            }
        }
    }
    if (m_kProcess.IsReady() && ::fnv_009c2c80::CanProjectileHit((::fnv_009c2c80::RefObj *)(pkTarget), (::fnv_009c2c80::CdBody *)(a4), (int)(this), (::fnv_009c2c80::ProjData *)(void *)(((void *)(reinterpret_cast<::Actor *>(this)->GetActorBase())))) &&
        reinterpret_cast<::ProjectileHit *>(this)->ProcessHit((::Obj *)(pkTarget), (*(const ::Vec *)(a2)), (*(const ::Vec *)(a3)), (::Buffer *)(a4), a5, a6))
    {
        if (pkTarget && pkTarget->IsActor())
        {
            ::FUN_0062b8d0(Get3D(), (*reinterpret_cast<const float (*)[3]>((void *)&::NiPoint3::ZERO)), 1);
        }
        else if (reinterpret_cast<::FUN_00885bd0_St *>(this)->FUN_00885bd0() == 0.0)
        {
            reinterpret_cast<::GrenadeProjectile *>(this)->FUN_009b4740();
            m_bFiring = true;
        }
        return true;
    }
    return false;
}
// @fnv 0x009b4670
void hkVector4Mul::FUN_009b4670(const hkVector4Mul& a)
{
    m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents);
}
