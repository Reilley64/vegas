#pragma once

class NiFloatData;
class NiFloatInterpolator;
struct BSFadeNode;

// 0x00a3c130
::BSFadeNode *FUN_00a3c130();
// 0x00a3c570
::NiFloatInterpolator *CreateNiFloatInterpolator();
// 0x00a3cd00
namespace fnv_00a3cd00 { ::NiFloatData *CreateNiFloatData(); }
