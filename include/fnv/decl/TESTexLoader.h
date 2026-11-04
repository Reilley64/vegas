#pragma once

struct NiSourceTexture;
template <class> struct TexPtr;

struct TESTexLoader {
public:
    // 0x004568c0
    void FUN_004568c0(const char *, ::TexPtr< ::NiSourceTexture> &, bool, bool);
};
