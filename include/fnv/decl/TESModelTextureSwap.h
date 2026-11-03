#pragma once

class BGSTextureSet;
class DistantTreeTextureInfo;
class NiAVObject;
class TESFile;
class TESForm;

class TESModelTextureSwap {
public:
    // 0x0048a3d0
    TESModelTextureSwap();
    // 0x0048a990
    static void ReadTextureSwapChunk(::TESModelTextureSwap *, ::TESFile *);
    // 0x0048aa80
    void InitItem(::TESForm *);
    // 0x0048ad70
    ::DistantTreeTextureInfo *GetTexSwap(int);
    // 0x0048ade0
    void ClearTextureSwaps();
    // 0x0048ae30
    void AddTexSwap(const char *, int, ::BGSTextureSet *);
    // 0x0048afe0
    void ApplyTextureSwaps(::NiAVObject *);
};
