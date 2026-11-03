// fallout/ai/combat/combatprocedureattackmelee_timer.h: declares Actor
#ifndef COMBATPROCEDUREATTACKMELEE_TIMER_H
#define COMBATPROCEDUREATTACKMELEE_TIMER_H

#include "fnv/symbols_00435000.h"
class Actor
{
  public:
};
class BGSLoadFormBuffer;
class TimeoutTimer
{
  public:
    float m_fStartTime;
    float m_fTimeout;
    bool CheckTimer();
public:
    float FUN_006b9130();
public:
    void FUN_00910b10();
public:
    void LoadGame(::BGSLoadFormBuffer *);
};
#endif
