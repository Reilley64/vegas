#pragma once

struct CB3DD0Entity;
struct CB3DD0World;
struct FUN_00cb3ca0_object;
struct S_00cb3da0_Ctx;

// 0x00cb39d0
void FUN_00cb39d0(void *, void *, void *, void *);
// 0x00cb3c80
void FUN_00cb3c80(int, int);
// 0x00cb3ca0
int *FUN_00cb3ca0(::FUN_00cb3ca0_object *, int *, int);
// 0x00cb3da0
void FUN_00cb3da0(::S_00cb3da0_Ctx *, void *);
// 0x00cb3dd0
void FUN_00cb3dd0(::CB3DD0World *, ::CB3DD0Entity *, int);
// 0x00cb3fd0
void ClearSlotReference(int *, int *);
