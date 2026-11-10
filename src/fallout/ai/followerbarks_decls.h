// fallout/ai/followerbarks_decls.h: declares Actor, BarkPlaybackEntry
#ifndef FOLLOWERBARKS_DECLS_H
#define FOLLOWERBARKS_DECLS_H

#include "fnv/decl/FNVWipScreenManager.h"
#include "fnv/decl/FUN_008d6000_Class.h"
#include "fnv/decl/HealthCond5e30.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_011e0000.h"
class Actor
{
  public:
};
class BGSPerkEntry;
#include "fnv/bs_simple_list.h"
template <> void BSSimpleList<const char*>::RemoveHead();
struct GlobalObject2_0096a2d0
{
};
class BarkPlaybackEntry
{
  public:
    Actor* actor;
    void* topic;
    unsigned int startTime;
    unsigned int endTime;
    static void UpdateBarks();
};
#endif
