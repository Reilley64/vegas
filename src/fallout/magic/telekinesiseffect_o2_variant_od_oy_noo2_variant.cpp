
// src/fallout/magic/telekinesiseffect_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/magic/telekinesiseffect_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/telekinesiseffect_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/telekinesiseffect.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/magic/telekinesiseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/telekinesiseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/B8182D0Object.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_00802d90_shell.h"
#include "fnv/decl/FUN_0082a540.h"
#include "fnv/decl/FUN_0082aee0_shell.h"
#include "fnv/decl/FUN_0082c000_shell.h"
#include "fnv/decl/FUN_00a59660_cls.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/Owner5615.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TelekinesisStartEffect.h"
#include "fnv/decl/fnv_00961280__FUN_00961280_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
struct FUN_0082a510_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};
struct FUN_0082aab0_shell
{
    void SetField644(float value);
};
struct FUN_0082af40_shell
{
    float fTelekinesisStrength;  // +0x644
    float GetTelekinesisStrength();
};
struct Actor
{
};
struct ValueModifierEffect
{
};
struct TelekinesisEffect : ValueModifierEffect
{
    unsigned short __thiscall FUN_0082b190(Actor* apActor);
};
struct FUN_008df040_shell
{
    unsigned char __thiscall FUN_008df040();
};
struct FUN_0082a670_shell
{
    void __thiscall FUN_0082a670();
};
struct Flt
{
    operator unsigned int();
};
struct FUN_0082aa90_shell
{
    unsigned int GetFloatAsUInt();
};
struct FUN_0082aeb0_shell
{
    void* __thiscall FUN_0082aeb0();
};

#include <xmmintrin.h>
class NiPoint3T
{
  public:
    float x, y, z;
    NiPoint3T();
    NiPoint3T operator*(float fScalar) const;
};

class NiMatrix3T
{
  public:
    float m_afEntries[3][3];
    NiMatrix3T();
};

class hkVector4T
{
  public:
    __m128 m_vComponents;
    hkVector4T();
};

class hkSimdRealT
{
  public:
    __m128 m_vValue;
    hkSimdRealT(float fValue);
};


class TelekinesisTargetController
{
  public:
};

class TelekinesisTarget
{
  public:
};

class PlayerCameraT
{
  public:
};

class GameSettingTableT
{
  public:
};

class TelekinesisEffectT
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
    float m_fHitDistance;
    unsigned int unk58;
    bool m_bHolding;

    void FUN_0082afa0();
};

// @fnv 0x0082afa0
void TelekinesisEffectT::FUN_0082afa0()
{
    if (((::FUN_0082aeb0_shell *)(reinterpret_cast<::FUN_0082aa90_shell *>(((*reinterpret_cast<::PlayerCameraT * *>(&::_g_thePlayer))))->GetFloatAsUInt())))
    {
        void* pvGrabbed = ((void *)(reinterpret_cast<::FUN_0082aee0_shell *>((((::FUN_0082aeb0_shell *)(reinterpret_cast<::FUN_0082aa90_shell *>(((*reinterpret_cast<::PlayerCameraT * *>(&::_g_thePlayer))))->GetFloatAsUInt()))))->FUN_0082aee0()));
        reinterpret_cast<::fnv_00961280::FUN_00961280_shell *>(((*reinterpret_cast<::PlayerCameraT * *>(&::_g_thePlayer))))->FUN_00961280();
        if (pvGrabbed)
        {
            TelekinesisTarget* pkTarget = (TelekinesisTarget*)FUN_004b5a80(pvGrabbed);
            if (m_bHolding)
            {
                NiPoint3T kForward;
                NiMatrix3T kRotationBasis;
                NiPoint3T kAngles = (*(const ::NiPoint3T *)(reinterpret_cast<::TESRecipe *>(((*reinterpret_cast<::PlayerCameraT * *>(&::_g_thePlayer))))->GetData()));
                reinterpret_cast<::FUN_00a59660_cls *>(&(kRotationBasis))->FUN_00a59660(kAngles.z, kAngles.x, kAngles.y);
                reinterpret_cast<::FUN_00439f50_class *>((void *)&(kRotationBasis))->FUN_00439f50(1, (::NiPoint3 *)&(kForward));
                NiPoint3T kIntersectionOffset = kForward * (::FUN_00403e20((float *)&((*reinterpret_cast<::GameSettingTableT *>(&::originalRuntimeFloatSetting1172)))) + m_fHitDistance);
                hkVector4T kMotionVelocity;
                ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&kMotionVelocity)), (*(const ::fnv_004a3e00::NiPoint3 *)(&kIntersectionOffset)));
                hkSimdRealT kMass(::FUN_004b5400((void *)(pkTarget)));
                reinterpret_cast<::S_00627920 *>(&(kMotionVelocity))->FUN_00627920((::S_00561240 *)&(kMass));
                reinterpret_cast<::B8182D0Object *>((((::TelekinesisTargetController *)(::FUN_004ae750((void *)(pkTarget))))))->ApplyToTarget({});
            }
            else
            {
                reinterpret_cast<::Owner5615 *>((pkTarget))->FUN_005615d0((int)&((*reinterpret_cast<const ::NiPoint3T *>((void *)&::NiPoint3::ZERO))));
            }
        }
    }
}
