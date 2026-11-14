#pragma once

struct HolderStub;
struct StatisticsResult;
struct StatsB0;
struct TrackAnalysis;

// 0x00e4e3f0
::HolderStub *FUN_00e4e3f0();
// 0x00e4e570
void AnalyzeTrackBits(const unsigned short *, unsigned int, ::TrackAnalysis *);
// 0x00e4e610
void AnalyzeTrackWithZeroCount(const unsigned short *, const unsigned short *, unsigned int, unsigned int, ::TrackAnalysis *);
// 0x00e4ead0
void FUN_00e4ead0(const unsigned short *, unsigned int, ::StatisticsResult *);
// 0x00e4ebb0
void FUN_00e4ebb0(const unsigned short *, void *, unsigned int, unsigned int, ::StatsB0 *);
