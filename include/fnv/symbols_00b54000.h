#pragma once

class BSShaderAccumulator;
class NiTexture;
struct NativeB66810;
struct NiGeometry;

// 0x00b54090
::NiTexture *GetImageSpaceTexture();
// 0x00b540b0
void FUN_00b540b0();
// 0x00b540d0
void FUN_00b540d0();
// 0x00b540f0
int PopNextInt();
// 0x00b54630
namespace fnv_00b54630 { namespace CleanupState { void FUN_00b54630(bool); } }
// 0x00b54ac0
void FUN_00b54ac0(::NiTexture *);
// 0x00b54b10
void FUN_00b54b10(::BSShaderAccumulator *);
// 0x00b54b60
::NativeB66810 *FUN_00b54b60(::NiGeometry *);
