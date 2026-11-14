#pragma once

class NiNode;
enum FADER_ENUM;

class FaderManager {
public:
    // 0x007006c0
    void AddRoot(::NiNode *, float, bool);
    // 0x00700960
    void AddFader(::FADER_ENUM, float, bool);
    // 0x007010e0
    void StopFader(::FADER_ENUM, bool);
    // 0x007011d0
    void AdvanceFaders(bool);
    // 0x00701450
    bool HasFader(::FADER_ENUM);
    // 0x007014e0
    float GetFadeValue(::FADER_ENUM);
};
