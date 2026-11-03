#pragma once

namespace ActorValue { enum Index; }

// 0x0066f110
extern "C" void ClearActorValueSlots();
// 0x0066f190
namespace ActorValue { float ClampValue(::ActorValue::Index, float); }
// 0x0066f260
namespace ActorValue { void LoadActorValueDefinitions(); }
