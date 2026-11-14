#pragma once

struct GridCell;

class GridCellArray {
public:
    // 0x004ba490
    ::GridCell *Get(unsigned int, unsigned int);
};
