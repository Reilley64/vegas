#pragma once

class D45480Object;
struct CdBody;
struct CollisionInput;
struct FUN_00cfbbe0;
struct S_00d45dd0_CdBody;
struct S_00d45dd0_CollectorBase;
struct S_00d45dd0_Input;

// 0x00d45480
::D45480Object *FUN_00d45480(void *, void *, void *, void *);
// 0x00d45800
void FUN_00d45800(::CdBody *, ::CdBody *, ::CollisionInput *, void *, void *);
// 0x00d45af0
void FUN_00d45af0(::CdBody *, ::CdBody *, ::CollisionInput *, void *);
// 0x00d45dd0
void FUN_00d45dd0(const ::S_00d45dd0_CdBody &, const ::S_00d45dd0_CdBody &, const ::S_00d45dd0_Input &, ::S_00d45dd0_CollectorBase &);
// 0x00d45f30
namespace fnv_00d45f30 { void *FUN_00d45f30(int, int, int, int); }
// 0x00d45f80
void ConfigureVtblHandlers(::FUN_00cfbbe0 *);
