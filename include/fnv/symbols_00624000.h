#pragma once
#include <cstdint>

struct FUN_004769c0_shell;
struct FUN_004b4cf0_shell;
struct NiTransform;
struct TopicH;

// 0x006240d0
void *FUN_006240d0(void *);
// 0x00624560
void FUN_00624560();
// 0x00624ad0
::NiTransform *FUN_00624ad0(::NiTransform *, ::TopicH *);
// 0x00624b10
::FUN_004769c0_shell *FUN_00624b10(::FUN_004769c0_shell *, ::FUN_004b4cf0_shell *);
// 0x00624b70
unsigned int GetBSXFlags(std::uintptr_t, unsigned int);
