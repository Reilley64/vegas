// include/havok/hkMonitorStreamFrameInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x24.
#ifndef FNV_HAVOK_HKMONITORSTREAMFRAMEINFO_H
#define FNV_HAVOK_HKMONITORSTREAMFRAMEINFO_H

#include "hkBase.h"
class hkMonitorStreamFrameInfo
{
  public:
    enum AbsoluteTimeCounter
    {
        ABSOLUTE_TIME_TIMER_0 = 0,
        ABSOLUTE_TIME_TIMER_1 = 1,
        ABSOLUTE_TIME_NOT_TIMED = -1
    };
    char* m_pHeading;        // +0x0
    hkInt32 m_iColor;        // +0x4
    hkInt32 m_iTimer0;       // +0x8
    hkUint32 m_uiTimer1;     // +0xC (AbsoluteTimeCounter)
    hkReal m_fStartTime;     // +0x10
    hkReal m_fEndTime;       // +0x14
    hkInt32 m_uiThreadId;    // +0x18
    hkInt32 m_iTimer0Index;  // +0x1C
    hkInt32 m_iTimer1Index;  // +0x20
};
#endif
