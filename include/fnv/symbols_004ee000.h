#pragma once

class TESObjectREFR;
struct GO;
struct SeqSound;

// 0x004ee440
int FUN_004ee440();
// 0x004eeb60
void AssignNewObjectFromValue(int, int, ::GO *);
// 0x004eef00
bool PlaySequenceSounds(::SeqSound *, ::TESObjectREFR *);
