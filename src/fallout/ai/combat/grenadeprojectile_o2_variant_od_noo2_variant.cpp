
// src/fallout/ai/combat/grenadeprojectile_o2_variant_od_noo2_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy (unit src/fallout/ai/combat/grenadeprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
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
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Projectile9c58.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S00561240_Vector.h"
#include "fnv/decl/TESRecipe.h"
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
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_01012000.h"
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
    void __thiscall FUN_009b4d10(BGSLoadFormBuffer* apLoadGameBuffer);
};

#include <xmmintrin.h>
struct S_00561240
{
};

struct S_00627920
{
    __m128 unk00;
    void __thiscall FUN_00627920(S_00561240* param);
};

// @fnv 0x00627920
void __thiscall S_00627920::FUN_00627920(S_00561240* param)
{
    __m128 tmp;
    unk00 = _mm_mul_ps(*((::__m128 *)(reinterpret_cast<::S00561240_Vector *>((param))->FUN_00561240((::S00561240_Vector *)(::__m128 *)(&tmp)))), unk00);
}
