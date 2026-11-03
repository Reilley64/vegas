#pragma once

class BSExtraData;
class BaseExtraList;
namespace s40fa40 { struct Entry; }
namespace s40fa40 { struct Owner; }

// 0x0040f740
void *FUN_0040f740(int *);
// 0x0040f860
void ResetTlsBufferIfListMatches(const ::BaseExtraList *);
// 0x0040f900
namespace fnv_0040f900 { void ResetTlsBufferIfStale(); }
// 0x0040f980
bool FUN_0040f980(int);
// 0x0040f9e0
::BSExtraData *FUN_0040f9e0(::BaseExtraList *, int);
// 0x0040fa40
namespace s40fa40 { void FUN_0040fa40(::s40fa40::Owner *, ::s40fa40::Entry *); }
// 0x0040fbe0
void FUN_0040fbe0(...);
// 0x0040fca0
void FUN_0040fca0(unsigned long);
