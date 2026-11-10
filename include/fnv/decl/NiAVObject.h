#pragma once

struct CloningProcess;
class NiExtraData;
class NiFixedString;
class NiNode;
struct NiPoint3;
struct NiUpdateData;
struct NiPoint3;

class NiAVObject {
public:
    // 0x0043c470
    int FUN_0043c470();
    // 0x0043c490
    ::NiPoint3 &FUN_0043c490();
    // 0x004491f0
    ::NiNode *GetParentNode();
    // 0x0045bba0
    ::NiPoint3 GetWorldTranslation();
    // 0x004b2960
    int IsVisualObject();
    // 0x004eff50
    void UpdateTimeControllers(::NiUpdateData &, bool);
    // 0x005467e0
    void EnsureWorldBound();
    // 0x006404b0
    void SetLocalRotation(float, float, float, float);
    // 0x00a5ac90
    void FUN_00a5ac90(::NiAVObject *, ::CloningProcess &);
    // 0x00a5bdd0
    ::NiExtraData *GetExtraData(const ::NiFixedString &);
    // 0x00a68bf0
    void UpdateWorldLoc();
    // 0x00a68c60
    void UpdateWorldData(::NiUpdateData &);
    // 0x00c43470
    void FUN_00c43470();
    // 0x00c61610
    void FUN_00c61610();
};
