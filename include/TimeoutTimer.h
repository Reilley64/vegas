#ifndef FNV_COMBATTIMER_H
#define FNV_COMBATTIMER_H
#include "layout_support.h"
class BGSLoadFormBuffer;
class TimeoutTimer
{
  public:
    float m_fStartTime;  // +0x0
    float m_fTimeout;  // +0x4
public:
    bool CheckTimer();
public:
    void FUN_00910b10();
public:
    void LoadGame(::BGSLoadFormBuffer *);
};
#endif
