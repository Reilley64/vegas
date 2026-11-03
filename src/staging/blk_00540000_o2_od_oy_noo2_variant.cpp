
// src/staging/blk_00540000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/staging/blk_00540000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00540000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004a3000.h"
#include "../../include/layout_support.h"

#include <xmmintrin.h>
class NiPoint3;

struct hkVector4
{
    __m128 m_vComponents;
};


class Obj554720
{
  public:
    void FUN_00c9a1f0(const hkVector4& v);
    void FUN_00554720(const NiPoint3& pt);
};

// @fnv 0x00554720
void Obj554720::FUN_00554720(const NiPoint3& pt)
{
    hkVector4 v;
    new ((void *)&(v)) ::Vec3();
    FUN_00c9a1f0((*(::hkVector4 *)&(::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(v), (const ::fnv_004a3e00::NiPoint3 &)(pt)))));
}
