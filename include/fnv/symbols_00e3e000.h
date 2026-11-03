#pragma once

struct HeapEntryE3EE;
struct HeapLessE3EE;
struct SortEntry;

// 0x00e3e020
int FUN_00e3e020(int, int *);
// 0x00e3eec0
void SiftDownHeap(::HeapEntryE3EE *, int, int, ::HeapLessE3EE);
// 0x00e3eff0
void HeapSort(::SortEntry *, int, int);
