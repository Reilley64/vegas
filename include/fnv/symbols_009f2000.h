#pragma once

struct BGSMessageInitAccess;
class TESObjectREFR;

// 0x009f27a0
void *InitEscortPackageData(void *);
// 0x009f2d40
::TESObjectREFR *FUN_009f2d40(::TESObjectREFR *, ::BGSMessageInitAccess *);
// 0x009f2da0
bool BuildLinkedRefChain(char *);
