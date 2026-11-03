#pragma once
#include <cstdint>

class NiAlphaProperty;
class NiStream;
namespace fnv_00a5c5b0 { struct VStream; }

// 0x00a5c180
bool FUN_00a5c180(void *, intptr_t, ::NiStream *);
// 0x00a5c5b0
namespace fnv_00a5c5b0 { void SaveNiObjectLinks(char *, intptr_t, ::fnv_00a5c5b0::VStream *); }
// 0x00a5cb90
char *GetAlphaBlendFuncName(const char *, int);
// 0x00a5cd00
char *FormatTestCondition(const char *, int);
// 0x00a5ceb0
::NiAlphaProperty *CreateNiAlphaProperty();
