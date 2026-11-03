
// src/fallout_shared/tesobjectweap_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectweap.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004ad010_shell.h"
#include "fnv/decl/FUN_004bcf60_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0051f4b0_shell.h"
#include "fnv/decl/FUN_0051f4d0_class.h"
#include "fnv/decl/FUN_0051f4f0_Class.h"
#include "fnv/decl/FUN_0051f530_class.h"
#include "fnv/decl/FUN_0051f570_shell.h"
#include "fnv/decl/FUN_0051f590_cls.h"
#include "fnv/decl/FUN_005214d0_shell.h"
#include "fnv/decl/FUN_00521580_shell.h"
#include "fnv/decl/FUN_005215a0_shell.h"
#include "fnv/decl/FUN_005215d0_shell.h"
#include "fnv/decl/FUN_005215f0_shell.h"
#include "fnv/decl/FUN_00521610_shell.h"
#include "fnv/decl/FUN_00521650_shell.h"
#include "fnv/decl/FUN_00521670_shell.h"
#include "fnv/decl/FUN_005216b0_shell.h"
#include "fnv/decl/FUN_005216d0_shell.h"
#include "fnv/decl/FUN_005216f0_shell.h"
#include "fnv/decl/FUN_00524b60_shell.h"
#include "fnv/decl/FUN_00525be0_shell.h"
#include "fnv/decl/FUN_00535aa0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/HighProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/QueueModelHolder.h"
#include "fnv/decl/ResetAccess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/TESDataHandler.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0067ff10__FUN_0067ff10_Class.h"
#include "fnv/symbols_0045c000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "tesobjectweap_decls.h"

// sub ecx, 0x3c ; jmp target  --  MSVC virtual adjustor thunk.
// The thunk converts the pointer to the second base sub-object back into a
// pointer to the complete object before jumping to the implementation.
struct PrimaryBase
{
    virtual void FUN_00525c00();
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
};

struct SecondaryBase
{
    virtual void FUN_00525c00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00525c00
    virtual void FUN_00525c00();
};

Derived::Derived()
{}

#include <math.h>
static float NI_HALF_PI;
float FUN_00a811f0(float y, float x);

inline float NiASin(float fValue)
{
    if (-1.0f < fValue)
    {
        if (fValue < 1.0f)
            return float(asin(fValue));
        else
            return NI_HALF_PI;
    }
    else
    {
        return -NI_HALF_PI;
    }
}

struct RotationMatrix
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    bool FUN_00a59400(float& x, float& y, float& z);
};

// @fnv 0x00a59400
bool RotationMatrix::FUN_00a59400(float& x, float& y, float& z)
{
    y = -NiASin(m21);
    if (y < NI_HALF_PI)
    {
        if (y > -NI_HALF_PI)
        {
            x = -FUN_00a811f0(-m01, m11);
            z = -FUN_00a811f0(-m20, m22);
            return true;
        }
        else
        {
            float fRmY = FUN_00a811f0(m02, m00);
            z = 0.0f;
            x = fRmY - z;
            return false;
        }
    }
    else
    {
        float fRpY = FUN_00a811f0(m02, m00);
        z = 0.0f;
        x = z - fRpY;
        return false;
    }
}
