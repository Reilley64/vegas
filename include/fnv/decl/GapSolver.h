#pragma once

class GapTransform;
class GapVector;
enum GapStatus;
struct GapShape;

class GapSolver {
public:
    // 0x00daad40
    ::GapStatus FUN_00daad40(const ::GapShape *, const ::GapShape *, const ::GapTransform &, ::GapVector &);
};
