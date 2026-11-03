
// Header unit for bsshadernolightingproperty.h.
// No @fnv markers here; the covered getter is defined and marked in the
// header. This translation unit only forces the covered COMDAT to be
// emitted so its bytes can be compared against the original.
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "bsshadernolightingproperty.h"

void BSShaderNoLightingProperty_UnitReference()
{
    BSShaderNoLightingProperty* pProperty = 0;
    NiTexture* pTexture = pProperty->GetBaseTexture();
    (void)pTexture;
}
