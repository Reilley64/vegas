#pragma once

class PathingActorData;
class TESObjectREFR;

class DoorAccessData {
public:
    // 0x00501d20
    DoorAccessData(::TESObjectREFR *);
    // 0x00501e50
    ~DoorAccessData();
    // 0x00502450
    bool CanUnlockDoor(const ::PathingActorData *, ::TESObjectREFR *, bool &);
    // 0x0073cb80
    bool ReadState98();
};
