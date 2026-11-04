#pragma once

class BGSLoadGameBuffer;

class LoadingMenu {
public:
    // 0x00458080
    void SetFloatFlag(int, bool);
    // 0x00458110
    bool GetFloat(int);
    // 0x00717740
    static void SetLoadingScreenVisible(int);
    // 0x0078abd0
    void UpdateLoadingScreenTip();
    // 0x0078aec0
    void RefreshLoadingScreen();
    // 0x0078cfc0
    static void UpdateLoadingScreenThread();
    // 0x0078d2d0
    static void HideTile();
    // 0x0078d770
    static void LoadGame(::BGSLoadGameBuffer *);
};
