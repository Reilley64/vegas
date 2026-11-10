// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIUPDATEDATA_H
#define FNV_NIUPDATEDATA_H

#include "layout_support.h"
struct NiUpdateData;
struct NiUpdateData
{
  public:
    float fTime;            // +0x0, 4 bytes
    bool m_bUpdateEnabled;  // +0x4, 1 bytes
    bool m_bRender;         // +0x5, 1 bytes
    bool m_bInterpolate;    // +0x6, 1 bytes
    bool m_bTimeToDie;      // +0x7, 1 bytes
    bool m_bVisible;        // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    // void __cdecl NiUpdateData::*(float, bool, bool)
};
#endif
