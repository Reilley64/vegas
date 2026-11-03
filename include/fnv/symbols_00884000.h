#pragma once

class Actor;
struct blob4;

// 0x008840d0
bool IsFlagBitSet(char *);
// 0x008840f0
bool FUN_008840f0(int);
// 0x008842c0
namespace fnv_008842c0 { bool FUN_008842c0(::Actor *); }
// 0x00884920
bool FUN_00884920(int *);
// 0x00884940
void FUN_00884940(int *, ::blob4);
// 0x00884990
void UpdateFlag800State(::Actor *);
