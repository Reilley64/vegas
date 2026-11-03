// gamebryo2.2/corelibs/nianimation/nikeyframemanager.cpp: NiGeomMorpherController (1 function)

#include <cstdint>
#include "fnv/decl/Twin_0044ddc0.h"
#include "nikeyframemanager_decls.h"

// @fnv 0x008d3ed0
uintptr_t NiGeomMorpherController::GetNumTargets() const
{
    return m_spMorphTargetData.operator->()
               ? ((uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<GlobalObject_00869f00*>(m_spMorphTargetData.operator->())))->GetName()))
               : 0;
}
