// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSSAVELOADFILEENTRY_H
#define FNV_BGSSAVELOADFILEENTRY_H

#include "layout_support.h"
#include "_FILETIME.h"
class BGSSaveLoadFileEntry;
class NiTexture;
class BGSSaveLoadFileEntry
{
  public:
    char* pFileName;         // +0x0, 4 bytes
    bool m_bHeaderParsed;    // +0x4, 1 bytes
    bool m_bSaveEntryValid;  // +0x5, 1 bytes
    unsigned char layoutPadding6[2];
    unsigned int PathMetadataRecord;     // +0x8, 4 bytes
    char* m_pStringBeforeSaveFileName;   // +0xC, 4 bytes
    char* m_pSaveFileName;               // +0x10, 4 bytes
    char* pLocation;                     // +0x14, 4 bytes
    char* m_pStringAfterLocation;        // +0x18, 4 bytes
    unsigned int StringIntegerRecord;    // +0x1C, 4 bytes
    unsigned int m_uiHeaderRecordValue;  // +0x20, 4 bytes
    unsigned int m_uiFileSize;           // +0x24, 4 bytes
    unsigned int SaveFileMetadata;       // +0x28, 4 bytes
    _FILETIME FileTime;                  // +0x2C, 8 bytes
    int m_iScreenshotOffset;             // +0x34, 4 bytes
    int iVersion;                        // +0x38, 4 bytes
    char m_sModuleName[64];              // +0x3C, 64 bytes
    // void __cdecl BGSSaveLoadFileEntry::*(char*, int)
    // void __cdecl BGSSaveLoadFileEntry::*()
    // bool __cdecl BGSSaveLoadFileEntry::*()
    // bool __cdecl BGSSaveLoadFileEntry::*()
    // void __cdecl BGSSaveLoadFileEntry::*()
    // unsigned int __cdecl BGSSaveLoadFileEntry::*()
    // const char* __cdecl BGSSaveLoadFileEntry::*()
    // const char* __cdecl BGSSaveLoadFileEntry::*()
    // unsigned int __cdecl BGSSaveLoadFileEntry::*()
    // const char* __cdecl BGSSaveLoadFileEntry::*()
    // const char* __cdecl BGSSaveLoadFileEntry::*()
    // unsigned int __cdecl BGSSaveLoadFileEntry::*()
    // unsigned int __cdecl BGSSaveLoadFileEntry::*()
    // unsigned int __cdecl BGSSaveLoadFileEntry::*()
    // NiTexture* __cdecl BGSSaveLoadFileEntry::*()
    // void __cdecl BGSSaveLoadFileEntry::*()
    // void __cdecl BGSSaveLoadFileEntry::*(_FILETIME&)
    // void __cdecl BGSSaveLoadFileEntry::*(_FILETIME&)
    // int __cdecl BGSSaveLoadFileEntry::*()
    // char* __cdecl BGSSaveLoadFileEntry::*()
    // void __cdecl BGSSaveLoadFileEntry::*(unsigned int)
    // void __cdecl BGSSaveLoadFileEntry::*(char*)
    // void __cdecl BGSSaveLoadFileEntry::*(char*)
    // void __cdecl BGSSaveLoadFileEntry::*(unsigned int)
    // void __cdecl BGSSaveLoadFileEntry::*(char*)
    // void __cdecl BGSSaveLoadFileEntry::*(char*)
    // void __cdecl BGSSaveLoadFileEntry::*(unsigned int)
    // void __cdecl BGSSaveLoadFileEntry::*(unsigned int)
    // void __cdecl BGSSaveLoadFileEntry::*(unsigned int)
    // void __cdecl BGSSaveLoadFileEntry::*(int)
    // void __cdecl BGSSaveLoadFileEntry::*(char*)
    // void __cdecl BGSSaveLoadFileEntry::*()
    // bool __cdecl BGSSaveLoadFileEntry::*()
    // bool __cdecl BGSSaveLoadFileEntry::*()
    // bool __cdecl BGSSaveLoadFileEntry::*()
    // ReadTypedData
    // void* __cdecl BGSSaveLoadFileEntry::*(unsigned int)
    bool IsAutoSave();
    bool IsSaveEntryValid();
    NiTexture* ReadScreenshotFromFile();
    void ReadTypedData();
};
#endif
