#pragma once

class BGSLoadGameBuffer;

class FalloutRadio {
public:
    // 0x008324e0
    static bool SetRadioEnabled(bool);
    // 0x008329a0
    static void RefreshRadioReceivers(bool);
    // 0x00832ad0
    static bool Update(bool);
    // 0x00836af0
    static void InitLoadGame(::BGSLoadGameBuffer *);
    // 0x011dd438
    static unsigned int ms_uiRadioSyncFlags;
};
