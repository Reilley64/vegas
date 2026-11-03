#pragma once

struct D06D50Class;
struct D06D50Object;

struct D06D50Finder {
public:
    // 0x00d06d50
    const ::D06D50Class *FindClass(const ::D06D50Object *) const;
};
