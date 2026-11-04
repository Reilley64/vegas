#pragma once

struct Tile {
public:
    // 0x006faa90
    void SetNodeFloat(float);
    // 0x00700320
    void Set(int, int);
    // 0x00707e10
    void SetName(const char *);
    // 0x00715c60
    void Set(int, unsigned int);
    // 0x0071aa80
    bool GetSpeechChallengeFailure();
    // 0x00a01530
    static float GetInterfaceScale();
    // 0x00a03c60
    bool IsMenuRendered();
    // 0x00a04620
    void SetSpeechChallengeFailure(bool);
    // 0x00a0bb00
    static bool IsSpecialTileName(const char *);
};
