#pragma once

struct EffectData;
struct SceneValue;

struct ShaderSource {
public:
    // 0x00507830
    ::EffectData *CreateEffectData(::SceneValue *, void *, void *);
};
