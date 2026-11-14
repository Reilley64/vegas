#pragma once

namespace fnv_00d95cf0 { struct Command; }
namespace fnv_00d95cf0 { struct Queue; }
namespace fnv_00d95cf0 { struct TaskOwner; }
struct BuildCollection;
struct FlagByte;
struct JobHeader;
struct SceneInput;
struct SolveCollection;

// 0x00d95130
void FUN_00d95130(::SceneInput, ::FlagByte, ::JobHeader *, ::BuildCollection *, ::SolveCollection *);
// 0x00d95cf0
namespace fnv_00d95cf0 { int FUN_00d95cf0(::fnv_00d95cf0::TaskOwner &, ::fnv_00d95cf0::Queue &, ::fnv_00d95cf0::Command &); }
