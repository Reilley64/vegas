#pragma once

namespace fnv_00d97130 { struct S_00d97130_Collector; }
namespace fnv_00d97130 { struct S_00d97130_Input; }
namespace fnv_00d97130 { struct S_00d97130_Track; }
struct Hdr;
struct Logger;
struct S_00d97360_Collector;
struct S_00d97360_Track;

// 0x00d97130
namespace fnv_00d97130 { void FUN_00d97130(::fnv_00d97130::S_00d97130_Track &, const ::fnv_00d97130::S_00d97130_Input *, ::fnv_00d97130::S_00d97130_Collector *); }
// 0x00d97250
void FUN_00d97250(::Hdr *, char **, ::Logger *);
// 0x00d97360
void CollectSectors(::S_00d97360_Track &, ::S_00d97360_Collector *);
