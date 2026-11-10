// fallout/ai/combat/combattimer_decls.h: declares BGSLoadFormBuffer, BGSLoadGameBuffer, Actor
#ifndef COMBATTIMER_DECLS_H
#define COMBATTIMER_DECLS_H

#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00435000.h"
struct BGSLoadFormBuffer
{
  public:
};
struct BGSLoadGameBuffer : public BGSLoadFormBuffer
{
};
class Actor
{
  public:
};
extern float DAT_0108e360;
extern float DAT_011f1bf0;
struct CombatTargetTimestamp
{
  public:
    float fTimeStamp;
    void LoadGame(BGSLoadGameBuffer*);
};
class TimeoutTimer
{
  public:
    float m_fStartTime;
    float m_fTimeout;
    void LoadGame(BGSLoadFormBuffer*);
};
#endif
