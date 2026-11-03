#pragma once

class BSShader;

class ParticleShader {
public:
    // 0x00ba52d0
    static unsigned int GetShaderParticleCount();
    // 0x00ba58b0
    static ::BSShader *CreateShader();
};
