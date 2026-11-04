#pragma once

struct GameSound;
struct TESSoundEx;

// 0x0082d150
bool GetSoundPathAndFlags(unsigned int, char *, unsigned int *, ::TESSoundEx **);
// 0x0082d400
unsigned int ApplySoundFormToGameSound(::GameSound *, void *, unsigned int *);
// 0x0082d700
int FUN_0082d700(void *);
