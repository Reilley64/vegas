#pragma once

class MessageHandler {
public:
    // 0x0045a330
    const char *GetWarningFileName();
    // 0x004694c0
    float GetSpeechProgress();
    // 0x006259f0
    static ::MessageHandler &Handler();
    // 0x00c3bcf0
    ::MessageHandler *FUN_00c3bcf0(bool);
    // 0x01202d74
    static ::MessageHandler *pHandler;
};
