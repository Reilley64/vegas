#pragma once

struct GeomBufferDataQ;
struct GeometryQ;
struct SkinPartitionQ;

struct ShaderPrepQ {
public:
    // 0x00e812f0
    ::GeomBufferDataQ *PrepareShaderAndStreams(::GeometryQ *, ::SkinPartitionQ *, ::GeomBufferDataQ *, void *);
};
