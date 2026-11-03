#pragma once

class Modifier;
class TESDataHandler;
namespace fnv_00560870 { class NiAVObject; }
namespace fnv_00560870 { struct VisitDataStandIn; }
namespace fnv_00560d80 { struct hkVector4; }
namespace fnv_00560e70 { struct CollisionLoad; }
namespace fnv_00560e70 { struct ContextLoad; }
struct FUN_00560d10_shell;
struct PSRef;
struct PSSaveContext;

// 0x00560870
namespace fnv_00560870 { void FUN_00560870(::fnv_00560870::NiAVObject *, ::fnv_00560870::VisitDataStandIn *); }
// 0x00560a10
void FUN_00560a10(::PSRef *, ::PSSaveContext *);
// 0x00560c80
::Modifier *CopyModifierSettings(::Modifier *, ::FUN_00560d10_shell *);
// 0x00560d80
namespace fnv_00560d80 { const ::fnv_00560d80::hkVector4 &FUN_00560d80(void *); }
// 0x00560dc0
int FUN_00560dc0(::TESDataHandler *);
// 0x00560e70
namespace fnv_00560e70 { void FUN_00560e70(::fnv_00560e70::CollisionLoad *, ::fnv_00560e70::ContextLoad *); }
