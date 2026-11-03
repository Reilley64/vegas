#pragma once

class NiTexture;

class BGSSaveLoadFileEntry {
public:
    // 0x007d5140
    char *FUN_007d5140();
    // 0x00846820
    ::NiTexture *ReadScreenshotFromFile();
    // 0x00846900
    void ReadTypedData();
    // 0x00846b10
    bool IsAutoSave();
    // 0x00846b30
    bool IsSaveEntryValid();
    // 0x00851ef0
    void *FUN_00851ef0();
};
