#pragma once

struct CloneProcess;
struct PixelProxy;
struct TextureProxy;

struct OwnerProxy {
public:
    // 0x007253a0
    void FUN_007253a0();
    // 0x00c6ba30
    void FUN_00c6ba30(::OwnerProxy *, ::CloneProcess *);
    // 0x00e8fe10
    ::PixelProxy *FUN_00e8fe10(::TextureProxy *, int);
};
