#pragma once

struct DirFileTime;
template <class> class BSSimpleList;

// 0x00b013f0
void *FUN_00b013f0();
// 0x00b014b0
const char *SkipDataPrefix(const char *);
// 0x00b01930
void CollectDirectoryEntries(const char *, const char *, ::BSSimpleList<char *> *);
// 0x00b01b60
bool FUN_00b01b60(const char *, ::DirFileTime *);
