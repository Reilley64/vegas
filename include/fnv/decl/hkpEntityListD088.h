#pragma once

struct hkpCollidableD088;
template <class> struct hkArrayD088;

class hkpEntityListD088 {
public:
    // 0x00d08800
    bool CheckCollidables(::hkArrayD088< ::hkpCollidableD088 *> &);
};
