#pragma once
#include <cstdint>

class ActiveEffect;
class ActiveEffectList_5d40;
class Actor;
class ActorStandin_5d40;
class BGSLoadFormBuffer;
class SaveEffectObj;
namespace fnv_00805b40 { struct AENode; }
struct SaveSizeListNode;

// 0x00805880
void SaveEffectData(::SaveEffectObj *, uintptr_t);
// 0x00805920
::ActiveEffect *FUN_00805920(::BGSLoadFormBuffer *);
// 0x00805a00
unsigned short FUN_00805a00(::SaveSizeListNode *, void *);
// 0x00805b40
namespace fnv_00805b40 { void FUN_00805b40(::fnv_00805b40::AENode *, ::Actor *); }
// 0x00805d40
void FUN_00805d40(::ActiveEffectList_5d40 *, ::ActorStandin_5d40 *);
