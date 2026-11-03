
// Header unit for region system/tesregion.h.
// No @fnv markers here; the covered getter is defined and marked in the
// header. This translation unit only forces the covered COMDAT to be
// emitted so its bytes can be compared against the original.
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

void TESRegion_UnitReference()
{
    TESRegion* pRegion = 0;
    NiColor* pColor = pRegion->GetDiffuseColor();
    (void)pColor;
}
