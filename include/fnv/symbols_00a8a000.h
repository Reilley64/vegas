#pragma once
struct NiStream;

class NiTriBasedGeomData;
struct NiPairHolder;

// 0x00a8a240
namespace fnv_00a8a240 { void FreeMemoryList(); }
// 0x00a8a700
::NiPairHolder *CreateNiPairHolder();
// 0x00a8a970
::NiTriBasedGeomData *InitializeTriBasedGeomData(::NiTriBasedGeomData *);
// 0x00a8a9a0
struct FUN_00a8a9a0_shell { void FUN_00a8a9a0(::NiStream& kStream); };
