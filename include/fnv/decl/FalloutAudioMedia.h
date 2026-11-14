#pragma once

class BGSMusicType;
enum MEDIATYPE;

class FalloutAudioMedia {
public:
    // 0x00830010
    static void PlayMedia(::BGSMusicType *);
    // 0x008304a0
    static void BeginMediaUpdate();
    // 0x008304c0
    static void EndMediaUpdate();
    // 0x00830680
    static void FadeOutMedia(int, ::MEDIATYPE);
    // 0x00830ad0
    static char IsRadioPlaying();
};
