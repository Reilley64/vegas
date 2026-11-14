#pragma once

struct BGSLoadFormBuffer;
struct OutputA;

struct HostA {
public:
    // 0x006c1590
    void RemoveEntry(unsigned int);
    // 0x00760bd0
    void WriteTextUntilDelimiter(::OutputA *);
    // 0x009a2a30
    void FUN_009a2a30(::BGSLoadFormBuffer *);
    // 0x00a90ac0
    void ReleaseResources();
};
