
#include "fnv/decl/S004b4db0_Quaternion.h"
#include "fnv/symbols_00c9f000.h"
#include "bhklimitedhingeconstraint_decls.h"
// @fnv 0x00caade0
void bhkLimitedHingeConstraint::PopulateOutput(bhkLimitedHingeOutput* output)
{
    ::FUN_00c9fb70((::MyObj *)this, (int)(output), {});
    reinterpret_cast<::S004b4db0_Quaternion *>(&(output->first))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(GetFirst())));
    reinterpret_cast<::S004b4db0_Quaternion *>(&(output->second))->FUN_004b4db0((*(const ::S004b4db0_Vector4 *)(GetSecond())));
}
