#pragma once

struct Input_d2e9;
struct hkpCollisionDispatcher;

// 0x00d46010
void FUN_00d46010(int, int, int, int);
// 0x00d46050
void FUN_00d46050(int, int, int, int);
// 0x00d46090
void FUN_00d46090(int, int, const ::Input_d2e9 *, int, int);
// 0x00d46410
void FUN_00d46410(::hkpCollisionDispatcher *);
// 0x00d46ee0
int *GetEntryAt(char *, int, int);
