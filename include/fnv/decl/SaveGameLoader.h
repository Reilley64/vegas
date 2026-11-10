#pragma once

struct BGSLoadGameBuffer;

class SaveGameLoader {
public:
    // 0x0084c330
    static bool LoadFormRange(unsigned int, ::BGSLoadGameBuffer *, bool);
};
