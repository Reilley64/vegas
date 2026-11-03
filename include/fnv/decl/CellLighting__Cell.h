#pragma once

namespace CellLighting { struct Vec3; }

namespace CellLighting {
struct Cell {
public:
    // 0x00555f60
    void UpdateLightingAtPoint(const ::CellLighting::Vec3 *);
};
}
