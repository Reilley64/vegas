#pragma once

class DispatcherDA34;
class hkpShapeContainer;
namespace fnv_00da3480 { struct DispatcherDA34; }
struct AgentProcessingInput;
struct AgentSectorPointerArray;
struct CollisionAgentContext;
struct Da35Stream;
struct S_00da40e0_AgentData;
struct S_00da40e0_Entry;
struct S_00da40e0_Input;
struct WorldOperationEntry;

// 0x00da3400
void FUN_00da3400(::DispatcherDA34 *);
// 0x00da3480
namespace fnv_00da3480 { void FUN_00da3480(::fnv_00da3480::DispatcherDA34 *); }
// 0x00da3510
void FUN_00da3510(::AgentSectorPointerArray &, ::CollisionAgentContext &);
// 0x00da35f0
void FUN_00da35f0(::Da35Stream ***, float, float, void **);
// 0x00da3930
void FUN_00da3930(::AgentProcessingInput &, const ::hkpShapeContainer *, ::WorldOperationEntry &);
// 0x00da3f90
::S_00da40e0_Entry *ProcessEntryPair(const ::S_00da40e0_Input &, ::S_00da40e0_Entry *, ::S_00da40e0_AgentData *);
