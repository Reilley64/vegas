#pragma once

class ActiveEffect;
class Actor;
class B806840ActiveEffect;
class B806840SaveBuffer;
class B9277Node;
struct BGSLoadFormBuffer;
class BGSPerkEntry;
struct BGSSaveFormBuffer;
struct ActiveEffectListBridge;
struct ActorBridge;
struct Node008061b0;
template <class> class BSSimpleList;

// 0x008060e0
void FUN_008060e0(::BSSimpleList< ::ActiveEffect *> *, ::BGSLoadFormBuffer *);
// 0x00806130
void FUN_00806130(::ActiveEffectListBridge *, ::ActorBridge *);
// 0x008061b0
void FUN_008061b0(::Node008061b0 *, void *);
// 0x00806840
void FUN_00806840(::B806840SaveBuffer *, ::B806840ActiveEffect *);
// 0x00806a10
void FUN_00806a10(::BGSSaveFormBuffer *, ::BSSimpleList< ::BGSPerkEntry *> *);
// 0x00806b00
void InitLoadGameForEffects(::Actor *, ::BSSimpleList< ::ActiveEffect *> *);
// 0x00806ba0
void FUN_00806ba0(void *, ::B9277Node *);
