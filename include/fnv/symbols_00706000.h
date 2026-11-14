#pragma once
#include <cstdint>

class NiAVObject;
namespace fnv_007062e0 { class TESObjectREFR; }
namespace fnv_00706860 { struct BGSLoadGameBuffer; }
struct Buffer;
struct TutorialManagerLayout;

// 0x00706130
bool FUN_00706130(intptr_t);
// 0x00706230
namespace fnv_00706230 { void FUN_00706230(int, int); }
// 0x00706270
namespace fnv_00706270 { void FUN_00706270(); }
// 0x007062a0
void FUN_007062a0(int, int, unsigned char, unsigned char);
// 0x007062e0
namespace fnv_007062e0 { bool FUN_007062e0(::fnv_007062e0::TESObjectREFR *, bool, bool); }
// 0x00706320
void FUN_00706320(int);
// 0x007065c0
namespace fnv_007065c0 { unsigned short FUN_007065c0(); }
// 0x00706610
void SaveMenuTabStates();
// 0x007066d0
void FUN_007066d0(::Buffer *);
// 0x00706860
namespace fnv_00706860 { void LoadMenuState(::fnv_00706860::BGSLoadGameBuffer *); }
// 0x007069d0
void FUN_007069d0(unsigned char);
// 0x00706a20
void FUN_00706a20(unsigned char);
// 0x00706a40
void SetInventoryTab(int);
// 0x00706a90
namespace fnv_00706a90 { void FUN_00706a90(); }
// 0x00706ac0
void ClearMapMenuNote();
// 0x00706ae0
void ResetInterfaceState();
// 0x00706b90
void ResetEntries(::TutorialManagerLayout *);
// 0x00706c20
void ClearInterfaceRefs(uintptr_t);
// 0x00706d10
uintptr_t FUN_00706d10();
// 0x00706d50
void AttachFaceGenAnimationData(::NiAVObject *);
// 0x00706db0
void FUN_00706db0(unsigned char);
// 0x00706dd0
void SetFlagAtOffsetDC(bool);
// 0x00706e20
float FUN_00706e20();
// 0x00706e50
float FUN_00706e50();
// 0x00706e80
float FUN_00706e80();
// 0x00706e90
float FUN_00706e90();
// 0x00706f20
unsigned int FUN_00706f20();
// 0x00706f30
void FUN_00706f30(intptr_t);
// 0x00706f50
void FUN_00706f50(void *, float);
// 0x00706f90
void FUN_00706f90(int);
// 0x00706fb0
void FUN_00706fb0(int);
// 0x00706fd0
int FUN_00706fd0(int, bool);
// 0x00706ff0
void FUN_00706ff0(intptr_t);
