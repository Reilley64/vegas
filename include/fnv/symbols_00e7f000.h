#pragma once

class BeamStage;
struct FUN_00e7ee80;
struct Node_00e7f000;
struct Self_00e7f000;
template <class> class NiPointer;

// 0x00e7f000
::Node_00e7f000 *FindNodeByKey(::Self_00e7f000 *, int, int, bool &);
// 0x00e7f050
namespace fnv_00e7f050 { void *FUN_00e7f050(void *, int, unsigned int); }
// 0x00e7f070
namespace fnv_00e7f070 { void FUN_00e7f070(void *); }
// 0x00e7f0a0
::FUN_00e7ee80 *FUN_00e7f0a0(unsigned int);
// 0x00e7f2b0
namespace fnv_00e7f2b0 { void FUN_00e7f2b0(); }
// 0x00e7f610
void DestroyGlobalQueues();
// 0x00e7f7c0
int FUN_00e7f7c0();
// 0x00e7f900
namespace fnv_00e7f900 { void *FUN_00e7f900(void *, int, unsigned int); }
// 0x00e7f920
void FUN_00e7f920(int);
// 0x00e7fcd0
void FreePointerArray(::NiPointer< ::BeamStage> *);
