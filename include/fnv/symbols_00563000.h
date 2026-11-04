#pragma once

namespace fnv_00563220 { struct SaveRequest; }
namespace fnv_00563220 { struct bhkCollisionObject; }
namespace fnv_00563f30 { struct AnimationInterpolatorNode; }
namespace fnv_00563f30 { struct BGSSaveFormBuffer; }
struct Arg2_S;
struct CollObj_S;
struct Param_563380;
struct bhkCollisionObject_563380;

// 0x00563120
void FUN_00563120(::CollObj_S *, ::Arg2_S *);
// 0x00563220
namespace fnv_00563220 { void FUN_00563220(::fnv_00563220::bhkCollisionObject *, ::fnv_00563220::SaveRequest *); }
// 0x00563380
void FUN_00563380(::bhkCollisionObject_563380 *, ::Param_563380 *);
// 0x00563f30
namespace fnv_00563f30 { void FUN_00563f30(::fnv_00563f30::AnimationInterpolatorNode *, ::fnv_00563f30::BGSSaveFormBuffer *, float); }
