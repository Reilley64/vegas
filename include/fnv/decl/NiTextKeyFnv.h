#pragma once

struct FNVStream;

struct NiTextKeyFnv {
public:
    // 0x00a57930
    void ReadFromStream(::FNVStream &);
};
