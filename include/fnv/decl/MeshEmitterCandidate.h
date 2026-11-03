#pragma once

struct MeshPoint;
struct NiGeometry;

struct MeshEmitterCandidate {
public:
    // 0x00c1dae0
    bool PickEmitterParticle(::NiGeometry *, ::MeshPoint &, ::MeshPoint &);
};
