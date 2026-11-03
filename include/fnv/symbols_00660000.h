#pragma once

struct Alloc6605;
struct C0130Iterator;
struct C0190Iterator;
struct C60490Element;
struct C6602B0Entry;
struct CheckedTag6605;
struct Elem6605;
struct FUN_00660070_cls;
struct NonscalarTag6605;
struct S6;
struct S_00660510_Context;
template <class> class BSSimpleList;

// 0x00660030
::S6 *CopyTripleShorts(::S6 *, ::S6 *, ::S6 *);
// 0x00660070
int CopyRange(int, int, int, ::FUN_00660070_cls *);
// 0x00660130
char *FUN_00660130(::C0130Iterator, ::C0130Iterator, ::C0130Iterator);
// 0x00660190
char *FUN_00660190(::C0190Iterator, ::C0190Iterator, ::C0190Iterator);
// 0x00660210
void FUN_00660210(void *, void *, void *, void *);
// 0x00660230
void FUN_00660230(void *, void *, void *, void *);
// 0x00660250
void CallWithUninitializedFlag(void *);
// 0x00660270
char *FUN_00660270(const char *, const char *, char *);
// 0x006602b0
void CopyConstructEntry(::C6602B0Entry *, const ::C6602B0Entry &);
// 0x00660340
extern "C" void FUN_00660340(void *, void *, void *, void *);
// 0x006603a0
extern "C" void FUN_006603a0(void *, void *, void *, void *);
// 0x00660400
::BSSimpleList<int> *FUN_00660400(::BSSimpleList<int> *);
// 0x00660410
void ConstructInPlace(void *, int);
// 0x00660490
void CopyConstructElement(::C60490Element *, const ::C60490Element &);
// 0x00660510
int FUN_00660510(int, int, int, ::S_00660510_Context *);
// 0x006605d0
namespace std6605 { ::Elem6605 *CopyConstructRange(::Elem6605 *, ::Elem6605 *, ::Elem6605 *, ::Alloc6605 &, ::NonscalarTag6605, ::CheckedTag6605); }
// 0x00660940
unsigned int MinUnsigned(unsigned short, unsigned int);
