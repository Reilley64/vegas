#pragma once

struct FileReader;

struct WorldReader {
public:
    // 0x005854f0
    bool SeekToCellInWorld(::FileReader *, int, int);
};
