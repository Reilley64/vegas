#pragma once

class ExplosionEffectSettings;
struct BGSExplosionData_init;
struct DArg;
struct S_004fa4b0;

// 0x004fa4b0
int FUN_004fa4b0(const ::S_004fa4b0 *, const ::S_004fa4b0 *);
// 0x004fa5e0
void *FUN_004fa5e0(char *);
// 0x004fa610
bool InsertDebrisIfValid(char *, ::DArg);
// 0x004faa00
::ExplosionEffectSettings *FUN_004faa00(::ExplosionEffectSettings *);
// 0x004faa20
void InitExplosionData(::BGSExplosionData_init *);
