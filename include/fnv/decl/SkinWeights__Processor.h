#pragma once

namespace SkinWeights { struct Geometry; }
namespace SkinWeights { struct Group; }

namespace SkinWeights {
struct Processor {
public:
    // 0x00a833b0
    bool ReduceGroupWeights(::SkinWeights::Geometry *, unsigned char, unsigned char, ::SkinWeights::Group *);
};
}
