#pragma once

class SaveLoadHeader;

class BGSSaveLoadManager {
public:
    // 0x00850100
    void FUN_00850100(::SaveLoadHeader *, int);
    // 0x00850760
    bool LoadGame(const char *, int, bool, bool);
    // 0x00850b40
    static void BuildAutosaveName(char *);
    // 0x00850c20
    void ProcessQueuedLoads();
    // 0x00850fe0
    bool CanSave(bool);
    // 0x00851120
    void GetFNVVersionInfo(char *, unsigned int);
    // 0x008512f0
    bool FUN_008512f0();
    // 0x00851980
    bool IsSaveFileNameDefault(const char *);
    // 0x00851a20
    bool IsSaveFileNameLegacyAutosave(const char *);
    // 0x00851a60
    bool IsQuickSaveFileName(const char *);
    // 0x00851b00
    bool IsAutoSaveFileName(const char *);
    // 0x00851d10
    void UpdateSaveTimestamp();
    // 0x00851d90
    void ProcessQueuedSaveLoad();
    // 0x00876ad0
    static void GetSaveDirectory(char *);
};
