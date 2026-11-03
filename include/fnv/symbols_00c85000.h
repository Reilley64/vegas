#pragma once
#include <cstdint>

class MemHeap;
struct FNV_Dispatch;
struct FUN_00c85620_heap;
struct FUN_00c85690_Allocator;
struct Item;
struct S_00c85ef0_Map;
struct S_00c85ef0_Ret;

// 0x00c852c0
void FUN_00c852c0(::Item *, int, int, int);
// 0x00c85620
void *FUN_00c85620(::FUN_00c85620_heap *, unsigned int, unsigned int);
// 0x00c85660
void FUN_00c85660(::MemHeap *, char *);
// 0x00c85690
void *AllocateWithHeader(::FUN_00c85690_Allocator *, uintptr_t);
// 0x00c856c0
void FUN_00c856c0(::FNV_Dispatch *, char *);
// 0x00c85730
void SetThreadLocalValue(void *);
// 0x00c85750
void FUN_00c85750();
// 0x00c85760
namespace fnv_00c85760 { void *FUN_00c85760(); }
// 0x00c85800
void FUN_00c85800();
// 0x00c85ef0
::S_00c85ef0_Ret FUN_00c85ef0(::S_00c85ef0_Map *, int);
