
// src/fallout_shared/bgsdecalmanager_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /GF /Oy- (unit src/fallout_shared/bgsdecalmanager_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/bgsdecalmanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bgsdecalmanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "fnv/decl/CameraPass__Camera.h"
#include "fnv/decl/DecalSetup.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004a0350_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_0068de30_holder.h"
#include "fnv/decl/FUN_0068dea0_cls.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004a0330__FUN_004a0330_shell.h"
#include "fnv/decl/fnv_004a03c0__DD.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c5000.h"
#include "bgsdecalmanager_decls.h"
#include "bgsdecalmanager_types_BGSDecalManager.h"
#include "bgsdecalmanager_types_BSTempEffectSimpleDecal.h"

#include <xmmintrin.h>
struct AlignedVector
{
    __m128 value;
    void __thiscall FUN_004a3f10(const AlignedVector& source);
};
// @fnv 0x004a3f10
void AlignedVector::FUN_004a3f10(const AlignedVector& source)
{
    value = source.value;
}
