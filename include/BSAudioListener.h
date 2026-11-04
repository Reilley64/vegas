// Source layout: BSAudioListener. PC corrections are in generate_headers.py.
#ifndef FNV_BSAUDIOLISTENER_H
#define FNV_BSAUDIOLISTENER_H

#include "layout_support.h"
#include "NiPoint3.h"
class BSAudioListener
{
  public:
    void** m_ppVirtualMethodTable;                 // +0x0
    NiPoint3 m_kListenerPosition;    // +0x4
    NiPoint3 m_kListenerVelocity;    // +0x10
    NiPoint3 m_kForward;             // +0x1C
    NiPoint3 m_kUp;                  // +0x28
    unsigned int m_uiListenerID;     // +0x34
    float m_fGain;                   // +0x38
    float m_fDopplerScale;           // +0x3C
    float m_fDistanceScale;          // +0x40
    unsigned int m_uiListenerFlags;  // +0x44
    void SetListenerID(unsigned int);
    unsigned int GetListenerID();
};
#endif
