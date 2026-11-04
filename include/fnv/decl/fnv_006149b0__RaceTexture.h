#pragma once

class TESNPC;
enum BIPED_OBJECT;
namespace fnv_006149b0 { class NiSourceTexture; }
namespace fnv_006149b0 { class NiTexture; }
namespace fnv_006149b0 { template <class> class NiPointer; }

namespace fnv_006149b0 {
struct RaceTexture {
public:
    // 0x006149b0
    bool ApplyBodyTexture(::fnv_006149b0::NiPointer< ::fnv_006149b0::NiSourceTexture> &, ::fnv_006149b0::NiPointer< ::fnv_006149b0::NiTexture> &, ::TESNPC *, ::BIPED_OBJECT, bool);
};
}
