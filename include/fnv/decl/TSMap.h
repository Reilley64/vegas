#pragma once

struct QHeadPtr;

struct TSMap {
public:
    // 0x0044d070
    bool InsertOrReplace(int, int, const ::QHeadPtr &, bool);
};
