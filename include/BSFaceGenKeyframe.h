// Source layout: BSFaceGenKeyframe. PC corrections are in generate_headers.py.
#ifndef FNV_BSFACEGENKEYFRAME_H
#define FNV_BSFACEGENKEYFRAME_H

#include "layout_support.h"
class BSFaceGenKeyframe
{
  public:
    void** m_ppVirtualMethodTable;              // +0x0
    BS_FACEGEN_MORPH_TYPE eType;  // +0x4
    float fTime;                  // +0x8
    float GetTime();
};
#endif
