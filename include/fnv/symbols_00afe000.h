#pragma once

class Actor;
namespace fnv_00afe7d0 { struct _FILETIME; }
struct FileMatchList;
template <class> class BSSimpleList;

// 0x00afe420
::FileMatchList *FUN_00afe420(const char *, const char *, unsigned int, ::FileMatchList *);
// 0x00afe5b0
::BSSimpleList< ::Actor *> *FUN_00afe5b0(const char *, const char *, int, ::BSSimpleList< ::Actor *> *);
// 0x00afe7d0
namespace fnv_00afe7d0 { bool FUN_00afe7d0(const char *, ::fnv_00afe7d0::_FILETIME &, unsigned int); }
