#pragma once

class TESQuest;
class TESTopic;
class TESTopicInfo;
template <class> class BSStringT;

class TESResponse {
public:
    // 0x00616dc0
    ~TESResponse();
    // 0x00616de0
    const char *GetDialogueText();
    // 0x00617400
    void BuildResponseFileName(::TESQuest *, ::TESTopic *, ::TESTopicInfo *, ::BSStringT<char> &);
    // 0x006174b0
    unsigned int GetResponseID();
};
