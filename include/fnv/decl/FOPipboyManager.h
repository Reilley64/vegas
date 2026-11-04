#pragma once

class NiAVObject;

class FOPipboyManager {
public:
    // 0x007f8720
    bool FUN_007f8720(bool, bool, float &, float &, int &);
    // 0x007f9010
    void SetScreen(::NiAVObject *);
    // 0x007f9050
    void SetScanlines(bool, float);
    // 0x007f99b0
    void SetScreenLightFlickerIntensity(float);
    // 0x007fa010
    void ActivateButton(const unsigned int);
    // 0x007fa200
    void FUN_007fa200();
    // 0x007fa310
    void SetPipBoyObjectVisibility(bool, bool, bool);
    // 0x007fc2d0
    void FUN_007fc2d0(::NiAVObject *);
    // 0x00974d90
    bool IsUnk28Set();
};
