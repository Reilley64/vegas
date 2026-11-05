#pragma once

class NiUpdateData {
public:
    float time;
    bool updateControllers;
    bool isMultiThreaded;
    bool flag6, flag7, flag8;

    // 0x0043d410
    NiUpdateData(float, bool, bool);
};
