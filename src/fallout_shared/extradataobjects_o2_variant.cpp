
// src/fallout_shared/extradataobjects_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/extradataobjects.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0040f700_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00567e10__FUN_00567e10_shell.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011de000.h"
#include "extradataobjects_private_packet.h"
#include "extradataobjects_additions.h"

class FUN_00ee8ac0_cls
{
  public:
    virtual void vSlot0();
    unsigned int m_uiCount;
    int** m_ppItems;
    int* FUN_00ee8ac0();
};

// @fnv 0x00ee8ac0
int* FUN_00ee8ac0_cls::FUN_00ee8ac0()
{
    unsigned int count = m_uiCount;
    int i = 0;
    if (i < count)
    {
        int** items = m_ppItems;
        int** p = items;
        do
        {
            if (*p != 0)
            {
                return items[i];
            }
            ++i;
            ++p;
        } while (i < count);
    }
    return 0;
}
