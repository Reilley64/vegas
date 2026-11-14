#pragma once

struct SaveFile;

struct SaveOwner {
public:
    // 0x00857370
    ::SaveFile *OpenSaveFile(::SaveFile *, const char *, unsigned int);
};
