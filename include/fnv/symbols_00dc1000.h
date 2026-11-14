#pragma once
#include <cstdint>

struct Arg2;
struct DC1C50Collection;
struct LayoutOptions;
struct NodeListEx;

// 0x00dc1960
void FUN_00dc1960(::NodeListEx &, const ::LayoutOptions &, ::Arg2 &, int);
// 0x00dc1bf0
unsigned int FUN_00dc1bf0(intptr_t, intptr_t, intptr_t, intptr_t);
// 0x00dc1c50
int GetShapeTypeFlags(int, int, ::DC1C50Collection *, int);
