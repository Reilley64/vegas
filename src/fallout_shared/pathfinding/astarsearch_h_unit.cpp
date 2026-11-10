// fallout_shared/pathfinding/astarsearch_h_unit.cpp: free functions (1 function)

#include "fnv/decl/A83A0ScrapHeap.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_006a83f0_cls.h"
#include "fnv/decl/FUN_006a8490_class.h"
#include "fnv/decl/FUN_006b9420_Class.h"
#include "fnv/decl/FUN_006b9540_class.h"
#include "fnv/decl/HX.h"
#include "fnv/decl/SlotOwnerCls.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00b00000.h"
#include "astarsearch.h"

// @fnv 0x00b00a00
BSWin32TaskletManager& GetTaskletManager()
{
    static BSWin32TaskletManager s_TaskletManager(6);
    return s_TaskletManager;
}

struct FUN_00996840_shell
{
    unsigned int FUN_00996840(unsigned int a);
};

// @fnv 0x00996840
unsigned int FUN_00996840_shell::FUN_00996840(unsigned int auiValue)
{
    return auiValue % 0x7f7;
}
