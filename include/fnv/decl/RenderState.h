#pragma once

struct Descriptor;
struct RenderModes;

struct RenderState {
public:
    // 0x00e8bb70
    void ApplyRenderModes(void *, ::Descriptor *, ::RenderModes *);
};
