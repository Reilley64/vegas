#pragma once

class D2F2C0Dispatcher;
class D2FA00Agent;
namespace fnv_00d2f240 { class D2F240Agent; }
namespace fnv_00d2f240 { struct D2F240CdBody; }
namespace fnv_00d2fa40 { struct FloatOwner; }
namespace fnv_00d2fa40 { struct SpawnedObject; }
struct Holder;
struct MoppCastBody;
struct MoppCastInput;
struct SlotBox;
struct SlotParam;
struct SlotRef;
struct ValueSource;

// 0x00d2f0d0
void FUN_00d2f0d0(::MoppCastBody *, ::MoppCastBody *, ::MoppCastInput *, int, int);
// 0x00d2f240
namespace fnv_00d2f240 { ::fnv_00d2f240::D2F240Agent *CreateAgentForBodyPair(const ::fnv_00d2f240::D2F240CdBody &, const ::fnv_00d2f240::D2F240CdBody &, const void *, void *); }
// 0x00d2f2c0
void FUN_00d2f2c0(::D2F2C0Dispatcher *);
// 0x00d2f690
void FUN_00d2f690(::SlotRef *, ::SlotRef *, ::SlotParam *, ::SlotBox *);
// 0x00d2f710
void ApplyTransformToTarget(::Holder *, ::Holder *, ::ValueSource *, void *);
// 0x00d2f9d0
void FUN_00d2f9d0(int, int, int, int);
// 0x00d2fa00
::D2FA00Agent *FUN_00d2fa00(const void *, const void *, const void *, void *);
// 0x00d2fa40
namespace fnv_00d2fa40 { ::fnv_00d2fa40::SpawnedObject *FUN_00d2fa40(::fnv_00d2fa40::FloatOwner *, ::fnv_00d2fa40::FloatOwner *, int, int); }
