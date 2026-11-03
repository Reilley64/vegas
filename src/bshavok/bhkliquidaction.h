// bshavok/bhkliquidaction.h: declares bhkLiquidAction
#ifndef BHKLIQUIDACTION_H
#define BHKLIQUIDACTION_H

#include "fnv/decl/BodyBuild.h"
#include "fnv/symbols_01268000.h"
#include "bhkliquidaction_decls.h"
class bhkLiquidAction : public FUN_0056d410
{
  public:
    bhkLiquidAction(const LiquidActionInfo& info);
    virtual ~bhkLiquidAction();
    GlobalObject_004ee810 member;
};
// @fnv 0x0056d380
bhkLiquidAction::bhkLiquidAction(const LiquidActionInfo& info)
{
    reinterpret_cast<::BodyBuild *>(this)->ConfigureBody((::BuildSettings *)&(info));
    ++(*reinterpret_cast<unsigned int *>(&::DAT_012681bc));
}
#endif
