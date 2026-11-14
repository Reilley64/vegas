#pragma once

namespace fnv_00af6160 { struct Archive; }
namespace fnv_00af6340 { struct ArchiveFile; }
namespace fnv_00af6340 { struct BSFileEntry; }
namespace fnv_00af6540 { struct BSFileEntry; }
namespace fnv_00af6540 { struct FileNameHash; }
struct FileNameHash;
struct LNode;
struct LookupArchive;
struct SortKey;

// 0x00af6160
namespace fnv_00af6160 { ::fnv_00af6160::Archive *FindArchiveForFile(const char *, unsigned int); }
// 0x00af6340
namespace fnv_00af6340 { ::fnv_00af6340::ArchiveFile *FUN_00af6340(int, ::fnv_00af6340::BSFileEntry *, unsigned int, unsigned int); }
// 0x00af6540
namespace fnv_00af6540 { ::fnv_00af6540::BSFileEntry *FindFileEntryInArchives(int, ::fnv_00af6540::FileNameHash &, ::fnv_00af6540::FileNameHash &, const char *); }
// 0x00af6910
::LookupArchive *FindArchiveByKey(const ::FileNameHash *, unsigned int);
// 0x00af6ba0
void FUN_00af6ba0(::LNode *, const char *, const char *, unsigned int);
// 0x00af6e50
void QuickSortSortKeys(::SortKey **, int, int);
