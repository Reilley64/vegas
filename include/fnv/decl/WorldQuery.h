#pragma once

struct NiPoint3;

struct WorldQuery {
public:
    // 0x00588d10
    bool ContainsPoint(const ::NiPoint3 *);
    // 0x00c92430
    void FUN_00c92430(void *, void *, void *, void *);
};
