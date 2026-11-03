#pragma once
#include <cstdint>

#include <cstdint>

class NiAVObject;
class NiNode;
class NiPropertyState;
class NiUpdateData;
namespace fnv_00a5e5b0 { struct NiStream; }

// 0x00a5e1f0
void FUN_00a5e1f0(::NiNode *, intptr_t, ::NiUpdateData &, unsigned int);
// 0x00a5e280
namespace fnv_00a5e280 { void UpdateChildControllers(::NiNode *, intptr_t, ::NiUpdateData &); }
// 0x00a5e3a0
void FUN_00a5e3a0(::NiAVObject *, intptr_t, ::NiPropertyState *&);
// 0x00a5e5b0
namespace fnv_00a5e5b0 { bool RegisterChildStreamables(::NiNode *, std::intptr_t, ::fnv_00a5e5b0::NiStream &); }
