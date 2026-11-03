#pragma once

class DialogueItem;
class TESObjectREFR;
class TESTopic;
class TESTopicInfo;
template <class> class BSSimpleList;

// 0x0061a270
namespace fnv_0061a270 { void ClearTableEntries(); }
// 0x0061a2d0
namespace fnv_0061a2d0 { const char *GetTopicSubTypeName(int, int); }
// 0x0061a310
namespace fnv_0061a310 { ::TESTopic *FindTopicByInfo(::TESTopicInfo *); }
// 0x0061a380
void AddTopicToList(::TESTopic *, ::BSSimpleList< ::TESTopic *> *, bool);
// 0x0061a450
bool FUN_0061a450(::TESTopic *, ::TESTopic *, bool);
// 0x0061a5a0
namespace fnv_0061a5a0 { void SortTopicList(bool, ::BSSimpleList< ::TESTopic *> *); }
// 0x0061aed0
bool IsFlag20Set(char *);
// 0x0061af30
::TESTopicInfo *FUN_0061af30(::TESTopicInfo *, bool &, ::TESObjectREFR *, ::TESObjectREFR *, bool, ::BSSimpleList< ::DialogueItem *> *);
