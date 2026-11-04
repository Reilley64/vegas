#pragma once

struct FilterCF7080;
struct PairCF7080;

struct DispatcherCF7080 {
public:
    // 0x00cf7080
    void FUN_00cf7080(::PairCF7080 *, int, const ::FilterCF7080 *);
};
