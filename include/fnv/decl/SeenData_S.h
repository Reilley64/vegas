#pragma once

struct NiPoint3;

struct SeenData_S {
public:
    // 0x00879ad0
    bool HasEnoughSeenPoints(const ::NiPoint3 &, const ::NiPoint3 &);
};
