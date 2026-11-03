#pragma once

#include <cstdint>

struct M;
struct R;
struct StrArray;
struct Tile;
struct V;

struct S {
public:
    // 0x0044e4f0
    void FUN_0044e4f0(void *);
    // 0x00479110
    ::S *ConstructShadowSceneArray();
    // 0x004a7800
    void FUN_004a7800();
    // 0x004ed140
    ::R FUN_004ed140(int);
    // 0x00540540
    std::uintptr_t GetElement(int);
    // 0x00546890
    ::S *InitBound(unsigned short, unsigned short);
    // 0x00561690
    void FUN_00561690(std::intptr_t);
    // 0x005fdb60
    void *FUN_005fdb60(unsigned int);
    // 0x00670760
    void FUN_00670760();
    // 0x0071f310
    void DestroyMenu();
    // 0x007315b0
    int FUN_007315b0();
    // 0x007983c0
    float GetScaledValue();
    // 0x007b41c0
    ::Tile *FUN_007b41c0(int);
    // 0x007db250
    void FUN_007db250(int, int *);
    // 0x00a1bf80
    void Reset();
    // 0x00a5ca80
    void FUN_00a5ca80(::StrArray *);
    // 0x00a824d0
    void FUN_00a824d0();
    // 0x00ae7920
    ::S *AssignFrom(const ::S *);
    // 0x00b05000
    ::V *FUN_00b05000(::V *, ::M *);
    // 0x00c8d4a0
    const char *FUN_00c8d4a0();
    // 0x00e89b70
    void FUN_00e89b70();
    // 0x00e971d0
    void FUN_00e971d0();
};
