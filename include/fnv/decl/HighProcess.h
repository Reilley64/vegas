#pragma once

class Actor;
class MobileObject;
class TESIdleForm;
enum ACTOR_SOUND_HANDLE;

class HighProcess {
public:
    // 0x0051f510
    ::MobileObject *GetMobileObject();
    // 0x006214b0
    ::TESIdleForm *GetSelectedIdleForm();
    // 0x00676280
    unsigned int UpdateHighProcessState(::Actor *);
    // 0x008d7510
    HighProcess();
    // 0x008e5730
    void FUN_008e5730(::Actor *);
    // 0x008fec10
    bool ClearProcessState(::Actor *);
    // 0x008ff1b0
    void StopActorSound(::ACTOR_SOUND_HANDLE);
    // 0x00901550
    void ClearTrackedActorEntries();
};
