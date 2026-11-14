#pragma once

class Actor;
struct ActorAnimDataAA8;

// 0x0049aa20
unsigned short GetAnimationSize(void *, void *);
// 0x0049aa80
void FUN_0049aa80(::Actor *, ::ActorAnimDataAA8 *);
// 0x0049ab00
void ReadAndDispatchSaveData(void *);
