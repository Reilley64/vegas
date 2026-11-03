#pragma once

class Script;
class TESResponseList;
class TESTopic;
class TESTopicInfoData;
enum DIALOGUE_TYPE;
template <class> class BSSimpleList;

class TESTopicInfo {
public:
    // 0x00436aa0
    ::BSSimpleList< ::TESTopic *> *GetAddTopicList();
    // 0x0061ccd0
    TESTopicInfo(::DIALOGUE_TYPE);
    // 0x0061d230
    void ClearResponses();
    // 0x0061d250
    void ResetResponseList();
    // 0x0061e180
    void SetTopicInfoData(::TESTopicInfoData *);
    // 0x0061e780
    ::TESResponseList *DuplicateResponseList(::TESResponseList *);
    // 0x0061eb60
    ::Script *GetResultScript(unsigned int);
    // 0x0061f150
    void AddTopicList();
    // 0x0061f220
    void MarkAsRefusal();
    // 0x007627c0
    bool IsChallengeFlagSet();
};
