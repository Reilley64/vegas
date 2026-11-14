#pragma once

namespace fnv_00c1eb20 { struct MeshPoint; }
class NiGeometry;

namespace fnv_00c1eb20 {
struct MeshEmitterCandidate {
public:
    // 0x00c1eb20
    bool EmitFromMesh(::NiGeometry *, ::fnv_00c1eb20::MeshPoint &, ::fnv_00c1eb20::MeshPoint &);
};
}
