#pragma once

struct Descriptor;
struct Geometry;
struct PropertyState;

struct ShaderHost {
public:
    // 0x00e8d890
    void BindShaderInput(::Descriptor *, ::Geometry *, ::PropertyState *);
};
