#pragma once

struct hkStreamWriter;

struct FNVWorldObject {
public:
    // 0x00cd2b00
    void WriteToStream(::hkStreamWriter *, const void *);
};
