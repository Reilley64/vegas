#pragma once

namespace fnv_00d32110 { struct TargetObj; }
namespace fnv_00d32190 { struct FUN_00d32190_cls; }
namespace fnv_00d323f0 { struct CopyPacket; }
namespace fnv_00d32cd0 { struct Agent; }
namespace fnv_00d32cd0 { struct CollisionResult; }
namespace fnv_00d32cd0 { struct Context; }
namespace fnv_00d32cd0 { struct Output; }
struct Arg1;
struct Arg3;
struct S_00d321e0_Dispatcher;
struct hkpShapeD32;

// 0x00d32030
extern "C" void FUN_00d32030(void *, void *, void *, void *, void *);
// 0x00d32110
namespace fnv_00d32110 { ::fnv_00d32110::TargetObj *AllocateTargetObj(void *, void *, void *, void *); }
// 0x00d32150
extern "C" void FUN_00d32150(void *, void *, void *, void *);
// 0x00d32170
void FUN_00d32170(void *, void *, void *, void *);
// 0x00d32190
namespace fnv_00d32190 { ::fnv_00d32190::FUN_00d32190_cls *FUN_00d32190(int, int, int, int); }
// 0x00d321e0
void FUN_00d321e0(::S_00d321e0_Dispatcher *);
// 0x00d32370
void FUN_00d32370(int, int, int, int);
// 0x00d323b0
void FUN_00d323b0(int, int, int, int);
// 0x00d323f0
namespace fnv_00d323f0 { void FUN_00d323f0(int, int, const ::fnv_00d323f0::CopyPacket *, int, int); }
// 0x00d32ac0
int FUN_00d32ac0(int, int);
// 0x00d32ad0
void *FUN_00d32ad0(int, char *);
// 0x00d32ba0
void FUN_00d32ba0(void *, ::hkpShapeD32 *, void *, void *, void *);
// 0x00d32c40
void FUN_00d32c40(int, ::Arg1 *, int, ::Arg3 *, int, int, int);
// 0x00d32ca0
void FUN_00d32ca0(int, int, int, int);
// 0x00d32cd0
namespace fnv_00d32cd0 { void *FUN_00d32cd0(::fnv_00d32cd0::Context *, int, ::fnv_00d32cd0::Agent *, ::fnv_00d32cd0::CollisionResult *, ::fnv_00d32cd0::Output *); }
