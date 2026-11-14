#pragma once

class BGSDehydrationStage;
class BGSHungerStage;
class BGSSleepDeprevationStage;

// 0x00402030
::BGSHungerStage *FindHungerStage(float);
// 0x004020b0
int GetHungerStage(unsigned int);
// 0x00402550
void FUN_00402550(::BGSDehydrationStage *);
// 0x00402760
::BGSSleepDeprevationStage *GetSleepDeprivationStage(float);
// 0x004027e0
void *FUN_004027e0(unsigned int);
// 0x00402d30
int *FUN_00402d30(int *);
