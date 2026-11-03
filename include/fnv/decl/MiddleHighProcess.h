#pragma once

#include <cstdint>

class Animation;
class BSBound;
class BSFaceGenNiNode;
class BooleanFloatQuery;
class FurnitureMark;
class MagicItem;
class MagicTarget;
class NiAVObject;
class TESEffectShader;
class TESIdleForm;
class TargetDoorController;

class MiddleHighProcess {
public:
    // 0x00407800
    void SetFaceAnimationData(::TargetDoorController *);
    // 0x00460ff0
    ::FurnitureMark *GetFurnitureMarkerData();
    // 0x00502430
    ::NiAVObject *GetSceneRoot();
    // 0x00505e50
    void SetCurrentIdle(::TESIdleForm *);
    // 0x00521630
    ::BooleanFloatQuery *RefreshActorRuntimeData();
    // 0x00521710
    void SetAnimationNode(::NiAVObject *);
    // 0x005224a0
    ::BSFaceGenNiNode *GetFacialAnimationNode();
    // 0x00566950
    bool IsActorInCombat();
    // 0x005c8a30
    void SetBoundingBox(::BSBound *);
    // 0x005ce8f0
    bool IsAnimationPlaying();
    // 0x00602150
    ::Animation *GetAnimation();
    // 0x007ac9d0
    void AssignEffectShader(::TESEffectShader *);
    // 0x008d8140
    void SetSelectedMagicItem(::MagicItem *);
    // 0x008d8180
    void SetMagicTarget(::MagicTarget *);
    // 0x008d8220
    bool ResetAlertState();
    // 0x008d8270
    bool GetProcessState();
    // 0x008d8500
    void AddDeferredHideLimb(::TargetDoorController *);
    // 0x008d8a80
    void SetKnockdownStage(std::intptr_t);
    // 0x008d8aa0
    void AttachFaceGenerationNode(::BSFaceGenNiNode *);
    // 0x008d8ac0
    ::BSFaceGenNiNode *GetFaceGenHeadNode();
    // 0x008d8ae0
    void SetFaceGenHeadNode(::BSFaceGenNiNode *);
    // 0x008d8b00
    ::NiAVObject *GetAnimationObject();
    // 0x008f7710
    float GetLightIntensity();
    // 0x00929260
    void FUN_00929260(unsigned char);
    // 0x009ee020
    ::BSBound *GetObjectBounds();
};
