#pragma once

class DoorCell;
class TESFile;
class TESForm;
class TESObjectREFR;
class TESWorldSpace;

struct TeleportableReference {
public:
    // 0x0043a210
    void SetLinkedDoorReference(::TESObjectREFR *, bool);
    // 0x0043a2b0
    ::DoorCell *FUN_0043a2b0();
    // 0x0043a320
    ::TESWorldSpace *GetTeleportWorldspace();
    // 0x0043a4e0
    void Load(::TESFile *);
    // 0x008b3bb0
    ::TESForm *GetTeleportDestinationForm();
};
