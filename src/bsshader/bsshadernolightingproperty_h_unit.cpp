
// Header unit for bsshadernolightingproperty.h.
// The recipe gives the covered getter to this unit, so it is defined here,
// once and with external linkage. The header only declares it.
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "bsshadernolightingproperty.h"

// @fnv 0x008d8520
NiTexture* BSShaderNoLightingProperty::GetBaseTexture()
{
    return m_pNoLightingTexture.m_pObject;
}

void BSShaderNoLightingProperty_UnitReference()
{
    BSShaderNoLightingProperty* pProperty = 0;
    NiTexture* pTexture = pProperty->GetBaseTexture();
    (void)pTexture;
}
