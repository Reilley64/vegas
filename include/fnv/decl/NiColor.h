#pragma once

struct NiStream;

struct NiColor {
public:
    // 0x00a59be0
    void LoadBinary(::NiStream &);
    // 0x00a696c0
    char *GetFormattedString(const char *) const;
    // 0x00a69780
    void SaveBinary(::NiStream &);
};
