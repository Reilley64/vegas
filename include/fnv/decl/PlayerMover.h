#pragma once

class NiPoint3;

class PlayerMover {
public:
    // 0x009185e0
    unsigned int GetActorStateFlags();
    // 0x009ea360
    void UpdatePlayerStatus(unsigned int, bool);
    // 0x009ea3b0
    void ClearMode(unsigned int);
    // 0x009ea570
    void SetSideVec(const ::NiPoint3 &);
};
