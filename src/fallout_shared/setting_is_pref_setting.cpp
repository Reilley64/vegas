// The function at 0x0047c850, which returns false, in a unit of its own
// (VEGAS-129). It was defined in src/fallout_shared/tesactorbasedata.cpp.
// Slot 1 of Setting's table, ?vftable_SettingBase_01012120 in generated
// data, holds its address, and include/fnv/setting_class.h declares
// IsPrefSetting at that slot, so this unit also defines
// Setting::IsPrefSetting with the same body: an identity the original
// linker folded into this address.
#include "fnv/setting_class.h"

struct FUN_0047c850
{
    bool EvaluateCondition();
};

// @fnv 0x0047c850
bool FUN_0047c850::EvaluateCondition()
{
    return false;
}

// @fnv 0x0047c850
bool Setting::IsPrefSetting()
{
    return false;
}
