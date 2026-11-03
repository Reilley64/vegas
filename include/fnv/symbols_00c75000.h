#pragma once
#include <cstdint>

class NiNode;
struct Input134;
struct SavedNodeArray;

// 0x00c75180
intptr_t FUN_00c75180(::Input134 *);
// 0x00c75c00
void RestoreNodeTransforms(::NiNode *, ::SavedNodeArray *, int, int);
