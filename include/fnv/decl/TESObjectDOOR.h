#pragma once

class Actor;
class NiFixedString;
class TESObjectREFR;

class TESObjectDOOR {
public:
    // 0x0047a500
    static ::NiFixedString *GetOpenSequenceName();
    // 0x00517500
    ~TESObjectDOOR();
    // 0x00518000
    bool IsTeleportDoor();
    // 0x00518b70
    void QueueDoorTeleport(::TESObjectREFR *);
    // 0x00518f00
    static bool ProcessDoorActivation(::TESObjectREFR *, ::Actor *, bool, bool);
    // 0x00519550
    void ClearRandomTeleportList();
};
