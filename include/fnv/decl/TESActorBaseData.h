#pragma once

class TESActorBaseData {
public:
    // 0x00461580
    bool GetFlag(unsigned int) const;
    // 0x0047c860
    float GetHealthRegeneration() const;
    // 0x004a8ae0
    unsigned short GetFatigue() const;
    // 0x005d1070
    void SetMatchesPCLevel(bool);
};
