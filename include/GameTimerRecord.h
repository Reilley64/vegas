#ifndef FNV_BSTIMER_H
#define FNV_BSTIMER_H
#include "layout_support.h"
class GameTimerRecord
{
  public:
    unsigned char m_ucFirstTimerByte;  // +0x0
    unsigned char layoutPadding1;
    unsigned short layoutPadding2;
    float m_fFirstTimerValue;           // +0x4
    float m_fSecondTimerValue;          // +0x8
    float fTimeSinceScaleStart;         // +0xC
    float m_fFourthTimerValue;          // +0x10
    unsigned int m_uiFirstTimerValue;   // +0x14
    unsigned int m_uiSecondTimerValue;  // +0x18
    bool m_bFirstTimerFlag;             // +0x1C
    bool m_bSecondTimerFlag;            // +0x1D
    unsigned short layoutPadding1E;
public:
    void Update();
};
#endif
