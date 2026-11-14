#pragma once

namespace fnv_00d11d00 { struct PairArray; }
namespace fnv_00d11d00 { struct TagEntity; }
namespace fnv_00d11d00 { struct TagOwner; }
struct FUN_00d11c10_cls;
struct FnvArr;
struct FnvNode;
struct PairArray;
struct UnkRet;

// 0x00d11bc0
void AppendPairToBuffer(::UnkRet *, ::UnkRet *, void *);
// 0x00d11c10
void AppendPairEntry(::FUN_00d11c10_cls *, ::FUN_00d11c10_cls *, ::PairArray *);
// 0x00d11c60
void FUN_00d11c60(void *, ::FnvNode *, unsigned short, ::FnvNode *, ::FnvArr *);
// 0x00d11d00
namespace fnv_00d11d00 { void RemoveOrAppendTagEntry(char *, ::fnv_00d11d00::TagEntity *, unsigned int, ::fnv_00d11d00::TagOwner *, ::fnv_00d11d00::PairArray *); }
