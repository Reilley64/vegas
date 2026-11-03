#pragma once

class TESForm;
class TESNPC;
struct BGSTextureModel;

class TESRace {
public:
    // 0x006131a0
    ::BGSTextureModel *GetBodyTextureModel(int);
    // 0x00613fd0
    void ClearFaceGenUndo();
    // 0x006147e0
    void BuildBodyTexturePath(::TESNPC *, char *);
    // 0x00969910
    ::TESForm *FUN_00969910();
};
