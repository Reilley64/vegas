#pragma once
#include <cstdint>

class NiControllerSequence;
struct Owner;
struct Seq;

// 0x00a2f0c0
bool AttachSeqToOwner(::Owner *, intptr_t, ::Seq *, int *, ::Seq *);
// 0x00a2f6c0
void *FUN_00a2f6c0();
// 0x00a2f800
bool FUN_00a2f800(::NiControllerSequence *, float, float, int, intptr_t);
// 0x00a2f8b0
void FUN_00a2f8b0();
// 0x00a2f8c0
void *FUN_00a2f8c0(void *);
