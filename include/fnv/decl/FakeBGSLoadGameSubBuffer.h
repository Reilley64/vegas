#pragma once

struct BGSSaveGameBuffer;

struct FakeBGSLoadGameSubBuffer {
public:
    // 0x00865510
    void WriteToSaveGameBuffer(::BGSSaveGameBuffer *);
};
