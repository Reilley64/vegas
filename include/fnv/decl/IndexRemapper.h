#pragma once

struct IndexBuffer;

struct IndexRemapper {
public:
    // 0x00d28120
    void RemapIndices(::IndexBuffer *);
};
