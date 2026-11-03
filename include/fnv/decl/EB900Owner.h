#pragma once

class EB900Entry;

class EB900Owner {
public:
    // 0x005eb900
    ::EB900Entry *FindEntryByLevel(unsigned char);
};
