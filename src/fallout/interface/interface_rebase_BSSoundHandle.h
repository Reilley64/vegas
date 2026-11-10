#ifndef FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_FNV_BSSOUNDHANDLE_H
#define FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_FNV_BSSOUNDHANDLE_H
#include "interface_rebase_layout_support.h"
struct SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;  // +0x0
    bool m_bLooping;        // +0x4
    unsigned char layoutPadding5[3];
    BSSoundHandle__ASSUMED_STATE eState;  // +0x8
};
#endif
