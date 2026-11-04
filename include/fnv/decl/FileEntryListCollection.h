#pragma once

class TESFile;
class TESModelList;

struct FileEntryListCollection {
public:
    // 0x0048a0d0
    void LoadFromTESFile(::TESModelList *, ::TESFile *);
};
