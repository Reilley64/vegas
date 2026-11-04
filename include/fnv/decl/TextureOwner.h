#pragma once

struct RefPtr_b9fcc0;
struct TextureInput;

struct TextureOwner {
public:
    // 0x00b5ef90
    void FUN_00b5ef90(const ::RefPtr_b9fcc0 &);
    // 0x00e682b0
    bool CreateTextureFromInput(::TextureInput *, int);
};
