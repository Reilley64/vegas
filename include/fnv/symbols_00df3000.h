#pragma once

struct BndBounds;
struct BndBuffers;
struct BndSplit;
struct Entry8;

// 0x00df3160
void FUN_00df3160();
// 0x00df3250
int FUN_00df3250(int);
// 0x00df32a0
void FUN_00df32a0(::Entry8 *, int, int);
// 0x00df33b0
int FUN_00df33b0(const ::BndBuffers *, int, int, ::BndSplit *, ::BndBuffers *, const ::BndBounds *);
