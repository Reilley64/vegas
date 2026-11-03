#pragma once

struct GeomS;
struct MatS;
struct PropS;

struct ShaderS {
public:
    // 0x00b795b0
    void ApplyFogAndAlpha(unsigned int, void *, ::GeomS *, void *, ::PropS *, ::MatS *);
};
