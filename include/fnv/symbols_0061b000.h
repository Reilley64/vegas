#pragma once

class TESObjectREFR;
class TESQuest;
struct DialogueList;
struct FUN_0061b320_shell;

// 0x0061b440
unsigned int GenerateConversation(::TESObjectREFR *, ::TESObjectREFR *, ::DialogueList *, ::FUN_0061b320_shell *);
// 0x0061b9d0
long long GetTime64(long long *);
// 0x0061b9f0
int GetSignedByteAtOffset36(signed char *);
// 0x0061ba10
namespace fnv_0061ba10 { bool CheckTopicsForQuest(::TESQuest *); }
// 0x0061bbf0
char FUN_0061bbf0(unsigned char);
