#pragma once
#include <cstdint>

class NiFixedString;
class TESObjectREFR;
namespace fnv_005a0150 { class ActorV; }
namespace fnv_005a0b60 { struct Obj; }
namespace fnv_005a0e80 { class ActorW; }
namespace fnv_005a0f90 { class ActorC; }
namespace fnv_005a0f90 { class FormC; }

// 0x005a0040
bool FUN_005a0040(::TESObjectREFR *, void *, void *, double &);
// 0x005a00a0
unsigned int FUN_005a00a0(uintptr_t);
// 0x005a00c0
bool FUN_005a00c0(::TESObjectREFR *, void *, void *, double &);
// 0x005a0150
namespace fnv_005a0150 { bool FUN_005a0150(::fnv_005a0150::ActorV *, void *, void *, double &); }
// 0x005a01f0
bool FUN_005a01f0(::TESObjectREFR *, void *, void *, double &);
// 0x005a0260
bool FUN_005a0260(::TESObjectREFR *, void *, void *, double &);
// 0x005a02f0
namespace fnv_005a02f0 { bool FUN_005a02f0(::TESObjectREFR *, void *, void *, double &); }
// 0x005a05e0
namespace fnv_005a05e0 { bool FUN_005a05e0(::TESObjectREFR *, void *, void *, double &); }
// 0x005a0710
namespace fnv_005a0710 { bool FUN_005a0710(::TESObjectREFR *, void *, void *, double &); }
// 0x005a07f0
::NiFixedString *FUN_005a07f0();
// 0x005a0800
namespace fnv_005a0800 { bool FUN_005a0800(::TESObjectREFR *, void *, void *, double &); }
// 0x005a08c0
bool FUN_005a08c0(::TESObjectREFR *, void *, void *, double *);
// 0x005a09b0
namespace fnv_005a09b0 { bool FUN_005a09b0(::TESObjectREFR *, void *, void *, double &); }
// 0x005a0ab0
namespace fnv_005a0ab0 { bool IsWeaponSkillType(::TESObjectREFR *, void *, void *, double &); }
// 0x005a0b60
namespace fnv_005a0b60 { bool FUN_005a0b60(::fnv_005a0b60::Obj *, int, int, double *); }
// 0x005a0e80
namespace fnv_005a0e80 { bool FUN_005a0e80(::fnv_005a0e80::ActorW *, void *, void *, double &); }
// 0x005a0f10
bool FUN_005a0f10(::TESObjectREFR *, void *, void *, double *);
// 0x005a0f90
namespace fnv_005a0f90 { bool FUN_005a0f90(::fnv_005a0f90::ActorC *, ::fnv_005a0f90::FormC *, void *, double &); }
