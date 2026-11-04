#pragma once

class DialogueItem;
class TESObjectREFR;
class TESTopicInfo;
template <class> class BSSimpleList;

class TESTopic {
public:
    // 0x0061a790
    ::TESTopicInfo *FindMatchingTopicInfo(bool &, ::TESObjectREFR *, ::TESObjectREFR *, bool, ::TESTopic *, ::BSSimpleList< ::DialogueItem *> *);
};
