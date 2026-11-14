#pragma once
#include <cstdint>

struct NiObject;
namespace fnv_00a36f80 { struct BlendInterpS; }
namespace fnv_00a36f80 { struct StreamS; }
namespace fnv_00a36fd0 { struct BlendS; }
namespace fnv_00a36fd0 { struct ObjS; }

// 0x00a36810
::NiObject *FUN_00a36810();
// 0x00a36f80
namespace fnv_00a36f80 { bool FUN_00a36f80(::fnv_00a36f80::BlendInterpS *, int, ::fnv_00a36f80::StreamS &); }
// 0x00a36fd0
namespace fnv_00a36fd0 { bool FUN_00a36fd0(::fnv_00a36fd0::BlendS *, intptr_t, ::fnv_00a36fd0::ObjS *); }
