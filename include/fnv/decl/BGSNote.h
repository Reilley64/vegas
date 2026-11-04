#pragma once

class TESActorBase;
class TESDescription;
class TESSound;
class TESTexture;
class TESTopic;
enum NOTE_TYPE;

class BGSNote {
public:
    // 0x005e8f90
    void ChangeNoteType(::NOTE_TYPE);
    // 0x005e9100
    ::TESSound *FUN_005e9100();
    // 0x005e9160
    ::TESTexture *GetNoteTexture();
    // 0x005e91d0
    ::TESDescription *GetNoteDescription();
    // 0x005e9240
    ::TESTopic *FUN_005e9240();
    // 0x005e92a0
    ::TESActorBase *FUN_005e92a0();
};
