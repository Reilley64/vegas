#pragma once

struct FeatureCache;
struct S06c0_Rec;
struct SweepBounds;
struct SweepPair;

// 0x00db00f0
int CollideSweepBounds(const ::SweepBounds *, int, const ::SweepBounds *, int, ::SweepPair *__restrict, int, int &);
// 0x00db06c0
void SortRecordsByKey(::S06c0_Rec *, int);
// 0x00db0b00
void CheckFeatureCacheCoverage(::FeatureCache *, int, int);
