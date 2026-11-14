// The setting value accessor (VEGAS-111) and the int it returns for a null
// setting, in a unit of their own so that a link that reaches them loads no
// other code (VEGAS-129). The accessor was defined in
// src/fallout_shared/magic/magicitem.cpp, the int in generated data.
#include "fnv/setting_class.h"
#include "fnv/symbols_0043d000.h"

int DAT_01202800;

// Returns the setting's value when pThis is non-null, otherwise resets DAT_01202800 to 0 and returns it.
// @fnv 0x0043d4d0
int& FUN_0043d4d0(Setting* pThis)
{
    return pThis ? pThis->uValue.i : (DAT_01202800 = 0, DAT_01202800);
}
