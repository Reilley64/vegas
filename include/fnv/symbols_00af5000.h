#pragma once

namespace fnv_00af5320 { class Archive; }
namespace fnv_00af5550 { class MyArchiveFile; }

// 0x00af5320
namespace fnv_00af5320 { ::fnv_00af5320::Archive *FindArchiveByName(const char *); }
// 0x00af5550
namespace fnv_00af5550 { bool RemoveArchiveFile(::fnv_00af5550::MyArchiveFile *); }
// 0x00af5820
void ClearArchiveTables();
// 0x00af59f0
void ProcessArcList();
// 0x00af5ab0
void FUN_00af5ab0(const char *);
// 0x00af5e40
bool HasFileInArchives(const char *);
// 0x00af5fa0
namespace fnv_00af5fa0 { void *LoadFileFromArchives(const char *, unsigned int, unsigned int); }
