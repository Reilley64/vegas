#pragma once

class MenuTopic;

class TopicMenuController {
public:
    // 0x004d5c60
    static void IncrementMiscStat(int);
    // 0x0083e370
    bool SelectTopic(bool);
    // 0x0083e4f0
    ::MenuTopic *GetFirstTopic();
    // 0x0083e590
    static ::TopicMenuController *GetInstance();
};
