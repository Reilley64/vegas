#pragma once
#include <cstdint>

class BGSPerk;
class TESSound;
namespace fnv_00705420 { struct BSS; }
struct DecompArg12;
struct DecompVec3;
template <class> class BSSimpleList;

// 0x00705040
void FUN_00705040();
// 0x00705050
namespace fnv_00705050 { void *FUN_00705050(); }
// 0x00705070
namespace fnv_00705070 { void *FUN_00705070(void *, void *, void *); }
// 0x007050d0
namespace fnv_007050d0 { bool FUN_007050d0(); }
// 0x00705100
bool FUN_00705100();
// 0x00705110
void SetDialogMenuActive(bool);
// 0x00705190
::TESSound *GetDialogCastSound();
// 0x00705210
bool FUN_00705210(int, ::DecompArg12, ::DecompVec3, int, bool);
// 0x007052f0
bool DispatchMessageToSink(std::intptr_t, int, std::intptr_t, std::intptr_t, float, unsigned char);
// 0x007053b0
namespace fnv_007053b0 { void FUN_007053b0(); }
// 0x007053f0
namespace fnv_007053f0 { void FUN_007053f0(); }
// 0x00705420
namespace fnv_00705420 { void FUN_00705420(int, ::fnv_00705420::BSS, bool); }
// 0x007054f0
void FUN_007054f0(bool);
// 0x007055c0
void FUN_007055c0();
// 0x007056f0
namespace fnv_007056f0 { bool FUN_007056f0(); }
// 0x00705770
unsigned int FUN_00705770();
// 0x00705780
void FUN_00705780();
// 0x00705800
namespace fnv_00705800 { void FUN_00705800(); }
// 0x00705830
namespace fnv_00705830 { void FUN_00705830(int, int, unsigned char); }
// 0x00705870
void FUN_00705870(int);
// 0x007058e0
namespace fnv_007058e0 { void FUN_007058e0(); }
// 0x00705910
namespace fnv_00705910 { intptr_t FUN_00705910(); }
// 0x00705950
::BSSimpleList< ::BGSPerk *> *FUN_00705950();
// 0x00705990
namespace fnv_00705990 { int FUN_00705990(); }
// 0x007059d0
namespace fnv_007059d0 { void FUN_007059d0(); }
// 0x00705a00
namespace fnv_00705a00 { bool FUN_00705a00(); }
// 0x00705a60
namespace fnv_00705a60 { void FUN_00705a60(); }
// 0x00705a90
namespace fnv_00705a90 { int GetLODMultTypeIfKeySet(); }
// 0x00705ad0
namespace fnv_00705ad0 { void FUN_00705ad0(int); }
// 0x00705b30
namespace fnv_00705b30 { void FUN_00705b30(int); }
// 0x00705b70
namespace fnv_00705b70 { void FUN_00705b70(char, char, char, int); }
// 0x00705c40
int FUN_00705c40(int, char);
// 0x00705cb0
namespace fnv_00705cb0 { char FUN_00705cb0(); }
// 0x00705d10
namespace fnv_00705d10 { char FUN_00705d10(); }
// 0x00705d50
namespace fnv_00705d50 { char FUN_00705d50(); }
// 0x00705d90
namespace fnv_00705d90 { int FUN_00705d90(); }
// 0x00705e30
void FUN_00705e30();
// 0x00705ec0
namespace fnv_00705ec0 { bool FUN_00705ec0(void *); }
