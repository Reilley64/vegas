#pragma once

struct SaveMetadataReader {
public:
    // 0x008600b0
    int ReadSaveMetadata(const char *, unsigned int *, char *, char *, char *, char *, char *, char *, unsigned int *, bool);
};
