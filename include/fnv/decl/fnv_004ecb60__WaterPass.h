#pragma once

class WaterSurface;
namespace fnv_004ecb60 { struct NiCamera; }

namespace fnv_004ecb60 {
struct WaterPass {
public:
    // 0x004ecb60
    void RenderWaterGroup(::fnv_004ecb60::NiCamera *, ::WaterSurface *, int, unsigned short);
};
}
