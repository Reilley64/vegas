#pragma once

struct FileNameHash;

namespace fnv_00af7060 { struct ArchiveSearch; }
namespace fnv_00af7060 { struct Filter; }
namespace fnv_00af7060 { struct HashKey; }
namespace fnv_00af7060 { struct PathNode; }

// 0x00af7060
namespace fnv_00af7060 { ::fnv_00af7060::HashKey **FUN_00af7060(::fnv_00af7060::ArchiveSearch *, unsigned int, ::fnv_00af7060::HashKey **, ::FileNameHash *, ::fnv_00af7060::Filter *, ::fnv_00af7060::PathNode *, const char *); }
// 0x00af7400
namespace fnv_00af7400 { bool ResolveArchivePath(const char *, char *, unsigned int); }
// 0x00af7c40
void ProcessFilesByType(::FileNameHash *, ::FileNameHash *, unsigned int);
// 0x00af7d80
int FUN_00af7d80(const char *);
// 0x00af7db0
namespace fnv_00af7db0 { unsigned int LookupExtensionType(const char *); }
