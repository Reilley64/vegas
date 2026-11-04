#pragma once
#include <cstdint>

struct E0C860Node;
struct Node;
struct Node_e0c8e0;
struct Sink;

// 0x00e0c700
void FUN_00e0c700(::Node *, int, float);
// 0x00e0c860
intptr_t GetTreeWidth(::E0C860Node *, intptr_t, int, bool);
// 0x00e0c8e0
void FUN_00e0c8e0(void *, ::Node_e0c8e0 *, int, float);
// 0x00e0cd20
void ProcessRecords(unsigned char *, unsigned char *, ::Sink *);
