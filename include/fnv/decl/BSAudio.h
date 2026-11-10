#pragma once

struct NiPoint3;

struct BSAudio {
public:
    // 0x007624c0
    static void DeactivateAudio();
    // 0x007ec380
    void DisableAudioPlayback();
    // 0x00ad7740
    void Update(bool);
    // 0x00ad77f0
    void FUN_00ad77f0(float, unsigned int);
    // 0x00ad78b0
    void SetListenerPosition(::NiPoint3);
    // 0x00ad7990
    void FUN_00ad7990(bool);
    // 0x00ad79f0
    float GetMasterVolume();
    // 0x00ad7a50
    float FUN_00ad7a50();
    // 0x00ad7a80
    float FUN_00ad7a80();
    // 0x00ad7ab0
    float FUN_00ad7ab0();
    // 0x00ad7ae0
    float GetMusicVolume();
    // 0x00ad7c50
    bool FUN_00ad7c50();
    // 0x00ad7c80
    float FUN_00ad7c80();
    // 0x00ad8480
    void SetAudioProperty(unsigned int, unsigned int, unsigned int);
    // 0x00ad8780
    void SetAudioState(unsigned int);
};
