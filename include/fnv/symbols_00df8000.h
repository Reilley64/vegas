#pragma once

namespace fnv_00df8570 { struct S00df8570_Enc; }
namespace fnv_00df8570 { struct S00df8570_Input; }
namespace fnv_00df8df0 { struct MeshRequest; }
struct InDF8800;
struct Interface;
struct Output;
struct S00df8440_Job;
struct S00df8440_Owner;
struct Source;
struct Spawned;
struct WorldDF8800;

// 0x00df8440
int FUN_00df8440(::S00df8440_Owner *, ::S00df8440_Job *);
// 0x00df8570
namespace fnv_00df8570 { int FUN_00df8570(::fnv_00df8570::S00df8570_Enc *, ::fnv_00df8570::S00df8570_Input *); }
// 0x00df8800
void *FUN_00df8800(::WorldDF8800 *, ::InDF8800 *);
// 0x00df89b0
void FUN_00df89b0(::Interface *, ::Source *, ::Output *, ::Spawned *);
// 0x00df8df0
namespace fnv_00df8df0 { void FUN_00df8df0(void *, ::fnv_00df8df0::MeshRequest *); }
