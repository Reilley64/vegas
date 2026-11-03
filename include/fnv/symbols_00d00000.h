#pragma once

class hkpAction;
namespace fnv_00d00060 { class ContactPointEvent; }
namespace fnv_00d00060 { struct World833; }
namespace fnv_00d00500 { class hkpEntity; }
namespace fnv_00d00500 { struct World833; }
namespace fnv_00d006e0 { class hkpEntity; }
namespace fnv_00d006e0 { struct World833; }
namespace fnv_00d00780 { class hkpPhantom; }
namespace fnv_00d00780 { struct World833; }
namespace fnv_00d00d40 { class CollisionEvent; }
namespace fnv_00d00d40 { struct World833; }
namespace fnv_00d00f30 { struct World833; }
struct CEvent;
struct CManager;
struct D005A0World;
struct D00640World;
struct D00820World;
struct D008C0World;
struct D00CA0World;
struct D00DE0World;
struct D00E80World;
struct Game;
struct ListenerEvent;
struct ListenerOwner;
struct ListenerOwnerQ;
struct OwnerD;
struct ProfOwner;
struct Scene;
struct TaskContext;
struct World833;
struct WorldA;

// 0x00d00060
namespace fnv_00d00060 { void FUN_00d00060(::fnv_00d00060::World833 *, ::fnv_00d00060::ContactPointEvent *); }
// 0x00d00110
void FUN_00d00110(::ListenerOwner *, ::ListenerEvent *);
// 0x00d001c0
void FUN_00d001c0(::CManager *, ::CEvent *);
// 0x00d00270
void FUN_00d00270(void *, ::TaskContext *);
// 0x00d003c0
void NotifyActionAdded(::World833 *, ::hkpAction *);
// 0x00d00460
void NotifyActionRemoved(::WorldA *, void *);
// 0x00d00500
namespace fnv_00d00500 { void NotifyEntityAdded(::fnv_00d00500::World833 *, ::fnv_00d00500::hkpEntity *); }
// 0x00d005a0
void FUN_00d005a0(::D005A0World *, void *);
// 0x00d00640
void NotifyShapeSet(::D00640World *, void *);
// 0x00d006e0
namespace fnv_00d006e0 { void NotifyEntitySetMotionType(::fnv_00d006e0::World833 *, ::fnv_00d006e0::hkpEntity *); }
// 0x00d00780
namespace fnv_00d00780 { void NotifyPhantomAdded(::fnv_00d00780::World833 *, ::fnv_00d00780::hkpPhantom *); }
// 0x00d00820
void FUN_00d00820(::D00820World *, void *);
// 0x00d008c0
void FUN_00d008c0(::D008C0World *, void *);
// 0x00d00960
void FUN_00d00960(::ProfOwner *, void *);
// 0x00d00a00
void NotifyTargets(::ProfOwner *, unsigned long);
// 0x00d00aa0
void FUN_00d00aa0(::OwnerD *, const void *);
// 0x00d00b40
void FUN_00d00b40(::ListenerOwnerQ *, void *);
// 0x00d00bf0
void FUN_00d00bf0(::ListenerOwner *, void *);
// 0x00d00ca0
void FUN_00d00ca0(::D00CA0World *, void *);
// 0x00d00d40
namespace fnv_00d00d40 { void DispatchCollisionEvents(::fnv_00d00d40::World833 *, ::fnv_00d00d40::CollisionEvent *); }
// 0x00d00de0
void FUN_00d00de0(::D00DE0World *, void *);
// 0x00d00e80
void FUN_00d00e80(::D00E80World *);
// 0x00d00f30
namespace fnv_00d00f30 { void NotifyWorldDeleted(::fnv_00d00f30::World833 *); }
// 0x00d00fe0
void ProcessSceneCallbacks(::Game *, ::Scene *);
