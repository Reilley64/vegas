#pragma once

struct B8B060Pair;

class B8B060Request {
public:
    // 0x00b8b060
    void SetIfHigherPriority(float, int, float, float, float, float, const ::B8B060Pair &);
};
