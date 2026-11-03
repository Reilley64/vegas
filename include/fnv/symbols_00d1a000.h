#pragma once

struct CollisionContext;
struct EntityNode;

// 0x00d1a220
void QuickSortByLowWord(unsigned int *, int, int, int);
// 0x00d1a300
void InitArrayEntries(int **, int);
// 0x00d1a330
extern "C" void FUN_00d1a330(const ::CollisionContext *, ::EntityNode *const *, int);
