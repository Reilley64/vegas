#pragma once

class TESObjectREFR;
struct ListObj;
struct VObj1d0;
struct Weap;

// 0x0083a930
void PlayWeaponImpactSound(::TESObjectREFR *, int);
// 0x0083ac30
void PlayWeaponSound(::Weap *, ::VObj1d0 *, ::ListObj *, bool);
