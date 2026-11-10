#pragma once

struct BGSLoadFormBuffer;
class GlobalObject_008c71b0;
struct SoundPlaybackHandle;
enum PROCESS_TYPE;

class MobileObject {
public:
    // 0x004b9930
    bool GetCharControllerFlag() const;
    // 0x009316c0
    void ProcessAnimation();
    // 0x00931850
    ::PROCESS_TYPE GetCurrentProcessLevel();
    // 0x00931d30
    void AdvanceMovement(float);
    // 0x00931d70
    float GetLooking() const;
    // 0x00931ed0
    ::GlobalObject_008c71b0 GetVectorElement();
    // 0x00932f60
    void Revert(::BGSLoadFormBuffer *);
    // 0x00933270
    ::SoundPlaybackHandle PlaySoundByEditorName(const char *, bool, unsigned int, bool);
    // 0x009336c0
    bool IsCombatStateActive() const;
    // 0x00933840
    bool IsInDialogueWithPlayer() const;
};
