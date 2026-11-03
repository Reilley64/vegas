#pragma once

struct VertexBufferLockInfo;
struct VertexData;
struct VertexSource;

struct VertexRenderer {
public:
    // 0x00e8c820
    ::VertexBufferLockInfo *FUN_00e8c820(::VertexSource *, unsigned int, ::VertexData *, unsigned int, ::VertexBufferLockInfo *, char *);
};
