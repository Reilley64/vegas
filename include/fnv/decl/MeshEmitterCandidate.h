#pragma once

struct MeshPoint;
class NiGeometry;

struct MeshEmitterCandidate {
public:
    // 0x00c1dae0
    bool PickEmitterParticle(::NiGeometry *, ::MeshPoint &, ::MeshPoint &);
};
