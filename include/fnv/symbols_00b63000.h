#pragma once

class BB63F90Accumulator;
class BB63F90Geometry;
class NiNode;
namespace fnv_00b63620 { struct AccumStub; }
namespace fnv_00b63a50 { struct AccumStub; }
struct FUN_00b63320_Pass;

// 0x00b630f0
bool FUN_00b630f0(unsigned int);
// 0x00b63320
void FUN_00b63320(::FUN_00b63320_Pass *, unsigned int);
// 0x00b63420
::NiNode *CreateRenderPassesNode();
// 0x00b63620
namespace fnv_00b63620 { void FUN_00b63620(::fnv_00b63620::AccumStub *); }
// 0x00b63a50
namespace fnv_00b63a50 { void FUN_00b63a50(::fnv_00b63a50::AccumStub *); }
// 0x00b63f90
bool AccumulateRenderPasses(::BB63F90Accumulator *, int, int, ::BB63F90Geometry *);
