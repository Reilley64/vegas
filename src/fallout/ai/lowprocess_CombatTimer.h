#ifndef FNV_COMBATTIMER_H
#define FNV_COMBATTIMER_H
#include "lowprocess_support.h"
class TimeoutTimer
{
  public:
    void FUN_00910b10();
    bool CheckTimer();
    void LoadGame(BGSLoadFormBuffer*);
    float m_fStartTime;  // +0x0
    float m_fTimeout;  // +0x4
};
#endif
