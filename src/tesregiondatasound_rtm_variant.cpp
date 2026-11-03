
// src/tesregiondatasound_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/tesregiondatasound.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /Od /Oy- /GS /EHsc /Gy /GF (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004615d0_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_011c3000.h"
#include "tesregiondatasound_decls.h"

struct FUN_004f4f90_node : BSSimpleList<unsigned int>
{
    void FUN_005ae3d0(unsigned int* out);
};


struct FUN_004f4f90_shell : TESRegionDataSound
{
    int FUN_004f4f90();
};

// @fnv 0x004f4f90
int FUN_004f4f90_shell::FUN_004f4f90()
{
    unsigned int found;
    FUN_004f4f90_node* node7 = (FUN_004f4f90_node*)&Battle;
    found = 0;
    if (node7 != 0 && *((unsigned int *)(new ((void *)(node7)) ::Vec3())) != 0)
    {
        while (node7 != 0 && *((unsigned int *)(new ((void *)(node7)) ::Vec3())) != 0)
        {
            if (((int)(::GetRandomNumberInRange(0, 3))) == 0 || found == 0)
            {
                found = *((unsigned int *)(new ((void *)(node7)) ::Vec3()));
            }
            node7 = ((::FUN_004f4f90_node *)(reinterpret_cast<::Callees *>((node7))->FUN_00726070()));
        }
    }
    else
    {
        return 0;
    }
    if (found != 0)
    {
        reinterpret_cast<::ItemChangeListNode *>((((FUN_004f4f90_node*)&Battle)))->FUN_00905330((*(::InventoryStackRecord *const *)(&found)));
        ((FUN_004f4f90_node*)&Battle)->FUN_005ae3d0(&found);
        return ((int)(::FUN_004839c0(found)));
    }
    return 0;
}
