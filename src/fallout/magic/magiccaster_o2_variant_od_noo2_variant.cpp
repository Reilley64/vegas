
// src/fallout/magic/magiccaster_o2_variant_od_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /GF (unit src/fallout/magic/magiccaster_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/magiccaster_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/magiccaster.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/CastTargets__Caster.h"
#include "fnv/decl/FUN_00404390_shell.h"
#include "fnv/decl/FUN_00404420_shell.h"
#include "fnv/decl/FUN_004044d0_shell.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00445300_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00622290_cls.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_0080fcc0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00c9f420_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Obj.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/ScriptLocalsX.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/TESGrass.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00572380__Fn572380.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00817970__CasterOps.h"
#include "fnv/decl/fnv_00818310__ExplosionCaster.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "magiccaster_private_match.h"

#include <xmmintrin.h>
struct Vec3
{
    float x, y, z;
    Vec3();
    Vec3(float ix, float iy, float iz);
};
struct Box3
{
    Vec3 minimum;
    Vec3 maximum;
    int kind;
};
struct __declspec(align(16)) BoundShape
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c;
    __m128 low, high;
    BoundShape();
    ~BoundShape();
};
struct PhantomShape
{
    int field00, field04, field08, field0c, field10, field14;
    PhantomShape(BoundShape* bounds);
    ~PhantomShape();
};
struct ListEntries
{
};
struct TargetInterface
{
    void** vtable;
    int unused04;
    int unused08;
    int unused0c;
    int unused10;
    int unused14;
    int unused18;
    int unused1c;
    int unused20;
    int unused24;
    int unused28;
    int unused2c;
    int unused30;
    int unused34;
    int unused38;
    int unused3c;
    int unused40;
    int unused44;
    int unused48;
    int unused4c;
    int unused50;
    int unused54;
    int unused58;
    int unused5c;
    int unused60;
    int unused64;
    int unused68;
    int unused6c;
    int unused70;
    int unused74;
    int unused78;
    int unused7c;
    int unused80;
    int unused84;
    int unused88;
    int unused8c;
    int unused90;
    int origin94;
};
typedef bool(* TargetAvailable)(TargetInterface*);
typedef int(* TargetActive)(TargetInterface*);
typedef bool(* TargetDisabled)(TargetInterface*, int);
struct RangeManager
{
};
struct TimeObject
{
};
struct CalcObject
{
    float* FUN_00403e20();
};
struct ListHandle
{
};
struct Master
{
    int reserved;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    void FUN_00817b90(Vec3 center, ListHandle* item, void* filter, RangeManager* source, TargetInterface* first,
                      float scale, float strength);
    void FUN_00818150(TargetInterface* selected, Vec3 location, RangeManager* source, float attenuation);
};
class GameSettingCollection;
template <> class SettingT<GameSettingCollection>
{
  public:
    float* FUN_00403e20();
};
struct FormRef;
struct MediaSelector
{
    int field00;
};
struct FormRef
{
};
extern float __cdecl CalcEffectCost(float value, int area, int duration, int magnitude, bool special);
extern int __cdecl FUN_00ec62c0();
extern int* __cdecl FUN_00403e20(unsigned int);
extern void* __cdecl FUN_00416870(float, float, float);

// @fnv 0x00817b90
void Master::FUN_00817b90(Vec3 center, ListHandle* item, void* filter, RangeManager* source, TargetInterface* first,
                          float scale, float strength)
{
    if (reinterpret_cast<::S3e60 *>((((::TimeObject *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((source))->FUN_00825c00()))))->FUN_00403e60(0x20000000))
    {
        float range = (double)reinterpret_cast<::FUN_00404420_shell *>((source))->FUN_00404420() * *originalRuntimeFloatSetting1112.FUN_00403e20() * strength;
        if (range > ::_DAT_01012060)
        {
            float attenuation = CalcEffectCost(reinterpret_cast<::TESGrass *>((((::TimeObject *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((source))->FUN_00825c00()))))->GetLowestAllowedSlope(), reinterpret_cast<::FUN_00404420_shell *>((source))->FUN_00404420(),
                                               (int)(reinterpret_cast<::FUN_004044d0_shell *>((source))->FUN_004044d0() * scale),
                                               (int)(reinterpret_cast<::FUN_00404390_shell *>((source))->FUN_00404390() * scale), reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0() == 2);
            float size = (float)(range * ::DAT_01011588);
            BoundShape space;
            ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)((Vec3*)&space.low)), (*(const ::fnv_004a3e00::NiPoint3 *)(&(*(::Vec3 *)(reinterpret_cast<::Point3Offset *>(&(center))->ProjectileLaunched((::NiPoint3 *)&(const ::Vec3 &)(Vec3(-size, -size, -size)), {}))))));
            ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)((Vec3*)&space.high)), (*(const ::fnv_004a3e00::NiPoint3 *)(&(*(::Vec3 *)(reinterpret_cast<::Point3Offset *>(&(center))->ProjectileLaunched((::NiPoint3 *)&(const ::Vec3 &)(Vec3(size, size, size)), {}))))));
            MediaSelector obj;
            space.field00 = ::FUN_00559450((int *)(((::FormRef *)(reinterpret_cast<::FUN_00622290_cls *>(&(obj))->FUN_00622290(0x29, (int)(((void *)(::FUN_005dbe10()))), {})))));
            PhantomShape results(&space);
            void* world = reinterpret_cast<::FUN_004543c0_cls *>((item))->FUN_004543c0();
            reinterpret_cast<::Obj *>(&(results))->FUN_00c85810((::Obj *)(world));
            ListEntries* entries = ((::ListEntries *)(reinterpret_cast<::ScriptLocalsX *>(&(results))->FUN_00818110()));
            for (int i = 0; i < ((int)(reinterpret_cast<::Callees *>((entries))->FUN_00726070())); ++i)
            {
                int target = ((int)(::FUN_004b59f0((const void *)(*((int *)&(reinterpret_cast<::FUN_00629ab0_shell *>((entries))->FUN_00629ab0(i)))))));
                if (target)
                {
                    FUN_00818150((TargetInterface*)target, center, source, attenuation);
                }
            }

            reinterpret_cast<::FUN_00c9f420_Class *>(&(results))->FUN_00c9f420();
            TargetInterface* node = first;
            TargetInterface* skip = ((::TargetInterface *)(reinterpret_cast<::MagicCaster *>(this)->GetCasterActor()));
            while (node && *((::TargetInterface **)(new ((void *)(node)) ::Vec3())))
            {
                TargetInterface* current = *((::TargetInterface **)(new ((void *)(node)) ::Vec3()));
                TargetInterface* candidate = ((TargetAvailable)current->vtable[64])(current) ? current : 0;
                if (candidate)
                    if (candidate && candidate != skip && ((TargetActive)candidate->vtable[116])(candidate))
                    {
                        float distance = reinterpret_cast<::fnv_00572380::Fn572380 *>((candidate))->FUN_00572380((::fnv_00572380::NiP3Sub *)(::Vec3 *)(&center));
                        if (distance <= range && !((TargetDisabled)candidate->vtable[139])(candidate, 0) &&
                            !reinterpret_cast<::FUN_008ace90_shell *>((candidate))->FUN_008ace90())
                        {
                            if (reinterpret_cast<::fnv_00817970::CasterOps *>(this)->CheckHealthDamageKill((::fnv_00817970::Recipient *)(int *)(candidate ? &candidate->origin94 : 0), (::fnv_00817970::EffectSpec *)(filter)))
                            {
                                reinterpret_cast<::fnv_00818310::ExplosionCaster *>(this)->ApplyExplosion((::fnv_00818310::ExplosionActor *)(candidate), (*(::NiPoint3 *)&(const ::Vec3 &)(center)), (::fnv_00818310::ExplosionEffect *)(source), attenuation);
                            }
                        }
                    }
                node = ((::TargetInterface *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
            }
            if ((*reinterpret_cast<::TargetInterface * *>(&::_g_thePlayer)) && (*reinterpret_cast<::TargetInterface * *>(&::_g_thePlayer)) != skip && ((TargetActive)(*reinterpret_cast<::TargetInterface * *>(&::_g_thePlayer))->vtable[116])((*reinterpret_cast<::TargetInterface * *>(&::_g_thePlayer))))
            {
                float distance = reinterpret_cast<::fnv_00572380::Fn572380 *>(((*reinterpret_cast<::TargetInterface * *>(&::_g_thePlayer))))->FUN_00572380((::fnv_00572380::NiP3Sub *)(::Vec3 *)(&center));
                if (distance <= range && !((TargetDisabled)(*reinterpret_cast<::TargetInterface * *>(&::_g_thePlayer))->vtable[139])((*reinterpret_cast<::TargetInterface * *>(&::_g_thePlayer)), 0) &&
                    !reinterpret_cast<::FUN_008ace90_shell *>(((*reinterpret_cast<::TargetInterface * *>(&::_g_thePlayer))))->FUN_008ace90())
                {
                    if (reinterpret_cast<::fnv_00817970::CasterOps *>(this)->CheckHealthDamageKill((::fnv_00817970::Recipient *)(int *)((*reinterpret_cast<::TargetInterface * *>(&::_g_thePlayer)) ? &(*reinterpret_cast<::TargetInterface * *>(&::_g_thePlayer))->origin94 : 0), (::fnv_00817970::EffectSpec *)(filter)))
                    {
                        reinterpret_cast<::fnv_00818310::ExplosionCaster *>(this)->ApplyExplosion((::fnv_00818310::ExplosionActor *)((*reinterpret_cast<::TargetInterface * *>(&::_g_thePlayer))), (*(::NiPoint3 *)&(const ::Vec3 &)(center)), (::fnv_00818310::ExplosionEffect *)(source), attenuation);
                    }
                }
            }
        }
    }
}
