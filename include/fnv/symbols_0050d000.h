#pragma once

class NiDynamicEffect;
class NiLight;
class NiNode;
struct FUN_0050dd50_arg;
struct List;

// 0x0050d640
void ProcessListItems(::List *);
// 0x0050d6d0
::NiLight *FindLightInNode(::NiNode *);
// 0x0050dd50
void FUN_0050dd50(::NiDynamicEffect *, ::FUN_0050dd50_arg);
// 0x0050de10
int FUN_0050de10();
