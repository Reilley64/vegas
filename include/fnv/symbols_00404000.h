#pragma once

class GameSettingCollection;
namespace fnv_00404820 { struct StrArg; }
struct FUN_004047f0_arg;
template <class> class BSStringT;

// 0x00404010
float FUN_00404010(float, float);
// 0x00404040
float FUN_00404040(float);
// 0x004046f0
void FUN_004046f0(char *, const char *);
// 0x004047f0
::BSStringT<char> *AssignFromString(::BSStringT<char> *, ::FUN_004047f0_arg);
// 0x00404820
namespace fnv_00404820 { ::BSStringT<char> *FUN_00404820(::BSStringT<char> *, ::fnv_00404820::StrArg); }
// 0x00404a70
::GameSettingCollection *GetGameSettingCollection();
// 0x00404a80
void EnsureSpawnedObj();
// 0x00404dc0
int FUN_00404dc0(const char *, const char *);
// 0x00404f30
namespace fnv_00404f30 { void FUN_00404f30(int); }
