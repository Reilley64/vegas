// Source layout: MiddleLowProcess. PC corrections are in generate_headers.py.
#ifndef FNV_MIDDLELOWPROCESS_H
#define FNV_MIDDLELOWPROCESS_H
#include "layout_support.h"
#include "LowProcess.h"
#include "ActorValueModifierList.h"
class MiddleLowProcess : public LowProcess
{
  public:
    int m_iValueB4;                       // +0xB4
    ActorValueModifierList m_kProcessModifierList;  // +0xB8
    int GetProcessInteger();
    void SetProcessInteger(int);
};
#endif
