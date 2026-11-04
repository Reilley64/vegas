#pragma once

struct ParticleSource;

struct TempEffectListOwner {
public:
    // 0x00974290
    void RemoveParticleEffectsBySource(::ParticleSource *);
};
