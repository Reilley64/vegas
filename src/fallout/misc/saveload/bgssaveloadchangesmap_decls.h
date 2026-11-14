// fallout/misc/saveload/bgssaveloadchangesmap_decls.h: declares FormChangeRecord, TESDataHandlerAccess, QuantityData
#ifndef FNV_BGSSAVELOADCHANGESMAP_DECLS_H
#define FNV_BGSSAVELOADCHANGESMAP_DECLS_H


#include "fnv/decl/BSFlags.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_00841100_shell.h"
#include "fnv/symbols_011c3000.h"
#include "bgssaveloadchangesmap_types_BGSSaveLoadChangesMap.h"
#include "bgssaveloadchangesmap_types_BGSChangeFlags.h"
#include "bgssaveloadchangesmap_types_CombatTargetMap.h"
#include "bgssaveloadchangesmap_types_BGSUnloadedFormBuffer.h"

class FormChangeRecord : public FormChangeMask
{
  public:
    FormChangeMask flags;
    FormChangeRecord();
    ~FormChangeRecord();
};

class TESDataHandlerAccess
{
  public:
};

struct QuantityData
{
  public:
};


#endif
