#pragma once

struct BGSLoadFormBuffer;
class BSFaceGenNiNode;
class BipedAnim;
class NiNode;
class TESHair;
class TESObjectREFR;
template <class> struct FaceGenMatrix;

class TESNPC {
public:
    // 0x005dd560
    void ResetFaceGen();
    // 0x00601170
    TESNPC();
    // 0x00601570
    void ResetFormData();
    // 0x00603790
    void CopyActorBaseData(::TESNPC *);
    // 0x00603ad0
    void GetFaceGenCoords(FaceGenMatrix<float> (&)[2][2]);
    // 0x00603b50
    ::TESHair *GetHair();
    // 0x00603be0
    void UpdateActorBaseData(bool);
    // 0x006041d0
    float GetDefaultHeight();
    // 0x006047c0
    void FUN_006047c0(::TESObjectREFR *, bool, bool, bool, bool);
    // 0x006062e0
    void AttachHeadParts(::TESObjectREFR *, ::NiNode *);
    // 0x00606540
    void RebuildHeadModel(::TESObjectREFR *, ::BipedAnim *, bool);
    // 0x00607370
    void GetFaceGenNodes(::BSFaceGenNiNode *&, ::BSFaceGenNiNode *&);
    // 0x009dace0
    void Revert(::BGSLoadFormBuffer *);
};
