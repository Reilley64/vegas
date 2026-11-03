
#include "fnv/decl/A54440Hash.h"
#include "nicontrollersequence_decls.h"
// @fnv 0x00a5d3f0
NiControllerSequence__IDTag& NiControllerSequence__IDTag::operator=(const NiControllerSequence__IDTag& rhs)
{
    ShaderBufferRecord* result;
    NiTStringPointerMap<ShaderBufferRecord*>* map = *(NiTStringPointerMap<ShaderBufferRecord*>**)&rhs;
    if (reinterpret_cast<::A54440Hash *>((map))->FUN_00a53c30((::A54440Manager *)((const char*)this), (::A54440Manager **)&(result)))
        return *(NiControllerSequence__IDTag*)result;
    return Clone(rhs);
}
