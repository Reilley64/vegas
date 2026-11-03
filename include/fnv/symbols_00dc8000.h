#pragma once

namespace fnv_00dc88c0 { union hkDataValueDC88; }
struct HashEntryTable;

// 0x00dc88c0
namespace fnv_00dc88c0 { void ReleaseDataValues(int, ::fnv_00dc88c0::hkDataValueDC88 *, int); }
// 0x00dc8e30
unsigned long LookupWithDefault(::HashEntryTable *, int, unsigned long);
