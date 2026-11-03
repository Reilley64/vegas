#pragma once

struct Buffer;
struct Node;
struct OutputD72;
struct StateD72090;

// 0x00d72090
void FUN_00d72090(::StateD72090 *);
// 0x00d72190
extern "C" void FUN_00d72190(::Node *, ::Buffer *, int, int *);
// 0x00d72e90
void FUN_00d72e90(const float *, ::OutputD72);
