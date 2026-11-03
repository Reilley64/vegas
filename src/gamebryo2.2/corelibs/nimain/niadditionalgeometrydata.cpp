// gamebryo2.2/corelibs/nimain/niadditionalgeometrydata.cpp: NiAdditionalGeometryData (1 function)

#include "fnv/symbols_011f9000.h"
#include "niadditionalgeometrydata_decls.h"

// @fnv 0x00450b80
ShadowSceneNode* NiAdditionalGeometryData::GetShadowSceneNodeForIndex(int index)
{
    return DAT_011f91c8[index];
}
