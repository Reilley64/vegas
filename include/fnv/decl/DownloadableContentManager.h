#pragma once

class ContentMountRecord;

class DownloadableContentManager {
public:
    // 0x004c69f0
    bool IsDLCAvailable();
    // 0x00af26c0
    static ::DownloadableContentManager &GetRandomGenerator();
    // 0x00af2b10
    unsigned int MountDownloadableContent(unsigned int, void (*)(unsigned int, unsigned int, bool, const ContentMountRecord *));
};
