#pragma once

#include <cstdint>

class Actor;
struct BGSSaveFormBuffer;
namespace fnv_005aaaf0 { struct BGSLoadFormBuffer; }

// 0x005aa500
namespace fnv_005aa500 { void FUN_005aa500(std::intptr_t, unsigned char); }
// 0x005aa5d0
namespace fnv_005aa5d0 { void FUN_005aa5d0(std::intptr_t); }
// 0x005aa630
namespace fnv_005aa630 { bool FUN_005aa630(::Actor *); }
// 0x005aa680
namespace fnv_005aa680 { bool FUN_005aa680(::Actor *); }
// 0x005aa6d0
namespace fnv_005aa6d0 { char FUN_005aa6d0(int *); }
// 0x005aa720
namespace fnv_005aa720 { void FUN_005aa720(); }
// 0x005aa930
void WriteReferenceLists(::BGSSaveFormBuffer *);
// 0x005aaaf0
namespace fnv_005aaaf0 { void LoadReferenceLists(::fnv_005aaaf0::BGSLoadFormBuffer *); }
// 0x005aae20
namespace fnv_005aae20 { void FUN_005aae20(); }
// 0x005aaee0
char *AllocateZeroed(unsigned int, unsigned int);
