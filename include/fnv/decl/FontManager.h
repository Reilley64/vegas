#pragma once

struct PageTable;

class FontManager {
public:
    // 0x005bd5b0
    static ::FontManager *Instance();
    // 0x00802220
    void FUN_00802220(::PageTable *, int, unsigned char);
};
