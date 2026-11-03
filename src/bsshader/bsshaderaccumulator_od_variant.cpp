
// src/bsshader/bsshaderaccumulator_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/bsshaderaccumulator.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/FUN_00b64a00_Pass.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/RenderAccumulator.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00b9a000.h"
#include "fnv/symbols_011f6000.h"
#include "bsshaderaccumulator_types.h"
// offset-exact local views to dodge the task headers' mutually conflicting
// into the unit header and declare the methods on the real classes
// (BSShaderAccumulator, BSBatchRenderer__GeometryGroup).
struct GroupView
{
    unsigned char m_ucEntryType;
};
struct BRView
{
    unsigned char pad[0x3C];
    GroupView* m_pGeometryGroups[13];
};
class AccumWIP : public BSShaderAccumulator
{
  public:
    void SetShaderPassEnabled(unsigned int uiRenderPassIndex, bool bFlag);
};
#include "bsshaderaccumulator_batchrenderer.h"
#include "MemoryManager.h"
typedef BSSimpleList<unsigned short> BSShaderAccumulatorPassIndexList;
FNV_STATIC_ASSERT(sizeof(BSShaderAccumulatorPassIndexList) == 8);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulatorPassIndexList, m_item) == 0);
FNV_STATIC_ASSERT(offsetof(BSShaderAccumulatorPassIndexList, m_pkNext) == 4);

class Handler
{
  public:
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
};

class FUN_00c4ed40_cls
{
  public:
    Handler* m_00;

    void FUN_00c4ed40();
};

// @fnv 0x00c4ed40
void FUN_00c4ed40_cls::FUN_00c4ed40()
{
    if (m_00 != 0)
    {
        m_00->v02();
    }
}
