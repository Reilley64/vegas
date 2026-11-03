// fallout/ai/followerbarks_decls.h: declares Actor, BarkPlaybackEntry
#ifndef FOLLOWERBARKS_DECLS_H
#define FOLLOWERBARKS_DECLS_H

#include "fnv/decl/FNVWipScreenManager.h"
#include "fnv/decl/FUN_008d6000_Class.h"
#include "fnv/decl/HealthCond5e30.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_011e0000.h"
void __cdecl operator delete(void*);
class Actor
{
  public:
};
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList<T>* GetNext();
    void RemoveHead();
};
template <> void BSSimpleList<const char*>::RemoveHead();
class GlobalObject2_0096a2d0
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
