#pragma once

struct SortElem16;
struct SortRec;
struct hkAabbUint32;

// 0x00cf83c0
void FUN_00cf83c0(::SortElem16 *, int, int, bool (*)(const SortElem16 &, const SortElem16 &));
// 0x00cf8510
void FUN_00cf8510(::SortRec *, int, int, char *(*)(void *, const SortRec *, const SortRec *));
// 0x00cf8690
void FUN_00cf8690(::hkAabbUint32 *, const ::hkAabbUint32 *);
