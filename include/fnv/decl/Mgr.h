#pragma once

class MenuTopic;
struct Item;
struct PoolSet;

class Mgr {
public:
    // 0x00658650
    ::Mgr *ScaleAll(float);
    // 0x0083e850
    bool CheckTopicInfoChance(::MenuTopic *);
    // 0x00a22660
    ::Mgr *FUN_00a22660(int);
    // 0x00c97d30
    void *FUN_00c97d30(::Item *);
    // 0x00d04b00
    void InsertItemAndNotify(::PoolSet *, const ::Item &, int);
};
