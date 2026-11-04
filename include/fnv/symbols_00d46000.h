#pragma once

struct Input_d2e9;
struct hkpCollisionDispatcher;

// 0x00d46010
void FUN_00d46010(const void *, const void *, const void *, void *);
// 0x00d46050
void FUN_00d46050(int, int, int, int);
// 0x00d46090
void FUN_00d46090(void *, void *, const ::Input_d2e9 *, void *, void *);
// 0x00d46410
void FUN_00d46410(::hkpCollisionDispatcher *);
// 0x00d46ee0
int *GetEntryAt(char *, int, int);
