#pragma once

class PathingLocation;
struct ArgObj;
struct BuildStatus;
struct P0;
struct P2;
struct ParamCls;
struct ParamObj;
struct Pkg;
struct Src;
struct Vec4f;

struct ThisCls {
public:
    // 0x0063ddb0
    void FUN_0063ddb0(::ParamObj *);
    // 0x006ce2d0
    bool ComputePathingLocation(::ArgObj *, ::ArgObj *, ::PathingLocation *);
    // 0x0078e1c0
    void InitLockInterface();
    // 0x0091ae00
    void *FUN_0091ae00(::P0 *, ::Pkg *, ::P2 *);
    // 0x00972d30
    void FUN_00972d30();
    // 0x009bb240
    void UpdateMuzzleFlash(::ParamCls *);
    // 0x009dbdc0
    void UpdatePathingState(float);
    // 0x00c6eb00
    char FUN_00c6eb00(::ArgObj *);
    // 0x00d7f720
    ::ThisCls *FUN_00d7f720();
    // 0x00db0ec0
    int FUN_00db0ec0(::Vec4f *);
    // 0x00dbcea0
    void FUN_00dbcea0(::Src *);
    // 0x00e1de00
    ::BuildStatus FUN_00e1de00(float *);
};
