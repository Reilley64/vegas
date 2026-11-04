#pragma once

class BGSAcousticSpace;
class TESSound;
struct NiPoint3;

class SoundPlaybackManager {
public:
    // 0x0082d7c0
    static void ProcessPendingSounds();
    // 0x0082eae0
    static void SetAcousticSpace(::BGSAcousticSpace *);
    // 0x0082eb70
    static void ResetAcousticSpace(::BGSAcousticSpace *);
    // 0x0082eca0
    static bool CanPlaySoundAt(::TESSound *, ::NiPoint3, float);
};
