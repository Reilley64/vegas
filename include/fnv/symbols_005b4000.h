#pragma once

#include <cstdint>

class Script;
struct ScriptLocals;
class TESObjectREFR;
template <class> class BSStringT;

// 0x005b4960
bool FUN_005b4960(std::intptr_t, const char *, ::TESObjectREFR *, ::TESObjectREFR *, ::Script *, ::ScriptLocals *, int, unsigned int &, const char *, ::BSStringT<char> *);
