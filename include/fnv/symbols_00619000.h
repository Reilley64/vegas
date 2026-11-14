#pragma once
#include <cstdint>

class QuestDialogueInfo;
class TESTopicInfo;
class TopicInfoArray;

// 0x00619410
bool FUN_00619410(const char *);
// 0x006197c0
void *InitLargePrimitiveArray(void *);
// 0x00619b60
void FUN_00619b60(std::intptr_t);
// 0x00619f20
::TESTopicInfo *GetTopicInfoByIndex(::QuestDialogueInfo *, unsigned int);
// 0x00619fe0
void FUN_00619fe0(::TopicInfoArray *);
