#pragma once

#include <cstdint>

struct CollisionKeyEntry;

// 0x00d4d250
void SortEntriesByCollisionKey(::CollisionKeyEntry *, int, int, int);
// 0x00d4de30
void FUN_00d4de30(intptr_t, intptr_t);
