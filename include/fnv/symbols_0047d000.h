#pragma once

class TESActorBase;
struct DummyVtable;
struct PathManager;

// 0x0047d0b0
::PathManager *GetPathManager();
// 0x0047d130
::TESActorBase *FUN_0047d130(::TESActorBase *, ::TESActorBase *);
// 0x0047d1a0
::DummyVtable *FindFirstNonActorBaseTemplate(::DummyVtable *, unsigned short *);
