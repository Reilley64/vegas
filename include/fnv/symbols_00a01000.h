#pragma once
#include <cstdint>

struct ScrapHeapBuffer;
namespace fnv_00a01e20 { struct FUN_00a0ac80; }
namespace tileext { struct ExtraNode; }

// 0x00a01160
int FUN_00a01160(int **, int **);
// 0x00a01630
namespace tileext { intptr_t FUN_00a01630(::tileext::ExtraNode *); }
// 0x00a01860
intptr_t FUN_00a01860(const char *);
// 0x00a018d0
int ParseTextAndParams(const char *, char *);
// 0x00a01a20
int FUN_00a01a20(const char *);
// 0x00a01a70
::ScrapHeapBuffer *FUN_00a01a70(unsigned int);
// 0x00a01e20
namespace fnv_00a01e20 { ::fnv_00a01e20::FUN_00a0ac80 *FUN_00a01e20(const char *, const char *, unsigned int); }
