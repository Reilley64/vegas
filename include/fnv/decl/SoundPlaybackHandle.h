#pragma once

struct SoundPlaybackHandle {
public:
    // 0x00418900
    ::SoundPlaybackHandle &operator=(const ::SoundPlaybackHandle &);
    // 0x0068a7d0
    bool SetPositionFromArray(float *);
    // 0x00877700
    bool FUN_00877700();
    // 0x00ad8870
    bool SchedulePlayback(unsigned int, int);
    // 0x00ad8930
    bool IsPlaying() const;
    // 0x00ad8a90
    bool SetPlaybackFrequency(float);
    // 0x00ad8ce0
    bool IsValid() const;
    // 0x00ad8d10
    bool Release();
    // 0x00ad8da0
    bool StopWithFade(unsigned int);
    // 0x00ad8e60
    void SetCompletionCallback(void (*)(void *, bool), void *);
};
