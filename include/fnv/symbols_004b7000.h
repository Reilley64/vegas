#pragma once

class NiAVObject;
class NiNode;
enum LANGUAGE;
namespace fnv_004b7210 { struct UIRoot; }

// 0x004b70f0
void FUN_004b70f0(::NiNode *, float);
// 0x004b71d0
bool FUN_004b71d0();
// 0x004b7210
namespace fnv_004b7210 { ::fnv_004b7210::UIRoot *FUN_004b7210(); }
// 0x004b7220
::LANGUAGE GetConfiguredLanguage();
// 0x004b7240
bool ConvertLocalizedString(const char *, char *, unsigned int);
// 0x004b75a0
const char *FUN_004b75a0(const char *, const char *);
// 0x004b7660
bool UpdateObjectVisibility(::NiAVObject *);
