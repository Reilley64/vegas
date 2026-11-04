#pragma once
#include <cstdint>

struct VertexBufferLockInfo;
struct VertexData;
struct VertexSource;

struct VertexRenderer {
public:
    // 0x00e8c820
    ::VertexBufferLockInfo *FUN_00e8c820(::VertexSource *, uintptr_t, ::VertexData *, unsigned int, ::VertexBufferLockInfo *, char *);
};
