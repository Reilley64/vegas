
// src/gamebryo2.2/corelibs/nimain/nitrishape_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/gamebryo2.2/corelibs/nimain/nitrishape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "nitrishape_decls.h"

class NiTriGeom2
{
  public:
    void FUN_0051d000(unsigned short a);
    void FUN_0051d020(unsigned short a, unsigned short b, unsigned short c);
};

// @fnv 0x0051d000
void NiTriGeom2::FUN_0051d000(unsigned short a)
{
    reinterpret_cast<::NiTriBasedGeom *>((this))->SetBitfield(a, 7, 0);
}

void NiTriGeom2::FUN_0051d020(unsigned short a, unsigned short b, unsigned short c)
{
    (void)a;
    (void)b;
    (void)c;
}
