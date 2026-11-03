#pragma once

class ActorValueOwner;
namespace ActorValue { enum Index; }
struct AVOwner;
struct StatOwner;

// 0x008b9220
void *FUN_008b9220(char *);
// 0x008b9240
void FUN_008b9240(::ActorValueOwner *, int, float, float, ::ActorValueOwner *);
// 0x008b9830
void ApplyAVModifierAndUpdatePair(::AVOwner *, int, float, float, void *);
// 0x008b9960
void UpdateActorValueFlag(::ActorValueOwner *, ::ActorValue::Index, float, float);
// 0x008b9ab0
void FUN_008b9ab0(::ActorValueOwner *);
// 0x008b9b10
void FUN_008b9b10(char *);
// 0x008b9cc0
void FUN_008b9cc0(int);
// 0x008b9db0
void FUN_008b9db0(::ActorValueOwner *);
// 0x008b9ea0
void FUN_008b9ea0(::StatOwner *, int, float, float);
