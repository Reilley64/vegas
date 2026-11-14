#pragma once

struct BSRenderedTexture;
struct FUN_00b37880;
struct FakeObj;
struct Helper;
struct Output;
struct P1;
struct P3;
struct Param;
struct Ptr;
struct Refs;
struct VirtObj;
struct Wrap;

struct Host {
public:
    // 0x0050de60
    bool FUN_0050de60(::Ptr, float *, ::P3 *);
    // 0x005174d0
    void *FUN_005174d0(unsigned int);
    // 0x00639c90
    bool FUN_00639c90(unsigned int);
    // 0x0068b4c0
    bool FUN_0068b4c0(::Param *);
    // 0x00872f50
    ::BSRenderedTexture *FUN_00872f50(::P1 *, ::BSRenderedTexture *, unsigned char, unsigned char);
    // 0x0087ae60
    void QueueCheckTask(::FakeObj *);
    // 0x00913fb0
    void FUN_00913fb0(::VirtObj *);
    // 0x009a3780
    void ProcessElements(::Helper *);
    // 0x00b18f60
    void FUN_00b18f60(::FUN_00b37880 *);
    // 0x00b8b3b0
    void FUN_00b8b3b0();
    // 0x00d05840
    int FUN_00d05840(int, ::Refs *, int, int);
    // 0x00dbf930
    void WriteArray(const ::Wrap &, int);
    // 0x00df9fe0
    int FUN_00df9fe0(::Output *, int *);
};
