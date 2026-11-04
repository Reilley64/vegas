#pragma once

namespace DecalAdd { struct DecalRequest; }

namespace DecalAdd {
struct DecalManager {
public:
    // 0x004a10d0
    void AddGeometryDecal(::DecalAdd::DecalRequest *, int, bool);
};
}
