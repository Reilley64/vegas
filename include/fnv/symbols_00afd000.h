#pragma once

namespace fnv_00afd4e0 { struct FileNameHash; }
struct FileNameHash;

// 0x00afd270
void HashPathComponents(const char *, ::FileNameHash *, ::FileNameHash *);
// 0x00afd4e0
namespace fnv_00afd4e0 { void ComputeNameHash(const unsigned char *, const unsigned char *, ::fnv_00afd4e0::FileNameHash *); }
// 0x00afde50
bool FUN_00afde50(const char *, int);
// 0x00afdf00
void FUN_00afdf00(const char *, int, unsigned int);
