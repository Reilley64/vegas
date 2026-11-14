#pragma once
#include <cstdint>

class Menu;
class UserOptionView_007d23b0;
namespace fnv_007d29d0 { struct UserOptionLayout_007d29d0; }
namespace fnv_007d2d30 { struct UserOptionStandIn; }
namespace fnv_007d2fc0 { struct SaveOpt; }
struct UserOptionLayout_007d28b0;

// 0x007d23b0
void FUN_007d23b0(::UserOptionView_007d23b0 *);
// 0x007d28b0
void FUN_007d28b0(::UserOptionLayout_007d28b0 *);
// 0x007d29d0
namespace fnv_007d29d0 { void FUN_007d29d0(::fnv_007d29d0::UserOptionLayout_007d29d0 *); }
// 0x007d2d30
namespace fnv_007d2d30 { void FUN_007d2d30(::fnv_007d2d30::UserOptionStandIn *); }
// 0x007d2e50
void UpdateMenuSaveOptions(::Menu *);
// 0x007d2eb0
namespace fnv_007d2eb0 { void SyncSliderWithSetting(intptr_t); }
// 0x007d2fc0
namespace fnv_007d2fc0 { void UpdateSaveOption(::fnv_007d2fc0::SaveOpt *); }
