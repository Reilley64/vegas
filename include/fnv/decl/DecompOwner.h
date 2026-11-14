#pragma once

struct NiStream;

struct DecompOwner {
public:
    // 0x00b667e0
    bool CheckAndNotify(::NiStream &);
};
