#pragma once

class DownloadableContentManager;

class BSSystemUtility {
public:
    // 0x005dfa10
    ::DownloadableContentManager &QDLCUtility();
    // 0x0078d020
    static void GetRandomGenerator();
    // 0x011da0c0
    static int s_iUpdateEnabled;
    // 0x011da0c4
    static ::BSSystemUtility *ms_pSystemUtility;
};
