#pragma once

struct KObject;
struct KPoint3;

// 0x00c821b0
void FUN_00c821b0(::KObject *, ::KPoint3 *, bool);
// 0x00c82580
float FUN_00c82580(void *);
// 0x00c827f0
void SetSelectionMask(unsigned int, unsigned int, bool);
// 0x00c828f0
namespace fnv_00c828f0 { void InitializeSelectionMasks(); }
