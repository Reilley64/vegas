#pragma once

struct Alloc64e9;
struct C64E550Allocator;
struct C64E550Element;
struct CheckedTag64e9;
struct Elem64e9;
struct FUN_0064e680_S;
struct FUN_0064e7d0_class;
struct FUN_0064e7f0_S;
struct FUN_0064e980_Block;
struct FUN_0065e9a0_holder;
struct ItE4E0;
struct NonscalarTag64e9;
struct S_0064e860_Block;
struct S_0064e8c0_Blk;

// 0x0064e430
extern "C" void FUN_0064e430(int, int);
// 0x0064e4b0
void FUN_0064e4b0(int, int, int);
// 0x0064e4e0
void FUN_0064e4e0(::ItE4E0, ::ItE4E0, ::ItE4E0);
// 0x0064e550
void FUN_0064e550(::C64E550Element *, ::C64E550Element *, ::C64E550Element *, ::C64E550Allocator *);
// 0x0064e5a0
int FUN_0064e5a0(int, int, int);
// 0x0064e600
void FUN_0064e600(int *, int *, ::FUN_0065e9a0_holder *);
// 0x0064e680
void FUN_0064e680(::FUN_0064e680_S *, ::FUN_0064e680_S *, ::FUN_0064e680_S *);
// 0x0064e6c0
extern "C" void FUN_0064e6c0(void *, void *, void *, unsigned char);
// 0x0064e710
void ConstructArrayWithRollback(char *, unsigned int, void *, ::FUN_0064e7d0_class *);
// 0x0064e7f0
::FUN_0064e7f0_S *CopyStructRange(::FUN_0064e7f0_S *, ::FUN_0064e7f0_S *, ::FUN_0064e7f0_S *);
// 0x0064e840
void ForwardToHandler(int, int, int, int);
// 0x0064e860
::S_0064e860_Block *FUN_0064e860(::S_0064e860_Block *, ::S_0064e860_Block *, ::S_0064e860_Block *);
// 0x0064e8c0
void CopyConstructBlock(void *, ::S_0064e8c0_Blk *);
// 0x0064e980
void *CopyBlocksBackward(void *, ::FUN_0064e980_Block *, ::FUN_0064e980_Block *);
// 0x0064e9c0
::Elem64e9 *FUN_0064e9c0(::Elem64e9 *, ::Elem64e9 *, ::Elem64e9 *, ::Alloc64e9 &, ::NonscalarTag64e9, ::CheckedTag64e9);
