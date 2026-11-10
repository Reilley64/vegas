
// Header unit for region system/tesregion.h.
// The recipe gives the covered getter to this unit, so it is defined here,
// once and with external linkage. The header only declares it.
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "tesregion.h"

// @fnv 0x005d8a70
NiColor* TESRegion::GetDiffuseColor()
{
    return &m_kDiffuseColor;
}

void TESRegion_UnitReference()
{
    TESRegion* pRegion = 0;
    NiColor* pColor = pRegion->GetDiffuseColor();
    (void)pColor;
}
