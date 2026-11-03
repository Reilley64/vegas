
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aa0390.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_010f0000.h"
#include "fnv/symbols_011f6000.h"
#include "nid3dshaderfactory_decls.h"
const char kFailedShaderFactoryMessage[] = "Failed to create shader factory!";


struct FUN_00a1e740_Class
{
    bool __thiscall FUN_00a1e740(const char*, const char*);
};

// @fnv 0x00a1e740
bool __thiscall FUN_00a1e740_Class::FUN_00a1e740(const char* pcKey1, const char* pcKey2)
{
    return NiStricmp(pcKey1, pcKey2) == 0;
}
