#pragma once

struct QuadInput;

struct QuadRenderer {
public:
    // 0x00e723a0
    void UploadQuads(::QuadInput *, unsigned short);
};
