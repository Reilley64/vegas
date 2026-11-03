#pragma once

class BGSVoiceType;
class TESForm;
class TESObjectREFR;
template <class> class BSSimpleList;

class BGSTalkingActivator {
public:
    // 0x004febf0
    void SetVoiceType(::BGSVoiceType *);
    // 0x004fedc0
    bool IsRadioStation();
    // 0x004fede0
    static bool IsRadioStation(::TESForm *, unsigned int);
    // 0x004ff150
    static void AddRadioStation(::TESObjectREFR *);
    // 0x004ff1a0
    static void FindRadioStations(::TESObjectREFR *, ::BSSimpleList< ::TESObjectREFR *> *, ::BSSimpleList<float> *);
};
