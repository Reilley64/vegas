#pragma once
#include <cstdint>

namespace fnv_00dc88c0 { union hkDataValueDC88; }
struct HashEntryTable;

// 0x00dc88c0
namespace fnv_00dc88c0 { void ReleaseDataValues(intptr_t, ::fnv_00dc88c0::hkDataValueDC88 *, int); }
// 0x00dc8e30
unsigned long LookupWithDefault(::HashEntryTable *, intptr_t, unsigned long);
