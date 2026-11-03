#ifndef FNV_BSSOUNDHANDLE_H
#define FNV_BSSOUNDHANDLE_H

#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "layout_support.h"
class NiAVObject;
#pragma pack(push, 4)
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;                // +0x0
    bool m_bLooping;                      // +0x4
    BSSoundHandle__ASSUMED_STATE eState;  // +0x8
    SoundPlaybackHandle();
    SoundPlaybackHandle(const SoundPlaybackHandle& other);
    ~SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& other);
public:
    bool SchedulePlayback(unsigned int, int);
public:
    bool IsValid() const;
public:
    bool Release();
public:
    void SetCompletionCallback(void (*)(void *, bool), void *);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SoundPlaybackHandle) == 0xC);
FNV_STATIC_ASSERT(offsetof(SoundPlaybackHandle, m_uiSoundResourceID) == 0x0);
FNV_STATIC_ASSERT(offsetof(SoundPlaybackHandle, m_bLooping) == 0x4);
FNV_STATIC_ASSERT(offsetof(SoundPlaybackHandle, eState) == 0x8);
#endif
