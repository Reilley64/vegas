#pragma once

struct NiStream;

struct NiPointLightSave {
public:
    // 0x00a7d840
    void SaveToStream(::NiStream *);
};
